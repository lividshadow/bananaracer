#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void fix32_sqrt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800709C0: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x800709C4: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800709C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800709CC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800709D0: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800709D4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x800709D8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800709DC: cvt.w.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800709E0: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x800709E4: jr          $ra
    // 0x800709E8: nop

    return;
    // 0x800709E8: nop

;}
RECOMP_FUNC void update_camera_finish_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058D9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80058DA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80058DA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80058DA8: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x80058DAC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80058DB0: lb          $t7, 0x1D0($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X1D0);
    // 0x80058DB4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80058DB8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80058DBC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80058DC0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80058DC4: jal         0x8001BE08
    // 0x80058DC8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    spectate_nearest(rdram, ctx);
        goto after_0;
    // 0x80058DC8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    after_0:
    // 0x80058DCC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80058DD0: bne         $v0, $zero, L_80058DF0
    if (ctx->r2 != 0) {
        // 0x80058DD4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80058DF0;
    }
    // 0x80058DD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80058DD8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80058DDC: addiu       $s0, $s0, -0x2578
    ctx->r16 = ADD32(ctx->r16, -0X2578);
    // 0x80058DE0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80058DE4: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80058DE8: b           L_80058F74
    // 0x80058DEC: sh          $t8, 0x36($t9)
    MEM_H(0X36, ctx->r25) = ctx->r24;
        goto L_80058F74;
    // 0x80058DEC: sh          $t8, 0x36($t9)
    MEM_H(0X36, ctx->r25) = ctx->r24;
L_80058DF0:
    // 0x80058DF0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80058DF4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80058DF8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80058DFC: sb          $t0, 0x1D0($t1)
    MEM_B(0X1D0, ctx->r9) = ctx->r8;
    // 0x80058E00: addiu       $s0, $s0, -0x2578
    ctx->r16 = ADD32(ctx->r16, -0X2578);
    // 0x80058E04: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80058E08: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80058E0C: nop

    // 0x80058E10: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    // 0x80058E14: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80058E18: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80058E1C: nop

    // 0x80058E20: swc1        $f6, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f6.u32l;
    // 0x80058E24: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80058E28: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80058E2C: nop

    // 0x80058E30: swc1        $f8, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f8.u32l;
    // 0x80058E34: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80058E38: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80058E3C: lwc1        $f18, 0x10($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80058E40: lwc1        $f16, 0xC($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80058E44: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80058E48: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80058E4C: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80058E50: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80058E54: lwc1        $f10, 0x14($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80058E58: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80058E5C: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80058E60: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80058E64: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80058E68: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80058E6C: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80058E70: jal         0x800CA030
    // 0x80058E74: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80058E74: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_1:
    // 0x80058E78: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80058E7C: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80058E80: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80058E84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80058E88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80058E8C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80058E90: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80058E94: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80058E98: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80058E9C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80058EA0: nop

    // 0x80058EA4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80058EA8: nop

    // 0x80058EAC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80058EB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80058EB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80058EB8: nop

    // 0x80058EBC: cvt.w.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = CVT_W_S(ctx->f14.fl);
    // 0x80058EC0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80058EC4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80058EC8: jal         0x800708AC
    // 0x80058ECC: nop

    atan2s(rdram, ctx);
        goto after_2;
    // 0x80058ECC: nop

    after_2:
    // 0x80058ED0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80058ED4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80058ED8: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80058EDC: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x80058EE0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80058EE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80058EE8: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x80058EEC: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80058EF0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80058EF4: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80058EF8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80058EFC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80058F00: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80058F04: nop

    // 0x80058F08: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80058F0C: nop

    // 0x80058F10: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80058F14: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80058F18: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80058F1C: nop

    // 0x80058F20: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80058F24: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80058F28: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80058F2C: jal         0x800708AC
    // 0x80058F30: nop

    atan2s(rdram, ctx);
        goto after_3;
    // 0x80058F30: nop

    after_3:
    // 0x80058F34: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80058F38: nop

    // 0x80058F3C: sh          $v0, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r2;
    // 0x80058F40: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80058F44: nop

    // 0x80058F48: sh          $zero, 0x4($t3)
    MEM_H(0X4, ctx->r11) = 0;
    // 0x80058F4C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80058F50: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80058F54: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80058F58: lw          $a2, 0x14($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X14);
    // 0x80058F5C: lwc1        $f14, 0x3C($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X3C);
    // 0x80058F60: jal         0x80029F58
    // 0x80058F64: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_4;
    // 0x80058F64: nop

    after_4:
    // 0x80058F68: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80058F6C: nop

    // 0x80058F70: sh          $v0, 0x34($t5)
    MEM_H(0X34, ctx->r13) = ctx->r2;
L_80058F74:
    // 0x80058F74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80058F78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80058F7C: jr          $ra
    // 0x80058F80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80058F80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void rsp_segment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void guMtxL2F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4F58: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800D4F5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D4F60: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800D4F64: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800D4F68: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x800D4F6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D4F70: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800D4F74: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800D4F78: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800D4F7C: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_800D4F80:
    // 0x800D4F80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D4F84: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_800D4F88:
    // 0x800D4F88: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800D4F8C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800D4F90: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D4F94: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x800D4F98: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800D4F9C: and         $t5, $t9, $t2
    ctx->r13 = ctx->r25 & ctx->r10;
    // 0x800D4FA0: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800D4FA4: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800D4FA8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800D4FAC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800D4FB0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x800D4FB4: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800D4FB8: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x800D4FBC: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x800D4FC0: and         $t6, $t5, $t2
    ctx->r14 = ctx->r13 & ctx->r10;
    // 0x800D4FC4: or          $a3, $t9, $t6
    ctx->r7 = ctx->r25 | ctx->r14;
    // 0x800D4FC8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D4FCC: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800D4FD0: sw          $a3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r7;
    // 0x800D4FD4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D4FD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D4FDC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800D4FE0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4FE4: div.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800D4FE8: div.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800D4FEC: swc1        $f18, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f18.u32l;
    // 0x800D4FF0: bne         $a0, $t3, L_800D4F88
    if (ctx->r4 != ctx->r11) {
        // 0x800D4FF4: swc1        $f16, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
            goto L_800D4F88;
    }
    // 0x800D4FF4: swc1        $f16, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
    // 0x800D4FF8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800D4FFC: bne         $a2, $t4, L_800D4F80
    if (ctx->r6 != ctx->r12) {
        // 0x800D5000: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_800D4F80;
    }
    // 0x800D5000: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x800D5004: jr          $ra
    // 0x800D5008: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800D5008: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void rsp_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void emitter_cleanup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B27C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B27C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B27C8: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x800B27CC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B27D0: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x800B27D4: beq         $t7, $zero, L_800B2850
    if (ctx->r15 == 0) {
        // 0x800B27D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B2850;
    }
    // 0x800B27D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B27DC: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    // 0x800B27E0: nop

    // 0x800B27E4: beq         $a0, $zero, L_800B2850
    if (ctx->r4 == 0) {
        // 0x800B27E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B2850;
    }
    // 0x800B27E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B27EC: lbu         $t8, 0x6($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X6);
    // 0x800B27F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B27F4: blez        $t8, L_800B2838
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B27F8: nop
    
            goto L_800B2838;
    }
    // 0x800B27F8: nop

    // 0x800B27FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800B2800:
    // 0x800B2800: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x800B2804: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B2808: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x800B280C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800B2810: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800B2814: sh          $zero, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = 0;
    // 0x800B2818: sw          $zero, 0x70($v0)
    MEM_W(0X70, ctx->r2) = 0;
    // 0x800B281C: lbu         $t1, 0x6($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X6);
    // 0x800B2820: nop

    // 0x800B2824: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800B2828: bne         $at, $zero, L_800B2800
    if (ctx->r1 != 0) {
        // 0x800B282C: nop
    
            goto L_800B2800;
    }
    // 0x800B282C: nop

    // 0x800B2830: lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XC);
    // 0x800B2834: nop

L_800B2838:
    // 0x800B2838: jal         0x80071380
    // 0x800B283C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800B283C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800B2840: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2844: nop

    // 0x800B2848: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800B284C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B2850:
    // 0x800B2850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B2854: jr          $ra
    // 0x800B2858: nop

    return;
    // 0x800B2858: nop

;}
RECOMP_FUNC void set_triangle_texture_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF604: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x800AF608: nop

    // 0x800AF60C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800AF610: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800AF614: lbu         $a1, 0x0($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X0);
    // 0x800AF618: lbu         $a3, 0x1($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0X1);
    // 0x800AF61C: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x800AF620: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x800AF624: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800AF628: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800AF62C: sll         $t1, $a3, 5
    ctx->r9 = S32(ctx->r7 << 5);
    // 0x800AF630: sra         $t2, $t8, 1
    ctx->r10 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AF634: sh          $t2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r10;
    // 0x800AF638: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x800AF63C: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x800AF640: sh          $t1, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r9;
    // 0x800AF644: sh          $t8, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r24;
    // 0x800AF648: jr          $ra
    // 0x800AF64C: sh          $t1, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r9;
    return;
    // 0x800AF64C: sh          $t1, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r9;
;}
RECOMP_FUNC void sound_play_spatial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001EA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001EAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001EB0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80001EB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001EB8: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001EBC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80001EC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001EC4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80001EC8: bne         $a1, $zero, L_80001ED8
    if (ctx->r5 != 0) {
        // 0x80001ECC: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_80001ED8;
    }
    // 0x80001ECC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80001ED0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80001ED4: addiu       $a1, $a1, 0x6504
    ctx->r5 = ADD32(ctx->r5, 0X6504);
L_80001ED8:
    // 0x80001ED8: jal         0x80001D04
    // 0x80001EDC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80001EDC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x80001EE0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80001EE4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80001EE8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80001EEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80001EF0: beq         $a0, $zero, L_80001F08
    if (ctx->r4 == 0) {
        // 0x80001EF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001F08;
    }
    // 0x80001EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001EF8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80001EFC: jal         0x80009B7C
    // 0x80001F00: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_1;
    // 0x80001F00: nop

    after_1:
    // 0x80001F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001F08:
    // 0x80001F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001F0C: jr          $ra
    // 0x80001F10: nop

    return;
    // 0x80001F10: nop

;}
RECOMP_FUNC void cam_move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069D0C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069D10: lw          $t6, 0x1264($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1264);
    // 0x80069D14: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069D18: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80069D1C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80069D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069D24: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069D28: addiu       $t8, $t8, 0x1040
    ctx->r24 = ADD32(ctx->r24, 0X1040);
    // 0x80069D2C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x80069D30: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80069D34: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80069D38: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80069D3C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80069D40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80069D44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80069D48: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80069D4C: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80069D50: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80069D54: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80069D58: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80069D5C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80069D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069D64: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80069D68: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
    // 0x80069D6C: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x80069D70: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x80069D74: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80069D78: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80069D7C: jal         0x80029F58
    // 0x80069D80: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_0;
    // 0x80069D80: nop

    after_0:
    // 0x80069D84: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80069D88: lw          $t9, 0x1264($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1264);
    // 0x80069D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069D90: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80069D94: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80069D98: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80069D9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069DA0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80069DA4: sh          $v0, 0x1074($at)
    MEM_H(0X1074, ctx->r1) = ctx->r2;
    // 0x80069DA8: jr          $ra
    // 0x80069DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80069DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void check_fadeout_transition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C06AC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C06B0: lhu         $v0, 0x3740($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3740);
    // 0x800C06B4: nop

    // 0x800C06B8: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C06BC: bne         $t6, $zero, L_800C06F0
    if (ctx->r14 != 0) {
        // 0x800C06C0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800C06F0;
    }
    // 0x800C06C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800C06C4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C06C8: lhu         $v0, 0x3744($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3744);
    // 0x800C06CC: nop

    // 0x800C06D0: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C06D4: beq         $t7, $zero, L_800C06F0
    if (ctx->r15 == 0) {
        // 0x800C06D8: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800C06F0;
    }
    // 0x800C06D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800C06DC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C06E0: lb          $v0, 0x374C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X374C);
    // 0x800C06E4: nop

    // 0x800C06E8: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C06EC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800C06F0:
    // 0x800C06F0: jr          $ra
    // 0x800C06F4: nop

    return;
    // 0x800C06F4: nop

;}
RECOMP_FUNC void music_dynamic_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001074: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001078: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8000107C: lbu         $t7, -0x3434($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3434);
    // 0x80001080: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80001084: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001088: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8000108C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80001090: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80001094: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80001098: beq         $t7, $zero, L_800010AC
    if (ctx->r15 == 0) {
        // 0x8000109C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800010AC;
    }
    // 0x8000109C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800010A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800010A4: b           L_800010FC
    // 0x800010A8: sw          $t6, 0x64FC($at)
    MEM_W(0X64FC, ctx->r1) = ctx->r14;
        goto L_800010FC;
    // 0x800010A8: sw          $t6, 0x64FC($at)
    MEM_W(0X64FC, ctx->r1) = ctx->r14;
L_800010AC:
    // 0x800010AC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800010B0: lw          $t8, -0x3460($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3460);
    // 0x800010B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800010B8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800010BC: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x800010C0: sh          $a0, 0x30($t8)
    MEM_H(0X30, ctx->r24) = ctx->r4;
    // 0x800010C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800010C8:
    // 0x800010C8: sllv        $t0, $t9, $s0
    ctx->r8 = S32(ctx->r25 << (ctx->r16 & 31));
    // 0x800010CC: and         $t1, $s1, $t0
    ctx->r9 = ctx->r17 & ctx->r8;
    // 0x800010D0: beq         $t1, $zero, L_800010E8
    if (ctx->r9 == 0) {
        // 0x800010D4: nop
    
            goto L_800010E8;
    }
    // 0x800010D4: nop

    // 0x800010D8: jal         0x80001170
    // 0x800010DC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_0;
    // 0x800010DC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x800010E0: b           L_800010F4
    // 0x800010E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800010F4;
    // 0x800010E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800010E8:
    // 0x800010E8: jal         0x80001114
    // 0x800010EC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_off(rdram, ctx);
        goto after_1;
    // 0x800010EC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_1:
    // 0x800010F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800010F4:
    // 0x800010F4: bne         $s0, $s2, L_800010C8
    if (ctx->r16 != ctx->r18) {
        // 0x800010F8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800010C8;
    }
    // 0x800010F8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800010FC:
    // 0x800010FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80001100: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001104: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80001108: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000110C: jr          $ra
    // 0x80001110: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80001110: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sndp_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000463C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004640: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80004644: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80004648: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8000464C: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80004650: jal         0x80004668
    // 0x80004654: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sndp_play_with_priority(rdram, ctx);
        goto after_0;
    // 0x80004654: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80004658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000465C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004660: jr          $ra
    // 0x80004664: nop

    return;
    // 0x80004664: nop

;}
RECOMP_FUNC void func_80042D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042D60: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80042D64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042D68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80042D6C: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x80042D70: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x80042D74: lb          $t6, 0x1CA($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1CA);
    // 0x80042D78: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80042D7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80042D80: jal         0x8001E2D0
    // 0x80042D84: sh          $t6, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r14;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80042D84: sh          $t6, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r14;
    after_0:
    // 0x80042D88: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80042D8C: jal         0x8001E2D0
    // 0x80042D90: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x80042D90: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80042D94: jal         0x8006BFF0
    // 0x80042D98: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    level_header(rdram, ctx);
        goto after_2;
    // 0x80042D98: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_2:
    // 0x80042D9C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80042DA0: jal         0x8001BAE0
    // 0x80042DA4: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    get_racer_objects_by_position(rdram, ctx);
        goto after_3;
    // 0x80042DA4: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_3:
    // 0x80042DA8: jal         0x8006C3CC
    // 0x80042DAC: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    aitable_get(rdram, ctx);
        goto after_4;
    // 0x80042DAC: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    after_4:
    // 0x80042DB0: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80042DB4: lh          $v1, 0x1C6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1C6);
    // 0x80042DB8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80042DBC: blez        $v1, L_80042DD8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80042DC0: nop
    
            goto L_80042DD8;
    }
    // 0x80042DC0: nop

    // 0x80042DC4: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80042DC8: nop

    // 0x80042DCC: subu        $t8, $v1, $t7
    ctx->r24 = SUB32(ctx->r3, ctx->r15);
    // 0x80042DD0: b           L_80042DDC
    // 0x80042DD4: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
        goto L_80042DDC;
    // 0x80042DD4: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
L_80042DD8:
    // 0x80042DD8: sh          $zero, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = 0;
L_80042DDC:
    // 0x80042DDC: jal         0x8001AE78
    // 0x80042DE0: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    race_finish_timer(rdram, ctx);
        goto after_5;
    // 0x80042DE0: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    after_5:
    // 0x80042DE4: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80042DE8: beq         $v0, $zero, L_80042E08
    if (ctx->r2 == 0) {
        // 0x80042DEC: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80042E08;
    }
    // 0x80042DEC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80042DF0: addiu       $v0, $v0, -0x2558
    ctx->r2 = ADD32(ctx->r2, -0X2558);
    // 0x80042DF4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80042DF8: nop

    // 0x80042DFC: ori         $t6, $t9, 0x8000
    ctx->r14 = ctx->r25 | 0X8000;
    // 0x80042E00: b           L_80043EFC
    // 0x80042E04: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_80043EFC;
    // 0x80042E04: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80042E08:
    // 0x80042E08: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80042E0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80042E10: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80042E14: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80042E18: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80042E1C: blez        $t7, L_80042EB0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80042E20: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80042EB0;
    }
    // 0x80042E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80042E24: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80042E28: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
L_80042E2C:
    // 0x80042E2C: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80042E30: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80042E34: nop

    // 0x80042E38: lw          $t1, 0x64($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X64);
    // 0x80042E3C: nop

    // 0x80042E40: bne         $t1, $s0, L_80042E50
    if (ctx->r9 != ctx->r16) {
        // 0x80042E44: nop
    
            goto L_80042E50;
    }
    // 0x80042E44: nop

    // 0x80042E48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80042E4C: sh          $v1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r3;
L_80042E50:
    // 0x80042E50: lh          $t7, 0x0($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X0);
    // 0x80042E54: nop

    // 0x80042E58: bne         $ra, $t7, L_80042E80
    if (ctx->r31 != ctx->r15) {
        // 0x80042E5C: nop
    
            goto L_80042E80;
    }
    // 0x80042E5C: nop

    // 0x80042E60: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80042E64: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x80042E68: beq         $v0, $zero, L_80042E94
    if (ctx->r2 == 0) {
        // 0x80042E6C: sra         $t0, $t8, 16
        ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
            goto L_80042E94;
    }
    // 0x80042E6C: sra         $t0, $t8, 16
    ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80042E70: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x80042E74: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80042E78: b           L_80042E94
    // 0x80042E7C: sra         $t5, $t6, 16
    ctx->r13 = S32(SIGNED(ctx->r14) >> 16);
        goto L_80042E94;
    // 0x80042E7C: sra         $t5, $t6, 16
    ctx->r13 = S32(SIGNED(ctx->r14) >> 16);
L_80042E80:
    // 0x80042E80: bne         $t4, $ra, L_80042E94
    if (ctx->r12 != ctx->r31) {
        // 0x80042E84: nop
    
            goto L_80042E94;
    }
    // 0x80042E84: nop

    // 0x80042E88: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
    // 0x80042E8C: sra         $t8, $t4, 16
    ctx->r24 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80042E90: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
L_80042E94:
    // 0x80042E94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80042E98: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80042E9C: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x80042EA0: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80042EA4: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80042EA8: bne         $at, $zero, L_80042E2C
    if (ctx->r1 != 0) {
        // 0x80042EAC: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_80042E2C;
    }
    // 0x80042EAC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
L_80042EB0:
    // 0x80042EB0: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80042EB4: bne         $t4, $ra, L_80042EC0
    if (ctx->r12 != ctx->r31) {
        // 0x80042EB8: nop
    
            goto L_80042EC0;
    }
    // 0x80042EB8: nop

    // 0x80042EBC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_80042EC0:
    // 0x80042EC0: beq         $t0, $zero, L_80043F00
    if (ctx->r8 == 0) {
        // 0x80042EC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80043F00;
    }
    // 0x80042EC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80042EC8: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    // 0x80042ECC: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x80042ED0: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80042ED4: jal         0x8002359C
    // 0x80042ED8: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    func_80023568(rdram, ctx);
        goto after_6;
    // 0x80042ED8: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_6:
    // 0x80042EDC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80042EE0: lw          $t8, -0x2540($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2540);
    // 0x80042EE4: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x80042EE8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80042EEC: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80042EF0: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80042EF4: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80042EF8: bne         $t8, $zero, L_8004311C
    if (ctx->r24 != 0) {
        // 0x80042EFC: sh          $v0, 0x70($sp)
        MEM_H(0X70, ctx->r29) = ctx->r2;
            goto L_8004311C;
    }
    // 0x80042EFC: sh          $v0, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r2;
    // 0x80042F00: lb          $t9, 0x1D6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D6);
    // 0x80042F04: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80042F08: beq         $t9, $at, L_80043120
    if (ctx->r25 == ctx->r1) {
        // 0x80042F0C: lh          $a3, 0x72($sp)
        ctx->r7 = MEM_H(ctx->r29, 0X72);
            goto L_80043120;
    }
    // 0x80042F0C: lh          $a3, 0x72($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X72);
    // 0x80042F10: lh          $a3, 0x72($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X72);
    // 0x80042F14: lbu         $a0, 0x20B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20B);
    // 0x80042F18: addiu       $v1, $a3, -0x1
    ctx->r3 = ADD32(ctx->r7, -0X1);
    // 0x80042F1C: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80042F20: beq         $at, $zero, L_80043030
    if (ctx->r1 == 0) {
        // 0x80042F24: sll         $t6, $v1, 16
        ctx->r14 = S32(ctx->r3 << 16);
            goto L_80043030;
    }
    // 0x80042F24: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x80042F28: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80042F2C: bltz        $t7, L_80043034
    if (SIGNED(ctx->r15) < 0) {
        // 0x80042F30: lh          $t6, 0x72($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X72);
            goto L_80043034;
    }
    // 0x80042F30: lh          $t6, 0x72($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X72);
    // 0x80042F34: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80042F38: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80042F3C: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80042F40: beq         $at, $zero, L_80043030
    if (ctx->r1 == 0) {
        // 0x80042F44: addu        $t3, $t2, $t9
        ctx->r11 = ADD32(ctx->r10, ctx->r25);
            goto L_80043030;
    }
    // 0x80042F44: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x80042F48: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x80042F4C: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80042F50: lw          $t1, 0x64($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X64);
    // 0x80042F54: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80042F58: lh          $t7, 0x0($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X0);
    // 0x80042F5C: nop

    // 0x80042F60: beq         $ra, $t7, L_80043034
    if (ctx->r31 == ctx->r15) {
        // 0x80042F64: lh          $t6, 0x72($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X72);
            goto L_80043034;
    }
    // 0x80042F64: lh          $t6, 0x72($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X72);
    // 0x80042F68: bne         $t9, $zero, L_80042FB0
    if (ctx->r25 != 0) {
        // 0x80042F6C: addiu       $a1, $zero, 0x1C2
        ctx->r5 = ADD32(0, 0X1C2);
            goto L_80042FB0;
    }
    // 0x80042F6C: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x80042F70: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x80042F74: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80042F78: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80042F7C: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    // 0x80042F80: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x80042F84: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80042F88: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80042F8C: jal         0x800570F8
    // 0x80042F90: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    play_random_character_voice(rdram, ctx);
        goto after_7;
    // 0x80042F90: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_7:
    // 0x80042F94: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x80042F98: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80042F9C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80042FA0: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80042FA4: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80042FA8: b           L_80042FF8
    // 0x80042FAC: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
        goto L_80042FF8;
    // 0x80042FAC: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
L_80042FB0:
    // 0x80042FB0: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x80042FB4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80042FB8: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80042FBC: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80042FC0: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x80042FC4: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x80042FC8: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80042FCC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80042FD0: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x80042FD4: jal         0x8005CC24
    // 0x80042FD8: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    racer_boss_sound_spatial(rdram, ctx);
        goto after_8;
    // 0x80042FD8: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    after_8:
    // 0x80042FDC: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x80042FE0: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80042FE4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80042FE8: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80042FEC: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80042FF0: nop

    // 0x80042FF4: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
L_80042FF8:
    // 0x80042FF8: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x80042FFC: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043000: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x80043004: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    // 0x80043008: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x8004300C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80043010: jal         0x800570F8
    // 0x80043014: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    play_random_character_voice(rdram, ctx);
        goto after_9;
    // 0x80043014: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_9:
    // 0x80043018: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x8004301C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80043020: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043024: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043028: lbu         $a0, 0x20B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20B);
    // 0x8004302C: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
L_80043030:
    // 0x80043030: lh          $t6, 0x72($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X72);
L_80043034:
    // 0x80043034: nop

    // 0x80043038: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8004303C: beq         $at, $zero, L_8004311C
    if (ctx->r1 == 0) {
        // 0x80043040: addiu       $v0, $t6, 0x1
        ctx->r2 = ADD32(ctx->r14, 0X1);
            goto L_8004311C;
    }
    // 0x80043040: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80043044: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80043048: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004304C: bltz        $t8, L_80043120
    if (SIGNED(ctx->r24) < 0) {
        // 0x80043050: lh          $a3, 0x72($sp)
        ctx->r7 = MEM_H(ctx->r29, 0X72);
            goto L_80043120;
    }
    // 0x80043050: lh          $a3, 0x72($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X72);
    // 0x80043054: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80043058: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8004305C: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80043060: beq         $at, $zero, L_8004311C
    if (ctx->r1 == 0) {
        // 0x80043064: addu        $t8, $t2, $t7
        ctx->r24 = ADD32(ctx->r10, ctx->r15);
            goto L_8004311C;
    }
    // 0x80043064: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x80043068: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8004306C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80043070: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x80043074: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80043078: lh          $t7, 0x0($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X0);
    // 0x8004307C: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x80043080: beq         $ra, $t7, L_8004311C
    if (ctx->r31 == ctx->r15) {
        // 0x80043084: addiu       $a2, $zero, 0x8
        ctx->r6 = ADD32(0, 0X8);
            goto L_8004311C;
    }
    // 0x80043084: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80043088: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x8004308C: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x80043090: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043094: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    // 0x80043098: jal         0x800570F8
    // 0x8004309C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    play_random_character_voice(rdram, ctx);
        goto after_10;
    // 0x8004309C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_10:
    // 0x800430A0: lh          $t7, 0x70($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X70);
    // 0x800430A4: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x800430A8: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x800430AC: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x800430B0: bne         $t7, $zero, L_800430E8
    if (ctx->r15 != 0) {
        // 0x800430B4: addiu       $a1, $zero, 0x162
        ctx->r5 = ADD32(0, 0X162);
            goto L_800430E8;
    }
    // 0x800430B4: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x800430B8: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x800430BC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800430C0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800430C4: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    // 0x800430C8: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x800430CC: jal         0x800570F8
    // 0x800430D0: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    play_random_character_voice(rdram, ctx);
        goto after_11;
    // 0x800430D0: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_11:
    // 0x800430D4: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x800430D8: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x800430DC: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x800430E0: b           L_80043120
    // 0x800430E4: lh          $a3, 0x72($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X72);
        goto L_80043120;
    // 0x800430E4: lh          $a3, 0x72($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X72);
L_800430E8:
    // 0x800430E8: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x800430EC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800430F0: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800430F4: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800430F8: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x800430FC: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x80043100: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043104: jal         0x8005CC24
    // 0x80043108: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    racer_boss_sound_spatial(rdram, ctx);
        goto after_12;
    // 0x80043108: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    after_12:
    // 0x8004310C: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x80043110: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043114: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043118: nop

L_8004311C:
    // 0x8004311C: lh          $a3, 0x72($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X72);
L_80043120:
    // 0x80043120: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80043124: sb          $a3, 0x20B($s0)
    MEM_B(0X20B, ctx->r16) = ctx->r7;
    // 0x80043128: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x8004312C: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043130: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x80043134: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    // 0x80043138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004313C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80043140: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    // 0x80043144: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x80043148: jal         0x8001B7DC
    // 0x8004314C: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    racer_find_nearest_opponent_relative(rdram, ctx);
        goto after_13;
    // 0x8004314C: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x80043150: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x80043154: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043158: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x8004315C: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043160: beq         $v0, $zero, L_80043170
    if (ctx->r2 == 0) {
        // 0x80043164: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_80043170;
    }
    // 0x80043164: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80043168: lw          $t1, 0x64($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X64);
    // 0x8004316C: nop

L_80043170:
    // 0x80043170: or          $a1, $ra, $zero
    ctx->r5 = ctx->r31 | 0;
    // 0x80043174: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x80043178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004317C: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // 0x80043180: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    // 0x80043184: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80043188: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x8004318C: jal         0x8001B7DC
    // 0x80043190: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    racer_find_nearest_opponent_relative(rdram, ctx);
        goto after_14;
    // 0x80043190: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_14:
    // 0x80043194: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x80043198: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8004319C: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x800431A0: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x800431A4: beq         $v0, $zero, L_800431B8
    if (ctx->r2 == 0) {
        // 0x800431A8: slti        $at, $t0, 0x7
        ctx->r1 = SIGNED(ctx->r8) < 0X7 ? 1 : 0;
            goto L_800431B8;
    }
    // 0x800431A8: slti        $at, $t0, 0x7
    ctx->r1 = SIGNED(ctx->r8) < 0X7 ? 1 : 0;
    // 0x800431AC: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x800431B0: nop

    // 0x800431B4: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
L_800431B8:
    // 0x800431B8: lb          $t8, 0x3($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X3);
    // 0x800431BC: beq         $t1, $zero, L_800431D0
    if (ctx->r9 == 0) {
        // 0x800431C0: sb          $t8, 0x3E($sp)
        MEM_B(0X3E, ctx->r29) = ctx->r24;
            goto L_800431D0;
    }
    // 0x800431C0: sb          $t8, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r24;
    // 0x800431C4: lb          $t9, 0x3($t1)
    ctx->r25 = MEM_B(ctx->r9, 0X3);
    // 0x800431C8: nop

    // 0x800431CC: sb          $t9, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r25;
L_800431D0:
    // 0x800431D0: beq         $at, $zero, L_8004327C
    if (ctx->r1 == 0) {
        // 0x800431D4: nop
    
            goto L_8004327C;
    }
    // 0x800431D4: nop

    // 0x800431D8: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800431DC: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x800431E0: jal         0x80099B68
    // 0x800431E4: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    get_trophy_race_world_id(rdram, ctx);
        goto after_15;
    // 0x800431E4: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_15:
    // 0x800431E8: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800431EC: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x800431F0: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x800431F4: bne         $v0, $zero, L_8004327C
    if (ctx->r2 != 0) {
        // 0x800431F8: nop
    
            goto L_8004327C;
    }
    // 0x800431F8: nop

    // 0x800431FC: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80043200: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043204: jal         0x8002359C
    // 0x80043208: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    func_80023568(rdram, ctx);
        goto after_16;
    // 0x80043208: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_16:
    // 0x8004320C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043210: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043214: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043218: bne         $v0, $zero, L_8004327C
    if (ctx->r2 != 0) {
        // 0x8004321C: nop
    
            goto L_8004327C;
    }
    // 0x8004321C: nop

    // 0x80043220: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80043224: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043228: jal         0x80023450
    // 0x8004322C: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    is_taj_challenge(rdram, ctx);
        goto after_17;
    // 0x8004322C: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_17:
    // 0x80043230: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043234: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043238: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x8004323C: bne         $v0, $zero, L_8004327C
    if (ctx->r2 != 0) {
        // 0x80043240: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8004327C;
    }
    // 0x80043240: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80043244: lw          $t7, -0x2540($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2540);
    // 0x80043248: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8004324C: bne         $t7, $at, L_800432D8
    if (ctx->r15 != ctx->r1) {
        // 0x80043250: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800432D8;
    }
    // 0x80043250: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80043254: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80043258: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8004325C: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043260: jal         0x8006FB8C
    // 0x80043264: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    rand_range(rdram, ctx);
        goto after_18;
    // 0x80043264: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_18:
    // 0x80043268: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8004326C: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043270: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043274: b           L_800432D8
    // 0x80043278: sb          $v0, 0x1CC($s0)
    MEM_B(0X1CC, ctx->r16) = ctx->r2;
        goto L_800432D8;
    // 0x80043278: sb          $v0, 0x1CC($s0)
    MEM_B(0X1CC, ctx->r16) = ctx->r2;
L_8004327C:
    // 0x8004327C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80043280: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043284: jal         0x80099B68
    // 0x80043288: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    get_trophy_race_world_id(rdram, ctx);
        goto after_19;
    // 0x80043288: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_19:
    // 0x8004328C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043290: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043294: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043298: beq         $v0, $zero, L_800432C0
    if (ctx->r2 == 0) {
        // 0x8004329C: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_800432C0;
    }
    // 0x8004329C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800432A0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800432A4: lb          $t8, 0x3E($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X3E);
    // 0x800432A8: nop

    // 0x800432AC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800432B0: lbu         $t7, 0x16($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X16);
    // 0x800432B4: b           L_800432D8
    // 0x800432B8: sb          $t7, 0x1CC($s0)
    MEM_B(0X1CC, ctx->r16) = ctx->r15;
        goto L_800432D8;
    // 0x800432B8: sb          $t7, 0x1CC($s0)
    MEM_B(0X1CC, ctx->r16) = ctx->r15;
    // 0x800432BC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_800432C0:
    // 0x800432C0: lb          $t8, 0x3E($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X3E);
    // 0x800432C4: nop

    // 0x800432C8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800432CC: lbu         $t7, 0xC($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0XC);
    // 0x800432D0: nop

    // 0x800432D4: sb          $t7, 0x1CC($s0)
    MEM_B(0X1CC, ctx->r16) = ctx->r15;
L_800432D8:
    // 0x800432D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800432DC: lwc1        $f0, -0x253C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X253C);
    // 0x800432E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800432E4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800432E8: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x800432EC: nop

    // 0x800432F0: bc1t        L_80043318
    if (c1cs) {
        // 0x800432F4: nop
    
            goto L_80043318;
    }
    // 0x800432F4: nop

    // 0x800432F8: lh          $t6, 0x1AE($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1AE);
    // 0x800432FC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80043300: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80043304: lb          $t8, -0x2CF0($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X2CF0);
    // 0x80043308: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004330C: sb          $t8, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r24;
    // 0x80043310: lwc1        $f0, -0x253C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X253C);
    // 0x80043314: nop

L_80043318:
    // 0x80043318: lb          $v1, 0x1CC($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1CC);
    // 0x8004331C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80043320: addiu       $t6, $v1, -0x2
    ctx->r14 = ADD32(ctx->r3, -0X2);
    // 0x80043324: sll         $t8, $t6, 18
    ctx->r24 = S32(ctx->r14 << 18);
    // 0x80043328: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004332C: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x80043330: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80043334: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80043338: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8004333C: c.le.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl <= ctx->f8.fl;
    // 0x80043340: nop

    // 0x80043344: bc1f        L_8004335C
    if (!c1cs) {
        // 0x80043348: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8004335C;
    }
    // 0x80043348: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004334C: lw          $t7, -0x2558($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2558);
    // 0x80043350: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043354: ori         $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 | 0X8000;
    // 0x80043358: sw          $t6, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r14;
L_8004335C:
    // 0x8004335C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80043360: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043364: jal         0x8001E2D0
    // 0x80043368: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    get_misc_asset(rdram, ctx);
        goto after_20;
    // 0x80043368: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_20:
    // 0x8004336C: lb          $t0, 0x174($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X174);
    // 0x80043370: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043374: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043378: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x8004337C: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80043380: beq         $at, $zero, L_800433AC
    if (ctx->r1 == 0) {
        // 0x80043384: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_800433AC;
    }
    // 0x80043384: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80043388: lb          $t8, 0x172($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X172);
    // 0x8004338C: nop

    // 0x80043390: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80043394: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80043398: addu        $t7, $t9, $t0
    ctx->r15 = ADD32(ctx->r25, ctx->r8);
    // 0x8004339C: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x800433A0: lb          $t2, 0x0($t6)
    ctx->r10 = MEM_B(ctx->r14, 0X0);
    // 0x800433A4: b           L_800433B8
    // 0x800433A8: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
        goto L_800433B8;
    // 0x800433A8: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_800433AC:
    // 0x800433AC: lb          $t2, 0x172($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X172);
    // 0x800433B0: nop

    // 0x800433B4: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_800433B8:
    // 0x800433B8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800433BC: lb          $v1, 0xC($t8)
    ctx->r3 = MEM_B(ctx->r24, 0XC);
    // 0x800433C0: lb          $t9, 0xD($t8)
    ctx->r25 = MEM_B(ctx->r24, 0XD);
    // 0x800433C4: subu        $t3, $v0, $t5
    ctx->r11 = SUB32(ctx->r2, ctx->r13);
    // 0x800433C8: subu        $t7, $t9, $v1
    ctx->r15 = SUB32(ctx->r25, ctx->r3);
    // 0x800433CC: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800433D0: mflo        $t6
    ctx->r14 = lo;
    // 0x800433D4: nop

    // 0x800433D8: nop

    // 0x800433DC: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800433E0: bne         $v0, $zero, L_800433EC
    if (ctx->r2 != 0) {
        // 0x800433E4: nop
    
            goto L_800433EC;
    }
    // 0x800433E4: nop

    // 0x800433E8: break       7
    do_break(2147759080);
L_800433EC:
    // 0x800433EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800433F0: bne         $v0, $at, L_80043404
    if (ctx->r2 != ctx->r1) {
        // 0x800433F4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80043404;
    }
    // 0x800433F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800433F8: bne         $t6, $at, L_80043404
    if (ctx->r14 != ctx->r1) {
        // 0x800433FC: nop
    
            goto L_80043404;
    }
    // 0x800433FC: nop

    // 0x80043400: break       6
    do_break(2147759104);
L_80043404:
    // 0x80043404: mflo        $t9
    ctx->r25 = lo;
    // 0x80043408: addu        $t7, $t9, $v1
    ctx->r15 = ADD32(ctx->r25, ctx->r3);
    // 0x8004340C: sh          $t7, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r15;
    // 0x80043410: lb          $t6, 0x11($t8)
    ctx->r14 = MEM_B(ctx->r24, 0X11);
    // 0x80043414: lb          $a0, 0x10($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X10);
    // 0x80043418: nop

    // 0x8004341C: subu        $t9, $t6, $a0
    ctx->r25 = SUB32(ctx->r14, ctx->r4);
    // 0x80043420: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80043424: mflo        $t6
    ctx->r14 = lo;
    // 0x80043428: nop

    // 0x8004342C: nop

    // 0x80043430: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x80043434: bne         $v0, $zero, L_80043440
    if (ctx->r2 != 0) {
        // 0x80043438: nop
    
            goto L_80043440;
    }
    // 0x80043438: nop

    // 0x8004343C: break       7
    do_break(2147759164);
L_80043440:
    // 0x80043440: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80043444: bne         $v0, $at, L_80043458
    if (ctx->r2 != ctx->r1) {
        // 0x80043448: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80043458;
    }
    // 0x80043448: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004344C: bne         $t6, $at, L_80043458
    if (ctx->r14 != ctx->r1) {
        // 0x80043450: nop
    
            goto L_80043458;
    }
    // 0x80043450: nop

    // 0x80043454: break       6
    do_break(2147759188);
L_80043458:
    // 0x80043458: mflo        $t9
    ctx->r25 = lo;
    // 0x8004345C: addu        $t6, $t9, $a0
    ctx->r14 = ADD32(ctx->r25, ctx->r4);
    // 0x80043460: sh          $t6, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r14;
    // 0x80043464: lb          $t9, 0x9($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X9);
    // 0x80043468: lb          $a1, 0x8($t8)
    ctx->r5 = MEM_B(ctx->r24, 0X8);
    // 0x8004346C: nop

    // 0x80043470: subu        $t6, $t9, $a1
    ctx->r14 = SUB32(ctx->r25, ctx->r5);
    // 0x80043474: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80043478: mflo        $t9
    ctx->r25 = lo;
    // 0x8004347C: nop

    // 0x80043480: nop

    // 0x80043484: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x80043488: bne         $v0, $zero, L_80043494
    if (ctx->r2 != 0) {
        // 0x8004348C: nop
    
            goto L_80043494;
    }
    // 0x8004348C: nop

    // 0x80043490: break       7
    do_break(2147759248);
L_80043494:
    // 0x80043494: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80043498: bne         $v0, $at, L_800434AC
    if (ctx->r2 != ctx->r1) {
        // 0x8004349C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800434AC;
    }
    // 0x8004349C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800434A0: bne         $t9, $at, L_800434AC
    if (ctx->r25 != ctx->r1) {
        // 0x800434A4: nop
    
            goto L_800434AC;
    }
    // 0x800434A4: nop

    // 0x800434A8: break       6
    do_break(2147759272);
L_800434AC:
    // 0x800434AC: mflo        $t6
    ctx->r14 = lo;
    // 0x800434B0: addu        $t9, $t6, $a1
    ctx->r25 = ADD32(ctx->r14, ctx->r5);
    // 0x800434B4: sh          $t9, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r25;
    // 0x800434B8: lb          $t6, 0x15($t8)
    ctx->r14 = MEM_B(ctx->r24, 0X15);
    // 0x800434BC: lb          $a2, 0x14($t8)
    ctx->r6 = MEM_B(ctx->r24, 0X14);
    // 0x800434C0: nop

    // 0x800434C4: subu        $t9, $t6, $a2
    ctx->r25 = SUB32(ctx->r14, ctx->r6);
    // 0x800434C8: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800434CC: mflo        $t8
    ctx->r24 = lo;
    // 0x800434D0: nop

    // 0x800434D4: nop

    // 0x800434D8: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x800434DC: bne         $v0, $zero, L_800434E8
    if (ctx->r2 != 0) {
        // 0x800434E0: nop
    
            goto L_800434E8;
    }
    // 0x800434E0: nop

    // 0x800434E4: break       7
    do_break(2147759332);
L_800434E8:
    // 0x800434E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800434EC: bne         $v0, $at, L_80043500
    if (ctx->r2 != ctx->r1) {
        // 0x800434F0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80043500;
    }
    // 0x800434F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800434F4: bne         $t8, $at, L_80043500
    if (ctx->r24 != ctx->r1) {
        // 0x800434F8: nop
    
            goto L_80043500;
    }
    // 0x800434F8: nop

    // 0x800434FC: break       6
    do_break(2147759356);
L_80043500:
    // 0x80043500: mflo        $t6
    ctx->r14 = lo;
    // 0x80043504: addu        $t9, $t6, $a2
    ctx->r25 = ADD32(ctx->r14, ctx->r6);
    // 0x80043508: sh          $t9, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r25;
    // 0x8004350C: lbu         $a3, 0x209($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X209);
    // 0x80043510: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80043514: andi        $t8, $a3, 0x1
    ctx->r24 = ctx->r7 & 0X1;
    // 0x80043518: beq         $t8, $zero, L_800437D8
    if (ctx->r24 == 0) {
        // 0x8004351C: nop
    
            goto L_800437D8;
    }
    // 0x8004351C: nop

    // 0x80043520: lb          $t6, 0x201($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X201);
    // 0x80043524: nop

    // 0x80043528: bne         $t6, $zero, L_800435C0
    if (ctx->r14 != 0) {
        // 0x8004352C: nop
    
            goto L_800435C0;
    }
    // 0x8004352C: nop

    // 0x80043530: bne         $t0, $zero, L_8004357C
    if (ctx->r8 != 0) {
        // 0x80043534: sll         $a0, $t7, 16
        ctx->r4 = S32(ctx->r15 << 16);
            goto L_8004357C;
    }
    // 0x80043534: sll         $a0, $t7, 16
    ctx->r4 = S32(ctx->r15 << 16);
    // 0x80043538: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8004353C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80043540: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80043544: sb          $t2, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r10;
    // 0x80043548: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x8004354C: jal         0x80044490
    // 0x80043550: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    roll_percent_chance(rdram, ctx);
        goto after_21;
    // 0x80043550: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_21:
    // 0x80043554: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043558: lb          $t2, 0x4B($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X4B);
    // 0x8004355C: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043560: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043564: beq         $v0, $zero, L_8004357C
    if (ctx->r2 == 0) {
        // 0x80043568: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_8004357C;
    }
    // 0x80043568: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x8004356C: lb          $t8, 0x174($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X174);
    // 0x80043570: nop

    // 0x80043574: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80043578: sb          $t6, 0x174($s0)
    MEM_B(0X174, ctx->r16) = ctx->r14;
L_8004357C:
    // 0x8004357C: bne         $t4, $zero, L_800435C0
    if (ctx->r12 != 0) {
        // 0x80043580: slti        $at, $t5, 0x3
        ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
            goto L_800435C0;
    }
    // 0x80043580: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x80043584: beq         $at, $zero, L_800435C0
    if (ctx->r1 == 0) {
        // 0x80043588: nop
    
            goto L_800435C0;
    }
    // 0x80043588: nop

    // 0x8004358C: lh          $a0, 0x3C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3C);
    // 0x80043590: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80043594: sb          $t2, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r10;
    // 0x80043598: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x8004359C: jal         0x80044490
    // 0x800435A0: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    roll_percent_chance(rdram, ctx);
        goto after_22;
    // 0x800435A0: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_22:
    // 0x800435A4: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800435A8: lb          $t2, 0x4B($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X4B);
    // 0x800435AC: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x800435B0: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x800435B4: beq         $v0, $zero, L_800435C0
    if (ctx->r2 == 0) {
        // 0x800435B8: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_800435C0;
    }
    // 0x800435B8: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x800435BC: sb          $zero, 0x172($s0)
    MEM_B(0X172, ctx->r16) = 0;
L_800435C0:
    // 0x800435C0: lb          $t7, 0x1D3($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D3);
    // 0x800435C4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800435C8: bne         $t7, $zero, L_80043624
    if (ctx->r15 != 0) {
        // 0x800435CC: addu        $t9, $t9, $t2
        ctx->r25 = ADD32(ctx->r25, ctx->r10);
            goto L_80043624;
    }
    // 0x800435CC: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x800435D0: lb          $t9, -0x2D00($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X2D00);
    // 0x800435D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800435D8: bne         $t9, $at, L_80043624
    if (ctx->r25 != ctx->r1) {
        // 0x800435DC: nop
    
            goto L_80043624;
    }
    // 0x800435DC: nop

    // 0x800435E0: lh          $a0, 0x3C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3C);
    // 0x800435E4: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800435E8: sb          $t2, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r10;
    // 0x800435EC: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x800435F0: jal         0x80044490
    // 0x800435F4: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    roll_percent_chance(rdram, ctx);
        goto after_23;
    // 0x800435F4: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_23:
    // 0x800435F8: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800435FC: lb          $t2, 0x4B($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X4B);
    // 0x80043600: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043604: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043608: beq         $v0, $zero, L_80043624
    if (ctx->r2 == 0) {
        // 0x8004360C: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_80043624;
    }
    // 0x8004360C: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80043610: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80043614: lw          $t8, -0x2550($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2550);
    // 0x80043618: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004361C: ori         $t6, $t8, 0x2000
    ctx->r14 = ctx->r24 | 0X2000;
    // 0x80043620: sw          $t6, -0x2550($at)
    MEM_W(-0X2550, ctx->r1) = ctx->r14;
L_80043624:
    // 0x80043624: lb          $t7, 0x173($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X173);
    // 0x80043628: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8004362C: beq         $t7, $zero, L_800437C4
    if (ctx->r15 == 0) {
        // 0x80043630: addiu       $t9, $t9, -0x2D00
        ctx->r25 = ADD32(ctx->r25, -0X2D00);
            goto L_800437C4;
    }
    // 0x80043630: addiu       $t9, $t9, -0x2D00
    ctx->r25 = ADD32(ctx->r25, -0X2D00);
    // 0x80043634: addu        $v1, $t2, $t9
    ctx->r3 = ADD32(ctx->r10, ctx->r25);
    // 0x80043638: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x8004363C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80043640: bne         $t8, $at, L_80043700
    if (ctx->r24 != ctx->r1) {
        // 0x80043644: nop
    
            goto L_80043700;
    }
    // 0x80043644: nop

    // 0x80043648: beq         $t1, $zero, L_8004369C
    if (ctx->r9 == 0) {
        // 0x8004364C: lh          $a0, 0x36($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X36);
            goto L_8004369C;
    }
    // 0x8004364C: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x80043650: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x80043654: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x80043658: bne         $ra, $t6, L_8004369C
    if (ctx->r31 != ctx->r14) {
        // 0x8004365C: lh          $a0, 0x36($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X36);
            goto L_8004369C;
    }
    // 0x8004365C: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x80043660: beq         $at, $zero, L_80043700
    if (ctx->r1 == 0) {
        // 0x80043664: nop
    
            goto L_80043700;
    }
    // 0x80043664: nop

    // 0x80043668: lb          $t7, 0x3E($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X3E);
    // 0x8004366C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80043670: nop

    // 0x80043674: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80043678: lb          $t6, 0x0($t8)
    ctx->r14 = MEM_B(ctx->r24, 0X0);
    // 0x8004367C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80043680: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80043684: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80043688: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004368C: sh          $t7, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r15;
    // 0x80043690: b           L_80043700
    // 0x80043694: sb          $t9, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r25;
        goto L_80043700;
    // 0x80043694: sb          $t9, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r25;
    // 0x80043698: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
L_8004369C:
    // 0x8004369C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800436A0: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800436A4: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x800436A8: jal         0x80044490
    // 0x800436AC: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    roll_percent_chance(rdram, ctx);
        goto after_24;
    // 0x800436AC: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_24:
    // 0x800436B0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800436B4: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800436B8: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x800436BC: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x800436C0: beq         $v0, $zero, L_80043700
    if (ctx->r2 == 0) {
        // 0x800436C4: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_80043700;
    }
    // 0x800436C4: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x800436C8: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x800436CC: beq         $at, $zero, L_80043700
    if (ctx->r1 == 0) {
        // 0x800436D0: nop
    
            goto L_80043700;
    }
    // 0x800436D0: nop

    // 0x800436D4: lb          $t8, 0x3E($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X3E);
    // 0x800436D8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800436DC: nop

    // 0x800436E0: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800436E4: lb          $t9, 0x0($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X0);
    // 0x800436E8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800436EC: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x800436F0: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x800436F4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800436F8: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
    // 0x800436FC: sb          $t6, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r14;
L_80043700:
    // 0x80043700: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x80043704: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80043708: bne         $t7, $at, L_800437C4
    if (ctx->r15 != ctx->r1) {
        // 0x8004370C: nop
    
            goto L_800437C4;
    }
    // 0x8004370C: nop

    // 0x80043710: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80043714: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x80043718: beq         $v1, $zero, L_80043768
    if (ctx->r3 == 0) {
        // 0x8004371C: nop
    
            goto L_80043768;
    }
    // 0x8004371C: nop

    // 0x80043720: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80043724: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x80043728: bne         $ra, $t9, L_80043768
    if (ctx->r31 != ctx->r25) {
        // 0x8004372C: nop
    
            goto L_80043768;
    }
    // 0x8004372C: nop

    // 0x80043730: beq         $at, $zero, L_800437C4
    if (ctx->r1 == 0) {
        // 0x80043734: nop
    
            goto L_800437C4;
    }
    // 0x80043734: nop

    // 0x80043738: lb          $t8, 0x3E($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X3E);
    // 0x8004373C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80043740: nop

    // 0x80043744: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80043748: lb          $t9, 0x0($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X0);
    // 0x8004374C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80043750: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x80043754: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80043758: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8004375C: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
    // 0x80043760: b           L_800437C4
    // 0x80043764: sb          $t6, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r14;
        goto L_800437C4;
    // 0x80043764: sb          $t6, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r14;
L_80043768:
    // 0x80043768: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8004376C: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043770: jal         0x80044490
    // 0x80043774: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    roll_percent_chance(rdram, ctx);
        goto after_25;
    // 0x80043774: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_25:
    // 0x80043778: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8004377C: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043780: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043784: beq         $v0, $zero, L_800437C4
    if (ctx->r2 == 0) {
        // 0x80043788: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_800437C4;
    }
    // 0x80043788: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x8004378C: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x80043790: beq         $at, $zero, L_800437C4
    if (ctx->r1 == 0) {
        // 0x80043794: nop
    
            goto L_800437C4;
    }
    // 0x80043794: nop

    // 0x80043798: lb          $t7, 0x3E($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X3E);
    // 0x8004379C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800437A0: nop

    // 0x800437A4: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800437A8: lb          $t6, 0x0($t8)
    ctx->r14 = MEM_B(ctx->r24, 0X0);
    // 0x800437AC: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x800437B0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800437B4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800437B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800437BC: sh          $t7, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r15;
    // 0x800437C0: sb          $t9, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r25;
L_800437C4:
    // 0x800437C4: lbu         $t8, 0x209($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X209);
    // 0x800437C8: nop

    // 0x800437CC: andi        $t6, $t8, 0xFFFE
    ctx->r14 = ctx->r24 & 0XFFFE;
    // 0x800437D0: sb          $t6, 0x209($s0)
    MEM_B(0X209, ctx->r16) = ctx->r14;
    // 0x800437D4: andi        $a3, $t6, 0xFF
    ctx->r7 = ctx->r14 & 0XFF;
L_800437D8:
    // 0x800437D8: lb          $t7, 0x1D3($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D3);
    // 0x800437DC: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800437E0: beq         $t7, $zero, L_80043868
    if (ctx->r15 == 0) {
        // 0x800437E4: andi        $t9, $a3, 0x2
        ctx->r25 = ctx->r7 & 0X2;
            goto L_80043868;
    }
    // 0x800437E4: andi        $t9, $a3, 0x2
    ctx->r25 = ctx->r7 & 0X2;
    // 0x800437E8: bne         $t9, $zero, L_80043844
    if (ctx->r25 != 0) {
        // 0x800437EC: andi        $t8, $a3, 0x4
        ctx->r24 = ctx->r7 & 0X4;
            goto L_80043844;
    }
    // 0x800437EC: andi        $t8, $a3, 0x4
    ctx->r24 = ctx->r7 & 0X4;
    // 0x800437F0: lh          $a0, 0x3A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3A);
    // 0x800437F4: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800437F8: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x800437FC: jal         0x80044490
    // 0x80043800: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    roll_percent_chance(rdram, ctx);
        goto after_26;
    // 0x80043800: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_26:
    // 0x80043804: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043808: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x8004380C: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043810: beq         $v0, $zero, L_80043828
    if (ctx->r2 == 0) {
        // 0x80043814: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_80043828;
    }
    // 0x80043814: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80043818: lbu         $t8, 0x209($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X209);
    // 0x8004381C: nop

    // 0x80043820: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x80043824: sb          $t6, 0x209($s0)
    MEM_B(0X209, ctx->r16) = ctx->r14;
L_80043828:
    // 0x80043828: lbu         $t7, 0x209($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X209);
    // 0x8004382C: nop

    // 0x80043830: ori         $t9, $t7, 0x2
    ctx->r25 = ctx->r15 | 0X2;
    // 0x80043834: sb          $t9, 0x209($s0)
    MEM_B(0X209, ctx->r16) = ctx->r25;
    // 0x80043838: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8004383C: andi        $a3, $t9, 0xFF
    ctx->r7 = ctx->r25 & 0XFF;
    // 0x80043840: andi        $t8, $a3, 0x4
    ctx->r24 = ctx->r7 & 0X4;
L_80043844:
    // 0x80043844: beq         $t8, $zero, L_80043898
    if (ctx->r24 == 0) {
        // 0x80043848: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80043898;
    }
    // 0x80043848: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004384C: lw          $t6, -0x2558($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2558);
    // 0x80043850: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80043854: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80043858: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8004385C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043860: b           L_80043898
    // 0x80043864: sw          $t7, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r15;
        goto L_80043898;
    // 0x80043864: sw          $t7, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r15;
L_80043868:
    // 0x80043868: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8004386C: and         $t9, $a3, $at
    ctx->r25 = ctx->r7 & ctx->r1;
    // 0x80043870: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80043874: lui         $at, 0xC028
    ctx->r1 = S32(0XC028 << 16);
    // 0x80043878: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004387C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80043880: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80043884: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80043888: sb          $t9, 0x209($s0)
    MEM_B(0X209, ctx->r16) = ctx->r25;
    // 0x8004388C: bc1f        L_80043898
    if (!c1cs) {
        // 0x80043890: andi        $t6, $t9, 0xFFFB
        ctx->r14 = ctx->r25 & 0XFFFB;
            goto L_80043898;
    }
    // 0x80043890: andi        $t6, $t9, 0xFFFB
    ctx->r14 = ctx->r25 & 0XFFFB;
    // 0x80043894: sb          $t6, 0x209($s0)
    MEM_B(0X209, ctx->r16) = ctx->r14;
L_80043898:
    // 0x80043898: lbu         $t7, 0x209($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X209);
    // 0x8004389C: nop

    // 0x800438A0: andi        $t9, $t7, 0x4
    ctx->r25 = ctx->r15 & 0X4;
    // 0x800438A4: beq         $t9, $zero, L_800438C4
    if (ctx->r25 == 0) {
        // 0x800438A8: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800438C4;
    }
    // 0x800438A8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800438AC: lw          $t8, -0x2558($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2558);
    // 0x800438B0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800438B4: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x800438B8: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800438BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800438C0: sw          $t6, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r14;
L_800438C4:
    // 0x800438C4: lh          $t7, 0x1C6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1C6);
    // 0x800438C8: nop

    // 0x800438CC: bne         $t7, $zero, L_800439DC
    if (ctx->r15 != 0) {
        // 0x800438D0: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_800439DC;
    }
    // 0x800438D0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800438D4: lbu         $v0, 0x1C9($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1C9);
    // 0x800438D8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800438DC: beq         $v0, $at, L_800438F0
    if (ctx->r2 == ctx->r1) {
        // 0x800438E0: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800438F0;
    }
    // 0x800438E0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800438E4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800438E8: bne         $v0, $at, L_80043900
    if (ctx->r2 != ctx->r1) {
        // 0x800438EC: nop
    
            goto L_80043900;
    }
    // 0x800438EC: nop

L_800438F0:
    // 0x800438F0: lw          $t9, -0x2550($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2550);
    // 0x800438F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800438F8: ori         $t8, $t9, 0x2000
    ctx->r24 = ctx->r25 | 0X2000;
    // 0x800438FC: sw          $t8, -0x2550($at)
    MEM_W(-0X2550, ctx->r1) = ctx->r24;
L_80043900:
    // 0x80043900: beq         $v1, $zero, L_80043978
    if (ctx->r3 == 0) {
        // 0x80043904: sb          $zero, 0x1C9($s0)
        MEM_B(0X1C9, ctx->r16) = 0;
            goto L_80043978;
    }
    // 0x80043904: sb          $zero, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = 0;
    // 0x80043908: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x8004390C: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80043910: beq         $ra, $t6, L_80043978
    if (ctx->r31 == ctx->r14) {
        // 0x80043914: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_80043978;
    }
    // 0x80043914: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80043918: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004391C: nop

    // 0x80043920: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80043924: nop

    // 0x80043928: bc1f        L_80043978
    if (!c1cs) {
        // 0x8004392C: nop
    
            goto L_80043978;
    }
    // 0x8004392C: nop

    // 0x80043930: beq         $t5, $zero, L_80043978
    if (ctx->r13 == 0) {
        // 0x80043934: slti        $at, $t4, 0x3
        ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
            goto L_80043978;
    }
    // 0x80043934: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x80043938: beq         $at, $zero, L_80043978
    if (ctx->r1 == 0) {
        // 0x8004393C: nop
    
            goto L_80043978;
    }
    // 0x8004393C: nop

    // 0x80043940: lb          $t7, 0x3E($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X3E);
    // 0x80043944: lb          $t8, 0x3F($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X3F);
    // 0x80043948: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8004394C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80043950: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80043954: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80043958: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x8004395C: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80043960: lb          $t8, 0x0($t9)
    ctx->r24 = MEM_B(ctx->r25, 0X0);
    // 0x80043964: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80043968: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x8004396C: beq         $at, $zero, L_80043978
    if (ctx->r1 == 0) {
        // 0x80043970: nop
    
            goto L_80043978;
    }
    // 0x80043970: nop

    // 0x80043974: sb          $t6, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r14;
L_80043978:
    // 0x80043978: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004397C: lwc1        $f4, -0x253C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X253C);
    // 0x80043980: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80043984: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80043988: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x8004398C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80043990: bc1f        L_800439D0
    if (!c1cs) {
        // 0x80043994: lw          $v1, 0x58($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X58);
            goto L_800439D0;
    }
    // 0x80043994: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80043998: lb          $t7, -0x2CE8($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2CE8);
    // 0x8004399C: nop

    // 0x800439A0: sb          $t7, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r15;
    // 0x800439A4: lh          $a0, 0x3C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3C);
    // 0x800439A8: jal         0x80044490
    // 0x800439AC: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    roll_percent_chance(rdram, ctx);
        goto after_27;
    // 0x800439AC: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    after_27:
    // 0x800439B0: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800439B4: beq         $v0, $zero, L_800439CC
    if (ctx->r2 == 0) {
        // 0x800439B8: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_800439CC;
    }
    // 0x800439B8: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x800439BC: lb          $t9, 0x1CA($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1CA);
    // 0x800439C0: nop

    // 0x800439C4: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x800439C8: sb          $t8, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r24;
L_800439CC:
    // 0x800439CC: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
L_800439D0:
    // 0x800439D0: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x800439D4: sh          $t6, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r14;
    // 0x800439D8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
L_800439DC:
    // 0x800439DC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800439E0: bne         $t7, $at, L_80043A20
    if (ctx->r15 != ctx->r1) {
        // 0x800439E4: nop
    
            goto L_80043A20;
    }
    // 0x800439E4: nop

    // 0x800439E8: beq         $v1, $zero, L_80043A20
    if (ctx->r3 == 0) {
        // 0x800439EC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80043A20;
    }
    // 0x800439EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800439F0: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800439F4: lwc1        $f11, 0x6838($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6838);
    // 0x800439F8: lwc1        $f10, 0x683C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X683C);
    // 0x800439FC: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80043A00: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x80043A04: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80043A08: bc1f        L_80043A20
    if (!c1cs) {
        // 0x80043A0C: nop
    
            goto L_80043A20;
    }
    // 0x80043A0C: nop

    // 0x80043A10: lbu         $t9, 0x209($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X209);
    // 0x80043A14: sb          $t6, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r14;
    // 0x80043A18: andi        $t8, $t9, 0xFFFB
    ctx->r24 = ctx->r25 & 0XFFFB;
    // 0x80043A1C: sb          $t8, 0x209($s0)
    MEM_B(0X209, ctx->r16) = ctx->r24;
L_80043A20:
    // 0x80043A20: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80043A24: lw          $t7, -0x2540($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2540);
    // 0x80043A28: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80043A2C: bne         $t7, $zero, L_80043B70
    if (ctx->r15 != 0) {
        // 0x80043A30: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80043B70;
    }
    // 0x80043A30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043A34: lwc1        $f14, 0x4($t9)
    ctx->f14.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80043A38: lwc1        $f17, 0x6840($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6840);
    // 0x80043A3C: lwc1        $f16, 0x6844($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6844);
    // 0x80043A40: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x80043A44: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80043A48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043A4C: lwc1        $f19, 0x6848($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6848);
    // 0x80043A50: lwc1        $f18, 0x684C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X684C);
    // 0x80043A54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043A58: lwc1        $f11, 0x6850($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6850);
    // 0x80043A5C: lwc1        $f10, 0x6854($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6854);
    // 0x80043A60: add.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d + ctx->f18.d;
    // 0x80043A64: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80043A68: div.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f10.d);
    // 0x80043A6C: jal         0x800CA030
    // 0x80043A70: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    sqrtf_recomp(rdram, ctx);
        goto after_28;
    // 0x80043A70: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    after_28:
    // 0x80043A74: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80043A78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043A7C: lwc1        $f2, 0x0($t8)
    ctx->f2.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80043A80: lwc1        $f5, 0x6858($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6858);
    // 0x80043A84: lwc1        $f4, 0x685C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X685C);
    // 0x80043A88: cvt.d.s     $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.d = CVT_D_S(ctx->f2.fl);
    // 0x80043A8C: mul.d       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80043A90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043A94: lwc1        $f7, 0x6860($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6860);
    // 0x80043A98: lwc1        $f6, 0x6864($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6864);
    // 0x80043A9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043AA0: lwc1        $f9, 0x6868($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6868);
    // 0x80043AA4: lwc1        $f8, 0x686C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X686C);
    // 0x80043AA8: add.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f18.d + ctx->f6.d;
    // 0x80043AAC: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x80043AB0: div.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x80043AB4: jal         0x800CA030
    // 0x80043AB8: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    sqrtf_recomp(rdram, ctx);
        goto after_29;
    // 0x80043AB8: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    after_29:
    // 0x80043ABC: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80043AC0: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80043AC4: lwc1        $f14, 0x80($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80043AC8: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80043ACC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80043AD0: lb          $v0, 0x1CA($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CA);
    // 0x80043AD4: sub.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80043AD8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80043ADC: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80043AE0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80043AE4: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043AE8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80043AEC: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80043AF0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80043AF4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80043AF8: add.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80043AFC: bne         $at, $zero, L_80043B2C
    if (ctx->r1 != 0) {
        // 0x80043B00: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_80043B2C;
    }
    // 0x80043B00: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80043B04: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80043B08: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043B0C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80043B10: lwc1        $f11, 0x6870($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6870);
    // 0x80043B14: lwc1        $f10, 0x6874($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6874);
    // 0x80043B18: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80043B1C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80043B20: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x80043B24: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x80043B28: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
L_80043B2C:
    // 0x80043B2C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80043B30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043B34: lwc1        $f11, 0x6878($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6878);
    // 0x80043B38: lwc1        $f10, 0x687C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X687C);
    // 0x80043B3C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80043B40: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80043B44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043B48: lwc1        $f17, 0x6880($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6880);
    // 0x80043B4C: lwc1        $f16, 0x6884($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6884);
    // 0x80043B50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043B54: lwc1        $f7, 0x6888($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6888);
    // 0x80043B58: lwc1        $f6, 0x688C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X688C);
    // 0x80043B5C: sub.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d - ctx->f16.d;
    // 0x80043B60: nop

    // 0x80043B64: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x80043B68: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x80043B6C: swc1        $f2, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f2.u32l;
L_80043B70:
    // 0x80043B70: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80043B74: beq         $t1, $zero, L_80043BB0
    if (ctx->r9 == 0) {
        // 0x80043B78: nop
    
            goto L_80043BB0;
    }
    // 0x80043B78: nop

    // 0x80043B7C: lb          $t8, 0x1CA($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1CA);
    // 0x80043B80: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80043B84: bne         $t8, $at, L_80043BB0
    if (ctx->r24 != ctx->r1) {
        // 0x80043B88: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80043BB0;
    }
    // 0x80043B88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043B8C: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80043B90: lwc1        $f11, 0x6890($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6890);
    // 0x80043B94: lwc1        $f10, 0x6894($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6894);
    // 0x80043B98: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80043B9C: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x80043BA0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80043BA4: bc1f        L_80043BB0
    if (!c1cs) {
        // 0x80043BA8: nop
    
            goto L_80043BB0;
    }
    // 0x80043BA8: nop

    // 0x80043BAC: sb          $t6, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r14;
L_80043BB0:
    // 0x80043BB0: lbu         $v0, 0x1C9($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1C9);
    // 0x80043BB4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80043BB8: beq         $v0, $zero, L_80043BD8
    if (ctx->r2 == 0) {
        // 0x80043BBC: nop
    
            goto L_80043BD8;
    }
    // 0x80043BBC: nop

    // 0x80043BC0: beq         $v0, $at, L_80043C50
    if (ctx->r2 == ctx->r1) {
        // 0x80043BC4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80043C50;
    }
    // 0x80043BC4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80043BC8: beq         $v0, $at, L_80043C64
    if (ctx->r2 == ctx->r1) {
        // 0x80043BCC: nop
    
            goto L_80043C64;
    }
    // 0x80043BCC: nop

    // 0x80043BD0: b           L_80043C78
    // 0x80043BD4: nop

        goto L_80043C78;
    // 0x80043BD4: nop

L_80043BD8:
    // 0x80043BD8: beq         $t1, $zero, L_80043C78
    if (ctx->r9 == 0) {
        // 0x80043BDC: nop
    
            goto L_80043C78;
    }
    // 0x80043BDC: nop

    // 0x80043BE0: lh          $t7, 0x0($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X0);
    // 0x80043BE4: nop

    // 0x80043BE8: bne         $ra, $t7, L_80043C78
    if (ctx->r31 != ctx->r15) {
        // 0x80043BEC: nop
    
            goto L_80043C78;
    }
    // 0x80043BEC: nop

    // 0x80043BF0: lbu         $t9, 0x1C9($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X1C9);
    // 0x80043BF4: nop

    // 0x80043BF8: bne         $t9, $zero, L_80043C78
    if (ctx->r25 != 0) {
        // 0x80043BFC: nop
    
            goto L_80043C78;
    }
    // 0x80043BFC: nop

    // 0x80043C00: lb          $v0, 0x1CA($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CA);
    // 0x80043C04: lb          $t8, 0x1CA($t1)
    ctx->r24 = MEM_B(ctx->r9, 0X1CA);
    // 0x80043C08: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80043C0C: bne         $v0, $t8, L_80043C78
    if (ctx->r2 != ctx->r24) {
        // 0x80043C10: lui         $at, 0x4059
        ctx->r1 = S32(0X4059 << 16);
            goto L_80043C78;
    }
    // 0x80043C10: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80043C14: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80043C18: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80043C1C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80043C20: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80043C24: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80043C28: bc1f        L_80043C78
    if (!c1cs) {
        // 0x80043C2C: nop
    
            goto L_80043C78;
    }
    // 0x80043C2C: nop

    // 0x80043C30: sb          $t6, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r14;
    // 0x80043C34: lb          $t7, 0x1CA($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1CA);
    // 0x80043C38: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80043C3C: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80043C40: bne         $at, $zero, L_80043C78
    if (ctx->r1 != 0) {
        // 0x80043C44: nop
    
            goto L_80043C78;
    }
    // 0x80043C44: nop

    // 0x80043C48: b           L_80043C78
    // 0x80043C4C: sb          $t9, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r25;
        goto L_80043C78;
    // 0x80043C4C: sb          $t9, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r25;
L_80043C50:
    // 0x80043C50: beq         $t1, $zero, L_80043C78
    if (ctx->r9 == 0) {
        // 0x80043C54: nop
    
            goto L_80043C78;
    }
    // 0x80043C54: nop

    // 0x80043C58: lh          $t8, 0x1BA($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X1BA);
    // 0x80043C5C: b           L_80043C78
    // 0x80043C60: sh          $t8, 0x1BA($s0)
    MEM_H(0X1BA, ctx->r16) = ctx->r24;
        goto L_80043C78;
    // 0x80043C60: sh          $t8, 0x1BA($s0)
    MEM_H(0X1BA, ctx->r16) = ctx->r24;
L_80043C64:
    // 0x80043C64: beq         $v1, $zero, L_80043C78
    if (ctx->r3 == 0) {
        // 0x80043C68: nop
    
            goto L_80043C78;
    }
    // 0x80043C68: nop

    // 0x80043C6C: lh          $t6, 0x1BA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1BA);
    // 0x80043C70: nop

    // 0x80043C74: sh          $t6, 0x1BA($s0)
    MEM_H(0X1BA, ctx->r16) = ctx->r14;
L_80043C78:
    // 0x80043C78: jal         0x80023450
    // 0x80043C7C: nop

    is_taj_challenge(rdram, ctx);
        goto after_30;
    // 0x80043C7C: nop

    after_30:
    // 0x80043C80: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80043C84: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80043C88: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80043C8C: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80043C90: bne         $t8, $zero, L_80043CA8
    if (ctx->r24 != 0) {
        // 0x80043C94: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_80043CA8;
    }
    // 0x80043C94: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80043C98: lh          $t6, 0x70($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X70);
    // 0x80043C9C: nop

    // 0x80043CA0: beq         $t6, $zero, L_80043CFC
    if (ctx->r14 == 0) {
        // 0x80043CA4: lh          $t6, 0x70($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X70);
            goto L_80043CFC;
    }
    // 0x80043CA4: lh          $t6, 0x70($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X70);
L_80043CA8:
    // 0x80043CA8: sb          $zero, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = 0;
    // 0x80043CAC: sb          $zero, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = 0;
    // 0x80043CB0: lh          $t7, 0x70($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X70);
    // 0x80043CB4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x80043CB8: beq         $t7, $zero, L_80043CD4
    if (ctx->r15 == 0) {
        // 0x80043CBC: nop
    
            goto L_80043CD4;
    }
    // 0x80043CBC: nop

    // 0x80043CC0: jal         0x8001E2D0
    // 0x80043CC4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    get_misc_asset(rdram, ctx);
        goto after_31;
    // 0x80043CC4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_31:
    // 0x80043CC8: lh          $v1, 0x70($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X70);
    // 0x80043CCC: b           L_80043CE8
    // 0x80043CD0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
        goto L_80043CE8;
    // 0x80043CD0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_80043CD4:
    // 0x80043CD4: jal         0x8001E2D0
    // 0x80043CD8: sh          $v1, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r3;
    get_misc_asset(rdram, ctx);
        goto after_32;
    // 0x80043CD8: sh          $v1, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r3;
    after_32:
    // 0x80043CDC: lh          $v1, 0x7A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X7A);
    // 0x80043CE0: nop

    // 0x80043CE4: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_80043CE8:
    // 0x80043CE8: addu        $t8, $v0, $t9
    ctx->r24 = ADD32(ctx->r2, ctx->r25);
    // 0x80043CEC: lwc1        $f18, -0x4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, -0X4);
    // 0x80043CF0: nop

    // 0x80043CF4: swc1        $f18, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f18.u32l;
    // 0x80043CF8: lh          $t6, 0x70($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X70);
L_80043CFC:
    // 0x80043CFC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80043D00: beq         $t6, $zero, L_80043E88
    if (ctx->r14 == 0) {
        // 0x80043D04: nop
    
            goto L_80043E88;
    }
    // 0x80043D04: nop

    // 0x80043D08: lw          $t7, -0x2540($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2540);
    // 0x80043D0C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80043D10: beq         $t7, $zero, L_80043D2C
    if (ctx->r15 == 0) {
        // 0x80043D14: addiu       $v1, $v1, -0x24C8
        ctx->r3 = ADD32(ctx->r3, -0X24C8);
            goto L_80043D2C;
    }
    // 0x80043D14: addiu       $v1, $v1, -0x24C8
    ctx->r3 = ADD32(ctx->r3, -0X24C8);
    // 0x80043D18: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80043D1C: addiu       $v1, $v1, -0x24C8
    ctx->r3 = ADD32(ctx->r3, -0X24C8);
    // 0x80043D20: addiu       $t9, $zero, 0x384
    ctx->r25 = ADD32(0, 0X384);
    // 0x80043D24: b           L_80043E28
    // 0x80043D28: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
        goto L_80043E28;
    // 0x80043D28: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
L_80043D2C:
    // 0x80043D2C: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80043D30: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x80043D34: nop

    // 0x80043D38: subu        $t7, $t8, $t6
    ctx->r15 = SUB32(ctx->r24, ctx->r14);
    // 0x80043D3C: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x80043D40: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80043D44: nop

    // 0x80043D48: bgez        $v0, L_80043DA4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80043D4C: slti        $at, $v0, 0x2D1
        ctx->r1 = SIGNED(ctx->r2) < 0X2D1 ? 1 : 0;
            goto L_80043DA4;
    }
    // 0x80043D4C: slti        $at, $v0, 0x2D1
    ctx->r1 = SIGNED(ctx->r2) < 0X2D1 ? 1 : 0;
    // 0x80043D50: lh          $t9, 0x72($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X72);
    // 0x80043D54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80043D58: bne         $t9, $at, L_80043E28
    if (ctx->r25 != ctx->r1) {
        // 0x80043D5C: sh          $zero, 0x0($v1)
        MEM_H(0X0, ctx->r3) = 0;
            goto L_80043E28;
    }
    // 0x80043D5C: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80043D60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043D64: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80043D68: lwc1        $f11, 0x6898($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6898);
    // 0x80043D6C: lwc1        $f10, 0x689C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X689C);
    // 0x80043D70: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80043D74: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x80043D78: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80043D7C: bc1f        L_80043E28
    if (!c1cs) {
        // 0x80043D80: nop
    
            goto L_80043E28;
    }
    // 0x80043D80: nop

    // 0x80043D84: lwc1        $f6, 0x124($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X124);
    // 0x80043D88: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80043D8C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80043D90: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80043D94: add.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f8.d + ctx->f18.d;
    // 0x80043D98: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80043D9C: b           L_80043E28
    // 0x80043DA0: swc1        $f10, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f10.u32l;
        goto L_80043E28;
    // 0x80043DA0: swc1        $f10, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f10.u32l;
L_80043DA4:
    // 0x80043DA4: lwc1        $f0, 0x124($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X124);
    // 0x80043DA8: bne         $at, $zero, L_80043DCC
    if (ctx->r1 != 0) {
        // 0x80043DAC: mov.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
            goto L_80043DCC;
    }
    // 0x80043DAC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80043DB0: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80043DB4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80043DB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80043DBC: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80043DC0: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80043DC4: b           L_80043E14
    // 0x80043DC8: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
        goto L_80043E14;
    // 0x80043DC8: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
L_80043DCC:
    // 0x80043DCC: lh          $t8, 0x72($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X72);
    // 0x80043DD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80043DD4: beq         $t8, $at, L_80043E00
    if (ctx->r24 == ctx->r1) {
        // 0x80043DD8: lui         $at, 0x4024
        ctx->r1 = S32(0X4024 << 16);
            goto L_80043E00;
    }
    // 0x80043DD8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80043DDC: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80043DE0: lui         $at, 0x4069
    ctx->r1 = S32(0X4069 << 16);
    // 0x80043DE4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80043DE8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80043DEC: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80043DF0: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x80043DF4: nop

    // 0x80043DF8: bc1f        L_80043E14
    if (!c1cs) {
        // 0x80043DFC: lui         $at, 0x4024
        ctx->r1 = S32(0X4024 << 16);
            goto L_80043E14;
    }
    // 0x80043DFC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
L_80043E00:
    // 0x80043E00: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80043E04: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80043E08: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80043E0C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80043E10: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
L_80043E14:
    // 0x80043E14: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80043E18: nop

    // 0x80043E1C: bc1f        L_80043E28
    if (!c1cs) {
        // 0x80043E20: nop
    
            goto L_80043E28;
    }
    // 0x80043E20: nop

    // 0x80043E24: swc1        $f14, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f14.u32l;
L_80043E28:
    // 0x80043E28: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x80043E2C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80043E30: beq         $t6, $zero, L_80043E88
    if (ctx->r14 == 0) {
        // 0x80043E34: addiu       $v0, $v0, -0x2558
        ctx->r2 = ADD32(ctx->r2, -0X2558);
            goto L_80043E88;
    }
    // 0x80043E34: addiu       $v0, $v0, -0x2558
    ctx->r2 = ADD32(ctx->r2, -0X2558);
    // 0x80043E38: sb          $zero, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = 0;
    // 0x80043E3C: sb          $zero, 0x213($s0)
    MEM_B(0X213, ctx->r16) = 0;
    // 0x80043E40: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80043E44: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80043E48: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80043E4C: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x80043E50: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80043E54: ori         $t6, $t9, 0x4000
    ctx->r14 = ctx->r25 | 0X4000;
    // 0x80043E58: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80043E5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043E60: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80043E64: lwc1        $f19, 0x68A0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X68A0);
    // 0x80043E68: lwc1        $f18, 0x68A4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X68A4);
    // 0x80043E6C: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80043E70: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x80043E74: ori         $t9, $t6, 0x8000
    ctx->r25 = ctx->r14 | 0X8000;
    // 0x80043E78: bc1f        L_80043E88
    if (!c1cs) {
        // 0x80043E7C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80043E88;
    }
    // 0x80043E7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043E80: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80043E84: sw          $zero, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = 0;
L_80043E88:
    // 0x80043E88: lb          $t8, 0x214($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X214);
    // 0x80043E8C: lh          $t6, 0x6E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6E);
    // 0x80043E90: beq         $t8, $zero, L_80043E9C
    if (ctx->r24 == 0) {
        // 0x80043E94: addiu       $t9, $zero, 0x40
        ctx->r25 = ADD32(0, 0X40);
            goto L_80043E9C;
    }
    // 0x80043E94: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x80043E98: sb          $t6, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r14;
L_80043E9C:
    // 0x80043E9C: lh          $t7, 0x1BA($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1BA);
    // 0x80043EA0: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x80043EA4: slti        $at, $t7, 0x41
    ctx->r1 = SIGNED(ctx->r15) < 0X41 ? 1 : 0;
    // 0x80043EA8: bne         $at, $zero, L_80043EB4
    if (ctx->r1 != 0) {
        // 0x80043EAC: nop
    
            goto L_80043EB4;
    }
    // 0x80043EAC: nop

    // 0x80043EB0: sh          $t9, 0x1BA($s0)
    MEM_H(0X1BA, ctx->r16) = ctx->r25;
L_80043EB4:
    // 0x80043EB4: lh          $t8, 0x1BC($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1BC);
    // 0x80043EB8: addiu       $t9, $zero, -0x40
    ctx->r25 = ADD32(0, -0X40);
    // 0x80043EBC: slti        $at, $t8, 0x29
    ctx->r1 = SIGNED(ctx->r24) < 0X29 ? 1 : 0;
    // 0x80043EC0: bne         $at, $zero, L_80043ECC
    if (ctx->r1 != 0) {
        // 0x80043EC4: nop
    
            goto L_80043ECC;
    }
    // 0x80043EC4: nop

    // 0x80043EC8: sh          $t6, 0x1BC($s0)
    MEM_H(0X1BC, ctx->r16) = ctx->r14;
L_80043ECC:
    // 0x80043ECC: lh          $t7, 0x1BA($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1BA);
    // 0x80043ED0: addiu       $t6, $zero, -0x28
    ctx->r14 = ADD32(0, -0X28);
    // 0x80043ED4: slti        $at, $t7, -0x40
    ctx->r1 = SIGNED(ctx->r15) < -0X40 ? 1 : 0;
    // 0x80043ED8: beq         $at, $zero, L_80043EE4
    if (ctx->r1 == 0) {
        // 0x80043EDC: nop
    
            goto L_80043EE4;
    }
    // 0x80043EDC: nop

    // 0x80043EE0: sh          $t9, 0x1BA($s0)
    MEM_H(0X1BA, ctx->r16) = ctx->r25;
L_80043EE4:
    // 0x80043EE4: lh          $t8, 0x1BC($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1BC);
    // 0x80043EE8: nop

    // 0x80043EEC: slti        $at, $t8, -0x28
    ctx->r1 = SIGNED(ctx->r24) < -0X28 ? 1 : 0;
    // 0x80043EF0: beq         $at, $zero, L_80043F00
    if (ctx->r1 == 0) {
        // 0x80043EF4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80043F00;
    }
    // 0x80043EF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80043EF8: sh          $t6, 0x1BC($s0)
    MEM_H(0X1BC, ctx->r16) = ctx->r14;
L_80043EFC:
    // 0x80043EFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80043F00:
    // 0x80043F00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80043F04: jr          $ra
    // 0x80043F08: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80043F08: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void lerp_and_get_derivative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800228E4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800228E8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800228EC: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800228F0: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800228F4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800228F8: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800228FC: sub.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80022900: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80022904: swc1        $f2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
    // 0x80022908: jr          $ra
    // 0x8002290C: add.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f8.fl;
    return;
    // 0x8002290C: add.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f8.fl;
;}
RECOMP_FUNC void set_breakpoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void racer_approach_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050794: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80050798: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005079C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800507A0: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x800507A4: sb          $zero, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = 0;
    // 0x800507A8: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    // 0x800507AC: lw          $v0, 0x148($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X148);
    // 0x800507B0: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800507B4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800507B8: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800507BC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800507C0: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800507C4: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800507C8: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800507CC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800507D0: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800507D4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800507D8: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800507DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800507E0: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800507E4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800507E8: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x800507EC: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x800507F0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800507F4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800507F8: jal         0x80011570
    // 0x800507FC: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    move_object(rdram, ctx);
        goto after_0;
    // 0x800507FC: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80050800: lw          $t7, 0x148($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X148);
    // 0x80050804: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80050808: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8005080C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80050810: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80050814: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80050818: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8005081C: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x80050820: lw          $t9, 0x148($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X148);
    // 0x80050824: div.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80050828: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x8005082C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80050830: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    // 0x80050834: lw          $t1, 0x148($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X148);
    // 0x80050838: nop

    // 0x8005083C: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x80050840: nop

    // 0x80050844: sh          $t2, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r10;
    // 0x80050848: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x8005084C: nop

    // 0x80050850: sh          $t3, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r11;
    // 0x80050854: div.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80050858: lh          $t4, 0x0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X0);
    // 0x8005085C: nop

    // 0x80050860: sh          $t4, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r12;
    // 0x80050864: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x80050868: div.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8005086C: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x80050870: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    // 0x80050874: sb          $zero, 0x1F2($s0)
    MEM_B(0X1F2, ctx->r16) = 0;
    // 0x80050878: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x8005087C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x80050880: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80050884: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80050888: jr          $ra
    // 0x8005088C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005088C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void taj_menu_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D8A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009D8A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D8AC: jal         0x8006ECD0
    // 0x8009D8B0: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009D8B0: nop

    after_0:
    // 0x8009D8B4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009D8B8: lb          $v1, -0x5A4($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X5A4);
    // 0x8009D8BC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8009D8C0: beq         $v1, $zero, L_8009D8E0
    if (ctx->r3 == 0) {
        // 0x8009D8C4: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8009D8E0;
    }
    // 0x8009D8C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D8C8: addiu       $v0, $v0, 0x6A82
    ctx->r2 = ADD32(ctx->r2, 0X6A82);
    // 0x8009D8CC: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009D8D0: negu        $t7, $v1
    ctx->r15 = SUB32(0, ctx->r3);
    // 0x8009D8D4: bne         $t6, $zero, L_8009D8E0
    if (ctx->r14 != 0) {
        // 0x8009D8D8: nop
    
            goto L_8009D8E0;
    }
    // 0x8009D8D8: nop

    // 0x8009D8DC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_8009D8E0:
    // 0x8009D8E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D8E4: addiu       $v0, $v0, 0x6A82
    ctx->r2 = ADD32(ctx->r2, 0X6A82);
    // 0x8009D8E8: lb          $a1, 0x0($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X0);
    // 0x8009D8EC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009D8F0: bne         $a1, $zero, L_8009D904
    if (ctx->r5 != 0) {
        // 0x8009D8F4: nop
    
            goto L_8009D904;
    }
    // 0x8009D8F4: nop

    // 0x8009D8F8: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8009D8FC: lb          $a1, 0x0($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X0);
    // 0x8009D900: nop

L_8009D904:
    // 0x8009D904: blez        $a1, L_8009D938
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8009D908: slti        $at, $a1, 0x4
        ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
            goto L_8009D938;
    }
    // 0x8009D908: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8009D90C: beq         $at, $zero, L_8009D938
    if (ctx->r1 == 0) {
        // 0x8009D910: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8009D938;
    }
    // 0x8009D910: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D914: addiu       $t9, $zero, 0x7C
    ctx->r25 = ADD32(0, 0X7C);
    // 0x8009D918: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009D91C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8009D920: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009D924: jal         0x800C543C
    // 0x8009D928: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_1;
    // 0x8009D928: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    after_1:
    // 0x8009D92C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D930: jal         0x800C54DC
    // 0x8009D934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_2;
    // 0x8009D934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8009D938:
    // 0x8009D938: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8009D93C: jal         0x8006A794
    // 0x8009D940: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_3;
    // 0x8009D940: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8009D944: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D948: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009D94C: lb          $a1, 0x6A82($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6A82);
    // 0x8009D950: sb          $zero, 0x6AA4($at)
    MEM_B(0X6AA4, ctx->r1) = 0;
    // 0x8009D954: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009D958: beq         $a1, $at, L_8009D988
    if (ctx->r5 == ctx->r1) {
        // 0x8009D95C: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_8009D988;
    }
    // 0x8009D95C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8009D960: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009D964: beq         $a1, $at, L_8009DA30
    if (ctx->r5 == ctx->r1) {
        // 0x8009D968: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8009DA30;
    }
    // 0x8009D968: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D96C: addiu       $at, $zero, 0x62
    ctx->r1 = ADD32(0, 0X62);
    // 0x8009D970: beq         $a1, $at, L_8009D988
    if (ctx->r5 == ctx->r1) {
        // 0x8009D974: addiu       $at, $zero, 0x63
        ctx->r1 = ADD32(0, 0X63);
            goto L_8009D988;
    }
    // 0x8009D974: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x8009D978: beq         $a1, $at, L_8009DA30
    if (ctx->r5 == ctx->r1) {
        // 0x8009D97C: nop
    
            goto L_8009DA30;
    }
    // 0x8009D97C: nop

    // 0x8009D980: b           L_8009DB38
    // 0x8009D984: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
        goto L_8009DB38;
    // 0x8009D984: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
L_8009D988:
    // 0x8009D988: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009D98C: lw          $t0, -0x5E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E0);
    // 0x8009D990: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009D994: lw          $a3, 0xA0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XA0);
    // 0x8009D998: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009D99C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009D9A0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009D9A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D9A8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009D9AC: jal         0x800C56C8
    // 0x8009D9B0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_4;
    // 0x8009D9B0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_4:
    // 0x8009D9B4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009D9B8: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009D9BC: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x8009D9C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D9C4: sb          $t3, 0x6AAE($at)
    MEM_B(0X6AAE, ctx->r1) = ctx->r11;
    // 0x8009D9C8: lw          $a0, 0xA4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XA4);
    // 0x8009D9CC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D9D0: jal         0x8009D6FC
    // 0x8009D9D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_5;
    // 0x8009D9D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8009D9D8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009D9DC: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009D9E0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D9E4: lw          $a0, 0xA8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XA8);
    // 0x8009D9E8: jal         0x8009D6FC
    // 0x8009D9EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    render_dialogue_option(rdram, ctx);
        goto after_6;
    // 0x8009D9EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8009D9F0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009D9F4: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x8009D9F8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D9FC: lw          $a0, 0xAC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XAC);
    // 0x8009DA00: jal         0x8009D6FC
    // 0x8009DA04: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    render_dialogue_option(rdram, ctx);
        goto after_7;
    // 0x8009DA04: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_7:
    // 0x8009DA08: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009DA0C: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x8009DA10: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DA14: lw          $a0, 0xB0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XB0);
    // 0x8009DA18: jal         0x8009D6FC
    // 0x8009DA1C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    render_dialogue_option(rdram, ctx);
        goto after_8;
    // 0x8009DA1C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
    // 0x8009DA20: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009DA24: lb          $a1, 0x6A82($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6A82);
    // 0x8009DA28: b           L_8009DB38
    // 0x8009DA2C: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
        goto L_8009DB38;
    // 0x8009DA2C: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
L_8009DA30:
    // 0x8009DA30: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009DA34: lw          $t8, -0x5E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E0);
    // 0x8009DA38: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009DA3C: lw          $a3, 0xB4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0XB4);
    // 0x8009DA40: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8009DA44: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8009DA48: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009DA4C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009DA50: jal         0x800C56C8
    // 0x8009DA54: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_9;
    // 0x8009DA54: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_9:
    // 0x8009DA58: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8009DA5C: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x8009DA60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DA64: sb          $t1, 0x6AAE($at)
    MEM_B(0X6AAE, ctx->r1) = ctx->r9;
    // 0x8009DA68: lhu         $v1, 0x14($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0X14);
    // 0x8009DA6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DA70: andi        $t3, $v1, 0x1
    ctx->r11 = ctx->r3 & 0X1;
    // 0x8009DA74: beq         $t3, $zero, L_8009DAA8
    if (ctx->r11 == 0) {
        // 0x8009DA78: andi        $t4, $v1, 0x8
        ctx->r12 = ctx->r3 & 0X8;
            goto L_8009DAA8;
    }
    // 0x8009DA78: andi        $t4, $v1, 0x8
    ctx->r12 = ctx->r3 & 0X8;
    // 0x8009DA7C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009DA80: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009DA84: sb          $t4, -0x594($at)
    MEM_B(-0X594, ctx->r1) = ctx->r12;
    // 0x8009DA88: lw          $a0, 0xB8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XB8);
    // 0x8009DA8C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DA90: jal         0x8009D6FC
    // 0x8009DA94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_10;
    // 0x8009DA94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8009DA98: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8009DA9C: nop

    // 0x8009DAA0: lhu         $v1, 0x14($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X14);
    // 0x8009DAA4: nop

L_8009DAA8:
    // 0x8009DAA8: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x8009DAAC: beq         $t7, $zero, L_8009DAE4
    if (ctx->r15 == 0) {
        // 0x8009DAB0: andi        $t8, $v1, 0x10
        ctx->r24 = ctx->r3 & 0X10;
            goto L_8009DAE4;
    }
    // 0x8009DAB0: andi        $t8, $v1, 0x10
    ctx->r24 = ctx->r3 & 0X10;
    // 0x8009DAB4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009DAB8: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x8009DABC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DAC0: sb          $t8, -0x594($at)
    MEM_B(-0X594, ctx->r1) = ctx->r24;
    // 0x8009DAC4: lw          $a0, 0xBC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XBC);
    // 0x8009DAC8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DACC: jal         0x8009D6FC
    // 0x8009DAD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    render_dialogue_option(rdram, ctx);
        goto after_11;
    // 0x8009DAD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x8009DAD4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8009DAD8: nop

    // 0x8009DADC: lhu         $v1, 0x14($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X14);
    // 0x8009DAE0: nop

L_8009DAE4:
    // 0x8009DAE4: andi        $t1, $v1, 0x4
    ctx->r9 = ctx->r3 & 0X4;
    // 0x8009DAE8: beq         $t1, $zero, L_8009DB10
    if (ctx->r9 == 0) {
        // 0x8009DAEC: andi        $t2, $v1, 0x20
        ctx->r10 = ctx->r3 & 0X20;
            goto L_8009DB10;
    }
    // 0x8009DAEC: andi        $t2, $v1, 0x20
    ctx->r10 = ctx->r3 & 0X20;
    // 0x8009DAF0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009DAF4: lw          $t3, -0x5E0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5E0);
    // 0x8009DAF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DAFC: sb          $t2, -0x594($at)
    MEM_B(-0X594, ctx->r1) = ctx->r10;
    // 0x8009DB00: lw          $a0, 0xC0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC0);
    // 0x8009DB04: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DB08: jal         0x8009D6FC
    // 0x8009DB0C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    render_dialogue_option(rdram, ctx);
        goto after_12;
    // 0x8009DB0C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_12:
L_8009DB10:
    // 0x8009DB10: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009DB14: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009DB18: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DB1C: lw          $a0, 0xB0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XB0);
    // 0x8009DB20: jal         0x8009D6FC
    // 0x8009DB24: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    render_dialogue_option(rdram, ctx);
        goto after_13;
    // 0x8009DB24: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_13:
    // 0x8009DB28: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009DB2C: lb          $a1, 0x6A82($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6A82);
    // 0x8009DB30: nop

    // 0x8009DB34: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
L_8009DB38:
    // 0x8009DB38: sltiu       $at, $t5, 0x10
    ctx->r1 = ctx->r13 < 0X10 ? 1 : 0;
    // 0x8009DB3C: beq         $at, $zero, L_8009DF28
    if (ctx->r1 == 0) {
        // 0x8009DB40: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8009DF28;
    }
    // 0x8009DB40: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8009DB44: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009DB48: addu        $at, $at, $t5
    gpr jr_addend_8009DB54 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8009DB4C: lw          $t5, -0x74D0($at)
    ctx->r13 = ADD32(ctx->r1, -0X74D0);
    // 0x8009DB50: nop

    // 0x8009DB54: jr          $t5
    // 0x8009DB58: nop

    switch (jr_addend_8009DB54 >> 2) {
        case 0: goto L_8009DE88; break;
        case 1: goto L_8009DE88; break;
        case 2: goto L_8009DE88; break;
        case 3: goto L_8009DE60; break;
        case 4: goto L_8009DE34; break;
        case 5: goto L_8009DE18; break;
        case 6: goto L_8009DE18; break;
        case 7: goto L_8009DE18; break;
        case 8: goto L_8009DB5C; break;
        case 9: goto L_8009DB7C; break;
        case 10: goto L_8009DCE4; break;
        case 11: goto L_8009DD84; break;
        case 12: goto L_8009DEAC; break;
        case 13: goto L_8009DEDC; break;
        case 14: goto L_8009DEF4; break;
        case 15: goto L_8009DEF4; break;
        default: switch_error(__func__, 0x8009DB54, 0x800E8B30);
    }
    // 0x8009DB58: nop

L_8009DB5C:
    // 0x8009DB5C: jal         0x800C3744
    // 0x8009DB60: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    set_current_text(rdram, ctx);
        goto after_14;
    // 0x8009DB60: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_14:
    // 0x8009DB64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009DB68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DB6C: sb          $v0, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r2;
    // 0x8009DB70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DB74: b           L_8009DF28
    // 0x8009DB78: sb          $v0, -0x5A8($at)
    MEM_B(-0X5A8, ctx->r1) = ctx->r2;
        goto L_8009DF28;
    // 0x8009DB78: sb          $v0, -0x5A8($at)
    MEM_B(-0X5A8, ctx->r1) = ctx->r2;
L_8009DB7C:
    // 0x8009DB7C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009DB80: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x8009DB84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DB88: sb          $zero, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = 0;
    // 0x8009DB8C: lw          $a3, 0x2F8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X2F8);
    // 0x8009DB90: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009DB94: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8009DB98: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009DB9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009DBA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DBA4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009DBA8: jal         0x800C56C8
    // 0x8009DBAC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_15;
    // 0x8009DBAC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_15:
    // 0x8009DBB0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009DBB4: lw          $t0, -0x5E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E0);
    // 0x8009DBB8: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8009DBBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DBC0: sb          $t9, 0x6AAE($at)
    MEM_B(0X6AAE, ctx->r1) = ctx->r25;
    // 0x8009DBC4: lw          $a0, 0x94($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X94);
    // 0x8009DBC8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DBCC: jal         0x8009D6FC
    // 0x8009DBD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_16;
    // 0x8009DBD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x8009DBD4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8009DBD8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009DBDC: lhu         $t2, 0x14($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X14);
    // 0x8009DBE0: nop

    // 0x8009DBE4: andi        $t3, $t2, 0x7
    ctx->r11 = ctx->r10 & 0X7;
    // 0x8009DBE8: beq         $t3, $zero, L_8009DC04
    if (ctx->r11 == 0) {
        // 0x8009DBEC: nop
    
            goto L_8009DC04;
    }
    // 0x8009DBEC: nop

    // 0x8009DBF0: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009DBF4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DBF8: lw          $a0, 0x9C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X9C);
    // 0x8009DBFC: jal         0x8009D6FC
    // 0x8009DC00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    render_dialogue_option(rdram, ctx);
        goto after_17;
    // 0x8009DC00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
L_8009DC04:
    // 0x8009DC04: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009DC08: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009DC0C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DC10: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    // 0x8009DC14: jal         0x8009D6FC
    // 0x8009DC18: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    render_dialogue_option(rdram, ctx);
        goto after_18;
    // 0x8009DC18: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_18:
    // 0x8009DC1C: jal         0x8009D7B0
    // 0x8009DC20: nop

    handle_menu_joystick_input(rdram, ctx);
        goto after_19;
    // 0x8009DC20: nop

    after_19:
    // 0x8009DC24: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8009DC28: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8009DC2C: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8009DC30: beq         $t7, $zero, L_8009DC54
    if (ctx->r15 == 0) {
        // 0x8009DC34: andi        $t0, $t9, 0x8000
        ctx->r8 = ctx->r25 & 0X8000;
            goto L_8009DC54;
    }
    // 0x8009DC34: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x8009DC38: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8009DC3C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8009DC40: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009DC44: jal         0x80001D04
    // 0x8009DC48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_20;
    // 0x8009DC48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x8009DC4C: b           L_8009DF2C
    // 0x8009DC50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DF2C;
    // 0x8009DC50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DC54:
    // 0x8009DC54: beq         $t0, $zero, L_8009DF28
    if (ctx->r8 == 0) {
        // 0x8009DC58: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8009DF28;
    }
    // 0x8009DC58: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009DC5C: jal         0x80001D04
    // 0x8009DC60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_21;
    // 0x8009DC60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x8009DC64: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009DC68: lb          $v1, 0x6AB6($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6AB6);
    // 0x8009DC6C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8009DC70: beq         $v1, $zero, L_8009DCC4
    if (ctx->r3 == 0) {
        // 0x8009DC74: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8009DCC4;
    }
    // 0x8009DC74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DC78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009DC7C: beq         $v1, $at, L_8009DC98
    if (ctx->r3 == ctx->r1) {
        // 0x8009DC80: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_8009DC98;
    }
    // 0x8009DC80: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8009DC84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009DC88: beq         $v1, $at, L_8009DCBC
    if (ctx->r3 == ctx->r1) {
        // 0x8009DC8C: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8009DCBC;
    }
    // 0x8009DC8C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8009DC90: b           L_8009DF2C
    // 0x8009DC94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DF2C;
    // 0x8009DC94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DC98:
    // 0x8009DC98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DC9C: sb          $t1, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r9;
    // 0x8009DCA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DCA4: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
    // 0x8009DCA8: addiu       $a0, $zero, 0x239
    ctx->r4 = ADD32(0, 0X239);
    // 0x8009DCAC: jal         0x8003AC7C
    // 0x8009DCB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_22;
    // 0x8009DCB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x8009DCB4: b           L_8009DF2C
    // 0x8009DCB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DF2C;
    // 0x8009DCB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DCBC:
    // 0x8009DCBC: b           L_8009DF28
    // 0x8009DCC0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
        goto L_8009DF28;
    // 0x8009DCC0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_8009DCC4:
    // 0x8009DCC4: sb          $t3, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r11;
    // 0x8009DCC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DCCC: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
    // 0x8009DCD0: addiu       $a0, $zero, 0x234
    ctx->r4 = ADD32(0, 0X234);
    // 0x8009DCD4: jal         0x8003AC7C
    // 0x8009DCD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_23;
    // 0x8009DCD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x8009DCDC: b           L_8009DF2C
    // 0x8009DCE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DF2C;
    // 0x8009DCE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DCE4:
    // 0x8009DCE4: jal         0x8009D7B0
    // 0x8009DCE8: nop

    handle_menu_joystick_input(rdram, ctx);
        goto after_24;
    // 0x8009DCE8: nop

    after_24:
    // 0x8009DCEC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8009DCF0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8009DCF4: andi        $t5, $t4, 0x4000
    ctx->r13 = ctx->r12 & 0X4000;
    // 0x8009DCF8: beq         $t5, $zero, L_8009DD30
    if (ctx->r13 == 0) {
        // 0x8009DCFC: andi        $t8, $t7, 0x8000
        ctx->r24 = ctx->r15 & 0X8000;
            goto L_8009DD30;
    }
    // 0x8009DCFC: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8009DD00: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009DD04: jal         0x80001D04
    // 0x8009DD08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_25;
    // 0x8009DD08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x8009DD0C: addiu       $a0, $zero, 0x238
    ctx->r4 = ADD32(0, 0X238);
    // 0x8009DD10: jal         0x8003AC7C
    // 0x8009DD14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_26;
    // 0x8009DD14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x8009DD18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009DD1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DD20: sb          $t6, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r14;
    // 0x8009DD24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DD28: b           L_8009DF28
    // 0x8009DD2C: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
        goto L_8009DF28;
    // 0x8009DD2C: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
L_8009DD30:
    // 0x8009DD30: beq         $t8, $zero, L_8009DF28
    if (ctx->r24 == 0) {
        // 0x8009DD34: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8009DF28;
    }
    // 0x8009DD34: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009DD38: lb          $v0, 0x6AB6($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AB6);
    // 0x8009DD3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009DD40: beq         $v0, $at, L_8009DD60
    if (ctx->r2 == ctx->r1) {
        // 0x8009DD44: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8009DD60;
    }
    // 0x8009DD44: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009DD48: ori         $t9, $v0, 0x80
    ctx->r25 = ctx->r2 | 0X80;
    // 0x8009DD4C: addiu       $t0, $zero, 0x62
    ctx->r8 = ADD32(0, 0X62);
    // 0x8009DD50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DD54: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8009DD58: b           L_8009DF28
    // 0x8009DD5C: sb          $t0, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r8;
        goto L_8009DF28;
    // 0x8009DD5C: sb          $t0, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r8;
L_8009DD60:
    // 0x8009DD60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DD64: sb          $t1, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r9;
    // 0x8009DD68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DD6C: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
    // 0x8009DD70: addiu       $a0, $zero, 0x238
    ctx->r4 = ADD32(0, 0X238);
    // 0x8009DD74: jal         0x8003AC7C
    // 0x8009DD78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_27;
    // 0x8009DD78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x8009DD7C: b           L_8009DF2C
    // 0x8009DD80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DF2C;
    // 0x8009DD80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DD84:
    // 0x8009DD84: jal         0x8009D7B0
    // 0x8009DD88: nop

    handle_menu_joystick_input(rdram, ctx);
        goto after_28;
    // 0x8009DD88: nop

    after_28:
    // 0x8009DD8C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8009DD90: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009DD94: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
    // 0x8009DD98: bne         $t2, $zero, L_8009DDB8
    if (ctx->r10 != 0) {
        // 0x8009DD9C: andi        $v0, $v1, 0x8000
        ctx->r2 = ctx->r3 & 0X8000;
            goto L_8009DDB8;
    }
    // 0x8009DD9C: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x8009DDA0: beq         $v0, $zero, L_8009DDE8
    if (ctx->r2 == 0) {
        // 0x8009DDA4: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8009DDE8;
    }
    // 0x8009DDA4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009DDA8: lb          $t3, 0x6AB6($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X6AB6);
    // 0x8009DDAC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009DDB0: bne         $t3, $at, L_8009DDE8
    if (ctx->r11 != ctx->r1) {
        // 0x8009DDB4: nop
    
            goto L_8009DDE8;
    }
    // 0x8009DDB4: nop

L_8009DDB8:
    // 0x8009DDB8: jal         0x80001D04
    // 0x8009DDBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_29;
    // 0x8009DDBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x8009DDC0: addiu       $a0, $zero, 0x23A
    ctx->r4 = ADD32(0, 0X23A);
    // 0x8009DDC4: jal         0x8003AC7C
    // 0x8009DDC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_30;
    // 0x8009DDC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x8009DDCC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009DDD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DDD4: sb          $t4, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r12;
    // 0x8009DDD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DDDC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8009DDE0: b           L_8009DF28
    // 0x8009DDE4: sb          $t5, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = ctx->r13;
        goto L_8009DF28;
    // 0x8009DDE4: sb          $t5, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = ctx->r13;
L_8009DDE8:
    // 0x8009DDE8: beq         $v0, $zero, L_8009DF28
    if (ctx->r2 == 0) {
        // 0x8009DDEC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8009DF28;
    }
    // 0x8009DDEC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009DDF0: lb          $t6, 0x6AB6($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X6AB6);
    // 0x8009DDF4: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009DDF8: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x8009DDFC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8009DE00: jal         0x80001D04
    // 0x8009DE04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_31;
    // 0x8009DE04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x8009DE08: addiu       $t8, $zero, 0x63
    ctx->r24 = ADD32(0, 0X63);
    // 0x8009DE0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE10: b           L_8009DF28
    // 0x8009DE14: sb          $t8, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r24;
        goto L_8009DF28;
    // 0x8009DE14: sb          $t8, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r24;
L_8009DE18:
    // 0x8009DE18: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8009DE1C: jal         0x800C3744
    // 0x8009DE20: subu        $a0, $t9, $a1
    ctx->r4 = SUB32(ctx->r25, ctx->r5);
    set_current_text(rdram, ctx);
        goto after_32;
    // 0x8009DE20: subu        $a0, $t9, $a1
    ctx->r4 = SUB32(ctx->r25, ctx->r5);
    after_32:
    // 0x8009DE24: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8009DE28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE2C: b           L_8009DF28
    // 0x8009DE30: sb          $t0, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r8;
        goto L_8009DF28;
    // 0x8009DE30: sb          $t0, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r8;
L_8009DE34:
    // 0x8009DE34: jal         0x800C3744
    // 0x8009DE38: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    set_current_text(rdram, ctx);
        goto after_33;
    // 0x8009DE38: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_33:
    // 0x8009DE3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DE40: sb          $zero, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = 0;
    // 0x8009DE44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE48: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009DE4C: sb          $t1, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r9;
    // 0x8009DE50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE54: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8009DE58: b           L_8009DF28
    // 0x8009DE5C: sb          $t2, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = ctx->r10;
        goto L_8009DF28;
    // 0x8009DE5C: sb          $t2, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = ctx->r10;
L_8009DE60:
    // 0x8009DE60: jal         0x800C3744
    // 0x8009DE64: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    set_current_text(rdram, ctx);
        goto after_34;
    // 0x8009DE64: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_34:
    // 0x8009DE68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DE6C: sb          $zero, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = 0;
    // 0x8009DE70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE74: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x8009DE78: sb          $t3, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r11;
    // 0x8009DE7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE80: b           L_8009DF28
    // 0x8009DE84: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
        goto L_8009DF28;
    // 0x8009DE84: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
L_8009DE88:
    // 0x8009DE88: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8009DE8C: jal         0x800C3744
    // 0x8009DE90: subu        $a0, $t4, $a1
    ctx->r4 = SUB32(ctx->r12, ctx->r5);
    set_current_text(rdram, ctx);
        goto after_35;
    // 0x8009DE90: subu        $a0, $t4, $a1
    ctx->r4 = SUB32(ctx->r12, ctx->r5);
    after_35:
    // 0x8009DE94: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x8009DE98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE9C: sb          $t5, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r13;
    // 0x8009DEA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DEA4: b           L_8009DF28
    // 0x8009DEA8: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
        goto L_8009DF28;
    // 0x8009DEA8: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
L_8009DEAC:
    // 0x8009DEAC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009DEB0: lb          $t6, -0x5A4($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X5A4);
    // 0x8009DEB4: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8009DEB8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8009DEBC: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x8009DEC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DEC4: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8009DEC8: sb          $t9, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r25;
    // 0x8009DECC: jal         0x800C5B80
    // 0x8009DED0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    dialogue_close(rdram, ctx);
        goto after_36;
    // 0x8009DED0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_36:
    // 0x8009DED4: b           L_8009DF2C
    // 0x8009DED8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DF2C;
    // 0x8009DED8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DEDC:
    // 0x8009DEDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DEE0: sb          $zero, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = 0;
    // 0x8009DEE4: jal         0x800C5B80
    // 0x8009DEE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    dialogue_close(rdram, ctx);
        goto after_37;
    // 0x8009DEE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_37:
    // 0x8009DEEC: b           L_8009DF2C
    // 0x8009DEF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DF2C;
    // 0x8009DEF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DEF4:
    // 0x8009DEF4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8009DEF8: bne         $a1, $at, L_8009DF04
    if (ctx->r5 != ctx->r1) {
        // 0x8009DEFC: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8009DF04;
    }
    // 0x8009DEFC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8009DF00: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8009DF04:
    // 0x8009DF04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DF08: sb          $zero, -0x5A0($at)
    MEM_B(-0X5A0, ctx->r1) = 0;
    // 0x8009DF0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DF10: jal         0x800C5B80
    // 0x8009DF14: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    dialogue_close(rdram, ctx);
        goto after_38;
    // 0x8009DF14: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_38:
    // 0x8009DF18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DF1C: sb          $zero, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = 0;
    // 0x8009DF20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DF24: sb          $zero, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = 0;
L_8009DF28:
    // 0x8009DF28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DF2C:
    // 0x8009DF2C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8009DF30: jr          $ra
    // 0x8009DF34: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8009DF34: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void __vsDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AA88: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8000AA8C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x8000AA90: subu        $v1, $t6, $a1
    ctx->r3 = SUB32(ctx->r14, ctx->r5);
    // 0x8000AA94: bltz        $v1, L_8000AAA4
    if (SIGNED(ctx->r3) < 0) {
        // 0x8000AA98: nop
    
            goto L_8000AAA4;
    }
    // 0x8000AA98: nop

    // 0x8000AA9C: jr          $ra
    // 0x8000AAA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000AAA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000AAA4:
    // 0x8000AAA4: jr          $ra
    // 0x8000AAA8: nop

    return;
    // 0x8000AAA8: nop

;}
RECOMP_FUNC void particle_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B285C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B2860: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B2864: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B2868: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B286C: sw          $a1, -0x7DC0($at)
    MEM_W(-0X7DC0, ctx->r1) = ctx->r5;
    // 0x800B2870: lh          $v0, 0x2C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2C);
    // 0x800B2874: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B2878: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B287C: bne         $v0, $at, L_800B2894
    if (ctx->r2 != ctx->r1) {
        // 0x800B2880: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800B2894;
    }
    // 0x800B2880: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B2884: jal         0x800B2C40
    // 0x800B2888: nop

    update_line_particle(rdram, ctx);
        goto after_0;
    // 0x800B2888: nop

    after_0:
    // 0x800B288C: b           L_800B2B90
    // 0x800B2890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800B2B90;
    // 0x800B2890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B2894:
    // 0x800B2894: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x800B2898: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800B289C: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x800B28A0: beq         $t7, $zero, L_800B28D0
    if (ctx->r15 == 0) {
        // 0x800B28A4: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_800B28D0;
    }
    // 0x800B28A4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800B28A8: lw          $t8, -0x7DC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DC0);
    // 0x800B28AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B28B0: blez        $t8, L_800B28CC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B28B4: nop
    
            goto L_800B28CC;
    }
    // 0x800B28B4: nop

    // 0x800B28B8: jal         0x800B351C
    // 0x800B28BC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    update_particle_texture_frame(rdram, ctx);
        goto after_1;
    // 0x800B28BC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x800B28C0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800B28C4: lh          $v0, 0x2C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2C);
    // 0x800B28C8: nop

L_800B28CC:
    // 0x800B28CC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_800B28D0:
    // 0x800B28D0: bne         $a0, $v0, L_800B28EC
    if (ctx->r4 != ctx->r2) {
        // 0x800B28D4: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800B28EC;
    }
    // 0x800B28D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800B28D8: lbu         $t9, 0x75($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X75);
    // 0x800B28DC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800B28E0: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x800B28E4: sb          $t1, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r9;
    // 0x800B28E8: sb          $zero, 0x77($s0)
    MEM_B(0X77, ctx->r16) = 0;
L_800B28EC:
    // 0x800B28EC: beq         $v1, $zero, L_800B290C
    if (ctx->r3 == 0) {
        // 0x800B28F0: nop
    
            goto L_800B290C;
    }
    // 0x800B28F0: nop

    // 0x800B28F4: beq         $v1, $zero, L_800B2980
    if (ctx->r3 == 0) {
        // 0x800B28F8: nop
    
            goto L_800B2980;
    }
    // 0x800B28F8: nop

    // 0x800B28FC: lw          $t2, 0x70($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X70);
    // 0x800B2900: nop

    // 0x800B2904: beq         $t2, $zero, L_800B2980
    if (ctx->r10 == 0) {
        // 0x800B2908: nop
    
            goto L_800B2980;
    }
    // 0x800B2908: nop

L_800B290C:
    // 0x800B290C: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x800B2910: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B2914: bne         $v0, $at, L_800B2930
    if (ctx->r2 != ctx->r1) {
        // 0x800B2918: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800B2930;
    }
    // 0x800B2918: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B291C: jal         0x800B38B8
    // 0x800B2920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_particle_with_acceleration(rdram, ctx);
        goto after_2;
    // 0x800B2920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800B2924: b           L_800B2984
    // 0x800B2928: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
        goto L_800B2984;
    // 0x800B2928: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
    // 0x800B292C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800B2930:
    // 0x800B2930: bne         $v0, $at, L_800B2948
    if (ctx->r2 != ctx->r1) {
        // 0x800B2934: nop
    
            goto L_800B2948;
    }
    // 0x800B2934: nop

    // 0x800B2938: jal         0x800B37A0
    // 0x800B293C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_particle_attached_to_parent(rdram, ctx);
        goto after_3;
    // 0x800B293C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800B2940: b           L_800B2984
    // 0x800B2944: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
        goto L_800B2984;
    // 0x800B2944: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_800B2948:
    // 0x800B2948: bne         $a0, $v0, L_800B2960
    if (ctx->r4 != ctx->r2) {
        // 0x800B294C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800B2960;
    }
    // 0x800B294C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800B2950: jal         0x800B36A0
    // 0x800B2954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_particle_basic_parent(rdram, ctx);
        goto after_4;
    // 0x800B2954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800B2958: b           L_800B2984
    // 0x800B295C: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
        goto L_800B2984;
    // 0x800B295C: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_800B2960:
    // 0x800B2960: bne         $v0, $at, L_800B2978
    if (ctx->r2 != ctx->r1) {
        // 0x800B2964: nop
    
            goto L_800B2978;
    }
    // 0x800B2964: nop

    // 0x800B2968: jal         0x800B3AC4
    // 0x800B296C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_particle_forward(rdram, ctx);
        goto after_5;
    // 0x800B296C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800B2970: b           L_800B2984
    // 0x800B2974: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
        goto L_800B2984;
    // 0x800B2974: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_800B2978:
    // 0x800B2978: jal         0x800B3A10
    // 0x800B297C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_particle_basic(rdram, ctx);
        goto after_6;
    // 0x800B297C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_800B2980:
    // 0x800B2980: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_800B2984:
    // 0x800B2984: jal         0x8002A31C
    // 0x800B2988: nop

    block_boundbox(rdram, ctx);
        goto after_7;
    // 0x800B2988: nop

    after_7:
    // 0x800B298C: beq         $v0, $zero, L_800B2A84
    if (ctx->r2 == 0) {
        // 0x800B2990: nop
    
            goto L_800B2A84;
    }
    // 0x800B2990: nop

    // 0x800B2994: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800B2998: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B299C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800B29A0: nop

    // 0x800B29A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B29A8: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x800B29AC: nop

    // 0x800B29B0: bc1t        L_800B2A6C
    if (c1cs) {
        // 0x800B29B4: nop
    
            goto L_800B2A6C;
    }
    // 0x800B29B4: nop

    // 0x800B29B8: lh          $t4, 0x6($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X6);
    // 0x800B29BC: nop

    // 0x800B29C0: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800B29C4: nop

    // 0x800B29C8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B29CC: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x800B29D0: nop

    // 0x800B29D4: bc1t        L_800B2A6C
    if (c1cs) {
        // 0x800B29D8: nop
    
            goto L_800B2A6C;
    }
    // 0x800B29D8: nop

    // 0x800B29DC: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x800B29E0: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B29E4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800B29E8: nop

    // 0x800B29EC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B29F0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800B29F4: nop

    // 0x800B29F8: bc1t        L_800B2A6C
    if (c1cs) {
        // 0x800B29FC: nop
    
            goto L_800B2A6C;
    }
    // 0x800B29FC: nop

    // 0x800B2A00: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x800B2A04: nop

    // 0x800B2A08: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B2A0C: nop

    // 0x800B2A10: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B2A14: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800B2A18: nop

    // 0x800B2A1C: bc1t        L_800B2A6C
    if (c1cs) {
        // 0x800B2A20: nop
    
            goto L_800B2A6C;
    }
    // 0x800B2A20: nop

    // 0x800B2A24: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x800B2A28: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B2A2C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B2A30: nop

    // 0x800B2A34: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B2A38: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800B2A3C: nop

    // 0x800B2A40: bc1t        L_800B2A6C
    if (c1cs) {
        // 0x800B2A44: nop
    
            goto L_800B2A6C;
    }
    // 0x800B2A44: nop

    // 0x800B2A48: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x800B2A4C: nop

    // 0x800B2A50: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800B2A54: nop

    // 0x800B2A58: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B2A5C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x800B2A60: nop

    // 0x800B2A64: bc1f        L_800B2A9C
    if (!c1cs) {
        // 0x800B2A68: nop
    
            goto L_800B2A9C;
    }
    // 0x800B2A68: nop

L_800B2A6C:
    // 0x800B2A6C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B2A70: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B2A74: jal         0x80029F58
    // 0x800B2A78: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_8;
    // 0x800B2A78: nop

    after_8:
    // 0x800B2A7C: b           L_800B2A9C
    // 0x800B2A80: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
        goto L_800B2A9C;
    // 0x800B2A80: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
L_800B2A84:
    // 0x800B2A84: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B2A88: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B2A8C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B2A90: jal         0x80029F58
    // 0x800B2A94: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_9;
    // 0x800B2A94: nop

    after_9:
    // 0x800B2A98: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
L_800B2A9C:
    // 0x800B2A9C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B2AA0: lw          $t9, -0x7DC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DC0);
    // 0x800B2AA4: lh          $t0, 0x3A($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X3A);
    // 0x800B2AA8: nop

    // 0x800B2AAC: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x800B2AB0: sh          $t1, 0x3A($s0)
    MEM_H(0X3A, ctx->r16) = ctx->r9;
    // 0x800B2AB4: lh          $t2, 0x3A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X3A);
    // 0x800B2AB8: nop

    // 0x800B2ABC: bgtz        $t2, L_800B2AD4
    if (SIGNED(ctx->r10) > 0) {
        // 0x800B2AC0: nop
    
            goto L_800B2AD4;
    }
    // 0x800B2AC0: nop

    // 0x800B2AC4: jal         0x8000FFB8
    // 0x800B2AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_10;
    // 0x800B2AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800B2ACC: b           L_800B2B90
    // 0x800B2AD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800B2B90;
    // 0x800B2AD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B2AD4:
    // 0x800B2AD4: lh          $v0, 0x60($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X60);
    // 0x800B2AD8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B2ADC: bne         $v0, $zero, L_800B2B50
    if (ctx->r2 != 0) {
        // 0x800B2AE0: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800B2B50;
    }
    // 0x800B2AE0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B2AE4: lw          $t3, -0x7DC0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7DC0);
    // 0x800B2AE8: lh          $t4, 0x5E($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X5E);
    // 0x800B2AEC: lh          $t6, 0x5C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X5C);
    // 0x800B2AF0: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2AF4: mflo        $t5
    ctx->r13 = lo;
    // 0x800B2AF8: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x800B2AFC: sh          $t7, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r15;
    // 0x800B2B00: lh          $t8, 0x5C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X5C);
    // 0x800B2B04: nop

    // 0x800B2B08: slti        $at, $t8, 0xFF
    ctx->r1 = SIGNED(ctx->r24) < 0XFF ? 1 : 0;
    // 0x800B2B0C: beq         $at, $zero, L_800B2B90
    if (ctx->r1 == 0) {
        // 0x800B2B10: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B2B90;
    }
    // 0x800B2B10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2B14: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x800B2B18: nop

    // 0x800B2B1C: andi        $t9, $t0, 0x1000
    ctx->r25 = ctx->r8 & 0X1000;
    // 0x800B2B20: beq         $t9, $zero, L_800B2B3C
    if (ctx->r25 == 0) {
        // 0x800B2B24: nop
    
            goto L_800B2B3C;
    }
    // 0x800B2B24: nop

    // 0x800B2B28: lh          $t1, 0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6);
    // 0x800B2B2C: nop

    // 0x800B2B30: ori         $t2, $t1, 0x100
    ctx->r10 = ctx->r9 | 0X100;
    // 0x800B2B34: b           L_800B2B8C
    // 0x800B2B38: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
        goto L_800B2B8C;
    // 0x800B2B38: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
L_800B2B3C:
    // 0x800B2B3C: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x800B2B40: nop

    // 0x800B2B44: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x800B2B48: b           L_800B2B8C
    // 0x800B2B4C: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
        goto L_800B2B8C;
    // 0x800B2B4C: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
L_800B2B50:
    // 0x800B2B50: lw          $t6, -0x7DC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DC0);
    // 0x800B2B54: nop

    // 0x800B2B58: subu        $t5, $v0, $t6
    ctx->r13 = SUB32(ctx->r2, ctx->r14);
    // 0x800B2B5C: sh          $t5, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r13;
    // 0x800B2B60: lh          $v0, 0x60($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X60);
    // 0x800B2B64: nop

    // 0x800B2B68: bgez        $v0, L_800B2B90
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B2B6C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B2B90;
    }
    // 0x800B2B6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2B70: lh          $t8, 0x5E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X5E);
    // 0x800B2B74: lh          $t7, 0x5C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X5C);
    // 0x800B2B78: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2B7C: sh          $zero, 0x60($s0)
    MEM_H(0X60, ctx->r16) = 0;
    // 0x800B2B80: mflo        $t0
    ctx->r8 = lo;
    // 0x800B2B84: subu        $t9, $t7, $t0
    ctx->r25 = SUB32(ctx->r15, ctx->r8);
    // 0x800B2B88: sh          $t9, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r25;
L_800B2B8C:
    // 0x800B2B8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B2B90:
    // 0x800B2B90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B2B94: jr          $ra
    // 0x800B2B98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B2B98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void collision_objectmodel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001727C: addiu       $sp, $sp, -0x178
    ctx->r29 = ADD32(ctx->r29, -0X178);
    // 0x80017280: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80017284: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80017288: addiu       $s5, $s5, -0x4C10
    ctx->r21 = ADD32(ctx->r21, -0X4C10);
    // 0x8001728C: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80017290: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80017294: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80017298: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8001729C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800172A0: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800172A4: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800172A8: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800172AC: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800172B0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800172B4: swc1        $f21, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800172B8: swc1        $f20, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f20.u32l;
    // 0x800172BC: sw          $a1, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r5;
    // 0x800172C0: sw          $a3, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r7;
    // 0x800172C4: sw          $zero, 0x160($sp)
    MEM_W(0X160, ctx->r29) = 0;
    // 0x800172C8: sw          $zero, 0x170($sp)
    MEM_W(0X170, ctx->r29) = 0;
    // 0x800172CC: blez        $t6, L_800174BC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800172D0: sw          $a2, 0x180($sp)
        MEM_W(0X180, ctx->r29) = ctx->r6;
            goto L_800174BC;
    }
    // 0x800172D0: sw          $a2, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r6;
    // 0x800172D4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800172D8: sw          $a0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r4;
    // 0x800172DC: sw          $a2, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r6;
    // 0x800172E0: addiu       $s4, $sp, 0x8C
    ctx->r20 = ADD32(ctx->r29, 0X8C);
    // 0x800172E4: addiu       $s3, $sp, 0xB4
    ctx->r19 = ADD32(ctx->r29, 0XB4);
    // 0x800172E8: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
L_800172EC:
    // 0x800172EC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800172F0: lw          $t7, -0x4C14($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C14);
    // 0x800172F4: lw          $a0, 0x178($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X178);
    // 0x800172F8: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800172FC: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80017300: nop

    // 0x80017304: lb          $t2, 0x3A($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X3A);
    // 0x80017308: lw          $t9, 0x68($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X68);
    // 0x8001730C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80017310: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80017314: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80017318: nop

    // 0x8001731C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80017320: nop

    // 0x80017324: sw          $t5, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r13;
    // 0x80017328: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001732C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80017330: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80017334: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80017338: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001733C: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80017340: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80017344: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80017348: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001734C: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80017350: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80017354: sw          $v0, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r2;
    // 0x80017358: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001735C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80017360: jal         0x800CA030
    // 0x80017364: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80017364: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80017368: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001736C: lw          $a0, 0x158($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X158);
    // 0x80017370: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80017374: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80017378: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001737C: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x80017380: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80017384: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x80017388: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8001738C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80017390: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x80017394: beq         $t8, $zero, L_800173A0
    if (ctx->r24 == 0) {
        // 0x80017398: or          $fp, $v0, $zero
        ctx->r30 = ctx->r2 | 0;
            goto L_800173A0;
    }
    // 0x80017398: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x8001739C: sra         $fp, $v0, 3
    ctx->r30 = S32(SIGNED(ctx->r2) >> 3);
L_800173A0:
    // 0x800173A0: slti        $at, $fp, 0x100
    ctx->r1 = SIGNED(ctx->r30) < 0X100 ? 1 : 0;
    // 0x800173A4: bne         $at, $zero, L_800173B0
    if (ctx->r1 != 0) {
        // 0x800173A8: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800173B0;
    }
    // 0x800173A8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800173AC: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
L_800173B0:
    // 0x800173B0: lbu         $t2, 0x13($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X13);
    // 0x800173B4: nop

    // 0x800173B8: slt         $at, $fp, $t2
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800173BC: beq         $at, $zero, L_800173DC
    if (ctx->r1 == 0) {
        // 0x800173C0: lw          $t4, 0x154($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X154);
            goto L_800173DC;
    }
    // 0x800173C0: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x800173C4: sb          $fp, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r30;
    // 0x800173C8: lw          $t3, 0x4C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4C);
    // 0x800173CC: lw          $t9, 0x178($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X178);
    // 0x800173D0: nop

    // 0x800173D4: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800173D8: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
L_800173DC:
    // 0x800173DC: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800173E0: lwc1        $f6, 0x3C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X3C);
    // 0x800173E4: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800173E8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800173EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800173F0: lw          $a1, 0x160($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X160);
    // 0x800173F4: lw          $t5, 0x170($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X170);
    // 0x800173F8: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800173FC: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80017400: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x80017404: addu        $t6, $s3, $v0
    ctx->r14 = ADD32(ctx->r19, ctx->r2);
    // 0x80017408: bc1f        L_80017494
    if (!c1cs) {
        // 0x8001740C: addu        $v1, $s4, $v0
        ctx->r3 = ADD32(ctx->r20, ctx->r2);
            goto L_80017494;
    }
    // 0x8001740C: addu        $v1, $s4, $v0
    ctx->r3 = ADD32(ctx->r20, ctx->r2);
    // 0x80017410: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80017414: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80017418: blez        $a1, L_8001748C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8001741C: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_8001748C;
    }
    // 0x8001741C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80017420: lwc1        $f16, -0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80017424: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80017428: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
    // 0x8001742C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80017430: addu        $v1, $s4, $a0
    ctx->r3 = ADD32(ctx->r20, ctx->r4);
    // 0x80017434: bc1f        L_8001748C
    if (!c1cs) {
        // 0x80017438: nop
    
            goto L_8001748C;
    }
    // 0x80017438: nop

    // 0x8001743C: lwc1        $f0, -0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80017440: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80017444: addu        $v0, $s3, $a0
    ctx->r2 = ADD32(ctx->r19, ctx->r4);
L_80017448:
    // 0x80017448: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8001744C: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x80017450: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80017454: sltu        $at, $v0, $s0
    ctx->r1 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x80017458: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8001745C: swc1        $f2, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f2.u32l;
    // 0x80017460: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80017464: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80017468: bne         $at, $zero, L_8001748C
    if (ctx->r1 != 0) {
        // 0x8001746C: sw          $t7, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r15;
            goto L_8001748C;
    }
    // 0x8001746C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80017470: lwc1        $f0, -0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80017474: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80017478: nop

    // 0x8001747C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80017480: nop

    // 0x80017484: bc1t        L_80017448
    if (c1cs) {
        // 0x80017488: nop
    
            goto L_80017448;
    }
    // 0x80017488: nop

L_8001748C:
    // 0x8001748C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80017490: sw          $a1, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r5;
L_80017494:
    // 0x80017494: lw          $t8, 0x170($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X170);
    // 0x80017498: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x8001749C: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x800174A0: lw          $a1, 0x160($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X160);
    // 0x800174A4: slt         $at, $t2, $t9
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800174A8: bne         $at, $zero, L_800172EC
    if (ctx->r1 != 0) {
        // 0x800174AC: sw          $t2, 0x170($sp)
        MEM_W(0X170, ctx->r29) = ctx->r10;
            goto L_800172EC;
    }
    // 0x800174AC: sw          $t2, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r10;
    // 0x800174B0: lw          $a0, 0x178($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X178);
    // 0x800174B4: sw          $zero, 0x170($sp)
    MEM_W(0X170, ctx->r29) = 0;
    // 0x800174B8: sw          $a1, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r5;
L_800174BC:
    // 0x800174BC: lw          $t3, 0x160($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X160);
    // 0x800174C0: lw          $a2, 0x180($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X180);
    // 0x800174C4: blez        $t3, L_800178A8
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800174C8: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800178A8;
    }
    // 0x800174C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800174CC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800174D0: addiu       $t1, $sp, 0xB4
    ctx->r9 = ADD32(ctx->r29, 0XB4);
    // 0x800174D4: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x800174D8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800174DC: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x800174E0: sw          $a0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r4;
    // 0x800174E4: sw          $a2, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r6;
    // 0x800174E8: sw          $zero, 0x168($sp)
    MEM_W(0X168, ctx->r29) = 0;
L_800174EC:
    // 0x800174EC: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x800174F0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800174F4: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800174F8: lw          $t4, -0x4C14($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4C14);
    // 0x800174FC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80017500: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80017504: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80017508: lw          $a0, 0x178($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X178);
    // 0x8001750C: lb          $t2, 0x3A($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X3A);
    // 0x80017510: lw          $t8, 0x68($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X68);
    // 0x80017514: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x80017518: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x8001751C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80017520: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80017524: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80017528: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001752C: sw          $t5, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r13;
    // 0x80017530: lw          $v0, 0x5C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X5C);
    // 0x80017534: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80017538: lbu         $t4, 0x104($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X104);
    // 0x8001753C: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x80017540: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80017544: andi        $t2, $t6, 0x1
    ctx->r10 = ctx->r14 & 0X1;
    // 0x80017548: sll         $t8, $t2, 6
    ctx->r24 = S32(ctx->r10 << 6);
    // 0x8001754C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80017550: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x80017554: jal         0x80017940
    // 0x80017558: sw          $a1, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r5;
    func_8001790C(rdram, ctx);
        goto after_1;
    // 0x80017558: sw          $a1, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r5;
    after_1:
    // 0x8001755C: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x80017560: beq         $v0, $zero, L_80017614
    if (ctx->r2 == 0) {
        // 0x80017564: sw          $v0, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r2;
            goto L_80017614;
    }
    // 0x80017564: sw          $v0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r2;
    // 0x80017568: lw          $t3, 0x17C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X17C);
    // 0x8001756C: addiu       $s2, $sp, 0x13C
    ctx->r18 = ADD32(ctx->r29, 0X13C);
    // 0x80017570: blez        $t3, L_80017678
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80017574: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80017678;
    }
    // 0x80017574: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80017578: lw          $s1, 0x188($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X188);
    // 0x8001757C: addiu       $s3, $sp, 0x12C
    ctx->r19 = ADD32(ctx->r29, 0X12C);
    // 0x80017580: addiu       $s4, $sp, 0x11C
    ctx->r20 = ADD32(ctx->r29, 0X11C);
    // 0x80017584: addiu       $s5, $sp, 0x100
    ctx->r21 = ADD32(ctx->r29, 0X100);
    // 0x80017588: addiu       $s6, $sp, 0xF0
    ctx->r22 = ADD32(ctx->r29, 0XF0);
    // 0x8001758C: addiu       $s7, $sp, 0xE0
    ctx->r23 = ADD32(ctx->r29, 0XE0);
L_80017590:
    // 0x80017590: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80017594: nop

    // 0x80017598: swc1        $f6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f6.u32l;
    // 0x8001759C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800175A0: nop

    // 0x800175A4: swc1        $f8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f8.u32l;
    // 0x800175A8: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800175AC: nop

    // 0x800175B0: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
    // 0x800175B4: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x800175B8: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x800175BC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800175C0: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800175C4: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x800175C8: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x800175CC: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x800175D0: jal         0x8006F88C
    // 0x800175D4: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    mtxf_transform_point(rdram, ctx);
        goto after_2;
    // 0x800175D4: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_2:
    // 0x800175D8: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800175DC: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800175E0: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x800175E4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800175E8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800175EC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800175F0: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800175F4: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800175F8: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x800175FC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80017600: bne         $fp, $t5, L_80017590
    if (ctx->r30 != ctx->r13) {
        // 0x80017604: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80017590;
    }
    // 0x80017604: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80017608: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001760C: b           L_80017678
    // 0x80017610: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
        goto L_80017678;
    // 0x80017610: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_80017614:
    // 0x80017614: lw          $t4, 0x17C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X17C);
    // 0x80017618: addiu       $s2, $sp, 0x13C
    ctx->r18 = ADD32(ctx->r29, 0X13C);
    // 0x8001761C: blez        $t4, L_80017678
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80017620: addiu       $s3, $sp, 0x12C
        ctx->r19 = ADD32(ctx->r29, 0X12C);
            goto L_80017678;
    }
    // 0x80017620: addiu       $s3, $sp, 0x12C
    ctx->r19 = ADD32(ctx->r29, 0X12C);
    // 0x80017624: lw          $s0, 0x184($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X184);
    // 0x80017628: addiu       $s4, $sp, 0x11C
    ctx->r20 = ADD32(ctx->r29, 0X11C);
L_8001762C:
    // 0x8001762C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80017630: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80017634: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x80017638: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x8001763C: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x80017640: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80017644: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80017648: jal         0x8006F88C
    // 0x8001764C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    mtxf_transform_point(rdram, ctx);
        goto after_3;
    // 0x8001764C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_3:
    // 0x80017650: lw          $t6, 0x17C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X17C);
    // 0x80017654: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80017658: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x8001765C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80017660: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80017664: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80017668: bne         $fp, $t6, L_8001762C
    if (ctx->r30 != ctx->r14) {
        // 0x8001766C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8001762C;
    }
    // 0x8001766C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80017670: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80017674: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_80017678:
    // 0x80017678: lw          $t7, 0x17C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X17C);
    // 0x8001767C: addiu       $s5, $sp, 0x100
    ctx->r21 = ADD32(ctx->r29, 0X100);
    // 0x80017680: blez        $t7, L_800176D8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80017684: addiu       $s6, $sp, 0xF0
        ctx->r22 = ADD32(ctx->r29, 0XF0);
            goto L_800176D8;
    }
    // 0x80017684: addiu       $s6, $sp, 0xF0
    ctx->r22 = ADD32(ctx->r29, 0XF0);
    // 0x80017688: lw          $s1, 0x188($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X188);
    // 0x8001768C: addiu       $s7, $sp, 0xE0
    ctx->r23 = ADD32(ctx->r29, 0XE0);
L_80017690:
    // 0x80017690: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80017694: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80017698: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x8001769C: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800176A0: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x800176A4: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x800176A8: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x800176AC: jal         0x8006F88C
    // 0x800176B0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    mtxf_transform_point(rdram, ctx);
        goto after_4;
    // 0x800176B0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_4:
    // 0x800176B4: lw          $t2, 0x17C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X17C);
    // 0x800176B8: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800176BC: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x800176C0: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800176C4: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800176C8: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x800176CC: bne         $fp, $t2, L_80017690
    if (ctx->r30 != ctx->r10) {
        // 0x800176D0: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80017690;
    }
    // 0x800176D0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800176D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800176D8:
    // 0x800176D8: lw          $a2, 0x180($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X180);
    // 0x800176DC: addiu       $t8, $sp, 0x12C
    ctx->r24 = ADD32(ctx->r29, 0X12C);
    // 0x800176E0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800176E4: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x800176E8: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800176EC: lw          $t2, 0x158($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X158);
    // 0x800176F0: addiu       $t9, $sp, 0x11C
    ctx->r25 = ADD32(ctx->r29, 0X11C);
    // 0x800176F4: addiu       $t3, $sp, 0x100
    ctx->r11 = ADD32(ctx->r29, 0X100);
    // 0x800176F8: addiu       $t5, $sp, 0xF0
    ctx->r13 = ADD32(ctx->r29, 0XF0);
    // 0x800176FC: addiu       $t4, $sp, 0xE0
    ctx->r12 = ADD32(ctx->r29, 0XE0);
    // 0x80017700: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80017704: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80017708: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8001770C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80017710: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80017714: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80017718: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8001771C: lwc1        $f10, 0x8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80017720: lw          $a1, 0x17C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X17C);
    // 0x80017724: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80017728: nop

    // 0x8001772C: div.d       $f18, $f20, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f20.d, ctx->f16.d);
    // 0x80017730: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x80017734: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x80017738: addiu       $a3, $sp, 0x13C
    ctx->r7 = ADD32(ctx->r29, 0X13C);
    // 0x8001773C: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80017740: jal         0x80017A4C
    // 0x80017744: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_80017A18(rdram, ctx);
        goto after_5;
    // 0x80017744: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80017748: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x8001774C: beq         $v0, $zero, L_80017768
    if (ctx->r2 == 0) {
        // 0x80017750: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80017768;
    }
    // 0x80017750: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80017754: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x80017758: lw          $t8, 0x178($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X178);
    // 0x8001775C: lw          $t9, 0x5C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X5C);
    // 0x80017760: nop

    // 0x80017764: sw          $t8, 0x100($t9)
    MEM_W(0X100, ctx->r25) = ctx->r24;
L_80017768:
    // 0x80017768: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001776C: lb          $t3, -0x4D5C($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X4D5C);
    // 0x80017770: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x80017774: bne         $t3, $zero, L_80017794
    if (ctx->r11 != 0) {
        // 0x80017778: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_80017794;
    }
    // 0x80017778: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8001777C: lw          $a0, 0x178($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X178);
    // 0x80017780: jal         0x800179AC
    // 0x80017784: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    func_80017978(rdram, ctx);
        goto after_6;
    // 0x80017784: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    after_6:
    // 0x80017788: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x8001778C: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x80017790: sw          $v0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r2;
L_80017794:
    // 0x80017794: lw          $v0, 0x5C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X5C);
    // 0x80017798: lw          $t8, 0x17C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X17C);
    // 0x8001779C: lbu         $t5, 0x104($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X104);
    // 0x800177A0: nop

    // 0x800177A4: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x800177A8: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x800177AC: addu        $t2, $v0, $t7
    ctx->r10 = ADD32(ctx->r2, ctx->r15);
    // 0x800177B0: blez        $t8, L_80017874
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800177B4: sw          $t2, 0xDC($sp)
        MEM_W(0XDC, ctx->r29) = ctx->r10;
            goto L_80017874;
    }
    // 0x800177B4: sw          $t2, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r10;
L_800177B8:
    // 0x800177B8: lw          $t9, 0x14C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14C);
    // 0x800177BC: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x800177C0: beq         $t9, $zero, L_800177F8
    if (ctx->r25 == 0) {
        // 0x800177C4: and         $t7, $s2, $t0
        ctx->r15 = ctx->r18 & ctx->r8;
            goto L_800177F8;
    }
    // 0x800177C4: and         $t7, $s2, $t0
    ctx->r15 = ctx->r18 & ctx->r8;
    // 0x800177C8: sll         $v0, $fp, 2
    ctx->r2 = S32(ctx->r30 << 2);
    // 0x800177CC: addu        $t5, $sp, $v0
    ctx->r13 = ADD32(ctx->r29, ctx->r2);
    // 0x800177D0: lwc1        $f8, 0x100($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X100);
    // 0x800177D4: addu        $s0, $t9, $t3
    ctx->r16 = ADD32(ctx->r25, ctx->r11);
    // 0x800177D8: addu        $t4, $sp, $v0
    ctx->r12 = ADD32(ctx->r29, ctx->r2);
    // 0x800177DC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x800177E0: lwc1        $f4, 0xF0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XF0);
    // 0x800177E4: addu        $t6, $sp, $v0
    ctx->r14 = ADD32(ctx->r29, ctx->r2);
    // 0x800177E8: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x800177EC: lwc1        $f10, 0xE0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XE0);
    // 0x800177F0: nop

    // 0x800177F4: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
L_800177F8:
    // 0x800177F8: beq         $t7, $zero, L_8001785C
    if (ctx->r15 == 0) {
        // 0x800177FC: sll         $v0, $fp, 2
        ctx->r2 = S32(ctx->r30 << 2);
            goto L_8001785C;
    }
    // 0x800177FC: sll         $v0, $fp, 2
    ctx->r2 = S32(ctx->r30 << 2);
    // 0x80017800: addu        $t2, $sp, $v0
    ctx->r10 = ADD32(ctx->r29, ctx->r2);
    // 0x80017804: addu        $t8, $sp, $v0
    ctx->r24 = ADD32(ctx->r29, ctx->r2);
    // 0x80017808: addu        $t9, $sp, $v0
    ctx->r25 = ADD32(ctx->r29, ctx->r2);
    // 0x8001780C: lw          $v1, 0x188($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X188);
    // 0x80017810: lw          $a3, 0xE0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0XE0);
    // 0x80017814: lw          $a2, 0xF0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0XF0);
    // 0x80017818: lw          $a1, 0x100($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X100);
    // 0x8001781C: addiu       $t2, $s1, 0x2
    ctx->r10 = ADD32(ctx->r17, 0X2);
    // 0x80017820: addiu       $t4, $s1, 0x1
    ctx->r12 = ADD32(ctx->r17, 0X1);
    // 0x80017824: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80017828: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8001782C: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80017830: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x80017834: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x80017838: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8001783C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80017840: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80017844: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80017848: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8001784C: jal         0x8006F88C
    // 0x80017850: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    mtxf_transform_point(rdram, ctx);
        goto after_7;
    // 0x80017850: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    after_7:
    // 0x80017854: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x80017858: nop

L_8001785C:
    // 0x8001785C: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x80017860: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80017864: sll         $t3, $t0, 1
    ctx->r11 = S32(ctx->r8 << 1);
    // 0x80017868: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
    // 0x8001786C: bne         $fp, $t5, L_800177B8
    if (ctx->r30 != ctx->r13) {
        // 0x80017870: addiu       $s1, $s1, 0x3
        ctx->r17 = ADD32(ctx->r17, 0X3);
            goto L_800177B8;
    }
    // 0x80017870: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
L_80017874:
    // 0x80017874: lw          $t4, 0x168($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X168);
    // 0x80017878: lw          $t7, 0x170($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X170);
    // 0x8001787C: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x80017880: lw          $t3, 0x160($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X160);
    // 0x80017884: or          $t6, $t4, $s2
    ctx->r14 = ctx->r12 | ctx->r18;
    // 0x80017888: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x8001788C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x80017890: sw          $t6, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r14;
    // 0x80017894: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
    // 0x80017898: bne         $t2, $t3, L_800174EC
    if (ctx->r10 != ctx->r11) {
        // 0x8001789C: sw          $t2, 0x170($sp)
        MEM_W(0X170, ctx->r29) = ctx->r10;
            goto L_800174EC;
    }
    // 0x8001789C: sw          $t2, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r10;
    // 0x800178A0: lw          $a2, 0x180($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X180);
    // 0x800178A4: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
L_800178A8:
    // 0x800178A8: andi        $t5, $a3, 0x1
    ctx->r13 = ctx->r7 & 0X1;
    // 0x800178AC: beq         $t5, $zero, L_800178BC
    if (ctx->r13 == 0) {
        // 0x800178B0: sw          $zero, 0x0($a2)
        MEM_W(0X0, ctx->r6) = 0;
            goto L_800178BC;
    }
    // 0x800178B0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800178B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800178B8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_800178BC:
    // 0x800178BC: andi        $t8, $a3, 0x2
    ctx->r24 = ctx->r7 & 0X2;
    // 0x800178C0: beq         $t8, $zero, L_800178D8
    if (ctx->r24 == 0) {
        // 0x800178C4: andi        $t3, $a3, 0x4
        ctx->r11 = ctx->r7 & 0X4;
            goto L_800178D8;
    }
    // 0x800178C4: andi        $t3, $a3, 0x4
    ctx->r11 = ctx->r7 & 0X4;
    // 0x800178C8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800178CC: nop

    // 0x800178D0: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x800178D4: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
L_800178D8:
    // 0x800178D8: beq         $t3, $zero, L_800178F0
    if (ctx->r11 == 0) {
        // 0x800178DC: andi        $t4, $a3, 0x8
        ctx->r12 = ctx->r7 & 0X8;
            goto L_800178F0;
    }
    // 0x800178DC: andi        $t4, $a3, 0x8
    ctx->r12 = ctx->r7 & 0X8;
    // 0x800178E0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800178E4: nop

    // 0x800178E8: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x800178EC: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
L_800178F0:
    // 0x800178F0: beq         $t4, $zero, L_80017908
    if (ctx->r12 == 0) {
        // 0x800178F4: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_80017908;
    }
    // 0x800178F4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800178F8: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800178FC: nop

    // 0x80017900: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80017904: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_80017908:
    // 0x80017908: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8001790C: lwc1        $f21, 0x38($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80017910: lwc1        $f20, 0x3C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80017914: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80017918: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8001791C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80017920: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80017924: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80017928: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8001792C: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80017930: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80017934: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80017938: jr          $ra
    // 0x8001793C: addiu       $sp, $sp, 0x178
    ctx->r29 = ADD32(ctx->r29, 0X178);
    return;
    // 0x8001793C: addiu       $sp, $sp, 0x178
    ctx->r29 = ADD32(ctx->r29, 0X178);
;}
RECOMP_FUNC void viewport_scissor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067C7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067C84: jal         0x8007A970
    // 0x80067C88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80067C88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80067C8C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80067C90: lw          $v1, 0x1260($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1260);
    // 0x80067C94: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80067C98: beq         $v1, $zero, L_80067ED8
    if (ctx->r3 == 0) {
        // 0x80067C9C: andi        $t7, $v0, 0xFFFF
        ctx->r15 = ctx->r2 & 0XFFFF;
            goto L_80067ED8;
    }
    // 0x80067C9C: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x80067CA0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80067CA4: bne         $v1, $t2, L_80067CB0
    if (ctx->r3 != ctx->r10) {
        // 0x80067CA8: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80067CB0;
    }
    // 0x80067CA8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80067CAC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80067CB0:
    // 0x80067CB0: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80067CB4: andi        $a3, $a0, 0xFFFF
    ctx->r7 = ctx->r4 & 0XFFFF;
    // 0x80067CB8: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80067CBC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80067CC0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80067CC4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80067CC8: beq         $v1, $t3, L_80067CEC
    if (ctx->r3 == ctx->r11) {
        // 0x80067CCC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80067CEC;
    }
    // 0x80067CCC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80067CD0: beq         $v1, $t2, L_80067D1C
    if (ctx->r3 == ctx->r10) {
        // 0x80067CD4: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80067D1C;
    }
    // 0x80067CD4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80067CD8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80067CDC: beq         $v1, $t4, L_80067D48
    if (ctx->r3 == ctx->r12) {
        // 0x80067CE0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80067D48;
    }
    // 0x80067CE0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80067CE4: b           L_80067DE4
    // 0x80067CE8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
        goto L_80067DE4;
    // 0x80067CE8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_80067CEC:
    // 0x80067CEC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80067CF0: lw          $t7, 0x1264($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1264);
    // 0x80067CF4: sra         $v0, $a0, 7
    ctx->r2 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067CF8: bne         $t7, $zero, L_80067D10
    if (ctx->r15 != 0) {
        // 0x80067CFC: sra         $t6, $a0, 1
        ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
            goto L_80067D10;
    }
    // 0x80067CFC: sra         $t6, $a0, 1
    ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067D00: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067D04: sra         $t9, $a0, 7
    ctx->r25 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067D08: b           L_80067DE0
    // 0x80067D0C: subu        $a3, $t8, $t9
    ctx->r7 = SUB32(ctx->r24, ctx->r25);
        goto L_80067DE0;
    // 0x80067D0C: subu        $a3, $t8, $t9
    ctx->r7 = SUB32(ctx->r24, ctx->r25);
L_80067D10:
    // 0x80067D10: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x80067D14: b           L_80067DE0
    // 0x80067D18: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
        goto L_80067DE0;
    // 0x80067D18: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
L_80067D1C:
    // 0x80067D1C: lw          $t7, 0x1264($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1264);
    // 0x80067D20: sra         $v1, $a1, 8
    ctx->r3 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067D24: bne         $t7, $zero, L_80067D3C
    if (ctx->r15 != 0) {
        // 0x80067D28: sra         $t6, $a1, 1
        ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80067D3C;
    }
    // 0x80067D28: sra         $t6, $a1, 1
    ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067D2C: sra         $t8, $a1, 1
    ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067D30: sra         $t9, $a1, 8
    ctx->r25 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067D34: b           L_80067DE0
    // 0x80067D38: subu        $a2, $t8, $t9
    ctx->r6 = SUB32(ctx->r24, ctx->r25);
        goto L_80067DE0;
    // 0x80067D38: subu        $a2, $t8, $t9
    ctx->r6 = SUB32(ctx->r24, ctx->r25);
L_80067D3C:
    // 0x80067D3C: addu        $t0, $t6, $v1
    ctx->r8 = ADD32(ctx->r14, ctx->r3);
    // 0x80067D40: b           L_80067DE0
    // 0x80067D44: subu        $a2, $a1, $v1
    ctx->r6 = SUB32(ctx->r5, ctx->r3);
        goto L_80067DE0;
    // 0x80067D44: subu        $a2, $a1, $v1
    ctx->r6 = SUB32(ctx->r5, ctx->r3);
L_80067D48:
    // 0x80067D48: lw          $v0, 0x1264($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1264);
    // 0x80067D4C: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067D50: beq         $v0, $zero, L_80067D78
    if (ctx->r2 == 0) {
        // 0x80067D54: sra         $t8, $a1, 8
        ctx->r24 = S32(SIGNED(ctx->r5) >> 8);
            goto L_80067D78;
    }
    // 0x80067D54: sra         $t8, $a1, 8
    ctx->r24 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067D58: beq         $v0, $t3, L_80067D8C
    if (ctx->r2 == ctx->r11) {
        // 0x80067D5C: sra         $v1, $a1, 8
        ctx->r3 = S32(SIGNED(ctx->r5) >> 8);
            goto L_80067D8C;
    }
    // 0x80067D5C: sra         $v1, $a1, 8
    ctx->r3 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067D60: beq         $v0, $t2, L_80067DA8
    if (ctx->r2 == ctx->r10) {
        // 0x80067D64: sra         $t6, $a0, 1
        ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
            goto L_80067DA8;
    }
    // 0x80067D64: sra         $t6, $a0, 1
    ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067D68: beq         $v0, $t4, L_80067DC4
    if (ctx->r2 == ctx->r12) {
        // 0x80067D6C: sra         $v1, $a1, 8
        ctx->r3 = S32(SIGNED(ctx->r5) >> 8);
            goto L_80067DC4;
    }
    // 0x80067D6C: sra         $v1, $a1, 8
    ctx->r3 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067D70: b           L_80067DE4
    // 0x80067D74: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
        goto L_80067DE4;
    // 0x80067D74: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_80067D78:
    // 0x80067D78: sra         $t9, $a0, 1
    ctx->r25 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067D7C: sra         $t6, $a0, 7
    ctx->r14 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067D80: subu        $a3, $t9, $t6
    ctx->r7 = SUB32(ctx->r25, ctx->r14);
    // 0x80067D84: b           L_80067DE0
    // 0x80067D88: subu        $a2, $t7, $t8
    ctx->r6 = SUB32(ctx->r15, ctx->r24);
        goto L_80067DE0;
    // 0x80067D88: subu        $a2, $t7, $t8
    ctx->r6 = SUB32(ctx->r15, ctx->r24);
L_80067D8C:
    // 0x80067D8C: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067D90: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067D94: sra         $t9, $a0, 7
    ctx->r25 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067D98: addu        $t0, $t7, $v1
    ctx->r8 = ADD32(ctx->r15, ctx->r3);
    // 0x80067D9C: subu        $a2, $a1, $v1
    ctx->r6 = SUB32(ctx->r5, ctx->r3);
    // 0x80067DA0: b           L_80067DE0
    // 0x80067DA4: subu        $a3, $t8, $t9
    ctx->r7 = SUB32(ctx->r24, ctx->r25);
        goto L_80067DE0;
    // 0x80067DA4: subu        $a3, $t8, $t9
    ctx->r7 = SUB32(ctx->r24, ctx->r25);
L_80067DA8:
    // 0x80067DA8: sra         $v0, $a0, 7
    ctx->r2 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067DAC: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067DB0: sra         $t8, $a1, 8
    ctx->r24 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067DB4: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x80067DB8: subu        $a2, $t7, $t8
    ctx->r6 = SUB32(ctx->r15, ctx->r24);
    // 0x80067DBC: b           L_80067DE0
    // 0x80067DC0: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
        goto L_80067DE0;
    // 0x80067DC0: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
L_80067DC4:
    // 0x80067DC4: sra         $v0, $a0, 7
    ctx->r2 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067DC8: sra         $t9, $a1, 1
    ctx->r25 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067DCC: sra         $t6, $a0, 1
    ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067DD0: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x80067DD4: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x80067DD8: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
    // 0x80067DDC: subu        $a2, $a1, $v1
    ctx->r6 = SUB32(ctx->r5, ctx->r3);
L_80067DE0:
    // 0x80067DE0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_80067DE4:
    // 0x80067DE4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80067DE8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80067DEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067DF0: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80067DF4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067DF8: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x80067DFC: nop

    // 0x80067E00: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80067E04: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80067E08: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80067E0C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80067E10: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067E14: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067E18: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80067E1C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80067E20: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x80067E24: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80067E28: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80067E2C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80067E30: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067E34: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80067E38: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80067E3C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80067E40: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067E44: nop

    // 0x80067E48: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067E4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067E50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067E54: nop

    // 0x80067E58: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80067E5C: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x80067E60: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067E64: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80067E68: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80067E6C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80067E70: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80067E74: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80067E78: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80067E7C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80067E80: nop

    // 0x80067E84: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067E88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067E8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067E90: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067E94: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80067E98: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067E9C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067EA0: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80067EA4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80067EA8: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80067EAC: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80067EB0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067EB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067EB8: nop

    // 0x80067EBC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80067EC0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80067EC4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067EC8: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80067ECC: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80067ED0: b           L_80067F6C
    // 0x80067ED4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
        goto L_80067F6C;
    // 0x80067ED4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80067ED8:
    // 0x80067ED8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80067EDC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80067EE0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80067EE4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067EE8: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x80067EEC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80067EF0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80067EF4: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x80067EF8: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x80067EFC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80067F00: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80067F04: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067F08: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067F0C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067F10: nop

    // 0x80067F14: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80067F18: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80067F1C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067F20: sra         $t6, $v0, 16
    ctx->r14 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80067F24: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80067F28: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80067F2C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80067F30: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80067F34: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80067F38: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80067F3C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067F40: nop

    // 0x80067F44: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067F48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067F4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067F50: nop

    // 0x80067F54: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80067F58: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80067F5C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067F60: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80067F64: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80067F68: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80067F6C:
    // 0x80067F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067F70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067F74: jr          $ra
    // 0x80067F78: nop

    return;
    // 0x80067F78: nop

;}
RECOMP_FUNC void menu_credits_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B870: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8009B874: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8009B878: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x8009B87C: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8009B880: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8009B884: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8009B888: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8009B88C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8009B890: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8009B894: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8009B898: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8009B89C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8009B8A0: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8009B8A4: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8009B8A8: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8009B8AC: jal         0x8001E2D0
    // 0x8009B8B0: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8009B8B0: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_0:
    // 0x8009B8B4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8009B8B8: jal         0x8001E2D0
    // 0x8009B8BC: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8009B8BC: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_1:
    // 0x8009B8C0: jal         0x800C7950
    // 0x8009B8C4: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    bgload_tick(rdram, ctx);
        goto after_2;
    // 0x8009B8C4: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    after_2:
    // 0x8009B8C8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009B8CC: lw          $t6, -0x604($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X604);
    // 0x8009B8D0: nop

    // 0x8009B8D4: bne         $t6, $zero, L_8009B8F4
    if (ctx->r14 != 0) {
        // 0x8009B8D8: nop
    
            goto L_8009B8F4;
    }
    // 0x8009B8D8: nop

    // 0x8009B8DC: jal         0x800C06A0
    // 0x8009B8E0: nop

    disable_new_screen_transitions(rdram, ctx);
        goto after_3;
    // 0x8009B8E0: nop

    after_3:
    // 0x8009B8E4: jal         0x800C06F8
    // 0x8009B8E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    transition_begin(rdram, ctx);
        goto after_4;
    // 0x8009B8E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8009B8EC: jal         0x800C0690
    // 0x8009B8F0: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_5;
    // 0x8009B8F0: nop

    after_5:
L_8009B8F4:
    // 0x8009B8F4: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8009B8F8: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8009B8FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B900: bne         $t7, $zero, L_8009B934
    if (ctx->r15 != 0) {
        // 0x8009B904: addiu       $a1, $zero, 0x28
        ctx->r5 = ADD32(0, 0X28);
            goto L_8009B934;
    }
    // 0x8009B904: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8009B908: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009B90C: lw          $t8, 0x6978($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6978);
    // 0x8009B910: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B914: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8009B918: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009B91C: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x8009B920: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x8009B924: jal         0x8009B728
    // 0x8009B928: addiu       $a3, $zero, 0xBA
    ctx->r7 = ADD32(0, 0XBA);
    credits_fade(rdram, ctx);
        goto after_6;
    // 0x8009B928: addiu       $a3, $zero, 0xBA
    ctx->r7 = ADD32(0, 0XBA);
    after_6:
    // 0x8009B92C: b           L_8009B950
    // 0x8009B930: nop

        goto L_8009B950;
    // 0x8009B930: nop

L_8009B934:
    // 0x8009B934: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009B938: lw          $t1, 0x6978($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6978);
    // 0x8009B93C: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x8009B940: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8009B944: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009B948: jal         0x8009B728
    // 0x8009B94C: addiu       $a3, $zero, 0x9C
    ctx->r7 = ADD32(0, 0X9C);
    credits_fade(rdram, ctx);
        goto after_7;
    // 0x8009B94C: addiu       $a3, $zero, 0x9C
    ctx->r7 = ADD32(0, 0X9C);
    after_7:
L_8009B950:
    // 0x8009B950: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009B954: addiu       $a2, $a2, 0x6978
    ctx->r6 = ADD32(ctx->r6, 0X6978);
    // 0x8009B958: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8009B95C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009B960: blez        $v0, L_8009BA68
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009B964: addiu       $v1, $v1, -0x620
        ctx->r3 = ADD32(ctx->r3, -0X620);
            goto L_8009BA68;
    }
    // 0x8009B964: addiu       $v1, $v1, -0x620
    ctx->r3 = ADD32(ctx->r3, -0X620);
    // 0x8009B968: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x8009B96C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8009B970: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x8009B974: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x8009B978: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8009B97C: bne         $at, $zero, L_8009B98C
    if (ctx->r1 != 0) {
        // 0x8009B980: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8009B98C;
    }
    // 0x8009B980: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009B984: b           L_8009B994
    // 0x8009B988: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
        goto L_8009B994;
    // 0x8009B988: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8009B98C:
    // 0x8009B98C: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8009B990: subu        $s4, $t7, $v0
    ctx->r20 = SUB32(ctx->r15, ctx->r2);
L_8009B994:
    // 0x8009B994: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x8009B998: addu        $t8, $t8, $s4
    ctx->r24 = ADD32(ctx->r24, ctx->r20);
    // 0x8009B99C: lw          $s5, 0x0($v1)
    ctx->r21 = MEM_W(ctx->r3, 0X0);
    // 0x8009B9A0: jal         0x8007A970
    // 0x8009B9A4: addiu       $s4, $t8, 0x48
    ctx->r20 = ADD32(ctx->r24, 0X48);
    fb_size(rdram, ctx);
        goto after_8;
    // 0x8009B9A4: addiu       $s4, $t8, 0x48
    ctx->r20 = ADD32(ctx->r24, 0X48);
    after_8:
    // 0x8009B9A8: sra         $s2, $v0, 17
    ctx->r18 = S32(SIGNED(ctx->r2) >> 17);
    // 0x8009B9AC: andi        $t9, $s2, 0x7FFF
    ctx->r25 = ctx->r18 & 0X7FFF;
    // 0x8009B9B0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009B9B4: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8009B9B8: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8009B9BC: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x8009B9C0: addiu       $s6, $s6, 0x1098
    ctx->r22 = ADD32(ctx->r22, 0X1098);
    // 0x8009B9C4: addiu       $s7, $s7, 0x693C
    ctx->r23 = ADD32(ctx->r23, 0X693C);
    // 0x8009B9C8: addiu       $s0, $s0, 0x1070
    ctx->r16 = ADD32(ctx->r16, 0X1070);
L_8009B9CC:
    // 0x8009B9CC: sll         $s1, $s5, 16
    ctx->r17 = S32(ctx->r21 << 16);
    // 0x8009B9D0: sra         $t1, $s1, 16
    ctx->r9 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8009B9D4: sll         $a0, $t1, 16
    ctx->r4 = S32(ctx->r9 << 16);
    // 0x8009B9D8: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8009B9DC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8009B9E0: jal         0x80070A70
    // 0x8009B9E4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    static_3_80070A70(rdram, ctx);
        goto after_9;
    // 0x8009B9E4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    after_9:
    // 0x8009B9E8: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8009B9EC: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8009B9F0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8009B9F4: jal         0x80070A6C
    // 0x8009B9F8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    coss_s16(rdram, ctx);
        goto after_10;
    // 0x8009B9F8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_10:
    // 0x8009B9FC: multu       $s3, $s4
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009BA00: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8009BA04: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009BA08: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009BA0C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009BA10: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009BA14: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8009BA18: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8009BA1C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009BA20: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009BA24: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009BA28: mflo        $a2
    ctx->r6 = lo;
    // 0x8009BA2C: sra         $t3, $a2, 16
    ctx->r11 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8009BA30: addiu       $a2, $t3, 0x8C
    ctx->r6 = ADD32(ctx->r11, 0X8C);
    // 0x8009BA34: multu       $v0, $s4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009BA38: mflo        $t5
    ctx->r13 = lo;
    // 0x8009BA3C: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8009BA40: addu        $a3, $t6, $s2
    ctx->r7 = ADD32(ctx->r14, ctx->r18);
    // 0x8009BA44: jal         0x80078F08
    // 0x8009BA48: addiu       $a3, $a3, -0x14
    ctx->r7 = ADD32(ctx->r7, -0X14);
    texrect_draw(rdram, ctx);
        goto after_11;
    // 0x8009BA48: addiu       $a3, $a3, -0x14
    ctx->r7 = ADD32(ctx->r7, -0X14);
    after_11:
    // 0x8009BA4C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8009BA50: bne         $s0, $s6, L_8009B9CC
    if (ctx->r16 != ctx->r22) {
        // 0x8009BA54: addiu       $s5, $s5, 0x1999
        ctx->r21 = ADD32(ctx->r21, 0X1999);
            goto L_8009B9CC;
    }
    // 0x8009BA54: addiu       $s5, $s5, 0x1999
    ctx->r21 = ADD32(ctx->r21, 0X1999);
    // 0x8009BA58: jal         0x8007B820
    // 0x8009BA5C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    rendermode_reset(rdram, ctx);
        goto after_12;
    // 0x8009BA5C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_12:
    // 0x8009BA60: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009BA64: addiu       $a2, $a2, 0x6978
    ctx->r6 = ADD32(ctx->r6, 0X6978);
L_8009BA68:
    // 0x8009BA68: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009BA6C: lw          $t2, 0x71A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X71A0);
    // 0x8009BA70: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x8009BA74: beq         $t2, $zero, L_8009BA98
    if (ctx->r10 == 0) {
        // 0x8009BA78: nop
    
            goto L_8009BA98;
    }
    // 0x8009BA78: nop

    // 0x8009BA7C: jal         0x8008239C
    // 0x8009BA80: nop

    postrace_render(rdram, ctx);
        goto after_13;
    // 0x8009BA80: nop

    after_13:
    // 0x8009BA84: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8009BA88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BA8C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009BA90: addiu       $a2, $a2, 0x6978
    ctx->r6 = ADD32(ctx->r6, 0X6978);
    // 0x8009BA94: sw          $t4, 0x71A0($at)
    MEM_W(0X71A0, ctx->r1) = ctx->r12;
L_8009BA98:
    // 0x8009BA98: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009BA9C: lw          $t3, 0x7198($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7198);
    // 0x8009BAA0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8009BAA4: bne         $t3, $zero, L_8009BF68
    if (ctx->r11 != 0) {
        // 0x8009BAA8: nop
    
            goto L_8009BF68;
    }
    // 0x8009BAA8: nop

    // 0x8009BAAC: lw          $t5, 0x71A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X71A0);
    // 0x8009BAB0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8009BAB4: bne         $t5, $zero, L_8009BF68
    if (ctx->r13 != 0) {
        // 0x8009BAB8: lui         $s6, 0x8012
        ctx->r22 = S32(0X8012 << 16);
            goto L_8009BF68;
    }
    // 0x8009BAB8: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8009BABC: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8009BAC0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009BAC4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8009BAC8: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8009BACC: addiu       $t0, $t0, 0x1EB8
    ctx->r8 = ADD32(ctx->r8, 0X1EB8);
    // 0x8009BAD0: addiu       $fp, $fp, 0x1D74
    ctx->r30 = ADD32(ctx->r30, 0X1D74);
    // 0x8009BAD4: addiu       $s6, $s6, 0x7184
    ctx->r22 = ADD32(ctx->r22, 0X7184);
    // 0x8009BAD8: addiu       $a3, $zero, 0x6000
    ctx->r7 = ADD32(0, 0X6000);
L_8009BADC:
    // 0x8009BADC: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8009BAE0: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x8009BAE4: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8009BAE8: addu        $t7, $fp, $t6
    ctx->r15 = ADD32(ctx->r30, ctx->r14);
    // 0x8009BAEC: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    // 0x8009BAF0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009BAF4: andi        $v0, $a0, 0xF000
    ctx->r2 = ctx->r4 & 0XF000;
    // 0x8009BAF8: xor         $a2, $a3, $v0
    ctx->r6 = ctx->r7 ^ ctx->r2;
    // 0x8009BAFC: sltiu       $a2, $a2, 0x1
    ctx->r6 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x8009BB00: sll         $t8, $a2, 24
    ctx->r24 = S32(ctx->r6 << 24);
    // 0x8009BB04: beq         $v0, $at, L_8009BB4C
    if (ctx->r2 == ctx->r1) {
        // 0x8009BB08: sra         $a2, $t8, 24
        ctx->r6 = S32(SIGNED(ctx->r24) >> 24);
            goto L_8009BB4C;
    }
    // 0x8009BB08: sra         $a2, $t8, 24
    ctx->r6 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8009BB0C: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x8009BB10: beq         $v0, $at, L_8009BB60
    if (ctx->r2 == ctx->r1) {
        // 0x8009BB14: addiu       $s0, $a1, 0x1
        ctx->r16 = ADD32(ctx->r5, 0X1);
            goto L_8009BB60;
    }
    // 0x8009BB14: addiu       $s0, $a1, 0x1
    ctx->r16 = ADD32(ctx->r5, 0X1);
    // 0x8009BB18: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x8009BB1C: beq         $v0, $at, L_8009BDD0
    if (ctx->r2 == ctx->r1) {
        // 0x8009BB20: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8009BDD0;
    }
    // 0x8009BB20: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009BB24: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x8009BB28: beq         $v0, $at, L_8009BF30
    if (ctx->r2 == ctx->r1) {
        // 0x8009BB2C: addiu       $t3, $a1, 0x1
        ctx->r11 = ADD32(ctx->r5, 0X1);
            goto L_8009BF30;
    }
    // 0x8009BB2C: addiu       $t3, $a1, 0x1
    ctx->r11 = ADD32(ctx->r5, 0X1);
    // 0x8009BB30: addiu       $at, $zero, 0x5000
    ctx->r1 = ADD32(0, 0X5000);
    // 0x8009BB34: beq         $v0, $at, L_8009BF4C
    if (ctx->r2 == ctx->r1) {
        // 0x8009BB38: addiu       $t7, $a1, 0x1
        ctx->r15 = ADD32(ctx->r5, 0X1);
            goto L_8009BF4C;
    }
    // 0x8009BB38: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x8009BB3C: beq         $v0, $a3, L_8009BB64
    if (ctx->r2 == ctx->r7) {
        // 0x8009BB40: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8009BB64;
    }
    // 0x8009BB40: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8009BB44: b           L_8009BF54
    // 0x8009BB48: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
        goto L_8009BF54;
    // 0x8009BB48: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
L_8009BB4C:
    // 0x8009BB4C: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    // 0x8009BB50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BB54: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x8009BB58: b           L_8009BF50
    // 0x8009BB5C: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
        goto L_8009BF50;
    // 0x8009BB5C: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_8009BB60:
    // 0x8009BB60: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
L_8009BB64:
    // 0x8009BB64: ori         $at, $at, 0xFFF
    ctx->r1 = ctx->r1 | 0XFFF;
    // 0x8009BB68: and         $t2, $a0, $at
    ctx->r10 = ctx->r4 & ctx->r1;
    // 0x8009BB6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BB70: sll         $t3, $s0, 1
    ctx->r11 = S32(ctx->r16 << 1);
    // 0x8009BB74: sw          $t2, 0x71A8($at)
    MEM_W(0X71A8, ctx->r1) = ctx->r10;
    // 0x8009BB78: addu        $t5, $fp, $t3
    ctx->r13 = ADD32(ctx->r30, ctx->r11);
    // 0x8009BB7C: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x8009BB80: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009BB84: andi        $t6, $v0, 0xF000
    ctx->r14 = ctx->r2 & 0XF000;
    // 0x8009BB88: sw          $s0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r16;
    // 0x8009BB8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009BB90: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8009BB94: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x8009BB98: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8009BB9C: addiu       $s7, $zero, 0x14
    ctx->r23 = ADD32(0, 0X14);
    // 0x8009BBA0: bne         $t6, $zero, L_8009BBCC
    if (ctx->r14 != 0) {
        // 0x8009BBA4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8009BBCC;
    }
    // 0x8009BBA4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8009BBA8:
    // 0x8009BBA8: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x8009BBAC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8009BBB0: addu        $t1, $fp, $t9
    ctx->r9 = ADD32(ctx->r30, ctx->r25);
    // 0x8009BBB4: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
    // 0x8009BBB8: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
    // 0x8009BBBC: andi        $t2, $v0, 0xF000
    ctx->r10 = ctx->r2 & 0XF000;
    // 0x8009BBC0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8009BBC4: beq         $t2, $zero, L_8009BBA8
    if (ctx->r10 == 0) {
        // 0x8009BBC8: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_8009BBA8;
    }
    // 0x8009BBC8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_8009BBCC:
    // 0x8009BBCC: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8009BBD0: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x8009BBD4: subu        $v1, $a1, $s0
    ctx->r3 = SUB32(ctx->r5, ctx->r16);
    // 0x8009BBD8: bne         $t4, $zero, L_8009BBE8
    if (ctx->r12 != 0) {
        // 0x8009BBDC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8009BBE8;
    }
    // 0x8009BBDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009BBE0: b           L_8009BBEC
    // 0x8009BBE4: addiu       $s2, $zero, 0x86
    ctx->r18 = ADD32(0, 0X86);
        goto L_8009BBEC;
    // 0x8009BBE4: addiu       $s2, $zero, 0x86
    ctx->r18 = ADD32(0, 0X86);
L_8009BBE8:
    // 0x8009BBE8: addiu       $s2, $zero, 0x78
    ctx->r18 = ADD32(0, 0X78);
L_8009BBEC:
    // 0x8009BBEC: bne         $v1, $at, L_8009BC00
    if (ctx->r3 != ctx->r1) {
        // 0x8009BBF0: addiu       $t6, $zero, 0x1E0
        ctx->r14 = ADD32(0, 0X1E0);
            goto L_8009BC00;
    }
    // 0x8009BBF0: addiu       $t6, $zero, 0x1E0
    ctx->r14 = ADD32(0, 0X1E0);
    // 0x8009BBF4: addiu       $s2, $s2, -0xE
    ctx->r18 = ADD32(ctx->r18, -0XE);
    // 0x8009BBF8: b           L_8009BC24
    // 0x8009BBFC: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
        goto L_8009BC24;
    // 0x8009BBFC: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_8009BC00:
    // 0x8009BC00: beq         $a2, $zero, L_8009BC1C
    if (ctx->r6 == 0) {
        // 0x8009BC04: sll         $t5, $v1, 4
        ctx->r13 = S32(ctx->r3 << 4);
            goto L_8009BC1C;
    }
    // 0x8009BC04: sll         $t5, $v1, 4
    ctx->r13 = S32(ctx->r3 << 4);
    // 0x8009BC08: sll         $t3, $v1, 4
    ctx->r11 = S32(ctx->r3 << 4);
    // 0x8009BC0C: subu        $s2, $s2, $t3
    ctx->r18 = SUB32(ctx->r18, ctx->r11);
    // 0x8009BC10: addiu       $s2, $s2, 0x3
    ctx->r18 = ADD32(ctx->r18, 0X3);
    // 0x8009BC14: b           L_8009BC24
    // 0x8009BC18: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
        goto L_8009BC24;
    // 0x8009BC18: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
L_8009BC1C:
    // 0x8009BC1C: subu        $s2, $s2, $t5
    ctx->r18 = SUB32(ctx->r18, ctx->r13);
    // 0x8009BC20: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_8009BC24:
    // 0x8009BC24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009BC28: sh          $t6, 0x20D0($at)
    MEM_H(0X20D0, ctx->r1) = ctx->r14;
    // 0x8009BC2C: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x8009BC30: bne         $v0, $at, L_8009BC48
    if (ctx->r2 != ctx->r1) {
        // 0x8009BC34: addiu       $t8, $zero, -0xA0
        ctx->r24 = ADD32(0, -0XA0);
            goto L_8009BC48;
    }
    // 0x8009BC34: addiu       $t8, $zero, -0xA0
    ctx->r24 = ADD32(0, -0XA0);
    // 0x8009BC38: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x8009BC3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009BC40: b           L_8009BC50
    // 0x8009BC44: sh          $t7, 0x20D8($at)
    MEM_H(0X20D8, ctx->r1) = ctx->r15;
        goto L_8009BC50;
    // 0x8009BC44: sh          $t7, 0x20D8($at)
    MEM_H(0X20D8, ctx->r1) = ctx->r15;
L_8009BC48:
    // 0x8009BC48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009BC4C: sh          $t8, 0x20D8($at)
    MEM_H(0X20D8, ctx->r1) = ctx->r24;
L_8009BC50:
    // 0x8009BC50: slt         $at, $s0, $a1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8009BC54: beq         $at, $zero, L_8009BD60
    if (ctx->r1 == 0) {
        // 0x8009BC58: or          $s4, $s0, $zero
        ctx->r20 = ctx->r16 | 0;
            goto L_8009BD60;
    }
    // 0x8009BC58: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x8009BC5C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009BC60: sll         $t9, $s4, 1
    ctx->r25 = S32(ctx->r20 << 1);
    // 0x8009BC64: addu        $s1, $fp, $t9
    ctx->r17 = ADD32(ctx->r30, ctx->r25);
    // 0x8009BC68: addiu       $s0, $s0, 0x20D0
    ctx->r16 = ADD32(ctx->r16, 0X20D0);
L_8009BC6C:
    // 0x8009BC6C: sh          $s2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r18;
    // 0x8009BC70: sh          $s2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r18;
    // 0x8009BC74: beq         $a2, $zero, L_8009BD04
    if (ctx->r6 == 0) {
        // 0x8009BC78: sh          $s2, 0xA($s0)
        MEM_H(0XA, ctx->r16) = ctx->r18;
            goto L_8009BD04;
    }
    // 0x8009BC78: sh          $s2, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r18;
    // 0x8009BC7C: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    // 0x8009BC80: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8009BC84: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x8009BC88: sb          $zero, 0x11($s0)
    MEM_B(0X11, ctx->r16) = 0;
    // 0x8009BC8C: sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    // 0x8009BC90: sb          $t1, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r9;
    // 0x8009BC94: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x8009BC98: lb          $a0, 0x0($t3)
    ctx->r4 = MEM_B(ctx->r11, 0X0);
    // 0x8009BC9C: sb          $a2, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = ctx->r6;
    // 0x8009BCA0: jal         0x8006C01C
    // 0x8009BCA4: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    level_name(rdram, ctx);
        goto after_14;
    // 0x8009BCA4: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    after_14:
    // 0x8009BCA8: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x8009BCAC: addiu       $v1, $s2, 0xE
    ctx->r3 = ADD32(ctx->r18, 0XE);
    // 0x8009BCB0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009BCB4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8009BCB8: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8009BCBC: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8009BCC0: sh          $v1, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r3;
    // 0x8009BCC4: sh          $v1, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r3;
    // 0x8009BCC8: sh          $v1, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r3;
    // 0x8009BCCC: sb          $zero, 0x31($s0)
    MEM_B(0X31, ctx->r16) = 0;
    // 0x8009BCD0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8009BCD4: lw          $t7, 0x2014($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2014);
    // 0x8009BCD8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009BCDC: lb          $a2, 0x5B($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X5B);
    // 0x8009BCE0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009BCE4: addiu       $t9, $t9, 0x1D74
    ctx->r25 = ADD32(ctx->r25, 0X1D74);
    // 0x8009BCE8: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x8009BCEC: addiu       $t0, $t0, 0x1EB8
    ctx->r8 = ADD32(ctx->r8, 0X1EB8);
    // 0x8009BCF0: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x8009BCF4: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x8009BCF8: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x8009BCFC: b           L_8009BD4C
    // 0x8009BD00: sw          $t7, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->r15;
        goto L_8009BD4C;
    // 0x8009BD00: sw          $t7, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->r15;
L_8009BD04:
    // 0x8009BD04: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009BD08: addiu       $t2, $t2, 0x1D74
    ctx->r10 = ADD32(ctx->r10, 0X1D74);
    // 0x8009BD0C: sll         $t1, $a1, 1
    ctx->r9 = S32(ctx->r5 << 1);
    // 0x8009BD10: andi        $t4, $s3, 0x1
    ctx->r12 = ctx->r19 & 0X1;
    // 0x8009BD14: beq         $t4, $zero, L_8009BD28
    if (ctx->r12 == 0) {
        // 0x8009BD18: addu        $a0, $t1, $t2
        ctx->r4 = ADD32(ctx->r9, ctx->r10);
            goto L_8009BD28;
    }
    // 0x8009BD18: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x8009BD1C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8009BD20: sb          $t3, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r11;
    // 0x8009BD24: sb          $zero, 0xF($s0)
    MEM_B(0XF, ctx->r16) = 0;
L_8009BD28:
    // 0x8009BD28: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x8009BD2C: sb          $s5, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r21;
    // 0x8009BD30: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8009BD34: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8009BD38: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8009BD3C: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8009BD40: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8009BD44: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8009BD48: sw          $t8, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->r24;
L_8009BD4C:
    // 0x8009BD4C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8009BD50: sltu        $at, $s1, $a0
    ctx->r1 = ctx->r17 < ctx->r4 ? 1 : 0;
    // 0x8009BD54: addu        $s2, $s2, $s7
    ctx->r18 = ADD32(ctx->r18, ctx->r23);
    // 0x8009BD58: bne         $at, $zero, L_8009BC6C
    if (ctx->r1 != 0) {
        // 0x8009BD5C: addiu       $s7, $zero, 0x20
        ctx->r23 = ADD32(0, 0X20);
            goto L_8009BC6C;
    }
    // 0x8009BD5C: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
L_8009BD60:
    // 0x8009BD60: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009BD64: addiu       $a0, $a0, 0x20D0
    ctx->r4 = ADD32(ctx->r4, 0X20D0);
    // 0x8009BD68: sll         $t9, $s3, 5
    ctx->r25 = S32(ctx->r19 << 5);
    // 0x8009BD6C: addu        $t1, $a0, $t9
    ctx->r9 = ADD32(ctx->r4, ctx->r25);
    // 0x8009BD70: sw          $zero, 0x14($t1)
    MEM_W(0X14, ctx->r9) = 0;
    // 0x8009BD74: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009BD78: lw          $t2, 0x71A8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X71A8);
    // 0x8009BD7C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8009BD80: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8009BD84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009BD88: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009BD8C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8009BD90: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8009BD94: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009BD98: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009BD9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8009BDA0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8009BDA4: jal         0x800822A4
    // 0x8009BDA8: nop

    postrace_offsets(rdram, ctx);
        goto after_15;
    // 0x8009BDA8: nop

    after_15:
    // 0x8009BDAC: jal         0x8008239C
    // 0x8009BDB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    postrace_render(rdram, ctx);
        goto after_16;
    // 0x8009BDB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x8009BDB4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009BDB8: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8009BDBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BDC0: sw          $t4, 0x71A0($at)
    MEM_W(0X71A0, ctx->r1) = ctx->r12;
    // 0x8009BDC4: addiu       $t0, $t0, 0x1EB8
    ctx->r8 = ADD32(ctx->r8, 0X1EB8);
    // 0x8009BDC8: b           L_8009BF50
    // 0x8009BDCC: addiu       $a3, $zero, 0x6000
    ctx->r7 = ADD32(0, 0X6000);
        goto L_8009BF50;
    // 0x8009BDCC: addiu       $a3, $zero, 0x6000
    ctx->r7 = ADD32(0, 0X6000);
L_8009BDD0:
    // 0x8009BDD0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8009BDD4: ori         $at, $at, 0xFFF
    ctx->r1 = ctx->r1 | 0XFFF;
    // 0x8009BDD8: and         $t3, $a0, $at
    ctx->r11 = ctx->r4 & ctx->r1;
    // 0x8009BDDC: addiu       $s0, $a1, 0x1
    ctx->r16 = ADD32(ctx->r5, 0X1);
    // 0x8009BDE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BDE4: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x8009BDE8: sw          $t3, 0x71A8($at)
    MEM_W(0X71A8, ctx->r1) = ctx->r11;
    // 0x8009BDEC: addu        $t7, $fp, $t6
    ctx->r15 = ADD32(ctx->r30, ctx->r14);
    // 0x8009BDF0: lh          $v0, 0x0($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X0);
    // 0x8009BDF4: sw          $s0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r16;
    // 0x8009BDF8: andi        $t8, $v0, 0xF000
    ctx->r24 = ctx->r2 & 0XF000;
    // 0x8009BDFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009BE00: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8009BE04: bne         $t8, $zero, L_8009BE30
    if (ctx->r24 != 0) {
        // 0x8009BE08: sw          $t9, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r25;
            goto L_8009BE30;
    }
    // 0x8009BE08: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
L_8009BE0C:
    // 0x8009BE0C: addiu       $t1, $a1, 0x1
    ctx->r9 = ADD32(ctx->r5, 0X1);
    // 0x8009BE10: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8009BE14: addu        $t4, $fp, $t2
    ctx->r12 = ADD32(ctx->r30, ctx->r10);
    // 0x8009BE18: lh          $v0, 0x0($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X0);
    // 0x8009BE1C: sw          $t1, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r9;
    // 0x8009BE20: andi        $t3, $v0, 0xF000
    ctx->r11 = ctx->r2 & 0XF000;
    // 0x8009BE24: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8009BE28: beq         $t3, $zero, L_8009BE0C
    if (ctx->r11 == 0) {
        // 0x8009BE2C: or          $a1, $t1, $zero
        ctx->r5 = ctx->r9 | 0;
            goto L_8009BE0C;
    }
    // 0x8009BE2C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_8009BE30:
    // 0x8009BE30: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009BE34: addiu       $v1, $v1, 0x20D0
    ctx->r3 = ADD32(ctx->r3, 0X20D0);
    // 0x8009BE38: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x8009BE3C: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x8009BE40: bne         $v0, $at, L_8009BE50
    if (ctx->r2 != ctx->r1) {
        // 0x8009BE44: sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
            goto L_8009BE50;
    }
    // 0x8009BE44: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x8009BE48: b           L_8009BE58
    // 0x8009BE4C: sh          $a0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r4;
        goto L_8009BE58;
    // 0x8009BE4C: sh          $a0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r4;
L_8009BE50:
    // 0x8009BE50: addiu       $t5, $zero, -0xA0
    ctx->r13 = ADD32(0, -0XA0);
    // 0x8009BE54: sh          $t5, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r13;
L_8009BE58:
    // 0x8009BE58: slt         $at, $s0, $a1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8009BE5C: beq         $at, $zero, L_8009BEB0
    if (ctx->r1 == 0) {
        // 0x8009BE60: or          $s4, $s0, $zero
        ctx->r20 = ctx->r16 | 0;
            goto L_8009BEB0;
    }
    // 0x8009BE60: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x8009BE64: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x8009BE68: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8009BE6C: sll         $t7, $s4, 5
    ctx->r15 = S32(ctx->r20 << 5);
    // 0x8009BE70: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009BE74: addiu       $t2, $t2, 0x20D0
    ctx->r10 = ADD32(ctx->r10, 0X20D0);
    // 0x8009BE78: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x8009BE7C: sll         $t6, $s4, 1
    ctx->r14 = S32(ctx->r20 << 1);
    // 0x8009BE80: addu        $s1, $fp, $t6
    ctx->r17 = ADD32(ctx->r30, ctx->r14);
    // 0x8009BE84: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
L_8009BE88:
    // 0x8009BE88: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x8009BE8C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8009BE90: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8009BE94: addu        $t5, $t0, $t3
    ctx->r13 = ADD32(ctx->r8, ctx->r11);
    // 0x8009BE98: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8009BE9C: slt         $at, $s4, $a1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8009BEA0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8009BEA4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8009BEA8: bne         $at, $zero, L_8009BE88
    if (ctx->r1 != 0) {
        // 0x8009BEAC: sw          $t6, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->r14;
            goto L_8009BE88;
    }
    // 0x8009BEAC: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
L_8009BEB0:
    // 0x8009BEB0: sll         $t7, $s0, 5
    ctx->r15 = S32(ctx->r16 << 5);
    // 0x8009BEB4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009BEB8: lw          $t2, 0x71A8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X71A8);
    // 0x8009BEBC: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x8009BEC0: sll         $t8, $s4, 5
    ctx->r24 = S32(ctx->r20 << 5);
    // 0x8009BEC4: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8009BEC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009BECC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8009BED0: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8009BED4: sw          $zero, 0x2104($at)
    MEM_W(0X2104, ctx->r1) = 0;
    // 0x8009BED8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009BEDC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8009BEE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009BEE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009BEE8: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009BEEC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8009BEF0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8009BEF4: addiu       $a0, $a0, 0x20D0
    ctx->r4 = ADD32(ctx->r4, 0X20D0);
    // 0x8009BEF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8009BEFC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009BF00: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8009BF04: jal         0x800822A4
    // 0x8009BF08: nop

    postrace_offsets(rdram, ctx);
        goto after_17;
    // 0x8009BF08: nop

    after_17:
    // 0x8009BF0C: jal         0x8008239C
    // 0x8009BF10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    postrace_render(rdram, ctx);
        goto after_18;
    // 0x8009BF10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_18:
    // 0x8009BF14: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009BF18: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8009BF1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BF20: sw          $t4, 0x71A0($at)
    MEM_W(0X71A0, ctx->r1) = ctx->r12;
    // 0x8009BF24: addiu       $t0, $t0, 0x1EB8
    ctx->r8 = ADD32(ctx->r8, 0X1EB8);
    // 0x8009BF28: b           L_8009BF50
    // 0x8009BF2C: addiu       $a3, $zero, 0x6000
    ctx->r7 = ADD32(0, 0X6000);
        goto L_8009BF50;
    // 0x8009BF2C: addiu       $a3, $zero, 0x6000
    ctx->r7 = ADD32(0, 0X6000);
L_8009BF30:
    // 0x8009BF30: sw          $t3, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r11;
    // 0x8009BF34: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8009BF38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BF3C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009BF40: sw          $t5, 0x7198($at)
    MEM_W(0X7198, ctx->r1) = ctx->r13;
    // 0x8009BF44: b           L_8009BF50
    // 0x8009BF48: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
        goto L_8009BF50;
    // 0x8009BF48: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
L_8009BF4C:
    // 0x8009BF4C: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
L_8009BF50:
    // 0x8009BF50: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
L_8009BF54:
    // 0x8009BF54: nop

    // 0x8009BF58: beq         $t8, $zero, L_8009BADC
    if (ctx->r24 == 0) {
        // 0x8009BF5C: nop
    
            goto L_8009BADC;
    }
    // 0x8009BF5C: nop

    // 0x8009BF60: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009BF64: addiu       $a2, $a2, 0x6978
    ctx->r6 = ADD32(ctx->r6, 0X6978);
L_8009BF68:
    // 0x8009BF68: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009BF6C: lw          $t9, 0x6964($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6964);
    // 0x8009BF70: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8009BF74: bne         $t9, $zero, L_8009BFA8
    if (ctx->r25 != 0) {
        // 0x8009BF78: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_8009BFA8;
    }
    // 0x8009BF78: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009BF7C: lw          $t1, -0x604($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X604);
    // 0x8009BF80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009BF84: bne         $t1, $zero, L_8009BFA8
    if (ctx->r9 != 0) {
        // 0x8009BF88: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_8009BFA8;
    }
    // 0x8009BF88: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_8009BF8C:
    // 0x8009BF8C: jal         0x8006A794
    // 0x8009BF90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    input_pressed(rdram, ctx);
        goto after_19;
    // 0x8009BF90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8009BF94: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009BF98: bne         $s0, $s1, L_8009BF8C
    if (ctx->r16 != ctx->r17) {
        // 0x8009BF9C: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_8009BF8C;
    }
    // 0x8009BF9C: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x8009BFA0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009BFA4: addiu       $a2, $a2, 0x6978
    ctx->r6 = ADD32(ctx->r6, 0X6978);
L_8009BFA8:
    // 0x8009BFA8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009BFAC: addiu       $s0, $s0, 0x6980
    ctx->r16 = ADD32(ctx->r16, 0X6980);
    // 0x8009BFB0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8009BFB4: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8009BFB8: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x8009BFBC: beq         $at, $zero, L_8009C148
    if (ctx->r1 == 0) {
        // 0x8009BFC0: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8009C148;
    }
    // 0x8009BFC0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8009BFC4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009BFC8: addu        $at, $at, $t2
    gpr jr_addend_8009BFD4 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8009BFCC: lw          $t2, -0x74FC($at)
    ctx->r10 = ADD32(ctx->r1, -0X74FC);
    // 0x8009BFD0: nop

    // 0x8009BFD4: jr          $t2
    // 0x8009BFD8: nop

    switch (jr_addend_8009BFD4 >> 2) {
        case 0: goto L_8009BFDC; break;
        case 1: goto L_8009C01C; break;
        case 2: goto L_8009C04C; break;
        case 3: goto L_8009C08C; break;
        case 4: goto L_8009C0E0; break;
        default: switch_error(__func__, 0x8009BFD4, 0x800E8B04);
    }
    // 0x8009BFD8: nop

L_8009BFDC:
    // 0x8009BFDC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009BFE0: addiu       $v1, $v1, 0x718C
    ctx->r3 = ADD32(ctx->r3, 0X718C);
    // 0x8009BFE4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8009BFE8: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8009BFEC: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8009BFF0: addu        $v0, $t3, $t5
    ctx->r2 = ADD32(ctx->r11, ctx->r13);
    // 0x8009BFF4: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x8009BFF8: lb          $a1, 0x2($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X2);
    // 0x8009BFFC: jal         0x800C79B8
    // 0x8009C000: nop

    bgload_start(rdram, ctx);
        goto after_20;
    // 0x8009C000: nop

    after_20:
    // 0x8009C004: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009C008: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009C00C: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8009C010: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C014: b           L_8009C148
    // 0x8009C018: sw          $t7, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r15;
        goto L_8009C148;
    // 0x8009C018: sw          $t7, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r15;
L_8009C01C:
    // 0x8009C01C: jal         0x800C7940
    // 0x8009C020: nop

    bgload_active(rdram, ctx);
        goto after_21;
    // 0x8009C020: nop

    after_21:
    // 0x8009C024: bne         $v0, $zero, L_8009C148
    if (ctx->r2 != 0) {
        // 0x8009C028: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009C148;
    }
    // 0x8009C028: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009C02C: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8009C030: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8009C034: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x8009C038: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8009C03C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8009C040: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C044: b           L_8009C148
    // 0x8009C048: sw          $zero, 0x7198($at)
    MEM_W(0X7198, ctx->r1) = 0;
        goto L_8009C148;
    // 0x8009C048: sw          $zero, 0x7198($at)
    MEM_W(0X7198, ctx->r1) = 0;
L_8009C04C:
    // 0x8009C04C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009C050: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8009C054: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8009C058: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8009C05C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8009C060: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8009C064: subu        $t4, $t1, $t2
    ctx->r12 = SUB32(ctx->r9, ctx->r10);
    // 0x8009C068: subu        $t6, $t3, $t5
    ctx->r14 = SUB32(ctx->r11, ctx->r13);
    // 0x8009C06C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8009C070: bgtz        $t4, L_8009C148
    if (SIGNED(ctx->r12) > 0) {
        // 0x8009C074: sw          $t6, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r14;
            goto L_8009C148;
    }
    // 0x8009C074: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8009C078: addiu       $t7, $t4, 0x258
    ctx->r15 = ADD32(ctx->r12, 0X258);
    // 0x8009C07C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8009C080: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8009C084: b           L_8009C148
    // 0x8009C088: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_8009C148;
    // 0x8009C088: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_8009C08C:
    // 0x8009C08C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009C090: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8009C094: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8009C098: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x8009C09C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8009C0A0: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x8009C0A4: blez        $v0, L_8009C0C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009C0A8: sw          $t2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r10;
            goto L_8009C0C0;
    }
    // 0x8009C0A8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8009C0AC: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x8009C0B0: nop

    // 0x8009C0B4: subu        $t3, $v0, $t4
    ctx->r11 = SUB32(ctx->r2, ctx->r12);
    // 0x8009C0B8: b           L_8009C0C4
    // 0x8009C0BC: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
        goto L_8009C0C4;
    // 0x8009C0BC: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_8009C0C0:
    // 0x8009C0C0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8009C0C4:
    // 0x8009C0C4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8009C0C8: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x8009C0CC: bgtz        $t5, L_8009C14C
    if (SIGNED(ctx->r13) > 0) {
        // 0x8009C0D0: andi        $t4, $s2, 0x9000
        ctx->r12 = ctx->r18 & 0X9000;
            goto L_8009C14C;
    }
    // 0x8009C0D0: andi        $t4, $s2, 0x9000
    ctx->r12 = ctx->r18 & 0X9000;
    // 0x8009C0D4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009C0D8: b           L_8009C148
    // 0x8009C0DC: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
        goto L_8009C148;
    // 0x8009C0DC: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
L_8009C0E0:
    // 0x8009C0E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009C0E4: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8009C0E8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8009C0EC: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8009C0F0: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8009C0F4: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8009C0F8: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8009C0FC: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8009C100: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8009C104: bgtz        $t9, L_8009C148
    if (SIGNED(ctx->r25) > 0) {
        // 0x8009C108: sw          $t4, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r12;
            goto L_8009C148;
    }
    // 0x8009C108: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8009C10C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009C110: addiu       $v1, $v1, 0x718C
    ctx->r3 = ADD32(ctx->r3, 0X718C);
    // 0x8009C114: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8009C118: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8009C11C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8009C120: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8009C124: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8009C128: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009C12C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8009C130: lb          $t2, 0x0($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X0);
    // 0x8009C134: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C138: bgez        $t2, L_8009C14C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8009C13C: andi        $t4, $s2, 0x9000
        ctx->r12 = ctx->r18 & 0X9000;
            goto L_8009C14C;
    }
    // 0x8009C13C: andi        $t4, $s2, 0x9000
    ctx->r12 = ctx->r18 & 0X9000;
    // 0x8009C140: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8009C144: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_8009C148:
    // 0x8009C148: andi        $t4, $s2, 0x9000
    ctx->r12 = ctx->r18 & 0X9000;
L_8009C14C:
    // 0x8009C14C: bne         $t4, $zero, L_8009C168
    if (ctx->r12 != 0) {
        // 0x8009C150: andi        $t3, $s2, 0x4000
        ctx->r11 = ctx->r18 & 0X4000;
            goto L_8009C168;
    }
    // 0x8009C150: andi        $t3, $s2, 0x4000
    ctx->r11 = ctx->r18 & 0X4000;
    // 0x8009C154: bne         $t3, $zero, L_8009C16C
    if (ctx->r11 != 0) {
        // 0x8009C158: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8009C16C;
    }
    // 0x8009C158: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009C15C: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8009C160: nop

    // 0x8009C164: beq         $t5, $zero, L_8009C194
    if (ctx->r13 == 0) {
        // 0x8009C168: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8009C194;
    }
L_8009C168:
    // 0x8009C168: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_8009C16C:
    // 0x8009C16C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C170: jal         0x800C06A0
    // 0x8009C174: sw          $t6, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r14;
    disable_new_screen_transitions(rdram, ctx);
        goto after_22;
    // 0x8009C174: sw          $t6, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r14;
    after_22:
    // 0x8009C178: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009C17C: jal         0x800C06F8
    // 0x8009C180: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_23;
    // 0x8009C180: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_23:
    // 0x8009C184: jal         0x800C0690
    // 0x8009C188: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_24;
    // 0x8009C188: nop

    after_24:
    // 0x8009C18C: jal         0x80000C98
    // 0x8009C190: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_25;
    // 0x8009C190: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_25:
L_8009C194:
    // 0x8009C194: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C198: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8009C19C: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x8009C1A0: blez        $v0, L_8009C1F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009C1A4: addu        $t8, $v0, $t7
        ctx->r24 = ADD32(ctx->r2, ctx->r15);
            goto L_8009C1F8;
    }
    // 0x8009C1A4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8009C1A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C1AC: jal         0x800C7940
    // 0x8009C1B0: sw          $t8, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r24;
    bgload_active(rdram, ctx);
        goto after_26;
    // 0x8009C1B0: sw          $t8, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r24;
    after_26:
    // 0x8009C1B4: bne         $v0, $zero, L_8009C1F8
    if (ctx->r2 != 0) {
        // 0x8009C1B8: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8009C1F8;
    }
    // 0x8009C1B8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009C1BC: lw          $t9, -0x604($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X604);
    // 0x8009C1C0: nop

    // 0x8009C1C4: slti        $at, $t9, 0x1F
    ctx->r1 = SIGNED(ctx->r25) < 0X1F ? 1 : 0;
    // 0x8009C1C8: bne         $at, $zero, L_8009C1FC
    if (ctx->r1 != 0) {
        // 0x8009C1CC: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8009C1FC;
    }
    // 0x8009C1CC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8009C1D0: jal         0x80000B28
    // 0x8009C1D4: nop

    music_change_on(rdram, ctx);
        goto after_27;
    // 0x8009C1D4: nop

    after_27:
    // 0x8009C1D8: jal         0x8009C234
    // 0x8009C1DC: nop

    credits_free(rdram, ctx);
        goto after_28;
    // 0x8009C1DC: nop

    after_28:
    // 0x8009C1E0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8009C1E4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8009C1E8: jal         0x8006E528
    // 0x8009C1EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_29;
    // 0x8009C1EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_29:
    // 0x8009C1F0: jal         0x80081820
    // 0x8009C1F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    menu_init(rdram, ctx);
        goto after_30;
    // 0x8009C1F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_30:
L_8009C1F8:
    // 0x8009C1F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8009C1FC:
    // 0x8009C1FC: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8009C200: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8009C204: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8009C208: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8009C20C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8009C210: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8009C214: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8009C218: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8009C21C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8009C220: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8009C224: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8009C228: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x8009C22C: jr          $ra
    // 0x8009C230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8009C230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void menu_character_select_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C1DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008C1E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C1E4: jal         0x8008B6C4
    // 0x8008C1E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    charselect_render_text(rdram, ctx);
        goto after_0;
    // 0x8008C1E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008C1EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008C1F0: jal         0x8008C620
    // 0x8008C1F4: nop

    charselect_music_channels(rdram, ctx);
        goto after_1;
    // 0x8008C1F4: nop

    after_1:
    // 0x8008C1F8: jal         0x8008E9A4
    // 0x8008C1FC: nop

    menu_input(rdram, ctx);
        goto after_2;
    // 0x8008C1FC: nop

    after_2:
    // 0x8008C200: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008C204: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008C208: addiu       $a0, $a0, 0x6980
    ctx->r4 = ADD32(ctx->r4, 0X6980);
    // 0x8008C20C: addiu       $v0, $v0, 0x697C
    ctx->r2 = ADD32(ctx->r2, 0X697C);
    // 0x8008C210: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008C214: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8008C218:
    // 0x8008C218: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8008C21C: nop

    // 0x8008C220: bne         $t2, $t6, L_8008C22C
    if (ctx->r10 != ctx->r14) {
        // 0x8008C224: nop
    
            goto L_8008C22C;
    }
    // 0x8008C224: nop

    // 0x8008C228: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8008C22C:
    // 0x8008C22C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008C230: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8008C234: bne         $at, $zero, L_8008C218
    if (ctx->r1 != 0) {
        // 0x8008C238: nop
    
            goto L_8008C218;
    }
    // 0x8008C238: nop

    // 0x8008C23C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008C240: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008C244: addiu       $v1, $v1, -0x604
    ctx->r3 = ADD32(ctx->r3, -0X604);
    // 0x8008C248: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x8008C24C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008C250: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008C254: bne         $v0, $zero, L_8008C2C4
    if (ctx->r2 != 0) {
        // 0x8008C258: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8008C2C4;
    }
    // 0x8008C258: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008C25C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008C260: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008C264: lb          $t4, 0x6977($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X6977);
    // 0x8008C268: lb          $t9, 0x6976($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X6976);
    // 0x8008C26C: lb          $t7, 0x6974($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X6974);
    // 0x8008C270: lb          $t8, 0x6975($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X6975);
    // 0x8008C274: sb          $t4, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r12;
    // 0x8008C278: sb          $t9, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r25;
    // 0x8008C27C: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x8008C280: jal         0x8008B810
    // 0x8008C284: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    charselect_new_player(rdram, ctx);
        goto after_3;
    // 0x8008C284: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    after_3:
    // 0x8008C288: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008C28C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008C290: lw          $t6, -0x600($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X600);
    // 0x8008C294: lw          $t5, -0x5C4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5C4);
    // 0x8008C298: nop

    // 0x8008C29C: bne         $t5, $t6, L_8008C2B4
    if (ctx->r13 != ctx->r14) {
        // 0x8008C2A0: nop
    
            goto L_8008C2B4;
    }
    // 0x8008C2A0: nop

    // 0x8008C2A4: jal         0x8008B980
    // 0x8008C2A8: nop

    charselect_pick(rdram, ctx);
        goto after_4;
    // 0x8008C2A8: nop

    after_4:
    // 0x8008C2AC: b           L_8008C490
    // 0x8008C2B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008C490;
    // 0x8008C2B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C2B4:
    // 0x8008C2B4: jal         0x8008BC10
    // 0x8008C2B8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    charselect_input(rdram, ctx);
        goto after_5;
    // 0x8008C2B8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x8008C2BC: b           L_8008C490
    // 0x8008C2C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008C490;
    // 0x8008C2C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C2C4:
    // 0x8008C2C4: blez        $v0, L_8008C448
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008C2C8: nop
    
            goto L_8008C448;
    }
    // 0x8008C2C8: nop

    // 0x8008C2CC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8008C2D0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008C2D4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8008C2D8: slti        $at, $t8, 0x1F
    ctx->r1 = SIGNED(ctx->r24) < 0X1F ? 1 : 0;
    // 0x8008C2DC: bne         $at, $zero, L_8008C48C
    if (ctx->r1 != 0) {
        // 0x8008C2E0: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8008C48C;
    }
    // 0x8008C2E0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008C2E4: lw          $t4, 0x550($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X550);
    // 0x8008C2E8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8008C2EC: bne         $t4, $zero, L_8008C30C
    if (ctx->r12 != 0) {
        // 0x8008C2F0: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8008C30C;
    }
    // 0x8008C2F0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008C2F4: lw          $t5, 0x318($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X318);
    // 0x8008C2F8: or          $t3, $t2, $zero
    ctx->r11 = ctx->r10 | 0;
    // 0x8008C2FC: sll         $t6, $t5, 7
    ctx->r14 = S32(ctx->r13 << 7);
    // 0x8008C300: bgez        $t6, L_8008C30C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008C304: nop
    
            goto L_8008C30C;
    }
    // 0x8008C304: nop

    // 0x8008C308: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
L_8008C30C:
    // 0x8008C30C: jal         0x8008C5E0
    // 0x8008C310: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    charselect_free(rdram, ctx);
        goto after_6;
    // 0x8008C310: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_6:
    // 0x8008C314: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C318: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008C31C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008C320: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008C324: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8008C328: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008C32C: addiu       $a1, $a1, 0x6990
    ctx->r5 = ADD32(ctx->r5, 0X6990);
    // 0x8008C330: addiu       $a2, $a2, 0x696C
    ctx->r6 = ADD32(ctx->r6, 0X696C);
    // 0x8008C334: addiu       $a3, $a3, 0x6988
    ctx->r7 = ADD32(ctx->r7, 0X6988);
    // 0x8008C338: addiu       $v1, $v1, 0x6974
    ctx->r3 = ADD32(ctx->r3, 0X6974);
    // 0x8008C33C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008C340: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8008C344: addiu       $t0, $zero, 0xE
    ctx->r8 = ADD32(0, 0XE);
L_8008C348:
    // 0x8008C348: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x8008C34C: addu        $t9, $a3, $v0
    ctx->r25 = ADD32(ctx->r7, ctx->r2);
    // 0x8008C350: beq         $t7, $zero, L_8008C380
    if (ctx->r15 == 0) {
        // 0x8008C354: nop
    
            goto L_8008C380;
    }
    // 0x8008C354: nop

    // 0x8008C358: lb          $t4, 0x0($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X0);
    // 0x8008C35C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8008C360: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008C364: addu        $t9, $a1, $a0
    ctx->r25 = ADD32(ctx->r5, ctx->r4);
    // 0x8008C368: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008C36C: mflo        $t5
    ctx->r13 = lo;
    // 0x8008C370: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x8008C374: lh          $t7, 0xC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XC);
    // 0x8008C378: nop

    // 0x8008C37C: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
L_8008C380:
    // 0x8008C380: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008C384: bne         $v0, $t1, L_8008C348
    if (ctx->r2 != ctx->r9) {
        // 0x8008C388: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8008C348;
    }
    // 0x8008C388: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008C38C: jal         0x8008BFF4
    // 0x8008C390: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    charselect_assign_ai(rdram, ctx);
        goto after_7;
    // 0x8008C390: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_7:
    // 0x8008C394: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008C398: jal         0x8006A698
    // 0x8008C39C: addiu       $a0, $a0, 0x6974
    ctx->r4 = ADD32(ctx->r4, 0X6974);
    charselect_assign_players(rdram, ctx);
        goto after_8;
    // 0x8008C39C: addiu       $a0, $a0, 0x6974
    ctx->r4 = ADD32(ctx->r4, 0X6974);
    after_8:
    // 0x8008C3A0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008C3A4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8008C3A8: lw          $t4, -0x5C4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5C4);
    // 0x8008C3AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008C3B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C3B4: sw          $t2, -0x5C8($at)
    MEM_W(-0X5C8, ctx->r1) = ctx->r10;
    // 0x8008C3B8: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8008C3BC: bne         $at, $zero, L_8008C420
    if (ctx->r1 != 0) {
        // 0x8008C3C0: nop
    
            goto L_8008C420;
    }
    // 0x8008C3C0: nop

    // 0x8008C3C4: jal         0x80000B18
    // 0x8008C3C8: nop

    music_change_off(rdram, ctx);
        goto after_9;
    // 0x8008C3C8: nop

    after_9:
    // 0x8008C3CC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8008C3D0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008C3D4: jal         0x8006E528
    // 0x8008C3D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_10;
    // 0x8008C3D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8008C3DC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008C3E0: lw          $t8, -0x5C4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5C4);
    // 0x8008C3E4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008C3E8: bne         $t2, $t8, L_8008C410
    if (ctx->r10 != ctx->r24) {
        // 0x8008C3EC: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8008C410;
    }
    // 0x8008C3EC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008C3F0: lw          $t5, -0x5E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E8);
    // 0x8008C3F4: nop

    // 0x8008C3F8: bne         $t5, $zero, L_8008C410
    if (ctx->r13 != 0) {
        // 0x8008C3FC: nop
    
            goto L_8008C410;
    }
    // 0x8008C3FC: nop

    // 0x8008C400: jal         0x80081820
    // 0x8008C404: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    menu_init(rdram, ctx);
        goto after_11;
    // 0x8008C404: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_11:
    // 0x8008C408: b           L_8008C490
    // 0x8008C40C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008C490;
    // 0x8008C40C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C410:
    // 0x8008C410: jal         0x80081820
    // 0x8008C414: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    menu_init(rdram, ctx);
        goto after_12;
    // 0x8008C414: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_12:
    // 0x8008C418: b           L_8008C490
    // 0x8008C41C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008C490;
    // 0x8008C41C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C420:
    // 0x8008C420: jal         0x80000B28
    // 0x8008C424: nop

    music_change_on(rdram, ctx);
        goto after_13;
    // 0x8008C424: nop

    after_13:
    // 0x8008C428: jal         0x80082D08
    // 0x8008C42C: nop

    trackmenu_set_records(rdram, ctx);
        goto after_14;
    // 0x8008C42C: nop

    after_14:
    // 0x8008C430: jal         0x8006E7FC
    // 0x8008C434: nop

    init_racer_headers(rdram, ctx);
        goto after_15;
    // 0x8008C434: nop

    after_15:
    // 0x8008C438: jal         0x80081820
    // 0x8008C43C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    menu_init(rdram, ctx);
        goto after_16;
    // 0x8008C43C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_16:
    // 0x8008C440: b           L_8008C490
    // 0x8008C444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008C490;
    // 0x8008C444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C448:
    // 0x8008C448: bgez        $v0, L_8008C48C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008C44C: nop
    
            goto L_8008C48C;
    }
    // 0x8008C44C: nop

    // 0x8008C450: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8008C454: nop

    // 0x8008C458: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8008C45C: slti        $at, $t7, -0x1E
    ctx->r1 = SIGNED(ctx->r15) < -0X1E ? 1 : 0;
    // 0x8008C460: beq         $at, $zero, L_8008C48C
    if (ctx->r1 == 0) {
        // 0x8008C464: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_8008C48C;
    }
    // 0x8008C464: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8008C468: jal         0x80000B28
    // 0x8008C46C: nop

    music_change_on(rdram, ctx);
        goto after_17;
    // 0x8008C46C: nop

    after_17:
    // 0x8008C470: jal         0x8008C5E0
    // 0x8008C474: nop

    charselect_free(rdram, ctx);
        goto after_18;
    // 0x8008C474: nop

    after_18:
    // 0x8008C478: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008C47C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C480: sw          $t2, -0x5C4($at)
    MEM_W(-0X5C4, ctx->r1) = ctx->r10;
    // 0x8008C484: jal         0x80081820
    // 0x8008C488: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    menu_init(rdram, ctx);
        goto after_19;
    // 0x8008C488: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
L_8008C48C:
    // 0x8008C48C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C490:
    // 0x8008C490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C494: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008C498: jr          $ra
    // 0x8008C49C: nop

    return;
    // 0x8008C49C: nop

;}
RECOMP_FUNC void ignore_bounds_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011560: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80011564: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011568: jr          $ra
    // 0x8001156C: sb          $t6, -0x3248($at)
    MEM_B(-0X3248, ctx->r1) = ctx->r14;
    return;
    // 0x8001156C: sb          $t6, -0x3248($at)
    MEM_B(-0X3248, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void sndp_stop_with_flags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800048D8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800048DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800048E0: andi        $s2, $a0, 0xFF
    ctx->r18 = ctx->r4 & 0XFF;
    // 0x800048E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800048E8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800048EC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800048F0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800048F4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800048F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800048FC: jal         0x800C9F90
    // 0x80004900: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80004900: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80004904: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80004908: lw          $s0, -0x33E0($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X33E0);
    // 0x8000490C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80004910: beq         $s0, $zero, L_8000496C
    if (ctx->r16 == 0) {
        // 0x80004914: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_8000496C;
    }
    // 0x80004914: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80004918: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8000491C: addiu       $s3, $s3, -0x33D4
    ctx->r19 = ADD32(ctx->r19, -0X33D4);
    // 0x80004920: addiu       $s4, $sp, 0x3C
    ctx->r20 = ADD32(ctx->r29, 0X3C);
    // 0x80004924: addiu       $s2, $zero, -0x11
    ctx->r18 = ADD32(0, -0X11);
    // 0x80004928: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
L_8000492C:
    // 0x8000492C: sh          $t6, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r14;
    // 0x80004930: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80004934: lbu         $v0, 0x3E($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3E);
    // 0x80004938: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8000493C: and         $t7, $v0, $s1
    ctx->r15 = ctx->r2 & ctx->r17;
    // 0x80004940: bne         $s1, $t7, L_8000495C
    if (ctx->r17 != ctx->r15) {
        // 0x80004944: and         $t8, $v0, $s2
        ctx->r24 = ctx->r2 & ctx->r18;
            goto L_8000495C;
    }
    // 0x80004944: and         $t8, $v0, $s2
    ctx->r24 = ctx->r2 & ctx->r18;
    // 0x80004948: sb          $t8, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r24;
    // 0x8000494C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80004950: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004954: jal         0x800C970C
    // 0x80004958: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x80004958: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
L_8000495C:
    // 0x8000495C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80004960: nop

    // 0x80004964: bne         $s0, $zero, L_8000492C
    if (ctx->r16 != 0) {
        // 0x80004968: addiu       $t6, $zero, 0x400
        ctx->r14 = ADD32(0, 0X400);
            goto L_8000492C;
    }
    // 0x80004968: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
L_8000496C:
    // 0x8000496C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80004970: jal         0x800C9F90
    // 0x80004974: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80004974: nop

    after_2:
    // 0x80004978: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000497C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004980: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80004984: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80004988: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000498C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80004990: jr          $ra
    // 0x80004994: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80004994: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void search_level_properties_backwards(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B06C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006B070: lw          $v0, 0x16F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16F0);
    // 0x8006B074: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006B078: sll         $t6, $a1, 24
    ctx->r14 = S32(ctx->r5 << 24);
    // 0x8006B07C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8006B080: sll         $t8, $a2, 24
    ctx->r24 = S32(ctx->r6 << 24);
    // 0x8006B084: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006B088: sra         $a2, $t8, 24
    ctx->r6 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8006B08C: bne         $at, $zero, L_8006B098
    if (ctx->r1 != 0) {
        // 0x8006B090: sra         $a1, $t6, 24
        ctx->r5 = S32(SIGNED(ctx->r14) >> 24);
            goto L_8006B098;
    }
    // 0x8006B090: sra         $a1, $t6, 24
    ctx->r5 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006B094: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8006B098:
    // 0x8006B098: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8006B09C: beq         $a1, $at, L_8006B1A0
    if (ctx->r5 == ctx->r1) {
        // 0x8006B0A0: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8006B1A0;
    }
    // 0x8006B0A0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006B0A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006B0A8: bne         $a2, $v0, L_8006B0F8
    if (ctx->r6 != ctx->r2) {
        // 0x8006B0AC: nop
    
            goto L_8006B0F8;
    }
    // 0x8006B0AC: nop

    // 0x8006B0B0: bltz        $a0, L_8006B24C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B0B4: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8006B24C;
    }
    // 0x8006B0B4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006B0B8: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8006B0BC: lw          $t0, 0x16FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X16FC);
    // 0x8006B0C0: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8006B0C4: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006B0C8: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
L_8006B0CC:
    // 0x8006B0CC: lb          $t2, 0x1($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X1);
    // 0x8006B0D0: nop

    // 0x8006B0D4: bne         $a1, $t2, L_8006B0E4
    if (ctx->r5 != ctx->r10) {
        // 0x8006B0D8: nop
    
            goto L_8006B0E4;
    }
    // 0x8006B0D8: nop

    // 0x8006B0DC: jr          $ra
    // 0x8006B0E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006B0E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006B0E4:
    // 0x8006B0E4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006B0E8: bgez        $a0, L_8006B0CC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006B0EC: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8006B0CC;
    }
    // 0x8006B0EC: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x8006B0F0: b           L_8006B250
    // 0x8006B0F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B250;
    // 0x8006B0F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006B0F8:
    // 0x8006B0F8: bne         $a1, $v0, L_8006B148
    if (ctx->r5 != ctx->r2) {
        // 0x8006B0FC: nop
    
            goto L_8006B148;
    }
    // 0x8006B0FC: nop

    // 0x8006B100: bltz        $a0, L_8006B24C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B104: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8006B24C;
    }
    // 0x8006B104: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006B108: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8006B10C: lw          $t3, 0x16FC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X16FC);
    // 0x8006B110: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8006B114: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8006B118: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
L_8006B11C:
    // 0x8006B11C: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x8006B120: nop

    // 0x8006B124: bne         $a2, $t5, L_8006B134
    if (ctx->r6 != ctx->r13) {
        // 0x8006B128: nop
    
            goto L_8006B134;
    }
    // 0x8006B128: nop

    // 0x8006B12C: jr          $ra
    // 0x8006B130: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006B130: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006B134:
    // 0x8006B134: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006B138: bgez        $a0, L_8006B11C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006B13C: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8006B11C;
    }
    // 0x8006B13C: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x8006B140: b           L_8006B250
    // 0x8006B144: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B250;
    // 0x8006B144: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006B148:
    // 0x8006B148: bltz        $a0, L_8006B24C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B14C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006B24C;
    }
    // 0x8006B14C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B150: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8006B154: lw          $t6, 0x16FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16FC);
    // 0x8006B158: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8006B15C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006B160: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_8006B164:
    // 0x8006B164: lb          $t8, 0x1($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1);
    // 0x8006B168: nop

    // 0x8006B16C: bne         $a1, $t8, L_8006B18C
    if (ctx->r5 != ctx->r24) {
        // 0x8006B170: nop
    
            goto L_8006B18C;
    }
    // 0x8006B170: nop

    // 0x8006B174: lb          $t9, 0x0($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X0);
    // 0x8006B178: nop

    // 0x8006B17C: bne         $a2, $t9, L_8006B18C
    if (ctx->r6 != ctx->r25) {
        // 0x8006B180: nop
    
            goto L_8006B18C;
    }
    // 0x8006B180: nop

    // 0x8006B184: jr          $ra
    // 0x8006B188: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006B188: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006B18C:
    // 0x8006B18C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006B190: bgez        $a0, L_8006B164
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006B194: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8006B164;
    }
    // 0x8006B194: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x8006B198: b           L_8006B250
    // 0x8006B19C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B250;
    // 0x8006B19C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006B1A0:
    // 0x8006B1A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006B1A4: bne         $a2, $v0, L_8006B1F8
    if (ctx->r6 != ctx->r2) {
        // 0x8006B1A8: nop
    
            goto L_8006B1F8;
    }
    // 0x8006B1A8: nop

    // 0x8006B1AC: bltz        $a0, L_8006B24C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B1B0: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8006B24C;
    }
    // 0x8006B1B0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006B1B4: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8006B1B8: lw          $t0, 0x16FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X16FC);
    // 0x8006B1BC: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8006B1C0: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006B1C4: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
L_8006B1C8:
    // 0x8006B1C8: lb          $t2, 0x1($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X1);
    // 0x8006B1CC: nop

    // 0x8006B1D0: andi        $t3, $t2, 0x40
    ctx->r11 = ctx->r10 & 0X40;
    // 0x8006B1D4: beq         $t3, $zero, L_8006B1E4
    if (ctx->r11 == 0) {
        // 0x8006B1D8: nop
    
            goto L_8006B1E4;
    }
    // 0x8006B1D8: nop

    // 0x8006B1DC: jr          $ra
    // 0x8006B1E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006B1E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006B1E4:
    // 0x8006B1E4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006B1E8: bgez        $a0, L_8006B1C8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006B1EC: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8006B1C8;
    }
    // 0x8006B1EC: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x8006B1F0: b           L_8006B250
    // 0x8006B1F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B250;
    // 0x8006B1F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006B1F8:
    // 0x8006B1F8: bltz        $a0, L_8006B24C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B1FC: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_8006B24C;
    }
    // 0x8006B1FC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006B200: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8006B204: lw          $t4, 0x16FC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X16FC);
    // 0x8006B208: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8006B20C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8006B210: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
L_8006B214:
    // 0x8006B214: lb          $t6, 0x1($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1);
    // 0x8006B218: nop

    // 0x8006B21C: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x8006B220: beq         $t7, $zero, L_8006B240
    if (ctx->r15 == 0) {
        // 0x8006B224: nop
    
            goto L_8006B240;
    }
    // 0x8006B224: nop

    // 0x8006B228: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x8006B22C: nop

    // 0x8006B230: bne         $a2, $t8, L_8006B240
    if (ctx->r6 != ctx->r24) {
        // 0x8006B234: nop
    
            goto L_8006B240;
    }
    // 0x8006B234: nop

    // 0x8006B238: jr          $ra
    // 0x8006B23C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006B23C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006B240:
    // 0x8006B240: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006B244: bgez        $a0, L_8006B214
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006B248: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8006B214;
    }
    // 0x8006B248: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
L_8006B24C:
    // 0x8006B24C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006B250:
    // 0x8006B250: jr          $ra
    // 0x8006B254: nop

    return;
    // 0x8006B254: nop

;}
RECOMP_FUNC void rain_lightning(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE018: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AE01C: addiu       $a2, $a2, 0x3210
    ctx->r6 = ADD32(ctx->r6, 0X3210);
    // 0x800AE020: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800AE024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE028: blez        $v0, L_800AE084
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AE02C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AE084;
    }
    // 0x800AE02C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE030: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x800AE034: bgtz        $t6, L_800AE118
    if (SIGNED(ctx->r14) > 0) {
        // 0x800AE038: sw          $t6, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r14;
            goto L_800AE118;
    }
    // 0x800AE038: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800AE03C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AE040: lw          $t8, 0x31FC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X31FC);
    // 0x800AE044: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800AE048: slt         $at, $t8, $at
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800AE04C: bne         $at, $zero, L_800AE070
    if (ctx->r1 != 0) {
        // 0x800AE050: addiu       $a0, $zero, 0x27
        ctx->r4 = ADD32(0, 0X27);
            goto L_800AE070;
    }
    // 0x800AE050: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800AE054: jal         0x800C06AC
    // 0x800AE058: nop

    check_fadeout_transition(rdram, ctx);
        goto after_0;
    // 0x800AE058: nop

    after_0:
    // 0x800AE05C: bne         $v0, $zero, L_800AE06C
    if (ctx->r2 != 0) {
        // 0x800AE060: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800AE06C;
    }
    // 0x800AE060: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE064: jal         0x800C06F8
    // 0x800AE068: addiu       $a0, $a0, 0x3228
    ctx->r4 = ADD32(ctx->r4, 0X3228);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x800AE068: addiu       $a0, $a0, 0x3228
    ctx->r4 = ADD32(ctx->r4, 0X3228);
    after_1:
L_800AE06C:
    // 0x800AE06C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
L_800AE070:
    // 0x800AE070: jal         0x80001D04
    // 0x800AE074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x800AE074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800AE078: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE07C: b           L_800AE118
    // 0x800AE080: sw          $zero, 0x3210($at)
    MEM_W(0X3210, ctx->r1) = 0;
        goto L_800AE118;
    // 0x800AE080: sw          $zero, 0x3210($at)
    MEM_W(0X3210, ctx->r1) = 0;
L_800AE084:
    // 0x800AE084: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AE088: lw          $t9, 0x31F0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X31F0);
    // 0x800AE08C: ori         $at, $zero, 0xBB80
    ctx->r1 = 0 | 0XBB80;
    // 0x800AE090: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800AE094: bne         $at, $zero, L_800AE118
    if (ctx->r1 != 0) {
        // 0x800AE098: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800AE118;
    }
    // 0x800AE098: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AE09C: addiu       $v1, $v1, 0x320C
    ctx->r3 = ADD32(ctx->r3, 0X320C);
    // 0x800AE0A0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AE0A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AE0A8: blez        $v0, L_800AE0B8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AE0AC: subu        $t0, $v0, $a0
        ctx->r8 = SUB32(ctx->r2, ctx->r4);
            goto L_800AE0B8;
    }
    // 0x800AE0AC: subu        $t0, $v0, $a0
    ctx->r8 = SUB32(ctx->r2, ctx->r4);
    // 0x800AE0B0: b           L_800AE118
    // 0x800AE0B4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
        goto L_800AE118;
    // 0x800AE0B4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_800AE0B8:
    // 0x800AE0B8: jal         0x80001D04
    // 0x800AE0BC: addiu       $a0, $zero, 0x23F
    ctx->r4 = ADD32(0, 0X23F);
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800AE0BC: addiu       $a0, $zero, 0x23F
    ctx->r4 = ADD32(0, 0X23F);
    after_3:
    // 0x800AE0C0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AE0C4: lw          $t1, 0x31F0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X31F0);
    // 0x800AE0C8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800AE0CC: ori         $at, $at, 0x4480
    ctx->r1 = ctx->r1 | 0X4480;
    // 0x800AE0D0: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800AE0D4: sra         $t3, $t2, 5
    ctx->r11 = S32(SIGNED(ctx->r10) >> 5);
    // 0x800AE0D8: addiu       $t4, $zero, 0x258
    ctx->r12 = ADD32(0, 0X258);
    // 0x800AE0DC: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x800AE0E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE0E4: sw          $t5, 0x3210($at)
    MEM_W(0X3210, ctx->r1) = ctx->r13;
    // 0x800AE0E8: addiu       $a0, $zero, 0x384
    ctx->r4 = ADD32(0, 0X384);
    // 0x800AE0EC: jal         0x8006FB8C
    // 0x800AE0F0: addiu       $a1, $zero, 0x474
    ctx->r5 = ADD32(0, 0X474);
    rand_range(rdram, ctx);
        goto after_4;
    // 0x800AE0F0: addiu       $a1, $zero, 0x474
    ctx->r5 = ADD32(0, 0X474);
    after_4:
    // 0x800AE0F4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AE0F8: lw          $t6, 0x31F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31F0);
    // 0x800AE0FC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800AE100: ori         $at, $at, 0x4480
    ctx->r1 = ctx->r1 | 0X4480;
    // 0x800AE104: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800AE108: sra         $t8, $t7, 5
    ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
    // 0x800AE10C: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x800AE110: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE114: sw          $t9, 0x320C($at)
    MEM_W(0X320C, ctx->r1) = ctx->r25;
L_800AE118:
    // 0x800AE118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE11C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE120: jr          $ra
    // 0x800AE124: nop

    return;
    // 0x800AE124: nop

;}
RECOMP_FUNC void transition_update_circle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2408: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C240C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C2410: addiu       $v1, $v1, 0x3740
    ctx->r3 = ADD32(ctx->r3, 0X3740);
    // 0x800C2414: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800C2418: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800C241C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800C2420: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800C2424: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800C2428: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800C242C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800C2430: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800C2434: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800C2438: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800C243C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800C2440: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800C2444: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800C2448: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800C244C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C2450: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800C2454: blez        $v0, L_800C2728
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C2458: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C2728;
    }
    // 0x800C2458: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C245C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C2460: beq         $at, $zero, L_800C24B4
    if (ctx->r1 == 0) {
        // 0x800C2464: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800C24B4;
    }
    // 0x800C2464: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800C2468: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C246C: lwc1        $f8, -0x52E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X52E0);
    // 0x800C2470: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800C2474: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800C2478: addiu       $s7, $s7, -0x52E8
    ctx->r23 = ADD32(ctx->r23, -0X52E8);
    // 0x800C247C: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800C2480: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2484: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C2488: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800C248C: swc1        $f16, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f16.u32l;
    // 0x800C2490: lwc1        $f4, -0x52DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X52DC);
    // 0x800C2494: addiu       $fp, $fp, -0x52E4
    ctx->r30 = ADD32(ctx->r30, -0X52E4);
    // 0x800C2498: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C249C: lwc1        $f18, 0x0($fp)
    ctx->f18.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800C24A0: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x800C24A4: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x800C24A8: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800C24AC: b           L_800C24E0
    // 0x800C24B0: swc1        $f6, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f6.u32l;
        goto L_800C24E0;
    // 0x800C24B0: swc1        $f6, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f6.u32l;
L_800C24B4:
    // 0x800C24B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C24B8: lwc1        $f10, -0x52D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X52D8);
    // 0x800C24BC: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800C24C0: addiu       $s7, $s7, -0x52E8
    ctx->r23 = ADD32(ctx->r23, -0X52E8);
    // 0x800C24C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C24C8: swc1        $f10, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f10.u32l;
    // 0x800C24CC: lwc1        $f16, -0x52D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X52D4);
    // 0x800C24D0: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800C24D4: addiu       $fp, $fp, -0x52E4
    ctx->r30 = ADD32(ctx->r30, -0X52E4);
    // 0x800C24D8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800C24DC: swc1        $f16, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f16.u32l;
L_800C24E0:
    // 0x800C24E0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C24E4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800C24E8: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800C24EC: lwc1        $f22, -0x6754($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X6754);
    // 0x800C24F0: addiu       $s0, $s0, 0x3750
    ctx->r16 = ADD32(ctx->r16, 0X3750);
    // 0x800C24F4: addiu       $s1, $s1, 0x3760
    ctx->r17 = ADD32(ctx->r17, 0X3760);
    // 0x800C24F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800C24FC: addiu       $s6, $zero, 0x9
    ctx->r22 = ADD32(0, 0X9);
    // 0x800C2500: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
L_800C2504:
    // 0x800C2504: sll         $s4, $s3, 16
    ctx->r20 = S32(ctx->r19 << 16);
    // 0x800C2508: sra         $t7, $s4, 16
    ctx->r15 = S32(SIGNED(ctx->r20) >> 16);
    // 0x800C250C: sll         $a0, $t7, 16
    ctx->r4 = S32(ctx->r15 << 16);
    // 0x800C2510: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C2514: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800C2518: jal         0x80070A04
    // 0x800C251C: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x800C251C: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    after_0:
    // 0x800C2520: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800C2524: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
    // 0x800C2528: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C252C: mul.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C2530: jal         0x80070A38
    // 0x800C2534: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x800C2534: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
    // 0x800C2538: lwc1        $f18, 0x0($fp)
    ctx->f18.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800C253C: sll         $t0, $s2, 1
    ctx->r8 = S32(ctx->r18 << 1);
    // 0x800C2540: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800C2544: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800C2548: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C254C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C2550: mul.s       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800C2554: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x800C2558: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800C255C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C2560: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800C2564: addiu       $s3, $s3, 0x1000
    ctx->r19 = ADD32(ctx->r19, 0X1000);
    // 0x800C2568: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800C256C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C2570: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C2574: nop

    // 0x800C2578: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800C257C: mflo        $v0
    ctx->r2 = lo;
    // 0x800C2580: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800C2584: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800C2588: mul.s       $f10, $f2, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800C258C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C2590: sh          $a0, 0xA($t6)
    MEM_H(0XA, ctx->r14) = ctx->r4;
    // 0x800C2594: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800C2598: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800C259C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C25A0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800C25A4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C25A8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C25AC: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x800C25B0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800C25B4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800C25B8: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800C25BC: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800C25C0: sh          $v1, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r3;
    // 0x800C25C4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800C25C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C25CC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C25D0: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800C25D4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C25D8: negu        $a3, $a0
    ctx->r7 = SUB32(0, ctx->r4);
    // 0x800C25DC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C25E0: sh          $a3, 0x172($t8)
    MEM_H(0X172, ctx->r24) = ctx->r7;
    // 0x800C25E4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800C25E8: nop

    // 0x800C25EC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800C25F0: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800C25F4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800C25F8: nop

    // 0x800C25FC: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800C2600: sh          $v1, 0x174($t3)
    MEM_H(0X174, ctx->r11) = ctx->r3;
    // 0x800C2604: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800C2608: nop

    // 0x800C260C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C2610: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800C2614: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C2618: nop

    // 0x800C261C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2620: sh          $a0, 0xB4($t8)
    MEM_H(0XB4, ctx->r24) = ctx->r4;
    // 0x800C2624: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800C2628: nop

    // 0x800C262C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800C2630: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800C2634: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800C2638: nop

    // 0x800C263C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800C2640: sh          $v1, 0xB6($t3)
    MEM_H(0XB6, ctx->r11) = ctx->r3;
    // 0x800C2644: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800C2648: nop

    // 0x800C264C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C2650: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800C2654: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C2658: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800C265C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2660: sh          $a3, 0x21C($t8)
    MEM_H(0X21C, ctx->r24) = ctx->r7;
    // 0x800C2664: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800C2668: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800C266C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800C2670: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800C2674: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800C2678: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C267C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C2680: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800C2684: sh          $v1, 0x21E($t3)
    MEM_H(0X21E, ctx->r11) = ctx->r3;
    // 0x800C2688: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800C268C: cvt.w.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = CVT_W_S(ctx->f20.fl);
    // 0x800C2690: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800C2694: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800C2698: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x800C269C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800C26A0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800C26A4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800C26A8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C26AC: sh          $a1, 0xBE($t9)
    MEM_H(0XBE, ctx->r25) = ctx->r5;
    // 0x800C26B0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800C26B4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800C26B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C26BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C26C0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800C26C4: cvt.w.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = CVT_W_S(ctx->f2.fl);
    // 0x800C26C8: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x800C26CC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800C26D0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800C26D4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C26D8: sh          $a2, 0xC0($t5)
    MEM_H(0XC0, ctx->r13) = ctx->r6;
    // 0x800C26DC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800C26E0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800C26E4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800C26E8: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800C26EC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800C26F0: negu        $t8, $a1
    ctx->r24 = SUB32(0, ctx->r5);
    // 0x800C26F4: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800C26F8: sh          $t8, 0x226($t3)
    MEM_H(0X226, ctx->r11) = ctx->r24;
    // 0x800C26FC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800C2700: nop

    // 0x800C2704: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C2708: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800C270C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C2710: nop

    // 0x800C2714: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2718: bne         $s2, $s6, L_800C2504
    if (ctx->r18 != ctx->r22) {
        // 0x800C271C: sh          $a2, 0x228($t9)
        MEM_H(0X228, ctx->r25) = ctx->r6;
            goto L_800C2504;
    }
    // 0x800C271C: sh          $a2, 0x228($t9)
    MEM_H(0X228, ctx->r25) = ctx->r6;
    // 0x800C2720: b           L_800C2758
    // 0x800C2724: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_800C2758;
    // 0x800C2724: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_800C2728:
    // 0x800C2728: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C272C: addiu       $v1, $v1, 0x3744
    ctx->r3 = ADD32(ctx->r3, 0X3744);
    // 0x800C2730: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800C2734: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800C2738: beq         $v0, $at, L_800C2754
    if (ctx->r2 == ctx->r1) {
        // 0x800C273C: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800C2754;
    }
    // 0x800C273C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C2740: beq         $at, $zero, L_800C2750
    if (ctx->r1 == 0) {
        // 0x800C2744: subu        $t0, $v0, $a0
        ctx->r8 = SUB32(ctx->r2, ctx->r4);
            goto L_800C2750;
    }
    // 0x800C2744: subu        $t0, $v0, $a0
    ctx->r8 = SUB32(ctx->r2, ctx->r4);
    // 0x800C2748: b           L_800C2754
    // 0x800C274C: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
        goto L_800C2754;
    // 0x800C274C: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
L_800C2750:
    // 0x800C2750: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_800C2754:
    // 0x800C2754: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_800C2758:
    // 0x800C2758: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800C275C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C2760: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C2764: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C2768: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800C276C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2770: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800C2774: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800C2778: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800C277C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800C2780: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800C2784: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800C2788: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800C278C: jr          $ra
    // 0x800C2790: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800C2790: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void savemenu_load_destinations(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80086C18: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80086C1C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80086C20: addiu       $s0, $s0, 0x6FC0
    ctx->r16 = ADD32(ctx->r16, 0X6FC0);
    // 0x80086C24: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80086C28: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80086C2C: lw          $t7, 0x7194($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7194);
    // 0x80086C30: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80086C34: lw          $t6, 0x6FCC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6FCC);
    // 0x80086C38: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80086C3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80086C40: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80086C44: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80086C48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80086C4C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80086C50: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x80086C54: beq         $at, $zero, L_80086E4C
    if (ctx->r1 == 0) {
        // 0x80086C58: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80086E4C;
    }
    // 0x80086C58: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80086C5C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80086C60: addu        $at, $at, $t0
    gpr jr_addend_80086C6C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80086C64: lw          $t0, -0x7670($at)
    ctx->r8 = ADD32(ctx->r1, -0X7670);
    // 0x80086C68: nop

    // 0x80086C6C: jr          $t0
    // 0x80086C70: nop

    switch (jr_addend_80086C6C >> 2) {
        case 0: goto L_80086C74; break;
        case 1: goto L_80086CC8; break;
        case 2: goto L_80086D00; break;
        case 3: goto L_80086D60; break;
        case 4: goto L_80086DD8; break;
        default: switch_error(__func__, 0x80086C6C, 0x800E8990);
    }
    // 0x80086C70: nop

L_80086C74:
    // 0x80086C74: lbu         $a0, 0x6($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X6);
    // 0x80086C78: jal         0x8006EDB8
    // 0x80086C7C: nop

    mark_read_save_file(rdram, ctx);
        goto after_0;
    // 0x80086C7C: nop

    after_0:
    // 0x80086C80: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80086C84: lw          $a0, 0x6FC4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6FC4);
    // 0x80086C88: jal         0x80086608
    // 0x80086C8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    savemenu_blank_save_destination(rdram, ctx);
        goto after_1;
    // 0x80086C8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80086C90: jal         0x80073EA4
    // 0x80086C94: nop

    get_game_data_file_size(rdram, ctx);
        goto after_2;
    // 0x80086C94: nop

    after_2:
    // 0x80086C98: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80086C9C: lw          $a2, 0x6FC4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6FC4);
    // 0x80086CA0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086CA4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80086CA8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80086CAC: addiu       $a1, $a1, 0x6FD8
    ctx->r5 = ADD32(ctx->r5, 0X6FD8);
    // 0x80086CB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80086CB4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80086CB8: jal         0x800864E8
    // 0x80086CBC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    savemenu_check_space(rdram, ctx);
        goto after_3;
    // 0x80086CBC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x80086CC0: b           L_80086E4C
    // 0x80086CC4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80086E4C;
    // 0x80086CC4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80086CC8:
    // 0x80086CC8: jal         0x80073EAC
    // 0x80086CCC: nop

    get_time_data_file_size(rdram, ctx);
        goto after_4;
    // 0x80086CCC: nop

    after_4:
    // 0x80086CD0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80086CD4: lw          $a2, 0x6FC4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6FC4);
    // 0x80086CD8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086CDC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80086CE0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80086CE4: addiu       $a1, $a1, 0x6FD8
    ctx->r5 = ADD32(ctx->r5, 0X6FD8);
    // 0x80086CE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80086CEC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80086CF0: jal         0x800864E8
    // 0x80086CF4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    savemenu_check_space(rdram, ctx);
        goto after_5;
    // 0x80086CF4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
    // 0x80086CF8: b           L_80086E4C
    // 0x80086CFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80086E4C;
    // 0x80086CFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80086D00:
    // 0x80086D00: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80086D04: lw          $a0, 0x6FC4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6FC4);
    // 0x80086D08: jal         0x80086608
    // 0x80086D0C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    savemenu_blank_save_destination(rdram, ctx);
        goto after_6;
    // 0x80086D0C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80086D10: jal         0x80073EA4
    // 0x80086D14: nop

    get_game_data_file_size(rdram, ctx);
        goto after_7;
    // 0x80086D14: nop

    after_7:
    // 0x80086D18: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80086D1C: lw          $t4, 0x7194($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7194);
    // 0x80086D20: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80086D24: lw          $t3, 0x6FCC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6FCC);
    // 0x80086D28: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80086D2C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80086D30: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80086D34: lbu         $t6, 0x6($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X6);
    // 0x80086D38: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80086D3C: lw          $a2, 0x6FC4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6FC4);
    // 0x80086D40: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086D44: addiu       $a1, $a1, 0x6FDC
    ctx->r5 = ADD32(ctx->r5, 0X6FDC);
    // 0x80086D48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80086D4C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80086D50: jal         0x800864E8
    // 0x80086D54: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    savemenu_check_space(rdram, ctx);
        goto after_8;
    // 0x80086D54: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_8:
    // 0x80086D58: b           L_80086E4C
    // 0x80086D5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80086E4C;
    // 0x80086D5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80086D60:
    // 0x80086D60: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80086D64: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80086D68: lw          $t9, 0x6FC4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6FC4);
    // 0x80086D6C: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80086D70: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80086D74: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80086D78: sb          $t8, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r24;
    // 0x80086D7C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80086D80: nop

    // 0x80086D84: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80086D88: jal         0x80073EAC
    // 0x80086D8C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    get_time_data_file_size(rdram, ctx);
        goto after_9;
    // 0x80086D8C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    after_9:
    // 0x80086D90: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80086D94: lw          $t7, 0x7194($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7194);
    // 0x80086D98: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80086D9C: lw          $t5, 0x6FCC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6FCC);
    // 0x80086DA0: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x80086DA4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80086DA8: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x80086DAC: lbu         $t9, 0x6($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X6);
    // 0x80086DB0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80086DB4: lw          $a2, 0x6FC4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6FC4);
    // 0x80086DB8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086DBC: addiu       $a1, $a1, 0x6FDC
    ctx->r5 = ADD32(ctx->r5, 0X6FDC);
    // 0x80086DC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80086DC4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80086DC8: jal         0x800864E8
    // 0x80086DCC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    savemenu_check_space(rdram, ctx);
        goto after_10;
    // 0x80086DCC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_10:
    // 0x80086DD0: b           L_80086E4C
    // 0x80086DD4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80086E4C;
    // 0x80086DD4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80086DD8:
    // 0x80086DD8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80086DDC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80086DE0: lw          $t8, 0x6FC4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6FC4);
    // 0x80086DE4: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x80086DE8: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80086DEC: addu        $t3, $t8, $t4
    ctx->r11 = ADD32(ctx->r24, ctx->r12);
    // 0x80086DF0: sb          $t1, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r9;
    // 0x80086DF4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80086DF8: nop

    // 0x80086DFC: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x80086E00: jal         0x80074D74
    // 0x80086E04: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    get_ghost_data_file_size(rdram, ctx);
        goto after_11;
    // 0x80086E04: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    after_11:
    // 0x80086E08: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80086E0C: lw          $t0, 0x7194($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7194);
    // 0x80086E10: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80086E14: lw          $t6, 0x6FCC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6FCC);
    // 0x80086E18: sll         $t9, $t0, 4
    ctx->r25 = S32(ctx->r8 << 4);
    // 0x80086E1C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80086E20: addu        $t2, $t6, $t9
    ctx->r10 = ADD32(ctx->r14, ctx->r25);
    // 0x80086E24: lbu         $t8, 0x6($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X6);
    // 0x80086E28: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80086E2C: lw          $a2, 0x6FC4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6FC4);
    // 0x80086E30: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086E34: addiu       $a1, $a1, 0x6FDC
    ctx->r5 = ADD32(ctx->r5, 0X6FDC);
    // 0x80086E38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80086E3C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80086E40: jal         0x800864E8
    // 0x80086E44: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    savemenu_check_space(rdram, ctx);
        goto after_12;
    // 0x80086E44: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_12:
    // 0x80086E48: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80086E4C:
    // 0x80086E4C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80086E50: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086E54: lw          $t1, 0x6FC4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6FC4);
    // 0x80086E58: sll         $t7, $t3, 4
    ctx->r15 = S32(ctx->r11 << 4);
    // 0x80086E5C: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x80086E60: addu        $t5, $t1, $t7
    ctx->r13 = ADD32(ctx->r9, ctx->r15);
    // 0x80086E64: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x80086E68: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80086E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80086E70: addiu       $t6, $t0, 0x1
    ctx->r14 = ADD32(ctx->r8, 0X1);
    // 0x80086E74: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80086E78: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80086E7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80086E80: jr          $ra
    // 0x80086E84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80086E84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void audspat_debug_render_line(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A414: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000A418: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000A41C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A420: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000A424: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8000A428: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8000A42C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8000A430: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A434: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A438: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8000A43C: lwc1        $f8, 0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8000A440: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000A444: lwc1        $f16, 0x8($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8000A448: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000A44C: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8000A450: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8000A454: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000A458: nop

    // 0x8000A45C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8000A460: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A464: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A468: nop

    // 0x8000A46C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000A470: lwc1        $f8, 0x10($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8000A474: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000A478: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8000A47C: nop

    // 0x8000A480: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8000A484: nop

    // 0x8000A488: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8000A48C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A490: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A494: nop

    // 0x8000A498: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000A49C: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8000A4A0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000A4A4: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8000A4A8: nop

    // 0x8000A4AC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000A4B0: nop

    // 0x8000A4B4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8000A4B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A4BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A4C0: nop

    // 0x8000A4C4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000A4C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000A4CC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8000A4D0: nop

    // 0x8000A4D4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000A4D8: nop

    // 0x8000A4DC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000A4E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A4E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A4E8: nop

    // 0x8000A4EC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000A4F0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000A4F4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8000A4F8: nop

    // 0x8000A4FC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000A500: nop

    // 0x8000A504: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8000A508: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A50C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A510: nop

    // 0x8000A514: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000A518: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000A51C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8000A520: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8000A524: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8000A528: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8000A52C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8000A530: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000A534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000A538: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8000A53C: sh          $t0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r8;
    // 0x8000A540: sh          $t1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r9;
    // 0x8000A544: sh          $t2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r10;
    // 0x8000A548: sh          $t3, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r11;
    // 0x8000A54C: sh          $t4, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r12;
    // 0x8000A550: sh          $t5, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r13;
    // 0x8000A554: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8000A558: jal         0x8007B918
    // 0x8000A55C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    material_set_no_tex_offset(rdram, ctx);
        goto after_0;
    // 0x8000A55C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8000A560: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8000A564: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8000A568: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8000A56C: addu        $a1, $v0, $a3
    ctx->r5 = ADD32(ctx->r2, ctx->r7);
    // 0x8000A570: andi        $t6, $a1, 0x6
    ctx->r14 = ctx->r5 & 0X6;
    // 0x8000A574: ori         $t7, $t6, 0x18
    ctx->r15 = ctx->r14 | 0X18;
    // 0x8000A578: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x8000A57C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8000A580: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8000A584: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8000A588: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8000A58C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A590: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x8000A594: lh          $t1, 0x28($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X28);
    // 0x8000A598: lh          $t2, 0x26($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X26);
    // 0x8000A59C: lh          $t3, 0x24($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X24);
    // 0x8000A5A0: lh          $t4, 0x22($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X22);
    // 0x8000A5A4: lh          $t5, 0x20($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X20);
    // 0x8000A5A8: lbu         $ra, 0x4B($sp)
    ctx->r31 = MEM_BU(ctx->r29, 0X4B);
    // 0x8000A5AC: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8000A5B0: ori         $t7, $t6, 0x50
    ctx->r15 = ctx->r14 | 0X50;
    // 0x8000A5B4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8000A5B8: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x8000A5BC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8000A5C0: lui         $t6, 0x510
    ctx->r14 = S32(0X510 << 16);
    // 0x8000A5C4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8000A5C8: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8000A5CC: ori         $t6, $t6, 0x20
    ctx->r14 = ctx->r14 | 0X20;
    // 0x8000A5D0: addu        $t7, $v1, $a3
    ctx->r15 = ADD32(ctx->r3, ctx->r7);
    // 0x8000A5D4: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8000A5D8: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8000A5DC: addiu       $t8, $t1, 0x5
    ctx->r24 = ADD32(ctx->r9, 0X5);
    // 0x8000A5E0: sh          $t8, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r24;
    // 0x8000A5E4: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x8000A5E8: sh          $t2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r10;
    // 0x8000A5EC: sb          $ra, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r31;
    // 0x8000A5F0: lbu         $t9, 0x4F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4F);
    // 0x8000A5F4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8000A5F8: sb          $t9, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r25;
    // 0x8000A5FC: lbu         $a1, 0x53($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X53);
    // 0x8000A600: addiu       $t6, $t1, -0x5
    ctx->r14 = ADD32(ctx->r9, -0X5);
    // 0x8000A604: sb          $a0, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r4;
    // 0x8000A608: sh          $t6, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r14;
    // 0x8000A60C: sh          $t0, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r8;
    // 0x8000A610: sh          $t2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r10;
    // 0x8000A614: sb          $ra, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r31;
    // 0x8000A618: sb          $a1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r5;
    // 0x8000A61C: lbu         $t7, 0x4F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4F);
    // 0x8000A620: sb          $a0, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r4;
    // 0x8000A624: sb          $a0, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r4;
    // 0x8000A628: sb          $a0, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r4;
    // 0x8000A62C: sb          $a0, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r4;
    // 0x8000A630: sb          $a0, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r4;
    // 0x8000A634: sb          $a0, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r4;
    // 0x8000A638: sb          $a0, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r4;
    // 0x8000A63C: sb          $a0, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r4;
    // 0x8000A640: sb          $a0, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r4;
    // 0x8000A644: addiu       $t8, $t4, 0x5
    ctx->r24 = ADD32(ctx->r12, 0X5);
    // 0x8000A648: addiu       $t9, $t4, -0x5
    ctx->r25 = ADD32(ctx->r12, -0X5);
    // 0x8000A64C: sb          $a1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r5;
    // 0x8000A650: sh          $t8, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r24;
    // 0x8000A654: sh          $t9, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r25;
    // 0x8000A658: sh          $t3, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r11;
    // 0x8000A65C: sh          $t3, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r11;
    // 0x8000A660: sh          $t5, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r13;
    // 0x8000A664: sh          $t5, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r13;
    // 0x8000A668: sb          $t7, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r15;
    // 0x8000A66C: addiu       $a0, $zero, 0x3E0
    ctx->r4 = ADD32(0, 0X3E0);
    // 0x8000A670: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000A674: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000A678: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8000A67C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8000A680: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8000A684: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
    // 0x8000A688: sb          $a3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r7;
    // 0x8000A68C: sb          $t0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r8;
    // 0x8000A690: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x8000A694: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
    // 0x8000A698: sh          $a0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r4;
    // 0x8000A69C: sh          $a0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r4;
    // 0x8000A6A0: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x8000A6A4: sh          $a1, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r5;
    // 0x8000A6A8: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x8000A6AC: sb          $a2, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r6;
    // 0x8000A6B0: sb          $t6, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r14;
    // 0x8000A6B4: sb          $a3, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r7;
    // 0x8000A6B8: sb          $t0, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r8;
    // 0x8000A6BC: sh          $a1, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r5;
    // 0x8000A6C0: sh          $a0, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r4;
    // 0x8000A6C4: sh          $a0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r4;
    // 0x8000A6C8: sh          $a0, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r4;
    // 0x8000A6CC: sh          $a1, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r5;
    // 0x8000A6D0: sh          $zero, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = 0;
    // 0x8000A6D4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8000A6D8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8000A6DC: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x8000A6E0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8000A6E4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000A6E8: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8000A6EC: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8000A6F0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8000A6F4: nop

    // 0x8000A6F8: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x8000A6FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A700: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000A704: jr          $ra
    // 0x8000A708: nop

    return;
    // 0x8000A708: nop

;}
RECOMP_FUNC void enable_tracks_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C808: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C80C: jr          $ra
    // 0x8009C810: sw          $a0, -0x5C8($at)
    MEM_W(-0X5C8, ctx->r1) = ctx->r4;
    return;
    // 0x8009C810: sw          $a0, -0x5C8($at)
    MEM_W(-0X5C8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void disable_new_screen_transitions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C06A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C06A4: jr          $ra
    // 0x800C06A8: sw          $zero, 0x3730($at)
    MEM_W(0X3730, ctx->r1) = 0;
    return;
    // 0x800C06A8: sw          $zero, 0x3730($at)
    MEM_W(0X3730, ctx->r1) = 0;
;}
RECOMP_FUNC void alSaveParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCA40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CCA44: beq         $a1, $at, L_800CCA60
    if (ctx->r5 == ctx->r1) {
        // 0x800CCA48: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CCA60;
    }
    // 0x800CCA48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CCA4C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800CCA50: beql        $a1, $at, L_800CCA6C
    if (ctx->r5 == ctx->r1) {
        // 0x800CCA54: sw          $a2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r6;
            goto L_800CCA6C;
    }
    goto skip_0;
    // 0x800CCA54: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    skip_0:
    // 0x800CCA58: jr          $ra
    // 0x800CCA5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CCA5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CCA60:
    // 0x800CCA60: jr          $ra
    // 0x800CCA64: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    return;
    // 0x800CCA64: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x800CCA68: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
L_800CCA6C:
    // 0x800CCA6C: jr          $ra
    // 0x800CCA70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CCA70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void obj_loop_dooropener(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037D48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80037D4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037D50: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80037D54: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80037D58: jal         0x8001F494
    // 0x80037D5C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80037D5C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x80037D60: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80037D64: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80037D68: lh          $t9, 0x2A($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2A);
    // 0x80037D6C: subu        $a0, $t7, $v0
    ctx->r4 = SUB32(ctx->r15, ctx->r2);
    // 0x80037D70: blez        $t9, L_80037D7C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80037D74: nop
    
            goto L_80037D7C;
    }
    // 0x80037D74: nop

    // 0x80037D78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80037D7C:
    // 0x80037D7C: jal         0x80023604
    // 0x80037D80: nop

    obj_door_open(rdram, ctx);
        goto after_1;
    // 0x80037D80: nop

    after_1:
    // 0x80037D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037D88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80037D8C: jr          $ra
    // 0x80037D90: nop

    return;
    // 0x80037D90: nop

;}
RECOMP_FUNC void alCSPGetState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7FB0: jr          $ra
    // 0x800C7FB4: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    return;
    // 0x800C7FB4: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
;}
RECOMP_FUNC void alCSPSetFadeIn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063DE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063DE4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80063DE8: lbu         $t9, 0x33($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X33);
    // 0x80063DEC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80063DF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063DF4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80063DF8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80063DFC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80063E00: ori         $t7, $a3, 0xB0
    ctx->r15 = ctx->r7 | 0XB0;
    // 0x80063E04: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80063E08: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80063E0C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80063E10: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80063E14: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x80063E18: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063E1C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80063E20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80063E24: jal         0x800C970C
    // 0x80063E28: sb          $t9, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r25;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80063E28: sb          $t9, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r25;
    after_0:
    // 0x80063E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063E30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80063E34: jr          $ra
    // 0x80063E38: nop

    return;
    // 0x80063E38: nop

;}
RECOMP_FUNC void get_racer_objects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BAA8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001BAAC: lw          $t6, -0x4B90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B90);
    // 0x8001BAB0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BAB4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BAB8: lw          $v0, -0x4B9C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4B9C);
    // 0x8001BABC: jr          $ra
    // 0x8001BAC0: nop

    return;
    // 0x8001BAC0: nop

;}
RECOMP_FUNC void fileselect_input_copy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DD74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008DD78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DD7C: jal         0x8006ECD0
    // 0x8008DD80: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8008DD80: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008DD84: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008DD88: jal         0x8006A794
    // 0x8008DD8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8008DD8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8008DD90: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008DD94: lw          $t6, -0x5C4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C4);
    // 0x8008DD98: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008DD9C: lb          $a1, 0x69FC($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X69FC);
    // 0x8008DDA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008DDA4: bne         $t6, $at, L_8008DDD4
    if (ctx->r14 != ctx->r1) {
        // 0x8008DDA8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008DDD4;
    }
    // 0x8008DDA8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008DDAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008DDB0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8008DDB4: jal         0x8006A794
    // 0x8008DDB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    input_pressed(rdram, ctx);
        goto after_2;
    // 0x8008DDB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x8008DDBC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008DDC0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8008DDC4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008DDC8: lb          $t7, 0x69FD($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X69FD);
    // 0x8008DDCC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008DDD0: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
L_8008DDD4:
    // 0x8008DDD4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DDD8: lw          $v0, 0x6A34($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A34);
    // 0x8008DDDC: andi        $t8, $v1, 0x4000
    ctx->r24 = ctx->r3 & 0X4000;
    // 0x8008DDE0: bne         $v0, $zero, L_8008DEF0
    if (ctx->r2 != 0) {
        // 0x8008DDE4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008DEF0;
    }
    // 0x8008DDE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008DDE8: beq         $t8, $zero, L_8008DE08
    if (ctx->r24 == 0) {
        // 0x8008DDEC: andi        $t9, $v1, 0x9000
        ctx->r25 = ctx->r3 & 0X9000;
            goto L_8008DE08;
    }
    // 0x8008DDEC: andi        $t9, $v1, 0x9000
    ctx->r25 = ctx->r3 & 0X9000;
    // 0x8008DDF0: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008DDF4: jal         0x80001D04
    // 0x8008DDF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x8008DDF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8008DDFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DE00: b           L_8008E124
    // 0x8008DE04: sw          $zero, 0x6A24($at)
    MEM_W(0X6A24, ctx->r1) = 0;
        goto L_8008E124;
    // 0x8008DE04: sw          $zero, 0x6A24($at)
    MEM_W(0X6A24, ctx->r1) = 0;
L_8008DE08:
    // 0x8008DE08: beq         $t9, $zero, L_8008DEA0
    if (ctx->r25 == 0) {
        // 0x8008DE0C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8008DEA0;
    }
    // 0x8008DE0C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DE10: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DE14: addiu       $v0, $v0, 0x6A2C
    ctx->r2 = ADD32(ctx->r2, 0X6A2C);
    // 0x8008DE18: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8008DE1C: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8008DE20: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008DE24: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008DE28: addiu       $t0, $t0, 0x6A40
    ctx->r8 = ADD32(ctx->r8, 0X6A40);
    // 0x8008DE2C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008DE30: mflo        $t2
    ctx->r10 = lo;
    // 0x8008DE34: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8008DE38: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x8008DE3C: nop

    // 0x8008DE40: beq         $t4, $zero, L_8008DE8C
    if (ctx->r12 == 0) {
        // 0x8008DE44: nop
    
            goto L_8008DE8C;
    }
    // 0x8008DE44: nop

    // 0x8008DE48: jal         0x80001D04
    // 0x8008DE4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8008DE4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8008DE50: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DE54: addiu       $v0, $v0, 0x6A2C
    ctx->r2 = ADD32(ctx->r2, 0X6A2C);
    // 0x8008DE58: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8008DE5C: jal         0x8006EDB8
    // 0x8008DE60: nop

    mark_read_save_file(rdram, ctx);
        goto after_5;
    // 0x8008DE60: nop

    after_5:
    // 0x8008DE64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DE68: addiu       $v0, $v0, 0x6A2C
    ctx->r2 = ADD32(ctx->r2, 0X6A2C);
    // 0x8008DE6C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8008DE70: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DE74: addiu       $a2, $a2, 0x6A30
    ctx->r6 = ADD32(ctx->r6, 0X6A30);
    // 0x8008DE78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008DE7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DE80: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8008DE84: b           L_8008E124
    // 0x8008DE88: sw          $t6, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = ctx->r14;
        goto L_8008E124;
    // 0x8008DE88: sw          $t6, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = ctx->r14;
L_8008DE8C:
    // 0x8008DE8C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008DE90: jal         0x80001D04
    // 0x8008DE94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8008DE94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8008DE98: b           L_8008E128
    // 0x8008DE9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008E128;
    // 0x8008DE9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DEA0:
    // 0x8008DEA0: addiu       $v0, $v0, 0x6A2C
    ctx->r2 = ADD32(ctx->r2, 0X6A2C);
    // 0x8008DEA4: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8008DEA8: bgez        $a1, L_8008DEC0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8008DEAC: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_8008DEC0;
    }
    // 0x8008DEAC: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8008DEB0: blez        $a2, L_8008DEC0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008DEB4: addiu       $t7, $a2, -0x1
        ctx->r15 = ADD32(ctx->r6, -0X1);
            goto L_8008DEC0;
    }
    // 0x8008DEB4: addiu       $t7, $a2, -0x1
    ctx->r15 = ADD32(ctx->r6, -0X1);
    // 0x8008DEB8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8008DEBC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_8008DEC0:
    // 0x8008DEC0: blez        $a1, L_8008DED8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8008DEC4: slti        $at, $a2, 0x2
        ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
            goto L_8008DED8;
    }
    // 0x8008DEC4: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8008DEC8: beq         $at, $zero, L_8008DED8
    if (ctx->r1 == 0) {
        // 0x8008DECC: addiu       $t8, $a2, 0x1
        ctx->r24 = ADD32(ctx->r6, 0X1);
            goto L_8008DED8;
    }
    // 0x8008DECC: addiu       $t8, $a2, 0x1
    ctx->r24 = ADD32(ctx->r6, 0X1);
    // 0x8008DED0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8008DED4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
L_8008DED8:
    // 0x8008DED8: beq         $v1, $a2, L_8008E124
    if (ctx->r3 == ctx->r6) {
        // 0x8008DEDC: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8008E124;
    }
    // 0x8008DEDC: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008DEE0: jal         0x80001D04
    // 0x8008DEE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x8008DEE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8008DEE8: b           L_8008E128
    // 0x8008DEEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008E128;
    // 0x8008DEEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DEF0:
    // 0x8008DEF0: bne         $v0, $at, L_8008DFF0
    if (ctx->r2 != ctx->r1) {
        // 0x8008DEF4: andi        $t1, $v1, 0x9000
        ctx->r9 = ctx->r3 & 0X9000;
            goto L_8008DFF0;
    }
    // 0x8008DEF4: andi        $t1, $v1, 0x9000
    ctx->r9 = ctx->r3 & 0X9000;
    // 0x8008DEF8: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x8008DEFC: beq         $t9, $zero, L_8008DF30
    if (ctx->r25 == 0) {
        // 0x8008DF00: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8008DF30;
    }
    // 0x8008DF00: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008DF04: jal         0x80001D04
    // 0x8008DF08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x8008DF08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8008DF0C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DF10: addiu       $a2, $a2, 0x6A30
    ctx->r6 = ADD32(ctx->r6, 0X6A30);
    // 0x8008DF14: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8008DF18: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DF1C: addiu       $v0, $v0, 0x6A2C
    ctx->r2 = ADD32(ctx->r2, 0X6A2C);
    // 0x8008DF20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DF24: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8008DF28: b           L_8008E124
    // 0x8008DF2C: sw          $zero, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = 0;
        goto L_8008E124;
    // 0x8008DF2C: sw          $zero, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = 0;
L_8008DF30:
    // 0x8008DF30: andi        $t2, $v1, 0x9000
    ctx->r10 = ctx->r3 & 0X9000;
    // 0x8008DF34: beq         $t2, $zero, L_8008DF9C
    if (ctx->r10 == 0) {
        // 0x8008DF38: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8008DF9C;
    }
    // 0x8008DF38: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DF3C: addiu       $a2, $a2, 0x6A30
    ctx->r6 = ADD32(ctx->r6, 0X6A30);
    // 0x8008DF40: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8008DF44: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8008DF48: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008DF4C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008DF50: addiu       $t0, $t0, 0x6A40
    ctx->r8 = ADD32(ctx->r8, 0X6A40);
    // 0x8008DF54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008DF58: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008DF5C: mflo        $t4
    ctx->r12 = lo;
    // 0x8008DF60: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8008DF64: lbu         $t6, 0x1($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X1);
    // 0x8008DF68: nop

    // 0x8008DF6C: bne         $t6, $zero, L_8008DF8C
    if (ctx->r14 != 0) {
        // 0x8008DF70: nop
    
            goto L_8008DF8C;
    }
    // 0x8008DF70: nop

    // 0x8008DF74: jal         0x80001D04
    // 0x8008DF78: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    sound_play(rdram, ctx);
        goto after_9;
    // 0x8008DF78: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    after_9:
    // 0x8008DF7C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8008DF80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DF84: b           L_8008E124
    // 0x8008DF88: sw          $t7, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = ctx->r15;
        goto L_8008E124;
    // 0x8008DF88: sw          $t7, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = ctx->r15;
L_8008DF8C:
    // 0x8008DF8C: jal         0x80001D04
    // 0x8008DF90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x8008DF90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8008DF94: b           L_8008E128
    // 0x8008DF98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008E128;
    // 0x8008DF98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DF9C:
    // 0x8008DF9C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DFA0: addiu       $a2, $a2, 0x6A30
    ctx->r6 = ADD32(ctx->r6, 0X6A30);
    // 0x8008DFA4: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8008DFA8: bgez        $a1, L_8008DFC0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8008DFAC: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_8008DFC0;
    }
    // 0x8008DFAC: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8008DFB0: blez        $a3, L_8008DFC0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8008DFB4: addiu       $t8, $a3, -0x1
        ctx->r24 = ADD32(ctx->r7, -0X1);
            goto L_8008DFC0;
    }
    // 0x8008DFB4: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
    // 0x8008DFB8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8008DFBC: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
L_8008DFC0:
    // 0x8008DFC0: blez        $a1, L_8008DFD8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8008DFC4: slti        $at, $a3, 0x2
        ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
            goto L_8008DFD8;
    }
    // 0x8008DFC4: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x8008DFC8: beq         $at, $zero, L_8008DFD8
    if (ctx->r1 == 0) {
        // 0x8008DFCC: addiu       $t9, $a3, 0x1
        ctx->r25 = ADD32(ctx->r7, 0X1);
            goto L_8008DFD8;
    }
    // 0x8008DFCC: addiu       $t9, $a3, 0x1
    ctx->r25 = ADD32(ctx->r7, 0X1);
    // 0x8008DFD0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8008DFD4: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
L_8008DFD8:
    // 0x8008DFD8: beq         $v1, $a3, L_8008E124
    if (ctx->r3 == ctx->r7) {
        // 0x8008DFDC: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8008E124;
    }
    // 0x8008DFDC: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008DFE0: jal         0x80001D04
    // 0x8008DFE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_11;
    // 0x8008DFE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x8008DFE8: b           L_8008E128
    // 0x8008DFEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008E128;
    // 0x8008DFEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DFF0:
    // 0x8008DFF0: beq         $t1, $zero, L_8008E104
    if (ctx->r9 == 0) {
        // 0x8008DFF4: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008E104;
    }
    // 0x8008DFF4: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008DFF8: jal         0x80001D04
    // 0x8008DFFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_12;
    // 0x8008DFFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8008E000: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008E004: addiu       $a2, $a2, 0x6A30
    ctx->r6 = ADD32(ctx->r6, 0X6A30);
    // 0x8008E008: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8008E00C: jal         0x8006EE58
    // 0x8008E010: nop

    force_mark_write_save_file(rdram, ctx);
        goto after_13;
    // 0x8008E010: nop

    after_13:
    // 0x8008E014: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008E018: addiu       $a2, $a2, 0x6A30
    ctx->r6 = ADD32(ctx->r6, 0X6A30);
    // 0x8008E01C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8008E020: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8008E024: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008E028: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008E02C: addiu       $t0, $t0, 0x6A40
    ctx->r8 = ADD32(ctx->r8, 0X6A40);
    // 0x8008E030: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8008E034: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008E038: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x8008E03C: subu        $t1, $t1, $a3
    ctx->r9 = SUB32(ctx->r9, ctx->r7);
    // 0x8008E040: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008E044: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E048: mflo        $t2
    ctx->r10 = lo;
    // 0x8008E04C: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x8008E050: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008E054: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x8008E058: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8008E05C: nop

    // 0x8008E060: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8008E064: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x8008E068: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    // 0x8008E06C: lw          $t5, 0x10($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X10);
    // 0x8008E070: subu        $t3, $t3, $a3
    ctx->r11 = SUB32(ctx->r11, ctx->r7);
    // 0x8008E074: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x8008E078: beq         $t6, $zero, L_8008E084
    if (ctx->r14 == 0) {
        // 0x8008E07C: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_8008E084;
    }
    // 0x8008E07C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008E080: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
L_8008E084:
    // 0x8008E084: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008E088: addiu       $v0, $v0, 0x6A2C
    ctx->r2 = ADD32(ctx->r2, 0X6A2C);
    // 0x8008E08C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8008E090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008E094: multu       $a2, $v1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008E098: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8008E09C: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x8008E0A0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008E0A4: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x8008E0A8: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8008E0AC: mflo        $t7
    ctx->r15 = lo;
    // 0x8008E0B0: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8008E0B4: lbu         $t9, 0x4($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X4);
    // 0x8008E0B8: nop

    // 0x8008E0BC: beq         $t9, $zero, L_8008E0E8
    if (ctx->r25 == 0) {
        // 0x8008E0C0: addu        $t5, $t4, $a1
        ctx->r13 = ADD32(ctx->r12, ctx->r5);
            goto L_8008E0E8;
    }
    // 0x8008E0C0: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x8008E0C4: lbu         $a0, 0x4($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X4);
    // 0x8008E0C8: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
L_8008E0CC:
    // 0x8008E0CC: sb          $a0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r4;
    // 0x8008E0D0: lbu         $a0, 0x5($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X5);
    // 0x8008E0D4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008E0D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008E0DC: bne         $a0, $zero, L_8008E0CC
    if (ctx->r4 != 0) {
        // 0x8008E0E0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008E0CC;
    }
    // 0x8008E0E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008E0E4: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
L_8008E0E8:
    // 0x8008E0E8: sb          $zero, 0x4($t5)
    MEM_B(0X4, ctx->r13) = 0;
    // 0x8008E0EC: sw          $a3, -0x5B4($at)
    MEM_W(-0X5B4, ctx->r1) = ctx->r7;
    // 0x8008E0F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E0F4: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x8008E0F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E0FC: b           L_8008E124
    // 0x8008E100: sw          $zero, 0x6A24($at)
    MEM_W(0X6A24, ctx->r1) = 0;
        goto L_8008E124;
    // 0x8008E100: sw          $zero, 0x6A24($at)
    MEM_W(0X6A24, ctx->r1) = 0;
L_8008E104:
    // 0x8008E104: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
    // 0x8008E108: beq         $t6, $zero, L_8008E124
    if (ctx->r14 == 0) {
        // 0x8008E10C: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8008E124;
    }
    // 0x8008E10C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008E110: jal         0x80001D04
    // 0x8008E114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_14;
    // 0x8008E114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x8008E118: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008E11C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E120: sw          $t7, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = ctx->r15;
L_8008E124:
    // 0x8008E124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008E128:
    // 0x8008E128: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008E12C: jr          $ra
    // 0x8008E130: nop

    return;
    // 0x8008E130: nop

;}
RECOMP_FUNC void obj_loop_lasergun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800345E0: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x800345E4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800345E8: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x800345EC: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x800345F0: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800345F4: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x800345F8: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800345FC: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80034600: lw          $s1, 0x64($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X64);
    // 0x80034604: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80034608: lh          $v0, 0xC($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XC);
    // 0x8003460C: nop

    // 0x80034610: blez        $v0, L_80034620
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80034614: subu        $t6, $v0, $a1
        ctx->r14 = SUB32(ctx->r2, ctx->r5);
            goto L_80034620;
    }
    // 0x80034614: subu        $t6, $v0, $a1
    ctx->r14 = SUB32(ctx->r2, ctx->r5);
    // 0x80034618: b           L_80034860
    // 0x8003461C: sh          $t6, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r14;
        goto L_80034860;
    // 0x8003461C: sh          $t6, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r14;
L_80034620:
    // 0x80034620: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x80034624: lbu         $t7, 0x11($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X11);
    // 0x80034628: lbu         $t8, 0x13($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X13);
    // 0x8003462C: nop

    // 0x80034630: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80034634: bne         $at, $zero, L_80034864
    if (ctx->r1 != 0) {
        // 0x80034638: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80034864;
    }
    // 0x80034638: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8003463C: lb          $t9, 0xE($s1)
    ctx->r25 = MEM_B(ctx->r17, 0XE);
    // 0x80034640: nop

    // 0x80034644: beq         $t9, $zero, L_800346FC
    if (ctx->r25 == 0) {
        // 0x80034648: nop
    
            goto L_800346FC;
    }
    // 0x80034648: nop

    // 0x8003464C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80034650: nop

    // 0x80034654: beq         $v0, $zero, L_800346FC
    if (ctx->r2 == 0) {
        // 0x80034658: nop
    
            goto L_800346FC;
    }
    // 0x80034658: nop

    // 0x8003465C: lh          $t0, 0x48($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X48);
    // 0x80034660: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80034664: bne         $t0, $at, L_800346FC
    if (ctx->r8 != ctx->r1) {
        // 0x80034668: nop
    
            goto L_800346FC;
    }
    // 0x80034668: nop

    // 0x8003466C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034670: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80034674: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034678: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003467C: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80034680: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80034684: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80034688: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003468C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80034690: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80034694: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80034698: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    // 0x8003469C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800346A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800346A4: jal         0x800CA030
    // 0x800346A8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800346A8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x800346AC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800346B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800346B4: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800346B8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800346BC: nop

    // 0x800346C0: bc1f        L_800346FC
    if (!c1cs) {
        // 0x800346C4: nop
    
            goto L_800346FC;
    }
    // 0x800346C4: nop

    // 0x800346C8: div.s       $f12, $f20, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800346CC: nop

    // 0x800346D0: div.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800346D4: jal         0x80070990
    // 0x800346D8: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    arctan2_f(rdram, ctx);
        goto after_1;
    // 0x800346D8: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    after_1:
    // 0x800346DC: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800346E0: addu        $t2, $v0, $at
    ctx->r10 = ADD32(ctx->r2, ctx->r1);
    // 0x800346E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800346E8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800346EC: sh          $t2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r10;
    // 0x800346F0: jal         0x80070990
    // 0x800346F4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x800346F4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_2:
    // 0x800346F8: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
L_800346FC:
    // 0x800346FC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80034700: lb          $t4, 0xF($s1)
    ctx->r12 = MEM_B(ctx->r17, 0XF);
    // 0x80034704: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80034708: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003470C: sh          $t4, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r12;
    // 0x80034710: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034714: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80034718: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8003471C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80034720: addiu       $t2, $zero, 0xC6
    ctx->r10 = ADD32(0, 0XC6);
    // 0x80034724: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80034728: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8003472C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80034730: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80034734: sh          $t6, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r14;
    // 0x80034738: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8003473C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80034740: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80034744: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034748: addiu       $a0, $zero, 0x133
    ctx->r4 = ADD32(0, 0X133);
    // 0x8003474C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80034750: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80034754: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80034758: nop

    // 0x8003475C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80034760: sh          $t8, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r24;
    // 0x80034764: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80034768: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003476C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80034770: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80034774: sb          $t1, 0x49($sp)
    MEM_B(0X49, ctx->r29) = ctx->r9;
    // 0x80034778: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8003477C: sb          $t2, 0x48($sp)
    MEM_B(0X48, ctx->r29) = ctx->r10;
    // 0x80034780: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80034784: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80034788: sh          $t0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r8;
    // 0x8003478C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80034790: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80034794: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80034798: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003479C: jal         0x80009558
    // 0x800347A0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_3;
    // 0x800347A0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_3:
    // 0x800347A4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800347A8: jal         0x8000EA54
    // 0x800347AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_4;
    // 0x800347AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x800347B0: beq         $v0, $zero, L_80034860
    if (ctx->r2 == 0) {
        // 0x800347B4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80034860;
    }
    // 0x800347B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800347B8: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800347BC: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x800347C0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800347C4: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x800347C8: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x800347CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800347D0: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x800347D4: lbu         $t6, 0x10($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X10);
    // 0x800347D8: sw          $s1, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r17;
    // 0x800347DC: sw          $t6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r14;
    // 0x800347E0: swc1        $f22, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f22.u32l;
    // 0x800347E4: swc1        $f22, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f22.u32l;
    // 0x800347E8: swc1        $f22, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f22.u32l;
    // 0x800347EC: swc1        $f18, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f18.u32l;
    // 0x800347F0: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800347F4: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x800347F8: sh          $t7, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = ctx->r15;
    // 0x800347FC: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x80034800: sh          $zero, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = 0;
    // 0x80034804: sw          $v0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r2;
    // 0x80034808: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x8003480C: jal         0x8006FE70
    // 0x80034810: sh          $t8, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r24;
    mtxf_from_transform(rdram, ctx);
        goto after_5;
    // 0x80034810: sh          $t8, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r24;
    after_5:
    // 0x80034814: lb          $t9, 0xE($s1)
    ctx->r25 = MEM_B(ctx->r17, 0XE);
    // 0x80034818: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8003481C: lw          $v1, 0xC0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC0);
    // 0x80034820: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80034824: bne         $t9, $zero, L_80034838
    if (ctx->r25 != 0) {
        // 0x80034828: addiu       $a0, $sp, 0x64
        ctx->r4 = ADD32(ctx->r29, 0X64);
            goto L_80034838;
    }
    // 0x80034828: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8003482C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80034830: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80034834: nop

L_80034838:
    // 0x80034838: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8003483C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80034840: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80034844: addiu       $t0, $v1, 0x1C
    ctx->r8 = ADD32(ctx->r3, 0X1C);
    // 0x80034848: addiu       $t1, $v1, 0x20
    ctx->r9 = ADD32(ctx->r3, 0X20);
    // 0x8003484C: addiu       $t2, $v1, 0x24
    ctx->r10 = ADD32(ctx->r3, 0X24);
    // 0x80034850: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80034854: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80034858: jal         0x8006F88C
    // 0x8003485C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    mtxf_transform_point(rdram, ctx);
        goto after_6;
    // 0x8003485C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_6:
L_80034860:
    // 0x80034860: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80034864:
    // 0x80034864: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80034868: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003486C: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80034870: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80034874: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80034878: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8003487C: jr          $ra
    // 0x80034880: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80034880: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void dialogue_ortho(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EEF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009EEF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009EEFC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8009EF00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009EF04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EF08: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8009EF0C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8009EF10: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8009EF14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009EF18: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8009EF1C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009EF20: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8009EF24: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009EF28: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8009EF2C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8009EF30: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8009EF34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EF38: jal         0x8006816C
    // 0x8009EF3C: sw          $t1, 0x694C($at)
    MEM_W(0X694C, ctx->r1) = ctx->r9;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x8009EF3C: sw          $t1, 0x694C($at)
    MEM_W(0X694C, ctx->r1) = ctx->r9;
    after_0:
    // 0x8009EF40: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009EF44: lb          $t2, 0x23A8($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X23A8);
    // 0x8009EF48: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009EF4C: beq         $t2, $zero, L_8009EF6C
    if (ctx->r10 == 0) {
        // 0x8009EF50: nop
    
            goto L_8009EF6C;
    }
    // 0x8009EF50: nop

    // 0x8009EF54: lb          $t3, 0x6A82($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X6A82);
    // 0x8009EF58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009EF5C: bne         $t3, $at, L_8009EF6C
    if (ctx->r11 != ctx->r1) {
        // 0x8009EF60: nop
    
            goto L_8009EF6C;
    }
    // 0x8009EF60: nop

    // 0x8009EF64: jal         0x8009E914
    // 0x8009EF68: nop

    dialogue_tt_gamestatus(rdram, ctx);
        goto after_1;
    // 0x8009EF68: nop

    after_1:
L_8009EF6C:
    // 0x8009EF6C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8009EF70: lw          $t4, 0x693C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X693C);
    // 0x8009EF74: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8009EF78: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009EF7C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8009EF80: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8009EF84: lw          $t6, 0x6944($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6944);
    // 0x8009EF88: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009EF8C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009EF90: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8009EF94: lw          $t8, 0x694C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X694C);
    // 0x8009EF98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009EF9C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8009EFA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EFA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009EFA8: jr          $ra
    // 0x8009EFAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8009EFAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void hud_stopwatch_face(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3C14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A3C18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A3C1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A3C20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A3C24: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x800A3C28: andi        $s1, $a1, 0xFF
    ctx->r17 = ctx->r5 & 0XFF;
    // 0x800A3C2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A3C30: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A3C34: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800A3C38: jal         0x8000E4D8
    // 0x800A3C3C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    is_in_time_trial(rdram, ctx);
        goto after_0;
    // 0x800A3C3C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A3C40: beq         $v0, $zero, L_800A3DA4
    if (ctx->r2 == 0) {
        // 0x800A3C44: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_800A3DA4;
    }
    // 0x800A3C44: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A3C48: lw          $t6, 0x72B4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72B4);
    // 0x800A3C4C: nop

    // 0x800A3C50: lw          $v0, 0x50($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X50);
    // 0x800A3C54: nop

    // 0x800A3C58: beq         $v0, $zero, L_800A3DA8
    if (ctx->r2 == 0) {
        // 0x800A3C5C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A3DA8;
    }
    // 0x800A3C5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A3C60: lw          $t7, 0x68($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X68);
    // 0x800A3C64: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x800A3C68: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x800A3C6C: addiu       $ra, $ra, 0x7325
    ctx->r31 = ADD32(ctx->r31, 0X7325);
    // 0x800A3C70: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800A3C74: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A3C78: lh          $a3, 0x28($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X28);
    // 0x800A3C7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A3C80: blez        $a3, L_800A3D68
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800A3C84: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800A3D68;
    }
    // 0x800A3C84: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A3C88: lui         $t4, 0xFF7E
    ctx->r12 = S32(0XFF7E << 16);
    // 0x800A3C8C: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x800A3C90: addiu       $t5, $t5, 0x7326
    ctx->r13 = ADD32(ctx->r13, 0X7326);
    // 0x800A3C94: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A3C98: lui         $t2, 0x81
    ctx->r10 = S32(0X81 << 16);
    // 0x800A3C9C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_800A3CA0:
    // 0x800A3CA0: lw          $t8, 0x38($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X38);
    // 0x800A3CA4: lbu         $t9, 0x0($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X0);
    // 0x800A3CA8: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x800A3CAC: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x800A3CB0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800A3CB4: bne         $t9, $a2, L_800A3D38
    if (ctx->r25 != ctx->r6) {
        // 0x800A3CB8: nop
    
            goto L_800A3D38;
    }
    // 0x800A3CB8: nop

    // 0x800A3CBC: bne         $t1, $s0, L_800A3CF4
    if (ctx->r9 != ctx->r16) {
        // 0x800A3CC0: sb          $s0, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r16;
            goto L_800A3CF4;
    }
    // 0x800A3CC0: sb          $s0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r16;
    // 0x800A3CC4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800A3CC8: nop

    // 0x800A3CCC: lw          $t7, 0x38($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X38);
    // 0x800A3CD0: nop

    // 0x800A3CD4: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x800A3CD8: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x800A3CDC: nop

    // 0x800A3CE0: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x800A3CE4: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x800A3CE8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800A3CEC: b           L_800A3D24
    // 0x800A3CF0: sh          $t3, 0x50($t6)
    MEM_H(0X50, ctx->r14) = ctx->r11;
        goto L_800A3D24;
    // 0x800A3CF0: sh          $t3, 0x50($t6)
    MEM_H(0X50, ctx->r14) = ctx->r11;
L_800A3CF4:
    // 0x800A3CF4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A3CF8: nop

    // 0x800A3CFC: lw          $t8, 0x38($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X38);
    // 0x800A3D00: nop

    // 0x800A3D04: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x800A3D08: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x800A3D0C: nop

    // 0x800A3D10: and         $t6, $t9, $t4
    ctx->r14 = ctx->r25 & ctx->r12;
    // 0x800A3D14: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x800A3D18: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A3D1C: nop

    // 0x800A3D20: sh          $zero, 0x50($t7)
    MEM_H(0X50, ctx->r15) = 0;
L_800A3D24:
    // 0x800A3D24: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800A3D28: nop

    // 0x800A3D2C: lh          $a3, 0x28($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X28);
    // 0x800A3D30: b           L_800A3D60
    // 0x800A3D34: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
        goto L_800A3D60;
    // 0x800A3D34: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
L_800A3D38:
    // 0x800A3D38: lbu         $t8, 0x0($ra)
    ctx->r24 = MEM_BU(ctx->r31, 0X0);
    // 0x800A3D3C: nop

    // 0x800A3D40: bne         $t8, $a2, L_800A3D60
    if (ctx->r24 != ctx->r6) {
        // 0x800A3D44: slt         $at, $t0, $a3
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800A3D60;
    }
    // 0x800A3D44: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800A3D48: sb          $s1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r17;
    // 0x800A3D4C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800A3D50: nop

    // 0x800A3D54: lh          $a3, 0x28($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X28);
    // 0x800A3D58: nop

    // 0x800A3D5C: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
L_800A3D60:
    // 0x800A3D60: bne         $at, $zero, L_800A3CA0
    if (ctx->r1 != 0) {
        // 0x800A3D64: addiu       $a0, $a0, 0xC
        ctx->r4 = ADD32(ctx->r4, 0XC);
            goto L_800A3CA0;
    }
    // 0x800A3D64: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
L_800A3D68:
    // 0x800A3D68: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A3D6C: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x800A3D70: lbu         $t9, 0x2B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2B);
    // 0x800A3D74: addiu       $ra, $ra, 0x7325
    ctx->r31 = ADD32(ctx->r31, 0X7325);
    // 0x800A3D78: addiu       $t5, $t5, 0x7326
    ctx->r13 = ADD32(ctx->r13, 0X7326);
    // 0x800A3D7C: sb          $s0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r16;
    // 0x800A3D80: sb          $s1, 0x0($ra)
    MEM_B(0X0, ctx->r31) = ctx->r17;
    // 0x800A3D84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A3D88: lbu         $t6, 0x2F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2F);
    // 0x800A3D8C: sb          $t9, 0x7327($at)
    MEM_B(0X7327, ctx->r1) = ctx->r25;
    // 0x800A3D90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A3D94: lbu         $t7, 0x33($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X33);
    // 0x800A3D98: sb          $t6, 0x7329($at)
    MEM_B(0X7329, ctx->r1) = ctx->r14;
    // 0x800A3D9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A3DA0: sb          $t7, 0x7328($at)
    MEM_B(0X7328, ctx->r1) = ctx->r15;
L_800A3DA4:
    // 0x800A3DA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A3DA8:
    // 0x800A3DA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A3DAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A3DB0: jr          $ra
    // 0x800A3DB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A3DB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void music_voicelimit_change_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000C30: jr          $ra
    // 0x80000C34: sb          $zero, -0x3420($at)
    MEM_B(-0X3420, ctx->r1) = 0;
    return;
    // 0x80000C34: sb          $zero, -0x3420($at)
    MEM_B(-0X3420, ctx->r1) = 0;
;}
RECOMP_FUNC void mode_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F67C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006F680: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006F684: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006F688: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006F68C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006F690: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006F694: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006F698: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_8006F69C:
    // 0x8006F69C: jal         0x8006A768
    // 0x8006F6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    input_held(rdram, ctx);
        goto after_0;
    // 0x8006F6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006F6A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006F6A8: bne         $s0, $s2, L_8006F69C
    if (ctx->r16 != ctx->r18) {
        // 0x8006F6AC: or          $s1, $s1, $v0
        ctx->r17 = ctx->r17 | ctx->r2;
            goto L_8006F69C;
    }
    // 0x8006F6AC: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
    // 0x8006F6B0: andi        $t6, $s1, 0x1000
    ctx->r14 = ctx->r17 & 0X1000;
    // 0x8006F6B4: beq         $t6, $zero, L_8006F6C8
    if (ctx->r14 == 0) {
        // 0x8006F6B8: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8006F6C8;
    }
    // 0x8006F6B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006F6BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006F6C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F6C4: sw          $t7, 0x314($at)
    MEM_W(0X314, ctx->r1) = ctx->r15;
L_8006F6C8:
    // 0x8006F6C8: addiu       $v0, $v0, 0x3AA0
    ctx->r2 = ADD32(ctx->r2, 0X3AA0);
    // 0x8006F6CC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8006F6D0: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x8006F6D4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8006F6D8: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x8006F6DC: bne         $at, $zero, L_8006F6F0
    if (ctx->r1 != 0) {
        // 0x8006F6E0: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_8006F6F0;
    }
    // 0x8006F6E0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8006F6E4: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    // 0x8006F6E8: jal         0x8006DC68
    // 0x8006F6EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    load_menu_with_level_background(rdram, ctx);
        goto after_1;
    // 0x8006F6EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
L_8006F6F0:
    // 0x8006F6F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006F6F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006F6F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F6FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006F700: jr          $ra
    // 0x8006F704: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006F704: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80026430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026470: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x80026474: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80026478: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002647C: lh          $t7, -0x25C6($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X25C6);
    // 0x80026480: lh          $t6, -0x25E2($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X25E2);
    // 0x80026484: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x80026488: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8002648C: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80026490: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x80026494: mtc1        $a1, $f26
    ctx->f26.u32l = ctx->r5;
    // 0x80026498: mtc1        $a3, $f28
    ctx->f28.u32l = ctx->r7;
    // 0x8002649C: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800264A0: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800264A4: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800264A8: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800264AC: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x800264B0: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x800264B4: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800264B8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800264BC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800264C0: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800264C4: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800264C8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800264CC: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800264D0: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x800264D4: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800264D8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800264DC: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800264E0: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800264E4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800264E8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800264EC: beq         $at, $zero, L_80026BF4
    if (ctx->r1 == 0) {
        // 0x800264F0: swc1        $f20, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
            goto L_80026BF4;
    }
    // 0x800264F0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800264F4: sh          $zero, 0x10E($sp)
    MEM_H(0X10E, ctx->r29) = 0;
    // 0x800264F8: lh          $a0, 0x20($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X20);
    // 0x800264FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80026500: blez        $a0, L_80026BF4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80026504: addiu       $fp, $sp, 0xB8
        ctx->r30 = ADD32(ctx->r29, 0XB8);
            goto L_80026BF4;
    }
    // 0x80026504: addiu       $fp, $sp, 0xB8
    ctx->r30 = ADD32(ctx->r29, 0XB8);
    // 0x80026508: lwc1        $f31, 0x6408($at)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r1, 0X6408);
    // 0x8002650C: lwc1        $f30, 0x640C($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X640C);
    // 0x80026510: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x80026514: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80026518: addiu       $s5, $sp, 0xD0
    ctx->r21 = ADD32(ctx->r29, 0XD0);
    // 0x8002651C: addiu       $s4, $sp, 0xDC
    ctx->r20 = ADD32(ctx->r29, 0XDC);
    // 0x80026520: addiu       $s3, $sp, 0xE8
    ctx->r19 = ADD32(ctx->r29, 0XE8);
    // 0x80026524: addiu       $s2, $sp, 0xF8
    ctx->r18 = ADD32(ctx->r29, 0XF8);
    // 0x80026528: addiu       $s1, $sp, 0xC4
    ctx->r17 = ADD32(ctx->r29, 0XC4);
    // 0x8002652C: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80026530: addiu       $t5, $sp, 0xA8
    ctx->r13 = ADD32(ctx->r29, 0XA8);
    // 0x80026534: addiu       $t4, $sp, 0xA0
    ctx->r12 = ADD32(ctx->r29, 0XA0);
    // 0x80026538: addiu       $t3, $sp, 0xB0
    ctx->r11 = ADD32(ctx->r29, 0XB0);
    // 0x8002653C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
L_80026540:
    // 0x80026540: lh          $t9, 0x10E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X10E);
    // 0x80026544: lw          $t8, 0xC($s6)
    ctx->r24 = MEM_W(ctx->r22, 0XC);
    // 0x80026548: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8002654C: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80026550: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80026554: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x80026558: lh          $t7, 0x10($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X10);
    // 0x8002655C: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80026560: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80026564: sh          $t7, 0x108($sp)
    MEM_H(0X108, ctx->r29) = ctx->r15;
    // 0x80026568: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8002656C: lh          $t7, 0x108($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X108);
    // 0x80026570: andi        $t8, $t9, 0x300
    ctx->r24 = ctx->r25 & 0X300;
    // 0x80026574: beq         $t8, $zero, L_80026588
    if (ctx->r24 == 0) {
        // 0x80026578: sll         $s7, $v1, 16
        ctx->r23 = S32(ctx->r3 << 16);
            goto L_80026588;
    }
    // 0x80026578: sll         $s7, $v1, 16
    ctx->r23 = S32(ctx->r3 << 16);
    // 0x8002657C: lh          $v1, 0x108($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X108);
    // 0x80026580: nop

    // 0x80026584: sll         $s7, $v1, 16
    ctx->r23 = S32(ctx->r3 << 16);
L_80026588:
    // 0x80026588: sra         $t6, $s7, 16
    ctx->r14 = S32(SIGNED(ctx->r23) >> 16);
    // 0x8002658C: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80026590: beq         $at, $zero, L_80026BD4
    if (ctx->r1 == 0) {
        // 0x80026594: or          $s7, $t6, $zero
        ctx->r23 = ctx->r14 | 0;
            goto L_80026BD4;
    }
    // 0x80026594: or          $s7, $t6, $zero
    ctx->r23 = ctx->r14 | 0;
L_80026598:
    // 0x80026598: lw          $t9, 0x4($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X4);
    // 0x8002659C: sll         $t8, $s7, 4
    ctx->r24 = S32(ctx->r23 << 4);
    // 0x800265A0: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x800265A4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800265A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800265AC: andi        $t9, $t7, 0x40
    ctx->r25 = ctx->r15 & 0X40;
    // 0x800265B0: bne         $t9, $zero, L_80026BB0
    if (ctx->r25 != 0) {
        // 0x800265B4: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80026BB0;
    }
    // 0x800265B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800265B8:
    // 0x800265B8: lw          $t8, 0x4($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X4);
    // 0x800265BC: sll         $t6, $s7, 4
    ctx->r14 = S32(ctx->r23 << 4);
    // 0x800265C0: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800265C4: addu        $t9, $t7, $a3
    ctx->r25 = ADD32(ctx->r15, ctx->r7);
    // 0x800265C8: lbu         $t8, 0x1($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X1);
    // 0x800265CC: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x800265D0: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800265D4: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800265D8: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x800265DC: addu        $a0, $s3, $v0
    ctx->r4 = ADD32(ctx->r19, ctx->r2);
    // 0x800265E0: addu        $a1, $s5, $v0
    ctx->r5 = ADD32(ctx->r21, ctx->r2);
    // 0x800265E4: addu        $a2, $s2, $a3
    ctx->r6 = ADD32(ctx->r18, ctx->r7);
    // 0x800265E8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800265EC: mflo        $t7
    ctx->r15 = lo;
    // 0x800265F0: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x800265F4: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800265F8: addu        $t7, $s4, $v0
    ctx->r15 = ADD32(ctx->r20, ctx->r2);
    // 0x800265FC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80026600: addu        $t8, $s1, $v0
    ctx->r24 = ADD32(ctx->r17, ctx->r2);
    // 0x80026604: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026608: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8002660C: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x80026610: nop

    // 0x80026614: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80026618: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8002661C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80026620: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x80026624: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x80026628: nop

    // 0x8002662C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80026630: nop

    // 0x80026634: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026638: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002663C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80026640: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80026644: nop

    // 0x80026648: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x8002664C: nop

    // 0x80026650: mul.s       $f6, $f26, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x80026654: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80026658: add.s       $f0, $f8, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x8002665C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80026660: c.le.d      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.d <= ctx->f20.d;
    // 0x80026664: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x80026668: bc1f        L_80026674
    if (!c1cs) {
        // 0x8002666C: nop
    
            goto L_80026674;
    }
    // 0x8002666C: nop

    // 0x80026670: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80026674:
    // 0x80026674: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80026678: lb          $t7, 0x0($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X0);
    // 0x8002667C: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x80026680: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80026684: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80026688: cvt.d.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.d = CVT_D_W(ctx->f10.u32l);
    // 0x8002668C: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80026690: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x80026694: c.le.d      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.d <= ctx->f20.d;
    // 0x80026698: nop

    // 0x8002669C: bc1f        L_800266A8
    if (!c1cs) {
        // 0x800266A0: nop
    
            goto L_800266A8;
    }
    // 0x800266A0: nop

    // 0x800266A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800266A8:
    // 0x800266A8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800266AC: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x800266B0: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800266B4: bne         $at, $zero, L_800265B8
    if (ctx->r1 != 0) {
        // 0x800266B8: or          $t0, $t6, $zero
        ctx->r8 = ctx->r14 | 0;
            goto L_800265B8;
    }
    // 0x800266B8: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x800266BC: beq         $t6, $ra, L_800266C8
    if (ctx->r14 == ctx->r31) {
        // 0x800266C0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800266C8;
    }
    // 0x800266C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800266C4: bne         $t6, $at, L_80026BB0
    if (ctx->r14 != ctx->r1) {
        // 0x800266C8: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80026BB0;
    }
L_800266C8:
    // 0x800266C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800266CC: lwc1        $f8, -0x25DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X25DC);
    // 0x800266D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800266D4: lwc1        $f4, -0x25E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X25E0);
    // 0x800266D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800266DC: lwc1        $f22, -0x25D8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X25D8);
    // 0x800266E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800266E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800266E8: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x800266EC: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
L_800266F0:
    // 0x800266F0: addiu       $a2, $a3, 0x1
    ctx->r6 = ADD32(ctx->r7, 0X1);
    // 0x800266F4: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800266F8: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x800266FC: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80026700: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80026704: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80026708: bne         $at, $zero, L_80026714
    if (ctx->r1 != 0) {
        // 0x8002670C: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_80026714;
    }
    // 0x8002670C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80026710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80026714:
    // 0x80026714: addu        $t9, $s2, $a1
    ctx->r25 = ADD32(ctx->r18, ctx->r5);
    // 0x80026718: addu        $t6, $s2, $a3
    ctx->r14 = ADD32(ctx->r18, ctx->r7);
    // 0x8002671C: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x80026720: lb          $t8, 0x0($t9)
    ctx->r24 = MEM_B(ctx->r25, 0X0);
    // 0x80026724: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x80026728: beq         $t8, $t7, L_800267CC
    if (ctx->r24 == ctx->r15) {
        // 0x8002672C: addu        $t6, $s1, $v0
        ctx->r14 = ADD32(ctx->r17, ctx->r2);
            goto L_800267CC;
    }
    // 0x8002672C: addu        $t6, $s1, $v0
    ctx->r14 = ADD32(ctx->r17, ctx->r2);
    // 0x80026730: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x80026734: addu        $t8, $s1, $v1
    ctx->r24 = ADD32(ctx->r17, ctx->r3);
    // 0x80026738: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8002673C: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80026740: addu        $t9, $s3, $v1
    ctx->r25 = ADD32(ctx->r19, ctx->r3);
    // 0x80026744: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80026748: addu        $t7, $s3, $v0
    ctx->r15 = ADD32(ctx->r19, ctx->r2);
    // 0x8002674C: div.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80026750: lwc1        $f2, 0x0($t7)
    ctx->f2.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80026754: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80026758: sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16 << 2);
    // 0x8002675C: sub.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80026760: addu        $t6, $t3, $a0
    ctx->r14 = ADD32(ctx->r11, ctx->r4);
    // 0x80026764: addu        $t7, $s4, $v1
    ctx->r15 = ADD32(ctx->r20, ctx->r3);
    // 0x80026768: addu        $t8, $s4, $v0
    ctx->r24 = ADD32(ctx->r20, ctx->r2);
    // 0x8002676C: addu        $t9, $fp, $a0
    ctx->r25 = ADD32(ctx->r30, ctx->r4);
    // 0x80026770: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80026774: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80026778: add.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8002677C: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x80026780: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80026784: lwc1        $f12, 0x0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80026788: addu        $t6, $t4, $a0
    ctx->r14 = ADD32(ctx->r12, ctx->r4);
    // 0x8002678C: sub.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x80026790: addu        $t8, $s5, $v0
    ctx->r24 = ADD32(ctx->r21, ctx->r2);
    // 0x80026794: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80026798: addu        $t7, $s5, $v1
    ctx->r15 = ADD32(ctx->r21, ctx->r3);
    // 0x8002679C: add.s       $f14, $f10, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800267A0: swc1        $f14, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f14.u32l;
    // 0x800267A4: swc1        $f14, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f14.u32l;
    // 0x800267A8: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800267AC: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800267B0: addu        $t9, $t5, $a0
    ctx->r25 = ADD32(ctx->r13, ctx->r4);
    // 0x800267B4: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800267B8: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x800267BC: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800267C0: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800267C4: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800267C8: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
L_800267CC:
    // 0x800267CC: sll         $a3, $a2, 16
    ctx->r7 = S32(ctx->r6 << 16);
    // 0x800267D0: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800267D4: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x800267D8: bne         $at, $zero, L_800266F0
    if (ctx->r1 != 0) {
        // 0x800267DC: or          $a3, $t7, $zero
        ctx->r7 = ctx->r15 | 0;
            goto L_800266F0;
    }
    // 0x800267DC: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800267E0: lwc1        $f14, 0x98($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800267E4: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800267E8: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800267EC: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800267F0: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800267F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800267F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800267FC: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80026800: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80026804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80026808: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002680C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80026810: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80026814: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80026818: add.s       $f2, $f6, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x8002681C: lwc1        $f9, 0x6410($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6410);
    // 0x80026820: swc1        $f2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f2.u32l;
    // 0x80026824: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80026828: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8002682C: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80026830: lwc1        $f8, 0x6414($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6414);
    // 0x80026834: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80026838: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8002683C: add.s       $f12, $f4, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x80026840: bc1f        L_80026854
    if (!c1cs) {
        // 0x80026844: swc1        $f12, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->f12.u32l;
            goto L_80026854;
    }
    // 0x80026844: swc1        $f12, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f12.u32l;
    // 0x80026848: sll         $v0, $ra, 24
    ctx->r2 = S32(ctx->r31 << 24);
    // 0x8002684C: sra         $t9, $v0, 24
    ctx->r25 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80026850: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80026854:
    // 0x80026854: c.lt.d      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.d < ctx->f0.d;
    // 0x80026858: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8002685C: bc1f        L_80026870
    if (!c1cs) {
        // 0x80026860: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80026870;
    }
    // 0x80026860: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80026864: ori         $t6, $v0, 0x2
    ctx->r14 = ctx->r2 | 0X2;
    // 0x80026868: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x8002686C: sra         $v0, $t8, 24
    ctx->r2 = S32(SIGNED(ctx->r24) >> 24);
L_80026870:
    // 0x80026870: lwc1        $f5, 0x6418($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6418);
    // 0x80026874: lwc1        $f4, 0x641C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X641C);
    // 0x80026878: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8002687C: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80026880: nop

    // 0x80026884: bc1f        L_80026898
    if (!c1cs) {
        // 0x80026888: nop
    
            goto L_80026898;
    }
    // 0x80026888: nop

    // 0x8002688C: sll         $v1, $ra, 24
    ctx->r3 = S32(ctx->r31 << 24);
    // 0x80026890: sra         $t9, $v1, 24
    ctx->r25 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80026894: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_80026898:
    // 0x80026898: c.lt.d      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.d < ctx->f0.d;
    // 0x8002689C: ori         $t6, $v1, 0x2
    ctx->r14 = ctx->r3 | 0X2;
    // 0x800268A0: bc1f        L_800268AC
    if (!c1cs) {
        // 0x800268A4: sll         $t8, $t6, 24
        ctx->r24 = S32(ctx->r14 << 24);
            goto L_800268AC;
    }
    // 0x800268A4: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x800268A8: sra         $v1, $t8, 24
    ctx->r3 = S32(SIGNED(ctx->r24) >> 24);
L_800268AC:
    // 0x800268AC: or          $t9, $v1, $v0
    ctx->r25 = ctx->r3 | ctx->r2;
    // 0x800268B0: bne         $t9, $zero, L_800268D0
    if (ctx->r25 != 0) {
        // 0x800268B4: nop
    
            goto L_800268D0;
    }
    // 0x800268B4: nop

    // 0x800268B8: sll         $s0, $ra, 16
    ctx->r16 = S32(ctx->r31 << 16);
    // 0x800268BC: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800268C0: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800268C4: sb          $v1, 0xF9($sp)
    MEM_B(0XF9, ctx->r29) = ctx->r3;
    // 0x800268C8: b           L_80026A0C
    // 0x800268CC: sb          $v0, 0xF8($sp)
    MEM_B(0XF8, ctx->r29) = ctx->r2;
        goto L_80026A0C;
    // 0x800268CC: sb          $v0, 0xF8($sp)
    MEM_B(0XF8, ctx->r29) = ctx->r2;
L_800268D0:
    // 0x800268D0: sb          $v0, 0xF8($sp)
    MEM_B(0XF8, ctx->r29) = ctx->r2;
    // 0x800268D4: beq         $v1, $v0, L_80026A0C
    if (ctx->r3 == ctx->r2) {
        // 0x800268D8: sb          $v1, 0xF9($sp)
        MEM_B(0XF9, ctx->r29) = ctx->r3;
            goto L_80026A0C;
    }
    // 0x800268D8: sb          $v1, 0xF9($sp)
    MEM_B(0XF9, ctx->r29) = ctx->r3;
    // 0x800268DC: lwc1        $f10, 0xC8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800268E0: lwc1        $f8, 0xC4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800268E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800268E8: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800268EC: sll         $s0, $ra, 16
    ctx->r16 = S32(ctx->r31 << 16);
    // 0x800268F0: bc1f        L_80026908
    if (!c1cs) {
        // 0x800268F4: addu        $t9, $s2, $a3
        ctx->r25 = ADD32(ctx->r18, ctx->r7);
            goto L_80026908;
    }
    // 0x800268F4: addu        $t9, $s2, $a3
    ctx->r25 = ADD32(ctx->r18, ctx->r7);
    // 0x800268F8: sll         $a3, $ra, 16
    ctx->r7 = S32(ctx->r31 << 16);
    // 0x800268FC: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80026900: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80026904: addu        $t9, $s2, $a3
    ctx->r25 = ADD32(ctx->r18, ctx->r7);
L_80026908:
    // 0x80026908: lb          $t6, 0x0($t9)
    ctx->r14 = MEM_B(ctx->r25, 0X0);
    // 0x8002690C: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x80026910: bne         $ra, $t6, L_80026988
    if (ctx->r31 != ctx->r14) {
        // 0x80026914: subu        $a2, $ra, $a3
        ctx->r6 = SUB32(ctx->r31, ctx->r7);
            goto L_80026988;
    }
    // 0x80026914: subu        $a2, $ra, $a3
    ctx->r6 = SUB32(ctx->r31, ctx->r7);
    // 0x80026918: subu        $a1, $ra, $a3
    ctx->r5 = SUB32(ctx->r31, ctx->r7);
    // 0x8002691C: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80026920: addu        $v1, $s1, $v0
    ctx->r3 = ADD32(ctx->r17, ctx->r2);
    // 0x80026924: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80026928: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002692C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80026930: addu        $t6, $s1, $t9
    ctx->r14 = ADD32(ctx->r17, ctx->r25);
    // 0x80026934: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x80026938: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8002693C: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80026940: sub.d       $f10, $f4, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f30.d); 
    ctx->f10.d = ctx->f4.d - ctx->f30.d;
    // 0x80026944: addu        $t8, $fp, $t9
    ctx->r24 = ADD32(ctx->r30, ctx->r25);
    // 0x80026948: sub.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8002694C: addu        $a0, $fp, $v0
    ctx->r4 = ADD32(ctx->r30, ctx->r2);
    // 0x80026950: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80026954: nop

    // 0x80026958: div.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x8002695C: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80026960: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80026964: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x80026968: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8002696C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80026970: nop

    // 0x80026974: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80026978: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8002697C: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80026980: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80026984: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
L_80026988:
    // 0x80026988: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x8002698C: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80026990: addu        $t6, $s2, $t9
    ctx->r14 = ADD32(ctx->r18, ctx->r25);
    // 0x80026994: lb          $t8, 0x0($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X0);
    // 0x80026998: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002699C: bne         $t8, $at, L_80026A08
    if (ctx->r24 != ctx->r1) {
        // 0x800269A0: sra         $t6, $s0, 16
        ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
            goto L_80026A08;
    }
    // 0x800269A0: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800269A4: sll         $a1, $t9, 2
    ctx->r5 = S32(ctx->r25 << 2);
    // 0x800269A8: addu        $v1, $s1, $a1
    ctx->r3 = ADD32(ctx->r17, ctx->r5);
    // 0x800269AC: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x800269B0: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800269B4: addu        $t7, $s1, $v0
    ctx->r15 = ADD32(ctx->r17, ctx->r2);
    // 0x800269B8: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800269BC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800269C0: sub.d       $f4, $f10, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f30.d); 
    ctx->f4.d = ctx->f10.d - ctx->f30.d;
    // 0x800269C4: addu        $t9, $fp, $v0
    ctx->r25 = ADD32(ctx->r30, ctx->r2);
    // 0x800269C8: sub.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800269CC: addu        $a0, $fp, $a1
    ctx->r4 = ADD32(ctx->r30, ctx->r5);
    // 0x800269D0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800269D4: nop

    // 0x800269D8: div.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800269DC: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800269E0: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800269E4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800269E8: sub.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800269EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800269F0: nop

    // 0x800269F4: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800269F8: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x800269FC: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80026A00: add.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80026A04: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
L_80026A08:
    // 0x80026A08: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_80026A0C:
    // 0x80026A0C: beq         $s0, $zero, L_80026BB0
    if (ctx->r16 == 0) {
        // 0x80026A10: sll         $t7, $s7, 3
        ctx->r15 = S32(ctx->r23 << 3);
            goto L_80026BB0;
    }
    // 0x80026A10: sll         $t7, $s7, 3
    ctx->r15 = S32(ctx->r23 << 3);
    // 0x80026A14: lw          $t8, 0x14($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X14);
    // 0x80026A18: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80026A1C: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80026A20: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x80026A24: lw          $t9, 0x18($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X18);
    // 0x80026A28: sll         $t8, $t6, 18
    ctx->r24 = S32(ctx->r14 << 18);
    // 0x80026A2C: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026A30: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80026A34: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80026A38: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x80026A3C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80026A40: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80026A44: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80026A48: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80026A4C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80026A50: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80026A54: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80026A58: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80026A5C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80026A60: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80026A64: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80026A68: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80026A6C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80026A70: nop

    // 0x80026A74: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80026A78: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026A7C: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80026A80: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80026A84: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80026A88: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80026A8C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80026A90: c.lt.d      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.d < ctx->f4.d;
    // 0x80026A94: nop

    // 0x80026A98: bc1f        L_80026AA8
    if (!c1cs) {
        // 0x80026A9C: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_80026AA8;
    }
    // 0x80026A9C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80026AA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80026AA4: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
L_80026AA8:
    // 0x80026AA8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80026AAC: sll         $s0, $t8, 16
    ctx->r16 = S32(ctx->r24 << 16);
    // 0x80026AB0: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80026AB4: bc1f        L_80026ACC
    if (!c1cs) {
        // 0x80026AB8: or          $s0, $t7, $zero
        ctx->r16 = ctx->r15 | 0;
            goto L_80026ACC;
    }
    // 0x80026AB8: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80026ABC: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x80026AC0: ori         $t6, $t9, 0x1
    ctx->r14 = ctx->r25 | 0X1;
    // 0x80026AC4: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80026AC8: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
L_80026ACC:
    // 0x80026ACC: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80026AD0: ori         $t9, $s0, 0x8
    ctx->r25 = ctx->r16 | 0X8;
    // 0x80026AD4: bc1f        L_80026AE0
    if (!c1cs) {
        // 0x80026AD8: sll         $t6, $t9, 16
        ctx->r14 = S32(ctx->r25 << 16);
            goto L_80026AE0;
    }
    // 0x80026AD8: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80026ADC: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
L_80026AE0:
    // 0x80026AE0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80026AE4: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80026AE8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80026AEC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80026AF0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80026AF4: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80026AF8: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80026AFC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80026B00: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80026B04: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80026B08: sh          $t1, 0x10A($sp)
    MEM_H(0X10A, ctx->r29) = ctx->r9;
    // 0x80026B0C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80026B10: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80026B14: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80026B18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80026B1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80026B20: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80026B24: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80026B28: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80026B2C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80026B30: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80026B34: jal         0x80026C54
    // 0x80026B38: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    func_80026C14(rdram, ctx);
        goto after_0;
    // 0x80026B38: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    after_0:
    // 0x80026B3C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80026B40: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80026B44: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80026B48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80026B4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80026B50: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80026B54: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80026B58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80026B5C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80026B60: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80026B64: nop

    // 0x80026B68: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80026B6C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80026B70: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80026B74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80026B78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80026B7C: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026B80: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80026B84: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80026B88: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80026B8C: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80026B90: jal         0x80026C54
    // 0x80026B94: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    func_80026C14(rdram, ctx);
        goto after_1;
    // 0x80026B94: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    after_1:
    // 0x80026B98: lh          $t1, 0x10A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X10A);
    // 0x80026B9C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80026BA0: addiu       $t3, $sp, 0xB0
    ctx->r11 = ADD32(ctx->r29, 0XB0);
    // 0x80026BA4: addiu       $t4, $sp, 0xA0
    ctx->r12 = ADD32(ctx->r29, 0XA0);
    // 0x80026BA8: addiu       $t5, $sp, 0xA8
    ctx->r13 = ADD32(ctx->r29, 0XA8);
    // 0x80026BAC: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
L_80026BB0:
    // 0x80026BB0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80026BB4: lh          $t6, 0x108($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X108);
    // 0x80026BB8: sll         $t7, $s7, 16
    ctx->r15 = S32(ctx->r23 << 16);
    // 0x80026BBC: sra         $s7, $t7, 16
    ctx->r23 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80026BC0: slt         $at, $s7, $t6
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80026BC4: bne         $at, $zero, L_80026598
    if (ctx->r1 != 0) {
        // 0x80026BC8: nop
    
            goto L_80026598;
    }
    // 0x80026BC8: nop

    // 0x80026BCC: lh          $a0, 0x20($s6)
    ctx->r4 = MEM_H(ctx->r22, 0X20);
    // 0x80026BD0: nop

L_80026BD4:
    // 0x80026BD4: lh          $v0, 0x10E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X10E);
    // 0x80026BD8: nop

    // 0x80026BDC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80026BE0: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80026BE4: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026BE8: slt         $at, $t7, $a0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80026BEC: bne         $at, $zero, L_80026540
    if (ctx->r1 != 0) {
        // 0x80026BF0: sh          $t7, 0x10E($sp)
        MEM_H(0X10E, ctx->r29) = ctx->r15;
            goto L_80026540;
    }
    // 0x80026BF0: sh          $t7, 0x10E($sp)
    MEM_H(0X10E, ctx->r29) = ctx->r15;
L_80026BF4:
    // 0x80026BF4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80026BF8: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80026BFC: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80026C00: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80026C04: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80026C08: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80026C0C: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80026C10: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80026C14: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80026C18: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80026C1C: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80026C20: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80026C24: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80026C28: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80026C2C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80026C30: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80026C34: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80026C38: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80026C3C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80026C40: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80026C44: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80026C48: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80026C4C: jr          $ra
    // 0x80026C50: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x80026C50: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void alCSPStop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8B30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C8B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8B38: addiu       $t6, $zero, 0x11
    ctx->r14 = ADD32(0, 0X11);
    // 0x800C8B3C: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C8B40: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C8B44: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C8B48: jal         0x800C970C
    // 0x800C8B4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C8B4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C8B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8B54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C8B58: jr          $ra
    // 0x800C8B5C: nop

    return;
    // 0x800C8B5C: nop

;}
RECOMP_FUNC void func_800B92F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9814: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800B9818: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800B981C: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800B9820: addiu       $s5, $s5, -0x5A78
    ctx->r21 = ADD32(ctx->r21, -0X5A78);
    // 0x800B9824: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800B9828: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B982C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800B9830: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9834: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B9838: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800B983C: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800B9840: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B9844: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B9848: lwc1        $f6, 0x44($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X44);
    // 0x800B984C: lw          $t8, 0x3668($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3668);
    // 0x800B9850: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800B9854: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B9858: lh          $t2, -0x5458($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X5458);
    // 0x800B985C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B9860: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B9864: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800B9868: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800B986C: mflo        $t1
    ctx->r9 = lo;
    // 0x800B9870: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9874: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B9878: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800B987C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800B9880: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800B9884: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800B9888: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800B988C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800B9890: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800B9894: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800B9898: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B989C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B98A0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800B98A4: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x800B98A8: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x800B98AC: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x800B98B0: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    // 0x800B98B4: beq         $t2, $at, L_800B9C88
    if (ctx->r10 == ctx->r1) {
        // 0x800B98B8: div.s       $f22, $f8, $f10
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
            goto L_800B9C88;
    }
    // 0x800B98B8: div.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B98BC: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B98C0: addiu       $t3, $t3, -0x5458
    ctx->r11 = ADD32(ctx->r11, -0X5458);
    // 0x800B98C4: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800B98C8: lh          $v0, 0x0($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X0);
    // 0x800B98CC: addiu       $s6, $s6, -0x5458
    ctx->r22 = ADD32(ctx->r22, -0X5458);
    // 0x800B98D0: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
L_800B98D4:
    // 0x800B98D4: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x800B98D8: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x800B98DC: bne         $t4, $v0, L_800B9C78
    if (ctx->r12 != ctx->r2) {
        // 0x800B98E0: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_800B9C78;
    }
    // 0x800B98E0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B98E4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B98E8: lw          $t1, -0x5A28($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5A28);
    // 0x800B98EC: lw          $t3, 0xB4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB4);
    // 0x800B98F0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800B98F4: lw          $t5, 0x3664($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3664);
    // 0x800B98F8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800B98FC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B9900: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x800B9904: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800B9908: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B990C: lw          $a1, 0x28($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X28);
    // 0x800B9910: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x800B9914: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B9918: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800B991C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x800B9920: lw          $a3, 0x3674($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3674);
    // 0x800B9924: lw          $a2, 0x3600($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3600);
    // 0x800B9928: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x800B992C: beq         $a1, $zero, L_800B9980
    if (ctx->r5 == 0) {
        // 0x800B9930: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_800B9980;
    }
    // 0x800B9930: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800B9934: lh          $v0, 0x2($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X2);
    // 0x800B9938: nop

    // 0x800B993C: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800B9940: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9944: andi        $t2, $v0, 0x2
    ctx->r10 = ctx->r2 & 0X2;
    // 0x800B9948: sra         $t4, $t2, 1
    ctx->r12 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800B994C: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800B9950: srlv        $t5, $a0, $t7
    ctx->r13 = S32(U32(ctx->r4) >> (ctx->r15 & 31));
    // 0x800B9954: andi        $t8, $t5, 0xFF
    ctx->r24 = ctx->r13 & 0XFF;
    // 0x800B9958: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B995C: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x800B9960: mflo        $t3
    ctx->r11 = lo;
    // 0x800B9964: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
    // 0x800B9968: nop

    // 0x800B996C: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9970: mflo        $t6
    ctx->r14 = lo;
    // 0x800B9974: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
    // 0x800B9978: b           L_800B9998
    // 0x800B997C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
        goto L_800B9998;
    // 0x800B997C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
L_800B9980:
    // 0x800B9980: andi        $t7, $a0, 0xFF
    ctx->r15 = ctx->r4 & 0XFF;
    // 0x800B9984: addiu       $t5, $t7, -0x1
    ctx->r13 = ADD32(ctx->r15, -0X1);
    // 0x800B9988: sw          $t5, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r13;
    // 0x800B998C: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
    // 0x800B9990: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // 0x800B9994: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
L_800B9998:
    // 0x800B9998: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x800B999C: lh          $a0, 0x6($s6)
    ctx->r4 = MEM_H(ctx->r22, 0X6);
    // 0x800B99A0: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B99A4: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x800B99A8: addu        $t6, $a3, $t4
    ctx->r14 = ADD32(ctx->r7, ctx->r12);
    // 0x800B99AC: mflo        $t1
    ctx->r9 = lo;
    // 0x800B99B0: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800B99B4: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x800B99B8: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800B99BC: addu        $t2, $a2, $t3
    ctx->r10 = ADD32(ctx->r6, ctx->r11);
    // 0x800B99C0: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x800B99C4: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800B99C8: bltz        $v1, L_800B9C78
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B99CC: sw          $t7, 0x98($sp)
        MEM_W(0X98, ctx->r29) = ctx->r15;
            goto L_800B9C78;
    }
    // 0x800B99CC: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x800B99D0: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x800B99D4: nop

L_800B99D8:
    // 0x800B99D8: multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B99DC: lh          $s1, 0x4($s6)
    ctx->r17 = MEM_H(ctx->r22, 0X4);
    // 0x800B99E0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800B99E4: addiu       $t3, $t3, 0x35DC
    ctx->r11 = ADD32(ctx->r11, 0X35DC);
    // 0x800B99E8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B99EC: sll         $s4, $s7, 2
    ctx->r20 = S32(ctx->r23 << 2);
    // 0x800B99F0: mflo        $t5
    ctx->r13 = lo;
    // 0x800B99F4: addu        $s2, $t5, $s1
    ctx->r18 = ADD32(ctx->r13, ctx->r17);
    // 0x800B99F8: bltz        $v1, L_800B9C34
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B99FC: sll         $t5, $s7, 2
        ctx->r13 = S32(ctx->r23 << 2);
            goto L_800B9C34;
    }
    // 0x800B99FC: sll         $t5, $s7, 2
    ctx->r13 = S32(ctx->r23 << 2);
    // 0x800B9A00: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x800B9A04: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800B9A08: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x800B9A0C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800B9A10: addu        $t5, $t5, $s7
    ctx->r13 = ADD32(ctx->r13, ctx->r23);
    // 0x800B9A14: sra         $t4, $t9, 1
    ctx->r12 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800B9A18: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800B9A1C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800B9A20: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x800B9A24: addu        $a3, $t1, $t3
    ctx->r7 = ADD32(ctx->r9, ctx->r11);
    // 0x800B9A28: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
    // 0x800B9A2C: addu        $t0, $t2, $t6
    ctx->r8 = ADD32(ctx->r10, ctx->r14);
    // 0x800B9A30: addu        $s0, $t7, $t5
    ctx->r16 = ADD32(ctx->r15, ctx->r13);
L_800B9A34:
    // 0x800B9A34: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B9A38: lw          $t8, 0x35D4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X35D4);
    // 0x800B9A3C: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x800B9A40: addu        $v1, $t8, $t1
    ctx->r3 = ADD32(ctx->r24, ctx->r9);
    // 0x800B9A44: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B9A48: lw          $v0, 0x35D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X35D0);
    // 0x800B9A4C: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x800B9A50: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800B9A54: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x800B9A58: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x800B9A5C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800B9A60: addu        $t4, $v0, $t9
    ctx->r12 = ADD32(ctx->r2, ctx->r25);
    // 0x800B9A64: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800B9A68: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800B9A6C: lwc1        $f6, 0x40($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X40);
    // 0x800B9A70: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B9A74: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B9A78: lw          $t5, 0x3718($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3718);
    // 0x800B9A7C: mul.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B9A80: blez        $t5, L_800B9AB8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800B9A84: nop
    
            goto L_800B9AB8;
    }
    // 0x800B9A84: nop

    // 0x800B9A88: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x800B9A8C: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x800B9A90: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x800B9A94: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x800B9A98: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800B9A9C: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800B9AA0: addu        $a1, $s3, $t8
    ctx->r5 = ADD32(ctx->r19, ctx->r24);
    // 0x800B9AA4: jal         0x800BF4E4
    // 0x800B9AA8: addu        $a2, $t1, $t3
    ctx->r6 = ADD32(ctx->r9, ctx->r11);
    waves_get_y(rdram, ctx);
        goto after_0;
    // 0x800B9AA8: addu        $a2, $t1, $t3
    ctx->r6 = ADD32(ctx->r9, ctx->r11);
    after_0:
    // 0x800B9AAC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800B9AB0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800B9AB4: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
L_800B9AB8:
    // 0x800B9AB8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B9ABC: lw          $t2, 0x3708($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3708);
    // 0x800B9AC0: lw          $v1, 0x8($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X8);
    // 0x800B9AC4: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x800B9AC8: addu        $t6, $v1, $t2
    ctx->r14 = ADD32(ctx->r3, ctx->r10);
    // 0x800B9ACC: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x800B9AD0: addu        $t4, $t9, $s4
    ctx->r12 = ADD32(ctx->r25, ctx->r20);
    // 0x800B9AD4: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800B9AD8: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800B9ADC: slti        $at, $t7, 0xFF
    ctx->r1 = SIGNED(ctx->r15) < 0XFF ? 1 : 0;
    // 0x800B9AE0: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x800B9AE4: mul.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800B9AE8: sw          $t5, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r13;
    // 0x800B9AEC: beq         $at, $zero, L_800B9B10
    if (ctx->r1 == 0) {
        // 0x800B9AF0: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800B9B10;
    }
    // 0x800B9AF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800B9AF4: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800B9AF8: lwc1        $f10, 0x44($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X44);
    // 0x800B9AFC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B9B00: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x800B9B04: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B9B08: mul.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800B9B0C: nop

L_800B9B10:
    // 0x800B9B10: lwc1        $f8, 0x48($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X48);
    // 0x800B9B14: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B9B18: mul.s       $f16, $f20, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800B9B1C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800B9B20: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B9B24: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B9B28: nop

    // 0x800B9B2C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B9B30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B9B34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B9B38: nop

    // 0x800B9B3C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B9B40: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800B9B44: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B9B48: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800B9B4C: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800B9B50: bne         $at, $zero, L_800B9B60
    if (ctx->r1 != 0) {
        // 0x800B9B54: nop
    
            goto L_800B9B60;
    }
    // 0x800B9B54: nop

    // 0x800B9B58: b           L_800B9B6C
    // 0x800B9B5C: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
        goto L_800B9B6C;
    // 0x800B9B5C: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
L_800B9B60:
    // 0x800B9B60: bgez        $v0, L_800B9B6C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B9B64: nop
    
            goto L_800B9B6C;
    }
    // 0x800B9B64: nop

    // 0x800B9B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B9B6C:
    // 0x800B9B6C: lh          $t9, 0x2($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X2);
    // 0x800B9B70: subu        $t3, $fp, $v0
    ctx->r11 = SUB32(ctx->r30, ctx->r2);
    // 0x800B9B74: addu        $t4, $t0, $t9
    ctx->r12 = ADD32(ctx->r8, ctx->r25);
    // 0x800B9B78: lbu         $t2, 0x14($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X14);
    // 0x800B9B7C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800B9B80: multu       $t3, $t2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9B84: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800B9B88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B9B8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B9B90: nop

    // 0x800B9B94: cvt.w.s     $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    ctx->f10.u32l = CVT_W_S(ctx->f20.fl);
    // 0x800B9B98: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800B9B9C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800B9BA0: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x800B9BA4: mflo        $t6
    ctx->r14 = lo;
    // 0x800B9BA8: sra         $t7, $t6, 7
    ctx->r15 = S32(SIGNED(ctx->r14) >> 7);
    // 0x800B9BAC: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800B9BB0: slti        $at, $v0, 0xC0
    ctx->r1 = SIGNED(ctx->r2) < 0XC0 ? 1 : 0;
    // 0x800B9BB4: beq         $at, $zero, L_800B9BC4
    if (ctx->r1 == 0) {
        // 0x800B9BB8: subu        $v1, $fp, $v0
        ctx->r3 = SUB32(ctx->r30, ctx->r2);
            goto L_800B9BC4;
    }
    // 0x800B9BB8: subu        $v1, $fp, $v0
    ctx->r3 = SUB32(ctx->r30, ctx->r2);
    // 0x800B9BBC: b           L_800B9BCC
    // 0x800B9BC0: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
        goto L_800B9BCC;
    // 0x800B9BC0: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
L_800B9BC4:
    // 0x800B9BC4: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800B9BC8: andi        $v1, $t1, 0xFF
    ctx->r3 = ctx->r9 & 0XFF;
L_800B9BCC:
    // 0x800B9BCC: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x800B9BD0: sb          $v1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r3;
    // 0x800B9BD4: sb          $v1, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r3;
    // 0x800B9BD8: beq         $at, $zero, L_800B9BF0
    if (ctx->r1 == 0) {
        // 0x800B9BDC: sb          $v1, 0x8($s0)
        MEM_B(0X8, ctx->r16) = ctx->r3;
            goto L_800B9BF0;
    }
    // 0x800B9BDC: sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // 0x800B9BE0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800B9BE4: andi        $t4, $v1, 0xFF
    ctx->r12 = ctx->r3 & 0XFF;
    // 0x800B9BE8: b           L_800B9BF4
    // 0x800B9BEC: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
        goto L_800B9BF4;
    // 0x800B9BEC: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_800B9BF0:
    // 0x800B9BF0: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
L_800B9BF4:
    // 0x800B9BF4: sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // 0x800B9BF8: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x800B9BFC: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x800B9C00: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B9C04: bne         $at, $zero, L_800B9C14
    if (ctx->r1 != 0) {
        // 0x800B9C08: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800B9C14;
    }
    // 0x800B9C08: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800B9C0C: subu        $s1, $s1, $v0
    ctx->r17 = SUB32(ctx->r17, ctx->r2);
    // 0x800B9C10: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
L_800B9C14:
    // 0x800B9C14: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800B9C18: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800B9C1C: slt         $at, $v1, $s3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800B9C20: beq         $at, $zero, L_800B9A34
    if (ctx->r1 == 0) {
        // 0x800B9C24: nop
    
            goto L_800B9A34;
    }
    // 0x800B9C24: nop

    // 0x800B9C28: lw          $a1, 0x28($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X28);
    // 0x800B9C2C: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x800B9C30: nop

L_800B9C34:
    // 0x800B9C34: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B9C38: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B9C3C: bne         $at, $zero, L_800B9C48
    if (ctx->r1 != 0) {
        // 0x800B9C40: nop
    
            goto L_800B9C48;
    }
    // 0x800B9C40: nop

    // 0x800B9C44: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
L_800B9C48:
    // 0x800B9C48: beq         $a1, $zero, L_800B9C64
    if (ctx->r5 == 0) {
        // 0x800B9C4C: lw          $t6, 0xAC($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XAC);
            goto L_800B9C64;
    }
    // 0x800B9C4C: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800B9C50: lw          $t3, 0x8($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X8);
    // 0x800B9C54: nop

    // 0x800B9C58: addu        $t2, $t3, $v1
    ctx->r10 = ADD32(ctx->r11, ctx->r3);
    // 0x800B9C5C: sw          $t2, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r10;
    // 0x800B9C60: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
L_800B9C64:
    // 0x800B9C64: nop

    // 0x800B9C68: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B9C6C: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B9C70: beq         $at, $zero, L_800B99D8
    if (ctx->r1 == 0) {
        // 0x800B9C74: sw          $t7, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->r15;
            goto L_800B99D8;
    }
    // 0x800B9C74: sw          $t7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r15;
L_800B9C78:
    // 0x800B9C78: lh          $v0, 0xC($s6)
    ctx->r2 = MEM_H(ctx->r22, 0XC);
    // 0x800B9C7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9C80: bne         $v0, $at, L_800B98D4
    if (ctx->r2 != ctx->r1) {
        // 0x800B9C84: addiu       $s6, $s6, 0xC
        ctx->r22 = ADD32(ctx->r22, 0XC);
            goto L_800B98D4;
    }
    // 0x800B9C84: addiu       $s6, $s6, 0xC
    ctx->r22 = ADD32(ctx->r22, 0XC);
L_800B9C88:
    // 0x800B9C88: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800B9C8C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800B9C90: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B9C94: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800B9C98: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B9C9C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B9CA0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9CA4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800B9CA8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800B9CAC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800B9CB0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800B9CB4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800B9CB8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800B9CBC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800B9CC0: jr          $ra
    // 0x800B9CC4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800B9CC4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void init_track(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024A30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80024A34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80024A38: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80024A3C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80024A40: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80024A44: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80024A48: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80024A4C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80024A50: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80024A54: jal         0x8006BFF0
    // 0x80024A58: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    level_header(rdram, ctx);
        goto after_0;
    // 0x80024A58: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x80024A5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80024A60: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80024A64: addiu       $a1, $a1, -0x3174
    ctx->r5 = ADD32(ctx->r5, -0X3174);
    // 0x80024A68: addiu       $a0, $a0, -0x4988
    ctx->r4 = ADD32(ctx->r4, -0X4988);
    // 0x80024A6C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80024A70: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80024A74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024A78: sw          $zero, -0x4980($at)
    MEM_W(-0X4980, ctx->r1) = 0;
    // 0x80024A7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024A80: sw          $zero, -0x497C($at)
    MEM_W(-0X497C, ctx->r1) = 0;
    // 0x80024A84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024A88: sw          $zero, -0x4978($at)
    MEM_W(-0X4978, ctx->r1) = 0;
    // 0x80024A8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024A90: sw          $zero, -0x4974($at)
    MEM_W(-0X4974, ctx->r1) = 0;
    // 0x80024A94: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80024A98: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80024A9C: lb          $v1, 0x4C($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X4C);
    // 0x80024AA0: nop

    // 0x80024AA4: beq         $v1, $at, L_80024AB0
    if (ctx->r3 == ctx->r1) {
        // 0x80024AA8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80024AB0;
    }
    // 0x80024AA8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80024AAC: bne         $v1, $at, L_80024AB8
    if (ctx->r3 != ctx->r1) {
        // 0x80024AB0: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80024AB8;
    }
L_80024AB0:
    // 0x80024AB0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80024AB4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_80024AB8:
    // 0x80024AB8: jal         0x8002C104
    // 0x80024ABC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    generate_track(rdram, ctx);
        goto after_1;
    // 0x80024ABC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80024AC0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80024AC4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80024AC8: addiu       $s0, $s0, -0x26FC
    ctx->r16 = ADD32(ctx->r16, -0X26FC);
    // 0x80024ACC: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80024AD0: beq         $at, $zero, L_80024B4C
    if (ctx->r1 == 0) {
        // 0x80024AD4: sw          $zero, 0x0($s0)
        MEM_W(0X0, ctx->r16) = 0;
            goto L_80024B4C;
    }
    // 0x80024AD4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80024AD8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80024ADC: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x80024AE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80024AE4: lh          $a0, 0x1A($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X1A);
    // 0x80024AE8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80024AEC: blez        $a0, L_80024B4C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80024AF0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80024B4C;
    }
    // 0x80024AF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80024AF4:
    // 0x80024AF4: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80024AF8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80024AFC: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x80024B00: lb          $t1, 0x2B($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X2B);
    // 0x80024B04: nop

    // 0x80024B08: beq         $t1, $zero, L_80024B44
    if (ctx->r9 == 0) {
        // 0x80024B0C: slt         $at, $a2, $a0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80024B44;
    }
    // 0x80024B0C: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80024B10: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80024B14: nop

    // 0x80024B18: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80024B1C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80024B20: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80024B24: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80024B28: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80024B2C: sb          $a1, 0x2B($t5)
    MEM_B(0X2B, ctx->r13) = ctx->r5;
    // 0x80024B30: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x80024B34: nop

    // 0x80024B38: lh          $a0, 0x1A($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X1A);
    // 0x80024B3C: nop

    // 0x80024B40: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
L_80024B44:
    // 0x80024B44: bne         $at, $zero, L_80024AF4
    if (ctx->r1 != 0) {
        // 0x80024B48: addiu       $v1, $v1, 0x44
        ctx->r3 = ADD32(ctx->r3, 0X44);
            goto L_80024AF4;
    }
    // 0x80024B48: addiu       $v1, $v1, 0x44
    ctx->r3 = ADD32(ctx->r3, 0X44);
L_80024B4C:
    // 0x80024B4C: jal         0x8009F1C4
    // 0x80024B50: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_2;
    // 0x80024B50: nop

    after_2:
    // 0x80024B54: beq         $v0, $zero, L_80024B84
    if (ctx->r2 == 0) {
        // 0x80024B58: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_80024B84;
    }
    // 0x80024B58: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80024B5C: lw          $t6, -0x3174($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3174);
    // 0x80024B60: nop

    // 0x80024B64: lb          $v1, 0x4C($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X4C);
    // 0x80024B68: nop

    // 0x80024B6C: beq         $v1, $zero, L_80024B7C
    if (ctx->r3 == 0) {
        // 0x80024B70: andi        $t7, $v1, 0x40
        ctx->r15 = ctx->r3 & 0X40;
            goto L_80024B7C;
    }
    // 0x80024B70: andi        $t7, $v1, 0x40
    ctx->r15 = ctx->r3 & 0X40;
    // 0x80024B74: beq         $t7, $zero, L_80024B88
    if (ctx->r15 == 0) {
        // 0x80024B78: lw          $a2, 0x30($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X30);
            goto L_80024B88;
    }
    // 0x80024B78: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
L_80024B7C:
    // 0x80024B7C: b           L_80024B90
    // 0x80024B80: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_80024B90;
    // 0x80024B80: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80024B84:
    // 0x80024B84: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
L_80024B88:
    // 0x80024B88: nop

    // 0x80024B8C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80024B90:
    // 0x80024B90: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80024B94: nop

    // 0x80024B98: beq         $t8, $zero, L_80024BB4
    if (ctx->r24 == 0) {
        // 0x80024B9C: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80024BB4;
    }
    // 0x80024B9C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80024BA0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80024BA4: lw          $a1, -0x3174($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3174);
    // 0x80024BA8: lw          $a0, -0x3178($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3178);
    // 0x80024BAC: jal         0x800B87D4
    // 0x80024BB0: nop

    waves_init(rdram, ctx);
        goto after_3;
    // 0x80024BB0: nop

    after_3:
L_80024BB4:
    // 0x80024BB4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80024BB8: jal         0x8006676C
    // 0x80024BBC: nop

    cam_set_layout(rdram, ctx);
        goto after_4;
    // 0x80024BBC: nop

    after_4:
    // 0x80024BC0: jal         0x80028004
    // 0x80024BC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skydome_spawn(rdram, ctx);
        goto after_5;
    // 0x80024BC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80024BC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024BCC: sw          $zero, -0x4970($at)
    MEM_W(-0X4970, ctx->r1) = 0;
    // 0x80024BD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024BD4: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x80024BD8: jal         0x80011390
    // 0x80024BDC: sw          $t9, -0x496C($at)
    MEM_W(-0X496C, ctx->r1) = ctx->r25;
    path_enable(rdram, ctx);
        goto after_6;
    // 0x80024BDC: sw          $t9, -0x496C($at)
    MEM_W(-0X496C, ctx->r1) = ctx->r25;
    after_6:
    // 0x80024BE0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80024BE4: jal         0x8000C8F8
    // 0x80024BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    track_spawn_objects(rdram, ctx);
        goto after_7;
    // 0x80024BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80024BEC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80024BF0: jal         0x8000C8F8
    // 0x80024BF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    track_spawn_objects(rdram, ctx);
        goto after_8;
    // 0x80024BF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80024BF8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80024BFC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80024C00: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80024C04: addiu       $s3, $s3, -0x2704
    ctx->r19 = ADD32(ctx->r19, -0X2704);
    // 0x80024C08: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80024C0C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80024C10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80024C14: jal         0x8000CC7C
    // 0x80024C18: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    track_setup_racers(rdram, ctx);
        goto after_9;
    // 0x80024C18: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    after_9:
    // 0x80024C1C: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x80024C20: jal         0x8000B020
    // 0x80024C24: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    racerfx_alloc(rdram, ctx);
        goto after_10;
    // 0x80024C24: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_10:
    // 0x80024C28: bne         $s1, $zero, L_80024C4C
    if (ctx->r17 != 0) {
        // 0x80024C2C: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80024C4C;
    }
    // 0x80024C2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80024C30: bne         $s0, $zero, L_80024C4C
    if (ctx->r16 != 0) {
        // 0x80024C34: nop
    
            goto L_80024C4C;
    }
    // 0x80024C34: nop

    // 0x80024C38: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80024C3C: jal         0x800C06F8
    // 0x80024C40: addiu       $a0, $a0, -0x3214
    ctx->r4 = ADD32(ctx->r4, -0X3214);
    transition_begin(rdram, ctx);
        goto after_11;
    // 0x80024C40: addiu       $a0, $a0, -0x3214
    ctx->r4 = ADD32(ctx->r4, -0X3214);
    after_11:
    // 0x80024C44: b           L_80024C58
    // 0x80024C48: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
        goto L_80024C58;
    // 0x80024C48: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
L_80024C4C:
    // 0x80024C4C: jal         0x800C06F8
    // 0x80024C50: addiu       $a0, $a0, -0x321C
    ctx->r4 = ADD32(ctx->r4, -0X321C);
    transition_begin(rdram, ctx);
        goto after_12;
    // 0x80024C50: addiu       $a0, $a0, -0x321C
    ctx->r4 = ADD32(ctx->r4, -0X321C);
    after_12:
    // 0x80024C54: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
L_80024C58:
    // 0x80024C58: jal         0x8006676C
    // 0x80024C5C: nop

    cam_set_layout(rdram, ctx);
        goto after_13;
    // 0x80024C5C: nop

    after_13:
    // 0x80024C60: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x80024C64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024C68: lui         $s3, 0xFFFF
    ctx->r19 = S32(0XFFFF << 16);
    // 0x80024C6C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80024C70: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80024C74: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80024C78: sw          $zero, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = 0;
    // 0x80024C7C: addiu       $s0, $s0, -0x2748
    ctx->r16 = ADD32(ctx->r16, -0X2748);
    // 0x80024C80: addiu       $s2, $s2, -0x2760
    ctx->r18 = ADD32(ctx->r18, -0X2760);
    // 0x80024C84: addiu       $s1, $s1, -0x2730
    ctx->r17 = ADD32(ctx->r17, -0X2730);
    // 0x80024C88: ori         $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 | 0XFF;
    // 0x80024C8C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
L_80024C90:
    // 0x80024C90: addiu       $a0, $zero, 0xC80
    ctx->r4 = ADD32(0, 0XC80);
    // 0x80024C94: jal         0x80070EDC
    // 0x80024C98: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_14;
    // 0x80024C98: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_14:
    // 0x80024C9C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80024CA0: addiu       $a0, $zero, 0x3200
    ctx->r4 = ADD32(0, 0X3200);
    // 0x80024CA4: jal         0x80070EDC
    // 0x80024CA8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_15;
    // 0x80024CA8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_15:
    // 0x80024CAC: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x80024CB0: addiu       $a0, $zero, 0x4E20
    ctx->r4 = ADD32(0, 0X4E20);
    // 0x80024CB4: jal         0x80070EDC
    // 0x80024CB8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_16;
    // 0x80024CB8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_16:
    // 0x80024CBC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80024CC0: addiu       $t2, $t2, -0x2738
    ctx->r10 = ADD32(ctx->r10, -0X2738);
    // 0x80024CC4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80024CC8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80024CCC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80024CD0: bne         $s0, $t2, L_80024C90
    if (ctx->r16 != ctx->r10) {
        // 0x80024CD4: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_80024C90;
    }
    // 0x80024CD4: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x80024CD8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80024CDC: addiu       $s0, $s0, -0x49B8
    ctx->r16 = ADD32(ctx->r16, -0X49B8);
    // 0x80024CE0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80024CE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80024CE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80024CEC: jal         0x8002D91C
    // 0x80024CF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    shadow_update(rdram, ctx);
        goto after_17;
    // 0x80024CF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x80024CF4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80024CF8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80024CFC: jal         0x8002D91C
    // 0x80024D00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    shadow_update(rdram, ctx);
        goto after_18;
    // 0x80024D00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x80024D04: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80024D08: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80024D0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80024D10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80024D14: jal         0x8002D91C
    // 0x80024D18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    shadow_update(rdram, ctx);
        goto after_19;
    // 0x80024D18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x80024D1C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80024D20: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80024D24: jal         0x8002D91C
    // 0x80024D28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    shadow_update(rdram, ctx);
        goto after_20;
    // 0x80024D28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x80024D2C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80024D30: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80024D34: lw          $v0, -0x3174($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3174);
    // 0x80024D38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024D3C: lbu         $t4, 0xB7($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XB7);
    // 0x80024D40: nop

    // 0x80024D44: beq         $t4, $zero, L_80024D7C
    if (ctx->r12 == 0) {
        // 0x80024D48: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80024D7C;
    }
    // 0x80024D48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80024D4C: lbu         $t5, 0xB4($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XB4);
    // 0x80024D50: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80024D54: sb          $t5, -0x499F($at)
    MEM_B(-0X499F, ctx->r1) = ctx->r13;
    // 0x80024D58: lbu         $t6, 0xB5($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XB5);
    // 0x80024D5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024D60: sb          $t6, -0x499E($at)
    MEM_B(-0X499E, ctx->r1) = ctx->r14;
    // 0x80024D64: lbu         $t7, 0xB6($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XB6);
    // 0x80024D68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024D6C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80024D70: jal         0x80025550
    // 0x80024D74: sb          $t7, -0x499D($at)
    MEM_B(-0X499D, ctx->r1) = ctx->r15;
    void_init(rdram, ctx);
        goto after_21;
    // 0x80024D74: sb          $t7, -0x499D($at)
    MEM_B(-0X499D, ctx->r1) = ctx->r15;
    after_21:
    // 0x80024D78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80024D7C:
    // 0x80024D7C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80024D80: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80024D84: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80024D88: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80024D8C: jr          $ra
    // 0x80024D90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80024D90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mtxf_from_inverse_transform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800700B4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800700B8: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x800700BC: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x800700C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800700C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800700C8: jal         0x80070A70
    // 0x800700CC: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    static_3_80070A70(rdram, ctx);
        goto after_0;
    // 0x800700CC: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_0:
    // 0x800700D0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800700D4: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x800700D8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800700DC: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800700E0: jal         0x80070A6C
    // 0x800700E4: nop

    coss_s16(rdram, ctx);
        goto after_1;
    // 0x800700E4: nop

    after_1:
    // 0x800700E8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800700EC: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x800700F0: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800700F4: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800700F8: jal         0x80070A70
    // 0x800700FC: nop

    static_3_80070A70(rdram, ctx);
        goto after_2;
    // 0x800700FC: nop

    after_2:
    // 0x80070100: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80070104: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x80070108: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007010C: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80070110: jal         0x80070A6C
    // 0x80070114: nop

    coss_s16(rdram, ctx);
        goto after_3;
    // 0x80070114: nop

    after_3:
    // 0x80070118: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8007011C: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x80070120: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80070124: mul.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80070128: jal         0x80070A70
    // 0x8007012C: nop

    static_3_80070A70(rdram, ctx);
        goto after_4;
    // 0x8007012C: nop

    after_4:
    // 0x80070130: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80070134: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x80070138: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007013C: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80070140: jal         0x80070A6C
    // 0x80070144: nop

    coss_s16(rdram, ctx);
        goto after_5;
    // 0x80070144: nop

    after_5:
    // 0x80070148: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8007014C: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x80070150: swc1        $f4, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f4.u32l;
    // 0x80070154: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80070158: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x8007015C: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x80070160: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80070164: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80070168: nop

    // 0x8007016C: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80070170: nop

    // 0x80070174: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80070178: nop

    // 0x8007017C: mul.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80070180: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80070184: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x80070188: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8007018C: nop

    // 0x80070190: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80070194: nop

    // 0x80070198: mul.s       $f18, $f2, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8007019C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800701A0: swc1        $f16, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f16.u32l;
    // 0x800701A4: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800701A8: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x800701AC: swc1        $f16, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f16.u32l;
    // 0x800701B0: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800701B4: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x800701B8: swc1        $f16, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f16.u32l;
    // 0x800701BC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800701C0: swc1        $f16, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f16.u32l;
    // 0x800701C4: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800701C8: nop

    // 0x800701CC: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800701D0: nop

    // 0x800701D4: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800701D8: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800701DC: swc1        $f16, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f16.u32l;
    // 0x800701E0: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800701E4: nop

    // 0x800701E8: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800701EC: nop

    // 0x800701F0: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800701F4: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800701F8: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800701FC: swc1        $f16, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f16.u32l;
    // 0x80070200: mul.s       $f16, $f2, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80070204: swc1        $f16, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f16.u32l;
    // 0x80070208: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8007020C: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80070210: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80070214: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80070218: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8007021C: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80070220: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070224: lwc1        $f18, 0x20($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80070228: mul.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8007022C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070230: lwc1        $f18, 0x4($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80070234: swc1        $f16, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f16.u32l;
    // 0x80070238: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8007023C: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80070240: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80070244: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070248: lwc1        $f18, 0x24($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X24);
    // 0x8007024C: mul.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80070250: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070254: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80070258: swc1        $f16, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f16.u32l;
    // 0x8007025C: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80070260: lwc1        $f16, 0x18($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X18);
    // 0x80070264: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80070268: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8007026C: lwc1        $f18, 0x28($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X28);
    // 0x80070270: mul.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80070274: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070278: swc1        $f16, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f16.u32l;
    // 0x8007027C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80070280: nop

    // 0x80070284: swc1        $f16, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f16.u32l;
    // 0x80070288: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x8007028C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070290: jr          $ra
    // 0x80070294: nop

    return;
    // 0x80070294: nop

;}
RECOMP_FUNC void track_init_collision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CC70: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8002CC74: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8002CC78: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x8002CC7C: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x8002CC80: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8002CC84: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8002CC88: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8002CC8C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8002CC90: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8002CC94: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8002CC98: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8002CC9C: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x8002CCA0: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x8002CCA4: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002CCA8: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8002CCAC: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002CCB0: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8002CCB4: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002CCB8: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8002CCBC: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002CCC0: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002CCC4: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002CCC8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8002CCCC: sw          $zero, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = 0;
    // 0x8002CCD0: lh          $a1, 0x20($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X20);
    // 0x8002CCD4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8002CCD8: blez        $a1, L_8002CF58
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002CCDC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8002CF58;
    }
    // 0x8002CCDC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8002CCE0: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8002CCE4: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_8002CCE8:
    // 0x8002CCE8: lw          $t6, 0xC($s2)
    ctx->r14 = MEM_W(ctx->r18, 0XC);
    // 0x8002CCEC: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8002CCF0: nop

    // 0x8002CCF4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8002CCF8: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x8002CCFC: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x8002CD00: lh          $fp, 0x2($v0)
    ctx->r30 = MEM_H(ctx->r2, 0X2);
    // 0x8002CD04: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002CD08: beq         $at, $zero, L_8002CF38
    if (ctx->r1 == 0) {
        // 0x8002CD0C: sw          $t8, 0xF4($sp)
        MEM_W(0XF4, ctx->r29) = ctx->r24;
            goto L_8002CF38;
    }
    // 0x8002CD0C: sw          $t8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r24;
    // 0x8002CD10: sll         $a1, $v1, 4
    ctx->r5 = S32(ctx->r3 << 4);
    // 0x8002CD14: sll         $s0, $t8, 4
    ctx->r16 = S32(ctx->r24 << 4);
L_8002CD18:
    // 0x8002CD18: lw          $t2, 0x4($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X4);
    // 0x8002CD1C: nop

    // 0x8002CD20: addu        $v1, $t2, $a1
    ctx->r3 = ADD32(ctx->r10, ctx->r5);
    // 0x8002CD24: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x8002CD28: nop

    // 0x8002CD2C: andi        $t4, $t3, 0x80
    ctx->r12 = ctx->r11 & 0X80;
    // 0x8002CD30: bne         $t4, $zero, L_8002CF20
    if (ctx->r12 != 0) {
        // 0x8002CD34: nop
    
            goto L_8002CF20;
    }
    // 0x8002CD34: nop

    // 0x8002CD38: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x8002CD3C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8002CD40: addu        $t6, $t5, $fp
    ctx->r14 = ADD32(ctx->r13, ctx->r30);
    // 0x8002CD44: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002CD48: mflo        $t7
    ctx->r15 = lo;
    // 0x8002CD4C: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x8002CD50: lh          $t2, 0x4($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X4);
    // 0x8002CD54: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8002CD58: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8002CD5C: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x8002CD60: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002CD64: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8002CD68: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8002CD6C: swc1        $f10, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
    // 0x8002CD70: lbu         $t3, 0x2($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2);
    // 0x8002CD74: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    // 0x8002CD78: addu        $t4, $t3, $fp
    ctx->r12 = ADD32(ctx->r11, ctx->r30);
    // 0x8002CD7C: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002CD80: addu        $t2, $t9, $fp
    ctx->r10 = ADD32(ctx->r25, ctx->r30);
    // 0x8002CD84: cvt.s.w     $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    ctx->f30.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002CD88: lwc1        $f26, 0xBC($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002CD8C: cvt.s.w     $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    ctx->f28.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002CD90: mflo        $t5
    ctx->r13 = lo;
    // 0x8002CD94: addu        $v0, $t5, $a0
    ctx->r2 = ADD32(ctx->r13, ctx->r4);
    // 0x8002CD98: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8002CD9C: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002CDA0: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8002CDA4: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8002CDA8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002CDAC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8002CDB0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8002CDB4: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002CDB8: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002CDBC: mflo        $t3
    ctx->r11 = lo;
    // 0x8002CDC0: addu        $v0, $t3, $a0
    ctx->r2 = ADD32(ctx->r11, ctx->r4);
    // 0x8002CDC4: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8002CDC8: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x8002CDCC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8002CDD0: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x8002CDD4: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002CDD8: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8002CDDC: sw          $a1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r5;
    // 0x8002CDE0: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002CDE4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8002CDE8: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8002CDEC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002CDF0: mul.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f30.fl);
    // 0x8002CDF4: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002CDF8: sub.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x8002CDFC: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8002CE00: sub.s       $f4, $f26, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f26.fl - ctx->f14.fl;
    // 0x8002CE04: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8002CE08: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8002CE0C: sub.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8002CE10: mul.s       $f4, $f6, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x8002CE14: add.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002CE18: swc1        $f20, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f20.u32l;
    // 0x8002CE1C: sub.s       $f8, $f16, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f28.fl;
    // 0x8002CE20: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8002CE24: sub.s       $f8, $f28, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f28.fl - ctx->f2.fl;
    // 0x8002CE28: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8002CE2C: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8002CE30: sub.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8002CE34: mul.s       $f8, $f10, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f28.fl);
    // 0x8002CE38: add.s       $f22, $f6, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002CE3C: swc1        $f22, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f22.u32l;
    // 0x8002CE40: sub.s       $f6, $f18, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f30.fl;
    // 0x8002CE44: mul.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8002CE48: sub.s       $f6, $f30, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f30.fl - ctx->f12.fl;
    // 0x8002CE4C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8002CE50: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8002CE54: nop

    // 0x8002CE58: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8002CE5C: add.s       $f24, $f10, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8002CE60: swc1        $f24, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f24.u32l;
    // 0x8002CE64: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8002CE68: nop

    // 0x8002CE6C: mul.s       $f8, $f24, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8002CE70: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002CE74: jal         0x800CA030
    // 0x8002CE78: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8002CE78: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_0:
    // 0x8002CE7C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8002CE80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002CE84: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8002CE88: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8002CE8C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8002CE90: bc1f        L_8002CEB8
    if (!c1cs) {
        // 0x8002CE94: or          $v0, $s4, $zero
        ctx->r2 = ctx->r20 | 0;
            goto L_8002CEB8;
    }
    // 0x8002CE94: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8002CE98: nop

    // 0x8002CE9C: div.s       $f14, $f20, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8002CEA0: nop

    // 0x8002CEA4: div.s       $f12, $f22, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8002CEA8: swc1        $f14, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f14.u32l;
    // 0x8002CEAC: div.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8002CEB0: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x8002CEB4: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
L_8002CEB8:
    // 0x8002CEB8: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x8002CEBC: lwc1        $f14, 0xA0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8002CEC0: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x8002CEC4: lwc1        $f2, 0x98($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8002CEC8: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8002CECC: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8002CED0: swc1        $f14, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f14.u32l;
    // 0x8002CED4: lw          $t2, 0x18($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X18);
    // 0x8002CED8: mul.s       $f10, $f28, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f14.fl);
    // 0x8002CEDC: addu        $t3, $t2, $t7
    ctx->r11 = ADD32(ctx->r10, ctx->r15);
    // 0x8002CEE0: swc1        $f12, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f12.u32l;
    // 0x8002CEE4: lw          $t4, 0x18($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X18);
    // 0x8002CEE8: mul.s       $f8, $f30, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f12.fl);
    // 0x8002CEEC: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x8002CEF0: swc1        $f2, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f2.u32l;
    // 0x8002CEF4: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002CEF8: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8002CEFC: lw          $t6, 0x18($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X18);
    // 0x8002CF00: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8002CF04: addu        $t7, $t6, $t7
    ctx->r15 = ADD32(ctx->r14, ctx->r15);
    // 0x8002CF08: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8002CF0C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8002CF10: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x8002CF14: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x8002CF18: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8002CF1C: nop

L_8002CF20:
    // 0x8002CF20: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8002CF24: slt         $at, $a1, $s0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002CF28: bne         $at, $zero, L_8002CD18
    if (ctx->r1 != 0) {
        // 0x8002CF2C: nop
    
            goto L_8002CD18;
    }
    // 0x8002CF2C: nop

    // 0x8002CF30: lh          $a1, 0x20($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X20);
    // 0x8002CF34: nop

L_8002CF38:
    // 0x8002CF38: lw          $t8, 0xEC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XEC);
    // 0x8002CF3C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8002CF40: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002CF44: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002CF48: addiu       $t3, $t2, 0xC
    ctx->r11 = ADD32(ctx->r10, 0XC);
    // 0x8002CF4C: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x8002CF50: bne         $at, $zero, L_8002CCE8
    if (ctx->r1 != 0) {
        // 0x8002CF54: sw          $t9, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r25;
            goto L_8002CCE8;
    }
    // 0x8002CF54: sw          $t9, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r25;
L_8002CF58:
    // 0x8002CF58: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8002CF5C: lw          $t4, -0x4988($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4988);
    // 0x8002CF60: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8002CF64: beq         $t4, $zero, L_8002CF74
    if (ctx->r12 == 0) {
        // 0x8002CF68: or          $t1, $s4, $zero
        ctx->r9 = ctx->r20 | 0;
            goto L_8002CF74;
    }
    // 0x8002CF68: or          $t1, $s4, $zero
    ctx->r9 = ctx->r20 | 0;
    // 0x8002CF6C: b           L_8002D2EC
    // 0x8002CF70: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
        goto L_8002D2EC;
    // 0x8002CF70: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
L_8002CF74:
    // 0x8002CF74: blez        $a1, L_8002D2E8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002CF78: sw          $zero, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = 0;
            goto L_8002D2E8;
    }
    // 0x8002CF78: sw          $zero, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = 0;
    // 0x8002CF7C: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8002CF80: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
L_8002CF84:
    // 0x8002CF84: lw          $t5, 0xC($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XC);
    // 0x8002CF88: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8002CF8C: nop

    // 0x8002CF90: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8002CF94: lh          $t7, 0x10($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X10);
    // 0x8002CF98: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x8002CF9C: lh          $fp, 0x2($v0)
    ctx->r30 = MEM_H(ctx->r2, 0X2);
    // 0x8002CFA0: sw          $t7, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r15;
    // 0x8002CFA4: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8002CFA8: lw          $t3, 0xF4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF4);
    // 0x8002CFAC: andi        $t2, $t8, 0x200
    ctx->r10 = ctx->r24 & 0X200;
    // 0x8002CFB0: beq         $t2, $zero, L_8002CFC0
    if (ctx->r10 == 0) {
        // 0x8002CFB4: slt         $at, $v1, $t3
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_8002CFC0;
    }
    // 0x8002CFB4: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002CFB8: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8002CFBC: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
L_8002CFC0:
    // 0x8002CFC0: beq         $at, $zero, L_8002D2C8
    if (ctx->r1 == 0) {
        // 0x8002CFC4: or          $s7, $v1, $zero
        ctx->r23 = ctx->r3 | 0;
            goto L_8002D2C8;
    }
    // 0x8002CFC4: or          $s7, $v1, $zero
    ctx->r23 = ctx->r3 | 0;
    // 0x8002CFC8: sll         $a0, $v1, 4
    ctx->r4 = S32(ctx->r3 << 4);
L_8002CFCC:
    // 0x8002CFCC: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x8002CFD0: nop

    // 0x8002CFD4: addu        $t4, $t9, $a0
    ctx->r12 = ADD32(ctx->r25, ctx->r4);
    // 0x8002CFD8: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8002CFDC: nop

    // 0x8002CFE0: andi        $t6, $t5, 0x80
    ctx->r14 = ctx->r13 & 0X80;
    // 0x8002CFE4: bne         $t6, $zero, L_8002D2B4
    if (ctx->r14 != 0) {
        // 0x8002CFE8: lw          $t9, 0xF4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XF4);
            goto L_8002D2B4;
    }
    // 0x8002CFE8: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x8002CFEC: lw          $t7, 0x14($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X14);
    // 0x8002CFF0: sll         $t8, $s7, 3
    ctx->r24 = S32(ctx->r23 << 3);
    // 0x8002CFF4: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x8002CFF8: lhu         $s1, 0x0($t2)
    ctx->r17 = MEM_HU(ctx->r10, 0X0);
    // 0x8002CFFC: lw          $t3, 0x18($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X18);
    // 0x8002D000: sll         $t4, $s1, 4
    ctx->r12 = S32(ctx->r17 << 4);
    // 0x8002D004: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x8002D008: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002D00C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002D010: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    // 0x8002D014: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8002D018: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8002D01C: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    // 0x8002D020: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002D024: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8002D028: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
L_8002D02C:
    // 0x8002D02C: lw          $t5, 0x4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X4);
    // 0x8002D030: lw          $t7, 0x14($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X14);
    // 0x8002D034: addiu       $s6, $v0, 0x1
    ctx->r22 = ADD32(ctx->r2, 0X1);
    // 0x8002D038: sll         $t6, $s7, 4
    ctx->r14 = S32(ctx->r23 << 4);
    // 0x8002D03C: sll         $t8, $s7, 3
    ctx->r24 = S32(ctx->r23 << 3);
    // 0x8002D040: slti        $at, $s6, 0x3
    ctx->r1 = SIGNED(ctx->r22) < 0X3 ? 1 : 0;
    // 0x8002D044: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x8002D048: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x8002D04C: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x8002D050: addu        $a3, $t2, $s5
    ctx->r7 = ADD32(ctx->r10, ctx->r21);
    // 0x8002D054: bne         $at, $zero, L_8002D060
    if (ctx->r1 != 0) {
        // 0x8002D058: addu        $a0, $v1, $v0
        ctx->r4 = ADD32(ctx->r3, ctx->r2);
            goto L_8002D060;
    }
    // 0x8002D058: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x8002D05C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002D060:
    // 0x8002D060: addu        $t3, $v1, $s0
    ctx->r11 = ADD32(ctx->r3, ctx->r16);
    // 0x8002D064: lhu         $s0, 0x2($a3)
    ctx->r16 = MEM_HU(ctx->r7, 0X2);
    // 0x8002D068: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x8002D06C: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x8002D070: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002D074: addu        $a1, $t9, $fp
    ctx->r5 = ADD32(ctx->r25, ctx->r30);
    // 0x8002D078: beq         $at, $zero, L_8002D298
    if (ctx->r1 == 0) {
        // 0x8002D07C: addu        $a2, $t4, $fp
        ctx->r6 = ADD32(ctx->r12, ctx->r30);
            goto L_8002D298;
    }
    // 0x8002D07C: addu        $a2, $t4, $fp
    ctx->r6 = ADD32(ctx->r12, ctx->r30);
    // 0x8002D080: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002D084: lw          $t5, 0x18($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X18);
    // 0x8002D088: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x8002D08C: addu        $v1, $t5, $t7
    ctx->r3 = ADD32(ctx->r13, ctx->r15);
    // 0x8002D090: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002D094: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8002D098: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8002D09C: add.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002D0A0: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8002D0A4: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002D0A8: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8002D0AC: add.s       $f26, $f6, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002D0B0: mflo        $t8
    ctx->r24 = lo;
    // 0x8002D0B4: addu        $v0, $a0, $t8
    ctx->r2 = ADD32(ctx->r4, ctx->r24);
    // 0x8002D0B8: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x8002D0BC: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002D0C0: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8002D0C4: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8002D0C8: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002D0CC: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x8002D0D0: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x8002D0D4: add.s       $f22, $f10, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8002D0D8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8002D0DC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002D0E0: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x8002D0E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002D0E8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8002D0EC: mflo        $t4
    ctx->r12 = lo;
    // 0x8002D0F0: addu        $v0, $a0, $t4
    ctx->r2 = ADD32(ctx->r4, ctx->r12);
    // 0x8002D0F4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8002D0F8: cvt.s.w     $f28, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    ctx->f28.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002D0FC: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x8002D100: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8002D104: mul.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8002D108: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8002D10C: sw          $t1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r9;
    // 0x8002D110: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8002D114: cvt.s.w     $f30, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    ctx->f30.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002D118: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8002D11C: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002D120: mul.s       $f10, $f22, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8002D124: add.s       $f16, $f4, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f28.fl;
    // 0x8002D128: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002D12C: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002D130: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002D134: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002D138: mul.s       $f6, $f26, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f8.fl);
    // 0x8002D13C: add.s       $f18, $f10, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x8002D140: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002D144: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8002D148: mul.s       $f8, $f10, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x8002D14C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8002D150: mul.s       $f10, $f12, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8002D154: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002D158: sub.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8002D15C: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8002D160: sub.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8002D164: add.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8002D168: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8002D16C: sub.s       $f10, $f16, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f28.fl;
    // 0x8002D170: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x8002D174: sub.s       $f10, $f28, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f28.fl - ctx->f2.fl;
    // 0x8002D178: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002D17C: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8002D180: sub.s       $f8, $f12, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8002D184: mul.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f28.fl);
    // 0x8002D188: add.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002D18C: sub.s       $f4, $f18, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f30.fl;
    // 0x8002D190: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8002D194: sub.s       $f4, $f30, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f30.fl - ctx->f12.fl;
    // 0x8002D198: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8002D19C: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8002D1A0: nop

    // 0x8002D1A4: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8002D1A8: add.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002D1AC: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8002D1B0: mov.s       $f26, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    ctx->f26.fl = ctx->f24.fl;
    // 0x8002D1B4: mul.s       $f10, $f24, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8002D1B8: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002D1BC: jal         0x800CA030
    // 0x8002D1C0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8002D1C0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x8002D1C4: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8002D1C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002D1CC: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8002D1D0: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8002D1D4: lw          $t1, 0xD0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD0);
    // 0x8002D1D8: bc1f        L_8002D1F8
    if (!c1cs) {
        // 0x8002D1DC: addiu       $t0, $zero, 0xA
        ctx->r8 = ADD32(0, 0XA);
            goto L_8002D1F8;
    }
    // 0x8002D1DC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8002D1E0: nop

    // 0x8002D1E4: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8002D1E8: nop

    // 0x8002D1EC: div.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8002D1F0: nop

    // 0x8002D1F4: div.s       $f26, $f24, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
L_8002D1F8:
    // 0x8002D1F8: beq         $s0, $s1, L_8002D230
    if (ctx->r16 == ctx->r17) {
        // 0x8002D1FC: sll         $t5, $s7, 3
        ctx->r13 = S32(ctx->r23 << 3);
            goto L_8002D230;
    }
    // 0x8002D1FC: sll         $t5, $s7, 3
    ctx->r13 = S32(ctx->r23 << 3);
    // 0x8002D200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002D204:
    // 0x8002D204: lw          $t8, 0x14($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X14);
    // 0x8002D208: sll         $t2, $s0, 3
    ctx->r10 = S32(ctx->r16 << 3);
    // 0x8002D20C: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8002D210: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x8002D214: lhu         $t3, 0x2($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X2);
    // 0x8002D218: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8002D21C: bne         $s1, $t3, L_8002D228
    if (ctx->r17 != ctx->r11) {
        // 0x8002D220: ori         $t4, $s4, 0x8000
        ctx->r12 = ctx->r20 | 0X8000;
            goto L_8002D228;
    }
    // 0x8002D220: ori         $t4, $s4, 0x8000
    ctx->r12 = ctx->r20 | 0X8000;
    // 0x8002D224: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
L_8002D228:
    // 0x8002D228: bne         $v0, $s3, L_8002D204
    if (ctx->r2 != ctx->r19) {
        // 0x8002D22C: nop
    
            goto L_8002D204;
    }
    // 0x8002D22C: nop

L_8002D230:
    // 0x8002D230: lw          $t6, 0x14($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X14);
    // 0x8002D234: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8002D238: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x8002D23C: addu        $t8, $t7, $s5
    ctx->r24 = ADD32(ctx->r15, ctx->r21);
    // 0x8002D240: sh          $s4, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r20;
    // 0x8002D244: lw          $t9, 0x18($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X18);
    // 0x8002D248: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x8002D24C: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8002D250: swc1        $f20, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f20.u32l;
    // 0x8002D254: lw          $t4, 0x18($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X18);
    // 0x8002D258: mul.s       $f8, $f28, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f20.fl);
    // 0x8002D25C: addu        $t6, $t4, $t2
    ctx->r14 = ADD32(ctx->r12, ctx->r10);
    // 0x8002D260: swc1        $f22, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f22.u32l;
    // 0x8002D264: lw          $t5, 0x18($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X18);
    // 0x8002D268: mul.s       $f10, $f30, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f22.fl);
    // 0x8002D26C: addu        $t7, $t5, $t2
    ctx->r15 = ADD32(ctx->r13, ctx->r10);
    // 0x8002D270: swc1        $f26, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f26.u32l;
    // 0x8002D274: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002D278: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002D27C: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x8002D280: mul.s       $f8, $f4, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x8002D284: addu        $t2, $t8, $t2
    ctx->r10 = ADD32(ctx->r24, ctx->r10);
    // 0x8002D288: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8002D28C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002D290: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8002D294: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
L_8002D298:
    // 0x8002D298: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002D29C: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x8002D2A0: bne         $s6, $at, L_8002D02C
    if (ctx->r22 != ctx->r1) {
        // 0x8002D2A4: addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
            goto L_8002D02C;
    }
    // 0x8002D2A4: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x8002D2A8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8002D2AC: nop

    // 0x8002D2B0: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
L_8002D2B4:
    // 0x8002D2B4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002D2B8: bne         $s7, $t9, L_8002CFCC
    if (ctx->r23 != ctx->r25) {
        // 0x8002D2BC: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8002CFCC;
    }
    // 0x8002D2BC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8002D2C0: lh          $a1, 0x20($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X20);
    // 0x8002D2C4: nop

L_8002D2C8:
    // 0x8002D2C8: lw          $t3, 0xEC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XEC);
    // 0x8002D2CC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8002D2D0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8002D2D4: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002D2D8: addiu       $t5, $t6, 0xC
    ctx->r13 = ADD32(ctx->r14, 0XC);
    // 0x8002D2DC: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x8002D2E0: bne         $at, $zero, L_8002CF84
    if (ctx->r1 != 0) {
        // 0x8002D2E4: sw          $t4, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r12;
            goto L_8002CF84;
    }
    // 0x8002D2E4: sw          $t4, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r12;
L_8002D2E8:
    // 0x8002D2E8: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
L_8002D2EC:
    // 0x8002D2EC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8002D2F0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002D2F4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002D2F8: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002D2FC: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002D300: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002D304: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002D308: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8002D30C: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002D310: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8002D314: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8002D318: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8002D31C: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002D320: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8002D324: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8002D328: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8002D32C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8002D330: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8002D334: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8002D338: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8002D33C: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x8002D340: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8002D344: jr          $ra
    // 0x8002D348: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8002D348: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void racer_attack_handler_hovercraft(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048CBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80048CC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80048CC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80048CC8: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80048CCC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80048CD0: bne         $t6, $at, L_80048CE0
    if (ctx->r14 != ctx->r1) {
        // 0x80048CD4: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_80048CE0;
    }
    // 0x80048CD4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80048CD8: b           L_80048CE8
    // 0x80048CDC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80048CE8;
    // 0x80048CDC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80048CE0:
    // 0x80048CE0: lb          $v1, 0x185($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X185);
    // 0x80048CE4: nop

L_80048CE8:
    // 0x80048CE8: lb          $v0, 0x187($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X187);
    // 0x80048CEC: nop

    // 0x80048CF0: beq         $v0, $zero, L_80048D08
    if (ctx->r2 == 0) {
        // 0x80048CF4: nop
    
            goto L_80048D08;
    }
    // 0x80048CF4: nop

    // 0x80048CF8: lh          $t7, 0x18E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18E);
    // 0x80048CFC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80048D00: blez        $t7, L_80048D10
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80048D04: nop
    
            goto L_80048D10;
    }
    // 0x80048D04: nop

L_80048D08:
    // 0x80048D08: b           L_80048E94
    // 0x80048D0C: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
        goto L_80048E94;
    // 0x80048D0C: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_80048D10:
    // 0x80048D10: beq         $v0, $at, L_80048D34
    if (ctx->r2 == ctx->r1) {
        // 0x80048D14: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80048D34;
    }
    // 0x80048D14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80048D18: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80048D1C: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    // 0x80048D20: jal         0x80057720
    // 0x80048D24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    drop_bananas(rdram, ctx);
        goto after_0;
    // 0x80048D24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80048D28: lb          $v1, 0x27($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X27);
    // 0x80048D2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80048D30: nop

L_80048D34:
    // 0x80048D34: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x80048D38: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80048D3C: addiu       $a3, $zero, 0x81
    ctx->r7 = ADD32(0, 0X81);
    // 0x80048D40: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    // 0x80048D44: jal         0x800570F8
    // 0x80048D48: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    play_random_character_voice(rdram, ctx);
        goto after_1;
    // 0x80048D48: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x80048D4C: lb          $t8, 0x187($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X187);
    // 0x80048D50: lb          $v1, 0x27($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X27);
    // 0x80048D54: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80048D58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80048D5C: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x80048D60: beq         $at, $zero, L_80048E90
    if (ctx->r1 == 0) {
        // 0x80048D64: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80048E90;
    }
    // 0x80048D64: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80048D68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048D6C: addu        $at, $at, $t9
    gpr jr_addend_80048D78 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80048D70: lw          $t9, 0x69FC($at)
    ctx->r25 = ADD32(ctx->r1, 0X69FC);
    // 0x80048D74: nop

    // 0x80048D78: jr          $t9
    // 0x80048D7C: nop

    switch (jr_addend_80048D78 >> 2) {
        case 0: goto L_80048D80; break;
        case 1: goto L_80048D80; break;
        case 2: goto L_80048E90; break;
        case 3: goto L_80048DEC; break;
        case 4: goto L_80048E58; break;
        case 5: goto L_80048DF8; break;
        default: switch_error(__func__, 0x80048D78, 0x800E69FC);
    }
    // 0x80048D7C: nop

L_80048D80:
    // 0x80048D80: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80048D84: bne         $v1, $zero, L_80048DA8
    if (ctx->r3 != 0) {
        // 0x80048D88: sb          $t0, 0x1F1($s0)
        MEM_B(0X1F1, ctx->r16) = ctx->r8;
            goto L_80048DA8;
    }
    // 0x80048D88: sb          $t0, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = ctx->r8;
    // 0x80048D8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80048D90: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80048D94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80048D98: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80048D9C: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80048DA0: b           L_80048E90
    // 0x80048DA4: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
        goto L_80048E90;
    // 0x80048DA4: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
L_80048DA8:
    // 0x80048DA8: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80048DAC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80048DB0: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80048DB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80048DB8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80048DBC: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80048DC0: lwc1        $f18, 0x24($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80048DC4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80048DC8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80048DCC: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80048DD0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80048DD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80048DD8: swc1        $f16, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f16.u32l;
    // 0x80048DDC: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x80048DE0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80048DE4: b           L_80048E90
    // 0x80048DE8: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
        goto L_80048E90;
    // 0x80048DE8: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
L_80048DEC:
    // 0x80048DEC: addiu       $t1, $zero, 0x3C
    ctx->r9 = ADD32(0, 0X3C);
    // 0x80048DF0: b           L_80048E90
    // 0x80048DF4: sb          $t1, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = ctx->r9;
        goto L_80048E90;
    // 0x80048DF4: sb          $t1, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = ctx->r9;
L_80048DF8:
    // 0x80048DF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048DFC: lwc1        $f1, 0x6A18($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6A18);
    // 0x80048E00: lwc1        $f0, 0x6A1C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6A1C);
    // 0x80048E04: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x80048E08: sh          $t2, 0x204($s0)
    MEM_H(0X204, ctx->r16) = ctx->r10;
    // 0x80048E0C: lwc1        $f16, 0x1C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80048E10: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80048E14: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80048E18: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80048E1C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80048E20: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80048E24: nop

    // 0x80048E28: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80048E2C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80048E30: bc1f        L_80048E3C
    if (!c1cs) {
        // 0x80048E34: swc1        $f6, 0x1C($a0)
        MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
            goto L_80048E3C;
    }
    // 0x80048E34: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x80048E38: swc1        $f2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f2.u32l;
L_80048E3C:
    // 0x80048E3C: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80048E40: nop

    // 0x80048E44: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80048E48: mul.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x80048E4C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80048E50: b           L_80048E90
    // 0x80048E54: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
        goto L_80048E90;
    // 0x80048E54: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
L_80048E58:
    // 0x80048E58: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80048E5C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80048E60: sb          $t3, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = ctx->r11;
    // 0x80048E64: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80048E68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048E6C: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80048E70: lwc1        $f11, 0x6A20($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6A20);
    // 0x80048E74: lwc1        $f10, 0x6A24($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6A24);
    // 0x80048E78: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80048E7C: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x80048E80: addiu       $a1, $zero, 0x139
    ctx->r5 = ADD32(0, 0X139);
    // 0x80048E84: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80048E88: jal         0x80057088
    // 0x80048E8C: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    racer_play_sound(rdram, ctx);
        goto after_2;
    // 0x80048E8C: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    after_2:
L_80048E90:
    // 0x80048E90: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_80048E94:
    // 0x80048E94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80048E98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80048E9C: jr          $ra
    // 0x80048EA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80048EA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
