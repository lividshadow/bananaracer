#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void load_game_text_table(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C35A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C35A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C35A8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800C35AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C35B0: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800C35B4: sh          $t6, -0x52B4($at)
    MEM_H(-0X52B4, ctx->r1) = ctx->r14;
    // 0x800C35B8: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800C35BC: jal         0x80070EDC
    // 0x800C35C0: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800C35C0: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    after_0:
    // 0x800C35C4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C35C8: addiu       $v1, $v1, -0x52A8
    ctx->r3 = ADD32(ctx->r3, -0X52A8);
    // 0x800C35CC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C35D0: addiu       $t8, $v0, 0x80
    ctx->r24 = ADD32(ctx->r2, 0X80);
    // 0x800C35D4: addiu       $a0, $a0, -0x52C0
    ctx->r4 = ADD32(ctx->r4, -0X52C0);
    // 0x800C35D8: addiu       $t0, $t8, 0x3C0
    ctx->r8 = ADD32(ctx->r24, 0X3C0);
    // 0x800C35DC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800C35E0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C35E4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800C35E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C35EC: jal         0x800C2F10
    // 0x800C35F0: sw          $zero, -0x529C($at)
    MEM_W(-0X529C, ctx->r1) = 0;
    init_dialogue_text(rdram, ctx);
        goto after_1;
    // 0x800C35F0: sw          $zero, -0x529C($at)
    MEM_W(-0X529C, ctx->r1) = 0;
    after_1:
    // 0x800C35F4: jal         0x800772DC
    // 0x800C35F8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    asset_table_size(rdram, ctx);
        goto after_2;
    // 0x800C35F8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
    // 0x800C35FC: sra         $t1, $v0, 2
    ctx->r9 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800C3600: addiu       $t2, $t1, -0x2
    ctx->r10 = ADD32(ctx->r9, -0X2);
    // 0x800C3604: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C360C: sh          $t2, -0x52B0($at)
    MEM_H(-0X52B0, ctx->r1) = ctx->r10;
    // 0x800C3610: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C3614: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C3618: sb          $t3, 0x3C00($at)
    MEM_B(0X3C00, ctx->r1) = ctx->r11;
    // 0x800C361C: jr          $ra
    // 0x800C3620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C3620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void update_envmap_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D614: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001D618: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D61C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8001D620: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x8001D624: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001D628: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001D62C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8001D630: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D634: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8001D638: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001D63C: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8001D640: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x8001D644: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8001D648: jal         0x800CA030
    // 0x8001D64C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001D64C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8001D650: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001D654: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001D658: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x8001D65C: lui         $at, 0xC600
    ctx->r1 = S32(0XC600 << 16);
    // 0x8001D660: bc1t        L_8001D68C
    if (c1cs) {
        // 0x8001D664: nop
    
            goto L_8001D68C;
    }
    // 0x8001D664: nop

    // 0x8001D668: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001D66C: nop

    // 0x8001D670: div.s       $f2, $f18, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8001D674: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8001D678: nop

    // 0x8001D67C: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8001D680: nop

    // 0x8001D684: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8001D688: nop

L_8001D68C:
    // 0x8001D68C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001D690: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001D694: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001D698: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D69C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D6A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D6A4: cvt.w.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = CVT_W_S(ctx->f20.fl);
    // 0x8001D6A8: addiu       $v0, $v0, -0x4A98
    ctx->r2 = ADD32(ctx->r2, -0X4A98);
    // 0x8001D6AC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001D6B0: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8001D6B4: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001D6B8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001D6BC: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8001D6C0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001D6C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D6C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D6CC: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8001D6D0: cvt.w.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = CVT_W_S(ctx->f14.fl);
    // 0x8001D6D4: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8001D6D8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001D6DC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8001D6E0: nop

    // 0x8001D6E4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8001D6E8: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x8001D6EC: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8001D6F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D6F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D6F8: nop

    // 0x8001D6FC: cvt.w.s     $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    ctx->f8.u32l = CVT_W_S(ctx->f22.fl);
    // 0x8001D700: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001D704: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8001D708: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8001D70C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D710: jr          $ra
    // 0x8001D714: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
    return;
    // 0x8001D714: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void func_8002AC00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AC40: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8002AC44: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x8002AC48: nop

    // 0x8002AC4C: lh          $v1, 0x1A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X1A);
    // 0x8002AC50: nop

    // 0x8002AC54: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002AC58: beq         $at, $zero, L_8002ACD8
    if (ctx->r1 == 0) {
        // 0x8002AC5C: slt         $at, $a1, $v1
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8002ACD8;
    }
    // 0x8002AC5C: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002AC60: beq         $at, $zero, L_8002ACD8
    if (ctx->r1 == 0) {
        // 0x8002AC64: sll         $t7, $a0, 4
        ctx->r15 = S32(ctx->r4 << 4);
            goto L_8002ACD8;
    }
    // 0x8002AC64: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x8002AC68: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8002AC6C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8002AC70: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002AC74: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8002AC78: lh          $v1, 0x28($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X28);
    // 0x8002AC7C: beq         $a2, $zero, L_8002ACB0
    if (ctx->r6 == 0) {
        // 0x8002AC80: sra         $t0, $a1, 3
        ctx->r8 = S32(SIGNED(ctx->r5) >> 3);
            goto L_8002ACB0;
    }
    // 0x8002AC80: sra         $t0, $a1, 3
    ctx->r8 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8002AC84: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x8002AC88: sra         $t1, $a1, 3
    ctx->r9 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8002AC8C: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x8002AC90: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x8002AC94: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
    // 0x8002AC98: andi        $t3, $a1, 0x7
    ctx->r11 = ctx->r5 & 0X7;
    // 0x8002AC9C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8002ACA0: sllv        $t6, $t4, $t3
    ctx->r14 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x8002ACA4: or          $t7, $t2, $t6
    ctx->r15 = ctx->r10 | ctx->r14;
    // 0x8002ACA8: jr          $ra
    // 0x8002ACAC: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x8002ACAC: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
L_8002ACB0:
    // 0x8002ACB0: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x8002ACB4: andi        $t4, $a1, 0x7
    ctx->r12 = ctx->r5 & 0X7;
    // 0x8002ACB8: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8002ACBC: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x8002ACC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002ACC4: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    // 0x8002ACC8: sllv        $t2, $t3, $t4
    ctx->r10 = S32(ctx->r11 << (ctx->r12 & 31));
    // 0x8002ACCC: nor         $t6, $t2, $zero
    ctx->r14 = ~(ctx->r10 | 0);
    // 0x8002ACD0: and         $t7, $t1, $t6
    ctx->r15 = ctx->r9 & ctx->r14;
    // 0x8002ACD4: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
L_8002ACD8:
    // 0x8002ACD8: jr          $ra
    // 0x8002ACDC: nop

    return;
    // 0x8002ACDC: nop

;}
RECOMP_FUNC void handle_racer_items(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055F00: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80055F04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80055F08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80055F0C: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80055F10: sh          $zero, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = 0;
    // 0x80055F14: lw          $v0, 0x144($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X144);
    // 0x80055F18: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80055F1C: beq         $v0, $zero, L_800560EC
    if (ctx->r2 == 0) {
        // 0x80055F20: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800560EC;
    }
    // 0x80055F20: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80055F24: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80055F28: addiu       $a1, $a1, -0x2554
    ctx->r5 = ADD32(ctx->r5, -0X2554);
    // 0x80055F2C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80055F30: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80055F34: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x80055F38: bne         $t7, $zero, L_80055F60
    if (ctx->r15 != 0) {
        // 0x80055F3C: nop
    
            goto L_80055F60;
    }
    // 0x80055F3C: nop

    // 0x80055F40: lb          $t8, 0x1D8($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D8);
    // 0x80055F44: nop

    // 0x80055F48: bne         $t8, $zero, L_80055F60
    if (ctx->r24 != 0) {
        // 0x80055F4C: nop
    
            goto L_80055F60;
    }
    // 0x80055F4C: nop

    // 0x80055F50: lb          $t9, 0x187($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X187);
    // 0x80055F54: nop

    // 0x80055F58: beq         $t9, $zero, L_80056964
    if (ctx->r25 == 0) {
        // 0x80055F5C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80056964;
    }
    // 0x80055F5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80055F60:
    // 0x80055F60: lb          $t4, 0x3A($a3)
    ctx->r12 = MEM_B(ctx->r7, 0X3A);
    // 0x80055F64: lw          $t3, 0x68($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X68);
    // 0x80055F68: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80055F6C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80055F70: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80055F74: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80055F78: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80055F7C: beq         $v0, $zero, L_80056008
    if (ctx->r2 == 0) {
        // 0x80055F80: nop
    
            goto L_80056008;
    }
    // 0x80055F80: nop

    // 0x80055F84: lw          $t7, 0x40($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X40);
    // 0x80055F88: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80055F8C: lb          $a0, 0x58($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X58);
    // 0x80055F90: nop

    // 0x80055F94: bltz        $a0, L_80056008
    if (SIGNED(ctx->r4) < 0) {
        // 0x80055F98: nop
    
            goto L_80056008;
    }
    // 0x80055F98: nop

    // 0x80055F9C: lh          $t8, 0x18($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X18);
    // 0x80055FA0: nop

    // 0x80055FA4: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80055FA8: beq         $at, $zero, L_80056008
    if (ctx->r1 == 0) {
        // 0x80055FAC: nop
    
            goto L_80056008;
    }
    // 0x80055FAC: nop

    // 0x80055FB0: lw          $a2, 0x44($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X44);
    // 0x80055FB4: nop

    // 0x80055FB8: beq         $a2, $zero, L_80056008
    if (ctx->r6 == 0) {
        // 0x80055FBC: nop
    
            goto L_80056008;
    }
    // 0x80055FBC: nop

    // 0x80055FC0: lw          $t9, 0x14($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X14);
    // 0x80055FC4: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x80055FC8: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x80055FCC: lh          $t5, 0x0($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X0);
    // 0x80055FD0: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80055FD4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80055FD8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80055FDC: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80055FE0: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x80055FE4: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80055FE8: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x80055FEC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80055FF0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80055FF4: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80055FF8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80055FFC: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80056000: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80056004: nop

L_80056008:
    // 0x80056008: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8005600C: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80056010: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80056014: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80056018: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005601C: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x80056020: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80056024: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80056028: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8005602C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80056030: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80056034: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x80056038: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8005603C: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80056040: mul.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80056044: lwc1        $f8, 0x10($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80056048: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8005604C: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80056050: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80056054: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x80056058: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8005605C: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80056060: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80056064: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80056068: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8005606C: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80056070: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80056074: swc1        $f4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f4.u32l;
    // 0x80056078: lh          $t9, 0x2E($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X2E);
    // 0x8005607C: nop

    // 0x80056080: sh          $t9, 0x2E($v1)
    MEM_H(0X2E, ctx->r3) = ctx->r25;
    // 0x80056084: lwc1        $f8, 0x1C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x80056088: lwc1        $f0, 0x6DDC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6DDC);
    // 0x8005608C: lwc1        $f1, 0x6DD8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6DD8);
    // 0x80056090: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80056094: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x80056098: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005609C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800560A0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800560A4: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800560A8: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x800560AC: lwc1        $f16, 0x20($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X20);
    // 0x800560B0: nop

    // 0x800560B4: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800560B8: sub.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d - ctx->f8.d;
    // 0x800560BC: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800560C0: swc1        $f10, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f10.u32l;
    // 0x800560C4: lwc1        $f18, 0x24($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X24);
    // 0x800560C8: nop

    // 0x800560CC: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800560D0: mul.d       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x800560D4: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800560D8: swc1        $f8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f8.u32l;
    // 0x800560DC: sb          $t4, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r12;
    // 0x800560E0: sw          $zero, 0x144($s0)
    MEM_W(0X144, ctx->r16) = 0;
    // 0x800560E4: b           L_80056960
    // 0x800560E8: sb          $t3, 0x211($s0)
    MEM_B(0X211, ctx->r16) = ctx->r11;
        goto L_80056960;
    // 0x800560E8: sb          $t3, 0x211($s0)
    MEM_B(0X211, ctx->r16) = ctx->r11;
L_800560EC:
    // 0x800560EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800560F0: addiu       $a1, $a1, -0x2554
    ctx->r5 = ADD32(ctx->r5, -0X2554);
    // 0x800560F4: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800560F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800560FC: andi        $t6, $t5, 0x2000
    ctx->r14 = ctx->r13 & 0X2000;
    // 0x80056100: beq         $t6, $zero, L_8005610C
    if (ctx->r14 == 0) {
        // 0x80056104: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_8005610C;
    }
    // 0x80056104: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80056108: sb          $zero, 0x211($s0)
    MEM_B(0X211, ctx->r16) = 0;
L_8005610C:
    // 0x8005610C: lb          $t7, 0x211($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X211);
    // 0x80056110: nop

    // 0x80056114: beq         $t7, $zero, L_80056130
    if (ctx->r15 == 0) {
        // 0x80056118: nop
    
            goto L_80056130;
    }
    // 0x80056118: nop

    // 0x8005611C: sw          $zero, -0x2550($at)
    MEM_W(-0X2550, ctx->r1) = 0;
    // 0x80056120: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80056124: addiu       $at, $zero, -0x2001
    ctx->r1 = ADD32(0, -0X2001);
    // 0x80056128: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8005612C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_80056130:
    // 0x80056130: lb          $t4, 0x175($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X175);
    // 0x80056134: nop

    // 0x80056138: bne         $t4, $zero, L_80056144
    if (ctx->r12 != 0) {
        // 0x8005613C: nop
    
            goto L_80056144;
    }
    // 0x8005613C: nop

    // 0x80056140: sw          $zero, 0x140($s0)
    MEM_W(0X140, ctx->r16) = 0;
L_80056144:
    // 0x80056144: lb          $t3, 0x172($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X172);
    // 0x80056148: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005614C: bne         $t3, $at, L_80056158
    if (ctx->r11 != ctx->r1) {
        // 0x80056150: nop
    
            goto L_80056158;
    }
    // 0x80056150: nop

    // 0x80056154: sb          $zero, 0x173($s0)
    MEM_B(0X173, ctx->r16) = 0;
L_80056158:
    // 0x80056158: lb          $t5, 0x173($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X173);
    // 0x8005615C: nop

    // 0x80056160: bgtz        $t5, L_8005618C
    if (SIGNED(ctx->r13) > 0) {
        // 0x80056164: nop
    
            goto L_8005618C;
    }
    // 0x80056164: nop

    // 0x80056168: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8005616C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80056170: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x80056174: beq         $t7, $zero, L_80056964
    if (ctx->r15 == 0) {
        // 0x80056178: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80056964;
    }
    // 0x80056178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005617C: jal         0x80056970
    // 0x80056180: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    play_char_horn_sound(rdram, ctx);
        goto after_0;
    // 0x80056180: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80056184: b           L_80056964
    // 0x80056188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80056964;
    // 0x80056188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005618C:
    // 0x8005618C: jal         0x8001E2D0
    // 0x80056190: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x80056190: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    after_1:
    // 0x80056194: lb          $t8, 0x172($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X172);
    // 0x80056198: lb          $t4, 0x174($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X174);
    // 0x8005619C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800561A0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800561A4: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800561A8: sll         $t3, $t4, 1
    ctx->r11 = S32(ctx->r12 << 1);
    // 0x800561AC: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x800561B0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800561B4: lb          $t0, 0x0($t6)
    ctx->r8 = MEM_B(ctx->r14, 0X0);
    // 0x800561B8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800561BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800561C0: bne         $t0, $at, L_800561D0
    if (ctx->r8 != ctx->r1) {
        // 0x800561C4: addiu       $a1, $a1, -0x2554
        ctx->r5 = ADD32(ctx->r5, -0X2554);
            goto L_800561D0;
    }
    // 0x800561C4: addiu       $a1, $a1, -0x2554
    ctx->r5 = ADD32(ctx->r5, -0X2554);
    // 0x800561C8: b           L_80056960
    // 0x800561CC: sb          $zero, 0x173($s0)
    MEM_B(0X173, ctx->r16) = 0;
        goto L_80056960;
    // 0x800561CC: sb          $zero, 0x173($s0)
    MEM_B(0X173, ctx->r16) = 0;
L_800561D0:
    // 0x800561D0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800561D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800561D8: andi        $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 & 0X2000;
    // 0x800561DC: beq         $t8, $zero, L_80056200
    if (ctx->r24 == 0) {
        // 0x800561E0: addiu       $a0, $zero, 0x13E
        ctx->r4 = ADD32(0, 0X13E);
            goto L_80056200;
    }
    // 0x800561E0: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    // 0x800561E4: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x800561E8: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x800561EC: jal         0x800A7A48
    // 0x800561F0: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    hud_sound_stop(rdram, ctx);
        goto after_2;
    // 0x800561F0: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    after_2:
    // 0x800561F4: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800561F8: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800561FC: nop

L_80056200:
    // 0x80056200: lb          $t4, 0x195($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X195);
    // 0x80056204: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80056208: beq         $t4, $zero, L_80056224
    if (ctx->r12 == 0) {
        // 0x8005620C: nop
    
            goto L_80056224;
    }
    // 0x8005620C: nop

    // 0x80056210: lb          $t9, 0x175($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X175);
    // 0x80056214: nop

    // 0x80056218: bne         $t9, $zero, L_80056964
    if (ctx->r25 != 0) {
        // 0x8005621C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80056964;
    }
    // 0x8005621C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80056220: sb          $zero, 0x195($s0)
    MEM_B(0X195, ctx->r16) = 0;
L_80056224:
    // 0x80056224: lw          $t3, -0x2558($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2558);
    // 0x80056228: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005622C: andi        $t5, $t3, 0x2000
    ctx->r13 = ctx->r11 & 0X2000;
    // 0x80056230: bne         $t5, $zero, L_8005624C
    if (ctx->r13 != 0) {
        // 0x80056234: nop
    
            goto L_8005624C;
    }
    // 0x80056234: nop

    // 0x80056238: lw          $v1, -0x2550($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2550);
    // 0x8005623C: nop

    // 0x80056240: andi        $t6, $v1, 0x2000
    ctx->r14 = ctx->r3 & 0X2000;
    // 0x80056244: beq         $t6, $zero, L_8005635C
    if (ctx->r14 == 0) {
        // 0x80056248: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8005635C;
    }
    // 0x80056248: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8005624C:
    // 0x8005624C: beq         $t0, $zero, L_80056288
    if (ctx->r8 == 0) {
        // 0x80056250: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80056288;
    }
    // 0x80056250: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80056254: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80056258: beq         $t0, $at, L_800562C4
    if (ctx->r8 == ctx->r1) {
        // 0x8005625C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800562C4;
    }
    // 0x8005625C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80056260: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80056264: beq         $t0, $at, L_800562C4
    if (ctx->r8 == ctx->r1) {
        // 0x80056268: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_800562C4;
    }
    // 0x80056268: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005626C: beq         $t0, $at, L_800562C4
    if (ctx->r8 == ctx->r1) {
        // 0x80056270: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800562C4;
    }
    // 0x80056270: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80056274: lw          $v1, -0x2550($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2550);
    // 0x80056278: nop

    // 0x8005627C: andi        $t7, $v1, 0x2000
    ctx->r15 = ctx->r3 & 0X2000;
    // 0x80056280: b           L_8005635C
    // 0x80056284: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_8005635C;
    // 0x80056284: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_80056288:
    // 0x80056288: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x8005628C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x80056290: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x80056294: jal         0x800569CC
    // 0x80056298: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    func_8005698C(rdram, ctx);
        goto after_3;
    // 0x80056298: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_3:
    // 0x8005629C: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800562A0: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800562A4: sb          $zero, 0x175($s0)
    MEM_B(0X175, ctx->r16) = 0;
    // 0x800562A8: sw          $v0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->r2;
    // 0x800562AC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800562B0: lw          $v1, -0x2550($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2550);
    // 0x800562B4: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x800562B8: andi        $t8, $v1, 0x2000
    ctx->r24 = ctx->r3 & 0X2000;
    // 0x800562BC: b           L_8005635C
    // 0x800562C0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
        goto L_8005635C;
    // 0x800562C0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800562C4:
    // 0x800562C4: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x800562C8: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x800562CC: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x800562D0: jal         0x800569CC
    // 0x800562D4: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    func_8005698C(rdram, ctx);
        goto after_4;
    // 0x800562D4: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_4:
    // 0x800562D8: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800562DC: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800562E0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800562E4: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800562E8: bne         $t0, $at, L_80056300
    if (ctx->r8 != ctx->r1) {
        // 0x800562EC: sb          $zero, 0x175($s0)
        MEM_B(0X175, ctx->r16) = 0;
            goto L_80056300;
    }
    // 0x800562EC: sb          $zero, 0x175($s0)
    MEM_B(0X175, ctx->r16) = 0;
    // 0x800562F0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800562F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800562F8: b           L_80056310
    // 0x800562FC: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
        goto L_80056310;
    // 0x800562FC: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
L_80056300:
    // 0x80056300: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80056304: lwc1        $f0, 0x6DE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6DE0);
    // 0x80056308: nop

    // 0x8005630C: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
L_80056310:
    // 0x80056310: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80056314: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80056318: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005631C: bc1f        L_80056344
    if (!c1cs) {
        // 0x80056320: nop
    
            goto L_80056344;
    }
    // 0x80056320: nop

    // 0x80056324: bne         $t0, $at, L_8005633C
    if (ctx->r8 != ctx->r1) {
        // 0x80056328: nop
    
            goto L_8005633C;
    }
    // 0x80056328: nop

    // 0x8005632C: beq         $v0, $zero, L_8005633C
    if (ctx->r2 == 0) {
        // 0x80056330: nop
    
            goto L_8005633C;
    }
    // 0x80056330: nop

    // 0x80056334: lw          $a3, 0x64($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X64);
    // 0x80056338: nop

L_8005633C:
    // 0x8005633C: b           L_8005634C
    // 0x80056340: sw          $v0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->r2;
        goto L_8005634C;
    // 0x80056340: sw          $v0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->r2;
L_80056344:
    // 0x80056344: sw          $zero, 0x140($s0)
    MEM_W(0X140, ctx->r16) = 0;
    // 0x80056348: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8005634C:
    // 0x8005634C: lw          $v1, -0x2550($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2550);
    // 0x80056350: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
    // 0x80056354: andi        $t4, $v1, 0x2000
    ctx->r12 = ctx->r3 & 0X2000;
    // 0x80056358: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_8005635C:
    // 0x8005635C: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80056360: beq         $v1, $zero, L_80056960
    if (ctx->r3 == 0) {
        // 0x80056364: addiu       $v0, $zero, 0x1D
        ctx->r2 = ADD32(0, 0X1D);
            goto L_80056960;
    }
    // 0x80056364: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    // 0x80056368: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8005636C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80056370: sltiu       $at, $t0, 0x10
    ctx->r1 = ctx->r8 < 0X10 ? 1 : 0;
    // 0x80056374: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80056378: beq         $at, $zero, L_80056660
    if (ctx->r1 == 0) {
        // 0x8005637C: or          $t9, $t0, $zero
        ctx->r25 = ctx->r8 | 0;
            goto L_80056660;
    }
    // 0x8005637C: or          $t9, $t0, $zero
    ctx->r25 = ctx->r8 | 0;
    // 0x80056380: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80056384: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80056388: addu        $at, $at, $t9
    gpr jr_addend_80056394 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8005638C: lw          $t9, 0x6DE4($at)
    ctx->r25 = ADD32(ctx->r1, 0X6DE4);
    // 0x80056390: nop

    // 0x80056394: jr          $t9
    // 0x80056398: nop

    switch (jr_addend_80056394 >> 2) {
        case 0: goto L_8005639C; break;
        case 1: goto L_800563B0; break;
        case 2: goto L_800563C0; break;
        case 3: goto L_800563DC; break;
        case 4: goto L_8005642C; break;
        case 5: goto L_80056548; break;
        case 6: goto L_8005659C; break;
        case 7: goto L_80056548; break;
        case 8: goto L_8005642C; break;
        case 9: goto L_80056660; break;
        case 10: goto L_8005640C; break;
        case 11: goto L_800563C0; break;
        case 12: goto L_80056600; break;
        case 13: goto L_80056620; break;
        case 14: goto L_80056640; break;
        case 15: goto L_8005642C; break;
        default: switch_error(__func__, 0x80056394, 0x800E6DE4);
    }
    // 0x80056398: nop

L_8005639C:
    // 0x8005639C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800563A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800563A4: addiu       $v0, $zero, 0xE5
    ctx->r2 = ADD32(0, 0XE5);
    // 0x800563A8: b           L_8005666C
    // 0x800563AC: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
        goto L_8005666C;
    // 0x800563AC: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
L_800563B0:
    // 0x800563B0: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800563B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800563B8: b           L_8005666C
    // 0x800563BC: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
        goto L_8005666C;
    // 0x800563BC: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
L_800563C0:
    // 0x800563C0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800563C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800563C8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800563CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800563D0: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x800563D4: b           L_8005666C
    // 0x800563D8: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
        goto L_8005666C;
    // 0x800563D8: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
L_800563DC:
    // 0x800563DC: lb          $t3, 0x1D6($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D6);
    // 0x800563E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800563E4: beq         $t3, $at, L_800563F4
    if (ctx->r11 == ctx->r1) {
        // 0x800563E8: addiu       $v0, $zero, 0xEB
        ctx->r2 = ADD32(0, 0XEB);
            goto L_800563F4;
    }
    // 0x800563E8: addiu       $v0, $zero, 0xEB
    ctx->r2 = ADD32(0, 0XEB);
    // 0x800563EC: b           L_800563F4
    // 0x800563F0: addiu       $v0, $zero, 0x82
    ctx->r2 = ADD32(0, 0X82);
        goto L_800563F4;
    // 0x800563F0: addiu       $v0, $zero, 0x82
    ctx->r2 = ADD32(0, 0X82);
L_800563F4:
    // 0x800563F4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800563F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800563FC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80056400: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80056404: b           L_8005666C
    // 0x80056408: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
        goto L_8005666C;
    // 0x80056408: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
L_8005640C:
    // 0x8005640C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80056410: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80056414: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80056418: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005641C: addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    // 0x80056420: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80056424: b           L_8005666C
    // 0x80056428: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
        goto L_8005666C;
    // 0x80056428: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
L_8005642C:
    // 0x8005642C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80056430: beq         $t0, $at, L_80056458
    if (ctx->r8 == ctx->r1) {
        // 0x80056434: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80056458;
    }
    // 0x80056434: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80056438: bne         $t0, $at, L_80056470
    if (ctx->r8 != ctx->r1) {
        // 0x8005643C: nop
    
            goto L_80056470;
    }
    // 0x8005643C: nop

    // 0x80056440: jal         0x8000C8B4
    // 0x80056444: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    normalise_time(rdram, ctx);
        goto after_5;
    // 0x80056444: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_5:
    // 0x80056448: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8005644C: sb          $t5, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r13;
    // 0x80056450: b           L_80056480
    // 0x80056454: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
        goto L_80056480;
    // 0x80056454: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
L_80056458:
    // 0x80056458: jal         0x8000C8B4
    // 0x8005645C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    normalise_time(rdram, ctx);
        goto after_6;
    // 0x8005645C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_6:
    // 0x80056460: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80056464: sb          $t6, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r14;
    // 0x80056468: b           L_80056480
    // 0x8005646C: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
        goto L_80056480;
    // 0x8005646C: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
L_80056470:
    // 0x80056470: jal         0x8000C8B4
    // 0x80056474: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    normalise_time(rdram, ctx);
        goto after_7;
    // 0x80056474: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_7:
    // 0x80056478: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x8005647C: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
L_80056480:
    // 0x80056480: lbu         $t7, 0x20C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X20C);
    // 0x80056484: nop

    // 0x80056488: beq         $t7, $zero, L_800564A4
    if (ctx->r15 == 0) {
        // 0x8005648C: lw          $t9, 0x30($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X30);
            goto L_800564A4;
    }
    // 0x8005648C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80056490: lb          $t8, 0x203($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X203);
    // 0x80056494: nop

    // 0x80056498: ori         $t4, $t8, 0x4
    ctx->r12 = ctx->r24 | 0X4;
    // 0x8005649C: sb          $t4, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r12;
    // 0x800564A0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
L_800564A4:
    // 0x800564A4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800564A8: bne         $t9, $at, L_800564D8
    if (ctx->r25 != ctx->r1) {
        // 0x800564AC: lw          $a0, 0x88($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X88);
            goto L_800564D8;
    }
    // 0x800564AC: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x800564B0: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x800564B4: jal         0x80057088
    // 0x800564B8: addiu       $a1, $zero, 0x232
    ctx->r5 = ADD32(0, 0X232);
    racer_play_sound(rdram, ctx);
        goto after_8;
    // 0x800564B8: addiu       $a1, $zero, 0x232
    ctx->r5 = ADD32(0, 0X232);
    after_8:
    // 0x800564BC: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x800564C0: addiu       $a1, $zero, 0x233
    ctx->r5 = ADD32(0, 0X233);
    // 0x800564C4: jal         0x800570E4
    // 0x800564C8: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    racer_play_sound_after_delay(rdram, ctx);
        goto after_9;
    // 0x800564C8: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_9:
    // 0x800564CC: b           L_800564E4
    // 0x800564D0: lb          $t3, 0x173($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X173);
        goto L_800564E4;
    // 0x800564D0: lb          $t3, 0x173($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X173);
    // 0x800564D4: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
L_800564D8:
    // 0x800564D8: jal         0x80057088
    // 0x800564DC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    racer_play_sound(rdram, ctx);
        goto after_10;
    // 0x800564DC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_10:
    // 0x800564E0: lb          $t3, 0x173($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X173);
L_800564E4:
    // 0x800564E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800564E8: addiu       $t5, $t3, -0x1
    ctx->r13 = ADD32(ctx->r11, -0X1);
    // 0x800564EC: sb          $t5, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r13;
    // 0x800564F0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800564F4: nop

    // 0x800564F8: bne         $t6, $at, L_80056524
    if (ctx->r14 != ctx->r1) {
        // 0x800564FC: nop
    
            goto L_80056524;
    }
    // 0x800564FC: nop

    // 0x80056500: lb          $t7, 0x1D8($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D8);
    // 0x80056504: nop

    // 0x80056508: bne         $t7, $zero, L_80056964
    if (ctx->r15 != 0) {
        // 0x8005650C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80056964;
    }
    // 0x8005650C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80056510: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80056514: jal         0x80072594
    // 0x80056518: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    rumble_set(rdram, ctx);
        goto after_11;
    // 0x80056518: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_11:
    // 0x8005651C: b           L_80056964
    // 0x80056520: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80056964;
    // 0x80056520: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80056524:
    // 0x80056524: lb          $t8, 0x1D8($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D8);
    // 0x80056528: nop

    // 0x8005652C: bne         $t8, $zero, L_80056964
    if (ctx->r24 != 0) {
        // 0x80056530: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80056964;
    }
    // 0x80056530: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80056534: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80056538: jal         0x80072594
    // 0x8005653C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_12;
    // 0x8005653C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_12:
    // 0x80056540: b           L_80056964
    // 0x80056544: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80056964;
    // 0x80056544: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80056548:
    // 0x80056548: lb          $t4, 0x173($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X173);
    // 0x8005654C: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x80056550: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056554: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x80056558: beq         $t3, $at, L_80056960
    if (ctx->r11 == ctx->r1) {
        // 0x8005655C: sb          $t9, 0x173($s0)
        MEM_B(0X173, ctx->r16) = ctx->r25;
            goto L_80056960;
    }
    // 0x8005655C: sb          $t9, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r25;
    // 0x80056560: beq         $t2, $zero, L_80056578
    if (ctx->r10 == 0) {
        // 0x80056564: addiu       $t5, $zero, 0x5A
        ctx->r13 = ADD32(0, 0X5A);
            goto L_80056578;
    }
    // 0x80056564: addiu       $t5, $zero, 0x5A
    ctx->r13 = ADD32(0, 0X5A);
    // 0x80056568: addiu       $t6, $t0, -0x5
    ctx->r14 = ADD32(ctx->r8, -0X5);
    // 0x8005656C: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80056570: sb          $t5, 0x175($s0)
    MEM_B(0X175, ctx->r16) = ctx->r13;
    // 0x80056574: sb          $t7, 0x184($s0)
    MEM_B(0X184, ctx->r16) = ctx->r15;
L_80056578:
    // 0x80056578: lb          $t8, 0x1D8($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005657C: nop

    // 0x80056580: bne         $t8, $zero, L_80056964
    if (ctx->r24 != 0) {
        // 0x80056584: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80056964;
    }
    // 0x80056584: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80056588: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8005658C: jal         0x80072594
    // 0x80056590: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    rumble_set(rdram, ctx);
        goto after_13;
    // 0x80056590: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_13:
    // 0x80056594: b           L_80056964
    // 0x80056598: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80056964;
    // 0x80056598: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005659C:
    // 0x8005659C: lb          $t4, 0x173($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X173);
    // 0x800565A0: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x800565A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800565A8: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x800565AC: sb          $t9, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r25;
    // 0x800565B0: beq         $t3, $at, L_80056960
    if (ctx->r11 == ctx->r1) {
        // 0x800565B4: sw          $zero, 0x140($s0)
        MEM_W(0X140, ctx->r16) = 0;
            goto L_80056960;
    }
    // 0x800565B4: sw          $zero, 0x140($s0)
    MEM_W(0X140, ctx->r16) = 0;
    // 0x800565B8: beq         $a3, $zero, L_800565DC
    if (ctx->r7 == 0) {
        // 0x800565BC: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_800565DC;
    }
    // 0x800565BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800565C0: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x800565C4: sb          $t5, 0x195($a3)
    MEM_B(0X195, ctx->r7) = ctx->r13;
    // 0x800565C8: sb          $t6, 0x175($a3)
    MEM_B(0X175, ctx->r7) = ctx->r14;
    // 0x800565CC: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x800565D0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800565D4: sb          $t8, 0x184($a3)
    MEM_B(0X184, ctx->r7) = ctx->r24;
    // 0x800565D8: sw          $t7, 0x140($a3)
    MEM_W(0X140, ctx->r7) = ctx->r15;
L_800565DC:
    // 0x800565DC: lb          $t4, 0x1D8($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D8);
    // 0x800565E0: nop

    // 0x800565E4: bne         $t4, $zero, L_80056964
    if (ctx->r12 != 0) {
        // 0x800565E8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80056964;
    }
    // 0x800565E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800565EC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800565F0: jal         0x80072594
    // 0x800565F4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    rumble_set(rdram, ctx);
        goto after_14;
    // 0x800565F4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_14:
    // 0x800565F8: b           L_80056964
    // 0x800565FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80056964;
    // 0x800565FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80056600:
    // 0x80056600: lb          $t5, 0x173($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X173);
    // 0x80056604: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80056608: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x8005660C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80056610: sb          $t9, 0x189($s0)
    MEM_B(0X189, ctx->r16) = ctx->r25;
    // 0x80056614: sh          $t3, 0x18E($s0)
    MEM_H(0X18E, ctx->r16) = ctx->r11;
    // 0x80056618: b           L_80056960
    // 0x8005661C: sb          $t6, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r14;
        goto L_80056960;
    // 0x8005661C: sb          $t6, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r14;
L_80056620:
    // 0x80056620: lb          $t8, 0x173($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X173);
    // 0x80056624: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80056628: addiu       $t9, $zero, 0x258
    ctx->r25 = ADD32(0, 0X258);
    // 0x8005662C: addiu       $t4, $t8, -0x1
    ctx->r12 = ADD32(ctx->r24, -0X1);
    // 0x80056630: sb          $t7, 0x189($s0)
    MEM_B(0X189, ctx->r16) = ctx->r15;
    // 0x80056634: sb          $t4, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r12;
    // 0x80056638: b           L_80056960
    // 0x8005663C: sh          $t9, 0x18E($s0)
    MEM_H(0X18E, ctx->r16) = ctx->r25;
        goto L_80056960;
    // 0x8005663C: sh          $t9, 0x18E($s0)
    MEM_H(0X18E, ctx->r16) = ctx->r25;
L_80056640:
    // 0x80056640: lb          $t6, 0x173($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X173);
    // 0x80056644: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80056648: addiu       $t5, $zero, 0x384
    ctx->r13 = ADD32(0, 0X384);
    // 0x8005664C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80056650: sb          $t3, 0x189($s0)
    MEM_B(0X189, ctx->r16) = ctx->r11;
    // 0x80056654: sh          $t5, 0x18E($s0)
    MEM_H(0X18E, ctx->r16) = ctx->r13;
    // 0x80056658: b           L_80056960
    // 0x8005665C: sb          $t7, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r15;
        goto L_80056960;
    // 0x8005665C: sb          $t7, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r15;
L_80056660:
    // 0x80056660: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80056664: nop

    // 0x80056668: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
L_8005666C:
    // 0x8005666C: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80056670: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x80056674: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80056678: addiu       $a3, $zero, 0x81
    ctx->r7 = ADD32(0, 0X81);
    // 0x8005667C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80056680: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x80056684: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
    // 0x80056688: jal         0x800570F8
    // 0x8005668C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    play_random_character_voice(rdram, ctx);
        goto after_15;
    // 0x8005668C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_15:
    // 0x80056690: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80056694: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80056698: lw          $v1, 0x88($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X88);
    // 0x8005669C: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800566A0: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800566A4: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x800566A8: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800566AC: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800566B0: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x800566B4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800566B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800566BC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800566C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800566C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800566C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800566CC: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800566D0: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800566D4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800566D8: sh          $t4, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r12;
    // 0x800566DC: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800566E0: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800566E4: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800566E8: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800566EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800566F0: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800566F4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800566F8: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800566FC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80056700: nop

    // 0x80056704: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80056708: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005670C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80056710: nop

    // 0x80056714: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80056718: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8005671C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80056720: sh          $t3, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r11;
    // 0x80056724: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80056728: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8005672C: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80056730: sb          $t7, 0x81($sp)
    MEM_B(0X81, ctx->r29) = ctx->r15;
    // 0x80056734: sb          $v0, 0x80($sp)
    MEM_B(0X80, ctx->r29) = ctx->r2;
    // 0x80056738: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8005673C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80056740: nop

    // 0x80056744: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80056748: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005674C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80056750: nop

    // 0x80056754: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80056758: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8005675C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80056760: jal         0x8000EA54
    // 0x80056764: sh          $t6, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r14;
    spawn_object(rdram, ctx);
        goto after_16;
    // 0x80056764: sh          $t6, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r14;
    after_16:
    // 0x80056768: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x8005676C: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80056770: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80056774: beq         $v0, $zero, L_80056944
    if (ctx->r2 == 0) {
        // 0x80056778: nop
    
            goto L_80056944;
    }
    // 0x80056778: nop

    // 0x8005677C: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x80056780: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80056784: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80056788: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x8005678C: mul.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80056790: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80056794: sub.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80056798: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x8005679C: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800567A0: lwc1        $f4, 0x20($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X20);
    // 0x800567A4: mul.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800567A8: sub.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800567AC: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x800567B0: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800567B4: lwc1        $f16, 0x24($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X24);
    // 0x800567B8: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800567BC: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800567C0: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x800567C4: lh          $t8, 0x0($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X0);
    // 0x800567C8: nop

    // 0x800567CC: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800567D0: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x800567D4: nop

    // 0x800567D8: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    // 0x800567DC: lb          $t9, 0x1D6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D6);
    // 0x800567E0: nop

    // 0x800567E4: bne         $t9, $at, L_8005681C
    if (ctx->r25 != ctx->r1) {
        // 0x800567E8: nop
    
            goto L_8005681C;
    }
    // 0x800567E8: nop

    // 0x800567EC: lb          $t3, 0x1E5($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E5);
    // 0x800567F0: nop

    // 0x800567F4: beq         $t3, $zero, L_8005681C
    if (ctx->r11 == 0) {
        // 0x800567F8: nop
    
            goto L_8005681C;
    }
    // 0x800567F8: nop

    // 0x800567FC: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x80056800: nop

    // 0x80056804: slti        $at, $v1, -0x3FF
    ctx->r1 = SIGNED(ctx->r3) < -0X3FF ? 1 : 0;
    // 0x80056808: bne         $at, $zero, L_8005681C
    if (ctx->r1 != 0) {
        // 0x8005680C: slti        $at, $v1, 0x400
        ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
            goto L_8005681C;
    }
    // 0x8005680C: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x80056810: beq         $at, $zero, L_8005681C
    if (ctx->r1 == 0) {
        // 0x80056814: nop
    
            goto L_8005681C;
    }
    // 0x80056814: nop

    // 0x80056818: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
L_8005681C:
    // 0x8005681C: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80056820: andi        $t6, $t0, 0xFF
    ctx->r14 = ctx->r8 & 0XFF;
    // 0x80056824: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80056828: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8005682C: lb          $t5, 0x192($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X192);
    // 0x80056830: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x80056834: sb          $t5, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r13;
    // 0x80056838: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005683C: sb          $t0, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r8;
    // 0x80056840: sub.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80056844: beq         $at, $zero, L_800568C4
    if (ctx->r1 == 0) {
        // 0x80056848: swc1        $f10, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
            goto L_800568C4;
    }
    // 0x80056848: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    // 0x8005684C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80056850: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80056854: addu        $at, $at, $t6
    gpr jr_addend_80056860 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80056858: lw          $t6, 0x6E24($at)
    ctx->r14 = ADD32(ctx->r1, 0X6E24);
    // 0x8005685C: nop

    // 0x80056860: jr          $t6
    // 0x80056864: nop

    switch (jr_addend_80056860 >> 2) {
        case 0: goto L_80056868; break;
        case 1: goto L_80056874; break;
        case 2: goto L_80056880; break;
        case 3: goto L_8005688C; break;
        case 4: goto L_800568C4; break;
        case 5: goto L_800568C4; break;
        case 6: goto L_800568C4; break;
        case 7: goto L_800568C4; break;
        case 8: goto L_800568C4; break;
        case 9: goto L_800568C4; break;
        case 10: goto L_800568B4; break;
        case 11: goto L_800568C0; break;
        default: switch_error(__func__, 0x80056860, 0x800E6E24);
    }
    // 0x80056864: nop

L_80056868:
    // 0x80056868: addiu       $t7, $zero, 0x134
    ctx->r15 = ADD32(0, 0X134);
    // 0x8005686C: b           L_800568C4
    // 0x80056870: sh          $t7, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r15;
        goto L_800568C4;
    // 0x80056870: sh          $t7, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r15;
L_80056874:
    // 0x80056874: addiu       $t8, $zero, 0x135
    ctx->r24 = ADD32(0, 0X135);
    // 0x80056878: b           L_800568C4
    // 0x8005687C: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
        goto L_800568C4;
    // 0x8005687C: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
L_80056880:
    // 0x80056880: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x80056884: b           L_800568C4
    // 0x80056888: sh          $t4, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r12;
        goto L_800568C4;
    // 0x80056888: sh          $t4, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r12;
L_8005688C:
    // 0x8005688C: lb          $t9, 0x1D6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D6);
    // 0x80056890: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80056894: beq         $t9, $at, L_800568AC
    if (ctx->r25 == ctx->r1) {
        // 0x80056898: addiu       $t5, $zero, 0x151
        ctx->r13 = ADD32(0, 0X151);
            goto L_800568AC;
    }
    // 0x80056898: addiu       $t5, $zero, 0x151
    ctx->r13 = ADD32(0, 0X151);
    // 0x8005689C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800568A0: lw          $t3, 0x50($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X50);
    // 0x800568A4: nop

    // 0x800568A8: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
L_800568AC:
    // 0x800568AC: b           L_800568C4
    // 0x800568B0: sh          $t5, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r13;
        goto L_800568C4;
    // 0x800568B0: sh          $t5, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r13;
L_800568B4:
    // 0x800568B4: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x800568B8: b           L_800568C4
    // 0x800568BC: sh          $t6, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r14;
        goto L_800568C4;
    // 0x800568BC: sh          $t6, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r14;
L_800568C0:
    // 0x800568C0: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
L_800568C4:
    // 0x800568C4: lhu         $t7, 0x3A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X3A);
    // 0x800568C8: nop

    // 0x800568CC: beq         $t7, $zero, L_80056944
    if (ctx->r15 == 0) {
        // 0x800568D0: nop
    
            goto L_80056944;
    }
    // 0x800568D0: nop

    // 0x800568D4: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x800568D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800568DC: bne         $t8, $at, L_80056908
    if (ctx->r24 != ctx->r1) {
        // 0x800568E0: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_80056908;
    }
    // 0x800568E0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800568E4: lw          $a1, 0xC($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XC);
    // 0x800568E8: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    // 0x800568EC: lw          $a3, 0x14($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X14);
    // 0x800568F0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800568F4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800568F8: jal         0x80009558
    // 0x800568FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_17;
    // 0x800568FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_17:
    // 0x80056900: b           L_80056948
    // 0x80056904: lb          $v0, 0x173($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X173);
        goto L_80056948;
    // 0x80056904: lb          $v0, 0x173($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X173);
L_80056908:
    // 0x80056908: lw          $a0, 0x218($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X218);
    // 0x8005690C: nop

    // 0x80056910: beq         $a0, $zero, L_80056928
    if (ctx->r4 == 0) {
        // 0x80056914: nop
    
            goto L_80056928;
    }
    // 0x80056914: nop

    // 0x80056918: jal         0x8000488C
    // 0x8005691C: nop

    sndp_stop(rdram, ctx);
        goto after_18;
    // 0x8005691C: nop

    after_18:
    // 0x80056920: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x80056924: nop

L_80056928:
    // 0x80056928: lhu         $a0, 0x3A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X3A);
    // 0x8005692C: lw          $a1, 0xC($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XC);
    // 0x80056930: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    // 0x80056934: lw          $a3, 0x14($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X14);
    // 0x80056938: addiu       $t9, $s0, 0x218
    ctx->r25 = ADD32(ctx->r16, 0X218);
    // 0x8005693C: jal         0x80001EA8
    // 0x80056940: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    sound_play_spatial(rdram, ctx);
        goto after_19;
    // 0x80056940: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_19:
L_80056944:
    // 0x80056944: lb          $v0, 0x173($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X173);
L_80056948:
    // 0x80056948: nop

    // 0x8005694C: blez        $v0, L_8005695C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80056950: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8005695C;
    }
    // 0x80056950: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80056954: b           L_80056960
    // 0x80056958: sb          $t3, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r11;
        goto L_80056960;
    // 0x80056958: sb          $t3, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r11;
L_8005695C:
    // 0x8005695C: sb          $zero, 0x173($s0)
    MEM_B(0X173, ctx->r16) = 0;
L_80056960:
    // 0x80056960: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80056964:
    // 0x80056964: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80056968: jr          $ra
    // 0x8005696C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8005696C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800738A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073AFC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80073B00: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80073B04: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80073B08: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80073B0C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80073B10: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80073B14: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80073B18: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80073B1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80073B20: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80073B24: jal         0x8006B464
    // 0x80073B28: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    level_count(rdram, ctx);
        goto after_0;
    // 0x80073B28: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_0:
    // 0x80073B2C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80073B30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073B34: sw          $t6, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r14;
    // 0x80073B38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073B3C: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x80073B40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073B44: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80073B48: sw          $t7, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = ctx->r15;
    // 0x80073B4C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073B50: jal         0x80073080
    // 0x80073B54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80072E28(rdram, ctx);
        goto after_1;
    // 0x80073B54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80073B58: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80073B5C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80073B60: blez        $t8, L_80073C70
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80073B64: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80073C70;
    }
    // 0x80073B64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80073B68:
    // 0x80073B68: jal         0x8006B38C
    // 0x80073B6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_type(rdram, ctx);
        goto after_2;
    // 0x80073B6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80073B70: bne         $v0, $zero, L_80073C60
    if (ctx->r2 != 0) {
        // 0x80073B74: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_80073C60;
    }
    // 0x80073B74: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80073B78: jal         0x8006B338
    // 0x80073B7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_vehicle_usable(rdram, ctx);
        goto after_3;
    // 0x80073B7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80073B80: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x80073B84: sra         $t9, $s3, 16
    ctx->r25 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80073B88: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x80073B8C: beq         $t2, $zero, L_80073BC8
    if (ctx->r10 == 0) {
        // 0x80073B90: or          $s3, $t9, $zero
        ctx->r19 = ctx->r25 | 0;
            goto L_80073BC8;
    }
    // 0x80073B90: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x80073B94: lw          $t3, 0x24($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X24);
    // 0x80073B98: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073B9C: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80073BA0: lhu         $a1, 0x0($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X0);
    // 0x80073BA4: jal         0x80073080
    // 0x80073BA8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_4;
    // 0x80073BA8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_4:
    // 0x80073BAC: lw          $t5, 0x18($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X18);
    // 0x80073BB0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073BB4: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x80073BB8: lhu         $a1, 0x0($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X0);
    // 0x80073BBC: jal         0x80073080
    // 0x80073BC0: nop

    func_80072E28(rdram, ctx);
        goto after_5;
    // 0x80073BC0: nop

    after_5:
    // 0x80073BC4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80073BC8:
    // 0x80073BC8: andi        $t7, $s3, 0x2
    ctx->r15 = ctx->r19 & 0X2;
    // 0x80073BCC: beq         $t7, $zero, L_80073C0C
    if (ctx->r15 == 0) {
        // 0x80073BD0: andi        $t2, $s3, 0x4
        ctx->r10 = ctx->r19 & 0X4;
            goto L_80073C0C;
    }
    // 0x80073BD0: andi        $t2, $s3, 0x4
    ctx->r10 = ctx->r19 & 0X4;
    // 0x80073BD4: lw          $t8, 0x28($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X28);
    // 0x80073BD8: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073BDC: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80073BE0: lhu         $a1, 0x0($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X0);
    // 0x80073BE4: jal         0x80073080
    // 0x80073BE8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_6;
    // 0x80073BE8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_6:
    // 0x80073BEC: lw          $t0, 0x1C($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X1C);
    // 0x80073BF0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073BF4: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80073BF8: lhu         $a1, 0x0($t1)
    ctx->r5 = MEM_HU(ctx->r9, 0X0);
    // 0x80073BFC: jal         0x80073080
    // 0x80073C00: nop

    func_80072E28(rdram, ctx);
        goto after_7;
    // 0x80073C00: nop

    after_7:
    // 0x80073C04: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80073C08: andi        $t2, $s3, 0x4
    ctx->r10 = ctx->r19 & 0X4;
L_80073C0C:
    // 0x80073C0C: beq         $t2, $zero, L_80073C4C
    if (ctx->r10 == 0) {
        // 0x80073C10: slti        $at, $s2, 0x30
        ctx->r1 = SIGNED(ctx->r18) < 0X30 ? 1 : 0;
            goto L_80073C4C;
    }
    // 0x80073C10: slti        $at, $s2, 0x30
    ctx->r1 = SIGNED(ctx->r18) < 0X30 ? 1 : 0;
    // 0x80073C14: lw          $t3, 0x2C($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X2C);
    // 0x80073C18: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073C1C: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80073C20: lhu         $a1, 0x0($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X0);
    // 0x80073C24: jal         0x80073080
    // 0x80073C28: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_8;
    // 0x80073C28: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_8:
    // 0x80073C2C: lw          $t5, 0x20($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X20);
    // 0x80073C30: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073C34: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x80073C38: lhu         $a1, 0x0($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X0);
    // 0x80073C3C: jal         0x80073080
    // 0x80073C40: nop

    func_80072E28(rdram, ctx);
        goto after_9;
    // 0x80073C40: nop

    after_9:
    // 0x80073C44: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80073C48: slti        $at, $s2, 0x30
    ctx->r1 = SIGNED(ctx->r18) < 0X30 ? 1 : 0;
L_80073C4C:
    // 0x80073C4C: bne         $at, $zero, L_80073C60
    if (ctx->r1 != 0) {
        // 0x80073C50: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_80073C60;
    }
    // 0x80073C50: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80073C54: b           L_80073C74
    // 0x80073C58: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
        goto L_80073C74;
    // 0x80073C58: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80073C5C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_80073C60:
    // 0x80073C60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073C64: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80073C68: bne         $at, $zero, L_80073B68
    if (ctx->r1 != 0) {
        // 0x80073C6C: nop
    
            goto L_80073B68;
    }
    // 0x80073C6C: nop

L_80073C70:
    // 0x80073C70: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_80073C74:
    // 0x80073C74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073C78: sw          $t8, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r24;
    // 0x80073C7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073C80: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x80073C84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073C88: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80073C8C: sw          $t9, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = ctx->r25;
    // 0x80073C90: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80073C94: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80073C98: addiu       $v0, $t8, 0x2
    ctx->r2 = ADD32(ctx->r24, 0X2);
L_80073C9C:
    // 0x80073C9C: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80073CA0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073CA4: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80073CA8: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x80073CAC: slti        $at, $s1, 0xC0
    ctx->r1 = SIGNED(ctx->r17) < 0XC0 ? 1 : 0;
    // 0x80073CB0: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80073CB4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80073CB8: bne         $at, $zero, L_80073C9C
    if (ctx->r1 != 0) {
        // 0x80073CBC: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_80073C9C;
    }
    // 0x80073CBC: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x80073CC0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073CC4: jal         0x80073080
    // 0x80073CC8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_80072E28(rdram, ctx);
        goto after_10;
    // 0x80073CC8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_10:
    // 0x80073CCC: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x80073CD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073CD4: addiu       $s2, $s2, 0xC0
    ctx->r18 = ADD32(ctx->r18, 0XC0);
    // 0x80073CD8: sw          $s2, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r18;
    // 0x80073CDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073CE0: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x80073CE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073CE8: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80073CEC: sw          $t3, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = ctx->r11;
    // 0x80073CF0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073CF4: jal         0x80073080
    // 0x80073CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80072E28(rdram, ctx);
        goto after_11;
    // 0x80073CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80073CFC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80073D00: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80073D04: blez        $t4, L_80073DF4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80073D08: nop
    
            goto L_80073DF4;
    }
    // 0x80073D08: nop

L_80073D0C:
    // 0x80073D0C: jal         0x8006B38C
    // 0x80073D10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_type(rdram, ctx);
        goto after_12;
    // 0x80073D10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80073D14: bne         $v0, $zero, L_80073DE4
    if (ctx->r2 != 0) {
        // 0x80073D18: lw          $t3, 0x48($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X48);
            goto L_80073DE4;
    }
    // 0x80073D18: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80073D1C: jal         0x8006B338
    // 0x80073D20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_vehicle_usable(rdram, ctx);
        goto after_13;
    // 0x80073D20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80073D24: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x80073D28: sra         $t5, $s3, 16
    ctx->r13 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80073D2C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80073D30: beq         $t9, $zero, L_80073D68
    if (ctx->r25 == 0) {
        // 0x80073D34: or          $s3, $t5, $zero
        ctx->r19 = ctx->r13 | 0;
            goto L_80073D68;
    }
    // 0x80073D34: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
    // 0x80073D38: lw          $t8, 0x3C($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X3C);
    // 0x80073D3C: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073D40: addu        $t0, $t8, $s0
    ctx->r8 = ADD32(ctx->r24, ctx->r16);
    // 0x80073D44: lhu         $a1, 0x0($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X0);
    // 0x80073D48: jal         0x80073080
    // 0x80073D4C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_14;
    // 0x80073D4C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_14:
    // 0x80073D50: lw          $t1, 0x30($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X30);
    // 0x80073D54: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073D58: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80073D5C: lhu         $a1, 0x0($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X0);
    // 0x80073D60: jal         0x80073080
    // 0x80073D64: nop

    func_80072E28(rdram, ctx);
        goto after_15;
    // 0x80073D64: nop

    after_15:
L_80073D68:
    // 0x80073D68: andi        $t3, $s3, 0x2
    ctx->r11 = ctx->r19 & 0X2;
    // 0x80073D6C: beq         $t3, $zero, L_80073DA8
    if (ctx->r11 == 0) {
        // 0x80073D70: andi        $t9, $s3, 0x4
        ctx->r25 = ctx->r19 & 0X4;
            goto L_80073DA8;
    }
    // 0x80073D70: andi        $t9, $s3, 0x4
    ctx->r25 = ctx->r19 & 0X4;
    // 0x80073D74: lw          $t4, 0x40($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X40);
    // 0x80073D78: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073D7C: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80073D80: lhu         $a1, 0x0($t5)
    ctx->r5 = MEM_HU(ctx->r13, 0X0);
    // 0x80073D84: jal         0x80073080
    // 0x80073D88: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_16;
    // 0x80073D88: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_16:
    // 0x80073D8C: lw          $t6, 0x34($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X34);
    // 0x80073D90: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073D94: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80073D98: lhu         $a1, 0x0($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X0);
    // 0x80073D9C: jal         0x80073080
    // 0x80073DA0: nop

    func_80072E28(rdram, ctx);
        goto after_17;
    // 0x80073DA0: nop

    after_17:
    // 0x80073DA4: andi        $t9, $s3, 0x4
    ctx->r25 = ctx->r19 & 0X4;
L_80073DA8:
    // 0x80073DA8: beq         $t9, $zero, L_80073DE4
    if (ctx->r25 == 0) {
        // 0x80073DAC: lw          $t3, 0x48($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X48);
            goto L_80073DE4;
    }
    // 0x80073DAC: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80073DB0: lw          $t8, 0x44($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X44);
    // 0x80073DB4: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073DB8: addu        $t0, $t8, $s0
    ctx->r8 = ADD32(ctx->r24, ctx->r16);
    // 0x80073DBC: lhu         $a1, 0x0($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X0);
    // 0x80073DC0: jal         0x80073080
    // 0x80073DC4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_18;
    // 0x80073DC4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_18:
    // 0x80073DC8: lw          $t1, 0x38($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X38);
    // 0x80073DCC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073DD0: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80073DD4: lhu         $a1, 0x0($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X0);
    // 0x80073DD8: jal         0x80073080
    // 0x80073DDC: nop

    func_80072E28(rdram, ctx);
        goto after_19;
    // 0x80073DDC: nop

    after_19:
    // 0x80073DE0: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
L_80073DE4:
    // 0x80073DE4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073DE8: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80073DEC: bne         $at, $zero, L_80073D0C
    if (ctx->r1 != 0) {
        // 0x80073DF0: nop
    
            goto L_80073D0C;
    }
    // 0x80073DF0: nop

L_80073DF4:
    // 0x80073DF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073DF8: sw          $s2, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r18;
    // 0x80073DFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073E00: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80073E04: lw          $a0, 0x476C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X476C);
    // 0x80073E08: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x80073E0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073E10: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80073E14: sw          $t4, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = ctx->r12;
    // 0x80073E18: addiu       $a1, $a0, 0x2
    ctx->r5 = ADD32(ctx->r4, 0X2);
    // 0x80073E1C: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80073E20: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x80073E24: addiu       $t6, $v1, 0x5
    ctx->r14 = ADD32(ctx->r3, 0X5);
    // 0x80073E28: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80073E2C: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x80073E30: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x80073E34: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    // 0x80073E38: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80073E3C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80073E40:
    // 0x80073E40: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80073E44: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x80073E48: lbu         $t6, 0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2);
    // 0x80073E4C: addu        $t2, $v1, $t0
    ctx->r10 = ADD32(ctx->r3, ctx->r8);
    // 0x80073E50: lbu         $t8, 0x3($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X3);
    // 0x80073E54: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x80073E58: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x80073E5C: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
    // 0x80073E60: sll         $t0, $v1, 16
    ctx->r8 = S32(ctx->r3 << 16);
    // 0x80073E64: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80073E68: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80073E6C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80073E70: bne         $s1, $a0, L_80073E40
    if (ctx->r17 != ctx->r4) {
        // 0x80073E74: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80073E40;
    }
    // 0x80073E74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80073E78: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073E7C: jal         0x80073080
    // 0x80073E80: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_80072E28(rdram, ctx);
        goto after_20;
    // 0x80073E80: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_20:
    // 0x80073E84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80073E88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80073E8C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80073E90: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80073E94: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80073E98: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80073E9C: jr          $ra
    // 0x80073EA0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80073EA0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void alMainBusNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800652C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800652C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800652CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800652D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800652D4: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800652D8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800652DC: addiu       $a1, $a1, -0x36E0
    ctx->r5 = ADD32(ctx->r5, -0X36E0);
    // 0x800652E0: addiu       $a2, $a2, -0x3710
    ctx->r6 = ADD32(ctx->r6, -0X3710);
    // 0x800652E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800652E8: jal         0x800CA610
    // 0x800652EC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800652EC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x800652F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800652F4: nop

    // 0x800652F8: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800652FC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80065300: nop

    // 0x80065304: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x80065308: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8006530C: nop

    // 0x80065310: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x80065314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006531C: jr          $ra
    // 0x80065320: nop

    return;
    // 0x80065320: nop

;}
RECOMP_FUNC void handle_car_velocity_control(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800536A4: lwc1        $f4, 0xB4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XB4);
    // 0x800536A8: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800536AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800536B0: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800536B4: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x800536B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800536BC: bc1f        L_800536DC
    if (!c1cs) {
        // 0x800536C0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800536DC;
    }
    // 0x800536C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800536C4: lwc1        $f9, 0x6CF8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6CF8);
    // 0x800536C8: lwc1        $f8, 0x6CFC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6CFC);
    // 0x800536CC: nop

    // 0x800536D0: sub.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f0.d - ctx->f8.d;
    // 0x800536D4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800536D8: swc1        $f16, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->f16.u32l;
L_800536DC:
    // 0x800536DC: lw          $v0, -0x2558($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2558);
    // 0x800536E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800536E4: andi        $t6, $v0, 0x8000
    ctx->r14 = ctx->r2 & 0X8000;
    // 0x800536E8: beq         $t6, $zero, L_80053708
    if (ctx->r14 == 0) {
        // 0x800536EC: andi        $t7, $v0, 0x4000
        ctx->r15 = ctx->r2 & 0X4000;
            goto L_80053708;
    }
    // 0x800536EC: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
    // 0x800536F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800536F4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800536F8: swc1        $f18, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->f18.u32l;
    // 0x800536FC: lw          $v0, -0x2558($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2558);
    // 0x80053700: nop

    // 0x80053704: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
L_80053708:
    // 0x80053708: beq         $t7, $zero, L_80053750
    if (ctx->r15 == 0) {
        // 0x8005370C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80053750;
    }
    // 0x8005370C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053710: lwc1        $f4, 0xB8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XB8);
    // 0x80053714: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80053718: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005371C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80053720: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80053724: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x80053728: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005372C: bc1f        L_80053788
    if (!c1cs) {
        // 0x80053730: nop
    
            goto L_80053788;
    }
    // 0x80053730: nop

    // 0x80053734: lwc1        $f9, 0x6D00($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6D00);
    // 0x80053738: lwc1        $f8, 0x6D04($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6D04);
    // 0x8005373C: nop

    // 0x80053740: add.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f0.d + ctx->f8.d;
    // 0x80053744: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80053748: jr          $ra
    // 0x8005374C: swc1        $f16, 0xB8($a0)
    MEM_W(0XB8, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x8005374C: swc1        $f16, 0xB8($a0)
    MEM_W(0XB8, ctx->r4) = ctx->f16.u32l;
L_80053750:
    // 0x80053750: lwc1        $f18, 0xB8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XB8);
    // 0x80053754: lwc1        $f5, 0x6D08($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6D08);
    // 0x80053758: lwc1        $f4, 0x6D0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6D0C);
    // 0x8005375C: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x80053760: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80053764: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053768: bc1f        L_80053788
    if (!c1cs) {
        // 0x8005376C: nop
    
            goto L_80053788;
    }
    // 0x8005376C: nop

    // 0x80053770: lwc1        $f7, 0x6D10($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6D10);
    // 0x80053774: lwc1        $f6, 0x6D14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6D14);
    // 0x80053778: nop

    // 0x8005377C: sub.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d - ctx->f6.d;
    // 0x80053780: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80053784: swc1        $f10, 0xB8($a0)
    MEM_W(0XB8, ctx->r4) = ctx->f10.u32l;
L_80053788:
    // 0x80053788: jr          $ra
    // 0x8005378C: nop

    return;
    // 0x8005378C: nop

;}
RECOMP_FUNC void debug_text_print(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B64D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B64DC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800B64E0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800B64E4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800B64E8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800B64EC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800B64F0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B64F4: jal         0x800784A4
    // 0x800B64F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    rdp_init(rdram, ctx);
        goto after_0;
    // 0x800B64F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x800B64FC: jal         0x8007A970
    // 0x800B6500: nop

    fb_size(rdram, ctx);
        goto after_1;
    // 0x800B6500: nop

    after_1:
    // 0x800B6504: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B6508: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B650C: addiu       $a1, $a1, -0x7D70
    ctx->r5 = ADD32(ctx->r5, -0X7D70);
    // 0x800B6510: addiu       $a0, $a0, -0x7D6E
    ctx->r4 = ADD32(ctx->r4, -0X7D6E);
    // 0x800B6514: srl         $t6, $v0, 16
    ctx->r14 = S32(U32(ctx->r2) >> 16);
    // 0x800B6518: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x800B651C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x800B6520: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800B6524: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x800B6528: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800B652C: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800B6530: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B6534: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x800B6538: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800B653C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B6540: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B6544: bgez        $t0, L_800B655C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800B6548: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B655C;
    }
    // 0x800B6548: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B654C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B6550: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B6554: nop

    // 0x800B6558: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800B655C:
    // 0x800B655C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B6560: lhu         $t5, 0x0($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X0);
    // 0x800B6564: nop

    // 0x800B6568: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800B656C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800B6570: nop

    // 0x800B6574: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800B6578: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B657C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B6580: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B6584: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B6588: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x800B658C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800B6590: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x800B6594: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x800B6598: bgez        $t5, L_800B65AC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B659C: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800B65AC;
    }
    // 0x800B659C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B65A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B65A4: nop

    // 0x800B65A8: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800B65AC:
    // 0x800B65AC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B65B0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B65B4: nop

    // 0x800B65B8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B65BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B65C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B65C4: nop

    // 0x800B65C8: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800B65CC: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800B65D0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B65D4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B65D8: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x800B65DC: jal         0x800B73B0
    // 0x800B65E0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    debug_text_bounds(rdram, ctx);
        goto after_2;
    // 0x800B65E0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    after_2:
    // 0x800B65E4: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x800B65E8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B65EC: addiu       $t0, $s1, 0x8
    ctx->r8 = ADD32(ctx->r17, 0X8);
    // 0x800B65F0: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    // 0x800B65F4: addiu       $t2, $t2, 0x3548
    ctx->r10 = ADD32(ctx->r10, 0X3548);
    // 0x800B65F8: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800B65FC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B6600: addiu       $s0, $s0, -0x7D68
    ctx->r16 = ADD32(ctx->r16, -0X7D68);
    // 0x800B6604: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x800B6608: jal         0x800B7440
    // 0x800B660C: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    debug_text_origin(rdram, ctx);
        goto after_3;
    // 0x800B660C: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    after_3:
    // 0x800B6610: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800B6614: addiu       $s4, $s4, -0x7D74
    ctx->r20 = ADD32(ctx->r20, -0X7D74);
    // 0x800B6618: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800B661C: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x800B6620: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B6624: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800B6628: lhu         $a3, -0x7D94($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X7D94);
    // 0x800B662C: sw          $zero, -0x7D8C($at)
    MEM_W(-0X7D8C, ctx->r1) = 0;
    // 0x800B6630: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B6634: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B6638: lhu         $v0, -0x7D92($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7D92);
    // 0x800B663C: sh          $a3, -0x7D90($at)
    MEM_H(-0X7D90, ctx->r1) = ctx->r7;
    // 0x800B6640: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800B6644: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B6648: addiu       $s2, $s2, -0x7468
    ctx->r18 = ADD32(ctx->r18, -0X7468);
    // 0x800B664C: sh          $v0, -0x7D8E($at)
    MEM_H(-0X7D8E, ctx->r1) = ctx->r2;
    // 0x800B6650: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800B6654: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B6658: addiu       $t5, $t5, -0x7D68
    ctx->r13 = ADD32(ctx->r13, -0X7D68);
    // 0x800B665C: beq         $t5, $t6, L_800B66A0
    if (ctx->r13 == ctx->r14) {
        // 0x800B6660: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_800B66A0;
    }
    // 0x800B6660: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800B6664: addiu       $s1, $s1, -0x7D88
    ctx->r17 = ADD32(ctx->r17, -0X7D88);
L_800B6668:
    // 0x800B6668: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x800B666C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B6670: jal         0x800B6A9C
    // 0x800B6674: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    debug_text_parse(rdram, ctx);
        goto after_4;
    // 0x800B6674: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800B6678: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800B667C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800B6680: bne         $s0, $t7, L_800B6668
    if (ctx->r16 != ctx->r15) {
        // 0x800B6684: nop
    
            goto L_800B6668;
    }
    // 0x800B6684: nop

    // 0x800B6688: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800B668C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B6690: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B6694: lhu         $v0, -0x7D92($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7D92);
    // 0x800B6698: lhu         $a3, -0x7D94($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X7D94);
    // 0x800B669C: addiu       $s0, $s0, -0x7D68
    ctx->r16 = ADD32(ctx->r16, -0X7D68);
L_800B66A0:
    // 0x800B66A0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B66A4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B66A8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800B66AC: lhu         $a2, -0x7D8E($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X7D8E);
    // 0x800B66B0: lhu         $a1, -0x7D90($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D90);
    // 0x800B66B4: addiu       $t4, $v0, 0xA
    ctx->r12 = ADD32(ctx->r2, 0XA);
    // 0x800B66B8: addiu       $s1, $s1, -0x7D88
    ctx->r17 = ADD32(ctx->r17, -0X7D88);
    // 0x800B66BC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800B66C0: jal         0x800B6EBC
    // 0x800B66C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    debug_text_background(rdram, ctx);
        goto after_5;
    // 0x800B66C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x800B66C8: jal         0x800B7440
    // 0x800B66CC: nop

    debug_text_origin(rdram, ctx);
        goto after_6;
    // 0x800B66CC: nop

    after_6:
    // 0x800B66D0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B66D4: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x800B66D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B66DC: sw          $zero, -0x7D8C($at)
    MEM_W(-0X7D8C, ctx->r1) = 0;
    // 0x800B66E0: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x800B66E4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B66E8: addiu       $t9, $t9, -0x7D68
    ctx->r25 = ADD32(ctx->r25, -0X7D68);
    // 0x800B66EC: beq         $t9, $t0, L_800B6714
    if (ctx->r25 == ctx->r8) {
        // 0x800B66F0: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_800B6714;
    }
    // 0x800B66F0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_800B66F4:
    // 0x800B66F4: sw          $s4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r20;
    // 0x800B66F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B66FC: jal         0x800B6A9C
    // 0x800B6700: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    debug_text_parse(rdram, ctx);
        goto after_7;
    // 0x800B6700: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800B6704: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800B6708: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800B670C: bne         $s0, $t1, L_800B66F4
    if (ctx->r16 != ctx->r9) {
        // 0x800B6710: nop
    
            goto L_800B66F4;
    }
    // 0x800B6710: nop

L_800B6714:
    // 0x800B6714: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B6718: addiu       $t2, $t2, -0x7D68
    ctx->r10 = ADD32(ctx->r10, -0X7D68);
    // 0x800B671C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800B6720: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x800B6724: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800B6728: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B672C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800B6730: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6734: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800B6738: jr          $ra
    // 0x800B673C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B673C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void transition_render_circle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C279C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C27A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C27A4: jal         0x8007B820
    // 0x800C27A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800C27A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C27AC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C27B0: lw          $v1, 0x3760($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3760);
    // 0x800C27B4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C27B8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C27BC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800C27C0: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x800C27C4: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800C27C8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800C27CC: lw          $a3, 0x3750($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3750);
    // 0x800C27D0: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x800C27D4: lw          $t0, 0x3758($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3758);
    // 0x800C27D8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C27DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C27E0: addiu       $t9, $t9, 0x3BD8
    ctx->r25 = ADD32(ctx->r25, 0X3BD8);
    // 0x800C27E4: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800C27E8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800C27EC: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800C27F0: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800C27F4: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x800C27F8: andi        $t3, $a0, 0x6
    ctx->r11 = ctx->r4 & 0X6;
    // 0x800C27FC: ori         $t4, $t3, 0x88
    ctx->r12 = ctx->r11 | 0X88;
    // 0x800C2800: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800C2804: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800C2808: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x800C280C: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800C2810: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800C2814: addiu       $a3, $a3, 0xB4
    ctx->r7 = ADD32(ctx->r7, 0XB4);
    // 0x800C2818: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x800C281C: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x800C2820: andi        $t3, $a0, 0x6
    ctx->r11 = ctx->r4 & 0X6;
    // 0x800C2824: ori         $t8, $t7, 0x14C
    ctx->r24 = ctx->r15 | 0X14C;
    // 0x800C2828: addiu       $a1, $v1, 0x8
    ctx->r5 = ADD32(ctx->r3, 0X8);
    // 0x800C282C: ori         $t4, $t3, 0x88
    ctx->r12 = ctx->r11 | 0X88;
    // 0x800C2830: lui         $t2, 0x5F0
    ctx->r10 = S32(0X5F0 << 16);
    // 0x800C2834: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C2838: ori         $t2, $t2, 0x100
    ctx->r10 = ctx->r10 | 0X100;
    // 0x800C283C: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800C2840: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
    // 0x800C2844: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800C2848: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800C284C: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800C2850: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x800C2854: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x800C2858: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x800C285C: addiu       $a3, $a3, 0xB4
    ctx->r7 = ADD32(ctx->r7, 0XB4);
    // 0x800C2860: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x800C2864: ori         $t8, $t7, 0x14C
    ctx->r24 = ctx->r15 | 0X14C;
    // 0x800C2868: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800C286C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800C2870: andi        $t3, $a0, 0x6
    ctx->r11 = ctx->r4 & 0X6;
    // 0x800C2874: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x800C2878: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
    // 0x800C287C: ori         $t4, $t3, 0x88
    ctx->r12 = ctx->r11 | 0X88;
    // 0x800C2880: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800C2884: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800C2888: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800C288C: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x800C2890: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800C2894: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800C2898: addiu       $a3, $a3, 0xB4
    ctx->r7 = ADD32(ctx->r7, 0XB4);
    // 0x800C289C: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x800C28A0: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x800C28A4: ori         $t8, $t7, 0x14C
    ctx->r24 = ctx->r15 | 0X14C;
    // 0x800C28A8: andi        $t3, $a0, 0x6
    ctx->r11 = ctx->r4 & 0X6;
    // 0x800C28AC: ori         $t4, $t3, 0x88
    ctx->r12 = ctx->r11 | 0X88;
    // 0x800C28B0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C28B4: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x800C28B8: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x800C28BC: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
    // 0x800C28C0: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800C28C4: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800C28C8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C28CC: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800C28D0: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x800C28D4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800C28D8: ori         $t8, $t7, 0x14C
    ctx->r24 = ctx->r15 | 0X14C;
    // 0x800C28DC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C28E0: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800C28E4: addiu       $a1, $v1, 0x8
    ctx->r5 = ADD32(ctx->r3, 0X8);
    // 0x800C28E8: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x800C28EC: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
    // 0x800C28F0: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800C28F4: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800C28F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C28FC: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x800C2900: jal         0x8007B820
    // 0x800C2904: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C2904: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    after_1:
    // 0x800C2908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C290C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2910: jr          $ra
    // 0x800C2914: nop

    return;
    // 0x800C2914: nop

;}
RECOMP_FUNC void play_tt_voice_clip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036C0C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80036C10: addiu       $a3, $a3, -0x25A8
    ctx->r7 = ADD32(ctx->r7, -0X25A8);
    // 0x80036C14: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80036C18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036C20: beq         $a2, $zero, L_80036C4C
    if (ctx->r6 == 0) {
        // 0x80036C24: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80036C4C;
    }
    // 0x80036C24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80036C28: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x80036C2C: beq         $t6, $zero, L_80036C4C
    if (ctx->r14 == 0) {
        // 0x80036C30: nop
    
            goto L_80036C4C;
    }
    // 0x80036C30: nop

    // 0x80036C34: jal         0x8000488C
    // 0x80036C38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x80036C38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80036C3C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80036C40: addiu       $a3, $a3, -0x25A8
    ctx->r7 = ADD32(ctx->r7, -0X25A8);
    // 0x80036C44: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80036C48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80036C4C:
    // 0x80036C4C: bne         $a2, $zero, L_80036C64
    if (ctx->r6 != 0) {
        // 0x80036C50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80036C64;
    }
    // 0x80036C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036C54: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x80036C58: jal         0x80001D04
    // 0x80036C5C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80036C5C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x80036C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036C64:
    // 0x80036C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036C68: jr          $ra
    // 0x80036C6C: nop

    return;
    // 0x80036C6C: nop

;}
RECOMP_FUNC void copy_viewport_background_size_to_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066DE8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066DEC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066DF0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066DF4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066DF8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80066DFC: addiu       $t7, $t7, -0x2A2C
    ctx->r15 = ADD32(ctx->r15, -0X2A2C);
    // 0x80066E00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066E04: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80066E08: lw          $t8, 0x20($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X20);
    // 0x80066E0C: nop

    // 0x80066E10: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80066E14: lw          $t9, 0x28($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X28);
    // 0x80066E18: nop

    // 0x80066E1C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80066E20: lw          $t0, 0x24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X24);
    // 0x80066E24: nop

    // 0x80066E28: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80066E2C: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x80066E30: lw          $t1, 0x2C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2C);
    // 0x80066E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80066E38: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80066E3C: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80066E40: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x80066E44: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80066E48: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80066E4C: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80066E50: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80066E54: bne         $t8, $zero, L_80066E64
    if (ctx->r24 != 0) {
        // 0x80066E58: nop
    
            goto L_80066E64;
    }
    // 0x80066E58: nop

    // 0x80066E5C: jr          $ra
    // 0x80066E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80066E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80066E64:
    // 0x80066E64: jr          $ra
    // 0x80066E68: nop

    return;
    // 0x80066E68: nop

;}
RECOMP_FUNC void obj_loop_infopoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003891C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80038920: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80038924: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80038928: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003892C: bne         $t6, $zero, L_80038948
    if (ctx->r14 != 0) {
        // 0x80038930: nop
    
            goto L_80038948;
    }
    // 0x80038930: nop

    // 0x80038934: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x80038938: nop

    // 0x8003893C: ori         $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 | 0X4000;
    // 0x80038940: b           L_80038958
    // 0x80038944: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
        goto L_80038958;
    // 0x80038944: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
L_80038948:
    // 0x80038948: lh          $t9, 0x6($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X6);
    // 0x8003894C: nop

    // 0x80038950: andi        $t0, $t9, 0xBFFF
    ctx->r8 = ctx->r25 & 0XBFFF;
    // 0x80038954: sh          $t0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r8;
L_80038958:
    // 0x80038958: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x8003895C: lw          $t2, 0x78($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X78);
    // 0x80038960: lbu         $t1, 0x13($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X13);
    // 0x80038964: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80038968: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8003896C: slt         $at, $t1, $t4
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80038970: beq         $at, $zero, L_800389E0
    if (ctx->r1 == 0) {
        // 0x80038974: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800389E0;
    }
    // 0x80038974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038978: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003897C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80038980: lw          $t5, 0x40($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X40);
    // 0x80038984: nop

    // 0x80038988: lb          $t6, 0x54($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X54);
    // 0x8003898C: nop

    // 0x80038990: bne         $t6, $at, L_800389E0
    if (ctx->r14 != ctx->r1) {
        // 0x80038994: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800389E0;
    }
    // 0x80038994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038998: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8003899C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800389A0: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x800389A4: nop

    // 0x800389A8: beq         $a0, $at, L_800389E0
    if (ctx->r4 == ctx->r1) {
        // 0x800389AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800389E0;
    }
    // 0x800389AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800389B0: jal         0x8006A794
    // 0x800389B4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x800389B4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800389B8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800389BC: andi        $t7, $v0, 0x2000
    ctx->r15 = ctx->r2 & 0X2000;
    // 0x800389C0: beq         $t7, $zero, L_800389E0
    if (ctx->r15 == 0) {
        // 0x800389C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800389E0;
    }
    // 0x800389C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800389C8: lw          $a0, 0x78($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X78);
    // 0x800389CC: nop

    // 0x800389D0: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800389D4: jal         0x800C3744
    // 0x800389D8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    set_current_text(rdram, ctx);
        goto after_1;
    // 0x800389D8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x800389DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800389E0:
    // 0x800389E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800389E4: jr          $ra
    // 0x800389E8: nop

    return;
    // 0x800389E8: nop

;}
RECOMP_FUNC void tex_asset_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C9CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007C9D0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8007C9D4: andi        $t7, $a0, 0x8000
    ctx->r15 = ctx->r4 & 0X8000;
    // 0x8007C9D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C9DC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8007C9E0: beq         $t7, $zero, L_8007C9FC
    if (ctx->r15 == 0) {
        // 0x8007C9E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007C9FC;
    }
    // 0x8007C9E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007C9E8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8007C9EC: andi        $t9, $a0, 0x7FFF
    ctx->r25 = ctx->r4 & 0X7FFF;
    // 0x8007C9F0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8007C9F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007C9F8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_8007C9FC:
    // 0x8007C9FC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8007CA00: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007CA04: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8007CA08: lw          $t0, 0x68D8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X68D8);
    // 0x8007CA0C: nop

    // 0x8007CA10: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8007CA14: beq         $at, $zero, L_8007CA24
    if (ctx->r1 == 0) {
        // 0x8007CA18: nop
    
            goto L_8007CA24;
    }
    // 0x8007CA18: nop

    // 0x8007CA1C: bgez        $a0, L_8007CA2C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8007CA20: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8007CA2C;
    }
    // 0x8007CA20: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
L_8007CA24:
    // 0x8007CA24: b           L_8007CAA0
    // 0x8007CA28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007CAA0;
    // 0x8007CA28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007CA2C:
    // 0x8007CA2C: addu        $t1, $t1, $v1
    ctx->r9 = ADD32(ctx->r9, ctx->r3);
    // 0x8007CA30: lw          $t1, 0x68C0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X68C0);
    // 0x8007CA34: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x8007CA38: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007CA3C: lw          $a1, 0x690C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X690C);
    // 0x8007CA40: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8007CA44: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007CA48: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x8007CA4C: lbu         $t4, 0x1D($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X1D);
    // 0x8007CA50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007CA54: beq         $t4, $zero, L_8007CA80
    if (ctx->r12 == 0) {
        // 0x8007CA58: subu        $a3, $t3, $a2
        ctx->r7 = SUB32(ctx->r11, ctx->r6);
            goto L_8007CA80;
    }
    // 0x8007CA58: subu        $a3, $t3, $a2
    ctx->r7 = SUB32(ctx->r11, ctx->r6);
    // 0x8007CA5C: jal         0x80077190
    // 0x8007CA60: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    asset_load(rdram, ctx);
        goto after_0;
    // 0x8007CA60: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    after_0:
    // 0x8007CA64: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007CA68: lw          $v1, 0x690C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X690C);
    // 0x8007CA6C: jal         0x800C670C
    // 0x8007CA70: addiu       $a0, $v1, 0x20
    ctx->r4 = ADD32(ctx->r3, 0X20);
    byteswap32(rdram, ctx);
        goto after_1;
    // 0x8007CA70: addiu       $a0, $v1, 0x20
    ctx->r4 = ADD32(ctx->r3, 0X20);
    after_1:
    // 0x8007CA74: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007CA78: lw          $a1, 0x690C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X690C);
    // 0x8007CA7C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8007CA80:
    // 0x8007CA80: lhu         $v1, 0x12($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X12);
    // 0x8007CA84: nop

    // 0x8007CA88: sra         $t5, $v1, 8
    ctx->r13 = S32(SIGNED(ctx->r3) >> 8);
    // 0x8007CA8C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8007CA90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007CA94: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8007CA98: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8007CA9C: addu        $v0, $t7, $a3
    ctx->r2 = ADD32(ctx->r15, ctx->r7);
L_8007CAA0:
    // 0x8007CAA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007CAA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007CAA8: jr          $ra
    // 0x8007CAAC: nop

    return;
    // 0x8007CAAC: nop

;}
RECOMP_FUNC void obj_loop_goldenballoon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B4FC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003B500: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8003B504: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8003B508: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003B50C: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8003B510: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003B514: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8003B518: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003B51C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8003B520: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8003B524: bne         $t7, $zero, L_8003B544
    if (ctx->r15 != 0) {
        // 0x8003B528: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8003B544;
    }
    // 0x8003B528: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8003B52C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003B530: lwc1        $f9, 0x66F0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X66F0);
    // 0x8003B534: lwc1        $f8, 0x66F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X66F4);
    // 0x8003B538: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8003B53C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003B540: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_8003B544:
    // 0x8003B544: lui         $t8, 0xA000
    ctx->r24 = S32(0XA000 << 16);
    // 0x8003B548: lw          $t9, 0x284($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X284);
    // 0x8003B54C: lui         $at, 0x240B
    ctx->r1 = S32(0X240B << 16);
    // 0x8003B550: ori         $at, $at, 0x17D7
    ctx->r1 = ctx->r1 | 0X17D7;
    // 0x8003B554: beq         $t9, $at, L_8003B560
    if (ctx->r25 == ctx->r1) {
        // 0x8003B558: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8003B560;
    }
    // 0x8003B558: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003B55C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8003B560:
    // 0x8003B560: jal         0x8006ECD0
    // 0x8003B564: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8003B564: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8003B568: lbu         $t3, 0x49($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X49);
    // 0x8003B56C: lw          $v1, 0x3C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X3C);
    // 0x8003B570: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8003B574: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8003B578: lb          $t0, 0x8($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X8);
    // 0x8003B57C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8003B580: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8003B584: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8003B588: sllv        $a1, $t1, $t0
    ctx->r5 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x8003B58C: and         $t7, $t6, $a1
    ctx->r15 = ctx->r14 & ctx->r5;
    // 0x8003B590: beq         $t7, $zero, L_8003B5E0
    if (ctx->r15 == 0) {
        // 0x8003B594: nop
    
            goto L_8003B5E0;
    }
    // 0x8003B594: nop

    // 0x8003B598: lw          $t8, 0x7C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X7C);
    // 0x8003B59C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8003B5A0: blez        $t8, L_8003B5D0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8003B5A4: nop
    
            goto L_8003B5D0;
    }
    // 0x8003B5A4: nop

    // 0x8003B5A8: sw          $t9, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r25;
    // 0x8003B5AC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8003B5B0: jal         0x800B019C
    // 0x8003B5B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_1;
    // 0x8003B5B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8003B5B8: lw          $t1, 0x7C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X7C);
    // 0x8003B5BC: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8003B5C0: nop

    // 0x8003B5C4: subu        $t3, $t1, $t0
    ctx->r11 = SUB32(ctx->r9, ctx->r8);
    // 0x8003B5C8: b           L_8003B7F8
    // 0x8003B5CC: sw          $t3, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r11;
        goto L_8003B7F8;
    // 0x8003B5CC: sw          $t3, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r11;
L_8003B5D0:
    // 0x8003B5D0: jal         0x8000FFB8
    // 0x8003B5D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_2;
    // 0x8003B5D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8003B5D8: b           L_8003B7FC
    // 0x8003B5DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003B7FC;
    // 0x8003B5DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003B5E0:
    // 0x8003B5E0: lh          $t2, 0x6($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X6);
    // 0x8003B5E4: lw          $t5, 0x78($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X78);
    // 0x8003B5E8: ori         $t4, $t2, 0x4000
    ctx->r12 = ctx->r10 | 0X4000;
    // 0x8003B5EC: bne         $t5, $zero, L_8003B7F8
    if (ctx->r13 != 0) {
        // 0x8003B5F0: sh          $t4, 0x6($s1)
        MEM_H(0X6, ctx->r17) = ctx->r12;
            goto L_8003B7F8;
    }
    // 0x8003B5F0: sh          $t4, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r12;
    // 0x8003B5F4: lh          $t6, 0x6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X6);
    // 0x8003B5F8: lbu         $a0, 0x39($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X39);
    // 0x8003B5FC: andi        $t7, $t6, 0xBFFF
    ctx->r15 = ctx->r14 & 0XBFFF;
    // 0x8003B600: sh          $t7, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r15;
    // 0x8003B604: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8003B608: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8003B60C: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x8003B610: subu        $t1, $t9, $t8
    ctx->r9 = SUB32(ctx->r25, ctx->r24);
    // 0x8003B614: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8003B618: beq         $at, $zero, L_8003B62C
    if (ctx->r1 == 0) {
        // 0x8003B61C: addiu       $t3, $zero, 0xFF
        ctx->r11 = ADD32(0, 0XFF);
            goto L_8003B62C;
    }
    // 0x8003B61C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8003B620: addu        $t0, $a0, $t8
    ctx->r8 = ADD32(ctx->r4, ctx->r24);
    // 0x8003B624: b           L_8003B630
    // 0x8003B628: sb          $t0, 0x39($s1)
    MEM_B(0X39, ctx->r17) = ctx->r8;
        goto L_8003B630;
    // 0x8003B628: sb          $t0, 0x39($s1)
    MEM_B(0X39, ctx->r17) = ctx->r8;
L_8003B62C:
    // 0x8003B62C: sb          $t3, 0x39($s1)
    MEM_B(0X39, ctx->r17) = ctx->r11;
L_8003B630:
    // 0x8003B630: lw          $a0, 0x4C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4C);
    // 0x8003B634: nop

    // 0x8003B638: lbu         $t2, 0x13($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X13);
    // 0x8003B63C: nop

    // 0x8003B640: slti        $at, $t2, 0x2D
    ctx->r1 = SIGNED(ctx->r10) < 0X2D ? 1 : 0;
    // 0x8003B644: beq         $at, $zero, L_8003B738
    if (ctx->r1 == 0) {
        // 0x8003B648: nop
    
            goto L_8003B738;
    }
    // 0x8003B648: nop

    // 0x8003B64C: bne         $s0, $zero, L_8003B738
    if (ctx->r16 != 0) {
        // 0x8003B650: nop
    
            goto L_8003B738;
    }
    // 0x8003B650: nop

    // 0x8003B654: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8003B658: nop

    // 0x8003B65C: beq         $v1, $zero, L_8003B738
    if (ctx->r3 == 0) {
        // 0x8003B660: nop
    
            goto L_8003B738;
    }
    // 0x8003B660: nop

    // 0x8003B664: lw          $t4, 0x40($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X40);
    // 0x8003B668: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B66C: lb          $t5, 0x54($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X54);
    // 0x8003B670: nop

    // 0x8003B674: bne         $a2, $t5, L_8003B738
    if (ctx->r6 != ctx->r13) {
        // 0x8003B678: nop
    
            goto L_8003B738;
    }
    // 0x8003B678: nop

    // 0x8003B67C: lw          $a0, 0x64($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X64);
    // 0x8003B680: nop

    // 0x8003B684: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8003B688: nop

    // 0x8003B68C: bne         $t6, $zero, L_8003B738
    if (ctx->r14 != 0) {
        // 0x8003B690: nop
    
            goto L_8003B738;
    }
    // 0x8003B690: nop

    // 0x8003B694: lbu         $t8, 0x48($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X48);
    // 0x8003B698: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8003B69C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8003B6A0: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x8003B6A4: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    // 0x8003B6A8: nop

    // 0x8003B6AC: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x8003B6B0: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x8003B6B4: lbu         $t3, 0x48($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X48);
    // 0x8003B6B8: nop

    // 0x8003B6BC: beq         $t3, $zero, L_8003B6DC
    if (ctx->r11 == 0) {
        // 0x8003B6C0: nop
    
            goto L_8003B6DC;
    }
    // 0x8003B6C0: nop

    // 0x8003B6C4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003B6C8: nop

    // 0x8003B6CC: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x8003B6D0: nop

    // 0x8003B6D4: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8003B6D8: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_8003B6DC:
    // 0x8003B6DC: lbu         $t6, 0x49($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X49);
    // 0x8003B6E0: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8003B6E4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8003B6E8: addu        $v1, $t5, $t8
    ctx->r3 = ADD32(ctx->r13, ctx->r24);
    // 0x8003B6EC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8003B6F0: addiu       $a0, $zero, 0x23D
    ctx->r4 = ADD32(0, 0X23D);
    // 0x8003B6F4: or          $t9, $t7, $a1
    ctx->r25 = ctx->r15 | ctx->r5;
    // 0x8003B6F8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8003B6FC: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8003B700: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8003B704: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8003B708: jal         0x80001EA8
    // 0x8003B70C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_3;
    // 0x8003B70C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x8003B710: lh          $t3, 0x6($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X6);
    // 0x8003B714: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8003B718: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8003B71C: ori         $t2, $t3, 0x4000
    ctx->r10 = ctx->r11 | 0X4000;
    // 0x8003B720: sw          $t1, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r9;
    // 0x8003B724: sw          $t0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r8;
    // 0x8003B728: sh          $t2, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r10;
    // 0x8003B72C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8003B730: jal         0x800B019C
    // 0x8003B734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_4;
    // 0x8003B734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
L_8003B738:
    // 0x8003B738: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003B73C: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x8003B740: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
    // 0x8003B744: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x8003B748: lbu         $t4, 0x39($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X39);
    // 0x8003B74C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003B750: slti        $at, $t4, 0xFF
    ctx->r1 = SIGNED(ctx->r12) < 0XFF ? 1 : 0;
    // 0x8003B754: beq         $at, $zero, L_8003B764
    if (ctx->r1 == 0) {
        // 0x8003B758: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003B764;
    }
    // 0x8003B758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B75C: b           L_8003B770
    // 0x8003B760: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8003B770;
    // 0x8003B760: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8003B764:
    // 0x8003B764: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003B768: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003B76C: nop

L_8003B770:
    // 0x8003B770: lbu         $t6, 0xD($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XD);
    // 0x8003B774: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003B778: bne         $t6, $at, L_8003B7EC
    if (ctx->r14 != ctx->r1) {
        // 0x8003B77C: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_8003B7EC;
    }
    // 0x8003B77C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B780: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003B784: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003B788: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x8003B78C: jal         0x8001C558
    // 0x8003B790: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_5;
    // 0x8003B790: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8003B794: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003B798: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003B79C: beq         $a0, $at, L_8003B7F8
    if (ctx->r4 == ctx->r1) {
        // 0x8003B7A0: sb          $v0, 0xD($s0)
        MEM_B(0XD, ctx->r16) = ctx->r2;
            goto L_8003B7F8;
    }
    // 0x8003B7A0: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x8003B7A4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8003B7A8: jal         0x8001CC7C
    // 0x8003B7AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_6;
    // 0x8003B7AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8003B7B0: lbu         $a1, 0xD($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XD);
    // 0x8003B7B4: sb          $v0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r2;
    // 0x8003B7B8: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003B7BC: jal         0x8001CC7C
    // 0x8003B7C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_7;
    // 0x8003B7C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8003B7C4: lbu         $a1, 0xE($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XE);
    // 0x8003B7C8: sb          $v0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r2;
    // 0x8003B7CC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003B7D0: jal         0x8001CC7C
    // 0x8003B7D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_8;
    // 0x8003B7D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8003B7D8: lbu         $t5, 0xD($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XD);
    // 0x8003B7DC: sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
    // 0x8003B7E0: b           L_8003B7F8
    // 0x8003B7E4: sb          $t5, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r13;
        goto L_8003B7F8;
    // 0x8003B7E4: sb          $t5, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r13;
    // 0x8003B7E8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
L_8003B7EC:
    // 0x8003B7EC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003B7F0: jal         0x8001C6F8
    // 0x8003B7F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001C6C4(rdram, ctx);
        goto after_9;
    // 0x8003B7F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
L_8003B7F8:
    // 0x8003B7F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003B7FC:
    // 0x8003B7FC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B800: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8003B804: jr          $ra
    // 0x8003B808: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8003B808: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void load_next_ingame_level(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CD24: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x8006CD28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006CD2C: sw          $t6, 0x3A80($at)
    MEM_W(0X3A80, ctx->r1) = ctx->r14;
    // 0x8006CD30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CD34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006CD38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CD3C: bne         $a1, $at, L_8006CD5C
    if (ctx->r5 != ctx->r1) {
        // 0x8006CD40: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8006CD5C;
    }
    // 0x8006CD40: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006CD44: jal         0x8009C6F4
    // 0x8006CD48: nop

    get_track_id_to_load(rdram, ctx);
        goto after_0;
    // 0x8006CD48: nop

    after_0:
    // 0x8006CD4C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006CD50: addiu       $v1, $v1, 0x3A74
    ctx->r3 = ADD32(ctx->r3, 0X3A74);
    // 0x8006CD54: b           L_8006CD68
    // 0x8006CD58: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_8006CD68;
    // 0x8006CD58: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8006CD5C:
    // 0x8006CD5C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006CD60: addiu       $v1, $v1, 0x3A74
    ctx->r3 = ADD32(ctx->r3, 0X3A74);
    // 0x8006CD64: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
L_8006CD68:
    // 0x8006CD68: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006CD6C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006CD70: lw          $a2, 0x3A84($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3A84);
    // 0x8006CD74: lw          $a1, 0x3A80($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3A80);
    // 0x8006CD78: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8006CD7C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8006CD80: jal         0x8006CD98
    // 0x8006CD84: nop

    load_level_game(rdram, ctx);
        goto after_1;
    // 0x8006CD84: nop

    after_1:
    // 0x8006CD88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CD8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CD90: jr          $ra
    // 0x8006CD94: nop

    return;
    // 0x8006CD94: nop

;}
RECOMP_FUNC void calculate_eeprom_settings_checksum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074A64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80074A68: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80074A6C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80074A70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074A74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80074A78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80074A7C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80074A80: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x80074A84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80074A88: addiu       $s2, $zero, 0xE
    ctx->r18 = ADD32(0, 0XE);
L_80074A8C:
    // 0x80074A8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80074A90: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80074A94: sll         $a3, $s0, 2
    ctx->r7 = S32(ctx->r16 << 2);
    // 0x80074A98: jal         0x800CEFC0
    // 0x80074A9C: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    __ull_rshift_recomp(rdram, ctx);
        goto after_0;
    // 0x80074A9C: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_0:
    // 0x80074AA0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074AA4: andi        $t9, $v1, 0xF
    ctx->r25 = ctx->r3 & 0XF;
    // 0x80074AA8: bne         $s0, $s2, L_80074A8C
    if (ctx->r16 != ctx->r18) {
        // 0x80074AAC: addu        $s1, $s1, $t9
        ctx->r17 = ADD32(ctx->r17, ctx->r25);
            goto L_80074A8C;
    }
    // 0x80074AAC: addu        $s1, $s1, $t9
    ctx->r17 = ADD32(ctx->r17, ctx->r25);
    // 0x80074AB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80074AB4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80074AB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80074ABC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074AC0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80074AC4: jr          $ra
    // 0x80074AC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80074AC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void read_data_from_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076868: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007686C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80076870: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80076874: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80076878: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007687C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80076880: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80076884: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80076888: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8007688C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80076890: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80076894: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80076898: addiu       $t8, $t8, 0x4598
    ctx->r24 = ADD32(ctx->r24, 0X4598);
    // 0x8007689C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800768A0: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800768A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800768A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800768AC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800768B0: jal         0x800CF53C
    // 0x800768B4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_0;
    // 0x800768B4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_0:
    // 0x800768B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800768BC: bne         $v0, $zero, L_800768CC
    if (ctx->r2 != 0) {
        // 0x800768C0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800768CC;
    }
    // 0x800768C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800768C4: b           L_80076924
    // 0x800768C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80076924;
    // 0x800768C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800768CC:
    // 0x800768CC: beq         $v0, $at, L_800768DC
    if (ctx->r2 == ctx->r1) {
        // 0x800768D0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800768DC;
    }
    // 0x800768D0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800768D4: bne         $v0, $at, L_800768E8
    if (ctx->r2 != ctx->r1) {
        // 0x800768D8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800768E8;
    }
    // 0x800768D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800768DC:
    // 0x800768DC: b           L_80076924
    // 0x800768E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80076924;
    // 0x800768E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800768E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800768E8:
    // 0x800768E8: bne         $v0, $at, L_800768FC
    if (ctx->r2 != ctx->r1) {
        // 0x800768EC: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800768FC;
    }
    // 0x800768EC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800768F0: b           L_80076924
    // 0x800768F4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80076924;
    // 0x800768F4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800768F8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_800768FC:
    // 0x800768FC: bne         $v0, $at, L_80076910
    if (ctx->r2 != ctx->r1) {
        // 0x80076900: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80076910;
    }
    // 0x80076900: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80076904: b           L_80076924
    // 0x80076908: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80076924;
    // 0x80076908: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8007690C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_80076910:
    // 0x80076910: bne         $v0, $at, L_80076924
    if (ctx->r2 != ctx->r1) {
        // 0x80076914: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80076924;
    }
    // 0x80076914: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80076918: b           L_80076924
    // 0x8007691C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80076924;
    // 0x8007691C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80076920: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80076924:
    // 0x80076924: jr          $ra
    // 0x80076928: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80076928: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void obj_loop_skycontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CFD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003CFDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003CFE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003CFE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003CFE8: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CFEC: lw          $t8, 0x7C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X7C);
    // 0x8003CFF0: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x8003CFF4: nop

    // 0x8003CFF8: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003CFFC: beq         $at, $zero, L_8003D014
    if (ctx->r1 == 0) {
        // 0x8003D000: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003D014;
    }
    // 0x8003D000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D004: lw          $a0, 0x78($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78);
    // 0x8003D008: jal         0x80028084
    // 0x8003D00C: nop

    set_skydome_visbility(rdram, ctx);
        goto after_0;
    // 0x8003D00C: nop

    after_0:
    // 0x8003D010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003D014:
    // 0x8003D014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D018: jr          $ra
    // 0x8003D01C: nop

    return;
    // 0x8003D01C: nop

;}
RECOMP_FUNC void func_80067D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067F7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067F80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067F84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80067F88: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80067F8C: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x80067F90: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80067F94: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80067F98: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80067F9C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80067FA0: lhu         $t8, 0x12EC($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X12EC);
    // 0x80067FA4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80067FA8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80067FAC: addiu       $a2, $a2, 0x1264
    ctx->r6 = ADD32(ctx->r6, 0X1264);
    // 0x80067FB0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80067FB4: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80067FB8: lb          $t9, 0x1294($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X1294);
    // 0x80067FBC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80067FC0: beq         $t9, $zero, L_80067FD4
    if (ctx->r25 == 0) {
        // 0x80067FC4: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80067FD4;
    }
    // 0x80067FC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067FC8: addiu       $t0, $a1, 0x4
    ctx->r8 = ADD32(ctx->r5, 0X4);
    // 0x80067FCC: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80067FD0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_80067FD4:
    // 0x80067FD4: sll         $t1, $a1, 4
    ctx->r9 = S32(ctx->r5 << 4);
    // 0x80067FD8: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x80067FDC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80067FE0: addiu       $t2, $t2, 0x1040
    ctx->r10 = ADD32(ctx->r10, 0X1040);
    // 0x80067FE4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80067FE8: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80067FEC: addiu       $a3, $a3, 0x1270
    ctx->r7 = ADD32(ctx->r7, 0X1270);
    // 0x80067FF0: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80067FF4: lh          $t5, 0x38($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X38);
    // 0x80067FF8: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80067FFC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80068000: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80068004: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x80068008: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8006800C: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x80068010: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80068014: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80068018: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8006801C: sh          $t4, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r12;
    // 0x80068020: sh          $t7, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r15;
    // 0x80068024: swc1        $f6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f6.u32l;
    // 0x80068028: swc1        $f10, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f10.u32l;
    // 0x8006802C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80068030: sh          $t8, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r24;
    // 0x80068034: lw          $t9, 0x1298($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1298);
    // 0x80068038: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006803C: beq         $t9, $zero, L_80068058
    if (ctx->r25 == 0) {
        // 0x80068040: addiu       $a0, $a0, 0x14E0
        ctx->r4 = ADD32(ctx->r4, 0X14E0);
            goto L_80068058;
    }
    // 0x80068040: addiu       $a0, $a0, 0x14E0
    ctx->r4 = ADD32(ctx->r4, 0X14E0);
    // 0x80068044: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80068048: lwc1        $f18, 0x30($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8006804C: nop

    // 0x80068050: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80068054: swc1        $f4, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f4.u32l;
L_80068058:
    // 0x80068058: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8006805C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80068060: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80068064: jal         0x800700B4
    // 0x80068068: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x80068068: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    after_0:
    // 0x8006806C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068070: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80068074: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80068078: addiu       $a2, $a2, 0x14A0
    ctx->r6 = ADD32(ctx->r6, 0X14A0);
    // 0x8006807C: addiu       $a1, $a1, 0x1460
    ctx->r5 = ADD32(ctx->r5, 0X1460);
    // 0x80068080: jal         0x8006F9A8
    // 0x80068084: addiu       $a0, $a0, 0x14E0
    ctx->r4 = ADD32(ctx->r4, 0X14E0);
    mtxf_mul(rdram, ctx);
        goto after_1;
    // 0x80068084: addiu       $a0, $a0, 0x14E0
    ctx->r4 = ADD32(ctx->r4, 0X14E0);
    after_1:
    // 0x80068088: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006808C: lw          $t0, 0x1264($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1264);
    // 0x80068090: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80068094: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80068098: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8006809C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800680A0: addiu       $t2, $t2, 0x1040
    ctx->r10 = ADD32(ctx->r10, 0X1040);
    // 0x800680A4: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x800680A8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800680AC: addiu       $a3, $a3, 0x1270
    ctx->r7 = ADD32(ctx->r7, 0X1270);
    // 0x800680B0: lh          $t6, 0x38($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X38);
    // 0x800680B4: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800680B8: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800680BC: lh          $t0, 0x4($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X4);
    // 0x800680C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800680C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800680C8: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800680CC: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800680D0: addiu       $t4, $zero, -0x8000
    ctx->r12 = ADD32(0, -0X8000);
    // 0x800680D4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800680D8: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x800680DC: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x800680E0: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x800680E4: sh          $t5, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r13;
    // 0x800680E8: sh          $t9, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r25;
    // 0x800680EC: sh          $t1, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r9;
    // 0x800680F0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800680F4: swc1        $f10, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f10.u32l;
    // 0x800680F8: swc1        $f16, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f16.u32l;
    // 0x800680FC: swc1        $f18, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f18.u32l;
    // 0x80068100: lw          $t2, 0x1298($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1298);
    // 0x80068104: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068108: beq         $t2, $zero, L_80068124
    if (ctx->r10 == 0) {
        // 0x8006810C: addiu       $a0, $a0, 0x1520
        ctx->r4 = ADD32(ctx->r4, 0X1520);
            goto L_80068124;
    }
    // 0x8006810C: addiu       $a0, $a0, 0x1520
    ctx->r4 = ADD32(ctx->r4, 0X1520);
    // 0x80068110: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80068114: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80068118: nop

    // 0x8006811C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80068120: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
L_80068124:
    // 0x80068124: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80068128: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8006812C: jal         0x8006FE70
    // 0x80068130: swc1        $f10, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f10.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_2;
    // 0x80068130: swc1        $f10, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f10.u32l;
    after_2:
    // 0x80068134: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068138: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006813C: addiu       $a1, $a1, 0x15A0
    ctx->r5 = ADD32(ctx->r5, 0X15A0);
    // 0x80068140: jal         0x8006FAB0
    // 0x80068144: addiu       $a0, $a0, 0x1520
    ctx->r4 = ADD32(ctx->r4, 0X1520);
    mtxf_to_mtx(rdram, ctx);
        goto after_3;
    // 0x80068144: addiu       $a0, $a0, 0x1520
    ctx->r4 = ADD32(ctx->r4, 0X1520);
    after_3:
    // 0x80068148: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8006814C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068150: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068154: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80068158: jr          $ra
    // 0x8006815C: sw          $t4, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = ctx->r12;
    return;
    // 0x8006815C: sw          $t4, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = ctx->r12;
;}
RECOMP_FUNC void dialogue_box_clear_unused_flag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5BD8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5BDC: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5BE0: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C5BE4: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5BE8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C5BEC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5BF0: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C5BF4: nop

    // 0x800C5BF8: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x800C5BFC: jr          $ra
    // 0x800C5C00: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C5C00: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void handle_racer_top_speed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057260: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80057264: lw          $t6, -0x2540($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2540);
    // 0x80057268: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005726C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80057270: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80057274: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80057278: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8005727C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80057280: beq         $t6, $zero, L_80057290
    if (ctx->r14 == 0) {
        // 0x80057284: sw          $a0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r4;
            goto L_80057290;
    }
    // 0x80057284: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80057288: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005728C: nop

L_80057290:
    // 0x80057290: jal         0x800113AC
    // 0x80057294: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    get_race_start_timer(rdram, ctx);
        goto after_0;
    // 0x80057294: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80057298: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005729C: lw          $a0, -0x2540($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2540);
    // 0x800572A0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800572A4: blez        $a0, L_80057470
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800572A8: slti        $at, $a0, 0x1E
        ctx->r1 = SIGNED(ctx->r4) < 0X1E ? 1 : 0;
            goto L_80057470;
    }
    // 0x800572A8: slti        $at, $a0, 0x1E
    ctx->r1 = SIGNED(ctx->r4) < 0X1E ? 1 : 0;
    // 0x800572AC: beq         $at, $zero, L_80057470
    if (ctx->r1 == 0) {
        // 0x800572B0: nop
    
            goto L_80057470;
    }
    // 0x800572B0: nop

    // 0x800572B4: lbu         $t7, 0x1F4($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1F4);
    // 0x800572B8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800572BC: bne         $t7, $zero, L_80057470
    if (ctx->r15 != 0) {
        // 0x800572C0: nop
    
            goto L_80057470;
    }
    // 0x800572C0: nop

    // 0x800572C4: lw          $t8, -0x2554($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2554);
    // 0x800572C8: addiu       $v1, $a0, -0xE
    ctx->r3 = ADD32(ctx->r4, -0XE);
    // 0x800572CC: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800572D0: beq         $t9, $zero, L_800573C4
    if (ctx->r25 == 0) {
        // 0x800572D4: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800573C4;
    }
    // 0x800572D4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800572D8: bgez        $v1, L_800572EC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800572DC: addiu       $t2, $zero, 0x18
        ctx->r10 = ADD32(0, 0X18);
            goto L_800572EC;
    }
    // 0x800572DC: addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // 0x800572E0: bltz        $v0, L_800572EC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800572E4: nop
    
            goto L_800572EC;
    }
    // 0x800572E4: nop

    // 0x800572E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800572EC:
    // 0x800572EC: bgez        $v1, L_800572F8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800572F0: nop
    
            goto L_800572F8;
    }
    // 0x800572F0: nop

    // 0x800572F4: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_800572F8:
    // 0x800572F8: lw          $t0, -0x2558($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2558);
    // 0x800572FC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80057300: andi        $t1, $t0, 0x2000
    ctx->r9 = ctx->r8 & 0X2000;
    // 0x80057304: beq         $t1, $zero, L_8005731C
    if (ctx->r9 == 0) {
        // 0x80057308: subu        $a1, $t2, $v1
        ctx->r5 = SUB32(ctx->r10, ctx->r3);
            goto L_8005731C;
    }
    // 0x80057308: subu        $a1, $t2, $v1
    ctx->r5 = SUB32(ctx->r10, ctx->r3);
    // 0x8005730C: beq         $at, $zero, L_8005731C
    if (ctx->r1 == 0) {
        // 0x80057310: subu        $a1, $t2, $v1
        ctx->r5 = SUB32(ctx->r10, ctx->r3);
            goto L_8005731C;
    }
    // 0x80057310: subu        $a1, $t2, $v1
    ctx->r5 = SUB32(ctx->r10, ctx->r3);
    // 0x80057314: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80057318: subu        $a1, $t2, $v1
    ctx->r5 = SUB32(ctx->r10, ctx->r3);
L_8005731C:
    // 0x8005731C: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80057320: jal         0x8000C8B4
    // 0x80057324: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    normalise_time(rdram, ctx);
        goto after_1;
    // 0x80057324: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x80057328: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8005732C: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80057330: bne         $a1, $at, L_80057350
    if (ctx->r5 != ctx->r1) {
        // 0x80057334: sb          $v0, 0x1D3($s0)
        MEM_B(0X1D3, ctx->r16) = ctx->r2;
            goto L_80057350;
    }
    // 0x80057334: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x80057338: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8005733C: jal         0x80057088
    // 0x80057340: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    racer_play_sound(rdram, ctx);
        goto after_2;
    // 0x80057340: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_2:
    // 0x80057344: jal         0x8000C8B4
    // 0x80057348: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    normalise_time(rdram, ctx);
        goto after_3;
    // 0x80057348: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_3:
    // 0x8005734C: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
L_80057350:
    // 0x80057350: jal         0x8000C8B4
    // 0x80057354: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    normalise_time(rdram, ctx);
        goto after_4;
    // 0x80057354: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_4:
    // 0x80057358: lb          $t3, 0x1D3($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D3);
    // 0x8005735C: nop

    // 0x80057360: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80057364: beq         $at, $zero, L_80057374
    if (ctx->r1 == 0) {
        // 0x80057368: nop
    
            goto L_80057374;
    }
    // 0x80057368: nop

    // 0x8005736C: b           L_8005739C
    // 0x80057370: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
        goto L_8005739C;
    // 0x80057370: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
L_80057374:
    // 0x80057374: jal         0x8000C8B4
    // 0x80057378: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    normalise_time(rdram, ctx);
        goto after_5;
    // 0x80057378: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_5:
    // 0x8005737C: lb          $t4, 0x1D3($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D3);
    // 0x80057380: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80057384: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80057388: beq         $at, $zero, L_80057398
    if (ctx->r1 == 0) {
        // 0x8005738C: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_80057398;
    }
    // 0x8005738C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80057390: b           L_8005739C
    // 0x80057394: sb          $t5, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r13;
        goto L_8005739C;
    // 0x80057394: sb          $t5, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r13;
L_80057398:
    // 0x80057398: sb          $t6, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r14;
L_8005739C:
    // 0x8005739C: lbu         $t7, 0x1EF($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1EF);
    // 0x800573A0: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x800573A4: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x800573A8: sb          $t8, 0x1EF($s0)
    MEM_B(0X1EF, ctx->r16) = ctx->r24;
    // 0x800573AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800573B0: sh          $t9, -0x2520($at)
    MEM_H(-0X2520, ctx->r1) = ctx->r25;
    // 0x800573B4: lb          $t0, 0x1D3($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1D3);
    // 0x800573B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800573BC: addiu       $v1, $v1, -0x24FB
    ctx->r3 = ADD32(ctx->r3, -0X24FB);
    // 0x800573C0: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
L_800573C4:
    // 0x800573C4: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x800573C8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800573CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800573D0: bne         $t1, $at, L_80057470
    if (ctx->r9 != ctx->r1) {
        // 0x800573D4: addiu       $v1, $v1, -0x24FB
        ctx->r3 = ADD32(ctx->r3, -0X24FB);
            goto L_80057470;
    }
    // 0x800573D4: addiu       $v1, $v1, -0x24FB
    ctx->r3 = ADD32(ctx->r3, -0X24FB);
    // 0x800573D8: lb          $v0, 0x1CC($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CC);
    // 0x800573DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800573E0: beq         $v0, $zero, L_80057400
    if (ctx->r2 == 0) {
        // 0x800573E4: nop
    
            goto L_80057400;
    }
    // 0x800573E4: nop

    // 0x800573E8: bne         $v0, $at, L_80057470
    if (ctx->r2 != ctx->r1) {
        // 0x800573EC: nop
    
            goto L_80057470;
    }
    // 0x800573EC: nop

    // 0x800573F0: lb          $t2, 0x0($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X0);
    // 0x800573F4: nop

    // 0x800573F8: beq         $t2, $zero, L_80057470
    if (ctx->r10 == 0) {
        // 0x800573FC: nop
    
            goto L_80057470;
    }
    // 0x800573FC: nop

L_80057400:
    // 0x80057400: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80057404: nop

    // 0x80057408: beq         $v0, $zero, L_80057418
    if (ctx->r2 == 0) {
        // 0x8005740C: nop
    
            goto L_80057418;
    }
    // 0x8005740C: nop

    // 0x80057410: b           L_80057424
    // 0x80057414: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
        goto L_80057424;
    // 0x80057414: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
L_80057418:
    // 0x80057418: jal         0x8000C8B4
    // 0x8005741C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    normalise_time(rdram, ctx);
        goto after_6;
    // 0x8005741C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_6:
    // 0x80057420: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
L_80057424:
    // 0x80057424: jal         0x8000C8B4
    // 0x80057428: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    normalise_time(rdram, ctx);
        goto after_7;
    // 0x80057428: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_7:
    // 0x8005742C: lb          $t3, 0x1D3($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D3);
    // 0x80057430: nop

    // 0x80057434: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80057438: beq         $at, $zero, L_80057448
    if (ctx->r1 == 0) {
        // 0x8005743C: nop
    
            goto L_80057448;
    }
    // 0x8005743C: nop

    // 0x80057440: b           L_80057470
    // 0x80057444: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
        goto L_80057470;
    // 0x80057444: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
L_80057448:
    // 0x80057448: jal         0x8000C8B4
    // 0x8005744C: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    normalise_time(rdram, ctx);
        goto after_8;
    // 0x8005744C: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_8:
    // 0x80057450: lb          $t4, 0x1D3($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D3);
    // 0x80057454: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80057458: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005745C: beq         $at, $zero, L_8005746C
    if (ctx->r1 == 0) {
        // 0x80057460: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_8005746C;
    }
    // 0x80057460: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80057464: b           L_80057470
    // 0x80057468: sb          $t5, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r13;
        goto L_80057470;
    // 0x80057468: sb          $t5, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r13;
L_8005746C:
    // 0x8005746C: sb          $t6, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r14;
L_80057470:
    // 0x80057470: lb          $t7, 0x1D3($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D3);
    // 0x80057474: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80057478: lw          $a0, -0x2540($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2540);
    // 0x8005747C: beq         $t7, $zero, L_800574C8
    if (ctx->r15 == 0) {
        // 0x80057480: slti        $at, $a0, 0x50
        ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
            goto L_800574C8;
    }
    // 0x80057480: slti        $at, $a0, 0x50
    ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
    // 0x80057484: bne         $a0, $zero, L_800574C8
    if (ctx->r4 != 0) {
        // 0x80057488: slti        $at, $a0, 0x50
        ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
            goto L_800574C8;
    }
    // 0x80057488: slti        $at, $a0, 0x50
    ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
    // 0x8005748C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80057490: nop

    // 0x80057494: beq         $t8, $zero, L_800574C8
    if (ctx->r24 == 0) {
        // 0x80057498: slti        $at, $a0, 0x50
        ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
            goto L_800574C8;
    }
    // 0x80057498: slti        $at, $a0, 0x50
    ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
    // 0x8005749C: lb          $t9, 0x1D8($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D8);
    // 0x800574A0: nop

    // 0x800574A4: bne         $t9, $zero, L_800574C8
    if (ctx->r25 != 0) {
        // 0x800574A8: slti        $at, $a0, 0x50
        ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
            goto L_800574C8;
    }
    // 0x800574A8: slti        $at, $a0, 0x50
    ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
    // 0x800574AC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800574B0: jal         0x80072594
    // 0x800574B4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    rumble_set(rdram, ctx);
        goto after_9;
    // 0x800574B4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_9:
    // 0x800574B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800574BC: lw          $a0, -0x2540($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2540);
    // 0x800574C0: nop

    // 0x800574C4: slti        $at, $a0, 0x50
    ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
L_800574C8:
    // 0x800574C8: beq         $at, $zero, L_800574F4
    if (ctx->r1 == 0) {
        // 0x800574CC: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800574F4;
    }
    // 0x800574CC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800574D0: lw          $t0, -0x2554($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2554);
    // 0x800574D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800574D8: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x800574DC: beq         $t1, $zero, L_800574F4
    if (ctx->r9 == 0) {
        // 0x800574E0: nop
    
            goto L_800574F4;
    }
    // 0x800574E0: nop

    // 0x800574E4: sb          $t2, 0x1F4($s0)
    MEM_B(0X1F4, ctx->r16) = ctx->r10;
    // 0x800574E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800574EC: lw          $a0, -0x2540($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2540);
    // 0x800574F0: nop

L_800574F4:
    // 0x800574F4: bne         $a0, $zero, L_80057530
    if (ctx->r4 != 0) {
        // 0x800574F8: nop
    
            goto L_80057530;
    }
    // 0x800574F8: nop

    // 0x800574FC: lbu         $v0, 0x1EF($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1EF);
    // 0x80057500: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x80057504: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x80057508: beq         $t3, $zero, L_80057530
    if (ctx->r11 == 0) {
        // 0x8005750C: andi        $t4, $v0, 0xFFFE
        ctx->r12 = ctx->r2 & 0XFFFE;
            goto L_80057530;
    }
    // 0x8005750C: andi        $t4, $v0, 0xFFFE
    ctx->r12 = ctx->r2 & 0XFFFE;
    // 0x80057510: sb          $t4, 0x1EF($s0)
    MEM_B(0X1EF, ctx->r16) = ctx->r12;
    // 0x80057514: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80057518: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8005751C: jal         0x800570F8
    // 0x80057520: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    play_random_character_voice(rdram, ctx);
        goto after_10;
    // 0x80057520: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_10:
    // 0x80057524: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80057528: jal         0x80057088
    // 0x8005752C: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    racer_play_sound(rdram, ctx);
        goto after_11;
    // 0x8005752C: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_11:
L_80057530:
    // 0x80057530: lbu         $v0, 0x1EF($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1EF);
    // 0x80057534: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80057538: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    // 0x8005753C: beq         $t5, $zero, L_80057548
    if (ctx->r13 == 0) {
        // 0x80057540: andi        $t6, $v0, 0xFFFD
        ctx->r14 = ctx->r2 & 0XFFFD;
            goto L_80057548;
    }
    // 0x80057540: andi        $t6, $v0, 0xFFFD
    ctx->r14 = ctx->r2 & 0XFFFD;
    // 0x80057544: sb          $t6, 0x1EF($s0)
    MEM_B(0X1EF, ctx->r16) = ctx->r14;
L_80057548:
    // 0x80057548: lb          $t7, 0x185($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X185);
    // 0x8005754C: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x80057550: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80057554: bne         $t8, $at, L_80057568
    if (ctx->r24 != ctx->r1) {
        // 0x80057558: cvt.s.w     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80057568;
    }
    // 0x80057558: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005755C: lwc1        $f2, 0x124($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X124);
    // 0x80057560: b           L_800575E0
    // 0x80057564: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
        goto L_800575E0;
    // 0x80057564: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_80057568:
    // 0x80057568: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8005756C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80057570: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80057574: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x80057578: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8005757C: nop

    // 0x80057580: bc1f        L_800575A8
    if (!c1cs) {
        // 0x80057584: nop
    
            goto L_800575A8;
    }
    // 0x80057584: nop

    // 0x80057588: jal         0x8009C850
    // 0x8005758C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    get_filtered_cheats(rdram, ctx);
        goto after_12;
    // 0x8005758C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_12:
    // 0x80057590: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80057594: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x80057598: bne         $t9, $zero, L_800575A8
    if (ctx->r25 != 0) {
        // 0x8005759C: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_800575A8;
    }
    // 0x8005759C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800575A0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800575A4: nop

L_800575A8:
    // 0x800575A8: jal         0x8009C850
    // 0x800575AC: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    get_filtered_cheats(rdram, ctx);
        goto after_13;
    // 0x800575AC: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_13:
    // 0x800575B0: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800575B4: andi        $t0, $v0, 0x2000
    ctx->r8 = ctx->r2 & 0X2000;
    // 0x800575B8: beq         $t0, $zero, L_800575E0
    if (ctx->r8 == 0) {
        // 0x800575BC: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_800575E0;
    }
    // 0x800575BC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800575C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800575C4: nop

    // 0x800575C8: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x800575CC: nop

    // 0x800575D0: bc1f        L_800575E0
    if (!c1cs) {
        // 0x800575D4: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_800575E0;
    }
    // 0x800575D4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800575D8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800575DC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_800575E0:
    // 0x800575E0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800575E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800575E8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800575EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800575F0: bc1f        L_800575FC
    if (!c1cs) {
        // 0x800575F4: neg.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
            goto L_800575FC;
    }
    // 0x800575F4: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x800575F8: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800575FC:
    // 0x800575FC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80057600: nop

    // 0x80057604: bc1f        L_80057610
    if (!c1cs) {
        // 0x80057608: nop
    
            goto L_80057610;
    }
    // 0x80057608: nop

    // 0x8005760C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80057610:
    // 0x80057610: lwc1        $f16, 0x6E5C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6E5C);
    // 0x80057614: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80057618: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8005761C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80057620: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80057624: jr          $ra
    // 0x80057628: add.s       $f0, $f12, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f18.fl;
    return;
    // 0x80057628: add.s       $f0, $f12, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f18.fl;
;}
RECOMP_FUNC void menu_logos_screen_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082EFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082F00: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x80082F04: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80082F08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80082F0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80082F10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80082F14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082F18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082F1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082F20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80082F24: jal         0x80077FAC
    // 0x80082F28: swc1        $f4, 0x69F0($at)
    MEM_W(0X69F0, ctx->r1) = ctx->f4.u32l;
    bgdraw_fillcolour(rdram, ctx);
        goto after_0;
    // 0x80082F28: swc1        $f4, 0x69F0($at)
    MEM_W(0X69F0, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x80082F2C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80082F30: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80082F34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082F38: bne         $t6, $zero, L_80082F80
    if (ctx->r14 != 0) {
        // 0x80082F3C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80082F80;
    }
    // 0x80082F3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082F40: addiu       $t7, $zero, 0xE0
    ctx->r15 = ADD32(0, 0XE0);
    // 0x80082F44: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80082F48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082F4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082F50: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80082F54: jal         0x80066B80
    // 0x80082F58: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    viewport_menu_set(rdram, ctx);
        goto after_1;
    // 0x80082F58: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_1:
    // 0x80082F5C: addiu       $t8, $zero, 0x11C
    ctx->r24 = ADD32(0, 0X11C);
    // 0x80082F60: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80082F64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082F68: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80082F6C: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x80082F70: jal         0x80066CE8
    // 0x80082F74: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    set_viewport_properties(rdram, ctx);
        goto after_2;
    // 0x80082F74: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_2:
    // 0x80082F78: b           L_80082FB0
    // 0x80082F7C: nop

        goto L_80082FB0;
    // 0x80082F7C: nop

L_80082F80:
    // 0x80082F80: addiu       $t9, $zero, 0xC4
    ctx->r25 = ADD32(0, 0XC4);
    // 0x80082F84: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80082F88: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x80082F8C: jal         0x80066B80
    // 0x80082F90: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    viewport_menu_set(rdram, ctx);
        goto after_3;
    // 0x80082F90: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_3:
    // 0x80082F94: addiu       $t0, $zero, 0xF0
    ctx->r8 = ADD32(0, 0XF0);
    // 0x80082F98: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80082F9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082FA0: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80082FA4: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x80082FA8: jal         0x80066CE8
    // 0x80082FAC: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    set_viewport_properties(rdram, ctx);
        goto after_4;
    // 0x80082FAC: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_4:
L_80082FB0:
    // 0x80082FB0: jal         0x80066850
    // 0x80082FB4: nop

    copy_viewports_to_stack(rdram, ctx);
        goto after_5;
    // 0x80082FB4: nop

    after_5:
    // 0x80082FB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082FBC: jal         0x80066A58
    // 0x80082FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camEnableUserView(rdram, ctx);
        goto after_6;
    // 0x80082FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80082FC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80082FC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80082FCC: jr          $ra
    // 0x80082FD0: nop

    return;
    // 0x80082FD0: nop

;}
RECOMP_FUNC void _itoa(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4EA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B4EA4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800B4EA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B4EAC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B4EB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B4EB4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800B4EB8: beq         $t6, $zero, L_800B4ECC
    if (ctx->r14 == 0) {
        // 0x800B4EBC: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_800B4ECC;
    }
    // 0x800B4EBC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800B4EC0: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800B4EC4: b           L_800B4ED4
    // 0x800B4EC8: addiu       $s1, $s1, -0x6E58
    ctx->r17 = ADD32(ctx->r17, -0X6E58);
        goto L_800B4ED4;
    // 0x800B4EC8: addiu       $s1, $s1, -0x6E58
    ctx->r17 = ADD32(ctx->r17, -0X6E58);
L_800B4ECC:
    // 0x800B4ECC: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800B4ED0: addiu       $s1, $s1, -0x6E80
    ctx->r17 = ADD32(ctx->r17, -0X6E80);
L_800B4ED4:
    // 0x800B4ED4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B4ED8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800B4EDC: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800B4EE0: bne         $t8, $zero, L_800B4EF0
    if (ctx->r24 != 0) {
        // 0x800B4EE4: addiu       $t0, $zero, 0x0
        ctx->r8 = ADD32(0, 0X0);
            goto L_800B4EF0;
    }
    // 0x800B4EE4: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x800B4EE8: beq         $t9, $zero, L_800B4F54
    if (ctx->r25 == 0) {
        // 0x800B4EEC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B4F54;
    }
    // 0x800B4EEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B4EF0:
    // 0x800B4EF0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800B4EF4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
L_800B4EF8:
    // 0x800B4EF8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_800B4EFC:
    // 0x800B4EFC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800B4F00: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800B4F04: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800B4F08: jal         0x800CEFEC
    // 0x800B4F0C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    __ull_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x800B4F0C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    after_0:
    // 0x800B4F10: addu        $t2, $v1, $s1
    ctx->r10 = ADD32(ctx->r3, ctx->r17);
    // 0x800B4F14: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x800B4F18: nop

    // 0x800B4F1C: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x800B4F20: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800B4F24: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800B4F28: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800B4F2C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800B4F30: jal         0x800CF028
    // 0x800B4F34: nop

    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800B4F34: nop

    after_1:
    // 0x800B4F38: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800B4F3C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B4F40: bne         $v0, $zero, L_800B4EF8
    if (ctx->r2 != 0) {
        // 0x800B4F44: or          $t5, $v1, $zero
        ctx->r13 = ctx->r3 | 0;
            goto L_800B4EF8;
    }
    // 0x800B4F44: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
    // 0x800B4F48: bne         $t5, $zero, L_800B4EFC
    if (ctx->r13 != 0) {
        // 0x800B4F4C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800B4EFC;
    }
    // 0x800B4F4C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800B4F50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B4F54:
    // 0x800B4F54: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B4F58: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B4F5C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B4F60: jr          $ra
    // 0x800B4F64: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B4F64: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void guPerspective(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD0B0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800CD0B4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800CD0B8: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800CD0BC: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800CD0C0: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800CD0C4: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CD0C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CD0CC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800CD0D0: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800CD0D4: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800CD0D8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800CD0DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800CD0E0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800CD0E4: jal         0x800CCE80
    // 0x800CD0E8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_0;
    // 0x800CD0E8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800CD0EC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800CD0F0: jal         0x800D4DA0
    // 0x800CD0F4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800CD0F4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x800CD0F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CD0FC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800CD100: jr          $ra
    // 0x800CD104: nop

    return;
    // 0x800CD104: nop

;}
RECOMP_FUNC void free_particle_assets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE9F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE9F4: lw          $a0, 0x327C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X327C);
    // 0x800AE9F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE9FC: beq         $a0, $zero, L_800AEA14
    if (ctx->r4 == 0) {
        // 0x800AEA00: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AEA14;
    }
    // 0x800AEA00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AEA04: jal         0x80071380
    // 0x800AEA08: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800AEA08: nop

    after_0:
    // 0x800AEA0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEA10: sw          $zero, 0x327C($at)
    MEM_W(0X327C, ctx->r1) = 0;
L_800AEA14:
    // 0x800AEA14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AEA18: lw          $a0, 0x3280($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3280);
    // 0x800AEA1C: nop

    // 0x800AEA20: beq         $a0, $zero, L_800AEA38
    if (ctx->r4 == 0) {
        // 0x800AEA24: nop
    
            goto L_800AEA38;
    }
    // 0x800AEA24: nop

    // 0x800AEA28: jal         0x80071380
    // 0x800AEA2C: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800AEA2C: nop

    after_1:
    // 0x800AEA30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEA34: sw          $zero, 0x3280($at)
    MEM_W(0X3280, ctx->r1) = 0;
L_800AEA38:
    // 0x800AEA38: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AEA3C: lw          $a0, 0x3288($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3288);
    // 0x800AEA40: nop

    // 0x800AEA44: beq         $a0, $zero, L_800AEA5C
    if (ctx->r4 == 0) {
        // 0x800AEA48: nop
    
            goto L_800AEA5C;
    }
    // 0x800AEA48: nop

    // 0x800AEA4C: jal         0x80071380
    // 0x800AEA50: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800AEA50: nop

    after_2:
    // 0x800AEA54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEA58: sw          $zero, 0x3288($at)
    MEM_W(0X3288, ctx->r1) = 0;
L_800AEA5C:
    // 0x800AEA5C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AEA60: lw          $a0, 0x328C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X328C);
    // 0x800AEA64: nop

    // 0x800AEA68: beq         $a0, $zero, L_800AEA84
    if (ctx->r4 == 0) {
        // 0x800AEA6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AEA84;
    }
    // 0x800AEA6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AEA70: jal         0x80071380
    // 0x800AEA74: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x800AEA74: nop

    after_3:
    // 0x800AEA78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEA7C: sw          $zero, 0x328C($at)
    MEM_W(0X328C, ctx->r1) = 0;
    // 0x800AEA80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AEA84:
    // 0x800AEA84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AEA88: jr          $ra
    // 0x800AEA8C: nop

    return;
    // 0x800AEA8C: nop

;}
RECOMP_FUNC void mainproc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065F80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065F84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065F88: jal         0x800CCB00
    // 0x80065F8C: nop

    osInitialize_recomp(rdram, ctx);
        goto after_0;
    // 0x80065F8C: nop

    after_0:
    // 0x80065F90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80065F94: addiu       $t6, $t6, -0x2330
    ctx->r14 = ADD32(ctx->r14, -0X2330);
    // 0x80065F98: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80065F9C: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80065FA0: addiu       $a2, $a2, 0x5FD8
    ctx->r6 = ADD32(ctx->r6, 0X5FD8);
    // 0x80065FA4: addiu       $a0, $a0, -0x320
    ctx->r4 = ADD32(ctx->r4, -0X320);
    // 0x80065FA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80065FAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80065FB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80065FB4: jal         0x800C8DB0
    // 0x80065FB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80065FB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x80065FBC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80065FC0: jal         0x800C8F00
    // 0x80065FC4: addiu       $a0, $a0, -0x320
    ctx->r4 = ADD32(ctx->r4, -0X320);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80065FC4: addiu       $a0, $a0, -0x320
    ctx->r4 = ADD32(ctx->r4, -0X320);
    after_2:
    // 0x80065FC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80065FCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065FD0: jr          $ra
    // 0x80065FD4: nop

    return;
    // 0x80065FD4: nop

;}
RECOMP_FUNC void obj_shade_fast(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024630: lw          $a3, 0x54($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X54);
    // 0x80024634: beq         $a3, $zero, L_8002477C
    if (ctx->r7 == 0) {
        // 0x80024638: nop
    
            goto L_8002477C;
    }
    // 0x80024638: nop

    // 0x8002463C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80024640: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x80024644: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80024648: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8002464C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80024650: lh          $t0, 0x28($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X28);
    // 0x80024654: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80024658: lw          $t5, 0x38($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X38);
    // 0x8002465C: lh          $t8, 0x1C($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X1C);
    // 0x80024660: lh          $t7, 0x1E($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X1E);
    // 0x80024664: lh          $t6, 0x20($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X20);
    // 0x80024668: lw          $a3, 0x40($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X40);
    // 0x8002466C: lw          $a1, 0x44($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X44);
    // 0x80024670: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80024674: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80024678: nop

    // 0x8002467C: ori         $v1, $v0, 0x3
    ctx->r3 = ctx->r2 | 0X3;
    // 0x80024680: xori        $v1, $v1, 0x2
    ctx->r3 = ctx->r3 ^ 0X2;
    // 0x80024684: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80024688: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8002468C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80024690: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80024694: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
    // 0x80024698: add         $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x8002469C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800246A0: add         $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x800246A4: lbu         $t0, 0x6($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X6);
L_800246A8:
    // 0x800246A8: lh          $v0, 0x2($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X2);
    // 0x800246AC: lh          $v1, 0xE($t5)
    ctx->r3 = MEM_H(ctx->r13, 0XE);
    // 0x800246B0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800246B4: bne         $t0, $at, L_800246E8
    if (ctx->r8 != ctx->r1) {
        // 0x800246B8: sub         $t4, $v1, $v0
        ctx->r12 = SUB32(ctx->r3, ctx->r2);
            goto L_800246E8;
    }
    // 0x800246B8: sub         $t4, $v1, $v0
    ctx->r12 = SUB32(ctx->r3, ctx->r2);
    // 0x800246BC: lw          $t1, 0x8($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X8);
    // 0x800246C0: sll         $v0, $t4, 3
    ctx->r2 = S32(ctx->r12 << 3);
    // 0x800246C4: sll         $v1, $t4, 1
    ctx->r3 = S32(ctx->r12 << 1);
    // 0x800246C8: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800246CC: andi        $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 & 0X8000;
    // 0x800246D0: beq         $t1, $zero, L_8002476C
    if (ctx->r9 == 0) {
        // 0x800246D4: add         $a1, $a1, $v0
        ctx->r5 = ADD32(ctx->r5, ctx->r2);
            goto L_8002476C;
    }
    // 0x800246D4: add         $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800246D8: sll         $v0, $t4, 2
    ctx->r2 = S32(ctx->r12 << 2);
    // 0x800246DC: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800246E0: b           L_8002476C
    // 0x800246E4: add         $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
        goto L_8002476C;
    // 0x800246E4: add         $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
L_800246E8:
    // 0x800246E8: lh          $t0, 0x0($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X0);
    // 0x800246EC: mult        $t0, $t8
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800246F0: mflo        $t9
    ctx->r25 = lo;
    // 0x800246F4: lh          $t1, 0x2($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X2);
    // 0x800246F8: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800246FC: mult        $t1, $t7
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024700: mflo        $v0
    ctx->r2 = lo;
    // 0x80024704: lh          $t2, 0x4($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X4);
    // 0x80024708: add         $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8002470C: mult        $t2, $t6
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024710: mflo        $v0
    ctx->r2 = lo;
    // 0x80024714: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x80024718: add         $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8002471C: sra         $t9, $t9, 11
    ctx->r25 = S32(SIGNED(ctx->r25) >> 11);
    // 0x80024720: bgtz        $t9, L_80024730
    if (SIGNED(ctx->r25) > 0) {
        // 0x80024724: nop
    
            goto L_80024730;
    }
    // 0x80024724: nop

    // 0x80024728: b           L_80024750
    // 0x8002472C: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
        goto L_80024750;
    // 0x8002472C: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
L_80024730:
    // 0x80024730: mult        $t9, $a2
    result = S64(S32(ctx->r25)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024734: mflo        $t9
    ctx->r25 = lo;
    // 0x80024738: srl         $t9, $t9, 16
    ctx->r25 = S32(U32(ctx->r25) >> 16);
    // 0x8002473C: add         $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // 0x80024740: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x80024744: bnel        $at, $zero, L_80024754
    if (ctx->r1 != 0) {
        // 0x80024748: sll         $v0, $t9, 8
        ctx->r2 = S32(ctx->r25 << 8);
            goto L_80024754;
    }
    goto skip_0;
    // 0x80024748: sll         $v0, $t9, 8
    ctx->r2 = S32(ctx->r25 << 8);
    skip_0:
    // 0x8002474C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
L_80024750:
    // 0x80024750: sll         $v0, $t9, 8
    ctx->r2 = S32(ctx->r25 << 8);
L_80024754:
    // 0x80024754: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
    // 0x80024758: sh          $t9, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r25;
    // 0x8002475C: ori         $t9, $t9, 0xFF
    ctx->r25 = ctx->r25 | 0XFF;
    // 0x80024760: sh          $t9, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r25;
    // 0x80024764: bne         $t4, $zero, L_800246E8
    if (ctx->r12 != 0) {
        // 0x80024768: addiu       $a1, $a1, 0xA
        ctx->r5 = ADD32(ctx->r5, 0XA);
            goto L_800246E8;
    }
    // 0x80024768: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
L_8002476C:
    // 0x8002476C: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80024770: slt         $at, $t5, $a0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80024774: bnel        $at, $zero, L_800246A8
    if (ctx->r1 != 0) {
        // 0x80024778: lbu         $t0, 0x6($t5)
        ctx->r8 = MEM_BU(ctx->r13, 0X6);
            goto L_800246A8;
    }
    goto skip_1;
    // 0x80024778: lbu         $t0, 0x6($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X6);
    skip_1:
L_8002477C:
    // 0x8002477C: jr          $ra
    // 0x80024780: nop

    return;
    // 0x80024780: nop

;}
RECOMP_FUNC void obj_init_scenery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033D00: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80033D04: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80033D08: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x80033D0C: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x80033D10: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x80033D14: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80033D18: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80033D1C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80033D20: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80033D24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80033D28: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80033D2C: nop

    // 0x80033D30: bc1f        L_80033D40
    if (!c1cs) {
        // 0x80033D34: nop
    
            goto L_80033D40;
    }
    // 0x80033D34: nop

    // 0x80033D38: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80033D3C: nop

L_80033D40:
    // 0x80033D40: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80033D44: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80033D48: lw          $t0, 0x50($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X50);
    // 0x80033D4C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80033D50: nop

    // 0x80033D54: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80033D58: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80033D5C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80033D60: nop

    // 0x80033D64: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80033D68: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x80033D6C: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x80033D70: nop

    // 0x80033D74: sb          $t1, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = ctx->r9;
    // 0x80033D78: lbu         $t3, 0xA($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0XA);
    // 0x80033D7C: nop

    // 0x80033D80: sll         $t4, $t3, 10
    ctx->r12 = S32(ctx->r11 << 10);
    // 0x80033D84: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x80033D88: lbu         $t5, 0xB($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XB);
    // 0x80033D8C: nop

    // 0x80033D90: beq         $t5, $zero, L_80033DE4
    if (ctx->r13 == 0) {
        // 0x80033D94: nop
    
            goto L_80033DE4;
    }
    // 0x80033D94: nop

    // 0x80033D98: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80033D9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80033DA0: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80033DA4: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x80033DA8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80033DAC: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x80033DB0: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80033DB4: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80033DB8: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x80033DBC: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x80033DC0: addiu       $t3, $zero, -0x5
    ctx->r11 = ADD32(0, -0X5);
    // 0x80033DC4: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    // 0x80033DC8: lw          $t4, 0x4C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4C);
    // 0x80033DCC: nop

    // 0x80033DD0: sb          $t3, 0x16($t4)
    MEM_B(0X16, ctx->r12) = ctx->r11;
    // 0x80033DD4: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x80033DD8: lbu         $t5, 0xB($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XB);
    // 0x80033DDC: nop

    // 0x80033DE0: sb          $t5, 0x17($t6)
    MEM_B(0X17, ctx->r14) = ctx->r13;
L_80033DE4:
    // 0x80033DE4: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x80033DE8: lb          $t7, 0x3A($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3A);
    // 0x80033DEC: lb          $t9, 0x55($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X55);
    // 0x80033DF0: nop

    // 0x80033DF4: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80033DF8: bne         $at, $zero, L_80033E04
    if (ctx->r1 != 0) {
        // 0x80033DFC: nop
    
            goto L_80033E04;
    }
    // 0x80033DFC: nop

    // 0x80033E00: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_80033E04:
    // 0x80033E04: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    // 0x80033E08: jr          $ra
    // 0x80033E0C: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    return;
    // 0x80033E0C: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
;}
RECOMP_FUNC void dialogue_try_close(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D4F4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009D4F8: addiu       $v0, $v0, -0x5A0
    ctx->r2 = ADD32(ctx->r2, -0X5A0);
    // 0x8009D4FC: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009D500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009D504: beq         $t6, $zero, L_8009D520
    if (ctx->r14 == 0) {
        // 0x8009D508: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009D520;
    }
    // 0x8009D508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009D50C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8009D510: jal         0x800C5B80
    // 0x8009D514: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    dialogue_close(rdram, ctx);
        goto after_0;
    // 0x8009D514: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8009D518: jal         0x8009C3A0
    // 0x8009D51C: nop

    reset_controller_sticks(rdram, ctx);
        goto after_1;
    // 0x8009D51C: nop

    after_1:
L_8009D520:
    // 0x8009D520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009D524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009D528: jr          $ra
    // 0x8009D52C: nop

    return;
    // 0x8009D52C: nop

;}
RECOMP_FUNC void level_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BFD8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006BFDC: lw          $t6, 0x16E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16E8);
    // 0x8006BFE0: nop

    // 0x8006BFE4: lbu         $v0, 0x4C($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X4C);
    // 0x8006BFE8: jr          $ra
    // 0x8006BFEC: nop

    return;
    // 0x8006BFEC: nop

;}
RECOMP_FUNC void parse_string_with_number(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C64C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C64C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C64C8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C64CC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C64D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C64D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C64D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C64DC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C64E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C64E4: beq         $v0, $zero, L_800C6538
    if (ctx->r2 == 0) {
        // 0x800C64E8: or          $s3, $a2, $zero
        ctx->r19 = ctx->r6 | 0;
            goto L_800C6538;
    }
    // 0x800C64E8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800C64EC: addiu       $s2, $sp, 0x2C
    ctx->r18 = ADD32(ctx->r29, 0X2C);
    // 0x800C64F0: addiu       $s1, $zero, 0x7E
    ctx->r17 = ADD32(0, 0X7E);
L_800C64F4:
    // 0x800C64F4: bne         $s1, $v0, L_800C650C
    if (ctx->r17 != ctx->r2) {
        // 0x800C64F8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C650C;
    }
    // 0x800C64F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C64FC: jal         0x800C5D6C
    // 0x800C6500: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    s32_to_string(rdram, ctx);
        goto after_0;
    // 0x800C6500: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x800C6504: b           L_800C6528
    // 0x800C6508: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800C6528;
    // 0x800C6508: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C650C:
    // 0x800C650C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6510: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C6514: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x800C6518: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800C651C: nop

    // 0x800C6520: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C6524: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_800C6528:
    // 0x800C6528: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C652C: nop

    // 0x800C6530: bne         $v0, $zero, L_800C64F4
    if (ctx->r2 != 0) {
        // 0x800C6534: nop
    
            goto L_800C64F4;
    }
    // 0x800C6534: nop

L_800C6538:
    // 0x800C6538: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800C653C: nop

    // 0x800C6540: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x800C6544: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C6548: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C654C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6550: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C6554: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C6558: jr          $ra
    // 0x800C655C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C655C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void wavegen_destroy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF904: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BF908: lw          $t6, 0x3720($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3720);
    // 0x800BF90C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BF910: beq         $t6, $zero, L_800BFA3C
    if (ctx->r14 == 0) {
        // 0x800BF914: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800BFA3C;
    }
    // 0x800BF914: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800BF918: addiu       $t0, $t0, 0x3718
    ctx->r8 = ADD32(ctx->r8, 0X3718);
    // 0x800BF91C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800BF920: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BF924: blez        $a0, L_800BF960
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BF928: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BF960;
    }
    // 0x800BF928: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BF92C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800BF930: lw          $t7, 0x3724($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3724);
    // 0x800BF934: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x800BF938: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
L_800BF93C:
    // 0x800BF93C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800BF940: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BF944: bne         $a1, $t9, L_800BF950
    if (ctx->r5 != ctx->r25) {
        // 0x800BF948: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800BF950;
    }
    // 0x800BF948: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BF94C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800BF950:
    // 0x800BF950: beq         $at, $zero, L_800BF960
    if (ctx->r1 == 0) {
        // 0x800BF954: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800BF960;
    }
    // 0x800BF954: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800BF958: beq         $v1, $zero, L_800BF93C
    if (ctx->r3 == 0) {
        // 0x800BF95C: nop
    
            goto L_800BF93C;
    }
    // 0x800BF95C: nop

L_800BF960:
    // 0x800BF960: beq         $v1, $zero, L_800BFA3C
    if (ctx->r3 == 0) {
        // 0x800BF964: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_800BFA3C;
    }
    // 0x800BF964: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BF968: addiu       $t1, $t1, 0x371C
    ctx->r9 = ADD32(ctx->r9, 0X371C);
    // 0x800BF96C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800BF970: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800BF974: blez        $t5, L_800BFA18
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800BF978: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BFA18;
    }
    // 0x800BF978: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BF97C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BF980: addiu       $t2, $t2, 0x3714
    ctx->r10 = ADD32(ctx->r10, 0X3714);
    // 0x800BF984: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800BF988: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800BF98C:
    // 0x800BF98C: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800BF990: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x800BF994: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800BF998: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x800BF99C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800BF9A0: beq         $t3, $t8, L_800BFA04
    if (ctx->r11 == ctx->r24) {
        // 0x800BF9A4: nop
    
            goto L_800BFA04;
    }
    // 0x800BF9A4: nop

    // 0x800BF9A8: lbu         $a3, 0x0($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X0);
    // 0x800BF9AC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_800BF9B0:
    // 0x800BF9B0: bne         $v0, $a3, L_800BF9E4
    if (ctx->r2 != ctx->r7) {
        // 0x800BF9B4: slti        $at, $a0, 0x7
        ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
            goto L_800BF9E4;
    }
    // 0x800BF9B4: slti        $at, $a0, 0x7
    ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x800BF9B8: beq         $at, $zero, L_800BF9D8
    if (ctx->r1 == 0) {
        // 0x800BF9BC: nop
    
            goto L_800BF9D8;
    }
    // 0x800BF9BC: nop

L_800BF9C0:
    // 0x800BF9C0: lbu         $t9, 0x1($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X1);
    // 0x800BF9C4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BF9C8: slti        $at, $a0, 0x7
    ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x800BF9CC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BF9D0: bne         $at, $zero, L_800BF9C0
    if (ctx->r1 != 0) {
        // 0x800BF9D4: sb          $t9, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r25;
            goto L_800BF9C0;
    }
    // 0x800BF9D4: sb          $t9, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r25;
L_800BF9D8:
    // 0x800BF9D8: sb          $t4, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r12;
    // 0x800BF9DC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BF9E0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800BF9E4:
    // 0x800BF9E4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BF9E8: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800BF9EC: beq         $at, $zero, L_800BFA04
    if (ctx->r1 == 0) {
        // 0x800BF9F0: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800BFA04;
    }
    // 0x800BF9F0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BF9F4: lbu         $a3, 0x0($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0X0);
    // 0x800BF9F8: nop

    // 0x800BF9FC: bne         $t3, $a3, L_800BF9B0
    if (ctx->r11 != ctx->r7) {
        // 0x800BFA00: nop
    
            goto L_800BF9B0;
    }
    // 0x800BFA00: nop

L_800BFA04:
    // 0x800BFA04: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800BFA08: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BFA0C: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800BFA10: bne         $at, $zero, L_800BF98C
    if (ctx->r1 != 0) {
        // 0x800BFA14: nop
    
            goto L_800BF98C;
    }
    // 0x800BFA14: nop

L_800BFA18:
    // 0x800BFA18: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BFA1C: lw          $t6, 0x3724($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3724);
    // 0x800BFA20: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800BFA24: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800BFA28: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800BFA2C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800BFA30: nop

    // 0x800BFA34: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x800BFA38: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_800BFA3C:
    // 0x800BFA3C: jr          $ra
    // 0x800BFA40: nop

    return;
    // 0x800BFA40: nop

;}
RECOMP_FUNC void gfxtask_run_xbus2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077A00: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80077A04: addiu       $v1, $v1, -0x15A8
    ctx->r3 = ADD32(ctx->r3, -0X15A8);
    // 0x80077A08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80077A0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077A10: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80077A14: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80077A18: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80077A1C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80077A20: addiu       $t7, $t7, 0x65C0
    ctx->r15 = ADD32(ctx->r15, 0X65C0);
    // 0x80077A24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80077A28: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80077A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077A30: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80077A34: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80077A38: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x80077A3C: bne         $t8, $at, L_80077A48
    if (ctx->r24 != ctx->r1) {
        // 0x80077A40: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80077A48;
    }
    // 0x80077A40: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80077A44: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80077A48:
    // 0x80077A48: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80077A4C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80077A50: addiu       $v0, $v0, -0x75E0
    ctx->r2 = ADD32(ctx->r2, -0X75E0);
    // 0x80077A54: subu        $t0, $a1, $a0
    ctx->r8 = SUB32(ctx->r5, ctx->r4);
    // 0x80077A58: addiu       $t5, $t5, -0x7510
    ctx->r13 = ADD32(ctx->r13, -0X7510);
    // 0x80077A5C: sra         $t1, $t0, 3
    ctx->r9 = S32(SIGNED(ctx->r8) >> 3);
    // 0x80077A60: subu        $t6, $t5, $v0
    ctx->r14 = SUB32(ctx->r13, ctx->r2);
    // 0x80077A64: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80077A68: sw          $t2, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r10;
    // 0x80077A6C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80077A70: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80077A74: sw          $t6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r14;
    // 0x80077A78: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80077A7C: sw          $t3, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r11;
    // 0x80077A80: sw          $t4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r12;
    // 0x80077A84: addiu       $t7, $t7, -0x5120
    ctx->r15 = ADD32(ctx->r15, -0X5120);
    // 0x80077A88: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80077A8C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80077A90: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80077A94: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80077A98: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80077A9C: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x80077AA0: addiu       $t8, $t8, -0x4EE0
    ctx->r24 = ADD32(ctx->r24, -0X4EE0);
    // 0x80077AA4: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x80077AA8: addiu       $t0, $t0, 0x4840
    ctx->r8 = ADD32(ctx->r8, 0X4840);
    // 0x80077AAC: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x80077AB0: addiu       $t2, $t2, 0x7770
    ctx->r10 = ADD32(ctx->r10, 0X7770);
    // 0x80077AB4: addiu       $t3, $zero, 0xA00
    ctx->r11 = ADD32(0, 0XA00);
    // 0x80077AB8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80077ABC: addiu       $t5, $t5, 0x6478
    ctx->r13 = ADD32(ctx->r13, 0X6478);
    // 0x80077AC0: addiu       $t6, $t6, -0x15F0
    ctx->r14 = ADD32(ctx->r14, -0X15F0);
    // 0x80077AC4: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x80077AC8: sw          $v0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r2;
    // 0x80077ACC: sw          $t8, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r24;
    // 0x80077AD0: sw          $t9, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r25;
    // 0x80077AD4: sw          $t0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r8;
    // 0x80077AD8: sw          $t1, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r9;
    // 0x80077ADC: sw          $t2, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r10;
    // 0x80077AE0: sw          $t3, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r11;
    // 0x80077AE4: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x80077AE8: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x80077AEC: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80077AF0: sw          $t4, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r12;
    // 0x80077AF4: sw          $t5, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r13;
    // 0x80077AF8: sw          $t6, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r14;
    // 0x80077AFC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80077B00: lw          $t7, 0x6874($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6874);
    // 0x80077B04: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x80077B08: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x80077B0C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80077B10: sw          $v0, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->r2;
    // 0x80077B14: sw          $v0, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->r2;
    // 0x80077B18: sw          $v1, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->r3;
    // 0x80077B1C: sw          $v1, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r3;
    // 0x80077B20: sw          $zero, 0x68($a3)
    MEM_W(0X68, ctx->r7) = 0;
    // 0x80077B24: sw          $t7, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r15;
    // 0x80077B28: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80077B2C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80077B30: beq         $t8, $zero, L_80077B3C
    if (ctx->r24 == 0) {
        // 0x80077B34: addiu       $t9, $t9, 0x6440
        ctx->r25 = ADD32(ctx->r25, 0X6440);
            goto L_80077B3C;
    }
    // 0x80077B34: addiu       $t9, $t9, 0x6440
    ctx->r25 = ADD32(ctx->r25, 0X6440);
    // 0x80077B38: sw          $t9, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r25;
L_80077B3C:
    // 0x80077B3C: jal         0x800D1E00
    // 0x80077B40: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80077B40: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80077B44: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077B48: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80077B4C: lw          $a0, 0x66A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66A0);
    // 0x80077B50: jal         0x800C9390
    // 0x80077B54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80077B54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80077B58: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80077B5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077B60: beq         $t0, $zero, L_80077B74
    if (ctx->r8 == 0) {
        // 0x80077B64: addiu       $a0, $a0, 0x6440
        ctx->r4 = ADD32(ctx->r4, 0X6440);
            goto L_80077B74;
    }
    // 0x80077B64: addiu       $a0, $a0, 0x6440
    ctx->r4 = ADD32(ctx->r4, 0X6440);
    // 0x80077B68: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80077B6C: jal         0x800C9110
    // 0x80077B70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80077B70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_80077B74:
    // 0x80077B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077B78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80077B7C: jr          $ra
    // 0x80077B80: nop

    return;
    // 0x80077B80: nop

;}
RECOMP_FUNC void track_setup_racers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CC7C: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x8000CC80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CC84: sb          $zero, -0x4D60($at)
    MEM_B(-0X4D60, ctx->r1) = 0;
    // 0x8000CC88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CC8C: sw          $zero, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = 0;
    // 0x8000CC90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CC94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000CC98: sb          $zero, -0x4CBC($at)
    MEM_B(-0X4CBC, ctx->r1) = 0;
    // 0x8000CC9C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8000CCA0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000CCA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CCA8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8000CCAC: addiu       $s1, $s1, -0x4B80
    ctx->r17 = ADD32(ctx->r17, -0X4B80);
    // 0x8000CCB0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000CCB4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000CCB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000CCBC: sw          $zero, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = 0;
    // 0x8000CCC0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000CCC4: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8000CCC8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8000CCCC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000CCD0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000CCD4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000CCD8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000CCDC: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x8000CCE0: jal         0x800521F8
    // 0x8000CCE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_taj_status(rdram, ctx);
        goto after_0;
    // 0x8000CCE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8000CCE8: jal         0x8006BFF0
    // 0x8000CCEC: nop

    level_header(rdram, ctx);
        goto after_1;
    // 0x8000CCEC: nop

    after_1:
    // 0x8000CCF0: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x8000CCF4: lbu         $v1, 0x4C($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4C);
    // 0x8000CCF8: addiu       $s6, $zero, 0x6
    ctx->r22 = ADD32(0, 0X6);
    // 0x8000CCFC: beq         $s6, $v1, L_8000E080
    if (ctx->r22 == ctx->r3) {
        // 0x8000CD00: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_8000E080;
    }
    // 0x8000CD00: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8000CD04: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8000CD08: beq         $v1, $at, L_8000E080
    if (ctx->r3 == ctx->r1) {
        // 0x8000CD0C: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_8000E080;
    }
    // 0x8000CD0C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8000CD10: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000CD14: beq         $v1, $at, L_8000CD20
    if (ctx->r3 == ctx->r1) {
        // 0x8000CD18: andi        $t6, $v1, 0x40
        ctx->r14 = ctx->r3 & 0X40;
            goto L_8000CD20;
    }
    // 0x8000CD18: andi        $t6, $v1, 0x40
    ctx->r14 = ctx->r3 & 0X40;
    // 0x8000CD1C: beq         $t6, $zero, L_8000CD34
    if (ctx->r14 == 0) {
        // 0x8000CD20: lui         $s4, 0x8012
        ctx->r20 = S32(0X8012 << 16);
            goto L_8000CD34;
    }
L_8000CD20:
    // 0x8000CD20: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8000CD24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CD28: addiu       $s4, $s4, -0x4B8C
    ctx->r20 = ADD32(ctx->r20, -0X4B8C);
    // 0x8000CD2C: sb          $zero, -0x4B8B($at)
    MEM_B(-0X4B8B, ctx->r1) = 0;
    // 0x8000CD30: sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
L_8000CD34:
    // 0x8000CD34: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8000CD38: addiu       $s4, $s4, -0x4B8C
    ctx->r20 = ADD32(ctx->r20, -0X4B8C);
    // 0x8000CD3C: sw          $t7, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r15;
    // 0x8000CD40: jal         0x8000E4C8
    // 0x8000CD44: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    is_time_trial_enabled(rdram, ctx);
        goto after_2;
    // 0x8000CD44: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_2:
    // 0x8000CD48: beq         $v0, $zero, L_8000CD7C
    if (ctx->r2 == 0) {
        // 0x8000CD4C: nop
    
            goto L_8000CD7C;
    }
    // 0x8000CD4C: nop

    // 0x8000CD50: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8000CD54: nop

    // 0x8000CD58: bne         $t8, $zero, L_8000CD7C
    if (ctx->r24 != 0) {
        // 0x8000CD5C: nop
    
            goto L_8000CD7C;
    }
    // 0x8000CD5C: nop

    // 0x8000CD60: jal         0x80069FBC
    // 0x8000CD64: nop

    cam_get_cameras(rdram, ctx);
        goto after_3;
    // 0x8000CD64: nop

    after_3:
    // 0x8000CD68: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8000CD6C: lbu         $t9, 0x3B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3B);
    // 0x8000CD70: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000CD74: sw          $t9, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r25;
    // 0x8000CD78: sb          $t5, 0x3B($v0)
    MEM_B(0X3B, ctx->r2) = ctx->r13;
L_8000CD7C:
    // 0x8000CD7C: jal         0x8006DC4C
    // 0x8000CD80: nop

    get_game_mode(rdram, ctx);
        goto after_4;
    // 0x8000CD80: nop

    after_4:
    // 0x8000CD84: jal         0x8006ECD0
    // 0x8000CD88: sw          $v0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r2;
    get_settings(rdram, ctx);
        goto after_5;
    // 0x8000CD88: sw          $v0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r2;
    after_5:
    // 0x8000CD8C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x8000CD90: jal         0x8001E2D0
    // 0x8000CD94: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    get_misc_asset(rdram, ctx);
        goto after_6;
    // 0x8000CD94: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x8000CD98: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8000CD9C: addiu       $t3, $t3, -0x4CBB
    ctx->r11 = ADD32(ctx->r11, -0X4CBB);
    // 0x8000CDA0: lb          $t6, 0x0($t3)
    ctx->r14 = MEM_B(ctx->r11, 0X0);
    // 0x8000CDA4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8000CDA8: addiu       $t4, $t4, -0x4BFE
    ctx->r12 = ADD32(ctx->r12, -0X4BFE);
    // 0x8000CDAC: sw          $v0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r2;
    // 0x8000CDB0: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x8000CDB4: lbu         $t8, 0x49($s7)
    ctx->r24 = MEM_BU(ctx->r23, 0X49);
    // 0x8000CDB8: lw          $t7, 0x4($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X4);
    // 0x8000CDBC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000CDC0: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x8000CDC4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8000CDC8: addiu       $v0, $sp, 0xB4
    ctx->r2 = ADD32(ctx->r29, 0XB4);
    // 0x8000CDCC: andi        $t5, $a0, 0x1
    ctx->r13 = ctx->r4 & 0X1;
    // 0x8000CDD0: bne         $t5, $zero, L_8000CDE8
    if (ctx->r13 != 0) {
        // 0x8000CDD4: addiu       $a1, $sp, 0xD4
        ctx->r5 = ADD32(ctx->r29, 0XD4);
            goto L_8000CDE8;
    }
    // 0x8000CDD4: addiu       $a1, $sp, 0xD4
    ctx->r5 = ADD32(ctx->r29, 0XD4);
    // 0x8000CDD8: ori         $t6, $a0, 0x1
    ctx->r14 = ctx->r4 | 0X1;
    // 0x8000CDDC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000CDE0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8000CDE4: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
L_8000CDE8:
    // 0x8000CDE8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8000CDEC: addiu       $v1, $sp, 0xF4
    ctx->r3 = ADD32(ctx->r29, 0XF4);
    // 0x8000CDF0: beq         $t7, $zero, L_8000CE00
    if (ctx->r15 == 0) {
        // 0x8000CDF4: addiu       $a0, $sp, 0xD4
        ctx->r4 = ADD32(ctx->r29, 0XD4);
            goto L_8000CE00;
    }
    // 0x8000CDF4: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x8000CDF8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8000CDFC: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
L_8000CE00:
    // 0x8000CE00: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000CE04: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8000CE08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000CE0C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000CE10: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8000CE14: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
    // 0x8000CE18: bne         $at, $zero, L_8000CE00
    if (ctx->r1 != 0) {
        // 0x8000CE1C: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_8000CE00;
    }
    // 0x8000CE1C: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8000CE20: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CE24: lw          $v0, -0x4C24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C24);
    // 0x8000CE28: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000CE2C: blez        $v0, L_8000CF70
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000CE30: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8000CF70;
    }
    // 0x8000CE30: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8000CE34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000CE38: lw          $a0, -0x4C28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C28);
    // 0x8000CE3C: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x8000CE40: addiu       $t2, $sp, 0x94
    ctx->r10 = ADD32(ctx->r29, 0X94);
    // 0x8000CE44: addiu       $t1, $sp, 0xB4
    ctx->r9 = ADD32(ctx->r29, 0XB4);
    // 0x8000CE48: addiu       $t0, $sp, 0xD4
    ctx->r8 = ADD32(ctx->r29, 0XD4);
    // 0x8000CE4C: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    // 0x8000CE50: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
L_8000CE54:
    // 0x8000CE54: lw          $s1, 0x0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X0);
    // 0x8000CE58: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8000CE5C: lh          $t5, 0x6($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X6);
    // 0x8000CE60: nop

    // 0x8000CE64: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x8000CE68: bne         $t6, $zero, L_8000CF64
    if (ctx->r14 != 0) {
        // 0x8000CE6C: slt         $at, $s5, $a1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8000CF64;
    }
    // 0x8000CE6C: slt         $at, $s5, $a1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000CE70: lh          $t8, 0x48($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X48);
    // 0x8000CE74: nop

    // 0x8000CE78: bne         $a2, $t8, L_8000CF64
    if (ctx->r6 != ctx->r24) {
        // 0x8000CE7C: slt         $at, $s5, $a1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8000CF64;
    }
    // 0x8000CE7C: slt         $at, $s5, $a1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000CE80: lw          $t7, 0x7C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X7C);
    // 0x8000CE84: nop

    // 0x8000CE88: bne         $s0, $t7, L_8000CF64
    if (ctx->r16 != ctx->r15) {
        // 0x8000CE8C: slt         $at, $s5, $a1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8000CF64;
    }
    // 0x8000CE8C: slt         $at, $s5, $a1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000CE90: lw          $v0, 0x78($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X78);
    // 0x8000CE94: nop

    // 0x8000CE98: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8000CE9C: beq         $at, $zero, L_8000CF44
    if (ctx->r1 == 0) {
        // 0x8000CEA0: nop
    
            goto L_8000CF44;
    }
    // 0x8000CEA0: nop

    // 0x8000CEA4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000CEA8: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8000CEAC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8000CEB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000CEB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000CEB8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8000CEBC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000CEC0: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x8000CEC4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000CEC8: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8000CECC: nop

    // 0x8000CED0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000CED4: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x8000CED8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8000CEDC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000CEE0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000CEE4: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8000CEE8: lw          $t6, 0x78($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X78);
    // 0x8000CEEC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000CEF0: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8000CEF4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8000CEF8: addu        $t8, $t0, $t5
    ctx->r24 = ADD32(ctx->r8, ctx->r13);
    // 0x8000CEFC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8000CF00: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000CF04: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000CF08: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8000CF0C: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8000CF10: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000CF14: lw          $t5, 0x78($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X78);
    // 0x8000CF18: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000CF1C: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8000CF20: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8000CF24: addu        $t8, $t1, $t9
    ctx->r24 = ADD32(ctx->r9, ctx->r25);
    // 0x8000CF28: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8000CF2C: lw          $t5, 0x78($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X78);
    // 0x8000CF30: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000CF34: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x8000CF38: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8000CF3C: addu        $t6, $t2, $t9
    ctx->r14 = ADD32(ctx->r10, ctx->r25);
    // 0x8000CF40: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
L_8000CF44:
    // 0x8000CF44: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    // 0x8000CF48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000CF4C: lb          $v1, 0xB($v0)
    ctx->r3 = MEM_B(ctx->r2, 0XB);
    // 0x8000CF50: nop

    // 0x8000CF54: beq         $v1, $at, L_8000CF64
    if (ctx->r3 == ctx->r1) {
        // 0x8000CF58: slt         $at, $s5, $a1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8000CF64;
    }
    // 0x8000CF58: slt         $at, $s5, $a1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000CF5C: or          $fp, $v1, $zero
    ctx->r30 = ctx->r3 | 0;
    // 0x8000CF60: slt         $at, $s5, $a1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
L_8000CF64:
    // 0x8000CF64: bne         $at, $zero, L_8000CE54
    if (ctx->r1 != 0) {
        // 0x8000CF68: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8000CE54;
    }
    // 0x8000CF68: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000CF6C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000CF70:
    // 0x8000CF70: sb          $fp, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r30;
    // 0x8000CF74: lb          $t8, 0x0($t3)
    ctx->r24 = MEM_B(ctx->r11, 0X0);
    // 0x8000CF78: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000CF7C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8000CF80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CF84: sh          $t8, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r24;
    // 0x8000CF88: addiu       $s0, $s0, -0x3350
    ctx->r16 = ADD32(ctx->r16, -0X3350);
    // 0x8000CF8C: addiu       $v0, $s3, 0x1
    ctx->r2 = ADD32(ctx->r19, 0X1);
    // 0x8000CF90: sw          $t5, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = ctx->r13;
    // 0x8000CF94: sw          $v0, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r2;
    // 0x8000CF98: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8000CF9C: jal         0x8006C3DC
    // 0x8000CFA0: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    race_is_adventure_2P(rdram, ctx);
        goto after_7;
    // 0x8000CFA0: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    after_7:
    // 0x8000CFA4: beq         $v0, $zero, L_8000CFC0
    if (ctx->r2 == 0) {
        // 0x8000CFA8: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8000CFC0;
    }
    // 0x8000CFA8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8000CFAC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000CFB0: sw          $t9, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r25;
    // 0x8000CFB4: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x8000CFB8: jal         0x80024A20
    // 0x8000CFBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_scene_viewport_num(rdram, ctx);
        goto after_8;
    // 0x8000CFBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
L_8000CFC0:
    // 0x8000CFC0: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8000CFC4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000CFC8: bne         $t6, $at, L_8000CFD4
    if (ctx->r14 != ctx->r1) {
        // 0x8000CFCC: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8000CFD4;
    }
    // 0x8000CFCC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000CFD0: sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
L_8000CFD4:
    // 0x8000CFD4: lbu         $t8, 0x0($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X0);
    // 0x8000CFD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CFDC: sb          $t8, -0x4B8B($at)
    MEM_B(-0X4B8B, ctx->r1) = ctx->r24;
    // 0x8000CFE0: lbu         $t5, -0x4B8B($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4B8B);
    // 0x8000CFE4: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8000CFE8: beq         $t5, $zero, L_8000CFF8
    if (ctx->r13 == 0) {
        // 0x8000CFEC: lw          $t7, 0x68($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X68);
            goto L_8000CFF8;
    }
    // 0x8000CFEC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8000CFF0: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x8000CFF4: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
L_8000CFF8:
    // 0x8000CFF8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000CFFC: andi        $t6, $t7, 0x40
    ctx->r14 = ctx->r15 & 0X40;
    // 0x8000D000: beq         $t7, $at, L_8000D01C
    if (ctx->r15 == ctx->r1) {
        // 0x8000D004: sw          $t6, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r14;
            goto L_8000D01C;
    }
    // 0x8000D004: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x8000D008: lw          $t8, 0x144($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X144);
    // 0x8000D00C: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x8000D010: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8000D014: bne         $at, $zero, L_8000D058
    if (ctx->r1 != 0) {
        // 0x8000D018: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000D058;
    }
    // 0x8000D018: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8000D01C:
    // 0x8000D01C: lw          $t5, 0x144($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X144);
    // 0x8000D020: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D024: jal         0x8006C530
    // 0x8000D028: sw          $t5, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = ctx->r13;
    level_properties_get(rdram, ctx);
        goto after_9;
    // 0x8000D028: sw          $t5, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = ctx->r13;
    after_9:
    // 0x8000D02C: bne         $v0, $zero, L_8000D070
    if (ctx->r2 != 0) {
        // 0x8000D030: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8000D070;
    }
    // 0x8000D030: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000D034: addiu       $v1, $v1, -0x3388
    ctx->r3 = ADD32(ctx->r3, -0X3388);
    // 0x8000D038: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8000D03C: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x8000D040: beq         $v0, $zero, L_8000D070
    if (ctx->r2 == 0) {
        // 0x8000D044: addu        $t6, $t9, $v0
        ctx->r14 = ADD32(ctx->r25, ctx->r2);
            goto L_8000D070;
    }
    // 0x8000D044: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8000D048: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    // 0x8000D04C: b           L_8000D070
    // 0x8000D050: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
        goto L_8000D070;
    // 0x8000D050: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8000D054: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8000D058:
    // 0x8000D058: bne         $t7, $at, L_8000D074
    if (ctx->r15 != ctx->r1) {
        // 0x8000D05C: lw          $t8, 0x64($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X64);
            goto L_8000D074;
    }
    // 0x8000D05C: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8000D060: jal         0x8009C984
    // 0x8000D064: nop

    get_multiplayer_racer_count(rdram, ctx);
        goto after_10;
    // 0x8000D064: nop

    after_10:
    // 0x8000D068: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D06C: sw          $v0, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = ctx->r2;
L_8000D070:
    // 0x8000D070: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
L_8000D074:
    // 0x8000D074: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000D078: beq         $t8, $zero, L_8000D090
    if (ctx->r24 == 0) {
        // 0x8000D07C: addiu       $a1, $a1, -0x4D44
        ctx->r5 = ADD32(ctx->r5, -0X4D44);
            goto L_8000D090;
    }
    // 0x8000D07C: addiu       $a1, $a1, -0x4D44
    ctx->r5 = ADD32(ctx->r5, -0X4D44);
    // 0x8000D080: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000D084: addiu       $a2, $a2, -0x4B90
    ctx->r6 = ADD32(ctx->r6, -0X4B90);
    // 0x8000D088: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8000D08C: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
L_8000D090:
    // 0x8000D090: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8000D094: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000D098: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000D09C: addiu       $a2, $a2, -0x4B90
    ctx->r6 = ADD32(ctx->r6, -0X4B90);
    // 0x8000D0A0: bne         $t9, $at, L_8000D0BC
    if (ctx->r25 != ctx->r1) {
        // 0x8000D0A4: sb          $zero, 0x0($a1)
        MEM_B(0X0, ctx->r5) = 0;
            goto L_8000D0BC;
    }
    // 0x8000D0A4: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8000D0A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8000D0AC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8000D0B0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8000D0B4: sw          $a3, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r7;
    // 0x8000D0B8: sb          $a3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r7;
L_8000D0BC:
    // 0x8000D0BC: lw          $t7, 0x138($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X138);
    // 0x8000D0C0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000D0C4: addiu       $v0, $v0, -0x3374
    ctx->r2 = ADD32(ctx->r2, -0X3374);
    // 0x8000D0C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8000D0CC: bne         $t7, $a3, L_8000D0F0
    if (ctx->r15 != ctx->r7) {
        // 0x8000D0D0: sb          $zero, 0x0($v0)
        MEM_B(0X0, ctx->r2) = 0;
            goto L_8000D0F0;
    }
    // 0x8000D0D0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8000D0D4: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8000D0D8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8000D0DC: bne         $t8, $zero, L_8000D0F0
    if (ctx->r24 != 0) {
        // 0x8000D0E0: nop
    
            goto L_8000D0F0;
    }
    // 0x8000D0E0: nop

    // 0x8000D0E4: sw          $s6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r22;
    // 0x8000D0E8: sb          $a3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r7;
    // 0x8000D0EC: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
L_8000D0F0:
    // 0x8000D0F0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8000D0F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000D0F8: blez        $v1, L_8000D118
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000D0FC: addiu       $v0, $sp, 0x11C
        ctx->r2 = ADD32(ctx->r29, 0X11C);
            goto L_8000D118;
    }
    // 0x8000D0FC: addiu       $v0, $sp, 0x11C
    ctx->r2 = ADD32(ctx->r29, 0X11C);
    // 0x8000D100: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
L_8000D104:
    // 0x8000D104: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000D108: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8000D10C: bne         $at, $zero, L_8000D104
    if (ctx->r1 != 0) {
        // 0x8000D110: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_8000D104;
    }
    // 0x8000D110: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x8000D114: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000D118:
    // 0x8000D118: lw          $t6, 0x144($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X144);
    // 0x8000D11C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000D120: blez        $t6, L_8000D2E0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000D124: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8000D2E0;
    }
    // 0x8000D124: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000D128: andi        $v0, $t6, 0x3
    ctx->r2 = ctx->r14 & 0X3;
    // 0x8000D12C: beq         $v0, $zero, L_8000D1A4
    if (ctx->r2 == 0) {
        // 0x8000D130: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8000D1A4;
    }
    // 0x8000D130: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8000D134: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8000D138: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x8000D13C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8000D140: addu        $a2, $s7, $t7
    ctx->r6 = ADD32(ctx->r23, ctx->r15);
    // 0x8000D144: addiu       $t0, $sp, 0x114
    ctx->r8 = ADD32(ctx->r29, 0X114);
    // 0x8000D148: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
L_8000D14C:
    // 0x8000D14C: lb          $v0, 0x5A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X5A);
    // 0x8000D150: nop

    // 0x8000D154: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D158: beq         $at, $zero, L_8000D178
    if (ctx->r1 == 0) {
        // 0x8000D15C: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D178;
    }
    // 0x8000D15C: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D160: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8000D164: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000D168: bne         $t8, $zero, L_8000D17C
    if (ctx->r24 != 0) {
        // 0x8000D16C: addu        $t9, $t0, $a1
        ctx->r25 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D17C;
    }
    // 0x8000D16C: addu        $t9, $t0, $a1
    ctx->r25 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D170: b           L_8000D18C
    // 0x8000D174: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
        goto L_8000D18C;
    // 0x8000D174: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_8000D178:
    // 0x8000D178: addu        $t9, $t0, $a1
    ctx->r25 = ADD32(ctx->r8, ctx->r5);
L_8000D17C:
    // 0x8000D17C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D180: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000D184: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8000D188: sb          $s0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r16;
L_8000D18C:
    // 0x8000D18C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000D190: bne         $t1, $s0, L_8000D14C
    if (ctx->r9 != ctx->r16) {
        // 0x8000D194: addiu       $a2, $a2, 0x18
        ctx->r6 = ADD32(ctx->r6, 0X18);
            goto L_8000D14C;
    }
    // 0x8000D194: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x8000D198: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x8000D19C: nop

    // 0x8000D1A0: beq         $s0, $t7, L_8000D2D8
    if (ctx->r16 == ctx->r15) {
        // 0x8000D1A4: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_8000D2D8;
    }
L_8000D1A4:
    // 0x8000D1A4: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8000D1A8: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x8000D1AC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8000D1B0: addu        $a2, $s7, $t8
    ctx->r6 = ADD32(ctx->r23, ctx->r24);
    // 0x8000D1B4: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    // 0x8000D1B8: addiu       $t0, $sp, 0x114
    ctx->r8 = ADD32(ctx->r29, 0X114);
L_8000D1BC:
    // 0x8000D1BC: lb          $v0, 0x5A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X5A);
    // 0x8000D1C0: nop

    // 0x8000D1C4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D1C8: beq         $at, $zero, L_8000D1E8
    if (ctx->r1 == 0) {
        // 0x8000D1CC: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D1E8;
    }
    // 0x8000D1CC: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D1D0: lb          $t5, 0x0($a0)
    ctx->r13 = MEM_B(ctx->r4, 0X0);
    // 0x8000D1D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000D1D8: bne         $t5, $zero, L_8000D1EC
    if (ctx->r13 != 0) {
        // 0x8000D1DC: addu        $t6, $t0, $a1
        ctx->r14 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D1EC;
    }
    // 0x8000D1DC: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D1E0: b           L_8000D1FC
    // 0x8000D1E4: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
        goto L_8000D1FC;
    // 0x8000D1E4: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
L_8000D1E8:
    // 0x8000D1E8: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
L_8000D1EC:
    // 0x8000D1EC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D1F0: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8000D1F4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8000D1F8: sb          $s0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r16;
L_8000D1FC:
    // 0x8000D1FC: lb          $v0, 0x72($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X72);
    // 0x8000D200: nop

    // 0x8000D204: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D208: beq         $at, $zero, L_8000D228
    if (ctx->r1 == 0) {
        // 0x8000D20C: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D228;
    }
    // 0x8000D20C: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D210: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8000D214: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000D218: bne         $t8, $zero, L_8000D22C
    if (ctx->r24 != 0) {
        // 0x8000D21C: addu        $t6, $t0, $a1
        ctx->r14 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D22C;
    }
    // 0x8000D21C: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D220: b           L_8000D240
    // 0x8000D224: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
        goto L_8000D240;
    // 0x8000D224: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_8000D228:
    // 0x8000D228: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
L_8000D22C:
    // 0x8000D22C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D230: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8000D234: addiu       $t9, $s0, 0x1
    ctx->r25 = ADD32(ctx->r16, 0X1);
    // 0x8000D238: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x8000D23C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8000D240:
    // 0x8000D240: lb          $v0, 0x8A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X8A);
    // 0x8000D244: nop

    // 0x8000D248: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D24C: beq         $at, $zero, L_8000D26C
    if (ctx->r1 == 0) {
        // 0x8000D250: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D26C;
    }
    // 0x8000D250: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D254: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8000D258: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000D25C: bne         $t8, $zero, L_8000D270
    if (ctx->r24 != 0) {
        // 0x8000D260: addu        $t6, $t0, $a1
        ctx->r14 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D270;
    }
    // 0x8000D260: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D264: b           L_8000D284
    // 0x8000D268: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
        goto L_8000D284;
    // 0x8000D268: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_8000D26C:
    // 0x8000D26C: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
L_8000D270:
    // 0x8000D270: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D274: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8000D278: addiu       $t9, $s0, 0x2
    ctx->r25 = ADD32(ctx->r16, 0X2);
    // 0x8000D27C: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x8000D280: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8000D284:
    // 0x8000D284: lb          $v0, 0xA2($a2)
    ctx->r2 = MEM_B(ctx->r6, 0XA2);
    // 0x8000D288: nop

    // 0x8000D28C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D290: beq         $at, $zero, L_8000D2B0
    if (ctx->r1 == 0) {
        // 0x8000D294: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D2B0;
    }
    // 0x8000D294: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D298: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8000D29C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000D2A0: bne         $t8, $zero, L_8000D2B4
    if (ctx->r24 != 0) {
        // 0x8000D2A4: addu        $t6, $t0, $a1
        ctx->r14 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D2B4;
    }
    // 0x8000D2A4: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D2A8: b           L_8000D2C8
    // 0x8000D2AC: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
        goto L_8000D2C8;
    // 0x8000D2AC: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_8000D2B0:
    // 0x8000D2B0: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
L_8000D2B4:
    // 0x8000D2B4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D2B8: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8000D2BC: addiu       $t9, $s0, 0x3
    ctx->r25 = ADD32(ctx->r16, 0X3);
    // 0x8000D2C0: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x8000D2C4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8000D2C8:
    // 0x8000D2C8: lw          $t8, 0x144($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X144);
    // 0x8000D2CC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000D2D0: bne         $s0, $t8, L_8000D1BC
    if (ctx->r16 != ctx->r24) {
        // 0x8000D2D4: addiu       $a2, $a2, 0x60
        ctx->r6 = ADD32(ctx->r6, 0X60);
            goto L_8000D1BC;
    }
    // 0x8000D2D4: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
L_8000D2D8:
    // 0x8000D2D8: lw          $v0, 0x144($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X144);
    // 0x8000D2DC: nop

L_8000D2E0:
    // 0x8000D2E0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D2E4: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    // 0x8000D2E8: addiu       $t0, $sp, 0x114
    ctx->r8 = ADD32(ctx->r29, 0X114);
    // 0x8000D2EC: beq         $at, $zero, L_8000D354
    if (ctx->r1 == 0) {
        // 0x8000D2F0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000D354;
    }
    // 0x8000D2F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000D2F4: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8000D2F8: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8000D2FC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8000D300: addu        $a2, $s7, $t5
    ctx->r6 = ADD32(ctx->r23, ctx->r13);
L_8000D304:
    // 0x8000D304: lb          $v0, 0x5A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X5A);
    // 0x8000D308: nop

    // 0x8000D30C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D310: beq         $at, $zero, L_8000D330
    if (ctx->r1 == 0) {
        // 0x8000D314: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D330;
    }
    // 0x8000D314: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D318: lb          $t9, 0x0($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X0);
    // 0x8000D31C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000D320: bne         $t9, $zero, L_8000D334
    if (ctx->r25 != 0) {
        // 0x8000D324: addu        $t7, $t0, $a1
        ctx->r15 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D334;
    }
    // 0x8000D324: addu        $t7, $t0, $a1
    ctx->r15 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D328: b           L_8000D344
    // 0x8000D32C: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
        goto L_8000D344;
    // 0x8000D32C: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
L_8000D330:
    // 0x8000D330: addu        $t7, $t0, $a1
    ctx->r15 = ADD32(ctx->r8, ctx->r5);
L_8000D334:
    // 0x8000D334: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D338: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x8000D33C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8000D340: sb          $s0, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r16;
L_8000D344:
    // 0x8000D344: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000D348: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D34C: bne         $at, $zero, L_8000D304
    if (ctx->r1 != 0) {
        // 0x8000D350: addiu       $a2, $a2, 0x18
        ctx->r6 = ADD32(ctx->r6, 0X18);
            goto L_8000D304;
    }
    // 0x8000D350: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
L_8000D354:
    // 0x8000D354: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000D358: blez        $a1, L_8000D3CC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8000D35C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8000D3CC;
    }
    // 0x8000D35C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8000D360: addiu       $s5, $zero, 0x18
    ctx->r21 = ADD32(0, 0X18);
L_8000D364:
    // 0x8000D364: blez        $v1, L_8000D3BC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000D368: addu        $v0, $a3, $s2
        ctx->r2 = ADD32(ctx->r7, ctx->r18);
            goto L_8000D3BC;
    }
    // 0x8000D368: addu        $v0, $a3, $s2
    ctx->r2 = ADD32(ctx->r7, ctx->r18);
L_8000D36C:
    // 0x8000D36C: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x8000D370: addu        $t6, $t0, $s0
    ctx->r14 = ADD32(ctx->r8, ctx->r16);
    // 0x8000D374: bne         $t5, $zero, L_8000D3A8
    if (ctx->r13 != 0) {
        // 0x8000D378: nop
    
            goto L_8000D3A8;
    }
    // 0x8000D378: nop

    // 0x8000D37C: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x8000D380: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000D384: multu       $t7, $s5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D388: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8000D38C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000D390: mflo        $t8
    ctx->r24 = lo;
    // 0x8000D394: addu        $t5, $s7, $t8
    ctx->r13 = ADD32(ctx->r23, ctx->r24);
    // 0x8000D398: sb          $s2, 0x5A($t5)
    MEM_B(0X5A, ctx->r13) = ctx->r18;
    // 0x8000D39C: lw          $v1, -0x4B90($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B90);
    // 0x8000D3A0: nop

    // 0x8000D3A4: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
L_8000D3A8:
    // 0x8000D3A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000D3AC: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D3B0: bne         $at, $zero, L_8000D36C
    if (ctx->r1 != 0) {
        // 0x8000D3B4: addu        $v0, $a3, $s2
        ctx->r2 = ADD32(ctx->r7, ctx->r18);
            goto L_8000D36C;
    }
    // 0x8000D3B4: addu        $v0, $a3, $s2
    ctx->r2 = ADD32(ctx->r7, ctx->r18);
    // 0x8000D3B8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000D3BC:
    // 0x8000D3BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000D3C0: bne         $s0, $a0, L_8000D364
    if (ctx->r16 != ctx->r4) {
        // 0x8000D3C4: nop
    
            goto L_8000D364;
    }
    // 0x8000D3C4: nop

    // 0x8000D3C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000D3CC:
    // 0x8000D3CC: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8000D3D0: addiu       $s5, $zero, 0x18
    ctx->r21 = ADD32(0, 0X18);
    // 0x8000D3D4: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8000D3D8: jal         0x80070EDC
    // 0x8000D3DC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    mempool_alloc_safe(rdram, ctx);
        goto after_11;
    // 0x8000D3DC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_11:
    // 0x8000D3E0: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // 0x8000D3E4: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x8000D3E8: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x8000D3EC: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8000D3F0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8000D3F4: lb          $t6, 0x4D($t9)
    ctx->r14 = MEM_B(ctx->r25, 0X4D);
    // 0x8000D3F8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8000D3FC: bne         $t6, $zero, L_8000D410
    if (ctx->r14 != 0) {
        // 0x8000D400: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8000D410;
    }
    // 0x8000D400: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000D404: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D408: b           L_8000D41C
    // 0x8000D40C: sb          $zero, -0x4C7E($at)
    MEM_B(-0X4C7E, ctx->r1) = 0;
        goto L_8000D41C;
    // 0x8000D40C: sb          $zero, -0x4C7E($at)
    MEM_B(-0X4C7E, ctx->r1) = 0;
L_8000D410:
    // 0x8000D410: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000D414: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D418: sb          $t7, -0x4C7E($at)
    MEM_B(-0X4C7E, ctx->r1) = ctx->r15;
L_8000D41C:
    // 0x8000D41C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8000D420: lw          $v1, -0x4B90($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B90);
    // 0x8000D424: lb          $t5, 0xB8($t8)
    ctx->r13 = MEM_B(ctx->r24, 0XB8);
    // 0x8000D428: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D42C: sb          $t9, 0x127($sp)
    MEM_B(0X127, ctx->r29) = ctx->r25;
    // 0x8000D430: blez        $v1, L_8000D9AC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000D434: sb          $t5, -0x4D5B($at)
        MEM_B(-0X4D5B, ctx->r1) = ctx->r13;
            goto L_8000D9AC;
    }
    // 0x8000D434: sb          $t5, -0x4D5B($at)
    MEM_B(-0X4D5B, ctx->r1) = ctx->r13;
    // 0x8000D438: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8000D43C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8000D440:
    // 0x8000D440: beq         $v0, $a0, L_8000D4A8
    if (ctx->r2 == ctx->r4) {
        // 0x8000D444: or          $s4, $s0, $zero
        ctx->r20 = ctx->r16 | 0;
            goto L_8000D4A8;
    }
    // 0x8000D444: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x8000D448: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8000D44C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000D450: bne         $t6, $zero, L_8000D4A8
    if (ctx->r14 != 0) {
        // 0x8000D454: nop
    
            goto L_8000D4A8;
    }
    // 0x8000D454: nop

    // 0x8000D458: lb          $t7, -0x4D44($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X4D44);
    // 0x8000D45C: nop

    // 0x8000D460: bne         $t7, $zero, L_8000D4A8
    if (ctx->r15 != 0) {
        // 0x8000D464: nop
    
            goto L_8000D4A8;
    }
    // 0x8000D464: nop

    // 0x8000D468: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8000D46C:
    // 0x8000D46C: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D470: mflo        $t8
    ctx->r24 = lo;
    // 0x8000D474: addu        $t5, $s7, $t8
    ctx->r13 = ADD32(ctx->r23, ctx->r24);
    // 0x8000D478: lb          $t9, 0x5A($t5)
    ctx->r25 = MEM_B(ctx->r13, 0X5A);
    // 0x8000D47C: nop

    // 0x8000D480: bne         $s0, $t9, L_8000D490
    if (ctx->r16 != ctx->r25) {
        // 0x8000D484: nop
    
            goto L_8000D490;
    }
    // 0x8000D484: nop

    // 0x8000D488: or          $s4, $s2, $zero
    ctx->r20 = ctx->r18 | 0;
    // 0x8000D48C: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
L_8000D490:
    // 0x8000D490: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000D494: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D498: bne         $at, $zero, L_8000D46C
    if (ctx->r1 != 0) {
        // 0x8000D49C: nop
    
            goto L_8000D46C;
    }
    // 0x8000D49C: nop

    // 0x8000D4A0: b           L_8000D4A8
    // 0x8000D4A4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_8000D4A8;
    // 0x8000D4A4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000D4A8:
    // 0x8000D4A8: lw          $t6, 0x144($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X144);
    // 0x8000D4AC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8000D4B0: slt         $at, $s4, $t6
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000D4B4: beq         $at, $zero, L_8000D4C4
    if (ctx->r1 == 0) {
        // 0x8000D4B8: sll         $a2, $s0, 2
        ctx->r6 = S32(ctx->r16 << 2);
            goto L_8000D4C4;
    }
    // 0x8000D4B8: sll         $a2, $s0, 2
    ctx->r6 = S32(ctx->r16 << 2);
    // 0x8000D4BC: b           L_8000D4C8
    // 0x8000D4C0: sh          $s4, 0xE($s6)
    MEM_H(0XE, ctx->r22) = ctx->r20;
        goto L_8000D4C8;
    // 0x8000D4C0: sh          $s4, 0xE($s6)
    MEM_H(0XE, ctx->r22) = ctx->r20;
L_8000D4C4:
    // 0x8000D4C4: sh          $t7, 0xE($s6)
    MEM_H(0XE, ctx->r22) = ctx->r15;
L_8000D4C8:
    // 0x8000D4C8: bne         $v0, $a0, L_8000D4E0
    if (ctx->r2 != ctx->r4) {
        // 0x8000D4CC: addiu       $t5, $sp, 0xF4
        ctx->r13 = ADD32(ctx->r29, 0XF4);
            goto L_8000D4E0;
    }
    // 0x8000D4CC: addiu       $t5, $sp, 0xF4
    ctx->r13 = ADD32(ctx->r29, 0XF4);
    // 0x8000D4D0: lh          $t8, 0xE($s6)
    ctx->r24 = MEM_H(ctx->r22, 0XE);
    // 0x8000D4D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D4D8: beq         $t8, $at, L_8000D994
    if (ctx->r24 == ctx->r1) {
        // 0x8000D4DC: nop
    
            goto L_8000D994;
    }
    // 0x8000D4DC: nop

L_8000D4E0:
    // 0x8000D4E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D4E4: addu        $s3, $a2, $t5
    ctx->r19 = ADD32(ctx->r6, ctx->r13);
    // 0x8000D4E8: addiu       $t9, $sp, 0xD4
    ctx->r25 = ADD32(ctx->r29, 0XD4);
    // 0x8000D4EC: lb          $v0, -0x4D44($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D44);
    // 0x8000D4F0: addu        $t6, $a2, $t9
    ctx->r14 = ADD32(ctx->r6, ctx->r25);
    // 0x8000D4F4: addiu       $t5, $sp, 0x94
    ctx->r13 = ADD32(ctx->r29, 0X94);
    // 0x8000D4F8: addiu       $t7, $sp, 0xB4
    ctx->r15 = ADD32(ctx->r29, 0XB4);
    // 0x8000D4FC: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x8000D500: addu        $t9, $a2, $t5
    ctx->r25 = ADD32(ctx->r6, ctx->r13);
    // 0x8000D504: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000D508: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8000D50C: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x8000D510: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x8000D514: bne         $v0, $at, L_8000D560
    if (ctx->r2 != ctx->r1) {
        // 0x8000D518: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_8000D560;
    }
    // 0x8000D518: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8000D51C: bne         $s0, $zero, L_8000D544
    if (ctx->r16 != 0) {
        // 0x8000D520: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8000D544;
    }
    // 0x8000D520: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000D524: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000D528: lb          $t6, -0x4D5B($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X4D5B);
    // 0x8000D52C: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8000D530: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8000D534: addu        $fp, $fp, $t7
    ctx->r30 = ADD32(ctx->r30, ctx->r15);
    // 0x8000D538: lb          $fp, -0x3270($fp)
    ctx->r30 = MEM_B(ctx->r30, -0X3270);
    // 0x8000D53C: b           L_8000D5E0
    // 0x8000D540: nop

        goto L_8000D5E0;
    // 0x8000D540: nop

L_8000D544:
    // 0x8000D544: lb          $t8, -0x4D5B($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X4D5B);
    // 0x8000D548: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8000D54C: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x8000D550: addu        $fp, $fp, $t5
    ctx->r30 = ADD32(ctx->r30, ctx->r13);
    // 0x8000D554: lb          $fp, -0x326F($fp)
    ctx->r30 = MEM_B(ctx->r30, -0X326F);
    // 0x8000D558: b           L_8000D5E0
    // 0x8000D55C: nop

        goto L_8000D5E0;
    // 0x8000D55C: nop

L_8000D560:
    // 0x8000D560: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D564: bne         $v0, $at, L_8000D580
    if (ctx->r2 != ctx->r1) {
        // 0x8000D568: nop
    
            goto L_8000D580;
    }
    // 0x8000D568: nop

    // 0x8000D56C: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8000D570: nop

    // 0x8000D574: lb          $fp, 0x4D($t9)
    ctx->r30 = MEM_B(ctx->r25, 0X4D);
    // 0x8000D578: b           L_8000D5E0
    // 0x8000D57C: nop

        goto L_8000D5E0;
    // 0x8000D57C: nop

L_8000D580:
    // 0x8000D580: lh          $t6, 0xE($s6)
    ctx->r14 = MEM_H(ctx->r22, 0XE);
    // 0x8000D584: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D588: beq         $t6, $at, L_8000D5A4
    if (ctx->r14 == ctx->r1) {
        // 0x8000D58C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000D5A4;
    }
    // 0x8000D58C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000D590: jal         0x8006C3DC
    // 0x8000D594: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    race_is_adventure_2P(rdram, ctx);
        goto after_12;
    // 0x8000D594: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_12:
    // 0x8000D598: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D59C: beq         $v0, $zero, L_8000D5B8
    if (ctx->r2 == 0) {
        // 0x8000D5A0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000D5B8;
    }
    // 0x8000D5A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000D5A4:
    // 0x8000D5A4: jal         0x8009C794
    // 0x8000D5A8: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    get_player_selected_vehicle(rdram, ctx);
        goto after_13;
    // 0x8000D5A8: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_13:
    // 0x8000D5AC: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D5B0: b           L_8000D5E0
    // 0x8000D5B4: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
        goto L_8000D5E0;
    // 0x8000D5B4: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
L_8000D5B8:
    // 0x8000D5B8: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x8000D5BC: nop

    // 0x8000D5C0: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8000D5C4: bne         $at, $zero, L_8000D5E0
    if (ctx->r1 != 0) {
        // 0x8000D5C8: nop
    
            goto L_8000D5E0;
    }
    // 0x8000D5C8: nop

    // 0x8000D5CC: lh          $a0, 0xE($s6)
    ctx->r4 = MEM_H(ctx->r22, 0XE);
    // 0x8000D5D0: jal         0x8009C794
    // 0x8000D5D4: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    get_player_selected_vehicle(rdram, ctx);
        goto after_14;
    // 0x8000D5D4: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_14:
    // 0x8000D5D8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D5DC: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
L_8000D5E0:
    // 0x8000D5E0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000D5E4: lb          $t8, -0x4D44($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X4D44);
    // 0x8000D5E8: lh          $v1, 0xE($s6)
    ctx->r3 = MEM_H(ctx->r22, 0XE);
    // 0x8000D5EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D5F0: bne         $t8, $at, L_8000D634
    if (ctx->r24 != ctx->r1) {
        // 0x8000D5F4: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8000D634;
    }
    // 0x8000D5F4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8000D5F8: addu        $t5, $t5, $s0
    ctx->r13 = ADD32(ctx->r13, ctx->r16);
    // 0x8000D5FC: lb          $t5, -0x3250($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X3250);
    // 0x8000D600: sll         $t6, $fp, 2
    ctx->r14 = S32(ctx->r30 << 2);
    // 0x8000D604: addu        $t6, $t6, $fp
    ctx->r14 = ADD32(ctx->r14, ctx->r30);
    // 0x8000D608: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x8000D60C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000D610: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8000D614: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    // 0x8000D618: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000D61C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8000D620: subu        $t5, $t5, $s4
    ctx->r13 = SUB32(ctx->r13, ctx->r20);
    // 0x8000D624: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8000D628: lh          $v0, -0x32E8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X32E8);
    // 0x8000D62C: b           L_8000D698
    // 0x8000D630: addu        $a3, $s7, $t5
    ctx->r7 = ADD32(ctx->r23, ctx->r13);
        goto L_8000D698;
    // 0x8000D630: addu        $a3, $s7, $t5
    ctx->r7 = ADD32(ctx->r23, ctx->r13);
L_8000D634:
    // 0x8000D634: slti        $at, $fp, 0x5
    ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
    // 0x8000D638: beq         $at, $zero, L_8000D67C
    if (ctx->r1 == 0) {
        // 0x8000D63C: sll         $t9, $fp, 1
        ctx->r25 = S32(ctx->r30 << 1);
            goto L_8000D67C;
    }
    // 0x8000D63C: sll         $t9, $fp, 1
    ctx->r25 = S32(ctx->r30 << 1);
    // 0x8000D640: multu       $s4, $s5
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D644: sll         $t8, $fp, 2
    ctx->r24 = S32(ctx->r30 << 2);
    // 0x8000D648: addu        $t8, $t8, $fp
    ctx->r24 = ADD32(ctx->r24, ctx->r30);
    // 0x8000D64C: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8000D650: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000D654: mflo        $t6
    ctx->r14 = lo;
    // 0x8000D658: addu        $a3, $s7, $t6
    ctx->r7 = ADD32(ctx->r23, ctx->r14);
    // 0x8000D65C: lb          $t9, 0x59($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X59);
    // 0x8000D660: nop

    // 0x8000D664: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x8000D668: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x8000D66C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8000D670: lh          $v0, -0x32E8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X32E8);
    // 0x8000D674: b           L_8000D69C
    // 0x8000D678: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
        goto L_8000D69C;
    // 0x8000D678: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
L_8000D67C:
    // 0x8000D67C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000D680: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x8000D684: subu        $t8, $t8, $s4
    ctx->r24 = SUB32(ctx->r24, ctx->r20);
    // 0x8000D688: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8000D68C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8000D690: lh          $v0, -0x328E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X328E);
    // 0x8000D694: addu        $a3, $s7, $t8
    ctx->r7 = ADD32(ctx->r23, ctx->r24);
L_8000D698:
    // 0x8000D698: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
L_8000D69C:
    // 0x8000D69C: sra         $t5, $t7, 1
    ctx->r13 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8000D6A0: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x8000D6A4: sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
    // 0x8000D6A8: sb          $t6, 0x1($s6)
    MEM_B(0X1, ctx->r22) = ctx->r14;
    // 0x8000D6AC: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8000D6B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D6B4: sh          $t9, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r25;
    // 0x8000D6B8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8000D6BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000D6C0: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8000D6C4: nop

    // 0x8000D6C8: sh          $t7, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r15;
    // 0x8000D6CC: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8000D6D0: nop

    // 0x8000D6D4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8000D6D8: nop

    // 0x8000D6DC: sh          $t6, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r14;
    // 0x8000D6E0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8000D6E4: nop

    // 0x8000D6E8: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8000D6EC: bne         $v1, $at, L_8000D710
    if (ctx->r3 != ctx->r1) {
        // 0x8000D6F0: sh          $t8, 0xC($s6)
        MEM_H(0XC, ctx->r22) = ctx->r24;
            goto L_8000D710;
    }
    // 0x8000D6F0: sh          $t8, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r24;
    // 0x8000D6F4: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x8000D6F8: jal         0x80061C34
    // 0x8000D6FC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    model_anim_offset(rdram, ctx);
        goto after_15;
    // 0x8000D6FC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_15:
    // 0x8000D700: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D704: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8000D708: lh          $v1, 0xE($s6)
    ctx->r3 = MEM_H(ctx->r22, 0XE);
    // 0x8000D70C: nop

L_8000D710:
    // 0x8000D710: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D714: bne         $v1, $at, L_8000D734
    if (ctx->r3 != ctx->r1) {
        // 0x8000D718: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000D734;
    }
    // 0x8000D718: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000D71C: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x8000D720: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x8000D724: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8000D728: bne         $at, $zero, L_8000D734
    if (ctx->r1 != 0) {
        // 0x8000D72C: ori         $t5, $s1, 0x8
        ctx->r13 = ctx->r17 | 0X8;
            goto L_8000D734;
    }
    // 0x8000D72C: ori         $t5, $s1, 0x8
    ctx->r13 = ctx->r17 | 0X8;
    // 0x8000D730: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
L_8000D734:
    // 0x8000D734: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D738: beq         $v1, $at, L_8000D758
    if (ctx->r3 == ctx->r1) {
        // 0x8000D73C: slti        $at, $fp, 0x5
        ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
            goto L_8000D758;
    }
    // 0x8000D73C: slti        $at, $fp, 0x5
    ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
    // 0x8000D740: lw          $t6, 0x144($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X144);
    // 0x8000D744: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000D748: bne         $t6, $at, L_8000D754
    if (ctx->r14 != ctx->r1) {
        // 0x8000D74C: ori         $t9, $s1, 0x10
        ctx->r25 = ctx->r17 | 0X10;
            goto L_8000D754;
    }
    // 0x8000D74C: ori         $t9, $s1, 0x10
    ctx->r25 = ctx->r17 | 0X10;
    // 0x8000D750: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
L_8000D754:
    // 0x8000D754: slti        $at, $fp, 0x5
    ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
L_8000D758:
    // 0x8000D758: bne         $at, $zero, L_8000D77C
    if (ctx->r1 != 0) {
        // 0x8000D75C: nop
    
            goto L_8000D77C;
    }
    // 0x8000D75C: nop

    // 0x8000D760: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8000D764: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x8000D768: jal         0x80061C34
    // 0x8000D76C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    model_anim_offset(rdram, ctx);
        goto after_16;
    // 0x8000D76C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_16:
    // 0x8000D770: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D774: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8000D778: nop

L_8000D77C:
    // 0x8000D77C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000D780: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000D784: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x8000D788: jal         0x8000EA54
    // 0x8000D78C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    spawn_object(rdram, ctx);
        goto after_17;
    // 0x8000D78C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_17:
    // 0x8000D790: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8000D794: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D798: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8000D79C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8000D7A0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000D7A4: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8000D7A8: lw          $t5, -0x4B9C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4B9C);
    // 0x8000D7AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000D7B0: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x8000D7B4: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8000D7B8: lw          $t9, -0x4B98($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4B98);
    // 0x8000D7BC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000D7C0: addu        $t8, $t9, $a2
    ctx->r24 = ADD32(ctx->r25, ctx->r6);
    // 0x8000D7C4: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8000D7C8: lw          $t7, -0x4B94($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4B94);
    // 0x8000D7CC: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    // 0x8000D7D0: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x8000D7D4: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8000D7D8: lw          $s3, 0x64($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X64);
    // 0x8000D7DC: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8000D7E0: sb          $fp, 0x1D6($s3)
    MEM_B(0X1D6, ctx->r19) = ctx->r30;
    // 0x8000D7E4: sb          $fp, 0x1D7($s3)
    MEM_B(0X1D7, ctx->r19) = ctx->r30;
    // 0x8000D7E8: lb          $t9, 0x127($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X127);
    // 0x8000D7EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D7F0: beq         $t9, $at, L_8000D808
    if (ctx->r25 == ctx->r1) {
        // 0x8000D7F4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000D808;
    }
    // 0x8000D7F4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000D7F8: beq         $t9, $fp, L_8000D808
    if (ctx->r25 == ctx->r30) {
        // 0x8000D7FC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8000D808;
    }
    // 0x8000D7FC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000D800: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D804: sb          $t8, -0x4D60($at)
    MEM_B(-0X4D60, ctx->r1) = ctx->r24;
L_8000D808:
    // 0x8000D808: sb          $fp, 0x127($sp)
    MEM_B(0X127, ctx->r29) = ctx->r30;
    // 0x8000D80C: lb          $v0, 0x1D6($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X1D6);
    // 0x8000D810: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D814: beq         $v0, $at, L_8000D82C
    if (ctx->r2 == ctx->r1) {
        // 0x8000D818: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8000D82C;
    }
    // 0x8000D818: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000D81C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8000D820: beq         $v0, $at, L_8000D82C
    if (ctx->r2 == ctx->r1) {
        // 0x8000D824: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8000D82C;
    }
    // 0x8000D824: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000D828: bne         $v0, $at, L_8000D834
    if (ctx->r2 != ctx->r1) {
        // 0x8000D82C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8000D834;
    }
L_8000D82C:
    // 0x8000D82C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D830: sb          $t7, -0x4C7E($at)
    MEM_B(-0X4C7E, ctx->r1) = ctx->r15;
L_8000D834:
    // 0x8000D834: sb          $fp, 0x1CB($s3)
    MEM_B(0X1CB, ctx->r19) = ctx->r30;
    // 0x8000D838: lb          $v0, 0x1CB($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X1CB);
    // 0x8000D83C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000D840: bltz        $v0, L_8000D850
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000D844: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_8000D850;
    }
    // 0x8000D844: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8000D848: bne         $at, $zero, L_8000D854
    if (ctx->r1 != 0) {
        // 0x8000D84C: nop
    
            goto L_8000D854;
    }
    // 0x8000D84C: nop

L_8000D850:
    // 0x8000D850: sb          $zero, 0x1CB($s3)
    MEM_B(0X1CB, ctx->r19) = 0;
L_8000D854:
    // 0x8000D854: sb          $s4, 0x2($s3)
    MEM_B(0X2, ctx->r19) = ctx->r20;
    // 0x8000D858: lb          $t5, 0x59($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X59);
    // 0x8000D85C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000D860: sb          $t5, 0x3($s3)
    MEM_B(0X3, ctx->r19) = ctx->r13;
    // 0x8000D864: lb          $t6, -0x4D44($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X4D44);
    // 0x8000D868: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D86C: bne         $t6, $at, L_8000D880
    if (ctx->r14 != ctx->r1) {
        // 0x8000D870: addu        $t9, $t9, $s0
        ctx->r25 = ADD32(ctx->r25, ctx->r16);
            goto L_8000D880;
    }
    // 0x8000D870: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x8000D874: lb          $t9, -0x3250($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X3250);
    // 0x8000D878: b           L_8000D88C
    // 0x8000D87C: sb          $t9, 0x3($s3)
    MEM_B(0X3, ctx->r19) = ctx->r25;
        goto L_8000D88C;
    // 0x8000D87C: sb          $t9, 0x3($s3)
    MEM_B(0X3, ctx->r19) = ctx->r25;
L_8000D880:
    // 0x8000D880: lb          $t8, 0x59($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X59);
    // 0x8000D884: nop

    // 0x8000D888: sb          $t8, 0x3($s3)
    MEM_B(0X3, ctx->r19) = ctx->r24;
L_8000D88C:
    // 0x8000D88C: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8000D890: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8000D894: bne         $t7, $at, L_8000D8A4
    if (ctx->r15 != ctx->r1) {
        // 0x8000D898: addiu       $t5, $zero, 0x8
        ctx->r13 = ADD32(0, 0X8);
            goto L_8000D8A4;
    }
    // 0x8000D898: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8000D89C: b           L_8000D8A8
    // 0x8000D8A0: sb          $t5, 0x185($s3)
    MEM_B(0X185, ctx->r19) = ctx->r13;
        goto L_8000D8A8;
    // 0x8000D8A0: sb          $t5, 0x185($s3)
    MEM_B(0X185, ctx->r19) = ctx->r13;
L_8000D8A4:
    // 0x8000D8A4: sb          $zero, 0x185($s3)
    MEM_B(0X185, ctx->r19) = 0;
L_8000D8A8:
    // 0x8000D8A8: jal         0x8009C850
    // 0x8000D8AC: nop

    get_filtered_cheats(rdram, ctx);
        goto after_18;
    // 0x8000D8AC: nop

    after_18:
    // 0x8000D8B0: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x8000D8B4: beq         $t6, $zero, L_8000D8E4
    if (ctx->r14 == 0) {
        // 0x8000D8B8: lw          $t5, 0x138($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X138);
            goto L_8000D8E4;
    }
    // 0x8000D8B8: lw          $t5, 0x138($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X138);
    // 0x8000D8BC: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8000D8C0: nop

    // 0x8000D8C4: bne         $t9, $zero, L_8000D8E4
    if (ctx->r25 != 0) {
        // 0x8000D8C8: lw          $t5, 0x138($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X138);
            goto L_8000D8E4;
    }
    // 0x8000D8C8: lw          $t5, 0x138($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X138);
    // 0x8000D8CC: lh          $t8, 0x0($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X0);
    // 0x8000D8D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D8D4: beq         $t8, $at, L_8000D8E0
    if (ctx->r24 == ctx->r1) {
        // 0x8000D8D8: addiu       $t7, $zero, 0xA
        ctx->r15 = ADD32(0, 0XA);
            goto L_8000D8E0;
    }
    // 0x8000D8D8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8000D8DC: sb          $t7, 0x185($s3)
    MEM_B(0X185, ctx->r19) = ctx->r15;
L_8000D8E0:
    // 0x8000D8E0: lw          $t5, 0x138($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X138);
L_8000D8E4:
    // 0x8000D8E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000D8E8: bne         $t5, $at, L_8000D8FC
    if (ctx->r13 != ctx->r1) {
        // 0x8000D8EC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8000D8FC;
    }
    // 0x8000D8EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000D8F0: lb          $t6, -0x4D44($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X4D44);
    // 0x8000D8F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D8F8: bne         $t6, $at, L_8000D920
    if (ctx->r14 != ctx->r1) {
        // 0x8000D8FC: slti        $at, $fp, 0x5
        ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
            goto L_8000D920;
    }
L_8000D8FC:
    // 0x8000D8FC: slti        $at, $fp, 0x5
    ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
    // 0x8000D900: beq         $at, $zero, L_8000D920
    if (ctx->r1 == 0) {
        // 0x8000D904: nop
    
            goto L_8000D920;
    }
    // 0x8000D904: nop

    // 0x8000D908: lb          $a0, 0x3($s3)
    ctx->r4 = MEM_B(ctx->r19, 0X3);
    // 0x8000D90C: lb          $a1, 0x1D6($s3)
    ctx->r5 = MEM_B(ctx->r19, 0X1D6);
    // 0x8000D910: jal         0x80004B40
    // 0x8000D914: nop

    racer_sound_init(rdram, ctx);
        goto after_19;
    // 0x8000D914: nop

    after_19:
    // 0x8000D918: b           L_8000D924
    // 0x8000D91C: sw          $v0, 0x118($s3)
    MEM_W(0X118, ctx->r19) = ctx->r2;
        goto L_8000D924;
    // 0x8000D91C: sw          $v0, 0x118($s3)
    MEM_W(0X118, ctx->r19) = ctx->r2;
L_8000D920:
    // 0x8000D920: sw          $zero, 0x118($s3)
    MEM_W(0X118, ctx->r19) = 0;
L_8000D924:
    // 0x8000D924: lb          $t9, 0x3($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X3);
    // 0x8000D928: lw          $t8, 0x128($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X128);
    // 0x8000D92C: nop

    // 0x8000D930: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8000D934: lb          $t5, 0x0($t7)
    ctx->r13 = MEM_B(ctx->r15, 0X0);
    // 0x8000D938: lw          $t9, 0x4C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4C);
    // 0x8000D93C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000D940: sb          $t6, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r14;
    // 0x8000D944: lb          $t8, 0x1D6($s3)
    ctx->r24 = MEM_B(ctx->r19, 0X1D6);
    // 0x8000D948: nop

    // 0x8000D94C: addiu       $t7, $t8, -0x5
    ctx->r15 = ADD32(ctx->r24, -0X5);
    // 0x8000D950: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x8000D954: beq         $at, $zero, L_8000D98C
    if (ctx->r1 == 0) {
        // 0x8000D958: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8000D98C;
    }
    // 0x8000D958: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000D95C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000D960: addu        $at, $at, $t7
    gpr jr_addend_8000D96C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8000D964: lw          $t7, 0x56E4($at)
    ctx->r15 = ADD32(ctx->r1, 0X56E4);
    // 0x8000D968: nop

    // 0x8000D96C: jr          $t7
    // 0x8000D970: nop

    switch (jr_addend_8000D96C >> 2) {
        case 0: goto L_8000D974; break;
        case 1: goto L_8000D974; break;
        case 2: goto L_8000D974; break;
        case 3: goto L_8000D974; break;
        case 4: goto L_8000D974; break;
        case 5: goto L_8000D98C; break;
        case 6: goto L_8000D974; break;
        case 7: goto L_8000D974; break;
        case 8: goto L_8000D974; break;
        default: switch_error(__func__, 0x8000D96C, 0x800E56E4);
    }
    // 0x8000D970: nop

L_8000D974:
    // 0x8000D974: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000D978: jal         0x8005C490
    // 0x8000D97C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    racer_special_init(rdram, ctx);
        goto after_20;
    // 0x8000D97C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_20:
    // 0x8000D980: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8000D984: b           L_8000D994
    // 0x8000D988: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8000D994;
    // 0x8000D988: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8000D98C:
    // 0x8000D98C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8000D990: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8000D994:
    // 0x8000D994: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000D998: lw          $v1, -0x4B90($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B90);
    // 0x8000D99C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000D9A0: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D9A4: bne         $at, $zero, L_8000D440
    if (ctx->r1 != 0) {
        // 0x8000D9A8: nop
    
            goto L_8000D440;
    }
    // 0x8000D9A8: nop

L_8000D9AC:
    // 0x8000D9AC: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8000D9B0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000D9B4: beq         $a0, $at, L_8000D9C4
    if (ctx->r4 == ctx->r1) {
        // 0x8000D9B8: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8000D9C4;
    }
    // 0x8000D9B8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8000D9BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D9C0: sb          $zero, -0x4D44($at)
    MEM_B(-0X4D44, ctx->r1) = 0;
L_8000D9C4:
    // 0x8000D9C4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000D9C8: lb          $t5, -0x4D44($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X4D44);
    // 0x8000D9CC: nop

    // 0x8000D9D0: beq         $t5, $zero, L_8000D9DC
    if (ctx->r13 == 0) {
        // 0x8000D9D4: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8000D9DC;
    }
    // 0x8000D9D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D9D8: sb          $zero, -0x4D60($at)
    MEM_B(-0X4D60, ctx->r1) = 0;
L_8000D9DC:
    // 0x8000D9DC: jal         0x8006DC4C
    // 0x8000D9E0: nop

    get_game_mode(rdram, ctx);
        goto after_21;
    // 0x8000D9E0: nop

    after_21:
    // 0x8000D9E4: bne         $v0, $zero, L_8000DA9C
    if (ctx->r2 != 0) {
        // 0x8000D9E8: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8000DA9C;
    }
    // 0x8000D9E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D9EC: lw          $v0, -0x4C24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C24);
    // 0x8000D9F0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8000D9F4: blez        $v0, L_8000DA9C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000D9F8: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_8000DA9C;
    }
    // 0x8000D9F8: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8000D9FC: addiu       $s3, $s3, -0x4C28
    ctx->r19 = ADD32(ctx->r19, -0X4C28);
L_8000DA00:
    // 0x8000DA00: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8000DA04: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000DA08: addu        $t9, $t6, $s5
    ctx->r25 = ADD32(ctx->r14, ctx->r21);
    // 0x8000DA0C: lw          $s1, 0x0($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X0);
    // 0x8000DA10: nop

    // 0x8000DA14: lw          $t8, 0x40($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X40);
    // 0x8000DA18: nop

    // 0x8000DA1C: lhu         $s0, 0x30($t8)
    ctx->r16 = MEM_HU(ctx->r24, 0X30);
    // 0x8000DA20: nop

    // 0x8000DA24: andi        $t7, $s0, 0x20
    ctx->r15 = ctx->r16 & 0X20;
    // 0x8000DA28: beq         $t7, $zero, L_8000DA58
    if (ctx->r15 == 0) {
        // 0x8000DA2C: andi        $t6, $s0, 0x40
        ctx->r14 = ctx->r16 & 0X40;
            goto L_8000DA58;
    }
    // 0x8000DA2C: andi        $t6, $s0, 0x40
    ctx->r14 = ctx->r16 & 0X40;
    // 0x8000DA30: lbu         $t5, -0x4B8B($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4B8B);
    // 0x8000DA34: nop

    // 0x8000DA38: beq         $t5, $zero, L_8000DA58
    if (ctx->r13 == 0) {
        // 0x8000DA3C: nop
    
            goto L_8000DA58;
    }
    // 0x8000DA3C: nop

    // 0x8000DA40: jal         0x8000FFB8
    // 0x8000DA44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_22;
    // 0x8000DA44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x8000DA48: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000DA4C: lw          $v0, -0x4C24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C24);
    // 0x8000DA50: b           L_8000DA8C
    // 0x8000DA54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8000DA8C;
    // 0x8000DA54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8000DA58:
    // 0x8000DA58: beq         $t6, $zero, L_8000DA88
    if (ctx->r14 == 0) {
        // 0x8000DA5C: nop
    
            goto L_8000DA88;
    }
    // 0x8000DA5C: nop

    // 0x8000DA60: lw          $t9, 0x144($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X144);
    // 0x8000DA64: nop

    // 0x8000DA68: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8000DA6C: bne         $at, $zero, L_8000DA88
    if (ctx->r1 != 0) {
        // 0x8000DA70: nop
    
            goto L_8000DA88;
    }
    // 0x8000DA70: nop

    // 0x8000DA74: jal         0x8000FFB8
    // 0x8000DA78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_23;
    // 0x8000DA78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
    // 0x8000DA7C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000DA80: lw          $v0, -0x4C24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C24);
    // 0x8000DA84: nop

L_8000DA88:
    // 0x8000DA88: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8000DA8C:
    // 0x8000DA8C: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000DA90: bne         $at, $zero, L_8000DA00
    if (ctx->r1 != 0) {
        // 0x8000DA94: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_8000DA00;
    }
    // 0x8000DA94: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8000DA98: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000DA9C:
    // 0x8000DA9C: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x8000DAA0: addiu       $s5, $s5, -0x3378
    ctx->r21 = ADD32(ctx->r21, -0X3378);
    // 0x8000DAA4: jal         0x80059B9C
    // 0x8000DAA8: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    timetrial_free_staff_ghost(rdram, ctx);
        goto after_24;
    // 0x8000DAA8: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    after_24:
    // 0x8000DAAC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8000DAB0: addiu       $s1, $s1, -0x4D48
    ctx->r17 = ADD32(ctx->r17, -0X4D48);
    // 0x8000DAB4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8000DAB8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8000DABC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000DAC0: lbu         $t7, -0x4B8B($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4B8B);
    // 0x8000DAC4: nop

    // 0x8000DAC8: beq         $t7, $zero, L_8000DC90
    if (ctx->r15 == 0) {
        // 0x8000DACC: nop
    
            goto L_8000DC90;
    }
    // 0x8000DACC: nop

    // 0x8000DAD0: lw          $t5, 0x144($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X144);
    // 0x8000DAD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000DAD8: bne         $t5, $at, L_8000DC90
    if (ctx->r13 != ctx->r1) {
        // 0x8000DADC: nop
    
            goto L_8000DC90;
    }
    // 0x8000DADC: nop

    // 0x8000DAE0: jal         0x80059994
    // 0x8000DAE4: nop

    timetrial_reset_player_ghost(rdram, ctx);
        goto after_25;
    // 0x8000DAE4: nop

    after_25:
    // 0x8000DAE8: jal         0x8001B69C
    // 0x8000DAEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    timetrial_init_player_ghost(rdram, ctx);
        goto after_26;
    // 0x8000DAEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_26:
    // 0x8000DAF0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000DAF4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8000DAF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000DAFC: addiu       $s0, $s0, -0x3368
    ctx->r16 = ADD32(ctx->r16, -0X3368);
    // 0x8000DB00: sb          $zero, -0x3360($at)
    MEM_B(-0X3360, ctx->r1) = 0;
    // 0x8000DB04: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8000DB08: nop

    // 0x8000DB0C: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x8000DB10: bne         $at, $zero, L_8000DB1C
    if (ctx->r1 != 0) {
        // 0x8000DB14: nop
    
            goto L_8000DB1C;
    }
    // 0x8000DB14: nop

    // 0x8000DB18: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_8000DB1C:
    // 0x8000DB1C: jal         0x8001B2BC
    // 0x8000DB20: nop

    timetrial_valid_player_ghost(rdram, ctx);
        goto after_27;
    // 0x8000DB20: nop

    after_27:
    // 0x8000DB24: beq         $v0, $zero, L_8000DBD8
    if (ctx->r2 == 0) {
        // 0x8000DB28: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8000DBD8;
    }
    // 0x8000DB28: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000DB2C: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8000DB30: lh          $t9, -0x3364($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X3364);
    // 0x8000DB34: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8000DB38: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8000DB3C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8000DB40: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x8000DB44: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x8000DB48: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000DB4C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8000DB50: lh          $v0, -0x32E8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X32E8);
    // 0x8000DB54: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000DB58: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x8000DB5C: sra         $t5, $t7, 1
    ctx->r13 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8000DB60: ori         $t8, $t5, 0x10
    ctx->r24 = ctx->r13 | 0X10;
    // 0x8000DB64: sb          $t8, 0x1($s6)
    MEM_B(0X1, ctx->r22) = ctx->r24;
    // 0x8000DB68: sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
    // 0x8000DB6C: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x8000DB70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000DB74: sh          $t6, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r14;
    // 0x8000DB78: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x8000DB7C: nop

    // 0x8000DB80: sh          $t9, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r25;
    // 0x8000DB84: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8000DB88: nop

    // 0x8000DB8C: sh          $t7, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r15;
    // 0x8000DB90: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8000DB94: jal         0x8000EA54
    // 0x8000DB98: sh          $t5, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r13;
    spawn_object(rdram, ctx);
        goto after_28;
    // 0x8000DB98: sh          $t5, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r13;
    after_28:
    // 0x8000DB9C: addiu       $t8, $zero, 0x3A
    ctx->r24 = ADD32(0, 0X3A);
    // 0x8000DBA0: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8000DBA4: sh          $t8, 0x48($v0)
    MEM_H(0X48, ctx->r2) = ctx->r24;
    // 0x8000DBA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000DBAC: lwc1        $f4, 0x5708($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5708);
    // 0x8000DBB0: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
    // 0x8000DBB4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000DBB8: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x8000DBBC: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x8000DBC0: addiu       $v1, $v1, -0x4D4C
    ctx->r3 = ADD32(ctx->r3, -0X4D4C);
    // 0x8000DBC4: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    // 0x8000DBC8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000DBCC: lw          $s3, 0x64($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X64);
    // 0x8000DBD0: addiu       $t5, $zero, 0x60
    ctx->r13 = ADD32(0, 0X60);
    // 0x8000DBD4: sb          $t5, 0x1F7($s3)
    MEM_B(0X1F7, ctx->r19) = ctx->r13;
L_8000DBD8:
    // 0x8000DBD8: jal         0x8006BFC8
    // 0x8000DBDC: nop

    level_id(rdram, ctx);
        goto after_29;
    // 0x8000DBDC: nop

    after_29:
    // 0x8000DBE0: jal         0x8001B530
    // 0x8000DBE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    timetrial_init_staff_ghost(rdram, ctx);
        goto after_30;
    // 0x8000DBE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_30:
    // 0x8000DBE8: beq         $v0, $zero, L_8000DC90
    if (ctx->r2 == 0) {
        // 0x8000DBEC: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8000DC90;
    }
    // 0x8000DBEC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000DBF0: lh          $t8, -0x4BFC($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4BFC);
    // 0x8000DBF4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000DBF8: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8000DBFC: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8000DC00: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8000DC04: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8000DC08: lh          $v0, -0x32D8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X32D8);
    // 0x8000DC0C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000DC10: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x8000DC14: sra         $t5, $t7, 1
    ctx->r13 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8000DC18: ori         $t8, $t5, 0x10
    ctx->r24 = ctx->r13 | 0X10;
    // 0x8000DC1C: sb          $t8, 0x1($s6)
    MEM_B(0X1, ctx->r22) = ctx->r24;
    // 0x8000DC20: sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
    // 0x8000DC24: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x8000DC28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000DC2C: sh          $t6, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r14;
    // 0x8000DC30: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x8000DC34: nop

    // 0x8000DC38: sh          $t9, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r25;
    // 0x8000DC3C: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8000DC40: nop

    // 0x8000DC44: sh          $t7, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r15;
    // 0x8000DC48: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8000DC4C: jal         0x8000EA54
    // 0x8000DC50: sh          $t5, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r13;
    spawn_object(rdram, ctx);
        goto after_31;
    // 0x8000DC50: sh          $t5, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r13;
    after_31:
    // 0x8000DC54: addiu       $t8, $zero, 0x3A
    ctx->r24 = ADD32(0, 0X3A);
    // 0x8000DC58: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8000DC5C: sh          $t8, 0x48($v0)
    MEM_H(0X48, ctx->r2) = ctx->r24;
    // 0x8000DC60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000DC64: lwc1        $f6, 0x570C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X570C);
    // 0x8000DC68: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
    // 0x8000DC6C: addiu       $t5, $zero, 0x60
    ctx->r13 = ADD32(0, 0X60);
    // 0x8000DC70: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x8000DC74: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x8000DC78: nop

    // 0x8000DC7C: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    // 0x8000DC80: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x8000DC84: lw          $s3, 0x64($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X64);
    // 0x8000DC88: nop

    // 0x8000DC8C: sb          $t5, 0x1F7($s3)
    MEM_B(0X1F7, ctx->r19) = ctx->r13;
L_8000DC90:
    // 0x8000DC90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000DC94: lw          $t6, -0x4B90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B90);
    // 0x8000DC98: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8000DC9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DCA0: blez        $t6, L_8000DE44
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000DCA4: sw          $t8, -0x4CD0($at)
        MEM_W(-0X4CD0, ctx->r1) = ctx->r24;
            goto L_8000DE44;
    }
    // 0x8000DCA4: sw          $t8, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = ctx->r24;
    // 0x8000DCA8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8000DCAC:
    // 0x8000DCAC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000DCB0: lw          $t9, -0x4B9C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4B9C);
    // 0x8000DCB4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000DCB8: addu        $t7, $t9, $s5
    ctx->r15 = ADD32(ctx->r25, ctx->r21);
    // 0x8000DCBC: lw          $s1, 0x0($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X0);
    // 0x8000DCC0: nop

    // 0x8000DCC4: lw          $s3, 0x64($s1)
    ctx->r19 = MEM_W(ctx->r17, 0X64);
    // 0x8000DCC8: nop

    // 0x8000DCCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8000DCD0:
    // 0x8000DCD0: jal         0x8004DE78
    // 0x8000DCD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    update_player_racer(rdram, ctx);
        goto after_32;
    // 0x8000DCD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_32:
    // 0x8000DCD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000DCDC: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8000DCE0: bne         $at, $zero, L_8000DCD0
    if (ctx->r1 != 0) {
        // 0x8000DCE4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8000DCD0;
    }
    // 0x8000DCE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000DCE8: lh          $t5, 0x0($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X0);
    // 0x8000DCEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000DCF0: bne         $t5, $at, L_8000DD68
    if (ctx->r13 != ctx->r1) {
        // 0x8000DCF4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000DD68;
    }
    // 0x8000DCF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000DCF8: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8000DCFC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8000DD00: lb          $a0, 0x55($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X55);
    // 0x8000DD04: andi        $t8, $s4, 0x1
    ctx->r24 = ctx->r20 & 0X1;
    // 0x8000DD08: blez        $a0, L_8000DDCC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000DD0C: or          $s4, $t8, $zero
        ctx->r20 = ctx->r24 | 0;
            goto L_8000DDCC;
    }
    // 0x8000DD0C: or          $s4, $t8, $zero
    ctx->r20 = ctx->r24 | 0;
    // 0x8000DD10: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000DD14:
    // 0x8000DD14: lw          $t9, 0x68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X68);
    // 0x8000DD18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000DD1C: addu        $t7, $t9, $v1
    ctx->r15 = ADD32(ctx->r25, ctx->r3);
    // 0x8000DD20: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8000DD24: nop

    // 0x8000DD28: beq         $v0, $zero, L_8000DD58
    if (ctx->r2 == 0) {
        // 0x8000DD2C: slt         $at, $s0, $a0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8000DD58;
    }
    // 0x8000DD2C: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000DD30: lb          $t5, 0x20($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X20);
    // 0x8000DD34: sll         $t8, $s4, 1
    ctx->r24 = S32(ctx->r20 << 1);
    // 0x8000DD38: beq         $t5, $zero, L_8000DD58
    if (ctx->r13 == 0) {
        // 0x8000DD3C: slt         $at, $s0, $a0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8000DD58;
    }
    // 0x8000DD3C: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000DD40: sb          $t8, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r24;
    // 0x8000DD44: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8000DD48: nop

    // 0x8000DD4C: lb          $a0, 0x55($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X55);
    // 0x8000DD50: nop

    // 0x8000DD54: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
L_8000DD58:
    // 0x8000DD58: bne         $at, $zero, L_8000DD14
    if (ctx->r1 != 0) {
        // 0x8000DD5C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000DD14;
    }
    // 0x8000DD5C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000DD60: b           L_8000DDCC
    // 0x8000DD64: nop

        goto L_8000DDCC;
    // 0x8000DD64: nop

L_8000DD68:
    // 0x8000DD68: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    // 0x8000DD6C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000DD70: lb          $a0, 0x55($t9)
    ctx->r4 = MEM_B(ctx->r25, 0X55);
    // 0x8000DD74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000DD78: blez        $a0, L_8000DDCC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000DD7C: nop
    
            goto L_8000DDCC;
    }
    // 0x8000DD7C: nop

L_8000DD80:
    // 0x8000DD80: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
    // 0x8000DD84: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000DD88: addu        $t5, $t7, $v1
    ctx->r13 = ADD32(ctx->r15, ctx->r3);
    // 0x8000DD8C: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x8000DD90: nop

    // 0x8000DD94: beq         $v0, $zero, L_8000DDC4
    if (ctx->r2 == 0) {
        // 0x8000DD98: slt         $at, $s0, $a0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8000DDC4;
    }
    // 0x8000DD98: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000DD9C: lb          $t8, 0x20($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X20);
    // 0x8000DDA0: nop

    // 0x8000DDA4: beq         $t8, $zero, L_8000DDC4
    if (ctx->r24 == 0) {
        // 0x8000DDA8: slt         $at, $s0, $a0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8000DDC4;
    }
    // 0x8000DDA8: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000DDAC: sb          $zero, 0x20($v0)
    MEM_B(0X20, ctx->r2) = 0;
    // 0x8000DDB0: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8000DDB4: nop

    // 0x8000DDB8: lb          $a0, 0x55($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X55);
    // 0x8000DDBC: nop

    // 0x8000DDC0: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
L_8000DDC4:
    // 0x8000DDC4: bne         $at, $zero, L_8000DD80
    if (ctx->r1 != 0) {
        // 0x8000DDC8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000DD80;
    }
    // 0x8000DDC8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8000DDCC:
    // 0x8000DDCC: jal         0x8009C850
    // 0x8000DDD0: nop

    get_filtered_cheats(rdram, ctx);
        goto after_33;
    // 0x8000DDD0: nop

    after_33:
    // 0x8000DDD4: andi        $t9, $v0, 0x10
    ctx->r25 = ctx->r2 & 0X10;
    // 0x8000DDD8: beq         $t9, $zero, L_8000DDF4
    if (ctx->r25 == 0) {
        // 0x8000DDDC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000DDF4;
    }
    // 0x8000DDDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000DDE0: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8000DDE4: lwc1        $f10, 0x5710($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5710);
    // 0x8000DDE8: nop

    // 0x8000DDEC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000DDF0: swc1        $f16, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f16.u32l;
L_8000DDF4:
    // 0x8000DDF4: jal         0x8009C850
    // 0x8000DDF8: nop

    get_filtered_cheats(rdram, ctx);
        goto after_34;
    // 0x8000DDF8: nop

    after_34:
    // 0x8000DDFC: andi        $t7, $v0, 0x20
    ctx->r15 = ctx->r2 & 0X20;
    // 0x8000DE00: beq         $t7, $zero, L_8000DE1C
    if (ctx->r15 == 0) {
        // 0x8000DE04: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000DE1C;
    }
    // 0x8000DE04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000DE08: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8000DE0C: lwc1        $f4, 0x5714($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5714);
    // 0x8000DE10: nop

    // 0x8000DE14: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8000DE18: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
L_8000DE1C:
    // 0x8000DE1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000DE20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000DE24: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000DE28: swc1        $f0, 0x90($s3)
    MEM_W(0X90, ctx->r19) = ctx->f0.u32l;
    // 0x8000DE2C: swc1        $f0, 0x8C($s3)
    MEM_W(0X8C, ctx->r19) = ctx->f0.u32l;
    // 0x8000DE30: lw          $t5, -0x4B90($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4B90);
    // 0x8000DE34: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000DE38: slt         $at, $s2, $t5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000DE3C: bne         $at, $zero, L_8000DCAC
    if (ctx->r1 != 0) {
        // 0x8000DE40: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_8000DCAC;
    }
    // 0x8000DE40: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8000DE44:
    // 0x8000DE44: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8000DE48: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8000DE4C: beq         $t8, $zero, L_8000DE7C
    if (ctx->r24 == 0) {
        // 0x8000DE50: addiu       $t5, $zero, 0x50
        ctx->r13 = ADD32(0, 0X50);
            goto L_8000DE7C;
    }
    // 0x8000DE50: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x8000DE54: bne         $t6, $zero, L_8000DE7C
    if (ctx->r14 != 0) {
        // 0x8000DE58: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8000DE7C;
    }
    // 0x8000DE58: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000DE5C: lbu         $t9, -0x4B8B($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X4B8B);
    // 0x8000DE60: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000DE64: bne         $t9, $zero, L_8000DE7C
    if (ctx->r25 != 0) {
        // 0x8000DE68: nop
    
            goto L_8000DE7C;
    }
    // 0x8000DE68: nop

    // 0x8000DE6C: lb          $t7, -0x4D44($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X4D44);
    // 0x8000DE70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DE74: beq         $t7, $zero, L_8000DE88
    if (ctx->r15 == 0) {
        // 0x8000DE78: nop
    
            goto L_8000DE88;
    }
    // 0x8000DE78: nop

L_8000DE7C:
    // 0x8000DE7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DE80: b           L_8000DE8C
    // 0x8000DE84: sw          $t5, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = ctx->r13;
        goto L_8000DE8C;
    // 0x8000DE84: sw          $t5, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = ctx->r13;
L_8000DE88:
    // 0x8000DE88: sw          $zero, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = 0;
L_8000DE8C:
    // 0x8000DE8C: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8000DE90: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8000DE94: bne         $t8, $zero, L_8000DF00
    if (ctx->r24 != 0) {
        // 0x8000DE98: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8000DF00;
    }
    // 0x8000DE98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000DE9C: bne         $t6, $at, L_8000DF00
    if (ctx->r14 != ctx->r1) {
        // 0x8000DEA0: nop
    
            goto L_8000DF00;
    }
    // 0x8000DEA0: nop

    // 0x8000DEA4: jal         0x8009F1B4
    // 0x8000DEA8: nop

    is_in_adventure_two(rdram, ctx);
        goto after_35;
    // 0x8000DEA8: nop

    after_35:
    // 0x8000DEAC: bne         $v0, $zero, L_8000DF00
    if (ctx->r2 != 0) {
        // 0x8000DEB0: nop
    
            goto L_8000DF00;
    }
    // 0x8000DEB0: nop

    // 0x8000DEB4: jal         0x8006C3DC
    // 0x8000DEB8: nop

    race_is_adventure_2P(rdram, ctx);
        goto after_36;
    // 0x8000DEB8: nop

    after_36:
    // 0x8000DEBC: bne         $v0, $zero, L_8000DF00
    if (ctx->r2 != 0) {
        // 0x8000DEC0: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8000DF00;
    }
    // 0x8000DEC0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000DEC4: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x8000DEC8: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x8000DECC: addiu       $s0, $zero, 0x32
    ctx->r16 = ADD32(0, 0X32);
L_8000DED0:
    // 0x8000DED0: sb          $s0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r16;
    // 0x8000DED4: sb          $s1, 0x1($s6)
    MEM_B(0X1, ctx->r22) = ctx->r17;
    // 0x8000DED8: sh          $zero, 0x2($s6)
    MEM_H(0X2, ctx->r22) = 0;
    // 0x8000DEDC: sh          $zero, 0x4($s6)
    MEM_H(0X4, ctx->r22) = 0;
    // 0x8000DEE0: sh          $zero, 0x6($s6)
    MEM_H(0X6, ctx->r22) = 0;
    // 0x8000DEE4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000DEE8: jal         0x8000EA54
    // 0x8000DEEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_37;
    // 0x8000DEEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_37:
    // 0x8000DEF0: sw          $s2, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r18;
    // 0x8000DEF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000DEF8: bne         $s2, $s3, L_8000DED0
    if (ctx->r18 != ctx->r19) {
        // 0x8000DEFC: sw          $zero, 0x3C($v0)
        MEM_W(0X3C, ctx->r2) = 0;
            goto L_8000DED0;
    }
    // 0x8000DEFC: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
L_8000DF00:
    // 0x8000DF00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DF04: sh          $zero, -0x4D32($at)
    MEM_H(-0X4D32, ctx->r1) = 0;
    // 0x8000DF08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DF0C: sw          $zero, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = 0;
    // 0x8000DF10: jal         0x8009D874
    // 0x8000DF14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_38;
    // 0x8000DF14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_38:
    // 0x8000DF18: lbu         $t9, 0x48($s7)
    ctx->r25 = MEM_BU(ctx->r23, 0X48);
    // 0x8000DF1C: nop

    // 0x8000DF20: bne         $t9, $zero, L_8000E018
    if (ctx->r25 != 0) {
        // 0x8000DF24: lw          $t6, 0x130($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X130);
            goto L_8000E018;
    }
    // 0x8000DF24: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    // 0x8000DF28: jal         0x8009C814
    // 0x8000DF2C: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_39;
    // 0x8000DF2C: nop

    after_39:
    // 0x8000DF30: bne         $v0, $zero, L_8000E014
    if (ctx->r2 != 0) {
        // 0x8000DF34: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_8000E014;
    }
    // 0x8000DF34: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8000DF38: jal         0x8001E2D0
    // 0x8000DF3C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    get_misc_asset(rdram, ctx);
        goto after_40;
    // 0x8000DF3C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_40:
    // 0x8000DF40: lhu         $v1, 0x14($s7)
    ctx->r3 = MEM_HU(ctx->r23, 0X14);
    // 0x8000DF44: nop

    // 0x8000DF48: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x8000DF4C: bne         $t7, $zero, L_8000DF78
    if (ctx->r15 != 0) {
        // 0x8000DF50: andi        $t9, $v1, 0x2
        ctx->r25 = ctx->r3 & 0X2;
            goto L_8000DF78;
    }
    // 0x8000DF50: andi        $t9, $v1, 0x2
    ctx->r25 = ctx->r3 & 0X2;
    // 0x8000DF54: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x8000DF58: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8000DF5C: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x8000DF60: nop

    // 0x8000DF64: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000DF68: bne         $at, $zero, L_8000DF78
    if (ctx->r1 != 0) {
        // 0x8000DF6C: nop
    
            goto L_8000DF78;
    }
    // 0x8000DF6C: nop

    // 0x8000DF70: b           L_8000DFCC
    // 0x8000DF74: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8000DFCC;
    // 0x8000DF74: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8000DF78:
    // 0x8000DF78: bne         $t9, $zero, L_8000DFA4
    if (ctx->r25 != 0) {
        // 0x8000DF7C: andi        $t6, $v1, 0x4
        ctx->r14 = ctx->r3 & 0X4;
            goto L_8000DFA4;
    }
    // 0x8000DF7C: andi        $t6, $v1, 0x4
    ctx->r14 = ctx->r3 & 0X4;
    // 0x8000DF80: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x8000DF84: lb          $t8, 0x1($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1);
    // 0x8000DF88: lh          $t5, 0x0($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X0);
    // 0x8000DF8C: nop

    // 0x8000DF90: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000DF94: bne         $at, $zero, L_8000DFA4
    if (ctx->r1 != 0) {
        // 0x8000DF98: nop
    
            goto L_8000DFA4;
    }
    // 0x8000DF98: nop

    // 0x8000DF9C: b           L_8000DFCC
    // 0x8000DFA0: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
        goto L_8000DFCC;
    // 0x8000DFA0: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_8000DFA4:
    // 0x8000DFA4: bne         $t6, $zero, L_8000DFCC
    if (ctx->r14 != 0) {
        // 0x8000DFA8: nop
    
            goto L_8000DFCC;
    }
    // 0x8000DFA8: nop

    // 0x8000DFAC: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x8000DFB0: lb          $t5, 0x2($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X2);
    // 0x8000DFB4: lh          $t7, 0x0($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X0);
    // 0x8000DFB8: nop

    // 0x8000DFBC: slt         $at, $t7, $t5
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000DFC0: bne         $at, $zero, L_8000DFCC
    if (ctx->r1 != 0) {
        // 0x8000DFC4: nop
    
            goto L_8000DFCC;
    }
    // 0x8000DFC4: nop

    // 0x8000DFC8: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_8000DFCC:
    // 0x8000DFCC: beq         $s2, $zero, L_8000E018
    if (ctx->r18 == 0) {
        // 0x8000DFD0: lw          $t6, 0x130($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X130);
            goto L_8000E018;
    }
    // 0x8000DFD0: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    // 0x8000DFD4: jal         0x80039360
    // 0x8000DFD8: addiu       $a0, $zero, 0x250
    ctx->r4 = ADD32(0, 0X250);
    set_taj_voice_line(rdram, ctx);
        goto after_41;
    // 0x8000DFD8: addiu       $a0, $zero, 0x250
    ctx->r4 = ADD32(0, 0X250);
    after_41:
    // 0x8000DFDC: lhu         $t8, 0x14($s7)
    ctx->r24 = MEM_HU(ctx->r23, 0X14);
    // 0x8000DFE0: addiu       $t6, $s2, 0x1F
    ctx->r14 = ADD32(ctx->r18, 0X1F);
    // 0x8000DFE4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000DFE8: sllv        $t7, $t9, $t6
    ctx->r15 = S32(ctx->r25 << (ctx->r14 & 31));
    // 0x8000DFEC: or          $t5, $t8, $t7
    ctx->r13 = ctx->r24 | ctx->r15;
    // 0x8000DFF0: sh          $t5, 0x14($s7)
    MEM_H(0X14, ctx->r23) = ctx->r13;
    // 0x8000DFF4: jal         0x800521F8
    // 0x8000DFF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_taj_status(rdram, ctx);
        goto after_42;
    // 0x8000DFF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_42:
    // 0x8000DFFC: jal         0x8009D874
    // 0x8000E000: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_43;
    // 0x8000E000: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_43:
    // 0x8000E004: jal         0x8009C6E4
    // 0x8000E008: nop

    get_save_file_index(rdram, ctx);
        goto after_44;
    // 0x8000E008: nop

    after_44:
    // 0x8000E00C: jal         0x8006EE88
    // 0x8000E010: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_45;
    // 0x8000E010: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_45:
L_8000E014:
    // 0x8000E014: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
L_8000E018:
    // 0x8000E018: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000E01C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E020: bltz        $t6, L_8000E038
    if (SIGNED(ctx->r14) < 0) {
        // 0x8000E024: sb          $t9, -0x4D5C($at)
        MEM_B(-0X4D5C, ctx->r1) = ctx->r25;
            goto L_8000E038;
    }
    // 0x8000E024: sb          $t9, -0x4D5C($at)
    MEM_B(-0X4D5C, ctx->r1) = ctx->r25;
    // 0x8000E028: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x8000E02C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8000E030: nop

    // 0x8000E034: sb          $t8, 0x3B($t7)
    MEM_B(0X3B, ctx->r15) = ctx->r24;
L_8000E038:
    // 0x8000E038: jal         0x8000E148
    // 0x8000E03C: nop

    racetype_demo(rdram, ctx);
        goto after_46;
    // 0x8000E03C: nop

    after_46:
    // 0x8000E040: beq         $v0, $zero, L_8000E068
    if (ctx->r2 == 0) {
        // 0x8000E044: nop
    
            goto L_8000E068;
    }
    // 0x8000E044: nop

    // 0x8000E048: jal         0x800724E4
    // 0x8000E04C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    rumble_init(rdram, ctx);
        goto after_47;
    // 0x8000E04C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_47:
    // 0x8000E050: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E054: sw          $zero, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = 0;
    // 0x8000E058: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E05C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8000E060: jal         0x8006BF50
    // 0x8000E064: nop

    level_music_start(rdram, ctx);
        goto after_48;
    // 0x8000E064: nop

    after_48:
L_8000E068:
    // 0x8000E068: jal         0x800712F0
    // 0x8000E06C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_49;
    // 0x8000E06C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_49:
    // 0x8000E070: jal         0x80071380
    // 0x8000E074: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    mempool_free(rdram, ctx);
        goto after_50;
    // 0x8000E074: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_50:
    // 0x8000E078: jal         0x800712F0
    // 0x8000E07C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_51;
    // 0x8000E07C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_51:
L_8000E080:
    // 0x8000E080: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E084: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000E088: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E08C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000E090: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000E094: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000E098: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000E09C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000E0A0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8000E0A4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000E0A8: jr          $ra
    // 0x8000E0AC: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x8000E0AC: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void set_vehicle_id_for_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DD64: jr          $ra
    // 0x8006DD68: sw          $a0, 0x3A9C($at)
    MEM_W(0X3A9C, ctx->r1) = ctx->r4;
    return;
    // 0x8006DD68: sw          $a0, 0x3A9C($at)
    MEM_W(0X3A9C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void obj_init_weapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E60C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E610: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003E614: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003E618: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E61C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003E620: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003E624: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E628: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x8003E62C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003E630: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E634: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003E638: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003E63C: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E640: addiu       $a0, $zero, 0x1E0
    ctx->r4 = ADD32(0, 0X1E0);
    // 0x8003E644: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8003E648: jal         0x8000C8B4
    // 0x8003E64C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    normalise_time(rdram, ctx);
        goto after_0;
    // 0x8003E64C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003E650: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8003E654: nop

    // 0x8003E658: sw          $v0, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->r2;
    // 0x8003E65C: sw          $zero, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = 0;
    // 0x8003E660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E668: jr          $ra
    // 0x8003E66C: nop

    return;
    // 0x8003E66C: nop

;}
RECOMP_FUNC void obj_init_wballoonpop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E5F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003E5F4: jr          $ra
    // 0x8003E5F8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003E5F8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_80027568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800275A8: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x800275AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800275B0: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800275B4: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x800275B8: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800275BC: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x800275C0: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800275C4: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x800275C8: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800275CC: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800275D0: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800275D4: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800275D8: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800275DC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800275E0: jal         0x8001BAA8
    // 0x800275E4: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800275E4: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    after_0:
    // 0x800275E8: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800275EC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800275F0: bne         $t6, $zero, L_80027600
    if (ctx->r14 != 0) {
        // 0x800275F4: nop
    
            goto L_80027600;
    }
    // 0x800275F4: nop

    // 0x800275F8: b           L_800278EC
    // 0x800275FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800278EC;
    // 0x800275FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80027600:
    // 0x80027600: jal         0x80066750
    // 0x80027604: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_1;
    // 0x80027604: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    after_1:
    // 0x80027608: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8002760C: bne         $v0, $zero, L_80027638
    if (ctx->r2 != 0) {
        // 0x80027610: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80027638;
    }
    // 0x80027610: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80027614: lw          $t7, -0x49D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X49D0);
    // 0x80027618: nop

    // 0x8002761C: lh          $v0, 0x36($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X36);
    // 0x80027620: nop

    // 0x80027624: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80027628: beq         $at, $zero, L_80027638
    if (ctx->r1 == 0) {
        // 0x8002762C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80027638;
    }
    // 0x8002762C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80027630: bne         $v0, $at, L_80027640
    if (ctx->r2 != ctx->r1) {
        // 0x80027634: nop
    
            goto L_80027640;
    }
    // 0x80027634: nop

L_80027638:
    // 0x80027638: b           L_800278EC
    // 0x8002763C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800278EC;
    // 0x8002763C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80027640:
    // 0x80027640: jal         0x80066460
    // 0x80027644: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    get_current_viewport(rdram, ctx);
        goto after_2;
    // 0x80027644: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    after_2:
    // 0x80027648: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x8002764C: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80027650: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80027654: blez        $t8, L_8002769C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80027658: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002769C;
    }
    // 0x80027658: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002765C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_80027660:
    // 0x80027660: addu        $t6, $a2, $t9
    ctx->r14 = ADD32(ctx->r6, ctx->r25);
    // 0x80027664: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80027668: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x8002766C: lw          $a0, 0x64($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X64);
    // 0x80027670: nop

    // 0x80027674: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80027678: nop

    // 0x8002767C: bne         $v0, $t7, L_80027690
    if (ctx->r2 != ctx->r15) {
        // 0x80027680: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80027690;
    }
    // 0x80027680: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80027684: lw          $v1, 0xC4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC4);
    // 0x80027688: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x8002768C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80027690:
    // 0x80027690: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80027694: bne         $at, $zero, L_80027660
    if (ctx->r1 != 0) {
        // 0x80027698: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_80027660;
    }
    // 0x80027698: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_8002769C:
    // 0x8002769C: bne         $t3, $zero, L_800276AC
    if (ctx->r11 != 0) {
        // 0x800276A0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800276AC;
    }
    // 0x800276A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800276A4: b           L_800278EC
    // 0x800276A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800278EC;
    // 0x800276A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800276AC:
    // 0x800276AC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800276B0: lw          $a2, -0x49D0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X49D0);
    // 0x800276B4: addiu       $a1, $t3, 0xC
    ctx->r5 = ADD32(ctx->r11, 0XC);
    // 0x800276B8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800276BC: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x800276C0: jal         0x80031170
    // 0x800276C4: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    generate_collision_candidates(rdram, ctx);
        goto after_3;
    // 0x800276C4: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    after_3:
    // 0x800276C8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800276CC: lw          $v1, -0x2708($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2708);
    // 0x800276D0: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800276D4: blez        $v1, L_800278E8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800276D8: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800278E8;
    }
    // 0x800276D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800276DC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800276E0: lw          $t9, -0x2710($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2710);
    // 0x800276E4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800276E8: sll         $t4, $zero, 2
    ctx->r12 = S32(0 << 2);
    // 0x800276EC: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800276F0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800276F4: lw          $ra, 0xE4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XE4);
    // 0x800276F8: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x800276FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80027700: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
L_80027704:
    // 0x80027704: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80027708: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002770C: blez        $a0, L_8002771C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80027710: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8002771C;
    }
    // 0x80027710: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80027714: b           L_800278C8
    // 0x80027718: or          $ra, $a0, $at
    ctx->r31 = ctx->r4 | ctx->r1;
        goto L_800278C8;
    // 0x80027718: or          $ra, $a0, $at
    ctx->r31 = ctx->r4 | ctx->r1;
L_8002771C:
    // 0x8002771C: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x80027720: lw          $t0, 0x18($ra)
    ctx->r8 = MEM_W(ctx->r31, 0X18);
    // 0x80027724: lw          $a1, -0x49D0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X49D0);
    // 0x80027728: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8002772C: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x80027730: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80027734: lwc1        $f28, 0xC($a1)
    ctx->f28.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80027738: lwc1        $f20, 0x4($v1)
    ctx->f20.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8002773C: mul.s       $f4, $f28, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x80027740: lwc1        $f30, 0x10($a1)
    ctx->f30.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80027744: lwc1        $f22, 0x8($v1)
    ctx->f22.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80027748: lwc1        $f0, 0x14($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8002774C: mul.s       $f6, $f20, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x80027750: lwc1        $f24, 0xC($v1)
    ctx->f24.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80027754: lui         $at, 0x402C
    ctx->r1 = S32(0X402C << 16);
    // 0x80027758: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8002775C: mul.s       $f10, $f22, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80027760: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80027764: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80027768: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002776C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80027770: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80027774: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x80027778: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8002777C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80027780: sub.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d - ctx->f10.d;
    // 0x80027784: lwc1        $f8, 0x6424($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6424);
    // 0x80027788: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x8002778C: lwc1        $f9, 0x6420($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6420);
    // 0x80027790: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x80027794: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80027798: nop

    // 0x8002779C: bc1f        L_800278CC
    if (!c1cs) {
        // 0x800277A0: lw          $t9, 0x4C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X4C);
            goto L_800278CC;
    }
    // 0x800277A0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800277A4: lwc1        $f14, 0xC($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800277A8: lwc1        $f16, 0x10($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X10);
    // 0x800277AC: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800277B0: lwc1        $f18, 0x14($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X14);
    // 0x800277B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800277B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800277BC: mul.s       $f4, $f20, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x800277C0: nop

    // 0x800277C4: mul.s       $f8, $f22, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x800277C8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800277CC: lwc1        $f7, 0x6428($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6428);
    // 0x800277D0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800277D4: lwc1        $f6, 0x642C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X642C);
    // 0x800277D8: add.s       $f0, $f10, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x800277DC: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800277E0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800277E4: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x800277E8: nop

    // 0x800277EC: bc1f        L_800278C8
    if (!c1cs) {
        // 0x800277F0: nop
    
            goto L_800278C8;
    }
    // 0x800277F0: nop

    // 0x800277F4: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x800277F8: sub.s       $f20, $f28, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = ctx->f28.fl - ctx->f14.fl;
    // 0x800277FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80027800: sub.s       $f22, $f30, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f30.fl - ctx->f16.fl;
    // 0x80027804: bc1t        L_80027818
    if (c1cs) {
        // 0x80027808: sub.s       $f24, $f8, $f18
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f8.fl - ctx->f18.fl;
            goto L_80027818;
    }
    // 0x80027808: sub.s       $f24, $f8, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8002780C: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80027810: b           L_80027820
    // 0x80027814: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
        goto L_80027820;
    // 0x80027814: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
L_80027818:
    // 0x80027818: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002781C: nop

L_80027820:
    // 0x80027820: mul.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80027824: sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2 << 1);
    // 0x80027828: addu        $a2, $t2, $a1
    ctx->r6 = ADD32(ctx->r10, ctx->r5);
    // 0x8002782C: mul.s       $f6, $f22, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80027830: add.s       $f20, $f14, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x80027834: mul.s       $f8, $f24, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x80027838: add.s       $f22, $f16, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8002783C: add.s       $f24, $f18, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f18.fl + ctx->f8.fl;
L_80027840:
    // 0x80027840: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
    // 0x80027844: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80027848: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x8002784C: beq         $t9, $zero, L_80027860
    if (ctx->r25 == 0) {
        // 0x80027850: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80027860;
    }
    // 0x80027850: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80027854: andi        $t6, $v0, 0x7FFF
    ctx->r14 = ctx->r2 & 0X7FFF;
    // 0x80027858: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8002785C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
L_80027860:
    // 0x80027860: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x80027864: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x80027868: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002786C: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80027870: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80027874: lwc1        $f12, 0x8($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80027878: lwc1        $f14, 0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002787C: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x80027880: mul.s       $f4, $f2, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x80027884: nop

    // 0x80027888: mul.s       $f8, $f12, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x8002788C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80027890: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80027894: add.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80027898: beq         $a0, $zero, L_800278A4
    if (ctx->r4 == 0) {
        // 0x8002789C: mov.s       $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
            goto L_800278A4;
    }
    // 0x8002789C: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
    // 0x800278A0: neg.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
L_800278A4:
    // 0x800278A4: c.lt.s      $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f26.fl < ctx->f16.fl;
    // 0x800278A8: nop

    // 0x800278AC: bc1f        L_800278B8
    if (!c1cs) {
        // 0x800278B0: nop
    
            goto L_800278B8;
    }
    // 0x800278B0: nop

    // 0x800278B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800278B8:
    // 0x800278B8: beq         $at, $zero, L_800278C8
    if (ctx->r1 == 0) {
        // 0x800278BC: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_800278C8;
    }
    // 0x800278BC: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800278C0: beq         $a3, $t1, L_80027840
    if (ctx->r7 == ctx->r9) {
        // 0x800278C4: nop
    
            goto L_80027840;
    }
    // 0x800278C4: nop

L_800278C8:
    // 0x800278C8: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
L_800278CC:
    // 0x800278CC: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x800278D0: slt         $at, $t4, $t9
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800278D4: beq         $at, $zero, L_800278E8
    if (ctx->r1 == 0) {
        // 0x800278D8: addiu       $t5, $t5, 0x4
        ctx->r13 = ADD32(ctx->r13, 0X4);
            goto L_800278E8;
    }
    // 0x800278D8: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x800278DC: beq         $a3, $zero, L_80027704
    if (ctx->r7 == 0) {
        // 0x800278E0: nop
    
            goto L_80027704;
    }
    // 0x800278E0: nop

    // 0x800278E4: sw          $ra, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r31;
L_800278E8:
    // 0x800278E8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800278EC:
    // 0x800278EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800278F0: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800278F4: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800278F8: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800278FC: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80027900: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80027904: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80027908: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002790C: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80027910: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80027914: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80027918: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8002791C: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80027920: jr          $ra
    // 0x80027924: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x80027924: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void gzip_inflate_block(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6E20: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C6E24: lw          $t3, -0x4F6C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4F6C);
    // 0x800C6E28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C6E2C: sw          $zero, -0x4F68($at)
    MEM_W(-0X4F68, ctx->r1) = 0;
    // 0x800C6E30: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C6E34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C6E38: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800C6E3C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C6E40: sltu        $at, $t3, $t0
    ctx->r1 = ctx->r11 < ctx->r8 ? 1 : 0;
    // 0x800C6E44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C6E48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C6E4C: lw          $t4, 0x3CF8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3CF8);
    // 0x800C6E50: beq         $at, $zero, L_800C6E74
    if (ctx->r1 == 0) {
        // 0x800C6E54: lw          $t2, -0x4F70($t2)
        ctx->r10 = MEM_W(ctx->r10, -0X4F70);
            goto L_800C6E74;
    }
    // 0x800C6E54: lw          $t2, -0x4F70($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4F70);
L_800C6E58:
    // 0x800C6E58: lbu         $v0, 0x0($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X0);
    // 0x800C6E5C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C6E60: sllv        $v0, $v0, $t3
    ctx->r2 = S32(ctx->r2 << (ctx->r11 & 31));
    // 0x800C6E64: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x800C6E68: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6E6C: bne         $at, $zero, L_800C6E58
    if (ctx->r1 != 0) {
        // 0x800C6E70: or          $t2, $t2, $v0
        ctx->r10 = ctx->r10 | ctx->r2;
            goto L_800C6E58;
    }
    // 0x800C6E70: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
L_800C6E74:
    // 0x800C6E74: andi        $s0, $t2, 0x1
    ctx->r16 = ctx->r10 & 0X1;
    // 0x800C6E78: srlv        $t2, $t2, $t0
    ctx->r10 = S32(U32(ctx->r10) >> (ctx->r8 & 31));
    // 0x800C6E7C: sub         $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x800C6E80: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800C6E84: sltu        $at, $t3, $t0
    ctx->r1 = ctx->r11 < ctx->r8 ? 1 : 0;
    // 0x800C6E88: beq         $at, $zero, L_800C6EAC
    if (ctx->r1 == 0) {
        // 0x800C6E8C: nop
    
            goto L_800C6EAC;
    }
    // 0x800C6E8C: nop

L_800C6E90:
    // 0x800C6E90: lbu         $v0, 0x0($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X0);
    // 0x800C6E94: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C6E98: sllv        $v0, $v0, $t3
    ctx->r2 = S32(ctx->r2 << (ctx->r11 & 31));
    // 0x800C6E9C: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x800C6EA0: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6EA4: bne         $at, $zero, L_800C6E90
    if (ctx->r1 != 0) {
        // 0x800C6EA8: or          $t2, $t2, $v0
        ctx->r10 = ctx->r10 | ctx->r2;
            goto L_800C6E90;
    }
    // 0x800C6EA8: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
L_800C6EAC:
    // 0x800C6EAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C6EB0: andi        $t1, $t2, 0x3
    ctx->r9 = ctx->r10 & 0X3;
    // 0x800C6EB4: sw          $t4, 0x3CF8($at)
    MEM_W(0X3CF8, ctx->r1) = ctx->r12;
    // 0x800C6EB8: srlv        $t2, $t2, $t0
    ctx->r10 = S32(U32(ctx->r10) >> (ctx->r8 & 31));
    // 0x800C6EBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C6EC0: sw          $t2, -0x4F70($at)
    MEM_W(-0X4F70, ctx->r1) = ctx->r10;
    // 0x800C6EC4: sub         $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x800C6EC8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C6ECC: sw          $t3, -0x4F6C($at)
    MEM_W(-0X4F6C, ctx->r1) = ctx->r11;
    // 0x800C6ED0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C6ED4: beq         $t1, $at, L_800C6F04
    if (ctx->r9 == ctx->r1) {
        // 0x800C6ED8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800C6F04;
    }
    // 0x800C6ED8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C6EDC: beq         $t1, $at, L_800C6EF4
    if (ctx->r9 == ctx->r1) {
        // 0x800C6EE0: nop
    
            goto L_800C6EF4;
    }
    // 0x800C6EE0: nop

    // 0x800C6EE4: jal         0x800C7494
    // 0x800C6EE8: nop

    gzip_inflate_stored(rdram, ctx);
        goto after_0;
    // 0x800C6EE8: nop

    after_0:
    // 0x800C6EEC: j           L_800C6F0C
    // 0x800C6EF0: nop

        goto L_800C6F0C;
    // 0x800C6EF0: nop

L_800C6EF4:
    // 0x800C6EF4: jal         0x800C733C
    // 0x800C6EF8: nop

    gzip_inflate_fixed(rdram, ctx);
        goto after_1;
    // 0x800C6EF8: nop

    after_1:
    // 0x800C6EFC: j           L_800C6F0C
    // 0x800C6F00: nop

        goto L_800C6F0C;
    // 0x800C6F00: nop

L_800C6F04:
    // 0x800C6F04: jal         0x800C6F24
    // 0x800C6F08: nop

    gzip_inflate_dynamic(rdram, ctx);
        goto after_2;
    // 0x800C6F08: nop

    after_2:
L_800C6F0C:
    // 0x800C6F0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6F10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C6F14: sub         $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x800C6F18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C6F1C: jr          $ra
    // 0x800C6F20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C6F20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mtx_world_origin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068648: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006864C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80068650: lw          $t6, 0x129C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X129C);
    // 0x80068654: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80068658: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006865C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068660: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068664: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80068668: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8006866C: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80068670: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068674: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x80068678: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8006867C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80068680: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80068684: jal         0x80070838
    // 0x80068688: nop

    mtxf_from_translation(rdram, ctx);
        goto after_0;
    // 0x80068688: nop

    after_0:
    // 0x8006868C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80068690: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x80068694: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068698: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006869C: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x800686A0: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x800686A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800686A8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800686AC: addiu       $a2, $a2, 0x15E0
    ctx->r6 = ADD32(ctx->r6, 0X15E0);
    // 0x800686B0: jal         0x8006F9A8
    // 0x800686B4: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    mtxf_mul(rdram, ctx);
        goto after_1;
    // 0x800686B4: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    after_1:
    // 0x800686B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800686BC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800686C0: jal         0x8006FAB0
    // 0x800686C4: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    mtxf_to_mtx(rdram, ctx);
        goto after_2;
    // 0x800686C4: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    after_2:
    // 0x800686C8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800686CC: lw          $t1, 0x129C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X129C);
    // 0x800686D0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800686D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800686D8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800686DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800686E0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800686E4: sw          $t0, 0x1308($at)
    MEM_W(0X1308, ctx->r1) = ctx->r8;
    // 0x800686E8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800686EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800686F0: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800686F4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800686F8: lw          $t4, 0x1288($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1288);
    // 0x800686FC: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x80068700: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x80068704: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80068708: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8006870C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80068710: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x80068714: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80068718: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8006871C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068720: addu        $t0, $t1, $at
    ctx->r8 = ADD32(ctx->r9, ctx->r1);
    // 0x80068724: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80068728: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8006872C: nop

    // 0x80068730: addiu       $t3, $t2, 0x40
    ctx->r11 = ADD32(ctx->r10, 0X40);
    // 0x80068734: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80068738: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006873C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068740: jr          $ra
    // 0x80068744: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80068744: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void obj_door_number(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011264: lh          $t6, 0x50($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X50);
    // 0x80011268: nop

    // 0x8001126C: blez        $t6, L_8001135C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80011270: nop
    
            goto L_8001135C;
    }
    // 0x80011270: nop

    // 0x80011274: lw          $v0, 0x64($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X64);
    // 0x80011278: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8001127C: lbu         $v1, 0x10($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X10);
    // 0x80011280: lw          $t0, 0x38($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X38);
    // 0x80011284: div         $zero, $v1, $t2
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r10)));
    // 0x80011288: bne         $t2, $zero, L_80011294
    if (ctx->r10 != 0) {
        // 0x8001128C: nop
    
            goto L_80011294;
    }
    // 0x8001128C: nop

    // 0x80011290: break       7
    do_break(2147553936);
L_80011294:
    // 0x80011294: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80011298: bne         $t2, $at, L_800112AC
    if (ctx->r10 != ctx->r1) {
        // 0x8001129C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800112AC;
    }
    // 0x8001129C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800112A0: bne         $v1, $at, L_800112AC
    if (ctx->r3 != ctx->r1) {
        // 0x800112A4: nop
    
            goto L_800112AC;
    }
    // 0x800112A4: nop

    // 0x800112A8: break       6
    do_break(2147553960);
L_800112AC:
    // 0x800112AC: lh          $t1, 0x28($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X28);
    // 0x800112B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800112B4: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x800112B8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800112BC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800112C0: mflo        $a2
    ctx->r6 = lo;
    // 0x800112C4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800112C8: mfhi        $v1
    ctx->r3 = hi;
    // 0x800112CC: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800112D0: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800112D4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800112D8: blez        $t1, L_8001135C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800112DC: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_8001135C;
    }
    // 0x800112DC: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800112E0:
    // 0x800112E0: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x800112E4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800112E8: and         $t4, $t9, $t2
    ctx->r12 = ctx->r25 & ctx->r10;
    // 0x800112EC: beq         $t4, $zero, L_80011354
    if (ctx->r12 == 0) {
        // 0x800112F0: slt         $at, $a3, $t1
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80011354;
    }
    // 0x800112F0: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800112F4: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x800112F8: nop

    // 0x800112FC: beq         $t3, $a1, L_80011354
    if (ctx->r11 == ctx->r5) {
        // 0x80011300: slt         $at, $a3, $t1
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80011354;
    }
    // 0x80011300: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80011304: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80011308: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x8001130C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80011310: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x80011314: nop

    // 0x80011318: lhu         $t8, 0x12($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X12);
    // 0x8001131C: nop

    // 0x80011320: slti        $at, $t8, 0x901
    ctx->r1 = SIGNED(ctx->r24) < 0X901 ? 1 : 0;
    // 0x80011324: bne         $at, $zero, L_8001133C
    if (ctx->r1 != 0) {
        // 0x80011328: nop
    
            goto L_8001133C;
    }
    // 0x80011328: nop

    // 0x8001132C: sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
    // 0x80011330: lh          $t1, 0x28($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X28);
    // 0x80011334: b           L_80011354
    // 0x80011338: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
        goto L_80011354;
    // 0x80011338: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
L_8001133C:
    // 0x8001133C: bltz        $a2, L_80011354
    if (SIGNED(ctx->r6) < 0) {
        // 0x80011340: slt         $at, $a3, $t1
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80011354;
    }
    // 0x80011340: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80011344: sb          $a2, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r6;
    // 0x80011348: lh          $t1, 0x28($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X28);
    // 0x8001134C: nop

    // 0x80011350: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
L_80011354:
    // 0x80011354: bne         $at, $zero, L_800112E0
    if (ctx->r1 != 0) {
        // 0x80011358: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800112E0;
    }
    // 0x80011358: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_8001135C:
    // 0x8001135C: jr          $ra
    // 0x80011360: nop

    return;
    // 0x80011360: nop

;}
RECOMP_FUNC void bad_int_sqrt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800709EC: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x800709F0: nop

    // 0x800709F4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x800709F8: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x800709FC: jr          $ra
    // 0x80070A00: nop

    return;
    // 0x80070A00: nop

;}
RECOMP_FUNC void obj_init_timetrialghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035E60: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80035E64: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80035E68: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    // 0x80035E6C: jr          $ra
    // 0x80035E70: sw          $t6, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r14;
    return;
    // 0x80035E70: sw          $t6, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void hud_draw_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB52C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800AB530: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AB534: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800AB538: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800AB53C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AB540: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AB544: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AB548: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AB54C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AB550: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AB554: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AB558: lh          $a1, 0x28($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X28);
    // 0x800AB55C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800AB560: blez        $a1, L_800AB6C0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800AB564: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_800AB6C0;
    }
    // 0x800AB564: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800AB568: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800AB56C: addiu       $s2, $s2, 0x72BC
    ctx->r18 = ADD32(ctx->r18, 0X72BC);
    // 0x800AB570: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_800AB574:
    // 0x800AB574: lw          $t6, 0x38($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X38);
    // 0x800AB578: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800AB57C: addu        $v0, $t6, $fp
    ctx->r2 = ADD32(ctx->r14, ctx->r30);
    // 0x800AB580: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x800AB584: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800AB588: andi        $t7, $a3, 0x100
    ctx->r15 = ctx->r7 & 0X100;
    // 0x800AB58C: bne         $t7, $zero, L_800AB6B0
    if (ctx->r15 != 0) {
        // 0x800AB590: nop
    
            goto L_800AB6B0;
    }
    // 0x800AB590: nop

    // 0x800AB594: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x800AB598: lh          $a0, 0x4($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X4);
    // 0x800AB59C: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800AB5A0: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x800AB5A4: lh          $t9, 0x10($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X10);
    // 0x800AB5A8: lw          $t2, 0x4($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X4);
    // 0x800AB5AC: lw          $t4, 0x8($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X8);
    // 0x800AB5B0: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x800AB5B4: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x800AB5B8: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800AB5BC: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x800AB5C0: subu        $s0, $t8, $v1
    ctx->r16 = SUB32(ctx->r24, ctx->r3);
    // 0x800AB5C4: subu        $s4, $t9, $a0
    ctx->r20 = SUB32(ctx->r25, ctx->r4);
    // 0x800AB5C8: addu        $s5, $t2, $t3
    ctx->r21 = ADD32(ctx->r10, ctx->r11);
    // 0x800AB5CC: bne         $a1, $at, L_800AB5DC
    if (ctx->r5 != ctx->r1) {
        // 0x800AB5D0: addu        $t0, $t4, $t5
        ctx->r8 = ADD32(ctx->r12, ctx->r13);
            goto L_800AB5DC;
    }
    // 0x800AB5D0: addu        $t0, $t4, $t5
    ctx->r8 = ADD32(ctx->r12, ctx->r13);
    // 0x800AB5D4: b           L_800AB5F0
    // 0x800AB5D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_800AB5F0;
    // 0x800AB5D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AB5DC:
    // 0x800AB5DC: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800AB5E0: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x800AB5E4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AB5E8: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x800AB5EC: nop

L_800AB5F0:
    // 0x800AB5F0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800AB5F4: and         $a2, $a3, $at
    ctx->r6 = ctx->r7 & ctx->r1;
    // 0x800AB5F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AB5FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800AB600: jal         0x8007B918
    // 0x800AB604: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    material_set_no_tex_offset(rdram, ctx);
        goto after_0;
    // 0x800AB604: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_0:
    // 0x800AB608: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800AB60C: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800AB610: addu        $a0, $s5, $t1
    ctx->r4 = ADD32(ctx->r21, ctx->r9);
    // 0x800AB614: addiu       $t2, $s0, -0x1
    ctx->r10 = ADD32(ctx->r16, -0X1);
    // 0x800AB618: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800AB61C: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800AB620: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800AB624: andi        $t4, $a0, 0x6
    ctx->r12 = ctx->r4 & 0X6;
    // 0x800AB628: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800AB62C: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
    // 0x800AB630: addu        $t2, $t9, $s0
    ctx->r10 = ADD32(ctx->r25, ctx->r16);
    // 0x800AB634: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800AB638: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800AB63C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800AB640: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800AB644: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800AB648: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800AB64C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800AB650: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800AB654: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800AB658: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800AB65C: bne         $s1, $zero, L_800AB668
    if (ctx->r17 != 0) {
        // 0x800AB660: sw          $a0, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r4;
            goto L_800AB668;
    }
    // 0x800AB660: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800AB664: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_800AB668:
    // 0x800AB668: addiu       $t9, $s4, -0x1
    ctx->r25 = ADD32(ctx->r20, -0X1);
    // 0x800AB66C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800AB670: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x800AB674: or          $t3, $t2, $s6
    ctx->r11 = ctx->r10 | ctx->r22;
    // 0x800AB678: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800AB67C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800AB680: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x800AB684: sll         $t8, $t4, 16
    ctx->r24 = S32(ctx->r12 << 16);
    // 0x800AB688: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800AB68C: sll         $t6, $s4, 4
    ctx->r14 = S32(ctx->r20 << 4);
    // 0x800AB690: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800AB694: or          $t5, $t8, $at
    ctx->r13 = ctx->r24 | ctx->r1;
    // 0x800AB698: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x800AB69C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800AB6A0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800AB6A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800AB6A8: lh          $a1, 0x28($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X28);
    // 0x800AB6AC: nop

L_800AB6B0:
    // 0x800AB6B0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800AB6B4: slt         $at, $s7, $a1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AB6B8: bne         $at, $zero, L_800AB574
    if (ctx->r1 != 0) {
        // 0x800AB6BC: addiu       $fp, $fp, 0xC
        ctx->r30 = ADD32(ctx->r30, 0XC);
            goto L_800AB574;
    }
    // 0x800AB6BC: addiu       $fp, $fp, 0xC
    ctx->r30 = ADD32(ctx->r30, 0XC);
L_800AB6C0:
    // 0x800AB6C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800AB6C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AB6C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AB6CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AB6D0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AB6D4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AB6D8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AB6DC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AB6E0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800AB6E4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800AB6E8: jr          $ra
    // 0x800AB6EC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800AB6EC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void write_game_data_to_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800741B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800741B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800741BC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800741C0: jal         0x80073EA4
    // 0x800741C4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    get_game_data_file_size(rdram, ctx);
        goto after_0;
    // 0x800741C4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800741C8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800741CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800741D0: jal         0x80070EDC
    // 0x800741D4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800741D4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x800741D8: lui         $t6, 0x4741
    ctx->r14 = S32(0X4741 << 16);
    // 0x800741DC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800741E0: ori         $t6, $t6, 0x4D44
    ctx->r14 = ctx->r14 | 0X4D44;
    // 0x800741E4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800741E8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800741EC: jal         0x80073540
    // 0x800741F0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800732E8(rdram, ctx);
        goto after_2;
    // 0x800741F0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_2:
    // 0x800741F4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800741F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800741FC: jal         0x80073EB4
    // 0x80074200: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    get_file_extension(rdram, ctx);
        goto after_3;
    // 0x80074200: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80074204: bne         $v0, $zero, L_80074238
    if (ctx->r2 != 0) {
        // 0x80074208: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80074238;
    }
    // 0x80074208: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007420C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80074210: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80074214: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80074218: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007421C: addiu       $a2, $a2, 0x7C10
    ctx->r6 = ADD32(ctx->r6, 0X7C10);
    // 0x80074220: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80074224: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x80074228: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8007422C: jal         0x8007692C
    // 0x80074230: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    write_controller_pak_file(rdram, ctx);
        goto after_4;
    // 0x80074230: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_4:
    // 0x80074234: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80074238:
    // 0x80074238: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007423C: jal         0x80071380
    // 0x80074240: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x80074240: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_5:
    // 0x80074244: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80074248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007424C: beq         $v1, $zero, L_80074268
    if (ctx->r3 == 0) {
        // 0x80074250: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80074268;
    }
    // 0x80074250: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80074254: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80074258: nop

    // 0x8007425C: sll         $t0, $t9, 30
    ctx->r8 = S32(ctx->r25 << 30);
    // 0x80074260: or          $v1, $v1, $t0
    ctx->r3 = ctx->r3 | ctx->r8;
    // 0x80074264: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80074268:
    // 0x80074268: jr          $ra
    // 0x8007426C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8007426C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void light_remove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032BEC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80032BF0: addiu       $t0, $t0, -0x3134
    ctx->r8 = ADD32(ctx->r8, -0X3134);
    // 0x80032BF4: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80032BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80032BFC: blez        $a1, L_80032C38
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80032C00: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80032C38;
    }
    // 0x80032C00: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80032C04: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80032C08: lw          $t6, -0x3140($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3140);
    // 0x80032C0C: sll         $t7, $zero, 2
    ctx->r15 = S32(0 << 2);
    // 0x80032C10: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
L_80032C14:
    // 0x80032C14: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80032C18: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80032C1C: bne         $a0, $a3, L_80032C28
    if (ctx->r4 != ctx->r7) {
        // 0x80032C20: slt         $at, $v1, $a1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80032C28;
    }
    // 0x80032C20: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80032C24: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80032C28:
    // 0x80032C28: beq         $at, $zero, L_80032C38
    if (ctx->r1 == 0) {
        // 0x80032C2C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80032C38;
    }
    // 0x80032C2C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80032C30: beq         $v0, $zero, L_80032C14
    if (ctx->r2 == 0) {
        // 0x80032C34: nop
    
            goto L_80032C14;
    }
    // 0x80032C34: nop

L_80032C38:
    // 0x80032C38: beq         $v0, $zero, L_80032CA4
    if (ctx->r2 == 0) {
        // 0x80032C3C: addiu       $t8, $a1, -0x1
        ctx->r24 = ADD32(ctx->r5, -0X1);
            goto L_80032CA4;
    }
    // 0x80032C3C: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    // 0x80032C40: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80032C44: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80032C48: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80032C4C: beq         $at, $zero, L_80032C8C
    if (ctx->r1 == 0) {
        // 0x80032C50: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_80032C8C;
    }
    // 0x80032C50: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80032C54: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80032C58: addiu       $a3, $a3, -0x3140
    ctx->r7 = ADD32(ctx->r7, -0X3140);
    // 0x80032C5C: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
L_80032C60:
    // 0x80032C60: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80032C64: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80032C68: addu        $a2, $t9, $a0
    ctx->r6 = ADD32(ctx->r25, ctx->r4);
    // 0x80032C6C: lw          $t1, 0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4);
    // 0x80032C70: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80032C74: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80032C78: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80032C7C: nop

    // 0x80032C80: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80032C84: bne         $at, $zero, L_80032C60
    if (ctx->r1 != 0) {
        // 0x80032C88: nop
    
            goto L_80032C60;
    }
    // 0x80032C88: nop

L_80032C8C:
    // 0x80032C8C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80032C90: addiu       $a3, $a3, -0x3140
    ctx->r7 = ADD32(ctx->r7, -0X3140);
    // 0x80032C94: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80032C98: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80032C9C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80032CA0: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
L_80032CA4:
    // 0x80032CA4: jr          $ra
    // 0x80032CA8: nop

    return;
    // 0x80032CA8: nop

;}
RECOMP_FUNC void ghostmenu_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A3C8: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x8009A3CC: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8009A3D0: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8009A3D4: addiu       $s7, $s7, 0x693C
    ctx->r23 = ADD32(ctx->r23, 0X693C);
    // 0x8009A3D8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8009A3DC: sw          $a0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r4;
    // 0x8009A3E0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009A3E4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8009A3E8: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8009A3EC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8009A3F0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8009A3F4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8009A3F8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8009A3FC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8009A400: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8009A404: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8009A408: jal         0x8006816C
    // 0x8009A40C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x8009A40C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_0:
    // 0x8009A410: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8009A414: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8009A418: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009A41C: bne         $t6, $zero, L_8009A430
    if (ctx->r14 != 0) {
        // 0x8009A420: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8009A430;
    }
    // 0x8009A420: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8009A424: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8009A428: b           L_8009A434
    // 0x8009A42C: sw          $t7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r15;
        goto L_8009A434;
    // 0x8009A42C: sw          $t7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r15;
L_8009A430:
    // 0x8009A430: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
L_8009A434:
    // 0x8009A434: lw          $t8, 0x6978($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6978);
    // 0x8009A438: jal         0x800C484C
    // 0x8009A43C: sw          $t8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r24;
    set_text_font(rdram, ctx);
        goto after_1;
    // 0x8009A43C: sw          $t8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r24;
    after_1:
    // 0x8009A440: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009A444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009A448: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009A44C: jal         0x800C492C
    // 0x8009A450: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_2;
    // 0x8009A450: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8009A454: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x8009A458: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009A45C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009A460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009A464: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009A468: jal         0x800C48E4
    // 0x8009A46C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_3;
    // 0x8009A46C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x8009A470: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009A474: lw          $t1, -0x5E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5E0);
    // 0x8009A478: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8009A47C: lw          $a3, 0x148($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X148);
    // 0x8009A480: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009A484: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A488: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x8009A48C: jal         0x800C49A0
    // 0x8009A490: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_4;
    // 0x8009A490: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_4:
    // 0x8009A494: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8009A498: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8009A49C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8009A4A0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009A4A4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009A4A8: jal         0x800C48E4
    // 0x8009A4AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_5;
    // 0x8009A4AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8009A4B0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009A4B4: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009A4B8: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x8009A4BC: lw          $a3, 0x148($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X148);
    // 0x8009A4C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8009A4C4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A4C8: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8009A4CC: jal         0x800C49A0
    // 0x8009A4D0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_6;
    // 0x8009A4D0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_6:
    // 0x8009A4D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009A4D8: lw          $t6, 0x6A74($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A74);
    // 0x8009A4DC: addiu       $s2, $zero, 0x38
    ctx->r18 = ADD32(0, 0X38);
    // 0x8009A4E0: bgtz        $t6, L_8009A534
    if (SIGNED(ctx->r14) > 0) {
        // 0x8009A4E4: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_8009A534;
    }
    // 0x8009A4E4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8009A4E8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009A4EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009A4F0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8009A4F4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009A4F8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009A4FC: jal         0x800C48E4
    // 0x8009A500: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x8009A500: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8009A504: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009A508: lw          $t8, -0x5E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E0);
    // 0x8009A50C: lw          $a2, 0xD0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD0);
    // 0x8009A510: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x8009A514: lw          $a3, 0x14C($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X14C);
    // 0x8009A518: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009A51C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A520: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8009A524: jal         0x800C49A0
    // 0x8009A528: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    draw_text(rdram, ctx);
        goto after_8;
    // 0x8009A528: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    after_8:
    // 0x8009A52C: b           L_8009ACE4
    // 0x8009A530: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8009ACE4;
    // 0x8009A530: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8009A534:
    // 0x8009A534: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009A538: lw          $v0, 0x695C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X695C);
    // 0x8009A53C: sw          $t1, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r9;
    // 0x8009A540: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x8009A544: slti        $at, $t2, 0x100
    ctx->r1 = SIGNED(ctx->r10) < 0X100 ? 1 : 0;
    // 0x8009A548: bne         $at, $zero, L_8009A558
    if (ctx->r1 != 0) {
        // 0x8009A54C: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8009A558;
    }
    // 0x8009A54C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8009A550: addiu       $t3, $zero, 0x1FF
    ctx->r11 = ADD32(0, 0X1FF);
    // 0x8009A554: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
L_8009A558:
    // 0x8009A558: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8009A55C: or          $t4, $v0, $at
    ctx->r12 = ctx->r2 | ctx->r1;
    // 0x8009A560: sw          $t4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r12;
    // 0x8009A564: jal         0x800C484C
    // 0x8009A568: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_text_font(rdram, ctx);
        goto after_9;
    // 0x8009A568: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x8009A56C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8009A570: lw          $v0, 0xE4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE4);
    // 0x8009A574: lw          $t5, 0x6A74($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6A74);
    // 0x8009A578: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009A57C: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8009A580: beq         $at, $zero, L_8009AA30
    if (ctx->r1 == 0) {
        // 0x8009A584: addiu       $t6, $t6, 0x6AA8
        ctx->r14 = ADD32(ctx->r14, 0X6AA8);
            goto L_8009AA30;
    }
    // 0x8009A584: addiu       $t6, $t6, 0x6AA8
    ctx->r14 = ADD32(ctx->r14, 0X6AA8);
    // 0x8009A588: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x8009A58C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8009A590: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009A594: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009A598: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009A59C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009A5A0: addiu       $t3, $t3, 0x6AC0
    ctx->r11 = ADD32(ctx->r11, 0X6AC0);
    // 0x8009A5A4: addiu       $t9, $t9, 0x6AB8
    ctx->r25 = ADD32(ctx->r25, 0X6AB8);
    // 0x8009A5A8: addiu       $t7, $t7, 0x6AB0
    ctx->r15 = ADD32(ctx->r15, 0X6AB0);
    // 0x8009A5AC: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x8009A5B0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8009A5B4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8009A5B8: addu        $t1, $v0, $t9
    ctx->r9 = ADD32(ctx->r2, ctx->r25);
    // 0x8009A5BC: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x8009A5C0: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8009A5C4: addiu       $s1, $s1, 0x1CD4
    ctx->r17 = ADD32(ctx->r17, 0X1CD4);
    // 0x8009A5C8: addiu       $s5, $s5, 0x23A0
    ctx->r21 = ADD32(ctx->r21, 0X23A0);
    // 0x8009A5CC: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    // 0x8009A5D0: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x8009A5D4: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x8009A5D8: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x8009A5DC: addu        $fp, $v0, $t6
    ctx->r30 = ADD32(ctx->r2, ctx->r14);
    // 0x8009A5E0: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x8009A5E4: addiu       $s4, $zero, 0x3F
    ctx->r20 = ADD32(0, 0X3F);
    // 0x8009A5E8: addiu       $s3, $sp, 0x88
    ctx->r19 = ADD32(ctx->r29, 0X88);
L_8009A5EC:
    // 0x8009A5EC: lbu         $a0, 0x0($fp)
    ctx->r4 = MEM_BU(ctx->r30, 0X0);
    // 0x8009A5F0: jal         0x8006B3D0
    // 0x8009A5F4: nop

    leveltable_world(rdram, ctx);
        goto after_10;
    // 0x8009A5F4: nop

    after_10:
    // 0x8009A5F8: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8009A5FC: bltz        $v1, L_8009A610
    if (SIGNED(ctx->r3) < 0) {
        // 0x8009A600: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_8009A610;
    }
    // 0x8009A600: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8009A604: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x8009A608: bne         $at, $zero, L_8009A614
    if (ctx->r1 != 0) {
        // 0x8009A60C: nop
    
            goto L_8009A614;
    }
    // 0x8009A60C: nop

L_8009A610:
    // 0x8009A610: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8009A614:
    // 0x8009A614: lbu         $a0, 0x0($fp)
    ctx->r4 = MEM_BU(ctx->r30, 0X0);
    // 0x8009A618: jal         0x8006C01C
    // 0x8009A61C: sw          $t0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r8;
    level_name(rdram, ctx);
        goto after_11;
    // 0x8009A61C: sw          $t0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r8;
    after_11:
    // 0x8009A620: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8009A624: lw          $t0, 0xEC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XEC);
    // 0x8009A628: beq         $t6, $zero, L_8009A678
    if (ctx->r14 == 0) {
        // 0x8009A62C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8009A678;
    }
    // 0x8009A62C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009A630: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x8009A634: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8009A638: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8009A63C: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
L_8009A640:
    // 0x8009A640: slti        $at, $v1, 0x61
    ctx->r1 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
    // 0x8009A644: bne         $at, $zero, L_8009A65C
    if (ctx->r1 != 0) {
        // 0x8009A648: sb          $a1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r5;
            goto L_8009A65C;
    }
    // 0x8009A648: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x8009A64C: slti        $at, $v1, 0x7B
    ctx->r1 = SIGNED(ctx->r3) < 0X7B ? 1 : 0;
    // 0x8009A650: beq         $at, $zero, L_8009A65C
    if (ctx->r1 == 0) {
        // 0x8009A654: xori        $t7, $v1, 0x20
        ctx->r15 = ctx->r3 ^ 0X20;
            goto L_8009A65C;
    }
    // 0x8009A654: xori        $t7, $v1, 0x20
    ctx->r15 = ctx->r3 ^ 0X20;
    // 0x8009A658: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
L_8009A65C:
    // 0x8009A65C: lbu         $a1, 0x1($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X1);
    // 0x8009A660: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009A664: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8009A668: beq         $a1, $zero, L_8009A678
    if (ctx->r5 == 0) {
        // 0x8009A66C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8009A678;
    }
    // 0x8009A66C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8009A670: bne         $s0, $s4, L_8009A640
    if (ctx->r16 != ctx->r20) {
        // 0x8009A674: andi        $v1, $a1, 0xFF
        ctx->r3 = ctx->r5 & 0XFF;
            goto L_8009A640;
    }
    // 0x8009A674: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
L_8009A678:
    // 0x8009A678: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x8009A67C: addu        $t8, $s3, $s0
    ctx->r24 = ADD32(ctx->r19, ctx->r16);
    // 0x8009A680: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x8009A684: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8009A688: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009A68C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009A690: lui         $at, 0x3F50
    ctx->r1 = S32(0X3F50 << 16);
    // 0x8009A694: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8009A698: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A69C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009A6A0: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8009A6A4: lw          $a1, 0x1C74($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1C74);
    // 0x8009A6A8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8009A6AC: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x8009A6B0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8009A6B4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8009A6B8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8009A6BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009A6C0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A6C4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8009A6C8: jal         0x80079150
    // 0x8009A6CC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_12;
    // 0x8009A6CC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_12:
    // 0x8009A6D0: addiu       $t2, $zero, 0x34
    ctx->r10 = ADD32(0, 0X34);
    // 0x8009A6D4: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x8009A6D8: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x8009A6DC: addiu       $t5, $zero, 0xB0
    ctx->r13 = ADD32(0, 0XB0);
    // 0x8009A6E0: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8009A6E4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8009A6E8: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8009A6EC: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8009A6F0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8009A6F4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009A6F8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A6FC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8009A700: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8009A704: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x8009A708: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x8009A70C: jal         0x800812E0
    // 0x8009A710: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    func_80080E90(rdram, ctx);
        goto after_13;
    // 0x8009A710: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    after_13:
    // 0x8009A714: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009A718: lw          $t8, 0x6A38($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A38);
    // 0x8009A71C: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x8009A720: lw          $v0, 0xD8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD8);
    // 0x8009A724: bne         $t7, $t8, L_8009A75C
    if (ctx->r15 != ctx->r24) {
        // 0x8009A728: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8009A75C;
    }
    // 0x8009A728: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A72C: addiu       $t9, $zero, 0x34
    ctx->r25 = ADD32(0, 0X34);
    // 0x8009A730: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009A734: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8009A738: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8009A73C: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x8009A740: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x8009A744: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x8009A748: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8009A74C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8009A750: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8009A754: jal         0x800812E0
    // 0x8009A758: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80080E90(rdram, ctx);
        goto after_14;
    // 0x8009A758: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_14:
L_8009A75C:
    // 0x8009A75C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009A760: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009A764: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009A768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009A76C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009A770: jal         0x800C48E4
    // 0x8009A774: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_15;
    // 0x8009A774: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_15:
    // 0x8009A778: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
L_8009A77C:
    // 0x8009A77C: addu        $v0, $s5, $t2
    ctx->r2 = ADD32(ctx->r21, ctx->r10);
    // 0x8009A780: lb          $t3, 0x0($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X0);
    // 0x8009A784: lb          $t5, 0x1($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X1);
    // 0x8009A788: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x8009A78C: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x8009A790: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8009A794: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8009A798: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x8009A79C: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x8009A7A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009A7A4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A7A8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8009A7AC: jal         0x800C49A0
    // 0x8009A7B0: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    draw_text(rdram, ctx);
        goto after_16;
    // 0x8009A7B0: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    after_16:
    // 0x8009A7B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009A7B8: bne         $s0, $s6, L_8009A77C
    if (ctx->r16 != ctx->r22) {
        // 0x8009A7BC: sll         $t2, $s0, 1
        ctx->r10 = S32(ctx->r16 << 1);
            goto L_8009A77C;
    }
    // 0x8009A7BC: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    // 0x8009A7C0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009A7C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009A7C8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x8009A7CC: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x8009A7D0: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x8009A7D4: jal         0x800C48E4
    // 0x8009A7D8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_17;
    // 0x8009A7D8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_17:
    // 0x8009A7DC: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    // 0x8009A7E0: lh          $t1, 0x2($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X2);
    // 0x8009A7E4: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8009A7E8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009A7EC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A7F0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8009A7F4: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x8009A7F8: jal         0x800C49A0
    // 0x8009A7FC: addu        $a2, $t1, $s2
    ctx->r6 = ADD32(ctx->r9, ctx->r18);
    draw_text(rdram, ctx);
        goto after_18;
    // 0x8009A7FC: addu        $a2, $t1, $s2
    ctx->r6 = ADD32(ctx->r9, ctx->r18);
    after_18:
    // 0x8009A800: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8009A804: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A808: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8009A80C: lh          $a2, 0x4($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X4);
    // 0x8009A810: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8009A814: lh          $t6, 0x6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X6);
    // 0x8009A818: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x8009A81C: lw          $a1, 0x1070($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1070);
    // 0x8009A820: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009A824: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009A828: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009A82C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009A830: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8009A834: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8009A838: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009A83C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009A840: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A844: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    // 0x8009A848: jal         0x80078F08
    // 0x8009A84C: addu        $a3, $t6, $s2
    ctx->r7 = ADD32(ctx->r14, ctx->r18);
    texrect_draw(rdram, ctx);
        goto after_19;
    // 0x8009A84C: addu        $a3, $t6, $s2
    ctx->r7 = ADD32(ctx->r14, ctx->r18);
    after_19:
    // 0x8009A850: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8009A854: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009A858: lbu         $v0, 0x0($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X0);
    // 0x8009A85C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A860: beq         $v0, $at, L_8009A880
    if (ctx->r2 == ctx->r1) {
        // 0x8009A864: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_8009A880;
    }
    // 0x8009A864: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8009A868: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009A86C: beq         $v0, $at, L_8009A88C
    if (ctx->r2 == ctx->r1) {
        // 0x8009A870: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_8009A88C;
    }
    // 0x8009A870: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A874: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A878: b           L_8009A890
    // 0x8009A87C: addiu       $a1, $a1, 0x9DC
    ctx->r5 = ADD32(ctx->r5, 0X9DC);
        goto L_8009A890;
    // 0x8009A87C: addiu       $a1, $a1, 0x9DC
    ctx->r5 = ADD32(ctx->r5, 0X9DC);
L_8009A880:
    // 0x8009A880: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A884: b           L_8009A890
    // 0x8009A888: addiu       $a1, $a1, 0x9F4
    ctx->r5 = ADD32(ctx->r5, 0X9F4);
        goto L_8009A890;
    // 0x8009A888: addiu       $a1, $a1, 0x9F4
    ctx->r5 = ADD32(ctx->r5, 0X9F4);
L_8009A88C:
    // 0x8009A88C: addiu       $a1, $a1, 0xA0C
    ctx->r5 = ADD32(ctx->r5, 0XA0C);
L_8009A890:
    // 0x8009A890: lh          $t3, 0x8($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X8);
    // 0x8009A894: lh          $t5, 0xA($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XA);
    // 0x8009A898: addiu       $t4, $t3, 0x28
    ctx->r12 = ADD32(ctx->r11, 0X28);
    // 0x8009A89C: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8009A8A0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8009A8A4: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8009A8A8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009A8AC: lui         $at, 0x3F20
    ctx->r1 = S32(0X3F20 << 16);
    // 0x8009A8B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009A8B4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009A8B8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8009A8BC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8009A8C0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8009A8C4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8009A8C8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8009A8CC: jal         0x80079150
    // 0x8009A8D0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_20;
    // 0x8009A8D0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x8009A8D4: jal         0x8007B820
    // 0x8009A8D8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    rendermode_reset(rdram, ctx);
        goto after_21;
    // 0x8009A8D8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_21:
    // 0x8009A8DC: lh          $t8, 0xC($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC);
    // 0x8009A8E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009A8E4: addiu       $t9, $t8, -0x78
    ctx->r25 = ADD32(ctx->r24, -0X78);
    // 0x8009A8E8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8009A8EC: addiu       $v0, $v0, -0x324
    ctx->r2 = ADD32(ctx->r2, -0X324);
    // 0x8009A8F0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009A8F4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8009A8F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009A8FC: swc1        $f8, 0xEC($t1)
    MEM_W(0XEC, ctx->r9) = ctx->f8.u32l;
    // 0x8009A900: lh          $t2, 0xE($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XE);
    // 0x8009A904: lw          $t5, 0xD0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD0);
    // 0x8009A908: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x8009A90C: subu        $t4, $t3, $s2
    ctx->r12 = SUB32(ctx->r11, ctx->r18);
    // 0x8009A910: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8009A914: addiu       $t7, $t6, 0x78
    ctx->r15 = ADD32(ctx->r14, 0X78);
    // 0x8009A918: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8009A91C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8009A920: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009A924: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009A928: swc1        $f16, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = ctx->f16.u32l;
    // 0x8009A92C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8009A930: lwc1        $f18, -0x7500($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7500);
    // 0x8009A934: jal         0x8009CFA4
    // 0x8009A938: swc1        $f18, 0xE8($t9)
    MEM_W(0XE8, ctx->r25) = ctx->f18.u32l;
    menu_element_render(rdram, ctx);
        goto after_22;
    // 0x8009A938: swc1        $f18, 0xE8($t9)
    MEM_W(0XE8, ctx->r25) = ctx->f18.u32l;
    after_22:
    // 0x8009A93C: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x8009A940: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A944: sw          $t1, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r9;
    // 0x8009A948: lh          $t3, 0x12($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X12);
    // 0x8009A94C: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A950: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x8009A954: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8009A958: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    // 0x8009A95C: lh          $a1, 0x10($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X10);
    // 0x8009A960: subu        $t5, $t4, $s2
    ctx->r13 = SUB32(ctx->r12, ctx->r18);
    // 0x8009A964: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x8009A968: addiu       $a2, $a2, 0x77
    ctx->r6 = ADD32(ctx->r6, 0X77);
    // 0x8009A96C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8009A970: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009A974: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8009A978: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8009A97C: jal         0x80081C50
    // 0x8009A980: addiu       $a1, $a1, -0x77
    ctx->r5 = ADD32(ctx->r5, -0X77);
    menu_timestamp_render(rdram, ctx);
        goto after_23;
    // 0x8009A980: addiu       $a1, $a1, -0x77
    ctx->r5 = ADD32(ctx->r5, -0X77);
    after_23:
    // 0x8009A984: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009A988: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A98C: sw          $t7, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r15;
    // 0x8009A990: lh          $t9, 0x12($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X12);
    // 0x8009A994: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A998: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
    // 0x8009A99C: negu        $t1, $t9
    ctx->r9 = SUB32(0, ctx->r25);
    // 0x8009A9A0: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    // 0x8009A9A4: lh          $a1, 0x10($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X10);
    // 0x8009A9A8: subu        $t2, $t1, $s2
    ctx->r10 = SUB32(ctx->r9, ctx->r18);
    // 0x8009A9AC: addiu       $t4, $zero, 0xC0
    ctx->r12 = ADD32(0, 0XC0);
    // 0x8009A9B0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8009A9B4: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x8009A9B8: addiu       $a2, $a2, 0x79
    ctx->r6 = ADD32(ctx->r6, 0X79);
    // 0x8009A9BC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8009A9C0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8009A9C4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8009A9C8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009A9CC: jal         0x80081C50
    // 0x8009A9D0: addiu       $a1, $a1, -0x79
    ctx->r5 = ADD32(ctx->r5, -0X79);
    menu_timestamp_render(rdram, ctx);
        goto after_24;
    // 0x8009A9D0: addiu       $a1, $a1, -0x79
    ctx->r5 = ADD32(ctx->r5, -0X79);
    after_24:
    // 0x8009A9D4: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8009A9D8: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x8009A9DC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8009A9E0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009A9E4: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8009A9E8: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A9EC: lw          $t5, 0xE8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE8);
    // 0x8009A9F0: lw          $t8, 0x6A74($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A74);
    // 0x8009A9F4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8009A9F8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8009A9FC: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x8009AA00: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8009AA04: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8009AA08: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x8009AA0C: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x8009AA10: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x8009AA14: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x8009AA18: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8009AA1C: sw          $t6, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r14;
    // 0x8009AA20: beq         $at, $zero, L_8009AA30
    if (ctx->r1 == 0) {
        // 0x8009AA24: addiu       $s2, $s2, 0x36
        ctx->r18 = ADD32(ctx->r18, 0X36);
            goto L_8009AA30;
    }
    // 0x8009AA24: addiu       $s2, $s2, 0x36
    ctx->r18 = ADD32(ctx->r18, 0X36);
    // 0x8009AA28: bgtz        $t6, L_8009A5EC
    if (SIGNED(ctx->r14) > 0) {
        // 0x8009AA2C: nop
    
            goto L_8009A5EC;
    }
    // 0x8009AA2C: nop

L_8009AA30:
    // 0x8009AA30: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009AA34: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x8009AA38: addiu       $s0, $s0, 0x6980
    ctx->r16 = ADD32(ctx->r16, 0X6980);
    // 0x8009AA3C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8009AA40: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8009AA44: blez        $t2, L_8009ABD4
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8009AA48: sw          $t1, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r9;
            goto L_8009ABD4;
    }
    // 0x8009AA48: sw          $t1, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r9;
    // 0x8009AA4C: jal         0x800C5C30
    // 0x8009AA50: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    clear_dialogue_box_open_flag(rdram, ctx);
        goto after_25;
    // 0x8009AA50: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_25:
    // 0x8009AA54: jal         0x800C59F4
    // 0x8009AA58: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_26;
    // 0x8009AA58: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_26:
    // 0x8009AA5C: addiu       $t3, $zero, 0x8A
    ctx->r11 = ADD32(0, 0X8A);
    // 0x8009AA60: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8009AA64: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AA68: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // 0x8009AA6C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8009AA70: jal         0x800C543C
    // 0x8009AA74: addiu       $a3, $zero, 0xE4
    ctx->r7 = ADD32(0, 0XE4);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_27;
    // 0x8009AA74: addiu       $a3, $zero, 0xE4
    ctx->r7 = ADD32(0, 0XE4);
    after_27:
    // 0x8009AA78: addiu       $t4, $zero, 0xC0
    ctx->r12 = ADD32(0, 0XC0);
    // 0x8009AA7C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8009AA80: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AA84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009AA88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009AA8C: jal         0x800C551C
    // 0x8009AA90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_28;
    // 0x8009AA90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_28:
    // 0x8009AA94: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AA98: jal         0x800C54DC
    // 0x8009AA9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_29;
    // 0x8009AA9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x8009AAA0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AAA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009AAA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009AAAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8009AAB0: jal         0x800C55B0
    // 0x8009AAB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_30;
    // 0x8009AAB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_30:
    // 0x8009AAB8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8009AABC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009AAC0: bne         $t5, $at, L_8009AAF4
    if (ctx->r13 != ctx->r1) {
        // 0x8009AAC4: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8009AAF4;
    }
    // 0x8009AAC4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AAC8: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
    // 0x8009AACC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009AAD0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009AAD4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AAD8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009AADC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009AAE0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009AAE4: jal         0x800C5560
    // 0x8009AAE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    set_current_text_colour(rdram, ctx);
        goto after_31;
    // 0x8009AAE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_31:
    // 0x8009AAEC: b           L_8009AB10
    // 0x8009AAF0: nop

        goto L_8009AB10;
    // 0x8009AAF0: nop

L_8009AAF4:
    // 0x8009AAF4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8009AAF8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8009AAFC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009AB00: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009AB04: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009AB08: jal         0x800C5560
    // 0x8009AB0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_32;
    // 0x8009AB0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_32:
L_8009AB10:
    // 0x8009AB10: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009AB14: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x8009AB18: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009AB1C: lw          $a3, 0x150($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X150);
    // 0x8009AB20: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8009AB24: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009AB28: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009AB2C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AB30: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009AB34: jal         0x800C56C8
    // 0x8009AB38: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    render_dialogue_text(rdram, ctx);
        goto after_33;
    // 0x8009AB38: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_33:
    // 0x8009AB3C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8009AB40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009AB44: bne         $t3, $at, L_8009AB78
    if (ctx->r11 != ctx->r1) {
        // 0x8009AB48: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8009AB78;
    }
    // 0x8009AB48: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AB4C: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x8009AB50: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8009AB54: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8009AB58: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AB5C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009AB60: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009AB64: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009AB68: jal         0x800C5560
    // 0x8009AB6C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    set_current_text_colour(rdram, ctx);
        goto after_34;
    // 0x8009AB6C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_34:
    // 0x8009AB70: b           L_8009AB94
    // 0x8009AB74: nop

        goto L_8009AB94;
    // 0x8009AB74: nop

L_8009AB78:
    // 0x8009AB78: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009AB7C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009AB80: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009AB84: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009AB88: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009AB8C: jal         0x800C5560
    // 0x8009AB90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_35;
    // 0x8009AB90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_35:
L_8009AB94:
    // 0x8009AB94: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009AB98: lw          $t8, -0x5E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E0);
    // 0x8009AB9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009ABA0: lw          $a3, 0x154($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X154);
    // 0x8009ABA4: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x8009ABA8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009ABAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009ABB0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009ABB4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009ABB8: jal         0x800C56C8
    // 0x8009ABBC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    render_dialogue_text(rdram, ctx);
        goto after_36;
    // 0x8009ABBC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    after_36:
    // 0x8009ABC0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009ABC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009ABC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009ABCC: jal         0x800C60B8
    // 0x8009ABD0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_37;
    // 0x8009ABD0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_37:
L_8009ABD4:
    // 0x8009ABD4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009ABD8: lw          $t1, 0x695C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X695C);
    // 0x8009ABDC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009ABE0: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x8009ABE4: beq         $t2, $zero, L_8009ACE0
    if (ctx->r10 == 0) {
        // 0x8009ABE8: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8009ACE0;
    }
    // 0x8009ABE8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009ABEC: lw          $v0, 0x6978($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6978);
    // 0x8009ABF0: lw          $t3, 0x6A74($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6A74);
    // 0x8009ABF4: addiu       $t4, $v0, 0x3
    ctx->r12 = ADD32(ctx->r2, 0X3);
    // 0x8009ABF8: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8009ABFC: beq         $at, $zero, L_8009AC70
    if (ctx->r1 == 0) {
        // 0x8009AC00: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_8009AC70;
    }
    // 0x8009AC00: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009AC04: addiu       $s0, $s0, 0x9BC
    ctx->r16 = ADD32(ctx->r16, 0X9BC);
    // 0x8009AC08: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x8009AC0C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8009AC10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009AC14: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009AC18: addiu       $a2, $zero, 0xA1
    ctx->r6 = ADD32(0, 0XA1);
    // 0x8009AC1C: addiu       $a3, $s2, 0x3
    ctx->r7 = ADD32(ctx->r18, 0X3);
    // 0x8009AC20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8009AC24: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009AC28: jal         0x80078F08
    // 0x8009AC2C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    texrect_draw(rdram, ctx);
        goto after_38;
    // 0x8009AC2C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_38:
    // 0x8009AC30: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009AC34: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009AC38: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8009AC3C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009AC40: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8009AC44: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8009AC48: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009AC4C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009AC50: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009AC54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009AC58: addiu       $a2, $zero, 0x9F
    ctx->r6 = ADD32(0, 0X9F);
    // 0x8009AC5C: jal         0x80078F08
    // 0x8009AC60: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
    texrect_draw(rdram, ctx);
        goto after_39;
    // 0x8009AC60: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
    after_39:
    // 0x8009AC64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009AC68: lw          $v0, 0x6978($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6978);
    // 0x8009AC6C: nop

L_8009AC70:
    // 0x8009AC70: blez        $v0, L_8009ACD8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009AC74: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_8009ACD8;
    }
    // 0x8009AC74: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009AC78: addiu       $s0, $s0, 0x99C
    ctx->r16 = ADD32(ctx->r16, 0X99C);
    // 0x8009AC7C: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x8009AC80: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8009AC84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009AC88: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009AC8C: addiu       $a2, $zero, 0xA1
    ctx->r6 = ADD32(0, 0XA1);
    // 0x8009AC90: addiu       $a3, $zero, 0x36
    ctx->r7 = ADD32(0, 0X36);
    // 0x8009AC94: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8009AC98: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009AC9C: jal         0x80078F08
    // 0x8009ACA0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    texrect_draw(rdram, ctx);
        goto after_40;
    // 0x8009ACA0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_40:
    // 0x8009ACA4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009ACA8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8009ACAC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8009ACB0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8009ACB4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8009ACB8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8009ACBC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8009ACC0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009ACC4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009ACC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009ACCC: addiu       $a2, $zero, 0x9F
    ctx->r6 = ADD32(0, 0X9F);
    // 0x8009ACD0: jal         0x80078F08
    // 0x8009ACD4: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    texrect_draw(rdram, ctx);
        goto after_41;
    // 0x8009ACD4: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    after_41:
L_8009ACD8:
    // 0x8009ACD8: jal         0x8007B820
    // 0x8009ACDC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    rendermode_reset(rdram, ctx);
        goto after_42;
    // 0x8009ACDC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_42:
L_8009ACE0:
    // 0x8009ACE0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8009ACE4:
    // 0x8009ACE4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8009ACE8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8009ACEC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8009ACF0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8009ACF4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8009ACF8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8009ACFC: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8009AD00: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8009AD04: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8009AD08: jr          $ra
    // 0x8009AD0C: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x8009AD0C: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void alCSPSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7DB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7DB8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C7DBC: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800C7DC0: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x800C7DC4: sh          $t7, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r15;
    // 0x800C7DC8: sh          $t6, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r14;
    // 0x800C7DCC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C7DD0: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C7DD4: jal         0x800C970C
    // 0x800C7DD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C7DD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C7DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7DE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7DE4: jr          $ra
    // 0x800C7DE8: nop

    return;
    // 0x800C7DE8: nop

;}
RECOMP_FUNC void dialogue_challenge_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3ABC: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800C3AC0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C3AC4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800C3AC8: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x800C3ACC: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x800C3AD0: addiu       $t9, $zero, 0x7D
    ctx->r25 = ADD32(0, 0X7D);
    // 0x800C3AD4: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800C3AD8: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x800C3ADC: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x800C3AE0: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x800C3AE4: addiu       $t4, $zero, 0x7D
    ctx->r12 = ADD32(0, 0X7D);
    // 0x800C3AE8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800C3AEC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800C3AF0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800C3AF4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800C3AF8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x800C3AFC: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x800C3B00: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800C3B04: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800C3B08: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x800C3B0C: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    // 0x800C3B10: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x800C3B14: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x800C3B18: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x800C3B1C: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800C3B20: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    // 0x800C3B24: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
    // 0x800C3B28: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x800C3B2C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800C3B30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3B34: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800C3B38: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x800C3B3C: jal         0x800C543C
    // 0x800C3B40: addiu       $a3, $zero, 0xB4
    ctx->r7 = ADD32(0, 0XB4);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_0;
    // 0x800C3B40: addiu       $a3, $zero, 0xB4
    ctx->r7 = ADD32(0, 0XB4);
    after_0:
    // 0x800C3B44: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800C3B48: jal         0x800C54DC
    // 0x800C3B4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_dialogue_font(rdram, ctx);
        goto after_1;
    // 0x800C3B4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800C3B50: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x800C3B54: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800C3B58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3B5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C3B60: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800C3B64: jal         0x800C551C
    // 0x800C3B68: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_2;
    // 0x800C3B68: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
    // 0x800C3B6C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800C3B70: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800C3B74: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800C3B78: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800C3B7C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800C3B80: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800C3B84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3B88: jal         0x800C5560
    // 0x800C3B8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    set_current_text_colour(rdram, ctx);
        goto after_3;
    // 0x800C3B8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x800C3B90: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C3B94: lh          $a0, -0x52B2($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X52B2);
    // 0x800C3B98: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800C3B9C: beq         $a0, $zero, L_800C3C2C
    if (ctx->r4 == 0) {
        // 0x800C3BA0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800C3C2C;
    }
    // 0x800C3BA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C3BA4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C3BA8: lw          $v0, -0x52A0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X52A0);
    // 0x800C3BAC: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x800C3BB0: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x800C3BB4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800C3BB8: beq         $s2, $t8, L_800C3C2C
    if (ctx->r18 == ctx->r24) {
        // 0x800C3BBC: andi        $v1, $t8, 0xFF
        ctx->r3 = ctx->r24 & 0XFF;
            goto L_800C3C2C;
    }
    // 0x800C3BBC: andi        $v1, $t8, 0xFF
    ctx->r3 = ctx->r24 & 0XFF;
    // 0x800C3BC0: addiu       $s3, $sp, 0x40
    ctx->r19 = ADD32(ctx->r29, 0X40);
    // 0x800C3BC4: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_800C3BC8:
    // 0x800C3BC8: bne         $at, $zero, L_800C3C04
    if (ctx->r1 != 0) {
        // 0x800C3BCC: slti        $at, $v1, 0xD
        ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
            goto L_800C3C04;
    }
    // 0x800C3BCC: slti        $at, $v1, 0xD
    ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
    // 0x800C3BD0: beq         $at, $zero, L_800C3C04
    if (ctx->r1 == 0) {
        // 0x800C3BD4: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_800C3C04;
    }
    // 0x800C3BD4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800C3BD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C3BDC: jal         0x800C3E0C
    // 0x800C3BE0: sw          $a2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r6;
    func_800C38B4(rdram, ctx);
        goto after_4;
    // 0x800C3BE0: sw          $a2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r6;
    after_4:
    // 0x800C3BE4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C3BE8: lw          $t9, -0x52A0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X52A0);
    // 0x800C3BEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C3BF0: addu        $s0, $t9, $v0
    ctx->r16 = ADD32(ctx->r25, ctx->r2);
    // 0x800C3BF4: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3BF8: lh          $a0, -0x52B2($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X52B2);
    // 0x800C3BFC: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x800C3C00: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800C3C04:
    // 0x800C3C04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C3C08: bne         $v1, $at, L_800C3C14
    if (ctx->r3 != ctx->r1) {
        // 0x800C3C0C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800C3C14;
    }
    // 0x800C3C0C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C3C10: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800C3C14:
    // 0x800C3C14: beq         $a2, $a0, L_800C3C2C
    if (ctx->r6 == ctx->r4) {
        // 0x800C3C18: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C3C2C;
    }
    // 0x800C3C18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C3C1C: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3C20: nop

    // 0x800C3C24: bne         $s2, $v1, L_800C3BC8
    if (ctx->r18 != ctx->r3) {
        // 0x800C3C28: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800C3BC8;
    }
    // 0x800C3C28: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_800C3C2C:
    // 0x800C3C2C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C3C30: lw          $t0, -0x52A0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X52A0);
    // 0x800C3C34: addiu       $s3, $sp, 0x40
    ctx->r19 = ADD32(ctx->r29, 0X40);
    // 0x800C3C38: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800C3C3C: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x800C3C40: nop

    // 0x800C3C44: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800C3C48: bne         $at, $zero, L_800C3C64
    if (ctx->r1 != 0) {
        // 0x800C3C4C: slti        $at, $v1, 0xD
        ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
            goto L_800C3C64;
    }
    // 0x800C3C4C: slti        $at, $v1, 0xD
    ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
    // 0x800C3C50: beq         $at, $zero, L_800C3C64
    if (ctx->r1 == 0) {
        // 0x800C3C54: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800C3C64;
    }
    // 0x800C3C54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C3C58: jal         0x800C3E0C
    // 0x800C3C5C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800C38B4(rdram, ctx);
        goto after_5;
    // 0x800C3C5C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_5:
    // 0x800C3C60: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800C3C64:
    // 0x800C3C64: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800C3C68:
    // 0x800C3C68: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C3C6C: lw          $t2, -0x52A0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X52A0);
    // 0x800C3C70: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800C3C74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3C78: bne         $t3, $zero, L_800C3C8C
    if (ctx->r11 != 0) {
        // 0x800C3C7C: addu        $s0, $t2, $s1
        ctx->r16 = ADD32(ctx->r10, ctx->r17);
            goto L_800C3C8C;
    }
    // 0x800C3C7C: addu        $s0, $t2, $s1
    ctx->r16 = ADD32(ctx->r10, ctx->r17);
    // 0x800C3C80: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800C3C84: b           L_800C3CA4
    // 0x800C3C88: nop

        goto L_800C3CA4;
    // 0x800C3C88: nop

L_800C3C8C:
    // 0x800C3C8C: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800C3C90: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800C3C94: nop

    // 0x800C3C98: subu        $a1, $t4, $t5
    ctx->r5 = SUB32(ctx->r12, ctx->r13);
    // 0x800C3C9C: sra         $t6, $a1, 1
    ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800C3CA0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_800C3CA4:
    // 0x800C3CA4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800C3CA8: lh          $t7, 0x3C04($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X3C04);
    // 0x800C3CAC: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x800C3CB0: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800C3CB4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800C3CB8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C3CBC: jal         0x800C56C8
    // 0x800C3CC0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    render_dialogue_text(rdram, ctx);
        goto after_6;
    // 0x800C3CC0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_6:
    // 0x800C3CC4: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x800C3CC8: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800C3CCC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C3CD0: lw          $t2, -0x52A0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X52A0);
    // 0x800C3CD4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800C3CD8: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x800C3CDC: addu        $s0, $t2, $s1
    ctx->r16 = ADD32(ctx->r10, ctx->r17);
    // 0x800C3CE0: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3CE4: nop

    // 0x800C3CE8: blez        $v1, L_800C3D00
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C3CEC: nop
    
            goto L_800C3D00;
    }
    // 0x800C3CEC: nop

L_800C3CF0:
    // 0x800C3CF0: lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3CF4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C3CF8: bgtz        $v1, L_800C3CF0
    if (SIGNED(ctx->r3) > 0) {
        // 0x800C3CFC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C3CF0;
    }
    // 0x800C3CFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C3D00:
    // 0x800C3D00: bne         $v1, $zero, L_800C3D1C
    if (ctx->r3 != 0) {
        // 0x800C3D04: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800C3D1C;
    }
    // 0x800C3D04: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_800C3D08:
    // 0x800C3D08: lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3D0C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C3D10: beq         $v1, $zero, L_800C3D08
    if (ctx->r3 == 0) {
        // 0x800C3D14: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C3D08;
    }
    // 0x800C3D14: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C3D18: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_800C3D1C:
    // 0x800C3D1C: beq         $at, $zero, L_800C3D2C
    if (ctx->r1 == 0) {
        // 0x800C3D20: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800C3D2C;
    }
    // 0x800C3D20: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800C3D24: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800C3D28: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_800C3D2C:
    // 0x800C3D2C: bne         $at, $zero, L_800C3D48
    if (ctx->r1 != 0) {
        // 0x800C3D30: slti        $at, $v1, 0xD
        ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
            goto L_800C3D48;
    }
    // 0x800C3D30: slti        $at, $v1, 0xD
    ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
    // 0x800C3D34: beq         $at, $zero, L_800C3D48
    if (ctx->r1 == 0) {
        // 0x800C3D38: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800C3D48;
    }
    // 0x800C3D38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C3D3C: jal         0x800C3E0C
    // 0x800C3D40: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800C38B4(rdram, ctx);
        goto after_7;
    // 0x800C3D40: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x800C3D44: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800C3D48:
    // 0x800C3D48: bne         $s2, $zero, L_800C3C68
    if (ctx->r18 != 0) {
        // 0x800C3D4C: nop
    
            goto L_800C3C68;
    }
    // 0x800C3D4C: nop

    // 0x800C3D50: jal         0x8006A794
    // 0x800C3D54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_8;
    // 0x800C3D54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800C3D58: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C3D5C: lb          $t3, -0x52B9($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X52B9);
    // 0x800C3D60: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C3D64: bne         $t3, $zero, L_800C3D70
    if (ctx->r11 != 0) {
        // 0x800C3D68: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_800C3D70;
    }
    // 0x800C3D68: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C3D6C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C3D70:
    // 0x800C3D70: addiu       $s0, $s0, -0x52B6
    ctx->r16 = ADD32(ctx->r16, -0X52B6);
    // 0x800C3D74: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3D78: andi        $t5, $v1, 0x8000
    ctx->r13 = ctx->r3 & 0X8000;
    // 0x800C3D7C: bne         $t4, $zero, L_800C3DEC
    if (ctx->r12 != 0) {
        // 0x800C3D80: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800C3DEC;
    }
    // 0x800C3D80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C3D84: bne         $t5, $zero, L_800C3D98
    if (ctx->r13 != 0) {
        // 0x800C3D88: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800C3D98;
    }
    // 0x800C3D88: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C3D8C: lb          $t6, -0x52BC($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X52BC);
    // 0x800C3D90: nop

    // 0x800C3D94: beq         $t6, $zero, L_800C3DE8
    if (ctx->r14 == 0) {
        // 0x800C3D98: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800C3DE8;
    }
L_800C3D98:
    // 0x800C3D98: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C3D9C: lw          $t7, -0x52A0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X52A0);
    // 0x800C3DA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C3DA4: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800C3DA8: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800C3DAC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C3DB0: bne         $t9, $at, L_800C3DCC
    if (ctx->r25 != ctx->r1) {
        // 0x800C3DB4: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_800C3DCC;
    }
    // 0x800C3DB4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800C3DB8: lh          $t0, -0x52B2($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X52B2);
    // 0x800C3DBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3DC0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C3DC4: b           L_800C3DD8
    // 0x800C3DC8: sh          $t1, -0x52B2($at)
    MEM_H(-0X52B2, ctx->r1) = ctx->r9;
        goto L_800C3DD8;
    // 0x800C3DC8: sh          $t1, -0x52B2($at)
    MEM_H(-0X52B2, ctx->r1) = ctx->r9;
L_800C3DCC:
    // 0x800C3DCC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3DD0: jal         0x8009D4AC
    // 0x800C3DD4: sb          $zero, -0x52B7($at)
    MEM_B(-0X52B7, ctx->r1) = 0;
    dialogue_npc_finish(rdram, ctx);
        goto after_9;
    // 0x800C3DD4: sb          $zero, -0x52B7($at)
    MEM_B(-0X52B7, ctx->r1) = 0;
    after_9:
L_800C3DD8:
    // 0x800C3DD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3DDC: sb          $zero, -0x52BC($at)
    MEM_B(-0X52BC, ctx->r1) = 0;
    // 0x800C3DE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3DE4: sb          $zero, -0x52BA($at)
    MEM_B(-0X52BA, ctx->r1) = 0;
L_800C3DE8:
    // 0x800C3DE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800C3DEC:
    // 0x800C3DEC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x800C3DF0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3DF4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800C3DF8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800C3DFC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800C3E00: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x800C3E04: jr          $ra
    // 0x800C3E08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800C3E08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80060AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060D08: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80060D0C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80060D10: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80060D14: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80060D18: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80060D1C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80060D20: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80060D24: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80060D28: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80060D2C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80060D30: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80060D34: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80060D38: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x80060D3C: lh          $t0, 0x28($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X28);
    // 0x80060D40: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80060D44: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80060D48: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80060D4C: blez        $t0, L_80060E64
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80060D50: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_80060E64;
    }
    // 0x80060D50: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80060D54: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80060D58: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
L_80060D5C:
    // 0x80060D5C: lw          $t6, 0x38($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X38);
    // 0x80060D60: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80060D64: nop

    // 0x80060D68: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80060D6C: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x80060D70: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80060D74: lh          $s2, 0x2($v0)
    ctx->r18 = MEM_H(ctx->r2, 0X2);
    // 0x80060D78: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x80060D7C: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80060D80: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x80060D84: andi        $t1, $t9, 0x200
    ctx->r9 = ctx->r25 & 0X200;
    // 0x80060D88: beq         $t1, $zero, L_80060D98
    if (ctx->r9 == 0) {
        // 0x80060D8C: lw          $t3, 0x70($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X70);
            goto L_80060D98;
    }
    // 0x80060D8C: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80060D90: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x80060D94: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
L_80060D98:
    // 0x80060D98: or          $s4, $v1, $zero
    ctx->r20 = ctx->r3 | 0;
    // 0x80060D9C: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80060DA0: beq         $at, $zero, L_80060E48
    if (ctx->r1 == 0) {
        // 0x80060DA4: lw          $t6, 0x74($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X74);
            goto L_80060E48;
    }
    // 0x80060DA4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80060DA8:
    // 0x80060DA8: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80060DAC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80060DB0: beq         $s4, $t4, L_80060E2C
    if (ctx->r20 == ctx->r12) {
        // 0x80060DB4: addiu       $s0, $s1, 0x1
        ctx->r16 = ADD32(ctx->r17, 0X1);
            goto L_80060E2C;
    }
L_80060DB4:
    // 0x80060DB4: addiu       $s0, $s1, 0x1
    ctx->r16 = ADD32(ctx->r17, 0X1);
    // 0x80060DB8: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80060DBC: bne         $at, $zero, L_80060DC8
    if (ctx->r1 != 0) {
        // 0x80060DC0: or          $t0, $s0, $zero
        ctx->r8 = ctx->r16 | 0;
            goto L_80060DC8;
    }
    // 0x80060DC0: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x80060DC4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80060DC8:
    // 0x80060DC8: lw          $t5, 0x8($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X8);
    // 0x80060DCC: sll         $t6, $s4, 4
    ctx->r14 = S32(ctx->r20 << 4);
    // 0x80060DD0: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x80060DD4: addu        $t9, $v0, $t0
    ctx->r25 = ADD32(ctx->r2, ctx->r8);
    // 0x80060DD8: lbu         $t1, 0x1($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X1);
    // 0x80060DDC: addu        $t7, $v0, $s1
    ctx->r15 = ADD32(ctx->r2, ctx->r17);
    // 0x80060DE0: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x80060DE4: lw          $a0, 0x4($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4);
    // 0x80060DE8: addu        $v1, $t1, $s2
    ctx->r3 = ADD32(ctx->r9, ctx->r18);
    // 0x80060DEC: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80060DF0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80060DF4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80060DF8: jal         0x80060E98
    // 0x80060DFC: addu        $a3, $t8, $s2
    ctx->r7 = ADD32(ctx->r24, ctx->r18);
    func_80060C58(rdram, ctx);
        goto after_0;
    // 0x80060DFC: addu        $a3, $t8, $s2
    ctx->r7 = ADD32(ctx->r24, ctx->r18);
    after_0:
    // 0x80060E00: beq         $v0, $zero, L_80060E24
    if (ctx->r2 == 0) {
        // 0x80060E04: nop
    
            goto L_80060E24;
    }
    // 0x80060E04: nop

    // 0x80060E08: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x80060E0C: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x80060E10: sw          $s1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r17;
    // 0x80060E14: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x80060E18: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x80060E1C: b           L_80060E68
    // 0x80060E20: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
        goto L_80060E68;
    // 0x80060E20: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_80060E24:
    // 0x80060E24: bne         $s0, $s7, L_80060DB4
    if (ctx->r16 != ctx->r23) {
        // 0x80060E28: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80060DB4;
    }
    // 0x80060E28: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_80060E2C:
    // 0x80060E2C: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x80060E30: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80060E34: bne         $s4, $t5, L_80060DA8
    if (ctx->r20 != ctx->r13) {
        // 0x80060E38: addiu       $fp, $fp, 0x1
        ctx->r30 = ADD32(ctx->r30, 0X1);
            goto L_80060DA8;
    }
    // 0x80060E38: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80060E3C: lh          $t0, 0x28($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X28);
    // 0x80060E40: nop

    // 0x80060E44: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80060E48:
    // 0x80060E48: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80060E4C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80060E50: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80060E54: addiu       $t9, $t8, 0xC
    ctx->r25 = ADD32(ctx->r24, 0XC);
    // 0x80060E58: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x80060E5C: bne         $at, $zero, L_80060D5C
    if (ctx->r1 != 0) {
        // 0x80060E60: sw          $t7, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r15;
            goto L_80060D5C;
    }
    // 0x80060E60: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
L_80060E64:
    // 0x80060E64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80060E68:
    // 0x80060E68: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80060E6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80060E70: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80060E74: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80060E78: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80060E7C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80060E80: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80060E84: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80060E88: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80060E8C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80060E90: jr          $ra
    // 0x80060E94: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80060E94: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
