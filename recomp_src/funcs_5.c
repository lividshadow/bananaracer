#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void alCSPSetSeq(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8AC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C8AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8AC8: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x800C8ACC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C8AD0: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C8AD4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C8AD8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C8ADC: jal         0x800C970C
    // 0x800C8AE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C8AE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C8AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8AE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C8AEC: jr          $ra
    // 0x800C8AF0: nop

    return;
    // 0x800C8AF0: nop

;}
RECOMP_FUNC void set_subtitles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3014: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C3018: jr          $ra
    // 0x800C301C: sw          $a0, 0x3C10($at)
    MEM_W(0X3C10, ctx->r1) = ctx->r4;
    return;
    // 0x800C301C: sw          $a0, 0x3C10($at)
    MEM_W(0X3C10, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void rankings_render_order(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800993F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800993FC: addiu       $v0, $v0, 0x695C
    ctx->r2 = ADD32(ctx->r2, 0X695C);
    // 0x80099400: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80099404: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80099408: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8009940C: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x80099410: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80099414: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x80099418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009941C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80099420: bne         $at, $zero, L_80099430
    if (ctx->r1 != 0) {
        // 0x80099424: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_80099430;
    }
    // 0x80099424: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80099428: addiu       $t4, $zero, 0x1FF
    ctx->r12 = ADD32(0, 0X1FF);
    // 0x8009942C: subu        $a2, $t4, $t9
    ctx->r6 = SUB32(ctx->r12, ctx->r25);
L_80099430:
    // 0x80099430: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80099434: lw          $t1, 0x1564($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1564);
    // 0x80099438: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009943C: blez        $t1, L_800994D0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80099440: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_800994D0;
    }
    // 0x80099440: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80099444: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80099448: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009944C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80099450: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80099454: lw          $t2, -0x5C4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5C4);
    // 0x80099458: addiu       $a3, $a3, 0x69B8
    ctx->r7 = ADD32(ctx->r7, 0X69B8);
    // 0x8009945C: addiu       $t0, $t0, 0x69C0
    ctx->r8 = ADD32(ctx->r8, 0X69C0);
    // 0x80099460: addiu       $t3, $t3, 0x6980
    ctx->r11 = ADD32(ctx->r11, 0X6980);
    // 0x80099464: addiu       $a1, $a1, 0x1608
    ctx->r5 = ADD32(ctx->r5, 0X1608);
L_80099468:
    // 0x80099468: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x8009946C: beq         $at, $zero, L_800994B4
    if (ctx->r1 == 0) {
        // 0x80099470: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_800994B4;
    }
    // 0x80099470: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80099474: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80099478: addu        $t5, $a3, $a0
    ctx->r13 = ADD32(ctx->r7, ctx->r4);
    // 0x8009947C: bne         $v1, $zero, L_80099494
    if (ctx->r3 != 0) {
        // 0x80099480: nop
    
            goto L_80099494;
    }
    // 0x80099480: nop

    // 0x80099484: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x80099488: nop

    // 0x8009948C: bne         $t6, $zero, L_800994AC
    if (ctx->r14 != 0) {
        // 0x80099490: nop
    
            goto L_800994AC;
    }
    // 0x80099490: nop

L_80099494:
    // 0x80099494: beq         $v1, $zero, L_800994B4
    if (ctx->r3 == 0) {
        // 0x80099498: addu        $t7, $t0, $a0
        ctx->r15 = ADD32(ctx->r8, ctx->r4);
            goto L_800994B4;
    }
    // 0x80099498: addu        $t7, $t0, $a0
    ctx->r15 = ADD32(ctx->r8, ctx->r4);
    // 0x8009949C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800994A0: nop

    // 0x800994A4: beq         $t8, $zero, L_800994B4
    if (ctx->r24 == 0) {
        // 0x800994A8: nop
    
            goto L_800994B4;
    }
    // 0x800994A8: nop

L_800994AC:
    // 0x800994AC: sra         $v0, $a2, 1
    ctx->r2 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800994B0: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
L_800994B4:
    // 0x800994B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800994B8: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800994BC: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    // 0x800994C0: sb          $v0, -0x54($a1)
    MEM_B(-0X54, ctx->r5) = ctx->r2;
    // 0x800994C4: sb          $v0, -0x53($a1)
    MEM_B(-0X53, ctx->r5) = ctx->r2;
    // 0x800994C8: bne         $at, $zero, L_80099468
    if (ctx->r1 != 0) {
        // 0x800994CC: sb          $v0, -0x52($a1)
        MEM_B(-0X52, ctx->r5) = ctx->r2;
            goto L_80099468;
    }
    // 0x800994CC: sb          $v0, -0x52($a1)
    MEM_B(-0X52, ctx->r5) = ctx->r2;
L_800994D0:
    // 0x800994D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800994D4: addiu       $t3, $t3, 0x6980
    ctx->r11 = ADD32(ctx->r11, 0X6980);
    // 0x800994D8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800994DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800994E0: beq         $v0, $at, L_800994F0
    if (ctx->r2 == ctx->r1) {
        // 0x800994E4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800994F0;
    }
    // 0x800994E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800994E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800994EC: bne         $v0, $at, L_80099500
    if (ctx->r2 != ctx->r1) {
        // 0x800994F0: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_80099500;
    }
L_800994F0:
    // 0x800994F0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800994F4: addiu       $a1, $a1, 0x15C8
    ctx->r5 = ADD32(ctx->r5, 0X15C8);
    // 0x800994F8: jal         0x8008263C
    // 0x800994FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    draw_menu_elements(rdram, ctx);
        goto after_0;
    // 0x800994FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_0:
L_80099500:
    // 0x80099500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80099504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80099508: jr          $ra
    // 0x8009950C: nop

    return;
    // 0x8009950C: nop

;}
RECOMP_FUNC void debug_print_fixed_matrix_values(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A1A4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8006A1A8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8006A1AC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006A1B0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006A1B4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8006A1B8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8006A1BC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8006A1C0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8006A1C4: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8006A1C8: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8006A1CC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8006A1D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006A1D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006A1D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A1DC: addiu       $fp, $fp, 0x7614
    ctx->r30 = ADD32(ctx->r30, 0X7614);
    // 0x8006A1E0: addiu       $s4, $s4, 0x760C
    ctx->r20 = ADD32(ctx->r20, 0X760C);
    // 0x8006A1E4: addiu       $s3, $s3, 0x7608
    ctx->r19 = ADD32(ctx->r19, 0X7608);
    // 0x8006A1E8: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x8006A1EC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8006A1F0: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
L_8006A1F4:
    // 0x8006A1F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006A1F8: or          $s0, $s7, $zero
    ctx->r16 = ctx->r23 | 0;
L_8006A1FC:
    // 0x8006A1FC: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8006A200: jal         0x800CA2B4
    // 0x8006A204: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8006A204: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x8006A208: lh          $a1, 0x20($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X20);
    // 0x8006A20C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8006A210: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x8006A214: jal         0x800CA2B4
    // 0x8006A218: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8006A218: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_1:
    // 0x8006A21C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8006A220: bne         $s1, $s5, L_8006A1FC
    if (ctx->r17 != ctx->r21) {
        // 0x8006A224: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8006A1FC;
    }
    // 0x8006A224: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8006A228: jal         0x800CA2B4
    // 0x8006A22C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8006A22C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_2:
    // 0x8006A230: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8006A234: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8006A238: bne         $s6, $at, L_8006A1F4
    if (ctx->r22 != ctx->r1) {
        // 0x8006A23C: addiu       $s7, $s7, 0x8
        ctx->r23 = ADD32(ctx->r23, 0X8);
            goto L_8006A1F4;
    }
    // 0x8006A23C: addiu       $s7, $s7, 0x8
    ctx->r23 = ADD32(ctx->r23, 0X8);
    // 0x8006A240: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006A244: jal         0x800CA2B4
    // 0x8006A248: addiu       $a0, $a0, 0x7618
    ctx->r4 = ADD32(ctx->r4, 0X7618);
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8006A248: addiu       $a0, $a0, 0x7618
    ctx->r4 = ADD32(ctx->r4, 0X7618);
    after_3:
    // 0x8006A24C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8006A250: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A254: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A258: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006A25C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006A260: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006A264: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8006A268: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8006A26C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8006A270: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8006A274: jr          $ra
    // 0x8006A278: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8006A278: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void alSynSetPriority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA040: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800CA044: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800CA048: jr          $ra
    // 0x800CA04C: sh          $a2, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r6;
    return;
    // 0x800CA04C: sh          $a2, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void obj_init_fish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036C70: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80036C74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80036C78: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80036C7C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80036C80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80036C84: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80036C88: lbu         $t6, 0xE($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XE);
    // 0x80036C8C: lw          $s0, 0x64($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X64);
    // 0x80036C90: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80036C94: sh          $t7, 0x100($s0)
    MEM_H(0X100, ctx->r16) = ctx->r15;
    // 0x80036C98: lbu         $t8, 0xF($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XF);
    // 0x80036C9C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80036CA0: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80036CA4: sh          $t9, 0x104($s0)
    MEM_H(0X104, ctx->r16) = ctx->r25;
    // 0x80036CA8: lhu         $t0, 0x8($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X8);
    // 0x80036CAC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80036CB0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80036CB4: bgez        $t0, L_80036CCC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80036CB8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80036CCC;
    }
    // 0x80036CB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80036CBC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80036CC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80036CC4: nop

    // 0x80036CC8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80036CCC:
    // 0x80036CCC: swc1        $f6, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f6.u32l;
    // 0x80036CD0: lbu         $t1, 0xA($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0XA);
    // 0x80036CD4: nop

    // 0x80036CD8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80036CDC: bgez        $t1, L_80036CF4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80036CE0: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80036CF4;
    }
    // 0x80036CE0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80036CE4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80036CE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036CEC: nop

    // 0x80036CF0: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80036CF4:
    // 0x80036CF4: swc1        $f18, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f18.u32l;
    // 0x80036CF8: lh          $t2, 0x2($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X2);
    // 0x80036CFC: nop

    // 0x80036D00: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80036D04: nop

    // 0x80036D08: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80036D0C: swc1        $f6, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f6.u32l;
    // 0x80036D10: lh          $t3, 0x4($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X4);
    // 0x80036D14: nop

    // 0x80036D18: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80036D1C: nop

    // 0x80036D20: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80036D24: swc1        $f4, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f4.u32l;
    // 0x80036D28: lh          $t4, 0x6($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X6);
    // 0x80036D2C: nop

    // 0x80036D30: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80036D34: nop

    // 0x80036D38: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80036D3C: swc1        $f8, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f8.u32l;
    // 0x80036D40: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80036D44: nop

    // 0x80036D48: bne         $t5, $zero, L_80036D84
    if (ctx->r13 != 0) {
        // 0x80036D4C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80036D84;
    }
    // 0x80036D4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036D50: jal         0x8006FB8C
    // 0x80036D54: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x80036D54: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_0:
    // 0x80036D58: sh          $v0, 0xFE($s0)
    MEM_H(0XFE, ctx->r16) = ctx->r2;
    // 0x80036D5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036D60: jal         0x8006FB8C
    // 0x80036D64: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x80036D64: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_1:
    // 0x80036D68: sh          $v0, 0x102($s0)
    MEM_H(0X102, ctx->r16) = ctx->r2;
    // 0x80036D6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036D70: jal         0x8006FB8C
    // 0x80036D74: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x80036D74: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_2:
    // 0x80036D78: sh          $v0, 0x106($s0)
    MEM_H(0X106, ctx->r16) = ctx->r2;
    // 0x80036D7C: b           L_80036D94
    // 0x80036D80: sb          $zero, 0xFD($s0)
    MEM_B(0XFD, ctx->r16) = 0;
        goto L_80036D94;
    // 0x80036D80: sb          $zero, 0xFD($s0)
    MEM_B(0XFD, ctx->r16) = 0;
L_80036D84:
    // 0x80036D84: lh          $t7, 0x104($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X104);
    // 0x80036D88: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x80036D8C: sh          $t6, 0xFE($s0)
    MEM_H(0XFE, ctx->r16) = ctx->r14;
    // 0x80036D90: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
L_80036D94:
    // 0x80036D94: lh          $t8, 0xFE($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XFE);
    // 0x80036D98: nop

    // 0x80036D9C: sll         $t9, $t8, 17
    ctx->r25 = S32(ctx->r24 << 17);
    // 0x80036DA0: jal         0x80070A04
    // 0x80036DA4: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    sins_f(rdram, ctx);
        goto after_3;
    // 0x80036DA4: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_3:
    // 0x80036DA8: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80036DAC: nop

    // 0x80036DB0: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80036DB4: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80036DB8: lh          $a0, 0xFE($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XFE);
    // 0x80036DBC: jal         0x80070A38
    // 0x80036DC0: nop

    coss_f(rdram, ctx);
        goto after_4;
    // 0x80036DC0: nop

    after_4:
    // 0x80036DC4: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80036DC8: nop

    // 0x80036DCC: mul.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80036DD0: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x80036DD4: lh          $a0, 0x104($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X104);
    // 0x80036DD8: jal         0x80070A04
    // 0x80036DDC: nop

    sins_f(rdram, ctx);
        goto after_5;
    // 0x80036DDC: nop

    after_5:
    // 0x80036DE0: lh          $a0, 0x104($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X104);
    // 0x80036DE4: jal         0x80070A38
    // 0x80036DE8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_6;
    // 0x80036DE8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x80036DEC: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80036DF0: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80036DF4: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80036DF8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80036DFC: lwc1        $f18, 0x108($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X108);
    // 0x80036E00: mul.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80036E04: swc1        $f18, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f18.u32l;
    // 0x80036E08: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80036E0C: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80036E10: lwc1        $f8, 0x110($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
    // 0x80036E14: mul.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80036E18: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    // 0x80036E1C: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x80036E20: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80036E24: jal         0x80011560
    // 0x80036E28: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    ignore_bounds_check(rdram, ctx);
        goto after_7;
    // 0x80036E28: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x80036E2C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80036E30: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80036E34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80036E38: jal         0x80011570
    // 0x80036E3C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    move_object(rdram, ctx);
        goto after_8;
    // 0x80036E3C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_8:
    // 0x80036E40: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80036E44: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80036E48: bne         $t1, $zero, L_80036F10
    if (ctx->r9 != 0) {
        // 0x80036E4C: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80036F10;
    }
    // 0x80036E4C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80036E50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80036E54: addiu       $a0, $a0, -0x3040
    ctx->r4 = ADD32(ctx->r4, -0X3040);
    // 0x80036E58: addiu       $v0, $v0, -0x30C0
    ctx->r2 = ADD32(ctx->r2, -0X30C0);
L_80036E5C:
    // 0x80036E5C: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80036E60: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80036E64: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x80036E68: lbu         $t3, -0xF($v0)
    ctx->r11 = MEM_BU(ctx->r2, -0XF);
    // 0x80036E6C: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80036E70: sb          $t3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r11;
    // 0x80036E74: lbu         $t4, -0xE($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0XE);
    // 0x80036E78: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80036E7C: sb          $t4, -0xE($v1)
    MEM_B(-0XE, ctx->r3) = ctx->r12;
    // 0x80036E80: lbu         $t5, -0xD($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0XD);
    // 0x80036E84: bne         $at, $zero, L_80036E5C
    if (ctx->r1 != 0) {
        // 0x80036E88: sb          $t5, -0xD($v1)
        MEM_B(-0XD, ctx->r3) = ctx->r13;
            goto L_80036E5C;
    }
    // 0x80036E88: sb          $t5, -0xD($v1)
    MEM_B(-0XD, ctx->r3) = ctx->r13;
    // 0x80036E8C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80036E90: addiu       $v1, $v1, -0x30E8
    ctx->r3 = ADD32(ctx->r3, -0X30E8);
    // 0x80036E94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80036E98: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80036E9C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80036EA0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80036EA4:
    // 0x80036EA4: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80036EA8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80036EAC: sh          $t6, 0x80($v0)
    MEM_H(0X80, ctx->r2) = ctx->r14;
    // 0x80036EB0: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x80036EB4: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80036EB8: sh          $t7, 0x78($v0)
    MEM_H(0X78, ctx->r2) = ctx->r15;
    // 0x80036EBC: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    // 0x80036EC0: sb          $a0, 0x7C($v0)
    MEM_B(0X7C, ctx->r2) = ctx->r4;
    // 0x80036EC4: sb          $a0, 0x7D($v0)
    MEM_B(0X7D, ctx->r2) = ctx->r4;
    // 0x80036EC8: sb          $a0, 0x7E($v0)
    MEM_B(0X7E, ctx->r2) = ctx->r4;
    // 0x80036ECC: sb          $a0, 0x7F($v0)
    MEM_B(0X7F, ctx->r2) = ctx->r4;
    // 0x80036ED0: sh          $t8, 0x7A($v0)
    MEM_H(0X7A, ctx->r2) = ctx->r24;
    // 0x80036ED4: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80036ED8: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x80036EDC: sh          $t9, 0xB2($v0)
    MEM_H(0XB2, ctx->r2) = ctx->r25;
    // 0x80036EE0: lh          $t0, -0x4($v1)
    ctx->r8 = MEM_H(ctx->r3, -0X4);
    // 0x80036EE4: nop

    // 0x80036EE8: sh          $t0, 0xB4($v0)
    MEM_H(0XB4, ctx->r2) = ctx->r8;
    // 0x80036EEC: lh          $t1, -0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, -0X2);
    // 0x80036EF0: sb          $a0, 0xB8($v0)
    MEM_B(0XB8, ctx->r2) = ctx->r4;
    // 0x80036EF4: sb          $a0, 0xB9($v0)
    MEM_B(0XB9, ctx->r2) = ctx->r4;
    // 0x80036EF8: sb          $a0, 0xBA($v0)
    MEM_B(0XBA, ctx->r2) = ctx->r4;
    // 0x80036EFC: sb          $a0, 0xBB($v0)
    MEM_B(0XBB, ctx->r2) = ctx->r4;
    // 0x80036F00: bne         $a2, $a1, L_80036EA4
    if (ctx->r6 != ctx->r5) {
        // 0x80036F04: sh          $t1, 0xB6($v0)
        MEM_H(0XB6, ctx->r2) = ctx->r9;
            goto L_80036EA4;
    }
    // 0x80036F04: sh          $t1, 0xB6($v0)
    MEM_H(0XB6, ctx->r2) = ctx->r9;
    // 0x80036F08: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80036F0C: sb          $t2, 0xFC($s0)
    MEM_B(0XFC, ctx->r16) = ctx->r10;
L_80036F10:
    // 0x80036F10: lbu         $t3, 0xC($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0XC);
    // 0x80036F14: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80036F18: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80036F1C: bgez        $t3, L_80036F34
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80036F20: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80036F34;
    }
    // 0x80036F20: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80036F24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80036F28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036F2C: nop

    // 0x80036F30: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80036F34:
    // 0x80036F34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80036F38: lwc1        $f18, 0x65D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X65D8);
    // 0x80036F3C: lw          $t4, 0x40($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X40);
    // 0x80036F40: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80036F44: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80036F48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036F4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80036F50: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    // 0x80036F54: lbu         $v0, 0xB($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XB);
    // 0x80036F58: lb          $t5, 0x55($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X55);
    // 0x80036F5C: addiu       $a2, $a2, -0x3040
    ctx->r6 = ADD32(ctx->r6, -0X3040);
    // 0x80036F60: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80036F64: beq         $at, $zero, L_80036F84
    if (ctx->r1 == 0) {
        // 0x80036F68: nop
    
            goto L_80036F84;
    }
    // 0x80036F68: nop

    // 0x80036F6C: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    // 0x80036F70: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80036F74: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80036F78: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80036F7C: b           L_80036F98
    // 0x80036F80: sw          $t9, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->r25;
        goto L_80036F98;
    // 0x80036F80: sw          $t9, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->r25;
L_80036F84:
    // 0x80036F84: lw          $t0, 0x68($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X68);
    // 0x80036F88: nop

    // 0x80036F8C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80036F90: nop

    // 0x80036F94: sw          $t1, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->r9;
L_80036F98:
    // 0x80036F98: lw          $v0, 0xF8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF8);
    // 0x80036F9C: nop

    // 0x80036FA0: beq         $v0, $zero, L_80036FCC
    if (ctx->r2 == 0) {
        // 0x80036FA4: nop
    
            goto L_80036FCC;
    }
    // 0x80036FA4: nop

    // 0x80036FA8: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80036FAC: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x80036FB0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80036FB4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80036FB8: sll         $t2, $a0, 5
    ctx->r10 = S32(ctx->r4 << 5);
    // 0x80036FBC: sll         $t3, $a1, 5
    ctx->r11 = S32(ctx->r5 << 5);
    // 0x80036FC0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80036FC4: b           L_80036FCC
    // 0x80036FC8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
        goto L_80036FCC;
    // 0x80036FC8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_80036FCC:
    // 0x80036FCC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80036FD0: addiu       $v0, $v0, -0x30C0
    ctx->r2 = ADD32(ctx->r2, -0X30C0);
L_80036FD4:
    // 0x80036FD4: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x80036FD8: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80036FDC: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80036FE0: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80036FE4: mflo        $t5
    ctx->r13 = lo;
    // 0x80036FE8: sra         $t6, $t5, 2
    ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
    // 0x80036FEC: sh          $t6, -0x1C($v1)
    MEM_H(-0X1C, ctx->r3) = ctx->r14;
    // 0x80036FF0: lh          $t7, -0x1A($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X1A);
    // 0x80036FF4: nop

    // 0x80036FF8: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80036FFC: mflo        $t8
    ctx->r24 = lo;
    // 0x80037000: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x80037004: sh          $t9, -0x1A($v1)
    MEM_H(-0X1A, ctx->r3) = ctx->r25;
    // 0x80037008: lh          $t0, -0x18($v0)
    ctx->r8 = MEM_H(ctx->r2, -0X18);
    // 0x8003700C: nop

    // 0x80037010: multu       $t0, $a0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037014: mflo        $t1
    ctx->r9 = lo;
    // 0x80037018: sra         $t2, $t1, 2
    ctx->r10 = S32(SIGNED(ctx->r9) >> 2);
    // 0x8003701C: sh          $t2, -0x18($v1)
    MEM_H(-0X18, ctx->r3) = ctx->r10;
    // 0x80037020: lh          $t3, -0x16($v0)
    ctx->r11 = MEM_H(ctx->r2, -0X16);
    // 0x80037024: nop

    // 0x80037028: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003702C: mflo        $t4
    ctx->r12 = lo;
    // 0x80037030: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x80037034: sh          $t5, -0x16($v1)
    MEM_H(-0X16, ctx->r3) = ctx->r13;
    // 0x80037038: lh          $t6, -0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, -0X14);
    // 0x8003703C: nop

    // 0x80037040: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037044: mflo        $t7
    ctx->r15 = lo;
    // 0x80037048: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x8003704C: sh          $t8, -0x14($v1)
    MEM_H(-0X14, ctx->r3) = ctx->r24;
    // 0x80037050: lh          $t9, -0x12($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X12);
    // 0x80037054: nop

    // 0x80037058: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003705C: mflo        $t0
    ctx->r8 = lo;
    // 0x80037060: sra         $t1, $t0, 2
    ctx->r9 = S32(SIGNED(ctx->r8) >> 2);
    // 0x80037064: sh          $t1, -0x12($v1)
    MEM_H(-0X12, ctx->r3) = ctx->r9;
    // 0x80037068: lh          $t2, -0xC($v0)
    ctx->r10 = MEM_H(ctx->r2, -0XC);
    // 0x8003706C: nop

    // 0x80037070: multu       $t2, $a0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037074: mflo        $t3
    ctx->r11 = lo;
    // 0x80037078: sra         $t4, $t3, 2
    ctx->r12 = S32(SIGNED(ctx->r11) >> 2);
    // 0x8003707C: sh          $t4, -0xC($v1)
    MEM_H(-0XC, ctx->r3) = ctx->r12;
    // 0x80037080: lh          $t5, -0xA($v0)
    ctx->r13 = MEM_H(ctx->r2, -0XA);
    // 0x80037084: nop

    // 0x80037088: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003708C: mflo        $t6
    ctx->r14 = lo;
    // 0x80037090: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x80037094: sh          $t7, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = ctx->r15;
    // 0x80037098: lh          $t8, -0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X8);
    // 0x8003709C: nop

    // 0x800370A0: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800370A4: mflo        $t9
    ctx->r25 = lo;
    // 0x800370A8: sra         $t0, $t9, 2
    ctx->r8 = S32(SIGNED(ctx->r25) >> 2);
    // 0x800370AC: sh          $t0, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r8;
    // 0x800370B0: lh          $t1, -0x6($v0)
    ctx->r9 = MEM_H(ctx->r2, -0X6);
    // 0x800370B4: nop

    // 0x800370B8: multu       $t1, $a1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800370BC: mflo        $t2
    ctx->r10 = lo;
    // 0x800370C0: sra         $t3, $t2, 2
    ctx->r11 = S32(SIGNED(ctx->r10) >> 2);
    // 0x800370C4: sh          $t3, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r11;
    // 0x800370C8: lh          $t4, -0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, -0X4);
    // 0x800370CC: nop

    // 0x800370D0: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800370D4: mflo        $t5
    ctx->r13 = lo;
    // 0x800370D8: sra         $t6, $t5, 2
    ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
    // 0x800370DC: sh          $t6, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r14;
    // 0x800370E0: lh          $t7, -0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X2);
    // 0x800370E4: nop

    // 0x800370E8: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800370EC: mflo        $t8
    ctx->r24 = lo;
    // 0x800370F0: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x800370F4: bne         $v0, $a2, L_80036FD4
    if (ctx->r2 != ctx->r6) {
        // 0x800370F8: sh          $t9, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r25;
            goto L_80036FD4;
    }
    // 0x800370F8: sh          $t9, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r25;
    // 0x800370FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80037100: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80037104: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80037108: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003710C: jr          $ra
    // 0x80037110: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80037110: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void spawn_boss_hazard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E3A4: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8005E3A8: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8005E3AC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8005E3B0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8005E3B4: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x8005E3B8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8005E3BC: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8005E3C0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8005E3C4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8005E3C8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005E3CC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8005E3D0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8005E3D4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8005E3D8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8005E3DC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8005E3E0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8005E3E4: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005E3E8: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x8005E3EC: jal         0x8000E988
    // 0x8005E3F0: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    objGetObjList(rdram, ctx);
        goto after_0;
    // 0x8005E3F0: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_0:
    // 0x8005E3F4: andi        $t7, $s0, 0x100
    ctx->r15 = ctx->r16 & 0X100;
    // 0x8005E3F8: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8005E3FC: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x8005E400: sb          $s0, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r16;
    // 0x8005E404: sb          $t9, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r25;
    // 0x8005E408: lwc1        $f6, 0x38($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X38);
    // 0x8005E40C: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005E410: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8005E414: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8005E418: lw          $fp, 0x98($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X98);
    // 0x8005E41C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8005E420: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8005E424: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8005E428: nop

    // 0x8005E42C: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8005E430: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005E434: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005E438: nop

    // 0x8005E43C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8005E440: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x8005E444: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8005E448: sh          $t1, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r9;
    // 0x8005E44C: lwc1        $f6, 0x3C($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X3C);
    // 0x8005E450: lwc1        $f18, 0x10($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005E454: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8005E458: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8005E45C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8005E460: nop

    // 0x8005E464: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8005E468: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005E46C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005E470: nop

    // 0x8005E474: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8005E478: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8005E47C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8005E480: sh          $t3, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r11;
    // 0x8005E484: lwc1        $f6, 0x40($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X40);
    // 0x8005E488: lwc1        $f16, 0x14($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005E48C: mul.s       $f18, $f6, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8005E490: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8005E494: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8005E498: nop

    // 0x8005E49C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8005E4A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005E4A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005E4A8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8005E4AC: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8005E4B0: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8005E4B4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8005E4B8: blez        $t6, L_8005E61C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8005E4BC: sh          $t5, 0x6A($sp)
        MEM_H(0X6A, ctx->r29) = ctx->r13;
            goto L_8005E61C;
    }
    // 0x8005E4BC: sh          $t5, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r13;
    // 0x8005E4C0: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8005E4C4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8005E4C8: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
L_8005E4CC:
    // 0x8005E4CC: lw          $s1, 0x0($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X0);
    // 0x8005E4D0: addiu       $at, $zero, 0x6B
    ctx->r1 = ADD32(0, 0X6B);
    // 0x8005E4D4: lh          $t7, 0x48($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X48);
    // 0x8005E4D8: nop

    // 0x8005E4DC: bne         $t7, $at, L_8005E60C
    if (ctx->r15 != ctx->r1) {
        // 0x8005E4E0: lw          $t7, 0x7C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X7C);
            goto L_8005E60C;
    }
    // 0x8005E4E0: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8005E4E4: lw          $s2, 0x3C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X3C);
    // 0x8005E4E8: lb          $t8, 0x193($s7)
    ctx->r24 = MEM_B(ctx->r23, 0X193);
    // 0x8005E4EC: lb          $v0, 0x8($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X8);
    // 0x8005E4F0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8005E4F4: beq         $t9, $v0, L_8005E504
    if (ctx->r25 == ctx->r2) {
        // 0x8005E4F8: nop
    
            goto L_8005E504;
    }
    // 0x8005E4F8: nop

    // 0x8005E4FC: bne         $v0, $zero, L_8005E60C
    if (ctx->r2 != 0) {
        // 0x8005E500: lw          $t7, 0x7C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X7C);
            goto L_8005E60C;
    }
    // 0x8005E500: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_8005E504:
    // 0x8005E504: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005E508: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005E50C: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8005E510: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8005E514: lwc1        $f18, 0x10($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005E518: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005E51C: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8005E520: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005E524: lwc1        $f8, 0x14($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005E528: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005E52C: sub.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8005E530: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005E534: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8005E538: jal         0x800CA030
    // 0x8005E53C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8005E53C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_1:
    // 0x8005E540: lb          $t0, 0x9($s2)
    ctx->r8 = MEM_B(ctx->r18, 0X9);
    // 0x8005E544: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8005E548: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8005E54C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8005E550: nop

    // 0x8005E554: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005E558: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8005E55C: mul.d       $f16, $f6, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x8005E560: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x8005E564: nop

    // 0x8005E568: bc1f        L_8005E604
    if (!c1cs) {
        // 0x8005E56C: nop
    
            goto L_8005E604;
    }
    // 0x8005E56C: nop

    // 0x8005E570: lw          $t2, 0x78($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X78);
    // 0x8005E574: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005E578: bne         $t2, $zero, L_8005E608
    if (ctx->r10 != 0) {
        // 0x8005E57C: addiu       $a0, $sp, 0x64
        ctx->r4 = ADD32(ctx->r29, 0X64);
            goto L_8005E608;
    }
    // 0x8005E57C: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8005E580: sw          $t3, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->r11;
    // 0x8005E584: jal         0x8000EA54
    // 0x8005E588: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_2;
    // 0x8005E588: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8005E58C: beq         $v0, $zero, L_8005E608
    if (ctx->r2 == 0) {
        // 0x8005E590: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8005E608;
    }
    // 0x8005E590: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005E594: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8005E598: lwc1        $f18, 0x1C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x8005E59C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005E5A0: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
    // 0x8005E5A4: lwc1        $f8, 0x20($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X20);
    // 0x8005E5A8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8005E5AC: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    // 0x8005E5B0: lwc1        $f10, 0x24($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8005E5B4: sw          $s1, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r17;
    // 0x8005E5B8: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
    // 0x8005E5BC: lb          $t4, 0xA($s2)
    ctx->r12 = MEM_B(ctx->r18, 0XA);
    // 0x8005E5C0: andi        $s4, $fp, 0xFFFF
    ctx->r20 = ctx->r30 & 0XFFFF;
    // 0x8005E5C4: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8005E5C8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8005E5CC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8005E5D0: jal         0x8006FB8C
    // 0x8005E5D4: sw          $t5, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r13;
    rand_range(rdram, ctx);
        goto after_3;
    // 0x8005E5D4: sw          $t5, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r13;
    after_3:
    // 0x8005E5D8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8005E5DC: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8005E5E0: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8005E5E4: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // 0x8005E5E8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8005E5EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005E5F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005E5F4: jal         0x80009558
    // 0x8005E5F8: andi        $a0, $s4, 0xFFFF
    ctx->r4 = ctx->r20 & 0XFFFF;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_4;
    // 0x8005E5F8: andi        $a0, $s4, 0xFFFF
    ctx->r4 = ctx->r20 & 0XFFFF;
    after_4:
    // 0x8005E5FC: b           L_8005E60C
    // 0x8005E600: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
        goto L_8005E60C;
    // 0x8005E600: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_8005E604:
    // 0x8005E604: sw          $zero, 0x78($s1)
    MEM_W(0X78, ctx->r17) = 0;
L_8005E608:
    // 0x8005E608: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_8005E60C:
    // 0x8005E60C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8005E610: slt         $at, $s5, $t7
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8005E614: bne         $at, $zero, L_8005E4CC
    if (ctx->r1 != 0) {
        // 0x8005E618: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_8005E4CC;
    }
    // 0x8005E618: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_8005E61C:
    // 0x8005E61C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8005E620: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8005E624: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005E628: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8005E62C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E630: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8005E634: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8005E638: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8005E63C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E640: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8005E644: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8005E648: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8005E64C: jr          $ra
    // 0x8005E650: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8005E650: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void vec3s_rotate_rpy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070424: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80070428: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x8007042C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80070430: lh          $t3, 0x0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X0);
    // 0x80070434: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x80070438: lh          $t5, 0x4($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X4);
    // 0x8007043C: jal         0x80070A70
    // 0x80070440: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    static_3_80070A70(rdram, ctx);
        goto after_0;
    // 0x80070440: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    after_0:
    // 0x80070444: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
    // 0x80070448: jal         0x80070A6C
    // 0x8007044C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    coss_s16(rdram, ctx);
        goto after_1;
    // 0x8007044C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    after_1:
    // 0x80070450: mult        $t3, $t6
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070454: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
    // 0x80070458: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x8007045C: mflo        $t0
    ctx->r8 = lo;
    // 0x80070460: nop

    // 0x80070464: nop

    // 0x80070468: mult        $t4, $t6
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007046C: mflo        $t1
    ctx->r9 = lo;
    // 0x80070470: nop

    // 0x80070474: nop

    // 0x80070478: mult        $t3, $t7
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007047C: mflo        $t3
    ctx->r11 = lo;
    // 0x80070480: sub         $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x80070484: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80070488: mult        $t4, $t7
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007048C: mflo        $t4
    ctx->r12 = lo;
    // 0x80070490: add         $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x80070494: jal         0x80070A70
    // 0x80070498: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    static_3_80070A70(rdram, ctx);
        goto after_2;
    // 0x80070498: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    after_2:
    // 0x8007049C: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
    // 0x800704A0: jal         0x80070A6C
    // 0x800704A4: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    coss_s16(rdram, ctx);
        goto after_3;
    // 0x800704A4: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    after_3:
    // 0x800704A8: mult        $t4, $t6
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800704AC: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
    // 0x800704B0: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    // 0x800704B4: mflo        $t0
    ctx->r8 = lo;
    // 0x800704B8: nop

    // 0x800704BC: nop

    // 0x800704C0: mult        $t5, $t6
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800704C4: mflo        $t1
    ctx->r9 = lo;
    // 0x800704C8: nop

    // 0x800704CC: nop

    // 0x800704D0: mult        $t4, $t7
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800704D4: mflo        $t4
    ctx->r12 = lo;
    // 0x800704D8: sub         $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x800704DC: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800704E0: mult        $t5, $t7
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800704E4: mflo        $t5
    ctx->r13 = lo;
    // 0x800704E8: add         $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x800704EC: jal         0x80070A70
    // 0x800704F0: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    static_3_80070A70(rdram, ctx);
        goto after_4;
    // 0x800704F0: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    after_4:
    // 0x800704F4: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
    // 0x800704F8: jal         0x80070A6C
    // 0x800704FC: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    coss_s16(rdram, ctx);
        goto after_5;
    // 0x800704FC: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    after_5:
    // 0x80070500: mult        $t3, $t6
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070504: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
    // 0x80070508: sh          $t4, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r12;
    // 0x8007050C: mflo        $t0
    ctx->r8 = lo;
    // 0x80070510: nop

    // 0x80070514: nop

    // 0x80070518: mult        $t5, $t6
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007051C: mflo        $t1
    ctx->r9 = lo;
    // 0x80070520: nop

    // 0x80070524: nop

    // 0x80070528: mult        $t3, $t7
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007052C: mflo        $t3
    ctx->r11 = lo;
    // 0x80070530: add         $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80070534: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80070538: mult        $t5, $t7
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007053C: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x80070540: mflo        $t5
    ctx->r13 = lo;
    // 0x80070544: sub         $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x80070548: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8007054C: sh          $t5, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r13;
    // 0x80070550: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070554: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070558: jr          $ra
    // 0x8007055C: nop

    return;
    // 0x8007055C: nop

;}
RECOMP_FUNC void process_onscreen_textbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3998: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C399C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C39A0: lb          $t6, 0x3C00($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3C00);
    // 0x800C39A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C39A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C39AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C39B0: beq         $t6, $zero, L_800C3AA8
    if (ctx->r14 == 0) {
        // 0x800C39B4: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_800C3AA8;
    }
    // 0x800C39B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C39B8: jal         0x8006ECE0
    // 0x800C39BC: nop

    is_game_paused(rdram, ctx);
        goto after_0;
    // 0x800C39BC: nop

    after_0:
    // 0x800C39C0: bne         $v0, $zero, L_800C39F8
    if (ctx->r2 != 0) {
        // 0x800C39C4: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_800C39F8;
    }
    // 0x800C39C4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800C39C8: addiu       $s0, $s0, 0x3C08
    ctx->r16 = ADD32(ctx->r16, 0X3C08);
    // 0x800C39CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800C39D0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800C39D4: blez        $v0, L_800C39F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C39D8: subu        $t8, $v0, $t7
        ctx->r24 = SUB32(ctx->r2, ctx->r15);
            goto L_800C39F8;
    }
    // 0x800C39D8: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x800C39DC: bgtz        $t8, L_800C39F8
    if (SIGNED(ctx->r24) > 0) {
        // 0x800C39E0: sw          $t8, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r24;
            goto L_800C39F8;
    }
    // 0x800C39E0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800C39E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C39E8: lw          $a0, 0x3C0C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C0C);
    // 0x800C39EC: jal         0x800C3744
    // 0x800C39F0: nop

    set_current_text(rdram, ctx);
        goto after_1;
    // 0x800C39F0: nop

    after_1:
    // 0x800C39F4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800C39F8:
    // 0x800C39F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C39FC: jal         0x800C3474
    // 0x800C3A00: nop

    process_subtitles(rdram, ctx);
        goto after_2;
    // 0x800C3A00: nop

    after_2:
    // 0x800C3A04: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C3A08: lbu         $t0, -0x52B7($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X52B7);
    // 0x800C3A0C: nop

    // 0x800C3A10: beq         $t0, $zero, L_800C3AAC
    if (ctx->r8 == 0) {
        // 0x800C3A14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C3AAC;
    }
    // 0x800C3A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3A18: jal         0x8005A41C
    // 0x800C3A1C: nop

    disable_racer_input(rdram, ctx);
        goto after_3;
    // 0x800C3A1C: nop

    after_3:
    // 0x800C3A20: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C3A24: addiu       $s1, $s1, -0x52BA
    ctx->r17 = ADD32(ctx->r17, -0X52BA);
    // 0x800C3A28: lb          $v0, 0x0($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X0);
    // 0x800C3A2C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C3A30: beq         $v0, $zero, L_800C3AA0
    if (ctx->r2 == 0) {
        // 0x800C3A34: addiu       $s0, $s0, -0x52BB
        ctx->r16 = ADD32(ctx->r16, -0X52BB);
            goto L_800C3AA0;
    }
    // 0x800C3A34: addiu       $s0, $s0, -0x52BB
    ctx->r16 = ADD32(ctx->r16, -0X52BB);
    // 0x800C3A38: lb          $t1, 0x0($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X0);
    // 0x800C3A3C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800C3A40: nop

    // 0x800C3A44: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x800C3A48: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x800C3A4C: lb          $t4, 0x0($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X0);
    // 0x800C3A50: nop

    // 0x800C3A54: bgez        $t4, L_800C3A90
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800C3A58: nop
    
            goto L_800C3A90;
    }
    // 0x800C3A58: nop

L_800C3A5C:
    // 0x800C3A5C: jal         0x8000C8B4
    // 0x800C3A60: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    normalise_time(rdram, ctx);
        goto after_4;
    // 0x800C3A60: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_4:
    // 0x800C3A64: lb          $t5, 0x0($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X0);
    // 0x800C3A68: lb          $t7, 0x0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X0);
    // 0x800C3A6C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C3A70: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x800C3A74: lb          $t9, 0x0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X0);
    // 0x800C3A78: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800C3A7C: bltz        $t9, L_800C3A5C
    if (SIGNED(ctx->r25) < 0) {
        // 0x800C3A80: sb          $t8, 0x0($s1)
        MEM_B(0X0, ctx->r17) = ctx->r24;
            goto L_800C3A5C;
    }
    // 0x800C3A80: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800C3A84: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C3A88: lb          $v0, -0x52BA($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X52BA);
    // 0x800C3A8C: nop

L_800C3A90:
    // 0x800C3A90: bgtz        $v0, L_800C3AA0
    if (SIGNED(ctx->r2) > 0) {
        // 0x800C3A94: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800C3AA0;
    }
    // 0x800C3A94: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C3A98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3A9C: sb          $t0, -0x52BC($at)
    MEM_B(-0X52BC, ctx->r1) = ctx->r8;
L_800C3AA0:
    // 0x800C3AA0: jal         0x8009D530
    // 0x800C3AA4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    npc_dialogue_loop(rdram, ctx);
        goto after_5;
    // 0x800C3AA4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_5:
L_800C3AA8:
    // 0x800C3AA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C3AAC:
    // 0x800C3AAC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C3AB0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C3AB4: jr          $ra
    // 0x800C3AB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C3AB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void __sinf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5180: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800D5184: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x800D5188: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D518C: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800D5190: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x800D5194: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x800D5198: beq         $at, $zero, L_800D5200
    if (ctx->r1 == 0) {
        // 0x800D519C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800D5200;
    }
    // 0x800D519C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800D51A0: slti        $at, $t6, 0xE6
    ctx->r1 = SIGNED(ctx->r14) < 0XE6 ? 1 : 0;
    // 0x800D51A4: bne         $at, $zero, L_800D51F8
    if (ctx->r1 != 0) {
        // 0x800D51A8: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_800D51F8;
    }
    // 0x800D51A8: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800D51AC: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800D51B0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800D51B4: addiu       $v1, $v1, -0x6270
    ctx->r3 = ADD32(ctx->r3, -0X6270);
    // 0x800D51B8: ldc1        $f6, 0x20($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X20);
    // 0x800D51BC: ldc1        $f10, 0x18($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X18);
    // 0x800D51C0: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800D51C4: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800D51C8: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800D51CC: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800D51D0: mul.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x800D51D4: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x800D51D8: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800D51DC: add.d       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f14.d = ctx->f10.d + ctx->f8.d;
    // 0x800D51E0: mul.d       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800D51E4: nop

    // 0x800D51E8: mul.d       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f14.d);
    // 0x800D51EC: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x800D51F0: jr          $ra
    // 0x800D51F4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x800D51F4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_800D51F8:
    // 0x800D51F8: jr          $ra
    // 0x800D51FC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    return;
    // 0x800D51FC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
L_800D5200:
    // 0x800D5200: slti        $at, $v1, 0x136
    ctx->r1 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x800D5204: beq         $at, $zero, L_800D5318
    if (ctx->r1 == 0) {
        // 0x800D5208: lwc1        $f4, 0x0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
            goto L_800D5318;
    }
    // 0x800D5208: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D520C: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D5210: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5214: ldc1        $f10, -0x6248($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6248);
    // 0x800D5218: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x800D521C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800D5220: mul.d       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x800D5224: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D5228: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D522C: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x800D5230: nop

    // 0x800D5234: bc1fl       L_800D5264
    if (!c1cs) {
        // 0x800D5238: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_800D5264;
    }
    goto skip_0;
    // 0x800D5238: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800D523C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D5240: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D5244: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D5248: nop

    // 0x800D524C: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x800D5250: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x800D5254: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800D5258: b           L_800D5280
    // 0x800D525C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_800D5280;
    // 0x800D525C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800D5260: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_800D5264:
    // 0x800D5264: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800D5268: nop

    // 0x800D526C: sub.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d - ctx->f6.d;
    // 0x800D5270: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800D5274: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800D5278: nop

    // 0x800D527C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_800D5280:
    // 0x800D5280: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5284: ldc1        $f18, -0x6240($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X6240);
    // 0x800D5288: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x800D528C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5290: ldc1        $f6, -0x6238($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6238);
    // 0x800D5294: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800D5298: addiu       $v1, $v1, -0x6270
    ctx->r3 = ADD32(ctx->r3, -0X6270);
    // 0x800D529C: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x800D52A0: ldc1        $f8, 0x20($v1)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r3, 0X20);
    // 0x800D52A4: ldc1        $f18, 0x18($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X18);
    // 0x800D52A8: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800D52AC: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800D52B0: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x800D52B4: sub.d       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f2.d - ctx->f10.d;
    // 0x800D52B8: ldc1        $f10, 0x10($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X10);
    // 0x800D52BC: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800D52C0: nop

    // 0x800D52C4: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800D52C8: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800D52CC: ldc1        $f18, 0x8($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X8);
    // 0x800D52D0: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x800D52D4: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x800D52D8: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800D52DC: bne         $t9, $zero, L_800D52FC
    if (ctx->r25 != 0) {
        // 0x800D52E0: add.d       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
            goto L_800D52FC;
    }
    // 0x800D52E0: add.d       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
    // 0x800D52E4: mul.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800D52E8: nop

    // 0x800D52EC: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x800D52F0: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800D52F4: jr          $ra
    // 0x800D52F8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800D52F8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800D52FC:
    // 0x800D52FC: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800D5300: nop

    // 0x800D5304: mul.d       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x800D5308: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x800D530C: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x800D5310: jr          $ra
    // 0x800D5314: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x800D5314: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800D5318:
    // 0x800D5318: c.eq.s      $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f4.fl == ctx->f4.fl;
    // 0x800D531C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5320: bc1t        L_800D5334
    if (c1cs) {
        // 0x800D5324: nop
    
            goto L_800D5334;
    }
    // 0x800D5324: nop

    // 0x800D5328: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D532C: jr          $ra
    // 0x800D5330: lwc1        $f0, -0x61C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X61C0);
    return;
    // 0x800D5330: lwc1        $f0, -0x61C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X61C0);
L_800D5334:
    // 0x800D5334: lwc1        $f0, -0x6230($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6230);
    // 0x800D5338: jr          $ra
    // 0x800D533C: nop

    return;
    // 0x800D533C: nop

;}
RECOMP_FUNC void alAudioFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800656D4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800656D8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800656DC: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800656E0: lw          $s2, 0x3D10($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X3D10);
    // 0x800656E4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800656E8: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x800656EC: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x800656F0: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800656F4: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800656F8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800656FC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80065700: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80065704: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80065708: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x8006570C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80065710: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80065714: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x80065718: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8006571C: bne         $t6, $zero, L_80065730
    if (ctx->r14 != 0) {
        // 0x80065720: or          $s5, $a2, $zero
        ctx->r21 = ctx->r6 | 0;
            goto L_80065730;
    }
    // 0x80065720: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80065724: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80065728: b           L_8006587C
    // 0x8006572C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8006587C;
    // 0x8006572C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80065730:
    // 0x80065730: addiu       $s0, $sp, 0x6C
    ctx->r16 = ADD32(ctx->r29, 0X6C);
    // 0x80065734: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80065738: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8006573C: jal         0x80065A2C
    // 0x80065740: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    static_3_80065A2C(rdram, ctx);
        goto after_0;
    // 0x80065740: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    after_0:
    // 0x80065744: lw          $t8, 0x20($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X20);
    // 0x80065748: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x8006574C: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x80065750: slt         $at, $t9, $s3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80065754: beq         $at, $zero, L_800657C4
    if (ctx->r1 == 0) {
        // 0x80065758: addiu       $s1, $zero, -0x10
        ctx->r17 = ADD32(0, -0X10);
            goto L_800657C4;
    }
    // 0x80065758: addiu       $s1, $zero, -0x10
    ctx->r17 = ADD32(0, -0X10);
L_8006575C:
    // 0x8006575C: lw          $t0, 0x1C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X1C);
    // 0x80065760: nop

    // 0x80065764: and         $t1, $t0, $s1
    ctx->r9 = ctx->r8 & ctx->r17;
    // 0x80065768: sw          $t1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r9;
    // 0x8006576C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80065770: nop

    // 0x80065774: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80065778: nop

    // 0x8006577C: jalr        $t9
    // 0x80065780: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80065780: nop

    after_1:
    // 0x80065784: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80065788: jal         0x80065994
    // 0x8006578C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    static_3_80065994(rdram, ctx);
        goto after_2;
    // 0x8006578C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80065790: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80065794: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80065798: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8006579C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800657A0: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800657A4: jal         0x80065A2C
    // 0x800657A8: sw          $t5, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r13;
    static_3_80065A2C(rdram, ctx);
        goto after_3;
    // 0x800657A8: sw          $t5, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r13;
    after_3:
    // 0x800657AC: lw          $t6, 0x20($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X20);
    // 0x800657B0: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x800657B4: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x800657B8: slt         $at, $t7, $s3
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800657BC: bne         $at, $zero, L_8006575C
    if (ctx->r1 != 0) {
        // 0x800657C0: nop
    
            goto L_8006575C;
    }
    // 0x800657C0: nop

L_800657C4:
    // 0x800657C4: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
    // 0x800657C8: addiu       $s1, $zero, -0x10
    ctx->r17 = ADD32(0, -0X10);
    // 0x800657CC: and         $t0, $t8, $s1
    ctx->r8 = ctx->r24 & ctx->r17;
    // 0x800657D0: blez        $s3, L_8006585C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800657D4: sw          $t0, 0x1C($s2)
        MEM_W(0X1C, ctx->r18) = ctx->r8;
            goto L_8006585C;
    }
    // 0x800657D4: sw          $t0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r8;
    // 0x800657D8: addiu       $s7, $sp, 0x62
    ctx->r23 = ADD32(ctx->r29, 0X62);
    // 0x800657DC: lui         $s6, 0x700
    ctx->r22 = S32(0X700 << 16);
L_800657E0:
    // 0x800657E0: lw          $v0, 0x48($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X48);
    // 0x800657E4: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x800657E8: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800657EC: beq         $at, $zero, L_800657FC
    if (ctx->r1 == 0) {
        // 0x800657F0: nop
    
            goto L_800657FC;
    }
    // 0x800657F0: nop

    // 0x800657F4: b           L_800657FC
    // 0x800657F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800657FC;
    // 0x800657F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800657FC:
    // 0x800657FC: sw          $s6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r22;
    // 0x80065800: sw          $zero, 0x4($s4)
    MEM_W(0X4, ctx->r20) = 0;
    // 0x80065804: lw          $s1, 0x38($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X38);
    // 0x80065808: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8006580C: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80065810: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80065814: jalr        $t9
    // 0x80065818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80065818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8006581C: lw          $a3, 0x20($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X20);
    // 0x80065820: addiu       $t1, $s4, 0x8
    ctx->r9 = ADD32(ctx->r20, 0X8);
    // 0x80065824: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80065828: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x8006582C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80065830: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80065834: jalr        $t9
    // 0x80065838: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x80065838: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x8006583C: lw          $t5, 0x20($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X20);
    // 0x80065840: subu        $s3, $s3, $s0
    ctx->r19 = SUB32(ctx->r19, ctx->r16);
    // 0x80065844: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80065848: addu        $t3, $t5, $s0
    ctx->r11 = ADD32(ctx->r13, ctx->r16);
    // 0x8006584C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80065850: addu        $s5, $s5, $t4
    ctx->r21 = ADD32(ctx->r21, ctx->r12);
    // 0x80065854: bgtz        $s3, L_800657E0
    if (SIGNED(ctx->r19) > 0) {
        // 0x80065858: sw          $t3, 0x20($s2)
        MEM_W(0X20, ctx->r18) = ctx->r11;
            goto L_800657E0;
    }
    // 0x80065858: sw          $t3, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r11;
L_8006585C:
    // 0x8006585C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80065860: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80065864: subu        $t7, $s4, $t6
    ctx->r15 = SUB32(ctx->r20, ctx->r14);
    // 0x80065868: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8006586C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80065870: jal         0x800658FC
    // 0x80065874: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    _collectPVoices(rdram, ctx);
        goto after_6;
    // 0x80065874: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    after_6:
    // 0x80065878: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_8006587C:
    // 0x8006587C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80065880: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80065884: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80065888: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8006588C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80065890: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80065894: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80065898: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x8006589C: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x800658A0: jr          $ra
    // 0x800658A4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800658A4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void cam_set_zoom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800662A0: bltz        $a0, L_800662D0
    if (SIGNED(ctx->r4) < 0) {
        // 0x800662A4: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_800662D0;
    }
    // 0x800662A4: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x800662A8: beq         $at, $zero, L_800662D0
    if (ctx->r1 == 0) {
        // 0x800662AC: sll         $t6, $a0, 4
        ctx->r14 = S32(ctx->r4 << 4);
            goto L_800662D0;
    }
    // 0x800662AC: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800662B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800662B4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800662B8: sb          $a1, -0x2798($at)
    MEM_B(-0X2798, ctx->r1) = ctx->r5;
    // 0x800662BC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800662C0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800662C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800662C8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800662CC: sb          $a1, 0x107B($at)
    MEM_B(0X107B, ctx->r1) = ctx->r5;
L_800662D0:
    // 0x800662D0: jr          $ra
    // 0x800662D4: nop

    return;
    // 0x800662D4: nop

;}
RECOMP_FUNC void sndp_stop_all_retrigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800049B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800049BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800049C0: jal         0x800048D8
    // 0x800049C4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    sndp_stop_with_flags(rdram, ctx);
        goto after_0;
    // 0x800049C4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_0:
    // 0x800049C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800049CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800049D0: jr          $ra
    // 0x800049D4: nop

    return;
    // 0x800049D4: nop

;}
RECOMP_FUNC void postrace_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094F60: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80094F64: addiu       $v1, $v1, 0x7230
    ctx->r3 = ADD32(ctx->r3, 0X7230);
    // 0x80094F68: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80094F6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80094F70: bltz        $v0, L_80095108
    if (SIGNED(ctx->r2) < 0) {
        // 0x80094F74: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80095108;
    }
    // 0x80094F74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094F78: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80094F7C: beq         $at, $zero, L_80094F90
    if (ctx->r1 == 0) {
        // 0x80094F80: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_80094F90;
    }
    // 0x80094F80: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80094F84: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80094F88: b           L_80095108
    // 0x80094F8C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_80095108;
    // 0x80094F8C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80094F90:
    // 0x80094F90: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80094F94: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80094F98: lh          $a0, 0xF90($a0)
    ctx->r4 = MEM_H(ctx->r4, 0XF90);
    // 0x80094F9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80094FA0: bne         $a0, $at, L_800950EC
    if (ctx->r4 != ctx->r1) {
        // 0x80094FA4: nop
    
            goto L_800950EC;
    }
    // 0x80094FA4: nop

    // 0x80094FA8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80094FAC: jal         0x8009CDE8
    // 0x80094FB0: addiu       $a0, $a0, 0xFC0
    ctx->r4 = ADD32(ctx->r4, 0XFC0);
    menu_imagegroup_load(rdram, ctx);
        goto after_0;
    // 0x80094FB0: addiu       $a0, $a0, 0xFC0
    ctx->r4 = ADD32(ctx->r4, 0XFC0);
    after_0:
    // 0x80094FB4: jal         0x80094B08
    // 0x80094FB8: nop

    menu_racer_portraits(rdram, ctx);
        goto after_1;
    // 0x80094FB8: nop

    after_1:
    // 0x80094FBC: jal         0x8006ECD0
    // 0x80094FC0: nop

    get_settings(rdram, ctx);
        goto after_2;
    // 0x80094FC0: nop

    after_2:
    // 0x80094FC4: lb          $t8, 0x114($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X114);
    // 0x80094FC8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80094FCC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80094FD0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80094FD4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80094FD8: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x80094FDC: lb          $t3, 0x59($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X59);
    // 0x80094FE0: addiu       $a1, $a1, 0x1070
    ctx->r5 = ADD32(ctx->r5, 0X1070);
    // 0x80094FE4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80094FE8: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x80094FEC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80094FF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094FF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80094FF8: jal         0x8000E4C8
    // 0x80094FFC: sw          $t6, 0x1180($at)
    MEM_W(0X1180, ctx->r1) = ctx->r14;
    is_time_trial_enabled(rdram, ctx);
        goto after_3;
    // 0x80094FFC: sw          $t6, 0x1180($at)
    MEM_W(0X1180, ctx->r1) = ctx->r14;
    after_3:
    // 0x80095000: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80095004: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80095008: bne         $v0, $zero, L_800950DC
    if (ctx->r2 != 0) {
        // 0x8009500C: addiu       $a1, $a1, 0x1070
        ctx->r5 = ADD32(ctx->r5, 0X1070);
            goto L_800950DC;
    }
    // 0x8009500C: addiu       $a1, $a1, 0x1070
    ctx->r5 = ADD32(ctx->r5, 0X1070);
    // 0x80095010: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80095014: addiu       $a2, $a2, 0x134C
    ctx->r6 = ADD32(ctx->r6, 0X134C);
    // 0x80095018: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009501C: addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    // 0x80095020: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80095024:
    // 0x80095024: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80095028:
    // 0x80095028: lb          $t7, 0x5A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X5A);
    // 0x8009502C: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80095030: bne         $a0, $t7, L_80095054
    if (ctx->r4 != ctx->r15) {
        // 0x80095034: sll         $t4, $a0, 5
        ctx->r12 = S32(ctx->r4 << 5);
            goto L_80095054;
    }
    // 0x80095034: sll         $t4, $a0, 5
    ctx->r12 = S32(ctx->r4 << 5);
    // 0x80095038: lb          $t8, 0x59($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X59);
    // 0x8009503C: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x80095040: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80095044: addu        $t2, $a1, $t9
    ctx->r10 = ADD32(ctx->r5, ctx->r25);
    // 0x80095048: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8009504C: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x80095050: sw          $t3, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r11;
L_80095054:
    // 0x80095054: bne         $v1, $a3, L_80095028
    if (ctx->r3 != ctx->r7) {
        // 0x80095058: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_80095028;
    }
    // 0x80095058: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x8009505C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80095060: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x80095064: bne         $at, $zero, L_80095024
    if (ctx->r1 != 0) {
        // 0x80095068: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80095024;
    }
    // 0x80095068: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009506C: jal         0x8009F1C4
    // 0x80095070: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_4;
    // 0x80095070: nop

    after_4:
    // 0x80095074: beq         $v0, $zero, L_800950DC
    if (ctx->r2 == 0) {
        // 0x80095078: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800950DC;
    }
    // 0x80095078: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009507C: lw          $t7, 0x12C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X12C0);
    // 0x80095080: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095084: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80095088: sw          $t7, 0x12A0($at)
    MEM_W(0X12A0, ctx->r1) = ctx->r15;
    // 0x8009508C: lw          $t8, 0x12E0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X12E0);
    // 0x80095090: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80095094: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80095098: addiu       $v1, $v1, 0x126C
    ctx->r3 = ADD32(ctx->r3, 0X126C);
    // 0x8009509C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800950A0: sll         $t9, $a0, 5
    ctx->r25 = S32(ctx->r4 << 5);
    // 0x800950A4: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x800950A8: sw          $t8, 0x12C0($at)
    MEM_W(0X12C0, ctx->r1) = ctx->r24;
    // 0x800950AC: lw          $t5, 0x94($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X94);
    // 0x800950B0: lw          $t3, 0xB4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XB4);
    // 0x800950B4: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x800950B8: lw          $t2, 0x54($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X54);
    // 0x800950BC: sw          $t5, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r13;
    // 0x800950C0: sw          $t3, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r11;
    // 0x800950C4: sw          $t4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r12;
    // 0x800950C8: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
    // 0x800950CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800950D0: addiu       $v0, $v0, 0x6DF0
    ctx->r2 = ADD32(ctx->r2, 0X6DF0);
    // 0x800950D4: sw          $v0, 0xF4($v1)
    MEM_W(0XF4, ctx->r3) = ctx->r2;
    // 0x800950D8: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_800950DC:
    // 0x800950DC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800950E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800950E4: b           L_80095108
    // 0x800950E8: sw          $t6, 0x7230($at)
    MEM_W(0X7230, ctx->r1) = ctx->r14;
        goto L_80095108;
    // 0x800950E8: sw          $t6, 0x7230($at)
    MEM_W(0X7230, ctx->r1) = ctx->r14;
L_800950EC:
    // 0x800950EC: jal         0x8009CC18
    // 0x800950F0: nop

    menu_asset_load(rdram, ctx);
        goto after_5;
    // 0x800950F0: nop

    after_5:
    // 0x800950F4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800950F8: lw          $t7, 0x7230($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7230);
    // 0x800950FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095100: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80095104: sw          $t8, 0x7230($at)
    MEM_W(0X7230, ctx->r1) = ctx->r24;
L_80095108:
    // 0x80095108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009510C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80095110: jr          $ra
    // 0x80095114: nop

    return;
    // 0x80095114: nop

;}
RECOMP_FUNC void interrupts_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F77C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006F780: lb          $t0, -0x2660($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2660);
    // 0x8006F784: beq         $t0, $zero, L_8006F79C
    if (ctx->r8 == 0) {
        // 0x8006F788: mfc0        $t0, Status
        ctx->r8 = cop0_status_read(ctx);
            goto L_8006F79C;
    }
    // 0x8006F788: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x8006F78C: or          $t0, $t0, $a0
    ctx->r8 = ctx->r8 | ctx->r4;
    // 0x8006F790: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x8006F794: nop

    // 0x8006F798: nop

L_8006F79C:
    // 0x8006F79C: jr          $ra
    // 0x8006F7A0: nop

    return;
    // 0x8006F7A0: nop

;}
RECOMP_FUNC void obj_init_midifadepoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041EC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80041EC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80041EC8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80041ECC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80041ED0: lw          $a2, 0x64($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X64);
    // 0x80041ED4: lhu         $t6, 0xA($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XA);
    // 0x80041ED8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80041EDC: sh          $t6, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r14;
    // 0x80041EE0: lhu         $t7, 0x8($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X8);
    // 0x80041EE4: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x80041EE8: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x80041EEC: lbu         $t8, 0x1C($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1C);
    // 0x80041EF0: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    // 0x80041EF4: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80041EF8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80041EFC: beq         $at, $zero, L_80041F0C
    if (ctx->r1 == 0) {
        // 0x80041F00: sb          $t8, 0x1C($a2)
        MEM_B(0X1C, ctx->r6) = ctx->r24;
            goto L_80041F0C;
    }
    // 0x80041F00: sb          $t8, 0x1C($a2)
    MEM_B(0X1C, ctx->r6) = ctx->r24;
    // 0x80041F04: addiu       $t0, $v0, 0xA
    ctx->r8 = ADD32(ctx->r2, 0XA);
    // 0x80041F08: sh          $t0, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r8;
L_80041F0C:
    // 0x80041F0C: sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // 0x80041F10: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x80041F14: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x80041F18: lbu         $t1, 0xC($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XC);
    // 0x80041F1C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80041F20: sb          $t1, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r9;
    // 0x80041F24: lbu         $t2, 0xD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XD);
    // 0x80041F28: addiu       $v0, $a2, 0x3
    ctx->r2 = ADD32(ctx->r6, 0X3);
    // 0x80041F2C: sb          $t2, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r10;
    // 0x80041F30: lbu         $t3, 0xE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XE);
    // 0x80041F34: addiu       $v1, $s0, 0x3
    ctx->r3 = ADD32(ctx->r16, 0X3);
    // 0x80041F38: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80041F3C: sb          $t3, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r11;
L_80041F40:
    // 0x80041F40: lbu         $t4, 0xC($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XC);
    // 0x80041F44: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80041F48: sb          $t4, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r12;
    // 0x80041F4C: lbu         $t5, 0xD($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XD);
    // 0x80041F50: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80041F54: sb          $t5, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r13;
    // 0x80041F58: lbu         $t6, 0xE($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XE);
    // 0x80041F5C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80041F60: sb          $t6, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r14;
    // 0x80041F64: lbu         $t7, 0xB($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XB);
    // 0x80041F68: bne         $a0, $a1, L_80041F40
    if (ctx->r4 != ctx->r5) {
        // 0x80041F6C: sb          $t7, 0xB($v0)
        MEM_B(0XB, ctx->r2) = ctx->r15;
            goto L_80041F40;
    }
    // 0x80041F6C: sb          $t7, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r15;
    // 0x80041F70: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    // 0x80041F74: nop

    // 0x80041F78: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x80041F7C: nop

    // 0x80041F80: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80041F84: nop

    // 0x80041F88: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80041F8C: nop

    // 0x80041F90: lh          $t9, 0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA);
    // 0x80041F94: lh          $t0, 0xC($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XC);
    // 0x80041F98: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80041F9C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80041FA0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80041FA4: lh          $t1, 0xE($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XE);
    // 0x80041FA8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80041FAC: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80041FB0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80041FB4: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80041FB8: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80041FBC: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80041FC0: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80041FC4: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80041FC8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80041FCC: jal         0x800CA030
    // 0x80041FD0: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80041FD0: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x80041FD4: lhu         $t2, 0x8($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X8);
    // 0x80041FD8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80041FDC: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80041FE0: bgez        $t2, L_80041FF8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80041FE4: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80041FF8;
    }
    // 0x80041FE4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80041FE8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80041FEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80041FF0: nop

    // 0x80041FF4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80041FF8:
    // 0x80041FF8: nop

    // 0x80041FFC: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80042000: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80042004: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x80042008: lhu         $t3, 0xA($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XA);
    // 0x8004200C: nop

    // 0x80042010: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80042014: bgez        $t3, L_80042028
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80042018: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80042028;
    }
    // 0x80042018: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8004201C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80042020: nop

    // 0x80042024: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80042028:
    // 0x80042028: nop

    // 0x8004202C: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80042030: swc1        $f10, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
    // 0x80042034: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80042038: nop

    // 0x8004203C: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    // 0x80042040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80042044: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80042048: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004204C: jr          $ra
    // 0x80042050: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80042050: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mode_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DF38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DF3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006DF40: lb          $t6, 0x3A94($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3A94);
    // 0x8006DF44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006DF48: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    // 0x8006DF4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DF50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006DF54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006DF58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8006DF5C: bne         $t6, $zero, L_8006DF80
    if (ctx->r14 != 0) {
        // 0x8006DF60: sb          $zero, 0x3A96($at)
        MEM_B(0X3A96, ctx->r1) = 0;
            goto L_8006DF80;
    }
    // 0x8006DF60: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    // 0x8006DF64: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006DF68: lw          $t7, 0x3A70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3A70);
    // 0x8006DF6C: nop

    // 0x8006DF70: beq         $t7, $zero, L_8006DF84
    if (ctx->r15 == 0) {
        // 0x8006DF74: lw          $t8, 0x30($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X30);
            goto L_8006DF84;
    }
    // 0x8006DF74: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8006DF78: jal         0x8006DE98
    // 0x8006DF7C: nop

    update_menu_scene(rdram, ctx);
        goto after_0;
    // 0x8006DF7C: nop

    after_0:
L_8006DF80:
    // 0x8006DF80: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
L_8006DF84:
    // 0x8006DF84: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006DF88: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
    // 0x8006DF8C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006DF90: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006DF94: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006DF98: addiu       $a3, $a3, 0x17A8
    ctx->r7 = ADD32(ctx->r7, 0X17A8);
    // 0x8006DF9C: addiu       $a2, $a2, 0x1798
    ctx->r6 = ADD32(ctx->r6, 0X1798);
    // 0x8006DFA0: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    // 0x8006DFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006DFA8: jal         0x800819F4
    // 0x8006DFAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    menu_loop(rdram, ctx);
        goto after_1;
    // 0x8006DFAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x8006DFB0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006DFB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DFB8: sw          $t9, 0x3A70($at)
    MEM_W(0X3A70, ctx->r1) = ctx->r25;
    // 0x8006DFBC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8006DFC0: bne         $v0, $at, L_8006DFD4
    if (ctx->r2 != ctx->r1) {
        // 0x8006DFC4: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_8006DFD4;
    }
    // 0x8006DFC4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8006DFC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DFCC: b           L_8006E518
    // 0x8006DFD0: sw          $zero, 0x3A70($at)
    MEM_W(0X3A70, ctx->r1) = 0;
        goto L_8006E518;
    // 0x8006DFD0: sw          $zero, 0x3A70($at)
    MEM_W(0X3A70, ctx->r1) = 0;
L_8006DFD4:
    // 0x8006DFD4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8006DFD8: beq         $v0, $v1, L_8006E0D0
    if (ctx->r2 == ctx->r3) {
        // 0x8006DFDC: andi        $t4, $v0, 0x200
        ctx->r12 = ctx->r2 & 0X200;
            goto L_8006E0D0;
    }
    // 0x8006DFDC: andi        $t4, $v0, 0x200
    ctx->r12 = ctx->r2 & 0X200;
    // 0x8006DFE0: beq         $t4, $zero, L_8006E0D0
    if (ctx->r12 == 0) {
        // 0x8006DFE4: nop
    
            goto L_8006E0D0;
    }
    // 0x8006DFE4: nop

    // 0x8006DFE8: jal         0x8006DE24
    // 0x8006DFEC: nop

    unload_level_menu(rdram, ctx);
        goto after_2;
    // 0x8006DFEC: nop

    after_2:
    // 0x8006DFF0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006DFF4: lw          $t5, 0x3A68($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3A68);
    // 0x8006DFF8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006DFFC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006E000: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8006E004: lw          $t7, 0x1770($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1770);
    // 0x8006E008: lui         $t9, 0xE900
    ctx->r25 = S32(0XE900 << 16);
    // 0x8006E00C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8006E010: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8006E014: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8006E018: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8006E01C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8006E020: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006E024: lui         $t5, 0xB800
    ctx->r13 = S32(0XB800 << 16);
    // 0x8006E028: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8006E02C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8006E030: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006E034: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8006E038: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E03C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E040: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E044: andi        $a0, $t6, 0x7F
    ctx->r4 = ctx->r14 & 0X7F;
    // 0x8006E048: jal         0x8006B2EC
    // 0x8006E04C: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    leveltable_vehicle_default(rdram, ctx);
        goto after_3;
    // 0x8006E04C: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    after_3:
    // 0x8006E050: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E054: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E058: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006E05C: addiu       $t3, $t3, 0x3A88
    ctx->r11 = ADD32(ctx->r11, 0X3A88);
    // 0x8006E060: addiu       $t2, $t2, 0x3A98
    ctx->r10 = ADD32(ctx->r10, 0X3A98);
    // 0x8006E064: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E068: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8006E06C: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x8006E070: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8006E074: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8006E078: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E07C: sw          $zero, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = 0;
    // 0x8006E080: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E084: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    // 0x8006E088: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E08C: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    // 0x8006E090: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E094: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E098: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E09C: addiu       $v1, $v1, 0x3A80
    ctx->r3 = ADD32(ctx->r3, 0X3A80);
    // 0x8006E0A0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8006E0A4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006E0A8: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8006E0AC: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006E0B0: jal         0x8006CD98
    // 0x8006E0B4: nop

    load_level_game(rdram, ctx);
        goto after_4;
    // 0x8006E0B4: nop

    after_4:
    // 0x8006E0B8: jal         0x8009C6E4
    // 0x8006E0BC: nop

    get_save_file_index(rdram, ctx);
        goto after_5;
    // 0x8006E0BC: nop

    after_5:
    // 0x8006E0C0: jal         0x8006EE88
    // 0x8006E0C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_6;
    // 0x8006E0C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8006E0C8: b           L_8006E51C
    // 0x8006E0CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E51C;
    // 0x8006E0CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E0D0:
    // 0x8006E0D0: beq         $v0, $v1, L_8006E338
    if (ctx->r2 == ctx->r3) {
        // 0x8006E0D4: andi        $t9, $v0, 0x100
        ctx->r25 = ctx->r2 & 0X100;
            goto L_8006E338;
    }
    // 0x8006E0D4: andi        $t9, $v0, 0x100
    ctx->r25 = ctx->r2 & 0X100;
    // 0x8006E0D8: beq         $t9, $zero, L_8006E33C
    if (ctx->r25 == 0) {
        // 0x8006E0DC: andi        $t4, $v0, 0x80
        ctx->r12 = ctx->r2 & 0X80;
            goto L_8006E33C;
    }
    // 0x8006E0DC: andi        $t4, $v0, 0x80
    ctx->r12 = ctx->r2 & 0X80;
    // 0x8006E0E0: jal         0x8006CE54
    // 0x8006E0E4: nop

    unload_level_game(rdram, ctx);
        goto after_7;
    // 0x8006E0E4: nop

    after_7:
    // 0x8006E0E8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E0EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E0F0: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    // 0x8006E0F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E0F8: andi        $t5, $t4, 0x7F
    ctx->r13 = ctx->r12 & 0X7F;
    // 0x8006E0FC: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    // 0x8006E100: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8006E104: sltiu       $at, $t6, 0xE
    ctx->r1 = ctx->r14 < 0XE ? 1 : 0;
    // 0x8006E108: beq         $at, $zero, L_8006E320
    if (ctx->r1 == 0) {
        // 0x8006E10C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8006E320;
    }
    // 0x8006E10C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006E110: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006E114: addu        $at, $at, $t6
    gpr jr_addend_8006E120 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8006E118: lw          $t6, 0x7768($at)
    ctx->r14 = ADD32(ctx->r1, 0X7768);
    // 0x8006E11C: nop

    // 0x8006E120: jr          $t6
    // 0x8006E124: nop

    switch (jr_addend_8006E120 >> 2) {
        case 0: goto L_8006E1B0; break;
        case 1: goto L_8006E24C; break;
        case 2: goto L_8006E294; break;
        case 3: goto L_8006E320; break;
        case 4: goto L_8006E128; break;
        case 5: goto L_8006E320; break;
        case 6: goto L_8006E320; break;
        case 7: goto L_8006E320; break;
        case 8: goto L_8006E320; break;
        case 9: goto L_8006E320; break;
        case 10: goto L_8006E320; break;
        case 11: goto L_8006E320; break;
        case 12: goto L_8006E320; break;
        case 13: goto L_8006E140; break;
        default: switch_error(__func__, 0x8006E120, 0x800E7768);
    }
    // 0x8006E124: nop

L_8006E128:
    // 0x8006E128: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8006E12C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006E130: jal         0x8006DC68
    // 0x8006E134: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    load_menu_with_level_background(rdram, ctx);
        goto after_8;
    // 0x8006E134: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x8006E138: b           L_8006E51C
    // 0x8006E13C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E51C;
    // 0x8006E13C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E140:
    // 0x8006E140: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E144: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E148: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006E14C: addiu       $t3, $t3, 0x3A88
    ctx->r11 = ADD32(ctx->r11, 0X3A88);
    // 0x8006E150: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E154: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E158: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8006E15C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8006E160: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8006E164: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8006E168: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E16C: sw          $zero, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = 0;
    // 0x8006E170: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E174: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E178: addiu       $t2, $t2, 0x3A98
    ctx->r10 = ADD32(ctx->r10, 0X3A98);
    // 0x8006E17C: addiu       $v1, $v1, 0x3A80
    ctx->r3 = ADD32(ctx->r3, 0X3A80);
    // 0x8006E180: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8006E184: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8006E188: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006E18C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006E190: jal         0x8006CD98
    // 0x8006E194: nop

    load_level_game(rdram, ctx);
        goto after_9;
    // 0x8006E194: nop

    after_9:
    // 0x8006E198: jal         0x8009C6E4
    // 0x8006E19C: nop

    get_save_file_index(rdram, ctx);
        goto after_10;
    // 0x8006E19C: nop

    after_10:
    // 0x8006E1A0: jal         0x8006EE88
    // 0x8006E1A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_11;
    // 0x8006E1A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x8006E1A8: b           L_8006E51C
    // 0x8006E1AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E51C;
    // 0x8006E1AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E1B0:
    // 0x8006E1B0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006E1B4: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    // 0x8006E1B8: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x8006E1BC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E1C0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E1C4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006E1C8: addiu       $t3, $t3, 0x3A88
    ctx->r11 = ADD32(ctx->r11, 0X3A88);
    // 0x8006E1CC: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E1D0: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E1D4: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8006E1D8: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8006E1DC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8006E1E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E1E4: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8006E1E8: sw          $zero, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = 0;
    // 0x8006E1EC: lb          $v0, 0xF($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XF);
    // 0x8006E1F0: lb          $v1, 0x1($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1);
    // 0x8006E1F4: bltz        $v0, L_8006E200
    if (SIGNED(ctx->r2) < 0) {
        // 0x8006E1F8: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8006E200;
    }
    // 0x8006E1F8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E1FC: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_8006E200:
    // 0x8006E200: addu        $t4, $a1, $v1
    ctx->r12 = ADD32(ctx->r5, ctx->r3);
    // 0x8006E204: lb          $v0, 0x8($t4)
    ctx->r2 = MEM_B(ctx->r12, 0X8);
    // 0x8006E208: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E20C: bltz        $v0, L_8006E218
    if (SIGNED(ctx->r2) < 0) {
        // 0x8006E210: addiu       $v1, $v1, 0x3A80
        ctx->r3 = ADD32(ctx->r3, 0X3A80);
            goto L_8006E218;
    }
    // 0x8006E210: addiu       $v1, $v1, 0x3A80
    ctx->r3 = ADD32(ctx->r3, 0X3A80);
    // 0x8006E214: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
L_8006E218:
    // 0x8006E218: addiu       $t2, $t2, 0x3A98
    ctx->r10 = ADD32(ctx->r10, 0X3A98);
    // 0x8006E21C: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8006E220: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006E224: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8006E228: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006E22C: jal         0x8006CD98
    // 0x8006E230: nop

    load_level_game(rdram, ctx);
        goto after_12;
    // 0x8006E230: nop

    after_12:
    // 0x8006E234: jal         0x8009C6E4
    // 0x8006E238: nop

    get_save_file_index(rdram, ctx);
        goto after_13;
    // 0x8006E238: nop

    after_13:
    // 0x8006E23C: jal         0x8006EE88
    // 0x8006E240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_14;
    // 0x8006E240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x8006E244: b           L_8006E51C
    // 0x8006E248: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E51C;
    // 0x8006E248: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E24C:
    // 0x8006E24C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E250: sw          $zero, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = 0;
    // 0x8006E254: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E258: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E25C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E260: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E264: addiu       $t2, $t2, 0x3A98
    ctx->r10 = ADD32(ctx->r10, 0X3A98);
    // 0x8006E268: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E26C: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E270: addiu       $v1, $v1, 0x3A80
    ctx->r3 = ADD32(ctx->r3, 0X3A80);
    // 0x8006E274: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8006E278: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006E27C: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006E280: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8006E284: jal         0x8006CD98
    // 0x8006E288: nop

    load_level_game(rdram, ctx);
        goto after_15;
    // 0x8006E288: nop

    after_15:
    // 0x8006E28C: b           L_8006E51C
    // 0x8006E290: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E51C;
    // 0x8006E290: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E294:
    // 0x8006E294: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006E298: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E29C: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    // 0x8006E2A0: sw          $zero, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = 0;
    // 0x8006E2A4: lb          $t7, 0x1($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1);
    // 0x8006E2A8: lb          $a0, 0x0($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X0);
    // 0x8006E2AC: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x8006E2B0: lb          $t6, 0xF($a1)
    ctx->r14 = MEM_B(ctx->r5, 0XF);
    // 0x8006E2B4: lb          $t9, 0x8($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X8);
    // 0x8006E2B8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E2BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E2C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006E2C4: addiu       $t3, $t3, 0x3A88
    ctx->r11 = ADD32(ctx->r11, 0X3A88);
    // 0x8006E2C8: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E2CC: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E2D0: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    // 0x8006E2D4: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8006E2D8: jal         0x8006B2EC
    // 0x8006E2DC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    leveltable_vehicle_default(rdram, ctx);
        goto after_16;
    // 0x8006E2DC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    after_16:
    // 0x8006E2E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E2E4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E2E8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E2EC: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E2F0: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E2F4: addiu       $v1, $v1, 0x3A80
    ctx->r3 = ADD32(ctx->r3, 0X3A80);
    // 0x8006E2F8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E2FC: addiu       $t2, $t2, 0x3A98
    ctx->r10 = ADD32(ctx->r10, 0X3A98);
    // 0x8006E300: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8006E304: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006E308: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006E30C: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x8006E310: jal         0x8006CD98
    // 0x8006E314: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    load_level_game(rdram, ctx);
        goto after_17;
    // 0x8006E314: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_17:
    // 0x8006E318: b           L_8006E51C
    // 0x8006E31C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E51C;
    // 0x8006E31C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E320:
    // 0x8006E320: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006E324: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006E328: jal         0x8006DC68
    // 0x8006E32C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_18;
    // 0x8006E32C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x8006E330: b           L_8006E51C
    // 0x8006E334: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E51C;
    // 0x8006E334: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E338:
    // 0x8006E338: andi        $t4, $v0, 0x80
    ctx->r12 = ctx->r2 & 0X80;
L_8006E33C:
    // 0x8006E33C: beq         $t4, $zero, L_8006E45C
    if (ctx->r12 == 0) {
        // 0x8006E340: nop
    
            goto L_8006E45C;
    }
    // 0x8006E340: nop

    // 0x8006E344: beq         $v0, $v1, L_8006E45C
    if (ctx->r2 == ctx->r3) {
        // 0x8006E348: nop
    
            goto L_8006E45C;
    }
    // 0x8006E348: nop

    // 0x8006E34C: jal         0x8006DE24
    // 0x8006E350: nop

    unload_level_menu(rdram, ctx);
        goto after_19;
    // 0x8006E350: nop

    after_19:
    // 0x8006E354: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006E358: lw          $t5, 0x3A68($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3A68);
    // 0x8006E35C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006E360: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006E364: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8006E368: lw          $t7, 0x1770($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1770);
    // 0x8006E36C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E370: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8006E374: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8006E378: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8006E37C: lui         $t9, 0xE900
    ctx->r25 = S32(0XE900 << 16);
    // 0x8006E380: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8006E384: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8006E388: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006E38C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006E390: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8006E394: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8006E398: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E39C: lui         $t5, 0xB800
    ctx->r13 = S32(0XB800 << 16);
    // 0x8006E3A0: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E3A4: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    // 0x8006E3A8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8006E3AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006E3B0: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8006E3B4: andi        $t6, $t2, 0x7F
    ctx->r14 = ctx->r10 & 0X7F;
    // 0x8006E3B8: sb          $t6, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r14;
    // 0x8006E3BC: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x8006E3C0: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    // 0x8006E3C4: lb          $t8, 0x2($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X2);
    // 0x8006E3C8: lb          $t9, 0x4($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X4);
    // 0x8006E3CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E3D0: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E3D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E3D8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8006E3DC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8006E3E0: sw          $zero, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = 0;
    // 0x8006E3E4: lb          $t4, 0xC($v1)
    ctx->r12 = MEM_B(ctx->r3, 0XC);
    // 0x8006E3E8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006E3EC: addiu       $t3, $t3, 0x3A88
    ctx->r11 = ADD32(ctx->r11, 0X3A88);
    // 0x8006E3F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006E3F4: jal         0x8009C794
    // 0x8006E3F8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    get_player_selected_vehicle(rdram, ctx);
        goto after_20;
    // 0x8006E3F8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    after_20:
    // 0x8006E3FC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006E400: addiu       $s0, $s0, 0x3A90
    ctx->r16 = ADD32(ctx->r16, 0X3A90);
    // 0x8006E404: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8006E408: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E40C: lbu         $t6, 0x4A($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X4A);
    // 0x8006E410: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E414: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E418: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E41C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E420: addiu       $v1, $v1, 0x3A80
    ctx->r3 = ADD32(ctx->r3, 0X3A80);
    // 0x8006E424: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006E428: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006E42C: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    // 0x8006E430: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8006E434: jal         0x8006CD98
    // 0x8006E438: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    load_level_game(rdram, ctx);
        goto after_21;
    // 0x8006E438: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_21:
    // 0x8006E43C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006E440: lw          $t8, 0x3A9C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3A9C);
    // 0x8006E444: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E448: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E44C: addiu       $t2, $t2, 0x3A98
    ctx->r10 = ADD32(ctx->r10, 0X3A98);
    // 0x8006E450: sw          $zero, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = 0;
    // 0x8006E454: b           L_8006E518
    // 0x8006E458: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
        goto L_8006E518;
    // 0x8006E458: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_8006E45C:
    // 0x8006E45C: blez        $v0, L_8006E51C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006E460: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006E51C;
    }
    // 0x8006E460: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006E464: jal         0x8006DE24
    // 0x8006E468: nop

    unload_level_menu(rdram, ctx);
        goto after_22;
    // 0x8006E468: nop

    after_22:
    // 0x8006E46C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006E470: lw          $t9, 0x3A68($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3A68);
    // 0x8006E474: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006E478: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x8006E47C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8006E480: lw          $t5, 0x1770($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1770);
    // 0x8006E484: lui         $t7, 0xE900
    ctx->r15 = S32(0XE900 << 16);
    // 0x8006E488: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8006E48C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8006E490: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8006E494: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8006E498: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8006E49C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006E4A0: lui         $t9, 0xB800
    ctx->r25 = S32(0XB800 << 16);
    // 0x8006E4A4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8006E4A8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8006E4AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006E4B0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8006E4B4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E4B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E4BC: addiu       $t2, $t2, 0x3A98
    ctx->r10 = ADD32(ctx->r10, 0X3A98);
    // 0x8006E4C0: sw          $zero, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = 0;
    // 0x8006E4C4: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x8006E4C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E4CC: jal         0x8006CD24
    // 0x8006E4D0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    load_next_ingame_level(rdram, ctx);
        goto after_23;
    // 0x8006E4D0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_23:
    // 0x8006E4D4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006E4D8: addiu       $s0, $s0, 0x3A90
    ctx->r16 = ADD32(ctx->r16, 0X3A90);
    // 0x8006E4DC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8006E4E0: nop

    // 0x8006E4E4: lbu         $t5, 0x4B($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X4B);
    // 0x8006E4E8: nop

    // 0x8006E4EC: beq         $t5, $zero, L_8006E51C
    if (ctx->r13 == 0) {
        // 0x8006E4F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006E51C;
    }
    // 0x8006E4F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006E4F4: jal         0x8009C814
    // 0x8006E4F8: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_24;
    // 0x8006E4F8: nop

    after_24:
    // 0x8006E4FC: bne         $v0, $zero, L_8006E51C
    if (ctx->r2 != 0) {
        // 0x8006E500: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006E51C;
    }
    // 0x8006E500: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006E504: jal         0x80000B28
    // 0x8006E508: nop

    music_change_on(rdram, ctx);
        goto after_25;
    // 0x8006E508: nop

    after_25:
    // 0x8006E50C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006E510: nop

    // 0x8006E514: sb          $zero, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = 0;
L_8006E518:
    // 0x8006E518: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E51C:
    // 0x8006E51C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006E520: jr          $ra
    // 0x8006E524: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006E524: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void render_printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B643C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B6440: lw          $t6, -0x7468($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7468);
    // 0x800B6444: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B6448: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B644C: addiu       $t7, $t7, -0x7D68
    ctx->r15 = ADD32(ctx->r15, -0X7D68);
    // 0x800B6450: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800B6454: slti        $at, $t8, 0x801
    ctx->r1 = SIGNED(ctx->r24) < 0X801 ? 1 : 0;
    // 0x800B6458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B645C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B6460: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B6464: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B6468: bne         $at, $zero, L_800B6478
    if (ctx->r1 != 0) {
        // 0x800B646C: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800B6478;
    }
    // 0x800B646C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800B6470: b           L_800B64C8
    // 0x800B6474: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B64C8;
    // 0x800B6474: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B6478:
    // 0x800B6478: jal         0x800B4F68
    // 0x800B647C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprintfSetSpacingCodes(rdram, ctx);
        goto after_0;
    // 0x800B647C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800B6480: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B6484: lw          $a0, -0x7468($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7468);
    // 0x800B6488: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800B648C: jal         0x800B4FA0
    // 0x800B6490: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    vsprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800B6490: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x800B6494: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B6498: jal         0x800B4F68
    // 0x800B649C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sprintfSetSpacingCodes(rdram, ctx);
        goto after_2;
    // 0x800B649C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x800B64A0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800B64A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B64A8: blez        $v1, L_800B64C4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B64AC: addiu       $v0, $v0, -0x7468
        ctx->r2 = ADD32(ctx->r2, -0X7468);
            goto L_800B64C4;
    }
    // 0x800B64AC: addiu       $v0, $v0, -0x7468
    ctx->r2 = ADD32(ctx->r2, -0X7468);
    // 0x800B64B0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800B64B4: nop

    // 0x800B64B8: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x800B64BC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B64C0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_800B64C4:
    // 0x800B64C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B64C8:
    // 0x800B64C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B64CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B64D0: jr          $ra
    // 0x800B64D4: nop

    return;
    // 0x800B64D4: nop

;}
RECOMP_FUNC void func_80080580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800809D0: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800809D4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800809D8: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800809DC: addiu       $fp, $fp, 0x2338
    ctx->r30 = ADD32(ctx->r30, 0X2338);
    // 0x800809E0: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800809E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800809E8: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x800809EC: lw          $t6, 0x71EC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X71EC);
    // 0x800809F0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800809F4: lw          $t7, 0x2334($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2334);
    // 0x800809F8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800809FC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80080A00: lw          $s3, 0xE0($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XE0);
    // 0x80080A04: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80080A08: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80080A0C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80080A10: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80080A14: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80080A18: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80080A1C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80080A20: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80080A24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80080A28: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80080A2C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80080A30: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80080A34: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80080A38: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80080A3C: beq         $s3, $zero, L_80080C58
    if (ctx->r19 == 0) {
        // 0x80080A40: sw          $s3, 0x10($t8)
        MEM_W(0X10, ctx->r24) = ctx->r19;
            goto L_80080C58;
    }
    // 0x80080A40: sw          $s3, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r19;
    // 0x80080A44: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80080A48: lw          $t3, 0xD4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD4);
    // 0x80080A4C: lw          $a1, 0x2340($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2340);
    // 0x80080A50: subu        $t9, $a3, $t3
    ctx->r25 = SUB32(ctx->r7, ctx->r11);
    // 0x80080A54: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080A58: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80080A5C: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x80080A60: lw          $a2, 0x2344($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2344);
    // 0x80080A64: lw          $t5, 0xD0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD0);
    // 0x80080A68: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
    // 0x80080A6C: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
    // 0x80080A70: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80080A74: addiu       $v0, $v0, 0x2270
    ctx->r2 = ADD32(ctx->r2, 0X2270);
    // 0x80080A78: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80080A7C: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x80080A80: mflo        $t7
    ctx->r15 = lo;
    // 0x80080A84: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x80080A88: nop

    // 0x80080A8C: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080A90: subu        $t9, $t5, $t4
    ctx->r25 = SUB32(ctx->r13, ctx->r12);
    // 0x80080A94: mflo        $t6
    ctx->r14 = lo;
    // 0x80080A98: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
    // 0x80080A9C: nop

    // 0x80080AA0: multu       $a1, $a3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080AA4: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x80080AA8: mflo        $t8
    ctx->r24 = lo;
    // 0x80080AAC: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80080AB0: nop

    // 0x80080AB4: multu       $a2, $t4
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080AB8: mflo        $t7
    ctx->r15 = lo;
    // 0x80080ABC: sw          $t7, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r15;
    // 0x80080AC0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80080AC4: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080AC8: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x80080ACC: lw          $t7, 0x71EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X71EC);
    // 0x80080AD0: mflo        $t6
    ctx->r14 = lo;
    // 0x80080AD4: sw          $t6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r14;
    // 0x80080AD8: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x80080ADC: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080AE0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80080AE4: lw          $t9, 0x2334($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2334);
    // 0x80080AE8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80080AEC: mflo        $t8
    ctx->r24 = lo;
    // 0x80080AF0: sw          $t8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r24;
    // 0x80080AF4: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80080AF8: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80080AFC: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80080B00: lw          $v1, 0x8($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X8);
    // 0x80080B04: nop

L_80080B08:
    // 0x80080B08: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80080B0C: addiu       $ra, $ra, 0x2
    ctx->r31 = ADD32(ctx->r31, 0X2);
    // 0x80080B10: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080B14: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80080B18: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080B1C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80080B20: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x80080B24: lbu         $t9, -0xB($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0XB);
    // 0x80080B28: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80080B2C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080B30: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x80080B34: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080B38: nop

    // 0x80080B3C: sh          $t6, -0x1A($v1)
    MEM_H(-0X1A, ctx->r3) = ctx->r14;
    // 0x80080B40: lbu         $t9, -0xA($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0XA);
    // 0x80080B44: nop

    // 0x80080B48: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080B4C: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80080B50: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080B54: nop

    // 0x80080B58: sh          $t6, -0x18($v1)
    MEM_H(-0X18, ctx->r3) = ctx->r14;
    // 0x80080B5C: lbu         $t9, -0x9($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X9);
    // 0x80080B60: nop

    // 0x80080B64: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080B68: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x80080B6C: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080B70: nop

    // 0x80080B74: sh          $t6, -0x16($v1)
    MEM_H(-0X16, ctx->r3) = ctx->r14;
    // 0x80080B78: lbu         $t9, -0x8($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X8);
    // 0x80080B7C: nop

    // 0x80080B80: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080B84: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80080B88: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080B8C: nop

    // 0x80080B90: sh          $t6, -0x14($v1)
    MEM_H(-0X14, ctx->r3) = ctx->r14;
    // 0x80080B94: lbu         $t9, -0x7($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X7);
    // 0x80080B98: nop

    // 0x80080B9C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080BA0: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x80080BA4: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080BA8: nop

    // 0x80080BAC: sh          $t6, -0x12($v1)
    MEM_H(-0X12, ctx->r3) = ctx->r14;
    // 0x80080BB0: lbu         $t9, -0x6($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X6);
    // 0x80080BB4: nop

    // 0x80080BB8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080BBC: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80080BC0: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080BC4: nop

    // 0x80080BC8: sh          $t6, -0xC($v1)
    MEM_H(-0XC, ctx->r3) = ctx->r14;
    // 0x80080BCC: lbu         $t9, -0x5($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X5);
    // 0x80080BD0: nop

    // 0x80080BD4: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080BD8: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x80080BDC: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080BE0: nop

    // 0x80080BE4: sh          $t6, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = ctx->r14;
    // 0x80080BE8: lbu         $t9, -0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X4);
    // 0x80080BEC: nop

    // 0x80080BF0: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080BF4: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80080BF8: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080BFC: nop

    // 0x80080C00: sh          $t6, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r14;
    // 0x80080C04: lbu         $t9, -0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X3);
    // 0x80080C08: nop

    // 0x80080C0C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080C10: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x80080C14: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080C18: nop

    // 0x80080C1C: sh          $t6, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r14;
    // 0x80080C20: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x80080C24: nop

    // 0x80080C28: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080C2C: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80080C30: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080C34: nop

    // 0x80080C38: sh          $t6, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r14;
    // 0x80080C3C: lbu         $t9, -0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X1);
    // 0x80080C40: nop

    // 0x80080C44: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080C48: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x80080C4C: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080C50: bne         $ra, $a2, L_80080B08
    if (ctx->r31 != ctx->r6) {
        // 0x80080C54: sh          $t6, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r14;
            goto L_80080B08;
    }
    // 0x80080C54: sh          $t6, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r14;
L_80080C58:
    // 0x80080C58: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x80080C5C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80080C60: sra         $s3, $a0, 24
    ctx->r19 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80080C64: andi        $t9, $s3, 0xFF
    ctx->r25 = ctx->r19 & 0XFF;
    // 0x80080C68: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x80080C6C: sra         $s4, $a0, 16
    ctx->r20 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80080C70: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x80080C74: andi        $t8, $s4, 0xFF
    ctx->r24 = ctx->r20 & 0XFF;
    // 0x80080C78: or          $s4, $t8, $zero
    ctx->r20 = ctx->r24 | 0;
    // 0x80080C7C: sra         $s5, $a0, 8
    ctx->r21 = S32(SIGNED(ctx->r4) >> 8);
    // 0x80080C80: sll         $t8, $t9, 5
    ctx->r24 = S32(ctx->r25 << 5);
    // 0x80080C84: lw          $t6, 0x71EC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X71EC);
    // 0x80080C88: andi        $t7, $s5, 0xFF
    ctx->r15 = ctx->r21 & 0XFF;
    // 0x80080C8C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80080C90: lw          $t9, 0x2334($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2334);
    // 0x80080C94: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
    // 0x80080C98: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80080C9C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80080CA0: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80080CA4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80080CA8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80080CAC: lw          $t3, 0xD4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD4);
    // 0x80080CB0: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x80080CB4: lw          $t5, 0xD0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD0);
    // 0x80080CB8: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80080CBC: addiu       $v1, $v1, 0x22AC
    ctx->r3 = ADD32(ctx->r3, 0X22AC);
    // 0x80080CC0: addiu       $t2, $t2, 0x22FC
    ctx->r10 = ADD32(ctx->r10, 0X22FC);
    // 0x80080CC4: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80080CC8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80080CCC: andi        $s6, $a0, 0xFF
    ctx->r22 = ctx->r4 & 0XFF;
L_80080CD0:
    // 0x80080CD0: lh          $t9, 0x0($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X0);
    // 0x80080CD4: lh          $t6, 0x2($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X2);
    // 0x80080CD8: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080CDC: lh          $t9, 0x4($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X4);
    // 0x80080CE0: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x80080CE4: slti        $at, $ra, 0x5
    ctx->r1 = SIGNED(ctx->r31) < 0X5 ? 1 : 0;
    // 0x80080CE8: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x80080CEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80080CF0: mflo        $a1
    ctx->r5 = lo;
    // 0x80080CF4: sra         $t7, $a1, 8
    ctx->r15 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80080CF8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80080CFC: multu       $t6, $s4
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080D00: lh          $t6, -0x2($t2)
    ctx->r14 = MEM_H(ctx->r10, -0X2);
    // 0x80080D04: mflo        $a2
    ctx->r6 = lo;
    // 0x80080D08: sra         $t8, $a2, 8
    ctx->r24 = S32(SIGNED(ctx->r6) >> 8);
    // 0x80080D0C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80080D10: multu       $t9, $s5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080D14: mflo        $a3
    ctx->r7 = lo;
    // 0x80080D18: sra         $t7, $a3, 8
    ctx->r15 = S32(SIGNED(ctx->r7) >> 8);
    // 0x80080D1C: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80080D20: multu       $t6, $s6
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080D24: mflo        $t0
    ctx->r8 = lo;
    // 0x80080D28: sra         $t8, $t0, 8
    ctx->r24 = S32(SIGNED(ctx->r8) >> 8);
    // 0x80080D2C: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
L_80080D30:
    // 0x80080D30: sh          $s1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r17;
    // 0x80080D34: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x80080D38: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80080D3C: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080D40: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80080D44: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80080D48: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80080D4C: mflo        $t6
    ctx->r14 = lo;
    // 0x80080D50: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80080D54: sh          $t8, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = ctx->r24;
    // 0x80080D58: lb          $t9, -0x3($v1)
    ctx->r25 = MEM_B(ctx->r3, -0X3);
    // 0x80080D5C: lh          $t7, -0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, -0XA);
    // 0x80080D60: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080D64: sh          $s2, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r18;
    // 0x80080D68: lh          $t9, -0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X8);
    // 0x80080D6C: mflo        $t6
    ctx->r14 = lo;
    // 0x80080D70: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80080D74: sh          $t8, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = ctx->r24;
    // 0x80080D78: lb          $t7, -0x2($v1)
    ctx->r15 = MEM_B(ctx->r3, -0X2);
    // 0x80080D7C: nop

    // 0x80080D80: multu       $t7, $t5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080D84: mflo        $t6
    ctx->r14 = lo;
    // 0x80080D88: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80080D8C: sh          $t8, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r24;
    // 0x80080D90: lb          $t9, -0x1($v1)
    ctx->r25 = MEM_B(ctx->r3, -0X1);
    // 0x80080D94: lh          $t7, -0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X8);
    // 0x80080D98: multu       $t9, $t4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080D9C: sh          $zero, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = 0;
    // 0x80080DA0: sb          $a1, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r5;
    // 0x80080DA4: sb          $a2, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r6;
    // 0x80080DA8: sb          $a3, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r7;
    // 0x80080DAC: sb          $t0, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r8;
    // 0x80080DB0: mflo        $t6
    ctx->r14 = lo;
    // 0x80080DB4: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80080DB8: bne         $a0, $t1, L_80080D30
    if (ctx->r4 != ctx->r9) {
        // 0x80080DBC: sh          $t8, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = ctx->r24;
            goto L_80080D30;
    }
    // 0x80080DBC: sh          $t8, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r24;
    // 0x80080DC0: bne         $at, $zero, L_80080CD0
    if (ctx->r1 != 0) {
        // 0x80080DC4: nop
    
            goto L_80080CD0;
    }
    // 0x80080DC4: nop

    // 0x80080DC8: beq         $s7, $zero, L_80080FB8
    if (ctx->r23 == 0) {
        // 0x80080DCC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80080FB8;
    }
    // 0x80080DCC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80080DD0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80080DD4: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80080DD8: addiu       $t0, $t0, 0x71EC
    ctx->r8 = ADD32(ctx->r8, 0X71EC);
    // 0x80080DDC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80080DE0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80080DE4: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x80080DE8: addiu       $a3, $a3, 0x2334
    ctx->r7 = ADD32(ctx->r7, 0X2334);
    // 0x80080DEC: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x80080DF0: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80080DF4: lw          $a2, 0xE0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE0);
    // 0x80080DF8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80080DFC: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80080E00: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80080E04: sw          $t9, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r25;
    // 0x80080E08: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080E0C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80080E10: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80080E14: sw          $t6, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r14;
    // 0x80080E18: addiu       $t9, $t9, 0x21F0
    ctx->r25 = ADD32(ctx->r25, 0X21F0);
    // 0x80080E1C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80080E20: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80080E24: beq         $a2, $zero, L_80080E98
    if (ctx->r6 == 0) {
        // 0x80080E28: sw          $t9, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r25;
            goto L_80080E98;
    }
    // 0x80080E28: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80080E2C: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080E30: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x80080E34: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80080E38: sw          $t7, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r15;
    // 0x80080E3C: lui         $t8, 0xE
    ctx->r24 = S32(0XE << 16);
    // 0x80080E40: addiu       $t8, $t8, 0x2230
    ctx->r24 = ADD32(ctx->r24, 0X2230);
    // 0x80080E44: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x80080E48: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80080E4C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80080E50: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080E54: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80080E58: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80080E5C: sw          $t9, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r25;
    // 0x80080E60: lh          $a1, 0xA($a2)
    ctx->r5 = MEM_H(ctx->r6, 0XA);
    // 0x80080E64: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80080E68: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x80080E6C: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80080E70: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x80080E74: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x80080E78: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80080E7C: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80080E80: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80080E84: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x80080E88: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80080E8C: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x80080E90: b           L_80080EC4
    // 0x80080E94: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_80080EC4;
    // 0x80080E94: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_80080E98:
    // 0x80080E98: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080E9C: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x80080EA0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80080EA4: sw          $t7, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r15;
    // 0x80080EA8: lui         $t9, 0xE
    ctx->r25 = S32(0XE << 16);
    // 0x80080EAC: addiu       $t9, $t9, 0x2220
    ctx->r25 = ADD32(ctx->r25, 0X2220);
    // 0x80080EB0: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x80080EB4: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80080EB8: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80080EBC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80080EC0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80080EC4:
    // 0x80080EC4: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080EC8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80080ECC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80080ED0: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x80080ED4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80080ED8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80080EDC: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080EE0: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80080EE4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80080EE8: sw          $t6, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r14;
    // 0x80080EEC: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x80080EF0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80080EF4: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x80080EF8: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80080EFC: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x80080F00: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80080F04: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x80080F08: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80080F0C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80080F10: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x80080F14: andi        $t9, $t6, 0x6
    ctx->r25 = ctx->r14 & 0X6;
    // 0x80080F18: ori         $t7, $t9, 0x98
    ctx->r15 = ctx->r25 | 0X98;
    // 0x80080F1C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80080F20: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80080F24: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80080F28: ori         $t7, $t9, 0x170
    ctx->r15 = ctx->r25 | 0X170;
    // 0x80080F2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80080F30: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80080F34: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80080F38: sll         $t9, $t6, 5
    ctx->r25 = S32(ctx->r14 << 5);
    // 0x80080F3C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80080F40: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x80080F44: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80080F48: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80080F4C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80080F50: ori         $t9, $ra, 0x90
    ctx->r25 = ctx->r31 | 0X90;
    // 0x80080F54: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x80080F58: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80080F5C: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080F60: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80080F64: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80080F68: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x80080F6C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80080F70: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80080F74: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80080F78: ori         $t9, $t8, 0xA0
    ctx->r25 = ctx->r24 | 0XA0;
    // 0x80080F7C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80080F80: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x80080F84: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80080F88: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80080F8C: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80080F90: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80080F94: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80080F98: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80080F9C: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x80080FA0: nop

    // 0x80080FA4: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x80080FA8: jal         0x8007B820
    // 0x80080FAC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x80080FAC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    after_0:
    // 0x80080FB0: b           L_80080FE0
    // 0x80080FB4: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
        goto L_80080FE0;
    // 0x80080FB4: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
L_80080FB8:
    // 0x80080FB8: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x80080FBC: lw          $t6, 0x71EC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X71EC);
    // 0x80080FC0: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x80080FC4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80080FC8: lw          $t8, 0x2334($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2334);
    // 0x80080FCC: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80080FD0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80080FD4: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80080FD8: sw          $zero, 0x18($t7)
    MEM_W(0X18, ctx->r15) = 0;
    // 0x80080FDC: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
L_80080FE0:
    // 0x80080FE0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80080FE4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80080FE8: sw          $t9, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r25;
    // 0x80080FEC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80080FF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80080FF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80080FF8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80080FFC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80081000: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80081004: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80081008: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008100C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80081010: jr          $ra
    // 0x80081014: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80081014: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void obj_loop_modechange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AE90: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8003AE94: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8003AE98: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x8003AE9C: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x8003AEA0: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8003AEA4: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8003AEA8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8003AEAC: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8003AEB0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8003AEB4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8003AEB8: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8003AEBC: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8003AEC0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003AEC4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8003AEC8: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8003AECC: lw          $s2, 0x64($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X64);
    // 0x8003AED0: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8003AED4: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x8003AED8: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x8003AEDC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8003AEE0: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003AEE4: beq         $at, $zero, L_8003B05C
    if (ctx->r1 == 0) {
        // 0x8003AEE8: addiu       $a0, $sp, 0x74
        ctx->r4 = ADD32(ctx->r29, 0X74);
            goto L_8003B05C;
    }
    // 0x8003AEE8: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x8003AEEC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8003AEF0: jal         0x8001BAA8
    // 0x8003AEF4: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x8003AEF4: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x8003AEF8: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8003AEFC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8003AF00: blez        $t8, L_8003B05C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8003AF04: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_8003B05C;
    }
    // 0x8003AF04: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8003AF08: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8003AF0C: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x8003AF10: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
L_8003AF14:
    // 0x8003AF14: lw          $s0, 0x0($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X0);
    // 0x8003AF18: lbu         $t9, 0x14($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X14);
    // 0x8003AF1C: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x8003AF20: nop

    // 0x8003AF24: lb          $t0, 0x1D6($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X1D6);
    // 0x8003AF28: nop

    // 0x8003AF2C: beq         $t9, $t0, L_8003B04C
    if (ctx->r25 == ctx->r8) {
        // 0x8003AF30: lw          $t5, 0x74($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X74);
            goto L_8003B04C;
    }
    // 0x8003AF30: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8003AF34: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003AF38: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8003AF3C: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003AF40: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003AF44: lwc1        $f16, 0x10($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8003AF48: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003AF4C: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003AF50: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003AF54: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8003AF58: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003AF5C: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003AF60: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003AF64: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003AF68: jal         0x800CA030
    // 0x8003AF6C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8003AF6C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_1:
    // 0x8003AF70: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8003AF74: nop

    // 0x8003AF78: bc1f        L_8003B04C
    if (!c1cs) {
        // 0x8003AF7C: lw          $t5, 0x74($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X74);
            goto L_8003B04C;
    }
    // 0x8003AF7C: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8003AF80: lwc1        $f18, 0x0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8003AF84: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003AF88: lwc1        $f8, 0x8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8003AF8C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8003AF90: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003AF94: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8003AF98: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003AF9C: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8003AFA0: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003AFA4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8003AFA8: nop

    // 0x8003AFAC: bc1f        L_8003B04C
    if (!c1cs) {
        // 0x8003AFB0: lw          $t5, 0x74($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X74);
            goto L_8003B04C;
    }
    // 0x8003AFB0: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8003AFB4: sb          $zero, 0x1E0($s1)
    MEM_B(0X1E0, ctx->r17) = 0;
    // 0x8003AFB8: lbu         $v0, 0x14($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X14);
    // 0x8003AFBC: nop

    // 0x8003AFC0: bne         $v0, $zero, L_8003AFD4
    if (ctx->r2 != 0) {
        // 0x8003AFC4: nop
    
            goto L_8003AFD4;
    }
    // 0x8003AFC4: nop

    // 0x8003AFC8: lb          $t1, 0x1D7($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1D7);
    // 0x8003AFCC: b           L_8003AFD8
    // 0x8003AFD0: sb          $t1, 0x1D6($s1)
    MEM_B(0X1D6, ctx->r17) = ctx->r9;
        goto L_8003AFD8;
    // 0x8003AFD0: sb          $t1, 0x1D6($s1)
    MEM_B(0X1D6, ctx->r17) = ctx->r9;
L_8003AFD4:
    // 0x8003AFD4: sb          $v0, 0x1D6($s1)
    MEM_B(0X1D6, ctx->r17) = ctx->r2;
L_8003AFD8:
    // 0x8003AFD8: lbu         $t2, 0x14($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X14);
    // 0x8003AFDC: nop

    // 0x8003AFE0: bne         $s6, $t2, L_8003B03C
    if (ctx->r22 != ctx->r10) {
        // 0x8003AFE4: nop
    
            goto L_8003B03C;
    }
    // 0x8003AFE4: nop

    // 0x8003AFE8: lb          $t3, 0x1D8($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X1D8);
    // 0x8003AFEC: nop

    // 0x8003AFF0: bne         $t3, $zero, L_8003B004
    if (ctx->r11 != 0) {
        // 0x8003AFF4: nop
    
            goto L_8003B004;
    }
    // 0x8003AFF4: nop

    // 0x8003AFF8: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x8003AFFC: jal         0x80072594
    // 0x8003B000: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_2;
    // 0x8003B000: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
L_8003B004:
    // 0x8003B004: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003B008: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003B00C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003B010: jal         0x8001C558
    // 0x8003B014: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_3;
    // 0x8003B014: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8003B018: beq         $v0, $s7, L_8003B030
    if (ctx->r2 == ctx->r23) {
        // 0x8003B01C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8003B030;
    }
    // 0x8003B01C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003B020: jal         0x8001D248
    // 0x8003B024: nop

    ainode_get(rdram, ctx);
        goto after_4;
    // 0x8003B024: nop

    after_4:
    // 0x8003B028: b           L_8003B034
    // 0x8003B02C: sw          $v0, 0x158($s1)
    MEM_W(0X158, ctx->r17) = ctx->r2;
        goto L_8003B034;
    // 0x8003B02C: sw          $v0, 0x158($s1)
    MEM_W(0X158, ctx->r17) = ctx->r2;
L_8003B030:
    // 0x8003B030: sw          $zero, 0x158($s1)
    MEM_W(0X158, ctx->r17) = 0;
L_8003B034:
    // 0x8003B034: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x8003B038: sh          $zero, 0x19A($s1)
    MEM_H(0X19A, ctx->r17) = 0;
L_8003B03C:
    // 0x8003B03C: lh          $t4, 0x0($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X0);
    // 0x8003B040: nop

    // 0x8003B044: sh          $t4, 0x198($s1)
    MEM_H(0X198, ctx->r17) = ctx->r12;
    // 0x8003B048: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
L_8003B04C:
    // 0x8003B04C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8003B050: slt         $at, $s4, $t5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8003B054: bne         $at, $zero, L_8003AF14
    if (ctx->r1 != 0) {
        // 0x8003B058: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_8003AF14;
    }
    // 0x8003B058: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8003B05C:
    // 0x8003B05C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8003B060: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8003B064: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8003B068: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8003B06C: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8003B070: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8003B074: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8003B078: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B07C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8003B080: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8003B084: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8003B088: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x8003B08C: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x8003B090: jr          $ra
    // 0x8003B094: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8003B094: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void is_adventure_two_unlocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F1A4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009F1A8: lw          $t7, 0x69EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69EC);
    // 0x8009F1AC: jr          $ra
    // 0x8009F1B0: andi        $v0, $t7, 0x1
    ctx->r2 = ctx->r15 & 0X1;
    return;
    // 0x8009F1B0: andi        $v0, $t7, 0x1
    ctx->r2 = ctx->r15 & 0X1;
;}
RECOMP_FUNC void create_point_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0BF8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B0BFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B0C00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B0C04: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B0C08: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x800B0C0C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B0C10: lw          $t6, 0x3280($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3280);
    // 0x800B0C14: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B0C18: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B0C1C: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x800B0C20: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B0C24: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x800B0C28: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800B0C2C: beq         $t0, $at, L_800B0C3C
    if (ctx->r8 == ctx->r1) {
        // 0x800B0C30: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_800B0C3C;
    }
    // 0x800B0C30: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800B0C34: b           L_800B10FC
    // 0x800B0C38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B10FC;
    // 0x800B0C38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B0C3C:
    // 0x800B0C3C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800B0C40: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800B0C44: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B0C48: jal         0x800B2218
    // 0x800B0C4C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    particle_allocate(rdram, ctx);
        goto after_0;
    // 0x800B0C4C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x800B0C50: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0C54: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B0C58: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800B0C5C: bne         $v0, $zero, L_800B0C6C
    if (ctx->r2 != 0) {
        // 0x800B0C60: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800B0C6C;
    }
    // 0x800B0C60: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B0C64: b           L_800B10FC
    // 0x800B0C68: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800B10FC;
    // 0x800B0C68: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800B0C6C:
    // 0x800B0C6C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B0C70: addiu       $t3, $zero, -0x8000
    ctx->r11 = ADD32(0, -0X8000);
    // 0x800B0C74: lh          $t2, 0x2E($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2E);
    // 0x800B0C78: sh          $t3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r11;
    // 0x800B0C7C: sh          $t2, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r10;
    // 0x800B0C80: lbu         $t4, 0x1($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X1);
    // 0x800B0C84: nop

    // 0x800B0C88: sb          $t4, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r12;
    // 0x800B0C8C: lhu         $t5, 0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X2);
    // 0x800B0C90: nop

    // 0x800B0C94: sw          $t5, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r13;
    // 0x800B0C98: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800B0C9C: sw          $a2, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r6;
    // 0x800B0CA0: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
    // 0x800B0CA4: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800B0CA8: lwc1        $f6, 0x50($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X50);
    // 0x800B0CAC: andi        $t3, $t5, 0x800
    ctx->r11 = ctx->r13 & 0X800;
    // 0x800B0CB0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B0CB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B0CB8: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800B0CBC: lwc1        $f16, 0x54($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X54);
    // 0x800B0CC0: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800B0CC4: nop

    // 0x800B0CC8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B0CCC: swc1        $f18, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f18.u32l;
    // 0x800B0CD0: lh          $t6, 0x8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X8);
    // 0x800B0CD4: sb          $zero, 0x38($v0)
    MEM_B(0X38, ctx->r2) = 0;
    // 0x800B0CD8: swc1        $f4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f4.u32l;
    // 0x800B0CDC: sh          $t6, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r14;
    // 0x800B0CE0: lbu         $t8, 0x14($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X14);
    // 0x800B0CE4: nop

    // 0x800B0CE8: sb          $t8, 0x6C($v0)
    MEM_B(0X6C, ctx->r2) = ctx->r24;
    // 0x800B0CEC: lbu         $t9, 0x15($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X15);
    // 0x800B0CF0: nop

    // 0x800B0CF4: sb          $t9, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r25;
    // 0x800B0CF8: lbu         $t0, 0x16($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X16);
    // 0x800B0CFC: nop

    // 0x800B0D00: sb          $t0, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r8;
    // 0x800B0D04: lbu         $t1, 0x17($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X17);
    // 0x800B0D08: beq         $t3, $zero, L_800B0D64
    if (ctx->r11 == 0) {
        // 0x800B0D0C: sb          $t1, 0x6F($v0)
        MEM_B(0X6F, ctx->r2) = ctx->r9;
            goto L_800B0D64;
    }
    // 0x800B0D0C: sb          $t1, 0x6F($v0)
    MEM_B(0X6F, ctx->r2) = ctx->r9;
    // 0x800B0D10: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800B0D14: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800B0D18: lw          $a0, 0x54($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X54);
    // 0x800B0D1C: nop

    // 0x800B0D20: beq         $a0, $zero, L_800B0D64
    if (ctx->r4 == 0) {
        // 0x800B0D24: nop
    
            goto L_800B0D64;
    }
    // 0x800B0D24: nop

    // 0x800B0D28: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B0D2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B0D30: nop

    // 0x800B0D34: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B0D38: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800B0D3C: nop

    // 0x800B0D40: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800B0D44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0D48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B0D4C: nop

    // 0x800B0D50: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B0D54: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800B0D58: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800B0D5C: b           L_800B0D6C
    // 0x800B0D60: sh          $t7, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r15;
        goto L_800B0D6C;
    // 0x800B0D60: sh          $t7, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r15;
L_800B0D64:
    // 0x800B0D64: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800B0D68: sh          $t6, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r14;
L_800B0D6C:
    // 0x800B0D6C: lh          $t8, 0xE($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XE);
    // 0x800B0D70: nop

    // 0x800B0D74: sh          $t8, 0x60($v0)
    MEM_H(0X60, ctx->r2) = ctx->r24;
    // 0x800B0D78: lh          $t9, 0x4($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X4);
    // 0x800B0D7C: nop

    // 0x800B0D80: andi        $t0, $t9, 0x100
    ctx->r8 = ctx->r25 & 0X100;
    // 0x800B0D84: beq         $t0, $zero, L_800B0D98
    if (ctx->r8 == 0) {
        // 0x800B0D88: nop
    
            goto L_800B0D98;
    }
    // 0x800B0D88: nop

    // 0x800B0D8C: lh          $t1, 0xA($a2)
    ctx->r9 = MEM_H(ctx->r6, 0XA);
    // 0x800B0D90: b           L_800B0DA8
    // 0x800B0D94: sh          $t1, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r9;
        goto L_800B0DA8;
    // 0x800B0D94: sh          $t1, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r9;
L_800B0D98:
    // 0x800B0D98: lbu         $t2, 0xC($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XC);
    // 0x800B0D9C: nop

    // 0x800B0DA0: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x800B0DA4: sh          $t3, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r11;
L_800B0DA8:
    // 0x800B0DA8: lbu         $t4, 0xC($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XC);
    // 0x800B0DAC: nop

    // 0x800B0DB0: slti        $at, $t4, 0xFF
    ctx->r1 = SIGNED(ctx->r12) < 0XFF ? 1 : 0;
    // 0x800B0DB4: beq         $at, $zero, L_800B0DF4
    if (ctx->r1 == 0) {
        // 0x800B0DB8: nop
    
            goto L_800B0DF4;
    }
    // 0x800B0DB8: nop

    // 0x800B0DBC: lw          $t5, 0x40($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X40);
    // 0x800B0DC0: nop

    // 0x800B0DC4: andi        $t7, $t5, 0x1000
    ctx->r15 = ctx->r13 & 0X1000;
    // 0x800B0DC8: beq         $t7, $zero, L_800B0DE4
    if (ctx->r15 == 0) {
        // 0x800B0DCC: nop
    
            goto L_800B0DE4;
    }
    // 0x800B0DCC: nop

    // 0x800B0DD0: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x800B0DD4: nop

    // 0x800B0DD8: ori         $t8, $t6, 0x100
    ctx->r24 = ctx->r14 | 0X100;
    // 0x800B0DDC: b           L_800B0DF4
    // 0x800B0DE0: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
        goto L_800B0DF4;
    // 0x800B0DE0: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
L_800B0DE4:
    // 0x800B0DE4: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x800B0DE8: nop

    // 0x800B0DEC: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x800B0DF0: sh          $t0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r8;
L_800B0DF4:
    // 0x800B0DF4: lh          $a1, 0x60($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X60);
    // 0x800B0DF8: lh          $a0, 0x3A($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X3A);
    // 0x800B0DFC: nop

    // 0x800B0E00: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B0E04: beq         $at, $zero, L_800B0E58
    if (ctx->r1 == 0) {
        // 0x800B0E08: subu        $t7, $a0, $a1
        ctx->r15 = SUB32(ctx->r4, ctx->r5);
            goto L_800B0E58;
    }
    // 0x800B0E08: subu        $t7, $a0, $a1
    ctx->r15 = SUB32(ctx->r4, ctx->r5);
    // 0x800B0E0C: lbu         $t1, 0xD($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XD);
    // 0x800B0E10: lh          $t3, 0x5C($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X5C);
    // 0x800B0E14: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800B0E18: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800B0E1C: subu        $t5, $t2, $t4
    ctx->r13 = SUB32(ctx->r10, ctx->r12);
    // 0x800B0E20: div         $zero, $t5, $t7
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r15)));
    // 0x800B0E24: bne         $t7, $zero, L_800B0E30
    if (ctx->r15 != 0) {
        // 0x800B0E28: nop
    
            goto L_800B0E30;
    }
    // 0x800B0E28: nop

    // 0x800B0E2C: break       7
    do_break(2148208172);
L_800B0E30:
    // 0x800B0E30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B0E34: bne         $t7, $at, L_800B0E48
    if (ctx->r15 != ctx->r1) {
        // 0x800B0E38: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B0E48;
    }
    // 0x800B0E38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B0E3C: bne         $t5, $at, L_800B0E48
    if (ctx->r13 != ctx->r1) {
        // 0x800B0E40: nop
    
            goto L_800B0E48;
    }
    // 0x800B0E40: nop

    // 0x800B0E44: break       6
    do_break(2148208196);
L_800B0E48:
    // 0x800B0E48: mflo        $t6
    ctx->r14 = lo;
    // 0x800B0E4C: sh          $t6, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = ctx->r14;
    // 0x800B0E50: b           L_800B0E60
    // 0x800B0E54: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
        goto L_800B0E60;
    // 0x800B0E54: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_800B0E58:
    // 0x800B0E58: sh          $zero, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = 0;
    // 0x800B0E5C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_800B0E60:
    // 0x800B0E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B0E64: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B0E68: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800B0E6C: jal         0x800B0920
    // 0x800B0E70: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    setup_particle_position(rdram, ctx);
        goto after_1;
    // 0x800B0E70: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x800B0E74: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800B0E78: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0E7C: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800B0E80: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800B0E84: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B0E88: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800B0E8C: beq         $t9, $zero, L_800B0EB8
    if (ctx->r25 == 0) {
        // 0x800B0E90: nop
    
            goto L_800B0EB8;
    }
    // 0x800B0E90: nop

    // 0x800B0E94: lh          $t0, 0x44($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X44);
    // 0x800B0E98: nop

    // 0x800B0E9C: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x800B0EA0: lh          $t1, 0x46($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X46);
    // 0x800B0EA4: nop

    // 0x800B0EA8: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x800B0EAC: lh          $t3, 0x48($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X48);
    // 0x800B0EB0: b           L_800B0EF4
    // 0x800B0EB4: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
        goto L_800B0EF4;
    // 0x800B0EB4: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
L_800B0EB8:
    // 0x800B0EB8: lh          $t2, 0x0($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X0);
    // 0x800B0EBC: lh          $t4, 0x44($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X44);
    // 0x800B0EC0: nop

    // 0x800B0EC4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800B0EC8: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
    // 0x800B0ECC: lh          $t6, 0x46($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X46);
    // 0x800B0ED0: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x800B0ED4: nop

    // 0x800B0ED8: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800B0EDC: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x800B0EE0: lh          $t0, 0x48($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X48);
    // 0x800B0EE4: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x800B0EE8: nop

    // 0x800B0EEC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B0EF0: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
L_800B0EF4:
    // 0x800B0EF4: lh          $t3, 0x4A($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X4A);
    // 0x800B0EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B0EFC: sh          $t3, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r11;
    // 0x800B0F00: lh          $t2, 0x4C($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X4C);
    // 0x800B0F04: nop

    // 0x800B0F08: sh          $t2, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r10;
    // 0x800B0F0C: lh          $t4, 0x4E($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X4E);
    // 0x800B0F10: nop

    // 0x800B0F14: sh          $t4, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r12;
    // 0x800B0F18: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x800B0F1C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800B0F20: jal         0x800B0570
    // 0x800B0F24: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    setup_particle_velocity(rdram, ctx);
        goto after_2;
    // 0x800B0F24: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800B0F28: lw          $t5, 0x40($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X40);
    // 0x800B0F2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0F30: sra         $t7, $t5, 4
    ctx->r15 = S32(SIGNED(ctx->r13) >> 4);
    // 0x800B0F34: andi        $t6, $t7, 0x7
    ctx->r14 = ctx->r15 & 0X7;
    // 0x800B0F38: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800B0F3C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B0F40: lwc1        $f18, 0x33BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X33BC);
    // 0x800B0F44: lbu         $t9, 0x39($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X39);
    // 0x800B0F48: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0F4C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B0F50: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800B0F54: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800B0F58: bne         $t9, $at, L_800B0FA0
    if (ctx->r25 != ctx->r1) {
        // 0x800B0F5C: swc1        $f18, 0x68($s0)
        MEM_W(0X68, ctx->r16) = ctx->f18.u32l;
            goto L_800B0FA0;
    }
    // 0x800B0F5C: swc1        $f18, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f18.u32l;
    // 0x800B0F60: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B0F64: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B0F68: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B0F6C: lwc1        $f14, 0x24($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B0F70: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x800B0F74: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800B0F78: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800B0F7C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B0F80: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800B0F84: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B0F88: jal         0x800CA030
    // 0x800B0F8C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800B0F8C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_3:
    // 0x800B0F90: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0F94: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B0F98: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800B0F9C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_800B0FA0:
    // 0x800B0FA0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800B0FA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B0FA8: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    // 0x800B0FAC: beq         $t0, $zero, L_800B0FE4
    if (ctx->r8 == 0) {
        // 0x800B0FB0: andi        $t6, $v0, 0x8
        ctx->r14 = ctx->r2 & 0X8;
            goto L_800B0FE4;
    }
    // 0x800B0FB0: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
    // 0x800B0FB4: lh          $t1, 0x10($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X10);
    // 0x800B0FB8: lh          $t3, 0x1C($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X1C);
    // 0x800B0FBC: lh          $t4, 0x12($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X12);
    // 0x800B0FC0: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x800B0FC4: sh          $t2, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r10;
    // 0x800B0FC8: lh          $t5, 0x1E($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X1E);
    // 0x800B0FCC: nop

    // 0x800B0FD0: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x800B0FD4: sh          $t7, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r15;
    // 0x800B0FD8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800B0FDC: nop

    // 0x800B0FE0: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
L_800B0FE4:
    // 0x800B0FE4: beq         $t6, $zero, L_800B1010
    if (ctx->r14 == 0) {
        // 0x800B0FE8: nop
    
            goto L_800B1010;
    }
    // 0x800B0FE8: nop

    // 0x800B0FEC: lh          $t8, 0x14($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X14);
    // 0x800B0FF0: lh          $t9, 0x2A($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X2A);
    // 0x800B0FF4: lh          $t1, 0x16($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X16);
    // 0x800B0FF8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800B0FFC: sh          $t0, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r8;
    // 0x800B1000: lh          $t3, 0x2C($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2C);
    // 0x800B1004: nop

    // 0x800B1008: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x800B100C: sh          $t2, 0x16($a2)
    MEM_H(0X16, ctx->r6) = ctx->r10;
L_800B1010:
    // 0x800B1010: lh          $t4, 0x6($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X6);
    // 0x800B1014: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x800B1018: sh          $t4, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r12;
    // 0x800B101C: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    // 0x800B1020: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x800B1024: bne         $a0, $at, L_800B1034
    if (ctx->r4 != ctx->r1) {
        // 0x800B1028: nop
    
            goto L_800B1034;
    }
    // 0x800B1028: nop

    // 0x800B102C: b           L_800B10C8
    // 0x800B1030: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_800B10C8;
    // 0x800B1030: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800B1034:
    // 0x800B1034: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B1038: jal         0x8007B2C4
    // 0x800B103C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    load_texture(rdram, ctx);
        goto after_4;
    // 0x800B103C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x800B1040: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B1044: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B1048: beq         $v0, $zero, L_800B10C8
    if (ctx->r2 == 0) {
        // 0x800B104C: sw          $v0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r2;
            goto L_800B10C8;
    }
    // 0x800B104C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800B1050: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x800B1054: nop

    // 0x800B1058: andi        $t6, $t7, 0x4
    ctx->r14 = ctx->r15 & 0X4;
    // 0x800B105C: beq         $t6, $zero, L_800B109C
    if (ctx->r14 == 0) {
        // 0x800B1060: nop
    
            goto L_800B109C;
    }
    // 0x800B1060: nop

    // 0x800B1064: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x800B1068: nop

    // 0x800B106C: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x800B1070: beq         $t9, $zero, L_800B108C
    if (ctx->r25 == 0) {
        // 0x800B1074: nop
    
            goto L_800B108C;
    }
    // 0x800B1074: nop

    // 0x800B1078: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800B107C: nop

    // 0x800B1080: ori         $t1, $t0, 0x100
    ctx->r9 = ctx->r8 | 0X100;
    // 0x800B1084: b           L_800B109C
    // 0x800B1088: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
        goto L_800B109C;
    // 0x800B1088: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
L_800B108C:
    // 0x800B108C: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x800B1090: nop

    // 0x800B1094: ori         $t2, $t3, 0x80
    ctx->r10 = ctx->r11 | 0X80;
    // 0x800B1098: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
L_800B109C:
    // 0x800B109C: lw          $t4, 0x40($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X40);
    // 0x800B10A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B10A4: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x800B10A8: bne         $t5, $at, L_800B10C8
    if (ctx->r13 != ctx->r1) {
        // 0x800B10AC: nop
    
            goto L_800B10C8;
    }
    // 0x800B10AC: nop

    // 0x800B10B0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800B10B4: nop

    // 0x800B10B8: lhu         $t6, 0x12($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X12);
    // 0x800B10BC: nop

    // 0x800B10C0: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x800B10C4: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
L_800B10C8:
    // 0x800B10C8: sb          $zero, 0x75($s0)
    MEM_B(0X75, ctx->r16) = 0;
    // 0x800B10CC: lhu         $t9, 0xA($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XA);
    // 0x800B10D0: sb          $zero, 0x77($s0)
    MEM_B(0X77, ctx->r16) = 0;
    // 0x800B10D4: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x800B10D8: sb          $t0, 0x76($s0)
    MEM_B(0X76, ctx->r16) = ctx->r8;
    // 0x800B10DC: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800B10E0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B10E4: bne         $t1, $zero, L_800B10FC
    if (ctx->r9 != 0) {
        // 0x800B10E8: nop
    
            goto L_800B10FC;
    }
    // 0x800B10E8: nop

    // 0x800B10EC: jal         0x800B25A0
    // 0x800B10F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    particle_deallocate(rdram, ctx);
        goto after_5;
    // 0x800B10F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800B10F4: b           L_800B10FC
    // 0x800B10F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B10FC;
    // 0x800B10F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B10FC:
    // 0x800B10FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1100: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B1104: jr          $ra
    // 0x800B1108: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B1108: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void read_eeprom_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074ACC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80074AD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074AD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074AD8: jal         0x8006A340
    // 0x80074ADC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80074ADC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80074AE0: jal         0x800CE770
    // 0x80074AE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x80074AE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074AE8: bne         $v0, $zero, L_80074AF8
    if (ctx->r2 != 0) {
        // 0x80074AEC: nop
    
            goto L_80074AF8;
    }
    // 0x80074AEC: nop

    // 0x80074AF0: b           L_80074BC4
    // 0x80074AF4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80074BC4;
    // 0x80074AF4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074AF8:
    // 0x80074AF8: jal         0x8006A340
    // 0x80074AFC: nop

    si_mesg(rdram, ctx);
        goto after_2;
    // 0x80074AFC: nop

    after_2:
    // 0x80074B00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074B04: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80074B08: jal         0x800CE7E0
    // 0x80074B0C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osEepromRead_recomp(rdram, ctx);
        goto after_3;
    // 0x80074B0C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x80074B10: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80074B14: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80074B18: jal         0x80074A64
    // 0x80074B1C: nop

    calculate_eeprom_settings_checksum(rdram, ctx);
        goto after_4;
    // 0x80074B1C: nop

    after_4:
    // 0x80074B20: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80074B24: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80074B28: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80074B2C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074B30: jal         0x800CEFC0
    // 0x80074B34: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    __ull_rshift_recomp(rdram, ctx);
        goto after_5;
    // 0x80074B34: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    after_5:
    // 0x80074B38: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80074B3C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80074B40: beq         $t6, $v1, L_80074BC0
    if (ctx->r14 == ctx->r3) {
        // 0x80074B44: lui         $t9, 0x300
        ctx->r25 = S32(0X300 << 16);
            goto L_80074BC0;
    }
    // 0x80074B44: lui         $t9, 0x300
    ctx->r25 = S32(0X300 << 16);
    // 0x80074B48: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80074B4C: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80074B50: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80074B54: lui         $a1, 0x300
    ctx->r5 = S32(0X300 << 16);
    // 0x80074B58: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074B5C: jal         0x800CF064
    // 0x80074B60: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ll_lshift_recomp(rdram, ctx);
        goto after_6;
    // 0x80074B60: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_6:
    // 0x80074B64: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80074B68: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x80074B6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074B70: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80074B74: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074B78: jal         0x800CEFC0
    // 0x80074B7C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ull_rshift_recomp(rdram, ctx);
        goto after_7;
    // 0x80074B7C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_7:
    // 0x80074B80: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80074B84: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x80074B88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074B8C: jal         0x80074A64
    // 0x80074B90: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    calculate_eeprom_settings_checksum(rdram, ctx);
        goto after_8;
    // 0x80074B90: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_8:
    // 0x80074B94: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80074B98: sra         $a0, $v0, 31
    ctx->r4 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80074B9C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074BA0: jal         0x800CF064
    // 0x80074BA4: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    __ll_lshift_recomp(rdram, ctx);
        goto after_9;
    // 0x80074BA4: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    after_9:
    // 0x80074BA8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80074BAC: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80074BB0: or          $t2, $t0, $v0
    ctx->r10 = ctx->r8 | ctx->r2;
    // 0x80074BB4: or          $t3, $t1, $v1
    ctx->r11 = ctx->r9 | ctx->r3;
    // 0x80074BB8: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x80074BBC: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
L_80074BC0:
    // 0x80074BC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80074BC4:
    // 0x80074BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074BC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074BCC: jr          $ra
    // 0x80074BD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80074BD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bgdraw_chequer_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078BC8: sra         $t7, $a0, 24
    ctx->r15 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80078BCC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078BD0: sb          $t7, 0x64D0($at)
    MEM_B(0X64D0, ctx->r1) = ctx->r15;
    // 0x80078BD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078BD8: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80078BDC: sb          $t9, 0x64D1($at)
    MEM_B(0X64D1, ctx->r1) = ctx->r25;
    // 0x80078BE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078BE4: sra         $t1, $a0, 8
    ctx->r9 = S32(SIGNED(ctx->r4) >> 8);
    // 0x80078BE8: sb          $t1, 0x64D2($at)
    MEM_B(0X64D2, ctx->r1) = ctx->r9;
    // 0x80078BEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078BF0: sb          $a0, 0x64D3($at)
    MEM_B(0X64D3, ctx->r1) = ctx->r4;
    // 0x80078BF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078BF8: sra         $t4, $a1, 24
    ctx->r12 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80078BFC: sb          $t4, 0x64D4($at)
    MEM_B(0X64D4, ctx->r1) = ctx->r12;
    // 0x80078C00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078C04: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80078C08: sb          $t6, 0x64D5($at)
    MEM_B(0X64D5, ctx->r1) = ctx->r14;
    // 0x80078C0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078C10: sra         $t8, $a1, 8
    ctx->r24 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80078C14: sb          $t8, 0x64D6($at)
    MEM_B(0X64D6, ctx->r1) = ctx->r24;
    // 0x80078C18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078C1C: sb          $a1, 0x64D7($at)
    MEM_B(0X64D7, ctx->r1) = ctx->r5;
    // 0x80078C20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078C24: sw          $a2, 0x64D8($at)
    MEM_W(0X64D8, ctx->r1) = ctx->r6;
    // 0x80078C28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078C2C: sw          $a3, 0x64DC($at)
    MEM_W(0X64DC, ctx->r1) = ctx->r7;
    // 0x80078C30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80078C34: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80078C38: jr          $ra
    // 0x80078C3C: sw          $t0, -0x15B4($at)
    MEM_W(-0X15B4, ctx->r1) = ctx->r8;
    return;
    // 0x80078C3C: sw          $t0, -0x15B4($at)
    MEM_W(-0X15B4, ctx->r1) = ctx->r8;
;}
RECOMP_FUNC void filename_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097DB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097DB4: sw          $a0, 0x1510($at)
    MEM_W(0X1510, ctx->r1) = ctx->r4;
    // 0x80097DB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097DBC: sw          $a1, 0x1514($at)
    MEM_W(0X1514, ctx->r1) = ctx->r5;
    // 0x80097DC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097DC4: sw          $a2, 0x1518($at)
    MEM_W(0X1518, ctx->r1) = ctx->r6;
    // 0x80097DC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097DCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097DD0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80097DD4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80097DD8: sw          $a3, 0x151C($at)
    MEM_W(0X151C, ctx->r1) = ctx->r7;
    // 0x80097DDC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80097DE0: addiu       $v0, $v0, 0x722C
    ctx->r2 = ADD32(ctx->r2, 0X722C);
    // 0x80097DE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80097DE8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80097DEC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80097DF0: sw          $t8, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = ctx->r24;
    // 0x80097DF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80097DF8: sw          $t9, 0x723C($at)
    MEM_W(0X723C, ctx->r1) = ctx->r25;
    // 0x80097DFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097E00: sw          $zero, 0x1520($at)
    MEM_W(0X1520, ctx->r1) = 0;
    // 0x80097E04: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80097E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097E0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097E10: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80097E14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80097E18: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80097E1C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80097E20: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80097E24: swc1        $f6, 0x7210($at)
    MEM_W(0X7210, ctx->r1) = ctx->f6.u32l;
    // 0x80097E28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80097E2C: sw          $zero, 0x7208($at)
    MEM_W(0X7208, ctx->r1) = 0;
    // 0x80097E30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80097E34: sw          $zero, 0x71FC($at)
    MEM_W(0X71FC, ctx->r1) = 0;
    // 0x80097E38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80097E3C: jal         0x800C46D0
    // 0x80097E40: sw          $zero, 0x71F4($at)
    MEM_W(0X71F4, ctx->r1) = 0;
    load_font(rdram, ctx);
        goto after_0;
    // 0x80097E40: sw          $zero, 0x71F4($at)
    MEM_W(0X71F4, ctx->r1) = 0;
    after_0:
    // 0x80097E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097E48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097E4C: jr          $ra
    // 0x80097E50: nop

    return;
    // 0x80097E50: nop

;}
RECOMP_FUNC void obj_init_airzippers_waterzippers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800358CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800358D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800358D4: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x800358D8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800358DC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800358E0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800358E4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800358E8: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800358EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800358F0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800358F4: nop

    // 0x800358F8: bc1f        L_80035908
    if (!c1cs) {
        // 0x800358FC: nop
    
            goto L_80035908;
    }
    // 0x800358FC: nop

    // 0x80035900: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80035904: nop

L_80035908:
    // 0x80035908: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003590C: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80035910: lb          $t1, 0x3A($a0)
    ctx->r9 = MEM_B(ctx->r4, 0X3A);
    // 0x80035914: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80035918: nop

    // 0x8003591C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80035920: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80035924: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x80035928: nop

    // 0x8003592C: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x80035930: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x80035934: lb          $t2, 0x55($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X55);
    // 0x80035938: nop

    // 0x8003593C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80035940: bne         $at, $zero, L_8003594C
    if (ctx->r1 != 0) {
        // 0x80035944: nop
    
            goto L_8003594C;
    }
    // 0x80035944: nop

    // 0x80035948: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_8003594C:
    // 0x8003594C: lw          $t4, 0x4C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4C);
    // 0x80035950: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80035954: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x80035958: lw          $t5, 0x4C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4C);
    // 0x8003595C: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80035960: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
    // 0x80035964: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80035968: nop

    // 0x8003596C: sb          $t6, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r14;
    // 0x80035970: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80035974: nop

    // 0x80035978: sb          $zero, 0x12($t8)
    MEM_B(0X12, ctx->r24) = 0;
    // 0x8003597C: jal         0x8009C850
    // 0x80035980: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x80035980: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80035984: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80035988: sll         $t9, $v0, 10
    ctx->r25 = S32(ctx->r2 << 10);
    // 0x8003598C: bgez        $t9, L_800359A0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80035990: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800359A0;
    }
    // 0x80035990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035994: jal         0x8000FFB8
    // 0x80035998: nop

    free_object(rdram, ctx);
        goto after_1;
    // 0x80035998: nop

    after_1:
    // 0x8003599C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800359A0:
    // 0x800359A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800359A4: jr          $ra
    // 0x800359A8: nop

    return;
    // 0x800359A8: nop

;}
RECOMP_FUNC void music_enabled_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001878: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000187C: addiu       $v0, $v0, -0x3450
    ctx->r2 = ADD32(ctx->r2, -0X3450);
    // 0x80001880: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80001884: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001888: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8000188C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001890: beq         $t7, $t6, L_800018C0
    if (ctx->r15 == ctx->r14) {
        // 0x80001894: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800018C0;
    }
    // 0x80001894: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001898: beq         $t6, $zero, L_800018B8
    if (ctx->r14 == 0) {
        // 0x8000189C: sb          $t6, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r14;
            goto L_800018B8;
    }
    // 0x8000189C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800018A0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800018A4: lbu         $a0, 0x6284($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X6284);
    // 0x800018A8: jal         0x80000B34
    // 0x800018AC: nop

    music_play(rdram, ctx);
        goto after_0;
    // 0x800018AC: nop

    after_0:
    // 0x800018B0: b           L_800018C4
    // 0x800018B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800018C4;
    // 0x800018B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800018B8:
    // 0x800018B8: jal         0x80001844
    // 0x800018BC: nop

    music_stop(rdram, ctx);
        goto after_1;
    // 0x800018BC: nop

    after_1:
L_800018C0:
    // 0x800018C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800018C4:
    // 0x800018C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800018C8: jr          $ra
    // 0x800018CC: nop

    return;
    // 0x800018CC: nop

;}
RECOMP_FUNC void func_8006D8F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DB30: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006DB34: lw          $t6, 0x3A6C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3A6C);
    // 0x8006DB38: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006DB3C: beq         $t6, $at, L_8006DBA0
    if (ctx->r14 == ctx->r1) {
        // 0x8006DB40: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_8006DBA0;
    }
    // 0x8006DB40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006DB44: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DB48: addiu       $a0, $a0, 0x17D0
    ctx->r4 = ADD32(ctx->r4, 0X17D0);
    // 0x8006DB4C: lb          $t7, 0x0($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X0);
    // 0x8006DB50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DB54: sw          $t7, 0x3A74($at)
    MEM_W(0X3A74, ctx->r1) = ctx->r15;
    // 0x8006DB58: lb          $v1, 0xF($a0)
    ctx->r3 = MEM_B(ctx->r4, 0XF);
    // 0x8006DB5C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006DB60: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006DB64: addiu       $a2, $a2, 0x3A88
    ctx->r6 = ADD32(ctx->r6, 0X3A88);
    // 0x8006DB68: addiu       $a1, $a1, 0x3A84
    ctx->r5 = ADD32(ctx->r5, 0X3A84);
    // 0x8006DB6C: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8006DB70: lb          $v0, 0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1);
    // 0x8006DB74: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8006DB78: bltz        $v1, L_8006DB84
    if (SIGNED(ctx->r3) < 0) {
        // 0x8006DB7C: sw          $t8, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r24;
            goto L_8006DB84;
    }
    // 0x8006DB7C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8006DB80: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_8006DB84:
    // 0x8006DB84: addu        $t9, $a0, $v0
    ctx->r25 = ADD32(ctx->r4, ctx->r2);
    // 0x8006DB88: lb          $v1, 0x8($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X8);
    // 0x8006DB8C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8006DB90: bltz        $v1, L_8006DB9C
    if (SIGNED(ctx->r3) < 0) {
        // 0x8006DB94: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8006DB9C;
    }
    // 0x8006DB94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DB98: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
L_8006DB9C:
    // 0x8006DB9C: sw          $t0, 0x3A78($at)
    MEM_W(0X3A78, ctx->r1) = ctx->r8;
L_8006DBA0:
    // 0x8006DBA0: jr          $ra
    // 0x8006DBA4: nop

    return;
    // 0x8006DBA4: nop

;}
RECOMP_FUNC void hud_element_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AAB5C: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800AAB60: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AAB64: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800AAB68: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x800AAB6C: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x800AAB70: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x800AAB74: lh          $t0, 0x6($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X6);
    // 0x800AAB78: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800AAB7C: lw          $v1, 0x72B0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72B0);
    // 0x800AAB80: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x800AAB84: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800AAB88: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800AAB8C: ori         $t2, $zero, 0xC000
    ctx->r10 = 0 | 0XC000;
    // 0x800AAB90: andi        $v0, $t8, 0xC000
    ctx->r2 = ctx->r24 & 0XC000;
    // 0x800AAB94: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800AAB98: bne         $t2, $v0, L_800AABB8
    if (ctx->r10 != ctx->r2) {
        // 0x800AAB9C: sw          $t8, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r24;
            goto L_800AABB8;
    }
    // 0x800AAB9C: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800AABA0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AABA4: lb          $t3, 0x7290($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X7290);
    // 0x800AABA8: nop

    // 0x800AABAC: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x800AABB0: b           L_800AABC8
    // 0x800AABB4: sw          $t4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r12;
        goto L_800AABC8;
    // 0x800AABB4: sw          $t4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r12;
L_800AABB8:
    // 0x800AABB8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AABBC: lb          $t5, 0x7290($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X7290);
    // 0x800AABC0: nop

    // 0x800AABC4: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
L_800AABC8:
    // 0x800AABC8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AABCC: addiu       $t1, $t1, 0x72B4
    ctx->r9 = ADD32(ctx->r9, 0X72B4);
    // 0x800AABD0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800AABD4: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800AABD8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AABDC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800AABE0: nop

    // 0x800AABE4: bne         $t9, $zero, L_800AAD10
    if (ctx->r25 != 0) {
        // 0x800AABE8: nop
    
            goto L_800AAD10;
    }
    // 0x800AABE8: nop

    // 0x800AABEC: bne         $t2, $v0, L_800AAC2C
    if (ctx->r10 != ctx->r2) {
        // 0x800AABF0: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_800AAC2C;
    }
    // 0x800AABF0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800AABF4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800AABF8: nop

    // 0x800AABFC: andi        $t3, $a0, 0x3FFF
    ctx->r11 = ctx->r4 & 0X3FFF;
    // 0x800AAC00: jal         0x8007B2C4
    // 0x800AAC04: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    load_texture(rdram, ctx);
        goto after_0;
    // 0x800AAC04: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_0:
    // 0x800AAC08: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AAC0C: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x800AAC10: addiu       $t1, $t1, 0x72B4
    ctx->r9 = ADD32(ctx->r9, 0X72B4);
    // 0x800AAC14: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800AAC18: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800AAC1C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800AAC20: b           L_800AACF4
    // 0x800AAC24: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
        goto L_800AACF4;
    // 0x800AAC24: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x800AAC28: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
L_800AAC2C:
    // 0x800AAC2C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800AAC30: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800AAC34: beq         $t9, $zero, L_800AAC64
    if (ctx->r25 == 0) {
        // 0x800AAC38: andi        $a0, $t8, 0x3FFF
        ctx->r4 = ctx->r24 & 0X3FFF;
            goto L_800AAC64;
    }
    // 0x800AAC38: andi        $a0, $t8, 0x3FFF
    ctx->r4 = ctx->r24 & 0X3FFF;
    // 0x800AAC3C: jal         0x8007C57C
    // 0x800AAC40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    tex_load_sprite(rdram, ctx);
        goto after_1;
    // 0x800AAC40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800AAC44: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AAC48: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x800AAC4C: addiu       $t1, $t1, 0x72B4
    ctx->r9 = ADD32(ctx->r9, 0X72B4);
    // 0x800AAC50: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800AAC54: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x800AAC58: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x800AAC5C: b           L_800AACF4
    // 0x800AAC60: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
        goto L_800AACF4;
    // 0x800AAC60: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
L_800AAC64:
    // 0x800AAC64: andi        $t9, $t7, 0x4000
    ctx->r25 = ctx->r15 & 0X4000;
    // 0x800AAC68: beq         $t9, $zero, L_800AACCC
    if (ctx->r25 == 0) {
        // 0x800AAC6C: or          $t8, $t7, $zero
        ctx->r24 = ctx->r15 | 0;
            goto L_800AACCC;
    }
    // 0x800AAC6C: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x800AAC70: sb          $t8, 0x9C($sp)
    MEM_B(0X9C, ctx->r29) = ctx->r24;
    // 0x800AAC74: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x800AAC78: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x800AAC7C: sll         $t3, $t5, 1
    ctx->r11 = S32(ctx->r13 << 1);
    // 0x800AAC80: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x800AAC84: lh          $t6, 0x0($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X0);
    // 0x800AAC88: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x800AAC8C: andi        $t9, $t6, 0x100
    ctx->r25 = ctx->r14 & 0X100;
    // 0x800AAC90: sra         $t7, $t9, 1
    ctx->r15 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800AAC94: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x800AAC98: sb          $t8, 0x9D($sp)
    MEM_B(0X9D, ctx->r29) = ctx->r24;
    // 0x800AAC9C: sh          $zero, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = 0;
    // 0x800AACA0: sh          $zero, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = 0;
    // 0x800AACA4: jal         0x8000EA54
    // 0x800AACA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    spawn_object(rdram, ctx);
        goto after_2;
    // 0x800AACA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800AACAC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AACB0: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x800AACB4: addiu       $t1, $t1, 0x72B4
    ctx->r9 = ADD32(ctx->r9, 0X72B4);
    // 0x800AACB8: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800AACBC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800AACC0: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x800AACC4: b           L_800AACF4
    // 0x800AACC8: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
        goto L_800AACF4;
    // 0x800AACC8: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
L_800AACCC:
    // 0x800AACCC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800AACD0: jal         0x8005FB3C
    // 0x800AACD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    object_model_init(rdram, ctx);
        goto after_3;
    // 0x800AACD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800AACD8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AACDC: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x800AACE0: addiu       $t1, $t1, 0x72B4
    ctx->r9 = ADD32(ctx->r9, 0X72B4);
    // 0x800AACE4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800AACE8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AACEC: addu        $t3, $t9, $t8
    ctx->r11 = ADD32(ctx->r25, ctx->r24);
    // 0x800AACF0: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
L_800AACF4:
    // 0x800AACF4: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800AACF8: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800AACFC: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x800AAD00: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x800AAD04: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800AAD08: nop

    // 0x800AAD0C: beq         $t7, $zero, L_800AB51C
    if (ctx->r15 == 0) {
        // 0x800AAD10: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800AB51C;
    }
L_800AAD10:
    // 0x800AAD10: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AAD14: lw          $t9, 0x7298($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7298);
    // 0x800AAD18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AAD1C: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800AAD20: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x800AAD24: lw          $t3, 0xB8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB8);
    // 0x800AAD28: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    // 0x800AAD2C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800AAD30: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x800AAD34: sw          $t5, 0x72BC($at)
    MEM_W(0X72BC, ctx->r1) = ctx->r13;
    // 0x800AAD38: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800AAD3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AAD40: sw          $t6, 0x72C0($at)
    MEM_W(0X72C0, ctx->r1) = ctx->r14;
    // 0x800AAD44: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800AAD48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AAD4C: sw          $t9, 0x72C4($at)
    MEM_W(0X72C4, ctx->r1) = ctx->r25;
    // 0x800AAD50: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800AAD54: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x800AAD58: beq         $t0, $at, L_800AADE0
    if (ctx->r8 == ctx->r1) {
        // 0x800AAD5C: ori         $t2, $zero, 0xC000
        ctx->r10 = 0 | 0XC000;
            goto L_800AADE0;
    }
    // 0x800AAD5C: ori         $t2, $zero, 0xC000
    ctx->r10 = 0 | 0XC000;
    // 0x800AAD60: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800AAD64: beq         $t0, $at, L_800AADB8
    if (ctx->r8 == ctx->r1) {
        // 0x800AAD68: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_800AADB8;
    }
    // 0x800AAD68: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AAD6C: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x800AAD70: beq         $t0, $at, L_800AADB8
    if (ctx->r8 == ctx->r1) {
        // 0x800AAD74: slti        $at, $t0, 0x2F
        ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
            goto L_800AADB8;
    }
    // 0x800AAD74: slti        $at, $t0, 0x2F
    ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
    // 0x800AAD78: bne         $at, $zero, L_800AAD84
    if (ctx->r1 != 0) {
        // 0x800AAD7C: slti        $at, $t0, 0x36
        ctx->r1 = SIGNED(ctx->r8) < 0X36 ? 1 : 0;
            goto L_800AAD84;
    }
    // 0x800AAD7C: slti        $at, $t0, 0x36
    ctx->r1 = SIGNED(ctx->r8) < 0X36 ? 1 : 0;
    // 0x800AAD80: bne         $at, $zero, L_800AADB8
    if (ctx->r1 != 0) {
        // 0x800AAD84: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800AADB8;
    }
L_800AAD84:
    // 0x800AAD84: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x800AAD88: beq         $t0, $at, L_800AADB8
    if (ctx->r8 == ctx->r1) {
        // 0x800AAD8C: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800AADB8;
    }
    // 0x800AAD8C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800AAD90: lb          $t8, 0x7293($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X7293);
    // 0x800AAD94: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x800AAD98: andi        $t3, $t8, 0x1
    ctx->r11 = ctx->r24 & 0X1;
    // 0x800AAD9C: beq         $t3, $zero, L_800AADB8
    if (ctx->r11 == 0) {
        // 0x800AADA0: nop
    
            goto L_800AADB8;
    }
    // 0x800AADA0: nop

    // 0x800AADA4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800AADA8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AADAC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AADB0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AADB4: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
L_800AADB8:
    // 0x800AADB8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800AADBC: lw          $t6, 0x72E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72E8);
    // 0x800AADC0: lw          $t4, 0x72E4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72E4);
    // 0x800AADC4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AADC8: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800AADCC: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800AADD0: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800AADD4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AADD8: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800AADDC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_800AADE0:
    // 0x800AADE0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AADE4: lw          $t9, 0x72B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72B0);
    // 0x800AADE8: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x800AADEC: addu        $t3, $t9, $t8
    ctx->r11 = ADD32(ctx->r25, ctx->r24);
    // 0x800AADF0: lh          $v0, 0x0($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X0);
    // 0x800AADF4: slti        $at, $t0, 0x2F
    ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
    // 0x800AADF8: andi        $t5, $v0, 0xC000
    ctx->r13 = ctx->r2 & 0XC000;
    // 0x800AADFC: bne         $t2, $t5, L_800AB300
    if (ctx->r10 != ctx->r13) {
        // 0x800AAE00: andi        $t9, $v0, 0x8000
        ctx->r25 = ctx->r2 & 0X8000;
            goto L_800AB300;
    }
    // 0x800AAE00: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x800AAE04: bne         $at, $zero, L_800AB05C
    if (ctx->r1 != 0) {
        // 0x800AAE08: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800AB05C;
    }
    // 0x800AAE08: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AAE0C: slti        $at, $t0, 0x36
    ctx->r1 = SIGNED(ctx->r8) < 0X36 ? 1 : 0;
    // 0x800AAE10: beq         $at, $zero, L_800AB05C
    if (ctx->r1 == 0) {
        // 0x800AAE14: lui         $a0, 0x8000
        ctx->r4 = S32(0X8000 << 16);
            goto L_800AB05C;
    }
    // 0x800AAE14: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800AAE18: lw          $a0, 0x300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X300);
    // 0x800AAE1C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800AAE20: bne         $a0, $zero, L_800AAE48
    if (ctx->r4 != 0) {
        // 0x800AAE24: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_800AAE48;
    }
    // 0x800AAE24: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AAE28: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AAE2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AAE30: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800AAE34: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AAE38: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800AAE3C: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x800AAE40: lw          $a0, 0x300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X300);
    // 0x800AAE44: nop

L_800AAE48:
    // 0x800AAE48: lb          $t4, 0x7293($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X7293);
    // 0x800AAE4C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800AAE50: andi        $t6, $t4, 0x2
    ctx->r14 = ctx->r12 & 0X2;
    // 0x800AAE54: beq         $t6, $zero, L_800AAED0
    if (ctx->r14 == 0) {
        // 0x800AAE58: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_800AAED0;
    }
    // 0x800AAE58: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800AAE5C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800AAE60: lb          $t7, 0x7290($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7290);
    // 0x800AAE64: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AAE68: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800AAE6C: lbu         $t9, 0x774B($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X774B);
    // 0x800AAE70: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AAE74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AAE78: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800AAE7C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800AAE80: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AAE84: bgez        $t9, L_800AAE98
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800AAE88: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800AAE98;
    }
    // 0x800AAE88: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AAE8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AAE90: nop

    // 0x800AAE94: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800AAE98:
    // 0x800AAE98: nop

    // 0x800AAE9C: div.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AAEA0: sub.s       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800AAEA4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AAEA8: nop

    // 0x800AAEAC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AAEB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AAEB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AAEB8: nop

    // 0x800AAEBC: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AAEC0: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800AAEC4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AAEC8: b           L_800AAED4
    // 0x800AAECC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
        goto L_800AAED4;
    // 0x800AAECC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
L_800AAED0:
    // 0x800AAED0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
L_800AAED4:
    // 0x800AAED4: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800AAED8: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x800AAEDC: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800AAEE0: lh          $t6, 0x18($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X18);
    // 0x800AAEE4: lh          $t7, 0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X16);
    // 0x800AAEE8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AAEEC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AAEF0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AAEF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AAEF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AAEFC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800AAF00: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x800AAF04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AAF08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AAF0C: mflo        $t9
    ctx->r25 = lo;
    // 0x800AAF10: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800AAF14: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x800AAF18: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AAF1C: nop

    // 0x800AAF20: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AAF24: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AAF28: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800AAF2C: nop

    // 0x800AAF30: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AAF34: sh          $t3, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r11;
    // 0x800AAF38: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800AAF3C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AAF40: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AAF44: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AAF48: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x800AAF4C: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AAF50: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800AAF54: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AAF58: bne         $a0, $zero, L_800AB00C
    if (ctx->r4 != 0) {
        // 0x800AAF5C: sh          $t4, 0x8E($sp)
        MEM_H(0X8E, ctx->r29) = ctx->r12;
            goto L_800AB00C;
    }
    // 0x800AAF5C: sh          $t4, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r12;
    // 0x800AAF60: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x800AAF64: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x800AAF68: bne         $t6, $at, L_800AAFD4
    if (ctx->r14 != ctx->r1) {
        // 0x800AAF6C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800AAFD4;
    }
    // 0x800AAF6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AAF70: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800AAF74: bne         $v1, $at, L_800AAF84
    if (ctx->r3 != ctx->r1) {
        // 0x800AAF78: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800AAF84;
    }
    // 0x800AAF78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AAF7C: b           L_800AAF8C
    // 0x800AAF80: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_800AAF8C;
    // 0x800AAF80: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_800AAF84:
    // 0x800AAF84: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800AAF88: or          $v0, $v1, $at
    ctx->r2 = ctx->r3 | ctx->r1;
L_800AAF8C:
    // 0x800AAF8C: sh          $zero, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = 0;
    // 0x800AAF90: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x800AAF94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AAF98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AAF9C: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x800AAFA0: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800AAFA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AAFA8: lwc1        $f8, -0x72A8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X72A8);
    // 0x800AAFAC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AAFB0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800AAFB4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800AAFB8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AAFBC: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x800AAFC0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800AAFC4: jal         0x80079150
    // 0x800AAFC8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_4;
    // 0x800AAFC8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x800AAFCC: b           L_800AB030
    // 0x800AAFD0: nop

        goto L_800AB030;
    // 0x800AAFD0: nop

L_800AAFD4:
    // 0x800AAFD4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800AAFD8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800AAFDC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800AAFE0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800AAFE4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800AAFE8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800AAFEC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AAFF0: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x800AAFF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AAFF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AAFFC: jal         0x80078F08
    // 0x800AB000: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    texrect_draw(rdram, ctx);
        goto after_5;
    // 0x800AB000: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_5:
    // 0x800AB004: b           L_800AB030
    // 0x800AB008: nop

        goto L_800AB030;
    // 0x800AB008: nop

L_800AB00C:
    // 0x800AB00C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB010: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800AB014: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800AB018: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800AB01C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800AB020: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AB024: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800AB028: jal         0x80078F08
    // 0x800AB02C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    texrect_draw(rdram, ctx);
        goto after_6;
    // 0x800AB02C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_6:
L_800AB030:
    // 0x800AB030: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800AB034: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800AB038: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800AB03C: bne         $t7, $zero, L_800AB45C
    if (ctx->r15 != 0) {
        // 0x800AB040: nop
    
            goto L_800AB45C;
    }
    // 0x800AB040: nop

    // 0x800AB044: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AB048: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AB04C: nop

    // 0x800AB050: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800AB054: b           L_800AB45C
    // 0x800AB058: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
        goto L_800AB45C;
    // 0x800AB058: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
L_800AB05C:
    // 0x800AB05C: lb          $t9, 0x7295($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7295);
    // 0x800AB060: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800AB064: beq         $t9, $zero, L_800AB108
    if (ctx->r25 == 0) {
        // 0x800AB068: lui         $at, 0x3FF0
        ctx->r1 = S32(0X3FF0 << 16);
            goto L_800AB108;
    }
    // 0x800AB068: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800AB06C: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800AB070: nop

    // 0x800AB074: bne         $t8, $zero, L_800AB108
    if (ctx->r24 != 0) {
        // 0x800AB078: nop
    
            goto L_800AB108;
    }
    // 0x800AB078: nop

    // 0x800AB07C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800AB080: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800AB084: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x800AB088: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800AB08C: lh          $t6, 0x18($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X18);
    // 0x800AB090: lh          $t7, 0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X16);
    // 0x800AB094: sh          $zero, 0x74($sp)
    MEM_H(0X74, ctx->r29) = 0;
    // 0x800AB098: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB09C: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x800AB0A0: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x800AB0A4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AB0A8: lwc1        $f19, -0x72A0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X72A0);
    // 0x800AB0AC: lwc1        $f18, -0x729C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X729C);
    // 0x800AB0B0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AB0B4: lw          $t8, 0x2DB4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2DB4);
    // 0x800AB0B8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AB0BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB0C0: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AB0C4: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x800AB0C8: mflo        $t9
    ctx->r25 = lo;
    // 0x800AB0CC: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800AB0D0: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x800AB0D4: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AB0D8: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x800AB0DC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800AB0E0: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x800AB0E4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800AB0E8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800AB0EC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800AB0F0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800AB0F4: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x800AB0F8: jal         0x80079150
    // 0x800AB0FC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_7;
    // 0x800AB0FC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x800AB100: b           L_800AB460
    // 0x800AB104: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
        goto L_800AB460;
    // 0x800AB104: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_800AB108:
    // 0x800AB108: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AB10C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800AB110: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AB114: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x800AB118: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x800AB11C: nop

    // 0x800AB120: bc1f        L_800AB280
    if (!c1cs) {
        // 0x800AB124: nop
    
            goto L_800AB280;
    }
    // 0x800AB124: nop

    // 0x800AB128: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800AB12C: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x800AB130: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x800AB134: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x800AB138: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x800AB13C: lh          $t9, 0x16($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X16);
    // 0x800AB140: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB144: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB148: lw          $v0, 0x2DB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2DB4);
    // 0x800AB14C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800AB150: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AB154: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AB158: addiu       $a1, $a1, 0x7740
    ctx->r5 = ADD32(ctx->r5, 0X7740);
    // 0x800AB15C: addiu       $t5, $t5, 0x7340
    ctx->r13 = ADD32(ctx->r13, 0X7340);
    // 0x800AB160: mflo        $t8
    ctx->r24 = lo;
    // 0x800AB164: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x800AB168: bne         $v0, $at, L_800AB1D8
    if (ctx->r2 != ctx->r1) {
        // 0x800AB16C: nop
    
            goto L_800AB1D8;
    }
    // 0x800AB16C: nop

    // 0x800AB170: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800AB174: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AB178: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x800AB17C: addu        $v0, $t3, $t5
    ctx->r2 = ADD32(ctx->r11, ctx->r13);
    // 0x800AB180: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800AB184: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800AB188: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AB18C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AB190: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AB194: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x800AB198: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AB19C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AB1A0: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800AB1A4: nop

    // 0x800AB1A8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AB1AC: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x800AB1B0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AB1B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AB1B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AB1BC: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AB1C0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800AB1C4: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AB1C8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800AB1CC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AB1D0: b           L_800AB45C
    // 0x800AB1D4: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
        goto L_800AB45C;
    // 0x800AB1D4: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
L_800AB1D8:
    // 0x800AB1D8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AB1DC: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x800AB1E0: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800AB1E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AB1E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AB1EC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AB1F0: srl         $t7, $v0, 24
    ctx->r15 = S32(U32(ctx->r2) >> 24);
    // 0x800AB1F4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AB1F8: srl         $t8, $v0, 16
    ctx->r24 = S32(U32(ctx->r2) >> 16);
    // 0x800AB1FC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AB200: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800AB204: andi        $t3, $t8, 0xFF
    ctx->r11 = ctx->r24 & 0XFF;
    // 0x800AB208: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AB20C: sh          $t5, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r13;
    // 0x800AB210: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800AB214: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AB218: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AB21C: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AB220: srl         $t5, $v0, 8
    ctx->r13 = S32(U32(ctx->r2) >> 8);
    // 0x800AB224: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AB228: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x800AB22C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800AB230: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AB234: sh          $t6, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r14;
    // 0x800AB238: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800AB23C: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
    // 0x800AB240: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB244: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800AB248: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AB24C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800AB250: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800AB254: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800AB258: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800AB25C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800AB260: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AB264: jal         0x80078F08
    // 0x800AB268: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    texrect_draw(rdram, ctx);
        goto after_8;
    // 0x800AB268: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x800AB26C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB270: jal         0x8007B820
    // 0x800AB274: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    rendermode_reset(rdram, ctx);
        goto after_9;
    // 0x800AB274: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_9:
    // 0x800AB278: b           L_800AB460
    // 0x800AB27C: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
        goto L_800AB460;
    // 0x800AB27C: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_800AB280:
    // 0x800AB280: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800AB284: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800AB288: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800AB28C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800AB290: lh          $t3, 0x18($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X18);
    // 0x800AB294: lh          $t5, 0x16($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X16);
    // 0x800AB298: sh          $zero, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = 0;
    // 0x800AB29C: multu       $t3, $t5
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB2A0: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
    // 0x800AB2A4: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x800AB2A8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AB2AC: lw          $t6, 0x2DB4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2DB4);
    // 0x800AB2B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AB2B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB2B8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AB2BC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800AB2C0: mflo        $t4
    ctx->r12 = lo;
    // 0x800AB2C4: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x800AB2C8: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800AB2CC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AB2D0: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x800AB2D4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800AB2D8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800AB2DC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800AB2E0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800AB2E4: jal         0x80079150
    // 0x800AB2E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_10;
    // 0x800AB2E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x800AB2EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB2F0: jal         0x8007B820
    // 0x800AB2F4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    rendermode_reset(rdram, ctx);
        goto after_11;
    // 0x800AB2F4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_11:
    // 0x800AB2F8: b           L_800AB460
    // 0x800AB2FC: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
        goto L_800AB460;
    // 0x800AB2FC: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_800AB300:
    // 0x800AB300: beq         $t9, $zero, L_800AB384
    if (ctx->r25 == 0) {
        // 0x800AB304: andi        $t6, $v0, 0x4000
        ctx->r14 = ctx->r2 & 0X4000;
            goto L_800AB384;
    }
    // 0x800AB304: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x800AB308: jal         0x80069F60
    // 0x800AB30C: nop

    cam_get_active_camera(rdram, ctx);
        goto after_12;
    // 0x800AB30C: nop

    after_12:
    // 0x800AB310: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AB314: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x800AB318: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x800AB31C: addiu       $t1, $t1, 0x72B4
    ctx->r9 = ADD32(ctx->r9, 0X72B4);
    // 0x800AB320: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800AB324: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x800AB328: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x800AB32C: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x800AB330: addu        $t4, $t8, $t5
    ctx->r12 = ADD32(ctx->r24, ctx->r13);
    // 0x800AB334: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x800AB338: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x800AB33C: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x800AB340: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB344: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AB348: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AB34C: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800AB350: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AB354: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AB358: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800AB35C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800AB360: jal         0x80068E34
    // 0x800AB364: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    render_ortho_triangle_image(rdram, ctx);
        goto after_13;
    // 0x800AB364: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_13:
    // 0x800AB368: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x800AB36C: lh          $t3, 0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4);
    // 0x800AB370: lh          $t5, 0x4($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X4);
    // 0x800AB374: nop

    // 0x800AB378: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x800AB37C: b           L_800AB45C
    // 0x800AB380: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
        goto L_800AB45C;
    // 0x800AB380: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
L_800AB384:
    // 0x800AB384: beq         $t6, $zero, L_800AB404
    if (ctx->r14 == 0) {
        // 0x800AB388: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800AB404;
    }
    // 0x800AB388: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB38C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800AB390: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800AB394: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800AB398: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    // 0x800AB39C: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x800AB3A0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800AB3A4: sh          $t3, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r11;
    // 0x800AB3A8: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x800AB3AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB3B0: sh          $t5, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r13;
    // 0x800AB3B4: lh          $t4, 0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4);
    // 0x800AB3B8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AB3BC: sh          $t4, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r12;
    // 0x800AB3C0: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AB3C4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AB3C8: swc1        $f16, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f16.u32l;
    // 0x800AB3CC: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AB3D0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800AB3D4: swc1        $f10, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f10.u32l;
    // 0x800AB3D8: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800AB3DC: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AB3E0: swc1        $f4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f4.u32l;
    // 0x800AB3E4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AB3E8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AB3EC: sb          $zero, 0x3A($a3)
    MEM_B(0X3A, ctx->r7) = 0;
    // 0x800AB3F0: sb          $t6, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r14;
    // 0x800AB3F4: jal         0x80012D5C
    // 0x800AB3F8: swc1        $f6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
    render_object(rdram, ctx);
        goto after_14;
    // 0x800AB3F8: swc1        $f6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
    after_14:
    // 0x800AB3FC: b           L_800AB460
    // 0x800AB400: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
        goto L_800AB460;
    // 0x800AB400: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_800AB404:
    // 0x800AB404: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AB408: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AB40C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AB410: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800AB414: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800AB418: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800AB41C: jal         0x800696C4
    // 0x800AB420: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_15;
    // 0x800AB420: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_15:
    // 0x800AB424: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AB428: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x800AB42C: addiu       $t1, $t1, 0x72B4
    ctx->r9 = ADD32(ctx->r9, 0X72B4);
    // 0x800AB430: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800AB434: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800AB438: addu        $t3, $t7, $t8
    ctx->r11 = ADD32(ctx->r15, ctx->r24);
    // 0x800AB43C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800AB440: nop

    // 0x800AB444: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800AB448: jal         0x800AB52C
    // 0x800AB44C: nop

    hud_draw_model(rdram, ctx);
        goto after_16;
    // 0x800AB44C: nop

    after_16:
    // 0x800AB450: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AB454: jal         0x80069C80
    // 0x800AB458: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    mtx_pop(rdram, ctx);
        goto after_17;
    // 0x800AB458: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_17:
L_800AB45C:
    // 0x800AB45C: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_800AB460:
    // 0x800AB460: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x800AB464: beq         $t0, $at, L_800AB4EC
    if (ctx->r8 == ctx->r1) {
        // 0x800AB468: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800AB4EC;
    }
    // 0x800AB468: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AB46C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800AB470: beq         $t0, $at, L_800AB4C4
    if (ctx->r8 == ctx->r1) {
        // 0x800AB474: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800AB4C4;
    }
    // 0x800AB474: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AB478: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x800AB47C: beq         $t0, $at, L_800AB4C4
    if (ctx->r8 == ctx->r1) {
        // 0x800AB480: slti        $at, $t0, 0x2F
        ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
            goto L_800AB4C4;
    }
    // 0x800AB480: slti        $at, $t0, 0x2F
    ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
    // 0x800AB484: bne         $at, $zero, L_800AB490
    if (ctx->r1 != 0) {
        // 0x800AB488: slti        $at, $t0, 0x36
        ctx->r1 = SIGNED(ctx->r8) < 0X36 ? 1 : 0;
            goto L_800AB490;
    }
    // 0x800AB488: slti        $at, $t0, 0x36
    ctx->r1 = SIGNED(ctx->r8) < 0X36 ? 1 : 0;
    // 0x800AB48C: bne         $at, $zero, L_800AB4C4
    if (ctx->r1 != 0) {
        // 0x800AB490: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800AB4C4;
    }
L_800AB490:
    // 0x800AB490: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x800AB494: beq         $t0, $at, L_800AB4C4
    if (ctx->r8 == ctx->r1) {
        // 0x800AB498: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800AB4C4;
    }
    // 0x800AB498: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AB49C: lb          $t5, 0x7293($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X7293);
    // 0x800AB4A0: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x800AB4A4: andi        $t4, $t5, 0x1
    ctx->r12 = ctx->r13 & 0X1;
    // 0x800AB4A8: beq         $t4, $zero, L_800AB4C4
    if (ctx->r12 == 0) {
        // 0x800AB4AC: nop
    
            goto L_800AB4C4;
    }
    // 0x800AB4AC: nop

    // 0x800AB4B0: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800AB4B4: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AB4B8: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AB4BC: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AB4C0: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_800AB4C4:
    // 0x800AB4C4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800AB4C8: lw          $t7, 0x72E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72E8);
    // 0x800AB4CC: lw          $t9, 0x72E4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72E4);
    // 0x800AB4D0: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AB4D4: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800AB4D8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800AB4DC: nop

    // 0x800AB4E0: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AB4E4: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800AB4E8: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_800AB4EC:
    // 0x800AB4EC: lw          $t3, 0x72BC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X72BC);
    // 0x800AB4F0: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800AB4F4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AB4F8: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x800AB4FC: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x800AB500: lw          $t4, 0x72C0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72C0);
    // 0x800AB504: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AB508: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x800AB50C: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x800AB510: lw          $t9, 0x72C4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72C4);
    // 0x800AB514: nop

    // 0x800AB518: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
L_800AB51C:
    // 0x800AB51C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AB520: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800AB524: jr          $ra
    // 0x800AB528: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800AB528: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void memset_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4E6C: sltiu       $v1, $a2, 0x1
    ctx->r3 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x800B4E70: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x800B4E74: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800B4E78: beq         $v1, $zero, L_800B4E98
    if (ctx->r3 == 0) {
        // 0x800B4E7C: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800B4E98;
    }
    // 0x800B4E7C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_800B4E80:
    // 0x800B4E80: sltiu       $v1, $a2, 0x1
    ctx->r3 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x800B4E84: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x800B4E88: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800B4E8C: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x800B4E90: bne         $v1, $zero, L_800B4E80
    if (ctx->r3 != 0) {
        // 0x800B4E94: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800B4E80;
    }
    // 0x800B4E94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800B4E98:
    // 0x800B4E98: jr          $ra
    // 0x800B4E9C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800B4E9C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void obj_init_cameracontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800391A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800391A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800391A8: lb          $t6, 0x8($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X8);
    // 0x800391AC: jal         0x80011390
    // 0x800391B0: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    path_enable(rdram, ctx);
        goto after_0;
    // 0x800391B0: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    after_0:
    // 0x800391B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800391B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800391BC: jr          $ra
    // 0x800391C0: nop

    return;
    // 0x800391C0: nop

;}
RECOMP_FUNC void charselect_move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C4A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008C4A4: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8008C4A8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8008C4AC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8008C4B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008C4B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008C4B8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8008C4BC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8008C4C0: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8008C4C4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008C4C8: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8008C4CC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8008C4D0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8008C4D4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8008C4D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008C4DC: blez        $a2, L_8008C578
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008C4E0: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_8008C578;
    }
    // 0x8008C4E0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8008C4E4: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x8008C4E8: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x8008C4EC: beq         $s7, $t6, L_8008C578
    if (ctx->r23 == ctx->r14) {
        // 0x8008C4F0: lui         $s5, 0x40
        ctx->r21 = S32(0X40 << 16);
            goto L_8008C578;
    }
    // 0x8008C4F0: lui         $s5, 0x40
    ctx->r21 = S32(0X40 << 16);
    // 0x8008C4F4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008C4F8: addiu       $s2, $s2, 0x6988
    ctx->r18 = ADD32(ctx->r18, 0X6988);
L_8008C4FC:
    // 0x8008C4FC: jal         0x8009C850
    // 0x8008C500: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x8008C500: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x8008C504: and         $t7, $v0, $s5
    ctx->r15 = ctx->r2 & ctx->r21;
    // 0x8008C508: bne         $t7, $zero, L_8008C558
    if (ctx->r15 != 0) {
        // 0x8008C50C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008C558;
    }
    // 0x8008C50C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C510:
    // 0x8008C510: beq         $v0, $s4, L_8008C534
    if (ctx->r2 == ctx->r20) {
        // 0x8008C514: addu        $t8, $s2, $v0
        ctx->r24 = ADD32(ctx->r18, ctx->r2);
            goto L_8008C534;
    }
    // 0x8008C514: addu        $t8, $s2, $v0
    ctx->r24 = ADD32(ctx->r18, ctx->r2);
    // 0x8008C518: addu        $t0, $s3, $s1
    ctx->r8 = ADD32(ctx->r19, ctx->r17);
    // 0x8008C51C: lb          $t1, 0x0($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X0);
    // 0x8008C520: lb          $t9, 0x0($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X0);
    // 0x8008C524: nop

    // 0x8008C528: bne         $t9, $t1, L_8008C534
    if (ctx->r25 != ctx->r9) {
        // 0x8008C52C: nop
    
            goto L_8008C534;
    }
    // 0x8008C52C: nop

    // 0x8008C530: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8008C534:
    // 0x8008C534: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008C538: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8008C53C: beq         $at, $zero, L_8008C54C
    if (ctx->r1 == 0) {
        // 0x8008C540: nop
    
            goto L_8008C54C;
    }
    // 0x8008C540: nop

    // 0x8008C544: beq         $s0, $zero, L_8008C510
    if (ctx->r16 == 0) {
        // 0x8008C548: nop
    
            goto L_8008C510;
    }
    // 0x8008C548: nop

L_8008C54C:
    // 0x8008C54C: beq         $s0, $zero, L_8008C558
    if (ctx->r16 == 0) {
        // 0x8008C550: nop
    
            goto L_8008C558;
    }
    // 0x8008C550: nop

    // 0x8008C554: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8008C558:
    // 0x8008C558: beq         $s0, $zero, L_8008C578
    if (ctx->r16 == 0) {
        // 0x8008C55C: slt         $at, $s1, $s6
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r22) ? 1 : 0;
            goto L_8008C578;
    }
    // 0x8008C55C: slt         $at, $s1, $s6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8008C560: beq         $at, $zero, L_8008C578
    if (ctx->r1 == 0) {
        // 0x8008C564: addu        $t2, $s3, $s1
        ctx->r10 = ADD32(ctx->r19, ctx->r17);
            goto L_8008C578;
    }
    // 0x8008C564: addu        $t2, $s3, $s1
    ctx->r10 = ADD32(ctx->r19, ctx->r17);
    // 0x8008C568: lb          $t3, 0x0($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X0);
    // 0x8008C56C: nop

    // 0x8008C570: bne         $s7, $t3, L_8008C4FC
    if (ctx->r23 != ctx->r11) {
        // 0x8008C574: nop
    
            goto L_8008C4FC;
    }
    // 0x8008C574: nop

L_8008C578:
    // 0x8008C578: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008C57C: bne         $s0, $zero, L_8008C5A8
    if (ctx->r16 != 0) {
        // 0x8008C580: addiu       $s2, $s2, 0x6988
        ctx->r18 = ADD32(ctx->r18, 0X6988);
            goto L_8008C5A8;
    }
    // 0x8008C580: addiu       $s2, $s2, 0x6988
    ctx->r18 = ADD32(ctx->r18, 0X6988);
    // 0x8008C584: addu        $t4, $s3, $s1
    ctx->r12 = ADD32(ctx->r19, ctx->r17);
    // 0x8008C588: lb          $t5, 0x0($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X0);
    // 0x8008C58C: addu        $t6, $s2, $s4
    ctx->r14 = ADD32(ctx->r18, ctx->r20);
    // 0x8008C590: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x8008C594: lhu         $a0, 0x46($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X46);
    // 0x8008C598: jal         0x80001D04
    // 0x8008C59C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8008C59C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8008C5A0: b           L_8008C5B8
    // 0x8008C5A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8008C5B8;
    // 0x8008C5A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8008C5A8:
    // 0x8008C5A8: lhu         $a0, 0x4A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4A);
    // 0x8008C5AC: jal         0x80001D04
    // 0x8008C5B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008C5B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8008C5B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8008C5B8:
    // 0x8008C5B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8008C5BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8008C5C0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C5C4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8008C5C8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8008C5CC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8008C5D0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8008C5D4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8008C5D8: jr          $ra
    // 0x8008C5DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8008C5DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void alBnkfNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7C04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C7C08: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C7C0C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C7C10: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C7C14: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C7C18: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C7C1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C7C20: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800C7C24: addiu       $at, $zero, 0x4231
    ctx->r1 = ADD32(0, 0X4231);
    // 0x800C7C28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C7C2C: bne         $t6, $at, L_800C7CE8
    if (ctx->r14 != ctx->r1) {
        // 0x800C7C30: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_800C7CE8;
    }
    // 0x800C7C30: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C7C34: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x800C7C38: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800C7C3C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C7C40: blez        $t7, L_800C7CE8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C7C44: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_800C7CE8;
    }
    // 0x800C7C44: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800C7C48: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
L_800C7C4C:
    // 0x800C7C4C: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800C7C50: beq         $t9, $zero, L_800C7CD0
    if (ctx->r25 == 0) {
        // 0x800C7C54: sw          $t9, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r25;
            goto L_800C7CD0;
    }
    // 0x800C7C54: sw          $t9, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r25;
    // 0x800C7C58: lbu         $t6, 0x2($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X2);
    // 0x800C7C5C: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800C7C60: bnel        $t6, $zero, L_800C7CD4
    if (ctx->r14 != 0) {
        // 0x800C7C64: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_800C7CD4;
    }
    goto skip_0;
    // 0x800C7C64: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_0:
    // 0x800C7C68: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x800C7C6C: sb          $s4, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r20;
    // 0x800C7C70: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800C7C74: beq         $v0, $zero, L_800C7C8C
    if (ctx->r2 == 0) {
        // 0x800C7C78: addu        $a0, $v0, $s0
        ctx->r4 = ADD32(ctx->r2, ctx->r16);
            goto L_800C7C8C;
    }
    // 0x800C7C78: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x800C7C7C: sw          $a0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r4;
    // 0x800C7C80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C7C84: jal         0x800C7B10
    // 0x800C7C88: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    static_3_800C7B10(rdram, ctx);
        goto after_0;
    // 0x800C7C88: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_0:
L_800C7C8C:
    // 0x800C7C8C: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x800C7C90: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x800C7C94: blezl       $t8, L_800C7CD4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800C7C98: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_800C7CD4;
    }
    goto skip_1;
    // 0x800C7C98: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_1:
    // 0x800C7C9C: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
L_800C7CA0:
    // 0x800C7CA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C7CA4: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x800C7CA8: beq         $a0, $zero, L_800C7CB8
    if (ctx->r4 == 0) {
        // 0x800C7CAC: sw          $a0, 0xC($t3)
        MEM_W(0XC, ctx->r11) = ctx->r4;
            goto L_800C7CB8;
    }
    // 0x800C7CAC: sw          $a0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r4;
    // 0x800C7CB0: jal         0x800C7B10
    // 0x800C7CB4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    static_3_800C7B10(rdram, ctx);
        goto after_1;
    // 0x800C7CB4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
L_800C7CB8:
    // 0x800C7CB8: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x800C7CBC: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C7CC0: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800C7CC4: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C7CC8: bnel        $at, $zero, L_800C7CA0
    if (ctx->r1 != 0) {
        // 0x800C7CCC: lw          $t9, 0xC($t3)
        ctx->r25 = MEM_W(ctx->r11, 0XC);
            goto L_800C7CA0;
    }
    goto skip_2;
    // 0x800C7CCC: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
    skip_2:
L_800C7CD0:
    // 0x800C7CD0: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
L_800C7CD4:
    // 0x800C7CD4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800C7CD8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C7CDC: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C7CE0: bnel        $at, $zero, L_800C7C4C
    if (ctx->r1 != 0) {
        // 0x800C7CE4: lw          $t8, 0x4($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X4);
            goto L_800C7C4C;
    }
    goto skip_3;
    // 0x800C7CE4: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    skip_3:
L_800C7CE8:
    // 0x800C7CE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7CEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C7CF0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7CF4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C7CF8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C7CFC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C7D00: jr          $ra
    // 0x800C7D04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C7D04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void load_object_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C718: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000C71C: lw          $t6, -0x4C34($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C34);
    // 0x8000C720: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000C724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C728: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000C72C: addu        $v1, $t6, $a0
    ctx->r3 = ADD32(ctx->r14, ctx->r4);
    // 0x8000C730: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x8000C734: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8000C738: beq         $a1, $zero, L_8000C768
    if (ctx->r5 == 0) {
        // 0x8000C73C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8000C768;
    }
    // 0x8000C73C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C740: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x8000C744: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x8000C748: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000C74C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000C750: lw          $t9, -0x4C38($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4C38);
    // 0x8000C754: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8000C758: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8000C75C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8000C760: b           L_8000C838
    // 0x8000C764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000C838;
    // 0x8000C764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000C768:
    // 0x8000C768: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8000C76C: lw          $t4, -0x4D1C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4D1C);
    // 0x8000C770: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8000C774: addu        $v0, $t4, $t3
    ctx->r2 = ADD32(ctx->r12, ctx->r11);
    // 0x8000C778: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8000C77C: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8000C780: lw          $a0, -0x4C18($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C18);
    // 0x8000C784: subu        $a1, $t5, $a2
    ctx->r5 = SUB32(ctx->r13, ctx->r6);
    // 0x8000C788: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8000C78C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8000C790: jal         0x800710D0
    // 0x8000C794: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    mempool_alloc_pool(rdram, ctx);
        goto after_0;
    // 0x8000C794: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000C798: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8000C79C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8000C7A0: beq         $v0, $zero, L_8000C828
    if (ctx->r2 == 0) {
        // 0x8000C7A4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000C828;
    }
    // 0x8000C7A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000C7A8: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8000C7AC: jal         0x80077190
    // 0x8000C7B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    asset_load(rdram, ctx);
        goto after_1;
    // 0x8000C7B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8000C7B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C7B8: nop

    // 0x8000C7BC: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x8000C7C0: lw          $t8, 0x1C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1C);
    // 0x8000C7C4: lw          $t9, 0x14($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X14);
    // 0x8000C7C8: lw          $t2, 0x18($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X18);
    // 0x8000C7CC: lw          $t4, 0x10($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X10);
    // 0x8000C7D0: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8000C7D4: addu        $t0, $a1, $t8
    ctx->r8 = ADD32(ctx->r5, ctx->r24);
    // 0x8000C7D8: addu        $t1, $a1, $t9
    ctx->r9 = ADD32(ctx->r5, ctx->r25);
    // 0x8000C7DC: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8000C7E0: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x8000C7E4: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
    // 0x8000C7E8: sw          $t0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r8;
    // 0x8000C7EC: sw          $t1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r9;
    // 0x8000C7F0: sw          $t3, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r11;
    // 0x8000C7F4: sw          $t5, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r13;
    // 0x8000C7F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000C7FC: lw          $t6, -0x4C38($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C38);
    // 0x8000C800: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8000C804: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000C808: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8000C80C: sw          $a1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r5;
    // 0x8000C810: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8000C814: lw          $t9, -0x4C34($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4C34);
    // 0x8000C818: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000C81C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8000C820: b           L_8000C830
    // 0x8000C824: sb          $t0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r8;
        goto L_8000C830;
    // 0x8000C824: sb          $t0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r8;
L_8000C828:
    // 0x8000C828: b           L_8000C834
    // 0x8000C82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C834;
    // 0x8000C82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C830:
    // 0x8000C830: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8000C834:
    // 0x8000C834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000C838:
    // 0x8000C838: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000C83C: jr          $ra
    // 0x8000C840: nop

    return;
    // 0x8000C840: nop

;}
RECOMP_FUNC void update_player_racer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DE78: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8004DE7C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004DE80: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8004DE84: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8004DE88: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8004DE8C: jal         0x80066450
    // 0x8004DE90: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8004DE90: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004DE94: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8004DE98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004DE9C: sw          $t6, -0x2EF8($at)
    MEM_W(-0X2EF8, ctx->r1) = ctx->r14;
    // 0x8004DEA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DEA4: jal         0x8001139C
    // 0x8004DEA8: sb          $zero, -0x24FF($at)
    MEM_B(-0X24FF, ctx->r1) = 0;
    get_race_countdown(rdram, ctx);
        goto after_1;
    // 0x8004DEA8: sb          $zero, -0x24FF($at)
    MEM_B(-0X24FF, ctx->r1) = 0;
    after_1:
    // 0x8004DEAC: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8004DEB0: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8004DEB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DEB8: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x8004DEBC: sw          $v0, -0x2540($at)
    MEM_W(-0X2540, ctx->r1) = ctx->r2;
    // 0x8004DEC0: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004DEC4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004DEC8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8004DECC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004DED0: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004DED4: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x8004DED8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004DEDC: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x8004DEE0: mov.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = ctx->f16.fl;
    // 0x8004DEE4: bc1f        L_8004DEF8
    if (!c1cs) {
        // 0x8004DEE8: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_8004DEF8;
    }
    // 0x8004DEE8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8004DEEC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004DEF0: nop

    // 0x8004DEF4: swc1        $f14, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f14.u32l;
L_8004DEF8:
    // 0x8004DEF8: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004DEFC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8004DF00: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004DF04: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x8004DF08: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004DF0C: bc1f        L_8004DF18
    if (!c1cs) {
        // 0x8004DF10: lui         $at, 0xC049
        ctx->r1 = S32(0XC049 << 16);
            goto L_8004DF18;
    }
    // 0x8004DF10: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x8004DF14: swc1        $f14, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f14.u32l;
L_8004DF18:
    // 0x8004DF18: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004DF1C: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8004DF20: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004DF24: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x8004DF28: nop

    // 0x8004DF2C: bc1f        L_8004DF38
    if (!c1cs) {
        // 0x8004DF30: nop
    
            goto L_8004DF38;
    }
    // 0x8004DF30: nop

    // 0x8004DF34: swc1        $f14, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f14.u32l;
L_8004DF38:
    // 0x8004DF38: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004DF3C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8004DF40: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004DF44: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x8004DF48: nop

    // 0x8004DF4C: bc1f        L_8004DF60
    if (!c1cs) {
        // 0x8004DF50: lui         $at, 0xC248
        ctx->r1 = S32(0XC248 << 16);
            goto L_8004DF60;
    }
    // 0x8004DF50: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8004DF54: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8004DF58: nop

    // 0x8004DF5C: swc1        $f12, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f12.u32l;
L_8004DF60:
    // 0x8004DF60: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004DF64: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8004DF68: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004DF6C: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8004DF70: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8004DF74: bc1f        L_8004DF80
    if (!c1cs) {
        // 0x8004DF78: lui         $at, 0xBFF0
        ctx->r1 = S32(0XBFF0 << 16);
            goto L_8004DF80;
    }
    // 0x8004DF78: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8004DF7C: swc1        $f12, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f12.u32l;
L_8004DF80:
    // 0x8004DF80: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004DF84: nop

    // 0x8004DF88: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004DF8C: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x8004DF90: nop

    // 0x8004DF94: bc1f        L_8004DFA0
    if (!c1cs) {
        // 0x8004DF98: nop
    
            goto L_8004DFA0;
    }
    // 0x8004DF98: nop

    // 0x8004DF9C: swc1        $f12, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f12.u32l;
L_8004DFA0:
    // 0x8004DFA0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004DFA4: nop

    // 0x8004DFA8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004DFAC: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x8004DFB0: nop

    // 0x8004DFB4: bc1f        L_8004DFC0
    if (!c1cs) {
        // 0x8004DFB8: nop
    
            goto L_8004DFC0;
    }
    // 0x8004DFB8: nop

    // 0x8004DFBC: swc1        $f14, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f14.u32l;
L_8004DFC0:
    // 0x8004DFC0: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8004DFC4: nop

    // 0x8004DFC8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004DFCC: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x8004DFD0: nop

    // 0x8004DFD4: bc1f        L_8004DFE0
    if (!c1cs) {
        // 0x8004DFD8: nop
    
            goto L_8004DFE0;
    }
    // 0x8004DFD8: nop

    // 0x8004DFDC: swc1        $f14, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f14.u32l;
L_8004DFE0:
    // 0x8004DFE0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004DFE4: nop

    // 0x8004DFE8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004DFEC: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8004DFF0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004DFF4: bc1f        L_8004E000
    if (!c1cs) {
        // 0x8004DFF8: nop
    
            goto L_8004E000;
    }
    // 0x8004DFF8: nop

    // 0x8004DFFC: swc1        $f12, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f12.u32l;
L_8004E000:
    // 0x8004E000: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8004E004: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8004E008: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004E00C: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x8004E010: nop

    // 0x8004E014: bc1f        L_8004E020
    if (!c1cs) {
        // 0x8004E018: nop
    
            goto L_8004E020;
    }
    // 0x8004E018: nop

    // 0x8004E01C: swc1        $f12, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f12.u32l;
L_8004E020:
    // 0x8004E020: lwc1        $f6, 0xA8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004E024: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004E028: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8004E02C: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8004E030: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004E034: bc1f        L_8004E054
    if (!c1cs) {
        // 0x8004E038: nop
    
            goto L_8004E054;
    }
    // 0x8004E038: nop

    // 0x8004E03C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004E040: nop

    // 0x8004E044: swc1        $f10, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f10.u32l;
    // 0x8004E048: lwc1        $f4, 0xA8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004E04C: nop

    // 0x8004E050: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
L_8004E054:
    // 0x8004E054: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004E058: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004E05C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004E060: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x8004E064: nop

    // 0x8004E068: bc1f        L_8004E07C
    if (!c1cs) {
        // 0x8004E06C: nop
    
            goto L_8004E07C;
    }
    // 0x8004E06C: nop

    // 0x8004E070: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004E074: nop

    // 0x8004E078: swc1        $f8, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f8.u32l;
L_8004E07C:
    // 0x8004E07C: lbu         $t7, 0x1FE($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004E080: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004E084: bne         $t7, $at, L_8004E090
    if (ctx->r15 != ctx->r1) {
        // 0x8004E088: nop
    
            goto L_8004E090;
    }
    // 0x8004E088: nop

    // 0x8004E08C: sb          $zero, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = 0;
L_8004E090:
    // 0x8004E090: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x8004E094: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004E098: bne         $t8, $zero, L_8004E0B4
    if (ctx->r24 != 0) {
        // 0x8004E09C: nop
    
            goto L_8004E0B4;
    }
    // 0x8004E09C: nop

    // 0x8004E0A0: lwc1        $f5, 0x6B20($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6B20);
    // 0x8004E0A4: lwc1        $f4, 0x6B24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6B24);
    // 0x8004E0A8: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8004E0AC: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8004E0B0: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
L_8004E0B4:
    // 0x8004E0B4: lb          $t9, 0x1F6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1F6);
    // 0x8004E0B8: nop

    // 0x8004E0BC: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x8004E0C0: sb          $t0, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = ctx->r8;
    // 0x8004E0C4: lb          $t1, 0x1F6($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1F6);
    // 0x8004E0C8: nop

    // 0x8004E0CC: bgez        $t1, L_8004E0D8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8004E0D0: nop
    
            goto L_8004E0D8;
    }
    // 0x8004E0D0: nop

    // 0x8004E0D4: sb          $zero, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = 0;
L_8004E0D8:
    // 0x8004E0D8: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8004E0DC: lb          $v0, 0x201($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X201);
    // 0x8004E0E0: nop

    // 0x8004E0E4: blez        $v0, L_8004E0F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004E0E8: subu        $t2, $v0, $v1
        ctx->r10 = SUB32(ctx->r2, ctx->r3);
            goto L_8004E0F4;
    }
    // 0x8004E0E8: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x8004E0EC: b           L_8004E0F8
    // 0x8004E0F0: sb          $t2, 0x201($s0)
    MEM_B(0X201, ctx->r16) = ctx->r10;
        goto L_8004E0F8;
    // 0x8004E0F0: sb          $t2, 0x201($s0)
    MEM_B(0X201, ctx->r16) = ctx->r10;
L_8004E0F4:
    // 0x8004E0F4: sb          $zero, 0x201($s0)
    MEM_B(0X201, ctx->r16) = 0;
L_8004E0F8:
    // 0x8004E0F8: jal         0x8006BFF0
    // 0x8004E0FC: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    level_header(rdram, ctx);
        goto after_2;
    // 0x8004E0FC: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8004E100: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x8004E104: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004E108: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E10C: swc1        $f8, -0x2590($at)
    MEM_W(-0X2590, ctx->r1) = ctx->f8.u32l;
    // 0x8004E110: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x8004E114: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004E118: bne         $v1, $at, L_8004E13C
    if (ctx->r3 != ctx->r1) {
        // 0x8004E11C: sb          $zero, 0x20C($s0)
        MEM_B(0X20C, ctx->r16) = 0;
            goto L_8004E13C;
    }
    // 0x8004E11C: sb          $zero, 0x20C($s0)
    MEM_B(0X20C, ctx->r16) = 0;
    // 0x8004E120: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E124: lw          $a3, 0x9C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X9C);
    // 0x8004E128: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E12C: jal         0x8005A75C
    // 0x8004E130: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    update_AI_racer(rdram, ctx);
        goto after_3;
    // 0x8004E130: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8004E134: b           L_8004F7AC
    // 0x8004E138: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8004F7AC;
    // 0x8004E138: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8004E13C:
    // 0x8004E13C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004E140: lw          $t3, -0x2540($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2540);
    // 0x8004E144: nop

    // 0x8004E148: bne         $t3, $zero, L_8004E1A8
    if (ctx->r11 != 0) {
        // 0x8004E14C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8004E1A8;
    }
    // 0x8004E14C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004E150: bne         $v1, $zero, L_8004E1A8
    if (ctx->r3 != 0) {
        // 0x8004E154: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8004E1A8;
    }
    // 0x8004E154: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004E158: jal         0x8009C850
    // 0x8004E15C: nop

    get_filtered_cheats(rdram, ctx);
        goto after_4;
    // 0x8004E15C: nop

    after_4:
    // 0x8004E160: andi        $t4, $v0, 0x200
    ctx->r12 = ctx->r2 & 0X200;
    // 0x8004E164: beq         $t4, $zero, L_8004E1A4
    if (ctx->r12 == 0) {
        // 0x8004E168: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8004E1A4;
    }
    // 0x8004E168: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8004E16C: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004E170: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004E174: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004E178: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004E17C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8004E180: swc1        $f9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x8004E184: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004E188: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8004E18C: mfc1        $a2, $f5
    ctx->r6 = (int32_t)ctx->f_odd[(5 - 1) * 2];
    // 0x8004E190: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004E194: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8004E198: swc1        $f5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
    // 0x8004E19C: jal         0x800B643C
    // 0x8004E1A0: addiu       $a0, $a0, 0x6810
    ctx->r4 = ADD32(ctx->r4, 0X6810);
    render_printf(rdram, ctx);
        goto after_5;
    // 0x8004E1A0: addiu       $a0, $a0, 0x6810
    ctx->r4 = ADD32(ctx->r4, 0X6810);
    after_5:
L_8004E1A4:
    // 0x8004E1A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8004E1A8:
    // 0x8004E1A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004E1AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004E1B0: jal         0x800B6814
    // 0x8004E1B4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_render_printf_background_colour(rdram, ctx);
        goto after_6;
    // 0x8004E1B4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_6:
    // 0x8004E1B8: jal         0x80023450
    // 0x8004E1BC: nop

    is_taj_challenge(rdram, ctx);
        goto after_7;
    // 0x8004E1BC: nop

    after_7:
    // 0x8004E1C0: beq         $v0, $zero, L_8004E1CC
    if (ctx->r2 == 0) {
        // 0x8004E1C4: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8004E1CC;
    }
    // 0x8004E1C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E1C8: sh          $zero, -0x24FA($at)
    MEM_H(-0X24FA, ctx->r1) = 0;
L_8004E1CC:
    // 0x8004E1CC: jal         0x8006DC4C
    // 0x8004E1D0: nop

    get_game_mode(rdram, ctx);
        goto after_8;
    // 0x8004E1D0: nop

    after_8:
    // 0x8004E1D4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004E1D8: lw          $t5, -0x2540($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2540);
    // 0x8004E1DC: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x8004E1E0: bne         $t5, $zero, L_8004E224
    if (ctx->r13 != 0) {
        // 0x8004E1E4: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8004E224;
    }
    // 0x8004E1E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004E1E8: addiu       $v0, $v0, -0x253C
    ctx->r2 = ADD32(ctx->r2, -0X253C);
    // 0x8004E1EC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004E1F0: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8004E1F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004E1F8: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8004E1FC: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8004E200: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8004E204: bc1f        L_8004E218
    if (!c1cs) {
        // 0x8004E208: nop
    
            goto L_8004E218;
    }
    // 0x8004E208: nop

    // 0x8004E20C: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8004E210: b           L_8004E238
    // 0x8004E214: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
        goto L_8004E238;
    // 0x8004E214: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_8004E218:
    // 0x8004E218: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004E21C: b           L_8004E238
    // 0x8004E220: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_8004E238;
    // 0x8004E220: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_8004E224:
    // 0x8004E224: addiu       $a0, $zero, -0x3C
    ctx->r4 = ADD32(0, -0X3C);
    // 0x8004E228: jal         0x8006FB8C
    // 0x8004E22C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    rand_range(rdram, ctx);
        goto after_9;
    // 0x8004E22C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_9:
    // 0x8004E230: addiu       $t6, $v0, 0x78
    ctx->r14 = ADD32(ctx->r2, 0X78);
    // 0x8004E234: sh          $t6, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r14;
L_8004E238:
    // 0x8004E238: lh          $v0, 0x18C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18C);
    // 0x8004E23C: nop

    // 0x8004E240: blez        $v0, L_8004E25C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004E244: nop
    
            goto L_8004E25C;
    }
    // 0x8004E244: nop

    // 0x8004E248: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E24C: nop

    // 0x8004E250: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x8004E254: b           L_8004E260
    // 0x8004E258: sh          $t8, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = ctx->r24;
        goto L_8004E260;
    // 0x8004E258: sh          $t8, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = ctx->r24;
L_8004E25C:
    // 0x8004E25C: sh          $zero, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = 0;
L_8004E260:
    // 0x8004E260: jal         0x8001E2D0
    // 0x8004E264: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    get_misc_asset(rdram, ctx);
        goto after_10;
    // 0x8004E264: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_10:
    // 0x8004E268: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004E26C: addiu       $a1, $a1, -0x251C
    ctx->r5 = ADD32(ctx->r5, -0X251C);
    // 0x8004E270: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8004E274: lb          $t0, 0x3($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X3);
    // 0x8004E278: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004E27C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8004E280: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8004E284: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8004E288: lwc1        $f5, 0x6B28($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6B28);
    // 0x8004E28C: lwc1        $f4, 0x6B2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6B2C);
    // 0x8004E290: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8004E294: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8004E298: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004E29C: addiu       $v1, $v1, -0x2514
    ctx->r3 = ADD32(ctx->r3, -0X2514);
    // 0x8004E2A0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8004E2A4: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8004E2A8: lh          $t3, 0x204($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X204);
    // 0x8004E2AC: nop

    // 0x8004E2B0: blez        $t3, L_8004E2C4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8004E2B4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004E2C4;
    }
    // 0x8004E2B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004E2B8: lwc1        $f10, 0x6B30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6B30);
    // 0x8004E2BC: nop

    // 0x8004E2C0: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
L_8004E2C4:
    // 0x8004E2C4: jal         0x8001E2D0
    // 0x8004E2C8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    get_misc_asset(rdram, ctx);
        goto after_11;
    // 0x8004E2C8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_11:
    // 0x8004E2CC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004E2D0: addiu       $a1, $a1, -0x251C
    ctx->r5 = ADD32(ctx->r5, -0X251C);
    // 0x8004E2D4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8004E2D8: lb          $t5, 0x3($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X3);
    // 0x8004E2DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E2E0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8004E2E4: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8004E2E8: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8004E2EC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8004E2F0: jal         0x8001E2D0
    // 0x8004E2F4: swc1        $f4, -0x2510($at)
    MEM_W(-0X2510, ctx->r1) = ctx->f4.u32l;
    get_misc_asset(rdram, ctx);
        goto after_12;
    // 0x8004E2F4: swc1        $f4, -0x2510($at)
    MEM_W(-0X2510, ctx->r1) = ctx->f4.u32l;
    after_12:
    // 0x8004E2F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E2FC: sw          $v0, -0x251C($at)
    MEM_W(-0X251C, ctx->r1) = ctx->r2;
    // 0x8004E300: lb          $t0, 0x3($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X3);
    // 0x8004E304: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004E308: lw          $t8, -0x251C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X251C);
    // 0x8004E30C: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8004E310: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8004E314: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8004E318: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E31C: swc1        $f6, -0x250C($at)
    MEM_W(-0X250C, ctx->r1) = ctx->f6.u32l;
    // 0x8004E320: lbu         $a0, 0x1FE($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004E324: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004E328: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004E32C: bne         $a0, $at, L_8004E374
    if (ctx->r4 != ctx->r1) {
        // 0x8004E330: addiu       $v1, $v1, -0x2514
        ctx->r3 = ADD32(ctx->r3, -0X2514);
            goto L_8004E374;
    }
    // 0x8004E330: addiu       $v1, $v1, -0x2514
    ctx->r3 = ADD32(ctx->r3, -0X2514);
    // 0x8004E334: lbu         $t2, 0x1FF($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8004E338: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8004E33C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8004E340: bgez        $t2, L_8004E354
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8004E344: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8004E354;
    }
    // 0x8004E344: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004E348: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004E34C: nop

    // 0x8004E350: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_8004E354:
    // 0x8004E354: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8004E358: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004E35C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004E360: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8004E364: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8004E368: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x8004E36C: lbu         $a0, 0x1FE($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004E370: nop

L_8004E374:
    // 0x8004E374: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004E378: bne         $a0, $at, L_8004E3E0
    if (ctx->r4 != ctx->r1) {
        // 0x8004E37C: nop
    
            goto L_8004E3E0;
    }
    // 0x8004E37C: nop

    // 0x8004E380: lbu         $t3, 0x1FF($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8004E384: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004E388: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8004E38C: bgez        $t3, L_8004E3A4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8004E390: cvt.s.w     $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8004E3A4;
    }
    // 0x8004E390: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004E394: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8004E398: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004E39C: nop

    // 0x8004E3A0: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8004E3A4:
    // 0x8004E3A4: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004E3A8: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8004E3AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004E3B0: nop

    // 0x8004E3B4: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8004E3B8: sub.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8004E3BC: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8004E3C0: lh          $t5, 0x204($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X204);
    // 0x8004E3C4: nop

    // 0x8004E3C8: blez        $t5, L_8004E3E0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8004E3CC: nop
    
            goto L_8004E3E0;
    }
    // 0x8004E3CC: nop

    // 0x8004E3D0: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004E3D4: nop

    // 0x8004E3D8: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x8004E3DC: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
L_8004E3E0:
    // 0x8004E3E0: lbu         $t4, 0x1FE($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004E3E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004E3E8: bne         $t4, $at, L_8004E4A8
    if (ctx->r12 != ctx->r1) {
        // 0x8004E3EC: nop
    
            goto L_8004E4A8;
    }
    // 0x8004E3EC: nop

    // 0x8004E3F0: lbu         $t6, 0x1FF($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8004E3F4: nop

    // 0x8004E3F8: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8004E3FC: jal         0x80070A04
    // 0x8004E400: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    sins_f(rdram, ctx);
        goto after_13;
    // 0x8004E400: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_13:
    // 0x8004E404: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x8004E408: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8004E40C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004E410: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004E414: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8004E418: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8004E41C: lwc1        $f2, 0x84($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8004E420: cvt.d.s     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f14.d = CVT_D_S(ctx->f8.fl);
    // 0x8004E424: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8004E428: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8004E42C: lbu         $t8, 0x1FF($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8004E430: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8004E434: mul.d       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x8004E438: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8004E43C: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x8004E440: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004E444: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x8004E448: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x8004E44C: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x8004E450: swc1        $f6, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f6.u32l;
    // 0x8004E454: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    // 0x8004E458: jal         0x80070A38
    // 0x8004E45C: swc1        $f15, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(15 - 1) * 2];
    coss_f(rdram, ctx);
        goto after_14;
    // 0x8004E45C: swc1        $f15, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(15 - 1) * 2];
    after_14:
    // 0x8004E460: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x8004E464: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8004E468: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004E46C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004E470: lwc1        $f2, 0x88($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8004E474: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004E478: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8004E47C: lwc1        $f9, 0x50($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x8004E480: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8004E484: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004E488: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8004E48C: mul.d       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x8004E490: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8004E494: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8004E498: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x8004E49C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8004E4A0: b           L_8004E504
    // 0x8004E4A4: swc1        $f8, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f8.u32l;
        goto L_8004E504;
    // 0x8004E4A4: swc1        $f8, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f8.u32l;
L_8004E4A8:
    // 0x8004E4A8: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8004E4AC: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x8004E4B0: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8004E4B4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8004E4B8: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8004E4BC: mul.d       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f12.d);
    // 0x8004E4C0: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8004E4C4: nop

    // 0x8004E4C8: cvt.d.s     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f14.d = CVT_D_S(ctx->f10.fl);
    // 0x8004E4CC: mul.d       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x8004E4D0: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8004E4D4: nop

    // 0x8004E4D8: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x8004E4DC: sub.d       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f0.d - ctx->f8.d;
    // 0x8004E4E0: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x8004E4E4: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8004E4E8: swc1        $f10, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f10.u32l;
    // 0x8004E4EC: mul.d       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x8004E4F0: sub.d       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f2.d - ctx->f6.d;
    // 0x8004E4F4: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8004E4F8: swc1        $f4, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f4.u32l;
    // 0x8004E4FC: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    // 0x8004E500: swc1        $f15, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(15 - 1) * 2];
L_8004E504:
    // 0x8004E504: lw          $t2, 0x40($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X40);
    // 0x8004E508: nop

    // 0x8004E50C: lbu         $a0, 0x5C($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X5C);
    // 0x8004E510: jal         0x8001E2D0
    // 0x8004E514: nop

    get_misc_asset(rdram, ctx);
        goto after_15;
    // 0x8004E514: nop

    after_15:
    // 0x8004E518: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E51C: sw          $v0, -0x251C($at)
    MEM_W(-0X251C, ctx->r1) = ctx->r2;
    // 0x8004E520: lw          $t3, 0x40($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X40);
    // 0x8004E524: nop

    // 0x8004E528: lbu         $a0, 0x5D($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X5D);
    // 0x8004E52C: jal         0x8001E2D0
    // 0x8004E530: nop

    get_misc_asset(rdram, ctx);
        goto after_16;
    // 0x8004E530: nop

    after_16:
    // 0x8004E534: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E538: sw          $v0, -0x2518($at)
    MEM_W(-0X2518, ctx->r1) = ctx->r2;
    // 0x8004E53C: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004E540: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8004E544: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004E548: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004E54C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8004E550: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8004E554: nop

    // 0x8004E558: bc1f        L_8004E598
    if (!c1cs) {
        // 0x8004E55C: nop
    
            goto L_8004E598;
    }
    // 0x8004E55C: nop

    // 0x8004E560: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004E564: nop

    // 0x8004E568: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x8004E56C: beq         $at, $zero, L_8004E594
    if (ctx->r1 == 0) {
        // 0x8004E570: nop
    
            goto L_8004E594;
    }
    // 0x8004E570: nop

    // 0x8004E574: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004E578: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8004E57C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004E580: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8004E584: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x8004E588: nop

    // 0x8004E58C: bc1t        L_8004E598
    if (c1cs) {
        // 0x8004E590: nop
    
            goto L_8004E598;
    }
    // 0x8004E590: nop

L_8004E594:
    // 0x8004E594: sb          $zero, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = 0;
L_8004E598:
    // 0x8004E598: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004E59C: nop

    // 0x8004E5A0: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    // 0x8004E5A4: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004E5A8: nop

    // 0x8004E5AC: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x8004E5B0: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004E5B4: nop

    // 0x8004E5B8: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x8004E5BC: lh          $v0, 0x1B2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1B2);
    // 0x8004E5C0: nop

    // 0x8004E5C4: blez        $v0, L_8004E5F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004E5C8: nop
    
            goto L_8004E5F0;
    }
    // 0x8004E5C8: nop

    // 0x8004E5CC: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E5D0: nop

    // 0x8004E5D4: subu        $t6, $v0, $t4
    ctx->r14 = SUB32(ctx->r2, ctx->r12);
    // 0x8004E5D8: sh          $t6, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = ctx->r14;
    // 0x8004E5DC: lh          $t7, 0x1B2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1B2);
    // 0x8004E5E0: nop

    // 0x8004E5E4: bgez        $t7, L_8004E5F0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8004E5E8: nop
    
            goto L_8004E5F0;
    }
    // 0x8004E5E8: nop

    // 0x8004E5EC: sh          $zero, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = 0;
L_8004E5F0:
    // 0x8004E5F0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8004E5F4: jal         0x80066828
    // 0x8004E5F8: nop

    set_active_camera(rdram, ctx);
        goto after_17;
    // 0x8004E5F8: nop

    after_17:
    // 0x8004E5FC: jal         0x80069F3C
    // 0x8004E600: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_18;
    // 0x8004E600: nop

    after_18:
    // 0x8004E604: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E608: sw          $v0, -0x2578($at)
    MEM_W(-0X2578, ctx->r1) = ctx->r2;
    // 0x8004E60C: lb          $t0, 0x1E7($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1E7);
    // 0x8004E610: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x8004E614: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x8004E618: sb          $t8, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r24;
    // 0x8004E61C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E620: sw          $t9, -0x2524($at)
    MEM_W(-0X2524, ctx->r1) = ctx->r25;
    // 0x8004E624: lb          $t1, 0x1D8($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1D8);
    // 0x8004E628: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8004E62C: beq         $a3, $t1, L_8004E644
    if (ctx->r7 == ctx->r9) {
        // 0x8004E630: nop
    
            goto L_8004E644;
    }
    // 0x8004E630: nop

    // 0x8004E634: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x8004E638: nop

    // 0x8004E63C: bne         $t2, $a3, L_8004E668
    if (ctx->r10 != ctx->r7) {
        // 0x8004E640: nop
    
            goto L_8004E668;
    }
    // 0x8004E640: nop

L_8004E644:
    // 0x8004E644: lh          $t5, 0x18E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X18E);
    // 0x8004E648: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8004E64C: slti        $at, $t5, 0x6
    ctx->r1 = SIGNED(ctx->r13) < 0X6 ? 1 : 0;
    // 0x8004E650: sb          $a3, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r7;
    // 0x8004E654: sh          $t3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r11;
    // 0x8004E658: bne         $at, $zero, L_8004E668
    if (ctx->r1 != 0) {
        // 0x8004E65C: sb          $zero, 0x1C9($s0)
        MEM_B(0X1C9, ctx->r16) = 0;
            goto L_8004E668;
    }
    // 0x8004E65C: sb          $zero, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = 0;
    // 0x8004E660: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8004E664: sh          $t4, 0x18E($s0)
    MEM_H(0X18E, ctx->r16) = ctx->r12;
L_8004E668:
    // 0x8004E668: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x8004E66C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004E670: beq         $v1, $at, L_8004E734
    if (ctx->r3 == ctx->r1) {
        // 0x8004E674: lw          $a2, 0xB4($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB4);
            goto L_8004E734;
    }
    // 0x8004E674: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E678: lw          $t6, 0x108($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X108);
    // 0x8004E67C: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E680: bne         $t6, $zero, L_8004E720
    if (ctx->r14 != 0) {
        // 0x8004E684: nop
    
            goto L_8004E720;
    }
    // 0x8004E684: nop

    // 0x8004E688: jal         0x8000E158
    // 0x8004E68C: sw          $v1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r3;
    is_race_started_by_player_two(rdram, ctx);
        goto after_19;
    // 0x8004E68C: sw          $v1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r3;
    after_19:
    // 0x8004E690: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x8004E694: beq         $v0, $zero, L_8004E6A0
    if (ctx->r2 == 0) {
        // 0x8004E698: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8004E6A0;
    }
    // 0x8004E698: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004E69C: subu        $a2, $t7, $a2
    ctx->r6 = SUB32(ctx->r15, ctx->r6);
L_8004E6A0:
    // 0x8004E6A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004E6A4: jal         0x8006A7DC
    // 0x8004E6A8: sw          $a2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r6;
    input_clamp_stick_x(rdram, ctx);
        goto after_20;
    // 0x8004E6A8: sw          $a2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r6;
    after_20:
    // 0x8004E6AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E6B0: jal         0x8009C850
    // 0x8004E6B4: sw          $v0, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = ctx->r2;
    get_filtered_cheats(rdram, ctx);
        goto after_21;
    // 0x8004E6B4: sw          $v0, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = ctx->r2;
    after_21:
    // 0x8004E6B8: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x8004E6BC: andi        $t0, $v0, 0x4
    ctx->r8 = ctx->r2 & 0X4;
    // 0x8004E6C0: beq         $t0, $zero, L_8004E6DC
    if (ctx->r8 == 0) {
        // 0x8004E6C4: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8004E6DC;
    }
    // 0x8004E6C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004E6C8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004E6CC: lw          $t8, -0x254C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X254C);
    // 0x8004E6D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E6D4: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8004E6D8: sw          $t9, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = ctx->r25;
L_8004E6DC:
    // 0x8004E6DC: jal         0x8006A820
    // 0x8004E6E0: sw          $a2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r6;
    input_clamp_stick_y(rdram, ctx);
        goto after_22;
    // 0x8004E6E0: sw          $a2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r6;
    after_22:
    // 0x8004E6E4: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x8004E6E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E6EC: jal         0x8006A768
    // 0x8004E6F0: sw          $v0, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = ctx->r2;
    input_held(rdram, ctx);
        goto after_23;
    // 0x8004E6F0: sw          $v0, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = ctx->r2;
    after_23:
    // 0x8004E6F4: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x8004E6F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E6FC: jal         0x8006A794
    // 0x8004E700: sw          $v0, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r2;
    input_pressed(rdram, ctx);
        goto after_24;
    // 0x8004E700: sw          $v0, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r2;
    after_24:
    // 0x8004E704: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x8004E708: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E70C: jal         0x8006A7B8
    // 0x8004E710: sw          $v0, -0x2554($at)
    MEM_W(-0X2554, ctx->r1) = ctx->r2;
    input_released(rdram, ctx);
        goto after_25;
    // 0x8004E710: sw          $v0, -0x2554($at)
    MEM_W(-0X2554, ctx->r1) = ctx->r2;
    after_25:
    // 0x8004E714: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E718: b           L_8004E740
    // 0x8004E71C: sw          $v0, -0x2550($at)
    MEM_W(-0X2550, ctx->r1) = ctx->r2;
        goto L_8004E740;
    // 0x8004E71C: sw          $v0, -0x2550($at)
    MEM_W(-0X2550, ctx->r1) = ctx->r2;
L_8004E720:
    // 0x8004E720: jal         0x8005A490
    // 0x8004E724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    racer_enter_door(rdram, ctx);
        goto after_26;
    // 0x8004E724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x8004E728: b           L_8004E740
    // 0x8004E72C: nop

        goto L_8004E740;
    // 0x8004E72C: nop

    // 0x8004E730: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
L_8004E734:
    // 0x8004E734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E738: jal         0x800441B0
    // 0x8004E73C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_AI_pathing_inputs(rdram, ctx);
        goto after_27;
    // 0x8004E73C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_27:
L_8004E740:
    // 0x8004E740: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004E744: lw          $t1, -0x2558($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2558);
    // 0x8004E748: nop

    // 0x8004E74C: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x8004E750: bne         $t2, $zero, L_8004E75C
    if (ctx->r10 != 0) {
        // 0x8004E754: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8004E75C;
    }
    // 0x8004E754: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004E758: sb          $t3, 0x20C($s0)
    MEM_B(0X20C, ctx->r16) = ctx->r11;
L_8004E75C:
    // 0x8004E75C: jal         0x80066750
    // 0x8004E760: nop

    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_28;
    // 0x8004E760: nop

    after_28:
    // 0x8004E764: bne         $v0, $zero, L_8004E7B8
    if (ctx->r2 != 0) {
        // 0x8004E768: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8004E7B8;
    }
    // 0x8004E768: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004E76C: lw          $t5, -0x2540($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2540);
    // 0x8004E770: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8004E774: beq         $t5, $at, L_8004E7B8
    if (ctx->r13 == ctx->r1) {
        // 0x8004E778: nop
    
            goto L_8004E7B8;
    }
    // 0x8004E778: nop

    // 0x8004E77C: lbu         $t4, 0x1F1($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1F1);
    // 0x8004E780: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004E784: bne         $t4, $zero, L_8004E7B8
    if (ctx->r12 != 0) {
        // 0x8004E788: nop
    
            goto L_8004E7B8;
    }
    // 0x8004E788: nop

    // 0x8004E78C: lb          $t6, -0x24FC($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X24FC);
    // 0x8004E790: nop

    // 0x8004E794: bne         $t6, $zero, L_8004E7B8
    if (ctx->r14 != 0) {
        // 0x8004E798: nop
    
            goto L_8004E7B8;
    }
    // 0x8004E798: nop

    // 0x8004E79C: lw          $t7, 0x148($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X148);
    // 0x8004E7A0: nop

    // 0x8004E7A4: bne         $t7, $zero, L_8004E7B8
    if (ctx->r15 != 0) {
        // 0x8004E7A8: nop
    
            goto L_8004E7B8;
    }
    // 0x8004E7A8: nop

    // 0x8004E7AC: lh          $v0, 0x204($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X204);
    // 0x8004E7B0: nop

    // 0x8004E7B4: blez        $v0, L_8004E7E8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004E7B8: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8004E7E8;
    }
L_8004E7B8:
    // 0x8004E7B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E7BC: sw          $zero, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = 0;
    // 0x8004E7C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E7C4: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
    // 0x8004E7C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E7CC: sw          $zero, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = 0;
    // 0x8004E7D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E7D4: sw          $zero, -0x2554($at)
    MEM_W(-0X2554, ctx->r1) = 0;
    // 0x8004E7D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E7DC: sw          $zero, -0x2550($at)
    MEM_W(-0X2550, ctx->r1) = 0;
    // 0x8004E7E0: lh          $v0, 0x204($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X204);
    // 0x8004E7E4: sb          $zero, 0x1E1($s0)
    MEM_B(0X1E1, ctx->r16) = 0;
L_8004E7E8:
    // 0x8004E7E8: blez        $v0, L_8004E850
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004E7EC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004E850;
    }
    // 0x8004E7EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004E7F0: lwc1        $f0, 0x6B34($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B34);
    // 0x8004E7F4: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E7F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004E7FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004E800: subu        $t8, $v0, $t0
    ctx->r24 = SUB32(ctx->r2, ctx->r8);
    // 0x8004E804: sh          $t8, 0x204($s0)
    MEM_H(0X204, ctx->r16) = ctx->r24;
    // 0x8004E808: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004E80C: lwc1        $f10, 0x6B38($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6B38);
    // 0x8004E810: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004E814: nop

    // 0x8004E818: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8004E81C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x8004E820: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004E824: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004E828: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004E82C: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8004E830: nop

    // 0x8004E834: bc1f        L_8004E840
    if (!c1cs) {
        // 0x8004E838: swc1        $f6, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
            goto L_8004E840;
    }
    // 0x8004E838: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x8004E83C: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_8004E840:
    // 0x8004E840: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004E844: nop

    // 0x8004E848: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8004E84C: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
L_8004E850:
    // 0x8004E850: lh          $v0, 0x206($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X206);
    // 0x8004E854: nop

    // 0x8004E858: blez        $v0, L_8004E874
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004E85C: nop
    
            goto L_8004E874;
    }
    // 0x8004E85C: nop

    // 0x8004E860: sh          $v0, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r2;
    // 0x8004E864: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E868: nop

    // 0x8004E86C: subu        $t1, $v0, $t9
    ctx->r9 = SUB32(ctx->r2, ctx->r25);
    // 0x8004E870: sh          $t1, 0x206($s0)
    MEM_H(0X206, ctx->r16) = ctx->r9;
L_8004E874:
    // 0x8004E874: lh          $v0, 0x18A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18A);
    // 0x8004E878: nop

    // 0x8004E87C: blez        $v0, L_8004E8D4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004E880: nop
    
            goto L_8004E8D4;
    }
    // 0x8004E880: nop

    // 0x8004E884: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E888: andi        $a2, $v0, 0xF
    ctx->r6 = ctx->r2 & 0XF;
    // 0x8004E88C: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x8004E890: sh          $t3, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r11;
    // 0x8004E894: lh          $t5, 0x18A($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X18A);
    // 0x8004E898: addiu       $a0, $zero, -0x50
    ctx->r4 = ADD32(0, -0X50);
    // 0x8004E89C: andi        $t4, $t5, 0xF
    ctx->r12 = ctx->r13 & 0XF;
    // 0x8004E8A0: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8004E8A4: beq         $at, $zero, L_8004E8B8
    if (ctx->r1 == 0) {
        // 0x8004E8A8: nop
    
            goto L_8004E8B8;
    }
    // 0x8004E8A8: nop

    // 0x8004E8AC: jal         0x8006FB8C
    // 0x8004E8B0: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    rand_range(rdram, ctx);
        goto after_29;
    // 0x8004E8B0: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_29:
    // 0x8004E8B4: sb          $v0, 0x1D1($s0)
    MEM_B(0X1D1, ctx->r16) = ctx->r2;
L_8004E8B8:
    // 0x8004E8B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004E8BC: lw          $t6, -0x254C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X254C);
    // 0x8004E8C0: lb          $t7, 0x1D1($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D1);
    // 0x8004E8C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E8C8: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x8004E8CC: b           L_8004E8D8
    // 0x8004E8D0: sw          $t0, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = ctx->r8;
        goto L_8004E8D8;
    // 0x8004E8D0: sw          $t0, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = ctx->r8;
L_8004E8D4:
    // 0x8004E8D4: sh          $zero, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = 0;
L_8004E8D8:
    // 0x8004E8D8: lb          $t8, 0x175($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X175);
    // 0x8004E8DC: nop

    // 0x8004E8E0: beq         $t8, $zero, L_8004E8F8
    if (ctx->r24 == 0) {
        // 0x8004E8E4: nop
    
            goto L_8004E8F8;
    }
    // 0x8004E8E4: nop

    // 0x8004E8E8: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E8EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E8F0: jal         0x80056E6C
    // 0x8004E8F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_activate_magnet(rdram, ctx);
        goto after_30;
    // 0x8004E8F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_30:
L_8004E8F8:
    // 0x8004E8F8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004E8FC: lw          $v1, -0x2540($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2540);
    // 0x8004E900: nop

    // 0x8004E904: beq         $v1, $zero, L_8004E948
    if (ctx->r3 == 0) {
        // 0x8004E908: nop
    
            goto L_8004E948;
    }
    // 0x8004E908: nop

    // 0x8004E90C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x8004E910: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004E914: lb          $v0, 0x4C($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X4C);
    // 0x8004E918: nop

    // 0x8004E91C: beq         $v0, $zero, L_8004E930
    if (ctx->r2 == 0) {
        // 0x8004E920: nop
    
            goto L_8004E930;
    }
    // 0x8004E920: nop

    // 0x8004E924: beq         $v0, $at, L_8004E930
    if (ctx->r2 == ctx->r1) {
        // 0x8004E928: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8004E930;
    }
    // 0x8004E928: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8004E92C: bne         $v0, $at, L_8004E948
    if (ctx->r2 != ctx->r1) {
        // 0x8004E930: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8004E948;
    }
L_8004E930:
    // 0x8004E930: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E934: sw          $zero, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = 0;
    // 0x8004E938: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E93C: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
    // 0x8004E940: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E944: sw          $zero, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = 0;
L_8004E948:
    // 0x8004E948: bne         $v1, $zero, L_8004E9BC
    if (ctx->r3 != 0) {
        // 0x8004E94C: nop
    
            goto L_8004E9BC;
    }
    // 0x8004E94C: nop

    // 0x8004E950: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x8004E954: lb          $t1, 0x194($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X194);
    // 0x8004E958: lb          $t3, 0x4B($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X4B);
    // 0x8004E95C: nop

    // 0x8004E960: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8004E964: beq         $at, $zero, L_8004E9BC
    if (ctx->r1 == 0) {
        // 0x8004E968: nop
    
            goto L_8004E9BC;
    }
    // 0x8004E968: nop

    // 0x8004E96C: jal         0x8000C8B4
    // 0x8004E970: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    normalise_time(rdram, ctx);
        goto after_31;
    // 0x8004E970: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    after_31:
    // 0x8004E974: lb          $t5, 0x194($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X194);
    // 0x8004E978: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E97C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8004E980: addu        $v1, $s0, $t4
    ctx->r3 = ADD32(ctx->r16, ctx->r12);
    // 0x8004E984: lw          $a0, 0x128($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X128);
    // 0x8004E988: subu        $t6, $v0, $a1
    ctx->r14 = SUB32(ctx->r2, ctx->r5);
    // 0x8004E98C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8004E990: beq         $at, $zero, L_8004E9A0
    if (ctx->r1 == 0) {
        // 0x8004E994: addu        $t7, $a0, $a1
        ctx->r15 = ADD32(ctx->r4, ctx->r5);
            goto L_8004E9A0;
    }
    // 0x8004E994: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x8004E998: b           L_8004E9BC
    // 0x8004E99C: sw          $t7, 0x128($v1)
    MEM_W(0X128, ctx->r3) = ctx->r15;
        goto L_8004E9BC;
    // 0x8004E99C: sw          $t7, 0x128($v1)
    MEM_W(0X128, ctx->r3) = ctx->r15;
L_8004E9A0:
    // 0x8004E9A0: jal         0x8000C8B4
    // 0x8004E9A4: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    normalise_time(rdram, ctx);
        goto after_32;
    // 0x8004E9A4: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    after_32:
    // 0x8004E9A8: lb          $t0, 0x194($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X194);
    // 0x8004E9AC: nop

    // 0x8004E9B0: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8004E9B4: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x8004E9B8: sw          $v0, 0x128($t9)
    MEM_W(0X128, ctx->r25) = ctx->r2;
L_8004E9BC:
    // 0x8004E9BC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8004E9C0: lw          $t2, -0x2524($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2524);
    // 0x8004E9C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004E9C8: beq         $t2, $at, L_8004E9E0
    if (ctx->r10 == ctx->r1) {
        // 0x8004E9CC: nop
    
            goto L_8004E9E0;
    }
    // 0x8004E9CC: nop

    // 0x8004E9D0: jal         0x80069F3C
    // 0x8004E9D4: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_33;
    // 0x8004E9D4: nop

    after_33:
    // 0x8004E9D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E9DC: sw          $v0, -0x2578($at)
    MEM_W(-0X2578, ctx->r1) = ctx->r2;
L_8004E9E0:
    // 0x8004E9E0: lh          $a0, 0x2E($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2E);
    // 0x8004E9E4: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004E9E8: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x8004E9EC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8004E9F0: jal         0x8002B134
    // 0x8004E9F4: addiu       $a3, $a3, -0x24D0
    ctx->r7 = ADD32(ctx->r7, -0X24D0);
    func_8002B0F4(rdram, ctx);
        goto after_34;
    // 0x8004E9F4: addiu       $a3, $a3, -0x24D0
    ctx->r7 = ADD32(ctx->r7, -0X24D0);
    after_34:
    // 0x8004E9F8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004E9FC: addiu       $v1, $v1, -0x24D2
    ctx->r3 = ADD32(ctx->r3, -0X24D2);
    // 0x8004EA00: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8004EA04: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x8004EA08: nop

    // 0x8004EA0C: beq         $a0, $zero, L_8004EA74
    if (ctx->r4 == 0) {
        // 0x8004EA10: nop
    
            goto L_8004EA74;
    }
    // 0x8004EA10: nop

    // 0x8004EA14: blez        $a0, L_8004EA74
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8004EA18: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004EA74;
    }
    // 0x8004EA18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004EA1C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004EA20: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8004EA24: lw          $v1, -0x24D0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X24D0);
    // 0x8004EA28: addiu       $a3, $a3, -0x2590
    ctx->r7 = ADD32(ctx->r7, -0X2590);
    // 0x8004EA2C: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x8004EA30: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
L_8004EA34:
    // 0x8004EA34: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004EA38: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004EA3C: lb          $t1, 0x10($a0)
    ctx->r9 = MEM_B(ctx->r4, 0X10);
    // 0x8004EA40: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8004EA44: bne         $a2, $t1, L_8004EA6C
    if (ctx->r6 != ctx->r9) {
        // 0x8004EA48: nop
    
            goto L_8004EA6C;
    }
    // 0x8004EA48: nop

    // 0x8004EA4C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8004EA50: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8004EA54: nop

    // 0x8004EA58: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8004EA5C: nop

    // 0x8004EA60: bc1f        L_8004EA6C
    if (!c1cs) {
        // 0x8004EA64: nop
    
            goto L_8004EA6C;
    }
    // 0x8004EA64: nop

    // 0x8004EA68: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
L_8004EA6C:
    // 0x8004EA6C: bne         $at, $zero, L_8004EA34
    if (ctx->r1 != 0) {
        // 0x8004EA70: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8004EA34;
    }
    // 0x8004EA70: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8004EA74:
    // 0x8004EA74: lb          $t3, 0x1D6($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004EA78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004EA7C: beq         $t3, $at, L_8004EB90
    if (ctx->r11 == ctx->r1) {
        // 0x8004EA80: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004EB90;
    }
    // 0x8004EA80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004EA84: lwc1        $f10, 0x6B3C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6B3C);
    // 0x8004EA88: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8004EA8C: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x8004EA90: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004EA94: addiu       $a2, $a2, -0x2588
    ctx->r6 = ADD32(ctx->r6, -0X2588);
    // 0x8004EA98: jal         0x8002AD48
    // 0x8004EA9C: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    get_wave_properties(rdram, ctx);
        goto after_35;
    // 0x8004EA9C: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    after_35:
    // 0x8004EAA0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004EAA4: addiu       $v1, $v1, -0x257C
    ctx->r3 = ADD32(ctx->r3, -0X257C);
    // 0x8004EAA8: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8004EAAC: lb          $t5, 0x0($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X0);
    // 0x8004EAB0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004EAB4: beq         $t5, $zero, L_8004EB08
    if (ctx->r13 == 0) {
        // 0x8004EAB8: nop
    
            goto L_8004EB08;
    }
    // 0x8004EAB8: nop

    // 0x8004EABC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004EAC0: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004EAC4: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8004EAC8: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8004EACC: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8004EAD0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8004EAD4: nop

    // 0x8004EAD8: bc1f        L_8004EAFC
    if (!c1cs) {
        // 0x8004EADC: nop
    
            goto L_8004EAFC;
    }
    // 0x8004EADC: nop

    // 0x8004EAE0: sb          $t4, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r12;
    // 0x8004EAE4: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004EAE8: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8004EAEC: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8004EAF0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8004EAF4: b           L_8004EB34
    // 0x8004EAF8: swc1        $f6, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f6.u32l;
        goto L_8004EB34;
    // 0x8004EAF8: swc1        $f6, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f6.u32l;
L_8004EAFC:
    // 0x8004EAFC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004EB00: b           L_8004EB34
    // 0x8004EB04: swc1        $f8, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f8.u32l;
        goto L_8004EB34;
    // 0x8004EB04: swc1        $f8, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f8.u32l;
L_8004EB08:
    // 0x8004EB08: lb          $v0, 0x1E5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E5);
    // 0x8004EB0C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004EB10: blez        $v0, L_8004EB28
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004EB14: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8004EB28;
    }
    // 0x8004EB14: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8004EB18: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004EB1C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004EB20: b           L_8004EB34
    // 0x8004EB24: sb          $t6, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r14;
        goto L_8004EB34;
    // 0x8004EB24: sb          $t6, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r14;
L_8004EB28:
    // 0x8004EB28: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004EB2C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004EB30: swc1        $f10, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f10.u32l;
L_8004EB34:
    // 0x8004EB34: lb          $t7, 0x1E5($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1E5);
    // 0x8004EB38: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8004EB3C: blez        $t7, L_8004EB78
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8004EB40: nop
    
            goto L_8004EB78;
    }
    // 0x8004EB40: nop

    // 0x8004EB44: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004EB48: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8004EB4C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8004EB50: nop

    // 0x8004EB54: bc1f        L_8004EB78
    if (!c1cs) {
        // 0x8004EB58: nop
    
            goto L_8004EB78;
    }
    // 0x8004EB58: nop

    // 0x8004EB5C: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    // 0x8004EB60: nop

    // 0x8004EB64: lh          $t0, 0x14($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X14);
    // 0x8004EB68: nop

    // 0x8004EB6C: ori         $t8, $t0, 0x10
    ctx->r24 = ctx->r8 | 0X10;
    // 0x8004EB70: b           L_8004EB90
    // 0x8004EB74: sh          $t8, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r24;
        goto L_8004EB90;
    // 0x8004EB74: sh          $t8, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r24;
L_8004EB78:
    // 0x8004EB78: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    // 0x8004EB7C: nop

    // 0x8004EB80: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
    // 0x8004EB84: nop

    // 0x8004EB88: andi        $t2, $t9, 0xFFEF
    ctx->r10 = ctx->r25 & 0XFFEF;
    // 0x8004EB8C: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
L_8004EB90:
    // 0x8004EB90: jal         0x8002AD08
    // 0x8004EB94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_collision_mode(rdram, ctx);
        goto after_36;
    // 0x8004EB94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_36:
    // 0x8004EB98: lbu         $t1, 0x1D6($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1D6);
    // 0x8004EB9C: nop

    // 0x8004EBA0: sltiu       $at, $t1, 0xE
    ctx->r1 = ctx->r9 < 0XE ? 1 : 0;
    // 0x8004EBA4: beq         $at, $zero, L_8004EDC8
    if (ctx->r1 == 0) {
        // 0x8004EBA8: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8004EDC8;
    }
    // 0x8004EBA8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8004EBAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004EBB0: addu        $at, $at, $t1
    gpr jr_addend_8004EBBC = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8004EBB4: lw          $t1, 0x6B40($at)
    ctx->r9 = ADD32(ctx->r1, 0X6B40);
    // 0x8004EBB8: nop

    // 0x8004EBBC: jr          $t1
    // 0x8004EBC0: nop

    switch (jr_addend_8004EBBC >> 2) {
        case 0: goto L_8004EBC4; break;
        case 1: goto L_8004EBFC; break;
        case 2: goto L_8004EC18; break;
        case 3: goto L_8004EC34; break;
        case 4: goto L_8004EBE0; break;
        case 5: goto L_8004EC50; break;
        case 6: goto L_8004EC90; break;
        case 7: goto L_8004ECD0; break;
        case 8: goto L_8004ECD0; break;
        case 9: goto L_8004EDC8; break;
        case 10: goto L_8004EC34; break;
        case 11: goto L_8004ED10; break;
        case 12: goto L_8004ED50; break;
        case 13: goto L_8004ED90; break;
        default: switch_error(__func__, 0x8004EBBC, 0x800E6B40);
    }
    // 0x8004EBC0: nop

L_8004EBC4:
    // 0x8004EBC4: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EBC8: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004EBCC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004EBD0: jal         0x8004F834
    // 0x8004EBD4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8004F7F4(rdram, ctx);
        goto after_37;
    // 0x8004EBD4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_37:
    // 0x8004EBD8: b           L_8004EDCC
    // 0x8004EBDC: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004EDCC;
    // 0x8004EBDC: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004EBE0:
    // 0x8004EBE0: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EBE4: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004EBE8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004EBEC: jal         0x8004CC60
    // 0x8004EBF0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8004CC20(rdram, ctx);
        goto after_38;
    // 0x8004EBF0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_38:
    // 0x8004EBF4: b           L_8004EDCC
    // 0x8004EBF8: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004EDCC;
    // 0x8004EBF8: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004EBFC:
    // 0x8004EBFC: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EC00: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004EC04: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004EC08: jal         0x80046564
    // 0x8004EC0C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80046524(rdram, ctx);
        goto after_39;
    // 0x8004EC0C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_39:
    // 0x8004EC10: b           L_8004EDCC
    // 0x8004EC14: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004EDCC;
    // 0x8004EC14: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004EC18:
    // 0x8004EC18: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EC1C: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004EC20: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004EC24: jal         0x800497D4
    // 0x8004EC28: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80049794(rdram, ctx);
        goto after_40;
    // 0x8004EC28: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_40:
    // 0x8004EC2C: b           L_8004EDCC
    // 0x8004EC30: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004EDCC;
    // 0x8004EC30: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004EC34:
    // 0x8004EC34: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EC38: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004EC3C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004EC40: jal         0x8004D99C
    // 0x8004EC44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_carpet(rdram, ctx);
        goto after_41;
    // 0x8004EC44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_41:
    // 0x8004EC48: b           L_8004EDCC
    // 0x8004EC4C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004EDCC;
    // 0x8004EC4C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004EC50:
    // 0x8004EC50: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004EC54: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004EC58: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004EC5C: addiu       $t4, $t4, -0x2540
    ctx->r12 = ADD32(ctx->r12, -0X2540);
    // 0x8004EC60: addiu       $t5, $t5, -0x2554
    ctx->r13 = ADD32(ctx->r13, -0X2554);
    // 0x8004EC64: addiu       $t3, $t3, -0x2558
    ctx->r11 = ADD32(ctx->r11, -0X2558);
    // 0x8004EC68: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EC6C: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004EC70: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8004EC74: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8004EC78: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8004EC7C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004EC80: jal         0x8005C504
    // 0x8004EC84: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_tricky(rdram, ctx);
        goto after_42;
    // 0x8004EC84: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_42:
    // 0x8004EC88: b           L_8004EDCC
    // 0x8004EC8C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004EDCC;
    // 0x8004EC8C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004EC90:
    // 0x8004EC90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004EC94: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004EC98: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004EC9C: addiu       $t0, $t0, -0x2540
    ctx->r8 = ADD32(ctx->r8, -0X2540);
    // 0x8004ECA0: addiu       $t7, $t7, -0x2554
    ctx->r15 = ADD32(ctx->r15, -0X2554);
    // 0x8004ECA4: addiu       $t6, $t6, -0x2558
    ctx->r14 = ADD32(ctx->r14, -0X2558);
    // 0x8004ECA8: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004ECAC: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004ECB0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8004ECB4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8004ECB8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8004ECBC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004ECC0: jal         0x8005D270
    // 0x8004ECC4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_bluey(rdram, ctx);
        goto after_43;
    // 0x8004ECC4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_43:
    // 0x8004ECC8: b           L_8004EDCC
    // 0x8004ECCC: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004EDCC;
    // 0x8004ECCC: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004ECD0:
    // 0x8004ECD0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004ECD4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8004ECD8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8004ECDC: addiu       $t2, $t2, -0x2540
    ctx->r10 = ADD32(ctx->r10, -0X2540);
    // 0x8004ECE0: addiu       $t9, $t9, -0x254C
    ctx->r25 = ADD32(ctx->r25, -0X254C);
    // 0x8004ECE4: addiu       $t8, $t8, -0x2558
    ctx->r24 = ADD32(ctx->r24, -0X2558);
    // 0x8004ECE8: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004ECEC: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004ECF0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8004ECF4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8004ECF8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8004ECFC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004ED00: jal         0x8005D9C0
    // 0x8004ED04: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_smokey(rdram, ctx);
        goto after_44;
    // 0x8004ED04: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_44:
    // 0x8004ED08: b           L_8004EDCC
    // 0x8004ED0C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004EDCC;
    // 0x8004ED0C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004ED10:
    // 0x8004ED10: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004ED14: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004ED18: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004ED1C: addiu       $t5, $t5, -0x2540
    ctx->r13 = ADD32(ctx->r13, -0X2540);
    // 0x8004ED20: addiu       $t3, $t3, -0x2554
    ctx->r11 = ADD32(ctx->r11, -0X2554);
    // 0x8004ED24: addiu       $t1, $t1, -0x2558
    ctx->r9 = ADD32(ctx->r9, -0X2558);
    // 0x8004ED28: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004ED2C: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004ED30: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8004ED34: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8004ED38: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8004ED3C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004ED40: jal         0x8005E660
    // 0x8004ED44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_bubbler(rdram, ctx);
        goto after_45;
    // 0x8004ED44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_45:
    // 0x8004ED48: b           L_8004EDCC
    // 0x8004ED4C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004EDCC;
    // 0x8004ED4C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004ED50:
    // 0x8004ED50: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004ED54: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004ED58: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004ED5C: addiu       $t7, $t7, -0x2540
    ctx->r15 = ADD32(ctx->r15, -0X2540);
    // 0x8004ED60: addiu       $t6, $t6, -0x2554
    ctx->r14 = ADD32(ctx->r14, -0X2554);
    // 0x8004ED64: addiu       $t4, $t4, -0x2558
    ctx->r12 = ADD32(ctx->r12, -0X2558);
    // 0x8004ED68: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004ED6C: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004ED70: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8004ED74: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8004ED78: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8004ED7C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004ED80: jal         0x8005EC30
    // 0x8004ED84: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_wizpig(rdram, ctx);
        goto after_46;
    // 0x8004ED84: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_46:
    // 0x8004ED88: b           L_8004EDCC
    // 0x8004ED8C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004EDCC;
    // 0x8004ED8C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004ED90:
    // 0x8004ED90: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004ED94: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004ED98: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8004ED9C: addiu       $t9, $t9, -0x2540
    ctx->r25 = ADD32(ctx->r25, -0X2540);
    // 0x8004EDA0: addiu       $t8, $t8, -0x2554
    ctx->r24 = ADD32(ctx->r24, -0X2554);
    // 0x8004EDA4: addiu       $t0, $t0, -0x2558
    ctx->r8 = ADD32(ctx->r8, -0X2558);
    // 0x8004EDA8: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EDAC: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004EDB0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8004EDB4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8004EDB8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8004EDBC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004EDC0: jal         0x8005F4B0
    // 0x8004EDC4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_rocket(rdram, ctx);
        goto after_47;
    // 0x8004EDC4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_47:
L_8004EDC8:
    // 0x8004EDC8: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004EDCC:
    // 0x8004EDCC: nop

    // 0x8004EDD0: bne         $t2, $zero, L_8004EDF8
    if (ctx->r10 != 0) {
        // 0x8004EDD4: lw          $t1, 0x7C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X7C);
            goto L_8004EDF8;
    }
    // 0x8004EDD4: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8004EDD8: lw          $a0, 0x178($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X178);
    // 0x8004EDDC: nop

    // 0x8004EDE0: beq         $a0, $zero, L_8004EDF8
    if (ctx->r4 == 0) {
        // 0x8004EDE4: lw          $t1, 0x7C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X7C);
            goto L_8004EDF8;
    }
    // 0x8004EDE4: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8004EDE8: jal         0x8000488C
    // 0x8004EDEC: nop

    sndp_stop(rdram, ctx);
        goto after_48;
    // 0x8004EDEC: nop

    after_48:
    // 0x8004EDF0: sw          $zero, 0x178($s0)
    MEM_W(0X178, ctx->r16) = 0;
    // 0x8004EDF4: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
L_8004EDF8:
    // 0x8004EDF8: nop

    // 0x8004EDFC: lb          $v0, 0x4A($t1)
    ctx->r2 = MEM_B(ctx->r9, 0X4A);
    // 0x8004EE00: nop

    // 0x8004EE04: beq         $v0, $zero, L_8004EE4C
    if (ctx->r2 == 0) {
        // 0x8004EE08: lw          $t3, 0xA4($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XA4);
            goto L_8004EE4C;
    }
    // 0x8004EE08: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x8004EE0C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8004EE10: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004EE14: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004EE18: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004EE1C: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
    // 0x8004EE20: bc1f        L_8004EE34
    if (!c1cs) {
        // 0x8004EE24: nop
    
            goto L_8004EE34;
    }
    // 0x8004EE24: nop

    // 0x8004EE28: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x8004EE2C: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004EE30: nop

L_8004EE34:
    // 0x8004EE34: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8004EE38: nop

    // 0x8004EE3C: bc1f        L_8004EE4C
    if (!c1cs) {
        // 0x8004EE40: lw          $t3, 0xA4($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XA4);
            goto L_8004EE4C;
    }
    // 0x8004EE40: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x8004EE44: swc1        $f12, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f12.u32l;
    // 0x8004EE48: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
L_8004EE4C:
    // 0x8004EE4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004EE50: bne         $t3, $at, L_8004EE64
    if (ctx->r11 != ctx->r1) {
        // 0x8004EE54: nop
    
            goto L_8004EE64;
    }
    // 0x8004EE54: nop

    // 0x8004EE58: jal         0x8000E148
    // 0x8004EE5C: nop

    racetype_demo(rdram, ctx);
        goto after_49;
    // 0x8004EE5C: nop

    after_49:
    // 0x8004EE60: beq         $v0, $zero, L_8004EE80
    if (ctx->r2 == 0) {
        // 0x8004EE64: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8004EE80;
    }
L_8004EE64:
    // 0x8004EE64: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004EE68: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8004EE6C: lw          $a2, -0x2558($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2558);
    // 0x8004EE70: lw          $a1, -0x2554($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2554);
    // 0x8004EE74: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EE78: jal         0x800050D0
    // 0x8004EE7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    racer_sound_update(rdram, ctx);
        goto after_50;
    // 0x8004EE7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_50:
L_8004EE80:
    // 0x8004EE80: lwc1        $f6, 0xA8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004EE84: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004EE88: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x8004EE8C: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8004EE90: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x8004EE94: lw          $a3, 0x8C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X8C);
    // 0x8004EE98: addiu       $t5, $s0, 0xA8
    ctx->r13 = ADD32(ctx->r16, 0XA8);
    // 0x8004EE9C: addiu       $t4, $s0, 0x1C8
    ctx->r12 = ADD32(ctx->r16, 0X1C8);
    // 0x8004EEA0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8004EEA4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8004EEA8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8004EEAC: jal         0x80018618
    // 0x8004EEB0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    checkpoint_is_passed(rdram, ctx);
        goto after_51;
    // 0x8004EEB0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_51:
    // 0x8004EEB4: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x8004EEB8: bne         $v0, $at, L_8004EED4
    if (ctx->r2 != ctx->r1) {
        // 0x8004EEBC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8004EED4;
    }
    // 0x8004EEBC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8004EEC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004EEC4: jal         0x8005C410
    // 0x8004EEC8: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    racer_update_progress(rdram, ctx);
        goto after_52;
    // 0x8004EEC8: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    after_52:
    // 0x8004EECC: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x8004EED0: nop

L_8004EED4:
    // 0x8004EED4: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8004EED8: lbu         $a1, 0x1C8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C8);
    // 0x8004EEDC: jal         0x8001BA50
    // 0x8004EEE0: sw          $a2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r6;
    find_next_checkpoint_node(rdram, ctx);
        goto after_53;
    // 0x8004EEE0: sw          $a2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r6;
    after_53:
    // 0x8004EEE4: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8004EEE8: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x8004EEEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004EEF0: bne         $t6, $at, L_8004EF28
    if (ctx->r14 != ctx->r1) {
        // 0x8004EEF4: nop
    
            goto L_8004EF28;
    }
    // 0x8004EEF4: nop

    // 0x8004EEF8: lb          $t7, 0x1CA($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1CA);
    // 0x8004EEFC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004EF00: addu        $t0, $v0, $t7
    ctx->r8 = ADD32(ctx->r2, ctx->r15);
    // 0x8004EF04: lb          $t8, 0x36($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X36);
    // 0x8004EF08: nop

    // 0x8004EF0C: bne         $t8, $at, L_8004EF28
    if (ctx->r24 != ctx->r1) {
        // 0x8004EF10: nop
    
            goto L_8004EF28;
    }
    // 0x8004EF10: nop

    // 0x8004EF14: lb          $t9, 0x1E5($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E5);
    // 0x8004EF18: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8004EF1C: beq         $t9, $zero, L_8004EF28
    if (ctx->r25 == 0) {
        // 0x8004EF20: nop
    
            goto L_8004EF28;
    }
    // 0x8004EF20: nop

    // 0x8004EF24: sb          $t2, 0x1C8($s0)
    MEM_B(0X1C8, ctx->r16) = ctx->r10;
L_8004EF28:
    // 0x8004EF28: lb          $t1, 0x1CA($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1CA);
    // 0x8004EF2C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8004EF30: addu        $t3, $v0, $t1
    ctx->r11 = ADD32(ctx->r2, ctx->r9);
    // 0x8004EF34: lb          $t5, 0x36($t3)
    ctx->r13 = MEM_B(ctx->r11, 0X36);
    // 0x8004EF38: nop

    // 0x8004EF3C: bne         $t5, $at, L_8004EF5C
    if (ctx->r13 != ctx->r1) {
        // 0x8004EF40: nop
    
            goto L_8004EF5C;
    }
    // 0x8004EF40: nop

    // 0x8004EF44: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x8004EF48: nop

    // 0x8004EF4C: lb          $t6, 0x4B($t4)
    ctx->r14 = MEM_B(ctx->r12, 0X4B);
    // 0x8004EF50: nop

    // 0x8004EF54: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004EF58: sb          $t7, 0x193($s0)
    MEM_B(0X193, ctx->r16) = ctx->r15;
L_8004EF5C:
    // 0x8004EF5C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x8004EF60: bne         $a2, $zero, L_8004F1C0
    if (ctx->r6 != 0) {
        // 0x8004EF64: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8004F1C0;
    }
    // 0x8004EF64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004EF68: bne         $v1, $at, L_8004EF90
    if (ctx->r3 != ctx->r1) {
        // 0x8004EF6C: nop
    
            goto L_8004EF90;
    }
    // 0x8004EF6C: nop

    // 0x8004EF70: lb          $t0, 0x1CA($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1CA);
    // 0x8004EF74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004EF78: addu        $t8, $v0, $t0
    ctx->r24 = ADD32(ctx->r2, ctx->r8);
    // 0x8004EF7C: lb          $t9, 0x36($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X36);
    // 0x8004EF80: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8004EF84: bne         $t9, $at, L_8004EF90
    if (ctx->r25 != ctx->r1) {
        // 0x8004EF88: nop
    
            goto L_8004EF90;
    }
    // 0x8004EF88: nop

    // 0x8004EF8C: sb          $t2, 0x1C8($s0)
    MEM_B(0X1C8, ctx->r16) = ctx->r10;
L_8004EF90:
    // 0x8004EF90: jal         0x8001BA98
    // 0x8004EF94: nop

    get_checkpoint_count(rdram, ctx);
        goto after_54;
    // 0x8004EF94: nop

    after_54:
    // 0x8004EF98: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x8004EF9C: lb          $t1, 0x192($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X192);
    // 0x8004EFA0: nop

    // 0x8004EFA4: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8004EFA8: sb          $t3, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r11;
    // 0x8004EFAC: lb          $t5, 0x192($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X192);
    // 0x8004EFB0: nop

    // 0x8004EFB4: slt         $at, $t5, $v0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004EFB8: bne         $at, $zero, L_8004F048
    if (ctx->r1 != 0) {
        // 0x8004EFBC: nop
    
            goto L_8004F048;
    }
    // 0x8004EFBC: nop

    // 0x8004EFC0: lh          $t4, 0x190($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X190);
    // 0x8004EFC4: sb          $zero, 0x192($s0)
    MEM_B(0X192, ctx->r16) = 0;
    // 0x8004EFC8: blez        $t4, L_8004EFE8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8004EFCC: nop
    
            goto L_8004EFE8;
    }
    // 0x8004EFCC: nop

    // 0x8004EFD0: lb          $v0, 0x193($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X193);
    // 0x8004EFD4: nop

    // 0x8004EFD8: slti        $at, $v0, 0x78
    ctx->r1 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x8004EFDC: beq         $at, $zero, L_8004EFE8
    if (ctx->r1 == 0) {
        // 0x8004EFE0: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8004EFE8;
    }
    // 0x8004EFE0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8004EFE4: sb          $t6, 0x193($s0)
    MEM_B(0X193, ctx->r16) = ctx->r14;
L_8004EFE8:
    // 0x8004EFE8: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8004EFEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004EFF0: beq         $t7, $at, L_8004F048
    if (ctx->r15 == ctx->r1) {
        // 0x8004EFF4: nop
    
            goto L_8004F048;
    }
    // 0x8004EFF4: nop

    // 0x8004EFF8: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x8004EFFC: lb          $t9, 0x193($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X193);
    // 0x8004F000: lb          $t8, 0x4B($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X4B);
    // 0x8004F004: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8004F008: bne         $t8, $t2, L_8004F048
    if (ctx->r24 != ctx->r10) {
        // 0x8004F00C: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8004F048;
    }
    // 0x8004F00C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004F010: lbu         $t1, -0x2500($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X2500);
    // 0x8004F014: nop

    // 0x8004F018: bne         $t1, $zero, L_8004F048
    if (ctx->r9 != 0) {
        // 0x8004F01C: nop
    
            goto L_8004F048;
    }
    // 0x8004F01C: nop

    // 0x8004F020: jal         0x8006BFD8
    // 0x8004F024: nop

    level_type(rdram, ctx);
        goto after_55;
    // 0x8004F024: nop

    after_55:
    // 0x8004F028: bne         $v0, $zero, L_8004F048
    if (ctx->r2 != 0) {
        // 0x8004F02C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004F048;
    }
    // 0x8004F02C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004F030: lwc1        $f12, 0x6B78($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6B78);
    // 0x8004F034: jal         0x800014BC
    // 0x8004F038: nop

    music_tempo_set_relative(rdram, ctx);
        goto after_56;
    // 0x8004F038: nop

    after_56:
    // 0x8004F03C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004F040: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004F044: sb          $t3, -0x2500($at)
    MEM_B(-0X2500, ctx->r1) = ctx->r11;
L_8004F048:
    // 0x8004F048: jal         0x80023450
    // 0x8004F04C: nop

    is_taj_challenge(rdram, ctx);
        goto after_57;
    // 0x8004F04C: nop

    after_57:
    // 0x8004F050: beq         $v0, $zero, L_8004F184
    if (ctx->r2 == 0) {
        // 0x8004F054: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8004F184;
    }
    // 0x8004F054: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004F058: lw          $t5, -0x2524($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2524);
    // 0x8004F05C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004F060: beq         $t5, $at, L_8004F188
    if (ctx->r13 == ctx->r1) {
        // 0x8004F064: lw          $t6, 0x7C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X7C);
            goto L_8004F188;
    }
    // 0x8004F064: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8004F068: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8004F06C: lbu         $a1, 0x1C8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C8);
    // 0x8004F070: jal         0x8001BA50
    // 0x8004F074: nop

    find_next_checkpoint_node(rdram, ctx);
        goto after_58;
    // 0x8004F074: nop

    after_58:
    // 0x8004F078: lw          $t4, 0x15C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F07C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8004F080: bne         $t4, $zero, L_8004F0CC
    if (ctx->r12 != 0) {
        // 0x8004F084: addiu       $t6, $zero, 0x86
        ctx->r14 = ADD32(0, 0X86);
            goto L_8004F0CC;
    }
    // 0x8004F084: addiu       $t6, $zero, 0x86
    ctx->r14 = ADD32(0, 0X86);
    // 0x8004F088: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8004F08C: sh          $zero, 0x66($sp)
    MEM_H(0X66, ctx->r29) = 0;
    // 0x8004F090: sh          $zero, 0x68($sp)
    MEM_H(0X68, ctx->r29) = 0;
    // 0x8004F094: sh          $zero, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = 0;
    // 0x8004F098: sb          $t6, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r14;
    // 0x8004F09C: sb          $t7, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r15;
    // 0x8004F0A0: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8004F0A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8004F0A8: jal         0x8000EA54
    // 0x8004F0AC: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    spawn_object(rdram, ctx);
        goto after_59;
    // 0x8004F0AC: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    after_59:
    // 0x8004F0B0: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x8004F0B4: beq         $v0, $zero, L_8004F0CC
    if (ctx->r2 == 0) {
        // 0x8004F0B8: sw          $v0, 0x15C($s0)
        MEM_W(0X15C, ctx->r16) = ctx->r2;
            goto L_8004F0CC;
    }
    // 0x8004F0B8: sw          $v0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r2;
    // 0x8004F0BC: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8004F0C0: lw          $t8, 0x15C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F0C4: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x8004F0C8: sb          $t9, 0x39($t8)
    MEM_B(0X39, ctx->r24) = ctx->r25;
L_8004F0CC:
    // 0x8004F0CC: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F0D0: nop

    // 0x8004F0D4: beq         $v0, $zero, L_8004F188
    if (ctx->r2 == 0) {
        // 0x8004F0D8: lw          $t6, 0x7C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X7C);
            goto L_8004F188;
    }
    // 0x8004F0D8: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8004F0DC: lw          $t2, 0x28($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X28);
    // 0x8004F0E0: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x8004F0E4: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8004F0E8: nop

    // 0x8004F0EC: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8004F0F0: lw          $t1, 0x28($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X28);
    // 0x8004F0F4: lw          $t3, 0x15C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F0F8: lwc1        $f10, 0x10($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X10);
    // 0x8004F0FC: nop

    // 0x8004F100: swc1        $f10, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f10.u32l;
    // 0x8004F104: lb          $t5, 0x1D6($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004F108: nop

    // 0x8004F10C: bne         $t5, $zero, L_8004F134
    if (ctx->r13 != 0) {
        // 0x8004F110: nop
    
            goto L_8004F134;
    }
    // 0x8004F110: nop

    // 0x8004F114: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F118: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004F11C: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004F120: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004F124: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8004F128: sub.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d - ctx->f8.d;
    // 0x8004F12C: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x8004F130: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
L_8004F134:
    // 0x8004F134: lw          $t4, 0x28($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X28);
    // 0x8004F138: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F13C: lwc1        $f4, 0x14($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X14);
    // 0x8004F140: nop

    // 0x8004F144: swc1        $f4, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f4.u32l;
    // 0x8004F148: lw          $t7, 0x28($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X28);
    // 0x8004F14C: lw          $t9, 0x15C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F150: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x8004F154: nop

    // 0x8004F158: sh          $t0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r8;
    // 0x8004F15C: lw          $t8, 0x28($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X28);
    // 0x8004F160: lw          $t1, 0x15C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F164: lh          $t2, 0x2($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X2);
    // 0x8004F168: nop

    // 0x8004F16C: sh          $t2, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r10;
    // 0x8004F170: lw          $t3, 0x28($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X28);
    // 0x8004F174: lw          $t4, 0x15C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F178: lh          $t5, 0x2E($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X2E);
    // 0x8004F17C: nop

    // 0x8004F180: sh          $t5, 0x2E($t4)
    MEM_H(0X2E, ctx->r12) = ctx->r13;
L_8004F184:
    // 0x8004F184: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
L_8004F188:
    // 0x8004F188: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x8004F18C: lb          $t7, 0x4B($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X4B);
    // 0x8004F190: lh          $v0, 0x190($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X190);
    // 0x8004F194: addiu       $t0, $t7, 0x3
    ctx->r8 = ADD32(ctx->r15, 0X3);
    // 0x8004F198: multu       $t0, $t9
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004F19C: addiu       $t1, $zero, 0x2710
    ctx->r9 = ADD32(0, 0X2710);
    // 0x8004F1A0: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x8004F1A4: mflo        $t8
    ctx->r24 = lo;
    // 0x8004F1A8: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8004F1AC: beq         $at, $zero, L_8004F1B8
    if (ctx->r1 == 0) {
        // 0x8004F1B0: nop
    
            goto L_8004F1B8;
    }
    // 0x8004F1B0: nop

    // 0x8004F1B4: sh          $t2, 0x190($s0)
    MEM_H(0X190, ctx->r16) = ctx->r10;
L_8004F1B8:
    // 0x8004F1B8: b           L_8004F1F0
    // 0x8004F1BC: sh          $t1, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r9;
        goto L_8004F1F0;
    // 0x8004F1BC: sh          $t1, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r9;
L_8004F1C0:
    // 0x8004F1C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004F1C4: bne         $v1, $at, L_8004F1EC
    if (ctx->r3 != ctx->r1) {
        // 0x8004F1C8: nop
    
            goto L_8004F1EC;
    }
    // 0x8004F1C8: nop

    // 0x8004F1CC: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8004F1D0: lwc1        $f8, 0xA8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004F1D4: nop

    // 0x8004F1D8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8004F1DC: nop

    // 0x8004F1E0: bc1f        L_8004F1EC
    if (!c1cs) {
        // 0x8004F1E4: nop
    
            goto L_8004F1EC;
    }
    // 0x8004F1E4: nop

    // 0x8004F1E8: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
L_8004F1EC:
    // 0x8004F1EC: sh          $a2, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r6;
L_8004F1F0:
    // 0x8004F1F0: jal         0x80023450
    // 0x8004F1F4: nop

    is_taj_challenge(rdram, ctx);
        goto after_60;
    // 0x8004F1F4: nop

    after_60:
    // 0x8004F1F8: beq         $v0, $zero, L_8004F248
    if (ctx->r2 == 0) {
        // 0x8004F1FC: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_8004F248;
    }
    // 0x8004F1FC: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F200: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F204: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F208: beq         $v0, $zero, L_8004F220
    if (ctx->r2 == 0) {
        // 0x8004F20C: nop
    
            goto L_8004F220;
    }
    // 0x8004F20C: nop

    // 0x8004F210: lh          $t3, 0x18($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X18);
    // 0x8004F214: sll         $t4, $t5, 3
    ctx->r12 = S32(ctx->r13 << 3);
    // 0x8004F218: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x8004F21C: sh          $t6, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r14;
L_8004F220:
    // 0x8004F220: lh          $v0, 0x1BA($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1BA);
    // 0x8004F224: nop

    // 0x8004F228: slti        $at, $v0, 0x191
    ctx->r1 = SIGNED(ctx->r2) < 0X191 ? 1 : 0;
    // 0x8004F22C: beq         $at, $zero, L_8004F23C
    if (ctx->r1 == 0) {
        // 0x8004F230: slti        $at, $v0, -0x190
        ctx->r1 = SIGNED(ctx->r2) < -0X190 ? 1 : 0;
            goto L_8004F23C;
    }
    // 0x8004F230: slti        $at, $v0, -0x190
    ctx->r1 = SIGNED(ctx->r2) < -0X190 ? 1 : 0;
    // 0x8004F234: beq         $at, $zero, L_8004F248
    if (ctx->r1 == 0) {
        // 0x8004F238: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_8004F248;
    }
    // 0x8004F238: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
L_8004F23C:
    // 0x8004F23C: jal         0x80022E4C
    // 0x8004F240: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mode_end_taj_race(rdram, ctx);
        goto after_61;
    // 0x8004F240: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_61:
    // 0x8004F244: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
L_8004F248:
    // 0x8004F248: lw          $a1, 0x90($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X90);
    // 0x8004F24C: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8004F250: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x8004F254: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004F258: jal         0x80018D14
    // 0x8004F25C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_80018CE0(rdram, ctx);
        goto after_62;
    // 0x8004F25C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_62:
    // 0x8004F260: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F264: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004F268: jal         0x80059248
    // 0x8004F26C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80059208(rdram, ctx);
        goto after_63;
    // 0x8004F26C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_63:
    // 0x8004F270: lb          $t0, 0x1D8($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1D8);
    // 0x8004F274: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004F278: bne         $t0, $at, L_8004F298
    if (ctx->r8 != ctx->r1) {
        // 0x8004F27C: nop
    
            goto L_8004F298;
    }
    // 0x8004F27C: nop

    // 0x8004F280: lb          $v0, 0x1D9($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D9);
    // 0x8004F284: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F288: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x8004F28C: beq         $at, $zero, L_8004F298
    if (ctx->r1 == 0) {
        // 0x8004F290: addu        $t8, $v0, $t9
        ctx->r24 = ADD32(ctx->r2, ctx->r25);
            goto L_8004F298;
    }
    // 0x8004F290: addu        $t8, $v0, $t9
    ctx->r24 = ADD32(ctx->r2, ctx->r25);
    // 0x8004F294: sb          $t8, 0x1D9($s0)
    MEM_B(0X1D9, ctx->r16) = ctx->r24;
L_8004F298:
    // 0x8004F298: lb          $a2, 0x188($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X188);
    // 0x8004F29C: nop

    // 0x8004F2A0: blez        $a2, L_8004F2B0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8004F2A4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004F2B0;
    }
    // 0x8004F2A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004F2A8: jal         0x80057720
    // 0x8004F2AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    drop_bananas(rdram, ctx);
        goto after_64;
    // 0x8004F2AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_64:
L_8004F2B0:
    // 0x8004F2B0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8004F2B4: lw          $t2, -0x2524($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2524);
    // 0x8004F2B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004F2BC: sh          $t2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r10;
    // 0x8004F2C0: lw          $a2, 0x9C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X9C);
    // 0x8004F2C4: jal         0x80057A80
    // 0x8004F2C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    update_player_camera(rdram, ctx);
        goto after_65;
    // 0x8004F2C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_65:
    // 0x8004F2CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004F2D0: sb          $zero, -0x24FD($at)
    MEM_B(-0X24FD, ctx->r1) = 0;
    // 0x8004F2D4: lw          $t1, 0x148($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X148);
    // 0x8004F2D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004F2DC: beq         $t1, $zero, L_8004F2F4
    if (ctx->r9 == 0) {
        // 0x8004F2E0: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8004F2F4;
    }
    // 0x8004F2E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004F2E4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004F2E8: sw          $zero, 0x148($s0)
    MEM_W(0X148, ctx->r16) = 0;
    // 0x8004F2EC: swc1        $f14, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f14.u32l;
    // 0x8004F2F0: swc1        $f14, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f14.u32l;
L_8004F2F4:
    // 0x8004F2F4: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    // 0x8004F2F8: lwc1        $f0, 0x8C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8004F2FC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004F300: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8004F304: sub.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8004F308: bc1f        L_8004F31C
    if (!c1cs) {
        // 0x8004F30C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004F31C;
    }
    // 0x8004F30C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004F310: lwc1        $f2, 0x6B7C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B7C);
    // 0x8004F314: b           L_8004F32C
    // 0x8004F318: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
        goto L_8004F32C;
    // 0x8004F318: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_8004F31C:
    // 0x8004F31C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004F320: lwc1        $f2, 0x6B80($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B80);
    // 0x8004F324: nop

    // 0x8004F328: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_8004F32C:
    // 0x8004F32C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004F330: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8004F334: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x8004F338: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8004F33C: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004F340: lwc1        $f5, 0x50($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x8004F344: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x8004F348: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x8004F34C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8004F350: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8004F354: add.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f10.d + ctx->f8.d;
    // 0x8004F358: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8004F35C: bc1f        L_8004F37C
    if (!c1cs) {
        // 0x8004F360: swc1        $f4, 0x8C($s0)
        MEM_W(0X8C, ctx->r16) = ctx->f4.u32l;
            goto L_8004F37C;
    }
    // 0x8004F360: swc1        $f4, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f4.u32l;
    // 0x8004F364: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8004F368: nop

    // 0x8004F36C: c.le.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl <= ctx->f12.fl;
    // 0x8004F370: nop

    // 0x8004F374: bc1t        L_8004F3A4
    if (c1cs) {
        // 0x8004F378: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8004F3A4;
    }
    // 0x8004F378: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8004F37C:
    // 0x8004F37C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8004F380: nop

    // 0x8004F384: bc1f        L_8004F3B0
    if (!c1cs) {
        // 0x8004F388: nop
    
            goto L_8004F3B0;
    }
    // 0x8004F388: nop

    // 0x8004F38C: lwc1        $f8, 0x8C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8004F390: nop

    // 0x8004F394: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x8004F398: nop

    // 0x8004F39C: bc1f        L_8004F3B0
    if (!c1cs) {
        // 0x8004F3A0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8004F3B0;
    }
    // 0x8004F3A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8004F3A4:
    // 0x8004F3A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004F3A8: swc1        $f12, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f12.u32l;
    // 0x8004F3AC: swc1        $f6, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f6.u32l;
L_8004F3B0:
    // 0x8004F3B0: lh          $v1, 0x16A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X16A);
    // 0x8004F3B4: lh          $t5, 0x16C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X16C);
    // 0x8004F3B8: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F3BC: subu        $t3, $t5, $v1
    ctx->r11 = SUB32(ctx->r13, ctx->r3);
    // 0x8004F3C0: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004F3C4: mflo        $a2
    ctx->r6 = lo;
    // 0x8004F3C8: sra         $t6, $a2, 3
    ctx->r14 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8004F3CC: slti        $at, $t6, 0x801
    ctx->r1 = SIGNED(ctx->r14) < 0X801 ? 1 : 0;
    // 0x8004F3D0: bne         $at, $zero, L_8004F3DC
    if (ctx->r1 != 0) {
        // 0x8004F3D4: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_8004F3DC;
    }
    // 0x8004F3D4: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8004F3D8: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
L_8004F3DC:
    // 0x8004F3DC: slti        $at, $a2, -0x800
    ctx->r1 = SIGNED(ctx->r6) < -0X800 ? 1 : 0;
    // 0x8004F3E0: beq         $at, $zero, L_8004F3EC
    if (ctx->r1 == 0) {
        // 0x8004F3E4: nop
    
            goto L_8004F3EC;
    }
    // 0x8004F3E4: nop

    // 0x8004F3E8: addiu       $a2, $zero, -0x800
    ctx->r6 = ADD32(0, -0X800);
L_8004F3EC:
    // 0x8004F3EC: lh          $v0, -0x2F3C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2F3C);
    // 0x8004F3F0: nop

    // 0x8004F3F4: beq         $v0, $zero, L_8004F404
    if (ctx->r2 == 0) {
        // 0x8004F3F8: addu        $t7, $v1, $v0
        ctx->r15 = ADD32(ctx->r3, ctx->r2);
            goto L_8004F404;
    }
    // 0x8004F3F8: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x8004F3FC: b           L_8004F40C
    // 0x8004F400: sh          $t7, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r15;
        goto L_8004F40C;
    // 0x8004F400: sh          $t7, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r15;
L_8004F404:
    // 0x8004F404: addu        $t0, $v1, $a2
    ctx->r8 = ADD32(ctx->r3, ctx->r6);
    // 0x8004F408: sh          $t0, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r8;
L_8004F40C:
    // 0x8004F40C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004F410: lw          $v0, -0x2554($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2554);
    // 0x8004F414: nop

    // 0x8004F418: andi        $t9, $v0, 0x10
    ctx->r25 = ctx->r2 & 0X10;
    // 0x8004F41C: beq         $t9, $zero, L_8004F440
    if (ctx->r25 == 0) {
        // 0x8004F420: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8004F440;
    }
    // 0x8004F420: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8004F424: lb          $t8, 0x1EB($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1EB);
    // 0x8004F428: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8004F42C: beq         $t8, $zero, L_8004F440
    if (ctx->r24 == 0) {
        // 0x8004F430: nop
    
            goto L_8004F440;
    }
    // 0x8004F430: nop

    // 0x8004F434: sb          $t2, 0x1EC($s0)
    MEM_B(0X1EC, ctx->r16) = ctx->r10;
    // 0x8004F438: b           L_8004F44C
    // 0x8004F43C: sb          $zero, 0x1EB($s0)
    MEM_B(0X1EB, ctx->r16) = 0;
        goto L_8004F44C;
    // 0x8004F43C: sb          $zero, 0x1EB($s0)
    MEM_B(0X1EB, ctx->r16) = 0;
L_8004F440:
    // 0x8004F440: beq         $v0, $zero, L_8004F44C
    if (ctx->r2 == 0) {
        // 0x8004F444: addiu       $t1, $zero, 0x16
        ctx->r9 = ADD32(0, 0X16);
            goto L_8004F44C;
    }
    // 0x8004F444: addiu       $t1, $zero, 0x16
    ctx->r9 = ADD32(0, 0X16);
    // 0x8004F448: sb          $t1, 0x1EB($s0)
    MEM_B(0X1EB, ctx->r16) = ctx->r9;
L_8004F44C:
    // 0x8004F44C: lb          $v0, 0x1EB($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1EB);
    // 0x8004F450: nop

    // 0x8004F454: blez        $v0, L_8004F470
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004F458: nop
    
            goto L_8004F470;
    }
    // 0x8004F458: nop

    // 0x8004F45C: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F460: nop

    // 0x8004F464: subu        $t3, $v0, $t5
    ctx->r11 = SUB32(ctx->r2, ctx->r13);
    // 0x8004F468: b           L_8004F474
    // 0x8004F46C: sb          $t3, 0x1EB($s0)
    MEM_B(0X1EB, ctx->r16) = ctx->r11;
        goto L_8004F474;
    // 0x8004F46C: sb          $t3, 0x1EB($s0)
    MEM_B(0X1EB, ctx->r16) = ctx->r11;
L_8004F470:
    // 0x8004F470: sb          $zero, 0x1EB($s0)
    MEM_B(0X1EB, ctx->r16) = 0;
L_8004F474:
    // 0x8004F474: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8004F478: nop

    // 0x8004F47C: blez        $v0, L_8004F538
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004F480: slti        $at, $v0, 0x3D
        ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
            goto L_8004F538;
    }
    // 0x8004F480: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x8004F484: bne         $at, $zero, L_8004F4F4
    if (ctx->r1 != 0) {
        // 0x8004F488: nop
    
            goto L_8004F4F4;
    }
    // 0x8004F488: nop

    // 0x8004F48C: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    // 0x8004F490: nop

    // 0x8004F494: beq         $a0, $zero, L_8004F4BC
    if (ctx->r4 == 0) {
        // 0x8004F498: nop
    
            goto L_8004F4BC;
    }
    // 0x8004F498: nop

    // 0x8004F49C: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004F4A0: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004F4A4: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004F4A8: jal         0x800096D8
    // 0x8004F4AC: nop

    audspat_point_set_position(rdram, ctx);
        goto after_66;
    // 0x8004F4AC: nop

    after_66:
    // 0x8004F4B0: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8004F4B4: b           L_8004F518
    // 0x8004F4B8: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
        goto L_8004F518;
    // 0x8004F4B8: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
L_8004F4BC:
    // 0x8004F4BC: lw          $t4, 0x118($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X118);
    // 0x8004F4C0: addiu       $a0, $zero, 0x9F
    ctx->r4 = ADD32(0, 0X9F);
    // 0x8004F4C4: beq         $t4, $zero, L_8004F514
    if (ctx->r12 == 0) {
        // 0x8004F4C8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8004F514;
    }
    // 0x8004F4C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004F4CC: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004F4D0: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004F4D4: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004F4D8: addiu       $t7, $s0, 0x17C
    ctx->r15 = ADD32(ctx->r16, 0X17C);
    // 0x8004F4DC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8004F4E0: jal         0x80009558
    // 0x8004F4E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_67;
    // 0x8004F4E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_67:
    // 0x8004F4E8: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8004F4EC: b           L_8004F518
    // 0x8004F4F0: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
        goto L_8004F518;
    // 0x8004F4F0: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
L_8004F4F4:
    // 0x8004F4F4: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    // 0x8004F4F8: nop

    // 0x8004F4FC: beq         $a0, $zero, L_8004F518
    if (ctx->r4 == 0) {
        // 0x8004F500: lw          $t0, 0xB4($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XB4);
            goto L_8004F518;
    }
    // 0x8004F500: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F504: jal         0x800096F8
    // 0x8004F508: nop

    audspat_point_stop(rdram, ctx);
        goto after_68;
    // 0x8004F508: nop

    after_68:
    // 0x8004F50C: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8004F510: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_8004F514:
    // 0x8004F514: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
L_8004F518:
    // 0x8004F518: nop

    // 0x8004F51C: subu        $t9, $v0, $t0
    ctx->r25 = SUB32(ctx->r2, ctx->r8);
    // 0x8004F520: sh          $t9, 0x18E($s0)
    MEM_H(0X18E, ctx->r16) = ctx->r25;
    // 0x8004F524: lh          $t8, 0x18E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X18E);
    // 0x8004F528: nop

    // 0x8004F52C: bgtz        $t8, L_8004F538
    if (SIGNED(ctx->r24) > 0) {
        // 0x8004F530: nop
    
            goto L_8004F538;
    }
    // 0x8004F530: nop

    // 0x8004F534: sb          $zero, 0x189($s0)
    MEM_B(0X189, ctx->r16) = 0;
L_8004F538:
    // 0x8004F538: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    // 0x8004F53C: nop

    // 0x8004F540: beq         $a0, $zero, L_8004F55C
    if (ctx->r4 == 0) {
        // 0x8004F544: nop
    
            goto L_8004F55C;
    }
    // 0x8004F544: nop

    // 0x8004F548: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004F54C: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004F550: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004F554: jal         0x800096D8
    // 0x8004F558: nop

    audspat_point_set_position(rdram, ctx);
        goto after_69;
    // 0x8004F558: nop

    after_69:
L_8004F55C:
    // 0x8004F55C: jal         0x8000E4D8
    // 0x8004F560: nop

    is_in_time_trial(rdram, ctx);
        goto after_70;
    // 0x8004F560: nop

    after_70:
    // 0x8004F564: beq         $v0, $zero, L_8004F594
    if (ctx->r2 == 0) {
        // 0x8004F568: nop
    
            goto L_8004F594;
    }
    // 0x8004F568: nop

    // 0x8004F56C: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x8004F570: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004F574: bne         $t2, $zero, L_8004F594
    if (ctx->r10 != 0) {
        // 0x8004F578: nop
    
            goto L_8004F594;
    }
    // 0x8004F578: nop

    // 0x8004F57C: lw          $t1, -0x2540($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2540);
    // 0x8004F580: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F584: bne         $t1, $zero, L_8004F594
    if (ctx->r9 != 0) {
        // 0x8004F588: nop
    
            goto L_8004F594;
    }
    // 0x8004F588: nop

    // 0x8004F58C: jal         0x80059C40
    // 0x8004F590: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    timetrial_ghost_write(rdram, ctx);
        goto after_71;
    // 0x8004F590: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_71:
L_8004F594:
    // 0x8004F594: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x8004F598: nop

    // 0x8004F59C: beq         $a0, $zero, L_8004F5B8
    if (ctx->r4 == 0) {
        // 0x8004F5A0: nop
    
            goto L_8004F5B8;
    }
    // 0x8004F5A0: nop

    // 0x8004F5A4: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004F5A8: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004F5AC: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004F5B0: jal         0x800096D8
    // 0x8004F5B4: nop

    audspat_point_set_position(rdram, ctx);
        goto after_72;
    // 0x8004F5B4: nop

    after_72:
L_8004F5B8:
    // 0x8004F5B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004F5BC: sb          $zero, -0x24FC($at)
    MEM_B(-0X24FC, ctx->r1) = 0;
    // 0x8004F5C0: lw          $v0, 0x150($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X150);
    // 0x8004F5C4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004F5C8: beq         $v0, $zero, L_8004F6C0
    if (ctx->r2 == 0) {
        // 0x8004F5CC: nop
    
            goto L_8004F6C0;
    }
    // 0x8004F5CC: nop

    // 0x8004F5D0: lw          $t5, -0x2540($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2540);
    // 0x8004F5D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004F5D8: bne         $t5, $zero, L_8004F6C4
    if (ctx->r13 != 0) {
        // 0x8004F5DC: addiu       $t5, $zero, 0xFF
        ctx->r13 = ADD32(0, 0XFF);
            goto L_8004F6C4;
    }
    // 0x8004F5DC: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8004F5E0: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004F5E4: jal         0x8001E2D0
    // 0x8004F5E8: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    get_misc_asset(rdram, ctx);
        goto after_73;
    // 0x8004F5E8: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    after_73:
    // 0x8004F5EC: lb          $t3, 0x3($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X3);
    // 0x8004F5F0: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004F5F4: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8004F5F8: lb          $t6, 0x0($t4)
    ctx->r14 = MEM_B(ctx->r12, 0X0);
    // 0x8004F5FC: lw          $t7, 0x150($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X150);
    // 0x8004F600: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8004F604: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004F608: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004F60C: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8004F610: swc1        $f4, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f4.u32l;
    // 0x8004F614: lw          $t0, 0x150($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X150);
    // 0x8004F618: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004F61C: nop

    // 0x8004F620: swc1        $f10, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f10.u32l;
    // 0x8004F624: lwc1        $f8, 0x30($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X30);
    // 0x8004F628: lwc1        $f6, 0x6B84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6B84);
    // 0x8004F62C: lw          $t9, 0x150($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X150);
    // 0x8004F630: div.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8004F634: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004F638: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
    // 0x8004F63C: lwc1        $f10, 0x30($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X30);
    // 0x8004F640: lwc1        $f6, 0x6B8C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6B8C);
    // 0x8004F644: lwc1        $f7, 0x6B88($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6B88);
    // 0x8004F648: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8004F64C: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8004F650: nop

    // 0x8004F654: bc1t        L_8004F670
    if (c1cs) {
        // 0x8004F658: nop
    
            goto L_8004F670;
    }
    // 0x8004F658: nop

    // 0x8004F65C: jal         0x8009C850
    // 0x8004F660: nop

    get_filtered_cheats(rdram, ctx);
        goto after_74;
    // 0x8004F660: nop

    after_74:
    // 0x8004F664: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x8004F668: beq         $t8, $zero, L_8004F688
    if (ctx->r24 == 0) {
        // 0x8004F66C: nop
    
            goto L_8004F688;
    }
    // 0x8004F66C: nop

L_8004F670:
    // 0x8004F670: lw          $v0, 0x150($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X150);
    // 0x8004F674: nop

    // 0x8004F678: lh          $t2, 0x6($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X6);
    // 0x8004F67C: nop

    // 0x8004F680: ori         $t1, $t2, 0x4000
    ctx->r9 = ctx->r10 | 0X4000;
    // 0x8004F684: sh          $t1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r9;
L_8004F688:
    // 0x8004F688: lw          $v0, 0x150($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X150);
    // 0x8004F68C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004F690: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004F694: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004F698: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004F69C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8004F6A0: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x8004F6A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004F6A8: bc1f        L_8004F6BC
    if (!c1cs) {
        // 0x8004F6AC: nop
    
            goto L_8004F6BC;
    }
    // 0x8004F6AC: nop

    // 0x8004F6B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004F6B4: nop

    // 0x8004F6B8: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
L_8004F6BC:
    // 0x8004F6BC: sw          $zero, 0x150($s0)
    MEM_W(0X150, ctx->r16) = 0;
L_8004F6C0:
    // 0x8004F6C0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
L_8004F6C4:
    // 0x8004F6C4: sb          $t5, 0x1FE($s0)
    MEM_B(0X1FE, ctx->r16) = ctx->r13;
    // 0x8004F6C8: jal         0x8004F7BC
    // 0x8004F6CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_racer_tail_lights(rdram, ctx);
        goto after_75;
    // 0x8004F6CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_75:
    // 0x8004F6D0: lhu         $t3, 0x20E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X20E);
    // 0x8004F6D4: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F6D8: beq         $t3, $zero, L_8004F754
    if (ctx->r11 == 0) {
        // 0x8004F6DC: lw          $t9, 0x7C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X7C);
            goto L_8004F754;
    }
    // 0x8004F6DC: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x8004F6E0: lbu         $v0, 0x210($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X210);
    // 0x8004F6E4: nop

    // 0x8004F6E8: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004F6EC: beq         $at, $zero, L_8004F6FC
    if (ctx->r1 == 0) {
        // 0x8004F6F0: subu        $t6, $v0, $t4
        ctx->r14 = SUB32(ctx->r2, ctx->r12);
            goto L_8004F6FC;
    }
    // 0x8004F6F0: subu        $t6, $v0, $t4
    ctx->r14 = SUB32(ctx->r2, ctx->r12);
    // 0x8004F6F4: b           L_8004F750
    // 0x8004F6F8: sb          $t6, 0x210($s0)
    MEM_B(0X210, ctx->r16) = ctx->r14;
        goto L_8004F750;
    // 0x8004F6F8: sb          $t6, 0x210($s0)
    MEM_B(0X210, ctx->r16) = ctx->r14;
L_8004F6FC:
    // 0x8004F6FC: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8004F700: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004F704: bne         $t7, $at, L_8004F734
    if (ctx->r15 != ctx->r1) {
        // 0x8004F708: sb          $zero, 0x210($s0)
        MEM_B(0X210, ctx->r16) = 0;
            goto L_8004F734;
    }
    // 0x8004F708: sb          $zero, 0x210($s0)
    MEM_B(0X210, ctx->r16) = 0;
    // 0x8004F70C: lhu         $a0, 0x20E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X20E);
    // 0x8004F710: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004F714: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004F718: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004F71C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8004F720: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8004F724: jal         0x80009558
    // 0x8004F728: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_76;
    // 0x8004F728: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_76:
    // 0x8004F72C: b           L_8004F750
    // 0x8004F730: sh          $zero, 0x20E($s0)
    MEM_H(0X20E, ctx->r16) = 0;
        goto L_8004F750;
    // 0x8004F730: sh          $zero, 0x20E($s0)
    MEM_H(0X20E, ctx->r16) = 0;
L_8004F734:
    // 0x8004F734: lhu         $a0, 0x20E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X20E);
    // 0x8004F738: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004F73C: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004F740: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004F744: jal         0x80001EA8
    // 0x8004F748: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_77;
    // 0x8004F748: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_77:
    // 0x8004F74C: sh          $zero, 0x20E($s0)
    MEM_H(0X20E, ctx->r16) = 0;
L_8004F750:
    // 0x8004F750: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
L_8004F754:
    // 0x8004F754: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8004F758: lb          $v0, 0x4C($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X4C);
    // 0x8004F75C: nop

    // 0x8004F760: andi        $t8, $v0, 0x40
    ctx->r24 = ctx->r2 & 0X40;
    // 0x8004F764: beq         $t8, $zero, L_8004F788
    if (ctx->r24 == 0) {
        // 0x8004F768: nop
    
            goto L_8004F788;
    }
    // 0x8004F768: nop

    // 0x8004F76C: beq         $v0, $at, L_8004F788
    if (ctx->r2 == ctx->r1) {
        // 0x8004F770: nop
    
            goto L_8004F788;
    }
    // 0x8004F770: nop

    // 0x8004F774: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004F778: jal         0x8001C44C
    // 0x8004F77C: nop

    obj_elevation(rdram, ctx);
        goto after_78;
    // 0x8004F77C: nop

    after_78:
    // 0x8004F780: b           L_8004F78C
    // 0x8004F784: sb          $v0, 0x212($s0)
    MEM_B(0X212, ctx->r16) = ctx->r2;
        goto L_8004F78C;
    // 0x8004F784: sb          $v0, 0x212($s0)
    MEM_B(0X212, ctx->r16) = ctx->r2;
L_8004F788:
    // 0x8004F788: sb          $zero, 0x212($s0)
    MEM_B(0X212, ctx->r16) = 0;
L_8004F78C:
    // 0x8004F78C: lb          $v0, 0x193($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X193);
    // 0x8004F790: lb          $t2, 0x194($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X194);
    // 0x8004F794: nop

    // 0x8004F798: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004F79C: beq         $at, $zero, L_8004F7AC
    if (ctx->r1 == 0) {
        // 0x8004F7A0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8004F7AC;
    }
    // 0x8004F7A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004F7A4: sb          $v0, 0x194($s0)
    MEM_B(0X194, ctx->r16) = ctx->r2;
    // 0x8004F7A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8004F7AC:
    // 0x8004F7AC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8004F7B0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8004F7B4: jr          $ra
    // 0x8004F7B8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8004F7B8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void align_text_in_box(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5A48: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C5A4C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5A50: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C5A54: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5A58: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C5A5C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800C5A60: beq         $a1, $zero, L_800C5B4C
    if (ctx->r5 == 0) {
        // 0x800C5A64: addu        $v0, $t6, $t7
        ctx->r2 = ADD32(ctx->r14, ctx->r15);
            goto L_800C5B4C;
    }
    // 0x800C5A64: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5A68: lbu         $v1, 0x19($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X19);
    // 0x800C5A6C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C5A70: beq         $v1, $at, L_800C5B4C
    if (ctx->r3 == ctx->r1) {
        // 0x800C5A74: sll         $t8, $v1, 10
        ctx->r24 = S32(ctx->r3 << 10);
            goto L_800C5B4C;
    }
    // 0x800C5A74: sll         $t8, $v1, 10
    ctx->r24 = S32(ctx->r3 << 10);
    // 0x800C5A78: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C5A7C: lw          $a2, 0x10($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X10);
    // 0x800C5A80: lw          $t9, -0x525C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X525C);
    // 0x800C5A84: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800C5A88: beq         $a2, $at, L_800C5B44
    if (ctx->r6 == ctx->r1) {
        // 0x800C5A8C: addu        $a0, $t8, $t9
        ctx->r4 = ADD32(ctx->r24, ctx->r25);
            goto L_800C5B44;
    }
    // 0x800C5A8C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800C5A90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C5A94: beq         $a2, $at, L_800C5AAC
    if (ctx->r6 == ctx->r1) {
        // 0x800C5A98: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C5AAC;
    }
    // 0x800C5A98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C5A9C: beq         $a2, $at, L_800C5AC4
    if (ctx->r6 == ctx->r1) {
        // 0x800C5AA0: nop
    
            goto L_800C5AC4;
    }
    // 0x800C5AA0: nop

    // 0x800C5AA4: b           L_800C5B28
    // 0x800C5AA8: lh          $t4, 0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XC);
        goto L_800C5B28;
    // 0x800C5AA8: lh          $t4, 0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XC);
L_800C5AAC:
    // 0x800C5AAC: lhu         $t0, 0x22($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X22);
    // 0x800C5AB0: nop

    // 0x800C5AB4: multu       $a3, $t0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5AB8: mflo        $a3
    ctx->r7 = lo;
    // 0x800C5ABC: b           L_800C5B28
    // 0x800C5AC0: lh          $t4, 0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XC);
        goto L_800C5B28;
    // 0x800C5AC0: lh          $t4, 0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XC);
L_800C5AC4:
    // 0x800C5AC4: lhu         $v1, 0x22($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X22);
    // 0x800C5AC8: lh          $t1, 0xE($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XE);
    // 0x800C5ACC: nop

    // 0x800C5AD0: div         $zero, $t1, $v1
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r3)));
    // 0x800C5AD4: bne         $v1, $zero, L_800C5AE0
    if (ctx->r3 != 0) {
        // 0x800C5AD8: nop
    
            goto L_800C5AE0;
    }
    // 0x800C5AD8: nop

    // 0x800C5ADC: break       7
    do_break(2148293340);
L_800C5AE0:
    // 0x800C5AE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5AE4: bne         $v1, $at, L_800C5AF8
    if (ctx->r3 != ctx->r1) {
        // 0x800C5AE8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5AF8;
    }
    // 0x800C5AE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5AEC: bne         $t1, $at, L_800C5AF8
    if (ctx->r9 != ctx->r1) {
        // 0x800C5AF0: nop
    
            goto L_800C5AF8;
    }
    // 0x800C5AF0: nop

    // 0x800C5AF4: break       6
    do_break(2148293364);
L_800C5AF8:
    // 0x800C5AF8: mflo        $t2
    ctx->r10 = lo;
    // 0x800C5AFC: nop

    // 0x800C5B00: nop

    // 0x800C5B04: multu       $a3, $t2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5B08: mflo        $t3
    ctx->r11 = lo;
    // 0x800C5B0C: nop

    // 0x800C5B10: nop

    // 0x800C5B14: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5B18: mflo        $a3
    ctx->r7 = lo;
    // 0x800C5B1C: nop

    // 0x800C5B20: nop

    // 0x800C5B24: lh          $t4, 0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XC);
L_800C5B28:
    // 0x800C5B28: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800C5B2C: lh          $t7, 0xE($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XE);
    // 0x800C5B30: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800C5B34: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x800C5B38: sh          $t6, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r14;
    // 0x800C5B3C: jr          $ra
    // 0x800C5B40: sh          $t8, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r24;
    return;
    // 0x800C5B40: sh          $t8, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r24;
L_800C5B44:
    // 0x800C5B44: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x800C5B48: sh          $zero, 0xE($a1)
    MEM_H(0XE, ctx->r5) = 0;
L_800C5B4C:
    // 0x800C5B4C: jr          $ra
    // 0x800C5B50: nop

    return;
    // 0x800C5B50: nop

;}
RECOMP_FUNC void create_line_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B110C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B1110: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B1114: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B1118: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x800B111C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B1120: lw          $t6, 0x3280($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3280);
    // 0x800B1124: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B1128: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B112C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B1130: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B1134: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x800B1138: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B113C: beq         $t2, $at, L_800B114C
    if (ctx->r10 == ctx->r1) {
        // 0x800B1140: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800B114C;
    }
    // 0x800B1140: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800B1144: b           L_800B1680
    // 0x800B1148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B1680;
    // 0x800B1148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B114C:
    // 0x800B114C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800B1150: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800B1154: lw          $t1, 0x9C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X9C);
    // 0x800B1158: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800B115C: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x800B1160: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x800B1164: jal         0x800B2218
    // 0x800B1168: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    particle_allocate(rdram, ctx);
        goto after_0;
    // 0x800B1168: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_0:
    // 0x800B116C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800B1170: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1174: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800B1178: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B117C: bne         $v0, $zero, L_800B118C
    if (ctx->r2 != 0) {
        // 0x800B1180: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800B118C;
    }
    // 0x800B1180: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B1184: b           L_800B1680
    // 0x800B1188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B1680;
    // 0x800B1188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B118C:
    // 0x800B118C: lh          $t3, 0x2E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2E);
    // 0x800B1190: addiu       $t4, $zero, -0x8000
    ctx->r12 = ADD32(0, -0X8000);
    // 0x800B1194: sh          $t4, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r12;
    // 0x800B1198: sh          $t3, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r11;
    // 0x800B119C: lbu         $t5, 0x1($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X1);
    // 0x800B11A0: nop

    // 0x800B11A4: sb          $t5, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r13;
    // 0x800B11A8: lhu         $t7, 0x2($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X2);
    // 0x800B11AC: sw          $s0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r16;
    // 0x800B11B0: sw          $a2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r6;
    // 0x800B11B4: sw          $t7, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r15;
    // 0x800B11B8: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800B11BC: lwc1        $f6, 0x50($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X50);
    // 0x800B11C0: nop

    // 0x800B11C4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B11C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B11CC: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800B11D0: lwc1        $f16, 0x54($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X54);
    // 0x800B11D4: lwc1        $f10, 0x10($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800B11D8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B11DC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B11E0: swc1        $f18, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f18.u32l;
    // 0x800B11E4: lh          $t6, 0x8($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X8);
    // 0x800B11E8: sb          $zero, 0x38($v0)
    MEM_B(0X38, ctx->r2) = 0;
    // 0x800B11EC: swc1        $f4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f4.u32l;
    // 0x800B11F0: sh          $t6, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r14;
    // 0x800B11F4: lw          $v1, 0x3290($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3290);
    // 0x800B11F8: nop

    // 0x800B11FC: beq         $v1, $zero, L_800B120C
    if (ctx->r3 == 0) {
        // 0x800B1200: nop
    
            goto L_800B120C;
    }
    // 0x800B1200: nop

    // 0x800B1204: b           L_800B1230
    // 0x800B1208: sw          $v1, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r3;
        goto L_800B1230;
    // 0x800B1208: sw          $v1, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r3;
L_800B120C:
    // 0x800B120C: lbu         $t8, 0x14($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X14);
    // 0x800B1210: nop

    // 0x800B1214: sb          $t8, 0x6C($v0)
    MEM_B(0X6C, ctx->r2) = ctx->r24;
    // 0x800B1218: lbu         $t9, 0x15($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X15);
    // 0x800B121C: nop

    // 0x800B1220: sb          $t9, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r25;
    // 0x800B1224: lbu         $t2, 0x16($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X16);
    // 0x800B1228: nop

    // 0x800B122C: sb          $t2, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r10;
L_800B1230:
    // 0x800B1230: lw          $t4, 0x40($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X40);
    // 0x800B1234: lbu         $t3, 0x17($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X17);
    // 0x800B1238: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x800B123C: beq         $t5, $zero, L_800B1290
    if (ctx->r13 == 0) {
        // 0x800B1240: sb          $t3, 0x6F($v0)
        MEM_B(0X6F, ctx->r2) = ctx->r11;
            goto L_800B1290;
    }
    // 0x800B1240: sb          $t3, 0x6F($v0)
    MEM_B(0X6F, ctx->r2) = ctx->r11;
    // 0x800B1244: lw          $v1, 0x54($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X54);
    // 0x800B1248: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800B124C: beq         $v1, $zero, L_800B1290
    if (ctx->r3 == 0) {
        // 0x800B1250: nop
    
            goto L_800B1290;
    }
    // 0x800B1250: nop

    // 0x800B1254: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B1258: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B125C: nop

    // 0x800B1260: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B1264: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B1268: nop

    // 0x800B126C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800B1270: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B1274: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B1278: nop

    // 0x800B127C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B1280: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800B1284: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B1288: b           L_800B1298
    // 0x800B128C: sh          $t6, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r14;
        goto L_800B1298;
    // 0x800B128C: sh          $t6, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r14;
L_800B1290:
    // 0x800B1290: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800B1294: sh          $t8, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r24;
L_800B1298:
    // 0x800B1298: lh          $t9, 0xE($t0)
    ctx->r25 = MEM_H(ctx->r8, 0XE);
    // 0x800B129C: nop

    // 0x800B12A0: sh          $t9, 0x60($v0)
    MEM_H(0X60, ctx->r2) = ctx->r25;
    // 0x800B12A4: lbu         $t2, 0xC($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0XC);
    // 0x800B12A8: nop

    // 0x800B12AC: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x800B12B0: sh          $t3, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r11;
    // 0x800B12B4: lbu         $t4, 0xC($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XC);
    // 0x800B12B8: nop

    // 0x800B12BC: slti        $at, $t4, 0xFF
    ctx->r1 = SIGNED(ctx->r12) < 0XFF ? 1 : 0;
    // 0x800B12C0: beq         $at, $zero, L_800B1300
    if (ctx->r1 == 0) {
        // 0x800B12C4: nop
    
            goto L_800B1300;
    }
    // 0x800B12C4: nop

    // 0x800B12C8: lw          $t5, 0x40($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X40);
    // 0x800B12CC: nop

    // 0x800B12D0: andi        $t7, $t5, 0x1000
    ctx->r15 = ctx->r13 & 0X1000;
    // 0x800B12D4: beq         $t7, $zero, L_800B12F0
    if (ctx->r15 == 0) {
        // 0x800B12D8: nop
    
            goto L_800B12F0;
    }
    // 0x800B12D8: nop

    // 0x800B12DC: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x800B12E0: nop

    // 0x800B12E4: ori         $t8, $t6, 0x100
    ctx->r24 = ctx->r14 | 0X100;
    // 0x800B12E8: b           L_800B1300
    // 0x800B12EC: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
        goto L_800B1300;
    // 0x800B12EC: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
L_800B12F0:
    // 0x800B12F0: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x800B12F4: nop

    // 0x800B12F8: ori         $t2, $t9, 0x80
    ctx->r10 = ctx->r25 | 0X80;
    // 0x800B12FC: sh          $t2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r10;
L_800B1300:
    // 0x800B1300: lh          $a0, 0x60($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X60);
    // 0x800B1304: lh          $v1, 0x3A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X3A);
    // 0x800B1308: nop

    // 0x800B130C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B1310: beq         $at, $zero, L_800B1364
    if (ctx->r1 == 0) {
        // 0x800B1314: nop
    
            goto L_800B1364;
    }
    // 0x800B1314: nop

    // 0x800B1318: lbu         $t3, 0xD($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XD);
    // 0x800B131C: lbu         $t4, 0xC($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XC);
    // 0x800B1320: subu        $t6, $v1, $a0
    ctx->r14 = SUB32(ctx->r3, ctx->r4);
    // 0x800B1324: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800B1328: sll         $t7, $t5, 8
    ctx->r15 = S32(ctx->r13 << 8);
    // 0x800B132C: div         $zero, $t7, $t6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r14)));
    // 0x800B1330: bne         $t6, $zero, L_800B133C
    if (ctx->r14 != 0) {
        // 0x800B1334: nop
    
            goto L_800B133C;
    }
    // 0x800B1334: nop

    // 0x800B1338: break       7
    do_break(2148209464);
L_800B133C:
    // 0x800B133C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B1340: bne         $t6, $at, L_800B1354
    if (ctx->r14 != ctx->r1) {
        // 0x800B1344: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B1354;
    }
    // 0x800B1344: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1348: bne         $t7, $at, L_800B1354
    if (ctx->r15 != ctx->r1) {
        // 0x800B134C: nop
    
            goto L_800B1354;
    }
    // 0x800B134C: nop

    // 0x800B1350: break       6
    do_break(2148209488);
L_800B1354:
    // 0x800B1354: mflo        $t8
    ctx->r24 = lo;
    // 0x800B1358: sh          $t8, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = ctx->r24;
    // 0x800B135C: b           L_800B136C
    // 0x800B1360: lh          $t9, 0x18($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X18);
        goto L_800B136C;
    // 0x800B1360: lh          $t9, 0x18($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X18);
L_800B1364:
    // 0x800B1364: sh          $zero, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = 0;
    // 0x800B1368: lh          $t9, 0x18($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X18);
L_800B136C:
    // 0x800B136C: lh          $t2, 0x1A($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X1A);
    // 0x800B1370: lh          $t3, 0x1C($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X1C);
    // 0x800B1374: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800B1378: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800B137C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800B1380: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B1384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B1388: addiu       $a1, $a2, 0xC
    ctx->r5 = ADD32(ctx->r6, 0XC);
    // 0x800B138C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B1390: swc1        $f4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f4.u32l;
    // 0x800B1394: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B1398: swc1        $f8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f8.u32l;
    // 0x800B139C: swc1        $f16, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f16.u32l;
    // 0x800B13A0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800B13A4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800B13A8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800B13AC: jal         0x80070560
    // 0x800B13B0: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    vec3f_rotate(rdram, ctx);
        goto after_1;
    // 0x800B13B0: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_1:
    // 0x800B13B4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800B13B8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B13BC: lwc1        $f18, 0xC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800B13C0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B13C4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B13C8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800B13CC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B13D0: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x800B13D4: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B13D8: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800B13DC: lwc1        $f18, 0x14($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800B13E0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B13E4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B13E8: swc1        $f16, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f16.u32l;
    // 0x800B13EC: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B13F0: nop

    // 0x800B13F4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B13F8: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    // 0x800B13FC: sb          $zero, 0x68($a3)
    MEM_B(0X68, ctx->r7) = 0;
    // 0x800B1400: sb          $zero, 0x6A($a3)
    MEM_B(0X6A, ctx->r7) = 0;
    // 0x800B1404: sb          $v0, 0x6B($a3)
    MEM_B(0X6B, ctx->r7) = ctx->r2;
    // 0x800B1408: lh          $t4, 0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X6);
    // 0x800B140C: sh          $zero, 0x18($a3)
    MEM_H(0X18, ctx->r7) = 0;
    // 0x800B1410: sh          $t4, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r12;
    // 0x800B1414: lh          $a0, 0x4($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X4);
    // 0x800B1418: lw          $v1, 0x44($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X44);
    // 0x800B141C: bne         $v0, $a0, L_800B142C
    if (ctx->r2 != ctx->r4) {
        // 0x800B1420: nop
    
            goto L_800B142C;
    }
    // 0x800B1420: nop

    // 0x800B1424: b           L_800B14D8
    // 0x800B1428: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800B14D8;
    // 0x800B1428: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800B142C:
    // 0x800B142C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B1430: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x800B1434: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800B1438: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800B143C: jal         0x8007B2C4
    // 0x800B1440: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    load_texture(rdram, ctx);
        goto after_2;
    // 0x800B1440: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_2:
    // 0x800B1444: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B1448: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800B144C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B1450: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800B1454: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B1458: beq         $v0, $zero, L_800B14D8
    if (ctx->r2 == 0) {
        // 0x800B145C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800B14D8;
    }
    // 0x800B145C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B1460: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x800B1464: nop

    // 0x800B1468: andi        $t6, $t7, 0x4
    ctx->r14 = ctx->r15 & 0X4;
    // 0x800B146C: beq         $t6, $zero, L_800B14AC
    if (ctx->r14 == 0) {
        // 0x800B1470: nop
    
            goto L_800B14AC;
    }
    // 0x800B1470: nop

    // 0x800B1474: lw          $t8, 0x40($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X40);
    // 0x800B1478: nop

    // 0x800B147C: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x800B1480: beq         $t9, $zero, L_800B149C
    if (ctx->r25 == 0) {
        // 0x800B1484: nop
    
            goto L_800B149C;
    }
    // 0x800B1484: nop

    // 0x800B1488: lh          $t2, 0x6($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X6);
    // 0x800B148C: nop

    // 0x800B1490: ori         $t3, $t2, 0x100
    ctx->r11 = ctx->r10 | 0X100;
    // 0x800B1494: b           L_800B14AC
    // 0x800B1498: sh          $t3, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r11;
        goto L_800B14AC;
    // 0x800B1498: sh          $t3, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r11;
L_800B149C:
    // 0x800B149C: lh          $t4, 0x6($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X6);
    // 0x800B14A0: nop

    // 0x800B14A4: ori         $t5, $t4, 0x80
    ctx->r13 = ctx->r12 | 0X80;
    // 0x800B14A8: sh          $t5, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r13;
L_800B14AC:
    // 0x800B14AC: lw          $t7, 0x40($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X40);
    // 0x800B14B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B14B4: andi        $t6, $t7, 0x3
    ctx->r14 = ctx->r15 & 0X3;
    // 0x800B14B8: bne         $t6, $at, L_800B14D8
    if (ctx->r14 != ctx->r1) {
        // 0x800B14BC: nop
    
            goto L_800B14D8;
    }
    // 0x800B14BC: nop

    // 0x800B14C0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800B14C4: nop

    // 0x800B14C8: lhu         $t9, 0x12($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X12);
    // 0x800B14CC: nop

    // 0x800B14D0: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x800B14D4: sh          $t2, 0x18($a3)
    MEM_H(0X18, ctx->r7) = ctx->r10;
L_800B14D8:
    // 0x800B14D8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800B14DC: lwc1        $f8, 0xC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800B14E0: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800B14E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B14E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B14EC: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800B14F0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B14F4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800B14F8: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800B14FC: nop

    // 0x800B1500: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B1504: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x800B1508: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800B150C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B1510: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B1514: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800B1518: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B151C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B1520: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B1524: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800B1528: nop

    // 0x800B152C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B1530: sh          $t6, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r14;
    // 0x800B1534: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B1538: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B153C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B1540: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800B1544: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B1548: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B154C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B1550: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800B1554: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B1558: beq         $t1, $at, L_800B15F4
    if (ctx->r9 == ctx->r1) {
        // 0x800B155C: sh          $t2, 0x4($t3)
        MEM_H(0X4, ctx->r11) = ctx->r10;
            goto L_800B15F4;
    }
    // 0x800B155C: sh          $t2, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r10;
    // 0x800B1560: lh          $t4, 0x1E($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1564: nop

    // 0x800B1568: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B156C: sh          $t5, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r13;
    // 0x800B1570: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800B1574: lh          $v0, 0x1E($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1578: nop

    // 0x800B157C: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B1580: bne         $at, $zero, L_800B1598
    if (ctx->r1 != 0) {
        // 0x800B1584: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_800B1598;
    }
    // 0x800B1584: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800B1588: sh          $zero, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = 0;
    // 0x800B158C: lh          $v0, 0x1E($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1590: nop

    // 0x800B1594: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
L_800B1598:
    // 0x800B1598: addu        $t8, $t1, $t6
    ctx->r24 = ADD32(ctx->r9, ctx->r14);
    // 0x800B159C: lbu         $t9, 0x14($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X14);
    // 0x800B15A0: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B15A4: nop

    // 0x800B15A8: sb          $t9, 0x6($t2)
    MEM_B(0X6, ctx->r10) = ctx->r25;
    // 0x800B15AC: lh          $t3, 0x1E($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X1E);
    // 0x800B15B0: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x800B15B4: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800B15B8: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x800B15BC: lbu         $t7, 0x15($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X15);
    // 0x800B15C0: nop

    // 0x800B15C4: sb          $t7, 0x7($t6)
    MEM_B(0X7, ctx->r14) = ctx->r15;
    // 0x800B15C8: lh          $t8, 0x1E($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X1E);
    // 0x800B15CC: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800B15D0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800B15D4: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x800B15D8: lbu         $t3, 0x16($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X16);
    // 0x800B15DC: nop

    // 0x800B15E0: sb          $t3, 0x8($t4)
    MEM_B(0X8, ctx->r12) = ctx->r11;
    // 0x800B15E4: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B15E8: lbu         $t5, 0x6($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X6);
    // 0x800B15EC: b           L_800B1634
    // 0x800B15F0: sb          $t5, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r13;
        goto L_800B1634;
    // 0x800B15F0: sb          $t5, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r13;
L_800B15F4:
    // 0x800B15F4: lbu         $t6, 0x6C($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X6C);
    // 0x800B15F8: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B15FC: nop

    // 0x800B1600: sb          $t6, 0x6($t8)
    MEM_B(0X6, ctx->r24) = ctx->r14;
    // 0x800B1604: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B1608: lbu         $t9, 0x6D($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X6D);
    // 0x800B160C: nop

    // 0x800B1610: sb          $t9, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r25;
    // 0x800B1614: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800B1618: lbu         $t3, 0x6E($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X6E);
    // 0x800B161C: nop

    // 0x800B1620: sb          $t3, 0x8($t4)
    MEM_B(0X8, ctx->r12) = ctx->r11;
    // 0x800B1624: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B1628: lbu         $t5, 0x6($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X6);
    // 0x800B162C: nop

    // 0x800B1630: sb          $t5, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r13;
L_800B1634:
    // 0x800B1634: lhu         $t6, 0xA($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0XA);
    // 0x800B1638: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800B163C: srl         $t8, $t6, 10
    ctx->r24 = S32(U32(ctx->r14) >> 10);
    // 0x800B1640: sb          $t8, 0x6A($a3)
    MEM_B(0X6A, ctx->r7) = ctx->r24;
    // 0x800B1644: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x800B1648: nop

    // 0x800B164C: sll         $t2, $t9, 22
    ctx->r10 = S32(ctx->r25 << 22);
    // 0x800B1650: srl         $t3, $t2, 26
    ctx->r11 = S32(U32(ctx->r10) >> 26);
    // 0x800B1654: sb          $t3, 0x6B($a3)
    MEM_B(0X6B, ctx->r7) = ctx->r11;
    // 0x800B1658: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B165C: nop

    // 0x800B1660: swc1        $f8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f8.u32l;
    // 0x800B1664: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B1668: nop

    // 0x800B166C: swc1        $f10, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f10.u32l;
    // 0x800B1670: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B1674: nop

    // 0x800B1678: swc1        $f16, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f16.u32l;
    // 0x800B167C: sh          $zero, 0xA($a2)
    MEM_H(0XA, ctx->r6) = 0;
L_800B1680:
    // 0x800B1680: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1684: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B1688: jr          $ra
    // 0x800B168C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B168C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7AD0: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x800D7AD4: mflo        $v0
    ctx->r2 = lo;
    // 0x800D7AD8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800D7ADC: bne         $a2, $zero, L_800D7AE8
    if (ctx->r6 != 0) {
        // 0x800D7AE0: nop
    
            goto L_800D7AE8;
    }
    // 0x800D7AE0: nop

    // 0x800D7AE4: break       7
    do_break(2148367076);
L_800D7AE8:
    // 0x800D7AE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D7AEC: bne         $a2, $at, L_800D7B00
    if (ctx->r6 != ctx->r1) {
        // 0x800D7AF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D7B00;
    }
    // 0x800D7AF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D7AF4: bne         $a1, $at, L_800D7B00
    if (ctx->r5 != ctx->r1) {
        // 0x800D7AF8: nop
    
            goto L_800D7B00;
    }
    // 0x800D7AF8: nop

    // 0x800D7AFC: break       6
    do_break(2148367100);
L_800D7B00:
    // 0x800D7B00: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D7B04: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x800D7B08: addiu       $t7, $sp, 0x0
    ctx->r15 = ADD32(ctx->r29, 0X0);
    // 0x800D7B0C: mflo        $t6
    ctx->r14 = lo;
    // 0x800D7B10: subu        $v1, $a1, $t6
    ctx->r3 = SUB32(ctx->r5, ctx->r14);
    // 0x800D7B14: bgez        $v0, L_800D7B38
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D7B18: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_800D7B38;
    }
    // 0x800D7B18: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800D7B1C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x800D7B20: blez        $v1, L_800D7B38
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800D7B24: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_800D7B38;
    }
    // 0x800D7B24: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800D7B28: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D7B2C: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x800D7B30: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800D7B34: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_800D7B38:
    // 0x800D7B38: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800D7B3C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800D7B40: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x800D7B44: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800D7B48: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800D7B4C: jr          $ra
    // 0x800D7B50: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    return;
    // 0x800D7B50: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void mempool_free_addr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800714B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800714BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800714C0: jal         0x8007182C
    // 0x800714C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    mempool_get_pool(rdram, ctx);
        goto after_0;
    // 0x800714C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800714C8: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800714CC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800714D0: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x800714D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800714D8: lw          $v1, 0x3B08($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3B08);
    // 0x800714DC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800714E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800714E4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800714E8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
L_800714EC:
    // 0x800714EC: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800714F0: mflo        $t7
    ctx->r15 = lo;
    // 0x800714F4: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x800714F8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800714FC: nop

    // 0x80071500: bne         $a0, $t8, L_80071534
    if (ctx->r4 != ctx->r24) {
        // 0x80071504: nop
    
            goto L_80071534;
    }
    // 0x80071504: nop

    // 0x80071508: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
    // 0x8007150C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80071510: beq         $v1, $at, L_80071520
    if (ctx->r3 == ctx->r1) {
        // 0x80071514: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80071520;
    }
    // 0x80071514: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80071518: bne         $v1, $at, L_80071548
    if (ctx->r3 != ctx->r1) {
        // 0x8007151C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80071548;
    }
    // 0x8007151C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80071520:
    // 0x80071520: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80071524: jal         0x8007188C
    // 0x80071528: nop

    mempool_slot_clear(rdram, ctx);
        goto after_1;
    // 0x80071528: nop

    after_1:
    // 0x8007152C: b           L_80071548
    // 0x80071530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80071548;
    // 0x80071530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80071534:
    // 0x80071534: lh          $a1, 0xC($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XC);
    // 0x80071538: nop

    // 0x8007153C: bne         $a1, $a3, L_800714EC
    if (ctx->r5 != ctx->r7) {
        // 0x80071540: nop
    
            goto L_800714EC;
    }
    // 0x80071540: nop

    // 0x80071544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80071548:
    // 0x80071548: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007154C: jr          $ra
    // 0x80071550: nop

    return;
    // 0x80071550: nop

;}
RECOMP_FUNC void update_camera_fixed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058F84: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80058F88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80058F8C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80058F90: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80058F94: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80058F98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058F9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80058FA0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80058FA4: lw          $v1, -0x2578($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2578);
    // 0x80058FA8: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80058FAC: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80058FB0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80058FB4: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80058FB8: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80058FBC: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80058FC0: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80058FC4: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x80058FC8: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80058FCC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80058FD0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80058FD4: nop

    // 0x80058FD8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80058FDC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80058FE0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80058FE4: nop

    // 0x80058FE8: cvt.w.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80058FEC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80058FF0: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80058FF4: nop

    // 0x80058FF8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80058FFC: nop

    // 0x80059000: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80059004: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059008: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005900C: nop

    // 0x80059010: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80059014: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80059018: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8005901C: jal         0x800708AC
    // 0x80059020: nop

    atan2s(rdram, ctx);
        goto after_0;
    // 0x80059020: nop

    after_0:
    // 0x80059024: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80059028: addiu       $a3, $a3, -0x2578
    ctx->r7 = ADD32(ctx->r7, -0X2578);
    // 0x8005902C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80059030: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x80059034: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80059038: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8005903C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80059040: subu        $t1, $t9, $a0
    ctx->r9 = SUB32(ctx->r25, ctx->r4);
    // 0x80059044: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x80059048: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005904C: mflo        $t3
    ctx->r11 = lo;
    // 0x80059050: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x80059054: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x80059058: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
    // 0x8005905C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80059060: nop

    // 0x80059064: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x80059068: nop

    // 0x8005906C: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80059070: mflo        $t6
    ctx->r14 = lo;
    // 0x80059074: sra         $t7, $t6, 4
    ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
    // 0x80059078: subu        $t8, $a1, $t7
    ctx->r24 = SUB32(ctx->r5, ctx->r15);
    // 0x8005907C: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80059080: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80059084: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80059088: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8005908C: lw          $a2, 0x14($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X14);
    // 0x80059090: lwc1        $f14, 0x3C($t9)
    ctx->f14.u32l = MEM_W(ctx->r25, 0X3C);
    // 0x80059094: jal         0x80029F58
    // 0x80059098: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_1;
    // 0x80059098: nop

    after_1:
    // 0x8005909C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800590A0: addiu       $a3, $a3, -0x2578
    ctx->r7 = ADD32(ctx->r7, -0X2578);
    // 0x800590A4: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x800590A8: nop

    // 0x800590AC: sh          $v0, 0x34($t1)
    MEM_H(0X34, ctx->r9) = ctx->r2;
    // 0x800590B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800590B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800590B8: jr          $ra
    // 0x800590BC: nop

    return;
    // 0x800590BC: nop

;}
RECOMP_FUNC void obj_loop_weather(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040860: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80040864: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80040868: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8004086C: jal         0x80066460
    // 0x80040870: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    get_current_viewport(rdram, ctx);
        goto after_0;
    // 0x80040870: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80040874: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80040878: jal         0x8001BAA8
    // 0x8004087C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    get_racer_objects(rdram, ctx);
        goto after_1;
    // 0x8004087C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_1:
    // 0x80040880: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80040884: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80040888: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8004088C: beq         $a1, $zero, L_8004095C
    if (ctx->r5 == 0) {
        // 0x80040890: addiu       $a0, $a1, -0x1
        ctx->r4 = ADD32(ctx->r5, -0X1);
            goto L_8004095C;
    }
    // 0x80040890: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    // 0x80040894: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80040898: addu        $a3, $t6, $v0
    ctx->r7 = ADD32(ctx->r14, ctx->r2);
    // 0x8004089C: addiu       $v1, $v0, -0x4
    ctx->r3 = ADD32(ctx->r2, -0X4);
L_800408A0:
    // 0x800408A0: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x800408A4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800408A8: sltu        $at, $v1, $a3
    ctx->r1 = ctx->r3 < ctx->r7 ? 1 : 0;
    // 0x800408AC: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x800408B0: beq         $at, $zero, L_800408C8
    if (ctx->r1 == 0) {
        // 0x800408B4: nop
    
            goto L_800408C8;
    }
    // 0x800408B4: nop

    // 0x800408B8: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x800408BC: nop

    // 0x800408C0: bne         $a2, $t7, L_800408A0
    if (ctx->r6 != ctx->r15) {
        // 0x800408C4: nop
    
            goto L_800408A0;
    }
    // 0x800408C4: nop

L_800408C8:
    // 0x800408C8: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800408CC: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800408D0: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800408D4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800408D8: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800408DC: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800408E0: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800408E4: lwc1        $f12, 0x78($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X78);
    // 0x800408E8: lw          $v1, 0x3C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X3C);
    // 0x800408EC: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800408F0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800408F4: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x800408F8: nop

    // 0x800408FC: bc1f        L_80040960
    if (!c1cs) {
        // 0x80040900: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80040960;
    }
    // 0x80040900: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80040904: lbu         $t2, 0x10($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X10);
    // 0x80040908: addiu       $v0, $zero, 0x101
    ctx->r2 = ADD32(0, 0X101);
    // 0x8004090C: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040910: lbu         $t3, 0x11($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X11);
    // 0x80040914: lh          $a0, 0xA($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XA);
    // 0x80040918: lh          $a1, 0xC($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XC);
    // 0x8004091C: lh          $a2, 0xE($v1)
    ctx->r6 = MEM_H(ctx->r3, 0XE);
    // 0x80040920: sll         $t8, $a0, 8
    ctx->r24 = S32(ctx->r4 << 8);
    // 0x80040924: sll         $t9, $a1, 8
    ctx->r25 = S32(ctx->r5 << 8);
    // 0x80040928: sll         $t1, $a2, 8
    ctx->r9 = S32(ctx->r6 << 8);
    // 0x8004092C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80040930: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80040934: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80040938: mflo        $a3
    ctx->r7 = lo;
    // 0x8004093C: nop

    // 0x80040940: nop

    // 0x80040944: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040948: mflo        $t4
    ctx->r12 = lo;
    // 0x8004094C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80040950: lh          $t5, 0x12($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X12);
    // 0x80040954: jal         0x800AC1BC
    // 0x80040958: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    weather_set(rdram, ctx);
        goto after_2;
    // 0x80040958: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_2:
L_8004095C:
    // 0x8004095C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80040960:
    // 0x80040960: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80040964: jr          $ra
    // 0x80040968: nop

    return;
    // 0x80040968: nop

;}
RECOMP_FUNC void bgdraw_chequer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078C4C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80078C50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80078C54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80078C58: jal         0x8007A970
    // 0x80078C5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80078C5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80078C60: sra         $t6, $v0, 16
    ctx->r14 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80078C64: andi        $ra, $t6, 0xFFFF
    ctx->r31 = ctx->r14 & 0XFFFF;
    // 0x80078C68: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80078C6C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078C70: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80078C74: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078C78: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80078C7C: addiu       $t6, $t6, -0x14A0
    ctx->r14 = ADD32(ctx->r14, -0X14A0);
    // 0x80078C80: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80078C84: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078C88: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80078C8C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078C90: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80078C94: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078C98: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80078C9C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80078CA0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078CA4: lbu         $t6, 0x64D0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X64D0);
    // 0x80078CA8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80078CAC: lbu         $t9, 0x64D1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X64D1);
    // 0x80078CB0: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80078CB4: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80078CB8: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80078CBC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80078CC0: lbu         $t7, 0x64D2($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X64D2);
    // 0x80078CC4: andi        $t5, $v0, 0xFFFF
    ctx->r13 = ctx->r2 & 0XFFFF;
    // 0x80078CC8: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x80078CCC: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80078CD0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80078CD4: lbu         $t8, 0x64D3($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X64D3);
    // 0x80078CD8: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x80078CDC: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80078CE0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80078CE4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80078CE8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80078CEC: blez        $t7, L_80078DB8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80078CF0: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_80078DB8;
    }
    // 0x80078CF0: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80078CF4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80078CF8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80078CFC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80078D00: lw          $a2, 0x64D8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X64D8);
    // 0x80078D04: addiu       $a3, $a3, 0x64D8
    ctx->r7 = ADD32(ctx->r7, 0X64D8);
    // 0x80078D08: addiu       $t1, $t1, 0x64DC
    ctx->r9 = ADD32(ctx->r9, 0X64DC);
    // 0x80078D0C: lui         $t2, 0xF600
    ctx->r10 = S32(0XF600 << 16);
L_80078D10:
    // 0x80078D10: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80078D14: andi        $a1, $t0, 0x3FF
    ctx->r5 = ctx->r8 & 0X3FF;
    // 0x80078D18: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80078D1C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80078D20: mflo        $v0
    ctx->r2 = lo;
    // 0x80078D24: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80078D28: beq         $at, $zero, L_80078D9C
    if (ctx->r1 == 0) {
        // 0x80078D2C: nop
    
            goto L_80078D9C;
    }
    // 0x80078D2C: nop

L_80078D30:
    // 0x80078D30: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078D34: nop

    // 0x80078D38: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078D3C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80078D40: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80078D44: nop

    // 0x80078D48: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80078D4C: andi        $t9, $t7, 0x3FF
    ctx->r25 = ctx->r15 & 0X3FF;
    // 0x80078D50: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80078D54: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x80078D58: or          $t6, $t8, $t2
    ctx->r14 = ctx->r24 | ctx->r10;
    // 0x80078D5C: addu        $t9, $t0, $t7
    ctx->r25 = ADD32(ctx->r8, ctx->r15);
    // 0x80078D60: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x80078D64: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80078D68: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80078D6C: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x80078D70: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x80078D74: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80078D78: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80078D7C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078D80: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80078D84: nop

    // 0x80078D88: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x80078D8C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80078D90: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80078D94: bne         $at, $zero, L_80078D30
    if (ctx->r1 != 0) {
        // 0x80078D98: nop
    
            goto L_80078D30;
    }
    // 0x80078D98: nop

L_80078D9C:
    // 0x80078D9C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80078DA0: xori        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 ^ 0X1;
    // 0x80078DA4: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x80078DA8: slt         $at, $t0, $ra
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x80078DAC: bne         $at, $zero, L_80078D10
    if (ctx->r1 != 0) {
        // 0x80078DB0: or          $t4, $t6, $zero
        ctx->r12 = ctx->r14 | 0;
            goto L_80078D10;
    }
    // 0x80078DB0: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x80078DB4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80078DB8:
    // 0x80078DB8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078DBC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80078DC0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078DC4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80078DC8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80078DCC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078DD0: lbu         $t6, 0x64D4($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X64D4);
    // 0x80078DD4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80078DD8: lbu         $t8, 0x64D5($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X64D5);
    // 0x80078DDC: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80078DE0: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80078DE4: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80078DE8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80078DEC: lbu         $t7, 0x64D6($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X64D6);
    // 0x80078DF0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80078DF4: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x80078DF8: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80078DFC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80078E00: lbu         $t9, 0x64D7($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X64D7);
    // 0x80078E04: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80078E08: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80078E0C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80078E10: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80078E14: addiu       $t1, $t1, 0x64DC
    ctx->r9 = ADD32(ctx->r9, 0X64DC);
    // 0x80078E18: addiu       $a3, $a3, 0x64D8
    ctx->r7 = ADD32(ctx->r7, 0X64D8);
    // 0x80078E1C: lui         $t2, 0xF600
    ctx->r10 = S32(0XF600 << 16);
    // 0x80078E20: blez        $t7, L_80078ED4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80078E24: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80078ED4;
    }
    // 0x80078E24: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80078E28: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80078E2C: nop

L_80078E30:
    // 0x80078E30: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80078E34: andi        $a1, $t0, 0x3FF
    ctx->r5 = ctx->r8 & 0X3FF;
    // 0x80078E38: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80078E3C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80078E40: mflo        $v0
    ctx->r2 = lo;
    // 0x80078E44: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80078E48: beq         $at, $zero, L_80078EBC
    if (ctx->r1 == 0) {
        // 0x80078E4C: nop
    
            goto L_80078EBC;
    }
    // 0x80078E4C: nop

L_80078E50:
    // 0x80078E50: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078E54: nop

    // 0x80078E58: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80078E5C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80078E60: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80078E64: nop

    // 0x80078E68: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80078E6C: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80078E70: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80078E74: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x80078E78: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x80078E7C: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x80078E80: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x80078E84: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80078E88: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80078E8C: andi        $t9, $v0, 0x3FF
    ctx->r25 = ctx->r2 & 0X3FF;
    // 0x80078E90: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x80078E94: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80078E98: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80078E9C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078EA0: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80078EA4: nop

    // 0x80078EA8: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x80078EAC: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80078EB0: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80078EB4: bne         $at, $zero, L_80078E50
    if (ctx->r1 != 0) {
        // 0x80078EB8: nop
    
            goto L_80078E50;
    }
    // 0x80078EB8: nop

L_80078EBC:
    // 0x80078EBC: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80078EC0: xori        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 ^ 0X1;
    // 0x80078EC4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80078EC8: slt         $at, $t0, $ra
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x80078ECC: bne         $at, $zero, L_80078E30
    if (ctx->r1 != 0) {
        // 0x80078ED0: or          $t4, $t6, $zero
        ctx->r12 = ctx->r14 | 0;
            goto L_80078E30;
    }
    // 0x80078ED0: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
L_80078ED4:
    // 0x80078ED4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078ED8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80078EDC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078EE0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80078EE4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078EE8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078EEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80078EF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80078EF4: jr          $ra
    // 0x80078EF8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80078EF8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void __unmapVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A7C4: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8000A7C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000A7CC: beq         $v1, $zero, L_8000A844
    if (ctx->r3 == 0) {
        // 0x8000A7D0: addiu       $a2, $a1, -0x4
        ctx->r6 = ADD32(ctx->r5, -0X4);
            goto L_8000A844;
    }
    // 0x8000A7D0: addiu       $a2, $a1, -0x4
    ctx->r6 = ADD32(ctx->r5, -0X4);
L_8000A7D4:
    // 0x8000A7D4: bne         $v1, $a2, L_8000A830
    if (ctx->r3 != ctx->r6) {
        // 0x8000A7D8: nop
    
            goto L_8000A830;
    }
    // 0x8000A7D8: nop

    // 0x8000A7DC: beq         $v0, $zero, L_8000A7F0
    if (ctx->r2 == 0) {
        // 0x8000A7E0: nop
    
            goto L_8000A7F0;
    }
    // 0x8000A7E0: nop

    // 0x8000A7E4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8000A7E8: b           L_8000A7FC
    // 0x8000A7EC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_8000A7FC;
    // 0x8000A7EC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8000A7F0:
    // 0x8000A7F0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8000A7F4: nop

    // 0x8000A7F8: sw          $t7, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r15;
L_8000A7FC:
    // 0x8000A7FC: lw          $t8, 0x68($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X68);
    // 0x8000A800: nop

    // 0x8000A804: bne         $v1, $t8, L_8000A810
    if (ctx->r3 != ctx->r24) {
        // 0x8000A808: nop
    
            goto L_8000A810;
    }
    // 0x8000A808: nop

    // 0x8000A80C: sw          $v0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r2;
L_8000A810:
    // 0x8000A810: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
    // 0x8000A814: nop

    // 0x8000A818: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000A81C: lbu         $t0, 0x71($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X71);
    // 0x8000A820: sw          $v1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r3;
    // 0x8000A824: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8000A828: jr          $ra
    // 0x8000A82C: sb          $t1, 0x71($a0)
    MEM_B(0X71, ctx->r4) = ctx->r9;
    return;
    // 0x8000A82C: sb          $t1, 0x71($a0)
    MEM_B(0X71, ctx->r4) = ctx->r9;
L_8000A830:
    // 0x8000A830: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000A834: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000A838: nop

    // 0x8000A83C: bne         $v1, $zero, L_8000A7D4
    if (ctx->r3 != 0) {
        // 0x8000A840: nop
    
            goto L_8000A7D4;
    }
    // 0x8000A840: nop

L_8000A844:
    // 0x8000A844: jr          $ra
    // 0x8000A848: nop

    return;
    // 0x8000A848: nop

;}
RECOMP_FUNC void hud_silver_coins(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4CE8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800A4CEC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800A4CF0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A4CF4: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x800A4CF8: addiu       $fp, $fp, 0x729C
    ctx->r30 = ADD32(ctx->r30, 0X729C);
    // 0x800A4CFC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A4D00: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x800A4D04: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A4D08: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A4D0C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800A4D10: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800A4D14: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800A4D18: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800A4D1C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800A4D20: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A4D24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A4D28: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800A4D2C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A4D30: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A4D34: lwc1        $f4, 0x5D0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X5D0);
    // 0x800A4D38: lui         $s2, 0x8080
    ctx->r18 = S32(0X8080 << 16);
    // 0x800A4D3C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A4D40: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800A4D44: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800A4D48: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A4D4C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800A4D50: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A4D54: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A4D58: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800A4D5C: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800A4D60: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A4D64: swc1        $f10, 0x5D0($s1)
    MEM_W(0X5D0, ctx->r17) = ctx->f10.u32l;
    // 0x800A4D68: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800A4D6C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A4D70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A4D74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A4D78: lwc1        $f16, 0x5D0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X5D0);
    // 0x800A4D7C: addiu       $s5, $s5, 0x72C4
    ctx->r21 = ADD32(ctx->r21, 0X72C4);
    // 0x800A4D80: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A4D84: addiu       $s4, $s4, 0x72C0
    ctx->r20 = ADD32(ctx->r20, 0X72C0);
    // 0x800A4D88: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800A4D8C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A4D90: addiu       $s3, $s3, 0x72BC
    ctx->r19 = ADD32(ctx->r19, 0X72BC);
    // 0x800A4D94: ori         $s2, $s2, 0x8080
    ctx->r18 = ctx->r18 | 0X8080;
    // 0x800A4D98: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A4D9C: addiu       $s7, $zero, 0x8
    ctx->r23 = ADD32(0, 0X8);
    // 0x800A4DA0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
L_800A4DA4:
    // 0x800A4DA4: lb          $t1, 0x202($s6)
    ctx->r9 = MEM_B(ctx->r22, 0X202);
    // 0x800A4DA8: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x800A4DAC: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A4DB0: bne         $at, $zero, L_800A4DC0
    if (ctx->r1 != 0) {
        // 0x800A4DB4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800A4DC0;
    }
    // 0x800A4DB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800A4DB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4DBC: sw          $s2, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = ctx->r18;
L_800A4DC0:
    // 0x800A4DC0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800A4DC4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800A4DC8: jal         0x800AAB5C
    // 0x800A4DCC: addiu       $a3, $s1, 0x5C0
    ctx->r7 = ADD32(ctx->r17, 0X5C0);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A4DCC: addiu       $a3, $s1, 0x5C0
    ctx->r7 = ADD32(ctx->r17, 0X5C0);
    after_0:
    // 0x800A4DD0: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x800A4DD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A4DD8: lb          $t2, 0x5DC($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X5DC);
    // 0x800A4DDC: lwc1        $f4, 0x5D0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X5D0);
    // 0x800A4DE0: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800A4DE4: nop

    // 0x800A4DE8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A4DEC: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800A4DF0: bne         $s0, $s7, L_800A4DA4
    if (ctx->r16 != ctx->r23) {
        // 0x800A4DF4: swc1        $f10, 0x5D0($s1)
        MEM_W(0X5D0, ctx->r17) = ctx->f10.u32l;
            goto L_800A4DA4;
    }
    // 0x800A4DF4: swc1        $f10, 0x5D0($s1)
    MEM_W(0X5D0, ctx->r17) = ctx->f10.u32l;
    // 0x800A4DF8: lb          $t3, 0x202($s6)
    ctx->r11 = MEM_B(ctx->r22, 0X202);
    // 0x800A4DFC: nop

    // 0x800A4E00: bne         $s7, $t3, L_800A4E78
    if (ctx->r23 != ctx->r11) {
        // 0x800A4E04: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_800A4E78;
    }
    // 0x800A4E04: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A4E08: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x800A4E0C: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800A4E10: lb          $v0, 0x5DB($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X5DB);
    // 0x800A4E14: nop

    // 0x800A4E18: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x800A4E1C: beq         $at, $zero, L_800A4E30
    if (ctx->r1 == 0) {
        // 0x800A4E20: addu        $t5, $v0, $t4
        ctx->r13 = ADD32(ctx->r2, ctx->r12);
            goto L_800A4E30;
    }
    // 0x800A4E20: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x800A4E24: sb          $t5, 0x5DB($s1)
    MEM_B(0X5DB, ctx->r17) = ctx->r13;
    // 0x800A4E28: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x800A4E2C: nop

L_800A4E30:
    // 0x800A4E30: lb          $t6, 0x5DA($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X5DA);
    // 0x800A4E34: nop

    // 0x800A4E38: bne         $t6, $zero, L_800A4E78
    if (ctx->r14 != 0) {
        // 0x800A4E3C: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_800A4E78;
    }
    // 0x800A4E3C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A4E40: lb          $t7, 0x5DB($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X5DB);
    // 0x800A4E44: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4E48: slti        $at, $t7, 0x1E
    ctx->r1 = SIGNED(ctx->r15) < 0X1E ? 1 : 0;
    // 0x800A4E4C: bne         $at, $zero, L_800A4E74
    if (ctx->r1 != 0) {
        // 0x800A4E50: addiu       $a1, $a1, 0x7300
        ctx->r5 = ADD32(ctx->r5, 0X7300);
            goto L_800A4E74;
    }
    // 0x800A4E50: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    // 0x800A4E54: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A4E58: sb          $t8, 0x5DA($s1)
    MEM_B(0X5DA, ctx->r17) = ctx->r24;
    // 0x800A4E5C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800A4E60: nop

    // 0x800A4E64: bne         $t9, $zero, L_800A4E78
    if (ctx->r25 != 0) {
        // 0x800A4E68: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_800A4E78;
    }
    // 0x800A4E68: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A4E6C: jal         0x80001D04
    // 0x800A4E70: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    sound_play(rdram, ctx);
        goto after_1;
    // 0x800A4E70: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    after_1:
L_800A4E74:
    // 0x800A4E74: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
L_800A4E78:
    // 0x800A4E78: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x800A4E7C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800A4E80: addiu       $t2, $zero, -0x2
    ctx->r10 = ADD32(0, -0X2);
    // 0x800A4E84: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A4E88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4E8C: swc1        $f18, 0x5D0($t1)
    MEM_W(0X5D0, ctx->r9) = ctx->f18.u32l;
    // 0x800A4E90: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4E94: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800A4E98: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800A4E9C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800A4EA0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800A4EA4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800A4EA8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800A4EAC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A4EB0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A4EB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A4EB8: sw          $t2, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = ctx->r10;
    // 0x800A4EBC: jr          $ra
    // 0x800A4EC0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800A4EC0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80017A18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017A4C: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x80017A50: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80017A54: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80017A58: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80017A5C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80017A60: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80017A64: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80017A68: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80017A6C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80017A70: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80017A74: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80017A78: swc1        $f31, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80017A7C: swc1        $f30, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f30.u32l;
    // 0x80017A80: swc1        $f29, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80017A84: swc1        $f28, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f28.u32l;
    // 0x80017A88: swc1        $f27, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80017A8C: swc1        $f26, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f26.u32l;
    // 0x80017A90: swc1        $f25, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80017A94: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x80017A98: swc1        $f23, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80017A9C: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80017AA0: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80017AA4: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x80017AA8: sw          $a1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r5;
    // 0x80017AAC: sw          $a2, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r6;
    // 0x80017AB0: sw          $zero, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = 0;
    // 0x80017AB4: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x80017AB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80017ABC: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80017AC0: blez        $a1, L_80017E44
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80017AC4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80017E44;
    }
    // 0x80017AC4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80017AC8: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x80017ACC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80017AD0: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x80017AD4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80017AD8: lw          $s2, 0x138($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X138);
    // 0x80017ADC: lw          $s3, 0x13C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X13C);
    // 0x80017AE0: lw          $s4, 0x140($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X140);
    // 0x80017AE4: lw          $fp, 0x130($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X130);
    // 0x80017AE8: lw          $ra, 0x134($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X134);
    // 0x80017AEC: lw          $s5, 0x148($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X148);
    // 0x80017AF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80017AF4: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
L_80017AF8:
    // 0x80017AF8: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80017AFC: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x80017B00: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x80017B04: lwc1        $f8, 0x0($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80017B08: lwc1        $f30, 0x0($s3)
    ctx->f30.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80017B0C: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
    // 0x80017B10: lwc1        $f10, 0x14C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x80017B14: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80017B18: lwc1        $f18, 0x0($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80017B1C: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80017B20: lwc1        $f20, 0x0($fp)
    ctx->f20.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80017B24: lwc1        $f22, 0x0($ra)
    ctx->f22.u32l = MEM_W(ctx->r31, 0X0);
    // 0x80017B28: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80017B2C: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
    // 0x80017B30: lh          $t3, 0x32($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X32);
    // 0x80017B34: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80017B38: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
L_80017B3C:
    // 0x80017B3C: blez        $t3, L_80017DDC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80017B40: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80017DDC;
    }
    // 0x80017B40: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80017B44: swc1        $f18, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f18.u32l;
    // 0x80017B48: swc1        $f20, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f20.u32l;
    // 0x80017B4C: swc1        $f22, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f22.u32l;
L_80017B50:
    // 0x80017B50: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80017B54: lwc1        $f28, 0xA4($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80017B58: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80017B5C: lwc1        $f20, 0x9C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80017B60: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x80017B64: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80017B68: lhu         $t7, 0x0($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X0);
    // 0x80017B6C: lwc1        $f18, 0xC0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80017B70: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x80017B74: addu        $v0, $t0, $t6
    ctx->r2 = ADD32(ctx->r8, ctx->r14);
    // 0x80017B78: lwc1        $f26, 0x4($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80017B7C: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80017B80: mul.s       $f14, $f26, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f6.fl);
    // 0x80017B84: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80017B88: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80017B8C: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    // 0x80017B90: mul.s       $f4, $f16, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f28.fl);
    // 0x80017B94: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80017B98: swc1        $f12, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f12.u32l;
    // 0x80017B9C: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80017BA0: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80017BA4: add.s       $f4, $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x80017BA8: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x80017BAC: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80017BB0: mul.s       $f14, $f26, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f30.fl);
    // 0x80017BB4: add.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80017BB8: swc1        $f10, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f10.u32l;
    // 0x80017BBC: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80017BC0: mul.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80017BC4: add.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80017BC8: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80017BCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80017BD0: mul.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80017BD4: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80017BD8: lwc1        $f10, 0x5B9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5B9C);
    // 0x80017BDC: swc1        $f28, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f28.u32l;
    // 0x80017BE0: add.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x80017BE4: swc1        $f20, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f20.u32l;
    // 0x80017BE8: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80017BEC: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    // 0x80017BF0: add.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x80017BF4: lwc1        $f11, 0x5B98($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X5B98);
    // 0x80017BF8: cvt.d.s     $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.d = CVT_D_S(ctx->f0.fl);
    // 0x80017BFC: c.le.d      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.d <= ctx->f14.d;
    // 0x80017C00: sub.s       $f22, $f12, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80017C04: bc1f        L_80017DBC
    if (!c1cs) {
        // 0x80017C08: swc1        $f8, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
            goto L_80017DBC;
    }
    // 0x80017C08: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x80017C0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80017C10: lwc1        $f9, 0x5BA0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5BA0);
    // 0x80017C14: lwc1        $f8, 0x5BA4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5BA4);
    // 0x80017C18: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x80017C1C: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80017C20: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80017C24: bc1f        L_80017DBC
    if (!c1cs) {
        // 0x80017C28: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80017DBC;
    }
    // 0x80017C28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80017C2C: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80017C30: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80017C34: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80017C38: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x80017C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017C40: sub.s       $f28, $f6, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80017C44: bc1t        L_80017C58
    if (c1cs) {
        // 0x80017C48: sub.s       $f14, $f30, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f30.fl - ctx->f8.fl;
            goto L_80017C58;
    }
    // 0x80017C48: sub.s       $f14, $f30, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f30.fl - ctx->f8.fl;
    // 0x80017C4C: sub.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80017C50: b           L_80017C60
    // 0x80017C54: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
        goto L_80017C60;
    // 0x80017C54: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
L_80017C58:
    // 0x80017C58: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80017C5C: nop

L_80017C60:
    // 0x80017C60: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80017C64: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80017C68: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80017C6C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80017C70: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80017C74: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80017C78: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80017C7C: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    // 0x80017C80: mul.s       $f8, $f28, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x80017C84: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80017C88: add.s       $f20, $f8, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f6.fl;
L_80017C8C:
    // 0x80017C8C: lhu         $t8, 0x2($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X2);
    // 0x80017C90: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80017C94: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80017C98: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x80017C9C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80017CA0: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80017CA4: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80017CA8: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80017CAC: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80017CB0: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x80017CB4: mul.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80017CB8: nop

    // 0x80017CBC: mul.s       $f6, $f12, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80017CC0: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80017CC4: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80017CC8: add.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x80017CCC: c.lt.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl < ctx->f10.fl;
    // 0x80017CD0: nop

    // 0x80017CD4: bc1f        L_80017CE0
    if (!c1cs) {
        // 0x80017CD8: nop
    
            goto L_80017CE0;
    }
    // 0x80017CD8: nop

    // 0x80017CDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80017CE0:
    // 0x80017CE0: beq         $at, $zero, L_80017CF0
    if (ctx->r1 == 0) {
        // 0x80017CE4: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80017CF0;
    }
    // 0x80017CE4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80017CE8: beq         $a2, $a3, L_80017C8C
    if (ctx->r6 == ctx->r7) {
        // 0x80017CEC: nop
    
            goto L_80017C8C;
    }
    // 0x80017CEC: nop

L_80017CF0:
    // 0x80017CF0: beq         $a2, $zero, L_80017DBC
    if (ctx->r6 == 0) {
        // 0x80017CF4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80017DBC;
    }
    // 0x80017CF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80017CF8: lwc1        $f9, 0x5BA8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5BA8);
    // 0x80017CFC: lwc1        $f8, 0x5BAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5BAC);
    // 0x80017D00: cvt.d.s     $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f6.d = CVT_D_S(ctx->f26.fl);
    // 0x80017D04: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80017D08: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80017D0C: bc1f        L_80017D38
    if (!c1cs) {
        // 0x80017D10: addu        $v0, $s5, $s1
        ctx->r2 = ADD32(ctx->r21, ctx->r17);
            goto L_80017D38;
    }
    // 0x80017D10: addu        $v0, $s5, $s1
    ctx->r2 = ADD32(ctx->r21, ctx->r17);
    // 0x80017D14: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80017D18: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80017D1C: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80017D20: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80017D24: lwc1        $f10, 0xC0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80017D28: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80017D2C: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80017D30: b           L_80017D68
    // 0x80017D34: div.s       $f30, $f8, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f30.fl = DIV_S(ctx->f8.fl, ctx->f26.fl);
        goto L_80017D68;
    // 0x80017D34: div.s       $f30, $f8, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f30.fl = DIV_S(ctx->f8.fl, ctx->f26.fl);
L_80017D38:
    // 0x80017D38: lwc1        $f10, 0xE4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80017D3C: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80017D40: mul.s       $f4, $f22, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x80017D44: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80017D48: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80017D4C: mul.s       $f10, $f22, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x80017D50: swc1        $f8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f8.u32l;
    // 0x80017D54: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80017D58: mul.s       $f8, $f22, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80017D5C: sub.s       $f30, $f30, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f30.fl - ctx->f10.fl;
    // 0x80017D60: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80017D64: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
L_80017D68:
    // 0x80017D68: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80017D6C: slti        $at, $t4, 0xB
    ctx->r1 = SIGNED(ctx->r12) < 0XB ? 1 : 0;
    // 0x80017D70: bne         $at, $zero, L_80017D90
    if (ctx->r1 != 0) {
        // 0x80017D74: nop
    
            goto L_80017D90;
    }
    // 0x80017D74: nop

    // 0x80017D78: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80017D7C: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80017D80: lwc1        $f30, 0xA0($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80017D84: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80017D88: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x80017D8C: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
L_80017D90:
    // 0x80017D90: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80017D94: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80017D98: nop

    // 0x80017D9C: swc1        $f8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f8.u32l;
    // 0x80017DA0: swc1        $f30, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f30.u32l;
    // 0x80017DA4: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80017DA8: nop

    // 0x80017DAC: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x80017DB0: lh          $t3, 0x32($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X32);
    // 0x80017DB4: nop

    // 0x80017DB8: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
L_80017DBC:
    // 0x80017DBC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80017DC0: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80017DC4: bne         $at, $zero, L_80017B50
    if (ctx->r1 != 0) {
        // 0x80017DC8: nop
    
            goto L_80017B50;
    }
    // 0x80017DC8: nop

    // 0x80017DCC: lwc1        $f22, 0x9C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80017DD0: lwc1        $f20, 0xA0($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80017DD4: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80017DD8: nop

L_80017DDC:
    // 0x80017DDC: bne         $t5, $zero, L_80017B3C
    if (ctx->r13 != 0) {
        // 0x80017DE0: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_80017B3C;
    }
    // 0x80017DE0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80017DE4: blez        $t4, L_80017E14
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80017DE8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80017E14;
    }
    // 0x80017DE8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80017DEC: lw          $t7, 0x128($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X128);
    // 0x80017DF0: nop

    // 0x80017DF4: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80017DF8: nop

    // 0x80017DFC: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80017E00: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80017E04: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x80017E08: nop

    // 0x80017E0C: or          $t6, $t9, $s6
    ctx->r14 = ctx->r25 | ctx->r22;
    // 0x80017E10: sw          $t6, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r14;
L_80017E14:
    // 0x80017E14: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x80017E18: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x80017E1C: sll         $t8, $s6, 1
    ctx->r24 = S32(ctx->r22 << 1);
    // 0x80017E20: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x80017E24: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    // 0x80017E28: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80017E2C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80017E30: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80017E34: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80017E38: addiu       $ra, $ra, 0x4
    ctx->r31 = ADD32(ctx->r31, 0X4);
    // 0x80017E3C: bne         $s1, $t6, L_80017AF8
    if (ctx->r17 != ctx->r14) {
        // 0x80017E40: or          $s6, $t8, $zero
        ctx->r22 = ctx->r24 | 0;
            goto L_80017AF8;
    }
    // 0x80017E40: or          $s6, $t8, $zero
    ctx->r22 = ctx->r24 | 0;
L_80017E44:
    // 0x80017E44: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80017E48: lw          $v0, 0xF8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XF8);
    // 0x80017E4C: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x80017E50: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80017E54: lwc1        $f23, 0x10($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80017E58: lwc1        $f22, 0x14($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80017E5C: lwc1        $f25, 0x18($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80017E60: lwc1        $f24, 0x1C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80017E64: lwc1        $f27, 0x20($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80017E68: lwc1        $f26, 0x24($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80017E6C: lwc1        $f29, 0x28($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80017E70: lwc1        $f28, 0x2C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80017E74: lwc1        $f31, 0x30($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80017E78: lwc1        $f30, 0x34($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80017E7C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80017E80: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80017E84: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80017E88: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80017E8C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80017E90: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80017E94: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80017E98: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80017E9C: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80017EA0: jr          $ra
    // 0x80017EA4: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    return;
    // 0x80017EA4: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
;}
RECOMP_FUNC void sndp_set_priority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004604: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80004608: beq         $a0, $zero, L_80004614
    if (ctx->r4 == 0) {
        // 0x8000460C: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_80004614;
    }
    // 0x8000460C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80004610: sb          $t6, 0x36($a0)
    MEM_B(0X36, ctx->r4) = ctx->r14;
L_80004614:
    // 0x80004614: jr          $ra
    // 0x80004618: nop

    return;
    // 0x80004618: nop

;}
RECOMP_FUNC void alCSeqGetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8000: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C8004: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C8008: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800C800C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800C8010: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x800C8014: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C8018: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800C801C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800C8020: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x800C8024: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800C8028: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C802C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
L_800C8030:
    // 0x800C8030: lw          $t9, 0x18($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X18);
    // 0x800C8034: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800C8038: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800C803C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800C8040: lw          $t1, 0x58($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X58);
    // 0x800C8044: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800C8048: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800C804C: sw          $t1, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r9;
    // 0x800C8050: lbu         $t2, 0x98($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X98);
    // 0x800C8054: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800C8058: sb          $t2, 0x8A($a3)
    MEM_B(0X8A, ctx->r7) = ctx->r10;
    // 0x800C805C: lbu         $t3, 0xA6($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XA6);
    // 0x800C8060: sb          $t3, 0x9A($a3)
    MEM_B(0X9A, ctx->r7) = ctx->r11;
    // 0x800C8064: lw          $t4, 0xB0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XB0);
    // 0x800C8068: sw          $t4, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->r12;
    // 0x800C806C: lw          $t5, 0x14($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X14);
    // 0x800C8070: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
    // 0x800C8074: lw          $t6, 0x54($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X54);
    // 0x800C8078: sw          $t6, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r14;
    // 0x800C807C: lbu         $t7, 0x97($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X97);
    // 0x800C8080: sb          $t7, 0x8B($a3)
    MEM_B(0X8B, ctx->r7) = ctx->r15;
    // 0x800C8084: lbu         $t8, 0xA7($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XA7);
    // 0x800C8088: sb          $t8, 0x9B($a3)
    MEM_B(0X9B, ctx->r7) = ctx->r24;
    // 0x800C808C: lw          $t9, 0xB4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XB4);
    // 0x800C8090: bne         $v0, $a0, L_800C8030
    if (ctx->r2 != ctx->r4) {
        // 0x800C8094: sw          $t9, 0xA8($v1)
        MEM_W(0XA8, ctx->r3) = ctx->r25;
            goto L_800C8030;
    }
    // 0x800C8094: sw          $t9, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r25;
    // 0x800C8098: jr          $ra
    // 0x800C809C: nop

    return;
    // 0x800C809C: nop

;}
RECOMP_FUNC void menu_cinematic_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B238: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8009B23C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009B240: lw          $t6, 0x6964($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6964);
    // 0x8009B244: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8009B248: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8009B24C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8009B250: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8009B254: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8009B258: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8009B25C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8009B260: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8009B264: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8009B268: bne         $t6, $zero, L_8009B2A4
    if (ctx->r14 != 0) {
        // 0x8009B26C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8009B2A4;
    }
    // 0x8009B26C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8009B270: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8009B274: addiu       $s1, $s1, -0x5C4
    ctx->r17 = ADD32(ctx->r17, -0X5C4);
    // 0x8009B278: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009B27C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009B280: blez        $t7, L_8009B2A4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8009B284: nop
    
            goto L_8009B2A4;
    }
    // 0x8009B284: nop

L_8009B288:
    // 0x8009B288: jal         0x8006A794
    // 0x8009B28C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8009B28C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8009B290: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8009B294: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009B298: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8009B29C: bne         $at, $zero, L_8009B288
    if (ctx->r1 != 0) {
        // 0x8009B2A0: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_8009B288;
    }
    // 0x8009B2A0: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_8009B2A4:
    // 0x8009B2A4: jal         0x800214F8
    // 0x8009B2A8: nop

    func_800214C4(rdram, ctx);
        goto after_1;
    // 0x8009B2A8: nop

    after_1:
    // 0x8009B2AC: beq         $v0, $zero, L_8009B320
    if (ctx->r2 == 0) {
        // 0x8009B2B0: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009B320;
    }
    // 0x8009B2B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009B2B4: addiu       $v1, $v1, 0x6D8C
    ctx->r3 = ADD32(ctx->r3, 0X6D8C);
    // 0x8009B2B8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8009B2BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009B2C0: addiu       $t0, $t9, 0x3
    ctx->r8 = ADD32(ctx->r25, 0X3);
    // 0x8009B2C4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8009B2C8: lb          $a0, 0x0($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X0);
    // 0x8009B2CC: nop

    // 0x8009B2D0: bltz        $a0, L_8009B2F0
    if (SIGNED(ctx->r4) < 0) {
        // 0x8009B2D4: nop
    
            goto L_8009B2F0;
    }
    // 0x8009B2D4: nop

    // 0x8009B2D8: lb          $a1, 0x1($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X1);
    // 0x8009B2DC: lb          $a2, 0x2($t0)
    ctx->r6 = MEM_B(ctx->r8, 0X2);
    // 0x8009B2E0: jal         0x8006E528
    // 0x8009B2E4: nop

    load_level_for_menu(rdram, ctx);
        goto after_2;
    // 0x8009B2E4: nop

    after_2:
    // 0x8009B2E8: b           L_8009B320
    // 0x8009B2EC: nop

        goto L_8009B320;
    // 0x8009B2EC: nop

L_8009B2F0:
    // 0x8009B2F0: lw          $t1, 0x6DEC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6DEC);
    // 0x8009B2F4: nop

    // 0x8009B2F8: beq         $t1, $zero, L_8009B308
    if (ctx->r9 == 0) {
        // 0x8009B2FC: nop
    
            goto L_8009B308;
    }
    // 0x8009B2FC: nop

    // 0x8009B300: jal         0x80000B18
    // 0x8009B304: nop

    music_change_off(rdram, ctx);
        goto after_3;
    // 0x8009B304: nop

    after_3:
L_8009B308:
    // 0x8009B308: jal         0x8009B454
    // 0x8009B30C: nop

    cinematic_free(rdram, ctx);
        goto after_4;
    // 0x8009B30C: nop

    after_4:
    // 0x8009B310: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009B314: lw          $v0, 0x6DC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6DC4);
    // 0x8009B318: b           L_8009B430
    // 0x8009B31C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8009B430;
    // 0x8009B31C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009B320:
    // 0x8009B320: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009B324: addiu       $s0, $s0, 0x6DDC
    ctx->r16 = ADD32(ctx->r16, 0X6DDC);
    // 0x8009B328: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8009B32C: andi        $t3, $s2, 0x9000
    ctx->r11 = ctx->r18 & 0X9000;
    // 0x8009B330: beq         $t2, $zero, L_8009B354
    if (ctx->r10 == 0) {
        // 0x8009B334: nop
    
            goto L_8009B354;
    }
    // 0x8009B334: nop

    // 0x8009B338: beq         $t3, $zero, L_8009B354
    if (ctx->r11 == 0) {
        // 0x8009B33C: nop
    
            goto L_8009B354;
    }
    // 0x8009B33C: nop

    // 0x8009B340: jal         0x8009B454
    // 0x8009B344: nop

    cinematic_free(rdram, ctx);
        goto after_5;
    // 0x8009B344: nop

    after_5:
    // 0x8009B348: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009B34C: b           L_8009B430
    // 0x8009B350: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8009B430;
    // 0x8009B350: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009B354:
    // 0x8009B354: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009B358: addiu       $s0, $s0, 0x6DE4
    ctx->r16 = ADD32(ctx->r16, 0X6DE4);
    // 0x8009B35C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8009B360: nop

    // 0x8009B364: beq         $t4, $zero, L_8009B388
    if (ctx->r12 == 0) {
        // 0x8009B368: andi        $t5, $s2, 0x4000
        ctx->r13 = ctx->r18 & 0X4000;
            goto L_8009B388;
    }
    // 0x8009B368: andi        $t5, $s2, 0x4000
    ctx->r13 = ctx->r18 & 0X4000;
    // 0x8009B36C: beq         $t5, $zero, L_8009B388
    if (ctx->r13 == 0) {
        // 0x8009B370: nop
    
            goto L_8009B388;
    }
    // 0x8009B370: nop

    // 0x8009B374: jal         0x8009B454
    // 0x8009B378: nop

    cinematic_free(rdram, ctx);
        goto after_6;
    // 0x8009B378: nop

    after_6:
    // 0x8009B37C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009B380: b           L_8009B430
    // 0x8009B384: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8009B430;
    // 0x8009B384: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009B388:
    // 0x8009B388: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8009B38C: addiu       $s3, $s3, 0x6DA4
    ctx->r19 = ADD32(ctx->r19, 0X6DA4);
    // 0x8009B390: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8009B394: nop

    // 0x8009B398: beq         $v0, $zero, L_8009B420
    if (ctx->r2 == 0) {
        // 0x8009B39C: nop
    
            goto L_8009B420;
    }
    // 0x8009B39C: nop

    // 0x8009B3A0: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009B3A4: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8009B3A8: beq         $s4, $t6, L_8009B420
    if (ctx->r20 == ctx->r14) {
        // 0x8009B3AC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8009B420;
    }
    // 0x8009B3AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009B3B0: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8009B3B4: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8009B3B8: lb          $s1, 0x0($v0)
    ctx->r17 = MEM_B(ctx->r2, 0X0);
    // 0x8009B3BC: addiu       $s5, $s5, 0x693C
    ctx->r21 = ADD32(ctx->r21, 0X693C);
    // 0x8009B3C0: addiu       $s6, $s6, 0x1070
    ctx->r22 = ADD32(ctx->r22, 0X1070);
    // 0x8009B3C4: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x8009B3C8: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
L_8009B3CC:
    // 0x8009B3CC: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x8009B3D0: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x8009B3D4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009B3D8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8009B3DC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009B3E0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009B3E4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8009B3E8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8009B3EC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8009B3F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009B3F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8009B3F8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8009B3FC: jal         0x80078F08
    // 0x8009B400: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    texrect_draw(rdram, ctx);
        goto after_7;
    // 0x8009B400: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_7:
    // 0x8009B404: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x8009B408: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009B40C: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8009B410: lb          $s1, 0x0($t4)
    ctx->r17 = MEM_B(ctx->r12, 0X0);
    // 0x8009B414: addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
    // 0x8009B418: bne         $s4, $s1, L_8009B3CC
    if (ctx->r20 != ctx->r17) {
        // 0x8009B41C: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_8009B3CC;
    }
    // 0x8009B41C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
L_8009B420:
    // 0x8009B420: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B424: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x8009B428: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009B42C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009B430:
    // 0x8009B430: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8009B434: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8009B438: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8009B43C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8009B440: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8009B444: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8009B448: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8009B44C: jr          $ra
    // 0x8009B450: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8009B450: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void __lookupSoundQuick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A8D0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000A8D4: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x8000A8D8: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8000A8DC: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x8000A8E0: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8000A8E4: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x8000A8E8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8000A8EC: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x8000A8F0: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8000A8F4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000A8F8: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x8000A8FC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8000A900: andi        $s0, $a2, 0xFF
    ctx->r16 = ctx->r6 & 0XFF;
    // 0x8000A904: lh          $t0, 0xE($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XE);
    // 0x8000A908: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000A90C: blez        $t0, L_8000A9E8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8000A910: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8000A9E8;
    }
    // 0x8000A910: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8000A914: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x8000A918: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
L_8000A91C:
    // 0x8000A91C: bgez        $a1, L_8000A92C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8000A920: sra         $t4, $a1, 1
        ctx->r12 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8000A92C;
    }
    // 0x8000A920: sra         $t4, $a1, 1
    ctx->r12 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8000A924: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x8000A928: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_8000A92C:
    // 0x8000A92C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8000A930: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8000A934: lw          $a3, 0xC($t6)
    ctx->r7 = MEM_W(ctx->r14, 0XC);
    // 0x8000A938: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8000A93C: lw          $a2, 0x4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X4);
    // 0x8000A940: nop

    // 0x8000A944: lbu         $t2, 0x2($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X2);
    // 0x8000A948: nop

    // 0x8000A94C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000A950: bne         $at, $zero, L_8000A9A0
    if (ctx->r1 != 0) {
        // 0x8000A954: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8000A9A0;
    }
    // 0x8000A954: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000A958: lbu         $t7, 0x3($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X3);
    // 0x8000A95C: nop

    // 0x8000A960: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000A964: bne         $at, $zero, L_8000A9A0
    if (ctx->r1 != 0) {
        // 0x8000A968: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8000A9A0;
    }
    // 0x8000A968: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000A96C: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x8000A970: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000A974: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000A978: bne         $at, $zero, L_8000A9A0
    if (ctx->r1 != 0) {
        // 0x8000A97C: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8000A9A0;
    }
    // 0x8000A97C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000A980: lbu         $t9, 0x1($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X1);
    // 0x8000A984: nop

    // 0x8000A988: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000A98C: bne         $at, $zero, L_8000A9A0
    if (ctx->r1 != 0) {
        // 0x8000A990: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8000A9A0;
    }
    // 0x8000A990: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000A994: b           L_8000A9EC
    // 0x8000A998: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_8000A9EC;
    // 0x8000A998: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8000A99C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
L_8000A9A0:
    // 0x8000A9A0: bne         $at, $zero, L_8000A9D0
    if (ctx->r1 != 0) {
        // 0x8000A9A4: nop
    
            goto L_8000A9D0;
    }
    // 0x8000A9A4: nop

    // 0x8000A9A8: lbu         $t3, 0x0($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X0);
    // 0x8000A9AC: nop

    // 0x8000A9B0: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8000A9B4: beq         $at, $zero, L_8000A9D8
    if (ctx->r1 == 0) {
        // 0x8000A9B8: nop
    
            goto L_8000A9D8;
    }
    // 0x8000A9B8: nop

    // 0x8000A9BC: lbu         $t4, 0x3($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X3);
    // 0x8000A9C0: nop

    // 0x8000A9C4: slt         $at, $t4, $t1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000A9C8: bne         $at, $zero, L_8000A9D8
    if (ctx->r1 != 0) {
        // 0x8000A9CC: nop
    
            goto L_8000A9D8;
    }
    // 0x8000A9CC: nop

L_8000A9D0:
    // 0x8000A9D0: b           L_8000A9DC
    // 0x8000A9D4: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
        goto L_8000A9DC;
    // 0x8000A9D4: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
L_8000A9D8:
    // 0x8000A9D8: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
L_8000A9DC:
    // 0x8000A9DC: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000A9E0: beq         $at, $zero, L_8000A91C
    if (ctx->r1 == 0) {
        // 0x8000A9E4: addu        $a1, $v1, $t0
        ctx->r5 = ADD32(ctx->r3, ctx->r8);
            goto L_8000A91C;
    }
    // 0x8000A9E4: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
L_8000A9E8:
    // 0x8000A9E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000A9EC:
    // 0x8000A9EC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8000A9F0: jr          $ra
    // 0x8000A9F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000A9F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void menu_credits_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B484: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009B488: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009B48C: jal         0x8006ECD0
    // 0x8009B490: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009B490: nop

    after_0:
    // 0x8009B494: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B498: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8009B49C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B4A0: sw          $zero, 0x7184($at)
    MEM_W(0X7184, ctx->r1) = 0;
    // 0x8009B4A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B4A8: sw          $zero, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = 0;
    // 0x8009B4AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B4B0: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x8009B4B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B4B8: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x8009B4BC: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
    // 0x8009B4C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B4C4: sw          $zero, -0x620($at)
    MEM_W(-0X620, ctx->r1) = 0;
    // 0x8009B4C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B4CC: sw          $zero, 0x7190($at)
    MEM_W(0X7190, ctx->r1) = 0;
    // 0x8009B4D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B4D4: sw          $zero, 0x7198($at)
    MEM_W(0X7198, ctx->r1) = 0;
    // 0x8009B4D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B4DC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8009B4E0: sw          $zero, 0x71A0($at)
    MEM_W(0X71A0, ctx->r1) = 0;
    // 0x8009B4E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B4E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009B4EC: jal         0x80077FAC
    // 0x8009B4F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bgdraw_fillcolour(rdram, ctx);
        goto after_1;
    // 0x8009B4F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8009B4F4: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8009B4F8: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8009B4FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B500: bne         $t7, $zero, L_8009B548
    if (ctx->r15 != 0) {
        // 0x8009B504: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8009B548;
    }
    // 0x8009B504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009B508: addiu       $t8, $zero, 0xE0
    ctx->r24 = ADD32(0, 0XE0);
    // 0x8009B50C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009B510: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009B518: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8009B51C: jal         0x80066B80
    // 0x8009B520: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    viewport_menu_set(rdram, ctx);
        goto after_2;
    // 0x8009B520: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_2:
    // 0x8009B524: addiu       $t9, $zero, 0x11C
    ctx->r25 = ADD32(0, 0X11C);
    // 0x8009B528: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009B52C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B530: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8009B534: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x8009B538: jal         0x80066CE8
    // 0x8009B53C: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    set_viewport_properties(rdram, ctx);
        goto after_3;
    // 0x8009B53C: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_3:
    // 0x8009B540: b           L_8009B578
    // 0x8009B544: nop

        goto L_8009B578;
    // 0x8009B544: nop

L_8009B548:
    // 0x8009B548: addiu       $t0, $zero, 0xC4
    ctx->r8 = ADD32(0, 0XC4);
    // 0x8009B54C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8009B550: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x8009B554: jal         0x80066B80
    // 0x8009B558: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    viewport_menu_set(rdram, ctx);
        goto after_4;
    // 0x8009B558: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_4:
    // 0x8009B55C: addiu       $t1, $zero, 0xF0
    ctx->r9 = ADD32(0, 0XF0);
    // 0x8009B560: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009B564: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B568: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8009B56C: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x8009B570: jal         0x80066CE8
    // 0x8009B574: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    set_viewport_properties(rdram, ctx);
        goto after_5;
    // 0x8009B574: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_5:
L_8009B578:
    // 0x8009B578: jal         0x80066850
    // 0x8009B57C: nop

    copy_viewports_to_stack(rdram, ctx);
        goto after_6;
    // 0x8009B57C: nop

    after_6:
    // 0x8009B580: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B584: jal         0x80066A58
    // 0x8009B588: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camEnableUserView(rdram, ctx);
        goto after_7;
    // 0x8009B588: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8009B58C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B590: jal         0x8009CBB8
    // 0x8009B594: addiu       $a0, $a0, 0x1D58
    ctx->r4 = ADD32(ctx->r4, 0X1D58);
    menu_assetgroup_load(rdram, ctx);
        goto after_8;
    // 0x8009B594: addiu       $a0, $a0, 0x1D58
    ctx->r4 = ADD32(ctx->r4, 0X1D58);
    after_8:
    // 0x8009B598: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B59C: jal         0x8009CDE8
    // 0x8009B5A0: addiu       $a0, $a0, 0x1D70
    ctx->r4 = ADD32(ctx->r4, 0X1D70);
    menu_imagegroup_load(rdram, ctx);
        goto after_9;
    // 0x8009B5A0: addiu       $a0, $a0, 0x1D70
    ctx->r4 = ADD32(ctx->r4, 0X1D70);
    after_9:
    // 0x8009B5A4: jal         0x80094B08
    // 0x8009B5A8: nop

    menu_racer_portraits(rdram, ctx);
        goto after_10;
    // 0x8009B5A8: nop

    after_10:
    // 0x8009B5AC: jal         0x800C46D0
    // 0x8009B5B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_11;
    // 0x8009B5B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x8009B5B4: jal         0x80000BE0
    // 0x8009B5B8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_12;
    // 0x8009B5B8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_12:
    // 0x8009B5BC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009B5C0: lw          $t3, 0x20CC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X20CC);
    // 0x8009B5C4: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x8009B5C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B5CC: beq         $t3, $zero, L_8009B610
    if (ctx->r11 == 0) {
        // 0x8009B5D0: sh          $t2, 0x1E78($at)
        MEM_H(0X1E78, ctx->r1) = ctx->r10;
            goto L_8009B610;
    }
    // 0x8009B5D0: sh          $t2, 0x1E78($at)
    MEM_H(0X1E78, ctx->r1) = ctx->r10;
    // 0x8009B5D4: jal         0x80000B34
    // 0x8009B5D8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    music_play(rdram, ctx);
        goto after_13;
    // 0x8009B5D8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_13:
    // 0x8009B5DC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009B5E0: addiu       $v0, $v0, 0x2064
    ctx->r2 = ADD32(ctx->r2, 0X2064);
    // 0x8009B5E4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009B5E8: addiu       $a2, $a2, 0x1EB8
    ctx->r6 = ADD32(ctx->r6, 0X1EB8);
    // 0x8009B5EC: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x8009B5F0: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x8009B5F4: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8009B5F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B5FC: sw          $t4, 0x150($a2)
    MEM_W(0X150, ctx->r6) = ctx->r12;
    // 0x8009B600: sw          $t5, 0x154($a2)
    MEM_W(0X154, ctx->r6) = ctx->r13;
    // 0x8009B604: sw          $t6, 0x158($a2)
    MEM_W(0X158, ctx->r6) = ctx->r14;
    // 0x8009B608: b           L_8009B700
    // 0x8009B60C: sw          $zero, 0x20CC($at)
    MEM_W(0X20CC, ctx->r1) = 0;
        goto L_8009B700;
    // 0x8009B60C: sw          $zero, 0x20CC($at)
    MEM_W(0X20CC, ctx->r1) = 0;
L_8009B610:
    // 0x8009B610: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8009B614: nop

    // 0x8009B618: lhu         $t8, 0xC($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XC);
    // 0x8009B61C: nop

    // 0x8009B620: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x8009B624: beq         $t9, $zero, L_8009B668
    if (ctx->r25 == 0) {
        // 0x8009B628: nop
    
            goto L_8009B668;
    }
    // 0x8009B628: nop

    // 0x8009B62C: jal         0x80000B34
    // 0x8009B630: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    music_play(rdram, ctx);
        goto after_14;
    // 0x8009B630: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_14:
    // 0x8009B634: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009B638: addiu       $v0, $v0, 0x2064
    ctx->r2 = ADD32(ctx->r2, 0X2064);
    // 0x8009B63C: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8009B640: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009B644: addiu       $a2, $a2, 0x1EB8
    ctx->r6 = ADD32(ctx->r6, 0X1EB8);
    // 0x8009B648: addiu       $t1, $zero, 0x61F4
    ctx->r9 = ADD32(0, 0X61F4);
    // 0x8009B64C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B650: sw          $t0, 0x150($a2)
    MEM_W(0X150, ctx->r6) = ctx->r8;
    // 0x8009B654: sh          $t1, 0x1E78($at)
    MEM_H(0X1E78, ctx->r1) = ctx->r9;
    // 0x8009B658: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B65C: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x8009B660: b           L_8009B688
    // 0x8009B664: sw          $t2, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r10;
        goto L_8009B688;
    // 0x8009B664: sw          $t2, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r10;
L_8009B668:
    // 0x8009B668: jal         0x80000B34
    // 0x8009B66C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    music_play(rdram, ctx);
        goto after_15;
    // 0x8009B66C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_15:
    // 0x8009B670: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009B674: addiu       $v0, $v0, 0x2064
    ctx->r2 = ADD32(ctx->r2, 0X2064);
    // 0x8009B678: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8009B67C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009B680: addiu       $a2, $a2, 0x1EB8
    ctx->r6 = ADD32(ctx->r6, 0X1EB8);
    // 0x8009B684: sw          $t3, 0x150($a2)
    MEM_W(0X150, ctx->r6) = ctx->r11;
L_8009B688:
    // 0x8009B688: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B68C: jal         0x8006FB8C
    // 0x8009B690: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    rand_range(rdram, ctx);
        goto after_16;
    // 0x8009B690: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_16:
    // 0x8009B694: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8009B698: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009B69C: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x8009B6A0: lw          $v1, 0x2078($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2078);
    // 0x8009B6A4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009B6A8: addiu       $a2, $a2, 0x1EB8
    ctx->r6 = ADD32(ctx->r6, 0X1EB8);
    // 0x8009B6AC: beq         $v1, $zero, L_8009B6C4
    if (ctx->r3 == 0) {
        // 0x8009B6B0: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8009B6C4;
    }
    // 0x8009B6B0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_8009B6B4:
    // 0x8009B6B4: sra         $t5, $v1, 1
    ctx->r13 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8009B6B8: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8009B6BC: bne         $t5, $zero, L_8009B6B4
    if (ctx->r13 != 0) {
        // 0x8009B6C0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8009B6B4;
    }
    // 0x8009B6C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8009B6C4:
    // 0x8009B6C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009B6C8: lw          $v0, 0x71F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X71F0);
    // 0x8009B6CC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8009B6D0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8009B6D4: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8009B6D8: addiu       $a1, $v0, 0x2
    ctx->r5 = ADD32(ctx->r2, 0X2);
    // 0x8009B6DC: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x8009B6E0: lhu         $t8, 0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2);
    // 0x8009B6E4: nop

    // 0x8009B6E8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8009B6EC: sw          $t9, 0x154($a2)
    MEM_W(0X154, ctx->r6) = ctx->r25;
    // 0x8009B6F0: lhu         $t0, 0x0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X0);
    // 0x8009B6F4: nop

    // 0x8009B6F8: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8009B6FC: sw          $t1, 0x158($a2)
    MEM_W(0X158, ctx->r6) = ctx->r9;
L_8009B700:
    // 0x8009B700: jal         0x80000B18
    // 0x8009B704: nop

    music_change_off(rdram, ctx);
        goto after_17;
    // 0x8009B704: nop

    after_17:
    // 0x8009B708: jal         0x800C0690
    // 0x8009B70C: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_18;
    // 0x8009B70C: nop

    after_18:
    // 0x8009B710: jal         0x8006F7A4
    // 0x8009B714: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_gIntDisFlag(rdram, ctx);
        goto after_19;
    // 0x8009B714: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x8009B718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B71C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009B720: jr          $ra
    // 0x8009B724: nop

    return;
    // 0x8009B724: nop

;}
