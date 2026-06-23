#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8002E904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E944: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x8002E948: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002E94C: lw          $v0, -0x29BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X29BC);
    // 0x8002E950: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002E954: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8002E958: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8002E95C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002E960: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8002E964: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002E968: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8002E96C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8002E970: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002E974: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002E978: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002E97C: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x8002E980: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002E984: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8002E988: sw          $a1, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r5;
    // 0x8002E98C: sw          $a2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r6;
    // 0x8002E990: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E994: lwc1        $f0, -0x29A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X29A4);
    // 0x8002E998: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002E99C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E9A0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002E9A4: lwc1        $f2, -0x29A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X29A0);
    // 0x8002E9A8: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
    // 0x8002E9AC: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002E9B0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002E9B4: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8002E9B8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002E9BC: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
    // 0x8002E9C0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002E9C4: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8002E9C8: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8002E9CC: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8002E9D0: swc1        $f18, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f18.u32l;
    // 0x8002E9D4: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002E9D8: addiu       $s6, $s6, -0x4960
    ctx->r22 = ADD32(ctx->r22, -0X4960);
    // 0x8002E9DC: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8002E9E0: addiu       $s4, $s4, -0x29C4
    ctx->r20 = ADD32(ctx->r20, -0X29C4);
    // 0x8002E9E4: swc1        $f6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f6.u32l;
    // 0x8002E9E8: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002E9EC: addiu       $s3, $s3, -0x4968
    ctx->r19 = ADD32(ctx->r19, -0X4968);
    // 0x8002E9F0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8002E9F4: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8002E9F8: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    // 0x8002E9FC: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EA00: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x8002EA04: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8002EA08: addiu       $s5, $sp, 0x100
    ctx->r21 = ADD32(ctx->r29, 0X100);
    // 0x8002EA0C: swc1        $f18, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f18.u32l;
    // 0x8002EA10: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002EA14: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8002EA18: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002EA1C: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
    // 0x8002EA20: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EA24: nop

    // 0x8002EA28: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8002EA2C: swc1        $f10, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f10.u32l;
    // 0x8002EA30: lh          $a3, 0x20($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X20);
    // 0x8002EA34: nop

    // 0x8002EA38: blez        $a3, L_8002EEF0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8002EA3C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8002EEF0;
    }
    // 0x8002EA3C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8002EA40: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8002EA44: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8002EA48: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8002EA4C: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
L_8002EA50:
    // 0x8002EA50: nop

    // 0x8002EA54: beq         $t6, $zero, L_8002EA84
    if (ctx->r14 == 0) {
        // 0x8002EA58: lw          $t6, 0x158($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X158);
            goto L_8002EA84;
    }
    // 0x8002EA58: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
    // 0x8002EA5C: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EA60: lw          $t7, 0xC($fp)
    ctx->r15 = MEM_W(ctx->r30, 0XC);
    // 0x8002EA64: mflo        $t8
    ctx->r24 = lo;
    // 0x8002EA68: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002EA6C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8002EA70: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
    // 0x8002EA74: andi        $t9, $v1, 0x2000
    ctx->r25 = ctx->r3 & 0X2000;
    // 0x8002EA78: bne         $t9, $zero, L_8002EAB8
    if (ctx->r25 != 0) {
        // 0x8002EA7C: nop
    
            goto L_8002EAB8;
    }
    // 0x8002EA7C: nop

    // 0x8002EA80: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
L_8002EA84:
    // 0x8002EA84: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
    // 0x8002EA88: bne         $t6, $zero, L_8002EED4
    if (ctx->r14 != 0) {
        // 0x8002EA8C: nop
    
            goto L_8002EED4;
    }
    // 0x8002EA8C: nop

    // 0x8002EA90: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EA94: lw          $t7, 0xC($fp)
    ctx->r15 = MEM_W(ctx->r30, 0XC);
    // 0x8002EA98: mflo        $t8
    ctx->r24 = lo;
    // 0x8002EA9C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002EAA0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8002EAA4: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
    // 0x8002EAA8: andi        $t9, $v1, 0x6900
    ctx->r25 = ctx->r3 & 0X6900;
    // 0x8002EAAC: bne         $t9, $zero, L_8002EED4
    if (ctx->r25 != 0) {
        // 0x8002EAB0: nop
    
            goto L_8002EED4;
    }
    // 0x8002EAB0: nop

    // 0x8002EAB4: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
L_8002EAB8:
    // 0x8002EAB8: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x8002EABC: lh          $s7, 0x4($v0)
    ctx->r23 = MEM_H(ctx->r2, 0X4);
    // 0x8002EAC0: lh          $a0, 0x10($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X10);
    // 0x8002EAC4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002EAC8: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8002EACC: srl         $t5, $v1, 19
    ctx->r13 = S32(U32(ctx->r3) >> 19);
    // 0x8002EAD0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8002EAD4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8002EAD8: andi        $t9, $t5, 0x7
    ctx->r25 = ctx->r13 & 0X7;
    // 0x8002EADC: slt         $at, $s7, $a0
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002EAE0: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x8002EAE4: beq         $at, $zero, L_8002EED4
    if (ctx->r1 == 0) {
        // 0x8002EAE8: addu        $s1, $t7, $t8
        ctx->r17 = ADD32(ctx->r15, ctx->r24);
            goto L_8002EED4;
    }
    // 0x8002EAE8: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x8002EAEC: sll         $ra, $s7, 1
    ctx->r31 = S32(ctx->r23 << 1);
    // 0x8002EAF0: sw          $a0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r4;
L_8002EAF4:
    // 0x8002EAF4: lw          $t6, 0x10($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X10);
    // 0x8002EAF8: lw          $t9, 0x154($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X154);
    // 0x8002EAFC: addu        $t7, $t6, $ra
    ctx->r15 = ADD32(ctx->r14, ctx->r31);
    // 0x8002EB00: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8002EB04: nop

    // 0x8002EB08: and         $v0, $t8, $t9
    ctx->r2 = ctx->r24 & ctx->r25;
    // 0x8002EB0C: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x8002EB10: beq         $t6, $zero, L_8002EEB8
    if (ctx->r14 == 0) {
        // 0x8002EB14: andi        $t7, $v0, 0xFF00
        ctx->r15 = ctx->r2 & 0XFF00;
            goto L_8002EEB8;
    }
    // 0x8002EB14: andi        $t7, $v0, 0xFF00
    ctx->r15 = ctx->r2 & 0XFF00;
    // 0x8002EB18: beq         $t7, $zero, L_8002EEBC
    if (ctx->r15 == 0) {
        // 0x8002EB1C: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_8002EEBC;
    }
    // 0x8002EB1C: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8002EB20: lw          $t8, 0x4($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X4);
    // 0x8002EB24: sll         $t9, $s7, 4
    ctx->r25 = S32(ctx->r23 << 4);
    // 0x8002EB28: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x8002EB2C: lbu         $t6, 0x1($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X1);
    // 0x8002EB30: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002EB34: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EB38: lh          $t0, -0x29B2($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X29B2);
    // 0x8002EB3C: addiu       $v1, $a3, 0x1
    ctx->r3 = ADD32(ctx->r7, 0X1);
    // 0x8002EB40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002EB44: mflo        $t7
    ctx->r15 = lo;
    // 0x8002EB48: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x8002EB4C: lh          $a1, 0x2($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X2);
    // 0x8002EB50: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002EB54: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_8002EB58:
    // 0x8002EB58: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x8002EB5C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002EB60: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EB64: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EB68: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8002EB6C: lh          $v0, 0x2($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X2);
    // 0x8002EB70: nop

    // 0x8002EB74: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002EB78: beq         $at, $zero, L_8002EB8C
    if (ctx->r1 == 0) {
        // 0x8002EB7C: slt         $at, $a2, $v0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8002EB8C;
    }
    // 0x8002EB7C: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002EB80: b           L_8002EB98
    // 0x8002EB84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8002EB98;
    // 0x8002EB84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002EB88: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
L_8002EB8C:
    // 0x8002EB8C: beq         $at, $zero, L_8002EB9C
    if (ctx->r1 == 0) {
        // 0x8002EB90: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_8002EB9C;
    }
    // 0x8002EB90: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8002EB94: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8002EB98:
    // 0x8002EB98: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
L_8002EB9C:
    // 0x8002EB9C: bne         $at, $zero, L_8002EB58
    if (ctx->r1 != 0) {
        // 0x8002EBA0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8002EB58;
    }
    // 0x8002EBA0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002EBA4: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002EBA8: bne         $at, $zero, L_8002EEBC
    if (ctx->r1 != 0) {
        // 0x8002EBAC: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_8002EEBC;
    }
    // 0x8002EBAC: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8002EBB0: lh          $t8, -0x29B4($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X29B4);
    // 0x8002EBB4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8002EBB8: slt         $at, $a2, $t8
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002EBBC: bne         $at, $zero, L_8002EEB8
    if (ctx->r1 != 0) {
        // 0x8002EBC0: addiu       $v0, $sp, 0xD0
        ctx->r2 = ADD32(ctx->r29, 0XD0);
            goto L_8002EEB8;
    }
    // 0x8002EBC0: addiu       $v0, $sp, 0xD0
    ctx->r2 = ADD32(ctx->r29, 0XD0);
    // 0x8002EBC4: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x8002EBC8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002EBCC: beq         $v0, $s5, L_8002EC2C
    if (ctx->r2 == ctx->r21) {
        // 0x8002EBD0: multu       $t9, $s2
        result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
            goto L_8002EC2C;
    }
    // 0x8002EBD0: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8002EBD4:
    // 0x8002EBD4: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EBD8: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8002EBDC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8002EBE0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002EBE4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8002EBE8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002EBEC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002EBF0: swc1        $f18, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = ctx->f18.u32l;
    // 0x8002EBF4: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8002EBF8: nop

    // 0x8002EBFC: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EC00: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EC04: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8002EC08: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x8002EC0C: sh          $s0, -0x12($v0)
    MEM_H(-0X12, ctx->r2) = ctx->r16;
    // 0x8002EC10: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8002EC14: nop

    // 0x8002EC18: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002EC1C: swc1        $f18, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = ctx->f18.u32l;
    // 0x8002EC20: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x8002EC24: bne         $v0, $s5, L_8002EBD4
    if (ctx->r2 != ctx->r21) {
        // 0x8002EC28: multu       $t9, $s2
        result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
            goto L_8002EBD4;
    }
    // 0x8002EC28: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8002EC2C:
    // 0x8002EC2C: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EC30: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8002EC34: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8002EC38: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002EC3C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8002EC40: nop

    // 0x8002EC44: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002EC48: swc1        $f18, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f18.u32l;
    // 0x8002EC4C: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8002EC50: nop

    // 0x8002EC54: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EC58: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EC5C: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8002EC60: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x8002EC64: sh          $s0, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r16;
    // 0x8002EC68: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8002EC6C: nop

    // 0x8002EC70: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002EC74: swc1        $f18, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f18.u32l;
    // 0x8002EC78: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8002EC7C: lwc1        $f14, 0xC4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8002EC80: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    // 0x8002EC84: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8002EC88: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8002EC8C: addiu       $t6, $sp, 0xD0
    ctx->r14 = ADD32(ctx->r29, 0XD0);
    // 0x8002EC90: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8002EC94: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8002EC98: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002EC9C: jal         0x8002FDB4
    // 0x8002ECA0: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    func_8002FD74(rdram, ctx);
        goto after_0;
    // 0x8002ECA0: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    after_0:
    // 0x8002ECA4: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8002ECA8: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8002ECAC: beq         $v0, $zero, L_8002EEBC
    if (ctx->r2 == 0) {
        // 0x8002ECB0: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_8002EEBC;
    }
    // 0x8002ECB0: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8002ECB4: lw          $t7, 0x14($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X14);
    // 0x8002ECB8: sll         $t8, $s7, 3
    ctx->r24 = S32(ctx->r23 << 3);
    // 0x8002ECBC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8002ECC0: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
    // 0x8002ECC4: lw          $t7, 0x18($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X18);
    // 0x8002ECC8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8002ECCC: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8002ECD0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8002ECD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8002ECD8: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x8002ECDC: lw          $t6, 0x18($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X18);
    // 0x8002ECE0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8002ECE4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8002ECE8: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8002ECEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002ECF0: c.eq.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl == ctx->f8.fl;
    // 0x8002ECF4: nop

    // 0x8002ECF8: bc1t        L_8002EEBC
    if (c1cs) {
        // 0x8002ECFC: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_8002EEBC;
    }
    // 0x8002ECFC: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8002ED00: lwc1        $f10, -0x2990($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2990);
    // 0x8002ED04: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x8002ED08: c.lt.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl < ctx->f10.fl;
    // 0x8002ED0C: nop

    // 0x8002ED10: bc1f        L_8002ED30
    if (!c1cs) {
        // 0x8002ED14: nop
    
            goto L_8002ED30;
    }
    // 0x8002ED14: nop

    // 0x8002ED18: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8002ED1C: jal         0x80030508
    // 0x8002ED20: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    func_800304C8(rdram, ctx);
        goto after_1;
    // 0x8002ED20: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    after_1:
    // 0x8002ED24: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8002ED28: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8002ED2C: nop

L_8002ED30:
    // 0x8002ED30: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8002ED34: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002ED38: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    // 0x8002ED3C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8002ED40: addiu       $a3, $sp, 0xB0
    ctx->r7 = ADD32(ctx->r29, 0XB0);
    // 0x8002ED44: jal         0x8002FFAC
    // 0x8002ED48: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    func_8002FF6C(rdram, ctx);
        goto after_2;
    // 0x8002ED48: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    after_2:
    // 0x8002ED4C: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8002ED50: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8002ED54: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8002ED58: bne         $at, $zero, L_8002EEB8
    if (ctx->r1 != 0) {
        // 0x8002ED5C: or          $t4, $v0, $zero
        ctx->r12 = ctx->r2 | 0;
            goto L_8002EEB8;
    }
    // 0x8002ED5C: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x8002ED60: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8002ED64: lw          $t3, -0x3850($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3850);
    // 0x8002ED68: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002ED6C: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x8002ED70: subu        $t9, $t9, $t3
    ctx->r25 = SUB32(ctx->r25, ctx->r11);
    // 0x8002ED74: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002ED78: addiu       $t6, $t6, -0x3848
    ctx->r14 = ADD32(ctx->r14, -0X3848);
    // 0x8002ED7C: addu        $t2, $t9, $t6
    ctx->r10 = ADD32(ctx->r25, ctx->r14);
    // 0x8002ED80: sb          $zero, 0x1($t2)
    MEM_B(0X1, ctx->r10) = 0;
    // 0x8002ED84: blez        $v0, L_8002EE84
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002ED88: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8002EE84;
    }
    // 0x8002ED88: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8002ED8C: addiu       $a3, $sp, 0xD0
    ctx->r7 = ADD32(ctx->r29, 0XD0);
L_8002ED90:
    // 0x8002ED90: lh          $v1, 0xE($a3)
    ctx->r3 = MEM_H(ctx->r7, 0XE);
    // 0x8002ED94: addu        $t6, $t2, $t0
    ctx->r14 = ADD32(ctx->r10, ctx->r8);
    // 0x8002ED98: bgez        $v1, L_8002EE64
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002ED9C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8002EE64;
    }
    // 0x8002ED9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002EDA0: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8002EDA4: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x8002EDA8: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x8002EDAC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002EDB0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002EDB4: addiu       $t9, $t9, -0x3848
    ctx->r25 = ADD32(ctx->r25, -0X3848);
    // 0x8002EDB8: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x8002EDBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002EDC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002EDC4: blez        $a2, L_8002EE28
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8002EDC8: addu        $t1, $t8, $t9
        ctx->r9 = ADD32(ctx->r24, ctx->r25);
            goto L_8002EE28;
    }
    // 0x8002EDC8: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8002EDCC: sll         $t6, $zero, 4
    ctx->r14 = S32(0 << 4);
    // 0x8002EDD0: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002EDD4: addu        $v1, $s6, $t6
    ctx->r3 = ADD32(ctx->r22, ctx->r14);
L_8002EDD8:
    // 0x8002EDD8: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002EDDC: nop

    // 0x8002EDE0: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x8002EDE4: nop

    // 0x8002EDE8: bc1f        L_8002EE10
    if (!c1cs) {
        // 0x8002EDEC: nop
    
            goto L_8002EE10;
    }
    // 0x8002EDEC: nop

    // 0x8002EDF0: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002EDF4: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002EDF8: nop

    // 0x8002EDFC: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8002EE00: nop

    // 0x8002EE04: bc1f        L_8002EE10
    if (!c1cs) {
        // 0x8002EE08: nop
    
            goto L_8002EE10;
    }
    // 0x8002EE08: nop

    // 0x8002EE0C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_8002EE10:
    // 0x8002EE10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002EE14: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002EE18: beq         $at, $zero, L_8002EE28
    if (ctx->r1 == 0) {
        // 0x8002EE1C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8002EE28;
    }
    // 0x8002EE1C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8002EE20: beq         $a1, $s0, L_8002EDD8
    if (ctx->r5 == ctx->r16) {
        // 0x8002EE24: nop
    
            goto L_8002EDD8;
    }
    // 0x8002EE24: nop

L_8002EE28:
    // 0x8002EE28: bne         $a1, $s0, L_8002EE5C
    if (ctx->r5 != ctx->r16) {
        // 0x8002EE2C: sll         $t7, $a2, 4
        ctx->r15 = S32(ctx->r6 << 4);
            goto L_8002EE5C;
    }
    // 0x8002EE2C: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x8002EE30: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002EE34: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8002EE38: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002EE3C: addu        $v1, $s6, $t7
    ctx->r3 = ADD32(ctx->r22, ctx->r15);
    // 0x8002EE40: addiu       $t9, $a2, 0x1
    ctx->r25 = ADD32(ctx->r6, 0X1);
    // 0x8002EE44: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8002EE48: sb          $a2, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r6;
    // 0x8002EE4C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8002EE50: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x8002EE54: b           L_8002EE78
    // 0x8002EE58: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
        goto L_8002EE78;
    // 0x8002EE58: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
L_8002EE5C:
    // 0x8002EE5C: b           L_8002EE78
    // 0x8002EE60: sb          $a1, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r5;
        goto L_8002EE78;
    // 0x8002EE60: sb          $a1, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r5;
L_8002EE64:
    // 0x8002EE64: sb          $v1, 0x2($t6)
    MEM_B(0X2, ctx->r14) = ctx->r3;
    // 0x8002EE68: lbu         $t7, 0x1($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X1);
    // 0x8002EE6C: sllv        $t9, $t8, $t0
    ctx->r25 = S32(ctx->r24 << (ctx->r8 & 31));
    // 0x8002EE70: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8002EE74: sb          $t6, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r14;
L_8002EE78:
    // 0x8002EE78: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8002EE7C: bne         $t0, $t4, L_8002ED90
    if (ctx->r8 != ctx->r12) {
        // 0x8002EE80: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8002ED90;
    }
    // 0x8002EE80: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_8002EE84:
    // 0x8002EE84: sb          $v0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r2;
    // 0x8002EE88: sh          $t5, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r13;
    // 0x8002EE8C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002EE90: lw          $v1, -0x2998($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2998);
    // 0x8002EE94: addiu       $t8, $t3, 0x1
    ctx->r24 = ADD32(ctx->r11, 0X1);
    // 0x8002EE98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002EE9C: bltz        $v1, L_8002EEB0
    if (SIGNED(ctx->r3) < 0) {
        // 0x8002EEA0: sw          $t8, -0x3850($at)
        MEM_W(-0X3850, ctx->r1) = ctx->r24;
            goto L_8002EEB0;
    }
    // 0x8002EEA0: sw          $t8, -0x3850($at)
    MEM_W(-0X3850, ctx->r1) = ctx->r24;
    // 0x8002EEA4: beq         $t5, $v1, L_8002EEB0
    if (ctx->r13 == ctx->r3) {
        // 0x8002EEA8: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8002EEB0;
    }
    // 0x8002EEA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002EEAC: sw          $zero, -0x2994($at)
    MEM_W(-0X2994, ctx->r1) = 0;
L_8002EEB0:
    // 0x8002EEB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002EEB4: sw          $t5, -0x2998($at)
    MEM_W(-0X2998, ctx->r1) = ctx->r13;
L_8002EEB8:
    // 0x8002EEB8: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
L_8002EEBC:
    // 0x8002EEBC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002EEC0: slt         $at, $s7, $t7
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002EEC4: bne         $at, $zero, L_8002EAF4
    if (ctx->r1 != 0) {
        // 0x8002EEC8: addiu       $ra, $ra, 0x2
        ctx->r31 = ADD32(ctx->r31, 0X2);
            goto L_8002EAF4;
    }
    // 0x8002EEC8: addiu       $ra, $ra, 0x2
    ctx->r31 = ADD32(ctx->r31, 0X2);
    // 0x8002EECC: lh          $a3, 0x20($fp)
    ctx->r7 = MEM_H(ctx->r30, 0X20);
    // 0x8002EED0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_8002EED4:
    // 0x8002EED4: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x8002EED8: nop

    // 0x8002EEDC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8002EEE0: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8002EEE4: bne         $at, $zero, L_8002EA50
    if (ctx->r1 != 0) {
        // 0x8002EEE8: lw          $t6, 0x158($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X158);
            goto L_8002EA50;
    }
    // 0x8002EEE8: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
    // 0x8002EEEC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8002EEF0:
    // 0x8002EEF0: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002EEF4: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002EEF8: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002EEFC: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002EF00: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002EF04: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8002EF08: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8002EF0C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8002EF10: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8002EF14: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8002EF18: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8002EF1C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8002EF20: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8002EF24: jr          $ra
    // 0x8002EF28: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x8002EF28: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void move_particle_forward(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3AC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B3AC8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800B3ACC: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800B3AD0: addiu       $s3, $s3, -0x7DC0
    ctx->r19 = ADD32(ctx->r19, -0X7DC0);
    // 0x800B3AD4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800B3AD8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B3ADC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B3AE0: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B3AE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B3AE8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B3AEC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800B3AF0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B3AF4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800B3AF8: beq         $t6, $zero, L_800B3BB4
    if (ctx->r14 == 0) {
        // 0x800B3AFC: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_800B3BB4;
    }
    // 0x800B3AFC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800B3B00: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B3B04: addiu       $s2, $a0, 0x1C
    ctx->r18 = ADD32(ctx->r4, 0X1C);
L_800B3B08:
    // 0x800B3B08: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800B3B0C: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
    // 0x800B3B10: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800B3B14: swc1        $f20, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f20.u32l;
    // 0x800B3B18: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800B3B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3B20: jal         0x800706D0
    // 0x800B3B24: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    vec3f_rotate_py(rdram, ctx);
        goto after_0;
    // 0x800B3B24: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800B3B28: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B3B2C: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B3B30: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B3B34: lwc1        $f4, 0x68($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800B3B38: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B3B3C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B3B40: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800B3B44: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x800B3B48: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B3B4C: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B3B50: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B3B54: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800B3B58: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800B3B5C: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800B3B60: lh          $t8, 0x62($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X62);
    // 0x800B3B64: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x800B3B68: lh          $t1, 0x64($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X64);
    // 0x800B3B6C: lh          $t3, 0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4);
    // 0x800B3B70: lh          $t4, 0x66($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X66);
    // 0x800B3B74: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x800B3B78: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3B7C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B3B80: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B3B84: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B3B88: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800B3B8C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x800B3B90: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x800B3B94: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800B3B98: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x800B3B9C: sh          $t5, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r13;
    // 0x800B3BA0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800B3BA4: nop

    // 0x800B3BA8: slt         $v0, $s1, $t6
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B3BAC: bne         $v0, $zero, L_800B3B08
    if (ctx->r2 != 0) {
        // 0x800B3BB0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800B3B08;
    }
    // 0x800B3BB0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800B3BB4:
    // 0x800B3BB4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3BB8: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800B3BBC: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800B3BC0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3BC4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800B3BC8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800B3BCC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800B3BD0: jr          $ra
    // 0x800B3BD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B3BD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void obj_init_banana(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D574: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D57C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003D580: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003D584: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003D588: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003D58C: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003D590: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8003D594: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003D598: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003D59C: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8003D5A0: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003D5A4: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8003D5A8: sh          $t1, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r9;
    // 0x8003D5AC: sh          $t2, 0x7E($a0)
    MEM_H(0X7E, ctx->r4) = ctx->r10;
    // 0x8003D5B0: jal         0x8009C850
    // 0x8003D5B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x8003D5B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003D5B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003D5BC: andi        $t3, $v0, 0x1000
    ctx->r11 = ctx->r2 & 0X1000;
    // 0x8003D5C0: beq         $t3, $zero, L_8003D5D4
    if (ctx->r11 == 0) {
        // 0x8003D5C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003D5D4;
    }
    // 0x8003D5C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D5C8: jal         0x8000FFB8
    // 0x8003D5CC: nop

    free_object(rdram, ctx);
        goto after_1;
    // 0x8003D5CC: nop

    after_1:
    // 0x8003D5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003D5D4:
    // 0x8003D5D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D5D8: jr          $ra
    // 0x8003D5DC: nop

    return;
    // 0x8003D5DC: nop

;}
RECOMP_FUNC void mempool_alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070F50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070F54: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80070F58: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80070F5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070F60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80070F64: jal         0x80070F7C
    // 0x80070F68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_slot_find(rdram, ctx);
        goto after_0;
    // 0x80070F68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80070F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070F70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070F74: jr          $ra
    // 0x80070F78: nop

    return;
    // 0x80070F78: nop

