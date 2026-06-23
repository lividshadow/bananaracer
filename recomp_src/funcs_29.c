#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void camEnableUserView(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066A58: beq         $a1, $zero, L_80066A94
    if (ctx->r5 == 0) {
        // 0x80066A5C: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_80066A94;
    }
    // 0x80066A5C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80066A60: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066A64: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066A68: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066A6C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066A70: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80066A74: addiu       $t7, $t7, -0x2A2C
    ctx->r15 = ADD32(ctx->r15, -0X2A2C);
    // 0x80066A78: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066A7C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80066A80: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x80066A84: nop

    // 0x80066A88: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80066A8C: b           L_80066AC0
    // 0x80066A90: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
        goto L_80066AC0;
    // 0x80066A90: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_80066A94:
    // 0x80066A94: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80066A98: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80066A9C: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x80066AA0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80066AA4: addiu       $t1, $t1, -0x2A2C
    ctx->r9 = ADD32(ctx->r9, -0X2A2C);
    // 0x80066AA8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80066AAC: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80066AB0: lw          $t2, 0x30($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X30);
    // 0x80066AB4: nop

    // 0x80066AB8: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x80066ABC: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
L_80066AC0:
    // 0x80066AC0: lw          $t4, 0x30($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30);
    // 0x80066AC4: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80066AC8: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80066ACC: jr          $ra
    // 0x80066AD0: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
    return;
    // 0x80066AD0: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void func_8001E93C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E970: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8001E974: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001E978: lb          $t6, -0x4C02($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X4C02);
    // 0x8001E97C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001E980: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001E984: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001E988: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001E98C: beq         $t6, $zero, L_8001EA1C
    if (ctx->r14 == 0) {
        // 0x8001E990: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8001EA1C;
    }
    // 0x8001E990: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001E994: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001E998: lh          $a0, -0x4C08($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4C08);
    // 0x8001E99C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001E9A0: blez        $a0, L_8001EA1C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001E9A4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8001EA1C;
    }
    // 0x8001E9A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001E9A8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001E9AC: addiu       $t5, $t5, -0x4C0C
    ctx->r13 = ADD32(ctx->r13, -0X4C0C);
    // 0x8001E9B0: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
L_8001E9B4:
    // 0x8001E9B4: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001E9B8: nop

    // 0x8001E9BC: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x8001E9C0: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001E9C4: nop

    // 0x8001E9C8: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8001E9CC: lw          $t0, 0x3C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X3C);
    // 0x8001E9D0: beq         $v1, $zero, L_8001EA0C
    if (ctx->r3 == 0) {
        // 0x8001E9D4: nop
    
            goto L_8001EA0C;
    }
    // 0x8001E9D4: nop

    // 0x8001E9D8: lb          $t9, 0x21($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X21);
    // 0x8001E9DC: nop

    // 0x8001E9E0: beq         $s0, $t9, L_8001EA0C
    if (ctx->r16 == ctx->r25) {
        // 0x8001E9E4: nop
    
            goto L_8001EA0C;
    }
    // 0x8001E9E4: nop

    // 0x8001E9E8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001E9EC: jal         0x8000FFB8
    // 0x8001E9F0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    free_object(rdram, ctx);
        goto after_0;
    // 0x8001E9F0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8001E9F4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8001E9F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001E9FC: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x8001EA00: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001EA04: lh          $a0, -0x4C08($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4C08);
    // 0x8001EA08: addiu       $t5, $t5, -0x4C0C
    ctx->r13 = ADD32(ctx->r13, -0X4C0C);
L_8001EA0C:
    // 0x8001EA0C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001EA10: slt         $at, $s3, $a0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001EA14: bne         $at, $zero, L_8001E9B4
    if (ctx->r1 != 0) {
        // 0x8001EA18: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8001E9B4;
    }
    // 0x8001EA18: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8001EA1C:
    // 0x8001EA1C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001EA20: addiu       $v0, $v0, -0x4D42
    ctx->r2 = ADD32(ctx->r2, -0X4D42);
    // 0x8001EA24: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8001EA28: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
    // 0x8001EA2C: slti        $at, $t6, 0x15
    ctx->r1 = SIGNED(ctx->r14) < 0X15 ? 1 : 0;
    // 0x8001EA30: bne         $at, $zero, L_8001EA3C
    if (ctx->r1 != 0) {
        // 0x8001EA34: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001EA3C;
    }
    // 0x8001EA34: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001EA38: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_8001EA3C:
    // 0x8001EA3C: jal         0x8001E4F8
    // 0x8001EA40: nop

    func_8001E4C4(rdram, ctx);
        goto after_1;
    // 0x8001EA40: nop

    after_1:
    // 0x8001EA44: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001EA48: lw          $a2, -0x4C24($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C24);
    // 0x8001EA4C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001EA50: blez        $a2, L_8001EAE0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001EA54: addiu       $t5, $t5, -0x4C0C
        ctx->r13 = ADD32(ctx->r13, -0X4C0C);
            goto L_8001EAE0;
    }
    // 0x8001EA54: addiu       $t5, $t5, -0x4C0C
    ctx->r13 = ADD32(ctx->r13, -0X4C0C);
    // 0x8001EA58: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001EA5C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001EA60: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001EA64: lw          $a1, -0x4C28($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4C28);
    // 0x8001EA68: addiu       $t1, $t1, -0x4C06
    ctx->r9 = ADD32(ctx->r9, -0X4C06);
    // 0x8001EA6C: addiu       $t3, $t3, -0x4CA8
    ctx->r11 = ADD32(ctx->r11, -0X4CA8);
    // 0x8001EA70: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8001EA74: sll         $a3, $a2, 2
    ctx->r7 = S32(ctx->r6 << 2);
    // 0x8001EA78: addiu       $t0, $zero, 0x53
    ctx->r8 = ADD32(0, 0X53);
L_8001EA7C:
    // 0x8001EA7C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8001EA80: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001EA84: beq         $v0, $zero, L_8001EAD8
    if (ctx->r2 == 0) {
        // 0x8001EA88: slt         $at, $t2, $a3
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_8001EAD8;
    }
    // 0x8001EA88: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001EA8C: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8001EA90: nop

    // 0x8001EA94: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8001EA98: bne         $t8, $zero, L_8001EAD8
    if (ctx->r24 != 0) {
        // 0x8001EA9C: nop
    
            goto L_8001EAD8;
    }
    // 0x8001EA9C: nop

    // 0x8001EAA0: lh          $t9, 0x48($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X48);
    // 0x8001EAA4: nop

    // 0x8001EAA8: bne         $t0, $t9, L_8001EAD8
    if (ctx->r8 != ctx->r25) {
        // 0x8001EAAC: nop
    
            goto L_8001EAD8;
    }
    // 0x8001EAAC: nop

    // 0x8001EAB0: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x8001EAB4: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x8001EAB8: lb          $a0, 0x9($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X9);
    // 0x8001EABC: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x8001EAC0: beq         $t6, $a0, L_8001EAD0
    if (ctx->r14 == ctx->r4) {
        // 0x8001EAC4: addu        $t8, $t3, $t7
        ctx->r24 = ADD32(ctx->r11, ctx->r15);
            goto L_8001EAD0;
    }
    // 0x8001EAC4: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x8001EAC8: bne         $s0, $a0, L_8001EAD8
    if (ctx->r16 != ctx->r4) {
        // 0x8001EACC: nop
    
            goto L_8001EAD8;
    }
    // 0x8001EACC: nop

L_8001EAD0:
    // 0x8001EAD0: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8001EAD4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8001EAD8:
    // 0x8001EAD8: bne         $at, $zero, L_8001EA7C
    if (ctx->r1 != 0) {
        // 0x8001EADC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001EA7C;
    }
    // 0x8001EADC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001EAE0:
    // 0x8001EAE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001EAE4: sb          $s3, -0x4C80($at)
    MEM_B(-0X4C80, ctx->r1) = ctx->r19;
    // 0x8001EAE8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8001EAEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001EAF0: sb          $s2, -0x4C7F($at)
    MEM_B(-0X4C7F, ctx->r1) = ctx->r18;
    // 0x8001EAF4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001EAF8: lw          $t4, -0x4C20($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4C20);
    // 0x8001EAFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001EB00: sh          $zero, -0x4C08($at)
    MEM_H(-0X4C08, ctx->r1) = 0;
    // 0x8001EB04: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001EB08: beq         $at, $zero, L_8001EB84
    if (ctx->r1 == 0) {
        // 0x8001EB0C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001EB84;
    }
    // 0x8001EB0C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001EB10: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001EB14: addiu       $v1, $v1, -0x4C28
    ctx->r3 = ADD32(ctx->r3, -0X4C28);
    // 0x8001EB18: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8001EB1C: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
L_8001EB20:
    // 0x8001EB20: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8001EB24: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8001EB28: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8001EB2C: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8001EB30: nop

    // 0x8001EB34: beq         $v0, $zero, L_8001EB7C
    if (ctx->r2 == 0) {
        // 0x8001EB38: slt         $at, $t4, $a2
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001EB7C;
    }
    // 0x8001EB38: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001EB3C: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8001EB40: nop

    // 0x8001EB44: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8001EB48: bne         $t8, $zero, L_8001EB7C
    if (ctx->r24 != 0) {
        // 0x8001EB4C: slt         $at, $t4, $a2
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001EB7C;
    }
    // 0x8001EB4C: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001EB50: lh          $t9, 0x48($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X48);
    // 0x8001EB54: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x8001EB58: bne         $a0, $t9, L_8001EB7C
    if (ctx->r4 != ctx->r25) {
        // 0x8001EB5C: slt         $at, $t4, $a2
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001EB7C;
    }
    // 0x8001EB5C: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001EB60: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001EB64: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001EB68: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001EB6C: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8001EB70: lw          $a2, -0x4C24($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C24);
    // 0x8001EB74: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001EB78: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
L_8001EB7C:
    // 0x8001EB7C: bne         $at, $zero, L_8001EB20
    if (ctx->r1 != 0) {
        // 0x8001EB80: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_8001EB20;
    }
    // 0x8001EB80: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
L_8001EB84:
    // 0x8001EB84: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8001EB88: addiu       $ra, $s3, -0x1
    ctx->r31 = ADD32(ctx->r19, -0X1);
    // 0x8001EB8C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8001EB90:
    // 0x8001EB90: blez        $ra, L_8001EC98
    if (SIGNED(ctx->r31) <= 0) {
        // 0x8001EB94: or          $t3, $s2, $zero
        ctx->r11 = ctx->r18 | 0;
            goto L_8001EC98;
    }
    // 0x8001EB94: or          $t3, $s2, $zero
    ctx->r11 = ctx->r18 | 0;
    // 0x8001EB98: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8001EB9C:
    // 0x8001EB9C: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8001EBA0: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8001EBA4: addu        $a1, $t9, $t2
    ctx->r5 = ADD32(ctx->r25, ctx->r10);
    // 0x8001EBA8: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x8001EBAC: lw          $a3, 0x4($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X4);
    // 0x8001EBB0: lw          $t1, 0x3C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X3C);
    // 0x8001EBB4: lw          $a0, 0x3C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X3C);
    // 0x8001EBB8: lb          $t6, 0x21($t1)
    ctx->r14 = MEM_B(ctx->r9, 0X21);
    // 0x8001EBBC: lb          $v0, 0x10($t1)
    ctx->r2 = MEM_B(ctx->r9, 0X10);
    // 0x8001EBC0: lb          $v1, 0x10($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X10);
    // 0x8001EBC4: bne         $s0, $t6, L_8001EBD8
    if (ctx->r16 != ctx->r14) {
        // 0x8001EBC8: nop
    
            goto L_8001EBD8;
    }
    // 0x8001EBC8: nop

    // 0x8001EBCC: addiu       $v0, $v0, -0x190
    ctx->r2 = ADD32(ctx->r2, -0X190);
    // 0x8001EBD0: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x8001EBD4: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
L_8001EBD8:
    // 0x8001EBD8: lb          $t9, 0x21($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X21);
    // 0x8001EBDC: nop

    // 0x8001EBE0: bne         $s0, $t9, L_8001EBF8
    if (ctx->r16 != ctx->r25) {
        // 0x8001EBE4: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001EBF8;
    }
    // 0x8001EBE4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001EBE8: addiu       $v1, $v1, -0x190
    ctx->r3 = ADD32(ctx->r3, -0X190);
    // 0x8001EBEC: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8001EBF0: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001EBF4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_8001EBF8:
    // 0x8001EBF8: beq         $at, $zero, L_8001EC18
    if (ctx->r1 == 0) {
        // 0x8001EBFC: nop
    
            goto L_8001EC18;
    }
    // 0x8001EBFC: nop

    // 0x8001EC00: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x8001EC04: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8001EC08: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8001EC0C: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001EC10: b           L_8001EC8C
    // 0x8001EC14: sw          $a2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r6;
        goto L_8001EC8C;
    // 0x8001EC14: sw          $a2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r6;
L_8001EC18:
    // 0x8001EC18: bne         $v0, $v1, L_8001EC8C
    if (ctx->r2 != ctx->r3) {
        // 0x8001EC1C: nop
    
            goto L_8001EC8C;
    }
    // 0x8001EC1C: nop

    // 0x8001EC20: lb          $v0, 0x11($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X11);
    // 0x8001EC24: lb          $v1, 0x11($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X11);
    // 0x8001EC28: nop

    // 0x8001EC2C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001EC30: beq         $at, $zero, L_8001EC50
    if (ctx->r1 == 0) {
        // 0x8001EC34: nop
    
            goto L_8001EC50;
    }
    // 0x8001EC34: nop

    // 0x8001EC38: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x8001EC3C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001EC40: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8001EC44: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8001EC48: b           L_8001EC8C
    // 0x8001EC4C: sw          $a2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r6;
        goto L_8001EC8C;
    // 0x8001EC4C: sw          $a2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r6;
L_8001EC50:
    // 0x8001EC50: bne         $v0, $v1, L_8001EC8C
    if (ctx->r2 != ctx->r3) {
        // 0x8001EC54: nop
    
            goto L_8001EC8C;
    }
    // 0x8001EC54: nop

    // 0x8001EC58: lw          $t8, 0x78($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X78);
    // 0x8001EC5C: nop

    // 0x8001EC60: beq         $s2, $t8, L_8001EC78
    if (ctx->r18 == ctx->r24) {
        // 0x8001EC64: nop
    
            goto L_8001EC78;
    }
    // 0x8001EC64: nop

    // 0x8001EC68: lw          $t9, 0x78($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X78);
    // 0x8001EC6C: nop

    // 0x8001EC70: bne         $s1, $t9, L_8001EC8C
    if (ctx->r17 != ctx->r25) {
        // 0x8001EC74: nop
    
            goto L_8001EC8C;
    }
    // 0x8001EC74: nop

L_8001EC78:
    // 0x8001EC78: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x8001EC7C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001EC80: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8001EC84: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8001EC88: sw          $a2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r6;
L_8001EC8C:
    // 0x8001EC8C: bne         $t4, $ra, L_8001EB9C
    if (ctx->r12 != ctx->r31) {
        // 0x8001EC90: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_8001EB9C;
    }
    // 0x8001EC90: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001EC94: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_8001EC98:
    // 0x8001EC98: beq         $t3, $zero, L_8001EB90
    if (ctx->r11 == 0) {
        // 0x8001EC9C: nop
    
            goto L_8001EB90;
    }
    // 0x8001EC9C: nop

    // 0x8001ECA0: blez        $s3, L_8001EE68
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8001ECA4: addiu       $a0, $zero, -0x65
        ctx->r4 = ADD32(0, -0X65);
            goto L_8001EE68;
    }
    // 0x8001ECA4: addiu       $a0, $zero, -0x65
    ctx->r4 = ADD32(0, -0X65);
    // 0x8001ECA8: andi        $v0, $s3, 0x3
    ctx->r2 = ctx->r19 & 0X3;
    // 0x8001ECAC: beq         $v0, $zero, L_8001ED18
    if (ctx->r2 == 0) {
        // 0x8001ECB0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8001ED18;
    }
    // 0x8001ECB0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001ECB4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8001ECB8: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
L_8001ECBC:
    // 0x8001ECBC: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8001ECC0: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8001ECC4: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001ECC8: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8001ECCC: nop

    // 0x8001ECD0: lw          $t1, 0x3C($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X3C);
    // 0x8001ECD4: nop

    // 0x8001ECD8: lb          $t7, 0x10($t1)
    ctx->r15 = MEM_B(ctx->r9, 0X10);
    // 0x8001ECDC: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x8001ECE0: beq         $a0, $t7, L_8001ECF0
    if (ctx->r4 == ctx->r15) {
        // 0x8001ECE4: nop
    
            goto L_8001ECF0;
    }
    // 0x8001ECE4: nop

    // 0x8001ECE8: lb          $a0, 0x10($t1)
    ctx->r4 = MEM_B(ctx->r9, 0X10);
    // 0x8001ECEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001ECF0:
    // 0x8001ECF0: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8001ECF4: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8001ECF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001ECFC: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001ED00: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8001ED04: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001ED08: bne         $v1, $t4, L_8001ECBC
    if (ctx->r3 != ctx->r12) {
        // 0x8001ED0C: sw          $zero, 0x78($t6)
        MEM_W(0X78, ctx->r14) = 0;
            goto L_8001ECBC;
    }
    // 0x8001ED0C: sw          $zero, 0x78($t6)
    MEM_W(0X78, ctx->r14) = 0;
    // 0x8001ED10: beq         $t4, $s3, L_8001EE68
    if (ctx->r12 == ctx->r19) {
        // 0x8001ED14: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_8001EE68;
    }
    // 0x8001ED14: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_8001ED18:
    // 0x8001ED18: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8001ED1C: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8001ED20: sll         $a1, $s3, 2
    ctx->r5 = S32(ctx->r19 << 2);
L_8001ED24:
    // 0x8001ED24: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001ED28: nop

    // 0x8001ED2C: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x8001ED30: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8001ED34: nop

    // 0x8001ED38: lw          $t1, 0x3C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X3C);
    // 0x8001ED3C: nop

    // 0x8001ED40: lb          $t6, 0x10($t1)
    ctx->r14 = MEM_B(ctx->r9, 0X10);
    // 0x8001ED44: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x8001ED48: beq         $a0, $t6, L_8001ED58
    if (ctx->r4 == ctx->r14) {
        // 0x8001ED4C: nop
    
            goto L_8001ED58;
    }
    // 0x8001ED4C: nop

    // 0x8001ED50: lb          $a0, 0x10($t1)
    ctx->r4 = MEM_B(ctx->r9, 0X10);
    // 0x8001ED54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001ED58:
    // 0x8001ED58: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8001ED5C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001ED60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001ED64: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x8001ED68: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8001ED6C: nop

    // 0x8001ED70: sw          $zero, 0x78($t9)
    MEM_W(0X78, ctx->r25) = 0;
    // 0x8001ED74: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001ED78: nop

    // 0x8001ED7C: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8001ED80: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8001ED84: nop

    // 0x8001ED88: lw          $t0, 0x3C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X3C);
    // 0x8001ED8C: nop

    // 0x8001ED90: lb          $v1, 0x10($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X10);
    // 0x8001ED94: nop

    // 0x8001ED98: beq         $a0, $v1, L_8001EDA8
    if (ctx->r4 == ctx->r3) {
        // 0x8001ED9C: nop
    
            goto L_8001EDA8;
    }
    // 0x8001ED9C: nop

    // 0x8001EDA0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001EDA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001EDA8:
    // 0x8001EDA8: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8001EDAC: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8001EDB0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001EDB4: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8001EDB8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8001EDBC: nop

    // 0x8001EDC0: sw          $zero, 0x78($t7)
    MEM_W(0X78, ctx->r15) = 0;
    // 0x8001EDC4: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8001EDC8: nop

    // 0x8001EDCC: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001EDD0: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x8001EDD4: nop

    // 0x8001EDD8: lw          $t0, 0x3C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X3C);
    // 0x8001EDDC: nop

    // 0x8001EDE0: lb          $v1, 0x10($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X10);
    // 0x8001EDE4: nop

    // 0x8001EDE8: beq         $a0, $v1, L_8001EDF8
    if (ctx->r4 == ctx->r3) {
        // 0x8001EDEC: nop
    
            goto L_8001EDF8;
    }
    // 0x8001EDEC: nop

    // 0x8001EDF0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001EDF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001EDF8:
    // 0x8001EDF8: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8001EDFC: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001EE00: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001EE04: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x8001EE08: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8001EE0C: nop

    // 0x8001EE10: sw          $zero, 0x78($t9)
    MEM_W(0X78, ctx->r25) = 0;
    // 0x8001EE14: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001EE18: nop

    // 0x8001EE1C: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8001EE20: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8001EE24: nop

    // 0x8001EE28: lw          $t0, 0x3C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X3C);
    // 0x8001EE2C: nop

    // 0x8001EE30: lb          $v1, 0x10($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X10);
    // 0x8001EE34: nop

    // 0x8001EE38: beq         $a0, $v1, L_8001EE48
    if (ctx->r4 == ctx->r3) {
        // 0x8001EE3C: nop
    
            goto L_8001EE48;
    }
    // 0x8001EE3C: nop

    // 0x8001EE40: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001EE44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001EE48:
    // 0x8001EE48: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8001EE4C: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8001EE50: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001EE54: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8001EE58: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8001EE5C: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x8001EE60: bne         $t2, $a1, L_8001ED24
    if (ctx->r10 != ctx->r5) {
        // 0x8001EE64: sw          $zero, 0x78($t7)
        MEM_W(0X78, ctx->r15) = 0;
            goto L_8001ED24;
    }
    // 0x8001EE64: sw          $zero, 0x78($t7)
    MEM_W(0X78, ctx->r15) = 0;
L_8001EE68:
    // 0x8001EE68: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001EE6C: lb          $t8, -0x4C02($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X4C02);
    // 0x8001EE70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001EE74: beq         $t8, $zero, L_8001EE84
    if (ctx->r24 == 0) {
        // 0x8001EE78: sh          $s3, -0x4C08($at)
        MEM_H(-0X4C08, ctx->r1) = ctx->r19;
            goto L_8001EE84;
    }
    // 0x8001EE78: sh          $s3, -0x4C08($at)
    MEM_H(-0X4C08, ctx->r1) = ctx->r19;
    // 0x8001EE7C: jal         0x8001EEA8
    // 0x8001EE80: nop

    func_8001EE74(rdram, ctx);
        goto after_2;
    // 0x8001EE80: nop

    after_2:
L_8001EE84:
    // 0x8001EE84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001EE88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001EE8C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001EE90: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001EE94: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EE98: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001EE9C: sb          $zero, -0x4C02($at)
    MEM_B(-0X4C02, ctx->r1) = 0;
    // 0x8001EEA0: jr          $ra
    // 0x8001EEA4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8001EEA4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void hud_draw_eggs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1A30: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800A1A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1A38: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800A1A3C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800A1A40: jal         0x8001BAA8
    // 0x800A1A44: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800A1A44: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x800A1A48: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A1A4C: lbu         $t6, 0x72F7($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X72F7);
    // 0x800A1A50: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x800A1A54: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800A1A58: bne         $t4, $t6, L_800A1BCC
    if (ctx->r12 != ctx->r14) {
        // 0x800A1A5C: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800A1BCC;
    }
    // 0x800A1A5C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800A1A60: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800A1A64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A1A68: blez        $t7, L_800A1BC4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A1A6C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800A1BC4;
    }
    // 0x800A1A6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A1A70: andi        $v1, $t7, 0x3
    ctx->r3 = ctx->r15 & 0X3;
    // 0x800A1A74: beq         $v1, $zero, L_800A1AD4
    if (ctx->r3 == 0) {
        // 0x800A1A78: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_800A1AD4;
    }
    // 0x800A1A78: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800A1A7C: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x800A1A80: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    // 0x800A1A84: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800A1A88:
    // 0x800A1A88: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800A1A8C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800A1A90: lw          $v1, 0x64($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X64);
    // 0x800A1A94: nop

    // 0x800A1A98: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x800A1A9C: nop

    // 0x800A1AA0: beq         $t0, $t5, L_800A1ABC
    if (ctx->r8 == ctx->r13) {
        // 0x800A1AA4: nop
    
            goto L_800A1ABC;
    }
    // 0x800A1AA4: nop

    // 0x800A1AA8: lb          $t6, 0x1D8($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1D8);
    // 0x800A1AAC: nop

    // 0x800A1AB0: beq         $t6, $zero, L_800A1ABC
    if (ctx->r14 == 0) {
        // 0x800A1AB4: nop
    
            goto L_800A1ABC;
    }
    // 0x800A1AB4: nop

    // 0x800A1AB8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A1ABC:
    // 0x800A1ABC: bne         $t1, $a3, L_800A1A88
    if (ctx->r9 != ctx->r7) {
        // 0x800A1AC0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800A1A88;
    }
    // 0x800A1AC0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800A1AC4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800A1AC8: nop

    // 0x800A1ACC: beq         $a3, $t7, L_800A1BC4
    if (ctx->r7 == ctx->r15) {
        // 0x800A1AD0: nop
    
            goto L_800A1BC4;
    }
    // 0x800A1AD0: nop

L_800A1AD4:
    // 0x800A1AD4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800A1AD8: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x800A1ADC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A1AE0: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800A1AE4: addu        $a1, $v0, $t5
    ctx->r5 = ADD32(ctx->r2, ctx->r13);
    // 0x800A1AE8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800A1AEC:
    // 0x800A1AEC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800A1AF0: nop

    // 0x800A1AF4: lw          $v1, 0x64($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X64);
    // 0x800A1AF8: nop

    // 0x800A1AFC: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800A1B00: nop

    // 0x800A1B04: beq         $t0, $t7, L_800A1B20
    if (ctx->r8 == ctx->r15) {
        // 0x800A1B08: nop
    
            goto L_800A1B20;
    }
    // 0x800A1B08: nop

    // 0x800A1B0C: lb          $t8, 0x1D8($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X1D8);
    // 0x800A1B10: nop

    // 0x800A1B14: beq         $t8, $zero, L_800A1B20
    if (ctx->r24 == 0) {
        // 0x800A1B18: nop
    
            goto L_800A1B20;
    }
    // 0x800A1B18: nop

    // 0x800A1B1C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A1B20:
    // 0x800A1B20: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800A1B24: nop

    // 0x800A1B28: lw          $a0, 0x64($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X64);
    // 0x800A1B2C: nop

    // 0x800A1B30: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
    // 0x800A1B34: nop

    // 0x800A1B38: beq         $t0, $t5, L_800A1B54
    if (ctx->r8 == ctx->r13) {
        // 0x800A1B3C: nop
    
            goto L_800A1B54;
    }
    // 0x800A1B3C: nop

    // 0x800A1B40: lb          $t6, 0x1D8($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1D8);
    // 0x800A1B44: nop

    // 0x800A1B48: beq         $t6, $zero, L_800A1B54
    if (ctx->r14 == 0) {
        // 0x800A1B4C: nop
    
            goto L_800A1B54;
    }
    // 0x800A1B4C: nop

    // 0x800A1B50: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A1B54:
    // 0x800A1B54: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800A1B58: nop

    // 0x800A1B5C: lw          $a0, 0x64($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X64);
    // 0x800A1B60: nop

    // 0x800A1B64: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x800A1B68: nop

    // 0x800A1B6C: beq         $t0, $t8, L_800A1B88
    if (ctx->r8 == ctx->r24) {
        // 0x800A1B70: nop
    
            goto L_800A1B88;
    }
    // 0x800A1B70: nop

    // 0x800A1B74: lb          $t9, 0x1D8($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X1D8);
    // 0x800A1B78: nop

    // 0x800A1B7C: beq         $t9, $zero, L_800A1B88
    if (ctx->r25 == 0) {
        // 0x800A1B80: nop
    
            goto L_800A1B88;
    }
    // 0x800A1B80: nop

    // 0x800A1B84: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A1B88:
    // 0x800A1B88: lw          $t5, 0xC($a1)
    ctx->r13 = MEM_W(ctx->r5, 0XC);
    // 0x800A1B8C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800A1B90: lw          $a0, 0x64($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X64);
    // 0x800A1B94: nop

    // 0x800A1B98: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800A1B9C: nop

    // 0x800A1BA0: beq         $t0, $t6, L_800A1BBC
    if (ctx->r8 == ctx->r14) {
        // 0x800A1BA4: nop
    
            goto L_800A1BBC;
    }
    // 0x800A1BA4: nop

    // 0x800A1BA8: lb          $t7, 0x1D8($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X1D8);
    // 0x800A1BAC: nop

    // 0x800A1BB0: beq         $t7, $zero, L_800A1BBC
    if (ctx->r15 == 0) {
        // 0x800A1BB4: nop
    
            goto L_800A1BBC;
    }
    // 0x800A1BB4: nop

    // 0x800A1BB8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A1BBC:
    // 0x800A1BBC: bne         $a1, $t1, L_800A1AEC
    if (ctx->r5 != ctx->r9) {
        // 0x800A1BC0: nop
    
            goto L_800A1AEC;
    }
    // 0x800A1BC0: nop

L_800A1BC4:
    // 0x800A1BC4: beq         $a2, $t4, L_800A1ED8
    if (ctx->r6 == ctx->r12) {
        // 0x800A1BC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A1ED8;
    }
    // 0x800A1BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1BCC:
    // 0x800A1BCC: beq         $t3, $zero, L_800A1BE0
    if (ctx->r11 == 0) {
        // 0x800A1BD0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800A1BE0;
    }
    // 0x800A1BD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A1BD4: lw          $t1, 0x64($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X64);
    // 0x800A1BD8: b           L_800A1BF4
    // 0x800A1BDC: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
        goto L_800A1BF4;
    // 0x800A1BDC: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
L_800A1BE0:
    // 0x800A1BE0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800A1BE4: nop

    // 0x800A1BE8: lw          $t1, 0x64($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X64);
    // 0x800A1BEC: nop

    // 0x800A1BF0: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
L_800A1BF4:
    // 0x800A1BF4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A1BF8: bne         $t9, $at, L_800A1ED4
    if (ctx->r25 != ctx->r1) {
        // 0x800A1BFC: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800A1ED4;
    }
    // 0x800A1BFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A1C00: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800A1C04: jal         0x80068748
    // 0x800A1C08: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x800A1C08: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    after_1:
    // 0x800A1C0C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A1C10: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A1C14: addiu       $a2, $a2, 0x729C
    ctx->r6 = ADD32(ctx->r6, 0X729C);
    // 0x800A1C18: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1C1C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A1C20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1C24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1C28: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A1C2C: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800A1C30: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A1C34: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800A1C38: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A1C3C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800A1C40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A1C44: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A1C48: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800A1C4C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A1C50: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1C54: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1C58: lwc1        $f8, 0x650($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A1C5C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800A1C60: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A1C64: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A1C68: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A1C6C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800A1C70: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A1C74: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x800A1C78: lwc1        $f18, 0x66C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A1C7C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1C80: sub.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x800A1C84: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800A1C88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1C8C: nop

    // 0x800A1C90: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A1C94: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A1C98: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800A1C9C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A1CA0: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x800A1CA4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800A1CA8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800A1CAC: lwc1        $f16, 0x670($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X670);
    // 0x800A1CB0: nop

    // 0x800A1CB4: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800A1CB8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A1CBC: nop

    // 0x800A1CC0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A1CC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1CC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1CCC: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x800A1CD0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A1CD4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A1CD8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A1CDC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800A1CE0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A1CE4: lwc1        $f1, -0x7360($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7360);
    // 0x800A1CE8: lwc1        $f0, -0x735C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X735C);
    // 0x800A1CEC: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800A1CF0: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
L_800A1CF4:
    // 0x800A1CF4: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A1CF8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A1CFC: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A1D00: lw          $v0, 0x64($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X64);
    // 0x800A1D04: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A1D08: bne         $at, $zero, L_800A1D24
    if (ctx->r1 != 0) {
        // 0x800A1D0C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800A1D24;
    }
    // 0x800A1D0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A1D10: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800A1D14: lh          $t8, 0x0($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X0);
    // 0x800A1D18: nop

    // 0x800A1D1C: bne         $t7, $t8, L_800A1D7C
    if (ctx->r15 != ctx->r24) {
        // 0x800A1D20: addiu       $t9, $zero, -0x2
        ctx->r25 = ADD32(0, -0X2);
            goto L_800A1D7C;
    }
    // 0x800A1D20: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
L_800A1D24:
    // 0x800A1D24: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800A1D28: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800A1D2C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800A1D30: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800A1D34: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x800A1D38: jal         0x800A1EE4
    // 0x800A1D3C: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    hud_eggs_portrait(rdram, ctx);
        goto after_2;
    // 0x800A1D3C: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x800A1D40: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A1D44: lwc1        $f1, -0x7358($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7358);
    // 0x800A1D48: lwc1        $f0, -0x7354($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7354);
    // 0x800A1D4C: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x800A1D50: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A1D54: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A1D58: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A1D5C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A1D60: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800A1D64: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800A1D68: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800A1D6C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800A1D70: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800A1D74: addiu       $a2, $a2, 0x729C
    ctx->r6 = ADD32(ctx->r6, 0X729C);
    // 0x800A1D78: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
L_800A1D7C:
    // 0x800A1D7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A1D80: sw          $t9, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = ctx->r25;
    // 0x800A1D84: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1D88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A1D8C: bne         $v1, $at, L_800A1DB8
    if (ctx->r3 != ctx->r1) {
        // 0x800A1D90: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_800A1DB8;
    }
    // 0x800A1D90: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800A1D94: lui         $at, 0x4288
    ctx->r1 = S32(0X4288 << 16);
    // 0x800A1D98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A1D9C: lwc1        $f8, 0x64C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A1DA0: nop

    // 0x800A1DA4: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800A1DA8: swc1        $f10, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f10.u32l;
    // 0x800A1DAC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1DB0: b           L_800A1E60
    // 0x800A1DB4: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
        goto L_800A1E60;
    // 0x800A1DB4: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
L_800A1DB8:
    // 0x800A1DB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A1DBC: bne         $v1, $at, L_800A1E5C
    if (ctx->r3 != ctx->r1) {
        // 0x800A1DC0: lui         $t6, 0x8000
        ctx->r14 = S32(0X8000 << 16);
            goto L_800A1E5C;
    }
    // 0x800A1DC0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800A1DC4: swc1        $f14, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f14.u32l;
    // 0x800A1DC8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800A1DCC: nop

    // 0x800A1DD0: bne         $t6, $zero, L_800A1E24
    if (ctx->r14 != 0) {
        // 0x800A1DD4: nop
    
            goto L_800A1E24;
    }
    // 0x800A1DD4: nop

    // 0x800A1DD8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1DDC: nop

    // 0x800A1DE0: lwc1        $f18, 0x650($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A1DE4: nop

    // 0x800A1DE8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800A1DEC: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x800A1DF0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800A1DF4: swc1        $f8, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f8.u32l;
    // 0x800A1DF8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1DFC: nop

    // 0x800A1E00: lwc1        $f16, 0x670($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X670);
    // 0x800A1E04: nop

    // 0x800A1E08: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800A1E0C: add.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f10.d + ctx->f0.d;
    // 0x800A1E10: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800A1E14: swc1        $f4, 0x670($v0)
    MEM_W(0X670, ctx->r2) = ctx->f4.u32l;
    // 0x800A1E18: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1E1C: b           L_800A1E60
    // 0x800A1E20: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
        goto L_800A1E60;
    // 0x800A1E20: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
L_800A1E24:
    // 0x800A1E24: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1E28: nop

    // 0x800A1E2C: lwc1        $f6, 0x650($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A1E30: nop

    // 0x800A1E34: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800A1E38: swc1        $f8, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f8.u32l;
    // 0x800A1E3C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1E40: nop

    // 0x800A1E44: lwc1        $f16, 0x670($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X670);
    // 0x800A1E48: nop

    // 0x800A1E4C: add.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A1E50: swc1        $f10, 0x670($v0)
    MEM_W(0X670, ctx->r2) = ctx->f10.u32l;
    // 0x800A1E54: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1E58: nop

L_800A1E5C:
    // 0x800A1E5C: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
L_800A1E60:
    // 0x800A1E60: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800A1E64: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x800A1E68: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800A1E6C: bne         $a3, $at, L_800A1CF4
    if (ctx->r7 != ctx->r1) {
        // 0x800A1E70: swc1        $f4, 0x66C($v0)
        MEM_W(0X66C, ctx->r2) = ctx->f4.u32l;
            goto L_800A1CF4;
    }
    // 0x800A1E70: swc1        $f4, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f4.u32l;
    // 0x800A1E74: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800A1E78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A1E7C: swc1        $f14, 0x64C($t5)
    MEM_W(0X64C, ctx->r13) = ctx->f14.u32l;
    // 0x800A1E80: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800A1E84: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800A1E88: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800A1E8C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800A1E90: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800A1E94: nop

    // 0x800A1E98: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A1E9C: swc1        $f8, 0x66C($t6)
    MEM_W(0X66C, ctx->r14) = ctx->f8.u32l;
    // 0x800A1EA0: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800A1EA4: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A1EA8: nop

    // 0x800A1EAC: swc1        $f16, 0x650($t5)
    MEM_W(0X650, ctx->r13) = ctx->f16.u32l;
    // 0x800A1EB0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800A1EB4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1EB8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800A1EBC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800A1EC0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800A1EC4: nop

    // 0x800A1EC8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A1ECC: jal         0x80068748
    // 0x800A1ED0: swc1        $f18, 0x670($t6)
    MEM_W(0X670, ctx->r14) = ctx->f18.u32l;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_3;
    // 0x800A1ED0: swc1        $f18, 0x670($t6)
    MEM_W(0X670, ctx->r14) = ctx->f18.u32l;
    after_3:
L_800A1ED4:
    // 0x800A1ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1ED8:
    // 0x800A1ED8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800A1EDC: jr          $ra
    // 0x800A1EE0: nop

    return;
    // 0x800A1EE0: nop

;}
RECOMP_FUNC void shadow_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D3C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002D3C8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002D3CC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8002D3D0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8002D3D4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002D3D8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002D3DC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002D3E0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002D3E4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002D3E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002D3EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D3F0: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x8002D3F4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002D3F8: lh          $t7, 0x32($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X32);
    // 0x8002D3FC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8002D400: beq         $t7, $zero, L_8002D684
    if (ctx->r15 == 0) {
        // 0x8002D404: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8002D684;
    }
    // 0x8002D404: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002D408: lh          $t8, 0x8($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X8);
    // 0x8002D40C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002D410: beq         $t8, $at, L_8002D680
    if (ctx->r24 == ctx->r1) {
        // 0x8002D414: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8002D680;
    }
    // 0x8002D414: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002D418: lw          $t9, -0x49BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X49BC);
    // 0x8002D41C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002D420: bne         $t9, $zero, L_8002D680
    if (ctx->r25 != 0) {
        // 0x8002D424: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8002D680;
    }
    // 0x8002D424: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002D428: lw          $t5, -0x49B8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X49B8);
    // 0x8002D42C: addiu       $a0, $a0, -0x49B4
    ctx->r4 = ADD32(ctx->r4, -0X49B4);
    // 0x8002D430: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8002D434: lw          $t6, 0x40($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X40);
    // 0x8002D438: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002D43C: lh          $t7, 0x32($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X32);
    // 0x8002D440: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002D444: bne         $t7, $at, L_8002D454
    if (ctx->r15 != ctx->r1) {
        // 0x8002D448: addiu       $s4, $s4, -0x2720
        ctx->r20 = ADD32(ctx->r20, -0X2720);
            goto L_8002D454;
    }
    // 0x8002D448: addiu       $s4, $s4, -0x2720
    ctx->r20 = ADD32(ctx->r20, -0X2720);
    // 0x8002D44C: addiu       $t9, $t5, 0x2
    ctx->r25 = ADD32(ctx->r13, 0X2);
    // 0x8002D450: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
L_8002D454:
    // 0x8002D454: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8002D458: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002D45C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8002D460: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8002D464: lw          $t6, -0x2730($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2730);
    // 0x8002D468: lh          $s3, 0x8($a3)
    ctx->r19 = MEM_H(ctx->r7, 0X8);
    // 0x8002D46C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002D470: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8002D474: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8002D478: lw          $t7, -0x2760($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2760);
    // 0x8002D47C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D480: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002D484: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8002D488: sw          $t7, -0x2750($at)
    MEM_W(-0X2750, ctx->r1) = ctx->r15;
    // 0x8002D48C: lw          $t8, -0x2748($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2748);
    // 0x8002D490: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8002D494: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8002D498: addiu       $s7, $s7, -0x2738
    ctx->r23 = ADD32(ctx->r23, -0X2738);
    // 0x8002D49C: sll         $t5, $s3, 3
    ctx->r13 = S32(ctx->r19 << 3);
    // 0x8002D4A0: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x8002D4A4: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x8002D4A8: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x8002D4AC: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x8002D4B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002D4B4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002D4B8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8002D4BC: addu        $t5, $t9, $t8
    ctx->r13 = ADD32(ctx->r25, ctx->r24);
    // 0x8002D4C0: lbu         $v1, 0x9($t5)
    ctx->r3 = MEM_BU(ctx->r13, 0X9);
    // 0x8002D4C4: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x8002D4C8: beq         $v1, $zero, L_8002D4E0
    if (ctx->r3 == 0) {
        // 0x8002D4CC: lui         $s6, 0x500
        ctx->r22 = S32(0X500 << 16);
            goto L_8002D4E0;
    }
    // 0x8002D4CC: lui         $s6, 0x500
    ctx->r22 = S32(0X500 << 16);
    // 0x8002D4D0: lbu         $a1, 0x39($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X39);
    // 0x8002D4D4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002D4D8: bne         $a1, $zero, L_8002D4EC
    if (ctx->r5 != 0) {
        // 0x8002D4DC: nop
    
            goto L_8002D4EC;
    }
    // 0x8002D4DC: nop

L_8002D4E0:
    // 0x8002D4E0: lh          $s3, 0xA($a3)
    ctx->r19 = MEM_H(ctx->r7, 0XA);
    // 0x8002D4E4: b           L_8002D53C
    // 0x8002D4E8: lh          $t6, 0xA($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XA);
        goto L_8002D53C;
    // 0x8002D4E8: lh          $t6, 0xA($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XA);
L_8002D4EC:
    // 0x8002D4EC: bne         $v1, $v0, L_8002D4FC
    if (ctx->r3 != ctx->r2) {
        // 0x8002D4F0: nop
    
            goto L_8002D4FC;
    }
    // 0x8002D4F0: nop

    // 0x8002D4F4: beq         $v0, $a1, L_8002D538
    if (ctx->r2 == ctx->r5) {
        // 0x8002D4F8: nop
    
            goto L_8002D538;
    }
    // 0x8002D4F8: nop

L_8002D4FC:
    // 0x8002D4FC: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002D500: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002D504: addiu       $s1, $s1, -0x49E0
    ctx->r17 = ADD32(ctx->r17, -0X49E0);
    // 0x8002D508: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002D50C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8002D510: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x8002D514: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8002D518: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8002D51C: addiu       $fp, $zero, 0xE
    ctx->r30 = ADD32(0, 0XE);
    // 0x8002D520: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8002D524: mflo        $v1
    ctx->r3 = lo;
    // 0x8002D528: sra         $t6, $v1, 8
    ctx->r14 = S32(SIGNED(ctx->r3) >> 8);
    // 0x8002D52C: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x8002D530: or          $t5, $t8, $at
    ctx->r13 = ctx->r24 | ctx->r1;
    // 0x8002D534: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
L_8002D538:
    // 0x8002D538: lh          $t6, 0xA($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XA);
L_8002D53C:
    // 0x8002D53C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002D540: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002D544: beq         $at, $zero, L_8002D65C
    if (ctx->r1 == 0) {
        // 0x8002D548: addiu       $s1, $s1, -0x49E0
        ctx->r17 = ADD32(ctx->r17, -0X49E0);
            goto L_8002D65C;
    }
    // 0x8002D548: addiu       $s1, $s1, -0x49E0
    ctx->r17 = ADD32(ctx->r17, -0X49E0);
    // 0x8002D54C: sll         $s0, $s3, 3
    ctx->r16 = S32(ctx->r19 << 3);
    // 0x8002D550: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8002D554: lui         $s5, 0x400
    ctx->r21 = S32(0X400 << 16);
    // 0x8002D558: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
L_8002D55C:
    // 0x8002D55C: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8002D560: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002D564: addu        $t9, $t7, $s0
    ctx->r25 = ADD32(ctx->r15, ctx->r16);
    // 0x8002D568: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x8002D56C: jal         0x8007B918
    // 0x8002D570: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    material_set_no_tex_offset(rdram, ctx);
        goto after_0;
    // 0x8002D570: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_0:
    // 0x8002D574: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8002D578: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002D57C: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
    // 0x8002D580: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x8002D584: lh          $a2, 0x6($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X6);
    // 0x8002D588: lh          $t5, 0xC($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XC);
    // 0x8002D58C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8002D590: subu        $a3, $t5, $a1
    ctx->r7 = SUB32(ctx->r13, ctx->r5);
    // 0x8002D594: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x8002D598: lw          $t9, -0x2750($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2750);
    // 0x8002D59C: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x8002D5A0: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x8002D5A4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8002D5A8: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x8002D5AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002D5B0: subu        $v1, $t6, $a2
    ctx->r3 = SUB32(ctx->r14, ctx->r6);
    // 0x8002D5B4: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x8002D5B8: addu        $t4, $t8, $t5
    ctx->r12 = ADD32(ctx->r24, ctx->r13);
    // 0x8002D5BC: addu        $t1, $t4, $s2
    ctx->r9 = ADD32(ctx->r12, ctx->r18);
    // 0x8002D5C0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8002D5C4: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x8002D5C8: andi        $t8, $t1, 0x6
    ctx->r24 = ctx->r9 & 0X6;
    // 0x8002D5CC: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8002D5D0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8002D5D4: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x8002D5D8: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8002D5DC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8002D5E0: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8002D5E4: addu        $t5, $t8, $v1
    ctx->r13 = ADD32(ctx->r24, ctx->r3);
    // 0x8002D5E8: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8002D5EC: or          $t9, $t7, $s5
    ctx->r25 = ctx->r15 | ctx->r21;
    // 0x8002D5F0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002D5F4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8002D5F8: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x8002D5FC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8002D600: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x8002D604: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002D608: addiu       $t7, $a3, -0x1
    ctx->r15 = ADD32(ctx->r7, -0X1);
    // 0x8002D60C: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x8002D610: ori         $t8, $t9, 0x1
    ctx->r24 = ctx->r25 | 0X1;
    // 0x8002D614: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8002D618: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8002D61C: andi        $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 & 0XFF;
    // 0x8002D620: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x8002D624: or          $t7, $t6, $s6
    ctx->r15 = ctx->r14 | ctx->r22;
    // 0x8002D628: sll         $t9, $a3, 4
    ctx->r25 = S32(ctx->r7 << 4);
    // 0x8002D62C: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x8002D630: or          $t5, $t7, $t8
    ctx->r13 = ctx->r15 | ctx->r24;
    // 0x8002D634: addu        $t6, $t3, $s2
    ctx->r14 = ADD32(ctx->r11, ctx->r18);
    // 0x8002D638: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8002D63C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8002D640: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8002D644: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8002D648: lh          $t7, 0xA($t9)
    ctx->r15 = MEM_H(ctx->r25, 0XA);
    // 0x8002D64C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8002D650: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002D654: bne         $at, $zero, L_8002D55C
    if (ctx->r1 != 0) {
        // 0x8002D658: nop
    
            goto L_8002D55C;
    }
    // 0x8002D658: nop

L_8002D65C:
    // 0x8002D65C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002D660: beq         $fp, $at, L_8002D680
    if (ctx->r30 == ctx->r1) {
        // 0x8002D664: lui         $t5, 0xFA00
        ctx->r13 = S32(0XFA00 << 16);
            goto L_8002D680;
    }
    // 0x8002D664: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8002D668: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002D66C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8002D670: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x8002D674: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8002D678: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8002D67C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_8002D680:
    // 0x8002D680: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8002D684:
    // 0x8002D684: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002D688: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D68C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002D690: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002D694: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002D698: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D69C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002D6A0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8002D6A4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8002D6A8: jr          $ra
    // 0x8002D6AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8002D6AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void audspat_reverb_add_vertex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009968: lbu         $a0, 0x13($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X13);
    // 0x8000996C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80009970: slti        $at, $a0, 0x7
    ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x80009974: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80009978: beq         $at, $zero, L_800099E4
    if (ctx->r1 == 0) {
        // 0x8000997C: andi        $t6, $a3, 0xFF
        ctx->r14 = ctx->r7 & 0XFF;
            goto L_800099E4;
    }
    // 0x8000997C: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x80009980: lbu         $v0, 0x17($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X17);
    // 0x80009984: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80009988: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x8000998C: beq         $at, $zero, L_800099E4
    if (ctx->r1 == 0) {
        // 0x80009990: subu        $t7, $t7, $a0
        ctx->r15 = SUB32(ctx->r15, ctx->r4);
            goto L_800099E4;
    }
    // 0x80009990: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80009994: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80009998: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8000999C: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x800099A0: addiu       $t8, $t8, -0x53A8
    ctx->r24 = ADD32(ctx->r24, -0X53A8);
    // 0x800099A4: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x800099A8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800099AC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800099B0: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800099B4: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    // 0x800099B8: swc1        $f12, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f12.u32l;
    // 0x800099BC: swc1        $f14, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f14.u32l;
    // 0x800099C0: bne         $v0, $zero, L_800099CC
    if (ctx->r2 != 0) {
        // 0x800099C4: swc1        $f4, 0xC($a1)
        MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
            goto L_800099CC;
    }
    // 0x800099C4: swc1        $f4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
    // 0x800099C8: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_800099CC:
    // 0x800099CC: lb          $t1, 0xB8($v1)
    ctx->r9 = MEM_B(ctx->r3, 0XB8);
    // 0x800099D0: nop

    // 0x800099D4: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800099D8: beq         $at, $zero, L_800099E4
    if (ctx->r1 == 0) {
        // 0x800099DC: nop
    
            goto L_800099E4;
    }
    // 0x800099DC: nop

    // 0x800099E0: sb          $v0, 0xB8($v1)
    MEM_B(0XB8, ctx->r3) = ctx->r2;
L_800099E4:
    // 0x800099E4: jr          $ra
    // 0x800099E8: nop

    return;
    // 0x800099E8: nop

;}
RECOMP_FUNC void gzip_inflate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6778: addiu       $t6, $a0, 0x5
    ctx->r14 = ADD32(ctx->r4, 0X5);
    // 0x800C677C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C6780: sw          $t6, 0x3CF8($at)
    MEM_W(0X3CF8, ctx->r1) = ctx->r14;
    // 0x800C6784: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C6788: sw          $a1, 0x3CFC($at)
    MEM_W(0X3CFC, ctx->r1) = ctx->r5;
    // 0x800C678C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C6790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6794: sw          $zero, -0x4F6C($at)
    MEM_W(-0X4F6C, ctx->r1) = 0;
    // 0x800C6798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C679C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C67A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C67A4: jal         0x800C6E20
    // 0x800C67A8: sw          $zero, -0x4F70($at)
    MEM_W(-0X4F70, ctx->r1) = 0;
    gzip_inflate_block(rdram, ctx);
        goto after_0;
    // 0x800C67A8: sw          $zero, -0x4F70($at)
    MEM_W(-0X4F70, ctx->r1) = 0;
    after_0:
    // 0x800C67AC: beq         $v0, $zero, L_800C67C8
    if (ctx->r2 == 0) {
        // 0x800C67B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C67C8;
    }
    // 0x800C67B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C67B4:
    // 0x800C67B4: jal         0x800C6E20
    // 0x800C67B8: nop

    gzip_inflate_block(rdram, ctx);
        goto after_1;
    // 0x800C67B8: nop

    after_1:
    // 0x800C67BC: bne         $v0, $zero, L_800C67B4
    if (ctx->r2 != 0) {
        // 0x800C67C0: nop
    
            goto L_800C67B4;
    }
    // 0x800C67C0: nop

    // 0x800C67C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C67C8:
    // 0x800C67C8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800C67CC: jr          $ra
    // 0x800C67D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C67D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void audioStopThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002A7C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002A80: jal         0x800C9050
    // 0x80002A84: addiu       $a0, $a0, 0x6530
    ctx->r4 = ADD32(ctx->r4, 0X6530);
    osStopThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80002A84: addiu       $a0, $a0, 0x6530
    ctx->r4 = ADD32(ctx->r4, 0X6530);
    after_0:
    // 0x80002A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002A90: jr          $ra
    // 0x80002A94: nop

    return;
    // 0x80002A94: nop

;}
RECOMP_FUNC void get_player_selected_vehicle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C794: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C798: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009C79C: lb          $v0, 0x6F80($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6F80);
    // 0x8009C7A0: jr          $ra
    // 0x8009C7A4: nop

    return;
    // 0x8009C7A4: nop

;}
RECOMP_FUNC void adventuretrack_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800933DC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800933E0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800933E4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800933E8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800933EC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800933F0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800933F4: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x800933F8: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x800933FC: jal         0x8006ECD0
    // 0x80093400: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80093400: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    after_0:
    // 0x80093404: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80093408: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8009340C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80093410: bne         $t6, $zero, L_8009341C
    if (ctx->r14 != 0) {
        // 0x80093414: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8009341C;
    }
    // 0x80093414: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80093418: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_8009341C:
    // 0x8009341C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80093420: lw          $t8, -0x5BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5BC);
    // 0x80093424: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80093428: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8009342C: addiu       $s2, $s2, 0x693C
    ctx->r18 = ADD32(ctx->r18, 0X693C);
    // 0x80093430: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80093434: lb          $t0, 0x2($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X2);
    // 0x80093438: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8009343C: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80093440: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80093444: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x80093448: lui         $t2, 0xB600
    ctx->r10 = S32(0XB600 << 16);
    // 0x8009344C: addiu       $t3, $zero, 0x1000
    ctx->r11 = ADD32(0, 0X1000);
    // 0x80093450: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80093454: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80093458: sw          $a1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r5;
    // 0x8009345C: jal         0x8009C2A0
    // 0x80093460: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    menu_camera_centre(rdram, ctx);
        goto after_1;
    // 0x80093460: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    after_1:
    // 0x80093464: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80093468: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8009346C: jal         0x8006816C
    // 0x80093470: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mtx_ortho(rdram, ctx);
        goto after_2;
    // 0x80093470: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80093474: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80093478: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8009347C: nop

    // 0x80093480: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x80093484: bne         $at, $zero, L_80093AEC
    if (ctx->r1 != 0) {
        // 0x80093488: slti        $at, $v0, 0x15
        ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
            goto L_80093AEC;
    }
    // 0x80093488: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8009348C: beq         $at, $zero, L_80093AF0
    if (ctx->r1 == 0) {
        // 0x80093490: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80093AF0;
    }
    // 0x80093490: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80093494: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80093498: jal         0x8006B338
    // 0x8009349C: nop

    leveltable_vehicle_usable(rdram, ctx);
        goto after_3;
    // 0x8009349C: nop

    after_3:
    // 0x800934A0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800934A4: jal         0x8006C01C
    // 0x800934A8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    level_name(rdram, ctx);
        goto after_4;
    // 0x800934A8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_4:
    // 0x800934AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800934B0: jal         0x800C484C
    // 0x800934B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_5;
    // 0x800934B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x800934B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800934BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800934C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800934C4: jal         0x800C492C
    // 0x800934C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_6;
    // 0x800934C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x800934CC: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x800934D0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800934D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800934D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800934DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800934E0: jal         0x800C48E4
    // 0x800934E4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x800934E4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_7:
    // 0x800934E8: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x800934EC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800934F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800934F4: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x800934F8: addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    // 0x800934FC: jal         0x800C49A0
    // 0x80093500: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    draw_text(rdram, ctx);
        goto after_8;
    // 0x80093500: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_8:
    // 0x80093504: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80093508: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009350C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80093510: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80093514: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80093518: jal         0x800C48E4
    // 0x8009351C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_9;
    // 0x8009351C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80093520: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80093524: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80093528: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8009352C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80093530: addiu       $a2, $zero, 0x2B
    ctx->r6 = ADD32(0, 0X2B);
    // 0x80093534: jal         0x800C49A0
    // 0x80093538: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    draw_text(rdram, ctx);
        goto after_10;
    // 0x80093538: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_10:
    // 0x8009353C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80093540: jal         0x8006B38C
    // 0x80093544: nop

    leveltable_type(rdram, ctx);
        goto after_11;
    // 0x80093544: nop

    after_11:
    // 0x80093548: andi        $t8, $v0, 0x40
    ctx->r24 = ctx->r2 & 0X40;
    // 0x8009354C: bne         $t8, $zero, L_80093AF0
    if (ctx->r24 != 0) {
        // 0x80093550: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80093AF0;
    }
    // 0x80093550: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80093554: bne         $s1, $zero, L_80093A18
    if (ctx->r17 != 0) {
        // 0x80093558: nop
    
            goto L_80093A18;
    }
    // 0x80093558: nop

    // 0x8009355C: jal         0x8000E4C8
    // 0x80093560: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_12;
    // 0x80093560: nop

    after_12:
    // 0x80093564: beq         $v0, $zero, L_8009377C
    if (ctx->r2 == 0) {
        // 0x80093568: nop
    
            goto L_8009377C;
    }
    // 0x80093568: nop

    // 0x8009356C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80093570: jal         0x80093128
    // 0x80093574: nop

    trackmenu_staff_beaten(rdram, ctx);
        goto after_13;
    // 0x80093574: nop

    after_13:
    // 0x80093578: bltz        $v0, L_800935BC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8009357C: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_800935BC;
    }
    // 0x8009357C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80093580: lw          $t2, -0x31C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X31C);
    // 0x80093584: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x80093588: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009358C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80093590: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80093594: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80093598: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8009359C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800935A0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800935A4: addiu       $a1, $a1, 0xB94
    ctx->r5 = ADD32(ctx->r5, 0XB94);
    // 0x800935A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800935AC: addiu       $a2, $zero, 0xCC
    ctx->r6 = ADD32(0, 0XCC);
    // 0x800935B0: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800935B4: jal         0x80078F08
    // 0x800935B8: addiu       $a3, $a3, 0x7A
    ctx->r7 = ADD32(ctx->r7, 0X7A);
    texrect_draw(rdram, ctx);
        goto after_14;
    // 0x800935B8: addiu       $a3, $a3, 0x7A
    ctx->r7 = ADD32(ctx->r7, 0X7A);
    after_14:
L_800935BC:
    // 0x800935BC: jal         0x800C484C
    // 0x800935C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_15;
    // 0x800935C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x800935C4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800935C8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800935CC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800935D0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800935D4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800935D8: jal         0x800C48E4
    // 0x800935DC: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    set_text_colour(rdram, ctx);
        goto after_16;
    // 0x800935DC: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    after_16:
    // 0x800935E0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800935E4: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x800935E8: lw          $s1, 0x60($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X60);
    // 0x800935EC: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x800935F0: lw          $a3, 0x24($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X24);
    // 0x800935F4: addiu       $s1, $s1, 0x48
    ctx->r17 = ADD32(ctx->r17, 0X48);
    // 0x800935F8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800935FC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80093600: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80093604: jal         0x800C49A0
    // 0x80093608: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    draw_text(rdram, ctx);
        goto after_17;
    // 0x80093608: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_17:
    // 0x8009360C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80093610: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x80093614: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x80093618: lw          $a3, 0x28($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X28);
    // 0x8009361C: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80093620: addiu       $a2, $a2, 0x5C
    ctx->r6 = ADD32(ctx->r6, 0X5C);
    // 0x80093624: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80093628: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009362C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80093630: jal         0x800C49A0
    // 0x80093634: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    draw_text(rdram, ctx);
        goto after_18;
    // 0x80093634: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_18:
    // 0x80093638: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009363C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80093640: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80093644: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80093648: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009364C: jal         0x800C48E4
    // 0x80093650: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    set_text_colour(rdram, ctx);
        goto after_19;
    // 0x80093650: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    after_19:
    // 0x80093654: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80093658: lb          $t1, 0x6F80($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X6F80);
    // 0x8009365C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80093660: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80093664: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80093668: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8009366C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80093670: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x80093674: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x80093678: lhu         $a0, 0x0($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X0);
    // 0x8009367C: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80093680: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80093684: jal         0x80097C34
    // 0x80093688: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_20;
    // 0x80093688: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_20:
    // 0x8009368C: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80093690: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80093694: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80093698: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x8009369C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800936A0: jal         0x800C49A0
    // 0x800936A4: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    draw_text(rdram, ctx);
        goto after_21;
    // 0x800936A4: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_21:
    // 0x800936A8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800936AC: lb          $t8, 0x6F80($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X6F80);
    // 0x800936B0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800936B4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800936B8: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x800936BC: lw          $t0, 0x18($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X18);
    // 0x800936C0: addiu       $s1, $sp, 0x54
    ctx->r17 = ADD32(ctx->r29, 0X54);
    // 0x800936C4: addu        $t2, $t0, $s0
    ctx->r10 = ADD32(ctx->r8, ctx->r16);
    // 0x800936C8: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    // 0x800936CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800936D0: jal         0x80097C34
    // 0x800936D4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_22;
    // 0x800936D4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_22:
    // 0x800936D8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800936DC: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x800936E0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800936E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800936E8: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x800936EC: jal         0x800C49A0
    // 0x800936F0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    draw_text(rdram, ctx);
        goto after_23;
    // 0x800936F0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_23:
    // 0x800936F4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800936F8: lb          $t5, 0x6F80($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X6F80);
    // 0x800936FC: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80093700: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80093704: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x80093708: lw          $t7, 0x3C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X3C);
    // 0x8009370C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80093710: addu        $t9, $t7, $s0
    ctx->r25 = ADD32(ctx->r15, ctx->r16);
    // 0x80093714: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    // 0x80093718: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8009371C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80093720: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80093724: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80093728: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x8009372C: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    // 0x80093730: jal         0x80081C50
    // 0x80093734: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    menu_timestamp_render(rdram, ctx);
        goto after_24;
    // 0x80093734: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_24:
    // 0x80093738: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009373C: lb          $t3, 0x6F80($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X6F80);
    // 0x80093740: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80093744: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80093748: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x8009374C: lw          $t6, 0x24($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X24);
    // 0x80093750: addiu       $t7, $zero, 0xC0
    ctx->r15 = ADD32(0, 0XC0);
    // 0x80093754: addu        $t8, $t6, $s0
    ctx->r24 = ADD32(ctx->r14, ctx->r16);
    // 0x80093758: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    // 0x8009375C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80093760: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80093764: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80093768: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009376C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80093770: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x80093774: jal         0x80081C50
    // 0x80093778: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    menu_timestamp_render(rdram, ctx);
        goto after_25;
    // 0x80093778: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_25:
L_8009377C:
    // 0x8009377C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80093780: lw          $a2, 0x695C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X695C);
    // 0x80093784: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80093788: sll         $t1, $a2, 3
    ctx->r9 = S32(ctx->r6 << 3);
    // 0x8009378C: slti        $at, $t1, 0x100
    ctx->r1 = SIGNED(ctx->r9) < 0X100 ? 1 : 0;
    // 0x80093790: bne         $at, $zero, L_800937A0
    if (ctx->r1 != 0) {
        // 0x80093794: or          $a2, $t1, $zero
        ctx->r6 = ctx->r9 | 0;
            goto L_800937A0;
    }
    // 0x80093794: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80093798: addiu       $t0, $zero, 0x1FF
    ctx->r8 = ADD32(0, 0X1FF);
    // 0x8009379C: subu        $a2, $t0, $t1
    ctx->r6 = SUB32(ctx->r8, ctx->r9);
L_800937A0:
    // 0x800937A0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800937A4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800937A8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800937AC: jal         0x800C551C
    // 0x800937B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_26;
    // 0x800937B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_26:
    // 0x800937B4: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x800937B8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800937BC: addiu       $t2, $v0, 0x89
    ctx->r10 = ADD32(ctx->r2, 0X89);
    // 0x800937C0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800937C4: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    // 0x800937C8: addiu       $a3, $zero, 0xBA
    ctx->r7 = ADD32(0, 0XBA);
    // 0x800937CC: jal         0x800C543C
    // 0x800937D0: addiu       $a2, $v0, 0x70
    ctx->r6 = ADD32(ctx->r2, 0X70);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_27;
    // 0x800937D0: addiu       $a2, $v0, 0x70
    ctx->r6 = ADD32(ctx->r2, 0X70);
    after_27:
    // 0x800937D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800937D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800937DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800937E0: jal         0x800C60B8
    // 0x800937E4: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_28;
    // 0x800937E4: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_28:
    // 0x800937E8: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x800937EC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800937F0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800937F4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800937F8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800937FC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80093800: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80093804: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80093808: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8009380C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80093810: addiu       $a1, $a1, 0xB34
    ctx->r5 = ADD32(ctx->r5, 0XB34);
    // 0x80093814: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80093818: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x8009381C: jal         0x80078F08
    // 0x80093820: addiu       $a3, $a3, 0x72
    ctx->r7 = ADD32(ctx->r7, 0X72);
    texrect_draw(rdram, ctx);
        goto after_29;
    // 0x80093820: addiu       $a3, $a3, 0x72
    ctx->r7 = ADD32(ctx->r7, 0X72);
    after_29:
    // 0x80093824: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80093828: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009382C: addiu       $s1, $t7, 0x8B
    ctx->r17 = ADD32(ctx->r15, 0X8B);
    // 0x80093830: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80093834: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
L_80093838:
    // 0x80093838: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8009383C: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x80093840: beq         $at, $zero, L_80093864
    if (ctx->r1 == 0) {
        // 0x80093844: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80093864;
    }
    // 0x80093844: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80093848: jal         0x8006B2EC
    // 0x8009384C: nop

    leveltable_vehicle_default(rdram, ctx);
        goto after_30;
    // 0x8009384C: nop

    after_30:
    // 0x80093850: beq         $v0, $s0, L_80093864
    if (ctx->r2 == ctx->r16) {
        // 0x80093854: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80093864;
    }
    // 0x80093854: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80093858: b           L_80093864
    // 0x8009385C: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
        goto L_80093864;
    // 0x8009385C: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x80093860: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80093864:
    // 0x80093864: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80093868: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8009386C: sllv        $t3, $t0, $s0
    ctx->r11 = S32(ctx->r8 << (ctx->r16 & 31));
    // 0x80093870: and         $t5, $t3, $t2
    ctx->r13 = ctx->r11 & ctx->r10;
    // 0x80093874: beq         $t5, $zero, L_8009390C
    if (ctx->r13 == 0) {
        // 0x80093878: sll         $t4, $s0, 2
        ctx->r12 = S32(ctx->r16 << 2);
            goto L_8009390C;
    }
    // 0x80093878: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x8009387C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80093880: lb          $t7, 0x6F80($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X6F80);
    // 0x80093884: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x80093888: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009388C: addiu       $t8, $t8, 0xBA4
    ctx->r24 = ADD32(ctx->r24, 0XBA4);
    // 0x80093890: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80093894: bne         $s0, $t7, L_800938D8
    if (ctx->r16 != ctx->r15) {
        // 0x80093898: addu        $v1, $t6, $t8
        ctx->r3 = ADD32(ctx->r14, ctx->r24);
            goto L_800938D8;
    }
    // 0x80093898: addu        $v1, $t6, $t8
    ctx->r3 = ADD32(ctx->r14, ctx->r24);
    // 0x8009389C: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x800938A0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800938A4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800938A8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800938AC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800938B0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800938B4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800938B8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800938BC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800938C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800938C4: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    // 0x800938C8: jal         0x80078F08
    // 0x800938CC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    texrect_draw(rdram, ctx);
        goto after_31;
    // 0x800938CC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_31:
    // 0x800938D0: b           L_8009390C
    // 0x800938D4: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
        goto L_8009390C;
    // 0x800938D4: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
L_800938D8:
    // 0x800938D8: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x800938DC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800938E0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800938E4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800938E8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800938EC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800938F0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800938F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800938F8: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    // 0x800938FC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80093900: jal         0x80078F08
    // 0x80093904: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    texrect_draw(rdram, ctx);
        goto after_32;
    // 0x80093904: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_32:
    // 0x80093908: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
L_8009390C:
    // 0x8009390C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80093910: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80093914: bne         $s0, $at, L_80093838
    if (ctx->r16 != ctx->r1) {
        // 0x80093918: lw          $t1, 0x7C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X7C);
            goto L_80093838;
    }
    // 0x80093918: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8009391C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80093920: lb          $v0, 0x6F80($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6F80);
    // 0x80093924: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80093928: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009392C: bne         $v0, $at, L_80093938
    if (ctx->r2 != ctx->r1) {
        // 0x80093930: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80093938;
    }
    // 0x80093930: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80093934: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_80093938:
    // 0x80093938: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8009393C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80093940: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80093944: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80093948: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8009394C: lw          $a1, 0xBA4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XBA4);
    // 0x80093950: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80093954: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80093958: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009395C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80093960: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80093964: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80093968: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009396C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80093970: addiu       $a2, $zero, 0x95
    ctx->r6 = ADD32(0, 0X95);
    // 0x80093974: jal         0x80078F08
    // 0x80093978: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    texrect_draw(rdram, ctx);
        goto after_33;
    // 0x80093978: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_33:
    // 0x8009397C: jal         0x8007B820
    // 0x80093980: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    rendermode_reset(rdram, ctx);
        goto after_34;
    // 0x80093980: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_34:
    // 0x80093984: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80093988: addiu       $v0, $v0, -0x324
    ctx->r2 = ADD32(ctx->r2, -0X324);
    // 0x8009398C: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x80093990: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80093994: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80093998: lui         $at, 0xC250
    ctx->r1 = S32(0XC250 << 16);
    // 0x8009399C: swc1        $f4, 0xEC($t3)
    MEM_W(0XEC, ctx->r11) = ctx->f4.u32l;
    // 0x800939A0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800939A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800939A8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800939AC: jal         0x8009CFA4
    // 0x800939B0: swc1        $f6, 0xF0($t2)
    MEM_W(0XF0, ctx->r10) = ctx->f6.u32l;
    menu_element_render(rdram, ctx);
        goto after_35;
    // 0x800939B0: swc1        $f6, 0xF0($t2)
    MEM_W(0XF0, ctx->r10) = ctx->f6.u32l;
    after_35:
    // 0x800939B4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800939B8: lw          $t5, 0x6980($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6980);
    // 0x800939BC: nop

    // 0x800939C0: beq         $t5, $zero, L_80093AF0
    if (ctx->r13 == 0) {
        // 0x800939C4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80093AF0;
    }
    // 0x800939C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800939C8: jal         0x800C484C
    // 0x800939CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_36;
    // 0x800939CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_36:
    // 0x800939D0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800939D4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800939D8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800939DC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800939E0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800939E4: jal         0x800C48E4
    // 0x800939E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_37;
    // 0x800939E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_37:
    // 0x800939EC: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800939F0: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800939F4: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x800939F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800939FC: addiu       $a3, $a3, -0x7830
    ctx->r7 = ADD32(ctx->r7, -0X7830);
    // 0x80093A00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80093A04: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80093A08: jal         0x800C49A0
    // 0x80093A0C: addiu       $a2, $a2, 0xAC
    ctx->r6 = ADD32(ctx->r6, 0XAC);
    draw_text(rdram, ctx);
        goto after_38;
    // 0x80093A0C: addiu       $a2, $a2, 0xAC
    ctx->r6 = ADD32(ctx->r6, 0XAC);
    after_38:
    // 0x80093A10: b           L_80093AF0
    // 0x80093A14: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80093AF0;
    // 0x80093A14: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80093A18:
    // 0x80093A18: jal         0x800C484C
    // 0x80093A1C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_39;
    // 0x80093A1C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_39:
    // 0x80093A20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80093A24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80093A28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80093A2C: jal         0x800C492C
    // 0x80093A30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_40;
    // 0x80093A30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_40:
    // 0x80093A34: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80093A38: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80093A3C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80093A40: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80093A44: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80093A48: jal         0x800C48E4
    // 0x80093A4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_41;
    // 0x80093A4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_41:
    // 0x80093A50: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x80093A54: nop

    // 0x80093A58: addiu       $s0, $s0, 0xB0
    ctx->r16 = ADD32(ctx->r16, 0XB0);
    // 0x80093A5C: jal         0x8009F064
    // 0x80093A60: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    get_language(rdram, ctx);
        goto after_42;
    // 0x80093A60: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    after_42:
    // 0x80093A64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80093A68: bne         $v0, $at, L_80093A94
    if (ctx->r2 != ctx->r1) {
        // 0x80093A6C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80093A94;
    }
    // 0x80093A6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80093A70: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80093A74: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x80093A78: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80093A7C: lw          $a3, 0x2FC($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X2FC);
    // 0x80093A80: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80093A84: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80093A88: jal         0x800C49A0
    // 0x80093A8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    draw_text(rdram, ctx);
        goto after_43;
    // 0x80093A8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_43:
    // 0x80093A90: addiu       $s1, $s0, 0x20
    ctx->r17 = ADD32(ctx->r16, 0X20);
L_80093A94:
    // 0x80093A94: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80093A98: lw          $t1, -0x5E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5E0);
    // 0x80093A9C: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x80093AA0: lw          $a3, 0x2C($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X2C);
    // 0x80093AA4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80093AA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80093AAC: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80093AB0: jal         0x800C49A0
    // 0x80093AB4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    draw_text(rdram, ctx);
        goto after_44;
    // 0x80093AB4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_44:
    // 0x80093AB8: jal         0x8009F064
    // 0x80093ABC: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    get_language(rdram, ctx);
        goto after_45;
    // 0x80093ABC: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    after_45:
    // 0x80093AC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80093AC4: beq         $v0, $at, L_80093AEC
    if (ctx->r2 == ctx->r1) {
        // 0x80093AC8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80093AEC;
    }
    // 0x80093AC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80093ACC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80093AD0: lw          $t3, -0x5E0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5E0);
    // 0x80093AD4: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80093AD8: lw          $a3, 0x2FC($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X2FC);
    // 0x80093ADC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80093AE0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80093AE4: jal         0x800C49A0
    // 0x80093AE8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    draw_text(rdram, ctx);
        goto after_46;
    // 0x80093AE8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_46:
L_80093AEC:
    // 0x80093AEC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80093AF0:
    // 0x80093AF0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80093AF4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80093AF8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80093AFC: jr          $ra
    // 0x80093B00: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80093B00: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void light_add_from_object_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031FC8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80031FCC: addiu       $v1, $v1, -0x3134
    ctx->r3 = ADD32(ctx->r3, -0X3134);
    // 0x80031FD0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80031FD4: lw          $t6, -0x3138($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3138);
    // 0x80031FD8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80031FDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031FE0: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80031FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031FE8: beq         $at, $zero, L_80032240
    if (ctx->r1 == 0) {
        // 0x80031FEC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80032240;
    }
    // 0x80031FEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80031FF0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80031FF4: lw          $t7, -0x3140($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3140);
    // 0x80031FF8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80031FFC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80032000: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x80032004: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80032008: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8003200C: lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8);
    // 0x80032010: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80032014: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x80032018: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x8003201C: lbu         $t3, 0x9($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X9);
    // 0x80032020: nop

    // 0x80032024: sb          $t3, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r11;
    // 0x80032028: lbu         $t4, 0xB($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XB);
    // 0x8003202C: nop

    // 0x80032030: sb          $t4, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r12;
    // 0x80032034: lbu         $t5, 0xA($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XA);
    // 0x80032038: nop

    // 0x8003203C: sb          $t5, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r13;
    // 0x80032040: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x80032044: sw          $a0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r4;
    // 0x80032048: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8003204C: sb          $t7, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r15;
    // 0x80032050: lh          $t8, 0xC($a1)
    ctx->r24 = MEM_H(ctx->r5, 0XC);
    // 0x80032054: nop

    // 0x80032058: sh          $t8, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r24;
    // 0x8003205C: lh          $t9, 0xE($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XE);
    // 0x80032060: lh          $t1, 0x6($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X6);
    // 0x80032064: sh          $t9, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r25;
    // 0x80032068: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    // 0x8003206C: lh          $t2, 0x8($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X8);
    // 0x80032070: sh          $t0, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r8;
    // 0x80032074: lh          $t3, 0xA($a2)
    ctx->r11 = MEM_H(ctx->r6, 0XA);
    // 0x80032078: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8003207C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80032080: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80032084: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80032088: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003208C: swc1        $f6, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f6.u32l;
    // 0x80032090: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80032094: swc1        $f10, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f10.u32l;
    // 0x80032098: swc1        $f18, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f18.u32l;
    // 0x8003209C: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x800320A0: sw          $zero, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = 0;
    // 0x800320A4: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x800320A8: sw          $t5, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r13;
    // 0x800320AC: sh          $zero, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = 0;
    // 0x800320B0: lbu         $t6, 0x3($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3);
    // 0x800320B4: sw          $zero, 0x30($a2)
    MEM_W(0X30, ctx->r6) = 0;
    // 0x800320B8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800320BC: sw          $t7, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r15;
    // 0x800320C0: sh          $zero, 0x3E($a2)
    MEM_H(0X3E, ctx->r6) = 0;
    // 0x800320C4: lbu         $t8, 0x4($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X4);
    // 0x800320C8: sw          $zero, 0x34($a2)
    MEM_W(0X34, ctx->r6) = 0;
    // 0x800320CC: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800320D0: sw          $t9, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r25;
    // 0x800320D4: sh          $zero, 0x40($a2)
    MEM_H(0X40, ctx->r6) = 0;
    // 0x800320D8: lbu         $t0, 0x5($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X5);
    // 0x800320DC: sw          $zero, 0x38($a2)
    MEM_W(0X38, ctx->r6) = 0;
    // 0x800320E0: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x800320E4: sw          $t1, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r9;
    // 0x800320E8: sh          $zero, 0x42($a2)
    MEM_H(0X42, ctx->r6) = 0;
    // 0x800320EC: lhu         $a0, 0x6($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X6);
    // 0x800320F0: nop

    // 0x800320F4: beq         $a0, $at, L_80032168
    if (ctx->r4 == ctx->r1) {
        // 0x800320F8: nop
    
            goto L_80032168;
    }
    // 0x800320F8: nop

    // 0x800320FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80032100: jal         0x8001E2D0
    // 0x80032104: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80032104: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80032108: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8003210C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80032110: sw          $v0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r2;
    // 0x80032114: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80032118: addiu       $t3, $v0, 0x14
    ctx->r11 = ADD32(ctx->r2, 0X14);
    // 0x8003211C: andi        $a0, $t2, 0xFFFF
    ctx->r4 = ctx->r10 & 0XFFFF;
    // 0x80032120: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80032124: sh          $zero, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = 0;
    // 0x80032128: sh          $zero, 0x4C($a2)
    MEM_H(0X4C, ctx->r6) = 0;
    // 0x8003212C: sh          $zero, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = 0;
    // 0x80032130: sw          $t3, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r11;
    // 0x80032134: blez        $a0, L_8003216C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80032138: sh          $t2, 0x48($a2)
        MEM_H(0X48, ctx->r6) = ctx->r10;
            goto L_8003216C;
    }
    // 0x80032138: sh          $t2, 0x48($a2)
    MEM_H(0X48, ctx->r6) = ctx->r10;
    // 0x8003213C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80032140:
    // 0x80032140: lhu         $t4, 0x4E($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X4E);
    // 0x80032144: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x80032148: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003214C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80032150: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80032154: sh          $t6, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r14;
    // 0x80032158: bne         $at, $zero, L_80032140
    if (ctx->r1 != 0) {
        // 0x8003215C: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80032140;
    }
    // 0x8003215C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80032160: b           L_80032170
    // 0x80032164: lhu         $t7, 0x12($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X12);
        goto L_80032170;
    // 0x80032164: lhu         $t7, 0x12($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X12);
L_80032168:
    // 0x80032168: sw          $zero, 0x44($a2)
    MEM_W(0X44, ctx->r6) = 0;
L_8003216C:
    // 0x8003216C: lhu         $t7, 0x12($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X12);
L_80032170:
    // 0x80032170: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80032174: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80032178: bgez        $t7, L_8003218C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8003217C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8003218C;
    }
    // 0x8003217C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80032180: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80032184: nop

    // 0x80032188: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8003218C:
    // 0x8003218C: swc1        $f6, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f6.u32l;
    // 0x80032190: lhu         $t8, 0x14($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X14);
    // 0x80032194: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80032198: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8003219C: bgez        $t8, L_800321B0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800321A0: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800321B0;
    }
    // 0x800321A0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800321A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800321A8: nop

    // 0x800321AC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800321B0:
    // 0x800321B0: swc1        $f16, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->f16.u32l;
    // 0x800321B4: lhu         $t9, 0x16($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X16);
    // 0x800321B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800321BC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800321C0: bgez        $t9, L_800321D4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800321C4: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800321D4;
    }
    // 0x800321C4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800321C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800321CC: nop

    // 0x800321D0: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800321D4:
    // 0x800321D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800321D8: lwc1        $f0, 0x5C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X5C);
    // 0x800321DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800321E0: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800321E4: nop

    // 0x800321E8: div.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800321EC: swc1        $f8, 0x64($a2)
    MEM_W(0X64, ctx->r6) = ctx->f8.u32l;
    // 0x800321F0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800321F4: swc1        $f10, 0x68($a2)
    MEM_W(0X68, ctx->r6) = ctx->f10.u32l;
    // 0x800321F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800321FC: swc1        $f16, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f16.u32l;
    // 0x80032200: lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X0);
    // 0x80032204: sh          $zero, 0x74($a2)
    MEM_H(0X74, ctx->r6) = 0;
    // 0x80032208: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8003220C: sh          $t1, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r9;
    // 0x80032210: sh          $zero, 0x78($a2)
    MEM_H(0X78, ctx->r6) = 0;
    // 0x80032214: lbu         $t2, 0x1($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X1);
    // 0x80032218: sh          $zero, 0x76($a2)
    MEM_H(0X76, ctx->r6) = 0;
    // 0x8003221C: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80032220: sh          $t3, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r11;
    // 0x80032224: sh          $zero, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = 0;
    // 0x80032228: sb          $t4, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r12;
    // 0x8003222C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80032230: jal         0x80032464
    // 0x80032234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    light_update(rdram, ctx);
        goto after_1;
    // 0x80032234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80032238: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8003223C: nop

L_80032240:
    // 0x80032240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032244: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80032248: jr          $ra
    // 0x8003224C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x8003224C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
;}
RECOMP_FUNC void shadow_generate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E274: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8002E278: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002E27C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002E280: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002E284: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8002E288: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8002E28C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8002E290: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8002E294: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8002E298: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8002E29C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8002E2A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E2A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E2A8: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002E2AC: lh          $t7, 0x48($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X48);
    // 0x8002E2B0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E2B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002E2B8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8002E2BC: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x8002E2C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002E2C4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002E2C8: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8002E2CC: bne         $s2, $t7, L_8002E30C
    if (ctx->r18 != ctx->r15) {
        // 0x8002E2D0: or          $s6, $a1, $zero
        ctx->r22 = ctx->r5 | 0;
            goto L_8002E30C;
    }
    // 0x8002E2D0: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8002E2D4: jal         0x8009C850
    // 0x8002E2D8: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x8002E2D8: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8002E2DC: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8002E2E0: andi        $t8, $v0, 0x10
    ctx->r24 = ctx->r2 & 0X10;
    // 0x8002E2E4: beq         $t8, $zero, L_8002E2FC
    if (ctx->r24 == 0) {
        // 0x8002E2E8: andi        $t9, $v0, 0x20
        ctx->r25 = ctx->r2 & 0X20;
            goto L_8002E2FC;
    }
    // 0x8002E2E8: andi        $t9, $v0, 0x20
    ctx->r25 = ctx->r2 & 0X20;
    // 0x8002E2EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002E2F0: lwc1        $f18, 0x64D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X64D8);
    // 0x8002E2F4: b           L_8002E310
    // 0x8002E2F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
        goto L_8002E310;
    // 0x8002E2F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_8002E2FC:
    // 0x8002E2FC: beq         $t9, $zero, L_8002E30C
    if (ctx->r25 == 0) {
        // 0x8002E300: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8002E30C;
    }
    // 0x8002E300: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002E304: lwc1        $f18, 0x64DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X64DC);
    // 0x8002E308: nop

L_8002E30C:
    // 0x8002E30C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_8002E310:
    // 0x8002E310: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002E314: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002E318: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002E31C: addiu       $s3, $s3, -0x29BC
    ctx->r19 = ADD32(ctx->r19, -0X29BC);
    // 0x8002E320: addiu       $s1, $s1, -0x29B8
    ctx->r17 = ADD32(ctx->r17, -0X29B8);
    // 0x8002E324: sw          $s5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r21;
    // 0x8002E328: beq         $s6, $zero, L_8002E434
    if (ctx->r22 == 0) {
        // 0x8002E32C: swc1        $f8, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
            goto L_8002E434;
    }
    // 0x8002E32C: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x8002E330: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E334: sw          $zero, -0x29C8($at)
    MEM_W(-0X29C8, ctx->r1) = 0;
    // 0x8002E338: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002E33C: lw          $t0, -0x271C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X271C);
    // 0x8002E340: lw          $t1, 0x58($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X58);
    // 0x8002E344: nop

    // 0x8002E348: sh          $t0, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r8;
    // 0x8002E34C: lw          $v0, 0x58($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X58);
    // 0x8002E350: nop

    // 0x8002E354: lh          $a1, 0xC($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XC);
    // 0x8002E358: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8002E35C: sll         $t2, $a1, 8
    ctx->r10 = S32(ctx->r5 << 8);
    // 0x8002E360: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8002E364: jal         0x8007B8BC
    // 0x8002E368: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    set_animated_texture_header(rdram, ctx);
        goto after_1;
    // 0x8002E368: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8002E36C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E370: sw          $v0, -0x29C0($at)
    MEM_W(-0X29C0, ctx->r1) = ctx->r2;
    // 0x8002E374: lw          $t3, 0x40($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X40);
    // 0x8002E378: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002E37C: lh          $t4, 0x48($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X48);
    // 0x8002E380: addiu       $s4, $s4, -0x29B2
    ctx->r20 = ADD32(ctx->r20, -0X29B2);
    // 0x8002E384: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8002E388: sh          $t5, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r13;
    // 0x8002E38C: lw          $t6, 0x40($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X40);
    // 0x8002E390: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002E394: lh          $t7, 0x46($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X46);
    // 0x8002E398: lw          $t9, -0x26FC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26FC);
    // 0x8002E39C: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8002E3A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E3A4: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8002E3A8: beq         $t9, $zero, L_8002E3C4
    if (ctx->r25 == 0) {
        // 0x8002E3AC: sh          $t8, -0x29B4($at)
        MEM_H(-0X29B4, ctx->r1) = ctx->r24;
            goto L_8002E3C4;
    }
    // 0x8002E3AC: sh          $t8, -0x29B4($at)
    MEM_H(-0X29B4, ctx->r1) = ctx->r24;
    // 0x8002E3B0: jal         0x80066450
    // 0x8002E3B4: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    cam_get_viewport_layout(rdram, ctx);
        goto after_2;
    // 0x8002E3B4: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8002E3B8: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8002E3BC: bgtz        $v0, L_8002E3D0
    if (SIGNED(ctx->r2) > 0) {
        // 0x8002E3C0: nop
    
            goto L_8002E3D0;
    }
    // 0x8002E3C0: nop

L_8002E3C4:
    // 0x8002E3C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002E3C8: nop

    // 0x8002E3CC: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_8002E3D0:
    // 0x8002E3D0: lw          $t0, 0x58($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X58);
    // 0x8002E3D4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002E3D8: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8002E3DC: addiu       $v1, $v1, -0x29A8
    ctx->r3 = ADD32(ctx->r3, -0X29A8);
    // 0x8002E3E0: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8002E3E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002E3E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002E3EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E3F0: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8002E3F4: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002E3F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002E3FC: mul.s       $f0, $f16, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8002E400: addiu       $v0, $v0, -0x2990
    ctx->r2 = ADD32(ctx->r2, -0X2990);
    // 0x8002E404: swc1        $f0, -0x29A4($at)
    MEM_W(-0X29A4, ctx->r1) = ctx->f0.u32l;
    // 0x8002E408: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E40C: swc1        $f0, -0x29A0($at)
    MEM_W(-0X29A0, ctx->r1) = ctx->f0.u32l;
    // 0x8002E410: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8002E414: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002E418: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E41C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8002E420: lwc1        $f12, -0x29A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X29A4);
    // 0x8002E424: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E428: lwc1        $f14, -0x29A0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X29A0);
    // 0x8002E42C: b           L_8002E608
    // 0x8002E430: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
        goto L_8002E608;
    // 0x8002E430: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
L_8002E434:
    // 0x8002E434: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002E438: lw          $t1, -0x271C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X271C);
    // 0x8002E43C: lw          $t2, 0x50($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X50);
    // 0x8002E440: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E444: sh          $t1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r9;
    // 0x8002E448: lw          $t3, 0x50($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X50);
    // 0x8002E44C: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002E450: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8002E454: addiu       $s4, $s4, -0x29B2
    ctx->r20 = ADD32(ctx->r20, -0X29B2);
    // 0x8002E458: sw          $t4, -0x29C0($at)
    MEM_W(-0X29C0, ctx->r1) = ctx->r12;
    // 0x8002E45C: lw          $t5, 0x40($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X40);
    // 0x8002E460: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E464: lh          $t6, 0x44($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X44);
    // 0x8002E468: nop

    // 0x8002E46C: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8002E470: sh          $t7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r15;
    // 0x8002E474: lw          $t8, 0x40($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X40);
    // 0x8002E478: nop

    // 0x8002E47C: lh          $t9, 0x42($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X42);
    // 0x8002E480: nop

    // 0x8002E484: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8002E488: sh          $t0, -0x29B4($at)
    MEM_H(-0X29B4, ctx->r1) = ctx->r8;
    // 0x8002E48C: lh          $t1, 0x48($s5)
    ctx->r9 = MEM_H(ctx->r21, 0X48);
    // 0x8002E490: nop

    // 0x8002E494: beq         $s2, $t1, L_8002E52C
    if (ctx->r18 == ctx->r9) {
        // 0x8002E498: nop
    
            goto L_8002E52C;
    }
    // 0x8002E498: nop

    // 0x8002E49C: lwc1        $f2, 0x30($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X30);
    // 0x8002E4A0: mtc1        $zero, $f13
    ctx->f_odd[(13 - 1) * 2] = 0;
    // 0x8002E4A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8002E4A8: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8002E4AC: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x8002E4B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E4B4: bc1f        L_8002E4C4
    if (!c1cs) {
        // 0x8002E4B8: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8002E4C4;
    }
    // 0x8002E4B8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002E4BC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8002E4C0: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_8002E4C4:
    // 0x8002E4C4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002E4C8: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8002E4CC: sub.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f0.d - ctx->f4.d;
    // 0x8002E4D0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002E4D4: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x8002E4D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002E4DC: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8002E4E0: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x8002E4E4: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8002E4E8: bc1f        L_8002E4FC
    if (!c1cs) {
        // 0x8002E4EC: nop
    
            goto L_8002E4FC;
    }
    // 0x8002E4EC: nop

    // 0x8002E4F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002E4F4: nop

    // 0x8002E4F8: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_8002E4FC:
    // 0x8002E4FC: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8002E500: nop

    // 0x8002E504: bc1f        L_8002E514
    if (!c1cs) {
        // 0x8002E508: nop
    
            goto L_8002E514;
    }
    // 0x8002E508: nop

    // 0x8002E50C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002E510: nop

L_8002E514:
    // 0x8002E514: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002E518: lwc1        $f4, 0x64E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X64E0);
    // 0x8002E51C: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8002E520: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8002E524: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8002E528: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
L_8002E52C:
    // 0x8002E52C: lw          $t2, 0x50($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X50);
    // 0x8002E530: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002E534: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8002E538: addiu       $v1, $v1, -0x29A8
    ctx->r3 = ADD32(ctx->r3, -0X29A8);
    // 0x8002E53C: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8002E540: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002E544: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002E548: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E54C: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x8002E550: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002E554: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002E558: mul.s       $f0, $f16, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8002E55C: addiu       $v0, $v0, -0x2990
    ctx->r2 = ADD32(ctx->r2, -0X2990);
    // 0x8002E560: swc1        $f0, -0x29A4($at)
    MEM_W(-0X29A4, ctx->r1) = ctx->f0.u32l;
    // 0x8002E564: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E568: swc1        $f0, -0x29A0($at)
    MEM_W(-0X29A0, ctx->r1) = ctx->f0.u32l;
    // 0x8002E56C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E570: lwc1        $f12, -0x29A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X29A4);
    // 0x8002E574: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E578: lwc1        $f14, -0x29A0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X29A0);
    // 0x8002E57C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002E580: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002E584: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E588: mul.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8002E58C: nop

    // 0x8002E590: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8002E594: swc1        $f10, -0x299C($at)
    MEM_W(-0X299C, ctx->r1) = ctx->f10.u32l;
    // 0x8002E598: lw          $t3, 0x40($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X40);
    // 0x8002E59C: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8002E5A0: lh          $t4, 0x42($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X42);
    // 0x8002E5A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002E5A8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8002E5AC: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8002E5B0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002E5B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002E5B8: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8002E5BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002E5C0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8002E5C4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002E5C8: nop

    // 0x8002E5CC: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8002E5D0: nop

    // 0x8002E5D4: bc1f        L_8002E5EC
    if (!c1cs) {
        // 0x8002E5D8: nop
    
            goto L_8002E5EC;
    }
    // 0x8002E5D8: nop

    // 0x8002E5DC: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x8002E5E0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8002E5E4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002E5E8: nop

L_8002E5EC:
    // 0x8002E5EC: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8002E5F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E5F4: addiu       $t5, $zero, -0x8000
    ctx->r13 = ADD32(0, -0X8000);
    // 0x8002E5F8: swc1        $f10, -0x298C($at)
    MEM_W(-0X298C, ctx->r1) = ctx->f10.u32l;
    // 0x8002E5FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E600: sh          $t5, -0x29B0($at)
    MEM_H(-0X29B0, ctx->r1) = ctx->r13;
    // 0x8002E604: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
L_8002E608:
    // 0x8002E608: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002E60C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8002E610: div.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8002E614: lh          $t4, 0x0($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X0);
    // 0x8002E618: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8002E61C: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8002E620: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8002E624: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002E628: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002E62C: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8002E630: lh          $a2, -0x29B4($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X29B4);
    // 0x8002E634: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002E638: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8002E63C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002E640: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E644: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E648: nop

    // 0x8002E64C: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E650: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002E654: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8002E658: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8002E65C: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8002E660: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002E664: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002E668: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002E66C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E670: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E674: nop

    // 0x8002E678: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002E67C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002E680: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8002E684: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8002E688: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x8002E68C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002E690: sra         $a3, $t0, 16
    ctx->r7 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8002E694: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8002E698: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E69C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E6A0: nop

    // 0x8002E6A4: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E6A8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002E6AC: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8002E6B0: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8002E6B4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002E6B8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8002E6BC: nop

    // 0x8002E6C0: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8002E6C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E6C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E6CC: nop

    // 0x8002E6D0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002E6D4: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8002E6D8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8002E6DC: jal         0x8002A174
    // 0x8002E6E0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    get_inside_segment_count_xyz(rdram, ctx);
        goto after_3;
    // 0x8002E6E0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_3:
    // 0x8002E6E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E6E8: sw          $zero, -0x3850($at)
    MEM_W(-0X3850, ctx->r1) = 0;
    // 0x8002E6EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E6F0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002E6F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002E6F8: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x8002E6FC: sw          $zero, -0x4968($at)
    MEM_W(-0X4968, ctx->r1) = 0;
    // 0x8002E700: addiu       $a0, $a0, -0x4750
    ctx->r4 = ADD32(ctx->r4, -0X4750);
    // 0x8002E704: addiu       $v1, $v1, -0x4760
    ctx->r3 = ADD32(ctx->r3, -0X4760);
L_8002E708:
    // 0x8002E708: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002E70C: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8002E710: bne         $at, $zero, L_8002E708
    if (ctx->r1 != 0) {
        // 0x8002E714: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_8002E708;
    }
    // 0x8002E714: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8002E718: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8002E71C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E720: sw          $v1, -0x2998($at)
    MEM_W(-0X2998, ctx->r1) = ctx->r3;
    // 0x8002E724: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E728: sw          $v1, -0x2994($at)
    MEM_W(-0X2994, ctx->r1) = ctx->r3;
    // 0x8002E72C: blez        $v0, L_8002E8A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002E730: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8002E8A0;
    }
    // 0x8002E730: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002E734: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8002E738: addiu       $s3, $s3, -0x3178
    ctx->r19 = ADD32(ctx->r19, -0X3178);
    // 0x8002E73C: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // 0x8002E740: addiu       $s4, $zero, 0x44
    ctx->r20 = ADD32(0, 0X44);
L_8002E744:
    // 0x8002E744: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8002E748: nop

    // 0x8002E74C: bltz        $s0, L_8002E894
    if (SIGNED(ctx->r16) < 0) {
        // 0x8002E750: lw          $t5, 0x70($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X70);
            goto L_8002E894;
    }
    // 0x8002E750: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8002E754: beq         $s6, $zero, L_8002E7A4
    if (ctx->r22 == 0) {
        // 0x8002E758: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8002E7A4;
    }
    // 0x8002E758: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E75C: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E760: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8002E764: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8002E768: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8002E76C: mflo        $t9
    ctx->r25 = lo;
    // 0x8002E770: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8002E774: lb          $t1, 0x2B($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X2B);
    // 0x8002E778: nop

    // 0x8002E77C: beq         $t1, $zero, L_8002E7A4
    if (ctx->r9 == 0) {
        // 0x8002E780: nop
    
            goto L_8002E7A4;
    }
    // 0x8002E780: nop

    // 0x8002E784: lw          $t2, -0x26FC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X26FC);
    // 0x8002E788: nop

    // 0x8002E78C: beq         $t2, $zero, L_8002E7A4
    if (ctx->r10 == 0) {
        // 0x8002E790: nop
    
            goto L_8002E7A4;
    }
    // 0x8002E790: nop

    // 0x8002E794: jal         0x8002EF2C
    // 0x8002E798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002EEEC(rdram, ctx);
        goto after_4;
    // 0x8002E798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8002E79C: b           L_8002E894
    // 0x8002E7A0: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
        goto L_8002E894;
    // 0x8002E7A0: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
L_8002E7A4:
    // 0x8002E7A4: lwc1        $f0, 0xC($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XC);
    // 0x8002E7A8: lwc1        $f12, -0x29A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X29A4);
    // 0x8002E7AC: lwc1        $f2, 0x14($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X14);
    // 0x8002E7B0: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8002E7B4: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8002E7B8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002E7BC: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x8002E7C0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002E7C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E7C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E7CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E7D0: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E7D4: lwc1        $f14, -0x29A0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X29A0);
    // 0x8002E7D8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002E7DC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8002E7E0: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8002E7E4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8002E7E8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002E7EC: subu        $t3, $t3, $s0
    ctx->r11 = SUB32(ctx->r11, ctx->r16);
    // 0x8002E7F0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002E7F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E7F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E7FC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8002E800: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002E804: addu        $a0, $t3, $t5
    ctx->r4 = ADD32(ctx->r11, ctx->r13);
    // 0x8002E808: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002E80C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8002E810: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8002E814: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002E818: nop

    // 0x8002E81C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002E820: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E824: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E828: nop

    // 0x8002E82C: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E830: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002E834: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8002E838: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8002E83C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002E840: nop

    // 0x8002E844: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002E848: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E84C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E850: nop

    // 0x8002E854: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002E858: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8002E85C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002E860: jal         0x8003151C
    // 0x8002E864: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    compute_grid_overlap_mask(rdram, ctx);
        goto after_5;
    // 0x8002E864: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_5:
    // 0x8002E868: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8002E86C: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8002E870: multu       $t1, $s4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E874: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x8002E878: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002E87C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8002E880: mflo        $t2
    ctx->r10 = lo;
    // 0x8002E884: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x8002E888: jal         0x8002E944
    // 0x8002E88C: nop

    func_8002E904(rdram, ctx);
        goto after_6;
    // 0x8002E88C: nop

    after_6:
    // 0x8002E890: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
L_8002E894:
    // 0x8002E894: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002E898: bne         $s2, $t5, L_8002E744
    if (ctx->r18 != ctx->r13) {
        // 0x8002E89C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8002E744;
    }
    // 0x8002E89C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8002E8A0:
    // 0x8002E8A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002E8A4: lw          $t6, -0x3850($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3850);
    // 0x8002E8A8: nop

    // 0x8002E8AC: blez        $t6, L_8002E8F0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8002E8B0: nop
    
            goto L_8002E8F0;
    }
    // 0x8002E8B0: nop

    // 0x8002E8B4: lw          $t7, 0x54($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X54);
    // 0x8002E8B8: nop

    // 0x8002E8BC: beq         $t7, $zero, L_8002E8E0
    if (ctx->r15 == 0) {
        // 0x8002E8C0: nop
    
            goto L_8002E8E0;
    }
    // 0x8002E8C0: nop

    // 0x8002E8C4: bne         $s6, $zero, L_8002E8E0
    if (ctx->r22 != 0) {
        // 0x8002E8C8: nop
    
            goto L_8002E8E0;
    }
    // 0x8002E8C8: nop

    // 0x8002E8CC: jal         0x8002FAA4
    // 0x8002E8D0: nop

    func_8002FA64(rdram, ctx);
        goto after_7;
    // 0x8002E8D0: nop

    after_7:
    // 0x8002E8D4: lw          $t8, 0x54($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X54);
    // 0x8002E8D8: nop

    // 0x8002E8DC: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
L_8002E8E0:
    // 0x8002E8E0: jal         0x8002F2EC
    // 0x8002E8E4: nop

    func_8002F2AC(rdram, ctx);
        goto after_8;
    // 0x8002E8E4: nop

    after_8:
    // 0x8002E8E8: jal         0x8002F480
    // 0x8002E8EC: nop

    func_8002F440(rdram, ctx);
        goto after_9;
    // 0x8002E8EC: nop

    after_9:
L_8002E8F0:
    // 0x8002E8F0: bne         $s6, $zero, L_8002E90C
    if (ctx->r22 != 0) {
        // 0x8002E8F4: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8002E90C;
    }
    // 0x8002E8F4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002E8F8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002E8FC: lw          $t9, -0x271C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X271C);
    // 0x8002E900: lw          $t0, 0x50($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X50);
    // 0x8002E904: b           L_8002E91C
    // 0x8002E908: sh          $t9, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r25;
        goto L_8002E91C;
    // 0x8002E908: sh          $t9, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r25;
L_8002E90C:
    // 0x8002E90C: lw          $t1, -0x271C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X271C);
    // 0x8002E910: lw          $t4, 0x58($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X58);
    // 0x8002E914: nop

    // 0x8002E918: sh          $t1, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r9;
L_8002E91C:
    // 0x8002E91C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002E920: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8002E924: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8002E928: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8002E92C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8002E930: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8002E934: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8002E938: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8002E93C: jr          $ra
    // 0x8002E940: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8002E940: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void postrace_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008239C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800823A0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800823A4: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800823A8: addiu       $s2, $s2, -0x2EC
    ctx->r18 = ADD32(ctx->r18, -0X2EC);
    // 0x800823AC: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800823B0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800823B4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800823B8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800823BC: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x800823C0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800823C4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800823C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800823CC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800823D0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800823D4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800823D8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800823DC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800823E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800823E4: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800823E8: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x800823EC: beq         $s6, $a3, L_80082608
    if (ctx->r22 == ctx->r7) {
        // 0x800823F0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80082608;
    }
    // 0x800823F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800823F4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800823F8: lw          $t7, 0x6964($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6964);
    // 0x800823FC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80082400: bne         $t7, $zero, L_80082440
    if (ctx->r15 != 0) {
        // 0x80082404: nop
    
            goto L_80082440;
    }
    // 0x80082404: nop

    // 0x80082408: lw          $t8, -0x5C4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5C4);
    // 0x8008240C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80082410: blez        $t8, L_80082440
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80082414: nop
    
            goto L_80082440;
    }
    // 0x80082414: nop

L_80082418:
    // 0x80082418: jal         0x8006A794
    // 0x8008241C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8008241C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80082420: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80082424: lw          $t9, -0x5C4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5C4);
    // 0x80082428: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008242C: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80082430: bne         $at, $zero, L_80082418
    if (ctx->r1 != 0) {
        // 0x80082434: or          $s1, $s1, $v0
        ctx->r17 = ctx->r17 | ctx->r2;
            goto L_80082418;
    }
    // 0x80082434: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
    // 0x80082438: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8008243C: nop

L_80082440:
    // 0x80082440: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80082444: addiu       $s0, $s0, 0x6DF4
    ctx->r16 = ADD32(ctx->r16, 0X6DF4);
    // 0x80082448: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8008244C: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80082450: addu        $t1, $t0, $s3
    ctx->r9 = ADD32(ctx->r8, ctx->r19);
    // 0x80082454: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80082458: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008245C: addiu       $s5, $s5, 0x6E00
    ctx->r21 = ADD32(ctx->r21, 0X6E00);
    // 0x80082460: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_80082464:
    // 0x80082464: beq         $a3, $zero, L_80082484
    if (ctx->r7 == 0) {
        // 0x80082468: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_80082484;
    }
    // 0x80082468: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8008246C: beq         $v0, $s3, L_800824E4
    if (ctx->r2 == ctx->r19) {
        // 0x80082470: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800824E4;
    }
    // 0x80082470: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80082474: beq         $v0, $s4, L_80082588
    if (ctx->r2 == ctx->r20) {
        // 0x80082478: andi        $t9, $s1, 0x9000
        ctx->r25 = ctx->r17 & 0X9000;
            goto L_80082588;
    }
    // 0x80082478: andi        $t9, $s1, 0x9000
    ctx->r25 = ctx->r17 & 0X9000;
    // 0x8008247C: b           L_800825D0
    // 0x80082480: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
        goto L_800825D0;
    // 0x80082480: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80082484:
    // 0x80082484: andi        $t2, $s1, 0x9000
    ctx->r10 = ctx->r17 & 0X9000;
    // 0x80082488: beq         $t2, $zero, L_800824A4
    if (ctx->r10 == 0) {
        // 0x8008248C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800824A4;
    }
    // 0x8008248C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80082490: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80082494: sw          $s3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r19;
    // 0x80082498: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008249C: b           L_800825CC
    // 0x800824A0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
        goto L_800825CC;
    // 0x800824A0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
L_800824A4:
    // 0x800824A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800824A8: lw          $v1, 0x6DF8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6DF8);
    // 0x800824AC: nop

    // 0x800824B0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800824B4: bne         $at, $zero, L_800824CC
    if (ctx->r1 != 0) {
        // 0x800824B8: subu        $t3, $v0, $v1
        ctx->r11 = SUB32(ctx->r2, ctx->r3);
            goto L_800824CC;
    }
    // 0x800824B8: subu        $t3, $v0, $v1
    ctx->r11 = SUB32(ctx->r2, ctx->r3);
    // 0x800824BC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800824C0: sw          $s3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r19;
    // 0x800824C4: b           L_800825CC
    // 0x800824C8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
        goto L_800825CC;
    // 0x800824C8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
L_800824CC:
    // 0x800824CC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800824D0: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800824D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800824D8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800824DC: b           L_800825CC
    // 0x800824E0: div.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
        goto L_800825CC;
    // 0x800824E0: div.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
L_800824E4:
    // 0x800824E4: lw          $v1, 0x6DFC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6DFC);
    // 0x800824E8: andi        $v0, $s1, 0x9000
    ctx->r2 = ctx->r17 & 0X9000;
    // 0x800824EC: bgez        $v1, L_800824F8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800824F0: nop
    
            goto L_800824F8;
    }
    // 0x800824F0: nop

    // 0x800824F4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800824F8:
    // 0x800824F8: beq         $v0, $zero, L_80082530
    if (ctx->r2 == 0) {
        // 0x800824FC: nop
    
            goto L_80082530;
    }
    // 0x800824FC: nop

    // 0x80082500: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x80082504: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80082508: slt         $at, $zero, $t5
    ctx->r1 = SIGNED(0) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8008250C: sw          $s4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r20;
    // 0x80082510: beq         $at, $zero, L_80082524
    if (ctx->r1 == 0) {
        // 0x80082514: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80082524;
    }
    // 0x80082514: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80082518: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8008251C: jal         0x80001D04
    // 0x80082520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80082520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_80082524:
    // 0x80082524: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80082528: b           L_800825D0
    // 0x8008252C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
        goto L_800825D0;
    // 0x8008252C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80082530:
    // 0x80082530: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80082534: nop

    // 0x80082538: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8008253C: bne         $at, $zero, L_80082570
    if (ctx->r1 != 0) {
        // 0x80082540: subu        $t6, $v0, $v1
        ctx->r14 = SUB32(ctx->r2, ctx->r3);
            goto L_80082570;
    }
    // 0x80082540: subu        $t6, $v0, $v1
    ctx->r14 = SUB32(ctx->r2, ctx->r3);
    // 0x80082544: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x80082548: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8008254C: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80082550: beq         $at, $zero, L_80082564
    if (ctx->r1 == 0) {
        // 0x80082554: sw          $s4, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r20;
            goto L_80082564;
    }
    // 0x80082554: sw          $s4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r20;
    // 0x80082558: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8008255C: jal         0x80001D04
    // 0x80082560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80082560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_80082564:
    // 0x80082564: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80082568: b           L_800825D0
    // 0x8008256C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
        goto L_800825D0;
    // 0x8008256C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80082570:
    // 0x80082570: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80082574: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80082578: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008257C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082580: b           L_800825CC
    // 0x80082584: div.s       $f20, $f18, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
        goto L_800825CC;
    // 0x80082584: div.s       $f20, $f18, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
L_80082588:
    // 0x80082588: bne         $t9, $zero, L_800825A8
    if (ctx->r25 != 0) {
        // 0x8008258C: nop
    
            goto L_800825A8;
    }
    // 0x8008258C: nop

    // 0x80082590: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80082594: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80082598: nop

    // 0x8008259C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800825A0: bne         $at, $zero, L_800825B4
    if (ctx->r1 != 0) {
        // 0x800825A4: nop
    
            goto L_800825B4;
    }
    // 0x800825A4: nop

L_800825A8:
    // 0x800825A8: sw          $s6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r22;
    // 0x800825AC: b           L_800825CC
    // 0x800825B0: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
        goto L_800825CC;
    // 0x800825B0: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
L_800825B4:
    // 0x800825B4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800825B8: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800825BC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800825C0: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800825C4: nop

    // 0x800825C8: div.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
L_800825CC:
    // 0x800825CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_800825D0:
    // 0x800825D0: nop

    // 0x800825D4: c.lt.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl < ctx->f18.fl;
    // 0x800825D8: nop

    // 0x800825DC: bc1f        L_800825EC
    if (!c1cs) {
        // 0x800825E0: nop
    
            goto L_800825EC;
    }
    // 0x800825E0: nop

    // 0x800825E4: bne         $s6, $a3, L_80082464
    if (ctx->r22 != ctx->r7) {
        // 0x800825E8: nop
    
            goto L_80082464;
    }
    // 0x800825E8: nop

L_800825EC:
    // 0x800825EC: beq         $s6, $a3, L_80082608
    if (ctx->r22 == ctx->r7) {
        // 0x800825F0: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_80082608;
    }
    // 0x800825F0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800825F4: lw          $a1, -0x2E8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2E8);
    // 0x800825F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800825FC: jal         0x8008263C
    // 0x80082600: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    draw_menu_elements(rdram, ctx);
        goto after_3;
    // 0x80082600: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x80082604: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_80082608:
    // 0x80082608: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008260C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80082610: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80082614: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80082618: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008261C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80082620: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80082624: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80082628: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8008262C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80082630: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80082634: jr          $ra
    // 0x80082638: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80082638: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void bgload_tick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7950: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C7954: lw          $t6, 0x3D00($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3D00);
    // 0x800C7958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C795C: beq         $t6, $zero, L_800C7998
    if (ctx->r14 == 0) {
        // 0x800C7960: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C7998;
    }
    // 0x800C7960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7964: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C7968: addiu       $v1, $v1, 0x3D0C
    ctx->r3 = ADD32(ctx->r3, 0X3D0C);
    // 0x800C796C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C7970: nop

    // 0x800C7974: blez        $v0, L_800C7998
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C7978: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800C7998;
    }
    // 0x800C7978: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800C797C: bne         $t7, $zero, L_800C7998
    if (ctx->r15 != 0) {
        // 0x800C7980: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_800C7998;
    }
    // 0x800C7980: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C7984: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C7988: addiu       $a0, $a0, -0x4DA0
    ctx->r4 = ADD32(ctx->r4, -0X4DA0);
    // 0x800C798C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800C7990: jal         0x800C9390
    // 0x800C7994: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7994: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_800C7998:
    // 0x800C7998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C799C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C79A0: jr          $ra
    // 0x800C79A4: nop

    return;
    // 0x800C79A4: nop

;}
RECOMP_FUNC void run_object_init_func(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800238F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800238F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800238F8: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x800238FC: nop

    // 0x80023900: lb          $t7, 0x54($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X54);
    // 0x80023904: nop

    // 0x80023908: sh          $t7, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r15;
    // 0x8002390C: lh          $t8, 0x48($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X48);
    // 0x80023910: nop

    // 0x80023914: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80023918: sltiu       $at, $t9, 0x76
    ctx->r1 = ctx->r25 < 0X76 ? 1 : 0;
    // 0x8002391C: beq         $at, $zero, L_80023E54
    if (ctx->r1 == 0) {
        // 0x80023920: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80023E54;
    }
    // 0x80023920: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80023924: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80023928: addu        $at, $at, $t9
    gpr jr_addend_80023934 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8002392C: lw          $t9, 0x5DF4($at)
    ctx->r25 = ADD32(ctx->r1, 0X5DF4);
    // 0x80023930: nop

    // 0x80023934: jr          $t9
    // 0x80023938: nop

    switch (jr_addend_80023934 >> 2) {
        case 0: goto L_8002393C; break;
        case 1: goto L_8002394C; break;
        case 2: goto L_8002395C; break;
        case 3: goto L_8002396C; break;
        case 4: goto L_80023AAC; break;
        case 5: goto L_8002397C; break;
        case 6: goto L_800239AC; break;
        case 7: goto L_800239BC; break;
        case 8: goto L_800239CC; break;
        case 9: goto L_800239EC; break;
        case 10: goto L_800239FC; break;
        case 11: goto L_80023A0C; break;
        case 12: goto L_80023A1C; break;
        case 13: goto L_80023A4C; break;
        case 14: goto L_80023A6C; break;
        case 15: goto L_80023A7C; break;
        case 16: goto L_80023A8C; break;
        case 17: goto L_80023AAC; break;
        case 18: goto L_800239CC; break;
        case 19: goto L_80023E54; break;
        case 20: goto L_80023E54; break;
        case 21: goto L_8002399C; break;
        case 22: goto L_80023A9C; break;
        case 23: goto L_80023E54; break;
        case 24: goto L_8002398C; break;
        case 25: goto L_80023ABC; break;
        case 26: goto L_800239DC; break;
        case 27: goto L_80023ACC; break;
        case 28: goto L_80023ADC; break;
        case 29: goto L_80023A2C; break;
        case 30: goto L_80023AEC; break;
        case 31: goto L_80023AFC; break;
        case 32: goto L_80023B0C; break;
        case 33: goto L_80023E54; break;
        case 34: goto L_80023E54; break;
        case 35: goto L_80023B1C; break;
        case 36: goto L_80023B3C; break;
        case 37: goto L_80023B4C; break;
        case 38: goto L_80023B5C; break;
        case 39: goto L_80023B6C; break;
        case 40: goto L_80023A3C; break;
        case 41: goto L_80023E54; break;
        case 42: goto L_80023B7C; break;
        case 43: goto L_80023B8C; break;
        case 44: goto L_80023B9C; break;
        case 45: goto L_80023BAC; break;
        case 46: goto L_80023BBC; break;
        case 47: goto L_80023E54; break;
        case 48: goto L_80023BCC; break;
        case 49: goto L_80023E54; break;
        case 50: goto L_80023E54; break;
        case 51: goto L_80023BDC; break;
        case 52: goto L_80023E54; break;
        case 53: goto L_80023E54; break;
        case 54: goto L_80023BEC; break;
        case 55: goto L_80023E54; break;
        case 56: goto L_80023BFC; break;
        case 57: goto L_80023C0C; break;
        case 58: goto L_80023C1C; break;
        case 59: goto L_80023E54; break;
        case 60: goto L_80023C2C; break;
        case 61: goto L_80023C3C; break;
        case 62: goto L_80023E54; break;
        case 63: goto L_80023C4C; break;
        case 64: goto L_80023C5C; break;
        case 65: goto L_80023C6C; break;
        case 66: goto L_80023B2C; break;
        case 67: goto L_80023C7C; break;
        case 68: goto L_80023C8C; break;
        case 69: goto L_80023C9C; break;
        case 70: goto L_80023CDC; break;
        case 71: goto L_80023CAC; break;
        case 72: goto L_80023D0C; break;
        case 73: goto L_80023D1C; break;
        case 74: goto L_80023D2C; break;
        case 75: goto L_80023D3C; break;
        case 76: goto L_80023D4C; break;
        case 77: goto L_80023D5C; break;
        case 78: goto L_80023D6C; break;
        case 79: goto L_80023E54; break;
        case 80: goto L_80023E54; break;
        case 81: goto L_80023D7C; break;
        case 82: goto L_80023D8C; break;
        case 83: goto L_80023D9C; break;
        case 84: goto L_80023E54; break;
        case 85: goto L_80023E54; break;
        case 86: goto L_80023E54; break;
        case 87: goto L_80023DBC; break;
        case 88: goto L_80023DAC; break;
        case 89: goto L_80023DCC; break;
        case 90: goto L_80023E54; break;
        case 91: goto L_80023E54; break;
        case 92: goto L_80023BFC; break;
        case 93: goto L_80023DDC; break;
        case 94: goto L_80023CAC; break;
        case 95: goto L_80023CBC; break;
        case 96: goto L_80023CCC; break;
        case 97: goto L_80023DEC; break;
        case 98: goto L_80023DFC; break;
        case 99: goto L_80023DFC; break;
        case 100: goto L_80023CBC; break;
        case 101: goto L_80023CCC; break;
        case 102: goto L_80023C9C; break;
        case 103: goto L_80023CAC; break;
        case 104: goto L_80023E0C; break;
        case 105: goto L_80023E54; break;
        case 106: goto L_80023E54; break;
        case 107: goto L_80023E1C; break;
        case 108: goto L_80023E2C; break;
        case 109: goto L_80023E3C; break;
        case 110: goto L_80023A5C; break;
        case 111: goto L_80023CEC; break;
        case 112: goto L_80023E54; break;
        case 113: goto L_80023E54; break;
        case 114: goto L_80023E54; break;
        case 115: goto L_80023E1C; break;
        case 116: goto L_80023E4C; break;
        case 117: goto L_80023CFC; break;
        default: switch_error(__func__, 0x80023934, 0x800E5DF4);
    }
    // 0x80023938: nop

L_8002393C:
    // 0x8002393C: jal         0x8004DAF0
    // 0x80023940: nop

    obj_init_racer(rdram, ctx);
        goto after_0;
    // 0x80023940: nop

    after_0:
    // 0x80023944: b           L_80023E58
    // 0x80023948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002394C:
    // 0x8002394C: jal         0x80033D00
    // 0x80023950: nop

    obj_init_scenery(rdram, ctx);
        goto after_1;
    // 0x80023950: nop

    after_1:
    // 0x80023954: b           L_80023E58
    // 0x80023958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002395C:
    // 0x8002395C: jal         0x80036C70
    // 0x80023960: nop

    obj_init_fish(rdram, ctx);
        goto after_2;
    // 0x80023960: nop

    after_2:
    // 0x80023964: b           L_80023E58
    // 0x80023968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002396C:
    // 0x8002396C: jal         0x80037720
    // 0x80023970: nop

    obj_init_animator(rdram, ctx);
        goto after_3;
    // 0x80023970: nop

    after_3:
    // 0x80023974: b           L_80023E58
    // 0x80023978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002397C:
    // 0x8002397C: jal         0x800389EC
    // 0x80023980: nop

    obj_init_smoke(rdram, ctx);
        goto after_4;
    // 0x80023980: nop

    after_4:
    // 0x80023984: b           L_80023E58
    // 0x80023988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002398C:
    // 0x8002398C: jal         0x80038AAC
    // 0x80023990: nop

    obj_init_unknown25(rdram, ctx);
        goto after_5;
    // 0x80023990: nop

    after_5:
    // 0x80023994: b           L_80023E58
    // 0x80023998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002399C:
    // 0x8002399C: jal         0x80038BB4
    // 0x800239A0: nop

    obj_init_bombexplosion(rdram, ctx);
        goto after_6;
    // 0x800239A0: nop

    after_6:
    // 0x800239A4: b           L_80023E58
    // 0x800239A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x800239A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239AC:
    // 0x800239AC: jal         0x80038E7C
    // 0x800239B0: nop

    obj_init_exit(rdram, ctx);
        goto after_7;
    // 0x800239B0: nop

    after_7:
    // 0x800239B4: b           L_80023E58
    // 0x800239B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x800239B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239BC:
    // 0x800239BC: jal         0x8003FDA8
    // 0x800239C0: nop

    obj_init_audio(rdram, ctx);
        goto after_8;
    // 0x800239C0: nop

    after_8:
    // 0x800239C4: b           L_80023E58
    // 0x800239C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x800239C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239CC:
    // 0x800239CC: jal         0x8003FF34
    // 0x800239D0: nop

    obj_init_audioline(rdram, ctx);
        goto after_9;
    // 0x800239D0: nop

    after_9:
    // 0x800239D4: b           L_80023E58
    // 0x800239D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x800239D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239DC:
    // 0x800239DC: jal         0x8004005C
    // 0x800239E0: nop

    obj_init_audioreverb(rdram, ctx);
        goto after_10;
    // 0x800239E0: nop

    after_10:
    // 0x800239E4: b           L_80023E58
    // 0x800239E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x800239E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239EC:
    // 0x800239EC: jal         0x800391A0
    // 0x800239F0: nop

    obj_init_cameracontrol(rdram, ctx);
        goto after_11;
    // 0x800239F0: nop

    after_11:
    // 0x800239F4: b           L_80023E58
    // 0x800239F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x800239F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239FC:
    // 0x800239FC: jal         0x800391D0
    // 0x80023A00: nop

    obj_init_setuppoint(rdram, ctx);
        goto after_12;
    // 0x80023A00: nop

    after_12:
    // 0x80023A04: b           L_80023E58
    // 0x80023A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A0C:
    // 0x80023A0C: jal         0x80039208
    // 0x80023A10: nop

    obj_init_dino_whale(rdram, ctx);
        goto after_13;
    // 0x80023A10: nop

    after_13:
    // 0x80023A14: b           L_80023E58
    // 0x80023A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A1C:
    // 0x80023A1C: jal         0x8003ACFC
    // 0x80023A20: nop

    obj_init_checkpoint(rdram, ctx);
        goto after_14;
    // 0x80023A20: nop

    after_14:
    // 0x80023A24: b           L_80023E58
    // 0x80023A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A2C:
    // 0x80023A2C: jal         0x8003AD74
    // 0x80023A30: nop

    obj_init_modechange(rdram, ctx);
        goto after_15;
    // 0x80023A30: nop

    after_15:
    // 0x80023A34: b           L_80023E58
    // 0x80023A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A3C:
    // 0x80023A3C: jal         0x8003B098
    // 0x80023A40: nop

    obj_init_bonus(rdram, ctx);
        goto after_16;
    // 0x80023A40: nop

    after_16:
    // 0x80023A44: b           L_80023E58
    // 0x80023A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A4C:
    // 0x80023A4C: jal         0x8003B80C
    // 0x80023A50: nop

    obj_init_door(rdram, ctx);
        goto after_17;
    // 0x80023A50: nop

    after_17:
    // 0x80023A54: b           L_80023E58
    // 0x80023A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A5C:
    // 0x80023A5C: jal         0x8003C220
    // 0x80023A60: nop

    obj_init_ttdoor(rdram, ctx);
        goto after_18;
    // 0x80023A60: nop

    after_18:
    // 0x80023A64: b           L_80023E58
    // 0x80023A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A6C:
    // 0x80023A6C: jal         0x8003CF58
    // 0x80023A70: nop

    obj_init_fogchanger(rdram, ctx);
        goto after_19;
    // 0x80023A70: nop

    after_19:
    // 0x80023A74: b           L_80023E58
    // 0x80023A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A7C:
    // 0x80023A7C: jal         0x8003D020
    // 0x80023A80: nop

    obj_init_ainode(rdram, ctx);
        goto after_20;
    // 0x80023A80: nop

    after_20:
    // 0x80023A84: b           L_80023E58
    // 0x80023A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A8C:
    // 0x80023A8C: jal         0x8003E00C
    // 0x80023A90: nop

    obj_init_weaponballoon(rdram, ctx);
        goto after_21;
    // 0x80023A90: nop

    after_21:
    // 0x80023A94: b           L_80023E58
    // 0x80023A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A9C:
    // 0x80023A9C: jal         0x8003E5F0
    // 0x80023AA0: nop

    obj_init_wballoonpop(rdram, ctx);
        goto after_22;
    // 0x80023AA0: nop

    after_22:
    // 0x80023AA4: b           L_80023E58
    // 0x80023AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023AAC:
    // 0x80023AAC: jal         0x8003E608
    // 0x80023AB0: nop

    obj_init_weapon(rdram, ctx);
        goto after_23;
    // 0x80023AB0: nop

    after_23:
    // 0x80023AB4: b           L_80023E58
    // 0x80023AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023ABC:
    // 0x80023ABC: jal         0x8003CF98
    // 0x80023AC0: nop

    obj_init_skycontrol(rdram, ctx);
        goto after_24;
    // 0x80023AC0: nop

    after_24:
    // 0x80023AC4: b           L_80023E58
    // 0x80023AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023ACC:
    // 0x80023ACC: jal         0x80034B30
    // 0x80023AD0: nop

    obj_init_torch_mist(rdram, ctx);
        goto after_25;
    // 0x80023AD0: nop

    after_25:
    // 0x80023AD4: b           L_80023E58
    // 0x80023AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023ADC:
    // 0x80023ADC: jal         0x800400E4
    // 0x80023AE0: nop

    obj_init_texscroll(rdram, ctx);
        goto after_26;
    // 0x80023AE0: nop

    after_26:
    // 0x80023AE4: b           L_80023E58
    // 0x80023AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023AEC:
    // 0x80023AEC: jal         0x800361D4
    // 0x80023AF0: nop

    obj_init_stopwatchman(rdram, ctx);
        goto after_27;
    // 0x80023AF0: nop

    after_27:
    // 0x80023AF4: b           L_80023E58
    // 0x80023AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023AFC:
    // 0x80023AFC: jal         0x8003D574
    // 0x80023B00: nop

    obj_init_banana(rdram, ctx);
        goto after_28;
    // 0x80023B00: nop

    after_28:
    // 0x80023B04: b           L_80023E58
    // 0x80023B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B0C:
    // 0x80023B0C: jal         0x800403E8
    // 0x80023B10: nop

    obj_init_rgbalight(rdram, ctx);
        goto after_29;
    // 0x80023B10: nop

    after_29:
    // 0x80023B14: b           L_80023E58
    // 0x80023B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B1C:
    // 0x80023B1C: jal         0x80040418
    // 0x80023B20: nop

    obj_init_buoy_pirateship(rdram, ctx);
        goto after_30;
    // 0x80023B20: nop

    after_30:
    // 0x80023B24: b           L_80023E58
    // 0x80023B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B2C:
    // 0x80023B2C: jal         0x800404DC
    // 0x80023B30: nop

    obj_init_log(rdram, ctx);
        goto after_31;
    // 0x80023B30: nop

    after_31:
    // 0x80023B34: b           L_80023E58
    // 0x80023B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B3C:
    // 0x80023B3C: jal         0x80040840
    // 0x80023B40: nop

    obj_init_weather(rdram, ctx);
        goto after_32;
    // 0x80023B40: nop

    after_32:
    // 0x80023B44: b           L_80023E58
    // 0x80023B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B4C:
    // 0x80023B4C: jal         0x8003CA2C
    // 0x80023B50: nop

    obj_init_bridge_whaleramp(rdram, ctx);
        goto after_33;
    // 0x80023B50: nop

    after_33:
    // 0x80023B54: b           L_80023E58
    // 0x80023B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B5C:
    // 0x80023B5C: jal         0x8003CEA4
    // 0x80023B60: nop

    obj_init_rampswitch(rdram, ctx);
        goto after_34;
    // 0x80023B60: nop

    after_34:
    // 0x80023B64: b           L_80023E58
    // 0x80023B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B6C:
    // 0x80023B6C: jal         0x8003CF40
    // 0x80023B70: nop

    obj_init_seamonster(rdram, ctx);
        goto after_35;
    // 0x80023B70: nop

    after_35:
    // 0x80023B74: b           L_80023E58
    // 0x80023B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B7C:
    // 0x80023B7C: jal         0x8004096C
    // 0x80023B80: nop

    obj_init_lensflare(rdram, ctx);
        goto after_36;
    // 0x80023B80: nop

    after_36:
    // 0x80023B84: b           L_80023E58
    // 0x80023B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B8C:
    // 0x80023B8C: jal         0x8004098C
    // 0x80023B90: nop

    obj_init_lensflareswitch(rdram, ctx);
        goto after_37;
    // 0x80023B90: nop

    after_37:
    // 0x80023B94: b           L_80023E58
    // 0x80023B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B9C:
    // 0x80023B9C: jal         0x8003526C
    // 0x80023BA0: nop

    obj_init_collectegg(rdram, ctx);
        goto after_38;
    // 0x80023BA0: nop

    after_38:
    // 0x80023BA4: b           L_80023E58
    // 0x80023BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BAC:
    // 0x80023BAC: jal         0x80035680
    // 0x80023BB0: nop

    obj_init_eggcreator(rdram, ctx);
        goto after_39;
    // 0x80023BB0: nop

    after_39:
    // 0x80023BB4: b           L_80023E58
    // 0x80023BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BBC:
    // 0x80023BBC: jal         0x80035F38
    // 0x80023BC0: nop

    obj_init_characterflag(rdram, ctx);
        goto after_40;
    // 0x80023BC0: nop

    after_40:
    // 0x80023BC4: b           L_80023E58
    // 0x80023BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BCC:
    // 0x80023BCC: jal         0x80037A58
    // 0x80023BD0: nop

    obj_init_animation(rdram, ctx);
        goto after_41;
    // 0x80023BD0: nop

    after_41:
    // 0x80023BD4: b           L_80023E58
    // 0x80023BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BDC:
    // 0x80023BDC: jal         0x80038894
    // 0x80023BE0: nop

    obj_init_infopoint(rdram, ctx);
        goto after_42;
    // 0x80023BE0: nop

    after_42:
    // 0x80023BE4: b           L_80023E58
    // 0x80023BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BEC:
    // 0x80023BEC: jal         0x8003C684
    // 0x80023BF0: nop

    obj_init_trigger(rdram, ctx);
        goto after_43;
    // 0x80023BF0: nop

    after_43:
    // 0x80023BF4: b           L_80023E58
    // 0x80023BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BFC:
    // 0x80023BFC: jal         0x800358CC
    // 0x80023C00: nop

    obj_init_airzippers_waterzippers(rdram, ctx);
        goto after_44;
    // 0x80023C00: nop

    after_44:
    // 0x80023C04: b           L_80023E58
    // 0x80023C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C0C:
    // 0x80023C0C: jal         0x80035E60
    // 0x80023C10: nop

    obj_init_timetrialghost(rdram, ctx);
        goto after_45;
    // 0x80023C10: nop

    after_45:
    // 0x80023C14: b           L_80023E58
    // 0x80023C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C1C:
    // 0x80023C1C: jal         0x800409E4
    // 0x80023C20: nop

    obj_init_wavegenerator(rdram, ctx);
        goto after_46;
    // 0x80023C20: nop

    after_46:
    // 0x80023C24: b           L_80023E58
    // 0x80023C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C2C:
    // 0x80023C2C: jal         0x80040A08
    // 0x80023C30: nop

    obj_init_butterfly(rdram, ctx);
        goto after_47;
    // 0x80023C30: nop

    after_47:
    // 0x80023C34: b           L_80023E58
    // 0x80023C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C3C:
    // 0x80023C3C: jal         0x800392F8
    // 0x80023C40: nop

    obj_init_parkwarden(rdram, ctx);
        goto after_48;
    // 0x80023C40: nop

    after_48:
    // 0x80023C44: b           L_80023E58
    // 0x80023C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C4C:
    // 0x80023C4C: jal         0x8003DEB4
    // 0x80023C50: nop

    obj_init_worldkey(rdram, ctx);
        goto after_49;
    // 0x80023C50: nop

    after_49:
    // 0x80023C54: b           L_80023E58
    // 0x80023C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C5C:
    // 0x80023C5C: jal         0x8003D42C
    // 0x80023C60: nop

    obj_init_bananacreator(rdram, ctx);
        goto after_50;
    // 0x80023C60: nop

    after_50:
    // 0x80023C64: b           L_80023E58
    // 0x80023C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C6C:
    // 0x80023C6C: jal         0x8003D078
    // 0x80023C70: nop

    obj_init_treasuresucker(rdram, ctx);
        goto after_51;
    // 0x80023C70: nop

    after_51:
    // 0x80023C74: b           L_80023E58
    // 0x80023C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C7C:
    // 0x80023C7C: jal         0x800375B8
    // 0x80023C80: nop

    obj_init_lavaspurt(rdram, ctx);
        goto after_52;
    // 0x80023C80: nop

    after_52:
    // 0x80023C84: b           L_80023E58
    // 0x80023C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C8C:
    // 0x80023C8C: jal         0x80037664
    // 0x80023C90: nop

    obj_init_posarrow(rdram, ctx);
        goto after_53;
    // 0x80023C90: nop

    after_53:
    // 0x80023C94: b           L_80023E58
    // 0x80023C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C9C:
    // 0x80023C9C: jal         0x800381CC
    // 0x80023CA0: nop

    obj_init_hittester(rdram, ctx);
        goto after_54;
    // 0x80023CA0: nop

    after_54:
    // 0x80023CA4: b           L_80023E58
    // 0x80023CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CAC:
    // 0x80023CAC: jal         0x80038220
    // 0x80023CB0: nop

    obj_init_dynamic_lighting_object(rdram, ctx);
        goto after_55;
    // 0x80023CB0: nop

    after_55:
    // 0x80023CB4: b           L_80023E58
    // 0x80023CB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023CB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CBC:
    // 0x80023CBC: jal         0x80038254
    // 0x80023CC0: nop

    obj_init_unknown96(rdram, ctx);
        goto after_56;
    // 0x80023CC0: nop

    after_56:
    // 0x80023CC4: b           L_80023E58
    // 0x80023CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CCC:
    // 0x80023CCC: jal         0x80038288
    // 0x80023CD0: nop

    obj_init_snowball(rdram, ctx);
        goto after_57;
    // 0x80023CD0: nop

    after_57:
    // 0x80023CD4: b           L_80023E58
    // 0x80023CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CDC:
    // 0x80023CDC: jal         0x80041AD0
    // 0x80023CE0: nop

    obj_init_midifade(rdram, ctx);
        goto after_58;
    // 0x80023CE0: nop

    after_58:
    // 0x80023CE4: b           L_80023E58
    // 0x80023CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CEC:
    // 0x80023CEC: jal         0x80041EC0
    // 0x80023CF0: nop

    obj_init_midifadepoint(rdram, ctx);
        goto after_59;
    // 0x80023CF0: nop

    after_59:
    // 0x80023CF4: b           L_80023E58
    // 0x80023CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CFC:
    // 0x80023CFC: jal         0x80042054
    // 0x80023D00: nop

    obj_init_midichset(rdram, ctx);
        goto after_60;
    // 0x80023D00: nop

    after_60:
    // 0x80023D04: b           L_80023E58
    // 0x80023D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D0C:
    // 0x80023D0C: jal         0x80034BA8
    // 0x80023D10: nop

    obj_init_effectbox(rdram, ctx);
        goto after_61;
    // 0x80023D10: nop

    after_61:
    // 0x80023D14: b           L_80023E58
    // 0x80023D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D1C:
    // 0x80023D1C: jal         0x80034EB0
    // 0x80023D20: nop

    obj_init_trophycab(rdram, ctx);
        goto after_62;
    // 0x80023D20: nop

    after_62:
    // 0x80023D24: b           L_80023E58
    // 0x80023D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D2C:
    // 0x80023D2C: jal         0x8004207C
    // 0x80023D30: nop

    obj_init_bubbler(rdram, ctx);
        goto after_63;
    // 0x80023D30: nop

    after_63:
    // 0x80023D34: b           L_80023E58
    // 0x80023D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D3C:
    // 0x80023D3C: jal         0x8003D2EC
    // 0x80023D40: nop

    obj_init_flycoin(rdram, ctx);
        goto after_64;
    // 0x80023D40: nop

    after_64:
    // 0x80023D44: b           L_80023E58
    // 0x80023D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D4C:
    // 0x80023D4C: jal         0x8003B3A8
    // 0x80023D50: nop

    obj_init_goldenballoon(rdram, ctx);
        goto after_65;
    // 0x80023D50: nop

    after_65:
    // 0x80023D54: b           L_80023E58
    // 0x80023D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D5C:
    // 0x80023D5C: jal         0x80034884
    // 0x80023D60: nop

    obj_init_laserbolt(rdram, ctx);
        goto after_66;
    // 0x80023D60: nop

    after_66:
    // 0x80023D64: b           L_80023E58
    // 0x80023D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D6C:
    // 0x80023D6C: jal         0x80034570
    // 0x80023D70: nop

    obj_init_lasergun(rdram, ctx);
        goto after_67;
    // 0x80023D70: nop

    after_67:
    // 0x80023D74: b           L_80023E58
    // 0x80023D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D7C:
    // 0x80023D7C: jal         0x80035B28
    // 0x80023D80: nop

    obj_init_groundzipper(rdram, ctx);
        goto after_68;
    // 0x80023D80: nop

    after_68:
    // 0x80023D84: b           L_80023E58
    // 0x80023D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D8C:
    // 0x80023D8C: jal         0x80037D94
    // 0x80023D90: nop

    obj_init_overridepos(rdram, ctx);
        goto after_69;
    // 0x80023D90: nop

    after_69:
    // 0x80023D94: b           L_80023E58
    // 0x80023D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D9C:
    // 0x80023D9C: jal         0x80037DAC
    // 0x80023DA0: nop

    obj_init_wizpigship(rdram, ctx);
        goto after_70;
    // 0x80023DA0: nop

    after_70:
    // 0x80023DA4: b           L_80023E58
    // 0x80023DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DAC:
    // 0x80023DAC: jal         0x8004214C
    // 0x80023DB0: nop

    obj_init_boost(rdram, ctx);
        goto after_71;
    // 0x80023DB0: nop

    after_71:
    // 0x80023DB4: b           L_80023E58
    // 0x80023DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DBC:
    // 0x80023DBC: jal         0x8003DC9C
    // 0x80023DC0: nop

    obj_init_silvercoin(rdram, ctx);
        goto after_72;
    // 0x80023DC0: nop

    after_72:
    // 0x80023DC4: b           L_80023E58
    // 0x80023DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DCC:
    // 0x80023DCC: jal         0x80038B08
    // 0x80023DD0: nop

    obj_init_wardensmoke(rdram, ctx);
        goto after_73;
    // 0x80023DD0: nop

    after_73:
    // 0x80023DD4: b           L_80023E58
    // 0x80023DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DDC:
    // 0x80023DDC: jal         0x80042190
    // 0x80023DE0: nop

    obj_init_unknown94(rdram, ctx);
        goto after_74;
    // 0x80023DE0: nop

    after_74:
    // 0x80023DE4: b           L_80023E58
    // 0x80023DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DEC:
    // 0x80023DEC: jal         0x80038D98
    // 0x80023DF0: nop

    obj_init_teleport(rdram, ctx);
        goto after_75;
    // 0x80023DF0: nop

    after_75:
    // 0x80023DF4: b           L_80023E58
    // 0x80023DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DFC:
    // 0x80023DFC: jal         0x8003576C
    // 0x80023E00: nop

    obj_init_lighthouse_rocketsignpost(rdram, ctx);
        goto after_76;
    // 0x80023E00: nop

    after_76:
    // 0x80023E04: b           L_80023E58
    // 0x80023E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023E0C:
    // 0x80023E0C: jal         0x800421AC
    // 0x80023E10: nop

    obj_init_rangetrigger(rdram, ctx);
        goto after_77;
    // 0x80023E10: nop

    after_77:
    // 0x80023E14: b           L_80023E58
    // 0x80023E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023E1C:
    // 0x80023E1C: jal         0x80033F84
    // 0x80023E20: nop

    obj_init_fireball_octoweapon(rdram, ctx);
        goto after_78;
    // 0x80023E20: nop

    after_78:
    // 0x80023E24: b           L_80023E58
    // 0x80023E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023E2C:
    // 0x80023E2C: jal         0x80042250
    // 0x80023E30: nop

    obj_init_frog(rdram, ctx);
        goto after_79;
    // 0x80023E30: nop

    after_79:
    // 0x80023E34: b           L_80023E58
    // 0x80023E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023E3C:
    // 0x80023E3C: jal         0x8003DBE0
    // 0x80023E40: nop

    obj_init_silvercoin_adv2(rdram, ctx);
        goto after_80;
    // 0x80023E40: nop

    after_80:
    // 0x80023E44: b           L_80023E58
    // 0x80023E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023E4C:
    // 0x80023E4C: jal         0x80042A5C
    // 0x80023E50: nop

    obj_init_levelname(rdram, ctx);
        goto after_81;
    // 0x80023E50: nop

    after_81:
L_80023E54:
    // 0x80023E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023E58:
    // 0x80023E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80023E5C: jr          $ra
    // 0x80023E60: nop

    return;
    // 0x80023E60: nop

;}
RECOMP_FUNC void music_tempo_set_relative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800014BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800014C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800014C4: jal         0x800015B8
    // 0x800014C8: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    music_tempo(rdram, ctx);
        goto after_0;
    // 0x800014C8: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800014CC: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800014D0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800014D4: bgez        $t6, L_800014EC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800014D8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800014EC;
    }
    // 0x800014D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800014DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800014E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800014E4: nop

    // 0x800014E8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800014EC:
    // 0x800014EC: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800014F0: nop

    // 0x800014F4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800014F8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800014FC: nop

    // 0x80001500: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80001504: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001508: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000150C: nop

    // 0x80001510: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80001514: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80001518: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000151C: jal         0x80001534
    // 0x80001520: nop

    music_tempo_set(rdram, ctx);
        goto after_1;
    // 0x80001520: nop

    after_1:
    // 0x80001524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000152C: jr          $ra
    // 0x80001530: nop

    return;
    // 0x80001530: nop

;}
RECOMP_FUNC void func_8006ABB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ADF4: bgez        $a0, L_8006AE04
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006ADF8: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006AE04;
    }
    // 0x8006ADF8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006ADFC: jr          $ra
    // 0x8006AE00: addiu       $v0, $zero, 0xE10
    ctx->r2 = ADD32(0, 0XE10);
    return;
    // 0x8006AE00: addiu       $v0, $zero, 0xE10
    ctx->r2 = ADD32(0, 0XE10);
L_8006AE04:
    // 0x8006AE04: lw          $t6, 0x16F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F0);
    // 0x8006AE08: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006AE0C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006AE10: bne         $at, $zero, L_8006AE20
    if (ctx->r1 != 0) {
        // 0x8006AE14: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006AE20;
    }
    // 0x8006AE14: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006AE18: jr          $ra
    // 0x8006AE1C: addiu       $v0, $zero, 0xE10
    ctx->r2 = ADD32(0, 0XE10);
    return;
    // 0x8006AE1C: addiu       $v0, $zero, 0xE10
    ctx->r2 = ADD32(0, 0XE10);
L_8006AE20:
    // 0x8006AE20: lw          $t7, 0x16FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16FC);
    // 0x8006AE24: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8006AE28: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006AE2C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006AE30: lh          $v0, 0x4($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X4);
    // 0x8006AE34: nop

    // 0x8006AE38: jr          $ra
    // 0x8006AE3C: nop

    return;
    // 0x8006AE3C: nop

;}
RECOMP_FUNC void obj_loop_rocketsignpost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035814: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80035818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003581C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80035820: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80035824: jal         0x8001BAFC
    // 0x80035828: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x80035828: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8003582C: beq         $v0, $zero, L_800358AC
    if (ctx->r2 == 0) {
        // 0x80035830: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_800358AC;
    }
    // 0x80035830: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80035834: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80035838: nop

    // 0x8003583C: lw          $v1, 0x4C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X4C);
    // 0x80035840: nop

    // 0x80035844: lbu         $t7, 0x13($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X13);
    // 0x80035848: nop

    // 0x8003584C: slti        $at, $t7, 0xC8
    ctx->r1 = SIGNED(ctx->r15) < 0XC8 ? 1 : 0;
    // 0x80035850: beq         $at, $zero, L_800358AC
    if (ctx->r1 == 0) {
        // 0x80035854: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_800358AC;
    }
    // 0x80035854: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80035858: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8003585C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80035860: bne         $v0, $t8, L_800358AC
    if (ctx->r2 != ctx->r24) {
        // 0x80035864: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_800358AC;
    }
    // 0x80035864: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80035868: jal         0x8006A794
    // 0x8003586C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8003586C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80035870: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80035874: andi        $t9, $v0, 0x2000
    ctx->r25 = ctx->r2 & 0X2000;
    // 0x80035878: bne         $t9, $zero, L_800358A0
    if (ctx->r25 != 0) {
        // 0x8003587C: nop
    
            goto L_800358A0;
    }
    // 0x8003587C: nop

    // 0x80035880: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80035884: nop

    // 0x80035888: lw          $t1, 0x5C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X5C);
    // 0x8003588C: nop

    // 0x80035890: lw          $t2, 0x100($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X100);
    // 0x80035894: nop

    // 0x80035898: bne         $a1, $t2, L_800358AC
    if (ctx->r5 != ctx->r10) {
        // 0x8003589C: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_800358AC;
    }
    // 0x8003589C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
L_800358A0:
    // 0x800358A0: jal         0x8006F4DC
    // 0x800358A4: nop

    begin_lighthouse_rocket_cutscene(rdram, ctx);
        goto after_2;
    // 0x800358A4: nop

    after_2:
    // 0x800358A8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
L_800358AC:
    // 0x800358AC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800358B0: lw          $t5, 0x4C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4C);
    // 0x800358B4: nop

    // 0x800358B8: sb          $t3, 0x13($t5)
    MEM_B(0X13, ctx->r13) = ctx->r11;
    // 0x800358BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800358C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800358C4: jr          $ra
    // 0x800358C8: nop

    return;
    // 0x800358C8: nop

;}
RECOMP_FUNC void func_80061C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061E4C: lb          $v0, 0x3A($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3A);
    // 0x80061E50: nop

    // 0x80061E54: bgez        $v0, L_80061E68
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80061E58: nop
    
            goto L_80061E68;
    }
    // 0x80061E58: nop

    // 0x80061E5C: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
    // 0x80061E60: lb          $v0, 0x3A($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3A);
    // 0x80061E64: nop

L_80061E68:
    // 0x80061E68: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80061E6C: nop

    // 0x80061E70: lb          $v1, 0x55($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X55);
    // 0x80061E74: nop

    // 0x80061E78: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80061E7C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80061E80: beq         $at, $zero, L_80061E94
    if (ctx->r1 == 0) {
        // 0x80061E84: nop
    
            goto L_80061E94;
    }
    // 0x80061E84: nop

    // 0x80061E88: sb          $v1, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = ctx->r3;
    // 0x80061E8C: lb          $v0, 0x3A($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3A);
    // 0x80061E90: nop

L_80061E94:
    // 0x80061E94: lw          $t7, 0x68($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X68);
    // 0x80061E98: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80061E9C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80061EA0: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80061EA4: nop

    // 0x80061EA8: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x80061EAC: nop

    // 0x80061EB0: lw          $t0, 0x44($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X44);
    // 0x80061EB4: nop

    // 0x80061EB8: beq         $t0, $zero, L_80061F60
    if (ctx->r8 == 0) {
        // 0x80061EBC: nop
    
            goto L_80061F60;
    }
    // 0x80061EBC: nop

    // 0x80061EC0: lb          $v0, 0x3B($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3B);
    // 0x80061EC4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80061EC8: bgez        $v0, L_80061EDC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80061ECC: nop
    
            goto L_80061EDC;
    }
    // 0x80061ECC: nop

    // 0x80061ED0: sb          $zero, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = 0;
    // 0x80061ED4: lb          $v0, 0x3B($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3B);
    // 0x80061ED8: nop

L_80061EDC:
    // 0x80061EDC: lh          $v1, 0x48($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X48);
    // 0x80061EE0: nop

    // 0x80061EE4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061EE8: bne         $at, $zero, L_80061EFC
    if (ctx->r1 != 0) {
        // 0x80061EEC: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_80061EFC;
    }
    // 0x80061EEC: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80061EF0: sb          $t1, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r9;
    // 0x80061EF4: lh          $v1, 0x48($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X48);
    // 0x80061EF8: nop

L_80061EFC:
    // 0x80061EFC: blez        $v1, L_80061F24
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80061F00: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80061F24;
    }
    // 0x80061F00: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80061F04: lb          $t3, 0x3B($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X3B);
    // 0x80061F08: lw          $t2, 0x44($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X44);
    // 0x80061F0C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80061F10: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80061F14: lw          $v1, 0x4($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X4);
    // 0x80061F18: b           L_80061F24
    // 0x80061F1C: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
        goto L_80061F24;
    // 0x80061F1C: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x80061F20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80061F24:
    // 0x80061F24: lh          $v0, 0x18($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X18);
    // 0x80061F28: nop

    // 0x80061F2C: sra         $t6, $v0, 4
    ctx->r14 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80061F30: bgez        $t6, L_80061F4C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80061F34: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80061F4C;
    }
    // 0x80061F34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80061F38: sh          $v1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r3;
    // 0x80061F3C: lh          $v0, 0x18($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X18);
    // 0x80061F40: nop

    // 0x80061F44: sra         $t7, $v0, 4
    ctx->r15 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80061F48: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80061F4C:
    // 0x80061F4C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80061F50: beq         $at, $zero, L_80061F60
    if (ctx->r1 == 0) {
        // 0x80061F54: nop
    
            goto L_80061F60;
    }
    // 0x80061F54: nop

    // 0x80061F58: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x80061F5C: sh          $t8, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r24;
L_80061F60:
    // 0x80061F60: jr          $ra
    // 0x80061F64: nop

    return;
    // 0x80061F64: nop

;}
RECOMP_FUNC void bgdraw_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077FEC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80077FF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80077FF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80077FF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80077FFC: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80078000: jal         0x8007A970
    // 0x80078004: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80078004: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    after_0:
    // 0x80078008: andi        $t4, $v0, 0xFFFF
    ctx->r12 = ctx->r2 & 0XFFFF;
    // 0x8007800C: addiu       $t1, $t4, -0x1
    ctx->r9 = ADD32(ctx->r12, -0X1);
    // 0x80078010: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80078014: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80078018: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007801C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80078020: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078024: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80078028: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8007802C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80078030: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80078034: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80078038: addiu       $t2, $t5, -0x1
    ctx->r10 = ADD32(ctx->r13, -0X1);
    // 0x8007803C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80078040: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80078044: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80078048: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8007804C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80078050: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80078054: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80078058: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007805C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80078060: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078064: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80078068: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8007806C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078070: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80078074: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80078078: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007807C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078080: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80078084: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80078088: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x8007808C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80078090: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80078094: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078098: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8007809C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800780A0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800780A4: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800780A8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800780AC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800780B0: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800780B4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800780B8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800780BC: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x800780C0: lui         $t8, 0x30
    ctx->r24 = S32(0X30 << 16);
    // 0x800780C4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800780C8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800780CC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800780D0: lui         $ra, 0xFF10
    ctx->r31 = S32(0XFF10 << 16);
    // 0x800780D4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800780D8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800780DC: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x800780E0: or          $t9, $t7, $ra
    ctx->r25 = ctx->r15 | ctx->r31;
    // 0x800780E4: lui         $t8, 0x200
    ctx->r24 = S32(0X200 << 16);
    // 0x800780E8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800780EC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800780F0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800780F4: lui         $t7, 0xFFFC
    ctx->r15 = S32(0XFFFC << 16);
    // 0x800780F8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800780FC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80078100: lui         $a3, 0xF700
    ctx->r7 = S32(0XF700 << 16);
    // 0x80078104: ori         $t7, $t7, 0xFFFC
    ctx->r15 = ctx->r15 | 0XFFFC;
    // 0x80078108: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8007810C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80078110: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078114: andi        $t8, $t1, 0x3FF
    ctx->r24 = ctx->r9 & 0X3FF;
    // 0x80078118: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8007811C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80078120: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x80078124: andi        $t9, $t2, 0x3FF
    ctx->r25 = ctx->r10 & 0X3FF;
    // 0x80078128: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x8007812C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80078130: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80078134: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80078138: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007813C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078140: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078144: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80078148: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8007814C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80078150: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078154: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80078158: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8007815C: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x80078160: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078164: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80078168: or          $t9, $t6, $ra
    ctx->r25 = ctx->r14 | ctx->r31;
    // 0x8007816C: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x80078170: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80078174: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078178: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x8007817C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80078180: beq         $t8, $zero, L_80078474
    if (ctx->r24 == 0) {
        // 0x80078184: nop
    
            goto L_80078474;
    }
    // 0x80078184: nop

    // 0x80078188: sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // 0x8007818C: jal         0x80066B50
    // 0x80078190: sw          $t5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r13;
    check_viewport_background_flag(rdram, ctx);
        goto after_1;
    // 0x80078190: sw          $t5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r13;
    after_1:
    // 0x80078194: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x80078198: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8007819C: beq         $v0, $zero, L_80078384
    if (ctx->r2 == 0) {
        // 0x800781A0: lui         $a3, 0xF700
        ctx->r7 = S32(0XF700 << 16);
            goto L_80078384;
    }
    // 0x800781A0: lui         $a3, 0xF700
    ctx->r7 = S32(0XF700 << 16);
    // 0x800781A4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800781A8: lw          $t6, -0x15B4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X15B4);
    // 0x800781AC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800781B0: beq         $t6, $zero, L_800781C8
    if (ctx->r14 == 0) {
        // 0x800781B4: nop
    
            goto L_800781C8;
    }
    // 0x800781B4: nop

    // 0x800781B8: jal         0x80078C4C
    // 0x800781BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bgdraw_chequer(rdram, ctx);
        goto after_2;
    // 0x800781BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800781C0: b           L_8007825C
    // 0x800781C4: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
        goto L_8007825C;
    // 0x800781C4: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
L_800781C8:
    // 0x800781C8: lw          $t9, -0x15BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X15BC);
    // 0x800781CC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800781D0: beq         $t9, $zero, L_800781E8
    if (ctx->r25 == 0) {
        // 0x800781D4: nop
    
            goto L_800781E8;
    }
    // 0x800781D4: nop

    // 0x800781D8: jal         0x800785E0
    // 0x800781DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bgdraw_texture(rdram, ctx);
        goto after_3;
    // 0x800781DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800781E0: b           L_8007825C
    // 0x800781E4: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
        goto L_8007825C;
    // 0x800781E4: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
L_800781E8:
    // 0x800781E8: lw          $v0, -0x15B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X15B0);
    // 0x800781EC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800781F0: beq         $v0, $zero, L_8007820C
    if (ctx->r2 == 0) {
        // 0x800781F4: addiu       $t9, $t4, -0x1
        ctx->r25 = ADD32(ctx->r12, -0X1);
            goto L_8007820C;
    }
    // 0x800781F4: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x800781F8: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800781FC: jalr        $v0
    // 0x80078200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x80078200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80078204: b           L_8007825C
    // 0x80078208: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
        goto L_8007825C;
    // 0x80078208: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
L_8007820C:
    // 0x8007820C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078210: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80078214: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078218: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8007821C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80078220: lw          $t8, -0x15C4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X15C4);
    // 0x80078224: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80078228: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007822C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078230: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80078234: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078238: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8007823C: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x80078240: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80078244: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80078248: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007824C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80078250: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078254: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078258: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
L_8007825C:
    // 0x8007825C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80078260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80078264: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x80078268: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    // 0x8007826C: jal         0x80066DE8
    // 0x80078270: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    copy_viewport_background_size_to_coords(rdram, ctx);
        goto after_5;
    // 0x80078270: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    after_5:
    // 0x80078274: beq         $v0, $zero, L_80078474
    if (ctx->r2 == 0) {
        // 0x80078278: lui         $t8, 0xBA00
        ctx->r24 = S32(0XBA00 << 16);
            goto L_80078474;
    }
    // 0x80078278: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8007827C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078280: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x80078284: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078288: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8007828C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078290: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078294: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078298: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8007829C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800782A0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800782A4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800782A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800782AC: lbu         $t8, -0x15D0($t6)
    ctx->r24 = MEM_BU(ctx->r14, -0X15D0);
    // 0x800782B0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800782B4: lbu         $t6, -0x15CC($t7)
    ctx->r14 = MEM_BU(ctx->r15, -0X15CC);
    // 0x800782B8: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800782BC: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800782C0: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x800782C4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800782C8: lbu         $t9, -0x15C8($t6)
    ctx->r25 = MEM_BU(ctx->r14, -0X15C8);
    // 0x800782CC: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800782D0: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x800782D4: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800782D8: ori         $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 | 0XFF;
    // 0x800782DC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800782E0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800782E4: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x800782E8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800782EC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800782F0: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x800782F4: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x800782F8: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x800782FC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80078300: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078304: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078308: lui         $t8, 0xF0A
    ctx->r24 = S32(0XF0A << 16);
    // 0x8007830C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80078310: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80078314: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80078318: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8007831C: ori         $t8, $t8, 0x4000
    ctx->r24 = ctx->r24 | 0X4000;
    // 0x80078320: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80078324: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80078328: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8007832C: nop

    // 0x80078330: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078334: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80078338: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8007833C: nop

    // 0x80078340: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80078344: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x80078348: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x8007834C: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80078350: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80078354: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80078358: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8007835C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078360: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x80078364: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x80078368: andi        $t6, $t7, 0x3FF
    ctx->r14 = ctx->r15 & 0X3FF;
    // 0x8007836C: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80078370: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80078374: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80078378: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8007837C: b           L_80078474
    // 0x80078380: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80078474;
    // 0x80078380: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80078384:
    // 0x80078384: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80078388: lw          $t7, -0x15B4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X15B4);
    // 0x8007838C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80078390: beq         $t7, $zero, L_800783A8
    if (ctx->r15 == 0) {
        // 0x80078394: nop
    
            goto L_800783A8;
    }
    // 0x80078394: nop

    // 0x80078398: jal         0x80078C4C
    // 0x8007839C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bgdraw_chequer(rdram, ctx);
        goto after_6;
    // 0x8007839C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800783A0: b           L_80078478
    // 0x800783A4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_80078478;
    // 0x800783A4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_800783A8:
    // 0x800783A8: lw          $t8, -0x15BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X15BC);
    // 0x800783AC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800783B0: beq         $t8, $zero, L_800783C8
    if (ctx->r24 == 0) {
        // 0x800783B4: nop
    
            goto L_800783C8;
    }
    // 0x800783B4: nop

    // 0x800783B8: jal         0x800785E0
    // 0x800783BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bgdraw_texture(rdram, ctx);
        goto after_7;
    // 0x800783BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800783C0: b           L_80078478
    // 0x800783C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_80078478;
    // 0x800783C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_800783C8:
    // 0x800783C8: lw          $v0, -0x15B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X15B0);
    // 0x800783CC: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800783D0: beq         $v0, $zero, L_800783E8
    if (ctx->r2 == 0) {
        // 0x800783D4: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800783E8;
    }
    // 0x800783D4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800783D8: jalr        $v0
    // 0x800783DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_8;
    // 0x800783DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800783E0: b           L_80078478
    // 0x800783E4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_80078478;
    // 0x800783E4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_800783E8:
    // 0x800783E8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800783EC: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800783F0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800783F4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800783F8: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800783FC: lbu         $t9, -0x15D0($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X15D0);
    // 0x80078400: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80078404: lbu         $t6, -0x15CC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X15CC);
    // 0x80078408: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x8007840C: andi        $t8, $t7, 0xF800
    ctx->r24 = ctx->r15 & 0XF800;
    // 0x80078410: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x80078414: andi        $t7, $t9, 0x7C0
    ctx->r15 = ctx->r25 & 0X7C0;
    // 0x80078418: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007841C: lbu         $t9, -0x15C8($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X15C8);
    // 0x80078420: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80078424: sra         $t8, $t9, 2
    ctx->r24 = S32(SIGNED(ctx->r25) >> 2);
    // 0x80078428: andi        $t7, $t8, 0x3E
    ctx->r15 = ctx->r24 & 0X3E;
    // 0x8007842C: or          $a0, $t6, $t7
    ctx->r4 = ctx->r14 | ctx->r15;
    // 0x80078430: ori         $t9, $a0, 0x1
    ctx->r25 = ctx->r4 | 0X1;
    // 0x80078434: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80078438: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8007843C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80078440: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078444: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x80078448: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x8007844C: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x80078450: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078454: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80078458: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007845C: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x80078460: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80078464: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80078468: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8007846C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078470: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_80078474:
    // 0x80078474: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80078478:
    // 0x80078478: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007847C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078480: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80078484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80078488: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007848C: jal         0x80067C7C
    // 0x80078490: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    viewport_scissor(rdram, ctx);
        goto after_9;
    // 0x80078490: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    after_9:
    // 0x80078494: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80078498: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007849C: jr          $ra
    // 0x800784A0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800784A0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void set_skydome_visbility(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028084: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028088: jr          $ra
    // 0x8002808C: sw          $a0, -0x49A4($at)
    MEM_W(-0X49A4, ctx->r1) = ctx->r4;
    return;
    // 0x8002808C: sw          $a0, -0x49A4($at)
    MEM_W(-0X49A4, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void alLink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8CF0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800C8CF4: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x800C8CF8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C8CFC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800C8D00: beq         $v0, $zero, L_800C8D0C
    if (ctx->r2 == 0) {
        // 0x800C8D04: nop
    
            goto L_800C8D0C;
    }
    // 0x800C8D04: nop

    // 0x800C8D08: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
L_800C8D0C:
    // 0x800C8D0C: jr          $ra
    // 0x800C8D10: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    return;
    // 0x800C8D10: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
;}
RECOMP_FUNC void get_file_number(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076740: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80076744: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80076748: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007674C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80076750: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80076754: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80076758: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8007675C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80076760: jal         0x80076C90
    // 0x80076764: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    string_to_font_codes(rdram, ctx);
        goto after_0;
    // 0x80076764: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x80076768: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8007676C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80076770: jal         0x80076C90
    // 0x80076774: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    string_to_font_codes(rdram, ctx);
        goto after_1;
    // 0x80076774: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80076778: jal         0x8009F064
    // 0x8007677C: nop

    get_language(rdram, ctx);
        goto after_2;
    // 0x8007677C: nop

    after_2:
    // 0x80076780: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80076784: bne         $v0, $at, L_80076798
    if (ctx->r2 != ctx->r1) {
        // 0x80076788: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80076798;
    }
    // 0x80076788: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007678C: lui         $a2, 0x4E44
    ctx->r6 = S32(0X4E44 << 16);
    // 0x80076790: b           L_800767B8
    // 0x80076794: ori         $a2, $a2, 0x594A
    ctx->r6 = ctx->r6 | 0X594A;
        goto L_800767B8;
    // 0x80076794: ori         $a2, $a2, 0x594A
    ctx->r6 = ctx->r6 | 0X594A;
L_80076798:
    // 0x80076798: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8007679C: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800767A0: lui         $a2, 0x4E44
    ctx->r6 = S32(0X4E44 << 16);
    // 0x800767A4: bne         $t6, $zero, L_800767B8
    if (ctx->r14 != 0) {
        // 0x800767A8: ori         $a2, $a2, 0x5945
        ctx->r6 = ctx->r6 | 0X5945;
            goto L_800767B8;
    }
    // 0x800767A8: ori         $a2, $a2, 0x5945
    ctx->r6 = ctx->r6 | 0X5945;
    // 0x800767AC: lui         $a2, 0x4E44
    ctx->r6 = S32(0X4E44 << 16);
    // 0x800767B0: b           L_800767B8
    // 0x800767B4: ori         $a2, $a2, 0x5950
    ctx->r6 = ctx->r6 | 0X5950;
        goto L_800767B8;
    // 0x800767B4: ori         $a2, $a2, 0x5950
    ctx->r6 = ctx->r6 | 0X5950;
L_800767B8:
    // 0x800767B8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800767BC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800767C0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800767C4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800767C8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800767CC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800767D0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800767D4: addiu       $t9, $t9, 0x4598
    ctx->r25 = ADD32(ctx->r25, 0X4598);
    // 0x800767D8: addiu       $t0, $sp, 0x2C
    ctx->r8 = ADD32(ctx->r29, 0X2C);
    // 0x800767DC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800767E0: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800767E4: addiu       $a1, $zero, 0x3459
    ctx->r5 = ADD32(0, 0X3459);
    // 0x800767E8: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x800767EC: jal         0x800D13E0
    // 0x800767F0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    osPfsFindFile_recomp(rdram, ctx);
        goto after_3;
    // 0x800767F0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_3:
    // 0x800767F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800767F8: bne         $v0, $zero, L_80076808
    if (ctx->r2 != 0) {
        // 0x800767FC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80076808;
    }
    // 0x800767FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80076800: b           L_80076860
    // 0x80076804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80076860;
    // 0x80076804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076808:
    // 0x80076808: beq         $v0, $at, L_80076818
    if (ctx->r2 == ctx->r1) {
        // 0x8007680C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80076818;
    }
    // 0x8007680C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80076810: bne         $v0, $at, L_80076824
    if (ctx->r2 != ctx->r1) {
        // 0x80076814: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80076824;
    }
    // 0x80076814: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80076818:
    // 0x80076818: b           L_80076860
    // 0x8007681C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80076860;
    // 0x8007681C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80076820: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80076824:
    // 0x80076824: bne         $v0, $at, L_80076838
    if (ctx->r2 != ctx->r1) {
        // 0x80076828: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80076838;
    }
    // 0x80076828: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007682C: b           L_80076860
    // 0x80076830: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80076860;
    // 0x80076830: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80076834: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_80076838:
    // 0x80076838: bne         $v0, $at, L_8007684C
    if (ctx->r2 != ctx->r1) {
        // 0x8007683C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8007684C;
    }
    // 0x8007683C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80076840: b           L_80076860
    // 0x80076844: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80076860;
    // 0x80076844: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80076848: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8007684C:
    // 0x8007684C: bne         $v0, $at, L_80076860
    if (ctx->r2 != ctx->r1) {
        // 0x80076850: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80076860;
    }
    // 0x80076850: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80076854: b           L_80076860
    // 0x80076858: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80076860;
    // 0x80076858: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8007685C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80076860:
    // 0x80076860: jr          $ra
    // 0x80076864: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80076864: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void scGetAudioTaskTimers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800799D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800799D8: lwc1        $f4, -0x1340($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1340);
    // 0x800799DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800799E0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800799E4: lwc1        $f6, -0x1338($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1338);
    // 0x800799E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800799EC: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x800799F0: lwc1        $f8, -0x1334($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1334);
    // 0x800799F4: jr          $ra
    // 0x800799F8: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    return;
    // 0x800799F8: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
;}
RECOMP_FUNC void obj_loop_characterflag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035FAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035FB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035FB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80035FB8: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80035FBC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80035FC0: bgez        $t6, L_80036074
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80035FC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80036074;
    }
    // 0x80035FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035FC8: lw          $a0, 0x78($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78);
    // 0x80035FCC: jal         0x8001BAFC
    // 0x80035FD0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x80035FD0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80035FD4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80035FD8: beq         $v0, $zero, L_80036070
    if (ctx->r2 == 0) {
        // 0x80035FDC: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80036070;
    }
    // 0x80035FDC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80035FE0: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    // 0x80035FE4: lw          $v1, 0x64($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X64);
    // 0x80035FE8: lb          $t7, 0x3($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3);
    // 0x80035FEC: addiu       $t8, $t8, -0x3110
    ctx->r24 = ADD32(ctx->r24, -0X3110);
    // 0x80035FF0: bltz        $t7, L_80036004
    if (SIGNED(ctx->r15) < 0) {
        // 0x80035FF4: sw          $t7, 0x7C($a2)
        MEM_W(0X7C, ctx->r6) = ctx->r15;
            goto L_80036004;
    }
    // 0x80035FF4: sw          $t7, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r15;
    // 0x80035FF8: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80035FFC: bne         $at, $zero, L_80036008
    if (ctx->r1 != 0) {
        // 0x80036000: nop
    
            goto L_80036008;
    }
    // 0x80036000: nop

L_80036004:
    // 0x80036004: sw          $zero, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = 0;
L_80036008:
    // 0x80036008: sw          $t8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r24;
    // 0x8003600C: lw          $t0, 0x7C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X7C);
    // 0x80036010: lw          $t9, 0x68($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X68);
    // 0x80036014: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80036018: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8003601C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80036020: lui         $t6, 0x4000
    ctx->r14 = S32(0X4000 << 16);
    // 0x80036024: sw          $t3, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r11;
    // 0x80036028: lbu         $v0, 0x0($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X0);
    // 0x8003602C: lbu         $a0, 0x1($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X1);
    // 0x80036030: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80036034: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80036038: sll         $t4, $v0, 21
    ctx->r12 = S32(ctx->r2 << 21);
    // 0x8003603C: sll         $t5, $a0, 5
    ctx->r13 = S32(ctx->r4 << 5);
    // 0x80036040: lui         $t7, 0x4001
    ctx->r15 = S32(0X4001 << 16);
    // 0x80036044: ori         $t6, $t6, 0x103
    ctx->r14 = ctx->r14 | 0X103;
    // 0x80036048: ori         $t7, $t7, 0x203
    ctx->r15 = ctx->r15 | 0X203;
    // 0x8003604C: or          $t8, $t4, $t5
    ctx->r24 = ctx->r12 | ctx->r13;
    // 0x80036050: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80036054: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80036058: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x8003605C: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x80036060: sw          $t7, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r15;
    // 0x80036064: sw          $t4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r12;
    // 0x80036068: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
    // 0x8003606C: sw          $t5, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r13;
L_80036070:
    // 0x80036070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036074:
    // 0x80036074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036078: jr          $ra
    // 0x8003607C: nop

    return;
    // 0x8003607C: nop

;}
RECOMP_FUNC void mtxf_scale_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070044: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x80070048: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8007004C: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80070050: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x80070054: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80070058: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8007005C: swc1        $f16, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f16.u32l;
    // 0x80070060: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80070064: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80070068: jr          $ra
    // 0x8007006C: swc1        $f16, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x8007006C: swc1        $f16, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_8005698C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800569CC: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800569D0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800569D4: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x800569D8: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x800569DC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800569E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800569E4: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800569E8: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x800569EC: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800569F0: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x800569F4: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800569F8: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x800569FC: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80056A00: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x80056A04: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80056A08: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80056A0C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80056A10: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80056A14: jal         0x8006BFD8
    // 0x80056A18: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    level_type(rdram, ctx);
        goto after_0;
    // 0x80056A18: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    after_0:
    // 0x80056A1C: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80056A20: andi        $a0, $v0, 0x40
    ctx->r4 = ctx->r2 & 0X40;
    // 0x80056A24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056A28: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80056A2C: bne         $t6, $at, L_80056A60
    if (ctx->r14 != ctx->r1) {
        // 0x80056A30: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_80056A60;
    }
    // 0x80056A30: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x80056A34: bne         $a0, $zero, L_80056A60
    if (ctx->r4 != 0) {
        // 0x80056A38: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80056A60;
    }
    // 0x80056A38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80056A3C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80056A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80056A44: addiu       $a2, $sp, 0xAC
    ctx->r6 = ADD32(ctx->r29, 0XAC);
    // 0x80056A48: jal         0x8001B7DC
    // 0x80056A4C: swc1        $f14, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f14.u32l;
    racer_find_nearest_opponent_relative(rdram, ctx);
        goto after_1;
    // 0x80056A4C: swc1        $f14, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x80056A50: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80056A54: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x80056A58: b           L_80056E28
    // 0x80056A5C: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
        goto L_80056E28;
    // 0x80056A5C: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
L_80056A60:
    // 0x80056A60: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80056A64: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80056A68: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80056A6C: mul.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80056A70: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80056A74: lwc1        $f20, 0x40($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80056A78: lwc1        $f12, 0x14($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80056A7C: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80056A80: lwc1        $f22, 0x50($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80056A84: lwc1        $f24, 0x58($s0)
    ctx->f24.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80056A88: lwc1        $f28, 0x54($s0)
    ctx->f28.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80056A8C: mul.s       $f4, $f12, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80056A90: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80056A94: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x80056A98: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80056A9C: mul.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80056AA0: add.s       $f26, $f10, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80056AA4: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80056AA8: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x80056AAC: mul.s       $f10, $f12, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x80056AB0: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80056AB4: swc1        $f16, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f16.u32l;
    // 0x80056AB8: add.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80056ABC: neg.s       $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f26.fl = -ctx->f26.fl;
    // 0x80056AC0: jal         0x8001BAA8
    // 0x80056AC4: neg.s       $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f30.fl = -ctx->f30.fl;
    get_racer_objects(rdram, ctx);
        goto after_2;
    // 0x80056AC4: neg.s       $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f30.fl = -ctx->f30.fl;
    after_2:
    // 0x80056AC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80056ACC: lwc1        $f12, 0x6E54($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6E54);
    // 0x80056AD0: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80056AD4: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80056AD8: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80056ADC: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80056AE0: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80056AE4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80056AE8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80056AEC: blez        $t8, L_80056E18
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80056AF0: swc1        $f12, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->f12.u32l;
            goto L_80056E18;
    }
    // 0x80056AF0: swc1        $f12, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f12.u32l;
    // 0x80056AF4: andi        $a0, $t8, 0x1
    ctx->r4 = ctx->r24 & 0X1;
    // 0x80056AF8: beq         $a0, $zero, L_80056C14
    if (ctx->r4 == 0) {
        // 0x80056AFC: lw          $t3, 0x70($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X70);
            goto L_80056C14;
    }
    // 0x80056AFC: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80056B00: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80056B04: nop

    // 0x80056B08: beq         $s1, $a0, L_80056C04
    if (ctx->r17 == ctx->r4) {
        // 0x80056B0C: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_80056C04;
    }
    // 0x80056B0C: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80056B10: beq         $t2, $zero, L_80056B30
    if (ctx->r10 == 0) {
        // 0x80056B14: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80056B30;
    }
    // 0x80056B14: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80056B18: lw          $t9, 0x64($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X64);
    // 0x80056B1C: nop

    // 0x80056B20: lb          $t4, 0x1D8($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X1D8);
    // 0x80056B24: nop

    // 0x80056B28: bne         $t4, $zero, L_80056C04
    if (ctx->r12 != 0) {
        // 0x80056B2C: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_80056C04;
    }
    // 0x80056B2C: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
L_80056B30:
    // 0x80056B30: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80056B34: lb          $t5, 0x212($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X212);
    // 0x80056B38: lb          $t7, 0x212($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X212);
    // 0x80056B3C: nop

    // 0x80056B40: bne         $t5, $t7, L_80056C04
    if (ctx->r13 != ctx->r15) {
        // 0x80056B44: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_80056C04;
    }
    // 0x80056B44: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80056B48: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80056B4C: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80056B50: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80056B54: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80056B58: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80056B5C: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80056B60: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80056B64: mul.s       $f6, $f20, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80056B68: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80056B6C: add.s       $f8, $f10, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x80056B70: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x80056B74: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x80056B78: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
    // 0x80056B7C: bc1f        L_80056C04
    if (!c1cs) {
        // 0x80056B80: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_80056C04;
    }
    // 0x80056B80: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80056B84: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80056B88: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80056B8C: mul.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80056B90: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80056B94: mul.s       $f4, $f28, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f8.fl);
    // 0x80056B98: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80056B9C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80056BA0: mul.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x80056BA4: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80056BA8: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80056BAC: add.s       $f2, $f4, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f30.fl;
    // 0x80056BB0: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80056BB4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80056BB8: bc1f        L_80056BC4
    if (!c1cs) {
        // 0x80056BBC: nop
    
            goto L_80056BC4;
    }
    // 0x80056BBC: nop

    // 0x80056BC0: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_80056BC4:
    // 0x80056BC4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80056BC8: nop

    // 0x80056BCC: bc1t        L_80056BD8
    if (c1cs) {
        // 0x80056BD0: nop
    
            goto L_80056BD8;
    }
    // 0x80056BD0: nop

    // 0x80056BD4: bne         $t1, $at, L_80056C00
    if (ctx->r9 != ctx->r1) {
        // 0x80056BD8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80056C00;
    }
L_80056BD8:
    // 0x80056BD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80056BDC: lwc1        $f6, 0x6E58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6E58);
    // 0x80056BE0: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80056BE4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80056BE8: nop

    // 0x80056BEC: bc1f        L_80056C04
    if (!c1cs) {
        // 0x80056BF0: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_80056C04;
    }
    // 0x80056BF0: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80056BF4: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    // 0x80056BF8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80056BFC: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_80056C00:
    // 0x80056C00: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
L_80056C04:
    // 0x80056C04: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80056C08: beq         $v1, $t8, L_80056E18
    if (ctx->r3 == ctx->r24) {
        // 0x80056C0C: nop
    
            goto L_80056E18;
    }
    // 0x80056C0C: nop

    // 0x80056C10: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
L_80056C14:
    // 0x80056C14: sll         $a3, $v1, 2
    ctx->r7 = S32(ctx->r3 << 2);
    // 0x80056C18: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80056C1C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80056C20: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x80056C24: addu        $a2, $v0, $a3
    ctx->r6 = ADD32(ctx->r2, ctx->r7);
L_80056C28:
    // 0x80056C28: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80056C2C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80056C30: beq         $s1, $a0, L_80056D20
    if (ctx->r17 == ctx->r4) {
        // 0x80056C34: nop
    
            goto L_80056D20;
    }
    // 0x80056C34: nop

    // 0x80056C38: beq         $t2, $zero, L_80056C58
    if (ctx->r10 == 0) {
        // 0x80056C3C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80056C58;
    }
    // 0x80056C3C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80056C40: lw          $t4, 0x64($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X64);
    // 0x80056C44: nop

    // 0x80056C48: lb          $t6, 0x1D8($t4)
    ctx->r14 = MEM_B(ctx->r12, 0X1D8);
    // 0x80056C4C: nop

    // 0x80056C50: bne         $t6, $zero, L_80056D20
    if (ctx->r14 != 0) {
        // 0x80056C54: nop
    
            goto L_80056D20;
    }
    // 0x80056C54: nop

L_80056C58:
    // 0x80056C58: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80056C5C: lb          $t5, 0x212($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X212);
    // 0x80056C60: lb          $t8, 0x212($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X212);
    // 0x80056C64: nop

    // 0x80056C68: bne         $t5, $t8, L_80056D20
    if (ctx->r13 != ctx->r24) {
        // 0x80056C6C: nop
    
            goto L_80056D20;
    }
    // 0x80056C6C: nop

    // 0x80056C70: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80056C74: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80056C78: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80056C7C: nop

    // 0x80056C80: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80056C84: lwc1        $f6, 0x14($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80056C88: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80056C8C: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80056C90: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80056C94: add.s       $f6, $f10, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x80056C98: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x80056C9C: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x80056CA0: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
    // 0x80056CA4: bc1f        L_80056D20
    if (!c1cs) {
        // 0x80056CA8: nop
    
            goto L_80056D20;
    }
    // 0x80056CA8: nop

    // 0x80056CAC: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80056CB0: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80056CB4: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80056CB8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80056CBC: mul.s       $f4, $f28, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f6.fl);
    // 0x80056CC0: lwc1        $f6, 0x14($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80056CC4: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80056CC8: mul.s       $f10, $f24, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f6.fl);
    // 0x80056CCC: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80056CD0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80056CD4: add.s       $f2, $f4, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f30.fl;
    // 0x80056CD8: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80056CDC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80056CE0: bc1f        L_80056CEC
    if (!c1cs) {
        // 0x80056CE4: nop
    
            goto L_80056CEC;
    }
    // 0x80056CE4: nop

    // 0x80056CE8: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_80056CEC:
    // 0x80056CEC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80056CF0: nop

    // 0x80056CF4: bc1t        L_80056D04
    if (c1cs) {
        // 0x80056CF8: nop
    
            goto L_80056D04;
    }
    // 0x80056CF8: nop

    // 0x80056CFC: bne         $t1, $at, L_80056D20
    if (ctx->r9 != ctx->r1) {
        // 0x80056D00: nop
    
            goto L_80056D20;
    }
    // 0x80056D00: nop

L_80056D04:
    // 0x80056D04: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80056D08: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80056D0C: bc1f        L_80056D20
    if (!c1cs) {
        // 0x80056D10: nop
    
            goto L_80056D20;
    }
    // 0x80056D10: nop

    // 0x80056D14: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x80056D18: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80056D1C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_80056D20:
    // 0x80056D20: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x80056D24: nop

    // 0x80056D28: beq         $s1, $a0, L_80056E10
    if (ctx->r17 == ctx->r4) {
        // 0x80056D2C: nop
    
            goto L_80056E10;
    }
    // 0x80056D2C: nop

    // 0x80056D30: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x80056D34: beq         $t2, $zero, L_80056D4C
    if (ctx->r10 == 0) {
        // 0x80056D38: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80056D4C;
    }
    // 0x80056D38: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80056D3C: lb          $t9, 0x1D8($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X1D8);
    // 0x80056D40: nop

    // 0x80056D44: bne         $t9, $zero, L_80056E10
    if (ctx->r25 != 0) {
        // 0x80056D48: nop
    
            goto L_80056E10;
    }
    // 0x80056D48: nop

L_80056D4C:
    // 0x80056D4C: lb          $t4, 0x212($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X212);
    // 0x80056D50: lb          $t6, 0x212($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X212);
    // 0x80056D54: nop

    // 0x80056D58: bne         $t4, $t6, L_80056E10
    if (ctx->r12 != ctx->r14) {
        // 0x80056D5C: nop
    
            goto L_80056E10;
    }
    // 0x80056D5C: nop

    // 0x80056D60: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80056D64: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80056D68: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80056D6C: nop

    // 0x80056D70: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80056D74: lwc1        $f6, 0x14($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80056D78: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80056D7C: mul.s       $f4, $f20, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80056D80: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80056D84: add.s       $f6, $f8, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f26.fl;
    // 0x80056D88: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x80056D8C: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x80056D90: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x80056D94: bc1f        L_80056E10
    if (!c1cs) {
        // 0x80056D98: nop
    
            goto L_80056E10;
    }
    // 0x80056D98: nop

    // 0x80056D9C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80056DA0: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80056DA4: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80056DA8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80056DAC: mul.s       $f10, $f28, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f6.fl);
    // 0x80056DB0: lwc1        $f6, 0x14($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80056DB4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80056DB8: mul.s       $f8, $f24, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f6.fl);
    // 0x80056DBC: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80056DC0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80056DC4: add.s       $f2, $f10, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x80056DC8: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80056DCC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80056DD0: bc1f        L_80056DDC
    if (!c1cs) {
        // 0x80056DD4: nop
    
            goto L_80056DDC;
    }
    // 0x80056DD4: nop

    // 0x80056DD8: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_80056DDC:
    // 0x80056DDC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80056DE0: nop

    // 0x80056DE4: bc1t        L_80056DF4
    if (c1cs) {
        // 0x80056DE8: nop
    
            goto L_80056DF4;
    }
    // 0x80056DE8: nop

    // 0x80056DEC: bne         $t1, $at, L_80056E10
    if (ctx->r9 != ctx->r1) {
        // 0x80056DF0: nop
    
            goto L_80056E10;
    }
    // 0x80056DF0: nop

L_80056DF4:
    // 0x80056DF4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80056DF8: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80056DFC: bc1f        L_80056E10
    if (!c1cs) {
        // 0x80056E00: nop
    
            goto L_80056E10;
    }
    // 0x80056E00: nop

    // 0x80056E04: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x80056E08: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80056E0C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_80056E10:
    // 0x80056E10: bne         $a3, $t3, L_80056C28
    if (ctx->r7 != ctx->r11) {
        // 0x80056E14: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80056C28;
    }
    // 0x80056E14: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_80056E18:
    // 0x80056E18: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80056E1C: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x80056E20: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80056E24: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
L_80056E28:
    // 0x80056E28: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80056E2C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80056E30: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80056E34: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80056E38: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80056E3C: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80056E40: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80056E44: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80056E48: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80056E4C: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80056E50: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80056E54: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80056E58: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80056E5C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80056E60: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80056E64: jr          $ra
    // 0x80056E68: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80056E68: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void menu_game_select_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CC74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008CC78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CC7C: jal         0x8008C620
    // 0x8008CC80: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    charselect_music_channels(rdram, ctx);
        goto after_0;
    // 0x8008CC80: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008CC84: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008CC88: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8008CC8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008CC90: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008CC94: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008CC98: addiu       $a1, $a1, 0x6978
    ctx->r5 = ADD32(ctx->r5, 0X6978);
    // 0x8008CC9C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008CCA0: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8008CCA4: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x8008CCA8: beq         $v0, $zero, L_8008CCD8
    if (ctx->r2 == 0) {
        // 0x8008CCAC: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8008CCD8;
    }
    // 0x8008CCAC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008CCB0: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8008CCB4: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x8008CCB8: bne         $at, $zero, L_8008CCD8
    if (ctx->r1 != 0) {
        // 0x8008CCBC: sw          $t9, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r25;
            goto L_8008CCD8;
    }
    // 0x8008CCBC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8008CCC0: jal         0x80082D08
    // 0x8008CCC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    trackmenu_set_records(rdram, ctx);
        goto after_1;
    // 0x8008CCC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x8008CCC8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008CCCC: addiu       $a1, $a1, 0x6978
    ctx->r5 = ADD32(ctx->r5, 0X6978);
    // 0x8008CCD0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008CCD4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_8008CCD8:
    // 0x8008CCD8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008CCDC: addiu       $v1, $v1, -0x604
    ctx->r3 = ADD32(ctx->r3, -0X604);
    // 0x8008CCE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008CCE4: nop

    // 0x8008CCE8: beq         $v0, $zero, L_8008CD14
    if (ctx->r2 == 0) {
        // 0x8008CCEC: slti        $at, $v0, 0x1F
        ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
            goto L_8008CD14;
    }
    // 0x8008CCEC: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8008CCF0: bgez        $v0, L_8008CD08
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008CCF4: addu        $t2, $v0, $a0
        ctx->r10 = ADD32(ctx->r2, ctx->r4);
            goto L_8008CD08;
    }
    // 0x8008CCF4: addu        $t2, $v0, $a0
    ctx->r10 = ADD32(ctx->r2, ctx->r4);
    // 0x8008CCF8: subu        $t1, $v0, $a0
    ctx->r9 = SUB32(ctx->r2, ctx->r4);
    // 0x8008CCFC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8008CD00: b           L_8008CD10
    // 0x8008CD04: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_8008CD10;
    // 0x8008CD04: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8008CD08:
    // 0x8008CD08: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8008CD0C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8008CD10:
    // 0x8008CD10: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
L_8008CD14:
    // 0x8008CD14: bne         $at, $zero, L_8008CDA4
    if (ctx->r1 != 0) {
        // 0x8008CD18: slti        $at, $v0, -0x1E
        ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
            goto L_8008CDA4;
    }
    // 0x8008CD18: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x8008CD1C: jal         0x8008CF84
    // 0x8008CD20: nop

    gameselect_free(rdram, ctx);
        goto after_2;
    // 0x8008CD20: nop

    after_2:
    // 0x8008CD24: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008CD28: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008CD2C: lw          $t3, 0x6980($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6980);
    // 0x8008CD30: lw          $v0, -0x620($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X620);
    // 0x8008CD34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CD38: bne         $t3, $v0, L_8008CD78
    if (ctx->r11 != ctx->r2) {
        // 0x8008CD3C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8008CD78;
    }
    // 0x8008CD3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008CD40: jal         0x80000B28
    // 0x8008CD44: nop

    music_change_on(rdram, ctx);
        goto after_3;
    // 0x8008CD44: nop

    after_3:
    // 0x8008CD48: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008CD4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CD50: jal         0x8006E7FC
    // 0x8008CD54: sw          $t4, -0x5C8($at)
    MEM_W(-0X5C8, ctx->r1) = ctx->r12;
    init_racer_headers(rdram, ctx);
        goto after_4;
    // 0x8008CD54: sw          $t4, -0x5C8($at)
    MEM_W(-0X5C8, ctx->r1) = ctx->r12;
    after_4:
    // 0x8008CD58: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8008CD5C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008CD60: jal         0x8006E528
    // 0x8008CD64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_5;
    // 0x8008CD64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8008CD68: jal         0x80081820
    // 0x8008CD6C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    menu_init(rdram, ctx);
        goto after_6;
    // 0x8008CD6C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_6:
    // 0x8008CD70: b           L_8008CF74
    // 0x8008CD74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008CF74;
    // 0x8008CD74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008CD78:
    // 0x8008CD78: sw          $v0, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r2;
    // 0x8008CD7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CD80: sw          $zero, -0x5C8($at)
    MEM_W(-0X5C8, ctx->r1) = 0;
    // 0x8008CD84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008CD88: jal         0x8006DD54
    // 0x8008CD8C: sb          $zero, 0x6F80($at)
    MEM_B(0X6F80, ctx->r1) = 0;
    set_level_default_vehicle(rdram, ctx);
        goto after_7;
    // 0x8008CD8C: sb          $zero, 0x6F80($at)
    MEM_B(0X6F80, ctx->r1) = 0;
    after_7:
    // 0x8008CD90: jal         0x80081820
    // 0x8008CD94: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    menu_init(rdram, ctx);
        goto after_8;
    // 0x8008CD94: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_8:
    // 0x8008CD98: b           L_8008CF74
    // 0x8008CD9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008CF74;
    // 0x8008CD9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008CDA0: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
L_8008CDA4:
    // 0x8008CDA4: beq         $at, $zero, L_8008CE0C
    if (ctx->r1 == 0) {
        // 0x8008CDA8: nop
    
            goto L_8008CE0C;
    }
    // 0x8008CDA8: nop

    // 0x8008CDAC: jal         0x8008CF84
    // 0x8008CDB0: nop

    gameselect_free(rdram, ctx);
        goto after_9;
    // 0x8008CDB0: nop

    after_9:
    // 0x8008CDB4: jal         0x8009F214
    // 0x8008CDB8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    is_drumstick_unlocked(rdram, ctx);
        goto after_10;
    // 0x8008CDB8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_10:
    // 0x8008CDBC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CDC0: beq         $v0, $zero, L_8008CDCC
    if (ctx->r2 == 0) {
        // 0x8008CDC4: nop
    
            goto L_8008CDCC;
    }
    // 0x8008CDC4: nop

    // 0x8008CDC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8008CDCC:
    // 0x8008CDCC: jal         0x8009F1FC
    // 0x8008CDD0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    is_tt_unlocked(rdram, ctx);
        goto after_11;
    // 0x8008CDD0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_11:
    // 0x8008CDD4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CDD8: beq         $v0, $zero, L_8008CDE8
    if (ctx->r2 == 0) {
        // 0x8008CDDC: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_8008CDE8;
    }
    // 0x8008CDDC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8008CDE0: xori        $t5, $a2, 0x3
    ctx->r13 = ctx->r6 ^ 0X3;
    // 0x8008CDE4: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
L_8008CDE8:
    // 0x8008CDE8: jal         0x8006E528
    // 0x8008CDEC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    load_level_for_menu(rdram, ctx);
        goto after_12;
    // 0x8008CDEC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_12:
    // 0x8008CDF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008CDF4: jal         0x8008B36C
    // 0x8008CDF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    charselect_prev(rdram, ctx);
        goto after_13;
    // 0x8008CDF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x8008CDFC: jal         0x80081820
    // 0x8008CE00: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    menu_init(rdram, ctx);
        goto after_14;
    // 0x8008CE00: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_14:
    // 0x8008CE04: b           L_8008CF74
    // 0x8008CE08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008CF74;
    // 0x8008CE08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008CE0C:
    // 0x8008CE0C: jal         0x8008CB50
    // 0x8008CE10: nop

    gameselect_render(rdram, ctx);
        goto after_15;
    // 0x8008CE10: nop

    after_15:
    // 0x8008CE14: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008CE18: lw          $t6, -0x604($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X604);
    // 0x8008CE1C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008CE20: bne         $t6, $zero, L_8008CF68
    if (ctx->r14 != 0) {
        // 0x8008CE24: addiu       $a1, $a1, 0x6978
        ctx->r5 = ADD32(ctx->r5, 0X6978);
            goto L_8008CF68;
    }
    // 0x8008CE24: addiu       $a1, $a1, 0x6978
    ctx->r5 = ADD32(ctx->r5, 0X6978);
    // 0x8008CE28: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8008CE2C: nop

    // 0x8008CE30: bne         $t7, $zero, L_8008CF68
    if (ctx->r15 != 0) {
        // 0x8008CE34: nop
    
            goto L_8008CF68;
    }
    // 0x8008CE34: nop

    // 0x8008CE38: jal         0x8006A794
    // 0x8008CE3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_16;
    // 0x8008CE3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x8008CE40: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008CE44: lw          $t8, -0x5C4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5C4);
    // 0x8008CE48: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008CE4C: lb          $a2, 0x6A04($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X6A04);
    // 0x8008CE50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008CE54: bne         $t8, $at, L_8008CE84
    if (ctx->r24 != ctx->r1) {
        // 0x8008CE58: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008CE84;
    }
    // 0x8008CE58: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008CE5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008CE60: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8008CE64: jal         0x8006A794
    // 0x8008CE68: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    input_pressed(rdram, ctx);
        goto after_17;
    // 0x8008CE68: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_17:
    // 0x8008CE6C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008CE70: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8008CE74: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008CE78: lb          $t9, 0x6A05($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X6A05);
    // 0x8008CE7C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008CE80: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_8008CE84:
    // 0x8008CE84: andi        $t0, $v1, 0x9000
    ctx->r8 = ctx->r3 & 0X9000;
    // 0x8008CE88: beq         $t0, $zero, L_8008CEE0
    if (ctx->r8 == 0) {
        // 0x8008CE8C: andi        $t4, $v1, 0x4000
        ctx->r12 = ctx->r3 & 0X4000;
            goto L_8008CEE0;
    }
    // 0x8008CE8C: andi        $t4, $v1, 0x4000
    ctx->r12 = ctx->r3 & 0X4000;
    // 0x8008CE90: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008CE94: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008CE98: lw          $t2, -0x620($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X620);
    // 0x8008CE9C: lw          $t1, 0x6980($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6980);
    // 0x8008CEA0: nop

    // 0x8008CEA4: bne         $t1, $t2, L_8008CEB4
    if (ctx->r9 != ctx->r10) {
        // 0x8008CEA8: nop
    
            goto L_8008CEB4;
    }
    // 0x8008CEA8: nop

    // 0x8008CEAC: jal         0x80000C98
    // 0x8008CEB0: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_18;
    // 0x8008CEB0: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_18:
L_8008CEB4:
    // 0x8008CEB4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008CEB8: jal         0x800C06F8
    // 0x8008CEBC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_19;
    // 0x8008CEBC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_19:
    // 0x8008CEC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8008CEC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CEC8: sw          $t3, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r11;
    // 0x8008CECC: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008CED0: jal         0x80001D04
    // 0x8008CED4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_20;
    // 0x8008CED4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x8008CED8: b           L_8008CF68
    // 0x8008CEDC: nop

        goto L_8008CF68;
    // 0x8008CEDC: nop

L_8008CEE0:
    // 0x8008CEE0: beq         $t4, $zero, L_8008CF00
    if (ctx->r12 == 0) {
        // 0x8008CEE4: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008CF00;
    }
    // 0x8008CEE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008CEE8: jal         0x800C06F8
    // 0x8008CEEC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_21;
    // 0x8008CEEC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_21:
    // 0x8008CEF0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8008CEF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CEF8: b           L_8008CF68
    // 0x8008CEFC: sw          $t5, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r13;
        goto L_8008CF68;
    // 0x8008CEFC: sw          $t5, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r13;
L_8008CF00:
    // 0x8008CF00: bgez        $a2, L_8008CF40
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008CF04: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8008CF40;
    }
    // 0x8008CF04: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008CF08: addiu       $v1, $v1, -0x620
    ctx->r3 = ADD32(ctx->r3, -0X620);
    // 0x8008CF0C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008CF10: lw          $t6, 0x6980($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6980);
    // 0x8008CF14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008CF18: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008CF1C: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8008CF20: beq         $at, $zero, L_8008CF40
    if (ctx->r1 == 0) {
        // 0x8008CF24: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_8008CF40;
    }
    // 0x8008CF24: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8008CF28: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8008CF2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008CF30: jal         0x80001D04
    // 0x8008CF34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    sound_play(rdram, ctx);
        goto after_22;
    // 0x8008CF34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_22:
    // 0x8008CF38: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008CF3C: nop

L_8008CF40:
    // 0x8008CF40: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008CF44: blez        $a2, L_8008CF68
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008CF48: addiu       $v1, $v1, -0x620
        ctx->r3 = ADD32(ctx->r3, -0X620);
            goto L_8008CF68;
    }
    // 0x8008CF48: addiu       $v1, $v1, -0x620
    ctx->r3 = ADD32(ctx->r3, -0X620);
    // 0x8008CF4C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008CF50: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008CF54: blez        $v0, L_8008CF68
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008CF58: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8008CF68;
    }
    // 0x8008CF58: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8008CF5C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008CF60: jal         0x80001D04
    // 0x8008CF64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_23;
    // 0x8008CF64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
L_8008CF68:
    // 0x8008CF68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008CF6C: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x8008CF70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008CF74:
    // 0x8008CF74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CF78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008CF7C: jr          $ra
    // 0x8008CF80: nop

    return;
    // 0x8008CF80: nop

;}
RECOMP_FUNC void init_racer_for_challenge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022928: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002292C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80022930: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022934: sb          $t6, -0x4B89($at)
    MEM_B(-0X4B89, ctx->r1) = ctx->r14;
    // 0x80022938: jal         0x8001BAFC
    // 0x8002293C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x8002293C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80022940: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80022944: nop

    // 0x80022948: sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    // 0x8002294C: sb          $zero, 0x192($v1)
    MEM_B(0X192, ctx->r3) = 0;
    // 0x80022950: sb          $zero, 0x193($v1)
    MEM_B(0X193, ctx->r3) = 0;
    // 0x80022954: sh          $zero, 0x1BA($v1)
    MEM_H(0X1BA, ctx->r3) = 0;
    // 0x80022958: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002295C: jal         0x80017EA8
    // 0x80022960: nop

    set_taj_challenge_type(rdram, ctx);
        goto after_1;
    // 0x80022960: nop

    after_1:
    // 0x80022964: jal         0x8006F5C8
    // 0x80022968: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    set_pause_lockout_timer(rdram, ctx);
        goto after_2;
    // 0x80022968: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_2:
    // 0x8002296C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022974: jr          $ra
    // 0x80022978: nop

    return;
    // 0x80022978: nop

;}
RECOMP_FUNC void alSynDelete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D31C0: jr          $ra
    // 0x800D31C4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x800D31C4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void transition_render_waves(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2918: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C291C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C2920: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C2924: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C2928: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C292C: jal         0x8007B820
    // 0x800C2930: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800C2930: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C2934: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C2938: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800C293C: lw          $v1, 0x3760($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3760);
    // 0x800C2940: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x800C2944: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800C2948: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800C294C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C2950: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x800C2954: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800C2958: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C295C: lw          $a2, 0x3750($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3750);
    // 0x800C2960: lw          $a3, 0x3758($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3758);
    // 0x800C2964: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C2968: addiu       $t9, $t9, 0x3BD8
    ctx->r25 = ADD32(ctx->r25, 0X3BD8);
    // 0x800C296C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800C2970: lui         $s0, 0x5D0
    ctx->r16 = S32(0X5D0 << 16);
    // 0x800C2974: lui         $t5, 0x5B0
    ctx->r13 = S32(0X5B0 << 16);
    // 0x800C2978: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800C297C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800C2980: ori         $t5, $t5, 0xC0
    ctx->r13 = ctx->r13 | 0XC0;
    // 0x800C2984: ori         $s0, $s0, 0xE0
    ctx->r16 = ctx->r16 | 0XE0;
    // 0x800C2988: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800C298C: addiu       $ra, $zero, 0x6
    ctx->r31 = ADD32(0, 0X6);
    // 0x800C2990: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800C2994: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C2998: lui         $t2, 0x400
    ctx->r10 = S32(0X400 << 16);
    // 0x800C299C: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800C29A0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800C29A4:
    // 0x800C29A4: beq         $t0, $t3, L_800C29B4
    if (ctx->r8 == ctx->r11) {
        // 0x800C29A8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C29B4;
    }
    // 0x800C29A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C29AC: bne         $t0, $t4, L_800C29FC
    if (ctx->r8 != ctx->r12) {
        // 0x800C29B0: addu        $a0, $a2, $t1
        ctx->r4 = ADD32(ctx->r6, ctx->r9);
            goto L_800C29FC;
    }
    // 0x800C29B0: addu        $a0, $a2, $t1
    ctx->r4 = ADD32(ctx->r6, ctx->r9);
L_800C29B4:
    // 0x800C29B4: addu        $a0, $a2, $t1
    ctx->r4 = ADD32(ctx->r6, ctx->r9);
    // 0x800C29B8: andi        $t6, $a0, 0x6
    ctx->r14 = ctx->r4 & 0X6;
    // 0x800C29BC: ori         $t7, $t6, 0x68
    ctx->r15 = ctx->r14 | 0X68;
    // 0x800C29C0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800C29C4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C29C8: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x800C29CC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800C29D0: ori         $t7, $t6, 0x104
    ctx->r15 = ctx->r14 | 0X104;
    // 0x800C29D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C29D8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C29DC: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800C29E0: addu        $t8, $a3, $t1
    ctx->r24 = ADD32(ctx->r7, ctx->r9);
    // 0x800C29E4: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800C29E8: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800C29EC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800C29F0: addiu       $a2, $a2, 0x8C
    ctx->r6 = ADD32(ctx->r6, 0X8C);
    // 0x800C29F4: b           L_800C2A40
    // 0x800C29F8: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, 0XC0);
        goto L_800C2A40;
    // 0x800C29F8: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, 0XC0);
L_800C29FC:
    // 0x800C29FC: andi        $t9, $a0, 0x6
    ctx->r25 = ctx->r4 & 0X6;
    // 0x800C2A00: ori         $t6, $t9, 0x78
    ctx->r14 = ctx->r25 | 0X78;
    // 0x800C2A04: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800C2A08: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800C2A0C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C2A10: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800C2A14: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x800C2A18: ori         $t6, $t9, 0x128
    ctx->r14 = ctx->r25 | 0X128;
    // 0x800C2A1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C2A20: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C2A24: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800C2A28: addu        $t7, $a3, $t1
    ctx->r15 = ADD32(ctx->r7, ctx->r9);
    // 0x800C2A2C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800C2A30: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x800C2A34: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800C2A38: addiu       $a2, $a2, 0xA0
    ctx->r6 = ADD32(ctx->r6, 0XA0);
    // 0x800C2A3C: addiu       $a3, $a3, 0xE0
    ctx->r7 = ADD32(ctx->r7, 0XE0);
L_800C2A40:
    // 0x800C2A40: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800C2A44: bne         $t0, $ra, L_800C29A4
    if (ctx->r8 != ctx->r31) {
        // 0x800C2A48: nop
    
            goto L_800C29A4;
    }
    // 0x800C2A48: nop

    // 0x800C2A4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C2A50: jal         0x8007B820
    // 0x800C2A54: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C2A54: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    after_1:
    // 0x800C2A58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2A5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C2A60: jr          $ra
    // 0x800C2A64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C2A64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800756D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007592C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80075930: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80075934: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80075938: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8007593C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80075940: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80075944: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x80075948: or          $fp, $a2, $zero
    ctx->r30 = ctx->r6 | 0;
    // 0x8007594C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80075950: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80075954: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80075958: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007595C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80075960: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80075964: jal         0x80075B34
    // 0x80075968: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80075968: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007596C: beq         $v0, $zero, L_8007598C
    if (ctx->r2 == 0) {
        // 0x80075970: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_8007598C;
    }
    // 0x80075970: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80075974: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80075978: jal         0x80075D44
    // 0x8007597C: nop

    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x8007597C: nop

    after_1:
    // 0x80075980: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80075984: b           L_80075B08
    // 0x80075988: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80075B08;
    // 0x80075988: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8007598C:
    // 0x8007598C: lw          $s5, 0x80($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X80);
    // 0x80075990: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80075994: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80075998: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8007599C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x800759A0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800759A4: or          $v1, $s5, $zero
    ctx->r3 = ctx->r21 | 0;
L_800759A8:
    // 0x800759A8: sb          $a3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r7;
    // 0x800759AC: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800759B0: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x800759B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800759B8: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x800759BC: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800759C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800759C4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800759C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800759CC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800759D0: bne         $at, $zero, L_800759A8
    if (ctx->r1 != 0) {
        // 0x800759D4: sb          $v0, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r2;
            goto L_800759A8;
    }
    // 0x800759D4: sb          $v0, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r2;
    // 0x800759D8: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800759DC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800759E0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800759E4: addiu       $a2, $a2, 0x7D6C
    ctx->r6 = ADD32(ctx->r6, 0X7D6C);
    // 0x800759E8: addiu       $a1, $a1, 0x7D5C
    ctx->r5 = ADD32(ctx->r5, 0X7D5C);
    // 0x800759EC: jal         0x80076740
    // 0x800759F0: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x800759F0: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    after_2:
    // 0x800759F4: bne         $v0, $zero, L_80075AF0
    if (ctx->r2 != 0) {
        // 0x800759F8: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_80075AF0;
    }
    // 0x800759F8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800759FC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80075A00: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80075A04: jal         0x80076B7C
    // 0x80075A08: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    get_file_size(rdram, ctx);
        goto after_3;
    // 0x80075A08: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_3:
    // 0x80075A0C: bne         $v0, $zero, L_80075AF0
    if (ctx->r2 != 0) {
        // 0x80075A10: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_80075AF0;
    }
    // 0x80075A10: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80075A14: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80075A18: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80075A1C: jal         0x80070EDC
    // 0x80075A20: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x80075A20: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_4:
    // 0x80075A24: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80075A28: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80075A2C: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x80075A30: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80075A34: jal         0x80076868
    // 0x80075A38: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_5;
    // 0x80075A38: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x80075A3C: bne         $v0, $zero, L_80075AE8
    if (ctx->r2 != 0) {
        // 0x80075A40: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_80075AE8;
    }
    // 0x80075A40: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80075A44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80075A48: addiu       $s1, $s2, 0x4
    ctx->r17 = ADD32(ctx->r18, 0X4);
    // 0x80075A4C: addiu       $s4, $zero, 0x6
    ctx->r20 = ADD32(0, 0X6);
    // 0x80075A50: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
L_80075A54:
    // 0x80075A54: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x80075A58: nop

    // 0x80075A5C: beq         $s3, $t6, L_80075ADC
    if (ctx->r19 == ctx->r14) {
        // 0x80075A60: nop
    
            goto L_80075ADC;
    }
    // 0x80075A60: nop

    // 0x80075A64: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x80075A68: jal         0x80074CA4
    // 0x80075A6C: addu        $a0, $t7, $s2
    ctx->r4 = ADD32(ctx->r15, ctx->r18);
    calculate_ghost_header_checksum(rdram, ctx);
        goto after_6;
    // 0x80075A6C: addu        $a0, $t7, $s2
    ctx->r4 = ADD32(ctx->r15, ctx->r18);
    after_6:
    // 0x80075A70: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x80075A74: nop

    // 0x80075A78: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x80075A7C: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80075A80: nop

    // 0x80075A84: beq         $v0, $t0, L_80075A94
    if (ctx->r2 == ctx->r8) {
        // 0x80075A88: addiu       $t1, $zero, 0x9
        ctx->r9 = ADD32(0, 0X9);
            goto L_80075A94;
    }
    // 0x80075A88: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80075A8C: b           L_80075AE8
    // 0x80075A90: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
        goto L_80075AE8;
    // 0x80075A90: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
L_80075A94:
    // 0x80075A94: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x80075A98: addu        $t3, $s6, $s0
    ctx->r11 = ADD32(ctx->r22, ctx->r16);
    // 0x80075A9C: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x80075AA0: lbu         $t4, 0x1($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X1);
    // 0x80075AA4: addu        $t5, $fp, $s0
    ctx->r13 = ADD32(ctx->r30, ctx->r16);
    // 0x80075AA8: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x80075AAC: lh          $t6, 0x2($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2);
    // 0x80075AB0: addu        $t9, $s7, $s0
    ctx->r25 = ADD32(ctx->r23, ctx->r16);
    // 0x80075AB4: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x80075AB8: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x80075ABC: sll         $t3, $s0, 1
    ctx->r11 = S32(ctx->r16 << 1);
    // 0x80075AC0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x80075AC4: lh          $t0, 0x2($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2);
    // 0x80075AC8: addu        $t4, $s5, $t3
    ctx->r12 = ADD32(ctx->r21, ctx->r11);
    // 0x80075ACC: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x80075AD0: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x80075AD4: nop

    // 0x80075AD8: sh          $t2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r10;
L_80075ADC:
    // 0x80075ADC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80075AE0: bne         $s0, $s4, L_80075A54
    if (ctx->r16 != ctx->r20) {
        // 0x80075AE4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80075A54;
    }
    // 0x80075AE4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80075AE8:
    // 0x80075AE8: jal         0x80071380
    // 0x80075AEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x80075AEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
L_80075AF0:
    // 0x80075AF0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80075AF4: jal         0x80075D44
    // 0x80075AF8: nop

    start_reading_controller_data(rdram, ctx);
        goto after_8;
    // 0x80075AF8: nop

    after_8:
    // 0x80075AFC: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80075B00: nop

    // 0x80075B04: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80075B08:
    // 0x80075B08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80075B0C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80075B10: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80075B14: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80075B18: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80075B1C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80075B20: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80075B24: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80075B28: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80075B2C: jr          $ra
    // 0x80075B30: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80075B30: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void mark_to_write_course_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE20: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EE24: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EE28: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EE2C: nop

    // 0x8006EE30: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x8006EE34: jr          $ra
    // 0x8006EE38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EE38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void set_taj_voice_line(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039360: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80039364: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80039368: jr          $ra
    // 0x8003936C: sh          $a0, -0x259E($at)
    MEM_H(-0X259E, ctx->r1) = ctx->r4;
    return;
    // 0x8003936C: sh          $a0, -0x259E($at)
    MEM_H(-0X259E, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void obj_loop_wizghosts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042D10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80042D14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042D18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80042D1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80042D20: jal         0x8001F494
    // 0x80042D24: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80042D24: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x80042D28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80042D2C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80042D30: lh          $t6, 0x18($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X18);
    // 0x80042D34: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80042D38: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80042D3C: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80042D40: sh          $t0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r8;
    // 0x80042D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80042D48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80042D4C: jr          $ra
    // 0x80042D50: nop

    return;
    // 0x80042D50: nop

;}
RECOMP_FUNC void alSavePull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCA74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CCA78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CCA7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CCA80: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800CCA84: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800CCA88: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CCA8C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CCA90: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800CCA94: jalr        $t9
    // 0x800CCA98: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CCA98: nop

    after_0:
    // 0x800CCA9C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800CCAA0: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x800CCAA4: lui         $t2, 0x440
    ctx->r10 = S32(0X440 << 16);
    // 0x800CCAA8: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800CCAAC: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x800CCAB0: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x800CCAB4: ori         $t2, $t2, 0x580
    ctx->r10 = ctx->r10 | 0X580;
    // 0x800CCAB8: lui         $t1, 0xD00
    ctx->r9 = S32(0XD00 << 16);
    // 0x800CCABC: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800CCAC0: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800CCAC4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800CCAC8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800CCACC: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x800CCAD0: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800CCAD4: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x800CCAD8: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x800CCADC: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x800CCAE0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800CCAE4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800CCAE8: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x800CCAEC: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x800CCAF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CCAF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CCAF8: jr          $ra
    // 0x800CCAFC: nop

    return;
    // 0x800CCAFC: nop

;}
RECOMP_FUNC void obj_loop_weaponballoon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E180: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003E184: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003E188: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003E18C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8003E190: lw          $a2, 0x64($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X64);
    // 0x8003E194: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8003E198: lh          $t6, 0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X4);
    // 0x8003E19C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003E1A0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8003E1A4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8003E1A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003E1AC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003E1B0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003E1B4: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003E1B8: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8003E1BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E1C0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003E1C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003E1C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003E1CC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8003E1D0: sub.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d - ctx->f16.d;
    // 0x8003E1D4: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x8003E1D8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8003E1DC: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x8003E1E0: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003E1E4: lwc1        $f6, 0x673C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X673C);
    // 0x8003E1E8: lwc1        $f7, 0x6738($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6738);
    // 0x8003E1EC: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x8003E1F0: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8003E1F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E1F8: bc1f        L_8003E218
    if (!c1cs) {
        // 0x8003E1FC: nop
    
            goto L_8003E218;
    }
    // 0x8003E1FC: nop

    // 0x8003E200: lwc1        $f8, 0x6740($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6740);
    // 0x8003E204: nop

    // 0x8003E208: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8003E20C: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003E210: nop

    // 0x8003E214: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
L_8003E218:
    // 0x8003E218: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E21C: lwc1        $f11, 0x6748($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6748);
    // 0x8003E220: lwc1        $f10, 0x674C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X674C);
    // 0x8003E224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E228: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x8003E22C: nop

    // 0x8003E230: bc1f        L_8003E24C
    if (!c1cs) {
        // 0x8003E234: nop
    
            goto L_8003E24C;
    }
    // 0x8003E234: nop

    // 0x8003E238: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x8003E23C: nop

    // 0x8003E240: ori         $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 | 0X4000;
    // 0x8003E244: b           L_8003E25C
    // 0x8003E248: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
        goto L_8003E25C;
    // 0x8003E248: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
L_8003E24C:
    // 0x8003E24C: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x8003E250: nop

    // 0x8003E254: andi        $t0, $t9, 0xBFFF
    ctx->r8 = ctx->r25 & 0XBFFF;
    // 0x8003E258: sh          $t0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r8;
L_8003E25C:
    // 0x8003E25C: lw          $t1, 0x7C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X7C);
    // 0x8003E260: nop

    // 0x8003E264: blez        $t1, L_8003E298
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8003E268: nop
    
            goto L_8003E298;
    }
    // 0x8003E268: nop

    // 0x8003E26C: sw          $t2, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r10;
    // 0x8003E270: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8003E274: jal         0x800B019C
    // 0x8003E278: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    obj_spawn_particle(rdram, ctx);
        goto after_0;
    // 0x8003E278: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_0:
    // 0x8003E27C: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
    // 0x8003E280: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8003E284: nop

    // 0x8003E288: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x8003E28C: sw          $t5, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r13;
    // 0x8003E290: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8003E294: nop

L_8003E298:
    // 0x8003E298: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
    // 0x8003E29C: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x8003E2A0: beq         $v0, $zero, L_8003E2F8
    if (ctx->r2 == 0) {
        // 0x8003E2A4: nop
    
            goto L_8003E2F8;
    }
    // 0x8003E2A4: nop

    // 0x8003E2A8: bne         $v0, $at, L_8003E2D0
    if (ctx->r2 != ctx->r1) {
        // 0x8003E2AC: lw          $t8, 0x44($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X44);
            goto L_8003E2D0;
    }
    // 0x8003E2AC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8003E2B0: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x8003E2B4: nop

    // 0x8003E2B8: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x8003E2BC: nop

    // 0x8003E2C0: slti        $at, $t7, 0x2D
    ctx->r1 = SIGNED(ctx->r15) < 0X2D ? 1 : 0;
    // 0x8003E2C4: bne         $at, $zero, L_8003E2E8
    if (ctx->r1 != 0) {
        // 0x8003E2C8: nop
    
            goto L_8003E2E8;
    }
    // 0x8003E2C8: nop

    // 0x8003E2CC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
L_8003E2D0:
    // 0x8003E2D0: nop

    // 0x8003E2D4: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x8003E2D8: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x8003E2DC: sh          $t0, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r8;
    // 0x8003E2E0: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
    // 0x8003E2E4: nop

L_8003E2E8:
    // 0x8003E2E8: bgez        $v0, L_8003E5E4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003E2EC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003E5E4;
    }
    // 0x8003E2EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003E2F0: b           L_8003E5E0
    // 0x8003E2F4: sh          $zero, 0x4($a2)
    MEM_H(0X4, ctx->r6) = 0;
        goto L_8003E5E0;
    // 0x8003E2F4: sh          $zero, 0x4($a2)
    MEM_H(0X4, ctx->r6) = 0;
L_8003E2F8:
    // 0x8003E2F8: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x8003E2FC: nop

    // 0x8003E300: lbu         $t1, 0x13($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X13);
    // 0x8003E304: nop

    // 0x8003E308: slti        $at, $t1, 0x2D
    ctx->r1 = SIGNED(ctx->r9) < 0X2D ? 1 : 0;
    // 0x8003E30C: beq         $at, $zero, L_8003E5E4
    if (ctx->r1 == 0) {
        // 0x8003E310: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003E5E4;
    }
    // 0x8003E310: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003E314: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003E318: nop

    // 0x8003E31C: beq         $v0, $zero, L_8003E5E4
    if (ctx->r2 == 0) {
        // 0x8003E320: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003E5E4;
    }
    // 0x8003E320: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003E324: lw          $t2, 0x40($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X40);
    // 0x8003E328: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003E32C: lb          $t3, 0x54($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X54);
    // 0x8003E330: nop

    // 0x8003E334: bne         $a0, $t3, L_8003E5E4
    if (ctx->r4 != ctx->r11) {
        // 0x8003E338: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003E5E4;
    }
    // 0x8003E338: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003E33C: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003E340: nop

    // 0x8003E344: lb          $t4, 0x1D6($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X1D6);
    // 0x8003E348: nop

    // 0x8003E34C: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x8003E350: bne         $at, $zero, L_8003E368
    if (ctx->r1 != 0) {
        // 0x8003E354: nop
    
            goto L_8003E368;
    }
    // 0x8003E354: nop

    // 0x8003E358: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x8003E35C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003E360: beq         $t5, $at, L_8003E5E4
    if (ctx->r13 == ctx->r1) {
        // 0x8003E364: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003E5E4;
    }
    // 0x8003E364: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003E368:
    // 0x8003E368: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x8003E36C: lb          $v0, 0x172($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X172);
    // 0x8003E370: sb          $t6, 0x172($v1)
    MEM_B(0X172, ctx->r3) = ctx->r14;
    // 0x8003E374: lb          $t7, 0x172($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X172);
    // 0x8003E378: nop

    // 0x8003E37C: bne         $v0, $t7, L_8003E3A8
    if (ctx->r2 != ctx->r15) {
        // 0x8003E380: nop
    
            goto L_8003E3A8;
    }
    // 0x8003E380: nop

    // 0x8003E384: lb          $t9, 0x173($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X173);
    // 0x8003E388: nop

    // 0x8003E38C: beq         $t9, $zero, L_8003E3A8
    if (ctx->r25 == 0) {
        // 0x8003E390: nop
    
            goto L_8003E3A8;
    }
    // 0x8003E390: nop

    // 0x8003E394: lb          $t8, 0x174($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X174);
    // 0x8003E398: nop

    // 0x8003E39C: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8003E3A0: b           L_8003E3AC
    // 0x8003E3A4: sb          $t0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r8;
        goto L_8003E3AC;
    // 0x8003E3A4: sb          $t0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r8;
L_8003E3A8:
    // 0x8003E3A8: sb          $zero, 0x174($v1)
    MEM_B(0X174, ctx->r3) = 0;
L_8003E3AC:
    // 0x8003E3AC: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x8003E3B0: jal         0x8006BFD8
    // 0x8003E3B4: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    level_type(rdram, ctx);
        goto after_1;
    // 0x8003E3B4: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_1:
    // 0x8003E3B8: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E3BC: andi        $t1, $v0, 0x40
    ctx->r9 = ctx->r2 & 0X40;
    // 0x8003E3C0: beq         $t1, $zero, L_8003E3F4
    if (ctx->r9 == 0) {
        // 0x8003E3C4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8003E3F4;
    }
    // 0x8003E3C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003E3C8: lb          $t2, 0x174($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X174);
    // 0x8003E3CC: nop

    // 0x8003E3D0: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x8003E3D4: bne         $at, $zero, L_8003E3E0
    if (ctx->r1 != 0) {
        // 0x8003E3D8: nop
    
            goto L_8003E3E0;
    }
    // 0x8003E3D8: nop

    // 0x8003E3DC: sb          $a0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r4;
L_8003E3E0:
    // 0x8003E3E0: lb          $t3, 0x172($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X172);
    // 0x8003E3E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003E3E8: bne         $t3, $at, L_8003E3F8
    if (ctx->r11 != ctx->r1) {
        // 0x8003E3EC: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_8003E3F8;
    }
    // 0x8003E3EC: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8003E3F0: sb          $a0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r4;
L_8003E3F4:
    // 0x8003E3F4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
L_8003E3F8:
    // 0x8003E3F8: sb          $t4, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r12;
    // 0x8003E3FC: jal         0x8009C850
    // 0x8003E400: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    get_filtered_cheats(rdram, ctx);
        goto after_2;
    // 0x8003E400: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_2:
    // 0x8003E404: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E408: sll         $t5, $v0, 11
    ctx->r13 = S32(ctx->r2 << 11);
    // 0x8003E40C: bgez        $t5, L_8003E418
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8003E410: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8003E418;
    }
    // 0x8003E410: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8003E414: sb          $a0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r4;
L_8003E418:
    // 0x8003E418: lb          $t6, 0x174($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X174);
    // 0x8003E41C: nop

    // 0x8003E420: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8003E424: bne         $at, $zero, L_8003E434
    if (ctx->r1 != 0) {
        // 0x8003E428: nop
    
            goto L_8003E434;
    }
    // 0x8003E428: nop

    // 0x8003E42C: sb          $a0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r4;
    // 0x8003E430: sb          $a0, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r4;
L_8003E434:
    // 0x8003E434: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8003E438: jal         0x8001E2D0
    // 0x8003E43C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    get_misc_asset(rdram, ctx);
        goto after_3;
    // 0x8003E43C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_3:
    // 0x8003E440: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E444: nop

    // 0x8003E448: lb          $t7, 0x172($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X172);
    // 0x8003E44C: lb          $t8, 0x174($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X174);
    // 0x8003E450: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8003E454: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8003E458: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8003E45C: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8003E460: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8003E464: lbu         $t4, 0x209($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X209);
    // 0x8003E468: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8003E46C: lb          $t3, 0x1($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X1);
    // 0x8003E470: lb          $a2, 0x173($v1)
    ctx->r6 = MEM_B(ctx->r3, 0X173);
    // 0x8003E474: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x8003E478: sb          $t5, 0x209($v1)
    MEM_B(0X209, ctx->r3) = ctx->r13;
    // 0x8003E47C: sb          $t3, 0x173($v1)
    MEM_B(0X173, ctx->r3) = ctx->r11;
    // 0x8003E480: jal         0x8009C90C
    // 0x8003E484: sb          $a2, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r6;
    get_number_of_active_players(rdram, ctx);
        goto after_4;
    // 0x8003E484: sb          $a2, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r6;
    after_4:
    // 0x8003E488: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E48C: lb          $a2, 0x2E($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X2E);
    // 0x8003E490: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8003E494: beq         $at, $zero, L_8003E4A0
    if (ctx->r1 == 0) {
        // 0x8003E498: addiu       $t6, $zero, 0x10
        ctx->r14 = ADD32(0, 0X10);
            goto L_8003E4A0;
    }
    // 0x8003E498: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8003E49C: sw          $t6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r14;
L_8003E4A0:
    // 0x8003E4A0: lh          $a3, 0x0($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X0);
    // 0x8003E4A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003E4A8: bne         $a3, $at, L_8003E4D4
    if (ctx->r7 != ctx->r1) {
        // 0x8003E4AC: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8003E4D4;
    }
    // 0x8003E4AC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8003E4B0: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003E4B4: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003E4B8: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003E4BC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8003E4C0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003E4C4: jal         0x80009558
    // 0x8003E4C8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_5;
    // 0x8003E4C8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x8003E4CC: b           L_8003E5C4
    // 0x8003E4D0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
        goto L_8003E5C4;
    // 0x8003E4D0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8003E4D4:
    // 0x8003E4D4: lb          $v0, 0x174($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X174);
    // 0x8003E4D8: lb          $t8, 0x2D($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X2D);
    // 0x8003E4DC: nop

    // 0x8003E4E0: bne         $t8, $v0, L_8003E574
    if (ctx->r24 != ctx->r2) {
        // 0x8003E4E4: nop
    
            goto L_8003E574;
    }
    // 0x8003E4E4: nop

    // 0x8003E4E8: lb          $t9, 0x1D8($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X1D8);
    // 0x8003E4EC: nop

    // 0x8003E4F0: bne         $t9, $zero, L_8003E5C4
    if (ctx->r25 != 0) {
        // 0x8003E4F4: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8003E5C4;
    }
    // 0x8003E4F4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003E4F8: lb          $t0, 0x173($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X173);
    // 0x8003E4FC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8003E500: beq         $a2, $t0, L_8003E554
    if (ctx->r6 == ctx->r8) {
        // 0x8003E504: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_8003E554;
    }
    // 0x8003E504: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8003E508: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    // 0x8003E50C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8003E510: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8003E514: jal         0x800A79E0
    // 0x8003E518: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    hud_sound_play_delayed(rdram, ctx);
        goto after_6;
    // 0x8003E518: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_6:
    // 0x8003E51C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003E524: lb          $a2, 0x174($v1)
    ctx->r6 = MEM_B(ctx->r3, 0X174);
    // 0x8003E528: nop

    // 0x8003E52C: slti        $at, $a2, 0x3
    ctx->r1 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
    // 0x8003E530: bne         $at, $zero, L_8003E540
    if (ctx->r1 != 0) {
        // 0x8003E534: addiu       $a0, $a2, 0xA0
        ctx->r4 = ADD32(ctx->r6, 0XA0);
            goto L_8003E540;
    }
    // 0x8003E534: addiu       $a0, $a2, 0xA0
    ctx->r4 = ADD32(ctx->r6, 0XA0);
    // 0x8003E538: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8003E53C: addiu       $a0, $a2, 0xA0
    ctx->r4 = ADD32(ctx->r6, 0XA0);
L_8003E540:
    // 0x8003E540: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x8003E544: jal         0x80001D04
    // 0x8003E548: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x8003E548: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_7:
    // 0x8003E54C: b           L_8003E5C4
    // 0x8003E550: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
        goto L_8003E5C4;
    // 0x8003E550: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8003E554:
    // 0x8003E554: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003E558: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003E55C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003E560: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003E564: jal         0x80009558
    // 0x8003E568: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_8;
    // 0x8003E568: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_8:
    // 0x8003E56C: b           L_8003E5C4
    // 0x8003E570: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
        goto L_8003E5C4;
    // 0x8003E570: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8003E574:
    // 0x8003E574: lb          $t3, 0x1D8($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X1D8);
    // 0x8003E578: nop

    // 0x8003E57C: bne         $t3, $zero, L_8003E5C4
    if (ctx->r11 != 0) {
        // 0x8003E580: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8003E5C4;
    }
    // 0x8003E580: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003E584: blez        $v0, L_8003E5AC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003E588: addiu       $a0, $zero, 0x13E
        ctx->r4 = ADD32(0, 0X13E);
            goto L_8003E5AC;
    }
    // 0x8003E588: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    // 0x8003E58C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8003E590: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8003E594: jal         0x800A79E0
    // 0x8003E598: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    hud_sound_play_delayed(rdram, ctx);
        goto after_9;
    // 0x8003E598: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_9:
    // 0x8003E59C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E5A0: nop

    // 0x8003E5A4: lb          $v0, 0x174($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X174);
    // 0x8003E5A8: nop

L_8003E5AC:
    // 0x8003E5AC: addiu       $a0, $v0, 0xA0
    ctx->r4 = ADD32(ctx->r2, 0XA0);
    // 0x8003E5B0: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x8003E5B4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8003E5B8: jal         0x80001D04
    // 0x8003E5BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x8003E5BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8003E5C0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8003E5C4:
    // 0x8003E5C4: sw          $t5, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r13;
    // 0x8003E5C8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8003E5CC: jal         0x800B019C
    // 0x8003E5D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_11;
    // 0x8003E5D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8003E5D4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8003E5D8: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    // 0x8003E5DC: sh          $t6, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r14;
L_8003E5E0:
    // 0x8003E5E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003E5E4:
    // 0x8003E5E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003E5E8: jr          $ra
    // 0x8003E5EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8003E5EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void set_game_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DC5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DC60: jr          $ra
    // 0x8006DC64: sw          $a0, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = ctx->r4;
    return;
    // 0x8006DC64: sw          $a0, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void hud_main_treasure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1788: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800A178C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A1790: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800A1794: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800A1798: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800A179C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800A17A0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A17A4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800A17A8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800A17AC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800A17B0: lw          $a3, 0x64($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X64);
    // 0x800A17B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A17B8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800A17BC: jal         0x8001BAA8
    // 0x800A17C0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800A17C0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A17C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800A17C8: jal         0x80068748
    // 0x800A17CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x800A17CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800A17D0: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800A17D4: jal         0x800A422C
    // 0x800A17D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    hud_race_start(rdram, ctx);
        goto after_2;
    // 0x800A17D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A17DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A17E0: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x800A17E4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800A17E8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800A17EC: beq         $v0, $s3, L_800A180C
    if (ctx->r2 == ctx->r19) {
        // 0x800A17F0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A180C;
    }
    // 0x800A17F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A17F4: beq         $v0, $at, L_800A18FC
    if (ctx->r2 == ctx->r1) {
        // 0x800A17F8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A18FC;
    }
    // 0x800A17F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A17FC: beq         $v0, $at, L_800A18FC
    if (ctx->r2 == ctx->r1) {
        // 0x800A1800: nop
    
            goto L_800A18FC;
    }
    // 0x800A1800: nop

    // 0x800A1804: b           L_800A1908
    // 0x800A1808: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
        goto L_800A1908;
    // 0x800A1808: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
L_800A180C:
    // 0x800A180C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1810: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A1814: blez        $t7, L_800A18BC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A1818: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_800A18BC;
    }
    // 0x800A1818: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800A181C: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x800A1820: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A1824: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A1828: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
L_800A182C:
    // 0x800A182C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800A1830: nop

    // 0x800A1834: lw          $a0, 0x64($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X64);
    // 0x800A1838: jal         0x800A4B38
    // 0x800A183C: nop

    hud_treasure(rdram, ctx);
        goto after_3;
    // 0x800A183C: nop

    after_3:
    // 0x800A1840: bne         $s1, $s3, L_800A1878
    if (ctx->r17 != ctx->r19) {
        // 0x800A1844: nop
    
            goto L_800A1878;
    }
    // 0x800A1844: nop

    // 0x800A1848: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A184C: nop

    // 0x800A1850: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A1854: nop

    // 0x800A1858: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800A185C: swc1        $f6, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f6.u32l;
    // 0x800A1860: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A1864: nop

    // 0x800A1868: lwc1        $f8, 0x40C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A186C: nop

    // 0x800A1870: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A1874: swc1        $f10, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f10.u32l;
L_800A1878:
    // 0x800A1878: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A187C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A1880: lwc1        $f16, 0x64C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A1884: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A1888: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x800A188C: swc1        $f18, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f18.u32l;
    // 0x800A1890: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A1894: nop

    // 0x800A1898: lwc1        $f4, 0x40C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A189C: nop

    // 0x800A18A0: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800A18A4: swc1        $f6, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f6.u32l;
    // 0x800A18A8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800A18AC: nop

    // 0x800A18B0: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A18B4: bne         $at, $zero, L_800A182C
    if (ctx->r1 != 0) {
        // 0x800A18B8: nop
    
            goto L_800A182C;
    }
    // 0x800A18B8: nop

L_800A18BC:
    // 0x800A18BC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A18C0: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
    // 0x800A18C4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A18C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A18CC: lwc1        $f0, -0x7368($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7368);
    // 0x800A18D0: lwc1        $f8, 0x64C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A18D4: nop

    // 0x800A18D8: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A18DC: swc1        $f10, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f10.u32l;
    // 0x800A18E0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A18E4: nop

    // 0x800A18E8: lwc1        $f16, 0x40C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A18EC: nop

    // 0x800A18F0: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800A18F4: b           L_800A1904
    // 0x800A18F8: swc1        $f18, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f18.u32l;
        goto L_800A1904;
    // 0x800A18F8: swc1        $f18, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f18.u32l;
L_800A18FC:
    // 0x800A18FC: jal         0x800A4B38
    // 0x800A1900: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_treasure(rdram, ctx);
        goto after_4;
    // 0x800A1900: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
L_800A1904:
    // 0x800A1904: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
L_800A1908:
    // 0x800A1908: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A190C: lw          $a3, 0x64($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X64);
    // 0x800A1910: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A1914: jal         0x8007B820
    // 0x800A1918: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    rendermode_reset(rdram, ctx);
        goto after_5;
    // 0x800A1918: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_5:
    // 0x800A191C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800A1920: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800A1924: jal         0x800A469C
    // 0x800A1928: nop

    hud_bananas(rdram, ctx);
        goto after_6;
    // 0x800A1928: nop

    after_6:
    // 0x800A192C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800A1930: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800A1934: jal         0x800A7A7C
    // 0x800A1938: nop

    hud_weapon(rdram, ctx);
        goto after_7;
    // 0x800A1938: nop

    after_7:
    // 0x800A193C: jal         0x80068748
    // 0x800A1940: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_8;
    // 0x800A1940: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800A1944: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A1948: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800A194C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A1950: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800A1954: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800A1958: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800A195C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800A1960: jr          $ra
    // 0x800A1964: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800A1964: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void video_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A760: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8007A764: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x8007A768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A76C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A770: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007A774: bne         $v0, $zero, L_8007A7AC
    if (ctx->r2 != 0) {
        // 0x8007A778: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8007A7AC;
    }
    // 0x8007A778: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007A77C: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x8007A780: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A784: sw          $t6, 0x6710($at)
    MEM_W(0X6710, ctx->r1) = ctx->r14;
    // 0x8007A788: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007A78C: lwc1        $f4, -0x7F74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7F74);
    // 0x8007A790: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A794: swc1        $f4, 0x6714($at)
    MEM_W(0X6714, ctx->r1) = ctx->f4.u32l;
    // 0x8007A798: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007A79C: lwc1        $f6, -0x7F70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7F70);
    // 0x8007A7A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A7A4: b           L_8007A810
    // 0x8007A7A8: swc1        $f6, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->f6.u32l;
        goto L_8007A810;
    // 0x8007A7A8: swc1        $f6, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->f6.u32l;
L_8007A7AC:
    // 0x8007A7AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007A7B0: bne         $v0, $at, L_8007A7E8
    if (ctx->r2 != ctx->r1) {
        // 0x8007A7B4: addiu       $t8, $zero, 0x3C
        ctx->r24 = ADD32(0, 0X3C);
            goto L_8007A7E8;
    }
    // 0x8007A7B4: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8007A7B8: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x8007A7BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A7C0: sw          $t7, 0x6710($at)
    MEM_W(0X6710, ctx->r1) = ctx->r15;
    // 0x8007A7C4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007A7C8: lwc1        $f8, -0x7F6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7F6C);
    // 0x8007A7CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A7D0: swc1        $f8, 0x6714($at)
    MEM_W(0X6714, ctx->r1) = ctx->f8.u32l;
    // 0x8007A7D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007A7D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007A7DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A7E0: b           L_8007A810
    // 0x8007A7E4: swc1        $f10, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->f10.u32l;
        goto L_8007A810;
    // 0x8007A7E4: swc1        $f10, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->f10.u32l;
L_8007A7E8:
    // 0x8007A7E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A7EC: sw          $t8, 0x6710($at)
    MEM_W(0X6710, ctx->r1) = ctx->r24;
    // 0x8007A7F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007A7F4: lwc1        $f16, -0x7F68($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7F68);
    // 0x8007A7F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A7FC: swc1        $f16, 0x6714($at)
    MEM_W(0X6714, ctx->r1) = ctx->f16.u32l;
    // 0x8007A800: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007A804: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007A808: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A80C: swc1        $f18, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->f18.u32l;
L_8007A810:
    // 0x8007A810: bne         $v0, $zero, L_8007A85C
    if (ctx->r2 != 0) {
        // 0x8007A814: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8007A85C;
    }
    // 0x8007A814: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007A818: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007A81C: addiu       $v0, $v0, -0x1304
    ctx->r2 = ADD32(ctx->r2, -0X1304);
    // 0x8007A820: addiu       $v1, $v1, -0x12C4
    ctx->r3 = ADD32(ctx->r3, -0X12C4);
L_8007A824:
    // 0x8007A824: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x8007A828: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x8007A82C: lw          $t5, 0x1C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1C);
    // 0x8007A830: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8007A834: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8007A838: addiu       $t2, $t1, 0x18
    ctx->r10 = ADD32(ctx->r9, 0X18);
    // 0x8007A83C: addiu       $t4, $t3, 0x18
    ctx->r12 = ADD32(ctx->r11, 0X18);
    // 0x8007A840: addiu       $t6, $t5, 0x18
    ctx->r14 = ADD32(ctx->r13, 0X18);
    // 0x8007A844: addiu       $t0, $t9, 0x18
    ctx->r8 = ADD32(ctx->r25, 0X18);
    // 0x8007A848: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x8007A84C: sw          $t4, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r12;
    // 0x8007A850: sw          $t2, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->r10;
    // 0x8007A854: bne         $v0, $v1, L_8007A824
    if (ctx->r2 != ctx->r3) {
        // 0x8007A858: sw          $t0, -0x1C($v0)
        MEM_W(-0X1C, ctx->r2) = ctx->r8;
            goto L_8007A824;
    }
    // 0x8007A858: sw          $t0, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = ctx->r8;
L_8007A85C:
    // 0x8007A85C: jal         0x8007ADC4
    // 0x8007A860: nop

    video_delta_reset(rdram, ctx);
        goto after_0;
    // 0x8007A860: nop

    after_0:
    // 0x8007A864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007A868: jal         0x8007A910
    // 0x8007A86C: nop

    fb_mode_set(rdram, ctx);
        goto after_1;
    // 0x8007A86C: nop

    after_1:
    // 0x8007A870: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007A874: addiu       $v0, $v0, 0x6860
    ctx->r2 = ADD32(ctx->r2, 0X6860);
    // 0x8007A878: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8007A87C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007A880: jal         0x8007AC38
    // 0x8007A884: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    fb_alloc(rdram, ctx);
        goto after_2;
    // 0x8007A884: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8007A888: jal         0x8007AC38
    // 0x8007A88C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    fb_alloc(rdram, ctx);
        goto after_3;
    // 0x8007A88C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8007A890: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007A894: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A898: jal         0x8007AFEC
    // 0x8007A89C: sw          $t7, 0x6868($at)
    MEM_W(0X6868, ctx->r1) = ctx->r15;
    fb_swap(rdram, ctx);
        goto after_4;
    // 0x8007A89C: sw          $t7, 0x6868($at)
    MEM_W(0X6868, ctx->r1) = ctx->r15;
    after_4:
    // 0x8007A8A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007A8A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007A8A8: addiu       $a1, $a1, 0x6720
    ctx->r5 = ADD32(ctx->r5, 0X6720);
    // 0x8007A8AC: addiu       $a0, $a0, 0x6740
    ctx->r4 = ADD32(ctx->r4, 0X6740);
    // 0x8007A8B0: jal         0x800C8D80
    // 0x8007A8B4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_5;
    // 0x8007A8B4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x8007A8B8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A8BC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007A8C0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007A8C4: addiu       $a2, $a2, 0x6740
    ctx->r6 = ADD32(ctx->r6, 0X6740);
    // 0x8007A8C8: addiu       $a1, $a1, 0x68B0
    ctx->r5 = ADD32(ctx->r5, 0X68B0);
    // 0x8007A8CC: jal         0x800798D0
    // 0x8007A8D0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    osScAddClient(rdram, ctx);
        goto after_6;
    // 0x8007A8D0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_6:
    // 0x8007A8D4: jal         0x8007A9A0
    // 0x8007A8D8: nop

    fb_init_vi(rdram, ctx);
        goto after_7;
    // 0x8007A8D8: nop

    after_7:
    // 0x8007A8DC: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8007A8E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A8E4: sw          $t8, 0x6870($at)
    MEM_W(0X6870, ctx->r1) = ctx->r24;
    // 0x8007A8E8: jal         0x800D2270
    // 0x8007A8EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_8;
    // 0x8007A8EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x8007A8F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A8F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A8F8: sb          $zero, 0x68A8($at)
    MEM_B(0X68A8, ctx->r1) = 0;
    // 0x8007A8FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A900: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8007A904: sb          $t9, 0x6884($at)
    MEM_B(0X6884, ctx->r1) = ctx->r25;
    // 0x8007A908: jr          $ra
    // 0x8007A90C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007A90C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void cinematic_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B114: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009B118: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009B11C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009B120: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009B124: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8009B128: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8009B12C: blez        $a1, L_8009B160
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8009B130: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8009B160;
    }
    // 0x8009B130: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009B134: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009B138:
    // 0x8009B138: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
    // 0x8009B13C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009B140: beq         $v0, $t6, L_8009B158
    if (ctx->r2 == ctx->r14) {
        // 0x8009B144: nop
    
            goto L_8009B158;
    }
    // 0x8009B144: nop

L_8009B148:
    // 0x8009B148: lb          $t7, 0x3($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X3);
    // 0x8009B14C: addiu       $s0, $s0, 0x3
    ctx->r16 = ADD32(ctx->r16, 0X3);
    // 0x8009B150: bne         $v0, $t7, L_8009B148
    if (ctx->r2 != ctx->r15) {
        // 0x8009B154: nop
    
            goto L_8009B148;
    }
    // 0x8009B154: nop

L_8009B158:
    // 0x8009B158: bne         $v1, $a1, L_8009B138
    if (ctx->r3 != ctx->r5) {
        // 0x8009B15C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8009B138;
    }
    // 0x8009B15C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8009B160:
    // 0x8009B160: bne         $v1, $zero, L_8009B184
    if (ctx->r3 != 0) {
        // 0x8009B164: nop
    
            goto L_8009B184;
    }
    // 0x8009B164: nop

    // 0x8009B168: jal         0x8001E2D0
    // 0x8009B16C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8009B16C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_0:
    // 0x8009B170: bne         $v0, $s0, L_8009B184
    if (ctx->r2 != ctx->r16) {
        // 0x8009B174: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8009B184;
    }
    // 0x8009B174: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009B178: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B17C: b           L_8009B18C
    // 0x8009B180: sw          $t8, 0x6DEC($at)
    MEM_W(0X6DEC, ctx->r1) = ctx->r24;
        goto L_8009B18C;
    // 0x8009B180: sw          $t8, 0x6DEC($at)
    MEM_W(0X6DEC, ctx->r1) = ctx->r24;
L_8009B184:
    // 0x8009B184: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B188: sw          $zero, 0x6DEC($at)
    MEM_W(0X6DEC, ctx->r1) = 0;
L_8009B18C:
    // 0x8009B18C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B190: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8009B194: sw          $s0, 0x6D8C($at)
    MEM_W(0X6D8C, ctx->r1) = ctx->r16;
    // 0x8009B198: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B19C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8009B1A0: sw          $t9, 0x6DC4($at)
    MEM_W(0X6DC4, ctx->r1) = ctx->r25;
    // 0x8009B1A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B1A8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8009B1AC: sw          $t0, 0x6DDC($at)
    MEM_W(0X6DDC, ctx->r1) = ctx->r8;
    // 0x8009B1B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B1B4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8009B1B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B1BC: sw          $t1, 0x6DE4($at)
    MEM_W(0X6DE4, ctx->r1) = ctx->r9;
    // 0x8009B1C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B1C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009B1C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009B1CC: jr          $ra
    // 0x8009B1D0: sw          $t2, 0x6DA4($at)
    MEM_W(0X6DA4, ctx->r1) = ctx->r10;
    return;
    // 0x8009B1D0: sw          $t2, 0x6DA4($at)
    MEM_W(0X6DA4, ctx->r1) = ctx->r10;
;}
RECOMP_FUNC void alMainBusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC8F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CC8F4: bne         $a1, $at, L_800CC918
    if (ctx->r5 != ctx->r1) {
        // 0x800CC8F8: lw          $v0, 0x1C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1C);
            goto L_800CC918;
    }
    // 0x800CC8F8: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800CC8FC: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x800CC900: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800CC904: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800CC908: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x800CC90C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x800CC910: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800CC914: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_800CC918:
    // 0x800CC918: jr          $ra
    // 0x800CC91C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CC91C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void obj_init_setuppoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800391D0: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x800391D4: nop

    // 0x800391D8: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    // 0x800391DC: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x800391E0: nop

    // 0x800391E4: sw          $t7, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r15;
    // 0x800391E8: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x800391EC: nop

    // 0x800391F0: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x800391F4: jr          $ra
    // 0x800391F8: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    return;
    // 0x800391F8: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void func_800159C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800159C8: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800159CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800159D0: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800159D4: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800159D8: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800159DC: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800159E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800159E4: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800159E8: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800159EC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800159F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800159F4: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800159F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800159FC: lwc1        $f6, -0x4CD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4CD8);
    // 0x80015A00: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80015A04: lw          $a2, 0x4C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X4C);
    // 0x80015A08: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80015A0C: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x80015A10: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80015A14: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80015A18: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x80015A1C: lbu         $v0, 0x11($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X11);
    // 0x80015A20: nop

    // 0x80015A24: bne         $t1, $v0, L_80015A90
    if (ctx->r9 != ctx->r2) {
        // 0x80015A28: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80015A90;
    }
    // 0x80015A28: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80015A2C: lb          $t9, 0x16($a2)
    ctx->r25 = MEM_B(ctx->r6, 0X16);
    // 0x80015A30: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80015A34: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80015A38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80015A3C: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80015A40: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80015A44: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80015A48: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80015A4C: nop

    // 0x80015A50: bc1t        L_80016528
    if (c1cs) {
        // 0x80015A54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80015A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015A58: lb          $t2, 0x17($a2)
    ctx->r10 = MEM_B(ctx->r6, 0X17);
    // 0x80015A5C: nop

    // 0x80015A60: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80015A64: nop

    // 0x80015A68: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80015A6C: mul.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80015A70: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80015A74: nop

    // 0x80015A78: bc1t        L_80016528
    if (c1cs) {
        // 0x80015A7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80015A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015A80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80015A84: nop

    // 0x80015A88: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80015A8C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_80015A90:
    // 0x80015A90: bne         $v0, $at, L_80015AC4
    if (ctx->r2 != ctx->r1) {
        // 0x80015A94: nop
    
            goto L_80015AC4;
    }
    // 0x80015A94: nop

    // 0x80015A98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80015A9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80015AA0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80015AA4: nop

    // 0x80015AA8: bc1f        L_80015AC4
    if (!c1cs) {
        // 0x80015AAC: nop
    
            goto L_80015AC4;
    }
    // 0x80015AAC: nop

    // 0x80015AB0: lwc1        $f5, 0x5B48($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5B48);
    // 0x80015AB4: lwc1        $f4, 0x5B4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B4C);
    // 0x80015AB8: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80015ABC: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80015AC0: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_80015AC4:
    // 0x80015AC4: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80015AC8: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80015ACC: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x80015AD0: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80015AD4: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80015AD8: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80015ADC: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80015AE0: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x80015AE4: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80015AE8: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80015AEC: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x80015AF0: jal         0x800CA030
    // 0x80015AF4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80015AF4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80015AF8: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x80015AFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80015B00: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80015B04: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80015B08: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80015B0C: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x80015B10: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80015B14: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80015B18: bc1t        L_80016524
    if (c1cs) {
        // 0x80015B1C: mov.s       $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
            goto L_80016524;
    }
    // 0x80015B1C: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80015B20: lui         $at, 0xC57A
    ctx->r1 = S32(0XC57A << 16);
    // 0x80015B24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80015B28: nop

    // 0x80015B2C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80015B30: nop

    // 0x80015B34: bc1t        L_80016528
    if (c1cs) {
        // 0x80015B38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80015B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015B3C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80015B40: lh          $t6, 0x14($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X14);
    // 0x80015B44: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80015B48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80015B4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80015B50: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x80015B54: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80015B58: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x80015B5C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80015B60: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80015B64: nop

    // 0x80015B68: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80015B6C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80015B70: nop

    // 0x80015B74: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80015B78: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80015B7C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80015B80: nop

    // 0x80015B84: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80015B88: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80015B8C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80015B90: beq         $t7, $zero, L_80015B9C
    if (ctx->r15 == 0) {
        // 0x80015B94: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80015B9C;
    }
    // 0x80015B94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80015B98: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
L_80015B9C:
    // 0x80015B9C: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80015BA0: bne         $at, $zero, L_80015BAC
    if (ctx->r1 != 0) {
        // 0x80015BA4: nop
    
            goto L_80015BAC;
    }
    // 0x80015BA4: nop

    // 0x80015BA8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80015BAC:
    // 0x80015BAC: lbu         $t8, 0x13($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X13);
    // 0x80015BB0: nop

    // 0x80015BB4: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015BB8: bne         $at, $zero, L_80015BC8
    if (ctx->r1 != 0) {
        // 0x80015BBC: nop
    
            goto L_80015BC8;
    }
    // 0x80015BBC: nop

    // 0x80015BC0: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x80015BC4: sb          $v0, 0x13($t0)
    MEM_B(0X13, ctx->r8) = ctx->r2;
L_80015BC8:
    // 0x80015BC8: lh          $a1, 0x14($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X14);
    // 0x80015BCC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80015BD0: andi        $t9, $a1, 0x20
    ctx->r25 = ctx->r5 & 0X20;
    // 0x80015BD4: beq         $t9, $zero, L_80015BE4
    if (ctx->r25 == 0) {
        // 0x80015BD8: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_80015BE4;
    }
    // 0x80015BD8: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80015BDC: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80015BE0: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
L_80015BE4:
    // 0x80015BE4: bne         $at, $zero, L_80015BF0
    if (ctx->r1 != 0) {
        // 0x80015BE8: nop
    
            goto L_80015BF0;
    }
    // 0x80015BE8: nop

    // 0x80015BEC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80015BF0:
    // 0x80015BF0: lbu         $t2, 0x13($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X13);
    // 0x80015BF4: nop

    // 0x80015BF8: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015BFC: bne         $at, $zero, L_80015C14
    if (ctx->r1 != 0) {
        // 0x80015C00: andi        $t4, $a1, 0x1
        ctx->r12 = ctx->r5 & 0X1;
            goto L_80015C14;
    }
    // 0x80015C00: andi        $t4, $a1, 0x1
    ctx->r12 = ctx->r5 & 0X1;
    // 0x80015C04: lh          $a1, 0x14($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X14);
    // 0x80015C08: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x80015C0C: sb          $v0, 0x13($a2)
    MEM_B(0X13, ctx->r6) = ctx->r2;
    // 0x80015C10: andi        $t4, $a1, 0x1
    ctx->r12 = ctx->r5 & 0X1;
L_80015C14:
    // 0x80015C14: beq         $t4, $zero, L_80016528
    if (ctx->r12 == 0) {
        // 0x80015C18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80015C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015C1C: lb          $t3, 0x10($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X10);
    // 0x80015C20: lb          $t5, 0x10($t0)
    ctx->r13 = MEM_B(ctx->r8, 0X10);
    // 0x80015C24: nop

    // 0x80015C28: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80015C2C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80015C30: nop

    // 0x80015C34: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80015C38: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    // 0x80015C3C: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80015C40: nop

    // 0x80015C44: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80015C48: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80015C4C: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80015C50: nop

    // 0x80015C54: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80015C58: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x80015C5C: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80015C60: nop

    // 0x80015C64: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80015C68: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80015C6C: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80015C70: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80015C74: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80015C78: sub.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80015C7C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80015C80: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80015C84: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80015C88: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80015C8C: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x80015C90: lbu         $t7, 0x11($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X11);
    // 0x80015C94: mul.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80015C98: bne         $t1, $t7, L_80015CA8
    if (ctx->r9 != ctx->r15) {
        // 0x80015C9C: nop
    
            goto L_80015CA8;
    }
    // 0x80015C9C: nop

    // 0x80015CA0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80015CA4: nop

L_80015CA8:
    // 0x80015CA8: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80015CAC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80015CB0: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80015CB4: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80015CB8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80015CBC: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80015CC0: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80015CC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80015CC8: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x80015CCC: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80015CD0: nop

    // 0x80015CD4: bc1f        L_80015E10
    if (!c1cs) {
        // 0x80015CD8: nop
    
            goto L_80015E10;
    }
    // 0x80015CD8: nop

    // 0x80015CDC: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80015CE0: lwc1        $f18, 0xC($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80015CE4: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80015CE8: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80015CEC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80015CF0: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x80015CF4: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80015CF8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80015CFC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80015D00: mul.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80015D04: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80015D08: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80015D0C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80015D10: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80015D14: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80015D18: mul.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80015D1C: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80015D20: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80015D24: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80015D28: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80015D2C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80015D30: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80015D34: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80015D38: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80015D3C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80015D40: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80015D44: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80015D48: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x80015D4C: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80015D50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80015D54: div.s       $f2, $f6, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80015D58: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x80015D5C: nop

    // 0x80015D60: bc1f        L_80015E10
    if (!c1cs) {
        // 0x80015D64: nop
    
            goto L_80015E10;
    }
    // 0x80015D64: nop

    // 0x80015D68: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80015D6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80015D70: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80015D74: c.le.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d <= ctx->f6.d;
    // 0x80015D78: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80015D7C: bc1f        L_80015E10
    if (!c1cs) {
        // 0x80015D80: swc1        $f12, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->f12.u32l;
            goto L_80015E10;
    }
    // 0x80015D80: swc1        $f12, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f12.u32l;
    // 0x80015D84: mul.s       $f4, $f2, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80015D88: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80015D8C: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80015D90: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80015D94: mul.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80015D98: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80015D9C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80015DA0: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x80015DA4: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80015DA8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80015DAC: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80015DB0: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80015DB4: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x80015DB8: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80015DBC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80015DC0: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80015DC4: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80015DC8: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80015DCC: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80015DD0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80015DD4: sub.s       $f14, $f18, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80015DD8: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x80015DDC: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80015DE0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80015DE4: sub.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80015DE8: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80015DEC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80015DF0: jal         0x800CA030
    // 0x80015DF4: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80015DF4: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_1:
    // 0x80015DF8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80015DFC: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80015E00: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x80015E04: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80015E08: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80015E0C: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
L_80015E10:
    // 0x80015E10: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80015E14: nop

    // 0x80015E18: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80015E1C: nop

    // 0x80015E20: bc1f        L_80016528
    if (!c1cs) {
        // 0x80015E24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80015E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015E28: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80015E2C: nop

    // 0x80015E30: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80015E34: nop

    // 0x80015E38: bc1f        L_80016528
    if (!c1cs) {
        // 0x80015E3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80015E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015E40: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80015E44: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80015E48: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80015E4C: sub.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80015E50: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80015E54: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80015E58: lwc1        $f8, 0xC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80015E5C: lbu         $t8, 0x11($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X11);
    // 0x80015E60: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80015E64: bne         $t1, $t8, L_80015E74
    if (ctx->r9 != ctx->r24) {
        // 0x80015E68: sub.s       $f14, $f8, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
            goto L_80015E74;
    }
    // 0x80015E68: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80015E6C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80015E70: nop

L_80015E74:
    // 0x80015E74: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80015E78: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80015E7C: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x80015E80: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80015E84: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80015E88: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80015E8C: swc1        $f2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f2.u32l;
    // 0x80015E90: swc1        $f14, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f14.u32l;
    // 0x80015E94: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80015E98: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80015E9C: swc1        $f16, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f16.u32l;
    // 0x80015EA0: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x80015EA4: jal         0x800CA030
    // 0x80015EA8: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80015EA8: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_2:
    // 0x80015EAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80015EB0: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80015EB4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80015EB8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80015EBC: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x80015EC0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80015EC4: lwc1        $f2, 0x8C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80015EC8: lwc1        $f14, 0x84($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80015ECC: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80015ED0: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80015ED4: bc1f        L_80015EFC
    if (!c1cs) {
        // 0x80015ED8: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80015EFC;
    }
    // 0x80015ED8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80015EDC: nop

    // 0x80015EE0: div.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80015EE4: nop

    // 0x80015EE8: div.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80015EEC: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x80015EF0: div.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80015EF4: b           L_80015F20
    // 0x80015EF8: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
        goto L_80015F20;
    // 0x80015EF8: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
L_80015EFC:
    // 0x80015EFC: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80015F00: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80015F04: div.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80015F08: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80015F0C: div.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80015F10: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x80015F14: div.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80015F18: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x80015F1C: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
L_80015F20:
    // 0x80015F20: sub.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80015F24: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80015F28: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80015F2C: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x80015F30: nop

    // 0x80015F34: bc1f        L_80015F40
    if (!c1cs) {
        // 0x80015F38: nop
    
            goto L_80015F40;
    }
    // 0x80015F38: nop

    // 0x80015F3C: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
L_80015F40:
    // 0x80015F40: mul.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80015F44: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80015F48: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80015F4C: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80015F50: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80015F54: nop

    // 0x80015F58: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80015F5C: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x80015F60: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x80015F64: lh          $t9, 0x14($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X14);
    // 0x80015F68: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80015F6C: ori         $t2, $t9, 0x8
    ctx->r10 = ctx->r25 | 0X8;
    // 0x80015F70: sh          $t2, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r10;
    // 0x80015F74: lh          $t4, 0x14($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X14);
    // 0x80015F78: lbu         $t5, 0x12($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X12);
    // 0x80015F7C: ori         $t3, $t4, 0x8
    ctx->r11 = ctx->r12 | 0X8;
    // 0x80015F80: bne         $t5, $zero, L_8001629C
    if (ctx->r13 != 0) {
        // 0x80015F84: sh          $t3, 0x14($a2)
        MEM_H(0X14, ctx->r6) = ctx->r11;
            goto L_8001629C;
    }
    // 0x80015F84: sh          $t3, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r11;
    // 0x80015F88: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80015F8C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80015F90: sub.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80015F94: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x80015F98: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80015F9C: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80015FA0: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80015FA4: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x80015FA8: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80015FAC: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80015FB0: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80015FB4: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x80015FB8: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80015FBC: nop

    // 0x80015FC0: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80015FC4: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x80015FC8: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x80015FCC: nop

    // 0x80015FD0: bne         $t1, $t6, L_80016528
    if (ctx->r9 != ctx->r14) {
        // 0x80015FD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80015FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015FD8: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x80015FDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80015FE0: lb          $t7, 0x1D6($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1D6);
    // 0x80015FE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80015FE8: bne         $t1, $t7, L_80016150
    if (ctx->r9 != ctx->r15) {
        // 0x80015FEC: nop
    
            goto L_80016150;
    }
    // 0x80015FEC: nop

    // 0x80015FF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80015FF4: lwc1        $f5, 0x5B50($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5B50);
    // 0x80015FF8: lwc1        $f4, 0x5B54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B54);
    // 0x80015FFC: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80016000: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80016004: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80016008: bc1f        L_80016274
    if (!c1cs) {
        // 0x8001600C: nop
    
            goto L_80016274;
    }
    // 0x8001600C: nop

    // 0x80016010: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80016014: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80016018: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001601C: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x80016020: nop

    // 0x80016024: bc1f        L_80016030
    if (!c1cs) {
        // 0x80016028: nop
    
            goto L_80016030;
    }
    // 0x80016028: nop

    // 0x8001602C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80016030:
    // 0x80016030: beq         $v0, $zero, L_8001606C
    if (ctx->r2 == 0) {
        // 0x80016034: nop
    
            goto L_8001606C;
    }
    // 0x80016034: nop

    // 0x80016038: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8001603C: lwc1        $f1, 0x5B58($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X5B58);
    // 0x80016040: lwc1        $f0, 0x5B5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B5C);
    // 0x80016044: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80016048: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8001604C: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80016050: nop

    // 0x80016054: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80016058: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8001605C: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80016060: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x80016064: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80016068: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
L_8001606C:
    // 0x8001606C: beq         $v0, $zero, L_80016274
    if (ctx->r2 == 0) {
        // 0x80016070: nop
    
            goto L_80016274;
    }
    // 0x80016070: nop

    // 0x80016074: lh          $t8, 0x14($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X14);
    // 0x80016078: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8001607C: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x80016080: sh          $t9, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r25;
    // 0x80016084: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80016088: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8001608C: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80016090: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80016094: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80016098: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8001609C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800160A0: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800160A4: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800160A8: lwc1        $f10, 0x14($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800160AC: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800160B0: sb          $t2, 0x1D2($a1)
    MEM_B(0X1D2, ctx->r5) = ctx->r10;
    // 0x800160B4: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800160B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800160BC: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800160C0: sub.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800160C4: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x800160C8: nop

    // 0x800160CC: bc1f        L_80016114
    if (!c1cs) {
        // 0x800160D0: nop
    
            goto L_80016114;
    }
    // 0x800160D0: nop

    // 0x800160D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800160D8: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800160DC: lwc1        $f1, 0x5B60($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X5B60);
    // 0x800160E0: lwc1        $f0, 0x5B64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B64);
    // 0x800160E4: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800160E8: mul.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800160EC: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800160F0: swc1        $f10, 0x120($a1)
    MEM_W(0X120, ctx->r5) = ctx->f10.u32l;
    // 0x800160F4: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800160F8: nop

    // 0x800160FC: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x80016100: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80016104: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x80016108: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8001610C: b           L_80016274
    // 0x80016110: swc1        $f4, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f4.u32l;
        goto L_80016274;
    // 0x80016110: swc1        $f4, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f4.u32l;
L_80016114:
    // 0x80016114: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80016118: lwc1        $f1, 0x5B68($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X5B68);
    // 0x8001611C: lwc1        $f0, 0x5B6C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B6C);
    // 0x80016120: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x80016124: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80016128: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8001612C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80016130: swc1        $f8, 0x120($a1)
    MEM_W(0X120, ctx->r5) = ctx->f8.u32l;
    // 0x80016134: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80016138: nop

    // 0x8001613C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80016140: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80016144: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80016148: b           L_80016274
    // 0x8001614C: swc1        $f8, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f8.u32l;
        goto L_80016274;
    // 0x8001614C: swc1        $f8, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f8.u32l;
L_80016150:
    // 0x80016150: lwc1        $f7, 0x5B70($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5B70);
    // 0x80016154: lwc1        $f6, 0x5B74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5B74);
    // 0x80016158: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x8001615C: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x80016160: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80016164: bc1f        L_800161C8
    if (!c1cs) {
        // 0x80016168: nop
    
            goto L_800161C8;
    }
    // 0x80016168: nop

    // 0x8001616C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80016170: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80016174: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80016178: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x8001617C: nop

    // 0x80016180: bc1f        L_8001618C
    if (!c1cs) {
        // 0x80016184: nop
    
            goto L_8001618C;
    }
    // 0x80016184: nop

    // 0x80016188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001618C:
    // 0x8001618C: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80016190: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80016194: sub.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80016198: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001619C: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x800161A0: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800161A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800161A8: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800161AC: mul.d       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f8.d);
    // 0x800161B0: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x800161B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800161B8: nop

    // 0x800161BC: swc1        $f4, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f4.u32l;
    // 0x800161C0: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800161C4: swc1        $f10, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f10.u32l;
L_800161C8:
    // 0x800161C8: beq         $v0, $zero, L_80016274
    if (ctx->r2 == 0) {
        // 0x800161CC: nop
    
            goto L_80016274;
    }
    // 0x800161CC: nop

    // 0x800161D0: lh          $t4, 0x14($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X14);
    // 0x800161D4: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800161D8: ori         $t3, $t4, 0x40
    ctx->r11 = ctx->r12 | 0X40;
    // 0x800161DC: sh          $t3, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r11;
    // 0x800161E0: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800161E4: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800161E8: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800161EC: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800161F0: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800161F4: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800161F8: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800161FC: sub.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80016200: lwc1        $f6, 0x14($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80016204: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80016208: nop

    // 0x8001620C: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80016210: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80016214: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80016218: sub.s       $f2, $f8, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8001621C: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x80016220: nop

    // 0x80016224: bc1f        L_8001623C
    if (!c1cs) {
        // 0x80016228: nop
    
            goto L_8001623C;
    }
    // 0x80016228: nop

    // 0x8001622C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80016230: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80016234: b           L_80016248
    // 0x80016238: lwc1        $f10, 0x50($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X50);
        goto L_80016248;
    // 0x80016238: lwc1        $f10, 0x50($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X50);
L_8001623C:
    // 0x8001623C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80016240: nop

    // 0x80016244: lwc1        $f10, 0x50($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X50);
L_80016248:
    // 0x80016248: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8001624C: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80016250: lwc1        $f6, 0x58($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X58);
    // 0x80016254: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80016258: sb          $t5, 0x1D2($a1)
    MEM_B(0X1D2, ctx->r5) = ctx->r13;
    // 0x8001625C: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80016260: nop

    // 0x80016264: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80016268: swc1        $f8, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f8.u32l;
    // 0x8001626C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80016270: swc1        $f4, 0x120($a1)
    MEM_W(0X120, ctx->r5) = ctx->f4.u32l;
L_80016274:
    // 0x80016274: beq         $v0, $zero, L_80016528
    if (ctx->r2 == 0) {
        // 0x80016278: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80016278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001627C: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80016280: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80016284: beq         $t6, $at, L_80016528
    if (ctx->r14 == ctx->r1) {
        // 0x80016288: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80016288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001628C: jal         0x80016534
    // 0x80016290: nop

    func_80016500(rdram, ctx);
        goto after_3;
    // 0x80016290: nop

    after_3:
    // 0x80016294: b           L_80016528
    // 0x80016298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80016528;
    // 0x80016298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001629C:
    // 0x8001629C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x800162A0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800162A4: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x800162A8: mul.d       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x800162AC: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800162B0: nop

    // 0x800162B4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800162B8: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800162BC: mul.d       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x800162C0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x800162C4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800162C8: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x800162CC: mul.d       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x800162D0: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x800162D4: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x800162D8: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x800162DC: lbu         $t7, 0x12($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X12);
    // 0x800162E0: nop

    // 0x800162E4: beq         $t7, $zero, L_8001631C
    if (ctx->r15 == 0) {
        // 0x800162E8: nop
    
            goto L_8001631C;
    }
    // 0x800162E8: nop

    // 0x800162EC: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800162F0: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800162F4: sub.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800162F8: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x800162FC: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80016300: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80016304: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80016308: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x8001630C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80016310: nop

    // 0x80016314: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80016318: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
L_8001631C:
    // 0x8001631C: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80016320: lwc1        $f8, 0x10($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80016324: add.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80016328: swc1        $f4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f4.u32l;
    // 0x8001632C: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80016330: lwc1        $f4, 0x14($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80016334: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80016338: swc1        $f10, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f10.u32l;
    // 0x8001633C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80016340: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80016344: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80016348: swc1        $f6, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f6.u32l;
    // 0x8001634C: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80016350: nop

    // 0x80016354: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80016358: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x8001635C: lh          $t8, 0x48($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X48);
    // 0x80016360: nop

    // 0x80016364: bne         $t1, $t8, L_80016528
    if (ctx->r9 != ctx->r24) {
        // 0x80016368: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80016368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001636C: lh          $t9, 0x48($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X48);
    // 0x80016370: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80016374: bne         $t1, $t9, L_80016528
    if (ctx->r9 != ctx->r25) {
        // 0x80016378: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80016378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001637C: lbu         $t2, 0x12($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X12);
    // 0x80016380: lbu         $t4, 0x12($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X12);
    // 0x80016384: lwc1        $f5, 0x5B78($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5B78);
    // 0x80016388: subu        $t3, $t2, $t4
    ctx->r11 = SUB32(ctx->r10, ctx->r12);
    // 0x8001638C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80016390: lwc1        $f4, 0x5B7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B7C);
    // 0x80016394: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80016398: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x8001639C: lw          $t5, 0x64($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X64);
    // 0x800163A0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800163A4: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800163A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800163AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800163B0: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800163B4: lb          $v0, 0x189($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X189);
    // 0x800163B8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800163BC: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x800163C0: beq         $v0, $zero, L_800163DC
    if (ctx->r2 == 0) {
        // 0x800163C4: cvt.s.d     $f14, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
            goto L_800163DC;
    }
    // 0x800163C4: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x800163C8: lb          $t7, 0x189($t5)
    ctx->r15 = MEM_B(ctx->r13, 0X189);
    // 0x800163CC: nop

    // 0x800163D0: bne         $t7, $zero, L_800163E0
    if (ctx->r15 != 0) {
        // 0x800163D4: lw          $t8, 0x4C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X4C);
            goto L_800163E0;
    }
    // 0x800163D4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800163D8: sb          $v0, 0x1DB($t5)
    MEM_B(0X1DB, ctx->r13) = ctx->r2;
L_800163DC:
    // 0x800163DC: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_800163E0:
    // 0x800163E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800163E4: lb          $v0, 0x189($t8)
    ctx->r2 = MEM_B(ctx->r24, 0X189);
    // 0x800163E8: nop

    // 0x800163EC: beq         $v0, $zero, L_80016408
    if (ctx->r2 == 0) {
        // 0x800163F0: nop
    
            goto L_80016408;
    }
    // 0x800163F0: nop

    // 0x800163F4: lb          $t9, 0x189($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X189);
    // 0x800163F8: nop

    // 0x800163FC: bne         $t9, $zero, L_80016408
    if (ctx->r25 != 0) {
        // 0x80016400: nop
    
            goto L_80016408;
    }
    // 0x80016400: nop

    // 0x80016404: sb          $v0, 0x1DB($a1)
    MEM_B(0X1DB, ctx->r5) = ctx->r2;
L_80016408:
    // 0x80016408: lb          $t2, 0x1D6($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X1D6);
    // 0x8001640C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016410: bne         $t1, $t2, L_80016424
    if (ctx->r9 != ctx->r10) {
        // 0x80016414: nop
    
            goto L_80016424;
    }
    // 0x80016414: nop

    // 0x80016418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001641C: b           L_80016470
    // 0x80016420: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
        goto L_80016470;
    // 0x80016420: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
L_80016424:
    // 0x80016424: lwc1        $f1, 0x5B80($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X5B80);
    // 0x80016428: lwc1        $f0, 0x5B84($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B84);
    // 0x8001642C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80016430: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x80016434: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x80016438: bc1f        L_80016470
    if (!c1cs) {
        // 0x8001643C: nop
    
            goto L_80016470;
    }
    // 0x8001643C: nop

    // 0x80016440: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80016444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80016448: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8001644C: mul.d       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x80016450: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80016454: nop

    // 0x80016458: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8001645C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80016460: mul.d       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x80016464: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x80016468: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8001646C: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
L_80016470:
    // 0x80016470: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80016474: beq         $v0, $zero, L_80016528
    if (ctx->r2 == 0) {
        // 0x80016478: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80016478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001647C: lbu         $t4, 0x12($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X12);
    // 0x80016480: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80016484: beq         $t4, $zero, L_800164EC
    if (ctx->r12 == 0) {
        // 0x80016488: nop
    
            goto L_800164EC;
    }
    // 0x80016488: nop

    // 0x8001648C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80016490: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80016494: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x80016498: sub.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d - ctx->f8.d;
    // 0x8001649C: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x800164A0: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800164A4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x800164A8: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800164AC: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800164B0: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800164B4: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800164B8: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x800164BC: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800164C0: nop

    // 0x800164C4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800164C8: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800164CC: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x800164D0: swc1        $f14, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f14.u32l;
    // 0x800164D4: jal         0x80016534
    // 0x800164D8: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    func_80016500(rdram, ctx);
        goto after_4;
    // 0x800164D8: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    after_4:
    // 0x800164DC: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x800164E0: lwc1        $f14, 0x90($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800164E4: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800164E8: nop

L_800164EC:
    // 0x800164EC: mul.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800164F0: lwc1        $f6, 0x1C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x800164F4: lwc1        $f4, 0x24($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X24);
    // 0x800164F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800164FC: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80016500: swc1        $f8, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f8.u32l;
    // 0x80016504: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80016508: nop

    // 0x8001650C: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80016510: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80016514: swc1        $f8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f8.u32l;
    // 0x80016518: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8001651C: jal         0x80016534
    // 0x80016520: nop

    func_80016500(rdram, ctx);
        goto after_5;
    // 0x80016520: nop

    after_5:
L_80016524:
    // 0x80016524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80016528:
    // 0x80016528: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x8001652C: jr          $ra
    // 0x80016530: nop

    return;
    // 0x80016530: nop

;}
RECOMP_FUNC void render_3d_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800120C8: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800120CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800120D0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800120D4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800120D8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800120DC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800120E0: lb          $t7, 0x3A($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3A);
    // 0x800120E4: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x800120E8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800120EC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800120F0: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x800120F4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800120F8: beq         $s0, $zero, L_80012C14
    if (ctx->r16 == 0) {
        // 0x800120FC: addiu       $t7, $zero, 0xFF
        ctx->r15 = ADD32(0, 0XFF);
            goto L_80012C14;
    }
    // 0x800120FC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80012100: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80012104: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x80012108: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
    // 0x8001210C: sw          $t7, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r15;
    // 0x80012110: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x80012114: lw          $v1, 0x54($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X54);
    // 0x80012118: nop

    // 0x8001211C: beq         $v1, $zero, L_8001217C
    if (ctx->r3 == 0) {
        // 0x80012120: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_8001217C;
    }
    // 0x80012120: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80012124: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80012128: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001212C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80012130: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80012134: addiu       $s1, $s1, -0x4D50
    ctx->r17 = ADD32(ctx->r17, -0X4D50);
    // 0x80012138: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8001213C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80012140: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80012144: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80012148: sw          $t9, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r25;
    // 0x8001214C: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    // 0x80012150: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80012154: nop

    // 0x80012158: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001215C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80012160: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80012164: nop

    // 0x80012168: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001216C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80012170: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80012174: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x80012178: nop

L_8001217C:
    // 0x8001217C: lh          $t7, 0x48($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X48);
    // 0x80012180: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80012184: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012188: bne         $t7, $at, L_800121A4
    if (ctx->r15 != ctx->r1) {
        // 0x8001218C: addiu       $s1, $s1, -0x4D50
        ctx->r17 = ADD32(ctx->r17, -0X4D50);
            goto L_800121A4;
    }
    // 0x8001218C: addiu       $s1, $s1, -0x4D50
    ctx->r17 = ADD32(ctx->r17, -0X4D50);
    // 0x80012190: lw          $s3, 0x64($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X64);
    // 0x80012194: jal         0x80012E28
    // 0x80012198: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    object_do_player_tumble(rdram, ctx);
        goto after_0;
    // 0x80012198: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x8001219C: b           L_800121AC
    // 0x800121A0: lb          $t6, 0x20($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X20);
        goto L_800121AC;
    // 0x800121A0: lb          $t6, 0x20($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X20);
L_800121A4:
    // 0x800121A4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800121A8: lb          $t6, 0x20($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X20);
L_800121AC:
    // 0x800121AC: nop

    // 0x800121B0: bgtz        $t6, L_800122FC
    if (SIGNED(ctx->r14) > 0) {
        // 0x800121B4: nop
    
            goto L_800122FC;
    }
    // 0x800121B4: nop

    // 0x800121B8: lb          $t8, 0x1F($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1F);
    // 0x800121BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800121C0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800121C4: addu        $t5, $s0, $t9
    ctx->r13 = ADD32(ctx->r16, ctx->r25);
    // 0x800121C8: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x800121CC: nop

    // 0x800121D0: sw          $t7, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r15;
    // 0x800121D4: lb          $v1, 0x1E($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E);
    // 0x800121D8: nop

    // 0x800121DC: bne         $v1, $at, L_800121F4
    if (ctx->r3 != ctx->r1) {
        // 0x800121E0: nop
    
            goto L_800121F4;
    }
    // 0x800121E0: nop

    // 0x800121E4: jal         0x80061F70
    // 0x800121E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_animate(rdram, ctx);
        goto after_1;
    // 0x800121E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800121EC: lb          $v1, 0x1E($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E);
    // 0x800121F0: nop

L_800121F4:
    // 0x800121F4: beq         $v1, $zero, L_800122C4
    if (ctx->r3 == 0) {
        // 0x800121F8: nop
    
            goto L_800122C4;
    }
    // 0x800121F8: nop

    // 0x800121FC: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80012200: nop

    // 0x80012204: lw          $t8, 0x40($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X40);
    // 0x80012208: nop

    // 0x8001220C: beq         $t8, $zero, L_800122C4
    if (ctx->r24 == 0) {
        // 0x80012210: nop
    
            goto L_800122C4;
    }
    // 0x80012210: nop

    // 0x80012214: beq         $s3, $zero, L_80012244
    if (ctx->r19 == 0) {
        // 0x80012218: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80012244;
    }
    // 0x80012218: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001221C: lb          $t9, 0x1D6($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X1D6);
    // 0x80012220: nop

    // 0x80012224: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x80012228: beq         $at, $zero, L_80012244
    if (ctx->r1 == 0) {
        // 0x8001222C: nop
    
            goto L_80012244;
    }
    // 0x8001222C: nop

    // 0x80012230: lh          $t5, 0x0($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X0);
    // 0x80012234: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80012238: bne         $t5, $at, L_80012244
    if (ctx->r13 != ctx->r1) {
        // 0x8001223C: nop
    
            goto L_80012244;
    }
    // 0x8001223C: nop

    // 0x80012240: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80012244:
    // 0x80012244: jal         0x80066450
    // 0x80012248: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    cam_get_viewport_layout(rdram, ctx);
        goto after_2;
    // 0x80012248: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    after_2:
    // 0x8001224C: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80012250: beq         $v0, $zero, L_8001225C
    if (ctx->r2 == 0) {
        // 0x80012254: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_8001225C;
    }
    // 0x80012254: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80012258: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8001225C:
    // 0x8001225C: lb          $t7, 0x1F($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1F);
    // 0x80012260: lh          $t5, 0x48($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X48);
    // 0x80012264: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80012268: addu        $t8, $s0, $t6
    ctx->r24 = ADD32(ctx->r16, ctx->r14);
    // 0x8001226C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80012270: bne         $t5, $at, L_80012294
    if (ctx->r13 != ctx->r1) {
        // 0x80012274: sw          $t9, 0x44($s2)
        MEM_W(0X44, ctx->r18) = ctx->r25;
            goto L_80012294;
    }
    // 0x80012274: sw          $t9, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r25;
    // 0x80012278: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8001227C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80012280: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80012284: jal         0x8001D718
    // 0x80012288: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    obj_shade_fancy(rdram, ctx);
        goto after_3;
    // 0x80012288: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8001228C: b           L_800122C4
    // 0x80012290: nop

        goto L_800122C4;
    // 0x80012290: nop

L_80012294:
    // 0x80012294: beq         $t1, $zero, L_800122B4
    if (ctx->r9 == 0) {
        // 0x80012298: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_800122B4;
    }
    // 0x80012298: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8001229C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800122A0: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800122A4: jal         0x8001D718
    // 0x800122A8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    obj_shade_fancy(rdram, ctx);
        goto after_4;
    // 0x800122A8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_4:
    // 0x800122AC: b           L_800122C4
    // 0x800122B0: nop

        goto L_800122C4;
    // 0x800122B0: nop

L_800122B4:
    // 0x800122B4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800122B8: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800122BC: jal         0x80024630
    // 0x800122C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    obj_shade_fast(rdram, ctx);
        goto after_5;
    // 0x800122C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
L_800122C4:
    // 0x800122C4: beq         $s3, $zero, L_800122F8
    if (ctx->r19 == 0) {
        // 0x800122C8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800122F8;
    }
    // 0x800122C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800122CC: lh          $t7, 0x0($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X0);
    // 0x800122D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800122D4: bne         $t7, $at, L_800122F8
    if (ctx->r15 != ctx->r1) {
        // 0x800122D8: nop
    
            goto L_800122F8;
    }
    // 0x800122D8: nop

    // 0x800122DC: lb          $t6, 0x1D6($s3)
    ctx->r14 = MEM_B(ctx->r19, 0X1D6);
    // 0x800122E0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800122E4: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x800122E8: beq         $at, $zero, L_800122F8
    if (ctx->r1 == 0) {
        // 0x800122EC: nop
    
            goto L_800122F8;
    }
    // 0x800122EC: nop

    // 0x800122F0: b           L_800122FC
    // 0x800122F4: sb          $t8, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r24;
        goto L_800122FC;
    // 0x800122F4: sb          $t8, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r24;
L_800122F8:
    // 0x800122F8: sb          $t9, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r25;
L_800122FC:
    // 0x800122FC: lb          $t5, 0x1F($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1F);
    // 0x80012300: lh          $t9, 0x48($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X48);
    // 0x80012304: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80012308: addu        $t6, $s0, $t7
    ctx->r14 = ADD32(ctx->r16, ctx->r15);
    // 0x8001230C: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80012310: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80012314: bne         $t9, $at, L_80012328
    if (ctx->r25 != ctx->r1) {
        // 0x80012318: sw          $t8, 0x44($s2)
        MEM_W(0X44, ctx->r18) = ctx->r24;
            goto L_80012328;
    }
    // 0x80012318: sw          $t8, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r24;
    // 0x8001231C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80012320: jal         0x80011264
    // 0x80012324: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    obj_door_number(rdram, ctx);
        goto after_6;
    // 0x80012324: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
L_80012328:
    // 0x80012328: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8001232C: nop

    // 0x80012330: lh          $a1, 0x52($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X52);
    // 0x80012334: nop

    // 0x80012338: beq         $a1, $zero, L_80012364
    if (ctx->r5 == 0) {
        // 0x8001233C: nop
    
            goto L_80012364;
    }
    // 0x8001233C: nop

    // 0x80012340: lh          $t7, 0x50($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X50);
    // 0x80012344: nop

    // 0x80012348: blez        $t7, L_80012364
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8001234C: nop
    
            goto L_80012364;
    }
    // 0x8001234C: nop

    // 0x80012350: jal         0x80011134
    // 0x80012354: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_tex_animate(rdram, ctx);
        goto after_7;
    // 0x80012354: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x80012358: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8001235C: nop

    // 0x80012360: sh          $zero, 0x52($t6)
    MEM_H(0X52, ctx->r14) = 0;
L_80012364:
    // 0x80012364: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80012368: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001236C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80012370: addiu       $s1, $s1, -0x4BF4
    ctx->r17 = ADD32(ctx->r17, -0X4BF4);
    // 0x80012374: lw          $a3, -0x4D58($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4D58);
    // 0x80012378: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001237C: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x80012380: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80012384: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80012388: jal         0x800696C4
    // 0x8001238C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_8;
    // 0x8001238C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x80012390: beq         $s3, $zero, L_800123E4
    if (ctx->r19 == 0) {
        // 0x80012394: sw          $zero, 0xB0($sp)
        MEM_W(0XB0, ctx->r29) = 0;
            goto L_800123E4;
    }
    // 0x80012394: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
    // 0x80012398: jal         0x80012F30
    // 0x8001239C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    object_undo_player_tumble(rdram, ctx);
        goto after_9;
    // 0x8001239C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x800123A0: lb          $t8, 0x3B($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X3B);
    // 0x800123A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800123A8: beq         $t8, $zero, L_800123C4
    if (ctx->r24 == 0) {
        // 0x800123AC: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800123C4;
    }
    // 0x800123AC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800123B0: lb          $t9, 0x1D6($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X1D6);
    // 0x800123B4: nop

    // 0x800123B8: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x800123BC: bne         $at, $zero, L_800123E0
    if (ctx->r1 != 0) {
        // 0x800123C0: nop
    
            goto L_800123E0;
    }
    // 0x800123C0: nop

L_800123C4:
    // 0x800123C4: lh          $a3, 0x16A($s3)
    ctx->r7 = MEM_H(ctx->r19, 0X16A);
    // 0x800123C8: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x800123CC: jal         0x800699D0
    // 0x800123D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mtx_head_push(rdram, ctx);
        goto after_10;
    // 0x800123D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_10:
    // 0x800123D4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800123D8: b           L_800123E4
    // 0x800123DC: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
        goto L_800123E4;
    // 0x800123DC: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
L_800123E0:
    // 0x800123E0: sh          $zero, 0x16A($s3)
    MEM_H(0X16A, ctx->r19) = 0;
L_800123E4:
    // 0x800123E4: lbu         $t0, 0x39($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X39);
    // 0x800123E8: nop

    // 0x800123EC: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x800123F0: bne         $at, $zero, L_800123FC
    if (ctx->r1 != 0) {
        // 0x800123F4: nop
    
            goto L_800123FC;
    }
    // 0x800123F4: nop

    // 0x800123F8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_800123FC:
    // 0x800123FC: lh          $t7, 0x48($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X48);
    // 0x80012400: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x80012404: bne         $t7, $at, L_80012410
    if (ctx->r15 != ctx->r1) {
        // 0x80012408: sra         $t6, $t0, 1
        ctx->r14 = S32(SIGNED(ctx->r8) >> 1);
            goto L_80012410;
    }
    // 0x80012408: sra         $t6, $t0, 1
    ctx->r14 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8001240C: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
L_80012410:
    // 0x80012410: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
    // 0x80012414: beq         $at, $zero, L_80012420
    if (ctx->r1 == 0) {
        // 0x80012418: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80012420;
    }
    // 0x80012418: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001241C: sw          $t8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r24;
L_80012420:
    // 0x80012420: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80012424: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80012428: beq         $t9, $zero, L_8001247C
    if (ctx->r25 == 0) {
        // 0x8001242C: nop
    
            goto L_8001247C;
    }
    // 0x8001242C: nop

    // 0x80012430: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012434: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80012438: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8001243C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80012440: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80012444: lw          $v1, 0x54($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X54);
    // 0x80012448: nop

    // 0x8001244C: lbu         $t7, 0x5($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X5);
    // 0x80012450: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x80012454: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80012458: lbu         $t7, 0x6($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X6);
    // 0x8001245C: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80012460: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80012464: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x80012468: lbu         $t7, 0x7($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X7);
    // 0x8001246C: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80012470: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80012474: b           L_80012494
    // 0x80012478: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_80012494;
    // 0x80012478: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8001247C:
    // 0x8001247C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012480: addiu       $t6, $zero, -0x100
    ctx->r14 = ADD32(0, -0X100);
    // 0x80012484: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80012488: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8001248C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80012490: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80012494:
    // 0x80012494: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x80012498: nop

    // 0x8001249C: lbu         $t8, 0x71($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X71);
    // 0x800124A0: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x800124A4: beq         $t8, $zero, L_80012504
    if (ctx->r24 == 0) {
        // 0x800124A8: nop
    
            goto L_80012504;
    }
    // 0x800124A8: nop

    // 0x800124AC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800124B0: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800124B4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800124B8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800124BC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800124C0: lw          $v1, 0x54($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X54);
    // 0x800124C4: andi        $t9, $t0, 0xFF
    ctx->r25 = ctx->r8 & 0XFF;
    // 0x800124C8: lbu         $t5, 0x19($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X19);
    // 0x800124CC: lbu         $t7, 0x18($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X18);
    // 0x800124D0: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800124D4: lbu         $t5, 0x1A($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1A);
    // 0x800124D8: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800124DC: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800124E0: sll         $t8, $t5, 8
    ctx->r24 = S32(ctx->r13 << 8);
    // 0x800124E4: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800124E8: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x800124EC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800124F0: jal         0x8007B88C
    // 0x800124F4: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    directional_lighting_on(rdram, ctx);
        goto after_11;
    // 0x800124F4: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    after_11:
    // 0x800124F8: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x800124FC: b           L_8001256C
    // 0x80012500: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
        goto L_8001256C;
    // 0x80012500: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
L_80012504:
    // 0x80012504: beq         $t7, $zero, L_80012550
    if (ctx->r15 == 0) {
        // 0x80012508: lui         $t6, 0xFA00
        ctx->r14 = S32(0XFA00 << 16);
            goto L_80012550;
    }
    // 0x80012508: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8001250C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012510: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80012514: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80012518: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8001251C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80012520: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
    // 0x80012524: nop

    // 0x80012528: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x8001252C: sll         $t5, $t9, 24
    ctx->r13 = S32(ctx->r25 << 24);
    // 0x80012530: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x80012534: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80012538: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x8001253C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80012540: andi        $t5, $t0, 0xFF
    ctx->r13 = ctx->r8 & 0XFF;
    // 0x80012544: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x80012548: b           L_80012568
    // 0x8001254C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_80012568;
    // 0x8001254C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_80012550:
    // 0x80012550: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012554: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80012558: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001255C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80012560: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80012564: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80012568:
    // 0x80012568: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
L_8001256C:
    // 0x8001256C: beq         $at, $zero, L_8001259C
    if (ctx->r1 == 0) {
        // 0x80012570: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_8001259C;
    }
    // 0x80012570: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80012574: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80012578: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8001257C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80012580: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80012584: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80012588: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x8001258C: jal         0x800143A8
    // 0x80012590: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    render_mesh(rdram, ctx);
        goto after_12;
    // 0x80012590: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_12:
    // 0x80012594: b           L_800125BC
    // 0x80012598: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
        goto L_800125BC;
    // 0x80012598: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
L_8001259C:
    // 0x8001259C: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x800125A0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800125A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800125A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800125AC: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x800125B0: jal         0x800143A8
    // 0x800125B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    render_mesh(rdram, ctx);
        goto after_13;
    // 0x800125B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_13:
    // 0x800125B8: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
L_800125BC:
    // 0x800125BC: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x800125C0: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x800125C4: lbu         $t6, 0x71($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X71);
    // 0x800125C8: nop

    // 0x800125CC: beq         $t6, $zero, L_80012644
    if (ctx->r14 == 0) {
        // 0x800125D0: nop
    
            goto L_80012644;
    }
    // 0x800125D0: nop

    // 0x800125D4: beq         $t9, $zero, L_80012624
    if (ctx->r25 == 0) {
        // 0x800125D8: lui         $t6, 0xFA00
        ctx->r14 = S32(0XFA00 << 16);
            goto L_80012624;
    }
    // 0x800125D8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800125DC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800125E0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800125E4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800125E8: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800125EC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800125F0: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
    // 0x800125F4: nop

    // 0x800125F8: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x800125FC: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x80012600: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80012604: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x80012608: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8001260C: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x80012610: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80012614: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x80012618: or          $t5, $t8, $t9
    ctx->r13 = ctx->r24 | ctx->r25;
    // 0x8001261C: b           L_8001263C
    // 0x80012620: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_8001263C;
    // 0x80012620: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_80012624:
    // 0x80012624: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012628: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8001262C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80012630: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80012634: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80012638: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8001263C:
    // 0x8001263C: jal         0x8007B8A4
    // 0x80012640: nop

    directional_lighting_off(rdram, ctx);
        goto after_14;
    // 0x80012640: nop

    after_14:
L_80012644:
    // 0x80012644: lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X60);
    // 0x80012648: nop

    // 0x8001264C: beq         $v0, $zero, L_800129A0
    if (ctx->r2 == 0) {
        // 0x80012650: lw          $a1, 0x78($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X78);
            goto L_800129A0;
    }
    // 0x80012650: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80012654: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80012658: beq         $s3, $zero, L_80012674
    if (ctx->r19 == 0) {
        // 0x8001265C: sw          $t9, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->r25;
            goto L_80012674;
    }
    // 0x8001265C: sw          $t9, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r25;
    // 0x80012660: lb          $t5, 0x1D6($s3)
    ctx->r13 = MEM_B(ctx->r19, 0X1D6);
    // 0x80012664: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80012668: bne         $t5, $at, L_80012678
    if (ctx->r13 != ctx->r1) {
        // 0x8001266C: lw          $t7, 0xAC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XAC);
            goto L_80012678;
    }
    // 0x8001266C: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80012670: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
L_80012674:
    // 0x80012674: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
L_80012678:
    // 0x80012678: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8001267C: blez        $t7, L_8001299C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80012680: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8001299C;
    }
    // 0x80012680: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80012684: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_80012688:
    // 0x80012688: lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X60);
    // 0x8001268C: nop

    // 0x80012690: addu        $t6, $v0, $t3
    ctx->r14 = ADD32(ctx->r2, ctx->r11);
    // 0x80012694: lw          $s0, 0x4($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X4);
    // 0x80012698: nop

    // 0x8001269C: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800126A0: nop

    // 0x800126A4: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x800126A8: bne         $t9, $zero, L_80012990
    if (ctx->r25 != 0) {
        // 0x800126AC: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_80012990;
    }
    // 0x800126AC: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800126B0: lw          $t5, 0x2C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X2C);
    // 0x800126B4: nop

    // 0x800126B8: addu        $t7, $t5, $t2
    ctx->r15 = ADD32(ctx->r13, ctx->r10);
    // 0x800126BC: lb          $v1, 0x0($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X0);
    // 0x800126C0: nop

    // 0x800126C4: bltz        $v1, L_80012990
    if (SIGNED(ctx->r3) < 0) {
        // 0x800126C8: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_80012990;
    }
    // 0x800126C8: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800126CC: lh          $t6, 0x18($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X18);
    // 0x800126D0: nop

    // 0x800126D4: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800126D8: beq         $at, $zero, L_80012990
    if (ctx->r1 == 0) {
        // 0x800126DC: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_80012990;
    }
    // 0x800126DC: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800126E0: lb          $t9, 0x3A($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X3A);
    // 0x800126E4: lw          $t8, 0x68($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X68);
    // 0x800126E8: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800126EC: lw          $t6, 0x14($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14);
    // 0x800126F0: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800126F4: addu        $t7, $t8, $t5
    ctx->r15 = ADD32(ctx->r24, ctx->r13);
    // 0x800126F8: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800126FC: lh          $t5, 0x0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X0);
    // 0x80012700: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80012704: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80012708: lw          $t6, 0x44($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X44);
    // 0x8001270C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80012710: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80012714: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80012718: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8001271C: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80012720: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80012724: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x80012728: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001272C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80012730: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80012734: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80012738: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001273C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80012740: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x80012744: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80012748: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8001274C: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80012750: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80012754: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012758: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8001275C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012760: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80012764: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80012768: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x8001276C: lb          $t7, 0x53($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X53);
    // 0x80012770: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x80012774: bne         $t7, $at, L_80012784
    if (ctx->r15 != ctx->r1) {
        // 0x80012778: lui         $t5, 0x8000
        ctx->r13 = S32(0X8000 << 16);
            goto L_80012784;
    }
    // 0x80012778: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x8001277C: b           L_80012788
    // 0x80012780: addiu       $t1, $zero, 0x10A
    ctx->r9 = ADD32(0, 0X10A);
        goto L_80012788;
    // 0x80012780: addiu       $t1, $zero, 0x10A
    ctx->r9 = ADD32(0, 0X10A);
L_80012784:
    // 0x80012784: addiu       $t1, $zero, 0x10B
    ctx->r9 = ADD32(0, 0X10B);
L_80012788:
    // 0x80012788: slti        $at, $t9, 0xFF
    ctx->r1 = SIGNED(ctx->r25) < 0XFF ? 1 : 0;
    // 0x8001278C: beq         $at, $zero, L_80012798
    if (ctx->r1 == 0) {
        // 0x80012790: ori         $t8, $t1, 0x4
        ctx->r24 = ctx->r9 | 0X4;
            goto L_80012798;
    }
    // 0x80012790: ori         $t8, $t1, 0x4
    ctx->r24 = ctx->r9 | 0X4;
    // 0x80012794: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
L_80012798:
    // 0x80012798: lw          $t5, 0x310($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X310);
    // 0x8001279C: addiu       $at, $zero, 0x17D7
    ctx->r1 = ADD32(0, 0X17D7);
    // 0x800127A0: beq         $t5, $at, L_800127AC
    if (ctx->r13 == ctx->r1) {
        // 0x800127A4: nop
    
            goto L_800127AC;
    }
    // 0x800127A4: nop

    // 0x800127A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800127AC:
    // 0x800127AC: bne         $a0, $zero, L_80012960
    if (ctx->r4 != 0) {
        // 0x800127B0: nop
    
            goto L_80012960;
    }
    // 0x800127B0: nop

    // 0x800127B4: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x800127B8: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
    // 0x800127BC: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800127C0: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
    // 0x800127C4: beq         $v0, $zero, L_800127DC
    if (ctx->r2 == 0) {
        // 0x800127C8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800127DC;
    }
    // 0x800127C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800127CC: lw          $v0, 0xAC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XAC);
    // 0x800127D0: nop

    // 0x800127D4: xori        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 ^ 0X3;
    // 0x800127D8: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
L_800127DC:
    // 0x800127DC: sll         $t0, $v0, 24
    ctx->r8 = S32(ctx->r2 << 24);
    // 0x800127E0: sra         $t8, $t0, 24
    ctx->r24 = S32(SIGNED(ctx->r8) >> 24);
    // 0x800127E4: beq         $s3, $zero, L_80012804
    if (ctx->r19 == 0) {
        // 0x800127E8: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_80012804;
    }
    // 0x800127E8: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800127EC: lbu         $t5, 0x1F7($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X1F7);
    // 0x800127F0: nop

    // 0x800127F4: slti        $at, $t5, 0xFF
    ctx->r1 = SIGNED(ctx->r13) < 0XFF ? 1 : 0;
    // 0x800127F8: beq         $at, $zero, L_80012804
    if (ctx->r1 == 0) {
        // 0x800127FC: nop
    
            goto L_80012804;
    }
    // 0x800127FC: nop

    // 0x80012800: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80012804:
    // 0x80012804: beq         $t0, $zero, L_800128B4
    if (ctx->r8 == 0) {
        // 0x80012808: andi        $t6, $v1, 0xFF
        ctx->r14 = ctx->r3 & 0XFF;
            goto L_800128B4;
    }
    // 0x80012808: andi        $t6, $v1, 0xFF
    ctx->r14 = ctx->r3 & 0XFF;
    // 0x8001280C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80012810: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x80012814: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80012818: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8001281C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80012820: sll         $t5, $t6, 8
    ctx->r13 = S32(ctx->r14 << 8);
    // 0x80012824: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80012828: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8001282C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80012830: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80012834: sb          $t0, 0x8A($sp)
    MEM_B(0X8A, ctx->r29) = ctx->r8;
    // 0x80012838: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    // 0x8001283C: sw          $t2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r10;
    // 0x80012840: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80012844: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    // 0x80012848: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x8001284C: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    // 0x80012850: jal         0x80012C98
    // 0x80012854: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    func_80012C98(rdram, ctx);
        goto after_15;
    // 0x80012854: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    after_15:
    // 0x80012858: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001285C: lb          $t0, 0x8A($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X8A);
    // 0x80012860: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80012864: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80012868: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x8001286C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80012870: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80012874: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80012878: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8001287C: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80012880: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80012884: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80012888: addiu       $t6, $zero, -0x100
    ctx->r14 = ADD32(0, -0X100);
    // 0x8001288C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80012890: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80012894: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012898: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8001289C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800128A0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800128A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800128A8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800128AC: nop

    // 0x800128B0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_800128B4:
    // 0x800128B4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800128B8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800128BC: addiu       $a2, $a2, -0x4BEC
    ctx->r6 = ADD32(ctx->r6, -0X4BEC);
    // 0x800128C0: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x800128C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800128C8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800128CC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800128D0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800128D4: sb          $t0, 0x8A($sp)
    MEM_B(0X8A, ctx->r29) = ctx->r8;
    // 0x800128D8: sw          $t2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r10;
    // 0x800128DC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x800128E0: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x800128E4: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    // 0x800128E8: jal         0x80068754
    // 0x800128EC: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    render_sprite_billboard(rdram, ctx);
        goto after_16;
    // 0x800128EC: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    after_16:
    // 0x800128F0: lb          $t0, 0x8A($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X8A);
    // 0x800128F4: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x800128F8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800128FC: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80012900: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80012904: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80012908: beq         $t0, $zero, L_80012960
    if (ctx->r8 == 0) {
        // 0x8001290C: sw          $v0, 0x78($s0)
        MEM_W(0X78, ctx->r16) = ctx->r2;
            goto L_80012960;
    }
    // 0x8001290C: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    // 0x80012910: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012914: lui         $t6, 0xBC00
    ctx->r14 = S32(0XBC00 << 16);
    // 0x80012918: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001291C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80012920: ori         $t6, $t6, 0xA
    ctx->r14 = ctx->r14 | 0XA;
    // 0x80012924: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80012928: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001292C: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    // 0x80012930: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    // 0x80012934: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x80012938: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8001293C: sw          $t2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r10;
    // 0x80012940: jal         0x80012CE8
    // 0x80012944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80012CE8(rdram, ctx);
        goto after_17;
    // 0x80012944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80012948: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x8001294C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80012950: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80012954: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80012958: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8001295C: nop

L_80012960:
    // 0x80012960: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80012964: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80012968: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8001296C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80012970: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80012974: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80012978: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x8001297C: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80012980: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x80012984: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80012988: nop

    // 0x8001298C: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
L_80012990:
    // 0x80012990: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80012994: bne         $t2, $t9, L_80012688
    if (ctx->r10 != ctx->r25) {
        // 0x80012998: addiu       $t3, $t3, 0x4
        ctx->r11 = ADD32(ctx->r11, 0X4);
            goto L_80012688;
    }
    // 0x80012998: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
L_8001299C:
    // 0x8001299C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
L_800129A0:
    // 0x800129A0: beq         $s3, $zero, L_80012AF8
    if (ctx->r19 == 0) {
        // 0x800129A4: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80012AF8;
    }
    // 0x800129A4: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800129A8: lw          $s0, 0x144($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X144);
    // 0x800129AC: nop

    // 0x800129B0: beq         $s0, $zero, L_80012AF8
    if (ctx->r16 == 0) {
        // 0x800129B4: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80012AF8;
    }
    // 0x800129B4: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800129B8: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x800129BC: nop

    // 0x800129C0: lb          $v1, 0x58($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X58);
    // 0x800129C4: nop

    // 0x800129C8: bltz        $v1, L_80012AF8
    if (SIGNED(ctx->r3) < 0) {
        // 0x800129CC: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80012AF8;
    }
    // 0x800129CC: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800129D0: lh          $t5, 0x18($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X18);
    // 0x800129D4: nop

    // 0x800129D8: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800129DC: beq         $at, $zero, L_80012AF8
    if (ctx->r1 == 0) {
        // 0x800129E0: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80012AF8;
    }
    // 0x800129E0: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800129E4: lb          $t6, 0x3A($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X3A);
    // 0x800129E8: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x800129EC: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800129F0: lw          $t5, 0x14($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X14);
    // 0x800129F4: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800129F8: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800129FC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80012A00: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x80012A04: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x80012A08: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80012A0C: lw          $t5, 0x44($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X44);
    // 0x80012A10: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x80012A14: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80012A18: addu        $v0, $t5, $t8
    ctx->r2 = ADD32(ctx->r13, ctx->r24);
    // 0x80012A1C: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80012A20: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80012A24: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80012A28: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x80012A2C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80012A30: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80012A34: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80012A38: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80012A3C: sub.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80012A40: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80012A44: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80012A48: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x80012A4C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80012A50: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80012A54: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80012A58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012A5C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80012A60: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x80012A64: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80012A68: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80012A6C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80012A70: addiu       $a2, $a2, -0x4BEC
    ctx->r6 = ADD32(ctx->r6, -0X4BEC);
    // 0x80012A74: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x80012A78: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x80012A7C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80012A80: addiu       $t6, $zero, 0x10A
    ctx->r14 = ADD32(0, 0X10A);
    // 0x80012A84: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80012A88: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80012A8C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80012A90: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x80012A94: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80012A98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80012A9C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80012AA0: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x80012AA4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80012AA8: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80012AAC: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x80012AB0: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80012AB4: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80012AB8: lw          $t5, 0x40($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X40);
    // 0x80012ABC: sub.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80012AC0: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80012AC4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80012AC8: mul.d       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x80012ACC: add.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d + ctx->f10.d;
    // 0x80012AD0: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80012AD4: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x80012AD8: lb          $t8, 0x53($t5)
    ctx->r24 = MEM_B(ctx->r13, 0X53);
    // 0x80012ADC: nop

    // 0x80012AE0: bne         $t8, $at, L_80012AF8
    if (ctx->r24 != ctx->r1) {
        // 0x80012AE4: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80012AF8;
    }
    // 0x80012AE4: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80012AE8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80012AEC: jal         0x80068754
    // 0x80012AF0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    render_sprite_billboard(rdram, ctx);
        goto after_18;
    // 0x80012AF0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_18:
    // 0x80012AF4: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
L_80012AF8:
    // 0x80012AF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80012AFC: beq         $t7, $at, L_80012BA8
    if (ctx->r15 == ctx->r1) {
        // 0x80012B00: lw          $t6, 0xA8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XA8);
            goto L_80012BA8;
    }
    // 0x80012B00: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80012B04: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x80012B08: nop

    // 0x80012B0C: lbu         $t5, 0x71($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X71);
    // 0x80012B10: nop

    // 0x80012B14: beq         $t5, $zero, L_80012B6C
    if (ctx->r13 == 0) {
        // 0x80012B18: lw          $t5, 0xB0($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XB0);
            goto L_80012B6C;
    }
    // 0x80012B18: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80012B1C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012B20: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80012B24: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80012B28: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80012B2C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80012B30: lw          $v1, 0x54($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X54);
    // 0x80012B34: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x80012B38: lbu         $t6, 0x19($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X19);
    // 0x80012B3C: lbu         $t9, 0x18($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X18);
    // 0x80012B40: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80012B44: lbu         $t6, 0x1A($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1A);
    // 0x80012B48: sll         $t5, $t9, 24
    ctx->r13 = S32(ctx->r25 << 24);
    // 0x80012B4C: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x80012B50: sll         $t5, $t6, 8
    ctx->r13 = S32(ctx->r14 << 8);
    // 0x80012B54: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x80012B58: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80012B5C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80012B60: jal         0x8007B88C
    // 0x80012B64: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    directional_lighting_on(rdram, ctx);
        goto after_19;
    // 0x80012B64: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    after_19:
    // 0x80012B68: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
L_80012B6C:
    // 0x80012B6C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80012B70: lw          $a2, 0x9C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X9C);
    // 0x80012B74: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80012B78: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80012B7C: jal         0x800143A8
    // 0x80012B80: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    render_mesh(rdram, ctx);
        goto after_20;
    // 0x80012B80: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_20:
    // 0x80012B84: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x80012B88: nop

    // 0x80012B8C: lbu         $t7, 0x71($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X71);
    // 0x80012B90: nop

    // 0x80012B94: beq         $t7, $zero, L_80012BA8
    if (ctx->r15 == 0) {
        // 0x80012B98: lw          $t6, 0xA8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XA8);
            goto L_80012BA8;
    }
    // 0x80012B98: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80012B9C: jal         0x8007B8A4
    // 0x80012BA0: nop

    directional_lighting_off(rdram, ctx);
        goto after_21;
    // 0x80012BA0: nop

    after_21:
    // 0x80012BA4: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
L_80012BA8:
    // 0x80012BA8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80012BAC: bne         $t6, $zero, L_80012BCC
    if (ctx->r14 != 0) {
        // 0x80012BB0: nop
    
            goto L_80012BCC;
    }
    // 0x80012BB0: nop

    // 0x80012BB4: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x80012BB8: nop

    // 0x80012BBC: lbu         $t5, 0x71($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X71);
    // 0x80012BC0: nop

    // 0x80012BC4: beq         $t5, $zero, L_80012BE8
    if (ctx->r13 == 0) {
        // 0x80012BC8: lw          $t9, 0xA4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA4);
            goto L_80012BE8;
    }
    // 0x80012BC8: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
L_80012BCC:
    // 0x80012BCC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012BD0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80012BD4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80012BD8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80012BDC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80012BE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80012BE4: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
L_80012BE8:
    // 0x80012BE8: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80012BEC: beq         $t9, $zero, L_80012C0C
    if (ctx->r25 == 0) {
        // 0x80012BF0: nop
    
            goto L_80012C0C;
    }
    // 0x80012BF0: nop

    // 0x80012BF4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012BF8: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x80012BFC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80012C00: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80012C04: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80012C08: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80012C0C:
    // 0x80012C0C: jal         0x80069C80
    // 0x80012C10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mtx_pop(rdram, ctx);
        goto after_22;
    // 0x80012C10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
L_80012C14:
    // 0x80012C14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80012C18: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80012C1C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80012C20: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80012C24: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80012C28: jr          $ra
    // 0x80012C2C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80012C2C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void set_render_printf_background_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6814: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B6818: addiu       $v0, $v0, -0x7468
    ctx->r2 = ADD32(ctx->r2, -0X7468);
    // 0x800B681C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800B6820: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B6824: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B6828: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800B682C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800B6830: addiu       $t0, $zero, 0x85
    ctx->r8 = ADD32(0, 0X85);
    // 0x800B6834: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x800B6838: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B683C: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x800B6840: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B6844: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800B6848: sb          $a0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r4;
    // 0x800B684C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800B6850: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800B6854: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800B6858: or          $t8, $a2, $zero
    ctx->r24 = ctx->r6 | 0;
    // 0x800B685C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B6860: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800B6864: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
    // 0x800B6868: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B686C: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
    // 0x800B6870: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800B6874: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B6878: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B687C: sb          $a2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r6;
    // 0x800B6880: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800B6884: nop

    // 0x800B6888: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B688C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800B6890: sb          $a3, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r7;
    // 0x800B6894: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800B6898: nop

    // 0x800B689C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B68A0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B68A4: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x800B68A8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800B68AC: nop

    // 0x800B68B0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B68B4: jr          $ra
    // 0x800B68B8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x800B68B8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void audspat_play_sound_direct(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800095E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800095EC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800095F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800095F4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800095F8: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800095FC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80009600: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80009604: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80009608: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8000960C: lbu         $t7, 0x4B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4B);
    // 0x80009610: lbu         $t9, 0x4F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4F);
    // 0x80009614: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80009618: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8000961C: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80009620: addiu       $t0, $zero, 0x3A98
    ctx->r8 = ADD32(0, 0X3A98);
    // 0x80009624: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80009628: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8000962C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80009630: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80009634: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80009638: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8000963C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80009640: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80009644: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80009648: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8000964C: beq         $t2, $zero, L_8000969C
    if (ctx->r10 == 0) {
        // 0x80009650: sw          $t9, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r25;
            goto L_8000969C;
    }
    // 0x80009650: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80009654: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80009658: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000965C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80009660: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80009664: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80009668: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8000966C: nop

    // 0x80009670: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80009674: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80009678: nop

    // 0x8000967C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80009680: bne         $t2, $zero, L_80009694
    if (ctx->r10 != 0) {
        // 0x80009684: nop
    
            goto L_80009694;
    }
    // 0x80009684: nop

    // 0x80009688: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8000968C: b           L_800096AC
    // 0x80009690: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_800096AC;
    // 0x80009690: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80009694:
    // 0x80009694: b           L_800096AC
    // 0x80009698: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_800096AC;
    // 0x80009698: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_8000969C:
    // 0x8000969C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800096A0: nop

    // 0x800096A4: bltz        $t2, L_80009694
    if (SIGNED(ctx->r10) < 0) {
        // 0x800096A8: nop
    
            goto L_80009694;
    }
    // 0x800096A8: nop

L_800096AC:
    // 0x800096AC: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800096B0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800096B4: addiu       $t3, $zero, 0x3F
    ctx->r11 = ADD32(0, 0X3F);
    // 0x800096B8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800096BC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800096C0: jal         0x8000974C
    // 0x800096C4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    audspat_point_create(rdram, ctx);
        goto after_0;
    // 0x800096C4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    after_0:
    // 0x800096C8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800096CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800096D0: jr          $ra
    // 0x800096D4: nop

    return;
    // 0x800096D4: nop

;}
RECOMP_FUNC void func_8000CBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CBC0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000CBC4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CBC8: addiu       $v0, $v0, -0x4C38
    ctx->r2 = ADD32(ctx->r2, -0X4C38);
    // 0x8000CBCC: addiu       $v1, $v1, -0x4C78
    ctx->r3 = ADD32(ctx->r3, -0X4C78);
L_8000CBD0:
    // 0x8000CBD0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8000CBD4: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x8000CBD8: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x8000CBDC: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x8000CBE0: bne         $v1, $v0, L_8000CBD0
    if (ctx->r3 != ctx->r2) {
        // 0x8000CBE4: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_8000CBD0;
    }
    // 0x8000CBE4: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8000CBE8: jr          $ra
    // 0x8000CBEC: nop

    return;
    // 0x8000CBEC: nop

;}
RECOMP_FUNC void repair_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075F90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80075F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075F98: jal         0x80075B34
    // 0x80075F9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80075F9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80075FA0: beq         $v0, $zero, L_80075FB0
    if (ctx->r2 == 0) {
        // 0x80075FA4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80075FB0;
    }
    // 0x80075FA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80075FA8: bne         $v0, $at, L_80076000
    if (ctx->r2 != ctx->r1) {
        // 0x80075FAC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80076000;
    }
    // 0x80075FAC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80075FB0:
    // 0x80075FB0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80075FB4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80075FB8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80075FBC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80075FC0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80075FC4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80075FC8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80075FCC: addiu       $t8, $t8, 0x4598
    ctx->r24 = ADD32(ctx->r24, 0X4598);
    // 0x80075FD0: jal         0x800CFA90
    // 0x80075FD4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    osPfsChecker_recomp(rdram, ctx);
        goto after_1;
    // 0x80075FD4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_1:
    // 0x80075FD8: bne         $v0, $zero, L_80075FE8
    if (ctx->r2 != 0) {
        // 0x80075FDC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80075FE8;
    }
    // 0x80075FDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80075FE0: b           L_80076000
    // 0x80075FE4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80076000;
    // 0x80075FE4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80075FE8:
    // 0x80075FE8: bne         $v0, $at, L_80075FF8
    if (ctx->r2 != ctx->r1) {
        // 0x80075FEC: nop
    
            goto L_80075FF8;
    }
    // 0x80075FEC: nop

    // 0x80075FF0: b           L_80076000
    // 0x80075FF4: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_80076000;
    // 0x80075FF4: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80075FF8:
    // 0x80075FF8: b           L_80076000
    // 0x80075FFC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80076000;
    // 0x80075FFC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80076000:
    // 0x80076000: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80076004: jal         0x80075D44
    // 0x80076008: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_2;
    // 0x80076008: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8007600C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076010: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80076014: jr          $ra
    // 0x80076018: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80076018: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void dialogue_tt_gamestatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E914: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8009E918: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009E91C: addiu       $v1, $v1, 0x23A8
    ctx->r3 = ADD32(ctx->r3, 0X23A8);
    // 0x8009E920: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009E924: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8009E928: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8009E92C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8009E930: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8009E934: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8009E938: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8009E93C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8009E940: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8009E944: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8009E948: bne         $s4, $v0, L_8009E95C
    if (ctx->r20 != ctx->r2) {
        // 0x8009E94C: swc1        $f20, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
            goto L_8009E95C;
    }
    // 0x8009E94C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8009E950: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8009E954: b           L_8009ED00
    // 0x8009E958: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
        goto L_8009ED00;
    // 0x8009E958: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_8009E95C:
    // 0x8009E95C: jal         0x8006ECD0
    // 0x8009E960: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009E960: nop

    after_0:
    // 0x8009E964: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8009E968: jal         0x80068748
    // 0x8009E96C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x8009E96C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x8009E970: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8009E974: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8009E978: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8009E97C: bne         $t7, $zero, L_8009E98C
    if (ctx->r15 != 0) {
        // 0x8009E980: lui         $s2, 0x800E
        ctx->r18 = S32(0X800E << 16);
            goto L_8009E98C;
    }
    // 0x8009E980: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8009E984: b           L_8009E990
    // 0x8009E988: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
        goto L_8009E990;
    // 0x8009E988: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
L_8009E98C:
    // 0x8009E98C: addiu       $s5, $zero, 0x14
    ctx->r21 = ADD32(0, 0X14);
L_8009E990:
    // 0x8009E990: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8009E994: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x8009E998: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8009E99C: beq         $t0, $zero, L_8009E9A8
    if (ctx->r8 == 0) {
        // 0x8009E9A0: addiu       $s2, $s2, -0x324
        ctx->r18 = ADD32(ctx->r18, -0X324);
            goto L_8009E9A8;
    }
    // 0x8009E9A0: addiu       $s2, $s2, -0x324
    ctx->r18 = ADD32(ctx->r18, -0X324);
    // 0x8009E9A4: addiu       $s3, $zero, 0x9
    ctx->r19 = ADD32(0, 0X9);
L_8009E9A8:
    // 0x8009E9A8: addiu       $t1, $zero, -0x4A
    ctx->r9 = ADD32(0, -0X4A);
    // 0x8009E9AC: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8009E9B0: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009E9B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009E9B8: sll         $v0, $s3, 5
    ctx->r2 = S32(ctx->r19 << 5);
    // 0x8009E9BC: addiu       $t4, $zero, 0x41
    ctx->r12 = ADD32(0, 0X41);
    // 0x8009E9C0: subu        $t5, $t4, $s5
    ctx->r13 = SUB32(ctx->r12, ctx->r21);
    // 0x8009E9C4: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8009E9C8: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8009E9CC: swc1        $f6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f6.u32l;
    // 0x8009E9D0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8009E9D4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009E9D8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8009E9DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8009E9E0: jal         0x8009CFA4
    // 0x8009E9E4: swc1        $f10, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f10.u32l;
    menu_element_render(rdram, ctx);
        goto after_2;
    // 0x8009E9E4: swc1        $f10, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f10.u32l;
    after_2:
    // 0x8009E9E8: jal         0x8007C36C
    // 0x8009E9EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_3;
    // 0x8009E9EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8009E9F0: addiu       $t8, $zero, -0x1D
    ctx->r24 = ADD32(0, -0X1D);
    // 0x8009E9F4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8009E9F8: addiu       $t0, $zero, 0x62
    ctx->r8 = ADD32(0, 0X62);
    // 0x8009E9FC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009EA00: subu        $t1, $t0, $s5
    ctx->r9 = SUB32(ctx->r8, ctx->r21);
    // 0x8009EA04: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8009EA08: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8009EA0C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8009EA10: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009EA14: swc1        $f18, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f18.u32l;
    // 0x8009EA18: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009EA1C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8009EA20: swc1        $f20, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f20.u32l;
    // 0x8009EA24: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8009EA28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009EA2C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8009EA30: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x8009EA34: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009EA38: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x8009EA3C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8009EA40: nop

    // 0x8009EA44: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8009EA48: nop

    // 0x8009EA4C: lh          $a1, 0x0($t4)
    ctx->r5 = MEM_H(ctx->r12, 0X0);
    // 0x8009EA50: nop

    // 0x8009EA54: div         $zero, $a1, $s0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r16)));
    // 0x8009EA58: bne         $s0, $zero, L_8009EA64
    if (ctx->r16 != 0) {
        // 0x8009EA5C: nop
    
            goto L_8009EA64;
    }
    // 0x8009EA5C: nop

    // 0x8009EA60: break       7
    do_break(2148133472);
L_8009EA64:
    // 0x8009EA64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009EA68: bne         $s0, $at, L_8009EA7C
    if (ctx->r16 != ctx->r1) {
        // 0x8009EA6C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009EA7C;
    }
    // 0x8009EA6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009EA70: bne         $a1, $at, L_8009EA7C
    if (ctx->r5 != ctx->r1) {
        // 0x8009EA74: nop
    
            goto L_8009EA7C;
    }
    // 0x8009EA74: nop

    // 0x8009EA78: break       6
    do_break(2148133496);
L_8009EA7C:
    // 0x8009EA7C: mflo        $v0
    ctx->r2 = lo;
    // 0x8009EA80: beq         $v0, $zero, L_8009EACC
    if (ctx->r2 == 0) {
        // 0x8009EA84: nop
    
            goto L_8009EACC;
    }
    // 0x8009EA84: nop

    // 0x8009EA88: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8009EA8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009EA90: jal         0x8009CFA4
    // 0x8009EA94: sh          $v0, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r2;
    menu_element_render(rdram, ctx);
        goto after_4;
    // 0x8009EA94: sh          $v0, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r2;
    after_4:
    // 0x8009EA98: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8009EA9C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8009EAA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009EAA4: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8009EAA8: nop

    // 0x8009EAAC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8009EAB0: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
    // 0x8009EAB4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8009EAB8: nop

    // 0x8009EABC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8009EAC0: nop

    // 0x8009EAC4: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    // 0x8009EAC8: nop

L_8009EACC:
    // 0x8009EACC: div         $zero, $a1, $s0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r16)));
    // 0x8009EAD0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8009EAD4: bne         $s0, $zero, L_8009EAE0
    if (ctx->r16 != 0) {
        // 0x8009EAD8: nop
    
            goto L_8009EAE0;
    }
    // 0x8009EAD8: nop

    // 0x8009EADC: break       7
    do_break(2148133596);
L_8009EAE0:
    // 0x8009EAE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009EAE4: bne         $s0, $at, L_8009EAF8
    if (ctx->r16 != ctx->r1) {
        // 0x8009EAE8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009EAF8;
    }
    // 0x8009EAE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009EAEC: bne         $a1, $at, L_8009EAF8
    if (ctx->r5 != ctx->r1) {
        // 0x8009EAF0: nop
    
            goto L_8009EAF8;
    }
    // 0x8009EAF0: nop

    // 0x8009EAF4: break       6
    do_break(2148133620);
L_8009EAF8:
    // 0x8009EAF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009EAFC: mfhi        $t8
    ctx->r24 = hi;
    // 0x8009EB00: sh          $t8, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r24;
    // 0x8009EB04: jal         0x8009CFA4
    // 0x8009EB08: nop

    menu_element_render(rdram, ctx);
        goto after_5;
    // 0x8009EB08: nop

    after_5:
    // 0x8009EB0C: addiu       $t0, $zero, -0x31
    ctx->r8 = ADD32(0, -0X31);
    // 0x8009EB10: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8009EB14: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8009EB18: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009EB1C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8009EB20: swc1        $f8, 0x14C($t1)
    MEM_W(0X14C, ctx->r9) = ctx->f8.u32l;
    // 0x8009EB24: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009EB28: jal         0x8009CFA4
    // 0x8009EB2C: swc1        $f20, 0x150($t2)
    MEM_W(0X150, ctx->r10) = ctx->f20.u32l;
    menu_element_render(rdram, ctx);
        goto after_6;
    // 0x8009EB2C: swc1        $f20, 0x150($t2)
    MEM_W(0X150, ctx->r10) = ctx->f20.u32l;
    after_6:
    // 0x8009EB30: jal         0x8007C36C
    // 0x8009EB34: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    sprite_opaque(rdram, ctx);
        goto after_7;
    // 0x8009EB34: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_7:
    // 0x8009EB38: addiu       $t3, $zero, -0x59
    ctx->r11 = ADD32(0, -0X59);
    // 0x8009EB3C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8009EB40: addiu       $s5, $s5, 0x32
    ctx->r21 = ADD32(ctx->r21, 0X32);
    // 0x8009EB44: addiu       $t5, $zero, 0x5F
    ctx->r13 = ADD32(0, 0X5F);
    // 0x8009EB48: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009EB4C: subu        $t6, $t5, $s5
    ctx->r14 = SUB32(ctx->r13, ctx->r21);
    // 0x8009EB50: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8009EB54: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8009EB58: swc1        $f16, 0x1EC($t4)
    MEM_W(0X1EC, ctx->r12) = ctx->f16.u32l;
    // 0x8009EB5C: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009EB60: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8009EB64: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8009EB68: swc1        $f20, 0x1F0($t7)
    MEM_W(0X1F0, ctx->r15) = ctx->f20.u32l;
    // 0x8009EB6C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8009EB70: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8009EB74: lbu         $t9, 0x17($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X17);
    // 0x8009EB78: jal         0x8009CFA4
    // 0x8009EB7C: sh          $t9, 0x1F8($t0)
    MEM_H(0X1F8, ctx->r8) = ctx->r25;
    menu_element_render(rdram, ctx);
        goto after_8;
    // 0x8009EB7C: sh          $t9, 0x1F8($t0)
    MEM_H(0X1F8, ctx->r8) = ctx->r25;
    after_8:
    // 0x8009EB80: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009EB84: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8009EB88: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8009EB8C: swc1        $f4, 0x20C($t1)
    MEM_W(0X20C, ctx->r9) = ctx->f4.u32l;
    // 0x8009EB90: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009EB94: nop

    // 0x8009EB98: swc1        $f20, 0x210($t2)
    MEM_W(0X210, ctx->r10) = ctx->f20.u32l;
    // 0x8009EB9C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8009EBA0: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8009EBA4: lbu         $t4, 0x16($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X16);
    // 0x8009EBA8: jal         0x8009CFA4
    // 0x8009EBAC: sh          $t4, 0x218($t5)
    MEM_H(0X218, ctx->r13) = ctx->r12;
    menu_element_render(rdram, ctx);
        goto after_9;
    // 0x8009EBAC: sh          $t4, 0x218($t5)
    MEM_H(0X218, ctx->r13) = ctx->r12;
    after_9:
    // 0x8009EBB0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8009EBB4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8009EBB8: lhu         $v1, 0xE($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0XE);
    // 0x8009EBBC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8009EBC0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8009EBC4:
    // 0x8009EBC4: and         $t7, $v1, $v0
    ctx->r15 = ctx->r3 & ctx->r2;
    // 0x8009EBC8: bne         $v0, $t7, L_8009EBD4
    if (ctx->r2 != ctx->r15) {
        // 0x8009EBCC: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_8009EBD4;
    }
    // 0x8009EBCC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8009EBD0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8009EBD4:
    // 0x8009EBD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009EBD8: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x8009EBDC: bne         $at, $zero, L_8009EBC4
    if (ctx->r1 != 0) {
        // 0x8009EBE0: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8009EBC4;
    }
    // 0x8009EBE0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8009EBE4: addiu       $s5, $s5, 0x32
    ctx->r21 = ADD32(ctx->r21, 0X32);
    // 0x8009EBE8: addiu       $t9, $zero, 0x5F
    ctx->r25 = ADD32(0, 0X5F);
    // 0x8009EBEC: subu        $t0, $t9, $s5
    ctx->r8 = SUB32(ctx->r25, ctx->r21);
    // 0x8009EBF0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8009EBF4: addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
    // 0x8009EBF8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009EBFC: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
L_8009EC00:
    // 0x8009EC00: addiu       $t1, $s1, -0x7C
    ctx->r9 = ADD32(ctx->r17, -0X7C);
    // 0x8009EC04: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8009EC08: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009EC0C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009EC10: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8009EC14: swc1        $f10, 0x1AC($t2)
    MEM_W(0X1AC, ctx->r10) = ctx->f10.u32l;
    // 0x8009EC18: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8009EC1C: beq         $at, $zero, L_8009EC30
    if (ctx->r1 == 0) {
        // 0x8009EC20: swc1        $f20, 0x1B0($t3)
        MEM_W(0X1B0, ctx->r11) = ctx->f20.u32l;
            goto L_8009EC30;
    }
    // 0x8009EC20: swc1        $f20, 0x1B0($t3)
    MEM_W(0X1B0, ctx->r11) = ctx->f20.u32l;
    // 0x8009EC24: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8009EC28: b           L_8009EC3C
    // 0x8009EC2C: sh          $s4, 0x1B8($t4)
    MEM_H(0X1B8, ctx->r12) = ctx->r20;
        goto L_8009EC3C;
    // 0x8009EC2C: sh          $s4, 0x1B8($t4)
    MEM_H(0X1B8, ctx->r12) = ctx->r20;
L_8009EC30:
    // 0x8009EC30: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8009EC34: nop

    // 0x8009EC38: sh          $zero, 0x1B8($t5)
    MEM_H(0X1B8, ctx->r13) = 0;
L_8009EC3C:
    // 0x8009EC3C: jal         0x8009CFA4
    // 0x8009EC40: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    menu_element_render(rdram, ctx);
        goto after_10;
    // 0x8009EC40: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_10:
    // 0x8009EC44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009EC48: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009EC4C: bne         $at, $zero, L_8009EC00
    if (ctx->r1 != 0) {
        // 0x8009EC50: addiu       $s1, $s1, 0x1E
        ctx->r17 = ADD32(ctx->r17, 0X1E);
            goto L_8009EC00;
    }
    // 0x8009EC50: addiu       $s1, $s1, 0x1E
    ctx->r17 = ADD32(ctx->r17, 0X1E);
    // 0x8009EC54: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8009EC58: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8009EC5C: lhu         $v1, 0x8($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X8);
    // 0x8009EC60: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8009EC64: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8009EC68:
    // 0x8009EC68: and         $t7, $v1, $v0
    ctx->r15 = ctx->r3 & ctx->r2;
    // 0x8009EC6C: bne         $v0, $t7, L_8009EC78
    if (ctx->r2 != ctx->r15) {
        // 0x8009EC70: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_8009EC78;
    }
    // 0x8009EC70: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8009EC74: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8009EC78:
    // 0x8009EC78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009EC7C: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x8009EC80: bne         $at, $zero, L_8009EC68
    if (ctx->r1 != 0) {
        // 0x8009EC84: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8009EC68;
    }
    // 0x8009EC84: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8009EC88: addiu       $s5, $s5, 0x2D
    ctx->r21 = ADD32(ctx->r21, 0X2D);
    // 0x8009EC8C: addiu       $t9, $zero, 0x5F
    ctx->r25 = ADD32(0, 0X5F);
    // 0x8009EC90: subu        $t0, $t9, $s5
    ctx->r8 = SUB32(ctx->r25, ctx->r21);
    // 0x8009EC94: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8009EC98: addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
    // 0x8009EC9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009ECA0: cvt.s.w     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = CVT_S_W(ctx->f16.u32l);
L_8009ECA4:
    // 0x8009ECA4: addiu       $t1, $s1, -0x7C
    ctx->r9 = ADD32(ctx->r17, -0X7C);
    // 0x8009ECA8: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8009ECAC: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009ECB0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009ECB4: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8009ECB8: swc1        $f4, 0x1CC($t2)
    MEM_W(0X1CC, ctx->r10) = ctx->f4.u32l;
    // 0x8009ECBC: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8009ECC0: beq         $at, $zero, L_8009ECD4
    if (ctx->r1 == 0) {
        // 0x8009ECC4: swc1        $f20, 0x1D0($t3)
        MEM_W(0X1D0, ctx->r11) = ctx->f20.u32l;
            goto L_8009ECD4;
    }
    // 0x8009ECC4: swc1        $f20, 0x1D0($t3)
    MEM_W(0X1D0, ctx->r11) = ctx->f20.u32l;
    // 0x8009ECC8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8009ECCC: b           L_8009ECE0
    // 0x8009ECD0: sh          $s4, 0x1D8($t4)
    MEM_H(0X1D8, ctx->r12) = ctx->r20;
        goto L_8009ECE0;
    // 0x8009ECD0: sh          $s4, 0x1D8($t4)
    MEM_H(0X1D8, ctx->r12) = ctx->r20;
L_8009ECD4:
    // 0x8009ECD4: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8009ECD8: nop

    // 0x8009ECDC: sh          $zero, 0x1D8($t5)
    MEM_H(0X1D8, ctx->r13) = 0;
L_8009ECE0:
    // 0x8009ECE0: jal         0x8009CFA4
    // 0x8009ECE4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    menu_element_render(rdram, ctx);
        goto after_11;
    // 0x8009ECE4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_11:
    // 0x8009ECE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009ECEC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009ECF0: bne         $s0, $at, L_8009ECA4
    if (ctx->r16 != ctx->r1) {
        // 0x8009ECF4: addiu       $s1, $s1, 0x1E
        ctx->r17 = ADD32(ctx->r17, 0X1E);
            goto L_8009ECA4;
    }
    // 0x8009ECF4: addiu       $s1, $s1, 0x1E
    ctx->r17 = ADD32(ctx->r17, 0X1E);
    // 0x8009ECF8: jal         0x80068748
    // 0x8009ECFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_12;
    // 0x8009ECFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
L_8009ED00:
    // 0x8009ED00: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8009ED04: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8009ED08: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8009ED0C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8009ED10: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8009ED14: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8009ED18: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8009ED1C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8009ED20: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8009ED24: jr          $ra
    // 0x8009ED28: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8009ED28: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void weather_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB750: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AB754: addiu       $v1, $v1, 0x2E68
    ctx->r3 = ADD32(ctx->r3, 0X2E68);
    // 0x800AB758: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AB75C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800AB760: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB764: sw          $zero, 0x2E64($at)
    MEM_W(0X2E64, ctx->r1) = 0;
    // 0x800AB768: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AB76C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AB770: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800AB774: addiu       $v0, $v0, -0x7E40
    ctx->r2 = ADD32(ctx->r2, -0X7E40);
    // 0x800AB778: sw          $zero, -0x7E90($at)
    MEM_W(-0X7E90, ctx->r1) = 0;
    // 0x800AB77C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800AB780: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AB784: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AB788: sra         $t0, $t8, 1
    ctx->r8 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AB78C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AB790: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AB794: sw          $t0, -0x7E3C($at)
    MEM_W(-0X7E3C, ctx->r1) = ctx->r8;
    // 0x800AB798: addiu       $a0, $a0, 0x2EA4
    ctx->r4 = ADD32(ctx->r4, 0X2EA4);
    // 0x800AB79C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800AB7A0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800AB7A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB7A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800AB7AC: sw          $zero, 0x2E9C($at)
    MEM_W(0X2E9C, ctx->r1) = 0;
    // 0x800AB7B0: addiu       $a1, $a1, -0x7E48
    ctx->r5 = ADD32(ctx->r5, -0X7E48);
    // 0x800AB7B4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800AB7B8: addiu       $t1, $zero, -0x200
    ctx->r9 = ADD32(0, -0X200);
    // 0x800AB7BC: sh          $a2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r6;
    // 0x800AB7C0: sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
    // 0x800AB7C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB7C8: sw          $zero, 0x3010($at)
    MEM_W(0X3010, ctx->r1) = 0;
    // 0x800AB7CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB7D0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800AB7D4: sw          $t2, 0x3014($at)
    MEM_W(0X3014, ctx->r1) = ctx->r10;
    // 0x800AB7D8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AB7DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB7E0: addiu       $a3, $a3, 0x2EAC
    ctx->r7 = ADD32(ctx->r7, 0X2EAC);
    // 0x800AB7E4: sw          $zero, 0x3018($at)
    MEM_W(0X3018, ctx->r1) = 0;
    // 0x800AB7E8: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800AB7EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AB7F0: bne         $t3, $zero, L_800AB854
    if (ctx->r11 != 0) {
        // 0x800AB7F4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AB854;
    }
    // 0x800AB7F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AB7F8: jal         0x80076EE4
    // 0x800AB7FC: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x800AB7FC: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_0:
    // 0x800AB800: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AB804: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AB808: addiu       $a3, $a3, 0x2EAC
    ctx->r7 = ADD32(ctx->r7, 0X2EAC);
    // 0x800AB80C: addiu       $a0, $a0, 0x2EB0
    ctx->r4 = ADD32(ctx->r4, 0X2EB0);
    // 0x800AB810: sll         $t4, $zero, 2
    ctx->r12 = S32(0 << 2);
    // 0x800AB814: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800AB818: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800AB81C: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x800AB820: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800AB824: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800AB828: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800AB82C: beq         $a2, $t6, L_800AB854
    if (ctx->r6 == ctx->r14) {
        // 0x800AB830: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AB854;
    }
    // 0x800AB830: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AB834: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
L_800AB838:
    // 0x800AB838: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AB83C: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800AB840: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800AB844: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800AB848: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800AB84C: bne         $a2, $t0, L_800AB838
    if (ctx->r6 != ctx->r8) {
        // 0x800AB850: addiu       $t7, $v1, 0x1
        ctx->r15 = ADD32(ctx->r3, 0X1);
            goto L_800AB838;
    }
    // 0x800AB850: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
L_800AB854:
    // 0x800AB854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AB858: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AB85C: sw          $zero, -0x7E38($at)
    MEM_W(-0X7E38, ctx->r1) = 0;
    // 0x800AB860: jr          $ra
    // 0x800AB864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AB864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
