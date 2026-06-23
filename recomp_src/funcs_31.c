#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void obj_init_bonus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003B09C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B0A0: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x8003B0A4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003B0A8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8003B0AC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003B0B0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003B0B4: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8003B0B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003B0BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003B0C0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8003B0C4: bc1f        L_8003B0D4
    if (!c1cs) {
        // 0x8003B0C8: nop
    
            goto L_8003B0D4;
    }
    // 0x8003B0C8: nop

    // 0x8003B0CC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003B0D0: nop

L_8003B0D4:
    // 0x8003B0D4: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003B0D8: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x8003B0DC: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8003B0E0: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x8003B0E4: nop

    // 0x8003B0E8: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x8003B0EC: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    // 0x8003B0F0: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x8003B0F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B0F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003B0FC: jal         0x80070A04
    // 0x8003B100: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x8003B100: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003B104: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003B108: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003B10C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003B110: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8003B114: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8003B118: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x8003B11C: jal         0x80070A38
    // 0x8003B120: nop

    coss_f(rdram, ctx);
        goto after_1;
    // 0x8003B120: nop

    after_1:
    // 0x8003B124: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003B128: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003B12C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8003B130: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8003B134: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003B138: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8003B13C: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8003B140: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003B144: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8003B148: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003B14C: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003B150: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003B154: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8003B158: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x8003B15C: nop

    // 0x8003B160: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    // 0x8003B164: lbu         $t2, 0xA($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XA);
    // 0x8003B168: nop

    // 0x8003B16C: sb          $t2, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r10;
    // 0x8003B170: lw          $t4, 0x4C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X4C);
    // 0x8003B174: nop

    // 0x8003B178: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x8003B17C: lw          $t5, 0x4C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4C);
    // 0x8003B180: nop

    // 0x8003B184: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
    // 0x8003B188: lw          $t7, 0x4C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4C);
    // 0x8003B18C: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x8003B190: nop

    // 0x8003B194: sb          $t6, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r14;
    // 0x8003B198: lw          $t8, 0x4C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4C);
    // 0x8003B19C: nop

    // 0x8003B1A0: sb          $zero, 0x12($t8)
    MEM_B(0X12, ctx->r24) = 0;
    // 0x8003B1A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B1A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003B1AC: jr          $ra
    // 0x8003B1B0: nop

    return;
    // 0x8003B1B0: nop

;}
RECOMP_FUNC void fade_when_near_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D1E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D1EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D1F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005D1F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005D1F8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005D1FC: jal         0x8001BAFC
    // 0x8005D200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x8005D200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8005D204: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8005D208: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005D20C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8005D210: jal         0x8001139C
    // 0x8005D214: sb          $t6, 0x1F7($t7)
    MEM_B(0X1F7, ctx->r15) = ctx->r14;
    get_race_countdown(rdram, ctx);
        goto after_1;
    // 0x8005D214: sb          $t6, 0x1F7($t7)
    MEM_B(0X1F7, ctx->r15) = ctx->r14;
    after_1:
    // 0x8005D218: bne         $v0, $zero, L_8005D25C
    if (ctx->r2 != 0) {
        // 0x8005D21C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005D25C;
    }
    // 0x8005D21C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D220: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005D224: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005D228: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8005D22C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D230: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005D234: lwc1        $f4, 0x30($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X30);
    // 0x8005D238: lwc1        $f16, 0x30($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X30);
    // 0x8005D23C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8005D240: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8005D244: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8005D248: nop

    // 0x8005D24C: bc1f        L_8005D258
    if (!c1cs) {
        // 0x8005D250: addiu       $t1, $zero, 0x40
        ctx->r9 = ADD32(0, 0X40);
            goto L_8005D258;
    }
    // 0x8005D250: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x8005D254: sb          $t1, 0x1F7($t2)
    MEM_B(0X1F7, ctx->r10) = ctx->r9;
L_8005D258:
    // 0x8005D258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005D25C:
    // 0x8005D25C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005D260: jr          $ra
    // 0x8005D264: nop

    return;
    // 0x8005D264: nop

;}
RECOMP_FUNC void racer_find_nearest_opponent_relative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B7DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B7E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B7E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001B7E8: lh          $t6, 0x1AA($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1AA);
    // 0x8001B7EC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001B7F0: subu        $a1, $t6, $a1
    ctx->r5 = SUB32(ctx->r14, ctx->r5);
    // 0x8001B7F4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001B7F8: bltz        $a1, L_8001B814
    if (SIGNED(ctx->r5) < 0) {
        // 0x8001B7FC: nop
    
            goto L_8001B814;
    }
    // 0x8001B7FC: nop

    // 0x8001B800: lw          $t7, -0x4B90($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4B90);
    // 0x8001B804: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001B808: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001B80C: bne         $at, $zero, L_8001B81C
    if (ctx->r1 != 0) {
        // 0x8001B810: nop
    
            goto L_8001B81C;
    }
    // 0x8001B810: nop

L_8001B814:
    // 0x8001B814: b           L_8001B858
    // 0x8001B818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001B858;
    // 0x8001B818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B81C:
    // 0x8001B81C: lw          $t8, -0x4B98($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4B98);
    // 0x8001B820: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8001B824: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8001B828: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001B82C: nop

    // 0x8001B830: bne         $v1, $zero, L_8001B840
    if (ctx->r3 != 0) {
        // 0x8001B834: nop
    
            goto L_8001B840;
    }
    // 0x8001B834: nop

    // 0x8001B838: b           L_8001B858
    // 0x8001B83C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001B858;
    // 0x8001B83C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B840:
    // 0x8001B840: lw          $a1, 0x64($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X64);
    // 0x8001B844: jal         0x8001B868
    // 0x8001B848: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    racer_calc_distance_to_opponent(rdram, ctx);
        goto after_0;
    // 0x8001B848: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8001B84C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001B850: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8001B854: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
L_8001B858:
    // 0x8001B858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B85C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001B860: jr          $ra
    // 0x8001B864: nop

    return;
    // 0x8001B864: nop

;}
RECOMP_FUNC void music_channel_reset_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800012E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800012EC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800012F0: lw          $t6, -0x3448($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3448);
    // 0x800012F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800012F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800012FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80001300: bne         $t6, $zero, L_80001340
    if (ctx->r14 != 0) {
        // 0x80001304: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80001340;
    }
    // 0x80001304: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80001308: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000130C: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x80001310: andi        $s1, $s0, 0xFF
    ctx->r17 = ctx->r16 & 0XFF;
L_80001314:
    // 0x80001314: jal         0x80001170
    // 0x80001318: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_0;
    // 0x80001318: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_0:
    // 0x8000131C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x80001320: jal         0x80001268
    // 0x80001324: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    music_channel_fade_set(rdram, ctx);
        goto after_1;
    // 0x80001324: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_1:
    // 0x80001328: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8000132C: jal         0x800011E8
    // 0x80001330: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    music_channel_volume_set(rdram, ctx);
        goto after_2;
    // 0x80001330: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_2:
    // 0x80001334: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80001338: bne         $s0, $s2, L_80001314
    if (ctx->r16 != ctx->r18) {
        // 0x8000133C: andi        $s1, $s0, 0xFF
        ctx->r17 = ctx->r16 & 0XFF;
            goto L_80001314;
    }
    // 0x8000133C: andi        $s1, $s0, 0xFF
    ctx->r17 = ctx->r16 & 0XFF;
L_80001340:
    // 0x80001340: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80001344: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001348: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000134C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80001350: jr          $ra
    // 0x80001354: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80001354: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_init_audioline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FF34: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003FF38: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8003FF3C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8003FF40: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8003FF44: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003FF48: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x8003FF4C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8003FF50: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8003FF54: lhu         $t8, 0xA($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XA);
    // 0x8003FF58: andi        $a0, $t7, 0xFF
    ctx->r4 = ctx->r15 & 0XFF;
    // 0x8003FF5C: sh          $t8, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r24;
    // 0x8003FF60: lbu         $t9, 0xC($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XC);
    // 0x8003FF64: nop

    // 0x8003FF68: sb          $t9, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r25;
    // 0x8003FF6C: lbu         $t0, 0xD($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XD);
    // 0x8003FF70: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8003FF74: sb          $t0, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r8;
    // 0x8003FF78: lhu         $t1, 0xE($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0XE);
    // 0x8003FF7C: nop

    // 0x8003FF80: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
    // 0x8003FF84: lbu         $t2, 0x12($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X12);
    // 0x8003FF88: nop

    // 0x8003FF8C: sb          $t2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r10;
    // 0x8003FF90: lbu         $t3, 0x11($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X11);
    // 0x8003FF94: nop

    // 0x8003FF98: sb          $t3, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r11;
    // 0x8003FF9C: lbu         $t4, 0x9($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X9);
    // 0x8003FFA0: nop

    // 0x8003FFA4: sb          $t4, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r12;
    // 0x8003FFA8: lbu         $t5, 0x10($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X10);
    // 0x8003FFAC: nop

    // 0x8003FFB0: sb          $t5, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r13;
    // 0x8003FFB4: lbu         $t6, 0x13($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X13);
    // 0x8003FFB8: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    // 0x8003FFBC: sb          $t6, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r14;
    // 0x8003FFC0: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x8003FFC4: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
    // 0x8003FFC8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8003FFCC: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x8003FFD0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003FFD4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8003FFD8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8003FFDC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8003FFE0: lbu         $t0, 0xF($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XF);
    // 0x8003FFE4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003FFE8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8003FFEC: lbu         $t1, 0xE($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XE);
    // 0x8003FFF0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003FFF4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8003FFF8: lbu         $t2, 0x10($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X10);
    // 0x8003FFFC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80040000: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80040004: lbu         $t3, 0x12($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X12);
    // 0x80040008: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8004000C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80040010: lhu         $t4, 0x4($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X4);
    // 0x80040014: nop

    // 0x80040018: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8004001C: lbu         $t5, 0x11($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X11);
    // 0x80040020: nop

    // 0x80040024: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80040028: lbu         $t6, 0xC($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC);
    // 0x8004002C: nop

    // 0x80040030: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80040034: lbu         $t7, 0xD($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XD);
    // 0x80040038: jal         0x800098A4
    // 0x8004003C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    audspat_line_add_vertex(rdram, ctx);
        goto after_0;
    // 0x8004003C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    after_0:
    // 0x80040040: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80040044: jal         0x8000FFB8
    // 0x80040048: nop

    free_object(rdram, ctx);
        goto after_1;
    // 0x80040048: nop

    after_1:
    // 0x8004004C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80040050: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80040054: jr          $ra
    // 0x80040058: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80040058: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void calc_dyn_lighting_for_level_segment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070B10: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80070B14: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x80070B18: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    // 0x80070B1C: lhu         $t0, 0x20($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X20);
    // 0x80070B20: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x80070B24: lw          $a1, 0x2C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2C);
    // 0x80070B28: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80070B2C: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
L_80070B30:
    // 0x80070B30: lbu         $t4, 0x6($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X6);
    // 0x80070B34: addiu       $t4, $t4, -0xFF
    ctx->r12 = ADD32(ctx->r12, -0XFF);
    // 0x80070B38: beql        $t4, $zero, L_80070C48
    if (ctx->r12 == 0) {
        // 0x80070B3C: lhu         $t4, 0x2($a2)
        ctx->r12 = MEM_HU(ctx->r6, 0X2);
            goto L_80070C48;
    }
    goto skip_0;
    // 0x80070B3C: lhu         $t4, 0x2($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X2);
    skip_0:
    // 0x80070B40: beql        $v0, $zero, L_80070B74
    if (ctx->r2 == 0) {
        // 0x80070B44: nop
    
            goto L_80070B74;
    }
    goto skip_1;
    // 0x80070B44: nop

    skip_1:
    // 0x80070B48: ori         $t4, $zero, 0xA
    ctx->r12 = 0 | 0XA;
    // 0x80070B4C: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070B50: ori         $t5, $zero, 0xA
    ctx->r13 = 0 | 0XA;
    // 0x80070B54: mflo        $t4
    ctx->r12 = lo;
    // 0x80070B58: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x80070B5C: nop

    // 0x80070B60: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070B64: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
    // 0x80070B68: mflo        $t5
    ctx->r13 = lo;
    // 0x80070B6C: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x80070B70: nop

L_80070B74:
    // 0x80070B74: lhu         $t5, 0x2($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X2);
    // 0x80070B78: lhu         $t4, 0xE($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0XE);
    // 0x80070B7C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80070B80: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
L_80070B84:
    // 0x80070B84: lh          $t5, 0x0($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X0);
    // 0x80070B88: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x80070B8C: lh          $t7, 0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X4);
    // 0x80070B90: mult        $t5, $t1
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070B94: lbu         $t8, 0x7($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X7);
    // 0x80070B98: lbu         $a3, 0x6($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X6);
    // 0x80070B9C: lbu         $t9, 0x8($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X8);
    // 0x80070BA0: sll         $t8, $t8, 16
    ctx->r24 = S32(ctx->r24 << 16);
    // 0x80070BA4: lbu         $v1, 0x9($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X9);
    // 0x80070BA8: or          $t8, $a3, $t8
    ctx->r24 = ctx->r7 | ctx->r24;
    // 0x80070BAC: mflo        $t5
    ctx->r13 = lo;
    // 0x80070BB0: nop

    // 0x80070BB4: nop

    // 0x80070BB8: mult        $t6, $t2
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070BBC: mflo        $t6
    ctx->r14 = lo;
    // 0x80070BC0: add         $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80070BC4: nop

    // 0x80070BC8: mult        $t7, $t3
    result = S64(S32(ctx->r15)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070BCC: mflo        $t7
    ctx->r15 = lo;
    // 0x80070BD0: add         $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x80070BD4: blez        $t5, L_80070BF4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80070BD8: nop
    
            goto L_80070BF4;
    }
    // 0x80070BD8: nop

    // 0x80070BDC: srl         $t5, $t5, 22
    ctx->r13 = S32(U32(ctx->r13) >> 22);
    // 0x80070BE0: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
    // 0x80070BE4: sltiu       $t5, $v1, 0x81
    ctx->r13 = ctx->r3 < 0X81 ? 1 : 0;
    // 0x80070BE8: bne         $t5, $zero, L_80070BF4
    if (ctx->r13 != 0) {
        // 0x80070BEC: nop
    
            goto L_80070BF4;
    }
    // 0x80070BEC: nop

    // 0x80070BF0: ori         $v1, $zero, 0x80
    ctx->r3 = 0 | 0X80;
L_80070BF4:
    // 0x80070BF4: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070BF8: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80070BFC: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80070C00: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x80070C04: mflo        $t8
    ctx->r24 = lo;
    // 0x80070C08: srl         $t8, $t8, 7
    ctx->r24 = S32(U32(ctx->r24) >> 7);
    // 0x80070C0C: sb          $t8, -0x4($a0)
    MEM_B(-0X4, ctx->r4) = ctx->r24;
    // 0x80070C10: multu       $v1, $t9
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070C14: srl         $t8, $t8, 16
    ctx->r24 = S32(U32(ctx->r24) >> 16);
    // 0x80070C18: sb          $t8, -0x3($a0)
    MEM_B(-0X3, ctx->r4) = ctx->r24;
    // 0x80070C1C: mflo        $t9
    ctx->r25 = lo;
    // 0x80070C20: srl         $t9, $t9, 7
    ctx->r25 = S32(U32(ctx->r25) >> 7);
    // 0x80070C24: sb          $t9, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r25;
    // 0x80070C28: bnel        $t4, $zero, L_80070B84
    if (ctx->r12 != 0) {
        // 0x80070C2C: nop
    
            goto L_80070B84;
    }
    goto skip_2;
    // 0x80070C2C: nop

    skip_2:
    // 0x80070C30: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80070C34: bnel        $t0, $zero, L_80070B30
    if (ctx->r8 != 0) {
        // 0x80070C38: nop
    
            goto L_80070B30;
    }
    goto skip_3;
    // 0x80070C38: nop

    skip_3:
    // 0x80070C3C: jr          $ra
    // 0x80070C40: nop

    return;
    // 0x80070C40: nop

    // 0x80070C44: lhu         $t4, 0x2($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X2);
L_80070C48:
    // 0x80070C48: lhu         $t5, 0xE($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0XE);
    // 0x80070C4C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80070C50: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80070C54: subu        $t4, $t5, $t4
    ctx->r12 = SUB32(ctx->r13, ctx->r12);
    // 0x80070C58: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x80070C5C: bnel        $t0, $zero, L_80070B30
    if (ctx->r8 != 0) {
        // 0x80070C60: nop
    
            goto L_80070B30;
    }
    goto skip_4;
    // 0x80070C60: nop

    skip_4:
    // 0x80070C64: jr          $ra
    // 0x80070C68: nop

    return;
    // 0x80070C68: nop

;}
RECOMP_FUNC void __initChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AE90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000AE94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000AE98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000AE9C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000AEA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000AEA4: lbu         $t6, 0x34($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X34);
    // 0x8000AEA8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000AEAC: blez        $t6, L_8000AEE4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000AEB0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000AEE4;
    }
    // 0x8000AEB0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000AEB4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000AEB8:
    // 0x8000AEB8: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
    // 0x8000AEBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000AEC0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8000AEC4: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8000AEC8: jal         0x8000ADF4
    // 0x8000AECC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __resetPerfChanState(rdram, ctx);
        goto after_0;
    // 0x8000AECC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8000AED0: lbu         $t9, 0x34($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X34);
    // 0x8000AED4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000AED8: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8000AEDC: bne         $at, $zero, L_8000AEB8
    if (ctx->r1 != 0) {
        // 0x8000AEE0: addiu       $s2, $s2, 0x14
        ctx->r18 = ADD32(ctx->r18, 0X14);
            goto L_8000AEB8;
    }
    // 0x8000AEE0: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
L_8000AEE4:
    // 0x8000AEE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000AEE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000AEEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AEF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000AEF4: jr          $ra
    // 0x8000AEF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000AEF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alCSeqSetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C80A0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800C80A4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C80A8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C80AC: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800C80B0: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800C80B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C80B8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C80BC: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x800C80C0: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x800C80C4: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800C80C8: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x800C80CC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_800C80D0:
    // 0x800C80D0: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x800C80D4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800C80D8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800C80DC: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x800C80E0: lw          $t1, 0x4C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4C);
    // 0x800C80E4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800C80E8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800C80EC: sw          $t1, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r9;
    // 0x800C80F0: lbu         $t2, 0x8C($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X8C);
    // 0x800C80F4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800C80F8: sb          $t2, 0x96($a3)
    MEM_B(0X96, ctx->r7) = ctx->r10;
    // 0x800C80FC: lbu         $t3, 0x9A($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X9A);
    // 0x800C8100: sb          $t3, 0xA6($a3)
    MEM_B(0XA6, ctx->r7) = ctx->r11;
    // 0x800C8104: lw          $t4, 0xA4($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XA4);
    // 0x800C8108: sw          $t4, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r12;
    // 0x800C810C: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x800C8110: sw          $t5, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r13;
    // 0x800C8114: lw          $t6, 0x48($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X48);
    // 0x800C8118: sw          $t6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r14;
    // 0x800C811C: lbu         $t7, 0x8B($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X8B);
    // 0x800C8120: sb          $t7, 0x97($a3)
    MEM_B(0X97, ctx->r7) = ctx->r15;
    // 0x800C8124: lbu         $t8, 0x9B($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X9B);
    // 0x800C8128: sb          $t8, 0xA7($a3)
    MEM_B(0XA7, ctx->r7) = ctx->r24;
    // 0x800C812C: lw          $t9, 0xA8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XA8);
    // 0x800C8130: bne         $v0, $a0, L_800C80D0
    if (ctx->r2 != ctx->r4) {
        // 0x800C8134: sw          $t9, 0xB4($v1)
        MEM_W(0XB4, ctx->r3) = ctx->r25;
            goto L_800C80D0;
    }
    // 0x800C8134: sw          $t9, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->r25;
    // 0x800C8138: jr          $ra
    // 0x800C813C: nop

    return;
    // 0x800C813C: nop

;}
RECOMP_FUNC void menu_cinematic_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B1D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009B1D8: lw          $t6, 0x6DA4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6DA4);
    // 0x8009B1DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B1E0: beq         $t6, $zero, L_8009B1FC
    if (ctx->r14 == 0) {
        // 0x8009B1E4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009B1FC;
    }
    // 0x8009B1E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B1E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B1EC: jal         0x8009CBB8
    // 0x8009B1F0: addiu       $a0, $a0, 0x1CE8
    ctx->r4 = ADD32(ctx->r4, 0X1CE8);
    menu_assetgroup_load(rdram, ctx);
        goto after_0;
    // 0x8009B1F0: addiu       $a0, $a0, 0x1CE8
    ctx->r4 = ADD32(ctx->r4, 0X1CE8);
    after_0:
    // 0x8009B1F4: jal         0x80094B08
    // 0x8009B1F8: nop

    menu_racer_portraits(rdram, ctx);
        goto after_1;
    // 0x8009B1F8: nop

    after_1:
L_8009B1FC:
    // 0x8009B1FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009B200: lw          $v0, 0x6D8C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6D8C);
    // 0x8009B204: nop

    // 0x8009B208: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x8009B20C: lb          $a1, 0x1($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X1);
    // 0x8009B210: lb          $a2, 0x2($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X2);
    // 0x8009B214: jal         0x8006E528
    // 0x8009B218: nop

    load_level_for_menu(rdram, ctx);
        goto after_2;
    // 0x8009B218: nop

    after_2:
    // 0x8009B21C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B224: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8009B228: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B22C: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x8009B230: jr          $ra
    // 0x8009B234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8009B234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void set_render_printf_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B68BC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B68C0: addiu       $a2, $a2, -0x7468
    ctx->r6 = ADD32(ctx->r6, -0X7468);
    // 0x800B68C4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B68C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B68CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B68D0: addiu       $t8, $zero, 0x82
    ctx->r24 = ADD32(0, 0X82);
    // 0x800B68D4: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800B68D8: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x800B68DC: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x800B68E0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B68E4: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x800B68E8: sb          $a0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r4;
    // 0x800B68EC: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800B68F0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800B68F4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B68F8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800B68FC: sra         $t7, $a0, 8
    ctx->r15 = S32(SIGNED(ctx->r4) >> 8);
    // 0x800B6900: sb          $t7, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r15;
    // 0x800B6904: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B6908: sra         $t6, $a1, 8
    ctx->r14 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800B690C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B6910: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x800B6914: sb          $a1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r5;
    // 0x800B6918: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800B691C: nop

    // 0x800B6920: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B6924: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800B6928: sb          $t6, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r14;
    // 0x800B692C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800B6930: nop

    // 0x800B6934: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B6938: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800B693C: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x800B6940: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x800B6944: nop

    // 0x800B6948: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B694C: jr          $ra
    // 0x800B6950: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    return;
    // 0x800B6950: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
;}
RECOMP_FUNC void render_3d_billboard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011C94: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80011C98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80011C9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80011CA0: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80011CA4: lw          $v1, 0x54($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X54);
    // 0x80011CA8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80011CAC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80011CB0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80011CB4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80011CB8: beq         $v1, $zero, L_80011D00
    if (ctx->r3 == 0) {
        // 0x80011CBC: ori         $t2, $t6, 0x108
        ctx->r10 = ctx->r14 | 0X108;
            goto L_80011D00;
    }
    // 0x80011CBC: ori         $t2, $t6, 0x108
    ctx->r10 = ctx->r14 | 0X108;
    // 0x80011CC0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80011CC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80011CC8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80011CCC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011CD0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80011CD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80011CD8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80011CDC: nop

    // 0x80011CE0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80011CE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80011CE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80011CEC: nop

    // 0x80011CF0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80011CF4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80011CF8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80011CFC: nop

L_80011D00:
    // 0x80011D00: lh          $v0, 0x48($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X48);
    // 0x80011D04: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80011D08: bne         $v0, $at, L_80011D50
    if (ctx->r2 != ctx->r1) {
        // 0x80011D0C: addiu       $t3, $zero, 0x5
        ctx->r11 = ADD32(0, 0X5);
            goto L_80011D50;
    }
    // 0x80011D0C: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80011D10: lbu         $v1, 0x39($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X39);
    // 0x80011D14: nop

    // 0x80011D18: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80011D1C: bne         $at, $zero, L_80011D34
    if (ctx->r1 != 0) {
        // 0x80011D20: nop
    
            goto L_80011D34;
    }
    // 0x80011D20: nop

    // 0x80011D24: lw          $t4, 0x7C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X7C);
    // 0x80011D28: lh          $v0, 0x48($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X48);
    // 0x80011D2C: b           L_80011D50
    // 0x80011D30: sb          $t4, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r12;
        goto L_80011D50;
    // 0x80011D30: sb          $t4, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r12;
L_80011D34:
    // 0x80011D34: lw          $t5, 0x7C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X7C);
    // 0x80011D38: lh          $v0, 0x48($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X48);
    // 0x80011D3C: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80011D40: multu       $v1, $t6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80011D44: mflo        $t7
    ctx->r15 = lo;
    // 0x80011D48: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80011D4C: sb          $t8, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r24;
L_80011D50:
    // 0x80011D50: lbu         $a1, 0x39($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X39);
    // 0x80011D54: addiu       $v1, $zero, 0x77
    ctx->r3 = ADD32(0, 0X77);
    // 0x80011D58: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80011D5C: bne         $at, $zero, L_80011D68
    if (ctx->r1 != 0) {
        // 0x80011D60: ori         $t4, $t2, 0x4
        ctx->r12 = ctx->r10 | 0X4;
            goto L_80011D68;
    }
    // 0x80011D60: ori         $t4, $t2, 0x4
    ctx->r12 = ctx->r10 | 0X4;
    // 0x80011D64: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_80011D68:
    // 0x80011D68: bne         $v1, $v0, L_80011D74
    if (ctx->r3 != ctx->r2) {
        // 0x80011D6C: sra         $t9, $a1, 1
        ctx->r25 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80011D74;
    }
    // 0x80011D6C: sra         $t9, $a1, 1
    ctx->r25 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80011D70: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_80011D74:
    // 0x80011D74: slti        $at, $a1, 0xFF
    ctx->r1 = SIGNED(ctx->r5) < 0XFF ? 1 : 0;
    // 0x80011D78: beq         $at, $zero, L_80011D88
    if (ctx->r1 == 0) {
        // 0x80011D7C: nop
    
            goto L_80011D88;
    }
    // 0x80011D7C: nop

    // 0x80011D80: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x80011D84: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80011D88:
    // 0x80011D88: bne         $t3, $v0, L_80011DFC
    if (ctx->r11 != ctx->r2) {
        // 0x80011D8C: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_80011DFC;
    }
    // 0x80011D8C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80011D90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80011D94: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80011D98: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80011D9C: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x80011DA0: addiu       $s0, $s0, -0x4BF4
    ctx->r16 = ADD32(ctx->r16, -0X4BF4);
    // 0x80011DA4: bc1f        L_80011DFC
    if (!c1cs) {
        // 0x80011DA8: lui         $t6, 0xFA00
        ctx->r14 = S32(0XFA00 << 16);
            goto L_80011DFC;
    }
    // 0x80011DA8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80011DAC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011DB0: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80011DB4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80011DB8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80011DBC: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80011DC0: sra         $t9, $t7, 2
    ctx->r25 = S32(SIGNED(ctx->r15) >> 2);
    // 0x80011DC4: sll         $t4, $t9, 24
    ctx->r12 = S32(ctx->r25 << 24);
    // 0x80011DC8: andi        $t5, $a2, 0xFF
    ctx->r13 = ctx->r6 & 0XFF;
    // 0x80011DCC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80011DD0: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80011DD4: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80011DD8: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80011DDC: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80011DE0: sll         $t5, $t9, 8
    ctx->r13 = S32(ctx->r25 << 8);
    // 0x80011DE4: or          $t4, $t7, $t5
    ctx->r12 = ctx->r15 | ctx->r13;
    // 0x80011DE8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80011DEC: or          $t8, $t4, $t6
    ctx->r24 = ctx->r12 | ctx->r14;
    // 0x80011DF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011DF4: b           L_80011EAC
    // 0x80011DF8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_80011EAC;
    // 0x80011DF8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_80011DFC:
    // 0x80011DFC: bne         $v1, $v0, L_80011E38
    if (ctx->r3 != ctx->r2) {
        // 0x80011E00: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80011E38;
    }
    // 0x80011E00: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80011E04: addiu       $s0, $s0, -0x4BF4
    ctx->r16 = ADD32(ctx->r16, -0X4BF4);
    // 0x80011E08: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011E0C: lui         $at, 0x96E6
    ctx->r1 = S32(0X96E6 << 16);
    // 0x80011E10: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x80011E14: andi        $t5, $a1, 0xFF
    ctx->r13 = ctx->r5 & 0XFF;
    // 0x80011E18: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80011E1C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80011E20: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x80011E24: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80011E28: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011E2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80011E30: b           L_80011EAC
    // 0x80011E34: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
        goto L_80011EAC;
    // 0x80011E34: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_80011E38:
    // 0x80011E38: bne         $t0, $zero, L_80011E48
    if (ctx->r8 != 0) {
        // 0x80011E3C: slti        $at, $a1, 0xFF
        ctx->r1 = SIGNED(ctx->r5) < 0XFF ? 1 : 0;
            goto L_80011E48;
    }
    // 0x80011E3C: slti        $at, $a1, 0xFF
    ctx->r1 = SIGNED(ctx->r5) < 0XFF ? 1 : 0;
    // 0x80011E40: beq         $at, $zero, L_80011E8C
    if (ctx->r1 == 0) {
        // 0x80011E44: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80011E8C;
    }
    // 0x80011E44: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
L_80011E48:
    // 0x80011E48: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80011E4C: addiu       $s0, $s0, -0x4BF4
    ctx->r16 = ADD32(ctx->r16, -0X4BF4);
    // 0x80011E50: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011E54: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x80011E58: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80011E5C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80011E60: sll         $t9, $v1, 24
    ctx->r25 = S32(ctx->r3 << 24);
    // 0x80011E64: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x80011E68: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80011E6C: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x80011E70: sll         $t4, $v1, 8
    ctx->r12 = S32(ctx->r3 << 8);
    // 0x80011E74: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80011E78: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80011E7C: or          $t6, $t5, $t4
    ctx->r14 = ctx->r13 | ctx->r12;
    // 0x80011E80: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80011E84: b           L_80011EAC
    // 0x80011E88: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
        goto L_80011EAC;
    // 0x80011E88: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80011E8C:
    // 0x80011E8C: addiu       $s0, $s0, -0x4BF4
    ctx->r16 = ADD32(ctx->r16, -0X4BF4);
    // 0x80011E90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011E94: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80011E98: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80011E9C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80011EA0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80011EA4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80011EA8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80011EAC:
    // 0x80011EAC: beq         $t1, $zero, L_80011F00
    if (ctx->r9 == 0) {
        // 0x80011EB0: nop
    
            goto L_80011F00;
    }
    // 0x80011EB0: nop

    // 0x80011EB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011EB8: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80011EBC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80011EC0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80011EC4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80011EC8: lw          $v1, 0x54($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X54);
    // 0x80011ECC: nop

    // 0x80011ED0: lbu         $t7, 0x4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4);
    // 0x80011ED4: lbu         $t6, 0x5($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X5);
    // 0x80011ED8: lbu         $t4, 0x6($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X6);
    // 0x80011EDC: sll         $t5, $t7, 24
    ctx->r13 = S32(ctx->r15 << 24);
    // 0x80011EE0: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80011EE4: lbu         $t7, 0x7($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X7);
    // 0x80011EE8: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x80011EEC: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x80011EF0: or          $t5, $t9, $t6
    ctx->r13 = ctx->r25 | ctx->r14;
    // 0x80011EF4: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x80011EF8: b           L_80011F50
    // 0x80011EFC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
        goto L_80011F50;
    // 0x80011EFC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_80011F00:
    // 0x80011F00: lh          $t9, 0x48($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X48);
    // 0x80011F04: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80011F08: bne         $t9, $at, L_80011F38
    if (ctx->r25 != ctx->r1) {
        // 0x80011F0C: lui         $t4, 0xFB00
        ctx->r12 = S32(0XFB00 << 16);
            goto L_80011F38;
    }
    // 0x80011F0C: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x80011F10: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011F14: lui         $t5, 0xFFFF
    ctx->r13 = S32(0XFFFF << 16);
    // 0x80011F18: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80011F1C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80011F20: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x80011F24: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80011F28: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80011F2C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80011F30: b           L_80011F50
    // 0x80011F34: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_80011F50;
    // 0x80011F34: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_80011F38:
    // 0x80011F38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011F3C: addiu       $t9, $zero, -0x100
    ctx->r25 = ADD32(0, -0X100);
    // 0x80011F40: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80011F44: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80011F48: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80011F4C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_80011F50:
    // 0x80011F50: lb          $t8, 0x3A($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X3A);
    // 0x80011F54: lw          $t6, 0x68($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X68);
    // 0x80011F58: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80011F5C: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x80011F60: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80011F64: addiu       $at, $zero, 0x74
    ctx->r1 = ADD32(0, 0X74);
    // 0x80011F68: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x80011F6C: lh          $v0, 0x48($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X48);
    // 0x80011F70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011F74: bne         $v0, $at, L_80011F90
    if (ctx->r2 != ctx->r1) {
        // 0x80011F78: nop
    
            goto L_80011F90;
    }
    // 0x80011F78: nop

    // 0x80011F7C: lw          $t9, 0x7C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X7C);
    // 0x80011F80: lw          $a0, 0x78($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X78);
    // 0x80011F84: blez        $t9, L_80011F90
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80011F88: nop
    
            goto L_80011F90;
    }
    // 0x80011F88: nop

    // 0x80011F8C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80011F90:
    // 0x80011F90: bne         $a0, $zero, L_80011FB8
    if (ctx->r4 != 0) {
        // 0x80011F94: nop
    
            goto L_80011FB8;
    }
    // 0x80011F94: nop

    // 0x80011F98: bne         $t3, $v0, L_8001203C
    if (ctx->r11 != ctx->r2) {
        // 0x80011F9C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8001203C;
    }
    // 0x80011F9C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80011FA0: lw          $t8, 0x64($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X64);
    // 0x80011FA4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80011FA8: lbu         $t6, 0x18($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X18);
    // 0x80011FAC: nop

    // 0x80011FB0: bne         $t6, $at, L_80012040
    if (ctx->r14 != ctx->r1) {
        // 0x80011FB4: lw          $t9, 0x58($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X58);
            goto L_80012040;
    }
    // 0x80011FB4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80011FB8:
    // 0x80011FB8: sh          $zero, 0x64($sp)
    MEM_H(0X64, ctx->r29) = 0;
    // 0x80011FBC: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x80011FC0: sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
    // 0x80011FC4: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80011FC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80011FCC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80011FD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80011FD4: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x80011FD8: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x80011FDC: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x80011FE0: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x80011FE4: lh          $t5, 0x18($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X18);
    // 0x80011FE8: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80011FEC: sh          $t7, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r15;
    // 0x80011FF0: bne         $a0, $zero, L_80012014
    if (ctx->r4 != 0) {
        // 0x80011FF4: sh          $t5, 0x78($sp)
        MEM_H(0X78, ctx->r29) = ctx->r13;
            goto L_80012014;
    }
    // 0x80011FF4: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x80011FF8: lw          $t4, 0x64($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X64);
    // 0x80011FFC: nop

    // 0x80012000: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80012004: nop

    // 0x80012008: bne         $a0, $zero, L_80012018
    if (ctx->r4 != 0) {
        // 0x8001200C: lw          $a1, 0x58($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X58);
            goto L_80012018;
    }
    // 0x8001200C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80012010: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80012014:
    // 0x80012014: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
L_80012018:
    // 0x80012018: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    // 0x8001201C: addiu       $a3, $zero, 0x106
    ctx->r7 = ADD32(0, 0X106);
    // 0x80012020: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x80012024: jal         0x800138A8
    // 0x80012028: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    render_bubble_trap(rdram, ctx);
        goto after_0;
    // 0x80012028: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    after_0:
    // 0x8001202C: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80012030: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80012034: b           L_80012070
    // 0x80012038: nop

        goto L_80012070;
    // 0x80012038: nop

L_8001203C:
    // 0x8001203C: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80012040:
    // 0x80012040: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80012044: addiu       $a2, $a2, -0x4BEC
    ctx->r6 = ADD32(ctx->r6, -0X4BEC);
    // 0x80012048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001204C: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x80012050: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80012054: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x80012058: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x8001205C: jal         0x80068754
    // 0x80012060: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    render_sprite_billboard(rdram, ctx);
        goto after_1;
    // 0x80012060: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x80012064: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80012068: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8001206C: nop

