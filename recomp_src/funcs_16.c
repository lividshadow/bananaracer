#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void get_cached_texture_by_slot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B7D0: bltz        $a0, L_8007B7EC
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007B7D4: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8007B7EC;
    }
    // 0x8007B7D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007B7D8: lw          $t6, 0x68D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68D0);
    // 0x8007B7DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007B7E0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007B7E4: bne         $at, $zero, L_8007B7F4
    if (ctx->r1 != 0) {
        // 0x8007B7E8: nop
    
            goto L_8007B7F4;
    }
    // 0x8007B7E8: nop

L_8007B7EC:
    // 0x8007B7EC: jr          $ra
    // 0x8007B7F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8007B7F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B7F4:
    // 0x8007B7F4: lw          $t7, 0x68C8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X68C8);
    // 0x8007B7F8: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8007B7FC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007B800: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x8007B804: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007B808: bne         $v1, $at, L_8007B818
    if (ctx->r3 != ctx->r1) {
        // 0x8007B80C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8007B818;
    }
    // 0x8007B80C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007B810: jr          $ra
    // 0x8007B814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8007B814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B818:
    // 0x8007B818: jr          $ra
    // 0x8007B81C: nop

    return;
    // 0x8007B81C: nop

;}
RECOMP_FUNC void byteswap32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C670C: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x800C6710: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800C6714: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x800C6718: lbu         $t0, 0x3($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X3);
    // 0x800C671C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800C6720: or          $v1, $v1, $t7
    ctx->r3 = ctx->r3 | ctx->r15;
    // 0x800C6724: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C6728: or          $v1, $v1, $t9
    ctx->r3 = ctx->r3 | ctx->r25;
    // 0x800C672C: sll         $t1, $t0, 24
    ctx->r9 = S32(ctx->r8 << 24);
    // 0x800C6730: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800C6734: jr          $ra
    // 0x800C6738: or          $v0, $v1, $t1
    ctx->r2 = ctx->r3 | ctx->r9;
    return;
    // 0x800C6738: or          $v0, $v1, $t1
    ctx->r2 = ctx->r3 | ctx->r9;
;}
RECOMP_FUNC void alSeqpNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A710: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000A714: jr          $ra
    // 0x8000A718: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8000A718: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void update_car_velocity_ground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005496C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80054970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80054974: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80054978: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8005497C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80054980: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80054984: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054988: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005498C: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x80054990: mul.s       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80054994: swc1        $f18, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->f18.u32l;
    // 0x80054998: bc1f        L_800549A4
    if (!c1cs) {
        // 0x8005499C: swc1        $f18, 0x88($a1)
        MEM_W(0X88, ctx->r5) = ctx->f18.u32l;
            goto L_800549A4;
    }
    // 0x8005499C: swc1        $f18, 0x88($a1)
    MEM_W(0X88, ctx->r5) = ctx->f18.u32l;
    // 0x800549A0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_800549A4:
    // 0x800549A4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800549A8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800549AC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800549B0: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x800549B4: jal         0x80057260
    // 0x800549B8: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    handle_racer_top_speed(rdram, ctx);
        goto after_0;
    // 0x800549B8: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x800549BC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800549C0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800549C4: lh          $v0, 0x1A2($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X1A2);
    // 0x800549C8: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800549CC: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800549D0: slti        $at, $v0, 0x1C01
    ctx->r1 = SIGNED(ctx->r2) < 0X1C01 ? 1 : 0;
    // 0x800549D4: beq         $at, $zero, L_800549E4
    if (ctx->r1 == 0) {
        // 0x800549D8: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800549E4;
    }
    // 0x800549D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800549DC: slti        $at, $v0, -0x1C00
    ctx->r1 = SIGNED(ctx->r2) < -0X1C00 ? 1 : 0;
    // 0x800549E0: beq         $at, $zero, L_800549EC
    if (ctx->r1 == 0) {
        // 0x800549E4: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800549EC;
    }
L_800549E4:
    // 0x800549E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800549E8: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
L_800549EC:
    // 0x800549EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800549F0: lw          $v0, -0x2558($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2558);
    // 0x800549F4: lw          $a0, -0x254C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X254C);
    // 0x800549F8: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
    // 0x800549FC: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80054A00: beq         $t7, $zero, L_80054A0C
    if (ctx->r15 == 0) {
        // 0x80054A04: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80054A0C;
    }
    // 0x80054A04: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80054A08: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
L_80054A0C:
    // 0x80054A0C: beq         $v0, $zero, L_80054A28
    if (ctx->r2 == 0) {
        // 0x80054A10: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80054A28;
    }
    // 0x80054A10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054A14: lb          $t8, 0x1E6($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X1E6);
    // 0x80054A18: nop

    // 0x80054A1C: beq         $t8, $zero, L_80054A28
    if (ctx->r24 == 0) {
        // 0x80054A20: nop
    
            goto L_80054A28;
    }
    // 0x80054A20: nop

    // 0x80054A24: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
L_80054A28:
    // 0x80054A28: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054A2C: lwc1        $f7, 0x6D78($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6D78);
    // 0x80054A30: lwc1        $f6, 0x6D7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6D7C);
    // 0x80054A34: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80054A38: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x80054A3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80054A40: bc1f        L_80054A58
    if (!c1cs) {
        // 0x80054A44: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80054A58;
    }
    // 0x80054A44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054A48: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054A4C: mflo        $v0
    ctx->r2 = lo;
    // 0x80054A50: nop

    // 0x80054A54: nop

L_80054A58:
    // 0x80054A58: lwc1        $f9, 0x6D80($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6D80);
    // 0x80054A5C: lwc1        $f8, 0x6D84($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6D84);
    // 0x80054A60: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80054A64: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x80054A68: nop

    // 0x80054A6C: bc1f        L_80054A84
    if (!c1cs) {
        // 0x80054A70: negu        $t9, $a0
        ctx->r25 = SUB32(0, ctx->r4);
            goto L_80054A84;
    }
    // 0x80054A70: negu        $t9, $a0
    ctx->r25 = SUB32(0, ctx->r4);
    // 0x80054A74: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054A78: mflo        $v0
    ctx->r2 = lo;
    // 0x80054A7C: nop

    // 0x80054A80: nop

L_80054A84:
    // 0x80054A84: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054A88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80054A8C: lwc1        $f6, -0x2510($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2510);
    // 0x80054A90: lh          $t3, 0x1A0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X1A0);
    // 0x80054A94: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80054A98: mflo        $v0
    ctx->r2 = lo;
    // 0x80054A9C: sra         $t1, $v0, 1
    ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80054AA0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80054AA4: nop

    // 0x80054AA8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80054AAC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80054AB0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80054AB4: nop

    // 0x80054AB8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80054ABC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80054AC0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80054AC4: nop

    // 0x80054AC8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80054ACC: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80054AD0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80054AD4: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80054AD8: sh          $t5, 0x1A0($a1)
    MEM_H(0X1A0, ctx->r5) = ctx->r13;
    // 0x80054ADC: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80054AE0: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x80054AE4: jal         0x800534B8
    // 0x80054AE8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    handle_car_steering(rdram, ctx);
        goto after_1;
    // 0x80054AE8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80054AEC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80054AF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054AF4: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80054AF8: lwc1        $f9, 0x6D88($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6D88);
    // 0x80054AFC: lwc1        $f8, 0x6D8C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6D8C);
    // 0x80054B00: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80054B04: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80054B08: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80054B0C: lbu         $a0, 0x1DC($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X1DC);
    // 0x80054B10: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80054B14: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80054B18: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80054B1C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80054B20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80054B24: swc1        $f4, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f4.u32l;
    // 0x80054B28: beq         $a0, $at, L_80054B4C
    if (ctx->r4 == ctx->r1) {
        // 0x80054B2C: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_80054B4C;
    }
    // 0x80054B2C: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    // 0x80054B30: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80054B34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054B38: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80054B3C: lwc1        $f6, -0x2EF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2EF4);
    // 0x80054B40: blez        $a0, L_80054B4C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80054B44: add.s       $f0, $f18, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f6.fl;
            goto L_80054B4C;
    }
    // 0x80054B44: add.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80054B48: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80054B4C:
    // 0x80054B4C: lwc1        $f10, 0xC0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC0);
    // 0x80054B50: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80054B54: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80054B58: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80054B5C: c.eq.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d == ctx->f4.d;
    // 0x80054B60: nop

    // 0x80054B64: bc1t        L_80054B74
    if (c1cs) {
        // 0x80054B68: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80054B74;
    }
    // 0x80054B68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054B6C: lwc1        $f0, 0x6D90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6D90);
    // 0x80054B70: nop

L_80054B74:
    // 0x80054B74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80054B78: sb          $v1, -0x24FF($at)
    MEM_B(-0X24FF, ctx->r1) = ctx->r3;
    // 0x80054B7C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80054B80: sb          $zero, 0x1E6($a1)
    MEM_B(0X1E6, ctx->r5) = 0;
    // 0x80054B84: bne         $v1, $at, L_80054BA0
    if (ctx->r3 != ctx->r1) {
        // 0x80054B88: sw          $zero, 0x10C($a1)
        MEM_W(0X10C, ctx->r5) = 0;
            goto L_80054BA0;
    }
    // 0x80054B88: sw          $zero, 0x10C($a1)
    MEM_W(0X10C, ctx->r5) = 0;
    // 0x80054B8C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80054B90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80054B94: nop

    // 0x80054B98: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80054B9C: swc1        $f18, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f18.u32l;
L_80054BA0:
    // 0x80054BA0: lb          $t7, 0x1D3($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1D3);
    // 0x80054BA4: nop

    // 0x80054BA8: bne         $t7, $zero, L_80054BE8
    if (ctx->r15 != 0) {
        // 0x80054BAC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80054BE8;
    }
    // 0x80054BAC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80054BB0: bne         $v1, $at, L_80054BE8
    if (ctx->r3 != ctx->r1) {
        // 0x80054BB4: addiu       $a0, $zero, 0x2D
        ctx->r4 = ADD32(0, 0X2D);
            goto L_80054BE8;
    }
    // 0x80054BB4: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x80054BB8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80054BBC: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x80054BC0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80054BC4: jal         0x8000C8B4
    // 0x80054BC8: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    normalise_time(rdram, ctx);
        goto after_2;
    // 0x80054BC8: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80054BCC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80054BD0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80054BD4: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80054BD8: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80054BDC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80054BE0: sb          $v0, 0x1D3($a1)
    MEM_B(0X1D3, ctx->r5) = ctx->r2;
    // 0x80054BE4: sb          $t8, 0x203($a1)
    MEM_B(0X203, ctx->r5) = ctx->r24;
L_80054BE8:
    // 0x80054BE8: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80054BEC: lwc1        $f10, 0x2C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054BF0: nop

    // 0x80054BF4: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80054BF8: swc1        $f4, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f4.u32l;
    // 0x80054BFC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80054C00: nop

    // 0x80054C04: beq         $t9, $zero, L_80054C28
    if (ctx->r25 == 0) {
        // 0x80054C08: nop
    
            goto L_80054C28;
    }
    // 0x80054C08: nop

    // 0x80054C0C: lbu         $v0, 0x1EE($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1EE);
    // 0x80054C10: nop

    // 0x80054C14: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80054C18: beq         $at, $zero, L_80054C2C
    if (ctx->r1 == 0) {
        // 0x80054C1C: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_80054C2C;
    }
    // 0x80054C1C: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80054C20: b           L_80054C2C
    // 0x80054C24: sb          $t0, 0x1EE($a1)
    MEM_B(0X1EE, ctx->r5) = ctx->r8;
        goto L_80054C2C;
    // 0x80054C24: sb          $t0, 0x1EE($a1)
    MEM_B(0X1EE, ctx->r5) = ctx->r8;
L_80054C28:
    // 0x80054C28: sb          $zero, 0x1EE($a1)
    MEM_B(0X1EE, ctx->r5) = 0;
L_80054C2C:
    // 0x80054C2C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80054C30: jal         0x80066450
    // 0x80054C34: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    cam_get_viewport_layout(rdram, ctx);
        goto after_3;
    // 0x80054C34: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    after_3:
    // 0x80054C38: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80054C3C: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80054C40: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80054C44: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80054C48: beq         $at, $zero, L_80054CC8
    if (ctx->r1 == 0) {
        // 0x80054C4C: nop
    
            goto L_80054CC8;
    }
    // 0x80054C4C: nop

    // 0x80054C50: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80054C54: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80054C58: beq         $t1, $zero, L_80054CC8
    if (ctx->r9 == 0) {
        // 0x80054C5C: nop
    
            goto L_80054CC8;
    }
    // 0x80054C5C: nop

    // 0x80054C60: lwc1        $f6, 0x2C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054C64: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80054C68: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80054C6C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80054C70: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80054C74: nop

    // 0x80054C78: bc1f        L_80054CC8
    if (!c1cs) {
        // 0x80054C7C: nop
    
            goto L_80054CC8;
    }
    // 0x80054C7C: nop

    // 0x80054C80: lbu         $v0, 0x1DE($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1DE);
    // 0x80054C84: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80054C88: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80054C8C: beq         $at, $zero, L_80054CA4
    if (ctx->r1 == 0) {
        // 0x80054C90: sll         $t3, $v0, 1
        ctx->r11 = S32(ctx->r2 << 1);
            goto L_80054CA4;
    }
    // 0x80054C90: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x80054C94: lw          $t2, 0x74($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X74);
    // 0x80054C98: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x80054C9C: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x80054CA0: sw          $t6, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r14;
L_80054CA4:
    // 0x80054CA4: lbu         $v0, 0x1DF($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1DF);
    // 0x80054CA8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80054CAC: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80054CB0: beq         $at, $zero, L_80054CC8
    if (ctx->r1 == 0) {
        // 0x80054CB4: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_80054CC8;
    }
    // 0x80054CB4: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80054CB8: lw          $t7, 0x74($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X74);
    // 0x80054CBC: sllv        $t0, $t9, $t8
    ctx->r8 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x80054CC0: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x80054CC4: sw          $t1, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r9;
L_80054CC8:
    // 0x80054CC8: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054CCC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80054CD0: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x80054CD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80054CD8: bc1f        L_80054CE4
    if (!c1cs) {
        // 0x80054CDC: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_80054CE4;
    }
    // 0x80054CDC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80054CE0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_80054CE4:
    // 0x80054CE4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80054CE8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80054CEC: bc1f        L_80054CF8
    if (!c1cs) {
        // 0x80054CF0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80054CF8;
    }
    // 0x80054CF0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80054CF4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80054CF8:
    // 0x80054CF8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80054CFC: lw          $t3, -0x251C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X251C);
    // 0x80054D00: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80054D04: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80054D08: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80054D0C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80054D10: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80054D14: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80054D18: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80054D1C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80054D20: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80054D24: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80054D28: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80054D2C: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80054D30: addu        $v1, $t3, $t2
    ctx->r3 = ADD32(ctx->r11, ctx->r10);
    // 0x80054D34: sub.s       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80054D38: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80054D3C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80054D40: sub.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d - ctx->f4.d;
    // 0x80054D44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054D48: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80054D4C: mul.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x80054D50: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80054D54: lb          $t5, 0x1D3($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X1D3);
    // 0x80054D58: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80054D5C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80054D60: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x80054D64: lwc1        $f4, 0x6D9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6D9C);
    // 0x80054D68: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x80054D6C: lwc1        $f5, 0x6D98($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6D98);
    // 0x80054D70: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x80054D74: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80054D78: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80054D7C: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x80054D80: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80054D84: blez        $t5, L_80054DE0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80054D88: nop
    
            goto L_80054DE0;
    }
    // 0x80054D88: nop

    // 0x80054D8C: lw          $t6, -0x2540($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2540);
    // 0x80054D90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80054D94: bne         $t6, $zero, L_80054DD8
    if (ctx->r14 != 0) {
        // 0x80054D98: nop
    
            goto L_80054DD8;
    }
    // 0x80054D98: nop

    // 0x80054D9C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80054DA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80054DA4: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80054DA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80054DAC: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x80054DB0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80054DB4: bc1t        L_80054DC4
    if (c1cs) {
        // 0x80054DB8: swc1        $f8, 0xB4($a1)
        MEM_W(0XB4, ctx->r5) = ctx->f8.u32l;
            goto L_80054DC4;
    }
    // 0x80054DB8: swc1        $f8, 0xB4($a1)
    MEM_W(0XB4, ctx->r5) = ctx->f8.u32l;
    // 0x80054DBC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80054DC0: nop

L_80054DC4:
    // 0x80054DC4: lb          $t9, 0x1D3($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X1D3);
    // 0x80054DC8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80054DCC: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054DD0: subu        $t7, $t9, $t8
    ctx->r15 = SUB32(ctx->r25, ctx->r24);
    // 0x80054DD4: sb          $t7, 0x1D3($a1)
    MEM_B(0X1D3, ctx->r5) = ctx->r15;
L_80054DD8:
    // 0x80054DD8: b           L_80054DEC
    // 0x80054DDC: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
        goto L_80054DEC;
    // 0x80054DDC: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
L_80054DE0:
    // 0x80054DE0: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054DE4: sb          $zero, 0x1D3($a1)
    MEM_B(0X1D3, ctx->r5) = 0;
    // 0x80054DE8: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
L_80054DEC:
    // 0x80054DEC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80054DF0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80054DF4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80054DF8: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80054DFC: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x80054E00: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80054E04: bc1f        L_80054E80
    if (!c1cs) {
        // 0x80054E08: nop
    
            goto L_80054E80;
    }
    // 0x80054E08: nop

    // 0x80054E0C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80054E10: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80054E14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054E18: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x80054E1C: nop

    // 0x80054E20: bc1f        L_80054E80
    if (!c1cs) {
        // 0x80054E24: nop
    
            goto L_80054E80;
    }
    // 0x80054E24: nop

    // 0x80054E28: sub.d       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f16.d - ctx->f0.d;
    // 0x80054E2C: lwc1        $f5, 0x6DA0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6DA0);
    // 0x80054E30: lwc1        $f4, 0x6DA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6DA4);
    // 0x80054E34: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80054E38: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80054E3C: lw          $t0, -0x2548($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2548);
    // 0x80054E40: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80054E44: slti        $at, $t0, -0x19
    ctx->r1 = SIGNED(ctx->r8) < -0X19 ? 1 : 0;
    // 0x80054E48: beq         $at, $zero, L_80054E80
    if (ctx->r1 == 0) {
        // 0x80054E4C: cvt.s.d     $f14, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
            goto L_80054E80;
    }
    // 0x80054E4C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x80054E50: lw          $v0, -0x2558($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2558);
    // 0x80054E54: nop

    // 0x80054E58: andi        $t1, $v0, 0x8000
    ctx->r9 = ctx->r2 & 0X8000;
    // 0x80054E5C: bne         $t1, $zero, L_80054E80
    if (ctx->r9 != 0) {
        // 0x80054E60: andi        $t4, $v0, 0x4000
        ctx->r12 = ctx->r2 & 0X4000;
            goto L_80054E80;
    }
    // 0x80054E60: andi        $t4, $v0, 0x4000
    ctx->r12 = ctx->r2 & 0X4000;
    // 0x80054E64: beq         $t4, $zero, L_80054E80
    if (ctx->r12 == 0) {
        // 0x80054E68: nop
    
            goto L_80054E80;
    }
    // 0x80054E68: nop

    // 0x80054E6C: add.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80054E70: swc1        $f18, 0xB8($a1)
    MEM_W(0XB8, ctx->r5) = ctx->f18.u32l;
    // 0x80054E74: swc1        $f10, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f10.u32l;
    // 0x80054E78: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054E7C: nop

L_80054E80:
    // 0x80054E80: lwc1        $f8, 0xB8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XB8);
    // 0x80054E84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054E88: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80054E8C: lwc1        $f11, 0x6DA8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6DA8);
    // 0x80054E90: lwc1        $f10, 0x6DAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6DAC);
    // 0x80054E94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054E98: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80054E9C: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80054EA0: lwc1        $f4, 0xB4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XB4);
    // 0x80054EA4: nop

    // 0x80054EA8: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80054EAC: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x80054EB0: sub.s       $f10, $f12, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80054EB4: swc1        $f10, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f10.u32l;
    // 0x80054EB8: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054EBC: lwc1        $f8, 0x6DB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6DB4);
    // 0x80054EC0: lwc1        $f9, 0x6DB0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6DB0);
    // 0x80054EC4: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x80054EC8: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x80054ECC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054ED0: bc1f        L_80054F00
    if (!c1cs) {
        // 0x80054ED4: nop
    
            goto L_80054F00;
    }
    // 0x80054ED4: nop

    // 0x80054ED8: lwc1        $f5, 0x6DB8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6DB8);
    // 0x80054EDC: lwc1        $f4, 0x6DBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6DBC);
    // 0x80054EE0: nop

    // 0x80054EE4: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80054EE8: nop

    // 0x80054EEC: bc1f        L_80054F00
    if (!c1cs) {
        // 0x80054EF0: nop
    
            goto L_80054F00;
    }
    // 0x80054EF0: nop

    // 0x80054EF4: swc1        $f18, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f18.u32l;
    // 0x80054EF8: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054EFC: nop

L_80054F00:
    // 0x80054F00: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x80054F04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80054F08: bc1f        L_80054F38
    if (!c1cs) {
        // 0x80054F0C: nop
    
            goto L_80054F38;
    }
    // 0x80054F0C: nop

    // 0x80054F10: add.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80054F14: swc1        $f6, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f6.u32l;
    // 0x80054F18: lwc1        $f10, 0x2C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054F1C: nop

    // 0x80054F20: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80054F24: nop

    // 0x80054F28: bc1f        L_80054F5C
    if (!c1cs) {
        // 0x80054F2C: nop
    
            goto L_80054F5C;
    }
    // 0x80054F2C: nop

    // 0x80054F30: b           L_80054F5C
    // 0x80054F34: swc1        $f18, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f18.u32l;
        goto L_80054F5C;
    // 0x80054F34: swc1        $f18, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f18.u32l;
L_80054F38:
    // 0x80054F38: sub.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x80054F3C: swc1        $f8, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f8.u32l;
    // 0x80054F40: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054F44: nop

    // 0x80054F48: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80054F4C: nop

    // 0x80054F50: bc1f        L_80054F5C
    if (!c1cs) {
        // 0x80054F54: nop
    
            goto L_80054F5C;
    }
    // 0x80054F54: nop

    // 0x80054F58: swc1        $f18, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f18.u32l;
L_80054F5C:
    // 0x80054F5C: lwc1        $f10, 0xC0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC0);
    // 0x80054F60: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80054F64: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80054F68: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80054F6C: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x80054F70: lwc1        $f0, -0x2514($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2514);
    // 0x80054F74: bc1t        L_80054F90
    if (c1cs) {
        // 0x80054F78: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_80054F90;
    }
    // 0x80054F78: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80054F7C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80054F80: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80054F84: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80054F88: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80054F8C: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_80054F90:
    // 0x80054F90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054F94: lwc1        $f8, 0xB8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XB8);
    // 0x80054F98: lwc1        $f11, 0x6DC0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6DC0);
    // 0x80054F9C: lwc1        $f10, 0x6DC4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6DC4);
    // 0x80054FA0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80054FA4: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x80054FA8: nop

    // 0x80054FAC: bc1f        L_80054FEC
    if (!c1cs) {
        // 0x80054FB0: nop
    
            goto L_80054FEC;
    }
    // 0x80054FB0: nop

    // 0x80054FB4: lw          $t3, -0x2540($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2540);
    // 0x80054FB8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80054FBC: bne         $t3, $zero, L_80054FEC
    if (ctx->r11 != 0) {
        // 0x80054FC0: nop
    
            goto L_80054FEC;
    }
    // 0x80054FC0: nop

    // 0x80054FC4: lwc1        $f6, 0x9C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X9C);
    // 0x80054FC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80054FCC: nop

    // 0x80054FD0: div.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80054FD4: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80054FD8: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80054FDC: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054FE0: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80054FE4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80054FE8: swc1        $f10, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f10.u32l;
L_80054FEC:
    // 0x80054FEC: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80054FF0: lwc1        $f6, 0x20($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80054FF4: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80054FF8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80054FFC: swc1        $f10, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f10.u32l;
    // 0x80055000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80055004: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80055008: jr          $ra
    // 0x8005500C: nop

    return;
    // 0x8005500C: nop

;}
RECOMP_FUNC void rumble_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800724E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800724E8: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800724EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800724F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800724F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800724F8: beq         $t6, $zero, L_8007251C
    if (ctx->r14 == 0) {
        // 0x800724FC: sb          $t6, 0x4764($at)
        MEM_B(0X4764, ctx->r1) = ctx->r14;
            goto L_8007251C;
    }
    // 0x800724FC: sb          $t6, 0x4764($at)
    MEM_B(0X4764, ctx->r1) = ctx->r14;
    // 0x80072500: addiu       $t7, $zero, 0x79
    ctx->r15 = ADD32(0, 0X79);
    // 0x80072504: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80072508: sw          $t7, 0x4768($at)
    MEM_W(0X4768, ctx->r1) = ctx->r15;
    // 0x8007250C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80072510: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80072514: b           L_80072524
    // 0x80072518: sb          $t8, 0x4766($at)
    MEM_B(0X4766, ctx->r1) = ctx->r24;
        goto L_80072524;
    // 0x80072518: sb          $t8, 0x4766($at)
    MEM_B(0X4766, ctx->r1) = ctx->r24;
L_8007251C:
    // 0x8007251C: jal         0x80072954
    // 0x80072520: nop

    rumble_kill(rdram, ctx);
        goto after_0;
    // 0x80072520: nop

    after_0:
L_80072524:
    // 0x80072524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007252C: jr          $ra
    // 0x80072530: nop

    return;
    // 0x80072530: nop

;}
RECOMP_FUNC void hud_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F230: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009F234: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009F238: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009F23C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009F240: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009F244: jal         0x80066450
    // 0x8009F248: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8009F248: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009F24C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F250: addiu       $v1, $v1, 0x72CC
    ctx->r3 = ADD32(ctx->r3, 0X72CC);
    // 0x8009F254: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8009F258: jal         0x8006676C
    // 0x8009F25C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    cam_set_layout(rdram, ctx);
        goto after_1;
    // 0x8009F25C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8009F260: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F264: jal         0x8006ECD0
    // 0x8009F268: sb          $v0, 0x72F7($at)
    MEM_B(0X72F7, ctx->r1) = ctx->r2;
    get_settings(rdram, ctx);
        goto after_2;
    // 0x8009F268: sb          $v0, 0x72F7($at)
    MEM_B(0X72F7, ctx->r1) = ctx->r2;
    after_2:
    // 0x8009F26C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F270: jal         0x8000E1DC
    // 0x8009F274: sw          $v0, 0x7744($at)
    MEM_W(0X7744, ctx->r1) = ctx->r2;
    check_if_silver_coin_race(rdram, ctx);
        goto after_3;
    // 0x8009F274: sw          $v0, 0x7744($at)
    MEM_W(0X7744, ctx->r1) = ctx->r2;
    after_3:
    // 0x8009F278: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F27C: sb          $v0, 0x7748($at)
    MEM_B(0X7748, ctx->r1) = ctx->r2;
    // 0x8009F280: jal         0x80076EE4
    // 0x8009F284: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    asset_table_load(rdram, ctx);
        goto after_4;
    // 0x8009F284: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_4:
    // 0x8009F288: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009F28C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8009F290: addiu       $s1, $s1, 0x72B0
    ctx->r17 = ADD32(ctx->r17, 0X72B0);
    // 0x8009F294: addiu       $a2, $a2, 0x72B8
    ctx->r6 = ADD32(ctx->r6, 0X72B8);
    // 0x8009F298: sll         $t6, $zero, 1
    ctx->r14 = S32(0 << 1);
    // 0x8009F29C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8009F2A0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8009F2A4: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8009F2A8: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8009F2AC: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8009F2B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8009F2B4: beq         $s2, $t8, L_8009F2DC
    if (ctx->r18 == ctx->r24) {
        // 0x8009F2B8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8009F2DC;
    }
    // 0x8009F2B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009F2BC: addiu       $t9, $s0, 0x1
    ctx->r25 = ADD32(ctx->r16, 0X1);
L_8009F2C0:
    // 0x8009F2C0: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8009F2C4: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x8009F2C8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8009F2CC: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8009F2D0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x8009F2D4: bne         $s2, $t2, L_8009F2C0
    if (ctx->r18 != ctx->r10) {
        // 0x8009F2D8: addiu       $t9, $s0, 0x1
        ctx->r25 = ADD32(ctx->r16, 0X1);
            goto L_8009F2C0;
    }
    // 0x8009F2D8: addiu       $t9, $s0, 0x1
    ctx->r25 = ADD32(ctx->r16, 0X1);
L_8009F2DC:
    // 0x8009F2DC: sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16 << 2);
    // 0x8009F2E0: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x8009F2E4: jal         0x80070EDC
    // 0x8009F2E8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x8009F2E8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_5:
    // 0x8009F2EC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009F2F0: addiu       $a2, $a2, 0x72B8
    ctx->r6 = ADD32(ctx->r6, 0X72B8);
    // 0x8009F2F4: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x8009F2F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009F2FC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009F300: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x8009F304: addiu       $a3, $a3, 0x72B4
    ctx->r7 = ADD32(ctx->r7, 0X72B4);
    // 0x8009F308: addiu       $a0, $a0, 0x7298
    ctx->r4 = ADD32(ctx->r4, 0X7298);
    // 0x8009F30C: addu        $t5, $t3, $v0
    ctx->r13 = ADD32(ctx->r11, ctx->r2);
    // 0x8009F310: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8009F314: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8009F318: blez        $s0, L_8009F358
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8009F31C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8009F358;
    }
    // 0x8009F31C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009F320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009F324:
    // 0x8009F324: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8009F328: nop

    // 0x8009F32C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8009F330: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8009F334: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8009F338: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009F33C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8009F340: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8009F344: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x8009F348: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8009F34C: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8009F350: bne         $at, $zero, L_8009F324
    if (ctx->r1 != 0) {
        // 0x8009F354: nop
    
            goto L_8009F324;
    }
    // 0x8009F354: nop

L_8009F358:
    // 0x8009F358: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8009F35C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009F360: lh          $a0, 0x2($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X2);
    // 0x8009F364: nop

    // 0x8009F368: andi        $t2, $a0, 0x3FFF
    ctx->r10 = ctx->r4 & 0X3FFF;
    // 0x8009F36C: jal         0x8007C57C
    // 0x8009F370: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_6;
    // 0x8009F370: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_6:
    // 0x8009F374: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009F378: addiu       $a3, $a3, 0x72B4
    ctx->r7 = ADD32(ctx->r7, 0X72B4);
    // 0x8009F37C: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x8009F380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009F384: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x8009F388: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8009F38C: nop

    // 0x8009F390: lh          $a0, 0x2E($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X2E);
    // 0x8009F394: nop

    // 0x8009F398: andi        $t5, $a0, 0x3FFF
    ctx->r13 = ctx->r4 & 0X3FFF;
    // 0x8009F39C: jal         0x8007C57C
    // 0x8009F3A0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_7;
    // 0x8009F3A0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_7:
    // 0x8009F3A4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009F3A8: addiu       $a3, $a3, 0x72B4
    ctx->r7 = ADD32(ctx->r7, 0X72B4);
    // 0x8009F3AC: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8009F3B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009F3B4: sw          $v0, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->r2;
    // 0x8009F3B8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009F3BC: nop

    // 0x8009F3C0: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    // 0x8009F3C4: nop

    // 0x8009F3C8: andi        $t8, $a0, 0x3FFF
    ctx->r24 = ctx->r4 & 0X3FFF;
    // 0x8009F3CC: jal         0x8007C57C
    // 0x8009F3D0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_8;
    // 0x8009F3D0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_8:
    // 0x8009F3D4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009F3D8: addiu       $a3, $a3, 0x72B4
    ctx->r7 = ADD32(ctx->r7, 0X72B4);
    // 0x8009F3DC: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x8009F3E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009F3E4: sw          $v0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->r2;
    // 0x8009F3E8: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8009F3EC: nop

    // 0x8009F3F0: lh          $a0, 0x22($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X22);
    // 0x8009F3F4: nop

    // 0x8009F3F8: andi        $t1, $a0, 0x3FFF
    ctx->r9 = ctx->r4 & 0X3FFF;
    // 0x8009F3FC: jal         0x8007C57C
    // 0x8009F400: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_9;
    // 0x8009F400: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_9:
    // 0x8009F404: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009F408: addiu       $a3, $a3, 0x72B4
    ctx->r7 = ADD32(ctx->r7, 0X72B4);
    // 0x8009F40C: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x8009F410: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F414: sw          $v0, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->r2;
    // 0x8009F418: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x8009F41C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009F420: beq         $v1, $at, L_8009F430
    if (ctx->r3 == ctx->r1) {
        // 0x8009F424: ori         $a1, $zero, 0xFFFF
        ctx->r5 = 0 | 0XFFFF;
            goto L_8009F430;
    }
    // 0x8009F424: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8009F428: b           L_8009F434
    // 0x8009F42C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8009F434;
    // 0x8009F42C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8009F430:
    // 0x8009F430: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8009F434:
    // 0x8009F434: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x8009F438: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8009F43C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8009F440: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8009F444: jal         0x80070EDC
    // 0x8009F448: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    mempool_alloc_safe(rdram, ctx);
        goto after_10;
    // 0x8009F448: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    after_10:
    // 0x8009F44C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F450: addiu       $v1, $v1, 0x72A0
    ctx->r3 = ADD32(ctx->r3, 0X72A0);
    // 0x8009F454: addiu       $t4, $v0, 0x760
    ctx->r12 = ADD32(ctx->r2, 0X760);
    // 0x8009F458: addiu       $t6, $t4, 0x760
    ctx->r14 = ADD32(ctx->r12, 0X760);
    // 0x8009F45C: addiu       $t8, $t6, 0x760
    ctx->r24 = ADD32(ctx->r14, 0X760);
    // 0x8009F460: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8009F464: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8009F468: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x8009F46C: jal         0x8009F574
    // 0x8009F470: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    hud_init_element(rdram, ctx);
        goto after_11;
    // 0x8009F470: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    after_11:
    // 0x8009F474: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F478: sb          $zero, 0x7324($at)
    MEM_B(0X7324, ctx->r1) = 0;
    // 0x8009F47C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F480: sw          $zero, 0x732C($at)
    MEM_W(0X732C, ctx->r1) = 0;
    // 0x8009F484: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F488: sh          $zero, 0x7308($at)
    MEM_H(0X7308, ctx->r1) = 0;
    // 0x8009F48C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8009F490: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F494: sb          $v0, 0x7326($at)
    MEM_B(0X7326, ctx->r1) = ctx->r2;
    // 0x8009F498: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F49C: sb          $zero, 0x7325($at)
    MEM_B(0X7325, ctx->r1) = 0;
    // 0x8009F4A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4A4: sb          $v0, 0x7327($at)
    MEM_B(0X7327, ctx->r1) = ctx->r2;
    // 0x8009F4A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009F4B0: sb          $t9, 0x7329($at)
    MEM_B(0X7329, ctx->r1) = ctx->r25;
    // 0x8009F4B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8009F4BC: sb          $t0, 0x7328($at)
    MEM_B(0X7328, ctx->r1) = ctx->r8;
    // 0x8009F4C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4C4: sb          $zero, 0x7330($at)
    MEM_B(0X7330, ctx->r1) = 0;
    // 0x8009F4C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4CC: sh          $zero, 0x733C($at)
    MEM_H(0X733C, ctx->r1) = 0;
    // 0x8009F4D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4D4: sw          $zero, 0x7334($at)
    MEM_W(0X7334, ctx->r1) = 0;
    // 0x8009F4D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4DC: sw          $zero, 0x72FC($at)
    MEM_W(0X72FC, ctx->r1) = 0;
    // 0x8009F4E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4E4: sw          $zero, 0x7304($at)
    MEM_W(0X7304, ctx->r1) = 0;
    // 0x8009F4E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4EC: sb          $zero, 0x7293($at)
    MEM_B(0X7293, ctx->r1) = 0;
    // 0x8009F4F0: jal         0x8001E2D0
    // 0x8009F4F4: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    get_misc_asset(rdram, ctx);
        goto after_12;
    // 0x8009F4F4: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_12:
    // 0x8009F4F8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F4FC: addiu       $v1, $v1, 0x7754
    ctx->r3 = ADD32(ctx->r3, 0X7754);
    // 0x8009F500: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8009F504: jal         0x8007F638
    // 0x8009F508: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8007F1E8(rdram, ctx);
        goto after_13;
    // 0x8009F508: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x8009F50C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009F510: jal         0x80004A60
    // 0x8009F514: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_14;
    // 0x8009F514: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_14:
    // 0x8009F518: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8009F51C: jal         0x80004A60
    // 0x8009F520: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_15;
    // 0x8009F520: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_15:
    // 0x8009F524: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009F528: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8009F52C: addiu       $s1, $s1, 0x2D10
    ctx->r17 = ADD32(ctx->r17, 0X2D10);
    // 0x8009F530: addiu       $s0, $s0, 0x2CF0
    ctx->r16 = ADD32(ctx->r16, 0X2CF0);
L_8009F534:
    // 0x8009F534: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8009F538: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x8009F53C: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x8009F540: beq         $a0, $zero, L_8009F550
    if (ctx->r4 == 0) {
        // 0x8009F544: sb          $s2, 0xC($s0)
        MEM_B(0XC, ctx->r16) = ctx->r18;
            goto L_8009F550;
    }
    // 0x8009F544: sb          $s2, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r18;
    // 0x8009F548: jal         0x8000488C
    // 0x8009F54C: nop

    sndp_stop(rdram, ctx);
        goto after_16;
    // 0x8009F54C: nop

    after_16:
L_8009F550:
    // 0x8009F550: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8009F554: bne         $s0, $s1, L_8009F534
    if (ctx->r16 != ctx->r17) {
        // 0x8009F558: nop
    
            goto L_8009F534;
    }
    // 0x8009F558: nop

    // 0x8009F55C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009F560: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009F564: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009F568: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009F56C: jr          $ra
    // 0x8009F570: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009F570: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void audspat_jingle_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008148: jal         0x800018E0
    // 0x8000814C: nop

    music_jingle_stop(rdram, ctx);
        goto after_0;
    // 0x8000814C: nop

    after_0:
    // 0x80008150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008154: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80008158: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000815C: sb          $t6, -0x4E68($at)
    MEM_B(-0X4E68, ctx->r1) = ctx->r14;
    // 0x80008160: jr          $ra
    // 0x80008164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80008164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void normalise_time(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C8B4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8000C8B8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8000C8BC: nop

    // 0x8000C8C0: bne         $t6, $zero, L_8000C8D0
    if (ctx->r14 != 0) {
        // 0x8000C8C4: nop
    
            goto L_8000C8D0;
    }
    // 0x8000C8C4: nop

    // 0x8000C8C8: bgez        $a0, L_8000C8D8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8000C8CC: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_8000C8D8;
    }
    // 0x8000C8CC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
L_8000C8D0:
    // 0x8000C8D0: jr          $ra
    // 0x8000C8D4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8000C8D4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8000C8D8:
    // 0x8000C8D8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000C8DC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8000C8E0: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8000C8E4: mflo        $v0
    ctx->r2 = lo;
    // 0x8000C8E8: nop

    // 0x8000C8EC: nop

    // 0x8000C8F0: jr          $ra
    // 0x8000C8F4: nop

    return;
    // 0x8000C8F4: nop

;}
RECOMP_FUNC void set_temp_model_transforms(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012F94: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80012F98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80012F9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80012FA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80012FA4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80012FA8: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80012FAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80012FB0: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80012FB4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80012FB8: bne         $t7, $zero, L_8001346C
    if (ctx->r15 != 0) {
        // 0x80012FBC: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_8001346C;
    }
    // 0x80012FBC: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x80012FC0: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x80012FC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012FC8: lb          $t9, 0x54($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X54);
    // 0x80012FCC: nop

    // 0x80012FD0: bne         $t9, $at, L_8001344C
    if (ctx->r25 != ctx->r1) {
        // 0x80012FD4: nop
    
            goto L_8001344C;
    }
    // 0x80012FD4: nop

    // 0x80012FD8: lw          $t2, 0x64($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X64);
    // 0x80012FDC: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x80012FE0: lh          $v0, 0x206($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X206);
    // 0x80012FE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80012FE8: blez        $v0, L_80013024
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80012FEC: sb          $t3, 0x201($t2)
        MEM_B(0X201, ctx->r10) = ctx->r11;
            goto L_80013024;
    }
    // 0x80012FEC: sb          $t3, 0x201($t2)
    MEM_B(0X201, ctx->r10) = ctx->r11;
    // 0x80012FF0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80012FF4: lwc1        $f0, 0x5AE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5AE4);
    // 0x80012FF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80012FFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013000: lwc1        $f8, 0x5AE8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5AE8);
    // 0x80013004: nop

    // 0x80013008: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001300C: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80013010: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80013014: nop

    // 0x80013018: bc1f        L_80013024
    if (!c1cs) {
        // 0x8001301C: nop
    
            goto L_80013024;
    }
    // 0x8001301C: nop

    // 0x80013020: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80013024:
    // 0x80013024: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x80013028: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001302C: beq         $t4, $at, L_8001304C
    if (ctx->r12 == ctx->r1) {
        // 0x80013030: nop
    
            goto L_8001304C;
    }
    // 0x80013030: nop

    // 0x80013034: lb          $t5, 0x1D8($t2)
    ctx->r13 = MEM_B(ctx->r10, 0X1D8);
    // 0x80013038: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001303C: beq         $t5, $zero, L_8001304C
    if (ctx->r13 == 0) {
        // 0x80013040: nop
    
            goto L_8001304C;
    }
    // 0x80013040: nop

    // 0x80013044: b           L_80013274
    // 0x80013048: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_80013274;
    // 0x80013048: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8001304C:
    // 0x8001304C: lh          $t6, 0x48($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X48);
    // 0x80013050: addiu       $at, $zero, 0x3A
    ctx->r1 = ADD32(0, 0X3A);
    // 0x80013054: bne         $t6, $at, L_80013064
    if (ctx->r14 != ctx->r1) {
        // 0x80013058: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80013064;
    }
    // 0x80013058: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001305C: b           L_80013274
    // 0x80013060: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_80013274;
    // 0x80013060: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80013064:
    // 0x80013064: lb          $t1, 0x1D6($t2)
    ctx->r9 = MEM_B(ctx->r10, 0X1D6);
    // 0x80013068: nop

    // 0x8001306C: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x80013070: bne         $at, $zero, L_80013080
    if (ctx->r1 != 0) {
        // 0x80013074: addiu       $a0, $t1, 0x5
        ctx->r4 = ADD32(ctx->r9, 0X5);
            goto L_80013080;
    }
    // 0x80013074: addiu       $a0, $t1, 0x5
    ctx->r4 = ADD32(ctx->r9, 0X5);
    // 0x80013078: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8001307C: addiu       $a0, $t1, 0x5
    ctx->r4 = ADD32(ctx->r9, 0X5);
L_80013080:
    // 0x80013080: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80013084: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80013088: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8001308C: jal         0x8001E2D0
    // 0x80013090: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80013090: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80013094: jal         0x80066450
    // 0x80013098: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    cam_get_viewport_layout(rdram, ctx);
        goto after_1;
    // 0x80013098: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001309C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800130A0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800130A4: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x800130A8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800130AC: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x800130B0: jal         0x80066460
    // 0x800130B4: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    get_current_viewport(rdram, ctx);
        goto after_2;
    // 0x800130B4: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_2:
    // 0x800130B8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800130BC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800130C0: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x800130C4: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800130C8: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800130CC: beq         $v0, $t8, L_800130D8
    if (ctx->r2 == ctx->r24) {
        // 0x800130D0: nop
    
            goto L_800130D8;
    }
    // 0x800130D0: nop

    // 0x800130D4: addiu       $a1, $a1, 0x5
    ctx->r5 = ADD32(ctx->r5, 0X5);
L_800130D8:
    // 0x800130D8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800130DC: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800130E0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800130E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800130E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800130EC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800130F0: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800130F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800130F8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800130FC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80013100: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80013104: sra         $t3, $v1, 3
    ctx->r11 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80013108: bc1f        L_80013118
    if (!c1cs) {
        // 0x8001310C: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80013118;
    }
    // 0x8001310C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80013110: b           L_80013134
    // 0x80013114: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80013134;
    // 0x80013114: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80013118:
    // 0x80013118: lwc1        $f2, 0x5AEC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AEC);
    // 0x8001311C: nop

    // 0x80013120: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80013124: nop

    // 0x80013128: bc1f        L_80013134
    if (!c1cs) {
        // 0x8001312C: nop
    
            goto L_80013134;
    }
    // 0x8001312C: nop

    // 0x80013130: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80013134:
    // 0x80013134: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013138: lwc1        $f18, 0x5AF0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5AF0);
    // 0x8001313C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80013140: div.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80013144: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80013148: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001314C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80013150: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80013154: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80013158: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8001315C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x80013160: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80013164: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80013168: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8001316C: jal         0x8001E2D0
    // 0x80013170: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    get_misc_asset(rdram, ctx);
        goto after_3;
    // 0x80013170: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_3:
    // 0x80013174: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80013178: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8001317C: lb          $t4, 0x3($t2)
    ctx->r12 = MEM_B(ctx->r10, 0X3);
    // 0x80013180: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x80013184: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80013188: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001318C: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80013190: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80013194: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80013198: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8001319C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800131A0: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800131A4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800131A8: nop

    // 0x800131AC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800131B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800131B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800131B8: nop

    // 0x800131BC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800131C0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800131C4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800131C8: slti        $at, $v1, -0x32
    ctx->r1 = SIGNED(ctx->r3) < -0X32 ? 1 : 0;
    // 0x800131CC: beq         $at, $zero, L_800131DC
    if (ctx->r1 == 0) {
        // 0x800131D0: sra         $t8, $v1, 1
        ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
            goto L_800131DC;
    }
    // 0x800131D0: sra         $t8, $v1, 1
    ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800131D4: b           L_80013274
    // 0x800131D8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
        goto L_80013274;
    // 0x800131D8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
L_800131DC:
    // 0x800131DC: bgez        $t8, L_800131E8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800131E0: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800131E8;
    }
    // 0x800131E0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800131E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800131E8:
    // 0x800131E8: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800131EC: nop

    // 0x800131F0: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800131F4: beq         $at, $zero, L_80013204
    if (ctx->r1 == 0) {
        // 0x800131F8: nop
    
            goto L_80013204;
    }
    // 0x800131F8: nop

    // 0x800131FC: b           L_80013274
    // 0x80013200: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_80013274;
    // 0x80013200: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80013204:
    // 0x80013204: lbu         $t3, 0x1($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X1);
    // 0x80013208: nop

    // 0x8001320C: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80013210: beq         $at, $zero, L_80013220
    if (ctx->r1 == 0) {
        // 0x80013214: nop
    
            goto L_80013220;
    }
    // 0x80013214: nop

    // 0x80013218: b           L_80013274
    // 0x8001321C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80013274;
    // 0x8001321C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013220:
    // 0x80013220: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x80013224: nop

    // 0x80013228: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001322C: beq         $at, $zero, L_8001323C
    if (ctx->r1 == 0) {
        // 0x80013230: nop
    
            goto L_8001323C;
    }
    // 0x80013230: nop

    // 0x80013234: b           L_80013274
    // 0x80013238: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
        goto L_80013274;
    // 0x80013238: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_8001323C:
    // 0x8001323C: lbu         $t5, 0x3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X3);
    // 0x80013240: nop

    // 0x80013244: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80013248: beq         $at, $zero, L_80013258
    if (ctx->r1 == 0) {
        // 0x8001324C: nop
    
            goto L_80013258;
    }
    // 0x8001324C: nop

    // 0x80013250: b           L_80013274
    // 0x80013254: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
        goto L_80013274;
    // 0x80013254: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
L_80013258:
    // 0x80013258: lbu         $t6, 0x4($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X4);
    // 0x8001325C: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80013260: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80013264: beq         $at, $zero, L_80013274
    if (ctx->r1 == 0) {
        // 0x80013268: nop
    
            goto L_80013274;
    }
    // 0x80013268: nop

    // 0x8001326C: b           L_80013274
    // 0x80013270: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
        goto L_80013274;
    // 0x80013270: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
L_80013274:
    // 0x80013274: lw          $a1, 0x68($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X68);
    // 0x80013278: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001327C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80013280: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80013284: bne         $t7, $zero, L_8001329C
    if (ctx->r15 != 0) {
        // 0x80013288: nop
    
            goto L_8001329C;
    }
    // 0x80013288: nop

L_8001328C:
    // 0x8001328C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80013290: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80013294: beq         $t8, $zero, L_8001328C
    if (ctx->r24 == 0) {
        // 0x80013298: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8001328C;
    }
    // 0x80013298: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8001329C:
    // 0x8001329C: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x800132A0: slt         $at, $t0, $a0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800132A4: lb          $v1, 0x55($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X55);
    // 0x800132A8: nop

    // 0x800132AC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800132B0: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800132B4: addu        $v0, $a1, $t3
    ctx->r2 = ADD32(ctx->r5, ctx->r11);
    // 0x800132B8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800132BC: nop

    // 0x800132C0: bne         $t4, $zero, L_800132D8
    if (ctx->r12 != 0) {
        // 0x800132C4: nop
    
            goto L_800132D8;
    }
    // 0x800132C4: nop

L_800132C8:
    // 0x800132C8: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800132CC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800132D0: beq         $t5, $zero, L_800132C8
    if (ctx->r13 == 0) {
        // 0x800132D4: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800132C8;
    }
    // 0x800132D4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_800132D8:
    // 0x800132D8: beq         $at, $zero, L_800132E4
    if (ctx->r1 == 0) {
        // 0x800132DC: lui         $a3, 0x81
        ctx->r7 = S32(0X81 << 16);
            goto L_800132E4;
    }
    // 0x800132DC: lui         $a3, 0x81
    ctx->r7 = S32(0X81 << 16);
    // 0x800132E0: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_800132E4:
    // 0x800132E4: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800132E8: beq         $at, $zero, L_800132F4
    if (ctx->r1 == 0) {
        // 0x800132EC: lui         $a2, 0x1
        ctx->r6 = S32(0X1 << 16);
            goto L_800132F4;
    }
    // 0x800132EC: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x800132F0: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_800132F4:
    // 0x800132F4: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x800132F8: sb          $t0, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r8;
    // 0x800132FC: beq         $v0, $zero, L_80013334
    if (ctx->r2 == 0) {
        // 0x80013300: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80013334;
    }
    // 0x80013300: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013304: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80013308: lwc1        $f10, 0x5AF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5AF4);
    // 0x8001330C: nop

    // 0x80013310: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80013314: nop

    // 0x80013318: bc1f        L_80013334
    if (!c1cs) {
        // 0x8001331C: nop
    
            goto L_80013334;
    }
    // 0x8001331C: nop

    // 0x80013320: lbu         $t6, 0x20A($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X20A);
    // 0x80013324: nop

    // 0x80013328: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x8001332C: b           L_80013344
    // 0x80013330: sb          $t7, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r15;
        goto L_80013344;
    // 0x80013330: sb          $t7, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r15;
L_80013334:
    // 0x80013334: lbu         $t8, 0x20A($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X20A);
    // 0x80013338: nop

    // 0x8001333C: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x80013340: sb          $t9, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r25;
L_80013344:
    // 0x80013344: lb          $t4, 0x3A($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X3A);
    // 0x80013348: lw          $t3, 0x68($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X68);
    // 0x8001334C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80013350: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80013354: lbu         $v0, 0x20A($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X20A);
    // 0x80013358: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8001335C: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x80013360: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80013364: beq         $t0, $zero, L_800133BC
    if (ctx->r8 == 0) {
        // 0x80013368: andi        $t7, $v0, 0x80
        ctx->r15 = ctx->r2 & 0X80;
            goto L_800133BC;
    }
    // 0x80013368: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x8001336C: beq         $t7, $zero, L_80013388
    if (ctx->r15 == 0) {
        // 0x80013370: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80013388;
    }
    // 0x80013370: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80013374: andi        $t8, $v0, 0xFFEF
    ctx->r24 = ctx->r2 & 0XFFEF;
    // 0x80013378: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x8001337C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80013380: b           L_800133BC
    // 0x80013384: sb          $t9, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r25;
        goto L_800133BC;
    // 0x80013384: sb          $t9, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r25;
L_80013388:
    // 0x80013388: andi        $t4, $v0, 0x40
    ctx->r12 = ctx->r2 & 0X40;
    // 0x8001338C: beq         $t4, $zero, L_800133A8
    if (ctx->r12 == 0) {
        // 0x80013390: andi        $t6, $v0, 0x20
        ctx->r14 = ctx->r2 & 0X20;
            goto L_800133A8;
    }
    // 0x80013390: andi        $t6, $v0, 0x20
    ctx->r14 = ctx->r2 & 0X20;
    // 0x80013394: andi        $t3, $v0, 0xFFDF
    ctx->r11 = ctx->r2 & 0XFFDF;
    // 0x80013398: ori         $t5, $t3, 0x10
    ctx->r13 = ctx->r11 | 0X10;
    // 0x8001339C: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x800133A0: b           L_800133BC
    // 0x800133A4: sb          $t5, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r13;
        goto L_800133BC;
    // 0x800133A4: sb          $t5, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r13;
L_800133A8:
    // 0x800133A8: beq         $t6, $zero, L_800133B8
    if (ctx->r14 == 0) {
        // 0x800133AC: nop
    
            goto L_800133B8;
    }
    // 0x800133AC: nop

    // 0x800133B0: b           L_800133BC
    // 0x800133B4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_800133BC;
    // 0x800133B4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800133B8:
    // 0x800133B8: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
L_800133BC:
    // 0x800133BC: lh          $a0, 0x28($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X28);
    // 0x800133C0: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800133C4: blez        $a0, L_80013408
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800133C8: or          $t0, $t7, $zero
        ctx->r8 = ctx->r15 | 0;
            goto L_80013408;
    }
    // 0x800133C8: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
    // 0x800133CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800133D0:
    // 0x800133D0: lw          $t8, 0x38($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X38);
    // 0x800133D4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800133D8: addu        $v1, $t8, $v0
    ctx->r3 = ADD32(ctx->r24, ctx->r2);
    // 0x800133DC: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x800133E0: nop

    // 0x800133E4: and         $t4, $t9, $a3
    ctx->r12 = ctx->r25 & ctx->r7;
    // 0x800133E8: bne         $a2, $t4, L_80013400
    if (ctx->r6 != ctx->r12) {
        // 0x800133EC: slt         $at, $t1, $a0
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80013400;
    }
    // 0x800133EC: slt         $at, $t1, $a0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800133F0: sb          $t0, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r8;
    // 0x800133F4: lh          $a0, 0x28($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X28);
    // 0x800133F8: nop

    // 0x800133FC: slt         $at, $t1, $a0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
L_80013400:
    // 0x80013400: bne         $at, $zero, L_800133D0
    if (ctx->r1 != 0) {
        // 0x80013404: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800133D0;
    }
    // 0x80013404: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_80013408:
    // 0x80013408: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8001340C: lwc1        $f18, 0x78($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X78);
    // 0x80013410: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80013414: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80013418: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8001341C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x80013420: lwc1        $f8, 0x7C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X7C);
    // 0x80013424: nop

    // 0x80013428: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001342C: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80013430: lwc1        $f18, 0x80($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X80);
    // 0x80013434: nop

    // 0x80013438: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001343C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x80013440: lwc1        $f0, 0x8C($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X8C);
    // 0x80013444: b           L_8001346C
    // 0x80013448: nop

        goto L_8001346C;
    // 0x80013448: nop

L_8001344C:
    // 0x8001344C: lh          $t3, 0x48($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X48);
    // 0x80013450: addiu       $at, $zero, 0x6D
    ctx->r1 = ADD32(0, 0X6D);
    // 0x80013454: bne         $t3, $at, L_8001346C
    if (ctx->r11 != ctx->r1) {
        // 0x80013458: nop
    
            goto L_8001346C;
    }
    // 0x80013458: nop

    // 0x8001345C: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x80013460: nop

    // 0x80013464: lwc1        $f0, 0x30($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X30);
    // 0x80013468: nop

L_8001346C:
    // 0x8001346C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80013470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80013474: swc1        $f0, -0x4D58($at)
    MEM_W(-0X4D58, ctx->r1) = ctx->f0.u32l;
    // 0x80013478: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001347C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80013480: swc1        $f14, -0x4D50($at)
    MEM_W(-0X4D50, ctx->r1) = ctx->f14.u32l;
    // 0x80013484: jr          $ra
    // 0x80013488: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80013488: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void default_alloc_displaylist_heap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F21C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8006F220: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006F224: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8006F228: lw          $t5, -0x26C4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X26C4);
    // 0x8006F22C: lw          $t9, -0x26D4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26D4);
    // 0x8006F230: lw          $t7, -0x26A4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26A4);
    // 0x8006F234: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8006F238: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F23C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8006F240: lw          $t2, -0x26B4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X26B4);
    // 0x8006F244: sw          $t6, 0x3A8C($at)
    MEM_W(0X3A8C, ctx->r1) = ctx->r14;
    // 0x8006F248: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006F24C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8006F250: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8006F254: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8006F258: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8006F25C: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x8006F260: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006F264: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8006F268: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8006F26C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F270: addu        $a0, $t4, $t6
    ctx->r4 = ADD32(ctx->r12, ctx->r14);
    // 0x8006F274: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8006F278: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006F27C: jal         0x80070EDC
    // 0x8006F280: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8006F280: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006F284: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006F288: addiu       $v1, $v1, 0x1770
    ctx->r3 = ADD32(ctx->r3, 0X1770);
    // 0x8006F28C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8006F290: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8006F294: lw          $t7, -0x26D4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26D4);
    // 0x8006F298: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8006F29C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8006F2A0: lw          $t2, -0x26B4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X26B4);
    // 0x8006F2A4: lw          $t5, -0x26C4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X26C4);
    // 0x8006F2A8: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x8006F2AC: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8006F2B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F2B4: sw          $t0, 0x1780($at)
    MEM_W(0X1780, ctx->r1) = ctx->r8;
    // 0x8006F2B8: sll         $t1, $t2, 6
    ctx->r9 = S32(ctx->r10 << 6);
    // 0x8006F2BC: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8006F2C0: addu        $t3, $t1, $t0
    ctx->r11 = ADD32(ctx->r9, ctx->r8);
    // 0x8006F2C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F2C8: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006F2CC: sw          $t3, 0x1790($at)
    MEM_W(0X1790, ctx->r1) = ctx->r11;
    // 0x8006F2D0: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8006F2D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006F2D8: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x8006F2DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F2E0: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006F2E4: sw          $t6, 0x17A0($at)
    MEM_W(0X17A0, ctx->r1) = ctx->r14;
    // 0x8006F2E8: jal         0x80070EDC
    // 0x8006F2EC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x8006F2EC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_1:
    // 0x8006F2F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F2F4: lw          $a0, -0x26D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26D4);
    // 0x8006F2F8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006F2FC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8006F300: lw          $a2, -0x26C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X26C4);
    // 0x8006F304: lw          $a1, -0x26B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X26B4);
    // 0x8006F308: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006F30C: addiu       $v1, $v1, 0x1770
    ctx->r3 = ADD32(ctx->r3, 0X1770);
    // 0x8006F310: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x8006F314: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8006F318: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8006F31C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F320: sw          $t8, 0x1784($at)
    MEM_W(0X1784, ctx->r1) = ctx->r24;
    // 0x8006F324: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8006F328: sll         $t2, $a1, 6
    ctx->r10 = S32(ctx->r5 << 6);
    // 0x8006F32C: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x8006F330: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F334: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8006F338: sw          $t1, 0x1794($at)
    MEM_W(0X1794, ctx->r1) = ctx->r9;
    // 0x8006F33C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8006F340: addu        $t5, $t0, $t1
    ctx->r13 = ADD32(ctx->r8, ctx->r9);
    // 0x8006F344: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F348: sw          $t5, 0x17A4($at)
    MEM_W(0X17A4, ctx->r1) = ctx->r13;
    // 0x8006F34C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F350: sw          $a0, 0x3AA8($at)
    MEM_W(0X3AA8, ctx->r1) = ctx->r4;
    // 0x8006F354: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F358: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8006F35C: lw          $t4, -0x26A4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X26A4);
    // 0x8006F360: sw          $a1, 0x3AAC($at)
    MEM_W(0X3AAC, ctx->r1) = ctx->r5;
    // 0x8006F364: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F36C: sw          $t4, 0x3AB0($at)
    MEM_W(0X3AB0, ctx->r1) = ctx->r12;
    // 0x8006F370: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F374: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006F378: jr          $ra
    // 0x8006F37C: sw          $a2, 0x3AB4($at)
    MEM_W(0X3AB4, ctx->r1) = ctx->r6;
    return;
    // 0x8006F37C: sw          $a2, 0x3AB4($at)
    MEM_W(0X3AB4, ctx->r1) = ctx->r6;
;}
RECOMP_FUNC void menu_missing_controller(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E48: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80082E4C: addiu       $v0, $v0, -0x614
    ctx->r2 = ADD32(ctx->r2, -0X614);
    // 0x80082E50: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80082E54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80082E58: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80082E5C: andi        $t9, $t7, 0x10
    ctx->r25 = ctx->r15 & 0X10;
    // 0x80082E60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80082E64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80082E68: beq         $t9, $zero, L_80082EEC
    if (ctx->r25 == 0) {
        // 0x80082E6C: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_80082EEC;
    }
    // 0x80082E6C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80082E70: jal         0x8009F064
    // 0x80082E74: nop

    get_language(rdram, ctx);
        goto after_0;
    // 0x80082E74: nop

    after_0:
    // 0x80082E78: jal         0x8007FD50
    // 0x80082E7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    load_menu_text(rdram, ctx);
        goto after_1;
    // 0x80082E7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80082E80: jal         0x800C484C
    // 0x80082E84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_2;
    // 0x80082E84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80082E88: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80082E8C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80082E90: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80082E94: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80082E98: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80082E9C: jal         0x800C48E4
    // 0x80082EA0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_3;
    // 0x80082EA0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80082EA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082EA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082EAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80082EB0: jal         0x800C492C
    // 0x80082EB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_4;
    // 0x80082EB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80082EB8: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80082EBC: lw          $t1, 0x300($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X300);
    // 0x80082EC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80082EC4: bne         $t1, $zero, L_80082ED0
    if (ctx->r9 != 0) {
        // 0x80082EC8: addiu       $a2, $zero, 0xD0
        ctx->r6 = ADD32(0, 0XD0);
            goto L_80082ED0;
    }
    // 0x80082EC8: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // 0x80082ECC: addiu       $a2, $zero, 0xEA
    ctx->r6 = ADD32(0, 0XEA);
L_80082ED0:
    // 0x80082ED0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80082ED4: lw          $t2, -0x5E0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E0);
    // 0x80082ED8: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80082EDC: lw          $a3, 0x25C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X25C);
    // 0x80082EE0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80082EE4: jal         0x800C49A0
    // 0x80082EE8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x80082EE8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    after_5:
L_80082EEC:
    // 0x80082EEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80082EF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80082EF4: jr          $ra
    // 0x80082EF8: nop

    return;
    // 0x80082EF8: nop

;}
RECOMP_FUNC void get_balloon_cutscene_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE88: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001AE8C: lw          $v0, -0x4CB8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CB8);
    // 0x8001AE90: jr          $ra
    // 0x8001AE94: nop

    return;
    // 0x8001AE94: nop

;}
RECOMP_FUNC void menu_trophy_race_round_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098AD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80098ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80098AE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80098AE4: jal         0x8001E2D0
    // 0x80098AE8: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80098AE8: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_0:
    // 0x80098AEC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80098AF0: addiu       $a3, $a3, 0xF00
    ctx->r7 = ADD32(ctx->r7, 0XF00);
    // 0x80098AF4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80098AF8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80098AFC: beq         $v1, $zero, L_80098B68
    if (ctx->r3 == 0) {
        // 0x80098B00: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80098B68;
    }
    // 0x80098B00: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80098B04: subu        $t7, $v1, $t6
    ctx->r15 = SUB32(ctx->r3, ctx->r14);
    // 0x80098B08: bgtz        $t7, L_80098B68
    if (SIGNED(ctx->r15) > 0) {
        // 0x80098B0C: sw          $t7, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r15;
            goto L_80098B68;
    }
    // 0x80098B0C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80098B10: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80098B14: lw          $t9, 0x1568($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1568);
    // 0x80098B18: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80098B1C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80098B20: lw          $t1, 0x156C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X156C);
    // 0x80098B24: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80098B28: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80098B2C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80098B30: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80098B34: lb          $v1, -0x6($t3)
    ctx->r3 = MEM_B(ctx->r11, -0X6);
    // 0x80098B38: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80098B3C: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x80098B40: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x80098B44: lh          $a2, 0xCD8($a2)
    ctx->r6 = MEM_H(ctx->r6, 0XCD8);
    // 0x80098B48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80098B4C: beq         $a2, $at, L_80098B64
    if (ctx->r6 == ctx->r1) {
        // 0x80098B50: andi        $a0, $a2, 0xFFFF
        ctx->r4 = ctx->r6 & 0XFFFF;
            goto L_80098B64;
    }
    // 0x80098B50: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    // 0x80098B54: jal         0x80001D04
    // 0x80098B58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80098B58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80098B5C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80098B60: addiu       $a3, $a3, 0xF00
    ctx->r7 = ADD32(ctx->r7, 0XF00);
L_80098B64:
    // 0x80098B64: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80098B68:
    // 0x80098B68: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80098B6C: addiu       $v1, $v1, -0x604
    ctx->r3 = ADD32(ctx->r3, -0X604);
    // 0x80098B70: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80098B74: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80098B78: beq         $v0, $zero, L_80098B88
    if (ctx->r2 == 0) {
        // 0x80098B7C: addu        $t6, $v0, $t5
        ctx->r14 = ADD32(ctx->r2, ctx->r13);
            goto L_80098B88;
    }
    // 0x80098B7C: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80098B80: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80098B84: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80098B88:
    // 0x80098B88: slti        $at, $v0, 0x16
    ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
    // 0x80098B8C: beq         $at, $zero, L_80098BA8
    if (ctx->r1 == 0) {
        // 0x80098B90: nop
    
            goto L_80098BA8;
    }
    // 0x80098B90: nop

    // 0x80098B94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80098B98: jal         0x800988FC
    // 0x80098B9C: nop

    trophyround_render(rdram, ctx);
        goto after_2;
    // 0x80098B9C: nop

    after_2:
    // 0x80098BA0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80098BA4: addiu       $v1, $v1, -0x604
    ctx->r3 = ADD32(ctx->r3, -0X604);
L_80098BA8:
    // 0x80098BA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80098BAC: lw          $t7, 0x6964($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6964);
    // 0x80098BB0: nop

    // 0x80098BB4: bne         $t7, $zero, L_80098C08
    if (ctx->r15 != 0) {
        // 0x80098BB8: nop
    
            goto L_80098C08;
    }
    // 0x80098BB8: nop

    // 0x80098BBC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80098BC0: nop

    // 0x80098BC4: bne         $t8, $zero, L_80098C08
    if (ctx->r24 != 0) {
        // 0x80098BC8: nop
    
            goto L_80098C08;
    }
    // 0x80098BC8: nop

    // 0x80098BCC: jal         0x8008E9A4
    // 0x80098BD0: nop

    menu_input(rdram, ctx);
        goto after_3;
    // 0x80098BD0: nop

    after_3:
    // 0x80098BD4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80098BD8: lw          $t9, 0x6D88($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6D88);
    // 0x80098BDC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80098BE0: andi        $t0, $t9, 0x9000
    ctx->r8 = ctx->r25 & 0X9000;
    // 0x80098BE4: beq         $t0, $zero, L_80098C08
    if (ctx->r8 == 0) {
        // 0x80098BE8: nop
    
            goto L_80098C08;
    }
    // 0x80098BE8: nop

    // 0x80098BEC: jal         0x800C06F8
    // 0x80098BF0: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_4;
    // 0x80098BF0: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_4:
    // 0x80098BF4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80098BF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80098BFC: sw          $t1, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r9;
    // 0x80098C00: jal         0x80000C98
    // 0x80098C04: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_5;
    // 0x80098C04: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_5:
L_80098C08:
    // 0x80098C08: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80098C0C: addiu       $v1, $v1, -0x604
    ctx->r3 = ADD32(ctx->r3, -0X604);
    // 0x80098C10: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80098C14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80098C18: slti        $at, $t2, 0x1F
    ctx->r1 = SIGNED(ctx->r10) < 0X1F ? 1 : 0;
    // 0x80098C1C: bne         $at, $zero, L_80098C78
    if (ctx->r1 != 0) {
        // 0x80098C20: nop
    
            goto L_80098C78;
    }
    // 0x80098C20: nop

    // 0x80098C24: jal         0x80098C90
    // 0x80098C28: nop

    trophyround_free(rdram, ctx);
        goto after_6;
    // 0x80098C28: nop

    after_6:
    // 0x80098C2C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80098C30: lw          $t3, 0x1568($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1568);
    // 0x80098C34: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80098C38: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80098C3C: lw          $t5, 0x156C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X156C);
    // 0x80098C40: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80098C44: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80098C48: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80098C4C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80098C50: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80098C54: lb          $t9, -0x6($t8)
    ctx->r25 = MEM_B(ctx->r24, -0X6);
    // 0x80098C58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80098C5C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80098C60: sw          $t9, -0x5AC($at)
    MEM_W(-0X5AC, ctx->r1) = ctx->r25;
    // 0x80098C64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80098C68: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80098C6C: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x80098C70: b           L_80098C80
    // 0x80098C74: sw          $t0, -0x608($at)
    MEM_W(-0X608, ctx->r1) = ctx->r8;
        goto L_80098C80;
    // 0x80098C74: sw          $t0, -0x608($at)
    MEM_W(-0X608, ctx->r1) = ctx->r8;
L_80098C78:
    // 0x80098C78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80098C7C: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_80098C80:
    // 0x80098C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098C84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80098C88: jr          $ra
    // 0x80098C8C: nop

    return;
    // 0x80098C8C: nop

;}
RECOMP_FUNC void func_800214C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800214F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800214FC: lb          $t6, -0x4D5F($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X4D5F);
    // 0x80021500: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80021504: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80021508: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8002150C: lb          $v0, -0x4D5D($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D5D);
    // 0x80021510: jr          $ra
    // 0x80021514: nop

    return;
    // 0x80021514: nop

;}
RECOMP_FUNC void racer_enter_door(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A490: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005A494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A498: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005A49C: lw          $t6, 0x108($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X108);
    // 0x8005A4A0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8005A4A4: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x8005A4A8: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x8005A4AC: lwc1        $f14, 0x8($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8005A4B0: lwc1        $f12, 0x0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8005A4B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005A4B8: jal         0x80070990
    // 0x8005A4BC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    arctan2_f(rdram, ctx);
        goto after_0;
    // 0x8005A4BC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8005A4C0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8005A4C4: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x8005A4C8: lh          $t9, 0x1A0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X1A0);
    // 0x8005A4CC: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005A4D0: andi        $t2, $t9, 0xFFFF
    ctx->r10 = ctx->r25 & 0XFFFF;
    // 0x8005A4D4: subu        $v1, $t8, $t2
    ctx->r3 = SUB32(ctx->r24, ctx->r10);
    // 0x8005A4D8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A4DC: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005A4E0: bne         $at, $zero, L_8005A4F4
    if (ctx->r1 != 0) {
        // 0x8005A4E4: addiu       $t1, $zero, -0x1
        ctx->r9 = ADD32(0, -0X1);
            goto L_8005A4F4;
    }
    // 0x8005A4E4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005A4E8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005A4EC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005A4F0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005A4F4:
    // 0x8005A4F4: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005A4F8: beq         $at, $zero, L_8005A508
    if (ctx->r1 == 0) {
        // 0x8005A4FC: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8005A508;
    }
    // 0x8005A4FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005A500: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005A504: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005A508:
    // 0x8005A508: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005A50C: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x8005A510: addiu       $a1, $a1, -0x254C
    ctx->r5 = ADD32(ctx->r5, -0X254C);
    // 0x8005A514: sra         $t3, $v1, 5
    ctx->r11 = S32(SIGNED(ctx->r3) >> 5);
    // 0x8005A518: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8005A51C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A520: sw          $zero, -0x2554($at)
    MEM_W(-0X2554, ctx->r1) = 0;
    // 0x8005A524: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A528: sw          $zero, -0x2550($at)
    MEM_W(-0X2550, ctx->r1) = 0;
    // 0x8005A52C: addiu       $a0, $a0, -0x2558
    ctx->r4 = ADD32(ctx->r4, -0X2558);
    // 0x8005A530: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8005A534: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A538: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
    // 0x8005A53C: lwc1        $f4, 0x2C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x8005A540: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x8005A544: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005A548: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005A54C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8005A550: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x8005A554: lui         $at, 0xC014
    ctx->r1 = S32(0XC014 << 16);
    // 0x8005A558: bc1f        L_8005A574
    if (!c1cs) {
        // 0x8005A55C: nop
    
            goto L_8005A574;
    }
    // 0x8005A55C: nop

    // 0x8005A560: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005A564: nop

    // 0x8005A568: ori         $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 | 0X8000;
    // 0x8005A56C: b           L_8005A5A0
    // 0x8005A570: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
        goto L_8005A5A0;
    // 0x8005A570: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_8005A574:
    // 0x8005A574: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005A578: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005A57C: nop

    // 0x8005A580: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8005A584: nop

    // 0x8005A588: bc1f        L_8005A5A4
    if (!c1cs) {
        // 0x8005A58C: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_8005A5A4;
    }
    // 0x8005A58C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8005A590: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005A594: nop

    // 0x8005A598: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x8005A59C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_8005A5A0:
    // 0x8005A5A0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_8005A5A4:
    // 0x8005A5A4: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8005A5A8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8005A5AC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8005A5B0: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005A5B4: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8005A5B8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005A5BC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8005A5C0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005A5C4: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x8005A5C8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8005A5CC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005A5D0: mul.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x8005A5D4: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005A5D8: addiu       $t4, $zero, -0x4B
    ctx->r12 = ADD32(0, -0X4B);
    // 0x8005A5DC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8005A5E0: add.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f18.d + ctx->f10.d;
    // 0x8005A5E4: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8005A5E8: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8005A5EC: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8005A5F0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8005A5F4: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8005A5F8: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005A5FC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8005A600: mul.d       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f2.d);
    // 0x8005A604: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005A608: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x8005A60C: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8005A610: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x8005A614: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8005A618: nop

    // 0x8005A61C: slti        $at, $v1, 0x4C
    ctx->r1 = SIGNED(ctx->r3) < 0X4C ? 1 : 0;
    // 0x8005A620: bne         $at, $zero, L_8005A640
    if (ctx->r1 != 0) {
        // 0x8005A624: slti        $at, $v1, -0x4B
        ctx->r1 = SIGNED(ctx->r3) < -0X4B ? 1 : 0;
            goto L_8005A640;
    }
    // 0x8005A624: slti        $at, $v1, -0x4B
    ctx->r1 = SIGNED(ctx->r3) < -0X4B ? 1 : 0;
    // 0x8005A628: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005A62C: addiu       $v1, $zero, 0x4B
    ctx->r3 = ADD32(0, 0X4B);
    // 0x8005A630: ori         $t3, $t2, 0xC000
    ctx->r11 = ctx->r10 | 0XC000;
    // 0x8005A634: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005A638: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8005A63C: slti        $at, $v1, -0x4B
    ctx->r1 = SIGNED(ctx->r3) < -0X4B ? 1 : 0;
L_8005A640:
    // 0x8005A640: beq         $at, $zero, L_8005A658
    if (ctx->r1 == 0) {
        // 0x8005A644: nop
    
            goto L_8005A658;
    }
    // 0x8005A644: nop

    // 0x8005A648: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005A64C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8005A650: ori         $t6, $t5, 0xC000
    ctx->r14 = ctx->r13 | 0XC000;
    // 0x8005A654: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_8005A658:
    // 0x8005A658: lb          $v0, 0x200($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X200);
    // 0x8005A65C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8005A660: slti        $at, $v0, -0x1
    ctx->r1 = SIGNED(ctx->r2) < -0X1 ? 1 : 0;
    // 0x8005A664: beq         $at, $zero, L_8005A68C
    if (ctx->r1 == 0) {
        // 0x8005A668: addu        $t9, $v0, $t7
        ctx->r25 = ADD32(ctx->r2, ctx->r15);
            goto L_8005A68C;
    }
    // 0x8005A668: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x8005A66C: sb          $t9, 0x200($a2)
    MEM_B(0X200, ctx->r6) = ctx->r25;
    // 0x8005A670: lb          $v0, 0x200($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X200);
    // 0x8005A674: nop

    // 0x8005A678: bltz        $v0, L_8005A690
    if (SIGNED(ctx->r2) < 0) {
        // 0x8005A67C: slti        $at, $v0, -0x1
        ctx->r1 = SIGNED(ctx->r2) < -0X1 ? 1 : 0;
            goto L_8005A690;
    }
    // 0x8005A67C: slti        $at, $v0, -0x1
    ctx->r1 = SIGNED(ctx->r2) < -0X1 ? 1 : 0;
    // 0x8005A680: sb          $t1, 0x200($a2)
    MEM_B(0X200, ctx->r6) = ctx->r9;
    // 0x8005A684: lb          $v0, 0x200($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X200);
    // 0x8005A688: nop

L_8005A68C:
    // 0x8005A68C: slti        $at, $v0, -0x1
    ctx->r1 = SIGNED(ctx->r2) < -0X1 ? 1 : 0;
L_8005A690:
    // 0x8005A690: beq         $at, $zero, L_8005A6B4
    if (ctx->r1 == 0) {
        // 0x8005A694: nop
    
            goto L_8005A6B4;
    }
    // 0x8005A694: nop

    // 0x8005A698: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8005A69C: nop

    // 0x8005A6A0: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x8005A6A4: beq         $at, $zero, L_8005A6B4
    if (ctx->r1 == 0) {
        // 0x8005A6A8: slti        $at, $v1, -0x9
        ctx->r1 = SIGNED(ctx->r3) < -0X9 ? 1 : 0;
            goto L_8005A6B4;
    }
    // 0x8005A6A8: slti        $at, $v1, -0x9
    ctx->r1 = SIGNED(ctx->r3) < -0X9 ? 1 : 0;
    // 0x8005A6AC: beq         $at, $zero, L_8005A6BC
    if (ctx->r1 == 0) {
        // 0x8005A6B0: nop
    
            goto L_8005A6BC;
    }
    // 0x8005A6B0: nop

L_8005A6B4:
    // 0x8005A6B4: bne         $t1, $v0, L_8005A6F8
    if (ctx->r9 != ctx->r2) {
        // 0x8005A6B8: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8005A6F8;
    }
    // 0x8005A6B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8005A6BC:
    // 0x8005A6BC: jal         0x80066750
    // 0x8005A6C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_1;
    // 0x8005A6C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x8005A6C4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8005A6C8: bne         $v0, $zero, L_8005A6E4
    if (ctx->r2 != 0) {
        // 0x8005A6CC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8005A6E4;
    }
    // 0x8005A6CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005A6D0: addiu       $a0, $a0, -0x2CBC
    ctx->r4 = ADD32(ctx->r4, -0X2CBC);
    // 0x8005A6D4: jal         0x800C06F8
    // 0x8005A6D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    transition_begin(rdram, ctx);
        goto after_2;
    // 0x8005A6D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x8005A6DC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8005A6E0: nop

L_8005A6E4:
    // 0x8005A6E4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8005A6E8: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x8005A6EC: subu        $t3, $t2, $t8
    ctx->r11 = SUB32(ctx->r10, ctx->r24);
    // 0x8005A6F0: sb          $t3, 0x200($a2)
    MEM_B(0X200, ctx->r6) = ctx->r11;
    // 0x8005A6F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8005A6F8:
    // 0x8005A6F8: jal         0x8006F5C8
    // 0x8005A6FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    set_pause_lockout_timer(rdram, ctx);
        goto after_3;
    // 0x8005A6FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x8005A700: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8005A704: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8005A708: lb          $v0, 0x200($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X200);
    // 0x8005A70C: nop

    // 0x8005A710: blez        $v0, L_8005A74C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005A714: subu        $t5, $v0, $t4
        ctx->r13 = SUB32(ctx->r2, ctx->r12);
            goto L_8005A74C;
    }
    // 0x8005A714: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x8005A718: sb          $t5, 0x200($a2)
    MEM_B(0X200, ctx->r6) = ctx->r13;
    // 0x8005A71C: lb          $t6, 0x200($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X200);
    // 0x8005A720: nop

    // 0x8005A724: bgtz        $t6, L_8005A750
    if (SIGNED(ctx->r14) > 0) {
        // 0x8005A728: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005A750;
    }
    // 0x8005A728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A72C: lw          $t7, 0x108($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X108);
    // 0x8005A730: nop

    // 0x8005A734: lw          $a0, 0x3C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X3C);
    // 0x8005A738: jal         0x8006DBA8
    // 0x8005A73C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8006D968(rdram, ctx);
        goto after_4;
    // 0x8005A73C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x8005A740: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8005A744: nop

    // 0x8005A748: sb          $zero, 0x200($a2)
    MEM_B(0X200, ctx->r6) = 0;
L_8005A74C:
    // 0x8005A74C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005A750:
    // 0x8005A750: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005A754: jr          $ra
    // 0x8005A758: nop

    return;
    // 0x8005A758: nop

;}
RECOMP_FUNC void racerfx_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B290: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000B294: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000B298: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000B29C: addiu       $s0, $s0, -0x333C
    ctx->r16 = ADD32(ctx->r16, -0X333C);
    // 0x8000B2A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000B2A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000B2A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000B2AC: beq         $a0, $zero, L_8000B2D4
    if (ctx->r4 == 0) {
        // 0x8000B2B0: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_8000B2D4;
    }
    // 0x8000B2B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000B2B4: jal         0x80071380
    // 0x8000B2B8: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x8000B2B8: nop

    after_0:
    // 0x8000B2BC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000B2C0: addiu       $v0, $v0, -0x3344
    ctx->r2 = ADD32(ctx->r2, -0X3344);
    // 0x8000B2C4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8000B2C8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8000B2CC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8000B2D0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_8000B2D4:
    // 0x8000B2D4: jal         0x8001E2D0
    // 0x8000B2D8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8000B2D8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_1:
    // 0x8000B2DC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000B2E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000B2E4: addiu       $s2, $zero, 0x500
    ctx->r18 = ADD32(0, 0X500);
L_8000B2E8:
    // 0x8000B2E8: lw          $a0, 0x78($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X78);
    // 0x8000B2EC: nop

    // 0x8000B2F0: beq         $a0, $zero, L_8000B304
    if (ctx->r4 == 0) {
        // 0x8000B2F4: nop
    
            goto L_8000B304;
    }
    // 0x8000B2F4: nop

    // 0x8000B2F8: jal         0x8007D100
    // 0x8000B2FC: nop

    sprite_free(rdram, ctx);
        goto after_2;
    // 0x8000B2FC: nop

    after_2:
    // 0x8000B300: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8000B304:
    // 0x8000B304: lw          $a0, 0x7C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7C);
    // 0x8000B308: nop

    // 0x8000B30C: beq         $a0, $zero, L_8000B320
    if (ctx->r4 == 0) {
        // 0x8000B310: nop
    
            goto L_8000B320;
    }
    // 0x8000B310: nop

    // 0x8000B314: jal         0x8007B70C
    // 0x8000B318: nop

    tex_free(rdram, ctx);
        goto after_3;
    // 0x8000B318: nop

    after_3:
    // 0x8000B31C: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
L_8000B320:
    // 0x8000B320: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x8000B324: bne         $s1, $s2, L_8000B2E8
    if (ctx->r17 != ctx->r18) {
        // 0x8000B328: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_8000B2E8;
    }
    // 0x8000B328: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x8000B32C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000B330: addiu       $s0, $s0, -0x3334
    ctx->r16 = ADD32(ctx->r16, -0X3334);
    // 0x8000B334: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000B338: nop

    // 0x8000B33C: beq         $a0, $zero, L_8000B34C
    if (ctx->r4 == 0) {
        // 0x8000B340: nop
    
            goto L_8000B34C;
    }
    // 0x8000B340: nop

    // 0x8000B344: jal         0x8000FFB8
    // 0x8000B348: nop

    free_object(rdram, ctx);
        goto after_4;
    // 0x8000B348: nop

    after_4:
L_8000B34C:
    // 0x8000B34C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8000B350: addiu       $s1, $s1, -0x332C
    ctx->r17 = ADD32(ctx->r17, -0X332C);
    // 0x8000B354: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8000B358: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8000B35C: beq         $a0, $zero, L_8000B36C
    if (ctx->r4 == 0) {
        // 0x8000B360: nop
    
            goto L_8000B36C;
    }
    // 0x8000B360: nop

    // 0x8000B364: jal         0x8000FFB8
    // 0x8000B368: nop

    free_object(rdram, ctx);
        goto after_5;
    // 0x8000B368: nop

    after_5:
L_8000B36C:
    // 0x8000B36C: jal         0x8001004C
    // 0x8000B370: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    gParticlePtrList_flush(rdram, ctx);
        goto after_6;
    // 0x8000B370: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    after_6:
    // 0x8000B374: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000B378: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000B37C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B380: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000B384: jr          $ra
    // 0x8000B388: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000B388: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void write_epc_data_to_cpak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B76EC: addiu       $sp, $sp, -0x848
    ctx->r29 = ADD32(ctx->r29, -0X848);
    // 0x800B76F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B76F4: jal         0x800D29D0
    // 0x800B76F8: nop

    __osGetActiveQueue(rdram, ctx);
        goto after_0;
    // 0x800B76F8: nop

    after_0:
    // 0x800B76FC: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800B7700: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800B7704: beq         $a0, $t6, L_800B7758
    if (ctx->r4 == ctx->r14) {
        // 0x800B7708: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800B7758;
    }
    // 0x800B7708: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B770C: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x800B7710: nop

L_800B7714:
    // 0x800B7714: blez        $v1, L_800B7740
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B7718: slti        $at, $v1, 0x80
        ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
            goto L_800B7740;
    }
    // 0x800B7718: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x800B771C: beq         $at, $zero, L_800B7740
    if (ctx->r1 == 0) {
        // 0x800B7720: nop
    
            goto L_800B7740;
    }
    // 0x800B7720: nop

    // 0x800B7724: lhu         $v1, 0x12($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X12);
    // 0x800B7728: nop

    // 0x800B772C: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x800B7730: bne         $t7, $zero, L_800B7758
    if (ctx->r15 != 0) {
        // 0x800B7734: andi        $t8, $v1, 0x1
        ctx->r24 = ctx->r3 & 0X1;
            goto L_800B7758;
    }
    // 0x800B7734: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x800B7738: bne         $t8, $zero, L_800B7758
    if (ctx->r24 != 0) {
        // 0x800B773C: nop
    
            goto L_800B7758;
    }
    // 0x800B773C: nop

L_800B7740:
    // 0x800B7740: lw          $a3, 0xC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0XC);
    // 0x800B7744: nop

    // 0x800B7748: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x800B774C: nop

    // 0x800B7750: bne         $a0, $v1, L_800B7714
    if (ctx->r4 != ctx->r3) {
        // 0x800B7754: nop
    
            goto L_800B7714;
    }
    // 0x800B7754: nop

L_800B7758:
    // 0x800B7758: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x800B775C: nop

    // 0x800B7760: beq         $a0, $t9, L_800B7968
    if (ctx->r4 == ctx->r25) {
        // 0x800B7764: nop
    
            goto L_800B7968;
    }
    // 0x800B7764: nop

    // 0x800B7768: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B776C: addiu       $v0, $v0, -0x5A90
    ctx->r2 = ADD32(ctx->r2, -0X5A90);
    // 0x800B7770: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800B7774: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800B7778: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B777C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800B7780: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B7784: addiu       $a2, $zero, 0x1B0
    ctx->r6 = ADD32(0, 0X1B0);
    // 0x800B7788: swc1        $f6, 0x130($a3)
    MEM_W(0X130, ctx->r7) = ctx->f6.u32l;
    // 0x800B778C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800B7790: nop

    // 0x800B7794: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800B7798: nop

    // 0x800B779C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B77A0: swc1        $f10, 0x134($a3)
    MEM_W(0X134, ctx->r7) = ctx->f10.u32l;
    // 0x800B77A4: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800B77A8: nop

    // 0x800B77AC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800B77B0: nop

    // 0x800B77B4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B77B8: swc1        $f18, 0x138($a3)
    MEM_W(0X138, ctx->r7) = ctx->f18.u32l;
    // 0x800B77BC: jal         0x800CA300
    // 0x800B77C0: sw          $a3, 0x844($sp)
    MEM_W(0X844, ctx->r29) = ctx->r7;
    _bcopy(rdram, ctx);
        goto after_1;
    // 0x800B77C0: sw          $a3, 0x844($sp)
    MEM_W(0X844, ctx->r29) = ctx->r7;
    after_1:
    // 0x800B77C4: lw          $a3, 0x844($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X844);
    // 0x800B77C8: addiu       $a1, $sp, 0x244
    ctx->r5 = ADD32(ctx->r29, 0X244);
    // 0x800B77CC: lw          $a0, 0xF4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XF4);
    // 0x800B77D0: jal         0x800CA300
    // 0x800B77D4: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    _bcopy(rdram, ctx);
        goto after_2;
    // 0x800B77D4: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_2:
    // 0x800B77D8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800B77DC: jal         0x800245C8
    // 0x800B77E0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80024594(rdram, ctx);
        goto after_3;
    // 0x800B77E0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x800B77E4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800B77E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B77EC: blez        $t3, L_800B7940
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800B77F0: lui         $a3, 0x800F
        ctx->r7 = S32(0X800F << 16);
            goto L_800B7940;
    }
    // 0x800B77F0: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800B77F4: andi        $a2, $t3, 0x3
    ctx->r6 = ctx->r11 & 0X3;
    // 0x800B77F8: beq         $a2, $zero, L_800B785C
    if (ctx->r6 == 0) {
        // 0x800B77FC: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_800B785C;
    }
    // 0x800B77FC: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800B7800: sll         $t6, $zero, 1
    ctx->r14 = S32(0 << 1);
    // 0x800B7804: addiu       $t7, $sp, 0x444
    ctx->r15 = ADD32(ctx->r29, 0X444);
    // 0x800B7808: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
L_800B780C:
    // 0x800B780C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B7810: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B7814: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7818: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800B781C: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800B7820: nop

    // 0x800B7824: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x800B7828: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B782C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800B7830: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x800B7834: bgez        $t4, L_800B7844
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800B7838: sw          $t4, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r12;
            goto L_800B7844;
    }
    // 0x800B7838: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800B783C: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x800B7840: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7844:
    // 0x800B7844: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800B7848: bne         $v1, $a1, L_800B780C
    if (ctx->r3 != ctx->r5) {
        // 0x800B784C: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_800B780C;
    }
    // 0x800B784C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B7850: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800B7854: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800B7858: beq         $a1, $t3, L_800B7940
    if (ctx->r5 == ctx->r11) {
        // 0x800B785C: sll         $t6, $a1, 1
        ctx->r14 = S32(ctx->r5 << 1);
            goto L_800B7940;
    }
L_800B785C:
    // 0x800B785C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800B7860: addiu       $t7, $sp, 0x444
    ctx->r15 = ADD32(ctx->r29, 0X444);
    // 0x800B7864: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
L_800B7868:
    // 0x800B7868: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B786C: nop

    // 0x800B7870: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7874: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x800B7878: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x800B787C: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B7880: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x800B7884: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B7888: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800B788C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800B7890: bgez        $t2, L_800B78A8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B7894: sw          $t2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r10;
            goto L_800B78A8;
    }
    // 0x800B7894: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B7898: addu        $a2, $t2, $t4
    ctx->r6 = ADD32(ctx->r10, ctx->r12);
    // 0x800B789C: sll         $t5, $a2, 1
    ctx->r13 = S32(ctx->r6 << 1);
    // 0x800B78A0: addu        $v1, $v0, $t5
    ctx->r3 = ADD32(ctx->r2, ctx->r13);
    // 0x800B78A4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B78A8:
    // 0x800B78A8: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x800B78AC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B78B0: sh          $t3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r11;
    // 0x800B78B4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800B78B8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800B78BC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B78C0: bgez        $t7, L_800B78D8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800B78C4: sw          $t7, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r15;
            goto L_800B78D8;
    }
    // 0x800B78C4: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800B78C8: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x800B78CC: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x800B78D0: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x800B78D4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B78D8:
    // 0x800B78D8: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x800B78DC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B78E0: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
    // 0x800B78E4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B78E8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800B78EC: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800B78F0: bgez        $t2, L_800B7908
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B78F4: sw          $t2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r10;
            goto L_800B7908;
    }
    // 0x800B78F4: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B78F8: addu        $a2, $t2, $t4
    ctx->r6 = ADD32(ctx->r10, ctx->r12);
    // 0x800B78FC: sll         $t5, $a2, 1
    ctx->r13 = S32(ctx->r6 << 1);
    // 0x800B7900: addu        $v1, $v0, $t5
    ctx->r3 = ADD32(ctx->r2, ctx->r13);
    // 0x800B7904: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7908:
    // 0x800B7908: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x800B790C: nop

    // 0x800B7910: sh          $t3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r11;
    // 0x800B7914: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800B7918: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800B791C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B7920: bgez        $t7, L_800B7930
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800B7924: sw          $t7, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r15;
            goto L_800B7930;
    }
    // 0x800B7924: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800B7928: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x800B792C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7930:
    // 0x800B7930: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800B7934: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B7938: bne         $a1, $t9, L_800B7868
    if (ctx->r5 != ctx->r25) {
        // 0x800B793C: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_800B7868;
    }
    // 0x800B793C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800B7940:
    // 0x800B7940: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800B7944: addiu       $t0, $sp, 0x44
    ctx->r8 = ADD32(ctx->r29, 0X44);
    // 0x800B7948: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x800B794C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800B7950: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800B7954: addiu       $a2, $a2, -0x6BA4
    ctx->r6 = ADD32(ctx->r6, -0X6BA4);
    // 0x800B7958: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B795C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800B7960: jal         0x8007692C
    // 0x800B7964: addiu       $a3, $a3, -0x6B9C
    ctx->r7 = ADD32(ctx->r7, -0X6B9C);
    write_controller_pak_file(rdram, ctx);
        goto after_4;
    // 0x800B7964: addiu       $a3, $a3, -0x6B9C
    ctx->r7 = ADD32(ctx->r7, -0X6B9C);
    after_4:
L_800B7968:
    // 0x800B7968: b           L_800B7968
    pause_self(rdram);
    // 0x800B796C: nop

    // 0x800B7970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7974: addiu       $sp, $sp, 0x848
    ctx->r29 = ADD32(ctx->r29, 0X848);
    // 0x800B7978: jr          $ra
    // 0x800B797C: nop

    return;
    // 0x800B797C: nop

;}
RECOMP_FUNC void get_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ECD0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006ECD4: lw          $v0, 0x3A90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A90);
    // 0x8006ECD8: jr          $ra
    // 0x8006ECDC: nop

    return;
    // 0x8006ECDC: nop

;}
RECOMP_FUNC void is_race_started_by_player_two(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E158: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000E15C: lb          $t6, -0x3350($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X3350);
    // 0x8000E160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000E164: beq         $t6, $zero, L_8000E17C
    if (ctx->r14 == 0) {
        // 0x8000E168: nop
    
            goto L_8000E17C;
    }
    // 0x8000E168: nop

    // 0x8000E16C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000E170: lb          $v0, -0x3354($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X3354);
    // 0x8000E174: jr          $ra
    // 0x8000E178: nop

    return;
    // 0x8000E178: nop

L_8000E17C:
    // 0x8000E17C: jr          $ra
    // 0x8000E180: nop

    return;
    // 0x8000E180: nop

;}
RECOMP_FUNC void cinematic_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B454: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009B458: lw          $t6, 0x6DA4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6DA4);
    // 0x8009B45C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B460: beq         $t6, $zero, L_8009B474
    if (ctx->r14 == 0) {
        // 0x8009B464: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009B474;
    }
    // 0x8009B464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B468: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B46C: jal         0x8009C9EC
    // 0x8009B470: addiu       $a0, $a0, 0x1CE8
    ctx->r4 = ADD32(ctx->r4, 0X1CE8);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x8009B470: addiu       $a0, $a0, 0x1CE8
    ctx->r4 = ADD32(ctx->r4, 0X1CE8);
    after_0:
L_8009B474:
    // 0x8009B474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B47C: jr          $ra
    // 0x8009B480: nop

    return;
    // 0x8009B480: nop

;}
RECOMP_FUNC void obj_loop_treasuresucker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D098: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003D09C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D0A0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8003D0A4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8003D0A8: lw          $a0, 0x78($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78);
    // 0x8003D0AC: jal         0x8001BAFC
    // 0x8003D0B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x8003D0B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x8003D0B4: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8003D0B8: beq         $v0, $zero, L_8003D2DC
    if (ctx->r2 == 0) {
        // 0x8003D0BC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8003D2DC;
    }
    // 0x8003D0BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8003D0C0: lw          $a3, 0x64($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X64);
    // 0x8003D0C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003D0C8: lb          $t6, 0x185($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X185);
    // 0x8003D0CC: nop

    // 0x8003D0D0: beq         $t6, $zero, L_8003D144
    if (ctx->r14 == 0) {
        // 0x8003D0D4: nop
    
            goto L_8003D144;
    }
    // 0x8003D0D4: nop

    // 0x8003D0D8: lw          $t7, 0x7C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X7C);
    // 0x8003D0DC: nop

    // 0x8003D0E0: bne         $t7, $zero, L_8003D144
    if (ctx->r15 != 0) {
        // 0x8003D0E4: nop
    
            goto L_8003D144;
    }
    // 0x8003D0E4: nop

    // 0x8003D0E8: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8003D0EC: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003D0F0: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8003D0F4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003D0F8: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003D0FC: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003D100: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003D104: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8003D108: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003D10C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003D110: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003D114: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D118: lwc1        $f16, 0x6710($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6710);
    // 0x8003D11C: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8003D120: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003D124: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8003D128: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003D12C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8003D130: nop

    // 0x8003D134: bc1f        L_8003D144
    if (!c1cs) {
        // 0x8003D138: nop
    
            goto L_8003D144;
    }
    // 0x8003D138: nop

    // 0x8003D13C: sw          $t8, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r24;
    // 0x8003D140: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8003D144:
    // 0x8003D144: lw          $v0, 0x7C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X7C);
    // 0x8003D148: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8003D14C: blez        $v0, L_8003D190
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003D150: subu        $t0, $v0, $t9
        ctx->r8 = SUB32(ctx->r2, ctx->r25);
            goto L_8003D190;
    }
    // 0x8003D150: subu        $t0, $v0, $t9
    ctx->r8 = SUB32(ctx->r2, ctx->r25);
    // 0x8003D154: bgtz        $t0, L_8003D190
    if (SIGNED(ctx->r8) > 0) {
        // 0x8003D158: sw          $t0, 0x7C($a2)
        MEM_W(0X7C, ctx->r6) = ctx->r8;
            goto L_8003D190;
    }
    // 0x8003D158: sw          $t0, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r8;
    // 0x8003D15C: lb          $v0, 0x185($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X185);
    // 0x8003D160: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8003D164: blez        $v0, L_8003D18C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003D168: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_8003D18C;
    }
    // 0x8003D168: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8003D16C: sb          $t2, 0x185($a3)
    MEM_B(0X185, ctx->r7) = ctx->r10;
    // 0x8003D170: lb          $t3, 0x185($a3)
    ctx->r11 = MEM_B(ctx->r7, 0X185);
    // 0x8003D174: nop

    // 0x8003D178: beq         $t3, $zero, L_8003D184
    if (ctx->r11 == 0) {
        // 0x8003D17C: nop
    
            goto L_8003D184;
    }
    // 0x8003D17C: nop

    // 0x8003D180: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8003D184:
    // 0x8003D184: b           L_8003D190
    // 0x8003D188: sw          $t4, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r12;
        goto L_8003D190;
    // 0x8003D188: sw          $t4, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r12;
L_8003D18C:
    // 0x8003D18C: sw          $zero, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = 0;
L_8003D190:
    // 0x8003D190: beq         $a0, $zero, L_8003D2E0
    if (ctx->r4 == 0) {
        // 0x8003D194: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003D2E0;
    }
    // 0x8003D194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D198: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8003D19C: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8003D1A0: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8003D1A4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D1A8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D1AC: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8003D1B0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8003D1B4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8003D1B8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8003D1BC: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8003D1C0: addiu       $t5, $zero, 0x61
    ctx->r13 = ADD32(0, 0X61);
    // 0x8003D1C4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8003D1C8: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    // 0x8003D1CC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8003D1D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D1D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D1D8: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003D1DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003D1E0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8003D1E4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003D1E8: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8003D1EC: nop

    // 0x8003D1F0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8003D1F4: addiu       $t1, $t0, 0xA
    ctx->r9 = ADD32(ctx->r8, 0XA);
    // 0x8003D1F8: sh          $t1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r9;
    // 0x8003D1FC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8003D200: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8003D204: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D208: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D20C: sb          $t4, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r12;
    // 0x8003D210: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8003D214: sb          $t5, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r13;
    // 0x8003D218: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x8003D21C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8003D220: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8003D224: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8003D228: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8003D22C: jal         0x8000EA54
    // 0x8003D230: sh          $t3, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r11;
    spawn_object(rdram, ctx);
        goto after_1;
    // 0x8003D230: sh          $t3, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r11;
    after_1:
    // 0x8003D234: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8003D238: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8003D23C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D240: beq         $v0, $zero, L_8003D2DC
    if (ctx->r2 == 0) {
        // 0x8003D244: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8003D2DC;
    }
    // 0x8003D244: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003D248: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003D24C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003D250: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003D254: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003D258: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8003D25C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003D260: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003D264: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8003D268: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8003D26C: nop

    // 0x8003D270: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x8003D274: swc1        $f2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f2.u32l;
    // 0x8003D278: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8003D27C: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8003D280: nop

    // 0x8003D284: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003D288: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x8003D28C: nop

    // 0x8003D290: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003D294: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x8003D298: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8003D29C: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8003D2A0: sw          $a3, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r7;
    // 0x8003D2A4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003D2A8: nop

    // 0x8003D2AC: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003D2B0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003D2B4: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
    // 0x8003D2B8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8003D2BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D2C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D2C4: nop

    // 0x8003D2C8: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8003D2CC: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8003D2D0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003D2D4: sw          $t7, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r15;
    // 0x8003D2D8: nop

L_8003D2DC:
    // 0x8003D2DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003D2E0:
    // 0x8003D2E0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8003D2E4: jr          $ra
    // 0x8003D2E8: nop

    return;
    // 0x8003D2E8: nop

;}
RECOMP_FUNC void set_ortho_matrix_height(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068160: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80068164: jr          $ra
    // 0x80068168: swc1        $f12, -0x27C4($at)
    MEM_W(-0X27C4, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x80068168: swc1        $f12, -0x27C4($at)
    MEM_W(-0X27C4, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void alSynStartVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9C58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C9C5C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C9C60: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800C9C64: beql        $t6, $zero, L_800C9CD0
    if (ctx->r14 == 0) {
        // 0x800C9C68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9CD0;
    }
    goto skip_0;
    // 0x800C9C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9C6C: jal         0x800658A8
    // 0x800C9C70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9C70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C9C74: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9C78: beq         $v0, $zero, L_800C9CCC
    if (ctx->r2 == 0) {
        // 0x800C9C7C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C9CCC;
    }
    // 0x800C9C7C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9C80: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C9C84: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800C9C88: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x800C9C8C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800C9C90: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800C9C94: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800C9C98: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9C9C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800C9CA0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800C9CA4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800C9CA8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C9CAC: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800C9CB0: lh          $t4, 0x1A($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1A);
    // 0x800C9CB4: sh          $t4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r12;
    // 0x800C9CB8: lw          $t5, 0x8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X8);
    // 0x800C9CBC: lw          $a0, 0xC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC);
    // 0x800C9CC0: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9CC4: jalr        $t9
    // 0x800C9CC8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C9CC8: nop

    after_1:
L_800C9CCC:
    // 0x800C9CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9CD0:
    // 0x800C9CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9CD4: jr          $ra
    // 0x800C9CD8: nop

    return;
    // 0x800C9CD8: nop

;}
RECOMP_FUNC void mtx_perspective(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800682BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800682C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800682C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800682C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800682CC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800682D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800682D4: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    // 0x800682D8: jal         0x800700B4
    // 0x800682DC: addiu       $a1, $a1, -0x2808
    ctx->r5 = ADD32(ctx->r5, -0X2808);
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x800682DC: addiu       $a1, $a1, -0x2808
    ctx->r5 = ADD32(ctx->r5, -0X2808);
    after_0:
    // 0x800682E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800682E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800682E8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800682EC: addiu       $a2, $a2, 0x14A0
    ctx->r6 = ADD32(ctx->r6, 0X14A0);
    // 0x800682F0: addiu       $a1, $a1, 0x1460
    ctx->r5 = ADD32(ctx->r5, 0X1460);
    // 0x800682F4: jal         0x8006F9A8
    // 0x800682F8: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    mtxf_mul(rdram, ctx);
        goto after_1;
    // 0x800682F8: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    after_1:
    // 0x800682FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068300: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x80068304: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80068308: jal         0x800700B4
    // 0x8006830C: addiu       $a1, $a1, -0x27F0
    ctx->r5 = ADD32(ctx->r5, -0X27F0);
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_2;
    // 0x8006830C: addiu       $a1, $a1, -0x27F0
    ctx->r5 = ADD32(ctx->r5, -0X27F0);
    after_2:
    // 0x80068310: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068314: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x80068318: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006831C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80068320: addiu       $a2, $a2, 0x15E0
    ctx->r6 = ADD32(ctx->r6, 0X15E0);
    // 0x80068324: jal         0x8006F9A8
    // 0x80068328: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    mtxf_mul(rdram, ctx);
        goto after_3;
    // 0x80068328: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    after_3:
    // 0x8006832C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80068330: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068334: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80068338: jal         0x8006FAB0
    // 0x8006833C: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    mtxf_to_mtx(rdram, ctx);
        goto after_4;
    // 0x8006833C: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    after_4:
    // 0x80068340: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80068344: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80068348: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8006834C: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x80068350: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80068354: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x80068358: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8006835C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80068360: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80068364: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068368: addu        $t0, $t9, $at
    ctx->r8 = ADD32(ctx->r25, ctx->r1);
    // 0x8006836C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80068370: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80068374: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068378: addiu       $t2, $t1, 0x40
    ctx->r10 = ADD32(ctx->r9, 0X40);
    // 0x8006837C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80068380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068384: sw          $zero, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = 0;
    // 0x80068388: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006838C: sw          $zero, 0x1288($at)
    MEM_W(0X1288, ctx->r1) = 0;
    // 0x80068390: jr          $ra
    // 0x80068394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80068394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80012C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012C30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012C34: jr          $ra
    // 0x80012C38: sh          $zero, -0x4CDC($at)
    MEM_H(-0X4CDC, ctx->r1) = 0;
    return;
    // 0x80012C38: sh          $zero, -0x4CDC($at)
    MEM_H(-0X4CDC, ctx->r1) = 0;
;}
RECOMP_FUNC void mtxs_transform_dir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FDA0: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8006FDA4: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x8006FDA8: lh          $t1, 0x2($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X2);
    // 0x8006FDAC: lh          $t2, 0x4($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X4);
    // 0x8006FDB0: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FDB4: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
    // 0x8006FDB8: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FDBC: nop

    // 0x8006FDC0: nop

    // 0x8006FDC4: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FDC8: lw          $t3, 0x20($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X20);
    // 0x8006FDCC: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FDD0: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FDD4: nop

    // 0x8006FDD8: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FDDC: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x8006FDE0: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FDE4: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FDE8: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FDEC: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FDF0: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x8006FDF4: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8006FDF8: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FDFC: nop

    // 0x8006FE00: nop

    // 0x8006FE04: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FE08: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x8006FE0C: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FE10: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FE14: nop

    // 0x8006FE18: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FE1C: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x8006FE20: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FE24: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FE28: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FE2C: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FE30: sh          $t4, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r12;
    // 0x8006FE34: lw          $t3, 0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X18);
    // 0x8006FE38: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FE3C: nop

    // 0x8006FE40: nop

    // 0x8006FE44: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FE48: lw          $t3, 0x28($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X28);
    // 0x8006FE4C: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FE50: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FE54: nop

    // 0x8006FE58: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FE5C: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FE60: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FE64: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FE68: jr          $ra
    // 0x8006FE6C: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
    return;
    // 0x8006FE6C: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
;}
RECOMP_FUNC void music_channel_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800012A8: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x800012AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800012B0: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x800012B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800012B8: bne         $at, $zero, L_800012C8
    if (ctx->r1 != 0) {
        // 0x800012BC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800012C8;
    }
    // 0x800012BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800012C0: b           L_800012D8
    // 0x800012C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800012D8;
    // 0x800012C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800012C8:
    // 0x800012C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800012CC: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x800012D0: jal         0x80063E40
    // 0x800012D4: nop

    alCSPGetFadeIn(rdram, ctx);
        goto after_0;
    // 0x800012D4: nop

    after_0:
L_800012D8:
    // 0x800012D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800012DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800012E0: jr          $ra
    // 0x800012E4: nop

    return;
    // 0x800012E4: nop

;}
RECOMP_FUNC void obj_loop_buoy_pirateship(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004048C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040490: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80040494: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x80040498: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8004049C: beq         $a3, $zero, L_800404B8
    if (ctx->r7 == 0) {
        // 0x800404A0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800404B8;
    }
    // 0x800404A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800404A4: jal         0x800BF3D4
    // 0x800404A8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    obj_wave_height(rdram, ctx);
        goto after_0;
    // 0x800404A8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800404AC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800404B0: nop

    // 0x800404B4: swc1        $f0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f0.u32l;
L_800404B8:
    // 0x800404B8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800404BC: lh          $t6, 0x18($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X18);
    // 0x800404C0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800404C4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800404C8: sh          $t9, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r25;
    // 0x800404CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800404D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800404D4: jr          $ra
    // 0x800404D8: nop

    return;
    // 0x800404D8: nop

;}
RECOMP_FUNC void obj_loop_hittester(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038208: jal         0x8001F494
    // 0x8003820C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x8003820C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x80038210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038218: jr          $ra
    // 0x8003821C: nop

    return;
    // 0x8003821C: nop

;}
RECOMP_FUNC void set_texture_colour_tag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B7C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007B7C8: jr          $ra
    // 0x8007B7CC: sw          $a0, -0x12C0($at)
    MEM_W(-0X12C0, ctx->r1) = ctx->r4;
    return;
    // 0x8007B7CC: sw          $a0, -0x12C0($at)
    MEM_W(-0X12C0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void sprite_cache_asset_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CCF0: bltz        $a0, L_8007CD0C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007CCF4: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8007CD0C;
    }
    // 0x8007CCF4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007CCF8: lw          $t6, 0x68F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68F8);
    // 0x8007CCFC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007CD00: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007CD04: bne         $at, $zero, L_8007CD14
    if (ctx->r1 != 0) {
        // 0x8007CD08: nop
    
            goto L_8007CD14;
    }
    // 0x8007CD08: nop

L_8007CD0C:
    // 0x8007CD0C: jr          $ra
    // 0x8007CD10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8007CD10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007CD14:
    // 0x8007CD14: lw          $t7, 0x68EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X68EC);
    // 0x8007CD18: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8007CD1C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007CD20: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8007CD24: nop

    // 0x8007CD28: jr          $ra
    // 0x8007CD2C: nop

    return;
    // 0x8007CD2C: nop

;}
RECOMP_FUNC void obj_init_char_select(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038370: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80038374: jr          $ra
    // 0x80038378: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80038378: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void wave_load_material(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA9D8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BA9DC: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800BA9E0: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x800BA9E4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800BA9E8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800BA9EC: bne         $t0, $at, L_800BAA08
    if (ctx->r8 != ctx->r1) {
        // 0x800BA9F0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800BAA08;
    }
    // 0x800BA9F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BA9F4: beq         $a1, $zero, L_800BAA00
    if (ctx->r5 == 0) {
        // 0x800BA9F8: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_800BAA00;
    }
    // 0x800BA9F8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800BA9FC: addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
L_800BAA00:
    // 0x800BAA00: b           L_800BAA44
    // 0x800BAA04: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
        goto L_800BAA44;
    // 0x800BAA04: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
L_800BAA08:
    // 0x800BAA08: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800BAA0C: bne         $t0, $at, L_800BAA34
    if (ctx->r8 != ctx->r1) {
        // 0x800BAA10: lw          $t8, 0x64($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X64);
            goto L_800BAA34;
    }
    // 0x800BAA10: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x800BAA14: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800BAA18: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800BAA1C: beq         $t7, $zero, L_800BAA28
    if (ctx->r15 == 0) {
        // 0x800BAA20: nop
    
            goto L_800BAA28;
    }
    // 0x800BAA20: nop

    // 0x800BAA24: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
L_800BAA28:
    // 0x800BAA28: b           L_800BAA44
    // 0x800BAA2C: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
        goto L_800BAA44;
    // 0x800BAA2C: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x800BAA30: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
L_800BAA34:
    // 0x800BAA34: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800BAA38: beq         $t8, $zero, L_800BAA44
    if (ctx->r24 == 0) {
        // 0x800BAA3C: nop
    
            goto L_800BAA44;
    }
    // 0x800BAA3C: nop

    // 0x800BAA40: addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
L_800BAA44:
    // 0x800BAA44: lbu         $t9, 0x2($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X2);
    // 0x800BAA48: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800BAA4C: andi        $t6, $t9, 0xF
    ctx->r14 = ctx->r25 & 0XF;
    // 0x800BAA50: bne         $t6, $zero, L_800BAC20
    if (ctx->r14 != 0) {
        // 0x800BAA54: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800BAC20;
    }
    // 0x800BAA54: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BAA58: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BAA5C: addiu       $v1, $v1, -0x5A80
    ctx->r3 = ADD32(ctx->r3, -0X5A80);
    // 0x800BAA60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAA64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BAA68: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BAA6C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BAA70: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800BAA74: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800BAA78: addu        $t6, $a3, $at
    ctx->r14 = ADD32(ctx->r7, ctx->r1);
    // 0x800BAA7C: lui         $t8, 0xFD18
    ctx->r24 = S32(0XFD18 << 16);
    // 0x800BAA80: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BAA84: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800BAA88: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAA8C: lui         $at, 0xF518
    ctx->r1 = S32(0XF518 << 16);
    // 0x800BAA90: andi        $t1, $a2, 0x1FF
    ctx->r9 = ctx->r6 & 0X1FF;
    // 0x800BAA94: or          $t8, $t1, $at
    ctx->r24 = ctx->r9 | ctx->r1;
    // 0x800BAA98: andi        $a0, $t4, 0xF
    ctx->r4 = ctx->r12 & 0XF;
    // 0x800BAA9C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BAAA0: multu       $t0, $t0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BAAA4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BAAA8: sll         $t2, $a0, 14
    ctx->r10 = S32(ctx->r4 << 14);
    // 0x800BAAAC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800BAAB0: or          $t9, $t2, $at
    ctx->r25 = ctx->r10 | ctx->r1;
    // 0x800BAAB4: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
    // 0x800BAAB8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800BAABC: or          $t7, $t9, $t3
    ctx->r15 = ctx->r25 | ctx->r11;
    // 0x800BAAC0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800BAAC4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BAAC8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAACC: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800BAAD0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800BAAD4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800BAAD8: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800BAADC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800BAAE0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800BAAE4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800BAAE8: mflo        $a1
    ctx->r5 = lo;
    // 0x800BAAEC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800BAAF0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800BAAF4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BAAF8: sltiu       $at, $a1, 0x7FF
    ctx->r1 = ctx->r5 < 0X7FF ? 1 : 0;
    // 0x800BAAFC: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x800BAB00: beq         $at, $zero, L_800BAB10
    if (ctx->r1 == 0) {
        // 0x800BAB04: sw          $t8, 0x0($t5)
        MEM_W(0X0, ctx->r13) = ctx->r24;
            goto L_800BAB10;
    }
    // 0x800BAB04: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x800BAB08: b           L_800BAB14
    // 0x800BAB0C: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
        goto L_800BAB14;
    // 0x800BAB0C: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
L_800BAB10:
    // 0x800BAB10: addiu       $t4, $zero, 0x7FF
    ctx->r12 = ADD32(0, 0X7FF);
L_800BAB14:
    // 0x800BAB14: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800BAB18: srl         $t9, $v0, 3
    ctx->r25 = S32(U32(ctx->r2) >> 3);
    // 0x800BAB1C: bne         $t9, $zero, L_800BAB2C
    if (ctx->r25 != 0) {
        // 0x800BAB20: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_800BAB2C;
    }
    // 0x800BAB20: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800BAB24: b           L_800BAB30
    // 0x800BAB28: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800BAB30;
    // 0x800BAB28: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800BAB2C:
    // 0x800BAB2C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800BAB30:
    // 0x800BAB30: bne         $v0, $zero, L_800BAB40
    if (ctx->r2 != 0) {
        // 0x800BAB34: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_800BAB40;
    }
    // 0x800BAB34: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x800BAB38: b           L_800BAB44
    // 0x800BAB3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800BAB44;
    // 0x800BAB3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800BAB40:
    // 0x800BAB40: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800BAB44:
    // 0x800BAB44: divu        $zero, $t7, $a2
    lo = S32(U32(ctx->r15) / U32(ctx->r6)); hi = S32(U32(ctx->r15) % U32(ctx->r6));
    // 0x800BAB48: andi        $t7, $t4, 0xFFF
    ctx->r15 = ctx->r12 & 0XFFF;
    // 0x800BAB4C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800BAB50: addiu       $a1, $t0, -0x1
    ctx->r5 = ADD32(ctx->r8, -0X1);
    // 0x800BAB54: bne         $a2, $zero, L_800BAB60
    if (ctx->r6 != 0) {
        // 0x800BAB58: nop
    
            goto L_800BAB60;
    }
    // 0x800BAB58: nop

    // 0x800BAB5C: break       7
    do_break(2148248412);
L_800BAB60:
    // 0x800BAB60: mflo        $t6
    ctx->r14 = lo;
    // 0x800BAB64: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800BAB68: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800BAB6C: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x800BAB70: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x800BAB74: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x800BAB78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAB7C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800BAB80: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BAB84: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BAB88: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800BAB8C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800BAB90: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800BAB94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAB98: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x800BAB9C: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x800BABA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800BABA4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800BABA8: srl         $t6, $t9, 3
    ctx->r14 = S32(U32(ctx->r25) >> 3);
    // 0x800BABAC: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x800BABB0: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x800BABB4: lui         $at, 0xF518
    ctx->r1 = S32(0XF518 << 16);
    // 0x800BABB8: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800BABBC: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x800BABC0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800BABC4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800BABC8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x800BABCC: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800BABD0: andi        $t7, $a0, 0x7
    ctx->r15 = ctx->r4 & 0X7;
    // 0x800BABD4: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x800BABD8: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x800BABDC: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x800BABE0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800BABE4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BABE8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800BABEC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800BABF0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800BABF4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800BABF8: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800BABFC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800BAC00: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800BAC04: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800BAC08: or          $t8, $a0, $t6
    ctx->r24 = ctx->r4 | ctx->r14;
    // 0x800BAC0C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800BAC10: or          $t9, $t8, $t9
    ctx->r25 = ctx->r24 | ctx->r25;
    // 0x800BAC14: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800BAC18: b           L_800BADFC
    // 0x800BAC1C: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
        goto L_800BADFC;
    // 0x800BAC1C: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
L_800BAC20:
    // 0x800BAC20: addiu       $v1, $v1, -0x5A80
    ctx->r3 = ADD32(ctx->r3, -0X5A80);
    // 0x800BAC24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAC28: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BAC2C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800BAC30: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BAC34: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800BAC38: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800BAC3C: addu        $t7, $a3, $at
    ctx->r15 = ADD32(ctx->r7, ctx->r1);
    // 0x800BAC40: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x800BAC44: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BAC48: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800BAC4C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAC50: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x800BAC54: andi        $t1, $a2, 0x1FF
    ctx->r9 = ctx->r6 & 0X1FF;
    // 0x800BAC58: or          $t8, $t1, $at
    ctx->r24 = ctx->r9 | ctx->r1;
    // 0x800BAC5C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800BAC60: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BAC64: andi        $a0, $t4, 0xF
    ctx->r4 = ctx->r12 & 0XF;
    // 0x800BAC68: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800BAC6C: sll         $t2, $a0, 14
    ctx->r10 = S32(ctx->r4 << 14);
    // 0x800BAC70: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800BAC74: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BAC78: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800BAC7C: or          $t9, $t2, $at
    ctx->r25 = ctx->r10 | ctx->r1;
    // 0x800BAC80: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
    // 0x800BAC84: multu       $t0, $t0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BAC88: or          $t6, $t9, $t3
    ctx->r14 = ctx->r25 | ctx->r11;
    // 0x800BAC8C: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x800BAC90: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAC94: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800BAC98: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BAC9C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BACA0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800BACA4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800BACA8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800BACAC: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x800BACB0: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800BACB4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800BACB8: mflo        $a1
    ctx->r5 = lo;
    // 0x800BACBC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800BACC0: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x800BACC4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BACC8: sltiu       $at, $a1, 0x7FF
    ctx->r1 = ctx->r5 < 0X7FF ? 1 : 0;
    // 0x800BACCC: beq         $at, $zero, L_800BACDC
    if (ctx->r1 == 0) {
        // 0x800BACD0: sw          $t9, 0x0($t5)
        MEM_W(0X0, ctx->r13) = ctx->r25;
            goto L_800BACDC;
    }
    // 0x800BACD0: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800BACD4: b           L_800BACE0
    // 0x800BACD8: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
        goto L_800BACE0;
    // 0x800BACD8: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
L_800BACDC:
    // 0x800BACDC: addiu       $t4, $zero, 0x7FF
    ctx->r12 = ADD32(0, 0X7FF);
L_800BACE0:
    // 0x800BACE0: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x800BACE4: srl         $t8, $t6, 3
    ctx->r24 = S32(U32(ctx->r14) >> 3);
    // 0x800BACE8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800BACEC: bne         $t8, $zero, L_800BACFC
    if (ctx->r24 != 0) {
        // 0x800BACF0: sw          $t6, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r14;
            goto L_800BACFC;
    }
    // 0x800BACF0: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x800BACF4: b           L_800BAD00
    // 0x800BACF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800BAD00;
    // 0x800BACF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800BACFC:
    // 0x800BACFC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800BAD00:
    // 0x800BAD00: bne         $v0, $zero, L_800BAD10
    if (ctx->r2 != 0) {
        // 0x800BAD04: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_800BAD10;
    }
    // 0x800BAD04: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x800BAD08: b           L_800BAD14
    // 0x800BAD0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800BAD14;
    // 0x800BAD0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800BAD10:
    // 0x800BAD10: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800BAD14:
    // 0x800BAD14: divu        $zero, $t7, $a2
    lo = S32(U32(ctx->r15) / U32(ctx->r6)); hi = S32(U32(ctx->r15) % U32(ctx->r6));
    // 0x800BAD18: andi        $t7, $t4, 0xFFF
    ctx->r15 = ctx->r12 & 0XFFF;
    // 0x800BAD1C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800BAD20: addiu       $a1, $t0, -0x1
    ctx->r5 = ADD32(ctx->r8, -0X1);
    // 0x800BAD24: bne         $a2, $zero, L_800BAD30
    if (ctx->r6 != 0) {
        // 0x800BAD28: nop
    
            goto L_800BAD30;
    }
    // 0x800BAD28: nop

    // 0x800BAD2C: break       7
    do_break(2148248876);
L_800BAD30:
    // 0x800BAD30: mflo        $t9
    ctx->r25 = lo;
    // 0x800BAD34: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800BAD38: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800BAD3C: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800BAD40: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800BAD44: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x800BAD48: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAD4C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800BAD50: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BAD54: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BAD58: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800BAD5C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BAD60: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800BAD64: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x800BAD68: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800BAD6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAD70: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BAD74: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BAD78: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800BAD7C: srl         $t6, $t9, 3
    ctx->r14 = S32(U32(ctx->r25) >> 3);
    // 0x800BAD80: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BAD84: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800BAD88: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x800BAD8C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800BAD90: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x800BAD94: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800BAD98: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800BAD9C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x800BADA0: nop

    // 0x800BADA4: andi        $t8, $a0, 0x7
    ctx->r24 = ctx->r4 & 0X7;
    // 0x800BADA8: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800BADAC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800BADB0: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x800BADB4: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x800BADB8: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800BADBC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BADC0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800BADC4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800BADC8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800BADCC: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800BADD0: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800BADD4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BADD8: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800BADDC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800BADE0: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800BADE4: or          $t7, $a0, $t6
    ctx->r15 = ctx->r4 | ctx->r14;
    // 0x800BADE8: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800BADEC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800BADF0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BADF4: nop

    // 0x800BADF8: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
L_800BADFC:
    // 0x800BADFC: jr          $ra
    // 0x800BAE00: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BAE00: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800BCC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD190: addiu       $sp, $sp, -0x190
    ctx->r29 = ADD32(ctx->r29, -0X190);
    // 0x800BD194: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800BD198: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800BD19C: addiu       $fp, $fp, -0x5A78
    ctx->r30 = ADD32(ctx->r30, -0X5A78);
    // 0x800BD1A0: lw          $t6, 0x28($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X28);
    // 0x800BD1A4: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800BD1A8: lw          $s4, 0x0($fp)
    ctx->r20 = MEM_W(ctx->r30, 0X0);
    // 0x800BD1AC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800BD1B0: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800BD1B4: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800BD1B8: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800BD1BC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800BD1C0: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800BD1C4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800BD1C8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800BD1CC: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800BD1D0: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x800BD1D4: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800BD1D8: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x800BD1DC: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800BD1E0: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x800BD1E4: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800BD1E8: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800BD1EC: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BD1F0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BD1F4: beq         $t6, $zero, L_800BD204
    if (ctx->r14 == 0) {
        // 0x800BD1F8: sw          $a0, 0x190($sp)
        MEM_W(0X190, ctx->r29) = ctx->r4;
            goto L_800BD204;
    }
    // 0x800BD1F8: sw          $a0, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r4;
    // 0x800BD1FC: sll         $t7, $s4, 1
    ctx->r15 = S32(ctx->r20 << 1);
    // 0x800BD200: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
L_800BD204:
    // 0x800BD204: addiu       $t8, $s4, 0x1
    ctx->r24 = ADD32(ctx->r20, 0X1);
    // 0x800BD208: multu       $t8, $t8
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD20C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800BD210: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BD214: addiu       $s1, $s1, 0x3708
    ctx->r17 = ADD32(ctx->r17, 0X3708);
    // 0x800BD218: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    // 0x800BD21C: mflo        $t6
    ctx->r14 = lo;
    // 0x800BD220: sw          $t6, 0x370C($at)
    MEM_W(0X370C, ctx->r1) = ctx->r14;
    // 0x800BD224: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD228: nop

    // 0x800BD22C: beq         $a0, $zero, L_800BD240
    if (ctx->r4 == 0) {
        // 0x800BD230: lw          $t7, 0x190($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X190);
            goto L_800BD240;
    }
    // 0x800BD230: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x800BD234: jal         0x80071380
    // 0x800BD238: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800BD238: nop

    after_0:
    // 0x800BD23C: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
L_800BD240:
    // 0x800BD240: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BD244: lw          $t9, 0x370C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X370C);
    // 0x800BD248: lh          $t8, 0x1A($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X1A);
    // 0x800BD24C: lui         $s0, 0xFF
    ctx->r16 = S32(0XFF << 16);
    // 0x800BD250: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD254: ori         $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 | 0XFFFF;
    // 0x800BD258: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800BD25C: mflo        $a0
    ctx->r4 = lo;
    // 0x800BD260: jal         0x80070EDC
    // 0x800BD264: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800BD264: nop

    after_1:
    // 0x800BD268: lw          $t6, 0x190($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X190);
    // 0x800BD26C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800BD270: lh          $a0, 0x1A($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X1A);
    // 0x800BD274: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800BD278: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800BD27C: jal         0x80070EDC
    // 0x800BD280: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800BD280: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x800BD284: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BD288: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BD28C: lw          $t9, -0x5964($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5964);
    // 0x800BD290: lw          $t8, -0x5968($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5968);
    // 0x800BD294: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x800BD298: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD29C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800BD2A0: mflo        $a0
    ctx->r4 = lo;
    // 0x800BD2A4: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800BD2A8: jal         0x80070EDC
    // 0x800BD2AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x800BD2AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_3:
    // 0x800BD2B0: sll         $a0, $s4, 2
    ctx->r4 = S32(ctx->r20 << 2);
    // 0x800BD2B4: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800BD2B8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BD2BC: jal         0x80070EDC
    // 0x800BD2C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800BD2C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800BD2C4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BD2C8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BD2CC: lw          $t8, -0x5964($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5964);
    // 0x800BD2D0: lw          $t7, -0x5968($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5968);
    // 0x800BD2D4: lw          $v1, 0xA4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD2D8: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD2DC: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x800BD2E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BD2E4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800BD2E8: addiu       $a1, $s4, 0x1
    ctx->r5 = ADD32(ctx->r20, 0X1);
    // 0x800BD2EC: mflo        $t9
    ctx->r25 = lo;
    // 0x800BD2F0: blez        $t9, L_800BD32C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BD2F4: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_800BD32C;
    }
    // 0x800BD2F4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_800BD2F8:
    // 0x800BD2F8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BD2FC: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800BD300: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BD304: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BD308: lw          $t8, -0x5964($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5964);
    // 0x800BD30C: lw          $t7, -0x5968($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5968);
    // 0x800BD310: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BD314: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD318: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800BD31C: mflo        $t9
    ctx->r25 = lo;
    // 0x800BD320: slt         $at, $a3, $t9
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BD324: bne         $at, $zero, L_800BD2F8
    if (ctx->r1 != 0) {
        // 0x800BD328: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_800BD2F8;
    }
    // 0x800BD328: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_800BD32C:
    // 0x800BD32C: bltz        $s4, L_800BD46C
    if (SIGNED(ctx->r20) < 0) {
        // 0x800BD330: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800BD46C;
    }
    // 0x800BD330: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800BD334: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x800BD338: beq         $t6, $zero, L_800BD3C4
    if (ctx->r14 == 0) {
        // 0x800BD33C: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_800BD3C4;
    }
    // 0x800BD33C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800BD340: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    // 0x800BD344: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800BD348: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800BD34C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800BD350: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x800BD354: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BD358: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x800BD35C: subu        $t9, $s4, $t8
    ctx->r25 = SUB32(ctx->r20, ctx->r24);
    // 0x800BD360: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800BD364: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800BD368: beq         $a0, $t2, L_800BD39C
    if (ctx->r4 == ctx->r10) {
        // 0x800BD36C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800BD39C;
    }
    // 0x800BD36C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
L_800BD370:
    // 0x800BD370: nop

    // 0x800BD374: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800BD378: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800BD37C: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x800BD380: subu        $t9, $s4, $t8
    ctx->r25 = SUB32(ctx->r20, ctx->r24);
    // 0x800BD384: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800BD388: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800BD38C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BD390: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800BD394: bne         $a0, $t2, L_800BD370
    if (ctx->r4 != ctx->r10) {
        // 0x800BD398: swc1        $f16, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
            goto L_800BD370;
    }
    // 0x800BD398: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
L_800BD39C:
    // 0x800BD39C: nop

    // 0x800BD3A0: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800BD3A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BD3A8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800BD3AC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800BD3B0: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800BD3B4: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x800BD3B8: addiu       $t6, $s4, 0x1
    ctx->r14 = ADD32(ctx->r20, 0X1);
    // 0x800BD3BC: beq         $t6, $t2, L_800BD46C
    if (ctx->r14 == ctx->r10) {
        // 0x800BD3C0: nop
    
            goto L_800BD46C;
    }
    // 0x800BD3C0: nop

L_800BD3C4:
    // 0x800BD3C4: mtc1        $s4, $f18
    ctx->f18.u32l = ctx->r20;
    // 0x800BD3C8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800BD3CC: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800BD3D0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800BD3D4: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x800BD3D8: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
L_800BD3DC:
    // 0x800BD3DC: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x800BD3E0: subu        $t9, $s4, $t8
    ctx->r25 = SUB32(ctx->r20, ctx->r24);
    // 0x800BD3E4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800BD3E8: addiu       $t6, $t2, 0x1
    ctx->r14 = ADD32(ctx->r10, 0X1);
    // 0x800BD3EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BD3F0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800BD3F4: subu        $t8, $s4, $t7
    ctx->r24 = SUB32(ctx->r20, ctx->r15);
    // 0x800BD3F8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800BD3FC: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800BD400: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BD404: addiu       $t9, $t2, 0x2
    ctx->r25 = ADD32(ctx->r10, 0X2);
    // 0x800BD408: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800BD40C: subu        $t7, $s4, $t6
    ctx->r15 = SUB32(ctx->r20, ctx->r14);
    // 0x800BD410: addiu       $t8, $t2, 0x3
    ctx->r24 = ADD32(ctx->r10, 0X3);
    // 0x800BD414: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800BD418: subu        $t6, $s4, $t9
    ctx->r14 = SUB32(ctx->r20, ctx->r25);
    // 0x800BD41C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800BD420: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800BD424: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800BD428: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800BD42C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800BD430: addiu       $t7, $s4, 0x1
    ctx->r15 = ADD32(ctx->r20, 0X1);
    // 0x800BD434: swc1        $f10, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f10.u32l;
    // 0x800BD438: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BD43C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800BD440: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800BD444: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BD448: swc1        $f6, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f6.u32l;
    // 0x800BD44C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BD450: nop

    // 0x800BD454: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800BD458: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800BD45C: swc1        $f18, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f18.u32l;
    // 0x800BD460: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800BD464: bne         $t7, $t2, L_800BD3DC
    if (ctx->r15 != ctx->r10) {
        // 0x800BD468: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_800BD3DC;
    }
    // 0x800BD468: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
L_800BD46C:
    // 0x800BD46C: mtc1        $s4, $f16
    ctx->f16.u32l = ctx->r20;
    // 0x800BD470: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BD474: lwc1        $f18, -0x59A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800BD478: lw          $t8, 0x190($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X190);
    // 0x800BD47C: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BD480: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BD484: sw          $zero, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = 0;
    // 0x800BD488: lwc1        $f4, -0x599C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800BD48C: lh          $v0, 0x1A($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X1A);
    // 0x800BD490: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800BD494: div.s       $f26, $f18, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800BD498: blez        $v0, L_800BD794
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BD49C: div.s       $f28, $f4, $f0
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
            goto L_800BD794;
    }
    // 0x800BD49C: div.s       $f28, $f4, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800BD4A0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800BD4A4: addiu       $a2, $a2, 0x3668
    ctx->r6 = ADD32(ctx->r6, 0X3668);
    // 0x800BD4A8: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800BD4AC: addiu       $s0, $sp, 0xAC
    ctx->r16 = ADD32(ctx->r29, 0XAC);
L_800BD4B0:
    // 0x800BD4B0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800BD4B4: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800BD4B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800BD4BC: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
    // 0x800BD4C0: lbu         $a0, 0xB($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0XB);
    // 0x800BD4C4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BD4C8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800BD4CC: lbu         $v1, 0xA($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XA);
    // 0x800BD4D0: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x800BD4D4: lw          $t6, -0x5958($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5958);
    // 0x800BD4D8: sllv        $t8, $t7, $v1
    ctx->r24 = S32(ctx->r15 << (ctx->r3 & 31));
    // 0x800BD4DC: and         $t7, $t8, $t6
    ctx->r15 = ctx->r24 & ctx->r14;
    // 0x800BD4E0: beq         $t7, $zero, L_800BD728
    if (ctx->r15 == 0) {
        // 0x800BD4E4: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_800BD728;
    }
    // 0x800BD4E4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BD4E8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BD4EC: lw          $t6, -0x5968($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5968);
    // 0x800BD4F0: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD4F4: multu       $a0, $t6
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD4F8: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800BD4FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BD500: mflo        $t7
    ctx->r15 = lo;
    // 0x800BD504: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800BD508: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800BD50C: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800BD510: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x800BD514: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800BD518: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x800BD51C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800BD520: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BD524: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x800BD528: lbu         $t9, 0xB($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XB);
    // 0x800BD52C: lw          $t6, -0x5968($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5968);
    // 0x800BD530: nop

    // 0x800BD534: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD538: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD53C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BD540: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800BD544: lbu         $t7, 0xA($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XA);
    // 0x800BD548: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x800BD54C: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x800BD550: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800BD554: sw          $s5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r21;
    // 0x800BD558: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800BD55C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800BD560: nop

    // 0x800BD564: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    // 0x800BD568: lh          $t9, 0x6($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X6);
    // 0x800BD56C: lh          $t8, 0x8($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X8);
    // 0x800BD570: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800BD574: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800BD578: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BD57C: bltz        $s4, L_800BD714
    if (SIGNED(ctx->r20) < 0) {
        // 0x800BD580: cvt.s.w     $f24, $f8
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800BD714;
    }
    // 0x800BD580: cvt.s.w     $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
L_800BD584:
    // 0x800BD584: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800BD588: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800BD58C: nop

    // 0x800BD590: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x800BD594: lh          $t8, 0x4($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X4);
    // 0x800BD598: nop

    // 0x800BD59C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800BD5A0: bltz        $s4, L_800BD704
    if (SIGNED(ctx->r20) < 0) {
        // 0x800BD5A4: cvt.s.w     $f22, $f10
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800BD704;
    }
    // 0x800BD5A4: cvt.s.w     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BD5A8: sw          $v0, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r2;
    // 0x800BD5AC: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x800BD5B0: lw          $s7, 0x90($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X90);
    // 0x800BD5B4: lw          $s3, 0xA8($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA8);
    // 0x800BD5B8: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800BD5BC: sll         $t9, $s7, 2
    ctx->r25 = S32(ctx->r23 << 2);
    // 0x800BD5C0: or          $s7, $t9, $zero
    ctx->r23 = ctx->r25 | 0;
    // 0x800BD5C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BD5C8: addu        $s6, $s3, $t6
    ctx->r22 = ADD32(ctx->r19, ctx->r14);
L_800BD5CC:
    // 0x800BD5CC: lwc1        $f16, 0x0($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800BD5D0: lwc1        $f4, 0x0($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800BD5D4: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x800BD5D8: lw          $a0, 0x18C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18C);
    // 0x800BD5DC: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x800BD5E0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800BD5E4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800BD5E8: jal         0x8002BAF0
    // 0x800BD5EC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    collision_get_y(rdram, ctx);
        goto after_5;
    // 0x800BD5EC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_5:
    // 0x800BD5F0: bne         $v0, $zero, L_800BD600
    if (ctx->r2 != 0) {
        // 0x800BD5F4: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800BD600;
    }
    // 0x800BD5F4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800BD5F8: b           L_800BD6DC
    // 0x800BD5FC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
        goto L_800BD6DC;
    // 0x800BD5FC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_800BD600:
    // 0x800BD600: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x800BD604: blez        $a0, L_800BD650
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BD608: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BD650;
    }
    // 0x800BD608: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BD60C: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BD610: nop

    // 0x800BD614: c.le.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl <= ctx->f8.fl;
    // 0x800BD618: nop

    // 0x800BD61C: bc1f        L_800BD654
    if (!c1cs) {
        // 0x800BD620: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_800BD654;
    }
    // 0x800BD620: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
L_800BD624:
    // 0x800BD624: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD628: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BD62C: beq         $at, $zero, L_800BD650
    if (ctx->r1 == 0) {
        // 0x800BD630: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_800BD650;
    }
    // 0x800BD630: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800BD634: addu        $t7, $s0, $t8
    ctx->r15 = ADD32(ctx->r16, ctx->r24);
    // 0x800BD638: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BD63C: nop

    // 0x800BD640: c.le.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl <= ctx->f10.fl;
    // 0x800BD644: nop

    // 0x800BD648: bc1t        L_800BD624
    if (c1cs) {
        // 0x800BD64C: nop
    
            goto L_800BD624;
    }
    // 0x800BD64C: nop

L_800BD650:
    // 0x800BD650: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
L_800BD654:
    // 0x800BD654: addu        $t9, $s0, $t6
    ctx->r25 = ADD32(ctx->r16, ctx->r14);
    // 0x800BD658: lwc1        $f0, 0x0($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BD65C: nop

    // 0x800BD660: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800BD664: nop

    // 0x800BD668: bc1f        L_800BD678
    if (!c1cs) {
        // 0x800BD66C: nop
    
            goto L_800BD678;
    }
    // 0x800BD66C: nop

    // 0x800BD670: b           L_800BD6DC
    // 0x800BD674: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800BD6DC;
    // 0x800BD674: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800BD678:
    // 0x800BD678: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800BD67C: nop

    // 0x800BD680: bc1f        L_800BD690
    if (!c1cs) {
        // 0x800BD684: nop
    
            goto L_800BD690;
    }
    // 0x800BD684: nop

    // 0x800BD688: b           L_800BD6DC
    // 0x800BD68C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
        goto L_800BD6DC;
    // 0x800BD68C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_800BD690:
    // 0x800BD690: sub.s       $f16, $f20, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x800BD694: lwc1        $f18, 0x48($fp)
    ctx->f18.u32l = MEM_W(ctx->r30, 0X48);
    // 0x800BD698: nop

    // 0x800BD69C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800BD6A0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BD6A4: nop

    // 0x800BD6A8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800BD6AC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BD6B0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BD6B4: nop

    // 0x800BD6B8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800BD6BC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800BD6C0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BD6C4: slti        $at, $a2, 0x200
    ctx->r1 = SIGNED(ctx->r6) < 0X200 ? 1 : 0;
    // 0x800BD6C8: bne         $at, $zero, L_800BD6D8
    if (ctx->r1 != 0) {
        // 0x800BD6CC: sra         $t7, $a2, 1
        ctx->r15 = S32(SIGNED(ctx->r6) >> 1);
            goto L_800BD6D8;
    }
    // 0x800BD6CC: sra         $t7, $a2, 1
    ctx->r15 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD6D0: addiu       $a2, $zero, 0x1FF
    ctx->r6 = ADD32(0, 0X1FF);
    // 0x800BD6D4: sra         $t7, $a2, 1
    ctx->r15 = S32(SIGNED(ctx->r6) >> 1);
L_800BD6D8:
    // 0x800BD6D8: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_800BD6DC:
    // 0x800BD6DC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD6E0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800BD6E4: addu        $t9, $t6, $s5
    ctx->r25 = ADD32(ctx->r14, ctx->r21);
    // 0x800BD6E8: sb          $a2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r6;
    // 0x800BD6EC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800BD6F0: bne         $s7, $s2, L_800BD5CC
    if (ctx->r23 != ctx->r18) {
        // 0x800BD6F4: add.s       $f22, $f22, $f26
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f26.fl;
            goto L_800BD5CC;
    }
    // 0x800BD6F4: add.s       $f22, $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f26.fl;
    // 0x800BD6F8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800BD6FC: lw          $v0, 0x184($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X184);
    // 0x800BD700: addiu       $a2, $a2, 0x3668
    ctx->r6 = ADD32(ctx->r6, 0X3668);
L_800BD704:
    // 0x800BD704: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800BD708: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BD70C: bne         $t8, $v0, L_800BD584
    if (ctx->r24 != ctx->r2) {
        // 0x800BD710: add.s       $f24, $f24, $f28
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f28.fl;
            goto L_800BD584;
    }
    // 0x800BD710: add.s       $f24, $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f28.fl;
L_800BD714:
    // 0x800BD714: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x800BD718: nop

    // 0x800BD71C: lh          $v0, 0x1A($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X1A);
    // 0x800BD720: b           L_800BD774
    // 0x800BD724: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
        goto L_800BD774;
    // 0x800BD724: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
L_800BD728:
    // 0x800BD728: lw          $t6, 0x370C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X370C);
    // 0x800BD72C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800BD730: blez        $t6, L_800BD774
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BD734: lw          $t9, 0x18C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18C);
            goto L_800BD774;
    }
    // 0x800BD734: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
L_800BD738:
    // 0x800BD738: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800BD73C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800BD740: addu        $t7, $t8, $s5
    ctx->r15 = ADD32(ctx->r24, ctx->r21);
    // 0x800BD744: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800BD748: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BD74C: lw          $t6, 0x370C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X370C);
    // 0x800BD750: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800BD754: slt         $at, $t2, $t6
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BD758: bne         $at, $zero, L_800BD738
    if (ctx->r1 != 0) {
        // 0x800BD75C: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800BD738;
    }
    // 0x800BD75C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800BD760: lw          $t8, 0x190($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X190);
    // 0x800BD764: nop

    // 0x800BD768: lh          $v0, 0x1A($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X1A);
    // 0x800BD76C: nop

    // 0x800BD770: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
L_800BD774:
    // 0x800BD774: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800BD778: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800BD77C: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BD780: addiu       $t8, $t6, 0x1C
    ctx->r24 = ADD32(ctx->r14, 0X1C);
    // 0x800BD784: sw          $t8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r24;
    // 0x800BD788: bne         $at, $zero, L_800BD4B0
    if (ctx->r1 != 0) {
        // 0x800BD78C: sw          $t7, 0x18C($sp)
        MEM_W(0X18C, ctx->r29) = ctx->r15;
            goto L_800BD4B0;
    }
    // 0x800BD78C: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800BD790: sw          $zero, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = 0;
L_800BD794:
    // 0x800BD794: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BD798: lw          $v1, -0x5964($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5964);
    // 0x800BD79C: sw          $zero, 0x184($sp)
    MEM_W(0X184, ctx->r29) = 0;
    // 0x800BD7A0: blez        $v1, L_800BDB94
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800BD7A4: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800BDB94;
    }
    // 0x800BD7A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD7A8: lw          $a0, -0x5968($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5968);
    // 0x800BD7AC: nop

L_800BD7B0:
    // 0x800BD7B0: blez        $a0, L_800BDB6C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BD7B4: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800BDB6C;
    }
    // 0x800BD7B4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800BD7B8: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD7BC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BD7C0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800BD7C4:
    // 0x800BD7C4: lw          $t9, 0x184($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X184);
    // 0x800BD7C8: nop

    // 0x800BD7CC: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD7D0: mflo        $t6
    ctx->r14 = lo;
    // 0x800BD7D4: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800BD7D8: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x800BD7DC: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x800BD7E0: lw          $t4, 0x4($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X4);
    // 0x800BD7E4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BD7E8: beq         $t4, $a2, L_800BDB4C
    if (ctx->r12 == ctx->r6) {
        // 0x800BD7EC: nop
    
            goto L_800BDB4C;
    }
    // 0x800BD7EC: nop

    // 0x800BD7F0: lw          $t8, -0x5964($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5964);
    // 0x800BD7F4: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800BD7F8: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x800BD7FC: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BD800: beq         $at, $zero, L_800BD99C
    if (ctx->r1 == 0) {
        // 0x800BD804: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_800BD99C;
    }
    // 0x800BD804: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x800BD808: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD80C: mflo        $t8
    ctx->r24 = lo;
    // 0x800BD810: sll         $t7, $t8, 3
    ctx->r15 = S32(ctx->r24 << 3);
    // 0x800BD814: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x800BD818: addu        $t6, $t9, $t3
    ctx->r14 = ADD32(ctx->r25, ctx->r11);
    // 0x800BD81C: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x800BD820: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800BD824: beq         $v0, $a2, L_800BD99C
    if (ctx->r2 == ctx->r6) {
        // 0x800BD828: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_800BD99C;
    }
    // 0x800BD828: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x800BD82C: multu       $t8, $s4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD830: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800BD834: addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
    // 0x800BD838: addiu       $t1, $s4, -0x1
    ctx->r9 = ADD32(ctx->r20, -0X1);
    // 0x800BD83C: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x800BD840: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BD844: mflo        $t7
    ctx->r15 = lo;
    // 0x800BD848: addu        $a1, $t7, $t4
    ctx->r5 = ADD32(ctx->r15, ctx->r12);
    // 0x800BD84C: blez        $t1, L_800BD998
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800BD850: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800BD998;
    }
    // 0x800BD850: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD854: beq         $t9, $zero, L_800BD8A4
    if (ctx->r25 == 0) {
        // 0x800BD858: or          $t0, $t9, $zero
        ctx->r8 = ctx->r25 | 0;
            goto L_800BD8A4;
    }
    // 0x800BD858: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
L_800BD85C:
    // 0x800BD85C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD860: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BD864: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD868: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD86C: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x800BD870: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD874: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD878: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x800BD87C: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD880: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800BD884: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD888: nop

    // 0x800BD88C: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800BD890: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800BD894: bne         $t0, $a3, L_800BD85C
    if (ctx->r8 != ctx->r7) {
        // 0x800BD898: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800BD85C;
    }
    // 0x800BD898: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD89C: beq         $a3, $t1, L_800BD98C
    if (ctx->r7 == ctx->r9) {
        // 0x800BD8A0: nop
    
            goto L_800BD98C;
    }
    // 0x800BD8A0: nop

L_800BD8A4:
    // 0x800BD8A4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD8A8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800BD8AC: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD8B0: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD8B4: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BD8B8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD8BC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD8C0: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BD8C4: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD8C8: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800BD8CC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BD8D0: nop

    // 0x800BD8D4: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BD8D8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BD8DC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD8E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD8E4: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD8E8: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD8EC: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD8F0: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x800BD8F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD8F8: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x800BD8FC: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD900: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800BD904: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD908: nop

    // 0x800BD90C: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800BD910: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800BD914: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD918: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD91C: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD920: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD924: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD928: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BD92C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD930: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BD934: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD938: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800BD93C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BD940: nop

    // 0x800BD944: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BD948: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BD94C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD950: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD954: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD958: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD95C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD960: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x800BD964: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD968: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x800BD96C: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD970: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800BD974: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD978: nop

    // 0x800BD97C: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800BD980: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800BD984: bne         $a3, $t1, L_800BD8A4
    if (ctx->r7 != ctx->r9) {
        // 0x800BD988: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800BD8A4;
    }
    // 0x800BD988: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800BD98C:
    // 0x800BD98C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD990: lw          $a0, -0x5968($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5968);
    // 0x800BD994: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800BD998:
    // 0x800BD998: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
L_800BD99C:
    // 0x800BD99C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD9A0: slt         $at, $t2, $t7
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BD9A4: beq         $at, $zero, L_800BDB4C
    if (ctx->r1 == 0) {
        // 0x800BD9A8: nop
    
            goto L_800BDB4C;
    }
    // 0x800BD9A8: nop

    // 0x800BD9AC: lw          $t9, 0x184($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X184);
    // 0x800BD9B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BD9B4: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD9B8: addiu       $t1, $s4, -0x1
    ctx->r9 = ADD32(ctx->r20, -0X1);
    // 0x800BD9BC: mflo        $t6
    ctx->r14 = lo;
    // 0x800BD9C0: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800BD9C4: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x800BD9C8: addu        $t9, $t7, $t3
    ctx->r25 = ADD32(ctx->r15, ctx->r11);
    // 0x800BD9CC: lw          $v0, 0xC($t9)
    ctx->r2 = MEM_W(ctx->r25, 0XC);
    // 0x800BD9D0: sll         $t6, $s4, 1
    ctx->r14 = S32(ctx->r20 << 1);
    // 0x800BD9D4: beq         $v0, $a2, L_800BDB4C
    if (ctx->r2 == ctx->r6) {
        // 0x800BD9D8: addu        $a1, $t6, $t4
        ctx->r5 = ADD32(ctx->r14, ctx->r12);
            goto L_800BDB4C;
    }
    // 0x800BD9D8: addu        $a1, $t6, $t4
    ctx->r5 = ADD32(ctx->r14, ctx->r12);
    // 0x800BD9DC: addu        $v1, $v0, $s4
    ctx->r3 = ADD32(ctx->r2, ctx->r20);
    // 0x800BD9E0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD9E4: blez        $t1, L_800BDB4C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800BD9E8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800BDB4C;
    }
    // 0x800BD9E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD9EC: addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
    // 0x800BD9F0: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x800BD9F4: beq         $t8, $zero, L_800BDA48
    if (ctx->r24 == 0) {
        // 0x800BD9F8: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_800BDA48;
    }
    // 0x800BD9F8: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
L_800BD9FC:
    // 0x800BD9FC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BDA00: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDA04: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BDA08: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x800BDA0C: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BDA10: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800BDA14: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // 0x800BDA18: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BDA1C: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BDA20: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800BDA24: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BDA28: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BDA2C: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BDA30: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800BDA34: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BDA38: bne         $t0, $a3, L_800BD9FC
    if (ctx->r8 != ctx->r7) {
        // 0x800BDA3C: sb          $t8, 0x0($t9)
        MEM_B(0X0, ctx->r25) = ctx->r24;
            goto L_800BD9FC;
    }
    // 0x800BDA3C: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BDA40: beq         $a3, $t1, L_800BDB40
    if (ctx->r7 == ctx->r9) {
        // 0x800BDA44: nop
    
            goto L_800BDB40;
    }
    // 0x800BDA44: nop

L_800BDA48:
    // 0x800BDA48: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BDA4C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800BDA50: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BDA54: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x800BDA58: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x800BDA5C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800BDA60: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // 0x800BDA64: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x800BDA68: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BDA6C: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800BDA70: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BDA74: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BDA78: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800BDA7C: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800BDA80: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BDA84: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800BDA88: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BDA8C: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x800BDA90: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BDA94: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800BDA98: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BDA9C: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // 0x800BDAA0: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BDAA4: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BDAA8: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800BDAAC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BDAB0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BDAB4: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BDAB8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BDABC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BDAC0: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800BDAC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BDAC8: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x800BDACC: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BDAD0: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800BDAD4: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x800BDAD8: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // 0x800BDADC: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x800BDAE0: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BDAE4: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800BDAE8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BDAEC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BDAF0: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800BDAF4: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800BDAF8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BDAFC: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800BDB00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BDB04: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x800BDB08: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BDB0C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800BDB10: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BDB14: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // 0x800BDB18: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BDB1C: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BDB20: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800BDB24: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BDB28: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BDB2C: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BDB30: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800BDB34: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BDB38: bne         $a3, $t1, L_800BDA48
    if (ctx->r7 != ctx->r9) {
        // 0x800BDB3C: sb          $t8, 0x0($t9)
        MEM_B(0X0, ctx->r25) = ctx->r24;
            goto L_800BDA48;
    }
    // 0x800BDB3C: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
L_800BDB40:
    // 0x800BDB40: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BDB44: lw          $a0, -0x5968($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5968);
    // 0x800BDB48: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800BDB4C:
    // 0x800BDB4C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800BDB50: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BDB54: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800BDB58: bne         $at, $zero, L_800BD7C4
    if (ctx->r1 != 0) {
        // 0x800BDB5C: addiu       $t3, $t3, 0x8
        ctx->r11 = ADD32(ctx->r11, 0X8);
            goto L_800BD7C4;
    }
    // 0x800BDB5C: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x800BDB60: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BDB64: lw          $v1, -0x5964($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5964);
    // 0x800BDB68: nop

L_800BDB6C:
    // 0x800BDB6C: lw          $t6, 0x184($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X184);
    // 0x800BDB70: nop

    // 0x800BDB74: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800BDB78: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BDB7C: bne         $at, $zero, L_800BD7B0
    if (ctx->r1 != 0) {
        // 0x800BDB80: sw          $t8, 0x184($sp)
        MEM_W(0X184, ctx->r29) = ctx->r24;
            goto L_800BD7B0;
    }
    // 0x800BDB80: sw          $t8, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r24;
    // 0x800BDB84: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x800BDB88: nop

    // 0x800BDB8C: lh          $v0, 0x1A($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X1A);
    // 0x800BDB90: nop

L_800BDB94:
    // 0x800BDB94: blez        $v0, L_800BDC5C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BDB98: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_800BDC5C;
    }
    // 0x800BDB98: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800BDB9C: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x800BDBA0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BDBA4: multu       $t9, $t9
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDBA8: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x800BDBAC: lw          $a0, 0x190($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X190);
    // 0x800BDBB0: addiu       $v1, $v1, 0x370C
    ctx->r3 = ADD32(ctx->r3, 0X370C);
    // 0x800BDBB4: mflo        $ra
    ctx->r31 = lo;
    // 0x800BDBB8: nop

    // 0x800BDBBC: nop

    // 0x800BDBC0: multu       $t9, $s4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDBC4: mflo        $t5
    ctx->r13 = lo;
    // 0x800BDBC8: nop

    // 0x800BDBCC: nop

L_800BDBD0:
    // 0x800BDBD0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BDBD4: addu        $t9, $t4, $s4
    ctx->r25 = ADD32(ctx->r12, ctx->r20);
    // 0x800BDBD8: addu        $t8, $t6, $t4
    ctx->r24 = ADD32(ctx->r14, ctx->r12);
    // 0x800BDBDC: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x800BDBE0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800BDBE4: sb          $t7, -0x4($t0)
    MEM_B(-0X4, ctx->r8) = ctx->r15;
    // 0x800BDBE8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BDBEC: nop

    // 0x800BDBF0: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800BDBF4: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x800BDBF8: addu        $t9, $t5, $t4
    ctx->r25 = ADD32(ctx->r13, ctx->r12);
    // 0x800BDBFC: sb          $t7, -0x3($t0)
    MEM_B(-0X3, ctx->r8) = ctx->r15;
    // 0x800BDC00: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BDC04: nop

    // 0x800BDC08: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800BDC0C: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x800BDC10: addu        $t9, $ra, $t4
    ctx->r25 = ADD32(ctx->r31, ctx->r12);
    // 0x800BDC14: sb          $t7, -0x2($t0)
    MEM_B(-0X2, ctx->r8) = ctx->r15;
    // 0x800BDC18: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BDC1C: nop

    // 0x800BDC20: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800BDC24: lbu         $t7, -0x1($t8)
    ctx->r15 = MEM_BU(ctx->r24, -0X1);
    // 0x800BDC28: nop

    // 0x800BDC2C: sb          $t7, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r15;
    // 0x800BDC30: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800BDC34: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800BDC38: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800BDC3C: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800BDC40: lh          $v0, 0x1A($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X1A);
    // 0x800BDC44: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x800BDC48: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BDC4C: bne         $at, $zero, L_800BDBD0
    if (ctx->r1 != 0) {
        // 0x800BDC50: nop
    
            goto L_800BDBD0;
    }
    // 0x800BDC50: nop

    // 0x800BDC54: sw          $zero, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = 0;
    // 0x800BDC58: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_800BDC5C:
    // 0x800BDC5C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BDC60: blez        $v0, L_800BE124
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BDC64: addiu       $v1, $v1, 0x370C
        ctx->r3 = ADD32(ctx->r3, 0X370C);
            goto L_800BE124;
    }
    // 0x800BDC64: addiu       $v1, $v1, 0x370C
    ctx->r3 = ADD32(ctx->r3, 0X370C);
    // 0x800BDC68: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800BDC6C: addiu       $t1, $sp, 0x160
    ctx->r9 = ADD32(ctx->r29, 0X160);
L_800BDC70:
    // 0x800BDC70: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800BDC74: lw          $t7, 0x3668($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3668);
    // 0x800BDC78: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x800BDC7C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BDC80: addu        $a1, $t7, $t9
    ctx->r5 = ADD32(ctx->r15, ctx->r25);
    // 0x800BDC84: lbu         $t6, 0xB($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XB);
    // 0x800BDC88: lw          $a0, -0x5968($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5968);
    // 0x800BDC8C: lbu         $t8, 0xA($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XA);
    // 0x800BDC90: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDC94: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x800BDC98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDC9C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BDCA0: addu        $s5, $t8, $t7
    ctx->r21 = ADD32(ctx->r24, ctx->r15);
    // 0x800BDCA4: sll         $t6, $s5, 3
    ctx->r14 = S32(ctx->r21 << 3);
    // 0x800BDCA8: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BDCAC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800BDCB0: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x800BDCB4: beq         $t8, $at, L_800BE0FC
    if (ctx->r24 == ctx->r1) {
        // 0x800BDCB8: nop
    
            goto L_800BE0FC;
    }
    // 0x800BDCB8: nop

    // 0x800BDCBC: multu       $t7, $t7
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDCC0: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800BDCC4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BDCC8: lw          $t3, -0x5964($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5964);
    // 0x800BDCCC: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x800BDCD0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800BDCD4: addiu       $t2, $a0, -0x1
    ctx->r10 = ADD32(ctx->r4, -0X1);
    // 0x800BDCD8: addiu       $v0, $sp, 0x140
    ctx->r2 = ADD32(ctx->r29, 0X140);
    // 0x800BDCDC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800BDCE0: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x800BDCE4: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x800BDCE8: mflo        $ra
    ctx->r31 = lo;
    // 0x800BDCEC: nop

    // 0x800BDCF0: nop

    // 0x800BDCF4: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDCF8: mflo        $t5
    ctx->r13 = lo;
    // 0x800BDCFC: nop

    // 0x800BDD00: nop

L_800BDD04:
    // 0x800BDD04: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BDD08: sltu        $at, $v0, $t1
    ctx->r1 = ctx->r2 < ctx->r9 ? 1 : 0;
    // 0x800BDD0C: bne         $at, $zero, L_800BDD04
    if (ctx->r1 != 0) {
        // 0x800BDD10: sw          $v1, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r3;
            goto L_800BDD04;
    }
    // 0x800BDD10: sw          $v1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r3;
    // 0x800BDD14: lbu         $t7, 0xB($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XB);
    // 0x800BDD18: nop

    // 0x800BDD1C: blez        $t7, L_800BDD94
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800BDD20: nop
    
            goto L_800BDD94;
    }
    // 0x800BDD20: nop

    // 0x800BDD24: lbu         $t6, 0xA($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XA);
    // 0x800BDD28: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x800BDD2C: blez        $t6, L_800BDD50
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BDD30: sll         $t8, $s5, 3
        ctx->r24 = S32(ctx->r21 << 3);
            goto L_800BDD50;
    }
    // 0x800BDD30: sll         $t8, $s5, 3
    ctx->r24 = S32(ctx->r21 << 3);
    // 0x800BDD34: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x800BDD38: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800BDD3C: negu        $t9, $t6
    ctx->r25 = SUB32(0, ctx->r14);
    // 0x800BDD40: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800BDD44: lw          $t6, -0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X8);
    // 0x800BDD48: nop

    // 0x800BDD4C: sw          $t6, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r14;
L_800BDD50:
    // 0x800BDD50: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x800BDD54: sll         $t9, $s5, 3
    ctx->r25 = S32(ctx->r21 << 3);
    // 0x800BDD58: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800BDD5C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800BDD60: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800BDD64: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x800BDD68: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800BDD6C: nop

    // 0x800BDD70: sw          $t9, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r25;
    // 0x800BDD74: lbu         $t6, 0xA($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XA);
    // 0x800BDD78: nop

    // 0x800BDD7C: slt         $at, $t6, $t2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BDD80: beq         $at, $zero, L_800BDD94
    if (ctx->r1 == 0) {
        // 0x800BDD84: nop
    
            goto L_800BDD94;
    }
    // 0x800BDD84: nop

    // 0x800BDD88: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x800BDD8C: nop

    // 0x800BDD90: sw          $t8, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r24;
L_800BDD94:
    // 0x800BDD94: lbu         $v1, 0xA($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XA);
    // 0x800BDD98: nop

    // 0x800BDD9C: blez        $v1, L_800BDDBC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800BDDA0: slt         $at, $v1, $t2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800BDDBC;
    }
    // 0x800BDDA0: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BDDA4: lw          $t7, -0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, -0X8);
    // 0x800BDDA8: nop

    // 0x800BDDAC: sw          $t7, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r15;
    // 0x800BDDB0: lbu         $v1, 0xA($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XA);
    // 0x800BDDB4: nop

    // 0x800BDDB8: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
L_800BDDBC:
    // 0x800BDDBC: beq         $at, $zero, L_800BDDD0
    if (ctx->r1 == 0) {
        // 0x800BDDC0: sll         $v1, $a0, 3
        ctx->r3 = S32(ctx->r4 << 3);
            goto L_800BDDD0;
    }
    // 0x800BDDC0: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x800BDDC4: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800BDDC8: nop

    // 0x800BDDCC: sw          $t9, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r25;
L_800BDDD0:
    // 0x800BDDD0: lbu         $t6, 0xB($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XB);
    // 0x800BDDD4: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x800BDDD8: slt         $at, $t6, $t3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BDDDC: beq         $at, $zero, L_800BDE34
    if (ctx->r1 == 0) {
        // 0x800BDDE0: nop
    
            goto L_800BDE34;
    }
    // 0x800BDDE0: nop

    // 0x800BDDE4: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x800BDDE8: sll         $t7, $s5, 3
    ctx->r15 = S32(ctx->r21 << 3);
    // 0x800BDDEC: blez        $t9, L_800BDE04
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BDDF0: addu        $v0, $t8, $t7
        ctx->r2 = ADD32(ctx->r24, ctx->r15);
            goto L_800BDE04;
    }
    // 0x800BDDF0: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x800BDDF4: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    // 0x800BDDF8: lw          $t8, -0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X8);
    // 0x800BDDFC: nop

    // 0x800BDE00: sw          $t8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r24;
L_800BDE04:
    // 0x800BDE04: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x800BDE08: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800BDE0C: nop

    // 0x800BDE10: sw          $t7, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r15;
    // 0x800BDE14: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x800BDE18: nop

    // 0x800BDE1C: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BDE20: beq         $at, $zero, L_800BDE38
    if (ctx->r1 == 0) {
        // 0x800BDE24: lw          $t8, 0x140($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X140);
            goto L_800BDE38;
    }
    // 0x800BDE24: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x800BDE28: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800BDE2C: nop

    // 0x800BDE30: sw          $t6, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r14;
L_800BDE34:
    // 0x800BDE34: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
L_800BDE38:
    // 0x800BDE38: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800BDE3C: lbu         $a2, 0x0($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X0);
    // 0x800BDE40: beq         $a0, $t8, L_800BDE60
    if (ctx->r4 == ctx->r24) {
        // 0x800BDE44: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800BDE60;
    }
    // 0x800BDE44: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800BDE48: lw          $v1, 0xA0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA0);
    // 0x800BDE4C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BDE50: addu        $t9, $v1, $t7
    ctx->r25 = ADD32(ctx->r3, ctx->r15);
    // 0x800BDE54: lbu         $t6, 0x3($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X3);
    // 0x800BDE58: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800BDE5C: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
L_800BDE60:
    // 0x800BDE60: lw          $t8, 0x144($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X144);
    // 0x800BDE64: lw          $v1, 0xA0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA0);
    // 0x800BDE68: beq         $a0, $t8, L_800BDE84
    if (ctx->r4 == ctx->r24) {
        // 0x800BDE6C: nop
    
            goto L_800BDE84;
    }
    // 0x800BDE6C: nop

    // 0x800BDE70: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BDE74: addu        $t9, $v1, $t7
    ctx->r25 = ADD32(ctx->r3, ctx->r15);
    // 0x800BDE78: lbu         $t6, 0x2($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X2);
    // 0x800BDE7C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDE80: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
L_800BDE84:
    // 0x800BDE84: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x800BDE88: nop

    // 0x800BDE8C: beq         $a0, $t8, L_800BDEA8
    if (ctx->r4 == ctx->r24) {
        // 0x800BDE90: nop
    
            goto L_800BDEA8;
    }
    // 0x800BDE90: nop

    // 0x800BDE94: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BDE98: addu        $t9, $v1, $t7
    ctx->r25 = ADD32(ctx->r3, ctx->r15);
    // 0x800BDE9C: lbu         $t6, 0x1($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X1);
    // 0x800BDEA0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDEA4: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
L_800BDEA8:
    // 0x800BDEA8: div         $zero, $a2, $a3
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r7)));
    // 0x800BDEAC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BDEB0: bne         $a3, $zero, L_800BDEBC
    if (ctx->r7 != 0) {
        // 0x800BDEB4: nop
    
            goto L_800BDEBC;
    }
    // 0x800BDEB4: nop

    // 0x800BDEB8: break       7
    do_break(2148261560);
L_800BDEBC:
    // 0x800BDEBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDEC0: bne         $a3, $at, L_800BDED4
    if (ctx->r7 != ctx->r1) {
        // 0x800BDEC4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BDED4;
    }
    // 0x800BDEC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BDEC8: bne         $a2, $at, L_800BDED4
    if (ctx->r6 != ctx->r1) {
        // 0x800BDECC: nop
    
            goto L_800BDED4;
    }
    // 0x800BDECC: nop

    // 0x800BDED0: break       6
    do_break(2148261584);
L_800BDED4:
    // 0x800BDED4: addu        $t9, $t7, $t4
    ctx->r25 = ADD32(ctx->r15, ctx->r12);
    // 0x800BDED8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800BDEDC: mflo        $t8
    ctx->r24 = lo;
    // 0x800BDEE0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BDEE4: lw          $t6, 0x144($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X144);
    // 0x800BDEE8: lbu         $a2, 0x1($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X1);
    // 0x800BDEEC: beq         $a0, $t6, L_800BDF08
    if (ctx->r4 == ctx->r14) {
        // 0x800BDEF0: nop
    
            goto L_800BDF08;
    }
    // 0x800BDEF0: nop

    // 0x800BDEF4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BDEF8: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800BDEFC: lbu         $t9, 0x3($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3);
    // 0x800BDF00: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800BDF04: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDF08:
    // 0x800BDF08: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x800BDF0C: nop

    // 0x800BDF10: beq         $a0, $t6, L_800BDF2C
    if (ctx->r4 == ctx->r14) {
        // 0x800BDF14: nop
    
            goto L_800BDF2C;
    }
    // 0x800BDF14: nop

    // 0x800BDF18: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BDF1C: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800BDF20: lbu         $t9, 0x2($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2);
    // 0x800BDF24: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDF28: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDF2C:
    // 0x800BDF2C: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x800BDF30: nop

    // 0x800BDF34: beq         $a0, $t6, L_800BDF50
    if (ctx->r4 == ctx->r14) {
        // 0x800BDF38: nop
    
            goto L_800BDF50;
    }
    // 0x800BDF38: nop

    // 0x800BDF3C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BDF40: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800BDF44: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800BDF48: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDF4C: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDF50:
    // 0x800BDF50: div         $zero, $a2, $a3
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r7)));
    // 0x800BDF54: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BDF58: bne         $a3, $zero, L_800BDF64
    if (ctx->r7 != 0) {
        // 0x800BDF5C: nop
    
            goto L_800BDF64;
    }
    // 0x800BDF5C: nop

    // 0x800BDF60: break       7
    do_break(2148261728);
L_800BDF64:
    // 0x800BDF64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDF68: bne         $a3, $at, L_800BDF7C
    if (ctx->r7 != ctx->r1) {
        // 0x800BDF6C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BDF7C;
    }
    // 0x800BDF6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BDF70: bne         $a2, $at, L_800BDF7C
    if (ctx->r6 != ctx->r1) {
        // 0x800BDF74: nop
    
            goto L_800BDF7C;
    }
    // 0x800BDF74: nop

    // 0x800BDF78: break       6
    do_break(2148261752);
L_800BDF7C:
    // 0x800BDF7C: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x800BDF80: addu        $t9, $t8, $s4
    ctx->r25 = ADD32(ctx->r24, ctx->r20);
    // 0x800BDF84: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800BDF88: mflo        $t6
    ctx->r14 = lo;
    // 0x800BDF8C: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800BDF90: lw          $t7, 0x14C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14C);
    // 0x800BDF94: lbu         $a2, 0x2($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X2);
    // 0x800BDF98: beq         $a0, $t7, L_800BDFB4
    if (ctx->r4 == ctx->r15) {
        // 0x800BDF9C: nop
    
            goto L_800BDFB4;
    }
    // 0x800BDF9C: nop

    // 0x800BDFA0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BDFA4: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x800BDFA8: lbu         $t9, 0x3($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X3);
    // 0x800BDFAC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800BDFB0: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDFB4:
    // 0x800BDFB4: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x800BDFB8: nop

    // 0x800BDFBC: beq         $a0, $t7, L_800BDFD8
    if (ctx->r4 == ctx->r15) {
        // 0x800BDFC0: nop
    
            goto L_800BDFD8;
    }
    // 0x800BDFC0: nop

    // 0x800BDFC4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BDFC8: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x800BDFCC: lbu         $t9, 0x1($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X1);
    // 0x800BDFD0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDFD4: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDFD8:
    // 0x800BDFD8: lw          $t7, 0x158($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X158);
    // 0x800BDFDC: nop

    // 0x800BDFE0: beq         $a0, $t7, L_800BDFFC
    if (ctx->r4 == ctx->r15) {
        // 0x800BDFE4: nop
    
            goto L_800BDFFC;
    }
    // 0x800BDFE4: nop

    // 0x800BDFE8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BDFEC: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x800BDFF0: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
    // 0x800BDFF4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDFF8: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDFFC:
    // 0x800BDFFC: div         $zero, $a2, $a3
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r7)));
    // 0x800BE000: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800BE004: bne         $a3, $zero, L_800BE010
    if (ctx->r7 != 0) {
        // 0x800BE008: nop
    
            goto L_800BE010;
    }
    // 0x800BE008: nop

    // 0x800BE00C: break       7
    do_break(2148261900);
L_800BE010:
    // 0x800BE010: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BE014: bne         $a3, $at, L_800BE028
    if (ctx->r7 != ctx->r1) {
        // 0x800BE018: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BE028;
    }
    // 0x800BE018: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE01C: bne         $a2, $at, L_800BE028
    if (ctx->r6 != ctx->r1) {
        // 0x800BE020: nop
    
            goto L_800BE028;
    }
    // 0x800BE020: nop

    // 0x800BE024: break       6
    do_break(2148261924);
L_800BE028:
    // 0x800BE028: addu        $t6, $t8, $t4
    ctx->r14 = ADD32(ctx->r24, ctx->r12);
    // 0x800BE02C: addu        $t9, $t6, $t5
    ctx->r25 = ADD32(ctx->r14, ctx->r13);
    // 0x800BE030: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800BE034: mflo        $t7
    ctx->r15 = lo;
    // 0x800BE038: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x800BE03C: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x800BE040: lbu         $a2, 0x3($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X3);
    // 0x800BE044: beq         $a0, $t8, L_800BE060
    if (ctx->r4 == ctx->r24) {
        // 0x800BE048: nop
    
            goto L_800BE060;
    }
    // 0x800BE048: nop

    // 0x800BE04C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800BE050: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800BE054: lbu         $t9, 0x2($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X2);
    // 0x800BE058: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800BE05C: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BE060:
    // 0x800BE060: lw          $t8, 0x158($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X158);
    // 0x800BE064: nop

    // 0x800BE068: beq         $a0, $t8, L_800BE084
    if (ctx->r4 == ctx->r24) {
        // 0x800BE06C: nop
    
            goto L_800BE084;
    }
    // 0x800BE06C: nop

    // 0x800BE070: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800BE074: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800BE078: lbu         $t9, 0x1($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X1);
    // 0x800BE07C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BE080: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BE084:
    // 0x800BE084: lw          $t8, 0x15C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X15C);
    // 0x800BE088: nop

    // 0x800BE08C: beq         $a0, $t8, L_800BE0A8
    if (ctx->r4 == ctx->r24) {
        // 0x800BE090: nop
    
            goto L_800BE0A8;
    }
    // 0x800BE090: nop

    // 0x800BE094: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800BE098: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800BE09C: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BE0A0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BE0A4: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BE0A8:
    // 0x800BE0A8: div         $zero, $a2, $a3
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r7)));
    // 0x800BE0AC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BE0B0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BE0B4: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x800BE0B8: addu        $t9, $t7, $ra
    ctx->r25 = ADD32(ctx->r15, ctx->r31);
    // 0x800BE0BC: addiu       $v1, $v1, 0x370C
    ctx->r3 = ADD32(ctx->r3, 0X370C);
    // 0x800BE0C0: bne         $a3, $zero, L_800BE0CC
    if (ctx->r7 != 0) {
        // 0x800BE0C4: nop
    
            goto L_800BE0CC;
    }
    // 0x800BE0C4: nop

    // 0x800BE0C8: break       7
    do_break(2148262088);
L_800BE0CC:
    // 0x800BE0CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BE0D0: bne         $a3, $at, L_800BE0E4
    if (ctx->r7 != ctx->r1) {
        // 0x800BE0D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BE0E4;
    }
    // 0x800BE0D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE0D8: bne         $a2, $at, L_800BE0E4
    if (ctx->r6 != ctx->r1) {
        // 0x800BE0DC: nop
    
            goto L_800BE0E4;
    }
    // 0x800BE0DC: nop

    // 0x800BE0E0: break       6
    do_break(2148262112);
L_800BE0E4:
    // 0x800BE0E4: mflo        $t8
    ctx->r24 = lo;
    // 0x800BE0E8: sb          $t8, -0x1($t9)
    MEM_B(-0X1, ctx->r25) = ctx->r24;
    // 0x800BE0EC: lw          $t6, 0x190($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X190);
    // 0x800BE0F0: nop

    // 0x800BE0F4: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x800BE0F8: nop

L_800BE0FC:
    // 0x800BE0FC: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800BE100: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x800BE104: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BE108: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800BE10C: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BE110: addiu       $t6, $t9, 0x1C
    ctx->r14 = ADD32(ctx->r25, 0X1C);
    // 0x800BE114: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
    // 0x800BE118: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800BE11C: bne         $at, $zero, L_800BDC70
    if (ctx->r1 != 0) {
        // 0x800BE120: addu        $t4, $t4, $t7
        ctx->r12 = ADD32(ctx->r12, ctx->r15);
            goto L_800BDC70;
    }
    // 0x800BE120: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
L_800BE124:
    // 0x800BE124: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BE128: jal         0x80071380
    // 0x800BE12C: nop

    mempool_free(rdram, ctx);
        goto after_6;
    // 0x800BE12C: nop

    after_6:
    // 0x800BE130: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    // 0x800BE134: jal         0x80071380
    // 0x800BE138: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x800BE138: nop

    after_7:
    // 0x800BE13C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800BE140: jal         0x80071380
    // 0x800BE144: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x800BE144: nop

    after_8:
    // 0x800BE148: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800BE14C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800BE150: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BE154: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BE158: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BE15C: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800BE160: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BE164: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800BE168: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800BE16C: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800BE170: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800BE174: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800BE178: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800BE17C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800BE180: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800BE184: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800BE188: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800BE18C: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800BE190: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800BE194: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800BE198: jr          $ra
    // 0x800BE19C: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
    return;
    // 0x800BE19C: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
;}
RECOMP_FUNC void music_channel_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001114: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80001118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000111C: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80001120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001124: beq         $at, $zero, L_8000113C
    if (ctx->r1 == 0) {
        // 0x80001128: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8000113C;
    }
    // 0x80001128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000112C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001130: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001134: jal         0x80063D30
    // 0x80001138: nop

    alSeqChOff(rdram, ctx);
        goto after_0;
    // 0x80001138: nop

    after_0:
L_8000113C:
    // 0x8000113C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001144: jr          $ra
    // 0x80001148: nop

    return;
    // 0x80001148: nop

;}
RECOMP_FUNC void obj_loop_setuppoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800391FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80039200: jr          $ra
    // 0x80039204: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80039204: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void hud_wrong_way(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5FAC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5FB0: lw          $t6, 0x72CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72CC);
    // 0x800A5FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5FB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A5FBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5FC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A5FC4: bne         $a2, $t6, L_800A5FD4
    if (ctx->r6 != ctx->r14) {
        // 0x800A5FC8: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800A5FD4;
    }
    // 0x800A5FC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A5FCC: jal         0x8007C36C
    // 0x800A5FD0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    sprite_opaque(rdram, ctx);
        goto after_0;
    // 0x800A5FD0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
L_800A5FD4:
    // 0x800A5FD4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800A5FD8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A5FDC: lbu         $t8, 0x1FC($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1FC);
    // 0x800A5FE0: nop

    // 0x800A5FE4: slti        $at, $t8, 0x79
    ctx->r1 = SIGNED(ctx->r24) < 0X79 ? 1 : 0;
    // 0x800A5FE8: bne         $at, $zero, L_800A6108
    if (ctx->r1 != 0) {
        // 0x800A5FEC: nop
    
            goto L_800A6108;
    }
    // 0x800A5FEC: nop

    // 0x800A5FF0: lw          $t9, 0x72CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72CC);
    // 0x800A5FF4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5FF8: bne         $t9, $zero, L_800A602C
    if (ctx->r25 != 0) {
        // 0x800A5FFC: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A602C;
    }
    // 0x800A5FFC: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A6000: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A6004: nop

    // 0x800A6008: lb          $t1, 0x47C($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X47C);
    // 0x800A600C: lwc1        $f4, 0x46C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x800A6010: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800A6014: nop

    // 0x800A6018: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A601C: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x800A6020: nop

    // 0x800A6024: bc1f        L_800A6108
    if (!c1cs) {
        // 0x800A6028: nop
    
            goto L_800A6108;
    }
    // 0x800A6028: nop

L_800A602C:
    // 0x800A602C: jal         0x8006ECE0
    // 0x800A6030: nop

    is_game_paused(rdram, ctx);
        goto after_1;
    // 0x800A6030: nop

    after_1:
    // 0x800A6034: bne         $v0, $zero, L_800A6108
    if (ctx->r2 != 0) {
        // 0x800A6038: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800A6108;
    }
    // 0x800A6038: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A603C: addiu       $v1, $v1, 0x72F8
    ctx->r3 = ADD32(ctx->r3, 0X72F8);
    // 0x800A6040: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800A6044: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A6048: bne         $v0, $zero, L_800A605C
    if (ctx->r2 != 0) {
        // 0x800A604C: addiu       $a3, $a3, 0x732C
        ctx->r7 = ADD32(ctx->r7, 0X732C);
            goto L_800A605C;
    }
    // 0x800A604C: addiu       $a3, $a3, 0x732C
    ctx->r7 = ADD32(ctx->r7, 0X732C);
    // 0x800A6050: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800A6054: nop

    // 0x800A6058: bne         $t2, $zero, L_800A60EC
    if (ctx->r10 != 0) {
        // 0x800A605C: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_800A60EC;
    }
L_800A605C:
    // 0x800A605C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A6060: addiu       $a2, $a2, 0x7300
    ctx->r6 = ADD32(ctx->r6, 0X7300);
    // 0x800A6064: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800A6068: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A606C: bne         $t3, $zero, L_800A60EC
    if (ctx->r11 != 0) {
        // 0x800A6070: addiu       $a3, $a3, 0x732C
        ctx->r7 = ADD32(ctx->r7, 0X732C);
            goto L_800A60EC;
    }
    // 0x800A6070: addiu       $a3, $a3, 0x732C
    ctx->r7 = ADD32(ctx->r7, 0X732C);
    // 0x800A6074: bne         $v0, $zero, L_800A609C
    if (ctx->r2 != 0) {
        // 0x800A6078: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800A609C;
    }
    // 0x800A6078: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A607C: jal         0x8006FB8C
    // 0x800A6080: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800A6080: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
    // 0x800A6084: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A6088: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A608C: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800A6090: addiu       $a2, $a2, 0x7300
    ctx->r6 = ADD32(ctx->r6, 0X7300);
    // 0x800A6094: bne         $at, $zero, L_800A60D0
    if (ctx->r1 != 0) {
        // 0x800A6098: addiu       $v1, $v1, 0x72F8
        ctx->r3 = ADD32(ctx->r3, 0X72F8);
            goto L_800A60D0;
    }
    // 0x800A6098: addiu       $v1, $v1, 0x72F8
    ctx->r3 = ADD32(ctx->r3, 0X72F8);
L_800A609C:
    // 0x800A609C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800A60A0: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    // 0x800A60A4: jal         0x80001D04
    // 0x800A60A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800A60A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x800A60AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A60B0: jal         0x8006FB8C
    // 0x800A60B4: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    rand_range(rdram, ctx);
        goto after_4;
    // 0x800A60B4: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    after_4:
    // 0x800A60B8: addiu       $t4, $v0, 0x78
    ctx->r12 = ADD32(ctx->r2, 0X78);
    // 0x800A60BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A60C0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A60C4: addiu       $a3, $a3, 0x732C
    ctx->r7 = ADD32(ctx->r7, 0X732C);
    // 0x800A60C8: b           L_800A60EC
    // 0x800A60CC: sw          $t4, 0x732C($at)
    MEM_W(0X732C, ctx->r1) = ctx->r12;
        goto L_800A60EC;
    // 0x800A60CC: sw          $t4, 0x732C($at)
    MEM_W(0X732C, ctx->r1) = ctx->r12;
L_800A60D0:
    // 0x800A60D0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800A60D4: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x800A60D8: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x800A60DC: jal         0x80001D04
    // 0x800A60E0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x800A60E0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_5:
    // 0x800A60E4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A60E8: addiu       $a3, $a3, 0x732C
    ctx->r7 = ADD32(ctx->r7, 0X732C);
L_800A60EC:
    // 0x800A60EC: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800A60F0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800A60F4: nop

    // 0x800A60F8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800A60FC: bgez        $t8, L_800A6108
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A6100: sw          $t8, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r24;
            goto L_800A6108;
    }
    // 0x800A6100: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800A6104: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_800A6108:
    // 0x800A6108: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A610C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A6110: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A6114: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800A6118: lb          $v1, 0x47A($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X47A);
    // 0x800A611C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A6120: beq         $v1, $zero, L_800A6334
    if (ctx->r3 == 0) {
        // 0x800A6124: nop
    
            goto L_800A6334;
    }
    // 0x800A6124: nop

    // 0x800A6128: bne         $a2, $v1, L_800A6448
    if (ctx->r6 != ctx->r3) {
        // 0x800A612C: nop
    
            goto L_800A6448;
    }
    // 0x800A612C: nop

    // 0x800A6130: lb          $v1, 0x47B($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X47B);
    // 0x800A6134: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6138: bne         $a2, $v1, L_800A6218
    if (ctx->r6 != ctx->r3) {
        // 0x800A613C: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800A6218;
    }
    // 0x800A613C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A6140: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A6144: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800A6148: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A614C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800A6150: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800A6154: lwc1        $f16, 0x46C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x800A6158: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A615C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A6160: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A6164: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A6168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A616C: swc1        $f18, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f18.u32l;
    // 0x800A6170: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A6174: nop

    // 0x800A6178: lb          $t3, 0x47C($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X47C);
    // 0x800A617C: lwc1        $f4, 0x46C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x800A6180: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800A6184: nop

    // 0x800A6188: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A618C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800A6190: nop

    // 0x800A6194: bc1f        L_800A61A8
    if (!c1cs) {
        // 0x800A6198: nop
    
            goto L_800A61A8;
    }
    // 0x800A6198: nop

    // 0x800A619C: swc1        $f2, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f2.u32l;
    // 0x800A61A0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A61A4: nop

L_800A61A8:
    // 0x800A61A8: lwc1        $f8, 0x48C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48C);
    // 0x800A61AC: nop

    // 0x800A61B0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A61B4: swc1        $f10, 0x48C($v0)
    MEM_W(0X48C, ctx->r2) = ctx->f10.u32l;
    // 0x800A61B8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A61BC: nop

    // 0x800A61C0: lb          $t4, 0x49C($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X49C);
    // 0x800A61C4: lwc1        $f18, 0x48C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48C);
    // 0x800A61C8: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800A61CC: nop

    // 0x800A61D0: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A61D4: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800A61D8: nop

    // 0x800A61DC: bc1f        L_800A61EC
    if (!c1cs) {
        // 0x800A61E0: lw          $t5, 0x18($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X18);
            goto L_800A61EC;
    }
    // 0x800A61E0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800A61E4: swc1        $f2, 0x48C($v0)
    MEM_W(0X48C, ctx->r2) = ctx->f2.u32l;
    // 0x800A61E8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
L_800A61EC:
    // 0x800A61EC: nop

    // 0x800A61F0: lbu         $t6, 0x1FC($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X1FC);
    // 0x800A61F4: nop

    // 0x800A61F8: slti        $at, $t6, 0x5B
    ctx->r1 = SIGNED(ctx->r14) < 0X5B ? 1 : 0;
    // 0x800A61FC: beq         $at, $zero, L_800A628C
    if (ctx->r1 == 0) {
        // 0x800A6200: nop
    
            goto L_800A628C;
    }
    // 0x800A6200: nop

    // 0x800A6204: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A6208: jal         0x80001D04
    // 0x800A620C: sb          $t7, 0x47B($t8)
    MEM_B(0X47B, ctx->r24) = ctx->r15;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x800A620C: sb          $t7, 0x47B($t8)
    MEM_B(0X47B, ctx->r24) = ctx->r15;
    after_6:
    // 0x800A6210: b           L_800A628C
    // 0x800A6214: nop

        goto L_800A628C;
    // 0x800A6214: nop

L_800A6218:
    // 0x800A6218: bne         $v1, $at, L_800A628C
    if (ctx->r3 != ctx->r1) {
        // 0x800A621C: nop
    
            goto L_800A628C;
    }
    // 0x800A621C: nop

    // 0x800A6220: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6224: lwc1        $f4, 0x46C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x800A6228: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800A622C: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x800A6230: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800A6234: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800A6238: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800A623C: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A6240: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A6244: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A6248: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A624C: swc1        $f8, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f8.u32l;
    // 0x800A6250: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A6254: nop

    // 0x800A6258: lwc1        $f10, 0x48C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48C);
    // 0x800A625C: nop

    // 0x800A6260: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800A6264: swc1        $f16, 0x48C($v0)
    MEM_W(0X48C, ctx->r2) = ctx->f16.u32l;
    // 0x800A6268: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A626C: nop

    // 0x800A6270: lwc1        $f18, 0x46C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x800A6274: nop

    // 0x800A6278: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800A627C: nop

    // 0x800A6280: bc1f        L_800A628C
    if (!c1cs) {
        // 0x800A6284: nop
    
            goto L_800A628C;
    }
    // 0x800A6284: nop

    // 0x800A6288: sb          $zero, 0x47A($v0)
    MEM_B(0X47A, ctx->r2) = 0;
L_800A628C:
    // 0x800A628C: jal         0x8006ECE0
    // 0x800A6290: nop

    is_game_paused(rdram, ctx);
        goto after_7;
    // 0x800A6290: nop

    after_7:
    // 0x800A6294: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A6298: bne         $v0, $zero, L_800A6448
    if (ctx->r2 != 0) {
        // 0x800A629C: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A6448;
    }
    // 0x800A629C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A62A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A62A4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A62A8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A62AC: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A62B0: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800A62B4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800A62B8: addiu       $t4, $zero, -0x60
    ctx->r12 = ADD32(0, -0X60);
    // 0x800A62BC: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800A62C0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800A62C4: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A62C8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A62CC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A62D0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A62D4: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A62D8: jal         0x800AAB5C
    // 0x800A62DC: addiu       $a3, $a3, 0x460
    ctx->r7 = ADD32(ctx->r7, 0X460);
    hud_element_render(rdram, ctx);
        goto after_8;
    // 0x800A62DC: addiu       $a3, $a3, 0x460
    ctx->r7 = ADD32(ctx->r7, 0X460);
    after_8:
    // 0x800A62E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A62E4: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A62E8: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A62EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A62F0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A62F4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A62F8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A62FC: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A6300: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A6304: jal         0x800AAB5C
    // 0x800A6308: addiu       $a3, $a3, 0x480
    ctx->r7 = ADD32(ctx->r7, 0X480);
    hud_element_render(rdram, ctx);
        goto after_9;
    // 0x800A6308: addiu       $a3, $a3, 0x480
    ctx->r7 = ADD32(ctx->r7, 0X480);
    after_9:
    // 0x800A630C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A6310: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A6314: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A6318: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A631C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800A6320: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800A6324: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A6328: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800A632C: b           L_800A6448
    // 0x800A6330: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_800A6448;
    // 0x800A6330: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800A6334:
    // 0x800A6334: lbu         $t9, 0x1FC($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1FC);
    // 0x800A6338: nop

    // 0x800A633C: slti        $at, $t9, 0x79
    ctx->r1 = SIGNED(ctx->r25) < 0X79 ? 1 : 0;
    // 0x800A6340: bne         $at, $zero, L_800A6448
    if (ctx->r1 != 0) {
        // 0x800A6344: nop
    
            goto L_800A6448;
    }
    // 0x800A6344: nop

    // 0x800A6348: sb          $a2, 0x47A($v0)
    MEM_B(0X47A, ctx->r2) = ctx->r6;
    // 0x800A634C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A6350: addiu       $t2, $zero, -0x1F
    ctx->r10 = ADD32(0, -0X1F);
    // 0x800A6354: sb          $a2, 0x47B($t1)
    MEM_B(0X47B, ctx->r9) = ctx->r6;
    // 0x800A6358: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A635C: addiu       $t4, $zero, 0x34
    ctx->r12 = ADD32(0, 0X34);
    // 0x800A6360: sb          $t2, 0x47C($t3)
    MEM_B(0X47C, ctx->r11) = ctx->r10;
    // 0x800A6364: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A6368: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A636C: sb          $t4, 0x49C($t5)
    MEM_B(0X49C, ctx->r13) = ctx->r12;
    // 0x800A6370: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A6374: addiu       $t7, $zero, -0x15
    ctx->r15 = ADD32(0, -0X15);
    // 0x800A6378: sb          $zero, 0x47D($t6)
    MEM_B(0X47D, ctx->r14) = 0;
    // 0x800A637C: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x800A6380: nop

    // 0x800A6384: bne         $a2, $v1, L_800A63A4
    if (ctx->r6 != ctx->r3) {
        // 0x800A6388: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800A63A4;
    }
    // 0x800A6388: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800A638C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A6390: addiu       $t9, $zero, 0x2A
    ctx->r25 = ADD32(0, 0X2A);
    // 0x800A6394: sb          $t7, 0x47C($t8)
    MEM_B(0X47C, ctx->r24) = ctx->r15;
    // 0x800A6398: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A639C: b           L_800A63FC
    // 0x800A63A0: sb          $t9, 0x49C($t1)
    MEM_B(0X49C, ctx->r9) = ctx->r25;
        goto L_800A63FC;
    // 0x800A63A0: sb          $t9, 0x49C($t1)
    MEM_B(0X49C, ctx->r9) = ctx->r25;
L_800A63A4:
    // 0x800A63A4: bne         $at, $zero, L_800A63FC
    if (ctx->r1 != 0) {
        // 0x800A63A8: nop
    
            goto L_800A63FC;
    }
    // 0x800A63A8: nop

    // 0x800A63AC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800A63B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A63B4: lh          $v0, 0x0($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X0);
    // 0x800A63B8: addiu       $t3, $zero, -0x64
    ctx->r11 = ADD32(0, -0X64);
    // 0x800A63BC: beq         $v0, $zero, L_800A63CC
    if (ctx->r2 == 0) {
        // 0x800A63C0: nop
    
            goto L_800A63CC;
    }
    // 0x800A63C0: nop

    // 0x800A63C4: bne         $v0, $at, L_800A63E4
    if (ctx->r2 != ctx->r1) {
        // 0x800A63C8: nop
    
            goto L_800A63E4;
    }
    // 0x800A63C8: nop

L_800A63CC:
    // 0x800A63CC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A63D0: addiu       $t5, $zero, -0x37
    ctx->r13 = ADD32(0, -0X37);
    // 0x800A63D4: sb          $t3, 0x47C($t4)
    MEM_B(0X47C, ctx->r12) = ctx->r11;
    // 0x800A63D8: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A63DC: b           L_800A63FC
    // 0x800A63E0: sb          $t5, 0x49C($t6)
    MEM_B(0X49C, ctx->r14) = ctx->r13;
        goto L_800A63FC;
    // 0x800A63E0: sb          $t5, 0x49C($t6)
    MEM_B(0X49C, ctx->r14) = ctx->r13;
L_800A63E4:
    // 0x800A63E4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A63E8: addiu       $t7, $zero, 0x3B
    ctx->r15 = ADD32(0, 0X3B);
    // 0x800A63EC: sb          $t7, 0x47C($t8)
    MEM_B(0X47C, ctx->r24) = ctx->r15;
    // 0x800A63F0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A63F4: addiu       $t9, $zero, 0x68
    ctx->r25 = ADD32(0, 0X68);
    // 0x800A63F8: sb          $t9, 0x49C($t1)
    MEM_B(0X49C, ctx->r9) = ctx->r25;
L_800A63FC:
    // 0x800A63FC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A6400: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A6404: lb          $t2, 0x49C($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X49C);
    // 0x800A6408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A640C: addiu       $t3, $t2, 0xC8
    ctx->r11 = ADD32(ctx->r10, 0XC8);
    // 0x800A6410: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800A6414: nop

    // 0x800A6418: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A641C: swc1        $f8, 0x48C($v0)
    MEM_W(0X48C, ctx->r2) = ctx->f8.u32l;
    // 0x800A6420: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A6424: nop

    // 0x800A6428: lb          $t4, 0x49C($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X49C);
    // 0x800A642C: nop

    // 0x800A6430: addiu       $t5, $t4, -0xC8
    ctx->r13 = ADD32(ctx->r12, -0XC8);
    // 0x800A6434: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800A6438: nop

    // 0x800A643C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A6440: jal         0x80001D04
    // 0x800A6444: swc1        $f16, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f16.u32l;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800A6444: swc1        $f16, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f16.u32l;
    after_10:
L_800A6448:
    // 0x800A6448: jal         0x8007C36C
    // 0x800A644C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_11;
    // 0x800A644C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x800A6450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A6454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A6458: jr          $ra
    // 0x800A645C: nop

    return;
    // 0x800A645C: nop

;}
RECOMP_FUNC void alCents2Ratio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9F40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C9F44: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800C9F48: bltz        $a0, L_800C9F5C
    if (SIGNED(ctx->r4) < 0) {
        // 0x800C9F4C: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_800C9F5C;
    }
    // 0x800C9F4C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9F50: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9F54: b           L_800C9F64
    // 0x800C9F58: lwc1        $f0, -0x65C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X65C0);
        goto L_800C9F64;
    // 0x800C9F58: lwc1        $f0, -0x65C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X65C0);
L_800C9F5C:
    // 0x800C9F5C: lwc1        $f0, -0x65BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X65BC);
    // 0x800C9F60: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_800C9F64:
    // 0x800C9F64: beq         $a0, $zero, L_800C9F88
    if (ctx->r4 == 0) {
        // 0x800C9F68: andi        $t6, $a0, 0x1
        ctx->r14 = ctx->r4 & 0X1;
            goto L_800C9F88;
    }
L_800C9F68:
    // 0x800C9F68: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x800C9F6C: beq         $t6, $zero, L_800C9F7C
    if (ctx->r14 == 0) {
        // 0x800C9F70: sra         $t7, $a0, 1
        ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
            goto L_800C9F7C;
    }
    // 0x800C9F70: sra         $t7, $a0, 1
    ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800C9F74: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C9F78: nop

L_800C9F7C:
    // 0x800C9F7C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C9F80: bne         $t7, $zero, L_800C9F68
    if (ctx->r15 != 0) {
        // 0x800C9F84: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800C9F68;
    }
    // 0x800C9F84: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_800C9F88:
    // 0x800C9F88: jr          $ra
    // 0x800C9F8C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800C9F8C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void check_viewport_background_flag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066B50: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066B54: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066B58: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066B5C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066B60: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066B64: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80066B68: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80066B6C: lw          $v0, -0x29FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X29FC);
    // 0x80066B70: nop

    // 0x80066B74: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80066B78: jr          $ra
    // 0x80066B7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80066B7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
;}
RECOMP_FUNC void savemenu_check_space(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800864E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800864EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800864F0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800864F4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800864F8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800864FC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80086500: beq         $t7, $zero, L_800865F8
    if (ctx->r15 == 0) {
        // 0x80086504: sll         $t2, $a0, 2
        ctx->r10 = S32(ctx->r4 << 2);
            goto L_800865F8;
    }
    // 0x80086504: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80086508: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8008650C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80086510: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80086514: addu        $a1, $t9, $a2
    ctx->r5 = ADD32(ctx->r25, ctx->r6);
    // 0x80086518: addiu       $t3, $t3, 0x6FE0
    ctx->r11 = ADD32(ctx->r11, 0X6FE0);
    // 0x8008651C: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x80086520: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80086524: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80086528: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8008652C: jal         0x800763EC
    // 0x80086530: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    get_free_space(rdram, ctx);
        goto after_0;
    // 0x80086530: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80086534: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80086538: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008653C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80086540: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80086544: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80086548: bne         $v0, $zero, L_800865B0
    if (ctx->r2 != 0) {
        // 0x8008654C: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_800865B0;
    }
    // 0x8008654C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80086550: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80086554: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80086558: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8008655C: addu        $v0, $a1, $t5
    ctx->r2 = ADD32(ctx->r5, ctx->r13);
    // 0x80086560: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80086564: nop

    // 0x80086568: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8008656C: bne         $at, $zero, L_800865FC
    if (ctx->r1 != 0) {
        // 0x80086570: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800865FC;
    }
    // 0x80086570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086574: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80086578: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8008657C: blez        $t8, L_800865FC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80086580: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800865FC;
    }
    // 0x80086580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086584: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80086588: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8008658C: nop

    // 0x80086590: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80086594: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x80086598: sb          $a0, 0x6($t3)
    MEM_B(0X6, ctx->r11) = ctx->r4;
    // 0x8008659C: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800865A0: nop

    // 0x800865A4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800865A8: b           L_800865F8
    // 0x800865AC: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
        goto L_800865F8;
    // 0x800865AC: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
L_800865B0:
    // 0x800865B0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800865B4: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x800865B8: bgez        $t6, L_800865D4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800865BC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_800865D4;
    }
    // 0x800865BC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800865C0: bne         $t7, $at, L_800865D4
    if (ctx->r15 != ctx->r1) {
        // 0x800865C4: nop
    
            goto L_800865D4;
    }
    // 0x800865C4: nop

    // 0x800865C8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800865CC: b           L_800865F8
    // 0x800865D0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_800865F8;
    // 0x800865D0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800865D4:
    // 0x800865D4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800865D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800865DC: beq         $v1, $at, L_800865F8
    if (ctx->r3 == ctx->r1) {
        // 0x800865E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800865F8;
    }
    // 0x800865E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800865E4: beq         $v1, $at, L_800865F8
    if (ctx->r3 == ctx->r1) {
        // 0x800865E8: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800865F8;
    }
    // 0x800865E8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800865EC: beq         $v1, $at, L_800865FC
    if (ctx->r3 == ctx->r1) {
        // 0x800865F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800865FC;
    }
    // 0x800865F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800865F4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800865F8:
    // 0x800865F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800865FC:
    // 0x800865FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80086600: jr          $ra
    // 0x80086604: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x80086604: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void __osBlockSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D12E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800D12EC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800D12F0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800D12F4: lbu         $t6, 0x4F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4F);
    // 0x800D12F8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800D12FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1300: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800D1304: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800D1308: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800D130C: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x800D1310: jal         0x800D653C
    // 0x800D1314: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_0;
    // 0x800D1314: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x800D1318: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800D131C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800D1320: beq         $t8, $zero, L_800D1330
    if (ctx->r24 == 0) {
        // 0x800D1324: nop
    
            goto L_800D1330;
    }
    // 0x800D1324: nop

    // 0x800D1328: b           L_800D13C8
    // 0x800D132C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800D13C8;
    // 0x800D132C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800D1330:
    // 0x800D1330: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_800D1334:
    // 0x800D1334: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x800D1338: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800D133C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800D1340: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800D1344: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x800D1348: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800D134C: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x800D1350: jal         0x800CE200
    // 0x800D1354: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamRead_recomp(rdram, ctx);
        goto after_1;
    // 0x800D1354: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x800D1358: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800D135C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800D1360: beq         $t3, $zero, L_800D1380
    if (ctx->r11 == 0) {
        // 0x800D1364: nop
    
            goto L_800D1380;
    }
    // 0x800D1364: nop

    // 0x800D1368: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800D136C: sb          $zero, 0x65($t4)
    MEM_B(0X65, ctx->r12) = 0;
    // 0x800D1370: jal         0x800D653C
    // 0x800D1374: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x800D1374: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x800D1378: b           L_800D13C8
    // 0x800D137C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_800D13C8;
    // 0x800D137C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800D1380:
    // 0x800D1380: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800D1384: jal         0x800D5850
    // 0x800D1388: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    __osSumcalc(rdram, ctx);
        goto after_3;
    // 0x800D1388: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_3:
    // 0x800D138C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800D1390: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800D1394: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800D1398: sh          $t7, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r15;
    // 0x800D139C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800D13A0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D13A4: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x800D13A8: bne         $at, $zero, L_800D1334
    if (ctx->r1 != 0) {
        // 0x800D13AC: sw          $t9, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r25;
            goto L_800D1334;
    }
    // 0x800D13AC: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800D13B0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800D13B4: sb          $zero, 0x65($t0)
    MEM_B(0X65, ctx->r8) = 0;
    // 0x800D13B8: jal         0x800D653C
    // 0x800D13BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_4;
    // 0x800D13BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x800D13C0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800D13C4: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800D13C8:
    // 0x800D13C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D13CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800D13D0: jr          $ra
    // 0x800D13D4: nop

    return;
    // 0x800D13D4: nop

;}
RECOMP_FUNC void load_menu_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FD50: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007FD54: addiu       $t1, $t1, -0x5E4
    ctx->r9 = ADD32(ctx->r9, -0X5E4);
    // 0x8007FD58: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8007FD5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007FD60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FD64: bne         $v1, $zero, L_8007FD8C
    if (ctx->r3 != 0) {
        // 0x8007FD68: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8007FD8C;
    }
    // 0x8007FD68: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8007FD6C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8007FD70: jal         0x80076EE4
    // 0x8007FD74: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x8007FD74: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8007FD78: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007FD7C: addiu       $t1, $t1, -0x5E4
    ctx->r9 = ADD32(ctx->r9, -0X5E4);
    // 0x8007FD80: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8007FD84: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x8007FD88: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8007FD8C:
    // 0x8007FD8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007FD90: beq         $a1, $at, L_8007FDC0
    if (ctx->r5 == ctx->r1) {
        // 0x8007FD94: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_8007FDC0;
    }
    // 0x8007FD94: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8007FD98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007FD9C: beq         $a1, $at, L_8007FDC8
    if (ctx->r5 == ctx->r1) {
        // 0x8007FDA0: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_8007FDC8;
    }
    // 0x8007FDA0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8007FDA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007FDA8: beq         $a1, $at, L_8007FDB8
    if (ctx->r5 == ctx->r1) {
        // 0x8007FDAC: nop
    
            goto L_8007FDB8;
    }
    // 0x8007FDAC: nop

    // 0x8007FDB0: b           L_8007FDC8
    // 0x8007FDB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8007FDC8;
    // 0x8007FDB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8007FDB8:
    // 0x8007FDB8: b           L_8007FDC8
    // 0x8007FDBC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
        goto L_8007FDC8;
    // 0x8007FDBC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_8007FDC0:
    // 0x8007FDC0: b           L_8007FDC8
    // 0x8007FDC4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
        goto L_8007FDC8;
    // 0x8007FDC4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_8007FDC8:
    // 0x8007FDC8: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8007FDCC: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x8007FDD0: addiu       $t0, $t0, -0x5E0
    ctx->r8 = ADD32(ctx->r8, -0X5E0);
    // 0x8007FDD4: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x8007FDD8: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007FDDC: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8007FDE0: subu        $a3, $a3, $a2
    ctx->r7 = SUB32(ctx->r7, ctx->r6);
    // 0x8007FDE4: beq         $a1, $zero, L_800803CC
    if (ctx->r5 == 0) {
        // 0x8007FDE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800803CC;
    }
    // 0x8007FDE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FDEC: jal         0x80077190
    // 0x8007FDF0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    asset_load(rdram, ctx);
        goto after_1;
    // 0x8007FDF0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x8007FDF4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007FDF8: addiu       $t1, $t1, -0x5E4
    ctx->r9 = ADD32(ctx->r9, -0X5E4);
    // 0x8007FDFC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8007FE00: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8007FE04: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007FE08: addiu       $t0, $t0, -0x5E0
    ctx->r8 = ADD32(ctx->r8, -0X5E0);
    // 0x8007FE0C: blez        $t8, L_8007FE60
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8007FE10: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8007FE60;
    }
    // 0x8007FE10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007FE14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007FE18: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8007FE1C:
    // 0x8007FE1C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8007FE20: nop

    // 0x8007FE24: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // 0x8007FE28: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8007FE2C: nop

    // 0x8007FE30: bne         $a3, $a0, L_8007FE40
    if (ctx->r7 != ctx->r4) {
        // 0x8007FE34: addu        $t9, $a0, $a1
        ctx->r25 = ADD32(ctx->r4, ctx->r5);
            goto L_8007FE40;
    }
    // 0x8007FE34: addu        $t9, $a0, $a1
    ctx->r25 = ADD32(ctx->r4, ctx->r5);
    // 0x8007FE38: b           L_8007FE44
    // 0x8007FE3C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_8007FE44;
    // 0x8007FE3C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8007FE40:
    // 0x8007FE40: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8007FE44:
    // 0x8007FE44: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8007FE48: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8007FE4C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8007FE50: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8007FE54: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007FE58: bne         $at, $zero, L_8007FE1C
    if (ctx->r1 != 0) {
        // 0x8007FE5C: nop
    
            goto L_8007FE1C;
    }
    // 0x8007FE5C: nop

L_8007FE60:
    // 0x8007FE60: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8007FE64: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007FE68: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8007FE6C: addiu       $a1, $a1, 0x6F90
    ctx->r5 = ADD32(ctx->r5, 0X6F90);
    // 0x8007FE70: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8007FE74: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8007FE78: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007FE7C: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x8007FE80: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8007FE84: addiu       $v0, $v0, -0x44
    ctx->r2 = ADD32(ctx->r2, -0X44);
    // 0x8007FE88: sw          $t6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r14;
    // 0x8007FE8C: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8007FE90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007FE94: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x8007FE98: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x8007FE9C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007FEA0: sw          $t8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r24;
    // 0x8007FEA4: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x8007FEA8: addiu       $v1, $v1, 0x320
    ctx->r3 = ADD32(ctx->r3, 0X320);
    // 0x8007FEAC: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    // 0x8007FEB0: lw          $t2, 0x18($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X18);
    // 0x8007FEB4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8007FEB8: sw          $t2, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r10;
    // 0x8007FEBC: lw          $t3, 0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X18);
    // 0x8007FEC0: addiu       $a3, $a3, 0x116C
    ctx->r7 = ADD32(ctx->r7, 0X116C);
    // 0x8007FEC4: sw          $t3, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r11;
    // 0x8007FEC8: lw          $t4, 0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1C);
    // 0x8007FECC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007FED0: sw          $t4, 0x6FA0($at)
    MEM_W(0X6FA0, ctx->r1) = ctx->r12;
    // 0x8007FED4: lw          $t5, 0x38($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X38);
    // 0x8007FED8: addiu       $t1, $t1, 0x126C
    ctx->r9 = ADD32(ctx->r9, 0X126C);
    // 0x8007FEDC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8007FEE0: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x8007FEE4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007FEE8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007FEEC: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x8007FEF0: addiu       $a2, $a2, 0x13CC
    ctx->r6 = ADD32(ctx->r6, 0X13CC);
    // 0x8007FEF4: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x8007FEF8: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x8007FEFC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007FF00: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x8007FF04: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x8007FF08: addiu       $v0, $v0, -0x70
    ctx->r2 = ADD32(ctx->r2, -0X70);
    // 0x8007FF0C: sw          $t9, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r25;
    // 0x8007FF10: lw          $t2, 0x78($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X78);
    // 0x8007FF14: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8007FF18: sw          $t2, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r10;
    // 0x8007FF1C: lw          $t3, 0x7C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X7C);
    // 0x8007FF20: nop

    // 0x8007FF24: sw          $t3, 0x114($t1)
    MEM_W(0X114, ctx->r9) = ctx->r11;
    // 0x8007FF28: lw          $t4, 0x7C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X7C);
    // 0x8007FF2C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007FF30: sw          $t4, 0x134($t1)
    MEM_W(0X134, ctx->r9) = ctx->r12;
    // 0x8007FF34: lw          $t5, 0x80($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X80);
    // 0x8007FF38: nop

    // 0x8007FF3C: sw          $t5, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r13;
    // 0x8007FF40: lw          $t6, 0x80($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X80);
    // 0x8007FF44: nop

    // 0x8007FF48: sw          $t6, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r14;
    // 0x8007FF4C: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x8007FF50: nop

    // 0x8007FF54: sw          $t7, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->r15;
    // 0x8007FF58: lw          $t8, 0x28($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X28);
    // 0x8007FF5C: nop

    // 0x8007FF60: sw          $t8, 0xB4($a2)
    MEM_W(0XB4, ctx->r6) = ctx->r24;
    // 0x8007FF64: lw          $t9, 0x88($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X88);
    // 0x8007FF68: nop

    // 0x8007FF6C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007FF70: lw          $t3, 0x69EC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X69EC);
    // 0x8007FF74: nop

    // 0x8007FF78: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8007FF7C: beq         $t5, $zero, L_8007FF90
    if (ctx->r13 == 0) {
        // 0x8007FF80: nop
    
            goto L_8007FF90;
    }
    // 0x8007FF80: nop

    // 0x8007FF84: lw          $t6, 0x2D8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2D8);
    // 0x8007FF88: b           L_8007FF9C
    // 0x8007FF8C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_8007FF9C;
    // 0x8007FF8C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8007FF90:
    // 0x8007FF90: lw          $t7, 0x2DC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2DC);
    // 0x8007FF94: nop

    // 0x8007FF98: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8007FF9C:
    // 0x8007FF9C: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x8007FFA0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007FFA4: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x8007FFA8: lw          $t9, 0x294($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X294);
    // 0x8007FFAC: addiu       $a2, $a2, 0x930
    ctx->r6 = ADD32(ctx->r6, 0X930);
    // 0x8007FFB0: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x8007FFB4: lw          $t2, 0x44($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X44);
    // 0x8007FFB8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8007FFBC: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x8007FFC0: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8007FFC4: addiu       $a3, $a3, 0x64
    ctx->r7 = ADD32(ctx->r7, 0X64);
    // 0x8007FFC8: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x8007FFCC: lw          $t4, 0x120($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X120);
    // 0x8007FFD0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007FFD4: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8007FFD8: lw          $t5, 0x124($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X124);
    // 0x8007FFDC: addiu       $v1, $v1, 0x7C
    ctx->r3 = ADD32(ctx->r3, 0X7C);
    // 0x8007FFE0: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x8007FFE4: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8007FFE8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007FFEC: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x8007FFF0: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x8007FFF4: addiu       $a1, $a1, 0x94
    ctx->r5 = ADD32(ctx->r5, 0X94);
    // 0x8007FFF8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8007FFFC: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80080000: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80080004: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80080008: lw          $t9, 0x154($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X154);
    // 0x8008000C: addiu       $t0, $t0, 0xAC
    ctx->r8 = ADD32(ctx->r8, 0XAC);
    // 0x80080010: sw          $t9, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r25;
    // 0x80080014: lw          $t2, 0x168($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X168);
    // 0x80080018: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008001C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80080020: lw          $t3, 0x174($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X174);
    // 0x80080024: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
    // 0x80080028: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8008002C: lw          $t4, 0x178($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X178);
    // 0x80080030: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80080034: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x80080038: lw          $t5, 0x154($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X154);
    // 0x8008003C: addiu       $a2, $a2, 0x10C
    ctx->r6 = ADD32(ctx->r6, 0X10C);
    // 0x80080040: sw          $t5, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r13;
    // 0x80080044: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x80080048: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008004C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80080050: lw          $t7, 0x17C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X17C);
    // 0x80080054: addiu       $v1, $v1, 0xDC
    ctx->r3 = ADD32(ctx->r3, 0XDC);
    // 0x80080058: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8008005C: lw          $t8, 0x180($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X180);
    // 0x80080060: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80080064: sw          $t8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r24;
    // 0x80080068: lw          $t9, 0x154($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X154);
    // 0x8008006C: addiu       $a3, $a3, 0x124
    ctx->r7 = ADD32(ctx->r7, 0X124);
    // 0x80080070: sw          $t9, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r25;
    // 0x80080074: lw          $t2, 0x168($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X168);
    // 0x80080078: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008007C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80080080: lw          $t3, 0x184($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X184);
    // 0x80080084: addiu       $a1, $a1, 0xF4
    ctx->r5 = ADD32(ctx->r5, 0XF4);
    // 0x80080088: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x8008008C: lw          $t4, 0x188($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X188);
    // 0x80080090: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080094: sw          $t4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r12;
    // 0x80080098: lw          $t5, 0x168($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X168);
    // 0x8008009C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800800A0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800800A4: lw          $t6, 0x18C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18C);
    // 0x800800A8: addiu       $t1, $t1, 0xF6C
    ctx->r9 = ADD32(ctx->r9, 0XF6C);
    // 0x800800AC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800800B0: lw          $t7, 0x190($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X190);
    // 0x800800B4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800800B8: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800800BC: lw          $t8, 0x154($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X154);
    // 0x800800C0: addiu       $t0, $t0, 0xF78
    ctx->r8 = ADD32(ctx->r8, 0XF78);
    // 0x800800C4: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x800800C8: lw          $t9, 0x168($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X168);
    // 0x800800CC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800800D0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800800D4: lw          $t2, 0x198($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X198);
    // 0x800800D8: addiu       $v0, $v0, 0x13C
    ctx->r2 = ADD32(ctx->r2, 0X13C);
    // 0x800800DC: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800800E0: lw          $t3, 0x19C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X19C);
    // 0x800800E4: nop

    // 0x800800E8: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x800800EC: lw          $t4, 0x188($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X188);
    // 0x800800F0: nop

    // 0x800800F4: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
    // 0x800800F8: lw          $t5, 0x168($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X168);
    // 0x800800FC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80080100: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80080104: lw          $t6, 0x2E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2E0);
    // 0x80080108: addiu       $v1, $v1, 0x7F8
    ctx->r3 = ADD32(ctx->r3, 0X7F8);
    // 0x8008010C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80080110: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x80080114: nop

    // 0x80080118: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x8008011C: lw          $t8, 0x154($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X154);
    // 0x80080120: nop

    // 0x80080124: sw          $t8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r24;
    // 0x80080128: lw          $t9, 0x264($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X264);
    // 0x8008012C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80080130: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80080134: lw          $t2, 0x268($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X268);
    // 0x80080138: addiu       $a1, $a1, 0x718
    ctx->r5 = ADD32(ctx->r5, 0X718);
    // 0x8008013C: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x80080140: lw          $t3, 0x26C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X26C);
    // 0x80080144: nop

    // 0x80080148: sw          $t3, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r11;
    // 0x8008014C: lw          $t4, 0x188($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X188);
    // 0x80080150: nop

    // 0x80080154: sw          $t4, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r12;
    // 0x80080158: lw          $t5, 0x270($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X270);
    // 0x8008015C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80080160: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x80080164: lw          $t6, 0x274($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X274);
    // 0x80080168: addiu       $a2, $a2, -0x2DC
    ctx->r6 = ADD32(ctx->r6, -0X2DC);
    // 0x8008016C: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x80080170: lw          $t7, 0x278($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X278);
    // 0x80080174: nop

    // 0x80080178: sw          $t7, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r15;
    // 0x8008017C: lw          $t8, 0x188($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X188);
    // 0x80080180: nop

    // 0x80080184: sw          $t8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r24;
    // 0x80080188: lw          $t9, 0x1A0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1A0);
    // 0x8008018C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80080190: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80080194: lw          $t2, 0x1A4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1A4);
    // 0x80080198: addiu       $a3, $a3, 0xF58
    ctx->r7 = ADD32(ctx->r7, 0XF58);
    // 0x8008019C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800801A0: lw          $t3, 0x1A8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1A8);
    // 0x800801A4: nop

    // 0x800801A8: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    // 0x800801AC: lw          $t4, 0x1AC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1AC);
    // 0x800801B0: nop

    // 0x800801B4: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
    // 0x800801B8: lw          $t5, 0x1B0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1B0);
    // 0x800801BC: nop

    // 0x800801C0: sw          $t5, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r13;
    // 0x800801C4: lw          $t6, 0x1B4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1B4);
    // 0x800801C8: nop

    // 0x800801CC: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x800801D0: lw          $t7, 0x188($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X188);
    // 0x800801D4: nop

    // 0x800801D8: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x800801DC: lw          $t8, 0x224($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X224);
    // 0x800801E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800801E4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800801E8: lw          $t9, 0x90($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X90);
    // 0x800801EC: nop

    // 0x800801F0: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x800801F4: lw          $t2, 0x130($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X130);
    // 0x800801F8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800801FC: sw          $t2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r10;
    // 0x80080200: lw          $t3, 0x130($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X130);
    // 0x80080204: addiu       $a2, $a2, 0xF44
    ctx->r6 = ADD32(ctx->r6, 0XF44);
    // 0x80080208: sw          $t3, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r11;
    // 0x8008020C: lw          $t4, 0x238($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X238);
    // 0x80080210: nop

    // 0x80080214: sw          $t4, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->r12;
    // 0x80080218: lw          $t5, 0x240($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X240);
    // 0x8008021C: nop

    // 0x80080220: sw          $t5, 0xB4($a1)
    MEM_W(0XB4, ctx->r5) = ctx->r13;
    // 0x80080224: lw          $t6, 0x130($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X130);
    // 0x80080228: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008022C: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
    // 0x80080230: lw          $t7, 0x130($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X130);
    // 0x80080234: addiu       $a1, $a1, 0xF30
    ctx->r5 = ADD32(ctx->r5, 0XF30);
    // 0x80080238: sw          $t7, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r15;
    // 0x8008023C: lw          $t8, 0x238($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X238);
    // 0x80080240: nop

    // 0x80080244: sw          $t8, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->r24;
    // 0x80080248: lw          $t9, 0x23C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X23C);
    // 0x8008024C: nop

    // 0x80080250: sw          $t9, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->r25;
    // 0x80080254: lw          $t2, 0x240($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X240);
    // 0x80080258: nop

    // 0x8008025C: sw          $t2, 0xF4($v1)
    MEM_W(0XF4, ctx->r3) = ctx->r10;
    // 0x80080260: lw          $t3, 0x114($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X114);
    // 0x80080264: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80080268: sw          $t3, 0xF30($at)
    MEM_W(0XF30, ctx->r1) = ctx->r11;
    // 0x8008026C: lw          $t4, 0x110($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X110);
    // 0x80080270: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080274: sw          $t4, 0xF44($at)
    MEM_W(0XF44, ctx->r1) = ctx->r12;
    // 0x80080278: lw          $t5, 0x10C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X10C);
    // 0x8008027C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080280: sw          $t5, 0xF58($at)
    MEM_W(0XF58, ctx->r1) = ctx->r13;
    // 0x80080284: lw          $t6, 0x2E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2E0);
    // 0x80080288: sw          $zero, 0x10($t1)
    MEM_W(0X10, ctx->r9) = 0;
    // 0x8008028C: sw          $zero, 0x14($t1)
    MEM_W(0X14, ctx->r9) = 0;
    // 0x80080290: addiu       $v1, $v1, 0xF6C
    ctx->r3 = ADD32(ctx->r3, 0XF6C);
    // 0x80080294: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
L_80080298:
    // 0x80080298: lw          $t7, 0x2C4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C4);
    // 0x8008029C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800802A0: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800802A4: lw          $t8, 0x2C4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C4);
    // 0x800802A8: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x800802AC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800802B0: lw          $t9, 0x2C4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C4);
    // 0x800802B4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800802B8: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800802BC: lw          $t2, 0x2C4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X2C4);
    // 0x800802C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800802C4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800802C8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800802CC: bne         $at, $zero, L_80080298
    if (ctx->r1 != 0) {
        // 0x800802D0: sw          $t2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r10;
            goto L_80080298;
    }
    // 0x800802D0: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800802D4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800802D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800802DC: beq         $t3, $zero, L_800802FC
    if (ctx->r11 == 0) {
        // 0x800802E0: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800802FC;
    }
    // 0x800802E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800802E4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800802E8: addiu       $v1, $v1, 0xF6C
    ctx->r3 = ADD32(ctx->r3, 0XF6C);
L_800802EC:
    // 0x800802EC: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x800802F0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800802F4: bne         $t4, $zero, L_800802EC
    if (ctx->r12 != 0) {
        // 0x800802F8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800802EC;
    }
    // 0x800802F8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800802FC:
    // 0x800802FC: lw          $t5, 0x2E4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2E4);
    // 0x80080300: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80080304: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x80080308: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8008030C: lw          $t8, 0x27C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X27C);
    // 0x80080310: addiu       $v0, $v0, 0xF84
    ctx->r2 = ADD32(ctx->r2, 0XF84);
    // 0x80080314: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80080318: lw          $t9, 0x280($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X280);
    // 0x8008031C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80080320: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80080324: lw          $t2, 0x284($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X284);
    // 0x80080328: addiu       $v1, $v1, 0xF94
    ctx->r3 = ADD32(ctx->r3, 0XF94);
    // 0x8008032C: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x80080330: lw          $t3, 0x288($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X288);
    // 0x80080334: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80080338: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8008033C: lw          $t4, 0x2E8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2E8);
    // 0x80080340: addiu       $a1, $a1, 0x558
    ctx->r5 = ADD32(ctx->r5, 0X558);
    // 0x80080344: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80080348: lw          $t6, 0x2EC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2EC);
    // 0x8008034C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080350: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x80080354: lw          $t5, 0x260($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X260);
    // 0x80080358: addiu       $v0, $a0, 0xC
    ctx->r2 = ADD32(ctx->r4, 0XC);
    // 0x8008035C: sw          $t5, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r13;
    // 0x80080360: lw          $t7, 0x260($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X260);
    // 0x80080364: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80080368: sw          $t7, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r15;
    // 0x8008036C: lw          $t8, 0x298($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X298);
    // 0x80080370: addiu       $v1, $v1, 0x5B8
    ctx->r3 = ADD32(ctx->r3, 0X5B8);
    // 0x80080374: sw          $t8, 0x5AC($at)
    MEM_W(0X5AC, ctx->r1) = ctx->r24;
    // 0x80080378: lw          $t9, 0x29C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X29C);
    // 0x8008037C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080380: sw          $t9, 0x5CC($at)
    MEM_W(0X5CC, ctx->r1) = ctx->r25;
    // 0x80080384: lw          $t2, 0x2A0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2A0);
    // 0x80080388: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008038C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080390: addiu       $a0, $a0, 0x6B8
    ctx->r4 = ADD32(ctx->r4, 0X6B8);
    // 0x80080394: sw          $t2, 0x5EC($at)
    MEM_W(0X5EC, ctx->r1) = ctx->r10;
L_80080398:
    // 0x80080398: lw          $t3, 0x298($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X298);
    // 0x8008039C: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800803A0: sw          $t3, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = ctx->r11;
    // 0x800803A4: lw          $t4, 0x29C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X29C);
    // 0x800803A8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800803AC: sw          $t4, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r12;
    // 0x800803B0: lw          $t6, 0x290($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X290);
    // 0x800803B4: nop

    // 0x800803B8: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
    // 0x800803BC: lw          $t5, 0x294($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X294);
    // 0x800803C0: bne         $v1, $a0, L_80080398
    if (ctx->r3 != ctx->r4) {
        // 0x800803C4: sw          $t5, 0x34($v1)
        MEM_W(0X34, ctx->r3) = ctx->r13;
            goto L_80080398;
    }
    // 0x800803C4: sw          $t5, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r13;
    // 0x800803C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800803CC:
    // 0x800803CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800803D0: jr          $ra
    // 0x800803D4: nop

    return;
    // 0x800803D4: nop

;}
RECOMP_FUNC void weather_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABA08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800ABA0C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800ABA10: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800ABA14: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800ABA18: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800ABA1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800ABA20: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800ABA24: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800ABA28: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800ABA2C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800ABA30: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800ABA34: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800ABA38: jal         0x800AB8BC
    // 0x800ABA3C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    weather_free(rdram, ctx);
        goto after_0;
    // 0x800ABA3C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    after_0:
    // 0x800ABA40: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800ABA44: addiu       $v0, $v0, -0x7E88
    ctx->r2 = ADD32(ctx->r2, -0X7E88);
    // 0x800ABA48: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x800ABA4C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800ABA50: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800ABA54: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x800ABA58: sw          $s0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r16;
    // 0x800ABA5C: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800ABA60: sw          $s0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r16;
    // 0x800ABA64: sw          $s2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r18;
    // 0x800ABA68: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x800ABA6C: sw          $s2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r18;
    // 0x800ABA70: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x800ABA74: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800ABA78: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x800ABA7C: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800ABA80: sw          $v1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r3;
    // 0x800ABA84: sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
    // 0x800ABA88: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x800ABA8C: sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
    // 0x800ABA90: sw          $a3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r7;
    // 0x800ABA94: bne         $at, $zero, L_800ABAA0
    if (ctx->r1 != 0) {
        // 0x800ABA98: sw          $a3, 0x38($v0)
        MEM_W(0X38, ctx->r2) = ctx->r7;
            goto L_800ABAA0;
    }
    // 0x800ABA98: sw          $a3, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r7;
    // 0x800ABA9C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800ABAA0:
    // 0x800ABAA0: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800ABAA4: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800ABAA8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800ABAAC: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800ABAB0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800ABAB4: addiu       $t7, $t7, 0x2DE0
    ctx->r15 = ADD32(ctx->r15, 0X2DE0);
    // 0x800ABAB8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800ABABC: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800ABAC0: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800ABAC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800ABAC8: bne         $t8, $at, L_800ABAE4
    if (ctx->r24 != ctx->r1) {
        // 0x800ABACC: lui         $s6, 0xFFAA
        ctx->r22 = S32(0XFFAA << 16);
            goto L_800ABAE4;
    }
    // 0x800ABACC: lui         $s6, 0xFFAA
    ctx->r22 = S32(0XFFAA << 16);
    // 0x800ABAD0: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    // 0x800ABAD4: jal         0x800AD6A4
    // 0x800ABAD8: addiu       $a1, $a3, 0x1
    ctx->r5 = ADD32(ctx->r7, 0X1);
    rain_init(rdram, ctx);
        goto after_1;
    // 0x800ABAD8: addiu       $a1, $a3, 0x1
    ctx->r5 = ADD32(ctx->r7, 0X1);
    after_1:
    // 0x800ABADC: b           L_800AC070
    // 0x800ABAE0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_800AC070;
    // 0x800ABAE0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800ABAE4:
    // 0x800ABAE4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800ABAE8: ori         $s6, $s6, 0x55FF
    ctx->r22 = ctx->r22 | 0X55FF;
    // 0x800ABAEC: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800ABAF0: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800ABAF4: sll         $a0, $t9, 2
    ctx->r4 = S32(ctx->r25 << 2);
    // 0x800ABAF8: jal         0x80070EDC
    // 0x800ABAFC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800ABAFC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_2:
    // 0x800ABB00: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800ABB04: addiu       $s5, $s5, 0x2E68
    ctx->r21 = ADD32(ctx->r21, 0X2E68);
    // 0x800ABB08: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x800ABB0C: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x800ABB10: lh          $t8, 0x24($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X24);
    // 0x800ABB14: lh          $t9, 0x26($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X26);
    // 0x800ABB18: lw          $t5, 0x18($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X18);
    // 0x800ABB1C: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x800ABB20: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x800ABB24: sw          $t1, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r9;
    // 0x800ABB28: sw          $t3, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->r11;
    // 0x800ABB2C: sh          $t8, 0x24($s5)
    MEM_H(0X24, ctx->r21) = ctx->r24;
    // 0x800ABB30: sh          $t9, 0x26($s5)
    MEM_H(0X26, ctx->r21) = ctx->r25;
    // 0x800ABB34: lh          $t1, 0x24($s5)
    ctx->r9 = MEM_H(ctx->r21, 0X24);
    // 0x800ABB38: lh          $t3, 0x26($s5)
    ctx->r11 = MEM_H(ctx->r21, 0X26);
    // 0x800ABB3C: sw          $t5, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r13;
    // 0x800ABB40: lw          $t6, 0x1C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C);
    // 0x800ABB44: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x800ABB48: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x800ABB4C: sw          $t2, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r10;
    // 0x800ABB50: sw          $t4, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r12;
    // 0x800ABB54: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800ABB58: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800ABB5C: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x800ABB60: sh          $t2, 0x28($s5)
    MEM_H(0X28, ctx->r21) = ctx->r10;
    // 0x800ABB64: sh          $t4, 0x2A($s5)
    MEM_H(0X2A, ctx->r21) = ctx->r12;
    // 0x800ABB68: sw          $t6, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r14;
    // 0x800ABB6C: bne         $t5, $zero, L_800ABB7C
    if (ctx->r13 != 0) {
        // 0x800ABB70: sw          $t7, 0x20($s5)
        MEM_W(0X20, ctx->r21) = ctx->r15;
            goto L_800ABB7C;
    }
    // 0x800ABB70: sw          $t7, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r15;
    // 0x800ABB74: jal         0x800AC094
    // 0x800ABB78: nop

    snow_init(rdram, ctx);
        goto after_3;
    // 0x800ABB78: nop

    after_3:
L_800ABB7C:
    // 0x800ABB7C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800ABB80: addiu       $s3, $s3, -0x7E90
    ctx->r19 = ADD32(ctx->r19, -0X7E90);
    // 0x800ABB84: sw          $s4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r20;
    // 0x800ABB88: sll         $a0, $s4, 1
    ctx->r4 = S32(ctx->r20 << 1);
    // 0x800ABB8C: jal         0x80070EDC
    // 0x800ABB90: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800ABB90: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_4:
    // 0x800ABB94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ABB98: sw          $v0, 0x2EA0($at)
    MEM_W(0X2EA0, ctx->r1) = ctx->r2;
    // 0x800ABB9C: sll         $a0, $s4, 4
    ctx->r4 = S32(ctx->r20 << 4);
    // 0x800ABBA0: jal         0x80070EDC
    // 0x800ABBA4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x800ABBA4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_5:
    // 0x800ABBA8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800ABBAC: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800ABBB0: addiu       $s2, $s2, 0x2E64
    ctx->r18 = ADD32(ctx->r18, 0X2E64);
    // 0x800ABBB4: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800ABBB8: blez        $t6, L_800ABCB8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800ABBBC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800ABCB8;
    }
    // 0x800ABBBC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800ABBC0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800ABBC4:
    // 0x800ABBC4: lw          $a1, 0x18($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X18);
    // 0x800ABBC8: jal         0x8006FB8C
    // 0x800ABBCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    rand_range(rdram, ctx);
        goto after_6;
    // 0x800ABBCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800ABBD0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800ABBD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800ABBD8: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800ABBDC: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x800ABBE0: lw          $a1, 0x1C($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X1C);
    // 0x800ABBE4: jal         0x8006FB8C
    // 0x800ABBE8: nop

    rand_range(rdram, ctx);
        goto after_7;
    // 0x800ABBE8: nop

    after_7:
    // 0x800ABBEC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800ABBF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800ABBF4: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x800ABBF8: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x800ABBFC: lw          $a1, 0x20($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X20);
    // 0x800ABC00: jal         0x8006FB8C
    // 0x800ABC04: nop

    rand_range(rdram, ctx);
        goto after_8;
    // 0x800ABC04: nop

    after_8:
    // 0x800ABC08: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800ABC0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800ABC10: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x800ABC14: sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    // 0x800ABC18: jal         0x8006FB8C
    // 0x800ABC1C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    rand_range(rdram, ctx);
        goto after_9;
    // 0x800ABC1C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_9:
    // 0x800ABC20: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800ABC24: addiu       $t4, $v0, 0x5
    ctx->r12 = ADD32(ctx->r2, 0X5);
    // 0x800ABC28: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800ABC2C: sllv        $t6, $t5, $t4
    ctx->r14 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x800ABC30: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800ABC34: sb          $t6, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r14;
    // 0x800ABC38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800ABC3C: jal         0x8006FB8C
    // 0x800ABC40: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    rand_range(rdram, ctx);
        goto after_10;
    // 0x800ABC40: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_10:
    // 0x800ABC44: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800ABC48: addiu       $t9, $v0, 0x5
    ctx->r25 = ADD32(ctx->r2, 0X5);
    // 0x800ABC4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800ABC50: sllv        $t2, $t1, $t9
    ctx->r10 = S32(ctx->r9 << (ctx->r25 & 31));
    // 0x800ABC54: addu        $t5, $t3, $s0
    ctx->r13 = ADD32(ctx->r11, ctx->r16);
    // 0x800ABC58: sb          $t2, 0xD($t5)
    MEM_B(0XD, ctx->r13) = ctx->r10;
    // 0x800ABC5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800ABC60: jal         0x8006FB8C
    // 0x800ABC64: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    rand_range(rdram, ctx);
        goto after_11;
    // 0x800ABC64: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_11:
    // 0x800ABC68: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800ABC6C: addiu       $t4, $v0, 0x5
    ctx->r12 = ADD32(ctx->r2, 0X5);
    // 0x800ABC70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800ABC74: sllv        $t6, $t7, $t4
    ctx->r14 = S32(ctx->r15 << (ctx->r12 & 31));
    // 0x800ABC78: addu        $t1, $t8, $s0
    ctx->r9 = ADD32(ctx->r24, ctx->r16);
    // 0x800ABC7C: sb          $t6, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r14;
    // 0x800ABC80: lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X4);
    // 0x800ABC84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800ABC88: jal         0x8006FB8C
    // 0x800ABC8C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    rand_range(rdram, ctx);
        goto after_12;
    // 0x800ABC8C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_12:
    // 0x800ABC90: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800ABC94: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800ABC98: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x800ABC9C: sb          $v0, 0xF($t3)
    MEM_B(0XF, ctx->r11) = ctx->r2;
    // 0x800ABCA0: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800ABCA4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800ABCA8: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800ABCAC: bne         $at, $zero, L_800ABBC4
    if (ctx->r1 != 0) {
        // 0x800ABCB0: nop
    
            goto L_800ABBC4;
    }
    // 0x800ABCB0: nop

    // 0x800ABCB4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800ABCB8:
    // 0x800ABCB8: sll         $s0, $s4, 2
    ctx->r16 = S32(ctx->r20 << 2);
    // 0x800ABCBC: sll         $s2, $s0, 2
    ctx->r18 = S32(ctx->r16 << 2);
    // 0x800ABCC0: addu        $s2, $s2, $s0
    ctx->r18 = ADD32(ctx->r18, ctx->r16);
    // 0x800ABCC4: sll         $s2, $s2, 1
    ctx->r18 = S32(ctx->r18 << 1);
    // 0x800ABCC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800ABCCC: jal         0x80070EDC
    // 0x800ABCD0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_13;
    // 0x800ABCD0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_13:
    // 0x800ABCD4: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800ABCD8: addiu       $s3, $s3, 0x2EA4
    ctx->r19 = ADD32(ctx->r19, 0X2EA4);
    // 0x800ABCDC: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800ABCE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800ABCE4: jal         0x80070EDC
    // 0x800ABCE8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_14;
    // 0x800ABCE8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_14:
    // 0x800ABCEC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800ABCF0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800ABCF4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800ABCF8: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x800ABCFC: addiu       $v1, $v1, 0x2E94
    ctx->r3 = ADD32(ctx->r3, 0X2E94);
    // 0x800ABD00: addiu       $t0, $t0, 0x2EAC
    ctx->r8 = ADD32(ctx->r8, 0X2EAC);
    // 0x800ABD04: addiu       $a3, $a3, 0x2EA4
    ctx->r7 = ADD32(ctx->r7, 0X2EA4);
    // 0x800ABD08: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800ABD0C:
    // 0x800ABD0C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800ABD10: blez        $s0, L_800ABEA0
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800ABD14: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_800ABEA0;
    }
    // 0x800ABD14: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800ABD18: andi        $a2, $s0, 0x3
    ctx->r6 = ctx->r16 & 0X3;
    // 0x800ABD1C: beq         $a2, $zero, L_800ABD7C
    if (ctx->r6 == 0) {
        // 0x800ABD20: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_800ABD7C;
    }
    // 0x800ABD20: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800ABD24: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800ABD28: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800ABD2C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_800ABD30:
    // 0x800ABD30: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800ABD34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800ABD38: addu        $t4, $t7, $v0
    ctx->r12 = ADD32(ctx->r15, ctx->r2);
    // 0x800ABD3C: sb          $a0, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r4;
    // 0x800ABD40: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800ABD44: nop

    // 0x800ABD48: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800ABD4C: sb          $a0, 0x7($t6)
    MEM_B(0X7, ctx->r14) = ctx->r4;
    // 0x800ABD50: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800ABD54: nop

    // 0x800ABD58: addu        $t9, $t1, $v0
    ctx->r25 = ADD32(ctx->r9, ctx->r2);
    // 0x800ABD5C: sb          $a0, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r4;
    // 0x800ABD60: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800ABD64: nop

    // 0x800ABD68: addu        $t2, $t3, $v0
    ctx->r10 = ADD32(ctx->r11, ctx->r2);
    // 0x800ABD6C: sb          $a0, 0x9($t2)
    MEM_B(0X9, ctx->r10) = ctx->r4;
    // 0x800ABD70: bne         $a1, $s1, L_800ABD30
    if (ctx->r5 != ctx->r17) {
        // 0x800ABD74: addiu       $v0, $v0, 0xA
        ctx->r2 = ADD32(ctx->r2, 0XA);
            goto L_800ABD30;
    }
    // 0x800ABD74: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800ABD78: beq         $s1, $s0, L_800ABE9C
    if (ctx->r17 == ctx->r16) {
        // 0x800ABD7C: sll         $v0, $s1, 2
        ctx->r2 = S32(ctx->r17 << 2);
            goto L_800ABE9C;
    }
L_800ABD7C:
    // 0x800ABD7C: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800ABD80: sll         $a1, $s0, 2
    ctx->r5 = S32(ctx->r16 << 2);
    // 0x800ABD84: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x800ABD88: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800ABD8C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800ABD90: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
L_800ABD94:
    // 0x800ABD94: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800ABD98: nop

    // 0x800ABD9C: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800ABDA0: sb          $a0, 0x6($t7)
    MEM_B(0X6, ctx->r15) = ctx->r4;
    // 0x800ABDA4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800ABDA8: nop

    // 0x800ABDAC: addu        $t8, $t4, $v0
    ctx->r24 = ADD32(ctx->r12, ctx->r2);
    // 0x800ABDB0: sb          $a0, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r4;
    // 0x800ABDB4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800ABDB8: nop

    // 0x800ABDBC: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x800ABDC0: sb          $a0, 0x8($t1)
    MEM_B(0X8, ctx->r9) = ctx->r4;
    // 0x800ABDC4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800ABDC8: nop

    // 0x800ABDCC: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800ABDD0: sb          $a0, 0x9($t3)
    MEM_B(0X9, ctx->r11) = ctx->r4;
    // 0x800ABDD4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800ABDD8: nop

    // 0x800ABDDC: addu        $t5, $t2, $v0
    ctx->r13 = ADD32(ctx->r10, ctx->r2);
    // 0x800ABDE0: sb          $a0, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r4;
    // 0x800ABDE4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800ABDE8: nop

    // 0x800ABDEC: addu        $t4, $t7, $v0
    ctx->r12 = ADD32(ctx->r15, ctx->r2);
    // 0x800ABDF0: sb          $a0, 0x11($t4)
    MEM_B(0X11, ctx->r12) = ctx->r4;
    // 0x800ABDF4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800ABDF8: nop

    // 0x800ABDFC: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800ABE00: sb          $a0, 0x12($t6)
    MEM_B(0X12, ctx->r14) = ctx->r4;
    // 0x800ABE04: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE08: nop

    // 0x800ABE0C: addu        $t9, $t1, $v0
    ctx->r25 = ADD32(ctx->r9, ctx->r2);
    // 0x800ABE10: sb          $a0, 0x13($t9)
    MEM_B(0X13, ctx->r25) = ctx->r4;
    // 0x800ABE14: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE18: nop

    // 0x800ABE1C: addu        $t2, $t3, $v0
    ctx->r10 = ADD32(ctx->r11, ctx->r2);
    // 0x800ABE20: sb          $a0, 0x1A($t2)
    MEM_B(0X1A, ctx->r10) = ctx->r4;
    // 0x800ABE24: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE28: nop

    // 0x800ABE2C: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800ABE30: sb          $a0, 0x1B($t7)
    MEM_B(0X1B, ctx->r15) = ctx->r4;
    // 0x800ABE34: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE38: nop

    // 0x800ABE3C: addu        $t8, $t4, $v0
    ctx->r24 = ADD32(ctx->r12, ctx->r2);
    // 0x800ABE40: sb          $a0, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r4;
    // 0x800ABE44: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE48: nop

    // 0x800ABE4C: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x800ABE50: sb          $a0, 0x1D($t1)
    MEM_B(0X1D, ctx->r9) = ctx->r4;
    // 0x800ABE54: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE58: nop

    // 0x800ABE5C: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800ABE60: sb          $a0, 0x24($t3)
    MEM_B(0X24, ctx->r11) = ctx->r4;
    // 0x800ABE64: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE68: nop

    // 0x800ABE6C: addu        $t5, $t2, $v0
    ctx->r13 = ADD32(ctx->r10, ctx->r2);
    // 0x800ABE70: sb          $a0, 0x25($t5)
    MEM_B(0X25, ctx->r13) = ctx->r4;
    // 0x800ABE74: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE78: nop

    // 0x800ABE7C: addu        $t4, $t7, $v0
    ctx->r12 = ADD32(ctx->r15, ctx->r2);
    // 0x800ABE80: sb          $a0, 0x26($t4)
    MEM_B(0X26, ctx->r12) = ctx->r4;
    // 0x800ABE84: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800ABE88: nop

    // 0x800ABE8C: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800ABE90: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800ABE94: bne         $v0, $a1, L_800ABD94
    if (ctx->r2 != ctx->r5) {
        // 0x800ABE98: sb          $a0, 0x27($t6)
        MEM_B(0X27, ctx->r14) = ctx->r4;
            goto L_800ABD94;
    }
    // 0x800ABE98: sb          $a0, 0x27($t6)
    MEM_B(0X27, ctx->r14) = ctx->r4;
L_800ABE9C:
    // 0x800ABE9C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800ABEA0:
    // 0x800ABEA0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800ABEA4: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800ABEA8: bne         $at, $zero, L_800ABD0C
    if (ctx->r1 != 0) {
        // 0x800ABEAC: nop
    
            goto L_800ABD0C;
    }
    // 0x800ABEAC: nop

    // 0x800ABEB0: lw          $v0, 0x8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X8);
    // 0x800ABEB4: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800ABEB8: lbu         $s2, 0x0($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X0);
    // 0x800ABEBC: lbu         $s3, 0x1($v0)
    ctx->r19 = MEM_BU(ctx->r2, 0X1);
    // 0x800ABEC0: addiu       $s4, $s4, -0x7E3C
    ctx->r20 = ADD32(ctx->r20, -0X7E3C);
    // 0x800ABEC4: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800ABEC8: sll         $t1, $s2, 5
    ctx->r9 = S32(ctx->r18 << 5);
    // 0x800ABECC: sll         $t2, $s3, 5
    ctx->r10 = S32(ctx->r19 << 5);
    // 0x800ABED0: addiu       $s2, $t1, -0x1
    ctx->r18 = ADD32(ctx->r9, -0X1);
    // 0x800ABED4: addiu       $s3, $t2, -0x1
    ctx->r19 = ADD32(ctx->r10, -0X1);
    // 0x800ABED8: sll         $t9, $s2, 16
    ctx->r25 = S32(ctx->r18 << 16);
    // 0x800ABEDC: sll         $t5, $s3, 16
    ctx->r13 = S32(ctx->r19 << 16);
    // 0x800ABEE0: sll         $t4, $a0, 4
    ctx->r12 = S32(ctx->r4 << 4);
    // 0x800ABEE4: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800ABEE8: sra         $s3, $t5, 16
    ctx->r19 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800ABEEC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800ABEF0: jal         0x80070EDC
    // 0x800ABEF4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_15;
    // 0x800ABEF4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_15:
    // 0x800ABEF8: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800ABEFC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800ABF00: addiu       $v1, $v1, 0x2E9C
    ctx->r3 = ADD32(ctx->r3, 0X2E9C);
    // 0x800ABF04: blez        $t8, L_800AC064
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800ABF08: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800AC064;
    }
    // 0x800ABF08: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800ABF0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800ABF10:
    // 0x800ABF10: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF14: sll         $a0, $s1, 1
    ctx->r4 = S32(ctx->r17 << 1);
    // 0x800ABF18: addu        $t1, $t6, $s0
    ctx->r9 = ADD32(ctx->r14, ctx->r16);
    // 0x800ABF1C: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x800ABF20: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF24: addiu       $v0, $a0, 0x3
    ctx->r2 = ADD32(ctx->r4, 0X3);
    // 0x800ABF28: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x800ABF2C: sb          $v0, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r2;
    // 0x800ABF30: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF34: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
    // 0x800ABF38: addu        $t5, $t2, $s0
    ctx->r13 = ADD32(ctx->r10, ctx->r16);
    // 0x800ABF3C: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x800ABF40: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF44: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800ABF48: addu        $t4, $t7, $s0
    ctx->r12 = ADD32(ctx->r15, ctx->r16);
    // 0x800ABF4C: sh          $s3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r19;
    // 0x800ABF50: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF54: nop

    // 0x800ABF58: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x800ABF5C: sb          $a1, 0x2($t6)
    MEM_B(0X2, ctx->r14) = ctx->r5;
    // 0x800ABF60: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF64: nop

    // 0x800ABF68: addu        $t9, $t1, $s0
    ctx->r25 = ADD32(ctx->r9, ctx->r16);
    // 0x800ABF6C: sh          $s2, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r18;
    // 0x800ABF70: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF74: nop

    // 0x800ABF78: addu        $t2, $t3, $s0
    ctx->r10 = ADD32(ctx->r11, ctx->r16);
    // 0x800ABF7C: sh          $zero, 0xA($t2)
    MEM_H(0XA, ctx->r10) = 0;
    // 0x800ABF80: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF84: nop

    // 0x800ABF88: addu        $t7, $t5, $s0
    ctx->r15 = ADD32(ctx->r13, ctx->r16);
    // 0x800ABF8C: sb          $a0, 0x3($t7)
    MEM_B(0X3, ctx->r15) = ctx->r4;
    // 0x800ABF90: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800ABF94: nop

    // 0x800ABF98: addu        $t8, $t4, $s0
    ctx->r24 = ADD32(ctx->r12, ctx->r16);
    // 0x800ABF9C: sh          $zero, 0xC($t8)
    MEM_H(0XC, ctx->r24) = 0;
    // 0x800ABFA0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800ABFA4: nop

    // 0x800ABFA8: addu        $t1, $t6, $s0
    ctx->r9 = ADD32(ctx->r14, ctx->r16);
    // 0x800ABFAC: sh          $zero, 0xE($t1)
    MEM_H(0XE, ctx->r9) = 0;
    // 0x800ABFB0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800ABFB4: addiu       $t1, $a0, 0x2
    ctx->r9 = ADD32(ctx->r4, 0X2);
    // 0x800ABFB8: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x800ABFBC: sb          $zero, 0x10($t3)
    MEM_B(0X10, ctx->r11) = 0;
    // 0x800ABFC0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800ABFC4: nop

    // 0x800ABFC8: addu        $t5, $t2, $s0
    ctx->r13 = ADD32(ctx->r10, ctx->r16);
    // 0x800ABFCC: sb          $v0, 0x11($t5)
    MEM_B(0X11, ctx->r13) = ctx->r2;
    // 0x800ABFD0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800ABFD4: nop

    // 0x800ABFD8: addu        $t4, $t7, $s0
    ctx->r12 = ADD32(ctx->r15, ctx->r16);
    // 0x800ABFDC: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
    // 0x800ABFE0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800ABFE4: nop

    // 0x800ABFE8: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x800ABFEC: sh          $s3, 0x16($t6)
    MEM_H(0X16, ctx->r14) = ctx->r19;
    // 0x800ABFF0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800ABFF4: nop

    // 0x800ABFF8: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x800ABFFC: sb          $t1, 0x12($t3)
    MEM_B(0X12, ctx->r11) = ctx->r9;
    // 0x800AC000: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800AC004: nop

    // 0x800AC008: addu        $t5, $t2, $s0
    ctx->r13 = ADD32(ctx->r10, ctx->r16);
    // 0x800AC00C: sh          $s2, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r18;
    // 0x800AC010: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AC014: nop

    // 0x800AC018: addu        $t4, $t7, $s0
    ctx->r12 = ADD32(ctx->r15, ctx->r16);
    // 0x800AC01C: sh          $s3, 0x1A($t4)
    MEM_H(0X1A, ctx->r12) = ctx->r19;
    // 0x800AC020: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800AC024: nop

    // 0x800AC028: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x800AC02C: sb          $a1, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r5;
    // 0x800AC030: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800AC034: nop

    // 0x800AC038: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x800AC03C: sh          $s2, 0x1C($t1)
    MEM_H(0X1C, ctx->r9) = ctx->r18;
    // 0x800AC040: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800AC044: nop

    // 0x800AC048: addu        $t2, $t3, $s0
    ctx->r10 = ADD32(ctx->r11, ctx->r16);
    // 0x800AC04C: sh          $zero, 0x1E($t2)
    MEM_H(0X1E, ctx->r10) = 0;
    // 0x800AC050: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800AC054: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x800AC058: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800AC05C: bne         $at, $zero, L_800ABF10
    if (ctx->r1 != 0) {
        // 0x800AC060: nop
    
            goto L_800ABF10;
    }
    // 0x800AC060: nop

L_800AC064:
    // 0x800AC064: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC068: sw          $zero, -0x7E38($at)
    MEM_W(-0X7E38, ctx->r1) = 0;
    // 0x800AC06C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800AC070:
    // 0x800AC070: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AC074: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AC078: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AC07C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AC080: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AC084: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AC088: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AC08C: jr          $ra
    // 0x800AC090: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800AC090: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void get_memory_pool_address(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800719B4: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800719B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800719BC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800719C0: lw          $v0, 0x3B08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3B08);
    // 0x800719C4: jr          $ra
    // 0x800719C8: nop

    return;
    // 0x800719C8: nop

;}
RECOMP_FUNC void free_rain_memory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD780: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AD784: lw          $a0, 0x31C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31C8);
    // 0x800AD788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AD78C: beq         $a0, $zero, L_800AD7A4
    if (ctx->r4 == 0) {
        // 0x800AD790: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AD7A4;
    }
    // 0x800AD790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AD794: jal         0x8007B70C
    // 0x800AD798: nop

    tex_free(rdram, ctx);
        goto after_0;
    // 0x800AD798: nop

    after_0:
    // 0x800AD79C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD7A0: sw          $zero, 0x3218($at)
    MEM_W(0X3218, ctx->r1) = 0;
L_800AD7A4:
    // 0x800AD7A4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AD7A8: lw          $a0, 0x31E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31E0);
    // 0x800AD7AC: nop

    // 0x800AD7B0: beq         $a0, $zero, L_800AD7C8
    if (ctx->r4 == 0) {
        // 0x800AD7B4: nop
    
            goto L_800AD7C8;
    }
    // 0x800AD7B4: nop

    // 0x800AD7B8: jal         0x8007B70C
    // 0x800AD7BC: nop

    tex_free(rdram, ctx);
        goto after_1;
    // 0x800AD7BC: nop

    after_1:
    // 0x800AD7C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD7C4: sw          $zero, 0x3218($at)
    MEM_W(0X3218, ctx->r1) = 0;
L_800AD7C8:
    // 0x800AD7C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AD7CC: lw          $a0, 0x321C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X321C);
    // 0x800AD7D0: nop

    // 0x800AD7D4: beq         $a0, $zero, L_800AD7EC
    if (ctx->r4 == 0) {
        // 0x800AD7D8: nop
    
            goto L_800AD7EC;
    }
    // 0x800AD7D8: nop

    // 0x800AD7DC: jal         0x8007D100
    // 0x800AD7E0: nop

    sprite_free(rdram, ctx);
        goto after_2;
    // 0x800AD7E0: nop

    after_2:
    // 0x800AD7E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD7E8: sw          $zero, 0x321C($at)
    MEM_W(0X321C, ctx->r1) = 0;
L_800AD7EC:
    // 0x800AD7EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AD7F0: lw          $a0, 0x3224($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3224);
    // 0x800AD7F4: nop

    // 0x800AD7F8: beq         $a0, $zero, L_800AD814
    if (ctx->r4 == 0) {
        // 0x800AD7FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AD814;
    }
    // 0x800AD7FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD800: jal         0x800096F8
    // 0x800AD804: nop

    audspat_point_stop(rdram, ctx);
        goto after_3;
    // 0x800AD804: nop

    after_3:
    // 0x800AD808: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD80C: sw          $zero, 0x3224($at)
    MEM_W(0X3224, ctx->r1) = 0;
    // 0x800AD810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AD814:
    // 0x800AD814: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD818: sw          $zero, 0x31EC($at)
    MEM_W(0X31EC, ctx->r1) = 0;
    // 0x800AD81C: jr          $ra
    // 0x800AD820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AD820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void get_camera_matrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069FFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A000: jr          $ra
    // 0x8006A004: addiu       $v0, $v0, 0x14E0
    ctx->r2 = ADD32(ctx->r2, 0X14E0);
    return;
    // 0x8006A004: addiu       $v0, $v0, 0x14E0
    ctx->r2 = ADD32(ctx->r2, 0X14E0);
;}
RECOMP_FUNC void obj_init_rampswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CEA4: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CEA8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003CEAC: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003CEB0: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CEB4: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8003CEB8: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003CEBC: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CEC0: nop

    // 0x8003CEC4: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003CEC8: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CECC: nop

    // 0x8003CED0: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8003CED4: lbu         $t2, 0x8($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X8);
    // 0x8003CED8: jr          $ra
    // 0x8003CEDC: sw          $t2, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r10;
    return;
    // 0x8003CEDC: sw          $t2, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void func_800C38B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3E0C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C3E10: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C3E14: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800C3E18: addiu       $s3, $s3, -0x52A0
    ctx->r19 = ADD32(ctx->r19, -0X52A0);
    // 0x800C3E1C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800C3E20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C3E24: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C3E28: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C3E2C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C3E30: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C3E34: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C3E38: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C3E3C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C3E40: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C3E44: addu        $s0, $t6, $a0
    ctx->r16 = ADD32(ctx->r14, ctx->r4);
    // 0x800C3E48: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3E4C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C3E50: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800C3E54: bne         $at, $zero, L_800C4120
    if (ctx->r1 != 0) {
        // 0x800C3E58: or          $s2, $a1, $zero
        ctx->r18 = ctx->r5 | 0;
            goto L_800C4120;
    }
    // 0x800C3E58: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800C3E5C: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
    // 0x800C3E60: beq         $at, $zero, L_800C4120
    if (ctx->r1 == 0) {
        // 0x800C3E64: addiu       $fp, $zero, 0x4
        ctx->r30 = ADD32(0, 0X4);
            goto L_800C4120;
    }
    // 0x800C3E64: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x800C3E68: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800C3E6C: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800C3E70: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800C3E74: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800C3E78: addiu       $s4, $s4, -0x52BA
    ctx->r20 = ADD32(ctx->r20, -0X52BA);
    // 0x800C3E7C: addiu       $s5, $s5, -0x52B8
    ctx->r21 = ADD32(ctx->r21, -0X52B8);
    // 0x800C3E80: addiu       $s6, $s6, -0x52B9
    ctx->r22 = ADD32(ctx->r22, -0X52B9);
    // 0x800C3E84: addiu       $s7, $s7, -0x52BB
    ctx->r23 = ADD32(ctx->r23, -0X52BB);
    // 0x800C3E88: addiu       $t7, $v0, -0x3
    ctx->r15 = ADD32(ctx->r2, -0X3);
L_800C3E8C:
    // 0x800C3E8C: sltiu       $at, $t7, 0xA
    ctx->r1 = ctx->r15 < 0XA ? 1 : 0;
    // 0x800C3E90: beq         $at, $zero, L_800C410C
    if (ctx->r1 == 0) {
        // 0x800C3E94: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800C410C;
    }
    // 0x800C3E94: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C3E98: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3E9C: addu        $at, $at, $t7
    gpr jr_addend_800C3EA8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C3EA0: lw          $t7, -0x6750($at)
    ctx->r15 = ADD32(ctx->r1, -0X6750);
    // 0x800C3EA4: nop

    // 0x800C3EA8: jr          $t7
    // 0x800C3EAC: nop

    switch (jr_addend_800C3EA8 >> 2) {
        case 0: goto L_800C3EB0; break;
        case 1: goto L_800C3EDC; break;
        case 2: goto L_800C3F88; break;
        case 3: goto L_800C4000; break;
        case 4: goto L_800C4034; break;
        case 5: goto L_800C4058; break;
        case 6: goto L_800C4084; break;
        case 7: goto L_800C40A8; break;
        case 8: goto L_800C40E0; break;
        case 9: goto L_800C40F8; break;
        default: switch_error(__func__, 0x800C3EA8, 0x800E98B0);
    }
    // 0x800C3EAC: nop

L_800C3EB0:
    // 0x800C3EB0: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3EB4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C3EB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3EBC: jal         0x800C54DC
    // 0x800C3EC0: sw          $a1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r5;
    set_dialogue_font(rdram, ctx);
        goto after_0;
    // 0x800C3EC0: sw          $a1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r5;
    after_0:
    // 0x800C3EC4: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800C3EC8: nop

    // 0x800C3ECC: addu        $s0, $t9, $s1
    ctx->r16 = ADD32(ctx->r25, ctx->r17);
    // 0x800C3ED0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3ED4: b           L_800C4110
    // 0x800C3ED8: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C4110;
    // 0x800C3ED8: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C3EDC:
    // 0x800C3EDC: lbu         $t1, 0x1($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3EE0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800C3EE4: sw          $t1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r9;
    // 0x800C3EE8: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800C3EEC: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x800C3EF0: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x800C3EF4: lbu         $t5, 0x2($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X2);
    // 0x800C3EF8: nop

    // 0x800C3EFC: sw          $t5, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r13;
    // 0x800C3F00: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800C3F04: sll         $t7, $t5, 5
    ctx->r15 = S32(ctx->r13 << 5);
    // 0x800C3F08: bne         $t6, $zero, L_800C3F28
    if (ctx->r14 != 0) {
        // 0x800C3F0C: addu        $t7, $t7, $t5
        ctx->r15 = ADD32(ctx->r15, ctx->r13);
            goto L_800C3F28;
    }
    // 0x800C3F0C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800C3F10: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C3F14: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800C3F18: mflo        $a2
    ctx->r6 = lo;
    // 0x800C3F1C: sw          $a2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r6;
    // 0x800C3F20: b           L_800C3F30
    // 0x800C3F24: subu        $v0, $a2, $t5
    ctx->r2 = SUB32(ctx->r6, ctx->r13);
        goto L_800C3F30;
    // 0x800C3F24: subu        $v0, $a2, $t5
    ctx->r2 = SUB32(ctx->r6, ctx->r13);
L_800C3F28:
    // 0x800C3F28: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x800C3F2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C3F30:
    // 0x800C3F30: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800C3F34: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x800C3F38: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x800C3F3C: lbu         $t2, 0x3($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X3);
    // 0x800C3F40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3F44: addiu       $a3, $t2, 0x41
    ctx->r7 = ADD32(ctx->r10, 0X41);
    // 0x800C3F48: sw          $a3, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r7;
    // 0x800C3F4C: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800C3F50: nop

    // 0x800C3F54: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x800C3F58: lbu         $t7, 0x4($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X4);
    // 0x800C3F5C: addiu       $s1, $s1, 0x5
    ctx->r17 = ADD32(ctx->r17, 0X5);
    // 0x800C3F60: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C3F64: sw          $t8, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r24;
    // 0x800C3F68: jal         0x800C543C
    // 0x800C3F6C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_1;
    // 0x800C3F6C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x800C3F70: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800C3F74: nop

    // 0x800C3F78: addu        $s0, $t0, $s1
    ctx->r16 = ADD32(ctx->r8, ctx->r17);
    // 0x800C3F7C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3F80: b           L_800C4110
    // 0x800C3F84: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C4110;
    // 0x800C3F84: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C3F88:
    // 0x800C3F88: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3F8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3F90: sw          $a1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r5;
    // 0x800C3F94: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800C3F98: nop

    // 0x800C3F9C: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x800C3FA0: lbu         $a2, 0x2($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X2);
    // 0x800C3FA4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800C3FA8: sw          $a2, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r6;
    // 0x800C3FAC: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800C3FB0: nop

    // 0x800C3FB4: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x800C3FB8: lbu         $a3, 0x3($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X3);
    // 0x800C3FBC: nop

    // 0x800C3FC0: sw          $a3, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r7;
    // 0x800C3FC4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800C3FC8: nop

    // 0x800C3FCC: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x800C3FD0: lbu         $t0, 0x4($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X4);
    // 0x800C3FD4: addiu       $s1, $s1, 0x5
    ctx->r17 = ADD32(ctx->r17, 0X5);
    // 0x800C3FD8: sw          $t0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r8;
    // 0x800C3FDC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800C3FE0: jal         0x800C5560
    // 0x800C3FE4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    set_current_text_colour(rdram, ctx);
        goto after_2;
    // 0x800C3FE4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_2:
    // 0x800C3FE8: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800C3FEC: nop

    // 0x800C3FF0: addu        $s0, $t3, $s1
    ctx->r16 = ADD32(ctx->r11, ctx->r17);
    // 0x800C3FF4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3FF8: b           L_800C4110
    // 0x800C3FFC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C4110;
    // 0x800C3FFC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C4000:
    // 0x800C4000: lbu         $t4, 0x1($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1);
    // 0x800C4004: nop

    // 0x800C4008: bne         $t4, $zero, L_800C4018
    if (ctx->r12 != 0) {
        // 0x800C400C: nop
    
            goto L_800C4018;
    }
    // 0x800C400C: nop

    // 0x800C4010: b           L_800C401C
    // 0x800C4014: sw          $fp, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r30;
        goto L_800C401C;
    // 0x800C4014: sw          $fp, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r30;
L_800C4018:
    // 0x800C4018: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
L_800C401C:
    // 0x800C401C: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800C4020: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C4024: addu        $s0, $t5, $s1
    ctx->r16 = ADD32(ctx->r13, ctx->r17);
    // 0x800C4028: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C402C: b           L_800C4110
    // 0x800C4030: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C4110;
    // 0x800C4030: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C4034:
    // 0x800C4034: lbu         $t6, 0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1);
    // 0x800C4038: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C403C: sw          $t6, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r14;
    // 0x800C4040: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800C4044: nop

    // 0x800C4048: addu        $s0, $t7, $s1
    ctx->r16 = ADD32(ctx->r15, ctx->r17);
    // 0x800C404C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C4050: b           L_800C4110
    // 0x800C4054: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C4110;
    // 0x800C4054: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C4058:
    // 0x800C4058: lw          $t8, 0x2C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X2C);
    // 0x800C405C: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x800C4060: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C4064: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800C4068: sw          $t0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r8;
    // 0x800C406C: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800C4070: nop

    // 0x800C4074: addu        $s0, $t1, $s1
    ctx->r16 = ADD32(ctx->r9, ctx->r17);
    // 0x800C4078: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C407C: b           L_800C4110
    // 0x800C4080: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C4110;
    // 0x800C4080: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C4084:
    // 0x800C4084: lbu         $t2, 0x1($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1);
    // 0x800C4088: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C408C: sw          $t2, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r10;
    // 0x800C4090: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800C4094: nop

    // 0x800C4098: addu        $s0, $t3, $s1
    ctx->r16 = ADD32(ctx->r11, ctx->r17);
    // 0x800C409C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C40A0: b           L_800C4110
    // 0x800C40A4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C4110;
    // 0x800C40A4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C40A8:
    // 0x800C40A8: lb          $t4, 0x0($s4)
    ctx->r12 = MEM_B(ctx->r20, 0X0);
    // 0x800C40AC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800C40B0: bne         $t4, $zero, L_800C40D0
    if (ctx->r12 != 0) {
        // 0x800C40B4: nop
    
            goto L_800C40D0;
    }
    // 0x800C40B4: nop

    // 0x800C40B8: lbu         $t6, 0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1);
    // 0x800C40BC: jal         0x8000C8B4
    // 0x800C40C0: sb          $t6, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r14;
    normalise_time(rdram, ctx);
        goto after_3;
    // 0x800C40C0: sb          $t6, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r14;
    after_3:
    // 0x800C40C4: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800C40C8: sb          $v0, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r2;
    // 0x800C40CC: addu        $s0, $t7, $s1
    ctx->r16 = ADD32(ctx->r15, ctx->r17);
L_800C40D0:
    // 0x800C40D0: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800C40D4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C40D8: b           L_800C410C
    // 0x800C40DC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
        goto L_800C410C;
    // 0x800C40DC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800C40E0:
    // 0x800C40E0: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
    // 0x800C40E4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C40E8: sb          $t8, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r24;
    // 0x800C40EC: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800C40F0: b           L_800C410C
    // 0x800C40F4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
        goto L_800C410C;
    // 0x800C40F4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800C40F8:
    // 0x800C40F8: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x800C40FC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C4100: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
    // 0x800C4104: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800C4108: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800C410C:
    // 0x800C410C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C4110:
    // 0x800C4110: bne         $at, $zero, L_800C4120
    if (ctx->r1 != 0) {
        // 0x800C4114: slti        $at, $v0, 0xD
        ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
            goto L_800C4120;
    }
    // 0x800C4114: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
    // 0x800C4118: bne         $at, $zero, L_800C3E8C
    if (ctx->r1 != 0) {
        // 0x800C411C: addiu       $t7, $v0, -0x3
        ctx->r15 = ADD32(ctx->r2, -0X3);
            goto L_800C3E8C;
    }
    // 0x800C411C: addiu       $t7, $v0, -0x3
    ctx->r15 = ADD32(ctx->r2, -0X3);
L_800C4120:
    // 0x800C4120: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C4124: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800C4128: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C412C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C4130: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C4134: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C4138: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C413C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C4140: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C4144: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C4148: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C414C: jr          $ra
    // 0x800C4150: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C4150: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void render_level_geometry_and_objects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028FEC: addiu       $sp, $sp, -0x170
    ctx->r29 = ADD32(ctx->r29, -0X170);
    // 0x80028FF0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80028FF4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80028FF8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80028FFC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80029000: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80029004: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80029008: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002900C: jal         0x80012C30
    // 0x80029010: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    func_80012C30(rdram, ctx);
        goto after_0;
    // 0x80029010: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x80029014: jal         0x8006ECD0
    // 0x80029018: nop

    get_settings(rdram, ctx);
        goto after_1;
    // 0x80029018: nop

    after_1:
    // 0x8002901C: lbu         $t6, 0x49($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X49);
    // 0x80029020: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x80029024: bne         $t6, $at, L_80029034
    if (ctx->r14 != ctx->r1) {
        // 0x80029028: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80029034;
    }
    // 0x80029028: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002902C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80029030: sw          $t7, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = ctx->r15;
L_80029034:
    // 0x80029034: jal         0x80014814
    // 0x80029038: addiu       $a0, $sp, 0x16C
    ctx->r4 = ADD32(ctx->r29, 0X16C);
    get_first_active_object(rdram, ctx);
        goto after_2;
    // 0x80029038: addiu       $a0, $sp, 0x16C
    ctx->r4 = ADD32(ctx->r29, 0X16C);
    after_2:
    // 0x8002903C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80029040: lw          $s0, -0x3178($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X3178);
    // 0x80029044: sw          $v0, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r2;
    // 0x80029048: lh          $t8, 0x1A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1A);
    // 0x8002904C: nop

    // 0x80029050: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80029054: bne         $at, $zero, L_80029094
    if (ctx->r1 != 0) {
        // 0x80029058: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80029094;
    }
    // 0x80029058: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002905C: sw          $zero, 0x168($sp)
    MEM_W(0X168, ctx->r29) = 0;
    // 0x80029060: lh          $a2, 0x1A($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X1A);
    // 0x80029064: addiu       $t9, $sp, 0x168
    ctx->r25 = ADD32(ctx->r29, 0X168);
    // 0x80029068: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002906C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80029070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029074: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    // 0x80029078: jal         0x80029B38
    // 0x8002907C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    traverse_segments_bsp_tree(rdram, ctx);
        goto after_3;
    // 0x8002907C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_3:
    // 0x80029080: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80029084: lw          $s0, -0x3178($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X3178);
    // 0x80029088: b           L_800290A0
    // 0x8002908C: lh          $t1, 0x1A($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1A);
        goto L_800290A0;
    // 0x8002908C: lh          $t1, 0x1A($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1A);
    // 0x80029090: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80029094:
    // 0x80029094: sw          $t0, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r8;
    // 0x80029098: sb          $zero, 0xD8($sp)
    MEM_B(0XD8, ctx->r29) = 0;
    // 0x8002909C: lh          $t1, 0x1A($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1A);
L_800290A0:
    // 0x800290A0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800290A4: blez        $t1, L_800290C8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800290A8: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_800290C8;
    }
    // 0x800290A8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800290AC: addiu       $v0, $sp, 0x59
    ctx->r2 = ADD32(ctx->r29, 0X59);
L_800290B0:
    // 0x800290B0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800290B4: lh          $t2, 0x1A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1A);
    // 0x800290B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800290BC: slt         $at, $t2, $s2
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800290C0: beq         $at, $zero, L_800290B0
    if (ctx->r1 == 0) {
        // 0x800290C4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800290B0;
    }
    // 0x800290C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800290C8:
    // 0x800290C8: lb          $t4, -0x49A0($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X49A0);
    // 0x800290CC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800290D0: beq         $t4, $zero, L_8002912C
    if (ctx->r12 == 0) {
        // 0x800290D4: sb          $t3, 0x58($sp)
        MEM_B(0X58, ctx->r29) = ctx->r11;
            goto L_8002912C;
    }
    // 0x800290D4: sb          $t3, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r11;
    // 0x800290D8: lw          $t5, 0x168($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X168);
    // 0x800290DC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800290E0: blez        $t5, L_8002912C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800290E4: addiu       $s6, $sp, 0x58
        ctx->r22 = ADD32(ctx->r29, 0X58);
            goto L_8002912C;
    }
    // 0x800290E4: addiu       $s6, $sp, 0x58
    ctx->r22 = ADD32(ctx->r29, 0X58);
    // 0x800290E8: addiu       $s0, $sp, 0xD8
    ctx->r16 = ADD32(ctx->r29, 0XD8);
    // 0x800290EC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800290F0:
    // 0x800290F0: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800290F4: jal         0x80029698
    // 0x800290F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    render_level_segment(rdram, ctx);
        goto after_4;
    // 0x800290F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800290FC: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80029100: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80029104: addu        $t7, $s6, $t6
    ctx->r15 = ADD32(ctx->r22, ctx->r14);
    // 0x80029108: sb          $s1, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r17;
    // 0x8002910C: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x80029110: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80029114: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80029118: bne         $at, $zero, L_800290F0
    if (ctx->r1 != 0) {
        // 0x8002911C: nop
    
            goto L_800290F0;
    }
    // 0x8002911C: nop

    // 0x80029120: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80029124: lw          $s0, -0x3178($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X3178);
    // 0x80029128: nop

L_8002912C:
    // 0x8002912C: lh          $t9, 0x1A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A);
    // 0x80029130: addiu       $s6, $sp, 0x58
    ctx->r22 = ADD32(ctx->r29, 0X58);
    // 0x80029134: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80029138: beq         $at, $zero, L_80029148
    if (ctx->r1 == 0) {
        // 0x8002913C: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_80029148;
    }
    // 0x8002913C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80029140: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80029144: sb          $t0, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r8;
L_80029148:
    // 0x80029148: addiu       $s3, $s3, -0x49E0
    ctx->r19 = ADD32(ctx->r19, -0X49E0);
    // 0x8002914C: jal         0x8007B820
    // 0x80029150: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rendermode_reset(rdram, ctx);
        goto after_5;
    // 0x80029150: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x80029154: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x80029158: lw          $a0, 0x160($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X160);
    // 0x8002915C: jal         0x80015348
    // 0x80029160: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    sort_objects_by_dist(rdram, ctx);
        goto after_6;
    // 0x80029160: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    after_6:
    // 0x80029164: jal         0x80066460
    // 0x80029168: nop

    get_current_viewport(rdram, ctx);
        goto after_7;
    // 0x80029168: nop

    after_7:
    // 0x8002916C: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x80029170: lw          $s2, 0x160($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X160);
    // 0x80029174: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80029178: addiu       $t2, $zero, 0x200
    ctx->r10 = ADD32(0, 0X200);
    // 0x8002917C: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x80029180: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029184: beq         $at, $zero, L_800292E0
    if (ctx->r1 == 0) {
        // 0x80029188: sw          $t3, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r11;
            goto L_800292E0;
    }
    // 0x80029188: sw          $t3, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r11;
    // 0x8002918C: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80029190: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80029194: addiu       $s4, $s4, -0x49DC
    ctx->r20 = ADD32(ctx->r20, -0X49DC);
    // 0x80029198: addiu       $s5, $s5, -0x49D8
    ctx->r21 = ADD32(ctx->r21, -0X49D8);
    // 0x8002919C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800291A0:
    // 0x800291A0: jal         0x8000E948
    // 0x800291A4: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    get_object(rdram, ctx);
        goto after_8;
    // 0x800291A4: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    after_8:
    // 0x800291A8: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x800291AC: lw          $t7, 0x158($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X158);
    // 0x800291B0: andi        $t5, $v1, 0x80
    ctx->r13 = ctx->r3 & 0X80;
    // 0x800291B4: beq         $t5, $zero, L_800291C4
    if (ctx->r13 == 0) {
        // 0x800291B8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800291C4;
    }
    // 0x800291B8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800291BC: b           L_800291D8
    // 0x800291C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800291D8;
    // 0x800291C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800291C4:
    // 0x800291C4: andi        $t6, $v1, 0x8000
    ctx->r14 = ctx->r3 & 0X8000;
    // 0x800291C8: bne         $t6, $zero, L_800291DC
    if (ctx->r14 != 0) {
        // 0x800291CC: and         $t8, $v1, $t7
        ctx->r24 = ctx->r3 & ctx->r15;
            goto L_800291DC;
    }
    // 0x800291CC: and         $t8, $v1, $t7
    ctx->r24 = ctx->r3 & ctx->r15;
    // 0x800291D0: lbu         $s0, 0x39($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X39);
    // 0x800291D4: nop

L_800291D8:
    // 0x800291D8: and         $t8, $v1, $t7
    ctx->r24 = ctx->r3 & ctx->r15;
L_800291DC:
    // 0x800291DC: beq         $t8, $zero, L_800291E8
    if (ctx->r24 == 0) {
        // 0x800291E0: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_800291E8;
    }
    // 0x800291E0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800291E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800291E8:
    // 0x800291E8: beq         $v0, $zero, L_800292D0
    if (ctx->r2 == 0) {
        // 0x800291EC: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_800292D0;
    }
    // 0x800291EC: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x800291F0: bne         $s0, $at, L_800292D0
    if (ctx->r16 != ctx->r1) {
        // 0x800291F4: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_800292D0;
    }
    // 0x800291F4: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x800291F8: jal         0x8002A940
    // 0x800291FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    check_if_in_draw_range(rdram, ctx);
        goto after_9;
    // 0x800291FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80029200: beq         $v0, $zero, L_800292D0
    if (ctx->r2 == 0) {
        // 0x80029204: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_800292D0;
    }
    // 0x80029204: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x80029208: lh          $t9, 0x2E($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2E);
    // 0x8002920C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80029210: addu        $t0, $s6, $t9
    ctx->r8 = ADD32(ctx->r22, ctx->r25);
    // 0x80029214: lbu         $t2, 0x1($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X1);
    // 0x80029218: nop

    // 0x8002921C: bne         $t2, $zero, L_80029244
    if (ctx->r10 != 0) {
        // 0x80029220: nop
    
            goto L_80029244;
    }
    // 0x80029220: nop

    // 0x80029224: lwc1        $f6, 0x34($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80029228: lwc1        $f5, 0x6430($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6430);
    // 0x8002922C: lwc1        $f4, 0x6434($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6434);
    // 0x80029230: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80029234: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80029238: nop

    // 0x8002923C: bc1f        L_800292D0
    if (!c1cs) {
        // 0x80029240: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_800292D0;
    }
    // 0x80029240: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
L_80029244:
    // 0x80029244: lh          $t1, 0x6($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X6);
    // 0x80029248: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002924C: andi        $t3, $t1, 0x8000
    ctx->r11 = ctx->r9 & 0X8000;
    // 0x80029250: beq         $t3, $zero, L_8002926C
    if (ctx->r11 == 0) {
        // 0x80029254: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_8002926C;
    }
    // 0x80029254: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029258: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002925C: jal         0x80012D5C
    // 0x80029260: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_10;
    // 0x80029260: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_10:
    // 0x80029264: b           L_800292D0
    // 0x80029268: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
        goto L_800292D0;
    // 0x80029268: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
L_8002926C:
    // 0x8002926C: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    // 0x80029270: nop

    // 0x80029274: beq         $a1, $zero, L_80029288
    if (ctx->r5 == 0) {
        // 0x80029278: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80029288;
    }
    // 0x80029278: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002927C: jal         0x8002D3C4
    // 0x80029280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_render(rdram, ctx);
        goto after_11;
    // 0x80029280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80029284: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80029288:
    // 0x80029288: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8002928C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80029290: jal         0x80012D5C
    // 0x80029294: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_12;
    // 0x80029294: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_12:
    // 0x80029298: lw          $a1, 0x58($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X58);
    // 0x8002929C: nop

    // 0x800292A0: beq         $a1, $zero, L_800292D0
    if (ctx->r5 == 0) {
        // 0x800292A4: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_800292D0;
    }
    // 0x800292A4: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x800292A8: lw          $t4, 0x40($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X40);
    // 0x800292AC: nop

    // 0x800292B0: lhu         $t5, 0x30($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X30);
    // 0x800292B4: nop

    // 0x800292B8: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x800292BC: beq         $t6, $zero, L_800292D0
    if (ctx->r14 == 0) {
        // 0x800292C0: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_800292D0;
    }
    // 0x800292C0: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x800292C4: jal         0x8002D6B0
    // 0x800292C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    watereffect_render(rdram, ctx);
        goto after_13;
    // 0x800292C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x800292CC: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
L_800292D0:
    // 0x800292D0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800292D4: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800292D8: bne         $at, $zero, L_800291A0
    if (ctx->r1 != 0) {
        // 0x800292DC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800291A0;
    }
    // 0x800292DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800292E0:
    // 0x800292E0: lw          $t7, 0x160($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X160);
    // 0x800292E4: addiu       $s2, $v1, -0x1
    ctx->r18 = ADD32(ctx->r3, -0X1);
    // 0x800292E8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800292EC: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800292F0: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800292F4: addiu       $s5, $s5, -0x49D8
    ctx->r21 = ADD32(ctx->r21, -0X49D8);
    // 0x800292F8: bne         $at, $zero, L_8002940C
    if (ctx->r1 != 0) {
        // 0x800292FC: addiu       $s4, $s4, -0x49DC
        ctx->r20 = ADD32(ctx->r20, -0X49DC);
            goto L_8002940C;
    }
    // 0x800292FC: addiu       $s4, $s4, -0x49DC
    ctx->r20 = ADD32(ctx->r20, -0X49DC);
    // 0x80029300: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80029304: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_80029308:
    // 0x80029308: jal         0x8000E948
    // 0x8002930C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    get_object(rdram, ctx);
        goto after_14;
    // 0x8002930C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x80029310: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x80029314: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x80029318: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8002931C: and         $t0, $v1, $t9
    ctx->r8 = ctx->r3 & ctx->r25;
    // 0x80029320: beq         $t0, $zero, L_80029330
    if (ctx->r8 == 0) {
        // 0x80029324: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_80029330;
    }
    // 0x80029324: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80029328: b           L_80029330
    // 0x8002932C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80029330;
    // 0x8002932C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80029330:
    // 0x80029330: beq         $v0, $zero, L_80029400
    if (ctx->r2 == 0) {
        // 0x80029334: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029400;
    }
    // 0x80029334: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029338: beq         $s0, $zero, L_800293FC
    if (ctx->r16 == 0) {
        // 0x8002933C: andi        $t2, $v1, 0x100
        ctx->r10 = ctx->r3 & 0X100;
            goto L_800293FC;
    }
    // 0x8002933C: andi        $t2, $v1, 0x100
    ctx->r10 = ctx->r3 & 0X100;
    // 0x80029340: beq         $t2, $zero, L_80029400
    if (ctx->r10 == 0) {
        // 0x80029344: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029400;
    }
    // 0x80029344: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029348: lh          $t1, 0x2E($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2E);
    // 0x8002934C: nop

    // 0x80029350: addu        $t3, $s6, $t1
    ctx->r11 = ADD32(ctx->r22, ctx->r9);
    // 0x80029354: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x80029358: nop

    // 0x8002935C: beq         $t4, $zero, L_80029400
    if (ctx->r12 == 0) {
        // 0x80029360: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029400;
    }
    // 0x80029360: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029364: jal         0x8002A940
    // 0x80029368: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    check_if_in_draw_range(rdram, ctx);
        goto after_15;
    // 0x80029368: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x8002936C: beq         $v0, $zero, L_80029400
    if (ctx->r2 == 0) {
        // 0x80029370: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029400;
    }
    // 0x80029370: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029374: lh          $t5, 0x6($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X6);
    // 0x80029378: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002937C: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x80029380: beq         $t6, $zero, L_8002939C
    if (ctx->r14 == 0) {
        // 0x80029384: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_8002939C;
    }
    // 0x80029384: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029388: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002938C: jal         0x80012D5C
    // 0x80029390: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_16;
    // 0x80029390: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_16:
    // 0x80029394: b           L_80029400
    // 0x80029398: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
        goto L_80029400;
    // 0x80029398: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_8002939C:
    // 0x8002939C: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    // 0x800293A0: nop

    // 0x800293A4: beq         $a1, $zero, L_800293B8
    if (ctx->r5 == 0) {
        // 0x800293A8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800293B8;
    }
    // 0x800293A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800293AC: jal         0x8002D3C4
    // 0x800293B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_render(rdram, ctx);
        goto after_17;
    // 0x800293B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x800293B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_800293B8:
    // 0x800293B8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800293BC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800293C0: jal         0x80012D5C
    // 0x800293C4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_18;
    // 0x800293C4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_18:
    // 0x800293C8: lw          $a1, 0x58($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X58);
    // 0x800293CC: nop

    // 0x800293D0: beq         $a1, $zero, L_80029400
    if (ctx->r5 == 0) {
        // 0x800293D4: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029400;
    }
    // 0x800293D4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800293D8: lw          $t7, 0x40($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X40);
    // 0x800293DC: nop

    // 0x800293E0: lhu         $t8, 0x30($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X30);
    // 0x800293E4: nop

    // 0x800293E8: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x800293EC: beq         $t9, $zero, L_80029400
    if (ctx->r25 == 0) {
        // 0x800293F0: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029400;
    }
    // 0x800293F0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800293F4: jal         0x8002D6B0
    // 0x800293F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    watereffect_render(rdram, ctx);
        goto after_19;
    // 0x800293F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
L_800293FC:
    // 0x800293FC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_80029400:
    // 0x80029400: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80029404: bne         $s2, $t0, L_80029308
    if (ctx->r18 != ctx->r8) {
        // 0x80029408: nop
    
            goto L_80029308;
    }
    // 0x80029408: nop

L_8002940C:
    // 0x8002940C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80029410: lb          $t2, -0x49A0($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X49A0);
    // 0x80029414: lw          $v0, 0x168($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X168);
    // 0x80029418: beq         $t2, $zero, L_8002944C
    if (ctx->r10 == 0) {
        // 0x8002941C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8002944C;
    }
    // 0x8002941C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80029420: bltz        $v0, L_8002944C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80029424: addiu       $t1, $sp, 0xD8
        ctx->r9 = ADD32(ctx->r29, 0XD8);
            goto L_8002944C;
    }
    // 0x80029424: addiu       $t1, $sp, 0xD8
    ctx->r9 = ADD32(ctx->r29, 0XD8);
    // 0x80029428: addu        $s0, $v0, $t1
    ctx->r16 = ADD32(ctx->r2, ctx->r9);
    // 0x8002942C: addiu       $s1, $sp, 0xD8
    ctx->r17 = ADD32(ctx->r29, 0XD8);
L_80029430:
    // 0x80029430: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80029434: jal         0x80029698
    // 0x80029438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    render_level_segment(rdram, ctx);
        goto after_20;
    // 0x80029438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x8002943C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80029440: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80029444: beq         $at, $zero, L_80029430
    if (ctx->r1 == 0) {
        // 0x80029448: nop
    
            goto L_80029430;
    }
    // 0x80029448: nop

L_8002944C:
    // 0x8002944C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80029450: lw          $t3, -0x26FC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X26FC);
    // 0x80029454: nop

    // 0x80029458: beq         $t3, $zero, L_80029478
    if (ctx->r11 == 0) {
        // 0x8002945C: nop
    
            goto L_80029478;
    }
    // 0x8002945C: nop

    // 0x80029460: jal         0x80066460
    // 0x80029464: nop

    get_current_viewport(rdram, ctx);
        goto after_21;
    // 0x80029464: nop

    after_21:
    // 0x80029468: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002946C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029470: jal         0x800BAE04
    // 0x80029474: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    waves_render(rdram, ctx);
        goto after_22;
    // 0x80029474: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_22:
L_80029478:
    // 0x80029478: jal         0x8007B820
    // 0x8002947C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rendermode_reset(rdram, ctx);
        goto after_23;
    // 0x8002947C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_23:
    // 0x80029480: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80029484: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029488: jal         0x8007B918
    // 0x8002948C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    material_set_no_tex_offset(rdram, ctx);
        goto after_24;
    // 0x8002948C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_24:
    // 0x80029490: jal         0x80012C3C
    // 0x80029494: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80012C3C(rdram, ctx);
        goto after_25;
    // 0x80029494: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_25:
    // 0x80029498: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x8002949C: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x800294A0: addiu       $s2, $v1, -0x1
    ctx->r18 = ADD32(ctx->r3, -0X1);
    // 0x800294A4: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800294A8: bne         $at, $zero, L_8002962C
    if (ctx->r1 != 0) {
        // 0x800294AC: addiu       $t5, $t4, -0x1
        ctx->r13 = ADD32(ctx->r12, -0X1);
            goto L_8002962C;
    }
    // 0x800294AC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800294B0: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x800294B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800294B8:
    // 0x800294B8: jal         0x8000E948
    // 0x800294BC: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    get_object(rdram, ctx);
        goto after_26;
    // 0x800294BC: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    after_26:
    // 0x800294C0: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x800294C4: lw          $t8, 0x158($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X158);
    // 0x800294C8: andi        $t6, $v1, 0x80
    ctx->r14 = ctx->r3 & 0X80;
    // 0x800294CC: beq         $t6, $zero, L_800294DC
    if (ctx->r14 == 0) {
        // 0x800294D0: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800294DC;
    }
    // 0x800294D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800294D4: b           L_800294F0
    // 0x800294D8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800294F0;
    // 0x800294D8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800294DC:
    // 0x800294DC: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
    // 0x800294E0: bne         $t7, $zero, L_800294F4
    if (ctx->r15 != 0) {
        // 0x800294E4: and         $t9, $v1, $t8
        ctx->r25 = ctx->r3 & ctx->r24;
            goto L_800294F4;
    }
    // 0x800294E4: and         $t9, $v1, $t8
    ctx->r25 = ctx->r3 & ctx->r24;
    // 0x800294E8: lbu         $s0, 0x39($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X39);
    // 0x800294EC: nop

L_800294F0:
    // 0x800294F0: and         $t9, $v1, $t8
    ctx->r25 = ctx->r3 & ctx->r24;
L_800294F4:
    // 0x800294F4: beq         $t9, $zero, L_80029500
    if (ctx->r25 == 0) {
        // 0x800294F8: nop
    
            goto L_80029500;
    }
    // 0x800294F8: nop

    // 0x800294FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80029500:
    // 0x80029500: lh          $t0, 0x48($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X48);
    // 0x80029504: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80029508: bne         $t0, $at, L_8002951C
    if (ctx->r8 != ctx->r1) {
        // 0x8002950C: slti        $at, $s0, 0xFF
        ctx->r1 = SIGNED(ctx->r16) < 0XFF ? 1 : 0;
            goto L_8002951C;
    }
    // 0x8002950C: slti        $at, $s0, 0xFF
    ctx->r1 = SIGNED(ctx->r16) < 0XFF ? 1 : 0;
    // 0x80029510: bne         $at, $zero, L_8002951C
    if (ctx->r1 != 0) {
        // 0x80029514: nop
    
            goto L_8002951C;
    }
    // 0x80029514: nop

    // 0x80029518: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002951C:
    // 0x8002951C: beq         $v0, $zero, L_8002961C
    if (ctx->r2 == 0) {
        // 0x80029520: slti        $at, $s0, 0xFF
        ctx->r1 = SIGNED(ctx->r16) < 0XFF ? 1 : 0;
            goto L_8002961C;
    }
    // 0x80029520: slti        $at, $s0, 0xFF
    ctx->r1 = SIGNED(ctx->r16) < 0XFF ? 1 : 0;
    // 0x80029524: beq         $at, $zero, L_80029620
    if (ctx->r1 == 0) {
        // 0x80029528: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029620;
    }
    // 0x80029528: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8002952C: lh          $t2, 0x2E($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X2E);
    // 0x80029530: nop

    // 0x80029534: addu        $t1, $s6, $t2
    ctx->r9 = ADD32(ctx->r22, ctx->r10);
    // 0x80029538: lbu         $t3, 0x1($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X1);
    // 0x8002953C: nop

    // 0x80029540: beq         $t3, $zero, L_80029620
    if (ctx->r11 == 0) {
        // 0x80029544: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029620;
    }
    // 0x80029544: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029548: jal         0x8002A940
    // 0x8002954C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    check_if_in_draw_range(rdram, ctx);
        goto after_27;
    // 0x8002954C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_27:
    // 0x80029550: beq         $v0, $zero, L_80029620
    if (ctx->r2 == 0) {
        // 0x80029554: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029620;
    }
    // 0x80029554: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029558: blez        $s0, L_800295E8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8002955C: nop
    
            goto L_800295E8;
    }
    // 0x8002955C: nop

    // 0x80029560: lh          $t4, 0x6($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X6);
    // 0x80029564: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80029568: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x8002956C: beq         $t5, $zero, L_80029588
    if (ctx->r13 == 0) {
        // 0x80029570: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_80029588;
    }
    // 0x80029570: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029574: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80029578: jal         0x80012D5C
    // 0x8002957C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_28;
    // 0x8002957C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_28:
    // 0x80029580: b           L_800295EC
    // 0x80029584: lh          $t9, 0x48($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X48);
        goto L_800295EC;
    // 0x80029584: lh          $t9, 0x48($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X48);
L_80029588:
    // 0x80029588: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    // 0x8002958C: nop

    // 0x80029590: beq         $a1, $zero, L_800295A4
    if (ctx->r5 == 0) {
        // 0x80029594: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800295A4;
    }
    // 0x80029594: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80029598: jal         0x8002D3C4
    // 0x8002959C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_render(rdram, ctx);
        goto after_29;
    // 0x8002959C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_29:
    // 0x800295A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_800295A4:
    // 0x800295A4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800295A8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800295AC: jal         0x80012D5C
    // 0x800295B0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_30;
    // 0x800295B0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_30:
    // 0x800295B4: lw          $a1, 0x58($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X58);
    // 0x800295B8: nop

    // 0x800295BC: beq         $a1, $zero, L_800295E8
    if (ctx->r5 == 0) {
        // 0x800295C0: nop
    
            goto L_800295E8;
    }
    // 0x800295C0: nop

    // 0x800295C4: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x800295C8: nop

    // 0x800295CC: lhu         $t7, 0x30($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X30);
    // 0x800295D0: nop

    // 0x800295D4: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x800295D8: beq         $t8, $zero, L_800295E8
    if (ctx->r24 == 0) {
        // 0x800295DC: nop
    
            goto L_800295E8;
    }
    // 0x800295DC: nop

    // 0x800295E0: jal         0x8002D6B0
    // 0x800295E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    watereffect_render(rdram, ctx);
        goto after_31;
    // 0x800295E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_31:
L_800295E8:
    // 0x800295E8: lh          $t9, 0x48($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X48);
L_800295EC:
    // 0x800295EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800295F0: bne         $t9, $at, L_8002961C
    if (ctx->r25 != ctx->r1) {
        // 0x800295F4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8002961C;
    }
    // 0x800295F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800295F8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800295FC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80029600: jal         0x80013A0C
    // 0x80029604: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_racer_shield(rdram, ctx);
        goto after_32;
    // 0x80029604: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_32:
    // 0x80029608: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002960C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029610: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80029614: jal         0x80013DCC
    // 0x80029618: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_racer_magnet(rdram, ctx);
        goto after_33;
    // 0x80029618: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_33:
L_8002961C:
    // 0x8002961C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_80029620:
    // 0x80029620: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80029624: bne         $s2, $t0, L_800294B8
    if (ctx->r18 != ctx->r8) {
        // 0x80029628: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800294B8;
    }
    // 0x80029628: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8002962C:
    // 0x8002962C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80029630: lw          $t2, -0x316C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X316C);
    // 0x80029634: nop

    // 0x80029638: beq         $t2, $zero, L_8002966C
    if (ctx->r10 == 0) {
        // 0x8002963C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8002966C;
    }
    // 0x8002963C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80029640: jal         0x800275A8
    // 0x80029644: nop

    func_80027568(rdram, ctx);
        goto after_34;
    // 0x80029644: nop

    after_34:
    // 0x80029648: beq         $v0, $zero, L_8002966C
    if (ctx->r2 == 0) {
        // 0x8002964C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8002966C;
    }
    // 0x8002964C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80029650: jal         0x80066460
    // 0x80029654: nop

    get_current_viewport(rdram, ctx);
        goto after_35;
    // 0x80029654: nop

    after_35:
    // 0x80029658: lw          $a1, 0x168($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X168);
    // 0x8002965C: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x80029660: jal         0x8002585C
    // 0x80029664: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    void_check(rdram, ctx);
        goto after_36;
    // 0x80029664: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_36:
    // 0x80029668: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8002966C:
    // 0x8002966C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80029670: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80029674: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80029678: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002967C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80029680: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80029684: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80029688: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8002968C: sw          $zero, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = 0;
    // 0x80029690: jr          $ra
    // 0x80029694: addiu       $sp, $sp, 0x170
    ctx->r29 = ADD32(ctx->r29, 0X170);
    return;
    // 0x80029694: addiu       $sp, $sp, 0x170
    ctx->r29 = ADD32(ctx->r29, 0X170);
;}
RECOMP_FUNC void obj_loop_butterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040C94: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80040C98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80040C9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80040CA0: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x80040CA4: lw          $t1, 0x3C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X3C);
    // 0x80040CA8: lw          $t0, 0x64($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X64);
    // 0x80040CAC: lbu         $t6, 0xA($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0XA);
    // 0x80040CB0: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x80040CB4: xori        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 ^ 0X2;
    // 0x80040CB8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80040CBC: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x80040CC0: lh          $v1, 0x106($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X106);
    // 0x80040CC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80040CC8: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x80040CCC: sra         $t8, $t2, 16
    ctx->r24 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80040CD0: bgez        $t8, L_80040CE4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80040CD4: or          $t2, $t8, $zero
        ctx->r10 = ctx->r24 | 0;
            goto L_80040CE4;
    }
    // 0x80040CD4: or          $t2, $t8, $zero
    ctx->r10 = ctx->r24 | 0;
    // 0x80040CD8: negu        $t2, $t8
    ctx->r10 = SUB32(0, ctx->r24);
    // 0x80040CDC: sll         $t9, $t2, 16
    ctx->r25 = S32(ctx->r10 << 16);
    // 0x80040CE0: sra         $t2, $t9, 16
    ctx->r10 = S32(SIGNED(ctx->r25) >> 16);
L_80040CE4:
    // 0x80040CE4: multu       $t2, $t4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040CE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80040CEC: lwc1        $f0, 0x67AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X67AC);
    // 0x80040CF0: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80040CF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80040CF8: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80040CFC: mflo        $t2
    ctx->r10 = lo;
    // 0x80040D00: sll         $t5, $t2, 16
    ctx->r13 = S32(ctx->r10 << 16);
    // 0x80040D04: beq         $t7, $zero, L_80040D1C
    if (ctx->r15 == 0) {
        // 0x80040D08: sra         $t2, $t5, 16
        ctx->r10 = S32(SIGNED(ctx->r13) >> 16);
            goto L_80040D1C;
    }
    // 0x80040D08: sra         $t2, $t5, 16
    ctx->r10 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80040D0C: lwc1        $f4, 0x67B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X67B0);
    // 0x80040D10: nop

    // 0x80040D14: mul.s       $f16, $f0, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80040D18: nop

L_80040D1C:
    // 0x80040D1C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80040D20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80040D24: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80040D28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80040D2C: beq         $t8, $zero, L_80040D44
    if (ctx->r24 == 0) {
        // 0x80040D30: swc1        $f0, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
            goto L_80040D44;
    }
    // 0x80040D30: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x80040D34: lwc1        $f6, 0x67B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X67B4);
    // 0x80040D38: nop

    // 0x80040D3C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80040D40: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
L_80040D44:
    // 0x80040D44: lbu         $v0, 0xFD($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XFD);
    // 0x80040D48: nop

    // 0x80040D4C: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x80040D50: beq         $at, $zero, L_80041878
    if (ctx->r1 == 0) {
        // 0x80040D54: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80041878;
    }
    // 0x80040D54: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80040D58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80040D5C: addu        $at, $at, $t9
    gpr jr_addend_80040D68 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80040D60: lw          $t9, 0x67B8($at)
    ctx->r25 = ADD32(ctx->r1, 0X67B8);
    // 0x80040D64: nop

    // 0x80040D68: jr          $t9
    // 0x80040D6C: nop

    switch (jr_addend_80040D68 >> 2) {
        case 0: goto L_80040D70; break;
        case 1: goto L_80040E94; break;
        case 2: goto L_80040E94; break;
        case 3: goto L_80041224; break;
        case 4: goto L_8004157C; break;
        default: switch_error(__func__, 0x80040D68, 0x800E67B8);
    }
    // 0x80040D6C: nop

L_80040D70:
    // 0x80040D70: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80040D74: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80040D78: swc1        $f14, 0x108($t0)
    MEM_W(0X108, ctx->r8) = ctx->f14.u32l;
    // 0x80040D7C: lhu         $t3, 0x8($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X8);
    // 0x80040D80: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x80040D84: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80040D88: bgez        $t3, L_80040DA0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80040D8C: cvt.s.w     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80040DA0;
    }
    // 0x80040D8C: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80040D90: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80040D94: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80040D98: nop

    // 0x80040D9C: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
L_80040DA0:
    // 0x80040DA0: lh          $t5, 0x6($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X6);
    // 0x80040DA4: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x80040DA8: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80040DAC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80040DB0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80040DB4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80040DB8: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x80040DBC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80040DC0: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80040DC4: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80040DC8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80040DCC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80040DD0: jal         0x80016E1C
    // 0x80040DD4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    obj_dist_racer(rdram, ctx);
        goto after_0;
    // 0x80040DD4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x80040DD8: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80040DDC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80040DE0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80040DE4: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80040DE8: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80040DEC: blez        $t9, L_80040E10
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80040DF0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80040E10;
    }
    // 0x80040DF0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80040DF4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80040DF8: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x80040DFC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80040E00: sh          $t4, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r12;
    // 0x80040E04: sb          $t5, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r13;
    // 0x80040E08: b           L_80040E5C
    // 0x80040E0C: sw          $t3, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r11;
        goto L_80040E5C;
    // 0x80040E0C: sw          $t3, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r11;
L_80040E10:
    // 0x80040E10: lh          $t7, 0x6($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X6);
    // 0x80040E14: lh          $t6, 0x2($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X2);
    // 0x80040E18: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80040E1C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80040E20: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80040E24: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80040E28: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80040E2C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80040E30: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80040E34: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80040E38: jal         0x80016C9C
    // 0x80040E3C: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    obj_butterfly_node(rdram, ctx);
        goto after_1;
    // 0x80040E3C: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_1:
    // 0x80040E40: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80040E44: beq         $v0, $zero, L_80040E5C
    if (ctx->r2 == 0) {
        // 0x80040E48: sw          $v0, 0x100($t0)
        MEM_W(0X100, ctx->r8) = ctx->r2;
            goto L_80040E5C;
    }
    // 0x80040E48: sw          $v0, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r2;
    // 0x80040E4C: addiu       $t9, $zero, 0xF0
    ctx->r25 = ADD32(0, 0XF0);
    // 0x80040E50: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80040E54: sh          $t9, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r25;
    // 0x80040E58: sb          $t3, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r11;
L_80040E5C:
    // 0x80040E5C: lh          $t4, 0x18($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X18);
    // 0x80040E60: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x80040E64: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x80040E68: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80040E6C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80040E70: sh          $t7, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r15;
    // 0x80040E74: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80040E78: nop

    // 0x80040E7C: beq         $t8, $zero, L_80040E88
    if (ctx->r24 == 0) {
        // 0x80040E80: nop
    
            goto L_80040E88;
    }
    // 0x80040E80: nop

    // 0x80040E84: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
L_80040E88:
    // 0x80040E88: lbu         $v0, 0xFD($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XFD);
    // 0x80040E8C: b           L_80041878
    // 0x80040E90: nop

        goto L_80041878;
    // 0x80040E90: nop

L_80040E94:
    // 0x80040E94: slti        $at, $v1, 0x480
    ctx->r1 = SIGNED(ctx->r3) < 0X480 ? 1 : 0;
    // 0x80040E98: beq         $at, $zero, L_80040ECC
    if (ctx->r1 == 0) {
        // 0x80040E9C: nop
    
            goto L_80040ECC;
    }
    // 0x80040E9C: nop

    // 0x80040EA0: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x80040EA4: addiu       $t7, $zero, 0x480
    ctx->r15 = ADD32(0, 0X480);
    // 0x80040EA8: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80040EAC: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x80040EB0: sh          $t5, 0x106($t0)
    MEM_H(0X106, ctx->r8) = ctx->r13;
    // 0x80040EB4: lh          $t6, 0x106($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X106);
    // 0x80040EB8: nop

    // 0x80040EBC: slti        $at, $t6, 0x481
    ctx->r1 = SIGNED(ctx->r14) < 0X481 ? 1 : 0;
    // 0x80040EC0: bne         $at, $zero, L_80040ECC
    if (ctx->r1 != 0) {
        // 0x80040EC4: nop
    
            goto L_80040ECC;
    }
    // 0x80040EC4: nop

    // 0x80040EC8: sh          $t7, 0x106($t0)
    MEM_H(0X106, ctx->r8) = ctx->r15;
L_80040ECC:
    // 0x80040ECC: lh          $t8, 0x2($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X2);
    // 0x80040ED0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80040ED4: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80040ED8: lh          $t9, 0x6($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X6);
    // 0x80040EDC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80040EE0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80040EE4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80040EE8: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x80040EEC: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x80040EF0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80040EF4: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80040EF8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80040EFC: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80040F00: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80040F04: sub.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80040F08: swc1        $f12, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f12.u32l;
    // 0x80040F0C: swc1        $f14, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f14.u32l;
    // 0x80040F10: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80040F14: jal         0x80070990
    // 0x80040F18: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x80040F18: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_2:
    // 0x80040F1C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80040F20: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80040F24: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
    // 0x80040F28: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x80040F2C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80040F30: lh          $t2, 0x72($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X72);
    // 0x80040F34: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80040F38: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80040F3C: bgez        $t8, L_80040F68
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80040F40: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_80040F68;
    }
    // 0x80040F40: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80040F44: negu        $t9, $t2
    ctx->r25 = SUB32(0, ctx->r10);
    // 0x80040F48: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80040F4C: beq         $at, $zero, L_80040F60
    if (ctx->r1 == 0) {
        // 0x80040F50: subu        $t4, $a0, $t2
        ctx->r12 = SUB32(ctx->r4, ctx->r10);
            goto L_80040F60;
    }
    // 0x80040F50: subu        $t4, $a0, $t2
    ctx->r12 = SUB32(ctx->r4, ctx->r10);
    // 0x80040F54: addu        $t3, $a0, $t8
    ctx->r11 = ADD32(ctx->r4, ctx->r24);
    // 0x80040F58: b           L_80040F88
    // 0x80040F5C: sh          $t3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r11;
        goto L_80040F88;
    // 0x80040F5C: sh          $t3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r11;
L_80040F60:
    // 0x80040F60: b           L_80040F88
    // 0x80040F64: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
        goto L_80040F88;
    // 0x80040F64: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
L_80040F68:
    // 0x80040F68: blez        $v1, L_80040F88
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80040F6C: slt         $at, $v1, $t2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80040F88;
    }
    // 0x80040F6C: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80040F70: beq         $at, $zero, L_80040F84
    if (ctx->r1 == 0) {
        // 0x80040F74: addu        $t6, $a0, $t2
        ctx->r14 = ADD32(ctx->r4, ctx->r10);
            goto L_80040F84;
    }
    // 0x80040F74: addu        $t6, $a0, $t2
    ctx->r14 = ADD32(ctx->r4, ctx->r10);
    // 0x80040F78: addu        $t5, $a0, $v1
    ctx->r13 = ADD32(ctx->r4, ctx->r3);
    // 0x80040F7C: b           L_80040F88
    // 0x80040F80: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
        goto L_80040F88;
    // 0x80040F80: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
L_80040F84:
    // 0x80040F84: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
L_80040F88:
    // 0x80040F88: lh          $t7, 0x4($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X4);
    // 0x80040F8C: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80040F90: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80040F94: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80040F98: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80040F9C: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x80040FA0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80040FA4: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80040FA8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80040FAC: nop

    // 0x80040FB0: bc1f        L_80040FF0
    if (!c1cs) {
        // 0x80040FB4: nop
    
            goto L_80040FF0;
    }
    // 0x80040FB4: nop

    // 0x80040FB8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80040FBC: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80040FC0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80040FC4: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80040FC8: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80040FCC: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x80040FD0: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80040FD4: nop

    // 0x80040FD8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80040FDC: nop

    // 0x80040FE0: bc1f        L_8004104C
    if (!c1cs) {
        // 0x80040FE4: nop
    
            goto L_8004104C;
    }
    // 0x80040FE4: nop

    // 0x80040FE8: b           L_8004104C
    // 0x80040FEC: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
        goto L_8004104C;
    // 0x80040FEC: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
L_80040FF0:
    // 0x80040FF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80040FF4: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x80040FF8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80040FFC: nop

    // 0x80041000: bc1f        L_80041040
    if (!c1cs) {
        // 0x80041004: nop
    
            goto L_80041040;
    }
    // 0x80041004: nop

    // 0x80041008: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8004100C: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80041010: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80041014: mul.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80041018: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8004101C: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x80041020: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80041024: nop

    // 0x80041028: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8004102C: nop

    // 0x80041030: bc1f        L_8004104C
    if (!c1cs) {
        // 0x80041034: nop
    
            goto L_8004104C;
    }
    // 0x80041034: nop

    // 0x80041038: b           L_8004104C
    // 0x8004103C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
        goto L_8004104C;
    // 0x8004103C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
L_80041040:
    // 0x80041040: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80041044: nop

    // 0x80041048: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
L_8004104C:
    // 0x8004104C: lbu         $t3, 0xFD($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XFD);
    // 0x80041050: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80041054: bne         $t3, $at, L_80041144
    if (ctx->r11 != ctx->r1) {
        // 0x80041058: addiu       $t8, $sp, 0x44
        ctx->r24 = ADD32(ctx->r29, 0X44);
            goto L_80041144;
    }
    // 0x80041058: addiu       $t8, $sp, 0x44
    ctx->r24 = ADD32(ctx->r29, 0X44);
    // 0x8004105C: lhu         $t4, 0x8($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X8);
    // 0x80041060: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80041064: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80041068: bgez        $t4, L_80041080
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8004106C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80041080;
    }
    // 0x8004106C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80041070: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80041074: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80041078: nop

    // 0x8004107C: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
L_80041080:
    // 0x80041080: lh          $t6, 0x6($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X6);
    // 0x80041084: lh          $t5, 0x2($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X2);
    // 0x80041088: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8004108C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80041090: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80041094: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80041098: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x8004109C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800410A0: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x800410A4: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x800410A8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800410AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800410B0: jal         0x80016E1C
    // 0x800410B4: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    obj_dist_racer(rdram, ctx);
        goto after_3;
    // 0x800410B4: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_3:
    // 0x800410B8: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x800410BC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800410C0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800410C4: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800410C8: sra         $t3, $t9, 16
    ctx->r11 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800410CC: blez        $t3, L_800410F0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800410D0: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800410F0;
    }
    // 0x800410D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800410D4: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800410D8: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x800410DC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800410E0: sh          $t5, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r13;
    // 0x800410E4: sb          $t6, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r14;
    // 0x800410E8: b           L_80041144
    // 0x800410EC: sw          $t4, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r12;
        goto L_80041144;
    // 0x800410EC: sw          $t4, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r12;
L_800410F0:
    // 0x800410F0: lh          $t8, 0x6($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X6);
    // 0x800410F4: lh          $t7, 0x2($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X2);
    // 0x800410F8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800410FC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80041100: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80041104: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80041108: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8004110C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80041110: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80041114: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80041118: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8004111C: jal         0x80016C9C
    // 0x80041120: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    obj_butterfly_node(rdram, ctx);
        goto after_4;
    // 0x80041120: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_4:
    // 0x80041124: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80041128: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8004112C: beq         $v0, $zero, L_80041144
    if (ctx->r2 == 0) {
        // 0x80041130: sw          $v0, 0x100($t0)
        MEM_W(0X100, ctx->r8) = ctx->r2;
            goto L_80041144;
    }
    // 0x80041130: sw          $v0, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r2;
    // 0x80041134: addiu       $t3, $zero, 0xF0
    ctx->r11 = ADD32(0, 0XF0);
    // 0x80041138: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8004113C: sh          $t3, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r11;
    // 0x80041140: sb          $t4, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r12;
L_80041144:
    // 0x80041144: lbu         $t5, 0xFD($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0XFD);
    // 0x80041148: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004114C: beq         $t5, $at, L_80041200
    if (ctx->r13 == ctx->r1) {
        // 0x80041150: nop
    
            goto L_80041200;
    }
    // 0x80041150: nop

    // 0x80041154: lh          $t6, 0x4($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X4);
    // 0x80041158: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8004115C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80041160: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80041164: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80041168: lwc1        $f14, 0x8C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8004116C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80041170: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80041174: sub.s       $f2, $f18, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80041178: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    // 0x8004117C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80041180: nop

    // 0x80041184: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80041188: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8004118C: jal         0x800CA030
    // 0x80041190: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x80041190: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_5:
    // 0x80041194: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80041198: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004119C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800411A0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800411A4: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800411A8: bc1f        L_80041200
    if (!c1cs) {
        // 0x800411AC: nop
    
            goto L_80041200;
    }
    // 0x800411AC: nop

    // 0x800411B0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x800411B4: jal         0x80011560
    // 0x800411B8: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    ignore_bounds_check(rdram, ctx);
        goto after_6;
    // 0x800411B8: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x800411BC: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800411C0: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800411C4: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800411C8: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x800411CC: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x800411D0: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x800411D4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800411D8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800411DC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800411E0: jal         0x80011570
    // 0x800411E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_object(rdram, ctx);
        goto after_7;
    // 0x800411E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800411E8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800411EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800411F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800411F4: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x800411F8: sb          $zero, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = 0;
    // 0x800411FC: swc1        $f4, 0x108($t0)
    MEM_W(0X108, ctx->r8) = ctx->f4.u32l;
L_80041200:
    // 0x80041200: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x80041204: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80041208: nop

    // 0x8004120C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80041210: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x80041214: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
    // 0x80041218: lbu         $v0, 0xFD($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XFD);
    // 0x8004121C: b           L_80041878
    // 0x80041220: nop

        goto L_80041878;
    // 0x80041220: nop

L_80041224:
    // 0x80041224: slti        $at, $v1, 0x480
    ctx->r1 = SIGNED(ctx->r3) < 0X480 ? 1 : 0;
    // 0x80041228: beq         $at, $zero, L_8004125C
    if (ctx->r1 == 0) {
        // 0x8004122C: nop
    
            goto L_8004125C;
    }
    // 0x8004122C: nop

    // 0x80041230: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x80041234: addiu       $t8, $zero, 0x480
    ctx->r24 = ADD32(0, 0X480);
    // 0x80041238: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8004123C: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x80041240: sh          $t6, 0x106($t0)
    MEM_H(0X106, ctx->r8) = ctx->r14;
    // 0x80041244: lh          $t7, 0x106($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X106);
    // 0x80041248: nop

    // 0x8004124C: slti        $at, $t7, 0x481
    ctx->r1 = SIGNED(ctx->r15) < 0X481 ? 1 : 0;
    // 0x80041250: bne         $at, $zero, L_8004125C
    if (ctx->r1 != 0) {
        // 0x80041254: nop
    
            goto L_8004125C;
    }
    // 0x80041254: nop

    // 0x80041258: sh          $t8, 0x106($t0)
    MEM_H(0X106, ctx->r8) = ctx->r24;
L_8004125C:
    // 0x8004125C: lh          $t9, 0x2($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X2);
    // 0x80041260: lw          $v0, 0x100($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X100);
    // 0x80041264: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80041268: lhu         $t4, 0x8($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X8);
    // 0x8004126C: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80041270: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80041274: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80041278: sub.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8004127C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80041280: lh          $t3, 0x6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X6);
    // 0x80041284: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80041288: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8004128C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80041290: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80041294: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x80041298: addiu       $t5, $sp, 0x44
    ctx->r13 = ADD32(ctx->r29, 0X44);
    // 0x8004129C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800412A0: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800412A4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800412A8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800412AC: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800412B0: sub.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800412B4: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800412B8: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800412BC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800412C0: nop

    // 0x800412C4: bc1f        L_800413C0
    if (!c1cs) {
        // 0x800412C8: nop
    
            goto L_800413C0;
    }
    // 0x800412C8: nop

    // 0x800412CC: sw          $zero, 0x100($t0)
    MEM_W(0X100, ctx->r8) = 0;
    // 0x800412D0: lhu         $t8, 0x8($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X8);
    // 0x800412D4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800412D8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800412DC: bgez        $t8, L_800412F4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800412E0: cvt.s.w     $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800412F4;
    }
    // 0x800412E0: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800412E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800412E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800412EC: nop

    // 0x800412F0: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_800412F4:
    // 0x800412F4: lh          $t9, 0x2($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X2);
    // 0x800412F8: lh          $t3, 0x6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X6);
    // 0x800412FC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80041300: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80041304: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80041308: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004130C: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x80041310: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x80041314: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80041318: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x8004131C: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80041320: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80041324: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80041328: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8004132C: jal         0x80016E1C
    // 0x80041330: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    obj_dist_racer(rdram, ctx);
        goto after_8;
    // 0x80041330: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_8:
    // 0x80041334: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x80041338: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8004133C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80041340: lh          $t2, 0x72($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X72);
    // 0x80041344: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80041348: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8004134C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80041350: blez        $t7, L_8004136C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80041354: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8004136C;
    }
    // 0x80041354: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80041358: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8004135C: addiu       $t9, $zero, 0xF0
    ctx->r25 = ADD32(0, 0XF0);
    // 0x80041360: sh          $t9, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r25;
    // 0x80041364: b           L_800413C0
    // 0x80041368: sw          $t8, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r24;
        goto L_800413C0;
    // 0x80041368: sw          $t8, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r24;
L_8004136C:
    // 0x8004136C: lh          $t4, 0x6($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X6);
    // 0x80041370: lh          $t3, 0x2($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X2);
    // 0x80041374: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80041378: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8004137C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80041380: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80041384: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80041388: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8004138C: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x80041390: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80041394: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80041398: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8004139C: jal         0x80016C9C
    // 0x800413A0: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    obj_butterfly_node(rdram, ctx);
        goto after_9;
    // 0x800413A0: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_9:
    // 0x800413A4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800413A8: lh          $t2, 0x72($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X72);
    // 0x800413AC: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800413B0: beq         $v0, $zero, L_800413C0
    if (ctx->r2 == 0) {
        // 0x800413B4: sw          $v0, 0x100($t0)
        MEM_W(0X100, ctx->r8) = ctx->r2;
            goto L_800413C0;
    }
    // 0x800413B4: sw          $v0, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r2;
    // 0x800413B8: addiu       $t6, $zero, 0xF0
    ctx->r14 = ADD32(0, 0XF0);
    // 0x800413BC: sh          $t6, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r14;
L_800413C0:
    // 0x800413C0: lw          $v0, 0x100($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X100);
    // 0x800413C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800413C8: beq         $v0, $zero, L_80041554
    if (ctx->r2 == 0) {
        // 0x800413CC: nop
    
            goto L_80041554;
    }
    // 0x800413CC: nop

    // 0x800413D0: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800413D4: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800413D8: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800413DC: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800413E0: sub.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800413E4: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x800413E8: sub.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800413EC: swc1        $f12, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f12.u32l;
    // 0x800413F0: swc1        $f14, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f14.u32l;
    // 0x800413F4: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x800413F8: jal         0x80070990
    // 0x800413FC: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    arctan2_f(rdram, ctx);
        goto after_10;
    // 0x800413FC: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_10:
    // 0x80041400: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80041404: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80041408: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
    // 0x8004140C: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x80041410: lh          $t2, 0x72($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X72);
    // 0x80041414: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80041418: sra         $t3, $t9, 16
    ctx->r11 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004141C: bgez        $t3, L_80041448
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80041420: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80041448;
    }
    // 0x80041420: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80041424: negu        $t4, $t2
    ctx->r12 = SUB32(0, ctx->r10);
    // 0x80041428: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8004142C: beq         $at, $zero, L_80041440
    if (ctx->r1 == 0) {
        // 0x80041430: subu        $t6, $a0, $t2
        ctx->r14 = SUB32(ctx->r4, ctx->r10);
            goto L_80041440;
    }
    // 0x80041430: subu        $t6, $a0, $t2
    ctx->r14 = SUB32(ctx->r4, ctx->r10);
    // 0x80041434: addu        $t5, $a0, $t3
    ctx->r13 = ADD32(ctx->r4, ctx->r11);
    // 0x80041438: b           L_80041468
    // 0x8004143C: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
        goto L_80041468;
    // 0x8004143C: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
L_80041440:
    // 0x80041440: b           L_80041468
    // 0x80041444: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
        goto L_80041468;
    // 0x80041444: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
L_80041448:
    // 0x80041448: blez        $v1, L_80041468
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004144C: slt         $at, $v1, $t2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80041468;
    }
    // 0x8004144C: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80041450: beq         $at, $zero, L_80041464
    if (ctx->r1 == 0) {
        // 0x80041454: addu        $t8, $a0, $t2
        ctx->r24 = ADD32(ctx->r4, ctx->r10);
            goto L_80041464;
    }
    // 0x80041454: addu        $t8, $a0, $t2
    ctx->r24 = ADD32(ctx->r4, ctx->r10);
    // 0x80041458: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x8004145C: b           L_80041468
    // 0x80041460: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
        goto L_80041468;
    // 0x80041460: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_80041464:
    // 0x80041464: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_80041468:
    // 0x80041468: lw          $t9, 0x100($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X100);
    // 0x8004146C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80041470: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80041474: lwc1        $f18, 0x10($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80041478: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8004147C: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80041480: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80041484: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80041488: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x8004148C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80041490: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80041494: bc1f        L_800414D4
    if (!c1cs) {
        // 0x80041498: nop
    
            goto L_800414D4;
    }
    // 0x80041498: nop

    // 0x8004149C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800414A0: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800414A4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800414A8: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800414AC: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800414B0: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x800414B4: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800414B8: nop

    // 0x800414BC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800414C0: nop

    // 0x800414C4: bc1f        L_80041520
    if (!c1cs) {
        // 0x800414C8: nop
    
            goto L_80041520;
    }
    // 0x800414C8: nop

    // 0x800414CC: b           L_80041520
    // 0x800414D0: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
        goto L_80041520;
    // 0x800414D0: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
L_800414D4:
    // 0x800414D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800414D8: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x800414DC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800414E0: nop

    // 0x800414E4: bc1f        L_80041520
    if (!c1cs) {
        // 0x800414E8: nop
    
            goto L_80041520;
    }
    // 0x800414E8: nop

    // 0x800414EC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800414F0: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800414F4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800414F8: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800414FC: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80041500: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x80041504: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80041508: nop

    // 0x8004150C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80041510: nop

    // 0x80041514: bc1f        L_80041520
    if (!c1cs) {
        // 0x80041518: nop
    
            goto L_80041520;
    }
    // 0x80041518: nop

    // 0x8004151C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
L_80041520:
    // 0x80041520: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80041524: lwc1        $f2, 0x8C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80041528: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8004152C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80041530: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80041534: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80041538: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8004153C: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80041540: nop

    // 0x80041544: bc1f        L_80041558
    if (!c1cs) {
        // 0x80041548: nop
    
            goto L_80041558;
    }
    // 0x80041548: nop

    // 0x8004154C: b           L_80041558
    // 0x80041550: sb          $t5, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r13;
        goto L_80041558;
    // 0x80041550: sb          $t5, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r13;
L_80041554:
    // 0x80041554: sb          $t6, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r14;
L_80041558:
    // 0x80041558: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x8004155C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80041560: nop

    // 0x80041564: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80041568: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x8004156C: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
    // 0x80041570: lbu         $v0, 0xFD($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XFD);
    // 0x80041574: b           L_80041878
    // 0x80041578: nop

        goto L_80041878;
    // 0x80041578: nop

L_8004157C:
    // 0x8004157C: slti        $at, $v1, 0x181
    ctx->r1 = SIGNED(ctx->r3) < 0X181 ? 1 : 0;
    // 0x80041580: bne         $at, $zero, L_800415B4
    if (ctx->r1 != 0) {
        // 0x80041584: nop
    
            goto L_800415B4;
    }
    // 0x80041584: nop

    // 0x80041588: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x8004158C: addiu       $t8, $zero, 0x180
    ctx->r24 = ADD32(0, 0X180);
    // 0x80041590: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80041594: subu        $t6, $v1, $t5
    ctx->r14 = SUB32(ctx->r3, ctx->r13);
    // 0x80041598: sh          $t6, 0x106($t0)
    MEM_H(0X106, ctx->r8) = ctx->r14;
    // 0x8004159C: lh          $t7, 0x106($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X106);
    // 0x800415A0: nop

    // 0x800415A4: slti        $at, $t7, 0x180
    ctx->r1 = SIGNED(ctx->r15) < 0X180 ? 1 : 0;
    // 0x800415A8: beq         $at, $zero, L_800415B4
    if (ctx->r1 == 0) {
        // 0x800415AC: nop
    
            goto L_800415B4;
    }
    // 0x800415AC: nop

    // 0x800415B0: sh          $t8, 0x106($t0)
    MEM_H(0X106, ctx->r8) = ctx->r24;
L_800415B4:
    // 0x800415B4: lh          $t9, 0x2($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X2);
    // 0x800415B8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800415BC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800415C0: lhu         $t4, 0x8($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X8);
    // 0x800415C4: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800415C8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800415CC: lh          $t3, 0x6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X6);
    // 0x800415D0: sub.s       $f2, $f4, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800415D4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800415D8: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800415DC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800415E0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800415E4: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x800415E8: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800415EC: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x800415F0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800415F4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800415F8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800415FC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80041600: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80041604: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80041608: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8004160C: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80041610: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80041614: nop

    // 0x80041618: bc1f        L_80041628
    if (!c1cs) {
        // 0x8004161C: nop
    
            goto L_80041628;
    }
    // 0x8004161C: nop

    // 0x80041620: b           L_80041858
    // 0x80041624: sb          $t8, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r24;
        goto L_80041858;
    // 0x80041624: sb          $t8, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r24;
L_80041628:
    // 0x80041628: lhu         $v0, 0x104($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X104);
    // 0x8004162C: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    // 0x80041630: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80041634: beq         $at, $zero, L_80041648
    if (ctx->r1 == 0) {
        // 0x80041638: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80041648;
    }
    // 0x80041638: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004163C: subu        $t3, $v0, $t9
    ctx->r11 = SUB32(ctx->r2, ctx->r25);
    // 0x80041640: b           L_800416F4
    // 0x80041644: sh          $t3, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r11;
        goto L_800416F4;
    // 0x80041644: sh          $t3, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r11;
L_80041648:
    // 0x80041648: sh          $zero, 0x104($t0)
    MEM_H(0X104, ctx->r8) = 0;
    // 0x8004164C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80041650: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80041654: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80041658: addiu       $t5, $sp, 0x44
    ctx->r13 = ADD32(ctx->r29, 0X44);
    // 0x8004165C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80041660: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x80041664: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80041668: jal         0x80016E1C
    // 0x8004166C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    obj_dist_racer(rdram, ctx);
        goto after_11;
    // 0x8004166C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_11:
    // 0x80041670: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80041674: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80041678: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004167C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80041680: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80041684: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80041688: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8004168C: bne         $t7, $zero, L_800416A4
    if (ctx->r15 != 0) {
        // 0x80041690: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_800416A4;
    }
    // 0x80041690: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80041694: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80041698: sw          $zero, 0x100($t0)
    MEM_W(0X100, ctx->r8) = 0;
    // 0x8004169C: b           L_800416F4
    // 0x800416A0: sb          $t8, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r24;
        goto L_800416F4;
    // 0x800416A0: sb          $t8, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r24;
L_800416A4:
    // 0x800416A4: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800416A8: bne         $at, $zero, L_800416D0
    if (ctx->r1 != 0) {
        // 0x800416AC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800416D0;
    }
    // 0x800416AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800416B0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x800416B4: jal         0x8006FB8C
    // 0x800416B8: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    rand_range(rdram, ctx);
        goto after_12;
    // 0x800416B8: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    after_12:
    // 0x800416BC: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x800416C0: sra         $t3, $v1, 16
    ctx->r11 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800416C4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800416C8: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800416CC: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
L_800416D0:
    // 0x800416D0: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x800416D4: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x800416D8: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800416DC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800416E0: addu        $t7, $sp, $t6
    ctx->r15 = ADD32(ctx->r29, ctx->r14);
    // 0x800416E4: lw          $t7, 0x44($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X44);
    // 0x800416E8: addiu       $t8, $zero, 0xF0
    ctx->r24 = ADD32(0, 0XF0);
    // 0x800416EC: sh          $t8, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r24;
    // 0x800416F0: sw          $t7, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r15;
L_800416F4:
    // 0x800416F4: lbu         $t9, 0xFD($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0XFD);
    // 0x800416F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800416FC: bne         $t9, $at, L_80041858
    if (ctx->r25 != ctx->r1) {
        // 0x80041700: nop
    
            goto L_80041858;
    }
    // 0x80041700: nop

    // 0x80041704: lw          $v0, 0x100($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X100);
    // 0x80041708: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004170C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80041710: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80041714: sub.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80041718: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8004171C: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80041720: sub.s       $f2, $f18, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80041724: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80041728: lwc1        $f6, 0x67CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X67CC);
    // 0x8004172C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80041730: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80041734: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80041738: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x8004173C: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80041740: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x80041744: nop

    // 0x80041748: bc1f        L_80041758
    if (!c1cs) {
        // 0x8004174C: nop
    
            goto L_80041758;
    }
    // 0x8004174C: nop

    // 0x80041750: b           L_80041858
    // 0x80041754: sb          $t3, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r11;
        goto L_80041858;
    // 0x80041754: sb          $t3, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r11;
L_80041758:
    // 0x80041758: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x8004175C: jal         0x8006FB8C
    // 0x80041760: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    rand_range(rdram, ctx);
        goto after_13;
    // 0x80041760: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    after_13:
    // 0x80041764: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80041768: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8004176C: slti        $at, $v0, 0x63
    ctx->r1 = SIGNED(ctx->r2) < 0X63 ? 1 : 0;
    // 0x80041770: bne         $at, $zero, L_8004178C
    if (ctx->r1 != 0) {
        // 0x80041774: lw          $v0, 0x9C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X9C);
            goto L_8004178C;
    }
    // 0x80041774: lw          $v0, 0x9C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X9C);
    // 0x80041778: lh          $t4, 0x106($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X106);
    // 0x8004177C: nop

    // 0x80041780: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x80041784: sh          $t5, 0x106($t0)
    MEM_H(0X106, ctx->r8) = ctx->r13;
    // 0x80041788: lw          $v0, 0x9C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X9C);
L_8004178C:
    // 0x8004178C: lh          $t7, 0x106($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X106);
    // 0x80041790: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80041794: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80041798: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8004179C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800417A0: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800417A4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800417A8: mflo        $t8
    ctx->r24 = lo;
    // 0x800417AC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800417B0: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800417B4: lw          $t3, 0x100($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X100);
    // 0x800417B8: nop

    // 0x800417BC: lwc1        $f2, 0x10($t3)
    ctx->f2.u32l = MEM_W(ctx->r11, 0X10);
    // 0x800417C0: nop

    // 0x800417C4: add.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x800417C8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800417CC: nop

    // 0x800417D0: bc1f        L_800417E0
    if (!c1cs) {
        // 0x800417D4: nop
    
            goto L_800417E0;
    }
    // 0x800417D4: nop

    // 0x800417D8: b           L_80041800
    // 0x800417DC: sb          $zero, 0xFE($t0)
    MEM_B(0XFE, ctx->r8) = 0;
        goto L_80041800;
    // 0x800417DC: sb          $zero, 0xFE($t0)
    MEM_B(0XFE, ctx->r8) = 0;
L_800417E0:
    // 0x800417E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800417E4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800417E8: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800417EC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800417F0: nop

    // 0x800417F4: bc1f        L_80041800
    if (!c1cs) {
        // 0x800417F8: nop
    
            goto L_80041800;
    }
    // 0x800417F8: nop

    // 0x800417FC: sb          $t4, 0xFE($t0)
    MEM_B(0XFE, ctx->r8) = ctx->r12;
L_80041800:
    // 0x80041800: lbu         $t5, 0xFE($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0XFE);
    // 0x80041804: nop

    // 0x80041808: beq         $t5, $zero, L_8004182C
    if (ctx->r13 == 0) {
        // 0x8004180C: nop
    
            goto L_8004182C;
    }
    // 0x8004180C: nop

    // 0x80041810: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80041814: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80041818: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004181C: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80041820: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80041824: b           L_80041844
    // 0x80041828: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
        goto L_80041844;
    // 0x80041828: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
L_8004182C:
    // 0x8004182C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80041830: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80041834: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80041838: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8004183C: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80041840: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
L_80041844:
    // 0x80041844: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80041848: lh          $t6, 0x106($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X106);
    // 0x8004184C: nop

    // 0x80041850: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80041854: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_80041858:
    // 0x80041858: lh          $t9, 0x18($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X18);
    // 0x8004185C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80041860: nop

    // 0x80041864: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80041868: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8004186C: sh          $t5, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r13;
    // 0x80041870: lbu         $v0, 0xFD($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XFD);
    // 0x80041874: nop

L_80041878:
    // 0x80041878: beq         $v0, $zero, L_800418DC
    if (ctx->r2 == 0) {
        // 0x8004187C: nop
    
            goto L_800418DC;
    }
    // 0x8004187C: nop

    // 0x80041880: lwc1        $f0, 0x108($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X108);
    // 0x80041884: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80041888: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8004188C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80041890: nop

    // 0x80041894: bc1f        L_800418DC
    if (!c1cs) {
        // 0x80041898: nop
    
            goto L_800418DC;
    }
    // 0x80041898: nop

    // 0x8004189C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800418A0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x800418A4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800418A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800418AC: nop

    // 0x800418B0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800418B4: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800418B8: swc1        $f8, 0x108($t0)
    MEM_W(0X108, ctx->r8) = ctx->f8.u32l;
    // 0x800418BC: lwc1        $f18, 0x108($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X108);
    // 0x800418C0: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800418C4: nop

    // 0x800418C8: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x800418CC: nop

    // 0x800418D0: bc1f        L_800418DC
    if (!c1cs) {
        // 0x800418D4: nop
    
            goto L_800418DC;
    }
    // 0x800418D4: nop

    // 0x800418D8: swc1        $f10, 0x108($t0)
    MEM_W(0X108, ctx->r8) = ctx->f10.u32l;
L_800418DC:
    // 0x800418DC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800418E0: lwc1        $f4, 0x108($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X108);
    // 0x800418E4: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x800418E8: c.eq.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl == ctx->f4.fl;
    // 0x800418EC: nop

    // 0x800418F0: bc1t        L_800419E8
    if (c1cs) {
        // 0x800418F4: nop
    
            goto L_800419E8;
    }
    // 0x800418F4: nop

    // 0x800418F8: lbu         $t6, 0xFD($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0XFD);
    // 0x800418FC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80041900: beq         $t6, $at, L_80041914
    if (ctx->r14 == ctx->r1) {
        // 0x80041904: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80041914;
    }
    // 0x80041904: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80041908: lwc1        $f0, 0x67D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X67D0);
    // 0x8004190C: b           L_80041920
    // 0x80041910: nop

        goto L_80041920;
    // 0x80041910: nop

L_80041914:
    // 0x80041914: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80041918: lwc1        $f0, 0x67D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X67D4);
    // 0x8004191C: nop

L_80041920:
    // 0x80041920: beq         $t8, $zero, L_80041938
    if (ctx->r24 == 0) {
        // 0x80041924: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80041938;
    }
    // 0x80041924: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80041928: lwc1        $f6, 0x67D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X67D8);
    // 0x8004192C: nop

    // 0x80041930: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80041934: nop

L_80041938:
    // 0x80041938: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8004193C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x80041940: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80041944: nop

    // 0x80041948: bc1f        L_8004195C
    if (!c1cs) {
        // 0x8004194C: nop
    
            goto L_8004195C;
    }
    // 0x8004194C: nop

    // 0x80041950: swc1        $f12, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f12.u32l;
    // 0x80041954: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80041958: nop

L_8004195C:
    // 0x8004195C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80041960: nop

    // 0x80041964: bc1f        L_80041970
    if (!c1cs) {
        // 0x80041968: nop
    
            goto L_80041970;
    }
    // 0x80041968: nop

    // 0x8004196C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
L_80041970:
    // 0x80041970: lwc1        $f8, 0x108($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X108);
    // 0x80041974: nop

    // 0x80041978: c.eq.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl == ctx->f8.fl;
    // 0x8004197C: nop

    // 0x80041980: bc1t        L_800419E8
    if (c1cs) {
        // 0x80041984: nop
    
            goto L_800419E8;
    }
    // 0x80041984: nop

    // 0x80041988: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8004198C: jal         0x80070A04
    // 0x80041990: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    sins_f(rdram, ctx);
        goto after_14;
    // 0x80041990: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_14:
    // 0x80041994: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80041998: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8004199C: lwc1        $f18, 0x108($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X108);
    // 0x800419A0: nop

    // 0x800419A4: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x800419A8: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800419AC: jal         0x80070A38
    // 0x800419B0: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    coss_f(rdram, ctx);
        goto after_15;
    // 0x800419B0: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    after_15:
    // 0x800419B4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800419B8: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x800419BC: lwc1        $f6, 0x108($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X108);
    // 0x800419C0: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x800419C4: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800419C8: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800419CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800419D0: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x800419D4: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x800419D8: jal         0x80011570
    // 0x800419DC: nop

    move_object(rdram, ctx);
        goto after_16;
    // 0x800419DC: nop

    after_16:
    // 0x800419E0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800419E4: nop

L_800419E8:
    // 0x800419E8: lbu         $t9, 0xFC($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0XFC);
    // 0x800419EC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800419F0: subu        $t4, $t3, $t9
    ctx->r12 = SUB32(ctx->r11, ctx->r25);
    // 0x800419F4: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800419F8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800419FC: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x80041A00: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80041A04: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80041A08: sb          $t4, 0xFC($t0)
    MEM_B(0XFC, ctx->r8) = ctx->r12;
    // 0x80041A0C: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x80041A10: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80041A14: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80041A18: addu        $a2, $t0, $t6
    ctx->r6 = ADD32(ctx->r8, ctx->r14);
    // 0x80041A1C: bne         $t8, $zero, L_80041A2C
    if (ctx->r24 != 0) {
        // 0x80041A20: addiu       $a2, $a2, 0x80
        ctx->r6 = ADD32(ctx->r6, 0X80);
            goto L_80041A2C;
    }
    // 0x80041A20: addiu       $a2, $a2, 0x80
    ctx->r6 = ADD32(ctx->r6, 0X80);
    // 0x80041A24: b           L_80041A30
    // 0x80041A28: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
        goto L_80041A30;
    // 0x80041A28: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
L_80041A2C:
    // 0x80041A2C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_80041A30:
    // 0x80041A30: lh          $t3, 0x18($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X18);
    // 0x80041A34: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80041A38: sllv        $a0, $t3, $a1
    ctx->r4 = S32(ctx->r11 << (ctx->r5 & 31));
    // 0x80041A3C: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80041A40: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80041A44: jal         0x80070A70
    // 0x80041A48: sh          $a1, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r5;
    static_3_80070A70(rdram, ctx);
        goto after_17;
    // 0x80041A48: sh          $a1, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r5;
    after_17:
    // 0x80041A4C: lh          $a1, 0x76($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X76);
    // 0x80041A50: lh          $t5, 0x18($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X18);
    // 0x80041A54: sra         $v1, $v0, 10
    ctx->r3 = S32(SIGNED(ctx->r2) >> 10);
    // 0x80041A58: sllv        $a0, $t5, $a1
    ctx->r4 = S32(ctx->r13 << (ctx->r5 & 31));
    // 0x80041A5C: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80041A60: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80041A64: jal         0x80070A6C
    // 0x80041A68: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    coss_s16(rdram, ctx);
        goto after_18;
    // 0x80041A68: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    after_18:
    // 0x80041A6C: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80041A70: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80041A74: sra         $a0, $v0, 10
    ctx->r4 = S32(SIGNED(ctx->r2) >> 10);
    // 0x80041A78: bgez        $v1, L_80041A84
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80041A7C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80041A84;
    }
    // 0x80041A7C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80041A80: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_80041A84:
    // 0x80041A84: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80041A88: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x80041A8C: bne         $t8, $zero, L_80041AA0
    if (ctx->r24 != 0) {
        // 0x80041A90: nop
    
            goto L_80041AA0;
    }
    // 0x80041A90: nop

    // 0x80041A94: bgez        $a0, L_80041AA0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80041A98: nop
    
            goto L_80041AA0;
    }
    // 0x80041A98: nop

    // 0x80041A9C: negu        $a1, $a0
    ctx->r5 = SUB32(0, ctx->r4);
L_80041AA0:
    // 0x80041AA0: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x80041AA4: sh          $a1, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r5;
    // 0x80041AA8: sh          $v0, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r2;
    // 0x80041AAC: sh          $a1, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r5;
    // 0x80041AB0: sh          $v1, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r3;
    // 0x80041AB4: sh          $a1, 0x2A($a2)
    MEM_H(0X2A, ctx->r6) = ctx->r5;
    // 0x80041AB8: sh          $v1, 0x32($a2)
    MEM_H(0X32, ctx->r6) = ctx->r3;
    // 0x80041ABC: sh          $a1, 0x34($a2)
    MEM_H(0X34, ctx->r6) = ctx->r5;
    // 0x80041AC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80041AC4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80041AC8: jr          $ra
    // 0x80041ACC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80041ACC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
