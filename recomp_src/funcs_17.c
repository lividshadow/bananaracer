#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80001358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001358: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000135C: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x80001360: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80001364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001368: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000136C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80001370: beq         $a3, $at, L_800013C0
    if (ctx->r7 == ctx->r1) {
        // 0x80001374: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_800013C0;
    }
    // 0x80001374: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80001378: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000137C: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001380: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    // 0x80001384: jal         0x800C7F00
    // 0x80001388: sb          $a3, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r7;
    alCSPGetChlVol(rdram, ctx);
        goto after_0;
    // 0x80001388: sb          $a3, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000138C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80001390: lbu         $a3, 0x23($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X23);
    // 0x80001394: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80001398: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x8000139C: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x800013A0: bne         $at, $zero, L_800013AC
    if (ctx->r1 != 0) {
        // 0x800013A4: andi        $a2, $v1, 0xFF
        ctx->r6 = ctx->r3 & 0XFF;
            goto L_800013AC;
    }
    // 0x800013A4: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    // 0x800013A8: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
L_800013AC:
    // 0x800013AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800013B0: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x800013B4: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    // 0x800013B8: jal         0x800C7EA0
    // 0x800013BC: sb          $a2, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r6;
    alCSPSetChlVol(rdram, ctx);
        goto after_1;
    // 0x800013BC: sb          $a2, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r6;
    after_1:
L_800013C0:
    // 0x800013C0: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x800013C4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800013C8: beq         $t8, $at, L_8000141C
    if (ctx->r24 == ctx->r1) {
        // 0x800013CC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8000141C;
    }
    // 0x800013CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800013D0: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x800013D4: jal         0x800C7F00
    // 0x800013D8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    alCSPGetChlVol(rdram, ctx);
        goto after_2;
    // 0x800013D8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_2:
    // 0x800013DC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800013E0: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x800013E4: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800013E8: beq         $at, $zero, L_80001400
    if (ctx->r1 == 0) {
        // 0x800013EC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80001400;
    }
    // 0x800013EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800013F0: subu        $a2, $v0, $t9
    ctx->r6 = SUB32(ctx->r2, ctx->r25);
    // 0x800013F4: andi        $t0, $a2, 0xFF
    ctx->r8 = ctx->r6 & 0XFF;
    // 0x800013F8: b           L_80001404
    // 0x800013FC: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
        goto L_80001404;
    // 0x800013FC: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
L_80001400:
    // 0x80001400: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80001404:
    // 0x80001404: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001408: jal         0x800C7EA0
    // 0x8000140C: sb          $a2, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r6;
    alCSPSetChlVol(rdram, ctx);
        goto after_3;
    // 0x8000140C: sb          $a2, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r6;
    after_3:
    // 0x80001410: lbu         $v0, 0x1E($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1E);
    // 0x80001414: b           L_80001434
    // 0x80001418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80001434;
    // 0x80001418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000141C:
    // 0x8000141C: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
    // 0x80001420: addiu       $t2, $zero, 0x7F
    ctx->r10 = ADD32(0, 0X7F);
    // 0x80001424: subu        $v0, $t2, $t1
    ctx->r2 = SUB32(ctx->r10, ctx->r9);
    // 0x80001428: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x8000142C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80001430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001434:
    // 0x80001434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80001438: jr          $ra
    // 0x8000143C: nop

    return;
    // 0x8000143C: nop

;}
RECOMP_FUNC void drop_bananas(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057720: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80057724: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80057728: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8005772C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80057730: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80057734: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80057738: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005773C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80057740: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80057744: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80057748: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8005774C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80057750: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80057754: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x80057758: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8005775C: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80057760: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80057764: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80057768: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8005776C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80057770: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80057774: jal         0x8009C850
    // 0x80057778: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x80057778: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x8005777C: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x80057780: bne         $t6, $zero, L_800579A4
    if (ctx->r14 != 0) {
        // 0x80057784: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800579A4;
    }
    // 0x80057784: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80057788: lb          $v0, 0x185($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X185);
    // 0x8005778C: sb          $zero, 0x188($s0)
    MEM_B(0X188, ctx->r16) = 0;
    // 0x80057790: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80057794: beq         $at, $zero, L_800577A0
    if (ctx->r1 == 0) {
        // 0x80057798: nop
    
            goto L_800577A0;
    }
    // 0x80057798: nop

    // 0x8005779C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800577A0:
    // 0x800577A0: blez        $s1, L_800579A0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800577A4: slti        $at, $s1, 0x3
        ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
            goto L_800579A0;
    }
    // 0x800577A4: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x800577A8: beq         $at, $zero, L_800579A0
    if (ctx->r1 == 0) {
        // 0x800577AC: addiu       $t0, $zero, 0x8
        ctx->r8 = ADD32(0, 0X8);
            goto L_800579A0;
    }
    // 0x800577AC: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x800577B0: lh          $t7, 0x1A4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A4);
    // 0x800577B4: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800577B8: sh          $t7, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r15;
    // 0x800577BC: lh          $t8, 0x2($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X2);
    // 0x800577C0: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x800577C4: sh          $t8, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r24;
    // 0x800577C8: lh          $t9, 0x1A0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A0);
    // 0x800577CC: sh          $zero, 0x70($sp)
    MEM_H(0X70, ctx->r29) = 0;
    // 0x800577D0: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
    // 0x800577D4: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x800577D8: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x800577DC: jal         0x80070424
    // 0x800577E0: sh          $t9, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r25;
    vec3s_rotate_rpy(rdram, ctx);
        goto after_1;
    // 0x800577E0: sh          $t9, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r25;
    after_1:
    // 0x800577E4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800577E8: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800577EC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800577F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800577F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800577F8: lh          $t2, 0x70($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X70);
    // 0x800577FC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80057800: lh          $t6, 0x72($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X72);
    // 0x80057804: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80057808: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x8005780C: lh          $t0, 0x74($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X74);
    // 0x80057810: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80057814: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80057818: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8005781C: sh          $t5, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r13;
    // 0x80057820: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80057824: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80057828: lwc1        $f8, 0x10($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8005782C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80057830: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80057834: addiu       $t5, $zero, 0x53
    ctx->r13 = ADD32(0, 0X53);
    // 0x80057838: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005783C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80057840: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80057844: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80057848: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8005784C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80057850: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80057854: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80057858: sh          $t9, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r25;
    // 0x8005785C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80057860: lwc1        $f16, 0x14($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80057864: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80057868: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8005786C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80057870: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80057874: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80057878: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8005787C: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x80057880: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80057884: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80057888: addu        $t2, $t0, $t3
    ctx->r10 = ADD32(ctx->r8, ctx->r11);
    // 0x8005788C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80057890: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80057894: sh          $t2, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r10;
    // 0x80057898: sb          $t4, 0x89($sp)
    MEM_B(0X89, ctx->r29) = ctx->r12;
    // 0x8005789C: sb          $t5, 0x88($sp)
    MEM_B(0X88, ctx->r29) = ctx->r13;
    // 0x800578A0: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x800578A4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800578A8: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800578AC: addiu       $s5, $sp, 0x88
    ctx->r21 = ADD32(ctx->r29, 0X88);
    // 0x800578B0: addiu       $s4, $zero, 0x40
    ctx->r20 = ADD32(0, 0X40);
L_800578B4:
    // 0x800578B4: jal         0x8006BFD8
    // 0x800578B8: nop

    level_type(rdram, ctx);
        goto after_2;
    // 0x800578B8: nop

    after_2:
    // 0x800578BC: beq         $s4, $v0, L_8005798C
    if (ctx->r20 == ctx->r2) {
        // 0x800578C0: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8005798C;
    }
    // 0x800578C0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800578C4: jal         0x8000EA54
    // 0x800578C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    spawn_object(rdram, ctx);
        goto after_3;
    // 0x800578C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x800578CC: beq         $v0, $zero, L_8005798C
    if (ctx->r2 == 0) {
        // 0x800578D0: nop
    
            goto L_8005798C;
    }
    // 0x800578D0: nop

    // 0x800578D4: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800578D8: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x800578DC: lb          $t7, 0x1D6($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D6);
    // 0x800578E0: nop

    // 0x800578E4: sb          $t7, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r15;
    // 0x800578E8: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800578EC: nop

    // 0x800578F0: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800578F4: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x800578F8: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800578FC: nop

    // 0x80057900: sub.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x80057904: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80057908: add.d       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f22.d); 
    ctx->f18.d = ctx->f16.d + ctx->f22.d;
    // 0x8005790C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80057910: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x80057914: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80057918: nop

    // 0x8005791C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80057920: bne         $s3, $s6, L_80057988
    if (ctx->r19 != ctx->r22) {
        // 0x80057924: swc1        $f8, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
            goto L_80057988;
    }
    // 0x80057924: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x80057928: bne         $s1, $s2, L_80057934
    if (ctx->r17 != ctx->r18) {
        // 0x8005792C: mov.s       $f0, $f26
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    ctx->f0.fl = ctx->f26.fl;
            goto L_80057934;
    }
    // 0x8005792C: mov.s       $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    ctx->f0.fl = ctx->f26.fl;
    // 0x80057930: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
L_80057934:
    // 0x80057934: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80057938: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8005793C: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80057940: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80057944: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80057948: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8005794C: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80057950: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x80057954: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80057958: nop

    // 0x8005795C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80057960: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80057964: lwc1        $f18, 0x24($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80057968: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x8005796C: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80057970: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80057974: nop

    // 0x80057978: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8005797C: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80057980: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80057984: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
L_80057988:
    // 0x80057988: sw          $s2, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r18;
L_8005798C:
    // 0x8005798C: lb          $t6, 0x185($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X185);
    // 0x80057990: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80057994: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x80057998: bgtz        $s1, L_800578B4
    if (SIGNED(ctx->r17) > 0) {
        // 0x8005799C: sb          $t8, 0x185($s0)
        MEM_B(0X185, ctx->r16) = ctx->r24;
            goto L_800578B4;
    }
    // 0x8005799C: sb          $t8, 0x185($s0)
    MEM_B(0X185, ctx->r16) = ctx->r24;
L_800579A0:
    // 0x800579A0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_800579A4:
    // 0x800579A4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800579A8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800579AC: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800579B0: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800579B4: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800579B8: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800579BC: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800579C0: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800579C4: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800579C8: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800579CC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800579D0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800579D4: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800579D8: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800579DC: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800579E0: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800579E4: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800579E8: jr          $ra
    // 0x800579EC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800579EC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void find_furthest_telepoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023460: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80023464: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80023468: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002346C: addiu       $s3, $s3, -0x4C24
    ctx->r19 = ADD32(ctx->r19, -0X4C24);
    // 0x80023470: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80023474: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80023478: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002347C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80023480: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80023484: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80023488: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002348C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80023490: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80023494: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x80023498: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x8002349C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800234A0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800234A4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800234A8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800234AC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800234B0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800234B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800234B8: blez        $t6, L_80023558
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800234BC: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_80023558;
    }
    // 0x800234BC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800234C0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800234C4: addiu       $s4, $s4, -0x4C28
    ctx->r20 = ADD32(ctx->r20, -0X4C28);
    // 0x800234C8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800234CC: addiu       $s5, $zero, 0x57
    ctx->r21 = ADD32(0, 0X57);
L_800234D0:
    // 0x800234D0: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800234D4: nop

    // 0x800234D8: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800234DC: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800234E0: nop

    // 0x800234E4: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x800234E8: nop

    // 0x800234EC: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x800234F0: bne         $t0, $zero, L_80023544
    if (ctx->r8 != 0) {
        // 0x800234F4: nop
    
            goto L_80023544;
    }
    // 0x800234F4: nop

    // 0x800234F8: lh          $t1, 0x48($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X48);
    // 0x800234FC: nop

    // 0x80023500: bne         $s5, $t1, L_80023544
    if (ctx->r21 != ctx->r9) {
        // 0x80023504: nop
    
            goto L_80023544;
    }
    // 0x80023504: nop

    // 0x80023508: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002350C: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80023510: sub.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80023514: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80023518: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8002351C: sub.s       $f2, $f6, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f24.fl;
    // 0x80023520: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80023524: jal         0x800CA030
    // 0x80023528: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80023528: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8002352C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80023530: nop

    // 0x80023534: bc1f        L_80023544
    if (!c1cs) {
        // 0x80023538: nop
    
            goto L_80023544;
    }
    // 0x80023538: nop

    // 0x8002353C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80023540: or          $s6, $s0, $zero
    ctx->r22 = ctx->r16 | 0;
L_80023544:
    // 0x80023544: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80023548: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002354C: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80023550: bne         $at, $zero, L_800234D0
    if (ctx->r1 != 0) {
        // 0x80023554: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800234D0;
    }
    // 0x80023554: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80023558:
    // 0x80023558: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8002355C: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x80023560: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80023564: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80023568: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002356C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80023570: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80023574: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80023578: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002357C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80023580: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80023584: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80023588: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8002358C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80023590: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80023594: jr          $ra
    // 0x80023598: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80023598: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void sound_clear_delayed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001050: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001054: jr          $ra
    // 0x80001058: sw          $zero, -0x3438($at)
    MEM_W(-0X3438, ctx->r1) = 0;
    return;
    // 0x80001058: sw          $zero, -0x3438($at)
    MEM_W(-0X3438, ctx->r1) = 0;
;}
RECOMP_FUNC void alAuxBusNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065268: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006526C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80065270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065274: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80065278: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x8006527C: addiu       $a1, $a1, 0x5B40
    ctx->r5 = ADD32(ctx->r5, 0X5B40);
    // 0x80065280: addiu       $a2, $a2, 0x5C14
    ctx->r6 = ADD32(ctx->r6, 0X5C14);
    // 0x80065284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065288: jal         0x800CA610
    // 0x8006528C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x8006528C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x80065290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80065294: nop

    // 0x80065298: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8006529C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800652A0: nop

    // 0x800652A4: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800652A8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800652AC: nop

    // 0x800652B0: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x800652B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800652B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800652BC: jr          $ra
    // 0x800652C0: nop

    return;
    // 0x800652C0: nop

;}
RECOMP_FUNC void dialogue_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C59F4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C59F8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C59FC: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C5A00: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5A04: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C5A08: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5A0C: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x800C5A10: nop

    // 0x800C5A14: beq         $v1, $zero, L_800C5A40
    if (ctx->r3 == 0) {
        // 0x800C5A18: nop
    
            goto L_800C5A40;
    }
    // 0x800C5A18: nop

    // 0x800C5A1C: beq         $v1, $zero, L_800C5A3C
    if (ctx->r3 == 0) {
        // 0x800C5A20: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800C5A3C;
    }
    // 0x800C5A20: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800C5A24: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_800C5A28:
    // 0x800C5A28: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
    // 0x800C5A2C: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    // 0x800C5A30: nop

    // 0x800C5A34: bne         $a0, $zero, L_800C5A28
    if (ctx->r4 != 0) {
        // 0x800C5A38: nop
    
            goto L_800C5A28;
    }
    // 0x800C5A38: nop

L_800C5A3C:
    // 0x800C5A3C: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
L_800C5A40:
    // 0x800C5A40: jr          $ra
    // 0x800C5A44: nop

    return;
    // 0x800C5A44: nop

;}
RECOMP_FUNC void bgdraw_set_func(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078EFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80078F00: jr          $ra
    // 0x80078F04: sw          $a0, -0x15B0($at)
    MEM_W(-0X15B0, ctx->r1) = ctx->r4;
    return;
    // 0x80078F04: sw          $a0, -0x15B0($at)
    MEM_W(-0X15B0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void alSeqChOn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063D84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063D88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063D8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80063D90: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80063D94: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80063D98: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80063D9C: addiu       $t7, $zero, 0xB0
    ctx->r15 = ADD32(0, 0XB0);
    // 0x80063DA0: addiu       $t8, $zero, 0x6C
    ctx->r24 = ADD32(0, 0X6C);
    // 0x80063DA4: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80063DA8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80063DAC: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80063DB0: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x80063DB4: sb          $a3, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r7;
    // 0x80063DB8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063DBC: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80063DC0: jal         0x800C970C
    // 0x80063DC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80063DC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80063DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063DCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80063DD0: jr          $ra
    // 0x80063DD4: nop

    return;
    // 0x80063DD4: nop

;}
RECOMP_FUNC void hud_weapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7A7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A7A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7A84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A7A88: lw          $t1, 0x64($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X64);
    // 0x800A7A8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A7A90: lb          $t6, 0x1D8($t1)
    ctx->r14 = MEM_B(ctx->r9, 0X1D8);
    // 0x800A7A94: nop

    // 0x800A7A98: bne         $t6, $zero, L_800A7FB0
    if (ctx->r14 != 0) {
        // 0x800A7A9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A7FB0;
    }
    // 0x800A7A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7AA0: jal         0x800662D8
    // 0x800A7AA4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_0;
    // 0x800A7AA4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_0:
    // 0x800A7AA8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7AAC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7AB0: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A7AB4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7AB8: lb          $t7, 0x172($t1)
    ctx->r15 = MEM_B(ctx->r9, 0X172);
    // 0x800A7ABC: lb          $v1, 0x174($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X174);
    // 0x800A7AC0: lb          $t9, 0x5D($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X5D);
    // 0x800A7AC4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A7AC8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A7ACC: beq         $v1, $t9, L_800A7B1C
    if (ctx->r3 == ctx->r25) {
        // 0x800A7AD0: addu        $a0, $t8, $v1
        ctx->r4 = ADD32(ctx->r24, ctx->r3);
            goto L_800A7B1C;
    }
    // 0x800A7AD0: addu        $a0, $t8, $v1
    ctx->r4 = ADD32(ctx->r24, ctx->r3);
    // 0x800A7AD4: bne         $v1, $zero, L_800A7AE8
    if (ctx->r3 != 0) {
        // 0x800A7AD8: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800A7AE8;
    }
    // 0x800A7AD8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A7ADC: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x800A7AE0: b           L_800A7B04
    // 0x800A7AE4: sb          $t2, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r10;
        goto L_800A7B04;
    // 0x800A7AE4: sb          $t2, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r10;
L_800A7AE8:
    // 0x800A7AE8: lbu         $t3, 0x72F7($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X72F7);
    // 0x800A7AEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A7AF0: bne         $t3, $at, L_800A7B00
    if (ctx->r11 != ctx->r1) {
        // 0x800A7AF4: addiu       $t4, $zero, 0x78
        ctx->r12 = ADD32(0, 0X78);
            goto L_800A7B00;
    }
    // 0x800A7AF4: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x800A7AF8: b           L_800A7B04
    // 0x800A7AFC: sb          $zero, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = 0;
        goto L_800A7B04;
    // 0x800A7AFC: sb          $zero, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = 0;
L_800A7B00:
    // 0x800A7B00: sb          $t4, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r12;
L_800A7B04:
    // 0x800A7B04: lb          $t5, 0x174($t1)
    ctx->r13 = MEM_B(ctx->r9, 0X174);
    // 0x800A7B08: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A7B0C: nop

    // 0x800A7B10: sb          $t5, 0x5D($t6)
    MEM_B(0X5D, ctx->r14) = ctx->r13;
    // 0x800A7B14: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7B18: nop

L_800A7B1C:
    // 0x800A7B1C: lb          $t7, 0x173($t1)
    ctx->r15 = MEM_B(ctx->r9, 0X173);
    // 0x800A7B20: nop

    // 0x800A7B24: blez        $t7, L_800A7E9C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A7B28: nop
    
            goto L_800A7E9C;
    }
    // 0x800A7B28: nop

    // 0x800A7B2C: lb          $v1, 0x5B($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7B30: nop

    // 0x800A7B34: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x800A7B38: beq         $at, $zero, L_800A7B94
    if (ctx->r1 == 0) {
        // 0x800A7B3C: nop
    
            goto L_800A7B94;
    }
    // 0x800A7B3C: nop

    // 0x800A7B40: lh          $t8, 0x170($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X170);
    // 0x800A7B44: sll         $t9, $v1, 12
    ctx->r25 = S32(ctx->r3 << 12);
    // 0x800A7B48: bne         $t8, $zero, L_800A7B94
    if (ctx->r24 != 0) {
        // 0x800A7B4C: nop
    
            goto L_800A7B94;
    }
    // 0x800A7B4C: nop

    // 0x800A7B50: sh          $t9, 0x44($v0)
    MEM_H(0X44, ctx->r2) = ctx->r25;
    // 0x800A7B54: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7B58: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A7B5C: lb          $t2, 0x5B($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7B60: lwc1        $f9, -0x7300($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X7300);
    // 0x800A7B64: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800A7B68: lwc1        $f8, -0x72FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X72FC);
    // 0x800A7B6C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800A7B70: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x800A7B74: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A7B78: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800A7B7C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A7B80: nop

    // 0x800A7B84: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x800A7B88: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800A7B8C: b           L_800A7BAC
    // 0x800A7B90: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
        goto L_800A7BAC;
    // 0x800A7B90: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
L_800A7B94:
    // 0x800A7B94: sh          $zero, 0x44($v0)
    MEM_H(0X44, ctx->r2) = 0;
    // 0x800A7B98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A7B9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A7BA0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A7BA4: nop

    // 0x800A7BA8: swc1        $f6, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->f6.u32l;
L_800A7BAC:
    // 0x800A7BAC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A7BB0: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x800A7BB4: sh          $a0, 0x58($t4)
    MEM_H(0X58, ctx->r12) = ctx->r4;
    // 0x800A7BB8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7BBC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800A7BC0: lb          $t5, 0x5B($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7BC4: nop

    // 0x800A7BC8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800A7BCC: sb          $t7, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = ctx->r15;
    // 0x800A7BD0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7BD4: nop

    // 0x800A7BD8: lb          $t8, 0x5B($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7BDC: nop

    // 0x800A7BE0: slti        $at, $t8, 0x11
    ctx->r1 = SIGNED(ctx->r24) < 0X11 ? 1 : 0;
    // 0x800A7BE4: bne         $at, $zero, L_800A7CE8
    if (ctx->r1 != 0) {
        // 0x800A7BE8: nop
    
            goto L_800A7CE8;
    }
    // 0x800A7BE8: nop

    // 0x800A7BEC: sb          $t9, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = ctx->r25;
    // 0x800A7BF0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7BF4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800A7BF8: lb          $t2, 0x5C($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X5C);
    // 0x800A7BFC: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x800A7C00: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800A7C04: sb          $t4, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r12;
    // 0x800A7C08: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7C0C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A7C10: lb          $v1, 0x5C($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X5C);
    // 0x800A7C14: nop

    // 0x800A7C18: slti        $at, $v1, 0x79
    ctx->r1 = SIGNED(ctx->r3) < 0X79 ? 1 : 0;
    // 0x800A7C1C: bne         $at, $zero, L_800A7C34
    if (ctx->r1 != 0) {
        // 0x800A7C20: nop
    
            goto L_800A7C34;
    }
    // 0x800A7C20: nop

    // 0x800A7C24: sb          $t5, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r13;
    // 0x800A7C28: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7C2C: b           L_800A7CE8
    // 0x800A7C30: nop

        goto L_800A7CE8;
    // 0x800A7C30: nop

L_800A7C34:
    // 0x800A7C34: lw          $t6, 0x72CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72CC);
    // 0x800A7C38: nop

    // 0x800A7C3C: bne         $t6, $zero, L_800A7CE8
    if (ctx->r14 != 0) {
        // 0x800A7C40: nop
    
            goto L_800A7CE8;
    }
    // 0x800A7C40: nop

    // 0x800A7C44: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A7C48: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A7C4C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A7C50: lwc1        $f19, -0x72F8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X72F8);
    // 0x800A7C54: lwc1        $f18, -0x72F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X72F4);
    // 0x800A7C58: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800A7C5C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800A7C60: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800A7C64: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800A7C68: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A7C6C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800A7C70: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800A7C74: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A7C78: nop

    // 0x800A7C7C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A7C80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7C84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7C88: nop

    // 0x800A7C8C: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800A7C90: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x800A7C94: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A7C98: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x800A7C9C: jal         0x80070A04
    // 0x800A7CA0: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    sins_f(rdram, ctx);
        goto after_1;
    // 0x800A7CA0: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_1:
    // 0x800A7CA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A7CA8: lwc1        $f17, -0x72F0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X72F0);
    // 0x800A7CAC: lwc1        $f16, -0x72EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X72EC);
    // 0x800A7CB0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7CB4: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A7CB8: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x800A7CBC: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800A7CC0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7CC4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7CC8: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800A7CCC: nop

    // 0x800A7CD0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A7CD4: add.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d + ctx->f4.d;
    // 0x800A7CD8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800A7CDC: swc1        $f16, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
    // 0x800A7CE0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7CE4: nop

L_800A7CE8:
    // 0x800A7CE8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A7CEC: lw          $t2, 0x72CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72CC);
    // 0x800A7CF0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A7CF4: blez        $t2, L_800A7D20
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800A7CF8: lui         $at, 0x3FE8
        ctx->r1 = S32(0X3FE8 << 16);
            goto L_800A7D20;
    }
    // 0x800A7CF8: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x800A7CFC: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800A7D00: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A7D04: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A7D08: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x800A7D0C: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800A7D10: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x800A7D14: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
    // 0x800A7D18: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7D1C: nop

L_800A7D20:
    // 0x800A7D20: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800A7D24: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800A7D28: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A7D2C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x800A7D30: c.eq.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d == ctx->f6.d;
    // 0x800A7D34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A7D38: bc1t        L_800A7D5C
    if (c1cs) {
        // 0x800A7D3C: nop
    
            goto L_800A7D5C;
    }
    // 0x800A7D3C: nop

    // 0x800A7D40: jal         0x8007C36C
    // 0x800A7D44: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    sprite_opaque(rdram, ctx);
        goto after_2;
    // 0x800A7D44: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_2:
    // 0x800A7D48: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7D4C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A7D50: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7D54: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7D58: nop

L_800A7D5C:
    // 0x800A7D5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7D60: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7D64: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7D68: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7D6C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A7D70: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7D74: addiu       $a3, $v0, 0x40
    ctx->r7 = ADD32(ctx->r2, 0X40);
    // 0x800A7D78: jal         0x800AAB5C
    // 0x800A7D7C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    hud_element_render(rdram, ctx);
        goto after_3;
    // 0x800A7D7C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_3:
    // 0x800A7D80: jal         0x8007C36C
    // 0x800A7D84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_4;
    // 0x800A7D84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800A7D88: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7D8C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7D90: lb          $v1, 0x173($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X173);
    // 0x800A7D94: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A7D98: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800A7D9C: bne         $at, $zero, L_800A7DB8
    if (ctx->r1 != 0) {
        // 0x800A7DA0: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A7DB8;
    }
    // 0x800A7DA0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7DA4: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A7DA8: addiu       $t3, $zero, -0x80
    ctx->r11 = ADD32(0, -0X80);
    // 0x800A7DAC: sb          $t3, 0x63A($t4)
    MEM_B(0X63A, ctx->r12) = ctx->r11;
    // 0x800A7DB0: lb          $v1, 0x173($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X173);
    // 0x800A7DB4: nop

L_800A7DB8:
    // 0x800A7DB8: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A7DBC: beq         $at, $zero, L_800A7DE4
    if (ctx->r1 == 0) {
        // 0x800A7DC0: addiu       $a0, $a0, 0x72BC
        ctx->r4 = ADD32(ctx->r4, 0X72BC);
            goto L_800A7DE4;
    }
    // 0x800A7DC0: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7DC4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7DC8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800A7DCC: lb          $t5, 0x63A($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X63A);
    // 0x800A7DD0: nop

    // 0x800A7DD4: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x800A7DD8: sb          $t7, 0x63A($v0)
    MEM_B(0X63A, ctx->r2) = ctx->r15;
    // 0x800A7DDC: lb          $v1, 0x173($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X173);
    // 0x800A7DE0: nop

L_800A7DE4:
    // 0x800A7DE4: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A7DE8: beq         $at, $zero, L_800A7E2C
    if (ctx->r1 == 0) {
        // 0x800A7DEC: lui         $t5, 0xFA00
        ctx->r13 = S32(0XFA00 << 16);
            goto L_800A7E2C;
    }
    // 0x800A7DEC: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800A7DF0: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A7DF4: nop

    // 0x800A7DF8: lb          $t9, 0x63A($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X63A);
    // 0x800A7DFC: nop

    // 0x800A7E00: addiu       $t2, $t9, 0x80
    ctx->r10 = ADD32(ctx->r25, 0X80);
    // 0x800A7E04: bgez        $t2, L_800A7E18
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A7E08: andi        $t3, $t2, 0x1F
        ctx->r11 = ctx->r10 & 0X1F;
            goto L_800A7E18;
    }
    // 0x800A7E08: andi        $t3, $t2, 0x1F
    ctx->r11 = ctx->r10 & 0X1F;
    // 0x800A7E0C: beq         $t3, $zero, L_800A7E18
    if (ctx->r11 == 0) {
        // 0x800A7E10: nop
    
            goto L_800A7E18;
    }
    // 0x800A7E10: nop

    // 0x800A7E14: addiu       $t3, $t3, -0x20
    ctx->r11 = ADD32(ctx->r11, -0X20);
L_800A7E18:
    // 0x800A7E18: slti        $at, $t3, 0x14
    ctx->r1 = SIGNED(ctx->r11) < 0X14 ? 1 : 0;
    // 0x800A7E1C: beq         $at, $zero, L_800A7E94
    if (ctx->r1 == 0) {
        // 0x800A7E20: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800A7E94;
    }
    // 0x800A7E20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A7E24: beq         $v1, $at, L_800A7E94
    if (ctx->r3 == ctx->r1) {
        // 0x800A7E28: nop
    
            goto L_800A7E94;
    }
    // 0x800A7E28: nop

L_800A7E2C:
    // 0x800A7E2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A7E30: addiu       $t6, $zero, -0x60
    ctx->r14 = ADD32(0, -0X60);
    // 0x800A7E34: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800A7E38: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800A7E3C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A7E40: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800A7E44: lb          $t7, 0x173($t1)
    ctx->r15 = MEM_B(ctx->r9, 0X173);
    // 0x800A7E48: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A7E4C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800A7E50: sh          $t8, 0x638($t9)
    MEM_H(0X638, ctx->r25) = ctx->r24;
    // 0x800A7E54: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A7E58: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7E5C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7E60: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7E64: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A7E68: jal         0x800AAB5C
    // 0x800A7E6C: addiu       $a3, $a3, 0x620
    ctx->r7 = ADD32(ctx->r7, 0X620);
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A7E6C: addiu       $a3, $a3, 0x620
    ctx->r7 = ADD32(ctx->r7, 0X620);
    after_5:
    // 0x800A7E70: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7E74: addiu       $a1, $a1, 0x72BC
    ctx->r5 = ADD32(ctx->r5, 0X72BC);
    // 0x800A7E78: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A7E7C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A7E80: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800A7E84: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800A7E88: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800A7E8C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A7E90: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_800A7E94:
    // 0x800A7E94: b           L_800A7F80
    // 0x800A7E98: nop

        goto L_800A7F80;
    // 0x800A7E98: nop

L_800A7E9C:
    // 0x800A7E9C: lb          $v1, 0x5B($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7EA0: nop

    // 0x800A7EA4: blez        $v1, L_800A7F80
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A7EA8: sll         $t5, $v1, 12
        ctx->r13 = S32(ctx->r3 << 12);
            goto L_800A7F80;
    }
    // 0x800A7EA8: sll         $t5, $v1, 12
    ctx->r13 = S32(ctx->r3 << 12);
    // 0x800A7EAC: sh          $t5, 0x44($v0)
    MEM_H(0X44, ctx->r2) = ctx->r13;
    // 0x800A7EB0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7EB4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A7EB8: lb          $t6, 0x5B($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7EBC: lwc1        $f11, -0x72E8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X72E8);
    // 0x800A7EC0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800A7EC4: lwc1        $f10, -0x72E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X72E4);
    // 0x800A7EC8: cvt.d.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
    // 0x800A7ECC: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x800A7ED0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A7ED4: mul.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800A7ED8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A7EDC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7EE0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7EE4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A7EE8: add.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f18.d + ctx->f16.d;
    // 0x800A7EEC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A7EF0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800A7EF4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7EF8: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    // 0x800A7EFC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7F00: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800A7F04: lb          $t7, 0x5B($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7F08: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A7F0C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800A7F10: sb          $t9, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = ctx->r25;
    // 0x800A7F14: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800A7F18: nop

    // 0x800A7F1C: sh          $a0, 0x58($t2)
    MEM_H(0X58, ctx->r10) = ctx->r4;
    // 0x800A7F20: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7F24: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7F28: lb          $t3, 0x5B($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7F2C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7F30: bgez        $t3, L_800A7F48
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A7F34: nop
    
            goto L_800A7F48;
    }
    // 0x800A7F34: nop

    // 0x800A7F38: sb          $zero, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = 0;
    // 0x800A7F3C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7F40: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A7F44: nop

L_800A7F48:
    // 0x800A7F48: lw          $t4, 0x72CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72CC);
    // 0x800A7F4C: nop

    // 0x800A7F50: beq         $t4, $zero, L_800A7F78
    if (ctx->r12 == 0) {
        // 0x800A7F54: nop
    
            goto L_800A7F78;
    }
    // 0x800A7F54: nop

    // 0x800A7F58: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800A7F5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A7F60: nop

    // 0x800A7F64: div.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800A7F68: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x800A7F6C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7F70: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A7F74: nop

L_800A7F78:
    // 0x800A7F78: jal         0x800AAB5C
    // 0x800A7F7C: addiu       $a3, $v0, 0x40
    ctx->r7 = ADD32(ctx->r2, 0X40);
    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A7F7C: addiu       $a3, $v0, 0x40
    ctx->r7 = ADD32(ctx->r2, 0X40);
    after_6:
L_800A7F80:
    // 0x800A7F80: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7F84: addiu       $a1, $a1, 0x72BC
    ctx->r5 = ADD32(ctx->r5, 0X72BC);
    // 0x800A7F88: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A7F8C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A7F90: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800A7F94: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800A7F98: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A7F9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A7FA0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800A7FA4: jal         0x800662D8
    // 0x800A7FA8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_7;
    // 0x800A7FA8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_7:
    // 0x800A7FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7FB0:
    // 0x800A7FB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A7FB4: jr          $ra
    // 0x800A7FB8: nop

    return;
    // 0x800A7FB8: nop

;}
RECOMP_FUNC void audspat_calculate_spatial_pan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800090C0: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800090C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800090C8: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x800090CC: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800090D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800090D4: mul.s       $f16, $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800090D8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800090DC: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x800090E0: jal         0x800CA030
    // 0x800090E4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800090E4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x800090E8: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800090EC: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800090F0: jal         0x80070990
    // 0x800090F4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    arctan2_f(rdram, ctx);
        goto after_1;
    // 0x800090F4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800090F8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800090FC: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x80009100: subu        $v1, $t6, $v0
    ctx->r3 = SUB32(ctx->r14, ctx->r2);
    // 0x80009104: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80009108: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8000910C: beq         $at, $zero, L_800091CC
    if (ctx->r1 == 0) {
        // 0x80009110: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_800091CC;
    }
    // 0x80009110: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80009114: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009118: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000911C: subu        $a0, $a2, $a1
    ctx->r4 = SUB32(ctx->r6, ctx->r5);
    // 0x80009120: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x80009124: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x80009128: bc1f        L_800091A8
    if (!c1cs) {
        // 0x8000912C: nop
    
            goto L_800091A8;
    }
    // 0x8000912C: nop

    // 0x80009130: subu        $a0, $a2, $v1
    ctx->r4 = SUB32(ctx->r6, ctx->r3);
    // 0x80009134: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80009138: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8000913C: jal         0x80070A70
    // 0x80009140: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    static_3_80070A70(rdram, ctx);
        goto after_2;
    // 0x80009140: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80009144: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80009148: bgez        $v0, L_80009158
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000914C: sra         $t9, $v0, 10
        ctx->r25 = S32(SIGNED(ctx->r2) >> 10);
            goto L_80009158;
    }
    // 0x8000914C: sra         $t9, $v0, 10
    ctx->r25 = S32(SIGNED(ctx->r2) >> 10);
    // 0x80009150: addiu       $at, $v0, 0x3FF
    ctx->r1 = ADD32(ctx->r2, 0X3FF);
    // 0x80009154: sra         $t9, $at, 10
    ctx->r25 = S32(SIGNED(ctx->r1) >> 10);
L_80009158:
    // 0x80009158: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000915C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80009160: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80009164: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80009168: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8000916C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80009170: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80009174: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80009178: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8000917C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80009180: nop

    // 0x80009184: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80009188: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000918C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80009190: nop

    // 0x80009194: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80009198: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8000919C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800091A0: b           L_8000927C
    // 0x800091A4: nop

        goto L_8000927C;
    // 0x800091A4: nop

L_800091A8:
    // 0x800091A8: jal         0x80070AD0
    // 0x800091AC: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    static_3_80070AD0(rdram, ctx);
        goto after_3;
    // 0x800091AC: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    after_3:
    // 0x800091B0: bgez        $v0, L_800091C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800091B4: sra         $t3, $v0, 10
        ctx->r11 = S32(SIGNED(ctx->r2) >> 10);
            goto L_800091C0;
    }
    // 0x800091B4: sra         $t3, $v0, 10
    ctx->r11 = S32(SIGNED(ctx->r2) >> 10);
    // 0x800091B8: addiu       $at, $v0, 0x3FF
    ctx->r1 = ADD32(ctx->r2, 0X3FF);
    // 0x800091BC: sra         $t3, $at, 10
    ctx->r11 = S32(SIGNED(ctx->r1) >> 10);
L_800091C0:
    // 0x800091C0: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x800091C4: b           L_8000927C
    // 0x800091C8: subu        $v1, $t4, $t3
    ctx->r3 = SUB32(ctx->r12, ctx->r11);
        goto L_8000927C;
    // 0x800091C8: subu        $v1, $t4, $t3
    ctx->r3 = SUB32(ctx->r12, ctx->r11);
L_800091CC:
    // 0x800091CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800091D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800091D4: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x800091D8: c.le.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl <= ctx->f18.fl;
    // 0x800091DC: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x800091E0: bc1f        L_80009260
    if (!c1cs) {
        // 0x800091E4: nop
    
            goto L_80009260;
    }
    // 0x800091E4: nop

    // 0x800091E8: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x800091EC: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800091F0: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800091F4: jal         0x80070A70
    // 0x800091F8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    static_3_80070A70(rdram, ctx);
        goto after_4;
    // 0x800091F8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x800091FC: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80009200: bgez        $v0, L_80009210
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80009204: sra         $t7, $v0, 10
        ctx->r15 = S32(SIGNED(ctx->r2) >> 10);
            goto L_80009210;
    }
    // 0x80009204: sra         $t7, $v0, 10
    ctx->r15 = S32(SIGNED(ctx->r2) >> 10);
    // 0x80009208: addiu       $at, $v0, 0x3FF
    ctx->r1 = ADD32(ctx->r2, 0X3FF);
    // 0x8000920C: sra         $t7, $at, 10
    ctx->r15 = S32(SIGNED(ctx->r1) >> 10);
L_80009210:
    // 0x80009210: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009214: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80009218: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8000921C: mul.s       $f16, $f2, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80009220: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80009224: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80009228: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000922C: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80009230: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80009234: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80009238: nop

    // 0x8000923C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80009240: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80009244: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80009248: nop

    // 0x8000924C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80009250: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80009254: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80009258: b           L_8000927C
    // 0x8000925C: nop

        goto L_8000927C;
    // 0x8000925C: nop

L_80009260:
    // 0x80009260: jal         0x80070AD0
    // 0x80009264: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    static_3_80070AD0(rdram, ctx);
        goto after_5;
    // 0x80009264: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_5:
    // 0x80009268: bgez        $v0, L_80009278
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000926C: sra         $v1, $v0, 10
        ctx->r3 = S32(SIGNED(ctx->r2) >> 10);
            goto L_80009278;
    }
    // 0x8000926C: sra         $v1, $v0, 10
    ctx->r3 = S32(SIGNED(ctx->r2) >> 10);
    // 0x80009270: addiu       $at, $v0, 0x3FF
    ctx->r1 = ADD32(ctx->r2, 0X3FF);
    // 0x80009274: sra         $v1, $at, 10
    ctx->r3 = S32(SIGNED(ctx->r1) >> 10);
L_80009278:
    // 0x80009278: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
L_8000927C:
    // 0x8000927C: jal         0x8009C850
    // 0x80009280: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    get_filtered_cheats(rdram, ctx);
        goto after_6;
    // 0x80009280: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_6:
    // 0x80009284: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80009288: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x8000928C: beq         $t1, $zero, L_80009298
    if (ctx->r9 == 0) {
        // 0x80009290: addiu       $t2, $zero, 0x80
        ctx->r10 = ADD32(0, 0X80);
            goto L_80009298;
    }
    // 0x80009290: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80009294: subu        $v1, $t2, $v1
    ctx->r3 = SUB32(ctx->r10, ctx->r3);
L_80009298:
    // 0x80009298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000929C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800092A0: jr          $ra
    // 0x800092A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800092A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void get_modelmatrix_vector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069C24: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80069C28: addiu       $v0, $v0, 0x12A0
    ctx->r2 = ADD32(ctx->r2, 0X12A0);
    // 0x80069C2C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80069C30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069C34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80069C38: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80069C3C: lwc1        $f4, 0x12A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X12A8);
    // 0x80069C40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069C44: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80069C48: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80069C4C: nop

    // 0x80069C50: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80069C54: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80069C58: lwc1        $f6, 0x12C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X12C0);
    // 0x80069C5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069C60: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80069C64: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80069C68: nop

    // 0x80069C6C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80069C70: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80069C74: lwc1        $f8, 0x12D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X12D8);
    // 0x80069C78: jr          $ra
    // 0x80069C7C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    return;
    // 0x80069C7C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
;}
RECOMP_FUNC void mtx_to_mtxs_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FC80: ori         $t2, $zero, 0x10
    ctx->r10 = 0 | 0X10;
    // 0x8006FC84: xor         $t3, $t3, $t3
    ctx->r11 = ctx->r11 ^ ctx->r11;
L_8006FC88:
    // 0x8006FC88: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x8006FC8C: lhu         $t1, 0x20($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X20);
    // 0x8006FC90: addi        $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8006FC94: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8006FC98: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x8006FC9C: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8006FCA0: addi        $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8006FCA4: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8006FCA8: bnel        $t3, $t2, L_8006FC88
    if (ctx->r11 != ctx->r10) {
        // 0x8006FCAC: nop
    
            goto L_8006FC88;
    }
    goto skip_0;
    // 0x8006FCAC: nop

    skip_0:
    // 0x8006FCB0: jr          $ra
    // 0x8006FCB4: nop

    return;
    // 0x8006FCB4: nop

;}
RECOMP_FUNC void obj_loop_bonus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B1B4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8003B1B8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8003B1BC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8003B1C0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8003B1C4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8003B1C8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8003B1CC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8003B1D0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8003B1D4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8003B1D8: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8003B1DC: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x8003B1E0: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8003B1E4: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x8003B1E8: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003B1EC: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8003B1F0: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x8003B1F4: lw          $s4, 0x64($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X64);
    // 0x8003B1F8: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8003B1FC: lw          $v0, 0x10($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10);
    // 0x8003B200: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x8003B204: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8003B208: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003B20C: beq         $at, $zero, L_8003B368
    if (ctx->r1 == 0) {
        // 0x8003B210: addiu       $a0, $sp, 0x84
        ctx->r4 = ADD32(ctx->r29, 0X84);
            goto L_8003B368;
    }
    // 0x8003B210: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x8003B214: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8003B218: jal         0x8001BAA8
    // 0x8003B21C: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x8003B21C: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x8003B220: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x8003B224: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003B228: blez        $t8, L_8003B368
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8003B22C: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_8003B368;
    }
    // 0x8003B22C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003B230: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003B234: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003B238: cvt.d.s     $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.d = CVT_D_S(ctx->f22.fl);
    // 0x8003B23C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003B240: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x8003B244: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003B248: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x8003B24C: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
L_8003B250:
    // 0x8003B250: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8003B254: lwc1        $f18, 0x10($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0X10);
    // 0x8003B258: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003B25C: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x8003B260: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003B264: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x8003B268: nop

    // 0x8003B26C: bc1f        L_8003B358
    if (!c1cs) {
        // 0x8003B270: lw          $t2, 0x84($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X84);
            goto L_8003B358;
    }
    // 0x8003B270: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8003B274: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x8003B278: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x8003B27C: nop

    // 0x8003B280: bc1f        L_8003B358
    if (!c1cs) {
        // 0x8003B284: lw          $t2, 0x84($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X84);
            goto L_8003B358;
    }
    // 0x8003B284: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8003B288: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003B28C: lwc1        $f8, 0xC($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0XC);
    // 0x8003B290: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003B294: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003B298: lwc1        $f16, 0x14($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X14);
    // 0x8003B29C: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003B2A0: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003B2A4: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003B2A8: nop

    // 0x8003B2AC: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003B2B0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003B2B4: jal         0x800CA030
    // 0x8003B2B8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B2B8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_1:
    // 0x8003B2BC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8003B2C0: nop

    // 0x8003B2C4: bc1f        L_8003B358
    if (!c1cs) {
        // 0x8003B2C8: lw          $t2, 0x84($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X84);
            goto L_8003B358;
    }
    // 0x8003B2C8: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8003B2CC: lwc1        $f10, 0x0($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8003B2D0: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003B2D4: lwc1        $f4, 0x8($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8003B2D8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003B2DC: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003B2E0: lwc1        $f16, 0xC($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8003B2E4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003B2E8: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8003B2EC: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003B2F0: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8003B2F4: nop

    // 0x8003B2F8: bc1f        L_8003B358
    if (!c1cs) {
        // 0x8003B2FC: lw          $t2, 0x84($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X84);
            goto L_8003B358;
    }
    // 0x8003B2FC: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8003B300: lb          $t9, 0x185($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X185);
    // 0x8003B304: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8003B308: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x8003B30C: beq         $at, $zero, L_8003B354
    if (ctx->r1 == 0) {
        // 0x8003B310: addiu       $t0, $zero, 0x4
        ctx->r8 = ADD32(0, 0X4);
            goto L_8003B354;
    }
    // 0x8003B310: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8003B314: sb          $s6, 0x185($s1)
    MEM_B(0X185, ctx->r17) = ctx->r22;
    // 0x8003B318: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003B31C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003B320: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003B324: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003B328: jal         0x80009558
    // 0x8003B32C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_2;
    // 0x8003B32C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_2:
    // 0x8003B330: lb          $a0, 0x3($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X3);
    // 0x8003B334: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003B338: addiu       $a0, $a0, 0x7B
    ctx->r4 = ADD32(ctx->r4, 0X7B);
    // 0x8003B33C: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x8003B340: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003B344: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003B348: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8003B34C: jal         0x80001EA8
    // 0x8003B350: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    sound_play_spatial(rdram, ctx);
        goto after_3;
    // 0x8003B350: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_3:
L_8003B354:
    // 0x8003B354: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
L_8003B358:
    // 0x8003B358: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003B35C: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003B360: bne         $at, $zero, L_8003B250
    if (ctx->r1 != 0) {
        // 0x8003B364: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_8003B250;
    }
    // 0x8003B364: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_8003B368:
    // 0x8003B368: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8003B36C: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8003B370: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003B374: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8003B378: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003B37C: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8003B380: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8003B384: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8003B388: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8003B38C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8003B390: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8003B394: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8003B398: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8003B39C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8003B3A0: jr          $ra
    // 0x8003B3A4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8003B3A4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void obj_loop_fireball_octoweapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033FA0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80033FA4: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80033FA8: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80033FAC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80033FB0: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80033FB4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80033FB8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80033FBC: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80033FC0: lw          $v1, 0x78($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X78);
    // 0x80033FC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80033FC8: bne         $t7, $zero, L_80033FEC
    if (ctx->r15 != 0) {
        // 0x80033FCC: swc1        $f0, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
            goto L_80033FEC;
    }
    // 0x80033FCC: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x80033FD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80033FD4: lwc1        $f9, 0x6570($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6570);
    // 0x80033FD8: lwc1        $f8, 0x6574($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6574);
    // 0x80033FDC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80033FE0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80033FE4: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80033FE8: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
L_80033FEC:
    // 0x80033FEC: lh          $t8, 0x48($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X48);
    // 0x80033FF0: addiu       $at, $zero, 0x74
    ctx->r1 = ADD32(0, 0X74);
    // 0x80033FF4: bne         $t8, $at, L_8003404C
    if (ctx->r24 != ctx->r1) {
        // 0x80033FF8: nop
    
            goto L_8003404C;
    }
    // 0x80033FF8: nop

    // 0x80033FFC: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x80034000: nop

    // 0x80034004: bgez        $t9, L_8003404C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80034008: nop
    
            goto L_8003404C;
    }
    // 0x80034008: nop

    // 0x8003400C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80034010: nop

    // 0x80034014: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80034018: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8003401C: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80034020: jal         0x80011560
    // 0x80034024: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    ignore_bounds_check(rdram, ctx);
        goto after_0;
    // 0x80034024: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    after_0:
    // 0x80034028: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x8003402C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80034030: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x80034034: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x80034038: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    // 0x8003403C: jal         0x80011570
    // 0x80034040: nop

    move_object(rdram, ctx);
        goto after_1;
    // 0x80034040: nop

    after_1:
    // 0x80034044: b           L_800342F8
    // 0x80034048: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
        goto L_800342F8;
    // 0x80034048: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
L_8003404C:
    // 0x8003404C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80034050: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034054: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80034058: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003405C: lwc1        $f19, 0x6578($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6578);
    // 0x80034060: lwc1        $f18, 0x657C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X657C);
    // 0x80034064: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80034068: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x8003406C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80034070: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80034074: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80034078: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8003407C: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x80034080: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80034084: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80034088: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8003408C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80034090: bc1f        L_800340A4
    if (!c1cs) {
        // 0x80034094: cvt.d.s     $f16, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
            goto L_800340A4;
    }
    // 0x80034094: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80034098: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003409C: nop

    // 0x800340A0: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_800340A4:
    // 0x800340A4: lui         $at, 0xC024
    ctx->r1 = S32(0XC024 << 16);
    // 0x800340A8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800340AC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800340B0: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x800340B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800340B8: bc1f        L_800340C8
    if (!c1cs) {
        // 0x800340BC: nop
    
            goto L_800340C8;
    }
    // 0x800340BC: nop

    // 0x800340C0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800340C4: nop

L_800340C8:
    // 0x800340C8: lwc1        $f14, 0x1C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800340CC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800340D0: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x800340D4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800340D8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800340DC: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800340E0: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x800340E4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800340E8: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800340EC: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x800340F0: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800340F4: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x800340F8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800340FC: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x80034100: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80034104: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80034108: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8003410C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80034110: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80034114: mul.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80034118: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003411C: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x80034120: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80034124: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x80034128: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003412C: bc1f        L_80034140
    if (!c1cs) {
        // 0x80034130: nop
    
            goto L_80034140;
    }
    // 0x80034130: nop

    // 0x80034134: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80034138: nop

    // 0x8003413C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_80034140:
    // 0x80034140: lui         $at, 0xC024
    ctx->r1 = S32(0XC024 << 16);
    // 0x80034144: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80034148: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8003414C: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x80034150: nop

    // 0x80034154: bc1f        L_80034164
    if (!c1cs) {
        // 0x80034158: nop
    
            goto L_80034164;
    }
    // 0x80034158: nop

    // 0x8003415C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80034160: nop

L_80034164:
    // 0x80034164: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80034168: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8003416C: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80034170: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80034174: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80034178: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x8003417C: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x80034180: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80034184: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80034188: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x8003418C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80034190: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80034194: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80034198: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x8003419C: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800341A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800341A4: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800341A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800341AC: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800341B0: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800341B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800341B8: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x800341BC: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x800341C0: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x800341C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800341C8: bc1f        L_800341DC
    if (!c1cs) {
        // 0x800341CC: nop
    
            goto L_800341DC;
    }
    // 0x800341CC: nop

    // 0x800341D0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800341D4: nop

    // 0x800341D8: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_800341DC:
    // 0x800341DC: lui         $at, 0xC024
    ctx->r1 = S32(0XC024 << 16);
    // 0x800341E0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800341E4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800341E8: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x800341EC: nop

    // 0x800341F0: bc1f        L_80034200
    if (!c1cs) {
        // 0x800341F4: nop
    
            goto L_80034200;
    }
    // 0x800341F4: nop

    // 0x800341F8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800341FC: nop

L_80034200:
    // 0x80034200: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80034204: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80034208: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8003420C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80034210: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80034214: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80034218: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8003421C: lwc1        $f14, 0x1C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80034220: mul.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80034224: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x80034228: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8003422C: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80034230: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x80034234: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80034238: nop

    // 0x8003423C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80034240: jal         0x800CA030
    // 0x80034244: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80034244: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80034248: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003424C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80034250: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80034254: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80034258: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8003425C: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80034260: bc1f        L_80034294
    if (!c1cs) {
        // 0x80034264: nop
    
            goto L_80034294;
    }
    // 0x80034264: nop

    // 0x80034268: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003426C: lwc1        $f14, 0x24($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80034270: jal         0x80070990
    // 0x80034274: nop

    arctan2_f(rdram, ctx);
        goto after_3;
    // 0x80034274: nop

    after_3:
    // 0x80034278: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8003427C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80034280: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x80034284: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x80034288: sll         $t2, $t1, 9
    ctx->r10 = S32(ctx->r9 << 9);
    // 0x8003428C: subu        $t3, $t0, $t2
    ctx->r11 = SUB32(ctx->r8, ctx->r10);
    // 0x80034290: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
L_80034294:
    // 0x80034294: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80034298: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003429C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800342A0: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800342A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800342A8: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800342AC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800342B0: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800342B4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800342B8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800342BC: jal         0x80011570
    // 0x800342C0: nop

    move_object(rdram, ctx);
        goto after_4;
    // 0x800342C0: nop

    after_4:
    // 0x800342C4: lh          $t4, 0x4A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4A);
    // 0x800342C8: addiu       $at, $zero, 0x12A
    ctx->r1 = ADD32(0, 0X12A);
    // 0x800342CC: bne         $t4, $at, L_800342F4
    if (ctx->r12 != ctx->r1) {
        // 0x800342D0: addiu       $a1, $sp, 0x4C
        ctx->r5 = ADD32(ctx->r29, 0X4C);
            goto L_800342F4;
    }
    // 0x800342D0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800342D4: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800342D8: jal         0x8002AD48
    // 0x800342DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    get_wave_properties(rdram, ctx);
        goto after_5;
    // 0x800342DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x800342E0: beq         $v0, $zero, L_800342F8
    if (ctx->r2 == 0) {
        // 0x800342E4: lw          $t6, 0x8C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X8C);
            goto L_800342F8;
    }
    // 0x800342E4: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x800342E8: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800342EC: nop

    // 0x800342F0: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_800342F4:
    // 0x800342F4: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
L_800342F8:
    // 0x800342F8: lh          $t5, 0x18($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X18);
    // 0x800342FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80034300: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80034304: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80034308: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x8003430C: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80034310: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
    // 0x80034314: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x80034318: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003431C: nop

    // 0x80034320: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80034324: nop

    // 0x80034328: beq         $a0, $zero, L_800343F4
    if (ctx->r4 == 0) {
        // 0x8003432C: nop
    
            goto L_800343F4;
    }
    // 0x8003432C: nop

    // 0x80034330: lbu         $t1, 0x13($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X13);
    // 0x80034334: nop

    // 0x80034338: slti        $at, $t1, 0x3C
    ctx->r1 = SIGNED(ctx->r9) < 0X3C ? 1 : 0;
    // 0x8003433C: beq         $at, $zero, L_800343F4
    if (ctx->r1 == 0) {
        // 0x80034340: nop
    
            goto L_800343F4;
    }
    // 0x80034340: nop

    // 0x80034344: lw          $t0, 0x40($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X40);
    // 0x80034348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003434C: lb          $t2, 0x54($t0)
    ctx->r10 = MEM_B(ctx->r8, 0X54);
    // 0x80034350: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80034354: bne         $a1, $t2, L_800343F4
    if (ctx->r5 != ctx->r10) {
        // 0x80034358: nop
    
            goto L_800343F4;
    }
    // 0x80034358: nop

    // 0x8003435C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80034360: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80034364: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80034368: nop

    // 0x8003436C: beq         $t3, $at, L_800343F4
    if (ctx->r11 == ctx->r1) {
        // 0x80034370: nop
    
            goto L_800343F4;
    }
    // 0x80034370: nop

    // 0x80034374: lh          $t4, 0x48($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X48);
    // 0x80034378: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x8003437C: bne         $t4, $at, L_800343C8
    if (ctx->r12 != ctx->r1) {
        // 0x80034380: addiu       $t6, $zero, 0x14
        ctx->r14 = ADD32(0, 0X14);
            goto L_800343C8;
    }
    // 0x80034380: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80034384: sb          $a1, 0x187($v0)
    MEM_B(0X187, ctx->r2) = ctx->r5;
    // 0x80034388: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003438C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034390: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034394: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80034398: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003439C: sw          $t6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r14;
    // 0x800343A0: addiu       $t5, $zero, 0x11
    ctx->r13 = ADD32(0, 0X11);
    // 0x800343A4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800343A8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x800343AC: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x800343B0: jal         0x8003FC84
    // 0x800343B4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_6;
    // 0x800343B4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x800343B8: jal         0x8000FFB8
    // 0x800343BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_7;
    // 0x800343BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800343C0: b           L_800343F8
    // 0x800343C4: lh          $t1, 0x48($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X48);
        goto L_800343F8;
    // 0x800343C4: lh          $t1, 0x48($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X48);
L_800343C8:
    // 0x800343C8: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    // 0x800343CC: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x800343D0: blez        $t7, L_800343F4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800343D4: addiu       $t9, $zero, -0x3C
        ctx->r25 = ADD32(0, -0X3C);
            goto L_800343F4;
    }
    // 0x800343D4: addiu       $t9, $zero, -0x3C
    ctx->r25 = ADD32(0, -0X3C);
    // 0x800343D8: sh          $t8, 0x204($v0)
    MEM_H(0X204, ctx->r2) = ctx->r24;
    // 0x800343DC: sw          $t9, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r25;
    // 0x800343E0: sw          $v1, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r3;
    // 0x800343E4: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x800343E8: addiu       $a0, $zero, 0x24A
    ctx->r4 = ADD32(0, 0X24A);
    // 0x800343EC: jal         0x80001D04
    // 0x800343F0: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800343F0: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_8:
L_800343F4:
    // 0x800343F4: lh          $t1, 0x48($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X48);
L_800343F8:
    // 0x800343F8: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800343FC: bne         $t1, $at, L_800344C8
    if (ctx->r9 != ctx->r1) {
        // 0x80034400: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800344C8;
    }
    // 0x80034400: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80034404: sw          $t0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r8;
    // 0x80034408: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8003440C: jal         0x800B019C
    // 0x80034410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_9;
    // 0x80034410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80034414: lw          $t2, 0x7C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X7C);
    // 0x80034418: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x8003441C: nop

    // 0x80034420: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80034424: bgez        $t4, L_80034560
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80034428: sw          $t4, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r12;
            goto L_80034560;
    }
    // 0x80034428: sw          $t4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r12;
    // 0x8003442C: lh          $t5, 0x4A($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4A);
    // 0x80034430: addiu       $at, $zero, 0x12A
    ctx->r1 = ADD32(0, 0X12A);
    // 0x80034434: bne         $t5, $at, L_80034474
    if (ctx->r13 != ctx->r1) {
        // 0x80034438: nop
    
            goto L_80034474;
    }
    // 0x80034438: nop

    // 0x8003443C: jal         0x8000FFB8
    // 0x80034440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_10;
    // 0x80034440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80034444: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034448: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003444C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80034450: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80034454: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80034458: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x8003445C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80034460: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80034464: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80034468: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003446C: jal         0x8003FC84
    // 0x80034470: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_11;
    // 0x80034470: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_11:
L_80034474:
    // 0x80034474: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80034478: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003447C: lwc1        $f7, 0x6580($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6580);
    // 0x80034480: lwc1        $f6, 0x6584($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6584);
    // 0x80034484: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80034488: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8003448C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80034490: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80034494: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80034498: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8003449C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800344A0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800344A4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800344A8: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x800344AC: nop

    // 0x800344B0: bc1f        L_80034564
    if (!c1cs) {
        // 0x800344B4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80034564;
    }
    // 0x800344B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800344B8: jal         0x8000FFB8
    // 0x800344BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_12;
    // 0x800344BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800344C0: b           L_80034564
    // 0x800344C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80034564;
    // 0x800344C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800344C8:
    // 0x800344C8: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x800344CC: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x800344D0: bgez        $v0, L_800344FC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800344D4: subu        $t2, $v0, $t0
        ctx->r10 = SUB32(ctx->r2, ctx->r8);
            goto L_800344FC;
    }
    // 0x800344D4: subu        $t2, $v0, $t0
    ctx->r10 = SUB32(ctx->r2, ctx->r8);
    // 0x800344D8: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x800344DC: nop

    // 0x800344E0: addu        $t1, $v0, $t9
    ctx->r9 = ADD32(ctx->r2, ctx->r25);
    // 0x800344E4: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
    // 0x800344E8: bltz        $t1, L_80034510
    if (SIGNED(ctx->r9) < 0) {
        // 0x800344EC: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80034510;
    }
    // 0x800344EC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800344F0: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x800344F4: b           L_80034510
    // 0x800344F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80034510;
    // 0x800344F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800344FC:
    // 0x800344FC: sw          $t2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r10;
    // 0x80034500: bgtz        $t2, L_80034510
    if (SIGNED(ctx->r10) > 0) {
        // 0x80034504: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_80034510;
    }
    // 0x80034504: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80034508: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x8003450C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80034510:
    // 0x80034510: bne         $v0, $zero, L_80034564
    if (ctx->r2 != 0) {
        // 0x80034514: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80034564;
    }
    // 0x80034514: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80034518: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8003451C: nop

    // 0x80034520: lw          $a0, 0x1C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X1C);
    // 0x80034524: nop

    // 0x80034528: beq         $a0, $zero, L_80034538
    if (ctx->r4 == 0) {
        // 0x8003452C: nop
    
            goto L_80034538;
    }
    // 0x8003452C: nop

    // 0x80034530: jal         0x8000488C
    // 0x80034534: nop

    sndp_stop(rdram, ctx);
        goto after_13;
    // 0x80034534: nop

    after_13:
L_80034538:
    // 0x80034538: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003453C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80034540: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80034544: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80034548: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8003454C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80034550: jal         0x80009558
    // 0x80034554: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_14;
    // 0x80034554: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    after_14:
    // 0x80034558: jal         0x8000FFB8
    // 0x8003455C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_15;
    // 0x8003455C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_80034560:
    // 0x80034560: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80034564:
    // 0x80034564: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80034568: jr          $ra
    // 0x8003456C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8003456C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void mark_read_all_save_files(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EDE8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EDEC: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EDF0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EDF4: nop

    // 0x8006EDF8: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x8006EDFC: jr          $ra
    // 0x8006EE00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EE00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void obj_init_parkwarden(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800392F8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800392FC: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80039300: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80039304: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80039308: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003930C: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80039310: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x80039314: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x80039318: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003931C: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x80039320: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80039324: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80039328: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8003932C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80039330: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80039334: sb          $t2, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r10;
    // 0x80039338: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8003933C: sh          $zero, 0x28($v0)
    MEM_H(0X28, ctx->r2) = 0;
    // 0x80039340: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80039344: sh          $zero, 0x34($v0)
    MEM_H(0X34, ctx->r2) = 0;
    // 0x80039348: sb          $zero, 0x36($v0)
    MEM_B(0X36, ctx->r2) = 0;
    // 0x8003934C: sw          $zero, -0x25AC($at)
    MEM_W(-0X25AC, ctx->r1) = 0;
    // 0x80039350: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80039354: addiu       $t3, $zero, 0x10F
    ctx->r11 = ADD32(0, 0X10F);
    // 0x80039358: jr          $ra
    // 0x8003935C: sh          $t3, -0x259E($at)
    MEM_H(-0X259E, ctx->r1) = ctx->r11;
    return;
    // 0x8003935C: sh          $t3, -0x259E($at)
    MEM_H(-0X259E, ctx->r1) = ctx->r11;
;}
RECOMP_FUNC void align8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071AAC: andi        $v1, $a0, 0x7
    ctx->r3 = ctx->r4 & 0X7;
    // 0x80071AB0: blez        $v1, L_80071AC0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80071AB4: nop
    
            goto L_80071AC0;
    }
    // 0x80071AB4: nop

    // 0x80071AB8: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80071ABC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80071AC0:
    // 0x80071AC0: jr          $ra
    // 0x80071AC4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80071AC4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void get_trophy_race_world_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099B68: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80099B6C: lw          $v0, 0x1568($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1568);
    // 0x80099B70: jr          $ra
    // 0x80099B74: nop

    return;
    // 0x80099B74: nop

;}
RECOMP_FUNC void sndp_play_with_priority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004668: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8000466C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80004670: sll         $s1, $a1, 16
    ctx->r17 = S32(ctx->r5 << 16);
    // 0x80004674: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80004678: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000467C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80004680: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80004684: andi        $fp, $a2, 0xFF
    ctx->r30 = ctx->r6 & 0XFF;
    // 0x80004688: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8000468C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80004690: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80004694: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80004698: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000469C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800046A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800046A4: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800046A8: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800046AC: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x800046B0: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800046B4: sh          $zero, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = 0;
    // 0x800046B8: bne         $t6, $zero, L_800046C8
    if (ctx->r14 != 0) {
        // 0x800046BC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800046C8;
    }
    // 0x800046BC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800046C0: b           L_8000485C
    // 0x800046C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000485C;
    // 0x800046C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800046C8:
    // 0x800046C8: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800046CC: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x800046D0: addiu       $s5, $s5, -0x33D4
    ctx->r21 = ADD32(ctx->r21, -0X33D4);
    // 0x800046D4: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x800046D8: addiu       $s6, $sp, 0x50
    ctx->r22 = ADD32(ctx->r29, 0X50);
    // 0x800046DC: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
L_800046E0:
    // 0x800046E0: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x800046E4: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x800046E8: nop

    // 0x800046EC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800046F0: lw          $s2, 0xC($t9)
    ctx->r18 = MEM_W(ctx->r25, 0XC);
    // 0x800046F4: jal         0x80004384
    // 0x800046F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    sndp_allocate(rdram, ctx);
        goto after_0;
    // 0x800046F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800046FC: beq         $v0, $zero, L_800047B0
    if (ctx->r2 == 0) {
        // 0x80004700: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800047B0;
    }
    // 0x80004700: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80004704: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x80004708: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000470C: sw          $v0, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r2;
    // 0x80004710: sh          $t1, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r9;
    // 0x80004714: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80004718: lw          $t2, 0x4($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X4);
    // 0x8000471C: addiu       $a2, $s4, 0x1
    ctx->r6 = ADD32(ctx->r20, 0X1);
    // 0x80004720: lbu         $s3, 0x1($t2)
    ctx->r19 = MEM_BU(ctx->r10, 0X1);
    // 0x80004724: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80004728: sll         $t3, $s3, 6
    ctx->r11 = S32(ctx->r19 << 6);
    // 0x8000472C: addu        $t3, $t3, $s3
    ctx->r11 = ADD32(ctx->r11, ctx->r19);
    // 0x80004730: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80004734: addu        $t3, $t3, $s3
    ctx->r11 = ADD32(ctx->r11, ctx->r19);
    // 0x80004738: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8000473C: subu        $t3, $t3, $s3
    ctx->r11 = SUB32(ctx->r11, ctx->r19);
    // 0x80004740: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80004744: addu        $t3, $t3, $s3
    ctx->r11 = ADD32(ctx->r11, ctx->r19);
    // 0x80004748: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8000474C: addu        $t3, $t3, $s3
    ctx->r11 = ADD32(ctx->r11, ctx->r19);
    // 0x80004750: beq         $fp, $zero, L_8000475C
    if (ctx->r30 == 0) {
        // 0x80004754: or          $s3, $t3, $zero
        ctx->r19 = ctx->r11 | 0;
            goto L_8000475C;
    }
    // 0x80004754: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
    // 0x80004758: sb          $fp, 0x36($v0)
    MEM_B(0X36, ctx->r2) = ctx->r30;
L_8000475C:
    // 0x8000475C: lbu         $t4, 0x3E($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X3E);
    // 0x80004760: nop

    // 0x80004764: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80004768: beq         $t5, $zero, L_8000479C
    if (ctx->r13 == 0) {
        // 0x8000476C: nop
    
            goto L_8000479C;
    }
    // 0x8000476C: nop

    // 0x80004770: lbu         $t6, 0x3E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X3E);
    // 0x80004774: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80004778: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x8000477C: sb          $t7, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r15;
    // 0x80004780: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x80004784: jal         0x800C970C
    // 0x80004788: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x80004788: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
    // 0x8000478C: addiu       $t8, $s3, 0x1
    ctx->r24 = ADD32(ctx->r19, 0X1);
    // 0x80004790: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x80004794: b           L_800047AC
    // 0x80004798: sh          $s1, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r17;
        goto L_800047AC;
    // 0x80004798: sh          $s1, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r17;
L_8000479C:
    // 0x8000479C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x800047A0: addiu       $a2, $s3, 0x1
    ctx->r6 = ADD32(ctx->r19, 0X1);
    // 0x800047A4: jal         0x800C970C
    // 0x800047A8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_2;
    // 0x800047A8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_2:
L_800047AC:
    // 0x800047AC: or          $s7, $s0, $zero
    ctx->r23 = ctx->r16 | 0;
L_800047B0:
    // 0x800047B0: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x800047B4: addu        $s4, $s4, $s3
    ctx->r20 = ADD32(ctx->r20, ctx->r19);
    // 0x800047B8: lbu         $t0, 0x2($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2);
    // 0x800047BC: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800047C0: andi        $t1, $t0, 0xC0
    ctx->r9 = ctx->r8 & 0XC0;
    // 0x800047C4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800047C8: addu        $s1, $t9, $t2
    ctx->r17 = ADD32(ctx->r25, ctx->r10);
    // 0x800047CC: sll         $t3, $s1, 16
    ctx->r11 = S32(ctx->r17 << 16);
    // 0x800047D0: sra         $s1, $t3, 16
    ctx->r17 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800047D4: beq         $s1, $zero, L_800047E8
    if (ctx->r17 == 0) {
        // 0x800047D8: nop
    
            goto L_800047E8;
    }
    // 0x800047D8: nop

    // 0x800047DC: bne         $s0, $zero, L_800046E0
    if (ctx->r16 != 0) {
        // 0x800047E0: lw          $a0, 0x80($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X80);
            goto L_800046E0;
    }
    // 0x800047E0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x800047E4: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
L_800047E8:
    // 0x800047E8: beq         $s7, $zero, L_8000484C
    if (ctx->r23 == 0) {
        // 0x800047EC: lw          $t4, 0x8C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X8C);
            goto L_8000484C;
    }
    // 0x800047EC: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x800047F0: lbu         $t5, 0x3E($s7)
    ctx->r13 = MEM_BU(ctx->r23, 0X3E);
    // 0x800047F4: addiu       $t9, $zero, 0x200
    ctx->r25 = ADD32(0, 0X200);
    // 0x800047F8: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x800047FC: sb          $t6, 0x3E($s7)
    MEM_B(0X3E, ctx->r23) = ctx->r14;
    // 0x80004800: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x80004804: ori         $t1, $t6, 0x10
    ctx->r9 = ctx->r14 | 0X10;
    // 0x80004808: sw          $t7, 0x30($s7)
    MEM_W(0X30, ctx->r23) = ctx->r15;
    // 0x8000480C: lh          $t8, 0x6E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6E);
    // 0x80004810: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80004814: beq         $t8, $zero, L_8000484C
    if (ctx->r24 == 0) {
        // 0x80004818: lw          $t4, 0x8C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X8C);
            goto L_8000484C;
    }
    // 0x80004818: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x8000481C: sb          $t1, 0x3E($s7)
    MEM_B(0X3E, ctx->r23) = ctx->r9;
    // 0x80004820: lh          $t2, 0x6E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X6E);
    // 0x80004824: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x80004828: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8000482C: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x80004830: sh          $t9, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r25;
    // 0x80004834: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80004838: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x8000483C: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x80004840: jal         0x800C970C
    // 0x80004844: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_3;
    // 0x80004844: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_3:
    // 0x80004848: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
L_8000484C:
    // 0x8000484C: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x80004850: beq         $t4, $zero, L_8000485C
    if (ctx->r12 == 0) {
        // 0x80004854: nop
    
            goto L_8000485C;
    }
    // 0x80004854: nop

    // 0x80004858: sw          $s7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r23;
L_8000485C:
    // 0x8000485C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80004860: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004864: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80004868: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000486C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80004870: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80004874: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80004878: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000487C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80004880: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80004884: jr          $ra
    // 0x80004888: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80004888: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void aspMainTextStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void gameselect_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CF84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CF88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CF8C: jal         0x800C478C
    // 0x8008CF90: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x8008CF90: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008CF94: jal         0x800803D8
    // 0x8008CF98: nop

    menu_button_free(rdram, ctx);
        goto after_1;
    // 0x8008CF98: nop

    after_1:
    // 0x8008CF9C: jal         0x8009CA4C
    // 0x8008CFA0: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    menu_asset_free(rdram, ctx);
        goto after_2;
    // 0x8008CFA0: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_2:
    // 0x8008CFA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CFA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CFAC: jr          $ra
    // 0x8008CFB0: nop

    return;
    // 0x8008CFB0: nop

;}
RECOMP_FUNC void racer_sound_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004B40: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80004B44: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80004B48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004B4C: slti        $at, $a0, 0xB
    ctx->r1 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
    // 0x80004B50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80004B54: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80004B58: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80004B5C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80004B60: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80004B64: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80004B68: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80004B6C: bne         $at, $zero, L_80004B78
    if (ctx->r1 != 0) {
        // 0x80004B70: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_80004B78;
    }
    // 0x80004B70: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80004B74: addiu       $s0, $zero, 0xB
    ctx->r16 = ADD32(0, 0XB);
L_80004B78:
    // 0x80004B78: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80004B7C: lw          $t6, -0x33B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X33B8);
    // 0x80004B80: nop

    // 0x80004B84: beq         $t6, $zero, L_80004BAC
    if (ctx->r14 == 0) {
        // 0x80004B88: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80004BAC;
    }
    // 0x80004B88: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80004B8C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80004B90: addiu       $v1, $v1, -0x5E48
    ctx->r3 = ADD32(ctx->r3, -0X5E48);
    // 0x80004B94: addiu       $v0, $v0, -0x5E50
    ctx->r2 = ADD32(ctx->r2, -0X5E50);
L_80004B98:
    // 0x80004B98: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80004B9C: bne         $v0, $v1, L_80004B98
    if (ctx->r2 != ctx->r3) {
        // 0x80004BA0: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_80004B98;
    }
    // 0x80004BA0: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80004BA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80004BA8: sw          $zero, -0x33B8($at)
    MEM_W(-0X33B8, ctx->r1) = 0;
L_80004BAC:
    // 0x80004BAC: jal         0x80076EE4
    // 0x80004BB0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x80004BB0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_0:
    // 0x80004BB4: sll         $s6, $s3, 2
    ctx->r22 = S32(ctx->r19 << 2);
    // 0x80004BB8: addu        $s6, $s6, $s3
    ctx->r22 = ADD32(ctx->r22, ctx->r19);
    // 0x80004BBC: sll         $s6, $s6, 1
    ctx->r22 = S32(ctx->r22 << 1);
    // 0x80004BC0: addu        $t8, $s6, $s0
    ctx->r24 = ADD32(ctx->r22, ctx->r16);
    // 0x80004BC4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80004BC8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80004BCC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80004BD0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80004BD4: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x80004BD8: lui         $s2, 0xFF
    ctx->r18 = S32(0XFF << 16);
    // 0x80004BDC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80004BE0: ori         $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 | 0XFFFF;
    // 0x80004BE4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80004BE8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80004BEC: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x80004BF0: jal         0x80070EDC
    // 0x80004BF4: addu        $s1, $t7, $t9
    ctx->r17 = ADD32(ctx->r15, ctx->r25);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80004BF4: addu        $s1, $t7, $t9
    ctx->r17 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x80004BF8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80004BFC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80004C00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80004C04: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80004C08: jal         0x80077190
    // 0x80004C0C: addiu       $a3, $zero, 0x4C
    ctx->r7 = ADD32(0, 0X4C);
    asset_load(rdram, ctx);
        goto after_2;
    // 0x80004C0C: addiu       $a3, $zero, 0x4C
    ctx->r7 = ADD32(0, 0X4C);
    after_2:
    // 0x80004C10: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    // 0x80004C14: jal         0x80070EDC
    // 0x80004C18: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80004C18: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80004C1C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80004C20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80004C24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80004C28: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
L_80004C2C:
    // 0x80004C2C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80004C30: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80004C34: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80004C38: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80004C3C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80004C40: bne         $a3, $a0, L_80004C2C
    if (ctx->r7 != ctx->r4) {
        // 0x80004C44: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_80004C2C;
    }
    // 0x80004C44: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x80004C48: lbu         $t6, 0x36($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X36);
    // 0x80004C4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80004C50: lwc1        $f2, 0x5180($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5180);
    // 0x80004C54: sb          $t6, 0x36($v0)
    MEM_B(0X36, ctx->r2) = ctx->r14;
    // 0x80004C58: lbu         $t8, 0x37($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X37);
    // 0x80004C5C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80004C60: sb          $t8, 0x37($v0)
    MEM_B(0X37, ctx->r2) = ctx->r24;
    // 0x80004C64: lbu         $t7, 0x38($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X38);
    // 0x80004C68: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x80004C6C: sb          $t7, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r15;
    // 0x80004C70: lbu         $t9, 0x39($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X39);
    // 0x80004C74: or          $t3, $s5, $zero
    ctx->r11 = ctx->r21 | 0;
    // 0x80004C78: sb          $t9, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r25;
    // 0x80004C7C: lbu         $t6, 0x3A($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X3A);
    // 0x80004C80: or          $t4, $s5, $zero
    ctx->r12 = ctx->r21 | 0;
    // 0x80004C84: sb          $t6, 0x64($v0)
    MEM_B(0X64, ctx->r2) = ctx->r14;
    // 0x80004C88: lh          $t8, 0x46($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X46);
    // 0x80004C8C: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x80004C90: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80004C94: or          $ra, $v0, $zero
    ctx->r31 = ctx->r2 | 0;
    // 0x80004C98: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004C9C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80004CA0: or          $t2, $s5, $zero
    ctx->r10 = ctx->r21 | 0;
    // 0x80004CA4: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004CA8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80004CAC: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x80004CB0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80004CB4: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80004CB8: swc1        $f8, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f8.u32l;
    // 0x80004CBC: lh          $t7, 0x3E($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X3E);
    // 0x80004CC0: nop

    // 0x80004CC4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80004CC8: nop

    // 0x80004CCC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80004CD0: nop

    // 0x80004CD4: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80004CD8: swc1        $f18, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = ctx->f18.u32l;
    // 0x80004CDC: lh          $t9, 0x40($s5)
    ctx->r25 = MEM_H(ctx->r21, 0X40);
    // 0x80004CE0: nop

    // 0x80004CE4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80004CE8: nop

    // 0x80004CEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004CF0: nop

    // 0x80004CF4: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004CF8: swc1        $f8, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->f8.u32l;
    // 0x80004CFC: lh          $t6, 0x42($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X42);
    // 0x80004D00: nop

    // 0x80004D04: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80004D08: nop

    // 0x80004D0C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80004D10: nop

    // 0x80004D14: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80004D18: swc1        $f18, 0xC0($v0)
    MEM_W(0XC0, ctx->r2) = ctx->f18.u32l;
    // 0x80004D1C: lh          $t8, 0x44($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X44);
    // 0x80004D20: nop

    // 0x80004D24: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80004D28: nop

    // 0x80004D2C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004D30: nop

    // 0x80004D34: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004D38: swc1        $f8, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f8.u32l;
    // 0x80004D3C: lh          $t7, 0x3C($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X3C);
    // 0x80004D40: nop

    // 0x80004D44: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80004D48: nop

    // 0x80004D4C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80004D50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80004D54: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80004D58: swc1        $f18, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->f18.u32l;
    // 0x80004D5C: lbu         $t9, 0x3B($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X3B);
    // 0x80004D60: nop

    // 0x80004D64: sb          $t9, 0xB8($v0)
    MEM_B(0XB8, ctx->r2) = ctx->r25;
    // 0x80004D68: lh          $t6, 0x48($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X48);
    // 0x80004D6C: sb          $zero, 0xD8($v0)
    MEM_B(0XD8, ctx->r2) = 0;
    // 0x80004D70: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80004D74: nop

    // 0x80004D78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004D7C: nop

    // 0x80004D80: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004D84: swc1        $f8, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->f8.u32l;
L_80004D88:
    // 0x80004D88: lhu         $t8, 0x0($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X0);
    // 0x80004D8C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80004D90: sh          $t8, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r24;
    // 0x80004D94: lbu         $t7, 0x4($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X4);
    // 0x80004D98: addiu       $v1, $t3, 0x1
    ctx->r3 = ADD32(ctx->r11, 0X1);
    // 0x80004D9C: sb          $t7, 0x4($t1)
    MEM_B(0X4, ctx->r9) = ctx->r15;
    // 0x80004DA0: lhu         $t9, 0x18($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X18);
    // 0x80004DA4: addiu       $a1, $t4, 0x2
    ctx->r5 = ADD32(ctx->r12, 0X2);
    // 0x80004DA8: sh          $t9, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r25;
    // 0x80004DAC: lbu         $t6, 0xE($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0XE);
    // 0x80004DB0: addiu       $a0, $t5, 0x1
    ctx->r4 = ADD32(ctx->r13, 0X1);
    // 0x80004DB4: sb          $t6, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r14;
    // 0x80004DB8: lbu         $t8, 0x2C($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X2C);
    // 0x80004DBC: addiu       $a2, $ra, 0x2
    ctx->r6 = ADD32(ctx->r31, 0X2);
    // 0x80004DC0: sb          $t8, 0x2C($t1)
    MEM_B(0X2C, ctx->r9) = ctx->r24;
L_80004DC4:
    // 0x80004DC4: lbu         $t7, 0x4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4);
    // 0x80004DC8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80004DCC: sb          $t7, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r15;
    // 0x80004DD0: lhu         $t9, 0x18($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X18);
    // 0x80004DD4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80004DD8: sh          $t9, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r25;
    // 0x80004DDC: lbu         $t6, 0xC($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XC);
    // 0x80004DE0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80004DE4: sb          $t6, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r14;
    // 0x80004DE8: lbu         $t8, 0x2A($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2A);
    // 0x80004DEC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80004DF0: sb          $t8, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r24;
    // 0x80004DF4: lbu         $t7, 0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3);
    // 0x80004DF8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80004DFC: sb          $t7, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r15;
    // 0x80004E00: lhu         $t9, 0x16($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X16);
    // 0x80004E04: nop

    // 0x80004E08: sh          $t9, 0x16($a2)
    MEM_H(0X16, ctx->r6) = ctx->r25;
    // 0x80004E0C: lbu         $t6, 0xD($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XD);
    // 0x80004E10: nop

    // 0x80004E14: sb          $t6, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r14;
    // 0x80004E18: lbu         $t8, 0x2B($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2B);
    // 0x80004E1C: bne         $a3, $t0, L_80004DC4
    if (ctx->r7 != ctx->r8) {
        // 0x80004E20: sb          $t8, 0x2B($a0)
        MEM_B(0X2B, ctx->r4) = ctx->r24;
            goto L_80004DC4;
    }
    // 0x80004E20: sb          $t8, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r24;
    // 0x80004E24: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80004E28: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80004E2C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80004E30: addiu       $t3, $t3, 0x5
    ctx->r11 = ADD32(ctx->r11, 0X5);
    // 0x80004E34: addiu       $t4, $t4, 0xA
    ctx->r12 = ADD32(ctx->r12, 0XA);
    // 0x80004E38: addiu       $t5, $t5, 0x5
    ctx->r13 = ADD32(ctx->r13, 0X5);
    // 0x80004E3C: addiu       $ra, $ra, 0xA
    ctx->r31 = ADD32(ctx->r31, 0XA);
    // 0x80004E40: addiu       $t1, $t1, 0x5
    ctx->r9 = ADD32(ctx->r9, 0X5);
    // 0x80004E44: addiu       $t2, $t2, 0x5
    ctx->r10 = ADD32(ctx->r10, 0X5);
    // 0x80004E48: addiu       $s2, $s2, 0xA
    ctx->r18 = ADD32(ctx->r18, 0XA);
    // 0x80004E4C: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
    // 0x80004E50: bne         $at, $zero, L_80004D88
    if (ctx->r1 != 0) {
        // 0x80004E54: addiu       $s4, $s4, 0x2
        ctx->r20 = ADD32(ctx->r20, 0X2);
            goto L_80004D88;
    }
    // 0x80004E54: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x80004E58: sb          $zero, 0x74($v0)
    MEM_B(0X74, ctx->r2) = 0;
    // 0x80004E5C: swc1        $f10, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f10.u32l;
    // 0x80004E60: lbu         $t7, 0x4A($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X4A);
    // 0x80004E64: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80004E68: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80004E6C: bgez        $t7, L_80004E80
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80004E70: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80004E80;
    }
    // 0x80004E70: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80004E74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80004E78: nop

    // 0x80004E7C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80004E80:
    // 0x80004E80: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80004E84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80004E88: nop

    // 0x80004E8C: div.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80004E90: bne         $s6, $zero, L_80004F40
    if (ctx->r22 != 0) {
        // 0x80004E94: swc1        $f8, 0xD4($v0)
        MEM_W(0XD4, ctx->r2) = ctx->f8.u32l;
            goto L_80004F40;
    }
    // 0x80004E94: swc1        $f8, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->f8.u32l;
    // 0x80004E98: lbu         $t9, 0x2C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2C);
    // 0x80004E9C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80004EA0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80004EA4: bgez        $t9, L_80004EB8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80004EA8: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80004EB8;
    }
    // 0x80004EA8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80004EAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80004EB0: nop

    // 0x80004EB4: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80004EB8:
    // 0x80004EB8: lhu         $t6, 0x18($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X18);
    // 0x80004EBC: swc1        $f16, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f16.u32l;
    // 0x80004EC0: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80004EC4: bgez        $t6, L_80004EDC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80004EC8: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80004EDC;
    }
    // 0x80004EC8: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80004ECC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80004ED0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80004ED4: nop

    // 0x80004ED8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80004EDC:
    // 0x80004EDC: nop

    // 0x80004EE0: div.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004EE4: lbu         $t8, 0x31($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X31);
    // 0x80004EE8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80004EEC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80004EF0: nop

    // 0x80004EF4: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004EF8: bgez        $t8, L_80004F0C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80004EFC: swc1        $f10, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
            goto L_80004F0C;
    }
    // 0x80004EFC: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80004F00: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80004F04: nop

    // 0x80004F08: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80004F0C:
    // 0x80004F0C: lhu         $t7, 0x22($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X22);
    // 0x80004F10: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80004F14: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80004F18: bgez        $t7, L_80004F30
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80004F1C: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80004F30;
    }
    // 0x80004F1C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80004F20: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80004F24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80004F28: nop

    // 0x80004F2C: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80004F30:
    // 0x80004F30: nop

    // 0x80004F34: div.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004F38: b           L_80005090
    // 0x80004F3C: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
        goto L_80005090;
    // 0x80004F3C: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
L_80004F40:
    // 0x80004F40: lwc1        $f0, 0xD4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XD4);
    // 0x80004F44: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80004F48: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80004F4C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80004F50: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80004F54: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80004F58: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80004F5C: nop

    // 0x80004F60: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80004F64: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x80004F68: nop

    // 0x80004F6C: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x80004F70: beq         $v1, $zero, L_80004FBC
    if (ctx->r3 == 0) {
        // 0x80004F74: nop
    
            goto L_80004FBC;
    }
    // 0x80004F74: nop

    // 0x80004F78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80004F7C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80004F80: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80004F84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80004F88: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80004F8C: nop

    // 0x80004F90: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80004F94: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x80004F98: nop

    // 0x80004F9C: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x80004FA0: bne         $v1, $zero, L_80004FB4
    if (ctx->r3 != 0) {
        // 0x80004FA4: nop
    
            goto L_80004FB4;
    }
    // 0x80004FA4: nop

    // 0x80004FA8: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80004FAC: b           L_80004FCC
    // 0x80004FB0: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_80004FCC;
    // 0x80004FB0: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_80004FB4:
    // 0x80004FB4: b           L_80004FCC
    // 0x80004FB8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_80004FCC;
    // 0x80004FB8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80004FBC:
    // 0x80004FBC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80004FC0: nop

    // 0x80004FC4: bltz        $v1, L_80004FB4
    if (SIGNED(ctx->r3) < 0) {
        // 0x80004FC8: nop
    
            goto L_80004FB4;
    }
    // 0x80004FC8: nop

L_80004FCC:
    // 0x80004FCC: lhu         $t8, 0x18($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X18);
    // 0x80004FD0: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // 0x80004FD4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80004FD8: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80004FDC: bne         $at, $zero, L_80005010
    if (ctx->r1 != 0) {
        // 0x80004FE0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80005010;
    }
    // 0x80004FE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80004FE4:
    // 0x80004FE4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80004FE8: andi        $t7, $a0, 0xFFFF
    ctx->r15 = ctx->r4 & 0XFFFF;
    // 0x80004FEC: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80004FF0: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x80004FF4: lhu         $t8, 0x18($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X18);
    // 0x80004FF8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80004FFC: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80005000: bne         $at, $zero, L_80005010
    if (ctx->r1 != 0) {
        // 0x80005004: slti        $at, $t7, 0x4
        ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
            goto L_80005010;
    }
    // 0x80005004: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80005008: bne         $at, $zero, L_80004FE4
    if (ctx->r1 != 0) {
        // 0x8000500C: nop
    
            goto L_80004FE4;
    }
    // 0x8000500C: nop

L_80005010:
    // 0x80005010: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80005014: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80005018: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8000501C: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x80005020: lhu         $a2, 0x18($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X18);
    // 0x80005024: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x80005028: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x8000502C: lhu         $t6, 0x1A($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X1A);
    // 0x80005030: subu        $t8, $a1, $a2
    ctx->r24 = SUB32(ctx->r5, ctx->r6);
    // 0x80005034: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80005038: subu        $t8, $t6, $a2
    ctx->r24 = SUB32(ctx->r14, ctx->r6);
    // 0x8000503C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80005040: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80005044: addu        $t9, $v0, $v1
    ctx->r25 = ADD32(ctx->r2, ctx->r3);
    // 0x80005048: addu        $t7, $v0, $v1
    ctx->r15 = ADD32(ctx->r2, ctx->r3);
    // 0x8000504C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80005050: lbu         $a3, 0x2C($t7)
    ctx->r7 = MEM_BU(ctx->r15, 0X2C);
    // 0x80005054: lbu         $t6, 0x2D($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X2D);
    // 0x80005058: div.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8000505C: subu        $t8, $t6, $a3
    ctx->r24 = SUB32(ctx->r14, ctx->r7);
    // 0x80005060: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80005064: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x80005068: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000506C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80005070: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80005074: bgez        $a3, L_80005088
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80005078: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80005088;
    }
    // 0x80005078: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000507C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80005080: nop

    // 0x80005084: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80005088:
    // 0x80005088: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000508C: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
L_80005090:
    // 0x80005090: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80005094: jal         0x80071380
    // 0x80005098: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x80005098: nop

    after_4:
    // 0x8000509C: jal         0x80071380
    // 0x800050A0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800050A0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_5:
    // 0x800050A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800050A8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800050AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800050B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800050B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800050B8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800050BC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800050C0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800050C4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800050C8: jr          $ra
    // 0x800050CC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800050CC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void obj_loop_trigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C7E4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8003C7E8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8003C7EC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8003C7F0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8003C7F4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8003C7F8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8003C7FC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8003C800: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8003C804: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8003C808: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8003C80C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003C810: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8003C814: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8003C818: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003C81C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8003C820: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x8003C824: lw          $fp, 0x3C($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X3C);
    // 0x8003C828: lw          $s2, 0x64($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X64);
    // 0x8003C82C: jal         0x8006ECD0
    // 0x8003C830: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8003C830: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    after_0:
    // 0x8003C834: lbu         $t7, 0x49($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X49);
    // 0x8003C838: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8003C83C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003C840: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8003C844: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x8003C848: jal         0x8006BFD8
    // 0x8003C84C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    level_type(rdram, ctx);
        goto after_1;
    // 0x8003C84C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    after_1:
    // 0x8003C850: lb          $v1, 0x9($fp)
    ctx->r3 = MEM_B(ctx->r30, 0X9);
    // 0x8003C854: nop

    // 0x8003C858: bltz        $v1, L_8003C9F0
    if (SIGNED(ctx->r3) < 0) {
        // 0x8003C85C: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8003C9F0;
    }
    // 0x8003C85C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8003C860: lw          $t1, 0x4C($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X4C);
    // 0x8003C864: lw          $a1, 0x10($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X10);
    // 0x8003C868: lbu         $t2, 0x13($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X13);
    // 0x8003C86C: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x8003C870: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003C874: beq         $at, $zero, L_8003C9EC
    if (ctx->r1 == 0) {
        // 0x8003C878: sllv        $a2, $t0, $v1
        ctx->r6 = S32(ctx->r8 << (ctx->r3 & 31));
            goto L_8003C9EC;
    }
    // 0x8003C878: sllv        $a2, $t0, $v1
    ctx->r6 = S32(ctx->r8 << (ctx->r3 & 31));
    // 0x8003C87C: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x8003C880: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003C884: bne         $t3, $at, L_8003C894
    if (ctx->r11 != ctx->r1) {
        // 0x8003C888: and         $t4, $s0, $a2
        ctx->r12 = ctx->r16 & ctx->r6;
            goto L_8003C894;
    }
    // 0x8003C888: and         $t4, $s0, $a2
    ctx->r12 = ctx->r16 & ctx->r6;
    // 0x8003C88C: bne         $t4, $zero, L_8003C9F0
    if (ctx->r12 != 0) {
        // 0x8003C890: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8003C9F0;
    }
    // 0x8003C890: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8003C894:
    // 0x8003C894: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003C898: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x8003C89C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8003C8A0: jal         0x8001BAA8
    // 0x8003C8A4: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    get_racer_objects(rdram, ctx);
        goto after_2;
    // 0x8003C8A4: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    after_2:
    // 0x8003C8A8: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C8AC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8003C8B0: blez        $t5, L_8003C9EC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8003C8B4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8003C9EC;
    }
    // 0x8003C8B4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8003C8B8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8003C8BC: addiu       $s6, $zero, 0xFF
    ctx->r22 = ADD32(0, 0XFF);
    // 0x8003C8C0: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
L_8003C8C4:
    // 0x8003C8C4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8003C8C8: lbu         $v1, 0x14($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X14);
    // 0x8003C8CC: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8003C8D0: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x8003C8D4: bne         $t7, $zero, L_8003C8EC
    if (ctx->r15 != 0) {
        // 0x8003C8D8: andi        $t8, $v1, 0x2
        ctx->r24 = ctx->r3 & 0X2;
            goto L_8003C8EC;
    }
    // 0x8003C8D8: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x8003C8DC: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8003C8E0: nop

    // 0x8003C8E4: beq         $s5, $t6, L_8003C904
    if (ctx->r21 == ctx->r14) {
        // 0x8003C8E8: nop
    
            goto L_8003C904;
    }
    // 0x8003C8E8: nop

L_8003C8EC:
    // 0x8003C8EC: bne         $t8, $zero, L_8003C9DC
    if (ctx->r24 != 0) {
        // 0x8003C8F0: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_8003C9DC;
    }
    // 0x8003C8F0: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C8F4: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8003C8F8: nop

    // 0x8003C8FC: beq         $s5, $t9, L_8003C9DC
    if (ctx->r21 == ctx->r25) {
        // 0x8003C900: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_8003C9DC;
    }
    // 0x8003C900: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
L_8003C904:
    // 0x8003C904: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003C908: lwc1        $f8, 0xC($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8003C90C: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003C910: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003C914: lwc1        $f16, 0x10($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X10);
    // 0x8003C918: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003C91C: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003C920: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003C924: lwc1        $f4, 0x14($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X14);
    // 0x8003C928: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003C92C: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003C930: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003C934: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003C938: jal         0x800CA030
    // 0x8003C93C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x8003C93C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_3:
    // 0x8003C940: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8003C944: nop

    // 0x8003C948: bc1f        L_8003C9DC
    if (!c1cs) {
        // 0x8003C94C: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_8003C9DC;
    }
    // 0x8003C94C: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C950: lwc1        $f18, 0x0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8003C954: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003C958: lwc1        $f8, 0x8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8003C95C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8003C960: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003C964: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8003C968: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8003C96C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003C970: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8003C974: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003C978: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8003C97C: nop

    // 0x8003C980: bc1f        L_8003C9DC
    if (!c1cs) {
        // 0x8003C984: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_8003C9DC;
    }
    // 0x8003C984: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C988: lbu         $t1, 0x49($s7)
    ctx->r9 = MEM_BU(ctx->r23, 0X49);
    // 0x8003C98C: lw          $t0, 0x4($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X4);
    // 0x8003C990: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8003C994: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x8003C998: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8003C99C: nop

    // 0x8003C9A0: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x8003C9A4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8003C9A8: lbu         $a0, 0xB($fp)
    ctx->r4 = MEM_BU(ctx->r30, 0XB);
    // 0x8003C9AC: nop

    // 0x8003C9B0: beq         $s6, $a0, L_8003C9C0
    if (ctx->r22 == ctx->r4) {
        // 0x8003C9B4: nop
    
            goto L_8003C9C0;
    }
    // 0x8003C9B4: nop

    // 0x8003C9B8: jal         0x800C3744
    // 0x8003C9BC: nop

    set_current_text(rdram, ctx);
        goto after_4;
    // 0x8003C9BC: nop

    after_4:
L_8003C9C0:
    // 0x8003C9C0: lbu         $v0, 0xC($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0XC);
    // 0x8003C9C4: nop

    // 0x8003C9C8: beq         $s6, $v0, L_8003C9DC
    if (ctx->r22 == ctx->r2) {
        // 0x8003C9CC: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_8003C9DC;
    }
    // 0x8003C9CC: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C9D0: jal         0x80021434
    // 0x8003C9D4: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    func_80021400(rdram, ctx);
        goto after_5;
    // 0x8003C9D4: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    after_5:
    // 0x8003C9D8: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
L_8003C9DC:
    // 0x8003C9DC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8003C9E0: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8003C9E4: bne         $at, $zero, L_8003C8C4
    if (ctx->r1 != 0) {
        // 0x8003C9E8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8003C8C4;
    }
    // 0x8003C9E8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8003C9EC:
    // 0x8003C9EC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8003C9F0:
    // 0x8003C9F0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8003C9F4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8003C9F8: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8003C9FC: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003CA00: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003CA04: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8003CA08: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8003CA0C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8003CA10: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8003CA14: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8003CA18: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8003CA1C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8003CA20: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8003CA24: jr          $ra
    // 0x8003CA28: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8003CA28: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void get_free_space(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800763EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800763F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800763F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800763F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800763FC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80076400: jal         0x80075B34
    // 0x80076404: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80076404: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80076408: bne         $v0, $zero, L_800764F4
    if (ctx->r2 != 0) {
        // 0x8007640C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800764F4;
    }
    // 0x8007640C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80076410: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80076414: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80076418: beq         $t6, $zero, L_80076470
    if (ctx->r14 == 0) {
        // 0x8007641C: subu        $t7, $t7, $s0
        ctx->r15 = SUB32(ctx->r15, ctx->r16);
            goto L_80076470;
    }
    // 0x8007641C: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80076420: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80076424: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x80076428: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007642C: addiu       $t8, $t8, 0x4598
    ctx->r24 = ADD32(ctx->r24, 0X4598);
    // 0x80076430: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80076434: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80076438: jal         0x800CF940
    // 0x8007643C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_1;
    // 0x8007643C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80076440: beq         $v0, $zero, L_80076460
    if (ctx->r2 == 0) {
        // 0x80076444: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80076460;
    }
    // 0x80076444: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80076448: jal         0x80075D44
    // 0x8007644C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_2;
    // 0x8007644C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80076450: sll         $v0, $s0, 30
    ctx->r2 = S32(ctx->r16 << 30);
    // 0x80076454: ori         $t9, $v0, 0x9
    ctx->r25 = ctx->r2 | 0X9;
    // 0x80076458: b           L_80076510
    // 0x8007645C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80076510;
    // 0x8007645C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80076460:
    // 0x80076460: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80076464: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80076468: nop

    // 0x8007646C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
L_80076470:
    // 0x80076470: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80076474: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80076478: beq         $t2, $zero, L_800764FC
    if (ctx->r10 == 0) {
        // 0x8007647C: subu        $t3, $t3, $s0
        ctx->r11 = SUB32(ctx->r11, ctx->r16);
            goto L_800764FC;
    }
    // 0x8007647C: subu        $t3, $t3, $s0
    ctx->r11 = SUB32(ctx->r11, ctx->r16);
    // 0x80076480: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80076484: addu        $t3, $t3, $s0
    ctx->r11 = ADD32(ctx->r11, ctx->r16);
    // 0x80076488: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007648C: addiu       $t4, $t4, 0x4598
    ctx->r12 = ADD32(ctx->r12, 0X4598);
    // 0x80076490: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80076494: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80076498: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8007649C: jal         0x800D08F0
    // 0x800764A0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    osPfsNumFiles_recomp(rdram, ctx);
        goto after_3;
    // 0x800764A0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x800764A4: beq         $v0, $zero, L_800764C4
    if (ctx->r2 == 0) {
        // 0x800764A8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800764C4;
    }
    // 0x800764A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800764AC: jal         0x80075D44
    // 0x800764B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_4;
    // 0x800764B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800764B4: sll         $v0, $s0, 30
    ctx->r2 = S32(ctx->r16 << 30);
    // 0x800764B8: ori         $t5, $v0, 0x9
    ctx->r13 = ctx->r2 | 0X9;
    // 0x800764BC: b           L_80076510
    // 0x800764C0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_80076510;
    // 0x800764C0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800764C4:
    // 0x800764C4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800764C8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800764CC: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x800764D0: bne         $at, $zero, L_800764E4
    if (ctx->r1 != 0) {
        // 0x800764D4: addiu       $t9, $zero, 0x10
        ctx->r25 = ADD32(0, 0X10);
            goto L_800764E4;
    }
    // 0x800764D4: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x800764D8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800764DC: b           L_800764FC
    // 0x800764E0: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
        goto L_800764FC;
    // 0x800764E0: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_800764E4:
    // 0x800764E4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800764E8: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x800764EC: b           L_800764FC
    // 0x800764F0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
        goto L_800764FC;
    // 0x800764F0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
L_800764F4:
    // 0x800764F4: sll         $t2, $s0, 30
    ctx->r10 = S32(ctx->r16 << 30);
    // 0x800764F8: or          $v1, $v0, $t2
    ctx->r3 = ctx->r2 | ctx->r10;
L_800764FC:
    // 0x800764FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076500: jal         0x80075D44
    // 0x80076504: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_5;
    // 0x80076504: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_5:
    // 0x80076508: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8007650C: nop

L_80076510:
    // 0x80076510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80076514: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80076518: jr          $ra
    // 0x8007651C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007651C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void wavegen_register(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFB54: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BFB58: addiu       $v1, $v1, 0x3720
    ctx->r3 = ADD32(ctx->r3, 0X3720);
    // 0x800BFB5C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800BFB60: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BFB64: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800BFB68: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800BFB6C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BFB70: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800BFB74: beq         $t6, $zero, L_800BFF0C
    if (ctx->r14 == 0) {
        // 0x800BFB78: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800BFF0C;
    }
    // 0x800BFB78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BFB7C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800BFB80: lw          $t7, 0x3724($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3724);
    // 0x800BFB84: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x800BFB88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BFB8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800BFB90: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
L_800BFB94:
    // 0x800BFB94: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800BFB98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BFB9C: bne         $t9, $zero, L_800BFBA8
    if (ctx->r25 != 0) {
        // 0x800BFBA0: slti        $at, $v0, 0x20
        ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
            goto L_800BFBA8;
    }
    // 0x800BFBA0: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x800BFBA4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_800BFBA8:
    // 0x800BFBA8: beq         $at, $zero, L_800BFBB8
    if (ctx->r1 == 0) {
        // 0x800BFBAC: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800BFBB8;
    }
    // 0x800BFBAC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800BFBB0: beq         $a0, $zero, L_800BFB94
    if (ctx->r4 == 0) {
        // 0x800BFBB4: nop
    
            goto L_800BFB94;
    }
    // 0x800BFBB4: nop

L_800BFBB8:
    // 0x800BFBB8: beq         $a0, $zero, L_800BFF0C
    if (ctx->r4 == 0) {
        // 0x800BFBBC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800BFF0C;
    }
    // 0x800BFBBC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800BFBC0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BFBC4: lw          $t3, 0x3724($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3724);
    // 0x800BFBC8: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800BFBCC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800BFBD0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800BFBD4: addiu       $a0, $a0, 0x3718
    ctx->r4 = ADD32(ctx->r4, 0X3718);
    // 0x800BFBD8: sw          $a3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r7;
    // 0x800BFBDC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800BFBE0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BFBE4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BFBE8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800BFBEC: lw          $t8, -0x5A50($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5A50);
    // 0x800BFBF0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BFBF4: lwc1        $f0, -0x5988($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800BFBF8: beq         $t8, $zero, L_800BFC14
    if (ctx->r24 == 0) {
        // 0x800BFBFC: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_800BFC14;
    }
    // 0x800BFBFC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BFC00: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BFC04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BFC08: nop

    // 0x800BFC0C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800BFC10: nop

L_800BFC14:
    // 0x800BFC14: lw          $t9, -0x5970($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5970);
    // 0x800BFC18: sub.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800BFC1C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800BFC20: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BFC24: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BFC28: lw          $a1, 0x371C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X371C);
    // 0x800BFC2C: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800BFC30: nop

    // 0x800BFC34: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BFC38: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800BFC3C: nop

    // 0x800BFC40: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800BFC44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BFC48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BFC4C: nop

    // 0x800BFC50: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800BFC54: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x800BFC58: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800BFC5C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800BFC60: bne         $at, $zero, L_800BFC70
    if (ctx->r1 != 0) {
        // 0x800BFC64: nop
    
            goto L_800BFC70;
    }
    // 0x800BFC64: nop

    // 0x800BFC68: jr          $ra
    // 0x800BFC6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800BFC6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BFC70:
    // 0x800BFC70: add.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800BFC74: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800BFC78: nop

    // 0x800BFC7C: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800BFC80: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BFC84: nop

    // 0x800BFC88: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800BFC8C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BFC90: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BFC94: nop

    // 0x800BFC98: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BFC9C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800BFCA0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BFCA4: bgez        $a2, L_800BFCB4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800BFCA8: slt         $at, $a2, $a1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800BFCB4;
    }
    // 0x800BFCA8: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800BFCAC: jr          $ra
    // 0x800BFCB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800BFCB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BFCB4:
    // 0x800BFCB4: bgez        $a0, L_800BFCC0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800BFCB8: sll         $t4, $v0, 6
        ctx->r12 = S32(ctx->r2 << 6);
            goto L_800BFCC0;
    }
    // 0x800BFCB8: sll         $t4, $v0, 6
    ctx->r12 = S32(ctx->r2 << 6);
    // 0x800BFCBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BFCC0:
    // 0x800BFCC0: bne         $at, $zero, L_800BFCCC
    if (ctx->r1 != 0) {
        // 0x800BFCC4: addiu       $t2, $zero, 0xFF
        ctx->r10 = ADD32(0, 0XFF);
            goto L_800BFCCC;
    }
    // 0x800BFCC4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800BFCC8: addiu       $a2, $a1, -0x1
    ctx->r6 = ADD32(ctx->r5, -0X1);
L_800BFCCC:
    // 0x800BFCCC: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BFCD0: bne         $at, $zero, L_800BFD30
    if (ctx->r1 != 0) {
        // 0x800BFCD4: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_800BFD30;
    }
    // 0x800BFCD4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BFCD8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BFCDC: addiu       $t1, $t1, 0x3714
    ctx->r9 = ADD32(ctx->r9, 0X3714);
    // 0x800BFCE0: addiu       $t0, $a2, 0x1
    ctx->r8 = ADD32(ctx->r6, 0X1);
L_800BFCE4:
    // 0x800BFCE4: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800BFCE8: sll         $t5, $a1, 3
    ctx->r13 = S32(ctx->r5 << 3);
    // 0x800BFCEC: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x800BFCF0: lbu         $t7, 0x7($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X7);
    // 0x800BFCF4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BFCF8: bne         $t2, $t7, L_800BFD28
    if (ctx->r10 != ctx->r15) {
        // 0x800BFCFC: nop
    
            goto L_800BFD28;
    }
    // 0x800BFCFC: nop

    // 0x800BFD00: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800BFD04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BFD08: beq         $t2, $t8, L_800BFD20
    if (ctx->r10 == ctx->r24) {
        // 0x800BFD0C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800BFD20;
    }
    // 0x800BFD0C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_800BFD10:
    // 0x800BFD10: lbu         $t9, 0x1($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X1);
    // 0x800BFD14: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BFD18: bne         $t2, $t9, L_800BFD10
    if (ctx->r10 != ctx->r25) {
        // 0x800BFD1C: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800BFD10;
    }
    // 0x800BFD1C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800BFD20:
    // 0x800BFD20: addu        $t3, $a0, $a2
    ctx->r11 = ADD32(ctx->r4, ctx->r6);
    // 0x800BFD24: sb          $v0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r2;
L_800BFD28:
    // 0x800BFD28: bne         $t0, $a1, L_800BFCE4
    if (ctx->r8 != ctx->r5) {
        // 0x800BFD2C: nop
    
            goto L_800BFCE4;
    }
    // 0x800BFD2C: nop

L_800BFD30:
    // 0x800BFD30: lwc1        $f16, 0x8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800BFD34: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800BFD38: sub.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x800BFD3C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x800BFD40: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x800BFD44: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800BFD48: swc1        $f12, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f12.u32l;
    // 0x800BFD4C: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x800BFD50: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800BFD54: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x800BFD58: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800BFD5C: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800BFD60: swc1        $f14, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f14.u32l;
    // 0x800BFD64: sh          $v0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r2;
    // 0x800BFD68: swc1        $f10, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f10.u32l;
    // 0x800BFD6C: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
    // 0x800BFD70: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800BFD74: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BFD78: sh          $t6, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r14;
    // 0x800BFD7C: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800BFD80: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800BFD84: bne         $t7, $zero, L_800BFE34
    if (ctx->r15 != 0) {
        // 0x800BFD88: nop
    
            goto L_800BFE34;
    }
    // 0x800BFD88: nop

    // 0x800BFD8C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BFD90: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800BFD94: lwc1        $f19, -0x67D8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X67D8);
    // 0x800BFD98: lwc1        $f18, -0x67D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X67D4);
    // 0x800BFD9C: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x800BFDA0: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800BFDA4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800BFDA8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800BFDAC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BFDB0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BFDB4: nop

    // 0x800BFDB8: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800BFDBC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BFDC0: nop

    // 0x800BFDC4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800BFDC8: beq         $t9, $zero, L_800BFE18
    if (ctx->r25 == 0) {
        // 0x800BFDCC: nop
    
            goto L_800BFE18;
    }
    // 0x800BFDCC: nop

    // 0x800BFDD0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800BFDD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800BFDD8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800BFDDC: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x800BFDE0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BFDE4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BFDE8: nop

    // 0x800BFDEC: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x800BFDF0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BFDF4: nop

    // 0x800BFDF8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800BFDFC: bne         $t9, $zero, L_800BFE10
    if (ctx->r25 != 0) {
        // 0x800BFE00: nop
    
            goto L_800BFE10;
    }
    // 0x800BFE00: nop

    // 0x800BFE04: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800BFE08: b           L_800BFE28
    // 0x800BFE0C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800BFE28;
    // 0x800BFE0C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800BFE10:
    // 0x800BFE10: b           L_800BFE28
    // 0x800BFE14: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800BFE28;
    // 0x800BFE14: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800BFE18:
    // 0x800BFE18: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800BFE1C: nop

    // 0x800BFE20: bltz        $t9, L_800BFE10
    if (SIGNED(ctx->r25) < 0) {
        // 0x800BFE24: nop
    
            goto L_800BFE10;
    }
    // 0x800BFE24: nop

L_800BFE28:
    // 0x800BFE28: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BFE2C: b           L_800BFED4
    // 0x800BFE30: sw          $t9, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r25;
        goto L_800BFED4;
    // 0x800BFE30: sw          $t9, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r25;
L_800BFE34:
    // 0x800BFE34: lwc1        $f11, -0x67D0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X67D0);
    // 0x800BFE38: lwc1        $f10, -0x67CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X67CC);
    // 0x800BFE3C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800BFE40: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800BFE44: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800BFE48: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800BFE4C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800BFE50: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BFE54: nop

    // 0x800BFE58: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x800BFE5C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BFE60: nop

    // 0x800BFE64: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800BFE68: beq         $t4, $zero, L_800BFEB8
    if (ctx->r12 == 0) {
        // 0x800BFE6C: nop
    
            goto L_800BFEB8;
    }
    // 0x800BFE6C: nop

    // 0x800BFE70: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800BFE74: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800BFE78: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800BFE7C: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x800BFE80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BFE84: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BFE88: nop

    // 0x800BFE8C: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x800BFE90: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BFE94: nop

    // 0x800BFE98: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800BFE9C: bne         $t4, $zero, L_800BFEB0
    if (ctx->r12 != 0) {
        // 0x800BFEA0: nop
    
            goto L_800BFEB0;
    }
    // 0x800BFEA0: nop

    // 0x800BFEA4: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800BFEA8: b           L_800BFEC8
    // 0x800BFEAC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_800BFEC8;
    // 0x800BFEAC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_800BFEB0:
    // 0x800BFEB0: b           L_800BFEC8
    // 0x800BFEB4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_800BFEC8;
    // 0x800BFEB4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_800BFEB8:
    // 0x800BFEB8: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800BFEBC: nop

    // 0x800BFEC0: bltz        $t4, L_800BFEB0
    if (SIGNED(ctx->r12) < 0) {
        // 0x800BFEC4: nop
    
            goto L_800BFEB0;
    }
    // 0x800BFEC4: nop

L_800BFEC8:
    // 0x800BFEC8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800BFECC: sw          $t4, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r12;
    // 0x800BFED0: nop

L_800BFED4:
    // 0x800BFED4: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800BFED8: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800BFEDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BFEE0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800BFEE4: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800BFEE8: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x800BFEEC: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x800BFEF0: swc1        $f6, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f6.u32l;
    // 0x800BFEF4: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BFEF8: swc1        $f0, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f0.u32l;
    // 0x800BFEFC: sb          $t5, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r13;
    // 0x800BFF00: sb          $t6, 0x31($a1)
    MEM_B(0X31, ctx->r5) = ctx->r14;
    // 0x800BFF04: swc1        $f2, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f2.u32l;
    // 0x800BFF08: swc1        $f8, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f8.u32l;
L_800BFF0C:
    // 0x800BFF0C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800BFF10: jr          $ra
    // 0x800BFF14: nop

    return;
    // 0x800BFF14: nop

;}
RECOMP_FUNC void obj_init_weather(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040840: lh          $t6, 0x8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X8);
    // 0x80040844: nop

    // 0x80040848: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8004084C: nop

    // 0x80040850: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80040854: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80040858: jr          $ra
    // 0x8004085C: swc1        $f0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8004085C: swc1        $f0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void asset_rom_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077240: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077244: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80077248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007724C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80077250: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077254: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80077258: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x8007725C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80077260: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80077264: jal         0x800C9110
    // 0x80077268: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80077268: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007726C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80077270: lw          $v1, 0x4830($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4830);
    // 0x80077274: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80077278: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8007727C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80077280: sltu        $at, $t6, $a3
    ctx->r1 = ctx->r14 < ctx->r7 ? 1 : 0;
    // 0x80077284: beq         $at, $zero, L_80077294
    if (ctx->r1 == 0) {
        // 0x80077288: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80077294;
    }
    // 0x80077288: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8007728C: b           L_800772CC
    // 0x80077290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800772CC;
    // 0x80077290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80077294:
    // 0x80077294: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80077298: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x8007729C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800772A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800772A4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800772A8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800772AC: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x800772B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800772B4: jal         0x800C9390
    // 0x800772B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800772B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800772BC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800772C0: lui         $t2, 0xF
    ctx->r10 = S32(0XF << 16);
    // 0x800772C4: addiu       $t2, $t2, -0x2E50
    ctx->r10 = ADD32(ctx->r10, -0X2E50);
    // 0x800772C8: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
L_800772CC:
    // 0x800772CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800772D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800772D4: jr          $ra
    // 0x800772D8: nop

    return;
    // 0x800772D8: nop

;}
RECOMP_FUNC void trackbg_render_flashy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028090: addiu       $sp, $sp, -0x158
    ctx->r29 = ADD32(ctx->r29, -0X158);
    // 0x80028094: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80028098: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002809C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800280A0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800280A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800280A8: lw          $s1, -0x49D8($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X49D8);
    // 0x800280AC: lw          $s0, -0x49D4($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X49D4);
    // 0x800280B0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800280B4: jal         0x80069F60
    // 0x800280B8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x800280B8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    after_0:
    // 0x800280BC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800280C0: lw          $t6, -0x3174($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3174);
    // 0x800280C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800280C8: lw          $v1, 0xA4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0XA4);
    // 0x800280CC: nop

    // 0x800280D0: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x800280D4: lbu         $s3, 0x0($v1)
    ctx->r19 = MEM_BU(ctx->r3, 0X0);
    // 0x800280D8: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x800280DC: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x800280E0: sw          $t4, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r12;
    // 0x800280E4: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x800280E8: sll         $t7, $s3, 5
    ctx->r15 = S32(ctx->r19 << 5);
    // 0x800280EC: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800280F0: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800280F4: addiu       $s3, $t7, -0x1
    ctx->r19 = ADD32(ctx->r15, -0X1);
    // 0x800280F8: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800280FC: jal         0x80070A04
    // 0x80028100: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    sins_f(rdram, ctx);
        goto after_1;
    // 0x80028100: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    after_1:
    // 0x80028104: swc1        $f0, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f0.u32l;
    // 0x80028108: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    // 0x8002810C: nop

    // 0x80028110: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80028114: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80028118: jal         0x80070A38
    // 0x8002811C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    coss_f(rdram, ctx);
        goto after_2;
    // 0x8002811C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_2:
    // 0x80028120: lui         $at, 0x44A0
    ctx->r1 = S32(0X44A0 << 16);
    // 0x80028124: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80028128: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002812C: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80028130: lwc1        $f6, 0x10C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80028134: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80028138: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8002813C: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80028140: neg.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = -ctx->f12.fl;
    // 0x80028144: lw          $a0, -0x3174($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3174);
    // 0x80028148: add.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8002814C: sub.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80028150: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80028154: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80028158: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8002815C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80028160: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80028164: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80028168: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
    // 0x8002816C: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x80028170: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80028174: add.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80028178: swc1        $f8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f8.u32l;
    // 0x8002817C: swc1        $f8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f8.u32l;
    // 0x80028180: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80028184: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80028188: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002818C: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x80028190: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
    // 0x80028194: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x80028198: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002819C: add.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x800281A0: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x800281A4: add.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800281A8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x800281AC: swc1        $f4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f4.u32l;
    // 0x800281B0: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x800281B4: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800281B8: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800281BC: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x800281C0: sub.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800281C4: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800281C8: swc1        $f8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f8.u32l;
    // 0x800281CC: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800281D0: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800281D4: sub.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x800281D8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800281DC: swc1        $f8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f8.u32l;
    // 0x800281E0: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800281E4: swc1        $f10, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f10.u32l;
    // 0x800281E8: add.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x800281EC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800281F0: swc1        $f10, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f10.u32l;
    // 0x800281F4: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
    // 0x800281F8: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800281FC: add.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80028200: swc1        $f10, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f10.u32l;
    // 0x80028204: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    // 0x80028208: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x8002820C: lbu         $t5, 0xA0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0XA0);
    // 0x80028210: sll         $t4, $t9, 4
    ctx->r12 = S32(ctx->r25 << 4);
    // 0x80028214: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80028218: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002821C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80028220: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80028224: lbu         $t6, 0x1($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X1);
    // 0x80028228: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8002822C: lbu         $t8, 0xA1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA1);
    // 0x80028230: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80028234: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80028238: mflo        $a1
    ctx->r5 = lo;
    // 0x8002823C: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x80028240: nop

    // 0x80028244: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80028248: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002824C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80028250: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80028254: lh          $t5, 0xA8($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XA8);
    // 0x80028258: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8002825C: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80028260: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x80028264: mflo        $a2
    ctx->r6 = lo;
    // 0x80028268: mul.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8002826C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80028270: nop

    // 0x80028274: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80028278: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002827C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028280: nop

    // 0x80028284: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80028288: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x8002828C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80028290: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80028294: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80028298: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8002829C: and         $v0, $t7, $s3
    ctx->r2 = ctx->r15 & ctx->r19;
    // 0x800282A0: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x800282A4: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800282A8: lh          $t5, 0xAA($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XAA);
    // 0x800282AC: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800282B0: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800282B4: lw          $t7, 0x14C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14C);
    // 0x800282B8: sra         $t4, $t5, 4
    ctx->r12 = S32(SIGNED(ctx->r13) >> 4);
    // 0x800282BC: sh          $v0, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r2;
    // 0x800282C0: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800282C4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800282C8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800282CC: nop

    // 0x800282D0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800282D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800282D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800282DC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800282E0: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800282E4: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800282E8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800282EC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800282F0: mul.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800282F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800282F8: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x800282FC: and         $v1, $t6, $t7
    ctx->r3 = ctx->r14 & ctx->r15;
    // 0x80028300: mul.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80028304: neg.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = -ctx->f14.fl;
    // 0x80028308: swc1        $f14, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f14.u32l;
    // 0x8002830C: swc1        $f14, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f14.u32l;
    // 0x80028310: sub.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80028314: sh          $v1, 0x11C($sp)
    MEM_H(0X11C, ctx->r29) = ctx->r3;
    // 0x80028318: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002831C: nop

    // 0x80028320: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80028324: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80028328: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8002832C: sub.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80028330: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x80028334: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80028338: sh          $t6, 0x128($sp)
    MEM_H(0X128, ctx->r29) = ctx->r14;
    // 0x8002833C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80028340: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028344: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028348: nop

    // 0x8002834C: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80028350: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80028354: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80028358: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8002835C: addu        $t9, $a0, $v1
    ctx->r25 = ADD32(ctx->r4, ctx->r3);
    // 0x80028360: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80028364: sh          $t9, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r25;
    // 0x80028368: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8002836C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028370: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028374: nop

    // 0x80028378: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002837C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80028380: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80028384: sub.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80028388: addu        $t5, $t8, $v0
    ctx->r13 = ADD32(ctx->r24, ctx->r2);
    // 0x8002838C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80028390: sh          $t5, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r13;
    // 0x80028394: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80028398: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002839C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800283A0: nop

    // 0x800283A4: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800283A8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800283AC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800283B0: add.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x800283B4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800283B8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800283BC: sh          $t8, 0x116($sp)
    MEM_H(0X116, ctx->r29) = ctx->r24;
    // 0x800283C0: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800283C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800283C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800283CC: nop

    // 0x800283D0: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800283D4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800283D8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800283DC: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x800283E0: addu        $t6, $a1, $v0
    ctx->r14 = ADD32(ctx->r5, ctx->r2);
    // 0x800283E4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800283E8: sh          $t6, 0x12C($sp)
    MEM_H(0X12C, ctx->r29) = ctx->r14;
    // 0x800283EC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800283F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800283F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800283F8: addu        $t6, $a0, $v0
    ctx->r14 = ADD32(ctx->r4, ctx->r2);
    // 0x800283FC: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80028400: sh          $t6, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = ctx->r14;
    // 0x80028404: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80028408: addu        $t7, $a1, $v1
    ctx->r15 = ADD32(ctx->r5, ctx->r3);
    // 0x8002840C: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80028410: sh          $t7, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = ctx->r15;
    // 0x80028414: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80028418: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8002841C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80028420: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x80028424: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80028428: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002842C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028430: sh          $t4, 0x118($sp)
    MEM_H(0X118, ctx->r29) = ctx->r12;
    // 0x80028434: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80028438: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002843C: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80028440: add.s       $f2, $f14, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80028444: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x80028448: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002844C: sh          $t6, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r14;
    // 0x80028450: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80028454: nop

    // 0x80028458: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002845C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028460: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028464: nop

    // 0x80028468: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8002846C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80028470: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80028474: sub.s       $f8, $f14, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x80028478: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x8002847C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80028480: sh          $t4, 0x11E($sp)
    MEM_H(0X11E, ctx->r29) = ctx->r12;
    // 0x80028484: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80028488: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002848C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028490: nop

    // 0x80028494: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80028498: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002849C: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x800284A0: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x800284A4: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800284A8: addu        $t9, $t5, $v0
    ctx->r25 = ADD32(ctx->r13, ctx->r2);
    // 0x800284AC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800284B0: sh          $t9, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r25;
    // 0x800284B4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800284B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800284BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800284C0: nop

    // 0x800284C4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800284C8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800284CC: nop

    // 0x800284D0: nop

    // 0x800284D4: lwc1        $f14, 0xB4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800284D8: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800284DC: add.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x800284E0: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800284E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800284E8: addu        $t5, $t8, $v1
    ctx->r13 = ADD32(ctx->r24, ctx->r3);
    // 0x800284EC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800284F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800284F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800284F8: sh          $t5, 0x120($sp)
    MEM_H(0X120, ctx->r29) = ctx->r13;
    // 0x800284FC: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80028500: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80028504: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80028508: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8002850C: add.s       $f2, $f16, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f16.fl;
    // 0x80028510: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80028514: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80028518: sh          $t8, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r24;
    // 0x8002851C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80028520: addiu       $s3, $s3, -0x49E0
    ctx->r19 = ADD32(ctx->r19, -0X49E0);
    // 0x80028524: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80028528: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002852C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028530: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80028534: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80028538: addiu       $a1, $a1, -0x49DC
    ctx->r5 = ADD32(ctx->r5, -0X49DC);
    // 0x8002853C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80028540: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80028544: sub.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x80028548: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8002854C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80028550: sh          $t7, 0x122($sp)
    MEM_H(0X122, ctx->r29) = ctx->r15;
    // 0x80028554: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80028558: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002855C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028560: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80028564: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80028568: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002856C: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80028570: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80028574: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x80028578: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002857C: sh          $t6, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r14;
    // 0x80028580: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80028584: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028588: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002858C: nop

    // 0x80028590: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80028594: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80028598: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002859C: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x800285A0: jal         0x80068648
    // 0x800285A4: sh          $t4, 0x124($sp)
    MEM_H(0X124, ctx->r29) = ctx->r12;
    mtx_world_origin(rdram, ctx);
        goto after_3;
    // 0x800285A4: sh          $t4, 0x124($sp)
    MEM_H(0X124, ctx->r29) = ctx->r12;
    after_3:
    // 0x800285A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800285AC: lw          $a0, -0x3174($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3174);
    // 0x800285B0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800285B4: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x800285B8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800285BC: beq         $t2, $v1, L_800285DC
    if (ctx->r10 == ctx->r3) {
        // 0x800285C0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800285DC;
    }
    // 0x800285C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800285C4: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x800285C8: nop

    // 0x800285CC: bne         $v0, $v1, L_800285E4
    if (ctx->r2 != ctx->r3) {
        // 0x800285D0: nop
    
            goto L_800285E4;
    }
    // 0x800285D0: nop

    // 0x800285D4: b           L_800285E4
    // 0x800285D8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_800285E4;
    // 0x800285D8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800285DC:
    // 0x800285DC: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x800285E0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_800285E4:
    // 0x800285E4: beq         $t2, $zero, L_80028600
    if (ctx->r10 == 0) {
        // 0x800285E8: addiu       $a3, $zero, -0x100
        ctx->r7 = ADD32(0, -0X100);
            goto L_80028600;
    }
    // 0x800285E8: addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // 0x800285EC: lw          $a3, 0x10($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X10);
    // 0x800285F0: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800285F4: and         $t6, $a3, $at
    ctx->r14 = ctx->r7 & ctx->r1;
    // 0x800285F8: lw          $a2, 0x10($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X10);
    // 0x800285FC: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
L_80028600:
    // 0x80028600: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80028604: jal         0x8007F9E4
    // 0x80028608: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    gfx_init_basic_xlu(rdram, ctx);
        goto after_4;
    // 0x80028608: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    after_4:
    // 0x8002860C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80028610: lw          $a1, -0x4970($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4970);
    // 0x80028614: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80028618: sll         $t7, $a1, 8
    ctx->r15 = S32(ctx->r5 << 8);
    // 0x8002861C: jal         0x8007B8BC
    // 0x80028620: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    set_animated_texture_header(rdram, ctx);
        goto after_5;
    // 0x80028620: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_5:
    // 0x80028624: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80028628: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8002862C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80028630: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x80028634: lh          $a1, 0xA($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XA);
    // 0x80028638: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x8002863C: andi        $t5, $a1, 0xFF
    ctx->r13 = ctx->r5 & 0XFF;
    // 0x80028640: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x80028644: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x80028648: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8002864C: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x80028650: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80028654: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80028658: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x8002865C: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80028660: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80028664: addu        $t9, $t5, $t1
    ctx->r25 = ADD32(ctx->r13, ctx->r9);
    // 0x80028668: addiu       $t3, $t3, -0x49D8
    ctx->r11 = ADD32(ctx->r11, -0X49D8);
    // 0x8002866C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80028670: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80028674: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80028678: addu        $t7, $t4, $t1
    ctx->r15 = ADD32(ctx->r12, ctx->r9);
    // 0x8002867C: andi        $t8, $t7, 0x6
    ctx->r24 = ctx->r15 & 0X6;
    // 0x80028680: ori         $t5, $t8, 0x40
    ctx->r13 = ctx->r24 | 0X40;
    // 0x80028684: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80028688: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8002868C: andi        $t9, $t5, 0xFF
    ctx->r25 = ctx->r13 & 0XFF;
    // 0x80028690: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80028694: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80028698: or          $t4, $t6, $at
    ctx->r12 = ctx->r14 | ctx->r1;
    // 0x8002869C: ori         $t7, $t4, 0xAA
    ctx->r15 = ctx->r12 | 0XAA;
    // 0x800286A0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800286A4: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x800286A8: lui         $t6, 0x571
    ctx->r14 = S32(0X571 << 16);
    // 0x800286AC: addu        $t5, $t8, $t1
    ctx->r13 = ADD32(ctx->r24, ctx->r9);
    // 0x800286B0: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800286B4: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800286B8: ori         $t6, $t6, 0x80
    ctx->r14 = ctx->r14 | 0X80;
    // 0x800286BC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800286C0: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x800286C4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800286C8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800286CC: lw          $t4, -0x49D4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X49D4);
    // 0x800286D0: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800286D4: addu        $t7, $t4, $t1
    ctx->r15 = ADD32(ctx->r12, ctx->r9);
    // 0x800286D8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800286DC: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800286E0: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800286E4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800286E8: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800286EC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800286F0: beq         $t2, $zero, L_8002872C
    if (ctx->r10 == 0) {
        // 0x800286F4: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_8002872C;
    }
    // 0x800286F4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800286F8: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800286FC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80028700: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80028704: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80028708: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8002870C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80028710: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80028714: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80028718: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8002871C: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80028720: addiu       $t5, $zero, -0x100
    ctx->r13 = ADD32(0, -0X100);
    // 0x80028724: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80028728: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8002872C:
    // 0x8002872C: jal         0x8007B820
    // 0x80028730: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rendermode_reset(rdram, ctx);
        goto after_6;
    // 0x80028730: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x80028734: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x80028738: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002873C: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80028740: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
    // 0x80028744: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80028748: addiu       $v0, $sp, 0xB8
    ctx->r2 = ADD32(ctx->r29, 0XB8);
    // 0x8002874C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80028750: addiu       $a3, $sp, 0xDC
    ctx->r7 = ADD32(ctx->r29, 0XDC);
    // 0x80028754: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80028758: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002875C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028760: addiu       $a2, $sp, 0xCC
    ctx->r6 = ADD32(ctx->r29, 0XCC);
    // 0x80028764: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80028768: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8002876C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80028770: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80028774: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80028778: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
L_8002877C:
    // 0x8002877C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80028780: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80028784: sh          $a1, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r5;
    // 0x80028788: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8002878C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80028790: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80028794: nop

    // 0x80028798: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002879C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800287A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800287A4: nop

    // 0x800287A8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800287AC: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800287B0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800287B4: sh          $t8, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r24;
    // 0x800287B8: lwc1        $f10, 0x14($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800287BC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800287C0: sb          $v1, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r3;
    // 0x800287C4: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800287C8: sb          $v1, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r3;
    // 0x800287CC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800287D0: sb          $v1, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r3;
    // 0x800287D4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800287D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800287DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800287E0: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x800287E4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800287E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800287EC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800287F0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800287F4: beq         $at, $zero, L_80028804
    if (ctx->r1 == 0) {
        // 0x800287F8: sh          $t9, 0x4($s1)
        MEM_H(0X4, ctx->r17) = ctx->r25;
            goto L_80028804;
    }
    // 0x800287F8: sh          $t9, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r25;
    // 0x800287FC: b           L_80028808
    // 0x80028800: sb          $v1, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r3;
        goto L_80028808;
    // 0x80028800: sb          $v1, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r3;
L_80028804:
    // 0x80028804: sb          $zero, 0x9($s1)
    MEM_B(0X9, ctx->r17) = 0;
L_80028808:
    // 0x80028808: sltu        $at, $v0, $a3
    ctx->r1 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x8002880C: bne         $at, $zero, L_8002877C
    if (ctx->r1 != 0) {
        // 0x80028810: addiu       $s1, $s1, 0xA
        ctx->r17 = ADD32(ctx->r17, 0XA);
            goto L_8002877C;
    }
    // 0x80028810: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80028814: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80028818: addiu       $v0, $v0, -0x3164
    ctx->r2 = ADD32(ctx->r2, -0X3164);
    // 0x8002881C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80028820: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80028824: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80028828: addiu       $a0, $sp, 0x114
    ctx->r4 = ADD32(ctx->r29, 0X114);
    // 0x8002882C: addiu       $v1, $sp, 0x128
    ctx->r3 = ADD32(ctx->r29, 0X128);
L_80028830:
    // 0x80028830: sb          $a1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r5;
    // 0x80028834: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80028838: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8002883C: sb          $t6, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r14;
    // 0x80028840: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x80028844: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80028848: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x8002884C: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80028850: lh          $t5, 0x0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X0);
    // 0x80028854: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x80028858: sh          $t5, -0x1C($s0)
    MEM_H(-0X1C, ctx->r16) = ctx->r13;
    // 0x8002885C: lbu         $t9, -0x6($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X6);
    // 0x80028860: nop

    // 0x80028864: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80028868: addu        $t4, $a0, $t6
    ctx->r12 = ADD32(ctx->r4, ctx->r14);
    // 0x8002886C: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    // 0x80028870: nop

    // 0x80028874: sh          $t7, -0x1A($s0)
    MEM_H(-0X1A, ctx->r16) = ctx->r15;
    // 0x80028878: lbu         $t8, -0x5($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X5);
    // 0x8002887C: nop

    // 0x80028880: sb          $t8, -0x1E($s0)
    MEM_B(-0X1E, ctx->r16) = ctx->r24;
    // 0x80028884: lbu         $t5, -0x5($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X5);
    // 0x80028888: nop

    // 0x8002888C: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x80028890: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x80028894: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x80028898: nop

    // 0x8002889C: sh          $t4, -0x18($s0)
    MEM_H(-0X18, ctx->r16) = ctx->r12;
    // 0x800288A0: lbu         $t7, -0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0X5);
    // 0x800288A4: nop

    // 0x800288A8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800288AC: addu        $t5, $a0, $t8
    ctx->r13 = ADD32(ctx->r4, ctx->r24);
    // 0x800288B0: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x800288B4: nop

    // 0x800288B8: sh          $t9, -0x16($s0)
    MEM_H(-0X16, ctx->r16) = ctx->r25;
    // 0x800288BC: lbu         $t6, -0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X4);
    // 0x800288C0: nop

    // 0x800288C4: sb          $t6, -0x1D($s0)
    MEM_B(-0X1D, ctx->r16) = ctx->r14;
    // 0x800288C8: lbu         $t4, -0x4($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0X4);
    // 0x800288CC: nop

    // 0x800288D0: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x800288D4: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800288D8: lh          $t5, 0x0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X0);
    // 0x800288DC: nop

    // 0x800288E0: sh          $t5, -0x14($s0)
    MEM_H(-0X14, ctx->r16) = ctx->r13;
    // 0x800288E4: lbu         $t9, -0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X4);
    // 0x800288E8: nop

    // 0x800288EC: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800288F0: addu        $t4, $a0, $t6
    ctx->r12 = ADD32(ctx->r4, ctx->r14);
    // 0x800288F4: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    // 0x800288F8: sb          $a1, -0x10($s0)
    MEM_B(-0X10, ctx->r16) = ctx->r5;
    // 0x800288FC: sh          $t7, -0x12($s0)
    MEM_H(-0X12, ctx->r16) = ctx->r15;
    // 0x80028900: lbu         $t8, -0x3($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X3);
    // 0x80028904: nop

    // 0x80028908: sb          $t8, -0xF($s0)
    MEM_B(-0XF, ctx->r16) = ctx->r24;
    // 0x8002890C: lbu         $t5, -0x3($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X3);
    // 0x80028910: nop

    // 0x80028914: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x80028918: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x8002891C: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x80028920: nop

    // 0x80028924: sh          $t4, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = ctx->r12;
    // 0x80028928: lbu         $t7, -0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0X3);
    // 0x8002892C: nop

    // 0x80028930: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80028934: addu        $t5, $a0, $t8
    ctx->r13 = ADD32(ctx->r4, ctx->r24);
    // 0x80028938: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x8002893C: nop

    // 0x80028940: sh          $t9, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = ctx->r25;
    // 0x80028944: lbu         $t6, -0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X2);
    // 0x80028948: nop

    // 0x8002894C: sb          $t6, -0xE($s0)
    MEM_B(-0XE, ctx->r16) = ctx->r14;
    // 0x80028950: lbu         $t4, -0x2($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0X2);
    // 0x80028954: nop

    // 0x80028958: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x8002895C: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80028960: lh          $t5, 0x0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X0);
    // 0x80028964: nop

    // 0x80028968: sh          $t5, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r13;
    // 0x8002896C: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x80028970: nop

    // 0x80028974: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80028978: addu        $t4, $a0, $t6
    ctx->r12 = ADD32(ctx->r4, ctx->r14);
    // 0x8002897C: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    // 0x80028980: nop

    // 0x80028984: sh          $t7, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r15;
    // 0x80028988: lbu         $t8, -0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X1);
    // 0x8002898C: nop

    // 0x80028990: sb          $t8, -0xD($s0)
    MEM_B(-0XD, ctx->r16) = ctx->r24;
    // 0x80028994: lbu         $t5, -0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X1);
    // 0x80028998: nop

    // 0x8002899C: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x800289A0: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x800289A4: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x800289A8: nop

    // 0x800289AC: sh          $t4, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r12;
    // 0x800289B0: lbu         $t7, -0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0X1);
    // 0x800289B4: nop

    // 0x800289B8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800289BC: addu        $t5, $a0, $t8
    ctx->r13 = ADD32(ctx->r4, ctx->r24);
    // 0x800289C0: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x800289C4: bne         $a2, $a3, L_80028830
    if (ctx->r6 != ctx->r7) {
        // 0x800289C8: sh          $t9, -0x2($s0)
        MEM_H(-0X2, ctx->r16) = ctx->r25;
            goto L_80028830;
    }
    // 0x800289C8: sh          $t9, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r25;
    // 0x800289CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800289D0: sw          $s1, -0x49D8($at)
    MEM_W(-0X49D8, ctx->r1) = ctx->r17;
    // 0x800289D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800289D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800289DC: sw          $s0, -0x49D4($at)
    MEM_W(-0X49D4, ctx->r1) = ctx->r16;
    // 0x800289E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800289E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800289E8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800289EC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800289F0: jr          $ra
    // 0x800289F4: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
    return;
    // 0x800289F4: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
;}
RECOMP_FUNC void draw_dialogue_text_unused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4A20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C4A24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C4A28: bltz        $a1, L_800C4A60
    if (SIGNED(ctx->r5) < 0) {
        // 0x800C4A2C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800C4A60;
    }
    // 0x800C4A2C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C4A30: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x800C4A34: beq         $at, $zero, L_800C4A60
    if (ctx->r1 == 0) {
        // 0x800C4A38: sll         $t7, $a1, 2
        ctx->r15 = S32(ctx->r5 << 2);
            goto L_800C4A60;
    }
    // 0x800C4A38: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C4A3C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C4A40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4A44: lw          $t8, -0x5258($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5258);
    // 0x800C4A48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C4A4C: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x800C4A50: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C4A54: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x800C4A58: jal         0x800C4B04
    // 0x800C4A5C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    render_text_string(rdram, ctx);
        goto after_0;
    // 0x800C4A5C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
L_800C4A60:
    // 0x800C4A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4A64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C4A68: jr          $ra
    // 0x800C4A6C: nop

    return;
    // 0x800C4A6C: nop

;}
RECOMP_FUNC void set_language(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F0D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009F0DC: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8009F0E0: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x8009F0E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009F0E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009F0EC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8009F0F0: beq         $a0, $at, L_8009F118
    if (ctx->r4 == ctx->r1) {
        // 0x8009F0F4: sw          $t6, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r14;
            goto L_8009F118;
    }
    // 0x8009F0F4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8009F0F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009F0FC: beq         $a0, $at, L_8009F12C
    if (ctx->r4 == ctx->r1) {
        // 0x8009F100: addiu       $t0, $zero, 0x0
        ctx->r8 = ADD32(0, 0X0);
            goto L_8009F12C;
    }
    // 0x8009F100: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x8009F104: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009F108: beq         $a0, $at, L_8009F13C
    if (ctx->r4 == ctx->r1) {
        // 0x8009F10C: addiu       $t2, $zero, 0x0
        ctx->r10 = ADD32(0, 0X0);
            goto L_8009F13C;
    }
    // 0x8009F10C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8009F110: b           L_8009F148
    // 0x8009F114: nop

        goto L_8009F148;
    // 0x8009F114: nop

L_8009F118:
    // 0x8009F118: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8009F11C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8009F120: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8009F124: b           L_8009F148
    // 0x8009F128: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_8009F148;
    // 0x8009F128: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_8009F12C:
    // 0x8009F12C: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8009F130: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8009F134: b           L_8009F148
    // 0x8009F138: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
        goto L_8009F148;
    // 0x8009F138: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_8009F13C:
    // 0x8009F13C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x8009F140: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8009F144: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_8009F148:
    // 0x8009F148: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009F14C: addiu       $v0, $v0, 0x69E8
    ctx->r2 = ADD32(ctx->r2, 0X69E8);
    // 0x8009F150: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8009F154: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009F158: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8009F15C: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8009F160: addiu       $at, $zero, -0xD
    ctx->r1 = ADD32(0, -0XD);
    // 0x8009F164: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8009F168: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8009F16C: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8009F170: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009F174: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009F178: or          $t2, $t6, $t0
    ctx->r10 = ctx->r14 | ctx->r8;
    // 0x8009F17C: or          $t3, $t7, $t1
    ctx->r11 = ctx->r15 | ctx->r9;
    // 0x8009F180: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8009F184: jal         0x8007FD50
    // 0x8009F188: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    load_menu_text(rdram, ctx);
        goto after_0;
    // 0x8009F188: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_0:
    // 0x8009F18C: jal         0x8006EF20
    // 0x8009F190: nop

    mark_write_eeprom_settings(rdram, ctx);
        goto after_1;
    // 0x8009F190: nop

    after_1:
    // 0x8009F194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009F198: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009F19C: jr          $ra
    // 0x8009F1A0: nop

    return;
    // 0x8009F1A0: nop

;}
RECOMP_FUNC void init_particle_assets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEA90: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AEA94: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AEA98: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800AEA9C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800AEAA0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800AEAA4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800AEAA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800AEAAC: jal         0x800AE9F0
    // 0x800AEAB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    free_particle_assets(rdram, ctx);
        goto after_0;
    // 0x800AEAB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800AEAB4: jal         0x80076EE4
    // 0x800AEAB8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    asset_table_load(rdram, ctx);
        goto after_1;
    // 0x800AEAB8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_1:
    // 0x800AEABC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800AEAC0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800AEAC4: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800AEAC8: addiu       $s2, $s2, 0x3280
    ctx->r18 = ADD32(ctx->r18, 0X3280);
    // 0x800AEACC: addiu       $a1, $a1, 0x3278
    ctx->r5 = ADD32(ctx->r5, 0X3278);
    // 0x800AEAD0: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800AEAD4: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800AEAD8: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x800AEADC: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800AEAE0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800AEAE4: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800AEAE8: beq         $a2, $t8, L_800AEB10
    if (ctx->r6 == ctx->r24) {
        // 0x800AEAEC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800AEB10;
    }
    // 0x800AEAEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800AEAF0: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_800AEAF4:
    // 0x800AEAF4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800AEAF8: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800AEAFC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800AEB00: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800AEB04: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800AEB08: bne         $a2, $t2, L_800AEAF4
    if (ctx->r6 != ctx->r10) {
        // 0x800AEB0C: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_800AEAF4;
    }
    // 0x800AEB0C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_800AEB10:
    // 0x800AEB10: jal         0x80076EE4
    // 0x800AEB14: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    asset_table_load(rdram, ctx);
        goto after_2;
    // 0x800AEB14: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_2:
    // 0x800AEB18: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800AEB1C: addiu       $a1, $a1, 0x3278
    ctx->r5 = ADD32(ctx->r5, 0X3278);
    // 0x800AEB20: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x800AEB24: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AEB28: addiu       $v1, $v1, 0x327C
    ctx->r3 = ADD32(ctx->r3, 0X327C);
    // 0x800AEB2C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800AEB30: blez        $t3, L_800AEB70
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800AEB34: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800AEB70;
    }
    // 0x800AEB34: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AEB38: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AEB3C:
    // 0x800AEB3C: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800AEB40: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800AEB44: addu        $v0, $t4, $s0
    ctx->r2 = ADD32(ctx->r12, ctx->r16);
    // 0x800AEB48: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800AEB4C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEB50: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800AEB54: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800AEB58: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800AEB5C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800AEB60: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AEB64: bne         $at, $zero, L_800AEB3C
    if (ctx->r1 != 0) {
        // 0x800AEB68: nop
    
            goto L_800AEB3C;
    }
    // 0x800AEB68: nop

    // 0x800AEB6C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AEB70:
    // 0x800AEB70: jal         0x80076EE4
    // 0x800AEB74: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    asset_table_load(rdram, ctx);
        goto after_3;
    // 0x800AEB74: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_3:
    // 0x800AEB78: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800AEB7C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800AEB80: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800AEB84: addiu       $s3, $s3, 0x328C
    ctx->r19 = ADD32(ctx->r19, 0X328C);
    // 0x800AEB88: addiu       $s2, $s2, 0x3284
    ctx->r18 = ADD32(ctx->r18, 0X3284);
    // 0x800AEB8C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800AEB90: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800AEB94: sw          $a2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r6;
    // 0x800AEB98: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800AEB9C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800AEBA0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800AEBA4: beq         $a2, $t1, L_800AEBCC
    if (ctx->r6 == ctx->r9) {
        // 0x800AEBA8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800AEBCC;
    }
    // 0x800AEBA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800AEBAC: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
L_800AEBB0:
    // 0x800AEBB0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800AEBB4: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x800AEBB8: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x800AEBBC: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800AEBC0: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x800AEBC4: bne         $a2, $t5, L_800AEBB0
    if (ctx->r6 != ctx->r13) {
        // 0x800AEBC8: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_800AEBB0;
    }
    // 0x800AEBC8: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
L_800AEBCC:
    // 0x800AEBCC: jal         0x80076EE4
    // 0x800AEBD0: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    asset_table_load(rdram, ctx);
        goto after_4;
    // 0x800AEBD0: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    after_4:
    // 0x800AEBD4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800AEBD8: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800AEBDC: addiu       $s5, $s5, 0x3288
    ctx->r21 = ADD32(ctx->r21, 0X3288);
    // 0x800AEBE0: blez        $t6, L_800AEC64
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800AEBE4: sw          $v0, 0x0($s5)
        MEM_W(0X0, ctx->r21) = ctx->r2;
            goto L_800AEC64;
    }
    // 0x800AEBE4: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x800AEBE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AEBEC: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_800AEBF0:
    // 0x800AEBF0: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800AEBF4: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x800AEBF8: addu        $v0, $t7, $s0
    ctx->r2 = ADD32(ctx->r15, ctx->r16);
    // 0x800AEBFC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800AEC00: nop

    // 0x800AEC04: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AEC08: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800AEC0C: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800AEC10: nop

    // 0x800AEC14: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x800AEC18: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800AEC1C: nop

    // 0x800AEC20: lw          $v1, 0x9C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X9C);
    // 0x800AEC24: nop

    // 0x800AEC28: beq         $s4, $v1, L_800AEC50
    if (ctx->r20 == ctx->r3) {
        // 0x800AEC2C: nop
    
            goto L_800AEC50;
    }
    // 0x800AEC2C: nop

    // 0x800AEC30: jal         0x8001E2D0
    // 0x800AEC34: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    get_misc_asset(rdram, ctx);
        goto after_5;
    // 0x800AEC34: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    after_5:
    // 0x800AEC38: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800AEC3C: nop

    // 0x800AEC40: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x800AEC44: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800AEC48: nop

    // 0x800AEC4C: sw          $v0, 0x9C($t6)
    MEM_W(0X9C, ctx->r14) = ctx->r2;
L_800AEC50:
    // 0x800AEC50: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AEC54: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEC58: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AEC5C: bne         $at, $zero, L_800AEBF0
    if (ctx->r1 != 0) {
        // 0x800AEC60: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800AEBF0;
    }
    // 0x800AEC60: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800AEC64:
    // 0x800AEC64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AEC68: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AEC6C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AEC70: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEC74: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800AEC78: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800AEC7C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800AEC80: jr          $ra
    // 0x800AEC84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800AEC84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void get_player_character(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C7C4: bltz        $a0, L_8009C7D4
    if (SIGNED(ctx->r4) < 0) {
        // 0x8009C7C8: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_8009C7D4;
    }
    // 0x8009C7C8: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x8009C7CC: bne         $at, $zero, L_8009C7DC
    if (ctx->r1 != 0) {
        // 0x8009C7D0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8009C7DC;
    }
    // 0x8009C7D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
L_8009C7D4:
    // 0x8009C7D4: jr          $ra
    // 0x8009C7D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8009C7D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009C7DC:
    // 0x8009C7DC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8009C7E0: lb          $t6, 0x6974($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X6974);
    // 0x8009C7E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C7E8: bne         $t6, $zero, L_8009C7F8
    if (ctx->r14 != 0) {
        // 0x8009C7EC: addu        $v0, $v0, $a0
        ctx->r2 = ADD32(ctx->r2, ctx->r4);
            goto L_8009C7F8;
    }
    // 0x8009C7EC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009C7F0: jr          $ra
    // 0x8009C7F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8009C7F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009C7F8:
    // 0x8009C7F8: lb          $v0, 0x6988($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6988);
    // 0x8009C7FC: nop

    // 0x8009C800: jr          $ra
    // 0x8009C804: nop

    return;
    // 0x8009C804: nop

;}
RECOMP_FUNC void dialogue_close(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5B80: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5B84: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5B88: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C5B8C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5B90: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C5B94: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5B98: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C5B9C: nop

    // 0x800C5BA0: andi        $t9, $t8, 0x7FFF
    ctx->r25 = ctx->r24 & 0X7FFF;
    // 0x800C5BA4: jr          $ra
    // 0x800C5BA8: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C5BA8: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void hud_render_general(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A89D0: addiu       $sp, $sp, -0x160
    ctx->r29 = ADD32(ctx->r29, -0X160);
    // 0x800A89D4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A89D8: sw          $a0, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r4;
    // 0x800A89DC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800A89E0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800A89E4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800A89E8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800A89EC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800A89F0: sw          $a1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r5;
    // 0x800A89F4: sw          $a2, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r6;
    // 0x800A89F8: sw          $a3, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r7;
    // 0x800A89FC: jal         0x800A1114
    // 0x800A8A00: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_audio_update(rdram, ctx);
        goto after_0;
    // 0x800A8A00: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800A8A04: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A8A08: addiu       $s0, $s0, 0x7298
    ctx->r16 = ADD32(ctx->r16, 0X7298);
    // 0x800A8A0C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800A8A10: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A8A14: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    // 0x800A8A18: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A8A1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8A20: sb          $zero, 0x17($t7)
    MEM_B(0X17, ctx->r15) = 0;
    // 0x800A8A24: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800A8A28: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A8A2C: sb          $zero, 0x8($t8)
    MEM_B(0X8, ctx->r24) = 0;
    // 0x800A8A30: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A8A34: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A8A38: sb          $zero, 0x11($t9)
    MEM_B(0X11, ctx->r25) = 0;
    // 0x800A8A3C: lb          $t2, 0x7293($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X7293);
    // 0x800A8A40: sw          $zero, 0x7740($at)
    MEM_W(0X7740, ctx->r1) = 0;
    // 0x800A8A44: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x800A8A48: beq         $t3, $zero, L_800A8AC4
    if (ctx->r11 == 0) {
        // 0x800A8A4C: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800A8AC4;
    }
    // 0x800A8A4C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A8A50: lb          $t4, 0x7290($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X7290);
    // 0x800A8A54: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A8A58: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800A8A5C: lbu         $t5, 0x774B($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X774B);
    // 0x800A8A60: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A8A64: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A8A68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A8A6C: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800A8A70: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A8A74: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800A8A78: bgez        $t5, L_800A8A8C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800A8A7C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800A8A8C;
    }
    // 0x800A8A7C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A8A80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A8A84: nop

    // 0x800A8A88: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800A8A8C:
    // 0x800A8A8C: nop

    // 0x800A8A90: div.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800A8A94: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800A8A98: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A8A9C: nop

    // 0x800A8AA0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A8AA4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8AA8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8AAC: nop

    // 0x800A8AB0: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A8AB4: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800A8AB8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A8ABC: b           L_800A8AC8
    // 0x800A8AC0: sw          $t7, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r15;
        goto L_800A8AC8;
    // 0x800A8AC0: sw          $t7, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r15;
L_800A8AC4:
    // 0x800A8AC4: sw          $t8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r24;
L_800A8AC8:
    // 0x800A8AC8: lw          $t9, 0x72B8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72B8);
    // 0x800A8ACC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A8AD0: blez        $t9, L_800A8C34
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800A8AD4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800A8C34;
    }
    // 0x800A8AD4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A8AD8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8ADC: addiu       $a1, $a1, 0x72B4
    ctx->r5 = ADD32(ctx->r5, 0X72B4);
    // 0x800A8AE0: ori         $s3, $zero, 0xC000
    ctx->r19 = 0 | 0XC000;
    // 0x800A8AE4: addiu       $s2, $zero, 0x28
    ctx->r18 = ADD32(0, 0X28);
L_800A8AE8:
    // 0x800A8AE8: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800A8AEC: nop

    // 0x800A8AF0: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x800A8AF4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800A8AF8: nop

    // 0x800A8AFC: beq         $t4, $zero, L_800A8C1C
    if (ctx->r12 == 0) {
        // 0x800A8B00: nop
    
            goto L_800A8C1C;
    }
    // 0x800A8B00: nop

    // 0x800A8B04: beq         $v1, $s2, L_800A8C1C
    if (ctx->r3 == ctx->r18) {
        // 0x800A8B08: nop
    
            goto L_800A8C1C;
    }
    // 0x800A8B08: nop

    // 0x800A8B0C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800A8B10: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A8B14: addu        $v0, $t5, $v1
    ctx->r2 = ADD32(ctx->r13, ctx->r3);
    // 0x800A8B18: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800A8B1C: nop

    // 0x800A8B20: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A8B24: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x800A8B28: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800A8B2C: nop

    // 0x800A8B30: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800A8B34: lbu         $t2, 0x0($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X0);
    // 0x800A8B38: nop

    // 0x800A8B3C: slti        $at, $t2, 0x3D
    ctx->r1 = SIGNED(ctx->r10) < 0X3D ? 1 : 0;
    // 0x800A8B40: bne         $at, $zero, L_800A8C1C
    if (ctx->r1 != 0) {
        // 0x800A8B44: nop
    
            goto L_800A8C1C;
    }
    // 0x800A8B44: nop

    // 0x800A8B48: lw          $t3, 0x72B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X72B0);
    // 0x800A8B4C: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x800A8B50: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800A8B54: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x800A8B58: nop

    // 0x800A8B5C: andi        $t6, $v0, 0xC000
    ctx->r14 = ctx->r2 & 0XC000;
    // 0x800A8B60: bne         $s3, $t6, L_800A8B8C
    if (ctx->r19 != ctx->r14) {
        // 0x800A8B64: andi        $t9, $v0, 0x8000
        ctx->r25 = ctx->r2 & 0X8000;
            goto L_800A8B8C;
    }
    // 0x800A8B64: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x800A8B68: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A8B6C: nop

    // 0x800A8B70: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800A8B74: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800A8B78: jal         0x8007B70C
    // 0x800A8B7C: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    tex_free(rdram, ctx);
        goto after_1;
    // 0x800A8B7C: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    after_1:
    // 0x800A8B80: lw          $v1, 0x144($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X144);
    // 0x800A8B84: b           L_800A8C04
    // 0x800A8B88: nop

        goto L_800A8C04;
    // 0x800A8B88: nop

L_800A8B8C:
    // 0x800A8B8C: beq         $t9, $zero, L_800A8BB8
    if (ctx->r25 == 0) {
        // 0x800A8B90: andi        $t4, $v0, 0x4000
        ctx->r12 = ctx->r2 & 0X4000;
            goto L_800A8BB8;
    }
    // 0x800A8B90: andi        $t4, $v0, 0x4000
    ctx->r12 = ctx->r2 & 0X4000;
    // 0x800A8B94: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800A8B98: nop

    // 0x800A8B9C: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x800A8BA0: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800A8BA4: jal         0x8007D100
    // 0x800A8BA8: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    sprite_free(rdram, ctx);
        goto after_2;
    // 0x800A8BA8: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    after_2:
    // 0x800A8BAC: lw          $v1, 0x144($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X144);
    // 0x800A8BB0: b           L_800A8C04
    // 0x800A8BB4: nop

        goto L_800A8C04;
    // 0x800A8BB4: nop

L_800A8BB8:
    // 0x800A8BB8: beq         $t4, $zero, L_800A8BE4
    if (ctx->r12 == 0) {
        // 0x800A8BBC: nop
    
            goto L_800A8BE4;
    }
    // 0x800A8BBC: nop

    // 0x800A8BC0: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800A8BC4: nop

    // 0x800A8BC8: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800A8BCC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x800A8BD0: jal         0x8000FFB8
    // 0x800A8BD4: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    free_object(rdram, ctx);
        goto after_3;
    // 0x800A8BD4: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    after_3:
    // 0x800A8BD8: lw          $v1, 0x144($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X144);
    // 0x800A8BDC: b           L_800A8C04
    // 0x800A8BE0: nop

        goto L_800A8C04;
    // 0x800A8BE0: nop

L_800A8BE4:
    // 0x800A8BE4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A8BE8: nop

    // 0x800A8BEC: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800A8BF0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800A8BF4: jal         0x80060180
    // 0x800A8BF8: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    free_3d_model(rdram, ctx);
        goto after_4;
    // 0x800A8BF8: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    after_4:
    // 0x800A8BFC: lw          $v1, 0x144($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X144);
    // 0x800A8C00: nop

L_800A8C04:
    // 0x800A8C04: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A8C08: lw          $t9, 0x72B4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72B4);
    // 0x800A8C0C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8C10: addu        $t2, $t9, $s1
    ctx->r10 = ADD32(ctx->r25, ctx->r17);
    // 0x800A8C14: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x800A8C18: addiu       $a1, $a1, 0x72B4
    ctx->r5 = ADD32(ctx->r5, 0X72B4);
L_800A8C1C:
    // 0x800A8C1C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A8C20: lw          $t3, 0x72B8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X72B8);
    // 0x800A8C24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A8C28: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800A8C2C: bne         $at, $zero, L_800A8AE8
    if (ctx->r1 != 0) {
        // 0x800A8C30: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800A8AE8;
    }
    // 0x800A8C30: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800A8C34:
    // 0x800A8C34: jal         0x8006BFF0
    // 0x800A8C38: nop

    level_header(rdram, ctx);
        goto after_5;
    // 0x800A8C38: nop

    after_5:
    // 0x800A8C3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8C40: sw          $v0, 0x7320($at)
    MEM_W(0X7320, ctx->r1) = ctx->r2;
    // 0x800A8C44: jal         0x8001BAC4
    // 0x800A8C48: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    get_racer_objects_by_port(rdram, ctx);
        goto after_6;
    // 0x800A8C48: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    after_6:
    // 0x800A8C4C: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x800A8C50: sw          $v0, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r2;
    // 0x800A8C54: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800A8C58: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A8C5C: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x800A8C60: addiu       $s4, $s4, 0x72BC
    ctx->r20 = ADD32(ctx->r20, 0X72BC);
    // 0x800A8C64: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800A8C68: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800A8C6C: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x800A8C70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8C74: sw          $t7, 0x72C0($at)
    MEM_W(0X72C0, ctx->r1) = ctx->r15;
    // 0x800A8C78: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800A8C7C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A8C80: lw          $t2, 0x7320($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7320);
    // 0x800A8C84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8C88: sw          $t9, 0x72C4($at)
    MEM_W(0X72C4, ctx->r1) = ctx->r25;
    // 0x800A8C8C: lb          $v1, 0x4C($t2)
    ctx->r3 = MEM_B(ctx->r10, 0X4C);
    // 0x800A8C90: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x800A8C94: bne         $v1, $at, L_800A8FE8
    if (ctx->r3 != ctx->r1) {
        // 0x800A8C98: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800A8FE8;
    }
    // 0x800A8C98: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A8C9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A8CA0: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A8CA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A8CA8: bne         $v1, $at, L_800A8CE4
    if (ctx->r3 != ctx->r1) {
        // 0x800A8CAC: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800A8CE4;
    }
    // 0x800A8CAC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A8CB0: lw          $t3, 0x72CC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X72CC);
    // 0x800A8CB4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800A8CB8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800A8CBC: lb          $t4, 0x2D24($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X2D24);
    // 0x800A8CC0: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x800A8CC4: bne         $t4, $zero, L_800A8CE8
    if (ctx->r12 != 0) {
        // 0x800A8CC8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A8CE8;
    }
    // 0x800A8CC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A8CCC: jal         0x800A1A30
    // 0x800A8CD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    hud_draw_eggs(rdram, ctx);
        goto after_7;
    // 0x800A8CD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800A8CD4: jal         0x8007B820
    // 0x800A8CD8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    rendermode_reset(rdram, ctx);
        goto after_8;
    // 0x800A8CD8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_8:
    // 0x800A8CDC: b           L_800A9C10
    // 0x800A8CE0: nop

        goto L_800A9C10;
    // 0x800A8CE0: nop

L_800A8CE4:
    // 0x800A8CE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800A8CE8:
    // 0x800A8CE8: bne         $v1, $at, L_800A8FDC
    if (ctx->r3 != ctx->r1) {
        // 0x800A8CEC: nop
    
            goto L_800A8FDC;
    }
    // 0x800A8CEC: nop

    // 0x800A8CF0: lw          $t5, 0x140($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X140);
    // 0x800A8CF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A8CF8: blez        $t5, L_800A8E04
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800A8CFC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800A8E04;
    }
    // 0x800A8CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A8D00: andi        $t0, $t5, 0x3
    ctx->r8 = ctx->r13 & 0X3;
    // 0x800A8D04: beq         $t0, $zero, L_800A8D54
    if (ctx->r8 == 0) {
        // 0x800A8D08: or          $a3, $t0, $zero
        ctx->r7 = ctx->r8 | 0;
            goto L_800A8D54;
    }
    // 0x800A8D08: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x800A8D0C: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x800A8D10: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x800A8D14: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A8D18:
    // 0x800A8D18: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800A8D1C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A8D20: lw          $v1, 0x64($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X64);
    // 0x800A8D24: nop

    // 0x800A8D28: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800A8D2C: nop

    // 0x800A8D30: bne         $s3, $t8, L_800A8D3C
    if (ctx->r19 != ctx->r24) {
        // 0x800A8D34: nop
    
            goto L_800A8D3C;
    }
    // 0x800A8D34: nop

    // 0x800A8D38: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A8D3C:
    // 0x800A8D3C: bne         $a3, $a1, L_800A8D18
    if (ctx->r7 != ctx->r5) {
        // 0x800A8D40: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A8D18;
    }
    // 0x800A8D40: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A8D44: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x800A8D48: nop

    // 0x800A8D4C: beq         $a1, $t9, L_800A8E04
    if (ctx->r5 == ctx->r25) {
        // 0x800A8D50: nop
    
            goto L_800A8E04;
    }
    // 0x800A8D50: nop

L_800A8D54:
    // 0x800A8D54: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x800A8D58: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x800A8D5C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800A8D60: addu        $a3, $t3, $v0
    ctx->r7 = ADD32(ctx->r11, ctx->r2);
    // 0x800A8D64: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    // 0x800A8D68: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A8D6C:
    // 0x800A8D6C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800A8D70: nop

    // 0x800A8D74: lw          $v1, 0x64($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X64);
    // 0x800A8D78: nop

    // 0x800A8D7C: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800A8D80: nop

    // 0x800A8D84: bne         $s3, $t6, L_800A8D90
    if (ctx->r19 != ctx->r14) {
        // 0x800A8D88: nop
    
            goto L_800A8D90;
    }
    // 0x800A8D88: nop

    // 0x800A8D8C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A8D90:
    // 0x800A8D90: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800A8D94: nop

    // 0x800A8D98: lw          $v1, 0x64($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X64);
    // 0x800A8D9C: nop

    // 0x800A8DA0: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800A8DA4: nop

    // 0x800A8DA8: bne         $s3, $t8, L_800A8DB4
    if (ctx->r19 != ctx->r24) {
        // 0x800A8DAC: nop
    
            goto L_800A8DB4;
    }
    // 0x800A8DAC: nop

    // 0x800A8DB0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A8DB4:
    // 0x800A8DB4: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800A8DB8: nop

    // 0x800A8DBC: lw          $v1, 0x64($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X64);
    // 0x800A8DC0: nop

    // 0x800A8DC4: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800A8DC8: nop

    // 0x800A8DCC: bne         $s3, $t2, L_800A8DD8
    if (ctx->r19 != ctx->r10) {
        // 0x800A8DD0: nop
    
            goto L_800A8DD8;
    }
    // 0x800A8DD0: nop

    // 0x800A8DD4: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A8DD8:
    // 0x800A8DD8: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x800A8DDC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800A8DE0: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x800A8DE4: nop

    // 0x800A8DE8: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x800A8DEC: nop

    // 0x800A8DF0: bne         $s3, $t4, L_800A8DFC
    if (ctx->r19 != ctx->r12) {
        // 0x800A8DF4: nop
    
            goto L_800A8DFC;
    }
    // 0x800A8DF4: nop

    // 0x800A8DF8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A8DFC:
    // 0x800A8DFC: bne         $a0, $a3, L_800A8D6C
    if (ctx->r4 != ctx->r7) {
        // 0x800A8E00: nop
    
            goto L_800A8D6C;
    }
    // 0x800A8E00: nop

L_800A8E04:
    // 0x800A8E04: beq         $a2, $zero, L_800A8FDC
    if (ctx->r6 == 0) {
        // 0x800A8E08: lui         $s2, 0x8012
        ctx->r18 = S32(0X8012 << 16);
            goto L_800A8FDC;
    }
    // 0x800A8E08: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A8E0C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A8E10: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
    // 0x800A8E14: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8E18: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A8E1C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8E20: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8E24: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A8E28: lwc1        $f16, 0x650($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A8E2C: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A8E30: lwc1        $f6, 0x66C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A8E34: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A8E38: lwc1        $f18, 0x670($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X670);
    // 0x800A8E3C: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
    // 0x800A8E40: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A8E44: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A8E48: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A8E4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8E50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8E54: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800A8E58: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A8E5C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A8E60: mfc1        $s1, $f4
    ctx->r17 = (int32_t)ctx->f4.u32l;
    // 0x800A8E64: nop

    // 0x800A8E68: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A8E6C: nop

    // 0x800A8E70: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A8E74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8E78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8E7C: nop

    // 0x800A8E80: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A8E84: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A8E88: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A8E8C: nop

    // 0x800A8E90: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A8E94: nop

    // 0x800A8E98: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A8E9C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8EA0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8EA4: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x800A8EA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A8EAC: lui         $at, 0x435D
    ctx->r1 = S32(0X435D << 16);
    // 0x800A8EB0: swc1        $f16, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f16.u32l;
    // 0x800A8EB4: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A8EB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A8EBC: lui         $at, 0x4345
    ctx->r1 = S32(0X4345 << 16);
    // 0x800A8EC0: swc1        $f4, 0x66C($t9)
    MEM_W(0X66C, ctx->r25) = ctx->f4.u32l;
    // 0x800A8EC4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A8EC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A8ECC: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x800A8ED0: swc1        $f6, 0x670($t2)
    MEM_W(0X670, ctx->r10) = ctx->f6.u32l;
    // 0x800A8ED4: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A8ED8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A8EDC: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A8EE0: swc1        $f10, 0x650($t3)
    MEM_W(0X650, ctx->r11) = ctx->f10.u32l;
    // 0x800A8EE4: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x800A8EE8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800A8EEC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A8EF0: bne         $t4, $zero, L_800A8F74
    if (ctx->r12 != 0) {
        // 0x800A8EF4: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_800A8F74;
    }
    // 0x800A8EF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A8EF8: lwc1        $f1, -0x72E0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X72E0);
    // 0x800A8EFC: lwc1        $f0, -0x72DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72DC);
    // 0x800A8F00: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8F04: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A8F08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A8F0C: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A8F10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A8F14: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800A8F18: swc1        $f16, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f16.u32l;
    // 0x800A8F1C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8F20: nop

    // 0x800A8F24: lwc1        $f4, 0x66C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A8F28: nop

    // 0x800A8F2C: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A8F30: swc1        $f10, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f10.u32l;
    // 0x800A8F34: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8F38: nop

    // 0x800A8F3C: lwc1        $f18, 0x650($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A8F40: nop

    // 0x800A8F44: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800A8F48: mul.d       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800A8F4C: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x800A8F50: swc1        $f4, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f4.u32l;
    // 0x800A8F54: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8F58: nop

    // 0x800A8F5C: lwc1        $f6, 0x670($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X670);
    // 0x800A8F60: nop

    // 0x800A8F64: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800A8F68: mul.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x800A8F6C: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x800A8F70: swc1        $f8, 0x670($v0)
    MEM_W(0X670, ctx->r2) = ctx->f8.u32l;
L_800A8F74:
    // 0x800A8F74: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x800A8F78: sw          $v1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r3;
    // 0x800A8F7C: jal         0x800A1EE4
    // 0x800A8F80: sw          $a3, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r7;
    hud_eggs_portrait(rdram, ctx);
        goto after_9;
    // 0x800A8F80: sw          $a3, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r7;
    after_9:
    // 0x800A8F84: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x800A8F88: addiu       $t5, $zero, -0x2
    ctx->r13 = ADD32(0, -0X2);
    // 0x800A8F8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A8F90: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A8F94: sw          $t5, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = ctx->r13;
    // 0x800A8F98: lw          $v1, 0xF4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XF4);
    // 0x800A8F9C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800A8FA0: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x800A8FA4: lw          $a3, 0xF0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF0);
    // 0x800A8FA8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A8FAC: swc1        $f4, 0x64C($t6)
    MEM_W(0X64C, ctx->r14) = ctx->f4.u32l;
    // 0x800A8FB0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800A8FB4: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x800A8FB8: swc1        $f10, 0x650($t7)
    MEM_W(0X650, ctx->r15) = ctx->f10.u32l;
    // 0x800A8FBC: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A8FC0: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A8FC4: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800A8FC8: swc1        $f8, 0x66C($t8)
    MEM_W(0X66C, ctx->r24) = ctx->f8.u32l;
    // 0x800A8FCC: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A8FD0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A8FD4: nop

    // 0x800A8FD8: swc1        $f4, 0x670($t9)
    MEM_W(0X670, ctx->r25) = ctx->f4.u32l;
L_800A8FDC:
    // 0x800A8FDC: b           L_800A9C10
    // 0x800A8FE0: nop

        goto L_800A9C10;
    // 0x800A8FE0: nop

    // 0x800A8FE4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
L_800A8FE8:
    // 0x800A8FE8: bne         $v1, $at, L_800A96B4
    if (ctx->r3 != ctx->r1) {
        // 0x800A8FEC: addiu       $at, $zero, 0x41
        ctx->r1 = ADD32(0, 0X41);
            goto L_800A96B4;
    }
    // 0x800A8FEC: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800A8FF0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A8FF4: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A8FF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A8FFC: bne         $v1, $at, L_800A906C
    if (ctx->r3 != ctx->r1) {
        // 0x800A9000: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800A906C;
    }
    // 0x800A9000: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A9004: lw          $t2, 0x72CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72CC);
    // 0x800A9008: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800A900C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800A9010: lb          $t3, 0x2D24($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X2D24);
    // 0x800A9014: nop

    // 0x800A9018: bne         $t3, $zero, L_800A9070
    if (ctx->r11 != 0) {
        // 0x800A901C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A9070;
    }
    // 0x800A901C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A9020: jal         0x80068748
    // 0x800A9024: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_10;
    // 0x800A9024: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x800A9028: jal         0x8007C36C
    // 0x800A902C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_11;
    // 0x800A902C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x800A9030: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A9034: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A9038: jal         0x8006816C
    // 0x800A903C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mtx_ortho(rdram, ctx);
        goto after_12;
    // 0x800A903C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_12:
    // 0x800A9040: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x800A9044: jal         0x800A2388
    // 0x800A9048: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    hud_battle_portraits(rdram, ctx);
        goto after_13;
    // 0x800A9048: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x800A904C: jal         0x80068748
    // 0x800A9050: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_14;
    // 0x800A9050: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x800A9054: jal         0x8007B820
    // 0x800A9058: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    rendermode_reset(rdram, ctx);
        goto after_15;
    // 0x800A9058: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_15:
    // 0x800A905C: jal         0x8007C36C
    // 0x800A9060: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_16;
    // 0x800A9060: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x800A9064: b           L_800A9C10
    // 0x800A9068: nop

        goto L_800A9C10;
    // 0x800A9068: nop

L_800A906C:
    // 0x800A906C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800A9070:
    // 0x800A9070: bne         $v1, $at, L_800A96A8
    if (ctx->r3 != ctx->r1) {
        // 0x800A9074: nop
    
            goto L_800A96A8;
    }
    // 0x800A9074: nop

    // 0x800A9078: lw          $t4, 0x140($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X140);
    // 0x800A907C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A9080: blez        $t4, L_800A918C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800A9084: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800A918C;
    }
    // 0x800A9084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A9088: andi        $t0, $t4, 0x3
    ctx->r8 = ctx->r12 & 0X3;
    // 0x800A908C: beq         $t0, $zero, L_800A90DC
    if (ctx->r8 == 0) {
        // 0x800A9090: or          $a2, $t0, $zero
        ctx->r6 = ctx->r8 | 0;
            goto L_800A90DC;
    }
    // 0x800A9090: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800A9094: sll         $t5, $zero, 2
    ctx->r13 = S32(0 << 2);
    // 0x800A9098: addu        $a0, $v0, $t5
    ctx->r4 = ADD32(ctx->r2, ctx->r13);
    // 0x800A909C: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A90A0:
    // 0x800A90A0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A90A4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A90A8: lw          $v1, 0x64($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X64);
    // 0x800A90AC: nop

    // 0x800A90B0: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800A90B4: nop

    // 0x800A90B8: bne         $s3, $t7, L_800A90C4
    if (ctx->r19 != ctx->r15) {
        // 0x800A90BC: nop
    
            goto L_800A90C4;
    }
    // 0x800A90BC: nop

    // 0x800A90C0: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800A90C4:
    // 0x800A90C4: bne         $a2, $a1, L_800A90A0
    if (ctx->r6 != ctx->r5) {
        // 0x800A90C8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A90A0;
    }
    // 0x800A90C8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A90CC: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x800A90D0: nop

    // 0x800A90D4: beq         $a1, $t8, L_800A918C
    if (ctx->r5 == ctx->r24) {
        // 0x800A90D8: nop
    
            goto L_800A918C;
    }
    // 0x800A90D8: nop

L_800A90DC:
    // 0x800A90DC: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x800A90E0: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x800A90E4: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800A90E8: addu        $a2, $t2, $v0
    ctx->r6 = ADD32(ctx->r10, ctx->r2);
    // 0x800A90EC: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x800A90F0: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A90F4:
    // 0x800A90F4: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800A90F8: nop

    // 0x800A90FC: lw          $v1, 0x64($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X64);
    // 0x800A9100: nop

    // 0x800A9104: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x800A9108: nop

    // 0x800A910C: bne         $s3, $t5, L_800A9118
    if (ctx->r19 != ctx->r13) {
        // 0x800A9110: nop
    
            goto L_800A9118;
    }
    // 0x800A9110: nop

    // 0x800A9114: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800A9118:
    // 0x800A9118: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800A911C: nop

    // 0x800A9120: lw          $v1, 0x64($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X64);
    // 0x800A9124: nop

    // 0x800A9128: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800A912C: nop

    // 0x800A9130: bne         $s3, $t7, L_800A913C
    if (ctx->r19 != ctx->r15) {
        // 0x800A9134: nop
    
            goto L_800A913C;
    }
    // 0x800A9134: nop

    // 0x800A9138: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800A913C:
    // 0x800A913C: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800A9140: nop

    // 0x800A9144: lw          $v1, 0x64($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X64);
    // 0x800A9148: nop

    // 0x800A914C: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x800A9150: nop

    // 0x800A9154: bne         $s3, $t9, L_800A9160
    if (ctx->r19 != ctx->r25) {
        // 0x800A9158: nop
    
            goto L_800A9160;
    }
    // 0x800A9158: nop

    // 0x800A915C: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800A9160:
    // 0x800A9160: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x800A9164: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800A9168: lw          $v1, 0x64($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X64);
    // 0x800A916C: nop

    // 0x800A9170: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x800A9174: nop

    // 0x800A9178: bne         $s3, $t3, L_800A9184
    if (ctx->r19 != ctx->r11) {
        // 0x800A917C: nop
    
            goto L_800A9184;
    }
    // 0x800A917C: nop

    // 0x800A9180: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800A9184:
    // 0x800A9184: bne         $a0, $a2, L_800A90F4
    if (ctx->r4 != ctx->r6) {
        // 0x800A9188: nop
    
            goto L_800A90F4;
    }
    // 0x800A9188: nop

L_800A918C:
    // 0x800A918C: beq         $s0, $zero, L_800A96A8
    if (ctx->r16 == 0) {
        // 0x800A9190: lui         $s2, 0x8012
        ctx->r18 = S32(0X8012 << 16);
            goto L_800A96A8;
    }
    // 0x800A9190: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A9194: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A9198: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A919C: lw          $t4, 0x72AC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72AC);
    // 0x800A91A0: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
    // 0x800A91A4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A91A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A91AC: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x800A91B0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A91B4: lwc1        $f6, 0x64C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X64C);
    // 0x800A91B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A91BC: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A91C0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A91C4: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800A91C8: nop

    // 0x800A91CC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A91D0: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x800A91D4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A91D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A91DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A91E0: lwc1        $f18, 0x650($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X650);
    // 0x800A91E4: nop

    // 0x800A91E8: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A91EC: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800A91F0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A91F4: jal         0x8007C36C
    // 0x800A91F8: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    sprite_opaque(rdram, ctx);
        goto after_17;
    // 0x800A91F8: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    after_17:
    // 0x800A91FC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A9200: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A9204: jal         0x8006816C
    // 0x800A9208: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mtx_ortho(rdram, ctx);
        goto after_18;
    // 0x800A9208: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_18:
    // 0x800A920C: jal         0x80068748
    // 0x800A9210: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_19;
    // 0x800A9210: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x800A9214: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x800A9218: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A921C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A9220: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800A9224: swc1        $f16, 0x64C($t9)
    MEM_W(0X64C, ctx->r25) = ctx->f16.u32l;
    // 0x800A9228: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x800A922C: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x800A9230: bne         $t2, $zero, L_800A924C
    if (ctx->r10 != 0) {
        // 0x800A9234: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_800A924C;
    }
    // 0x800A9234: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A9238: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A923C: lwc1        $f4, -0x72D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X72D8);
    // 0x800A9240: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A9244: b           L_800A9260
    // 0x800A9248: swc1        $f4, 0x650($t3)
    MEM_W(0X650, ctx->r11) = ctx->f4.u32l;
        goto L_800A9260;
    // 0x800A9248: swc1        $f4, 0x650($t3)
    MEM_W(0X650, ctx->r11) = ctx->f4.u32l;
L_800A924C:
    // 0x800A924C: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x800A9250: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A9254: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800A9258: nop

    // 0x800A925C: swc1        $f6, 0x650($t4)
    MEM_W(0X650, ctx->r12) = ctx->f6.u32l;
L_800A9260:
    // 0x800A9260: lw          $t5, 0x300($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X300);
    // 0x800A9264: addiu       $s1, $s1, 0x7295
    ctx->r17 = ADD32(ctx->r17, 0X7295);
    // 0x800A9268: bne         $t5, $zero, L_800A92EC
    if (ctx->r13 != 0) {
        // 0x800A926C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A92EC;
    }
    // 0x800A926C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A9270: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9274: lui         $at, 0x4284
    ctx->r1 = S32(0X4284 << 16);
    // 0x800A9278: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A927C: lwc1        $f12, 0x36C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X36C);
    // 0x800A9280: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A9284: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A9288: sub.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800A928C: lwc1        $f10, 0x370($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X370);
    // 0x800A9290: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800A9294: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A9298: nop

    // 0x800A929C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A92A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A92A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A92A8: lui         $at, 0xC2E4
    ctx->r1 = S32(0XC2E4 << 16);
    // 0x800A92AC: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A92B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A92B4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A92B8: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800A92BC: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800A92C0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A92C4: nop

    // 0x800A92C8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A92CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A92D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A92D4: nop

    // 0x800A92D8: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A92DC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800A92E0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A92E4: b           L_800A935C
    // 0x800A92E8: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
        goto L_800A935C;
    // 0x800A92E8: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
L_800A92EC:
    // 0x800A92EC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A92F0: lui         $at, 0x4284
    ctx->r1 = S32(0X4284 << 16);
    // 0x800A92F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A92F8: lwc1        $f12, 0x36C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X36C);
    // 0x800A92FC: lwc1        $f18, 0x370($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X370);
    // 0x800A9300: sub.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x800A9304: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A9308: nop

    // 0x800A930C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A9310: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9314: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9318: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x800A931C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9320: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A9324: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A9328: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800A932C: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800A9330: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A9334: nop

    // 0x800A9338: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A933C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9340: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9344: nop

    // 0x800A9348: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A934C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A9350: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800A9354: nop

    // 0x800A9358: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
L_800A935C:
    // 0x800A935C: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800A9360: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A9364: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x800A9368: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800A936C: add.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800A9370: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A9374: swc1        $f6, 0x36C($v0)
    MEM_W(0X36C, ctx->r2) = ctx->f6.u32l;
    // 0x800A9378: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A937C: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A9380: lwc1        $f18, 0x370($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X370);
    // 0x800A9384: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A9388: add.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800A938C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A9390: swc1        $f8, 0x370($v0)
    MEM_W(0X370, ctx->r2) = ctx->f8.u32l;
    // 0x800A9394: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9398: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A939C: lwc1        $f16, 0xEC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XEC);
    // 0x800A93A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A93A4: add.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A93A8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A93AC: swc1        $f4, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->f4.u32l;
    // 0x800A93B0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A93B4: nop

    // 0x800A93B8: lwc1        $f6, 0xF0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XF0);
    // 0x800A93BC: nop

    // 0x800A93C0: add.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800A93C4: swc1        $f10, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->f10.u32l;
    // 0x800A93C8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A93CC: nop

    // 0x800A93D0: lwc1        $f18, 0x38C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X38C);
    // 0x800A93D4: nop

    // 0x800A93D8: add.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x800A93DC: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800A93E0: swc1        $f8, 0x38C($v0)
    MEM_W(0X38C, ctx->r2) = ctx->f8.u32l;
    // 0x800A93E4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A93E8: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A93EC: lwc1        $f16, 0x390($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X390);
    // 0x800A93F0: nop

    // 0x800A93F4: add.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A93F8: swc1        $f4, 0x390($v0)
    MEM_W(0X390, ctx->r2) = ctx->f4.u32l;
    // 0x800A93FC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9400: nop

    // 0x800A9404: lwc1        $f6, 0x10C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10C);
    // 0x800A9408: nop

    // 0x800A940C: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A9410: swc1        $f10, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->f10.u32l;
    // 0x800A9414: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9418: nop

    // 0x800A941C: lwc1        $f8, 0x110($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X110);
    // 0x800A9420: nop

    // 0x800A9424: sub.s       $f16, $f8, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800A9428: swc1        $f16, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->f16.u32l;
    // 0x800A942C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9430: nop

    // 0x800A9434: lwc1        $f4, 0x12C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X12C);
    // 0x800A9438: nop

    // 0x800A943C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A9440: swc1        $f6, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->f6.u32l;
    // 0x800A9444: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9448: nop

    // 0x800A944C: lwc1        $f10, 0x130($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X130);
    // 0x800A9450: nop

    // 0x800A9454: sub.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x800A9458: swc1        $f18, 0x130($v0)
    MEM_W(0X130, ctx->r2) = ctx->f18.u32l;
    // 0x800A945C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9460: nop

    // 0x800A9464: lwc1        $f8, 0x24C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24C);
    // 0x800A9468: nop

    // 0x800A946C: add.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A9470: swc1        $f16, 0x24C($v0)
    MEM_W(0X24C, ctx->r2) = ctx->f16.u32l;
    // 0x800A9474: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9478: nop

    // 0x800A947C: lwc1        $f4, 0x250($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X250);
    // 0x800A9480: nop

    // 0x800A9484: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A9488: swc1        $f6, 0x250($v0)
    MEM_W(0X250, ctx->r2) = ctx->f6.u32l;
    // 0x800A948C: lb          $t3, 0x3($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X3);
    // 0x800A9490: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800A9494: addiu       $t4, $t3, 0x38
    ctx->r12 = ADD32(ctx->r11, 0X38);
    // 0x800A9498: sh          $t4, 0x646($t5)
    MEM_H(0X646, ctx->r13) = ctx->r12;
    // 0x800A949C: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800A94A0: nop

    // 0x800A94A4: bne         $t6, $zero, L_800A94DC
    if (ctx->r14 != 0) {
        // 0x800A94A8: nop
    
            goto L_800A94DC;
    }
    // 0x800A94A8: nop

    // 0x800A94AC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A94B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A94B4: lwc1        $f10, 0x64C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A94B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A94BC: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800A94C0: swc1        $f8, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f8.u32l;
    // 0x800A94C4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A94C8: nop

    // 0x800A94CC: lwc1        $f16, 0x66C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A94D0: nop

    // 0x800A94D4: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800A94D8: swc1        $f6, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f6.u32l;
L_800A94DC:
    // 0x800A94DC: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A94E0: sb          $t7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r15;
    // 0x800A94E4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800A94E8: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800A94EC: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x800A94F0: jal         0x800AAB5C
    // 0x800A94F4: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    hud_element_render(rdram, ctx);
        goto after_20;
    // 0x800A94F4: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    after_20:
    // 0x800A94F8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A94FC: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x800A9500: lb          $t8, 0xFB($v0)
    ctx->r24 = MEM_B(ctx->r2, 0XFB);
    // 0x800A9504: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800A9508: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A950C: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A9510: bne         $t8, $zero, L_800A952C
    if (ctx->r24 != 0) {
        // 0x800A9514: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A952C;
    }
    // 0x800A9514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A9518: lb          $v1, 0x185($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X185);
    // 0x800A951C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A9520: bne         $v1, $at, L_800A9530
    if (ctx->r3 != ctx->r1) {
        // 0x800A9524: lw          $a1, 0x16C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X16C);
            goto L_800A9530;
    }
    // 0x800A9524: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x800A9528: sb          $v1, 0xFB($v0)
    MEM_B(0XFB, ctx->r2) = ctx->r3;
L_800A952C:
    // 0x800A952C: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
L_800A9530:
    // 0x800A9530: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800A9534: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800A9538: jal         0x800A469C
    // 0x800A953C: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    hud_bananas(rdram, ctx);
        goto after_21;
    // 0x800A953C: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    after_21:
    // 0x800A9540: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9544: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800A9548: lwc1        $f10, 0x36C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X36C);
    // 0x800A954C: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A9550: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800A9554: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A9558: swc1        $f18, 0x36C($v0)
    MEM_W(0X36C, ctx->r2) = ctx->f18.u32l;
    // 0x800A955C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9560: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A9564: lwc1        $f8, 0x370($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X370);
    // 0x800A9568: nop

    // 0x800A956C: sub.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800A9570: swc1        $f16, 0x370($v0)
    MEM_W(0X370, ctx->r2) = ctx->f16.u32l;
    // 0x800A9574: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9578: nop

    // 0x800A957C: lwc1        $f4, 0xEC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XEC);
    // 0x800A9580: nop

    // 0x800A9584: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A9588: swc1        $f6, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->f6.u32l;
    // 0x800A958C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9590: nop

    // 0x800A9594: lwc1        $f10, 0xF0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XF0);
    // 0x800A9598: nop

    // 0x800A959C: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800A95A0: swc1        $f18, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->f18.u32l;
    // 0x800A95A4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A95A8: nop

    // 0x800A95AC: lwc1        $f8, 0x38C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38C);
    // 0x800A95B0: nop

    // 0x800A95B4: sub.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A95B8: swc1        $f16, 0x38C($v0)
    MEM_W(0X38C, ctx->r2) = ctx->f16.u32l;
    // 0x800A95BC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A95C0: nop

    // 0x800A95C4: lwc1        $f4, 0x390($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X390);
    // 0x800A95C8: nop

    // 0x800A95CC: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A95D0: swc1        $f6, 0x390($v0)
    MEM_W(0X390, ctx->r2) = ctx->f6.u32l;
    // 0x800A95D4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A95D8: nop

    // 0x800A95DC: lwc1        $f10, 0x10C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10C);
    // 0x800A95E0: nop

    // 0x800A95E4: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800A95E8: swc1        $f18, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->f18.u32l;
    // 0x800A95EC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A95F0: nop

    // 0x800A95F4: lwc1        $f8, 0x110($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X110);
    // 0x800A95F8: nop

    // 0x800A95FC: add.s       $f16, $f8, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x800A9600: swc1        $f16, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->f16.u32l;
    // 0x800A9604: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9608: nop

    // 0x800A960C: lwc1        $f4, 0x12C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X12C);
    // 0x800A9610: nop

    // 0x800A9614: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A9618: swc1        $f6, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->f6.u32l;
    // 0x800A961C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9620: nop

    // 0x800A9624: lwc1        $f10, 0x130($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X130);
    // 0x800A9628: nop

    // 0x800A962C: add.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x800A9630: swc1        $f18, 0x130($v0)
    MEM_W(0X130, ctx->r2) = ctx->f18.u32l;
    // 0x800A9634: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9638: nop

    // 0x800A963C: lwc1        $f8, 0x24C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24C);
    // 0x800A9640: nop

    // 0x800A9644: sub.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A9648: swc1        $f16, 0x24C($v0)
    MEM_W(0X24C, ctx->r2) = ctx->f16.u32l;
    // 0x800A964C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9650: nop

    // 0x800A9654: lwc1        $f4, 0x250($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X250);
    // 0x800A9658: nop

    // 0x800A965C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A9660: swc1        $f6, 0x250($v0)
    MEM_W(0X250, ctx->r2) = ctx->f6.u32l;
    // 0x800A9664: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x800A9668: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A966C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800A9670: nop

    // 0x800A9674: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A9678: swc1        $f18, 0x64C($t2)
    MEM_W(0X64C, ctx->r10) = ctx->f18.u32l;
    // 0x800A967C: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x800A9680: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800A9684: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800A9688: nop

    // 0x800A968C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9690: jal         0x8007C36C
    // 0x800A9694: swc1        $f16, 0x650($t4)
    MEM_W(0X650, ctx->r12) = ctx->f16.u32l;
    sprite_opaque(rdram, ctx);
        goto after_22;
    // 0x800A9694: swc1        $f16, 0x650($t4)
    MEM_W(0X650, ctx->r12) = ctx->f16.u32l;
    after_22:
    // 0x800A9698: jal         0x8007B820
    // 0x800A969C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    rendermode_reset(rdram, ctx);
        goto after_23;
    // 0x800A969C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_23:
    // 0x800A96A0: jal         0x80068748
    // 0x800A96A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_24;
    // 0x800A96A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_24:
L_800A96A8:
    // 0x800A96A8: b           L_800A9C10
    // 0x800A96AC: nop

        goto L_800A9C10;
    // 0x800A96AC: nop

    // 0x800A96B0: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
L_800A96B4:
    // 0x800A96B4: bne         $v1, $at, L_800A9C10
    if (ctx->r3 != ctx->r1) {
        // 0x800A96B8: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800A9C10;
    }
    // 0x800A96B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A96BC: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A96C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A96C4: bne         $v1, $at, L_800A98B8
    if (ctx->r3 != ctx->r1) {
        // 0x800A96C8: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800A98B8;
    }
    // 0x800A96C8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A96CC: lw          $t5, 0x72CC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72CC);
    // 0x800A96D0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A96D4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800A96D8: lb          $t6, 0x2D24($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X2D24);
    // 0x800A96DC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A96E0: bne         $t6, $zero, L_800A98B8
    if (ctx->r14 != 0) {
        // 0x800A96E4: addiu       $s2, $s2, 0x729C
        ctx->r18 = ADD32(ctx->r18, 0X729C);
            goto L_800A98B8;
    }
    // 0x800A96E4: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
    // 0x800A96E8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A96EC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A96F0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A96F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A96F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A96FC: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A9700: lwc1        $f10, 0x650($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A9704: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9708: lwc1        $f8, 0x40C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A970C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A9710: lwc1        $f4, 0x410($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A9714: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x800A9718: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A971C: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x800A9720: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A9724: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9728: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A972C: nop

    // 0x800A9730: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A9734: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A9738: mfc1        $s1, $f18
    ctx->r17 = (int32_t)ctx->f18.u32l;
    // 0x800A973C: nop

    // 0x800A9740: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A9744: nop

    // 0x800A9748: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A974C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9750: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9754: nop

    // 0x800A9758: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A975C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A9760: mfc1        $s3, $f16
    ctx->r19 = (int32_t)ctx->f16.u32l;
    // 0x800A9764: nop

    // 0x800A9768: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A976C: nop

    // 0x800A9770: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A9774: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9778: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A977C: nop

    // 0x800A9780: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9784: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800A9788: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A978C: jal         0x8001BAA8
    // 0x800A9790: sw          $t3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r11;
    get_racer_objects(rdram, ctx);
        goto after_25;
    // 0x800A9790: sw          $t3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r11;
    after_25:
    // 0x800A9794: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x800A9798: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A979C: blez        $t4, L_800A9868
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800A97A0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800A9868;
    }
    // 0x800A97A0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800A97A4:
    // 0x800A97A4: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800A97A8: nop

    // 0x800A97AC: lw          $a0, 0x64($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X64);
    // 0x800A97B0: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x800A97B4: jal         0x800A4B38
    // 0x800A97B8: sw          $v1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r3;
    hud_treasure(rdram, ctx);
        goto after_26;
    // 0x800A97B8: sw          $v1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r3;
    after_26:
    // 0x800A97BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A97C0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800A97C4: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800A97C8: lwc1        $f1, -0x72C8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X72C8);
    // 0x800A97CC: lwc1        $f0, -0x72C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72C4);
    // 0x800A97D0: lw          $v1, 0xD0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD0);
    // 0x800A97D4: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800A97D8: bne         $t6, $zero, L_800A9824
    if (ctx->r14 != 0) {
        // 0x800A97DC: lui         $at, 0x425C
        ctx->r1 = S32(0X425C << 16);
            goto L_800A9824;
    }
    // 0x800A97DC: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x800A97E0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A97E4: nop

    // 0x800A97E8: lwc1        $f10, 0x650($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A97EC: nop

    // 0x800A97F0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800A97F4: add.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f18.d + ctx->f0.d;
    // 0x800A97F8: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x800A97FC: swc1        $f16, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f16.u32l;
    // 0x800A9800: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9804: nop

    // 0x800A9808: lwc1        $f4, 0x410($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A980C: nop

    // 0x800A9810: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800A9814: add.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f6.d + ctx->f0.d;
    // 0x800A9818: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800A981C: b           L_800A9854
    // 0x800A9820: swc1        $f18, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f18.u32l;
        goto L_800A9854;
    // 0x800A9820: swc1        $f18, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f18.u32l;
L_800A9824:
    // 0x800A9824: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9828: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A982C: lwc1        $f8, 0x650($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A9830: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A9834: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800A9838: swc1        $f4, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f4.u32l;
    // 0x800A983C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9840: nop

    // 0x800A9844: lwc1        $f6, 0x410($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A9848: nop

    // 0x800A984C: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800A9850: swc1        $f18, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f18.u32l;
L_800A9854:
    // 0x800A9854: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800A9858: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A985C: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800A9860: bne         $at, $zero, L_800A97A4
    if (ctx->r1 != 0) {
        // 0x800A9864: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800A97A4;
    }
    // 0x800A9864: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_800A9868:
    // 0x800A9868: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x800A986C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A9870: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9874: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x800A9878: mtc1        $s3, $f10
    ctx->f10.u32l = ctx->r19;
    // 0x800A987C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A9880: swc1        $f16, 0x64C($t8)
    MEM_W(0X64C, ctx->r24) = ctx->f16.u32l;
    // 0x800A9884: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A9888: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A988C: swc1        $f6, 0x650($t9)
    MEM_W(0X650, ctx->r25) = ctx->f6.u32l;
    // 0x800A9890: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A9894: nop

    // 0x800A9898: swc1        $f18, 0x40C($t2)
    MEM_W(0X40C, ctx->r10) = ctx->f18.u32l;
    // 0x800A989C: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x800A98A0: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800A98A4: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800A98A8: nop

    // 0x800A98AC: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A98B0: b           L_800A9C10
    // 0x800A98B4: swc1        $f16, 0x410($t4)
    MEM_W(0X410, ctx->r12) = ctx->f16.u32l;
        goto L_800A9C10;
    // 0x800A98B4: swc1        $f16, 0x410($t4)
    MEM_W(0X410, ctx->r12) = ctx->f16.u32l;
L_800A98B8:
    // 0x800A98B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A98BC: bne         $v1, $at, L_800A9C10
    if (ctx->r3 != ctx->r1) {
        // 0x800A98C0: nop
    
            goto L_800A9C10;
    }
    // 0x800A98C0: nop

    // 0x800A98C4: lw          $t5, 0x140($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X140);
    // 0x800A98C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A98CC: blez        $t5, L_800A99D8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800A98D0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800A99D8;
    }
    // 0x800A98D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A98D4: andi        $t0, $t5, 0x3
    ctx->r8 = ctx->r13 & 0X3;
    // 0x800A98D8: beq         $t0, $zero, L_800A9928
    if (ctx->r8 == 0) {
        // 0x800A98DC: or          $a3, $t0, $zero
        ctx->r7 = ctx->r8 | 0;
            goto L_800A9928;
    }
    // 0x800A98DC: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x800A98E0: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x800A98E4: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x800A98E8: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A98EC:
    // 0x800A98EC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800A98F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A98F4: lw          $v1, 0x64($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X64);
    // 0x800A98F8: nop

    // 0x800A98FC: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800A9900: nop

    // 0x800A9904: bne         $s3, $t8, L_800A9910
    if (ctx->r19 != ctx->r24) {
        // 0x800A9908: nop
    
            goto L_800A9910;
    }
    // 0x800A9908: nop

    // 0x800A990C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A9910:
    // 0x800A9910: bne         $a3, $a1, L_800A98EC
    if (ctx->r7 != ctx->r5) {
        // 0x800A9914: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A98EC;
    }
    // 0x800A9914: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A9918: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x800A991C: nop

    // 0x800A9920: beq         $a1, $t9, L_800A99D8
    if (ctx->r5 == ctx->r25) {
        // 0x800A9924: nop
    
            goto L_800A99D8;
    }
    // 0x800A9924: nop

L_800A9928:
    // 0x800A9928: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x800A992C: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x800A9930: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800A9934: addu        $a3, $t3, $v0
    ctx->r7 = ADD32(ctx->r11, ctx->r2);
    // 0x800A9938: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    // 0x800A993C: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A9940:
    // 0x800A9940: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800A9944: nop

    // 0x800A9948: lw          $v1, 0x64($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X64);
    // 0x800A994C: nop

    // 0x800A9950: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800A9954: nop

    // 0x800A9958: bne         $s3, $t6, L_800A9964
    if (ctx->r19 != ctx->r14) {
        // 0x800A995C: nop
    
            goto L_800A9964;
    }
    // 0x800A995C: nop

    // 0x800A9960: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A9964:
    // 0x800A9964: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800A9968: nop

    // 0x800A996C: lw          $v1, 0x64($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X64);
    // 0x800A9970: nop

    // 0x800A9974: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800A9978: nop

    // 0x800A997C: bne         $s3, $t8, L_800A9988
    if (ctx->r19 != ctx->r24) {
        // 0x800A9980: nop
    
            goto L_800A9988;
    }
    // 0x800A9980: nop

    // 0x800A9984: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A9988:
    // 0x800A9988: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800A998C: nop

    // 0x800A9990: lw          $v1, 0x64($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X64);
    // 0x800A9994: nop

    // 0x800A9998: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800A999C: nop

    // 0x800A99A0: bne         $s3, $t2, L_800A99AC
    if (ctx->r19 != ctx->r10) {
        // 0x800A99A4: nop
    
            goto L_800A99AC;
    }
    // 0x800A99A4: nop

    // 0x800A99A8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A99AC:
    // 0x800A99AC: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x800A99B0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800A99B4: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x800A99B8: nop

    // 0x800A99BC: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x800A99C0: nop

    // 0x800A99C4: bne         $s3, $t4, L_800A99D0
    if (ctx->r19 != ctx->r12) {
        // 0x800A99C8: nop
    
            goto L_800A99D0;
    }
    // 0x800A99C8: nop

    // 0x800A99CC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A99D0:
    // 0x800A99D0: bne         $a0, $a3, L_800A9940
    if (ctx->r4 != ctx->r7) {
        // 0x800A99D4: nop
    
            goto L_800A9940;
    }
    // 0x800A99D4: nop

L_800A99D8:
    // 0x800A99D8: beq         $a2, $zero, L_800A9C10
    if (ctx->r6 == 0) {
        // 0x800A99DC: lui         $s2, 0x8012
        ctx->r18 = S32(0X8012 << 16);
            goto L_800A9C10;
    }
    // 0x800A99DC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A99E0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A99E4: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
    // 0x800A99E8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A99EC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A99F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A99F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A99F8: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A99FC: lwc1        $f10, 0x650($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A9A00: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9A04: lwc1        $f8, 0x40C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A9A08: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A9A0C: lwc1        $f4, 0x410($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A9A10: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x800A9A14: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A9A18: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A9A1C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A9A20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9A24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9A28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800A9A2C: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A9A30: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A9A34: mfc1        $s1, $f18
    ctx->r17 = (int32_t)ctx->f18.u32l;
    // 0x800A9A38: nop

    // 0x800A9A3C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A9A40: nop

    // 0x800A9A44: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A9A48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9A4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9A50: nop

    // 0x800A9A54: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A9A58: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A9A5C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800A9A60: nop

    // 0x800A9A64: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A9A68: nop

    // 0x800A9A6C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A9A70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9A74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9A78: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x800A9A7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A9A80: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x800A9A84: swc1        $f10, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f10.u32l;
    // 0x800A9A88: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A9A8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A9A90: lui         $at, 0x4351
    ctx->r1 = S32(0X4351 << 16);
    // 0x800A9A94: swc1        $f18, 0x650($t9)
    MEM_W(0X650, ctx->r25) = ctx->f18.u32l;
    // 0x800A9A98: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A9A9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A9AA0: lui         $at, 0x4341
    ctx->r1 = S32(0X4341 << 16);
    // 0x800A9AA4: swc1        $f8, 0x40C($t2)
    MEM_W(0X40C, ctx->r10) = ctx->f8.u32l;
    // 0x800A9AA8: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A9AAC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A9AB0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9AB4: swc1        $f16, 0x410($t3)
    MEM_W(0X410, ctx->r11) = ctx->f16.u32l;
    // 0x800A9AB8: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x800A9ABC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A9AC0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A9AC4: bne         $t4, $zero, L_800A9BB8
    if (ctx->r12 != 0) {
        // 0x800A9AC8: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_800A9BB8;
    }
    // 0x800A9AC8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A9ACC: lwc1        $f1, -0x72C0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X72C0);
    // 0x800A9AD0: lwc1        $f0, -0x72BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72BC);
    // 0x800A9AD4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9AD8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A9ADC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A9AE0: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A9AE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A9AE8: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A9AEC: swc1        $f10, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f10.u32l;
    // 0x800A9AF0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9AF4: nop

    // 0x800A9AF8: lwc1        $f18, 0x40C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A9AFC: nop

    // 0x800A9B00: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800A9B04: swc1        $f16, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f16.u32l;
    // 0x800A9B08: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9B0C: nop

    // 0x800A9B10: lwc1        $f4, 0x650($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A9B14: nop

    // 0x800A9B18: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800A9B1C: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x800A9B20: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800A9B24: swc1        $f18, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f18.u32l;
    // 0x800A9B28: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9B2C: nop

    // 0x800A9B30: lwc1        $f8, 0x410($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A9B34: nop

    // 0x800A9B38: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800A9B3C: mul.d       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x800A9B40: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800A9B44: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A9B48: swc1        $f6, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f6.u32l;
    // 0x800A9B4C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9B50: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A9B54: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9B58: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9B5C: lwc1        $f10, 0x650($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A9B60: nop

    // 0x800A9B64: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A9B68: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800A9B6C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A9B70: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800A9B74: nop

    // 0x800A9B78: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9B7C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A9B80: swc1        $f16, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f16.u32l;
    // 0x800A9B84: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9B88: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A9B8C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9B90: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9B94: lwc1        $f4, 0x410($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A9B98: nop

    // 0x800A9B9C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9BA0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800A9BA4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A9BA8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800A9BAC: nop

    // 0x800A9BB0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A9BB4: swc1        $f18, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f18.u32l;
L_800A9BB8:
    // 0x800A9BB8: sw          $v1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r3;
    // 0x800A9BBC: jal         0x800A4B38
    // 0x800A9BC0: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    hud_treasure(rdram, ctx);
        goto after_27;
    // 0x800A9BC0: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    after_27:
    // 0x800A9BC4: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x800A9BC8: lw          $v1, 0xA8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA8);
    // 0x800A9BCC: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9BD0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A9BD4: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x800A9BD8: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800A9BDC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A9BE0: swc1        $f16, 0x64C($t9)
    MEM_W(0X64C, ctx->r25) = ctx->f16.u32l;
    // 0x800A9BE4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A9BE8: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800A9BEC: swc1        $f6, 0x650($t2)
    MEM_W(0X650, ctx->r10) = ctx->f6.u32l;
    // 0x800A9BF0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A9BF4: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A9BF8: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800A9BFC: swc1        $f18, 0x40C($t3)
    MEM_W(0X40C, ctx->r11) = ctx->f18.u32l;
    // 0x800A9C00: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9C04: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800A9C08: nop

    // 0x800A9C0C: swc1        $f16, 0x410($t4)
    MEM_W(0X410, ctx->r12) = ctx->f16.u32l;
L_800A9C10:
    // 0x800A9C10: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9C14: lw          $v0, 0x7740($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7740);
    // 0x800A9C18: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A9C1C: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
    // 0x800A9C20: beq         $v0, $zero, L_800A9C6C
    if (ctx->r2 == 0) {
        // 0x800A9C24: addiu       $s3, $zero, -0x1
        ctx->r19 = ADD32(0, -0X1);
            goto L_800A9C6C;
    }
    // 0x800A9C24: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800A9C28: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A9C2C: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x800A9C30: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x800A9C34: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x800A9C38: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x800A9C3C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A9C40: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A9C44: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A9C48: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A9C4C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800A9C50: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A9C54: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800A9C58: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800A9C5C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A9C60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A9C64: jal         0x80078F08
    // 0x800A9C68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    texrect_draw(rdram, ctx);
        goto after_28;
    // 0x800A9C68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_28:
L_800A9C6C:
    // 0x800A9C6C: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800A9C70: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x800A9C74: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A9C78: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A9C7C: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x800A9C80: lw          $t5, 0x72C0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72C0);
    // 0x800A9C84: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A9C88: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A9C8C: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x800A9C90: lw          $t7, 0x72C4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72C4);
    // 0x800A9C94: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A9C98: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A9C9C: lw          $t9, 0x7320($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7320);
    // 0x800A9CA0: nop

    // 0x800A9CA4: lbu         $t2, 0xBC($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0XBC);
    // 0x800A9CA8: nop

    // 0x800A9CAC: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x800A9CB0: bne         $t3, $zero, L_800AA92C
    if (ctx->r11 != 0) {
        // 0x800A9CB4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800AA92C;
    }
    // 0x800A9CB4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A9CB8: lw          $t4, 0x140($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X140);
    // 0x800A9CBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A9CC0: blez        $t4, L_800A9E44
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800A9CC4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800A9E44;
    }
    // 0x800A9CC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A9CC8: andi        $t0, $t4, 0x3
    ctx->r8 = ctx->r12 & 0X3;
    // 0x800A9CCC: beq         $t0, $zero, L_800A9D34
    if (ctx->r8 == 0) {
        // 0x800A9CD0: or          $a2, $t0, $zero
        ctx->r6 = ctx->r8 | 0;
            goto L_800A9D34;
    }
    // 0x800A9CD0: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800A9CD4: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800A9CD8: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x800A9CDC: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
L_800A9CE0:
    // 0x800A9CE0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A9CE4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A9CE8: lw          $v0, 0x64($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X64);
    // 0x800A9CEC: nop

    // 0x800A9CF0: beq         $v0, $zero, L_800A9D1C
    if (ctx->r2 == 0) {
        // 0x800A9CF4: nop
    
            goto L_800A9D1C;
    }
    // 0x800A9CF4: nop

    // 0x800A9CF8: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800A9CFC: nop

    // 0x800A9D00: beq         $s3, $t8, L_800A9D1C
    if (ctx->r19 == ctx->r24) {
        // 0x800A9D04: nop
    
            goto L_800A9D1C;
    }
    // 0x800A9D04: nop

    // 0x800A9D08: lb          $t9, 0x1D8($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1D8);
    // 0x800A9D0C: nop

    // 0x800A9D10: bne         $t9, $zero, L_800A9D1C
    if (ctx->r25 != 0) {
        // 0x800A9D14: nop
    
            goto L_800A9D1C;
    }
    // 0x800A9D14: nop

    // 0x800A9D18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800A9D1C:
    // 0x800A9D1C: bne         $a2, $v1, L_800A9CE0
    if (ctx->r6 != ctx->r3) {
        // 0x800A9D20: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800A9CE0;
    }
    // 0x800A9D20: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A9D24: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x800A9D28: nop

    // 0x800A9D2C: beq         $v1, $t2, L_800A9E44
    if (ctx->r3 == ctx->r10) {
        // 0x800A9D30: nop
    
            goto L_800A9E44;
    }
    // 0x800A9D30: nop

L_800A9D34:
    // 0x800A9D34: lw          $a2, 0x140($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X140);
    // 0x800A9D38: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x800A9D3C: sll         $s1, $v1, 2
    ctx->r17 = S32(ctx->r3 << 2);
    // 0x800A9D40: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x800A9D44: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x800A9D48: addu        $s0, $t3, $s1
    ctx->r16 = ADD32(ctx->r11, ctx->r17);
L_800A9D4C:
    // 0x800A9D4C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800A9D50: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800A9D54: lw          $v0, 0x64($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X64);
    // 0x800A9D58: nop

    // 0x800A9D5C: beq         $v0, $zero, L_800A9D88
    if (ctx->r2 == 0) {
        // 0x800A9D60: nop
    
            goto L_800A9D88;
    }
    // 0x800A9D60: nop

    // 0x800A9D64: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800A9D68: nop

    // 0x800A9D6C: beq         $s3, $t6, L_800A9D88
    if (ctx->r19 == ctx->r14) {
        // 0x800A9D70: nop
    
            goto L_800A9D88;
    }
    // 0x800A9D70: nop

    // 0x800A9D74: lb          $t7, 0x1D8($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1D8);
    // 0x800A9D78: nop

    // 0x800A9D7C: bne         $t7, $zero, L_800A9D88
    if (ctx->r15 != 0) {
        // 0x800A9D80: nop
    
            goto L_800A9D88;
    }
    // 0x800A9D80: nop

    // 0x800A9D84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800A9D88:
    // 0x800A9D88: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800A9D8C: nop

    // 0x800A9D90: lw          $a1, 0x64($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X64);
    // 0x800A9D94: nop

    // 0x800A9D98: beq         $a1, $zero, L_800A9DC4
    if (ctx->r5 == 0) {
        // 0x800A9D9C: nop
    
            goto L_800A9DC4;
    }
    // 0x800A9D9C: nop

    // 0x800A9DA0: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x800A9DA4: nop

    // 0x800A9DA8: beq         $s3, $t9, L_800A9DC4
    if (ctx->r19 == ctx->r25) {
        // 0x800A9DAC: nop
    
            goto L_800A9DC4;
    }
    // 0x800A9DAC: nop

    // 0x800A9DB0: lb          $t2, 0x1D8($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X1D8);
    // 0x800A9DB4: nop

    // 0x800A9DB8: bne         $t2, $zero, L_800A9DC4
    if (ctx->r10 != 0) {
        // 0x800A9DBC: nop
    
            goto L_800A9DC4;
    }
    // 0x800A9DBC: nop

    // 0x800A9DC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800A9DC4:
    // 0x800A9DC4: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x800A9DC8: nop

    // 0x800A9DCC: lw          $a1, 0x64($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X64);
    // 0x800A9DD0: nop

    // 0x800A9DD4: beq         $a1, $zero, L_800A9E00
    if (ctx->r5 == 0) {
        // 0x800A9DD8: nop
    
            goto L_800A9E00;
    }
    // 0x800A9DD8: nop

    // 0x800A9DDC: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x800A9DE0: nop

    // 0x800A9DE4: beq         $s3, $t4, L_800A9E00
    if (ctx->r19 == ctx->r12) {
        // 0x800A9DE8: nop
    
            goto L_800A9E00;
    }
    // 0x800A9DE8: nop

    // 0x800A9DEC: lb          $t5, 0x1D8($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X1D8);
    // 0x800A9DF0: nop

    // 0x800A9DF4: bne         $t5, $zero, L_800A9E00
    if (ctx->r13 != 0) {
        // 0x800A9DF8: nop
    
            goto L_800A9E00;
    }
    // 0x800A9DF8: nop

    // 0x800A9DFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800A9E00:
    // 0x800A9E00: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800A9E04: nop

    // 0x800A9E08: lw          $a1, 0x64($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X64);
    // 0x800A9E0C: nop

    // 0x800A9E10: beq         $a1, $zero, L_800A9E3C
    if (ctx->r5 == 0) {
        // 0x800A9E14: nop
    
            goto L_800A9E3C;
    }
    // 0x800A9E14: nop

    // 0x800A9E18: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x800A9E1C: nop

    // 0x800A9E20: beq         $s3, $t7, L_800A9E3C
    if (ctx->r19 == ctx->r15) {
        // 0x800A9E24: nop
    
            goto L_800A9E3C;
    }
    // 0x800A9E24: nop

    // 0x800A9E28: lb          $t8, 0x1D8($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X1D8);
    // 0x800A9E2C: nop

    // 0x800A9E30: bne         $t8, $zero, L_800A9E3C
    if (ctx->r24 != 0) {
        // 0x800A9E34: nop
    
            goto L_800A9E3C;
    }
    // 0x800A9E34: nop

    // 0x800A9E38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800A9E3C:
    // 0x800A9E3C: bne         $s1, $a2, L_800A9D4C
    if (ctx->r17 != ctx->r6) {
        // 0x800A9E40: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800A9D4C;
    }
    // 0x800A9E40: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_800A9E44:
    // 0x800A9E44: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A9E48: lw          $t9, 0x72CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72CC);
    // 0x800A9E4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9E50: bne         $t9, $at, L_800A9E6C
    if (ctx->r25 != ctx->r1) {
        // 0x800A9E54: nop
    
            goto L_800A9E6C;
    }
    // 0x800A9E54: nop

    // 0x800A9E58: jal         0x8006ECF0
    // 0x800A9E5C: sb          $a0, 0x113($sp)
    MEM_B(0X113, ctx->r29) = ctx->r4;
    is_postrace_viewport_active(rdram, ctx);
        goto after_29;
    // 0x800A9E5C: sb          $a0, 0x113($sp)
    MEM_B(0X113, ctx->r29) = ctx->r4;
    after_29:
    // 0x800A9E60: lbu         $a0, 0x113($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X113);
    // 0x800A9E64: bne         $v0, $zero, L_800AA92C
    if (ctx->r2 != 0) {
        // 0x800A9E68: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800AA92C;
    }
    // 0x800A9E68: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800A9E6C:
    // 0x800A9E6C: jal         0x80066750
    // 0x800A9E70: sb          $a0, 0x113($sp)
    MEM_B(0X113, ctx->r29) = ctx->r4;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_30;
    // 0x800A9E70: sb          $a0, 0x113($sp)
    MEM_B(0X113, ctx->r29) = ctx->r4;
    after_30:
    // 0x800A9E74: lbu         $a0, 0x113($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X113);
    // 0x800A9E78: bne         $v0, $zero, L_800AA92C
    if (ctx->r2 != 0) {
        // 0x800A9E7C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800AA92C;
    }
    // 0x800A9E7C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A9E80: bne         $a0, $zero, L_800AA928
    if (ctx->r4 != 0) {
        // 0x800A9E84: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800AA928;
    }
    // 0x800A9E84: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A9E88: lw          $t2, 0x72CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72CC);
    // 0x800A9E8C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800A9E90: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800A9E94: lb          $t3, 0x2D24($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X2D24);
    // 0x800A9E98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A9E9C: beq         $t3, $at, L_800A9EAC
    if (ctx->r11 == ctx->r1) {
        // 0x800A9EA0: nop
    
            goto L_800A9EAC;
    }
    // 0x800A9EA0: nop

    // 0x800A9EA4: b           L_800AA92C
    // 0x800A9EA8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800AA92C;
    // 0x800A9EA8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800A9EAC:
    // 0x800A9EAC: jal         0x8007B820
    // 0x800A9EB0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    rendermode_reset(rdram, ctx);
        goto after_31;
    // 0x800A9EB0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_31:
    // 0x800A9EB4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A9EB8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A9EBC: jal         0x8006816C
    // 0x800A9EC0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mtx_ortho(rdram, ctx);
        goto after_32;
    // 0x800A9EC0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_32:
    // 0x800A9EC4: jal         0x8002C804
    // 0x800A9EC8: nop

    get_current_level_model(rdram, ctx);
        goto after_33;
    // 0x800A9EC8: nop

    after_33:
    // 0x800A9ECC: beq         $v0, $zero, L_800AA928
    if (ctx->r2 == 0) {
        // 0x800A9ED0: sw          $v0, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r2;
            goto L_800AA928;
    }
    // 0x800A9ED0: sw          $v0, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r2;
    // 0x800A9ED4: jal         0x80069F60
    // 0x800A9ED8: nop

    cam_get_active_camera(rdram, ctx);
        goto after_34;
    // 0x800A9ED8: nop

    after_34:
    // 0x800A9EDC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800A9EE0: jal         0x80068748
    // 0x800A9EE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_35;
    // 0x800A9EE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_35:
    // 0x800A9EE8: lw          $t4, 0x158($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X158);
    // 0x800A9EEC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9EF0: lw          $v0, 0x72CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72CC);
    // 0x800A9EF4: lw          $t5, 0x20($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X20);
    // 0x800A9EF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A9EFC: beq         $v0, $at, L_800A9F38
    if (ctx->r2 == ctx->r1) {
        // 0x800A9F00: sw          $t5, 0x154($sp)
        MEM_W(0X154, ctx->r29) = ctx->r13;
            goto L_800A9F38;
    }
    // 0x800A9F00: sw          $t5, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r13;
    // 0x800A9F04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9F08: beq         $v0, $at, L_800A9F70
    if (ctx->r2 == ctx->r1) {
        // 0x800A9F0C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A9F70;
    }
    // 0x800A9F0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A9F10: beq         $v0, $at, L_800AA04C
    if (ctx->r2 == ctx->r1) {
        // 0x800A9F14: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_800AA04C;
    }
    // 0x800A9F14: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A9F18: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A9F1C: addiu       $t6, $zero, 0x87
    ctx->r14 = ADD32(0, 0X87);
    // 0x800A9F20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A9F24: sw          $t6, 0x7318($at)
    MEM_W(0X7318, ctx->r1) = ctx->r14;
    // 0x800A9F28: addiu       $s0, $s0, 0x731C
    ctx->r16 = ADD32(ctx->r16, 0X731C);
    // 0x800A9F2C: addiu       $t7, $zero, -0x62
    ctx->r15 = ADD32(0, -0X62);
    // 0x800A9F30: b           L_800AA094
    // 0x800A9F34: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
        goto L_800AA094;
    // 0x800A9F34: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_800A9F38:
    // 0x800A9F38: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A9F3C: lw          $t9, 0x72E0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72E0);
    // 0x800A9F40: addiu       $t8, $zero, 0x87
    ctx->r24 = ADD32(0, 0X87);
    // 0x800A9F44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A9F48: sw          $t8, 0x7318($at)
    MEM_W(0X7318, ctx->r1) = ctx->r24;
    // 0x800A9F4C: negu        $t2, $t9
    ctx->r10 = SUB32(0, ctx->r25);
    // 0x800A9F50: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A9F54: addiu       $s0, $s0, 0x731C
    ctx->r16 = ADD32(ctx->r16, 0X731C);
    // 0x800A9F58: bgez        $t2, L_800A9F68
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A9F5C: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800A9F68;
    }
    // 0x800A9F5C: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800A9F60: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x800A9F64: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800A9F68:
    // 0x800A9F68: b           L_800AA094
    // 0x800A9F6C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
        goto L_800AA094;
    // 0x800A9F6C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
L_800A9F70:
    // 0x800A9F70: jal         0x8006BFD8
    // 0x800A9F74: nop

    level_type(rdram, ctx);
        goto after_36;
    // 0x800A9F74: nop

    after_36:
    // 0x800A9F78: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x800A9F7C: beq         $v0, $at, L_800A9FAC
    if (ctx->r2 == ctx->r1) {
        // 0x800A9F80: nop
    
            goto L_800A9FAC;
    }
    // 0x800A9F80: nop

    // 0x800A9F84: jal         0x8006BFD8
    // 0x800A9F88: nop

    level_type(rdram, ctx);
        goto after_37;
    // 0x800A9F88: nop

    after_37:
    // 0x800A9F8C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A9F90: beq         $v0, $at, L_800A9FAC
    if (ctx->r2 == ctx->r1) {
        // 0x800A9F94: nop
    
            goto L_800A9FAC;
    }
    // 0x800A9F94: nop

    // 0x800A9F98: jal         0x8006BFD8
    // 0x800A9F9C: nop

    level_type(rdram, ctx);
        goto after_38;
    // 0x800A9F9C: nop

    after_38:
    // 0x800A9FA0: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800A9FA4: bne         $v0, $at, L_800A9FFC
    if (ctx->r2 != ctx->r1) {
        // 0x800A9FA8: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_800A9FFC;
    }
    // 0x800A9FA8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
L_800A9FAC:
    // 0x800A9FAC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A9FB0: lw          $t4, 0x72DC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72DC);
    // 0x800A9FB4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A9FB8: lw          $t7, 0x72E0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72E0);
    // 0x800A9FBC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A9FC0: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x800A9FC4: addiu       $s0, $s0, 0x731C
    ctx->r16 = ADD32(ctx->r16, 0X731C);
    // 0x800A9FC8: bgez        $t4, L_800A9FD8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800A9FCC: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_800A9FD8;
    }
    // 0x800A9FCC: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800A9FD0: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x800A9FD4: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_800A9FD8:
    // 0x800A9FD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A9FDC: addiu       $t6, $t5, -0x8
    ctx->r14 = ADD32(ctx->r13, -0X8);
    // 0x800A9FE0: sw          $t6, 0x7318($at)
    MEM_W(0X7318, ctx->r1) = ctx->r14;
    // 0x800A9FE4: bgez        $t8, L_800A9FF4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A9FE8: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_800A9FF4;
    }
    // 0x800A9FE8: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800A9FEC: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x800A9FF0: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_800A9FF4:
    // 0x800A9FF4: b           L_800AA094
    // 0x800A9FF8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
        goto L_800AA094;
    // 0x800A9FF8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_800A9FFC:
    // 0x800A9FFC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800AA000: lw          $t2, 0x72DC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72DC);
    // 0x800AA004: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AA008: lw          $t5, 0x72E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72E0);
    // 0x800AA00C: addiu       $t7, $zero, -0x3C
    ctx->r15 = ADD32(0, -0X3C);
    // 0x800AA010: addiu       $s0, $s0, 0x731C
    ctx->r16 = ADD32(ctx->r16, 0X731C);
    // 0x800AA014: bgez        $t2, L_800AA024
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800AA018: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800AA024;
    }
    // 0x800AA018: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800AA01C: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x800AA020: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800AA024:
    // 0x800AA024: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AA028: addiu       $t4, $t3, 0x48
    ctx->r12 = ADD32(ctx->r11, 0X48);
    // 0x800AA02C: sw          $t4, 0x7318($at)
    MEM_W(0X7318, ctx->r1) = ctx->r12;
    // 0x800AA030: bgez        $t5, L_800AA040
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800AA034: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_800AA040;
    }
    // 0x800AA034: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800AA038: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x800AA03C: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_800AA040:
    // 0x800AA040: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800AA044: b           L_800AA094
    // 0x800AA048: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_800AA094;
    // 0x800AA048: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_800AA04C:
    // 0x800AA04C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AA050: lw          $t9, 0x72DC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72DC);
    // 0x800AA054: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AA058: lw          $t4, 0x72E0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72E0);
    // 0x800AA05C: addiu       $s0, $s0, 0x731C
    ctx->r16 = ADD32(ctx->r16, 0X731C);
    // 0x800AA060: bgez        $t9, L_800AA070
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800AA064: sra         $t2, $t9, 1
        ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
            goto L_800AA070;
    }
    // 0x800AA064: sra         $t2, $t9, 1
    ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800AA068: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x800AA06C: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_800AA070:
    // 0x800AA070: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AA074: addiu       $t3, $t2, -0x8
    ctx->r11 = ADD32(ctx->r10, -0X8);
    // 0x800AA078: sw          $t3, 0x7318($at)
    MEM_W(0X7318, ctx->r1) = ctx->r11;
    // 0x800AA07C: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800AA080: bgez        $t5, L_800AA090
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800AA084: sra         $t7, $t5, 1
        ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
            goto L_800AA090;
    }
    // 0x800AA084: sra         $t7, $t5, 1
    ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800AA088: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x800AA08C: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800AA090:
    // 0x800AA090: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_800AA094:
    // 0x800AA094: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800AA098: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800AA09C: nop

    // 0x800AA0A0: bne         $t6, $zero, L_800AA0F0
    if (ctx->r14 != 0) {
        // 0x800AA0A4: nop
    
            goto L_800AA0F0;
    }
    // 0x800AA0A4: nop

    // 0x800AA0A8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800AA0AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AA0B0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800AA0B4: lwc1        $f11, -0x72B8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X72B8);
    // 0x800AA0B8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800AA0BC: lwc1        $f10, -0x72B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X72B4);
    // 0x800AA0C0: nop

    // 0x800AA0C4: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800AA0C8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AA0CC: nop

    // 0x800AA0D0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AA0D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AA0D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AA0DC: nop

    // 0x800AA0E0: cvt.w.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_D(ctx->f18.d);
    // 0x800AA0E4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AA0E8: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x800AA0EC: nop

L_800AA0F0:
    // 0x800AA0F0: jal         0x8007C36C
    // 0x800AA0F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_39;
    // 0x800AA0F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_39:
    // 0x800AA0F8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800AA0FC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800AA100: lw          $t2, 0x7318($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7318);
    // 0x800AA104: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800AA108: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AA10C: lw          $t3, 0x72E4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X72E4);
    // 0x800AA110: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AA114: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AA118: lw          $t5, 0x72E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72E8);
    // 0x800AA11C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800AA120: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x800AA124: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800AA128: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800AA12C: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AA130: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800AA134: swc1        $f18, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f18.u32l;
    // 0x800AA138: bne         $t8, $zero, L_800AA154
    if (ctx->r24 != 0) {
        // 0x800AA13C: swc1        $f0, 0x12C($sp)
        MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
            goto L_800AA154;
    }
    // 0x800AA13C: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
    // 0x800AA140: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AA144: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA148: nop

    // 0x800AA14C: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800AA150: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
L_800AA154:
    // 0x800AA154: lh          $t9, 0x4($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4);
    // 0x800AA158: sh          $zero, 0x122($sp)
    MEM_H(0X122, ctx->r29) = 0;
    // 0x800AA15C: negu        $t2, $t9
    ctx->r10 = SUB32(0, ctx->r25);
    // 0x800AA160: jal         0x8009C850
    // 0x800AA164: sh          $t2, 0x124($sp)
    MEM_H(0X124, ctx->r29) = ctx->r10;
    get_filtered_cheats(rdram, ctx);
        goto after_40;
    // 0x800AA164: sh          $t2, 0x124($sp)
    MEM_H(0X124, ctx->r29) = ctx->r10;
    after_40:
    // 0x800AA168: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x800AA16C: beq         $t3, $zero, L_800AA19C
    if (ctx->r11 == 0) {
        // 0x800AA170: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800AA19C;
    }
    // 0x800AA170: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA174: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AA178: lw          $t5, 0x72DC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72DC);
    // 0x800AA17C: lwc1        $f0, 0x12C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x800AA180: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800AA184: addiu       $t4, $zero, -0x8000
    ctx->r12 = ADD32(0, -0X8000);
    // 0x800AA188: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AA18C: sh          $t4, 0x120($sp)
    MEM_H(0X120, ctx->r29) = ctx->r12;
    // 0x800AA190: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800AA194: b           L_800AA1A0
    // 0x800AA198: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
        goto L_800AA1A0;
    // 0x800AA198: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
L_800AA19C:
    // 0x800AA19C: sh          $zero, 0x120($sp)
    MEM_H(0X120, ctx->r29) = 0;
L_800AA1A0:
    // 0x800AA1A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AA1A4: lw          $t7, 0x10C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10C);
    // 0x800AA1A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AA1AC: slti        $at, $t7, 0xA1
    ctx->r1 = SIGNED(ctx->r15) < 0XA1 ? 1 : 0;
    // 0x800AA1B0: sh          $zero, 0x138($sp)
    MEM_H(0X138, ctx->r29) = 0;
    // 0x800AA1B4: swc1        $f4, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f4.u32l;
    // 0x800AA1B8: sw          $t7, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r15;
    // 0x800AA1BC: bne         $at, $zero, L_800AA1CC
    if (ctx->r1 != 0) {
        // 0x800AA1C0: swc1        $f16, 0x134($sp)
        MEM_W(0X134, ctx->r29) = ctx->f16.u32l;
            goto L_800AA1CC;
    }
    // 0x800AA1C0: swc1        $f16, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f16.u32l;
    // 0x800AA1C4: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x800AA1C8: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
L_800AA1CC:
    // 0x800AA1CC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800AA1D0: lbu         $t8, 0x72F7($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X72F7);
    // 0x800AA1D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AA1D8: bne         $t8, $at, L_800AA20C
    if (ctx->r24 != ctx->r1) {
        // 0x800AA1DC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800AA20C;
    }
    // 0x800AA1DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800AA1E0: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA1E4: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800AA1E8: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800AA1EC: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800AA1F0: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800AA1F4: lw          $t3, 0x10C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10C);
    // 0x800AA1F8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800AA1FC: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800AA200: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800AA204: b           L_800AA25C
    // 0x800AA208: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
        goto L_800AA25C;
    // 0x800AA208: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
L_800AA20C:
    // 0x800AA20C: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA210: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800AA214: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x800AA218: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800AA21C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AA220: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800AA224: lbu         $t4, 0x7315($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X7315);
    // 0x800AA228: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800AA22C: lbu         $t9, 0x7314($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X7314);
    // 0x800AA230: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800AA234: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x800AA238: lbu         $t8, 0x7316($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X7316);
    // 0x800AA23C: sll         $t2, $t9, 24
    ctx->r10 = S32(ctx->r25 << 24);
    // 0x800AA240: lw          $t4, 0x10C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10C);
    // 0x800AA244: or          $t7, $t2, $t5
    ctx->r15 = ctx->r10 | ctx->r13;
    // 0x800AA248: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800AA24C: or          $t3, $t7, $t9
    ctx->r11 = ctx->r15 | ctx->r25;
    // 0x800AA250: andi        $t2, $t4, 0xFF
    ctx->r10 = ctx->r12 & 0XFF;
    // 0x800AA254: or          $t5, $t3, $t2
    ctx->r13 = ctx->r11 | ctx->r10;
    // 0x800AA258: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
L_800AA25C:
    // 0x800AA25C: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x800AA260: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AA264: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AA268: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800AA26C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AA270: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    // 0x800AA274: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800AA278: jal         0x80068E34
    // 0x800AA27C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    render_ortho_triangle_image(rdram, ctx);
        goto after_41;
    // 0x800AA27C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_41:
    // 0x800AA280: lw          $v0, 0x158($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X158);
    // 0x800AA284: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x800AA288: lh          $t8, 0x3E($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X3E);
    // 0x800AA28C: lh          $t7, 0x3C($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X3C);
    // 0x800AA290: lh          $t4, 0x46($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X46);
    // 0x800AA294: lh          $t3, 0x44($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X44);
    // 0x800AA298: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x800AA29C: subu        $t2, $t4, $t3
    ctx->r10 = SUB32(ctx->r12, ctx->r11);
    // 0x800AA2A0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800AA2A4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800AA2A8: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AA2AC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AA2B0: nop

    // 0x800AA2B4: div.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800AA2B8: swc1        $f16, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f16.u32l;
    // 0x800AA2BC: lhu         $a0, 0x24($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X24);
    // 0x800AA2C0: nop

    // 0x800AA2C4: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800AA2C8: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800AA2CC: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x800AA2D0: mflo        $t6
    ctx->r14 = lo;
    // 0x800AA2D4: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800AA2D8: jal         0x80070A38
    // 0x800AA2DC: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    coss_f(rdram, ctx);
        goto after_42;
    // 0x800AA2DC: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_42:
    // 0x800AA2E0: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x800AA2E4: swc1        $f0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f0.u32l;
    // 0x800AA2E8: lhu         $a0, 0x24($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X24);
    // 0x800AA2EC: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x800AA2F0: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x800AA2F4: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x800AA2F8: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x800AA2FC: mflo        $t3
    ctx->r11 = lo;
    // 0x800AA300: sll         $t2, $t3, 16
    ctx->r10 = S32(ctx->r11 << 16);
    // 0x800AA304: jal         0x80070A04
    // 0x800AA308: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    sins_f(rdram, ctx);
        goto after_43;
    // 0x800AA308: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    after_43:
    // 0x800AA30C: jal         0x8000E4D8
    // 0x800AA310: swc1        $f0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f0.u32l;
    is_in_time_trial(rdram, ctx);
        goto after_44;
    // 0x800AA310: swc1        $f0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f0.u32l;
    after_44:
    // 0x800AA314: beq         $v0, $zero, L_800AA424
    if (ctx->r2 == 0) {
        // 0x800AA318: nop
    
            goto L_800AA424;
    }
    // 0x800AA318: nop

    // 0x800AA31C: jal         0x8001B2BC
    // 0x800AA320: nop

    timetrial_valid_player_ghost(rdram, ctx);
        goto after_45;
    // 0x800AA320: nop

    after_45:
    // 0x800AA324: beq         $v0, $zero, L_800AA424
    if (ctx->r2 == 0) {
        // 0x800AA328: nop
    
            goto L_800AA424;
    }
    // 0x800AA328: nop

    // 0x800AA32C: jal         0x8001B314
    // 0x800AA330: nop

    timetrial_player_ghost(rdram, ctx);
        goto after_46;
    // 0x800AA330: nop

    after_46:
    // 0x800AA334: beq         $v0, $zero, L_800AA424
    if (ctx->r2 == 0) {
        // 0x800AA338: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800AA424;
    }
    // 0x800AA338: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800AA33C: lwc1        $f4, 0x11C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800AA340: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AA344: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AA348: lw          $a2, 0x114($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X114);
    // 0x800AA34C: lw          $a3, 0x118($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X118);
    // 0x800AA350: jal         0x800AA948
    // 0x800AA354: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    minimap_marker_pos(rdram, ctx);
        goto after_47;
    // 0x800AA354: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_47:
    // 0x800AA358: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800AA35C: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x800AA360: sh          $t6, 0x1E6($t8)
    MEM_H(0X1E6, ctx->r24) = ctx->r14;
    // 0x800AA364: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AA368: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA36C: sh          $zero, 0x1E4($t7)
    MEM_H(0X1E4, ctx->r15) = 0;
    // 0x800AA370: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800AA374: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AA378: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800AA37C: swc1        $f6, 0x1E8($t9)
    MEM_W(0X1E8, ctx->r25) = ctx->f6.u32l;
    // 0x800AA380: lbu         $t3, 0x39($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X39);
    // 0x800AA384: lw          $t4, 0x108($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X108);
    // 0x800AA388: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800AA38C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800AA390: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AA394: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AA398: bgez        $t3, L_800AA3B0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800AA39C: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800AA3B0;
    }
    // 0x800AA39C: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AA3A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AA3A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AA3A8: nop

    // 0x800AA3AC: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_800AA3B0:
    // 0x800AA3B0: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AA3B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA3B8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800AA3BC: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA3C0: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x800AA3C4: mul.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x800AA3C8: addiu       $t5, $t0, 0x8
    ctx->r13 = ADD32(ctx->r8, 0X8);
    // 0x800AA3CC: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800AA3D0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800AA3D4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AA3D8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800AA3DC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AA3E0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800AA3E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AA3E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AA3EC: lui         $at, 0x3C3C
    ctx->r1 = S32(0X3C3C << 16);
    // 0x800AA3F0: cvt.w.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_D(ctx->f4.d);
    // 0x800AA3F4: ori         $at, $at, 0x3C00
    ctx->r1 = ctx->r1 | 0X3C00;
    // 0x800AA3F8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800AA3FC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800AA400: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x800AA404: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800AA408: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800AA40C: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800AA410: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800AA414: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AA418: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800AA41C: jal         0x800AAB5C
    // 0x800AA420: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    hud_element_render(rdram, ctx);
        goto after_48;
    // 0x800AA420: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    after_48:
L_800AA424:
    // 0x800AA424: jal         0x8001B674
    // 0x800AA428: nop

    timetrial_ghost_staff(rdram, ctx);
        goto after_49;
    // 0x800AA428: nop

    after_49:
    // 0x800AA42C: beq         $v0, $zero, L_800AA544
    if (ctx->r2 == 0) {
        // 0x800AA430: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800AA544;
    }
    // 0x800AA430: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800AA434: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x800AA438: lwc1        $f16, 0x11C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800AA43C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800AA440: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AA444: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AA448: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AA44C: lw          $a2, 0x114($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X114);
    // 0x800AA450: lw          $a3, 0x118($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X118);
    // 0x800AA454: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x800AA458: jal         0x800AA948
    // 0x800AA45C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    minimap_marker_pos(rdram, ctx);
        goto after_50;
    // 0x800AA45C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_50:
    // 0x800AA460: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800AA464: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AA468: sh          $zero, 0x1E4($t4)
    MEM_H(0X1E4, ctx->r12) = 0;
    // 0x800AA46C: lbu         $t3, 0x39($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X39);
    // 0x800AA470: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800AA474: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800AA478: addiu       $t1, $t1, 0x2D3C
    ctx->r9 = ADD32(ctx->r9, 0X2D3C);
    // 0x800AA47C: bgez        $t3, L_800AA494
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800AA480: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800AA494;
    }
    // 0x800AA480: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AA484: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AA488: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AA48C: nop

    // 0x800AA490: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800AA494:
    // 0x800AA494: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AA498: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA49C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800AA4A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AA4A4: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x800AA4A8: mul.d       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800AA4AC: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA4B0: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800AA4B4: addiu       $t5, $t0, 0x8
    ctx->r13 = ADD32(ctx->r8, 0X8);
    // 0x800AA4B8: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800AA4BC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800AA4C0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800AA4C4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800AA4C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AA4CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AA4D0: lbu         $t7, 0x1A($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X1A);
    // 0x800AA4D4: cvt.w.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = CVT_W_D(ctx->f16.d);
    // 0x800AA4D8: lbu         $t3, 0x18($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X18);
    // 0x800AA4DC: lbu         $t8, 0x19($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X19);
    // 0x800AA4E0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800AA4E4: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x800AA4E8: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800AA4EC: sll         $t2, $t3, 24
    ctx->r10 = S32(ctx->r11 << 24);
    // 0x800AA4F0: or          $t5, $t9, $t2
    ctx->r13 = ctx->r25 | ctx->r10;
    // 0x800AA4F4: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x800AA4F8: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x800AA4FC: andi        $t3, $v1, 0xFF
    ctx->r11 = ctx->r3 & 0XFF;
    // 0x800AA500: or          $t9, $t4, $t3
    ctx->r25 = ctx->r12 | ctx->r11;
    // 0x800AA504: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA508: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800AA50C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800AA510: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA514: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x800AA518: swc1        $f10, 0x1E8($t2)
    MEM_W(0X1E8, ctx->r10) = ctx->f10.u32l;
    // 0x800AA51C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800AA520: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AA524: sh          $t6, 0x1E6($t8)
    MEM_H(0X1E6, ctx->r24) = ctx->r14;
    // 0x800AA528: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800AA52C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AA530: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800AA534: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AA538: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800AA53C: jal         0x800AAB5C
    // 0x800AA540: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    hud_element_render(rdram, ctx);
        goto after_51;
    // 0x800AA540: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    after_51:
L_800AA544:
    // 0x800AA544: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AA548: lw          $t5, 0x7320($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7320);
    // 0x800AA54C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800AA550: lb          $t7, 0x4C($t5)
    ctx->r15 = MEM_B(ctx->r13, 0X4C);
    // 0x800AA554: nop

    // 0x800AA558: bne         $t7, $at, L_800AA600
    if (ctx->r15 != ctx->r1) {
        // 0x800AA55C: lw          $v0, 0x140($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X140);
            goto L_800AA600;
    }
    // 0x800AA55C: lw          $v0, 0x140($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X140);
    // 0x800AA560: jal         0x80018CA0
    // 0x800AA564: nop

    find_taj_object(rdram, ctx);
        goto after_52;
    // 0x800AA564: nop

    after_52:
    // 0x800AA568: beq         $v0, $zero, L_800AA5FC
    if (ctx->r2 == 0) {
        // 0x800AA56C: nop
    
            goto L_800AA5FC;
    }
    // 0x800AA56C: nop

    // 0x800AA570: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800AA574: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x800AA578: sh          $t4, 0x1E6($t3)
    MEM_H(0X1E6, ctx->r11) = ctx->r12;
    // 0x800AA57C: lwc1        $f6, 0x11C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800AA580: lw          $a3, 0x118($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X118);
    // 0x800AA584: lw          $a2, 0x114($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X114);
    // 0x800AA588: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AA58C: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AA590: jal         0x800AA948
    // 0x800AA594: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    minimap_marker_pos(rdram, ctx);
        goto after_53;
    // 0x800AA594: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_53:
    // 0x800AA598: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800AA59C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800AA5A0: sh          $zero, 0x1E4($t9)
    MEM_H(0X1E4, ctx->r25) = 0;
    // 0x800AA5A4: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA5A8: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x800AA5AC: addiu       $t2, $t0, 0x8
    ctx->r10 = ADD32(ctx->r8, 0X8);
    // 0x800AA5B0: sw          $t2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r10;
    // 0x800AA5B4: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800AA5B8: lw          $t8, 0x108($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X108);
    // 0x800AA5BC: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x800AA5C0: andi        $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 & 0XFF;
    // 0x800AA5C4: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x800AA5C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA5CC: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800AA5D0: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800AA5D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AA5D8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AA5DC: swc1        $f18, 0x1E8($t4)
    MEM_W(0X1E8, ctx->r12) = ctx->f18.u32l;
    // 0x800AA5E0: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800AA5E4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AA5E8: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800AA5EC: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AA5F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800AA5F4: jal         0x800AAB5C
    // 0x800AA5F8: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    hud_element_render(rdram, ctx);
        goto after_54;
    // 0x800AA5F8: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    after_54:
L_800AA5FC:
    // 0x800AA5FC: lw          $v0, 0x140($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X140);
L_800AA600:
    // 0x800AA600: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x800AA604: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800AA608: bltz        $v0, L_800AA8D0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800AA60C: sll         $s1, $v0, 2
        ctx->r17 = S32(ctx->r2 << 2);
            goto L_800AA8D0;
    }
    // 0x800AA60C: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
    // 0x800AA610: addu        $s0, $t3, $s1
    ctx->r16 = ADD32(ctx->r11, ctx->r17);
L_800AA614:
    // 0x800AA614: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AA618: lw          $a2, 0x114($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X114);
    // 0x800AA61C: lw          $a1, 0x64($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X64);
    // 0x800AA620: lw          $a3, 0x118($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X118);
    // 0x800AA624: beq         $a1, $zero, L_800AA8C4
    if (ctx->r5 == 0) {
        // 0x800AA628: nop
    
            goto L_800AA8C4;
    }
    // 0x800AA628: nop

    // 0x800AA62C: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x800AA630: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AA634: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AA638: lwc1        $f4, 0x11C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800AA63C: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x800AA640: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x800AA644: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    // 0x800AA648: jal         0x800AA948
    // 0x800AA64C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    minimap_marker_pos(rdram, ctx);
        goto after_55;
    // 0x800AA64C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_55:
    // 0x800AA650: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA654: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA658: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x800AA65C: nop

    // 0x800AA660: beq         $s3, $t6, L_800AA700
    if (ctx->r19 == ctx->r14) {
        // 0x800AA664: nop
    
            goto L_800AA700;
    }
    // 0x800AA664: nop

    // 0x800AA668: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800AA66C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AA670: lwc1        $f16, 0x1F0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1F0);
    // 0x800AA674: addiu       $t8, $zero, 0x1B
    ctx->r24 = ADD32(0, 0X1B);
    // 0x800AA678: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800AA67C: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x800AA680: swc1        $f10, 0x1F0($v0)
    MEM_W(0X1F0, ctx->r2) = ctx->f10.u32l;
    // 0x800AA684: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800AA688: nop

    // 0x800AA68C: sh          $t8, 0x1E6($t5)
    MEM_H(0X1E6, ctx->r13) = ctx->r24;
    // 0x800AA690: lw          $t3, 0x158($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X158);
    // 0x800AA694: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800AA698: lhu         $t9, 0x24($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X24);
    // 0x800AA69C: lh          $t4, 0x0($t7)
    ctx->r12 = MEM_H(ctx->r15, 0X0);
    // 0x800AA6A0: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800AA6A4: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x800AA6A8: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x800AA6AC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AA6B0: mflo        $t6
    ctx->r14 = lo;
    // 0x800AA6B4: subu        $t5, $t4, $t6
    ctx->r13 = SUB32(ctx->r12, ctx->r14);
    // 0x800AA6B8: sh          $t5, 0x1E4($t7)
    MEM_H(0X1E4, ctx->r15) = ctx->r13;
    // 0x800AA6BC: jal         0x8009C850
    // 0x800AA6C0: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    get_filtered_cheats(rdram, ctx);
        goto after_56;
    // 0x800AA6C0: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    after_56:
    // 0x800AA6C4: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA6C8: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x800AA6CC: beq         $t3, $zero, L_800AA6EC
    if (ctx->r11 == 0) {
        // 0x800AA6D0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800AA6EC;
    }
    // 0x800AA6D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800AA6D4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800AA6D8: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x800AA6DC: lh          $t9, 0x1E4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X1E4);
    // 0x800AA6E0: nop

    // 0x800AA6E4: subu        $t4, $t2, $t9
    ctx->r12 = SUB32(ctx->r10, ctx->r25);
    // 0x800AA6E8: sh          $t4, 0x1E4($v0)
    MEM_H(0X1E4, ctx->r2) = ctx->r12;
L_800AA6EC:
    // 0x800AA6EC: jal         0x8007C36C
    // 0x800AA6F0: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    sprite_opaque(rdram, ctx);
        goto after_57;
    // 0x800AA6F0: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    after_57:
    // 0x800AA6F4: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA6F8: b           L_800AA718
    // 0x800AA6FC: nop

        goto L_800AA718;
    // 0x800AA6FC: nop

L_800AA700:
    // 0x800AA700: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800AA704: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x800AA708: sh          $zero, 0x1E4($t6)
    MEM_H(0X1E4, ctx->r14) = 0;
    // 0x800AA70C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800AA710: nop

    // 0x800AA714: sh          $t8, 0x1E6($t5)
    MEM_H(0X1E6, ctx->r13) = ctx->r24;
L_800AA718:
    // 0x800AA718: jal         0x80023450
    // 0x800AA71C: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    is_taj_challenge(rdram, ctx);
        goto after_58;
    // 0x800AA71C: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    after_58:
    // 0x800AA720: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA724: beq         $v0, $zero, L_800AA764
    if (ctx->r2 == 0) {
        // 0x800AA728: lui         $t8, 0xFA00
        ctx->r24 = S32(0XFA00 << 16);
            goto L_800AA764;
    }
    // 0x800AA728: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800AA72C: lb          $t7, 0x1D6($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1D6);
    // 0x800AA730: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800AA734: bne         $t7, $at, L_800AA764
    if (ctx->r15 != ctx->r1) {
        // 0x800AA738: lui         $t2, 0xFA00
        ctx->r10 = S32(0XFA00 << 16);
            goto L_800AA764;
    }
    // 0x800AA738: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800AA73C: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA740: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x800AA744: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800AA748: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x800AA74C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800AA750: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800AA754: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x800AA758: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x800AA75C: b           L_800AA7B8
    // 0x800AA760: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
        goto L_800AA7B8;
    // 0x800AA760: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
L_800AA764:
    // 0x800AA764: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA768: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800AA76C: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x800AA770: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800AA774: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800AA778: lb          $t5, 0x3($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X3);
    // 0x800AA77C: addiu       $t3, $t3, 0x2D3C
    ctx->r11 = ADD32(ctx->r11, 0X2D3C);
    // 0x800AA780: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800AA784: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x800AA788: addu        $v0, $t7, $t3
    ctx->r2 = ADD32(ctx->r15, ctx->r11);
    // 0x800AA78C: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x800AA790: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x800AA794: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x800AA798: sll         $t4, $t9, 8
    ctx->r12 = S32(ctx->r25 << 8);
    // 0x800AA79C: sll         $t5, $t8, 24
    ctx->r13 = S32(ctx->r24 << 24);
    // 0x800AA7A0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800AA7A4: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x800AA7A8: sll         $t9, $t2, 16
    ctx->r25 = S32(ctx->r10 << 16);
    // 0x800AA7AC: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x800AA7B0: or          $t4, $t6, $t8
    ctx->r12 = ctx->r14 | ctx->r24;
    // 0x800AA7B4: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
L_800AA7B8:
    // 0x800AA7B8: jal         0x8006BFD8
    // 0x800AA7BC: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    level_type(rdram, ctx);
        goto after_59;
    // 0x800AA7BC: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    after_59:
    // 0x800AA7C0: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA7C4: andi        $t5, $v0, 0x40
    ctx->r13 = ctx->r2 & 0X40;
    // 0x800AA7C8: beq         $t5, $zero, L_800AA7E0
    if (ctx->r13 == 0) {
        // 0x800AA7CC: lui         $t2, 0x8000
        ctx->r10 = S32(0X8000 << 16);
            goto L_800AA7E0;
    }
    // 0x800AA7CC: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800AA7D0: lb          $t3, 0x1D8($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X1D8);
    // 0x800AA7D4: nop

    // 0x800AA7D8: bne         $t3, $zero, L_800AA8BC
    if (ctx->r11 != 0) {
        // 0x800AA7DC: nop
    
            goto L_800AA8BC;
    }
    // 0x800AA7DC: nop

L_800AA7E0:
    // 0x800AA7E0: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x800AA7E4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AA7E8: bne         $t2, $zero, L_800AA808
    if (ctx->r10 != 0) {
        // 0x800AA7EC: nop
    
            goto L_800AA808;
    }
    // 0x800AA7EC: nop

    // 0x800AA7F0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800AA7F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AA7F8: lwc1        $f6, 0x1EC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1EC);
    // 0x800AA7FC: nop

    // 0x800AA800: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800AA804: swc1        $f4, 0x1EC($v0)
    MEM_W(0X1EC, ctx->r2) = ctx->f4.u32l;
L_800AA808:
    // 0x800AA808: jal         0x8006BFD8
    // 0x800AA80C: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    level_type(rdram, ctx);
        goto after_60;
    // 0x800AA80C: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    after_60:
    // 0x800AA810: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA814: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800AA818: bne         $v0, $at, L_800AA88C
    if (ctx->r2 != ctx->r1) {
        // 0x800AA81C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800AA88C;
    }
    // 0x800AA81C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800AA820: lb          $v0, 0x212($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X212);
    // 0x800AA824: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AA828: beq         $v0, $zero, L_800AA854
    if (ctx->r2 == 0) {
        // 0x800AA82C: nop
    
            goto L_800AA854;
    }
    // 0x800AA82C: nop

    // 0x800AA830: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AA834: beq         $v0, $at, L_800AA864
    if (ctx->r2 == ctx->r1) {
        // 0x800AA838: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800AA864;
    }
    // 0x800AA838: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AA83C: beq         $v0, $at, L_800AA878
    if (ctx->r2 == ctx->r1) {
        // 0x800AA840: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AA878;
    }
    // 0x800AA840: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AA844: beq         $v0, $at, L_800AA878
    if (ctx->r2 == ctx->r1) {
        // 0x800AA848: nop
    
            goto L_800AA878;
    }
    // 0x800AA848: nop

    // 0x800AA84C: b           L_800AA8A4
    // 0x800AA850: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
        goto L_800AA8A4;
    // 0x800AA850: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
L_800AA854:
    // 0x800AA854: lwc1        $f16, -0x72B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X72B0);
    // 0x800AA858: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AA85C: b           L_800AA8A0
    // 0x800AA860: swc1        $f16, 0x1E8($t7)
    MEM_W(0X1E8, ctx->r15) = ctx->f16.u32l;
        goto L_800AA8A0;
    // 0x800AA860: swc1        $f16, 0x1E8($t7)
    MEM_W(0X1E8, ctx->r15) = ctx->f16.u32l;
L_800AA864:
    // 0x800AA864: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA868: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AA86C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800AA870: b           L_800AA8A0
    // 0x800AA874: swc1        $f8, 0x1E8($t9)
    MEM_W(0X1E8, ctx->r25) = ctx->f8.u32l;
        goto L_800AA8A0;
    // 0x800AA874: swc1        $f8, 0x1E8($t9)
    MEM_W(0X1E8, ctx->r25) = ctx->f8.u32l;
L_800AA878:
    // 0x800AA878: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AA87C: lwc1        $f10, -0x72AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X72AC);
    // 0x800AA880: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800AA884: b           L_800AA8A0
    // 0x800AA888: swc1        $f10, 0x1E8($t6)
    MEM_W(0X1E8, ctx->r14) = ctx->f10.u32l;
        goto L_800AA8A0;
    // 0x800AA888: swc1        $f10, 0x1E8($t6)
    MEM_W(0X1E8, ctx->r14) = ctx->f10.u32l;
L_800AA88C:
    // 0x800AA88C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA890: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AA894: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800AA898: nop

    // 0x800AA89C: swc1        $f6, 0x1E8($t8)
    MEM_W(0X1E8, ctx->r24) = ctx->f6.u32l;
L_800AA8A0:
    // 0x800AA8A0: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
L_800AA8A4:
    // 0x800AA8A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AA8A8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AA8AC: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800AA8B0: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800AA8B4: jal         0x800AAB5C
    // 0x800AA8B8: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    hud_element_render(rdram, ctx);
        goto after_61;
    // 0x800AA8B8: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    after_61:
L_800AA8BC:
    // 0x800AA8BC: jal         0x8007C36C
    // 0x800AA8C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_62;
    // 0x800AA8C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_62:
L_800AA8C4:
    // 0x800AA8C4: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // 0x800AA8C8: bgez        $s1, L_800AA614
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800AA8CC: addiu       $s0, $s0, -0x4
        ctx->r16 = ADD32(ctx->r16, -0X4);
            goto L_800AA614;
    }
    // 0x800AA8CC: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
L_800AA8D0:
    // 0x800AA8D0: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA8D4: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800AA8D8: addiu       $t4, $t0, 0x8
    ctx->r12 = ADD32(ctx->r8, 0X8);
    // 0x800AA8DC: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x800AA8E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AA8E4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800AA8E8: jal         0x80068748
    // 0x800AA8EC: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_63;
    // 0x800AA8EC: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    after_63:
    // 0x800AA8F0: jal         0x8007C36C
    // 0x800AA8F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_64;
    // 0x800AA8F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_64:
    // 0x800AA8F8: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800AA8FC: lw          $t2, 0x160($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X160);
    // 0x800AA900: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800AA904: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800AA908: lw          $t9, 0x164($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X164);
    // 0x800AA90C: lw          $t7, 0x72C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72C0);
    // 0x800AA910: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800AA914: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800AA918: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x800AA91C: lw          $t6, 0x72C4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72C4);
    // 0x800AA920: nop

    // 0x800AA924: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_800AA928:
    // 0x800AA928: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800AA92C:
    // 0x800AA92C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800AA930: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800AA934: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800AA938: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800AA93C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800AA940: jr          $ra
    // 0x800AA944: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
    return;
    // 0x800AA944: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
;}
RECOMP_FUNC void checkpoint_update_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017ECC: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x80017ED0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80017ED4: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x80017ED8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80017EDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80017EE0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80017EE4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80017EE8: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80017EEC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80017EF0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80017EF4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80017EF8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80017EFC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80017F00: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80017F04: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80017F08: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x80017F0C: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80017F10: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80017F14: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80017F18: sw          $zero, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = 0;
    // 0x80017F1C: blez        $v1, L_8001803C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80017F20: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001803C;
    }
    // 0x80017F20: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80017F24: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80017F28: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80017F2C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80017F30: addiu       $a2, $a2, -0x4C28
    ctx->r6 = ADD32(ctx->r6, -0X4C28);
    // 0x80017F34: addiu       $t1, $t1, -0x4BA8
    ctx->r9 = ADD32(ctx->r9, -0X4BA8);
    // 0x80017F38: addiu       $s4, $s4, -0x4BB4
    ctx->r20 = ADD32(ctx->r20, -0X4BB4);
    // 0x80017F3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017F40: addiu       $t0, $zero, 0xD
    ctx->r8 = ADD32(0, 0XD);
    // 0x80017F44: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
L_80017F48:
    // 0x80017F48: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80017F4C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80017F50: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80017F54: lw          $s0, 0x0($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X0);
    // 0x80017F58: nop

    // 0x80017F5C: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x80017F60: nop

    // 0x80017F64: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80017F68: bne         $t9, $zero, L_80018034
    if (ctx->r25 != 0) {
        // 0x80017F6C: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80018034;
    }
    // 0x80017F6C: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80017F70: lh          $t3, 0x48($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X48);
    // 0x80017F74: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80017F78: bne         $t0, $t3, L_80018034
    if (ctx->r8 != ctx->r11) {
        // 0x80017F7C: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80018034;
    }
    // 0x80017F7C: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80017F80: lw          $a3, -0x4BB0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB0);
    // 0x80017F84: nop

    // 0x80017F88: slti        $at, $a3, 0x3C
    ctx->r1 = SIGNED(ctx->r7) < 0X3C ? 1 : 0;
    // 0x80017F8C: beq         $at, $zero, L_80018034
    if (ctx->r1 == 0) {
        // 0x80017F90: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80018034;
    }
    // 0x80017F90: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80017F94: lw          $s7, 0x3C($s0)
    ctx->r23 = MEM_W(ctx->r16, 0X3C);
    // 0x80017F98: lh          $t4, 0x0($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X0);
    // 0x80017F9C: lb          $t5, 0x1A($s7)
    ctx->r13 = MEM_B(ctx->r23, 0X1A);
    // 0x80017FA0: nop

    // 0x80017FA4: bne         $t4, $t5, L_80018034
    if (ctx->r12 != ctx->r13) {
        // 0x80017FA8: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80018034;
    }
    // 0x80017FA8: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80017FAC: multu       $a3, $a1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80017FB0: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80017FB4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80017FB8: addiu       $a3, $a3, -0x4BB0
    ctx->r7 = ADD32(ctx->r7, -0X4BB0);
    // 0x80017FBC: mflo        $t7
    ctx->r15 = lo;
    // 0x80017FC0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80017FC4: sw          $s0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r16;
    // 0x80017FC8: lbu         $t9, 0x17($s7)
    ctx->r25 = MEM_BU(ctx->r23, 0X17);
    // 0x80017FCC: lbu         $a0, 0x9($s7)
    ctx->r4 = MEM_BU(ctx->r23, 0X9);
    // 0x80017FD0: beq         $t9, $zero, L_80017FE0
    if (ctx->r25 == 0) {
        // 0x80017FD4: nop
    
            goto L_80017FE0;
    }
    // 0x80017FD4: nop

    // 0x80017FD8: addiu       $a0, $a0, 0xFF
    ctx->r4 = ADD32(ctx->r4, 0XFF);
    // 0x80017FDC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80017FE0:
    // 0x80017FE0: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80017FE4: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80017FE8: multu       $t4, $a1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80017FEC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80017FF0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80017FF4: mflo        $t5
    ctx->r13 = lo;
    // 0x80017FF8: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80017FFC: sh          $a0, 0x2C($t6)
    MEM_H(0X2C, ctx->r14) = ctx->r4;
    // 0x80018000: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80018004: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80018008: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001800C: mflo        $t4
    ctx->r12 = lo;
    // 0x80018010: addu        $t3, $t8, $t4
    ctx->r11 = ADD32(ctx->r24, ctx->r12);
    // 0x80018014: sb          $t7, 0x3A($t3)
    MEM_B(0X3A, ctx->r11) = ctx->r15;
    // 0x80018018: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8001801C: nop

    // 0x80018020: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80018024: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80018028: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x8001802C: nop

    // 0x80018030: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
L_80018034:
    // 0x80018034: bne         $at, $zero, L_80017F48
    if (ctx->r1 != 0) {
        // 0x80018038: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80017F48;
    }
    // 0x80018038: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8001803C:
    // 0x8001803C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80018040: lw          $a3, -0x4BB0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB0);
    // 0x80018044: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80018048: lw          $s2, 0x104($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X104);
    // 0x8001804C: addiu       $s4, $s4, -0x4BB4
    ctx->r20 = ADD32(ctx->r20, -0X4BB4);
    // 0x80018050: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80018054: addiu       $a2, $a3, -0x1
    ctx->r6 = ADD32(ctx->r7, -0X1);
    // 0x80018058: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001805C:
    // 0x8001805C: blez        $a2, L_800180EC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80018060: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800180EC;
    }
    // 0x80018060: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80018064: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80018068:
    // 0x80018068: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8001806C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80018070: addu        $v0, $t9, $s1
    ctx->r2 = ADD32(ctx->r25, ctx->r17);
    // 0x80018074: lh          $v1, 0x2C($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2C);
    // 0x80018078: lh          $a0, 0x68($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X68);
    // 0x8001807C: nop

    // 0x80018080: bne         $v1, $a0, L_80018090
    if (ctx->r3 != ctx->r4) {
        // 0x80018084: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80018090;
    }
    // 0x80018084: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80018088: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001808C: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
L_80018090:
    // 0x80018090: beq         $at, $zero, L_800180E4
    if (ctx->r1 == 0) {
        // 0x80018094: slt         $at, $s3, $a2
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800180E4;
    }
    // 0x80018094: slt         $at, $s3, $a2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80018098: sh          $a0, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r4;
    // 0x8001809C: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800180A0: lw          $s0, 0x28($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X28);
    // 0x800180A4: addu        $v0, $t8, $s1
    ctx->r2 = ADD32(ctx->r24, ctx->r17);
    // 0x800180A8: lw          $t4, 0x64($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X64);
    // 0x800180AC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800180B0: sw          $t4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r12;
    // 0x800180B4: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800180B8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800180BC: addu        $t3, $t7, $s1
    ctx->r11 = ADD32(ctx->r15, ctx->r17);
    // 0x800180C0: sh          $v1, 0x68($t3)
    MEM_H(0X68, ctx->r11) = ctx->r3;
    // 0x800180C4: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800180C8: nop

    // 0x800180CC: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800180D0: sw          $s0, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->r16;
    // 0x800180D4: lw          $a3, -0x4BB0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB0);
    // 0x800180D8: nop

    // 0x800180DC: addiu       $a2, $a3, -0x1
    ctx->r6 = ADD32(ctx->r7, -0X1);
    // 0x800180E0: slt         $at, $s3, $a2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r6) ? 1 : 0;
L_800180E4:
    // 0x800180E4: bne         $at, $zero, L_80018068
    if (ctx->r1 != 0) {
        // 0x800180E8: addiu       $s1, $s1, 0x3C
        ctx->r17 = ADD32(ctx->r17, 0X3C);
            goto L_80018068;
    }
    // 0x800180E8: addiu       $s1, $s1, 0x3C
    ctx->r17 = ADD32(ctx->r17, 0X3C);
L_800180EC:
    // 0x800180EC: beq         $t0, $zero, L_8001805C
    if (ctx->r8 == 0) {
        // 0x800180F0: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8001805C;
    }
    // 0x800180F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800180F4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800180F8: addiu       $t0, $t0, -0x4BAC
    ctx->r8 = ADD32(ctx->r8, -0X4BAC);
    // 0x800180FC: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x80018100: subu        $t9, $a3, $t2
    ctx->r25 = SUB32(ctx->r7, ctx->r10);
    // 0x80018104: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80018108: beq         $t1, $zero, L_80018134
    if (ctx->r9 == 0) {
        // 0x8001810C: sw          $t9, -0x4BB0($at)
        MEM_W(-0X4BB0, ctx->r1) = ctx->r25;
            goto L_80018134;
    }
    // 0x8001810C: sw          $t9, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = ctx->r25;
    // 0x80018110: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80018114: jal         0x800B68BC
    // 0x80018118: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    set_render_printf_position(rdram, ctx);
        goto after_0;
    // 0x80018118: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    after_0:
    // 0x8001811C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80018120: addiu       $a0, $a0, 0x5664
    ctx->r4 = ADD32(ctx->r4, 0X5664);
    // 0x80018124: jal         0x800B643C
    // 0x80018128: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    render_printf(rdram, ctx);
        goto after_1;
    // 0x80018128: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x8001812C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80018130: addiu       $t0, $t0, -0x4BAC
    ctx->r8 = ADD32(ctx->r8, -0X4BAC);
L_80018134:
    // 0x80018134: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80018138: lw          $a3, -0x4BB0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB0);
    // 0x8001813C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80018140: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x80018144: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80018148: beq         $at, $zero, L_800181E4
    if (ctx->r1 == 0) {
        // 0x8001814C: sll         $s1, $a3, 4
        ctx->r17 = S32(ctx->r7 << 4);
            goto L_800181E4;
    }
    // 0x8001814C: sll         $s1, $a3, 4
    ctx->r17 = S32(ctx->r7 << 4);
    // 0x80018150: subu        $s1, $s1, $a3
    ctx->r17 = SUB32(ctx->r17, ctx->r7);
    // 0x80018154: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
L_80018158:
    // 0x80018158: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8001815C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018160: addu        $t4, $t8, $s1
    ctx->r12 = ADD32(ctx->r24, ctx->r17);
    // 0x80018164: lh          $a1, 0x2C($t4)
    ctx->r5 = MEM_H(ctx->r12, 0X2C);
    // 0x80018168: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001816C: blez        $a3, L_800181D0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80018170: addiu       $a1, $a1, -0xFF
        ctx->r5 = ADD32(ctx->r5, -0XFF);
            goto L_800181D0;
    }
    // 0x80018170: addiu       $a1, $a1, -0xFF
    ctx->r5 = ADD32(ctx->r5, -0XFF);
    // 0x80018174: sll         $v0, $zero, 4
    ctx->r2 = S32(0 << 4);
    // 0x80018178: subu        $v0, $v0, $zero
    ctx->r2 = SUB32(ctx->r2, 0);
    // 0x8001817C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_80018180:
    // 0x80018180: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80018184: nop

    // 0x80018188: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x8001818C: lh          $t3, 0x2C($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2C);
    // 0x80018190: nop

    // 0x80018194: bne         $a1, $t3, L_800181B8
    if (ctx->r5 != ctx->r11) {
        // 0x80018198: nop
    
            goto L_800181B8;
    }
    // 0x80018198: nop

    // 0x8001819C: sb          $s3, 0x3A($v1)
    MEM_B(0X3A, ctx->r3) = ctx->r19;
    // 0x800181A0: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800181A4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800181A8: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800181AC: sb          $a0, 0x3A($t6)
    MEM_B(0X3A, ctx->r14) = ctx->r4;
    // 0x800181B0: lw          $a3, -0x4BB0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB0);
    // 0x800181B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800181B8:
    // 0x800181B8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800181BC: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800181C0: beq         $at, $zero, L_800181D0
    if (ctx->r1 == 0) {
        // 0x800181C4: addiu       $v0, $v0, 0x3C
        ctx->r2 = ADD32(ctx->r2, 0X3C);
            goto L_800181D0;
    }
    // 0x800181C4: addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // 0x800181C8: beq         $a2, $zero, L_80018180
    if (ctx->r6 == 0) {
        // 0x800181CC: nop
    
            goto L_80018180;
    }
    // 0x800181CC: nop

L_800181D0:
    // 0x800181D0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800181D4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800181D8: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800181DC: bne         $at, $zero, L_80018158
    if (ctx->r1 != 0) {
        // 0x800181E0: addiu       $s1, $s1, 0x3C
        ctx->r17 = ADD32(ctx->r17, 0X3C);
            goto L_80018158;
    }
    // 0x800181E0: addiu       $s1, $s1, 0x3C
    ctx->r17 = ADD32(ctx->r17, 0X3C);
L_800181E4:
    // 0x800181E4: blez        $v0, L_800185D8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800181E8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800185D8;
    }
    // 0x800181E8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800181EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800181F0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800181F4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800181F8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800181FC:
    // 0x800181FC: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80018200: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x80018204: addu        $s2, $s1, $t9
    ctx->r18 = ADD32(ctx->r17, ctx->r25);
    // 0x80018208: lw          $s0, 0x28($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X28);
    // 0x8001820C: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x80018210: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x80018214: lw          $s7, 0x3C($s0)
    ctx->r23 = MEM_W(ctx->r16, 0X3C);
    // 0x80018218: sh          $t8, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r24;
    // 0x8001821C: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80018220: nop

    // 0x80018224: sh          $t4, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r12;
    // 0x80018228: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x8001822C: swc1        $f22, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f22.u32l;
    // 0x80018230: swc1        $f20, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f20.u32l;
    // 0x80018234: swc1        $f20, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f20.u32l;
    // 0x80018238: swc1        $f20, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f20.u32l;
    // 0x8001823C: jal         0x8006FE70
    // 0x80018240: sh          $t7, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r15;
    mtxf_from_transform(rdram, ctx);
        goto after_2;
    // 0x80018240: sh          $t7, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r15;
    after_2:
    // 0x80018244: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80018248: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001824C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80018250: addiu       $t3, $sp, 0xE8
    ctx->r11 = ADD32(ctx->r29, 0XE8);
    // 0x80018254: addiu       $t5, $sp, 0xE4
    ctx->r13 = ADD32(ctx->r29, 0XE4);
    // 0x80018258: addiu       $t6, $sp, 0xE0
    ctx->r14 = ADD32(ctx->r29, 0XE0);
    // 0x8001825C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80018260: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80018264: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80018268: jal         0x8006F88C
    // 0x8001826C: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    mtxf_transform_point(rdram, ctx);
        goto after_3;
    // 0x8001826C: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    after_3:
    // 0x80018270: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80018274: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80018278: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x8001827C: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80018280: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80018284: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x80018288: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8001828C: addiu       $t4, $s3, 0x1
    ctx->r12 = ADD32(ctx->r19, 0X1);
    // 0x80018290: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
    // 0x80018294: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80018298: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x8001829C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800182A0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800182A4: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800182A8: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800182AC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800182B0: lwc1        $f4, 0xE0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800182B4: nop

    // 0x800182B8: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800182BC: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800182C0: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800182C4: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x800182C8: swc1        $f8, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f8.u32l;
    // 0x800182CC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800182D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800182D4: swc1        $f16, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f16.u32l;
    // 0x800182D8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800182DC: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800182E0: swc1        $f4, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f4.u32l;
    // 0x800182E4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800182E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800182EC: swc1        $f10, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f10.u32l;
    // 0x800182F0: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800182F4: nop

    // 0x800182F8: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800182FC: swc1        $f8, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f8.u32l;
    // 0x80018300: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80018304: swc1        $f20, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f20.u32l;
    // 0x80018308: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8001830C: swc1        $f20, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f20.u32l;
    // 0x80018310: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80018314: nop

    // 0x80018318: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001831C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80018320: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80018324: nop

    // 0x80018328: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001832C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80018330: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80018334: sh          $t8, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r24;
    // 0x80018338: lw          $a3, -0x4BB0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB0);
    // 0x8001833C: nop

    // 0x80018340: slt         $at, $s3, $a3
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80018344: beq         $at, $zero, L_80018430
    if (ctx->r1 == 0) {
        // 0x80018348: nop
    
            goto L_80018430;
    }
    // 0x80018348: nop

    // 0x8001834C: addiu       $fp, $s3, 0x1
    ctx->r30 = ADD32(ctx->r19, 0X1);
    // 0x80018350: bne         $t4, $a3, L_8001835C
    if (ctx->r12 != ctx->r7) {
        // 0x80018354: or          $a1, $fp, $zero
        ctx->r5 = ctx->r30 | 0;
            goto L_8001835C;
    }
    // 0x80018354: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80018358: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001835C:
    // 0x8001835C: sll         $s6, $a1, 4
    ctx->r22 = S32(ctx->r5 << 4);
    // 0x80018360: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80018364: subu        $s6, $s6, $a1
    ctx->r22 = SUB32(ctx->r22, ctx->r5);
    // 0x80018368: sll         $s6, $s6, 2
    ctx->r22 = S32(ctx->r22 << 2);
    // 0x8001836C: addu        $t3, $t7, $s6
    ctx->r11 = ADD32(ctx->r15, ctx->r22);
    // 0x80018370: lw          $v0, 0x28($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X28);
    // 0x80018374: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80018378: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001837C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80018380: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80018384: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80018388: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001838C: sub.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80018390: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80018394: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80018398: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001839C: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800183A0: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800183A4: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800183A8: jal         0x800CA030
    // 0x800183AC: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x800183AC: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    after_4:
    // 0x800183B0: swc1        $f0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f0.u32l;
    // 0x800183B4: lw          $s5, 0x0($s4)
    ctx->r21 = MEM_W(ctx->r20, 0X0);
    // 0x800183B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800183BC: addu        $t5, $s5, $s6
    ctx->r13 = ADD32(ctx->r21, ctx->r22);
    // 0x800183C0: lb          $v1, 0x3A($t5)
    ctx->r3 = MEM_B(ctx->r13, 0X3A);
    // 0x800183C4: nop

    // 0x800183C8: beq         $v1, $at, L_80018424
    if (ctx->r3 == ctx->r1) {
        // 0x800183CC: sll         $t6, $v1, 4
        ctx->r14 = S32(ctx->r3 << 4);
            goto L_80018424;
    }
    // 0x800183CC: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x800183D0: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x800183D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800183D8: addu        $t9, $s5, $t6
    ctx->r25 = ADD32(ctx->r21, ctx->r14);
    // 0x800183DC: lw          $v0, 0x28($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X28);
    // 0x800183E0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800183E4: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800183E8: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800183EC: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800183F0: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800183F4: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800183F8: sub.s       $f2, $f18, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800183FC: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80018400: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80018404: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80018408: sub.s       $f14, $f16, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8001840C: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80018410: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80018414: jal         0x800CA030
    // 0x80018418: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x80018418: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    after_5:
    // 0x8001841C: b           L_80018528
    // 0x80018420: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
        goto L_80018528;
    // 0x80018420: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
L_80018424:
    // 0x80018424: lwc1        $f16, 0x20($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X20);
    // 0x80018428: b           L_80018528
    // 0x8001842C: swc1        $f16, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f16.u32l;
        goto L_80018528;
    // 0x8001842C: swc1        $f16, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f16.u32l;
L_80018430:
    // 0x80018430: lw          $s5, 0x0($s4)
    ctx->r21 = MEM_W(ctx->r20, 0X0);
    // 0x80018434: nop

    // 0x80018438: addu        $t8, $s5, $s1
    ctx->r24 = ADD32(ctx->r21, ctx->r17);
    // 0x8001843C: lb          $a1, 0x3A($t8)
    ctx->r5 = MEM_B(ctx->r24, 0X3A);
    // 0x80018440: nop

    // 0x80018444: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80018448: bne         $a1, $a3, L_80018458
    if (ctx->r5 != ctx->r7) {
        // 0x8001844C: sll         $s6, $a1, 4
        ctx->r22 = S32(ctx->r5 << 4);
            goto L_80018458;
    }
    // 0x8001844C: sll         $s6, $a1, 4
    ctx->r22 = S32(ctx->r5 << 4);
    // 0x80018450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018454: sll         $s6, $a1, 4
    ctx->r22 = S32(ctx->r5 << 4);
L_80018458:
    // 0x80018458: subu        $s6, $s6, $a1
    ctx->r22 = SUB32(ctx->r22, ctx->r5);
    // 0x8001845C: sll         $s6, $s6, 2
    ctx->r22 = S32(ctx->r22 << 2);
    // 0x80018460: addu        $t4, $s5, $s6
    ctx->r12 = ADD32(ctx->r21, ctx->r22);
    // 0x80018464: lw          $v0, 0x28($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X28);
    // 0x80018468: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8001846C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80018470: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80018474: sub.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80018478: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001847C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80018480: sub.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80018484: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80018488: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001848C: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80018490: sub.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80018494: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80018498: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001849C: jal         0x800CA030
    // 0x800184A0: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x800184A0: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_6:
    // 0x800184A4: swc1        $f0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f0.u32l;
    // 0x800184A8: lw          $s5, 0x0($s4)
    ctx->r21 = MEM_W(ctx->r20, 0X0);
    // 0x800184AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800184B0: addu        $t7, $s5, $s6
    ctx->r15 = ADD32(ctx->r21, ctx->r22);
    // 0x800184B4: lb          $v1, 0x3A($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X3A);
    // 0x800184B8: nop

    // 0x800184BC: beq         $v1, $at, L_8001851C
    if (ctx->r3 == ctx->r1) {
        // 0x800184C0: sll         $t3, $v1, 4
        ctx->r11 = S32(ctx->r3 << 4);
            goto L_8001851C;
    }
    // 0x800184C0: sll         $t3, $v1, 4
    ctx->r11 = S32(ctx->r3 << 4);
    // 0x800184C4: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x800184C8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800184CC: addu        $t5, $s5, $t3
    ctx->r13 = ADD32(ctx->r21, ctx->r11);
    // 0x800184D0: lw          $v0, 0x28($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X28);
    // 0x800184D4: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800184D8: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800184DC: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800184E0: sub.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800184E4: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800184E8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800184EC: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800184F0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800184F4: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800184F8: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800184FC: sub.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80018500: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80018504: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80018508: jal         0x800CA030
    // 0x8001850C: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x8001850C: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_7:
    // 0x80018510: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
    // 0x80018514: b           L_80018528
    // 0x80018518: addiu       $fp, $s3, 0x1
    ctx->r30 = ADD32(ctx->r19, 0X1);
        goto L_80018528;
    // 0x80018518: addiu       $fp, $s3, 0x1
    ctx->r30 = ADD32(ctx->r19, 0X1);
L_8001851C:
    // 0x8001851C: lwc1        $f6, 0x20($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X20);
    // 0x80018520: addiu       $fp, $s3, 0x1
    ctx->r30 = ADD32(ctx->r19, 0X1);
    // 0x80018524: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
L_80018528:
    // 0x80018528: lb          $t6, 0xB($s7)
    ctx->r14 = MEM_B(ctx->r23, 0XB);
    // 0x8001852C: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x80018530: sb          $t6, 0x2E($s2)
    MEM_B(0X2E, ctx->r18) = ctx->r14;
    // 0x80018534: lb          $t9, 0xF($s7)
    ctx->r25 = MEM_B(ctx->r23, 0XF);
    // 0x80018538: addiu       $s1, $s1, 0x3C
    ctx->r17 = ADD32(ctx->r17, 0X3C);
    // 0x8001853C: sb          $t9, 0x32($s2)
    MEM_B(0X32, ctx->r18) = ctx->r25;
    // 0x80018540: lb          $t8, 0x13($s7)
    ctx->r24 = MEM_B(ctx->r23, 0X13);
    // 0x80018544: nop

    // 0x80018548: sb          $t8, 0x36($s2)
    MEM_B(0X36, ctx->r18) = ctx->r24;
    // 0x8001854C: lb          $t4, 0xC($s7)
    ctx->r12 = MEM_B(ctx->r23, 0XC);
    // 0x80018550: nop

    // 0x80018554: sb          $t4, 0x2F($s2)
    MEM_B(0X2F, ctx->r18) = ctx->r12;
    // 0x80018558: lb          $t7, 0x10($s7)
    ctx->r15 = MEM_B(ctx->r23, 0X10);
    // 0x8001855C: nop

    // 0x80018560: sb          $t7, 0x33($s2)
    MEM_B(0X33, ctx->r18) = ctx->r15;
    // 0x80018564: lb          $t3, 0x14($s7)
    ctx->r11 = MEM_B(ctx->r23, 0X14);
    // 0x80018568: nop

    // 0x8001856C: sb          $t3, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r11;
    // 0x80018570: lb          $t5, 0xD($s7)
    ctx->r13 = MEM_B(ctx->r23, 0XD);
    // 0x80018574: nop

    // 0x80018578: sb          $t5, 0x30($s2)
    MEM_B(0X30, ctx->r18) = ctx->r13;
    // 0x8001857C: lb          $t6, 0x11($s7)
    ctx->r14 = MEM_B(ctx->r23, 0X11);
    // 0x80018580: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80018584: sb          $t6, 0x34($s2)
    MEM_B(0X34, ctx->r18) = ctx->r14;
    // 0x80018588: lb          $t9, 0x15($s7)
    ctx->r25 = MEM_B(ctx->r23, 0X15);
    // 0x8001858C: nop

    // 0x80018590: sb          $t9, 0x38($s2)
    MEM_B(0X38, ctx->r18) = ctx->r25;
    // 0x80018594: lb          $t8, 0xE($s7)
    ctx->r24 = MEM_B(ctx->r23, 0XE);
    // 0x80018598: nop

    // 0x8001859C: sb          $t8, 0x31($s2)
    MEM_B(0X31, ctx->r18) = ctx->r24;
    // 0x800185A0: lb          $t4, 0x12($s7)
    ctx->r12 = MEM_B(ctx->r23, 0X12);
    // 0x800185A4: nop

    // 0x800185A8: sb          $t4, 0x35($s2)
    MEM_B(0X35, ctx->r18) = ctx->r12;
    // 0x800185AC: lb          $t7, 0x16($s7)
    ctx->r15 = MEM_B(ctx->r23, 0X16);
    // 0x800185B0: nop

    // 0x800185B4: sb          $t7, 0x39($s2)
    MEM_B(0X39, ctx->r18) = ctx->r15;
    // 0x800185B8: lbu         $t3, 0x19($s7)
    ctx->r11 = MEM_BU(ctx->r23, 0X19);
    // 0x800185BC: nop

    // 0x800185C0: sb          $t3, 0x3B($s2)
    MEM_B(0X3B, ctx->r18) = ctx->r11;
    // 0x800185C4: lw          $t5, -0x4BAC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4BAC);
    // 0x800185C8: nop

    // 0x800185CC: slt         $at, $fp, $t5
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800185D0: bne         $at, $zero, L_800181FC
    if (ctx->r1 != 0) {
        // 0x800185D4: nop
    
            goto L_800181FC;
    }
    // 0x800185D4: nop

L_800185D8:
    // 0x800185D8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800185DC: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800185E0: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800185E4: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800185E8: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800185EC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800185F0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800185F4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800185F8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800185FC: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80018600: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80018604: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80018608: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8001860C: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80018610: jr          $ra
    // 0x80018614: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x80018614: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void trackmenu_track_view(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800909A0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800909A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800909A8: jal         0x800C7950
    // 0x800909AC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    bgload_tick(rdram, ctx);
        goto after_0;
    // 0x800909AC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x800909B0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800909B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800909B8: blez        $a1, L_80090BBC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800909BC: andi        $v1, $a1, 0x3
        ctx->r3 = ctx->r5 & 0X3;
            goto L_80090BBC;
    }
    // 0x800909BC: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800909C0: beq         $v1, $zero, L_80090A88
    if (ctx->r3 == 0) {
        // 0x800909C4: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80090A88;
    }
    // 0x800909C4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800909C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800909CC: lwc1        $f14, 0x6FA8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6FA8);
    // 0x800909D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800909D4: lwc1        $f16, 0x6FAC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6FAC);
    // 0x800909D8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800909DC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800909E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800909E4: lwc1        $f1, -0x7590($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7590);
    // 0x800909E8: lwc1        $f0, -0x758C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X758C);
    // 0x800909EC: addiu       $v1, $v1, 0x6F9C
    ctx->r3 = ADD32(ctx->r3, 0X6F9C);
    // 0x800909F0: addiu       $t0, $t0, 0x6FA4
    ctx->r8 = ADD32(ctx->r8, 0X6FA4);
    // 0x800909F4: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800909F8: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800909FC: sub.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x80090A00: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80090A04: cvt.d.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.d = CVT_D_S(ctx->f4.fl);
    // 0x80090A08: mul.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80090A0C: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80090A10: cvt.d.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.d = CVT_D_S(ctx->f6.fl);
    // 0x80090A14: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x80090A18: beq         $a0, $v0, L_80090A68
    if (ctx->r4 == ctx->r2) {
        // 0x80090A1C: cvt.d.s     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
            goto L_80090A68;
    }
    // 0x80090A1C: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
L_80090A20:
    // 0x80090A20: mul.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80090A24: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80090A28: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80090A2C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80090A30: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80090A34: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80090A38: add.d       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f4.d + ctx->f8.d;
    // 0x80090A3C: cvt.s.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f8.fl = CVT_S_D(ctx->f8.d);
    // 0x80090A40: sub.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x80090A44: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x80090A48: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80090A4C: cvt.d.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.d = CVT_D_S(ctx->f4.fl);
    // 0x80090A50: mul.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80090A54: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80090A58: cvt.d.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.d = CVT_D_S(ctx->f6.fl);
    // 0x80090A5C: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x80090A60: bne         $a0, $v0, L_80090A20
    if (ctx->r4 != ctx->r2) {
        // 0x80090A64: cvt.d.s     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
            goto L_80090A20;
    }
    // 0x80090A64: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
L_80090A68:
    // 0x80090A68: mul.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80090A6C: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80090A70: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80090A74: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80090A78: add.d       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f4.d + ctx->f8.d;
    // 0x80090A7C: cvt.s.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f8.fl = CVT_S_D(ctx->f8.d);
    // 0x80090A80: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x80090A84: beq         $v0, $a1, L_80090BBC
    if (ctx->r2 == ctx->r5) {
        // 0x80090A88: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_80090BBC;
    }
L_80090A88:
    // 0x80090A88: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80090A8C: lwc1        $f1, -0x7588($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7588);
    // 0x80090A90: lwc1        $f0, -0x7584($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7584);
    // 0x80090A94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090A98: lwc1        $f14, 0x6FA8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6FA8);
    // 0x80090A9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090AA0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80090AA4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80090AA8: lwc1        $f16, 0x6FAC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6FAC);
    // 0x80090AAC: addiu       $t0, $t0, 0x6FA4
    ctx->r8 = ADD32(ctx->r8, 0X6FA4);
    // 0x80090AB0: addiu       $v1, $v1, 0x6F9C
    ctx->r3 = ADD32(ctx->r3, 0X6F9C);
L_80090AB4:
    // 0x80090AB4: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80090AB8: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80090ABC: sub.s       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x80090AC0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80090AC4: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80090AC8: cvt.d.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.d = CVT_D_S(ctx->f10.fl);
    // 0x80090ACC: mul.d       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80090AD0: cvt.d.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.d = CVT_D_S(ctx->f18.fl);
    // 0x80090AD4: cvt.d.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.d = CVT_D_S(ctx->f8.fl);
    // 0x80090AD8: cvt.d.s     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.d = CVT_D_S(ctx->f12.fl);
    // 0x80090ADC: mul.d       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80090AE0: add.d       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f18.d + ctx->f10.d;
    // 0x80090AE4: cvt.s.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f10.fl = CVT_S_D(ctx->f10.d);
    // 0x80090AE8: add.d       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f12.d + ctx->f8.d;
    // 0x80090AEC: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80090AF0: cvt.s.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f8.fl = CVT_S_D(ctx->f8.d);
    // 0x80090AF4: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80090AF8: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x80090AFC: sub.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x80090B00: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80090B04: cvt.d.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.d = CVT_D_S(ctx->f8.fl);
    // 0x80090B08: mul.d       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80090B0C: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80090B10: cvt.d.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.d = CVT_D_S(ctx->f10.fl);
    // 0x80090B14: add.d       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f10.d + ctx->f8.d;
    // 0x80090B18: cvt.s.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f8.fl = CVT_S_D(ctx->f8.d);
    // 0x80090B1C: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x80090B20: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80090B24: cvt.d.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.d = CVT_D_S(ctx->f18.fl);
    // 0x80090B28: mul.d       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80090B2C: sub.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x80090B30: cvt.d.s     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.d = CVT_D_S(ctx->f12.fl);
    // 0x80090B34: add.d       $f18, $f12, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f12.d + ctx->f18.d;
    // 0x80090B38: cvt.s.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f18.fl = CVT_S_D(ctx->f18.d);
    // 0x80090B3C: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x80090B40: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80090B44: cvt.d.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.d = CVT_D_S(ctx->f10.fl);
    // 0x80090B48: mul.d       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80090B4C: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80090B50: cvt.d.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.d = CVT_D_S(ctx->f8.fl);
    // 0x80090B54: add.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d + ctx->f10.d;
    // 0x80090B58: cvt.s.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f10.fl = CVT_S_D(ctx->f10.d);
    // 0x80090B5C: cvt.d.s     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.d = CVT_D_S(ctx->f12.fl);
    // 0x80090B60: mul.d       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f0.d);
    // 0x80090B64: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80090B68: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80090B6C: cvt.d.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.d = CVT_D_S(ctx->f18.fl);
    // 0x80090B70: add.d       $f12, $f18, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f12.d = ctx->f18.d + ctx->f12.d;
    // 0x80090B74: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    // 0x80090B78: sub.s       $f18, $f14, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x80090B7C: swc1        $f12, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f12.u32l;
    // 0x80090B80: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80090B84: cvt.d.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.d = CVT_D_S(ctx->f18.fl);
    // 0x80090B88: mul.d       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80090B8C: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80090B90: cvt.d.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.d = CVT_D_S(ctx->f10.fl);
    // 0x80090B94: add.d       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f10.d + ctx->f18.d;
    // 0x80090B98: cvt.s.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f18.fl = CVT_S_D(ctx->f18.d);
    // 0x80090B9C: cvt.d.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.d = CVT_D_S(ctx->f8.fl);
    // 0x80090BA0: mul.d       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80090BA4: cvt.d.s     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.d = CVT_D_S(ctx->f12.fl);
    // 0x80090BA8: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x80090BAC: add.d       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f12.d + ctx->f8.d;
    // 0x80090BB0: cvt.s.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f8.fl = CVT_S_D(ctx->f8.d);
    // 0x80090BB4: bne         $v0, $a1, L_80090AB4
    if (ctx->r2 != ctx->r5) {
        // 0x80090BB8: swc1        $f8, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
            goto L_80090AB4;
    }
    // 0x80090BB8: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
L_80090BBC:
    // 0x80090BBC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80090BC0: lw          $t6, 0x6978($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6978);
    // 0x80090BC4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80090BC8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80090BCC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80090BD0: addiu       $t0, $t0, 0x6FA4
    ctx->r8 = ADD32(ctx->r8, 0X6FA4);
    // 0x80090BD4: bne         $t6, $at, L_80090CA8
    if (ctx->r14 != ctx->r1) {
        // 0x80090BD8: addiu       $v1, $v1, 0x6F9C
        ctx->r3 = ADD32(ctx->r3, 0X6F9C);
            goto L_80090CA8;
    }
    // 0x80090BD8: addiu       $v1, $v1, 0x6F9C
    ctx->r3 = ADD32(ctx->r3, 0X6F9C);
    // 0x80090BDC: jal         0x800C7940
    // 0x80090BE0: nop

    bgload_active(rdram, ctx);
        goto after_1;
    // 0x80090BE0: nop

    after_1:
    // 0x80090BE4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80090BE8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80090BEC: addiu       $t0, $t0, 0x6FA4
    ctx->r8 = ADD32(ctx->r8, 0X6FA4);
    // 0x80090BF0: bne         $v0, $zero, L_80090CA8
    if (ctx->r2 != 0) {
        // 0x80090BF4: addiu       $v1, $v1, 0x6F9C
        ctx->r3 = ADD32(ctx->r3, 0X6F9C);
            goto L_80090CA8;
    }
    // 0x80090BF4: addiu       $v1, $v1, 0x6F9C
    ctx->r3 = ADD32(ctx->r3, 0X6F9C);
    // 0x80090BF8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80090BFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80090C00: lw          $a0, -0x5BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5BC);
    // 0x80090C04: lw          $v0, 0x6970($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6970);
    // 0x80090C08: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80090C0C: bne         $v0, $a0, L_80090C30
    if (ctx->r2 != ctx->r4) {
        // 0x80090C10: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80090C30;
    }
    // 0x80090C10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090C14: lw          $t7, 0x6F88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6F88);
    // 0x80090C18: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80090C1C: lw          $t8, 0x6F8C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6F8C);
    // 0x80090C20: sw          $t7, 0x6FB4($at)
    MEM_W(0X6FB4, ctx->r1) = ctx->r15;
    // 0x80090C24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090C28: b           L_80090CA8
    // 0x80090C2C: sw          $t8, 0x6FB8($at)
    MEM_W(0X6FB8, ctx->r1) = ctx->r24;
        goto L_80090CA8;
    // 0x80090C2C: sw          $t8, 0x6FB8($at)
    MEM_W(0X6FB8, ctx->r1) = ctx->r24;
L_80090C30:
    // 0x80090C30: beq         $v0, $a0, L_80090CA8
    if (ctx->r2 == ctx->r4) {
        // 0x80090C34: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80090CA8;
    }
    // 0x80090C34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80090C38: beq         $a0, $at, L_80090CA8
    if (ctx->r4 == ctx->r1) {
        // 0x80090C3C: nop
    
            goto L_80090CA8;
    }
    // 0x80090C3C: nop

    // 0x80090C40: jal         0x800C79B8
    // 0x80090C44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bgload_start(rdram, ctx);
        goto after_2;
    // 0x80090C44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80090C48: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80090C4C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80090C50: addiu       $t0, $t0, 0x6FA4
    ctx->r8 = ADD32(ctx->r8, 0X6FA4);
    // 0x80090C54: beq         $v0, $zero, L_80090CA8
    if (ctx->r2 == 0) {
        // 0x80090C58: addiu       $v1, $v1, 0x6F9C
        ctx->r3 = ADD32(ctx->r3, 0X6F9C);
            goto L_80090CA8;
    }
    // 0x80090C58: addiu       $v1, $v1, 0x6F9C
    ctx->r3 = ADD32(ctx->r3, 0X6F9C);
    // 0x80090C5C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80090C60: lw          $a0, -0x5BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5BC);
    // 0x80090C64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090C68: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80090C6C: lw          $t9, 0x6F88($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6F88);
    // 0x80090C70: sw          $a0, 0x6970($at)
    MEM_W(0X6970, ctx->r1) = ctx->r4;
    // 0x80090C74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090C78: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80090C7C: lw          $t3, 0x6F8C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6F8C);
    // 0x80090C80: sw          $t9, 0x6FB4($at)
    MEM_W(0X6FB4, ctx->r1) = ctx->r25;
    // 0x80090C84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090C88: jal         0x8006B2EC
    // 0x80090C8C: sw          $t3, 0x6FB8($at)
    MEM_W(0X6FB8, ctx->r1) = ctx->r11;
    leveltable_vehicle_default(rdram, ctx);
        goto after_3;
    // 0x80090C8C: sw          $t3, 0x6FB8($at)
    MEM_W(0X6FB8, ctx->r1) = ctx->r11;
    after_3:
    // 0x80090C90: jal         0x8006DD54
    // 0x80090C94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    set_level_default_vehicle(rdram, ctx);
        goto after_4;
    // 0x80090C94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80090C98: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80090C9C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80090CA0: addiu       $t0, $t0, 0x6FA4
    ctx->r8 = ADD32(ctx->r8, 0X6FA4);
    // 0x80090CA4: addiu       $v1, $v1, 0x6F9C
    ctx->r3 = ADD32(ctx->r3, 0X6F9C);
L_80090CA8:
    // 0x80090CA8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80090CAC: lw          $t4, 0x6FB4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6FB4);
    // 0x80090CB0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80090CB4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80090CB8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80090CBC: sll         $t5, $t5, 6
    ctx->r13 = S32(ctx->r13 << 6);
    // 0x80090CC0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80090CC4: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80090CC8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80090CCC: lw          $t1, 0x6A20($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6A20);
    // 0x80090CD0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80090CD4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80090CD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80090CDC: lw          $t7, 0x6FB8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6FB8);
    // 0x80090CE0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80090CE4: negu        $t8, $t1
    ctx->r24 = SUB32(0, ctx->r9);
    // 0x80090CE8: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80090CEC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80090CF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80090CF4: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80090CF8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80090CFC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80090D00: lw          $v0, 0x6A18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A18);
    // 0x80090D04: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80090D08: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80090D0C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80090D10: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80090D14: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80090D18: mflo        $t9
    ctx->r25 = lo;
    // 0x80090D1C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80090D20: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80090D24: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80090D28: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80090D2C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80090D30: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80090D34: sra         $t3, $t1, 2
    ctx->r11 = S32(SIGNED(ctx->r9) >> 2);
    // 0x80090D38: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80090D3C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80090D40: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80090D44: addiu       $a3, $a1, 0xA0
    ctx->r7 = ADD32(ctx->r5, 0XA0);
    // 0x80090D48: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80090D4C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80090D50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80090D54: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80090D58: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80090D5C: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80090D60: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80090D64: nop

    // 0x80090D68: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80090D6C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80090D70: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80090D74: nop

    // 0x80090D78: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80090D7C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80090D80: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80090D84: addu        $t2, $a2, $v0
    ctx->r10 = ADD32(ctx->r6, ctx->r2);
    // 0x80090D88: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80090D8C: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80090D90: jal         0x80066B80
    // 0x80090D94: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    viewport_menu_set(rdram, ctx);
        goto after_5;
    // 0x80090D94: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_5:
    // 0x80090D98: addiu       $t5, $sp, 0x38
    ctx->r13 = ADD32(ctx->r29, 0X38);
    // 0x80090D9C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80090DA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80090DA4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80090DA8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80090DAC: jal         0x80066DE8
    // 0x80090DB0: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    copy_viewport_background_size_to_coords(rdram, ctx);
        goto after_6;
    // 0x80090DB0: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    after_6:
    // 0x80090DB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80090DB8: jal         0x80066A58
    // 0x80090DBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camEnableUserView(rdram, ctx);
        goto after_7;
    // 0x80090DBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80090DC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80090DC4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80090DC8: jr          $ra
    // 0x80090DCC: nop

    return;
    // 0x80090DCC: nop

;}
RECOMP_FUNC void func_800A4C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A517C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800A5180: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800A5184: jr          $ra
    // 0x800A5188: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x800A5188: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void obj_init_levelname(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042A5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80042A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042A64: lb          $t6, 0x9($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X9);
    // 0x80042A68: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80042A6C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80042A70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80042A74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80042A78: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80042A7C: swc1        $f10, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f10.u32l;
    // 0x80042A80: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80042A84: nop

    // 0x80042A88: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80042A8C: swc1        $f16, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f16.u32l;
    // 0x80042A90: lb          $t7, 0x8($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X8);
    // 0x80042A94: sh          $zero, 0x7E($a0)
    MEM_H(0X7E, ctx->r4) = 0;
    // 0x80042A98: sh          $t7, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r15;
    // 0x80042A9C: jal         0x8009C814
    // 0x80042AA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x80042AA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80042AA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80042AA8: beq         $v0, $zero, L_80042AB8
    if (ctx->r2 == 0) {
        // 0x80042AAC: nop
    
            goto L_80042AB8;
    }
    // 0x80042AAC: nop

    // 0x80042AB0: jal         0x8000FFB8
    // 0x80042AB4: nop

    free_object(rdram, ctx);
        goto after_1;
    // 0x80042AB4: nop

    after_1:
L_80042AB8:
    // 0x80042AB8: jal         0x800C5C30
    // 0x80042ABC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    clear_dialogue_box_open_flag(rdram, ctx);
        goto after_2;
    // 0x80042ABC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x80042AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80042AC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80042AC8: jr          $ra
    // 0x80042ACC: nop

    return;
    // 0x80042ACC: nop

;}
RECOMP_FUNC void obj_init_posarrow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037664: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80037668: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8003766C: nop

    // 0x80037670: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x80037674: jr          $ra
    // 0x80037678: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    return;
    // 0x80037678: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void obj_loop_rangetrigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800421B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800421BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800421C0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800421C4: lw          $v1, 0x3C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3C);
    // 0x800421C8: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x800421CC: lhu         $t6, 0x8($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X8);
    // 0x800421D0: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800421D4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800421D8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800421DC: bgez        $t6, L_800421F4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800421E0: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800421F4;
    }
    // 0x800421E0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800421E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800421E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800421EC: nop

    // 0x800421F0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800421F4:
    // 0x800421F4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800421F8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800421FC: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80042200: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80042204: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80042208: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8004220C: jal         0x80016E1C
    // 0x80042210: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    obj_dist_racer(rdram, ctx);
        goto after_0;
    // 0x80042210: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x80042214: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80042218: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8004221C: blez        $v0, L_80042230
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80042220: nop
    
            goto L_80042230;
    }
    // 0x80042220: nop

    // 0x80042224: lhu         $t9, 0xA($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XA);
    // 0x80042228: b           L_80042234
    // 0x8004222C: sw          $t9, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r25;
        goto L_80042234;
    // 0x8004222C: sw          $t9, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r25;
L_80042230:
    // 0x80042230: sw          $zero, 0x74($a0)
    MEM_W(0X74, ctx->r4) = 0;
L_80042234:
    // 0x80042234: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80042238: jal         0x800B019C
    // 0x8004223C: nop

    obj_spawn_particle(rdram, ctx);
        goto after_1;
    // 0x8004223C: nop

    after_1:
    // 0x80042240: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80042244: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80042248: jr          $ra
    // 0x8004224C: nop

    return;
    // 0x8004224C: nop

;}
RECOMP_FUNC void func_8001F23C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F270: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001F274: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001F278: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8001F27C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001F280: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001F284: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001F288: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001F28C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001F290: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x8001F294: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8001F298: sh          $t6, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r14;
    // 0x8001F29C: lh          $t7, 0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X4);
    // 0x8001F2A0: addiu       $s5, $sp, 0x3C
    ctx->r21 = ADD32(ctx->r29, 0X3C);
    // 0x8001F2A4: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
    // 0x8001F2A8: lh          $t8, 0x6($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X6);
    // 0x8001F2AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001F2B0: sh          $t8, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r24;
    // 0x8001F2B4: lh          $t9, 0xC($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XC);
    // 0x8001F2B8: nop

    // 0x8001F2BC: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8001F2C0: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x8001F2C4: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x8001F2C8: sb          $t2, 0x3D($sp)
    MEM_B(0X3D, ctx->r29) = ctx->r10;
    // 0x8001F2CC: lh          $t3, 0xC($a1)
    ctx->r11 = MEM_H(ctx->r5, 0XC);
    // 0x8001F2D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001F2D4: jal         0x8000EA54
    // 0x8001F2D8: sb          $t3, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r11;
    spawn_object(rdram, ctx);
        goto after_0;
    // 0x8001F2D8: sb          $t3, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r11;
    after_0:
    // 0x8001F2DC: sw          $v0, 0x64($s4)
    MEM_W(0X64, ctx->r20) = ctx->r2;
    // 0x8001F2E0: beq         $v0, $zero, L_8001F318
    if (ctx->r2 == 0) {
        // 0x8001F2E4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8001F318;
    }
    // 0x8001F2E4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8001F2E8: lh          $t4, 0x48($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X48);
    // 0x8001F2EC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8001F2F0: bne         $t4, $at, L_8001F318
    if (ctx->r12 != ctx->r1) {
        // 0x8001F2F4: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8001F318;
    }
    // 0x8001F2F4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001F2F8: lbu         $t5, -0x4B8C($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4B8C);
    // 0x8001F2FC: nop

    // 0x8001F300: beq         $t5, $zero, L_8001F318
    if (ctx->r13 == 0) {
        // 0x8001F304: nop
    
            goto L_8001F318;
    }
    // 0x8001F304: nop

    // 0x8001F308: jal         0x8000FFB8
    // 0x8001F30C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    free_object(rdram, ctx);
        goto after_1;
    // 0x8001F30C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8001F310: sw          $zero, 0x64($s4)
    MEM_W(0X64, ctx->r20) = 0;
    // 0x8001F314: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001F318:
    // 0x8001F318: beq         $s1, $zero, L_8001F3C8
    if (ctx->r17 == 0) {
        // 0x8001F31C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8001F3C8;
    }
    // 0x8001F31C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001F320: sw          $zero, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = 0;
    // 0x8001F324: jal         0x8001EFD8
    // 0x8001F328: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    obj_init_animobject(rdram, ctx);
        goto after_2;
    // 0x8001F328: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8001F32C: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8001F330: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x8001F334: lb          $t7, 0x54($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X54);
    // 0x8001F338: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8001F33C: bne         $t7, $at, L_8001F3C8
    if (ctx->r15 != ctx->r1) {
        // 0x8001F340: addiu       $s3, $s3, -0x4D42
        ctx->r19 = ADD32(ctx->r19, -0X4D42);
            goto L_8001F3C8;
    }
    // 0x8001F340: addiu       $s3, $s3, -0x4D42
    ctx->r19 = ADD32(ctx->r19, -0X4D42);
    // 0x8001F344: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x8001F348: lb          $t8, 0x0($s3)
    ctx->r24 = MEM_B(ctx->r19, 0X0);
    // 0x8001F34C: jal         0x80066450
    // 0x8001F350: sb          $t8, 0x44($v0)
    MEM_B(0X44, ctx->r2) = ctx->r24;
    cam_get_viewport_layout(rdram, ctx);
        goto after_3;
    // 0x8001F350: sb          $t8, 0x44($v0)
    MEM_B(0X44, ctx->r2) = ctx->r24;
    after_3:
    // 0x8001F354: jal         0x8006C3DC
    // 0x8001F358: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    race_is_adventure_2P(rdram, ctx);
        goto after_4;
    // 0x8001F358: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_4:
    // 0x8001F35C: beq         $v0, $zero, L_8001F368
    if (ctx->r2 == 0) {
        // 0x8001F360: nop
    
            goto L_8001F368;
    }
    // 0x8001F360: nop

    // 0x8001F364: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8001F368:
    // 0x8001F368: blez        $s2, L_8001F3B8
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8001F36C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001F3B8;
    }
    // 0x8001F36C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001F370: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8001F374:
    // 0x8001F374: jal         0x8000EA54
    // 0x8001F378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_5;
    // 0x8001F378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8001F37C: beq         $v0, $zero, L_8001F3AC
    if (ctx->r2 == 0) {
        // 0x8001F380: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8001F3AC;
    }
    // 0x8001F380: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8001F384: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8001F388: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001F38C: jal         0x8001EFD8
    // 0x8001F390: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    obj_init_animobject(rdram, ctx);
        goto after_6;
    // 0x8001F390: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8001F394: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x8001F398: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001F39C: sb          $s0, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r16;
    // 0x8001F3A0: lb          $t9, 0x0($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X0);
    // 0x8001F3A4: nop

    // 0x8001F3A8: sb          $t9, 0x44($v0)
    MEM_B(0X44, ctx->r2) = ctx->r25;
L_8001F3AC:
    // 0x8001F3AC: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8001F3B0: bne         $at, $zero, L_8001F374
    if (ctx->r1 != 0) {
        // 0x8001F3B4: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8001F374;
    }
    // 0x8001F3B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8001F3B8:
    // 0x8001F3B8: lb          $t0, 0x0($s3)
    ctx->r8 = MEM_B(ctx->r19, 0X0);
    // 0x8001F3BC: nop

    // 0x8001F3C0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8001F3C4: sb          $t1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r9;
L_8001F3C8:
    // 0x8001F3C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F3CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001F3D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001F3D4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F3D8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001F3DC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001F3E0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8001F3E4: jr          $ra
    // 0x8001F3E8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8001F3E8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void rspF3DDKRDramStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void weather_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC1BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AC1C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AC1C4: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800AC1C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AC1CC: blez        $s0, L_800AC3B8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800AC1D0: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800AC3B8;
    }
    // 0x800AC1D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AC1D4: addiu       $v0, $v0, -0x7E88
    ctx->r2 = ADD32(ctx->r2, -0X7E88);
    // 0x800AC1D8: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x800AC1DC: nop

    // 0x800AC1E0: bne         $a0, $t6, L_800AC228
    if (ctx->r4 != ctx->r14) {
        // 0x800AC1E4: nop
    
            goto L_800AC228;
    }
    // 0x800AC1E4: nop

    // 0x800AC1E8: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x800AC1EC: nop

    // 0x800AC1F0: bne         $a1, $t7, L_800AC228
    if (ctx->r5 != ctx->r15) {
        // 0x800AC1F4: nop
    
            goto L_800AC228;
    }
    // 0x800AC1F4: nop

    // 0x800AC1F8: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x800AC1FC: nop

    // 0x800AC200: bne         $a2, $t8, L_800AC228
    if (ctx->r6 != ctx->r24) {
        // 0x800AC204: nop
    
            goto L_800AC228;
    }
    // 0x800AC204: nop

    // 0x800AC208: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800AC20C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800AC210: bne         $a3, $t9, L_800AC228
    if (ctx->r7 != ctx->r25) {
        // 0x800AC214: nop
    
            goto L_800AC228;
    }
    // 0x800AC214: nop

    // 0x800AC218: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    // 0x800AC21C: nop

    // 0x800AC220: beq         $v1, $t0, L_800AC3B8
    if (ctx->r3 == ctx->r8) {
        // 0x800AC224: nop
    
            goto L_800AC3B8;
    }
    // 0x800AC224: nop

L_800AC228:
    // 0x800AC228: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x800AC22C: lw          $t4, 0x18($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X18);
    // 0x800AC230: subu        $t2, $a0, $t1
    ctx->r10 = SUB32(ctx->r4, ctx->r9);
    // 0x800AC234: div         $zero, $t2, $s0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r16)));
    // 0x800AC238: subu        $t5, $a1, $t4
    ctx->r13 = SUB32(ctx->r5, ctx->r12);
    // 0x800AC23C: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x800AC240: sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
    // 0x800AC244: subu        $t8, $a2, $t7
    ctx->r24 = SUB32(ctx->r6, ctx->r15);
    // 0x800AC248: sw          $a1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r5;
    // 0x800AC24C: sw          $a2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r6;
    // 0x800AC250: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AC254: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800AC258: bne         $s0, $zero, L_800AC264
    if (ctx->r16 != 0) {
        // 0x800AC25C: nop
    
            goto L_800AC264;
    }
    // 0x800AC25C: nop

    // 0x800AC260: break       7
    do_break(2148188768);
L_800AC264:
    // 0x800AC264: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC268: bne         $s0, $at, L_800AC27C
    if (ctx->r16 != ctx->r1) {
        // 0x800AC26C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC27C;
    }
    // 0x800AC26C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC270: bne         $t2, $at, L_800AC27C
    if (ctx->r10 != ctx->r1) {
        // 0x800AC274: nop
    
            goto L_800AC27C;
    }
    // 0x800AC274: nop

    // 0x800AC278: break       6
    do_break(2148188792);
L_800AC27C:
    // 0x800AC27C: mflo        $t3
    ctx->r11 = lo;
    // 0x800AC280: sw          $t3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r11;
    // 0x800AC284: nop

    // 0x800AC288: div         $zero, $t5, $s0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r16)));
    // 0x800AC28C: bne         $s0, $zero, L_800AC298
    if (ctx->r16 != 0) {
        // 0x800AC290: nop
    
            goto L_800AC298;
    }
    // 0x800AC290: nop

    // 0x800AC294: break       7
    do_break(2148188820);
L_800AC298:
    // 0x800AC298: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC29C: bne         $s0, $at, L_800AC2B0
    if (ctx->r16 != ctx->r1) {
        // 0x800AC2A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC2B0;
    }
    // 0x800AC2A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC2A4: bne         $t5, $at, L_800AC2B0
    if (ctx->r13 != ctx->r1) {
        // 0x800AC2A8: nop
    
            goto L_800AC2B0;
    }
    // 0x800AC2A8: nop

    // 0x800AC2AC: break       6
    do_break(2148188844);
L_800AC2B0:
    // 0x800AC2B0: mflo        $t6
    ctx->r14 = lo;
    // 0x800AC2B4: sw          $t6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r14;
    // 0x800AC2B8: nop

    // 0x800AC2BC: div         $zero, $t8, $s0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r16)));
    // 0x800AC2C0: bne         $s0, $zero, L_800AC2CC
    if (ctx->r16 != 0) {
        // 0x800AC2C4: nop
    
            goto L_800AC2CC;
    }
    // 0x800AC2C4: nop

    // 0x800AC2C8: break       7
    do_break(2148188872);
L_800AC2CC:
    // 0x800AC2CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC2D0: bne         $s0, $at, L_800AC2E4
    if (ctx->r16 != ctx->r1) {
        // 0x800AC2D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC2E4;
    }
    // 0x800AC2D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC2D8: bne         $t8, $at, L_800AC2E4
    if (ctx->r24 != ctx->r1) {
        // 0x800AC2DC: nop
    
            goto L_800AC2E4;
    }
    // 0x800AC2DC: nop

    // 0x800AC2E0: break       6
    do_break(2148188896);
L_800AC2E4:
    // 0x800AC2E4: mflo        $t9
    ctx->r25 = lo;
    // 0x800AC2E8: sw          $t9, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r25;
    // 0x800AC2EC: lw          $t0, 0x31EC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X31EC);
    // 0x800AC2F0: nop

    // 0x800AC2F4: bne         $t0, $zero, L_800AC384
    if (ctx->r8 != 0) {
        // 0x800AC2F8: nop
    
            goto L_800AC384;
    }
    // 0x800AC2F8: nop

    // 0x800AC2FC: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800AC300: lw          $t4, 0x30($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30);
    // 0x800AC304: subu        $t2, $a3, $t1
    ctx->r10 = SUB32(ctx->r7, ctx->r9);
    // 0x800AC308: div         $zero, $t2, $s0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r16)));
    // 0x800AC30C: subu        $t5, $v1, $t4
    ctx->r13 = SUB32(ctx->r3, ctx->r12);
    // 0x800AC310: bne         $s0, $zero, L_800AC31C
    if (ctx->r16 != 0) {
        // 0x800AC314: nop
    
            goto L_800AC31C;
    }
    // 0x800AC314: nop

    // 0x800AC318: break       7
    do_break(2148188952);
L_800AC31C:
    // 0x800AC31C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC320: bne         $s0, $at, L_800AC334
    if (ctx->r16 != ctx->r1) {
        // 0x800AC324: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC334;
    }
    // 0x800AC324: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC328: bne         $t2, $at, L_800AC334
    if (ctx->r10 != ctx->r1) {
        // 0x800AC32C: nop
    
            goto L_800AC334;
    }
    // 0x800AC32C: nop

    // 0x800AC330: break       6
    do_break(2148188976);
L_800AC334:
    // 0x800AC334: sw          $a3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r7;
    // 0x800AC338: sw          $v1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r3;
    // 0x800AC33C: sw          $s0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r16;
    // 0x800AC340: mflo        $t3
    ctx->r11 = lo;
    // 0x800AC344: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800AC348: nop

    // 0x800AC34C: div         $zero, $t5, $s0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r16)));
    // 0x800AC350: bne         $s0, $zero, L_800AC35C
    if (ctx->r16 != 0) {
        // 0x800AC354: nop
    
            goto L_800AC35C;
    }
    // 0x800AC354: nop

    // 0x800AC358: break       7
    do_break(2148189016);
L_800AC35C:
    // 0x800AC35C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC360: bne         $s0, $at, L_800AC374
    if (ctx->r16 != ctx->r1) {
        // 0x800AC364: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC374;
    }
    // 0x800AC364: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC368: bne         $t5, $at, L_800AC374
    if (ctx->r13 != ctx->r1) {
        // 0x800AC36C: nop
    
            goto L_800AC374;
    }
    // 0x800AC36C: nop

    // 0x800AC370: break       6
    do_break(2148189040);
L_800AC374:
    // 0x800AC374: mflo        $t6
    ctx->r14 = lo;
    // 0x800AC378: sw          $t6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r14;
    // 0x800AC37C: b           L_800AC3BC
    // 0x800AC380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800AC3BC;
    // 0x800AC380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AC384:
    // 0x800AC384: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x800AC388: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800AC38C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AC390: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AC394: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x800AC398: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AC39C: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x800AC3A0: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800AC3A4: addiu       $a0, $a3, 0x1
    ctx->r4 = ADD32(ctx->r7, 0X1);
    // 0x800AC3A8: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x800AC3AC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800AC3B0: jal         0x800AD824
    // 0x800AC3B4: nop

    rain_set(rdram, ctx);
        goto after_0;
    // 0x800AC3B4: nop

    after_0:
L_800AC3B8:
    // 0x800AC3B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AC3BC:
    // 0x800AC3BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AC3C0: jr          $ra
    // 0x800AC3C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800AC3C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80016BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016BF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80016BFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80016C00: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80016C04: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80016C08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80016C0C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80016C10: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80016C14: jal         0x800170D0
    // 0x80016C18: sb          $zero, 0x104($t6)
    MEM_B(0X104, ctx->r14) = 0;
    obj_collision_transform(rdram, ctx);
        goto after_0;
    // 0x80016C18: sb          $zero, 0x104($t6)
    MEM_B(0X104, ctx->r14) = 0;
    after_0:
    // 0x80016C1C: jal         0x800170D0
    // 0x80016C20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_collision_transform(rdram, ctx);
        goto after_1;
    // 0x80016C20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80016C24: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x80016C28: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80016C2C: lb          $v1, 0x55($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X55);
    // 0x80016C30: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80016C34: blez        $v1, L_80016C88
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80016C38: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80016C88;
    }
    // 0x80016C38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80016C3C:
    // 0x80016C3C: lw          $t8, 0x68($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X68);
    // 0x80016C40: nop

    // 0x80016C44: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80016C48: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80016C4C: nop

    // 0x80016C50: beq         $v0, $zero, L_80016C74
    if (ctx->r2 == 0) {
        // 0x80016C54: nop
    
            goto L_80016C74;
    }
    // 0x80016C54: nop

    // 0x80016C58: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80016C5C: jal         0x800603BC
    // 0x80016C60: nop

    model_init_collision(rdram, ctx);
        goto after_2;
    // 0x80016C60: nop

    after_2:
    // 0x80016C64: lw          $t0, 0x40($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X40);
    // 0x80016C68: nop

    // 0x80016C6C: lb          $v1, 0x55($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X55);
    // 0x80016C70: nop

L_80016C74:
    // 0x80016C74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80016C78: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80016C7C: bne         $at, $zero, L_80016C3C
    if (ctx->r1 != 0) {
        // 0x80016C80: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80016C3C;
    }
    // 0x80016C80: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80016C84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80016C88:
    // 0x80016C88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016C8C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C90: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80016C94: jr          $ra
    // 0x80016C98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80016C98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alMainBusPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC920: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800CC924: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CC928: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800CC92C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800CC930: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800CC934: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800CC938: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800CC93C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800CC940: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800CC944: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800CC948: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800CC94C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800CC950: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800CC954: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x800CC958: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800CC95C: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x800CC960: ori         $t6, $t6, 0x440
    ctx->r14 = ctx->r14 | 0X440;
    // 0x800CC964: ori         $t7, $t7, 0x580
    ctx->r15 = ctx->r15 | 0X580;
    // 0x800CC968: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800CC96C: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800CC970: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x800CC974: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x800CC978: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x800CC97C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800CC980: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x800CC984: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x800CC988: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800CC98C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800CC990: blez        $t8, L_800CCA0C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800CC994: addiu       $s3, $t0, 0x10
        ctx->r19 = ADD32(ctx->r8, 0X10);
            goto L_800CCA0C;
    }
    // 0x800CC994: addiu       $s3, $t0, 0x10
    ctx->r19 = ADD32(ctx->r8, 0X10);
    // 0x800CC998: lui         $s2, 0xC00
    ctx->r18 = S32(0XC00 << 16);
    // 0x800CC99C: ori         $s2, $s2, 0x7FFF
    ctx->r18 = ctx->r18 | 0X7FFF;
    // 0x800CC9A0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800CC9A4: andi        $s6, $v0, 0xFFFF
    ctx->r22 = ctx->r2 & 0XFFFF;
L_800CC9A8:
    // 0x800CC9A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800CC9AC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800CC9B0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800CC9B4: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800CC9B8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800CC9BC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800CC9C0: jalr        $t9
    // 0x800CC9C4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CC9C4: nop

    after_0:
    // 0x800CC9C8: lui         $t2, 0x6C0
    ctx->r10 = S32(0X6C0 << 16);
    // 0x800CC9CC: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x800CC9D0: lui         $t1, 0x800
    ctx->r9 = S32(0X800 << 16);
    // 0x800CC9D4: ori         $t2, $t2, 0x440
    ctx->r10 = ctx->r10 | 0X440;
    // 0x800CC9D8: ori         $t3, $t3, 0x580
    ctx->r11 = ctx->r11 | 0X580;
    // 0x800CC9DC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800CC9E0: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x800CC9E4: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800CC9E8: sw          $s2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r18;
    // 0x800CC9EC: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x800CC9F0: sw          $s2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r18;
    // 0x800CC9F4: lw          $t4, 0x14($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X14);
    // 0x800CC9F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800CC9FC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800CCA00: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800CCA04: bne         $at, $zero, L_800CC9A8
    if (ctx->r1 != 0) {
        // 0x800CCA08: addiu       $s3, $v0, 0x18
        ctx->r19 = ADD32(ctx->r2, 0X18);
            goto L_800CC9A8;
    }
    // 0x800CCA08: addiu       $s3, $v0, 0x18
    ctx->r19 = ADD32(ctx->r2, 0X18);
L_800CCA0C:
    // 0x800CCA0C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800CCA10: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800CCA14: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800CCA18: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800CCA1C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800CCA20: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800CCA24: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800CCA28: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800CCA2C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800CCA30: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800CCA34: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800CCA38: jr          $ra
    // 0x800CCA3C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800CCA3C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void play_random_boss_sound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CCA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CCA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005CCAC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8005CCB0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8005CCB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005CCB8: jal         0x8006FB8C
    // 0x8005CCBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x8005CCBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8005CCC0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8005CCC4: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x8005CCC8: sra         $t6, $v1, 24
    ctx->r14 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8005CCCC: bne         $a2, $zero, L_8005CCD8
    if (ctx->r6 != 0) {
        // 0x8005CCD0: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8005CCD8;
    }
    // 0x8005CCD0: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8005CCD4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8005CCD8:
    // 0x8005CCD8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8005CCDC: lw          $t7, -0x24B8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X24B8);
    // 0x8005CCE0: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x8005CCE4: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8005CCE8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8005CCEC: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    // 0x8005CCF0: jal         0x80001D04
    // 0x8005CCF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8005CCF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8005CCF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005CCFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CD00: jr          $ra
    // 0x8005CD04: nop

    return;
    // 0x8005CD04: nop

;}
RECOMP_FUNC void sprite_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D100: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007D104: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8007D108: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8007D10C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007D110: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8007D114: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007D118: beq         $a0, $zero, L_8007D1F4
    if (ctx->r4 == 0) {
        // 0x8007D11C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8007D1F4;
    }
    // 0x8007D11C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007D120: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x8007D124: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007D128: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007D12C: sh          $t7, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r15;
    // 0x8007D130: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x8007D134: nop

    // 0x8007D138: bgtz        $t8, L_8007D1F8
    if (SIGNED(ctx->r24) > 0) {
        // 0x8007D13C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007D1F8;
    }
    // 0x8007D13C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007D140: lw          $v1, 0x68F8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X68F8);
    // 0x8007D144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007D148: blez        $v1, L_8007D1F4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007D14C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8007D1F4;
    }
    // 0x8007D14C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007D150: lw          $a0, 0x68EC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68EC);
    // 0x8007D154: nop

    // 0x8007D158: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_8007D15C:
    // 0x8007D15C: sll         $t9, $s3, 3
    ctx->r25 = S32(ctx->r19 << 3);
    // 0x8007D160: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8007D164: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8007D168: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x8007D16C: bne         $s2, $t1, L_8007D1E8
    if (ctx->r18 != ctx->r9) {
        // 0x8007D170: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8007D1E8;
    }
    // 0x8007D170: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007D174: lh          $t2, 0x2($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X2);
    // 0x8007D178: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007D17C: blez        $t2, L_8007D1B0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8007D180: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8007D1B0;
    }
    // 0x8007D180: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8007D184:
    // 0x8007D184: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
    // 0x8007D188: nop

    // 0x8007D18C: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x8007D190: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8007D194: jal         0x8007B70C
    // 0x8007D198: nop

    tex_free(rdram, ctx);
        goto after_0;
    // 0x8007D198: nop

    after_0:
    // 0x8007D19C: lh          $t5, 0x2($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X2);
    // 0x8007D1A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007D1A4: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8007D1A8: bne         $at, $zero, L_8007D184
    if (ctx->r1 != 0) {
        // 0x8007D1AC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8007D184;
    }
    // 0x8007D1AC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8007D1B0:
    // 0x8007D1B0: jal         0x80071380
    // 0x8007D1B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_1;
    // 0x8007D1B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8007D1B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007D1BC: addiu       $v0, $v0, 0x68EC
    ctx->r2 = ADD32(ctx->r2, 0X68EC);
    // 0x8007D1C0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8007D1C4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007D1C8: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x8007D1CC: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
    // 0x8007D1D0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8007D1D4: nop

    // 0x8007D1D8: addu        $t9, $t8, $s3
    ctx->r25 = ADD32(ctx->r24, ctx->r19);
    // 0x8007D1DC: b           L_8007D1F4
    // 0x8007D1E0: sw          $v1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r3;
        goto L_8007D1F4;
    // 0x8007D1E0: sw          $v1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r3;
    // 0x8007D1E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8007D1E8:
    // 0x8007D1E8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007D1EC: bne         $at, $zero, L_8007D15C
    if (ctx->r1 != 0) {
        // 0x8007D1F0: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8007D15C;
    }
    // 0x8007D1F0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_8007D1F4:
    // 0x8007D1F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007D1F8:
    // 0x8007D1F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007D1FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007D200: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D204: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007D208: jr          $ra
    // 0x8007D20C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007D20C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_loop_texscroll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040188: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004018C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80040190: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80040194: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80040198: lw          $t5, 0x64($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X64);
    // 0x8004019C: jal         0x8002C804
    // 0x800401A0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x800401A0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    after_0:
    // 0x800401A4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800401A8: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800401AC: lh          $t0, 0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X4);
    // 0x800401B0: lh          $t1, 0x6($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X6);
    // 0x800401B4: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800401B8: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x800401BC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800401C0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800401C4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800401C8: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x800401CC: lh          $t8, 0x8($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X8);
    // 0x800401D0: lbu         $a2, 0x0($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X0);
    // 0x800401D4: lbu         $a3, 0x1($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X1);
    // 0x800401D8: sll         $t7, $a2, 8
    ctx->r15 = S32(ctx->r6 << 8);
    // 0x800401DC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800401E0: lh          $t7, 0xA($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XA);
    // 0x800401E4: mflo        $t0
    ctx->r8 = lo;
    // 0x800401E8: sll         $t6, $a3, 8
    ctx->r14 = S32(ctx->r7 << 8);
    // 0x800401EC: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800401F0: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800401F4: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800401F8: sh          $t9, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r25;
    // 0x800401FC: lh          $a0, 0x8($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X8);
    // 0x80040200: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80040204: andi        $t8, $a0, 0x3
    ctx->r24 = ctx->r4 & 0X3;
    // 0x80040208: sh          $t8, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r24;
    // 0x8004020C: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80040210: sra         $t0, $a0, 2
    ctx->r8 = S32(SIGNED(ctx->r4) >> 2);
    // 0x80040214: mflo        $t1
    ctx->r9 = lo;
    // 0x80040218: addu        $t6, $t7, $t1
    ctx->r14 = ADD32(ctx->r15, ctx->r9);
    // 0x8004021C: sh          $t6, 0xA($t5)
    MEM_H(0XA, ctx->r13) = ctx->r14;
    // 0x80040220: lh          $a1, 0xA($t5)
    ctx->r5 = MEM_H(ctx->r13, 0XA);
    // 0x80040224: nop

    // 0x80040228: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8004022C: sh          $t9, 0xA($t5)
    MEM_H(0XA, ctx->r13) = ctx->r25;
    // 0x80040230: lh          $t7, 0x1A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X1A);
    // 0x80040234: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80040238: blez        $t7, L_800403D8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8004023C: sra         $t1, $a1, 2
        ctx->r9 = S32(SIGNED(ctx->r5) >> 2);
            goto L_800403D8;
    }
    // 0x8004023C: sra         $t1, $a1, 2
    ctx->r9 = S32(SIGNED(ctx->r5) >> 2);
    // 0x80040240: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
L_80040244:
    // 0x80040244: lh          $v0, 0x20($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X20);
    // 0x80040248: lw          $v1, 0xC($t3)
    ctx->r3 = MEM_W(ctx->r11, 0XC);
    // 0x8004024C: blez        $v0, L_800403C4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80040250: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_800403C4;
    }
    // 0x80040250: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80040254: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
L_80040258:
    // 0x80040258: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8004025C: lbu         $t8, 0x0($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X0);
    // 0x80040260: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80040264: bne         $t6, $t8, L_800403BC
    if (ctx->r14 != ctx->r24) {
        // 0x80040268: slt         $at, $t4, $v0
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800403BC;
    }
    // 0x80040268: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004026C: lh          $a1, 0x4($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X4);
    // 0x80040270: lh          $a0, 0x10($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X10);
    // 0x80040274: nop

    // 0x80040278: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8004027C: beq         $at, $zero, L_800403BC
    if (ctx->r1 == 0) {
        // 0x80040280: slt         $at, $t4, $v0
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800403BC;
    }
    // 0x80040280: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
L_80040284:
    // 0x80040284: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x80040288: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x8004028C: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x80040290: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80040294: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80040298: andi        $t8, $t6, 0x80
    ctx->r24 = ctx->r14 & 0X80;
    // 0x8004029C: bne         $t8, $zero, L_800403A8
    if (ctx->r24 != 0) {
        // 0x800402A0: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800403A8;
    }
    // 0x800402A0: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800402A4: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x800402A8: nop

    // 0x800402AC: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800402B0: beq         $at, $zero, L_800402D8
    if (ctx->r1 == 0) {
        // 0x800402B4: subu        $t9, $v1, $a3
        ctx->r25 = SUB32(ctx->r3, ctx->r7);
            goto L_800402D8;
    }
    // 0x800402B4: subu        $t9, $v1, $a3
    ctx->r25 = SUB32(ctx->r3, ctx->r7);
    // 0x800402B8: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x800402BC: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x800402C0: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x800402C4: subu        $t6, $t7, $a3
    ctx->r14 = SUB32(ctx->r15, ctx->r7);
    // 0x800402C8: subu        $t9, $t8, $a3
    ctx->r25 = SUB32(ctx->r24, ctx->r7);
    // 0x800402CC: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x800402D0: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x800402D4: sh          $t9, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r25;
L_800402D8:
    // 0x800402D8: bgez        $v1, L_800402FC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800402DC: addu        $t7, $v1, $a3
        ctx->r15 = ADD32(ctx->r3, ctx->r7);
            goto L_800402FC;
    }
    // 0x800402DC: addu        $t7, $v1, $a3
    ctx->r15 = ADD32(ctx->r3, ctx->r7);
    // 0x800402E0: lh          $t6, 0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA);
    // 0x800402E4: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x800402E8: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x800402EC: addu        $t8, $t6, $a3
    ctx->r24 = ADD32(ctx->r14, ctx->r7);
    // 0x800402F0: addu        $t7, $t9, $a3
    ctx->r15 = ADD32(ctx->r25, ctx->r7);
    // 0x800402F4: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
    // 0x800402F8: sh          $t7, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r15;
L_800402FC:
    // 0x800402FC: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80040300: nop

    // 0x80040304: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80040308: beq         $at, $zero, L_80040330
    if (ctx->r1 == 0) {
        // 0x8004030C: subu        $t6, $v1, $a2
        ctx->r14 = SUB32(ctx->r3, ctx->r6);
            goto L_80040330;
    }
    // 0x8004030C: subu        $t6, $v1, $a2
    ctx->r14 = SUB32(ctx->r3, ctx->r6);
    // 0x80040310: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x80040314: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x80040318: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x8004031C: subu        $t9, $t8, $a2
    ctx->r25 = SUB32(ctx->r24, ctx->r6);
    // 0x80040320: subu        $t6, $t7, $a2
    ctx->r14 = SUB32(ctx->r15, ctx->r6);
    // 0x80040324: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80040328: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    // 0x8004032C: sh          $t6, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r14;
L_80040330:
    // 0x80040330: bgez        $v1, L_80040358
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80040334: addu        $t8, $v1, $a2
        ctx->r24 = ADD32(ctx->r3, ctx->r6);
            goto L_80040358;
    }
    // 0x80040334: addu        $t8, $v1, $a2
    ctx->r24 = ADD32(ctx->r3, ctx->r6);
    // 0x80040338: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x8004033C: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x80040340: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x80040344: addu        $t7, $t9, $a2
    ctx->r15 = ADD32(ctx->r25, ctx->r6);
    // 0x80040348: addu        $t8, $t6, $a2
    ctx->r24 = ADD32(ctx->r14, ctx->r6);
    // 0x8004034C: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80040350: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x80040354: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
L_80040358:
    // 0x80040358: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x8004035C: lh          $t6, 0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA);
    // 0x80040360: addu        $t7, $t9, $t1
    ctx->r15 = ADD32(ctx->r25, ctx->r9);
    // 0x80040364: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x80040368: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x8004036C: addu        $t8, $t6, $t1
    ctx->r24 = ADD32(ctx->r14, ctx->r9);
    // 0x80040370: addu        $t7, $t9, $t1
    ctx->r15 = ADD32(ctx->r25, ctx->r9);
    // 0x80040374: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
    // 0x80040378: sh          $t7, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r15;
    // 0x8004037C: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x80040380: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x80040384: addu        $t6, $v1, $t0
    ctx->r14 = ADD32(ctx->r3, ctx->r8);
    // 0x80040388: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x8004038C: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80040390: addu        $t6, $t7, $t0
    ctx->r14 = ADD32(ctx->r15, ctx->r8);
    // 0x80040394: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    // 0x80040398: sh          $t6, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r14;
    // 0x8004039C: lh          $a0, 0x10($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X10);
    // 0x800403A0: nop

    // 0x800403A4: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
L_800403A8:
    // 0x800403A8: bne         $at, $zero, L_80040284
    if (ctx->r1 != 0) {
        // 0x800403AC: nop
    
            goto L_80040284;
    }
    // 0x800403AC: nop

    // 0x800403B0: lh          $v0, 0x20($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X20);
    // 0x800403B4: nop

    // 0x800403B8: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
L_800403BC:
    // 0x800403BC: bne         $at, $zero, L_80040258
    if (ctx->r1 != 0) {
        // 0x800403C0: addiu       $t2, $t2, 0xC
        ctx->r10 = ADD32(ctx->r10, 0XC);
            goto L_80040258;
    }
    // 0x800403C0: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
L_800403C4:
    // 0x800403C4: lh          $t8, 0x1A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1A);
    // 0x800403C8: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800403CC: slt         $at, $ra, $t8
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800403D0: bne         $at, $zero, L_80040244
    if (ctx->r1 != 0) {
        // 0x800403D4: addiu       $t3, $t3, 0x44
        ctx->r11 = ADD32(ctx->r11, 0X44);
            goto L_80040244;
    }
    // 0x800403D4: addiu       $t3, $t3, 0x44
    ctx->r11 = ADD32(ctx->r11, 0X44);
L_800403D8:
    // 0x800403D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800403DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800403E0: jr          $ra
    // 0x800403E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800403E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void light_setup_intensity_change(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032384: blez        $a2, L_800323D0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80032388: nop
    
            goto L_800323D0;
    }
    // 0x80032388: nop

    // 0x8003238C: lw          $t7, 0x28($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X28);
    // 0x80032390: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80032394: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80032398: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x8003239C: sh          $a2, 0x42($a0)
    MEM_H(0X42, ctx->r4) = ctx->r6;
    // 0x800323A0: bne         $a2, $zero, L_800323AC
    if (ctx->r6 != 0) {
        // 0x800323A4: nop
    
            goto L_800323AC;
    }
    // 0x800323A4: nop

    // 0x800323A8: break       7
    do_break(2147689384);
L_800323AC:
    // 0x800323AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800323B0: bne         $a2, $at, L_800323C4
    if (ctx->r6 != ctx->r1) {
        // 0x800323B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800323C4;
    }
    // 0x800323B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800323B8: bne         $t8, $at, L_800323C4
    if (ctx->r24 != ctx->r1) {
        // 0x800323BC: nop
    
            goto L_800323C4;
    }
    // 0x800323BC: nop

    // 0x800323C0: break       6
    do_break(2147689408);
L_800323C4:
    // 0x800323C4: mflo        $t9
    ctx->r25 = lo;
    // 0x800323C8: sw          $t9, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r25;
    // 0x800323CC: nop

L_800323D0:
    // 0x800323D0: jr          $ra
    // 0x800323D4: nop

    return;
    // 0x800323D4: nop

;}
RECOMP_FUNC void obj_loop_bananacreator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D43C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003D440: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003D444: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003D448: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x8003D44C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003D450: beq         $t6, $zero, L_8003D468
    if (ctx->r14 == 0) {
        // 0x8003D454: nop
    
            goto L_8003D468;
    }
    // 0x8003D454: nop

    // 0x8003D458: lw          $t7, 0x78($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X78);
    // 0x8003D45C: nop

    // 0x8003D460: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x8003D464: sw          $t8, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r24;
L_8003D468:
    // 0x8003D468: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
    // 0x8003D46C: nop

    // 0x8003D470: bgtz        $t9, L_8003D568
    if (SIGNED(ctx->r25) > 0) {
        // 0x8003D474: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8003D568;
    }
    // 0x8003D474: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D478: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8003D47C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003D480: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8003D484: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D488: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D48C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8003D490: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8003D494: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8003D498: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8003D49C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8003D4A0: addiu       $t0, $zero, 0x53
    ctx->r8 = ADD32(0, 0X53);
    // 0x8003D4A4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8003D4A8: sh          $t1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r9;
    // 0x8003D4AC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8003D4B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D4B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D4B8: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D4BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003D4C0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8003D4C4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8003D4C8: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x8003D4CC: nop

    // 0x8003D4D0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8003D4D4: addiu       $t6, $t5, -0x3
    ctx->r14 = ADD32(ctx->r13, -0X3);
    // 0x8003D4D8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8003D4DC: sh          $t6, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r14;
    // 0x8003D4E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D4E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D4E8: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003D4EC: sb          $t9, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r25;
    // 0x8003D4F0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8003D4F4: sb          $t0, 0x38($sp)
    MEM_B(0X38, ctx->r29) = ctx->r8;
    // 0x8003D4F8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8003D4FC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003D500: jal         0x8000EA54
    // 0x8003D504: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
    spawn_object(rdram, ctx);
        goto after_0;
    // 0x8003D504: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
    after_0:
    // 0x8003D508: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003D50C: beq         $v0, $zero, L_8003D55C
    if (ctx->r2 == 0) {
        // 0x8003D510: sw          $t1, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r9;
            goto L_8003D55C;
    }
    // 0x8003D510: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
    // 0x8003D514: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8003D518: lw          $v0, 0x64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X64);
    // 0x8003D51C: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8003D520: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x8003D524: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D528: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003D52C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8003D530: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003D534: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003D538: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003D53C: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x8003D540: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8003D544: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8003D548: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003D54C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003D550: jal         0x8003FC84
    // 0x8003D554: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_1;
    // 0x8003D554: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8003D558: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
L_8003D55C:
    // 0x8003D55C: addiu       $t3, $zero, 0x4B0
    ctx->r11 = ADD32(0, 0X4B0);
    // 0x8003D560: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    // 0x8003D564: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003D568:
    // 0x8003D568: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003D56C: jr          $ra
    // 0x8003D570: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8003D570: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