L_80012070:
    // 0x80012070: beq         $t0, $zero, L_80012094
    if (ctx->r8 == 0) {
        // 0x80012074: nop
    
            goto L_80012094;
    }
    // 0x80012074: nop

    // 0x80012078: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8001207C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80012080: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80012084: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80012088: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8001208C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80012090: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80012094:
    // 0x80012094: beq         $t1, $zero, L_800120BC
    if (ctx->r9 == 0) {
        // 0x80012098: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800120BC;
    }
    // 0x80012098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001209C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800120A0: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x800120A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800120A8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800120AC: addiu       $t9, $zero, -0x100
    ctx->r25 = ADD32(0, -0X100);
    // 0x800120B0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800120B4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800120B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800120BC:
    // 0x800120BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800120C0: jr          $ra
    // 0x800120C4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800120C4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void music_channel_get_mask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000105C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001060: lw          $t6, -0x3460($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3460);
    // 0x80001064: nop

    // 0x80001068: lhu         $v0, 0x30($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X30);
    // 0x8000106C: jr          $ra
    // 0x80001070: nop

    return;
    // 0x80001070: nop

;}
RECOMP_FUNC void get_game_data_file_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073EA4: jr          $ra
    // 0x80073EA8: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    return;
    // 0x80073EA8: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
;}
RECOMP_FUNC void get_racer_objects_by_port(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BAC4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001BAC8: lw          $t6, -0x4B90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B90);
    // 0x8001BACC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BAD0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BAD4: lw          $v0, -0x4B94($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4B94);
    // 0x8001BAD8: jr          $ra
    // 0x8001BADC: nop

    return;
    // 0x8001BADC: nop

;}
RECOMP_FUNC void timetrial_free_staff_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059B9C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80059BA0: lw          $a0, -0x24E8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X24E8);
    // 0x80059BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059BA8: beq         $a0, $zero, L_80059BB8
    if (ctx->r4 == 0) {
        // 0x80059BAC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80059BB8;
    }
    // 0x80059BAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059BB0: jal         0x80071380
    // 0x80059BB4: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x80059BB4: nop

    after_0:
L_80059BB8:
    // 0x80059BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059BBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059BC0: sw          $zero, -0x24E8($at)
    MEM_W(-0X24E8, ctx->r1) = 0;
    // 0x80059BC4: jr          $ra
    // 0x80059BC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80059BC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void get_checkpoint_node(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA34: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x8001BA38: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001BA3C: lw          $t7, -0x4BB4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4BB4);
    // 0x8001BA40: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8001BA44: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001BA48: jr          $ra
    // 0x8001BA4C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    return;
    // 0x8001BA4C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
;}
RECOMP_FUNC void get_track_id_to_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C6F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C6F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C6FC: jal         0x8006ECD0
    // 0x8009C700: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009C700: nop

    after_0:
    // 0x8009C704: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009C708: lw          $t6, -0x5C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C8);
    // 0x8009C70C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8009C710: bne         $t6, $zero, L_8009C74C
    if (ctx->r14 != 0) {
        // 0x8009C714: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_8009C74C;
    }
    // 0x8009C714: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009C718: lw          $t7, -0x608($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X608);
    // 0x8009C71C: nop

    // 0x8009C720: bne         $t7, $zero, L_8009C74C
    if (ctx->r15 != 0) {
        // 0x8009C724: nop
    
            goto L_8009C74C;
    }
    // 0x8009C724: nop

    // 0x8009C728: lbu         $t8, 0x4B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4B);
    // 0x8009C72C: nop

    // 0x8009C730: beq         $t8, $zero, L_8009C740
    if (ctx->r24 == 0) {
        // 0x8009C734: nop
    
            goto L_8009C740;
    }
    // 0x8009C734: nop

    // 0x8009C738: b           L_8009C75C
    // 0x8009C73C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009C75C;
    // 0x8009C73C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009C740:
    // 0x8009C740: lbu         $v0, 0x49($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X49);
    // 0x8009C744: b           L_8009C760
    // 0x8009C748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009C760;
    // 0x8009C748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009C74C:
    // 0x8009C74C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C750: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C754: lw          $v0, -0x5AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5AC);
    // 0x8009C758: sw          $zero, -0x608($at)
    MEM_W(-0X608, ctx->r1) = 0;
L_8009C75C:
    // 0x8009C75C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009C760:
    // 0x8009C760: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C764: jr          $ra
    // 0x8009C768: nop

    return;
    // 0x8009C768: nop

;}
RECOMP_FUNC void race_starting(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A06D0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A06D4: lbu         $v0, 0x72F4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F4);
    // 0x800A06D8: jr          $ra
    // 0x800A06DC: nop

    return;
    // 0x800A06DC: nop

;}
RECOMP_FUNC void viewport_menu_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066B80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80066B84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80066B88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066B8C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80066B90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80066B94: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80066B98: jal         0x8007A970
    // 0x80066B9C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80066B9C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80066BA0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80066BA4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80066BA8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80066BAC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80066BB0: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80066BB4: beq         $at, $zero, L_80066BC8
    if (ctx->r1 == 0) {
        // 0x80066BB8: andi        $a0, $v0, 0xFFFF
        ctx->r4 = ctx->r2 & 0XFFFF;
            goto L_80066BC8;
    }
    // 0x80066BB8: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80066BBC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80066BC0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80066BC4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_80066BC8:
    // 0x80066BC8: slt         $at, $a2, $s0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80066BCC: beq         $at, $zero, L_80066BDC
    if (ctx->r1 == 0) {
        // 0x80066BD0: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80066BDC;
    }
    // 0x80066BD0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80066BD4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80066BD8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_80066BDC:
    // 0x80066BDC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80066BE0: beq         $at, $zero, L_80066C04
    if (ctx->r1 == 0) {
        // 0x80066BE4: sll         $t7, $t0, 2
        ctx->r15 = S32(ctx->r8 << 2);
            goto L_80066C04;
    }
    // 0x80066BE4: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80066BE8: bltz        $a3, L_80066C04
    if (SIGNED(ctx->r7) < 0) {
        // 0x80066BEC: sra         $v1, $v0, 16
        ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
            goto L_80066C04;
    }
    // 0x80066BEC: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80066BF0: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x80066BF4: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80066BF8: beq         $at, $zero, L_80066C04
    if (ctx->r1 == 0) {
        // 0x80066BFC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80066C04;
    }
    // 0x80066BFC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80066C00: bgez        $a2, L_80066C34
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80066C04: subu        $t7, $t7, $t0
        ctx->r15 = SUB32(ctx->r15, ctx->r8);
            goto L_80066C34;
    }
L_80066C04:
    // 0x80066C04: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80066C08: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80066C0C: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x80066C10: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80066C14: addiu       $t8, $t8, -0x2A2C
    ctx->r24 = ADD32(ctx->r24, -0X2A2C);
    // 0x80066C18: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80066C1C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80066C20: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80066C24: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80066C28: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x80066C2C: b           L_80066CC8
    // 0x80066C30: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
        goto L_80066CC8;
    // 0x80066C30: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
L_80066C34:
    // 0x80066C34: bgez        $a1, L_80066C64
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80066C38: slt         $at, $a3, $a0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80066C64;
    }
    // 0x80066C38: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80066C3C: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80066C40: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x80066C44: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80066C48: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x80066C4C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80066C50: addiu       $t1, $t1, -0x2A2C
    ctx->r9 = ADD32(ctx->r9, -0X2A2C);
    // 0x80066C54: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80066C58: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x80066C5C: b           L_80066C88
    // 0x80066C60: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
        goto L_80066C88;
    // 0x80066C60: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
L_80066C64:
    // 0x80066C64: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80066C68: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x80066C6C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80066C70: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x80066C74: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80066C78: addiu       $t3, $t3, -0x2A2C
    ctx->r11 = ADD32(ctx->r11, -0X2A2C);
    // 0x80066C7C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80066C80: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80066C84: sw          $a1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r5;
L_80066C88:
    // 0x80066C88: bgez        $s0, L_80066C98
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80066C8C: nop
    
            goto L_80066C98;
    }
    // 0x80066C8C: nop

    // 0x80066C90: b           L_80066C9C
    // 0x80066C94: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
        goto L_80066C9C;
    // 0x80066C94: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
L_80066C98:
    // 0x80066C98: sw          $s0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r16;
L_80066C9C:
    // 0x80066C9C: bne         $at, $zero, L_80066CAC
    if (ctx->r1 != 0) {
        // 0x80066CA0: addiu       $t4, $a0, -0x1
        ctx->r12 = ADD32(ctx->r4, -0X1);
            goto L_80066CAC;
    }
    // 0x80066CA0: addiu       $t4, $a0, -0x1
    ctx->r12 = ADD32(ctx->r4, -0X1);
    // 0x80066CA4: b           L_80066CB0
    // 0x80066CA8: sw          $t4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r12;
        goto L_80066CB0;
    // 0x80066CA8: sw          $t4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r12;
L_80066CAC:
    // 0x80066CAC: sw          $a3, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r7;
L_80066CB0:
    // 0x80066CB0: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80066CB4: bne         $at, $zero, L_80066CC4
    if (ctx->r1 != 0) {
        // 0x80066CB8: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_80066CC4;
    }
    // 0x80066CB8: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80066CBC: b           L_80066CC8
    // 0x80066CC0: sw          $t5, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r13;
        goto L_80066CC8;
    // 0x80066CC0: sw          $t5, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r13;
L_80066CC4:
    // 0x80066CC4: sw          $a2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r6;
L_80066CC8:
    // 0x80066CC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80066CCC: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x80066CD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066CD4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80066CD8: sw          $a3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r7;
    // 0x80066CDC: sw          $a2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r6;
    // 0x80066CE0: jr          $ra
    // 0x80066CE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80066CE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void minimap_marker_pos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA948: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AA94C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA950: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x800AA954: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x800AA958: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800AA95C: jal         0x8002C804
    // 0x800AA960: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x800AA960: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800AA964: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800AA968: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AA96C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800AA970: lh          $v1, 0x3C($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X3C);
    // 0x800AA974: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AA978: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800AA97C: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800AA980: lh          $t6, 0x3E($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X3E);
    // 0x800AA984: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AA988: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800AA98C: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
    // 0x800AA990: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AA994: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800AA998: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800AA99C: lh          $a0, 0x44($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X44);
    // 0x800AA9A0: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800AA9A4: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x800AA9A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AA9AC: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800AA9B0: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AA9B4: lh          $t7, 0x46($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X46);
    // 0x800AA9B8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800AA9BC: div.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800AA9C0: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x800AA9C4: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800AA9C8: subu        $a3, $t7, $a0
    ctx->r7 = SUB32(ctx->r15, ctx->r4);
    // 0x800AA9CC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800AA9D0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AA9D4: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x800AA9D8: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800AA9DC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800AA9E0: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AA9E4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AA9E8: nop

    // 0x800AA9EC: div.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800AA9F0: jal         0x8009C850
    // 0x800AA9F4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    get_filtered_cheats(rdram, ctx);
        goto after_1;
    // 0x800AA9F4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x800AA9F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800AA9FC: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AAA00: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800AAA04: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800AAA08: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800AAA0C: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x800AAA10: beq         $t8, $zero, L_800AAAB4
    if (ctx->r24 == 0) {
        // 0x800AAA14: nop
    
            goto L_800AAAB4;
    }
    // 0x800AAA14: nop

    // 0x800AAA18: mul.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800AAA1C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AAA20: lw          $t9, 0x7318($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7318);
    // 0x800AAA24: lh          $t0, 0x34($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X34);
    // 0x800AAA28: mul.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800AAA2C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800AAA30: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AAA34: lw          $t1, 0x72DC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X72DC);
    // 0x800AAA38: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AAA3C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AAA40: addiu       $v0, $v0, 0x729C
    ctx->r2 = ADD32(ctx->r2, 0X729C);
    // 0x800AAA44: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800AAA48: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800AAA4C: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800AAA50: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800AAA54: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AAA58: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800AAA5C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AAA60: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AAA64: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800AAA68: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AAA6C: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800AAA70: swc1        $f18, 0x1EC($t2)
    MEM_W(0X1EC, ctx->r10) = ctx->f18.u32l;
    // 0x800AAA74: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800AAA78: lw          $t4, 0x731C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X731C);
    // 0x800AAA7C: lh          $t3, 0x36($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X36);
    // 0x800AAA80: lw          $t6, 0x72E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72E0);
    // 0x800AAA84: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800AAA88: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800AAA8C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800AAA90: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800AAA94: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AAA98: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800AAA9C: sub.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800AAAA0: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AAAA4: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800AAAA8: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AAAAC: b           L_800AAB4C
    // 0x800AAAB0: swc1        $f10, 0x1F0($t7)
    MEM_W(0X1F0, ctx->r15) = ctx->f10.u32l;
        goto L_800AAB4C;
    // 0x800AAAB0: swc1        $f10, 0x1F0($t7)
    MEM_W(0X1F0, ctx->r15) = ctx->f10.u32l;
L_800AAAB4:
    // 0x800AAAB4: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800AAAB8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800AAABC: lw          $t8, 0x7318($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7318);
    // 0x800AAAC0: lh          $t9, 0x30($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X30);
    // 0x800AAAC4: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800AAAC8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800AAACC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800AAAD0: lw          $t0, 0x72DC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X72DC);
    // 0x800AAAD4: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AAAD8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AAADC: addiu       $v0, $v0, 0x729C
    ctx->r2 = ADD32(ctx->r2, 0X729C);
    // 0x800AAAE0: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800AAAE4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800AAAE8: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800AAAEC: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800AAAF0: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AAAF4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800AAAF8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AAAFC: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AAB00: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AAB04: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800AAB08: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800AAB0C: swc1        $f8, 0x1EC($t1)
    MEM_W(0X1EC, ctx->r9) = ctx->f8.u32l;
    // 0x800AAB10: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800AAB14: lw          $t3, 0x731C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X731C);
    // 0x800AAB18: lh          $t2, 0x32($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X32);
    // 0x800AAB1C: lw          $t5, 0x72E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72E0);
    // 0x800AAB20: mul.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800AAB24: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800AAB28: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800AAB2C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800AAB30: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AAB34: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800AAB38: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800AAB3C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AAB40: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800AAB44: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AAB48: swc1        $f18, 0x1F0($t6)
    MEM_W(0X1F0, ctx->r14) = ctx->f18.u32l;
L_800AAB4C:
    // 0x800AAB4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AAB50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800AAB54: jr          $ra
    // 0x800AAB58: nop

    return;
    // 0x800AAB58: nop

;}
RECOMP_FUNC void titlescreen_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084558: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008455C: jal         0x8009C9EC
    // 0x80084560: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x80084560: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    after_0:
    // 0x80084564: jal         0x80000BE0
    // 0x80084568: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    music_voicelimit_set(rdram, ctx);
        goto after_1;
    // 0x80084568: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x8008456C: jal         0x80066310
    // 0x80084570: nop

    cam_shake_on(rdram, ctx);
        goto after_2;
    // 0x80084570: nop

    after_2:
    // 0x80084574: jal         0x800C478C
    // 0x80084578: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_3;
    // 0x80084578: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x8008457C: jal         0x80000890
    // 0x80084580: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sound_volume_reset(rdram, ctx);
        goto after_4;
    // 0x80084580: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80084584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008458C: jr          $ra
    // 0x80084590: nop

    return;
    // 0x80084590: nop

;}
RECOMP_FUNC void transition_render_blank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2E08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2E0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2E10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C2E14: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C2E18: jal         0x8007A970
    // 0x800C2E1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800C2E1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C2E20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C2E24: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C2E28: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C2E2C: addiu       $t8, $t8, 0x3768
    ctx->r24 = ADD32(ctx->r24, 0X3768);
    // 0x800C2E30: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C2E34: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C2E38: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C2E3C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C2E40: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C2E44: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C2E48: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x800C2E4C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800C2E50: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C2E54: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C2E58: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800C2E5C: lw          $t2, -0x5308($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5308);
    // 0x800C2E60: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C2E64: sra         $t4, $t2, 16
    ctx->r12 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800C2E68: lw          $t6, -0x5304($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5304);
    // 0x800C2E6C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C2E70: lw          $t2, -0x5300($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5300);
    // 0x800C2E74: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800C2E78: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800C2E7C: sll         $t5, $t4, 24
    ctx->r13 = S32(ctx->r12 << 24);
    // 0x800C2E80: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800C2E84: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800C2E88: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C2E8C: or          $t1, $t5, $t9
    ctx->r9 = ctx->r13 | ctx->r25;
    // 0x800C2E90: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x800C2E94: or          $t7, $t1, $t6
    ctx->r15 = ctx->r9 | ctx->r14;
    // 0x800C2E98: ori         $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 | 0XFF;
    // 0x800C2E9C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C2EA0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C2EA4: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x800C2EA8: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800C2EAC: lui         $t2, 0xFFFD
    ctx->r10 = S32(0XFFFD << 16);
    // 0x800C2EB0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800C2EB4: ori         $t2, $t2, 0xF6FB
    ctx->r10 = ctx->r10 | 0XF6FB;
    // 0x800C2EB8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800C2EBC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800C2EC0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800C2EC4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C2EC8: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C2ECC: andi        $t1, $v0, 0x3FF
    ctx->r9 = ctx->r2 & 0X3FF;
    // 0x800C2ED0: sll         $t6, $t1, 14
    ctx->r14 = S32(ctx->r9 << 14);
    // 0x800C2ED4: andi        $t9, $t5, 0x3FF
    ctx->r25 = ctx->r13 & 0X3FF;
    // 0x800C2ED8: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800C2EDC: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800C2EE0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800C2EE4: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800C2EE8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800C2EEC: or          $t3, $t7, $t2
    ctx->r11 = ctx->r15 | ctx->r10;
    // 0x800C2EF0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800C2EF4: jal         0x8007B820
    // 0x800C2EF8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C2EF8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    after_1:
    // 0x800C2EFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2F00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2F04: jr          $ra
    // 0x800C2F08: nop

    return;
    // 0x800C2F08: nop

;}
RECOMP_FUNC void menu_results_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096D4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80096D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096D54: jal         0x8006ECD0
    // 0x80096D58: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x80096D58: nop

    after_0:
    // 0x80096D5C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80096D60: lw          $v1, -0x5E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E0);
    // 0x80096D64: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80096D68: lw          $t6, 0x60($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X60);
    // 0x80096D6C: addiu       $a0, $a0, 0x71B0
    ctx->r4 = ADD32(ctx->r4, 0X71B0);
    // 0x80096D70: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80096D74: lw          $t7, 0x5C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X5C);
    // 0x80096D78: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80096D7C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80096D80: lw          $t8, 0x70($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X70);
    // 0x80096D84: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80096D88: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x80096D8C: lw          $a3, -0x5C4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5C4);
    // 0x80096D90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096D94: sw          $t9, 0x71D4($at)
    MEM_W(0X71D4, ctx->r1) = ctx->r25;
    // 0x80096D98: blez        $a3, L_80096DE0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80096D9C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80096DE0;
    }
    // 0x80096D9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80096DA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80096DA4:
    // 0x80096DA4: lb          $a2, 0x5A($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X5A);
    // 0x80096DA8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80096DAC: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80096DB0: beq         $at, $zero, L_80096DD4
    if (ctx->r1 == 0) {
        // 0x80096DB4: sll         $t0, $a2, 1
        ctx->r8 = S32(ctx->r6 << 1);
            goto L_80096DD4;
    }
    // 0x80096DB4: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x80096DB8: addu        $v1, $a0, $t0
    ctx->r3 = ADD32(ctx->r4, ctx->r8);
    // 0x80096DBC: lhu         $t1, 0x5C($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X5C);
    // 0x80096DC0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80096DC4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80096DC8: sh          $t2, 0x5C($v1)
    MEM_H(0X5C, ctx->r3) = ctx->r10;
    // 0x80096DCC: lw          $a3, -0x5C4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5C4);
    // 0x80096DD0: nop

L_80096DD4:
    // 0x80096DD4: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80096DD8: bne         $at, $zero, L_80096DA4
    if (ctx->r1 != 0) {
        // 0x80096DDC: addiu       $a0, $a0, 0x18
        ctx->r4 = ADD32(ctx->r4, 0X18);
            goto L_80096DA4;
    }
    // 0x80096DDC: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
L_80096DE0:
    // 0x80096DE0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80096DE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096DE8: sw          $t3, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r11;
    // 0x80096DEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096DF0: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x80096DF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096DF8: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    // 0x80096DFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096E00: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x80096E04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096E08: sw          $zero, 0x7028($at)
    MEM_W(0X7028, ctx->r1) = 0;
    // 0x80096E0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096E10: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80096E14: sw          $t4, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = ctx->r12;
    // 0x80096E18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096E1C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096E20: sw          $zero, 0xF08($at)
    MEM_W(0XF08, ctx->r1) = 0;
    // 0x80096E24: jal         0x8009CBB8
    // 0x80096E28: addiu       $a0, $a0, 0xFA4
    ctx->r4 = ADD32(ctx->r4, 0XFA4);
    menu_assetgroup_load(rdram, ctx);
        goto after_1;
    // 0x80096E28: addiu       $a0, $a0, 0xFA4
    ctx->r4 = ADD32(ctx->r4, 0XFA4);
    after_1:
    // 0x80096E2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096E30: jal         0x8009CDE8
    // 0x80096E34: addiu       $a0, $a0, 0xFC0
    ctx->r4 = ADD32(ctx->r4, 0XFC0);
    menu_imagegroup_load(rdram, ctx);
        goto after_2;
    // 0x80096E34: addiu       $a0, $a0, 0xFC0
    ctx->r4 = ADD32(ctx->r4, 0XFC0);
    after_2:
    // 0x80096E38: jal         0x80094B08
    // 0x80096E3C: nop

    menu_racer_portraits(rdram, ctx);
        goto after_3;
    // 0x80096E3C: nop

    after_3:
    // 0x80096E40: jal         0x800C46D0
    // 0x80096E44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_4;
    // 0x80096E44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80096E48: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096E4C: jal         0x800C06F8
    // 0x80096E50: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_5;
    // 0x80096E50: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_5:
    // 0x80096E54: jal         0x80000BE0
    // 0x80096E58: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_6;
    // 0x80096E58: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_6:
    // 0x80096E5C: jal         0x80000B34
    // 0x80096E60: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_7;
    // 0x80096E60: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_7:
    // 0x80096E64: jal         0x80000C98
    // 0x80096E68: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    music_fade(rdram, ctx);
        goto after_8;
    // 0x80096E68: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_8:
    // 0x80096E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096E70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80096E74: jr          $ra
    // 0x80096E78: nop

    return;
    // 0x80096E78: nop

;}
RECOMP_FUNC void charselect_render_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B6C4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008B6C8: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008B6CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B6D0: slti        $at, $v0, -0x16
    ctx->r1 = SIGNED(ctx->r2) < -0X16 ? 1 : 0;
    // 0x8008B6D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008B6D8: bne         $at, $zero, L_8008B800
    if (ctx->r1 != 0) {
        // 0x8008B6DC: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8008B800;
    }
    // 0x8008B6DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008B6E0: slti        $at, $v0, 0x17
    ctx->r1 = SIGNED(ctx->r2) < 0X17 ? 1 : 0;
    // 0x8008B6E4: beq         $at, $zero, L_8008B804
    if (ctx->r1 == 0) {
        // 0x8008B6E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008B804;
    }
    // 0x8008B6E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B6EC: jal         0x800C484C
    // 0x8008B6F0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_0;
    // 0x8008B6F0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008B6F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008B6F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008B6FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008B700: jal         0x800C492C
    // 0x8008B704: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_1;
    // 0x8008B704: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8008B708: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8008B70C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008B710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008B714: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008B718: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008B71C: jal         0x800C48E4
    // 0x8008B720: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x8008B720: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x8008B724: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008B728: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x8008B72C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B730: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8008B734: lw          $a3, 0x21C($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X21C);
    // 0x8008B738: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008B73C: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8008B740: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x8008B744: jal         0x800C49A0
    // 0x8008B748: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_3;
    // 0x8008B748: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_3:
    // 0x8008B74C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008B750: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8008B754: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008B758: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008B75C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008B760: jal         0x800C48E4
    // 0x8008B764: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x8008B764: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8008B768: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008B76C: lw          $t0, -0x5E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E0);
    // 0x8008B770: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B774: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8008B778: lw          $a3, 0x21C($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X21C);
    // 0x8008B77C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008B780: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8008B784: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008B788: jal         0x800C49A0
    // 0x8008B78C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x8008B78C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_5:
    // 0x8008B790: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008B794: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008B798: lw          $t2, -0x600($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X600);
    // 0x8008B79C: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x8008B7A0: nop

    // 0x8008B7A4: bne         $v0, $t2, L_8008B7E4
    if (ctx->r2 != ctx->r10) {
        // 0x8008B7A8: nop
    
            goto L_8008B7E4;
    }
    // 0x8008B7A8: nop

    // 0x8008B7AC: blez        $v0, L_8008B7E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008B7B0: lui         $t3, 0x8000
        ctx->r11 = S32(0X8000 << 16);
            goto L_8008B7E4;
    }
    // 0x8008B7B0: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8008B7B4: lw          $t3, 0x300($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X300);
    // 0x8008B7B8: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // 0x8008B7BC: bne         $t3, $zero, L_8008B7C8
    if (ctx->r11 != 0) {
        // 0x8008B7C0: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8008B7C8;
    }
    // 0x8008B7C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B7C4: addiu       $a2, $zero, 0xEA
    ctx->r6 = ADD32(0, 0XEA);
L_8008B7C8:
    // 0x8008B7C8: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8008B7CC: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8008B7D0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008B7D4: addiu       $a3, $a3, -0x7840
    ctx->r7 = ADD32(ctx->r7, -0X7840);
    // 0x8008B7D8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8008B7DC: jal         0x800C49A0
    // 0x8008B7E0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    draw_text(rdram, ctx);
        goto after_6;
    // 0x8008B7E0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    after_6:
L_8008B7E4:
    // 0x8008B7E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B7E8: jal         0x8007B820
    // 0x8008B7EC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    rendermode_reset(rdram, ctx);
        goto after_7;
    // 0x8008B7EC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_7:
    // 0x8008B7F0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8008B7F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8008B7F8: jal         0x8006632C
    // 0x8008B7FC: nop

    cam_set_fov(rdram, ctx);
        goto after_8;
    // 0x8008B7FC: nop

    after_8:
L_8008B800:
    // 0x8008B800: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008B804:
    // 0x8008B804: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008B808: jr          $ra
    // 0x8008B80C: nop

    return;
    // 0x8008B80C: nop

;}
RECOMP_FUNC void sound_reverb_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000260C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002610: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80002614: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80002618: jal         0x80064B6C
    // 0x8000261C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    alFxReverbSet(rdram, ctx);
        goto after_0;
    // 0x8000261C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80002620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002628: jr          $ra
    // 0x8000262C: nop

    return;
    // 0x8000262C: nop

;}
RECOMP_FUNC void get_ingame_map_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED54: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006ED58: lw          $v0, 0x3A74($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A74);
    // 0x8006ED5C: jr          $ra
    // 0x8006ED60: nop

    return;
    // 0x8006ED60: nop

;}
RECOMP_FUNC void light_toggle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032264: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    // 0x80032268: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003226C: bne         $t6, $at, L_8003227C
    if (ctx->r14 != ctx->r1) {
        // 0x80032270: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8003227C;
    }
    // 0x80032270: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80032274: jr          $ra
    // 0x80032278: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    return;
    // 0x80032278: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
L_8003227C:
    // 0x8003227C: sb          $t7, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r15;
    // 0x80032280: jr          $ra
    // 0x80032284: nop

    return;
    // 0x80032284: nop

;}
RECOMP_FUNC void spectate_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BC88: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001BC8C: addiu       $a3, $a3, -0x4BA0
    ctx->r7 = ADD32(ctx->r7, -0X4BA0);
    // 0x8001BC90: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x8001BC94: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001BC98: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x8001BC9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001BCA0: blez        $v1, L_8001BD3C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001BCA4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001BD3C;
    }
    // 0x8001BCA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001BCA8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001BCAC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8001BCB0: addiu       $t0, $t0, -0x4C28
    ctx->r8 = ADD32(ctx->r8, -0X4C28);
    // 0x8001BCB4: addiu       $t2, $t2, -0x4BA4
    ctx->r10 = ADD32(ctx->r10, -0X4BA4);
    // 0x8001BCB8: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
L_8001BCBC:
    // 0x8001BCBC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8001BCC0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001BCC4: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8001BCC8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8001BCCC: nop

    // 0x8001BCD0: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x8001BCD4: nop

    // 0x8001BCD8: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8001BCDC: bne         $t9, $zero, L_8001BD34
    if (ctx->r25 != 0) {
        // 0x8001BCE0: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001BD34;
    }
    // 0x8001BCE0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001BCE4: lh          $t3, 0x48($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X48);
    // 0x8001BCE8: nop

    // 0x8001BCEC: bne         $t1, $t3, L_8001BD34
    if (ctx->r9 != ctx->r11) {
        // 0x8001BCF0: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001BD34;
    }
    // 0x8001BCF0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001BCF4: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8001BCF8: nop

    // 0x8001BCFC: slti        $at, $a2, 0x14
    ctx->r1 = SIGNED(ctx->r6) < 0X14 ? 1 : 0;
    // 0x8001BD00: beq         $at, $zero, L_8001BD34
    if (ctx->r1 == 0) {
        // 0x8001BD04: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001BD34;
    }
    // 0x8001BD04: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001BD08: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8001BD0C: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x8001BD10: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8001BD14: sw          $a0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r4;
    // 0x8001BD18: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8001BD1C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001BD20: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001BD24: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8001BD28: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x8001BD2C: nop

    // 0x8001BD30: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001BD34:
    // 0x8001BD34: bne         $at, $zero, L_8001BCBC
    if (ctx->r1 != 0) {
        // 0x8001BD38: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001BCBC;
    }
    // 0x8001BD38: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001BD3C:
    // 0x8001BD3C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001BD40: lw          $a2, -0x4BA0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4BA0);
    // 0x8001BD44: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001BD48: addiu       $t2, $t2, -0x4BA4
    ctx->r10 = ADD32(ctx->r10, -0X4BA4);
    // 0x8001BD4C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001BD50: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001BD54:
    // 0x8001BD54: blez        $a2, L_8001BDB8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001BD58: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001BDB8;
    }
    // 0x8001BD58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001BD5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001BD60:
    // 0x8001BD60: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8001BD64: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001BD68: addu        $a3, $t9, $a1
    ctx->r7 = ADD32(ctx->r25, ctx->r5);
    // 0x8001BD6C: lw          $t0, 0x4($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X4);
    // 0x8001BD70: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8001BD74: lw          $t3, 0x78($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X78);
    // 0x8001BD78: lw          $t4, 0x78($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X78);
    // 0x8001BD7C: nop

    // 0x8001BD80: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001BD84: beq         $at, $zero, L_8001BDB0
    if (ctx->r1 == 0) {
        // 0x8001BD88: slt         $at, $v0, $a2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001BDB0;
    }
    // 0x8001BD88: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001BD8C: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x8001BD90: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x8001BD94: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001BD98: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x8001BD9C: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8001BDA0: lw          $a2, -0x4BA0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4BA0);
    // 0x8001BDA4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001BDA8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001BDAC: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
L_8001BDB0:
    // 0x8001BDB0: bne         $at, $zero, L_8001BD60
    if (ctx->r1 != 0) {
        // 0x8001BDB4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001BD60;
    }
    // 0x8001BDB4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001BDB8:
    // 0x8001BDB8: beq         $v1, $zero, L_8001BD54
    if (ctx->r3 == 0) {
        // 0x8001BDBC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8001BD54;
    }
    // 0x8001BDBC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001BDC0: jr          $ra
    // 0x8001BDC4: nop

    return;
    // 0x8001BDC4: nop

;}
RECOMP_FUNC void hud_race_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A518C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800A5190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5194: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800A5198: lb          $t6, 0x1D8($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1D8);
    // 0x800A519C: nop

    // 0x800A51A0: bne         $t6, $zero, L_800A548C
    if (ctx->r14 != 0) {
        // 0x800A51A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A548C;
    }
    // 0x800A51A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A51A8: lh          $v1, 0x1AE($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1AE);
    // 0x800A51AC: jal         0x8001139C
    // 0x800A51B0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    get_race_countdown(rdram, ctx);
        goto after_0;
    // 0x800A51B0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x800A51B4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800A51B8: beq         $v0, $zero, L_800A5228
    if (ctx->r2 == 0) {
        // 0x800A51BC: nop
    
            goto L_800A5228;
    }
    // 0x800A51BC: nop

    // 0x800A51C0: jal         0x8006BFD8
    // 0x800A51C4: nop

    level_type(rdram, ctx);
        goto after_1;
    // 0x800A51C4: nop

    after_1:
    // 0x800A51C8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A51CC: beq         $v0, $at, L_800A51E4
    if (ctx->r2 == ctx->r1) {
        // 0x800A51D0: nop
    
            goto L_800A51E4;
    }
    // 0x800A51D0: nop

    // 0x800A51D4: jal         0x80023450
    // 0x800A51D8: nop

    is_taj_challenge(rdram, ctx);
        goto after_2;
    // 0x800A51D8: nop

    after_2:
    // 0x800A51DC: beq         $v0, $zero, L_800A51EC
    if (ctx->r2 == 0) {
        // 0x800A51E0: nop
    
            goto L_800A51EC;
    }
    // 0x800A51E0: nop

L_800A51E4:
    // 0x800A51E4: b           L_800A5228
    // 0x800A51E8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_800A5228;
    // 0x800A51E8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800A51EC:
    // 0x800A51EC: jal         0x8006ECD0
    // 0x800A51F0: nop

    get_settings(rdram, ctx);
        goto after_3;
    // 0x800A51F0: nop

    after_3:
    // 0x800A51F4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A51F8: lw          $t7, 0x72D0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72D0);
    // 0x800A51FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5200: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A5204: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A5208: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800A520C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5210: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800A5214: lb          $v1, 0x5A($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X5A);
    // 0x800A5218: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A521C: nop

    // 0x800A5220: sh          $v1, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r3;
    // 0x800A5224: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800A5228:
    // 0x800A5228: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A522C: lw          $t2, 0x72CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72CC);
    // 0x800A5230: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5234: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800A5238: beq         $at, $zero, L_800A5298
    if (ctx->r1 == 0) {
        // 0x800A523C: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A5298;
    }
    // 0x800A523C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5240: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800A5244: beq         $at, $zero, L_800A525C
    if (ctx->r1 == 0) {
        // 0x800A5248: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A525C;
    }
    // 0x800A5248: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A524C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A5250: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x800A5254: b           L_800A5268
    // 0x800A5258: sh          $t3, 0x38($t4)
    MEM_H(0X38, ctx->r12) = ctx->r11;
        goto L_800A5268;
    // 0x800A5258: sh          $t3, 0x38($t4)
    MEM_H(0X38, ctx->r12) = ctx->r11;
L_800A525C:
    // 0x800A525C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5260: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800A5264: sh          $t5, 0x38($t6)
    MEM_H(0X38, ctx->r14) = ctx->r13;
L_800A5268:
    // 0x800A5268: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A526C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5270: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5274: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5278: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A527C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5280: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800A5284: jal         0x800AAB5C
    // 0x800A5288: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A5288: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    after_4:
    // 0x800A528C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5290: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800A5294: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
L_800A5298:
    // 0x800A5298: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A529C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800A52A0: lb          $t8, 0x1B($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X1B);
    // 0x800A52A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A52A8: addiu       $t9, $t8, 0x81
    ctx->r25 = ADD32(ctx->r24, 0X81);
    // 0x800A52AC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800A52B0: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x800A52B4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A52B8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800A52BC: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800A52C0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A52C4: nop

    // 0x800A52C8: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A52CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A52D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A52D4: nop

    // 0x800A52D8: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800A52DC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800A52E0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A52E4: sll         $t2, $a0, 16
    ctx->r10 = S32(ctx->r4 << 16);
    // 0x800A52E8: jal         0x80070A04
    // 0x800A52EC: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    sins_f(rdram, ctx);
        goto after_5;
    // 0x800A52EC: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    after_5:
    // 0x800A52F0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A52F4: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A52F8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A52FC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800A5300: lb          $t5, 0x1C($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X1C);
    // 0x800A5304: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A5308: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800A530C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A5310: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5314: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A5318: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A531C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A5320: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800A5324: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800A5328: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800A532C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800A5330: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A5334: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x800A5338: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A533C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5340: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5344: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5348: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A534C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800A5350: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x800A5354: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A5358: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x800A535C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5360: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800A5364: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x800A5368: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A536C: nop

    // 0x800A5370: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800A5374: nop

    // 0x800A5378: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x800A537C: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A5380: nop

    // 0x800A5384: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800A5388: sub.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800A538C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800A5390: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5394: jal         0x800AAB5C
    // 0x800A5398: nop

    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A5398: nop

    after_6:
    // 0x800A539C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A53A0: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A53A4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A53A8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A53AC: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x800A53B0: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x800A53B4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A53B8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800A53BC: lb          $t7, 0x1A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1A);
    // 0x800A53C0: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x800A53C4: beq         $t7, $zero, L_800A53FC
    if (ctx->r15 == 0) {
        // 0x800A53C8: nop
    
            goto L_800A53FC;
    }
    // 0x800A53C8: nop

    // 0x800A53CC: lb          $v1, 0x1B($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1B);
    // 0x800A53D0: subu        $t9, $a1, $t8
    ctx->r25 = SUB32(ctx->r5, ctx->r24);
    // 0x800A53D4: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A53D8: beq         $at, $zero, L_800A53F0
    if (ctx->r1 == 0) {
        // 0x800A53DC: addu        $t1, $v1, $t8
        ctx->r9 = ADD32(ctx->r3, ctx->r24);
            goto L_800A53F0;
    }
    // 0x800A53DC: addu        $t1, $v1, $t8
    ctx->r9 = ADD32(ctx->r3, ctx->r24);
    // 0x800A53E0: sb          $t1, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r9;
    // 0x800A53E4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A53E8: b           L_800A5400
    // 0x800A53EC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_800A5400;
    // 0x800A53EC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800A53F0:
    // 0x800A53F0: sb          $a1, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r5;
    // 0x800A53F4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A53F8: nop

