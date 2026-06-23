#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void get_number_of_active_players(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C90C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C910: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x8009C914: jr          $ra
    // 0x8009C918: nop

    return;
    // 0x8009C918: nop

;}
RECOMP_FUNC void transition_render_barndoor_vert(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C19FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1A04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C1A08: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C1A0C: jal         0x8007B820
    // 0x800C1A10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800C1A10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C1A14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C1A18: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C1A1C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C1A20: addiu       $t8, $t8, 0x3BD8
    ctx->r24 = ADD32(ctx->r24, 0X3BD8);
    // 0x800C1A24: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800C1A28: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C1A2C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C1A30: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C1A34: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800C1A38: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C1A3C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C1A40: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800C1A44: addiu       $a3, $a3, 0x3760
    ctx->r7 = ADD32(ctx->r7, 0X3760);
    // 0x800C1A48: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C1A4C: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800C1A50: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C1A54: addiu       $t1, $t1, 0x3750
    ctx->r9 = ADD32(ctx->r9, 0X3750);
    // 0x800C1A58: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C1A5C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800C1A60: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800C1A64: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800C1A68: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x800C1A6C: andi        $t7, $t6, 0x6
    ctx->r15 = ctx->r14 & 0X6;
    // 0x800C1A70: ori         $t8, $t7, 0x58
    ctx->r24 = ctx->r15 | 0X58;
    // 0x800C1A74: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800C1A78: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800C1A7C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800C1A80: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800C1A84: ori         $t4, $t3, 0xE0
    ctx->r12 = ctx->r11 | 0XE0;
    // 0x800C1A88: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800C1A8C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800C1A90: lui         $t3, 0x570
    ctx->r11 = S32(0X570 << 16);
    // 0x800C1A94: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800C1A98: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800C1A9C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800C1AA0: ori         $t3, $t3, 0x80
    ctx->r11 = ctx->r11 | 0X80;
    // 0x800C1AA4: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800C1AA8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C1AAC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C1AB0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C1AB4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800C1AB8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800C1ABC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800C1AC0: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800C1AC4: nop

    // 0x800C1AC8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C1ACC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800C1AD0: lw          $t6, 0x3758($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3758);
    // 0x800C1AD4: nop

    // 0x800C1AD8: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800C1ADC: jal         0x8007B820
    // 0x800C1AE0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C1AE0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    after_1:
    // 0x800C1AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C1AEC: jr          $ra
    // 0x800C1AF0: nop

    return;
    // 0x800C1AF0: nop

;}
RECOMP_FUNC void input_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A404: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8006A408: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006A40C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8006A410: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006A414: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8006A418: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A41C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006A420: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A424: addiu       $a0, $a0, 0x1660
    ctx->r4 = ADD32(ctx->r4, 0X1660);
    // 0x8006A428: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8006A42C: jal         0x800C9110
    // 0x8006A430: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8006A430: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8006A434: bne         $v0, $zero, L_8006A5AC
    if (ctx->r2 != 0) {
        // 0x8006A438: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8006A5AC;
    }
    // 0x8006A438: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A43C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A440: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006A444: addiu       $v1, $v1, 0x16A8
    ctx->r3 = ADD32(ctx->r3, 0X16A8);
    // 0x8006A448: addiu       $v0, $v0, 0x1690
    ctx->r2 = ADD32(ctx->r2, 0X1690);
    // 0x8006A44C: addiu       $a2, $a2, 0x16A8
    ctx->r6 = ADD32(ctx->r6, 0X16A8);
L_8006A450:
    // 0x8006A450: lwl         $at, 0x0($v0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r2, 0X0);
    // 0x8006A454: lwr         $at, 0x3($v0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r2, 0X3);
    // 0x8006A458: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8006A45C: swl         $at, 0x0($a2)
    do_swl(rdram, 0X0, ctx->r6, ctx->r1);
    // 0x8006A460: swr         $at, 0x3($a2)
    do_swr(rdram, 0X3, ctx->r6, ctx->r1);
    // 0x8006A464: lhu         $at, -0x2($v0)
    ctx->r1 = MEM_HU(ctx->r2, -0X2);
    // 0x8006A468: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // 0x8006A46C: sh          $at, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r1;
    // 0x8006A470: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8006A474: bne         $at, $zero, L_8006A450
    if (ctx->r1 != 0) {
        // 0x8006A478: nop
    
            goto L_8006A450;
    }
    // 0x8006A478: nop

    // 0x8006A47C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A480: jal         0x800CD604
    // 0x8006A484: addiu       $a0, $a0, 0x1690
    ctx->r4 = ADD32(ctx->r4, 0X1690);
    osContGetReadData_recomp(rdram, ctx);
        goto after_1;
    // 0x8006A484: addiu       $a0, $a0, 0x1690
    ctx->r4 = ADD32(ctx->r4, 0X1690);
    after_1:
    // 0x8006A488: beq         $s2, $zero, L_8006A598
    if (ctx->r18 == 0) {
        // 0x8006A48C: lw          $a0, 0x5C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X5C);
            goto L_8006A598;
    }
    // 0x8006A48C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8006A490: jal         0x8006ECD0
    // 0x8006A494: nop

    get_settings(rdram, ctx);
        goto after_2;
    // 0x8006A494: nop

    after_2:
    // 0x8006A498: andi        $v1, $s2, 0x3
    ctx->r3 = ctx->r18 & 0X3;
    // 0x8006A49C: beq         $v1, $zero, L_8006A4B0
    if (ctx->r3 == 0) {
        // 0x8006A4A0: sw          $v0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r2;
            goto L_8006A4B0;
    }
    // 0x8006A4A0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8006A4A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8006A4A8: jal         0x80074828
    // 0x8006A4AC: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    read_eeprom_data(rdram, ctx);
        goto after_3;
    // 0x8006A4AC: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    after_3:
L_8006A4B0:
    // 0x8006A4B0: andi        $t8, $s2, 0x8
    ctx->r24 = ctx->r18 & 0X8;
    // 0x8006A4B4: beq         $t8, $zero, L_8006A4EC
    if (ctx->r24 == 0) {
        // 0x8006A4B8: andi        $t9, $s2, 0x4
        ctx->r25 = ctx->r18 & 0X4;
            goto L_8006A4EC;
    }
    // 0x8006A4B8: andi        $t9, $s2, 0x4
    ctx->r25 = ctx->r18 & 0X4;
    // 0x8006A4BC: jal         0x8009C9D4
    // 0x8006A4C0: nop

    get_all_save_files_ptr(rdram, ctx);
        goto after_4;
    // 0x8006A4C0: nop

    after_4:
    // 0x8006A4C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006A4C8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8006A4CC:
    // 0x8006A4CC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8006A4D0: jal         0x8007445C
    // 0x8006A4D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    read_save_file(rdram, ctx);
        goto after_5;
    // 0x8006A4D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8006A4D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006A4DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006A4E0: bne         $s0, $at, L_8006A4CC
    if (ctx->r16 != ctx->r1) {
        // 0x8006A4E4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8006A4CC;
    }
    // 0x8006A4E4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8006A4E8: andi        $t9, $s2, 0x4
    ctx->r25 = ctx->r18 & 0X4;
L_8006A4EC:
    // 0x8006A4EC: beq         $t9, $zero, L_8006A504
    if (ctx->r25 == 0) {
        // 0x8006A4F0: sra         $a0, $s2, 8
        ctx->r4 = S32(SIGNED(ctx->r18) >> 8);
            goto L_8006A504;
    }
    // 0x8006A4F0: sra         $a0, $s2, 8
    ctx->r4 = S32(SIGNED(ctx->r18) >> 8);
    // 0x8006A4F4: andi        $t4, $a0, 0x3
    ctx->r12 = ctx->r4 & 0X3;
    // 0x8006A4F8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A4FC: jal         0x8007445C
    // 0x8006A500: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    read_save_file(rdram, ctx);
        goto after_6;
    // 0x8006A500: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_6:
L_8006A504:
    // 0x8006A504: andi        $v0, $s2, 0x30
    ctx->r2 = ctx->r18 & 0X30;
    // 0x8006A508: sra         $t5, $v0, 4
    ctx->r13 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8006A50C: beq         $t5, $zero, L_8006A524
    if (ctx->r13 == 0) {
        // 0x8006A510: andi        $t6, $s2, 0x40
        ctx->r14 = ctx->r18 & 0X40;
            goto L_8006A524;
    }
    // 0x8006A510: andi        $t6, $s2, 0x40
    ctx->r14 = ctx->r18 & 0X40;
    // 0x8006A514: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A518: jal         0x80074948
    // 0x8006A51C: andi        $a1, $t5, 0xFF
    ctx->r5 = ctx->r13 & 0XFF;
    write_eeprom_data(rdram, ctx);
        goto after_7;
    // 0x8006A51C: andi        $a1, $t5, 0xFF
    ctx->r5 = ctx->r13 & 0XFF;
    after_7:
    // 0x8006A520: andi        $t6, $s2, 0x40
    ctx->r14 = ctx->r18 & 0X40;
L_8006A524:
    // 0x8006A524: beq         $t6, $zero, L_8006A53C
    if (ctx->r14 == 0) {
        // 0x8006A528: sra         $a0, $s2, 10
        ctx->r4 = S32(SIGNED(ctx->r18) >> 10);
            goto L_8006A53C;
    }
    // 0x8006A528: sra         $a0, $s2, 10
    ctx->r4 = S32(SIGNED(ctx->r18) >> 10);
    // 0x8006A52C: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x8006A530: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A534: jal         0x80074734
    // 0x8006A538: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    write_save_data(rdram, ctx);
        goto after_8;
    // 0x8006A538: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_8:
L_8006A53C:
    // 0x8006A53C: andi        $t8, $s2, 0x80
    ctx->r24 = ctx->r18 & 0X80;
    // 0x8006A540: beq         $t8, $zero, L_8006A558
    if (ctx->r24 == 0) {
        // 0x8006A544: sra         $a0, $s2, 10
        ctx->r4 = S32(SIGNED(ctx->r18) >> 10);
            goto L_8006A558;
    }
    // 0x8006A544: sra         $a0, $s2, 10
    ctx->r4 = S32(SIGNED(ctx->r18) >> 10);
    // 0x8006A548: andi        $t9, $a0, 0x3
    ctx->r25 = ctx->r4 & 0X3;
    // 0x8006A54C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A550: jal         0x80074574
    // 0x8006A554: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    erase_save_file(rdram, ctx);
        goto after_9;
    // 0x8006A554: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_9:
L_8006A558:
    // 0x8006A558: andi        $t4, $s2, 0x100
    ctx->r12 = ctx->r18 & 0X100;
    // 0x8006A55C: beq         $t4, $zero, L_8006A578
    if (ctx->r12 == 0) {
        // 0x8006A560: andi        $t5, $s2, 0x200
        ctx->r13 = ctx->r18 & 0X200;
            goto L_8006A578;
    }
    // 0x8006A560: andi        $t5, $s2, 0x200
    ctx->r13 = ctx->r18 & 0X200;
    // 0x8006A564: jal         0x8009EFB0
    // 0x8006A568: nop

    get_eeprom_settings_pointer(rdram, ctx);
        goto after_10;
    // 0x8006A568: nop

    after_10:
    // 0x8006A56C: jal         0x80074ACC
    // 0x8006A570: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    read_eeprom_settings(rdram, ctx);
        goto after_11;
    // 0x8006A570: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x8006A574: andi        $t5, $s2, 0x200
    ctx->r13 = ctx->r18 & 0X200;
L_8006A578:
    // 0x8006A578: beq         $t5, $zero, L_8006A594
    if (ctx->r13 == 0) {
        // 0x8006A57C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8006A594;
    }
    // 0x8006A57C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8006A580: jal         0x8009EFB0
    // 0x8006A584: nop

    get_eeprom_settings_pointer(rdram, ctx);
        goto after_12;
    // 0x8006A584: nop

    after_12:
    // 0x8006A588: jal         0x80074BD4
    // 0x8006A58C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    write_eeprom_settings(rdram, ctx);
        goto after_13;
    // 0x8006A58C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x8006A590: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8006A594:
    // 0x8006A594: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
L_8006A598:
    // 0x8006A598: jal         0x80072964
    // 0x8006A59C: nop

    rumble_update(rdram, ctx);
        goto after_14;
    // 0x8006A59C: nop

    after_14:
    // 0x8006A5A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A5A4: jal         0x800CD540
    // 0x8006A5A8: addiu       $a0, $a0, 0x1660
    ctx->r4 = ADD32(ctx->r4, 0X1660);
    osContStartReadData_recomp(rdram, ctx);
        goto after_15;
    // 0x8006A5A8: addiu       $a0, $a0, 0x1660
    ctx->r4 = ADD32(ctx->r4, 0X1660);
    after_15:
L_8006A5AC:
    // 0x8006A5AC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8006A5B0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8006A5B4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A5B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A5BC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006A5C0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006A5C4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006A5C8: lhu         $t1, -0x278C($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X278C);
    // 0x8006A5CC: lw          $t2, -0x2790($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2790);
    // 0x8006A5D0: addiu       $t3, $t3, 0x16D0
    ctx->r11 = ADD32(ctx->r11, 0X16D0);
    // 0x8006A5D4: addiu       $a3, $a3, 0x16C8
    ctx->r7 = ADD32(ctx->r7, 0X16C8);
    // 0x8006A5D8: addiu       $t0, $t0, 0x16C0
    ctx->r8 = ADD32(ctx->r8, 0X16C0);
    // 0x8006A5DC: addiu       $v0, $v0, 0x1690
    ctx->r2 = ADD32(ctx->r2, 0X1690);
    // 0x8006A5E0: addiu       $a2, $a2, 0x16A8
    ctx->r6 = ADD32(ctx->r6, 0X16A8);
L_8006A5E4:
    // 0x8006A5E4: beq         $t2, $zero, L_8006A5F0
    if (ctx->r10 == 0) {
        // 0x8006A5E8: nop
    
            goto L_8006A5F0;
    }
    // 0x8006A5E8: nop

    // 0x8006A5EC: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_8006A5F0:
    // 0x8006A5F0: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8006A5F4: lhu         $a0, 0x0($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X0);
    // 0x8006A5F8: nop

    // 0x8006A5FC: xor         $a1, $v1, $a0
    ctx->r5 = ctx->r3 ^ ctx->r4;
    // 0x8006A600: and         $t6, $v1, $a1
    ctx->r14 = ctx->r3 & ctx->r5;
    // 0x8006A604: and         $t8, $a0, $a1
    ctx->r24 = ctx->r4 & ctx->r5;
    // 0x8006A608: and         $t7, $t6, $t1
    ctx->r15 = ctx->r14 & ctx->r9;
    // 0x8006A60C: and         $t9, $t8, $t1
    ctx->r25 = ctx->r24 & ctx->r9;
    // 0x8006A610: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
    // 0x8006A614: beq         $t2, $zero, L_8006A620
    if (ctx->r10 == 0) {
        // 0x8006A618: sh          $t9, 0x0($a3)
        MEM_H(0X0, ctx->r7) = ctx->r25;
            goto L_8006A620;
    }
    // 0x8006A618: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
    // 0x8006A61C: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
L_8006A620:
    // 0x8006A620: lhu         $v1, 0x6($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X6);
    // 0x8006A624: lhu         $a0, 0x6($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X6);
    // 0x8006A628: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8006A62C: xor         $a1, $v1, $a0
    ctx->r5 = ctx->r3 ^ ctx->r4;
    // 0x8006A630: and         $t4, $v1, $a1
    ctx->r12 = ctx->r3 & ctx->r5;
    // 0x8006A634: and         $t6, $a0, $a1
    ctx->r14 = ctx->r4 & ctx->r5;
    // 0x8006A638: and         $t7, $t6, $t1
    ctx->r15 = ctx->r14 & ctx->r9;
    // 0x8006A63C: and         $t5, $t4, $t1
    ctx->r13 = ctx->r12 & ctx->r9;
    // 0x8006A640: sh          $t5, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r13;
    // 0x8006A644: sh          $t7, -0x2($a3)
    MEM_H(-0X2, ctx->r7) = ctx->r15;
    // 0x8006A648: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x8006A64C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8006A650: bne         $a3, $t3, L_8006A5E4
    if (ctx->r7 != ctx->r11) {
        // 0x8006A654: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8006A5E4;
    }
    // 0x8006A654: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8006A658: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006A65C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8006A660: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006A664: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A668: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A66C: jr          $ra
    // 0x8006A670: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8006A670: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void load_sprite_info(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CD30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007CD34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007CD38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007CD3C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007CD40: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007CD44: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007CD48: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007CD4C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007CD50: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8007CD54: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8007CD58: bltz        $a0, L_8007CD78
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007CD5C: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_8007CD78;
    }
    // 0x8007CD5C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8007CD60: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007CD64: lw          $t6, 0x68F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68F4);
    // 0x8007CD68: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007CD6C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007CD70: bne         $at, $zero, L_8007CD9C
    if (ctx->r1 != 0) {
        // 0x8007CD74: sll         $t1, $s0, 2
        ctx->r9 = S32(ctx->r16 << 2);
            goto L_8007CD9C;
    }
    // 0x8007CD74: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
L_8007CD78:
    // 0x8007CD78: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8007CD7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007CD80: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8007CD84: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8007CD88: nop

    // 0x8007CD8C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8007CD90: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8007CD94: b           L_8007CE98
    // 0x8007CD98: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
        goto L_8007CE98;
    // 0x8007CD98: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_8007CD9C:
    // 0x8007CD9C: lw          $t0, 0x68E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X68E8);
    // 0x8007CDA0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8007CDA4: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8007CDA8: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007CDAC: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8007CDB0: lw          $s3, 0x68F0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X68F0);
    // 0x8007CDB4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8007CDB8: subu        $a3, $t2, $a2
    ctx->r7 = SUB32(ctx->r10, ctx->r6);
    // 0x8007CDBC: jal         0x80077190
    // 0x8007CDC0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    asset_load(rdram, ctx);
        goto after_0;
    // 0x8007CDC0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x8007CDC4: lbu         $t3, 0xC($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0XC);
    // 0x8007CDC8: lh          $t4, 0x0($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X0);
    // 0x8007CDCC: jal         0x8007B2C4
    // 0x8007CDD0: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    load_texture(rdram, ctx);
        goto after_1;
    // 0x8007CDD0: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_1:
    // 0x8007CDD4: beq         $v0, $zero, L_8007CD78
    if (ctx->r2 == 0) {
        // 0x8007CDD8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8007CD78;
    }
    // 0x8007CDD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8007CDDC: lbu         $t5, 0x2($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2);
    // 0x8007CDE0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8007CDE4: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x8007CDE8: jal         0x8007B70C
    // 0x8007CDEC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    tex_free(rdram, ctx);
        goto after_2;
    // 0x8007CDEC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    after_2:
    // 0x8007CDF0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8007CDF4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8007CDF8: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8007CDFC: lh          $v1, 0x2($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X2);
    // 0x8007CE00: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x8007CE04: blez        $v1, L_8007CE70
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007CE08: lw          $t3, 0x3C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X3C);
            goto L_8007CE70;
    }
    // 0x8007CE08: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
L_8007CE0C:
    // 0x8007CE0C: lbu         $s0, 0xC($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0XC);
    // 0x8007CE10: lbu         $t8, 0xD($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0XD);
    // 0x8007CE14: nop

    // 0x8007CE18: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8007CE1C: beq         $at, $zero, L_8007CE5C
    if (ctx->r1 == 0) {
        // 0x8007CE20: nop
    
            goto L_8007CE5C;
    }
    // 0x8007CE20: nop

L_8007CE24:
    // 0x8007CE24: lh          $t9, 0x0($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X0);
    // 0x8007CE28: jal         0x8007C9CC
    // 0x8007CE2C: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    tex_asset_size(rdram, ctx);
        goto after_3;
    // 0x8007CE2C: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    after_3:
    // 0x8007CE30: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8007CE34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007CE38: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8007CE3C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8007CE40: lbu         $t2, 0xD($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0XD);
    // 0x8007CE44: nop

    // 0x8007CE48: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007CE4C: bne         $at, $zero, L_8007CE24
    if (ctx->r1 != 0) {
        // 0x8007CE50: nop
    
            goto L_8007CE24;
    }
    // 0x8007CE50: nop

    // 0x8007CE54: lh          $v1, 0x2($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X2);
    // 0x8007CE58: nop

L_8007CE5C:
    // 0x8007CE5C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8007CE60: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007CE64: bne         $at, $zero, L_8007CE0C
    if (ctx->r1 != 0) {
        // 0x8007CE68: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8007CE0C;
    }
    // 0x8007CE68: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007CE6C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
L_8007CE70:
    // 0x8007CE70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007CE74: sw          $v1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r3;
    // 0x8007CE78: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8007CE7C: lh          $t4, 0x4($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X4);
    // 0x8007CE80: nop

    // 0x8007CE84: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8007CE88: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8007CE8C: lh          $t6, 0x6($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X6);
    // 0x8007CE90: nop

    // 0x8007CE94: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_8007CE98:
    // 0x8007CE98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007CE9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007CEA0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CEA4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007CEA8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8007CEAC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007CEB0: jr          $ra
    // 0x8007CEB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007CEB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void objFreeAssets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F648: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000F64C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000F650: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000F654: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8000F658: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8000F65C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000F660: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000F664: bne         $a2, $zero, L_8000F6B0
    if (ctx->r6 != 0) {
        // 0x8000F668: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8000F6B0;
    }
    // 0x8000F668: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000F66C: blez        $a1, L_8000F73C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8000F670: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000F73C;
    }
    // 0x8000F670: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000F674: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000F678:
    // 0x8000F678: lw          $t6, 0x68($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X68);
    // 0x8000F67C: nop

    // 0x8000F680: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8000F684: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8000F688: nop

    // 0x8000F68C: beq         $v0, $zero, L_8000F69C
    if (ctx->r2 == 0) {
        // 0x8000F690: nop
    
            goto L_8000F69C;
    }
    // 0x8000F690: nop

    // 0x8000F694: jal         0x80060180
    // 0x8000F698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    free_3d_model(rdram, ctx);
        goto after_0;
    // 0x8000F698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_0:
L_8000F69C:
    // 0x8000F69C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000F6A0: bne         $s1, $s2, L_8000F678
    if (ctx->r17 != ctx->r18) {
        // 0x8000F6A4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F678;
    }
    // 0x8000F6A4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000F6A8: b           L_8000F740
    // 0x8000F6AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8000F740;
    // 0x8000F6AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000F6B0:
    // 0x8000F6B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000F6B4: bne         $a2, $at, L_8000F700
    if (ctx->r6 != ctx->r1) {
        // 0x8000F6B8: nop
    
            goto L_8000F700;
    }
    // 0x8000F6B8: nop

    // 0x8000F6BC: blez        $s2, L_8000F73C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8000F6C0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000F73C;
    }
    // 0x8000F6C0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000F6C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000F6C8:
    // 0x8000F6C8: lw          $t8, 0x68($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X68);
    // 0x8000F6CC: nop

    // 0x8000F6D0: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8000F6D4: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8000F6D8: nop

    // 0x8000F6DC: beq         $v0, $zero, L_8000F6EC
    if (ctx->r2 == 0) {
        // 0x8000F6E0: nop
    
            goto L_8000F6EC;
    }
    // 0x8000F6E0: nop

    // 0x8000F6E4: jal         0x8007B70C
    // 0x8000F6E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_1;
    // 0x8000F6E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
L_8000F6EC:
    // 0x8000F6EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000F6F0: bne         $s1, $s2, L_8000F6C8
    if (ctx->r17 != ctx->r18) {
        // 0x8000F6F4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F6C8;
    }
    // 0x8000F6F4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000F6F8: b           L_8000F740
    // 0x8000F6FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8000F740;
    // 0x8000F6FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000F700:
    // 0x8000F700: blez        $s2, L_8000F73C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8000F704: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000F73C;
    }
    // 0x8000F704: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000F708: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000F70C:
    // 0x8000F70C: lw          $t0, 0x68($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X68);
    // 0x8000F710: nop

    // 0x8000F714: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x8000F718: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8000F71C: nop

    // 0x8000F720: beq         $v0, $zero, L_8000F730
    if (ctx->r2 == 0) {
        // 0x8000F724: nop
    
            goto L_8000F730;
    }
    // 0x8000F724: nop

    // 0x8000F728: jal         0x8007D100
    // 0x8000F72C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sprite_free(rdram, ctx);
        goto after_2;
    // 0x8000F72C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
L_8000F730:
    // 0x8000F730: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000F734: bne         $s1, $s2, L_8000F70C
    if (ctx->r17 != ctx->r18) {
        // 0x8000F738: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F70C;
    }
    // 0x8000F738: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000F73C:
    // 0x8000F73C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000F740:
    // 0x8000F740: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000F744: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000F748: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F74C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000F750: jr          $ra
    // 0x8000F754: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000F754: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mempool_slot_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007188C: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x80071890: multu       $a1, $t2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071894: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80071898: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8007189C: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800718A0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800718A4: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800718A8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800718AC: mflo        $t8
    ctx->r24 = lo;
    // 0x800718B0: addu        $a3, $t8, $v0
    ctx->r7 = ADD32(ctx->r24, ctx->r2);
    // 0x800718B4: lh          $a2, 0xC($a3)
    ctx->r6 = MEM_H(ctx->r7, 0XC);
    // 0x800718B8: lh          $t0, 0xA($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XA);
    // 0x800718BC: beq         $a2, $t3, L_80071934
    if (ctx->r6 == ctx->r11) {
        // 0x800718C0: sh          $zero, 0x8($a3)
        MEM_H(0X8, ctx->r7) = 0;
            goto L_80071934;
    }
    // 0x800718C0: sh          $zero, 0x8($a3)
    MEM_H(0X8, ctx->r7) = 0;
    // 0x800718C4: multu       $a2, $t2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800718C8: mflo        $t9
    ctx->r25 = lo;
    // 0x800718CC: addu        $a0, $t9, $v0
    ctx->r4 = ADD32(ctx->r25, ctx->r2);
    // 0x800718D0: lh          $t4, 0x8($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X8);
    // 0x800718D4: nop

    // 0x800718D8: bne         $t4, $zero, L_80071934
    if (ctx->r12 != 0) {
        // 0x800718DC: nop
    
            goto L_80071934;
    }
    // 0x800718DC: nop

    // 0x800718E0: lw          $t5, 0x4($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X4);
    // 0x800718E4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800718E8: nop

    // 0x800718EC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800718F0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800718F4: lh          $t1, 0xC($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XC);
    // 0x800718F8: nop

    // 0x800718FC: beq         $t1, $t3, L_80071914
    if (ctx->r9 == ctx->r11) {
        // 0x80071900: sh          $t1, 0xC($a3)
        MEM_H(0XC, ctx->r7) = ctx->r9;
            goto L_80071914;
    }
    // 0x80071900: sh          $t1, 0xC($a3)
    MEM_H(0XC, ctx->r7) = ctx->r9;
    // 0x80071904: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071908: mflo        $t8
    ctx->r24 = lo;
    // 0x8007190C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80071910: sh          $a1, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r5;
L_80071914:
    // 0x80071914: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x80071918: nop

    // 0x8007191C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80071920: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071924: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80071928: mflo        $t7
    ctx->r15 = lo;
    // 0x8007192C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80071930: sh          $a2, 0xE($t8)
    MEM_H(0XE, ctx->r24) = ctx->r6;
L_80071934:
    // 0x80071934: beq         $t0, $t3, L_800719AC
    if (ctx->r8 == ctx->r11) {
        // 0x80071938: nop
    
            goto L_800719AC;
    }
    // 0x80071938: nop

    // 0x8007193C: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071940: mflo        $t9
    ctx->r25 = lo;
    // 0x80071944: addu        $a0, $t9, $v0
    ctx->r4 = ADD32(ctx->r25, ctx->r2);
    // 0x80071948: lh          $t4, 0x8($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X8);
    // 0x8007194C: nop

    // 0x80071950: bne         $t4, $zero, L_800719AC
    if (ctx->r12 != 0) {
        // 0x80071954: nop
    
            goto L_800719AC;
    }
    // 0x80071954: nop

    // 0x80071958: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8007195C: lw          $t6, 0x4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X4);
    // 0x80071960: nop

    // 0x80071964: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80071968: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007196C: lh          $t1, 0xC($a3)
    ctx->r9 = MEM_H(ctx->r7, 0XC);
    // 0x80071970: nop

    // 0x80071974: beq         $t1, $t3, L_8007198C
    if (ctx->r9 == ctx->r11) {
        // 0x80071978: sh          $t1, 0xC($a0)
        MEM_H(0XC, ctx->r4) = ctx->r9;
            goto L_8007198C;
    }
    // 0x80071978: sh          $t1, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r9;
    // 0x8007197C: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071980: mflo        $t8
    ctx->r24 = lo;
    // 0x80071984: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80071988: sh          $t0, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r8;
L_8007198C:
    // 0x8007198C: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x80071990: nop

    // 0x80071994: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80071998: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007199C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800719A0: mflo        $t7
    ctx->r15 = lo;
    // 0x800719A4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800719A8: sh          $a1, 0xE($t8)
    MEM_H(0XE, ctx->r24) = ctx->r5;
L_800719AC:
    // 0x800719AC: jr          $ra
    // 0x800719B0: nop

    return;
    // 0x800719B0: nop

;}
RECOMP_FUNC void s32_to_string(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5D6C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C5D70: bgez        $a1, L_800C5D88
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800C5D74: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800C5D88;
    }
    // 0x800C5D74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C5D78: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x800C5D7C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800C5D80: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C5D84: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_800C5D88:
    // 0x800C5D88: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C5D8C: lw          $a3, 0x3C7C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3C7C);
    // 0x800C5D90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800C5D94: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C5D98: bne         $at, $zero, L_800C5DF0
    if (ctx->r1 != 0) {
        // 0x800C5D9C: addiu       $t1, $zero, 0x30
        ctx->r9 = ADD32(0, 0X30);
            goto L_800C5DF0;
    }
    // 0x800C5D9C: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800C5DA0: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x800C5DA4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C5DA8: bne         $a3, $zero, L_800C5DB4
    if (ctx->r7 != 0) {
        // 0x800C5DAC: nop
    
            goto L_800C5DB4;
    }
    // 0x800C5DAC: nop

    // 0x800C5DB0: break       7
    do_break(2148294064);
L_800C5DB4:
    // 0x800C5DB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5DB8: bne         $a3, $at, L_800C5DCC
    if (ctx->r7 != ctx->r1) {
        // 0x800C5DBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5DCC;
    }
    // 0x800C5DBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5DC0: bne         $a1, $at, L_800C5DCC
    if (ctx->r5 != ctx->r1) {
        // 0x800C5DC4: nop
    
            goto L_800C5DCC;
    }
    // 0x800C5DC4: nop

    // 0x800C5DC8: break       6
    do_break(2148294088);
L_800C5DCC:
    // 0x800C5DCC: mflo        $t3
    ctx->r11 = lo;
    // 0x800C5DD0: addiu       $t1, $t3, 0x30
    ctx->r9 = ADD32(ctx->r11, 0X30);
    // 0x800C5DD4: andi        $t8, $t1, 0xFF
    ctx->r24 = ctx->r9 & 0XFF;
    // 0x800C5DD8: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5DDC: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x800C5DE0: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x800C5DE4: mflo        $t7
    ctx->r15 = lo;
    // 0x800C5DE8: subu        $a1, $a1, $t7
    ctx->r5 = SUB32(ctx->r5, ctx->r15);
    // 0x800C5DEC: nop

L_800C5DF0:
    // 0x800C5DF0: beq         $v1, $zero, L_800C5E00
    if (ctx->r3 == 0) {
        // 0x800C5DF4: sll         $t9, $a2, 2
        ctx->r25 = S32(ctx->r6 << 2);
            goto L_800C5E00;
    }
    // 0x800C5DF4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C5DF8: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800C5DFC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C5E00:
    // 0x800C5E00: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800C5E04: addiu       $t5, $t5, 0x3C7C
    ctx->r13 = ADD32(ctx->r13, 0X3C7C);
    // 0x800C5E08: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800C5E0C: addiu       $t4, $t4, 0x3CA0
    ctx->r12 = ADD32(ctx->r12, 0X3CA0);
    // 0x800C5E10: addu        $t0, $t9, $t5
    ctx->r8 = ADD32(ctx->r25, ctx->r13);
L_800C5E14:
    // 0x800C5E14: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x800C5E18: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800C5E1C: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800C5E20: bne         $at, $zero, L_800C5E78
    if (ctx->r1 != 0) {
        // 0x800C5E24: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_800C5E78;
    }
    // 0x800C5E24: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800C5E28: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x800C5E2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C5E30: bne         $a2, $zero, L_800C5E3C
    if (ctx->r6 != 0) {
        // 0x800C5E34: nop
    
            goto L_800C5E3C;
    }
    // 0x800C5E34: nop

    // 0x800C5E38: break       7
    do_break(2148294200);
L_800C5E3C:
    // 0x800C5E3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5E40: bne         $a2, $at, L_800C5E54
    if (ctx->r6 != ctx->r1) {
        // 0x800C5E44: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5E54;
    }
    // 0x800C5E44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5E48: bne         $a1, $at, L_800C5E54
    if (ctx->r5 != ctx->r1) {
        // 0x800C5E4C: nop
    
            goto L_800C5E54;
    }
    // 0x800C5E4C: nop

    // 0x800C5E50: break       6
    do_break(2148294224);
L_800C5E54:
    // 0x800C5E54: mflo        $a3
    ctx->r7 = lo;
    // 0x800C5E58: addiu       $t1, $a3, 0x30
    ctx->r9 = ADD32(ctx->r7, 0X30);
    // 0x800C5E5C: andi        $t7, $t1, 0xFF
    ctx->r15 = ctx->r9 & 0XFF;
    // 0x800C5E60: multu       $a3, $a2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5E64: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x800C5E68: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x800C5E6C: mflo        $t6
    ctx->r14 = lo;
    // 0x800C5E70: subu        $a1, $a1, $t6
    ctx->r5 = SUB32(ctx->r5, ctx->r14);
    // 0x800C5E74: nop

L_800C5E78:
    // 0x800C5E78: beq         $v1, $zero, L_800C5E88
    if (ctx->r3 == 0) {
        // 0x800C5E7C: nop
    
            goto L_800C5E88;
    }
    // 0x800C5E7C: nop

    // 0x800C5E80: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800C5E84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C5E88:
    // 0x800C5E88: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x800C5E8C: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800C5E90: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C5E94: bne         $at, $zero, L_800C5EEC
    if (ctx->r1 != 0) {
        // 0x800C5E98: nop
    
            goto L_800C5EEC;
    }
    // 0x800C5E98: nop

    // 0x800C5E9C: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x800C5EA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C5EA4: bne         $a3, $zero, L_800C5EB0
    if (ctx->r7 != 0) {
        // 0x800C5EA8: nop
    
            goto L_800C5EB0;
    }
    // 0x800C5EA8: nop

    // 0x800C5EAC: break       7
    do_break(2148294316);
L_800C5EB0:
    // 0x800C5EB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5EB4: bne         $a3, $at, L_800C5EC8
    if (ctx->r7 != ctx->r1) {
        // 0x800C5EB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5EC8;
    }
    // 0x800C5EB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5EBC: bne         $a1, $at, L_800C5EC8
    if (ctx->r5 != ctx->r1) {
        // 0x800C5EC0: nop
    
            goto L_800C5EC8;
    }
    // 0x800C5EC0: nop

    // 0x800C5EC4: break       6
    do_break(2148294340);
L_800C5EC8:
    // 0x800C5EC8: mflo        $t3
    ctx->r11 = lo;
    // 0x800C5ECC: addiu       $t1, $t3, 0x30
    ctx->r9 = ADD32(ctx->r11, 0X30);
    // 0x800C5ED0: andi        $t9, $t1, 0xFF
    ctx->r25 = ctx->r9 & 0XFF;
    // 0x800C5ED4: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5ED8: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x800C5EDC: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x800C5EE0: mflo        $t8
    ctx->r24 = lo;
    // 0x800C5EE4: subu        $a1, $a1, $t8
    ctx->r5 = SUB32(ctx->r5, ctx->r24);
    // 0x800C5EE8: nop

L_800C5EEC:
    // 0x800C5EEC: beq         $v1, $zero, L_800C5EFC
    if (ctx->r3 == 0) {
        // 0x800C5EF0: nop
    
            goto L_800C5EFC;
    }
    // 0x800C5EF0: nop

    // 0x800C5EF4: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800C5EF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C5EFC:
    // 0x800C5EFC: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    // 0x800C5F00: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800C5F04: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C5F08: bne         $at, $zero, L_800C5F60
    if (ctx->r1 != 0) {
        // 0x800C5F0C: nop
    
            goto L_800C5F60;
    }
    // 0x800C5F0C: nop

    // 0x800C5F10: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x800C5F14: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C5F18: bne         $a3, $zero, L_800C5F24
    if (ctx->r7 != 0) {
        // 0x800C5F1C: nop
    
            goto L_800C5F24;
    }
    // 0x800C5F1C: nop

    // 0x800C5F20: break       7
    do_break(2148294432);
L_800C5F24:
    // 0x800C5F24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5F28: bne         $a3, $at, L_800C5F3C
    if (ctx->r7 != ctx->r1) {
        // 0x800C5F2C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5F3C;
    }
    // 0x800C5F2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5F30: bne         $a1, $at, L_800C5F3C
    if (ctx->r5 != ctx->r1) {
        // 0x800C5F34: nop
    
            goto L_800C5F3C;
    }
    // 0x800C5F34: nop

    // 0x800C5F38: break       6
    do_break(2148294456);
L_800C5F3C:
    // 0x800C5F3C: mflo        $t3
    ctx->r11 = lo;
    // 0x800C5F40: addiu       $t1, $t3, 0x30
    ctx->r9 = ADD32(ctx->r11, 0X30);
    // 0x800C5F44: andi        $t6, $t1, 0xFF
    ctx->r14 = ctx->r9 & 0XFF;
    // 0x800C5F48: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5F4C: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x800C5F50: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x800C5F54: mflo        $t5
    ctx->r13 = lo;
    // 0x800C5F58: subu        $a1, $a1, $t5
    ctx->r5 = SUB32(ctx->r5, ctx->r13);
    // 0x800C5F5C: nop

L_800C5F60:
    // 0x800C5F60: beq         $v1, $zero, L_800C5F70
    if (ctx->r3 == 0) {
        // 0x800C5F64: nop
    
            goto L_800C5F70;
    }
    // 0x800C5F64: nop

    // 0x800C5F68: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800C5F6C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C5F70:
    // 0x800C5F70: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x800C5F74: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x800C5F78: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C5F7C: bne         $at, $zero, L_800C5FD4
    if (ctx->r1 != 0) {
        // 0x800C5F80: addiu       $t1, $zero, 0x30
        ctx->r9 = ADD32(0, 0X30);
            goto L_800C5FD4;
    }
    // 0x800C5F80: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800C5F84: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x800C5F88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C5F8C: bne         $a3, $zero, L_800C5F98
    if (ctx->r7 != 0) {
        // 0x800C5F90: nop
    
            goto L_800C5F98;
    }
    // 0x800C5F90: nop

    // 0x800C5F94: break       7
    do_break(2148294548);