;}
RECOMP_FUNC void mode_game(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CF30: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8006CF34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006CF38: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006CF3C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8006CF40: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8006CF44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006CF48: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8006CF4C: jal         0x8009C91C
    // 0x8006CF50: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    get_active_player_count(rdram, ctx);
        goto after_0;
    // 0x8006CF50: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_0:
    // 0x8006CF54: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006CF58: nop

    // 0x8006CF5C: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006CF60: beq         $at, $zero, L_8006CFB0
    if (ctx->r1 == 0) {
        // 0x8006CF64: nop
    
            goto L_8006CFB0;
    }
    // 0x8006CF64: nop

    // 0x8006CF68: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
L_8006CF6C:
    // 0x8006CF6C: jal         0x8006A768
    // 0x8006CF70: nop

    input_held(rdram, ctx);
        goto after_1;
    // 0x8006CF70: nop

    after_1:
    // 0x8006CF74: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8006CF78: jal         0x8006A794
    // 0x8006CF7C: or          $s0, $s0, $v0
    ctx->r16 = ctx->r16 | ctx->r2;
    input_pressed(rdram, ctx);
        goto after_2;
    // 0x8006CF7C: or          $s0, $s0, $v0
    ctx->r16 = ctx->r16 | ctx->r2;
    after_2:
    // 0x8006CF80: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8006CF84: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CF88: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8006CF8C: or          $t8, $t7, $v0
    ctx->r24 = ctx->r15 | ctx->r2;
    // 0x8006CF90: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8006CF94: jal         0x8009C91C
    // 0x8006CF98: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    get_active_player_count(rdram, ctx);
        goto after_3;
    // 0x8006CF98: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    after_3:
    // 0x8006CF9C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8006CFA0: nop

    // 0x8006CFA4: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006CFA8: bne         $at, $zero, L_8006CF6C
    if (ctx->r1 != 0) {
        // 0x8006CFAC: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_8006CF6C;
    }
    // 0x8006CFAC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
L_8006CFB0:
    // 0x8006CFB0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8006CFB4: lb          $t3, -0x271C($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X271C);
    // 0x8006CFB8: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CFBC: beq         $t3, $zero, L_8006CFCC
    if (ctx->r11 == 0) {
        // 0x8006CFC0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006CFCC;
    }
    // 0x8006CFC0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006CFC4: ori         $t5, $t4, 0x1000
    ctx->r13 = ctx->r12 | 0X1000;
    // 0x8006CFC8: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
L_8006CFCC:
    // 0x8006CFCC: lb          $t6, 0x3A95($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3A95);
    // 0x8006CFD0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8006CFD4: bne         $t6, $zero, L_8006D0A0
    if (ctx->r14 != 0) {
        // 0x8006CFD8: nop
    
            goto L_8006D0A0;
    }
    // 0x8006CFD8: nop

    // 0x8006CFDC: jal         0x80010994
    // 0x8006CFE0: nop

    obj_update(rdram, ctx);
        goto after_4;
    // 0x8006CFE0: nop

    after_4:
    // 0x8006CFE4: jal         0x80066750
    // 0x8006CFE8: nop

    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_5;
    // 0x8006CFE8: nop

    after_5:
    // 0x8006CFEC: beq         $v0, $zero, L_8006D008
    if (ctx->r2 == 0) {
        // 0x8006CFF0: lw          $t7, 0x4C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X4C);
            goto L_8006D008;
    }
    // 0x8006CFF0: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CFF4: jal         0x8001139C
    // 0x8006CFF8: nop

    get_race_countdown(rdram, ctx);
        goto after_6;
    // 0x8006CFF8: nop

    after_6:
    // 0x8006CFFC: beq         $v0, $zero, L_8006D084
    if (ctx->r2 == 0) {
        // 0x8006D000: nop
    
            goto L_8006D084;
    }
    // 0x8006D000: nop

    // 0x8006D004: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
L_8006D008:
    // 0x8006D008: nop

    // 0x8006D00C: andi        $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 & 0X1000;
    // 0x8006D010: beq         $t8, $zero, L_8006D084
    if (ctx->r24 == 0) {
        // 0x8006D014: nop
    
            goto L_8006D084;
    }
    // 0x8006D014: nop

    // 0x8006D018: jal         0x8006C530
    // 0x8006D01C: nop

    level_properties_get(rdram, ctx);
        goto after_7;
    // 0x8006D01C: nop

    after_7:
    // 0x8006D020: bne         $v0, $zero, L_8006D084
    if (ctx->r2 != 0) {
        // 0x8006D024: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8006D084;
    }
    // 0x8006D024: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006D028: lb          $t9, -0x2700($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X2700);
    // 0x8006D02C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006D030: bne         $t9, $zero, L_8006D084
    if (ctx->r25 != 0) {
        // 0x8006D034: nop
    
            goto L_8006D084;
    }
    // 0x8006D034: nop

    // 0x8006D038: lw          $t1, 0x3A6C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3A6C);
    // 0x8006D03C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006D040: bne         $t1, $zero, L_8006D084
    if (ctx->r9 != 0) {
        // 0x8006D044: nop
    
            goto L_8006D084;
    }
    // 0x8006D044: nop

    // 0x8006D048: lb          $t2, 0x3A96($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X3A96);
    // 0x8006D04C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8006D050: bne         $t2, $zero, L_8006D084
    if (ctx->r10 != 0) {
        // 0x8006D054: nop
    
            goto L_8006D084;
    }
    // 0x8006D054: nop

    // 0x8006D058: lh          $t3, -0x26FC($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X26FC);
    // 0x8006D05C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006D060: bne         $t3, $zero, L_8006D084
    if (ctx->r11 != 0) {
        // 0x8006D064: addiu       $a0, $a0, -0x26F8
        ctx->r4 = ADD32(ctx->r4, -0X26F8);
            goto L_8006D084;
    }
    // 0x8006D064: addiu       $a0, $a0, -0x26F8
    ctx->r4 = ADD32(ctx->r4, -0X26F8);
    // 0x8006D068: lb          $t4, 0x0($a0)
    ctx->r12 = MEM_B(ctx->r4, 0X0);
    // 0x8006D06C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8006D070: bne         $t4, $zero, L_8006D084
    if (ctx->r12 != 0) {
        // 0x8006D074: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8006D084;
    }
    // 0x8006D074: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D078: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8006D07C: jal         0x80093F44
    // 0x8006D080: sb          $t5, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = ctx->r13;
    menu_pause_init(rdram, ctx);
        goto after_8;
    // 0x8006D080: sb          $t5, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = ctx->r13;
    after_8:
L_8006D084:
    // 0x8006D084: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006D088: addiu       $a0, $a0, -0x26F8
    ctx->r4 = ADD32(ctx->r4, -0X26F8);
    // 0x8006D08C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D090: lb          $v0, 0x3A96($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3A96);
    // 0x8006D094: lb          $v1, 0x0($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X0);
    // 0x8006D098: b           L_8006D0C4
    // 0x8006D09C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
        goto L_8006D0C4;
    // 0x8006D09C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_8006D0A0:
    // 0x8006D0A0: jal         0x80028FE0
    // 0x8006D0A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_anti_aliasing(rdram, ctx);
        goto after_9;
    // 0x8006D0A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x8006D0A8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D0AC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8006D0B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006D0B4: lb          $v1, -0x26F8($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X26F8);
    // 0x8006D0B8: lb          $v0, 0x3A96($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3A96);
    // 0x8006D0BC: addiu       $a0, $a0, -0x26F8
    ctx->r4 = ADD32(ctx->r4, -0X26F8);
    // 0x8006D0C0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_8006D0C4:
    // 0x8006D0C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D0C8: subu        $t7, $v1, $t6
    ctx->r15 = SUB32(ctx->r3, ctx->r14);
    // 0x8006D0CC: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x8006D0D0: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8006D0D4: nop

    // 0x8006D0D8: bgez        $t8, L_8006D0E4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8006D0DC: nop
    
            goto L_8006D0E4;
    }
    // 0x8006D0DC: nop

    // 0x8006D0E0: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_8006D0E4:
    // 0x8006D0E4: beq         $v0, $zero, L_8006D0F0
    if (ctx->r2 == 0) {
        // 0x8006D0E8: nop
    
            goto L_8006D0F0;
    }
    // 0x8006D0E8: nop

    // 0x8006D0EC: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
L_8006D0F0:
    // 0x8006D0F0: jal         0x8001004C
    // 0x8006D0F4: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_10;
    // 0x8006D0F4: nop

    after_10:
    // 0x8006D0F8: jal         0x8001BF54
    // 0x8006D0FC: nop

    ainode_update(rdram, ctx);
        goto after_11;
    // 0x8006D0FC: nop

    after_11:
    // 0x8006D100: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8006D104: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D108: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D10C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006D110: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006D114: addiu       $a3, $a3, 0x17A8
    ctx->r7 = ADD32(ctx->r7, 0X17A8);
    // 0x8006D118: addiu       $a2, $a2, 0x1798
    ctx->r6 = ADD32(ctx->r6, 0X1798);
    // 0x8006D11C: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    // 0x8006D120: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006D124: jal         0x80024D94
    // 0x8006D128: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    render_scene(rdram, ctx);
        goto after_12;
    // 0x8006D128: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_12:
    // 0x8006D12C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006D130: lw          $t1, 0x3A6C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3A6C);
    // 0x8006D134: addiu       $at, $zero, -0x2031
    ctx->r1 = ADD32(0, -0X2031);
    // 0x8006D138: bne         $t1, $zero, L_8006D148
    if (ctx->r9 != 0) {
        // 0x8006D13C: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8006D148;
    }
    // 0x8006D13C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006D140: and         $t2, $s0, $at
    ctx->r10 = ctx->r16 & ctx->r1;
    // 0x8006D144: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8006D148:
    // 0x8006D148: lb          $t3, 0x3A96($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X3A96);
    // 0x8006D14C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D150: beq         $t3, $zero, L_8006D264
    if (ctx->r11 == 0) {
        // 0x8006D154: addiu       $a0, $a0, 0x1778
        ctx->r4 = ADD32(ctx->r4, 0X1778);
            goto L_8006D264;
    }
    // 0x8006D154: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006D158: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D15C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006D160: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8006D164: addiu       $a2, $a2, 0x1798
    ctx->r6 = ADD32(ctx->r6, 0X1798);
    // 0x8006D168: jal         0x80095C2C
    // 0x8006D16C: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    menu_postrace(rdram, ctx);
        goto after_13;
    // 0x8006D16C: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    after_13:
    // 0x8006D170: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8006D174: sltiu       $at, $t4, 0xD
    ctx->r1 = ctx->r12 < 0XD ? 1 : 0;
    // 0x8006D178: beq         $at, $zero, L_8006D264
    if (ctx->r1 == 0) {
        // 0x8006D17C: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8006D264;
    }
    // 0x8006D17C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006D180: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8006D184: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D188: addu        $at, $at, $t4
    gpr jr_addend_8006D194 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8006D18C: lw          $t4, 0x76E4($at)
    ctx->r12 = ADD32(ctx->r1, 0X76E4);
    // 0x8006D190: nop

    // 0x8006D194: jr          $t4
    // 0x8006D198: nop

    switch (jr_addend_8006D194 >> 2) {
        case 0: goto L_8006D1A8; break;
        case 1: goto L_8006D19C; break;
        case 2: goto L_8006D264; break;
        case 3: goto L_8006D1C0; break;
        case 4: goto L_8006D1DC; break;
        case 5: goto L_8006D264; break;
        case 6: goto L_8006D264; break;
        case 7: goto L_8006D1F0; break;
        case 8: goto L_8006D204; break;
        case 9: goto L_8006D218; break;
        case 10: goto L_8006D22C; break;
        case 11: goto L_8006D240; break;
        case 12: goto L_8006D254; break;
        default: switch_error(__func__, 0x8006D194, 0x800E76E4);
    }
    // 0x8006D198: nop

L_8006D19C:
    // 0x8006D19C: ori         $t5, $s0, 0x2020
    ctx->r13 = ctx->r16 | 0X2020;
    // 0x8006D1A0: b           L_8006D264
    // 0x8006D1A4: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
        goto L_8006D264;
    // 0x8006D1A4: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
L_8006D1A8:
    // 0x8006D1A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D1AC: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    // 0x8006D1B0: jal         0x8006DB30
    // 0x8006D1B4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_8006D8F0(rdram, ctx);
        goto after_14;
    // 0x8006D1B4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_14:
    // 0x8006D1B8: b           L_8006D268
    // 0x8006D1BC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
        goto L_8006D268;
    // 0x8006D1BC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_8006D1C0:
    // 0x8006D1C0: jal         0x8006C524
    // 0x8006D1C4: nop

    level_properties_reset(rdram, ctx);
        goto after_15;
    // 0x8006D1C4: nop

    after_15:
    // 0x8006D1C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D1CC: ori         $t6, $s0, 0x30
    ctx->r14 = ctx->r16 | 0X30;
    // 0x8006D1D0: sb          $zero, -0x2700($at)
    MEM_B(-0X2700, ctx->r1) = 0;
    // 0x8006D1D4: b           L_8006D264
    // 0x8006D1D8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
        goto L_8006D264;
    // 0x8006D1D8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_8006D1DC:
    // 0x8006D1DC: ori         $t7, $s0, 0x20
    ctx->r15 = ctx->r16 | 0X20;
    // 0x8006D1E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006D1E4: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8006D1E8: b           L_8006D264
    // 0x8006D1EC: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
        goto L_8006D264;
    // 0x8006D1EC: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_8006D1F0:
    // 0x8006D1F0: ori         $t9, $s0, 0x20
    ctx->r25 = ctx->r16 | 0X20;
    // 0x8006D1F4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8006D1F8: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8006D1FC: b           L_8006D264
    // 0x8006D200: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
        goto L_8006D264;
    // 0x8006D200: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_8006D204:
    // 0x8006D204: ori         $t2, $s0, 0x20
    ctx->r10 = ctx->r16 | 0X20;
    // 0x8006D208: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8006D20C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x8006D210: b           L_8006D264
    // 0x8006D214: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
        goto L_8006D264;
    // 0x8006D214: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8006D218:
    // 0x8006D218: ori         $t4, $s0, 0x20
    ctx->r12 = ctx->r16 | 0X20;
    // 0x8006D21C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8006D220: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x8006D224: b           L_8006D264
    // 0x8006D228: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
        goto L_8006D264;
    // 0x8006D228: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
L_8006D22C:
    // 0x8006D22C: ori         $t6, $s0, 0x20
    ctx->r14 = ctx->r16 | 0X20;
    // 0x8006D230: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8006D234: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8006D238: b           L_8006D264
    // 0x8006D23C: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
        goto L_8006D264;
    // 0x8006D23C: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_8006D240:
    // 0x8006D240: ori         $t8, $s0, 0x20
    ctx->r24 = ctx->r16 | 0X20;
    // 0x8006D244: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8006D248: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8006D24C: b           L_8006D264
    // 0x8006D250: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
        goto L_8006D264;
    // 0x8006D250: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
L_8006D254:
    // 0x8006D254: ori         $t1, $s0, 0x20
    ctx->r9 = ctx->r16 | 0X20;
    // 0x8006D258: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8006D25C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x8006D260: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
L_8006D264:
    // 0x8006D264: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_8006D268:
    // 0x8006D268: jal         0x800C3998
    // 0x8006D26C: nop

    process_onscreen_textbox(rdram, ctx);
        goto after_16;
    // 0x8006D26C: nop

    after_16:
    // 0x8006D270: jal         0x800C3958
    // 0x8006D274: nop

    textbox_visible(rdram, ctx);
        goto after_17;
    // 0x8006D274: nop

    after_17:
    // 0x8006D278: beq         $v0, $zero, L_8006D2B0
    if (ctx->r2 == 0) {
        // 0x8006D27C: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8006D2B0;
    }
    // 0x8006D27C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006D280: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006D284: bne         $v0, $at, L_8006D294
    if (ctx->r2 != ctx->r1) {
        // 0x8006D288: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8006D294;
    }
    // 0x8006D288: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006D28C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D290: sb          $t3, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = ctx->r11;
L_8006D294:
    // 0x8006D294: jal         0x800C3958
    // 0x8006D298: nop

    textbox_visible(rdram, ctx);
        goto after_18;
    // 0x8006D298: nop

    after_18:
    // 0x8006D29C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006D2A0: beq         $v0, $at, L_8006D2B0
    if (ctx->r2 == ctx->r1) {
        // 0x8006D2A4: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8006D2B0;
    }
    // 0x8006D2A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D2A8: jal         0x80094AE8
    // 0x8006D2AC: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    menu_close_dialogue(rdram, ctx);
        goto after_19;
    // 0x8006D2AC: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    after_19:
L_8006D2B0:
    // 0x8006D2B0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006D2B4: lb          $t4, 0x3A95($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X3A95);
    // 0x8006D2B8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8006D2BC: beq         $t4, $zero, L_8006D400
    if (ctx->r12 == 0) {
        // 0x8006D2C0: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8006D400;
    }
    // 0x8006D2C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D2C4: jal         0x80094674
    // 0x8006D2C8: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    menu_pause_loop(rdram, ctx);
        goto after_20;
    // 0x8006D2C8: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_20:
    // 0x8006D2CC: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x8006D2D0: sltiu       $at, $t5, 0xC
    ctx->r1 = ctx->r13 < 0XC ? 1 : 0;
    // 0x8006D2D4: beq         $at, $zero, L_8006D400
    if (ctx->r1 == 0) {
        // 0x8006D2D8: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8006D400;
    }
    // 0x8006D2D8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006D2DC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8006D2E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D2E4: addu        $at, $at, $t5
    gpr jr_addend_8006D2F0 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8006D2E8: lw          $t5, 0x7718($at)
    ctx->r13 = ADD32(ctx->r1, 0X7718);
    // 0x8006D2EC: nop

    // 0x8006D2F0: jr          $t5
    // 0x8006D2F4: nop

    switch (jr_addend_8006D2F0 >> 2) {
        case 0: goto L_8006D2F8; break;
        case 1: goto L_8006D304; break;
        case 2: goto L_8006D348; break;
        case 3: goto L_8006D3DC; break;
        case 4: goto L_8006D38C; break;
        case 5: goto L_8006D3BC; break;
        case 6: goto L_8006D3C8; break;
        case 7: goto L_8006D400; break;
        case 8: goto L_8006D400; break;
        case 9: goto L_8006D400; break;
        case 10: goto L_8006D400; break;
        case 11: goto L_8006D3A4; break;
        default: switch_error(__func__, 0x8006D2F0, 0x800E7718);
    }
    // 0x8006D2F4: nop

L_8006D2F8:
    // 0x8006D2F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D2FC: b           L_8006D400
    // 0x8006D300: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
        goto L_8006D400;
    // 0x8006D300: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
L_8006D304:
    // 0x8006D304: jal         0x80001050
    // 0x8006D308: nop

    sound_clear_delayed(rdram, ctx);
        goto after_21;
    // 0x8006D308: nop

    after_21:
    // 0x8006D30C: jal         0x800C36A4
    // 0x8006D310: nop

    reset_delayed_text(rdram, ctx);
        goto after_22;
    // 0x8006D310: nop

    after_22:
    // 0x8006D314: jal         0x8002359C
    // 0x8006D318: nop

    func_80023568(rdram, ctx);
        goto after_23;
    // 0x8006D318: nop

    after_23:
    // 0x8006D31C: beq         $v0, $zero, L_8006D340
    if (ctx->r2 == 0) {
        // 0x8006D320: ori         $t6, $s0, 0x2020
        ctx->r14 = ctx->r16 | 0X2020;
            goto L_8006D340;
    }
    // 0x8006D320: ori         $t6, $s0, 0x2020
    ctx->r14 = ctx->r16 | 0X2020;
    // 0x8006D324: jal         0x8009F1C4
    // 0x8006D328: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_24;
    // 0x8006D328: nop

    after_24:
    // 0x8006D32C: beq         $v0, $zero, L_8006D340
    if (ctx->r2 == 0) {
        // 0x8006D330: ori         $t6, $s0, 0x2020
        ctx->r14 = ctx->r16 | 0X2020;
            goto L_8006D340;
    }
    // 0x8006D330: ori         $t6, $s0, 0x2020
    ctx->r14 = ctx->r16 | 0X2020;
    // 0x8006D334: jal         0x8006F5D8
    // 0x8006D338: nop

    swap_lead_player(rdram, ctx);
        goto after_25;
    // 0x8006D338: nop

    after_25:
    // 0x8006D33C: ori         $t6, $s0, 0x2020
    ctx->r14 = ctx->r16 | 0X2020;
L_8006D340:
    // 0x8006D340: b           L_8006D400
    // 0x8006D344: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
        goto L_8006D400;
    // 0x8006D344: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_8006D348:
    // 0x8006D348: jal         0x80001050
    // 0x8006D34C: nop

    sound_clear_delayed(rdram, ctx);
        goto after_26;
    // 0x8006D34C: nop

    after_26:
    // 0x8006D350: jal         0x800C36A4
    // 0x8006D354: nop

    reset_delayed_text(rdram, ctx);
        goto after_27;
    // 0x8006D354: nop

    after_27:
    // 0x8006D358: jal         0x8002359C
    // 0x8006D35C: nop

    func_80023568(rdram, ctx);
        goto after_28;
    // 0x8006D35C: nop

    after_28:
    // 0x8006D360: beq         $v0, $zero, L_8006D384
    if (ctx->r2 == 0) {
        // 0x8006D364: ori         $t7, $s0, 0x20
        ctx->r15 = ctx->r16 | 0X20;
            goto L_8006D384;
    }
    // 0x8006D364: ori         $t7, $s0, 0x20
    ctx->r15 = ctx->r16 | 0X20;
    // 0x8006D368: jal         0x8009F1C4
    // 0x8006D36C: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_29;
    // 0x8006D36C: nop

    after_29:
    // 0x8006D370: beq         $v0, $zero, L_8006D384
    if (ctx->r2 == 0) {
        // 0x8006D374: ori         $t7, $s0, 0x20
        ctx->r15 = ctx->r16 | 0X20;
            goto L_8006D384;
    }
    // 0x8006D374: ori         $t7, $s0, 0x20
    ctx->r15 = ctx->r16 | 0X20;
    // 0x8006D378: jal         0x8006F5D8
    // 0x8006D37C: nop

    swap_lead_player(rdram, ctx);
        goto after_30;
    // 0x8006D37C: nop

    after_30:
    // 0x8006D380: ori         $t7, $s0, 0x20
    ctx->r15 = ctx->r16 | 0X20;
L_8006D384:
    // 0x8006D384: b           L_8006D400
    // 0x8006D388: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
        goto L_8006D400;
    // 0x8006D388: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_8006D38C:
    // 0x8006D38C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006D390: jal         0x800C36A4
    // 0x8006D394: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    reset_delayed_text(rdram, ctx);
        goto after_31;
    // 0x8006D394: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    after_31:
    // 0x8006D398: ori         $t9, $s0, 0x20
    ctx->r25 = ctx->r16 | 0X20;
    // 0x8006D39C: b           L_8006D400
    // 0x8006D3A0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
        goto L_8006D400;
    // 0x8006D3A0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_8006D3A4:
    // 0x8006D3A4: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8006D3A8: jal         0x800C36A4
    // 0x8006D3AC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    reset_delayed_text(rdram, ctx);
        goto after_32;
    // 0x8006D3AC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_32:
    // 0x8006D3B0: ori         $t2, $s0, 0x20
    ctx->r10 = ctx->r16 | 0X20;
    // 0x8006D3B4: b           L_8006D400
    // 0x8006D3B8: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
        goto L_8006D400;
    // 0x8006D3B8: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8006D3BC:
    // 0x8006D3BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D3C0: b           L_8006D400
    // 0x8006D3C4: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
        goto L_8006D400;
    // 0x8006D3C4: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
L_8006D3C8:
    // 0x8006D3C8: jal         0x80022E4C
    // 0x8006D3CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mode_end_taj_race(rdram, ctx);
        goto after_33;
    // 0x8006D3CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_33:
    // 0x8006D3D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D3D4: b           L_8006D400
    // 0x8006D3D8: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
        goto L_8006D400;
    // 0x8006D3D8: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
L_8006D3DC:
    // 0x8006D3DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D3E0: jal         0x80001050
    // 0x8006D3E4: sb          $zero, -0x2700($at)
    MEM_B(-0X2700, ctx->r1) = 0;
    sound_clear_delayed(rdram, ctx);
        goto after_34;
    // 0x8006D3E4: sb          $zero, -0x2700($at)
    MEM_B(-0X2700, ctx->r1) = 0;
    after_34:
    // 0x8006D3E8: jal         0x800C36A4
    // 0x8006D3EC: nop

    reset_delayed_text(rdram, ctx);
        goto after_35;
    // 0x8006D3EC: nop

    after_35:
    // 0x8006D3F0: jal         0x8006C524
    // 0x8006D3F4: nop

    level_properties_reset(rdram, ctx);
        goto after_36;
    // 0x8006D3F4: nop

    after_36:
    // 0x8006D3F8: ori         $t3, $s0, 0x30
    ctx->r11 = ctx->r16 | 0X30;
    // 0x8006D3FC: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
L_8006D400:
    // 0x8006D400: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D404: jal         0x800784A4
    // 0x8006D408: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    rdp_init(rdram, ctx);
        goto after_37;
    // 0x8006D408: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_37:
    // 0x8006D40C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D410: jal         0x800774A0
    // 0x8006D414: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    divider_draw(rdram, ctx);
        goto after_38;
    // 0x8006D414: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_38:
    // 0x8006D418: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D41C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D420: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006D424: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8006D428: addiu       $a2, $a2, 0x1798
    ctx->r6 = ADD32(ctx->r6, 0X1798);
    // 0x8006D42C: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    // 0x8006D430: jal         0x800A89D0
    // 0x8006D434: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    hud_render_general(rdram, ctx);
        goto after_39;
    // 0x8006D434: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_39:
    // 0x8006D438: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D43C: jal         0x800776B8
    // 0x8006D440: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    divider_clear_coverage(rdram, ctx);
        goto after_40;
    // 0x8006D440: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_40:
    // 0x8006D444: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8006D448: lb          $t4, -0x26F4($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X26F4);
    // 0x8006D44C: nop

    // 0x8006D450: beq         $t4, $zero, L_8006D48C
    if (ctx->r12 == 0) {
        // 0x8006D454: nop
    
            goto L_8006D48C;
    }
    // 0x8006D454: nop

    // 0x8006D458: jal         0x800214F8
    // 0x8006D45C: nop

    func_800214C4(rdram, ctx);
        goto after_41;
    // 0x8006D45C: nop

    after_41:
    // 0x8006D460: beq         $v0, $zero, L_8006D48C
    if (ctx->r2 == 0) {
        // 0x8006D464: addiu       $t5, $zero, 0x23
        ctx->r13 = ADD32(0, 0X23);
            goto L_8006D48C;
    }
    // 0x8006D464: addiu       $t5, $zero, 0x23
    ctx->r13 = ADD32(0, 0X23);
    // 0x8006D468: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D46C: sw          $t5, 0x3A74($at)
    MEM_W(0X3A74, ctx->r1) = ctx->r13;
    // 0x8006D470: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D474: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006D478: sw          $t6, 0x3A78($at)
    MEM_W(0X3A78, ctx->r1) = ctx->r14;
    // 0x8006D47C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D480: sw          $zero, 0x3A84($at)
    MEM_W(0X3A84, ctx->r1) = 0;
    // 0x8006D484: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D488: sb          $zero, -0x26F4($at)
    MEM_B(-0X26F4, ctx->r1) = 0;
L_8006D48C:
    // 0x8006D48C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006D490: addiu       $t0, $t0, -0x2700
    ctx->r8 = ADD32(ctx->r8, -0X2700);
    // 0x8006D494: lb          $v0, 0x0($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X0);
    // 0x8006D498: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8006D49C: beq         $v0, $zero, L_8006D4E4
    if (ctx->r2 == 0) {
        // 0x8006D4A0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006D4E4;
    }
    // 0x8006D4A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006D4A4: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x8006D4A8: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
    // 0x8006D4AC: lb          $t9, 0x0($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X0);
    // 0x8006D4B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006D4B4: bgtz        $t9, L_8006D4E4
    if (SIGNED(ctx->r25) > 0) {
        // 0x8006D4B8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8006D4E4;
    }
    // 0x8006D4B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006D4BC: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8006D4C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006D4C4: jal         0x8006C3EC
    // 0x8006D4C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_42;
    // 0x8006D4C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_42:
    // 0x8006D4CC: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x8006D4D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006D4D4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8006D4D8: jal         0x8006C3EC
    // 0x8006D4DC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    level_properties_push(rdram, ctx);
        goto after_43;
    // 0x8006D4DC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_43:
    // 0x8006D4E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8006D4E4:
    // 0x8006D4E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006D4E8: addiu       $a0, $a0, -0x26FC
    ctx->r4 = ADD32(ctx->r4, -0X26FC);
    // 0x8006D4EC: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8006D4F0: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8006D4F4: blez        $v0, L_8006D5C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006D4F8: subu        $t2, $v0, $t1
        ctx->r10 = SUB32(ctx->r2, ctx->r9);
            goto L_8006D5C0;
    }
    // 0x8006D4F8: subu        $t2, $v0, $t1
    ctx->r10 = SUB32(ctx->r2, ctx->r9);
    // 0x8006D4FC: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    // 0x8006D500: lh          $t3, 0x0($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X0);
    // 0x8006D504: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D508: bgtz        $t3, L_8006D5C0
    if (SIGNED(ctx->r11) > 0) {
        // 0x8006D50C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8006D5C0;
    }
    // 0x8006D50C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006D510: lb          $v0, 0x3AA4($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3AA4);
    // 0x8006D514: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x8006D518: beq         $v0, $at, L_8006D54C
    if (ctx->r2 == ctx->r1) {
        // 0x8006D51C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8006D54C;
    }
    // 0x8006D51C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8006D520: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006D524: beq         $v0, $at, L_8006D554
    if (ctx->r2 == ctx->r1) {
        // 0x8006D528: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_8006D554;
    }
    // 0x8006D528: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8006D52C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006D530: beq         $v0, $at, L_8006D57C
    if (ctx->r2 == ctx->r1) {
        // 0x8006D534: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8006D57C;
    }
    // 0x8006D534: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006D538: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006D53C: beq         $v0, $at, L_8006D588
    if (ctx->r2 == ctx->r1) {
        // 0x8006D540: nop
    
            goto L_8006D588;
    }
    // 0x8006D540: nop

    // 0x8006D544: b           L_8006D5B4
    // 0x8006D548: nop

        goto L_8006D5B4;
    // 0x8006D548: nop

L_8006D54C:
    // 0x8006D54C: b           L_8006D5B4
    // 0x8006D550: addiu       $s0, $zero, 0x2020
    ctx->r16 = ADD32(0, 0X2020);
        goto L_8006D5B4;
    // 0x8006D550: addiu       $s0, $zero, 0x2020
    ctx->r16 = ADD32(0, 0X2020);
L_8006D554:
    // 0x8006D554: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8006D558: jal         0x80098744
    // 0x8006D55C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    trophyround_adventure(rdram, ctx);
        goto after_44;
    // 0x8006D55C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_44:
    // 0x8006D560: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8006D564: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8006D568: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D56C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006D570: sw          $t5, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r13;
    // 0x8006D574: b           L_8006D5B4
    // 0x8006D578: addiu       $a0, $a0, -0x26FC
    ctx->r4 = ADD32(ctx->r4, -0X26FC);
        goto L_8006D5B4;
    // 0x8006D578: addiu       $a0, $a0, -0x26FC
    ctx->r4 = ADD32(ctx->r4, -0X26FC);
L_8006D57C:
    // 0x8006D57C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006D580: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D584: sb          $t6, -0x26F4($at)
    MEM_B(-0X26F4, ctx->r1) = ctx->r14;
