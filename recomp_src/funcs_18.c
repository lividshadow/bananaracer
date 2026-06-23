#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void tex_cache_asset_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CCB0: bltz        $a0, L_8007CCCC
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007CCB4: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8007CCCC;
    }
    // 0x8007CCB4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007CCB8: lw          $t6, 0x68D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68D0);
    // 0x8007CCBC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007CCC0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007CCC4: bne         $at, $zero, L_8007CCD4
    if (ctx->r1 != 0) {
        // 0x8007CCC8: nop
    
            goto L_8007CCD4;
    }
    // 0x8007CCC8: nop

L_8007CCCC:
    // 0x8007CCCC: jr          $ra
    // 0x8007CCD0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8007CCD0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007CCD4:
    // 0x8007CCD4: lw          $t7, 0x68C8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X68C8);
    // 0x8007CCD8: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8007CCDC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007CCE0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8007CCE4: nop

    // 0x8007CCE8: jr          $ra
    // 0x8007CCEC: nop

    return;
    // 0x8007CCEC: nop

;}
RECOMP_FUNC void screenimage_draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FB64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007FB68: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007FB6C: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8007FB70: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8007FB74: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8007FB78: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8007FB7C: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8007FB80: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8007FB84: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8007FB88: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8007FB8C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8007FB90: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FB94: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007FB98: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007FB9C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007FBA0: addiu       $t8, $t8, -0x640
    ctx->r24 = ADD32(ctx->r24, -0X640);
    // 0x8007FBA4: lui         $t7, 0x702
    ctx->r15 = S32(0X702 << 16);
    // 0x8007FBA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007FBAC: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x8007FBB0: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8007FBB4: lui         $s1, 0x708
    ctx->r17 = S32(0X708 << 16);
    // 0x8007FBB8: lui         $s4, 0x777
    ctx->r20 = S32(0X777 << 16);
    // 0x8007FBBC: lui         $s6, 0xF510
    ctx->r22 = S32(0XF510 << 16);
    // 0x8007FBC0: lui         $s7, 0x8
    ctx->r23 = S32(0X8 << 16);
    // 0x8007FBC4: lui         $ra, 0x4F
    ctx->r31 = S32(0X4F << 16);
    // 0x8007FBC8: addiu       $s0, $a1, 0x10
    ctx->r16 = ADD32(ctx->r5, 0X10);
    // 0x8007FBCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8007FBD0: ori         $ra, $ra, 0xC014
    ctx->r31 = ctx->r31 | 0XC014;
    // 0x8007FBD4: ori         $s7, $s7, 0x200
    ctx->r23 = ctx->r23 | 0X200;
    // 0x8007FBD8: ori         $s6, $s6, 0xA000
    ctx->r22 = ctx->r22 | 0XA000;
    // 0x8007FBDC: ori         $s4, $s4, 0xF000
    ctx->r20 = ctx->r20 | 0XF000;
    // 0x8007FBE0: ori         $s1, $s1, 0x200
    ctx->r17 = ctx->r17 | 0X200;
    // 0x8007FBE4: lui         $s2, 0xE600
    ctx->r18 = S32(0XE600 << 16);
    // 0x8007FBE8: lui         $s3, 0xF300
    ctx->r19 = S32(0XF300 << 16);
    // 0x8007FBEC: lui         $s5, 0xE700
    ctx->r21 = S32(0XE700 << 16);
    // 0x8007FBF0: lui         $fp, 0xF200
    ctx->r30 = S32(0XF200 << 16);
    // 0x8007FBF4: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x8007FBF8: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8007FBFC: lui         $t3, 0xFD10
    ctx->r11 = S32(0XFD10 << 16);
    // 0x8007FC00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007FC04: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_8007FC08:
    // 0x8007FC08: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FC0C: addu        $t7, $s0, $t4
    ctx->r15 = ADD32(ctx->r16, ctx->r12);
    // 0x8007FC10: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007FC14: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007FC18: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007FC1C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8007FC20: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FC24: addiu       $t2, $a3, 0x6
    ctx->r10 = ADD32(ctx->r7, 0X6);
    // 0x8007FC28: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007FC2C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007FC30: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8007FC34: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8007FC38: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FC3C: lui         $at, 0xE450
    ctx->r1 = S32(0XE450 << 16);
    // 0x8007FC40: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007FC44: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007FC48: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007FC4C: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8007FC50: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FC54: addiu       $s0, $s0, 0xF00
    ctx->r16 = ADD32(ctx->r16, 0XF00);
    // 0x8007FC58: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007FC5C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007FC60: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x8007FC64: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8007FC68: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FC6C: nop

    // 0x8007FC70: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007FC74: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007FC78: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007FC7C: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8007FC80: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FC84: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x8007FC88: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007FC8C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007FC90: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x8007FC94: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8007FC98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FC9C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8007FCA0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007FCA4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007FCA8: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x8007FCAC: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x8007FCB0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FCB4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8007FCB8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007FCBC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007FCC0: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8007FCC4: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8007FCC8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007FCCC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007FCD0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FCD4: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x8007FCD8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007FCDC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007FCE0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007FCE4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007FCE8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007FCEC: lui         $t8, 0x1000
    ctx->r24 = S32(0X1000 << 16);
    // 0x8007FCF0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007FCF4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007FCF8: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x8007FCFC: lui         $t7, 0xB200
    ctx->r15 = S32(0XB200 << 16);
    // 0x8007FD00: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x8007FD04: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x8007FD08: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007FD0C: bne         $t2, $at, L_8007FC08
    if (ctx->r10 != ctx->r1) {
        // 0x8007FD10: sw          $t8, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r24;
            goto L_8007FC08;
    }
    // 0x8007FD10: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007FD14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007FD18: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8007FD1C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8007FD20: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8007FD24: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8007FD28: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8007FD2C: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8007FD30: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8007FD34: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8007FD38: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8007FD3C: jr          $ra
    // 0x8007FD40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007FD40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void rspUnknown2Start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void sndp_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000488C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80004890: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x80004894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004898: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x8000489C: beq         $a0, $zero, L_800048C8
    if (ctx->r4 == 0) {
        // 0x800048A0: sw          $a0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r4;
            goto L_800048C8;
    }
    // 0x800048A0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x800048A4: lbu         $t7, 0x3E($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X3E);
    // 0x800048A8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800048AC: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x800048B0: sb          $t8, 0x3E($a0)
    MEM_B(0X3E, ctx->r4) = ctx->r24;
    // 0x800048B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800048B8: lw          $a0, -0x33D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33D4);
    // 0x800048BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800048C0: jal         0x800C970C
    // 0x800048C4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800048C4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_0:
L_800048C8:
    // 0x800048C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800048CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800048D0: jr          $ra
    // 0x800048D4: nop

    return;
    // 0x800048D4: nop

;}
RECOMP_FUNC void func_8001C6C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C6F8: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8001C6FC: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8001C700: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8001C704: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8001C708: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8001C70C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8001C710: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x8001C714: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x8001C718: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8001C71C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8001C720: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8001C724: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x8001C728: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x8001C72C: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8001C730: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x8001C734: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8001C738: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x8001C73C: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8001C740: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x8001C744: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8001C748: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8001C74C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001C750: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8001C754: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x8001C758: sw          $a2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r6;
    // 0x8001C75C: bne         $t6, $zero, L_8001C784
    if (ctx->r14 != 0) {
        // 0x8001C760: sw          $a3, 0xF4($sp)
        MEM_W(0XF4, ctx->r29) = ctx->r7;
            goto L_8001C784;
    }
    // 0x8001C760: sw          $a3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r7;
    // 0x8001C764: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C768: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001C76C: lwc1        $f9, 0x5BD8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5BD8);
    // 0x8001C770: lwc1        $f8, 0x5BDC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5BDC);
    // 0x8001C774: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001C778: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8001C77C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8001C780: swc1        $f16, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f16.u32l;
L_8001C784:
    // 0x8001C784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001C788: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001C78C: addiu       $s5, $sp, 0xAC
    ctx->r21 = ADD32(ctx->r29, 0XAC);
    // 0x8001C790: addiu       $s4, $sp, 0xC0
    ctx->r20 = ADD32(ctx->r29, 0XC0);
    // 0x8001C794: addiu       $s3, $sp, 0xD4
    ctx->r19 = ADD32(ctx->r29, 0XD4);
    // 0x8001C798: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x8001C79C: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
L_8001C7A0:
    // 0x8001C7A0: lbu         $a0, 0xC($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0XC);
    // 0x8001C7A4: nop

    // 0x8001C7A8: bne         $s0, $a0, L_8001C7BC
    if (ctx->r16 != ctx->r4) {
        // 0x8001C7AC: nop
    
            goto L_8001C7BC;
    }
    // 0x8001C7AC: nop

    // 0x8001C7B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001C7B4: b           L_8001CC2C
    // 0x8001C7B8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8001CC2C;
    // 0x8001C7B8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8001C7BC:
    // 0x8001C7BC: sw          $a1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r5;
    // 0x8001C7C0: jal         0x8001D248
    // 0x8001C7C4: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    ainode_get(rdram, ctx);
        goto after_0;
    // 0x8001C7C4: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001C7C8: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x8001C7CC: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8001C7D0: bne         $v0, $zero, L_8001C7E4
    if (ctx->r2 != 0) {
        // 0x8001C7D4: sll         $v1, $a1, 2
        ctx->r3 = S32(ctx->r5 << 2);
            goto L_8001C7E4;
    }
    // 0x8001C7D4: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8001C7D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001C7DC: b           L_8001CC2C
    // 0x8001C7E0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8001CC2C;
    // 0x8001C7E0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8001C7E4:
    // 0x8001C7E4: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001C7E8: addu        $t7, $s3, $v1
    ctx->r15 = ADD32(ctx->r19, ctx->r3);
    // 0x8001C7EC: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x8001C7F0: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001C7F4: addu        $t8, $s4, $v1
    ctx->r24 = ADD32(ctx->r20, ctx->r3);
    // 0x8001C7F8: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x8001C7FC: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001C800: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001C804: addu        $t9, $s5, $v1
    ctx->r25 = ADD32(ctx->r21, ctx->r3);
    // 0x8001C808: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001C80C: bne         $a1, $s1, L_8001C7A0
    if (ctx->r5 != ctx->r17) {
        // 0x8001C810: swc1        $f6, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
            goto L_8001C7A0;
    }
    // 0x8001C810: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x8001C814: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x8001C818: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001C81C: jal         0x80022574
    // 0x8001C820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_1;
    // 0x8001C820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8001C824: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x8001C828: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x8001C82C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001C830: jal         0x80022574
    // 0x8001C834: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_2;
    // 0x8001C834: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8001C838: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x8001C83C: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x8001C840: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001C844: jal         0x80022574
    // 0x8001C848: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_3;
    // 0x8001C848: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8001C84C: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    // 0x8001C850: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8001C854: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001C858: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x8001C85C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8001C860: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C864: bc1f        L_8001C878
    if (!c1cs) {
        // 0x8001C868: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8001C878;
    }
    // 0x8001C868: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C86C: lwc1        $f16, 0x5BE0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5BE0);
    // 0x8001C870: nop

    // 0x8001C874: swc1        $f16, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f16.u32l;
L_8001C878:
    // 0x8001C878: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001C87C: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x8001C880: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001C884:
    // 0x8001C884: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8001C888: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001C88C: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8001C890: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8001C894: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001C898: add.s       $f20, $f8, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001C89C: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x8001C8A0: c.le.d      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.d <= ctx->f0.d;
    // 0x8001C8A4: nop

    // 0x8001C8A8: bc1f        L_8001C8BC
    if (!c1cs) {
        // 0x8001C8AC: nop
    
            goto L_8001C8BC;
    }
    // 0x8001C8AC: nop

    // 0x8001C8B0: sub.d       $f10, $f0, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f28.d); 
    ctx->f10.d = ctx->f0.d - ctx->f28.d;
    // 0x8001C8B4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8001C8B8: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
L_8001C8BC:
    // 0x8001C8BC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001C8C0: jal         0x80022574
    // 0x8001C8C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_4;
    // 0x8001C8C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8001C8C8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001C8CC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8001C8D0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001C8D4: jal         0x80022574
    // 0x8001C8D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_5;
    // 0x8001C8D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x8001C8DC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001C8E0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8001C8E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001C8E8: jal         0x80022574
    // 0x8001C8EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_6;
    // 0x8001C8EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x8001C8F0: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8001C8F4: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001C8F8: sub.s       $f24, $f24, $f30
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f30.fl;
    // 0x8001C8FC: sub.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f16.fl;
    // 0x8001C900: bne         $s0, $zero, L_8001C95C
    if (ctx->r16 != 0) {
        // 0x8001C904: sub.s       $f26, $f0, $f18
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = ctx->f0.fl - ctx->f18.fl;
            goto L_8001C95C;
    }
    // 0x8001C904: sub.s       $f26, $f0, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8001C908: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8001C90C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C910: mul.s       $f8, $f24, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8001C914: nop

    // 0x8001C918: mul.s       $f10, $f26, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8001C91C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001C920: jal         0x800CA030
    // 0x8001C924: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x8001C924: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_7:
    // 0x8001C928: lwc1        $f16, 0xF0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001C92C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001C930: div.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8001C934: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8001C938: c.eq.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl == ctx->f2.fl;
    // 0x8001C93C: nop

    // 0x8001C940: bc1t        L_8001C95C
    if (c1cs) {
        // 0x8001C944: nop
    
            goto L_8001C95C;
    }
    // 0x8001C944: nop

    // 0x8001C948: div.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001C94C: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8001C950: nop

    // 0x8001C954: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001C958: swc1        $f10, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f10.u32l;
L_8001C95C:
    // 0x8001C95C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001C960: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001C964: bne         $s0, $at, L_8001C884
    if (ctx->r16 != ctx->r1) {
        // 0x8001C968: nop
    
            goto L_8001C884;
    }
    // 0x8001C968: nop

    // 0x8001C96C: lw          $v0, 0xEC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XEC);
    // 0x8001C970: swc1        $f20, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f20.u32l;
    // 0x8001C974: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8001C978: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001C97C: add.s       $f18, $f22, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x8001C980: add.s       $f30, $f24, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f30.fl = ctx->f24.fl + ctx->f30.fl;
    // 0x8001C984: swc1        $f18, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
    // 0x8001C988: add.s       $f4, $f26, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f26.fl + ctx->f8.fl;
    // 0x8001C98C: swc1        $f30, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f30.u32l;
    // 0x8001C990: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    // 0x8001C994: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8001C998: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001C99C: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001C9A0: sub.s       $f22, $f6, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8001C9A4: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001C9A8: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8001C9AC: sub.s       $f24, $f30, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = ctx->f30.fl - ctx->f16.fl;
    // 0x8001C9B0: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001C9B4: swc1        $f22, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f22.u32l;
    // 0x8001C9B8: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8001C9BC: sub.s       $f26, $f18, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8001C9C0: swc1        $f26, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f26.u32l;
    // 0x8001C9C4: mul.s       $f16, $f26, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8001C9C8: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001C9CC: mov.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
    // 0x8001C9D0: jal         0x800CA030
    // 0x8001C9D4: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8001C9D4: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_8:
    // 0x8001C9D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001C9DC: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8001C9E0: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x8001C9E4: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8001C9E8: bc1t        L_8001CA20
    if (c1cs) {
        // 0x8001C9EC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8001CA20;
    }
    // 0x8001C9EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C9F0: lwc1        $f9, 0x5BE8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5BE8);
    // 0x8001C9F4: lwc1        $f8, 0x5BEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5BEC);
    // 0x8001C9F8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8001C9FC: nop

    // 0x8001CA00: div.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f4.d);
    // 0x8001CA04: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x8001CA08: mul.s       $f22, $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x8001CA0C: nop

    // 0x8001CA10: mul.s       $f24, $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x8001CA14: nop

    // 0x8001CA18: mul.s       $f26, $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x8001CA1C: nop

L_8001CA20:
    // 0x8001CA20: mul.s       $f18, $f30, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x8001CA24: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001CA28: nop

    // 0x8001CA2C: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8001CA30: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001CA34: jal         0x800CA030
    // 0x8001CA38: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x8001CA38: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_9:
    // 0x8001CA3C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8001CA40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001CA44: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8001CA48: div.s       $f20, $f0, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8001CA4C: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x8001CA50: nop

    // 0x8001CA54: bc1f        L_8001CA60
    if (!c1cs) {
        // 0x8001CA58: nop
    
            goto L_8001CA60;
    }
    // 0x8001CA58: nop

    // 0x8001CA5C: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
L_8001CA60:
    // 0x8001CA60: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x8001CA64: c.le.d      $f28, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f28.d <= ctx->f18.d;
    // 0x8001CA68: nop

    // 0x8001CA6C: bc1f        L_8001CB60
    if (!c1cs) {
        // 0x8001CA70: lw          $t3, 0xEC($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XEC);
            goto L_8001CB60;
    }
    // 0x8001CA70: lw          $t3, 0xEC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CA74: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x8001CA78: jal         0x80070990
    // 0x8001CA7C: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    arctan2_f(rdram, ctx);
        goto after_10;
    // 0x8001CA7C: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_10:
    // 0x8001CA80: lw          $t0, 0xEC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CA84: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x8001CA88: lh          $v1, 0x0($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X0);
    // 0x8001CA8C: ori         $s4, $zero, 0x8001
    ctx->r20 = 0 | 0X8001;
    // 0x8001CA90: andi        $t1, $v1, 0xFFFF
    ctx->r9 = ctx->r3 & 0XFFFF;
    // 0x8001CA94: subu        $s0, $v0, $t1
    ctx->r16 = SUB32(ctx->r2, ctx->r9);
    // 0x8001CA98: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
    // 0x8001CA9C: slt         $at, $s0, $s4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8001CAA0: bne         $at, $zero, L_8001CAB0
    if (ctx->r1 != 0) {
        // 0x8001CAA4: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8001CAB0;
    }
    // 0x8001CAA4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8001CAA8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8001CAAC: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
L_8001CAB0:
    // 0x8001CAB0: slti        $at, $s0, -0x8000
    ctx->r1 = SIGNED(ctx->r16) < -0X8000 ? 1 : 0;
    // 0x8001CAB4: beq         $at, $zero, L_8001CAC0
    if (ctx->r1 == 0) {
        // 0x8001CAB8: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8001CAC0;
    }
    // 0x8001CAB8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001CABC: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
L_8001CAC0:
    // 0x8001CAC0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8001CAC4: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001CAC8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8001CACC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001CAD0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001CAD4: lw          $t6, 0xEC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CAD8: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001CADC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8001CAE0: mfc1        $s3, $f8
    ctx->r19 = (int32_t)ctx->f8.u32l;
    // 0x8001CAE4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8001CAE8: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001CAEC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8001CAF0: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x8001CAF4: mflo        $t3
    ctx->r11 = lo;
    // 0x8001CAF8: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x8001CAFC: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x8001CB00: jal         0x80070990
    // 0x8001CB04: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    arctan2_f(rdram, ctx);
        goto after_11;
    // 0x8001CB04: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    after_11:
    // 0x8001CB08: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CB0C: nop

    // 0x8001CB10: lh          $v1, 0x2($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X2);
    // 0x8001CB14: nop

    // 0x8001CB18: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x8001CB1C: subu        $s0, $v0, $t8
    ctx->r16 = SUB32(ctx->r2, ctx->r24);
    // 0x8001CB20: slt         $at, $s0, $s4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8001CB24: bne         $at, $zero, L_8001CB34
    if (ctx->r1 != 0) {
        // 0x8001CB28: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8001CB34;
    }
    // 0x8001CB28: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8001CB2C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8001CB30: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
L_8001CB34:
    // 0x8001CB34: slti        $at, $s0, -0x8000
    ctx->r1 = SIGNED(ctx->r16) < -0X8000 ? 1 : 0;
    // 0x8001CB38: beq         $at, $zero, L_8001CB44
    if (ctx->r1 == 0) {
        // 0x8001CB3C: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8001CB44;
    }
    // 0x8001CB3C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001CB40: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
L_8001CB44:
    // 0x8001CB44: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001CB48: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CB4C: mflo        $t9
    ctx->r25 = lo;
    // 0x8001CB50: sra         $t0, $t9, 4
    ctx->r8 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8001CB54: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x8001CB58: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x8001CB5C: lw          $t3, 0xEC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XEC);
L_8001CB60:
    // 0x8001CB60: ori         $s0, $zero, 0x8000
    ctx->r16 = 0 | 0X8000;
    // 0x8001CB64: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8001CB68: sh          $zero, 0x4($t3)
    MEM_H(0X4, ctx->r11) = 0;
    // 0x8001CB6C: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    // 0x8001CB70: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x8001CB74: jal         0x80070A04
    // 0x8001CB78: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    sins_f(rdram, ctx);
        goto after_12;
    // 0x8001CB78: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_12:
    // 0x8001CB7C: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CB80: mul.s       $f22, $f0, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001CB84: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8001CB88: nop

    // 0x8001CB8C: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    // 0x8001CB90: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8001CB94: jal         0x80070A38
    // 0x8001CB98: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    coss_f(rdram, ctx);
        goto after_13;
    // 0x8001CB98: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_13:
    // 0x8001CB9C: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001CBA0: lw          $a0, 0xEC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CBA4: mul.s       $f10, $f22, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x8001CBA8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8001CBAC: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001CBB0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8001CBB4: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8001CBB8: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8001CBBC: jal         0x80011570
    // 0x8001CBC0: nop

    move_object(rdram, ctx);
        goto after_14;
    // 0x8001CBC0: nop

    after_14:
    // 0x8001CBC4: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8001CBC8: lw          $t1, 0xEC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CBCC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001CBD0: swc1        $f4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f4.u32l;
    // 0x8001CBD4: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001CBD8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001CBDC: mul.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x8001CBE0: nop

    // 0x8001CBE4: mul.s       $f20, $f10, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001CBE8: beq         $s1, $zero, L_8001CC24
    if (ctx->r17 == 0) {
        // 0x8001CBEC: nop
    
            goto L_8001CC24;
    }
    // 0x8001CBEC: nop

    // 0x8001CBF0: lbu         $t2, 0xD($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0XD);
    // 0x8001CBF4: lbu         $t3, 0xE($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0XE);
    // 0x8001CBF8: lbu         $t4, 0xF($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0XF);
    // 0x8001CBFC: lbu         $t5, 0x10($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X10);
    // 0x8001CC00: sb          $t2, 0xC($s2)
    MEM_B(0XC, ctx->r18) = ctx->r10;
    // 0x8001CC04: sb          $t3, 0xD($s2)
    MEM_B(0XD, ctx->r18) = ctx->r11;
    // 0x8001CC08: sb          $t4, 0xE($s2)
    MEM_B(0XE, ctx->r18) = ctx->r12;
    // 0x8001CC0C: sb          $t5, 0xF($s2)
    MEM_B(0XF, ctx->r18) = ctx->r13;
    // 0x8001CC10: lw          $a2, 0xF8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF8);
    // 0x8001CC14: andi        $a1, $t4, 0xFF
    ctx->r5 = ctx->r12 & 0XFF;
    // 0x8001CC18: jal         0x8001CC7C
    // 0x8001CC1C: andi        $a0, $t5, 0xFF
    ctx->r4 = ctx->r13 & 0XFF;
    ainode_find_next(rdram, ctx);
        goto after_15;
    // 0x8001CC1C: andi        $a0, $t5, 0xFF
    ctx->r4 = ctx->r13 & 0XFF;
    after_15:
    // 0x8001CC20: sb          $v0, 0x10($s2)
    MEM_B(0X10, ctx->r18) = ctx->r2;
L_8001CC24:
    // 0x8001CC24: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x8001CC28: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8001CC2C:
    // 0x8001CC2C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8001CC30: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001CC34: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8001CC38: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001CC3C: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8001CC40: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001CC44: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8001CC48: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001CC4C: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8001CC50: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001CC54: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8001CC58: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001CC5C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8001CC60: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8001CC64: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8001CC68: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8001CC6C: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x8001CC70: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x8001CC74: jr          $ra
    // 0x8001CC78: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x8001CC78: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void waves_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8240: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B8244: lw          $a0, 0x35D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X35D0);
    // 0x800B8248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B824C: beq         $a0, $zero, L_800B8264
    if (ctx->r4 == 0) {
        // 0x800B8250: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800B8264;
    }
    // 0x800B8250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8254: jal         0x80071380
    // 0x800B8258: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800B8258: nop

    after_0:
    // 0x800B825C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8260: sw          $zero, 0x35D0($at)
    MEM_W(0X35D0, ctx->r1) = 0;
L_800B8264:
    // 0x800B8264: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B8268: lw          $a0, 0x35D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X35D4);
    // 0x800B826C: nop

    // 0x800B8270: beq         $a0, $zero, L_800B8288
    if (ctx->r4 == 0) {
        // 0x800B8274: nop
    
            goto L_800B8288;
    }
    // 0x800B8274: nop

    // 0x800B8278: jal         0x80071380
    // 0x800B827C: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800B827C: nop

    after_1:
    // 0x800B8280: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8284: sw          $zero, 0x35D4($at)
    MEM_W(0X35D4, ctx->r1) = 0;
L_800B8288:
    // 0x800B8288: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B828C: lw          $a0, 0x35D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X35D8);
    // 0x800B8290: nop

    // 0x800B8294: beq         $a0, $zero, L_800B82AC
    if (ctx->r4 == 0) {
        // 0x800B8298: nop
    
            goto L_800B82AC;
    }
    // 0x800B8298: nop

    // 0x800B829C: jal         0x80071380
    // 0x800B82A0: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800B82A0: nop

    after_2:
    // 0x800B82A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B82A8: sw          $zero, 0x35D8($at)
    MEM_W(0X35D8, ctx->r1) = 0;
L_800B82AC:
    // 0x800B82AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B82B0: lw          $a0, 0x35DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X35DC);
    // 0x800B82B4: nop

    // 0x800B82B8: beq         $a0, $zero, L_800B82D0
    if (ctx->r4 == 0) {
        // 0x800B82BC: nop
    
            goto L_800B82D0;
    }
    // 0x800B82BC: nop

    // 0x800B82C0: jal         0x80071380
    // 0x800B82C4: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x800B82C4: nop

    after_3:
    // 0x800B82C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B82CC: sw          $zero, 0x35DC($at)
    MEM_W(0X35DC, ctx->r1) = 0;
L_800B82D0:
    // 0x800B82D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B82D4: lw          $a0, 0x3600($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3600);
    // 0x800B82D8: nop

    // 0x800B82DC: beq         $a0, $zero, L_800B82F4
    if (ctx->r4 == 0) {
        // 0x800B82E0: nop
    
            goto L_800B82F4;
    }
    // 0x800B82E0: nop

    // 0x800B82E4: jal         0x80071380
    // 0x800B82E8: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x800B82E8: nop

    after_4:
    // 0x800B82EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B82F0: sw          $zero, 0x3600($at)
    MEM_W(0X3600, ctx->r1) = 0;
L_800B82F4:
    // 0x800B82F4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B82F8: lw          $a0, 0x3610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3610);
    // 0x800B82FC: nop

    // 0x800B8300: beq         $a0, $zero, L_800B8318
    if (ctx->r4 == 0) {
        // 0x800B8304: nop
    
            goto L_800B8318;
    }
    // 0x800B8304: nop

    // 0x800B8308: jal         0x80071380
    // 0x800B830C: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800B830C: nop

    after_5:
    // 0x800B8310: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8314: sw          $zero, 0x3610($at)
    MEM_W(0X3610, ctx->r1) = 0;
L_800B8318:
    // 0x800B8318: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B831C: lw          $a0, 0x3660($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3660);
    // 0x800B8320: nop

    // 0x800B8324: beq         $a0, $zero, L_800B833C
    if (ctx->r4 == 0) {
        // 0x800B8328: nop
    
            goto L_800B833C;
    }
    // 0x800B8328: nop

    // 0x800B832C: jal         0x8007B70C
    // 0x800B8330: nop

    tex_free(rdram, ctx);
        goto after_6;
    // 0x800B8330: nop

    after_6:
    // 0x800B8334: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8338: sw          $zero, 0x3660($at)
    MEM_W(0X3660, ctx->r1) = 0;
L_800B833C:
    // 0x800B833C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B8340: lw          $a0, 0x3664($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3664);
    // 0x800B8344: nop

    // 0x800B8348: beq         $a0, $zero, L_800B8360
    if (ctx->r4 == 0) {
        // 0x800B834C: nop
    
            goto L_800B8360;
    }
    // 0x800B834C: nop

    // 0x800B8350: jal         0x80071380
    // 0x800B8354: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x800B8354: nop

    after_7:
    // 0x800B8358: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B835C: sw          $zero, 0x3664($at)
    MEM_W(0X3664, ctx->r1) = 0;
L_800B8360:
    // 0x800B8360: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B8364: lw          $a0, 0x3668($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3668);
    // 0x800B8368: nop

    // 0x800B836C: beq         $a0, $zero, L_800B8384
    if (ctx->r4 == 0) {
        // 0x800B8370: nop
    
            goto L_800B8384;
    }
    // 0x800B8370: nop

    // 0x800B8374: jal         0x80071380
    // 0x800B8378: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x800B8378: nop

    after_8:
    // 0x800B837C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8380: sw          $zero, 0x3668($at)
    MEM_W(0X3668, ctx->r1) = 0;
L_800B8384:
    // 0x800B8384: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B8388: lw          $a0, 0x3708($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3708);
    // 0x800B838C: nop

    // 0x800B8390: beq         $a0, $zero, L_800B83A8
    if (ctx->r4 == 0) {
        // 0x800B8394: nop
    
            goto L_800B83A8;
    }
    // 0x800B8394: nop

    // 0x800B8398: jal         0x80071380
    // 0x800B839C: nop

    mempool_free(rdram, ctx);
        goto after_9;
    // 0x800B839C: nop

    after_9:
    // 0x800B83A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B83A4: sw          $zero, 0x3708($at)
    MEM_W(0X3708, ctx->r1) = 0;
L_800B83A8:
    // 0x800B83A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B83AC: sw          $zero, 0x3720($at)
    MEM_W(0X3720, ctx->r1) = 0;
    // 0x800B83B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B83B4: sw          $zero, 0x3724($at)
    MEM_W(0X3724, ctx->r1) = 0;
    // 0x800B83B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B83BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B83C0: sw          $zero, 0x3714($at)
    MEM_W(0X3714, ctx->r1) = 0;
    // 0x800B83C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B83C8: sw          $zero, 0x3718($at)
    MEM_W(0X3718, ctx->r1) = 0;
    // 0x800B83CC: jr          $ra
    // 0x800B83D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B83D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void free_game_text_table(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3624: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3628: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C362C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800C3630: addiu       $s1, $s1, 0x3C00
    ctx->r17 = ADD32(ctx->r17, 0X3C00);
    // 0x800C3634: lb          $t6, 0x0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X0);
    // 0x800C3638: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C363C: beq         $t6, $zero, L_800C3684
    if (ctx->r14 == 0) {
        // 0x800C3640: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800C3684;
    }
    // 0x800C3640: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C3644: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C3648: lw          $a0, -0x52C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X52C0);
    // 0x800C364C: jal         0x80071380
    // 0x800C3650: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800C3650: nop

    after_0:
    // 0x800C3654: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x800C3658: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C365C: sb          $zero, -0x52B7($at)
    MEM_B(-0X52B7, ctx->r1) = 0;
    // 0x800C3660: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x800C3664: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800C3668:
    // 0x800C3668: jal         0x8009D4F4
    // 0x800C366C: nop

    dialogue_try_close(rdram, ctx);
        goto after_1;
    // 0x800C366C: nop

    after_1:
    // 0x800C3670: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C3674: bne         $s0, $s1, L_800C3668
    if (ctx->r16 != ctx->r17) {
        // 0x800C3678: nop
    
            goto L_800C3668;
    }
    // 0x800C3678: nop

    // 0x800C367C: jal         0x800C2FD4
    // 0x800C3680: nop

    free_message_box(rdram, ctx);
        goto after_2;
    // 0x800C3680: nop

    after_2:
L_800C3684:
    // 0x800C3684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3688: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C368C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C3690: jr          $ra
    // 0x800C3694: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C3694: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void cam_shake_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066300: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80066304: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066308: jr          $ra
    // 0x8006630C: sw          $t6, 0x1298($at)
    MEM_W(0X1298, ctx->r1) = ctx->r14;
    return;
    // 0x8006630C: sw          $t6, 0x1298($at)
    MEM_W(0X1298, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void savemenu_render_error(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087648: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008764C: lui         $at, 0x3FFF
    ctx->r1 = S32(0X3FFF << 16);
    // 0x80087650: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80087654: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80087658: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x8008765C: sra         $t6, $a0, 30
    ctx->r14 = S32(SIGNED(ctx->r4) >> 30);
    // 0x80087660: and         $t8, $a0, $at
    ctx->r24 = ctx->r4 & ctx->r1;
    // 0x80087664: addiu       $s5, $s5, 0x60
    ctx->r21 = ADD32(ctx->r21, 0X60);
    // 0x80087668: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x8008766C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80087670: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80087674: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80087678: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    // 0x8008767C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80087680: lw          $t0, 0x15C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X15C);
    // 0x80087684: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80087688: addiu       $s4, $s4, 0x7030
    ctx->r20 = ADD32(ctx->r20, 0X7030);
    // 0x8008768C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80087690: sw          $t0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r8;
    // 0x80087694: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80087698: sw          $t8, 0x5C($at)
    MEM_W(0X5C, ctx->r1) = ctx->r24;
    // 0x8008769C: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800876A0: addiu       $a1, $a1, 0x7034
    ctx->r5 = ADD32(ctx->r5, 0X7034);
    // 0x800876A4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800876A8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800876AC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800876B0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800876B4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800876B8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800876BC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800876C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800876C4: beq         $t1, $zero, L_800876E0
    if (ctx->r9 == 0) {
        // 0x800876C8: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800876E0;
    }
    // 0x800876C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800876CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800876D0:
    // 0x800876D0: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800876D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800876D8: bne         $t2, $zero, L_800876D0
    if (ctx->r10 != 0) {
        // 0x800876DC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800876D0;
    }
    // 0x800876DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800876E0:
    // 0x800876E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800876E4: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x800876E8: addu        $v0, $v1, $t3
    ctx->r2 = ADD32(ctx->r3, ctx->r11);
    // 0x800876EC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800876F0: nop

    // 0x800876F4: beq         $t4, $zero, L_8008771C
    if (ctx->r12 == 0) {
        // 0x800876F8: nop
    
            goto L_8008771C;
    }
    // 0x800876F8: nop

L_800876FC:
    // 0x800876FC: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80087700: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80087704: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80087708: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8008770C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80087710: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80087714: bne         $t7, $zero, L_800876FC
    if (ctx->r15 != 0) {
        // 0x80087718: nop
    
            goto L_800876FC;
    }
    // 0x80087718: nop

L_8008771C:
    // 0x8008771C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80087720: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087724: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80087728: jal         0x800C59F4
    // 0x8008772C: sw          $t9, 0x7038($at)
    MEM_W(0X7038, ctx->r1) = ctx->r25;
    dialogue_clear(rdram, ctx);
        goto after_0;
    // 0x8008772C: sw          $t9, 0x7038($at)
    MEM_W(0X7038, ctx->r1) = ctx->r25;
    after_0:
    // 0x80087730: sll         $v0, $s0, 4
    ctx->r2 = S32(ctx->r16 << 4);
    // 0x80087734: addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
    // 0x80087738: sra         $t0, $v0, 1
    ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008773C: addiu       $t2, $t0, 0x78
    ctx->r10 = ADD32(ctx->r8, 0X78);
    // 0x80087740: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x80087744: subu        $a2, $t1, $t0
    ctx->r6 = SUB32(ctx->r9, ctx->r8);
    // 0x80087748: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008774C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80087750: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087754: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80087758: jal         0x800C543C
    // 0x8008775C: addiu       $a3, $zero, 0x118
    ctx->r7 = ADD32(0, 0X118);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_1;
    // 0x8008775C: addiu       $a3, $zero, 0x118
    ctx->r7 = ADD32(0, 0X118);
    after_1:
    // 0x80087760: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x80087764: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80087768: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8008776C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087770: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80087774: jal         0x800C551C
    // 0x80087778: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_2;
    // 0x80087778: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8008777C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087780: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087784: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80087788: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008778C: jal         0x800C55B0
    // 0x80087790: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_3;
    // 0x80087790: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80087794: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087798: jal         0x800C54DC
    // 0x8008779C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    set_dialogue_font(rdram, ctx);
        goto after_4;
    // 0x8008779C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x800877A0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800877A4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800877A8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800877AC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800877B0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800877B4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800877B8: jal         0x800C5560
    // 0x800877BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_5;
    // 0x800877BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x800877C0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800877C4: lw          $v0, -0x5E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E0);
    // 0x800877C8: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800877CC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800877D0: addiu       $t5, $t5, 0x10C
    ctx->r13 = ADD32(ctx->r13, 0X10C);
    // 0x800877D4: lw          $a3, 0x100($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X100);
    // 0x800877D8: beq         $v1, $t5, L_800877F0
    if (ctx->r3 == ctx->r13) {
        // 0x800877DC: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_800877F0;
    }
    // 0x800877DC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800877E0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800877E4: addiu       $t6, $t6, 0x124
    ctx->r14 = ADD32(ctx->r14, 0X124);
    // 0x800877E8: bne         $v1, $t6, L_800877FC
    if (ctx->r3 != ctx->r14) {
        // 0x800877EC: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800877FC;
    }
    // 0x800877EC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
L_800877F0:
    // 0x800877F0: lw          $a3, 0x260($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X260);
    // 0x800877F4: b           L_80087814
    // 0x800877F8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
        goto L_80087814;
    // 0x800877F8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_800877FC:
    // 0x800877FC: addiu       $t7, $t7, 0x13C
    ctx->r15 = ADD32(ctx->r15, 0X13C);
    // 0x80087800: bne         $v1, $t7, L_80087814
    if (ctx->r3 != ctx->r15) {
        // 0x80087804: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80087814;
    }
    // 0x80087804: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80087808: lw          $a3, 0x1F4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X1F4);
    // 0x8008780C: nop

    // 0x80087810: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80087814:
    // 0x80087814: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80087818: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8008781C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80087820: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80087824: jal         0x800C56C8
    // 0x80087828: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    render_dialogue_text(rdram, ctx);
        goto after_6;
    // 0x80087828: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_6:
    // 0x8008782C: addiu       $s2, $zero, 0x34
    ctx->r18 = ADD32(0, 0X34);
    // 0x80087830: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80087834: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087838: jal         0x800C54DC
    // 0x8008783C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_7;
    // 0x8008783C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80087840: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x80087844: sll         $s0, $s3, 2
    ctx->r16 = S32(ctx->r19 << 2);
    // 0x80087848: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8008784C: addu        $t1, $v1, $s0
    ctx->r9 = ADD32(ctx->r3, ctx->r16);
    // 0x80087850: beq         $t0, $zero, L_800878A4
    if (ctx->r8 == 0) {
        // 0x80087854: nop
    
            goto L_800878A4;
    }
    // 0x80087854: nop

    // 0x80087858: lw          $s1, 0x0($t1)
    ctx->r17 = MEM_W(ctx->r9, 0X0);
    // 0x8008785C: nop

L_80087860:
    // 0x80087860: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x80087864: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80087868: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008786C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80087870: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80087874: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087878: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8008787C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80087880: jal         0x800C56C8
    // 0x80087884: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_8;
    // 0x80087884: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_8:
    // 0x80087888: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8008788C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80087890: addu        $t5, $v1, $s0
    ctx->r13 = ADD32(ctx->r3, ctx->r16);
    // 0x80087894: lw          $s1, 0x0($t5)
    ctx->r17 = MEM_W(ctx->r13, 0X0);
    // 0x80087898: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8008789C: bne         $s1, $zero, L_80087860
    if (ctx->r17 != 0) {
        // 0x800878A0: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_80087860;
    }
    // 0x800878A0: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_800878A4:
    // 0x800878A4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800878A8: sll         $s0, $s3, 2
    ctx->r16 = S32(ctx->r19 << 2);
    // 0x800878AC: addu        $t6, $v1, $s0
    ctx->r14 = ADD32(ctx->r3, ctx->r16);
    // 0x800878B0: lw          $s1, 0x0($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X0);
    // 0x800878B4: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x800878B8: beq         $s1, $zero, L_80087908
    if (ctx->r17 == 0) {
        // 0x800878BC: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_80087908;
    }
    // 0x800878BC: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800878C0: addiu       $s3, $s3, 0x7040
    ctx->r19 = ADD32(ctx->r19, 0X7040);
L_800878C4:
    // 0x800878C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800878C8: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800878CC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800878D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800878D4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800878D8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x800878DC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800878E0: jal         0x800C56C8
    // 0x800878E4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_9;
    // 0x800878E4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_9:
    // 0x800878E8: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x800878EC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800878F0: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800878F4: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x800878F8: lw          $s1, 0x0($t0)
    ctx->r17 = MEM_W(ctx->r8, 0X0);
    // 0x800878FC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80087900: bne         $s1, $zero, L_800878C4
    if (ctx->r17 != 0) {
        // 0x80087904: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_800878C4;
    }
    // 0x80087904: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_80087908:
    // 0x80087908: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008790C: addiu       $v0, $v0, 0x6980
    ctx->r2 = ADD32(ctx->r2, 0X6980);
    // 0x80087910: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80087914: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80087918: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8008791C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80087920: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80087924: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80087928: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8008792C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80087930: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80087934: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80087938: jr          $ra
    // 0x8008793C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8008793C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void align4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071AC8: andi        $v1, $a0, 0x3
    ctx->r3 = ctx->r4 & 0X3;
    // 0x80071ACC: blez        $v1, L_80071ADC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80071AD0: nop
    
            goto L_80071ADC;
    }
    // 0x80071AD0: nop

    // 0x80071AD4: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80071AD8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80071ADC:
    // 0x80071ADC: jr          $ra
    // 0x80071AE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80071AE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void hud_main_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1300: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A1304: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A1308: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A130C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A1310: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A1314: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A1318: lw          $s1, 0x64($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X64);
    // 0x800A131C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800A1320: jal         0x80068748
    // 0x800A1324: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_0;
    // 0x800A1324: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800A1328: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A132C: jal         0x800A13F4
    // 0x800A1330: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_course_arrows(rdram, ctx);
        goto after_1;
    // 0x800A1330: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800A1334: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A1338: jal         0x800A5FAC
    // 0x800A133C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_wrong_way(rdram, ctx);
        goto after_2;
    // 0x800A133C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800A1340: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A1344: jal         0x800A422C
    // 0x800A1348: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_start(rdram, ctx);
        goto after_3;
    // 0x800A1348: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800A134C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A1350: lw          $t7, 0x7320($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7320);
    // 0x800A1354: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A1358: lb          $t8, 0x4C($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X4C);
    // 0x800A135C: nop

    // 0x800A1360: bne         $t8, $zero, L_800A1370
    if (ctx->r24 != 0) {
        // 0x800A1364: nop
    
            goto L_800A1370;
    }
    // 0x800A1364: nop

    // 0x800A1368: jal         0x800A5498
    // 0x800A136C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_lap_count(rdram, ctx);
        goto after_4;
    // 0x800A136C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
L_800A1370:
    // 0x800A1370: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A1374: jal         0x800A469C
    // 0x800A1378: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_bananas(rdram, ctx);
        goto after_5;
    // 0x800A1378: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800A137C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A1380: jal         0x800A80C4
    // 0x800A1384: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_time(rdram, ctx);
        goto after_6;
    // 0x800A1384: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800A1388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A138C: jal         0x800A518C
    // 0x800A1390: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_position(rdram, ctx);
        goto after_7;
    // 0x800A1390: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800A1394: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A1398: jal         0x800A3DCC
    // 0x800A139C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_speedometre(rdram, ctx);
        goto after_8;
    // 0x800A139C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800A13A0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A13A4: lbu         $t9, 0x7748($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7748);
    // 0x800A13A8: nop

    // 0x800A13AC: beq         $t9, $zero, L_800A13D0
    if (ctx->r25 == 0) {
        // 0x800A13B0: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_800A13D0;
    }
    // 0x800A13B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A13B4: lb          $t0, 0x1D8($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X1D8);
    // 0x800A13B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A13BC: bne         $t0, $zero, L_800A13CC
    if (ctx->r8 != 0) {
        // 0x800A13C0: nop
    
            goto L_800A13CC;
    }
    // 0x800A13C0: nop

    // 0x800A13C4: jal         0x800A4CE8
    // 0x800A13C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_silver_coins(rdram, ctx);
        goto after_9;
    // 0x800A13C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
L_800A13CC:
    // 0x800A13CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_800A13D0:
    // 0x800A13D0: jal         0x800A7A7C
    // 0x800A13D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_weapon(rdram, ctx);
        goto after_10;
    // 0x800A13D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x800A13D8: jal         0x80068748
    // 0x800A13DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_11;
    // 0x800A13DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x800A13E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A13E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A13E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A13EC: jr          $ra
    // 0x800A13F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A13F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void set_boss_voice_clip_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CC18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005CC1C: jr          $ra
    // 0x8005CC20: sw          $a0, -0x24B8($at)
    MEM_W(-0X24B8, ctx->r1) = ctx->r4;
    return;
    // 0x8005CC20: sw          $a0, -0x24B8($at)
    MEM_W(-0X24B8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void asset_table_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800772DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800772E0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800772E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800772E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800772EC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800772F0: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x800772F4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800772F8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800772FC: jal         0x800C9110
    // 0x80077300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80077300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80077304: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80077308: lw          $v0, 0x4830($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4830);
    // 0x8007730C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80077310: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80077314: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077318: sltu        $at, $t6, $a3
    ctx->r1 = ctx->r14 < ctx->r7 ? 1 : 0;
    // 0x8007731C: beq         $at, $zero, L_8007732C
    if (ctx->r1 == 0) {
        // 0x80077320: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_8007732C;
    }
    // 0x80077320: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80077324: b           L_80077360
    // 0x80077328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80077360;
    // 0x80077328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007732C:
    // 0x8007732C: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80077330: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x80077334: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80077338: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x8007733C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80077340: jal         0x800C9390
    // 0x80077344: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80077344: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80077348: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8007734C: nop

    // 0x80077350: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80077354: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80077358: nop

    // 0x8007735C: subu        $v0, $t8, $t9
    ctx->r2 = SUB32(ctx->r24, ctx->r25);
L_80077360:
    // 0x80077360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077364: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80077368: jr          $ra
    // 0x8007736C: nop

    return;
    // 0x8007736C: nop

;}
RECOMP_FUNC void update_AI_racer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A75C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8005A760: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005A764: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8005A768: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8005A76C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A770: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8005A774: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x8005A778: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x8005A77C: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x8005A780: jal         0x8006DC4C
    // 0x8005A784: sw          $t6, -0x2524($at)
    MEM_W(-0X2524, ctx->r1) = ctx->r14;
    get_game_mode(rdram, ctx);
        goto after_0;
    // 0x8005A784: sw          $t6, -0x2524($at)
    MEM_W(-0X2524, ctx->r1) = ctx->r14;
    after_0:
    // 0x8005A788: jal         0x8006BFF0
    // 0x8005A78C: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    level_header(rdram, ctx);
        goto after_1;
    // 0x8005A78C: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    after_1:
    // 0x8005A790: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x8005A794: lb          $v1, 0x1F6($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1F6);
    // 0x8005A798: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8005A79C: blez        $v1, L_8005A7B8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8005A7A0: nop
    
            goto L_8005A7B8;
    }
    // 0x8005A7A0: nop

    // 0x8005A7A4: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x8005A7A8: nop

    // 0x8005A7AC: subu        $t8, $v1, $t7
    ctx->r24 = SUB32(ctx->r3, ctx->r15);
    // 0x8005A7B0: b           L_8005A7BC
    // 0x8005A7B4: sb          $t8, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = ctx->r24;
        goto L_8005A7BC;
    // 0x8005A7B4: sb          $t8, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = ctx->r24;
L_8005A7B8:
    // 0x8005A7B8: sb          $zero, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = 0;
L_8005A7BC:
    // 0x8005A7BC: lw          $t9, -0x2540($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2540);
    // 0x8005A7C0: nop

    // 0x8005A7C4: beq         $t9, $zero, L_8005A7DC
    if (ctx->r25 == 0) {
        // 0x8005A7C8: addiu       $a0, $zero, -0x3C
        ctx->r4 = ADD32(0, -0X3C);
            goto L_8005A7DC;
    }
    // 0x8005A7C8: addiu       $a0, $zero, -0x3C
    ctx->r4 = ADD32(0, -0X3C);
    // 0x8005A7CC: jal         0x8006FB8C
    // 0x8005A7D0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x8005A7D0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_2:
    // 0x8005A7D4: addiu       $t5, $v0, 0x78
    ctx->r13 = ADD32(ctx->r2, 0X78);
    // 0x8005A7D8: sh          $t5, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r13;
L_8005A7DC:
    // 0x8005A7DC: lh          $v0, 0x18C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18C);
    // 0x8005A7E0: nop

    // 0x8005A7E4: blez        $v0, L_8005A800
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005A7E8: nop
    
            goto L_8005A800;
    }
    // 0x8005A7E8: nop

    // 0x8005A7EC: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8005A7F0: nop

    // 0x8005A7F4: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8005A7F8: b           L_8005A804
    // 0x8005A7FC: sh          $t7, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = ctx->r15;
        goto L_8005A804;
    // 0x8005A7FC: sh          $t7, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = ctx->r15;
L_8005A800:
    // 0x8005A800: sh          $zero, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = 0;
L_8005A804:
    // 0x8005A804: jal         0x8001E2D0
    // 0x8005A808: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    get_misc_asset(rdram, ctx);
        goto after_3;
    // 0x8005A808: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_3:
    // 0x8005A80C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005A810: addiu       $v1, $v1, -0x251C
    ctx->r3 = ADD32(ctx->r3, -0X251C);
    // 0x8005A814: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005A818: lb          $t9, 0x3($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X3);
    // 0x8005A81C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A820: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8005A824: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8005A828: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8005A82C: lwc1        $f9, 0x6ED0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6ED0);
    // 0x8005A830: lwc1        $f8, 0x6ED4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6ED4);
    // 0x8005A834: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005A838: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8005A83C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8005A840: addiu       $t4, $t4, -0x2514
    ctx->r12 = ADD32(ctx->r12, -0X2514);
    // 0x8005A844: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005A848: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    // 0x8005A84C: lh          $t7, 0x204($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X204);
    // 0x8005A850: nop

    // 0x8005A854: blez        $t7, L_8005A868
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005A858: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005A868;
    }
    // 0x8005A858: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A85C: lwc1        $f4, 0x6ED8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6ED8);
    // 0x8005A860: nop

    // 0x8005A864: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
L_8005A868:
    // 0x8005A868: jal         0x8001E2D0
    // 0x8005A86C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    get_misc_asset(rdram, ctx);
        goto after_4;
    // 0x8005A86C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_4:
    // 0x8005A870: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005A874: addiu       $v1, $v1, -0x251C
    ctx->r3 = ADD32(ctx->r3, -0X251C);
    // 0x8005A878: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005A87C: lb          $t8, 0x3($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X3);
    // 0x8005A880: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A884: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8005A888: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8005A88C: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8005A890: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8005A894: jal         0x8001E2D0
    // 0x8005A898: swc1        $f6, -0x2510($at)
    MEM_W(-0X2510, ctx->r1) = ctx->f6.u32l;
    get_misc_asset(rdram, ctx);
        goto after_5;
    // 0x8005A898: swc1        $f6, -0x2510($at)
    MEM_W(-0X2510, ctx->r1) = ctx->f6.u32l;
    after_5:
    // 0x8005A89C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005A8A0: addiu       $a1, $a1, -0x251C
    ctx->r5 = ADD32(ctx->r5, -0X251C);
    // 0x8005A8A4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8005A8A8: lb          $t8, 0x3($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X3);
    // 0x8005A8AC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005A8B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005A8B4: addu        $t5, $v0, $t9
    ctx->r13 = ADD32(ctx->r2, ctx->r25);
    // 0x8005A8B8: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8005A8BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A8C0: swc1        $f8, -0x250C($at)
    MEM_W(-0X250C, ctx->r1) = ctx->f8.u32l;
    // 0x8005A8C4: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005A8C8: nop

    // 0x8005A8CC: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x8005A8D0: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8005A8D4: nop

    // 0x8005A8D8: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x8005A8DC: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8005A8E0: nop

    // 0x8005A8E4: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x8005A8E8: lh          $v1, 0x1B2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1B2);
    // 0x8005A8EC: nop

    // 0x8005A8F0: blez        $v1, L_8005A91C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8005A8F4: nop
    
            goto L_8005A91C;
    }
    // 0x8005A8F4: nop

    // 0x8005A8F8: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8005A8FC: nop

    // 0x8005A900: subu        $t8, $v1, $t6
    ctx->r24 = SUB32(ctx->r3, ctx->r14);
    // 0x8005A904: sh          $t8, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = ctx->r24;
    // 0x8005A908: lh          $t7, 0x1B2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1B2);
    // 0x8005A90C: nop

    // 0x8005A910: bgez        $t7, L_8005A91C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8005A914: nop
    
            goto L_8005A91C;
    }
    // 0x8005A914: nop

    // 0x8005A918: sh          $zero, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = 0;
L_8005A91C:
    // 0x8005A91C: lb          $t9, 0x1E7($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E7);
    // 0x8005A920: nop

    // 0x8005A924: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8005A928: jal         0x80023450
    // 0x8005A92C: sb          $t5, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r13;
    is_taj_challenge(rdram, ctx);
        goto after_6;
    // 0x8005A92C: sb          $t5, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r13;
    after_6:
    // 0x8005A930: bne         $v0, $zero, L_8005A99C
    if (ctx->r2 != 0) {
        // 0x8005A934: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_8005A99C;
    }
    // 0x8005A934: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8005A938: jal         0x8002359C
    // 0x8005A93C: nop

    func_80023568(rdram, ctx);
        goto after_7;
    // 0x8005A93C: nop

    after_7:
    // 0x8005A940: bne         $v0, $zero, L_8005A99C
    if (ctx->r2 != 0) {
        // 0x8005A944: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_8005A99C;
    }
    // 0x8005A944: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8005A948: lb          $t6, 0x1D6($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D6);
    // 0x8005A94C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005A950: beq         $t6, $at, L_8005A998
    if (ctx->r14 == ctx->r1) {
        // 0x8005A954: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_8005A998;
    }
    // 0x8005A954: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005A958: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005A95C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A960: lwc1        $f8, -0x253C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X253C);
    // 0x8005A964: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005A968: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8005A96C: nop

    // 0x8005A970: bc1t        L_8005A99C
    if (c1cs) {
        // 0x8005A974: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_8005A99C;
    }
    // 0x8005A974: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8005A978: lw          $t8, -0x2540($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2540);
    // 0x8005A97C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8005A980: bne         $t8, $zero, L_8005A99C
    if (ctx->r24 != 0) {
        // 0x8005A984: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_8005A99C;
    }
    // 0x8005A984: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8005A988: lb          $t9, 0x4C($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X4C);
    // 0x8005A98C: nop

    // 0x8005A990: andi        $t5, $t9, 0x40
    ctx->r13 = ctx->r25 & 0X40;
    // 0x8005A994: beq         $t5, $zero, L_8005A9A0
    if (ctx->r13 == 0) {
        // 0x8005A998: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_8005A9A0;
    }
L_8005A998:
    // 0x8005A998: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
L_8005A99C:
    // 0x8005A99C: sb          $t6, 0x201($s0)
    MEM_B(0X201, ctx->r16) = ctx->r14;
L_8005A9A0:
    // 0x8005A9A0: lb          $t8, 0x201($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X201);
    // 0x8005A9A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A9A8: lwc1        $f2, 0x6EDC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6EDC);
    // 0x8005A9AC: bne         $t8, $zero, L_8005ABA0
    if (ctx->r24 != 0) {
        // 0x8005A9B0: addiu       $a0, $sp, 0x90
        ctx->r4 = ADD32(ctx->r29, 0X90);
            goto L_8005ABA0;
    }
    // 0x8005A9B0: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x8005A9B4: jal         0x8001BAA8
    // 0x8005A9B8: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    get_racer_objects(rdram, ctx);
        goto after_8;
    // 0x8005A9B8: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    after_8:
    // 0x8005A9BC: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x8005A9C0: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8005A9C4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005A9C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005A9CC: blez        $t7, L_8005AB24
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005A9D0: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8005AB24;
    }
    // 0x8005A9D0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005A9D4: andi        $v1, $t7, 0x3
    ctx->r3 = ctx->r15 & 0X3;
    // 0x8005A9D8: beq         $v1, $zero, L_8005AA3C
    if (ctx->r3 == 0) {
        // 0x8005A9DC: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_8005AA3C;
    }
    // 0x8005A9DC: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8005A9E0: sll         $t9, $zero, 2
    ctx->r25 = S32(0 << 2);
    // 0x8005A9E4: addu        $a2, $v0, $t9
    ctx->r6 = ADD32(ctx->r2, ctx->r25);
    // 0x8005A9E8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005A9EC:
    // 0x8005A9EC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8005A9F0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8005A9F4: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x8005A9F8: nop

    // 0x8005A9FC: lh          $t5, 0x0($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X0);
    // 0x8005AA00: nop

    // 0x8005AA04: bne         $t5, $zero, L_8005AA10
    if (ctx->r13 != 0) {
        // 0x8005AA08: nop
    
            goto L_8005AA10;
    }
    // 0x8005AA08: nop

    // 0x8005AA0C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_8005AA10:
    // 0x8005AA10: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8005AA14: nop

    // 0x8005AA18: bne         $t3, $t6, L_8005AA24
    if (ctx->r11 != ctx->r14) {
        // 0x8005AA1C: nop
    
            goto L_8005AA24;
    }
    // 0x8005AA1C: nop

    // 0x8005AA20: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_8005AA24:
    // 0x8005AA24: bne         $t1, $t2, L_8005A9EC
    if (ctx->r9 != ctx->r10) {
        // 0x8005AA28: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8005A9EC;
    }
    // 0x8005AA28: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8005AA2C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x8005AA30: nop

    // 0x8005AA34: beq         $t2, $t8, L_8005AB24
    if (ctx->r10 == ctx->r24) {
        // 0x8005AA38: nop
    
            goto L_8005AB24;
    }
    // 0x8005AA38: nop

L_8005AA3C:
    // 0x8005AA3C: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x8005AA40: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x8005AA44: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8005AA48: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8005AA4C: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8005AA50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005AA54:
    // 0x8005AA54: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8005AA58: nop

    // 0x8005AA5C: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x8005AA60: nop

    // 0x8005AA64: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8005AA68: nop

    // 0x8005AA6C: bne         $t6, $zero, L_8005AA78
    if (ctx->r14 != 0) {
        // 0x8005AA70: nop
    
            goto L_8005AA78;
    }
    // 0x8005AA70: nop

    // 0x8005AA74: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_8005AA78:
    // 0x8005AA78: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x8005AA7C: nop

    // 0x8005AA80: bne         $t3, $t8, L_8005AA8C
    if (ctx->r11 != ctx->r24) {
        // 0x8005AA84: nop
    
            goto L_8005AA8C;
    }
    // 0x8005AA84: nop

    // 0x8005AA88: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_8005AA8C:
    // 0x8005AA8C: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    // 0x8005AA90: nop

    // 0x8005AA94: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x8005AA98: nop

    // 0x8005AA9C: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8005AAA0: nop

    // 0x8005AAA4: bne         $a0, $zero, L_8005AAB0
    if (ctx->r4 != 0) {
        // 0x8005AAA8: nop
    
            goto L_8005AAB0;
    }
    // 0x8005AAA8: nop

    // 0x8005AAAC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_8005AAB0:
    // 0x8005AAB0: bne         $t3, $a0, L_8005AABC
    if (ctx->r11 != ctx->r4) {
        // 0x8005AAB4: nop
    
            goto L_8005AABC;
    }
    // 0x8005AAB4: nop

    // 0x8005AAB8: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_8005AABC:
    // 0x8005AABC: lw          $a1, 0x8($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X8);
    // 0x8005AAC0: nop

    // 0x8005AAC4: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x8005AAC8: nop

    // 0x8005AACC: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8005AAD0: nop

    // 0x8005AAD4: bne         $a0, $zero, L_8005AAE0
    if (ctx->r4 != 0) {
        // 0x8005AAD8: nop
    
            goto L_8005AAE0;
    }
    // 0x8005AAD8: nop

    // 0x8005AADC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_8005AAE0:
    // 0x8005AAE0: bne         $t3, $a0, L_8005AAEC
    if (ctx->r11 != ctx->r4) {
        // 0x8005AAE4: nop
    
            goto L_8005AAEC;
    }
    // 0x8005AAE4: nop

    // 0x8005AAE8: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_8005AAEC:
    // 0x8005AAEC: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8005AAF0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8005AAF4: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x8005AAF8: nop

    // 0x8005AAFC: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8005AB00: nop

    // 0x8005AB04: bne         $a0, $zero, L_8005AB10
    if (ctx->r4 != 0) {
        // 0x8005AB08: nop
    
            goto L_8005AB10;
    }
    // 0x8005AB08: nop

    // 0x8005AB0C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_8005AB10:
    // 0x8005AB10: bne         $t3, $a0, L_8005AB1C
    if (ctx->r11 != ctx->r4) {
        // 0x8005AB14: nop
    
            goto L_8005AB1C;
    }
    // 0x8005AB14: nop

    // 0x8005AB18: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_8005AB1C:
    // 0x8005AB1C: bne         $a2, $t1, L_8005AA54
    if (ctx->r6 != ctx->r9) {
        // 0x8005AB20: nop
    
            goto L_8005AA54;
    }
    // 0x8005AB20: nop

L_8005AB24:
    // 0x8005AB24: beq         $a3, $zero, L_8005AB54
    if (ctx->r7 == 0) {
        // 0x8005AB28: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005AB54;
    }
    // 0x8005AB28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005AB2C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AB30: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005AB34: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005AB38: lwc1        $f4, 0x14($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8005AB3C: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8005AB40: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8005AB44: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005AB48: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005AB4C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005AB50: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
L_8005AB54:
    // 0x8005AB54: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AB58: beq         $t0, $zero, L_8005ABA0
    if (ctx->r8 == 0) {
        // 0x8005AB5C: nop
    
            goto L_8005ABA0;
    }
    // 0x8005AB5C: nop

    // 0x8005AB60: lwc1        $f5, 0x6EE0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6EE0);
    // 0x8005AB64: lwc1        $f4, 0x6EE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6EE4);
    // 0x8005AB68: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x8005AB6C: c.le.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d <= ctx->f18.d;
    // 0x8005AB70: nop

    // 0x8005AB74: bc1f        L_8005ABA0
    if (!c1cs) {
        // 0x8005AB78: nop
    
            goto L_8005ABA0;
    }
    // 0x8005AB78: nop

    // 0x8005AB7C: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8005AB80: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005AB84: lwc1        $f10, 0x14($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8005AB88: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8005AB8C: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8005AB90: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005AB94: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8005AB98: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005AB9C: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
L_8005ABA0:
    // 0x8005ABA0: lh          $v0, 0x204($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X204);
    // 0x8005ABA4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005ABA8: blez        $v0, L_8005ABD4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005ABAC: nop
    
            goto L_8005ABD4;
    }
    // 0x8005ABAC: nop

    // 0x8005ABB0: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x8005ABB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005ABB8: subu        $t7, $v0, $a2
    ctx->r15 = SUB32(ctx->r2, ctx->r6);
    // 0x8005ABBC: sh          $t7, 0x204($s0)
    MEM_H(0X204, ctx->r16) = ctx->r15;
    // 0x8005ABC0: lwc1        $f10, 0x6EE8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6EE8);
    // 0x8005ABC4: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005ABC8: nop

    // 0x8005ABCC: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005ABD0: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_8005ABD4:
    // 0x8005ABD4: lh          $v0, 0x206($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X206);
    // 0x8005ABD8: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x8005ABDC: blez        $v0, L_8005ABEC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005ABE0: subu        $t9, $v0, $a2
        ctx->r25 = SUB32(ctx->r2, ctx->r6);
            goto L_8005ABEC;
    }
    // 0x8005ABE0: subu        $t9, $v0, $a2
    ctx->r25 = SUB32(ctx->r2, ctx->r6);
    // 0x8005ABE4: sh          $v0, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r2;
    // 0x8005ABE8: sh          $t9, 0x206($s0)
    MEM_H(0X206, ctx->r16) = ctx->r25;
L_8005ABEC:
    // 0x8005ABEC: lb          $v0, 0x201($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X201);
    // 0x8005ABF0: nop

    // 0x8005ABF4: bne         $v0, $zero, L_8005AC24
    if (ctx->r2 != 0) {
        // 0x8005ABF8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005AC24;
    }
    // 0x8005ABF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005ABFC: lwc1        $f7, 0x6EF0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6EF0);
    // 0x8005AC00: lwc1        $f6, 0x6EF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6EF4);
    // 0x8005AC04: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8005AC08: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8005AC0C: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x8005AC10: bc1f        L_8005AC24
    if (!c1cs) {
        // 0x8005AC14: nop
    
            goto L_8005AC24;
    }
    // 0x8005AC14: nop

    // 0x8005AC18: sb          $t5, 0x201($s0)
    MEM_B(0X201, ctx->r16) = ctx->r13;
    // 0x8005AC1C: lb          $v0, 0x201($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X201);
    // 0x8005AC20: nop

L_8005AC24:
    // 0x8005AC24: beq         $v0, $zero, L_8005B488
    if (ctx->r2 == 0) {
        // 0x8005AC28: lw          $a3, 0xAC($sp)
        ctx->r7 = MEM_W(ctx->r29, 0XAC);
            goto L_8005B488;
    }
    // 0x8005AC28: lw          $a3, 0xAC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XAC);
    // 0x8005AC2C: jal         0x800441B0
    // 0x8005AC30: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_AI_pathing_inputs(rdram, ctx);
        goto after_9;
    // 0x8005AC30: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x8005AC34: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8005AC38: lw          $t6, -0x2558($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2558);
    // 0x8005AC3C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8005AC40: andi        $t8, $t6, 0x8000
    ctx->r24 = ctx->r14 & 0X8000;
    // 0x8005AC44: addiu       $t4, $t4, -0x2514
    ctx->r12 = ADD32(ctx->r12, -0X2514);
    // 0x8005AC48: bne         $t8, $zero, L_8005AC58
    if (ctx->r24 != 0) {
        // 0x8005AC4C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8005AC58;
    }
    // 0x8005AC4C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005AC50: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005AC54: sb          $t7, 0x20C($s0)
    MEM_B(0X20C, ctx->r16) = ctx->r15;
L_8005AC58:
    // 0x8005AC58: lbu         $v0, 0x1FE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8005AC5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005AC60: bne         $v0, $at, L_8005ACA8
    if (ctx->r2 != ctx->r1) {
        // 0x8005AC64: nop
    
            goto L_8005ACA8;
    }
    // 0x8005AC64: nop

    // 0x8005AC68: lbu         $t9, 0x1FF($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8005AC6C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8005AC70: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8005AC74: bgez        $t9, L_8005AC88
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005AC78: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8005AC88;
    }
    // 0x8005AC78: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005AC7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005AC80: nop

    // 0x8005AC84: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8005AC88:
    // 0x8005AC88: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8005AC8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005AC90: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8005AC94: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8005AC98: mul.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8005AC9C: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    // 0x8005ACA0: lbu         $v0, 0x1FE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8005ACA4: nop

L_8005ACA8:
    // 0x8005ACA8: bne         $t3, $v0, L_8005AD24
    if (ctx->r11 != ctx->r2) {
        // 0x8005ACAC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005AD24;
    }
    // 0x8005ACAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005ACB0: lbu         $t5, 0x1FF($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8005ACB4: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8005ACB8: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8005ACBC: bgez        $t5, L_8005ACD4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8005ACC0: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8005ACD4;
    }
    // 0x8005ACC0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005ACC4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8005ACC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005ACCC: nop

    // 0x8005ACD0: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8005ACD4:
    // 0x8005ACD4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005ACD8: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8005ACDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005ACE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005ACE4: div.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8005ACE8: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8005ACEC: sub.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8005ACF0: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x8005ACF4: lh          $t6, 0x204($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X204);
    // 0x8005ACF8: nop

    // 0x8005ACFC: blez        $t6, L_8005AD14
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8005AD00: nop
    
            goto L_8005AD14;
    }
    // 0x8005AD00: nop

    // 0x8005AD04: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8005AD08: nop

    // 0x8005AD0C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8005AD10: swc1        $f6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f6.u32l;
L_8005AD14:
    // 0x8005AD14: sw          $t8, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = ctx->r24;
    // 0x8005AD18: lbu         $v0, 0x1FE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8005AD1C: nop

    // 0x8005AD20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8005AD24:
    // 0x8005AD24: bne         $v0, $at, L_8005ADE4
    if (ctx->r2 != ctx->r1) {
        // 0x8005AD28: nop
    
            goto L_8005ADE4;
    }
    // 0x8005AD28: nop

    // 0x8005AD2C: lbu         $t7, 0x1FF($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8005AD30: nop

    // 0x8005AD34: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x8005AD38: jal         0x80070A04
    // 0x8005AD3C: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    sins_f(rdram, ctx);
        goto after_10;
    // 0x8005AD3C: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_10:
    // 0x8005AD40: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x8005AD44: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8005AD48: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8005AD4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005AD50: lwc1        $f2, 0x84($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8005AD54: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8005AD58: lwc1        $f18, 0xAC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8005AD5C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8005AD60: lbu         $t6, 0x1FF($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8005AD64: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8005AD68: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x8005AD6C: cvt.d.s     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f12.d = CVT_D_S(ctx->f18.fl);
    // 0x8005AD70: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8005AD74: mul.d       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f14.d);
    // 0x8005AD78: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8005AD7C: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8005AD80: mul.d       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x8005AD84: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8005AD88: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8005AD8C: swc1        $f18, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f18.u32l;
    // 0x8005AD90: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x8005AD94: jal         0x80070A38
    // 0x8005AD98: swc1        $f13, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    coss_f(rdram, ctx);
        goto after_11;
    // 0x8005AD98: swc1        $f13, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    after_11:
    // 0x8005AD9C: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x8005ADA0: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8005ADA4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8005ADA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005ADAC: lwc1        $f2, 0x88($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8005ADB0: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8005ADB4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8005ADB8: lwc1        $f13, 0x40($sp)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8005ADBC: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005ADC0: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8005ADC4: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8005ADC8: mul.d       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f14.d);
    // 0x8005ADCC: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8005ADD0: mul.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x8005ADD4: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x8005ADD8: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8005ADDC: b           L_8005AE34
    // 0x8005ADE0: swc1        $f18, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f18.u32l;
        goto L_8005AE34;
    // 0x8005ADE0: swc1        $f18, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f18.u32l;
L_8005ADE4:
    // 0x8005ADE4: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8005ADE8: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x8005ADEC: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8005ADF0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8005ADF4: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8005ADF8: mul.d       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f14.d);
    // 0x8005ADFC: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8005AE00: nop

    // 0x8005AE04: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x8005AE08: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8005AE0C: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x8005AE10: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x8005AE14: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x8005AE18: sub.d       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f0.d - ctx->f6.d;
    // 0x8005AE1C: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x8005AE20: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8005AE24: swc1        $f10, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f10.u32l;
    // 0x8005AE28: sub.d       $f18, $f2, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f2.d - ctx->f6.d;
    // 0x8005AE2C: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8005AE30: swc1        $f10, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f10.u32l;
L_8005AE34:
    // 0x8005AE34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005AE38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005AE3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AE40: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x8005AE44: jal         0x8001E2D0
    // 0x8005AE48: swc1        $f8, -0x2510($at)
    MEM_W(-0X2510, ctx->r1) = ctx->f8.u32l;
    get_misc_asset(rdram, ctx);
        goto after_12;
    // 0x8005AE48: swc1        $f8, -0x2510($at)
    MEM_W(-0X2510, ctx->r1) = ctx->f8.u32l;
    after_12:
    // 0x8005AE4C: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AE50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AE54: sw          $v0, -0x251C($at)
    MEM_W(-0X251C, ctx->r1) = ctx->r2;
    // 0x8005AE58: lw          $t5, 0x40($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X40);
    // 0x8005AE5C: nop

    // 0x8005AE60: lbu         $a0, 0x5D($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X5D);
    // 0x8005AE64: jal         0x8001E2D0
    // 0x8005AE68: nop

    get_misc_asset(rdram, ctx);
        goto after_13;
    // 0x8005AE68: nop

    after_13:
    // 0x8005AE6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AE70: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AE74: sw          $v0, -0x2518($at)
    MEM_W(-0X2518, ctx->r1) = ctx->r2;
    // 0x8005AE78: lwc1        $f4, 0x20($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8005AE7C: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8005AE80: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005AE84: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005AE88: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005AE8C: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x8005AE90: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005AE94: bc1f        L_8005AED4
    if (!c1cs) {
        // 0x8005AE98: nop
    
            goto L_8005AED4;
    }
    // 0x8005AE98: nop

    // 0x8005AE9C: lb          $t8, 0x1E2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1E2);
    // 0x8005AEA0: nop

    // 0x8005AEA4: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8005AEA8: beq         $at, $zero, L_8005AED0
    if (ctx->r1 == 0) {
        // 0x8005AEAC: nop
    
            goto L_8005AED0;
    }
    // 0x8005AEAC: nop

    // 0x8005AEB0: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8005AEB4: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8005AEB8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005AEBC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8005AEC0: c.eq.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d == ctx->f4.d;
    // 0x8005AEC4: nop

    // 0x8005AEC8: bc1t        L_8005AED4
    if (c1cs) {
        // 0x8005AECC: nop
    
            goto L_8005AED4;
    }
    // 0x8005AECC: nop

L_8005AED0:
    // 0x8005AED0: sb          $zero, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = 0;
L_8005AED4:
    // 0x8005AED4: lb          $t7, 0x175($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X175);
    // 0x8005AED8: nop

    // 0x8005AEDC: beq         $t7, $zero, L_8005AEF8
    if (ctx->r15 == 0) {
        // 0x8005AEE0: nop
    
            goto L_8005AEF8;
    }
    // 0x8005AEE0: nop

    // 0x8005AEE4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AEE8: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x8005AEEC: jal         0x80056E6C
    // 0x8005AEF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_activate_magnet(rdram, ctx);
        goto after_14;
    // 0x8005AEF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_14:
    // 0x8005AEF4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005AEF8:
    // 0x8005AEF8: lb          $t9, 0x1D6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D6);
    // 0x8005AEFC: nop

    // 0x8005AF00: beq         $t3, $t9, L_8005AF24
    if (ctx->r11 == ctx->r25) {
        // 0x8005AF04: lw          $t5, 0xA0($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA0);
            goto L_8005AF24;
    }
    // 0x8005AF04: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AF08: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005AF0C: sb          $zero, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = 0;
    // 0x8005AF10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AF14: swc1        $f6, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f6.u32l;
    // 0x8005AF18: b           L_8005AF44
    // 0x8005AF1C: sb          $zero, -0x24D2($at)
    MEM_B(-0X24D2, ctx->r1) = 0;
        goto L_8005AF44;
    // 0x8005AF1C: sb          $zero, -0x24D2($at)
    MEM_B(-0X24D2, ctx->r1) = 0;
    // 0x8005AF20: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
L_8005AF24:
    // 0x8005AF24: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8005AF28: lh          $a0, 0x2E($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X2E);
    // 0x8005AF2C: lw          $a1, 0xC($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC);
    // 0x8005AF30: lw          $a2, 0x14($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X14);
    // 0x8005AF34: jal         0x8002B134
    // 0x8005AF38: addiu       $a3, $a3, -0x24D0
    ctx->r7 = ADD32(ctx->r7, -0X24D0);
    func_8002B0F4(rdram, ctx);
        goto after_15;
    // 0x8005AF38: addiu       $a3, $a3, -0x24D0
    ctx->r7 = ADD32(ctx->r7, -0X24D0);
    after_15:
    // 0x8005AF3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AF40: sb          $v0, -0x24D2($at)
    MEM_B(-0X24D2, ctx->r1) = ctx->r2;
L_8005AF44:
    // 0x8005AF44: jal         0x8002AD08
    // 0x8005AF48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_collision_mode(rdram, ctx);
        goto after_16;
    // 0x8005AF48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x8005AF4C: lw          $t6, 0x148($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X148);
    // 0x8005AF50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005AF54: bne         $t6, $zero, L_8005AF7C
    if (ctx->r14 != 0) {
        // 0x8005AF58: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8005AF7C;
    }
    // 0x8005AF58: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005AF5C: addiu       $t0, $t0, -0x2540
    ctx->r8 = ADD32(ctx->r8, -0X2540);
    // 0x8005AF60: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8005AF64: nop

    // 0x8005AF68: bne         $t8, $zero, L_8005AF7C
    if (ctx->r24 != 0) {
        // 0x8005AF6C: nop
    
            goto L_8005AF7C;
    }
    // 0x8005AF6C: nop

    // 0x8005AF70: lh          $t7, 0x204($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X204);
    // 0x8005AF74: nop

    // 0x8005AF78: blez        $t7, L_8005AFB4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005AF7C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005AFB4;
    }
L_8005AF7C:
    // 0x8005AF7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AF80: sw          $zero, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = 0;
    // 0x8005AF84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AF88: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005AF8C: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
    // 0x8005AF90: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005AF94: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005AF98: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8005AF9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AFA0: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005AFA4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005AFA8: sw          $zero, -0x2550($at)
    MEM_W(-0X2550, ctx->r1) = 0;
    // 0x8005AFAC: addiu       $t0, $t0, -0x2540
    ctx->r8 = ADD32(ctx->r8, -0X2540);
    // 0x8005AFB0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8005AFB4:
    // 0x8005AFB4: lbu         $t9, 0x1D6($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1D6);
    // 0x8005AFB8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005AFBC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005AFC0: sltiu       $at, $t9, 0xE
    ctx->r1 = ctx->r25 < 0XE ? 1 : 0;
    // 0x8005AFC4: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005AFC8: beq         $at, $zero, L_8005B21C
    if (ctx->r1 == 0) {
        // 0x8005AFCC: addiu       $v0, $v0, -0x2554
        ctx->r2 = ADD32(ctx->r2, -0X2554);
            goto L_8005B21C;
    }
    // 0x8005AFCC: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005AFD0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005AFD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005AFD8: addu        $at, $at, $t9
    gpr jr_addend_8005AFE4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8005AFDC: lw          $t9, 0x6EF8($at)
    ctx->r25 = ADD32(ctx->r1, 0X6EF8);
    // 0x8005AFE0: nop

    // 0x8005AFE4: jr          $t9
    // 0x8005AFE8: nop

    switch (jr_addend_8005AFE4 >> 2) {
        case 0: goto L_8005AFEC; break;
        case 1: goto L_8005B044; break;
        case 2: goto L_8005B070; break;
        case 3: goto L_8005B09C; break;
        case 4: goto L_8005B018; break;
        case 5: goto L_8005B0C8; break;
        case 6: goto L_8005B100; break;
        case 7: goto L_8005B138; break;
        case 8: goto L_8005B138; break;
        case 9: goto L_8005B21C; break;
        case 10: goto L_8005B09C; break;
        case 11: goto L_8005B178; break;
        case 12: goto L_8005B1B0; break;
        case 13: goto L_8005B1E8; break;
        default: switch_error(__func__, 0x8005AFE4, 0x800E6EF8);
    }
    // 0x8005AFE8: nop

L_8005AFEC:
    // 0x8005AFEC: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005AFF0: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005AFF4: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AFF8: jal         0x8004F834
    // 0x8005AFFC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8004F7F4(rdram, ctx);
        goto after_17;
    // 0x8005AFFC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_17:
    // 0x8005B000: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B004: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B008: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B00C: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B010: b           L_8005B21C
    // 0x8005B014: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B014: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B018:
    // 0x8005B018: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B01C: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B020: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B024: jal         0x8004CC60
    // 0x8005B028: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8004CC20(rdram, ctx);
        goto after_18;
    // 0x8005B028: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_18:
    // 0x8005B02C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B030: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B034: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B038: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B03C: b           L_8005B21C
    // 0x8005B040: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B040: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B044:
    // 0x8005B044: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B048: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B04C: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B050: jal         0x80046564
    // 0x8005B054: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80046524(rdram, ctx);
        goto after_19;
    // 0x8005B054: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_19:
    // 0x8005B058: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B05C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B060: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B064: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B068: b           L_8005B21C
    // 0x8005B06C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B06C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B070:
    // 0x8005B070: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B074: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B078: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B07C: jal         0x800497D4
    // 0x8005B080: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80049794(rdram, ctx);
        goto after_20;
    // 0x8005B080: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_20:
    // 0x8005B084: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B088: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B08C: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B090: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B094: b           L_8005B21C
    // 0x8005B098: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B098: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B09C:
    // 0x8005B09C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B0A0: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B0A4: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B0A8: jal         0x8004D99C
    // 0x8005B0AC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_carpet(rdram, ctx);
        goto after_21;
    // 0x8005B0AC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_21:
    // 0x8005B0B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B0B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B0B8: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B0BC: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B0C0: b           L_8005B21C
    // 0x8005B0C4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B0C4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B0C8:
    // 0x8005B0C8: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B0CC: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B0D0: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B0D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B0D8: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B0DC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005B0E0: jal         0x8005C504
    // 0x8005B0E4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_tricky(rdram, ctx);
        goto after_22;
    // 0x8005B0E4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_22:
    // 0x8005B0E8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B0EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B0F0: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B0F4: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B0F8: b           L_8005B21C
    // 0x8005B0FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B0FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B100:
    // 0x8005B100: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B104: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B108: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B10C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B110: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B114: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005B118: jal         0x8005D270
    // 0x8005B11C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_bluey(rdram, ctx);
        goto after_23;
    // 0x8005B11C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_23:
    // 0x8005B120: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B124: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B128: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B12C: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B130: b           L_8005B21C
    // 0x8005B134: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B134: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B138:
    // 0x8005B138: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8005B13C: addiu       $t5, $t5, -0x254C
    ctx->r13 = ADD32(ctx->r13, -0X254C);
    // 0x8005B140: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B144: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B148: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B14C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005B150: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B154: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B158: jal         0x8005D9C0
    // 0x8005B15C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_smokey(rdram, ctx);
        goto after_24;
    // 0x8005B15C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_24:
    // 0x8005B160: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B164: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B168: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B16C: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B170: b           L_8005B21C
    // 0x8005B174: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B174: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B178:
    // 0x8005B178: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B17C: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B180: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B184: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B188: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B18C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005B190: jal         0x8005E660
    // 0x8005B194: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_bubbler(rdram, ctx);
        goto after_25;
    // 0x8005B194: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_25:
    // 0x8005B198: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B19C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B1A0: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B1A4: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B1A8: b           L_8005B21C
    // 0x8005B1AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B1AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B1B0:
    // 0x8005B1B0: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B1B4: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B1B8: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B1BC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B1C0: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B1C4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005B1C8: jal         0x8005EC30
    // 0x8005B1CC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_wizpig(rdram, ctx);
        goto after_26;
    // 0x8005B1CC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_26:
    // 0x8005B1D0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B1D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B1D8: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B1DC: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B1E0: b           L_8005B21C
    // 0x8005B1E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B21C;
    // 0x8005B1E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B1E8:
    // 0x8005B1E8: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B1EC: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B1F0: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B1F4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B1F8: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B1FC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005B200: jal         0x8005F4B0
    // 0x8005B204: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_rocket(rdram, ctx);
        goto after_27;
    // 0x8005B204: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_27:
    // 0x8005B208: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B20C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B210: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x8005B214: addiu       $v1, $v1, -0x2558
    ctx->r3 = ADD32(ctx->r3, -0X2558);
    // 0x8005B218: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B21C:
    // 0x8005B21C: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x8005B220: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B224: beq         $t6, $t3, L_8005B240
    if (ctx->r14 == ctx->r11) {
        // 0x8005B228: nop
    
            goto L_8005B240;
    }
    // 0x8005B228: nop

    // 0x8005B22C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8005B230: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x8005B234: lw          $a3, 0xA8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B238: jal         0x800050D0
    // 0x8005B23C: nop

    racer_sound_update(rdram, ctx);
        goto after_28;
    // 0x8005B23C: nop

    after_28:
L_8005B240:
    // 0x8005B240: lwc1        $f18, 0xA8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8005B244: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8005B248: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    // 0x8005B24C: lb          $t8, 0x192($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X192);
    // 0x8005B250: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B254: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    // 0x8005B258: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8005B25C: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8005B260: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x8005B264: addiu       $t7, $s0, 0xA8
    ctx->r15 = ADD32(ctx->r16, 0XA8);
    // 0x8005B268: addiu       $t9, $s0, 0x1C8
    ctx->r25 = ADD32(ctx->r16, 0X1C8);
    // 0x8005B26C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8005B270: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8005B274: jal         0x80018618
    // 0x8005B278: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    checkpoint_is_passed(rdram, ctx);
        goto after_29;
    // 0x8005B278: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_29:
    // 0x8005B27C: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x8005B280: bne         $v0, $at, L_8005B29C
    if (ctx->r2 != ctx->r1) {
        // 0x8005B284: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_8005B29C;
    }
    // 0x8005B284: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8005B288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005B28C: jal         0x8005C410
    // 0x8005B290: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    racer_update_progress(rdram, ctx);
        goto after_30;
    // 0x8005B290: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    after_30:
    // 0x8005B294: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x8005B298: nop

L_8005B29C:
    // 0x8005B29C: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8005B2A0: lbu         $a1, 0x1C8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C8);
    // 0x8005B2A4: jal         0x8001BA50
    // 0x8005B2A8: sw          $t2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r10;
    find_next_checkpoint_node(rdram, ctx);
        goto after_31;
    // 0x8005B2A8: sw          $t2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r10;
    after_31:
    // 0x8005B2AC: lb          $t5, 0x1CA($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005B2B0: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x8005B2B4: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8005B2B8: lb          $t8, 0x36($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X36);
    // 0x8005B2BC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005B2C0: bne         $t8, $at, L_8005B2E0
    if (ctx->r24 != ctx->r1) {
        // 0x8005B2C4: nop
    
            goto L_8005B2E0;
    }
    // 0x8005B2C4: nop

    // 0x8005B2C8: lb          $t9, 0x1E5($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E5);
    // 0x8005B2CC: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8005B2D0: beq         $t9, $zero, L_8005B2E0
    if (ctx->r25 == 0) {
        // 0x8005B2D4: sb          $t7, 0x201($s0)
        MEM_B(0X201, ctx->r16) = ctx->r15;
            goto L_8005B2E0;
    }
    // 0x8005B2D4: sb          $t7, 0x201($s0)
    MEM_B(0X201, ctx->r16) = ctx->r15;
    // 0x8005B2D8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005B2DC: sb          $t5, 0x1C8($s0)
    MEM_B(0X1C8, ctx->r16) = ctx->r13;
L_8005B2E0:
    // 0x8005B2E0: lb          $t6, 0x1CA($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005B2E4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8005B2E8: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x8005B2EC: lb          $v1, 0x36($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X36);
    // 0x8005B2F0: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8005B2F4: bne         $v1, $at, L_8005B31C
    if (ctx->r3 != ctx->r1) {
        // 0x8005B2F8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8005B31C;
    }
    // 0x8005B2F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005B2FC: lb          $t9, 0x4B($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X4B);
    // 0x8005B300: lb          $t6, 0x1CA($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005B304: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8005B308: sb          $t5, 0x193($s0)
    MEM_B(0X193, ctx->r16) = ctx->r13;
    // 0x8005B30C: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x8005B310: lb          $v1, 0x36($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X36);
    // 0x8005B314: nop

    // 0x8005B318: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_8005B31C:
    // 0x8005B31C: bne         $v1, $at, L_8005B360
    if (ctx->r3 != ctx->r1) {
        // 0x8005B320: nop
    
            goto L_8005B360;
    }
    // 0x8005B320: nop

    // 0x8005B324: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005B328: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x8005B32C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005B330: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005B334: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8005B338: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8005B33C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B340: bc1f        L_8005B360
    if (!c1cs) {
        // 0x8005B344: nop
    
            goto L_8005B360;
    }
    // 0x8005B344: nop

    // 0x8005B348: lwc1        $f7, 0x6F30($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6F30);
    // 0x8005B34C: lwc1        $f6, 0x6F34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6F34);
    // 0x8005B350: nop

    // 0x8005B354: mul.d       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x8005B358: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x8005B35C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_8005B360:
    // 0x8005B360: bne         $t2, $zero, L_8005B414
    if (ctx->r10 != 0) {
        // 0x8005B364: nop
    
            goto L_8005B414;
    }
    // 0x8005B364: nop

    // 0x8005B368: lb          $t7, 0x1CA($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005B36C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005B370: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x8005B374: lb          $t5, 0x36($t9)
    ctx->r13 = MEM_B(ctx->r25, 0X36);
    // 0x8005B378: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005B37C: bne         $t5, $at, L_8005B388
    if (ctx->r13 != ctx->r1) {
        // 0x8005B380: nop
    
            goto L_8005B388;
    }
    // 0x8005B380: nop

    // 0x8005B384: sb          $t6, 0x1C8($s0)
    MEM_B(0X1C8, ctx->r16) = ctx->r14;
L_8005B388:
    // 0x8005B388: jal         0x8001BA98
    // 0x8005B38C: nop

    get_checkpoint_count(rdram, ctx);
        goto after_32;
    // 0x8005B38C: nop

    after_32:
    // 0x8005B390: lb          $t8, 0x192($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X192);
    // 0x8005B394: nop

    // 0x8005B398: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8005B39C: sb          $t7, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r15;
    // 0x8005B3A0: lb          $t9, 0x192($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X192);
    // 0x8005B3A4: nop

    // 0x8005B3A8: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005B3AC: bne         $at, $zero, L_8005B3E0
    if (ctx->r1 != 0) {
        // 0x8005B3B0: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_8005B3E0;
    }
    // 0x8005B3B0: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8005B3B4: lh          $t5, 0x190($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X190);
    // 0x8005B3B8: sb          $zero, 0x192($s0)
    MEM_B(0X192, ctx->r16) = 0;
    // 0x8005B3BC: blez        $t5, L_8005B3E0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8005B3C0: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_8005B3E0;
    }
    // 0x8005B3C0: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8005B3C4: lb          $v1, 0x193($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X193);
    // 0x8005B3C8: nop

    // 0x8005B3CC: slti        $at, $v1, 0x78
    ctx->r1 = SIGNED(ctx->r3) < 0X78 ? 1 : 0;
    // 0x8005B3D0: beq         $at, $zero, L_8005B3DC
    if (ctx->r1 == 0) {
        // 0x8005B3D4: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_8005B3DC;
    }
    // 0x8005B3D4: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8005B3D8: sb          $t6, 0x193($s0)
    MEM_B(0X193, ctx->r16) = ctx->r14;
L_8005B3DC:
    // 0x8005B3DC: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
L_8005B3E0:
    // 0x8005B3E0: lh          $v1, 0x190($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X190);
    // 0x8005B3E4: lb          $t7, 0x4B($t8)
    ctx->r15 = MEM_B(ctx->r24, 0X4B);
    // 0x8005B3E8: addiu       $t8, $zero, 0x2710
    ctx->r24 = ADD32(0, 0X2710);
    // 0x8005B3EC: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x8005B3F0: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B3F4: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8005B3F8: mflo        $t5
    ctx->r13 = lo;
    // 0x8005B3FC: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8005B400: beq         $at, $zero, L_8005B40C
    if (ctx->r1 == 0) {
        // 0x8005B404: nop
    
            goto L_8005B40C;
    }
    // 0x8005B404: nop

    // 0x8005B408: sh          $t6, 0x190($s0)
    MEM_H(0X190, ctx->r16) = ctx->r14;
L_8005B40C:
    // 0x8005B40C: b           L_8005B448
    // 0x8005B410: sh          $t8, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r24;
        goto L_8005B448;
    // 0x8005B410: sh          $t8, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r24;
L_8005B414:
    // 0x8005B414: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8005B418: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005B41C: bne         $t7, $at, L_8005B444
    if (ctx->r15 != ctx->r1) {
        // 0x8005B420: nop
    
            goto L_8005B444;
    }
    // 0x8005B420: nop

    // 0x8005B424: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8005B428: lwc1        $f10, 0xA8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8005B42C: nop

    // 0x8005B430: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8005B434: nop

    // 0x8005B438: bc1f        L_8005B444
    if (!c1cs) {
        // 0x8005B43C: nop
    
            goto L_8005B444;
    }
    // 0x8005B43C: nop

    // 0x8005B440: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
L_8005B444:
    // 0x8005B444: sh          $t2, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r10;
L_8005B448:
    // 0x8005B448: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B44C: nop

    // 0x8005B450: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8005B454: nop

    // 0x8005B458: swc1        $f4, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
    // 0x8005B45C: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B460: nop

    // 0x8005B464: lwc1        $f6, 0x10($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X10);
    // 0x8005B468: nop

    // 0x8005B46C: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x8005B470: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B474: nop

    // 0x8005B478: lwc1        $f18, 0x14($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8005B47C: b           L_8005B4BC
    // 0x8005B480: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
        goto L_8005B4BC;
    // 0x8005B480: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
    // 0x8005B484: lw          $a3, 0xAC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XAC);
L_8005B488:
    // 0x8005B488: jal         0x8005B884
    // 0x8005B48C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8005B818(rdram, ctx);
        goto after_33;
    // 0x8005B48C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_33:
    // 0x8005B490: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x8005B494: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005B498: beq         $t8, $t3, L_8005B4BC
    if (ctx->r24 == ctx->r11) {
        // 0x8005B49C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8005B4BC;
    }
    // 0x8005B49C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005B4A0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8005B4A4: lw          $a2, -0x2558($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2558);
    // 0x8005B4A8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B4AC: lw          $a1, -0x2554($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2554);
    // 0x8005B4B0: lw          $a3, 0xA8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B4B4: jal         0x800050D0
    // 0x8005B4B8: nop

    racer_sound_update(rdram, ctx);
        goto after_34;
    // 0x8005B4B8: nop

    after_34:
L_8005B4BC:
    // 0x8005B4BC: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8005B4C0: lb          $t7, 0x175($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X175);
    // 0x8005B4C4: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x8005B4C8: bne         $t7, $zero, L_8005B4FC
    if (ctx->r15 != 0) {
        // 0x8005B4CC: lw          $t9, 0xA8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA8);
            goto L_8005B4FC;
    }
    // 0x8005B4CC: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B4D0: lw          $a0, 0x178($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X178);
    // 0x8005B4D4: nop

    // 0x8005B4D8: beq         $a0, $zero, L_8005B4FC
    if (ctx->r4 == 0) {
        // 0x8005B4DC: lw          $t9, 0xA8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA8);
            goto L_8005B4FC;
    }
    // 0x8005B4DC: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B4E0: swc1        $f13, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    // 0x8005B4E4: jal         0x8000488C
    // 0x8005B4E8: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    sndp_stop(rdram, ctx);
        goto after_35;
    // 0x8005B4E8: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    after_35:
    // 0x8005B4EC: lwc1        $f13, 0x40($sp)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8005B4F0: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005B4F4: sw          $zero, 0x178($s0)
    MEM_W(0X178, ctx->r16) = 0;
    // 0x8005B4F8: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
L_8005B4FC:
    // 0x8005B4FC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B500: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8005B504: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x8005B508: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x8005B50C: swc1        $f13, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    // 0x8005B510: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x8005B514: jal         0x80018D14
    // 0x8005B518: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80018CE0(rdram, ctx);
        goto after_36;
    // 0x8005B518: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_36:
    // 0x8005B51C: lb          $a2, 0x188($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X188);
    // 0x8005B520: lwc1        $f13, 0x40($sp)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8005B524: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005B528: blez        $a2, L_8005B550
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8005B52C: nop
    
            goto L_8005B550;
    }
    // 0x8005B52C: nop

    // 0x8005B530: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B534: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005B538: swc1        $f13, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    // 0x8005B53C: jal         0x80057720
    // 0x8005B540: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    drop_bananas(rdram, ctx);
        goto after_37;
    // 0x8005B540: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    after_37:
    // 0x8005B544: lwc1        $f13, 0x40($sp)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8005B548: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005B54C: nop

L_8005B550:
    // 0x8005B550: lw          $t5, 0x148($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X148);
    // 0x8005B554: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005B558: beq         $t5, $zero, L_8005B570
    if (ctx->r13 == 0) {
        // 0x8005B55C: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8005B570;
    }
    // 0x8005B55C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005B560: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005B564: sw          $zero, 0x148($s0)
    MEM_W(0X148, ctx->r16) = 0;
    // 0x8005B568: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x8005B56C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
L_8005B570:
    // 0x8005B570: lwc1        $f14, 0x90($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X90);
    // 0x8005B574: lwc1        $f0, 0x8C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8005B578: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005B57C: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x8005B580: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B584: bc1f        L_8005B59C
    if (!c1cs) {
        // 0x8005B588: sub.s       $f10, $f14, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
            goto L_8005B59C;
    }
    // 0x8005B588: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8005B58C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B590: lwc1        $f2, 0x6F38($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6F38);
    // 0x8005B594: b           L_8005B5A8
    // 0x8005B598: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
        goto L_8005B5A8;
    // 0x8005B598: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_8005B59C:
    // 0x8005B59C: lwc1        $f2, 0x6F3C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6F3C);
    // 0x8005B5A0: nop

    // 0x8005B5A4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_8005B5A8:
    // 0x8005B5A8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005B5AC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005B5B0: mul.d       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005B5B4: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8005B5B8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8005B5BC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8005B5C0: add.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d + ctx->f8.d;
    // 0x8005B5C4: mul.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x8005B5C8: add.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f6.d + ctx->f4.d;
    // 0x8005B5CC: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x8005B5D0: bc1f        L_8005B5F0
    if (!c1cs) {
        // 0x8005B5D4: swc1        $f8, 0x8C($s0)
        MEM_W(0X8C, ctx->r16) = ctx->f8.u32l;
            goto L_8005B5F0;
    }
    // 0x8005B5D4: swc1        $f8, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f8.u32l;
    // 0x8005B5D8: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8005B5DC: nop

    // 0x8005B5E0: c.le.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl <= ctx->f14.fl;
    // 0x8005B5E4: nop

    // 0x8005B5E8: bc1t        L_8005B618
    if (c1cs) {
        // 0x8005B5EC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8005B618;
    }
    // 0x8005B5EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8005B5F0:
    // 0x8005B5F0: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8005B5F4: nop

    // 0x8005B5F8: bc1f        L_8005B624
    if (!c1cs) {
        // 0x8005B5FC: nop
    
            goto L_8005B624;
    }
    // 0x8005B5FC: nop

    // 0x8005B600: lwc1        $f6, 0x8C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8005B604: nop

    // 0x8005B608: c.le.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl <= ctx->f6.fl;
    // 0x8005B60C: nop

    // 0x8005B610: bc1f        L_8005B624
    if (!c1cs) {
        // 0x8005B614: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8005B624;
    }
    // 0x8005B614: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8005B618:
    // 0x8005B618: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005B61C: swc1        $f14, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f14.u32l;
    // 0x8005B620: swc1        $f4, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f4.u32l;
L_8005B624:
    // 0x8005B624: lh          $v1, 0x16A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X16A);
    // 0x8005B628: lh          $t6, 0x16C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X16C);
    // 0x8005B62C: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B630: subu        $t8, $t6, $v1
    ctx->r24 = SUB32(ctx->r14, ctx->r3);
    // 0x8005B634: multu       $t8, $t7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B638: mflo        $t2
    ctx->r10 = lo;
    // 0x8005B63C: sra         $t9, $t2, 3
    ctx->r25 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8005B640: slti        $at, $t9, 0x801
    ctx->r1 = SIGNED(ctx->r25) < 0X801 ? 1 : 0;
    // 0x8005B644: bne         $at, $zero, L_8005B650
    if (ctx->r1 != 0) {
        // 0x8005B648: or          $t2, $t9, $zero
        ctx->r10 = ctx->r25 | 0;
            goto L_8005B650;
    }
    // 0x8005B648: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
    // 0x8005B64C: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
L_8005B650:
    // 0x8005B650: slti        $at, $t2, -0x800
    ctx->r1 = SIGNED(ctx->r10) < -0X800 ? 1 : 0;
    // 0x8005B654: beq         $at, $zero, L_8005B660
    if (ctx->r1 == 0) {
        // 0x8005B658: nop
    
            goto L_8005B660;
    }
    // 0x8005B658: nop

    // 0x8005B65C: addiu       $t2, $zero, -0x800
    ctx->r10 = ADD32(0, -0X800);
L_8005B660:
    // 0x8005B660: lh          $v0, -0x2F3C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2F3C);
    // 0x8005B664: addu        $t6, $v1, $t2
    ctx->r14 = ADD32(ctx->r3, ctx->r10);
    // 0x8005B668: beq         $v0, $zero, L_8005B678
    if (ctx->r2 == 0) {
        // 0x8005B66C: addu        $t5, $v1, $v0
        ctx->r13 = ADD32(ctx->r3, ctx->r2);
            goto L_8005B678;
    }
    // 0x8005B66C: addu        $t5, $v1, $v0
    ctx->r13 = ADD32(ctx->r3, ctx->r2);
    // 0x8005B670: b           L_8005B67C
    // 0x8005B674: sh          $t5, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r13;
        goto L_8005B67C;
    // 0x8005B674: sh          $t5, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r13;
L_8005B678:
    // 0x8005B678: sh          $t6, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r14;
L_8005B67C:
    // 0x8005B67C: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8005B680: nop

    // 0x8005B684: blez        $v0, L_8005B74C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005B688: slti        $at, $v0, 0x3D
        ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
            goto L_8005B74C;
    }
    // 0x8005B688: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x8005B68C: bne         $at, $zero, L_8005B708
    if (ctx->r1 != 0) {
        // 0x8005B690: nop
    
            goto L_8005B708;
    }
    // 0x8005B690: nop

    // 0x8005B694: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    // 0x8005B698: nop

    // 0x8005B69C: beq         $a0, $zero, L_8005B6CC
    if (ctx->r4 == 0) {
        // 0x8005B6A0: nop
    
            goto L_8005B6CC;
    }
    // 0x8005B6A0: nop

    // 0x8005B6A4: lw          $v0, 0xA0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B6A8: nop

    // 0x8005B6AC: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x8005B6B0: lw          $a2, 0x10($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10);
    // 0x8005B6B4: lw          $a3, 0x14($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X14);
    // 0x8005B6B8: jal         0x800096D8
    // 0x8005B6BC: nop

    audspat_point_set_position(rdram, ctx);
        goto after_38;
    // 0x8005B6BC: nop

    after_38:
    // 0x8005B6C0: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8005B6C4: b           L_8005B72C
    // 0x8005B6C8: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
        goto L_8005B72C;
    // 0x8005B6C8: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
L_8005B6CC:
    // 0x8005B6CC: lw          $t8, 0x118($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X118);
    // 0x8005B6D0: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B6D4: beq         $t8, $zero, L_8005B728
    if (ctx->r24 == 0) {
        // 0x8005B6D8: addiu       $a0, $zero, 0x9F
        ctx->r4 = ADD32(0, 0X9F);
            goto L_8005B728;
    }
    // 0x8005B6D8: addiu       $a0, $zero, 0x9F
    ctx->r4 = ADD32(0, 0X9F);
    // 0x8005B6DC: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    // 0x8005B6E0: lw          $a2, 0x10($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X10);
    // 0x8005B6E4: lw          $a3, 0x14($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X14);
    // 0x8005B6E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005B6EC: addiu       $t5, $s0, 0x17C
    ctx->r13 = ADD32(ctx->r16, 0X17C);
    // 0x8005B6F0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005B6F4: jal         0x80009558
    // 0x8005B6F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_39;
    // 0x8005B6F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_39:
    // 0x8005B6FC: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8005B700: b           L_8005B72C
    // 0x8005B704: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
        goto L_8005B72C;
    // 0x8005B704: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
L_8005B708:
    // 0x8005B708: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    // 0x8005B70C: nop

    // 0x8005B710: beq         $a0, $zero, L_8005B72C
    if (ctx->r4 == 0) {
        // 0x8005B714: lw          $t6, 0xA8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XA8);
            goto L_8005B72C;
    }
    // 0x8005B714: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B718: jal         0x800096F8
    // 0x8005B71C: nop

    audspat_point_stop(rdram, ctx);
        goto after_40;
    // 0x8005B71C: nop

    after_40:
    // 0x8005B720: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8005B724: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_8005B728:
    // 0x8005B728: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
L_8005B72C:
    // 0x8005B72C: nop

    // 0x8005B730: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x8005B734: sh          $t8, 0x18E($s0)
    MEM_H(0X18E, ctx->r16) = ctx->r24;
    // 0x8005B738: lh          $t7, 0x18E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18E);
    // 0x8005B73C: nop

    // 0x8005B740: bgtz        $t7, L_8005B74C
    if (SIGNED(ctx->r15) > 0) {
        // 0x8005B744: nop
    
            goto L_8005B74C;
    }
    // 0x8005B744: nop

    // 0x8005B748: sb          $zero, 0x189($s0)
    MEM_B(0X189, ctx->r16) = 0;
L_8005B74C:
    // 0x8005B74C: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x8005B750: lw          $v0, 0xA0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B754: beq         $a0, $zero, L_8005B770
    if (ctx->r4 == 0) {
        // 0x8005B758: nop
    
            goto L_8005B770;
    }
    // 0x8005B758: nop

    // 0x8005B75C: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x8005B760: lw          $a2, 0x10($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10);
    // 0x8005B764: lw          $a3, 0x14($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X14);
    // 0x8005B768: jal         0x800096D8
    // 0x8005B76C: nop

    audspat_point_set_position(rdram, ctx);
        goto after_41;
    // 0x8005B76C: nop

    after_41:
L_8005B770:
    // 0x8005B770: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005B774: sb          $zero, -0x24FC($at)
    MEM_B(-0X24FC, ctx->r1) = 0;
    // 0x8005B778: lw          $v0, 0x150($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X150);
    // 0x8005B77C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8005B780: beq         $v0, $zero, L_8005B864
    if (ctx->r2 == 0) {
        // 0x8005B784: nop
    
            goto L_8005B864;
    }
    // 0x8005B784: nop

    // 0x8005B788: lw          $t9, -0x2540($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2540);
    // 0x8005B78C: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B790: bne         $t9, $zero, L_8005B864
    if (ctx->r25 != 0) {
        // 0x8005B794: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8005B864;
    }
    // 0x8005B794: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005B798: lwc1        $f18, 0xC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8005B79C: jal         0x8001E2D0
    // 0x8005B7A0: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    get_misc_asset(rdram, ctx);
        goto after_42;
    // 0x8005B7A0: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    after_42:
    // 0x8005B7A4: lb          $t6, 0x3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X3);
    // 0x8005B7A8: lw          $v1, 0xA0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B7AC: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x8005B7B0: lb          $t7, 0x0($t8)
    ctx->r15 = MEM_B(ctx->r24, 0X0);
    // 0x8005B7B4: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8005B7B8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8005B7BC: lw          $t9, 0x150($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X150);
    // 0x8005B7C0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005B7C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B7C8: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8005B7CC: swc1        $f4, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f4.u32l;
    // 0x8005B7D0: lw          $t5, 0x150($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X150);
    // 0x8005B7D4: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8005B7D8: nop

    // 0x8005B7DC: swc1        $f18, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f18.u32l;
    // 0x8005B7E0: lwc1        $f10, 0x6F40($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6F40);
    // 0x8005B7E4: lwc1        $f8, 0x30($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8005B7E8: lw          $t6, 0x150($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X150);
    // 0x8005B7EC: div.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005B7F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B7F4: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x8005B7F8: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8005B7FC: lwc1        $f8, 0x6F4C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6F4C);
    // 0x8005B800: lwc1        $f9, 0x6F48($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6F48);
    // 0x8005B804: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8005B808: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x8005B80C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8005B810: bc1f        L_8005B830
    if (!c1cs) {
        // 0x8005B814: nop
    
            goto L_8005B830;
    }
    // 0x8005B814: nop

    // 0x8005B818: lw          $v0, 0x150($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X150);
    // 0x8005B81C: nop

    // 0x8005B820: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x8005B824: nop

    // 0x8005B828: ori         $t7, $t8, 0x4000
    ctx->r15 = ctx->r24 | 0X4000;
    // 0x8005B82C: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
L_8005B830:
    // 0x8005B830: lw          $v0, 0x150($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X150);
    // 0x8005B834: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005B838: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8005B83C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005B840: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8005B844: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8005B848: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005B84C: bc1f        L_8005B860
    if (!c1cs) {
        // 0x8005B850: nop
    
            goto L_8005B860;
    }
    // 0x8005B850: nop

    // 0x8005B854: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005B858: nop

    // 0x8005B85C: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
L_8005B860:
    // 0x8005B860: sw          $zero, 0x150($s0)
    MEM_W(0X150, ctx->r16) = 0;
L_8005B864:
    // 0x8005B864: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8005B868: sb          $t9, 0x1FE($s0)
    MEM_B(0X1FE, ctx->r16) = ctx->r25;
    // 0x8005B86C: jal         0x8004F7BC
    // 0x8005B870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_racer_tail_lights(rdram, ctx);
        goto after_43;
    // 0x8005B870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x8005B874: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B878: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8005B87C: jr          $ra
    // 0x8005B880: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8005B880: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void set_option_text_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D65C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009D660: bne         $a0, $zero, L_8009D6C4
    if (ctx->r4 != 0) {
        // 0x8009D664: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8009D6C4;
    }
    // 0x8009D664: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D668: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    // 0x8009D66C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009D670: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009D674: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009D678: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D67C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D680: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009D684: jal         0x800C5560
    // 0x8009D688: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    set_current_text_colour(rdram, ctx);
        goto after_0;
    // 0x8009D688: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    after_0:
    // 0x8009D68C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009D690: lb          $t8, -0x594($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X594);
    // 0x8009D694: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D698: beq         $t8, $zero, L_8009D6E8
    if (ctx->r24 == 0) {
        // 0x8009D69C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8009D6E8;
    }
    // 0x8009D69C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D6A0: addiu       $t9, $zero, 0x5A
    ctx->r25 = ADD32(0, 0X5A);
    // 0x8009D6A4: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x8009D6A8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8009D6AC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009D6B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009D6B4: jal         0x800C5560
    // 0x8009D6B8: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    set_current_text_colour(rdram, ctx);
        goto after_1;
    // 0x8009D6B8: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    after_1:
    // 0x8009D6BC: b           L_8009D6EC
    // 0x8009D6C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D6EC;
    // 0x8009D6C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D6C4:
    // 0x8009D6C4: addiu       $t1, $zero, 0x5A
    ctx->r9 = ADD32(0, 0X5A);
    // 0x8009D6C8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009D6CC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009D6D0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009D6D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D6D8: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    // 0x8009D6DC: addiu       $a2, $zero, 0xCF
    ctx->r6 = ADD32(0, 0XCF);
    // 0x8009D6E0: jal         0x800C5560
    // 0x8009D6E4: addiu       $a3, $zero, 0xCF
    ctx->r7 = ADD32(0, 0XCF);
    set_current_text_colour(rdram, ctx);
        goto after_2;
    // 0x8009D6E4: addiu       $a3, $zero, 0xCF
    ctx->r7 = ADD32(0, 0XCF);
    after_2:
L_8009D6E8:
    // 0x8009D6E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D6EC:
    // 0x8009D6EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D6F0: sb          $zero, -0x594($at)
    MEM_B(-0X594, ctx->r1) = 0;
    // 0x8009D6F4: jr          $ra
    // 0x8009D6F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009D6F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80075000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075258: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8007525C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80075260: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80075264: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80075268: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8007526C: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80075270: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80075274: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80075278: jal         0x80075B34
    // 0x8007527C: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x8007527C: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    after_0:
    // 0x80075280: beq         $v0, $zero, L_8007529C
    if (ctx->r2 == 0) {
        // 0x80075284: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8007529C;
    }
    // 0x80075284: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80075288: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8007528C: jal         0x80075D44
    // 0x80075290: nop

    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80075290: nop

    after_1:
    // 0x80075294: b           L_80075618
    // 0x80075298: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80075618;
    // 0x80075298: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8007529C:
    // 0x8007529C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800752A0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800752A4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800752A8: addiu       $s1, $zero, 0x1100
    ctx->r17 = ADD32(0, 0X1100);
    // 0x800752AC: addiu       $a2, $a2, 0x7D1C
    ctx->r6 = ADD32(ctx->r6, 0X7D1C);
    // 0x800752B0: addiu       $a1, $a1, 0x7D0C
    ctx->r5 = ADD32(ctx->r5, 0X7D0C);
    // 0x800752B4: jal         0x80076740
    // 0x800752B8: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x800752B8: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    after_2:
    // 0x800752BC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800752C0: bne         $v0, $at, L_80075308
    if (ctx->r2 != ctx->r1) {
        // 0x800752C4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80075308;
    }
    // 0x800752C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800752C8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800752CC: jal         0x80075D44
    // 0x800752D0: nop

    start_reading_controller_data(rdram, ctx);
        goto after_3;
    // 0x800752D0: nop

    after_3:
    // 0x800752D4: lh          $t6, 0x8A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8A);
    // 0x800752D8: lh          $t7, 0x8E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X8E);
    // 0x800752DC: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800752E0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800752E4: lh          $a1, 0x7E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X7E);
    // 0x800752E8: lh          $a2, 0x82($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X82);
    // 0x800752EC: lh          $a3, 0x86($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X86);
    // 0x800752F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800752F4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800752F8: jal         0x80075110
    // 0x800752FC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_80074EB8(rdram, ctx);
        goto after_4;
    // 0x800752FC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_4:
    // 0x80075300: b           L_8007561C
    // 0x80075304: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8007561C;
    // 0x80075304: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80075308:
    // 0x80075308: beq         $v0, $zero, L_80075328
    if (ctx->r2 == 0) {
        // 0x8007530C: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80075328;
    }
    // 0x8007530C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80075310: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80075314: jal         0x80075D44
    // 0x80075318: nop

    start_reading_controller_data(rdram, ctx);
        goto after_5;
    // 0x80075318: nop

    after_5:
    // 0x8007531C: b           L_80075618
    // 0x80075320: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80075618;
    // 0x80075320: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80075324: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
L_80075328:
    // 0x80075328: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8007532C: jal         0x80076B7C
    // 0x80075330: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    get_file_size(rdram, ctx);
        goto after_6;
    // 0x80075330: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_6:
    // 0x80075334: beq         $v0, $zero, L_80075350
    if (ctx->r2 == 0) {
        // 0x80075338: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80075350;
    }
    // 0x80075338: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007533C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80075340: jal         0x80075D44
    // 0x80075344: nop

    start_reading_controller_data(rdram, ctx);
        goto after_7;
    // 0x80075344: nop

    after_7:
    // 0x80075348: b           L_80075618
    // 0x8007534C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80075618;
    // 0x8007534C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80075350:
    // 0x80075350: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80075354: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80075358: jal         0x80070EDC
    // 0x8007535C: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x8007535C: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_8:
    // 0x80075360: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80075364: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80075368: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8007536C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80075370: jal         0x80076868
    // 0x80075374: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_9;
    // 0x80075374: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_9:
    // 0x80075378: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8007537C: jal         0x80075D44
    // 0x80075380: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_10;
    // 0x80075380: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_10:
    // 0x80075384: beq         $s0, $zero, L_8007539C
    if (ctx->r16 == 0) {
        // 0x80075388: lui         $at, 0x4748
        ctx->r1 = S32(0X4748 << 16);
            goto L_8007539C;
    }
    // 0x80075388: lui         $at, 0x4748
    ctx->r1 = S32(0X4748 << 16);
    // 0x8007538C: jal         0x80071380
    // 0x80075390: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_11;
    // 0x80075390: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_11:
    // 0x80075394: b           L_80075618
    // 0x80075398: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80075618;
    // 0x80075398: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8007539C:
    // 0x8007539C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800753A0: ori         $at, $at, 0x5353
    ctx->r1 = ctx->r1 | 0X5353;
    // 0x800753A4: bne         $t9, $at, L_8007560C
    if (ctx->r25 != ctx->r1) {
        // 0x800753A8: addiu       $s0, $zero, 0x9
        ctx->r16 = ADD32(0, 0X9);
            goto L_8007560C;
    }
    // 0x800753A8: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
    // 0x800753AC: addiu       $a2, $s2, 0x4
    ctx->r6 = ADD32(ctx->r18, 0X4);
    // 0x800753B0: lh          $t3, 0x82($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X82);
    // 0x800753B4: lh          $t2, 0x7E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X7E);
    // 0x800753B8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800753BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800753C0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_800753C4:
    // 0x800753C4: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x800753C8: nop

    // 0x800753CC: bne         $t2, $t4, L_800753EC
    if (ctx->r10 != ctx->r12) {
        // 0x800753D0: nop
    
            goto L_800753EC;
    }
    // 0x800753D0: nop

    // 0x800753D4: lbu         $t5, 0x1($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1);
    // 0x800753D8: nop

    // 0x800753DC: bne         $t3, $t5, L_800753EC
    if (ctx->r11 != ctx->r13) {
        // 0x800753E0: nop
    
            goto L_800753EC;
    }
    // 0x800753E0: nop

    // 0x800753E4: b           L_800753FC
    // 0x800753E8: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
        goto L_800753FC;
    // 0x800753E8: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
L_800753EC:
    // 0x800753EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800753F0: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x800753F4: bne         $at, $zero, L_800753C4
    if (ctx->r1 != 0) {
        // 0x800753F8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800753C4;
    }
    // 0x800753F8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800753FC:
    // 0x800753FC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80075400: beq         $t1, $a0, L_80075430
    if (ctx->r9 == ctx->r4) {
        // 0x80075404: sll         $t6, $t1, 2
        ctx->r14 = S32(ctx->r9 << 2);
            goto L_80075430;
    }
    // 0x80075404: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x80075408: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x8007540C: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x80075410: lh          $t9, 0x8A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X8A);
    // 0x80075414: addu        $v1, $t8, $s2
    ctx->r3 = ADD32(ctx->r24, ctx->r18);
    // 0x80075418: lh          $v1, 0x4($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X4);
    // 0x8007541C: nop

    // 0x80075420: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80075424: beq         $at, $zero, L_80075430
    if (ctx->r1 == 0) {
        // 0x80075428: nop
    
            goto L_80075430;
    }
    // 0x80075428: nop

    // 0x8007542C: addiu       $t1, $zero, -0x2
    ctx->r9 = ADD32(0, -0X2);
L_80075430:
    // 0x80075430: bne         $t1, $a0, L_8007546C
    if (ctx->r9 != ctx->r4) {
        // 0x80075434: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8007546C;
    }
    // 0x80075434: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80075438: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007543C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80075440: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80075444: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80075448:
    // 0x80075448: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x8007544C: nop

    // 0x80075450: bne         $v0, $t4, L_80075460
    if (ctx->r2 != ctx->r12) {
        // 0x80075454: nop
    
            goto L_80075460;
    }
    // 0x80075454: nop

    // 0x80075458: b           L_8007546C
    // 0x8007545C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
        goto L_8007546C;
    // 0x8007545C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
L_80075460:
    // 0x80075460: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80075464: bne         $v1, $a3, L_80075448
    if (ctx->r3 != ctx->r7) {
        // 0x80075468: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80075448;
    }
    // 0x80075468: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8007546C:
    // 0x8007546C: bne         $t1, $at, L_8007547C
    if (ctx->r9 != ctx->r1) {
        // 0x80075470: nop
    
            goto L_8007547C;
    }
    // 0x80075470: nop

    // 0x80075474: b           L_8007560C
    // 0x80075478: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8007560C;
    // 0x80075478: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007547C:
    // 0x8007547C: bne         $t1, $a0, L_8007548C
    if (ctx->r9 != ctx->r4) {
        // 0x80075480: sll         $t0, $t1, 2
        ctx->r8 = S32(ctx->r9 << 2);
            goto L_8007548C;
    }
    // 0x80075480: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x80075484: b           L_8007560C
    // 0x80075488: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
        goto L_8007560C;
    // 0x80075488: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
L_8007548C:
    // 0x8007548C: addu        $v0, $a2, $t0
    ctx->r2 = ADD32(ctx->r6, ctx->r8);
    // 0x80075490: lh          $t5, 0x6($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X6);
    // 0x80075494: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80075498: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8007549C: subu        $t6, $s1, $t5
    ctx->r14 = SUB32(ctx->r17, ctx->r13);
    // 0x800754A0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800754A4: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x800754A8: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800754AC: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x800754B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800754B4: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800754B8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800754BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800754C0: jal         0x80070EDC
    // 0x800754C4: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_12;
    // 0x800754C4: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_12:
    // 0x800754C8: lui         $t9, 0x4748
    ctx->r25 = S32(0X4748 << 16);
    // 0x800754CC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800754D0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800754D4: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x800754D8: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800754DC: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x800754E0: ori         $t9, $t9, 0x5353
    ctx->r25 = ctx->r25 | 0X5353;
    // 0x800754E4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800754E8: addiu       $t4, $v0, 0x4
    ctx->r12 = ADD32(ctx->r2, 0X4);
    // 0x800754EC: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x800754F0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800754F4: sb          $t5, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r13;
    // 0x800754F8: lh          $t6, 0x1A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A);
    // 0x800754FC: nop

    // 0x80075500: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x80075504: sh          $t7, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r15;
    // 0x80075508: lw          $s1, 0x70($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X70);
    // 0x8007550C: nop

L_80075510:
    // 0x80075510: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x80075514: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80075518: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x8007551C: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x80075520: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80075524: bne         $at, $zero, L_80075538
    if (ctx->r1 != 0) {
        // 0x80075528: sb          $t9, 0x1($s1)
        MEM_B(0X1, ctx->r17) = ctx->r25;
            goto L_80075538;
    }
    // 0x80075528: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x8007552C: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80075530: b           L_80075548
    // 0x80075534: sh          $t4, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r12;
        goto L_80075548;
    // 0x80075534: sh          $t4, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r12;
L_80075538:
    // 0x80075538: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x8007553C: nop

    // 0x80075540: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x80075544: sh          $t6, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r14;
L_80075548:
    // 0x80075548: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x8007554C: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x80075550: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x80075554: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80075558: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8007555C: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x80075560: addu        $a0, $v0, $s2
    ctx->r4 = ADD32(ctx->r2, ctx->r18);
    // 0x80075564: subu        $a2, $t9, $v0
    ctx->r6 = SUB32(ctx->r25, ctx->r2);
    // 0x80075568: jal         0x800CA300
    // 0x8007556C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    _bcopy(rdram, ctx);
        goto after_13;
    // 0x8007556C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_13:
    // 0x80075570: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x80075574: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80075578: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8007557C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80075580: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80075584: bne         $v1, $a3, L_80075510
    if (ctx->r3 != ctx->r7) {
        // 0x80075588: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80075510;
    }
    // 0x80075588: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8007558C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80075590: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80075594: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80075598: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x8007559C: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x800755A0: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800755A4: lh          $a1, 0x86($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X86);
    // 0x800755A8: lh          $a2, 0x8A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X8A);
    // 0x800755AC: lh          $a3, 0x8E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X8E);
    // 0x800755B0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800755B4: jal         0x80074D00
    // 0x800755B8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80074AA8(rdram, ctx);
        goto after_14;
    // 0x800755B8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_14:
    // 0x800755BC: lh          $t9, 0x7E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X7E);
    // 0x800755C0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800755C4: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800755C8: lh          $t4, 0x82($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X82);
    // 0x800755CC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800755D0: sb          $t4, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r12;
    // 0x800755D4: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800755D8: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800755DC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800755E0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800755E4: addiu       $a3, $a3, 0x7D30
    ctx->r7 = ADD32(ctx->r7, 0X7D30);
    // 0x800755E8: addiu       $a2, $a2, 0x7D20
    ctx->r6 = ADD32(ctx->r6, 0X7D20);
    // 0x800755EC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800755F0: jal         0x8007692C
    // 0x800755F4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    write_controller_pak_file(rdram, ctx);
        goto after_15;
    // 0x800755F4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_15:
    // 0x800755F8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800755FC: jal         0x80071380
    // 0x80075600: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    mempool_free(rdram, ctx);
        goto after_16;
    // 0x80075600: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_16:
    // 0x80075604: b           L_8007560C
    // 0x80075608: nop

        goto L_8007560C;
    // 0x80075608: nop

L_8007560C:
    // 0x8007560C: jal         0x80071380
    // 0x80075610: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_17;
    // 0x80075610: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x80075614: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80075618:
    // 0x80075618: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8007561C:
    // 0x8007561C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80075620: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80075624: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80075628: jr          $ra
    // 0x8007562C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8007562C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_8002FF6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FFAC: addiu       $sp, $sp, -0x160
    ctx->r29 = ADD32(ctx->r29, -0X160);
    // 0x8002FFB0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002FFB4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8002FFB8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8002FFBC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002FFC0: or          $ra, $a2, $zero
    ctx->r31 = ctx->r6 | 0;
    // 0x8002FFC4: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8002FFC8: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8002FFCC: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002FFD0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8002FFD4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002FFD8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002FFDC: swc1        $f29, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002FFE0: swc1        $f28, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f28.u32l;
    // 0x8002FFE4: swc1        $f27, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002FFE8: swc1        $f26, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f26.u32l;
    // 0x8002FFEC: swc1        $f25, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002FFF0: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x8002FFF4: swc1        $f23, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002FFF8: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8002FFFC: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80030000: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x80030004: sw          $a3, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r7;
    // 0x80030008: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8003000C: addiu       $s0, $sp, 0xE0
    ctx->r16 = ADD32(ctx->r29, 0XE0);
    // 0x80030010: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80030014: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80030018: blez        $a2, L_80030398
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8003001C: sw          $a1, 0x164($sp)
        MEM_W(0X164, ctx->r29) = ctx->r5;
            goto L_80030398;
    }
    // 0x8003001C: sw          $a1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r5;
    // 0x80030020: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80030024: bne         $at, $zero, L_80030398
    if (ctx->r1 != 0) {
        // 0x80030028: sw          $a1, 0x164($sp)
        MEM_W(0X164, ctx->r29) = ctx->r5;
            goto L_80030398;
    }
    // 0x80030028: sw          $a1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r5;
    // 0x8003002C: sll         $t7, $zero, 3
    ctx->r15 = S32(0 << 3);
    // 0x80030030: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80030034: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80030038: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8003003C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80030040: addiu       $s1, $s1, -0x4750
    ctx->r17 = ADD32(ctx->r17, -0X4750);
    // 0x80030044: addiu       $s4, $s4, -0x4760
    ctx->r20 = ADD32(ctx->r20, -0X4760);
    // 0x80030048: addiu       $s6, $s6, -0x29C4
    ctx->r22 = ADD32(ctx->r22, -0X29C4);
    // 0x8003004C: addu        $s7, $a3, $t7
    ctx->r23 = ADD32(ctx->r7, ctx->r15);
    // 0x80030050: sw          $a1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r5;
    // 0x80030054: addiu       $s5, $zero, 0x1F
    ctx->r21 = ADD32(0, 0X1F);
    // 0x80030058: addiu       $fp, $t5, 0x1
    ctx->r30 = ADD32(ctx->r13, 0X1);
L_8003005C:
    // 0x8003005C: slt         $at, $fp, $ra
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x80030060: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
    // 0x80030064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030068: bne         $at, $zero, L_80030074
    if (ctx->r1 != 0) {
        // 0x8003006C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80030074;
    }
    // 0x8003006C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80030070: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80030074:
    // 0x80030074: lw          $t8, 0x16C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X16C);
    // 0x80030078: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x8003007C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80030080: lwc1        $f20, 0x0($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80030084: lwc1        $f22, 0x0($s7)
    ctx->f22.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80030088: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8003008C: lwc1        $f18, 0x4($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X4);
    // 0x80030090: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x80030094: sub.s       $f14, $f20, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80030098: or          $t1, $s3, $zero
    ctx->r9 = ctx->r19 | 0;
    // 0x8003009C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x800300A0: bc1f        L_800300C0
    if (!c1cs) {
        // 0x800300A4: sub.s       $f12, $f16, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
            goto L_800300C0;
    }
    // 0x800300A4: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800300A8: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800300AC: nop

    // 0x800300B0: mul.s       $f6, $f12, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x800300B4: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800300B8: b           L_800300D4
    // 0x800300BC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_800300D4;
    // 0x800300BC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_800300C0:
    // 0x800300C0: mul.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800300C4: nop

    // 0x800300C8: mul.s       $f10, $f12, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800300CC: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800300D0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_800300D4:
    // 0x800300D4: blez        $s2, L_8003036C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800300D8: addiu       $t4, $v0, 0x1
        ctx->r12 = ADD32(ctx->r2, 0X1);
            goto L_8003036C;
    }
L_800300D8:
    // 0x800300D8: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x800300DC: slt         $at, $t4, $s2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800300E0: bne         $at, $zero, L_800300EC
    if (ctx->r1 != 0) {
        // 0x800300E4: or          $v1, $t4, $zero
        ctx->r3 = ctx->r12 | 0;
            goto L_800300EC;
    }
    // 0x800300E4: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x800300E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800300EC:
    // 0x800300EC: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800300F0: lwc1        $f20, 0x0($t1)
    ctx->f20.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800300F4: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800300F8: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x800300FC: addu        $a3, $s3, $t6
    ctx->r7 = ADD32(ctx->r19, ctx->r14);
    // 0x80030100: lwc1        $f24, 0x8($a3)
    ctx->f24.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80030104: mul.s       $f6, $f12, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80030108: lwc1        $f26, 0x0($a3)
    ctx->f26.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8003010C: mul.s       $f10, $f24, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f14.fl);
    // 0x80030110: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80030114: mul.s       $f4, $f12, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f26.fl);
    // 0x80030118: add.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8003011C: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x80030120: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80030124: bc1f        L_8003013C
    if (!c1cs) {
        // 0x80030128: add.s       $f22, $f6, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f2.fl;
            goto L_8003013C;
    }
    // 0x80030128: add.s       $f22, $f6, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8003012C: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80030130: nop

    // 0x80030134: bc1t        L_8003015C
    if (c1cs) {
        // 0x80030138: sll         $t7, $t5, 2
        ctx->r15 = S32(ctx->r13 << 2);
            goto L_8003015C;
    }
    // 0x80030138: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
L_8003013C:
    // 0x8003013C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80030140: nop

    // 0x80030144: bc1f        L_80030330
    if (!c1cs) {
        // 0x80030148: nop
    
            goto L_80030330;
    }
    // 0x80030148: nop

    // 0x8003014C: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x80030150: nop

    // 0x80030154: bc1f        L_80030330
    if (!c1cs) {
        // 0x80030158: sll         $t7, $t5, 2
        ctx->r15 = S32(ctx->r13 << 2);
            goto L_80030330;
    }
    // 0x80030158: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
L_8003015C:
    // 0x8003015C: addu        $t0, $s4, $t7
    ctx->r8 = ADD32(ctx->r20, ctx->r15);
    // 0x80030160: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80030164: sll         $t3, $t5, 5
    ctx->r11 = S32(ctx->r13 << 5);
    // 0x80030168: sll         $t8, $t2, 4
    ctx->r24 = S32(ctx->r10 << 4);
    // 0x8003016C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80030170: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80030174: blez        $a0, L_8003025C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80030178: addu        $a2, $s0, $t8
        ctx->r6 = ADD32(ctx->r16, ctx->r24);
            goto L_8003025C;
    }
    // 0x80030178: addu        $a2, $s0, $t8
    ctx->r6 = ADD32(ctx->r16, ctx->r24);
    // 0x8003017C: sll         $t9, $v1, 5
    ctx->r25 = S32(ctx->r3 << 5);
    // 0x80030180: addu        $v0, $s1, $t9
    ctx->r2 = ADD32(ctx->r17, ctx->r25);
L_80030184:
    // 0x80030184: lwc1        $f28, 0x10($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80030188: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8003018C: c.eq.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl == ctx->f20.fl;
    // 0x80030190: nop

    // 0x80030194: bc1f        L_800301EC
    if (!c1cs) {
        // 0x80030198: nop
    
            goto L_800301EC;
    }
    // 0x80030198: nop

    // 0x8003019C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800301A0: nop

    // 0x800301A4: c.eq.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl == ctx->f18.fl;
    // 0x800301A8: nop

    // 0x800301AC: bc1f        L_800301EC
    if (!c1cs) {
        // 0x800301B0: nop
    
            goto L_800301EC;
    }
    // 0x800301B0: nop

    // 0x800301B4: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800301B8: nop

    // 0x800301BC: c.eq.s      $f10, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f10.fl == ctx->f26.fl;
    // 0x800301C0: nop

    // 0x800301C4: bc1f        L_800301EC
    if (!c1cs) {
        // 0x800301C8: nop
    
            goto L_800301EC;
    }
    // 0x800301C8: nop

    // 0x800301CC: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800301D0: nop

    // 0x800301D4: c.eq.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl == ctx->f24.fl;
    // 0x800301D8: nop

    // 0x800301DC: bc1f        L_800301EC
    if (!c1cs) {
        // 0x800301E0: nop
    
            goto L_800301EC;
    }
    // 0x800301E0: nop

    // 0x800301E4: b           L_80030248
    // 0x800301E8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_80030248;
    // 0x800301E8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_800301EC:
    // 0x800301EC: c.eq.s      $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f28.fl == ctx->f26.fl;
    // 0x800301F0: nop

    // 0x800301F4: bc1f        L_80030248
    if (!c1cs) {
        // 0x800301F8: nop
    
            goto L_80030248;
    }
    // 0x800301F8: nop

    // 0x800301FC: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80030200: nop

    // 0x80030204: c.eq.s      $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f6.fl == ctx->f24.fl;
    // 0x80030208: nop

    // 0x8003020C: bc1f        L_80030248
    if (!c1cs) {
        // 0x80030210: nop
    
            goto L_80030248;
    }
    // 0x80030210: nop

    // 0x80030214: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80030218: nop

    // 0x8003021C: c.eq.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl == ctx->f20.fl;
    // 0x80030220: nop

    // 0x80030224: bc1f        L_80030248
    if (!c1cs) {
        // 0x80030228: nop
    
            goto L_80030248;
    }
    // 0x80030228: nop

    // 0x8003022C: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80030230: nop

    // 0x80030234: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x80030238: nop

    // 0x8003023C: bc1f        L_80030248
    if (!c1cs) {
        // 0x80030240: nop
    
            goto L_80030248;
    }
    // 0x80030240: nop

    // 0x80030244: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_80030248:
    // 0x80030248: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003024C: blez        $a0, L_8003025C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80030250: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_8003025C;
    }
    // 0x80030250: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80030254: bltz        $a1, L_80030184
    if (SIGNED(ctx->r5) < 0) {
        // 0x80030258: nop
    
            goto L_80030184;
    }
    // 0x80030258: nop

L_8003025C:
    // 0x8003025C: bltz        $a1, L_80030284
    if (SIGNED(ctx->r5) < 0) {
        // 0x80030260: sll         $t6, $a1, 5
        ctx->r14 = S32(ctx->r5 << 5);
            goto L_80030284;
    }
    // 0x80030260: sll         $t6, $a1, 5
    ctx->r14 = S32(ctx->r5 << 5);
    // 0x80030264: sh          $a1, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r5;
    // 0x80030268: addu        $v0, $s1, $t6
    ctx->r2 = ADD32(ctx->r17, ctx->r14);
    // 0x8003026C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80030270: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80030274: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x80030278: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8003027C: b           L_80030330
    // 0x80030280: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
        goto L_80030330;
    // 0x80030280: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
L_80030284:
    // 0x80030284: sub.s       $f8, $f16, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f22.fl;
    // 0x80030288: nop

    // 0x8003028C: div.s       $f24, $f16, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80030290: sub.s       $f10, $f26, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f26.fl - ctx->f20.fl;
    // 0x80030294: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80030298: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8003029C: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x800302A0: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800302A4: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800302A8: nop

    // 0x800302AC: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800302B0: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800302B4: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800302B8: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x800302BC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800302C0: nop

    // 0x800302C4: slti        $at, $a0, 0x20
    ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x800302C8: bne         $at, $zero, L_800302DC
    if (ctx->r1 != 0) {
        // 0x800302CC: addu        $v1, $a0, $t3
        ctx->r3 = ADD32(ctx->r4, ctx->r11);
            goto L_800302DC;
    }
    // 0x800302CC: addu        $v1, $a0, $t3
    ctx->r3 = ADD32(ctx->r4, ctx->r11);
    // 0x800302D0: sw          $s5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r21;
    // 0x800302D4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800302D8: addu        $v1, $a0, $t3
    ctx->r3 = ADD32(ctx->r4, ctx->r11);
L_800302DC:
    // 0x800302DC: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800302E0: sll         $t7, $v1, 5
    ctx->r15 = S32(ctx->r3 << 5);
    // 0x800302E4: addu        $v0, $s1, $t7
    ctx->r2 = ADD32(ctx->r17, ctx->r15);
    // 0x800302E8: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x800302EC: lwc1        $f10, 0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800302F0: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x800302F4: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x800302F8: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800302FC: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x80030300: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x80030304: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80030308: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8003030C: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x80030310: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80030314: nop

    // 0x80030318: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8003031C: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80030320: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80030324: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x80030328: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x8003032C: sh          $v1, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r3;
L_80030330:
    // 0x80030330: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x80030334: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80030338: bc1f        L_80030364
    if (!c1cs) {
        // 0x8003033C: sll         $t6, $t2, 4
        ctx->r14 = S32(ctx->r10 << 4);
            goto L_80030364;
    }
    // 0x8003033C: sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10 << 4);
    // 0x80030340: lh          $t7, 0xE($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XE);
    // 0x80030344: addu        $a2, $s0, $t6
    ctx->r6 = ADD32(ctx->r16, ctx->r14);
    // 0x80030348: sh          $t7, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r15;
    // 0x8003034C: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80030350: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80030354: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x80030358: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8003035C: nop

    // 0x80030360: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
L_80030364:
    // 0x80030364: bne         $t4, $s2, L_800300D8
    if (ctx->r12 != ctx->r18) {
        // 0x80030368: addiu       $t1, $t1, 0x10
        ctx->r9 = ADD32(ctx->r9, 0X10);
            goto L_800300D8;
    }
    // 0x80030368: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
L_8003036C:
    // 0x8003036C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80030370: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x80030374: slt         $at, $fp, $ra
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x80030378: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x8003037C: or          $t5, $fp, $zero
    ctx->r13 = ctx->r30 | 0;
    // 0x80030380: addiu       $s7, $s7, 0x8
    ctx->r23 = ADD32(ctx->r23, 0X8);
    // 0x80030384: beq         $at, $zero, L_80030398
    if (ctx->r1 == 0) {
        // 0x80030388: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80030398;
    }
    // 0x80030388: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003038C: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x80030390: beq         $at, $zero, L_8003005C
    if (ctx->r1 == 0) {
        // 0x80030394: addiu       $fp, $t5, 0x1
        ctx->r30 = ADD32(ctx->r13, 0X1);
            goto L_8003005C;
    }
    // 0x80030394: addiu       $fp, $t5, 0x1
    ctx->r30 = ADD32(ctx->r13, 0X1);
L_80030398:
    // 0x80030398: lw          $a1, 0x164($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X164);
    // 0x8003039C: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x800303A0: bne         $at, $zero, L_800304A8
    if (ctx->r1 != 0) {
        // 0x800303A4: nop
    
            goto L_800304A8;
    }
    // 0x800303A4: nop

    // 0x800303A8: beq         $s3, $a1, L_800304B0
    if (ctx->r19 == ctx->r5) {
        // 0x800303AC: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_800304B0;
    }
    // 0x800303AC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800303B0: blez        $s2, L_800304AC
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800303B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800304AC;
    }
    // 0x800303B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800303B8: andi        $a3, $s2, 0x3
    ctx->r7 = ctx->r18 & 0X3;
    // 0x800303BC: beq         $a3, $zero, L_800303FC
    if (ctx->r7 == 0) {
        // 0x800303C0: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_800303FC;
    }
    // 0x800303C0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800303C4: sll         $v1, $zero, 4
    ctx->r3 = S32(0 << 4);
    // 0x800303C8: addu        $t1, $s3, $v1
    ctx->r9 = ADD32(ctx->r19, ctx->r3);
    // 0x800303CC: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
L_800303D0:
    // 0x800303D0: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800303D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800303D8: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800303DC: lwc1        $f10, 0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800303E0: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x800303E4: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x800303E8: lh          $t8, -0x2($t1)
    ctx->r24 = MEM_H(ctx->r9, -0X2);
    // 0x800303EC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800303F0: bne         $a2, $v0, L_800303D0
    if (ctx->r6 != ctx->r2) {
        // 0x800303F4: sh          $t8, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r24;
            goto L_800303D0;
    }
    // 0x800303F4: sh          $t8, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r24;
    // 0x800303F8: beq         $v0, $s2, L_800304AC
    if (ctx->r2 == ctx->r18) {
        // 0x800303FC: sll         $v1, $v0, 4
        ctx->r3 = S32(ctx->r2 << 4);
            goto L_800304AC;
    }
L_800303FC:
    // 0x800303FC: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80030400: sll         $t9, $s2, 4
    ctx->r25 = S32(ctx->r18 << 4);
    // 0x80030404: addu        $a2, $t9, $a1
    ctx->r6 = ADD32(ctx->r25, ctx->r5);
    // 0x80030408: addu        $t1, $s3, $v1
    ctx->r9 = ADD32(ctx->r19, ctx->r3);
    // 0x8003040C: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
L_80030410:
    // 0x80030410: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80030414: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x80030418: swc1        $f4, -0x40($a0)
    MEM_W(-0X40, ctx->r4) = ctx->f4.u32l;
    // 0x8003041C: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80030420: addiu       $t1, $t1, 0x40
    ctx->r9 = ADD32(ctx->r9, 0X40);
    // 0x80030424: swc1        $f6, -0x38($a0)
    MEM_W(-0X38, ctx->r4) = ctx->f6.u32l;
    // 0x80030428: lh          $t6, -0x32($t1)
    ctx->r14 = MEM_H(ctx->r9, -0X32);
    // 0x8003042C: nop

    // 0x80030430: sh          $t6, -0x32($a0)
    MEM_H(-0X32, ctx->r4) = ctx->r14;
    // 0x80030434: lwc1        $f8, -0x30($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, -0X30);
    // 0x80030438: nop

    // 0x8003043C: swc1        $f8, -0x30($a0)
    MEM_W(-0X30, ctx->r4) = ctx->f8.u32l;
    // 0x80030440: lwc1        $f10, -0x28($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, -0X28);
    // 0x80030444: nop

    // 0x80030448: swc1        $f10, -0x28($a0)
    MEM_W(-0X28, ctx->r4) = ctx->f10.u32l;
    // 0x8003044C: lh          $t7, -0x22($t1)
    ctx->r15 = MEM_H(ctx->r9, -0X22);
    // 0x80030450: nop

    // 0x80030454: sh          $t7, -0x22($a0)
    MEM_H(-0X22, ctx->r4) = ctx->r15;
    // 0x80030458: lwc1        $f4, -0x20($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, -0X20);
    // 0x8003045C: nop

    // 0x80030460: swc1        $f4, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = ctx->f4.u32l;
    // 0x80030464: lwc1        $f6, -0x18($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, -0X18);
    // 0x80030468: nop

    // 0x8003046C: swc1        $f6, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = ctx->f6.u32l;
    // 0x80030470: lh          $t8, -0x12($t1)
    ctx->r24 = MEM_H(ctx->r9, -0X12);
    // 0x80030474: nop

    // 0x80030478: sh          $t8, -0x12($a0)
    MEM_H(-0X12, ctx->r4) = ctx->r24;
    // 0x8003047C: lwc1        $f8, -0x10($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, -0X10);
    // 0x80030480: nop

    // 0x80030484: swc1        $f8, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = ctx->f8.u32l;
    // 0x80030488: lwc1        $f10, -0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, -0X8);
    // 0x8003048C: nop

    // 0x80030490: swc1        $f10, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80030494: lh          $t9, -0x2($t1)
    ctx->r25 = MEM_H(ctx->r9, -0X2);
    // 0x80030498: bne         $a0, $a2, L_80030410
    if (ctx->r4 != ctx->r6) {
        // 0x8003049C: sh          $t9, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r25;
            goto L_80030410;
    }
    // 0x8003049C: sh          $t9, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r25;
    // 0x800304A0: b           L_800304B0
    // 0x800304A4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_800304B0;
    // 0x800304A4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_800304A8:
    // 0x800304A8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800304AC:
    // 0x800304AC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_800304B0:
    // 0x800304B0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800304B4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800304B8: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800304BC: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800304C0: lwc1        $f23, 0x10($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800304C4: lwc1        $f22, 0x14($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800304C8: lwc1        $f25, 0x18($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800304CC: lwc1        $f24, 0x1C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800304D0: lwc1        $f27, 0x20($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800304D4: lwc1        $f26, 0x24($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800304D8: lwc1        $f29, 0x28($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800304DC: lwc1        $f28, 0x2C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800304E0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800304E4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800304E8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800304EC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800304F0: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800304F4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800304F8: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800304FC: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80030500: jr          $ra
    // 0x80030504: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
    return;
    // 0x80030504: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
;}
RECOMP_FUNC void func_8001F3EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F420: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001F424: lh          $v0, -0x4C08($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4C08);
    // 0x8001F428: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8001F42C: bne         $v0, $zero, L_8001F43C
    if (ctx->r2 != 0) {
        // 0x8001F430: nop
    
            goto L_8001F43C;
    }
    // 0x8001F430: nop

    // 0x8001F434: jr          $ra
    // 0x8001F438: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8001F438: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001F43C:
    // 0x8001F43C: blez        $v0, L_8001F478
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F440: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001F478;
    }
    // 0x8001F440: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001F444: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001F448: lw          $a2, -0x4C0C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C0C);
    // 0x8001F44C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F450: sll         $a3, $v0, 2
    ctx->r7 = S32(ctx->r2 << 2);
L_8001F454:
    // 0x8001F454: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8001F458: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001F45C: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x8001F460: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001F464: bne         $a1, $t7, L_8001F470
    if (ctx->r5 != ctx->r15) {
        // 0x8001F468: nop
    
            goto L_8001F470;
    }
    // 0x8001F468: nop

    // 0x8001F46C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8001F470:
    // 0x8001F470: bne         $at, $zero, L_8001F454
    if (ctx->r1 != 0) {
        // 0x8001F474: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8001F454;
    }
    // 0x8001F474: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8001F478:
    // 0x8001F478: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001F47C: jr          $ra
    // 0x8001F480: nop

    return;
    // 0x8001F480: nop

;}
RECOMP_FUNC void check_if_in_draw_range(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A940: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8002A944: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002A948: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002A94C: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x8002A950: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002A954: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x8002A958: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002A95C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8002A960: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002A964: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8002A968: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8002A96C: nop

    // 0x8002A970: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8002A974: bne         $t7, $zero, L_8002AC14
    if (ctx->r15 != 0) {
        // 0x8002A978: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002AC14;
    }
    // 0x8002A978: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A97C: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x8002A980: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8002A984: lh          $v1, 0x4E($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X4E);
    // 0x8002A988: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002A98C: beq         $v1, $zero, L_8002AB00
    if (ctx->r3 == 0) {
        // 0x8002A990: nop
    
            goto L_8002AB00;
    }
    // 0x8002A990: nop

    // 0x8002A994: lw          $t9, -0x2704($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2704);
    // 0x8002A998: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002A99C: bne         $t9, $at, L_8002A9E8
    if (ctx->r25 != ctx->r1) {
        // 0x8002A9A0: nop
    
            goto L_8002A9E8;
    }
    // 0x8002A9A0: nop

    // 0x8002A9A4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8002A9A8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002A9AC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8002A9B0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002A9B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002A9B8: nop

    // 0x8002A9BC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8002A9C0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8002A9C4: nop

    // 0x8002A9C8: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8002A9CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002A9D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002A9D4: nop

    // 0x8002A9D8: cvt.w.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_D(ctx->f10.d);
    // 0x8002A9DC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8002A9E0: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8002A9E4: nop

L_8002A9E8:
    // 0x8002A9E8: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8002A9EC: lwc1        $f14, 0x10($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002A9F0: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x8002A9F4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8002A9F8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8002A9FC: jal         0x80066588
    // 0x8002AA00: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    get_distance_to_active_camera(rdram, ctx);
        goto after_0;
    // 0x8002AA00: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_0:
    // 0x8002AA04: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8002AA08: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8002AA0C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8002AA10: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8002AA14: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002AA18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002AA1C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8002AA20: nop

    // 0x8002AA24: bc1f        L_8002AA34
    if (!c1cs) {
        // 0x8002AA28: nop
    
            goto L_8002AA34;
    }
    // 0x8002AA28: nop

    // 0x8002AA2C: b           L_8002AC14
    // 0x8002AA30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002AC14;
    // 0x8002AA30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002AA34:
    // 0x8002AA34: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8002AA38: lwc1        $f5, 0x6440($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6440);
    // 0x8002AA3C: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x8002AA40: lwc1        $f4, 0x6444($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6444);
    // 0x8002AA44: nop

    // 0x8002AA48: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8002AA4C: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x8002AA50: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002AA54: nop

    // 0x8002AA58: bc1f        L_8002AB00
    if (!c1cs) {
        // 0x8002AA5C: nop
    
            goto L_8002AB00;
    }
    // 0x8002AA5C: nop

    // 0x8002AA60: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8002AA64: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8002AA68: nop

    // 0x8002AA6C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8002AA70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002AA74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002AA78: nop

    // 0x8002AA7C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002AA80: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8002AA84: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8002AA88: blez        $v1, L_8002AAF4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002AA8C: nop
    
            goto L_8002AAF4;
    }
    // 0x8002AA8C: nop

    // 0x8002AA90: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8002AA94: sub.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002AA98: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002AA9C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002AAA0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002AAA4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002AAA8: div.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8002AAAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002AAB0: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8002AAB4: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x8002AAB8: lwc1        $f6, 0x644C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X644C);
    // 0x8002AABC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002AAC0: lwc1        $f7, 0x6448($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6448);
    // 0x8002AAC4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8002AAC8: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8002AACC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002AAD0: nop

    // 0x8002AAD4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8002AAD8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002AADC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002AAE0: nop

    // 0x8002AAE4: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x8002AAE8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002AAEC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8002AAF0: nop

L_8002AAF4:
    // 0x8002AAF4: bne         $a1, $zero, L_8002AB00
    if (ctx->r5 != 0) {
        // 0x8002AAF8: nop
    
            goto L_8002AB00;
    }
    // 0x8002AAF8: nop

    // 0x8002AAFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8002AB00:
    // 0x8002AB00: lh          $v0, 0x48($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X48);
    // 0x8002AB04: nop

    // 0x8002AB08: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8002AB0C: bne         $at, $zero, L_8002AB38
    if (ctx->r1 != 0) {
        // 0x8002AB10: addiu       $t3, $v0, -0x32
        ctx->r11 = ADD32(ctx->r2, -0X32);
            goto L_8002AB38;
    }
    // 0x8002AB10: addiu       $t3, $v0, -0x32
    ctx->r11 = ADD32(ctx->r2, -0X32);
    // 0x8002AB14: sltiu       $at, $t3, 0x20
    ctx->r1 = ctx->r11 < 0X20 ? 1 : 0;
    // 0x8002AB18: beq         $at, $zero, L_8002AB94
    if (ctx->r1 == 0) {
        // 0x8002AB1C: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_8002AB94;
    }
    // 0x8002AB1C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8002AB20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002AB24: addu        $at, $at, $t3
    gpr jr_addend_8002AB30 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8002AB28: lw          $t3, 0x6450($at)
    ctx->r11 = ADD32(ctx->r1, 0X6450);
    // 0x8002AB2C: nop

    // 0x8002AB30: jr          $t3
    // 0x8002AB34: nop

    switch (jr_addend_8002AB30 >> 2) {
        case 0: goto L_8002AB80; break;
        case 1: goto L_8002AB80; break;
        case 2: goto L_8002AB94; break;
        case 3: goto L_8002AB80; break;
        case 4: goto L_8002AB80; break;
        case 5: goto L_8002AB94; break;
        case 6: goto L_8002AB80; break;
        case 7: goto L_8002AB94; break;
        case 8: goto L_8002AB6C; break;
        case 9: goto L_8002AB94; break;
        case 10: goto L_8002AB94; break;
        case 11: goto L_8002AB94; break;
        case 12: goto L_8002AB98; break;
        case 13: goto L_8002AB94; break;
        case 14: goto L_8002AB94; break;
        case 15: goto L_8002AB94; break;
        case 16: goto L_8002AB94; break;
        case 17: goto L_8002AB94; break;
        case 18: goto L_8002AB94; break;
        case 19: goto L_8002AB94; break;
        case 20: goto L_8002AB80; break;
        case 21: goto L_8002AB94; break;
        case 22: goto L_8002AB80; break;
        case 23: goto L_8002AB94; break;
        case 24: goto L_8002AB94; break;
        case 25: goto L_8002AB94; break;
        case 26: goto L_8002AB94; break;
        case 27: goto L_8002AB98; break;
        case 28: goto L_8002AB94; break;
        case 29: goto L_8002AB94; break;
        case 30: goto L_8002AB98; break;
        case 31: goto L_8002AB80; break;
        default: switch_error(__func__, 0x8002AB30, 0x800E6450);
    }
    // 0x8002AB34: nop

L_8002AB38:
    // 0x8002AB38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002AB3C: bne         $v0, $at, L_8002AB94
    if (ctx->r2 != ctx->r1) {
        // 0x8002AB40: nop
    
            goto L_8002AB94;
    }
    // 0x8002AB40: nop

    // 0x8002AB44: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8002AB48: nop

    // 0x8002AB4C: lbu         $t4, 0x1F7($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X1F7);
    // 0x8002AB50: nop

    // 0x8002AB54: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8002AB58: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002AB5C: mflo        $t6
    ctx->r14 = lo;
    // 0x8002AB60: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8002AB64: b           L_8002AB98
    // 0x8002AB68: sb          $t7, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r15;
        goto L_8002AB98;
    // 0x8002AB68: sb          $t7, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r15;
L_8002AB6C:
    // 0x8002AB6C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8002AB70: nop

    // 0x8002AB74: lbu         $t8, 0x1F7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1F7);
    // 0x8002AB78: b           L_8002AB98
    // 0x8002AB7C: sb          $t8, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r24;
        goto L_8002AB98;
    // 0x8002AB7C: sb          $t8, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r24;
L_8002AB80:
    // 0x8002AB80: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8002AB84: nop

    // 0x8002AB88: lbu         $t9, 0x42($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X42);
    // 0x8002AB8C: b           L_8002AB98
    // 0x8002AB90: sb          $t9, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r25;
        goto L_8002AB98;
    // 0x8002AB90: sb          $t9, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r25;
L_8002AB94:
    // 0x8002AB94: sb          $a1, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r5;
L_8002AB98:
    // 0x8002AB98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002AB9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002ABA0: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8002ABA4: lwc1        $f20, 0x10($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002ABA8: lwc1        $f22, 0x14($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002ABAC: lwc1        $f24, 0x34($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8002ABB0: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8002ABB4: addiu       $v1, $v1, -0x2958
    ctx->r3 = ADD32(ctx->r3, -0X2958);
    // 0x8002ABB8: addiu       $v0, $v0, -0x2988
    ctx->r2 = ADD32(ctx->r2, -0X2988);
L_8002ABBC:
    // 0x8002ABBC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002ABC0: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002ABC4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8002ABC8: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002ABCC: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002ABD0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002ABD4: mul.s       $f6, $f14, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x8002ABD8: nop

    // 0x8002ABDC: mul.s       $f10, $f2, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8002ABE0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002ABE4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002ABE8: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8002ABEC: add.s       $f16, $f6, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8002ABF0: c.lt.s      $f16, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f16.fl < ctx->f26.fl;
    // 0x8002ABF4: nop

    // 0x8002ABF8: bc1f        L_8002AC08
    if (!c1cs) {
        // 0x8002ABFC: nop
    
            goto L_8002AC08;
    }
    // 0x8002ABFC: nop

    // 0x8002AC00: b           L_8002AC14
    // 0x8002AC04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002AC14;
    // 0x8002AC04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002AC08:
    // 0x8002AC08: bne         $v0, $v1, L_8002ABBC
    if (ctx->r2 != ctx->r3) {
        // 0x8002AC0C: nop
    
            goto L_8002ABBC;
    }
    // 0x8002AC0C: nop

    // 0x8002AC10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002AC14:
    // 0x8002AC14: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8002AC18: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8002AC1C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8002AC20: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002AC24: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002AC28: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002AC2C: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002AC30: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002AC34: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002AC38: jr          $ra
    // 0x8002AC3C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8002AC3C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void menu_racer_portraits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094B08: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80094B0C: addiu       $v0, $v0, 0x6AF0
    ctx->r2 = ADD32(ctx->r2, 0X6AF0);
    // 0x80094B10: lw          $t6, 0xC8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC8);
    // 0x80094B14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094B18: sw          $t6, 0xFD0($at)
    MEM_W(0XFD0, ctx->r1) = ctx->r14;
    // 0x80094B1C: lw          $t7, 0xCC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XCC);
    // 0x80094B20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094B24: sw          $t7, 0xFE0($at)
    MEM_W(0XFE0, ctx->r1) = ctx->r15;
    // 0x80094B28: lw          $t8, 0xD0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD0);
    // 0x80094B2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094B30: sw          $t8, 0xFF0($at)
    MEM_W(0XFF0, ctx->r1) = ctx->r24;
    // 0x80094B34: lw          $t9, 0xD8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD8);
    // 0x80094B38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094B3C: sw          $t9, 0x1010($at)
    MEM_W(0X1010, ctx->r1) = ctx->r25;
    // 0x80094B40: lw          $t0, 0xD4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XD4);
    // 0x80094B44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094B48: sw          $t0, 0x1000($at)
    MEM_W(0X1000, ctx->r1) = ctx->r8;
    // 0x80094B4C: lw          $t1, 0xDC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XDC);
    // 0x80094B50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094B54: sw          $t1, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->r9;
    // 0x80094B58: lw          $t2, 0xE0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XE0);
    // 0x80094B5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094B60: sw          $t2, 0x1030($at)
    MEM_W(0X1030, ctx->r1) = ctx->r10;
    // 0x80094B64: lw          $t3, 0xE4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XE4);
    // 0x80094B68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094B6C: sw          $t3, 0x1040($at)
    MEM_W(0X1040, ctx->r1) = ctx->r11;
    // 0x80094B70: lw          $t4, 0xE8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XE8);
    // 0x80094B74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094B78: sw          $t4, 0x1050($at)
    MEM_W(0X1050, ctx->r1) = ctx->r12;
    // 0x80094B7C: lw          $t5, 0xEC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XEC);
    // 0x80094B80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094B84: jr          $ra
    // 0x80094B88: sw          $t5, 0x1060($at)
    MEM_W(0X1060, ctx->r1) = ctx->r13;
    return;
    // 0x80094B88: sw          $t5, 0x1060($at)
    MEM_W(0X1060, ctx->r1) = ctx->r13;
;}
RECOMP_FUNC void menu_init_vehicle_textures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E914: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008E918: addiu       $v1, $v1, 0x6AF0
    ctx->r3 = ADD32(ctx->r3, 0X6AF0);
    // 0x8008E91C: lw          $t6, 0x60($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X60);
    // 0x8008E920: lw          $t7, 0x64($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X64);
    // 0x8008E924: lw          $t8, 0x68($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X68);
    // 0x8008E928: lw          $t9, 0x6C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6C);
    // 0x8008E92C: lw          $t0, 0x70($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X70);
    // 0x8008E930: lw          $t1, 0x74($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X74);
    // 0x8008E934: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008E938: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E93C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008E940: addiu       $a1, $a1, 0xA0C
    ctx->r5 = ADD32(ctx->r5, 0XA0C);
    // 0x8008E944: addiu       $a0, $a0, 0x9F4
    ctx->r4 = ADD32(ctx->r4, 0X9F4);
    // 0x8008E948: addiu       $v0, $v0, 0x9DC
    ctx->r2 = ADD32(ctx->r2, 0X9DC);
    // 0x8008E94C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8008E950: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8008E954: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8008E958: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8008E95C: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8008E960: jr          $ra
    // 0x8008E964: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    return;
    // 0x8008E964: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
;}
RECOMP_FUNC void alResampleNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800651DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800651E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800651E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800651E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800651EC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800651F0: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800651F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800651F8: addiu       $a2, $a2, -0x3A10
    ctx->r6 = ADD32(ctx->r6, -0X3A10);
    // 0x800651FC: addiu       $a1, $a1, -0x3924
    ctx->r5 = ADD32(ctx->r5, -0X3924);
    // 0x80065200: jal         0x800CA610
    // 0x80065204: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80065204: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80065208: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8006520C: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80065210: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80065214: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006521C: jal         0x800C7D50
    // 0x80065220: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x80065220: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80065224: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80065228: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8006522C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80065230: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80065234: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80065238: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x8006523C: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x80065240: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80065244: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80065248: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x8006524C: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x80065250: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x80065254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80065258: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006525C: jr          $ra
    // 0x80065260: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80065260: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mtxf_translate_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070070: mtc1        $a1, $f16
    ctx->f16.u32l = ctx->r5;
    // 0x80070074: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80070078: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8007007C: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80070080: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80070084: lwc1        $f2, 0x30($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80070088: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8007008C: mul.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80070090: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80070094: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80070098: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007009C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800700A0: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x800700A4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800700A8: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x800700AC: jr          $ra
    // 0x800700B0: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800700B0: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void add_particle_to_entity_list(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E9D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E9D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E9D8: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8000E9DC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000E9E0: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x8000E9E4: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x8000E9E8: lh          $a0, 0x2C($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2C);
    // 0x8000E9EC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8000E9F0: ori         $t8, $a0, 0xC000
    ctx->r24 = ctx->r4 | 0XC000;
    // 0x8000E9F4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8000E9F8: jal         0x800245E8
    // 0x8000E9FC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    func_800245B4(rdram, ctx);
        goto after_0;
    // 0x8000E9FC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_0:
    // 0x8000EA00: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EA04: addiu       $v0, $v0, -0x4C24
    ctx->r2 = ADD32(ctx->r2, -0X4C24);
    // 0x8000EA08: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8000EA0C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000EA10: lw          $t1, -0x4C28($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4C28);
    // 0x8000EA14: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8000EA18: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8000EA1C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8000EA20: sw          $a1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r5;
    // 0x8000EA24: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8000EA28: nop

    // 0x8000EA2C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000EA30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000EA34: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EA38: addiu       $v0, $v0, -0x4C1C
    ctx->r2 = ADD32(ctx->r2, -0X4C1C);
    // 0x8000EA3C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8000EA40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000EA44: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000EA48: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000EA4C: jr          $ra
    // 0x8000EA50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000EA50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void check_if_silver_coin_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E1DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E1E0: lb          $v0, -0x4C7D($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4C7D);
    // 0x8000E1E4: jr          $ra
    // 0x8000E1E8: nop

    return;
    // 0x8000E1E8: nop

;}
RECOMP_FUNC void obj_init_ainode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D028: lbu         $a2, 0x9($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X9);
    // 0x8003D02C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003D030: bne         $a2, $at, L_8003D04C
    if (ctx->r6 != ctx->r1) {
        // 0x8003D034: nop
    
            goto L_8003D04C;
    }
    // 0x8003D034: nop

    // 0x8003D038: jal         0x8001C4C0
    // 0x8003D03C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ainode_register(rdram, ctx);
        goto after_0;
    // 0x8003D03C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003D040: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D044: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x8003D048: sb          $v0, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r2;
L_8003D04C:
    // 0x8003D04C: jal         0x8001D1F0
    // 0x8003D050: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ainode_tail_set(rdram, ctx);
        goto after_1;
    // 0x8003D050: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8003D054: jal         0x8001D1E0
    // 0x8003D058: nop

    ainode_enable(rdram, ctx);
        goto after_2;
    // 0x8003D058: nop

    after_2:
    // 0x8003D05C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D064: jr          $ra
    // 0x8003D068: nop

    return;
    // 0x8003D068: nop

;}
RECOMP_FUNC void bgload_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C78B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C78B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C78B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C78BC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C78C0: addiu       $a1, $a1, -0x4D88
    ctx->r5 = ADD32(ctx->r5, -0X4D88);
    // 0x800C78C4: addiu       $a0, $a0, -0x4DA0
    ctx->r4 = ADD32(ctx->r4, -0X4DA0);
    // 0x800C78C8: jal         0x800C8D80
    // 0x800C78CC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800C78CC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800C78D0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C78D4: addiu       $t6, $t6, -0x2D80
    ctx->r14 = ADD32(ctx->r14, -0X2D80);
    // 0x800C78D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C78DC: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x800C78E0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800C78E4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800C78E8: addiu       $a2, $a2, 0x7A00
    ctx->r6 = ADD32(ctx->r6, 0X7A00);
    // 0x800C78EC: addiu       $a0, $a0, -0x4F50
    ctx->r4 = ADD32(ctx->r4, -0X4F50);
    // 0x800C78F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C78F4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800C78F8: jal         0x800C8DB0
    // 0x800C78FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800C78FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800C7900: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C7904: jal         0x800C8F00
    // 0x800C7908: addiu       $a0, $a0, -0x4F50
    ctx->r4 = ADD32(ctx->r4, -0X4F50);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800C7908: addiu       $a0, $a0, -0x4F50
    ctx->r4 = ADD32(ctx->r4, -0X4F50);
    after_2:
    // 0x800C790C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7910: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C7914: jr          $ra
    // 0x800C7918: nop

    return;
    // 0x800C7918: nop

;}
RECOMP_FUNC void func_80012C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012C3C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80012C40: addiu       $a3, $a3, -0x4CDC
    ctx->r7 = ADD32(ctx->r7, -0X4CDC);
    // 0x80012C44: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x80012C48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80012C4C: blez        $t6, L_80012C90
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80012C50: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_80012C90;
    }
    // 0x80012C50: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80012C54: addiu       $a2, $a2, -0x4D08
    ctx->r6 = ADD32(ctx->r6, -0X4D08);
    // 0x80012C58: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
L_80012C5C:
    // 0x80012C5C: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80012C60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80012C64: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80012C68: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80012C6C: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80012C70: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80012C74: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80012C78: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80012C7C: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80012C80: nop

    // 0x80012C84: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80012C88: bne         $at, $zero, L_80012C5C
    if (ctx->r1 != 0) {
        // 0x80012C8C: nop
    
            goto L_80012C5C;
    }
    // 0x80012C8C: nop

L_80012C90:
    // 0x80012C90: jr          $ra
    // 0x80012C94: nop

    return;
    // 0x80012C94: nop

;}
RECOMP_FUNC void obj_wave_height(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF3D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BF3D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF3DC: lhu         $t6, 0x4($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X4);
    // 0x800BF3E0: lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6);
    // 0x800BF3E4: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800BF3E8: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    // 0x800BF3EC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BF3F0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800BF3F4: bne         $at, $zero, L_800BF410
    if (ctx->r1 != 0) {
        // 0x800BF3F8: sh          $t7, 0x4($a0)
        MEM_H(0X4, ctx->r4) = ctx->r15;
            goto L_800BF410;
    }
    // 0x800BF3F8: sh          $t7, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r15;
L_800BF3FC:
    // 0x800BF3FC: subu        $t8, $v0, $v1
    ctx->r24 = SUB32(ctx->r2, ctx->r3);
    // 0x800BF400: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x800BF404: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BF408: beq         $at, $zero, L_800BF3FC
    if (ctx->r1 == 0) {
        // 0x800BF40C: sh          $t8, 0x4($a3)
        MEM_H(0X4, ctx->r7) = ctx->r24;
            goto L_800BF3FC;
    }
    // 0x800BF40C: sh          $t8, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r24;
L_800BF410:
    // 0x800BF410: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800BF414: addu        $a0, $a3, $t9
    ctx->r4 = ADD32(ctx->r7, ctx->r25);
    // 0x800BF418: lb          $t0, 0xE($a0)
    ctx->r8 = MEM_B(ctx->r4, 0XE);
    // 0x800BF41C: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800BF420: beq         $t1, $zero, L_800BF46C
    if (ctx->r9 == 0) {
        // 0x800BF424: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_800BF46C;
    }
    // 0x800BF424: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x800BF428: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BF42C: bne         $at, $zero, L_800BF440
    if (ctx->r1 != 0) {
        // 0x800BF430: nop
    
            goto L_800BF440;
    }
    // 0x800BF430: nop

    // 0x800BF434: lb          $t3, 0xE($a3)
    ctx->r11 = MEM_B(ctx->r7, 0XE);
    // 0x800BF438: b           L_800BF44C
    // 0x800BF43C: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
        goto L_800BF44C;
    // 0x800BF43C: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
L_800BF440:
    // 0x800BF440: lb          $t4, 0xF($a0)
    ctx->r12 = MEM_B(ctx->r4, 0XF);
    // 0x800BF444: nop

    // 0x800BF448: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
L_800BF44C:
    // 0x800BF44C: lbu         $v0, 0x2($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X2);
    // 0x800BF450: sra         $t6, $t0, 1
    ctx->r14 = S32(SIGNED(ctx->r8) >> 1);
    // 0x800BF454: blez        $v0, L_800BF464
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BF458: addiu       $t5, $v0, 0x1F
        ctx->r13 = ADD32(ctx->r2, 0X1F);
            goto L_800BF464;
    }
    // 0x800BF458: addiu       $t5, $v0, 0x1F
    ctx->r13 = ADD32(ctx->r2, 0X1F);
    // 0x800BF45C: b           L_800BF478
    // 0x800BF460: sllv        $t0, $t0, $t5
    ctx->r8 = S32(ctx->r8 << (ctx->r13 & 31));
        goto L_800BF478;
    // 0x800BF460: sllv        $t0, $t0, $t5
    ctx->r8 = S32(ctx->r8 << (ctx->r13 & 31));
L_800BF464:
    // 0x800BF464: b           L_800BF478
    // 0x800BF468: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
        goto L_800BF478;
    // 0x800BF468: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
L_800BF46C:
    // 0x800BF46C: lbu         $t7, 0x2($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X2);
    // 0x800BF470: nop

    // 0x800BF474: sllv        $t0, $t0, $t7
    ctx->r8 = S32(ctx->r8 << (ctx->r15 & 31));
L_800BF478:
    // 0x800BF478: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800BF47C: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x800BF480: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BF484: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x800BF488: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800BF48C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BF490: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800BF494: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800BF498: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800BF49C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BF4A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BF4A4: lwc1        $f10, -0x5A38($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5A38);
    // 0x800BF4A8: lhu         $a0, 0xC($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0XC);
    // 0x800BF4AC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800BF4B0: add.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f16.d + ctx->f6.d;
    // 0x800BF4B4: lhu         $a1, 0x8($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0X8);
    // 0x800BF4B8: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x800BF4BC: lhu         $a2, 0xA($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0XA);
    // 0x800BF4C0: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800BF4C4: jal         0x800BF4E4
    // 0x800BF4C8: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    waves_get_y(rdram, ctx);
        goto after_0;
    // 0x800BF4C8: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x800BF4CC: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800BF4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BF4D4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800BF4D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BF4DC: jr          $ra
    // 0x800BF4E0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800BF4E0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void update_onscreen_AI_racer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054150: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80054154: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80054158: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005415C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80054160: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x80054164: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x80054168: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005416C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80054170: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x80054174: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80054178: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8005417C: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x80054180: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80054184: sw          $zero, -0x252C($at)
    MEM_W(-0X252C, ctx->r1) = 0;
    // 0x80054188: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8005418C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80054190: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80054194: sw          $zero, -0x2528($at)
    MEM_W(-0X2528, ctx->r1) = 0;
    // 0x80054198: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005419C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800541A0: jal         0x800579F0
    // 0x800541A4: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    handle_base_steering(rdram, ctx);
        goto after_0;
    // 0x800541A4: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800541A8: jal         0x800536A4
    // 0x800541AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    handle_car_velocity_control(rdram, ctx);
        goto after_1;
    // 0x800541AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800541B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800541B4: jal         0x8005762C
    // 0x800541B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800575EC(rdram, ctx);
        goto after_2;
    // 0x800541B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800541BC: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x800541C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800541C4: jal         0x80055F00
    // 0x800541C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    handle_racer_items(rdram, ctx);
        goto after_3;
    // 0x800541C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800541CC: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x800541D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800541D4: jal         0x80053EDC
    // 0x800541D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_attack_handler_car(rdram, ctx);
        goto after_4;
    // 0x800541D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800541DC: lb          $t6, 0x1DB($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1DB);
    // 0x800541E0: nop

    // 0x800541E4: beq         $t6, $zero, L_80054208
    if (ctx->r14 == 0) {
        // 0x800541E8: nop
    
            goto L_80054208;
    }
    // 0x800541E8: nop

    // 0x800541EC: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x800541F0: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    // 0x800541F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800541F8: jal         0x80052BA4
    // 0x800541FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_spinout_car(rdram, ctx);
        goto after_5;
    // 0x800541FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80054200: b           L_80054244
    // 0x80054204: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
        goto L_80054244;
    // 0x80054204: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
L_80054208:
    // 0x80054208: lb          $t7, 0x1E2($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1E2);
    // 0x8005420C: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x80054210: blez        $t7, L_80054234
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80054214: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80054234;
    }
    // 0x80054214: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80054218: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x8005421C: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    // 0x80054220: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80054224: jal         0x8005496C
    // 0x80054228: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    update_car_velocity_ground(rdram, ctx);
        goto after_6;
    // 0x80054228: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x8005422C: b           L_80054244
    // 0x80054230: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
        goto L_80054244;
    // 0x80054230: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
L_80054234:
    // 0x80054234: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    // 0x80054238: jal         0x80052DBC
    // 0x8005423C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    update_car_velocity_offground(rdram, ctx);
        goto after_7;
    // 0x8005423C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80054240: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
L_80054244:
    // 0x80054244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80054248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005424C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80054250: jal         0x80050890
    // 0x80054254: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    apply_vehicle_rotation_offset(rdram, ctx);
        goto after_8;
    // 0x80054254: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80054258: jal         0x8006BFF0
    // 0x8005425C: nop

    level_header(rdram, ctx);
        goto after_9;
    // 0x8005425C: nop

    after_9:
    // 0x80054260: lwc1        $f16, 0xC0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80054264: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80054268: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005426C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80054270: c.eq.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d == ctx->f18.d;
    // 0x80054274: nop

    // 0x80054278: bc1t        L_8005428C
    if (c1cs) {
        // 0x8005427C: nop
    
            goto L_8005428C;
    }
    // 0x8005427C: nop

    // 0x80054280: lb          $t8, 0x2($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X2);
    // 0x80054284: nop

    // 0x80054288: bne         $t8, $zero, L_800542A0
    if (ctx->r24 != 0) {
        // 0x8005428C: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800542A0;
    }
L_8005428C:
    // 0x8005428C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80054290: lb          $t9, -0x24FF($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X24FF);
    // 0x80054294: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80054298: bne         $t9, $at, L_800543D8
    if (ctx->r25 != ctx->r1) {
        // 0x8005429C: nop
    
            goto L_800543D8;
    }
    // 0x8005429C: nop

L_800542A0:
    // 0x800542A0: lbu         $t0, 0x1F0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1F0);
    // 0x800542A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800542A8: beq         $t0, $zero, L_800542D4
    if (ctx->r8 == 0) {
        // 0x800542AC: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800542D4;
    }
    // 0x800542AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800542B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800542B4: lwc1        $f4, 0xA8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x800542B8: lwc1        $f9, 0x6D58($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6D58);
    // 0x800542BC: lwc1        $f8, 0x6D5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6D5C);
    // 0x800542C0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800542C4: sub.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f6.d - ctx->f8.d;
    // 0x800542C8: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x800542CC: b           L_800542F4
    // 0x800542D0: swc1        $f10, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f10.u32l;
        goto L_800542F4;
    // 0x800542D0: swc1        $f10, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f10.u32l;
L_800542D4:
    // 0x800542D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800542D8: lwc1        $f18, 0xA8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x800542DC: lwc1        $f7, 0x6D60($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6D60);
    // 0x800542E0: lwc1        $f6, 0x6D64($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6D64);
    // 0x800542E4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800542E8: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x800542EC: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x800542F0: swc1        $f16, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f16.u32l;
L_800542F4:
    // 0x800542F4: addiu       $t1, $sp, 0xA4
    ctx->r9 = ADD32(ctx->r29, 0XA4);
    // 0x800542F8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800542FC: addiu       $a2, $sp, 0xA8
    ctx->r6 = ADD32(ctx->r29, 0XA8);
    // 0x80054300: jal         0x800590C0
    // 0x80054304: addiu       $a3, $sp, 0xA0
    ctx->r7 = ADD32(ctx->r29, 0XA0);
    set_position_goal_from_path(rdram, ctx);
        goto after_10;
    // 0x80054304: addiu       $a3, $sp, 0xA0
    ctx->r7 = ADD32(ctx->r29, 0XA0);
    after_10:
    // 0x80054308: lbu         $t2, 0x1F0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1F0);
    // 0x8005430C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054310: beq         $t2, $zero, L_8005433C
    if (ctx->r10 == 0) {
        // 0x80054314: nop
    
            goto L_8005433C;
    }
    // 0x80054314: nop

    // 0x80054318: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005431C: lwc1        $f10, 0xA8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x80054320: lwc1        $f5, 0x6D68($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6D68);
    // 0x80054324: lwc1        $f4, 0x6D6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6D6C);
    // 0x80054328: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8005432C: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80054330: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80054334: b           L_80054358
    // 0x80054338: swc1        $f8, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f8.u32l;
        goto L_80054358;
    // 0x80054338: swc1        $f8, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f8.u32l;
L_8005433C:
    // 0x8005433C: lwc1        $f16, 0xA8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x80054340: lwc1        $f19, 0x6D70($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6D70);
    // 0x80054344: lwc1        $f18, 0x6D74($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6D74);
    // 0x80054348: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8005434C: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x80054350: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80054354: swc1        $f6, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f6.u32l;
L_80054358:
    // 0x80054358: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8005435C: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80054360: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80054364: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80054368: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x8005436C: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80054370: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80054374: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80054378: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x8005437C: mul.s       $f16, $f6, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80054380: jal         0x800CA030
    // 0x80054384: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_11;
    // 0x80054384: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    after_11:
    // 0x80054388: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8005438C: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80054390: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80054394: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80054398: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005439C: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    // 0x800543A0: lui         $at, 0x4118
    ctx->r1 = S32(0X4118 << 16);
    // 0x800543A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800543A8: div.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800543AC: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800543B0: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x800543B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800543B8: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x800543BC: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x800543C0: lwc1        $f16, 0xA4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800543C4: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x800543C8: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800543CC: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
    // 0x800543D0: b           L_800543F0
    // 0x800543D4: sb          $t3, 0x1F0($s0)
    MEM_B(0X1F0, ctx->r16) = ctx->r11;
        goto L_800543F0;
    // 0x800543D4: sb          $t3, 0x1F0($s0)
    MEM_B(0X1F0, ctx->r16) = ctx->r11;
L_800543D8:
    // 0x800543D8: lb          $t4, 0x1E2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E2);
    // 0x800543DC: nop

    // 0x800543E0: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x800543E4: bne         $at, $zero, L_800543F0
    if (ctx->r1 != 0) {
        // 0x800543E8: nop
    
            goto L_800543F0;
    }
    // 0x800543E8: nop

    // 0x800543EC: sb          $zero, 0x1F0($s0)
    MEM_B(0X1F0, ctx->r16) = 0;
L_800543F0:
    // 0x800543F0: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
    // 0x800543F4: lh          $t5, 0x1A2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A2);
    // 0x800543F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800543FC: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x80054400: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80054404: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80054408: lwc1        $f8, -0x2510($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2510);
    // 0x8005440C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80054410: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x80054414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80054418: div.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8005441C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80054420: nop

    // 0x80054424: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80054428: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005442C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80054430: nop

    // 0x80054434: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80054438: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8005443C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80054440: subu        $v0, $t9, $v0
    ctx->r2 = SUB32(ctx->r25, ctx->r2);
    // 0x80054444: bgez        $v0, L_80054454
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80054448: slti        $at, $v0, 0x4A
        ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
            goto L_80054454;
    }
    // 0x80054448: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
    // 0x8005444C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80054450: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
L_80054454:
    // 0x80054454: bne         $at, $zero, L_80054460
    if (ctx->r1 != 0) {
        // 0x80054458: nop
    
            goto L_80054460;
    }
    // 0x80054458: nop

    // 0x8005445C: addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
L_80054460:
    // 0x80054460: jal         0x8005238C
    // 0x80054464: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    slowly_reset_head_angle(rdram, ctx);
        goto after_12;
    // 0x80054464: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    after_12:
    // 0x80054468: lh          $a0, 0x1A2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X1A2);
    // 0x8005446C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80054470: lw          $t0, -0x252C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X252C);
    // 0x80054474: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x80054478: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005447C: subu        $v0, $t0, $t1
    ctx->r2 = SUB32(ctx->r8, ctx->r9);
    // 0x80054480: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80054484: lw          $t3, 0xB8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB8);
    // 0x80054488: bne         $at, $zero, L_80054498
    if (ctx->r1 != 0) {
        // 0x8005448C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80054498;
    }
    // 0x8005448C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80054490: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80054494: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80054498:
    // 0x80054498: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x8005449C: beq         $at, $zero, L_800544A8
    if (ctx->r1 == 0) {
        // 0x800544A0: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800544A8;
    }
    // 0x800544A0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800544A4: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_800544A8:
    // 0x800544A8: sra         $t2, $v0, 2
    ctx->r10 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800544AC: slti        $at, $t2, 0x2EF
    ctx->r1 = SIGNED(ctx->r10) < 0X2EF ? 1 : 0;
    // 0x800544B0: bne         $at, $zero, L_800544BC
    if (ctx->r1 != 0) {
        // 0x800544B4: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800544BC;
    }
    // 0x800544B4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800544B8: addiu       $v0, $zero, 0x2EE
    ctx->r2 = ADD32(0, 0X2EE);
L_800544BC:
    // 0x800544BC: slti        $at, $v0, -0x2EE
    ctx->r1 = SIGNED(ctx->r2) < -0X2EE ? 1 : 0;
    // 0x800544C0: beq         $at, $zero, L_800544CC
    if (ctx->r1 == 0) {
        // 0x800544C4: nop
    
            goto L_800544CC;
    }
    // 0x800544C4: nop

    // 0x800544C8: addiu       $v0, $zero, -0x2EE
    ctx->r2 = ADD32(0, -0X2EE);
L_800544CC:
    // 0x800544CC: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800544D0: lh          $t6, 0x1A0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A0);
    // 0x800544D4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800544D8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800544DC: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x800544E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800544E4: mflo        $t4
    ctx->r12 = lo;
    // 0x800544E8: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x800544EC: sh          $t5, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r13;
    // 0x800544F0: lh          $t7, 0x1A2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A2);
    // 0x800544F4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800544F8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800544FC: sh          $t8, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r24;
    // 0x80054500: lh          $v1, 0x1A6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A6);
    // 0x80054504: lw          $t9, -0x2528($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2528);
    // 0x80054508: lw          $t1, 0xB8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB8);
    // 0x8005450C: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x80054510: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054514: lh          $t5, 0x1A4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A4);
    // 0x80054518: mflo        $t2
    ctx->r10 = lo;
    // 0x8005451C: sra         $t3, $t2, 4
    ctx->r11 = S32(SIGNED(ctx->r10) >> 4);
    // 0x80054520: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x80054524: sh          $t4, 0x1A6($s0)
    MEM_H(0X1A6, ctx->r16) = ctx->r12;
    // 0x80054528: lh          $t6, 0x1A6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A6);
    // 0x8005452C: nop

    // 0x80054530: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80054534: sh          $t7, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r15;
    // 0x80054538: lbu         $t8, 0x1F0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1F0);
    // 0x8005453C: nop

    // 0x80054540: bne         $t8, $zero, L_800545A8
    if (ctx->r24 != 0) {
        // 0x80054544: nop
    
            goto L_800545A8;
    }
    // 0x80054544: nop

    // 0x80054548: lh          $t9, 0x1A0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A0);
    // 0x8005454C: lw          $t0, 0x10C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10C);
    // 0x80054550: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80054554: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80054558: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8005455C: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x80054560: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x80054564: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x80054568: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x8005456C: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x80054570: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x80054574: jal         0x800700B4
    // 0x80054578: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_13;
    // 0x80054578: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    after_13:
    // 0x8005457C: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x80054580: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    // 0x80054584: addiu       $t2, $s1, 0x1C
    ctx->r10 = ADD32(ctx->r17, 0X1C);
    // 0x80054588: addiu       $t3, $sp, 0xAC
    ctx->r11 = ADD32(ctx->r29, 0XAC);
    // 0x8005458C: addiu       $t4, $s1, 0x24
    ctx->r12 = ADD32(ctx->r17, 0X24);
    // 0x80054590: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80054594: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80054598: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005459C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800545A0: jal         0x8006F88C
    // 0x800545A4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    mtxf_transform_point(rdram, ctx);
        goto after_14;
    // 0x800545A4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_14:
L_800545A8:
    // 0x800545A8: lb          $t5, 0x175($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X175);
    // 0x800545AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800545B0: beq         $t5, $zero, L_800545D0
    if (ctx->r13 == 0) {
        // 0x800545B4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800545D0;
    }
    // 0x800545B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800545B8: lwc1        $f6, -0x2508($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2508);
    // 0x800545BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800545C0: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x800545C4: lwc1        $f4, -0x2504($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2504);
    // 0x800545C8: nop

    // 0x800545CC: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
L_800545D0:
    // 0x800545D0: lw          $t6, 0x148($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X148);
    // 0x800545D4: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
    // 0x800545D8: bne         $t6, $zero, L_80054680
    if (ctx->r14 != 0) {
        // 0x800545DC: nop
    
            goto L_80054680;
    }
    // 0x800545DC: nop

    // 0x800545E0: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800545E4: nop

    // 0x800545E8: swc1        $f8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f8.u32l;
    // 0x800545EC: lwc1        $f16, 0x24($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800545F0: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800545F4: swc1        $f16, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f16.u32l;
    // 0x800545F8: lb          $t7, 0x1D2($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D2);
    // 0x800545FC: nop

    // 0x80054600: beq         $t7, $zero, L_80054628
    if (ctx->r15 == 0) {
        // 0x80054604: nop
    
            goto L_80054628;
    }
    // 0x80054604: nop

    // 0x80054608: lwc1        $f10, 0x11C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8005460C: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80054610: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80054614: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x80054618: lwc1        $f8, 0x120($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8005461C: nop

    // 0x80054620: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80054624: swc1        $f16, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f16.u32l;
L_80054628:
    // 0x80054628: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8005462C: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80054630: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80054634: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80054638: lwc1        $f0, 0xBC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8005463C: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x80054640: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80054644: mul.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80054648: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8005464C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80054650: swc1        $f16, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f16.u32l;
    // 0x80054654: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80054658: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005465C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80054660: nop

    // 0x80054664: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80054668: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8005466C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80054670: jal         0x80011570
    // 0x80054674: nop

    move_object(rdram, ctx);
        goto after_15;
    // 0x80054674: nop

    after_15:
    // 0x80054678: b           L_80054688
    // 0x8005467C: nop

        goto L_80054688;
    // 0x8005467C: nop

L_80054680:
    // 0x80054680: jal         0x80050794
    // 0x80054684: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_approach_object(rdram, ctx);
        goto after_16;
    // 0x80054684: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
L_80054688:
    // 0x80054688: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005468C: lw          $t8, -0x2524($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2524);
    // 0x80054690: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054694: bne         $t8, $at, L_800546C4
    if (ctx->r24 != ctx->r1) {
        // 0x80054698: lw          $a2, 0xB8($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB8);
            goto L_800546C4;
    }
    // 0x80054698: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x8005469C: jal         0x8002359C
    // 0x800546A0: nop

    func_80023568(rdram, ctx);
        goto after_17;
    // 0x800546A0: nop

    after_17:
    // 0x800546A4: bne         $v0, $zero, L_800546C0
    if (ctx->r2 != 0) {
        // 0x800546A8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800546C0;
    }
    // 0x800546A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800546AC: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x800546B0: jal         0x80055AC4
    // 0x800546B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    onscreen_ai_racer_physics(rdram, ctx);
        goto after_18;
    // 0x800546B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_18:
    // 0x800546B8: b           L_800546D4
    // 0x800546BC: lb          $t9, 0x201($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X201);
        goto L_800546D4;
    // 0x800546BC: lb          $t9, 0x201($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X201);
L_800546C0:
    // 0x800546C0: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
L_800546C4:
    // 0x800546C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800546C8: jal         0x80055010
    // 0x800546CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80054FD0(rdram, ctx);
        goto after_19;
    // 0x800546CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_19:
    // 0x800546D0: lb          $t9, 0x201($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X201);
L_800546D4:
    // 0x800546D4: nop

    // 0x800546D8: bne         $t9, $zero, L_800546E8
    if (ctx->r25 != 0) {
        // 0x800546DC: nop
    
            goto L_800546E8;
    }
    // 0x800546DC: nop

    // 0x800546E0: b           L_80054704
    // 0x800546E4: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
        goto L_80054704;
    // 0x800546E4: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
L_800546E8:
    // 0x800546E8: lb          $t0, 0x1D6($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1D6);
    // 0x800546EC: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    // 0x800546F0: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x800546F4: beq         $at, $zero, L_80054708
    if (ctx->r1 == 0) {
        // 0x800546F8: lw          $a2, 0xBC($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XBC);
            goto L_80054708;
    }
    // 0x800546F8: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
    // 0x800546FC: jal         0x800AFC74
    // 0x80054700: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    update_vehicle_particles(rdram, ctx);
        goto after_20;
    // 0x80054700: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
L_80054704:
    // 0x80054704: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
L_80054708:
    // 0x80054708: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005470C: jal         0x80053790
    // 0x80054710: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80053750(rdram, ctx);
        goto after_21;
    // 0x80054710: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_21:
    // 0x80054714: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80054718: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005471C: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80054720: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80054724: div.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80054728: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005472C: lwc1        $f6, -0x2538($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2538);
    // 0x80054730: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80054734: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80054738: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x8005473C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80054740: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80054744: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x80054748: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005474C: nop

    // 0x80054750: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80054754: lwc1        $f16, 0x84($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80054758: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8005475C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80054760: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80054764: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80054768: swc1        $f8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f8.u32l;
    // 0x8005476C: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80054770: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80054774: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80054778: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8005477C: swc1        $f16, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f16.u32l;
    // 0x80054780: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80054784: lwc1        $f4, -0x2534($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2534);
    // 0x80054788: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8005478C: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80054790: sub.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80054794: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80054798: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8005479C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800547A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800547A4: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800547A8: swc1        $f18, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f18.u32l;
    // 0x800547AC: lw          $t2, 0x10C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X10C);
    // 0x800547B0: lh          $t1, 0x1A0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1A0);
    // 0x800547B4: nop

    // 0x800547B8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800547BC: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x800547C0: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x800547C4: lh          $t5, 0x2($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X2);
    // 0x800547C8: nop

    // 0x800547CC: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x800547D0: sh          $t6, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r14;
    // 0x800547D4: lh          $t7, 0x4($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X4);
    // 0x800547D8: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x800547DC: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x800547E0: sh          $t8, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r24;
    // 0x800547E4: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x800547E8: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x800547EC: jal         0x800700B4
    // 0x800547F0: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_22;
    // 0x800547F0: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    after_22:
    // 0x800547F4: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x800547F8: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x800547FC: addiu       $t9, $sp, 0x9C
    ctx->r25 = ADD32(ctx->r29, 0X9C);
    // 0x80054800: addiu       $t0, $sp, 0xAC
    ctx->r8 = ADD32(ctx->r29, 0XAC);
    // 0x80054804: addiu       $t1, $sp, 0xA0
    ctx->r9 = ADD32(ctx->r29, 0XA0);
    // 0x80054808: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8005480C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80054810: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80054814: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80054818: jal         0x8006F88C
    // 0x8005481C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    mtxf_transform_point(rdram, ctx);
        goto after_23;
    // 0x8005481C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_23:
    // 0x80054820: lb          $v0, 0x1D2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D2);
    // 0x80054824: lwc1        $f16, 0xA0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80054828: beq         $v0, $zero, L_80054858
    if (ctx->r2 == 0) {
        // 0x8005482C: nop
    
            goto L_80054858;
    }
    // 0x8005482C: nop

    // 0x80054830: lw          $t2, 0xB8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB8);
    // 0x80054834: nop

    // 0x80054838: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x8005483C: sb          $t3, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = ctx->r11;
    // 0x80054840: lb          $t4, 0x1D2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D2);
    // 0x80054844: nop

    // 0x80054848: bgez        $t4, L_8005495C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8005484C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005495C;
    }
    // 0x8005484C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80054850: b           L_80054958
    // 0x80054854: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
        goto L_80054958;
    // 0x80054854: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
L_80054858:
    // 0x80054858: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005485C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80054860: sub.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80054864: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80054868: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x8005486C: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80054870: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80054874: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x80054878: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8005487C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80054880: bc1f        L_800548AC
    if (!c1cs) {
        // 0x80054884: lui         $at, 0xBFE0
        ctx->r1 = S32(0XBFE0 << 16);
            goto L_800548AC;
    }
    // 0x80054884: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80054888: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005488C: sub.d       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f0.d - ctx->f2.d;
    // 0x80054890: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80054894: sub.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d - ctx->f10.d;
    // 0x80054898: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8005489C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x800548A0: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800548A4: nop

    // 0x800548A8: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
L_800548AC:
    // 0x800548AC: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800548B0: nop

    // 0x800548B4: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x800548B8: nop

    // 0x800548BC: bc1f        L_800548DC
    if (!c1cs) {
        // 0x800548C0: nop
    
            goto L_800548DC;
    }
    // 0x800548C0: nop

    // 0x800548C4: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800548C8: add.d       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f0.d + ctx->f2.d;
    // 0x800548CC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800548D0: sub.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d - ctx->f10.d;
    // 0x800548D4: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x800548D8: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_800548DC:
    // 0x800548DC: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800548E0: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800548E4: nop

    // 0x800548E8: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800548EC: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
    // 0x800548F0: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800548F4: nop

    // 0x800548F8: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800548FC: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80054900: nop

    // 0x80054904: bc1f        L_80054930
    if (!c1cs) {
        // 0x80054908: nop
    
            goto L_80054930;
    }
    // 0x80054908: nop

    // 0x8005490C: lwc1        $f16, 0x30($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80054910: sub.d       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f0.d - ctx->f2.d;
    // 0x80054914: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80054918: sub.d       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f8.d - ctx->f6.d;
    // 0x8005491C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80054920: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x80054924: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80054928: nop

    // 0x8005492C: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
L_80054930:
    // 0x80054930: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x80054934: nop

    // 0x80054938: bc1f        L_8005495C
    if (!c1cs) {
        // 0x8005493C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005495C;
    }
    // 0x8005493C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80054940: lwc1        $f16, 0x30($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80054944: add.d       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f0.d + ctx->f2.d;
    // 0x80054948: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8005494C: sub.d       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f8.d - ctx->f6.d;
    // 0x80054950: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80054954: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
L_80054958:
    // 0x80054958: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005495C:
    // 0x8005495C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80054960: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80054964: jr          $ra
    // 0x80054968: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80054968: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void shadow_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D91C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8002D920: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002D924: lw          $t6, -0x49B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X49B8);
    // 0x8002D928: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002D92C: addiu       $v1, $v1, -0x49B4
    ctx->r3 = ADD32(ctx->r3, -0X49B4);
    // 0x8002D930: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8002D934: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002D938: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8002D93C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002D940: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8002D944: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002D948: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8002D94C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002D950: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8002D954: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8002D958: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002D95C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002D960: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002D964: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8002D968: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002D96C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002D970: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002D974: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8002D978: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x8002D97C: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x8002D980: bne         $a0, $at, L_8002D990
    if (ctx->r4 != ctx->r1) {
        // 0x8002D984: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8002D990;
    }
    // 0x8002D984: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002D988: addiu       $t8, $t6, 0x2
    ctx->r24 = ADD32(ctx->r14, 0X2);
    // 0x8002D98C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8002D990:
    // 0x8002D990: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002D994: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002D998: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8002D99C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8002D9A0: lw          $t0, -0x2760($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2760);
    // 0x8002D9A4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002D9A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D9AC: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8002D9B0: lw          $t1, -0x2748($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2748);
    // 0x8002D9B4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8002D9B8: sw          $t0, -0x2750($at)
    MEM_W(-0X2750, ctx->r1) = ctx->r8;
    // 0x8002D9BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D9C0: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x8002D9C4: lw          $t2, -0x2730($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2730);
    // 0x8002D9C8: sw          $t1, -0x2738($at)
    MEM_W(-0X2738, ctx->r1) = ctx->r9;
    // 0x8002D9CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D9D0: sw          $t2, -0x2720($at)
    MEM_W(-0X2720, ctx->r1) = ctx->r10;
    // 0x8002D9D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D9D8: sw          $zero, -0x271C($at)
    MEM_W(-0X271C, ctx->r1) = 0;
    // 0x8002D9DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D9E0: sw          $zero, -0x2718($at)
    MEM_W(-0X2718, ctx->r1) = 0;
    // 0x8002D9E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D9E8: jal         0x80066450
    // 0x8002D9EC: sw          $zero, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = 0;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8002D9EC: sw          $zero, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = 0;
    after_0:
    // 0x8002D9F0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8002D9F4: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8002D9F8: jal         0x8000E988
    // 0x8002D9FC: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    objGetObjList(rdram, ctx);
        goto after_1;
    // 0x8002D9FC: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_1:
    // 0x8002DA00: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x8002DA04: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x8002DA08: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x8002DA0C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8002DA10: beq         $at, $zero, L_8002DDE0
    if (ctx->r1 == 0) {
        // 0x8002DA14: addiu       $s7, $zero, 0x5
        ctx->r23 = ADD32(0, 0X5);
            goto L_8002DDE0;
    }
    // 0x8002DA14: addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
    // 0x8002DA18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002DA1C: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8002DA20: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8002DA24: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8002DA28: addiu       $s5, $s5, -0x29AC
    ctx->r21 = ADD32(ctx->r21, -0X29AC);
    // 0x8002DA2C: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x8002DA30: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x8002DA34: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
L_8002DA38:
    // 0x8002DA38: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8002DA3C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002DA40: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8002DA44: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x8002DA48: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8002DA4C: lw          $s2, 0x40($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X40);
    // 0x8002DA50: lw          $s0, 0x58($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X58);
    // 0x8002DA54: lw          $v0, 0x50($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X50);
    // 0x8002DA58: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x8002DA5C: lh          $v1, 0x6($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X6);
    // 0x8002DA60: nop

    // 0x8002DA64: andi        $t0, $v1, 0x8000
    ctx->r8 = ctx->r3 & 0X8000;
    // 0x8002DA68: bne         $t0, $zero, L_8002DDCC
    if (ctx->r8 != 0) {
        // 0x8002DA6C: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DDCC;
    }
    // 0x8002DA6C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DA70: beq         $v0, $zero, L_8002DAB0
    if (ctx->r2 == 0) {
        // 0x8002DA74: andi        $t2, $v1, 0x4000
        ctx->r10 = ctx->r3 & 0X4000;
            goto L_8002DAB0;
    }
    // 0x8002DA74: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
    // 0x8002DA78: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002DA7C: nop

    // 0x8002DA80: c.lt.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl < ctx->f4.fl;
    // 0x8002DA84: nop

    // 0x8002DA88: bc1f        L_8002DAB0
    if (!c1cs) {
        // 0x8002DA8C: andi        $t2, $v1, 0x4000
        ctx->r10 = ctx->r3 & 0X4000;
            goto L_8002DAB0;
    }
    // 0x8002DA8C: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
    // 0x8002DA90: lh          $t1, 0x32($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X32);
    // 0x8002DA94: nop

    // 0x8002DA98: bne         $fp, $t1, L_8002DAB0
    if (ctx->r30 != ctx->r9) {
        // 0x8002DA9C: andi        $t2, $v1, 0x4000
        ctx->r10 = ctx->r3 & 0X4000;
            goto L_8002DAB0;
    }
    // 0x8002DA9C: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
    // 0x8002DAA0: sh          $s3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r19;
    // 0x8002DAA4: lh          $v1, 0x6($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X6);
    // 0x8002DAA8: nop

    // 0x8002DAAC: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
L_8002DAB0:
    // 0x8002DAB0: beq         $t2, $zero, L_8002DABC
    if (ctx->r10 == 0) {
        // 0x8002DAB4: nop
    
            goto L_8002DABC;
    }
    // 0x8002DAB4: nop

    // 0x8002DAB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002DABC:
    // 0x8002DABC: beq         $v0, $zero, L_8002DAD4
    if (ctx->r2 == 0) {
        // 0x8002DAC0: nop
    
            goto L_8002DAD4;
    }
    // 0x8002DAC0: nop

    // 0x8002DAC4: lh          $t3, 0x32($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X32);
    // 0x8002DAC8: nop

    // 0x8002DACC: beq         $s4, $t3, L_8002DAEC
    if (ctx->r20 == ctx->r11) {
        // 0x8002DAD0: nop
    
            goto L_8002DAEC;
    }
    // 0x8002DAD0: nop

L_8002DAD4:
    // 0x8002DAD4: beq         $s0, $zero, L_8002DB0C
    if (ctx->r16 == 0) {
        // 0x8002DAD8: nop
    
            goto L_8002DB0C;
    }
    // 0x8002DAD8: nop

    // 0x8002DADC: lh          $t4, 0x36($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X36);
    // 0x8002DAE0: nop

    // 0x8002DAE4: bne         $s4, $t4, L_8002DB0C
    if (ctx->r20 != ctx->r12) {
        // 0x8002DAE8: nop
    
            goto L_8002DB0C;
    }
    // 0x8002DAE8: nop

L_8002DAEC:
    // 0x8002DAEC: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8002DAF0: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8002DAF4: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x8002DAF8: jal         0x80066588
    // 0x8002DAFC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    get_distance_to_active_camera(rdram, ctx);
        goto after_2;
    // 0x8002DAFC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8002DB00: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8002DB04: b           L_8002DB14
    // 0x8002DB08: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_8002DB14;
    // 0x8002DB08: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_8002DB0C:
    // 0x8002DB0C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8002DB10: nop

L_8002DB14:
    // 0x8002DB14: beq         $v0, $zero, L_8002DC48
    if (ctx->r2 == 0) {
        // 0x8002DB18: nop
    
            goto L_8002DC48;
    }
    // 0x8002DB18: nop

    // 0x8002DB1C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002DB20: nop

    // 0x8002DB24: c.lt.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl < ctx->f6.fl;
    // 0x8002DB28: nop

    // 0x8002DB2C: bc1f        L_8002DC48
    if (!c1cs) {
        // 0x8002DB30: nop
    
            goto L_8002DC48;
    }
    // 0x8002DB30: nop

    // 0x8002DB34: lh          $t5, 0x32($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X32);
    // 0x8002DB38: nop

    // 0x8002DB3C: bne         $fp, $t5, L_8002DC48
    if (ctx->r30 != ctx->r13) {
        // 0x8002DB40: nop
    
            goto L_8002DC48;
    }
    // 0x8002DB40: nop

    // 0x8002DB44: swc1        $f24, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f24.u32l;
    // 0x8002DB48: sh          $s3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r19;
    // 0x8002DB4C: lh          $t7, 0x32($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X32);
    // 0x8002DB50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002DB54: bne         $s4, $t7, L_8002DBBC
    if (ctx->r20 != ctx->r15) {
        // 0x8002DB58: nop
    
            goto L_8002DBBC;
    }
    // 0x8002DB58: nop

    // 0x8002DB5C: blez        $s6, L_8002DBBC
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8002DB60: slti        $at, $s6, 0x4
        ctx->r1 = SIGNED(ctx->r22) < 0X4 ? 1 : 0;
            goto L_8002DBBC;
    }
    // 0x8002DB60: slti        $at, $s6, 0x4
    ctx->r1 = SIGNED(ctx->r22) < 0X4 ? 1 : 0;
    // 0x8002DB64: beq         $at, $zero, L_8002DBBC
    if (ctx->r1 == 0) {
        // 0x8002DB68: nop
    
            goto L_8002DBBC;
    }
    // 0x8002DB68: nop

    // 0x8002DB6C: lh          $v0, 0x48($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X48);
    // 0x8002DB70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002DB74: bne         $v0, $at, L_8002DBA4
    if (ctx->r2 != ctx->r1) {
        // 0x8002DB78: nop
    
            goto L_8002DBA4;
    }
    // 0x8002DB78: nop

    // 0x8002DB7C: lw          $t8, 0x64($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X64);
    // 0x8002DB80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002DB84: lh          $v0, 0x0($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X0);
    // 0x8002DB88: nop

    // 0x8002DB8C: beq         $v0, $s3, L_8002DC28
    if (ctx->r2 == ctx->r19) {
        // 0x8002DB90: nop
    
            goto L_8002DC28;
    }
    // 0x8002DB90: nop

    // 0x8002DB94: jal         0x8002E274
    // 0x8002DB98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_generate(rdram, ctx);
        goto after_3;
    // 0x8002DB98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8002DB9C: b           L_8002DC28
    // 0x8002DBA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8002DC28;
    // 0x8002DBA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002DBA4:
    // 0x8002DBA4: bne         $s7, $v0, L_8002DC28
    if (ctx->r23 != ctx->r2) {
        // 0x8002DBA8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8002DC28;
    }
    // 0x8002DBA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002DBAC: jal         0x8002E274
    // 0x8002DBB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_generate(rdram, ctx);
        goto after_4;
    // 0x8002DBB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8002DBB4: b           L_8002DC28
    // 0x8002DBB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8002DC28;
    // 0x8002DBB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002DBBC:
    // 0x8002DBBC: lh          $v1, 0x4A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X4A);
    // 0x8002DBC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002DBC4: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8002DBC8: nop

    // 0x8002DBCC: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002DBD0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8002DBD4: nop

    // 0x8002DBD8: bc1f        L_8002DC28
    if (!c1cs) {
        // 0x8002DBDC: nop
    
            goto L_8002DC28;
    }
    // 0x8002DBDC: nop

    // 0x8002DBE0: lh          $v0, 0x4C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4C);
    // 0x8002DBE4: nop

    // 0x8002DBE8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8002DBEC: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
    // 0x8002DBF0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002DBF4: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x8002DBF8: nop

    // 0x8002DBFC: bc1f        L_8002DC1C
    if (!c1cs) {
        // 0x8002DC00: nop
    
            goto L_8002DC1C;
    }
    // 0x8002DC00: nop

    // 0x8002DC04: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002DC08: sub.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8002DC0C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002DC10: nop

    // 0x8002DC14: div.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8002DC18: swc1        $f8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f8.u32l;
L_8002DC1C:
    // 0x8002DC1C: jal         0x8002E274
    // 0x8002DC20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_generate(rdram, ctx);
        goto after_5;
    // 0x8002DC20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8002DC24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002DC28:
    // 0x8002DC28: bne         $a0, $zero, L_8002DC48
    if (ctx->r4 != 0) {
        // 0x8002DC2C: nop
    
            goto L_8002DC48;
    }
    // 0x8002DC2C: nop

    // 0x8002DC30: lw          $t9, 0x54($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X54);
    // 0x8002DC34: nop

    // 0x8002DC38: beq         $t9, $zero, L_8002DC48
    if (ctx->r25 == 0) {
        // 0x8002DC3C: nop
    
            goto L_8002DC48;
    }
    // 0x8002DC3C: nop

    // 0x8002DC40: jal         0x8002DE70
    // 0x8002DC44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8002DE30(rdram, ctx);
        goto after_6;
    // 0x8002DC44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
L_8002DC48:
    // 0x8002DC48: beq         $s0, $zero, L_8002DDCC
    if (ctx->r16 == 0) {
        // 0x8002DC4C: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DDCC;
    }
    // 0x8002DC4C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DC50: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8002DC54: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x8002DC58: c.lt.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl < ctx->f10.fl;
    // 0x8002DC5C: nop

    // 0x8002DC60: bc1f        L_8002DDCC
    if (!c1cs) {
        // 0x8002DC64: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DDCC;
    }
    // 0x8002DC64: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DC68: lh          $t1, 0x36($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X36);
    // 0x8002DC6C: nop

    // 0x8002DC70: bne         $t0, $t1, L_8002DDCC
    if (ctx->r8 != ctx->r9) {
        // 0x8002DC74: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DDCC;
    }
    // 0x8002DC74: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DC78: sh          $s3, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r19;
    // 0x8002DC7C: swc1        $f24, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f24.u32l;
    // 0x8002DC80: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8002DC84: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x8002DC88: beq         $a0, $zero, L_8002DCF0
    if (ctx->r4 == 0) {
        // 0x8002DC8C: nop
    
            goto L_8002DCF0;
    }
    // 0x8002DC8C: nop

    // 0x8002DC90: beq         $t2, $zero, L_8002DCF0
    if (ctx->r10 == 0) {
        // 0x8002DC94: nop
    
            goto L_8002DCF0;
    }
    // 0x8002DC94: nop

    // 0x8002DC98: lhu         $t3, 0x12($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X12);
    // 0x8002DC9C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x8002DCA0: beq         $t3, $at, L_8002DCF0
    if (ctx->r11 == ctx->r1) {
        // 0x8002DCA4: nop
    
            goto L_8002DCF0;
    }
    // 0x8002DCA4: nop

    // 0x8002DCA8: lh          $t4, 0xC($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XC);
    // 0x8002DCAC: lh          $t5, 0xE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE);
    // 0x8002DCB0: nop

    // 0x8002DCB4: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8002DCB8: sh          $t7, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r15;
    // 0x8002DCBC: lh          $v1, 0xC($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XC);
    // 0x8002DCC0: lhu         $v0, 0x12($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X12);
    // 0x8002DCC4: nop

    // 0x8002DCC8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002DCCC: beq         $at, $zero, L_8002DCF0
    if (ctx->r1 == 0) {
        // 0x8002DCD0: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_8002DCF0;
    }
    // 0x8002DCD0: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_8002DCD4:
    // 0x8002DCD4: sh          $t8, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r24;
    // 0x8002DCD8: lh          $v1, 0xC($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XC);
    // 0x8002DCDC: lhu         $v0, 0x12($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X12);
    // 0x8002DCE0: nop

    // 0x8002DCE4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002DCE8: bne         $at, $zero, L_8002DCD4
    if (ctx->r1 != 0) {
        // 0x8002DCEC: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_8002DCD4;
    }
    // 0x8002DCEC: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_8002DCF0:
    // 0x8002DCF0: lh          $t6, 0x32($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X32);
    // 0x8002DCF4: nop

    // 0x8002DCF8: bne         $s4, $t6, L_8002DD60
    if (ctx->r20 != ctx->r14) {
        // 0x8002DCFC: nop
    
            goto L_8002DD60;
    }
    // 0x8002DCFC: nop

    // 0x8002DD00: blez        $s6, L_8002DD60
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8002DD04: slti        $at, $s6, 0x4
        ctx->r1 = SIGNED(ctx->r22) < 0X4 ? 1 : 0;
            goto L_8002DD60;
    }
    // 0x8002DD04: slti        $at, $s6, 0x4
    ctx->r1 = SIGNED(ctx->r22) < 0X4 ? 1 : 0;
    // 0x8002DD08: beq         $at, $zero, L_8002DD60
    if (ctx->r1 == 0) {
        // 0x8002DD0C: nop
    
            goto L_8002DD60;
    }
    // 0x8002DD0C: nop

    // 0x8002DD10: lh          $v0, 0x48($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X48);
    // 0x8002DD14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002DD18: bne         $v0, $at, L_8002DD48
    if (ctx->r2 != ctx->r1) {
        // 0x8002DD1C: nop
    
            goto L_8002DD48;
    }
    // 0x8002DD1C: nop

    // 0x8002DD20: lw          $t9, 0x64($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X64);
    // 0x8002DD24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002DD28: lh          $v0, 0x0($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X0);
    // 0x8002DD2C: nop

    // 0x8002DD30: beq         $v0, $s3, L_8002DDCC
    if (ctx->r2 == ctx->r19) {
        // 0x8002DD34: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DDCC;
    }
    // 0x8002DD34: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DD38: jal         0x8002E274
    // 0x8002DD3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    shadow_generate(rdram, ctx);
        goto after_7;
    // 0x8002DD3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8002DD40: b           L_8002DDCC
    // 0x8002DD44: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
        goto L_8002DDCC;
    // 0x8002DD44: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
L_8002DD48:
    // 0x8002DD48: bne         $s7, $v0, L_8002DDC8
    if (ctx->r23 != ctx->r2) {
        // 0x8002DD4C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8002DDC8;
    }
    // 0x8002DD4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002DD50: jal         0x8002E274
    // 0x8002DD54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    shadow_generate(rdram, ctx);
        goto after_8;
    // 0x8002DD54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8002DD58: b           L_8002DDCC
    // 0x8002DD5C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
        goto L_8002DDCC;
    // 0x8002DD5C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
L_8002DD60:
    // 0x8002DD60: lh          $v1, 0x4A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X4A);
    // 0x8002DD64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002DD68: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x8002DD6C: nop

    // 0x8002DD70: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002DD74: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8002DD78: nop

    // 0x8002DD7C: bc1f        L_8002DDCC
    if (!c1cs) {
        // 0x8002DD80: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DDCC;
    }
    // 0x8002DD80: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DD84: lh          $v0, 0x4C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4C);
    // 0x8002DD88: nop

    // 0x8002DD8C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8002DD90: subu        $t0, $v1, $v0
    ctx->r8 = SUB32(ctx->r3, ctx->r2);
    // 0x8002DD94: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002DD98: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x8002DD9C: nop

    // 0x8002DDA0: bc1f        L_8002DDC0
    if (!c1cs) {
        // 0x8002DDA4: nop
    
            goto L_8002DDC0;
    }
    // 0x8002DDA4: nop

    // 0x8002DDA8: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8002DDAC: sub.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8002DDB0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002DDB4: nop

    // 0x8002DDB8: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8002DDBC: swc1        $f16, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f16.u32l;
L_8002DDC0:
    // 0x8002DDC0: jal         0x8002E274
    // 0x8002DDC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    shadow_generate(rdram, ctx);
        goto after_9;
    // 0x8002DDC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_8002DDC8:
    // 0x8002DDC8: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
L_8002DDCC:
    // 0x8002DDCC: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x8002DDD0: nop

    // 0x8002DDD4: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8002DDD8: bne         $at, $zero, L_8002DA38
    if (ctx->r1 != 0) {
        // 0x8002DDDC: lw          $t6, 0x94($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X94);
            goto L_8002DA38;
    }
    // 0x8002DDDC: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
L_8002DDE0:
    // 0x8002DDE0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002DDE4: addiu       $v1, $v1, -0x271C
    ctx->r3 = ADD32(ctx->r3, -0X271C);
    // 0x8002DDE8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002DDEC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8002DDF0: addiu       $v0, $v0, -0x2720
    ctx->r2 = ADD32(ctx->r2, -0X2720);
    // 0x8002DDF4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8002DDF8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8002DDFC: lw          $t3, -0x2718($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2718);
    // 0x8002DE00: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x8002DE04: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x8002DE08: sh          $t3, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r11;
    // 0x8002DE0C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8002DE10: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8002DE14: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002DE18: lw          $t6, -0x2714($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2714);
    // 0x8002DE1C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8002DE20: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8002DE24: sh          $t6, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r14;
    // 0x8002DE28: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8002DE2C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8002DE30: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8002DE34: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8002DE38: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8002DE3C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8002DE40: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8002DE44: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8002DE48: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8002DE4C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002DE50: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002DE54: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002DE58: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002DE5C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002DE60: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002DE64: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002DE68: jr          $ra
    // 0x8002DE6C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8002DE6C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void gzip_inflate_fixed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C733C: addiu       $sp, $sp, -0x530
    ctx->r29 = ADD32(ctx->r29, -0X530);
    // 0x800C7340: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C7344: addi        $t3, $sp, 0x44
    ctx->r11 = ADD32(ctx->r29, 0X44);
    // 0x800C7348: addiu       $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
    // 0x800C734C: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_800C7350:
    // 0x800C7350: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800C7354: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C7358: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800C735C: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x800C7360: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x800C7364: bne         $t0, $zero, L_800C7350
    if (ctx->r8 != 0) {
        // 0x800C7368: addiu       $t3, $t3, 0x10
        ctx->r11 = ADD32(ctx->r11, 0X10);
            goto L_800C7350;
    }
    // 0x800C7368: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x800C736C: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x800C7370: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
L_800C7374:
    // 0x800C7374: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800C7378: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C737C: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800C7380: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x800C7384: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x800C7388: bne         $t0, $zero, L_800C7374
    if (ctx->r8 != 0) {
        // 0x800C738C: addiu       $t3, $t3, 0x10
        ctx->r11 = ADD32(ctx->r11, 0X10);
            goto L_800C7374;
    }
    // 0x800C738C: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x800C7390: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x800C7394: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
L_800C7398:
    // 0x800C7398: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800C739C: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C73A0: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800C73A4: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x800C73A8: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x800C73AC: bne         $t0, $zero, L_800C7398
    if (ctx->r8 != 0) {
        // 0x800C73B0: addiu       $t3, $t3, 0x10
        ctx->r11 = ADD32(ctx->r11, 0X10);
            goto L_800C7398;
    }
    // 0x800C73B0: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x800C73B4: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x800C73B8: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C73BC: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800C73C0: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x800C73C4: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x800C73C8: sw          $t1, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r9;
    // 0x800C73CC: sw          $t1, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r9;
    // 0x800C73D0: sw          $t1, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r9;
    // 0x800C73D4: sw          $t1, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r9;
    // 0x800C73D8: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800C73DC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800C73E0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C73E4: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800C73E8: addiu       $v0, $v0, -0x666E
    ctx->r2 = ADD32(ctx->r2, -0X666E);
    // 0x800C73EC: addi        $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // 0x800C73F0: addi        $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x800C73F4: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800C73F8: addiu       $a1, $zero, 0x120
    ctx->r5 = ADD32(0, 0X120);
    // 0x800C73FC: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x800C7400: addiu       $a3, $a3, -0x66AC
    ctx->r7 = ADD32(ctx->r7, -0X66AC);
    // 0x800C7404: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C7408: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800C740C: jal         0x800C67D4
    // 0x800C7410: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    gzip_huft_build(rdram, ctx);
        goto after_0;
    // 0x800C7410: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_0:
    // 0x800C7414: addi        $t3, $sp, 0x44
    ctx->r11 = ADD32(ctx->r29, 0X44);
    // 0x800C7418: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x800C741C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
L_800C7420:
    // 0x800C7420: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800C7424: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C7428: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800C742C: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x800C7430: bne         $t0, $zero, L_800C7420
    if (ctx->r8 != 0) {
        // 0x800C7434: addiu       $t3, $t3, 0xC
        ctx->r11 = ADD32(ctx->r11, 0XC);
            goto L_800C7420;
    }
    // 0x800C7434: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x800C7438: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C743C: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800C7440: addiu       $v0, $v0, -0x6612
    ctx->r2 = ADD32(ctx->r2, -0X6612);
    // 0x800C7444: addi        $v1, $sp, 0x28
    ctx->r3 = ADD32(ctx->r29, 0X28);
    // 0x800C7448: addi        $t0, $sp, 0x2C
    ctx->r8 = ADD32(ctx->r29, 0X2C);
    // 0x800C744C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x800C7450: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800C7454: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800C7458: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C745C: addiu       $a3, $a3, -0x664E
    ctx->r7 = ADD32(ctx->r7, -0X664E);
    // 0x800C7460: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C7464: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800C7468: jal         0x800C67D4
    // 0x800C746C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    gzip_huft_build(rdram, ctx);
        goto after_1;
    // 0x800C746C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_1:
    // 0x800C7470: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C7474: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800C7478: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C747C: jal         0x800C75A0
    // 0x800C7480: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    gzip_inflate_codes(rdram, ctx);
        goto after_2;
    // 0x800C7480: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x800C7484: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7488: addiu       $sp, $sp, 0x530
    ctx->r29 = ADD32(ctx->r29, 0X530);
    // 0x800C748C: jr          $ra
    // 0x800C7490: nop

    return;
    // 0x800C7490: nop

;}
RECOMP_FUNC void get_save_file_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C6E4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C6E8: lw          $v0, -0x5B4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B4);
    // 0x8009C6EC: jr          $ra
    // 0x8009C6F0: nop

    return;
    // 0x8009C6F0: nop

;}
RECOMP_FUNC void filename_decompress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097C34: addu        $t6, $a1, $a2
    ctx->r14 = ADD32(ctx->r5, ctx->r6);
    // 0x80097C38: addiu       $v1, $a2, -0x1
    ctx->r3 = ADD32(ctx->r6, -0X1);
    // 0x80097C3C: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80097C40: bltz        $v1, L_80097C78
    if (SIGNED(ctx->r3) < 0) {
        // 0x80097C44: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80097C78;
    }
    // 0x80097C44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80097C48: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x80097C4C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80097C50: addiu       $a1, $a1, 0x14EC
    ctx->r5 = ADD32(ctx->r5, 0X14EC);
L_80097C54:
    // 0x80097C54: andi        $t7, $a0, 0x1F
    ctx->r15 = ctx->r4 & 0X1F;
    // 0x80097C58: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x80097C5C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80097C60: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80097C64: srl         $t0, $a0, 5
    ctx->r8 = S32(U32(ctx->r4) >> 5);
    // 0x80097C68: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80097C6C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80097C70: bgez        $v0, L_80097C54
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80097C74: sb          $t9, 0x1($v1)
        MEM_B(0X1, ctx->r3) = ctx->r25;
            goto L_80097C54;
    }
    // 0x80097C74: sb          $t9, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r25;
L_80097C78:
    // 0x80097C78: jr          $ra
    // 0x80097C7C: nop

    return;
    // 0x80097C7C: nop

;}
RECOMP_FUNC void free_3d_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060180: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80060184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060188: beq         $a0, $zero, L_80060288
    if (ctx->r4 == 0) {
        // 0x8006018C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80060288;
    }
    // 0x8006018C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80060190: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80060194: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80060198: lh          $t6, 0x30($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X30);
    // 0x8006019C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800601A0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800601A4: sh          $t7, 0x30($a1)
    MEM_H(0X30, ctx->r5) = ctx->r15;
    // 0x800601A8: lh          $t8, 0x30($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X30);
    // 0x800601AC: nop

    // 0x800601B0: blez        $t8, L_800601C8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800601B4: nop
    
            goto L_800601C8;
    }
    // 0x800601B4: nop

    // 0x800601B8: jal         0x80071380
    // 0x800601BC: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800601BC: nop

    after_0:
    // 0x800601C0: b           L_8006028C
    // 0x800601C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006028C;
    // 0x800601C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800601C8:
    // 0x800601C8: lw          $v1, -0x2454($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2454);
    // 0x800601CC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800601D0: blez        $v1, L_80060210
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800601D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80060210;
    }
    // 0x800601D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800601D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800601DC: lw          $a0, -0x245C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X245C);
    // 0x800601E0: nop

    // 0x800601E4: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
L_800601E8:
    // 0x800601E8: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x800601EC: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800601F0: nop

    // 0x800601F4: bne         $a1, $t3, L_80060200
    if (ctx->r5 != ctx->r11) {
        // 0x800601F8: nop
    
            goto L_80060200;
    }
    // 0x800601F8: nop

    // 0x800601FC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80060200:
    // 0x80060200: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80060204: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80060208: bne         $at, $zero, L_800601E8
    if (ctx->r1 != 0) {
        // 0x8006020C: sll         $t1, $v0, 3
        ctx->r9 = S32(ctx->r2 << 3);
            goto L_800601E8;
    }
    // 0x8006020C: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
L_80060210:
    // 0x80060210: beq         $a2, $t0, L_80060288
    if (ctx->r6 == ctx->r8) {
        // 0x80060214: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80060288;
    }
    // 0x80060214: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80060218: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8006021C: jal         0x80060298
    // 0x80060220: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    free_model_data(rdram, ctx);
        goto after_1;
    // 0x80060220: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80060224: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80060228: addiu       $v1, $v1, -0x244C
    ctx->r3 = ADD32(ctx->r3, -0X244C);
    // 0x8006022C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80060230: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80060234: lw          $t4, -0x2458($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2458);
    // 0x80060238: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8006023C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80060240: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80060244: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80060248: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006024C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x80060250: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80060254: addiu       $a1, $a1, -0x245C
    ctx->r5 = ADD32(ctx->r5, -0X245C);
    // 0x80060258: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8006025C: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x80060260: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80060264: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80060268: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006026C: addu        $t3, $t2, $t1
    ctx->r11 = ADD32(ctx->r10, ctx->r9);
    // 0x80060270: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x80060274: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80060278: nop

    // 0x8006027C: addu        $t4, $t5, $t1
    ctx->r12 = ADD32(ctx->r13, ctx->r9);
    // 0x80060280: jal         0x80071380
    // 0x80060284: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    mempool_free(rdram, ctx);
        goto after_2;
    // 0x80060284: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    after_2:
L_80060288:
    // 0x80060288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006028C:
    // 0x8006028C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80060290: jr          $ra
    // 0x80060294: nop

    return;
    // 0x80060294: nop

;}
RECOMP_FUNC void func_8004F7F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F834: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8004F838: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004F83C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8004F840: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8004F844: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x8004F848: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x8004F84C: sb          $zero, 0x53($sp)
    MEM_B(0X53, ctx->r29) = 0;
    // 0x8004F850: lb          $t6, 0x1D2($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X1D2);
    // 0x8004F854: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8004F858: beq         $t6, $zero, L_8004F87C
    if (ctx->r14 == 0) {
        // 0x8004F85C: or          $s1, $a2, $zero
        ctx->r17 = ctx->r6 | 0;
            goto L_8004F87C;
    }
    // 0x8004F85C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8004F860: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004F864: addiu       $a0, $a0, -0x2558
    ctx->r4 = ADD32(ctx->r4, -0X2558);
    // 0x8004F868: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8004F86C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004F870: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8004F874: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8004F878: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_8004F87C:
    // 0x8004F87C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8004F880: lw          $t9, -0x2524($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2524);
    // 0x8004F884: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004F888: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004F88C: beq         $t9, $at, L_8004F8A4
    if (ctx->r25 == ctx->r1) {
        // 0x8004F890: addiu       $a0, $a0, -0x2558
        ctx->r4 = ADD32(ctx->r4, -0X2558);
            goto L_8004F8A4;
    }
    // 0x8004F890: addiu       $a0, $a0, -0x2558
    ctx->r4 = ADD32(ctx->r4, -0X2558);
    // 0x8004F894: lb          $t0, 0x1D8($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1D8);
    // 0x8004F898: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004F89C: beq         $t0, $zero, L_8004F8C0
    if (ctx->r8 == 0) {
        // 0x8004F8A0: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8004F8C0;
    }
    // 0x8004F8A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8004F8A4:
    // 0x8004F8A4: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004F8A8: lw          $a3, 0xC4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC4);
    // 0x8004F8AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004F8B0: jal         0x80054150
    // 0x8004F8B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    update_onscreen_AI_racer(rdram, ctx);
        goto after_0;
    // 0x8004F8B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8004F8B8: b           L_80050784
    // 0x8004F8BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80050784;
    // 0x8004F8BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8004F8C0:
    // 0x8004F8C0: lb          $t1, 0x1D4($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1D4);
    // 0x8004F8C4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004F8C8: beq         $t1, $zero, L_8004F900
    if (ctx->r9 == 0) {
        // 0x8004F8CC: addiu       $v1, $v1, -0x2554
        ctx->r3 = ADD32(ctx->r3, -0X2554);
            goto L_8004F900;
    }
    // 0x8004F8CC: addiu       $v1, $v1, -0x2554
    ctx->r3 = ADD32(ctx->r3, -0X2554);
    // 0x8004F8D0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8004F8D4: addiu       $at, $zero, -0x2011
    ctx->r1 = ADD32(0, -0X2011);
    // 0x8004F8D8: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8004F8DC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8004F8E0: lb          $v0, 0x1D4($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D4);
    // 0x8004F8E4: nop

    // 0x8004F8E8: blez        $v0, L_8004F8FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004F8EC: addiu       $t5, $v0, 0x4
        ctx->r13 = ADD32(ctx->r2, 0X4);
            goto L_8004F8FC;
    }
    // 0x8004F8EC: addiu       $t5, $v0, 0x4
    ctx->r13 = ADD32(ctx->r2, 0X4);
    // 0x8004F8F0: addiu       $t4, $v0, -0x4
    ctx->r12 = ADD32(ctx->r2, -0X4);
    // 0x8004F8F4: b           L_8004F900
    // 0x8004F8F8: sb          $t4, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r12;
        goto L_8004F900;
    // 0x8004F8F8: sb          $t4, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r12;
L_8004F8FC:
    // 0x8004F8FC: sb          $t5, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r13;
L_8004F900:
    // 0x8004F900: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004F904: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8004F908: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8004F90C: beq         $t7, $zero, L_8004F944
    if (ctx->r15 == 0) {
        // 0x8004F910: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8004F944;
    }
    // 0x8004F910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004F914: lb          $v0, 0x1E6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E6);
    // 0x8004F918: nop

    // 0x8004F91C: beq         $v0, $zero, L_8004F944
    if (ctx->r2 == 0) {
        // 0x8004F920: nop
    
            goto L_8004F944;
    }
    // 0x8004F920: nop

    // 0x8004F924: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8004F928: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8004F92C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004F930: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004F934: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004F938: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8004F93C: b           L_8004F944
    // 0x8004F940: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
        goto L_8004F944;
    // 0x8004F940: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
L_8004F944:
    // 0x8004F944: lbu         $t8, 0x1FE($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004F948: nop

    // 0x8004F94C: bne         $t8, $zero, L_8004F968
    if (ctx->r24 != 0) {
        // 0x8004F950: lw          $a1, 0xC0($sp)
        ctx->r5 = MEM_W(ctx->r29, 0XC0);
            goto L_8004F968;
    }
    // 0x8004F950: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x8004F954: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x8004F958: nop

    // 0x8004F95C: ori         $t0, $t9, 0x400
    ctx->r8 = ctx->r25 | 0X400;
    // 0x8004F960: sw          $t0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r8;
    // 0x8004F964: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
L_8004F968:
    // 0x8004F968: jal         0x80050890
    // 0x8004F96C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    apply_vehicle_rotation_offset(rdram, ctx);
        goto after_1;
    // 0x8004F96C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_1:
    // 0x8004F970: lw          $a2, 0xC4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC4);
    // 0x8004F974: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004F978: jal         0x80053790
    // 0x8004F97C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80053750(rdram, ctx);
        goto after_2;
    // 0x8004F97C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8004F980: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004F984: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004F988: jal         0x80052204
    // 0x8004F98C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    handle_racer_head_turning(rdram, ctx);
        goto after_3;
    // 0x8004F98C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8004F990: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004F994: sh          $zero, -0x2530($at)
    MEM_H(-0X2530, ctx->r1) = 0;
    // 0x8004F998: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004F99C: sw          $zero, -0x252C($at)
    MEM_W(-0X252C, ctx->r1) = 0;
    // 0x8004F9A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004F9A4: sw          $zero, -0x2528($at)
    MEM_W(-0X2528, ctx->r1) = 0;
    // 0x8004F9A8: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004F9AC: nop

    // 0x8004F9B0: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x8004F9B4: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004F9B8: nop

    // 0x8004F9BC: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x8004F9C0: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004F9C4: nop

    // 0x8004F9C8: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x8004F9CC: lb          $v0, 0x1E6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E6);
    // 0x8004F9D0: nop

    // 0x8004F9D4: beq         $v0, $zero, L_8004FB78
    if (ctx->r2 == 0) {
        // 0x8004F9D8: nop
    
            goto L_8004FB78;
    }
    // 0x8004F9D8: nop

    // 0x8004F9DC: bgez        $v0, L_8004FA2C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004F9E0: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8004FA2C;
    }
    // 0x8004F9E0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8004F9E4: addiu       $a2, $a2, -0x254C
    ctx->r6 = ADD32(ctx->r6, -0X254C);
    // 0x8004F9E8: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8004F9EC: lw          $t3, 0xC0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC0);
    // 0x8004F9F0: slti        $at, $t1, 0x1A
    ctx->r1 = SIGNED(ctx->r9) < 0X1A ? 1 : 0;
    // 0x8004F9F4: bne         $at, $zero, L_8004FA2C
    if (ctx->r1 != 0) {
        // 0x8004F9F8: nop
    
            goto L_8004FA2C;
    }
    // 0x8004F9F8: nop

    // 0x8004F9FC: lh          $t2, 0x16E($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X16E);
    // 0x8004FA00: nop

    // 0x8004FA04: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8004FA08: sh          $t4, 0x16E($s0)
    MEM_H(0X16E, ctx->r16) = ctx->r12;
    // 0x8004FA0C: lh          $v0, 0x16E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X16E);
    // 0x8004FA10: nop

    // 0x8004FA14: bgez        $v0, L_8004FA88
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004FA18: nop
    
            goto L_8004FA88;
    }
    // 0x8004FA18: nop

    // 0x8004FA1C: sh          $zero, 0x16E($s0)
    MEM_H(0X16E, ctx->r16) = 0;
    // 0x8004FA20: lh          $v0, 0x16E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X16E);
    // 0x8004FA24: b           L_8004FA8C
    // 0x8004FA28: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
        goto L_8004FA8C;
    // 0x8004FA28: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
L_8004FA2C:
    // 0x8004FA2C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8004FA30: blez        $v0, L_8004FA7C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004FA34: addiu       $a2, $a2, -0x254C
        ctx->r6 = ADD32(ctx->r6, -0X254C);
            goto L_8004FA7C;
    }
    // 0x8004FA34: addiu       $a2, $a2, -0x254C
    ctx->r6 = ADD32(ctx->r6, -0X254C);
    // 0x8004FA38: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8004FA3C: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FA40: slti        $at, $t5, -0x19
    ctx->r1 = SIGNED(ctx->r13) < -0X19 ? 1 : 0;
    // 0x8004FA44: beq         $at, $zero, L_8004FA7C
    if (ctx->r1 == 0) {
        // 0x8004FA48: nop
    
            goto L_8004FA7C;
    }
    // 0x8004FA48: nop

    // 0x8004FA4C: lh          $t6, 0x16E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X16E);
    // 0x8004FA50: nop

    // 0x8004FA54: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8004FA58: sh          $t8, 0x16E($s0)
    MEM_H(0X16E, ctx->r16) = ctx->r24;
    // 0x8004FA5C: lh          $v0, 0x16E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X16E);
    // 0x8004FA60: nop

    // 0x8004FA64: blez        $v0, L_8004FA88
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004FA68: nop
    
            goto L_8004FA88;
    }
    // 0x8004FA68: nop

    // 0x8004FA6C: sh          $zero, 0x16E($s0)
    MEM_H(0X16E, ctx->r16) = 0;
    // 0x8004FA70: lh          $v0, 0x16E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X16E);
    // 0x8004FA74: b           L_8004FA8C
    // 0x8004FA78: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
        goto L_8004FA8C;
    // 0x8004FA78: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
L_8004FA7C:
    // 0x8004FA7C: sh          $zero, 0x16E($s0)
    MEM_H(0X16E, ctx->r16) = 0;
    // 0x8004FA80: lh          $v0, 0x16E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X16E);
    // 0x8004FA84: nop

L_8004FA88:
    // 0x8004FA88: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
L_8004FA8C:
    // 0x8004FA8C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004FA90: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004FA94: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8004FA98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004FA9C: swc1        $f16, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f16.u32l;
    // 0x8004FAA0: lwc1        $f18, 0xB8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8004FAA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FAA8: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8004FAAC: nop

    // 0x8004FAB0: bc1f        L_8004FAC0
    if (!c1cs) {
        // 0x8004FAB4: nop
    
            goto L_8004FAC0;
    }
    // 0x8004FAB4: nop

    // 0x8004FAB8: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x8004FABC: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
L_8004FAC0:
    // 0x8004FAC0: lwc1        $f10, 0xB8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8004FAC4: nop

    // 0x8004FAC8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8004FACC: nop

    // 0x8004FAD0: bc1f        L_8004FAF8
    if (!c1cs) {
        // 0x8004FAD4: nop
    
            goto L_8004FAF8;
    }
    // 0x8004FAD4: nop

    // 0x8004FAD8: jal         0x80057088
    // 0x8004FADC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    racer_play_sound(rdram, ctx);
        goto after_4;
    // 0x8004FADC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_4:
    // 0x8004FAE0: lb          $t9, 0x1E6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E6);
    // 0x8004FAE4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8004FAE8: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8004FAEC: addiu       $a2, $a2, -0x254C
    ctx->r6 = ADD32(ctx->r6, -0X254C);
    // 0x8004FAF0: sb          $t0, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r8;
    // 0x8004FAF4: sb          $zero, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = 0;
L_8004FAF8:
    // 0x8004FAF8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8004FAFC: nop

    // 0x8004FB00: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    // 0x8004FB04: bne         $at, $zero, L_8004FB18
    if (ctx->r1 != 0) {
        // 0x8004FB08: slti        $at, $v1, -0x32
        ctx->r1 = SIGNED(ctx->r3) < -0X32 ? 1 : 0;
            goto L_8004FB18;
    }
    // 0x8004FB08: slti        $at, $v1, -0x32
    ctx->r1 = SIGNED(ctx->r3) < -0X32 ? 1 : 0;
    // 0x8004FB0C: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x8004FB10: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8004FB14: slti        $at, $v1, -0x32
    ctx->r1 = SIGNED(ctx->r3) < -0X32 ? 1 : 0;
L_8004FB18:
    // 0x8004FB18: beq         $at, $zero, L_8004FB28
    if (ctx->r1 == 0) {
        // 0x8004FB1C: nop
    
            goto L_8004FB28;
    }
    // 0x8004FB1C: nop

    // 0x8004FB20: addiu       $v1, $zero, -0x32
    ctx->r3 = ADD32(0, -0X32);
    // 0x8004FB24: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
L_8004FB28:
    // 0x8004FB28: blez        $v1, L_8004FB40
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004FB2C: nop
    
            goto L_8004FB40;
    }
    // 0x8004FB2C: nop

    // 0x8004FB30: lb          $t3, 0x1E6($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E6);
    // 0x8004FB34: nop

    // 0x8004FB38: bgtz        $t3, L_8004FB54
    if (SIGNED(ctx->r11) > 0) {
        // 0x8004FB3C: sra         $t4, $v1, 2
        ctx->r12 = S32(SIGNED(ctx->r3) >> 2);
            goto L_8004FB54;
    }
    // 0x8004FB3C: sra         $t4, $v1, 2
    ctx->r12 = S32(SIGNED(ctx->r3) >> 2);
L_8004FB40:
    // 0x8004FB40: lb          $v0, 0x1E6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E6);
    // 0x8004FB44: bgez        $v1, L_8004FB64
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004FB48: sll         $t5, $v0, 4
        ctx->r13 = S32(ctx->r2 << 4);
            goto L_8004FB64;
    }
    // 0x8004FB48: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x8004FB4C: bgez        $v0, L_8004FB60
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004FB50: sra         $t4, $v1, 2
        ctx->r12 = S32(SIGNED(ctx->r3) >> 2);
            goto L_8004FB60;
    }
    // 0x8004FB50: sra         $t4, $v1, 2
    ctx->r12 = S32(SIGNED(ctx->r3) >> 2);
L_8004FB54:
    // 0x8004FB54: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8004FB58: lb          $v0, 0x1E6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E6);
    // 0x8004FB5C: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_8004FB60:
    // 0x8004FB60: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
L_8004FB64:
    // 0x8004FB64: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8004FB68: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8004FB6C: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x8004FB70: b           L_8004FB7C
    // 0x8004FB74: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
        goto L_8004FB7C;
    // 0x8004FB74: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
L_8004FB78:
    // 0x8004FB78: sh          $zero, 0x16E($s0)
    MEM_H(0X16E, ctx->r16) = 0;
L_8004FB7C:
    // 0x8004FB7C: lw          $a2, 0xC4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC4);
    // 0x8004FB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004FB84: jal         0x800579F0
    // 0x8004FB88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    handle_base_steering(rdram, ctx);
        goto after_5;
    // 0x8004FB88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8004FB8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FB90: jal         0x8005762C
    // 0x8004FB94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800575EC(rdram, ctx);
        goto after_6;
    // 0x8004FB94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x8004FB98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FB9C: jal         0x80053604
    // 0x8004FBA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800535C4(rdram, ctx);
        goto after_7;
    // 0x8004FBA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x8004FBA4: jal         0x800536A4
    // 0x8004FBA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    handle_car_velocity_control(rdram, ctx);
        goto after_8;
    // 0x8004FBA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8004FBAC: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FBB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FBB4: jal         0x80055F00
    // 0x8004FBB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    handle_racer_items(rdram, ctx);
        goto after_9;
    // 0x8004FBB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x8004FBBC: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FBC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FBC4: jal         0x80053EDC
    // 0x8004FBC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_attack_handler_car(rdram, ctx);
        goto after_10;
    // 0x8004FBC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x8004FBCC: lb          $t7, 0x1DB($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1DB);
    // 0x8004FBD0: nop

    // 0x8004FBD4: beq         $t7, $zero, L_8004FBF8
    if (ctx->r15 == 0) {
        // 0x8004FBD8: nop
    
            goto L_8004FBF8;
    }
    // 0x8004FBD8: nop

    // 0x8004FBDC: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FBE0: lw          $a3, 0xC4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC4);
    // 0x8004FBE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FBE8: jal         0x80052BA4
    // 0x8004FBEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_spinout_car(rdram, ctx);
        goto after_11;
    // 0x8004FBEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x8004FBF0: b           L_8004FC34
    // 0x8004FBF4: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
        goto L_8004FC34;
    // 0x8004FBF4: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
L_8004FBF8:
    // 0x8004FBF8: lb          $t8, 0x1E2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004FBFC: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FC00: blez        $t8, L_8004FC24
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8004FC04: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004FC24;
    }
    // 0x8004FC04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FC08: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FC0C: lw          $a3, 0xC4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC4);
    // 0x8004FC10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FC14: jal         0x80050A68
    // 0x8004FC18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80050A28(rdram, ctx);
        goto after_12;
    // 0x8004FC18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x8004FC1C: b           L_8004FC34
    // 0x8004FC20: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
        goto L_8004FC34;
    // 0x8004FC20: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
L_8004FC24:
    // 0x8004FC24: lw          $a3, 0xC4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC4);
    // 0x8004FC28: jal         0x80052DBC
    // 0x8004FC2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    update_car_velocity_offground(rdram, ctx);
        goto after_13;
    // 0x8004FC2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_13:
    // 0x8004FC30: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
L_8004FC34:
    // 0x8004FC34: nop

    // 0x8004FC38: beq         $v0, $zero, L_8004FC4C
    if (ctx->r2 == 0) {
        // 0x8004FC3C: nop
    
            goto L_8004FC4C;
    }
    // 0x8004FC3C: nop

    // 0x8004FC40: jal         0x8000488C
    // 0x8004FC44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_14;
    // 0x8004FC44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x8004FC48: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
L_8004FC4C:
    // 0x8004FC4C: lwc1        $f0, 0xC0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004FC50: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004FC54: nop

    // 0x8004FC58: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x8004FC5C: nop

    // 0x8004FC60: bc1t        L_8004FCC4
    if (c1cs) {
        // 0x8004FC64: nop
    
            goto L_8004FCC4;
    }
    // 0x8004FC64: nop

    // 0x8004FC68: lb          $t9, 0x1D7($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004FC6C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8004FC70: beq         $t9, $at, L_8004FCC4
    if (ctx->r25 == ctx->r1) {
        // 0x8004FC74: lui         $at, 0x4024
        ctx->r1 = S32(0X4024 << 16);
            goto L_8004FCC4;
    }
    // 0x8004FC74: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8004FC78: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004FC7C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004FC80: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8004FC84: sub.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d - ctx->f18.d;
    // 0x8004FC88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004FC8C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8004FC90: lwc1        $f17, 0x6B90($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6B90);
    // 0x8004FC94: lwc1        $f16, 0x6B94($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6B94);
    // 0x8004FC98: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8004FC9C: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8004FCA0: lwc1        $f18, 0xC4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8004FCA4: swc1        $f8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f8.u32l;
    // 0x8004FCA8: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8004FCAC: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004FCB0: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8004FCB4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8004FCB8: add.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f16.d + ctx->f8.d;
    // 0x8004FCBC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8004FCC0: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
L_8004FCC4:
    // 0x8004FCC4: jal         0x8006BFF0
    // 0x8004FCC8: nop

    level_header(rdram, ctx);
        goto after_15;
    // 0x8004FCC8: nop

    after_15:
    // 0x8004FCCC: lwc1        $f10, 0xC0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004FCD0: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8004FCD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004FCD8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8004FCDC: c.eq.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d == ctx->f16.d;
    // 0x8004FCE0: nop

    // 0x8004FCE4: bc1t        L_8004FCF8
    if (c1cs) {
        // 0x8004FCE8: nop
    
            goto L_8004FCF8;
    }
    // 0x8004FCE8: nop

    // 0x8004FCEC: lb          $t0, 0x2($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X2);
    // 0x8004FCF0: nop

    // 0x8004FCF4: bne         $t0, $zero, L_8004FD0C
    if (ctx->r8 != 0) {
        // 0x8004FCF8: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8004FD0C;
    }
L_8004FCF8:
    // 0x8004FCF8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004FCFC: lb          $t1, -0x24FF($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X24FF);
    // 0x8004FD00: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004FD04: bne         $t1, $at, L_8004FE44
    if (ctx->r9 != ctx->r1) {
        // 0x8004FD08: nop
    
            goto L_8004FE44;
    }
    // 0x8004FD08: nop

L_8004FD0C:
    // 0x8004FD0C: lbu         $t2, 0x1F0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1F0);
    // 0x8004FD10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FD14: beq         $t2, $zero, L_8004FD40
    if (ctx->r10 == 0) {
        // 0x8004FD18: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8004FD40;
    }
    // 0x8004FD18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004FD1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004FD20: lwc1        $f8, 0xA8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004FD24: lwc1        $f5, 0x6B98($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6B98);
    // 0x8004FD28: lwc1        $f4, 0x6B9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6B9C);
    // 0x8004FD2C: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8004FD30: sub.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f18.d - ctx->f4.d;
    // 0x8004FD34: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x8004FD38: b           L_8004FD60
    // 0x8004FD3C: swc1        $f6, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f6.u32l;
        goto L_8004FD60;
    // 0x8004FD3C: swc1        $f6, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f6.u32l;
L_8004FD40:
    // 0x8004FD40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004FD44: lwc1        $f16, 0xA8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004FD48: lwc1        $f19, 0x6BA0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6BA0);
    // 0x8004FD4C: lwc1        $f18, 0x6BA4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6BA4);
    // 0x8004FD50: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8004FD54: sub.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f8.d - ctx->f18.d;
    // 0x8004FD58: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8004FD5C: swc1        $f10, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f10.u32l;
L_8004FD60:
    // 0x8004FD60: addiu       $t3, $sp, 0xB4
    ctx->r11 = ADD32(ctx->r29, 0XB4);
    // 0x8004FD64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8004FD68: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    // 0x8004FD6C: jal         0x800590C0
    // 0x8004FD70: addiu       $a3, $sp, 0xB0
    ctx->r7 = ADD32(ctx->r29, 0XB0);
    set_position_goal_from_path(rdram, ctx);
        goto after_16;
    // 0x8004FD70: addiu       $a3, $sp, 0xB0
    ctx->r7 = ADD32(ctx->r29, 0XB0);
    after_16:
    // 0x8004FD74: lbu         $t4, 0x1F0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1F0);
    // 0x8004FD78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004FD7C: beq         $t4, $zero, L_8004FDA8
    if (ctx->r12 == 0) {
        // 0x8004FD80: nop
    
            goto L_8004FDA8;
    }
    // 0x8004FD80: nop

    // 0x8004FD84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004FD88: lwc1        $f6, 0xA8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004FD8C: lwc1        $f9, 0x6BA8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6BA8);
    // 0x8004FD90: lwc1        $f8, 0x6BAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6BAC);
    // 0x8004FD94: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8004FD98: add.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f16.d + ctx->f8.d;
    // 0x8004FD9C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8004FDA0: b           L_8004FDC4
    // 0x8004FDA4: swc1        $f4, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f4.u32l;
        goto L_8004FDC4;
    // 0x8004FDA4: swc1        $f4, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f4.u32l;
L_8004FDA8:
    // 0x8004FDA8: lwc1        $f10, 0xA8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004FDAC: lwc1        $f17, 0x6BB0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6BB0);
    // 0x8004FDB0: lwc1        $f16, 0x6BB4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6BB4);
    // 0x8004FDB4: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8004FDB8: add.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f6.d + ctx->f16.d;
    // 0x8004FDBC: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x8004FDC0: swc1        $f18, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f18.u32l;
L_8004FDC4:
    // 0x8004FDC4: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8004FDC8: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004FDCC: lwc1        $f16, 0xB4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8004FDD0: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8004FDD4: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    // 0x8004FDD8: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004FDDC: mul.s       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004FDE0: sub.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8004FDE4: swc1        $f18, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f18.u32l;
    // 0x8004FDE8: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8004FDEC: jal         0x800CA030
    // 0x8004FDF0: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_17;
    // 0x8004FDF0: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_17:
    // 0x8004FDF4: lwc1        $f16, 0xB8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8004FDF8: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8004FDFC: div.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004FE00: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004FE04: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004FE08: swc1        $f0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f0.u32l;
    // 0x8004FE0C: lui         $at, 0x4118
    ctx->r1 = S32(0X4118 << 16);
    // 0x8004FE10: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8004FE14: div.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004FE18: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004FE1C: swc1        $f8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f8.u32l;
    // 0x8004FE20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004FE24: swc1        $f18, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f18.u32l;
    // 0x8004FE28: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x8004FE2C: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8004FE30: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x8004FE34: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8004FE38: swc1        $f16, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f16.u32l;
    // 0x8004FE3C: b           L_8004FE5C
    // 0x8004FE40: sb          $t5, 0x1F0($s0)
    MEM_B(0X1F0, ctx->r16) = ctx->r13;
        goto L_8004FE5C;
    // 0x8004FE40: sb          $t5, 0x1F0($s0)
    MEM_B(0X1F0, ctx->r16) = ctx->r13;
L_8004FE44:
    // 0x8004FE44: lb          $t6, 0x1E2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004FE48: nop

    // 0x8004FE4C: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8004FE50: bne         $at, $zero, L_8004FE5C
    if (ctx->r1 != 0) {
        // 0x8004FE54: nop
    
            goto L_8004FE5C;
    }
    // 0x8004FE54: nop

    // 0x8004FE58: sb          $zero, 0x1F0($s0)
    MEM_B(0X1F0, ctx->r16) = 0;
L_8004FE5C:
    // 0x8004FE5C: lw          $t7, 0x148($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X148);
    // 0x8004FE60: nop

    // 0x8004FE64: bne         $t7, $zero, L_8004FE7C
    if (ctx->r15 != 0) {
        // 0x8004FE68: nop
    
            goto L_8004FE7C;
    }
    // 0x8004FE68: nop

    // 0x8004FE6C: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FE70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FE74: jal         0x8005254C
    // 0x8004FE78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8005250C(rdram, ctx);
        goto after_18;
    // 0x8004FE78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_18:
L_8004FE7C:
    // 0x8004FE7C: lh          $a1, 0x1A2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1A2);
    // 0x8004FE80: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004FE84: lw          $t8, -0x252C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X252C);
    // 0x8004FE88: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x8004FE8C: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004FE90: subu        $v1, $t8, $t9
    ctx->r3 = SUB32(ctx->r24, ctx->r25);
    // 0x8004FE94: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004FE98: lw          $t1, 0xC0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FE9C: bne         $at, $zero, L_8004FEAC
    if (ctx->r1 != 0) {
        // 0x8004FEA0: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004FEAC;
    }
    // 0x8004FEA0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004FEA4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004FEA8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004FEAC:
    // 0x8004FEAC: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8004FEB0: beq         $at, $zero, L_8004FEBC
    if (ctx->r1 == 0) {
        // 0x8004FEB4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004FEBC;
    }
    // 0x8004FEB4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004FEB8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004FEBC:
    // 0x8004FEBC: sra         $t0, $v1, 2
    ctx->r8 = S32(SIGNED(ctx->r3) >> 2);
    // 0x8004FEC0: slti        $at, $t0, 0x2EF
    ctx->r1 = SIGNED(ctx->r8) < 0X2EF ? 1 : 0;
    // 0x8004FEC4: bne         $at, $zero, L_8004FED0
    if (ctx->r1 != 0) {
        // 0x8004FEC8: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_8004FED0;
    }
    // 0x8004FEC8: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8004FECC: addiu       $v1, $zero, 0x2EE
    ctx->r3 = ADD32(0, 0X2EE);
L_8004FED0:
    // 0x8004FED0: slti        $at, $v1, -0x2EE
    ctx->r1 = SIGNED(ctx->r3) < -0X2EE ? 1 : 0;
    // 0x8004FED4: beq         $at, $zero, L_8004FEE0
    if (ctx->r1 == 0) {
        // 0x8004FED8: nop
    
            goto L_8004FEE0;
    }
    // 0x8004FED8: nop

    // 0x8004FEDC: addiu       $v1, $zero, -0x2EE
    ctx->r3 = ADD32(0, -0X2EE);
L_8004FEE0:
    // 0x8004FEE0: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004FEE4: lh          $t4, 0x1A0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004FEE8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004FEEC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004FEF0: mflo        $t2
    ctx->r10 = lo;
    // 0x8004FEF4: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8004FEF8: sh          $t3, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r11;
    // 0x8004FEFC: lh          $t5, 0x1A2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A2);
    // 0x8004FF00: nop

    // 0x8004FF04: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8004FF08: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x8004FF0C: lh          $v0, 0x1A6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A6);
    // 0x8004FF10: lw          $t7, -0x2528($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2528);
    // 0x8004FF14: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FF18: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x8004FF1C: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004FF20: lh          $t3, 0x1A4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004FF24: mflo        $t0
    ctx->r8 = lo;
    // 0x8004FF28: sra         $t1, $t0, 4
    ctx->r9 = S32(SIGNED(ctx->r8) >> 4);
    // 0x8004FF2C: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8004FF30: sh          $t2, 0x1A6($s0)
    MEM_H(0X1A6, ctx->r16) = ctx->r10;
    // 0x8004FF34: lh          $t4, 0x1A6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A6);
    // 0x8004FF38: nop

    // 0x8004FF3C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8004FF40: sh          $t5, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r13;
    // 0x8004FF44: lhu         $a0, -0x2530($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2530);
    // 0x8004FF48: nop

    // 0x8004FF4C: beq         $a0, $zero, L_8004FFE0
    if (ctx->r4 == 0) {
        // 0x8004FF50: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8004FFE0;
    }
    // 0x8004FF50: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004FF54: lw          $t6, -0x2524($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2524);
    // 0x8004FF58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004FF5C: beq         $t6, $at, L_8004FF9C
    if (ctx->r14 == ctx->r1) {
        // 0x8004FF60: addiu       $at, $zero, 0x10C
        ctx->r1 = ADD32(0, 0X10C);
            goto L_8004FF9C;
    }
    // 0x8004FF60: addiu       $at, $zero, 0x10C
    ctx->r1 = ADD32(0, 0X10C);
    // 0x8004FF64: beq         $a0, $at, L_8004FF9C
    if (ctx->r4 == ctx->r1) {
        // 0x8004FF68: addiu       $t7, $s0, 0x21C
        ctx->r15 = ADD32(ctx->r16, 0X21C);
            goto L_8004FF9C;
    }
    // 0x8004FF68: addiu       $t7, $s0, 0x21C
    ctx->r15 = ADD32(ctx->r16, 0X21C);
    // 0x8004FF6C: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004FF70: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004FF74: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004FF78: jal         0x80001EA8
    // 0x8004FF7C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    sound_play_spatial(rdram, ctx);
        goto after_19;
    // 0x8004FF7C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_19:
    // 0x8004FF80: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004FF84: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8004FF88: lbu         $a2, -0x252D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X252D);
    // 0x8004FF8C: lhu         $a0, -0x2530($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2530);
    // 0x8004FF90: lw          $a1, 0x21C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X21C);
    // 0x8004FF94: jal         0x80001FB8
    // 0x8004FF98: nop

    sound_volume_set_relative(rdram, ctx);
        goto after_20;
    // 0x8004FF98: nop

    after_20:
L_8004FF9C:
    // 0x8004FF9C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004FFA0: lhu         $t8, -0x252E($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X252E);
    // 0x8004FFA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004FFA8: addiu       $t9, $t8, -0x28
    ctx->r25 = ADD32(ctx->r24, -0X28);
    // 0x8004FFAC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8004FFB0: lwc1        $f11, 0x6BB8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6BB8);
    // 0x8004FFB4: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8004FFB8: lwc1        $f10, 0x6BBC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6BBC);
    // 0x8004FFBC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004FFC0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8004FFC4: mul.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x8004FFC8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004FFCC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004FFD0: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004FFD4: sub.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d - ctx->f16.d;
    // 0x8004FFD8: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x8004FFDC: swc1        $f8, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f8.u32l;
L_8004FFE0:
    // 0x8004FFE0: lbu         $t0, 0x1F0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1F0);
    // 0x8004FFE4: nop

    // 0x8004FFE8: bne         $t0, $zero, L_80050060
    if (ctx->r8 != 0) {
        // 0x8004FFEC: nop
    
            goto L_80050060;
    }
    // 0x8004FFEC: nop

    // 0x8004FFF0: lh          $t1, 0x1A0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004FFF4: lw          $t2, 0x10C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X10C);
    // 0x8004FFF8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004FFFC: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x80050000: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80050004: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80050008: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005000C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80050010: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x80050014: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x80050018: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x8005001C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80050020: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x80050024: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x80050028: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x8005002C: jal         0x800700B4
    // 0x80050030: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_21;
    // 0x80050030: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    after_21:
    // 0x80050034: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x80050038: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    // 0x8005003C: addiu       $t4, $s1, 0x1C
    ctx->r12 = ADD32(ctx->r17, 0X1C);
    // 0x80050040: addiu       $t5, $sp, 0xBC
    ctx->r13 = ADD32(ctx->r29, 0XBC);
    // 0x80050044: addiu       $t6, $s1, 0x24
    ctx->r14 = ADD32(ctx->r17, 0X24);
    // 0x80050048: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8005004C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80050050: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80050054: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80050058: jal         0x8006F88C
    // 0x8005005C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    mtxf_transform_point(rdram, ctx);
        goto after_22;
    // 0x8005005C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_22:
L_80050060:
    // 0x80050060: lb          $t7, 0x175($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X175);
    // 0x80050064: nop

    // 0x80050068: beq         $t7, $zero, L_80050088
    if (ctx->r15 == 0) {
        // 0x8005006C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80050088;
    }
    // 0x8005006C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050070: lwc1        $f10, -0x2508($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2508);
    // 0x80050074: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050078: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
    // 0x8005007C: lwc1        $f6, -0x2504($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2504);
    // 0x80050080: nop

    // 0x80050084: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
L_80050088:
    // 0x80050088: lw          $t8, 0x148($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X148);
    // 0x8005008C: lw          $a2, 0xC4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC4);
    // 0x80050090: bne         $t8, $zero, L_8005025C
    if (ctx->r24 != 0) {
        // 0x80050094: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8005025C;
    }
    // 0x80050094: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80050098: lwc1        $f16, 0x1C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005009C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800500A0: swc1        $f16, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f16.u32l;
    // 0x800500A4: lwc1        $f18, 0x24($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800500A8: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800500AC: swc1        $f18, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f18.u32l;
    // 0x800500B0: lb          $t9, 0x1D2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D2);
    // 0x800500B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800500B8: beq         $t9, $zero, L_800500E0
    if (ctx->r25 == 0) {
        // 0x800500BC: nop
    
            goto L_800500E0;
    }
    // 0x800500BC: nop

    // 0x800500C0: lwc1        $f4, 0x11C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x800500C4: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800500C8: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800500CC: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x800500D0: lwc1        $f16, 0x120($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X120);
    // 0x800500D4: nop

    // 0x800500D8: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800500DC: swc1        $f18, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f18.u32l;
L_800500E0:
    // 0x800500E0: lb          $t0, -0x24FC($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X24FC);
    // 0x800500E4: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800500E8: beq         $t0, $zero, L_800501DC
    if (ctx->r8 == 0) {
        // 0x800500EC: nop
    
            goto L_800501DC;
    }
    // 0x800500EC: nop

    // 0x800500F0: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800500F4: lwc1        $f3, 0x6BC0($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X6BC0);
    // 0x800500F8: lwc1        $f2, 0x6BC4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6BC4);
    // 0x800500FC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80050100: mul.d       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x80050104: lwc1        $f16, 0xB4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80050108: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8005010C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80050110: mul.d       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x80050114: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80050118: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005011C: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    // 0x80050120: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80050124: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80050128: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8005012C: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    // 0x80050130: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050134: nop

    // 0x80050138: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8005013C: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x80050140: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80050144: bc1t        L_80050168
    if (c1cs) {
        // 0x80050148: nop
    
            goto L_80050168;
    }
    // 0x80050148: nop

    // 0x8005014C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80050150: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80050154: nop

    // 0x80050158: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x8005015C: nop

    // 0x80050160: bc1f        L_80050184
    if (!c1cs) {
        // 0x80050164: nop
    
            goto L_80050184;
    }
    // 0x80050164: nop

L_80050168:
    // 0x80050168: mul.d       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8005016C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80050170: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80050174: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80050178: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8005017C: b           L_80050190
    // 0x80050180: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
        goto L_80050190;
    // 0x80050180: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_80050184:
    // 0x80050184: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80050188: nop

    // 0x8005018C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_80050190:
    // 0x80050190: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80050194: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80050198: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005019C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800501A0: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x800501A4: nop

    // 0x800501A8: bc1t        L_800501C0
    if (c1cs) {
        // 0x800501AC: nop
    
            goto L_800501C0;
    }
    // 0x800501AC: nop

    // 0x800501B0: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x800501B4: nop

    // 0x800501B8: bc1f        L_800501D0
    if (!c1cs) {
        // 0x800501BC: nop
    
            goto L_800501D0;
    }
    // 0x800501BC: nop

L_800501C0:
    // 0x800501C0: mul.d       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x800501C4: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x800501C8: b           L_800501FC
    // 0x800501CC: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
        goto L_800501FC;
    // 0x800501CC: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
L_800501D0:
    // 0x800501D0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800501D4: b           L_800501FC
    // 0x800501D8: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
        goto L_800501FC;
    // 0x800501D8: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
L_800501DC:
    // 0x800501DC: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x800501E0: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800501E4: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800501E8: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x800501EC: lwc1        $f16, 0x88($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X88);
    // 0x800501F0: nop

    // 0x800501F4: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800501F8: swc1        $f18, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f18.u32l;
L_800501FC:
    // 0x800501FC: lwc1        $f0, 0xC4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80050200: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80050204: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80050208: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8005020C: lwc1        $f16, 0xB4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80050210: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80050214: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80050218: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005021C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80050220: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80050224: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80050228: jal         0x80011570
    // 0x8005022C: nop

    move_object(rdram, ctx);
        goto after_23;
    // 0x8005022C: nop

    after_23:
    // 0x80050230: beq         $v0, $zero, L_8005024C
    if (ctx->r2 == 0) {
        // 0x80050234: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8005024C;
    }
    // 0x80050234: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80050238: lw          $t1, -0x2524($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2524);
    // 0x8005023C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80050240: beq         $t1, $at, L_8005024C
    if (ctx->r9 == ctx->r1) {
        // 0x80050244: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8005024C;
    }
    // 0x80050244: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80050248: sb          $t2, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r10;
L_8005024C:
    // 0x8005024C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80050250: lw          $v0, -0x2524($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2524);
    // 0x80050254: b           L_80050274
    // 0x80050258: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
        goto L_80050274;
    // 0x80050258: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_8005025C:
    // 0x8005025C: jal         0x80050794
    // 0x80050260: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_approach_object(rdram, ctx);
        goto after_24;
    // 0x80050260: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_24:
    // 0x80050264: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80050268: lw          $v0, -0x2524($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2524);
    // 0x8005026C: nop

    // 0x80050270: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80050274:
    // 0x80050274: bne         $v0, $at, L_80050294
    if (ctx->r2 != ctx->r1) {
        // 0x80050278: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80050294;
    }
    // 0x80050278: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005027C: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x80050280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80050284: jal         0x80055AC4
    // 0x80050288: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    onscreen_ai_racer_physics(rdram, ctx);
        goto after_25;
    // 0x80050288: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_25:
    // 0x8005028C: b           L_800502A4
    // 0x80050290: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_800502A4;
    // 0x80050290: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80050294:
    // 0x80050294: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x80050298: jal         0x80055010
    // 0x8005029C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80054FD0(rdram, ctx);
        goto after_26;
    // 0x8005029C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_26:
    // 0x800502A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800502A4:
    // 0x800502A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800502A8: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800502AC: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800502B0: div.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800502B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800502B8: lwc1        $f8, -0x2538($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2538);
    // 0x800502BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800502C0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800502C4: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x800502C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800502CC: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x800502D0: swc1        $f10, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
    // 0x800502D4: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800502D8: nop

    // 0x800502DC: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800502E0: lwc1        $f16, 0x84($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X84);
    // 0x800502E4: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800502E8: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800502EC: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800502F0: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800502F4: swc1        $f18, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f18.u32l;
    // 0x800502F8: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800502FC: lwc1        $f18, 0x14($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80050300: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80050304: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80050308: swc1        $f16, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f16.u32l;
    // 0x8005030C: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80050310: lwc1        $f6, -0x2534($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2534);
    // 0x80050314: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80050318: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8005031C: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80050320: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80050324: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80050328: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005032C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80050330: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80050334: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    // 0x80050338: lw          $t4, 0x10C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10C);
    // 0x8005033C: lh          $t3, 0x1A0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X1A0);
    // 0x80050340: nop

    // 0x80050344: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80050348: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x8005034C: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80050350: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x80050354: nop

    // 0x80050358: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8005035C: sh          $t8, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r24;
    // 0x80050360: lh          $t9, 0x4($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4);
    // 0x80050364: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x80050368: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8005036C: sh          $t0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r8;
    // 0x80050370: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x80050374: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x80050378: jal         0x800700B4
    // 0x8005037C: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_27;
    // 0x8005037C: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    after_27:
    // 0x80050380: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    // 0x80050384: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x80050388: addiu       $t1, $sp, 0xAC
    ctx->r9 = ADD32(ctx->r29, 0XAC);
    // 0x8005038C: addiu       $t2, $sp, 0xBC
    ctx->r10 = ADD32(ctx->r29, 0XBC);
    // 0x80050390: addiu       $t3, $sp, 0xB0
    ctx->r11 = ADD32(ctx->r29, 0XB0);
    // 0x80050394: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80050398: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8005039C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800503A0: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x800503A4: jal         0x8006F88C
    // 0x800503A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    mtxf_transform_point(rdram, ctx);
        goto after_28;
    // 0x800503A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_28:
    // 0x800503AC: lb          $v0, 0x1D2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D2);
    // 0x800503B0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800503B4: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800503B8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800503BC: beq         $v0, $zero, L_800503EC
    if (ctx->r2 == 0) {
        // 0x800503C0: lui         $at, 0xBFE0
        ctx->r1 = S32(0XBFE0 << 16);
            goto L_800503EC;
    }
    // 0x800503C0: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x800503C4: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x800503C8: nop

    // 0x800503CC: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x800503D0: sb          $t5, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = ctx->r13;
    // 0x800503D4: lb          $t6, 0x1D2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D2);
    // 0x800503D8: nop

    // 0x800503DC: bgez        $t6, L_800504F8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800503E0: nop
    
            goto L_800504F8;
    }
    // 0x800503E0: nop

    // 0x800503E4: b           L_800504F8
    // 0x800503E8: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
        goto L_800504F8;
    // 0x800503E8: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
L_800503EC:
    // 0x800503EC: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800503F0: lwc1        $f16, 0xB0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800503F4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800503F8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800503FC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80050400: swc1        $f18, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f18.u32l;
    // 0x80050404: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80050408: nop

    // 0x8005040C: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80050410: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x80050414: nop

    // 0x80050418: bc1f        L_80050444
    if (!c1cs) {
        // 0x8005041C: nop
    
            goto L_80050444;
    }
    // 0x8005041C: nop

    // 0x80050420: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050424: sub.d       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f0.d - ctx->f12.d;
    // 0x80050428: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005042C: sub.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d - ctx->f10.d;
    // 0x80050430: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80050434: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x80050438: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8005043C: nop

    // 0x80050440: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
L_80050444:
    // 0x80050444: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80050448: nop

    // 0x8005044C: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80050450: nop

    // 0x80050454: bc1f        L_80050474
    if (!c1cs) {
        // 0x80050458: nop
    
            goto L_80050474;
    }
    // 0x80050458: nop

    // 0x8005045C: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050460: add.d       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = ctx->f0.d + ctx->f12.d;
    // 0x80050464: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80050468: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x8005046C: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x80050470: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_80050474:
    // 0x80050474: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80050478: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8005047C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80050480: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80050484: swc1        $f10, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
    // 0x80050488: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8005048C: nop

    // 0x80050490: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80050494: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x80050498: nop

    // 0x8005049C: bc1f        L_800504C8
    if (!c1cs) {
        // 0x800504A0: nop
    
            goto L_800504C8;
    }
    // 0x800504A0: nop

    // 0x800504A4: lwc1        $f18, 0x30($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800504A8: sub.d       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f0.d - ctx->f12.d;
    // 0x800504AC: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800504B0: sub.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d - ctx->f4.d;
    // 0x800504B4: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800504B8: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x800504BC: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800504C0: nop

    // 0x800504C4: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
L_800504C8:
    // 0x800504C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800504CC: nop

    // 0x800504D0: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    // 0x800504D4: nop

    // 0x800504D8: bc1f        L_800504F8
    if (!c1cs) {
        // 0x800504DC: nop
    
            goto L_800504F8;
    }
    // 0x800504DC: nop

    // 0x800504E0: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800504E4: add.d       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f0.d + ctx->f12.d;
    // 0x800504E8: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x800504EC: sub.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d - ctx->f6.d;
    // 0x800504F0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800504F4: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
L_800504F8:
    // 0x800504F8: lb          $t7, 0x1D3($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D3);
    // 0x800504FC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80050500: bne         $t7, $zero, L_80050610
    if (ctx->r15 != 0) {
        // 0x80050504: nop
    
            goto L_80050610;
    }
    // 0x80050504: nop

    // 0x80050508: lw          $t8, -0x2EF8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2EF8);
    // 0x8005050C: nop

    // 0x80050510: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80050514: beq         $at, $zero, L_80050610
    if (ctx->r1 == 0) {
        // 0x80050518: nop
    
            goto L_80050610;
    }
    // 0x80050518: nop

    // 0x8005051C: jal         0x8001E2D0
    // 0x80050520: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_29;
    // 0x80050520: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_29:
    // 0x80050524: lb          $v1, 0x203($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X203);
    // 0x80050528: lb          $t9, 0x2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X2);
    // 0x8005052C: andi        $t1, $v1, 0x4
    ctx->r9 = ctx->r3 & 0X4;
    // 0x80050530: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80050534: sra         $t2, $t1, 2
    ctx->r10 = S32(SIGNED(ctx->r9) >> 2);
    // 0x80050538: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8005053C: addiu       $v1, $t2, 0x10
    ctx->r3 = ADD32(ctx->r10, 0X10);
    // 0x80050540: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80050544: slti        $at, $v1, 0x11
    ctx->r1 = SIGNED(ctx->r3) < 0X11 ? 1 : 0;
    // 0x80050548: sll         $t0, $t9, 7
    ctx->r8 = S32(ctx->r25 << 7);
    // 0x8005054C: bne         $at, $zero, L_80050598
    if (ctx->r1 != 0) {
        // 0x80050550: addu        $a0, $t0, $v0
        ctx->r4 = ADD32(ctx->r8, ctx->r2);
            goto L_80050598;
    }
    // 0x80050550: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    // 0x80050554: lbu         $t3, 0x70($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X70);
    // 0x80050558: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005055C: bgtz        $t3, L_80050584
    if (SIGNED(ctx->r11) > 0) {
        // 0x80050560: nop
    
            goto L_80050584;
    }
    // 0x80050560: nop

    // 0x80050564: lwc1        $f8, 0x74($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X74);
    // 0x80050568: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8005056C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80050570: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80050574: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80050578: nop

    // 0x8005057C: bc1f        L_80050610
    if (!c1cs) {
        // 0x80050580: nop
    
            goto L_80050610;
    }
    // 0x80050580: nop

L_80050584:
    // 0x80050584: lw          $t4, 0x74($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X74);
    // 0x80050588: sllv        $t6, $t5, $v1
    ctx->r14 = S32(ctx->r13 << (ctx->r3 & 31));
    // 0x8005058C: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80050590: b           L_80050610
    // 0x80050594: sw          $t7, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r15;
        goto L_80050610;
    // 0x80050594: sw          $t7, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r15;
L_80050598:
    // 0x80050598: lbu         $v0, 0x70($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X70);
    // 0x8005059C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800505A0: bne         $v0, $at, L_800505DC
    if (ctx->r2 != ctx->r1) {
        // 0x800505A4: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_800505DC;
    }
    // 0x800505A4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800505A8: lwc1        $f6, 0x74($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X74);
    // 0x800505AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800505B0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800505B4: c.lt.d      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.d < ctx->f12.d;
    // 0x800505B8: nop

    // 0x800505BC: bc1f        L_800505DC
    if (!c1cs) {
        // 0x800505C0: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_800505DC;
    }
    // 0x800505C0: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800505C4: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x800505C8: sllv        $t0, $t9, $v1
    ctx->r8 = S32(ctx->r25 << (ctx->r3 & 31));
    // 0x800505CC: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800505D0: b           L_80050610
    // 0x800505D4: sw          $t1, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r9;
        goto L_80050610;
    // 0x800505D4: sw          $t1, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r9;
    // 0x800505D8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_800505DC:
    // 0x800505DC: beq         $at, $zero, L_80050610
    if (ctx->r1 == 0) {
        // 0x800505E0: nop
    
            goto L_80050610;
    }
    // 0x800505E0: nop

    // 0x800505E4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800505E8: lwc1        $f8, 0x74($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X74);
    // 0x800505EC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800505F0: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800505F4: nop

    // 0x800505F8: bc1f        L_80050610
    if (!c1cs) {
        // 0x800505FC: nop
    
            goto L_80050610;
    }
    // 0x800505FC: nop

    // 0x80050600: lw          $t2, 0x74($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X74);
    // 0x80050604: sllv        $t5, $t3, $v1
    ctx->r13 = S32(ctx->r11 << (ctx->r3 & 31));
    // 0x80050608: or          $t4, $t2, $t5
    ctx->r12 = ctx->r10 | ctx->r13;
    // 0x8005060C: sw          $t4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r12;
L_80050610:
    // 0x80050610: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80050614: lw          $t6, -0x2524($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2524);
    // 0x80050618: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005061C: beq         $t6, $at, L_800506E0
    if (ctx->r14 == ctx->r1) {
        // 0x80050620: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800506E0;
    }
    // 0x80050620: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80050624: lw          $t7, -0x2EF8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2EF8);
    // 0x80050628: nop

    // 0x8005062C: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80050630: beq         $at, $zero, L_800506E0
    if (ctx->r1 == 0) {
        // 0x80050634: lui         $at, 0x4160
        ctx->r1 = S32(0X4160 << 16);
            goto L_800506E0;
    }
    // 0x80050634: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80050638: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005063C: lwc1        $f0, 0xC0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80050640: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80050644: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80050648: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8005064C: bc1f        L_80050678
    if (!c1cs) {
        // 0x80050650: nop
    
            goto L_80050678;
    }
    // 0x80050650: nop

    // 0x80050654: jal         0x8006FB8C
    // 0x80050658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rand_range(rdram, ctx);
        goto after_30;
    // 0x80050658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x8005065C: beq         $v0, $zero, L_800506E0
    if (ctx->r2 == 0) {
        // 0x80050660: nop
    
            goto L_800506E0;
    }
    // 0x80050660: nop

    // 0x80050664: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x80050668: lui         $at, 0x30
    ctx->r1 = S32(0X30 << 16);
    // 0x8005066C: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80050670: b           L_800506E0
    // 0x80050674: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
        goto L_800506E0;
    // 0x80050674: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
L_80050678:
    // 0x80050678: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005067C: lui         $at, 0xC008
    ctx->r1 = S32(0XC008 << 16);
    // 0x80050680: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80050684: nop

    // 0x80050688: bc1f        L_800506E0
    if (!c1cs) {
        // 0x8005068C: nop
    
            goto L_800506E0;
    }
    // 0x8005068C: nop

    // 0x80050690: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050694: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80050698: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005069C: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x800506A0: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x800506A4: nop

    // 0x800506A8: bc1f        L_800506E0
    if (!c1cs) {
        // 0x800506AC: nop
    
            goto L_800506E0;
    }
    // 0x800506AC: nop

    // 0x800506B0: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x800506B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800506B8: bc1f        L_800506E0
    if (!c1cs) {
        // 0x800506BC: nop
    
            goto L_800506E0;
    }
    // 0x800506BC: nop

    // 0x800506C0: jal         0x8006FB8C
    // 0x800506C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rand_range(rdram, ctx);
        goto after_31;
    // 0x800506C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x800506C8: beq         $v0, $zero, L_800506E0
    if (ctx->r2 == 0) {
        // 0x800506CC: nop
    
            goto L_800506E0;
    }
    // 0x800506CC: nop

    // 0x800506D0: lw          $t0, 0x74($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X74);
    // 0x800506D4: lui         $at, 0xC
    ctx->r1 = S32(0XC << 16);
    // 0x800506D8: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x800506DC: sw          $t1, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r9;
L_800506E0:
    // 0x800506E0: lb          $t3, 0x1D6($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D6);
    // 0x800506E4: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x800506E8: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x800506EC: beq         $at, $zero, L_80050700
    if (ctx->r1 == 0) {
        // 0x800506F0: lw          $a3, 0xC4($sp)
        ctx->r7 = MEM_W(ctx->r29, 0XC4);
            goto L_80050700;
    }
    // 0x800506F0: lw          $a3, 0xC4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC4);
    // 0x800506F4: jal         0x800AFC74
    // 0x800506F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    update_vehicle_particles(rdram, ctx);
        goto after_32;
    // 0x800506F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_32:
    // 0x800506FC: lw          $a3, 0xC4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC4);
L_80050700:
    // 0x80050700: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80050704: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80050708: jal         0x800580F4
    // 0x8005070C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    second_racer_camera_update(rdram, ctx);
        goto after_33;
    // 0x8005070C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_33:
    // 0x80050710: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80050714: lw          $t2, -0x2EF8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2EF8);
    // 0x80050718: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005071C: bne         $t2, $at, L_8005076C
    if (ctx->r10 != ctx->r1) {
        // 0x80050720: lb          $t4, 0x53($sp)
        ctx->r12 = MEM_B(ctx->r29, 0X53);
            goto L_8005076C;
    }
    // 0x80050720: lb          $t4, 0x53($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X53);
    // 0x80050724: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050728: lui         $at, 0xC008
    ctx->r1 = S32(0XC008 << 16);
    // 0x8005072C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80050730: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80050734: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80050738: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8005073C: nop

    // 0x80050740: bc1f        L_8005076C
    if (!c1cs) {
        // 0x80050744: lb          $t4, 0x53($sp)
        ctx->r12 = MEM_B(ctx->r29, 0X53);
            goto L_8005076C;
    }
    // 0x80050744: lb          $t4, 0x53($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X53);
    // 0x80050748: jal         0x8006ECD0
    // 0x8005074C: nop

    get_settings(rdram, ctx);
        goto after_34;
    // 0x8005074C: nop

    after_34:
    // 0x80050750: lbu         $t5, 0x49($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X49);
    // 0x80050754: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80050758: beq         $t5, $at, L_8005076C
    if (ctx->r13 == ctx->r1) {
        // 0x8005075C: lb          $t4, 0x53($sp)
        ctx->r12 = MEM_B(ctx->r29, 0X53);
            goto L_8005076C;
    }
    // 0x8005075C: lb          $t4, 0x53($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X53);
    // 0x80050760: jal         0x80028FE0
    // 0x80050764: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_anti_aliasing(rdram, ctx);
        goto after_35;
    // 0x80050764: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_35:
    // 0x80050768: lb          $t4, 0x53($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X53);
L_8005076C:
    // 0x8005076C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80050770: beq         $t4, $zero, L_80050784
    if (ctx->r12 == 0) {
        // 0x80050774: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80050784;
    }
    // 0x80050774: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80050778: jal         0x80023104
    // 0x8005077C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800230D0(rdram, ctx);
        goto after_36;
    // 0x8005077C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_36:
    // 0x80050780: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80050784:
    // 0x80050784: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80050788: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005078C: jr          $ra
    // 0x80050790: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80050790: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_8002F440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F480: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8002F484: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8002F488: addiu       $t4, $t4, -0x29BC
    ctx->r12 = ADD32(ctx->r12, -0X29BC);
    // 0x8002F48C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8002F490: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002F494: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8002F498: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8002F49C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002F4A0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002F4A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002F4A8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002F4AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002F4B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002F4B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002F4B8: lh          $a0, 0x0($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X0);
    // 0x8002F4BC: jal         0x80070A04
    // 0x8002F4C0: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    sins_f(rdram, ctx);
        goto after_0;
    // 0x8002F4C0: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    after_0:
    // 0x8002F4C4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8002F4C8: addiu       $t4, $t4, -0x29BC
    ctx->r12 = ADD32(ctx->r12, -0X29BC);
    // 0x8002F4CC: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8002F4D0: nop

    // 0x8002F4D4: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    // 0x8002F4D8: jal         0x80070A38
    // 0x8002F4DC: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x8002F4DC: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8002F4E0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002F4E4: lw          $t8, -0x29C0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X29C0);
    // 0x8002F4E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002F4EC: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8002F4F0: lwc1        $f6, -0x29A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X29A4);
    // 0x8002F4F4: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8002F4F8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002F4FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002F500: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002F504: lwc1        $f8, 0x64E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X64E4);
    // 0x8002F508: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002F50C: div.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8002F510: lwc1        $f12, -0x2990($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2990);
    // 0x8002F514: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002F518: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8002F51C: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x8002F520: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8002F524: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002F528: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8002F52C: addiu       $t4, $t4, -0x29BC
    ctx->r12 = ADD32(ctx->r12, -0X29BC);
    // 0x8002F530: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002F534: addiu       $fp, $fp, -0x271C
    ctx->r30 = ADD32(ctx->r30, -0X271C);
    // 0x8002F538: addiu       $t5, $t5, -0x3848
    ctx->r13 = ADD32(ctx->r13, -0X3848);
    // 0x8002F53C: mul.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8002F540: bc1f        L_8002F5FC
    if (!c1cs) {
        // 0x8002F544: addiu       $s6, $zero, 0x40
        ctx->r22 = ADD32(0, 0X40);
            goto L_8002F5FC;
    }
    // 0x8002F544: addiu       $s6, $zero, 0x40
    ctx->r22 = ADD32(0, 0X40);
    // 0x8002F548: lh          $t8, -0x29B0($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X29B0);
    // 0x8002F54C: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8002F550: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8002F554: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8002F558: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002F55C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8002F560: sub.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8002F564: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8002F568: nop

    // 0x8002F56C: bc1f        L_8002F5C4
    if (!c1cs) {
        // 0x8002F570: nop
    
            goto L_8002F5C4;
    }
    // 0x8002F570: nop

    // 0x8002F574: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002F578: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8002F57C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002F580: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8002F584: lwc1        $f8, -0x298C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X298C);
    // 0x8002F588: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8002F58C: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8002F590: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002F594: nop

    // 0x8002F598: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002F59C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F5A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F5A4: nop

    // 0x8002F5A8: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8002F5AC: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8002F5B0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002F5B4: subu        $s7, $t7, $t6
    ctx->r23 = SUB32(ctx->r15, ctx->r14);
    // 0x8002F5B8: bgez        $s7, L_8002F5C4
    if (SIGNED(ctx->r23) >= 0) {
        // 0x8002F5BC: nop
    
            goto L_8002F5C4;
    }
    // 0x8002F5BC: nop

    // 0x8002F5C0: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_8002F5C4:
    // 0x8002F5C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002F5C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002F5CC: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8002F5D0: nop

    // 0x8002F5D4: bc1f        L_8002F5FC
    if (!c1cs) {
        // 0x8002F5D8: nop
    
            goto L_8002F5FC;
    }
    // 0x8002F5D8: nop

    // 0x8002F5DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002F5E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002F5E4: lwc1        $f10, 0x64E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X64E8);
    // 0x8002F5E8: nop

    // 0x8002F5EC: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8002F5F0: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002F5F4: mul.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8002F5F8: nop

L_8002F5FC:
    // 0x8002F5FC: mtc1        $s7, $f10
    ctx->f10.u32l = ctx->r23;
    // 0x8002F600: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002F604: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002F608: lwc1        $f6, -0x29AC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X29AC);
    // 0x8002F60C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002F610: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8002F614: lw          $t9, -0x3850($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3850);
    // 0x8002F618: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8002F61C: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002F620: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002F624: addiu       $s2, $zero, 0x19
    ctx->r18 = ADD32(0, 0X19);
    // 0x8002F628: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002F62C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F630: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F634: addiu       $s4, $s4, -0x2738
    ctx->r20 = ADD32(ctx->r20, -0X2738);
    // 0x8002F638: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002F63C: addiu       $s5, $s5, -0x2750
    ctx->r21 = ADD32(ctx->r21, -0X2750);
    // 0x8002F640: mfc1        $s7, $f10
    ctx->r23 = (int32_t)ctx->f10.u32l;
    // 0x8002F644: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002F648: blez        $t9, L_8002FA74
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8002F64C: sw          $zero, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = 0;
            goto L_8002FA74;
    }
    // 0x8002F64C: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x8002F650: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002F654: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8002F658: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x8002F65C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8002F660: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002F664: addiu       $t1, $t1, -0x4750
    ctx->r9 = ADD32(ctx->r9, -0X4750);
    // 0x8002F668: addiu       $t2, $t2, -0x4960
    ctx->r10 = ADD32(ctx->r10, -0X4960);
    // 0x8002F66C: addiu       $ra, $ra, -0x2718
    ctx->r31 = ADD32(ctx->r31, -0X2718);
    // 0x8002F670: addiu       $s0, $s0, -0x2714
    ctx->r16 = ADD32(ctx->r16, -0X2714);
    // 0x8002F674: addiu       $s1, $s1, -0x29B8
    ctx->r17 = ADD32(ctx->r17, -0X29B8);
    // 0x8002F678: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x8002F67C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_8002F680:
    // 0x8002F680: lbu         $v0, 0x0($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X0);
    // 0x8002F684: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002F688: addu        $t7, $v0, $s2
    ctx->r15 = ADD32(ctx->r2, ctx->r18);
    // 0x8002F68C: slti        $at, $t7, 0x18
    ctx->r1 = SIGNED(ctx->r15) < 0X18 ? 1 : 0;
    // 0x8002F690: bne         $at, $zero, L_8002F6F8
    if (ctx->r1 != 0) {
        // 0x8002F694: addiu       $v1, $v1, -0x2720
        ctx->r3 = ADD32(ctx->r3, -0X2720);
            goto L_8002F6F8;
    }
    // 0x8002F694: addiu       $v1, $v1, -0x2720
    ctx->r3 = ADD32(ctx->r3, -0X2720);
    // 0x8002F698: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x8002F69C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8002F6A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002F6A4: lw          $t6, -0x29C0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X29C0);
    // 0x8002F6A8: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x8002F6AC: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8002F6B0: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8002F6B4: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x8002F6B8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8002F6BC: lw          $t8, 0x0($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X0);
    // 0x8002F6C0: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x8002F6C4: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x8002F6C8: sh          $t8, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r24;
    // 0x8002F6CC: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8002F6D0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8002F6D4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8002F6D8: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x8002F6DC: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8002F6E0: sh          $t7, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r15;
    // 0x8002F6E4: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x8002F6E8: lbu         $v0, 0x0($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X0);
    // 0x8002F6EC: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8002F6F0: sw          $t6, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r14;
    // 0x8002F6F4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8002F6F8:
    // 0x8002F6F8: lbu         $t0, 0x1($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X1);
    // 0x8002F6FC: blez        $v0, L_8002F9A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002F700: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8002F9A8;
    }
    // 0x8002F700: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002F704: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8002F708: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002F70C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002F710: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8002F714: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002F718: addiu       $t9, $t9, -0x3848
    ctx->r25 = ADD32(ctx->r25, -0X3848);
    // 0x8002F71C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8002F720: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x8002F724: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
L_8002F728:
    // 0x8002F728: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8002F72C: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8002F730: multu       $a0, $s3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002F734: andi        $t9, $t0, 0x1
    ctx->r25 = ctx->r8 & 0X1;
    // 0x8002F738: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x8002F73C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8002F740: mflo        $t6
    ctx->r14 = lo;
    // 0x8002F744: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8002F748: beq         $t9, $zero, L_8002F828
    if (ctx->r25 == 0) {
        // 0x8002F74C: nop
    
            goto L_8002F828;
    }
    // 0x8002F74C: nop

    // 0x8002F750: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F754: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002F758: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8002F75C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002F760: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F764: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x8002F768: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8002F76C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F770: nop

    // 0x8002F774: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002F778: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8002F77C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002F780: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x8002F784: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F788: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x8002F78C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8002F790: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
    // 0x8002F794: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002F798: lwc1        $f10, 0xC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8002F79C: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8002F7A0: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8002F7A4: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8002F7A8: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002F7AC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002F7B0: nop

    // 0x8002F7B4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002F7B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F7BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F7C0: nop

    // 0x8002F7C4: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002F7C8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8002F7CC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002F7D0: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x8002F7D4: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F7D8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002F7DC: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8002F7E0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002F7E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F7E8: addu        $t6, $t1, $t9
    ctx->r14 = ADD32(ctx->r9, ctx->r25);
    // 0x8002F7EC: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8002F7F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F7F4: nop

    // 0x8002F7F8: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002F7FC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8002F800: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002F804: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x8002F808: lbu         $t9, 0x2($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F80C: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8002F810: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x8002F814: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x8002F818: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8002F81C: lwc1        $f10, 0x14($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8002F820: b           L_8002F900
    // 0x8002F824: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
        goto L_8002F900;
    // 0x8002F824: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
L_8002F828:
    // 0x8002F828: lbu         $t9, 0x2($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F82C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002F830: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8002F834: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002F838: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F83C: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8002F840: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8002F844: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F848: nop

    // 0x8002F84C: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002F850: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8002F854: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002F858: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8002F85C: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F860: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8002F864: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8002F868: addu        $a0, $t2, $t7
    ctx->r4 = ADD32(ctx->r10, ctx->r15);
    // 0x8002F86C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002F870: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8002F874: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8002F878: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8002F87C: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8002F880: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002F884: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002F888: nop

    // 0x8002F88C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002F890: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F894: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F898: nop

    // 0x8002F89C: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002F8A0: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8002F8A4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002F8A8: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x8002F8AC: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F8B0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002F8B4: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8002F8B8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002F8BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F8C0: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x8002F8C4: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8002F8C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F8CC: nop

    // 0x8002F8D0: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002F8D4: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8002F8D8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002F8DC: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x8002F8E0: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F8E4: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8002F8E8: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8002F8EC: addu        $t6, $t2, $t9
    ctx->r14 = ADD32(ctx->r10, ctx->r25);
    // 0x8002F8F0: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8002F8F4: lwc1        $f10, 0x14($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X14);
    // 0x8002F8F8: nop

    // 0x8002F8FC: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
L_8002F900:
    // 0x8002F900: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8002F904: sra         $t8, $t0, 1
    ctx->r24 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8002F908: sb          $t3, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r11;
    // 0x8002F90C: sb          $t3, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r11;
    // 0x8002F910: mul.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8002F914: sb          $t3, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r11;
    // 0x8002F918: sb          $s7, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r23;
    // 0x8002F91C: lbu         $v0, 0x0($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X0);
    // 0x8002F920: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8002F924: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8002F928: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8002F92C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002F930: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002F934: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8002F938: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8002F93C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8002F940: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002F944: nop

    // 0x8002F948: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002F94C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F950: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F954: nop

    // 0x8002F958: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002F95C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002F960: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8002F964: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8002F968: sh          $t6, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r14;
    // 0x8002F96C: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8002F970: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8002F974: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8002F978: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8002F97C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002F980: nop

    // 0x8002F984: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002F988: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F98C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F990: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002F994: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002F998: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8002F99C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002F9A0: bne         $at, $zero, L_8002F728
    if (ctx->r1 != 0) {
        // 0x8002F9A4: sh          $t8, -0x2($a2)
        MEM_H(-0X2, ctx->r6) = ctx->r24;
            goto L_8002F728;
    }
    // 0x8002F9A4: sh          $t8, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r24;
L_8002F9A8:
    // 0x8002F9A8: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8002F9AC: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8002F9B0: bne         $at, $zero, L_8002FA50
    if (ctx->r1 != 0) {
        // 0x8002F9B4: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_8002FA50;
    }
    // 0x8002F9B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002F9B8: addiu       $a0, $s2, 0x1
    ctx->r4 = ADD32(ctx->r18, 0X1);
    // 0x8002F9BC: addiu       $t0, $a0, 0x1
    ctx->r8 = ADD32(ctx->r4, 0X1);
    // 0x8002F9C0: addiu       $a1, $sp, 0x92
    ctx->r5 = ADD32(ctx->r29, 0X92);
    // 0x8002F9C4: addiu       $a2, $sp, 0x82
    ctx->r6 = ADD32(ctx->r29, 0X82);
L_8002F9C8:
    // 0x8002F9C8: lw          $v1, 0x0($ra)
    ctx->r3 = MEM_W(ctx->r31, 0X0);
    // 0x8002F9CC: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x8002F9D0: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x8002F9D4: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8002F9D8: sw          $t8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r24;
    // 0x8002F9DC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8002F9E0: sb          $s6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r22;
    // 0x8002F9E4: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x8002F9E8: sb          $t0, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r8;
    // 0x8002F9EC: sb          $s2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r18;
    // 0x8002F9F0: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x8002F9F4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002F9F8: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x8002F9FC: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x8002FA00: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8002FA04: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x8002FA08: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x8002FA0C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002FA10: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x8002FA14: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x8002FA18: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8002FA1C: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
    // 0x8002FA20: lh          $t9, 0x90($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X90);
    // 0x8002FA24: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8002FA28: sh          $t9, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r25;
    // 0x8002FA2C: lh          $t6, 0x80($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X80);
    // 0x8002FA30: nop

    // 0x8002FA34: sh          $t6, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r14;
    // 0x8002FA38: lbu         $v0, 0x0($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X0);
    // 0x8002FA3C: nop

    // 0x8002FA40: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8002FA44: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002FA48: bne         $at, $zero, L_8002F9C8
    if (ctx->r1 != 0) {
        // 0x8002FA4C: nop
    
            goto L_8002F9C8;
    }
    // 0x8002FA4C: nop

L_8002FA50:
    // 0x8002FA50: lw          $v1, 0xAC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XAC);
    // 0x8002FA54: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002FA58: lw          $t8, -0x3850($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3850);
    // 0x8002FA5C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002FA60: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002FA64: sw          $v1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r3;
    // 0x8002FA68: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8002FA6C: bne         $at, $zero, L_8002F680
    if (ctx->r1 != 0) {
        // 0x8002FA70: addu        $s2, $s2, $v0
        ctx->r18 = ADD32(ctx->r18, ctx->r2);
            goto L_8002F680;
    }
    // 0x8002FA70: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_8002FA74:
    // 0x8002FA74: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002FA78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002FA7C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FA80: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002FA84: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002FA88: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002FA8C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002FA90: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002FA94: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8002FA98: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8002FA9C: jr          $ra
    // 0x8002FAA0: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8002FAA0: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void music_channel_active(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000114C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001150: lw          $t6, -0x3460($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3460);
    // 0x80001154: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80001158: lhu         $t7, 0x30($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X30);
    // 0x8000115C: sllv        $t9, $t8, $a0
    ctx->r25 = S32(ctx->r24 << (ctx->r4 & 31));
    // 0x80001160: and         $v0, $t7, $t9
    ctx->r2 = ctx->r15 & ctx->r25;
    // 0x80001164: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80001168: jr          $ra
    // 0x8000116C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x8000116C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void racer_update_eggs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045168: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004516C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045170: lw          $v0, 0x64($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X64);
    // 0x80045174: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80045178: lb          $t7, 0x193($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X193);
    // 0x8004517C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80045180: sb          $t7, -0x24F8($at)
    MEM_B(-0X24F8, ctx->r1) = ctx->r15;
    // 0x80045184: lb          $t8, 0x1CF($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1CF);
    // 0x80045188: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004518C: beq         $t8, $zero, L_800451A4
    if (ctx->r24 == 0) {
        // 0x80045190: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800451A4;
    }
    // 0x80045190: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80045194: lb          $t9, -0x24F8($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X24F8);
    // 0x80045198: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004519C: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x800451A0: sb          $t0, -0x24F8($at)
    MEM_B(-0X24F8, ctx->r1) = ctx->r8;
L_800451A4:
    // 0x800451A4: lw          $t1, 0x144($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X144);
    // 0x800451A8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800451AC: beq         $t1, $zero, L_800451C4
    if (ctx->r9 == 0) {
        // 0x800451B0: nop
    
            goto L_800451C4;
    }
    // 0x800451B0: nop

    // 0x800451B4: lb          $t2, -0x24F8($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X24F8);
    // 0x800451B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800451BC: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x800451C0: sb          $t3, -0x24F8($at)
    MEM_B(-0X24F8, ctx->r1) = ctx->r11;
L_800451C4:
    // 0x800451C4: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x800451C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800451CC: lw          $v0, 0x64($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X64);
    // 0x800451D0: nop

    // 0x800451D4: lb          $t5, 0x193($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X193);
    // 0x800451D8: nop

    // 0x800451DC: sb          $t5, -0x24F7($at)
    MEM_B(-0X24F7, ctx->r1) = ctx->r13;
    // 0x800451E0: lb          $t6, 0x1CF($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1CF);
    // 0x800451E4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800451E8: beq         $t6, $zero, L_80045200
    if (ctx->r14 == 0) {
        // 0x800451EC: nop
    
            goto L_80045200;
    }
    // 0x800451EC: nop

    // 0x800451F0: lb          $t7, -0x24F7($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X24F7);
    // 0x800451F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800451F8: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x800451FC: sb          $t8, -0x24F7($at)
    MEM_B(-0X24F7, ctx->r1) = ctx->r24;
L_80045200:
    // 0x80045200: lw          $t9, 0x144($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X144);
    // 0x80045204: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80045208: beq         $t9, $zero, L_80045220
    if (ctx->r25 == 0) {
        // 0x8004520C: nop
    
            goto L_80045220;
    }
    // 0x8004520C: nop

    // 0x80045210: lb          $t0, -0x24F7($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X24F7);
    // 0x80045214: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045218: ori         $t1, $t0, 0x80
    ctx->r9 = ctx->r8 | 0X80;
    // 0x8004521C: sb          $t1, -0x24F7($at)
    MEM_B(-0X24F7, ctx->r1) = ctx->r9;
L_80045220:
    // 0x80045220: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x80045224: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045228: lw          $v0, 0x64($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X64);
    // 0x8004522C: nop

    // 0x80045230: lb          $t3, 0x193($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X193);
    // 0x80045234: nop

    // 0x80045238: sb          $t3, -0x24F6($at)
    MEM_B(-0X24F6, ctx->r1) = ctx->r11;
    // 0x8004523C: lb          $t4, 0x1CF($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X1CF);
    // 0x80045240: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80045244: beq         $t4, $zero, L_8004525C
    if (ctx->r12 == 0) {
        // 0x80045248: nop
    
            goto L_8004525C;
    }
    // 0x80045248: nop

    // 0x8004524C: lb          $t5, -0x24F6($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X24F6);
    // 0x80045250: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045254: ori         $t6, $t5, 0x40
    ctx->r14 = ctx->r13 | 0X40;
    // 0x80045258: sb          $t6, -0x24F6($at)
    MEM_B(-0X24F6, ctx->r1) = ctx->r14;
L_8004525C:
    // 0x8004525C: lw          $t7, 0x144($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X144);
    // 0x80045260: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80045264: beq         $t7, $zero, L_8004527C
    if (ctx->r15 == 0) {
        // 0x80045268: nop
    
            goto L_8004527C;
    }
    // 0x80045268: nop

    // 0x8004526C: lb          $t8, -0x24F6($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X24F6);
    // 0x80045270: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045274: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x80045278: sb          $t9, -0x24F6($at)
    MEM_B(-0X24F6, ctx->r1) = ctx->r25;
L_8004527C:
    // 0x8004527C: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x80045280: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045284: lw          $v0, 0x64($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X64);
    // 0x80045288: nop

    // 0x8004528C: lb          $t1, 0x193($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X193);
    // 0x80045290: nop

    // 0x80045294: sb          $t1, -0x24F5($at)
    MEM_B(-0X24F5, ctx->r1) = ctx->r9;
    // 0x80045298: lb          $t2, 0x1CF($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X1CF);
    // 0x8004529C: nop

    // 0x800452A0: beq         $t2, $zero, L_800452B8
    if (ctx->r10 == 0) {
        // 0x800452A4: nop
    
            goto L_800452B8;
    }
    // 0x800452A4: nop

    // 0x800452A8: lb          $t3, -0x24F5($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X24F5);
    // 0x800452AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800452B0: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x800452B4: sb          $t4, -0x24F5($at)
    MEM_B(-0X24F5, ctx->r1) = ctx->r12;
L_800452B8:
    // 0x800452B8: lw          $t5, 0x144($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X144);
    // 0x800452BC: nop

    // 0x800452C0: beq         $t5, $zero, L_800452D8
    if (ctx->r13 == 0) {
        // 0x800452C4: nop
    
            goto L_800452D8;
    }
    // 0x800452C4: nop

    // 0x800452C8: lb          $t6, -0x24F5($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X24F5);
    // 0x800452CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800452D0: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x800452D4: sb          $t7, -0x24F5($at)
    MEM_B(-0X24F5, ctx->r1) = ctx->r15;
L_800452D8:
    // 0x800452D8: jr          $ra
    // 0x800452DC: nop

    return;
    // 0x800452DC: nop

;}
RECOMP_FUNC void rotate_racer_in_water(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049520: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80049524: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x80049528: sll         $t6, $a3, 24
    ctx->r14 = S32(ctx->r7 << 24);
    // 0x8004952C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80049530: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x80049534: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80049538: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8004953C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80049540: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80049544: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80049548: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004954C: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80049550: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x80049554: bne         $t7, $at, L_800495BC
    if (ctx->r15 != ctx->r1) {
        // 0x80049558: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800495BC;
    }
    // 0x80049558: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004955C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80049560: lwc1        $f2, 0x2C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80049564: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049568: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004956C: nop

    // 0x80049570: bc1f        L_8004957C
    if (!c1cs) {
        // 0x80049574: nop
    
            goto L_8004957C;
    }
    // 0x80049574: nop

    // 0x80049578: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8004957C:
    // 0x8004957C: lwc1        $f9, 0x6A30($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6A30);
    // 0x80049580: lwc1        $f8, 0x6A34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6A34);
    // 0x80049584: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80049588: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8004958C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80049590: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80049594: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80049598: nop

    // 0x8004959C: sub.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d - ctx->f10.d;
    // 0x800495A0: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x800495A4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800495A8: nop

    // 0x800495AC: bc1f        L_80049600
    if (!c1cs) {
        // 0x800495B0: nop
    
            goto L_80049600;
    }
    // 0x800495B0: nop

    // 0x800495B4: b           L_80049600
    // 0x800495B8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80049600;
    // 0x800495B8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800495BC:
    // 0x800495BC: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800495C0: lwc1        $f12, 0xA0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800495C4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800495C8: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800495CC: lwc1        $f18, 0x14($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800495D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800495D4: mul.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800495D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800495DC: add.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800495E0: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x800495E4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800495E8: nop

    // 0x800495EC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800495F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800495F4: mul.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800495F8: add.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800495FC: swc1        $f16, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f16.u32l;
L_80049600:
    // 0x80049600: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    // 0x80049604: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80049608: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x8004960C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80049610: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80049614: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x80049618: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x8004961C: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x80049620: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x80049624: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x80049628: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x8004962C: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x80049630: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x80049634: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80049638: jal         0x800700B4
    // 0x8004963C: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x8004963C: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    after_0:
    // 0x80049640: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80049644: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80049648: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8004964C: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
    // 0x80049650: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x80049654: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80049658: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8004965C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80049660: jal         0x8006F88C
    // 0x80049664: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x80049664: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_1:
    // 0x80049668: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8004966C: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80049670: jal         0x80070990
    // 0x80049674: nop

    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x80049674: nop

    after_2:
    // 0x80049678: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x8004967C: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80049680: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x80049684: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80049688: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004968C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80049690: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80049694: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x80049698: mul.s       $f18, $f8, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004969C: lh          $v1, 0x1A4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X1A4);
    // 0x800496A0: sll         $t0, $t9, 6
    ctx->r8 = S32(ctx->r25 << 6);
    // 0x800496A4: andi        $t3, $v1, 0xFFFF
    ctx->r11 = ctx->r3 & 0XFFFF;
    // 0x800496A8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800496AC: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x800496B0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800496B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800496B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800496BC: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800496C0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800496C4: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800496C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800496CC: subu        $t1, $t8, $t0
    ctx->r9 = SUB32(ctx->r24, ctx->r8);
    // 0x800496D0: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800496D4: subu        $a0, $t2, $t3
    ctx->r4 = SUB32(ctx->r10, ctx->r11);
    // 0x800496D8: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800496DC: bne         $at, $zero, L_800496EC
    if (ctx->r1 != 0) {
        // 0x800496E0: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800496EC;
    }
    // 0x800496E0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800496E4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800496E8: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_800496EC:
    // 0x800496EC: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x800496F0: beq         $at, $zero, L_800496FC
    if (ctx->r1 == 0) {
        // 0x800496F4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800496FC;
    }
    // 0x800496F4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800496F8: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_800496FC:
    // 0x800496FC: multu       $a0, $t4
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80049700: mflo        $t5
    ctx->r13 = lo;
    // 0x80049704: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x80049708: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8004970C: sh          $t7, 0x1A4($a1)
    MEM_H(0X1A4, ctx->r5) = ctx->r15;
    // 0x80049710: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80049714: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80049718: jal         0x80070990
    // 0x8004971C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    arctan2_f(rdram, ctx);
        goto after_3;
    // 0x8004971C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x80049720: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80049724: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80049728: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8004972C: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80049730: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80049734: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80049738: lw          $t2, -0x2548($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2548);
    // 0x8004973C: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80049740: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80049744: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80049748: lh          $a1, 0x2($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X2);
    // 0x8004974C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80049750: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80049754: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80049758: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004975C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80049760: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80049764: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80049768: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x8004976C: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80049770: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80049774: addu        $v1, $t1, $t4
    ctx->r3 = ADD32(ctx->r9, ctx->r12);
    // 0x80049778: addiu       $v1, $v1, 0x3C0
    ctx->r3 = ADD32(ctx->r3, 0X3C0);
    // 0x8004977C: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x80049780: subu        $a0, $t5, $t6
    ctx->r4 = SUB32(ctx->r13, ctx->r14);
    // 0x80049784: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80049788: bne         $at, $zero, L_80049798
    if (ctx->r1 != 0) {
        // 0x8004978C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80049798;
    }
    // 0x8004978C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80049790: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80049794: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_80049798:
    // 0x80049798: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x8004979C: beq         $at, $zero, L_800497A8
    if (ctx->r1 == 0) {
        // 0x800497A0: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800497A8;
    }
    // 0x800497A0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800497A4: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_800497A8:
    // 0x800497A8: multu       $a0, $t7
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800497AC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800497B0: mflo        $t9
    ctx->r25 = lo;
    // 0x800497B4: sra         $t8, $t9, 4
    ctx->r24 = S32(SIGNED(ctx->r25) >> 4);
    // 0x800497B8: addu        $t0, $a1, $t8
    ctx->r8 = ADD32(ctx->r5, ctx->r24);
    // 0x800497BC: sh          $t0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r8;
    // 0x800497C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800497C4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800497C8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800497CC: jr          $ra
    // 0x800497D0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800497D0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void get_first_active_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014814: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80014818: addiu       $a2, $a2, -0x4C24
    ctx->r6 = ADD32(ctx->r6, -0X4C24);
    // 0x8001481C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80014820: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80014824: addiu       $t2, $t2, -0x4C04
    ctx->r10 = ADD32(ctx->r10, -0X4C04);
    // 0x80014828: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001482C: lh          $v1, 0x0($t2)
    ctx->r3 = MEM_H(ctx->r10, 0X0);
    // 0x80014830: nop

    // 0x80014834: beq         $v1, $zero, L_80014844
    if (ctx->r3 == 0) {
        // 0x80014838: nop
    
            goto L_80014844;
    }
    // 0x80014838: nop

    // 0x8001483C: jr          $ra
    // 0x80014840: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80014840: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80014844:
    // 0x80014844: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80014848: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001484C: lw          $v1, -0x4C20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C20);
    // 0x80014850: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80014854: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80014858: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001485C: bne         $at, $zero, L_800149B0
    if (ctx->r1 != 0) {
        // 0x80014860: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800149B0;
    }
    // 0x80014860: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80014864: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80014868: addiu       $t3, $t3, -0x4C28
    ctx->r11 = ADD32(ctx->r11, -0X4C28);
    // 0x8001486C: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
L_80014870:
    // 0x80014870: bne         $at, $zero, L_800148EC
    if (ctx->r1 != 0) {
        // 0x80014874: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800148EC;
    }
    // 0x80014874: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80014878: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8001487C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80014880: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
L_80014884:
    // 0x80014884: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x80014888: nop

    // 0x8001488C: lh          $t9, 0x6($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X6);
    // 0x80014890: nop

    // 0x80014894: andi        $t4, $t9, 0x8000
    ctx->r12 = ctx->r25 & 0X8000;
    // 0x80014898: bne         $t4, $zero, L_800148D0
    if (ctx->r12 != 0) {
        // 0x8001489C: nop
    
            goto L_800148D0;
    }
    // 0x8001489C: nop

    // 0x800148A0: lw          $t5, 0x40($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X40);
    // 0x800148A4: nop

    // 0x800148A8: lhu         $t6, 0x30($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X30);
    // 0x800148AC: nop

    // 0x800148B0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800148B4: beq         $t7, $zero, L_800148C8
    if (ctx->r15 == 0) {
        // 0x800148B8: nop
    
            goto L_800148C8;
    }
    // 0x800148B8: nop

    // 0x800148BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800148C0: b           L_800148D8
    // 0x800148C4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
        goto L_800148D8;
    // 0x800148C4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_800148C8:
    // 0x800148C8: b           L_800148D8
    // 0x800148CC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_800148D8;
    // 0x800148CC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800148D0:
    // 0x800148D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800148D4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_800148D8:
    // 0x800148D8: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800148DC: bne         $at, $zero, L_800148F0
    if (ctx->r1 != 0) {
        // 0x800148E0: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800148F0;
    }
    // 0x800148E0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800148E4: beq         $a2, $zero, L_80014884
    if (ctx->r6 == 0) {
        // 0x800148E8: nop
    
            goto L_80014884;
    }
    // 0x800148E8: nop

L_800148EC:
    // 0x800148EC: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
L_800148F0:
    // 0x800148F0: bne         $at, $zero, L_80014968
    if (ctx->r1 != 0) {
        // 0x800148F4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80014968;
    }
    // 0x800148F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800148F8: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x800148FC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80014900: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
L_80014904:
    // 0x80014904: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x80014908: nop

    // 0x8001490C: lh          $t4, 0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X6);
    // 0x80014910: nop

    // 0x80014914: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x80014918: beq         $t5, $zero, L_80014928
    if (ctx->r13 == 0) {
        // 0x8001491C: nop
    
            goto L_80014928;
    }
    // 0x8001491C: nop

    // 0x80014920: b           L_80014954
    // 0x80014924: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_80014954;
    // 0x80014924: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80014928:
    // 0x80014928: lw          $t6, 0x40($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X40);
    // 0x8001492C: nop

    // 0x80014930: lhu         $t7, 0x30($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X30);
    // 0x80014934: nop

    // 0x80014938: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8001493C: bne         $t8, $zero, L_80014950
    if (ctx->r24 != 0) {
        // 0x80014940: nop
    
            goto L_80014950;
    }
    // 0x80014940: nop

    // 0x80014944: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80014948: b           L_80014954
    // 0x8001494C: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
        goto L_80014954;
    // 0x8001494C: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
L_80014950:
    // 0x80014950: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80014954:
    // 0x80014954: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014958: bne         $at, $zero, L_8001496C
    if (ctx->r1 != 0) {
        // 0x8001495C: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001496C;
    }
    // 0x8001495C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014960: beq         $a2, $zero, L_80014904
    if (ctx->r6 == 0) {
        // 0x80014964: nop
    
            goto L_80014904;
    }
    // 0x80014964: nop

L_80014968:
    // 0x80014968: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_8001496C:
    // 0x8001496C: beq         $at, $zero, L_800149A4
    if (ctx->r1 == 0) {
        // 0x80014970: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_800149A4;
    }
    // 0x80014970: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80014974: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x80014978: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8001497C: addu        $t4, $a2, $t0
    ctx->r12 = ADD32(ctx->r6, ctx->r8);
    // 0x80014980: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80014984: addu        $a3, $a2, $t9
    ctx->r7 = ADD32(ctx->r6, ctx->r25);
    // 0x80014988: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8001498C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x80014990: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x80014994: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80014998: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8001499C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800149A0: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
L_800149A4:
    // 0x800149A4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800149A8: beq         $at, $zero, L_80014870
    if (ctx->r1 == 0) {
        // 0x800149AC: slt         $at, $a1, $v1
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80014870;
    }
    // 0x800149AC: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
L_800149B0:
    // 0x800149B0: sh          $v1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r3;
    // 0x800149B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800149B8: jr          $ra
    // 0x800149BC: nop

    return;
    // 0x800149BC: nop

;}
RECOMP_FUNC void timetrial_ghost_full(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059E70: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80059E74: lb          $t6, -0x24E4($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X24E4);
    // 0x80059E78: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80059E7C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80059E80: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80059E84: lh          $v0, -0x24D8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X24D8);
    // 0x80059E88: jr          $ra
    // 0x80059E8C: nop

    return;
    // 0x80059E8C: nop

;}
RECOMP_FUNC void level_world_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B41C: bltz        $a0, L_8006B43C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B420: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8006B43C;
    }
    // 0x8006B420: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006B424: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B428: lw          $t6, 0x16F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F4);
    // 0x8006B42C: nop

    // 0x8006B430: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B434: bne         $at, $zero, L_8006B444
    if (ctx->r1 != 0) {
        // 0x8006B438: addiu       $a0, $zero, 0x1B
        ctx->r4 = ADD32(0, 0X1B);
            goto L_8006B444;
    }
    // 0x8006B438: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
L_8006B43C:
    // 0x8006B43C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006B440: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
L_8006B444:
    // 0x8006B444: jal         0x8001E2D0
    // 0x8006B448: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8006B448: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006B44C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006B450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B454: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x8006B458: lb          $v0, 0x0($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X0);
    // 0x8006B45C: jr          $ra
    // 0x8006B460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006B460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void alEvtqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9830: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C9834: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C9838: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C983C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C9840: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C9844: jal         0x800C9F90
    // 0x800C9848: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C9848: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C984C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C9850: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800C9854: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800C9858: lw          $s0, 0x8($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X8);
    // 0x800C985C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C9860: beql        $s0, $zero, L_800C9898
    if (ctx->r16 == 0) {
        // 0x800C9864: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_800C9898;
    }
    goto skip_0;
    // 0x800C9864: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    skip_0:
    // 0x800C9868: jal         0x800C8CC0
    // 0x800C986C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800C986C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C9870: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x800C9874: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800C9878: jal         0x800D3D80
    // 0x800C987C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    alCopy(rdram, ctx);
        goto after_2;
    // 0x800C987C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_2:
    // 0x800C9880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C9884: jal         0x800C8CF0
    // 0x800C9888: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    alLink(rdram, ctx);
        goto after_3;
    // 0x800C9888: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x800C988C: b           L_800C989C
    // 0x800C9890: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
        goto L_800C989C;
    // 0x800C9890: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x800C9894: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_800C9898:
    // 0x800C9898: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_800C989C:
    // 0x800C989C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800C98A0: jal         0x800C9F90
    // 0x800C98A4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_4;
    // 0x800C98A4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_4:
    // 0x800C98A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C98AC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800C98B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C98B4: jr          $ra
    // 0x800C98B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C98B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void set_viewport_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066CE8: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
    // 0x80066CEC: beq         $a1, $t0, L_80066D28
    if (ctx->r5 == ctx->r8) {
        // 0x80066CF0: sll         $t1, $a0, 2
        ctx->r9 = S32(ctx->r4 << 2);
            goto L_80066D28;
    }
    // 0x80066CF0: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80066CF4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066CF8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066CFC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066D00: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066D04: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80066D08: addiu       $t7, $t7, -0x2A2C
    ctx->r15 = ADD32(ctx->r15, -0X2A2C);
    // 0x80066D0C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066D10: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80066D14: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x80066D18: sw          $a1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r5;
    // 0x80066D1C: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80066D20: b           L_80066D54
    // 0x80066D24: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
        goto L_80066D54;
    // 0x80066D24: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_80066D28:
    // 0x80066D28: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x80066D2C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80066D30: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x80066D34: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80066D38: addiu       $t2, $t2, -0x2A2C
    ctx->r10 = ADD32(ctx->r10, -0X2A2C);
    // 0x80066D3C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80066D40: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80066D44: lw          $t3, 0x30($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X30);
    // 0x80066D48: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80066D4C: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80066D50: sw          $t4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r12;
L_80066D54:
    // 0x80066D54: beq         $a2, $t0, L_80066D70
    if (ctx->r6 == ctx->r8) {
        // 0x80066D58: nop
    
            goto L_80066D70;
    }
    // 0x80066D58: nop

    // 0x80066D5C: lw          $t5, 0x30($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X30);
    // 0x80066D60: sw          $a2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r6;
    // 0x80066D64: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x80066D68: b           L_80066D80
    // 0x80066D6C: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
        goto L_80066D80;
    // 0x80066D6C: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
L_80066D70:
    // 0x80066D70: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x80066D74: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80066D78: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80066D7C: sw          $t8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r24;
L_80066D80:
    // 0x80066D80: beq         $a3, $t0, L_80066D9C
    if (ctx->r7 == ctx->r8) {
        // 0x80066D84: nop
    
            goto L_80066D9C;
    }
    // 0x80066D84: nop

    // 0x80066D88: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
    // 0x80066D8C: sw          $a3, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r7;
    // 0x80066D90: ori         $t1, $t9, 0x20
    ctx->r9 = ctx->r25 | 0X20;
    // 0x80066D94: b           L_80066DAC
    // 0x80066D98: sw          $t1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r9;
        goto L_80066DAC;
    // 0x80066D98: sw          $t1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r9;
L_80066D9C:
    // 0x80066D9C: lw          $t2, 0x30($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X30);
    // 0x80066DA0: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80066DA4: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80066DA8: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
L_80066DAC:
    // 0x80066DAC: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80066DB0: nop

    // 0x80066DB4: beq         $v1, $t0, L_80066DD0
    if (ctx->r3 == ctx->r8) {
        // 0x80066DB8: nop
    
            goto L_80066DD0;
    }
    // 0x80066DB8: nop

    // 0x80066DBC: lw          $t4, 0x30($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30);
    // 0x80066DC0: sw          $v1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r3;
    // 0x80066DC4: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x80066DC8: jr          $ra
    // 0x80066DCC: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
    return;
    // 0x80066DCC: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
L_80066DD0:
    // 0x80066DD0: lw          $t6, 0x30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X30);
    // 0x80066DD4: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80066DD8: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80066DDC: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
    // 0x80066DE0: jr          $ra
    // 0x80066DE4: nop

    return;
    // 0x80066DE4: nop

;}
RECOMP_FUNC void obj_loop_snowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800382BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800382C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800382C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800382C8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800382CC: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x800382D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800382D4: lh          $v1, 0x24($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X24);
    // 0x800382D8: nop

    // 0x800382DC: bne         $v1, $zero, L_80038300
    if (ctx->r3 != 0) {
        // 0x800382E0: nop
    
            goto L_80038300;
    }
    // 0x800382E0: nop

    // 0x800382E4: lb          $a0, 0x38($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X38);
    // 0x800382E8: nop

    // 0x800382EC: beq         $a0, $zero, L_80038300
    if (ctx->r4 == 0) {
        // 0x800382F0: andi        $t6, $a0, 0xFF
        ctx->r14 = ctx->r4 & 0XFF;
            goto L_80038300;
    }
    // 0x800382F0: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800382F4: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x800382F8: lh          $v1, 0x24($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X24);
    // 0x800382FC: nop

L_80038300:
    // 0x80038300: beq         $v1, $zero, L_80038354
    if (ctx->r3 == 0) {
        // 0x80038304: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80038354;
    }
    // 0x80038304: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80038308: lw          $t0, 0x20($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X20);
    // 0x8003830C: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x80038310: bne         $t0, $zero, L_8003833C
    if (ctx->r8 != 0) {
        // 0x80038314: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8003833C;
    }
    // 0x80038314: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80038318: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003831C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80038320: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80038324: addiu       $t8, $v0, 0x20
    ctx->r24 = ADD32(ctx->r2, 0X20);
    // 0x80038328: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003832C: jal         0x80009558
    // 0x80038330: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_0;
    // 0x80038330: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x80038334: b           L_80038354
    // 0x80038338: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
        goto L_80038354;
    // 0x80038338: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
L_8003833C:
    // 0x8003833C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80038340: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80038344: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80038348: jal         0x800096D8
    // 0x8003834C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    audspat_point_set_position(rdram, ctx);
        goto after_1;
    // 0x8003834C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
    // 0x80038350: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
L_80038354:
    // 0x80038354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80038358: jal         0x8001F494
    // 0x8003835C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8001F460(rdram, ctx);
        goto after_2;
    // 0x8003835C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x80038360: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80038364: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80038368: jr          $ra
    // 0x8003836C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003836C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80014B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014B50: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80014B54: sltiu       $at, $a3, 0xB
    ctx->r1 = ctx->r7 < 0XB ? 1 : 0;
    // 0x80014B58: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80014B5C: beq         $at, $zero, L_80015340
    if (ctx->r1 == 0) {
        // 0x80014B60: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80015340;
    }
    // 0x80014B60: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80014B64: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80014B68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80014B6C: addu        $at, $at, $t6
    gpr jr_addend_80014B78 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80014B70: lw          $t6, 0x5B18($at)
    ctx->r14 = ADD32(ctx->r1, 0X5B18);
    // 0x80014B74: nop

    // 0x80014B78: jr          $t6
    // 0x80014B7C: nop

    switch (jr_addend_80014B78 >> 2) {
        case 0: goto L_80014B80; break;
        case 1: goto L_80014CCC; break;
        case 2: goto L_80014E18; break;
        case 3: goto L_80015340; break;
        case 4: goto L_80015340; break;
        case 5: goto L_80015340; break;
        case 6: goto L_80015340; break;
        case 7: goto L_80015340; break;
        case 8: goto L_80014F64; break;
        case 9: goto L_800150B0; break;
        case 10: goto L_800151FC; break;
        default: switch_error(__func__, 0x80014B78, 0x800E5B18);
    }
    // 0x80014B7C: nop

L_80014B80:
    // 0x80014B80: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014B84: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x80014B88: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x80014B88: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80014B8C: addiu       $t2, $t2, -0x4C28
    ctx->r10 = ADD32(ctx->r10, -0X4C28);
    // 0x80014B90: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80014B94:
    // 0x80014B94: bne         $at, $zero, L_80014C0C
    if (ctx->r1 != 0) {
        // 0x80014B98: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014C0C;
    }
    // 0x80014B98: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014B9C: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x80014BA0: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80014BA4: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x80014BA8: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014BAC: nop

    // 0x80014BB0: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80014BB4: lwc1        $f6, 0x34($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014BB8: nop

    // 0x80014BBC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014BC0: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80014BC4: nop

    // 0x80014BC8: bc1f        L_80014C0C
    if (!c1cs) {
        // 0x80014BCC: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014C0C;
    }
    // 0x80014BCC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014BD0:
    // 0x80014BD0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014BD4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014BD8: bne         $at, $zero, L_80014C08
    if (ctx->r1 != 0) {
        // 0x80014BDC: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80014C08;
    }
    // 0x80014BDC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80014BE0: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014BE4: nop

    // 0x80014BE8: lwc1        $f10, 0xC($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80014BEC: lwc1        $f16, 0x34($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014BF0: nop

    // 0x80014BF4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014BF8: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80014BFC: nop

    // 0x80014C00: bc1t        L_80014BD0
    if (c1cs) {
        // 0x80014C04: nop
    
            goto L_80014BD0;
    }
    // 0x80014C04: nop

L_80014C08:
    // 0x80014C08: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014C0C:
    // 0x80014C0C: bne         $at, $zero, L_80014C80
    if (ctx->r1 != 0) {
        // 0x80014C10: sll         $t4, $a0, 2
        ctx->r12 = S32(ctx->r4 << 2);
            goto L_80014C80;
    }
    // 0x80014C10: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x80014C14: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80014C18: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80014C1C: addu        $a2, $t9, $t3
    ctx->r6 = ADD32(ctx->r25, ctx->r11);
    // 0x80014C20: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014C24: nop

    // 0x80014C28: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80014C2C: lwc1        $f6, 0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014C30: nop

    // 0x80014C34: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014C38: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80014C3C: nop

    // 0x80014C40: bc1f        L_80014C84
    if (!c1cs) {
        // 0x80014C44: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80014C84;
    }
    // 0x80014C44: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014C48:
    // 0x80014C48: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014C4C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014C50: bne         $at, $zero, L_80014C80
    if (ctx->r1 != 0) {
        // 0x80014C54: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80014C80;
    }
    // 0x80014C54: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80014C58: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014C5C: nop

    // 0x80014C60: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80014C64: lwc1        $f16, 0x34($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014C68: nop

    // 0x80014C6C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014C70: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x80014C74: nop

    // 0x80014C78: bc1t        L_80014C48
    if (c1cs) {
        // 0x80014C7C: nop
    
            goto L_80014C48;
    }
    // 0x80014C7C: nop

L_80014C80:
    // 0x80014C80: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014C84:
    // 0x80014C84: beq         $at, $zero, L_80014CB8
    if (ctx->r1 == 0) {
        // 0x80014C88: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_80014CB8;
    }
    // 0x80014C88: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80014C8C: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80014C90: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014C94: addu        $t5, $a2, $t0
    ctx->r13 = ADD32(ctx->r6, ctx->r8);
    // 0x80014C98: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80014C9C: addu        $a3, $a2, $t4
    ctx->r7 = ADD32(ctx->r6, ctx->r12);
    // 0x80014CA0: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80014CA4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80014CA8: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x80014CAC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014CB0: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x80014CB4: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
L_80014CB8:
    // 0x80014CB8: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014CBC: beq         $at, $zero, L_80014B94
    if (ctx->r1 == 0) {
        // 0x80014CC0: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80014B94;
    }
    // 0x80014CC0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014CC4: jr          $ra
    // 0x80014CC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80014CC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80014CCC:
    // 0x80014CCC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014CD0: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x80014CD4: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x80014CD4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80014CD8: addiu       $t2, $t2, -0x4C28
    ctx->r10 = ADD32(ctx->r10, -0X4C28);
    // 0x80014CDC: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80014CE0:
    // 0x80014CE0: bne         $at, $zero, L_80014D58
    if (ctx->r1 != 0) {
        // 0x80014CE4: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014D58;
    }
    // 0x80014CE4: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014CE8: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80014CEC: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x80014CF0: addu        $a3, $t9, $t3
    ctx->r7 = ADD32(ctx->r25, ctx->r11);
    // 0x80014CF4: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014CF8: nop

    // 0x80014CFC: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80014D00: lwc1        $f6, 0x34($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014D04: nop

    // 0x80014D08: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014D0C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80014D10: nop

    // 0x80014D14: bc1f        L_80014D58
    if (!c1cs) {
        // 0x80014D18: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014D58;
    }
    // 0x80014D18: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014D1C:
    // 0x80014D1C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014D20: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014D24: bne         $at, $zero, L_80014D54
    if (ctx->r1 != 0) {
        // 0x80014D28: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80014D54;
    }
    // 0x80014D28: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80014D2C: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014D30: nop

    // 0x80014D34: lwc1        $f10, 0x10($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80014D38: lwc1        $f16, 0x34($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014D3C: nop

    // 0x80014D40: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014D44: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80014D48: nop

    // 0x80014D4C: bc1t        L_80014D1C
    if (c1cs) {
        // 0x80014D50: nop
    
            goto L_80014D1C;
    }
    // 0x80014D50: nop

L_80014D54:
    // 0x80014D54: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014D58:
    // 0x80014D58: bne         $at, $zero, L_80014DCC
    if (ctx->r1 != 0) {
        // 0x80014D5C: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80014DCC;
    }
    // 0x80014D5C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80014D60: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80014D64: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x80014D68: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x80014D6C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014D70: nop

    // 0x80014D74: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80014D78: lwc1        $f6, 0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014D7C: nop

    // 0x80014D80: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014D84: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80014D88: nop

    // 0x80014D8C: bc1f        L_80014DD0
    if (!c1cs) {
        // 0x80014D90: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80014DD0;
    }
    // 0x80014D90: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014D94:
    // 0x80014D94: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014D98: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014D9C: bne         $at, $zero, L_80014DCC
    if (ctx->r1 != 0) {
        // 0x80014DA0: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80014DCC;
    }
    // 0x80014DA0: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80014DA4: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014DA8: nop

    // 0x80014DAC: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80014DB0: lwc1        $f16, 0x34($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014DB4: nop

    // 0x80014DB8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014DBC: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x80014DC0: nop

    // 0x80014DC4: bc1t        L_80014D94
    if (c1cs) {
        // 0x80014DC8: nop
    
            goto L_80014D94;
    }
    // 0x80014DC8: nop

L_80014DCC:
    // 0x80014DCC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014DD0:
    // 0x80014DD0: beq         $at, $zero, L_80014E04
    if (ctx->r1 == 0) {
        // 0x80014DD4: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_80014E04;
    }
    // 0x80014DD4: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80014DD8: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80014DDC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014DE0: addu        $t7, $a2, $t0
    ctx->r15 = ADD32(ctx->r6, ctx->r8);
    // 0x80014DE4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80014DE8: addu        $a3, $a2, $t6
    ctx->r7 = ADD32(ctx->r6, ctx->r14);
    // 0x80014DEC: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80014DF0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80014DF4: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80014DF8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014DFC: addu        $t3, $t9, $t0
    ctx->r11 = ADD32(ctx->r25, ctx->r8);
    // 0x80014E00: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
L_80014E04:
    // 0x80014E04: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014E08: beq         $at, $zero, L_80014CE0
    if (ctx->r1 == 0) {
        // 0x80014E0C: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80014CE0;
    }
    // 0x80014E0C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014E10: jr          $ra
    // 0x80014E14: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80014E14: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80014E18:
    // 0x80014E18: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014E1C: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x80014E20: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x80014E20: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80014E24: addiu       $t2, $t2, -0x4C28
    ctx->r10 = ADD32(ctx->r10, -0X4C28);
    // 0x80014E28: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80014E2C:
    // 0x80014E2C: bne         $at, $zero, L_80014EA4
    if (ctx->r1 != 0) {
        // 0x80014E30: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014EA4;
    }
    // 0x80014E30: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014E34: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80014E38: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80014E3C: addu        $a3, $t4, $t5
    ctx->r7 = ADD32(ctx->r12, ctx->r13);
    // 0x80014E40: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014E44: nop

    // 0x80014E48: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80014E4C: lwc1        $f6, 0x34($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014E50: nop

    // 0x80014E54: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014E58: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80014E5C: nop

    // 0x80014E60: bc1f        L_80014EA4
    if (!c1cs) {
        // 0x80014E64: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014EA4;
    }
    // 0x80014E64: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014E68:
    // 0x80014E68: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014E6C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014E70: bne         $at, $zero, L_80014EA0
    if (ctx->r1 != 0) {
        // 0x80014E74: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80014EA0;
    }
    // 0x80014E74: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80014E78: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014E7C: nop

    // 0x80014E80: lwc1        $f10, 0x14($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80014E84: lwc1        $f16, 0x34($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014E88: nop

    // 0x80014E8C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014E90: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80014E94: nop

    // 0x80014E98: bc1t        L_80014E68
    if (c1cs) {
        // 0x80014E9C: nop
    
            goto L_80014E68;
    }
    // 0x80014E9C: nop

L_80014EA0:
    // 0x80014EA0: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014EA4:
    // 0x80014EA4: bne         $at, $zero, L_80014F18
    if (ctx->r1 != 0) {
        // 0x80014EA8: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_80014F18;
    }
    // 0x80014EA8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80014EAC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80014EB0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80014EB4: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x80014EB8: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014EBC: nop

    // 0x80014EC0: lwc1        $f4, 0x14($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80014EC4: lwc1        $f6, 0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014EC8: nop

    // 0x80014ECC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014ED0: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80014ED4: nop

    // 0x80014ED8: bc1f        L_80014F1C
    if (!c1cs) {
        // 0x80014EDC: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80014F1C;
    }
    // 0x80014EDC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014EE0:
    // 0x80014EE0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014EE4: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014EE8: bne         $at, $zero, L_80014F18
    if (ctx->r1 != 0) {
        // 0x80014EEC: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80014F18;
    }
    // 0x80014EEC: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80014EF0: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014EF4: nop

    // 0x80014EF8: lwc1        $f10, 0x14($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80014EFC: lwc1        $f16, 0x34($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014F00: nop

    // 0x80014F04: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014F08: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x80014F0C: nop

    // 0x80014F10: bc1t        L_80014EE0
    if (c1cs) {
        // 0x80014F14: nop
    
            goto L_80014EE0;
    }
    // 0x80014F14: nop

L_80014F18:
    // 0x80014F18: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014F1C:
    // 0x80014F1C: beq         $at, $zero, L_80014F50
    if (ctx->r1 == 0) {
        // 0x80014F20: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_80014F50;
    }
    // 0x80014F20: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80014F24: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80014F28: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014F2C: addu        $t9, $a2, $t0
    ctx->r25 = ADD32(ctx->r6, ctx->r8);
    // 0x80014F30: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80014F34: addu        $a3, $a2, $t8
    ctx->r7 = ADD32(ctx->r6, ctx->r24);
    // 0x80014F38: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80014F3C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x80014F40: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80014F44: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014F48: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x80014F4C: sw          $t1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r9;
L_80014F50:
    // 0x80014F50: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014F54: beq         $at, $zero, L_80014E2C
    if (ctx->r1 == 0) {
        // 0x80014F58: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80014E2C;
    }
    // 0x80014F58: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014F5C: jr          $ra
    // 0x80014F60: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80014F60: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80014F64:
    // 0x80014F64: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014F68: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x80014F6C: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x80014F6C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80014F70: addiu       $t2, $t2, -0x4C28
    ctx->r10 = ADD32(ctx->r10, -0X4C28);
    // 0x80014F74: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80014F78:
    // 0x80014F78: bne         $at, $zero, L_80014FF0
    if (ctx->r1 != 0) {
        // 0x80014F7C: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014FF0;
    }
    // 0x80014F7C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014F80: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80014F84: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80014F88: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x80014F8C: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014F90: nop

    // 0x80014F94: lwc1        $f4, 0x34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014F98: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80014F9C: nop

    // 0x80014FA0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80014FA4: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80014FA8: nop

    // 0x80014FAC: bc1f        L_80014FF0
    if (!c1cs) {
        // 0x80014FB0: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014FF0;
    }
    // 0x80014FB0: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014FB4:
    // 0x80014FB4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014FB8: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014FBC: bne         $at, $zero, L_80014FEC
    if (ctx->r1 != 0) {
        // 0x80014FC0: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80014FEC;
    }
    // 0x80014FC0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80014FC4: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014FC8: nop

    // 0x80014FCC: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014FD0: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80014FD4: nop

    // 0x80014FD8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80014FDC: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80014FE0: nop

    // 0x80014FE4: bc1t        L_80014FB4
    if (c1cs) {
        // 0x80014FE8: nop
    
            goto L_80014FB4;
    }
    // 0x80014FE8: nop

L_80014FEC:
    // 0x80014FEC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014FF0:
    // 0x80014FF0: bne         $at, $zero, L_80015064
    if (ctx->r1 != 0) {
        // 0x80014FF4: sll         $t3, $a0, 2
        ctx->r11 = S32(ctx->r4 << 2);
            goto L_80015064;
    }
    // 0x80014FF4: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x80014FF8: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80014FFC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80015000: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x80015004: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80015008: nop

    // 0x8001500C: lwc1        $f4, 0x34($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80015010: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80015014: nop

    // 0x80015018: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001501C: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80015020: nop

    // 0x80015024: bc1f        L_80015068
    if (!c1cs) {
        // 0x80015028: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80015068;
    }
    // 0x80015028: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_8001502C:
    // 0x8001502C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80015030: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015034: bne         $at, $zero, L_80015064
    if (ctx->r1 != 0) {
        // 0x80015038: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80015064;
    }
    // 0x80015038: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8001503C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80015040: nop

    // 0x80015044: lwc1        $f10, 0x34($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80015048: lwc1        $f16, 0xC($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8001504C: nop

    // 0x80015050: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80015054: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x80015058: nop

    // 0x8001505C: bc1t        L_8001502C
    if (c1cs) {
        // 0x80015060: nop
    
            goto L_8001502C;
    }
    // 0x80015060: nop

L_80015064:
    // 0x80015064: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80015068:
    // 0x80015068: beq         $at, $zero, L_8001509C
    if (ctx->r1 == 0) {
        // 0x8001506C: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_8001509C;
    }
    // 0x8001506C: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80015070: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80015074: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80015078: addu        $t4, $a2, $t0
    ctx->r12 = ADD32(ctx->r6, ctx->r8);
    // 0x8001507C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80015080: addu        $a3, $a2, $t3
    ctx->r7 = ADD32(ctx->r6, ctx->r11);
    // 0x80015084: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80015088: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x8001508C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80015090: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80015094: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x80015098: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
L_8001509C:
    // 0x8001509C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800150A0: beq         $at, $zero, L_80014F78
    if (ctx->r1 == 0) {
        // 0x800150A4: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80014F78;
    }
    // 0x800150A4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800150A8: jr          $ra
    // 0x800150AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800150AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800150B0:
    // 0x800150B0: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800150B4: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x800150B8: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x800150B8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800150BC: addiu       $t2, $t2, -0x4C28
    ctx->r10 = ADD32(ctx->r10, -0X4C28);
    // 0x800150C0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_800150C4:
    // 0x800150C4: bne         $at, $zero, L_8001513C
    if (ctx->r1 != 0) {
        // 0x800150C8: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001513C;
    }
    // 0x800150C8: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800150CC: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800150D0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800150D4: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x800150D8: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x800150DC: nop

    // 0x800150E0: lwc1        $f4, 0x34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800150E4: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800150E8: nop

    // 0x800150EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800150F0: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x800150F4: nop

    // 0x800150F8: bc1f        L_8001513C
    if (!c1cs) {
        // 0x800150FC: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001513C;
    }
    // 0x800150FC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80015100:
    // 0x80015100: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80015104: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015108: bne         $at, $zero, L_80015138
    if (ctx->r1 != 0) {
        // 0x8001510C: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80015138;
    }
    // 0x8001510C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80015110: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80015114: nop

    // 0x80015118: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x8001511C: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80015120: nop

    // 0x80015124: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80015128: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x8001512C: nop

    // 0x80015130: bc1t        L_80015100
    if (c1cs) {
        // 0x80015134: nop
    
            goto L_80015100;
    }
    // 0x80015134: nop

L_80015138:
    // 0x80015138: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_8001513C:
    // 0x8001513C: bne         $at, $zero, L_800151B0
    if (ctx->r1 != 0) {
        // 0x80015140: sll         $t5, $a0, 2
        ctx->r13 = S32(ctx->r4 << 2);
            goto L_800151B0;
    }
    // 0x80015140: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80015144: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80015148: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x8001514C: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x80015150: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80015154: nop

    // 0x80015158: lwc1        $f4, 0x34($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X34);
    // 0x8001515C: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80015160: nop

    // 0x80015164: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80015168: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x8001516C: nop

    // 0x80015170: bc1f        L_800151B4
    if (!c1cs) {
        // 0x80015174: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800151B4;
    }
    // 0x80015174: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80015178:
    // 0x80015178: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001517C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015180: bne         $at, $zero, L_800151B0
    if (ctx->r1 != 0) {
        // 0x80015184: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_800151B0;
    }
    // 0x80015184: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80015188: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8001518C: nop

    // 0x80015190: lwc1        $f10, 0x34($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80015194: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80015198: nop

    // 0x8001519C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800151A0: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x800151A4: nop

    // 0x800151A8: bc1t        L_80015178
    if (c1cs) {
        // 0x800151AC: nop
    
            goto L_80015178;
    }
    // 0x800151AC: nop

L_800151B0:
    // 0x800151B0: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_800151B4:
    // 0x800151B4: beq         $at, $zero, L_800151E8
    if (ctx->r1 == 0) {
        // 0x800151B8: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_800151E8;
    }
    // 0x800151B8: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x800151BC: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800151C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800151C4: addu        $t6, $a2, $t0
    ctx->r14 = ADD32(ctx->r6, ctx->r8);
    // 0x800151C8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800151CC: addu        $a3, $a2, $t5
    ctx->r7 = ADD32(ctx->r6, ctx->r13);
    // 0x800151D0: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x800151D4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800151D8: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800151DC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800151E0: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800151E4: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
L_800151E8:
    // 0x800151E8: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800151EC: beq         $at, $zero, L_800150C4
    if (ctx->r1 == 0) {
        // 0x800151F0: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800150C4;
    }
    // 0x800151F0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800151F4: jr          $ra
    // 0x800151F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800151F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800151FC:
    // 0x800151FC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015200: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x80015204: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x80015204: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80015208: addiu       $t2, $t2, -0x4C28
    ctx->r10 = ADD32(ctx->r10, -0X4C28);
    // 0x8001520C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80015210:
    // 0x80015210: bne         $at, $zero, L_80015288
    if (ctx->r1 != 0) {
        // 0x80015214: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80015288;
    }
    // 0x80015214: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015218: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8001521C: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x80015220: addu        $a3, $t3, $t4
    ctx->r7 = ADD32(ctx->r11, ctx->r12);
    // 0x80015224: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80015228: nop

    // 0x8001522C: lwc1        $f4, 0x34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80015230: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80015234: nop

    // 0x80015238: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001523C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80015240: nop

    // 0x80015244: bc1f        L_80015288
    if (!c1cs) {
        // 0x80015248: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80015288;
    }
    // 0x80015248: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_8001524C:
    // 0x8001524C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80015250: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015254: bne         $at, $zero, L_80015284
    if (ctx->r1 != 0) {
        // 0x80015258: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80015284;
    }
    // 0x80015258: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8001525C: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80015260: nop

    // 0x80015264: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80015268: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8001526C: nop

    // 0x80015270: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80015274: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80015278: nop

    // 0x8001527C: bc1t        L_8001524C
    if (c1cs) {
        // 0x80015280: nop
    
            goto L_8001524C;
    }
    // 0x80015280: nop

L_80015284:
    // 0x80015284: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80015288:
    // 0x80015288: bne         $at, $zero, L_800152FC
    if (ctx->r1 != 0) {
        // 0x8001528C: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_800152FC;
    }
    // 0x8001528C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80015290: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80015294: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80015298: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x8001529C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800152A0: nop

    // 0x800152A4: lwc1        $f4, 0x34($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X34);
    // 0x800152A8: lwc1        $f6, 0x14($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800152AC: nop

    // 0x800152B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800152B4: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x800152B8: nop

    // 0x800152BC: bc1f        L_80015300
    if (!c1cs) {
        // 0x800152C0: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80015300;
    }
    // 0x800152C0: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_800152C4:
    // 0x800152C4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800152C8: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800152CC: bne         $at, $zero, L_800152FC
    if (ctx->r1 != 0) {
        // 0x800152D0: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_800152FC;
    }
    // 0x800152D0: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800152D4: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800152D8: nop

    // 0x800152DC: lwc1        $f10, 0x34($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X34);
    // 0x800152E0: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800152E4: nop

    // 0x800152E8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800152EC: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x800152F0: nop

    // 0x800152F4: bc1t        L_800152C4
    if (c1cs) {
        // 0x800152F8: nop
    
            goto L_800152C4;
    }
    // 0x800152F8: nop

L_800152FC:
    // 0x800152FC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80015300:
    // 0x80015300: beq         $at, $zero, L_80015334
    if (ctx->r1 == 0) {
        // 0x80015304: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_80015334;
    }
    // 0x80015304: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80015308: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x8001530C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80015310: addu        $t8, $a2, $t0
    ctx->r24 = ADD32(ctx->r6, ctx->r8);
    // 0x80015314: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80015318: addu        $a3, $a2, $t7
    ctx->r7 = ADD32(ctx->r6, ctx->r15);
    // 0x8001531C: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80015320: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80015324: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80015328: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001532C: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x80015330: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
L_80015334:
    // 0x80015334: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015338: beq         $at, $zero, L_80015210
    if (ctx->r1 == 0) {
        // 0x8001533C: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80015210;
    }
    // 0x8001533C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80015340:
    // 0x80015340: jr          $ra
    // 0x80015344: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80015344: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void fb_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A970: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007A974: lw          $v1, 0x6868($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6868);
    // 0x8007A978: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007A97C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8007A980: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8007A984: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007A988: lw          $t8, 0x6858($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6858);
    // 0x8007A98C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8007A990: lw          $t7, 0x6850($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6850);
    // 0x8007A994: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8007A998: jr          $ra
    // 0x8007A99C: or          $v0, $t7, $t9
    ctx->r2 = ctx->r15 | ctx->r25;
    return;
    // 0x8007A99C: or          $v0, $t7, $t9
    ctx->r2 = ctx->r15 | ctx->r25;
;}
RECOMP_FUNC void obj_loop_bridge_whaleramp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CAA8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8003CAAC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003CAB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003CAB4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003CAB8: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8003CABC: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8003CAC0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003CAC4: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8003CAC8: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8003CACC: lw          $t0, 0x3C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X3C);
    // 0x8003CAD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003CAD4: bne         $t7, $zero, L_8003CAF4
    if (ctx->r15 != 0) {
        // 0x8003CAD8: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_8003CAF4;
    }
    // 0x8003CAD8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8003CADC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003CAE0: lwc1        $f9, 0x6708($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6708);
    // 0x8003CAE4: lwc1        $f8, 0x670C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X670C);
    // 0x8003CAE8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8003CAEC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003CAF0: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_8003CAF4:
    // 0x8003CAF4: lbu         $t8, 0xB($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XB);
    // 0x8003CAF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003CAFC: beq         $t8, $at, L_8003CC2C
    if (ctx->r24 == ctx->r1) {
        // 0x8003CB00: nop
    
            goto L_8003CC2C;
    }
    // 0x8003CB00: nop

    // 0x8003CB04: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
    // 0x8003CB08: nop

    // 0x8003CB0C: beq         $t9, $zero, L_8003CBB4
    if (ctx->r25 == 0) {
        // 0x8003CB10: nop
    
            goto L_8003CBB4;
    }
    // 0x8003CB10: nop

    // 0x8003CB14: lb          $t1, 0xE($t0)
    ctx->r9 = MEM_B(ctx->r8, 0XE);
    // 0x8003CB18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003CB1C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8003CB20: nop

    // 0x8003CB24: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003CB28: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8003CB2C: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x8003CB30: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x8003CB34: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8003CB38: nop

    // 0x8003CB3C: bc1f        L_8003CB7C
    if (!c1cs) {
        // 0x8003CB40: nop
    
            goto L_8003CB7C;
    }
    // 0x8003CB40: nop

    // 0x8003CB44: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8003CB48: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003CB4C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8003CB50: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003CB54: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8003CB58: nop

    // 0x8003CB5C: bc1f        L_8003CD60
    if (!c1cs) {
        // 0x8003CB60: nop
    
            goto L_8003CD60;
    }
    // 0x8003CB60: nop

    // 0x8003CB64: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003CB68: nop

    // 0x8003CB6C: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8003CB70: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8003CB74: b           L_8003CD60
    // 0x8003CB78: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
        goto L_8003CD60;
    // 0x8003CB78: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_8003CB7C:
    // 0x8003CB7C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8003CB80: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003CB84: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8003CB88: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003CB8C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8003CB90: nop

    // 0x8003CB94: bc1f        L_8003CD60
    if (!c1cs) {
        // 0x8003CB98: nop
    
            goto L_8003CD60;
    }
    // 0x8003CB98: nop

    // 0x8003CB9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003CBA0: nop

    // 0x8003CBA4: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8003CBA8: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8003CBAC: b           L_8003CD60
    // 0x8003CBB0: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
        goto L_8003CD60;
    // 0x8003CBB0: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
L_8003CBB4:
    // 0x8003CBB4: lbu         $t2, 0xC($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0XC);
    // 0x8003CBB8: nop

    // 0x8003CBBC: blez        $t2, L_8003CBF8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8003CBC0: nop
    
            goto L_8003CBF8;
    }
    // 0x8003CBC0: nop

    // 0x8003CBC4: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003CBC8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8003CBCC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003CBD0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8003CBD4: nop

    // 0x8003CBD8: bc1f        L_8003CD60
    if (!c1cs) {
        // 0x8003CBDC: nop
    
            goto L_8003CD60;
    }
    // 0x8003CBDC: nop

    // 0x8003CBE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003CBE4: nop

    // 0x8003CBE8: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8003CBEC: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8003CBF0: b           L_8003CD60
    // 0x8003CBF4: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
        goto L_8003CD60;
    // 0x8003CBF4: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
L_8003CBF8:
    // 0x8003CBF8: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003CBFC: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8003CC00: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003CC04: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8003CC08: nop

    // 0x8003CC0C: bc1f        L_8003CD60
    if (!c1cs) {
        // 0x8003CC10: nop
    
            goto L_8003CD60;
    }
    // 0x8003CC10: nop

    // 0x8003CC14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003CC18: nop

    // 0x8003CC1C: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8003CC20: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8003CC24: b           L_8003CD60
    // 0x8003CC28: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
        goto L_8003CD60;
    // 0x8003CC28: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
L_8003CC2C:
    // 0x8003CC2C: lw          $t3, 0x78($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X78);
    // 0x8003CC30: nop

    // 0x8003CC34: beq         $t3, $zero, L_8003CCC4
    if (ctx->r11 == 0) {
        // 0x8003CC38: nop
    
            goto L_8003CCC4;
    }
    // 0x8003CC38: nop

    // 0x8003CC3C: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x8003CC40: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8003CC44: slti        $at, $v0, -0x12FF
    ctx->r1 = SIGNED(ctx->r2) < -0X12FF ? 1 : 0;
    // 0x8003CC48: bne         $at, $zero, L_8003CC6C
    if (ctx->r1 != 0) {
        // 0x8003CC4C: sll         $t5, $t4, 2
        ctx->r13 = S32(ctx->r12 << 2);
            goto L_8003CC6C;
    }
    // 0x8003CC4C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8003CC50: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8003CC54: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8003CC58: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8003CC5C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8003CC60: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8003CC64: subu        $t6, $v0, $t5
    ctx->r14 = SUB32(ctx->r2, ctx->r13);
    // 0x8003CC68: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
L_8003CC6C:
    // 0x8003CC6C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8003CC70: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8003CC74: bne         $t7, $zero, L_8003CD60
    if (ctx->r15 != 0) {
        // 0x8003CC78: addiu       $a2, $sp, 0x4C
        ctx->r6 = ADD32(ctx->r29, 0X4C);
            goto L_8003CD60;
    }
    // 0x8003CC78: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x8003CC7C: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
    // 0x8003CC80: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8003CC84: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x8003CC88: jal         0x8001E3A0
    // 0x8003CC8C: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    obj_bridge_pos(rdram, ctx);
        goto after_0;
    // 0x8003CC8C: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    after_0:
    // 0x8003CC90: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x8003CC94: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8003CC98: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8003CC9C: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8003CCA0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003CCA4: addiu       $t9, $v1, 0x4
    ctx->r25 = ADD32(ctx->r3, 0X4);
    // 0x8003CCA8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8003CCAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003CCB0: jal         0x80009558
    // 0x8003CCB4: addiu       $a0, $zero, 0x249
    ctx->r4 = ADD32(0, 0X249);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_1;
    // 0x8003CCB4: addiu       $a0, $zero, 0x249
    ctx->r4 = ADD32(0, 0X249);
    after_1:
    // 0x8003CCB8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003CCBC: b           L_8003CD64
    // 0x8003CCC0: lbu         $v1, 0xB($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB);
        goto L_8003CD64;
    // 0x8003CCC0: lbu         $v1, 0xB($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB);
L_8003CCC4:
    // 0x8003CCC4: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x8003CCC8: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x8003CCCC: bgez        $v0, L_8003CD3C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003CCD0: sll         $t2, $t1, 2
        ctx->r10 = S32(ctx->r9 << 2);
            goto L_8003CD3C;
    }
    // 0x8003CCD0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8003CCD4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8003CCD8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8003CCDC: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8003CCE0: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x8003CCE4: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x8003CCE8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8003CCEC: bne         $t4, $zero, L_8003CD60
    if (ctx->r12 != 0) {
        // 0x8003CCF0: addiu       $a2, $sp, 0x40
        ctx->r6 = ADD32(ctx->r29, 0X40);
            goto L_8003CD60;
    }
    // 0x8003CCF0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8003CCF4: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
    // 0x8003CCF8: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8003CCFC: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x8003CD00: jal         0x8001E3A0
    // 0x8003CD04: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    obj_bridge_pos(rdram, ctx);
        goto after_2;
    // 0x8003CD04: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x8003CD08: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x8003CD0C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8003CD10: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8003CD14: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8003CD18: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003CD1C: addiu       $t6, $v1, 0x4
    ctx->r14 = ADD32(ctx->r3, 0X4);
    // 0x8003CD20: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8003CD24: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003CD28: jal         0x80009558
    // 0x8003CD2C: addiu       $a0, $zero, 0x249
    ctx->r4 = ADD32(0, 0X249);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_3;
    // 0x8003CD2C: addiu       $a0, $zero, 0x249
    ctx->r4 = ADD32(0, 0X249);
    after_3:
    // 0x8003CD30: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003CD34: b           L_8003CD64
    // 0x8003CD38: lbu         $v1, 0xB($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB);
        goto L_8003CD64;
    // 0x8003CD38: lbu         $v1, 0xB($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB);
L_8003CD3C:
    // 0x8003CD3C: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8003CD40: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8003CD44: nop

    // 0x8003CD48: beq         $a0, $zero, L_8003CD60
    if (ctx->r4 == 0) {
        // 0x8003CD4C: nop
    
            goto L_8003CD60;
    }
    // 0x8003CD4C: nop

    // 0x8003CD50: jal         0x800096F8
    // 0x8003CD54: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    audspat_point_stop(rdram, ctx);
        goto after_4;
    // 0x8003CD54: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_4:
    // 0x8003CD58: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003CD5C: nop

L_8003CD60:
    // 0x8003CD60: lbu         $v1, 0xB($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB);
L_8003CD64:
    // 0x8003CD64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003CD68: beq         $v1, $zero, L_8003CD80
    if (ctx->r3 == 0) {
        // 0x8003CD6C: nop
    
            goto L_8003CD80;
    }
    // 0x8003CD6C: nop

    // 0x8003CD70: beq         $v1, $at, L_8003CDAC
    if (ctx->r3 == ctx->r1) {
        // 0x8003CD74: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8003CDAC;
    }
    // 0x8003CD74: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003CD78: b           L_8003CE20
    // 0x8003CD7C: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
        goto L_8003CE20;
    // 0x8003CD7C: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
L_8003CD80:
    // 0x8003CD80: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CD84: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x8003CD88: lbu         $t8, 0xC($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XC);
    // 0x8003CD8C: lbu         $t7, 0x13($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X13);
    // 0x8003CD90: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003CD94: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003CD98: beq         $at, $zero, L_8003CE6C
    if (ctx->r1 == 0) {
        // 0x8003CD9C: addiu       $t8, $zero, 0xFF
        ctx->r24 = ADD32(0, 0XFF);
            goto L_8003CE6C;
    }
    // 0x8003CD9C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8003CDA0: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CDA4: b           L_8003CE68
    // 0x8003CDA8: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
        goto L_8003CE68;
    // 0x8003CDA8: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
L_8003CDAC:
    // 0x8003CDAC: sw          $t1, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r9;
    // 0x8003CDB0: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8003CDB4: jal         0x8001BAFC
    // 0x8003CDB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_5;
    // 0x8003CDB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x8003CDBC: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003CDC0: beq         $v0, $zero, L_8003CE10
    if (ctx->r2 == 0) {
        // 0x8003CDC4: nop
    
            goto L_8003CE10;
    }
    // 0x8003CDC4: nop

    // 0x8003CDC8: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    // 0x8003CDCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003CDD0: lb          $v1, 0x1D6($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X1D6);
    // 0x8003CDD4: nop

    // 0x8003CDD8: beq         $v1, $at, L_8003CDF0
    if (ctx->r3 == ctx->r1) {
        // 0x8003CDDC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003CDF0;
    }
    // 0x8003CDDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003CDE0: beq         $v1, $at, L_8003CDF8
    if (ctx->r3 == ctx->r1) {
        // 0x8003CDE4: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8003CDF8;
    }
    // 0x8003CDE4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8003CDE8: b           L_8003CDF8
    // 0x8003CDEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003CDF8;
    // 0x8003CDEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003CDF0:
    // 0x8003CDF0: b           L_8003CDF8
    // 0x8003CDF4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8003CDF8;
    // 0x8003CDF4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8003CDF8:
    // 0x8003CDF8: lbu         $t2, 0xF($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0XF);
    // 0x8003CDFC: nop

    // 0x8003CE00: and         $t3, $t2, $v0
    ctx->r11 = ctx->r10 & ctx->r2;
    // 0x8003CE04: beq         $t3, $zero, L_8003CE10
    if (ctx->r11 == 0) {
        // 0x8003CE08: nop
    
            goto L_8003CE10;
    }
    // 0x8003CE08: nop

    // 0x8003CE0C: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003CE10:
    // 0x8003CE10: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CE14: b           L_8003CE6C
    // 0x8003CE18: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
        goto L_8003CE6C;
    // 0x8003CE18: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8003CE1C: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
L_8003CE20:
    // 0x8003CE20: jal         0x8001E320
    // 0x8003CE24: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    is_bridge_raised(rdram, ctx);
        goto after_6;
    // 0x8003CE24: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_6:
    // 0x8003CE28: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003CE2C: beq         $v0, $zero, L_8003CE44
    if (ctx->r2 == 0) {
        // 0x8003CE30: nop
    
            goto L_8003CE44;
    }
    // 0x8003CE30: nop

    // 0x8003CE34: lbu         $t4, 0xD($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XD);
    // 0x8003CE38: nop

    // 0x8003CE3C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8003CE40: sw          $t5, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r13;
L_8003CE44:
    // 0x8003CE44: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x8003CE48: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8003CE4C: blez        $v0, L_8003CE5C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003CE50: subu        $t7, $v0, $t6
        ctx->r15 = SUB32(ctx->r2, ctx->r14);
            goto L_8003CE5C;
    }
    // 0x8003CE50: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8003CE54: b           L_8003CE60
    // 0x8003CE58: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
        goto L_8003CE60;
    // 0x8003CE58: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
L_8003CE5C:
    // 0x8003CE5C: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003CE60:
    // 0x8003CE60: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CE64: nop

L_8003CE68:
    // 0x8003CE68: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
L_8003CE6C:
    // 0x8003CE6C: sb          $t8, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r24;
    // 0x8003CE70: lw          $t9, 0x4C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CE74: nop

    // 0x8003CE78: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8003CE7C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CE80: nop

    // 0x8003CE84: lh          $t1, 0x14($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X14);
    // 0x8003CE88: nop

    // 0x8003CE8C: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x8003CE90: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
    // 0x8003CE94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003CE98: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003CE9C: jr          $ra
    // 0x8003CEA0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8003CEA0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void timetrial_staff_unbeaten(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B684: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001B688: lbu         $v0, -0x3358($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3358);
    // 0x8001B68C: nop

    // 0x8001B690: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8001B694: jr          $ra
    // 0x8001B698: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x8001B698: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