L_800C5F98:
    // 0x800C5F98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5F9C: bne         $a3, $at, L_800C5FB0
    if (ctx->r7 != ctx->r1) {
        // 0x800C5FA0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5FB0;
    }
    // 0x800C5FA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5FA4: bne         $a1, $at, L_800C5FB0
    if (ctx->r5 != ctx->r1) {
        // 0x800C5FA8: nop
    
            goto L_800C5FB0;
    }
    // 0x800C5FA8: nop

    // 0x800C5FAC: break       6
    do_break(2148294572);
L_800C5FB0:
    // 0x800C5FB0: mflo        $t3
    ctx->r11 = lo;
    // 0x800C5FB4: addiu       $t1, $t3, 0x30
    ctx->r9 = ADD32(ctx->r11, 0X30);
    // 0x800C5FB8: andi        $t8, $t1, 0xFF
    ctx->r24 = ctx->r9 & 0XFF;
    // 0x800C5FBC: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5FC0: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x800C5FC4: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x800C5FC8: mflo        $t7
    ctx->r15 = lo;
    // 0x800C5FCC: subu        $a1, $a1, $t7
    ctx->r5 = SUB32(ctx->r5, ctx->r15);
    // 0x800C5FD0: nop

L_800C5FD4:
    // 0x800C5FD4: beq         $v1, $zero, L_800C5FE4
    if (ctx->r3 == 0) {
        // 0x800C5FD8: nop
    
            goto L_800C5FE4;
    }
    // 0x800C5FD8: nop

    // 0x800C5FDC: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800C5FE0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C5FE4:
    // 0x800C5FE4: bne         $t0, $t4, L_800C5E14
    if (ctx->r8 != ctx->r12) {
        // 0x800C5FE8: nop
    
            goto L_800C5E14;
    }
    // 0x800C5FE8: nop

    // 0x800C5FEC: addiu       $t9, $a1, 0x30
    ctx->r25 = ADD32(ctx->r5, 0X30);
    // 0x800C5FF0: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800C5FF4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C5FF8: jr          $ra
    // 0x800C5FFC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x800C5FFC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void set_gIntDisFlag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F7A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F7A8: jr          $ra
    // 0x8006F7AC: sb          $a0, -0x2660($at)
    MEM_B(-0X2660, ctx->r1) = ctx->r4;
    return;
    // 0x8006F7AC: sb          $a0, -0x2660($at)
    MEM_B(-0X2660, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void trackmenu_timetrial_sound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091390: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80091394: lw          $t6, 0x6980($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6980);
    // 0x80091398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009139C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800913A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800913A4: bne         $t6, $at, L_800913D8
    if (ctx->r14 != ctx->r1) {
        // 0x800913A8: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800913D8;
    }
    // 0x800913A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800913AC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800913B0: lw          $t7, 0x994($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X994);
    // 0x800913B4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800913B8: bne         $t7, $zero, L_800913D8
    if (ctx->r15 != 0) {
        // 0x800913BC: addiu       $a1, $a1, 0x6DE0
        ctx->r5 = ADD32(ctx->r5, 0X6DE0);
            goto L_800913D8;
    }
    // 0x800913BC: addiu       $a1, $a1, 0x6DE0
    ctx->r5 = ADD32(ctx->r5, 0X6DE0);
    // 0x800913C0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800913C4: nop

    // 0x800913C8: bne         $t8, $zero, L_800913DC
    if (ctx->r24 != 0) {
        // 0x800913CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800913DC;
    }
    // 0x800913CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800913D0: jal         0x80001D04
    // 0x800913D4: addiu       $a0, $zero, 0x132
    ctx->r4 = ADD32(0, 0X132);
    sound_play(rdram, ctx);
        goto after_0;
    // 0x800913D4: addiu       $a0, $zero, 0x132
    ctx->r4 = ADD32(0, 0X132);
    after_0:
L_800913D8:
    // 0x800913D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800913DC:
    // 0x800913DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800913E0: jr          $ra
    // 0x800913E4: nop

    return;
    // 0x800913E4: nop

;}
RECOMP_FUNC void particle_free_dummy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE838: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AE83C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800AE840: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800AE844: addiu       $s3, $s3, 0x33F0
    ctx->r19 = ADD32(ctx->r19, 0X33F0);
    // 0x800AE848: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800AE84C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AE850: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800AE854: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800AE858: beq         $a0, $zero, L_800AE8B8
    if (ctx->r4 == 0) {
        // 0x800AE85C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800AE8B8;
    }
    // 0x800AE85C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800AE860: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800AE864: addiu       $s2, $s2, 0x33F4
    ctx->r18 = ADD32(ctx->r18, 0X33F4);
    // 0x800AE868: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800AE86C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AE870: blez        $t6, L_800AE8AC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800AE874: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800AE8AC;
    }
    // 0x800AE874: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AE878:
    // 0x800AE878: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800AE87C: nop

    // 0x800AE880: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800AE884: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800AE888: jal         0x8007D100
    // 0x800AE88C: nop

    sprite_free(rdram, ctx);
        goto after_0;
    // 0x800AE88C: nop

    after_0:
    // 0x800AE890: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800AE894: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800AE898: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AE89C: bne         $at, $zero, L_800AE878
    if (ctx->r1 != 0) {
        // 0x800AE8A0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800AE878;
    }
    // 0x800AE8A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800AE8A4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800AE8A8: nop

L_800AE8AC:
    // 0x800AE8AC: jal         0x80071380
    // 0x800AE8B0: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800AE8B0: nop

    after_1:
    // 0x800AE8B4: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_800AE8B8:
    // 0x800AE8B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AE8BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AE8C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AE8C4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE8C8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800AE8CC: jr          $ra
    // 0x800AE8D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AE8D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void cpak_free_files(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800763BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800763C0: lw          $a0, -0x1650($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1650);
    // 0x800763C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800763C8: beq         $a0, $zero, L_800763D8
    if (ctx->r4 == 0) {
        // 0x800763CC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800763D8;
    }
    // 0x800763CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800763D0: jal         0x80071380
    // 0x800763D4: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800763D4: nop

    after_0:
L_800763D8:
    // 0x800763D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800763DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800763E0: sw          $zero, -0x1650($at)
    MEM_W(-0X1650, ctx->r1) = 0;
    // 0x800763E4: jr          $ra
    // 0x800763E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800763E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void obj_loop_levelname(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042AD0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80042AD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80042AD8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80042ADC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80042AE0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80042AE4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80042AE8: jal         0x8001BB4C
    // 0x80042AEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object_by_port(rdram, ctx);
        goto after_0;
    // 0x80042AEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80042AF0: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x80042AF4: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80042AF8: beq         $v0, $zero, L_80042D04
    if (ctx->r2 == 0) {
        // 0x80042AFC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80042D04;
    }
    // 0x80042AFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80042B00: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80042B04: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80042B08: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80042B0C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80042B10: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80042B14: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80042B18: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80042B1C: lwc1        $f6, 0x78($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X78);
    // 0x80042B20: addiu       $s0, $a2, 0x78
    ctx->r16 = ADD32(ctx->r6, 0X78);
    // 0x80042B24: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80042B28: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80042B2C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80042B30: nop

    // 0x80042B34: bc1f        L_80042B74
    if (!c1cs) {
        // 0x80042B38: nop
    
            goto L_80042B74;
    }
    // 0x80042B38: nop

    // 0x80042B3C: addiu       $s0, $a2, 0x78
    ctx->r16 = ADD32(ctx->r6, 0X78);
    // 0x80042B40: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x80042B44: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80042B48: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80042B4C: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
    // 0x80042B50: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x80042B54: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x80042B58: slti        $at, $v0, 0x101
    ctx->r1 = SIGNED(ctx->r2) < 0X101 ? 1 : 0;
    // 0x80042B5C: bne         $at, $zero, L_80042BA0
    if (ctx->r1 != 0) {
        // 0x80042B60: nop
    
            goto L_80042BA0;
    }
    // 0x80042B60: nop

    // 0x80042B64: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x80042B68: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x80042B6C: b           L_80042BA0
    // 0x80042B70: nop

        goto L_80042BA0;
    // 0x80042B70: nop

L_80042B74:
    // 0x80042B74: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x80042B78: sll         $t1, $v1, 4
    ctx->r9 = S32(ctx->r3 << 4);
    // 0x80042B7C: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80042B80: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
    // 0x80042B84: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x80042B88: nop

    // 0x80042B8C: bgez        $v0, L_80042BA0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80042B90: nop
    
            goto L_80042BA0;
    }
    // 0x80042B90: nop

    // 0x80042B94: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x80042B98: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x80042B9C: nop

L_80042BA0:
    // 0x80042BA0: blez        $v0, L_80042D04
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80042BA4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80042D04;
    }
    // 0x80042BA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80042BA8: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x80042BAC: jal         0x8006C01C
    // 0x80042BB0: nop

    level_name(rdram, ctx);
        goto after_1;
    // 0x80042BB0: nop

    after_1:
    // 0x80042BB4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80042BB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80042BBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042BC0: jal         0x800C5300
    // 0x80042BC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    get_text_width(rdram, ctx);
        goto after_2;
    // 0x80042BC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80042BC8: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x80042BCC: sra         $t3, $v1, 1
    ctx->r11 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80042BD0: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80042BD4: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80042BD8: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x80042BDC: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x80042BE0: addiu       $t6, $t3, 0xA0
    ctx->r14 = ADD32(ctx->r11, 0XA0);
    // 0x80042BE4: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x80042BE8: bne         $t7, $zero, L_80042C04
    if (ctx->r15 != 0) {
        // 0x80042BEC: sw          $t6, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r14;
            goto L_80042C04;
    }
    // 0x80042BEC: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x80042BF0: addiu       $t8, $zero, 0xE0
    ctx->r24 = ADD32(0, 0XE0);
    // 0x80042BF4: addiu       $t9, $zero, 0xF8
    ctx->r25 = ADD32(0, 0XF8);
    // 0x80042BF8: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80042BFC: b           L_80042C14
    // 0x80042C00: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_80042C14;
    // 0x80042C00: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_80042C04:
    // 0x80042C04: addiu       $t0, $zero, 0xCA
    ctx->r8 = ADD32(0, 0XCA);
    // 0x80042C08: addiu       $t1, $zero, 0xDE
    ctx->r9 = ADD32(0, 0XDE);
    // 0x80042C0C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80042C10: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_80042C14:
    // 0x80042C14: jal         0x800C59F4
    // 0x80042C18: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    dialogue_clear(rdram, ctx);
        goto after_3;
    // 0x80042C18: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_3:
    // 0x80042C1C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80042C20: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80042C24: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80042C28: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80042C2C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80042C30: jal         0x800C543C
    // 0x80042C34: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_4;
    // 0x80042C34: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_4:
    // 0x80042C38: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x80042C3C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80042C40: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80042C44: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80042C48: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x80042C4C: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80042C50: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80042C54: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80042C58: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80042C5C: jal         0x800C551C
    // 0x80042C60: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_5;
    // 0x80042C60: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_5:
    // 0x80042C64: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80042C68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042C6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80042C70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80042C74: jal         0x800C55B0
    // 0x80042C78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_6;
    // 0x80042C78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80042C7C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80042C80: jal         0x800C54DC
    // 0x80042C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_7;
    // 0x80042C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80042C88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80042C8C: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x80042C90: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80042C94: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80042C98: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80042C9C: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80042CA0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80042CA4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80042CA8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80042CAC: jal         0x800C5560
    // 0x80042CB0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_current_text_colour(rdram, ctx);
        goto after_8;
    // 0x80042CB0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_8:
    // 0x80042CB4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80042CB8: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80042CBC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80042CC0: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80042CC4: subu        $a1, $t9, $t0
    ctx->r5 = SUB32(ctx->r25, ctx->r8);
    // 0x80042CC8: subu        $a2, $t2, $t3
    ctx->r6 = SUB32(ctx->r10, ctx->r11);
    // 0x80042CCC: sra         $t4, $a2, 1
    ctx->r12 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80042CD0: sra         $t1, $a1, 1
    ctx->r9 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80042CD4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80042CD8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80042CDC: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80042CE0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80042CE4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80042CE8: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80042CEC: addiu       $a2, $t4, 0x2
    ctx->r6 = ADD32(ctx->r12, 0X2);
    // 0x80042CF0: jal         0x800C56C8
    // 0x80042CF4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    render_dialogue_text(rdram, ctx);
        goto after_9;
    // 0x80042CF4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_9:
    // 0x80042CF8: jal         0x800C5B54
    // 0x80042CFC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    open_dialogue_box(rdram, ctx);
        goto after_10;
    // 0x80042CFC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_10:
    // 0x80042D00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80042D04:
    // 0x80042D04: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80042D08: jr          $ra
    // 0x80042D0C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80042D0C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void set_menu_id_if_option_equal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D880: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D884: addiu       $v0, $v0, 0x6A82
    ctx->r2 = ADD32(ctx->r2, 0X6A82);
    // 0x8009D888: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009D88C: nop

    // 0x8009D890: bne         $a0, $t6, L_8009D89C
    if (ctx->r4 != ctx->r14) {
        // 0x8009D894: nop
    
            goto L_8009D89C;
    }
    // 0x8009D894: nop

    // 0x8009D898: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
L_8009D89C:
    // 0x8009D89C: jr          $ra
    // 0x8009D8A0: nop

    return;
    // 0x8009D8A0: nop

;}
RECOMP_FUNC void alSynSetPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065D60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065D68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80065D6C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80065D70: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80065D74: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x80065D78: nop

    // 0x80065D7C: beq         $t7, $zero, L_80065DFC
    if (ctx->r15 == 0) {
        // 0x80065D80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80065DFC;
    }
    // 0x80065D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065D84: jal         0x800658A8
    // 0x80065D88: nop

    __allocParam(rdram, ctx);
        goto after_0;
    // 0x80065D88: nop

    after_0:
    // 0x80065D8C: beq         $v0, $zero, L_80065DF8
    if (ctx->r2 == 0) {
        // 0x80065D90: addiu       $t4, $zero, 0xC
        ctx->r12 = ADD32(0, 0XC);
            goto L_80065DF8;
    }
    // 0x80065D90: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80065D94: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80065D98: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80065D9C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80065DA0: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x80065DA4: lw          $t2, 0xD8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XD8);
    // 0x80065DA8: sh          $t4, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r12;
    // 0x80065DAC: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80065DB0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80065DB4: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x80065DB8: jal         0x80065E2C
    // 0x80065DBC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    modify_panning(rdram, ctx);
        goto after_1;
    // 0x80065DBC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80065DC0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80065DC4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80065DC8: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // 0x80065DCC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80065DD0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80065DD4: nop

    // 0x80065DD8: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80065DDC: nop

    // 0x80065DE0: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x80065DE4: nop

    // 0x80065DE8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80065DEC: nop

    // 0x80065DF0: jalr        $t9
    // 0x80065DF4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80065DF4: nop

    after_2:
L_80065DF8:
    // 0x80065DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80065DFC:
    // 0x80065DFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065E00: jr          $ra
    // 0x80065E04: nop

    return;
    // 0x80065E04: nop

;}
RECOMP_FUNC void material_set_no_tex_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B918: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007B91C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B920: jal         0x8007B938
    // 0x8007B924: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    material_set(rdram, ctx);
        goto after_0;
    // 0x8007B924: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8007B928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B92C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007B930: jr          $ra
    // 0x8007B934: nop

    return;
    // 0x8007B934: nop

;}
RECOMP_FUNC void slowly_change_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030E20: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80030E24: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80030E28: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80030E2C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80030E30: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80030E34: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80030E38: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80030E3C: beq         $at, $zero, L_80030E50
    if (ctx->r1 == 0) {
        // 0x80030E40: sll         $t6, $a0, 3
        ctx->r14 = S32(ctx->r4 << 3);
            goto L_80030E50;
    }
    // 0x80030E40: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80030E44: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80030E48: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80030E4C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80030E50:
    // 0x80030E50: slti        $at, $s0, 0x400
    ctx->r1 = SIGNED(ctx->r16) < 0X400 ? 1 : 0;
    // 0x80030E54: bne         $at, $zero, L_80030E60
    if (ctx->r1 != 0) {
        // 0x80030E58: subu        $t6, $t6, $a0
        ctx->r14 = SUB32(ctx->r14, ctx->r4);
            goto L_80030E60;
    }
    // 0x80030E58: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80030E5C: addiu       $s0, $zero, 0x3FF
    ctx->r16 = ADD32(0, 0X3FF);
L_80030E60:
    // 0x80030E60: addiu       $v0, $s0, -0x5
    ctx->r2 = ADD32(ctx->r16, -0X5);
    // 0x80030E64: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030E68: bne         $at, $zero, L_80030E74
    if (ctx->r1 != 0) {
        // 0x80030E6C: sll         $t6, $t6, 3
        ctx->r14 = S32(ctx->r14 << 3);
            goto L_80030E74;
    }
    // 0x80030E6C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80030E70: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80030E74:
    // 0x80030E74: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80030E78: addiu       $t7, $t7, -0x26F8
    ctx->r15 = ADD32(ctx->r15, -0X26F8);
    // 0x80030E7C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80030E80: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80030E84: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80030E88: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80030E8C: div         $zero, $t0, $v1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r3)));
    // 0x80030E90: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x80030E94: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x80030E98: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80030E9C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80030EA0: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80030EA4: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030EA8: sb          $a1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r5;
    // 0x80030EAC: sb          $a2, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r6;
    // 0x80030EB0: sb          $a3, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r7;
    // 0x80030EB4: sh          $s1, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r17;
    // 0x80030EB8: sh          $s0, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r16;
    // 0x80030EBC: bne         $v1, $zero, L_80030EC8
    if (ctx->r3 != 0) {
        // 0x80030EC0: nop
    
            goto L_80030EC8;
    }
    // 0x80030EC0: nop

    // 0x80030EC4: break       7
    do_break(2147684036);
L_80030EC8:
    // 0x80030EC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030ECC: bne         $v1, $at, L_80030EE0
    if (ctx->r3 != ctx->r1) {
        // 0x80030ED0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030EE0;
    }
    // 0x80030ED0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030ED4: bne         $t0, $at, L_80030EE0
    if (ctx->r8 != ctx->r1) {
        // 0x80030ED8: nop
    
            goto L_80030EE0;
    }
    // 0x80030ED8: nop

    // 0x80030EDC: break       6
    do_break(2147684060);
L_80030EE0:
    // 0x80030EE0: sll         $t0, $s1, 16
    ctx->r8 = S32(ctx->r17 << 16);
    // 0x80030EE4: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x80030EE8: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x80030EEC: mflo        $t1
    ctx->r9 = lo;
    // 0x80030EF0: sw          $t1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r9;
    // 0x80030EF4: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80030EF8: div         $zero, $t4, $v1
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r3)));
    // 0x80030EFC: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80030F00: bne         $v1, $zero, L_80030F0C
    if (ctx->r3 != 0) {
        // 0x80030F04: nop
    
            goto L_80030F0C;
    }
    // 0x80030F04: nop

    // 0x80030F08: break       7
    do_break(2147684104);
L_80030F0C:
    // 0x80030F0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030F10: bne         $v1, $at, L_80030F24
    if (ctx->r3 != ctx->r1) {
        // 0x80030F14: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030F24;
    }
    // 0x80030F14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030F18: bne         $t4, $at, L_80030F24
    if (ctx->r12 != ctx->r1) {
        // 0x80030F1C: nop
    
            goto L_80030F24;
    }
    // 0x80030F1C: nop

    // 0x80030F20: break       6
    do_break(2147684128);
L_80030F24:
    // 0x80030F24: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80030F28: mflo        $t5
    ctx->r13 = lo;
    // 0x80030F2C: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x80030F30: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x80030F34: div         $zero, $t8, $v1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r3)));
    // 0x80030F38: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80030F3C: bne         $v1, $zero, L_80030F48
    if (ctx->r3 != 0) {
        // 0x80030F40: nop
    
            goto L_80030F48;
    }
    // 0x80030F40: nop

    // 0x80030F44: break       7
    do_break(2147684164);
L_80030F48:
    // 0x80030F48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030F4C: bne         $v1, $at, L_80030F60
    if (ctx->r3 != ctx->r1) {
        // 0x80030F50: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030F60;
    }
    // 0x80030F50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030F54: bne         $t8, $at, L_80030F60
    if (ctx->r24 != ctx->r1) {
        // 0x80030F58: nop
    
            goto L_80030F60;
    }
    // 0x80030F58: nop

    // 0x80030F5C: break       6
    do_break(2147684188);
L_80030F60:
    // 0x80030F60: mflo        $t9
    ctx->r25 = lo;
    // 0x80030F64: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x80030F68: nop

    // 0x80030F6C: div         $zero, $t2, $v1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r3)));
    // 0x80030F70: bne         $v1, $zero, L_80030F7C
    if (ctx->r3 != 0) {
        // 0x80030F74: nop
    
            goto L_80030F7C;
    }
    // 0x80030F74: nop

    // 0x80030F78: break       7
    do_break(2147684216);
L_80030F7C:
    // 0x80030F7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030F80: bne         $v1, $at, L_80030F94
    if (ctx->r3 != ctx->r1) {
        // 0x80030F84: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030F94;
    }
    // 0x80030F84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030F88: bne         $t2, $at, L_80030F94
    if (ctx->r10 != ctx->r1) {
        // 0x80030F8C: nop
    
            goto L_80030F94;
    }
    // 0x80030F8C: nop

    // 0x80030F90: break       6
    do_break(2147684240);
L_80030F94:
    // 0x80030F94: mflo        $t3
    ctx->r11 = lo;
    // 0x80030F98: sw          $t3, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r11;
    // 0x80030F9C: nop

    // 0x80030FA0: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x80030FA4: bne         $v1, $zero, L_80030FB0
    if (ctx->r3 != 0) {
        // 0x80030FA8: nop
    
            goto L_80030FB0;
    }
    // 0x80030FA8: nop

    // 0x80030FAC: break       7
    do_break(2147684268);
L_80030FB0:
    // 0x80030FB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030FB4: bne         $v1, $at, L_80030FC8
    if (ctx->r3 != ctx->r1) {
        // 0x80030FB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030FC8;
    }
    // 0x80030FB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030FBC: bne         $t6, $at, L_80030FC8
    if (ctx->r14 != ctx->r1) {
        // 0x80030FC0: nop
    
            goto L_80030FC8;
    }
    // 0x80030FC0: nop

    // 0x80030FC4: break       6
    do_break(2147684292);
L_80030FC8:
    // 0x80030FC8: mflo        $t7
    ctx->r15 = lo;
    // 0x80030FCC: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x80030FD0: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80030FD4: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80030FD8: jr          $ra
    // 0x80030FDC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80030FDC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void leveltable_world(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B3D0: bltz        $a0, L_8006B408
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B3D4: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006B408;
    }
    // 0x8006B3D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B3D8: lw          $t6, 0x16F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F0);
    // 0x8006B3DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006B3E0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B3E4: beq         $at, $zero, L_8006B408
    if (ctx->r1 == 0) {
        // 0x8006B3E8: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006B408;
    }
    // 0x8006B3E8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006B3EC: lw          $t7, 0x16FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16FC);
    // 0x8006B3F0: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8006B3F4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006B3F8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B3FC: lb          $v0, 0x0($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X0);
    // 0x8006B400: jr          $ra
    // 0x8006B404: nop

    return;
    // 0x8006B404: nop

L_8006B408:
    // 0x8006B408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B40C: jr          $ra
    // 0x8006B410: nop

    return;
    // 0x8006B410: nop

;}
RECOMP_FUNC void mtx_ortho(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006816C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80068170: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068174: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068178: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8006817C: jal         0x8007A970
    // 0x80068180: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80068180: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80068184: srl         $t6, $v0, 16
    ctx->r14 = S32(U32(ctx->r2) >> 16);
    // 0x80068188: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x8006818C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80068190: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80068194: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80068198: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006819C: jal         0x8006FAB0
    // 0x800681A0: addiu       $a0, $a0, -0x27D8
    ctx->r4 = ADD32(ctx->r4, -0X27D8);
    mtxf_to_mtx(rdram, ctx);
        goto after_1;
    // 0x800681A0: addiu       $a0, $a0, -0x27D8
    ctx->r4 = ADD32(ctx->r4, -0X27D8);
    after_1:
    // 0x800681A4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800681A8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800681AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800681B0: addiu       $t4, $t4, 0x1264
    ctx->r12 = ADD32(ctx->r12, 0X1264);
    // 0x800681B4: sw          $t8, 0x1308($at)
    MEM_W(0X1308, ctx->r1) = ctx->r24;
    // 0x800681B8: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800681BC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800681C0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800681C4: addiu       $t3, $t3, -0x2948
    ctx->r11 = ADD32(ctx->r11, -0X2948);
    // 0x800681C8: sll         $t5, $t9, 4
    ctx->r13 = S32(ctx->r25 << 4);
    // 0x800681CC: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    // 0x800681D0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800681D4: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x800681D8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800681DC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800681E0: sh          $t6, 0x50($a1)
    MEM_H(0X50, ctx->r5) = ctx->r14;
    // 0x800681E4: sh          $t6, 0x52($a1)
    MEM_H(0X52, ctx->r5) = ctx->r14;
    // 0x800681E8: sh          $t6, 0x58($a1)
    MEM_H(0X58, ctx->r5) = ctx->r14;
    // 0x800681EC: sh          $t8, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r24;
    // 0x800681F0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800681F4: lui         $t5, 0x380
    ctx->r13 = S32(0X380 << 16);
    // 0x800681F8: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x800681FC: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x80068200: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80068204: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80068208: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8006820C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068210: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80068214: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x80068218: ori         $at, $at, 0x50
    ctx->r1 = ctx->r1 | 0X50;
    // 0x8006821C: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80068220: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80068224: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80068228: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x8006822C: addiu       $t5, $a0, 0x8
    ctx->r13 = ADD32(ctx->r4, 0X8);
    // 0x80068230: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x80068234: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80068238: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8006823C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80068240: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068244: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x80068248: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8006824C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80068250: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068254: addiu       $t5, $t9, 0x40
    ctx->r13 = ADD32(ctx->r25, 0X40);
    // 0x80068258: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8006825C: sw          $zero, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = 0;
    // 0x80068260: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068264: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80068268: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006826C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80068270: sw          $zero, 0x1288($at)
    MEM_W(0X1288, ctx->r1) = 0;
    // 0x80068274: addiu       $v0, $v0, -0x27D8
    ctx->r2 = ADD32(ctx->r2, -0X27D8);
    // 0x80068278: addiu       $v1, $v1, 0x14A0
    ctx->r3 = ADD32(ctx->r3, 0X14A0);
    // 0x8006827C: addiu       $a0, $a0, -0x2798
    ctx->r4 = ADD32(ctx->r4, -0X2798);
L_80068280:
    // 0x80068280: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80068284: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80068288: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8006828C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80068290: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80068294: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80068298: swc1        $f4, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f4.u32l;
    // 0x8006829C: swc1        $f6, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f6.u32l;
    // 0x800682A0: swc1        $f8, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f8.u32l;
    // 0x800682A4: bne         $v0, $a0, L_80068280
    if (ctx->r2 != ctx->r4) {
        // 0x800682A8: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_80068280;
    }
    // 0x800682A8: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x800682AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800682B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800682B4: jr          $ra
    // 0x800682B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800682B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void model_anim_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061C40: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80061C44: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80061C48: lw          $t6, -0x2448($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2448);
    // 0x80061C4C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80061C50: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80061C54: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80061C58: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80061C5C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80061C60: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80061C64: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80061C68: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80061C6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80061C70: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80061C74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80061C78: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80061C7C: lh          $s0, 0x0($v0)
    ctx->r16 = MEM_H(ctx->r2, 0X0);
    // 0x80061C80: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x80061C84: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80061C88: bne         $s0, $v1, L_80061C9C
    if (ctx->r16 != ctx->r3) {
        // 0x80061C8C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80061C9C;
    }
    // 0x80061C8C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80061C90: sh          $zero, 0x48($a0)
    MEM_H(0X48, ctx->r4) = 0;
    // 0x80061C94: b           L_80061E1C
    // 0x80061C98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80061E1C;
    // 0x80061C98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061C9C:
    // 0x80061C9C: lw          $v0, -0x2440($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2440);
    // 0x80061CA0: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x80061CA4: beq         $v0, $zero, L_80061CC0
    if (ctx->r2 == 0) {
        // 0x80061CA8: ori         $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 | 0XFF;
            goto L_80061CC0;
    }
    // 0x80061CA8: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x80061CAC: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x80061CB0: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061CB4: beq         $at, $zero, L_80061CC4
    if (ctx->r1 == 0) {
        // 0x80061CB8: subu        $t8, $v1, $s0
        ctx->r24 = SUB32(ctx->r3, ctx->r16);
            goto L_80061CC4;
    }
    // 0x80061CB8: subu        $t8, $v1, $s0
    ctx->r24 = SUB32(ctx->r3, ctx->r16);
    // 0x80061CBC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80061CC0:
    // 0x80061CC0: subu        $t8, $v1, $s0
    ctx->r24 = SUB32(ctx->r3, ctx->r16);
L_80061CC4:
    // 0x80061CC4: sh          $t8, 0x48($s5)
    MEM_H(0X48, ctx->r21) = ctx->r24;
    // 0x80061CC8: lh          $a0, 0x48($s5)
    ctx->r4 = MEM_H(ctx->r21, 0X48);
    // 0x80061CCC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x80061CD0: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x80061CD4: jal         0x80070F50
    // 0x80061CD8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    mempool_alloc(rdram, ctx);
        goto after_0;
    // 0x80061CD8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x80061CDC: bne         $v0, $zero, L_80061CEC
    if (ctx->r2 != 0) {
        // 0x80061CE0: sw          $v0, 0x44($s5)
        MEM_W(0X44, ctx->r21) = ctx->r2;
            goto L_80061CEC;
    }
    // 0x80061CE0: sw          $v0, 0x44($s5)
    MEM_W(0X44, ctx->r21) = ctx->r2;
    // 0x80061CE4: b           L_80061E1C
    // 0x80061CE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061E1C;
    // 0x80061CE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061CEC:
    // 0x80061CEC: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80061CF0: sll         $s4, $s0, 2
    ctx->r20 = S32(ctx->r16 << 2);
    // 0x80061CF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80061CF8:
    // 0x80061CF8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80061CFC: lw          $t0, -0x2444($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2444);
    // 0x80061D00: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80061D04: addu        $v0, $t0, $s4
    ctx->r2 = ADD32(ctx->r8, ctx->r20);
    // 0x80061D08: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x80061D0C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80061D10: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80061D14: jal         0x800C673C
    // 0x80061D18: subu        $s3, $t1, $s2
    ctx->r19 = SUB32(ctx->r9, ctx->r18);
    gzip_size_uncompressed(rdram, ctx);
        goto after_1;
    // 0x80061D18: subu        $s3, $t1, $s2
    ctx->r19 = SUB32(ctx->r9, ctx->r18);
    after_1:
    // 0x80061D1C: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    // 0x80061D20: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x80061D24: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80061D28: jal         0x80070F50
    // 0x80061D2C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc(rdram, ctx);
        goto after_2;
    // 0x80061D2C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_2:
    // 0x80061D30: lw          $t2, 0x44($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X44);
    // 0x80061D34: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80061D38: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80061D3C: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x80061D40: lw          $a0, 0x44($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X44);
    // 0x80061D44: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80061D48: addu        $t4, $a0, $s1
    ctx->r12 = ADD32(ctx->r4, ctx->r17);
    // 0x80061D4C: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80061D50: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80061D54: bne         $v1, $zero, L_80061DA8
    if (ctx->r3 != 0) {
        // 0x80061D58: addu        $t7, $v1, $s6
        ctx->r15 = ADD32(ctx->r3, ctx->r22);
            goto L_80061DA8;
    }
    // 0x80061D58: addu        $t7, $v1, $s6
    ctx->r15 = ADD32(ctx->r3, ctx->r22);
    // 0x80061D5C: blez        $fp, L_80061D94
    if (SIGNED(ctx->r30) <= 0) {
        // 0x80061D60: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80061D94;
    }
    // 0x80061D60: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80061D64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80061D68:
    // 0x80061D68: lw          $t5, 0x44($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X44);
    // 0x80061D6C: nop

    // 0x80061D70: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x80061D74: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80061D78: jal         0x80071380
    // 0x80061D7C: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x80061D7C: nop

    after_3:
    // 0x80061D80: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80061D84: bne         $s0, $fp, L_80061D68
    if (ctx->r16 != ctx->r30) {
        // 0x80061D88: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80061D68;
    }
    // 0x80061D88: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80061D8C: lw          $a0, 0x44($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X44);
    // 0x80061D90: nop

L_80061D94:
    // 0x80061D94: jal         0x80071380
    // 0x80061D98: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x80061D98: nop

    after_4:
    // 0x80061D9C: sw          $zero, 0x44($s5)
    MEM_W(0X44, ctx->r21) = 0;
    // 0x80061DA0: b           L_80061E1C
    // 0x80061DA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061E1C;
    // 0x80061DA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061DA8:
    // 0x80061DA8: subu        $s0, $t7, $s3
    ctx->r16 = SUB32(ctx->r15, ctx->r19);
    // 0x80061DAC: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x80061DB0: or          $s7, $t8, $zero
    ctx->r23 = ctx->r24 | 0;
    // 0x80061DB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80061DB8: jal         0x80077190
    // 0x80061DBC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    asset_load(rdram, ctx);
        goto after_5;
    // 0x80061DBC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_5:
    // 0x80061DC0: lw          $t9, 0x44($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X44);
    // 0x80061DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061DC8: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x80061DCC: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80061DD0: jal         0x800C6778
    // 0x80061DD4: nop

    gzip_inflate(rdram, ctx);
        goto after_6;
    // 0x80061DD4: nop

    after_6:
    // 0x80061DD8: lw          $t1, 0x44($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X44);
    // 0x80061DDC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80061DE0: addu        $v1, $t1, $s1
    ctx->r3 = ADD32(ctx->r9, ctx->r17);
    // 0x80061DE4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80061DE8: slt         $at, $s4, $s7
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x80061DEC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80061DF0: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80061DF4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80061DF8: lw          $t3, 0x44($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X44);
    // 0x80061DFC: nop

    // 0x80061E00: addu        $v1, $t3, $s1
    ctx->r3 = ADD32(ctx->r11, ctx->r17);
    // 0x80061E04: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80061E08: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80061E0C: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x80061E10: bne         $at, $zero, L_80061CF8
    if (ctx->r1 != 0) {
        // 0x80061E14: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_80061CF8;
    }
    // 0x80061E14: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80061E18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061E1C:
    // 0x80061E1C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80061E20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80061E24: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80061E28: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80061E2C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80061E30: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80061E34: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80061E38: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80061E3C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80061E40: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80061E44: jr          $ra
    // 0x80061E48: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80061E48: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void gzip_inflate_stored(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7494: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800C7498: lw          $t5, -0x4F6C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4F6C);
    // 0x800C749C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800C74A0: lw          $t4, -0x4F70($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4F70);
    // 0x800C74A4: andi        $t0, $t5, 0x7
    ctx->r8 = ctx->r13 & 0X7;
    // 0x800C74A8: sub         $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x800C74AC: srlv        $t4, $t4, $t0
    ctx->r12 = S32(U32(ctx->r12) >> (ctx->r8 & 31));
    // 0x800C74B0: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800C74B4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800C74B8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C74BC: sltu        $at, $t5, $t0
    ctx->r1 = ctx->r13 < ctx->r8 ? 1 : 0;
    // 0x800C74C0: lw          $t7, 0x3CF8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3CF8);
    // 0x800C74C4: beq         $at, $zero, L_800C74E8
    if (ctx->r1 == 0) {
        // 0x800C74C8: lw          $t6, 0x3CFC($t6)
        ctx->r14 = MEM_W(ctx->r14, 0X3CFC);
            goto L_800C74E8;
    }
    // 0x800C74C8: lw          $t6, 0x3CFC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3CFC);
L_800C74CC:
    // 0x800C74CC: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800C74D0: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x800C74D4: sllv        $v0, $v0, $t5
    ctx->r2 = S32(ctx->r2 << (ctx->r13 & 31));
    // 0x800C74D8: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x800C74DC: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C74E0: bne         $at, $zero, L_800C74CC
    if (ctx->r1 != 0) {
        // 0x800C74E4: or          $t4, $t4, $v0
        ctx->r12 = ctx->r12 | ctx->r2;
            goto L_800C74CC;
    }
    // 0x800C74E4: or          $t4, $t4, $v0
    ctx->r12 = ctx->r12 | ctx->r2;
L_800C74E8:
    // 0x800C74E8: sub         $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x800C74EC: andi        $t1, $t4, 0xFFFF
    ctx->r9 = ctx->r12 & 0XFFFF;
    // 0x800C74F0: sltu        $at, $t5, $t0
    ctx->r1 = ctx->r13 < ctx->r8 ? 1 : 0;
    // 0x800C74F4: beq         $at, $zero, L_800C7518
    if (ctx->r1 == 0) {
        // 0x800C74F8: srlv        $t4, $t4, $t0
        ctx->r12 = S32(U32(ctx->r12) >> (ctx->r8 & 31));
            goto L_800C7518;
    }
    // 0x800C74F8: srlv        $t4, $t4, $t0
    ctx->r12 = S32(U32(ctx->r12) >> (ctx->r8 & 31));
L_800C74FC:
    // 0x800C74FC: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800C7500: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x800C7504: sllv        $v0, $v0, $t5
    ctx->r2 = S32(ctx->r2 << (ctx->r13 & 31));
    // 0x800C7508: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x800C750C: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C7510: bne         $at, $zero, L_800C74FC
    if (ctx->r1 != 0) {
        // 0x800C7514: or          $t4, $t4, $v0
        ctx->r12 = ctx->r12 | ctx->r2;
            goto L_800C74FC;
    }
    // 0x800C7514: or          $t4, $t4, $v0
    ctx->r12 = ctx->r12 | ctx->r2;
L_800C7518:
    // 0x800C7518: andi        $v0, $t1, 0x3
    ctx->r2 = ctx->r9 & 0X3;
    // 0x800C751C: srlv        $t4, $t4, $t0
    ctx->r12 = S32(U32(ctx->r12) >> (ctx->r8 & 31));
    // 0x800C7520: beq         $v0, $zero, L_800C754C
    if (ctx->r2 == 0) {
        // 0x800C7524: sub         $t5, $t5, $t0
        ctx->r13 = SUB32(ctx->r13, ctx->r8);
            goto L_800C754C;
    }
    // 0x800C7524: sub         $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x800C7528: sub         $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
L_800C752C:
    // 0x800C752C: lbu         $t2, 0x0($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X0);
    // 0x800C7530: addi        $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C7534: addi        $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x800C7538: addi        $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x800C753C: bne         $v0, $zero, L_800C752C
    if (ctx->r2 != 0) {
        // 0x800C7540: sb          $t2, -0x1($t6)
        MEM_B(-0X1, ctx->r14) = ctx->r10;
            goto L_800C752C;
    }
    // 0x800C7540: sb          $t2, -0x1($t6)
    MEM_B(-0X1, ctx->r14) = ctx->r10;
    // 0x800C7544: beq         $t1, $zero, L_800C757C
    if (ctx->r9 == 0) {
        // 0x800C7548: nop
    
            goto L_800C757C;
    }
    // 0x800C7548: nop

L_800C754C:
    // 0x800C754C: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800C7550: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x800C7554: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x800C7558: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x800C755C: lbu         $v1, -0x3($t7)
    ctx->r3 = MEM_BU(ctx->r15, -0X3);
    // 0x800C7560: addiu       $t6, $t6, 0x4
    ctx->r14 = ADD32(ctx->r14, 0X4);
    // 0x800C7564: sb          $v1, -0x3($t6)
    MEM_B(-0X3, ctx->r14) = ctx->r3;
    // 0x800C7568: lbu         $t2, -0x2($t7)
    ctx->r10 = MEM_BU(ctx->r15, -0X2);
    // 0x800C756C: sb          $t2, -0x2($t6)
    MEM_B(-0X2, ctx->r14) = ctx->r10;
    // 0x800C7570: lbu         $t3, -0x1($t7)
    ctx->r11 = MEM_BU(ctx->r15, -0X1);
    // 0x800C7574: bne         $t1, $zero, L_800C754C
    if (ctx->r9 != 0) {
        // 0x800C7578: sb          $t3, -0x1($t6)
        MEM_B(-0X1, ctx->r14) = ctx->r11;
            goto L_800C754C;
    }
    // 0x800C7578: sb          $t3, -0x1($t6)
    MEM_B(-0X1, ctx->r14) = ctx->r11;
L_800C757C:
    // 0x800C757C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C7580: sw          $t7, 0x3CF8($at)
    MEM_W(0X3CF8, ctx->r1) = ctx->r15;
    // 0x800C7584: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C7588: sw          $t6, 0x3CFC($at)
    MEM_W(0X3CFC, ctx->r1) = ctx->r14;
    // 0x800C758C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7590: sw          $t4, -0x4F70($at)
    MEM_W(-0X4F70, ctx->r1) = ctx->r12;
    // 0x800C7594: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7598: jr          $ra
    // 0x800C759C: sw          $t5, -0x4F6C($at)
    MEM_W(-0X4F6C, ctx->r1) = ctx->r13;
    return;
    // 0x800C759C: sw          $t5, -0x4F6C($at)
    MEM_W(-0X4F6C, ctx->r1) = ctx->r13;
;}
RECOMP_FUNC void postrace_music_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095118: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009511C: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x80095120: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80095124: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80095128: addiu       $a1, $a1, 0x7054
    ctx->r5 = ADD32(ctx->r5, 0X7054);
    // 0x8009512C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80095130: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80095134: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x80095138: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x8009513C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80095140: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80095144: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80095148: lw          $v0, 0x6978($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6978);
    // 0x8009514C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80095150: bltz        $v0, L_8009521C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80095154: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009521C;
    }
    // 0x80095154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80095158: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009515C: lw          $v1, -0x620($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X620);
    // 0x80095160: addu        $t1, $v0, $a0
    ctx->r9 = ADD32(ctx->r2, ctx->r4);
    // 0x80095164: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095168: beq         $v1, $zero, L_80095184
    if (ctx->r3 == 0) {
        // 0x8009516C: sw          $t1, 0x6978($at)
        MEM_W(0X6978, ctx->r1) = ctx->r9;
            goto L_80095184;
    }
    // 0x8009516C: sw          $t1, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r9;
    // 0x80095170: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80095174: beq         $v1, $at, L_800951BC
    if (ctx->r3 == ctx->r1) {
        // 0x80095178: nop
    
            goto L_800951BC;
    }
    // 0x80095178: nop

    // 0x8009517C: b           L_800951F4
    // 0x80095180: nop

        goto L_800951F4;
    // 0x80095180: nop