L_800A53FC:
    // 0x800A53FC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800A5400:
    // 0x800A5400: lh          $t2, 0x18($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X18);
    // 0x800A5404: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x800A5408: beq         $a0, $t2, L_800A5458
    if (ctx->r4 == ctx->r10) {
        // 0x800A540C: nop
    
            goto L_800A5458;
    }
    // 0x800A540C: nop

    // 0x800A5410: lb          $t3, 0x1A($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X1A);
    // 0x800A5414: addiu       $t5, $zero, -0x7F
    ctx->r13 = ADD32(0, -0X7F);
    // 0x800A5418: beq         $t3, $zero, L_800A5440
    if (ctx->r11 == 0) {
        // 0x800A541C: nop
    
            goto L_800A5440;
    }
    // 0x800A541C: nop

    // 0x800A5420: lb          $v1, 0x1B($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1B);
    // 0x800A5424: nop

    // 0x800A5428: blez        $v1, L_800A5440
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A542C: negu        $t4, $v1
        ctx->r12 = SUB32(0, ctx->r3);
            goto L_800A5440;
    }
    // 0x800A542C: negu        $t4, $v1
    ctx->r12 = SUB32(0, ctx->r3);
    // 0x800A5430: sb          $t4, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r12;
    // 0x800A5434: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5438: b           L_800A545C
    // 0x800A543C: sh          $a0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r4;
        goto L_800A545C;
    // 0x800A543C: sh          $a0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r4;
L_800A5440:
    // 0x800A5440: sb          $t5, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r13;
    // 0x800A5444: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5448: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A544C: sb          $t6, 0x1A($t7)
    MEM_B(0X1A, ctx->r15) = ctx->r14;
    // 0x800A5450: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5454: nop

L_800A5458:
    // 0x800A5458: sh          $a0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r4;
L_800A545C:
    // 0x800A545C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5460: nop

    // 0x800A5464: lb          $t8, 0x1A($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1A);
    // 0x800A5468: nop

    // 0x800A546C: beq         $t8, $zero, L_800A548C
    if (ctx->r24 == 0) {
        // 0x800A5470: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A548C;
    }
    // 0x800A5470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5474: lb          $t9, 0x1B($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1B);
    // 0x800A5478: nop

    // 0x800A547C: bne         $a1, $t9, L_800A548C
    if (ctx->r5 != ctx->r25) {
        // 0x800A5480: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A548C;
    }
    // 0x800A5480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5484: sb          $zero, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = 0;
    // 0x800A5488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A548C:
    // 0x800A548C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800A5490: jr          $ra
    // 0x800A5494: nop

    return;
    // 0x800A5494: nop

;}
RECOMP_FUNC void racer_sound_update_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006FC8: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80006FCC: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80006FD0: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x80006FD4: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x80006FD8: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80006FDC: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80006FE0: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80006FE4: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80006FE8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80006FEC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80006FF0: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80006FF4: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80006FF8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80006FFC: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80007000: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x80007004: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80007008: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8000700C: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80007010: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80007014: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80007018: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8000701C: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80007020: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80007024: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80007028: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8000702C: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x80007030: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x80007034: sw          $a3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r7;
    // 0x80007038: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x8000703C: blez        $t6, L_80007750
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80007040: sw          $zero, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = 0;
            goto L_80007750;
    }
    // 0x80007040: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x80007044: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007048: lwc1        $f30, 0x5254($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X5254);
    // 0x8000704C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007050: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80007054: lwc1        $f29, 0x5258($at)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r1, 0X5258);
    // 0x80007058: lwc1        $f28, 0x525C($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X525C);
    // 0x8000705C: mtc1        $zero, $f25
    ctx->f_odd[(25 - 1) * 2] = 0;
    // 0x80007060: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80007064: lw          $fp, 0xD8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XD8);
    // 0x80007068: addiu       $s4, $s4, -0x5E48
    ctx->r20 = ADD32(ctx->r20, -0X5E48);
    // 0x8000706C: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
L_80007070:
    // 0x80007070: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x80007074: nop

    // 0x80007078: lw          $s1, 0x64($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X64);
    // 0x8000707C: nop

    // 0x80007080: beq         $s1, $zero, L_80007094
    if (ctx->r17 == 0) {
        // 0x80007084: nop
    
            goto L_80007094;
    }
    // 0x80007084: nop

    // 0x80007088: lw          $t9, 0x118($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X118);
    // 0x8000708C: b           L_80007098
    // 0x80007090: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
        goto L_80007098;
    // 0x80007090: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
L_80007094:
    // 0x80007094: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
L_80007098:
    // 0x80007098: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x8000709C: nop

    // 0x800070A0: beq         $s0, $zero, L_8000773C
    if (ctx->r16 == 0) {
        // 0x800070A4: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_8000773C;
    }
    // 0x800070A4: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800070A8: lhu         $t0, 0x0($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X0);
    // 0x800070AC: nop

    // 0x800070B0: beq         $t0, $zero, L_8000773C
    if (ctx->r8 == 0) {
        // 0x800070B4: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_8000773C;
    }
    // 0x800070B4: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800070B8: lb          $t1, 0x1D8($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1D8);
    // 0x800070BC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800070C0: bne         $t1, $zero, L_800070DC
    if (ctx->r9 != 0) {
        // 0x800070C4: lw          $t2, 0xAC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XAC);
            goto L_800070DC;
    }
    // 0x800070C4: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x800070C8: jal         0x80066750
    // 0x800070CC: nop

    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_0;
    // 0x800070CC: nop

    after_0:
    // 0x800070D0: beq         $v0, $zero, L_800071F0
    if (ctx->r2 == 0) {
        // 0x800070D4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800071F0;
    }
    // 0x800070D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800070D8: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
L_800070DC:
    // 0x800070DC: lw          $a2, 0x0($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X0);
    // 0x800070E0: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800070E4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800070E8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800070EC: addu        $v1, $s7, $t3
    ctx->r3 = ADD32(ctx->r23, ctx->r11);
    // 0x800070F0: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800070F4: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800070F8: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800070FC: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80007100: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80007104: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80007108: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000710C: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    // 0x80007110: swc1        $f0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f0.u32l;
    // 0x80007114: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80007118: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x8000711C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80007120: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80007124: jal         0x80006BFC
    // 0x80007128: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    racer_sound_doppler_effect(rdram, ctx);
        goto after_1;
    // 0x80007128: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    after_1:
    // 0x8000712C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80007130: lwc1        $f0, 0xC0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80007134: nop

    // 0x80007138: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000713C: nop

    // 0x80007140: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80007144: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80007148: jal         0x800CA030
    // 0x8000714C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x8000714C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80007150: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80007154: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x80007158: swc1        $f0, 0x84($t4)
    MEM_W(0X84, ctx->r12) = ctx->f0.u32l;
    // 0x8000715C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007160: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007164: lwc1        $f16, 0x5260($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5260);
    // 0x80007168: lwc1        $f2, 0x84($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8000716C: nop

    // 0x80007170: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80007174: nop

    // 0x80007178: bc1f        L_800071C0
    if (!c1cs) {
        // 0x8000717C: nop
    
            goto L_800071C0;
    }
    // 0x8000717C: nop

    // 0x80007180: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80007184: lh          $a2, 0x0($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X0);
    // 0x80007188: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8000718C: sub.s       $f4, $f30, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f30.fl - ctx->f18.fl;
    // 0x80007190: nop

    // 0x80007194: div.s       $f26, $f4, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = DIV_S(ctx->f4.fl, ctx->f30.fl);
    // 0x80007198: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x8000719C: mul.s       $f26, $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x800071A0: jal         0x800090C0
    // 0x800071A4: nop

    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_3;
    // 0x800071A4: nop

    after_3:
    // 0x800071A8: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800071AC: nop

    // 0x800071B0: sb          $v0, 0x91($t5)
    MEM_B(0X91, ctx->r13) = ctx->r2;
    // 0x800071B4: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800071B8: b           L_800071CC
    // 0x800071BC: lb          $t6, 0x1D8($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1D8);
        goto L_800071CC;
    // 0x800071BC: lb          $t6, 0x1D8($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1D8);
L_800071C0:
    // 0x800071C0: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800071C4: nop

    // 0x800071C8: lb          $t6, 0x1D8($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1D8);
L_800071CC:
    // 0x800071CC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800071D0: bne         $t6, $zero, L_80007214
    if (ctx->r14 != 0) {
        // 0x800071D4: nop
    
            goto L_80007214;
    }
    // 0x800071D4: nop

    // 0x800071D8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800071DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800071E0: cvt.d.s     $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f6.d = CVT_D_S(ctx->f26.fl);
    // 0x800071E4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800071E8: b           L_80007214
    // 0x800071EC: cvt.s.d     $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f26.fl = CVT_S_D(ctx->f10.d);
        goto L_80007214;
    // 0x800071EC: cvt.s.d     $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f26.fl = CVT_S_D(ctx->f10.d);
L_800071F0:
    // 0x800071F0: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800071F4: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x800071F8: sb          $t7, 0x91($t8)
    MEM_B(0X91, ctx->r24) = ctx->r15;
    // 0x800071FC: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80007200: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80007204: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80007208: swc1        $f16, 0x68($t9)
    MEM_W(0X68, ctx->r25) = ctx->f16.u32l;
    // 0x8000720C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007210: nop

L_80007214:
    // 0x80007214: lbu         $v0, 0xA0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA0);
    // 0x80007218: nop

    // 0x8000721C: slti        $at, $v0, 0x46
    ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
    // 0x80007220: beq         $at, $zero, L_80007498
    if (ctx->r1 == 0) {
        // 0x80007224: nop
    
            goto L_80007498;
    }
    // 0x80007224: nop

    // 0x80007228: lbu         $a0, 0x36($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X36);
    // 0x8000722C: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80007230: beq         $a0, $zero, L_80007498
    if (ctx->r4 == 0) {
        // 0x80007234: slti        $at, $t0, 0x3
        ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
            goto L_80007498;
    }
    // 0x80007234: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80007238: beq         $at, $zero, L_80007498
    if (ctx->r1 == 0) {
        // 0x8000723C: nop
    
            goto L_80007498;
    }
    // 0x8000723C: nop

    // 0x80007240: cvt.d.s     $f18, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f18.d = CVT_D_S(ctx->f26.fl);
    // 0x80007244: c.eq.d      $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f24.d == ctx->f18.d;
    // 0x80007248: nop

    // 0x8000724C: bc1t        L_80007498
    if (c1cs) {
        // 0x80007250: nop
    
            goto L_80007498;
    }
    // 0x80007250: nop

    // 0x80007254: lbu         $t1, 0x44($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X44);
    // 0x80007258: nop

    // 0x8000725C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80007260: bne         $t2, $zero, L_80007498
    if (ctx->r10 != 0) {
        // 0x80007264: nop
    
            goto L_80007498;
    }
    // 0x80007264: nop

    // 0x80007268: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000726C: bgez        $v0, L_80007284
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80007270: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80007284;
    }
    // 0x80007270: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80007274: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80007278: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000727C: nop

    // 0x80007280: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80007284:
    // 0x80007284: lbu         $t3, 0x37($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X37);
    // 0x80007288: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8000728C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80007290: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80007294: div.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80007298: bgez        $t3, L_800072B0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8000729C: cvt.s.w     $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800072B0;
    }
    // 0x8000729C: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800072A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800072A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800072A8: nop

    // 0x800072AC: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
L_800072B0:
    // 0x800072B0: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800072B4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800072B8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800072BC: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800072C0: mul.s       $f6, $f8, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x800072C4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800072C8: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x800072CC: nop

    // 0x800072D0: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800072D4: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x800072D8: nop

    // 0x800072DC: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x800072E0: beq         $s2, $zero, L_8000732C
    if (ctx->r18 == 0) {
        // 0x800072E4: nop
    
            goto L_8000732C;
    }
    // 0x800072E4: nop

    // 0x800072E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800072EC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800072F0: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800072F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800072F8: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x800072FC: nop

    // 0x80007300: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80007304: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x80007308: nop

    // 0x8000730C: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x80007310: bne         $s2, $zero, L_80007324
    if (ctx->r18 != 0) {
        // 0x80007314: nop
    
            goto L_80007324;
    }
    // 0x80007314: nop

    // 0x80007318: mfc1        $s2, $f10
    ctx->r18 = (int32_t)ctx->f10.u32l;
    // 0x8000731C: b           L_8000733C
    // 0x80007320: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
        goto L_8000733C;
    // 0x80007320: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
L_80007324:
    // 0x80007324: b           L_8000733C
    // 0x80007328: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
        goto L_8000733C;
    // 0x80007328: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_8000732C:
    // 0x8000732C: mfc1        $s2, $f10
    ctx->r18 = (int32_t)ctx->f10.u32l;
    // 0x80007330: nop

    // 0x80007334: bltz        $s2, L_80007324
    if (SIGNED(ctx->r18) < 0) {
        // 0x80007338: nop
    
            goto L_80007324;
    }
    // 0x80007338: nop

L_8000733C:
    // 0x8000733C: andi        $s3, $s2, 0xFF
    ctx->r19 = ctx->r18 & 0XFF;
    // 0x80007340: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80007344: slti        $at, $s3, 0x10
    ctx->r1 = SIGNED(ctx->r19) < 0X10 ? 1 : 0;
    // 0x80007348: bne         $at, $zero, L_80007468
    if (ctx->r1 != 0) {
        // 0x8000734C: nop
    
            goto L_80007468;
    }
    // 0x8000734C: nop

    // 0x80007350: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x80007354: nop

    // 0x80007358: bne         $t6, $zero, L_80007370
    if (ctx->r14 != 0) {
        // 0x8000735C: nop
    
            goto L_80007370;
    }
    // 0x8000735C: nop

    // 0x80007360: jal         0x80001F14
    // 0x80007364: addiu       $a1, $s0, 0x50
    ctx->r5 = ADD32(ctx->r16, 0X50);
    sound_play_direct(rdram, ctx);
        goto after_4;
    // 0x80007364: addiu       $a1, $s0, 0x50
    ctx->r5 = ADD32(ctx->r16, 0X50);
    after_4:
    // 0x80007368: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x8000736C: nop

L_80007370:
    // 0x80007370: lbu         $t7, 0x38($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X38);
    // 0x80007374: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80007378: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8000737C: bgez        $t7, L_80007390
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80007380: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80007390;
    }
    // 0x80007380: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80007384: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80007388: nop

    // 0x8000738C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80007390:
    // 0x80007390: lbu         $t8, 0x39($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X39);
    // 0x80007394: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80007398: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000739C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800073A0: div.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800073A4: bgez        $t8, L_800073BC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800073A8: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800073BC;
    }
    // 0x800073A8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800073AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800073B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800073B4: nop

    // 0x800073B8: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800073BC:
    // 0x800073BC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800073C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800073C4: nop

    // 0x800073C8: div.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800073CC: sub.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800073D0: mul.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800073D4: add.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800073D8: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x800073DC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x800073E0: nop

    // 0x800073E4: beq         $a0, $zero, L_800074C4
    if (ctx->r4 == 0) {
        // 0x800073E8: nop
    
            goto L_800074C4;
    }
    // 0x800073E8: nop

    // 0x800073EC: lw          $s0, 0x0($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X0);
    // 0x800073F0: nop

    // 0x800073F4: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800073F8: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x800073FC: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80007400: jal         0x80009B7C
    // 0x80007404: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_5;
    // 0x80007404: nop

    after_5:
    // 0x80007408: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8000740C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80007410: lw          $a0, 0x50($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X50);
    // 0x80007414: jal         0x800049F8
    // 0x80007418: sll         $a2, $s3, 8
    ctx->r6 = S32(ctx->r19 << 8);
    sndp_set_param(rdram, ctx);
        goto after_6;
    // 0x80007418: sll         $a2, $s3, 8
    ctx->r6 = S32(ctx->r19 << 8);
    after_6:
    // 0x8000741C: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x80007420: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x80007424: lw          $a0, 0x50($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X50);
    // 0x80007428: jal         0x800049F8
    // 0x8000742C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_7;
    // 0x8000742C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_7:
    // 0x80007430: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80007434: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80007438: lw          $a0, 0x50($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X50);
    // 0x8000743C: jal         0x80004604
    // 0x80007440: nop

    sndp_set_priority(rdram, ctx);
        goto after_8;
    // 0x80007440: nop

    after_8:
    // 0x80007444: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007448: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8000744C: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80007450: lbu         $a2, 0x91($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X91);
    // 0x80007454: jal         0x800049F8
    // 0x80007458: nop

    sndp_set_param(rdram, ctx);
        goto after_9;
    // 0x80007458: nop

    after_9:
    // 0x8000745C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007460: b           L_800074C8
    // 0x80007464: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
        goto L_800074C8;
    // 0x80007464: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
L_80007468:
    // 0x80007468: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8000746C: nop

    // 0x80007470: beq         $a0, $zero, L_800074C4
    if (ctx->r4 == 0) {
        // 0x80007474: nop
    
            goto L_800074C4;
    }
    // 0x80007474: nop

    // 0x80007478: jal         0x8000488C
    // 0x8000747C: nop

    sndp_stop(rdram, ctx);
        goto after_10;
    // 0x8000747C: nop

    after_10:
    // 0x80007480: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80007484: nop

    // 0x80007488: sw          $zero, 0x50($t2)
    MEM_W(0X50, ctx->r10) = 0;
    // 0x8000748C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007490: b           L_800074C8
    // 0x80007494: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
        goto L_800074C8;
    // 0x80007494: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
L_80007498:
    // 0x80007498: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8000749C: nop

    // 0x800074A0: beq         $a0, $zero, L_800074C4
    if (ctx->r4 == 0) {
        // 0x800074A4: nop
    
            goto L_800074C4;
    }
    // 0x800074A4: nop

    // 0x800074A8: jal         0x8000488C
    // 0x800074AC: nop

    sndp_stop(rdram, ctx);
        goto after_11;
    // 0x800074AC: nop

    after_11:
    // 0x800074B0: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800074B4: nop

    // 0x800074B8: sw          $zero, 0x50($t3)
    MEM_W(0X50, ctx->r11) = 0;
    // 0x800074BC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800074C0: nop

L_800074C4:
    // 0x800074C4: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
L_800074C8:
    // 0x800074C8: nop

    // 0x800074CC: beq         $t4, $zero, L_8000773C
    if (ctx->r12 == 0) {
        // 0x800074D0: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_8000773C;
    }
    // 0x800074D0: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800074D4: cvt.d.s     $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f20.d = CVT_D_S(ctx->f26.fl);
    // 0x800074D8: c.eq.d      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.d == ctx->f20.d;
    // 0x800074DC: sll         $s1, $s5, 2
    ctx->r17 = S32(ctx->r21 << 2);
    // 0x800074E0: bc1t        L_80007738
    if (c1cs) {
        // 0x800074E4: addu        $v0, $s0, $s1
        ctx->r2 = ADD32(ctx->r16, ctx->r17);
            goto L_80007738;
    }
    // 0x800074E4: addu        $v0, $s0, $s1
    ctx->r2 = ADD32(ctx->r16, ctx->r17);
L_800074E8:
    // 0x800074E8: lwc1        $f10, 0x54($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800074EC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800074F0: mul.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x800074F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800074F8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800074FC: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x80007500: nop

    // 0x80007504: cvt.w.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80007508: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x8000750C: nop

    // 0x80007510: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x80007514: beq         $s2, $zero, L_80007560
    if (ctx->r18 == 0) {
        // 0x80007518: nop
    
            goto L_80007560;
    }
    // 0x80007518: nop

    // 0x8000751C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80007520: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80007524: sub.s       $f18, $f4, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80007528: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000752C: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x80007530: nop

    // 0x80007534: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80007538: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x8000753C: nop

    // 0x80007540: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x80007544: bne         $s2, $zero, L_80007558
    if (ctx->r18 != 0) {
        // 0x80007548: nop
    
            goto L_80007558;
    }
    // 0x80007548: nop

    // 0x8000754C: mfc1        $s2, $f18
    ctx->r18 = (int32_t)ctx->f18.u32l;
    // 0x80007550: b           L_80007570
    // 0x80007554: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
        goto L_80007570;
    // 0x80007554: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
L_80007558:
    // 0x80007558: b           L_80007570
    // 0x8000755C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
        goto L_80007570;
    // 0x8000755C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_80007560:
    // 0x80007560: mfc1        $s2, $f18
    ctx->r18 = (int32_t)ctx->f18.u32l;
    // 0x80007564: nop

    // 0x80007568: bltz        $s2, L_80007558
    if (SIGNED(ctx->r18) < 0) {
        // 0x8000756C: nop
    
            goto L_80007558;
    }
    // 0x8000756C: nop

L_80007570:
    // 0x80007570: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80007574: lwc1        $f8, 0x5C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80007578: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8000757C: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80007580: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80007584: lwc1        $f18, 0x68($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80007588: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8000758C: andi        $t6, $s2, 0xFF
    ctx->r14 = ctx->r18 & 0XFF;
    // 0x80007590: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80007594: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x80007598: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8000759C: c.lt.d      $f6, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f6.d < ctx->f28.d;
    // 0x800075A0: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x800075A4: bc1f        L_800075B8
    if (!c1cs) {
        // 0x800075A8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800075B8;
    }
    // 0x800075A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800075AC: lwc1        $f16, 0x5264($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5264);
    // 0x800075B0: nop

    // 0x800075B4: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
L_800075B8:
    // 0x800075B8: bne         $s5, $zero, L_800075F8
    if (ctx->r21 != 0) {
        // 0x800075BC: nop
    
            goto L_800075F8;
    }
    // 0x800075BC: nop

    // 0x800075C0: lbu         $t7, 0x44($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X44);
    // 0x800075C4: nop

    // 0x800075C8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800075CC: beq         $t8, $zero, L_800075F8
    if (ctx->r24 == 0) {
        // 0x800075D0: nop
    
            goto L_800075F8;
    }
    // 0x800075D0: nop

    // 0x800075D4: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x800075D8: nop

    // 0x800075DC: beq         $a0, $zero, L_800076FC
    if (ctx->r4 == 0) {
        // 0x800075E0: nop
    
            goto L_800076FC;
    }
    // 0x800075E0: nop

    // 0x800075E4: jal         0x8000488C
    // 0x800075E8: nop

    sndp_stop(rdram, ctx);
        goto after_12;
    // 0x800075E8: nop

    after_12:
    // 0x800075EC: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x800075F0: b           L_800076FC
    // 0x800075F4: sw          $zero, 0x48($t9)
    MEM_W(0X48, ctx->r25) = 0;
        goto L_800076FC;
    // 0x800075F4: sw          $zero, 0x48($t9)
    MEM_W(0X48, ctx->r25) = 0;
L_800075F8:
    // 0x800075F8: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
    // 0x800075FC: nop

    // 0x80007600: beq         $a0, $zero, L_8000762C
    if (ctx->r4 == 0) {
        // 0x80007604: nop
    
            goto L_8000762C;
    }
    // 0x80007604: nop

    // 0x80007608: bne         $s2, $zero, L_8000762C
    if (ctx->r18 != 0) {
        // 0x8000760C: nop
    
            goto L_8000762C;
    }
    // 0x8000760C: nop

    // 0x80007610: jal         0x8000488C
    // 0x80007614: nop

    sndp_stop(rdram, ctx);
        goto after_13;
    // 0x80007614: nop

    after_13:
    // 0x80007618: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x8000761C: nop

    // 0x80007620: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80007624: b           L_800076FC
    // 0x80007628: sw          $zero, 0x48($t1)
    MEM_W(0X48, ctx->r9) = 0;
        goto L_800076FC;
    // 0x80007628: sw          $zero, 0x48($t1)
    MEM_W(0X48, ctx->r9) = 0;
L_8000762C:
    // 0x8000762C: bne         $a0, $zero, L_80007658
    if (ctx->r4 != 0) {
        // 0x80007630: sll         $t2, $s5, 1
        ctx->r10 = S32(ctx->r21 << 1);
            goto L_80007658;
    }
    // 0x80007630: sll         $t2, $s5, 1
    ctx->r10 = S32(ctx->r21 << 1);
    // 0x80007634: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80007638: lhu         $a0, 0x0($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X0);
    // 0x8000763C: jal         0x80001F14
    // 0x80007640: addiu       $a1, $v0, 0x48
    ctx->r5 = ADD32(ctx->r2, 0X48);
    sound_play_direct(rdram, ctx);
        goto after_14;
    // 0x80007640: addiu       $a1, $v0, 0x48
    ctx->r5 = ADD32(ctx->r2, 0X48);
    after_14:
    // 0x80007644: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80007648: nop

    // 0x8000764C: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80007650: lw          $a0, 0x48($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X48);
    // 0x80007654: nop

L_80007658:
    // 0x80007658: beq         $a0, $zero, L_800076FC
    if (ctx->r4 == 0) {
        // 0x8000765C: nop
    
            goto L_800076FC;
    }
    // 0x8000765C: nop

    // 0x80007660: lw          $s0, 0x0($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X0);
    // 0x80007664: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x80007668: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8000766C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80007670: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80007674: jal         0x80009B7C
    // 0x80007678: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_15;
    // 0x80007678: nop

    after_15:
    // 0x8000767C: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80007680: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80007684: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80007688: lw          $a0, 0x48($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X48);
    // 0x8000768C: jal         0x800049F8
    // 0x80007690: sll         $a2, $s3, 8
    ctx->r6 = S32(ctx->r19 << 8);
    sndp_set_param(rdram, ctx);
        goto after_16;
    // 0x80007690: sll         $a2, $s3, 8
    ctx->r6 = S32(ctx->r19 << 8);
    after_16:
    // 0x80007694: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80007698: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8000769C: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x800076A0: lw          $a0, 0x48($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X48);
    // 0x800076A4: jal         0x800049F8
    // 0x800076A8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_17;
    // 0x800076A8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_17:
    // 0x800076AC: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800076B0: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x800076B4: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800076B8: lw          $a0, 0x48($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X48);
    // 0x800076BC: jal         0x80004604
    // 0x800076C0: nop

    sndp_set_priority(rdram, ctx);
        goto after_18;
    // 0x800076C0: nop

    after_18:
    // 0x800076C4: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x800076C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800076CC: beq         $t2, $at, L_800076E0
    if (ctx->r10 == ctx->r1) {
        // 0x800076D0: nop
    
            goto L_800076E0;
    }
    // 0x800076D0: nop

    // 0x800076D4: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x800076D8: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x800076DC: sb          $t3, 0x91($t4)
    MEM_B(0X91, ctx->r12) = ctx->r11;
L_800076E0:
    // 0x800076E0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800076E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800076E8: addu        $t5, $s0, $s1
    ctx->r13 = ADD32(ctx->r16, ctx->r17);
    // 0x800076EC: lw          $a0, 0x48($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X48);
    // 0x800076F0: lbu         $a2, 0x91($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X91);
    // 0x800076F4: jal         0x800049F8
    // 0x800076F8: nop

    sndp_set_param(rdram, ctx);
        goto after_19;
    // 0x800076F8: nop

    after_19:
L_800076FC:
    // 0x800076FC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80007700: slti        $at, $s5, 0x2
    ctx->r1 = SIGNED(ctx->r21) < 0X2 ? 1 : 0;
    // 0x80007704: beq         $at, $zero, L_80007738
    if (ctx->r1 == 0) {
        // 0x80007708: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80007738;
    }
    // 0x80007708: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000770C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007710: sll         $t6, $s5, 1
    ctx->r14 = S32(ctx->r21 << 1);
    // 0x80007714: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80007718: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8000771C: nop

    // 0x80007720: beq         $t8, $zero, L_8000773C
    if (ctx->r24 == 0) {
        // 0x80007724: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_8000773C;
    }
    // 0x80007724: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x80007728: c.eq.d      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.d == ctx->f20.d;
    // 0x8000772C: nop

    // 0x80007730: bc1f        L_800074E8
    if (!c1cs) {
        // 0x80007734: addu        $v0, $s0, $s1
        ctx->r2 = ADD32(ctx->r16, ctx->r17);
            goto L_800074E8;
    }
    // 0x80007734: addu        $v0, $s0, $s1
    ctx->r2 = ADD32(ctx->r16, ctx->r17);
L_80007738:
    // 0x80007738: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
L_8000773C:
    // 0x8000773C: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80007740: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80007744: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
    // 0x80007748: bne         $t0, $t1, L_80007070
    if (ctx->r8 != ctx->r9) {
        // 0x8000774C: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_80007070;
    }
    // 0x8000774C: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_80007750:
    // 0x80007750: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007754: lwc1        $f29, 0x5268($at)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r1, 0X5268);
    // 0x80007758: lwc1        $f28, 0x526C($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X526C);
    // 0x8000775C: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80007760: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007764: lwc1        $f30, 0x5270($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X5270);
    // 0x80007768: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8000776C: lw          $fp, 0xD8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XD8);
    // 0x80007770: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x80007774: beq         $at, $zero, L_80007F18
    if (ctx->r1 == 0) {
        // 0x80007778: addiu       $s4, $s4, -0x5E48
        ctx->r20 = ADD32(ctx->r20, -0X5E48);
            goto L_80007F18;
    }
    // 0x80007778: addiu       $s4, $s4, -0x5E48
    ctx->r20 = ADD32(ctx->r20, -0X5E48);
    // 0x8000777C: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x80007780: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
    // 0x80007784: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80007788: beq         $at, $zero, L_800078C0
    if (ctx->r1 == 0) {
        // 0x8000778C: sw          $zero, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = 0;
            goto L_800078C0;
    }
    // 0x8000778C: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x80007790: subu        $v1, $t4, $t2
    ctx->r3 = SUB32(ctx->r12, ctx->r10);
    // 0x80007794: andi        $t5, $v1, 0x3
    ctx->r13 = ctx->r3 & 0X3;
    // 0x80007798: beq         $t5, $zero, L_800077F0
    if (ctx->r13 == 0) {
        // 0x8000779C: addu        $v0, $t5, $t2
        ctx->r2 = ADD32(ctx->r13, ctx->r10);
            goto L_800077F0;
    }
    // 0x8000779C: addu        $v0, $t5, $t2
    ctx->r2 = ADD32(ctx->r13, ctx->r10);
    // 0x800077A0: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800077A4: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800077A8: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
L_800077AC:
    // 0x800077AC: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800077B0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800077B4: lw          $s1, 0x64($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X64);
    // 0x800077B8: nop

    // 0x800077BC: beq         $s1, $zero, L_800077D8
    if (ctx->r17 == 0) {
        // 0x800077C0: nop
    
            goto L_800077D8;
    }
    // 0x800077C0: nop

    // 0x800077C4: lw          $t9, 0x118($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X118);
    // 0x800077C8: nop

    // 0x800077CC: beq         $t9, $zero, L_800077D8
    if (ctx->r25 == 0) {
        // 0x800077D0: sw          $t9, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r25;
            goto L_800077D8;
    }
    // 0x800077D0: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800077D4: sb          $zero, 0x88($t9)
    MEM_B(0X88, ctx->r25) = 0;
L_800077D8:
    // 0x800077D8: bne         $v0, $s5, L_800077AC
    if (ctx->r2 != ctx->r21) {
        // 0x800077DC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800077AC;
    }
    // 0x800077DC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800077E0: lw          $v1, 0xCC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XCC);
    // 0x800077E4: nop

    // 0x800077E8: beq         $s5, $v1, L_800078C4
    if (ctx->r21 == ctx->r3) {
        // 0x800077EC: lw          $t2, 0x7C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X7C);
            goto L_800078C4;
    }
    // 0x800077EC: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
L_800077F0:
    // 0x800077F0: lw          $v1, 0xCC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XCC);
    // 0x800077F4: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x800077F8: sll         $t1, $s5, 2
    ctx->r9 = S32(ctx->r21 << 2);
    // 0x800077FC: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80007800: addu        $v0, $t2, $t0
    ctx->r2 = ADD32(ctx->r10, ctx->r8);
    // 0x80007804: addu        $s2, $t0, $t1
    ctx->r18 = ADD32(ctx->r8, ctx->r9);
L_80007808:
    // 0x80007808: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8000780C: nop

    // 0x80007810: lw          $s1, 0x64($t4)
    ctx->r17 = MEM_W(ctx->r12, 0X64);
    // 0x80007814: nop

    // 0x80007818: beq         $s1, $zero, L_80007834
    if (ctx->r17 == 0) {
        // 0x8000781C: nop
    
            goto L_80007834;
    }
    // 0x8000781C: nop

    // 0x80007820: lw          $t5, 0x118($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X118);
    // 0x80007824: nop

    // 0x80007828: beq         $t5, $zero, L_80007834
    if (ctx->r13 == 0) {
        // 0x8000782C: sw          $t5, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r13;
            goto L_80007834;
    }
    // 0x8000782C: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x80007830: sb          $zero, 0x88($t5)
    MEM_B(0X88, ctx->r13) = 0;
L_80007834:
    // 0x80007834: lw          $t3, 0x4($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X4);
    // 0x80007838: nop

    // 0x8000783C: lw          $s1, 0x64($t3)
    ctx->r17 = MEM_W(ctx->r11, 0X64);
    // 0x80007840: nop

    // 0x80007844: beq         $s1, $zero, L_80007860
    if (ctx->r17 == 0) {
        // 0x80007848: nop
    
            goto L_80007860;
    }
    // 0x80007848: nop

    // 0x8000784C: lw          $t6, 0x118($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X118);
    // 0x80007850: nop

    // 0x80007854: beq         $t6, $zero, L_80007860
    if (ctx->r14 == 0) {
        // 0x80007858: sw          $t6, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r14;
            goto L_80007860;
    }
    // 0x80007858: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8000785C: sb          $zero, 0x88($t6)
    MEM_B(0X88, ctx->r14) = 0;
L_80007860:
    // 0x80007860: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
    // 0x80007864: nop

    // 0x80007868: lw          $s1, 0x64($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X64);
    // 0x8000786C: nop

    // 0x80007870: beq         $s1, $zero, L_8000788C
    if (ctx->r17 == 0) {
        // 0x80007874: nop
    
            goto L_8000788C;
    }
    // 0x80007874: nop

    // 0x80007878: lw          $t8, 0x118($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X118);
    // 0x8000787C: nop

    // 0x80007880: beq         $t8, $zero, L_8000788C
    if (ctx->r24 == 0) {
        // 0x80007884: sw          $t8, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r24;
            goto L_8000788C;
    }
    // 0x80007884: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x80007888: sb          $zero, 0x88($t8)
    MEM_B(0X88, ctx->r24) = 0;
L_8000788C:
    // 0x8000788C: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x80007890: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80007894: lw          $s1, 0x64($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X64);
    // 0x80007898: nop

    // 0x8000789C: beq         $s1, $zero, L_800078B8
    if (ctx->r17 == 0) {
        // 0x800078A0: nop
    
            goto L_800078B8;
    }
    // 0x800078A0: nop

    // 0x800078A4: lw          $t1, 0x118($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X118);
    // 0x800078A8: nop

    // 0x800078AC: beq         $t1, $zero, L_800078B8
    if (ctx->r9 == 0) {
        // 0x800078B0: sw          $t1, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r9;
            goto L_800078B8;
    }
    // 0x800078B0: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
    // 0x800078B4: sb          $zero, 0x88($t1)
    MEM_B(0X88, ctx->r9) = 0;
L_800078B8:
    // 0x800078B8: bne         $s2, $v0, L_80007808
    if (ctx->r18 != ctx->r2) {
        // 0x800078BC: nop
    
            goto L_80007808;
    }
    // 0x800078BC: nop

L_800078C0:
    // 0x800078C0: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
L_800078C4:
    // 0x800078C4: lw          $s6, 0xC8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XC8);
    // 0x800078C8: blez        $t2, L_80007C28
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800078CC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80007C28;
    }
    // 0x800078CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800078D0: lwc1        $f25, 0x5278($at)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r1, 0X5278);
    // 0x800078D4: lwc1        $f24, 0x527C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X527C);
    // 0x800078D8: nop

L_800078DC:
    // 0x800078DC: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x800078E0: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800078E4: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x800078E8: lw          $s1, 0x64($t0)
    ctx->r17 = MEM_W(ctx->r8, 0X64);
    // 0x800078EC: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800078F0: beq         $at, $zero, L_80007C10
    if (ctx->r1 == 0) {
        // 0x800078F4: or          $s5, $t4, $zero
        ctx->r21 = ctx->r12 | 0;
            goto L_80007C10;
    }
    // 0x800078F4: or          $s5, $t4, $zero
    ctx->r21 = ctx->r12 | 0;
    // 0x800078F8: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x800078FC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80007900: addu        $s2, $t3, $t6
    ctx->r18 = ADD32(ctx->r11, ctx->r14);
