#ifdef AI_AGENT_HOST_TEST
#include "../tests/include/f256lib_host.h"
#else
#include "f256lib.h"
#endif
#include "../include/timer.h"

static uint16_t alarm_ticks[TIMER_ALARM_COUNT] = {0};
static uint8_t alarm_active_mask = 0u;

#if PROFILER_USE_TIMER0
static uint8_t g_t0_initialized = 0u;
static uint32_t g_t0_last_tick = 0u;

static inline uint32_t t0_delta_24(uint32_t start, uint32_t end) {
	return (end - start) & (uint32_t)T0_MASK_TICKS;
}
#endif

static uint8_t alarm_bit(timer_alarm_id_t alarm) {
	return (uint8_t)(1u << ((uint8_t)alarm & 7u));
}

static void serviceTimer0(void) {
	if (!isTimerDone()) {
		return;
	}

	if (alarm_active_mask != 0u) {
		for (uint8_t index = 0u; index < TIMER_ALARM_COUNT; ++index) {
			if (alarm_ticks[index] > 0u) {
				--alarm_ticks[index];
				if (alarm_ticks[index] == 0u) {
					alarm_active_mask &= (uint8_t)~alarm_bit((timer_alarm_id_t)index);
				}
			}
		}
	}

	setTimer0();

}



void timer_service(void) {
	serviceTimer0();
}


void setTimer0()
{

	resetTimer0();
	POKE(T0_CMP_CTR, T0_CMP_CTR_RECLEAR); //when the target is reached, bring it back to value 0x000000
	POKE(T0_CMP_L,T0_TICK_CMP_L);POKE(T0_CMP_M,T0_TICK_CMP_M);POKE(T0_CMP_H,T0_TICK_CMP_H); //inject the compare value as max value

}

void resetTimer0()
{
	POKE(T0_CTR, CTR_CLEAR);
	POKE(T0_CTR, CTR_UPDOWN | CTR_ENABLE);
	POKE(T0_PEND,0x10); //clear pending timer0 
}
uint32_t readTimer0()
{
	return (uint32_t)((PEEK(T0_VAL_H)))<<16 | (uint32_t)((PEEK(T0_VAL_M)))<<8 | (uint32_t)((PEEK(T0_VAL_L)));
}

uint32_t readTimer0_consistent(void)
{
	// Attempt a consistent snapshot of the 24-bit counter.
	// If the high byte changes during the read, re-sample the low bytes once.
	for (uint8_t tries = 0u; tries < 2u; ++tries) {
		const uint8_t h1 = PEEK(T0_VAL_H);
		uint8_t m = PEEK(T0_VAL_M);
		uint8_t l = PEEK(T0_VAL_L);
		const uint8_t h2 = PEEK(T0_VAL_H);
		if (h1 == h2) {
			return ((uint32_t)h1 << 16) | ((uint32_t)m << 8) | (uint32_t)l;
		}
		// High byte rolled; re-read M/L (use the later high byte).
		m = PEEK(T0_VAL_M);
		l = PEEK(T0_VAL_L);
		return ((uint32_t)h2 << 16) | ((uint32_t)m << 8) | (uint32_t)l;
	}
	return readTimer0();
}

bool isTimerDone()
{
	#if PROFILER_USE_TIMER0
	if (!g_t0_initialized) {
		setTimer0();
	}
	const uint32_t now = readTimer0_consistent();
	return t0_delta_24(g_t0_last_tick, now) >= (uint32_t)T0_TICK_PERIOD_TICKS;
	#else
	return (PEEK(T0_PEND) & 0x10) != 0;
	#endif
}

uint16_t getAlarmTicks(timer_alarm_id_t alarm) {
	serviceTimer0();

	if (alarm >= TIMER_ALARM_COUNT) {
		return 0u;
	}

	return alarm_ticks[alarm];
}

void setAlarm(timer_alarm_id_t alarm, uint16_t ticks) {
	if (alarm >= TIMER_ALARM_COUNT) {
		return;
	}

	serviceTimer0();

	alarm_ticks[alarm] = ticks;

	if (ticks > 0u) {
		alarm_active_mask |= alarm_bit(alarm);
	} else {
		alarm_active_mask &= (uint8_t)~alarm_bit(alarm);
	}

	setTimer0();
}

void clearAlarm(timer_alarm_id_t alarm) {
	if (alarm >= TIMER_ALARM_COUNT) {
		return;
	}

	serviceTimer0();

	alarm_ticks[alarm] = 0u;
	alarm_active_mask &= (uint8_t)~alarm_bit(alarm);
}

bool checkAlarm(timer_alarm_id_t alarm) {
	serviceTimer0();

	if (alarm >= TIMER_ALARM_COUNT) {
		return true;
	}

	return (alarm_ticks[alarm] == 0u);
}