L_80095184:
    // 0x80095184: jal         0x8000C8B4
    // 0x80095188: addiu       $a0, $zero, 0xF0
    ctx->r4 = ADD32(0, 0XF0);
    normalise_time(rdram, ctx);
        goto after_0;
    // 0x80095188: addiu       $a0, $zero, 0xF0
    ctx->r4 = ADD32(0, 0XF0);
    after_0:
    // 0x8009518C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80095190: lw          $t2, 0x6978($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6978);
    // 0x80095194: nop

    // 0x80095198: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8009519C: beq         $at, $zero, L_800951F4
    if (ctx->r1 == 0) {
        // 0x800951A0: nop
    
            goto L_800951F4;
    }
    // 0x800951A0: nop

    // 0x800951A4: jal         0x80000C98
    // 0x800951A8: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    music_fade(rdram, ctx);
        goto after_1;
    // 0x800951A8: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    after_1:
    // 0x800951AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800951B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800951B4: b           L_800951F4
    // 0x800951B8: sw          $t3, -0x620($at)
    MEM_W(-0X620, ctx->r1) = ctx->r11;
        goto L_800951F4;
    // 0x800951B8: sw          $t3, -0x620($at)
    MEM_W(-0X620, ctx->r1) = ctx->r11;
L_800951BC:
    // 0x800951BC: jal         0x8000C8B4
    // 0x800951C0: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    normalise_time(rdram, ctx);
        goto after_2;
    // 0x800951C0: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_2:
    // 0x800951C4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800951C8: lw          $t4, 0x6978($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6978);
    // 0x800951CC: nop

    // 0x800951D0: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800951D4: beq         $at, $zero, L_800951F4
    if (ctx->r1 == 0) {
        // 0x800951D8: nop
    
            goto L_800951F4;
    }
    // 0x800951D8: nop

    // 0x800951DC: jal         0x80000BE0
    // 0x800951E0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_3;
    // 0x800951E0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_3:
    // 0x800951E4: jal         0x80000B34
    // 0x800951E8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_4;
    // 0x800951E8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_4:
    // 0x800951EC: jal         0x80000C98
    // 0x800951F0: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    music_fade(rdram, ctx);
        goto after_5;
    // 0x800951F0: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_5:
L_800951F4:
    // 0x800951F4: jal         0x8000C8B4
    // 0x800951F8: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    normalise_time(rdram, ctx);
        goto after_6;
    // 0x800951F8: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_6:
    // 0x800951FC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80095200: addiu       $v1, $v1, 0x6978
    ctx->r3 = ADD32(ctx->r3, 0X6978);
    // 0x80095204: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80095208: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8009520C: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80095210: beq         $at, $zero, L_80095220
    if (ctx->r1 == 0) {
        // 0x80095214: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80095220;
    }
    // 0x80095214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80095218: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_8009521C:
    // 0x8009521C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80095220:
    // 0x80095220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80095224: jr          $ra
    // 0x80095228: nop

    return;
    // 0x80095228: nop

;}
RECOMP_FUNC void model_init_normals(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800610E8: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800610EC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800610F0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800610F4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800610F8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800610FC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80061100: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80061104: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80061108: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006110C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80061110: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80061114: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80061118: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8006111C: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x80061120: lh          $v1, 0x28($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X28);
    // 0x80061124: lw          $ra, 0x38($a0)
    ctx->r31 = MEM_W(ctx->r4, 0X38);
    // 0x80061128: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
    // 0x8006112C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80061130: blez        $v1, L_800611A0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80061134: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800611A0;
    }
    // 0x80061134: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80061138: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
L_8006113C:
    // 0x8006113C: multu       $s1, $t5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061140: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80061144: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80061148: mflo        $t7
    ctx->r15 = lo;
    // 0x8006114C: addu        $v0, $ra, $t7
    ctx->r2 = ADD32(ctx->r31, ctx->r15);
    // 0x80061150: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x80061154: nop

    // 0x80061158: bne         $t8, $at, L_80061174
    if (ctx->r24 != ctx->r1) {
        // 0x8006115C: nop
    
            goto L_80061174;
    }
    // 0x8006115C: nop

    // 0x80061160: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80061164: nop

    // 0x80061168: andi        $t6, $t9, 0x8000
    ctx->r14 = ctx->r25 & 0X8000;
    // 0x8006116C: beq         $t6, $zero, L_80061190
    if (ctx->r14 == 0) {
        // 0x80061170: sll         $t8, $s1, 16
        ctx->r24 = S32(ctx->r17 << 16);
            goto L_80061190;
    }
    // 0x80061170: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
L_80061174:
    // 0x80061174: lh          $t7, 0xE($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XE);
    // 0x80061178: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x8006117C: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80061180: subu        $a3, $t8, $t9
    ctx->r7 = SUB32(ctx->r24, ctx->r25);
    // 0x80061184: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80061188: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8006118C: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
L_80061190:
    // 0x80061190: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80061194: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061198: bne         $at, $zero, L_8006113C
    if (ctx->r1 != 0) {
        // 0x8006119C: nop
    
            goto L_8006113C;
    }
    // 0x8006119C: nop

L_800611A0:
    // 0x800611A0: blez        $a3, L_80061BF8
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800611A4: lui         $a1, 0xFF7F
        ctx->r5 = S32(0XFF7F << 16);
            goto L_80061BF8;
    }
    // 0x800611A4: lui         $a1, 0xFF7F
    ctx->r5 = S32(0XFF7F << 16);
    // 0x800611A8: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800611AC: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x800611B0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x800611B4: lw          $s3, 0x4($t6)
    ctx->r19 = MEM_W(ctx->r14, 0X4);
    // 0x800611B8: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x800611BC: lh          $a0, 0x26($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X26);
    // 0x800611C0: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x800611C4: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800611C8: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x800611CC: sll         $a0, $t8, 2
    ctx->r4 = S32(ctx->r24 << 2);
    // 0x800611D0: jal         0x80070F50
    // 0x800611D4: sh          $a3, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r7;
    mempool_alloc(rdram, ctx);
        goto after_0;
    // 0x800611D4: sh          $a3, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r7;
    after_0:
    // 0x800611D8: lh          $a3, 0x98($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X98);
    // 0x800611DC: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x800611E0: bne         $v0, $zero, L_800611F0
    if (ctx->r2 != 0) {
        // 0x800611E4: sw          $v0, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->r2;
            goto L_800611F0;
    }
    // 0x800611E4: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x800611E8: b           L_80061BFC
    // 0x800611EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061BFC;
    // 0x800611EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800611F0:
    // 0x800611F0: sll         $a0, $a3, 2
    ctx->r4 = S32(ctx->r7 << 2);
    // 0x800611F4: subu        $a0, $a0, $a3
    ctx->r4 = SUB32(ctx->r4, ctx->r7);
    // 0x800611F8: lui         $a1, 0xFF7F
    ctx->r5 = S32(0XFF7F << 16);
    // 0x800611FC: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x80061200: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x80061204: jal         0x80070F50
    // 0x80061208: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    mempool_alloc(rdram, ctx);
        goto after_1;
    // 0x80061208: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_1:
    // 0x8006120C: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x80061210: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80061214: bne         $v0, $zero, L_80061230
    if (ctx->r2 != 0) {
        // 0x80061218: sw          $v0, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->r2;
            goto L_80061230;
    }
    // 0x80061218: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x8006121C: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x80061220: jal         0x80071380
    // 0x80061224: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x80061224: nop

    after_2:
    // 0x80061228: b           L_80061BFC
    // 0x8006122C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061BFC;
    // 0x8006122C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061230:
    // 0x80061230: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x80061234: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80061238: lh          $v1, 0x28($t9)
    ctx->r3 = MEM_H(ctx->r25, 0X28);
    // 0x8006123C: addiu       $s7, $sp, 0x64
    ctx->r23 = ADD32(ctx->r29, 0X64);
    // 0x80061240: blez        $v1, L_80061470
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80061244: addiu       $s6, $sp, 0x70
        ctx->r22 = ADD32(ctx->r29, 0X70);
            goto L_80061470;
    }
    // 0x80061244: addiu       $s6, $sp, 0x70
    ctx->r22 = ADD32(ctx->r29, 0X70);
    // 0x80061248: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8006124C: addiu       $fp, $sp, 0x58
    ctx->r30 = ADD32(ctx->r29, 0X58);
    // 0x80061250: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_80061254:
    // 0x80061254: multu       $s1, $t5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061258: mflo        $t7
    ctx->r15 = lo;
    // 0x8006125C: addu        $v0, $ra, $t7
    ctx->r2 = ADD32(ctx->r31, ctx->r15);
    // 0x80061260: lh          $s5, 0x4($v0)
    ctx->r21 = MEM_H(ctx->r2, 0X4);
    // 0x80061264: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x80061268: lh          $s4, 0x2($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X2);
    // 0x8006126C: slt         $at, $s5, $t6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80061270: beq         $at, $zero, L_80061458
    if (ctx->r1 == 0) {
        // 0x80061274: nop
    
            goto L_80061458;
    }
    // 0x80061274: nop

    // 0x80061278: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8006127C: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
L_80061280:
    // 0x80061280: sll         $t9, $s5, 4
    ctx->r25 = S32(ctx->r21 << 4);
    // 0x80061284: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80061288: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
L_8006128C:
    // 0x8006128C: addu        $t7, $a0, $a3
    ctx->r15 = ADD32(ctx->r4, ctx->r7);
    // 0x80061290: lbu         $t6, 0x1($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X1);
    // 0x80061294: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x80061298: addu        $a2, $t6, $s4
    ctx->r6 = ADD32(ctx->r14, ctx->r20);
    // 0x8006129C: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800612A0: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800612A4: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800612A8: addu        $t8, $s6, $v0
    ctx->r24 = ADD32(ctx->r22, ctx->r2);
    // 0x800612AC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800612B0: mflo        $t7
    ctx->r15 = lo;
    // 0x800612B4: addu        $v1, $s3, $t7
    ctx->r3 = ADD32(ctx->r19, ctx->r15);
    // 0x800612B8: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800612BC: addu        $t7, $s7, $v0
    ctx->r15 = ADD32(ctx->r23, ctx->r2);
    // 0x800612C0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800612C4: nop

    // 0x800612C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800612CC: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x800612D0: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x800612D4: addu        $t8, $fp, $v0
    ctx->r24 = ADD32(ctx->r30, ctx->r2);
    // 0x800612D8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800612DC: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x800612E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800612E4: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800612E8: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x800612EC: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x800612F0: lh          $t6, 0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4);
    // 0x800612F4: nop

    // 0x800612F8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800612FC: nop

    // 0x80061300: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80061304: bne         $at, $zero, L_8006128C
    if (ctx->r1 != 0) {
        // 0x80061308: swc1        $f18, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
            goto L_8006128C;
    }
    // 0x80061308: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
    // 0x8006130C: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80061310: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80061314: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80061318: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8006131C: multu       $s5, $t5
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061320: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80061324: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x80061328: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8006132C: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80061330: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80061334: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80061338: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8006133C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80061340: mflo        $t8
    ctx->r24 = lo;
    // 0x80061344: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80061348: addu        $s0, $t6, $t8
    ctx->r16 = ADD32(ctx->r14, ctx->r24);
    // 0x8006134C: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80061350: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x80061354: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80061358: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8006135C: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80061360: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80061364: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80061368: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8006136C: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80061370: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80061374: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80061378: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8006137C: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80061380: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80061384: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80061388: sub.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8006138C: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80061390: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80061394: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80061398: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8006139C: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800613A0: sub.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800613A4: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800613A8: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800613AC: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800613B0: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800613B4: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800613B8: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800613BC: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800613C0: mul.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800613C4: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800613C8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800613CC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x800613D0: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800613D4: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x800613D8: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800613DC: nop

    // 0x800613E0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800613E4: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800613E8: jal         0x800CA030
    // 0x800613EC: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800613EC: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_3:
    // 0x800613F0: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800613F4: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x800613F8: bc1t        L_80061428
    if (c1cs) {
        // 0x800613FC: addiu       $t5, $zero, 0xC
        ctx->r13 = ADD32(0, 0XC);
            goto L_80061428;
    }
    // 0x800613FC: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80061400: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80061404: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80061408: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006140C: div.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80061410: nop

    // 0x80061414: div.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80061418: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8006141C: div.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80061420: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x80061424: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_80061428:
    // 0x80061428: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8006142C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80061430: lh          $t8, 0x10($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X10);
    // 0x80061434: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x80061438: sra         $s5, $t9, 16
    ctx->r21 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8006143C: slt         $at, $s5, $t8
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061440: bne         $at, $zero, L_80061280
    if (ctx->r1 != 0) {
        // 0x80061444: lw          $t8, 0xB0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XB0);
            goto L_80061280;
    }
    // 0x80061444: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x80061448: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x8006144C: nop

    // 0x80061450: lh          $v1, 0x28($t9)
    ctx->r3 = MEM_H(ctx->r25, 0X28);
    // 0x80061454: nop

L_80061458:
    // 0x80061458: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006145C: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x80061460: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80061464: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061468: bne         $at, $zero, L_80061254
    if (ctx->r1 != 0) {
        // 0x8006146C: nop
    
            goto L_80061254;
    }
    // 0x8006146C: nop

L_80061470:
    // 0x80061470: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x80061474: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80061478: lh          $a0, 0x24($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X24);
    // 0x8006147C: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x80061480: lui         $a1, 0xFF7F
    ctx->r5 = S32(0XFF7F << 16);
    // 0x80061484: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80061488: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x8006148C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80061490: jal         0x80070F50
    // 0x80061494: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    mempool_alloc(rdram, ctx);
        goto after_4;
    // 0x80061494: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    after_4:
    // 0x80061498: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x8006149C: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x800614A0: bne         $v0, $zero, L_800614C8
    if (ctx->r2 != 0) {
        // 0x800614A4: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_800614C8;
    }
    // 0x800614A4: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x800614A8: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x800614AC: jal         0x80071380
    // 0x800614B0: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800614B0: nop

    after_5:
    // 0x800614B4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800614B8: jal         0x80071380
    // 0x800614BC: nop

    mempool_free(rdram, ctx);
        goto after_6;
    // 0x800614BC: nop

    after_6:
    // 0x800614C0: b           L_80061BFC
    // 0x800614C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061BFC;
    // 0x800614C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800614C8:
    // 0x800614C8: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x800614CC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800614D0: lh          $v1, 0x28($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X28);
    // 0x800614D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800614D8: blez        $v1, L_80061874
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800614DC: addiu       $s4, $zero, -0x1
        ctx->r20 = ADD32(0, -0X1);
            goto L_80061874;
    }
    // 0x800614DC: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x800614E0: addiu       $s0, $zero, 0xFE
    ctx->r16 = ADD32(0, 0XFE);
L_800614E4:
    // 0x800614E4: multu       $s1, $t5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800614E8: mflo        $t6
    ctx->r14 = lo;
    // 0x800614EC: addu        $t8, $ra, $t6
    ctx->r24 = ADD32(ctx->r31, ctx->r14);
    // 0x800614F0: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x800614F4: lh          $t7, 0xE($t8)
    ctx->r15 = MEM_H(ctx->r24, 0XE);
    // 0x800614F8: lh          $t3, 0x2($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X2);
    // 0x800614FC: nop

    // 0x80061500: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80061504: beq         $at, $zero, L_8006185C
    if (ctx->r1 == 0) {
        // 0x80061508: nop
    
            goto L_8006185C;
    }
    // 0x80061508: nop

    // 0x8006150C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_80061510:
    // 0x80061510: nop

    // 0x80061514: lbu         $t4, 0x6($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X6);
    // 0x80061518: nop

    // 0x8006151C: slti        $at, $t4, 0xFE
    ctx->r1 = SIGNED(ctx->r12) < 0XFE ? 1 : 0;
    // 0x80061520: beq         $at, $zero, L_80061684
    if (ctx->r1 == 0) {
        // 0x80061524: nop
    
            goto L_80061684;
    }
    // 0x80061524: nop

    // 0x80061528: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006152C: sll         $a2, $s4, 16
    ctx->r6 = S32(ctx->r20 << 16);
    // 0x80061530: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80061534: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80061538: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006153C: mflo        $t9
    ctx->r25 = lo;
    // 0x80061540: addu        $v1, $s3, $t9
    ctx->r3 = ADD32(ctx->r19, ctx->r25);
    // 0x80061544: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80061548: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
    // 0x8006154C: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    // 0x80061550: bltz        $s1, L_80061654
    if (SIGNED(ctx->r17) < 0) {
        // 0x80061554: nop
    
            goto L_80061654;
    }
    // 0x80061554: nop

L_80061558:
    // 0x80061558: multu       $a1, $t5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006155C: mflo        $t7
    ctx->r15 = lo;
    // 0x80061560: addu        $a3, $ra, $t7
    ctx->r7 = ADD32(ctx->r31, ctx->r15);
    // 0x80061564: lbu         $t6, 0x6($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X6);
    // 0x80061568: nop

    // 0x8006156C: bne         $t4, $t6, L_80061634
    if (ctx->r12 != ctx->r14) {
        // 0x80061570: nop
    
            goto L_80061634;
    }
    // 0x80061570: nop

    // 0x80061574: lh          $a0, 0x2($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X2);
    // 0x80061578: bne         $a1, $s1, L_80061588
    if (ctx->r5 != ctx->r17) {
        // 0x8006157C: slt         $at, $a0, $t3
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_80061588;
    }
    // 0x8006157C: slt         $at, $a0, $t3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80061580: bne         $at, $zero, L_800615A4
    if (ctx->r1 != 0) {
        // 0x80061584: nop
    
            goto L_800615A4;
    }
    // 0x80061584: nop

L_80061588:
    // 0x80061588: beq         $a1, $s1, L_80061634
    if (ctx->r5 == ctx->r17) {
        // 0x8006158C: nop
    
            goto L_80061634;
    }
    // 0x8006158C: nop

    // 0x80061590: lh          $t8, 0xE($a3)
    ctx->r24 = MEM_H(ctx->r7, 0XE);
    // 0x80061594: nop

    // 0x80061598: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8006159C: beq         $at, $zero, L_80061634
    if (ctx->r1 == 0) {
        // 0x800615A0: nop
    
            goto L_80061634;
    }
    // 0x800615A0: nop

L_800615A4:
    // 0x800615A4: bgez        $a2, L_80061634
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800615A8: nop
    
            goto L_80061634;
    }
    // 0x800615A8: nop

L_800615AC:
    // 0x800615AC: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800615B0: mflo        $t9
    ctx->r25 = lo;
    // 0x800615B4: addu        $v1, $s3, $t9
    ctx->r3 = ADD32(ctx->r19, ctx->r25);
    // 0x800615B8: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800615BC: nop

    // 0x800615C0: bne         $t0, $t7, L_800615F0
    if (ctx->r8 != ctx->r15) {
        // 0x800615C4: nop
    
            goto L_800615F0;
    }
    // 0x800615C4: nop

    // 0x800615C8: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800615CC: nop

    // 0x800615D0: bne         $t1, $t6, L_800615F0
    if (ctx->r9 != ctx->r14) {
        // 0x800615D4: nop
    
            goto L_800615F0;
    }
    // 0x800615D4: nop

    // 0x800615D8: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    // 0x800615DC: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800615E0: bne         $t2, $t8, L_800615F0
    if (ctx->r10 != ctx->r24) {
        // 0x800615E4: addu        $t7, $v0, $t9
        ctx->r15 = ADD32(ctx->r2, ctx->r25);
            goto L_800615F0;
    }
    // 0x800615E4: addu        $t7, $v0, $t9
    ctx->r15 = ADD32(ctx->r2, ctx->r25);
    // 0x800615E8: lh          $a2, 0x0($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X0);
    // 0x800615EC: nop

L_800615F0:
    // 0x800615F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800615F4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800615F8: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800615FC: bne         $a1, $s1, L_80061610
    if (ctx->r5 != ctx->r17) {
        // 0x80061600: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_80061610;
    }
    // 0x80061600: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80061604: slt         $at, $t8, $t3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80061608: bne         $at, $zero, L_8006162C
    if (ctx->r1 != 0) {
        // 0x8006160C: nop
    
            goto L_8006162C;
    }
    // 0x8006160C: nop

L_80061610:
    // 0x80061610: beq         $a1, $s1, L_80061634
    if (ctx->r5 == ctx->r17) {
        // 0x80061614: nop
    
            goto L_80061634;
    }
    // 0x80061614: nop

    // 0x80061618: lh          $t9, 0xE($a3)
    ctx->r25 = MEM_H(ctx->r7, 0XE);
    // 0x8006161C: nop

    // 0x80061620: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80061624: beq         $at, $zero, L_80061634
    if (ctx->r1 == 0) {
        // 0x80061628: nop
    
            goto L_80061634;
    }
    // 0x80061628: nop

L_8006162C:
    // 0x8006162C: bltz        $a2, L_800615AC
    if (SIGNED(ctx->r6) < 0) {
        // 0x80061630: nop
    
            goto L_800615AC;
    }
    // 0x80061630: nop

L_80061634:
    // 0x80061634: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80061638: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8006163C: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80061640: slt         $at, $s1, $a1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80061644: bne         $at, $zero, L_80061654
    if (ctx->r1 != 0) {
        // 0x80061648: nop
    
            goto L_80061654;
    }
    // 0x80061648: nop

    // 0x8006164C: bltz        $a2, L_80061558
    if (SIGNED(ctx->r6) < 0) {
        // 0x80061650: nop
    
            goto L_80061558;
    }
    // 0x80061650: nop

L_80061654:
    // 0x80061654: bgez        $a2, L_80061678
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80061658: sll         $t8, $t3, 1
        ctx->r24 = S32(ctx->r11 << 1);
            goto L_80061678;
    }
    // 0x80061658: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x8006165C: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x80061660: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80061664: sh          $s6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r22;
    // 0x80061668: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8006166C: sll         $t7, $s6, 16
    ctx->r15 = S32(ctx->r22 << 16);
    // 0x80061670: b           L_8006182C
    // 0x80061674: sra         $s6, $t7, 16
    ctx->r22 = S32(SIGNED(ctx->r15) >> 16);
        goto L_8006182C;
    // 0x80061674: sra         $s6, $t7, 16
    ctx->r22 = S32(SIGNED(ctx->r15) >> 16);
L_80061678:
    // 0x80061678: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8006167C: b           L_8006182C
    // 0x80061680: sh          $a2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r6;
        goto L_8006182C;
    // 0x80061680: sh          $a2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r6;
L_80061684:
    // 0x80061684: bne         $s0, $t4, L_800616A4
    if (ctx->r16 != ctx->r12) {
        // 0x80061688: sll         $t7, $t3, 1
        ctx->r15 = S32(ctx->r11 << 1);
            goto L_800616A4;
    }
    // 0x80061688: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x8006168C: addu        $t6, $v0, $t7
    ctx->r14 = ADD32(ctx->r2, ctx->r15);
    // 0x80061690: sh          $s6, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r22;
    // 0x80061694: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80061698: sll         $t8, $s6, 16
    ctx->r24 = S32(ctx->r22 << 16);
    // 0x8006169C: b           L_8006182C
    // 0x800616A0: sra         $s6, $t8, 16
    ctx->r22 = S32(SIGNED(ctx->r24) >> 16);
        goto L_8006182C;
    // 0x800616A0: sra         $s6, $t8, 16
    ctx->r22 = S32(SIGNED(ctx->r24) >> 16);
L_800616A4:
    // 0x800616A4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800616A8: nop

    // 0x800616AC: lw          $t6, 0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X8);
    // 0x800616B0: nop

    // 0x800616B4: andi        $t8, $t6, 0x8000
    ctx->r24 = ctx->r14 & 0X8000;
    // 0x800616B8: beq         $t8, $zero, L_80061824
    if (ctx->r24 == 0) {
        // 0x800616BC: sll         $t8, $t3, 1
        ctx->r24 = S32(ctx->r11 << 1);
            goto L_80061824;
    }
    // 0x800616BC: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x800616C0: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800616C4: sll         $a2, $s4, 16
    ctx->r6 = S32(ctx->r20 << 16);
    // 0x800616C8: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800616CC: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800616D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800616D4: mflo        $t7
    ctx->r15 = lo;
    // 0x800616D8: addu        $v1, $s3, $t7
    ctx->r3 = ADD32(ctx->r19, ctx->r15);
    // 0x800616DC: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x800616E0: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
    // 0x800616E4: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    // 0x800616E8: bltz        $s1, L_800617F0
    if (SIGNED(ctx->r17) < 0) {
        // 0x800616EC: nop
    
            goto L_800617F0;
    }
    // 0x800616EC: nop

L_800616F0:
    // 0x800616F0: multu       $a1, $t5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800616F4: mflo        $t6
    ctx->r14 = lo;
    // 0x800616F8: addu        $a3, $ra, $t6
    ctx->r7 = ADD32(ctx->r31, ctx->r14);
    // 0x800616FC: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    // 0x80061700: nop

    // 0x80061704: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80061708: beq         $t9, $zero, L_800617D0
    if (ctx->r25 == 0) {
        // 0x8006170C: nop
    
            goto L_800617D0;
    }
    // 0x8006170C: nop

    // 0x80061710: lh          $a0, 0x2($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X2);
    // 0x80061714: bne         $a1, $s1, L_80061724
    if (ctx->r5 != ctx->r17) {
        // 0x80061718: slt         $at, $a0, $t3
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_80061724;
    }
    // 0x80061718: slt         $at, $a0, $t3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8006171C: bne         $at, $zero, L_80061740
    if (ctx->r1 != 0) {
        // 0x80061720: nop
    
            goto L_80061740;
    }
    // 0x80061720: nop

L_80061724:
    // 0x80061724: beq         $a1, $s1, L_800617D0
    if (ctx->r5 == ctx->r17) {
        // 0x80061728: nop
    
            goto L_800617D0;
    }
    // 0x80061728: nop

    // 0x8006172C: lh          $t7, 0xE($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XE);
    // 0x80061730: nop

    // 0x80061734: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80061738: beq         $at, $zero, L_800617D0
    if (ctx->r1 == 0) {
        // 0x8006173C: nop
    
            goto L_800617D0;
    }
    // 0x8006173C: nop

L_80061740:
    // 0x80061740: bgez        $a2, L_800617D0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80061744: nop
    
            goto L_800617D0;
    }
    // 0x80061744: nop

L_80061748:
    // 0x80061748: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006174C: mflo        $t6
    ctx->r14 = lo;
    // 0x80061750: addu        $v1, $s3, $t6
    ctx->r3 = ADD32(ctx->r19, ctx->r14);
    // 0x80061754: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80061758: nop

    // 0x8006175C: bne         $t0, $t8, L_8006178C
    if (ctx->r8 != ctx->r24) {
        // 0x80061760: nop
    
            goto L_8006178C;
    }
    // 0x80061760: nop

    // 0x80061764: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x80061768: nop

    // 0x8006176C: bne         $t1, $t9, L_8006178C
    if (ctx->r9 != ctx->r25) {
        // 0x80061770: nop
    
            goto L_8006178C;
    }
    // 0x80061770: nop

    // 0x80061774: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x80061778: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x8006177C: bne         $t2, $t7, L_8006178C
    if (ctx->r10 != ctx->r15) {
        // 0x80061780: addu        $t8, $v0, $t6
        ctx->r24 = ADD32(ctx->r2, ctx->r14);
            goto L_8006178C;
    }
    // 0x80061780: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x80061784: lh          $a2, 0x0($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X0);
    // 0x80061788: nop

L_8006178C:
    // 0x8006178C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80061790: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80061794: sra         $t7, $t9, 16
    ctx->r15 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80061798: bne         $a1, $s1, L_800617AC
    if (ctx->r5 != ctx->r17) {
        // 0x8006179C: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800617AC;
    }
    // 0x8006179C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800617A0: slt         $at, $t7, $t3
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800617A4: bne         $at, $zero, L_800617C8
    if (ctx->r1 != 0) {
        // 0x800617A8: nop
    
            goto L_800617C8;
    }
    // 0x800617A8: nop

L_800617AC:
    // 0x800617AC: beq         $a1, $s1, L_800617D0
    if (ctx->r5 == ctx->r17) {
        // 0x800617B0: nop
    
            goto L_800617D0;
    }
    // 0x800617B0: nop

    // 0x800617B4: lh          $t6, 0xE($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XE);
    // 0x800617B8: nop

    // 0x800617BC: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800617C0: beq         $at, $zero, L_800617D0
    if (ctx->r1 == 0) {
        // 0x800617C4: nop
    
            goto L_800617D0;
    }
    // 0x800617C4: nop

L_800617C8:
    // 0x800617C8: bltz        $a2, L_80061748
    if (SIGNED(ctx->r6) < 0) {
        // 0x800617CC: nop
    
            goto L_80061748;
    }
    // 0x800617CC: nop

L_800617D0:
    // 0x800617D0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800617D4: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x800617D8: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800617DC: slt         $at, $s1, $a1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800617E0: bne         $at, $zero, L_800617F0
    if (ctx->r1 != 0) {
        // 0x800617E4: nop
    
            goto L_800617F0;
    }
    // 0x800617E4: nop

    // 0x800617E8: bltz        $a2, L_800616F0
    if (SIGNED(ctx->r6) < 0) {
        // 0x800617EC: nop
    
            goto L_800616F0;
    }
    // 0x800617EC: nop

L_800617F0:
    // 0x800617F0: bgez        $a2, L_80061814
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800617F4: sll         $t7, $t3, 1
        ctx->r15 = S32(ctx->r11 << 1);
            goto L_80061814;
    }
    // 0x800617F4: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x800617F8: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x800617FC: addu        $t6, $v0, $t7
    ctx->r14 = ADD32(ctx->r2, ctx->r15);
    // 0x80061800: sh          $s6, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r22;
    // 0x80061804: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80061808: sll         $t8, $s6, 16
    ctx->r24 = S32(ctx->r22 << 16);
    // 0x8006180C: b           L_8006182C
    // 0x80061810: sra         $s6, $t8, 16
    ctx->r22 = S32(SIGNED(ctx->r24) >> 16);
        goto L_8006182C;
    // 0x80061810: sra         $s6, $t8, 16
    ctx->r22 = S32(SIGNED(ctx->r24) >> 16);
L_80061814:
    // 0x80061814: addu        $t6, $v0, $t7
    ctx->r14 = ADD32(ctx->r2, ctx->r15);
    // 0x80061818: b           L_8006182C
    // 0x8006181C: sh          $a2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r6;
        goto L_8006182C;
    // 0x8006181C: sh          $a2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r6;
    // 0x80061820: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
L_80061824:
    // 0x80061824: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80061828: sh          $s4, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r20;
L_8006182C:
    // 0x8006182C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80061830: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80061834: lh          $t9, 0xE($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XE);
    // 0x80061838: sll         $t7, $t3, 16
    ctx->r15 = S32(ctx->r11 << 16);
    // 0x8006183C: sra         $t3, $t7, 16
    ctx->r11 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80061840: slt         $at, $t3, $t9
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80061844: bne         $at, $zero, L_80061510
    if (ctx->r1 != 0) {
        // 0x80061848: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_80061510;
    }
    // 0x80061848: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8006184C: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x80061850: nop

    // 0x80061854: lh          $v1, 0x28($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X28);
    // 0x80061858: nop

L_8006185C:
    // 0x8006185C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80061860: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x80061864: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80061868: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006186C: bne         $at, $zero, L_800614E4
    if (ctx->r1 != 0) {
        // 0x80061870: nop
    
            goto L_800614E4;
    }
    // 0x80061870: nop

L_80061874:
    // 0x80061874: sll         $a0, $s6, 2
    ctx->r4 = S32(ctx->r22 << 2);
    // 0x80061878: subu        $a0, $a0, $s6
    ctx->r4 = SUB32(ctx->r4, ctx->r22);
    // 0x8006187C: lui         $a1, 0xFF7F
    ctx->r5 = S32(0XFF7F << 16);
    // 0x80061880: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x80061884: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x80061888: jal         0x80070F50
    // 0x8006188C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    mempool_alloc(rdram, ctx);
        goto after_7;
    // 0x8006188C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_7:
    // 0x80061890: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x80061894: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80061898: bne         $v0, $zero, L_800618C8
    if (ctx->r2 != 0) {
        // 0x8006189C: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800618C8;
    }
    // 0x8006189C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800618A0: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x800618A4: jal         0x80071380
    // 0x800618A8: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x800618A8: nop

    after_8:
    // 0x800618AC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800618B0: jal         0x80071380
    // 0x800618B4: nop

    mempool_free(rdram, ctx);
        goto after_9;
    // 0x800618B4: nop

    after_9:
    // 0x800618B8: jal         0x80071380
    // 0x800618BC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    mempool_free(rdram, ctx);
        goto after_10;
    // 0x800618BC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_10:
    // 0x800618C0: b           L_80061BFC
    // 0x800618C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061BFC;
    // 0x800618C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800618C8:
    // 0x800618C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800618CC: blez        $s6, L_80061900
    if (SIGNED(ctx->r22) <= 0) {
        // 0x800618D0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80061900;
    }
    // 0x800618D0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800618D4:
    // 0x800618D4: multu       $a3, $t5
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800618D8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800618DC: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x800618E0: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800618E4: slt         $at, $a3, $s6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x800618E8: mflo        $t9
    ctx->r25 = lo;
    // 0x800618EC: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x800618F0: swc1        $f20, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f20.u32l;
    // 0x800618F4: swc1        $f20, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f20.u32l;
    // 0x800618F8: bne         $at, $zero, L_800618D4
    if (ctx->r1 != 0) {
        // 0x800618FC: swc1        $f20, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
            goto L_800618D4;
    }
    // 0x800618FC: swc1        $f20, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
L_80061900:
    // 0x80061900: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x80061904: nop

    // 0x80061908: lh          $v1, 0x28($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X28);
    // 0x8006190C: nop

    // 0x80061910: blez        $v1, L_80061A50
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80061914: nop
    
            goto L_80061A50;
    }
    // 0x80061914: nop

L_80061918:
    // 0x80061918: multu       $s1, $t5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006191C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80061920: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80061924: mflo        $t9
    ctx->r25 = lo;
    // 0x80061928: addu        $t0, $ra, $t9
    ctx->r8 = ADD32(ctx->r31, ctx->r25);
    // 0x8006192C: lbu         $t7, 0x6($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X6);
    // 0x80061930: nop

    // 0x80061934: bne         $t7, $at, L_80061950
    if (ctx->r15 != ctx->r1) {
        // 0x80061938: nop
    
            goto L_80061950;
    }
    // 0x80061938: nop

    // 0x8006193C: lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8);
    // 0x80061940: nop

    // 0x80061944: andi        $t8, $t6, 0x8000
    ctx->r24 = ctx->r14 & 0X8000;
    // 0x80061948: beq         $t8, $zero, L_80061A40
    if (ctx->r24 == 0) {
        // 0x8006194C: sll         $t8, $s1, 16
        ctx->r24 = S32(ctx->r17 << 16);
            goto L_80061A40;
    }
    // 0x8006194C: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
L_80061950:
    // 0x80061950: lh          $s5, 0x4($t0)
    ctx->r21 = MEM_H(ctx->r8, 0X4);
    // 0x80061954: lh          $t9, 0x10($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X10);
    // 0x80061958: lh          $s4, 0x2($t0)
    ctx->r20 = MEM_H(ctx->r8, 0X2);
    // 0x8006195C: slt         $at, $s5, $t9
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80061960: beq         $at, $zero, L_80061A40
    if (ctx->r1 == 0) {
        // 0x80061964: sll         $t8, $s1, 16
        ctx->r24 = S32(ctx->r17 << 16);
            goto L_80061A40;
    }
    // 0x80061964: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
    // 0x80061968: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x8006196C: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x80061970: nop

    // 0x80061974: sll         $t7, $s5, 4
    ctx->r15 = S32(ctx->r21 << 4);