L_80007904:
    // 0x80007904: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80007908: nop

    // 0x8000790C: lw          $v0, 0x64($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X64);
    // 0x80007910: nop

    // 0x80007914: beq         $v0, $zero, L_80007C04
    if (ctx->r2 == 0) {
        // 0x80007918: lw          $t2, 0xCC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XCC);
            goto L_80007C04;
    }
    // 0x80007918: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x8000791C: lw          $t8, 0x118($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X118);
    // 0x80007920: nop

    // 0x80007924: beq         $t8, $zero, L_80007C00
    if (ctx->r24 == 0) {
        // 0x80007928: sw          $t8, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r24;
            goto L_80007C00;
    }
    // 0x80007928: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x8000792C: lb          $t1, 0x1D8($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1D8);
    // 0x80007930: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80007934: beq         $t1, $zero, L_80007974
    if (ctx->r9 == 0) {
        // 0x80007938: sll         $t0, $t2, 4
        ctx->r8 = S32(ctx->r10 << 4);
            goto L_80007974;
    }
    // 0x80007938: sll         $t0, $t2, 4
    ctx->r8 = S32(ctx->r10 << 4);
    // 0x8000793C: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80007940: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80007944: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80007948: addu        $v1, $s7, $t0
    ctx->r3 = ADD32(ctx->r23, ctx->r8);
    // 0x8000794C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80007950: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80007954: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80007958: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000795C: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80007960: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80007964: sub.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80007968: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8000796C: b           L_800079A0
    // 0x80007970: sub.s       $f22, $f6, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f16.fl;
        goto L_800079A0;
    // 0x80007970: sub.s       $f22, $f6, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f16.fl;
L_80007974:
    // 0x80007974: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80007978: lw          $s0, 0x0($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X0);
    // 0x8000797C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80007980: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80007984: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80007988: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8000798C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80007990: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80007994: sub.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80007998: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8000799C: sub.s       $f22, $f6, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f16.fl;
L_800079A0:
    // 0x800079A0: mul.s       $f10, $f20, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800079A4: nop

    // 0x800079A8: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800079AC: nop

    // 0x800079B0: mul.s       $f8, $f22, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800079B4: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800079B8: jal         0x800CA030
    // 0x800079BC: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_20;
    // 0x800079BC: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    after_20:
    // 0x800079C0: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x800079C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800079C8: swc1        $f0, 0x84($t4)
    MEM_W(0X84, ctx->r12) = ctx->f0.u32l;
    // 0x800079CC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800079D0: lwc1        $f6, 0x5280($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5280);
    // 0x800079D4: lwc1        $f2, 0x84($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X84);
    // 0x800079D8: nop

    // 0x800079DC: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800079E0: nop

    // 0x800079E4: bc1f        L_80007C04
    if (!c1cs) {
        // 0x800079E8: lw          $t2, 0xCC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XCC);
            goto L_80007C04;
    }
    // 0x800079E8: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x800079EC: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800079F0: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800079F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800079F8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800079FC: sub.s       $f10, $f30, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f30.fl - ctx->f16.fl;
    // 0x80007A00: nop

    // 0x80007A04: div.s       $f26, $f10, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = DIV_S(ctx->f10.fl, ctx->f30.fl);
    // 0x80007A08: mul.s       $f18, $f4, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80007A0C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80007A10: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80007A14: nop

    // 0x80007A18: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80007A1C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80007A20: nop

    // 0x80007A24: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80007A28: beq         $v0, $zero, L_80007A74
    if (ctx->r2 == 0) {
        // 0x80007A2C: nop
    
            goto L_80007A74;
    }
    // 0x80007A2C: nop

    // 0x80007A30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80007A34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007A38: sub.s       $f8, $f18, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80007A3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80007A40: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80007A44: nop

    // 0x80007A48: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80007A4C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80007A50: nop

    // 0x80007A54: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80007A58: bne         $v0, $zero, L_80007A6C
    if (ctx->r2 != 0) {
        // 0x80007A5C: nop
    
            goto L_80007A6C;
    }
    // 0x80007A5C: nop

    // 0x80007A60: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80007A64: b           L_80007A84
    // 0x80007A68: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80007A84;
    // 0x80007A68: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80007A6C:
    // 0x80007A6C: b           L_80007A84
    // 0x80007A70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80007A84;
    // 0x80007A70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80007A74:
    // 0x80007A74: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80007A78: nop

    // 0x80007A7C: bltz        $v0, L_80007A6C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80007A80: nop
    
            goto L_80007A6C;
    }
    // 0x80007A80: nop

L_80007A84:
    // 0x80007A84: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x80007A88: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80007A8C: slti        $at, $t3, 0x80
    ctx->r1 = SIGNED(ctx->r11) < 0X80 ? 1 : 0;
    // 0x80007A90: bne         $at, $zero, L_80007A9C
    if (ctx->r1 != 0) {
        // 0x80007A94: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_80007A9C;
    }
    // 0x80007A94: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80007A98: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_80007A9C:
    // 0x80007A9C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80007AA0: bgez        $v0, L_80007ABC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80007AA4: cvt.d.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
            goto L_80007ABC;
    }
    // 0x80007AA4: cvt.d.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
    // 0x80007AA8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80007AAC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80007AB0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80007AB4: nop

    // 0x80007AB8: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_80007ABC:
    // 0x80007ABC: mul.d       $f4, $f16, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f24.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f24.d);
    // 0x80007AC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007AC4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80007AC8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80007ACC: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80007AD0: nop

    // 0x80007AD4: cvt.w.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_D(ctx->f4.d);
    // 0x80007AD8: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80007ADC: nop

    // 0x80007AE0: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80007AE4: beq         $v0, $zero, L_80007B34
    if (ctx->r2 == 0) {
        // 0x80007AE8: nop
    
            goto L_80007B34;
    }
    // 0x80007AE8: nop

    // 0x80007AEC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80007AF0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80007AF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007AF8: sub.d       $f18, $f4, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f4.d - ctx->f18.d;
    // 0x80007AFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80007B00: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80007B04: nop

    // 0x80007B08: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x80007B0C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80007B10: nop

    // 0x80007B14: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80007B18: bne         $v0, $zero, L_80007B2C
    if (ctx->r2 != 0) {
        // 0x80007B1C: nop
    
            goto L_80007B2C;
    }
    // 0x80007B1C: nop

    // 0x80007B20: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80007B24: b           L_80007B44
    // 0x80007B28: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80007B44;
    // 0x80007B28: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80007B2C:
    // 0x80007B2C: b           L_80007B44
    // 0x80007B30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80007B44;
    // 0x80007B30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80007B34:
    // 0x80007B34: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80007B38: nop

    // 0x80007B3C: bltz        $v0, L_80007B2C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80007B40: nop
    
            goto L_80007B2C;
    }
    // 0x80007B40: nop

L_80007B44:
    // 0x80007B44: lbu         $t8, 0x88($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X88);
    // 0x80007B48: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x80007B4C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80007B50: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80007B54: beq         $at, $zero, L_80007C04
    if (ctx->r1 == 0) {
        // 0x80007B58: lw          $t2, 0xCC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XCC);
            goto L_80007C04;
    }
    // 0x80007B58: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x80007B5C: sb          $t7, 0x88($s0)
    MEM_B(0X88, ctx->r16) = ctx->r15;
    // 0x80007B60: lh          $a2, 0x0($s7)
    ctx->r6 = MEM_H(ctx->r23, 0X0);
    // 0x80007B64: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80007B68: jal         0x800090C0
    // 0x80007B6C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_21;
    // 0x80007B6C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_21:
    // 0x80007B70: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80007B74: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x80007B78: sb          $v0, 0x91($t9)
    MEM_B(0X91, ctx->r25) = ctx->r2;
    // 0x80007B7C: lb          $t1, 0x1D8($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1D8);
    // 0x80007B80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80007B84: beq         $t1, $zero, L_80007BA4
    if (ctx->r9 == 0) {
        // 0x80007B88: nop
    
            goto L_80007BA4;
    }
    // 0x80007B88: nop

    // 0x80007B8C: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x80007B90: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80007B94: jal         0x80006BFC
    // 0x80007B98: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    racer_sound_doppler_effect(rdram, ctx);
        goto after_22;
    // 0x80007B98: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_22:
    // 0x80007B9C: b           L_80007BB8
    // 0x80007BA0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
        goto L_80007BB8;
    // 0x80007BA0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
L_80007BA4:
    // 0x80007BA4: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x80007BA8: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80007BAC: jal         0x80006BFC
    // 0x80007BB0: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    racer_sound_doppler_effect(rdram, ctx);
        goto after_23;
    // 0x80007BB0: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_23:
    // 0x80007BB4: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
L_80007BB8:
    // 0x80007BB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007BBC: lwc1        $f8, 0x5C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80007BC0: lwc1        $f6, 0x68($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80007BC4: nop

    // 0x80007BC8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80007BCC: swc1        $f10, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f10.u32l;
    // 0x80007BD0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007BD4: nop

    // 0x80007BD8: lwc1        $f16, 0x8C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80007BDC: nop

    // 0x80007BE0: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80007BE4: c.lt.d      $f4, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f4.d < ctx->f28.d;
    // 0x80007BE8: nop

    // 0x80007BEC: bc1f        L_80007C04
    if (!c1cs) {
        // 0x80007BF0: lw          $t2, 0xCC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XCC);
            goto L_80007C04;
    }
    // 0x80007BF0: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x80007BF4: lwc1        $f18, 0x5284($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5284);
    // 0x80007BF8: nop

    // 0x80007BFC: swc1        $f18, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f18.u32l;
L_80007C00:
    // 0x80007C00: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
L_80007C04:
    // 0x80007C04: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80007C08: bne         $s5, $t2, L_80007904
    if (ctx->r21 != ctx->r10) {
        // 0x80007C0C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80007904;
    }
    // 0x80007C0C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80007C10:
    // 0x80007C10: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x80007C14: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x80007C18: addiu       $t4, $t0, 0x1
    ctx->r12 = ADD32(ctx->r8, 0X1);
    // 0x80007C1C: sw          $t4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r12;
    // 0x80007C20: bne         $t4, $t5, L_800078DC
    if (ctx->r12 != ctx->r13) {
        // 0x80007C24: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_800078DC;
    }
    // 0x80007C24: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_80007C28:
    // 0x80007C28: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80007C2C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80007C30: addiu       $s0, $s0, -0x5E48
    ctx->r16 = ADD32(ctx->r16, -0X5E48);
    // 0x80007C34: addiu       $s3, $s3, -0x5E50
    ctx->r19 = ADD32(ctx->r19, -0X5E50);
L_80007C38:
    // 0x80007C38: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80007C3C: nop

    // 0x80007C40: beq         $v0, $zero, L_80007C90
    if (ctx->r2 == 0) {
        // 0x80007C44: nop
    
            goto L_80007C90;
    }
    // 0x80007C44: nop

    // 0x80007C48: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
    // 0x80007C4C: nop

    // 0x80007C50: beq         $a0, $zero, L_80007C90
    if (ctx->r4 == 0) {
        // 0x80007C54: nop
    
            goto L_80007C90;
    }
    // 0x80007C54: nop

    // 0x80007C58: lbu         $t3, 0x88($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X88);
    // 0x80007C5C: nop

    // 0x80007C60: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x80007C64: beq         $at, $zero, L_80007C90
    if (ctx->r1 == 0) {
        // 0x80007C68: nop
    
            goto L_80007C90;
    }
    // 0x80007C68: nop

    // 0x80007C6C: jal         0x8000488C
    // 0x80007C70: nop

    sndp_stop(rdram, ctx);
        goto after_24;
    // 0x80007C70: nop

    after_24:
    // 0x80007C74: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80007C78: nop

    // 0x80007C7C: sw          $zero, 0x48($t6)
    MEM_W(0X48, ctx->r14) = 0;
    // 0x80007C80: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80007C84: nop

    // 0x80007C88: sb          $zero, 0x74($t7)
    MEM_B(0X74, ctx->r15) = 0;
    // 0x80007C8C: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_80007C90:
    // 0x80007C90: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80007C94: bne         $s3, $s0, L_80007C38
    if (ctx->r19 != ctx->r16) {
        // 0x80007C98: nop
    
            goto L_80007C38;
    }
    // 0x80007C98: nop

    // 0x80007C9C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80007CA0: addiu       $a3, $a3, -0x33BC
    ctx->r7 = ADD32(ctx->r7, -0X33BC);
    // 0x80007CA4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80007CA8: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x80007CAC: slt         $at, $fp, $v0
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80007CB0: beq         $at, $zero, L_80007CC0
    if (ctx->r1 == 0) {
        // 0x80007CB4: subu        $t8, $v0, $fp
        ctx->r24 = SUB32(ctx->r2, ctx->r30);
            goto L_80007CC0;
    }
    // 0x80007CB4: subu        $t8, $v0, $fp
    ctx->r24 = SUB32(ctx->r2, ctx->r30);
    // 0x80007CB8: b           L_80007CC4
    // 0x80007CBC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
        goto L_80007CC4;
    // 0x80007CBC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_80007CC0:
    // 0x80007CC0: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80007CC4:
    // 0x80007CC4: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x80007CC8: lw          $s2, 0xC8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC8);
    // 0x80007CCC: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80007CD0: bne         $at, $zero, L_80007E24
    if (ctx->r1 != 0) {
        // 0x80007CD4: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_80007E24;
    }
    // 0x80007CD4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80007CD8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80007CDC: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x80007CE0: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
L_80007CE4:
    // 0x80007CE4: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80007CE8: nop

    // 0x80007CEC: lw          $v0, 0x64($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X64);
    // 0x80007CF0: nop

    // 0x80007CF4: beq         $v0, $zero, L_80007E18
    if (ctx->r2 == 0) {
        // 0x80007CF8: lw          $t4, 0xCC($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XCC);
            goto L_80007E18;
    }
    // 0x80007CF8: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x80007CFC: lw          $t2, 0x118($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X118);
    // 0x80007D00: nop

    // 0x80007D04: sw          $t2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r10;
    // 0x80007D08: beq         $t2, $zero, L_80007E14
    if (ctx->r10 == 0) {
        // 0x80007D0C: or          $s0, $t2, $zero
        ctx->r16 = ctx->r10 | 0;
            goto L_80007E14;
    }
    // 0x80007D0C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80007D10: lbu         $t0, 0x74($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X74);
    // 0x80007D14: nop

    // 0x80007D18: bne         $t0, $zero, L_80007E18
    if (ctx->r8 != 0) {
        // 0x80007D1C: lw          $t4, 0xCC($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XCC);
            goto L_80007E18;
    }
    // 0x80007D1C: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x80007D20: lhu         $t4, 0x0($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X0);
    // 0x80007D24: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80007D28: beq         $t4, $zero, L_80007E14
    if (ctx->r12 == 0) {
        // 0x80007D2C: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_80007E14;
    }
    // 0x80007D2C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80007D30: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80007D34: lbu         $a1, 0x88($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X88);
    // 0x80007D38: addiu       $s3, $s3, -0x5E50
    ctx->r19 = ADD32(ctx->r19, -0X5E50);
    // 0x80007D3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80007D40:
    // 0x80007D40: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80007D44: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x80007D48: beq         $s1, $zero, L_80007D84
    if (ctx->r17 == 0) {
        // 0x80007D4C: nop
    
            goto L_80007D84;
    }
    // 0x80007D4C: nop

    // 0x80007D50: lbu         $t5, 0x88($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X88);
    // 0x80007D54: nop

    // 0x80007D58: subu        $v0, $a1, $t5
    ctx->r2 = SUB32(ctx->r5, ctx->r13);
    // 0x80007D5C: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80007D60: beq         $at, $zero, L_80007D90
    if (ctx->r1 == 0) {
        // 0x80007D64: nop
    
            goto L_80007D90;
    }
    // 0x80007D64: nop

    // 0x80007D68: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80007D6C: nop

    // 0x80007D70: bne         $t3, $zero, L_80007D90
    if (ctx->r11 != 0) {
        // 0x80007D74: nop
    
            goto L_80007D90;
    }
    // 0x80007D74: nop

    // 0x80007D78: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80007D7C: b           L_80007D90
    // 0x80007D80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80007D90;
    // 0x80007D80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80007D84:
    // 0x80007D84: bne         $at, $zero, L_80007D90
    if (ctx->r1 != 0) {
        // 0x80007D88: nop
    
            goto L_80007D90;
    }
    // 0x80007D88: nop

    // 0x80007D8C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80007D90:
    // 0x80007D90: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80007D94: bne         $v1, $s6, L_80007D40
    if (ctx->r3 != ctx->r22) {
        // 0x80007D98: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80007D40;
    }
    // 0x80007D98: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80007D9C: beq         $a0, $fp, L_80007E14
    if (ctx->r4 == ctx->r30) {
        // 0x80007DA0: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80007E14;
    }
    // 0x80007DA0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80007DA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80007DA8: addiu       $t7, $t7, -0x5E50
    ctx->r15 = ADD32(ctx->r15, -0X5E50);
    // 0x80007DAC: sb          $s7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r23;
    // 0x80007DB0: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x80007DB4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80007DB8: nop

    // 0x80007DBC: beq         $v0, $zero, L_80007E08
    if (ctx->r2 == 0) {
        // 0x80007DC0: nop
    
            goto L_80007E08;
    }
    // 0x80007DC0: nop

    // 0x80007DC4: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
    // 0x80007DC8: nop

    // 0x80007DCC: beq         $a0, $zero, L_80007E00
    if (ctx->r4 == 0) {
        // 0x80007DD0: addiu       $t2, $zero, 0x3C
        ctx->r10 = ADD32(0, 0X3C);
            goto L_80007E00;
    }
    // 0x80007DD0: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x80007DD4: jal         0x8000488C
    // 0x80007DD8: nop

    sndp_stop(rdram, ctx);
        goto after_25;
    // 0x80007DD8: nop

    after_25:
    // 0x80007DDC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80007DE0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80007DE4: sw          $zero, 0x48($t8)
    MEM_W(0X48, ctx->r24) = 0;
    // 0x80007DE8: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80007DEC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80007DF0: sb          $t9, 0x74($t1)
    MEM_B(0X74, ctx->r9) = ctx->r25;
    // 0x80007DF4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80007DF8: addiu       $a3, $a3, -0x33BC
    ctx->r7 = ADD32(ctx->r7, -0X33BC);
    // 0x80007DFC: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
L_80007E00:
    // 0x80007E00: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80007E04: sb          $zero, 0x74($v0)
    MEM_B(0X74, ctx->r2) = 0;
L_80007E08:
    // 0x80007E08: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x80007E0C: nop

    // 0x80007E10: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
L_80007E14:
    // 0x80007E14: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
L_80007E18:
    // 0x80007E18: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80007E1C: bne         $s5, $t4, L_80007CE4
    if (ctx->r21 != ctx->r12) {
        // 0x80007E20: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80007CE4;
    }
    // 0x80007E20: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80007E24:
    // 0x80007E24: jal         0x8001139C
    // 0x80007E28: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    get_race_countdown(rdram, ctx);
        goto after_26;
    // 0x80007E28: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    after_26:
    // 0x80007E2C: bgtz        $v0, L_80007F18
    if (SIGNED(ctx->r2) > 0) {
        // 0x80007E30: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_80007F18;
    }
    // 0x80007E30: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80007E34: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80007E38: addiu       $s0, $s0, -0x5E48
    ctx->r16 = ADD32(ctx->r16, -0X5E48);
    // 0x80007E3C: addiu       $s3, $s3, -0x5E50
    ctx->r19 = ADD32(ctx->r19, -0X5E50);
L_80007E40:
    // 0x80007E40: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80007E44: nop

    // 0x80007E48: beq         $s1, $zero, L_80007F0C
    if (ctx->r17 == 0) {
        // 0x80007E4C: nop
    
            goto L_80007F0C;
    }
    // 0x80007E4C: nop

    // 0x80007E50: lhu         $a2, 0x0($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X0);
    // 0x80007E54: nop

    // 0x80007E58: beq         $a2, $zero, L_80007F0C
    if (ctx->r6 == 0) {
        // 0x80007E5C: nop
    
            goto L_80007F0C;
    }
    // 0x80007E5C: nop

    // 0x80007E60: lbu         $t5, 0x74($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X74);
    // 0x80007E64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007E68: bne         $t5, $at, L_80007E78
    if (ctx->r13 != ctx->r1) {
        // 0x80007E6C: nop
    
            goto L_80007E78;
    }
    // 0x80007E6C: nop

    // 0x80007E70: b           L_80007F0C
    // 0x80007E74: sb          $s7, 0x74($s1)
    MEM_B(0X74, ctx->r17) = ctx->r23;
        goto L_80007F0C;
    // 0x80007E74: sb          $s7, 0x74($s1)
    MEM_B(0X74, ctx->r17) = ctx->r23;
L_80007E78:
    // 0x80007E78: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007E7C: addiu       $a1, $s1, 0x48
    ctx->r5 = ADD32(ctx->r17, 0X48);
    // 0x80007E80: bne         $a0, $zero, L_80007E98
    if (ctx->r4 != 0) {
        // 0x80007E84: nop
    
            goto L_80007E98;
    }
    // 0x80007E84: nop

    // 0x80007E88: jal         0x80001F14
    // 0x80007E8C: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    sound_play_direct(rdram, ctx);
        goto after_27;
    // 0x80007E8C: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    after_27:
    // 0x80007E90: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007E94: nop

L_80007E98:
    // 0x80007E98: beq         $a0, $zero, L_80007F0C
    if (ctx->r4 == 0) {
        // 0x80007E9C: nop
    
            goto L_80007F0C;
    }
    // 0x80007E9C: nop

    // 0x80007EA0: lw          $a1, 0x78($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X78);
    // 0x80007EA4: lw          $a2, 0x7C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X7C);
    // 0x80007EA8: lw          $a3, 0x80($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X80);
    // 0x80007EAC: jal         0x80009B7C
    // 0x80007EB0: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_28;
    // 0x80007EB0: nop

    after_28:
    // 0x80007EB4: lbu         $a2, 0x88($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X88);
    // 0x80007EB8: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007EBC: sll         $t3, $a2, 8
    ctx->r11 = S32(ctx->r6 << 8);
    // 0x80007EC0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80007EC4: jal         0x800049F8
    // 0x80007EC8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    sndp_set_param(rdram, ctx);
        goto after_29;
    // 0x80007EC8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_29:
    // 0x80007ECC: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007ED0: lw          $a2, 0x8C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8C);
    // 0x80007ED4: jal         0x800049F8
    // 0x80007ED8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_30;
    // 0x80007ED8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_30:
    // 0x80007EDC: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x80007EE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007EE4: beq         $t6, $at, L_80007EF0
    if (ctx->r14 == ctx->r1) {
        // 0x80007EE8: addiu       $t7, $zero, 0x40
        ctx->r15 = ADD32(0, 0X40);
            goto L_80007EF0;
    }
    // 0x80007EE8: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80007EEC: sb          $t7, 0x91($s1)
    MEM_B(0X91, ctx->r17) = ctx->r15;
L_80007EF0:
    // 0x80007EF0: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007EF4: lbu         $a2, 0x91($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X91);
    // 0x80007EF8: jal         0x800049F8
    // 0x80007EFC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sndp_set_param(rdram, ctx);
        goto after_31;
    // 0x80007EFC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_31:
    // 0x80007F00: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007F04: jal         0x80004604
    // 0x80007F08: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    sndp_set_priority(rdram, ctx);
        goto after_32;
    // 0x80007F08: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_32:
L_80007F0C:
    // 0x80007F0C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80007F10: bne         $s3, $s0, L_80007E40
    if (ctx->r19 != ctx->r16) {
        // 0x80007F14: nop
    
            goto L_80007E40;
    }
    // 0x80007F14: nop

L_80007F18:
    // 0x80007F18: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80007F1C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80007F20: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80007F24: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80007F28: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80007F2C: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80007F30: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80007F34: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80007F38: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80007F3C: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80007F40: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80007F44: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80007F48: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80007F4C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80007F50: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80007F54: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80007F58: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80007F5C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80007F60: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80007F64: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80007F68: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80007F6C: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80007F70: jr          $ra
    // 0x80007F74: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80007F74: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void hud_lap_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A549C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A54A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A54A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A54A8: lb          $t7, 0x1D8($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X1D8);
    // 0x800A54AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A54B0: bne         $t7, $zero, L_800A56D8
    if (ctx->r15 != 0) {
        // 0x800A54B4: nop
    
            goto L_800A56D8;
    }
    // 0x800A54B4: nop

    // 0x800A54B8: lw          $v0, 0x72CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72CC);
    // 0x800A54BC: nop

    // 0x800A54C0: blez        $v0, L_800A54F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A54C4: nop
    
            goto L_800A54F0;
    }
    // 0x800A54C4: nop

    // 0x800A54C8: lb          $v1, 0x193($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X193);
    // 0x800A54CC: nop

    // 0x800A54D0: blez        $v1, L_800A54F0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A54D4: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_800A54F0;
    }
    // 0x800A54D4: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800A54D8: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800A54DC: lw          $t3, 0x128($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X128);
    // 0x800A54E0: nop

    // 0x800A54E4: slti        $at, $t3, 0xB4
    ctx->r1 = SIGNED(ctx->r11) < 0XB4 ? 1 : 0;
    // 0x800A54E8: bne         $at, $zero, L_800A56D8
    if (ctx->r1 != 0) {
        // 0x800A54EC: nop
    
            goto L_800A56D8;
    }
    // 0x800A54EC: nop

L_800A54F0:
    // 0x800A54F0: blez        $v0, L_800A5520
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A54F4: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800A5520;
    }
    // 0x800A54F4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A54F8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800A54FC: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800A5500: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x800A5504: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800A5508: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x800A550C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x800A5510: lbu         $t8, 0x2D14($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X2D14);
    // 0x800A5514: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A5518: bne         $t8, $at, L_800A56D8
    if (ctx->r24 != ctx->r1) {
        // 0x800A551C: nop
    
            goto L_800A56D8;
    }
    // 0x800A551C: nop

L_800A5520:
    // 0x800A5520: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800A5524: lw          $t9, 0x7320($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7320);
    // 0x800A5528: lb          $t4, 0x194($t5)
    ctx->r12 = MEM_B(ctx->r13, 0X194);
    // 0x800A552C: lb          $t3, 0x4B($t9)
    ctx->r11 = MEM_B(ctx->r25, 0X4B);
    // 0x800A5530: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x800A5534: bne         $t3, $t7, L_800A55DC
    if (ctx->r11 != ctx->r15) {
        // 0x800A5538: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_800A55DC;
    }
    // 0x800A5538: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800A553C: beq         $at, $zero, L_800A55DC
    if (ctx->r1 == 0) {
        // 0x800A5540: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800A55DC;
    }
    // 0x800A5540: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5544: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5548: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A554C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5550: lb          $t6, 0x21A($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X21A);
    // 0x800A5554: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5558: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800A555C: sb          $t9, 0x21A($v0)
    MEM_B(0X21A, ctx->r2) = ctx->r25;
    // 0x800A5560: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5564: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5568: lb          $t5, 0x21A($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X21A);
    // 0x800A556C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A5570: slti        $at, $t5, 0x7
    ctx->r1 = SIGNED(ctx->r13) < 0X7 ? 1 : 0;
    // 0x800A5574: bne         $at, $zero, L_800A55CC
    if (ctx->r1 != 0) {
        // 0x800A5578: addiu       $a0, $a0, 0x72BC
        ctx->r4 = ADD32(ctx->r4, 0X72BC);
            goto L_800A55CC;
    }
    // 0x800A5578: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A557C: lh          $t4, 0x218($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X218);
    // 0x800A5580: nop

    // 0x800A5584: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x800A5588: sh          $t3, 0x218($v0)
    MEM_H(0X218, ctx->r2) = ctx->r11;
    // 0x800A558C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5590: nop

    // 0x800A5594: lb          $t7, 0x21A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X21A);
    // 0x800A5598: nop

    // 0x800A559C: addiu       $t6, $t7, -0x6
    ctx->r14 = ADD32(ctx->r15, -0X6);
    // 0x800A55A0: sb          $t6, 0x21A($v0)
    MEM_B(0X21A, ctx->r2) = ctx->r14;
    // 0x800A55A4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A55A8: nop

    // 0x800A55AC: lh          $t8, 0x218($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X218);
    // 0x800A55B0: nop

    // 0x800A55B4: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x800A55B8: bne         $at, $zero, L_800A55CC
    if (ctx->r1 != 0) {
        // 0x800A55BC: nop
    
            goto L_800A55CC;
    }
    // 0x800A55BC: nop

    // 0x800A55C0: sh          $zero, 0x218($v0)
    MEM_H(0X218, ctx->r2) = 0;
    // 0x800A55C4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A55C8: nop

L_800A55CC:
    // 0x800A55CC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A55D0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A55D4: jal         0x800AAB5C
    // 0x800A55D8: addiu       $a3, $v0, 0x200
    ctx->r7 = ADD32(ctx->r2, 0X200);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A55D8: addiu       $a3, $v0, 0x200
    ctx->r7 = ADD32(ctx->r2, 0X200);
    after_0:
L_800A55DC:
    // 0x800A55DC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A55E0: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A55E4: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A55E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A55EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A55F0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A55F4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A55F8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A55FC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5600: jal         0x800AAB5C
    // 0x800A5604: addiu       $a3, $a3, 0x60
    ctx->r7 = ADD32(ctx->r7, 0X60);
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A5604: addiu       $a3, $a3, 0x60
    ctx->r7 = ADD32(ctx->r7, 0X60);
    after_1:
    // 0x800A5608: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A560C: addiu       $t2, $t2, 0x7320
    ctx->r10 = ADD32(ctx->r10, 0X7320);
    // 0x800A5610: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x800A5614: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A5618: lb          $v0, 0x4B($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X4B);
    // 0x800A561C: lb          $v1, 0x194($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X194);
    // 0x800A5620: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x800A5624: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5628: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800A562C: bne         $at, $zero, L_800A5640
    if (ctx->r1 != 0) {
        // 0x800A5630: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A5640;
    }
    // 0x800A5630: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5634: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A5638: b           L_800A564C
    // 0x800A563C: sh          $v0, 0x98($t4)
    MEM_H(0X98, ctx->r12) = ctx->r2;
        goto L_800A564C;
    // 0x800A563C: sh          $v0, 0x98($t4)
    MEM_H(0X98, ctx->r12) = ctx->r2;
L_800A5640:
    // 0x800A5640: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5644: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x800A5648: sh          $t3, 0x98($t7)
    MEM_H(0X98, ctx->r15) = ctx->r11;
L_800A564C:
    // 0x800A564C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800A5650: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A5654: lb          $t8, 0x4B($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X4B);
    // 0x800A5658: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A565C: sh          $t8, 0xD8($t9)
    MEM_H(0XD8, ctx->r25) = ctx->r24;
    // 0x800A5660: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5664: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5668: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A566C: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5670: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A5674: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5678: jal         0x800AAB5C
    // 0x800A567C: addiu       $a3, $a3, 0x80
    ctx->r7 = ADD32(ctx->r7, 0X80);
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A567C: addiu       $a3, $a3, 0x80
    ctx->r7 = ADD32(ctx->r7, 0X80);
    after_2:
    // 0x800A5680: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5684: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5688: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A568C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5690: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5694: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5698: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A569C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A56A0: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A56A4: jal         0x800AAB5C
    // 0x800A56A8: addiu       $a3, $a3, 0xA0
    ctx->r7 = ADD32(ctx->r7, 0XA0);
    hud_element_render(rdram, ctx);
        goto after_3;
    // 0x800A56A8: addiu       $a3, $a3, 0xA0
    ctx->r7 = ADD32(ctx->r7, 0XA0);
    after_3:
    // 0x800A56AC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A56B0: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A56B4: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A56B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A56BC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A56C0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A56C4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A56C8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A56CC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A56D0: jal         0x800AAB5C
    // 0x800A56D4: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, 0XC0);
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A56D4: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, 0XC0);
    after_4:
L_800A56D8:
    // 0x800A56D8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A56DC: lw          $t5, 0x72CC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72CC);
    // 0x800A56E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A56E4: bne         $t5, $at, L_800A56F4
    if (ctx->r13 != ctx->r1) {
        // 0x800A56E8: nop
    
            goto L_800A56F4;
    }
    // 0x800A56E8: nop

    // 0x800A56EC: jal         0x8007C36C
    // 0x800A56F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_5;
    // 0x800A56F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
L_800A56F4:
    // 0x800A56F4: jal         0x8006ECE0
    // 0x800A56F8: nop

    is_game_paused(rdram, ctx);
        goto after_6;
    // 0x800A56F8: nop

    after_6:
    // 0x800A56FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5700: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A5704: bne         $v0, $zero, L_800A5F94
    if (ctx->r2 != 0) {
        // 0x800A5708: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A5F94;
    }
    // 0x800A5708: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A570C: lb          $v1, 0x193($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X193);
    // 0x800A5710: nop

    // 0x800A5714: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800A5718: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x800A571C: lw          $t7, 0x128($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X128);
    // 0x800A5720: nop

    // 0x800A5724: slti        $at, $t7, 0x1E
    ctx->r1 = SIGNED(ctx->r15) < 0X1E ? 1 : 0;
    // 0x800A5728: beq         $at, $zero, L_800A5A28
    if (ctx->r1 == 0) {
        // 0x800A572C: nop
    
            goto L_800A5A28;
    }
    // 0x800A572C: nop

    // 0x800A5730: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5734: nop

    // 0x800A5738: lb          $t6, 0x3DA($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X3DA);
    // 0x800A573C: nop

    // 0x800A5740: bne         $t6, $zero, L_800A5A28
    if (ctx->r14 != 0) {
        // 0x800A5744: nop
    
            goto L_800A5A28;
    }
    // 0x800A5744: nop

    // 0x800A5748: lb          $t8, 0x1D8($t1)
    ctx->r24 = MEM_B(ctx->r9, 0X1D8);
    // 0x800A574C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A5750: bne         $t8, $zero, L_800A5A28
    if (ctx->r24 != 0) {
        // 0x800A5754: nop
    
            goto L_800A5A28;
    }
    // 0x800A5754: nop

    // 0x800A5758: bne         $a2, $v1, L_800A58BC
    if (ctx->r6 != ctx->r3) {
        // 0x800A575C: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800A58BC;
    }
    // 0x800A575C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A5760: lw          $t9, 0x7320($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7320);
    // 0x800A5764: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800A5768: lb          $t5, 0x4B($t9)
    ctx->r13 = MEM_B(ctx->r25, 0X4B);
    // 0x800A576C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A5770: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x800A5774: bne         $at, $zero, L_800A58BC
    if (ctx->r1 != 0) {
        // 0x800A5778: nop
    
            goto L_800A58BC;
    }
    // 0x800A5778: nop

    // 0x800A577C: sb          $t4, 0x3DA($v0)
    MEM_B(0X3DA, ctx->r2) = ctx->r12;
    // 0x800A5780: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A5784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A5788: sb          $a2, 0x3DB($t3)
    MEM_B(0X3DB, ctx->r11) = ctx->r6;
    // 0x800A578C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5790: jal         0x80001D04
    // 0x800A5794: sb          $zero, 0x3DD($t7)
    MEM_B(0X3DD, ctx->r15) = 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x800A5794: sb          $zero, 0x3DD($t7)
    MEM_B(0X3DD, ctx->r15) = 0;
    after_7:
    // 0x800A5798: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A579C: lw          $v0, 0x72CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72CC);
    // 0x800A57A0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A57A4: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A57A8: beq         $v0, $zero, L_800A57C4
    if (ctx->r2 == 0) {
        // 0x800A57AC: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A57C4;
    }
    // 0x800A57AC: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A57B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A57B4: beq         $v0, $at, L_800A5800
    if (ctx->r2 == ctx->r1) {
        // 0x800A57B8: addiu       $t7, $zero, -0x10
        ctx->r15 = ADD32(0, -0X10);
            goto L_800A5800;
    }
    // 0x800A57B8: addiu       $t7, $zero, -0x10
    ctx->r15 = ADD32(0, -0X10);
    // 0x800A57BC: b           L_800A5838
    // 0x800A57C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_800A5838;
    // 0x800A57C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800A57C4:
    // 0x800A57C4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A57C8: addiu       $t6, $zero, -0x15
    ctx->r14 = ADD32(0, -0X15);
    // 0x800A57CC: sb          $t6, 0x3DC($t8)
    MEM_B(0X3DC, ctx->r24) = ctx->r14;
    // 0x800A57D0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A57D4: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x800A57D8: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A57DC: sb          $t9, 0x3FC($t5)
    MEM_B(0X3FC, ctx->r13) = ctx->r25;
    // 0x800A57E0: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A57E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A57E8: lui         $at, 0x4353
    ctx->r1 = S32(0X4353 << 16);
    // 0x800A57EC: swc1        $f4, 0x3CC($t4)
    MEM_W(0X3CC, ctx->r12) = ctx->f4.u32l;
    // 0x800A57F0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A57F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A57F8: b           L_800A5A28
    // 0x800A57FC: swc1        $f6, 0x3EC($t3)
    MEM_W(0X3EC, ctx->r11) = ctx->f6.u32l;
        goto L_800A5A28;
    // 0x800A57FC: swc1        $f6, 0x3EC($t3)
    MEM_W(0X3EC, ctx->r11) = ctx->f6.u32l;