L_8006D588:
    // 0x8006D588: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D58C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006D590: lb          $t8, 0x3AA5($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X3AA5);
    // 0x8006D594: sw          $t7, 0x3A78($at)
    MEM_W(0X3A78, ctx->r1) = ctx->r15;
    // 0x8006D598: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D59C: sw          $t8, 0x3A74($at)
    MEM_W(0X3A74, ctx->r1) = ctx->r24;
    // 0x8006D5A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D5A4: sw          $zero, 0x3A84($at)
    MEM_W(0X3A84, ctx->r1) = 0;
    // 0x8006D5A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D5AC: sw          $zero, 0x3A88($at)
    MEM_W(0X3A88, ctx->r1) = 0;
    // 0x8006D5B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006D5B4:
    // 0x8006D5B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D5B8: sb          $zero, 0x3AA4($at)
    MEM_B(0X3AA4, ctx->r1) = 0;
    // 0x8006D5BC: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
L_8006D5C0:
    // 0x8006D5C0: beq         $v1, $zero, L_8006D68C
    if (ctx->r3 == 0) {
        // 0x8006D5C4: nop
    
            goto L_8006D68C;
    }
    // 0x8006D5C4: nop

    // 0x8006D5C8: jal         0x8006C530
    // 0x8006D5CC: nop

    level_properties_get(rdram, ctx);
        goto after_45;
    // 0x8006D5CC: nop

    after_45:
    // 0x8006D5D0: beq         $v0, $zero, L_8006D7A0
    if (ctx->r2 == 0) {
        // 0x8006D5D4: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8006D7A0;
    }
    // 0x8006D5D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D5D8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D5DC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006D5E0: addiu       $a3, $a3, 0x3A88
    ctx->r7 = ADD32(ctx->r7, 0X3A88);
    // 0x8006D5E4: addiu       $a1, $a1, 0x3A84
    ctx->r5 = ADD32(ctx->r5, 0X3A84);
    // 0x8006D5E8: addiu       $a0, $a0, 0x3A74
    ctx->r4 = ADD32(ctx->r4, 0X3A74);
    // 0x8006D5EC: jal         0x8006C46C
    // 0x8006D5F0: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    level_properties_pop(rdram, ctx);
        goto after_46;
    // 0x8006D5F0: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_46:
    // 0x8006D5F4: jal         0x8006F66C
    // 0x8006D5F8: nop

    set_frame_blackout_timer(rdram, ctx);
        goto after_47;
    // 0x8006D5F8: nop

    after_47:
    // 0x8006D5FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D600: lw          $v0, 0x3A74($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A74);
    // 0x8006D604: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D608: bgez        $v0, L_8006D678
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006D60C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8006D678;
    }
    // 0x8006D60C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8006D610: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006D614: beq         $v0, $at, L_8006D624
    if (ctx->r2 == ctx->r1) {
        // 0x8006D618: addiu       $at, $zero, -0xA
        ctx->r1 = ADD32(0, -0XA);
            goto L_8006D624;
    }
    // 0x8006D618: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x8006D61C: bne         $v0, $at, L_8006D660
    if (ctx->r2 != ctx->r1) {
        // 0x8006D620: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8006D660;
    }
    // 0x8006D620: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8006D624:
    // 0x8006D624: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x8006D628: bne         $v0, $at, L_8006D64C
    if (ctx->r2 != ctx->r1) {
        // 0x8006D62C: ori         $t9, $s0, 0x20
        ctx->r25 = ctx->r16 | 0X20;
            goto L_8006D64C;
    }
    // 0x8006D62C: ori         $t9, $s0, 0x20
    ctx->r25 = ctx->r16 | 0X20;
    // 0x8006D630: jal         0x8009F1C4
    // 0x8006D634: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_48;
    // 0x8006D634: nop

    after_48:
    // 0x8006D638: beq         $v0, $zero, L_8006D64C
    if (ctx->r2 == 0) {
        // 0x8006D63C: ori         $t9, $s0, 0x20
        ctx->r25 = ctx->r16 | 0X20;
            goto L_8006D64C;
    }
    // 0x8006D63C: ori         $t9, $s0, 0x20
    ctx->r25 = ctx->r16 | 0X20;
    // 0x8006D640: jal         0x8006F5D8
    // 0x8006D644: nop

    swap_lead_player(rdram, ctx);
        goto after_49;
    // 0x8006D644: nop

    after_49:
    // 0x8006D648: ori         $t9, $s0, 0x20
    ctx->r25 = ctx->r16 | 0X20;
L_8006D64C:
    // 0x8006D64C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8006D650: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D654: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x8006D658: b           L_8006D7A0
    // 0x8006D65C: sw          $t1, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r9;
        goto L_8006D7A0;
    // 0x8006D65C: sw          $t1, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r9;
L_8006D660:
    // 0x8006D660: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D664: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8006D668: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006D66C: sw          $t2, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r10;
    // 0x8006D670: b           L_8006D7A0
    // 0x8006D674: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
        goto L_8006D7A0;
    // 0x8006D674: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
L_8006D678:
    // 0x8006D678: sw          $zero, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = 0;
    // 0x8006D67C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D680: sw          $t4, 0x3A78($at)
    MEM_W(0X3A78, ctx->r1) = ctx->r12;
    // 0x8006D684: b           L_8006D7A0
    // 0x8006D688: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8006D7A0;
    // 0x8006D688: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006D68C:
    // 0x8006D68C: jal         0x8006C540
    // 0x8006D690: nop

    func_8006C300(rdram, ctx);
        goto after_50;
    // 0x8006D690: nop

    after_50:
    // 0x8006D694: jal         0x8006C530
    // 0x8006D698: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    level_properties_get(rdram, ctx);
        goto after_51;
    // 0x8006D698: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_51:
    // 0x8006D69C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8006D6A0: beq         $v0, $zero, L_8006D7A0
    if (ctx->r2 == 0) {
        // 0x8006D6A4: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8006D7A0;
    }
    // 0x8006D6A4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8006D6A8: lh          $t5, -0x26FC($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X26FC);
    // 0x8006D6AC: nop

    // 0x8006D6B0: bne         $t5, $zero, L_8006D7A4
    if (ctx->r13 != 0) {
        // 0x8006D6B4: andi        $t4, $s0, 0x20
        ctx->r12 = ctx->r16 & 0X20;
            goto L_8006D7A4;
    }
    // 0x8006D6B4: andi        $t4, $s0, 0x20
    ctx->r12 = ctx->r16 & 0X20;
    // 0x8006D6B8: jal         0x800214F8
    // 0x8006D6BC: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_800214C4(rdram, ctx);
        goto after_52;
    // 0x8006D6BC: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_52:
    // 0x8006D6C0: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8006D6C4: bne         $v0, $zero, L_8006D6E8
    if (ctx->r2 != 0) {
        // 0x8006D6C8: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8006D6E8;
    }
    // 0x8006D6C8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006D6CC: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8006D6D0: nop

    // 0x8006D6D4: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8006D6D8: beq         $t7, $zero, L_8006D7A4
    if (ctx->r15 == 0) {
        // 0x8006D6DC: andi        $t4, $s0, 0x20
        ctx->r12 = ctx->r16 & 0X20;
            goto L_8006D7A4;
    }
    // 0x8006D6DC: andi        $t4, $s0, 0x20
    ctx->r12 = ctx->r16 & 0X20;
    // 0x8006D6E0: beq         $v1, $zero, L_8006D7A4
    if (ctx->r3 == 0) {
        // 0x8006D6E4: andi        $t4, $s0, 0x20
        ctx->r12 = ctx->r16 & 0X20;
            goto L_8006D7A4;
    }
    // 0x8006D6E4: andi        $t4, $s0, 0x20
    ctx->r12 = ctx->r16 & 0X20;
L_8006D6E8:
    // 0x8006D6E8: beq         $v1, $zero, L_8006D6F8
    if (ctx->r3 == 0) {
        // 0x8006D6EC: nop
    
            goto L_8006D6F8;
    }
    // 0x8006D6EC: nop

    // 0x8006D6F0: jal         0x80000B28
    // 0x8006D6F4: nop

    music_change_on(rdram, ctx);
        goto after_53;
    // 0x8006D6F4: nop

    after_53:
L_8006D6F8:
    // 0x8006D6F8: jal         0x8006F66C
    // 0x8006D6FC: nop

    set_frame_blackout_timer(rdram, ctx);
        goto after_54;
    // 0x8006D6FC: nop

    after_54:
    // 0x8006D700: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D704: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D708: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006D70C: addiu       $a3, $a3, 0x3A88
    ctx->r7 = ADD32(ctx->r7, 0X3A88);
    // 0x8006D710: addiu       $a1, $a1, 0x3A84
    ctx->r5 = ADD32(ctx->r5, 0X3A84);
    // 0x8006D714: addiu       $a0, $a0, 0x3A74
    ctx->r4 = ADD32(ctx->r4, 0X3A74);
    // 0x8006D718: jal         0x8006C46C
    // 0x8006D71C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    level_properties_pop(rdram, ctx);
        goto after_55;
    // 0x8006D71C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_55:
    // 0x8006D720: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D724: lw          $v0, 0x3A74($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A74);
    // 0x8006D728: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006D72C: bgez        $v0, L_8006D79C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006D730: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8006D79C;
    }
    // 0x8006D730: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D734: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006D738: beq         $v0, $at, L_8006D748
    if (ctx->r2 == ctx->r1) {
        // 0x8006D73C: addiu       $at, $zero, -0xA
        ctx->r1 = ADD32(0, -0XA);
            goto L_8006D748;
    }
    // 0x8006D73C: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x8006D740: bne         $v0, $at, L_8006D784
    if (ctx->r2 != ctx->r1) {
        // 0x8006D744: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8006D784;
    }
    // 0x8006D744: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8006D748:
    // 0x8006D748: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x8006D74C: bne         $v0, $at, L_8006D770
    if (ctx->r2 != ctx->r1) {
        // 0x8006D750: ori         $t8, $s0, 0x20
        ctx->r24 = ctx->r16 | 0X20;
            goto L_8006D770;
    }
    // 0x8006D750: ori         $t8, $s0, 0x20
    ctx->r24 = ctx->r16 | 0X20;
    // 0x8006D754: jal         0x8009F1C4
    // 0x8006D758: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_56;
    // 0x8006D758: nop

    after_56:
    // 0x8006D75C: beq         $v0, $zero, L_8006D770
    if (ctx->r2 == 0) {
        // 0x8006D760: ori         $t8, $s0, 0x20
        ctx->r24 = ctx->r16 | 0X20;
            goto L_8006D770;
    }
    // 0x8006D760: ori         $t8, $s0, 0x20
    ctx->r24 = ctx->r16 | 0X20;
    // 0x8006D764: jal         0x8006F5D8
    // 0x8006D768: nop

    swap_lead_player(rdram, ctx);
        goto after_57;
    // 0x8006D768: nop

    after_57:
    // 0x8006D76C: ori         $t8, $s0, 0x20
    ctx->r24 = ctx->r16 | 0X20;
L_8006D770:
    // 0x8006D770: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8006D774: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D778: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8006D77C: b           L_8006D7A0
    // 0x8006D780: sw          $t9, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r25;
        goto L_8006D7A0;
    // 0x8006D780: sw          $t9, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r25;
L_8006D784:
    // 0x8006D784: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D788: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8006D78C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006D790: sw          $t1, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r9;
    // 0x8006D794: b           L_8006D7A0
    // 0x8006D798: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
        goto L_8006D7A0;
    // 0x8006D798: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
L_8006D79C:
    // 0x8006D79C: sw          $t3, 0x3A78($at)
    MEM_W(0X3A78, ctx->r1) = ctx->r11;
L_8006D7A0:
    // 0x8006D7A0: andi        $t4, $s0, 0x20
    ctx->r12 = ctx->r16 & 0X20;
L_8006D7A4:
    // 0x8006D7A4: beq         $t4, $zero, L_8006D7B8
    if (ctx->r12 == 0) {
        // 0x8006D7A8: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8006D7B8;
    }
    // 0x8006D7A8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006D7AC: lw          $t5, 0x3A6C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3A6C);
    // 0x8006D7B0: nop

    // 0x8006D7B4: beq         $t5, $zero, L_8006D7C8
    if (ctx->r13 == 0) {
        // 0x8006D7B8: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006D7C8;
    }
L_8006D7B8:
    // 0x8006D7B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006D7BC: lw          $t6, 0x3A7C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3A7C);
    // 0x8006D7C0: nop

    // 0x8006D7C4: beq         $t6, $zero, L_8006DA78
    if (ctx->r14 == 0) {
        // 0x8006D7C8: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8006DA78;
    }
L_8006D7C8:
    // 0x8006D7C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D7CC: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    // 0x8006D7D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D7D4: sh          $zero, -0x26FC($at)
    MEM_H(-0X26FC, ctx->r1) = 0;
    // 0x8006D7D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D7DC: jal         0x8006CE54
    // 0x8006D7E0: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    unload_level_game(rdram, ctx);
        goto after_58;
    // 0x8006D7E0: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    after_58:
    // 0x8006D7E4: jal         0x8009C6E4
    // 0x8006D7E8: nop

    get_save_file_index(rdram, ctx);
        goto after_59;
    // 0x8006D7E8: nop

    after_59:
    // 0x8006D7EC: jal         0x8006EE88
    // 0x8006D7F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_60;
    // 0x8006D7F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_60:
    // 0x8006D7F4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8006D7F8: nop

    // 0x8006D7FC: beq         $t7, $zero, L_8006D94C
    if (ctx->r15 == 0) {
        // 0x8006D800: nop
    
            goto L_8006D94C;
    }
    // 0x8006D800: nop

    // 0x8006D804: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8006D808: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006D80C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8006D810: addiu       $s0, $s0, 0x3A94
    ctx->r16 = ADD32(ctx->r16, 0X3A94);
    // 0x8006D814: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x8006D818: beq         $at, $zero, L_8006DA70
    if (ctx->r1 == 0) {
        // 0x8006D81C: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_8006DA70;
    }
    // 0x8006D81C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8006D820: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8006D824: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D828: addu        $at, $at, $t9
    gpr jr_addend_8006D834 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8006D82C: lw          $t9, 0x7748($at)
    ctx->r25 = ADD32(ctx->r1, 0X7748);
    // 0x8006D830: nop

    // 0x8006D834: jr          $t9
    // 0x8006D838: nop

    switch (jr_addend_8006D834 >> 2) {
        case 0: goto L_8006D83C; break;
        case 1: goto L_8006D854; break;
        case 2: goto L_8006D86C; break;
        case 3: goto L_8006D884; break;
        case 4: goto L_8006D89C; break;
        case 5: goto L_8006D8B4; break;
        case 6: goto L_8006D914; break;
        case 7: goto L_8006D934; break;
        default: switch_error(__func__, 0x8006D834, 0x800E7748);
    }
    // 0x8006D838: nop

L_8006D83C:
    // 0x8006D83C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8006D840: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D844: jal         0x8006DC68
    // 0x8006D848: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    load_menu_with_level_background(rdram, ctx);
        goto after_61;
    // 0x8006D848: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_61:
    // 0x8006D84C: b           L_8006DA70
    // 0x8006D850: nop

        goto L_8006DA70;
    // 0x8006D850: nop

L_8006D854:
    // 0x8006D854: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8006D858: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8006D85C: jal         0x8006DC68
    // 0x8006D860: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_62;
    // 0x8006D860: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_62:
    // 0x8006D864: b           L_8006DA70
    // 0x8006D868: nop

        goto L_8006DA70;
    // 0x8006D868: nop

L_8006D86C:
    // 0x8006D86C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8006D870: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8006D874: jal         0x8006DC68
    // 0x8006D878: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_63;
    // 0x8006D878: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_63:
    // 0x8006D87C: b           L_8006DA70
    // 0x8006D880: nop

        goto L_8006DA70;
    // 0x8006D880: nop

L_8006D884:
    // 0x8006D884: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8006D888: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8006D88C: jal         0x8006DC68
    // 0x8006D890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_64;
    // 0x8006D890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_64:
    // 0x8006D894: b           L_8006DA70
    // 0x8006D898: nop

        goto L_8006DA70;
    // 0x8006D898: nop

L_8006D89C:
    // 0x8006D89C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8006D8A0: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8006D8A4: jal         0x8006DC68
    // 0x8006D8A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_65;
    // 0x8006D8A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_65:
    // 0x8006D8AC: b           L_8006DA70
    // 0x8006D8B0: nop

        goto L_8006DA70;
    // 0x8006D8B0: nop

L_8006D8B4:
    // 0x8006D8B4: jal         0x8009F214
    // 0x8006D8B8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    is_drumstick_unlocked(rdram, ctx);
        goto after_66;
    // 0x8006D8B8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_66:
    // 0x8006D8BC: beq         $v0, $zero, L_8006D8D4
    if (ctx->r2 == 0) {
        // 0x8006D8C0: nop
    
            goto L_8006D8D4;
    }
    // 0x8006D8C0: nop

    // 0x8006D8C4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8006D8C8: nop

    // 0x8006D8CC: xori        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 ^ 0X1;
    // 0x8006D8D0: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_8006D8D4:
    // 0x8006D8D4: jal         0x8009F1FC
    // 0x8006D8D8: nop

    is_tt_unlocked(rdram, ctx);
        goto after_67;
    // 0x8006D8D8: nop

    after_67:
    // 0x8006D8DC: beq         $v0, $zero, L_8006D8F4
    if (ctx->r2 == 0) {
        // 0x8006D8E0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8006D8F4;
    }
    // 0x8006D8E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006D8E4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8006D8E8: nop

    // 0x8006D8EC: xori        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 ^ 0X3;
    // 0x8006D8F0: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_8006D8F4:
    // 0x8006D8F4: jal         0x8008B36C
    // 0x8006D8F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    charselect_prev(rdram, ctx);
        goto after_68;
    // 0x8006D8F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_68:
    // 0x8006D8FC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8006D900: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8006D904: jal         0x8006DC68
    // 0x8006D908: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    load_menu_with_level_background(rdram, ctx);
        goto after_69;
    // 0x8006D908: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_69:
    // 0x8006D90C: b           L_8006DA70
    // 0x8006D910: nop

        goto L_8006DA70;
    // 0x8006D910: nop

L_8006D914:
    // 0x8006D914: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8006D918: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x8006D91C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8006D920: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D924: jal         0x8006DC68
    // 0x8006D928: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_70;
    // 0x8006D928: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_70:
    // 0x8006D92C: b           L_8006DA70
    // 0x8006D930: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_8006DA70;
    // 0x8006D930: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8006D934:
    // 0x8006D934: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x8006D938: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D93C: jal         0x8006DC68
    // 0x8006D940: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_71;
    // 0x8006D940: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_71:
    // 0x8006D944: b           L_8006DA70
    // 0x8006D948: nop

        goto L_8006DA70;
    // 0x8006D948: nop

L_8006D94C:
    // 0x8006D94C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006D950: lw          $t6, 0x3A7C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3A7C);
    // 0x8006D954: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006D958: bne         $t6, $at, L_8006D9B4
    if (ctx->r14 != ctx->r1) {
        // 0x8006D95C: andi        $t9, $s0, 0x10
        ctx->r25 = ctx->r16 & 0X10;
            goto L_8006D9B4;
    }
    // 0x8006D95C: andi        $t9, $s0, 0x10
    ctx->r25 = ctx->r16 & 0X10;
    // 0x8006D960: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D964: addiu       $v0, $v0, 0x17D0
    ctx->r2 = ADD32(ctx->r2, 0X17D0);
    // 0x8006D968: lb          $t7, 0x2($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X2);
    // 0x8006D96C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006D970: bne         $t7, $at, L_8006D990
    if (ctx->r15 != ctx->r1) {
        // 0x8006D974: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8006D990;
    }
    // 0x8006D974: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006D978: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8006D97C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D980: jal         0x8006DC68
    // 0x8006D984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_72;
    // 0x8006D984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_72:
    // 0x8006D988: b           L_8006DA70
    // 0x8006D98C: nop

        goto L_8006DA70;
    // 0x8006D98C: nop

L_8006D990:
    // 0x8006D990: addiu       $s0, $s0, 0x3A94
    ctx->r16 = ADD32(ctx->r16, 0X3A94);
    // 0x8006D994: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006D998: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x8006D99C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8006D9A0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D9A4: jal         0x8006DC68
    // 0x8006D9A8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    load_menu_with_level_background(rdram, ctx);
        goto after_73;
    // 0x8006D9A8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_73:
    // 0x8006D9AC: b           L_8006DA70
    // 0x8006D9B0: nop

        goto L_8006DA70;
    // 0x8006D9B0: nop

L_8006D9B4:
    // 0x8006D9B4: bne         $t9, $zero, L_8006DA50
    if (ctx->r25 != 0) {
        // 0x8006D9B8: andi        $t1, $s0, 0x2000
        ctx->r9 = ctx->r16 & 0X2000;
            goto L_8006DA50;
    }
    // 0x8006D9B8: andi        $t1, $s0, 0x2000
    ctx->r9 = ctx->r16 & 0X2000;
    // 0x8006D9BC: bne         $t1, $zero, L_8006DA20
    if (ctx->r9 != 0) {
        // 0x8006D9C0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8006DA20;
    }
    // 0x8006D9C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D9C4: addiu       $v0, $v0, 0x17D0
    ctx->r2 = ADD32(ctx->r2, 0X17D0);
    // 0x8006D9C8: lb          $t2, 0x0($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X0);
    // 0x8006D9CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D9D0: sw          $t2, 0x3A74($at)
    MEM_W(0X3A74, ctx->r1) = ctx->r10;
    // 0x8006D9D4: lb          $t3, 0xF($v0)
    ctx->r11 = MEM_B(ctx->r2, 0XF);
    // 0x8006D9D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D9DC: sw          $t3, 0x3A84($at)
    MEM_W(0X3A84, ctx->r1) = ctx->r11;
    // 0x8006D9E0: lb          $t4, 0x1($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X1);
    // 0x8006D9E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D9E8: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8006D9EC: lb          $t6, 0x8($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X8);
    // 0x8006D9F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D9F4: lw          $a0, 0x3A74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3A74);
    // 0x8006D9F8: jal         0x8006B2EC
    // 0x8006D9FC: sw          $t6, 0x3A88($at)
    MEM_W(0X3A88, ctx->r1) = ctx->r14;
    leveltable_vehicle_default(rdram, ctx);
        goto after_74;
    // 0x8006D9FC: sw          $t6, 0x3A88($at)
    MEM_W(0X3A88, ctx->r1) = ctx->r14;
    after_74:
    // 0x8006DA00: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006DA04: lw          $t7, 0x3A88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3A88);
    // 0x8006DA08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DA0C: bgez        $t7, L_8006DA20
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8006DA10: sw          $v0, 0x3A98($at)
        MEM_W(0X3A98, ctx->r1) = ctx->r2;
            goto L_8006DA20;
    }
    // 0x8006DA10: sw          $v0, 0x3A98($at)
    MEM_W(0X3A98, ctx->r1) = ctx->r2;
    // 0x8006DA14: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8006DA18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DA1C: sw          $t8, 0x3A88($at)
    MEM_W(0X3A88, ctx->r1) = ctx->r24;
L_8006DA20:
    // 0x8006DA20: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DA24: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006DA28: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006DA2C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006DA30: lw          $a3, 0x3A98($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3A98);
    // 0x8006DA34: lw          $a2, 0x3A84($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3A84);
    // 0x8006DA38: lw          $a1, 0x3A80($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3A80);
    // 0x8006DA3C: lw          $a0, 0x3A74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3A74);
    // 0x8006DA40: jal         0x8006CD98
    // 0x8006DA44: nop

    load_level_game(rdram, ctx);
        goto after_75;
    // 0x8006DA44: nop

    after_75:
    // 0x8006DA48: b           L_8006DA70
    // 0x8006DA4C: nop

        goto L_8006DA70;
    // 0x8006DA4C: nop

L_8006DA50:
    // 0x8006DA50: jal         0x8009C6E4
    // 0x8006DA54: nop

    get_save_file_index(rdram, ctx);
        goto after_76;
    // 0x8006DA54: nop

    after_76:
    // 0x8006DA58: jal         0x8006EE88
    // 0x8006DA5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_77;
    // 0x8006DA5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_77:
    // 0x8006DA60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006DA64: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006DA68: jal         0x8006DC68
    // 0x8006DA6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_78;
    // 0x8006DA6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_78:
L_8006DA70:
    // 0x8006DA70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DA74: sw          $zero, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = 0;
L_8006DA78:
    // 0x8006DA78: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006DA7C: lw          $t9, 0x3A78($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3A78);
    // 0x8006DA80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DA84: beq         $t9, $zero, L_8006DAD8
    if (ctx->r25 == 0) {
        // 0x8006DA88: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006DAD8;
    }
    // 0x8006DA88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006DA8C: jal         0x8006CE54
    // 0x8006DA90: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    unload_level_game(rdram, ctx);
        goto after_79;
    // 0x8006DA90: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    after_79:
    // 0x8006DA94: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DA98: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006DA9C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006DAA0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006DAA4: lw          $a3, 0x3A98($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3A98);
    // 0x8006DAA8: lw          $a2, 0x3A84($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3A84);
    // 0x8006DAAC: lw          $a1, 0x3A80($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3A80);
    // 0x8006DAB0: lw          $a0, 0x3A74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3A74);
    // 0x8006DAB4: jal         0x8006CD98
    // 0x8006DAB8: nop

    load_level_game(rdram, ctx);
        goto after_80;
    // 0x8006DAB8: nop

    after_80:
    // 0x8006DABC: jal         0x8009C6E4
    // 0x8006DAC0: nop

    get_save_file_index(rdram, ctx);
        goto after_81;
    // 0x8006DAC0: nop

    after_81:
    // 0x8006DAC4: jal         0x8006EE88
    // 0x8006DAC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_82;
    // 0x8006DAC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_82:
    // 0x8006DACC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DAD0: sw          $zero, 0x3A78($at)
    MEM_W(0X3A78, ctx->r1) = 0;
    // 0x8006DAD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006DAD8:
    // 0x8006DAD8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006DADC: jr          $ra
    // 0x8006DAE0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8006DAE0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _bcmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE5B0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800CE5B4: bne         $at, $zero, L_800CE694
    if (ctx->r1 != 0) {
        // 0x800CE5B8: xor         $v0, $a0, $a1
        ctx->r2 = ctx->r4 ^ ctx->r5;
            goto L_800CE694;
    }
    // 0x800CE5B8: xor         $v0, $a0, $a1
    ctx->r2 = ctx->r4 ^ ctx->r5;
    // 0x800CE5BC: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800CE5C0: bne         $v0, $zero, L_800CE628
    if (ctx->r2 != 0) {
        // 0x800CE5C4: negu        $t8, $a0
        ctx->r24 = SUB32(0, ctx->r4);
            goto L_800CE628;
    }
    // 0x800CE5C4: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x800CE5C8: andi        $t8, $t8, 0x3
    ctx->r24 = ctx->r24 & 0X3;
    // 0x800CE5CC: beq         $t8, $zero, L_800CE5EC
    if (ctx->r24 == 0) {
        // 0x800CE5D0: subu        $a2, $a2, $t8
        ctx->r6 = SUB32(ctx->r6, ctx->r24);
            goto L_800CE5EC;
    }
    // 0x800CE5D0: subu        $a2, $a2, $t8
    ctx->r6 = SUB32(ctx->r6, ctx->r24);
    // 0x800CE5D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CE5D8: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    // 0x800CE5DC: lwl         $v1, 0x0($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r5, 0X0);
    // 0x800CE5E0: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800CE5E4: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x800CE5E8: bne         $v0, $v1, L_800CE6C4
    if (ctx->r2 != ctx->r3) {
        // 0x800CE5EC: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800CE6C4;
    }
L_800CE5EC:
    // 0x800CE5EC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800CE5F0: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x800CE5F4: beq         $a3, $zero, L_800CE694
    if (ctx->r7 == 0) {
        // 0x800CE5F8: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_800CE694;
    }
    // 0x800CE5F8: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x800CE5FC: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x800CE600: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_800CE604:
    // 0x800CE604: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800CE608: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800CE60C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800CE610: bne         $v0, $v1, L_800CE6C4
    if (ctx->r2 != ctx->r3) {
        // 0x800CE614: nop
    
            goto L_800CE6C4;
    }
    // 0x800CE614: nop

    // 0x800CE618: bnel        $a0, $a3, L_800CE604
    if (ctx->r4 != ctx->r7) {
        // 0x800CE61C: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_800CE604;
    }
    goto skip_0;
    // 0x800CE61C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800CE620: b           L_800CE694
    // 0x800CE624: nop

        goto L_800CE694;
    // 0x800CE624: nop