L_80061978:
    // 0x80061978: addu        $a0, $t1, $t7
    ctx->r4 = ADD32(ctx->r9, ctx->r15);
    // 0x8006197C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80061980: addu        $t6, $a0, $a3
    ctx->r14 = ADD32(ctx->r4, ctx->r7);
L_80061984:
    // 0x80061984: lbu         $t8, 0x1($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1);
    // 0x80061988: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8006198C: addu        $a2, $t8, $s4
    ctx->r6 = ADD32(ctx->r24, ctx->r20);
    // 0x80061990: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x80061994: sra         $t7, $t9, 16
    ctx->r15 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80061998: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8006199C: addu        $t8, $s7, $t6
    ctx->r24 = ADD32(ctx->r23, ctx->r14);
    // 0x800619A0: lh          $a2, 0x0($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X0);
    // 0x800619A4: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x800619A8: bltz        $a2, L_80061A04
    if (SIGNED(ctx->r6) < 0) {
        // 0x800619AC: sra         $a3, $t6, 16
        ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
            goto L_80061A04;
    }
    // 0x800619AC: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800619B0: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800619B4: mflo        $t9
    ctx->r25 = lo;
    // 0x800619B8: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x800619BC: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800619C0: multu       $s5, $t5
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800619C4: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800619C8: mflo        $t7
    ctx->r15 = lo;
    // 0x800619CC: addu        $s0, $a1, $t7
    ctx->r16 = ADD32(ctx->r5, ctx->r15);
    // 0x800619D0: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800619D4: nop

    // 0x800619D8: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800619DC: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800619E0: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800619E4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800619E8: nop

    // 0x800619EC: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800619F0: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x800619F4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800619F8: nop

    // 0x800619FC: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80061A00: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
L_80061A04:
    // 0x80061A04: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x80061A08: bne         $at, $zero, L_80061984
    if (ctx->r1 != 0) {
        // 0x80061A0C: addu        $t6, $a0, $a3
        ctx->r14 = ADD32(ctx->r4, ctx->r7);
            goto L_80061984;
    }
    // 0x80061A0C: addu        $t6, $a0, $a3
    ctx->r14 = ADD32(ctx->r4, ctx->r7);
    // 0x80061A10: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80061A14: lh          $v1, 0x10($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X10);
    // 0x80061A18: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x80061A1C: sra         $s5, $t9, 16
    ctx->r21 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80061A20: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061A24: bne         $at, $zero, L_80061978
    if (ctx->r1 != 0) {
        // 0x80061A28: sll         $t7, $s5, 4
        ctx->r15 = S32(ctx->r21 << 4);
            goto L_80061978;
    }
    // 0x80061A28: sll         $t7, $s5, 4
    ctx->r15 = S32(ctx->r21 << 4);
    // 0x80061A2C: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x80061A30: nop

    // 0x80061A34: lh          $v1, 0x28($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X28);
    // 0x80061A38: nop

    // 0x80061A3C: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
L_80061A40:
    // 0x80061A40: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80061A44: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061A48: bne         $at, $zero, L_80061918
    if (ctx->r1 != 0) {
        // 0x80061A4C: nop
    
            goto L_80061918;
    }
    // 0x80061A4C: nop

L_80061A50:
    // 0x80061A50: blez        $s6, L_80061AF0
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80061A54: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80061AF0;
    }
    // 0x80061A54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80061A58:
    // 0x80061A58: multu       $a3, $t5
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061A5C: mflo        $t7
    ctx->r15 = lo;
    // 0x80061A60: addu        $s0, $s2, $t7
    ctx->r16 = ADD32(ctx->r18, ctx->r15);
    // 0x80061A64: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80061A68: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80061A6C: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80061A70: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80061A74: sh          $a3, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r7;
    // 0x80061A78: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80061A7C: nop

    // 0x80061A80: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80061A84: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80061A88: jal         0x800CA030
    // 0x80061A8C: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_11;
    // 0x80061A8C: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    after_11:
    // 0x80061A90: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x80061A94: lh          $a3, 0x98($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X98);
    // 0x80061A98: bc1t        L_80061AD4
    if (c1cs) {
        // 0x80061A9C: addiu       $t5, $zero, 0xC
        ctx->r13 = ADD32(0, 0XC);
            goto L_80061AD4;
    }
    // 0x80061A9C: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80061AA0: lui         $at, 0x3900
    ctx->r1 = S32(0X3900 << 16);
    // 0x80061AA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80061AA8: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80061AAC: mul.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80061AB0: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80061AB4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80061AB8: div.s       $f18, $f6, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80061ABC: nop

    // 0x80061AC0: div.s       $f16, $f4, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80061AC4: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x80061AC8: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80061ACC: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x80061AD0: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_80061AD4:
    // 0x80061AD4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80061AD8: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80061ADC: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80061AE0: slt         $at, $a3, $s6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80061AE4: bne         $at, $zero, L_80061A58
    if (ctx->r1 != 0) {
        // 0x80061AE8: nop
    
            goto L_80061A58;
    }
    // 0x80061AE8: nop

    // 0x80061AEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80061AF0:
    // 0x80061AF0: lw          $t2, 0xB8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB8);
    // 0x80061AF4: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80061AF8: lh          $a1, 0x24($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X24);
    // 0x80061AFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80061B00: blez        $a1, L_80061BD4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80061B04: addiu       $t0, $zero, 0x6
        ctx->r8 = ADD32(0, 0X6);
            goto L_80061BD4;
    }
    // 0x80061B04: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80061B08: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
L_80061B0C:
    // 0x80061B0C: addu        $t7, $s7, $t9
    ctx->r15 = ADD32(ctx->r23, ctx->r25);
    // 0x80061B10: lh          $a2, 0x0($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X0);
    // 0x80061B14: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80061B18: bltz        $a2, L_80061BC4
    if (SIGNED(ctx->r6) < 0) {
        // 0x80061B1C: sll         $t9, $a3, 16
        ctx->r25 = S32(ctx->r7 << 16);
            goto L_80061BC4;
    }
    // 0x80061B1C: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x80061B20: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061B24: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80061B28: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80061B2C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80061B30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80061B34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80061B38: mflo        $t6
    ctx->r14 = lo;
    // 0x80061B3C: addu        $v1, $t1, $t6
    ctx->r3 = ADD32(ctx->r9, ctx->r14);
    // 0x80061B40: nop

    // 0x80061B44: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061B48: mflo        $t8
    ctx->r24 = lo;
    // 0x80061B4C: addu        $v0, $s2, $t8
    ctx->r2 = ADD32(ctx->r18, ctx->r24);
    // 0x80061B50: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80061B54: nop

    // 0x80061B58: cvt.w.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80061B5C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80061B60: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80061B64: nop

    // 0x80061B68: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80061B6C: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x80061B70: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80061B74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80061B78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80061B7C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80061B80: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80061B84: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80061B88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80061B8C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80061B90: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80061B94: sh          $t8, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r24;
    // 0x80061B98: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80061B9C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80061BA0: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80061BA4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80061BA8: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80061BAC: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80061BB0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80061BB4: sh          $t7, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r15;
    // 0x80061BB8: lh          $a1, 0x24($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X24);
    // 0x80061BBC: nop

    // 0x80061BC0: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
L_80061BC4:
    // 0x80061BC4: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80061BC8: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80061BCC: bne         $at, $zero, L_80061B0C
    if (ctx->r1 != 0) {
        // 0x80061BD0: sll         $t9, $a3, 1
        ctx->r25 = S32(ctx->r7 << 1);
            goto L_80061B0C;
    }
    // 0x80061BD0: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
L_80061BD4:
    // 0x80061BD4: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80061BD8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80061BDC: jal         0x80071380
    // 0x80061BE0: sw          $t1, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->r9;
    mempool_free(rdram, ctx);
        goto after_12;
    // 0x80061BE0: sw          $t1, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->r9;
    after_12:
    // 0x80061BE4: jal         0x80071380
    // 0x80061BE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_13;
    // 0x80061BE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x80061BEC: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x80061BF0: jal         0x80071380
    // 0x80061BF4: nop

    mempool_free(rdram, ctx);
        goto after_14;
    // 0x80061BF4: nop

    after_14:
L_80061BF8:
    // 0x80061BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061BFC:
    // 0x80061BFC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80061C00: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80061C04: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80061C08: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80061C0C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80061C10: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80061C14: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80061C18: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80061C1C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80061C20: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80061C24: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80061C28: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80061C2C: jr          $ra
    // 0x80061C30: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80061C30: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void set_course_finish_flags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A80C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001A810: lw          $t6, -0x4B98($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B98);
    // 0x8001A814: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001A818: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001A81C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001A820: lw          $v0, 0x64($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X64);
    // 0x8001A824: addiu       $v1, $v1, -0x4CBC
    ctx->r3 = ADD32(ctx->r3, -0X4CBC);
    // 0x8001A828: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8001A82C: nop

    // 0x8001A830: bne         $t8, $at, L_8001A840
    if (ctx->r24 != ctx->r1) {
        // 0x8001A834: nop
    
            goto L_8001A840;
    }
    // 0x8001A834: nop

    // 0x8001A838: jr          $ra
    // 0x8001A83C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001A83C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001A840:
    // 0x8001A840: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8001A844: lbu         $t0, 0x49($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X49);
    // 0x8001A848: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8001A84C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8001A850: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8001A854: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8001A858: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001A85C: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x8001A860: bne         $t4, $zero, L_8001A8A0
    if (ctx->r12 != 0) {
        // 0x8001A864: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8001A8A0;
    }
    // 0x8001A864: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001A868: lbu         $t5, -0x4B8B($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4B8B);
    // 0x8001A86C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001A870: bne         $t5, $zero, L_8001A8F8
    if (ctx->r13 != 0) {
        // 0x8001A874: nop
    
            goto L_8001A8F8;
    }
    // 0x8001A874: nop

    // 0x8001A878: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8001A87C: lbu         $t8, 0x49($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X49);
    // 0x8001A880: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8001A884: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8001A888: addu        $v0, $t7, $t0
    ctx->r2 = ADD32(ctx->r15, ctx->r8);
    // 0x8001A88C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8001A890: nop

    // 0x8001A894: ori         $t1, $t9, 0x2
    ctx->r9 = ctx->r25 | 0X2;
    // 0x8001A898: b           L_8001A8F8
    // 0x8001A89C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
        goto L_8001A8F8;
    // 0x8001A89C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_8001A8A0:
    // 0x8001A8A0: lb          $t2, -0x4C7D($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X4C7D);
    // 0x8001A8A4: nop

    // 0x8001A8A8: beq         $t2, $zero, L_8001A8F8
    if (ctx->r10 == 0) {
        // 0x8001A8AC: nop
    
            goto L_8001A8F8;
    }
    // 0x8001A8AC: nop

    // 0x8001A8B0: lb          $t3, 0x202($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X202);
    // 0x8001A8B4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001A8B8: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x8001A8BC: bne         $at, $zero, L_8001A8F8
    if (ctx->r1 != 0) {
        // 0x8001A8C0: nop
    
            goto L_8001A8F8;
    }
    // 0x8001A8C0: nop

    // 0x8001A8C4: lbu         $t4, -0x4B8B($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X4B8B);
    // 0x8001A8C8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001A8CC: bne         $t4, $zero, L_8001A8F8
    if (ctx->r12 != 0) {
        // 0x8001A8D0: nop
    
            goto L_8001A8F8;
    }
    // 0x8001A8D0: nop

    // 0x8001A8D4: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x8001A8D8: lbu         $t8, 0x49($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X49);
    // 0x8001A8DC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8001A8E0: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001A8E4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8001A8E8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8001A8EC: nop

    // 0x8001A8F0: ori         $t9, $t0, 0x4
    ctx->r25 = ctx->r8 | 0X4;
    // 0x8001A8F4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8001A8F8:
    // 0x8001A8F8: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8001A8FC: nop

    // 0x8001A900: jr          $ra
    // 0x8001A904: nop

    return;
    // 0x8001A904: nop

;}
RECOMP_FUNC void func_80080E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800812E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800812E4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800812E8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800812EC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800812F0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800812F4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800812F8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800812FC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80081300: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80081304: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80081308: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008130C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80081310: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80081314: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80081318: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8008131C: addiu       $t8, $t8, 0x21F0
    ctx->r24 = ADD32(ctx->r24, 0X21F0);
    // 0x80081320: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80081324: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80081328: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8008132C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80081330: lui         $t7, 0xE
    ctx->r15 = S32(0XE << 16);
    // 0x80081334: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80081338: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8008133C: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x80081340: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x80081344: addiu       $t7, $t7, 0x2240
    ctx->r15 = ADD32(ctx->r15, 0X2240);
    // 0x80081348: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8008134C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80081350: lw          $s7, 0x58($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X58);
    // 0x80081354: lw          $fp, 0x54($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X54);
    // 0x80081358: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008135C: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80081360: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80081364: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80081368: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8008136C: lui         $s1, 0xF600
    ctx->r17 = S32(0XF600 << 16);
L_80081370:
    // 0x80081370: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80081374: addiu       $t6, $t6, 0x2348
    ctx->r14 = ADD32(ctx->r14, 0X2348);
    // 0x80081378: sll         $t9, $s4, 3
    ctx->r25 = S32(ctx->r20 << 3);
    // 0x8008137C: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x80081380: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80081384: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x80081388: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x8008138C: lh          $ra, 0x6($v0)
    ctx->r31 = MEM_H(ctx->r2, 0X6);
    // 0x80081390: or          $t1, $s5, $zero
    ctx->r9 = ctx->r21 | 0;
    // 0x80081394: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80081398: beq         $s4, $zero, L_800813D8
    if (ctx->r20 == 0) {
        // 0x8008139C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800813D8;
    }
    // 0x8008139C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800813A0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800813A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800813A8: addu        $a0, $s3, $t7
    ctx->r4 = ADD32(ctx->r19, ctx->r15);
    // 0x800813AC: beq         $s4, $at, L_800813EC
    if (ctx->r20 == ctx->r1) {
        // 0x800813B0: addiu       $v1, $a0, -0x1
        ctx->r3 = ADD32(ctx->r4, -0X1);
            goto L_800813EC;
    }
    // 0x800813B0: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x800813B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800813B8: beq         $s4, $at, L_8008140C
    if (ctx->r20 == ctx->r1) {
        // 0x800813BC: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_8008140C;
    }
    // 0x800813BC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800813C0: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800813C4: addiu       $a2, $s3, 0x1
    ctx->r6 = ADD32(ctx->r19, 0X1);
    // 0x800813C8: addiu       $a3, $s5, 0x1
    ctx->r7 = ADD32(ctx->r21, 0X1);
    // 0x800813CC: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x800813D0: b           L_8008141C
    // 0x800813D4: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
        goto L_8008141C;
    // 0x800813D4: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
L_800813D8:
    // 0x800813D8: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800813DC: addu        $a3, $s5, $s6
    ctx->r7 = ADD32(ctx->r21, ctx->r22);
    // 0x800813E0: addiu       $t0, $s3, 0x1
    ctx->r8 = ADD32(ctx->r19, 0X1);
    // 0x800813E4: b           L_8008141C
    // 0x800813E8: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
        goto L_8008141C;
    // 0x800813E8: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
L_800813EC:
    // 0x800813EC: addu        $t1, $s5, $s6
    ctx->r9 = ADD32(ctx->r21, ctx->r22);
    // 0x800813F0: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x800813F4: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800813F8: addiu       $a2, $s3, 0x1
    ctx->r6 = ADD32(ctx->r19, 0X1);
    // 0x800813FC: addu        $a3, $s5, $s6
    ctx->r7 = ADD32(ctx->r21, ctx->r22);
    // 0x80081400: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80081404: b           L_8008141C
    // 0x80081408: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
        goto L_8008141C;
    // 0x80081408: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
L_8008140C:
    // 0x8008140C: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80081410: addu        $a3, $s5, $s6
    ctx->r7 = ADD32(ctx->r21, ctx->r22);
    // 0x80081414: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80081418: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
L_8008141C:
    // 0x8008141C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80081420: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80081424: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80081428: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8008142C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80081430: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80081434: sra         $t7, $v0, 24
    ctx->r15 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80081438: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8008143C: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80081440: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80081444: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80081448: sra         $t6, $v0, 8
    ctx->r14 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8008144C: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x80081450: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x80081454: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80081458: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8008145C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80081460: blez        $s2, L_800815EC
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80081464: sw          $t9, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r25;
            goto L_800815EC;
    }
    // 0x80081464: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80081468: andi        $v0, $s2, 0x1
    ctx->r2 = ctx->r18 & 0X1;
    // 0x8008146C: beq         $v0, $zero, L_800814F4
    if (ctx->r2 == 0) {
        // 0x80081470: nop
    
            goto L_800814F4;
    }
    // 0x80081470: nop

    // 0x80081474: bltz        $a3, L_800814E0
    if (SIGNED(ctx->r7) < 0) {
        // 0x80081478: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800814E0;
    }
    // 0x80081478: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008147C: bltz        $t0, L_800814E0
    if (SIGNED(ctx->r8) < 0) {
        // 0x80081480: andi        $t6, $a3, 0x3FF
        ctx->r14 = ctx->r7 & 0X3FF;
            goto L_800814E0;
    }
    // 0x80081480: andi        $t6, $a3, 0x3FF
    ctx->r14 = ctx->r7 & 0X3FF;
    // 0x80081484: bgez        $t1, L_80081494
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80081488: sll         $t8, $t6, 14
        ctx->r24 = S32(ctx->r14 << 14);
            goto L_80081494;
    }
    // 0x80081488: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x8008148C: b           L_80081498
    // 0x80081490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80081498;
    // 0x80081490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80081494:
    // 0x80081494: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_80081498:
    // 0x80081498: bgez        $a2, L_800814A8
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008149C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800814A8;
    }
    // 0x8008149C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800814A0: b           L_800814A8
    // 0x800814A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800814A8;
    // 0x800814A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800814A8:
    // 0x800814A8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800814AC: or          $t9, $t8, $s1
    ctx->r25 = ctx->r24 | ctx->r17;
    // 0x800814B0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800814B4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800814B8: andi        $t7, $t0, 0x3FF
    ctx->r15 = ctx->r8 & 0X3FF;
    // 0x800814BC: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800814C0: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x800814C4: andi        $t6, $a0, 0x3FF
    ctx->r14 = ctx->r4 & 0X3FF;
    // 0x800814C8: andi        $t7, $a1, 0x3FF
    ctx->r15 = ctx->r5 & 0X3FF;
    // 0x800814CC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800814D0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800814D4: sll         $t9, $t7, 14
    ctx->r25 = S32(ctx->r15 << 14);
    // 0x800814D8: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x800814DC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_800814E0:
    // 0x800814E0: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x800814E4: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x800814E8: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x800814EC: beq         $t2, $s2, L_800815EC
    if (ctx->r10 == ctx->r18) {
        // 0x800814F0: addu        $t0, $t0, $ra
        ctx->r8 = ADD32(ctx->r8, ctx->r31);
            goto L_800815EC;
    }
    // 0x800814F0: addu        $t0, $t0, $ra
    ctx->r8 = ADD32(ctx->r8, ctx->r31);
L_800814F4:
    // 0x800814F4: bltz        $a3, L_80081560
    if (SIGNED(ctx->r7) < 0) {
        // 0x800814F8: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_80081560;
    }
    // 0x800814F8: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x800814FC: bltz        $t0, L_80081560
    if (SIGNED(ctx->r8) < 0) {
        // 0x80081500: andi        $t9, $a3, 0x3FF
        ctx->r25 = ctx->r7 & 0X3FF;
            goto L_80081560;
    }
    // 0x80081500: andi        $t9, $a3, 0x3FF
    ctx->r25 = ctx->r7 & 0X3FF;
    // 0x80081504: bgez        $t1, L_80081514
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80081508: sll         $t8, $t9, 14
        ctx->r24 = S32(ctx->r25 << 14);
            goto L_80081514;
    }
    // 0x80081508: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x8008150C: b           L_80081518
    // 0x80081510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80081518;
    // 0x80081510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80081514:
    // 0x80081514: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_80081518:
    // 0x80081518: bgez        $a2, L_80081528
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008151C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80081528;
    }
    // 0x8008151C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80081520: b           L_80081528
    // 0x80081524: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80081528;
    // 0x80081524: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80081528:
    // 0x80081528: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8008152C: or          $t7, $t8, $s1
    ctx->r15 = ctx->r24 | ctx->r17;
    // 0x80081530: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80081534: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80081538: andi        $t6, $t0, 0x3FF
    ctx->r14 = ctx->r8 & 0X3FF;
    // 0x8008153C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80081540: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80081544: andi        $t9, $a0, 0x3FF
    ctx->r25 = ctx->r4 & 0X3FF;
    // 0x80081548: andi        $t6, $a1, 0x3FF
    ctx->r14 = ctx->r5 & 0X3FF;
    // 0x8008154C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80081550: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80081554: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80081558: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8008155C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80081560:
    // 0x80081560: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x80081564: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x80081568: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x8008156C: bltz        $a3, L_800815D8
    if (SIGNED(ctx->r7) < 0) {
        // 0x80081570: addu        $t0, $t0, $ra
        ctx->r8 = ADD32(ctx->r8, ctx->r31);
            goto L_800815D8;
    }
    // 0x80081570: addu        $t0, $t0, $ra
    ctx->r8 = ADD32(ctx->r8, ctx->r31);
    // 0x80081574: bltz        $t0, L_800815D8
    if (SIGNED(ctx->r8) < 0) {
        // 0x80081578: andi        $t7, $a3, 0x3FF
        ctx->r15 = ctx->r7 & 0X3FF;
            goto L_800815D8;
    }
    // 0x80081578: andi        $t7, $a3, 0x3FF
    ctx->r15 = ctx->r7 & 0X3FF;
    // 0x8008157C: bgez        $t1, L_8008158C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80081580: sll         $t8, $t7, 14
        ctx->r24 = S32(ctx->r15 << 14);
            goto L_8008158C;
    }
    // 0x80081580: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80081584: b           L_80081590
    // 0x80081588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80081590;
    // 0x80081588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8008158C:
    // 0x8008158C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_80081590:
    // 0x80081590: bgez        $a2, L_800815A0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80081594: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800815A0;
    }
    // 0x80081594: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80081598: b           L_800815A0
    // 0x8008159C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800815A0;
    // 0x8008159C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800815A0:
    // 0x800815A0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800815A4: or          $t6, $t8, $s1
    ctx->r14 = ctx->r24 | ctx->r17;
    // 0x800815A8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800815AC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800815B0: andi        $t9, $t0, 0x3FF
    ctx->r25 = ctx->r8 & 0X3FF;
    // 0x800815B4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800815B8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800815BC: andi        $t7, $a0, 0x3FF
    ctx->r15 = ctx->r4 & 0X3FF;
    // 0x800815C0: andi        $t9, $a1, 0x3FF
    ctx->r25 = ctx->r5 & 0X3FF;
    // 0x800815C4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800815C8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800815CC: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x800815D0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800815D4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_800815D8:
    // 0x800815D8: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x800815DC: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x800815E0: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x800815E4: bne         $t2, $s2, L_800814F4
    if (ctx->r10 != ctx->r18) {
        // 0x800815E8: addu        $t0, $t0, $ra
        ctx->r8 = ADD32(ctx->r8, ctx->r31);
            goto L_800814F4;
    }
    // 0x800815E8: addu        $t0, $t0, $ra
    ctx->r8 = ADD32(ctx->r8, ctx->r31);
L_800815EC:
    // 0x800815EC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800815F0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800815F4: bne         $s4, $at, L_80081370
    if (ctx->r20 != ctx->r1) {
        // 0x800815F8: nop
    
            goto L_80081370;
    }
    // 0x800815F8: nop

    // 0x800815FC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80081600: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80081604: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80081608: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8008160C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80081610: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80081614: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80081618: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008161C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80081620: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80081624: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80081628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008162C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80081630: jal         0x8007B820
    // 0x80081634: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x80081634: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    after_0:
    // 0x80081638: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008163C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80081640: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80081644: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80081648: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008164C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80081650: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80081654: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80081658: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008165C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80081660: jr          $ra
    // 0x80081664: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80081664: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void update_controller_sticks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C464: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8009C468: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8009C46C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8009C470: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8009C474: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009C478: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009C47C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009C480: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8009C484: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8009C488: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009C48C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8009C490: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8009C494: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8009C498: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8009C49C: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8009C4A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8009C4A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8009C4A8: addiu       $s7, $s7, 0x6A04
    ctx->r23 = ADD32(ctx->r23, 0X6A04);
    // 0x8009C4AC: addiu       $s6, $s6, 0x69FC
    ctx->r22 = ADD32(ctx->r22, 0X69FC);
    // 0x8009C4B0: addiu       $s3, $s3, 0x6A0C
    ctx->r19 = ADD32(ctx->r19, 0X6A0C);
    // 0x8009C4B4: addiu       $s2, $s2, 0x6A08
    ctx->r18 = ADD32(ctx->r18, 0X6A08);
    // 0x8009C4B8: addiu       $s1, $s1, 0x69F8
    ctx->r17 = ADD32(ctx->r17, 0X69F8);
    // 0x8009C4BC: addiu       $s0, $s0, 0x69F4
    ctx->r16 = ADD32(ctx->r16, 0X69F4);
    // 0x8009C4C0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8009C4C4: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
L_8009C4C8:
    // 0x8009C4C8: jal         0x8006A7DC
    // 0x8009C4CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    input_clamp_stick_x(rdram, ctx);
        goto after_0;
    // 0x8009C4CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x8009C4D0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8009C4D4: jal         0x8006A820
    // 0x8009C4D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    input_clamp_stick_y(rdram, ctx);
        goto after_1;
    // 0x8009C4D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x8009C4DC: slti        $at, $s4, -0x23
    ctx->r1 = SIGNED(ctx->r20) < -0X23 ? 1 : 0;
    // 0x8009C4E0: sb          $zero, 0x0($s6)
    MEM_B(0X0, ctx->r22) = 0;
    // 0x8009C4E4: beq         $at, $zero, L_8009C508
    if (ctx->r1 == 0) {
        // 0x8009C4E8: sb          $zero, 0x0($s7)
        MEM_B(0X0, ctx->r23) = 0;
            goto L_8009C508;
    }
    // 0x8009C4E8: sb          $zero, 0x0($s7)
    MEM_B(0X0, ctx->r23) = 0;
    // 0x8009C4EC: lb          $t6, 0x0($s2)
    ctx->r14 = MEM_B(ctx->r18, 0X0);
    // 0x8009C4F0: nop

    // 0x8009C4F4: slti        $at, $t6, -0x23
    ctx->r1 = SIGNED(ctx->r14) < -0X23 ? 1 : 0;
    // 0x8009C4F8: bne         $at, $zero, L_8009C50C
    if (ctx->r1 != 0) {
        // 0x8009C4FC: slti        $at, $s4, 0x24
        ctx->r1 = SIGNED(ctx->r20) < 0X24 ? 1 : 0;
            goto L_8009C50C;
    }
    // 0x8009C4FC: slti        $at, $s4, 0x24
    ctx->r1 = SIGNED(ctx->r20) < 0X24 ? 1 : 0;
    // 0x8009C500: sb          $fp, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r30;
    // 0x8009C504: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8009C508:
    // 0x8009C508: slti        $at, $s4, 0x24
    ctx->r1 = SIGNED(ctx->r20) < 0X24 ? 1 : 0;
L_8009C50C:
    // 0x8009C50C: bne         $at, $zero, L_8009C530
    if (ctx->r1 != 0) {
        // 0x8009C510: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8009C530;
    }
    // 0x8009C510: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8009C514: lb          $t7, 0x0($s2)
    ctx->r15 = MEM_B(ctx->r18, 0X0);
    // 0x8009C518: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009C51C: slti        $at, $t7, 0x24
    ctx->r1 = SIGNED(ctx->r15) < 0X24 ? 1 : 0;
    // 0x8009C520: beq         $at, $zero, L_8009C534
    if (ctx->r1 == 0) {
        // 0x8009C524: slti        $at, $v0, -0x23
        ctx->r1 = SIGNED(ctx->r2) < -0X23 ? 1 : 0;
            goto L_8009C534;
    }
    // 0x8009C524: slti        $at, $v0, -0x23
    ctx->r1 = SIGNED(ctx->r2) < -0X23 ? 1 : 0;
    // 0x8009C528: sb          $t8, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r24;
    // 0x8009C52C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8009C530:
    // 0x8009C530: slti        $at, $v0, -0x23
    ctx->r1 = SIGNED(ctx->r2) < -0X23 ? 1 : 0;
L_8009C534:
    // 0x8009C534: beq         $at, $zero, L_8009C558
    if (ctx->r1 == 0) {
        // 0x8009C538: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_8009C558;
    }
    // 0x8009C538: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8009C53C: lb          $t9, 0x0($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X0);
    // 0x8009C540: nop

    // 0x8009C544: slti        $at, $t9, -0x23
    ctx->r1 = SIGNED(ctx->r25) < -0X23 ? 1 : 0;
    // 0x8009C548: bne         $at, $zero, L_8009C55C
    if (ctx->r1 != 0) {
        // 0x8009C54C: slti        $at, $v0, 0x24
        ctx->r1 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
            goto L_8009C55C;
    }
    // 0x8009C54C: slti        $at, $v0, 0x24
    ctx->r1 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
    // 0x8009C550: sb          $fp, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r30;
    // 0x8009C554: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8009C558:
    // 0x8009C558: slti        $at, $v0, 0x24
    ctx->r1 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
L_8009C55C:
    // 0x8009C55C: bne         $at, $zero, L_8009C580
    if (ctx->r1 != 0) {
        // 0x8009C560: nop
    
            goto L_8009C580;
    }
    // 0x8009C560: nop

    // 0x8009C564: lb          $t0, 0x0($s3)
    ctx->r8 = MEM_B(ctx->r19, 0X0);
    // 0x8009C568: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009C56C: slti        $at, $t0, 0x24
    ctx->r1 = SIGNED(ctx->r8) < 0X24 ? 1 : 0;
    // 0x8009C570: beq         $at, $zero, L_8009C580
    if (ctx->r1 == 0) {
        // 0x8009C574: nop
    
            goto L_8009C580;
    }
    // 0x8009C574: nop

    // 0x8009C578: sb          $t1, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r9;
    // 0x8009C57C: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8009C580:
    // 0x8009C580: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
    // 0x8009C584: lb          $v1, 0x0($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X0);
    // 0x8009C588: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8009C58C: slti        $at, $v1, -0x23
    ctx->r1 = SIGNED(ctx->r3) < -0X23 ? 1 : 0;
    // 0x8009C590: beq         $at, $zero, L_8009C5B0
    if (ctx->r1 == 0) {
        // 0x8009C594: slti        $at, $v1, 0x24
        ctx->r1 = SIGNED(ctx->r3) < 0X24 ? 1 : 0;
            goto L_8009C5B0;
    }
    // 0x8009C594: slti        $at, $v1, 0x24
    ctx->r1 = SIGNED(ctx->r3) < 0X24 ? 1 : 0;
    // 0x8009C598: lb          $t2, 0x0($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X0);
    // 0x8009C59C: nop

    // 0x8009C5A0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8009C5A4: b           L_8009C5D0
    // 0x8009C5A8: sb          $t3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r11;
        goto L_8009C5D0;
    // 0x8009C5A8: sb          $t3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r11;
    // 0x8009C5AC: slti        $at, $v1, 0x24
    ctx->r1 = SIGNED(ctx->r3) < 0X24 ? 1 : 0;
L_8009C5B0:
    // 0x8009C5B0: bne         $at, $zero, L_8009C5CC
    if (ctx->r1 != 0) {
        // 0x8009C5B4: nop
    
            goto L_8009C5CC;
    }
    // 0x8009C5B4: nop

    // 0x8009C5B8: lb          $t4, 0x0($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X0);
    // 0x8009C5BC: nop

    // 0x8009C5C0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8009C5C4: b           L_8009C5D0
    // 0x8009C5C8: sb          $t5, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r13;
        goto L_8009C5D0;
    // 0x8009C5C8: sb          $t5, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r13;
L_8009C5CC:
    // 0x8009C5CC: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8009C5D0:
    // 0x8009C5D0: lb          $t6, 0x0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X0);
    // 0x8009C5D4: nop

    // 0x8009C5D8: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x8009C5DC: bne         $at, $zero, L_8009C5EC
    if (ctx->r1 != 0) {
        // 0x8009C5E0: nop
    
            goto L_8009C5EC;
    }
    // 0x8009C5E0: nop

    // 0x8009C5E4: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // 0x8009C5E8: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8009C5EC:
    // 0x8009C5EC: sb          $s4, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r20;
    // 0x8009C5F0: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8009C5F4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8009C5F8: slti        $at, $v0, -0x23
    ctx->r1 = SIGNED(ctx->r2) < -0X23 ? 1 : 0;
    // 0x8009C5FC: beq         $at, $zero, L_8009C618
    if (ctx->r1 == 0) {
        // 0x8009C600: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8009C618;
    }
    // 0x8009C600: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8009C604: lb          $t7, 0x0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X0);
    // 0x8009C608: nop

    // 0x8009C60C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8009C610: b           L_8009C63C
    // 0x8009C614: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
        goto L_8009C63C;
    // 0x8009C614: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
L_8009C618:
    // 0x8009C618: slti        $at, $v0, 0x24
    ctx->r1 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
    // 0x8009C61C: bne         $at, $zero, L_8009C638
    if (ctx->r1 != 0) {
        // 0x8009C620: nop
    
            goto L_8009C638;
    }
    // 0x8009C620: nop

    // 0x8009C624: lb          $t9, 0x0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X0);
    // 0x8009C628: nop

    // 0x8009C62C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8009C630: b           L_8009C63C
    // 0x8009C634: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
        goto L_8009C63C;
    // 0x8009C634: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
L_8009C638:
    // 0x8009C638: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8009C63C:
    // 0x8009C63C: lb          $t1, 0x0($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X0);
    // 0x8009C640: nop

    // 0x8009C644: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x8009C648: bne         $at, $zero, L_8009C65C
    if (ctx->r1 != 0) {
        // 0x8009C64C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8009C65C;
    }
    // 0x8009C64C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009C650: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x8009C654: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8009C658: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_8009C65C:
    // 0x8009C65C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8009C660: bne         $s5, $at, L_8009C4C8
    if (ctx->r21 != ctx->r1) {
        // 0x8009C664: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8009C4C8;
    }
    // 0x8009C664: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009C668: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8009C66C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009C670: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009C674: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009C678: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8009C67C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8009C680: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8009C684: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8009C688: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8009C68C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8009C690: jr          $ra
    // 0x8009C694: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8009C694: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void light_update_ambience(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033824: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80033828: addiu       $t2, $t2, -0x3128
    ctx->r10 = ADD32(ctx->r10, -0X3128);
    // 0x8003382C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80033830: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80033834: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80033838: bne         $at, $zero, L_80033A4C
    if (ctx->r1 != 0) {
        // 0x8003383C: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_80033A4C;
    }
    // 0x8003383C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80033840: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80033844: addiu       $t3, $t3, -0x3130
    ctx->r11 = ADD32(ctx->r11, -0X3130);
    // 0x80033848: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
L_8003384C:
    // 0x8003384C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80033850: nop

    // 0x80033854: addu        $a1, $v1, $a0
    ctx->r5 = ADD32(ctx->r3, ctx->r4);
    // 0x80033858: lw          $a2, 0x10($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X10);
    // 0x8003385C: nop

    // 0x80033860: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x80033864: bne         $at, $zero, L_80033A38
    if (ctx->r1 != 0) {
        // 0x80033868: nop
    
            goto L_80033A38;
    }
    // 0x80033868: nop

    // 0x8003386C: lw          $a3, 0x10($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X10);
    // 0x80033870: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80033874: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80033878: bne         $at, $zero, L_80033924
    if (ctx->r1 != 0) {
        // 0x8003387C: sll         $t7, $a3, 16
        ctx->r15 = S32(ctx->r7 << 16);
            goto L_80033924;
    }
    // 0x8003387C: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80033880: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x80033884: div         $zero, $t7, $a3
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r7)));
    // 0x80033888: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8003388C: bne         $a3, $zero, L_80033898
    if (ctx->r7 != 0) {
        // 0x80033890: nop
    
            goto L_80033898;
    }
    // 0x80033890: nop

    // 0x80033894: break       7
    do_break(2147694740);
L_80033898:
    // 0x80033898: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003389C: bne         $a3, $at, L_800338B0
    if (ctx->r7 != ctx->r1) {
        // 0x800338A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800338B0;
    }
    // 0x800338A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800338A4: bne         $t7, $at, L_800338B0
    if (ctx->r15 != ctx->r1) {
        // 0x800338A8: nop
    
            goto L_800338B0;
    }
    // 0x800338A8: nop

    // 0x800338AC: break       6
    do_break(2147694764);
L_800338B0:
    // 0x800338B0: mflo        $t0
    ctx->r8 = lo;
    // 0x800338B4: nop

    // 0x800338B8: nop

    // 0x800338BC: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800338C0: mflo        $t9
    ctx->r25 = lo;
    // 0x800338C4: sra         $t5, $t9, 16
    ctx->r13 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800338C8: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x800338CC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800338D0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800338D4: nop

    // 0x800338D8: addu        $t8, $v1, $a0
    ctx->r24 = ADD32(ctx->r3, ctx->r4);
    // 0x800338DC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800338E0: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800338E4: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800338E8: mflo        $t5
    ctx->r13 = lo;
    // 0x800338EC: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800338F0: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800338F4: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x800338F8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800338FC: nop

    // 0x80033900: addu        $t5, $v1, $a0
    ctx->r13 = ADD32(ctx->r3, ctx->r4);
    // 0x80033904: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x80033908: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x8003390C: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033910: mflo        $t6
    ctx->r14 = lo;
    // 0x80033914: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80033918: addu        $t5, $t9, $t8
    ctx->r13 = ADD32(ctx->r25, ctx->r24);
    // 0x8003391C: b           L_800339D8
    // 0x80033920: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
        goto L_800339D8;
    // 0x80033920: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
L_80033924:
    // 0x80033924: div         $zero, $t7, $a2
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r6)));
    // 0x80033928: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x8003392C: bne         $a2, $zero, L_80033938
    if (ctx->r6 != 0) {
        // 0x80033930: nop
    
            goto L_80033938;
    }
    // 0x80033930: nop

    // 0x80033934: break       7
    do_break(2147694900);
L_80033938:
    // 0x80033938: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003393C: bne         $a2, $at, L_80033950
    if (ctx->r6 != ctx->r1) {
        // 0x80033940: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80033950;
    }
    // 0x80033940: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80033944: bne         $t7, $at, L_80033950
    if (ctx->r15 != ctx->r1) {
        // 0x80033948: nop
    
            goto L_80033950;
    }
    // 0x80033948: nop

    // 0x8003394C: break       6
    do_break(2147694924);
