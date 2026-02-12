        .include "build/struct_offsets.inc"
        .section .bss
        .lcomm layer_value,1

        .section .text
        .globl draw_lines_asm
        .extern g_line_list
        .extern g_line_count
        .extern g_line_fifo_timeouts


draw_lines_asm:
        sta layer_value
        ldy g_line_count
        beq draw_lines_done     ; if zero lines, then done
        lda #$01
        sta $D00A               ; Set to line drawing mode
        ldx #$00                ; offset into line list (bytes)

draw_lines_loop_start:
        lda layer_value         ; draw each line until y decrements to zero
        asl
        asl
        ora #$01
        sta $D180               ; enable -- may be able to pull this out of loop

        lda g_line_list + LINE_LIST_X0, x      ; x0 low
        sta $D182
        lda g_line_list + LINE_LIST_X0 + 1, x  ; x0 high
        sta $D183
        lda g_line_list + LINE_LIST_X1, x      ; x1 low
        sta $D184
        lda g_line_list + LINE_LIST_X1 + 1, x  ; x1 high
        sta $D185
        lda g_line_list + LINE_LIST_Y, x       ; y0 low
        sta $D186
        lda g_line_list + LINE_LIST_Y + 1, x   ; y1 high
        sta $D187
        lda g_line_list + LINE_LIST_COLOR, x   ; color
        sta $D181

        lda layer_value
        asl
        asl
        ora #$03
        sta $D180               ; clock in lines to draw

        inx
        inx                     ; next word (advance by 2 bytes)

wait_fifo_empty:
        ; Watchdog: bound the FIFO-drain wait so a hardware stall can't hang the frame.
        ; Uses nested counters to avoid needing 16-bit index mode.
        phx
        phy
        ldy #$40                ; outer-loop count (tune as needed)
wait_fifo_outer:
        ldx #$FF                ; inner-loop count
wait_fifo_inner:
        lda $D182               ; wait for fifo to zero
        ora $D183
        beq wait_fifo_ok
        dex
        bne wait_fifo_inner
        dey
        bne wait_fifo_outer

        ; Timeout: record and bail out (skip remaining lines).
        inc g_line_fifo_timeouts
        bne fifo_timeout_done
        inc g_line_fifo_timeouts+1
fifo_timeout_done:
        ply
        plx
        lda #$00
        sta $D180
        sta $D00A
        rts

wait_fifo_ok:
        ply
        plx

        dey
        bne draw_lines_loop_start ; loop until all lines drawn

draw_lines_done:
        lda #$00                ; done all lines
        sta $D180
        sta $D00A
        rts