L_800CE628:
    // 0x800CE628: negu        $a3, $a1
    ctx->r7 = SUB32(0, ctx->r5);
    // 0x800CE62C: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x800CE630: beq         $a3, $zero, L_800CE65C
    if (ctx->r7 == 0) {
        // 0x800CE634: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_800CE65C;
    }
    // 0x800CE634: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x800CE638: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x800CE63C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_800CE640:
    // 0x800CE640: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE644: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CE648: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CE64C: bne         $v0, $v1, L_800CE6C4
    if (ctx->r2 != ctx->r3) {
        // 0x800CE650: nop
    
            goto L_800CE6C4;
    }
    // 0x800CE650: nop

    // 0x800CE654: bnel        $a0, $a3, L_800CE640
    if (ctx->r4 != ctx->r7) {
        // 0x800CE658: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_800CE640;
    }
    goto skip_1;
    // 0x800CE658: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_800CE65C:
    // 0x800CE65C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800CE660: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x800CE664: beq         $a3, $zero, L_800CE694
    if (ctx->r7 == 0) {
        // 0x800CE668: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_800CE694;
    }
    // 0x800CE668: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x800CE66C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x800CE670: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
L_800CE674:
    // 0x800CE674: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800CE678: lwr         $v0, 0x3($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r4, 0X3);
    // 0x800CE67C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800CE680: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800CE684: bne         $v0, $v1, L_800CE6C4
    if (ctx->r2 != ctx->r3) {
        // 0x800CE688: nop
    
            goto L_800CE6C4;
    }
    // 0x800CE688: nop

    // 0x800CE68C: bnel        $a0, $a3, L_800CE674
    if (ctx->r4 != ctx->r7) {
        // 0x800CE690: lwl         $v0, 0x0($a0)
        ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
            goto L_800CE674;
    }
    goto skip_2;
    // 0x800CE690: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    skip_2:
L_800CE694:
    // 0x800CE694: blez        $a2, L_800CE6BC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800CE698: addu        $a3, $a2, $a0
        ctx->r7 = ADD32(ctx->r6, ctx->r4);
            goto L_800CE6BC;
    }
    // 0x800CE698: addu        $a3, $a2, $a0
    ctx->r7 = ADD32(ctx->r6, ctx->r4);
    // 0x800CE69C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_800CE6A0:
    // 0x800CE6A0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE6A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CE6A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CE6AC: bne         $v0, $v1, L_800CE6C4
    if (ctx->r2 != ctx->r3) {
        // 0x800CE6B0: nop
    
            goto L_800CE6C4;
    }
    // 0x800CE6B0: nop

    // 0x800CE6B4: bnel        $a0, $a3, L_800CE6A0
    if (ctx->r4 != ctx->r7) {
        // 0x800CE6B8: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_800CE6A0;
    }
    goto skip_3;
    // 0x800CE6B8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_3:
L_800CE6BC:
    // 0x800CE6BC: jr          $ra
    // 0x800CE6C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE6C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CE6C4:
    // 0x800CE6C4: jr          $ra
    // 0x800CE6C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800CE6C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void obj_init_rangetrigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800421AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800421B0: jr          $ra
    // 0x800421B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x800421B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void sndp_set_group_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004A60: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80004A64: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80004A68: andi        $s2, $a0, 0xFF
    ctx->r18 = ctx->r4 & 0XFF;
    // 0x80004A6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80004A70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80004A74: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80004A78: andi        $s1, $a1, 0xFFFF
    ctx->r17 = ctx->r5 & 0XFFFF;
    // 0x80004A7C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80004A80: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80004A84: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80004A88: jal         0x800C9F90
    // 0x80004A8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80004A8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80004A90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80004A94: lw          $t6, -0x5E58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E58);
    // 0x80004A98: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80004A9C: lw          $s0, -0x33E0($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X33E0);
    // 0x80004AA0: sll         $t7, $s2, 1
    ctx->r15 = S32(ctx->r18 << 1);
    // 0x80004AA4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80004AA8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80004AAC: beq         $s0, $zero, L_80004B0C
    if (ctx->r16 == 0) {
        // 0x80004AB0: sh          $s1, 0x0($t8)
        MEM_H(0X0, ctx->r24) = ctx->r17;
            goto L_80004B0C;
    }
    // 0x80004AB0: sh          $s1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r17;
    // 0x80004AB4: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80004AB8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80004ABC: addiu       $s2, $s2, -0x33D4
    ctx->r18 = ADD32(ctx->r18, -0X33D4);
    // 0x80004AC0: addiu       $s3, $sp, 0x2C
    ctx->r19 = ADD32(ctx->r29, 0X2C);
L_80004AC4:
    // 0x80004AC4: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80004AC8: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x80004ACC: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80004AD0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80004AD4: lbu         $t1, 0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2);
    // 0x80004AD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004ADC: andi        $t2, $t1, 0x3F
    ctx->r10 = ctx->r9 & 0X3F;
    // 0x80004AE0: bne         $s1, $t2, L_80004AFC
    if (ctx->r17 != ctx->r10) {
        // 0x80004AE4: nop
    
            goto L_80004AFC;
    }
    // 0x80004AE4: nop

    // 0x80004AE8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80004AEC: sh          $t3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r11;
    // 0x80004AF0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80004AF4: jal         0x800C970C
    // 0x80004AF8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x80004AF8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
L_80004AFC:
    // 0x80004AFC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80004B00: nop

    // 0x80004B04: bne         $s0, $zero, L_80004AC4
    if (ctx->r16 != 0) {
        // 0x80004B08: nop
    
            goto L_80004AC4;
    }
    // 0x80004B08: nop

L_80004B0C:
    // 0x80004B0C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80004B10: jal         0x800C9F90
    // 0x80004B14: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80004B14: nop

    after_2:
    // 0x80004B18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80004B1C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80004B20: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80004B24: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80004B28: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80004B2C: jr          $ra
    // 0x80004B30: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80004B30: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void asset_table_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076EE4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80076EE8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80076EEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076EF0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076EF4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80076EF8: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x80076EFC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80076F00: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80076F04: jal         0x800C9110
    // 0x80076F08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80076F08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80076F0C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80076F10: lw          $v1, 0x4830($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4830);
    // 0x80076F14: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80076F18: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80076F1C: lui         $a1, 0x7F7F
    ctx->r5 = S32(0X7F7F << 16);
    // 0x80076F20: sltu        $at, $t6, $a3
    ctx->r1 = ctx->r14 < ctx->r7 ? 1 : 0;
    // 0x80076F24: beq         $at, $zero, L_80076F34
    if (ctx->r1 == 0) {
        // 0x80076F28: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80076F34;
    }
    // 0x80076F28: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80076F2C: b           L_80076FA0
    // 0x80076F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80076FA0;
    // 0x80076F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076F34:
    // 0x80076F34: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80076F38: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x80076F3C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80076F40: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80076F44: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x80076F48: subu        $a0, $t8, $t0
    ctx->r4 = SUB32(ctx->r24, ctx->r8);
    // 0x80076F4C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80076F50: jal         0x80070EDC
    // 0x80076F54: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80076F54: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_1:
    // 0x80076F58: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80076F5C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80076F60: bne         $v0, $zero, L_80076F70
    if (ctx->r2 != 0) {
        // 0x80076F64: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80076F70;
    }
    // 0x80076F64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80076F68: b           L_80076FA0
    // 0x80076F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80076FA0;
    // 0x80076F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076F70:
    // 0x80076F70: lui         $t9, 0xF
    ctx->r25 = S32(0XF << 16);
    // 0x80076F74: addiu       $t9, $t9, -0x2E50
    ctx->r25 = ADD32(ctx->r25, -0X2E50);
    // 0x80076F78: addu        $a0, $t0, $t9
    ctx->r4 = ADD32(ctx->r8, ctx->r25);
    // 0x80076F7C: jal         0x800773D4
    // 0x80076F80: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    dmacopy_v1(rdram, ctx);
        goto after_2;
    // 0x80076F80: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_2:
    // 0x80076F84: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076F88: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x80076F8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80076F90: jal         0x800C9390
    // 0x80076F94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80076F94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80076F98: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80076F9C: nop

L_80076FA0:
    // 0x80076FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076FA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80076FA8: jr          $ra
    // 0x80076FAC: nop

    return;
    // 0x80076FAC: nop

;}
RECOMP_FUNC void sprintfSetSpacingCodes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4F68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B4F6C: jr          $ra
    // 0x800B4F70: sw          $a0, 0x3480($at)
    MEM_W(0X3480, ctx->r1) = ctx->r4;
    return;
    // 0x800B4F70: sw          $a0, 0x3480($at)
    MEM_W(0X3480, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void light_setup_light_sources(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F758: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000F75C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000F760: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000F764: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000F768: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000F76C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000F770: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000F774: lw          $s0, 0x40($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X40);
    // 0x8000F778: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000F77C: lb          $t6, 0x5A($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X5A);
    // 0x8000F780: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000F784: blez        $t6, L_8000F7CC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000F788: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8000F7CC;
    }
    // 0x8000F788: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000F78C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8000F790:
    // 0x8000F790: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x8000F794: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F798: jal         0x80031FC8
    // 0x8000F79C: addu        $a1, $t7, $s3
    ctx->r5 = ADD32(ctx->r15, ctx->r19);
    light_add_from_object_header(rdram, ctx);
        goto after_0;
    // 0x8000F79C: addu        $a1, $t7, $s3
    ctx->r5 = ADD32(ctx->r15, ctx->r19);
    after_0:
    // 0x8000F7A0: lw          $t8, 0x70($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X70);
    // 0x8000F7A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000F7A8: addu        $t9, $t8, $s4
    ctx->r25 = ADD32(ctx->r24, ctx->r20);
    // 0x8000F7AC: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8000F7B0: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000F7B4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8000F7B8: lb          $t0, 0x5A($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X5A);
    // 0x8000F7BC: addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    // 0x8000F7C0: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000F7C4: bne         $at, $zero, L_8000F790
    if (ctx->r1 != 0) {
        // 0x8000F7C8: nop
    
            goto L_8000F790;
    }
    // 0x8000F7C8: nop

L_8000F7CC:
    // 0x8000F7CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000F7D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000F7D4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F7D8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000F7DC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000F7E0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000F7E4: jr          $ra
    // 0x8000F7E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000F7E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void render_racer_shield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013A0C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80013A10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80013A14: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80013A18: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80013A1C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80013A20: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80013A24: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80013A28: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80013A2C: lw          $t0, 0x64($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X64);
    // 0x80013A30: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80013A34: lh          $t7, 0x18E($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X18E);
    // 0x80013A38: addiu       $s0, $s0, -0x3334
    ctx->r16 = ADD32(ctx->r16, -0X3334);
    // 0x80013A3C: blez        $t7, L_80013DBC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80013A40: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80013DBC;
    }
    // 0x80013A40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013A44: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80013A48: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80013A4C: beq         $t8, $zero, L_80013DBC
    if (ctx->r24 == 0) {
        // 0x80013A50: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80013DBC;
    }
    // 0x80013A50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013A54: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80013A58: addiu       $s1, $s1, -0x4BF4
    ctx->r17 = ADD32(ctx->r17, -0X4BF4);
    // 0x80013A5C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80013A60: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80013A64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80013A68: sw          $t3, -0x4BF0($at)
    MEM_W(-0X4BF0, ctx->r1) = ctx->r11;
    // 0x80013A6C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80013A70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80013A74: sw          $t5, -0x4BEC($at)
    MEM_W(-0X4BEC, ctx->r1) = ctx->r13;
    // 0x80013A78: lb          $a2, 0x2($t0)
    ctx->r6 = MEM_B(ctx->r8, 0X2);
    // 0x80013A7C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80013A80: slti        $at, $a2, 0xB
    ctx->r1 = SIGNED(ctx->r6) < 0XB ? 1 : 0;
    // 0x80013A84: bne         $at, $zero, L_80013A90
    if (ctx->r1 != 0) {
        // 0x80013A88: nop
    
            goto L_80013A90;
    }
    // 0x80013A88: nop

    // 0x80013A8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80013A90:
    // 0x80013A90: lb          $a1, 0x1D6($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X1D6);
    // 0x80013A94: nop

    // 0x80013A98: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80013A9C: bne         $at, $zero, L_80013AA8
    if (ctx->r1 != 0) {
        // 0x80013AA0: nop
    
            goto L_80013AA8;
    }
    // 0x80013AA0: nop

    // 0x80013AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80013AA8:
    // 0x80013AA8: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x80013AAC: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x80013AB0: jal         0x8001E2D0
    // 0x80013AB4: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80013AB4: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    after_0:
    // 0x80013AB8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80013ABC: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80013AC0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80013AC4: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80013AC8: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80013ACC: addu        $a1, $t6, $a2
    ctx->r5 = ADD32(ctx->r14, ctx->r6);
    // 0x80013AD0: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x80013AD4: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x80013AD8: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80013ADC: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80013AE0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80013AE4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80013AE8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80013AEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80013AF0: addiu       $t5, $t5, -0x4A70
    ctx->r13 = ADD32(ctx->r13, -0X4A70);
    // 0x80013AF4: addu        $a3, $a2, $t5
    ctx->r7 = ADD32(ctx->r6, ctx->r13);
    // 0x80013AF8: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
    // 0x80013AFC: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
    // 0x80013B00: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80013B04: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80013B08: nop

    // 0x80013B0C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80013B10: swc1        $f10, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f10.u32l;
    // 0x80013B14: lh          $t3, 0x4($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X4);
    // 0x80013B18: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80013B1C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80013B20: nop

    // 0x80013B24: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80013B28: swc1        $f18, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f18.u32l;
    // 0x80013B2C: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x80013B30: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80013B34: sll         $t7, $t6, 25
    ctx->r15 = S32(ctx->r14 << 25);
    // 0x80013B38: jal         0x80070A04
    // 0x80013B3C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    sins_f(rdram, ctx);
        goto after_1;
    // 0x80013B3C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_1:
    // 0x80013B40: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80013B44: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013B48: lh          $t1, 0x6($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X6);
    // 0x80013B4C: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80013B50: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80013B54: nop

    // 0x80013B58: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80013B5C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80013B60: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80013B64: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x80013B68: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80013B6C: nop

    // 0x80013B70: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80013B74: nop

    // 0x80013B78: sll         $t4, $t3, 26
    ctx->r12 = S32(ctx->r11 << 26);
    // 0x80013B7C: jal         0x80070A38
    // 0x80013B80: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    coss_f(rdram, ctx);
        goto after_2;
    // 0x80013B80: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_2:
    // 0x80013B84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013B88: lwc1        $f18, 0x5AFC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5AFC);
    // 0x80013B8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013B90: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80013B94: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x80013B98: lwc1        $f8, 0x5B00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5B00);
    // 0x80013B9C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80013BA0: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80013BA4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80013BA8: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80013BAC: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80013BB0: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
    // 0x80013BB4: swc1        $f10, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f10.u32l;
    // 0x80013BB8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80013BBC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80013BC0: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80013BC4: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80013BC8: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x80013BCC: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    // 0x80013BD0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80013BD4: mul.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80013BD8: sh          $t2, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r10;
    // 0x80013BDC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80013BE0: nop

    // 0x80013BE4: sh          $zero, 0x4($t4)
    MEM_H(0X4, ctx->r12) = 0;
    // 0x80013BE8: lb          $a0, 0x189($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X189);
    // 0x80013BEC: nop

    // 0x80013BF0: beq         $a0, $zero, L_80013C00
    if (ctx->r4 == 0) {
        // 0x80013BF4: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_80013C00;
    }
    // 0x80013BF4: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80013BF8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80013BFC: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
L_80013C00:
    // 0x80013C00: bne         $at, $zero, L_80013C0C
    if (ctx->r1 != 0) {
        // 0x80013C04: nop
    
            goto L_80013C0C;
    }
    // 0x80013C04: nop

    // 0x80013C08: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80013C0C:
    // 0x80013C0C: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x80013C10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013C14: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80013C18: lwc1        $f5, 0x5B08($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5B08);
    // 0x80013C1C: lwc1        $f4, 0x5B0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B0C);
    // 0x80013C20: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80013C24: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80013C28: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80013C2C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80013C30: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80013C34: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013C38: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80013C3C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80013C40: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x80013C44: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80013C48: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80013C4C: addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // 0x80013C50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80013C54: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80013C58: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013C5C: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80013C60: lw          $t5, 0x68($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X68);
    // 0x80013C64: nop

    // 0x80013C68: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80013C6C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80013C70: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80013C74: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80013C78: nop

    // 0x80013C7C: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x80013C80: lb          $t9, 0x1F($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X1F);
    // 0x80013C84: nop

    // 0x80013C88: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80013C8C: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x80013C90: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80013C94: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80013C98: sw          $t3, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r11;
    // 0x80013C9C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80013CA0: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x80013CA4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80013CA8: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80013CAC: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80013CB0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80013CB4: lh          $t6, 0x18E($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X18E);
    // 0x80013CB8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80013CBC: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x80013CC0: beq         $at, $zero, L_80013CF8
    if (ctx->r1 == 0) {
        // 0x80013CC4: nop
    
            goto L_80013CF8;
    }
    // 0x80013CC4: nop

    // 0x80013CC8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80013CCC: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80013CD0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80013CD4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80013CD8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80013CDC: lh          $t9, 0x18E($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X18E);
    // 0x80013CE0: nop

    // 0x80013CE4: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80013CE8: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80013CEC: or          $t3, $t2, $a3
    ctx->r11 = ctx->r10 | ctx->r7;
    // 0x80013CF0: b           L_80013D10
    // 0x80013CF4: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
        goto L_80013D10;
    // 0x80013CF4: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
L_80013CF8:
    // 0x80013CF8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80013CFC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80013D00: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80013D04: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80013D08: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80013D0C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_80013D10:
    // 0x80013D10: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80013D14: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80013D18: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x80013D1C: jal         0x800691E8
    // 0x80013D20: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    mtx_shear_push(rdram, ctx);
        goto after_3;
    // 0x80013D20: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    after_3:
    // 0x80013D24: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80013D28: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80013D2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80013D30: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80013D34: jal         0x800143A8
    // 0x80013D38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    render_mesh(rdram, ctx);
        goto after_4;
    // 0x80013D38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80013D3C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80013D40: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80013D44: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80013D48: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80013D4C: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x80013D50: ori         $t8, $t8, 0xA
    ctx->r24 = ctx->r24 | 0XA;
    // 0x80013D54: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80013D58: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80013D5C: lh          $t9, 0x18E($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X18E);
    // 0x80013D60: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80013D64: slti        $at, $t9, 0x40
    ctx->r1 = SIGNED(ctx->r25) < 0X40 ? 1 : 0;
    // 0x80013D68: beq         $at, $zero, L_80013D88
    if (ctx->r1 == 0) {
        // 0x80013D6C: nop
    
            goto L_80013D88;
    }
    // 0x80013D6C: nop

    // 0x80013D70: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80013D74: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80013D78: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80013D7C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80013D80: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80013D84: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_80013D88:
    // 0x80013D88: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80013D8C: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x80013D90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80013D94: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80013D98: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80013D9C: lw          $t6, -0x4BF0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BF0);
    // 0x80013DA0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80013DA4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80013DA8: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80013DAC: lw          $t8, -0x4BEC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BEC);
    // 0x80013DB0: nop

    // 0x80013DB4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80013DB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80013DBC:
    // 0x80013DBC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80013DC0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80013DC4: jr          $ra
    // 0x80013DC8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80013DC8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void fileselect_input_erase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E134: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008E138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E13C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008E140: jal         0x8006A794
    // 0x8008E144: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8008E144: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8008E148: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008E14C: lw          $t6, -0x5C4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C4);
    // 0x8008E150: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008E154: lb          $a1, 0x69FC($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X69FC);
    // 0x8008E158: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008E15C: bne         $t6, $at, L_8008E18C
    if (ctx->r14 != ctx->r1) {
        // 0x8008E160: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008E18C;
    }
    // 0x8008E160: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008E164: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008E168: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008E16C: jal         0x8006A794
    // 0x8008E170: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8008E170: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x8008E174: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008E178: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8008E17C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008E180: lb          $t7, 0x69FD($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X69FD);
    // 0x8008E184: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008E188: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
L_8008E18C:
    // 0x8008E18C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008E190: lw          $t8, 0x6A34($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A34);
    // 0x8008E194: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x8008E198: bne         $t8, $zero, L_8008E270
    if (ctx->r24 != 0) {
        // 0x8008E19C: andi        $t7, $v1, 0x9000
        ctx->r15 = ctx->r3 & 0X9000;
            goto L_8008E270;
    }
    // 0x8008E19C: andi        $t7, $v1, 0x9000
    ctx->r15 = ctx->r3 & 0X9000;
    // 0x8008E1A0: beq         $t9, $zero, L_8008E1C0
    if (ctx->r25 == 0) {
        // 0x8008E1A4: andi        $t0, $v1, 0x9000
        ctx->r8 = ctx->r3 & 0X9000;
            goto L_8008E1C0;
    }
    // 0x8008E1A4: andi        $t0, $v1, 0x9000
    ctx->r8 = ctx->r3 & 0X9000;
    // 0x8008E1A8: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008E1AC: jal         0x80001D04
    // 0x8008E1B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008E1B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8008E1B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E1B8: b           L_8008E318
    // 0x8008E1BC: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
        goto L_8008E318;
    // 0x8008E1BC: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
L_8008E1C0:
    // 0x8008E1C0: beq         $t0, $zero, L_8008E220
    if (ctx->r8 == 0) {
        // 0x8008E1C4: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8008E220;
    }
    // 0x8008E1C4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008E1C8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008E1CC: addiu       $a2, $a2, 0x6A2C
    ctx->r6 = ADD32(ctx->r6, 0X6A2C);
    // 0x8008E1D0: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8008E1D4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008E1D8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8008E1DC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8008E1E0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008E1E4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8008E1E8: lbu         $t3, 0x6A41($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X6A41);
    // 0x8008E1EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008E1F0: beq         $t3, $zero, L_8008E210
    if (ctx->r11 == 0) {
        // 0x8008E1F4: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8008E210;
    }
    // 0x8008E1F4: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008E1F8: jal         0x80001D04
    // 0x8008E1FC: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    sound_play(rdram, ctx);
        goto after_3;
    // 0x8008E1FC: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    after_3:
    // 0x8008E200: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008E204: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E208: b           L_8008E318
    // 0x8008E20C: sw          $t4, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = ctx->r12;
        goto L_8008E318;
    // 0x8008E20C: sw          $t4, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = ctx->r12;
L_8008E210:
    // 0x8008E210: jal         0x80001D04
    // 0x8008E214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8008E214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8008E218: b           L_8008E31C
    // 0x8008E21C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008E31C;
    // 0x8008E21C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008E220:
    // 0x8008E220: addiu       $a2, $a2, 0x6A2C
    ctx->r6 = ADD32(ctx->r6, 0X6A2C);
    // 0x8008E224: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8008E228: bgez        $a1, L_8008E240
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8008E22C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8008E240;
    }
    // 0x8008E22C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008E230: blez        $v1, L_8008E240
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8008E234: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_8008E240;
    }
    // 0x8008E234: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x8008E238: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8008E23C: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
L_8008E240:
    // 0x8008E240: blez        $a1, L_8008E258
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8008E244: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8008E258;
    }
    // 0x8008E244: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8008E248: beq         $at, $zero, L_8008E258
    if (ctx->r1 == 0) {
        // 0x8008E24C: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_8008E258;
    }
    // 0x8008E24C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8008E250: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8008E254: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8008E258:
    // 0x8008E258: beq         $v0, $v1, L_8008E318
    if (ctx->r2 == ctx->r3) {
        // 0x8008E25C: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8008E318;
    }
    // 0x8008E25C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008E260: jal         0x80001D04
    // 0x8008E264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8008E264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8008E268: b           L_8008E31C
    // 0x8008E26C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008E31C;
    // 0x8008E26C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008E270:
    // 0x8008E270: beq         $t7, $zero, L_8008E2FC
    if (ctx->r15 == 0) {
        // 0x8008E274: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008E2FC;
    }
    // 0x8008E274: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008E278: jal         0x80001D04
    // 0x8008E27C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8008E27C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8008E280: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008E284: addiu       $a2, $a2, 0x6A2C
    ctx->r6 = ADD32(ctx->r6, 0X6A2C);
    // 0x8008E288: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8008E28C: jal         0x8006EEEC
    // 0x8008E290: nop

    mark_save_file_to_erase(rdram, ctx);
        goto after_7;
    // 0x8008E290: nop

    after_7:
    // 0x8008E294: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008E298: addiu       $a2, $a2, 0x6A2C
    ctx->r6 = ADD32(ctx->r6, 0X6A2C);
    // 0x8008E29C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8008E2A0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008E2A4: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8008E2A8: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x8008E2AC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008E2B0: addiu       $t9, $t9, 0x6A40
    ctx->r25 = ADD32(ctx->r25, 0X6A40);
    // 0x8008E2B4: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8008E2B8: addiu       $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
    // 0x8008E2BC: addiu       $t1, $zero, 0x4B
    ctx->r9 = ADD32(0, 0X4B);
    // 0x8008E2C0: addiu       $t2, $zero, 0x52
    ctx->r10 = ADD32(0, 0X52);
    // 0x8008E2C4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008E2C8: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x8008E2CC: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8008E2D0: sb          $t0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r8;
    // 0x8008E2D4: sb          $t1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r9;
    // 0x8008E2D8: sb          $t2, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r10;
    // 0x8008E2DC: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    // 0x8008E2E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E2E4: sw          $v1, -0x5B4($at)
    MEM_W(-0X5B4, ctx->r1) = ctx->r3;
    // 0x8008E2E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E2EC: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x8008E2F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E2F4: b           L_8008E318
    // 0x8008E2F8: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
        goto L_8008E318;
    // 0x8008E2F8: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
L_8008E2FC:
    // 0x8008E2FC: andi        $t3, $v1, 0x4000
    ctx->r11 = ctx->r3 & 0X4000;
    // 0x8008E300: beq         $t3, $zero, L_8008E318
    if (ctx->r11 == 0) {
        // 0x8008E304: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8008E318;
    }
    // 0x8008E304: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008E308: jal         0x80001D04
    // 0x8008E30C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x8008E30C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8008E310: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E314: sw          $zero, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = 0;
L_8008E318:
    // 0x8008E318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008E31C:
    // 0x8008E31C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008E320: jr          $ra
    // 0x8008E324: nop

    return;
    // 0x8008E324: nop

;}
RECOMP_FUNC void obj_init_infopoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038894: lbu         $t6, 0x9($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X9);
    // 0x80038898: addiu       $t7, $zero, 0x21
    ctx->r15 = ADD32(0, 0X21);
    // 0x8003889C: beq         $t6, $zero, L_800388B0
    if (ctx->r14 == 0) {
        // 0x800388A0: nop
    
            goto L_800388B0;
    }
    // 0x800388A0: nop

    // 0x800388A4: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x800388A8: b           L_800388BC
    // 0x800388AC: sh          $t7, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r15;
        goto L_800388BC;
    // 0x800388AC: sh          $t7, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r15;
L_800388B0:
    // 0x800388B0: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x800388B4: addiu       $t9, $zero, 0x22
    ctx->r25 = ADD32(0, 0X22);
    // 0x800388B8: sh          $t9, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r25;
L_800388BC:
    // 0x800388BC: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x800388C0: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800388C4: sb          $zero, 0x11($t1)
    MEM_B(0X11, ctx->r9) = 0;
    // 0x800388C8: lw          $t3, 0x4C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4C);
    // 0x800388CC: nop

    // 0x800388D0: sb          $t2, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r10;
    // 0x800388D4: lw          $t4, 0x4C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4C);
    // 0x800388D8: nop

    // 0x800388DC: sb          $zero, 0x12($t4)
    MEM_B(0X12, ctx->r12) = 0;
    // 0x800388E0: lbu         $t6, 0xA($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XA);
    // 0x800388E4: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x800388E8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800388EC: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800388F0: sw          $t8, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r24;
    // 0x800388F4: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x800388F8: nop

    // 0x800388FC: sw          $t9, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r25;
    // 0x80038900: lbu         $t0, 0xB($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XB);
    // 0x80038904: nop

    // 0x80038908: sll         $t1, $t0, 10
    ctx->r9 = S32(ctx->r8 << 10);
    // 0x8003890C: jr          $ra
    // 0x80038910: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    return;
    // 0x80038910: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void set_delayed_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C36B0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800C36B4: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800C36B8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C36BC: bne         $t6, $zero, L_800C3700
    if (ctx->r14 != 0) {
        // 0x800C36C0: lui         $at, 0x404E
        ctx->r1 = S32(0X404E << 16);
            goto L_800C3700;
    }
    // 0x800C36C0: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x800C36C4: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800C36C8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C36CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C36D0: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800C36D4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800C36D8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800C36DC: nop

    // 0x800C36E0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800C36E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C36E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C36EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C36F0: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C36F4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C36F8: b           L_800C3738
    // 0x800C36FC: swc1        $f10, 0x3C08($at)
    MEM_W(0X3C08, ctx->r1) = ctx->f10.u32l;
        goto L_800C3738;
    // 0x800C36FC: swc1        $f10, 0x3C08($at)
    MEM_W(0X3C08, ctx->r1) = ctx->f10.u32l;