L_80033950:
    // 0x80033950: mflo        $t0
    ctx->r8 = lo;
    // 0x80033954: nop

    // 0x80033958: nop

    // 0x8003395C: multu       $t1, $t0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033960: mflo        $t9
    ctx->r25 = lo;
    // 0x80033964: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80033968: addu        $t5, $t6, $t8
    ctx->r13 = ADD32(ctx->r14, ctx->r24);
    // 0x8003396C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80033970: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80033974: nop

    // 0x80033978: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x8003397C: addu        $t7, $v1, $a0
    ctx->r15 = ADD32(ctx->r3, ctx->r4);
    // 0x80033980: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033984: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80033988: mflo        $t8
    ctx->r24 = lo;
    // 0x8003398C: sra         $t5, $t8, 16
    ctx->r13 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80033990: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x80033994: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x80033998: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8003399C: nop

    // 0x800339A0: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x800339A4: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x800339A8: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800339AC: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x800339B0: mflo        $t5
    ctx->r13 = lo;
    // 0x800339B4: sra         $t7, $t5, 16
    ctx->r15 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800339B8: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800339BC: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
    // 0x800339C0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800339C4: nop

    // 0x800339C8: addu        $t9, $v1, $a0
    ctx->r25 = ADD32(ctx->r3, ctx->r4);
    // 0x800339CC: lw          $t5, 0x10($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X10);
    // 0x800339D0: nop

    // 0x800339D4: sw          $t5, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r13;
L_800339D8:
    // 0x800339D8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800339DC: nop

    // 0x800339E0: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x800339E4: nop

    // 0x800339E8: slti        $at, $t8, 0x100
    ctx->r1 = SIGNED(ctx->r24) < 0X100 ? 1 : 0;
    // 0x800339EC: bne         $at, $zero, L_80033A00
    if (ctx->r1 != 0) {
        // 0x800339F0: nop
    
            goto L_80033A00;
    }
    // 0x800339F0: nop

    // 0x800339F4: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800339F8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800339FC: nop

L_80033A00:
    // 0x80033A00: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x80033A04: nop

    // 0x80033A08: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x80033A0C: bne         $at, $zero, L_80033A20
    if (ctx->r1 != 0) {
        // 0x80033A10: nop
    
            goto L_80033A20;
    }
    // 0x80033A10: nop

    // 0x80033A14: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x80033A18: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80033A1C: nop

L_80033A20:
    // 0x80033A20: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x80033A24: nop

    // 0x80033A28: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80033A2C: bne         $at, $zero, L_80033A38
    if (ctx->r1 != 0) {
        // 0x80033A30: nop
    
            goto L_80033A38;
    }
    // 0x80033A30: nop

    // 0x80033A34: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
L_80033A38:
    // 0x80033A38: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80033A3C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80033A40: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80033A44: bne         $at, $zero, L_8003384C
    if (ctx->r1 != 0) {
        // 0x80033A48: addiu       $a0, $a0, 0x14
        ctx->r4 = ADD32(ctx->r4, 0X14);
            goto L_8003384C;
    }
    // 0x80033A48: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
L_80033A4C:
    // 0x80033A4C: jr          $ra
    // 0x80033A50: nop

    return;
    // 0x80033A50: nop

;}
RECOMP_FUNC void sndp_set_global_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003160: sltiu       $at, $a0, 0x101
    ctx->r1 = ctx->r4 < 0X101 ? 1 : 0;
    // 0x80003164: bne         $at, $zero, L_80003170
    if (ctx->r1 != 0) {
        // 0x80003168: nop
    
            goto L_80003170;
    }
    // 0x80003168: nop

    // 0x8000316C: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
L_80003170:
    // 0x80003170: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80003174: jr          $ra
    // 0x80003178: sw          $a0, -0x33D0($at)
    MEM_W(-0X33D0, ctx->r1) = ctx->r4;
    return;
    // 0x80003178: sw          $a0, -0x33D0($at)
    MEM_W(-0X33D0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void strcat_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4CA4: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800B4CA8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800B4CAC: beq         $t6, $zero, L_800B4CC4
    if (ctx->r14 == 0) {
        // 0x800B4CB0: nop
    
            goto L_800B4CC4;
    }
    // 0x800B4CB0: nop

L_800B4CB4:
    // 0x800B4CB4: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x800B4CB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4CBC: bne         $t7, $zero, L_800B4CB4
    if (ctx->r15 != 0) {
        // 0x800B4CC0: nop
    
            goto L_800B4CB4;
    }
    // 0x800B4CC0: nop

L_800B4CC4:
    // 0x800B4CC4: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4CC8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4CCC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4CD0: beq         $v0, $zero, L_800B4CEC
    if (ctx->r2 == 0) {
        // 0x800B4CD4: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_800B4CEC;
    }
    // 0x800B4CD4: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
L_800B4CD8:
    // 0x800B4CD8: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4CDC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4CE0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4CE4: bne         $v0, $zero, L_800B4CD8
    if (ctx->r2 != 0) {
        // 0x800B4CE8: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_800B4CD8;
    }
    // 0x800B4CE8: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
L_800B4CEC:
    // 0x800B4CEC: jr          $ra
    // 0x800B4CF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B4CF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void copy_viewports_to_stack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066850: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80066854: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80066858: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x8006685C: addiu       $s7, $s7, -0x295C
    ctx->r23 = ADD32(ctx->r23, -0X295C);
    // 0x80066860: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80066864: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066868: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006686C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80066870: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80066874: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80066878: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8006687C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80066880: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80066884: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80066888: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006688C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80066890: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80066894: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x80066898: addiu       $s0, $s0, -0x2A2C
    ctx->r16 = ADD32(ctx->r16, -0X2A2C);
    // 0x8006689C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800668A0: addiu       $fp, $zero, -0x2
    ctx->r30 = ADD32(0, -0X2);
L_800668A4:
    // 0x800668A4: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x800668A8: addiu       $at, $zero, -0x7
    ctx->r1 = ADD32(0, -0X7);
    // 0x800668AC: andi        $t9, $v1, 0x4
    ctx->r25 = ctx->r3 & 0X4;
    // 0x800668B0: beq         $t9, $zero, L_800668C8
    if (ctx->r25 == 0) {
        // 0x800668B4: andi        $t1, $v1, 0x2
        ctx->r9 = ctx->r3 & 0X2;
            goto L_800668C8;
    }
    // 0x800668B4: andi        $t1, $v1, 0x2
    ctx->r9 = ctx->r3 & 0X2;
    // 0x800668B8: and         $t0, $v1, $fp
    ctx->r8 = ctx->r3 & ctx->r30;
    // 0x800668BC: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x800668C0: b           L_800668D8
    // 0x800668C4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_800668D8;
    // 0x800668C4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800668C8:
    // 0x800668C8: beq         $t1, $zero, L_800668D8
    if (ctx->r9 == 0) {
        // 0x800668CC: ori         $t2, $v1, 0x1
        ctx->r10 = ctx->r3 | 0X1;
            goto L_800668D8;
    }
    // 0x800668CC: ori         $t2, $v1, 0x1
    ctx->r10 = ctx->r3 | 0X1;
    // 0x800668D0: sw          $t2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r10;
    // 0x800668D4: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_800668D8:
    // 0x800668D8: and         $t3, $v1, $at
    ctx->r11 = ctx->r3 & ctx->r1;
    // 0x800668DC: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800668E0: sw          $t3, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r11;
    // 0x800668E4: beq         $t4, $zero, L_80066A18
    if (ctx->r12 == 0) {
        // 0x800668E8: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80066A18;
    }
    // 0x800668E8: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800668EC: andi        $t5, $t3, 0x8
    ctx->r13 = ctx->r11 & 0X8;
    // 0x800668F0: bne         $t5, $zero, L_80066918
    if (ctx->r13 != 0) {
        // 0x800668F4: andi        $t2, $v1, 0x10
        ctx->r10 = ctx->r3 & 0X10;
            goto L_80066918;
    }
    // 0x800668F4: andi        $t2, $v1, 0x10
    ctx->r10 = ctx->r3 & 0X10;
    // 0x800668F8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800668FC: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80066900: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80066904: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x80066908: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8006690C: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80066910: b           L_80066928
    // 0x80066914: addu        $s5, $t7, $t0
    ctx->r21 = ADD32(ctx->r15, ctx->r8);
        goto L_80066928;
    // 0x80066914: addu        $s5, $t7, $t0
    ctx->r21 = ADD32(ctx->r15, ctx->r8);
L_80066918:
    // 0x80066918: lw          $s5, 0x10($s0)
    ctx->r21 = MEM_W(ctx->r16, 0X10);
    // 0x8006691C: nop

    // 0x80066920: sll         $t1, $s5, 2
    ctx->r9 = S32(ctx->r21 << 2);
    // 0x80066924: or          $s5, $t1, $zero
    ctx->r21 = ctx->r9 | 0;
L_80066928:
    // 0x80066928: bne         $t2, $zero, L_80066950
    if (ctx->r10 != 0) {
        // 0x8006692C: andi        $t7, $v1, 0x20
        ctx->r15 = ctx->r3 & 0X20;
            goto L_80066950;
    }
    // 0x8006692C: andi        $t7, $v1, 0x20
    ctx->r15 = ctx->r3 & 0X20;
    // 0x80066930: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80066934: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x80066938: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8006693C: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x80066940: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80066944: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80066948: b           L_80066960
    // 0x8006694C: addu        $s4, $t3, $t8
    ctx->r20 = ADD32(ctx->r11, ctx->r24);
        goto L_80066960;
    // 0x8006694C: addu        $s4, $t3, $t8
    ctx->r20 = ADD32(ctx->r11, ctx->r24);
L_80066950:
    // 0x80066950: lw          $s4, 0x14($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X14);
    // 0x80066954: nop

    // 0x80066958: sll         $t9, $s4, 2
    ctx->r25 = S32(ctx->r20 << 2);
    // 0x8006695C: or          $s4, $t9, $zero
    ctx->r20 = ctx->r25 | 0;
L_80066960:
    // 0x80066960: bne         $t7, $zero, L_80066988
    if (ctx->r15 != 0) {
        // 0x80066964: andi        $t5, $v1, 0x40
        ctx->r13 = ctx->r3 & 0X40;
            goto L_80066988;
    }
    // 0x80066964: andi        $t5, $v1, 0x40
    ctx->r13 = ctx->r3 & 0X40;
    // 0x80066968: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x8006696C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80066970: nop

    // 0x80066974: subu        $s1, $t0, $t1
    ctx->r17 = SUB32(ctx->r8, ctx->r9);
    // 0x80066978: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006697C: sll         $t2, $s1, 1
    ctx->r10 = S32(ctx->r17 << 1);
    // 0x80066980: b           L_80066998
    // 0x80066984: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
        goto L_80066998;
    // 0x80066984: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
L_80066988:
    // 0x80066988: lw          $s1, 0x18($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X18);
    // 0x8006698C: nop

    // 0x80066990: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x80066994: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
L_80066998:
    // 0x80066998: bne         $t5, $zero, L_800669C0
    if (ctx->r13 != 0) {
        // 0x8006699C: nop
    
            goto L_800669C0;
    }
    // 0x8006699C: nop

    // 0x800669A0: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800669A4: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x800669A8: nop

    // 0x800669AC: subu        $s2, $t6, $t3
    ctx->r18 = SUB32(ctx->r14, ctx->r11);
    // 0x800669B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800669B4: sll         $t8, $s2, 1
    ctx->r24 = S32(ctx->r18 << 1);
    // 0x800669B8: b           L_800669D0
    // 0x800669BC: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
        goto L_800669D0;
    // 0x800669BC: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
L_800669C0:
    // 0x800669C0: lw          $s2, 0x1C($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X1C);
    // 0x800669C4: nop

    // 0x800669C8: sll         $t9, $s2, 1
    ctx->r25 = S32(ctx->r18 << 1);
    // 0x800669CC: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_800669D0:
    // 0x800669D0: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800669D4: nop

    // 0x800669D8: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x800669DC: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x800669E0: addu        $s3, $s6, $t0
    ctx->r19 = ADD32(ctx->r22, ctx->r8);
    // 0x800669E4: jal         0x8009C850
    // 0x800669E8: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x800669E8: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
    after_0:
    // 0x800669EC: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x800669F0: beq         $t1, $zero, L_800669FC
    if (ctx->r9 == 0) {
        // 0x800669F4: sll         $t2, $s3, 4
        ctx->r10 = S32(ctx->r19 << 4);
            goto L_800669FC;
    }
    // 0x800669F4: sll         $t2, $s3, 4
    ctx->r10 = S32(ctx->r19 << 4);
    // 0x800669F8: negu        $s1, $s1
    ctx->r17 = SUB32(0, ctx->r17);
L_800669FC:
    // 0x800669FC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80066A00: addiu       $t4, $t4, -0x2948
    ctx->r12 = ADD32(ctx->r12, -0X2948);
    // 0x80066A04: addu        $v0, $t2, $t4
    ctx->r2 = ADD32(ctx->r10, ctx->r12);
    // 0x80066A08: sh          $s5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r21;
    // 0x80066A0C: sh          $s4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r20;
    // 0x80066A10: sh          $s1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r17;
    // 0x80066A14: sh          $s2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r18;
L_80066A18:
    // 0x80066A18: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80066A1C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80066A20: bne         $s6, $at, L_800668A4
    if (ctx->r22 != ctx->r1) {
        // 0x80066A24: addiu       $s0, $s0, 0x34
        ctx->r16 = ADD32(ctx->r16, 0X34);
            goto L_800668A4;
    }
    // 0x80066A24: addiu       $s0, $s0, 0x34
    ctx->r16 = ADD32(ctx->r16, 0X34);
    // 0x80066A28: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80066A2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066A30: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80066A34: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80066A38: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80066A3C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80066A40: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80066A44: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80066A48: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80066A4C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80066A50: jr          $ra
    // 0x80066A54: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80066A54: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8002B9BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B9FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002BA00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002BA04: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8002BA08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002BA0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002BA10: beq         $a2, $zero, L_8002BA30
    if (ctx->r6 == 0) {
        // 0x8002BA14: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8002BA30;
    }
    // 0x8002BA14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002BA18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002BA1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002BA20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002BA24: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8002BA28: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8002BA2C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
L_8002BA30:
    // 0x8002BA30: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002BA34: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8002BA38: lh          $a0, 0x2E($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X2E);
    // 0x8002BA3C: nop

    // 0x8002BA40: bltz        $a0, L_8002BA64
    if (SIGNED(ctx->r4) < 0) {
        // 0x8002BA44: nop
    
            goto L_8002BA64;
    }
    // 0x8002BA44: nop

    // 0x8002BA48: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x8002BA4C: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    // 0x8002BA50: lh          $t7, 0x1A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X1A);
    // 0x8002BA54: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8002BA58: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002BA5C: bne         $at, $zero, L_8002BA6C
    if (ctx->r1 != 0) {
        // 0x8002BA60: nop
    
            goto L_8002BA6C;
    }
    // 0x8002BA60: nop

L_8002BA64:
    // 0x8002BA64: b           L_8002BAE0
    // 0x8002BA68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002BAE0;
    // 0x8002BA68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002BA6C:
    // 0x8002BA6C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8002BA70: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002BA74: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8002BA78: lb          $t0, 0x2B($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X2B);
    // 0x8002BA7C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002BA80: beq         $t0, $zero, L_8002BAC8
    if (ctx->r8 == 0) {
        // 0x8002BA84: nop
    
            goto L_8002BAC8;
    }
    // 0x8002BA84: nop

    // 0x8002BA88: lw          $t1, -0x26FC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X26FC);
    // 0x8002BA8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002BA90: beq         $t1, $zero, L_8002BAC8
    if (ctx->r9 == 0) {
        // 0x8002BA94: nop
    
            goto L_8002BAC8;
    }
    // 0x8002BA94: nop

    // 0x8002BA98: bne         $a3, $at, L_8002BAC8
    if (ctx->r7 != ctx->r1) {
        // 0x8002BA9C: nop
    
            goto L_8002BAC8;
    }
    // 0x8002BA9C: nop

    // 0x8002BAA0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002BAA4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002BAA8: lw          $a1, 0xC($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC);
    // 0x8002BAAC: lw          $a2, 0x14($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X14);
    // 0x8002BAB0: jal         0x800BB814
    // 0x8002BAB4: nop

    func_800BB2F4(rdram, ctx);
        goto after_0;
    // 0x8002BAB4: nop

    after_0:
    // 0x8002BAB8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8002BABC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002BAC0: b           L_8002BAE0
    // 0x8002BAC4: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
        goto L_8002BAE0;
    // 0x8002BAC4: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
L_8002BAC8:
    // 0x8002BAC8: lh          $t4, 0x38($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X38);
    // 0x8002BACC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8002BAD0: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8002BAD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002BAD8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002BADC: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
L_8002BAE0:
    // 0x8002BAE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002BAE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002BAE8: jr          $ra
    // 0x8002BAEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002BAEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void get_gIntDisFlag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F7B0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F7B4: jr          $ra
    // 0x8006F7B8: lbu         $v0, -0x2660($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2660);
    return;
    // 0x8006F7B8: lbu         $v0, -0x2660($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2660);
;}
RECOMP_FUNC void music_change_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000B28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000B2C: jr          $ra
    // 0x80000B30: sw          $zero, -0x3448($at)
    MEM_W(-0X3448, ctx->r1) = 0;
    return;
    // 0x80000B30: sw          $zero, -0x3448($at)
    MEM_W(-0X3448, ctx->r1) = 0;
;}
RECOMP_FUNC void racer_sound_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006AC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80006ACC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80006AD0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80006AD4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80006AD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006ADC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80006AE0: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80006AE4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80006AE8: lw          $a1, 0x118($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X118);
    // 0x80006AEC: addiu       $s2, $s2, -0x5E48
    ctx->r18 = ADD32(ctx->r18, -0X5E48);
    // 0x80006AF0: beq         $a1, $zero, L_80006BE4
    if (ctx->r5 == 0) {
        // 0x80006AF4: sw          $a1, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r5;
            goto L_80006BE4;
    }
    // 0x80006AF4: sw          $a1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r5;
    // 0x80006AF8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80006AFC: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x80006B00: addu        $t9, $a1, $s0
    ctx->r25 = ADD32(ctx->r5, ctx->r16);
L_80006B04:
    // 0x80006B04: lw          $a0, 0x48($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X48);
    // 0x80006B08: nop

    // 0x80006B0C: beq         $a0, $zero, L_80006B34
    if (ctx->r4 == 0) {
        // 0x80006B10: nop
    
            goto L_80006B34;
    }
    // 0x80006B10: nop

    // 0x80006B14: jal         0x8000488C
    // 0x80006B18: nop

    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x80006B18: nop

    after_0:
    // 0x80006B1C: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80006B20: nop

    // 0x80006B24: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80006B28: sw          $zero, 0x48($t1)
    MEM_W(0X48, ctx->r9) = 0;
    // 0x80006B2C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80006B30: nop

L_80006B34:
    // 0x80006B34: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80006B38: bne         $s0, $s1, L_80006B04
    if (ctx->r16 != ctx->r17) {
        // 0x80006B3C: addu        $t9, $a1, $s0
        ctx->r25 = ADD32(ctx->r5, ctx->r16);
            goto L_80006B04;
    }
    // 0x80006B3C: addu        $t9, $a1, $s0
    ctx->r25 = ADD32(ctx->r5, ctx->r16);
    // 0x80006B40: lw          $a0, 0x50($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X50);
    // 0x80006B44: nop

    // 0x80006B48: beq         $a0, $zero, L_80006B6C
    if (ctx->r4 == 0) {
        // 0x80006B4C: nop
    
            goto L_80006B6C;
    }
    // 0x80006B4C: nop

    // 0x80006B50: jal         0x8000488C
    // 0x80006B54: nop

    sndp_stop(rdram, ctx);
        goto after_1;
    // 0x80006B54: nop

    after_1:
    // 0x80006B58: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80006B5C: nop

    // 0x80006B60: sw          $zero, 0x50($t2)
    MEM_W(0X50, ctx->r10) = 0;
    // 0x80006B64: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80006B68: nop

L_80006B6C:
    // 0x80006B6C: lw          $a0, 0xA8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XA8);
    // 0x80006B70: nop

    // 0x80006B74: beq         $a0, $zero, L_80006B98
    if (ctx->r4 == 0) {
        // 0x80006B78: nop
    
            goto L_80006B98;
    }
    // 0x80006B78: nop

    // 0x80006B7C: jal         0x8000488C
    // 0x80006B80: nop

    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x80006B80: nop

    after_2:
    // 0x80006B84: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80006B88: nop

    // 0x80006B8C: sw          $zero, 0xA8($t3)
    MEM_W(0XA8, ctx->r11) = 0;
    // 0x80006B90: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80006B94: nop

L_80006B98:
    // 0x80006B98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006B9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80006BA0: addiu       $v1, $v1, -0x5E48
    ctx->r3 = ADD32(ctx->r3, -0X5E48);
    // 0x80006BA4: addiu       $v0, $v0, -0x5E50
    ctx->r2 = ADD32(ctx->r2, -0X5E50);
L_80006BA8:
    // 0x80006BA8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80006BAC: nop

    // 0x80006BB0: bne         $a1, $t4, L_80006BBC
    if (ctx->r5 != ctx->r12) {
        // 0x80006BB4: nop
    
            goto L_80006BBC;
    }
    // 0x80006BB4: nop

    // 0x80006BB8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80006BBC:
    // 0x80006BBC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80006BC0: bne         $v0, $v1, L_80006BA8
    if (ctx->r2 != ctx->r3) {
        // 0x80006BC4: nop
    
            goto L_80006BA8;
    }
    // 0x80006BC4: nop

    // 0x80006BC8: jal         0x80071380
    // 0x80006BCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mempool_free(rdram, ctx);
        goto after_3;
    // 0x80006BCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x80006BD0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80006BD4: nop

    // 0x80006BD8: lw          $t6, 0x64($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X64);
    // 0x80006BDC: nop

    // 0x80006BE0: sw          $zero, 0x118($t6)
    MEM_W(0X118, ctx->r14) = 0;
L_80006BE4:
    // 0x80006BE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80006BE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006BEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80006BF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80006BF4: jr          $ra
    // 0x80006BF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80006BF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void charselect_assign_players(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A698: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A69C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006A6A0: addiu       $a2, $a2, 0x16D0
    ctx->r6 = ADD32(ctx->r6, 0X16D0);
    // 0x8006A6A4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006A6A8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_8006A6AC:
    // 0x8006A6AC: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x8006A6B0: addu        $t7, $a2, $v0
    ctx->r15 = ADD32(ctx->r6, ctx->r2);
    // 0x8006A6B4: beq         $t6, $zero, L_8006A6C4
    if (ctx->r14 == 0) {
        // 0x8006A6B8: nop
    
            goto L_8006A6C4;
    }
    // 0x8006A6B8: nop

    // 0x8006A6BC: sb          $v1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r3;
    // 0x8006A6C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006A6C4:
    // 0x8006A6C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006A6C8: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8006A6CC: bne         $at, $zero, L_8006A6AC
    if (ctx->r1 != 0) {
        // 0x8006A6D0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8006A6AC;
    }
    // 0x8006A6D0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006A6D4: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8006A6D8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8006A6DC: bne         $t8, $zero, L_8006A6EC
    if (ctx->r24 != 0) {
        // 0x8006A6E0: addu        $t9, $a2, $v0
        ctx->r25 = ADD32(ctx->r6, ctx->r2);
            goto L_8006A6EC;
    }
    // 0x8006A6E0: addu        $t9, $a2, $v0
    ctx->r25 = ADD32(ctx->r6, ctx->r2);
    // 0x8006A6E4: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8006A6E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006A6EC:
    // 0x8006A6EC: lb          $t0, 0x1($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X1);
    // 0x8006A6F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006A6F4: bne         $t0, $zero, L_8006A704
    if (ctx->r8 != 0) {
        // 0x8006A6F8: addu        $t2, $a2, $v0
        ctx->r10 = ADD32(ctx->r6, ctx->r2);
            goto L_8006A704;
    }
    // 0x8006A6F8: addu        $t2, $a2, $v0
    ctx->r10 = ADD32(ctx->r6, ctx->r2);
    // 0x8006A6FC: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
    // 0x8006A700: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006A704:
    // 0x8006A704: lb          $t3, 0x2($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X2);
    // 0x8006A708: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8006A70C: bne         $t3, $zero, L_8006A71C
    if (ctx->r11 != 0) {
        // 0x8006A710: addu        $t5, $a2, $v0
        ctx->r13 = ADD32(ctx->r6, ctx->r2);
            goto L_8006A71C;
    }
    // 0x8006A710: addu        $t5, $a2, $v0
    ctx->r13 = ADD32(ctx->r6, ctx->r2);
    // 0x8006A714: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x8006A718: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006A71C:
    // 0x8006A71C: lb          $t6, 0x3($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X3);
    // 0x8006A720: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8006A724: bne         $t6, $zero, L_8006A730
    if (ctx->r14 != 0) {
        // 0x8006A728: addu        $t8, $a2, $v0
        ctx->r24 = ADD32(ctx->r6, ctx->r2);
            goto L_8006A730;
    }
    // 0x8006A728: addu        $t8, $a2, $v0
    ctx->r24 = ADD32(ctx->r6, ctx->r2);
    // 0x8006A72C: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
L_8006A730:
    // 0x8006A730: jr          $ra
    // 0x8006A734: nop

    return;
    // 0x8006A734: nop

;}
RECOMP_FUNC void timetrial_load_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059A08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80059A0C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80059A10: lb          $v1, -0x24E4($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X24E4);
    // 0x80059A14: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80059A18: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80059A1C: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x80059A20: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80059A24: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80059A28: lw          $t2, -0x24F0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X24F0);
    // 0x80059A2C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80059A30: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80059A34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80059A38: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80059A3C: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80059A40: lh          $a1, 0x3E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3E);
    // 0x80059A44: addiu       $t0, $sp, 0x2E
    ctx->r8 = ADD32(ctx->r29, 0X2E);
    // 0x80059A48: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80059A4C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80059A50: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80059A54: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80059A58: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80059A5C: jal         0x80074D8C
    // 0x80059A60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80074B34(rdram, ctx);
        goto after_0;
    // 0x80059A60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x80059A64: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80059A68: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80059A6C: beq         $t3, $zero, L_80059AA8
    if (ctx->r11 == 0) {
        // 0x80059A70: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80059AA8;
    }
    // 0x80059A70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80059A74: bne         $v0, $zero, L_80059AA0
    if (ctx->r2 != 0) {
        // 0x80059A78: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_80059AA0;
    }
    // 0x80059A78: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80059A7C: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x80059A80: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
    // 0x80059A84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059A88: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80059A8C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80059A90: sh          $t4, -0x24E0($at)
    MEM_H(-0X24E0, ctx->r1) = ctx->r12;
    // 0x80059A94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059A98: b           L_80059AA8
    // 0x80059A9C: sh          $t6, -0x24D4($at)
    MEM_H(-0X24D4, ctx->r1) = ctx->r14;
        goto L_80059AA8;
    // 0x80059A9C: sh          $t6, -0x24D4($at)
    MEM_H(-0X24D4, ctx->r1) = ctx->r14;
L_80059AA0:
    // 0x80059AA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059AA4: sh          $t7, -0x24D4($at)
    MEM_H(-0X24D4, ctx->r1) = ctx->r15;
L_80059AA8:
    // 0x80059AA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80059AAC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80059AB0: jr          $ra
    // 0x80059AB4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80059AB4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void log(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007FA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80007FA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80007FAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007FB0: sub.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80007FB4: lwc1        $f19, 0x5288($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X5288);
    // 0x80007FB8: add.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80007FBC: lwc1        $f18, 0x528C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X528C);
    // 0x80007FC0: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80007FC4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80007FC8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80007FCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80007FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007FD4: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80007FD8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80007FDC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80007FE0: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80007FE4: nop

    // 0x80007FE8: bc1f        L_8000802C
    if (!c1cs) {
        // 0x80007FEC: mov.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
            goto L_8000802C;
    }
    // 0x80007FEC: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x80007FF0: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80007FF4: nop

L_80007FF8:
    // 0x80007FF8: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80007FFC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80008000: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008004: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80008008: div.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8000800C: mul.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80008010: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80008014: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80008018: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8000801C: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80008020: nop

    // 0x80008024: bc1t        L_80007FF8
    if (c1cs) {
        // 0x80008028: nop
    
            goto L_80007FF8;
    }
    // 0x80008028: nop

L_8000802C:
    // 0x8000802C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80008030: nop

    // 0x80008034: mul.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80008038: jr          $ra
    // 0x8000803C: nop

    return;
    // 0x8000803C: nop

;}
RECOMP_FUNC void get_time_data_file_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073EAC: jr          $ra
    // 0x80073EB0: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    return;
    // 0x80073EB0: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
;}
RECOMP_FUNC void racer_play_sound_after_delay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800570E4: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x800570E8: nop

    // 0x800570EC: sh          $a1, 0x20E($v0)
    MEM_H(0X20E, ctx->r2) = ctx->r5;
    // 0x800570F0: jr          $ra
    // 0x800570F4: sb          $a2, 0x210($v0)
    MEM_B(0X210, ctx->r2) = ctx->r6;
    return;
    // 0x800570F4: sb          $a2, 0x210($v0)
    MEM_B(0X210, ctx->r2) = ctx->r6;
;}
RECOMP_FUNC void sound_get_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001728: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000172C: addiu       $v1, $v1, 0x629C
    ctx->r3 = ADD32(ctx->r3, 0X629C);
    // 0x80001730: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80001734: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80001738: sll         $v0, $t6, 2
    ctx->r2 = S32(ctx->r14 << 2);
    // 0x8000173C: subu        $v0, $v0, $t6
    ctx->r2 = SUB32(ctx->r2, ctx->r14);
    // 0x80001740: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80001744: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80001748: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x8000174C: nop

    // 0x80001750: sb          $t9, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r25;
    // 0x80001754: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80001758: nop

    // 0x8000175C: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80001760: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80001764: nop

    // 0x80001768: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x8000176C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80001770: nop

    // 0x80001774: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80001778: lbu         $t5, 0x2($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X2);
    // 0x8000177C: jr          $ra
    // 0x80001780: sb          $t5, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r13;
    return;
    // 0x80001780: sb          $t5, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r13;
;}
RECOMP_FUNC void track_tex_anim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027E64: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80027E68: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80027E6C: lw          $a1, -0x3178($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3178);
    // 0x80027E70: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80027E74: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80027E78: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80027E7C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80027E80: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80027E84: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80027E88: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80027E8C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80027E90: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80027E94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80027E98: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x80027E9C: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80027EA0: lh          $v0, 0x1A($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X1A);
    // 0x80027EA4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80027EA8: blez        $v0, L_80027FD4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80027EAC: or          $s6, $v1, $zero
        ctx->r22 = ctx->r3 | 0;
            goto L_80027FD4;
    }
    // 0x80027EAC: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
    // 0x80027EB0: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x80027EB4: lui         $s7, 0x1
    ctx->r23 = S32(0X1 << 16);
    // 0x80027EB8: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
L_80027EBC:
    // 0x80027EBC: lh          $v1, 0x20($s6)
    ctx->r3 = MEM_H(ctx->r22, 0X20);
    // 0x80027EC0: lw          $s5, 0xC($s6)
    ctx->r21 = MEM_W(ctx->r22, 0XC);
    // 0x80027EC4: blez        $v1, L_80027FBC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80027EC8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80027FBC;
    }
    // 0x80027EC8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80027ECC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80027ED0: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
L_80027ED4:
    // 0x80027ED4: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80027ED8: nop

    // 0x80027EDC: and         $t7, $t6, $s7
    ctx->r15 = ctx->r14 & ctx->r23;
    // 0x80027EE0: beq         $t7, $zero, L_80027FA0
    if (ctx->r15 == 0) {
        // 0x80027EE4: nop
    
            goto L_80027FA0;
    }
    // 0x80027EE4: nop

    // 0x80027EE8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80027EEC: nop

    // 0x80027EF0: beq         $fp, $v0, L_80027FA0
    if (ctx->r30 == ctx->r2) {
        // 0x80027EF4: nop
    
            goto L_80027FA0;
    }
    // 0x80027EF4: nop

    // 0x80027EF8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80027EFC: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x80027F00: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80027F04: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80027F08: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80027F0C: lhu         $t1, 0x12($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X12);
    // 0x80027F10: nop

    // 0x80027F14: beq         $t1, $at, L_80027FA0
    if (ctx->r9 == ctx->r1) {
        // 0x80027F18: nop
    
            goto L_80027FA0;
    }
    // 0x80027F18: nop

    // 0x80027F1C: lhu         $t2, 0x14($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X14);
    // 0x80027F20: nop

    // 0x80027F24: beq         $t2, $zero, L_80027FA0
    if (ctx->r10 == 0) {
        // 0x80027F28: nop
    
            goto L_80027FA0;
    }
    // 0x80027F28: nop

    // 0x80027F2C: lbu         $t3, 0x7($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X7);
    // 0x80027F30: addu        $a1, $s2, $s5
    ctx->r5 = ADD32(ctx->r18, ctx->r21);
    // 0x80027F34: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x80027F38: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x80027F3C: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x80027F40: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80027F44: sll         $t6, $t5, 0
    ctx->r14 = S32(ctx->r13 << 0);
    // 0x80027F48: bgez        $t6, L_80027F7C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80027F4C: or          $a2, $s4, $zero
        ctx->r6 = ctx->r20 | 0;
            goto L_80027F7C;
    }
    // 0x80027F4C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80027F50: lbu         $t8, 0x6($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6);
    // 0x80027F54: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80027F58: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x80027F5C: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x80027F60: jal         0x8007F3D0
    // 0x80027F64: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    tex_animate_texture(rdram, ctx);
        goto after_0;
    // 0x80027F64: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_0:
    // 0x80027F68: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80027F6C: nop

    // 0x80027F70: andi        $t1, $t0, 0x3F
    ctx->r9 = ctx->r8 & 0X3F;
    // 0x80027F74: b           L_80027F84
    // 0x80027F78: sb          $t1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r9;
        goto L_80027F84;
    // 0x80027F78: sb          $t1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r9;
L_80027F7C:
    // 0x80027F7C: jal         0x8007F3D0
    // 0x80027F80: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    tex_animate_texture(rdram, ctx);
        goto after_1;
    // 0x80027F80: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_1:
L_80027F84:
    // 0x80027F84: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80027F88: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80027F8C: sra         $t4, $t2, 6
    ctx->r12 = S32(SIGNED(ctx->r10) >> 6);
    // 0x80027F90: sb          $t4, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r12;
    // 0x80027F94: lh          $v1, 0x20($s6)
    ctx->r3 = MEM_H(ctx->r22, 0X20);
    // 0x80027F98: lw          $a1, -0x3178($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3178);
    // 0x80027F9C: nop

L_80027FA0:
    // 0x80027FA0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80027FA4: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80027FA8: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80027FAC: bne         $at, $zero, L_80027ED4
    if (ctx->r1 != 0) {
        // 0x80027FB0: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80027ED4;
    }
    // 0x80027FB0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80027FB4: lh          $v0, 0x1A($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X1A);
    // 0x80027FB8: nop

L_80027FBC:
    // 0x80027FBC: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80027FC0: addiu       $s6, $s6, 0x44
    ctx->r22 = ADD32(ctx->r22, 0X44);
    // 0x80027FC4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80027FC8: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80027FCC: bne         $at, $zero, L_80027EBC
    if (ctx->r1 != 0) {
        // 0x80027FD0: sw          $t6, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r14;
            goto L_80027EBC;
    }
    // 0x80027FD0: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
L_80027FD4:
    // 0x80027FD4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80027FD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80027FDC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80027FE0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80027FE4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80027FE8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80027FEC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80027FF0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80027FF4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80027FF8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80027FFC: jr          $ra
    // 0x80028000: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80028000: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void menu_pause_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093F44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80093F48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80093F4C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80093F50: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80093F54: jal         0x800724E4
    // 0x80093F58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    rumble_init(rdram, ctx);
        goto after_0;
    // 0x80093F58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80093F5C: jal         0x8006ECD0
    // 0x80093F60: nop

    get_settings(rdram, ctx);
        goto after_1;
    // 0x80093F60: nop

    after_1:
    // 0x80093F64: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80093F68: addiu       $s1, $s1, 0xF0C
    ctx->r17 = ADD32(ctx->r17, 0XF0C);
    // 0x80093F6C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80093F70: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80093F74: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80093F78: jal         0x8009C91C
    // 0x80093F7C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    get_active_player_count(rdram, ctx);
        goto after_2;
    // 0x80093F7C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_2:
    // 0x80093F80: blez        $v0, L_80093FD4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80093F84: nop
    
            goto L_80093FD4;
    }
    // 0x80093F84: nop

    // 0x80093F88: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80093F8C: nop

    // 0x80093F90: bgez        $t7, L_80093FD4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80093F94: nop
    
            goto L_80093FD4;
    }
    // 0x80093F94: nop

L_80093F98:
    // 0x80093F98: jal         0x8006A768
    // 0x80093F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    input_held(rdram, ctx);
        goto after_3;
    // 0x80093F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80093FA0: andi        $t8, $v0, 0x1000
    ctx->r24 = ctx->r2 & 0X1000;
    // 0x80093FA4: beq         $t8, $zero, L_80093FB0
    if (ctx->r24 == 0) {
        // 0x80093FA8: nop
    
            goto L_80093FB0;
    }
    // 0x80093FA8: nop

    // 0x80093FAC: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
L_80093FB0:
    // 0x80093FB0: jal         0x8009C91C
    // 0x80093FB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    get_active_player_count(rdram, ctx);
        goto after_4;
    // 0x80093FB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_4:
    // 0x80093FB8: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80093FBC: beq         $at, $zero, L_80093FD4
    if (ctx->r1 == 0) {
        // 0x80093FC0: nop
    
            goto L_80093FD4;
    }
    // 0x80093FC0: nop

    // 0x80093FC4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80093FC8: nop

    // 0x80093FCC: bltz        $t9, L_80093F98
    if (SIGNED(ctx->r25) < 0) {
        // 0x80093FD0: nop
    
            goto L_80093F98;
    }
    // 0x80093FD0: nop