L_800A5800:
    // 0x800A5800: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5804: addiu       $t8, $zero, 0x1B
    ctx->r24 = ADD32(0, 0X1B);
    // 0x800A5808: sb          $t7, 0x3DC($t6)
    MEM_B(0X3DC, ctx->r14) = ctx->r15;
    // 0x800A580C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A5810: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A5814: sb          $t8, 0x3FC($t9)
    MEM_B(0X3FC, ctx->r25) = ctx->r24;
    // 0x800A5818: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A581C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A5820: lui         $at, 0x4353
    ctx->r1 = S32(0X4353 << 16);
    // 0x800A5824: swc1        $f8, 0x3CC($t5)
    MEM_W(0X3CC, ctx->r13) = ctx->f8.u32l;
    // 0x800A5828: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A582C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A5830: b           L_800A5A28
    // 0x800A5834: swc1        $f10, 0x3EC($t4)
    MEM_W(0X3EC, ctx->r12) = ctx->f10.u32l;
        goto L_800A5A28;
    // 0x800A5834: swc1        $f10, 0x3EC($t4)
    MEM_W(0X3EC, ctx->r12) = ctx->f10.u32l;
L_800A5838:
    // 0x800A5838: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
    // 0x800A583C: addiu       $t4, $zero, -0x5A
    ctx->r12 = ADD32(0, -0X5A);
    // 0x800A5840: beq         $v0, $zero, L_800A5888
    if (ctx->r2 == 0) {
        // 0x800A5844: addiu       $t7, $zero, -0x3B
        ctx->r15 = ADD32(0, -0X3B);
            goto L_800A5888;
    }
    // 0x800A5844: addiu       $t7, $zero, -0x3B
    ctx->r15 = ADD32(0, -0X3B);
    // 0x800A5848: beq         $v0, $at, L_800A5888
    if (ctx->r2 == ctx->r1) {
        // 0x800A584C: addiu       $t3, $zero, 0x3C
        ctx->r11 = ADD32(0, 0X3C);
            goto L_800A5888;
    }
    // 0x800A584C: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x800A5850: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5854: addiu       $t6, $zero, 0x5B
    ctx->r14 = ADD32(0, 0X5B);
    // 0x800A5858: sb          $t3, 0x3DC($t7)
    MEM_B(0X3DC, ctx->r15) = ctx->r11;
    // 0x800A585C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A5860: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x800A5864: sb          $t6, 0x3FC($t8)
    MEM_B(0X3FC, ctx->r24) = ctx->r14;
    // 0x800A5868: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A586C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A5870: lui         $at, 0x435D
    ctx->r1 = S32(0X435D << 16);
    // 0x800A5874: swc1        $f16, 0x3CC($t9)
    MEM_W(0X3CC, ctx->r25) = ctx->f16.u32l;
    // 0x800A5878: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A587C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A5880: b           L_800A5A28
    // 0x800A5884: swc1        $f18, 0x3EC($t5)
    MEM_W(0X3EC, ctx->r13) = ctx->f18.u32l;
        goto L_800A5A28;
    // 0x800A5884: swc1        $f18, 0x3EC($t5)
    MEM_W(0X3EC, ctx->r13) = ctx->f18.u32l;
L_800A5888:
    // 0x800A5888: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A588C: lui         $at, 0xC35C
    ctx->r1 = S32(0XC35C << 16);
    // 0x800A5890: sb          $t4, 0x3DC($t3)
    MEM_B(0X3DC, ctx->r11) = ctx->r12;
    // 0x800A5894: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5898: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A589C: sb          $t7, 0x3FC($t6)
    MEM_B(0X3FC, ctx->r14) = ctx->r15;
    // 0x800A58A0: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A58A4: lui         $at, 0x428E
    ctx->r1 = S32(0X428E << 16);
    // 0x800A58A8: swc1        $f4, 0x3CC($t8)
    MEM_W(0X3CC, ctx->r24) = ctx->f4.u32l;
    // 0x800A58AC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A58B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A58B4: b           L_800A5A28
    // 0x800A58B8: swc1        $f6, 0x3EC($t9)
    MEM_W(0X3EC, ctx->r25) = ctx->f6.u32l;
        goto L_800A5A28;
    // 0x800A58B8: swc1        $f6, 0x3EC($t9)
    MEM_W(0X3EC, ctx->r25) = ctx->f6.u32l;
L_800A58BC:
    // 0x800A58BC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A58C0: lw          $t5, 0x7320($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7320);
    // 0x800A58C4: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x800A58C8: lb          $t4, 0x4B($t5)
    ctx->r12 = MEM_B(ctx->r13, 0X4B);
    // 0x800A58CC: nop

    // 0x800A58D0: bne         $t4, $t3, L_800A5A28
    if (ctx->r12 != ctx->r11) {
        // 0x800A58D4: nop
    
            goto L_800A5A28;
    }
    // 0x800A58D4: nop

    // 0x800A58D8: beq         $v1, $zero, L_800A5A28
    if (ctx->r3 == 0) {
        // 0x800A58DC: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_800A5A28;
    }
    // 0x800A58DC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800A58E0: sb          $t7, 0x3DA($v0)
    MEM_B(0X3DA, ctx->r2) = ctx->r15;
    // 0x800A58E4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A58E8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800A58EC: sb          $t6, 0x3DB($t8)
    MEM_B(0X3DB, ctx->r24) = ctx->r14;
    // 0x800A58F0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A58F4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A58F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A58FC: jal         0x80001D04
    // 0x800A5900: sb          $zero, 0x3DD($t9)
    MEM_B(0X3DD, ctx->r25) = 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800A5900: sb          $zero, 0x3DD($t9)
    MEM_B(0X3DD, ctx->r25) = 0;
    after_8:
    // 0x800A5904: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A5908: lw          $v0, 0x72CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72CC);
    // 0x800A590C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5910: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A5914: beq         $v0, $zero, L_800A5930
    if (ctx->r2 == 0) {
        // 0x800A5918: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A5930;
    }
    // 0x800A5918: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A591C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A5920: beq         $v0, $at, L_800A596C
    if (ctx->r2 == ctx->r1) {
        // 0x800A5924: addiu       $t9, $zero, 0x29
        ctx->r25 = ADD32(0, 0X29);
            goto L_800A596C;
    }
    // 0x800A5924: addiu       $t9, $zero, 0x29
    ctx->r25 = ADD32(0, 0X29);
    // 0x800A5928: b           L_800A59A4
    // 0x800A592C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_800A59A4;
    // 0x800A592C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800A5930:
    // 0x800A5930: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A5934: addiu       $t5, $zero, 0x33
    ctx->r13 = ADD32(0, 0X33);
    // 0x800A5938: sb          $t5, 0x3DC($t4)
    MEM_B(0X3DC, ctx->r12) = ctx->r13;
    // 0x800A593C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5940: addiu       $t3, $zero, -0x29
    ctx->r11 = ADD32(0, -0X29);
    // 0x800A5944: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x800A5948: sb          $t3, 0x3BC($t7)
    MEM_B(0X3BC, ctx->r15) = ctx->r11;
    // 0x800A594C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5950: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A5954: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A5958: swc1        $f8, 0x3CC($t6)
    MEM_W(0X3CC, ctx->r14) = ctx->f8.u32l;
    // 0x800A595C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A5960: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A5964: b           L_800A5A28
    // 0x800A5968: swc1        $f10, 0x3AC($t8)
    MEM_W(0X3AC, ctx->r24) = ctx->f10.u32l;
        goto L_800A5A28;
    // 0x800A5968: swc1        $f10, 0x3AC($t8)
    MEM_W(0X3AC, ctx->r24) = ctx->f10.u32l;
L_800A596C:
    // 0x800A596C: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A5970: addiu       $t4, $zero, -0x1F
    ctx->r12 = ADD32(0, -0X1F);
    // 0x800A5974: sb          $t9, 0x3DC($t5)
    MEM_B(0X3DC, ctx->r13) = ctx->r25;
    // 0x800A5978: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A597C: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x800A5980: sb          $t4, 0x3BC($t3)
    MEM_B(0X3BC, ctx->r11) = ctx->r12;
    // 0x800A5984: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5988: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A598C: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A5990: swc1        $f16, 0x3CC($t7)
    MEM_W(0X3CC, ctx->r15) = ctx->f16.u32l;
    // 0x800A5994: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5998: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A599C: b           L_800A5A28
    // 0x800A59A0: swc1        $f18, 0x3AC($t6)
    MEM_W(0X3AC, ctx->r14) = ctx->f18.u32l;
        goto L_800A5A28;
    // 0x800A59A0: swc1        $f18, 0x3AC($t6)
    MEM_W(0X3AC, ctx->r14) = ctx->f18.u32l;
L_800A59A4:
    // 0x800A59A4: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
    // 0x800A59A8: addiu       $t6, $zero, -0x32
    ctx->r14 = ADD32(0, -0X32);
    // 0x800A59AC: beq         $v0, $zero, L_800A59F4
    if (ctx->r2 == 0) {
        // 0x800A59B0: addiu       $t9, $zero, -0x64
        ctx->r25 = ADD32(0, -0X64);
            goto L_800A59F4;
    }
    // 0x800A59B0: addiu       $t9, $zero, -0x64
    ctx->r25 = ADD32(0, -0X64);
    // 0x800A59B4: beq         $v0, $at, L_800A59F4
    if (ctx->r2 == ctx->r1) {
        // 0x800A59B8: addiu       $t8, $zero, 0x64
        ctx->r24 = ADD32(0, 0X64);
            goto L_800A59F4;
    }
    // 0x800A59B8: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x800A59BC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A59C0: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x800A59C4: sb          $t8, 0x3DC($t9)
    MEM_B(0X3DC, ctx->r25) = ctx->r24;
    // 0x800A59C8: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A59CC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A59D0: sb          $t5, 0x3BC($t4)
    MEM_B(0X3BC, ctx->r12) = ctx->r13;
    // 0x800A59D4: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A59D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A59DC: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800A59E0: swc1        $f4, 0x3CC($t3)
    MEM_W(0X3CC, ctx->r11) = ctx->f4.u32l;
    // 0x800A59E4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A59E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A59EC: b           L_800A5A28
    // 0x800A59F0: swc1        $f6, 0x3AC($t7)
    MEM_W(0X3AC, ctx->r15) = ctx->f6.u32l;
        goto L_800A5A28;
    // 0x800A59F0: swc1        $f6, 0x3AC($t7)
    MEM_W(0X3AC, ctx->r15) = ctx->f6.u32l;
L_800A59F4:
    // 0x800A59F4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A59F8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800A59FC: sb          $t6, 0x3DC($t8)
    MEM_B(0X3DC, ctx->r24) = ctx->r14;
    // 0x800A5A00: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A5A04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A5A08: sb          $t9, 0x3BC($t5)
    MEM_B(0X3BC, ctx->r13) = ctx->r25;
    // 0x800A5A0C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A5A10: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A5A14: swc1        $f8, 0x3CC($t4)
    MEM_W(0X3CC, ctx->r12) = ctx->f8.u32l;
    // 0x800A5A18: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A5A1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A5A20: nop

    // 0x800A5A24: swc1        $f10, 0x3AC($t3)
    MEM_W(0X3AC, ctx->r11) = ctx->f10.u32l;
L_800A5A28:
    // 0x800A5A28: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5A2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A5A30: lb          $v1, 0x3DA($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3DA);
    // 0x800A5A34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A5A38: beq         $v1, $zero, L_800A5F94
    if (ctx->r3 == 0) {
        // 0x800A5A3C: nop
    
            goto L_800A5F94;
    }
    // 0x800A5A3C: nop

    // 0x800A5A40: bne         $v1, $at, L_800A5CEC
    if (ctx->r3 != ctx->r1) {
        // 0x800A5A44: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A5CEC;
    }
    // 0x800A5A44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A5A48: lb          $v1, 0x3DB($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3DB);
    // 0x800A5A4C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5A50: bne         $a2, $v1, L_800A5BE0
    if (ctx->r6 != ctx->r3) {
        // 0x800A5A54: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800A5BE0;
    }
    // 0x800A5A54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A5A58: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800A5A5C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A5A60: lb          $v1, 0x3DC($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3DC);
    // 0x800A5A64: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A5A68: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800A5A6C: subu        $t6, $v1, $t7
    ctx->r14 = SUB32(ctx->r3, ctx->r15);
    // 0x800A5A70: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800A5A74: lwc1        $f0, 0x3CC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5A78: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A5A7C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A5A80: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A5A84: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800A5A88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A5A8C: bc1f        L_800A5AAC
    if (!c1cs) {
        // 0x800A5A90: nop
    
            goto L_800A5AAC;
    }
    // 0x800A5A90: nop

    // 0x800A5A94: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800A5A98: nop

    // 0x800A5A9C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5AA0: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800A5AA4: b           L_800A5ABC
    // 0x800A5AA8: swc1        $f8, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f8.u32l;
        goto L_800A5ABC;
    // 0x800A5AA8: swc1        $f8, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f8.u32l;
L_800A5AAC:
    // 0x800A5AAC: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800A5AB0: nop

    // 0x800A5AB4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5AB8: swc1        $f16, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f16.u32l;
L_800A5ABC:
    // 0x800A5ABC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5AC0: nop

    // 0x800A5AC4: lb          $v1, 0x3FC($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3FC);
    // 0x800A5AC8: lwc1        $f0, 0x3EC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3EC);
    // 0x800A5ACC: addu        $t8, $v1, $a0
    ctx->r24 = ADD32(ctx->r3, ctx->r4);
    // 0x800A5AD0: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800A5AD4: nop

    // 0x800A5AD8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A5ADC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800A5AE0: nop

    // 0x800A5AE4: bc1f        L_800A5B04
    if (!c1cs) {
        // 0x800A5AE8: nop
    
            goto L_800A5B04;
    }
    // 0x800A5AE8: nop

    // 0x800A5AEC: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x800A5AF0: nop

    // 0x800A5AF4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A5AF8: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800A5AFC: b           L_800A5B14
    // 0x800A5B00: swc1        $f10, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->f10.u32l;
        goto L_800A5B14;
    // 0x800A5B00: swc1        $f10, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->f10.u32l;
L_800A5B04:
    // 0x800A5B04: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800A5B08: nop

    // 0x800A5B0C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A5B10: swc1        $f18, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->f18.u32l;
L_800A5B14:
    // 0x800A5B14: lb          $t9, 0x193($t1)
    ctx->r25 = MEM_B(ctx->r9, 0X193);
    // 0x800A5B18: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A5B1C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800A5B20: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x800A5B24: lw          $t3, 0x128($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X128);
    // 0x800A5B28: nop

    // 0x800A5B2C: slti        $at, $t3, 0x3C
    ctx->r1 = SIGNED(ctx->r11) < 0X3C ? 1 : 0;
    // 0x800A5B30: bne         $at, $zero, L_800A5B50
    if (ctx->r1 != 0) {
        // 0x800A5B34: nop
    
            goto L_800A5B50;
    }
    // 0x800A5B34: nop

    // 0x800A5B38: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5B3C: jal         0x80001D04
    // 0x800A5B40: sb          $t7, 0x3DB($t6)
    MEM_B(0X3DB, ctx->r14) = ctx->r15;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x800A5B40: sb          $t7, 0x3DB($t6)
    MEM_B(0X3DB, ctx->r14) = ctx->r15;
    after_9:
    // 0x800A5B44: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5B48: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5B4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800A5B50:
    // 0x800A5B50: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5B54: nop

    // 0x800A5B58: lb          $t8, 0x3DC($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X3DC);
    // 0x800A5B5C: lwc1        $f4, 0x3CC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5B60: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800A5B64: nop

    // 0x800A5B68: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A5B6C: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x800A5B70: nop

    // 0x800A5B74: bc1f        L_800A5C54
    if (!c1cs) {
        // 0x800A5B78: nop
    
            goto L_800A5C54;
    }
    // 0x800A5B78: nop

    // 0x800A5B7C: lb          $t9, 0x3FC($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X3FC);
    // 0x800A5B80: lwc1        $f10, 0x3EC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3EC);
    // 0x800A5B84: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800A5B88: nop

    // 0x800A5B8C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A5B90: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x800A5B94: nop

    // 0x800A5B98: bc1f        L_800A5C54
    if (!c1cs) {
        // 0x800A5B9C: nop
    
            goto L_800A5C54;
    }
    // 0x800A5B9C: nop

    // 0x800A5BA0: lb          $t5, 0x3DD($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X3DD);
    // 0x800A5BA4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5BA8: bne         $t5, $zero, L_800A5C54
    if (ctx->r13 != 0) {
        // 0x800A5BAC: addiu       $a1, $a1, 0x7300
        ctx->r5 = ADD32(ctx->r5, 0X7300);
            goto L_800A5C54;
    }
    // 0x800A5BAC: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    // 0x800A5BB0: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x800A5BB4: nop

    // 0x800A5BB8: bne         $t4, $zero, L_800A5BD8
    if (ctx->r12 != 0) {
        // 0x800A5BBC: nop
    
            goto L_800A5BD8;
    }
    // 0x800A5BBC: nop

    // 0x800A5BC0: jal         0x80001D04
    // 0x800A5BC4: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800A5BC4: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_10:
    // 0x800A5BC8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5BCC: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5BD0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5BD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800A5BD8:
    // 0x800A5BD8: b           L_800A5C54
    // 0x800A5BDC: sb          $a2, 0x3DD($v0)
    MEM_B(0X3DD, ctx->r2) = ctx->r6;
        goto L_800A5C54;
    // 0x800A5BDC: sb          $a2, 0x3DD($v0)
    MEM_B(0X3DD, ctx->r2) = ctx->r6;
L_800A5BE0:
    // 0x800A5BE0: bne         $v1, $at, L_800A5C54
    if (ctx->r3 != ctx->r1) {
        // 0x800A5BE4: nop
    
            goto L_800A5C54;
    }
    // 0x800A5BE4: nop

    // 0x800A5BE8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5BEC: lwc1        $f4, 0x3CC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5BF0: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x800A5BF4: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x800A5BF8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A5BFC: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x800A5C00: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800A5C04: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A5C08: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A5C0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A5C10: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A5C14: swc1        $f8, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f8.u32l;
    // 0x800A5C18: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5C1C: nop

    // 0x800A5C20: lwc1        $f16, 0x3EC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3EC);
    // 0x800A5C24: nop

    // 0x800A5C28: add.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A5C2C: swc1        $f10, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->f10.u32l;
    // 0x800A5C30: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5C34: nop

    // 0x800A5C38: lwc1        $f18, 0x3CC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5C3C: nop

    // 0x800A5C40: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800A5C44: nop

    // 0x800A5C48: bc1f        L_800A5C54
    if (!c1cs) {
        // 0x800A5C4C: nop
    
            goto L_800A5C54;
    }
    // 0x800A5C4C: nop

    // 0x800A5C50: sb          $zero, 0x3DA($v0)
    MEM_B(0X3DA, ctx->r2) = 0;
L_800A5C54:
    // 0x800A5C54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5C58: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5C5C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A5C60: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800A5C64: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800A5C68: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A5C6C: addiu       $t9, $zero, -0x60
    ctx->r25 = ADD32(0, -0X60);
    // 0x800A5C70: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A5C74: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A5C78: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5C7C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5C80: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5C84: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5C88: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A5C8C: jal         0x800AAB5C
    // 0x800A5C90: addiu       $a3, $a3, 0x3E0
    ctx->r7 = ADD32(ctx->r7, 0X3E0);
    hud_element_render(rdram, ctx);
        goto after_11;
    // 0x800A5C90: addiu       $a3, $a3, 0x3E0
    ctx->r7 = ADD32(ctx->r7, 0X3E0);
    after_11:
    // 0x800A5C94: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5C98: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5C9C: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5CA0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5CA4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5CA8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5CAC: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5CB0: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A5CB4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5CB8: jal         0x800AAB5C
    // 0x800A5CBC: addiu       $a3, $a3, 0x3C0
    ctx->r7 = ADD32(ctx->r7, 0X3C0);
    hud_element_render(rdram, ctx);
        goto after_12;
    // 0x800A5CBC: addiu       $a3, $a3, 0x3C0
    ctx->r7 = ADD32(ctx->r7, 0X3C0);
    after_12:
    // 0x800A5CC0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5CC4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5CC8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A5CCC: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800A5CD0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800A5CD4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800A5CD8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800A5CDC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800A5CE0: b           L_800A5F94
    // 0x800A5CE4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_800A5F94;
    // 0x800A5CE4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800A5CE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800A5CEC:
    // 0x800A5CEC: bne         $v1, $at, L_800A5F94
    if (ctx->r3 != ctx->r1) {
        // 0x800A5CF0: nop
    
            goto L_800A5F94;
    }
    // 0x800A5CF0: nop

    // 0x800A5CF4: lb          $v1, 0x3DB($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3DB);
    // 0x800A5CF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A5CFC: bne         $v1, $at, L_800A5E90
    if (ctx->r3 != ctx->r1) {
        // 0x800A5D00: nop
    
            goto L_800A5E90;
    }
    // 0x800A5D00: nop

    // 0x800A5D04: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5D08: lb          $v1, 0x3DC($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3DC);
    // 0x800A5D0C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800A5D10: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A5D14: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A5D18: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800A5D1C: addu        $t6, $v1, $t7
    ctx->r14 = ADD32(ctx->r3, ctx->r15);
    // 0x800A5D20: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800A5D24: lwc1        $f0, 0x3CC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5D28: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5D2C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A5D30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A5D34: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800A5D38: nop

    // 0x800A5D3C: bc1f        L_800A5D5C
    if (!c1cs) {
        // 0x800A5D40: nop
    
            goto L_800A5D5C;
    }
    // 0x800A5D40: nop

    // 0x800A5D44: mtc1        $a0, $f16
    ctx->f16.u32l = ctx->r4;
    // 0x800A5D48: nop

    // 0x800A5D4C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A5D50: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800A5D54: b           L_800A5D6C
    // 0x800A5D58: swc1        $f18, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f18.u32l;
        goto L_800A5D6C;
    // 0x800A5D58: swc1        $f18, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f18.u32l;
L_800A5D5C:
    // 0x800A5D5C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800A5D60: nop

    // 0x800A5D64: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A5D68: swc1        $f4, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f4.u32l;
L_800A5D6C:
    // 0x800A5D6C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5D70: nop

    // 0x800A5D74: lb          $v1, 0x3BC($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3BC);
    // 0x800A5D78: lwc1        $f0, 0x3AC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3AC);
    // 0x800A5D7C: subu        $t8, $v1, $a0
    ctx->r24 = SUB32(ctx->r3, ctx->r4);
    // 0x800A5D80: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800A5D84: nop

    // 0x800A5D88: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A5D8C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800A5D90: nop

    // 0x800A5D94: bc1f        L_800A5DB4
    if (!c1cs) {
        // 0x800A5D98: nop
    
            goto L_800A5DB4;
    }
    // 0x800A5D98: nop

    // 0x800A5D9C: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x800A5DA0: nop

    // 0x800A5DA4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5DA8: add.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800A5DAC: b           L_800A5DC4
    // 0x800A5DB0: swc1        $f6, 0x3AC($v0)
    MEM_W(0X3AC, ctx->r2) = ctx->f6.u32l;
        goto L_800A5DC4;
    // 0x800A5DB0: swc1        $f6, 0x3AC($v0)
    MEM_W(0X3AC, ctx->r2) = ctx->f6.u32l;
L_800A5DB4:
    // 0x800A5DB4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A5DB8: nop

    // 0x800A5DBC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5DC0: swc1        $f8, 0x3AC($v0)
    MEM_W(0X3AC, ctx->r2) = ctx->f8.u32l;
L_800A5DC4:
    // 0x800A5DC4: lb          $t9, 0x193($t1)
    ctx->r25 = MEM_B(ctx->r9, 0X193);
    // 0x800A5DC8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A5DCC: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800A5DD0: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x800A5DD4: lw          $t3, 0x128($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X128);
    // 0x800A5DD8: nop

    // 0x800A5DDC: slti        $at, $t3, 0x3C
    ctx->r1 = SIGNED(ctx->r11) < 0X3C ? 1 : 0;
    // 0x800A5DE0: bne         $at, $zero, L_800A5E00
    if (ctx->r1 != 0) {
        // 0x800A5DE4: nop
    
            goto L_800A5E00;
    }
    // 0x800A5DE4: nop

    // 0x800A5DE8: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5DEC: jal         0x80001D04
    // 0x800A5DF0: sb          $a2, 0x3DB($t7)
    MEM_B(0X3DB, ctx->r15) = ctx->r6;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x800A5DF0: sb          $a2, 0x3DB($t7)
    MEM_B(0X3DB, ctx->r15) = ctx->r6;
    after_13:
    // 0x800A5DF4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5DF8: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5DFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800A5E00:
    // 0x800A5E00: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5E04: nop

    // 0x800A5E08: lb          $t6, 0x3DC($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X3DC);
    // 0x800A5E0C: lwc1        $f16, 0x3CC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5E10: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800A5E14: nop

    // 0x800A5E18: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5E1C: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800A5E20: nop

    // 0x800A5E24: bc1f        L_800A5F04
    if (!c1cs) {
        // 0x800A5E28: nop
    
            goto L_800A5F04;
    }
    // 0x800A5E28: nop

    // 0x800A5E2C: lb          $t8, 0x3BC($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X3BC);
    // 0x800A5E30: lwc1        $f6, 0x3AC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3AC);
    // 0x800A5E34: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800A5E38: nop

    // 0x800A5E3C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5E40: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800A5E44: nop

    // 0x800A5E48: bc1f        L_800A5F04
    if (!c1cs) {
        // 0x800A5E4C: nop
    
            goto L_800A5F04;
    }
    // 0x800A5E4C: nop

    // 0x800A5E50: lb          $t9, 0x3DD($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X3DD);
    // 0x800A5E54: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5E58: bne         $t9, $zero, L_800A5F04
    if (ctx->r25 != 0) {
        // 0x800A5E5C: addiu       $a1, $a1, 0x7300
        ctx->r5 = ADD32(ctx->r5, 0X7300);
            goto L_800A5F04;
    }
    // 0x800A5E5C: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    // 0x800A5E60: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800A5E64: nop

    // 0x800A5E68: bne         $t5, $zero, L_800A5E88
    if (ctx->r13 != 0) {
        // 0x800A5E6C: nop
    
            goto L_800A5E88;
    }
    // 0x800A5E6C: nop

    // 0x800A5E70: jal         0x80001D04
    // 0x800A5E74: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    sound_play(rdram, ctx);
        goto after_14;
    // 0x800A5E74: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    after_14:
    // 0x800A5E78: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5E7C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5E80: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5E84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800A5E88:
    // 0x800A5E88: b           L_800A5F04
    // 0x800A5E8C: sb          $a2, 0x3DD($v0)
    MEM_B(0X3DD, ctx->r2) = ctx->r6;
        goto L_800A5F04;
    // 0x800A5E8C: sb          $a2, 0x3DD($v0)
    MEM_B(0X3DD, ctx->r2) = ctx->r6;
L_800A5E90:
    // 0x800A5E90: bne         $a2, $v1, L_800A5F04
    if (ctx->r6 != ctx->r3) {
        // 0x800A5E94: nop
    
            goto L_800A5F04;
    }
    // 0x800A5E94: nop

    // 0x800A5E98: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5E9C: lwc1        $f16, 0x3CC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5EA0: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x800A5EA4: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x800A5EA8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800A5EAC: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x800A5EB0: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800A5EB4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800A5EB8: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5EBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A5EC0: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A5EC4: swc1        $f18, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f18.u32l;
    // 0x800A5EC8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5ECC: nop

    // 0x800A5ED0: lwc1        $f4, 0x3AC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3AC);
    // 0x800A5ED4: nop

    // 0x800A5ED8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A5EDC: swc1        $f6, 0x3AC($v0)
    MEM_W(0X3AC, ctx->r2) = ctx->f6.u32l;
    // 0x800A5EE0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5EE4: nop

    // 0x800A5EE8: lwc1        $f10, 0x3CC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5EEC: nop

    // 0x800A5EF0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800A5EF4: nop

    // 0x800A5EF8: bc1f        L_800A5F04
    if (!c1cs) {
        // 0x800A5EFC: nop
    
            goto L_800A5F04;
    }
    // 0x800A5EFC: nop

    // 0x800A5F00: sb          $zero, 0x3DA($v0)
    MEM_B(0X3DA, ctx->r2) = 0;
L_800A5F04:
    // 0x800A5F04: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5F08: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5F0C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A5F10: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A5F14: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A5F18: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A5F1C: addiu       $t8, $zero, -0x60
    ctx->r24 = ADD32(0, -0X60);
    // 0x800A5F20: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800A5F24: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A5F28: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5F2C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5F30: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5F34: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5F38: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A5F3C: jal         0x800AAB5C
    // 0x800A5F40: addiu       $a3, $a3, 0x3A0
    ctx->r7 = ADD32(ctx->r7, 0X3A0);
    hud_element_render(rdram, ctx);
        goto after_15;
    // 0x800A5F40: addiu       $a3, $a3, 0x3A0
    ctx->r7 = ADD32(ctx->r7, 0X3A0);
    after_15:
    // 0x800A5F44: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5F48: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A5F4C: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5F50: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5F54: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5F58: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5F5C: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5F60: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A5F64: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5F68: jal         0x800AAB5C
    // 0x800A5F6C: addiu       $a3, $a3, 0x3C0
    ctx->r7 = ADD32(ctx->r7, 0X3C0);
    hud_element_render(rdram, ctx);
        goto after_16;
    // 0x800A5F6C: addiu       $a3, $a3, 0x3C0
    ctx->r7 = ADD32(ctx->r7, 0X3C0);
    after_16:
    // 0x800A5F70: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A5F74: lw          $v0, 0x72BC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72BC);
    // 0x800A5F78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A5F7C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800A5F80: sw          $t9, 0x72BC($at)
    MEM_W(0X72BC, ctx->r1) = ctx->r25;
    // 0x800A5F84: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800A5F88: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800A5F8C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A5F90: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_800A5F94:
    // 0x800A5F94: jal         0x8007C36C
    // 0x800A5F98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_17;
    // 0x800A5F98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x800A5F9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5FA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5FA4: jr          $ra
    // 0x800A5FA8: nop

    return;
    // 0x800A5FA8: nop

;}
RECOMP_FUNC void obj_init_audio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FDA8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003FDAC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8003FDB0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8003FDB4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8003FDB8: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8003FDBC: lhu         $t7, 0x8($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X8);
    // 0x8003FDC0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8003FDC4: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x8003FDC8: lhu         $t8, 0xA($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XA);
    // 0x8003FDCC: andi        $a0, $t7, 0xFFFF
    ctx->r4 = ctx->r15 & 0XFFFF;
    // 0x8003FDD0: sh          $t8, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r24;
    // 0x8003FDD4: lbu         $t9, 0xF($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XF);
    // 0x8003FDD8: nop

    // 0x8003FDDC: sb          $t9, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r25;
    // 0x8003FDE0: lbu         $t0, 0xE($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XE);
    // 0x8003FDE4: nop

    // 0x8003FDE8: sb          $t0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r8;
    // 0x8003FDEC: lbu         $t1, 0xC($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XC);
    // 0x8003FDF0: nop

    // 0x8003FDF4: sb          $t1, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r9;
    // 0x8003FDF8: lbu         $t2, 0xD($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XD);
    // 0x8003FDFC: nop

    // 0x8003FE00: sb          $t2, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r10;
    // 0x8003FE04: lbu         $t3, 0x10($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X10);
    // 0x8003FE08: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8003FE0C: sb          $t3, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r11;
    // 0x8003FE10: jal         0x800021B0
    // 0x8003FE14: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    sound_is_looped(rdram, ctx);
        goto after_0;
    // 0x8003FE14: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_0:
    // 0x8003FE18: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8003FE1C: beq         $v0, $zero, L_8003FEA4
    if (ctx->r2 == 0) {
        // 0x8003FE20: addiu       $t8, $zero, 0xA
        ctx->r24 = ADD32(0, 0XA);
            goto L_8003FEA4;
    }
    // 0x8003FE20: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8003FE24: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x8003FE28: lh          $t5, 0x4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4);
    // 0x8003FE2C: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x8003FE30: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x8003FE34: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x8003FE38: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003FE3C: lbu         $t8, 0x5($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X5);
    // 0x8003FE40: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8003FE44: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003FE48: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x8003FE4C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8003FE50: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8003FE54: lhu         $t0, 0x2($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X2);
    // 0x8003FE58: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8003FE5C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8003FE60: lbu         $t1, 0xC($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XC);
    // 0x8003FE64: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003FE68: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8003FE6C: lbu         $t2, 0x6($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X6);
    // 0x8003FE70: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003FE74: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8003FE78: lbu         $t3, 0xD($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XD);
    // 0x8003FE7C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003FE80: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8003FE84: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003FE88: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8003FE8C: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8003FE90: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8003FE94: jal         0x8000974C
    // 0x8003FE98: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    audspat_point_create(rdram, ctx);
        goto after_1;
    // 0x8003FE98: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_1:
    // 0x8003FE9C: b           L_8003FF1C
    // 0x8003FEA0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
        goto L_8003FF1C;
    // 0x8003FEA0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_8003FEA4:
    // 0x8003FEA4: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x8003FEA8: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x8003FEAC: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x8003FEB0: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x8003FEB4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003FEB8: lbu         $t9, 0x5($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X5);
    // 0x8003FEBC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8003FEC0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8003FEC4: lbu         $t0, 0x4($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X4);
    // 0x8003FEC8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8003FECC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8003FED0: lhu         $t1, 0x2($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X2);
    // 0x8003FED4: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8003FED8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8003FEDC: lbu         $t2, 0xC($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XC);
    // 0x8003FEE0: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8003FEE4: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8003FEE8: lbu         $t3, 0x6($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X6);
    // 0x8003FEEC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003FEF0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8003FEF4: lbu         $t4, 0xD($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XD);
    // 0x8003FEF8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003FEFC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8003FF00: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003FF04: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8003FF08: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8003FF0C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8003FF10: jal         0x8000974C
    // 0x8003FF14: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    audspat_point_create(rdram, ctx);
        goto after_2;
    // 0x8003FF14: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    after_2:
    // 0x8003FF18: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_8003FF1C:
    // 0x8003FF1C: jal         0x8000FFB8
    // 0x8003FF20: nop

    free_object(rdram, ctx);
        goto after_3;
    // 0x8003FF20: nop

    after_3:
    // 0x8003FF24: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8003FF28: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8003FF2C: jr          $ra
    // 0x8003FF30: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8003FF30: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void allocate_ghost_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059928: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8005992C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x80059930: jal         0x80070EDC
    // 0x80059934: addiu       $a0, $zero, 0x21C0
    ctx->r4 = ADD32(0, 0X21C0);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80059934: addiu       $a0, $zero, 0x21C0
    ctx->r4 = ADD32(0, 0X21C0);
    after_0:
    // 0x80059938: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005993C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80059940: addiu       $a0, $a0, -0x24E0
    ctx->r4 = ADD32(ctx->r4, -0X24E0);
    // 0x80059944: addiu       $v1, $v1, -0x24F0
    ctx->r3 = ADD32(ctx->r3, -0X24F0);
    // 0x80059948: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005994C: addiu       $a1, $a1, -0x24D8
    ctx->r5 = ADD32(ctx->r5, -0X24D8);
    // 0x80059950: addiu       $t7, $v0, 0x10E0
    ctx->r15 = ADD32(ctx->r2, 0X10E0);
    // 0x80059954: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80059958: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005995C: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x80059960: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80059964: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x80059968: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x8005996C: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x80059970: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x80059974: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005997C: sb          $zero, -0x24E3($at)
    MEM_B(-0X24E3, ctx->r1) = 0;
    // 0x80059980: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059984: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80059988: sh          $t8, -0x24D4($at)
    MEM_H(-0X24D4, ctx->r1) = ctx->r24;
    // 0x8005998C: jr          $ra
    // 0x80059990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80059990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void render_mesh(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800143A8: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800143AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800143B0: lw          $t6, -0x4BF4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BF4);
    // 0x800143B4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800143B8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800143BC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800143C0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800143C4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800143C8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800143CC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800143D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800143D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800143D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800143DC: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x800143E0: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x800143E4: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x800143E8: lh          $t1, 0x28($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X28);
    // 0x800143EC: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x800143F0: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800143F4: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x800143F8: beq         $at, $zero, L_800147C4
    if (ctx->r1 == 0) {
        // 0x800143FC: or          $ra, $zero, $zero
        ctx->r31 = 0 | 0;
            goto L_800147C4;
    }
    // 0x800143FC: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80014400: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x80014404: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x80014408: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8001440C: lui         $fp, 0x400
    ctx->r30 = S32(0X400 << 16);
    // 0x80014410: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
    // 0x80014414: or          $t5, $a3, $zero
    ctx->r13 = ctx->r7 | 0;