L_800C3700:
    // 0x800C3700: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800C3704: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C3708: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x800C370C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800C3710: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C3714: nop

    // 0x800C3718: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800C371C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C3720: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C3724: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C3728: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800C372C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C3730: swc1        $f6, 0x3C08($at)
    MEM_W(0X3C08, ctx->r1) = ctx->f6.u32l;
    // 0x800C3734: nop

L_800C3738:
    // 0x800C3738: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C373C: jr          $ra
    // 0x800C3740: sw          $a0, 0x3C0C($at)
    MEM_W(0X3C0C, ctx->r1) = ctx->r4;
    return;
    // 0x800C3740: sw          $a0, 0x3C0C($at)
    MEM_W(0X3C0C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void music_volume_config(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001AFC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001B00: lw          $v0, -0x343C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X343C);
    // 0x80001B04: jr          $ra
    // 0x80001B08: nop

    return;
    // 0x80001B08: nop

;}
RECOMP_FUNC void charselect_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C5E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C5E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C5E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C5EC: jal         0x8009C9EC
    // 0x8008C5F0: addiu       $a0, $a0, 0x348
    ctx->r4 = ADD32(ctx->r4, 0X348);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x8008C5F0: addiu       $a0, $a0, 0x348
    ctx->r4 = ADD32(ctx->r4, 0X348);
    after_0:
    // 0x8008C5F4: jal         0x800712F0
    // 0x8008C5F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_1;
    // 0x8008C5F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8008C5FC: jal         0x800C478C
    // 0x8008C600: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_2;
    // 0x8008C600: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8008C604: jal         0x800712F0
    // 0x8008C608: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_3;
    // 0x8008C608: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x8008C60C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C610: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C614: sw          $zero, 0x550($at)
    MEM_W(0X550, ctx->r1) = 0;
    // 0x8008C618: jr          $ra
    // 0x8008C61C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008C61C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ttcam_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027928: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8002792C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80027930: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80027934: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80027938: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002793C: jal         0x8001BAA8
    // 0x80027940: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x80027940: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x80027944: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80027948: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002794C: blez        $t6, L_80027A14
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80027950: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80027A14;
    }
    // 0x80027950: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80027954: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80027958:
    // 0x80027958: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002795C: nop

    // 0x80027960: beq         $v0, $zero, L_80027A04
    if (ctx->r2 == 0) {
        // 0x80027964: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_80027A04;
    }
    // 0x80027964: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80027968: lw          $s1, 0x64($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X64);
    // 0x8002796C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80027970: lb          $t7, 0x1FD($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X1FD);
    // 0x80027974: nop

    // 0x80027978: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8002797C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80027980: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80027984: jal         0x8001BE08
    // 0x80027988: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    spectate_nearest(rdram, ctx);
        goto after_1;
    // 0x80027988: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_1:
    // 0x8002798C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80027990: lb          $t9, 0x1D8($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X1D8);
    // 0x80027994: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80027998: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8002799C: beq         $t9, $zero, L_800279C4
    if (ctx->r25 == 0) {
        // 0x800279A0: sb          $t8, 0x1FD($s1)
        MEM_B(0X1FD, ctx->r17) = ctx->r24;
            goto L_800279C4;
    }
    // 0x800279A0: sb          $t8, 0x1FD($s1)
    MEM_B(0X1FD, ctx->r17) = ctx->r24;
    // 0x800279A4: lh          $t0, 0x1AC($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X1AC);
    // 0x800279A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800279AC: bne         $t0, $at, L_80027A04
    if (ctx->r8 != ctx->r1) {
        // 0x800279B0: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_80027A04;
    }
    // 0x800279B0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800279B4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800279B8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800279BC: b           L_80027A00
    // 0x800279C0: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
        goto L_80027A00;
    // 0x800279C0: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
L_800279C4:
    // 0x800279C4: bne         $v1, $zero, L_800279DC
    if (ctx->r3 != 0) {
        // 0x800279C8: nop
    
            goto L_800279DC;
    }
    // 0x800279C8: nop

    // 0x800279CC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800279D0: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x800279D4: b           L_80027A00
    // 0x800279D8: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
        goto L_80027A00;
    // 0x800279D8: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
L_800279DC:
    // 0x800279DC: lh          $t3, 0x1AE($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X1AE);
    // 0x800279E0: lh          $t4, 0x1AE($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X1AE);
    // 0x800279E4: nop

    // 0x800279E8: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800279EC: beq         $at, $zero, L_80027A04
    if (ctx->r1 == 0) {
        // 0x800279F0: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_80027A04;
    }
    // 0x800279F0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800279F4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800279F8: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x800279FC: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
L_80027A00:
    // 0x80027A00: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_80027A04:
    // 0x80027A04: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80027A08: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80027A0C: bne         $at, $zero, L_80027958
    if (ctx->r1 != 0) {
        // 0x80027A10: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80027958;
    }
    // 0x80027A10: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80027A14:
    // 0x80027A14: beq         $v1, $zero, L_80027A2C
    if (ctx->r3 == 0) {
        // 0x80027A18: lw          $s1, 0x3C($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X3C);
            goto L_80027A2C;
    }
    // 0x80027A18: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80027A1C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80027A20: b           L_80027A34
    // 0x80027A24: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
        goto L_80027A34;
    // 0x80027A24: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80027A28: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
L_80027A2C:
    // 0x80027A2C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80027A30: nop

L_80027A34:
    // 0x80027A34: lb          $a0, 0x1FD($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X1FD);
    // 0x80027A38: jal         0x8001BDC8
    // 0x80027A3C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    spectate_object(rdram, ctx);
        goto after_2;
    // 0x80027A3C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_2:
    // 0x80027A40: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80027A44: lw          $t7, -0x497C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X497C);
    // 0x80027A48: lb          $t8, 0x1FD($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X1FD);
    // 0x80027A4C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80027A50: beq         $t7, $t8, L_80027A68
    if (ctx->r15 == ctx->r24) {
        // 0x80027A54: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80027A68;
    }
    // 0x80027A54: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80027A58: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027A5C: addiu       $a3, $a3, -0x4978
    ctx->r7 = ADD32(ctx->r7, -0X4978);
    // 0x80027A60: b           L_80027A9C
    // 0x80027A64: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
        goto L_80027A9C;
    // 0x80027A64: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80027A68:
    // 0x80027A68: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80027A6C: addiu       $v1, $v1, -0x4980
    ctx->r3 = ADD32(ctx->r3, -0X4980);
    // 0x80027A70: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80027A74: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    // 0x80027A78: nop

    // 0x80027A7C: beq         $t9, $t0, L_80027A9C
    if (ctx->r25 == ctx->r8) {
        // 0x80027A80: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80027A9C;
    }
    // 0x80027A80: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027A84: addiu       $a3, $a3, -0x4978
    ctx->r7 = ADD32(ctx->r7, -0X4978);
    // 0x80027A88: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
    // 0x80027A8C: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80027A90: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    // 0x80027A94: nop

    // 0x80027A98: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_80027A9C:
    // 0x80027A9C: beq         $v0, $zero, L_80027E54
    if (ctx->r2 == 0) {
        // 0x80027AA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80027E54;
    }
    // 0x80027AA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80027AA4: jal         0x80069F3C
    // 0x80027AA8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_3;
    // 0x80027AA8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_3:
    // 0x80027AAC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80027AB0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80027AB4: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x80027AB8: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027ABC: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80027AC0: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x80027AC4: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027AC8: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80027ACC: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x80027AD0: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80027AD4: lwc1        $f16, 0xC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80027AD8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80027ADC: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80027AE0: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x80027AE4: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80027AE8: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80027AEC: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80027AF0: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80027AF4: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x80027AF8: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x80027AFC: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80027B00: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80027B04: jal         0x800CA030
    // 0x80027B08: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x80027B08: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_4:
    // 0x80027B0C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027B10: addiu       $a3, $a3, -0x4978
    ctx->r7 = ADD32(ctx->r7, -0X4978);
    // 0x80027B14: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80027B18: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027B1C: lwc1        $f2, 0x68($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80027B20: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80027B24: beq         $t3, $zero, L_80027D58
    if (ctx->r11 == 0) {
        // 0x80027B28: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_80027D58;
    }
    // 0x80027B28: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80027B2C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80027B30: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80027B34: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80027B38: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027B3C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027B40: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    // 0x80027B44: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80027B48: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80027B4C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80027B50: nop

    // 0x80027B54: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80027B58: nop

    // 0x80027B5C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80027B60: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027B64: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027B68: nop

    // 0x80027B6C: cvt.w.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = CVT_W_S(ctx->f14.fl);
    // 0x80027B70: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80027B74: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80027B78: jal         0x800708AC
    // 0x80027B7C: nop

    atan2s(rdram, ctx);
        goto after_5;
    // 0x80027B7C: nop

    after_5:
    // 0x80027B80: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027B84: negu        $t6, $v0
    ctx->r14 = SUB32(0, ctx->r2);
    // 0x80027B88: lh          $a2, 0x0($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X0);
    // 0x80027B8C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80027B90: subu        $s0, $t6, $a2
    ctx->r16 = SUB32(ctx->r14, ctx->r6);
    // 0x80027B94: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
    // 0x80027B98: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x80027B9C: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80027BA0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80027BA4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027BA8: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80027BAC: slt         $at, $t8, $at
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80027BB0: addiu       $a3, $a3, -0x4978
    ctx->r7 = ADD32(ctx->r7, -0X4978);
    // 0x80027BB4: bne         $at, $zero, L_80027BD4
    if (ctx->r1 != 0) {
        // 0x80027BB8: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_80027BD4;
    }
    // 0x80027BB8: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80027BBC: lui         $t0, 0xFFFF
    ctx->r8 = S32(0XFFFF << 16);
    // 0x80027BC0: ori         $t0, $t0, 0x1
    ctx->r8 = ctx->r8 | 0X1;
    // 0x80027BC4: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80027BC8: subu        $s0, $t0, $t9
    ctx->r16 = SUB32(ctx->r8, ctx->r25);
    // 0x80027BCC: sll         $t1, $s0, 16
    ctx->r9 = S32(ctx->r16 << 16);
    // 0x80027BD0: sra         $s0, $t1, 16
    ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
L_80027BD4:
    // 0x80027BD4: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80027BD8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80027BDC: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80027BE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80027BE4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80027BE8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80027BEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80027BF0: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80027BF4: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80027BF8: nop

    // 0x80027BFC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80027C00: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80027C04: nop

    // 0x80027C08: div.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80027C0C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80027C10: nop

    // 0x80027C14: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80027C18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027C1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027C20: nop

    // 0x80027C24: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80027C28: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80027C2C: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80027C30: nop

    // 0x80027C34: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80027C38: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x80027C3C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80027C40: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x80027C44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027C48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027C4C: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80027C50: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80027C54: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80027C58: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80027C5C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80027C60: nop

    // 0x80027C64: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80027C68: nop

    // 0x80027C6C: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80027C70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027C74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027C78: nop

    // 0x80027C7C: cvt.w.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80027C80: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80027C84: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80027C88: jal         0x800708AC
    // 0x80027C8C: nop

    atan2s(rdram, ctx);
        goto after_6;
    // 0x80027C8C: nop

    after_6:
    // 0x80027C90: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027C94: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80027C98: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x80027C9C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027CA0: subu        $s0, $v0, $a0
    ctx->r16 = SUB32(ctx->r2, ctx->r4);
    // 0x80027CA4: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x80027CA8: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80027CAC: slt         $at, $t1, $at
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80027CB0: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x80027CB4: bne         $at, $zero, L_80027CD4
    if (ctx->r1 != 0) {
        // 0x80027CB8: addiu       $a3, $a3, -0x4978
        ctx->r7 = ADD32(ctx->r7, -0X4978);
            goto L_80027CD4;
    }
    // 0x80027CB8: addiu       $a3, $a3, -0x4978
    ctx->r7 = ADD32(ctx->r7, -0X4978);
    // 0x80027CBC: lui         $t3, 0xFFFF
    ctx->r11 = S32(0XFFFF << 16);
    // 0x80027CC0: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x80027CC4: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x80027CC8: subu        $s0, $t3, $t2
    ctx->r16 = SUB32(ctx->r11, ctx->r10);
    // 0x80027CCC: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80027CD0: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
L_80027CD4:
    // 0x80027CD4: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80027CD8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80027CDC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80027CE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80027CE4: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80027CE8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80027CEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80027CF0: div.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80027CF4: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x80027CF8: nop

    // 0x80027CFC: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80027D00: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80027D04: nop

    // 0x80027D08: div.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80027D0C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80027D10: nop

    // 0x80027D14: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80027D18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027D1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027D20: nop

    // 0x80027D24: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80027D28: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80027D2C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80027D30: addu        $t9, $a0, $t0
    ctx->r25 = ADD32(ctx->r4, ctx->r8);
    // 0x80027D34: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x80027D38: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80027D3C: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80027D40: nop

    // 0x80027D44: subu        $t2, $t1, $t3
    ctx->r10 = SUB32(ctx->r9, ctx->r11);
    // 0x80027D48: bgez        $t2, L_80027E20
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80027D4C: sw          $t2, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r10;
            goto L_80027E20;
    }
    // 0x80027D4C: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80027D50: b           L_80027E20
    // 0x80027D54: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
        goto L_80027E20;
    // 0x80027D54: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80027D58:
    // 0x80027D58: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80027D5C: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80027D60: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80027D64: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027D68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027D6C: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    // 0x80027D70: cvt.w.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80027D74: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80027D78: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80027D7C: nop

    // 0x80027D80: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80027D84: nop

    // 0x80027D88: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80027D8C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027D90: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027D94: nop

    // 0x80027D98: cvt.w.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = CVT_W_S(ctx->f14.fl);
    // 0x80027D9C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80027DA0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80027DA4: jal         0x800708AC
    // 0x80027DA8: nop

    atan2s(rdram, ctx);
        goto after_7;
    // 0x80027DA8: nop

    after_7:
    // 0x80027DAC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80027DB0: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027DB4: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80027DB8: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80027DBC: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x80027DC0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80027DC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027DC8: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80027DCC: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80027DD0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027DD4: nop

    // 0x80027DD8: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80027DDC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80027DE0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80027DE4: nop

    // 0x80027DE8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80027DEC: nop

    // 0x80027DF0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80027DF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027DF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027DFC: nop

    // 0x80027E00: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80027E04: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80027E08: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80027E0C: jal         0x800708AC
    // 0x80027E10: nop

    atan2s(rdram, ctx);
        goto after_8;
    // 0x80027E10: nop

    after_8:
    // 0x80027E14: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027E18: nop

    // 0x80027E1C: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
L_80027E20:
    // 0x80027E20: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x80027E24: lwc1        $f14, 0x3C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80027E28: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80027E2C: lw          $a2, 0x14($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X14);
    // 0x80027E30: jal         0x80029F58
    // 0x80027E34: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_9;
    // 0x80027E34: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    after_9:
    // 0x80027E38: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027E3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80027E40: sh          $v0, 0x34($v1)
    MEM_H(0X34, ctx->r3) = ctx->r2;
    // 0x80027E44: lb          $t1, 0x1FD($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1FD);
    // 0x80027E48: nop

    // 0x80027E4C: sw          $t1, -0x497C($at)
    MEM_W(-0X497C, ctx->r1) = ctx->r9;
    // 0x80027E50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80027E54:
    // 0x80027E54: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80027E58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80027E5C: jr          $ra
    // 0x80027E60: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80027E60: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void menu_asset_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CA4C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009CA50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009CA54: addiu       $t6, $t6, 0x6CF0
    ctx->r14 = ADD32(ctx->r14, 0X6CF0);
    // 0x8009CA58: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8009CA5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CA60: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8009CA64: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x8009CA68: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8009CA6C: beq         $t9, $zero, L_8009CB48
    if (ctx->r25 == 0) {
        // 0x8009CA70: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8009CB48;
    }
    // 0x8009CA70: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009CA74: addiu       $t1, $t1, 0x6AF0
    ctx->r9 = ADD32(ctx->r9, 0X6AF0);
    // 0x8009CA78: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8009CA7C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8009CA80: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8009CA84: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009CA88: beq         $v0, $zero, L_8009CB20
    if (ctx->r2 == 0) {
        // 0x8009CA8C: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_8009CB20;
    }
    // 0x8009CA8C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8009CA90: lw          $t3, -0x330($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X330);
    // 0x8009CA94: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x8009CA98: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8009CA9C: lh          $v1, 0x0($t5)
    ctx->r3 = MEM_H(ctx->r13, 0X0);
    // 0x8009CAA0: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x8009CAA4: andi        $t6, $v1, 0xC000
    ctx->r14 = ctx->r3 & 0XC000;
    // 0x8009CAA8: bne         $t6, $at, L_8009CAE4
    if (ctx->r14 != ctx->r1) {
        // 0x8009CAAC: andi        $t8, $v1, 0x8000
        ctx->r24 = ctx->r3 & 0X8000;
            goto L_8009CAE4;
    }
    // 0x8009CAAC: andi        $t8, $v1, 0x8000
    ctx->r24 = ctx->r3 & 0X8000;
    // 0x8009CAB0: beq         $v0, $zero, L_8009CAE4
    if (ctx->r2 == 0) {
        // 0x8009CAB4: nop
    
            goto L_8009CAE4;
    }
    // 0x8009CAB4: nop

    // 0x8009CAB8: jal         0x800712F0
    // 0x8009CABC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_0;
    // 0x8009CABC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8009CAC0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8009CAC4: nop

    // 0x8009CAC8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8009CACC: jal         0x8007B70C
    // 0x8009CAD0: nop

    tex_free(rdram, ctx);
        goto after_1;
    // 0x8009CAD0: nop

    after_1:
    // 0x8009CAD4: jal         0x800712F0
    // 0x8009CAD8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_2;
    // 0x8009CAD8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8009CADC: b           L_8009CB20
    // 0x8009CAE0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
        goto L_8009CB20;
    // 0x8009CAE0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_8009CAE4:
    // 0x8009CAE4: beq         $t8, $zero, L_8009CAFC
    if (ctx->r24 == 0) {
        // 0x8009CAE8: andi        $t9, $v1, 0x4000
        ctx->r25 = ctx->r3 & 0X4000;
            goto L_8009CAFC;
    }
    // 0x8009CAE8: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x8009CAEC: jal         0x8007D100
    // 0x8009CAF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sprite_free(rdram, ctx);
        goto after_3;
    // 0x8009CAF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8009CAF4: b           L_8009CB20
    // 0x8009CAF8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
        goto L_8009CB20;
    // 0x8009CAF8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_8009CAFC:
    // 0x8009CAFC: beq         $t9, $zero, L_8009CB14
    if (ctx->r25 == 0) {
        // 0x8009CB00: nop
    
            goto L_8009CB14;
    }
    // 0x8009CB00: nop

    // 0x8009CB04: jal         0x8000FFB8
    // 0x8009CB08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    free_object(rdram, ctx);
        goto after_4;
    // 0x8009CB08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8009CB0C: b           L_8009CB20
    // 0x8009CB10: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
        goto L_8009CB20;
    // 0x8009CB10: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_8009CB14:
    // 0x8009CB14: jal         0x80060180
    // 0x8009CB18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    free_3d_model(rdram, ctx);
        goto after_5;
    // 0x8009CB18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8009CB1C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_8009CB20:
    // 0x8009CB20: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009CB24: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8009CB28: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CB2C: addiu       $v0, $v0, -0x328
    ctx->r2 = ADD32(ctx->r2, -0X328);
    // 0x8009CB30: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x8009CB34: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x8009CB38: nop

    // 0x8009CB3C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8009CB40: jal         0x8001004C
    // 0x8009CB44: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    gParticlePtrList_flush(rdram, ctx);
        goto after_6;
    // 0x8009CB44: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    after_6:
L_8009CB48:
    // 0x8009CB48: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009CB4C: lh          $t4, -0x328($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X328);
    // 0x8009CB50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009CB54: bne         $t4, $zero, L_8009CBAC
    if (ctx->r12 != 0) {
        // 0x8009CB58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8009CBAC;
    }
    // 0x8009CB58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009CB5C: lw          $a0, -0x324($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X324);
    // 0x8009CB60: nop

    // 0x8009CB64: beq         $a0, $zero, L_8009CB7C
    if (ctx->r4 == 0) {
        // 0x8009CB68: nop
    
            goto L_8009CB7C;
    }
    // 0x8009CB68: nop

    // 0x8009CB6C: jal         0x80071380
    // 0x8009CB70: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x8009CB70: nop

    after_7:
    // 0x8009CB74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009CB78: sw          $zero, -0x324($at)
    MEM_W(-0X324, ctx->r1) = 0;
L_8009CB7C:
    // 0x8009CB7C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009CB80: lw          $a0, -0x330($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X330);
    // 0x8009CB84: nop

    // 0x8009CB88: beq         $a0, $zero, L_8009CBAC
    if (ctx->r4 == 0) {
        // 0x8009CB8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8009CBAC;
    }
    // 0x8009CB8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009CB90: jal         0x80071380
    // 0x8009CB94: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x8009CB94: nop

    after_8:
    // 0x8009CB98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009CB9C: sw          $zero, -0x330($at)
    MEM_W(-0X330, ctx->r1) = 0;
    // 0x8009CBA0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009CBA4: sh          $zero, -0x32C($at)
    MEM_H(-0X32C, ctx->r1) = 0;
    // 0x8009CBA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009CBAC:
    // 0x8009CBAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009CBB0: jr          $ra
    // 0x8009CBB4: nop

    return;
    // 0x8009CBB4: nop

;}
RECOMP_FUNC void obj_init_laserbolt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034884: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80034888: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003488C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80034890: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80034894: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80034898: jr          $ra
    // 0x8003489C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    return;
    // 0x8003489C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
;}
RECOMP_FUNC void music_jingle_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800018E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800018E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800018E8: jal         0x80001C08
    // 0x800018EC: nop

    music_jingle_playing(rdram, ctx);
        goto after_0;
    // 0x800018EC: nop

    after_0:
    // 0x800018F0: bne         $v0, $zero, L_80001908
    if (ctx->r2 != 0) {
        // 0x800018F4: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_80001908;
    }
    // 0x800018F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800018F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800018FC: lw          $a0, -0x345C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X345C);
    // 0x80001900: jal         0x80002570
    // 0x80001904: sb          $zero, 0x6285($at)
    MEM_B(0X6285, ctx->r1) = 0;
    music_sequence_stop(rdram, ctx);
        goto after_1;
    // 0x80001904: sb          $zero, 0x6285($at)
    MEM_B(0X6285, ctx->r1) = 0;
    after_1:
L_80001908:
    // 0x80001908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000190C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001910: jr          $ra
    // 0x80001914: nop

    return;
    // 0x80001914: nop

;}
RECOMP_FUNC void hud_main_taj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2B7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A2B80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2B84: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A2B88: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A2B8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A2B90: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A2B94: lw          $s0, 0x64($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X64);
    // 0x800A2B98: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800A2B9C: jal         0x80068748
    // 0x800A2BA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_0;
    // 0x800A2BA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800A2BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2BA8: jal         0x800A5FAC
    // 0x800A2BAC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_wrong_way(rdram, ctx);
        goto after_1;
    // 0x800A2BAC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800A2BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2BB4: jal         0x800A5498
    // 0x800A2BB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_lap_count(rdram, ctx);
        goto after_2;
    // 0x800A2BB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800A2BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2BC0: jal         0x800A518C
    // 0x800A2BC4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_race_position(rdram, ctx);
        goto after_3;
    // 0x800A2BC4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800A2BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2BCC: jal         0x800A80C4
    // 0x800A2BD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_race_time(rdram, ctx);
        goto after_4;
    // 0x800A2BD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x800A2BD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A2BD8: jal         0x800A422C
    // 0x800A2BDC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_race_start(rdram, ctx);
        goto after_5;
    // 0x800A2BDC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800A2BE0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A2BE4: jal         0x800A3DCC
    // 0x800A2BE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_speedometre(rdram, ctx);
        goto after_6;
    // 0x800A2BE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800A2BEC: jal         0x80068748
    // 0x800A2BF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_7;
    // 0x800A2BF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800A2BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2BF8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A2BFC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A2C00: jr          $ra
    // 0x800A2C04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A2C04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void hud_speedometre(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3DCC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A3DD0: lbu         $t6, 0x72F7($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X72F7);
    // 0x800A3DD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A3DD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A3DDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3DE0: bne         $t6, $at, L_800A421C
    if (ctx->r14 != ctx->r1) {
        // 0x800A3DE4: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_800A421C;
    }
    // 0x800A3DE4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800A3DE8: jal         0x80066750
    // 0x800A3DEC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_0;
    // 0x800A3DEC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A3DF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A3DF4: bne         $v0, $zero, L_800A4220
    if (ctx->r2 != 0) {
        // 0x800A3DF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A4220;
    }
    // 0x800A3DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3DFC: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x800A3E00: nop

    // 0x800A3E04: lb          $t7, 0x1D8($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1D8);
    // 0x800A3E08: nop

    // 0x800A3E0C: bne         $t7, $zero, L_800A4220
    if (ctx->r15 != 0) {
        // 0x800A3E10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A4220;
    }
    // 0x800A3E10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3E14: lb          $t8, 0x1D6($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1D6);
    // 0x800A3E18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A3E1C: bne         $t8, $at, L_800A3E5C
    if (ctx->r24 != ctx->r1) {
        // 0x800A3E20: nop
    
            goto L_800A3E5C;
    }
    // 0x800A3E20: nop

    // 0x800A3E24: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800A3E28: lwc1        $f2, 0x20($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800A3E2C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800A3E30: lwc1        $f14, 0x24($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800A3E34: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800A3E38: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800A3E3C: nop

    // 0x800A3E40: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800A3E44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A3E48: jal         0x800CA030
    // 0x800A3E4C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800A3E4C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x800A3E50: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800A3E54: b           L_800A3E80
    // 0x800A3E58: nop

        goto L_800A3E80;
    // 0x800A3E58: nop

L_800A3E5C:
    // 0x800A3E5C: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800A3E60: lwc1        $f14, 0x24($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800A3E64: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800A3E68: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800A3E6C: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800A3E70: jal         0x800CA030
    // 0x800A3E74: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800A3E74: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_2:
    // 0x800A3E78: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800A3E7C: nop

L_800A3E80:
    // 0x800A3E80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A3E84: lwc1        $f4, 0x2DB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2DB8);
    // 0x800A3E88: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800A3E8C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800A3E90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A3E94: bc1f        L_800A3EA0
    if (!c1cs) {
        // 0x800A3E98: nop
    
            goto L_800A3EA0;
    }
    // 0x800A3E98: nop

    // 0x800A3E9C: swc1        $f0, 0x2DB8($at)
    MEM_W(0X2DB8, ctx->r1) = ctx->f0.u32l;
L_800A3EA0:
    // 0x800A3EA0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A3EA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A3EA8: lb          $t9, 0x1E6($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1E6);
    // 0x800A3EAC: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800A3EB0: beq         $t9, $zero, L_800A3EC4
    if (ctx->r25 == 0) {
        // 0x800A3EB4: lui         $at, 0x40E0
        ctx->r1 = S32(0X40E0 << 16);
            goto L_800A3EC4;
    }
    // 0x800A3EB4: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x800A3EB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A3EBC: nop

    // 0x800A3EC0: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