L_80093FD4:
    // 0x80093FD4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80093FD8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80093FDC: bgez        $t0, L_80093FE8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80093FE0: addiu       $a1, $a1, 0xF04
        ctx->r5 = ADD32(ctx->r5, 0XF04);
            goto L_80093FE8;
    }
    // 0x80093FE0: addiu       $a1, $a1, 0xF04
    ctx->r5 = ADD32(ctx->r5, 0XF04);
    // 0x80093FE4: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_80093FE8:
    // 0x80093FE8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80093FEC: addiu       $a2, $a2, -0x5E0
    ctx->r6 = ADD32(ctx->r6, -0X5E0);
    // 0x80093FF0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80093FF4: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80093FF8: lw          $t1, 0x188($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X188);
    // 0x80093FFC: addiu       $s1, $s1, 0x7000
    ctx->r17 = ADD32(ctx->r17, 0X7000);
    // 0x80094000: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80094004: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x80094008: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009400C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80094010: lw          $t2, 0x1568($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1568);
    // 0x80094014: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80094018: bne         $t2, $zero, L_800941E8
    if (ctx->r10 != 0) {
        // 0x8009401C: nop
    
            goto L_800941E8;
    }
    // 0x8009401C: nop

    // 0x80094020: lbu         $a0, 0x49($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X49);
    // 0x80094024: jal         0x8006B38C
    // 0x80094028: nop

    leveltable_type(rdram, ctx);
        goto after_5;
    // 0x80094028: nop

    after_5:
    // 0x8009402C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80094030: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80094034: lbu         $t5, 0x48($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X48);
    // 0x80094038: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009403C: addiu       $a2, $a2, -0x5E0
    ctx->r6 = ADD32(ctx->r6, -0X5E0);
    // 0x80094040: addiu       $a1, $a1, 0xF04
    ctx->r5 = ADD32(ctx->r5, 0XF04);
    // 0x80094044: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80094048: bne         $t5, $zero, L_80094094
    if (ctx->r13 != 0) {
        // 0x8009404C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80094094;
    }
    // 0x8009404C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80094050: jal         0x80023450
    // 0x80094054: nop

    is_taj_challenge(rdram, ctx);
        goto after_6;
    // 0x80094054: nop

    after_6:
    // 0x80094058: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009405C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80094060: addiu       $a2, $a2, -0x5E0
    ctx->r6 = ADD32(ctx->r6, -0X5E0);
    // 0x80094064: addiu       $a1, $a1, 0xF04
    ctx->r5 = ADD32(ctx->r5, 0XF04);
    // 0x80094068: beq         $v0, $zero, L_80094094
    if (ctx->r2 == 0) {
        // 0x8009406C: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80094094;
    }
    // 0x8009406C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80094070: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80094074: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80094078: lw          $t7, 0x200($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X200);
    // 0x8009407C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80094080: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80094084: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x80094088: lw          $v0, -0x5C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C8);
    // 0x8009408C: b           L_8009418C
    // 0x80094090: nop

        goto L_8009418C;
    // 0x80094090: nop

L_80094094:
    // 0x80094094: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80094098: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8009409C: lbu         $t0, 0x48($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X48);
    // 0x800940A0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800940A4: blez        $t0, L_80094154
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800940A8: nop
    
            goto L_80094154;
    }
    // 0x800940A8: nop

    // 0x800940AC: beq         $s0, $at, L_80094154
    if (ctx->r16 == ctx->r1) {
        // 0x800940B0: andi        $t1, $s0, 0x40
        ctx->r9 = ctx->r16 & 0X40;
            goto L_80094154;
    }
    // 0x800940B0: andi        $t1, $s0, 0x40
    ctx->r9 = ctx->r16 & 0X40;
    // 0x800940B4: beq         $t1, $zero, L_80094100
    if (ctx->r9 == 0) {
        // 0x800940B8: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80094100;
    }
    // 0x800940B8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800940BC: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800940C0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800940C4: lw          $t2, 0x1FC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X1FC);
    // 0x800940C8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800940CC: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    // 0x800940D0: lw          $t3, -0x5C8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5C8);
    // 0x800940D4: nop

    // 0x800940D8: bne         $t3, $zero, L_800940EC
    if (ctx->r11 != 0) {
        // 0x800940DC: nop
    
            goto L_800940EC;
    }
    // 0x800940DC: nop

    // 0x800940E0: lw          $t4, 0x64($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X64);
    // 0x800940E4: b           L_800940F8
    // 0x800940E8: sw          $t4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r12;
        goto L_800940F8;
    // 0x800940E8: sw          $t4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r12;
L_800940EC:
    // 0x800940EC: lw          $t5, 0x60($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X60);
    // 0x800940F0: nop

    // 0x800940F4: sw          $t5, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r13;
L_800940F8:
    // 0x800940F8: b           L_80094148
    // 0x800940FC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
        goto L_80094148;
    // 0x800940FC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_80094100:
    // 0x80094100: bne         $s0, $zero, L_80094148
    if (ctx->r16 != 0) {
        // 0x80094104: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_80094148;
    }
    // 0x80094104: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80094108: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8009410C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80094110: lw          $t7, 0x1F8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1F8);
    // 0x80094114: nop

    // 0x80094118: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x8009411C: lw          $t8, -0x5C8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5C8);
    // 0x80094120: nop

    // 0x80094124: bne         $t8, $zero, L_80094138
    if (ctx->r24 != 0) {
        // 0x80094128: nop
    
            goto L_80094138;
    }
    // 0x80094128: nop

    // 0x8009412C: lw          $t9, 0x64($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X64);
    // 0x80094130: b           L_80094144
    // 0x80094134: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
        goto L_80094144;
    // 0x80094134: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
L_80094138:
    // 0x80094138: lw          $t0, 0x60($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X60);
    // 0x8009413C: nop

    // 0x80094140: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_80094144:
    // 0x80094144: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_80094148:
    // 0x80094148: lw          $v0, -0x5C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C8);
    // 0x8009414C: b           L_8009418C
    // 0x80094150: nop

        goto L_8009418C;
    // 0x80094150: nop

L_80094154:
    // 0x80094154: lw          $v0, -0x5C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C8);
    // 0x80094158: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8009415C: bne         $v0, $zero, L_8009418C
    if (ctx->r2 != 0) {
        // 0x80094160: nop
    
            goto L_8009418C;
    }
    // 0x80094160: nop

    // 0x80094164: bne         $s0, $at, L_8009418C
    if (ctx->r16 != ctx->r1) {
        // 0x80094168: nop
    
            goto L_8009418C;
    }
    // 0x80094168: nop

    // 0x8009416C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80094170: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80094174: lw          $t2, 0x1F8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X1F8);
    // 0x80094178: nop

    // 0x8009417C: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    // 0x80094180: lw          $t3, 0x64($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X64);
    // 0x80094184: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80094188: sw          $t3, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r11;
L_8009418C:
    // 0x8009418C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80094190: lw          $v1, -0x5E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E0);
    // 0x80094194: bne         $a3, $v0, L_800941C8
    if (ctx->r7 != ctx->r2) {
        // 0x80094198: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_800941C8;
    }
    // 0x80094198: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009419C: lw          $t5, -0x5C4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5C4);
    // 0x800941A0: nop

    // 0x800941A4: bne         $a3, $t5, L_800941C8
    if (ctx->r7 != ctx->r13) {
        // 0x800941A8: nop
    
            goto L_800941C8;
    }
    // 0x800941A8: nop

    // 0x800941AC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800941B0: lw          $t6, 0x68($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X68);
    // 0x800941B4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800941B8: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x800941BC: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800941C0: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800941C4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_800941C8:
    // 0x800941C8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800941CC: lw          $t0, 0x20C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X20C);
    // 0x800941D0: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x800941D4: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x800941D8: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x800941DC: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x800941E0: b           L_80094204
    // 0x800941E4: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
        goto L_80094204;
    // 0x800941E4: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
L_800941E8:
    // 0x800941E8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800941EC: lw          $t4, 0x204($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X204);
    // 0x800941F0: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800941F4: addu        $t7, $s1, $t5
    ctx->r15 = ADD32(ctx->r17, ctx->r13);
    // 0x800941F8: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800941FC: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x80094200: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_80094204:
    // 0x80094204: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094208: sw          $zero, 0x7028($at)
    MEM_W(0X7028, ctx->r1) = 0;
    // 0x8009420C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094210: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x80094214: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094218: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8009421C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094220: sw          $a3, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = ctx->r7;
    // 0x80094224: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094228: jal         0x8009C3A0
    // 0x8009422C: sw          $zero, 0xF08($at)
    MEM_W(0XF08, ctx->r1) = 0;
    reset_controller_sticks(rdram, ctx);
        goto after_7;
    // 0x8009422C: sw          $zero, 0xF08($at)
    MEM_W(0XF08, ctx->r1) = 0;
    after_7:
    // 0x80094230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80094234: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80094238: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8009423C: jr          $ra
    // 0x80094240: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80094240: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void menu_postrace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095C2C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80095C30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80095C34: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80095C38: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80095C3C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80095C40: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80095C44: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80095C48: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x80095C4C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80095C50: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80095C54: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80095C58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095C5C: sw          $t7, 0x693C($at)
    MEM_W(0X693C, ctx->r1) = ctx->r15;
    // 0x80095C60: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80095C64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095C68: sw          $t9, 0x6944($at)
    MEM_W(0X6944, ctx->r1) = ctx->r25;
    // 0x80095C6C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80095C70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095C74: jal         0x8006ECD0
    // 0x80095C78: sw          $t5, 0x694C($at)
    MEM_W(0X694C, ctx->r1) = ctx->r13;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80095C78: sw          $t5, 0x694C($at)
    MEM_W(0X694C, ctx->r1) = ctx->r13;
    after_0:
    // 0x80095C7C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80095C80: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80095C84: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80095C88: bne         $t6, $zero, L_80095CA4
    if (ctx->r14 != 0) {
        // 0x80095C8C: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_80095CA4;
    }
    // 0x80095C8C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80095C90: addiu       $t7, $zero, 0x1A
    ctx->r15 = ADD32(0, 0X1A);
    // 0x80095C94: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80095C98: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80095C9C: b           L_80095CAC
    // 0x80095CA0: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_80095CAC;
    // 0x80095CA0: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80095CA4:
    // 0x80095CA4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80095CA8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80095CAC:
    // 0x80095CAC: lw          $t2, -0x5C4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5C4);
    // 0x80095CB0: jal         0x8009F1C4
    // 0x80095CB4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    is_in_two_player_adventure(rdram, ctx);
        goto after_1;
    // 0x80095CB4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_1:
    // 0x80095CB8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80095CBC: beq         $v0, $zero, L_80095CC8
    if (ctx->r2 == 0) {
        // 0x80095CC0: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80095CC8;
    }
    // 0x80095CC0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80095CC4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
L_80095CC8:
    // 0x80095CC8: lw          $t9, 0x7050($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7050);
    // 0x80095CCC: nop

    // 0x80095CD0: beq         $t9, $zero, L_80095D2C
    if (ctx->r25 == 0) {
        // 0x80095CD4: nop
    
            goto L_80095D2C;
    }
    // 0x80095CD4: nop

    // 0x80095CD8: jal         0x8001B7B4
    // 0x80095CDC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    has_ghost_to_save(rdram, ctx);
        goto after_2;
    // 0x80095CDC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_2:
    // 0x80095CE0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80095CE4: beq         $v0, $zero, L_80095D28
    if (ctx->r2 == 0) {
        // 0x80095CE8: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80095D28;
    }
    // 0x80095CE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095CEC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80095CF0: addiu       $t1, $t1, 0x71D4
    ctx->r9 = ADD32(ctx->r9, 0X71D4);
    // 0x80095CF4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80095CF8: lw          $v0, -0x5E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E0);
    // 0x80095CFC: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80095D00: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80095D04: lw          $t6, 0x6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6C);
    // 0x80095D08: addiu       $t5, $t5, 0x71B0
    ctx->r13 = ADD32(ctx->r13, 0X71B0);
    // 0x80095D0C: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80095D10: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x80095D14: sw          $t6, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r14;
    // 0x80095D18: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x80095D1C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80095D20: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80095D24: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_80095D28:
    // 0x80095D28: sw          $zero, 0x7050($at)
    MEM_W(0X7050, ctx->r1) = 0;
L_80095D2C:
    // 0x80095D2C: jal         0x80094F60
    // 0x80095D30: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    postrace_load(rdram, ctx);
        goto after_3;
    // 0x80095D30: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_3:
    // 0x80095D34: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80095D38: jal         0x80095118
    // 0x80095D3C: nop

    postrace_music_fade(rdram, ctx);
        goto after_4;
    // 0x80095D3C: nop

    after_4:
    // 0x80095D40: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80095D44: lw          $t9, -0x604($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X604);
    // 0x80095D48: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80095D4C: slti        $at, $t9, 0x14
    ctx->r1 = SIGNED(ctx->r25) < 0X14 ? 1 : 0;
    // 0x80095D50: beq         $at, $zero, L_80095D8C
    if (ctx->r1 == 0) {
        // 0x80095D54: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_80095D8C;
    }
    // 0x80095D54: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80095D58: lb          $t4, 0x71E8($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X71E8);
    // 0x80095D5C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80095D60: bne         $t4, $zero, L_80095D90
    if (ctx->r12 != 0) {
        // 0x80095D64: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80095D90;
    }
    // 0x80095D64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80095D68: lw          $t5, 0x7230($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7230);
    // 0x80095D6C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80095D70: bgez        $t5, L_80095DA8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80095D74: nop
    
            goto L_80095DA8;
    }
    // 0x80095D74: nop

    // 0x80095D78: jal         0x8009522C
    // 0x80095D7C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    postrace_viewport(rdram, ctx);
        goto after_5;
    // 0x80095D7C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_5:
    // 0x80095D80: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80095D84: b           L_80095DA8
    // 0x80095D88: nop

        goto L_80095DA8;
    // 0x80095D88: nop

L_80095D8C:
    // 0x80095D8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80095D90:
    // 0x80095D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80095D94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80095D98: jal         0x800785C0
    // 0x80095D9C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    bgdraw_texture_init(rdram, ctx);
        goto after_6;
    // 0x80095D9C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_6:
    // 0x80095DA0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80095DA4: nop

L_80095DA8:
    // 0x80095DA8: jal         0x8009C464
    // 0x80095DAC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    update_controller_sticks(rdram, ctx);
        goto after_7;
    // 0x80095DAC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_7:
    // 0x80095DB0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80095DB4: lw          $t6, 0x6964($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6964);
    // 0x80095DB8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80095DBC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80095DC0: addiu       $t1, $t1, 0x71D4
    ctx->r9 = ADD32(ctx->r9, 0X71D4);
    // 0x80095DC4: bne         $t6, $zero, L_80095E18
    if (ctx->r14 != 0) {
        // 0x80095DC8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80095E18;
    }
    // 0x80095DC8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80095DCC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80095DD0: lw          $t7, 0x7230($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7230);
    // 0x80095DD4: nop

    // 0x80095DD8: bgez        $t7, L_80095E18
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80095DDC: nop
    
            goto L_80095E18;
    }
    // 0x80095DDC: nop

    // 0x80095DE0: blez        $t2, L_80095E18
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80095DE4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80095E18;
    }
    // 0x80095DE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80095DE8:
    // 0x80095DE8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x80095DEC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80095DF0: jal         0x8006A794
    // 0x80095DF4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    input_pressed(rdram, ctx);
        goto after_8;
    // 0x80095DF4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_8:
    // 0x80095DF8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80095DFC: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80095E00: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80095E04: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80095E08: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80095E0C: addiu       $t1, $t1, 0x71D4
    ctx->r9 = ADD32(ctx->r9, 0X71D4);
    // 0x80095E10: bne         $a0, $t2, L_80095DE8
    if (ctx->r4 != ctx->r10) {
        // 0x80095E14: or          $v1, $v1, $v0
        ctx->r3 = ctx->r3 | ctx->r2;
            goto L_80095DE8;
    }
    // 0x80095E14: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80095E18:
    // 0x80095E18: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80095E1C: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
    // 0x80095E20: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80095E24: nop

    // 0x80095E28: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x80095E2C: beq         $at, $zero, L_80096C18
    if (ctx->r1 == 0) {
        // 0x80095E30: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80096C18;
    }
    // 0x80095E30: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80095E34: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80095E38: addu        $at, $at, $t8
    gpr jr_addend_80095E44 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80095E3C: lw          $t8, -0x7528($at)
    ctx->r24 = ADD32(ctx->r1, -0X7528);
    // 0x80095E40: nop

    // 0x80095E44: jr          $t8
    // 0x80095E48: nop

    switch (jr_addend_80095E44 >> 2) {
        case 0: goto L_80095E4C; break;
        case 1: goto L_80095E68; break;
        case 2: goto L_80096038; break;
        case 3: goto L_80096234; break;
        case 4: goto L_80096254; break;
        case 5: goto L_800963AC; break;
        case 6: goto L_800963CC; break;
        case 7: goto L_800969B0; break;
        case 8: goto L_800969E0; break;
        default: switch_error(__func__, 0x80095E44, 0x800E8AD8);
    }
    // 0x80095E48: nop

L_80095E4C:
    // 0x80095E4C: andi        $t9, $v1, 0x9000
    ctx->r25 = ctx->r3 & 0X9000;
    // 0x80095E50: beq         $t9, $zero, L_80096C18
    if (ctx->r25 == 0) {
        // 0x80095E54: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80096C18;
    }
    // 0x80095E54: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80095E58: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x80095E5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095E60: b           L_80096C18
    // 0x80095E64: sw          $zero, 0x7054($at)
    MEM_W(0X7054, ctx->r1) = 0;
        goto L_80096C18;
    // 0x80095E64: sw          $zero, 0x7054($at)
    MEM_W(0X7054, ctx->r1) = 0;
L_80095E68:
    // 0x80095E68: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80095E6C: lw          $t4, 0x7054($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7054);
    // 0x80095E70: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80095E74: slti        $at, $t4, 0x3D
    ctx->r1 = SIGNED(ctx->r12) < 0X3D ? 1 : 0;
    // 0x80095E78: beq         $at, $zero, L_80095E8C
    if (ctx->r1 == 0) {
        // 0x80095E7C: nop
    
            goto L_80095E8C;
    }
    // 0x80095E7C: nop

    // 0x80095E80: andi        $t5, $v1, 0x9000
    ctx->r13 = ctx->r3 & 0X9000;
    // 0x80095E84: beq         $t5, $zero, L_80096C18
    if (ctx->r13 == 0) {
        // 0x80095E88: nop
    
            goto L_80096C18;
    }
    // 0x80095E88: nop

L_80095E8C:
    // 0x80095E8C: lw          $v0, 0x6A18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A18);
    // 0x80095E90: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80095E94: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80095E98: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x80095E9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80095EA0: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80095EA4: bne         $v1, $zero, L_80095EB0
    if (ctx->r3 != 0) {
        // 0x80095EA8: nop
    
            goto L_80095EB0;
    }
    // 0x80095EA8: nop

    // 0x80095EAC: break       7
    do_break(2148097708);
L_80095EB0:
    // 0x80095EB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80095EB4: bne         $v1, $at, L_80095EC8
    if (ctx->r3 != ctx->r1) {
        // 0x80095EB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80095EC8;
    }
    // 0x80095EB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095EBC: bne         $t6, $at, L_80095EC8
    if (ctx->r14 != ctx->r1) {
        // 0x80095EC0: nop
    
            goto L_80095EC8;
    }
    // 0x80095EC0: nop

    // 0x80095EC4: break       6
    do_break(2148097732);
L_80095EC8:
    // 0x80095EC8: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x80095ECC: mflo        $t7
    ctx->r15 = lo;
    // 0x80095ED0: subu        $a2, $v0, $t7
    ctx->r6 = SUB32(ctx->r2, ctx->r15);
    // 0x80095ED4: nop

    // 0x80095ED8: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x80095EDC: bne         $v1, $zero, L_80095EE8
    if (ctx->r3 != 0) {
        // 0x80095EE0: nop
    
            goto L_80095EE8;
    }
    // 0x80095EE0: nop

    // 0x80095EE4: break       7
    do_break(2148097764);
L_80095EE8:
    // 0x80095EE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80095EEC: bne         $v1, $at, L_80095F00
    if (ctx->r3 != ctx->r1) {
        // 0x80095EF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80095F00;
    }
    // 0x80095EF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095EF4: bne         $v0, $at, L_80095F00
    if (ctx->r2 != ctx->r1) {
        // 0x80095EF8: nop
    
            goto L_80095F00;
    }
    // 0x80095EF8: nop

    // 0x80095EFC: break       6
    do_break(2148097788);
L_80095F00:
    // 0x80095F00: mflo        $t8
    ctx->r24 = lo;
    // 0x80095F04: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80095F08: jal         0x80066B80
    // 0x80095F0C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    viewport_menu_set(rdram, ctx);
        goto after_9;
    // 0x80095F0C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_9:
    // 0x80095F10: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80095F14: addiu       $v0, $v0, -0x324
    ctx->r2 = ADD32(ctx->r2, -0X324);
    // 0x80095F18: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80095F1C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80095F20: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80095F24: swc1        $f4, 0x8C($t4)
    MEM_W(0X8C, ctx->r12) = ctx->f4.u32l;
    // 0x80095F28: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80095F2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095F30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095F34: swc1        $f6, 0x90($t5)
    MEM_W(0X90, ctx->r13) = ctx->f6.u32l;
    // 0x80095F38: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80095F3C: lwc1        $f8, -0x4E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4E8);
    // 0x80095F40: nop

    // 0x80095F44: swc1        $f8, 0x88($t6)
    MEM_W(0X88, ctx->r14) = ctx->f8.u32l;
    // 0x80095F48: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80095F4C: nop

    // 0x80095F50: lbu         $a0, 0x49($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X49);
    // 0x80095F54: jal         0x8006B38C
    // 0x80095F58: nop

    leveltable_type(rdram, ctx);
        goto after_10;
    // 0x80095F58: nop

    after_10:
    // 0x80095F5C: andi        $t8, $v0, 0x40
    ctx->r24 = ctx->r2 & 0X40;
    // 0x80095F60: beq         $t8, $zero, L_80095F74
    if (ctx->r24 == 0) {
        // 0x80095F64: addiu       $t9, $zero, 0x6
        ctx->r25 = ADD32(0, 0X6);
            goto L_80095F74;
    }
    // 0x80095F64: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80095F68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095F6C: b           L_80096C18
    // 0x80095F70: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
        goto L_80096C18;
    // 0x80095F70: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
L_80095F74:
    // 0x80095F74: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80095F78: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80095F7C: lb          $t4, 0x117($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X117);
    // 0x80095F80: addiu       $a0, $a0, 0x116C
    ctx->r4 = ADD32(ctx->r4, 0X116C);
    // 0x80095F84: bne         $t4, $zero, L_80095FCC
    if (ctx->r12 != 0) {
        // 0x80095F88: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80095FCC;
    }
    // 0x80095F88: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80095F8C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80095F90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80095F94: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80095F98: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80095F9C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80095FA0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80095FA4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80095FA8: addiu       $a0, $a0, 0x126C
    ctx->r4 = ADD32(ctx->r4, 0X126C);
    // 0x80095FAC: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x80095FB0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80095FB4: jal         0x800822A4
    // 0x80095FB8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    postrace_offsets(rdram, ctx);
        goto after_11;
    // 0x80095FB8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_11:
    // 0x80095FBC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80095FC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095FC4: b           L_80096C18
    // 0x80095FC8: sw          $t7, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r15;
        goto L_80096C18;
    // 0x80095FC8: sw          $t7, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r15;
L_80095FCC:
    // 0x80095FCC: lb          $t8, 0x114($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X114);
    // 0x80095FD0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80095FD4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80095FD8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80095FDC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80095FE0: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x80095FE4: addiu       $v0, $v0, 0x54
    ctx->r2 = ADD32(ctx->r2, 0X54);
    // 0x80095FE8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80095FEC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80095FF0: addiu       $t4, $v0, 0x12
    ctx->r12 = ADD32(ctx->r2, 0X12);
    // 0x80095FF4: addiu       $t5, $v0, 0x14
    ctx->r13 = ADD32(ctx->r2, 0X14);
    // 0x80095FF8: addiu       $t6, $v0, 0x16
    ctx->r14 = ADD32(ctx->r2, 0X16);
    // 0x80095FFC: addiu       $t7, $v0, 0x10
    ctx->r15 = ADD32(ctx->r2, 0X10);
    // 0x80096000: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80096004: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80096008: sw          $t4, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r12;
    // 0x8009600C: sw          $t5, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->r13;
    // 0x80096010: sw          $t6, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->r14;
    // 0x80096014: sw          $t7, 0xD4($a0)
    MEM_W(0XD4, ctx->r4) = ctx->r15;
    // 0x80096018: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x8009601C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80096020: jal         0x800822A4
    // 0x80096024: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    postrace_offsets(rdram, ctx);
        goto after_12;
    // 0x80096024: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_12:
    // 0x80096028: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8009602C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096030: b           L_80096C18
    // 0x80096034: sw          $a2, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r6;
        goto L_80096C18;
    // 0x80096034: sw          $a2, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r6;
L_80096038:
    // 0x80096038: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8009603C: jal         0x8008239C
    // 0x80096040: nop

    postrace_render(rdram, ctx);
        goto after_13;
    // 0x80096040: nop

    after_13:
    // 0x80096044: beq         $v0, $zero, L_80096C18
    if (ctx->r2 == 0) {
        // 0x80096048: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_80096C18;
    }
    // 0x80096048: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009604C: lw          $t4, 0x1568($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1568);
    // 0x80096050: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80096054: beq         $t4, $zero, L_80096080
    if (ctx->r12 == 0) {
        // 0x80096058: nop
    
            goto L_80096080;
    }
    // 0x80096058: nop

    // 0x8009605C: jal         0x80000C98
    // 0x80096060: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_14;
    // 0x80096060: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_14:
    // 0x80096064: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096068: jal         0x800C06F8
    // 0x8009606C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_15;
    // 0x8009606C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_15:
    // 0x80096070: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80096074: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096078: b           L_80096C18
    // 0x8009607C: sw          $t5, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r13;
        goto L_80096C18;
    // 0x8009607C: sw          $t5, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r13;
L_80096080:
    // 0x80096080: lb          $t6, 0x117($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X117);
    // 0x80096084: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80096088: beq         $t6, $zero, L_800961F8
    if (ctx->r14 == 0) {
        // 0x8009608C: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_800961F8;
    }
    // 0x8009608C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80096090: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80096094: lb          $t7, 0x6F80($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X6F80);
    // 0x80096098: lbu         $t4, 0x49($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X49);
    // 0x8009609C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800960A0: addu        $v0, $a3, $t8
    ctx->r2 = ADD32(ctx->r7, ctx->r24);
    // 0x800960A4: lw          $t9, 0x3C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X3C);
    // 0x800960A8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800960AC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800960B0: addiu       $v1, $v1, 0x13CC
    ctx->r3 = ADD32(ctx->r3, 0X13CC);
    // 0x800960B4: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800960B8: sw          $t6, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->r14;
    // 0x800960BC: lbu         $t8, 0x49($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X49);
    // 0x800960C0: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x800960C4: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x800960C8: addu        $t9, $t7, $t4
    ctx->r25 = ADD32(ctx->r15, ctx->r12);
    // 0x800960CC: sw          $t9, 0xD4($v1)
    MEM_W(0XD4, ctx->r3) = ctx->r25;
    // 0x800960D0: lbu         $t6, 0x49($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X49);
    // 0x800960D4: lw          $t5, 0x30($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X30);
    // 0x800960D8: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800960DC: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800960E0: lhu         $a0, 0x0($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X0);
    // 0x800960E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800960E8: addiu       $a1, $a1, 0x6930
    ctx->r5 = ADD32(ctx->r5, 0X6930);
    // 0x800960EC: jal         0x80097C34
    // 0x800960F0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_16;
    // 0x800960F0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_16:
    // 0x800960F4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800960F8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800960FC: lb          $t4, 0x6F80($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X6F80);
    // 0x80096100: lbu         $t8, 0x49($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X49);
    // 0x80096104: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80096108: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x8009610C: lw          $t5, 0x18($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X18);
    // 0x80096110: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x80096114: addu        $t4, $t5, $t7
    ctx->r12 = ADD32(ctx->r13, ctx->r15);
    // 0x80096118: lhu         $a0, 0x0($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X0);
    // 0x8009611C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80096120: addiu       $a1, $a1, 0x6934
    ctx->r5 = ADD32(ctx->r5, 0X6934);
    // 0x80096124: jal         0x80097C34
    // 0x80096128: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_17;
    // 0x80096128: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_17:
    // 0x8009612C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80096130: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096134: lb          $t9, 0x58($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X58);
    // 0x80096138: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8009613C: beq         $t9, $zero, L_800961C4
    if (ctx->r25 == 0) {
        // 0x80096140: addiu       $a0, $a0, 0x13CC
        ctx->r4 = ADD32(ctx->r4, 0X13CC);
            goto L_800961C4;
    }
    // 0x80096140: addiu       $a0, $a0, 0x13CC
    ctx->r4 = ADD32(ctx->r4, 0X13CC);
    // 0x80096144: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80096148: lw          $t8, -0x5C8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5C8);
    // 0x8009614C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80096150: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096154: bne         $t8, $zero, L_80096184
    if (ctx->r24 != 0) {
        // 0x80096158: sw          $t6, 0x6980($at)
        MEM_W(0X6980, ctx->r1) = ctx->r14;
            goto L_80096184;
    }
    // 0x80096158: sw          $t6, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r14;
    // 0x8009615C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80096160: lw          $t5, 0x152C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X152C);
    // 0x80096164: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80096168: beq         $t5, $zero, L_80096184
    if (ctx->r13 == 0) {
        // 0x8009616C: addiu       $a1, $a1, 0x1528
        ctx->r5 = ADD32(ctx->r5, 0X1528);
            goto L_80096184;
    }
    // 0x8009616C: addiu       $a1, $a1, 0x1528
    ctx->r5 = ADD32(ctx->r5, 0X1528);
    // 0x80096170: lw          $a0, 0x50($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X50);
    // 0x80096174: jal         0x80097C34
    // 0x80096178: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_18;
    // 0x80096178: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_18:
    // 0x8009617C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096180: sw          $zero, 0x152C($at)
    MEM_W(0X152C, ctx->r1) = 0;
L_80096184:
    // 0x80096184: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80096188: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009618C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80096190: addiu       $t4, $t4, 0x1528
    ctx->r12 = ADD32(ctx->r12, 0X1528);
    // 0x80096194: addiu       $t7, $t7, 0x1524
    ctx->r15 = ADD32(ctx->r15, 0X1524);
    // 0x80096198: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8009619C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800961A0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800961A4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800961A8: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x800961AC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800961B0: addiu       $a0, $v0, 0xC4
    ctx->r4 = ADD32(ctx->r2, 0XC4);
    // 0x800961B4: jal         0x80097DB0
    // 0x800961B8: addiu       $a2, $v0, 0x78
    ctx->r6 = ADD32(ctx->r2, 0X78);
    filename_init(rdram, ctx);
        goto after_19;
    // 0x800961B8: addiu       $a2, $v0, 0x78
    ctx->r6 = ADD32(ctx->r2, 0X78);
    after_19:
    // 0x800961BC: b           L_80096C18
    // 0x800961C0: nop

        goto L_80096C18;
    // 0x800961C0: nop

L_800961C4:
    // 0x800961C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800961C8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800961CC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800961D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800961D4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800961D8: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x800961DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800961E0: jal         0x800822A4
    // 0x800961E4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    postrace_offsets(rdram, ctx);
        goto after_20;
    // 0x800961E4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_20:
    // 0x800961E8: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x800961EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800961F0: b           L_80096C18
    // 0x800961F4: sw          $v1, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r3;
        goto L_80096C18;
    // 0x800961F4: sw          $v1, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r3;
L_800961F8:
    // 0x800961F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800961FC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80096200: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80096204: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096208: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009620C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80096210: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80096214: sw          $t5, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r13;
    // 0x80096218: addiu       $a0, $a0, 0x126C
    ctx->r4 = ADD32(ctx->r4, 0X126C);
    // 0x8009621C: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x80096220: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80096224: jal         0x800822A4
    // 0x80096228: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    postrace_offsets(rdram, ctx);
        goto after_21;
    // 0x80096228: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_21:
    // 0x8009622C: b           L_80096C18
    // 0x80096230: nop

        goto L_80096C18;
    // 0x80096230: nop

L_80096234:
    // 0x80096234: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80096238: jal         0x8008239C
    // 0x8009623C: nop

    postrace_render(rdram, ctx);
        goto after_22;
    // 0x8009623C: nop

    after_22:
    // 0x80096240: beq         $v0, $zero, L_80096C18
    if (ctx->r2 == 0) {
        // 0x80096244: addiu       $t9, $zero, 0x6
        ctx->r25 = ADD32(0, 0X6);
            goto L_80096C18;
    }
    // 0x80096244: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80096248: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009624C: b           L_80096C18
    // 0x80096250: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
        goto L_80096C18;
    // 0x80096250: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
L_80096254:
    // 0x80096254: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80096258: jal         0x8009824C
    // 0x8009625C: nop

    filename_enter(rdram, ctx);
        goto after_23;
    // 0x8009625C: nop

    after_23:
    // 0x80096260: beq         $v0, $zero, L_80096C18
    if (ctx->r2 == 0) {
        // 0x80096264: nop
    
            goto L_80096C18;
    }
    // 0x80096264: nop

    // 0x80096268: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8009626C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096270: lb          $v0, 0x58($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X58);
    // 0x80096274: addiu       $a0, $a0, 0x1528
    ctx->r4 = ADD32(ctx->r4, 0X1528);
    // 0x80096278: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x8009627C: beq         $t8, $zero, L_800962FC
    if (ctx->r24 == 0) {
        // 0x80096280: andi        $t6, $v0, 0x80
        ctx->r14 = ctx->r2 & 0X80;
            goto L_800962FC;
    }
    // 0x80096280: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x80096284: jal         0x80097C80
    // 0x80096288: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    filename_compress(rdram, ctx);
        goto after_24;
    // 0x80096288: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_24:
    // 0x8009628C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80096290: addiu       $a3, $a3, 0x6F80
    ctx->r7 = ADD32(ctx->r7, 0X6F80);
    // 0x80096294: lb          $t5, 0x0($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X0);
    // 0x80096298: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8009629C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800962A0: lbu         $t6, 0x49($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X49);
    // 0x800962A4: addu        $t4, $v1, $t7
    ctx->r12 = ADD32(ctx->r3, ctx->r15);
    // 0x800962A8: lw          $t9, 0x18($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X18);
    // 0x800962AC: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800962B0: addu        $t5, $t9, $t8
    ctx->r13 = ADD32(ctx->r25, ctx->r24);
    // 0x800962B4: sh          $v0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r2;
    // 0x800962B8: lb          $t7, 0x0($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X0);
    // 0x800962BC: lbu         $t8, 0x49($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X49);
    // 0x800962C0: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x800962C4: addu        $t6, $v1, $t4
    ctx->r14 = ADD32(ctx->r3, ctx->r12);
    // 0x800962C8: lw          $t9, 0x18($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X18);
    // 0x800962CC: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x800962D0: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x800962D4: lhu         $a0, 0x0($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X0);
    // 0x800962D8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800962DC: addiu       $a1, $a1, 0x6934
    ctx->r5 = ADD32(ctx->r5, 0X6934);
    // 0x800962E0: jal         0x80097C34
    // 0x800962E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_25;
    // 0x800962E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_25:
    // 0x800962E8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800962EC: nop

    // 0x800962F0: lb          $v0, 0x58($t4)
    ctx->r2 = MEM_B(ctx->r12, 0X58);
    // 0x800962F4: nop

    // 0x800962F8: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
L_800962FC:
    // 0x800962FC: beq         $t6, $zero, L_8009636C
    if (ctx->r14 == 0) {
        // 0x80096300: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8009636C;
    }
    // 0x80096300: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096304: addiu       $a0, $a0, 0x1528
    ctx->r4 = ADD32(ctx->r4, 0X1528);
    // 0x80096308: jal         0x80097C80
    // 0x8009630C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    filename_compress(rdram, ctx);
        goto after_26;
    // 0x8009630C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_26:
    // 0x80096310: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80096314: addiu       $a3, $a3, 0x6F80
    ctx->r7 = ADD32(ctx->r7, 0X6F80);
    // 0x80096318: lb          $t8, 0x0($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X0);
    // 0x8009631C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80096320: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80096324: lbu         $t4, 0x49($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X49);
    // 0x80096328: addu        $t5, $v1, $t9
    ctx->r13 = ADD32(ctx->r3, ctx->r25);
    // 0x8009632C: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80096330: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80096334: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80096338: sh          $v0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r2;
    // 0x8009633C: lb          $t9, 0x0($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X0);
    // 0x80096340: lbu         $t6, 0x49($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X49);
    // 0x80096344: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80096348: addu        $t4, $v1, $t5
    ctx->r12 = ADD32(ctx->r3, ctx->r13);
    // 0x8009634C: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x80096350: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80096354: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80096358: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    // 0x8009635C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80096360: addiu       $a1, $a1, 0x6930
    ctx->r5 = ADD32(ctx->r5, 0X6930);
    // 0x80096364: jal         0x80097C34
    // 0x80096368: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_27;
    // 0x80096368: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_27:
L_8009636C:
    // 0x8009636C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80096370: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80096374: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80096378: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8009637C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096380: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80096384: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80096388: addiu       $a0, $a0, 0x13CC
    ctx->r4 = ADD32(ctx->r4, 0X13CC);
    // 0x8009638C: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x80096390: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80096394: jal         0x800822A4
    // 0x80096398: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    postrace_offsets(rdram, ctx);
        goto after_28;
    // 0x80096398: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_28:
    // 0x8009639C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x800963A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800963A4: b           L_80096C18
    // 0x800963A8: sw          $v1, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r3;
        goto L_80096C18;
    // 0x800963A8: sw          $v1, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r3;
L_800963AC:
    // 0x800963AC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x800963B0: jal         0x8008239C
    // 0x800963B4: nop

    postrace_render(rdram, ctx);
        goto after_29;
    // 0x800963B4: nop

    after_29:
    // 0x800963B8: beq         $v0, $zero, L_80096C18
    if (ctx->r2 == 0) {
        // 0x800963BC: addiu       $t6, $zero, 0x6
        ctx->r14 = ADD32(0, 0X6);
            goto L_80096C18;
    }
    // 0x800963BC: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800963C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800963C4: b           L_80096C18
    // 0x800963C8: sw          $t6, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r14;
        goto L_80096C18;
    // 0x800963C8: sw          $t6, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r14;
L_800963CC:
    // 0x800963CC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800963D0: addiu       $a1, $a1, 0x7058
    ctx->r5 = ADD32(ctx->r5, 0X7058);
    // 0x800963D4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800963D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800963DC: beq         $v0, $zero, L_800964C4
    if (ctx->r2 == 0) {
        // 0x800963E0: addiu       $a0, $a0, 0x71DC
        ctx->r4 = ADD32(ctx->r4, 0X71DC);
            goto L_800964C4;
    }
    // 0x800963E0: addiu       $a0, $a0, 0x71DC
    ctx->r4 = ADD32(ctx->r4, 0X71DC);
    // 0x800963E4: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800963E8: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x800963EC: bne         $at, $zero, L_80096958
    if (ctx->r1 != 0) {
        // 0x800963F0: sw          $t7, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r15;
            goto L_80096958;
    }
    // 0x800963F0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800963F4: jal         0x80000968
    // 0x800963F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    sound_volume_change(rdram, ctx);
        goto after_30;
    // 0x800963F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_30:
    // 0x800963FC: jal         0x8001B76C
    // 0x80096400: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    timetrial_save_player_ghost(rdram, ctx);
        goto after_31;
    // 0x80096400: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_31:
    // 0x80096404: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80096408: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8009640C: bne         $v1, $t9, L_80096420
    if (ctx->r3 != ctx->r25) {
        // 0x80096410: sw          $v0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r2;
            goto L_80096420;
    }
    // 0x80096410: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80096414: jal         0x8001B76C
    // 0x80096418: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    timetrial_save_player_ghost(rdram, ctx);
        goto after_32;
    // 0x80096418: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_32:
    // 0x8009641C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_80096420:
    // 0x80096420: jal         0x80000968
    // 0x80096424: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    sound_volume_change(rdram, ctx);
        goto after_33;
    // 0x80096424: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_33:
    // 0x80096428: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8009642C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80096430: beq         $t5, $zero, L_8009644C
    if (ctx->r13 == 0) {
        // 0x80096434: addiu       $t1, $t1, 0x71D4
        ctx->r9 = ADD32(ctx->r9, 0X71D4);
            goto L_8009644C;
    }
    // 0x80096434: addiu       $t1, $t1, 0x71D4
    ctx->r9 = ADD32(ctx->r9, 0X71D4);
    // 0x80096438: jal         0x80095B28
    // 0x8009643C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    postrace_message(rdram, ctx);
        goto after_34;
    // 0x8009643C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_34:
    // 0x80096440: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80096444: b           L_800964B8
    // 0x80096448: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
        goto L_800964B8;
    // 0x80096448: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