L_80014418:
    // 0x80014418: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x8001441C: andi        $t9, $t5, 0x4
    ctx->r25 = ctx->r13 & 0X4;
    // 0x80014420: addu        $v0, $t7, $t3
    ctx->r2 = ADD32(ctx->r15, ctx->r11);
    // 0x80014424: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80014428: nop

    // 0x8001442C: andi        $t8, $t0, 0x4
    ctx->r24 = ctx->r8 & 0X4;
    // 0x80014430: beq         $t8, $zero, L_80014440
    if (ctx->r24 == 0) {
        // 0x80014434: andi        $v1, $t0, 0x100
        ctx->r3 = ctx->r8 & 0X100;
            goto L_80014440;
    }
    // 0x80014434: andi        $v1, $t0, 0x100
    ctx->r3 = ctx->r8 & 0X100;
    // 0x80014438: beq         $t9, $zero, L_800147AC
    if (ctx->r25 == 0) {
        // 0x8001443C: nop
    
            goto L_800147AC;
    }
    // 0x8001443C: nop

L_80014440:
    // 0x80014440: bne         $v1, $zero, L_800147A0
    if (ctx->r3 != 0) {
        // 0x80014444: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_800147A0;
    }
    // 0x80014444: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80014448: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    // 0x8001444C: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x80014450: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x80014454: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x80014458: andi        $t1, $t5, 0x4
    ctx->r9 = ctx->r13 & 0X4;
    // 0x8001445C: beq         $t7, $zero, L_80014470
    if (ctx->r15 == 0) {
        // 0x80014460: subu        $s1, $t6, $a0
        ctx->r17 = SUB32(ctx->r14, ctx->r4);
            goto L_80014470;
    }
    // 0x80014460: subu        $s1, $t6, $a0
    ctx->r17 = SUB32(ctx->r14, ctx->r4);
    // 0x80014464: lb          $s0, 0x1($v0)
    ctx->r16 = MEM_B(ctx->r2, 0X1);
    // 0x80014468: b           L_80014478
    // 0x8001446C: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
        goto L_80014478;
    // 0x8001446C: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
L_80014470:
    // 0x80014470: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80014474: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
L_80014478:
    // 0x80014478: lw          $t9, 0x8($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X8);
    // 0x8001447C: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x80014480: subu        $s5, $t8, $a1
    ctx->r21 = SUB32(ctx->r24, ctx->r5);
    // 0x80014484: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80014488: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x8001448C: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x80014490: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80014494: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80014498: lw          $t9, 0x44($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X44);
    // 0x8001449C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800144A0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800144A4: bne         $v1, $at, L_800144BC
    if (ctx->r3 != ctx->r1) {
        // 0x800144A8: addu        $s3, $t9, $t6
        ctx->r19 = ADD32(ctx->r25, ctx->r14);
            goto L_800144BC;
    }
    // 0x800144A8: addu        $s3, $t9, $t6
    ctx->r19 = ADD32(ctx->r25, ctx->r14);
    // 0x800144AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800144B0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800144B4: b           L_800144DC
    // 0x800144B8: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
        goto L_800144DC;
    // 0x800144B8: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_800144BC:
    // 0x800144BC: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800144C0: lbu         $a3, 0x7($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X7);
    // 0x800144C4: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x800144C8: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x800144CC: sll         $t7, $a3, 14
    ctx->r15 = S32(ctx->r7 << 14);
    // 0x800144D0: lw          $s2, 0x0($t6)
    ctx->r18 = MEM_W(ctx->r14, 0X0);
    // 0x800144D4: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800144D8: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800144DC:
    // 0x800144DC: beq         $t1, $zero, L_800144FC
    if (ctx->r9 == 0) {
        // 0x800144E0: ori         $a2, $t0, 0x8
        ctx->r6 = ctx->r8 | 0X8;
            goto L_800144FC;
    }
    // 0x800144E0: ori         $a2, $t0, 0x8
    ctx->r6 = ctx->r8 | 0X8;
    // 0x800144E4: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800144E8: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800144EC: and         $t8, $t0, $t7
    ctx->r24 = ctx->r8 & ctx->r15;
    // 0x800144F0: bne         $t8, $zero, L_800144FC
    if (ctx->r24 != 0) {
        // 0x800144F4: ori         $t9, $a2, 0x4
        ctx->r25 = ctx->r6 | 0X4;
            goto L_800144FC;
    }
    // 0x800144F4: ori         $t9, $a2, 0x4
    ctx->r25 = ctx->r6 | 0X4;
    // 0x800144F8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
L_800144FC:
    // 0x800144FC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80014500: lw          $t6, -0x3370($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3370);
    // 0x80014504: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80014508: bne         $t6, $zero, L_80014544
    if (ctx->r14 != 0) {
        // 0x8001450C: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80014544;
    }
    // 0x8001450C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80014510: sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
    // 0x80014514: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80014518: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8001451C: sw          $t2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r10;
    // 0x80014520: jal         0x8007B938
    // 0x80014524: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    material_set(rdram, ctx);
        goto after_0;
    // 0x80014524: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    after_0:
    // 0x80014528: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x8001452C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80014530: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x80014534: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x80014538: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
    // 0x8001453C: b           L_800145B0
    // 0x80014540: ori         $t4, $t4, 0xA
    ctx->r12 = ctx->r12 | 0XA;
        goto L_800145B0;
    // 0x80014540: ori         $t4, $t4, 0xA
    ctx->r12 = ctx->r12 | 0XA;
L_80014544:
    // 0x80014544: sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
    // 0x80014548: sw          $t2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r10;
    // 0x8001454C: jal         0x8007B8BC
    // 0x80014550: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    set_animated_texture_header(rdram, ctx);
        goto after_1;
    // 0x80014550: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    after_1:
    // 0x80014554: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80014558: addiu       $a2, $a2, -0x4BF4
    ctx->r6 = ADD32(ctx->r6, -0X4BF4);
    // 0x8001455C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80014560: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80014564: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80014568: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8001456C: lh          $a1, 0xA($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XA);
    // 0x80014570: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80014574: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80014578: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8001457C: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80014580: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80014584: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80014588: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8001458C: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x80014590: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
    // 0x80014594: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80014598: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001459C: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x800145A0: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x800145A4: addu        $t6, $t7, $s4
    ctx->r14 = ADD32(ctx->r15, ctx->r20);
    // 0x800145A8: ori         $t4, $t4, 0xA
    ctx->r12 = ctx->r12 | 0XA;
    // 0x800145AC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_800145B0:
    // 0x800145B0: bne         $s0, $s1, L_80014608
    if (ctx->r16 != ctx->r17) {
        // 0x800145B4: lui         $at, 0x500
        ctx->r1 = S32(0X500 << 16);
            goto L_80014608;
    }
    // 0x800145B4: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800145B8: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x800145BC: addu        $v0, $s3, $s4
    ctx->r2 = ADD32(ctx->r19, ctx->r20);
    // 0x800145C0: addiu       $t7, $s1, -0x1
    ctx->r15 = ADD32(ctx->r17, -0X1);
    // 0x800145C4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800145C8: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x800145CC: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800145D0: andi        $t8, $v0, 0x6
    ctx->r24 = ctx->r2 & 0X6;
    // 0x800145D4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800145D8: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x800145DC: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800145E0: sll         $t9, $s1, 3
    ctx->r25 = S32(ctx->r17 << 3);
    // 0x800145E4: addu        $t7, $t9, $s1
    ctx->r15 = ADD32(ctx->r25, ctx->r17);
    // 0x800145E8: or          $t8, $t6, $fp
    ctx->r24 = ctx->r14 | ctx->r30;
    // 0x800145EC: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800145F0: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x800145F4: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x800145F8: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800145FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80014600: b           L_80014754
    // 0x80014604: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_80014754;
    // 0x80014604: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80014608:
    // 0x80014608: blez        $s0, L_800146DC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8001460C: addiu       $t8, $zero, 0x80
        ctx->r24 = ADD32(0, 0X80);
            goto L_800146DC;
    }
    // 0x8001460C: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80014610: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80014614: addu        $v0, $s3, $s4
    ctx->r2 = ADD32(ctx->r19, ctx->r20);
    // 0x80014618: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8001461C: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80014620: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x80014624: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x80014628: andi        $t9, $v0, 0x6
    ctx->r25 = ctx->r2 & 0X6;
    // 0x8001462C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80014630: andi        $t7, $t8, 0xFF
    ctx->r15 = ctx->r24 & 0XFF;
    // 0x80014634: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80014638: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
    // 0x8001463C: addu        $t7, $t8, $s0
    ctx->r15 = ADD32(ctx->r24, ctx->r16);
    // 0x80014640: or          $t9, $t6, $fp
    ctx->r25 = ctx->r14 | ctx->r30;
    // 0x80014644: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x80014648: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8001464C: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x80014650: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80014654: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80014658: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8001465C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80014660: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80014664: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80014668: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x8001466C: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80014670: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80014674: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80014678: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x8001467C: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x80014680: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80014684: addu        $t7, $s3, $t9
    ctx->r15 = ADD32(ctx->r19, ctx->r25);
    // 0x80014688: subu        $v1, $s1, $s0
    ctx->r3 = SUB32(ctx->r17, ctx->r16);
    // 0x8001468C: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x80014690: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x80014694: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80014698: addu        $a3, $t7, $s4
    ctx->r7 = ADD32(ctx->r15, ctx->r20);
    // 0x8001469C: andi        $t9, $a3, 0x6
    ctx->r25 = ctx->r7 & 0X6;
    // 0x800146A0: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800146A4: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x800146A8: ori         $t6, $t7, 0x1
    ctx->r14 = ctx->r15 | 0X1;
    // 0x800146AC: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x800146B0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800146B4: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x800146B8: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800146BC: or          $t7, $t9, $fp
    ctx->r15 = ctx->r25 | ctx->r30;
    // 0x800146C0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800146C4: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800146C8: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x800146CC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800146D0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800146D4: b           L_8001473C
    // 0x800146D8: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
        goto L_8001473C;
    // 0x800146D8: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
L_800146DC:
    // 0x800146DC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800146E0: addu        $v0, $s3, $s4
    ctx->r2 = ADD32(ctx->r19, ctx->r20);
    // 0x800146E4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800146E8: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x800146EC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x800146F0: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x800146F4: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800146F8: addiu       $t7, $s1, -0x1
    ctx->r15 = ADD32(ctx->r17, -0X1);
    // 0x800146FC: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80014700: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x80014704: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80014708: andi        $t9, $v0, 0x6
    ctx->r25 = ctx->r2 & 0X6;
    // 0x8001470C: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80014710: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80014714: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80014718: sll         $t6, $s1, 3
    ctx->r14 = S32(ctx->r17 << 3);
    // 0x8001471C: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80014720: or          $t9, $t8, $fp
    ctx->r25 = ctx->r24 | ctx->r30;
    // 0x80014724: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80014728: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8001472C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80014730: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80014734: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80014738: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8001473C:
    // 0x8001473C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80014740: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80014744: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80014748: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x8001474C: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x80014750: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
L_80014754:
    // 0x80014754: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x80014758: addiu       $t9, $s5, -0x1
    ctx->r25 = ADD32(ctx->r21, -0X1);
    // 0x8001475C: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x80014760: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80014764: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x80014768: or          $t8, $t7, $s6
    ctx->r24 = ctx->r15 | ctx->r22;
    // 0x8001476C: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80014770: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x80014774: sll         $t8, $s5, 4
    ctx->r24 = S32(ctx->r21 << 4);
    // 0x80014778: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x8001477C: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80014780: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80014784: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80014788: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x8001478C: nop

    // 0x80014790: addu        $t7, $t8, $s4
    ctx->r15 = ADD32(ctx->r24, ctx->r20);
    // 0x80014794: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80014798: lh          $t1, 0x28($s7)
    ctx->r9 = MEM_H(ctx->r23, 0X28);
    // 0x8001479C: nop

L_800147A0:
    // 0x800147A0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800147A4: b           L_800147B0
    // 0x800147A8: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
        goto L_800147B0;
    // 0x800147A8: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
L_800147AC:
    // 0x800147AC: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
L_800147B0:
    // 0x800147B0: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800147B4: beq         $at, $zero, L_800147C8
    if (ctx->r1 == 0) {
        // 0x800147B8: slt         $at, $t2, $t1
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_800147C8;
    }
    // 0x800147B8: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800147BC: beq         $ra, $zero, L_80014418
    if (ctx->r31 == 0) {
        // 0x800147C0: nop
    
            goto L_80014418;
    }
    // 0x800147C0: nop

L_800147C4:
    // 0x800147C4: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
L_800147C8:
    // 0x800147C8: bne         $at, $zero, L_800147D8
    if (ctx->r1 != 0) {
        // 0x800147CC: lw          $t6, 0x74($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X74);
            goto L_800147D8;
    }
    // 0x800147CC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800147D0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800147D4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_800147D8:
    // 0x800147D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800147DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800147E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800147E4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800147E8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800147EC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800147F0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800147F4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800147F8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800147FC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80014800: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80014804: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x80014808: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8001480C: jr          $ra
    // 0x80014810: sw          $t6, -0x4BF4($at)
    MEM_W(-0X4BF4, ctx->r1) = ctx->r14;
    return;
    // 0x80014810: sw          $t6, -0x4BF4($at)
    MEM_W(-0X4BF4, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void write_to_object_render_stack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800666C8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800666CC: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800666D0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800666D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800666D8: addiu       $t7, $t7, 0x1040
    ctx->r15 = ADD32(ctx->r15, 0X1040);
    // 0x800666DC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800666E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800666E4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800666E8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800666EC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800666F0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800666F4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800666F8: lh          $t8, 0x32($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X32);
    // 0x800666FC: lh          $t9, 0x36($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X36);
    // 0x80066700: lh          $t0, 0x3A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3A);
    // 0x80066704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066708: sh          $zero, 0x38($v1)
    MEM_H(0X38, ctx->r3) = 0;
    // 0x8006670C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80066710: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80066714: swc1        $f12, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f12.u32l;
    // 0x80066718: swc1        $f14, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f14.u32l;
    // 0x8006671C: swc1        $f4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f4.u32l;
    // 0x80066720: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80066724: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x80066728: jal         0x80029F58
    // 0x8006672C: sh          $t0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r8;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_0;
    // 0x8006672C: sh          $t0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r8;
    after_0:
    // 0x80066730: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80066734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066738: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006673C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066740: sh          $v0, 0x34($v1)
    MEM_H(0X34, ctx->r3) = ctx->r2;
    // 0x80066744: sb          $t1, 0x1294($at)
    MEM_B(0X1294, ctx->r1) = ctx->r9;
    // 0x80066748: jr          $ra
    // 0x8006674C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006674C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void light_direction_calc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033C48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033C4C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80033C50: lwc1        $f12, -0x25C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25C0);
    // 0x80033C54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033C58: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80033C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033C60: bc1f        L_80033CE4
    if (!c1cs) {
        // 0x80033C64: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80033CE4;
    }
    // 0x80033C64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033C68: jal         0x800CA030
    // 0x80033C6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80033C6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80033C70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033C74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80033C78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033C7C: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80033C80: lwc1        $f6, -0x25BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X25BC);
    // 0x80033C84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80033C88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033C8C: lwc1        $f10, 0x7C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x80033C90: lwc1        $f18, -0x25B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X25B8);
    // 0x80033C94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033C98: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80033C9C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80033CA0: lwc1        $f6, 0x80($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X80);
    // 0x80033CA4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80033CA8: nop

    // 0x80033CAC: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80033CB0: lwc1        $f18, -0x25B4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X25B4);
    // 0x80033CB4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80033CB8: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80033CBC: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80033CC0: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80033CC4: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80033CC8: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80033CCC: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80033CD0: nop

    // 0x80033CD4: bc1f        L_80033CEC
    if (!c1cs) {
        // 0x80033CD8: nop
    
            goto L_80033CEC;
    }
    // 0x80033CD8: nop

    // 0x80033CDC: b           L_80033CEC
    // 0x80033CE0: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_80033CEC;
    // 0x80033CE0: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_80033CE4:
    // 0x80033CE4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80033CE8: nop

L_80033CEC:
    // 0x80033CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033CF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80033CF4: jr          $ra
    // 0x80033CF8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x80033CF8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
;}
RECOMP_FUNC void transition_update_blank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2CC0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C2CC4: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x800C2CC8: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800C2CCC: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x800C2CD0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C2CD4: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800C2CD8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800C2CDC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800C2CE0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C2CE4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C2CE8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800C2CEC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C2CF0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C2CF4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C2CF8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C2CFC: addiu       $a1, $a1, 0x3740
    ctx->r5 = ADD32(ctx->r5, 0X3740);
    // 0x800C2D00: addiu       $a2, $a2, -0x5308
    ctx->r6 = ADD32(ctx->r6, -0X5308);
    // 0x800C2D04: addiu       $a3, $a3, -0x52FC
    ctx->r7 = ADD32(ctx->r7, -0X52FC);
    // 0x800C2D08: addiu       $t0, $t0, -0x5304
    ctx->r8 = ADD32(ctx->r8, -0X5304);
    // 0x800C2D0C: addiu       $t1, $t1, -0x52F8
    ctx->r9 = ADD32(ctx->r9, -0X52F8);
    // 0x800C2D10: addiu       $t2, $t2, -0x5300
    ctx->r10 = ADD32(ctx->r10, -0X5300);
    // 0x800C2D14: addiu       $t3, $t3, -0x52F4
    ctx->r11 = ADD32(ctx->r11, -0X52F4);
    // 0x800C2D18: addiu       $t4, $t4, -0x530C
    ctx->r12 = ADD32(ctx->r12, -0X530C);
    // 0x800C2D1C: addiu       $t5, $t5, -0x530B
    ctx->r13 = ADD32(ctx->r13, -0X530B);
    // 0x800C2D20: addiu       $s2, $s2, 0x3744
    ctx->r18 = ADD32(ctx->r18, 0X3744);
    // 0x800C2D24: addiu       $s0, $s0, -0x530A
    ctx->r16 = ADD32(ctx->r16, -0X530A);
    // 0x800C2D28: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x800C2D2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C2D30:
    // 0x800C2D30: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x800C2D34: nop

    // 0x800C2D38: blez        $v1, L_800C2DCC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C2D3C: nop
    
            goto L_800C2DCC;
    }
    // 0x800C2D3C: nop

    // 0x800C2D40: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800C2D44: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C2D48: multu       $t7, $a0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C2D4C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800C2D50: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C2D54: mflo        $t8
    ctx->r24 = lo;
    // 0x800C2D58: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800C2D5C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800C2D60: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800C2D64: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C2D68: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800C2D6C: mflo        $t8
    ctx->r24 = lo;
    // 0x800C2D70: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C2D74: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800C2D78: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C2D7C: multu       $t7, $a0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C2D80: mflo        $t8
    ctx->r24 = lo;
    // 0x800C2D84: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800C2D88: bne         $at, $zero, L_800C2DC0
    if (ctx->r1 != 0) {
        // 0x800C2D8C: sw          $t9, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r25;
            goto L_800C2DC0;
    }
    // 0x800C2D8C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800C2D90: lbu         $t7, 0x0($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X0);
    // 0x800C2D94: lbu         $t8, 0x0($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X0);
    // 0x800C2D98: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800C2D9C: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x800C2DA0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800C2DA4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C2DA8: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800C2DAC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C2DB0: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800C2DB4: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800C2DB8: b           L_800C2DEC
    // 0x800C2DBC: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
        goto L_800C2DEC;
    // 0x800C2DBC: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_800C2DC0:
    // 0x800C2DC0: subu        $t8, $v1, $a0
    ctx->r24 = SUB32(ctx->r3, ctx->r4);
    // 0x800C2DC4: b           L_800C2DEC
    // 0x800C2DC8: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
        goto L_800C2DEC;
    // 0x800C2DC8: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
L_800C2DCC:
    // 0x800C2DCC: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x800C2DD0: nop

    // 0x800C2DD4: beq         $s1, $v1, L_800C2DEC
    if (ctx->r17 == ctx->r3) {
        // 0x800C2DD8: subu        $t9, $v1, $a0
        ctx->r25 = SUB32(ctx->r3, ctx->r4);
            goto L_800C2DEC;
    }
    // 0x800C2DD8: subu        $t9, $v1, $a0
    ctx->r25 = SUB32(ctx->r3, ctx->r4);
    // 0x800C2DDC: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x800C2DE0: bgtz        $t7, L_800C2DEC
    if (SIGNED(ctx->r15) > 0) {
        // 0x800C2DE4: sh          $t9, 0x0($s2)
        MEM_H(0X0, ctx->r18) = ctx->r25;
            goto L_800C2DEC;
    }
    // 0x800C2DE4: sh          $t9, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r25;
    // 0x800C2DE8: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
L_800C2DEC:
    // 0x800C2DEC: beq         $v0, $zero, L_800C2D30
    if (ctx->r2 == 0) {
        // 0x800C2DF0: nop
    
            goto L_800C2D30;
    }
    // 0x800C2DF0: nop

    // 0x800C2DF4: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800C2DF8: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x800C2DFC: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x800C2E00: jr          $ra
    // 0x800C2E04: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C2E04: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void obj_dist_racer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016E1C: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80016E20: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x80016E24: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80016E28: addiu       $s6, $s6, -0x4B90
    ctx->r22 = ADD32(ctx->r22, -0X4B90);
    // 0x80016E2C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x80016E30: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x80016E34: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80016E38: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80016E3C: mtc1        $a3, $f26
    ctx->f26.u32l = ctx->r7;
    // 0x80016E40: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x80016E44: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80016E48: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x80016E4C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80016E50: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80016E54: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80016E58: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x80016E5C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80016E60: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x80016E64: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x80016E68: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80016E6C: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80016E70: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80016E74: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80016E78: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80016E7C: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80016E80: blez        $v0, L_80017080
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80016E84: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80017080;
    }
    // 0x80016E84: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80016E88: blez        $v0, L_80016F7C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80016E8C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80016F7C;
    }
    // 0x80016E8C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80016E90: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80016E94: lw          $s5, 0xC8($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XC8);
    // 0x80016E98: lw          $s0, 0xCC($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XCC);
    // 0x80016E9C: addiu       $s3, $s3, -0x4B9C
    ctx->r19 = ADD32(ctx->r19, -0X4B9C);
    // 0x80016EA0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80016EA4: addiu       $s7, $sp, 0x98
    ctx->r23 = ADD32(ctx->r29, 0X98);
L_80016EA8:
    // 0x80016EA8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80016EAC: nop

    // 0x80016EB0: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x80016EB4: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x80016EB8: nop

    // 0x80016EBC: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80016EC0: nop

    // 0x80016EC4: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80016EC8: nop

    // 0x80016ECC: bltz        $a0, L_80016F68
    if (SIGNED(ctx->r4) < 0) {
        // 0x80016ED0: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_80016F68;
    }
    // 0x80016ED0: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80016ED4: beq         $at, $zero, L_80016F68
    if (ctx->r1 == 0) {
        // 0x80016ED8: nop
    
            goto L_80016F68;
    }
    // 0x80016ED8: nop

    // 0x80016EDC: beq         $s5, $zero, L_80016F0C
    if (ctx->r21 == 0) {
        // 0x80016EE0: nop
    
            goto L_80016F0C;
    }
    // 0x80016EE0: nop

    // 0x80016EE4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80016EE8: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80016EEC: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x80016EF0: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80016EF4: sub.s       $f2, $f6, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x80016EF8: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80016EFC: jal         0x800CA030
    // 0x80016F00: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80016F00: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80016F04: b           L_80016F40
    // 0x80016F08: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
        goto L_80016F40;
    // 0x80016F08: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
L_80016F0C:
    // 0x80016F0C: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80016F10: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80016F14: sub.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x80016F18: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80016F1C: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80016F20: sub.s       $f14, $f18, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f24.fl;
    // 0x80016F24: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80016F28: sub.s       $f2, $f4, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80016F2C: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80016F30: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80016F34: jal         0x800CA030
    // 0x80016F38: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80016F38: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_1:
    // 0x80016F3C: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
L_80016F40:
    // 0x80016F40: sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20 << 2);
    // 0x80016F44: bc1f        L_80016F68
    if (!c1cs) {
        // 0x80016F48: addu        $t8, $s7, $v0
        ctx->r24 = ADD32(ctx->r23, ctx->r2);
            goto L_80016F68;
    }
    // 0x80016F48: addu        $t8, $s7, $v0
    ctx->r24 = ADD32(ctx->r23, ctx->r2);
    // 0x80016F4C: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x80016F50: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80016F54: addu        $t2, $s0, $v0
    ctx->r10 = ADD32(ctx->r16, ctx->r2);
    // 0x80016F58: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x80016F5C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80016F60: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80016F64: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_80016F68:
    // 0x80016F68: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x80016F6C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80016F70: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80016F74: bne         $at, $zero, L_80016EA8
    if (ctx->r1 != 0) {
        // 0x80016F78: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80016EA8;
    }
    // 0x80016F78: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80016F7C:
    // 0x80016F7C: lw          $s0, 0xCC($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XCC);
    // 0x80016F80: slti        $at, $s4, 0x2
    ctx->r1 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
    // 0x80016F84: bne         $at, $zero, L_80017080
    if (ctx->r1 != 0) {
        // 0x80016F88: addiu       $s1, $s4, -0x1
        ctx->r17 = ADD32(ctx->r20, -0X1);
            goto L_80017080;
    }
    // 0x80016F88: addiu       $s1, $s4, -0x1
    ctx->r17 = ADD32(ctx->r20, -0X1);
    // 0x80016F8C: blez        $s1, L_80017084
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80016F90: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80017084;
    }
    // 0x80016F90: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80016F94:
    // 0x80016F94: blez        $s1, L_80017074
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80016F98: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80017074;
    }
    // 0x80016F98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016F9C: andi        $v1, $s1, 0x1
    ctx->r3 = ctx->r17 & 0X1;
    // 0x80016FA0: beq         $v1, $zero, L_80016FE4
    if (ctx->r3 == 0) {
        // 0x80016FA4: addiu       $t5, $sp, 0x98
        ctx->r13 = ADD32(ctx->r29, 0X98);
            goto L_80016FE4;
    }
    // 0x80016FA4: addiu       $t5, $sp, 0x98
    ctx->r13 = ADD32(ctx->r29, 0X98);
    // 0x80016FA8: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80016FAC: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80016FB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80016FB4: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80016FB8: nop

    // 0x80016FBC: bc1f        L_80016FE0
    if (!c1cs) {
        // 0x80016FC0: nop
    
            goto L_80016FE0;
    }
    // 0x80016FC0: nop

    // 0x80016FC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80016FC8: swc1        $f18, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f18.u32l;
    // 0x80016FCC: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80016FD0: nop

    // 0x80016FD4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80016FD8: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    // 0x80016FDC: sw          $a0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r4;
L_80016FE0:
    // 0x80016FE0: beq         $v0, $s1, L_80017074
    if (ctx->r2 == ctx->r17) {
        // 0x80016FE4: sll         $a1, $v0, 2
        ctx->r5 = S32(ctx->r2 << 2);
            goto L_80017074;
    }
L_80016FE4:
    // 0x80016FE4: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x80016FE8: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80016FEC: addu        $a2, $t6, $t5
    ctx->r6 = ADD32(ctx->r14, ctx->r13);
    // 0x80016FF0: addu        $v1, $a1, $t5
    ctx->r3 = ADD32(ctx->r5, ctx->r13);
L_80016FF4:
    // 0x80016FF4: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80016FF8: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80016FFC: addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // 0x80017000: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80017004: nop

    // 0x80017008: bc1f        L_80017034
    if (!c1cs) {
        // 0x8001700C: nop
    
            goto L_80017034;
    }
    // 0x8001700C: nop

    // 0x80017010: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80017014: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80017018: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8001701C: nop

    // 0x80017020: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80017024: swc1        $f12, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f12.u32l;
    // 0x80017028: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8001702C: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80017030: nop

L_80017034:
    // 0x80017034: lwc1        $f12, 0x8($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80017038: addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // 0x8001703C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80017040: nop

    // 0x80017044: bc1f        L_80017068
    if (!c1cs) {
        // 0x80017048: nop
    
            goto L_80017068;
    }
    // 0x80017048: nop

    // 0x8001704C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80017050: swc1        $f12, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f12.u32l;
    // 0x80017054: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80017058: nop

    // 0x8001705C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80017060: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80017064: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
L_80017068:
    // 0x80017068: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8001706C: bne         $v1, $a2, L_80016FF4
    if (ctx->r3 != ctx->r6) {
        // 0x80017070: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_80016FF4;
    }
    // 0x80017070: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_80017074:
    // 0x80017074: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80017078: bne         $s1, $zero, L_80016F94
    if (ctx->r17 != 0) {
        // 0x8001707C: nop
    
            goto L_80016F94;
    }
    // 0x8001707C: nop

L_80017080:
    // 0x80017080: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80017084:
    // 0x80017084: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80017088: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8001708C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80017090: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80017094: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80017098: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001709C: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800170A0: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800170A4: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800170A8: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800170AC: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800170B0: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x800170B4: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x800170B8: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x800170BC: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x800170C0: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x800170C4: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x800170C8: jr          $ra
    // 0x800170CC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800170CC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void menu_close_dialogue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094AE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80094AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094AF0: jal         0x80094AB4
    // 0x80094AF4: nop

    menu_dialogue_end(rdram, ctx);
        goto after_0;
    // 0x80094AF4: nop

    after_0:
    // 0x80094AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80094B00: jr          $ra
    // 0x80094B04: nop

    return;
    // 0x80094B04: nop

;}
RECOMP_FUNC void model_instance_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FF10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005FF14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FF18: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x8005FF1C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005FF20: beq         $t6, $zero, L_8005FFBC
    if (ctx->r14 == 0) {
        // 0x8005FF24: andi        $t7, $a1, 0x8
        ctx->r15 = ctx->r5 & 0X8;
            goto L_8005FFBC;
    }
    // 0x8005FF24: andi        $t7, $a1, 0x8
    ctx->r15 = ctx->r5 & 0X8;
    // 0x8005FF28: beq         $t7, $zero, L_8005FFBC
    if (ctx->r15 == 0) {
        // 0x8005FF2C: nop
    
            goto L_8005FFBC;
    }
    // 0x8005FF2C: nop

    // 0x8005FF30: lh          $a2, 0x24($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X24);
    // 0x8005FF34: lh          $t0, 0x4A($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4A);
    // 0x8005FF38: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8005FF3C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005FF40: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8005FF44: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8005FF48: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8005FF4C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8005FF50: addiu       $a2, $t9, 0x24
    ctx->r6 = ADD32(ctx->r25, 0X24);
    // 0x8005FF54: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8005FF58: addu        $a0, $t1, $a2
    ctx->r4 = ADD32(ctx->r9, ctx->r6);
    // 0x8005FF5C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8005FF60: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8005FF64: jal         0x80070F50
    // 0x8005FF68: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc(rdram, ctx);
        goto after_0;
    // 0x8005FF68: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_0:
    // 0x8005FF6C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FF70: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8005FF74: bne         $v0, $zero, L_8005FF84
    if (ctx->r2 != 0) {
        // 0x8005FF78: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8005FF84;
    }
    // 0x8005FF78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8005FF7C: b           L_80060170
    // 0x8005FF80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80060170;
    // 0x8005FF80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005FF84:
    // 0x8005FF84: addiu       $t2, $v0, 0x24
    ctx->r10 = ADD32(ctx->r2, 0X24);
    // 0x8005FF88: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005FF8C: lh          $t3, 0x24($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X24);
    // 0x8005FF90: addu        $t7, $v0, $a2
    ctx->r15 = ADD32(ctx->r2, ctx->r6);
    // 0x8005FF94: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005FF98: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8005FF9C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8005FFA0: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8005FFA4: addiu       $t6, $t5, 0x24
    ctx->r14 = ADD32(ctx->r13, 0X24);
    // 0x8005FFA8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8005FFAC: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8005FFB0: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x8005FFB4: b           L_8006005C
    // 0x8005FFB8: sb          $t8, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r24;
        goto L_8006005C;
    // 0x8005FFB8: sb          $t8, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r24;
L_8005FFBC:
    // 0x8005FFBC: lw          $t9, 0x40($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X40);
    // 0x8005FFC0: andi        $t0, $a1, 0x1
    ctx->r8 = ctx->r5 & 0X1;
    // 0x8005FFC4: beq         $t9, $zero, L_80060020
    if (ctx->r25 == 0) {
        // 0x8005FFC8: addiu       $a0, $zero, 0x24
        ctx->r4 = ADD32(0, 0X24);
            goto L_80060020;
    }
    // 0x8005FFC8: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x8005FFCC: beq         $t0, $zero, L_80060020
    if (ctx->r8 == 0) {
        // 0x8005FFD0: ori         $a1, $zero, 0xFFFF
        ctx->r5 = 0 | 0XFFFF;
            goto L_80060020;
    }
    // 0x8005FFD0: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8005FFD4: lh          $a2, 0x24($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X24);
    // 0x8005FFD8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8005FFDC: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x8005FFE0: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8005FFE4: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8005FFE8: jal         0x80070F50
    // 0x8005FFEC: addiu       $a0, $t1, 0x24
    ctx->r4 = ADD32(ctx->r9, 0X24);
    mempool_alloc(rdram, ctx);
        goto after_1;
    // 0x8005FFEC: addiu       $a0, $t1, 0x24
    ctx->r4 = ADD32(ctx->r9, 0X24);
    after_1:
    // 0x8005FFF0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8005FFF4: bne         $v0, $zero, L_80060004
    if (ctx->r2 != 0) {
        // 0x8005FFF8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80060004;
    }
    // 0x8005FFF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8005FFFC: b           L_80060170
    // 0x80060000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80060170;
    // 0x80060000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060004:
    // 0x80060004: addiu       $v1, $v0, 0x24
    ctx->r3 = ADD32(ctx->r2, 0X24);
    // 0x80060008: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8006000C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80060010: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x80060014: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80060018: b           L_8006005C
    // 0x8006001C: sb          $t2, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r10;
        goto L_8006005C;
    // 0x8006001C: sb          $t2, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r10;
L_80060020:
    // 0x80060020: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x80060024: jal         0x80070F50
    // 0x80060028: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    mempool_alloc(rdram, ctx);
        goto after_2;
    // 0x80060028: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x8006002C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80060030: bne         $v0, $zero, L_80060040
    if (ctx->r2 != 0) {
        // 0x80060034: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80060040;
    }
    // 0x80060034: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80060038: b           L_80060170
    // 0x8006003C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80060170;
    // 0x8006003C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060040:
    // 0x80060040: lw          $t3, 0x4($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X4);
    // 0x80060044: nop

    // 0x80060048: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8006004C: lw          $t4, 0x4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X4);
    // 0x80060050: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80060054: sb          $zero, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = 0;
    // 0x80060058: sw          $t4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r12;
L_8006005C:
    // 0x8006005C: lb          $t5, 0x1E($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X1E);
    // 0x80060060: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80060064: sh          $zero, 0x16($v0)
    MEM_H(0X16, ctx->r2) = 0;
    // 0x80060068: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
    // 0x8006006C: sh          $zero, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = 0;
    // 0x80060070: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80060074: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x80060078: sh          $v1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r3;
    // 0x8006007C: beq         $t5, $zero, L_8006016C
    if (ctx->r13 == 0) {
        // 0x80060080: sb          $zero, 0x1F($v0)
        MEM_B(0X1F, ctx->r2) = 0;
            goto L_8006016C;
    }
    // 0x80060080: sb          $zero, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = 0;
    // 0x80060084: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80060088: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x8006008C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80060090:
    // 0x80060090: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80060094: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80060098: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x8006009C: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x800600A0: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x800600A4: sh          $t7, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r15;
    // 0x800600A8: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x800600AC: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x800600B0: sh          $t8, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r24;
    // 0x800600B4: lbu         $t9, -0x4($a0)
    ctx->r25 = MEM_BU(ctx->r4, -0X4);
    // 0x800600B8: nop

    // 0x800600BC: sb          $t9, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r25;
    // 0x800600C0: lbu         $t0, -0x3($a0)
    ctx->r8 = MEM_BU(ctx->r4, -0X3);
    // 0x800600C4: nop

    // 0x800600C8: sb          $t0, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r8;
    // 0x800600CC: lbu         $t1, -0x2($a0)
    ctx->r9 = MEM_BU(ctx->r4, -0X2);
    // 0x800600D0: nop

    // 0x800600D4: sb          $t1, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r9;
    // 0x800600D8: lbu         $t2, -0x1($a0)
    ctx->r10 = MEM_BU(ctx->r4, -0X1);
    // 0x800600DC: nop

    // 0x800600E0: sb          $t2, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r10;
    // 0x800600E4: lh          $t3, 0x24($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X24);
    // 0x800600E8: nop

    // 0x800600EC: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800600F0: bne         $at, $zero, L_80060090
    if (ctx->r1 != 0) {
        // 0x800600F4: nop
    
            goto L_80060090;
    }
    // 0x800600F4: nop

    // 0x800600F8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x800600FC: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x80060100: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80060104:
    // 0x80060104: lh          $t4, 0x0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X0);
    // 0x80060108: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8006010C: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x80060110: lh          $t5, 0x2($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X2);
    // 0x80060114: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x80060118: sh          $t5, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r13;
    // 0x8006011C: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x80060120: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x80060124: sh          $t6, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r14;
    // 0x80060128: lbu         $t7, -0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, -0X4);
    // 0x8006012C: nop

    // 0x80060130: sb          $t7, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r15;
    // 0x80060134: lbu         $t8, -0x3($a0)
    ctx->r24 = MEM_BU(ctx->r4, -0X3);
    // 0x80060138: nop

    // 0x8006013C: sb          $t8, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r24;
    // 0x80060140: lbu         $t9, -0x2($a0)
    ctx->r25 = MEM_BU(ctx->r4, -0X2);
    // 0x80060144: nop

    // 0x80060148: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x8006014C: lbu         $t0, -0x1($a0)
    ctx->r8 = MEM_BU(ctx->r4, -0X1);
    // 0x80060150: nop

    // 0x80060154: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
    // 0x80060158: lh          $t1, 0x24($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X24);
    // 0x8006015C: nop

    // 0x80060160: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80060164: bne         $at, $zero, L_80060104
    if (ctx->r1 != 0) {
        // 0x80060168: nop
    
            goto L_80060104;
    }
    // 0x80060168: nop

