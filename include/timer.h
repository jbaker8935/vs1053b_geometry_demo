#if !defined(SRC_TIMER_H__)
#define SRC_TIMER_H__
#include <stdbool.h>
#include <stdint.h>

#define T0_PEND     0xD660
#define T0_MASK     0xD66C

#define T0_CTR      0xD650 //master control register for timer0, write.b0=ticks b1=reset b2=set to last value of VAL b3=set count up, clear count down
#define T0_STAT     0xD650 //master control register for timer0, read bit0 set = reached target val

#define CTR_INTEN   0x80  //present only for timer1? or timer0 as well?
#define CTR_ENABLE  0x01
#define CTR_CLEAR   0x02
#define CTR_LOAD    0x04
#define CTR_UPDOWN  0x08

#define T0_VAL_L    0xD651 //current 24 bit value of the timer
#define T0_VAL_M    0xD652
#define T0_VAL_H    0xD653

#define T0_CMP_CTR  0xD654 //b0: t0 returns 0 on reaching target. b1: CMP = last value written to T0_VAL
#define T0_CMP_L    0xD655 //24 bit target value for comparison
#define T0_CMP_M    0xD656
#define T0_CMP_H    0xD657

#define T0_CMP_CTR_RECLEAR 0x01
#define T0_CMP_CTR_RELOAD  0x02

#define T0_WRAP_TICKS 0x1000000u
#define T0_MASK_TICKS 0x00FFFFFFu

#define T0_TICK_FREQ 30
#define VIDEO_DOT_CLOCK_HZ 25175000u
#define T0_TICK_PERIOD_TICKS (VIDEO_DOT_CLOCK_HZ / (uint32_t)T0_TICK_FREQ)
#define T0_TICK_CMP_L ((VIDEO_DOT_CLOCK_HZ/T0_TICK_FREQ)&0xFF)
#define T0_TICK_CMP_M (((VIDEO_DOT_CLOCK_HZ/T0_TICK_FREQ)>>8)&0xFF)
#define T0_TICK_CMP_H (((VIDEO_DOT_CLOCK_HZ/T0_TICK_FREQ)>>16)&0xFF)

typedef uint8_t timer_alarm_id_t;

enum {
	TIMER_ALARM_SPLASH = 0u,
	TIMER_ALARM_PUZZLE = 1u,
	TIMER_ALARM_SOUND = 2u,
	TIMER_ALARM_GENERAL0 = 3u,
	TIMER_ALARM_COUNT = 4u
};

void setTimer0(void);
void resetTimer0(void);
uint32_t readTimer0(void);
uint32_t readTimer0_consistent(void);
bool isTimerDone(void);
void timer_service(void);
void setAlarm(timer_alarm_id_t alarm, uint16_t ticks);
void clearAlarm(timer_alarm_id_t alarm);
bool checkAlarm(timer_alarm_id_t alarm);
uint16_t getAlarmTicks(timer_alarm_id_t alarm);
#endif // SRC_TIMER_H__