L_8009644C:
    // 0x8009644C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80096450: addiu       $a0, $a0, 0x71DC
    ctx->r4 = ADD32(ctx->r4, 0X71DC);
    // 0x80096454: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80096458: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009645C: addiu       $t7, $t7, 0xF84
    ctx->r15 = ADD32(ctx->r15, 0XF84);
    // 0x80096460: bne         $t6, $t7, L_8009647C
    if (ctx->r14 != ctx->r15) {
        // 0x80096464: nop
    
            goto L_8009647C;
    }
    // 0x80096464: nop

    // 0x80096468: jal         0x80095B28
    // 0x8009646C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    postrace_message(rdram, ctx);
        goto after_35;
    // 0x8009646C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_35:
    // 0x80096470: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80096474: b           L_80096480
    // 0x80096478: addiu       $t1, $t1, 0x71D4
    ctx->r9 = ADD32(ctx->r9, 0X71D4);
        goto L_80096480;
    // 0x80096478: addiu       $t1, $t1, 0x71D4
    ctx->r9 = ADD32(ctx->r9, 0X71D4);
L_8009647C:
    // 0x8009647C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80096480:
    // 0x80096480: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80096484: addiu       $a2, $a2, 0x7028
    ctx->r6 = ADD32(ctx->r6, 0X7028);
    // 0x80096488: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009648C: lw          $t8, -0x5E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E0);
    // 0x80096490: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80096494: lw          $t9, 0x70($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X70);
    // 0x80096498: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009649C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x800964A0: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800964A4: sw          $t9, 0x71B0($at)
    MEM_W(0X71B0, ctx->r1) = ctx->r25;
    // 0x800964A8: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800964AC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800964B0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800964B4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
L_800964B8:
    // 0x800964B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800964BC: b           L_80096958
    // 0x800964C0: sw          $zero, 0x7058($at)
    MEM_W(0X7058, ctx->r1) = 0;
        goto L_80096958;
    // 0x800964C0: sw          $zero, 0x7058($at)
    MEM_W(0X7058, ctx->r1) = 0;
L_800964C4:
    // 0x800964C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800964C8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800964CC: beq         $v0, $zero, L_8009651C
    if (ctx->r2 == 0) {
        // 0x800964D0: addiu       $t0, $t0, 0xF08
        ctx->r8 = ADD32(ctx->r8, 0XF08);
            goto L_8009651C;
    }
    // 0x800964D0: addiu       $t0, $t0, 0xF08
    ctx->r8 = ADD32(ctx->r8, 0XF08);
    // 0x800964D4: andi        $t8, $v1, 0x9000
    ctx->r24 = ctx->r3 & 0X9000;
    // 0x800964D8: beq         $t8, $zero, L_80096508
    if (ctx->r24 == 0) {
        // 0x800964DC: andi        $t4, $v1, 0x4000
        ctx->r12 = ctx->r3 & 0X4000;
            goto L_80096508;
    }
    // 0x800964DC: andi        $t4, $v1, 0x4000
    ctx->r12 = ctx->r3 & 0X4000;
    // 0x800964E0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800964E4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800964E8: addiu       $t9, $t9, 0xF84
    ctx->r25 = ADD32(ctx->r25, 0XF84);
    // 0x800964EC: bne         $v0, $t9, L_80096500
    if (ctx->r2 != ctx->r25) {
        // 0x800964F0: sw          $t5, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r13;
            goto L_80096500;
    }
    // 0x800964F0: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x800964F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800964F8: b           L_80096958
    // 0x800964FC: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
        goto L_80096958;
    // 0x800964FC: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
L_80096500:
    // 0x80096500: b           L_80096958
    // 0x80096504: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_80096958;
    // 0x80096504: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80096508:
    // 0x80096508: beq         $t4, $zero, L_80096958
    if (ctx->r12 == 0) {
        // 0x8009650C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80096958;
    }
    // 0x8009650C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80096510: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80096514: b           L_80096958
    // 0x80096518: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
        goto L_80096958;
    // 0x80096518: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
L_8009651C:
    // 0x8009651C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80096520: andi        $t7, $v1, 0x9000
    ctx->r15 = ctx->r3 & 0X9000;
    // 0x80096524: beq         $v0, $zero, L_8009670C
    if (ctx->r2 == 0) {
        // 0x80096528: andi        $t9, $v1, 0x9000
        ctx->r25 = ctx->r3 & 0X9000;
            goto L_8009670C;
    }
    // 0x80096528: andi        $t9, $v1, 0x9000
    ctx->r25 = ctx->r3 & 0X9000;
    // 0x8009652C: beq         $t7, $zero, L_80096578
    if (ctx->r15 == 0) {
        // 0x80096530: andi        $t4, $v1, 0x4000
        ctx->r12 = ctx->r3 & 0X4000;
            goto L_80096578;
    }
    // 0x80096530: andi        $t4, $v1, 0x4000
    ctx->r12 = ctx->r3 & 0X4000;
    // 0x80096534: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80096538: bne         $a3, $v0, L_8009656C
    if (ctx->r7 != ctx->r2) {
        // 0x8009653C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8009656C;
    }
    // 0x8009653C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80096540: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80096544: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x80096548: jal         0x80000C98
    // 0x8009654C: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_36;
    // 0x8009654C: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_36:
    // 0x80096550: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096554: jal         0x800C06F8
    // 0x80096558: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_37;
    // 0x80096558: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_37:
    // 0x8009655C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80096560: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096564: b           L_80096958
    // 0x80096568: sw          $t5, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r13;
        goto L_80096958;
    // 0x80096568: sw          $t5, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r13;
L_8009656C:
    // 0x8009656C: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x80096570: b           L_80096958
    // 0x80096574: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
        goto L_80096958;
    // 0x80096574: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_80096578:
    // 0x80096578: beq         $t4, $zero, L_80096590
    if (ctx->r12 == 0) {
        // 0x8009657C: or          $t3, $v0, $zero
        ctx->r11 = ctx->r2 | 0;
            goto L_80096590;
    }
    // 0x8009657C: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80096580: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80096584: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x80096588: b           L_80096958
    // 0x8009658C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
        goto L_80096958;
    // 0x8009658C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_80096590:
    // 0x80096590: blez        $t2, L_800966FC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80096594: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800966FC;
    }
    // 0x80096594: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80096598: andi        $v1, $t2, 0x3
    ctx->r3 = ctx->r10 & 0X3;
    // 0x8009659C: beq         $v1, $zero, L_800965FC
    if (ctx->r3 == 0) {
        // 0x800965A0: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_800965FC;
    }
    // 0x800965A0: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800965A4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800965A8: addiu       $t7, $t7, 0x6A04
    ctx->r15 = ADD32(ctx->r15, 0X6A04);
    // 0x800965AC: addu        $a1, $zero, $t7
    ctx->r5 = ADD32(0, ctx->r15);
    // 0x800965B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800965B4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_800965B8:
    // 0x800965B8: lb          $v1, 0x0($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X0);
    // 0x800965BC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800965C0: blez        $v1, L_800965D8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800965C4: nop
    
            goto L_800965D8;
    }
    // 0x800965C4: nop

    // 0x800965C8: bne         $a2, $v0, L_800965D8
    if (ctx->r6 != ctx->r2) {
        // 0x800965CC: nop
    
            goto L_800965D8;
    }
    // 0x800965CC: nop

    // 0x800965D0: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x800965D4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800965D8:
    // 0x800965D8: bgez        $v1, L_800965F0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800965DC: nop
    
            goto L_800965F0;
    }
    // 0x800965DC: nop

    // 0x800965E0: bne         $a3, $v0, L_800965F0
    if (ctx->r7 != ctx->r2) {
        // 0x800965E4: nop
    
            goto L_800965F0;
    }
    // 0x800965E4: nop

    // 0x800965E8: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
    // 0x800965EC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800965F0:
    // 0x800965F0: bne         $t1, $a0, L_800965B8
    if (ctx->r9 != ctx->r4) {
        // 0x800965F4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800965B8;
    }
    // 0x800965F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800965F8: beq         $a0, $t2, L_800966FC
    if (ctx->r4 == ctx->r10) {
        // 0x800965FC: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800966FC;
    }
L_800965FC:
    // 0x800965FC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80096600: addiu       $t8, $t8, 0x6A04
    ctx->r24 = ADD32(ctx->r24, 0X6A04);
    // 0x80096604: addu        $a1, $a0, $t8
    ctx->r5 = ADD32(ctx->r4, ctx->r24);
    // 0x80096608: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x8009660C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80096610: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80096614:
    // 0x80096614: lb          $v1, 0x0($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X0);
    // 0x80096618: nop

    // 0x8009661C: blez        $v1, L_80096634
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80096620: nop
    
            goto L_80096634;
    }
    // 0x80096620: nop

    // 0x80096624: bne         $a2, $v0, L_80096634
    if (ctx->r6 != ctx->r2) {
        // 0x80096628: nop
    
            goto L_80096634;
    }
    // 0x80096628: nop

    // 0x8009662C: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x80096630: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80096634:
    // 0x80096634: bgez        $v1, L_8009664C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80096638: nop
    
            goto L_8009664C;
    }
    // 0x80096638: nop

    // 0x8009663C: bne         $a3, $v0, L_8009664C
    if (ctx->r7 != ctx->r2) {
        // 0x80096640: nop
    
            goto L_8009664C;
    }
    // 0x80096640: nop

    // 0x80096644: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
    // 0x80096648: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8009664C:
    // 0x8009664C: lb          $v1, 0x1($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1);
    // 0x80096650: nop

    // 0x80096654: blez        $v1, L_8009666C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80096658: nop
    
            goto L_8009666C;
    }
    // 0x80096658: nop

    // 0x8009665C: bne         $a2, $v0, L_8009666C
    if (ctx->r6 != ctx->r2) {
        // 0x80096660: nop
    
            goto L_8009666C;
    }
    // 0x80096660: nop

    // 0x80096664: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x80096668: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8009666C:
    // 0x8009666C: bgez        $v1, L_80096684
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80096670: nop
    
            goto L_80096684;
    }
    // 0x80096670: nop

    // 0x80096674: bne         $a3, $v0, L_80096684
    if (ctx->r7 != ctx->r2) {
        // 0x80096678: nop
    
            goto L_80096684;
    }
    // 0x80096678: nop

    // 0x8009667C: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
    // 0x80096680: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80096684:
    // 0x80096684: lb          $v1, 0x2($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X2);
    // 0x80096688: nop

    // 0x8009668C: blez        $v1, L_800966A4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80096690: nop
    
            goto L_800966A4;
    }
    // 0x80096690: nop

    // 0x80096694: bne         $a2, $v0, L_800966A4
    if (ctx->r6 != ctx->r2) {
        // 0x80096698: nop
    
            goto L_800966A4;
    }
    // 0x80096698: nop

    // 0x8009669C: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x800966A0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800966A4:
    // 0x800966A4: bgez        $v1, L_800966BC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800966A8: nop
    
            goto L_800966BC;
    }
    // 0x800966A8: nop

    // 0x800966AC: bne         $a3, $v0, L_800966BC
    if (ctx->r7 != ctx->r2) {
        // 0x800966B0: nop
    
            goto L_800966BC;
    }
    // 0x800966B0: nop

    // 0x800966B4: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
    // 0x800966B8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800966BC:
    // 0x800966BC: lb          $v1, 0x3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X3);
    // 0x800966C0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800966C4: blez        $v1, L_800966DC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800966C8: nop
    
            goto L_800966DC;
    }
    // 0x800966C8: nop

    // 0x800966CC: bne         $a2, $v0, L_800966DC
    if (ctx->r6 != ctx->r2) {
        // 0x800966D0: nop
    
            goto L_800966DC;
    }
    // 0x800966D0: nop

    // 0x800966D4: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x800966D8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800966DC:
    // 0x800966DC: bgez        $v1, L_800966F4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800966E0: nop
    
            goto L_800966F4;
    }
    // 0x800966E0: nop

    // 0x800966E4: bne         $a3, $v0, L_800966F4
    if (ctx->r7 != ctx->r2) {
        // 0x800966E8: nop
    
            goto L_800966F4;
    }
    // 0x800966E8: nop

    // 0x800966EC: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
    // 0x800966F0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800966F4:
    // 0x800966F4: bne         $a1, $t1, L_80096614
    if (ctx->r5 != ctx->r9) {
        // 0x800966F8: nop
    
            goto L_80096614;
    }
    // 0x800966F8: nop

L_800966FC:
    // 0x800966FC: beq         $t3, $v0, L_80096958
    if (ctx->r11 == ctx->r2) {
        // 0x80096700: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80096958;
    }
    // 0x80096700: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80096704: b           L_80096958
    // 0x80096708: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
        goto L_80096958;
    // 0x80096708: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
L_8009670C:
    // 0x8009670C: beq         $t9, $zero, L_80096794
    if (ctx->r25 == 0) {
        // 0x80096710: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_80096794;
    }
    // 0x80096710: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80096714: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80096718: addiu       $a2, $a2, 0x7028
    ctx->r6 = ADD32(ctx->r6, 0X7028);
    // 0x8009671C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80096720: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80096724: lw          $v0, -0x5E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E0);
    // 0x80096728: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009672C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80096730: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80096734: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x80096738: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x8009673C: lw          $v1, 0x71B0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X71B0);
    // 0x80096740: lw          $t8, 0x6C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X6C);
    // 0x80096744: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80096748: bne         $v1, $t8, L_80096758
    if (ctx->r3 != ctx->r24) {
        // 0x8009674C: nop
    
            goto L_80096758;
    }
    // 0x8009674C: nop

    // 0x80096750: b           L_80096958
    // 0x80096754: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
        goto L_80096958;
    // 0x80096754: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
L_80096758:
    // 0x80096758: lw          $t5, 0x70($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X70);
    // 0x8009675C: nop

    // 0x80096760: bne         $v1, $t5, L_80096770
    if (ctx->r3 != ctx->r13) {
        // 0x80096764: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_80096770;
    }
    // 0x80096764: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80096768: b           L_80096958
    // 0x8009676C: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
        goto L_80096958;
    // 0x8009676C: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
L_80096770:
    // 0x80096770: jal         0x80000C98
    // 0x80096774: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_38;
    // 0x80096774: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_38:
    // 0x80096778: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009677C: jal         0x800C06F8
    // 0x80096780: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_39;
    // 0x80096780: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_39:
    // 0x80096784: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80096788: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009678C: b           L_80096958
    // 0x80096790: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
        goto L_80096958;
    // 0x80096790: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
L_80096794:
    // 0x80096794: addiu       $a2, $a2, 0x7028
    ctx->r6 = ADD32(ctx->r6, 0X7028);
    // 0x80096798: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8009679C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800967A0: blez        $t2, L_8009694C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800967A4: or          $t3, $v0, $zero
        ctx->r11 = ctx->r2 | 0;
            goto L_8009694C;
    }
    // 0x800967A4: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800967A8: andi        $v1, $t2, 0x3
    ctx->r3 = ctx->r10 & 0X3;
    // 0x800967AC: beq         $v1, $zero, L_80096814
    if (ctx->r3 == 0) {
        // 0x800967B0: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80096814;
    }
    // 0x800967B0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800967B4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800967B8: addiu       $t4, $t4, 0x6A04
    ctx->r12 = ADD32(ctx->r12, 0X6A04);
    // 0x800967BC: addu        $a1, $zero, $t4
    ctx->r5 = ADD32(0, ctx->r12);
L_800967C0:
    // 0x800967C0: lb          $v1, 0x0($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X0);
    // 0x800967C4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800967C8: bgez        $v1, L_800967F0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800967CC: nop
    
            goto L_800967F0;
    }
    // 0x800967CC: nop

    // 0x800967D0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800967D4: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x800967D8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800967DC: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800967E0: beq         $at, $zero, L_800967F0
    if (ctx->r1 == 0) {
        // 0x800967E4: nop
    
            goto L_800967F0;
    }
    // 0x800967E4: nop

    // 0x800967E8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800967EC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800967F0:
    // 0x800967F0: blez        $v1, L_80096808
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800967F4: nop
    
            goto L_80096808;
    }
    // 0x800967F4: nop

    // 0x800967F8: blez        $v0, L_80096808
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800967FC: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_80096808;
    }
    // 0x800967FC: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80096800: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80096804: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80096808:
    // 0x80096808: bne         $a3, $a0, L_800967C0
    if (ctx->r7 != ctx->r4) {
        // 0x8009680C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800967C0;
    }
    // 0x8009680C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80096810: beq         $a0, $t2, L_8009694C
    if (ctx->r4 == ctx->r10) {
        // 0x80096814: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8009694C;
    }
L_80096814:
    // 0x80096814: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80096818: addiu       $t9, $t9, 0x6A04
    ctx->r25 = ADD32(ctx->r25, 0X6A04);
    // 0x8009681C: addu        $a1, $a0, $t9
    ctx->r5 = ADD32(ctx->r4, ctx->r25);
    // 0x80096820: addu        $a3, $t2, $t9
    ctx->r7 = ADD32(ctx->r10, ctx->r25);
L_80096824:
    // 0x80096824: lb          $v1, 0x0($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X0);
    // 0x80096828: nop

    // 0x8009682C: bgez        $v1, L_80096854
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80096830: nop
    
            goto L_80096854;
    }
    // 0x80096830: nop

    // 0x80096834: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80096838: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8009683C: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x80096840: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80096844: beq         $at, $zero, L_80096854
    if (ctx->r1 == 0) {
        // 0x80096848: nop
    
            goto L_80096854;
    }
    // 0x80096848: nop

    // 0x8009684C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80096850: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80096854:
    // 0x80096854: blez        $v1, L_8009686C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80096858: nop
    
            goto L_8009686C;
    }
    // 0x80096858: nop

    // 0x8009685C: blez        $v0, L_8009686C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80096860: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8009686C;
    }
    // 0x80096860: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80096864: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80096868: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8009686C:
    // 0x8009686C: lb          $v1, 0x1($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1);
    // 0x80096870: nop

    // 0x80096874: bgez        $v1, L_8009689C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80096878: nop
    
            goto L_8009689C;
    }
    // 0x80096878: nop

    // 0x8009687C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80096880: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x80096884: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x80096888: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8009688C: beq         $at, $zero, L_8009689C
    if (ctx->r1 == 0) {
        // 0x80096890: nop
    
            goto L_8009689C;
    }
    // 0x80096890: nop

    // 0x80096894: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x80096898: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_8009689C:
    // 0x8009689C: blez        $v1, L_800968B4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800968A0: nop
    
            goto L_800968B4;
    }
    // 0x800968A0: nop

    // 0x800968A4: blez        $v0, L_800968B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800968A8: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_800968B4;
    }
    // 0x800968A8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800968AC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800968B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_800968B4:
    // 0x800968B4: lb          $v1, 0x2($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X2);
    // 0x800968B8: nop

    // 0x800968BC: bgez        $v1, L_800968E4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800968C0: nop
    
            goto L_800968E4;
    }
    // 0x800968C0: nop

    // 0x800968C4: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800968C8: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x800968CC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800968D0: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800968D4: beq         $at, $zero, L_800968E4
    if (ctx->r1 == 0) {
        // 0x800968D8: nop
    
            goto L_800968E4;
    }
    // 0x800968D8: nop

    // 0x800968DC: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800968E0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800968E4:
    // 0x800968E4: blez        $v1, L_800968FC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800968E8: nop
    
            goto L_800968FC;
    }
    // 0x800968E8: nop

    // 0x800968EC: blez        $v0, L_800968FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800968F0: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800968FC;
    }
    // 0x800968F0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800968F4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800968F8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800968FC:
    // 0x800968FC: lb          $v1, 0x3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X3);
    // 0x80096900: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80096904: bgez        $v1, L_8009692C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80096908: nop
    
            goto L_8009692C;
    }
    // 0x80096908: nop

    // 0x8009690C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80096910: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80096914: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x80096918: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8009691C: beq         $at, $zero, L_8009692C
    if (ctx->r1 == 0) {
        // 0x80096920: nop
    
            goto L_8009692C;
    }
    // 0x80096920: nop

    // 0x80096924: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80096928: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8009692C:
    // 0x8009692C: blez        $v1, L_80096944
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80096930: nop
    
            goto L_80096944;
    }
    // 0x80096930: nop

    // 0x80096934: blez        $v0, L_80096944
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80096938: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80096944;
    }
    // 0x80096938: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8009693C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80096940: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80096944:
    // 0x80096944: bne         $a1, $a3, L_80096824
    if (ctx->r5 != ctx->r7) {
        // 0x80096948: nop
    
            goto L_80096824;
    }
    // 0x80096948: nop

L_8009694C:
    // 0x8009694C: beq         $t3, $v0, L_80096958
    if (ctx->r11 == ctx->r2) {
        // 0x80096950: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80096958;
    }
    // 0x80096950: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80096954: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
L_80096958:
    // 0x80096958: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8009695C: nop

    // 0x80096960: beq         $t9, $zero, L_80096978
    if (ctx->r25 == 0) {
        // 0x80096964: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_80096978;
    }
    // 0x80096964: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80096968: jal         0x80001D04
    // 0x8009696C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_40;
    // 0x8009696C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_40:
    // 0x80096970: b           L_80096C18
    // 0x80096974: nop

        goto L_80096C18;
    // 0x80096974: nop

L_80096978:
    // 0x80096978: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8009697C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80096980: beq         $t4, $zero, L_80096998
    if (ctx->r12 == 0) {
        // 0x80096984: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80096998;
    }
    // 0x80096984: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80096988: jal         0x80001D04
    // 0x8009698C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_41;
    // 0x8009698C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_41:
    // 0x80096990: b           L_80096C18
    // 0x80096994: nop

        goto L_80096C18;
    // 0x80096994: nop

L_80096998:
    // 0x80096998: beq         $t6, $zero, L_80096C18
    if (ctx->r14 == 0) {
        // 0x8009699C: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80096C18;
    }
    // 0x8009699C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800969A0: jal         0x80001D04
    // 0x800969A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_42;
    // 0x800969A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_42:
    // 0x800969A8: b           L_80096C18
    // 0x800969AC: nop

        goto L_80096C18;
    // 0x800969AC: nop

L_800969B0:
    // 0x800969B0: andi        $t7, $v1, 0x9000
    ctx->r15 = ctx->r3 & 0X9000;
    // 0x800969B4: beq         $t7, $zero, L_80096C18
    if (ctx->r15 == 0) {
        // 0x800969B8: nop
    
            goto L_80096C18;
    }
    // 0x800969B8: nop

    // 0x800969BC: jal         0x80000C98
    // 0x800969C0: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_43;
    // 0x800969C0: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_43:
    // 0x800969C4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800969C8: jal         0x800C06F8
    // 0x800969CC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_44;
    // 0x800969CC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_44:
    // 0x800969D0: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x800969D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800969D8: b           L_80096C18
    // 0x800969DC: sw          $t8, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r24;
        goto L_80096C18;
    // 0x800969DC: sw          $t8, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r24;
L_800969E0:
    // 0x800969E0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800969E4: lw          $t5, -0x604($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X604);
    // 0x800969E8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800969EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800969F0: addu        $t4, $t5, $t9
    ctx->r12 = ADD32(ctx->r13, ctx->r25);
    // 0x800969F4: sw          $t4, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r12;
    // 0x800969F8: slti        $at, $t4, 0x1F
    ctx->r1 = SIGNED(ctx->r12) < 0X1F ? 1 : 0;
    // 0x800969FC: bne         $at, $zero, L_80096C18
    if (ctx->r1 != 0) {
        // 0x80096A00: nop
    
            goto L_80096C18;
    }
    // 0x80096A00: nop

    // 0x80096A04: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80096A08: nop

    // 0x80096A0C: lb          $t6, 0x117($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X117);
    // 0x80096A10: nop

    // 0x80096A14: beq         $t6, $zero, L_80096A60
    if (ctx->r14 == 0) {
        // 0x80096A18: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80096A60;
    }
    // 0x80096A18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80096A1C: lb          $v0, 0x58($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X58);
    // 0x80096A20: nop

    // 0x80096A24: andi        $t7, $v0, 0x7F
    ctx->r15 = ctx->r2 & 0X7F;
    // 0x80096A28: beq         $t7, $zero, L_80096A4C
    if (ctx->r15 == 0) {
        // 0x80096A2C: andi        $t5, $v0, 0x80
        ctx->r13 = ctx->r2 & 0X80;
            goto L_80096A4C;
    }
    // 0x80096A2C: andi        $t5, $v0, 0x80
    ctx->r13 = ctx->r2 & 0X80;
    // 0x80096A30: jal         0x8006EE04
    // 0x80096A34: nop

    mark_to_write_flap_times(rdram, ctx);
        goto after_45;
    // 0x80096A34: nop

    after_45:
    // 0x80096A38: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80096A3C: nop

    // 0x80096A40: lb          $v0, 0x58($t8)
    ctx->r2 = MEM_B(ctx->r24, 0X58);
    // 0x80096A44: nop

    // 0x80096A48: andi        $t5, $v0, 0x80
    ctx->r13 = ctx->r2 & 0X80;
L_80096A4C:
    // 0x80096A4C: beq         $t5, $zero, L_80096A60
    if (ctx->r13 == 0) {
        // 0x80096A50: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80096A60;
    }
    // 0x80096A50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80096A54: jal         0x8006EE20
    // 0x80096A58: nop

    mark_to_write_course_times(rdram, ctx);
        goto after_46;
    // 0x80096A58: nop

    after_46:
    // 0x80096A5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80096A60:
    // 0x80096A60: jal         0x80066AD4
    // 0x80096A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camDisableUserView(rdram, ctx);
        goto after_47;
    // 0x80096A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_47:
    // 0x80096A68: jal         0x80096C94
    // 0x80096A6C: nop

    postrace_free(rdram, ctx);
        goto after_48;
    // 0x80096A6C: nop

    after_48:
    // 0x80096A70: jal         0x800C5B80
    // 0x80096A74: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_close(rdram, ctx);
        goto after_49;
    // 0x80096A74: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_49:
    // 0x80096A78: jal         0x800C59F4
    // 0x80096A7C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_50;
    // 0x80096A7C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_50:
    // 0x80096A80: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80096A84: lb          $v0, 0x71E8($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X71E8);
    // 0x80096A88: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80096A8C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80096A90: bne         $at, $zero, L_80096B04
    if (ctx->r1 != 0) {
        // 0x80096A94: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80096B04;
    }
    // 0x80096A94: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80096A98: bne         $v0, $at, L_80096AD0
    if (ctx->r2 != ctx->r1) {
        // 0x80096A9C: nop
    
            goto L_80096AD0;
    }
    // 0x80096A9C: nop

    // 0x80096AA0: jal         0x8001E2D0
    // 0x80096AA4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    get_misc_asset(rdram, ctx);
        goto after_51;
    // 0x80096AA4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_51:
    // 0x80096AA8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80096AAC: lb          $a1, 0x71E8($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X71E8);
    // 0x80096AB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80096AB4: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    // 0x80096AB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80096ABC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80096AC0: jal         0x8009B114
    // 0x80096AC4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    cinematic_start(rdram, ctx);
        goto after_52;
    // 0x80096AC4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_52:
    // 0x80096AC8: b           L_80096AFC
    // 0x80096ACC: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
        goto L_80096AFC;
    // 0x80096ACC: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
L_80096AD0:
    // 0x80096AD0: jal         0x8001E2D0
    // 0x80096AD4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    get_misc_asset(rdram, ctx);
        goto after_53;
    // 0x80096AD4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_53:
    // 0x80096AD8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80096ADC: lb          $a1, 0x71E8($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X71E8);
    // 0x80096AE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80096AE4: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x80096AE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80096AEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80096AF0: jal         0x8009B114
    // 0x80096AF4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    cinematic_start(rdram, ctx);
        goto after_54;
    // 0x80096AF4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_54:
    // 0x80096AF8: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
L_80096AFC:
    // 0x80096AFC: b           L_80096C18
    // 0x80096B00: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_80096C18;
    // 0x80096B00: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_80096B04:
    // 0x80096B04: lw          $t4, 0x1568($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1568);
    // 0x80096B08: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80096B0C: beq         $t4, $zero, L_80096B1C
    if (ctx->r12 == 0) {
        // 0x80096B10: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_80096B1C;
    }
    // 0x80096B10: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80096B14: b           L_80096C18
    // 0x80096B18: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
        goto L_80096C18;
    // 0x80096B18: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_80096B1C:
    // 0x80096B1C: lw          $t7, -0x5C4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5C4);
    // 0x80096B20: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80096B24: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80096B28: bne         $at, $zero, L_80096B3C
    if (ctx->r1 != 0) {
        // 0x80096B2C: addiu       $a2, $a2, 0x7028
        ctx->r6 = ADD32(ctx->r6, 0X7028);
            goto L_80096B3C;
    }
    // 0x80096B2C: addiu       $a2, $a2, 0x7028
    ctx->r6 = ADD32(ctx->r6, 0X7028);
    // 0x80096B30: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80096B34: b           L_80096C18
    // 0x80096B38: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
        goto L_80096C18;
    // 0x80096B38: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_80096B3C:
    // 0x80096B3C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80096B40: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80096B44: lw          $v0, -0x5E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E0);
    // 0x80096B48: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80096B4C: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x80096B50: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x80096B54: lw          $v1, 0x71B0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X71B0);
    // 0x80096B58: lw          $t4, 0x5C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X5C);
    // 0x80096B5C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80096B60: bne         $v1, $t4, L_80096BCC
    if (ctx->r3 != ctx->r12) {
        // 0x80096B64: nop
    
            goto L_80096BCC;
    }
    // 0x80096B64: nop

    // 0x80096B68: lw          $t6, -0x5C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C8);
    // 0x80096B6C: nop

    // 0x80096B70: bne         $t6, $zero, L_80096BC4
    if (ctx->r14 != 0) {
        // 0x80096B74: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_80096BC4;
    }
    // 0x80096B74: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80096B78: jal         0x8006ED54
    // 0x80096B7C: nop

    get_ingame_map_id(rdram, ctx);
        goto after_55;
    // 0x80096B7C: nop

    after_55:
    // 0x80096B80: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80096B84: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80096B88: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80096B8C: lh          $t8, 0xCD8($t8)
    ctx->r24 = MEM_H(ctx->r24, 0XCD8);
    // 0x80096B90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80096B94: beq         $t8, $at, L_80096BC4
    if (ctx->r24 == ctx->r1) {
        // 0x80096B98: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_80096BC4;
    }
    // 0x80096B98: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80096B9C: jal         0x8006ED54
    // 0x80096BA0: nop

    get_ingame_map_id(rdram, ctx);
        goto after_56;
    // 0x80096BA0: nop

    after_56:
    // 0x80096BA4: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x80096BA8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096BAC: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80096BB0: lhu         $a0, 0xCD8($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XCD8);
    // 0x80096BB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80096BB8: jal         0x80000FDC
    // 0x80096BBC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_57;
    // 0x80096BBC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_57:
    // 0x80096BC0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
L_80096BC4:
    // 0x80096BC4: b           L_80096C18
    // 0x80096BC8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_80096C18;
    // 0x80096BC8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_80096BCC:
    // 0x80096BCC: lw          $t4, 0x60($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X60);
    // 0x80096BD0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80096BD4: bne         $v1, $t4, L_80096BE4
    if (ctx->r3 != ctx->r12) {
        // 0x80096BD8: nop
    
            goto L_80096BE4;
    }
    // 0x80096BD8: nop

    // 0x80096BDC: b           L_80096C18
    // 0x80096BE0: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
        goto L_80096C18;
    // 0x80096BE0: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_80096BE4:
    // 0x80096BE4: lw          $t7, 0x68($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X68);
    // 0x80096BE8: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80096BEC: bne         $v1, $t7, L_80096BFC
    if (ctx->r3 != ctx->r15) {
        // 0x80096BF0: nop
    
            goto L_80096BFC;
    }
    // 0x80096BF0: nop

    // 0x80096BF4: b           L_80096C18
    // 0x80096BF8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
        goto L_80096C18;
    // 0x80096BF8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_80096BFC:
    // 0x80096BFC: lw          $t5, 0x64($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X64);
    // 0x80096C00: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80096C04: bne         $v1, $t5, L_80096C14
    if (ctx->r3 != ctx->r13) {
        // 0x80096C08: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_80096C14;
    }
    // 0x80096C08: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80096C0C: b           L_80096C18
    // 0x80096C10: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_80096C18;
    // 0x80096C10: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_80096C14:
    // 0x80096C14: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80096C18:
    // 0x80096C18: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80096C1C: lw          $v0, 0x6964($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6964);
    // 0x80096C20: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80096C24: blez        $v0, L_80096C54
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80096C28: nop
    
            goto L_80096C54;
    }
    // 0x80096C28: nop

    // 0x80096C2C: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80096C30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096C34: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x80096C38: sw          $t7, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = ctx->r15;
    // 0x80096C3C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80096C40: lw          $t8, 0x6964($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6964);
    // 0x80096C44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096C48: bgez        $t8, L_80096C54
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80096C4C: nop
    
            goto L_80096C54;
    }
    // 0x80096C4C: nop

    // 0x80096C50: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_80096C54:
    // 0x80096C54: lw          $t5, 0x693C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X693C);
    // 0x80096C58: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80096C5C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80096C60: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x80096C64: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80096C68: lw          $t4, 0x6944($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6944);
    // 0x80096C6C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80096C70: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x80096C74: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80096C78: lw          $t7, 0x694C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X694C);
    // 0x80096C7C: nop

    // 0x80096C80: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80096C84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80096C88: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80096C8C: jr          $ra
    // 0x80096C90: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80096C90: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void sndp_deallocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004520: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80004524: addiu       $v0, $v0, -0x33E0
    ctx->r2 = ADD32(ctx->r2, -0X33E0);
    // 0x80004528: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8000452C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004530: bne         $a0, $t6, L_80004544
    if (ctx->r4 != ctx->r14) {
        // 0x80004534: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80004544;
    }
    // 0x80004534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004538: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8000453C: nop

    // 0x80004540: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80004544:
    // 0x80004544: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80004548: nop

    // 0x8000454C: bne         $a0, $t8, L_80004560
    if (ctx->r4 != ctx->r24) {
        // 0x80004550: nop
    
            goto L_80004560;
    }
    // 0x80004550: nop

    // 0x80004554: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80004558: nop

    // 0x8000455C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80004560:
    // 0x80004560: jal         0x800C8CC0
    // 0x80004564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x80004564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80004568: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000456C: addiu       $v0, $v0, -0x33E0
    ctx->r2 = ADD32(ctx->r2, -0X33E0);
    // 0x80004570: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80004574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80004578: beq         $v1, $zero, L_8000459C
    if (ctx->r3 == 0) {
        // 0x8000457C: nop
    
            goto L_8000459C;
    }
    // 0x8000457C: nop

    // 0x80004580: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80004584: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80004588: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x8000458C: nop

    // 0x80004590: sw          $a0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r4;
    // 0x80004594: b           L_800045A8
    // 0x80004598: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
        goto L_800045A8;
    // 0x80004598: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
L_8000459C:
    // 0x8000459C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800045A0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800045A4: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
L_800045A8:
    // 0x800045A8: lbu         $t1, 0x3E($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X3E);
    // 0x800045AC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800045B0: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x800045B4: beq         $t2, $zero, L_800045CC
    if (ctx->r10 == 0) {
        // 0x800045B8: addiu       $v0, $v0, -0x33CC
        ctx->r2 = ADD32(ctx->r2, -0X33CC);
            goto L_800045CC;
    }
    // 0x800045B8: addiu       $v0, $v0, -0x33CC
    ctx->r2 = ADD32(ctx->r2, -0X33CC);
    // 0x800045BC: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800045C0: nop

    // 0x800045C4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800045C8: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
L_800045CC:
    // 0x800045CC: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x800045D0: sb          $zero, 0x3F($a0)
    MEM_B(0X3F, ctx->r4) = 0;
    // 0x800045D4: beq         $v0, $zero, L_800045F8
    if (ctx->r2 == 0) {
        // 0x800045D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800045F8;
    }
    // 0x800045D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800045DC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800045E0: nop

    // 0x800045E4: bne         $a0, $t5, L_800045F0
    if (ctx->r4 != ctx->r13) {
        // 0x800045E8: nop
    
            goto L_800045F0;
    }
    // 0x800045E8: nop

    // 0x800045EC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800045F0:
    // 0x800045F0: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x800045F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800045F8:
    // 0x800045F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800045FC: jr          $ra
    // 0x80004600: nop

    return;
    // 0x80004600: nop