L_8006016C:
    // 0x8006016C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80060170:
    // 0x80060170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80060178: jr          $ra
    // 0x8006017C: nop

    return;
    // 0x8006017C: nop

;}
RECOMP_FUNC void hud_race_time(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A80C4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A80C8: lw          $a3, 0x72CC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X72CC);
    // 0x800A80CC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800A80D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A80D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A80D8: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800A80DC: beq         $a3, $zero, L_800A8138
    if (ctx->r7 == 0) {
        // 0x800A80E0: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800A8138;
    }
    // 0x800A80E0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A80E4: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800A80E8: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x800A80EC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800A80F0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A80F4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800A80F8: lbu         $t9, 0x2D14($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X2D14);
    // 0x800A80FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A8100: beq         $t9, $at, L_800A8138
    if (ctx->r25 == ctx->r1) {
        // 0x800A8104: nop
    
            goto L_800A8138;
    }
    // 0x800A8104: nop

    // 0x800A8108: blez        $a3, L_800A850C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800A810C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A850C;
    }
    // 0x800A810C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A8110: lb          $v0, 0x193($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X193);
    // 0x800A8114: nop

    // 0x800A8118: blez        $v0, L_800A8508
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A811C: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_800A8508;
    }
    // 0x800A811C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x800A8120: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x800A8124: lw          $t5, 0x128($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X128);
    // 0x800A8128: nop

    // 0x800A812C: slti        $at, $t5, 0xB4
    ctx->r1 = SIGNED(ctx->r13) < 0XB4 ? 1 : 0;
    // 0x800A8130: beq         $at, $zero, L_800A850C
    if (ctx->r1 == 0) {
        // 0x800A8134: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A850C;
    }
    // 0x800A8134: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A8138:
    // 0x800A8138: lb          $t2, 0x1D8($a2)
    ctx->r10 = MEM_B(ctx->r6, 0X1D8);
    // 0x800A813C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A8140: bne         $t2, $zero, L_800A850C
    if (ctx->r10 != 0) {
        // 0x800A8144: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A850C;
    }
    // 0x800A8144: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A8148: lw          $t0, 0x729C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X729C);
    // 0x800A814C: lb          $v0, 0x193($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X193);
    // 0x800A8150: lb          $t1, 0x15A($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X15A);
    // 0x800A8154: blez        $v0, L_800A81A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A8158: addiu       $t1, $t1, 0x7F
        ctx->r9 = ADD32(ctx->r9, 0X7F);
            goto L_800A81A8;
    }
    // 0x800A8158: addiu       $t1, $t1, 0x7F
    ctx->r9 = ADD32(ctx->r9, 0X7F);
    // 0x800A815C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800A8160: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x800A8164: lw          $t7, 0x128($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X128);
    // 0x800A8168: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A816C: slti        $at, $t7, 0xB4
    ctx->r1 = SIGNED(ctx->r15) < 0XB4 ? 1 : 0;
    // 0x800A8170: beq         $at, $zero, L_800A81A8
    if (ctx->r1 == 0) {
        // 0x800A8174: nop
    
            goto L_800A81A8;
    }
    // 0x800A8174: nop

    // 0x800A8178: lw          $t8, 0x7320($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7320);
    // 0x800A817C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A8180: lb          $t9, 0x4B($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X4B);
    // 0x800A8184: nop

    // 0x800A8188: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A818C: beq         $at, $zero, L_800A81A8
    if (ctx->r1 == 0) {
        // 0x800A8190: nop
    
            goto L_800A81A8;
    }
    // 0x800A8190: nop

    // 0x800A8194: lw          $s0, 0x124($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X124);
    // 0x800A8198: bne         $t1, $zero, L_800A823C
    if (ctx->r9 != 0) {
        // 0x800A819C: sw          $t3, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r11;
            goto L_800A823C;
    }
    // 0x800A819C: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x800A81A0: b           L_800A823C
    // 0x800A81A4: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
        goto L_800A823C;
    // 0x800A81A4: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
L_800A81A8:
    // 0x800A81A8: lb          $a1, 0x194($a2)
    ctx->r5 = MEM_B(ctx->r6, 0X194);
    // 0x800A81AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A81B0: bltz        $a1, L_800A81F8
    if (SIGNED(ctx->r5) < 0) {
        // 0x800A81B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800A81F8;
    }
    // 0x800A81B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A81B8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A81BC: lw          $t4, 0x7320($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7320);
    // 0x800A81C0: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800A81C4: lb          $a0, 0x4B($t4)
    ctx->r4 = MEM_B(ctx->r12, 0X4B);
    // 0x800A81C8: addu        $v1, $a2, $t5
    ctx->r3 = ADD32(ctx->r6, ctx->r13);
    // 0x800A81CC: blez        $a0, L_800A81F8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800A81D0: nop
    
            goto L_800A81F8;
    }
    // 0x800A81D0: nop

L_800A81D4:
    // 0x800A81D4: lw          $t6, 0x128($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X128);
    // 0x800A81D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800A81DC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800A81E0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A81E4: bne         $at, $zero, L_800A81F8
    if (ctx->r1 != 0) {
        // 0x800A81E8: addu        $s0, $s0, $t6
        ctx->r16 = ADD32(ctx->r16, ctx->r14);
            goto L_800A81F8;
    }
    // 0x800A81E8: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x800A81EC: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800A81F0: bne         $at, $zero, L_800A81D4
    if (ctx->r1 != 0) {
        // 0x800A81F4: nop
    
            goto L_800A81D4;
    }
    // 0x800A81F4: nop

L_800A81F8:
    // 0x800A81F8: sltiu       $v1, $s0, 0x1
    ctx->r3 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x800A81FC: bne         $v1, $zero, L_800A8224
    if (ctx->r3 != 0) {
        // 0x800A8200: nop
    
            goto L_800A8224;
    }
    // 0x800A8200: nop

    // 0x800A8204: sltu        $v1, $zero, $t2
    ctx->r3 = 0 < ctx->r10 ? 1 : 0;
    // 0x800A8208: bne         $v1, $zero, L_800A8224
    if (ctx->r3 != 0) {
        // 0x800A820C: nop
    
            goto L_800A8224;
    }
    // 0x800A820C: nop

    // 0x800A8210: jal         0x8006ECE0
    // 0x800A8214: nop

    is_game_paused(rdram, ctx);
        goto after_0;
    // 0x800A8214: nop

    after_0:
    // 0x800A8218: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A821C: lw          $t0, 0x729C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X729C);
    // 0x800A8220: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_800A8224:
    // 0x800A8224: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x800A8228: addiu       $t7, $zero, -0x7F
    ctx->r15 = ADD32(0, -0X7F);
    // 0x800A822C: sb          $t7, 0x15A($t0)
    MEM_B(0X15A, ctx->r8) = ctx->r15;
    // 0x800A8230: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A8234: lw          $a3, 0x72CC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X72CC);
    // 0x800A8238: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800A823C:
    // 0x800A823C: bne         $a3, $zero, L_800A8274
    if (ctx->r7 != 0) {
        // 0x800A8240: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A8274;
    }
    // 0x800A8240: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A8244: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A8248: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A824C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8250: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A8254: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A8258: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A825C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A8260: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x800A8264: jal         0x800AAB5C
    // 0x800A8268: addiu       $a3, $a3, 0x140
    ctx->r7 = ADD32(ctx->r7, 0X140);
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A8268: addiu       $a3, $a3, 0x140
    ctx->r7 = ADD32(ctx->r7, 0X140);
    after_1:
    // 0x800A826C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A8270: nop

L_800A8274:
    // 0x800A8274: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    // 0x800A8278: jal         0x8000C8B4
    // 0x800A827C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    normalise_time(rdram, ctx);
        goto after_2;
    // 0x800A827C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_2:
    // 0x800A8280: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A8284: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800A8288: beq         $at, $zero, L_800A82A0
    if (ctx->r1 == 0) {
        // 0x800A828C: ori         $a0, $zero, 0x8CA0
        ctx->r4 = 0 | 0X8CA0;
            goto L_800A82A0;
    }
    // 0x800A828C: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    // 0x800A8290: jal         0x8000C8B4
    // 0x800A8294: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    normalise_time(rdram, ctx);
        goto after_3;
    // 0x800A8294: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_3:
    // 0x800A8298: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A829C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800A82A0:
    // 0x800A82A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A82A4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800A82A8: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x800A82AC: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    // 0x800A82B0: jal         0x800597E0
    // 0x800A82B4: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    get_timestamp_from_frames(rdram, ctx);
        goto after_4;
    // 0x800A82B4: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_4:
    // 0x800A82B8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800A82BC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A82C0: bne         $t8, $zero, L_800A82DC
    if (ctx->r24 != 0) {
        // 0x800A82C4: ori         $a0, $zero, 0x8CA0
        ctx->r4 = 0 | 0X8CA0;
            goto L_800A82DC;
    }
    // 0x800A82C4: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    // 0x800A82C8: jal         0x8000C8B4
    // 0x800A82CC: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    normalise_time(rdram, ctx);
        goto after_5;
    // 0x800A82CC: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_5:
    // 0x800A82D0: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A82D4: bne         $v0, $s0, L_800A8378
    if (ctx->r2 != ctx->r16) {
        // 0x800A82D8: lw          $t3, 0x4C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X4C);
            goto L_800A8378;
    }
    // 0x800A82D8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
L_800A82DC:
    // 0x800A82DC: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800A82E0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A82E4: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A82E8: beq         $at, $zero, L_800A82F8
    if (ctx->r1 == 0) {
        // 0x800A82EC: addiu       $s0, $s0, 0x72F6
        ctx->r16 = ADD32(ctx->r16, 0X72F6);
            goto L_800A82F8;
    }
    // 0x800A82EC: addiu       $s0, $s0, 0x72F6
    ctx->r16 = ADD32(ctx->r16, 0X72F6);
    // 0x800A82F0: b           L_800A82FC
    // 0x800A82F4: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
        goto L_800A82FC;
    // 0x800A82F4: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
L_800A82F8:
    // 0x800A82F8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800A82FC:
    // 0x800A82FC: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800A8300: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x800A8304: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A8308: lw          $t4, 0x729C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X729C);
    // 0x800A830C: addiu       $t3, $t1, -0x7F
    ctx->r11 = ADD32(ctx->r9, -0X7F);
    // 0x800A8310: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A8314: sb          $t3, 0x15A($t4)
    MEM_B(0X15A, ctx->r12) = ctx->r11;
    // 0x800A8318: mfhi        $t5
    ctx->r13 = hi;
    // 0x800A831C: slti        $at, $t5, 0x15
    ctx->r1 = SIGNED(ctx->r13) < 0X15 ? 1 : 0;
    // 0x800A8320: bne         $at, $zero, L_800A8338
    if (ctx->r1 != 0) {
        // 0x800A8324: nop
    
            goto L_800A8338;
    }
    // 0x800A8324: nop

    // 0x800A8328: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A832C: addiu       $s0, $s0, 0x72F6
    ctx->r16 = ADD32(ctx->r16, 0X72F6);
    // 0x800A8330: b           L_800A8508
    // 0x800A8334: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
        goto L_800A8508;
    // 0x800A8334: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
L_800A8338:
    // 0x800A8338: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x800A833C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A8340: beq         $t7, $zero, L_800A8364
    if (ctx->r15 == 0) {
        // 0x800A8344: nop
    
            goto L_800A8364;
    }
    // 0x800A8344: nop

    // 0x800A8348: lw          $t8, 0x72CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72CC);
    // 0x800A834C: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x800A8350: bne         $t8, $zero, L_800A8360
    if (ctx->r24 != 0) {
        // 0x800A8354: nop
    
            goto L_800A8360;
    }
    // 0x800A8354: nop

    // 0x800A8358: jal         0x80001D04
    // 0x800A835C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x800A835C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_800A8360:
    // 0x800A8360: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_800A8364:
    // 0x800A8364: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A8368: lw          $t0, 0x729C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X729C);
    // 0x800A836C: b           L_800A8410
    // 0x800A8370: nop

        goto L_800A8410;
    // 0x800A8370: nop

    // 0x800A8374: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
L_800A8378:
    // 0x800A8378: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800A837C: div         $zero, $t3, $v0
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r2)));
    // 0x800A8380: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A8384: lw          $t0, 0x729C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X729C);
    // 0x800A8388: nop

    // 0x800A838C: lb          $t9, 0x15B($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X15B);
    // 0x800A8390: bne         $v0, $zero, L_800A839C
    if (ctx->r2 != 0) {
        // 0x800A8394: nop
    
            goto L_800A839C;
    }
    // 0x800A8394: nop

    // 0x800A8398: break       7
    do_break(2148172696);
L_800A839C:
    // 0x800A839C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A83A0: bne         $v0, $at, L_800A83B4
    if (ctx->r2 != ctx->r1) {
        // 0x800A83A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A83B4;
    }
    // 0x800A83A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A83A8: bne         $t3, $at, L_800A83B4
    if (ctx->r11 != ctx->r1) {
        // 0x800A83AC: nop
    
            goto L_800A83B4;
    }
    // 0x800A83AC: nop

    // 0x800A83B0: break       6
    do_break(2148172720);
L_800A83B4:
    // 0x800A83B4: mflo        $t4
    ctx->r12 = lo;
    // 0x800A83B8: nop

    // 0x800A83BC: nop

    // 0x800A83C0: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A83C4: mflo        $t5
    ctx->r13 = lo;
    // 0x800A83C8: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800A83CC: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x800A83D0: lb          $t7, 0x15B($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X15B);
    // 0x800A83D4: nop

    // 0x800A83D8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800A83DC: sb          $t8, 0x15B($t0)
    MEM_B(0X15B, ctx->r8) = ctx->r24;
    // 0x800A83E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A83E4: lw          $t0, 0x729C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X729C);
    // 0x800A83E8: nop

    // 0x800A83EC: lb          $t3, 0x15B($t0)
    ctx->r11 = MEM_B(ctx->r8, 0X15B);
    // 0x800A83F0: nop

    // 0x800A83F4: slti        $at, $t3, 0xA
    ctx->r1 = SIGNED(ctx->r11) < 0XA ? 1 : 0;
    // 0x800A83F8: bne         $at, $zero, L_800A8410
    if (ctx->r1 != 0) {
        // 0x800A83FC: nop
    
            goto L_800A8410;
    }
    // 0x800A83FC: nop

    // 0x800A8400: sb          $zero, 0x15B($t0)
    MEM_B(0X15B, ctx->r8) = 0;
    // 0x800A8404: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A8408: lw          $t0, 0x729C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X729C);
    // 0x800A840C: nop

L_800A8410:
    // 0x800A8410: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A8414: lbu         $t4, 0x72F7($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X72F7);
    // 0x800A8418: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A841C: bne         $t4, $at, L_800A8488
    if (ctx->r12 != ctx->r1) {
        // 0x800A8420: nop
    
            goto L_800A8488;
    }
    // 0x800A8420: nop

    // 0x800A8424: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A8428: lwc1        $f4, 0x16C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X16C);
    // 0x800A842C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A8430: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8434: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8438: lwc1        $f8, 0x170($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X170);
    // 0x800A843C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A8440: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A8444: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A8448: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800A844C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800A8450: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A8454: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800A8458: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A845C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8460: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8464: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800A8468: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A846C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A8470: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A8474: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A8478: jal         0x800A8518
    // 0x800A847C: nop

    hud_timer_render(rdram, ctx);
        goto after_7;
    // 0x800A847C: nop

    after_7:
    // 0x800A8480: b           L_800A84E4
    // 0x800A8484: nop

        goto L_800A84E4;
    // 0x800A8484: nop

L_800A8488:
    // 0x800A8488: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A848C: lwc1        $f16, 0x16C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X16C);
    // 0x800A8490: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A8494: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8498: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A849C: lwc1        $f4, 0x170($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X170);
    // 0x800A84A0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A84A4: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A84A8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A84AC: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x800A84B0: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800A84B4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A84B8: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800A84BC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A84C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A84C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A84C8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A84CC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A84D0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800A84D4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A84D8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A84DC: jal         0x800A8518
    // 0x800A84E0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    hud_timer_render(rdram, ctx);
        goto after_8;
    // 0x800A84E0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_8:
L_800A84E4:
    // 0x800A84E4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A84E8: lw          $v1, 0x72BC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72BC);
    // 0x800A84EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A84F0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800A84F4: sw          $t9, 0x72BC($at)
    MEM_W(0X72BC, ctx->r1) = ctx->r25;
    // 0x800A84F8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800A84FC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800A8500: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800A8504: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_800A8508:
    // 0x800A8508: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A850C:
    // 0x800A850C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A8510: jr          $ra
    // 0x800A8514: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800A8514: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void audspat_debug_render_lines(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A184: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000A188: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8000A18C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8000A190: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8000A194: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8000A198: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8000A19C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8000A1A0: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8000A1A4: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8000A1A8: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8000A1AC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8000A1B0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8000A1B4: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x8000A1B8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8000A1BC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8000A1C0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8000A1C4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000A1C8: addiu       $fp, $fp, -0x53A4
    ctx->r30 = ADD32(ctx->r30, -0X53A4);
    // 0x8000A1CC: addiu       $s7, $s7, -0x5E24
    ctx->r23 = ADD32(ctx->r23, -0X5E24);
    // 0x8000A1D0: addiu       $s6, $s6, -0x5E28
    ctx->r22 = ADD32(ctx->r22, -0X5E28);
L_8000A1D4:
    // 0x8000A1D4: lw          $t6, 0x16C($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X16C);
    // 0x8000A1D8: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x8000A1DC: beq         $t6, $zero, L_8000A22C
    if (ctx->r14 == 0) {
        // 0x8000A1E0: or          $s1, $s7, $zero
        ctx->r17 = ctx->r23 | 0;
            goto L_8000A22C;
    }
    // 0x8000A1E0: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x8000A1E4: lb          $t7, 0x17C($s6)
    ctx->r15 = MEM_B(ctx->r22, 0X17C);
    // 0x8000A1E8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000A1EC: blez        $t7, L_8000A22C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8000A1F0: addiu       $t8, $zero, 0xFF
        ctx->r24 = ADD32(0, 0XFF);
            goto L_8000A22C;
    }
L_8000A1F0:
    // 0x8000A1F0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8000A1F4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8000A1F8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8000A1FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8000A200: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000A204: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8000A208: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8000A20C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8000A210: jal         0x8000A414
    // 0x8000A214: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    audspat_debug_render_line(rdram, ctx);
        goto after_0;
    // 0x8000A214: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_0:
    // 0x8000A218: lb          $t0, 0x17C($s2)
    ctx->r8 = MEM_B(ctx->r18, 0X17C);
    // 0x8000A21C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000A220: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000A224: bne         $at, $zero, L_8000A1F0
    if (ctx->r1 != 0) {
        // 0x8000A228: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8000A1F0;
    }
    // 0x8000A228: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8000A22C:
    // 0x8000A22C: addiu       $s7, $s7, 0x180
    ctx->r23 = ADD32(ctx->r23, 0X180);
    // 0x8000A230: sltu        $at, $s7, $fp
    ctx->r1 = ctx->r23 < ctx->r30 ? 1 : 0;
    // 0x8000A234: bne         $at, $zero, L_8000A1D4
    if (ctx->r1 != 0) {
        // 0x8000A238: addiu       $s6, $s6, 0x180
        ctx->r22 = ADD32(ctx->r22, 0X180);
            goto L_8000A1D4;
    }
    // 0x8000A238: addiu       $s6, $s6, 0x180
    ctx->r22 = ADD32(ctx->r22, 0X180);
    // 0x8000A23C: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8000A240: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8000A244: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8000A248: addiu       $fp, $fp, -0x4E64
    ctx->r30 = ADD32(ctx->r30, -0X4E64);
    // 0x8000A24C: addiu       $s7, $s7, -0x53A4
    ctx->r23 = ADD32(ctx->r23, -0X53A4);
    // 0x8000A250: addiu       $s6, $s6, -0x53A8
    ctx->r22 = ADD32(ctx->r22, -0X53A8);
L_8000A254:
    // 0x8000A254: lbu         $t1, 0x0($s6)
    ctx->r9 = MEM_BU(ctx->r22, 0X0);
    // 0x8000A258: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x8000A25C: beq         $t1, $zero, L_8000A2AC
    if (ctx->r9 == 0) {
        // 0x8000A260: or          $s1, $s7, $zero
        ctx->r17 = ctx->r23 | 0;
            goto L_8000A2AC;
    }
    // 0x8000A260: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x8000A264: lb          $t2, 0xB8($s6)
    ctx->r10 = MEM_B(ctx->r22, 0XB8);
    // 0x8000A268: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000A26C: blez        $t2, L_8000A2AC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8000A270: addiu       $t3, $zero, 0xFF
        ctx->r11 = ADD32(0, 0XFF);
            goto L_8000A2AC;
    }
L_8000A270:
    // 0x8000A270: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8000A274: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8000A278: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8000A27C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8000A280: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000A284: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8000A288: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8000A28C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8000A290: jal         0x8000A414
    // 0x8000A294: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_debug_render_line(rdram, ctx);
        goto after_1;
    // 0x8000A294: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x8000A298: lb          $t5, 0xB8($s2)
    ctx->r13 = MEM_B(ctx->r18, 0XB8);
    // 0x8000A29C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000A2A0: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000A2A4: bne         $at, $zero, L_8000A270
    if (ctx->r1 != 0) {
        // 0x8000A2A8: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8000A270;
    }
    // 0x8000A2A8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8000A2AC:
    // 0x8000A2AC: addiu       $s7, $s7, 0xC0
    ctx->r23 = ADD32(ctx->r23, 0XC0);
    // 0x8000A2B0: bne         $s7, $fp, L_8000A254
    if (ctx->r23 != ctx->r30) {
        // 0x8000A2B4: addiu       $s6, $s6, 0xC0
        ctx->r22 = ADD32(ctx->r22, 0XC0);
            goto L_8000A254;
    }
    // 0x8000A2B4: addiu       $s6, $s6, 0xC0
    ctx->r22 = ADD32(ctx->r22, 0XC0);
    // 0x8000A2B8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8000A2BC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000A2C0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A2C4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8000A2C8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8000A2CC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8000A2D0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8000A2D4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8000A2D8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8000A2DC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8000A2E0: jr          $ra
    // 0x8000A2E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000A2E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8009BE54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C398: jr          $ra
    // 0x8009C39C: nop

    return;
    // 0x8009C39C: nop

;}
RECOMP_FUNC void get_lockup_status(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7BFC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B7C00: addiu       $v0, $v0, 0x35B0
    ctx->r2 = ADD32(ctx->r2, 0X35B0);
    // 0x800B7C04: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800B7C08: addiu       $sp, $sp, -0x828
    ctx->r29 = ADD32(ctx->r29, -0X828);
    // 0x800B7C0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B7C10: beq         $v1, $at, L_800B7C20
    if (ctx->r3 == ctx->r1) {
        // 0x800B7C14: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800B7C20;
    }
    // 0x800B7C14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7C18: b           L_800B7CE4
    // 0x800B7C1C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800B7CE4;
    // 0x800B7C1C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B7C20:
    // 0x800B7C20: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B7C24: jal         0x80075B34
    // 0x800B7C28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x800B7C28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800B7C2C: bne         $v0, $zero, L_800B7CB0
    if (ctx->r2 != 0) {
        // 0x800B7C30: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B7CB0;
    }
    // 0x800B7C30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B7C34: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800B7C38: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800B7C3C: addiu       $a2, $a2, -0x6B84
    ctx->r6 = ADD32(ctx->r6, -0X6B84);
    // 0x800B7C40: addiu       $a1, $a1, -0x6B8C
    ctx->r5 = ADD32(ctx->r5, -0X6B8C);
    // 0x800B7C44: jal         0x80076740
    // 0x800B7C48: addiu       $a3, $sp, 0x824
    ctx->r7 = ADD32(ctx->r29, 0X824);
    get_file_number(rdram, ctx);
        goto after_1;
    // 0x800B7C48: addiu       $a3, $sp, 0x824
    ctx->r7 = ADD32(ctx->r29, 0X824);
    after_1:
    // 0x800B7C4C: bne         $v0, $zero, L_800B7CB0
    if (ctx->r2 != 0) {
        // 0x800B7C50: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B7CB0;
    }
    // 0x800B7C50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B7C54: lw          $a1, 0x824($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X824);
    // 0x800B7C58: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800B7C5C: jal         0x80076868
    // 0x800B7C60: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
    read_data_from_controller_pak(rdram, ctx);
        goto after_2;
    // 0x800B7C60: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
    after_2:
    // 0x800B7C64: bne         $v0, $zero, L_800B7CB0
    if (ctx->r2 != 0) {
        // 0x800B7C68: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_800B7CB0;
    }
    // 0x800B7C68: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800B7C6C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7C70: addiu       $a1, $a1, -0x6240
    ctx->r5 = ADD32(ctx->r5, -0X6240);
    // 0x800B7C74: jal         0x800CA300
    // 0x800B7C78: addiu       $a2, $zero, 0x1B0
    ctx->r6 = ADD32(0, 0X1B0);
    _bcopy(rdram, ctx);
        goto after_3;
    // 0x800B7C78: addiu       $a2, $zero, 0x1B0
    ctx->r6 = ADD32(0, 0X1B0);
    after_3:
    // 0x800B7C7C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7C80: addiu       $a1, $a1, -0x6090
    ctx->r5 = ADD32(ctx->r5, -0X6090);
    // 0x800B7C84: addiu       $a0, $sp, 0x220
    ctx->r4 = ADD32(ctx->r29, 0X220);
    // 0x800B7C88: jal         0x800CA300
    // 0x800B7C8C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    _bcopy(rdram, ctx);
        goto after_4;
    // 0x800B7C8C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_4:
    // 0x800B7C90: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7C94: addiu       $a1, $a1, -0x5E90
    ctx->r5 = ADD32(ctx->r5, -0X5E90);
    // 0x800B7C98: addiu       $a0, $sp, 0x420
    ctx->r4 = ADD32(ctx->r29, 0X420);
    // 0x800B7C9C: jal         0x800CA300
    // 0x800B7CA0: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    _bcopy(rdram, ctx);
        goto after_5;
    // 0x800B7CA0: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    after_5:
    // 0x800B7CA4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B7CA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7CAC: sw          $t6, 0x35B0($at)
    MEM_W(0X35B0, ctx->r1) = ctx->r14;
L_800B7CB0:
    // 0x800B7CB0: jal         0x80075D44
    // 0x800B7CB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_6;
    // 0x800B7CB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800B7CB8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B7CBC: lw          $v1, 0x35B0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X35B0);
    // 0x800B7CC0: lw          $a1, 0x824($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X824);
    // 0x800B7CC4: beq         $v1, $zero, L_800B7CE4
    if (ctx->r3 == 0) {
        // 0x800B7CC8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B7CE4;
    }
    // 0x800B7CC8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B7CCC: jal         0x80076520
    // 0x800B7CD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    delete_file(rdram, ctx);
        goto after_7;
    // 0x800B7CD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800B7CD4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B7CD8: lw          $v1, 0x35B0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X35B0);
    // 0x800B7CDC: nop

    // 0x800B7CE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B7CE4:
    // 0x800B7CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7CE8: addiu       $sp, $sp, 0x828
    ctx->r29 = ADD32(ctx->r29, 0X828);
    // 0x800B7CEC: jr          $ra
    // 0x800B7CF0: nop

    return;
    // 0x800B7CF0: nop

;}
RECOMP_FUNC void obj_loop_wardensmoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038B14: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80038B18: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80038B1C: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80038B20: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80038B24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038B2C: bne         $t6, $zero, L_80038B4C
    if (ctx->r14 != 0) {
        // 0x80038B30: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80038B4C;
    }
    // 0x80038B30: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80038B34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80038B38: lwc1        $f9, 0x65E8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X65E8);
    // 0x80038B3C: lwc1        $f8, 0x65EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X65EC);
    // 0x80038B40: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80038B44: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80038B48: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80038B4C:
    // 0x80038B4C: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80038B50: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80038B54: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80038B58: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80038B5C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80038B60: lh          $t7, 0x18($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X18);
    // 0x80038B64: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80038B68: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80038B6C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80038B70: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
    // 0x80038B74: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80038B78: add.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d + ctx->f4.d;
    // 0x80038B7C: lh          $t0, 0x18($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X18);
    // 0x80038B80: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80038B84: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x80038B88: bne         $at, $zero, L_80038BA4
    if (ctx->r1 != 0) {
        // 0x80038B8C: swc1        $f16, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
            goto L_80038BA4;
    }
    // 0x80038B8C: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x80038B90: jal         0x8000FFB8
    // 0x80038B94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    free_object(rdram, ctx);
        goto after_0;
    // 0x80038B94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038B98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038B9C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80038BA0: sh          $t1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r9;
L_80038BA4:
    // 0x80038BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038BA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038BAC: jr          $ra
    // 0x80038BB0: nop

    return;
    // 0x80038BB0: nop

;}
RECOMP_FUNC void obj_loop_stopwatchman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036220: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80036224: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80036228: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003622C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80036230: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80036234: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80036238: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8003623C: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80036240: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80036244: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80036248: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003624C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80036250: bne         $t7, $zero, L_80036270
    if (ctx->r15 != 0) {
        // 0x80036254: swc1        $f4, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
            goto L_80036270;
    }
    // 0x80036254: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x80036258: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003625C: lwc1        $f11, 0x65B8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X65B8);
    // 0x80036260: lwc1        $f10, 0x65BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65BC);
    // 0x80036264: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80036268: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8003626C: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
L_80036270:
    // 0x80036270: lh          $t8, 0x18($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X18);
    // 0x80036274: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x80036278: bne         $t8, $zero, L_800362B0
    if (ctx->r24 != 0) {
        // 0x8003627C: nop
    
            goto L_800362B0;
    }
    // 0x8003627C: nop

    // 0x80036280: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036284: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80036288: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8003628C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036290: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80036294: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80036298: nop

    // 0x8003629C: bc1f        L_800362B0
    if (!c1cs) {
        // 0x800362A0: nop
    
            goto L_800362B0;
    }
    // 0x800362A0: nop

    // 0x800362A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800362A8: nop

    // 0x800362AC: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_800362B0:
    // 0x800362B0: jal         0x8006BFF0
    // 0x800362B4: swc1        $f2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f2.u32l;
    level_header(rdram, ctx);
        goto after_0;
    // 0x800362B4: swc1        $f2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x800362B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800362BC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800362C0: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x800362C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800362C8: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800362CC: jal         0x8001BAFC
    // 0x800362D0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    get_racer_object(rdram, ctx);
        goto after_1;
    // 0x800362D0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x800362D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800362D8: beq         $v0, $zero, L_800363E4
    if (ctx->r2 == 0) {
        // 0x800362DC: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_800363E4;
    }
    // 0x800362DC: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800362E0: lw          $v0, 0x64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X64);
    // 0x800362E4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800362E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800362EC: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x800362F0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800362F4: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800362F8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800362FC: lwc1        $f10, 0x50($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X50);
    // 0x80036300: lwc1        $f18, 0xC($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80036304: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80036308: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003630C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036310: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80036314: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80036318: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8003631C: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80036320: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80036324: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80036328: nop

    // 0x8003632C: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80036330: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80036334: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80036338: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    // 0x8003633C: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80036340: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80036344: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80036348: sub.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8003634C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80036350: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    // 0x80036354: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80036358: jal         0x800CA030
    // 0x8003635C: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x8003635C: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    after_2:
    // 0x80036360: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x80036364: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80036368: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003636C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036370: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80036374: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80036378: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003637C: jal         0x80070990
    // 0x80036380: sub.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f4.fl;
    arctan2_f(rdram, ctx);
        goto after_3;
    // 0x80036380: sub.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f4.fl;
    after_3:
    // 0x80036384: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80036388: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8003638C: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80036390: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80036394: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x80036398: subu        $v1, $v0, $t1
    ctx->r3 = SUB32(ctx->r2, ctx->r9);
    // 0x8003639C: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800363A0: bne         $at, $zero, L_800363B4
    if (ctx->r1 != 0) {
        // 0x800363A4: slti        $at, $v1, -0x8000
        ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
            goto L_800363B4;
    }
    // 0x800363A4: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800363A8: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x800363AC: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x800363B0: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
L_800363B4:
    // 0x800363B4: beq         $at, $zero, L_800363C4
    if (ctx->r1 == 0) {
        // 0x800363B8: lw          $t2, 0x50($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X50);
            goto L_800363C4;
    }
    // 0x800363B8: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800363BC: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800363C0: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
L_800363C4:
    // 0x800363C4: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    // 0x800363C8: lw          $t3, 0x108($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X108);
    // 0x800363CC: nop

    // 0x800363D0: beq         $t3, $zero, L_800363E4
    if (ctx->r11 == 0) {
        // 0x800363D4: nop
    
            goto L_800363E4;
    }
    // 0x800363D4: nop

    // 0x800363D8: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x800363DC: sw          $t4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r12;
    // 0x800363E0: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
L_800363E4:
    // 0x800363E4: jal         0x8006A794
    // 0x800363E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_4;
    // 0x800363E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800363EC: lw          $t5, 0x78($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X78);
    // 0x800363F0: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x800363F4: bne         $t5, $zero, L_80036514
    if (ctx->r13 != 0) {
        // 0x800363F8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80036514;
    }
    // 0x800363F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800363FC: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80036400: lwc1        $f11, 0x65C0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X65C0);
    // 0x80036404: lwc1        $f10, 0x65C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65C4);
    // 0x80036408: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8003640C: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80036410: nop

    // 0x80036414: bc1f        L_80036514
    if (!c1cs) {
        // 0x80036418: nop
    
            goto L_80036514;
    }
    // 0x80036418: nop

    // 0x8003641C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x80036420: slti        $at, $v1, -0x1FFF
    ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
    // 0x80036424: bne         $t6, $zero, L_80036514
    if (ctx->r14 != 0) {
        // 0x80036428: nop
    
            goto L_80036514;
    }
    // 0x80036428: nop

    // 0x8003642C: bne         $at, $zero, L_80036514
    if (ctx->r1 != 0) {
        // 0x80036430: slti        $at, $v1, 0x2000
        ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
            goto L_80036514;
    }
    // 0x80036430: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x80036434: beq         $at, $zero, L_80036514
    if (ctx->r1 == 0) {
        // 0x80036438: nop
    
            goto L_80036514;
    }
    // 0x80036438: nop

    // 0x8003643C: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x80036440: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80036444: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x80036448: andi        $t1, $v0, 0x2000
    ctx->r9 = ctx->r2 & 0X2000;
    // 0x8003644C: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x80036450: beq         $t8, $zero, L_80036468
    if (ctx->r24 == 0) {
        // 0x80036454: nop
    
            goto L_80036468;
    }
    // 0x80036454: nop

    // 0x80036458: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8003645C: nop

    // 0x80036460: beq         $t9, $t0, L_80036470
    if (ctx->r25 == ctx->r8) {
        // 0x80036464: andi        $t2, $v0, 0x2000
        ctx->r10 = ctx->r2 & 0X2000;
            goto L_80036470;
    }
    // 0x80036464: andi        $t2, $v0, 0x2000
    ctx->r10 = ctx->r2 & 0X2000;
L_80036468:
    // 0x80036468: beq         $t1, $zero, L_80036514
    if (ctx->r9 == 0) {
        // 0x8003646C: andi        $t2, $v0, 0x2000
        ctx->r10 = ctx->r2 & 0X2000;
            goto L_80036514;
    }
    // 0x8003646C: andi        $t2, $v0, 0x2000
    ctx->r10 = ctx->r2 & 0X2000;