L_800A3EC4:
    // 0x800A3EC4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A3EC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A3ECC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A3ED0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800A3ED4: nop

    // 0x800A3ED8: bc1f        L_800A3EE4
    if (!c1cs) {
        // 0x800A3EDC: nop
    
            goto L_800A3EE4;
    }
    // 0x800A3EDC: nop

    // 0x800A3EE0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800A3EE4:
    // 0x800A3EE4: lwc1        $f10, 0x2C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800A3EE8: nop

    // 0x800A3EEC: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x800A3EF0: nop

    // 0x800A3EF4: bc1f        L_800A3F00
    if (!c1cs) {
        // 0x800A3EF8: nop
    
            goto L_800A3F00;
    }
    // 0x800A3EF8: nop

    // 0x800A3EFC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800A3F00:
    // 0x800A3F00: lwc1        $f12, -0x7340($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7340);
    // 0x800A3F04: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800A3F08: sub.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800A3F0C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A3F10: nop

    // 0x800A3F14: mul.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800A3F18: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800A3F1C: nop

    // 0x800A3F20: bc1f        L_800A3F2C
    if (!c1cs) {
        // 0x800A3F24: nop
    
            goto L_800A3F2C;
    }
    // 0x800A3F24: nop

    // 0x800A3F28: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800A3F2C:
    // 0x800A3F2C: jal         0x8006ECE0
    // 0x800A3F30: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    is_game_paused(rdram, ctx);
        goto after_3;
    // 0x800A3F30: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x800A3F34: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A3F38: bne         $v0, $zero, L_800A3FF4
    if (ctx->r2 != 0) {
        // 0x800A3F3C: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800A3FF4;
    }
    // 0x800A3F3C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A3F40: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A3F44: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A3F48: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800A3F4C: lh          $t0, 0x4C4($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X4C4);
    // 0x800A3F50: nop

    // 0x800A3F54: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800A3F58: nop

    // 0x800A3F5C: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A3F60: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800A3F64: nop

    // 0x800A3F68: bc1f        L_800A3FB4
    if (!c1cs) {
        // 0x800A3F6C: nop
    
            goto L_800A3FB4;
    }
    // 0x800A3F6C: nop

    // 0x800A3F70: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A3F74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A3F78: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800A3F7C: nop

    // 0x800A3F80: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A3F84: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800A3F88: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A3F8C: nop

    // 0x800A3F90: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A3F94: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A3F98: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A3F9C: nop

    // 0x800A3FA0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A3FA4: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x800A3FA8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A3FAC: b           L_800A3FF4
    // 0x800A3FB0: sh          $t2, 0x4C4($v0)
    MEM_H(0X4C4, ctx->r2) = ctx->r10;
        goto L_800A3FF4;
    // 0x800A3FB0: sh          $t2, 0x4C4($v0)
    MEM_H(0X4C4, ctx->r2) = ctx->r10;
L_800A3FB4:
    // 0x800A3FB4: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800A3FB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A3FBC: nop

    // 0x800A3FC0: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A3FC4: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800A3FC8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A3FCC: nop

    // 0x800A3FD0: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A3FD4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A3FD8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A3FDC: nop

    // 0x800A3FE0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A3FE4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800A3FE8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A3FEC: sh          $t4, 0x4C4($v0)
    MEM_H(0X4C4, ctx->r2) = ctx->r12;
    // 0x800A3FF0: nop

L_800A3FF4:
    // 0x800A3FF4: lw          $t5, 0x72CC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72CC);
    // 0x800A3FF8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A3FFC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800A4000: lb          $t6, 0x2D24($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X2D24);
    // 0x800A4004: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A4008: bne         $t6, $zero, L_800A421C
    if (ctx->r14 != 0) {
        // 0x800A400C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A421C;
    }
    // 0x800A400C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4010: lb          $t7, 0x7293($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7293);
    // 0x800A4014: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4018: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800A401C: beq         $t8, $zero, L_800A409C
    if (ctx->r24 == 0) {
        // 0x800A4020: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A409C;
    }
    // 0x800A4020: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4024: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A4028: lb          $t9, 0x7290($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7290);
    // 0x800A402C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A4030: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800A4034: lbu         $t0, 0x774B($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X774B);
    // 0x800A4038: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A403C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A4040: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A4044: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800A4048: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800A404C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800A4050: bgez        $t0, L_800A4064
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800A4054: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800A4064;
    }
    // 0x800A4054: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A4058: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A405C: nop

    // 0x800A4060: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800A4064:
    // 0x800A4064: nop

    // 0x800A4068: div.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800A406C: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800A4070: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A4074: nop

    // 0x800A4078: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A407C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A4080: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A4084: nop

    // 0x800A4088: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A408C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800A4090: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A4094: b           L_800A40A4
    // 0x800A4098: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
        goto L_800A40A4;
    // 0x800A4098: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_800A409C:
    // 0x800A409C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A40A0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
L_800A40A4:
    // 0x800A40A4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A40A8: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A40AC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A40B0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A40B4: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A40B8: jal         0x800AAB5C
    // 0x800A40BC: addiu       $a3, $a3, 0x5A0
    ctx->r7 = ADD32(ctx->r7, 0X5A0);
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A40BC: addiu       $a3, $a3, 0x5A0
    ctx->r7 = ADD32(ctx->r7, 0X5A0);
    after_4:
    // 0x800A40C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A40C4: jal         0x8007B820
    // 0x800A40C8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    rendermode_reset(rdram, ctx);
        goto after_5;
    // 0x800A40C8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_5:
    // 0x800A40CC: jal         0x8007C36C
    // 0x800A40D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_6;
    // 0x800A40D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x800A40D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A40D8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A40DC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A40E0: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800A40E4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800A40E8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800A40EC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800A40F0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800A40F4: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800A40F8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800A40FC: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800A4100: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A4104: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800A4108: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A410C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4110: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4114: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4118: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A411C: jal         0x800AAB5C
    // 0x800A4120: addiu       $a3, $a3, 0x4C0
    ctx->r7 = ADD32(ctx->r7, 0X4C0);
    hud_element_render(rdram, ctx);
        goto after_7;
    // 0x800A4120: addiu       $a3, $a3, 0x4C0
    ctx->r7 = ADD32(ctx->r7, 0X4C0);
    after_7:
    // 0x800A4124: jal         0x8007C36C
    // 0x800A4128: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_8;
    // 0x800A4128: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800A412C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A4130: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A4134: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4138: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A413C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4140: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4144: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4148: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A414C: jal         0x800AAB5C
    // 0x800A4150: addiu       $a3, $a3, 0x4E0
    ctx->r7 = ADD32(ctx->r7, 0X4E0);
    hud_element_render(rdram, ctx);
        goto after_9;
    // 0x800A4150: addiu       $a3, $a3, 0x4E0
    ctx->r7 = ADD32(ctx->r7, 0X4E0);
    after_9:
    // 0x800A4154: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A4158: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A415C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4160: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4164: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4168: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A416C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4170: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4174: jal         0x800AAB5C
    // 0x800A4178: addiu       $a3, $a3, 0x500
    ctx->r7 = ADD32(ctx->r7, 0X500);
    hud_element_render(rdram, ctx);
        goto after_10;
    // 0x800A4178: addiu       $a3, $a3, 0x500
    ctx->r7 = ADD32(ctx->r7, 0X500);
    after_10:
    // 0x800A417C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A4180: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A4184: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4188: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A418C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4190: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4194: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4198: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A419C: jal         0x800AAB5C
    // 0x800A41A0: addiu       $a3, $a3, 0x520
    ctx->r7 = ADD32(ctx->r7, 0X520);
    hud_element_render(rdram, ctx);
        goto after_11;
    // 0x800A41A0: addiu       $a3, $a3, 0x520
    ctx->r7 = ADD32(ctx->r7, 0X520);
    after_11:
    // 0x800A41A4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A41A8: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A41AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A41B0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A41B4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A41B8: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A41BC: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A41C0: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A41C4: jal         0x800AAB5C
    // 0x800A41C8: addiu       $a3, $a3, 0x540
    ctx->r7 = ADD32(ctx->r7, 0X540);
    hud_element_render(rdram, ctx);
        goto after_12;
    // 0x800A41C8: addiu       $a3, $a3, 0x540
    ctx->r7 = ADD32(ctx->r7, 0X540);
    after_12:
    // 0x800A41CC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A41D0: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A41D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A41D8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A41DC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A41E0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A41E4: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A41E8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A41EC: jal         0x800AAB5C
    // 0x800A41F0: addiu       $a3, $a3, 0x560
    ctx->r7 = ADD32(ctx->r7, 0X560);
    hud_element_render(rdram, ctx);
        goto after_13;
    // 0x800A41F0: addiu       $a3, $a3, 0x560
    ctx->r7 = ADD32(ctx->r7, 0X560);
    after_13:
    // 0x800A41F4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A41F8: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A41FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4200: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4204: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4208: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A420C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4210: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4214: jal         0x800AAB5C
    // 0x800A4218: addiu       $a3, $a3, 0x580
    ctx->r7 = ADD32(ctx->r7, 0X580);
    hud_element_render(rdram, ctx);
        goto after_14;
    // 0x800A4218: addiu       $a3, $a3, 0x580
    ctx->r7 = ADD32(ctx->r7, 0X580);
    after_14:
L_800A421C:
    // 0x800A421C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A4220:
    // 0x800A4220: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A4224: jr          $ra
    // 0x800A4228: nop

    return;
    // 0x800A4228: nop

;}
RECOMP_FUNC void minimap_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8910: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A8914: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A8918: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A891C: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x800A8920: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8924: srl         $t8, $t6, 16
    ctx->r24 = S32(U32(ctx->r14) >> 16);
    // 0x800A8928: sb          $t8, 0x7314($at)
    MEM_B(0X7314, ctx->r1) = ctx->r24;
    // 0x800A892C: lw          $t9, 0x38($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X38);
    // 0x800A8930: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8934: srl         $t1, $t9, 8
    ctx->r9 = S32(U32(ctx->r25) >> 8);
    // 0x800A8938: sb          $t1, 0x7315($at)
    MEM_B(0X7315, ctx->r1) = ctx->r9;
    // 0x800A893C: lw          $t3, 0x38($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X38);
    // 0x800A8940: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8944: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A8948: sb          $t3, 0x7316($at)
    MEM_B(0X7316, ctx->r1) = ctx->r11;
    // 0x800A894C: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    // 0x800A8950: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x800A8954: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8958: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A895C: addiu       $a2, $a2, 0x72E0
    ctx->r6 = ADD32(ctx->r6, 0X72E0);
    // 0x800A8960: addiu       $a1, $a1, 0x72DC
    ctx->r5 = ADD32(ctx->r5, 0X72DC);
    // 0x800A8964: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800A8968: jal         0x8007CD30
    // 0x800A896C: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    load_sprite_info(rdram, ctx);
        goto after_0;
    // 0x800A896C: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A8970: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x800A8974: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A8978: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A897C: addiu       $t4, $sp, 0x2C
    ctx->r12 = ADD32(ctx->r29, 0X2C);
    // 0x800A8980: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800A8984: addiu       $a3, $a3, 0x72D8
    ctx->r7 = ADD32(ctx->r7, 0X72D8);
    // 0x800A8988: addiu       $a2, $a2, 0x72D4
    ctx->r6 = ADD32(ctx->r6, 0X72D4);
    // 0x800A898C: jal         0x8007CEB8
    // 0x800A8990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8007CA68(rdram, ctx);
        goto after_1;
    // 0x800A8990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800A8994: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x800A8998: jal         0x8007C57C
    // 0x800A899C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    tex_load_sprite(rdram, ctx);
        goto after_2;
    // 0x800A899C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x800A89A0: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x800A89A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A89A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A89AC: jr          $ra
    // 0x800A89B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A89B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void free_track(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C814: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002C818: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002C81C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002C820: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002C824: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002C828: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002C82C: jal         0x8000B290
    // 0x8002C830: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    racerfx_free(rdram, ctx);
        goto after_0;
    // 0x8002C830: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8002C834: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002C838: lw          $t6, -0x26FC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26FC);
    // 0x8002C83C: nop

    // 0x8002C840: beq         $t6, $zero, L_8002C850
    if (ctx->r14 == 0) {
        // 0x8002C844: nop
    
            goto L_8002C850;
    }
    // 0x8002C844: nop

    // 0x8002C848: jal         0x800B8240
    // 0x8002C84C: nop

    waves_free(rdram, ctx);
        goto after_1;
    // 0x8002C84C: nop

    after_1:
L_8002C850:
    // 0x8002C850: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8002C854: addiu       $s4, $s4, -0x3178
    ctx->r20 = ADD32(ctx->r20, -0X3178);
    // 0x8002C858: lw          $s1, 0x0($s4)
    ctx->r17 = MEM_W(ctx->r20, 0X0);
    // 0x8002C85C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002C860: lh          $t7, 0x18($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X18);
    // 0x8002C864: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002C868: blez        $t7, L_8002C8A4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8002C86C: nop
    
            goto L_8002C8A4;
    }
    // 0x8002C86C: nop

L_8002C870:
    // 0x8002C870: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8002C874: nop

    // 0x8002C878: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8002C87C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8002C880: jal         0x8007B70C
    // 0x8002C884: nop

    tex_free(rdram, ctx);
        goto after_2;
    // 0x8002C884: nop

    after_2:
    // 0x8002C888: lw          $s1, 0x0($s4)
    ctx->r17 = MEM_W(ctx->r20, 0X0);
    // 0x8002C88C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002C890: lh          $t0, 0x18($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X18);
    // 0x8002C894: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8002C898: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002C89C: bne         $at, $zero, L_8002C870
    if (ctx->r1 != 0) {
        // 0x8002C8A0: nop
    
            goto L_8002C870;
    }
    // 0x8002C8A0: nop

L_8002C8A4:
    // 0x8002C8A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002C8A8: lw          $a0, -0x2774($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2774);
    // 0x8002C8AC: jal         0x80071380
    // 0x8002C8B0: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x8002C8B0: nop

    after_3:
    // 0x8002C8B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002C8B8: lw          $a0, -0x2710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2710);
    // 0x8002C8BC: jal         0x80071380
    // 0x8002C8C0: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x8002C8C0: nop

    after_4:
    // 0x8002C8C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002C8C8: lw          $a0, -0x270C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X270C);
    // 0x8002C8CC: jal         0x80071380
    // 0x8002C8D0: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x8002C8D0: nop

    after_5:
    // 0x8002C8D4: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x8002C8D8: nop

    // 0x8002C8DC: lw          $a0, 0x20($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X20);
    // 0x8002C8E0: jal         0x8007D100
    // 0x8002C8E4: nop

    sprite_free(rdram, ctx);
        goto after_6;
    // 0x8002C8E4: nop

    after_6:
    // 0x8002C8E8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002C8EC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8002C8F0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8002C8F4: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002C8F8: addiu       $s3, $s3, -0x2738
    ctx->r19 = ADD32(ctx->r19, -0X2738);
    // 0x8002C8FC: addiu       $s0, $s0, -0x2748
    ctx->r16 = ADD32(ctx->r16, -0X2748);
    // 0x8002C900: addiu       $s2, $s2, -0x2760
    ctx->r18 = ADD32(ctx->r18, -0X2760);
    // 0x8002C904: addiu       $s1, $s1, -0x2730
    ctx->r17 = ADD32(ctx->r17, -0X2730);
L_8002C908:
    // 0x8002C908: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002C90C: jal         0x80071380
    // 0x8002C910: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x8002C910: nop

    after_7:
    // 0x8002C914: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8002C918: jal         0x80071380
    // 0x8002C91C: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x8002C91C: nop

    after_8:
    // 0x8002C920: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8002C924: jal         0x80071380
    // 0x8002C928: nop

    mempool_free(rdram, ctx);
        goto after_9;
    // 0x8002C928: nop

    after_9:
    // 0x8002C92C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8002C930: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8002C934: bne         $s0, $s3, L_8002C908
    if (ctx->r16 != ctx->r19) {
        // 0x8002C938: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8002C908;
    }
    // 0x8002C938: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8002C93C: jal         0x80025810
    // 0x8002C940: nop

    void_free(rdram, ctx);
        goto after_10;
    // 0x8002C940: nop

    after_10:
    // 0x8002C944: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002C948: lw          $a0, -0x49C8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X49C8);
    // 0x8002C94C: nop

    // 0x8002C950: beq         $a0, $zero, L_8002C968
    if (ctx->r4 == 0) {
        // 0x8002C954: nop
    
            goto L_8002C968;
    }
    // 0x8002C954: nop

    // 0x8002C958: jal         0x8000FFB8
    // 0x8002C95C: nop

    free_object(rdram, ctx);
        goto after_11;
    // 0x8002C95C: nop

    after_11:
    // 0x8002C960: jal         0x8001004C
    // 0x8002C964: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_12;
    // 0x8002C964: nop

    after_12:
L_8002C968:
    // 0x8002C968: jal         0x8000C604
    // 0x8002C96C: nop

    free_all_objects(rdram, ctx);
        goto after_13;
    // 0x8002C96C: nop

    after_13:
    // 0x8002C970: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C974: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x8002C978: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002C97C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002C980: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C984: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002C988: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002C98C: jr          $ra
    // 0x8002C990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002C990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void postrace_message(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095B28: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80095B2C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80095B30: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x80095B34: beq         $at, $zero, L_80095BCC
    if (ctx->r1 == 0) {
        // 0x80095B38: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80095BCC;
    }
    // 0x80095B38: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80095B3C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80095B40: addu        $at, $at, $t7
    gpr jr_addend_80095B4C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80095B44: lw          $t7, -0x754C($at)
    ctx->r15 = ADD32(ctx->r1, -0X754C);
    // 0x80095B48: nop

    // 0x80095B4C: jr          $t7
    // 0x80095B50: nop

    switch (jr_addend_80095B4C >> 2) {
        case 0: goto L_80095B54; break;
        case 1: goto L_80095BCC; break;
        case 2: goto L_80095BCC; break;
        case 3: goto L_80095B6C; break;
        case 4: goto L_80095B54; break;
        case 5: goto L_80095B6C; break;
        case 6: goto L_80095B84; break;
        case 7: goto L_80095B9C; break;
        case 8: goto L_80095BB4; break;
        default: switch_error(__func__, 0x80095B4C, 0x800E8AB4);
    }
    // 0x80095B50: nop

L_80095B54:
    // 0x80095B54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80095B58: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80095B5C: addiu       $t8, $t8, 0xF58
    ctx->r24 = ADD32(ctx->r24, 0XF58);
    // 0x80095B60: addiu       $a0, $a0, 0x71DC
    ctx->r4 = ADD32(ctx->r4, 0X71DC);
    // 0x80095B64: b           L_80095BE0
    // 0x80095B68: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
        goto L_80095BE0;
    // 0x80095B68: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_80095B6C:
    // 0x80095B6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80095B70: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80095B74: addiu       $t9, $t9, 0xF44
    ctx->r25 = ADD32(ctx->r25, 0XF44);
    // 0x80095B78: addiu       $a0, $a0, 0x71DC
    ctx->r4 = ADD32(ctx->r4, 0X71DC);
    // 0x80095B7C: b           L_80095BE0
    // 0x80095B80: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
        goto L_80095BE0;
    // 0x80095B80: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
L_80095B84:
    // 0x80095B84: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80095B88: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80095B8C: addiu       $a0, $a0, 0x71DC
    ctx->r4 = ADD32(ctx->r4, 0X71DC);
    // 0x80095B90: addiu       $t0, $t0, 0xF84
    ctx->r8 = ADD32(ctx->r8, 0XF84);
    // 0x80095B94: b           L_80095BE0
    // 0x80095B98: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
        goto L_80095BE0;
    // 0x80095B98: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
L_80095B9C:
    // 0x80095B9C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80095BA0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80095BA4: addiu       $a0, $a0, 0x71DC
    ctx->r4 = ADD32(ctx->r4, 0X71DC);
    // 0x80095BA8: addiu       $t1, $t1, 0xF94
    ctx->r9 = ADD32(ctx->r9, 0XF94);
    // 0x80095BAC: b           L_80095BE0
    // 0x80095BB0: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
        goto L_80095BE0;
    // 0x80095BB0: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
L_80095BB4:
    // 0x80095BB4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80095BB8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80095BBC: addiu       $a0, $a0, 0x71DC
    ctx->r4 = ADD32(ctx->r4, 0X71DC);
    // 0x80095BC0: addiu       $t2, $t2, 0xF6C
    ctx->r10 = ADD32(ctx->r10, 0XF6C);
    // 0x80095BC4: b           L_80095BE0
    // 0x80095BC8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
        goto L_80095BE0;
    // 0x80095BC8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
L_80095BCC:
    // 0x80095BCC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80095BD0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80095BD4: addiu       $a0, $a0, 0x71DC
    ctx->r4 = ADD32(ctx->r4, 0X71DC);
    // 0x80095BD8: addiu       $t3, $t3, 0xF30
    ctx->r11 = ADD32(ctx->r11, 0XF30);
    // 0x80095BDC: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
L_80095BE0:
    // 0x80095BE0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80095BE4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80095BE8: addiu       $a1, $a1, 0x71E4
    ctx->r5 = ADD32(ctx->r5, 0X71E4);
    // 0x80095BEC: sll         $t4, $zero, 2
    ctx->r12 = S32(0 << 2);
    // 0x80095BF0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80095BF4: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80095BF8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80095BFC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80095C00: beq         $t6, $zero, L_80095C24
    if (ctx->r14 == 0) {
        // 0x80095C04: addiu       $t7, $v1, 0x1
        ctx->r15 = ADD32(ctx->r3, 0X1);
            goto L_80095C24;
    }
    // 0x80095C04: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
L_80095C08:
    // 0x80095C08: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80095C0C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80095C10: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80095C14: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80095C18: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80095C1C: bne         $t0, $zero, L_80095C08
    if (ctx->r8 != 0) {
        // 0x80095C20: addiu       $t7, $v1, 0x1
        ctx->r15 = ADD32(ctx->r3, 0X1);
            goto L_80095C08;
    }
    // 0x80095C20: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
L_80095C24:
    // 0x80095C24: jr          $ra
    // 0x80095C28: nop

    return;
    // 0x80095C28: nop

;}
RECOMP_FUNC void leveltable_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B38C: bltz        $a0, L_8006B3C4
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B390: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006B3C4;
    }
    // 0x8006B390: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B394: lw          $t6, 0x16F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F0);
    // 0x8006B398: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006B39C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B3A0: beq         $at, $zero, L_8006B3C4
    if (ctx->r1 == 0) {
        // 0x8006B3A4: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006B3C4;
    }
    // 0x8006B3A4: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006B3A8: lw          $t7, 0x16FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16FC);
    // 0x8006B3AC: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8006B3B0: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006B3B4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B3B8: lb          $v0, 0x1($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X1);
    // 0x8006B3BC: jr          $ra
    // 0x8006B3C0: nop

    return;
    // 0x8006B3C0: nop

L_8006B3C4:
    // 0x8006B3C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006B3C8: jr          $ra
    // 0x8006B3CC: nop

    return;
    // 0x8006B3CC: nop

;}
RECOMP_FUNC void reset_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800307FC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80030800: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80030804: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80030808: addiu       $t7, $t7, -0x26F8
    ctx->r15 = ADD32(ctx->r15, -0X26F8);
    // 0x8003080C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80030810: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80030814: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80030818: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8003081C: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x80030820: lui         $t8, 0x3FA
    ctx->r24 = S32(0X3FA << 16);
    // 0x80030824: lui         $t9, 0x3FF
    ctx->r25 = S32(0X3FF << 16);
    // 0x80030828: addiu       $t6, $zero, 0x3FA
    ctx->r14 = ADD32(0, 0X3FA);
    // 0x8003082C: addiu       $t7, $zero, 0x3FF
    ctx->r15 = ADD32(0, 0X3FF);
    // 0x80030830: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80030834: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80030838: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8003083C: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80030840: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80030844: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80030848: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x8003084C: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x80030850: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x80030854: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
    // 0x80030858: sb          $t1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r9;
    // 0x8003085C: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x80030860: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80030864: sh          $t6, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r14;
    // 0x80030868: sh          $t7, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r15;
    // 0x8003086C: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80030870: jr          $ra
    // 0x80030874: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    return;
    // 0x80030874: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
;}
RECOMP_FUNC void obj_init_seamonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003CF44: jr          $ra
    // 0x8003CF48: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003CF48: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void music_sequence_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002110: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80002114: lw          $t6, 0x6278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6278);
    // 0x80002118: nop

    // 0x8000211C: lbu         $v0, 0x3($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X3);
    // 0x80002120: jr          $ra
    // 0x80002124: nop

    return;
    // 0x80002124: nop

;}
RECOMP_FUNC void obj_loop_flycoin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D2F8: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003D2FC: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8003D300: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003D304: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8003D308: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003D30C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003D310: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003D314: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003D318: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003D31C: bne         $t7, $zero, L_8003D33C
    if (ctx->r15 != 0) {
        // 0x8003D320: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8003D33C;
    }
    // 0x8003D320: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003D324: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D328: lwc1        $f9, 0x6718($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6718);
    // 0x8003D32C: lwc1        $f8, 0x671C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X671C);
    // 0x8003D330: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8003D334: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003D338: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8003D33C:
    // 0x8003D33C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003D340: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8003D344: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003D348: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8003D34C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8003D350: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003D354: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003D358: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003D35C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D360: sub.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d - ctx->f4.d;
    // 0x8003D364: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8003D368: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003D36C: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8003D370: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x8003D374: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003D378: nop

    // 0x8003D37C: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003D380: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003D384: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003D388: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8003D38C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8003D390: jal         0x80011570
    // 0x8003D394: nop

    move_object(rdram, ctx);
        goto after_0;
    // 0x8003D394: nop

    after_0:
    // 0x8003D398: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
    // 0x8003D39C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D3A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D3A4: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8003D3A8: bgtz        $t0, L_8003D408
    if (SIGNED(ctx->r8) > 0) {
        // 0x8003D3AC: sw          $t0, 0x78($s0)
        MEM_W(0X78, ctx->r16) = ctx->r8;
            goto L_8003D408;
    }
    // 0x8003D3AC: sw          $t0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r8;
    // 0x8003D3B0: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x8003D3B4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003D3B8: lb          $t2, 0x193($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X193);
    // 0x8003D3BC: nop

    // 0x8003D3C0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8003D3C4: sb          $t3, 0x193($v0)
    MEM_B(0X193, ctx->r2) = ctx->r11;
    // 0x8003D3C8: lb          $t4, 0x193($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X193);
    // 0x8003D3CC: nop

    // 0x8003D3D0: slti        $at, $t4, 0xA
    ctx->r1 = SIGNED(ctx->r12) < 0XA ? 1 : 0;
    // 0x8003D3D4: bne         $at, $zero, L_8003D3E0
    if (ctx->r1 != 0) {
        // 0x8003D3D8: nop
    
            goto L_8003D3E0;
    }
    // 0x8003D3D8: nop

    // 0x8003D3DC: sb          $t5, 0x1D8($v0)
    MEM_B(0X1D8, ctx->r2) = ctx->r13;