;}
RECOMP_FUNC void render_dialogue_box(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C60B8: addiu       $sp, $sp, -0x180
    ctx->r29 = ADD32(ctx->r29, -0X180);
    // 0x800C60BC: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x800C60C0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C60C4: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C60C8: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x800C60CC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800C60D0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C60D4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C60D8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800C60DC: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800C60E0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800C60E4: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C60E8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800C60EC: sw          $a2, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r6;
    // 0x800C60F0: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800C60F4: lbu         $t8, 0x13($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X13);
    // 0x800C60F8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800C60FC: beq         $t8, $zero, L_800C6354
    if (ctx->r24 == 0) {
        // 0x800C6100: or          $s3, $a0, $zero
        ctx->r19 = ctx->r4 | 0;
            goto L_800C6354;
    }
    // 0x800C6100: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800C6104: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C6108: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800C610C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800C6110: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C6114: addiu       $t3, $t3, 0x3C20
    ctx->r11 = ADD32(ctx->r11, 0X3C20);
    // 0x800C6118: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x800C611C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800C6120: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800C6124: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C6128: lui         $t5, 0x702
    ctx->r13 = S32(0X702 << 16);
    // 0x800C612C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800C6130: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x800C6134: lui         $t6, 0xE
    ctx->r14 = S32(0XE << 16);
    // 0x800C6138: addiu       $t6, $t6, 0x3C68
    ctx->r14 = ADD32(ctx->r14, 0X3C68);
    // 0x800C613C: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800C6140: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800C6144: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800C6148: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800C614C: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x800C6150: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800C6154: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x800C6158: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C615C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800C6160: lh          $t1, 0x4($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X4);
    // 0x800C6164: lh          $t0, 0x8($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X8);
    // 0x800C6168: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C616C: subu        $t9, $t0, $t1
    ctx->r25 = SUB32(ctx->r8, ctx->r9);
    // 0x800C6170: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x800C6174: bne         $at, $zero, L_800C6198
    if (ctx->r1 != 0) {
        // 0x800C6178: addiu       $a1, $t1, -0x2
        ctx->r5 = ADD32(ctx->r9, -0X2);
            goto L_800C6198;
    }
    // 0x800C6178: addiu       $a1, $t1, -0x2
    ctx->r5 = ADD32(ctx->r9, -0X2);
    // 0x800C617C: lh          $v0, 0xA($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XA);
    // 0x800C6180: lh          $s0, 0x6($s1)
    ctx->r16 = MEM_H(ctx->r17, 0X6);
    // 0x800C6184: addiu       $a3, $t1, 0x2
    ctx->r7 = ADD32(ctx->r9, 0X2);
    // 0x800C6188: subu        $t2, $v0, $s0
    ctx->r10 = SUB32(ctx->r2, ctx->r16);
    // 0x800C618C: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x800C6190: beq         $at, $zero, L_800C61BC
    if (ctx->r1 == 0) {
        // 0x800C6194: addiu       $a2, $s0, 0x2
        ctx->r6 = ADD32(ctx->r16, 0X2);
            goto L_800C61BC;
    }
    // 0x800C6194: addiu       $a2, $s0, 0x2
    ctx->r6 = ADD32(ctx->r16, 0X2);
L_800C6198:
    // 0x800C6198: lh          $t3, 0xA($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XA);
    // 0x800C619C: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    // 0x800C61A0: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x800C61A4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800C61A8: addiu       $a3, $t0, 0x2
    ctx->r7 = ADD32(ctx->r8, 0X2);
    // 0x800C61AC: jal         0x800C6000
    // 0x800C61B0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    render_fill_rectangle(rdram, ctx);
        goto after_0;
    // 0x800C61B0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    after_0:
    // 0x800C61B4: b           L_800C624C
    // 0x800C61B8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
        goto L_800C624C;
    // 0x800C61B8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_800C61BC:
    // 0x800C61BC: addiu       $t5, $v0, -0x2
    ctx->r13 = ADD32(ctx->r2, -0X2);
    // 0x800C61C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800C61C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C61C8: jal         0x800C6000
    // 0x800C61CC: addiu       $a1, $t1, -0x2
    ctx->r5 = ADD32(ctx->r9, -0X2);
    render_fill_rectangle(rdram, ctx);
        goto after_1;
    // 0x800C61CC: addiu       $a1, $t1, -0x2
    ctx->r5 = ADD32(ctx->r9, -0X2);
    after_1:
    // 0x800C61D0: lh          $s0, 0x6($s1)
    ctx->r16 = MEM_H(ctx->r17, 0X6);
    // 0x800C61D4: lh          $a1, 0x4($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X4);
    // 0x800C61D8: lh          $a3, 0x8($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X8);
    // 0x800C61DC: addiu       $t6, $s0, 0x2
    ctx->r14 = ADD32(ctx->r16, 0X2);
    // 0x800C61E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C61E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C61E8: addiu       $a2, $s0, -0x2
    ctx->r6 = ADD32(ctx->r16, -0X2);
    // 0x800C61EC: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x800C61F0: jal         0x800C6000
    // 0x800C61F4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    render_fill_rectangle(rdram, ctx);
        goto after_2;
    // 0x800C61F4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_2:
    // 0x800C61F8: lh          $t0, 0x8($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X8);
    // 0x800C61FC: lh          $t7, 0xA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XA);
    // 0x800C6200: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    // 0x800C6204: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x800C6208: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C620C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C6210: addiu       $a1, $t0, -0x2
    ctx->r5 = ADD32(ctx->r8, -0X2);
    // 0x800C6214: addiu       $a3, $t0, 0x2
    ctx->r7 = ADD32(ctx->r8, 0X2);
    // 0x800C6218: jal         0x800C6000
    // 0x800C621C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    render_fill_rectangle(rdram, ctx);
        goto after_3;
    // 0x800C621C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    after_3:
    // 0x800C6220: lh          $v0, 0xA($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XA);
    // 0x800C6224: lh          $a1, 0x4($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X4);
    // 0x800C6228: lh          $a3, 0x8($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X8);
    // 0x800C622C: addiu       $t9, $v0, 0x2
    ctx->r25 = ADD32(ctx->r2, 0X2);
    // 0x800C6230: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800C6234: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C6238: addiu       $a2, $v0, -0x2
    ctx->r6 = ADD32(ctx->r2, -0X2);
    // 0x800C623C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x800C6240: jal         0x800C6000
    // 0x800C6244: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    render_fill_rectangle(rdram, ctx);
        goto after_4;
    // 0x800C6244: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_4:
    // 0x800C6248: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_800C624C:
    // 0x800C624C: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800C6250: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800C6254: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x800C6258: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C625C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800C6260: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800C6264: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x800C6268: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800C626C: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x800C6270: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800C6274: lbu         $t7, 0x10($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X10);
    // 0x800C6278: lbu         $t2, 0x11($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X11);
    // 0x800C627C: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800C6280: lbu         $t6, 0x12($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X12);
    // 0x800C6284: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x800C6288: or          $t4, $t8, $t3
    ctx->r12 = ctx->r24 | ctx->r11;
    // 0x800C628C: lbu         $t8, 0x13($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X13);
    // 0x800C6290: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800C6294: or          $t9, $t4, $t7
    ctx->r25 = ctx->r12 | ctx->r15;
    // 0x800C6298: or          $t3, $t9, $t8
    ctx->r11 = ctx->r25 | ctx->r24;
    // 0x800C629C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800C62A0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800C62A4: lb          $t5, 0x3CA0($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X3CA0);
    // 0x800C62A8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C62AC: bltz        $t5, L_800C633C
    if (SIGNED(ctx->r13) < 0) {
        // 0x800C62B0: addiu       $s0, $t6, 0x3CA0
        ctx->r16 = ADD32(ctx->r14, 0X3CA0);
            goto L_800C633C;
    }
    // 0x800C62B0: addiu       $s0, $t6, 0x3CA0
    ctx->r16 = ADD32(ctx->r14, 0X3CA0);
    // 0x800C62B4: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x800C62B8: nop

L_800C62BC:
    // 0x800C62BC: lh          $t4, 0x4($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X4);
    // 0x800C62C0: lb          $t7, 0x1($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1);
    // 0x800C62C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C62C8: beq         $t7, $zero, L_800C62E0
    if (ctx->r15 == 0) {
        // 0x800C62CC: addu        $a1, $v0, $t4
        ctx->r5 = ADD32(ctx->r2, ctx->r12);
            goto L_800C62E0;
    }
    // 0x800C62CC: addu        $a1, $v0, $t4
    ctx->r5 = ADD32(ctx->r2, ctx->r12);
    // 0x800C62D0: lb          $t2, 0x2($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X2);
    // 0x800C62D4: lh          $t9, 0xA($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XA);
    // 0x800C62D8: b           L_800C62F0
    // 0x800C62DC: addu        $a2, $t2, $t9
    ctx->r6 = ADD32(ctx->r10, ctx->r25);
        goto L_800C62F0;
    // 0x800C62DC: addu        $a2, $t2, $t9
    ctx->r6 = ADD32(ctx->r10, ctx->r25);
L_800C62E0:
    // 0x800C62E0: lb          $t8, 0x2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X2);
    // 0x800C62E4: lh          $t3, 0x6($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X6);
    // 0x800C62E8: nop

    // 0x800C62EC: addu        $a2, $t8, $t3
    ctx->r6 = ADD32(ctx->r24, ctx->r11);
L_800C62F0:
    // 0x800C62F0: lh          $t5, 0x8($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X8);
    // 0x800C62F4: lb          $t6, 0x3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X3);
    // 0x800C62F8: subu        $a3, $t5, $v0
    ctx->r7 = SUB32(ctx->r13, ctx->r2);
    // 0x800C62FC: beq         $t6, $zero, L_800C6314
    if (ctx->r14 == 0) {
        // 0x800C6300: nop
    
            goto L_800C6314;
    }
    // 0x800C6300: nop

    // 0x800C6304: lb          $t4, 0x4($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X4);
    // 0x800C6308: lh          $t7, 0xA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XA);
    // 0x800C630C: b           L_800C6324
    // 0x800C6310: addu        $v0, $t4, $t7
    ctx->r2 = ADD32(ctx->r12, ctx->r15);
        goto L_800C6324;
    // 0x800C6310: addu        $v0, $t4, $t7
    ctx->r2 = ADD32(ctx->r12, ctx->r15);
L_800C6314:
    // 0x800C6314: lb          $t2, 0x4($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X4);
    // 0x800C6318: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x800C631C: nop

    // 0x800C6320: addu        $v0, $t2, $t9
    ctx->r2 = ADD32(ctx->r10, ctx->r25);
L_800C6324:
    // 0x800C6324: jal         0x800C6000
    // 0x800C6328: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    render_fill_rectangle(rdram, ctx);
        goto after_5;
    // 0x800C6328: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
    // 0x800C632C: lb          $v0, 0x5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5);
    // 0x800C6330: addiu       $s0, $s0, 0x5
    ctx->r16 = ADD32(ctx->r16, 0X5);
    // 0x800C6334: bgez        $v0, L_800C62BC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800C6338: nop
    
            goto L_800C62BC;
    }
    // 0x800C6338: nop

L_800C633C:
    // 0x800C633C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800C6340: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800C6344: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800C6348: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800C634C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C6350: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_800C6354:
    // 0x800C6354: beq         $s2, $zero, L_800C63AC
    if (ctx->r18 == 0) {
        // 0x800C6358: nop
    
            goto L_800C63AC;
    }
    // 0x800C6358: nop

    // 0x800C635C: lw          $t5, 0x188($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X188);
    // 0x800C6360: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800C6364: beq         $t5, $zero, L_800C63AC
    if (ctx->r13 == 0) {
        // 0x800C6368: addiu       $s0, $s0, 0x3C78
        ctx->r16 = ADD32(ctx->r16, 0X3C78);
            goto L_800C63AC;
    }
    // 0x800C6368: addiu       $s0, $s0, 0x3C78
    ctx->r16 = ADD32(ctx->r16, 0X3C78);
    // 0x800C636C: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
    // 0x800C6370: nop

    // 0x800C6374: bne         $t6, $zero, L_800C6390
    if (ctx->r14 != 0) {
        // 0x800C6378: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_800C6390;
    }
    // 0x800C6378: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800C637C: jal         0x8009EEE4
    // 0x800C6380: nop

    dialogue_open_stub(rdram, ctx);
        goto after_6;
    // 0x800C6380: nop

    after_6:
    // 0x800C6384: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800C6388: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800C638C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_800C6390:
    // 0x800C6390: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C6394: lw          $a3, 0x188($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X188);
    // 0x800C6398: sb          $t7, -0x524C($at)
    MEM_B(-0X524C, ctx->r1) = ctx->r15;
    // 0x800C639C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C63A0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800C63A4: jal         0x8009EEF4
    // 0x800C63A8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    dialogue_ortho(rdram, ctx);
        goto after_7;
    // 0x800C63A8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_7:
L_800C63AC:
    // 0x800C63AC: lw          $s0, 0x24($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X24);
    // 0x800C63B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C63B4: beq         $s0, $zero, L_800C64A0
    if (ctx->r16 == 0) {
        // 0x800C63B8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800C64A0;
    }
    // 0x800C63B8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C63BC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800C63C0: addiu       $s2, $sp, 0x6C
    ctx->r18 = ADD32(ctx->r29, 0X6C);
L_800C63C4:
    // 0x800C63C4: lh          $t2, 0x8($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8);
    // 0x800C63C8: lh          $t9, 0xC($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XC);
    // 0x800C63CC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800C63D0: addu        $t8, $t2, $t9
    ctx->r24 = ADD32(ctx->r10, ctx->r25);
    // 0x800C63D4: sh          $t8, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r24;
    // 0x800C63D8: lh          $t5, 0xE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE);
    // 0x800C63DC: lh          $t3, 0xA($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XA);
    // 0x800C63E0: nop

    // 0x800C63E4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800C63E8: sh          $t6, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r14;
    // 0x800C63EC: lbu         $t4, 0x10($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X10);
    // 0x800C63F0: nop

    // 0x800C63F4: sb          $t4, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r12;
    // 0x800C63F8: lbu         $t7, 0x11($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X11);
    // 0x800C63FC: nop

    // 0x800C6400: sb          $t7, 0x15($s1)
    MEM_B(0X15, ctx->r17) = ctx->r15;
    // 0x800C6404: lbu         $t2, 0x12($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X12);
    // 0x800C6408: nop

    // 0x800C640C: sb          $t2, 0x16($s1)
    MEM_B(0X16, ctx->r17) = ctx->r10;
    // 0x800C6410: lbu         $t9, 0x13($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X13);
    // 0x800C6414: nop

    // 0x800C6418: sb          $t9, 0x17($s1)
    MEM_B(0X17, ctx->r17) = ctx->r25;
    // 0x800C641C: lbu         $t8, 0x14($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X14);
    // 0x800C6420: nop

    // 0x800C6424: sb          $t8, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r24;
    // 0x800C6428: lbu         $t3, 0x15($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X15);
    // 0x800C642C: nop

    // 0x800C6430: sb          $t3, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r11;
    // 0x800C6434: lbu         $t5, 0x16($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X16);
    // 0x800C6438: nop

    // 0x800C643C: sb          $t5, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r13;
    // 0x800C6440: lbu         $t6, 0x17($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X17);
    // 0x800C6444: nop

    // 0x800C6448: sb          $t6, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r14;
    // 0x800C644C: lbu         $t4, 0x18($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X18);
    // 0x800C6450: nop

    // 0x800C6454: sb          $t4, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r12;
    // 0x800C6458: lbu         $t7, 0x19($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X19);
    // 0x800C645C: nop

    // 0x800C6460: sb          $t7, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r15;
    // 0x800C6464: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x800C6468: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800C646C: jal         0x800C64C0
    // 0x800C6470: nop

    parse_string_with_number(rdram, ctx);
        goto after_8;
    // 0x800C6470: nop

    after_8:
    // 0x800C6474: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C6478: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C647C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800C6480: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C6484: jal         0x800C4B04
    // 0x800C6488: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    render_text_string(rdram, ctx);
        goto after_9;
    // 0x800C6488: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_9:
    // 0x800C648C: lw          $s0, 0x1C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X1C);
    // 0x800C6490: nop

    // 0x800C6494: bne         $s0, $zero, L_800C63C4
    if (ctx->r16 != 0) {
        // 0x800C6498: nop
    
            goto L_800C63C4;
    }
    // 0x800C6498: nop

    // 0x800C649C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800C64A0:
    // 0x800C64A0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800C64A4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C64A8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800C64AC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800C64B0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800C64B4: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800C64B8: jr          $ra
    // 0x800C64BC: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
    return;
    // 0x800C64BC: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
;}
RECOMP_FUNC void trackmenu_set_records(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80082D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082D10: jal         0x8006ECD0
    // 0x80082D14: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x80082D14: nop

    after_0:
    // 0x80082D18: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80082D1C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80082D20: jal         0x8006B464
    // 0x80082D24: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    level_count(rdram, ctx);
        goto after_1;
    // 0x80082D24: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80082D28: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80082D2C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80082D30: blez        $t6, L_80082DB4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80082D34: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80082DB4;
    }
    // 0x80082D34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082D38: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80082D3C: addiu       $a0, $a0, 0x6AD0
    ctx->r4 = ADD32(ctx->r4, 0X6AD0);
    // 0x80082D40: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80082D44:
    // 0x80082D44: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x80082D48: nop

    // 0x80082D4C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80082D50: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x80082D54: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80082D58:
    // 0x80082D58: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80082D5C: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x80082D60: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80082D64: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80082D68: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80082D6C: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x80082D70: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80082D74: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80082D78: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x80082D7C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80082D80: nop

    // 0x80082D84: or          $t8, $t0, $t7
    ctx->r24 = ctx->r8 | ctx->r15;
    // 0x80082D88: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80082D8C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80082D90: nop

    // 0x80082D94: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80082D98: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x80082D9C: bne         $at, $zero, L_80082D58
    if (ctx->r1 != 0) {
        // 0x80082DA0: sw          $t1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r9;
            goto L_80082D58;
    }
    // 0x80082DA0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80082DA4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80082DA8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80082DAC: bne         $a1, $t2, L_80082D44
    if (ctx->r5 != ctx->r10) {
        // 0x80082DB0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80082D44;
    }
    // 0x80082DB0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80082DB4:
    // 0x80082DB4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80082DB8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80082DBC: sh          $zero, 0xE($a2)
    MEM_H(0XE, ctx->r6) = 0;
    // 0x80082DC0: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x80082DC4: sh          $zero, 0xC($a2)
    MEM_H(0XC, ctx->r6) = 0;
    // 0x80082DC8: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x80082DCC: addiu       $v1, $v1, 0x6ADC
    ctx->r3 = ADD32(ctx->r3, 0X6ADC);
    // 0x80082DD0: addiu       $v0, $v0, 0x6AD0
    ctx->r2 = ADD32(ctx->r2, 0X6AD0);
L_80082DD4:
    // 0x80082DD4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80082DD8: lhu         $t3, 0xE($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0XE);
    // 0x80082DDC: lhu         $t5, 0xE($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0XE);
    // 0x80082DE0: lhu         $t0, 0x8($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X8);
    // 0x80082DE4: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80082DE8: sh          $t6, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r14;
    // 0x80082DEC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80082DF0: lhu         $t1, 0xC($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0XC);
    // 0x80082DF4: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x80082DF8: lw          $t5, 0x10($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X10);
    // 0x80082DFC: or          $t9, $t0, $t8
    ctx->r25 = ctx->r8 | ctx->r24;
    // 0x80082E00: sh          $t9, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r25;
    // 0x80082E04: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80082E08: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80082E0C: lhu         $t4, 0xC($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0XC);
    // 0x80082E10: nop

    // 0x80082E14: or          $t3, $t1, $t4
    ctx->r11 = ctx->r9 | ctx->r12;
    // 0x80082E18: sh          $t3, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r11;
    // 0x80082E1C: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x80082E20: nop

    // 0x80082E24: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80082E28: nop

    // 0x80082E2C: or          $t0, $t5, $t7
    ctx->r8 = ctx->r13 | ctx->r15;
    // 0x80082E30: bne         $v0, $v1, L_80082DD4
    if (ctx->r2 != ctx->r3) {
        // 0x80082E34: sw          $t0, 0x10($a2)
        MEM_W(0X10, ctx->r6) = ctx->r8;
            goto L_80082DD4;
    }
    // 0x80082E34: sw          $t0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r8;
    // 0x80082E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80082E3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80082E40: jr          $ra
    // 0x80082E44: nop

    return;
    // 0x80082E44: nop

;}
RECOMP_FUNC void alloc_displaylist_heap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF3C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006EF40: addiu       $v0, $v0, 0x3A8C
    ctx->r2 = ADD32(ctx->r2, 0X3A8C);
    // 0x8006EF44: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EF48: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006EF4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006EF50: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006EF54: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006EF58: beq         $a0, $t6, L_8006F150
    if (ctx->r4 == ctx->r14) {
        // 0x8006EF5C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8006F150;
    }
    // 0x8006EF5C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006EF60: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8006EF64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006EF68: jal         0x800712F0
    // 0x8006EF6C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    mempool_free_timer(rdram, ctx);
        goto after_0;
    // 0x8006EF6C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006EF70: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8006EF74: addiu       $s1, $s1, 0x1770
    ctx->r17 = ADD32(ctx->r17, 0X1770);
    // 0x8006EF78: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006EF7C: jal         0x80071380
    // 0x8006EF80: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x8006EF80: nop

    after_1:
    // 0x8006EF84: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8006EF88: jal         0x80071380
    // 0x8006EF8C: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x8006EF8C: nop

    after_2:
    // 0x8006EF90: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8006EF94: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8006EF98: addiu       $t8, $t8, -0x26B0
    ctx->r24 = ADD32(ctx->r24, -0X26B0);
    // 0x8006EF9C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006EFA0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8006EFA4: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8006EFA8: addiu       $t9, $t9, -0x26E0
    ctx->r25 = ADD32(ctx->r25, -0X26E0);
    // 0x8006EFAC: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x8006EFB0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8006EFB4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8006EFB8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8006EFBC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8006EFC0: addiu       $t5, $t5, -0x26D0
    ctx->r13 = ADD32(ctx->r13, -0X26D0);
    // 0x8006EFC4: addiu       $t4, $t4, -0x26C0
    ctx->r12 = ADD32(ctx->r12, -0X26C0);
    // 0x8006EFC8: addu        $a3, $t7, $t4
    ctx->r7 = ADD32(ctx->r15, ctx->r12);
    // 0x8006EFCC: addu        $t1, $t7, $t5
    ctx->r9 = ADD32(ctx->r15, ctx->r13);
    // 0x8006EFD0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8006EFD4: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8006EFD8: addu        $t4, $t7, $t9
    ctx->r12 = ADD32(ctx->r15, ctx->r25);
    // 0x8006EFDC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8006EFE0: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8006EFE4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8006EFE8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8006EFEC: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x8006EFF0: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x8006EFF4: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8006EFF8: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x8006EFFC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8006F000: lui         $a2, 0xFF00
    ctx->r6 = S32(0XFF00 << 16);
    // 0x8006F004: ori         $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 | 0XFF;
    // 0x8006F008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006F00C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8006F010: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8006F014: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8006F018: jal         0x80071138
    // 0x8006F01C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    mempool_alloc_fixed(rdram, ctx);
        goto after_3;
    // 0x8006F01C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_3:
    // 0x8006F020: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8006F024: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
    // 0x8006F028: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8006F02C: ori         $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 | 0XFF;
    // 0x8006F030: jal         0x80071138
    // 0x8006F034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_alloc_fixed(rdram, ctx);
        goto after_4;
    // 0x8006F034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8006F038: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8006F03C: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x8006F040: beq         $s0, $zero, L_8006F050
    if (ctx->r16 == 0) {
        // 0x8006F044: nop
    
            goto L_8006F050;
    }
    // 0x8006F044: nop

    // 0x8006F048: bne         $v0, $zero, L_8006F094
    if (ctx->r2 != 0) {
        // 0x8006F04C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8006F094;
    }
    // 0x8006F04C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8006F050:
    // 0x8006F050: beq         $s0, $zero, L_8006F064
    if (ctx->r16 == 0) {
        // 0x8006F054: nop
    
            goto L_8006F064;
    }
    // 0x8006F054: nop

    // 0x8006F058: jal         0x80071380
    // 0x8006F05C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x8006F05C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8006F060: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_8006F064:
    // 0x8006F064: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8006F068: nop

    // 0x8006F06C: beq         $a1, $zero, L_8006F080
    if (ctx->r5 == 0) {
        // 0x8006F070: nop
    
            goto L_8006F080;
    }
    // 0x8006F070: nop

    // 0x8006F074: jal         0x80071380
    // 0x8006F078: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mempool_free(rdram, ctx);
        goto after_6;
    // 0x8006F078: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_6:
    // 0x8006F07C: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
L_8006F080:
    // 0x8006F080: jal         0x8006F21C
    // 0x8006F084: nop

    default_alloc_displaylist_heap(rdram, ctx);
        goto after_7;
    // 0x8006F084: nop

    after_7:
    // 0x8006F088: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8006F08C: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8006F090: nop

L_8006F094:
    // 0x8006F094: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8006F098: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006F09C: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x8006F0A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F0A4: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8006F0A8: addu        $t4, $v1, $s0
    ctx->r12 = ADD32(ctx->r3, ctx->r16);
    // 0x8006F0AC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006F0B0: sw          $t4, 0x1780($at)
    MEM_W(0X1780, ctx->r1) = ctx->r12;
    // 0x8006F0B4: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x8006F0B8: addiu       $t2, $t2, 0x1780
    ctx->r10 = ADD32(ctx->r10, 0X1780);
    // 0x8006F0BC: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x8006F0C0: sll         $a3, $a2, 6
    ctx->r7 = S32(ctx->r6 << 6);
    // 0x8006F0C4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8006F0C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F0CC: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8006F0D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006F0D4: sw          $t8, 0x17A0($at)
    MEM_W(0X17A0, ctx->r1) = ctx->r24;
    // 0x8006F0D8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8006F0DC: addiu       $t3, $t3, 0x17A0
    ctx->r11 = ADD32(ctx->r11, 0X17A0);
    // 0x8006F0E0: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8006F0E4: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8006F0E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F0EC: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x8006F0F0: sw          $t4, 0x1790($at)
    MEM_W(0X1790, ctx->r1) = ctx->r12;
    // 0x8006F0F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F0F8: addu        $t6, $v1, $a1
    ctx->r14 = ADD32(ctx->r3, ctx->r5);
    // 0x8006F0FC: sw          $t6, 0x1784($at)
    MEM_W(0X1784, ctx->r1) = ctx->r14;
    // 0x8006F100: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x8006F104: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F108: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8006F10C: sw          $t8, 0x17A4($at)
    MEM_W(0X17A4, ctx->r1) = ctx->r24;
    // 0x8006F110: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8006F114: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F118: addu        $t5, $t1, $t9
    ctx->r13 = ADD32(ctx->r9, ctx->r25);
    // 0x8006F11C: sw          $t5, 0x1794($at)
    MEM_W(0X1794, ctx->r1) = ctx->r13;
    // 0x8006F120: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F124: sw          $v0, 0x3AA8($at)
    MEM_W(0X3AA8, ctx->r1) = ctx->r2;
    // 0x8006F128: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F12C: sw          $a2, 0x3AAC($at)
    MEM_W(0X3AAC, ctx->r1) = ctx->r6;
    // 0x8006F130: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8006F134: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F138: sw          $t0, 0x3AB0($at)
    MEM_W(0X3AB0, ctx->r1) = ctx->r8;
    // 0x8006F13C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8006F140: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F144: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8006F148: jal         0x800712F0
    // 0x8006F14C: sw          $t6, 0x3AB4($at)
    MEM_W(0X3AB4, ctx->r1) = ctx->r14;
    mempool_free_timer(rdram, ctx);
        goto after_8;
    // 0x8006F14C: sw          $t6, 0x3AB4($at)
    MEM_W(0X3AB4, ctx->r1) = ctx->r14;
    after_8:
L_8006F150:
    // 0x8006F150: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006F154: lw          $v1, 0x3A68($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3A68);
    // 0x8006F158: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8006F15C: addiu       $s1, $s1, 0x1770
    ctx->r17 = ADD32(ctx->r17, 0X1770);
    // 0x8006F160: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8006F164: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x8006F168: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8006F16C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006F170: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006F174: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006F178: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8006F17C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8006F180: lw          $t5, 0x1780($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1780);
    // 0x8006F184: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006F188: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F18C: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x8006F190: lw          $t4, 0x17A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X17A0);
    // 0x8006F194: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006F198: sw          $t5, 0x1788($at)
    MEM_W(0X1788, ctx->r1) = ctx->r13;
    // 0x8006F19C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F1A0: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8006F1A4: lw          $t6, 0x1790($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1790);
    // 0x8006F1A8: sw          $t4, 0x17A8($at)
    MEM_W(0X17A8, ctx->r1) = ctx->r12;
    // 0x8006F1AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F1B0: sw          $t6, 0x1798($at)
    MEM_W(0X1798, ctx->r1) = ctx->r14;
    // 0x8006F1B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006F1B8: lui         $t8, 0xE900
    ctx->r24 = S32(0XE900 << 16);
    // 0x8006F1BC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006F1C0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8006F1C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006F1C8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8006F1CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006F1D0: lui         $t5, 0xB800
    ctx->r13 = S32(0XB800 << 16);
    // 0x8006F1D4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8006F1D8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8006F1DC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006F1E0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8006F1E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F1E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006F1EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006F1F0: jr          $ra
    // 0x8006F1F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006F1F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alCSPSetChlPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7E40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7E44: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C7E48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7E4C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C7E50: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C7E54: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800C7E58: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C7E5C: ori         $t7, $a3, 0xB0
    ctx->r15 = ctx->r7 | 0XB0;
    // 0x800C7E60: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x800C7E64: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C7E68: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C7E6C: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x800C7E70: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x800C7E74: sb          $t0, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r8;
    // 0x800C7E78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C7E7C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C7E80: jal         0x800C970C
    // 0x800C7E84: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C7E84: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x800C7E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7E8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7E90: jr          $ra
    // 0x800C7E94: nop

    return;
    // 0x800C7E94: nop

;}
RECOMP_FUNC void func_80080BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081018: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008101C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80081020: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80081024: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80081028: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008102C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80081030: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80081034: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80081038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008103C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80081040: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80081044: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80081048: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8008104C: addiu       $t8, $t8, 0x21F0
    ctx->r24 = ADD32(ctx->r24, 0X21F0);
    // 0x80081050: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80081054: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80081058: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8008105C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80081060: lw          $t1, 0x2338($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2338);
    // 0x80081064: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80081068: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8008106C: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80081070: blez        $t1, L_8008126C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80081074: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8008126C;
    }
    // 0x80081074: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80081078: lui         $s6, 0xE
    ctx->r22 = S32(0XE << 16);
    // 0x8008107C: lui         $s1, 0xE
    ctx->r17 = S32(0XE << 16);
    // 0x80081080: lui         $ra, 0x702
    ctx->r31 = S32(0X702 << 16);
    // 0x80081084: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80081088: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008108C: addiu       $t2, $t2, 0x2334
    ctx->r10 = ADD32(ctx->r10, 0X2334);
    // 0x80081090: addiu       $t3, $t3, 0x71EC
    ctx->r11 = ADD32(ctx->r11, 0X71EC);
    // 0x80081094: ori         $ra, $ra, 0x10
    ctx->r31 = ctx->r31 | 0X10;
    // 0x80081098: addiu       $s1, $s1, 0x2230
    ctx->r17 = ADD32(ctx->r17, 0X2230);
    // 0x8008109C: addiu       $s6, $s6, 0x2220
    ctx->r22 = ADD32(ctx->r22, 0X2220);
    // 0x800810A0: lui         $s5, 0x500
    ctx->r21 = S32(0X500 << 16);
    // 0x800810A4: lui         $s4, 0x400
    ctx->r20 = S32(0X400 << 16);
    // 0x800810A8: lui         $s3, 0xE700
    ctx->r19 = S32(0XE700 << 16);
    // 0x800810AC: lui         $s2, 0x700
    ctx->r18 = S32(0X700 << 16);
    // 0x800810B0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800810B4: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
L_800810B8:
    // 0x800810B8: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x800810BC: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800810C0: sll         $t6, $a3, 5
    ctx->r14 = S32(ctx->r7 << 5);
    // 0x800810C4: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800810C8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800810CC: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x800810D0: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x800810D4: nop

    // 0x800810D8: bne         $t6, $zero, L_8008125C
    if (ctx->r14 != 0) {
        // 0x800810DC: nop
    
            goto L_8008125C;
    }
    // 0x800810DC: nop

    // 0x800810E0: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x800810E4: nop

    // 0x800810E8: beq         $v1, $zero, L_80081160
    if (ctx->r3 == 0) {
        // 0x800810EC: nop
    
            goto L_80081160;
    }
    // 0x800810EC: nop

    // 0x800810F0: beq         $t0, $s0, L_80081110
    if (ctx->r8 == ctx->r16) {
        // 0x800810F4: nop
    
            goto L_80081110;
    }
    // 0x800810F4: nop

    // 0x800810F8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800810FC: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x80081100: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80081104: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80081108: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8008110C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
L_80081110:
    // 0x80081110: beq         $t5, $v1, L_80081180
    if (ctx->r13 == ctx->r3) {
        // 0x80081114: nop
    
            goto L_80081180;
    }
    // 0x80081114: nop

    // 0x80081118: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8008111C: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
    // 0x80081120: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80081124: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80081128: lh          $a1, 0xA($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XA);
    // 0x8008112C: nop

    // 0x80081130: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x80081134: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80081138: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x8008113C: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80081140: or          $t8, $t6, $s2
    ctx->r24 = ctx->r14 | ctx->r18;
    // 0x80081144: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80081148: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8008114C: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x80081150: nop

    // 0x80081154: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x80081158: b           L_80081180
    // 0x8008115C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_80081180;
    // 0x8008115C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_80081160:
    // 0x80081160: beq         $t0, $zero, L_80081180
    if (ctx->r8 == 0) {
        // 0x80081164: nop
    
            goto L_80081180;
    }
    // 0x80081164: nop

    // 0x80081168: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8008116C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80081170: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80081174: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80081178: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x8008117C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
L_80081180:
    // 0x80081180: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80081184: sll         $t9, $a3, 5
    ctx->r25 = S32(ctx->r7 << 5);
    // 0x80081188: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8008118C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80081190: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80081194: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80081198: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8008119C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800811A0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800811A4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800811A8: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x800811AC: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800811B0: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x800811B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800811B8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800811BC: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800811C0: nop

    // 0x800811C4: addu        $t6, $t7, $t4
    ctx->r14 = ADD32(ctx->r15, ctx->r12);
    // 0x800811C8: andi        $t8, $t6, 0x6
    ctx->r24 = ctx->r14 & 0X6;
    // 0x800811CC: ori         $t9, $t8, 0x98
    ctx->r25 = ctx->r24 | 0X98;
    // 0x800811D0: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x800811D4: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800811D8: or          $t8, $t6, $s4
    ctx->r24 = ctx->r14 | ctx->r20;
    // 0x800811DC: ori         $t9, $t8, 0x170
    ctx->r25 = ctx->r24 | 0X170;
    // 0x800811E0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800811E4: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800811E8: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x800811EC: sll         $t6, $a3, 5
    ctx->r14 = S32(ctx->r7 << 5);
    // 0x800811F0: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800811F4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800811F8: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800811FC: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80081200: ori         $t6, $t0, 0x90
    ctx->r14 = ctx->r8 | 0X90;
    // 0x80081204: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x80081208: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8008120C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80081210: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x80081214: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80081218: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8008121C: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80081220: or          $t7, $t8, $s5
    ctx->r15 = ctx->r24 | ctx->r21;
    // 0x80081224: ori         $t6, $t7, 0xA0
    ctx->r14 = ctx->r15 | 0XA0;
    // 0x80081228: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8008122C: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x80081230: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80081234: sll         $t8, $a3, 5
    ctx->r24 = S32(ctx->r7 << 5);
    // 0x80081238: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8008123C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80081240: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80081244: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x80081248: nop

    // 0x8008124C: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x80081250: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80081254: lw          $t1, 0x2338($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2338);
    // 0x80081258: nop

L_8008125C:
    // 0x8008125C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80081260: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80081264: bne         $at, $zero, L_800810B8
    if (ctx->r1 != 0) {
        // 0x80081268: nop
    
            goto L_800810B8;
    }
    // 0x80081268: nop

L_8008126C:
    // 0x8008126C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80081270: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081274: addiu       $t2, $t2, 0x2334
    ctx->r10 = ADD32(ctx->r10, 0X2334);
    // 0x80081278: sw          $zero, 0x2338($at)
    MEM_W(0X2338, ctx->r1) = 0;
    // 0x8008127C: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80081280: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80081284: subu        $t8, $s0, $t9
    ctx->r24 = SUB32(ctx->r16, ctx->r25);
    // 0x80081288: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8008128C: jal         0x8007B820
    // 0x80081290: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x80081290: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80081294: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80081298: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008129C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800812A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800812A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800812A8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800812AC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800812B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800812B4: jr          $ra
    // 0x800812B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800812B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void obj_init_attachpoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F99C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000F9A0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000F9A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000F9A8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000F9AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000F9B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000F9B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000F9B8: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x8000F9BC: lw          $s3, 0x60($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X60);
    // 0x8000F9C0: lb          $v0, 0x56($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X56);
    // 0x8000F9C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000F9C8: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8000F9CC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8000F9D0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000F9D4: blez        $v0, L_8000FA20
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000F9D8: sw          $v0, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r2;
            goto L_8000FA20;
    }
    // 0x8000F9D8: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8000F9DC: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
L_8000F9E0:
    // 0x8000F9E0: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x8000F9E4: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x8000F9E8: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x8000F9EC: nop

    // 0x8000F9F0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8000F9F4: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8000F9F8: jal         0x8000FD54
    // 0x8000F9FC: nop

    obj_spawn_attachment(rdram, ctx);
        goto after_0;
    // 0x8000F9FC: nop

    after_0:
    // 0x8000FA00: bne         $v0, $zero, L_8000FA0C
    if (ctx->r2 != 0) {
        // 0x8000FA04: sw          $v0, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r2;
            goto L_8000FA0C;
    }
    // 0x8000FA04: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x8000FA08: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_8000FA0C:
    // 0x8000FA0C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8000FA10: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000FA14: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000FA18: bne         $at, $zero, L_8000F9E0
    if (ctx->r1 != 0) {
        // 0x8000FA1C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000F9E0;
    }
    // 0x8000FA1C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8000FA20:
    // 0x8000FA20: beq         $s4, $zero, L_8000FA90
    if (ctx->r20 == 0) {
        // 0x8000FA24: nop
    
            goto L_8000FA90;
    }
    // 0x8000FA24: nop

    // 0x8000FA28: blez        $v0, L_8000FA88
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000FA2C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8000FA88;
    }
    // 0x8000FA2C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000FA30: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
L_8000FA34:
    // 0x8000FA34: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8000FA38: nop

    // 0x8000FA3C: beq         $s0, $zero, L_8000FA78
    if (ctx->r16 == 0) {
        // 0x8000FA40: nop
    
            goto L_8000FA78;
    }
    // 0x8000FA40: nop

    // 0x8000FA44: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x8000FA48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000FA4C: lb          $a1, 0x55($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X55);
    // 0x8000FA50: lb          $a2, 0x53($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X53);
    // 0x8000FA54: jal         0x8000F648
    // 0x8000FA58: nop

    objFreeAssets(rdram, ctx);
        goto after_1;
    // 0x8000FA58: nop

    after_1:
    // 0x8000FA5C: lh          $a0, 0x2C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2C);
    // 0x8000FA60: jal         0x8000C844
    // 0x8000FA64: nop

    try_free_object_header(rdram, ctx);
        goto after_2;
    // 0x8000FA64: nop

    after_2:
    // 0x8000FA68: jal         0x80071380
    // 0x8000FA6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_3;
    // 0x8000FA6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8000FA70: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8000FA74: nop

L_8000FA78:
    // 0x8000FA78: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000FA7C: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000FA80: bne         $at, $zero, L_8000FA34
    if (ctx->r1 != 0) {
        // 0x8000FA84: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000FA34;
    }
    // 0x8000FA84: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8000FA88:
    // 0x8000FA88: b           L_8000FAA4
    // 0x8000FA8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000FAA4;
    // 0x8000FA8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000FA90:
    // 0x8000FA90: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x8000FA94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000FA98: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x8000FA9C: nop

    // 0x8000FAA0: sw          $t4, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->r12;
L_8000FAA4:
    // 0x8000FAA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FAA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000FAAC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FAB0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000FAB4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000FAB8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000FABC: jr          $ra
    // 0x8000FAC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000FAC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void cam_get_fov(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006631C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066320: lwc1        $f0, 0x1290($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X1290);
    // 0x80066324: jr          $ra
    // 0x80066328: nop

    return;
    // 0x80066328: nop

;}