L_80036470:
    // 0x80036470: beq         $t2, $zero, L_8003648C
    if (ctx->r10 == 0) {
        // 0x80036474: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8003648C;
    }
    // 0x80036474: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80036478: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8003647C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80036480: jal         0x80056970
    // 0x80036484: nop

    play_char_horn_sound(rdram, ctx);
        goto after_5;
    // 0x80036484: nop

    after_5:
    // 0x80036488: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8003648C:
    // 0x8003648C: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    // 0x80036490: addiu       $t4, $s1, 0x12
    ctx->r12 = ADD32(ctx->r17, 0X12);
    // 0x80036494: addiu       $t5, $s1, 0x13
    ctx->r13 = ADD32(ctx->r17, 0X13);
    // 0x80036498: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8003649C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800364A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800364A4: addiu       $a1, $s1, 0x20
    ctx->r5 = ADD32(ctx->r17, 0X20);
    // 0x800364A8: addiu       $a2, $s1, 0x22
    ctx->r6 = ADD32(ctx->r17, 0X22);
    // 0x800364AC: jal         0x80030790
    // 0x800364B0: addiu       $a3, $s1, 0x11
    ctx->r7 = ADD32(ctx->r17, 0X11);
    get_fog_settings(rdram, ctx);
        goto after_6;
    // 0x800364B0: addiu       $a3, $s1, 0x11
    ctx->r7 = ADD32(ctx->r17, 0X11);
    after_6:
    // 0x800364B4: addiu       $t6, $zero, 0x384
    ctx->r14 = ADD32(0, 0X384);
    // 0x800364B8: addiu       $t7, $zero, 0x3E6
    ctx->r15 = ADD32(0, 0X3E6);
    // 0x800364BC: addiu       $t8, $zero, 0xF0
    ctx->r24 = ADD32(0, 0XF0);
    // 0x800364C0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800364C4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800364C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800364CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800364D0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800364D4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800364D8: jal         0x80030E20
    // 0x800364DC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    slowly_change_fog(rdram, ctx);
        goto after_7;
    // 0x800364DC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_7:
    // 0x800364E0: jal         0x800012E8
    // 0x800364E4: nop

    music_channel_reset_all(rdram, ctx);
        goto after_8;
    // 0x800364E4: nop

    after_8:
    // 0x800364E8: jal         0x80000B34
    // 0x800364EC: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    music_play(rdram, ctx);
        goto after_9;
    // 0x800364EC: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_9:
    // 0x800364F0: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800364F4: nop

    // 0x800364F8: beq         $t9, $zero, L_80036514
    if (ctx->r25 == 0) {
        // 0x800364FC: nop
    
            goto L_80036514;
    }
    // 0x800364FC: nop

    // 0x80036500: jal         0x80006AC8
    // 0x80036504: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    racer_sound_free(rdram, ctx);
        goto after_10;
    // 0x80036504: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_10:
    // 0x80036508: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8003650C: nop

    // 0x80036510: sw          $zero, 0x118($t0)
    MEM_W(0X118, ctx->r8) = 0;
L_80036514:
    // 0x80036514: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x80036518: nop

    // 0x8003651C: beq         $v0, $zero, L_80036540
    if (ctx->r2 == 0) {
        // 0x80036520: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80036540;
    }
    // 0x80036520: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80036524: jal         0x8005A41C
    // 0x80036528: nop

    disable_racer_input(rdram, ctx);
        goto after_11;
    // 0x80036528: nop

    after_11:
    // 0x8003652C: jal         0x800AB6F0
    // 0x80036530: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    minimap_fade(rdram, ctx);
        goto after_12;
    // 0x80036530: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_12:
    // 0x80036534: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x80036538: nop

    // 0x8003653C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_80036540:
    // 0x80036540: bne         $at, $zero, L_80036558
    if (ctx->r1 != 0) {
        // 0x80036544: nop
    
            goto L_80036558;
    }
    // 0x80036544: nop

    // 0x80036548: jal         0x8009D530
    // 0x8003654C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    npc_dialogue_loop(rdram, ctx);
        goto after_13;
    // 0x8003654C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
    // 0x80036550: b           L_80036564
    // 0x80036554: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80036564;
    // 0x80036554: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80036558:
    // 0x80036558: jal         0x8009D4AC
    // 0x8003655C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    dialogue_npc_finish(rdram, ctx);
        goto after_14;
    // 0x8003655C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_14:
    // 0x80036560: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80036564:
    // 0x80036564: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x80036568: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003656C: beq         $v0, $at, L_80036598
    if (ctx->r2 == ctx->r1) {
        // 0x80036570: addiu       $t1, $zero, 0xFF
        ctx->r9 = ADD32(0, 0XFF);
            goto L_80036598;
    }
    // 0x80036570: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80036574: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80036578: beq         $v0, $at, L_8003675C
    if (ctx->r2 == ctx->r1) {
        // 0x8003657C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8003675C;
    }
    // 0x8003657C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80036580: beq         $v0, $at, L_80036894
    if (ctx->r2 == ctx->r1) {
        // 0x80036584: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80036894;
    }
    // 0x80036584: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80036588: beq         $v0, $at, L_800369EC
    if (ctx->r2 == ctx->r1) {
        // 0x8003658C: nop
    
            goto L_800369EC;
    }
    // 0x8003658C: nop

    // 0x80036590: b           L_80036A30
    // 0x80036594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80036A30;
    // 0x80036594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80036598:
    // 0x80036598: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x8003659C: sb          $t1, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r9;
    // 0x800365A0: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800365A4: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x800365A8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800365AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800365B0: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x800365B4: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x800365B8: nop

    // 0x800365BC: bc1f        L_800365E0
    if (!c1cs) {
        // 0x800365C0: lui         $at, 0x4024
        ctx->r1 = S32(0X4024 << 16);
            goto L_800365E0;
    }
    // 0x800365C0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800365C4: swc1        $f1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x800365C8: jal         0x8005A42C
    // 0x800365CC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_15;
    // 0x800365CC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_15:
    // 0x800365D0: lwc1        $f1, 0x38($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800365D4: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800365D8: nop

    // 0x800365DC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
L_800365E0:
    // 0x800365E0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800365E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800365E8: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800365EC: c.lt.d      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.d < ctx->f0.d;
    // 0x800365F0: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800365F4: bc1f        L_80036710
    if (!c1cs) {
        // 0x800365F8: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_80036710;
    }
    // 0x800365F8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800365FC: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80036600: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80036604: jal         0x80070990
    // 0x80036608: div.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    arctan2_f(rdram, ctx);
        goto after_16;
    // 0x80036608: div.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    after_16:
    // 0x8003660C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80036610: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80036614: andi        $t2, $a0, 0xFFFF
    ctx->r10 = ctx->r4 & 0XFFFF;
    // 0x80036618: subu        $v1, $v0, $t2
    ctx->r3 = SUB32(ctx->r2, ctx->r10);
    // 0x8003661C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80036620: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80036624: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80036628: bne         $at, $zero, L_80036638
    if (ctx->r1 != 0) {
        // 0x8003662C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80036638;
    }
    // 0x8003662C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80036630: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80036634: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80036638:
    // 0x80036638: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8003663C: beq         $at, $zero, L_80036648
    if (ctx->r1 == 0) {
        // 0x80036640: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80036648;
    }
    // 0x80036640: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80036644: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80036648:
    // 0x80036648: blez        $v1, L_8003665C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8003664C: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_8003665C;
    }
    // 0x8003664C: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80036650: beq         $at, $zero, L_80036660
    if (ctx->r1 == 0) {
        // 0x80036654: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_80036660;
    }
    // 0x80036654: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80036658: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_8003665C:
    // 0x8003665C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
L_80036660:
    // 0x80036660: sra         $t3, $v1, 4
    ctx->r11 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80036664: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80036668: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8003666C: slti        $at, $v1, 0x801
    ctx->r1 = SIGNED(ctx->r3) < 0X801 ? 1 : 0;
    // 0x80036670: beq         $at, $zero, L_80036680
    if (ctx->r1 == 0) {
        // 0x80036674: sh          $t4, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r12;
            goto L_80036680;
    }
    // 0x80036674: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x80036678: slti        $at, $v1, -0x800
    ctx->r1 = SIGNED(ctx->r3) < -0X800 ? 1 : 0;
    // 0x8003667C: beq         $at, $zero, L_8003668C
    if (ctx->r1 == 0) {
        // 0x80036680: lui         $at, 0xBF00
        ctx->r1 = S32(0XBF00 << 16);
            goto L_8003668C;
    }
L_80036680:
    // 0x80036680: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x80036684: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80036688: nop

L_8003668C:
    // 0x8003668C: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80036690: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80036694: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80036698: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003669C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800366A0: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x800366A4: mul.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x800366A8: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800366AC: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x800366B0: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x800366B4: swc1        $f18, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f18.u32l;
    // 0x800366B8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800366BC: jal         0x80070A04
    // 0x800366C0: nop

    sins_f(rdram, ctx);
        goto after_17;
    // 0x800366C0: nop

    after_17:
    // 0x800366C4: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800366C8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800366CC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800366D0: jal         0x80070A38
    // 0x800366D4: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    coss_f(rdram, ctx);
        goto after_18;
    // 0x800366D4: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    after_18:
    // 0x800366D8: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800366DC: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800366E0: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800366E4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800366E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800366EC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x800366F0: lwc1        $f18, 0x14($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800366F4: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800366F8: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800366FC: nop

    // 0x80036700: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80036704: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80036708: b           L_8003671C
    // 0x8003670C: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
        goto L_8003671C;
    // 0x8003670C: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
L_80036710:
    // 0x80036710: sw          $t5, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r13;
    // 0x80036714: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80036718: nop

L_8003671C:
    // 0x8003671C: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80036720: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80036724: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80036728: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003672C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80036730: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80036734: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80036738: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8003673C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80036740: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80036744: jal         0x80011570
    // 0x80036748: nop

    move_object(rdram, ctx);
        goto after_19;
    // 0x80036748: nop

    after_19:
    // 0x8003674C: jal         0x8006F5C8
    // 0x80036750: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_pause_lockout_timer(rdram, ctx);
        goto after_20;
    // 0x80036750: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_20:
    // 0x80036754: b           L_80036AF4
    // 0x80036758: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
        goto L_80036AF4;
    // 0x80036758: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
L_8003675C:
    // 0x8003675C: jal         0x8005A42C
    // 0x80036760: nop

    racer_set_dialogue_camera(rdram, ctx);
        goto after_21;
    // 0x80036760: nop

    after_21:
    // 0x80036764: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80036768: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x8003676C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80036770: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80036774: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80036778: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8003677C: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x80036780: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036784: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80036788: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8003678C: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x80036790: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80036794: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x80036798: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8003679C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800367A0: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800367A4: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x800367A8: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x800367AC: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x800367B0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800367B4: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800367B8: bne         $at, $zero, L_800367C8
    if (ctx->r1 != 0) {
        // 0x800367BC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800367C8;
    }
    // 0x800367BC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800367C0: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800367C4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800367C8:
    // 0x800367C8: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800367CC: beq         $at, $zero, L_800367D8
    if (ctx->r1 == 0) {
        // 0x800367D0: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800367D8;
    }
    // 0x800367D0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800367D4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800367D8:
    // 0x800367D8: blez        $v1, L_800367EC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800367DC: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_800367EC;
    }
    // 0x800367DC: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x800367E0: beq         $at, $zero, L_800367EC
    if (ctx->r1 == 0) {
        // 0x800367E4: nop
    
            goto L_800367EC;
    }
    // 0x800367E4: nop

    // 0x800367E8: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_800367EC:
    // 0x800367EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800367F0: sra         $t9, $v1, 4
    ctx->r25 = S32(SIGNED(ctx->r3) >> 4);
    // 0x800367F4: lwc1        $f1, 0x65C8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X65C8);
    // 0x800367F8: lwc1        $f0, 0x65CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X65CC);
    // 0x800367FC: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80036800: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x80036804: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80036808: slti        $at, $v1, 0x500
    ctx->r1 = SIGNED(ctx->r3) < 0X500 ? 1 : 0;
    // 0x8003680C: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80036810: mul.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80036814: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80036818: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x8003681C: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80036820: nop

    // 0x80036824: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x80036828: mul.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8003682C: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80036830: beq         $at, $zero, L_8003685C
    if (ctx->r1 == 0) {
        // 0x80036834: swc1        $f6, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
            goto L_8003685C;
    }
    // 0x80036834: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x80036838: slti        $at, $v1, -0x4FF
    ctx->r1 = SIGNED(ctx->r3) < -0X4FF ? 1 : 0;
    // 0x8003683C: bne         $at, $zero, L_8003685C
    if (ctx->r1 != 0) {
        // 0x80036840: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_8003685C;
    }
    // 0x80036840: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80036844: sw          $t1, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r9;
    // 0x80036848: addiu       $a0, $zero, 0x141
    ctx->r4 = ADD32(0, 0X141);
    // 0x8003684C: jal         0x80036C0C
    // 0x80036850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_22;
    // 0x80036850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80036854: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80036858: nop

L_8003685C:
    // 0x8003685C: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80036860: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80036864: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80036868: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003686C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80036870: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80036874: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80036878: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8003687C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80036880: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80036884: jal         0x80011570
    // 0x80036888: nop

    move_object(rdram, ctx);
        goto after_23;
    // 0x80036888: nop

    after_23:
    // 0x8003688C: b           L_80036AF4
    // 0x80036890: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
        goto L_80036AF4;
    // 0x80036890: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
L_80036894:
    // 0x80036894: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80036898: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8003689C: lwc1        $f1, 0x65D0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X65D0);
    // 0x800368A0: lwc1        $f0, 0x65D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X65D4);
    // 0x800368A4: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x800368A8: mul.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x800368AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800368B0: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x800368B4: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x800368B8: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800368BC: sb          $t2, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r10;
    // 0x800368C0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800368C4: mul.d       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800368C8: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x800368CC: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x800368D0: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800368D4: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800368D8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800368DC: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x800368E0: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x800368E4: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x800368E8: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x800368EC: jal         0x8005A42C
    // 0x800368F0: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_24;
    // 0x800368F0: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    after_24:
    // 0x800368F4: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800368F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800368FC: bne         $v1, $at, L_800369A8
    if (ctx->r3 != ctx->r1) {
        // 0x80036900: addiu       $t3, $zero, 0x4
        ctx->r11 = ADD32(0, 0X4);
            goto L_800369A8;
    }
    // 0x80036900: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80036904: jal         0x8000E4C8
    // 0x80036908: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    is_time_trial_enabled(rdram, ctx);
        goto after_25;
    // 0x80036908: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    after_25:
    // 0x8003690C: beq         $v0, $zero, L_80036928
    if (ctx->r2 == 0) {
        // 0x80036910: addiu       $a0, $zero, 0x143
        ctx->r4 = ADD32(0, 0X143);
            goto L_80036928;
    }
    // 0x80036910: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    // 0x80036914: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    // 0x80036918: jal         0x80036C0C
    // 0x8003691C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_26;
    // 0x8003691C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80036920: b           L_80036934
    // 0x80036924: lh          $t4, 0x20($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X20);
        goto L_80036934;
    // 0x80036924: lh          $t4, 0x20($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X20);
L_80036928:
    // 0x80036928: jal         0x80036C0C
    // 0x8003692C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_27;
    // 0x8003692C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x80036930: lh          $t4, 0x20($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X20);
L_80036934:
    // 0x80036934: lbu         $a1, 0x11($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X11);
    // 0x80036938: lbu         $a2, 0x12($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X12);
    // 0x8003693C: lbu         $a3, 0x13($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X13);
    // 0x80036940: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80036944: lh          $t5, 0x22($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X22);
    // 0x80036948: addiu       $t6, $zero, 0xB4
    ctx->r14 = ADD32(0, 0XB4);
    // 0x8003694C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80036950: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036954: jal         0x80030E20
    // 0x80036958: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    slowly_change_fog(rdram, ctx);
        goto after_28;
    // 0x80036958: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_28:
    // 0x8003695C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80036960: nop

    // 0x80036964: lbu         $a0, 0x52($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X52);
    // 0x80036968: jal         0x80000B34
    // 0x8003696C: nop

    music_play(rdram, ctx);
        goto after_29;
    // 0x8003696C: nop

    after_29:
    // 0x80036970: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80036974: nop

    // 0x80036978: lhu         $a0, 0x54($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X54);
    // 0x8003697C: jal         0x80001074
    // 0x80036980: nop

    music_dynamic_set(rdram, ctx);
        goto after_30;
    // 0x80036980: nop

    after_30:
    // 0x80036984: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80036988: nop

    // 0x8003698C: lb          $a0, 0x3($t9)
    ctx->r4 = MEM_B(ctx->r25, 0X3);
    // 0x80036990: lb          $a1, 0x1D6($t9)
    ctx->r5 = MEM_B(ctx->r25, 0X1D6);
    // 0x80036994: jal         0x80004B40
    // 0x80036998: nop

    racer_sound_init(rdram, ctx);
        goto after_31;
    // 0x80036998: nop

    after_31:
    // 0x8003699C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800369A0: nop

    // 0x800369A4: sw          $v0, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->r2;
L_800369A8:
    // 0x800369A8: lwc1        $f0, 0x7C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800369AC: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800369B0: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800369B4: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800369B8: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800369BC: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
    // 0x800369C0: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
    // 0x800369C4: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800369C8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800369CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800369D0: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800369D4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800369D8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800369DC: jal         0x80011570
    // 0x800369E0: nop

    move_object(rdram, ctx);
        goto after_32;
    // 0x800369E0: nop

    after_32:
    // 0x800369E4: b           L_80036AF4
    // 0x800369E8: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
        goto L_80036AF4;
    // 0x800369E8: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
L_800369EC:
    // 0x800369EC: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800369F0: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800369F4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800369F8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800369FC: add.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f18.d + ctx->f6.d;
    // 0x80036A00: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x80036A04: jal         0x8005A42C
    // 0x80036A08: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_33;
    // 0x80036A08: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    after_33:
    // 0x80036A0C: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x80036A10: nop

    // 0x80036A14: slti        $at, $v0, 0x8C
    ctx->r1 = SIGNED(ctx->r2) < 0X8C ? 1 : 0;
    // 0x80036A18: beq         $at, $zero, L_80036AF0
    if (ctx->r1 == 0) {
        // 0x80036A1C: addiu       $t2, $v0, 0x3C
        ctx->r10 = ADD32(ctx->r2, 0X3C);
            goto L_80036AF0;
    }
    // 0x80036A1C: addiu       $t2, $v0, 0x3C
    ctx->r10 = ADD32(ctx->r2, 0X3C);
    // 0x80036A20: sw          $t2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r10;
    // 0x80036A24: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x80036A28: b           L_80036AF0
    // 0x80036A2C: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
        goto L_80036AF0;
    // 0x80036A2C: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
L_80036A30:
    // 0x80036A30: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x80036A34: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80036A38: lbu         $t3, 0xD($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XD);
    // 0x80036A3C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80036A40: bne         $t3, $at, L_80036AB0
    if (ctx->r11 != ctx->r1) {
        // 0x80036A44: swc1        $f8, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
            goto L_80036AB0;
    }
    // 0x80036A44: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    // 0x80036A48: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036A4C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80036A50: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80036A54: jal         0x8001C558
    // 0x80036A58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_34;
    // 0x80036A58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_34:
    // 0x80036A5C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80036A60: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80036A64: beq         $a0, $at, L_80036AF0
    if (ctx->r4 == ctx->r1) {
        // 0x80036A68: sb          $v0, 0xD($s1)
        MEM_B(0XD, ctx->r17) = ctx->r2;
            goto L_80036AF0;
    }
    // 0x80036A68: sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // 0x80036A6C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80036A70: jal         0x8001CC7C
    // 0x80036A74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_35;
    // 0x80036A74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_35:
    // 0x80036A78: lbu         $a1, 0xD($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XD);
    // 0x80036A7C: sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // 0x80036A80: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80036A84: jal         0x8001CC7C
    // 0x80036A88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_36;
    // 0x80036A88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_36:
    // 0x80036A8C: lbu         $a1, 0xE($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XE);
    // 0x80036A90: sb          $v0, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r2;
    // 0x80036A94: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80036A98: jal         0x8001CC7C
    // 0x80036A9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_37;
    // 0x80036A9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_37:
    // 0x80036AA0: lbu         $t4, 0xD($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0XD);
    // 0x80036AA4: sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // 0x80036AA8: b           L_80036AF0
    // 0x80036AAC: sb          $t4, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r12;
        goto L_80036AF0;
    // 0x80036AAC: sb          $t4, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r12;
L_80036AB0:
    // 0x80036AB0: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80036AB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80036AB8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80036ABC: jal         0x8001C6F8
    // 0x80036AC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001C6C4(rdram, ctx);
        goto after_38;
    // 0x80036AC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_38:
    // 0x80036AC4: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80036AC8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80036ACC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80036AD0: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80036AD4: mul.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x80036AD8: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036ADC: nop

    // 0x80036AE0: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80036AE4: add.d       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f8.d + ctx->f4.d;
    // 0x80036AE8: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80036AEC: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
L_80036AF0:
    // 0x80036AF0: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
L_80036AF4:
    // 0x80036AF4: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
    // 0x80036AF8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80036AFC: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80036B00: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x80036B04: jal         0x8002B134
    // 0x80036B08: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    func_8002B0F4(rdram, ctx);
        goto after_39;
    // 0x80036B08: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    after_39:
    // 0x80036B0C: beq         $v0, $zero, L_80036B88
    if (ctx->r2 == 0) {
        // 0x80036B10: addiu       $v1, $v0, -0x1
        ctx->r3 = ADD32(ctx->r2, -0X1);
            goto L_80036B88;
    }
    // 0x80036B10: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80036B14: bltz        $v1, L_80036B88
    if (SIGNED(ctx->r3) < 0) {
        // 0x80036B18: sll         $a0, $v1, 2
        ctx->r4 = S32(ctx->r3 << 2);
            goto L_80036B88;
    }
    // 0x80036B18: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x80036B1C: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80036B20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80036B24: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80036B28: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80036B2C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
L_80036B30:
    // 0x80036B30: nop

    // 0x80036B34: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x80036B38: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80036B3C: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80036B40: lb          $v1, 0x10($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X10);
    // 0x80036B44: nop

    // 0x80036B48: beq         $a1, $v1, L_80036B80
    if (ctx->r5 == ctx->r3) {
        // 0x80036B4C: nop
    
            goto L_80036B80;
    }
    // 0x80036B4C: nop

    // 0x80036B50: beq         $a2, $v1, L_80036B80
    if (ctx->r6 == ctx->r3) {
        // 0x80036B54: nop
    
            goto L_80036B80;
    }
    // 0x80036B54: nop

    // 0x80036B58: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80036B5C: nop

    // 0x80036B60: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80036B64: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80036B68: nop

    // 0x80036B6C: bc1f        L_80036B80
    if (!c1cs) {
        // 0x80036B70: nop
    
            goto L_80036B80;
    }
    // 0x80036B70: nop

    // 0x80036B74: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80036B78: nop

    // 0x80036B7C: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
L_80036B80:
    // 0x80036B80: bgez        $a0, L_80036B30
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80036B84: lw          $t5, 0x48($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X48);
            goto L_80036B30;
    }
    // 0x80036B84: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
L_80036B88:
    // 0x80036B88: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x80036B8C: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x80036B90: beq         $t7, $zero, L_80036BA4
    if (ctx->r15 == 0) {
        // 0x80036B94: sh          $zero, 0x4($s0)
        MEM_H(0X4, ctx->r16) = 0;
            goto L_80036BA4;
    }
    // 0x80036B94: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80036B98: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80036B9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80036BA0: swc1        $f6, -0x25B0($at)
    MEM_W(-0X25B0, ctx->r1) = ctx->f6.u32l;
L_80036BA4:
    // 0x80036BA4: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80036BAC: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80036BB0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80036BB4: nop

    // 0x80036BB8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80036BBC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80036BC0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80036BC4: nop

    // 0x80036BC8: cvt.w.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_D(ctx->f8.d);
    // 0x80036BCC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80036BD0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80036BD4: jal         0x80061E4C
    // 0x80036BD8: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
    func_80061C0C(rdram, ctx);
        goto after_40;
    // 0x80036BD8: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
    after_40:
    // 0x80036BDC: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x80036BE0: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80036BE4: blez        $v0, L_80036BF4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80036BE8: subu        $t1, $v0, $t0
        ctx->r9 = SUB32(ctx->r2, ctx->r8);
            goto L_80036BF4;
    }
    // 0x80036BE8: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
    // 0x80036BEC: b           L_80036BF8
    // 0x80036BF0: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
        goto L_80036BF8;
    // 0x80036BF0: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
L_80036BF4:
    // 0x80036BF4: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
L_80036BF8:
    // 0x80036BF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80036BFC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80036C00: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80036C04: jr          $ra
    // 0x80036C08: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80036C08: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void obj_init_collision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FD34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000FD38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FD3C: jal         0x80016BF8
    // 0x8000FD40: sw          $a1, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r5;
    func_80016BC4(rdram, ctx);
        goto after_0;
    // 0x8000FD40: sw          $a1, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r5;
    after_0:
    // 0x8000FD44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000FD48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000FD4C: jr          $ra
    // 0x8000FD50: addiu       $v0, $zero, 0x10C
    ctx->r2 = ADD32(0, 0X10C);
    return;
    // 0x8000FD50: addiu       $v0, $zero, 0x10C
    ctx->r2 = ADD32(0, 0X10C);
;}
RECOMP_FUNC void asset_table_load_addr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800770E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800770EC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800770F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800770F4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800770F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800770FC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80077100: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x80077104: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80077108: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8007710C: jal         0x800C9110
    // 0x80077110: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80077110: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80077114: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80077118: lw          $t0, 0x4830($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4830);
    // 0x8007711C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80077120: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80077124: lui         $t9, 0xF
    ctx->r25 = S32(0XF << 16);
    // 0x80077128: sltu        $at, $t6, $a3
    ctx->r1 = ctx->r14 < ctx->r7 ? 1 : 0;
    // 0x8007712C: beq         $at, $zero, L_8007713C
    if (ctx->r1 == 0) {
        // 0x80077130: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_8007713C;
    }
    // 0x80077130: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80077134: b           L_80077180
    // 0x80077138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80077180;
    // 0x80077138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007713C:
    // 0x8007713C: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80077140: addu        $v0, $t7, $t0
    ctx->r2 = ADD32(ctx->r15, ctx->r8);
    // 0x80077144: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80077148: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8007714C: addiu       $t9, $t9, -0x2E50
    ctx->r25 = ADD32(ctx->r25, -0X2E50);
    // 0x80077150: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80077154: subu        $a2, $t8, $v1
    ctx->r6 = SUB32(ctx->r24, ctx->r3);
    // 0x80077158: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007715C: jal         0x800773D4
    // 0x80077160: addu        $a0, $v1, $t9
    ctx->r4 = ADD32(ctx->r3, ctx->r25);
    dmacopy_v1(rdram, ctx);
        goto after_1;
    // 0x80077160: addu        $a0, $v1, $t9
    ctx->r4 = ADD32(ctx->r3, ctx->r25);
    after_1:
    // 0x80077164: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077168: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x8007716C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80077170: jal         0x800C9390
    // 0x80077174: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80077174: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80077178: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8007717C: nop

L_80077180:
    // 0x80077180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077184: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80077188: jr          $ra
    // 0x8007718C: nop

    return;
    // 0x8007718C: nop

;}
RECOMP_FUNC void func_800732E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073540: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80073544: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80073548: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8007354C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80073550: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80073554: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80073558: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007355C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80073560: jal         0x8006B464
    // 0x80073564: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    level_count(rdram, ctx);
        goto after_0;
    // 0x80073564: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x80073568: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8007356C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073570: sw          $t6, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r14;
    // 0x80073574: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073578: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x8007357C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073580: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80073584: sw          $t7, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = ctx->r15;
    // 0x80073588: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8007358C: jal         0x80073080
    // 0x80073590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80072E28(rdram, ctx);
        goto after_1;
    // 0x80073590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80073594: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80073598: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007359C: blez        $t8, L_80073634
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800735A0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80073634;
    }
    // 0x800735A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800735A4:
    // 0x800735A4: jal         0x8006B38C
    // 0x800735A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_type(rdram, ctx);
        goto after_2;
    // 0x800735A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800735AC: beq         $v0, $zero, L_800735C4
    if (ctx->r2 == 0) {
        // 0x800735B0: andi        $t9, $v0, 0x40
        ctx->r25 = ctx->r2 & 0X40;
            goto L_800735C4;
    }
    // 0x800735B0: andi        $t9, $v0, 0x40
    ctx->r25 = ctx->r2 & 0X40;
    // 0x800735B4: bne         $t9, $zero, L_800735C4
    if (ctx->r25 != 0) {
        // 0x800735B8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800735C4;
    }
    // 0x800735B8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800735BC: bne         $v0, $at, L_80073620
    if (ctx->r2 != ctx->r1) {
        // 0x800735C0: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_80073620;
    }
    // 0x800735C0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_800735C4:
    // 0x800735C4: lw          $t0, 0x4($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X4);
    // 0x800735C8: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x800735CC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800735D0: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800735D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800735D8: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x800735DC: beq         $t3, $zero, L_800735E8
    if (ctx->r11 == 0) {
        // 0x800735E0: andi        $t4, $v0, 0x2
        ctx->r12 = ctx->r2 & 0X2;
            goto L_800735E8;
    }
    // 0x800735E0: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    // 0x800735E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800735E8:
    // 0x800735E8: beq         $t4, $zero, L_800735FC
    if (ctx->r12 == 0) {
        // 0x800735EC: andi        $t6, $v0, 0x4
        ctx->r14 = ctx->r2 & 0X4;
            goto L_800735FC;
    }
    // 0x800735EC: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x800735F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800735F4: andi        $t5, $a1, 0xFF
    ctx->r13 = ctx->r5 & 0XFF;
    // 0x800735F8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
L_800735FC:
    // 0x800735FC: beq         $t6, $zero, L_80073610
    if (ctx->r14 == 0) {
        // 0x80073600: nop
    
            goto L_80073610;
    }
    // 0x80073600: nop

    // 0x80073604: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80073608: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8007360C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_80073610:
    // 0x80073610: jal         0x80073080
    // 0x80073614: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80072E28(rdram, ctx);
        goto after_3;
    // 0x80073614: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80073618: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8007361C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_80073620:
    // 0x80073620: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073624: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80073628: bne         $at, $zero, L_800735A4
    if (ctx->r1 != 0) {
        // 0x8007362C: nop
    
            goto L_800735A4;
    }
    // 0x8007362C: nop

    // 0x80073630: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80073634:
    // 0x80073634: addiu       $t9, $zero, 0x44
    ctx->r25 = ADD32(0, 0X44);
    // 0x80073638: subu        $a0, $t9, $s0
    ctx->r4 = SUB32(ctx->r25, ctx->r16);
    // 0x8007363C: jal         0x80073080
    // 0x80073640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80072E28(rdram, ctx);
        goto after_4;
    // 0x80073640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80073644: lhu         $a1, 0x14($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X14);
    // 0x80073648: jal         0x80073080
    // 0x8007364C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80072E28(rdram, ctx);
        goto after_5;
    // 0x8007364C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_5:
    // 0x80073650: lhu         $a1, 0xE($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0XE);
    // 0x80073654: jal         0x80073080
    // 0x80073658: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_80072E28(rdram, ctx);
        goto after_6;
    // 0x80073658: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_6:
    // 0x8007365C: lhu         $a1, 0xC($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0XC);
    // 0x80073660: jal         0x80073080
    // 0x80073664: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80072E28(rdram, ctx);
        goto after_7;
    // 0x80073664: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_7:
    // 0x80073668: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8007366C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80073670: blez        $t0, L_800736A8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80073674: nop
    
            goto L_800736A8;
    }
    // 0x80073674: nop

L_80073678:
    // 0x80073678: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8007367C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80073680: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80073684: lh          $a1, 0x0($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X0);
    // 0x80073688: jal         0x80073080
    // 0x8007368C: nop

    func_80072E28(rdram, ctx);
        goto after_8;
    // 0x8007368C: nop

    after_8:
    // 0x80073690: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80073694: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073698: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007369C: bne         $at, $zero, L_80073678
    if (ctx->r1 != 0) {
        // 0x800736A0: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80073678;
    }
    // 0x800736A0: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800736A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800736A8:
    // 0x800736A8: lbu         $a1, 0x16($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X16);
    // 0x800736AC: jal         0x80073080
    // 0x800736B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80072E28(rdram, ctx);
        goto after_9;
    // 0x800736B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_9:
    // 0x800736B4: lbu         $a1, 0x17($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X17);
    // 0x800736B8: jal         0x80073080
    // 0x800736BC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80072E28(rdram, ctx);
        goto after_10;
    // 0x800736BC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_10:
    // 0x800736C0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800736C4: nop

    // 0x800736C8: blez        $t4, L_8007370C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800736CC: nop
    
            goto L_8007370C;
    }
    // 0x800736CC: nop

L_800736D0:
    // 0x800736D0: jal         0x8006B414
    // 0x800736D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    level_world_id(rdram, ctx);
        goto after_11;
    // 0x800736D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x800736D8: lw          $t5, 0x4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X4);
    // 0x800736DC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800736E0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800736E4: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x800736E8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800736EC: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800736F0: jal         0x80073080
    // 0x800736F4: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    func_80072E28(rdram, ctx);
        goto after_12;
    // 0x800736F4: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    after_12:
    // 0x800736F8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800736FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073700: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80073704: bne         $at, $zero, L_800736D0
    if (ctx->r1 != 0) {
        // 0x80073708: nop
    
            goto L_800736D0;
    }
    // 0x80073708: nop

L_8007370C:
    // 0x8007370C: lhu         $a1, 0x8($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X8);
    // 0x80073710: jal         0x80073080
    // 0x80073714: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_80072E28(rdram, ctx);
        goto after_13;
    // 0x80073714: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_13:
    // 0x80073718: lw          $a1, 0x10($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X10);
    // 0x8007371C: jal         0x80073080
    // 0x80073720: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80072E28(rdram, ctx);
        goto after_14;
    // 0x80073720: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_14:
    // 0x80073724: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    // 0x80073728: jal         0x80073080
    // 0x8007372C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_15;
    // 0x8007372C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_15:
    // 0x80073730: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80073734: jal         0x80073080
    // 0x80073738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80072E28(rdram, ctx);
        goto after_16;
    // 0x80073738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x8007373C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80073740: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80073744: addiu       $a0, $a2, 0x2
    ctx->r4 = ADD32(ctx->r6, 0X2);
    // 0x80073748: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8007374C: lbu         $t3, 0x1($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X1);
    // 0x80073750: addiu       $t2, $v0, 0x5
    ctx->r10 = ADD32(ctx->r2, 0X5);
    // 0x80073754: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80073758: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x8007375C: sra         $v0, $t4, 16
    ctx->r2 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80073760: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80073764: addiu       $v1, $a2, 0x4
    ctx->r3 = ADD32(ctx->r6, 0X4);
L_80073768:
    // 0x80073768: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8007376C: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x80073770: lbu         $t2, 0x2($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X2);
    // 0x80073774: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x80073778: lbu         $t5, 0x3($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X3);
    // 0x8007377C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80073780: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x80073784: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80073788: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8007378C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80073790: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80073794: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073798: bne         $s1, $a0, L_80073768
    if (ctx->r17 != ctx->r4) {
        // 0x8007379C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80073768;
    }
    // 0x8007379C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800737A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800737A4: sw          $a2, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r6;
    // 0x800737A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800737AC: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x800737B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800737B4: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800737B8: sw          $t8, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = ctx->r24;
    // 0x800737BC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800737C0: jal         0x80073080
    // 0x800737C4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_80072E28(rdram, ctx);
        goto after_17;
    // 0x800737C4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_17:
    // 0x800737C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800737CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800737D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800737D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800737D8: jr          $ra
    // 0x800737DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800737DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void debug_text_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B63E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B63EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B63F0: jal         0x8007B2C4
    // 0x800B63F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    load_texture(rdram, ctx);
        goto after_0;
    // 0x800B63F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800B63F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B63FC: sw          $v0, -0x7DA0($at)
    MEM_W(-0X7DA0, ctx->r1) = ctx->r2;
    // 0x800B6400: jal         0x8007B2C4
    // 0x800B6404: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    load_texture(rdram, ctx);
        goto after_1;
    // 0x800B6404: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800B6408: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B640C: sw          $v0, -0x7D9C($at)
    MEM_W(-0X7D9C, ctx->r1) = ctx->r2;
    // 0x800B6410: jal         0x8007B2C4
    // 0x800B6414: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_texture(rdram, ctx);
        goto after_2;
    // 0x800B6414: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x800B6418: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B641C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B6420: sw          $v0, -0x7D98($at)
    MEM_W(-0X7D98, ctx->r1) = ctx->r2;
    // 0x800B6424: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B6428: addiu       $t6, $t6, -0x7D68
    ctx->r14 = ADD32(ctx->r14, -0X7D68);
    // 0x800B642C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B6430: sw          $t6, -0x7468($at)
    MEM_W(-0X7468, ctx->r1) = ctx->r14;
    // 0x800B6434: jr          $ra
    // 0x800B6438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B6438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