L_8003D3E0:
    // 0x8003D3E0: jal         0x8000FFB8
    // 0x8003D3E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    free_object(rdram, ctx);
        goto after_1;
    // 0x8003D3E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x8003D3E8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8003D3EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003D3F0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8003D3F4: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8003D3F8: beq         $t6, $at, L_8003D40C
    if (ctx->r14 == ctx->r1) {
        // 0x8003D3FC: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_8003D40C;
    }
    // 0x8003D3FC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D400: jal         0x80001D04
    // 0x8003D404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8003D404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8003D408:
    // 0x8003D408: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_8003D40C:
    // 0x8003D40C: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x8003D410: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8003D414: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8003D418: sh          $t0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r8;
    // 0x8003D41C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D420: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003D424: jr          $ra
    // 0x8003D428: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003D428: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void rain_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADA18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ADA1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800ADA20: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800ADA24: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800ADA28: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800ADA2C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ADA30: jal         0x80066450
    // 0x800ADA34: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x800ADA34: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800ADA38: bne         $v0, $zero, L_800ADB9C
    if (ctx->r2 != 0) {
        // 0x800ADA3C: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_800ADB9C;
    }
    // 0x800ADA3C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ADA40: lw          $t6, 0x31EC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31EC);
    // 0x800ADA44: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800ADA48: beq         $t6, $zero, L_800ADB9C
    if (ctx->r14 == 0) {
        // 0x800ADA4C: addiu       $v1, $v1, 0x3208
        ctx->r3 = ADD32(ctx->r3, 0X3208);
            goto L_800ADB9C;
    }
    // 0x800ADA4C: addiu       $v1, $v1, 0x3208
    ctx->r3 = ADD32(ctx->r3, 0X3208);
    // 0x800ADA50: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800ADA54: nop

    // 0x800ADA58: blez        $v0, L_800ADAE8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800ADA5C: slt         $at, $s2, $v0
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800ADAE8;
    }
    // 0x800ADA5C: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800ADA60: beq         $at, $zero, L_800ADAC0
    if (ctx->r1 == 0) {
        // 0x800ADA64: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800ADAC0;
    }
    // 0x800ADA64: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800ADA68: subu        $t7, $v0, $s2
    ctx->r15 = SUB32(ctx->r2, ctx->r18);
    // 0x800ADA6C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800ADA70: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800ADA74: lw          $t9, 0x31F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X31F4);
    // 0x800ADA78: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800ADA7C: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADA80: addiu       $s0, $s0, 0x31F0
    ctx->r16 = ADD32(ctx->r16, 0X31F0);
    // 0x800ADA84: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800ADA88: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800ADA8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800ADA90: addiu       $a0, $a0, 0x31FC
    ctx->r4 = ADD32(ctx->r4, 0X31FC);
    // 0x800ADA94: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800ADA98: mflo        $t0
    ctx->r8 = lo;
    // 0x800ADA9C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800ADAA0: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800ADAA4: lw          $t3, 0x3200($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3200);
    // 0x800ADAA8: nop

    // 0x800ADAAC: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADAB0: mflo        $t4
    ctx->r12 = lo;
    // 0x800ADAB4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800ADAB8: b           L_800ADAE8
    // 0x800ADABC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
        goto L_800ADAE8;
    // 0x800ADABC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_800ADAC0:
    // 0x800ADAC0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800ADAC4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ADAC8: lw          $t6, 0x31F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31F8);
    // 0x800ADACC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800ADAD0: addiu       $s0, $s0, 0x31F0
    ctx->r16 = ADD32(ctx->r16, 0X31F0);
    // 0x800ADAD4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800ADAD8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800ADADC: lw          $t7, 0x3204($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3204);
    // 0x800ADAE0: addiu       $a0, $a0, 0x31FC
    ctx->r4 = ADD32(ctx->r4, 0X31FC);
    // 0x800ADAE4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_800ADAE8:
    // 0x800ADAE8: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800ADAEC: addiu       $s0, $s0, 0x31F0
    ctx->r16 = ADD32(ctx->r16, 0X31F0);
    // 0x800ADAF0: jal         0x800AE128
    // 0x800ADAF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    rain_sound(rdram, ctx);
        goto after_1;
    // 0x800ADAF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800ADAF8: jal         0x800ADBB8
    // 0x800ADAFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    rain_render_splashes(rdram, ctx);
        goto after_2;
    // 0x800ADAFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x800ADB00: jal         0x800AE018
    // 0x800ADB04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    rain_lightning(rdram, ctx);
        goto after_3;
    // 0x800ADB04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x800ADB08: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800ADB0C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800ADB10: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x800ADB14: bne         $at, $zero, L_800ADB9C
    if (ctx->r1 != 0) {
        // 0x800ADB18: addiu       $s3, $s3, -0x7E34
        ctx->r19 = ADD32(ctx->r19, -0X7E34);
            goto L_800ADB9C;
    }
    // 0x800ADB18: addiu       $s3, $s3, -0x7E34
    ctx->r19 = ADD32(ctx->r19, -0X7E34);
    // 0x800ADB1C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800ADB20: addiu       $a1, $a1, -0x7E30
    ctx->r5 = ADD32(ctx->r5, -0X7E30);
    // 0x800ADB24: jal         0x8006816C
    // 0x800ADB28: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mtx_ortho(rdram, ctx);
        goto after_4;
    // 0x800ADB28: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x800ADB2C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800ADB30: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800ADB34: addiu       $s1, $s1, 0x31EC
    ctx->r17 = ADD32(ctx->r17, 0X31EC);
    // 0x800ADB38: addiu       $s0, $s0, 0x31BC
    ctx->r16 = ADD32(ctx->r16, 0X31BC);
    // 0x800ADB3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800ADB40:
    // 0x800ADB40: jal         0x800AE21C
    // 0x800ADB44: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    rain_render(rdram, ctx);
        goto after_5;
    // 0x800ADB44: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x800ADB48: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x800ADB4C: bne         $s0, $s1, L_800ADB40
    if (ctx->r16 != ctx->r17) {
        // 0x800ADB50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800ADB40;
    }
    // 0x800ADB50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ADB54: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800ADB58: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x800ADB5C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800ADB60: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800ADB64: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800ADB68: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800ADB6C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800ADB70: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800ADB74: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x800ADB78: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800ADB7C: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x800ADB80: addiu       $t4, $zero, -0x100
    ctx->r12 = ADD32(0, -0X100);
    // 0x800ADB84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800ADB88: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800ADB8C: jal         0x8007B820
    // 0x800ADB90: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    rendermode_reset(rdram, ctx);
        goto after_6;
    // 0x800ADB90: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_6:
    // 0x800ADB94: jal         0x800684EC
    // 0x800ADB98: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    viewport_reset(rdram, ctx);
        goto after_7;
    // 0x800ADB98: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
L_800ADB9C:
    // 0x800ADB9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800ADBA0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800ADBA4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800ADBA8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADBAC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800ADBB0: jr          $ra
    // 0x800ADBB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800ADBB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void load_rng_seed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FB6C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006FB70: lw          $a0, -0x2658($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2658);
    // 0x8006FB74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006FB78: jr          $ra
    // 0x8006FB7C: sw          $a0, -0x265C($at)
    MEM_W(-0X265C, ctx->r1) = ctx->r4;
    return;
    // 0x8006FB7C: sw          $a0, -0x265C($at)
    MEM_W(-0X265C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void snow_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC094: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800AC098: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AC09C: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800AC0A0: addiu       $s4, $s4, 0x2E68
    ctx->r20 = ADD32(ctx->r20, 0X2E68);
    // 0x800AC0A4: lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X4);
    // 0x800AC0A8: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800AC0AC: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800AC0B0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AC0B4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AC0B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AC0BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AC0C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AC0C4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800AC0C8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AC0CC: bne         $v0, $zero, L_800AC0D8
    if (ctx->r2 != 0) {
        // 0x800AC0D0: nop
    
            goto L_800AC0D8;
    }
    // 0x800AC0D0: nop

    // 0x800AC0D4: break       7
    do_break(2148188372);
L_800AC0D8:
    // 0x800AC0D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC0DC: bne         $v0, $at, L_800AC0F0
    if (ctx->r2 != ctx->r1) {
        // 0x800AC0E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC0F0;
    }
    // 0x800AC0E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC0E4: bne         $t6, $at, L_800AC0F0
    if (ctx->r14 != ctx->r1) {
        // 0x800AC0E8: nop
    
            goto L_800AC0F0;
    }
    // 0x800AC0E8: nop

    // 0x800AC0EC: break       6
    do_break(2148188396);
L_800AC0F0:
    // 0x800AC0F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AC0F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AC0F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800AC0FC: lui         $s6, 0xFFFC
    ctx->r22 = S32(0XFFFC << 16);
    // 0x800AC100: mflo        $s5
    ctx->r21 = lo;
    // 0x800AC104: blez        $v0, L_800AC178
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AC108: or          $s3, $s1, $zero
        ctx->r19 = ctx->r17 | 0;
            goto L_800AC178;
    }
L_800AC108:
    // 0x800AC108: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x800AC10C: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x800AC110: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800AC114: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x800AC118: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AC11C: jal         0x80070A6C
    // 0x800AC120: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    coss_s16(rdram, ctx);
        goto after_0;
    // 0x800AC120: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x800AC124: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x800AC128: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x800AC12C: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x800AC130: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x800AC134: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800AC138: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x800AC13C: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AC140: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x800AC144: sw          $s6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r22;
    // 0x800AC148: jal         0x80070A70
    // 0x800AC14C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    static_3_80070A70(rdram, ctx);
        goto after_1;
    // 0x800AC14C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_1:
    // 0x800AC150: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800AC154: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800AC158: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800AC15C: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
    // 0x800AC160: lw          $t9, 0x4($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X4);
    // 0x800AC164: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800AC168: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AC16C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800AC170: bne         $at, $zero, L_800AC108
    if (ctx->r1 != 0) {
        // 0x800AC174: addu        $s1, $s1, $s5
        ctx->r17 = ADD32(ctx->r17, ctx->r21);
            goto L_800AC108;
    }
    // 0x800AC174: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
L_800AC178:
    // 0x800AC178: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AC17C: lw          $t1, 0x2EAC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2EAC);
    // 0x800AC180: nop

    // 0x800AC184: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800AC188: jal         0x8007B2C4
    // 0x800AC18C: nop

    load_texture(rdram, ctx);
        goto after_2;
    // 0x800AC18C: nop

    after_2:
    // 0x800AC190: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800AC194: sw          $v0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r2;
    // 0x800AC198: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AC19C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AC1A0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AC1A4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AC1A8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AC1AC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AC1B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AC1B4: jr          $ra
    // 0x800AC1B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800AC1B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void string_to_font_codes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076C90: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80076C94: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80076C98: beq         $t6, $zero, L_80076CFC
    if (ctx->r14 == 0) {
        // 0x80076C9C: nop
    
            goto L_80076CFC;
    }
    // 0x80076C9C: nop

    // 0x80076CA0: beq         $a2, $zero, L_80076CFC
    if (ctx->r6 == 0) {
        // 0x80076CA4: addiu       $t1, $zero, 0x41
        ctx->r9 = ADD32(0, 0X41);
            goto L_80076CFC;
    }
    // 0x80076CA4: addiu       $t1, $zero, 0x41
    ctx->r9 = ADD32(0, 0X41);
L_80076CA8:
    // 0x80076CA8: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076CAC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80076CB0: lbu         $a3, 0x0($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X0);
    // 0x80076CB4: addiu       $t0, $t0, -0x164C
    ctx->r8 = ADD32(ctx->r8, -0X164C);
    // 0x80076CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076CBC:
    // 0x80076CBC: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x80076CC0: nop

    // 0x80076CC4: bne         $a3, $t7, L_80076CD8
    if (ctx->r7 != ctx->r15) {
        // 0x80076CC8: nop
    
            goto L_80076CD8;
    }
    // 0x80076CC8: nop

    // 0x80076CCC: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80076CD0: b           L_80076CE4
    // 0x80076CD4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80076CE4;
    // 0x80076CD4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80076CD8:
    // 0x80076CD8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80076CDC: bne         $v0, $t1, L_80076CBC
    if (ctx->r2 != ctx->r9) {
        // 0x80076CE0: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80076CBC;
    }
    // 0x80076CE0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80076CE4:
    // 0x80076CE4: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x80076CE8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80076CEC: beq         $t8, $zero, L_80076CFC
    if (ctx->r24 == 0) {
        // 0x80076CF0: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_80076CFC;
    }
    // 0x80076CF0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80076CF4: bne         $a2, $zero, L_80076CA8
    if (ctx->r6 != 0) {
        // 0x80076CF8: nop
    
            goto L_80076CA8;
    }
    // 0x80076CF8: nop

L_80076CFC:
    // 0x80076CFC: beq         $a2, $zero, L_80076D40
    if (ctx->r6 == 0) {
        // 0x80076D00: andi        $a0, $a2, 0x3
        ctx->r4 = ctx->r6 & 0X3;
            goto L_80076D40;
    }
    // 0x80076D00: andi        $a0, $a2, 0x3
    ctx->r4 = ctx->r6 & 0X3;
    // 0x80076D04: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80076D08: beq         $a0, $zero, L_80076D24
    if (ctx->r4 == 0) {
        // 0x80076D0C: addu        $v0, $a0, $a2
        ctx->r2 = ADD32(ctx->r4, ctx->r6);
            goto L_80076D24;
    }
    // 0x80076D0C: addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
L_80076D10:
    // 0x80076D10: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80076D14: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076D18: bne         $v0, $a2, L_80076D10
    if (ctx->r2 != ctx->r6) {
        // 0x80076D1C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80076D10;
    }
    // 0x80076D1C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80076D20: beq         $a2, $zero, L_80076D40
    if (ctx->r6 == 0) {
        // 0x80076D24: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80076D40;
    }
L_80076D24:
    // 0x80076D24: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80076D28: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076D2C: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x80076D30: sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
    // 0x80076D34: sb          $zero, 0x3($a1)
    MEM_B(0X3, ctx->r5) = 0;
    // 0x80076D38: bne         $a2, $zero, L_80076D24
    if (ctx->r6 != 0) {
        // 0x80076D3C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80076D24;
    }
    // 0x80076D3C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80076D40:
    // 0x80076D40: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076D44: jr          $ra
    // 0x80076D48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80076D48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void music_volume_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000CBC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000CC0: sw          $zero, 0x62B8($at)
    MEM_W(0X62B8, ctx->r1) = 0;
    // 0x80000CC4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000CC8: sw          $zero, 0x62BC($at)
    MEM_W(0X62BC, ctx->r1) = 0;
    // 0x80000CCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80000CD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80000CD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000CD8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000CE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000CE4: lbu         $a0, -0x3458($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X3458);
    // 0x80000CE8: jal         0x80001990
    // 0x80000CEC: swc1        $f4, -0x3440($at)
    MEM_W(-0X3440, ctx->r1) = ctx->f4.u32l;
    music_volume_set(rdram, ctx);
        goto after_0;
    // 0x80000CEC: swc1        $f4, -0x3440($at)
    MEM_W(-0X3440, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x80000CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000CF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000CF8: jr          $ra
    // 0x80000CFC: nop

    return;
    // 0x80000CFC: nop

;}
RECOMP_FUNC void set_racer_tail_lights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F7BC: lbu         $t6, 0x20A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X20A);
    // 0x8004F7C0: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8004F7C4: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8004F7C8: sb          $t7, 0x20A($a0)
    MEM_B(0X20A, ctx->r4) = ctx->r15;
    // 0x8004F7CC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004F7D0: lw          $t8, -0x2558($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2558);
    // 0x8004F7D4: ori         $t1, $t7, 0x80
    ctx->r9 = ctx->r15 | 0X80;
    // 0x8004F7D8: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x8004F7DC: beq         $t9, $zero, L_8004F7E8
    if (ctx->r25 == 0) {
        // 0x8004F7E0: nop
    
            goto L_8004F7E8;
    }
    // 0x8004F7E0: nop

    // 0x8004F7E4: sb          $t1, 0x20A($a0)
    MEM_B(0X20A, ctx->r4) = ctx->r9;
L_8004F7E8:
    // 0x8004F7E8: lbu         $v0, 0x20A($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X20A);
    // 0x8004F7EC: nop

    // 0x8004F7F0: andi        $t2, $v0, 0xC0
    ctx->r10 = ctx->r2 & 0XC0;
    // 0x8004F7F4: beq         $t2, $zero, L_8004F814
    if (ctx->r10 == 0) {
        // 0x8004F7F8: andi        $v1, $v0, 0xF
        ctx->r3 = ctx->r2 & 0XF;
            goto L_8004F814;
    }
    // 0x8004F7F8: andi        $v1, $v0, 0xF
    ctx->r3 = ctx->r2 & 0XF;
    // 0x8004F7FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004F800: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8004F804: bne         $at, $zero, L_8004F828
    if (ctx->r1 != 0) {
        // 0x8004F808: andi        $t3, $v0, 0xFFF0
        ctx->r11 = ctx->r2 & 0XFFF0;
            goto L_8004F828;
    }
    // 0x8004F808: andi        $t3, $v0, 0xFFF0
    ctx->r11 = ctx->r2 & 0XFFF0;
    // 0x8004F80C: b           L_8004F824
    // 0x8004F810: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8004F824;
    // 0x8004F810: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8004F814:
    // 0x8004F814: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8004F818: bgez        $v1, L_8004F828
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004F81C: andi        $t3, $v0, 0xFFF0
        ctx->r11 = ctx->r2 & 0XFFF0;
            goto L_8004F828;
    }
    // 0x8004F81C: andi        $t3, $v0, 0xFFF0
    ctx->r11 = ctx->r2 & 0XFFF0;
    // 0x8004F820: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8004F824:
    // 0x8004F824: andi        $t3, $v0, 0xFFF0
    ctx->r11 = ctx->r2 & 0XFFF0;
L_8004F828:
    // 0x8004F828: or          $t4, $t3, $v1
    ctx->r12 = ctx->r11 | ctx->r3;
    // 0x8004F82C: jr          $ra
    // 0x8004F830: sb          $t4, 0x20A($a0)
    MEM_B(0X20A, ctx->r4) = ctx->r12;
    return;
    // 0x8004F830: sb          $t4, 0x20A($a0)
    MEM_B(0X20A, ctx->r4) = ctx->r12;
;}
RECOMP_FUNC void func_80021400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021434: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80021438: lh          $v1, -0x4C08($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X4C08);
    // 0x8002143C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80021440: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80021444: blez        $v1, L_800214A4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80021448: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800214A4;
    }
    // 0x80021448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002144C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80021450: lw          $a1, -0x4C0C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4C0C);
    // 0x80021454: nop

    // 0x80021458: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8002145C: nop

    // 0x80021460: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x80021464: nop

    // 0x80021468: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8002146C: beq         $t6, $t9, L_800214A8
    if (ctx->r14 == ctx->r25) {
        // 0x80021470: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800214A8;
    }
    // 0x80021470: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_80021474:
    // 0x80021474: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80021478: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002147C: beq         $at, $zero, L_800214A4
    if (ctx->r1 == 0) {
        // 0x80021480: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_800214A4;
    }
    // 0x80021480: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80021484: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x80021488: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8002148C: nop

    // 0x80021490: lw          $t3, 0x7C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X7C);
    // 0x80021494: nop

    // 0x80021498: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8002149C: bne         $a0, $t4, L_80021474
    if (ctx->r4 != ctx->r12) {
        // 0x800214A0: nop
    
            goto L_80021474;
    }
    // 0x800214A0: nop

L_800214A4:
    // 0x800214A4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800214A8:
    // 0x800214A8: beq         $at, $zero, L_800214F0
    if (ctx->r1 == 0) {
        // 0x800214AC: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800214F0;
    }
    // 0x800214AC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800214B0: lw          $t5, -0x4C0C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4C0C);
    // 0x800214B4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800214B8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800214BC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800214C0: nop

    // 0x800214C4: lw          $v1, 0x64($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X64);
    // 0x800214C8: nop

    // 0x800214CC: beq         $v1, $zero, L_800214F0
    if (ctx->r3 == 0) {
        // 0x800214D0: nop
    
            goto L_800214F0;
    }
    // 0x800214D0: nop

    // 0x800214D4: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x800214D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800214DC: lh          $t9, 0x2A($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2A);
    // 0x800214E0: nop

    // 0x800214E4: bgez        $t9, L_800214F0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800214E8: nop
    
            goto L_800214F0;
    }
    // 0x800214E8: nop

    // 0x800214EC: sh          $t0, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r8;
L_800214F0:
    // 0x800214F0: jr          $ra
    // 0x800214F4: nop

    return;
    // 0x800214F4: nop

;}
RECOMP_FUNC void enable_interupts_on_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B760C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7614: jal         0x800D29D0
    // 0x800B7618: nop

    __osGetActiveQueue(rdram, ctx);
        goto after_0;
    // 0x800B7618: nop

    after_0:
    // 0x800B761C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800B7620: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800B7624: beq         $a0, $t6, L_800B7670
    if (ctx->r4 == ctx->r14) {
        // 0x800B7628: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800B7670;
    }
    // 0x800B7628: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800B762C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800B7630: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
L_800B7634:
    // 0x800B7634: bne         $v0, $zero, L_800B7658
    if (ctx->r2 != 0) {
        // 0x800B7638: nop
    
            goto L_800B7658;
    }
    // 0x800B7638: nop

    // 0x800B763C: lw          $t7, 0x118($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X118);
    // 0x800B7640: ori         $at, $at, 0xFE
    ctx->r1 = ctx->r1 | 0XFE;
    // 0x800B7644: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800B7648: sw          $t8, 0x118($v1)
    MEM_W(0X118, ctx->r3) = ctx->r24;
    // 0x800B764C: ori         $t0, $t8, 0x6C01
    ctx->r8 = ctx->r24 | 0X6C01;
    // 0x800B7650: b           L_800B7670
    // 0x800B7654: sw          $t0, 0x118($v1)
    MEM_W(0X118, ctx->r3) = ctx->r8;
        goto L_800B7670;
    // 0x800B7654: sw          $t0, 0x118($v1)
    MEM_W(0X118, ctx->r3) = ctx->r8;
L_800B7658:
    // 0x800B7658: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
    // 0x800B765C: nop

    // 0x800B7660: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800B7664: nop

    // 0x800B7668: bne         $a0, $v0, L_800B7634
    if (ctx->r4 != ctx->r2) {
        // 0x800B766C: nop
    
            goto L_800B7634;
    }
    // 0x800B766C: nop

L_800B7670:
    // 0x800B7670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7674: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B7678: jr          $ra
    // 0x800B767C: nop

    return;
    // 0x800B767C: nop

;}
RECOMP_FUNC void menu_ghost_data_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099F98: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80099F9C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80099FA0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80099FA4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80099FA8: addiu       $t6, $t6, 0x6A98
    ctx->r14 = ADD32(ctx->r14, 0X6A98);
    // 0x80099FAC: lw          $a0, 0x6A70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A70);
    // 0x80099FB0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80099FB4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80099FB8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80099FBC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80099FC0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80099FC4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80099FC8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80099FCC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80099FD0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80099FD4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80099FD8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80099FDC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80099FE0: addiu       $a3, $a3, 0x6A84
    ctx->r7 = ADD32(ctx->r7, 0X6A84);
    // 0x80099FE4: addiu       $a2, $a2, 0x6A8C
    ctx->r6 = ADD32(ctx->r6, 0X6A8C);
    // 0x80099FE8: addiu       $a1, $a1, 0x6A7C
    ctx->r5 = ADD32(ctx->r5, 0X6A7C);
    // 0x80099FEC: jal         0x8007592C
    // 0x80099FF0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800756D4(rdram, ctx);
        goto after_0;
    // 0x80099FF0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80099FF4: bne         $v0, $zero, L_8009A004
    if (ctx->r2 != 0) {
        // 0x80099FF8: sw          $v0, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r2;
            goto L_8009A004;
    }
    // 0x80099FF8: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80099FFC: jal         0x80099B78
    // 0x8009A000: nop

    ghostmenu_generate(rdram, ctx);
        goto after_1;
    // 0x8009A000: nop

    after_1:
L_8009A004:
    // 0x8009A004: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009A008: jal         0x8009CBB8
    // 0x8009A00C: addiu       $a0, $a0, 0x1C88
    ctx->r4 = ADD32(ctx->r4, 0X1C88);
    menu_assetgroup_load(rdram, ctx);
        goto after_2;
    // 0x8009A00C: addiu       $a0, $a0, 0x1C88
    ctx->r4 = ADD32(ctx->r4, 0X1C88);
    after_2:
    // 0x8009A010: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009A014: jal         0x8009CDE8
    // 0x8009A018: addiu       $a0, $a0, 0x1CCC
    ctx->r4 = ADD32(ctx->r4, 0X1CCC);
    menu_imagegroup_load(rdram, ctx);
        goto after_3;
    // 0x8009A018: addiu       $a0, $a0, 0x1CCC
    ctx->r4 = ADD32(ctx->r4, 0X1CCC);
    after_3:
    // 0x8009A01C: jal         0x800C46D0
    // 0x8009A020: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_4;
    // 0x8009A020: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x8009A024: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009A028: addiu       $v0, $v0, 0x6AF0
    ctx->r2 = ADD32(ctx->r2, 0X6AF0);
    // 0x8009A02C: lw          $s7, 0x38($v0)
    ctx->r23 = MEM_W(ctx->r2, 0X38);
    // 0x8009A030: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A034: sw          $s7, 0x1ABC($at)
    MEM_W(0X1ABC, ctx->r1) = ctx->r23;
    // 0x8009A038: lw          $fp, 0x3C($v0)
    ctx->r30 = MEM_W(ctx->r2, 0X3C);
    // 0x8009A03C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A040: sw          $fp, 0x1AE4($at)
    MEM_W(0X1AE4, ctx->r1) = ctx->r30;
    // 0x8009A044: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8009A048: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A04C: sw          $v1, 0x1B14($at)
    MEM_W(0X1B14, ctx->r1) = ctx->r3;
    // 0x8009A050: lw          $a0, 0x44($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X44);
    // 0x8009A054: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A058: sw          $a0, 0x1B3C($at)
    MEM_W(0X1B3C, ctx->r1) = ctx->r4;
    // 0x8009A05C: lw          $a1, 0x48($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X48);
    // 0x8009A060: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A064: sw          $a1, 0x1B6C($at)
    MEM_W(0X1B6C, ctx->r1) = ctx->r5;
    // 0x8009A068: lw          $a2, 0x4C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4C);
    // 0x8009A06C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A070: sw          $a2, 0x1B94($at)
    MEM_W(0X1B94, ctx->r1) = ctx->r6;
    // 0x8009A074: lw          $a3, 0x50($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X50);
    // 0x8009A078: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A07C: sw          $a3, 0x1BC4($at)
    MEM_W(0X1BC4, ctx->r1) = ctx->r7;
    // 0x8009A080: lw          $t1, 0x54($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X54);
    // 0x8009A084: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A088: sw          $t1, 0x1BEC($at)
    MEM_W(0X1BEC, ctx->r1) = ctx->r9;
    // 0x8009A08C: lw          $t2, 0x58($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X58);
    // 0x8009A090: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A094: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8009A098: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8009A09C: sw          $t2, 0x1C1C($at)
    MEM_W(0X1C1C, ctx->r1) = ctx->r10;
    // 0x8009A0A0: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x8009A0A4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8009A0A8: andi        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 & 0X1;
    // 0x8009A0AC: multu       $t2, $a2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A0B0: lw          $t3, 0x5C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X5C);
    // 0x8009A0B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A0B8: sw          $t3, 0x1C44($at)
    MEM_W(0X1C44, ctx->r1) = ctx->r11;
    // 0x8009A0BC: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x8009A0C0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009A0C4: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8009A0C8: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x8009A0CC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A0D0: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8009A0D4: addiu       $t7, $t7, 0x1ABC
    ctx->r15 = ADD32(ctx->r15, 0X1ABC);
    // 0x8009A0D8: addiu       $a1, $a1, 0x1B14
    ctx->r5 = ADD32(ctx->r5, 0X1B14);
    // 0x8009A0DC: mflo        $t8
    ctx->r24 = lo;
    // 0x8009A0E0: addu        $t3, $t0, $t8
    ctx->r11 = ADD32(ctx->r8, ctx->r24);
    // 0x8009A0E4: xori        $t8, $t2, 0x1
    ctx->r24 = ctx->r10 ^ 0X1;
    // 0x8009A0E8: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A0EC: sll         $t9, $t3, 3
    ctx->r25 = S32(ctx->r11 << 3);
    // 0x8009A0F0: addu        $v0, $t1, $t7
    ctx->r2 = ADD32(ctx->r9, ctx->r15);
    // 0x8009A0F4: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x8009A0F8: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x8009A0FC: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
    // 0x8009A100: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    // 0x8009A104: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8009A108: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8009A10C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8009A110: addiu       $a3, $a3, 0x1C1C
    ctx->r7 = ADD32(ctx->r7, 0X1C1C);
    // 0x8009A114: addiu       $t5, $t0, 0x1
    ctx->r13 = ADD32(ctx->r8, 0X1);
    // 0x8009A118: mflo        $t9
    ctx->r25 = lo;
    // 0x8009A11C: addu        $t4, $t0, $t9
    ctx->r12 = ADD32(ctx->r8, ctx->r25);
    // 0x8009A120: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x8009A124: addu        $t8, $a1, $t6
    ctx->r24 = ADD32(ctx->r5, ctx->r14);
    // 0x8009A128: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x8009A12C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009A130: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8009A134: addiu       $t9, $t9, 0x1B6C
    ctx->r25 = ADD32(ctx->r25, 0X1B6C);
    // 0x8009A138: addu        $v1, $t1, $t9
    ctx->r3 = ADD32(ctx->r9, ctx->r25);
    // 0x8009A13C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009A140: addiu       $t8, $t8, 0x1BC4
    ctx->r24 = ADD32(ctx->r24, 0X1BC4);
    // 0x8009A144: sw          $t7, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r15;
    // 0x8009A148: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8009A14C: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
    // 0x8009A150: addu        $t8, $a3, $t3
    ctx->r24 = ADD32(ctx->r7, ctx->r11);
    // 0x8009A154: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8009A158: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x8009A15C: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A160: or          $t5, $t7, $zero
    ctx->r13 = ctx->r15 | 0;
    // 0x8009A164: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x8009A168: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8009A16C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8009A170: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009A174: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8009A178: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009A17C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8009A180: sw          $t6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r14;
    // 0x8009A184: addu        $t6, $a3, $t4
    ctx->r14 = ADD32(ctx->r7, ctx->r12);
    // 0x8009A188: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8009A18C: mflo        $t8
    ctx->r24 = lo;
    // 0x8009A190: addu        $ra, $t0, $t8
    ctx->r31 = ADD32(ctx->r8, ctx->r24);
    // 0x8009A194: xori        $t8, $t5, 0x1
    ctx->r24 = ctx->r13 ^ 0X1;
    // 0x8009A198: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A19C: sll         $t9, $ra, 3
    ctx->r25 = S32(ctx->r31 << 3);
    // 0x8009A1A0: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8009A1A4: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x8009A1A8: or          $ra, $t9, $zero
    ctx->r31 = ctx->r25 | 0;
    // 0x8009A1AC: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8009A1B0: sw          $fp, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r30;
    // 0x8009A1B4: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    // 0x8009A1B8: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8009A1BC: addiu       $s1, $t0, 0x2
    ctx->r17 = ADD32(ctx->r8, 0X2);
    // 0x8009A1C0: sw          $s7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r23;
    // 0x8009A1C4: sw          $fp, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r30;
    // 0x8009A1C8: mflo        $t9
    ctx->r25 = lo;
    // 0x8009A1CC: addu        $s0, $t0, $t9
    ctx->r16 = ADD32(ctx->r8, ctx->r25);
    // 0x8009A1D0: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x8009A1D4: addu        $t8, $a1, $t6
    ctx->r24 = ADD32(ctx->r5, ctx->r14);
    // 0x8009A1D8: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x8009A1DC: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8009A1E0: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8009A1E4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8009A1E8: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x8009A1EC: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8009A1F0: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
    // 0x8009A1F4: addu        $t6, $a3, $ra
    ctx->r14 = ADD32(ctx->r7, ctx->r31);
    // 0x8009A1F8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8009A1FC: andi        $t9, $s1, 0x1
    ctx->r25 = ctx->r17 & 0X1;
    // 0x8009A200: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A204: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8009A208: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8009A20C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8009A210: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x8009A214: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8009A218: sw          $t8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r24;
    // 0x8009A21C: addu        $t8, $a3, $s0
    ctx->r24 = ADD32(ctx->r7, ctx->r16);
    // 0x8009A220: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x8009A224: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8009A228: addiu       $s4, $t0, 0x3
    ctx->r20 = ADD32(ctx->r8, 0X3);
    // 0x8009A22C: sw          $s7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r23;
    // 0x8009A230: mflo        $t6
    ctx->r14 = lo;
    // 0x8009A234: addu        $s2, $t0, $t6
    ctx->r18 = ADD32(ctx->r8, ctx->r14);
    // 0x8009A238: xori        $t6, $s1, 0x1
    ctx->r14 = ctx->r17 ^ 0X1;
    // 0x8009A23C: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A240: sll         $t7, $s2, 3
    ctx->r15 = S32(ctx->r18 << 3);
    // 0x8009A244: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x8009A248: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8009A24C: sw          $t8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r24;
    // 0x8009A250: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8009A254: sw          $fp, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r30;
    // 0x8009A258: mflo        $t7
    ctx->r15 = lo;
    // 0x8009A25C: addu        $s3, $t0, $t7
    ctx->r19 = ADD32(ctx->r8, ctx->r15);
    // 0x8009A260: sll         $t8, $s3, 3
    ctx->r24 = S32(ctx->r19 << 3);
    // 0x8009A264: addu        $t6, $a1, $t8
    ctx->r14 = ADD32(ctx->r5, ctx->r24);
    // 0x8009A268: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8009A26C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8009A270: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x8009A274: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8009A278: sw          $t7, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r15;
    // 0x8009A27C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8009A280: sw          $t8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r24;
    // 0x8009A284: addu        $t8, $a3, $s2
    ctx->r24 = ADD32(ctx->r7, ctx->r18);
    // 0x8009A288: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x8009A28C: andi        $t7, $s4, 0x1
    ctx->r15 = ctx->r20 & 0X1;
    // 0x8009A290: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A294: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x8009A298: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8009A29C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8009A2A0: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
    // 0x8009A2A4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8009A2A8: sw          $t6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r14;
    // 0x8009A2AC: addu        $t6, $a3, $s3
    ctx->r14 = ADD32(ctx->r7, ctx->r19);
    // 0x8009A2B0: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8009A2B4: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8009A2B8: sw          $s7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r23;
    // 0x8009A2BC: sw          $fp, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r30;
    // 0x8009A2C0: mflo        $t8
    ctx->r24 = lo;
    // 0x8009A2C4: addu        $s5, $t0, $t8
    ctx->r21 = ADD32(ctx->r8, ctx->r24);
    // 0x8009A2C8: xori        $t8, $s4, 0x1
    ctx->r24 = ctx->r20 ^ 0X1;
    // 0x8009A2CC: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A2D0: sll         $t9, $s5, 3
    ctx->r25 = S32(ctx->r21 << 3);
    // 0x8009A2D4: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x8009A2D8: or          $s5, $t9, $zero
    ctx->r21 = ctx->r25 | 0;
    // 0x8009A2DC: sw          $t6, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r14;
    // 0x8009A2E0: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8009A2E4: mflo        $t9
    ctx->r25 = lo;
    // 0x8009A2E8: addu        $s6, $t0, $t9
    ctx->r22 = ADD32(ctx->r8, ctx->r25);
    // 0x8009A2EC: sll         $t6, $s6, 3
    ctx->r14 = S32(ctx->r22 << 3);
    // 0x8009A2F0: addu        $t8, $a1, $t6
    ctx->r24 = ADD32(ctx->r5, ctx->r14);
    // 0x8009A2F4: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    // 0x8009A2F8: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8009A2FC: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x8009A300: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8009A304: sw          $t9, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r25;
    // 0x8009A308: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8009A30C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8009A310: sw          $t6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r14;
    // 0x8009A314: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8009A318: addu        $t6, $a3, $s5
    ctx->r14 = ADD32(ctx->r7, ctx->r21);
    // 0x8009A31C: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x8009A320: sw          $t7, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r15;
    // 0x8009A324: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8009A328: sw          $t8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r24;
    // 0x8009A32C: addu        $t8, $a3, $s6
    ctx->r24 = ADD32(ctx->r7, ctx->r22);
    // 0x8009A330: jal         0x8008E914
    // 0x8009A334: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    menu_init_vehicle_textures(rdram, ctx);
        goto after_5;
    // 0x8009A334: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    after_5:
    // 0x8009A338: jal         0x80094B08
    // 0x8009A33C: nop

    menu_racer_portraits(rdram, ctx);
        goto after_6;
    // 0x8009A33C: nop

    after_6:
    // 0x8009A340: jal         0x8008E968
    // 0x8009A344: nop

    menu_init_arrow_textures(rdram, ctx);
        goto after_7;
    // 0x8009A344: nop

    after_7:
    // 0x8009A348: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009A34C: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x8009A350: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009A354: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x8009A358: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009A35C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009A360: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    // 0x8009A364: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8009A368: addiu       $v0, $v0, -0x604
    ctx->r2 = ADD32(ctx->r2, -0X604);
    // 0x8009A36C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8009A370: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009A374: bne         $t9, $zero, L_8009A390
    if (ctx->r25 != 0) {
        // 0x8009A378: sw          $zero, 0x6A38($at)
        MEM_W(0X6A38, ctx->r1) = 0;
            goto L_8009A390;
    }
    // 0x8009A378: sw          $zero, 0x6A38($at)
    MEM_W(0X6A38, ctx->r1) = 0;
    // 0x8009A37C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009A380: jal         0x800C06F8
    // 0x8009A384: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_8;
    // 0x8009A384: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_8:
    // 0x8009A388: b           L_8009A39C
    // 0x8009A38C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8009A39C;
    // 0x8009A38C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009A390:
    // 0x8009A390: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8009A394: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009A398: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009A39C:
    // 0x8009A39C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8009A3A0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8009A3A4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8009A3A8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8009A3AC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8009A3B0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8009A3B4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8009A3B8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8009A3BC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8009A3C0: jr          $ra
    // 0x8009A3C4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8009A3C4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void init_object_shadow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FBCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000FBD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FBD4: sw          $a1, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r5;
    // 0x8000FBD8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8000FBDC: lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X40);
    // 0x8000FBE0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000FBE4: lh          $t6, 0x32($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X32);
    // 0x8000FBE8: nop

    // 0x8000FBEC: beq         $t6, $zero, L_8000FC18
    if (ctx->r14 == 0) {
        // 0x8000FBF0: nop
    
            goto L_8000FC18;
    }
    // 0x8000FBF0: nop

    // 0x8000FBF4: lh          $a0, 0x34($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X34);
    // 0x8000FBF8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8000FBFC: jal         0x8007B2C4
    // 0x8000FC00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    load_texture(rdram, ctx);
        goto after_0;
    // 0x8000FC00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000FC04: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FC08: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8000FC0C: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8000FC10: lw          $v1, 0x40($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X40);
    // 0x8000FC14: nop

L_8000FC18:
    // 0x8000FC18: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8000FC1C: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8000FC20: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8000FC24: sh          $t7, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r15;
    // 0x8000FC28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000FC2C: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8000FC30: sw          $t8, -0x4C30($at)
    MEM_W(-0X4C30, ctx->r1) = ctx->r24;
    // 0x8000FC34: lw          $t9, 0x40($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X40);
    // 0x8000FC38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000FC3C: lh          $t0, 0x32($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X32);
    // 0x8000FC40: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8000FC44: beq         $t0, $zero, L_8000FC64
    if (ctx->r8 == 0) {
        // 0x8000FC48: nop
    
            goto L_8000FC64;
    }
    // 0x8000FC48: nop

    // 0x8000FC4C: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x8000FC50: nop

    // 0x8000FC54: bne         $t1, $zero, L_8000FC64
    if (ctx->r9 != 0) {
        // 0x8000FC58: nop
    
            goto L_8000FC64;
    }
    // 0x8000FC58: nop

    // 0x8000FC5C: b           L_8000FC64
    // 0x8000FC60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FC64;
    // 0x8000FC60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FC64:
    // 0x8000FC64: jr          $ra
    // 0x8000FC68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000FC68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void music_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001844: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001848: lw          $t6, -0x3448($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3448);
    // 0x8000184C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001850: bne         $t6, $zero, L_80001868
    if (ctx->r14 != 0) {
        // 0x80001854: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80001868;
    }
    // 0x80001854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001858: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000185C: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001860: jal         0x80002570
    // 0x80001864: nop

    music_sequence_stop(rdram, ctx);
        goto after_0;
    // 0x80001864: nop

    after_0:
L_80001868:
    // 0x80001868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000186C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001870: jr          $ra
    // 0x80001874: nop

    return;
    // 0x80001874: nop

;}
RECOMP_FUNC void __osGetActiveQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D29D0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800D29D4: jr          $ra
    // 0x800D29D8: lw          $v0, 0x4E1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4E1C);
    return;
    // 0x800D29D8: lw          $v0, 0x4E1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4E1C);
;}
RECOMP_FUNC void level_transition_begin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F380: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F384: addiu       $v0, $v0, -0x26FC
    ctx->r2 = ADD32(ctx->r2, -0X26FC);
    // 0x8006F388: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8006F38C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F394: bne         $t6, $zero, L_8006F43C
    if (ctx->r14 != 0) {
        // 0x8006F398: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8006F43C;
    }
    // 0x8006F398: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006F39C: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8006F3A0: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8006F3A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F3A8: sb          $zero, 0x3AA4($at)
    MEM_B(0X3AA4, ctx->r1) = 0;
    // 0x8006F3AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F3B0: sb          $zero, 0x3AA6($at)
    MEM_B(0X3AA6, ctx->r1) = 0;
    // 0x8006F3B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006F3B8: bne         $a0, $at, L_8006F3D8
    if (ctx->r4 != ctx->r1) {
        // 0x8006F3BC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006F3D8;
    }
    // 0x8006F3BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F3C0: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    // 0x8006F3C4: jal         0x800C06F8
    // 0x8006F3C8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8006F3C8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006F3CC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F3D0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006F3D4: addiu       $v0, $v0, -0x26FC
    ctx->r2 = ADD32(ctx->r2, -0X26FC);
L_8006F3D8:
    // 0x8006F3D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006F3DC: bne         $a1, $at, L_8006F404
    if (ctx->r5 != ctx->r1) {
        // 0x8006F3E0: addiu       $t8, $zero, 0x11A
        ctx->r24 = ADD32(0, 0X11A);
            goto L_8006F404;
    }
    // 0x8006F3E0: addiu       $t8, $zero, 0x11A
    ctx->r24 = ADD32(0, 0X11A);
    // 0x8006F3E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F3E8: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x8006F3EC: addiu       $a0, $a0, -0x266C
    ctx->r4 = ADD32(ctx->r4, -0X266C);
    // 0x8006F3F0: jal         0x800C06F8
    // 0x8006F3F4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x8006F3F4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x8006F3F8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F3FC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006F400: addiu       $v0, $v0, -0x26FC
    ctx->r2 = ADD32(ctx->r2, -0X26FC);
L_8006F404:
    // 0x8006F404: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006F408: bne         $a1, $at, L_8006F430
    if (ctx->r5 != ctx->r1) {
        // 0x8006F40C: addiu       $t9, $zero, 0x168
        ctx->r25 = ADD32(0, 0X168);
            goto L_8006F430;
    }
    // 0x8006F40C: addiu       $t9, $zero, 0x168
    ctx->r25 = ADD32(0, 0X168);
    // 0x8006F410: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F414: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8006F418: addiu       $a0, $a0, -0x266C
    ctx->r4 = ADD32(ctx->r4, -0X266C);
    // 0x8006F41C: jal         0x800C06F8
    // 0x8006F420: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    transition_begin(rdram, ctx);
        goto after_2;
    // 0x8006F420: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x8006F424: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F428: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006F42C: addiu       $v0, $v0, -0x26FC
    ctx->r2 = ADD32(ctx->r2, -0X26FC);
L_8006F430:
    // 0x8006F430: bne         $a1, $zero, L_8006F43C
    if (ctx->r5 != 0) {
        // 0x8006F434: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8006F43C;
    }
    // 0x8006F434: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8006F438: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
L_8006F43C:
    // 0x8006F43C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F444: jr          $ra
    // 0x8006F448: nop

    return;
    // 0x8006F448: nop

;}
RECOMP_FUNC void racer_activate_magnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056E6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80056E70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056E74: lb          $t6, 0x175($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X175);
    // 0x80056E78: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80056E7C: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x80056E80: sb          $t7, 0x175($a1)
    MEM_B(0X175, ctx->r5) = ctx->r15;
    // 0x80056E84: lb          $t8, 0x175($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X175);
    // 0x80056E88: nop

    // 0x80056E8C: bgez        $t8, L_80056E9C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80056E90: nop
    
            goto L_80056E9C;
    }
    // 0x80056E90: nop

    // 0x80056E94: b           L_80057078
    // 0x80056E98: sb          $zero, 0x175($a1)
    MEM_B(0X175, ctx->r5) = 0;
        goto L_80057078;
    // 0x80056E98: sb          $zero, 0x175($a1)
    MEM_B(0X175, ctx->r5) = 0;
L_80056E9C:
    // 0x80056E9C: lw          $v0, 0x140($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X140);
    // 0x80056EA0: nop

    // 0x80056EA4: bne         $v0, $zero, L_80056EB4
    if (ctx->r2 != 0) {
        // 0x80056EA8: nop
    
            goto L_80056EB4;
    }
    // 0x80056EA8: nop

    // 0x80056EAC: b           L_80057078
    // 0x80056EB0: sb          $zero, 0x175($a3)
    MEM_B(0X175, ctx->r7) = 0;
        goto L_80057078;
    // 0x80056EB0: sb          $zero, 0x175($a3)
    MEM_B(0X175, ctx->r7) = 0;
L_80056EB4:
    // 0x80056EB4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80056EB8: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80056EBC: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80056EC0: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80056EC4: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80056EC8: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80056ECC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80056ED0: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80056ED4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x80056ED8: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80056EDC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80056EE0: jal         0x800CA030
    // 0x80056EE4: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80056EE4: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x80056EE8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80056EEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80056EF0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80056EF4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80056EF8: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80056EFC: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80056F00: bc1f        L_80056FA4
    if (!c1cs) {
        // 0x80056F04: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80056FA4;
    }
    // 0x80056F04: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80056F08: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80056F0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80056F10: nop

    // 0x80056F14: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80056F18: nop

    // 0x80056F1C: bc1f        L_80056FA4
    if (!c1cs) {
        // 0x80056F20: nop
    
            goto L_80056FA4;
    }
    // 0x80056F20: nop

    // 0x80056F24: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80056F28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056F2C: beq         $t9, $at, L_80056F38
    if (ctx->r25 == ctx->r1) {
        // 0x80056F30: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_80056F38;
    }
    // 0x80056F30: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80056F34: sb          $t0, 0x1D3($a3)
    MEM_B(0X1D3, ctx->r7) = ctx->r8;
L_80056F38:
    // 0x80056F38: lbu         $t1, 0x20C($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X20C);
    // 0x80056F3C: sb          $zero, 0x203($a3)
    MEM_B(0X203, ctx->r7) = 0;
    // 0x80056F40: beq         $t1, $zero, L_80056F58
    if (ctx->r9 == 0) {
        // 0x80056F44: nop
    
            goto L_80056F58;
    }
    // 0x80056F44: nop

    // 0x80056F48: lb          $t2, 0x203($a3)
    ctx->r10 = MEM_B(ctx->r7, 0X203);
    // 0x80056F4C: nop

    // 0x80056F50: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x80056F54: sb          $t3, 0x203($a3)
    MEM_B(0X203, ctx->r7) = ctx->r11;
L_80056F58:
    // 0x80056F58: lw          $t4, 0x178($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X178);
    // 0x80056F5C: nop

    // 0x80056F60: bne         $t4, $zero, L_80056FAC
    if (ctx->r12 != 0) {
        // 0x80056F64: nop
    
            goto L_80056FAC;
    }
    // 0x80056F64: nop

    // 0x80056F68: lb          $t5, 0x1D8($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X1D8);
    // 0x80056F6C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    // 0x80056F70: bne         $t5, $zero, L_80056FAC
    if (ctx->r13 != 0) {
        // 0x80056F74: addiu       $a1, $a3, 0x178
        ctx->r5 = ADD32(ctx->r7, 0X178);
            goto L_80056FAC;
    }
    // 0x80056F74: addiu       $a1, $a3, 0x178
    ctx->r5 = ADD32(ctx->r7, 0X178);
    // 0x80056F78: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80056F7C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80056F80: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80056F84: jal         0x80001D04
    // 0x80056F88: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80056F88: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80056F8C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80056F90: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80056F94: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80056F98: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80056F9C: b           L_80056FB0
    // 0x80056FA0: lw          $t6, 0x140($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X140);
        goto L_80056FB0;
    // 0x80056FA0: lw          $t6, 0x140($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X140);
L_80056FA4:
    // 0x80056FA4: b           L_80057078
    // 0x80056FA8: sb          $zero, 0x175($a3)
    MEM_B(0X175, ctx->r7) = 0;
        goto L_80057078;
    // 0x80056FA8: sb          $zero, 0x175($a3)
    MEM_B(0X175, ctx->r7) = 0;
L_80056FAC:
    // 0x80056FAC: lw          $t6, 0x140($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X140);
L_80056FB0:
    // 0x80056FB0: div.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80056FB4: lw          $v0, 0x64($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X64);
    // 0x80056FB8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80056FBC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80056FC0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80056FC4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80056FC8: div.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80056FCC: lwc1        $f2, 0x2C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80056FD0: nop

    // 0x80056FD4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80056FD8: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80056FDC: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x80056FE0: nop

    // 0x80056FE4: bc1f        L_8005700C
    if (!c1cs) {
        // 0x80056FE8: lui         $at, 0x4034
        ctx->r1 = S32(0X4034 << 16);
            goto L_8005700C;
    }
    // 0x80056FE8: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x80056FEC: lb          $t7, 0x195($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X195);
    // 0x80056FF0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80056FF4: bne         $t7, $zero, L_80057008
    if (ctx->r15 != 0) {
        // 0x80056FF8: nop
    
            goto L_80057008;
    }
    // 0x80056FF8: nop

    // 0x80056FFC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80057000: nop

    // 0x80057004: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_80057008:
    // 0x80057008: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
L_8005700C:
    // 0x8005700C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80057010: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80057014: c.lt.d      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.d < ctx->f0.d;
    // 0x80057018: nop

    // 0x8005701C: bc1f        L_8005702C
    if (!c1cs) {
        // 0x80057020: nop
    
            goto L_8005702C;
    }
    // 0x80057020: nop

    // 0x80057024: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80057028: nop

L_8005702C:
    // 0x8005702C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80057030: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80057034: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80057038: add.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8005703C: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80057040: nop

    // 0x80057044: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80057048: swc1        $f6, -0x2508($at)
    MEM_W(-0X2508, ctx->r1) = ctx->f6.u32l;
    // 0x8005704C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80057050: swc1        $f8, -0x2504($at)
    MEM_W(-0X2504, ctx->r1) = ctx->f8.u32l;
    // 0x80057054: lh          $t8, 0x18E($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X18E);
    // 0x80057058: nop

    // 0x8005705C: beq         $t8, $zero, L_80057078
    if (ctx->r24 == 0) {
        // 0x80057060: nop
    
            goto L_80057078;
    }
    // 0x80057060: nop

    // 0x80057064: lb          $t9, 0x195($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X195);
    // 0x80057068: nop

    // 0x8005706C: bne         $t9, $zero, L_8005707C
    if (ctx->r25 != 0) {
        // 0x80057070: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005707C;
    }
    // 0x80057070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057074: sb          $zero, 0x175($a3)
    MEM_B(0X175, ctx->r7) = 0;
L_80057078:
    // 0x80057078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005707C:
    // 0x8005707C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80057080: jr          $ra
    // 0x80057084: nop

    return;
    // 0x80057084: nop

;}
RECOMP_FUNC void emitter_init_with_pos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF7FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AF800: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AF804: lw          $t8, 0x328C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X328C);
    // 0x800AF808: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800AF80C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AF810: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AF814: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800AF818: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AF81C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800AF820: sh          $a2, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r6;
    // 0x800AF824: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
    // 0x800AF828: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800AF82C: lh          $t1, 0x3A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3A);
    // 0x800AF830: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AF834: sh          $t1, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r9;
    // 0x800AF838: lh          $t2, 0x3E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3E);
    // 0x800AF83C: sh          $zero, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = 0;
    // 0x800AF840: sh          $t2, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r10;
    // 0x800AF844: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AF848: addiu       $t4, $zero, 0x4000
    ctx->r12 = ADD32(0, 0X4000);
    // 0x800AF84C: andi        $t3, $v0, 0x4000
    ctx->r11 = ctx->r2 & 0X4000;
    // 0x800AF850: beq         $t3, $zero, L_800AF874
    if (ctx->r11 == 0) {
        // 0x800AF854: andi        $t5, $v0, 0x400
        ctx->r13 = ctx->r2 & 0X400;
            goto L_800AF874;
    }
    // 0x800AF854: andi        $t5, $v0, 0x400
    ctx->r13 = ctx->r2 & 0X400;
    // 0x800AF858: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AF85C: sh          $t4, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r12;
    // 0x800AF860: sb          $zero, 0x6($a0)
    MEM_B(0X6, ctx->r4) = 0;
    // 0x800AF864: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x800AF868: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x800AF86C: b           L_800AF954
    // 0x800AF870: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
        goto L_800AF954;
    // 0x800AF870: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
L_800AF874:
    // 0x800AF874: beq         $t5, $zero, L_800AF908
    if (ctx->r13 == 0) {
        // 0x800AF878: addiu       $t6, $zero, 0x400
        ctx->r14 = ADD32(0, 0X400);
            goto L_800AF908;
    }
    // 0x800AF878: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x800AF87C: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    // 0x800AF880: sh          $t6, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r14;
    // 0x800AF884: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AF888: lw          $t7, 0x3280($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3280);
    // 0x800AF88C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800AF890: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AF894: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800AF898: lui         $a1, 0x8080
    ctx->r5 = S32(0X8080 << 16);
    // 0x800AF89C: lh          $v0, 0x8($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X8);
    // 0x800AF8A0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800AF8A4: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800AF8A8: beq         $at, $zero, L_800AF8B8
    if (ctx->r1 == 0) {
        // 0x800AF8AC: ori         $a1, $a1, 0x8080
        ctx->r5 = ctx->r5 | 0X8080;
            goto L_800AF8B8;
    }
    // 0x800AF8AC: ori         $a1, $a1, 0x8080
    ctx->r5 = ctx->r5 | 0X8080;
    // 0x800AF8B0: b           L_800AF8BC
    // 0x800AF8B4: sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
        goto L_800AF8BC;
    // 0x800AF8B4: sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
L_800AF8B8:
    // 0x800AF8B8: sb          $t1, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r9;
L_800AF8BC:
    // 0x800AF8BC: lbu         $a0, 0x7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X7);
    // 0x800AF8C0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800AF8C4: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x800AF8C8: jal         0x80070EDC
    // 0x800AF8CC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800AF8CC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_0:
    // 0x800AF8D0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800AF8D4: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x800AF8D8: lh          $t3, 0x14($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X14);
    // 0x800AF8DC: nop

    // 0x800AF8E0: sh          $t3, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r11;
    // 0x800AF8E4: lh          $t4, 0x16($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X16);
    // 0x800AF8E8: nop

    // 0x800AF8EC: sh          $t4, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r12;
    // 0x800AF8F0: lh          $t5, 0x22($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X22);
    // 0x800AF8F4: nop

    // 0x800AF8F8: sh          $t5, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r13;
    // 0x800AF8FC: lh          $t6, 0x24($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X24);
    // 0x800AF900: b           L_800AF954
    // 0x800AF904: sh          $t6, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r14;
        goto L_800AF954;
    // 0x800AF904: sh          $t6, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r14;
L_800AF908:
    // 0x800AF908: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x800AF90C: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x800AF910: nop

    // 0x800AF914: sh          $t7, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r15;
    // 0x800AF918: lh          $t8, 0x16($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X16);
    // 0x800AF91C: nop

    // 0x800AF920: sh          $t8, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r24;
    // 0x800AF924: lh          $t9, 0x18($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X18);
    // 0x800AF928: nop

    // 0x800AF92C: sh          $t9, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r25;
    // 0x800AF930: lh          $t0, 0x22($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X22);
    // 0x800AF934: nop

    // 0x800AF938: sh          $t0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r8;
    // 0x800AF93C: lh          $t1, 0x24($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X24);
    // 0x800AF940: nop

    // 0x800AF944: sh          $t1, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r9;
    // 0x800AF948: lh          $t2, 0x26($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X26);
    // 0x800AF94C: nop

    // 0x800AF950: sh          $t2, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r10;
L_800AF954:
    // 0x800AF954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF958: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AF95C: jr          $ra
    // 0x800AF960: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AF960: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mark_read_eeprom_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF04: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EF08: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EF0C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EF10: nop

    // 0x8006EF14: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x8006EF18: jr          $ra
    // 0x8006EF1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EF1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void get_character_id_from_slot_unused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C780: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C784: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009C788: lb          $v0, 0x6990($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6990);
    // 0x8009C78C: jr          $ra
    // 0x8009C790: nop

    return;
    // 0x8009C790: nop

;}
RECOMP_FUNC void __allocParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800658A8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800658AC: lw          $v0, 0x3D10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3D10);
    // 0x800658B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800658B4: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x800658B8: nop

    // 0x800658BC: beq         $a0, $zero, L_800658D4
    if (ctx->r4 == 0) {
        // 0x800658C0: nop
    
            goto L_800658D4;
    }
    // 0x800658C0: nop

    // 0x800658C4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800658C8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800658CC: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x800658D0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800658D4:
    // 0x800658D4: jr          $ra
    // 0x800658D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800658D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mempool_print_tags_usb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071D1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071D20: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x80071D24: jal         0x80071C64
    // 0x80071D28: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_0;
    // 0x80071D28: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_0:
    // 0x80071D2C: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x80071D30: jal         0x80071C64
    // 0x80071D34: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_1;
    // 0x80071D34: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_1:
    // 0x80071D38: jal         0x80071C64
    // 0x80071D3C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_2;
    // 0x80071D3C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    after_2:
    // 0x80071D40: lui         $a0, 0xFFFF
    ctx->r4 = S32(0XFFFF << 16);
    // 0x80071D44: jal         0x80071C64
    // 0x80071D48: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_3;
    // 0x80071D48: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_3:
    // 0x80071D4C: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x80071D50: jal         0x80071C64
    // 0x80071D54: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_4;
    // 0x80071D54: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_4:
    // 0x80071D58: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x80071D5C: jal         0x80071C64
    // 0x80071D60: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_5;
    // 0x80071D60: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_5:
    // 0x80071D64: jal         0x80071C64
    // 0x80071D68: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    get_memory_colour_tag_count(rdram, ctx);
        goto after_6;
    // 0x80071D68: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_6:
    // 0x80071D6C: lui         $a0, 0x7F7F
    ctx->r4 = S32(0X7F7F << 16);
    // 0x80071D70: jal         0x80071C64
    // 0x80071D74: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_7;
    // 0x80071D74: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    after_7:
    // 0x80071D78: lui         $a0, 0xFF7F
    ctx->r4 = S32(0XFF7F << 16);
    // 0x80071D7C: jal         0x80071C64
    // 0x80071D80: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_8;
    // 0x80071D80: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    after_8:
    // 0x80071D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071D8C: jr          $ra
    // 0x80071D90: nop

    return;
    // 0x80071D90: nop

;}
