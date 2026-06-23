#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80060910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060B50: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80060B54: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80060B58: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80060B5C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80060B60: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80060B64: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80060B68: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80060B6C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80060B70: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80060B74: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80060B78: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80060B7C: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // 0x80060B80: lh          $a1, 0x28($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X28);
    // 0x80060B84: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80060B88: blez        $a1, L_80060CD8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80060B8C: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80060CD8;
    }
    // 0x80060B8C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80060B90: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80060B94: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x80060B98: addiu       $s7, $sp, 0x60
    ctx->r23 = ADD32(ctx->r29, 0X60);
    // 0x80060B9C: addiu       $s6, $sp, 0x5C
    ctx->r22 = ADD32(ctx->r29, 0X5C);
L_80060BA0:
    // 0x80060BA0: lw          $t6, 0x38($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X38);
    // 0x80060BA4: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80060BA8: sll         $t4, $s4, 3
    ctx->r12 = S32(ctx->r20 << 3);
    // 0x80060BAC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80060BB0: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x80060BB4: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80060BB8: lh          $s5, 0x2($v0)
    ctx->r21 = MEM_H(ctx->r2, 0X2);
    // 0x80060BBC: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x80060BC0: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80060BC4: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x80060BC8: andi        $t1, $t9, 0x200
    ctx->r9 = ctx->r25 & 0X200;
    // 0x80060BCC: beq         $t1, $zero, L_80060BDC
    if (ctx->r9 == 0) {
        // 0x80060BD0: lw          $t3, 0x78($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X78);
            goto L_80060BDC;
    }
    // 0x80060BD0: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80060BD4: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    // 0x80060BD8: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80060BDC:
    // 0x80060BDC: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x80060BE0: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80060BE4: beq         $at, $zero, L_80060CBC
    if (ctx->r1 == 0) {
        // 0x80060BE8: lw          $t7, 0x88($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X88);
            goto L_80060CBC;
    }
    // 0x80060BE8: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x80060BEC: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
L_80060BF0:
    // 0x80060BF0: lw          $t5, 0xC($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XC);
    // 0x80060BF4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80060BF8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80060BFC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80060C00: sh          $s4, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r20;
    // 0x80060C04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80060C08:
    // 0x80060C08: addiu       $s1, $v1, 0x1
    ctx->r17 = ADD32(ctx->r3, 0X1);
    // 0x80060C0C: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x80060C10: bne         $at, $zero, L_80060C1C
    if (ctx->r1 != 0) {
        // 0x80060C14: or          $t0, $s1, $zero
        ctx->r8 = ctx->r17 | 0;
            goto L_80060C1C;
    }
    // 0x80060C14: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x80060C18: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80060C1C:
    // 0x80060C1C: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
    // 0x80060C20: sll         $t9, $s3, 4
    ctx->r25 = S32(ctx->r19 << 4);
    // 0x80060C24: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80060C28: addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    // 0x80060C2C: addu        $t3, $v0, $t0
    ctx->r11 = ADD32(ctx->r2, ctx->r8);
    // 0x80060C30: lbu         $t2, 0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1);
    // 0x80060C34: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x80060C38: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x80060C3C: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x80060C40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80060C44: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80060C48: addu        $a2, $t2, $s5
    ctx->r6 = ADD32(ctx->r10, ctx->r21);
    // 0x80060C4C: jal         0x80060D08
    // 0x80060C50: addu        $a3, $t4, $s5
    ctx->r7 = ADD32(ctx->r12, ctx->r21);
    func_80060AC8(rdram, ctx);
        goto after_0;
    // 0x80060C50: addu        $a3, $t4, $s5
    ctx->r7 = ADD32(ctx->r12, ctx->r21);
    after_0:
    // 0x80060C54: beq         $v0, $fp, L_80060C74
    if (ctx->r2 == ctx->r30) {
        // 0x80060C58: or          $v1, $s1, $zero
        ctx->r3 = ctx->r17 | 0;
            goto L_80060C74;
    }
    // 0x80060C58: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80060C5C: lw          $t5, 0xC($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XC);
    // 0x80060C60: sll         $t6, $s4, 3
    ctx->r14 = S32(ctx->r20 << 3);
    // 0x80060C64: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80060C68: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80060C6C: b           L_80060C88
    // 0x80060C70: sh          $v0, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r2;
        goto L_80060C88;
    // 0x80060C70: sh          $v0, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r2;
L_80060C74:
    // 0x80060C74: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x80060C78: sll         $t1, $s4, 3
    ctx->r9 = S32(ctx->r20 << 3);
    // 0x80060C7C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80060C80: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80060C84: sh          $s4, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r20;
L_80060C88:
    // 0x80060C88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80060C8C: bne         $s1, $at, L_80060C08
    if (ctx->r17 != ctx->r1) {
        // 0x80060C90: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80060C08;
    }
    // 0x80060C90: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80060C94: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80060C98: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80060C9C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80060CA0: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80060CA4: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    // 0x80060CA8: bne         $s3, $t6, L_80060BF0
    if (ctx->r19 != ctx->r14) {
        // 0x80060CAC: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80060BF0;
    }
    // 0x80060CAC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80060CB0: lh          $a1, 0x28($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X28);
    // 0x80060CB4: nop

    // 0x80060CB8: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
L_80060CBC:
    // 0x80060CBC: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80060CC0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80060CC4: slt         $at, $t8, $a1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80060CC8: addiu       $t1, $t9, 0xC
    ctx->r9 = ADD32(ctx->r25, 0XC);
    // 0x80060CCC: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x80060CD0: bne         $at, $zero, L_80060BA0
    if (ctx->r1 != 0) {
        // 0x80060CD4: sw          $t8, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r24;
            goto L_80060BA0;
    }
    // 0x80060CD4: sw          $t8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r24;
L_80060CD8:
    // 0x80060CD8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80060CDC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80060CE0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80060CE4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80060CE8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80060CEC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80060CF0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80060CF4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80060CF8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80060CFC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80060D00: jr          $ra
    // 0x80060D04: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80060D04: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void obj_init_emitter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FAC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000FAC8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000FACC: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8000FAD0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8000FAD4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8000FAD8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8000FADC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x8000FAE0: sw          $a1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r5;
    // 0x8000FAE4: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
    // 0x8000FAE8: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x8000FAEC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000FAF0: blez        $v1, L_8000FB9C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000FAF4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000FB9C;
    }
    // 0x8000FAF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000FAF8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8000FAFC: lui         $s3, 0xFFFF
    ctx->r19 = S32(0XFFFF << 16);
L_8000FB00:
    // 0x8000FB00: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8000FB04: sll         $t1, $s0, 5
    ctx->r9 = S32(ctx->r16 << 5);
    // 0x8000FB08: and         $t6, $v0, $s3
    ctx->r14 = ctx->r2 & ctx->r19;
    // 0x8000FB0C: bne         $s3, $t6, L_8000FB3C
    if (ctx->r19 != ctx->r14) {
        // 0x8000FB10: sra         $a1, $v0, 24
        ctx->r5 = S32(SIGNED(ctx->r2) >> 24);
            goto L_8000FB3C;
    }
    // 0x8000FB10: sra         $a1, $v0, 24
    ctx->r5 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8000FB14: lw          $t7, 0x6C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X6C);
    // 0x8000FB18: sra         $a1, $v0, 8
    ctx->r5 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8000FB1C: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x8000FB20: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x8000FB24: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8000FB28: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x8000FB2C: jal         0x800AF740
    // 0x8000FB30: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    emitter_init(rdram, ctx);
        goto after_0;
    // 0x8000FB30: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x8000FB34: b           L_8000FB84
    // 0x8000FB38: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
        goto L_8000FB84;
    // 0x8000FB38: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
L_8000FB3C:
    // 0x8000FB3C: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x8000FB40: lw          $t0, 0x6C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X6C);
    // 0x8000FB44: sra         $a2, $v0, 16
    ctx->r6 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000FB48: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8000FB4C: sra         $t6, $v1, 16
    ctx->r14 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000FB50: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8000FB54: sll         $t4, $a3, 16
    ctx->r12 = S32(ctx->r7 << 16);
    // 0x8000FB58: andi        $t3, $a2, 0xFF
    ctx->r11 = ctx->r6 & 0XFF;
    // 0x8000FB5C: andi        $t2, $a1, 0xFF
    ctx->r10 = ctx->r5 & 0XFF;
    // 0x8000FB60: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x8000FB64: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8000FB68: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8000FB6C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8000FB70: sra         $a3, $t4, 16
    ctx->r7 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8000FB74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8000FB78: jal         0x800AF7FC
    // 0x8000FB7C: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    emitter_init_with_pos(rdram, ctx);
        goto after_1;
    // 0x8000FB7C: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_1:
    // 0x8000FB80: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
L_8000FB84:
    // 0x8000FB84: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000FB88: lb          $v1, 0x57($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X57);
    // 0x8000FB8C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000FB90: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000FB94: bne         $at, $zero, L_8000FB00
    if (ctx->r1 != 0) {
        // 0x8000FB98: nop
    
            goto L_8000FB00;
    }
    // 0x8000FB98: nop

L_8000FB9C:
    // 0x8000FB9C: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x8000FBA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FBA4: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8000FBA8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8000FBAC: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x8000FBB0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FBB4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8000FBB8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8000FBBC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8000FBC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8000FBC4: jr          $ra
    // 0x8000FBC8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x8000FBC8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void ainode_tail(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D218: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001D21C: addiu       $v1, $v1, -0x4B78
    ctx->r3 = ADD32(ctx->r3, -0X4B78);
    // 0x8001D220: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8001D224: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001D228: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001D22C: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x8001D230: lw          $t7, -0x4B7C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4B7C);
    // 0x8001D234: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001D238: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8001D23C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8001D240: jr          $ra
    // 0x8001D244: nop

    return;
    // 0x8001D244: nop

;}
RECOMP_FUNC void reset_rocket_sound_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F110: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003F114: jr          $ra
    // 0x8003F118: sw          $zero, -0x25A4($at)
    MEM_W(-0X25A4, ctx->r1) = 0;
    return;
    // 0x8003F118: sw          $zero, -0x25A4($at)
    MEM_W(-0X25A4, ctx->r1) = 0;
;}
RECOMP_FUNC void obj_loop_lavaspurt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800375D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800375D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800375DC: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x800375E0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800375E4: blez        $v0, L_80037604
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800375E8: sll         $t2, $a1, 2
        ctx->r10 = S32(ctx->r5 << 2);
            goto L_80037604;
    }
    // 0x800375E8: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x800375EC: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800375F0: subu        $t6, $v0, $a1
    ctx->r14 = SUB32(ctx->r2, ctx->r5);
    // 0x800375F4: ori         $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 | 0X4000;
    // 0x800375F8: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    // 0x800375FC: b           L_80037654
    // 0x80037600: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
        goto L_80037654;
    // 0x80037600: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
L_80037604:
    // 0x80037604: lh          $t1, 0x18($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X18);
    // 0x80037608: lh          $t9, 0x6($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X6);
    // 0x8003760C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80037610: sh          $t3, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r11;
    // 0x80037614: lh          $t4, 0x18($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X18);
    // 0x80037618: andi        $t0, $t9, 0xBFFF
    ctx->r8 = ctx->r25 & 0XBFFF;
    // 0x8003761C: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    // 0x80037620: bne         $at, $zero, L_80037654
    if (ctx->r1 != 0) {
        // 0x80037624: sh          $t0, 0x6($a2)
        MEM_H(0X6, ctx->r6) = ctx->r8;
            goto L_80037654;
    }
    // 0x80037624: sh          $t0, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r8;
    // 0x80037628: sh          $zero, 0x18($a2)
    MEM_H(0X18, ctx->r6) = 0;
    // 0x8003762C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80037630: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80037634: jal         0x8006FB8C
    // 0x80037638: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x80037638: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_0:
    // 0x8003763C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80037640: nop

    // 0x80037644: lw          $t5, 0x7C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X7C);
    // 0x80037648: nop

    // 0x8003764C: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80037650: sw          $t6, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r14;
L_80037654:
    // 0x80037654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003765C: jr          $ra
    // 0x80037660: nop

    return;
    // 0x80037660: nop

;}
RECOMP_FUNC void mark_save_file_to_erase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EEEC: andi        $t6, $a0, 0x3
    ctx->r14 = ctx->r4 & 0X3;
    // 0x8006EEF0: sll         $t7, $t6, 10
    ctx->r15 = S32(ctx->r14 << 10);
    // 0x8006EEF4: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x8006EEF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006EEFC: jr          $ra
    // 0x8006EF00: sw          $t8, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = ctx->r24;
    return;
    // 0x8006EF00: sw          $t8, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void fb_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A91C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007A920: lw          $v0, 0x686C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X686C);
    // 0x8007A924: jr          $ra
    // 0x8007A928: nop

    return;
    // 0x8007A928: nop

;}
RECOMP_FUNC void trophy_race_cabinet_menu_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009ED2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009ED30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009ED34: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x8009ED38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009ED3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009ED40: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8009ED44: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009ED48: jal         0x800C543C
    // 0x8009ED4C: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_0;
    // 0x8009ED4C: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    after_0:
    // 0x8009ED50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009ED54: jal         0x800C54DC
    // 0x8009ED58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_1;
    // 0x8009ED58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8009ED5C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8009ED60: jal         0x8006A794
    // 0x8009ED64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_2;
    // 0x8009ED64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8009ED68: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009ED6C: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x8009ED70: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8009ED74: lw          $a3, 0x118($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X118);
    // 0x8009ED78: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009ED7C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8009ED80: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009ED84: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009ED88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009ED8C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009ED90: jal         0x800C56C8
    // 0x8009ED94: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_3;
    // 0x8009ED94: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_3:
    // 0x8009ED98: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009ED9C: lb          $v1, 0x6A04($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A04);
    // 0x8009EDA0: nop

    // 0x8009EDA4: bgez        $v1, L_8009EDC8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8009EDA8: nop
    
            goto L_8009EDC8;
    }
    // 0x8009EDA8: nop

    // 0x8009EDAC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EDB0: addiu       $v1, $v1, 0x6A78
    ctx->r3 = ADD32(ctx->r3, 0X6A78);
    // 0x8009EDB4: lb          $t0, 0x0($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X0);
    // 0x8009EDB8: nop

    // 0x8009EDBC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8009EDC0: b           L_8009EDE4
    // 0x8009EDC4: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
        goto L_8009EDE4;
    // 0x8009EDC4: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
L_8009EDC8:
    // 0x8009EDC8: blez        $v1, L_8009EDE4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009EDCC: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009EDE4;
    }
    // 0x8009EDCC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EDD0: addiu       $v1, $v1, 0x6A78
    ctx->r3 = ADD32(ctx->r3, 0X6A78);
    // 0x8009EDD4: lb          $t2, 0x0($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X0);
    // 0x8009EDD8: nop

    // 0x8009EDDC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8009EDE0: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
L_8009EDE4:
    // 0x8009EDE4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EDE8: addiu       $v1, $v1, 0x6A78
    ctx->r3 = ADD32(ctx->r3, 0X6A78);
    // 0x8009EDEC: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009EDF0: nop

    // 0x8009EDF4: bgez        $v0, L_8009EE0C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009EDF8: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_8009EE0C;
    }
    // 0x8009EDF8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8009EDFC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8009EE00: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009EE04: nop

    // 0x8009EE08: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_8009EE0C:
    // 0x8009EE0C: bne         $at, $zero, L_8009EE20
    if (ctx->r1 != 0) {
        // 0x8009EE10: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8009EE20;
    }
    // 0x8009EE10: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009EE14: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
    // 0x8009EE18: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009EE1C: nop

L_8009EE20:
    // 0x8009EE20: jal         0x8009D65C
    // 0x8009EE24: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
    set_option_text_colour(rdram, ctx);
        goto after_4;
    // 0x8009EE24: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
    after_4:
    // 0x8009EE28: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009EE2C: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009EE30: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009EE34: lw          $a3, 0x2D0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X2D0);
    // 0x8009EE38: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8009EE3C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009EE40: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009EE44: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009EE48: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009EE4C: jal         0x800C56C8
    // 0x8009EE50: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    render_dialogue_text(rdram, ctx);
        goto after_5;
    // 0x8009EE50: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_5:
    // 0x8009EE54: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EE58: addiu       $v1, $v1, 0x6A78
    ctx->r3 = ADD32(ctx->r3, 0X6A78);
    // 0x8009EE5C: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x8009EE60: nop

    // 0x8009EE64: xori        $t8, $a0, 0x1
    ctx->r24 = ctx->r4 ^ 0X1;
    // 0x8009EE68: jal         0x8009D65C
    // 0x8009EE6C: sltiu       $a0, $t8, 0x1
    ctx->r4 = ctx->r24 < 0X1 ? 1 : 0;
    set_option_text_colour(rdram, ctx);
        goto after_6;
    // 0x8009EE6C: sltiu       $a0, $t8, 0x1
    ctx->r4 = ctx->r24 < 0X1 ? 1 : 0;
    after_6:
    // 0x8009EE70: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009EE74: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x8009EE78: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8009EE7C: lw          $a3, 0xCC($t9)
    ctx->r7 = MEM_W(ctx->r25, 0XCC);
    // 0x8009EE80: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8009EE84: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8009EE88: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8009EE8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009EE90: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009EE94: jal         0x800C56C8
    // 0x8009EE98: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    render_dialogue_text(rdram, ctx);
        goto after_7;
    // 0x8009EE98: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_7:
    // 0x8009EE9C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8009EEA0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EEA4: andi        $t2, $a1, 0x8000
    ctx->r10 = ctx->r5 & 0X8000;
    // 0x8009EEA8: beq         $t2, $zero, L_8009EEC0
    if (ctx->r10 == 0) {
        // 0x8009EEAC: addiu       $v1, $v1, 0x6A78
        ctx->r3 = ADD32(ctx->r3, 0X6A78);
            goto L_8009EEC0;
    }
    // 0x8009EEAC: addiu       $v1, $v1, 0x6A78
    ctx->r3 = ADD32(ctx->r3, 0X6A78);
    // 0x8009EEB0: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x8009EEB4: nop

    // 0x8009EEB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8009EEBC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
L_8009EEC0:
    // 0x8009EEC0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8009EEC4: andi        $t3, $a1, 0x4000
    ctx->r11 = ctx->r5 & 0X4000;
    // 0x8009EEC8: beq         $t3, $zero, L_8009EED8
    if (ctx->r11 == 0) {
        // 0x8009EECC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009EED8;
    }
    // 0x8009EECC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009EED0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8009EED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009EED8:
    // 0x8009EED8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009EEDC: jr          $ra
    // 0x8009EEE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8009EEE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void menu_character_select_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B484: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008B488: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008B48C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008B490: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008B494: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008B498: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008B49C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008B4A0: jal         0x8006A674
    // 0x8008B4A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    input_assign_players(rdram, ctx);
        goto after_0;
    // 0x8008B4A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x8008B4A8: jal         0x8009F214
    // 0x8008B4AC: nop

    is_drumstick_unlocked(rdram, ctx);
        goto after_1;
    // 0x8008B4AC: nop

    after_1:
    // 0x8008B4B0: beq         $v0, $zero, L_8008B4F4
    if (ctx->r2 == 0) {
        // 0x8008B4B4: nop
    
            goto L_8008B4F4;
    }
    // 0x8008B4B4: nop

    // 0x8008B4B8: jal         0x8009F1FC
    // 0x8008B4BC: nop

    is_tt_unlocked(rdram, ctx);
        goto after_2;
    // 0x8008B4BC: nop

    after_2:
    // 0x8008B4C0: beq         $v0, $zero, L_8008B4E0
    if (ctx->r2 == 0) {
        // 0x8008B4C4: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_8008B4E0;
    }
    // 0x8008B4C4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008B4C8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008B4CC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008B4D0: addiu       $a3, $a3, 0x696C
    ctx->r7 = ADD32(ctx->r7, 0X696C);
    // 0x8008B4D4: addiu       $t6, $t6, 0x4C0
    ctx->r14 = ADD32(ctx->r14, 0X4C0);
    // 0x8008B4D8: b           L_8008B52C
    // 0x8008B4DC: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
        goto L_8008B52C;
    // 0x8008B4DC: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
L_8008B4E0:
    // 0x8008B4E0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008B4E4: addiu       $a3, $a3, 0x696C
    ctx->r7 = ADD32(ctx->r7, 0X696C);
    // 0x8008B4E8: addiu       $t7, $t7, 0x3C0
    ctx->r15 = ADD32(ctx->r15, 0X3C0);
    // 0x8008B4EC: b           L_8008B52C
    // 0x8008B4F0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
        goto L_8008B52C;
    // 0x8008B4F0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
L_8008B4F4:
    // 0x8008B4F4: jal         0x8009F1FC
    // 0x8008B4F8: nop

    is_tt_unlocked(rdram, ctx);
        goto after_3;
    // 0x8008B4F8: nop

    after_3:
    // 0x8008B4FC: beq         $v0, $zero, L_8008B518
    if (ctx->r2 == 0) {
        // 0x8008B500: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_8008B518;
    }
    // 0x8008B500: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008B504: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008B508: addiu       $a3, $a3, 0x696C
    ctx->r7 = ADD32(ctx->r7, 0X696C);
    // 0x8008B50C: addiu       $t8, $t8, 0x440
    ctx->r24 = ADD32(ctx->r24, 0X440);
    // 0x8008B510: b           L_8008B52C
    // 0x8008B514: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
        goto L_8008B52C;
    // 0x8008B514: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_8008B518:
    // 0x8008B518: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008B51C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008B520: addiu       $a3, $a3, 0x696C
    ctx->r7 = ADD32(ctx->r7, 0X696C);
    // 0x8008B524: addiu       $t9, $t9, 0x350
    ctx->r25 = ADD32(ctx->r25, 0X350);
    // 0x8008B528: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
L_8008B52C:
    // 0x8008B52C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008B530: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008B534: addiu       $v1, $v1, 0x6980
    ctx->r3 = ADD32(ctx->r3, 0X6980);
    // 0x8008B538: addiu       $v0, $v0, 0x697C
    ctx->r2 = ADD32(ctx->r2, 0X697C);
L_8008B53C:
    // 0x8008B53C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008B540: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008B544: bne         $at, $zero, L_8008B53C
    if (ctx->r1 != 0) {
        // 0x8008B548: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_8008B53C;
    }
    // 0x8008B548: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x8008B54C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B550: sw          $zero, -0x600($at)
    MEM_W(-0X600, ctx->r1) = 0;
    // 0x8008B554: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B558: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8008B55C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B560: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x8008B564: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008B568: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B56C: addiu       $t0, $t0, 0x6974
    ctx->r8 = ADD32(ctx->r8, 0X6974);
    // 0x8008B570: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008B574: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008B578: sw          $zero, -0x5FC($at)
    MEM_W(-0X5FC, ctx->r1) = 0;
    // 0x8008B57C: addiu       $v1, $v1, 0x6988
    ctx->r3 = ADD32(ctx->r3, 0X6988);
    // 0x8008B580: addiu       $s2, $s2, 0x6960
    ctx->r18 = ADD32(ctx->r18, 0X6960);
    // 0x8008B584: addu        $v0, $zero, $t0
    ctx->r2 = ADD32(0, ctx->r8);
    // 0x8008B588: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008B58C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008B590: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x8008B594: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
L_8008B598:
    // 0x8008B598: lb          $t1, 0x0($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X0);
    // 0x8008B59C: addu        $t3, $v1, $s0
    ctx->r11 = ADD32(ctx->r3, ctx->r16);
    // 0x8008B5A0: beq         $t1, $zero, L_8008B5D0
    if (ctx->r9 == 0) {
        // 0x8008B5A4: nop
    
            goto L_8008B5D0;
    }
    // 0x8008B5A4: nop

    // 0x8008B5A8: lb          $t4, 0x0($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X0);
    // 0x8008B5AC: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x8008B5B0: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B5B4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8008B5B8: mflo        $t5
    ctx->r13 = lo;
    // 0x8008B5BC: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x8008B5C0: lh          $t7, 0xC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XC);
    // 0x8008B5C4: sh          $a1, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r5;
    // 0x8008B5C8: sb          $a2, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r6;
    // 0x8008B5CC: sb          $t7, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r15;
L_8008B5D0:
    // 0x8008B5D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008B5D4: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8008B5D8: beq         $at, $zero, L_8008B5E8
    if (ctx->r1 == 0) {
        // 0x8008B5DC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008B5E8;
    }
    // 0x8008B5DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008B5E0: beq         $s1, $zero, L_8008B598
    if (ctx->r17 == 0) {
        // 0x8008B5E4: nop
    
            goto L_8008B598;
    }
    // 0x8008B5E4: nop

L_8008B5E8:
    // 0x8008B5E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008B5EC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008B5F0: addiu       $v1, $v1, 0x6958
    ctx->r3 = ADD32(ctx->r3, 0X6958);
    // 0x8008B5F4: addiu       $v0, $v0, 0x6954
    ctx->r2 = ADD32(ctx->r2, 0X6954);
    // 0x8008B5F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008B5FC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008B600: addiu       $s2, $s2, 0x6960
    ctx->r18 = ADD32(ctx->r18, 0X6960);
    // 0x8008B604: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x8008B608: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8008B60C: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x8008B610: sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
    // 0x8008B614: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x8008B618: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x8008B61C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x8008B620: jal         0x80000B34
    // 0x8008B624: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    music_play(rdram, ctx);
        goto after_4;
    // 0x8008B624: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_4:
    // 0x8008B628: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8008B62C: addiu       $s3, $s3, 0x334
    ctx->r19 = ADD32(ctx->r19, 0X334);
    // 0x8008B630: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
L_8008B634:
    // 0x8008B634: lb          $t8, 0x0($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X0);
    // 0x8008B638: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x8008B63C: beq         $s0, $t8, L_8008B65C
    if (ctx->r16 == ctx->r24) {
        // 0x8008B640: addu        $s1, $s3, $t9
        ctx->r17 = ADD32(ctx->r19, ctx->r25);
            goto L_8008B65C;
    }
    // 0x8008B640: addu        $s1, $s3, $t9
    ctx->r17 = ADD32(ctx->r19, ctx->r25);
    // 0x8008B644: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x8008B648: jal         0x80001114
    // 0x8008B64C: nop

    music_channel_off(rdram, ctx);
        goto after_5;
    // 0x8008B64C: nop

    after_5:
    // 0x8008B650: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x8008B654: jal         0x80001114
    // 0x8008B658: nop

    music_channel_off(rdram, ctx);
        goto after_6;
    // 0x8008B658: nop

    after_6:
L_8008B65C:
    // 0x8008B65C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008B660: bne         $s0, $s4, L_8008B634
    if (ctx->r16 != ctx->r20) {
        // 0x8008B664: nop
    
            goto L_8008B634;
    }
    // 0x8008B664: nop

    // 0x8008B668: jal         0x80001114
    // 0x8008B66C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_channel_off(rdram, ctx);
        goto after_7;
    // 0x8008B66C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_7:
    // 0x8008B670: jal         0x80000B18
    // 0x8008B674: nop

    music_change_off(rdram, ctx);
        goto after_8;
    // 0x8008B674: nop

    after_8:
    // 0x8008B678: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008B67C: jal         0x8009CBB8
    // 0x8008B680: addiu       $a0, $a0, 0x348
    ctx->r4 = ADD32(ctx->r4, 0X348);
    menu_assetgroup_load(rdram, ctx);
        goto after_9;
    // 0x8008B680: addiu       $a0, $a0, 0x348
    ctx->r4 = ADD32(ctx->r4, 0X348);
    after_9:
    // 0x8008B684: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008B688: jal         0x8009CDE8
    // 0x8008B68C: addiu       $a0, $a0, 0x34C
    ctx->r4 = ADD32(ctx->r4, 0X34C);
    menu_imagegroup_load(rdram, ctx);
        goto after_10;
    // 0x8008B68C: addiu       $a0, $a0, 0x34C
    ctx->r4 = ADD32(ctx->r4, 0X34C);
    after_10:
    // 0x8008B690: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008B694: jal         0x800C06F8
    // 0x8008B698: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_11;
    // 0x8008B698: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_11:
    // 0x8008B69C: jal         0x800C46D0
    // 0x8008B6A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_12;
    // 0x8008B6A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_12:
    // 0x8008B6A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008B6A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008B6AC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B6B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008B6B4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008B6B8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008B6BC: jr          $ra
    // 0x8008B6C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8008B6C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void roll_percent_chance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044498: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004449C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800444A0: jal         0x8006FB8C
    // 0x800444A4: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x800444A4: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    after_0:
    // 0x800444A8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800444AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800444B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800444B4: jr          $ra
    // 0x800444B8: slt         $v0, $v0, $t6
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    return;
    // 0x800444B8: slt         $v0, $v0, $t6
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
;}
RECOMP_FUNC void check_if_showing_cutscene_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066750: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066754: lb          $v0, 0x1294($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X1294);
    // 0x80066758: jr          $ra
    // 0x8006675C: nop

    return;
    // 0x8006675C: nop

;}
RECOMP_FUNC void sound_play_delayed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000FDC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80000FE0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80000FE4: addiu       $a2, $a2, -0x3438
    ctx->r6 = ADD32(ctx->r6, -0X3438);
    // 0x80000FE8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80000FEC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80000FF0: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80000FF4: beq         $at, $zero, L_80001048
    if (ctx->r1 == 0) {
        // 0x80000FF8: andi        $t6, $a0, 0xFFFF
        ctx->r14 = ctx->r4 & 0XFFFF;
            goto L_80001048;
    }
    // 0x80000FF8: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80000FFC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80001000: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80001004: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80001008: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8000100C: addiu       $t8, $t8, 0x62C8
    ctx->r24 = ADD32(ctx->r24, 0X62C8);
    // 0x80001010: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80001014: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80001018: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000101C: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80001020: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80001024: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001028: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000102C: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x80001030: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80001034: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x80001038: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8000103C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80001040: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80001044: sh          $t0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r8;
L_80001048:
    // 0x80001048: jr          $ra
    // 0x8000104C: nop

    return;
    // 0x8000104C: nop

;}
RECOMP_FUNC void sound_volume_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000208C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002094: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80002098: beq         $a0, $zero, L_800020AC
    if (ctx->r4 == 0) {
        // 0x8000209C: andi        $a3, $a1, 0xFF
        ctx->r7 = ctx->r5 & 0XFF;
            goto L_800020AC;
    }
    // 0x8000209C: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    // 0x800020A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800020A4: jal         0x800049F8
    // 0x800020A8: sll         $a2, $a3, 8
    ctx->r6 = S32(ctx->r7 << 8);
    sndp_set_param(rdram, ctx);
        goto after_0;
    // 0x800020A8: sll         $a2, $a3, 8
    ctx->r6 = S32(ctx->r7 << 8);
    after_0:
L_800020AC:
    // 0x800020AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800020B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800020B4: jr          $ra
    // 0x800020B8: nop

    return;
    // 0x800020B8: nop

;}
RECOMP_FUNC void font_codes_to_string(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076BE4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80076BE8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80076BEC: beq         $v0, $zero, L_80076C40
    if (ctx->r2 == 0) {
        // 0x80076BF0: nop
    
            goto L_80076C40;
    }
    // 0x80076BF0: nop

    // 0x80076BF4: beq         $a2, $zero, L_80076C40
    if (ctx->r6 == 0) {
        // 0x80076BF8: addiu       $t0, $zero, 0x2D
        ctx->r8 = ADD32(0, 0X2D);
            goto L_80076C40;
    }
    // 0x80076BF8: addiu       $t0, $zero, 0x2D
    ctx->r8 = ADD32(0, 0X2D);
    // 0x80076BFC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80076C00: addiu       $a3, $a3, -0x164C
    ctx->r7 = ADD32(ctx->r7, -0X164C);
    // 0x80076C04: slti        $at, $v0, 0x42
    ctx->r1 = SIGNED(ctx->r2) < 0X42 ? 1 : 0;
L_80076C08:
    // 0x80076C08: beq         $at, $zero, L_80076C20
    if (ctx->r1 == 0) {
        // 0x80076C0C: addu        $t6, $a3, $v0
        ctx->r14 = ADD32(ctx->r7, ctx->r2);
            goto L_80076C20;
    }
    // 0x80076C0C: addu        $t6, $a3, $v0
    ctx->r14 = ADD32(ctx->r7, ctx->r2);
    // 0x80076C10: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80076C14: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80076C18: b           L_80076C28
    // 0x80076C1C: sb          $t7, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r15;
        goto L_80076C28;
    // 0x80076C1C: sb          $t7, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r15;
L_80076C20:
    // 0x80076C20: sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
    // 0x80076C24: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80076C28:
    // 0x80076C28: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x80076C2C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80076C30: beq         $v0, $zero, L_80076C40
    if (ctx->r2 == 0) {
        // 0x80076C34: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_80076C40;
    }
    // 0x80076C34: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80076C38: bne         $a2, $zero, L_80076C08
    if (ctx->r6 != 0) {
        // 0x80076C3C: slti        $at, $v0, 0x42
        ctx->r1 = SIGNED(ctx->r2) < 0X42 ? 1 : 0;
            goto L_80076C08;
    }
    // 0x80076C3C: slti        $at, $v0, 0x42
    ctx->r1 = SIGNED(ctx->r2) < 0X42 ? 1 : 0;
L_80076C40:
    // 0x80076C40: beq         $a2, $zero, L_80076C84
    if (ctx->r6 == 0) {
        // 0x80076C44: andi        $a0, $a2, 0x3
        ctx->r4 = ctx->r6 & 0X3;
            goto L_80076C84;
    }
    // 0x80076C44: andi        $a0, $a2, 0x3
    ctx->r4 = ctx->r6 & 0X3;
    // 0x80076C48: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80076C4C: beq         $a0, $zero, L_80076C68
    if (ctx->r4 == 0) {
        // 0x80076C50: addu        $v0, $a0, $a2
        ctx->r2 = ADD32(ctx->r4, ctx->r6);
            goto L_80076C68;
    }
    // 0x80076C50: addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
L_80076C54:
    // 0x80076C54: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80076C58: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076C5C: bne         $v0, $a2, L_80076C54
    if (ctx->r2 != ctx->r6) {
        // 0x80076C60: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80076C54;
    }
    // 0x80076C60: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80076C64: beq         $a2, $zero, L_80076C84
    if (ctx->r6 == 0) {
        // 0x80076C68: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80076C84;
    }
L_80076C68:
    // 0x80076C68: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80076C6C: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076C70: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x80076C74: sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
    // 0x80076C78: sb          $zero, 0x3($a1)
    MEM_B(0X3, ctx->r5) = 0;
    // 0x80076C7C: bne         $a2, $zero, L_80076C68
    if (ctx->r6 != 0) {
        // 0x80076C80: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80076C68;
    }
    // 0x80076C80: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80076C84:
    // 0x80076C84: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076C88: jr          $ra
    // 0x80076C8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80076C8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8001E6EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E720: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8001E724: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8001E728: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E72C: lb          $v1, -0x4C80($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X4C80);
    // 0x8001E730: sll         $s0, $a0, 24
    ctx->r16 = S32(ctx->r4 << 24);
    // 0x8001E734: sra         $t6, $s0, 24
    ctx->r14 = S32(SIGNED(ctx->r16) >> 24);
    // 0x8001E738: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8001E73C: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x8001E740: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x8001E744: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x8001E748: blez        $v1, L_8001E8B4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E74C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001E8B4;
    }
    // 0x8001E74C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E750: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001E754: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8001E758: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001E75C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001E760: addiu       $t4, $t4, -0x4C06
    ctx->r12 = ADD32(ctx->r12, -0X4C06);
    // 0x8001E764: addiu       $s1, $s1, -0x4C08
    ctx->r17 = ADD32(ctx->r17, -0X4C08);
    // 0x8001E768: addiu       $s2, $s2, -0x4C0C
    ctx->r18 = ADD32(ctx->r18, -0X4C0C);
    // 0x8001E76C: addiu       $a1, $a1, -0x4CA8
    ctx->r5 = ADD32(ctx->r5, -0X4CA8);
    // 0x8001E770: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
L_8001E774:
    // 0x8001E774: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8001E778: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    // 0x8001E77C: lw          $a2, 0x3C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X3C);
    // 0x8001E780: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x8001E784: lb          $t0, 0x9($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X9);
    // 0x8001E788: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E78C: beq         $t7, $t0, L_8001E79C
    if (ctx->r15 == ctx->r8) {
        // 0x8001E790: nop
    
            goto L_8001E79C;
    }
    // 0x8001E790: nop

    // 0x8001E794: bne         $t5, $t0, L_8001E8AC
    if (ctx->r13 != ctx->r8) {
        // 0x8001E798: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E8AC;
    }
    // 0x8001E798: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E79C:
    // 0x8001E79C: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
    // 0x8001E7A0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001E7A4: blez        $t1, L_8001E7F8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001E7A8: nop
    
            goto L_8001E7F8;
    }
    // 0x8001E7A8: nop

    // 0x8001E7AC: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8001E7B0: lb          $t2, 0x8($a2)
    ctx->r10 = MEM_B(ctx->r6, 0X8);
    // 0x8001E7B4: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x8001E7B8: nop

    // 0x8001E7BC: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x8001E7C0: nop

    // 0x8001E7C4: beq         $t2, $t9, L_8001E7F8
    if (ctx->r10 == ctx->r25) {
        // 0x8001E7C8: nop
    
            goto L_8001E7F8;
    }
    // 0x8001E7C8: nop

L_8001E7CC:
    // 0x8001E7CC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001E7D0: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001E7D4: beq         $at, $zero, L_8001E7F8
    if (ctx->r1 == 0) {
        // 0x8001E7D8: sll         $t6, $t0, 2
        ctx->r14 = S32(ctx->r8 << 2);
            goto L_8001E7F8;
    }
    // 0x8001E7D8: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8001E7DC: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x8001E7E0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001E7E4: nop

    // 0x8001E7E8: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x8001E7EC: nop

    // 0x8001E7F0: bne         $t2, $t9, L_8001E7CC
    if (ctx->r10 != ctx->r25) {
        // 0x8001E7F4: nop
    
            goto L_8001E7CC;
    }
    // 0x8001E7F4: nop

L_8001E7F8:
    // 0x8001E7F8: beq         $t0, $t1, L_8001E898
    if (ctx->r8 == ctx->r9) {
        // 0x8001E7FC: nop
    
            goto L_8001E898;
    }
    // 0x8001E7FC: nop

    // 0x8001E800: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8001E804: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8001E808: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001E80C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8001E810: nop

    // 0x8001E814: lw          $a2, 0x64($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X64);
    // 0x8001E818: nop

    // 0x8001E81C: beq         $a2, $zero, L_8001E898
    if (ctx->r6 == 0) {
        // 0x8001E820: nop
    
            goto L_8001E898;
    }
    // 0x8001E820: nop

    // 0x8001E824: lw          $t6, 0x5C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X5C);
    // 0x8001E828: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001E82C: beq         $t6, $zero, L_8001E83C
    if (ctx->r14 == 0) {
        // 0x8001E830: nop
    
            goto L_8001E83C;
    }
    // 0x8001E830: nop

    // 0x8001E834: b           L_8001E83C
    // 0x8001E838: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_8001E83C;
    // 0x8001E838: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8001E83C:
    // 0x8001E83C: beq         $s0, $t0, L_8001E8AC
    if (ctx->r16 == ctx->r8) {
        // 0x8001E840: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E8AC;
    }
    // 0x8001E840: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E844: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8001E848: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E84C: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x8001E850: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8001E854: nop

    // 0x8001E858: swc1        $f6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f6.u32l;
    // 0x8001E85C: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8001E860: sw          $a2, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r6;
    // 0x8001E864: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
    // 0x8001E868: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001E86C: nop

    // 0x8001E870: swc1        $f10, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f10.u32l;
    // 0x8001E874: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8001E878: nop

    // 0x8001E87C: swc1        $f16, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f16.u32l;
    // 0x8001E880: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8001E884: nop

    // 0x8001E888: swc1        $f18, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f18.u32l;
    // 0x8001E88C: lb          $v1, -0x4C80($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X4C80);
    // 0x8001E890: b           L_8001E8AC
    // 0x8001E894: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_8001E8AC;
    // 0x8001E894: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E898:
    // 0x8001E898: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x8001E89C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E8A0: lb          $v1, -0x4C80($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X4C80);
    // 0x8001E8A4: nop

    // 0x8001E8A8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E8AC:
    // 0x8001E8AC: bne         $at, $zero, L_8001E774
    if (ctx->r1 != 0) {
        // 0x8001E8B0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001E774;
    }
    // 0x8001E8B0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001E8B4:
    // 0x8001E8B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E8B8: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8001E8BC: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x8001E8C0: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x8001E8C4: sb          $zero, -0x4C7F($at)
    MEM_B(-0X4C7F, ctx->r1) = 0;
    // 0x8001E8C8: jr          $ra
    // 0x8001E8CC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8001E8CC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void load_fonts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C4164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C4168: jal         0x80076EE4
    // 0x800C416C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x800C416C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x800C4170: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C4174: addiu       $v1, $v1, -0x525C
    ctx->r3 = ADD32(ctx->r3, -0X525C);
    // 0x800C4178: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800C417C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C4180: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C4184: addiu       $a0, $a0, -0x5260
    ctx->r4 = ADD32(ctx->r4, -0X5260);
    // 0x800C4188: addiu       $t7, $v0, 0x4
    ctx->r15 = ADD32(ctx->r2, 0X4);
    // 0x800C418C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C4190: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C4194: blez        $t6, L_800C41C4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800C4198: sw          $t6, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r14;
            goto L_800C41C4;
    }
    // 0x800C4198: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C419C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C41A0:
    // 0x800C41A0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C41A4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C41A8: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C41AC: sb          $zero, 0x28($t3)
    MEM_B(0X28, ctx->r11) = 0;
    // 0x800C41B0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800C41B4: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // 0x800C41B8: slt         $at, $a1, $t4
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800C41BC: bne         $at, $zero, L_800C41A0
    if (ctx->r1 != 0) {
        // 0x800C41C0: nop
    
            goto L_800C41A0;
    }
    // 0x800C41C0: nop

L_800C41C4:
    // 0x800C41C4: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x800C41C8: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800C41CC: jal         0x80070EDC
    // 0x800C41D0: addiu       $a0, $zero, 0x940
    ctx->r4 = ADD32(0, 0X940);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800C41D0: addiu       $a0, $zero, 0x940
    ctx->r4 = ADD32(0, 0X940);
    after_1:
    // 0x800C41D4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C41D8: addiu       $a2, $a2, -0x5258
    ctx->r6 = ADD32(ctx->r6, -0X5258);
    // 0x800C41DC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C41E0: addiu       $t6, $v0, 0x140
    ctx->r14 = ADD32(ctx->r2, 0X140);
    // 0x800C41E4: addiu       $v1, $v1, -0x5254
    ctx->r3 = ADD32(ctx->r3, -0X5254);
    // 0x800C41E8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x800C41EC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C41F0: addiu       $v0, $zero, 0x13F
    ctx->r2 = ADD32(0, 0X13F);
    // 0x800C41F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C41F8: addiu       $t2, $zero, 0x4000
    ctx->r10 = ADD32(0, 0X4000);
    // 0x800C41FC: addiu       $t1, $zero, 0xF0
    ctx->r9 = ADD32(0, 0XF0);
    // 0x800C4200: addiu       $t0, $zero, 0x140
    ctx->r8 = ADD32(0, 0X140);
    // 0x800C4204: addiu       $a3, $zero, 0xEF
    ctx->r7 = ADD32(0, 0XEF);
    // 0x800C4208: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800C420C:
    // 0x800C420C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C4210: nop

    // 0x800C4214: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C4218: sh          $zero, 0x0($t8)
    MEM_H(0X0, ctx->r24) = 0;
    // 0x800C421C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C4220: nop

    // 0x800C4224: addu        $t3, $t9, $a1
    ctx->r11 = ADD32(ctx->r25, ctx->r5);
    // 0x800C4228: sh          $zero, 0x2($t3)
    MEM_H(0X2, ctx->r11) = 0;
    // 0x800C422C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C4230: nop

    // 0x800C4234: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x800C4238: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x800C423C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C4240: nop

    // 0x800C4244: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800C4248: sh          $zero, 0x6($t7)
    MEM_H(0X6, ctx->r15) = 0;
    // 0x800C424C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C4250: nop

    // 0x800C4254: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C4258: sh          $v0, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r2;
    // 0x800C425C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800C4260: nop

    // 0x800C4264: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800C4268: sh          $a3, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r7;
    // 0x800C426C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800C4270: nop

    // 0x800C4274: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x800C4278: sh          $t0, 0xC($t6)
    MEM_H(0XC, ctx->r14) = ctx->r8;
    // 0x800C427C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C4280: nop

    // 0x800C4284: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C4288: sh          $t1, 0xE($t8)
    MEM_H(0XE, ctx->r24) = ctx->r9;
    // 0x800C428C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C4290: nop

    // 0x800C4294: addu        $t3, $t9, $a1
    ctx->r11 = ADD32(ctx->r25, ctx->r5);
    // 0x800C4298: sb          $a0, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r4;
    // 0x800C429C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C42A0: nop

    // 0x800C42A4: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x800C42A8: sb          $a0, 0x11($t5)
    MEM_B(0X11, ctx->r13) = ctx->r4;
    // 0x800C42AC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C42B0: nop

    // 0x800C42B4: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800C42B8: sb          $a0, 0x12($t7)
    MEM_B(0X12, ctx->r15) = ctx->r4;
    // 0x800C42BC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C42C0: nop

    // 0x800C42C4: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C42C8: sb          $zero, 0x13($t9)
    MEM_B(0X13, ctx->r25) = 0;
    // 0x800C42CC: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800C42D0: nop

    // 0x800C42D4: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800C42D8: sb          $a0, 0x14($t4)
    MEM_B(0X14, ctx->r12) = ctx->r4;
    // 0x800C42DC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800C42E0: nop

    // 0x800C42E4: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x800C42E8: sb          $a0, 0x15($t6)
    MEM_B(0X15, ctx->r14) = ctx->r4;
    // 0x800C42EC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C42F0: nop

    // 0x800C42F4: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C42F8: sb          $a0, 0x16($t8)
    MEM_B(0X16, ctx->r24) = ctx->r4;
    // 0x800C42FC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C4300: nop

    // 0x800C4304: addu        $t3, $t9, $a1
    ctx->r11 = ADD32(ctx->r25, ctx->r5);
    // 0x800C4308: sb          $zero, 0x17($t3)
    MEM_B(0X17, ctx->r11) = 0;
    // 0x800C430C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C4310: nop

    // 0x800C4314: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x800C4318: sb          $a0, 0x18($t5)
    MEM_B(0X18, ctx->r13) = ctx->r4;
    // 0x800C431C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C4320: nop

    // 0x800C4324: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800C4328: sb          $a0, 0x19($t7)
    MEM_B(0X19, ctx->r15) = ctx->r4;
    // 0x800C432C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C4330: nop

    // 0x800C4334: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C4338: sb          $a0, 0x1A($t9)
    MEM_B(0X1A, ctx->r25) = ctx->r4;
    // 0x800C433C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800C4340: nop

    // 0x800C4344: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800C4348: sb          $zero, 0x1B($t4)
    MEM_B(0X1B, ctx->r12) = 0;
    // 0x800C434C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800C4350: nop

    // 0x800C4354: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x800C4358: sb          $a0, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r4;
    // 0x800C435C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C4360: nop

    // 0x800C4364: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C4368: beq         $a1, $zero, L_800C4384
    if (ctx->r5 == 0) {
        // 0x800C436C: sb          $a0, 0x1D($t8)
        MEM_B(0X1D, ctx->r24) = ctx->r4;
            goto L_800C4384;
    }
    // 0x800C436C: sb          $a0, 0x1D($t8)
    MEM_B(0X1D, ctx->r24) = ctx->r4;
    // 0x800C4370: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C4374: nop

    // 0x800C4378: addu        $t3, $t9, $a1
    ctx->r11 = ADD32(ctx->r25, ctx->r5);
    // 0x800C437C: b           L_800C4394
    // 0x800C4380: sh          $t2, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = ctx->r10;
        goto L_800C4394;
    // 0x800C4380: sh          $t2, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = ctx->r10;
L_800C4384:
    // 0x800C4384: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C4388: nop

    // 0x800C438C: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x800C4390: sh          $zero, 0x1E($t5)
    MEM_H(0X1E, ctx->r13) = 0;
L_800C4394:
    // 0x800C4394: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C4398: nop

    // 0x800C439C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800C43A0: sh          $zero, 0x20($t7)
    MEM_H(0X20, ctx->r15) = 0;
    // 0x800C43A4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C43A8: nop

    // 0x800C43AC: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C43B0: sh          $zero, 0x22($t9)
    MEM_H(0X22, ctx->r25) = 0;
    // 0x800C43B4: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800C43B8: nop

    // 0x800C43BC: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800C43C0: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x800C43C4: slti        $at, $a1, 0x140
    ctx->r1 = SIGNED(ctx->r5) < 0X140 ? 1 : 0;
    // 0x800C43C8: bne         $at, $zero, L_800C420C
    if (ctx->r1 != 0) {
        // 0x800C43CC: sw          $zero, 0x24($t4)
        MEM_W(0X24, ctx->r12) = 0;
            goto L_800C420C;
    }
    // 0x800C43CC: sw          $zero, 0x24($t4)
    MEM_W(0X24, ctx->r12) = 0;
    // 0x800C43D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C43D4: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
L_800C43D8:
    // 0x800C43D8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C43DC: nop

    // 0x800C43E0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C43E4: sb          $a0, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r4;
    // 0x800C43E8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C43EC: nop

    // 0x800C43F0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C43F4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800C43F8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C43FC: nop

    // 0x800C4400: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C4404: sb          $a0, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r4;
    // 0x800C4408: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C440C: nop

    // 0x800C4410: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C4414: sb          $a0, 0x11($t5)
    MEM_B(0X11, ctx->r13) = ctx->r4;
    // 0x800C4418: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C441C: nop

    // 0x800C4420: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C4424: sb          $a0, 0x12($t7)
    MEM_B(0X12, ctx->r15) = ctx->r4;
    // 0x800C4428: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C442C: nop

    // 0x800C4430: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C4434: sb          $zero, 0x13($t9)
    MEM_B(0X13, ctx->r25) = 0;
    // 0x800C4438: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C443C: nop

    // 0x800C4440: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C4444: sb          $a0, 0x14($t4)
    MEM_B(0X14, ctx->r12) = ctx->r4;
    // 0x800C4448: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C444C: nop

    // 0x800C4450: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C4454: sb          $a0, 0x15($t6)
    MEM_B(0X15, ctx->r14) = ctx->r4;
    // 0x800C4458: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C445C: nop

    // 0x800C4460: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C4464: sb          $a0, 0x16($t8)
    MEM_B(0X16, ctx->r24) = ctx->r4;
    // 0x800C4468: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C446C: nop

    // 0x800C4470: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C4474: sb          $zero, 0x17($t3)
    MEM_B(0X17, ctx->r11) = 0;
    // 0x800C4478: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C447C: nop

    // 0x800C4480: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C4484: sw          $zero, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = 0;
    // 0x800C4488: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C448C: nop

    // 0x800C4490: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C4494: sb          $a0, 0x21($t7)
    MEM_B(0X21, ctx->r15) = ctx->r4;
    // 0x800C4498: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C449C: nop

    // 0x800C44A0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C44A4: sw          $zero, 0x24($t9)
    MEM_W(0X24, ctx->r25) = 0;
    // 0x800C44A8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C44AC: nop

    // 0x800C44B0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C44B4: sb          $a0, 0x30($t4)
    MEM_B(0X30, ctx->r12) = ctx->r4;
    // 0x800C44B8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C44BC: nop

    // 0x800C44C0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C44C4: sb          $a0, 0x31($t6)
    MEM_B(0X31, ctx->r14) = ctx->r4;
    // 0x800C44C8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C44CC: nop

    // 0x800C44D0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C44D4: sb          $a0, 0x32($t8)
    MEM_B(0X32, ctx->r24) = ctx->r4;
    // 0x800C44D8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C44DC: nop

    // 0x800C44E0: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C44E4: sb          $zero, 0x33($t3)
    MEM_B(0X33, ctx->r11) = 0;
    // 0x800C44E8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C44EC: nop

    // 0x800C44F0: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C44F4: sb          $a0, 0x34($t5)
    MEM_B(0X34, ctx->r13) = ctx->r4;
    // 0x800C44F8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C44FC: nop

    // 0x800C4500: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C4504: sb          $a0, 0x35($t7)
    MEM_B(0X35, ctx->r15) = ctx->r4;
    // 0x800C4508: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C450C: nop

    // 0x800C4510: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C4514: sb          $a0, 0x36($t9)
    MEM_B(0X36, ctx->r25) = ctx->r4;
    // 0x800C4518: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C451C: nop

    // 0x800C4520: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C4524: sb          $zero, 0x37($t4)
    MEM_B(0X37, ctx->r12) = 0;
    // 0x800C4528: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C452C: nop

    // 0x800C4530: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C4534: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    // 0x800C4538: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C453C: nop

    // 0x800C4540: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C4544: sb          $a0, 0x41($t8)
    MEM_B(0X41, ctx->r24) = ctx->r4;
    // 0x800C4548: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C454C: nop

    // 0x800C4550: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C4554: sw          $zero, 0x44($t3)
    MEM_W(0X44, ctx->r11) = 0;
    // 0x800C4558: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C455C: nop

    // 0x800C4560: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C4564: sb          $a0, 0x50($t5)
    MEM_B(0X50, ctx->r13) = ctx->r4;
    // 0x800C4568: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C456C: nop

    // 0x800C4570: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C4574: sb          $a0, 0x51($t7)
    MEM_B(0X51, ctx->r15) = ctx->r4;
    // 0x800C4578: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C457C: nop

    // 0x800C4580: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C4584: sb          $a0, 0x52($t9)
    MEM_B(0X52, ctx->r25) = ctx->r4;
    // 0x800C4588: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C458C: nop

    // 0x800C4590: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C4594: sb          $zero, 0x53($t4)
    MEM_B(0X53, ctx->r12) = 0;
    // 0x800C4598: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C459C: nop

    // 0x800C45A0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C45A4: sb          $a0, 0x54($t6)
    MEM_B(0X54, ctx->r14) = ctx->r4;
    // 0x800C45A8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C45AC: nop

    // 0x800C45B0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C45B4: sb          $a0, 0x55($t8)
    MEM_B(0X55, ctx->r24) = ctx->r4;
    // 0x800C45B8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C45BC: nop

    // 0x800C45C0: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C45C4: sb          $a0, 0x56($t3)
    MEM_B(0X56, ctx->r11) = ctx->r4;
    // 0x800C45C8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C45CC: nop

    // 0x800C45D0: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C45D4: sb          $zero, 0x57($t5)
    MEM_B(0X57, ctx->r13) = 0;
    // 0x800C45D8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C45DC: nop

    // 0x800C45E0: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C45E4: sw          $zero, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = 0;
    // 0x800C45E8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C45EC: nop

    // 0x800C45F0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C45F4: sb          $a0, 0x61($t9)
    MEM_B(0X61, ctx->r25) = ctx->r4;
    // 0x800C45F8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C45FC: nop

    // 0x800C4600: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C4604: sw          $zero, 0x64($t4)
    MEM_W(0X64, ctx->r12) = 0;
    // 0x800C4608: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C460C: nop

    // 0x800C4610: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C4614: sb          $a0, 0x70($t6)
    MEM_B(0X70, ctx->r14) = ctx->r4;
    // 0x800C4618: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C461C: nop

    // 0x800C4620: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C4624: sb          $a0, 0x71($t8)
    MEM_B(0X71, ctx->r24) = ctx->r4;
    // 0x800C4628: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C462C: nop

    // 0x800C4630: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C4634: sb          $a0, 0x72($t3)
    MEM_B(0X72, ctx->r11) = ctx->r4;
    // 0x800C4638: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C463C: nop

    // 0x800C4640: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C4644: sb          $zero, 0x73($t5)
    MEM_B(0X73, ctx->r13) = 0;
    // 0x800C4648: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C464C: nop

    // 0x800C4650: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C4654: sb          $a0, 0x74($t7)
    MEM_B(0X74, ctx->r15) = ctx->r4;
    // 0x800C4658: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C465C: nop

    // 0x800C4660: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C4664: sb          $a0, 0x75($t9)
    MEM_B(0X75, ctx->r25) = ctx->r4;
    // 0x800C4668: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C466C: nop

    // 0x800C4670: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C4674: sb          $a0, 0x76($t4)
    MEM_B(0X76, ctx->r12) = ctx->r4;
    // 0x800C4678: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C467C: nop

    // 0x800C4680: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C4684: sb          $zero, 0x77($t6)
    MEM_B(0X77, ctx->r14) = 0;
    // 0x800C4688: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C468C: nop

    // 0x800C4690: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C4694: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // 0x800C4698: bne         $v0, $a1, L_800C43D8
    if (ctx->r2 != ctx->r5) {
        // 0x800C469C: sw          $zero, 0x7C($t8)
        MEM_W(0X7C, ctx->r24) = 0;
            goto L_800C43D8;
    }
    // 0x800C469C: sw          $zero, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = 0;
    // 0x800C46A0: jal         0x800C46D0
    // 0x800C46A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    load_font(rdram, ctx);
        goto after_2;
    // 0x800C46A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800C46A8: jal         0x800C46D0
    // 0x800C46AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    load_font(rdram, ctx);
        goto after_3;
    // 0x800C46AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800C46B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C46B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C46B8: sw          $zero, -0x5250($at)
    MEM_W(-0X5250, ctx->r1) = 0;
    // 0x800C46BC: jr          $ra
    // 0x800C46C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C46C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void menu_track_select_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EC58: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8008EC5C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8008EC60: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8008EC64: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8008EC68: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8008EC6C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8008EC70: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8008EC74: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8008EC78: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8008EC7C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8008EC80: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008EC84: jal         0x800C46D0
    // 0x8008EC88: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_0;
    // 0x8008EC88: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008EC8C: jal         0x8006ECD0
    // 0x8008EC90: nop

    get_settings(rdram, ctx);
        goto after_1;
    // 0x8008EC90: nop

    after_1:
    // 0x8008EC94: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8008EC98: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8008EC9C: jal         0x8006B464
    // 0x8008ECA0: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    level_count(rdram, ctx);
        goto after_2;
    // 0x8008ECA0: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_2:
    // 0x8008ECA4: jal         0x8001E2D0
    // 0x8008ECA8: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    get_misc_asset(rdram, ctx);
        goto after_3;
    // 0x8008ECA8: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_3:
    // 0x8008ECAC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008ECB0: addiu       $v1, $v1, -0x5F8
    ctx->r3 = ADD32(ctx->r3, -0X5F8);
    // 0x8008ECB4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008ECB8: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x8008ECBC: beq         $t6, $zero, L_8008ECE4
    if (ctx->r14 == 0) {
        // 0x8008ECC0: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8008ECE4;
    }
    // 0x8008ECC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ECC4: sw          $zero, 0x6F88($at)
    MEM_W(0X6F88, ctx->r1) = 0;
    // 0x8008ECC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ECCC: sw          $zero, 0x6F8C($at)
    MEM_W(0X6F8C, ctx->r1) = 0;
    // 0x8008ECD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008ECD4: sw          $zero, 0x994($at)
    MEM_W(0X994, ctx->r1) = 0;
    // 0x8008ECD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008ECDC: sw          $zero, 0x998($at)
    MEM_W(0X998, ctx->r1) = 0;
    // 0x8008ECE0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8008ECE4:
    // 0x8008ECE4: jal         0x8007A970
    // 0x8008ECE8: nop

    fb_size(rdram, ctx);
        goto after_4;
    // 0x8008ECE8: nop

    after_4:
    // 0x8008ECEC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008ECF0: addiu       $a2, $a2, 0x6A1C
    ctx->r6 = ADD32(ctx->r6, 0X6A1C);
    // 0x8008ECF4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008ECF8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8008ECFC: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x8008ED00: addiu       $a3, $a3, 0x6A20
    ctx->r7 = ADD32(ctx->r7, 0X6A20);
    // 0x8008ED04: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8008ED08: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8008ED0C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8008ED10: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8008ED14: sra         $t2, $t9, 1
    ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8008ED18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ED1C: sw          $t2, 0x6A14($at)
    MEM_W(0X6A14, ctx->r1) = ctx->r10;
    // 0x8008ED20: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x8008ED24: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8008ED28: addiu       $fp, $fp, 0x6A18
    ctx->r30 = ADD32(ctx->r30, 0X6A18);
    // 0x8008ED2C: sra         $t3, $a1, 1
    ctx->r11 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8008ED30: sw          $t3, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r11;
    // 0x8008ED34: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008ED38: lw          $t4, 0x6F88($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6F88);
    // 0x8008ED3C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008ED40: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8008ED44: lw          $t5, 0x6F8C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6F8C);
    // 0x8008ED48: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008ED4C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8008ED50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008ED54: negu        $t6, $a1
    ctx->r14 = SUB32(0, ctx->r5);
    // 0x8008ED58: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8008ED5C: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8008ED60: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8008ED64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ED68: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x8008ED6C: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8008ED70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008ED74: swc1        $f10, 0x6F9C($at)
    MEM_W(0X6F9C, ctx->r1) = ctx->f10.u32l;
    // 0x8008ED78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ED7C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008ED80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008ED84: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8008ED88: swc1        $f8, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f8.u32l;
    // 0x8008ED8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ED90: sw          $s5, 0x6FB4($at)
    MEM_W(0X6FB4, ctx->r1) = ctx->r21;
    // 0x8008ED94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ED98: sw          $s5, 0x6FB8($at)
    MEM_W(0X6FB8, ctx->r1) = ctx->r21;
    // 0x8008ED9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EDA0: sw          $s5, 0x6970($at)
    MEM_W(0X6970, ctx->r1) = ctx->r21;
    // 0x8008EDA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EDA8: sw          $t7, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r15;
    // 0x8008EDAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EDB0: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x8008EDB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EDB8: jal         0x8008F4C4
    // 0x8008EDBC: sw          $s5, 0x6D70($at)
    MEM_W(0X6D70, ctx->r1) = ctx->r21;
    trackmenu_assets(rdram, ctx);
        goto after_5;
    // 0x8008EDBC: sw          $s5, 0x6D70($at)
    MEM_W(0X6D70, ctx->r1) = ctx->r21;
    after_5:
    // 0x8008EDC0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008EDC4: jal         0x800C06F8
    // 0x8008EDC8: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_6;
    // 0x8008EDC8: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_6:
    // 0x8008EDCC: jal         0x800C0690
    // 0x8008EDD0: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_7;
    // 0x8008EDD0: nop

    after_7:
    // 0x8008EDD4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8008EDD8: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    // 0x8008EDDC: jal         0x80077FAC
    // 0x8008EDE0: addiu       $a2, $zero, 0xDF
    ctx->r6 = ADD32(0, 0XDF);
    bgdraw_fillcolour(rdram, ctx);
        goto after_8;
    // 0x8008EDE0: addiu       $a2, $zero, 0xDF
    ctx->r6 = ADD32(0, 0XDF);
    after_8:
    // 0x8008EDE4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8008EDE8: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008EDEC: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8008EDF0: addiu       $s2, $s2, 0xCB0
    ctx->r18 = ADD32(ctx->r18, 0XCB0);
    // 0x8008EDF4: addiu       $s6, $s6, 0x6AF0
    ctx->r22 = ADD32(ctx->r22, 0X6AF0);
    // 0x8008EDF8: addiu       $s1, $s1, 0xC90
    ctx->r17 = ADD32(ctx->r17, 0XC90);
    // 0x8008EDFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8008EE00:
    // 0x8008EE00: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x8008EE04: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x8008EE08: beq         $s5, $a0, L_8008EE3C
    if (ctx->r21 == ctx->r4) {
        // 0x8008EE0C: addu        $s0, $s2, $t6
        ctx->r16 = ADD32(ctx->r18, ctx->r14);
            goto L_8008EE3C;
    }
    // 0x8008EE0C: addu        $s0, $s2, $t6
    ctx->r16 = ADD32(ctx->r18, ctx->r14);
    // 0x8008EE10: jal         0x8009CC18
    // 0x8008EE14: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    menu_asset_load(rdram, ctx);
        goto after_9;
    // 0x8008EE14: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    after_9:
    // 0x8008EE18: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
    // 0x8008EE1C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8008EE20: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8008EE24: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x8008EE28: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8008EE2C: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x8008EE30: addu        $s0, $s2, $t9
    ctx->r16 = ADD32(ctx->r18, ctx->r25);
    // 0x8008EE34: b           L_8008EE40
    // 0x8008EE38: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
        goto L_8008EE40;
    // 0x8008EE38: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_8008EE3C:
    // 0x8008EE3C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8008EE40:
    // 0x8008EE40: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x8008EE44: nop

    // 0x8008EE48: beq         $s5, $a0, L_8008EE74
    if (ctx->r21 == ctx->r4) {
        // 0x8008EE4C: nop
    
            goto L_8008EE74;
    }
    // 0x8008EE4C: nop

    // 0x8008EE50: jal         0x8009CC18
    // 0x8008EE54: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    menu_asset_load(rdram, ctx);
        goto after_10;
    // 0x8008EE54: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    after_10:
    // 0x8008EE58: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x8008EE5C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8008EE60: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8008EE64: addu        $t9, $s6, $t8
    ctx->r25 = ADD32(ctx->r22, ctx->r24);
    // 0x8008EE68: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8008EE6C: b           L_8008EE78
    // 0x8008EE70: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
        goto L_8008EE78;
    // 0x8008EE70: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
L_8008EE74:
    // 0x8008EE74: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_8008EE78:
    // 0x8008EE78: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008EE7C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8008EE80: bne         $a1, $at, L_8008EE00
    if (ctx->r5 != ctx->r1) {
        // 0x8008EE84: addiu       $s1, $s1, 0x6
        ctx->r17 = ADD32(ctx->r17, 0X6);
            goto L_8008EE00;
    }
    // 0x8008EE84: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x8008EE88: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8008EE8C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8008EE90: jal         0x80070EDC
    // 0x8008EE94: addiu       $a0, $zero, 0xB40
    ctx->r4 = ADD32(0, 0XB40);
    mempool_alloc_safe(rdram, ctx);
        goto after_11;
    // 0x8008EE94: addiu       $a0, $zero, 0xB40
    ctx->r4 = ADD32(0, 0XB40);
    after_11:
    // 0x8008EE98: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008EE9C: addiu       $a1, $a1, 0xEF0
    ctx->r5 = ADD32(ctx->r5, 0XEF0);
    // 0x8008EEA0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8008EEA4: addiu       $t3, $v0, 0x280
    ctx->r11 = ADD32(ctx->r2, 0X280);
    // 0x8008EEA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008EEAC: sw          $t3, 0xEF4($at)
    MEM_W(0XEF4, ctx->r1) = ctx->r11;
    // 0x8008EEB0: lw          $t4, 0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X4);
    // 0x8008EEB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008EEB8: addiu       $t5, $t4, 0x280
    ctx->r13 = ADD32(ctx->r12, 0X280);
    // 0x8008EEBC: sw          $t5, 0xEE8($at)
    MEM_W(0XEE8, ctx->r1) = ctx->r13;
    // 0x8008EEC0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008EEC4: lw          $t6, 0xEE8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XEE8);
    // 0x8008EEC8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008EECC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008EED0: addiu       $t7, $t6, 0x320
    ctx->r15 = ADD32(ctx->r14, 0X320);
    // 0x8008EED4: sw          $t7, 0xEEC($at)
    MEM_W(0XEEC, ctx->r1) = ctx->r15;
    // 0x8008EED8: addiu       $a0, $zero, -0xA0
    ctx->r4 = ADD32(0, -0XA0);
    // 0x8008EEDC: addiu       $t0, $t0, 0xEF0
    ctx->r8 = ADD32(ctx->r8, 0XEF0);
    // 0x8008EEE0: addiu       $v1, $v1, 0xEE8
    ctx->r3 = ADD32(ctx->r3, 0XEE8);
    // 0x8008EEE4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008EEE8: addiu       $a3, $zero, 0x320
    ctx->r7 = ADD32(0, 0X320);
    // 0x8008EEEC: addiu       $a2, $zero, -0x400
    ctx->r6 = ADD32(0, -0X400);
    // 0x8008EEF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008EEF4:
    // 0x8008EEF4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008EEF8: nop

    // 0x8008EEFC: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008EF00: sh          $a0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r4;
    // 0x8008EF04: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF08: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8008EF0C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8008EF10: sh          $a2, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r6;
    // 0x8008EF14: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF18: nop

    // 0x8008EF1C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8008EF20: sb          $a1, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r5;
    // 0x8008EF24: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF28: nop

    // 0x8008EF2C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8008EF30: sb          $a1, 0x7($t6)
    MEM_B(0X7, ctx->r14) = ctx->r5;
    // 0x8008EF34: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF38: nop

    // 0x8008EF3C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8008EF40: sb          $a1, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r5;
    // 0x8008EF44: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF48: nop

    // 0x8008EF4C: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8008EF50: sh          $a0, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r4;
    // 0x8008EF54: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF58: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8008EF5C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8008EF60: sh          $a2, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r6;
    // 0x8008EF64: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF68: nop

    // 0x8008EF6C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8008EF70: sb          $a1, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r5;
    // 0x8008EF74: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF78: nop

    // 0x8008EF7C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8008EF80: sb          $a1, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r5;
    // 0x8008EF84: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF88: nop

    // 0x8008EF8C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008EF90: sb          $a1, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r5;
    // 0x8008EF94: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF98: nop

    // 0x8008EF9C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8008EFA0: sh          $a0, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r4;
    // 0x8008EFA4: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8008EFA8: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8008EFAC: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8008EFB0: sh          $a2, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r6;
    // 0x8008EFB4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8008EFB8: nop

    // 0x8008EFBC: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8008EFC0: sb          $a1, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = ctx->r5;
    // 0x8008EFC4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8008EFC8: nop

    // 0x8008EFCC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8008EFD0: sb          $a1, 0x1B($t8)
    MEM_B(0X1B, ctx->r24) = ctx->r5;
    // 0x8008EFD4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008EFD8: nop

    // 0x8008EFDC: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8008EFE0: sb          $a1, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = ctx->r5;
    // 0x8008EFE4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8008EFE8: nop

    // 0x8008EFEC: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8008EFF0: sh          $a0, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = ctx->r4;
    // 0x8008EFF4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008EFF8: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8008EFFC: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8008F000: sh          $a2, 0x22($t5)
    MEM_H(0X22, ctx->r13) = ctx->r6;
    // 0x8008F004: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008F008: nop

    // 0x8008F00C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8008F010: sb          $a1, 0x24($t7)
    MEM_B(0X24, ctx->r15) = ctx->r5;
    // 0x8008F014: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008F018: nop

    // 0x8008F01C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008F020: sb          $a1, 0x25($t9)
    MEM_B(0X25, ctx->r25) = ctx->r5;
    // 0x8008F024: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8008F028: nop

    // 0x8008F02C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8008F030: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x8008F034: bne         $v0, $a3, L_8008EEF4
    if (ctx->r2 != ctx->r7) {
        // 0x8008F038: sb          $a1, 0x26($t2)
        MEM_B(0X26, ctx->r10) = ctx->r5;
            goto L_8008EEF4;
    }
    // 0x8008F038: sb          $a1, 0x26($t2)
    MEM_B(0X26, ctx->r10) = ctx->r5;
    // 0x8008F03C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8008F040: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x8008F044: bne         $at, $zero, L_8008EEF4
    if (ctx->r1 != 0) {
        // 0x8008F048: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008EEF4;
    }
    // 0x8008F048: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008F04C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008F050: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008F054: addiu       $t0, $t0, 0xEF8
    ctx->r8 = ADD32(ctx->r8, 0XEF8);
    // 0x8008F058: addiu       $v1, $v1, 0xEF0
    ctx->r3 = ADD32(ctx->r3, 0XEF0);
    // 0x8008F05C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8008F060: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008F064: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8008F068: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x8008F06C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F070:
    // 0x8008F070: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8008F074: nop

    // 0x8008F078: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8008F07C: sb          $a0, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r4;
    // 0x8008F080: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8008F084: nop

    // 0x8008F088: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8008F08C: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    // 0x8008F090: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8008F094: nop

    // 0x8008F098: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8008F09C: sb          $a1, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r5;
    // 0x8008F0A0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008F0A4: nop

    // 0x8008F0A8: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8008F0AC: sb          $a2, 0x3($t1)
    MEM_B(0X3, ctx->r9) = ctx->r6;
    // 0x8008F0B0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8008F0B4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8008F0B8: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8008F0BC: sb          $a0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r4;
    // 0x8008F0C0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008F0C4: nop

    // 0x8008F0C8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8008F0CC: sb          $a2, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r6;
    // 0x8008F0D0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008F0D4: nop

    // 0x8008F0D8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8008F0DC: sb          $a1, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r5;
    // 0x8008F0E0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008F0E4: nop

    // 0x8008F0E8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008F0EC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8008F0F0: slti        $at, $v0, 0x280
    ctx->r1 = SIGNED(ctx->r2) < 0X280 ? 1 : 0;
    // 0x8008F0F4: bne         $at, $zero, L_8008F070
    if (ctx->r1 != 0) {
        // 0x8008F0F8: sb          $a3, 0x3($t9)
        MEM_B(0X3, ctx->r25) = ctx->r7;
            goto L_8008F070;
    }
    // 0x8008F0F8: sb          $a3, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r7;
    // 0x8008F0FC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8008F100: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x8008F104: bne         $at, $zero, L_8008F070
    if (ctx->r1 != 0) {
        // 0x8008F108: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008F070;
    }
    // 0x8008F108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008F10C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F110: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8008F114: sw          $zero, 0x6EE4($at)
    MEM_W(0X6EE4, ctx->r1) = 0;
    // 0x8008F118: jal         0x80078EFC
    // 0x8008F11C: addiu       $a0, $a0, -0x530
    ctx->r4 = ADD32(ctx->r4, -0X530);
    bgdraw_set_func(rdram, ctx);
        goto after_12;
    // 0x8008F11C: addiu       $a0, $a0, -0x530
    ctx->r4 = ADD32(ctx->r4, -0X530);
    after_12:
    // 0x8008F120: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8008F124: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008F128: sra         $v1, $v0, 1
    ctx->r3 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008F12C: addu        $t1, $v1, $v0
    ctx->r9 = ADD32(ctx->r3, ctx->r2);
    // 0x8008F130: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008F134: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x8008F138: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x8008F13C: jal         0x80066B80
    // 0x8008F140: subu        $a2, $v0, $v1
    ctx->r6 = SUB32(ctx->r2, ctx->r3);
    viewport_menu_set(rdram, ctx);
        goto after_13;
    // 0x8008F140: subu        $a2, $v0, $v1
    ctx->r6 = SUB32(ctx->r2, ctx->r3);
    after_13:
    // 0x8008F144: jal         0x80066850
    // 0x8008F148: nop

    copy_viewports_to_stack(rdram, ctx);
        goto after_14;
    // 0x8008F148: nop

    after_14:
    // 0x8008F14C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008F150: jal         0x80066A58
    // 0x8008F154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camEnableUserView(rdram, ctx);
        goto after_15;
    // 0x8008F154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x8008F158: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008F15C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F160: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F164: sw          $t2, 0xEFC($at)
    MEM_W(0XEFC, ctx->r1) = ctx->r10;
    // 0x8008F168: jal         0x8009CBB8
    // 0x8008F16C: addiu       $a0, $a0, 0xD44
    ctx->r4 = ADD32(ctx->r4, 0XD44);
    menu_assetgroup_load(rdram, ctx);
        goto after_16;
    // 0x8008F16C: addiu       $a0, $a0, 0xD44
    ctx->r4 = ADD32(ctx->r4, 0XD44);
    after_16:
    // 0x8008F170: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F174: jal         0x8009CDE8
    // 0x8008F178: addiu       $a0, $a0, 0xD60
    ctx->r4 = ADD32(ctx->r4, 0XD60);
    menu_imagegroup_load(rdram, ctx);
        goto after_17;
    // 0x8008F178: addiu       $a0, $a0, 0xD60
    ctx->r4 = ADD32(ctx->r4, 0XD60);
    after_17:
    // 0x8008F17C: jal         0x8008E968
    // 0x8008F180: nop

    menu_init_arrow_textures(rdram, ctx);
        goto after_18;
    // 0x8008F180: nop

    after_18:
    // 0x8008F184: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008F188: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008F18C: addiu       $v1, $v1, 0xB74
    ctx->r3 = ADD32(ctx->r3, 0XB74);
    // 0x8008F190: addiu       $v0, $v0, 0xB54
    ctx->r2 = ADD32(ctx->r2, 0XB54);
    // 0x8008F194: lw          $t3, 0x20($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X20);
    // 0x8008F198: lw          $t4, 0x24($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X24);
    // 0x8008F19C: lw          $t5, 0x28($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X28);
    // 0x8008F1A0: lw          $t6, 0x2C($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X2C);
    // 0x8008F1A4: lw          $t7, 0x30($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X30);
    // 0x8008F1A8: lw          $t8, 0x34($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X34);
    // 0x8008F1AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008F1B0: addiu       $t9, $t9, 0x6EA8
    ctx->r25 = ADD32(ctx->r25, 0X6EA8);
    // 0x8008F1B4: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x8008F1B8: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x8008F1BC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8008F1C0: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
    // 0x8008F1C4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8008F1C8: sw          $t4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r12;
    // 0x8008F1CC: sw          $t5, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r13;
    // 0x8008F1D0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8008F1D4: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x8008F1D8: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
L_8008F1DC:
    // 0x8008F1DC: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8008F1E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008F1E4: addiu       $fp, $s3, 0x1
    ctx->r30 = ADD32(ctx->r19, 0X1);
L_8008F1E8:
    // 0x8008F1E8: bne         $s1, $zero, L_8008F218
    if (ctx->r17 != 0) {
        // 0x8008F1EC: sh          $s5, 0x0($s2)
        MEM_H(0X0, ctx->r18) = ctx->r21;
            goto L_8008F218;
    }
    // 0x8008F1EC: sh          $s5, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r21;
    // 0x8008F1F0: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8008F1F4: beq         $at, $zero, L_8008F21C
    if (ctx->r1 == 0) {
        // 0x8008F1F8: slti        $at, $s1, 0x4
        ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
            goto L_8008F21C;
    }
    // 0x8008F1F8: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8008F1FC: multu       $s3, $s0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008F200: mflo        $t1
    ctx->r9 = lo;
    // 0x8008F204: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x8008F208: addu        $t3, $t2, $s7
    ctx->r11 = ADD32(ctx->r10, ctx->r23);
    // 0x8008F20C: lb          $t4, 0x0($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X0);
    // 0x8008F210: b           L_8008F33C
    // 0x8008F214: sh          $t4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r12;
        goto L_8008F33C;
    // 0x8008F214: sh          $t4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r12;
L_8008F218:
    // 0x8008F218: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
L_8008F21C:
    // 0x8008F21C: beq         $at, $zero, L_8008F26C
    if (ctx->r1 == 0) {
        // 0x8008F220: nop
    
            goto L_8008F26C;
    }
    // 0x8008F220: nop

    // 0x8008F224: multu       $s3, $s0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008F228: mflo        $t5
    ctx->r13 = lo;
    // 0x8008F22C: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x8008F230: addu        $t7, $t6, $s7
    ctx->r15 = ADD32(ctx->r14, ctx->r23);
    // 0x8008F234: lb          $v0, 0x0($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X0);
    // 0x8008F238: nop

    // 0x8008F23C: beq         $s5, $v0, L_8008F33C
    if (ctx->r21 == ctx->r2) {
        // 0x8008F240: nop
    
            goto L_8008F33C;
    }
    // 0x8008F240: nop

    // 0x8008F244: lw          $t8, 0x4($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X4);
    // 0x8008F248: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8008F24C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8008F250: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8008F254: nop

    // 0x8008F258: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8008F25C: beq         $t3, $zero, L_8008F33C
    if (ctx->r11 == 0) {
        // 0x8008F260: nop
    
            goto L_8008F33C;
    }
    // 0x8008F260: nop

    // 0x8008F264: b           L_8008F33C
    // 0x8008F268: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
        goto L_8008F33C;
    // 0x8008F268: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
L_8008F26C:
    // 0x8008F26C: bne         $s1, $s6, L_8008F304
    if (ctx->r17 != ctx->r22) {
        // 0x8008F270: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8008F304;
    }
    // 0x8008F270: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8008F274: sll         $a2, $s3, 2
    ctx->r6 = S32(ctx->r19 << 2);
    // 0x8008F278: subu        $a2, $a2, $s3
    ctx->r6 = SUB32(ctx->r6, ctx->r19);
    // 0x8008F27C: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8008F280: addu        $v0, $a2, $s7
    ctx->r2 = ADD32(ctx->r6, ctx->r23);
    // 0x8008F284: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008F288: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8008F28C:
    // 0x8008F28C: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x8008F290: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008F294: beq         $s5, $v1, L_8008F2C0
    if (ctx->r21 == ctx->r3) {
        // 0x8008F298: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_8008F2C0;
    }
    // 0x8008F298: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x8008F29C: lw          $t4, 0x4($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X4);
    // 0x8008F2A0: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8008F2A4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8008F2A8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8008F2AC: nop

    // 0x8008F2B0: andi        $t8, $t7, 0x6
    ctx->r24 = ctx->r15 & 0X6;
    // 0x8008F2B4: bne         $s0, $t8, L_8008F2C0
    if (ctx->r16 != ctx->r24) {
        // 0x8008F2B8: nop
    
            goto L_8008F2C0;
    }
    // 0x8008F2B8: nop

    // 0x8008F2BC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8008F2C0:
    // 0x8008F2C0: bne         $at, $zero, L_8008F28C
    if (ctx->r1 != 0) {
        // 0x8008F2C4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008F28C;
    }
    // 0x8008F2C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008F2C8: bne         $a1, $s6, L_8008F2F0
    if (ctx->r5 != ctx->r22) {
        // 0x8008F2CC: addu        $t3, $a2, $s1
        ctx->r11 = ADD32(ctx->r6, ctx->r17);
            goto L_8008F2F0;
    }
    // 0x8008F2CC: addu        $t3, $a2, $s1
    ctx->r11 = ADD32(ctx->r6, ctx->r17);
    // 0x8008F2D0: beq         $s3, $s6, L_8008F2F0
    if (ctx->r19 == ctx->r22) {
        // 0x8008F2D4: addiu       $t9, $zero, 0x82
        ctx->r25 = ADD32(0, 0X82);
            goto L_8008F2F0;
    }
    // 0x8008F2D4: addiu       $t9, $zero, 0x82
    ctx->r25 = ADD32(0, 0X82);
    // 0x8008F2D8: lhu         $t1, 0xC($s4)
    ctx->r9 = MEM_HU(ctx->r20, 0XC);
    // 0x8008F2DC: sllv        $v0, $t9, $s3
    ctx->r2 = S32(ctx->r25 << (ctx->r19 & 31));
    // 0x8008F2E0: and         $t2, $t1, $v0
    ctx->r10 = ctx->r9 & ctx->r2;
    // 0x8008F2E4: beq         $v0, $t2, L_8008F2F0
    if (ctx->r2 == ctx->r10) {
        // 0x8008F2E8: nop
    
            goto L_8008F2F0;
    }
    // 0x8008F2E8: nop

    // 0x8008F2EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8008F2F0:
    // 0x8008F2F0: bne         $a1, $s6, L_8008F33C
    if (ctx->r5 != ctx->r22) {
        // 0x8008F2F4: addu        $t4, $t3, $s7
        ctx->r12 = ADD32(ctx->r11, ctx->r23);
            goto L_8008F33C;
    }
    // 0x8008F2F4: addu        $t4, $t3, $s7
    ctx->r12 = ADD32(ctx->r11, ctx->r23);
    // 0x8008F2F8: lb          $t5, 0x0($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X0);
    // 0x8008F2FC: b           L_8008F33C
    // 0x8008F300: sh          $t5, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r13;
        goto L_8008F33C;
    // 0x8008F300: sh          $t5, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r13;
L_8008F304:
    // 0x8008F304: bne         $s1, $at, L_8008F33C
    if (ctx->r17 != ctx->r1) {
        // 0x8008F308: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8008F33C;
    }
    // 0x8008F308: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008F30C: lhu         $t6, 0x8($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X8);
    // 0x8008F310: sllv        $t8, $t7, $fp
    ctx->r24 = S32(ctx->r15 << (ctx->r30 & 31));
    // 0x8008F314: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x8008F318: beq         $t9, $zero, L_8008F33C
    if (ctx->r25 == 0) {
        // 0x8008F31C: nop
    
            goto L_8008F33C;
    }
    // 0x8008F31C: nop

    // 0x8008F320: multu       $s3, $s0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008F324: mflo        $t1
    ctx->r9 = lo;
    // 0x8008F328: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x8008F32C: addu        $t3, $t2, $s7
    ctx->r11 = ADD32(ctx->r10, ctx->r23);
    // 0x8008F330: lb          $t4, 0x0($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X0);
    // 0x8008F334: nop

    // 0x8008F338: sh          $t4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r12;
L_8008F33C:
    // 0x8008F33C: jal         0x8009F1A4
    // 0x8008F340: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_19;
    // 0x8008F340: nop

    after_19:
    // 0x8008F344: beq         $v0, $zero, L_8008F368
    if (ctx->r2 == 0) {
        // 0x8008F348: nop
    
            goto L_8008F368;
    }
    // 0x8008F348: nop

    // 0x8008F34C: multu       $s3, $s0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008F350: mflo        $t5
    ctx->r13 = lo;
    // 0x8008F354: addu        $t7, $t5, $s1
    ctx->r15 = ADD32(ctx->r13, ctx->r17);
    // 0x8008F358: addu        $t6, $t7, $s7
    ctx->r14 = ADD32(ctx->r15, ctx->r23);
    // 0x8008F35C: lb          $t8, 0x0($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X0);
    // 0x8008F360: nop

    // 0x8008F364: sh          $t8, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r24;
L_8008F368:
    // 0x8008F368: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008F36C: bne         $s1, $s0, L_8008F1E8
    if (ctx->r17 != ctx->r16) {
        // 0x8008F370: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_8008F1E8;
    }
    // 0x8008F370: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8008F374: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8008F378: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8008F37C: addiu       $t1, $t9, 0xC
    ctx->r9 = ADD32(ctx->r25, 0XC);
    // 0x8008F380: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x8008F384: bne         $fp, $at, L_8008F1DC
    if (ctx->r30 != ctx->r1) {
        // 0x8008F388: or          $s3, $fp, $zero
        ctx->r19 = ctx->r30 | 0;
            goto L_8008F1DC;
    }
    // 0x8008F388: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x8008F38C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008F390: lw          $v0, 0x6F8C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6F8C);
    // 0x8008F394: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008F398: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x8008F39C: lw          $t4, 0x6F88($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6F88);
    // 0x8008F3A0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008F3A4: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x8008F3A8: addiu       $a3, $a3, 0x6EA8
    ctx->r7 = ADD32(ctx->r7, 0X6EA8);
    // 0x8008F3AC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008F3B0: addu        $t3, $a3, $t2
    ctx->r11 = ADD32(ctx->r7, ctx->r10);
    // 0x8008F3B4: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8008F3B8: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x8008F3BC: lh          $t6, 0x0($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X0);
    // 0x8008F3C0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008F3C4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008F3C8: addiu       $s0, $s0, -0x5B8
    ctx->r16 = ADD32(ctx->r16, -0X5B8);
    // 0x8008F3CC: addiu       $v1, $v1, -0x5BC
    ctx->r3 = ADD32(ctx->r3, -0X5BC);
    // 0x8008F3D0: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8008F3D4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8008F3D8: bne         $s5, $t6, L_8008F414
    if (ctx->r21 != ctx->r14) {
        // 0x8008F3DC: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8008F414;
    }
    // 0x8008F3DC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8008F3E0: lh          $a0, 0x0($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X0);
    // 0x8008F3E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008F3E8: addiu       $v0, $v0, 0x6970
    ctx->r2 = ADD32(ctx->r2, 0X6970);
    // 0x8008F3EC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008F3F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008F3F4: jal         0x8006E528
    // 0x8008F3F8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    load_level_for_menu(rdram, ctx);
        goto after_20;
    // 0x8008F3F8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_20:
    // 0x8008F3FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008F400: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8008F404: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F408: sw          $zero, 0x6FB4($at)
    MEM_W(0X6FB4, ctx->r1) = 0;
    // 0x8008F40C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F410: sw          $zero, 0x6FB8($at)
    MEM_W(0X6FB8, ctx->r1) = 0;
L_8008F414:
    // 0x8008F414: jal         0x800C59F4
    // 0x8008F418: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_21;
    // 0x8008F418: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_21:
    // 0x8008F41C: jal         0x8008043C
    // 0x8008F420: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8007FFEC(rdram, ctx);
        goto after_22;
    // 0x8008F420: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_22:
    // 0x8008F424: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F428: sw          $zero, 0x6DE0($at)
    MEM_W(0X6DE0, ctx->r1) = 0;
    // 0x8008F42C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008F430: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F434: addiu       $s0, $s0, -0x320
    ctx->r16 = ADD32(ctx->r16, -0X320);
    // 0x8008F438: sw          $zero, 0x6DE8($at)
    MEM_W(0X6DE8, ctx->r1) = 0;
    // 0x8008F43C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8008F440: jal         0x80000BE0
    // 0x8008F444: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_23;
    // 0x8008F444: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_23:
    // 0x8008F448: jal         0x80000C1C
    // 0x8008F44C: nop

    music_voicelimit_change_off(rdram, ctx);
        goto after_24;
    // 0x8008F44C: nop

    after_24:
    // 0x8008F450: jal         0x80000B34
    // 0x8008F454: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_25;
    // 0x8008F454: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_25:
    // 0x8008F458: lbu         $a0, 0x3($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X3);
    // 0x8008F45C: jal         0x80001990
    // 0x8008F460: nop

    music_volume_set(rdram, ctx);
        goto after_26;
    // 0x8008F460: nop

    after_26:
    // 0x8008F464: jal         0x80000B18
    // 0x8008F468: nop

    music_change_off(rdram, ctx);
        goto after_27;
    // 0x8008F468: nop

    after_27:
    // 0x8008F46C: jal         0x8006F7A4
    // 0x8008F470: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_gIntDisFlag(rdram, ctx);
        goto after_28;
    // 0x8008F470: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_28:
    // 0x8008F474: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008F478: lw          $t4, 0x998($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X998);
    // 0x8008F47C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F480: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008F484: lw          $t3, 0x990($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X990);
    // 0x8008F488: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8008F48C: sw          $t4, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r12;
    // 0x8008F490: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F494: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008F498: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8008F49C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8008F4A0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8008F4A4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8008F4A8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8008F4AC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8008F4B0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8008F4B4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8008F4B8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8008F4BC: jr          $ra
    // 0x8008F4C0: sw          $t3, 0x6AE8($at)
    MEM_W(0X6AE8, ctx->r1) = ctx->r11;
    return;
    // 0x8008F4C0: sw          $t3, 0x6AE8($at)
    MEM_W(0X6AE8, ctx->r1) = ctx->r11;
;}
RECOMP_FUNC void debug_text_background(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6EBC: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800B6EC0: xor         $t6, $a1, $a3
    ctx->r14 = ctx->r5 ^ ctx->r7;
    // 0x800B6EC4: xor         $t8, $a2, $t7
    ctx->r24 = ctx->r6 ^ ctx->r15;
    // 0x800B6EC8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800B6ECC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800B6ED0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B6ED4: bne         $t9, $zero, L_800B6F54
    if (ctx->r25 != 0) {
        // 0x800B6ED8: sltiu       $at, $a1, 0x2
        ctx->r1 = ctx->r5 < 0X2 ? 1 : 0;
            goto L_800B6F54;
    }
    // 0x800B6ED8: sltiu       $at, $a1, 0x2
    ctx->r1 = ctx->r5 < 0X2 ? 1 : 0;
    // 0x800B6EDC: bne         $at, $zero, L_800B6EE8
    if (ctx->r1 != 0) {
        // 0x800B6EE0: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_800B6EE8;
    }
    // 0x800B6EE0: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800B6EE4: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
L_800B6EE8:
    // 0x800B6EE8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B6EEC: lui         $t2, 0xFCFF
    ctx->r10 = S32(0XFCFF << 16);
    // 0x800B6EF0: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800B6EF4: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800B6EF8: lui         $t3, 0xFFFD
    ctx->r11 = S32(0XFFFD << 16);
    // 0x800B6EFC: ori         $t3, $t3, 0xF6FB
    ctx->r11 = ctx->r11 | 0XF6FB;
    // 0x800B6F00: ori         $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 | 0XFFFF;
    // 0x800B6F04: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800B6F08: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800B6F0C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B6F10: andi        $t5, $a3, 0x3FF
    ctx->r13 = ctx->r7 & 0X3FF;
    // 0x800B6F14: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800B6F18: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B6F1C: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800B6F20: sll         $t7, $t5, 14
    ctx->r15 = S32(ctx->r13 << 14);
    // 0x800B6F24: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800B6F28: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800B6F2C: andi        $t5, $a2, 0x3FF
    ctx->r13 = ctx->r6 & 0X3FF;
    // 0x800B6F30: andi        $t3, $a1, 0x3FF
    ctx->r11 = ctx->r5 & 0X3FF;
    // 0x800B6F34: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x800B6F38: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800B6F3C: sll         $t4, $t3, 14
    ctx->r12 = S32(ctx->r11 << 14);
    // 0x800B6F40: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800B6F44: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800B6F48: or          $t2, $t6, $t1
    ctx->r10 = ctx->r14 | ctx->r9;
    // 0x800B6F4C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800B6F50: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_800B6F54:
    // 0x800B6F54: jr          $ra
    // 0x800B6F58: nop

    return;
    // 0x800B6F58: nop

;}
RECOMP_FUNC void menu_title_screen_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E1C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80083E20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083E24: jal         0x80069F60
    // 0x80083E28: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x80083E28: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80083E2C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80083E30: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x80083E34: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80083E38: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80083E3C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80083E40: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80083E44: andi        $t9, $t8, 0x3F
    ctx->r25 = ctx->r24 & 0X3F;
    // 0x80083E48: jal         0x8008E9A4
    // 0x80083E4C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    menu_input(rdram, ctx);
        goto after_1;
    // 0x80083E4C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    after_1:
    // 0x80083E50: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80083E54: lw          $t1, 0x300($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X300);
    // 0x80083E58: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80083E5C: bne         $t1, $zero, L_80083E88
    if (ctx->r9 != 0) {
        // 0x80083E60: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80083E88;
    }
    // 0x80083E60: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083E64: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80083E68: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80083E6C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80083E70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80083E74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80083E78: nop

    // 0x80083E7C: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80083E80: b           L_80083EA4
    // 0x80083E84: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
        goto L_80083EA4;
    // 0x80083E84: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
L_80083E88:
    // 0x80083E88: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80083E8C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80083E90: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80083E94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80083E98: nop

    // 0x80083E9C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80083EA0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
L_80083EA4:
    // 0x80083EA4: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80083EA8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80083EAC: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80083EB0: beq         $at, $zero, L_80083ED0
    if (ctx->r1 == 0) {
        // 0x80083EB4: nop
    
            goto L_80083ED0;
    }
    // 0x80083EB4: nop

    // 0x80083EB8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80083EBC: jal         0x80083BB4
    // 0x80083EC0: nop

    render_title_screen(rdram, ctx);
        goto after_2;
    // 0x80083EC0: nop

    after_2:
    // 0x80083EC4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083EC8: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80083ECC: nop

L_80083ED0:
    // 0x80083ED0: beq         $v0, $zero, L_80083EE8
    if (ctx->r2 == 0) {
        // 0x80083ED4: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80083EE8;
    }
    // 0x80083ED4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80083ED8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80083EDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083EE0: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80083EE4: sw          $t5, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r13;
L_80083EE8:
    // 0x80083EE8: addiu       $t0, $t0, 0x6E04
    ctx->r8 = ADD32(ctx->r8, 0X6E04);
    // 0x80083EEC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083EF0: lw          $v0, 0x6E14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E14);
    // 0x80083EF4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80083EF8: lb          $t9, 0x0($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X0);
    // 0x80083EFC: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80083F00: lb          $t8, 0x0($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X0);
    // 0x80083F04: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80083F08: bne         $t8, $t9, L_80083F28
    if (ctx->r24 != ctx->r25) {
        // 0x80083F0C: addiu       $a3, $a3, 0x6E08
        ctx->r7 = ADD32(ctx->r7, 0X6E08);
            goto L_80083F28;
    }
    // 0x80083F0C: addiu       $a3, $a3, 0x6E08
    ctx->r7 = ADD32(ctx->r7, 0X6E08);
    // 0x80083F10: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80083F14: lw          $t1, 0x6978($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6978);
    // 0x80083F18: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80083F1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083F20: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80083F24: sw          $t3, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r11;
L_80083F28:
    // 0x80083F28: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x80083F2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80083F30: blez        $v1, L_80083FA8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80083F34: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80083FA8;
    }
    // 0x80083F34: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083F38: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80083F3C: nop

    // 0x80083F40: subu        $t5, $v1, $t4
    ctx->r13 = SUB32(ctx->r3, ctx->r12);
    // 0x80083F44: sh          $t5, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r13;
    // 0x80083F48: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x80083F4C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80083F50: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x80083F54: beq         $at, $zero, L_80083F90
    if (ctx->r1 == 0) {
        // 0x80083F58: addu        $t7, $v1, $t6
        ctx->r15 = ADD32(ctx->r3, ctx->r14);
            goto L_80083F90;
    }
    // 0x80083F58: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80083F5C: slti        $at, $t7, 0x3C
    ctx->r1 = SIGNED(ctx->r15) < 0X3C ? 1 : 0;
    // 0x80083F60: bne         $at, $zero, L_80083F90
    if (ctx->r1 != 0) {
        // 0x80083F64: addiu       $a0, $zero, -0x300
        ctx->r4 = ADD32(0, -0X300);
            goto L_80083F90;
    }
    // 0x80083F64: addiu       $a0, $zero, -0x300
    ctx->r4 = ADD32(0, -0X300);
    // 0x80083F68: jal         0x80000C98
    // 0x80083F6C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    music_fade(rdram, ctx);
        goto after_3;
    // 0x80083F6C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_3:
    // 0x80083F70: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083F74: jal         0x800C06F8
    // 0x80083F78: addiu       $a0, $a0, 0x2388
    ctx->r4 = ADD32(ctx->r4, 0X2388);
    transition_begin(rdram, ctx);
        goto after_4;
    // 0x80083F78: addiu       $a0, $a0, 0x2388
    ctx->r4 = ADD32(ctx->r4, 0X2388);
    after_4:
    // 0x80083F7C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80083F80: addiu       $a3, $a3, 0x6E08
    ctx->r7 = ADD32(ctx->r7, 0X6E08);
    // 0x80083F84: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x80083F88: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80083F8C: nop

L_80083F90:
    // 0x80083F90: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083F94: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80083F98: bgtz        $v1, L_80083FB4
    if (SIGNED(ctx->r3) > 0) {
        // 0x80083F9C: nop
    
            goto L_80083FB4;
    }
    // 0x80083F9C: nop

    // 0x80083FA0: b           L_80083FB4
    // 0x80083FA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80083FB4;
    // 0x80083FA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80083FA8:
    // 0x80083FA8: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x80083FAC: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80083FB0: nop

L_80083FB4:
    // 0x80083FB4: bne         $v0, $zero, L_800840B4
    if (ctx->r2 != 0) {
        // 0x80083FB8: nop
    
            goto L_800840B4;
    }
    // 0x80083FB8: nop

    // 0x80083FBC: jal         0x800214F8
    // 0x80083FC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800214C4(rdram, ctx);
        goto after_5;
    // 0x80083FC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_5:
    // 0x80083FC4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80083FC8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80083FCC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80083FD0: addiu       $t0, $t0, 0x6E04
    ctx->r8 = ADD32(ctx->r8, 0X6E04);
    // 0x80083FD4: bne         $v0, $zero, L_80083FE4
    if (ctx->r2 != 0) {
        // 0x80083FD8: addiu       $a3, $a3, 0x6E08
        ctx->r7 = ADD32(ctx->r7, 0X6E08);
            goto L_80083FE4;
    }
    // 0x80083FD8: addiu       $a3, $a3, 0x6E08
    ctx->r7 = ADD32(ctx->r7, 0X6E08);
    // 0x80083FDC: beq         $a2, $zero, L_800840B4
    if (ctx->r6 == 0) {
        // 0x80083FE0: nop
    
            goto L_800840B4;
    }
    // 0x80083FE0: nop

L_80083FE4:
    // 0x80083FE4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80083FE8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083FEC: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x80083FF0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80083FF4: lw          $v0, 0x6E14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E14);
    // 0x80083FF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80083FFC: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x80084000: lb          $t2, 0x0($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X0);
    // 0x80084004: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80084008: bne         $t2, $at, L_80084018
    if (ctx->r10 != ctx->r1) {
        // 0x8008400C: addiu       $t6, $zero, 0x5DC
        ctx->r14 = ADD32(0, 0X5DC);
            goto L_80084018;
    }
    // 0x8008400C: addiu       $t6, $zero, 0x5DC
    ctx->r14 = ADD32(0, 0X5DC);
    // 0x80084010: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80084014: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80084018:
    // 0x80084018: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008401C: addiu       $v0, $v0, 0x6E0C
    ctx->r2 = ADD32(ctx->r2, 0X6E0C);
    // 0x80084020: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80084024: nop

    // 0x80084028: bne         $t4, $zero, L_80084034
    if (ctx->r12 != 0) {
        // 0x8008402C: nop
    
            goto L_80084034;
    }
    // 0x8008402C: nop

    // 0x80084030: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80084034:
    // 0x80084034: lb          $a1, 0x1($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X1);
    // 0x80084038: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8008403C: bne         $a1, $at, L_8008404C
    if (ctx->r5 != ctx->r1) {
        // 0x80084040: sh          $zero, 0x0($a3)
        MEM_H(0X0, ctx->r7) = 0;
            goto L_8008404C;
    }
    // 0x80084040: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x80084044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084048: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
L_8008404C:
    // 0x8008404C: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x80084050: lb          $a2, 0x2($v1)
    ctx->r6 = MEM_B(ctx->r3, 0X2);
    // 0x80084054: jal         0x8006E528
    // 0x80084058: nop

    load_level_for_menu(rdram, ctx);
        goto after_6;
    // 0x80084058: nop

    after_6:
    // 0x8008405C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80084060: addiu       $t0, $t0, 0x6E04
    ctx->r8 = ADD32(ctx->r8, 0X6E04);
    // 0x80084064: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80084068: lw          $v0, 0x6E14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E14);
    // 0x8008406C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80084070: lb          $t1, 0x0($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X0);
    // 0x80084074: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80084078: lb          $t9, 0x0($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X0);
    // 0x8008407C: nop

    // 0x80084080: bne         $t9, $t1, L_800840B4
    if (ctx->r25 != ctx->r9) {
        // 0x80084084: nop
    
            goto L_800840B4;
    }
    // 0x80084084: nop

    // 0x80084088: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008408C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084090: swc1        $f8, 0x6E98($at)
    MEM_W(0X6E98, ctx->r1) = ctx->f8.u32l;
    // 0x80084094: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084098: sw          $zero, 0x6EA0($at)
    MEM_W(0X6EA0, ctx->r1) = 0;
    // 0x8008409C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800840A0: sw          $zero, 0x6E9C($at)
    MEM_W(0X6E9C, ctx->r1) = 0;
    // 0x800840A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800840A8: sw          $zero, -0x8C($at)
    MEM_W(-0X8C, ctx->r1) = 0;
    // 0x800840AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800840B0: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
L_800840B4:
    // 0x800840B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800840B8: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
    // 0x800840BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800840C0: nop

    // 0x800840C4: beq         $v0, $zero, L_800841FC
    if (ctx->r2 == 0) {
        // 0x800840C8: slti        $at, $v0, 0x20
        ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
            goto L_800841FC;
    }
    // 0x800840C8: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x800840CC: beq         $at, $zero, L_80084138
    if (ctx->r1 == 0) {
        // 0x800840D0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80084138;
    }
    // 0x800840D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800840D4: bne         $v0, $at, L_800840F4
    if (ctx->r2 != ctx->r1) {
        // 0x800840D8: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_800840F4;
    }
    // 0x800840D8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800840DC: jal         0x80001D04
    // 0x800840E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x800840E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x800840E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800840E8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800840EC: lw          $v0, 0x6E0C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E0C);
    // 0x800840F0: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
L_800840F4:
    // 0x800840F4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800840F8: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800840FC: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80084100: slti        $at, $t3, 0x20
    ctx->r1 = SIGNED(ctx->r11) < 0X20 ? 1 : 0;
    // 0x80084104: bne         $at, $zero, L_800841FC
    if (ctx->r1 != 0) {
        // 0x80084108: sw          $t3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r11;
            goto L_800841FC;
    }
    // 0x80084108: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8008410C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80084110: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80084114: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80084118: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8008411C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x80084120: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084124: jal         0x80001D04
    // 0x80084128: swc1        $f10, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f10.u32l;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x80084128: swc1        $f10, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f10.u32l;
    after_8:
    // 0x8008412C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084130: b           L_800841FC
    // 0x80084134: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
        goto L_800841FC;
    // 0x80084134: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
L_80084138:
    // 0x80084138: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008413C: addiu       $v0, $v0, 0x6E10
    ctx->r2 = ADD32(ctx->r2, 0X6E10);
    // 0x80084140: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80084144: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80084148: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8008414C: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80084150: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80084154: nop

    // 0x80084158: bc1f        L_800841FC
    if (!c1cs) {
        // 0x8008415C: nop
    
            goto L_800841FC;
    }
    // 0x8008415C: nop

    // 0x80084160: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80084164: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80084168: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8008416C: lwc1        $f6, -0x76C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X76C0);
    // 0x80084170: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80084174: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80084178: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8008417C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80084180: bc1f        L_800841B8
    if (!c1cs) {
        // 0x80084184: nop
    
            goto L_800841B8;
    }
    // 0x80084184: nop

    // 0x80084188: lw          $t7, 0x6980($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6980);
    // 0x8008418C: addiu       $a0, $zero, 0x105
    ctx->r4 = ADD32(0, 0X105);
    // 0x80084190: bne         $t7, $zero, L_800841B8
    if (ctx->r15 != 0) {
        // 0x80084194: nop
    
            goto L_800841B8;
    }
    // 0x80084194: nop

    // 0x80084198: jal         0x80001D04
    // 0x8008419C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x8008419C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x800841A0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800841A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800841A8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800841AC: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
    // 0x800841B0: b           L_800841FC
    // 0x800841B4: sw          $t8, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r24;
        goto L_800841FC;
    // 0x800841B4: sw          $t8, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r24;
L_800841B8:
    // 0x800841B8: lwc1        $f8, -0x76BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X76BC);
    // 0x800841BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800841C0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800841C4: nop

    // 0x800841C8: bc1f        L_800841FC
    if (!c1cs) {
        // 0x800841CC: nop
    
            goto L_800841FC;
    }
    // 0x800841CC: nop

    // 0x800841D0: lw          $t9, 0x6980($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6980);
    // 0x800841D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800841D8: bne         $t9, $at, L_800841FC
    if (ctx->r25 != ctx->r1) {
        // 0x800841DC: addiu       $a0, $zero, 0x106
        ctx->r4 = ADD32(0, 0X106);
            goto L_800841FC;
    }
    // 0x800841DC: addiu       $a0, $zero, 0x106
    ctx->r4 = ADD32(0, 0X106);
    // 0x800841E0: jal         0x80001D04
    // 0x800841E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800841E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x800841E8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800841EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800841F0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800841F4: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
    // 0x800841F8: sw          $t1, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r9;
L_800841FC:
    // 0x800841FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084200: lwc1        $f0, 0x6E10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6E10);
    // 0x80084204: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80084208: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8008420C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80084210: nop

    // 0x80084214: bc1f        L_80084344
    if (!c1cs) {
        // 0x80084218: nop
    
            goto L_80084344;
    }
    // 0x80084218: nop

    // 0x8008421C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80084220: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80084224: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80084228: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8008422C: bc1f        L_8008428C
    if (!c1cs) {
        // 0x80084230: nop
    
            goto L_8008428C;
    }
    // 0x80084230: nop

    // 0x80084234: lw          $t2, -0x320($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X320);
    // 0x80084238: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008423C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80084240: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80084244: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80084248: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8008424C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80084250: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80084254: nop

    // 0x80084258: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8008425C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80084260: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80084264: nop

    // 0x80084268: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8008426C: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x80084270: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80084274: andi        $t4, $a0, 0xFF
    ctx->r12 = ctx->r4 & 0XFF;
    // 0x80084278: jal         0x80001990
    // 0x8008427C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    music_volume_set(rdram, ctx);
        goto after_11;
    // 0x8008427C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_11:
    // 0x80084280: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084284: b           L_80084344
    // 0x80084288: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
        goto L_80084344;
    // 0x80084288: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
L_8008428C:
    // 0x8008428C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80084290: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084294: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80084298: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8008429C: bc1f        L_800842C4
    if (!c1cs) {
        // 0x800842A0: nop
    
            goto L_800842C4;
    }
    // 0x800842A0: nop

    // 0x800842A4: lw          $a0, -0x320($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X320);
    // 0x800842A8: nop

    // 0x800842AC: sra         $t5, $a0, 1
    ctx->r13 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800842B0: jal         0x80001990
    // 0x800842B4: andi        $a0, $t5, 0xFF
    ctx->r4 = ctx->r13 & 0XFF;
    music_volume_set(rdram, ctx);
        goto after_12;
    // 0x800842B4: andi        $a0, $t5, 0xFF
    ctx->r4 = ctx->r13 & 0XFF;
    after_12:
    // 0x800842B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800842BC: b           L_80084344
    // 0x800842C0: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
        goto L_80084344;
    // 0x800842C0: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
L_800842C4:
    // 0x800842C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800842C8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800842CC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800842D0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800842D4: bc1f        L_80084330
    if (!c1cs) {
        // 0x800842D8: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80084330;
    }
    // 0x800842D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800842DC: lw          $t7, -0x320($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X320);
    // 0x800842E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800842E4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800842E8: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800842EC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800842F0: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800842F4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800842F8: nop

    // 0x800842FC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80084300: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80084304: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80084308: nop

    // 0x8008430C: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80084310: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80084314: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80084318: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x8008431C: jal         0x80001990
    // 0x80084320: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    music_volume_set(rdram, ctx);
        goto after_13;
    // 0x80084320: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_13:
    // 0x80084324: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084328: b           L_80084344
    // 0x8008432C: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
        goto L_80084344;
    // 0x8008432C: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
L_80084330:
    // 0x80084330: lbu         $a0, -0x31D($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X31D);
    // 0x80084334: jal         0x80001990
    // 0x80084338: nop

    music_volume_set(rdram, ctx);
        goto after_14;
    // 0x80084338: nop

    after_14:
    // 0x8008433C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084340: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
L_80084344:
    // 0x80084344: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80084348: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008434C: bne         $t1, $zero, L_80084374
    if (ctx->r9 != 0) {
        // 0x80084350: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_80084374;
    }
    // 0x80084350: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80084354: addiu       $v0, $v0, 0x6D78
    ctx->r2 = ADD32(ctx->r2, 0X6D78);
    // 0x80084358: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x8008435C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80084360: andi        $t3, $t2, 0x9000
    ctx->r11 = ctx->r10 & 0X9000;
    // 0x80084364: beq         $t3, $zero, L_80084484
    if (ctx->r11 == 0) {
        // 0x80084368: nop
    
            goto L_80084484;
    }
    // 0x80084368: nop

    // 0x8008436C: b           L_80084484
    // 0x80084370: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
        goto L_80084484;
    // 0x80084370: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_80084374:
    // 0x80084374: lw          $t5, -0x604($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X604);
    // 0x80084378: nop

    // 0x8008437C: bne         $t5, $zero, L_80084484
    if (ctx->r13 != 0) {
        // 0x80084380: nop
    
            goto L_80084484;
    }
    // 0x80084380: nop

    // 0x80084384: jal         0x8006F708
    // 0x80084388: nop

    is_controller_missing(rdram, ctx);
        goto after_15;
    // 0x80084388: nop

    after_15:
    // 0x8008438C: bne         $v0, $zero, L_80084484
    if (ctx->r2 != 0) {
        // 0x80084390: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80084484;
    }
    // 0x80084390: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084394: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80084398: lw          $v0, -0x624($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X624);
    // 0x8008439C: lh          $v1, 0x6DD8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X6DD8);
    // 0x800843A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800843A4: bgez        $v1, L_800843C8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800843A8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800843C8;
    }
    // 0x800843A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800843AC: bgtz        $v0, L_800843C8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800843B0: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_800843C8;
    }
    // 0x800843B0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800843B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800843B8: sw          $t6, -0x624($at)
    MEM_W(-0X624, ctx->r1) = ctx->r14;
    // 0x800843BC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800843C0: lw          $v0, -0x624($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X624);
    // 0x800843C4: nop

L_800843C8:
    // 0x800843C8: blez        $v1, L_800843EC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800843CC: nop
    
            goto L_800843EC;
    }
    // 0x800843CC: nop

    // 0x800843D0: blez        $v0, L_800843EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800843D4: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800843EC;
    }
    // 0x800843D4: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800843D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800843DC: sw          $t7, -0x624($at)
    MEM_W(-0X624, ctx->r1) = ctx->r15;
    // 0x800843E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800843E4: lw          $v0, -0x624($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X624);
    // 0x800843E8: nop

L_800843EC:
    // 0x800843EC: beq         $a0, $v0, L_800843FC
    if (ctx->r4 == ctx->r2) {
        // 0x800843F0: nop
    
            goto L_800843FC;
    }
    // 0x800843F0: nop

    // 0x800843F4: jal         0x80001D04
    // 0x800843F8: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    sound_play(rdram, ctx);
        goto after_16;
    // 0x800843F8: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    after_16:
L_800843FC:
    // 0x800843FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80084400: addiu       $v0, $v0, 0x6D78
    ctx->r2 = ADD32(ctx->r2, 0X6D78);
    // 0x80084404: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x80084408: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008440C: andi        $t9, $t8, 0x9000
    ctx->r25 = ctx->r24 & 0X9000;
    // 0x80084410: beq         $t9, $zero, L_80084484
    if (ctx->r25 == 0) {
        // 0x80084414: nop
    
            goto L_80084484;
    }
    // 0x80084414: nop

    // 0x80084418: lw          $t1, 0x6D84($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6D84);
    // 0x8008441C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80084420: andi        $t2, $t1, 0x9000
    ctx->r10 = ctx->r9 & 0X9000;
    // 0x80084424: bne         $t2, $zero, L_80084450
    if (ctx->r10 != 0) {
        // 0x80084428: nop
    
            goto L_80084450;
    }
    // 0x80084428: nop

L_8008442C:
    // 0x8008442C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80084430: blez        $a2, L_80084450
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80084434: sll         $t3, $a2, 2
        ctx->r11 = S32(ctx->r6 << 2);
            goto L_80084450;
    }
    // 0x80084434: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x80084438: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x8008443C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80084440: nop

    // 0x80084444: andi        $t6, $t5, 0x9000
    ctx->r14 = ctx->r13 & 0X9000;
    // 0x80084448: beq         $t6, $zero, L_8008442C
    if (ctx->r14 == 0) {
        // 0x8008444C: nop
    
            goto L_8008442C;
    }
    // 0x8008444C: nop

L_80084450:
    // 0x80084450: jal         0x8008B3B8
    // 0x80084454: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    titlescreen_controller_assign(rdram, ctx);
        goto after_17;
    // 0x80084454: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_17:
    // 0x80084458: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008445C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084460: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084464: sw          $t7, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r15;
    // 0x80084468: jal         0x800C06F8
    // 0x8008446C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_18;
    // 0x8008446C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_18:
    // 0x80084470: jal         0x800C0690
    // 0x80084474: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_19;
    // 0x80084474: nop

    after_19:
    // 0x80084478: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008447C: jal         0x80001D04
    // 0x80084480: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_20;
    // 0x80084480: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
L_80084484:
    // 0x80084484: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80084488: lw          $t8, -0x604($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X604);
    // 0x8008448C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80084490: slti        $at, $t8, 0x1F
    ctx->r1 = SIGNED(ctx->r24) < 0X1F ? 1 : 0;
    // 0x80084494: bne         $at, $zero, L_80084538
    if (ctx->r1 != 0) {
        // 0x80084498: nop
    
            goto L_80084538;
    }
    // 0x80084498: nop

    // 0x8008449C: jal         0x80084550
    // 0x800844A0: nop

    titlescreen_free(rdram, ctx);
        goto after_21;
    // 0x800844A0: nop

    after_21:
    // 0x800844A4: jal         0x800C06A0
    // 0x800844A8: nop

    disable_new_screen_transitions(rdram, ctx);
        goto after_22;
    // 0x800844A8: nop

    after_22:
    // 0x800844AC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800844B0: lw          $t9, -0x624($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X624);
    // 0x800844B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800844B8: bne         $t9, $zero, L_80084518
    if (ctx->r25 != 0) {
        // 0x800844BC: addiu       $a0, $zero, 0x27
        ctx->r4 = ADD32(0, 0X27);
            goto L_80084518;
    }
    // 0x800844BC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800844C0: jal         0x8009F214
    // 0x800844C4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    is_drumstick_unlocked(rdram, ctx);
        goto after_23;
    // 0x800844C4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_23:
    // 0x800844C8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800844CC: beq         $v0, $zero, L_800844D8
    if (ctx->r2 == 0) {
        // 0x800844D0: nop
    
            goto L_800844D8;
    }
    // 0x800844D0: nop

    // 0x800844D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800844D8:
    // 0x800844D8: jal         0x8009F1FC
    // 0x800844DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    is_tt_unlocked(rdram, ctx);
        goto after_24;
    // 0x800844DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_24:
    // 0x800844E0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800844E4: beq         $v0, $zero, L_800844F4
    if (ctx->r2 == 0) {
        // 0x800844E8: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_800844F4;
    }
    // 0x800844E8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800844EC: xori        $t1, $a2, 0x3
    ctx->r9 = ctx->r6 ^ 0X3;
    // 0x800844F0: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
L_800844F4:
    // 0x800844F4: jal         0x8006E528
    // 0x800844F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    load_level_for_menu(rdram, ctx);
        goto after_25;
    // 0x800844F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_25:
    // 0x800844FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084500: jal         0x8008B36C
    // 0x80084504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    charselect_prev(rdram, ctx);
        goto after_26;
    // 0x80084504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x80084508: jal         0x80081820
    // 0x8008450C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    menu_init(rdram, ctx);
        goto after_27;
    // 0x8008450C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_27:
    // 0x80084510: b           L_80084540
    // 0x80084514: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084540;
    // 0x80084514: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80084518:
    // 0x80084518: sw          $zero, -0x620($at)
    MEM_W(-0X620, ctx->r1) = 0;
    // 0x8008451C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80084520: jal         0x8006E528
    // 0x80084524: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_28;
    // 0x80084524: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_28:
    // 0x80084528: jal         0x80081820
    // 0x8008452C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    menu_init(rdram, ctx);
        goto after_29;
    // 0x8008452C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_29:
    // 0x80084530: b           L_80084540
    // 0x80084534: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084540;
    // 0x80084534: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80084538:
    // 0x80084538: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008453C: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_80084540:
    // 0x80084540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084544: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80084548: jr          $ra
    // 0x8008454C: nop

    return;
    // 0x8008454C: nop

;}
RECOMP_FUNC void get_current_level_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C804: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8002C808: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x8002C80C: jr          $ra
    // 0x8002C810: nop

    return;
    // 0x8002C810: nop

;}
RECOMP_FUNC void racer_sound_doppler_effect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006BFC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80006C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006C04: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80006C08: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x80006C0C: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80006C10: lw          $t6, 0x118($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X118);
    // 0x80006C14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80006C18: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80006C1C: sw          $t6, -0x5E48($at)
    MEM_W(-0X5E48, ctx->r1) = ctx->r14;
    // 0x80006C20: lw          $t7, -0x5E48($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E48);
    // 0x80006C24: nop

    // 0x80006C28: beq         $t7, $zero, L_80006FBC
    if (ctx->r15 == 0) {
        // 0x80006C2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80006FBC;
    }
    // 0x80006C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006C30: beq         $a1, $zero, L_80006C6C
    if (ctx->r5 == 0) {
        // 0x80006C34: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80006C6C;
    }
    // 0x80006C34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80006C38: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80006C3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80006C40: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80006C44: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80006C48: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80006C4C: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x80006C50: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80006C54: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80006C58: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80006C5C: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80006C60: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80006C64: b           L_80006D84
    // 0x80006C68: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
        goto L_80006D84;
    // 0x80006C68: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
L_80006C6C:
    // 0x80006C6C: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80006C70: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80006C74: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80006C78: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80006C7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80006C80: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80006C84: lb          $v0, 0x1D6($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X1D6);
    // 0x80006C88: nop

    // 0x80006C8C: beq         $v0, $zero, L_80006CA4
    if (ctx->r2 == 0) {
        // 0x80006C90: nop
    
            goto L_80006CA4;
    }
    // 0x80006C90: nop

    // 0x80006C94: beq         $v0, $at, L_80006CD0
    if (ctx->r2 == ctx->r1) {
        // 0x80006C98: nop
    
            goto L_80006CD0;
    }
    // 0x80006C98: nop

    // 0x80006C9C: b           L_80006D0C
    // 0x80006CA0: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
        goto L_80006D0C;
    // 0x80006CA0: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
L_80006CA4:
    // 0x80006CA4: lwc1        $f0, 0x2C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80006CA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80006CAC: nop

    // 0x80006CB0: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80006CB4: nop

    // 0x80006CB8: bc1f        L_80006CC8
    if (!c1cs) {
        // 0x80006CBC: nop
    
            goto L_80006CC8;
    }
    // 0x80006CBC: nop

    // 0x80006CC0: b           L_80006D48
    // 0x80006CC4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80006D48;
    // 0x80006CC4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80006CC8:
    // 0x80006CC8: b           L_80006D48
    // 0x80006CCC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80006D48;
    // 0x80006CCC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_80006CD0:
    // 0x80006CD0: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80006CD4: lwc1        $f2, 0x24($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80006CD8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80006CDC: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80006CE0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80006CE4: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80006CE8: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80006CEC: jal         0x800CA030
    // 0x80006CF0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80006CF0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80006CF4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80006CF8: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80006CFC: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80006D00: b           L_80006D48
    // 0x80006D04: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80006D48;
    // 0x80006D04: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80006D08: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
L_80006D0C:
    // 0x80006D0C: lwc1        $f2, 0x24($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80006D10: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80006D14: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80006D18: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80006D1C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80006D20: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80006D24: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80006D28: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80006D2C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006D30: jal         0x800CA030
    // 0x80006D34: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80006D34: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x80006D38: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80006D3C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80006D40: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80006D44: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80006D48:
    // 0x80006D48: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80006D4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80006D50: nop

    // 0x80006D54: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80006D58: nop

    // 0x80006D5C: bc1f        L_80006D6C
    if (!c1cs) {
        // 0x80006D60: nop
    
            goto L_80006D6C;
    }
    // 0x80006D60: nop

    // 0x80006D64: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x80006D68: nop

L_80006D6C:
    // 0x80006D6C: div.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80006D70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80006D74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80006D78: nop

    // 0x80006D7C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80006D80: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
L_80006D84:
    // 0x80006D84: lwc1        $f10, 0xC($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80006D88: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80006D8C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80006D90: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80006D94: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80006D98: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80006D9C: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80006DA0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80006DA4: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80006DA8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80006DAC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80006DB0: nop

    // 0x80006DB4: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80006DB8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006DBC: jal         0x800CA030
    // 0x80006DC0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80006DC0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80006DC4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80006DC8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80006DCC: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80006DD0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006DD4: lw          $v0, -0x5E48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E48);
    // 0x80006DD8: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80006DDC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80006DE0: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80006DE4: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80006DE8: lwc1        $f4, 0x6C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X6C);
    // 0x80006DEC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80006DF0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80006DF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80006DF8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80006DFC: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80006E00: div.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80006E04: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80006E08: nop

    // 0x80006E0C: bc1f        L_80006E1C
    if (!c1cs) {
        // 0x80006E10: nop
    
            goto L_80006E1C;
    }
    // 0x80006E10: nop

    // 0x80006E14: b           L_80006E38
    // 0x80006E18: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
        goto L_80006E38;
    // 0x80006E18: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_80006E1C:
    // 0x80006E1C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80006E20: nop

    // 0x80006E24: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80006E28: nop

    // 0x80006E2C: bc1f        L_80006E38
    if (!c1cs) {
        // 0x80006E30: nop
    
            goto L_80006E38;
    }
    // 0x80006E30: nop

    // 0x80006E34: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80006E38:
    // 0x80006E38: lwc1        $f12, 0x5C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80006E3C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80006E40: jal         0x80007FA4
    // 0x80006E44: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    log(rdram, ctx);
        goto after_3;
    // 0x80006E44: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_3:
    // 0x80006E48: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80006E4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80006E50: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80006E54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006E58: add.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80006E5C: lwc1        $f5, 0x5230($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5230);
    // 0x80006E60: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80006E64: nop

    // 0x80006E68: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80006E6C: lwc1        $f4, 0x5234($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5234);
    // 0x80006E70: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80006E74: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80006E78: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80006E7C: nop

    // 0x80006E80: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80006E84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80006E88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80006E8C: nop

    // 0x80006E90: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x80006E94: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80006E98: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80006E9C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80006EA0: nop

    // 0x80006EA4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80006EA8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80006EAC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80006EB0: nop

    // 0x80006EB4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80006EB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80006EBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80006EC0: nop

    // 0x80006EC4: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80006EC8: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80006ECC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80006ED0: jal         0x800C9F40
    // 0x80006ED4: nop

    alCents2Ratio(rdram, ctx);
        goto after_4;
    // 0x80006ED4: nop

    after_4:
    // 0x80006ED8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006EDC: lw          $v0, -0x5E48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E48);
    // 0x80006EE0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80006EE4: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80006EE8: lwc1        $f2, 0x68($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80006EEC: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80006EF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80006EF4: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80006EF8: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80006EFC: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80006F00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006F04: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80006F08: swc1        $f8, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f8.u32l;
    // 0x80006F0C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006F10: lw          $v0, -0x5E48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E48);
    // 0x80006F14: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80006F18: lwc1        $f10, 0x68($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80006F1C: nop

    // 0x80006F20: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80006F24: swc1        $f6, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f6.u32l;
    // 0x80006F28: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006F2C: lw          $v0, -0x5E48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E48);
    // 0x80006F30: lwc1        $f10, 0x523C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X523C);
    // 0x80006F34: lwc1        $f8, 0x68($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80006F38: lwc1        $f11, 0x5238($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X5238);
    // 0x80006F3C: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x80006F40: c.lt.d      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.d < ctx->f12.d;
    // 0x80006F44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006F48: bc1f        L_80006F70
    if (!c1cs) {
        // 0x80006F4C: nop
    
            goto L_80006F70;
    }
    // 0x80006F4C: nop

    // 0x80006F50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006F54: lwc1        $f4, 0x5240($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5240);
    // 0x80006F58: nop

    // 0x80006F5C: swc1        $f4, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f4.u32l;
    // 0x80006F60: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006F64: lw          $v0, -0x5E48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E48);
    // 0x80006F68: b           L_80006FA8
    // 0x80006F6C: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
        goto L_80006FA8;
    // 0x80006F6C: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
L_80006F70:
    // 0x80006F70: lwc1        $f7, 0x5248($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5248);
    // 0x80006F74: lwc1        $f6, 0x524C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X524C);
    // 0x80006F78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006F7C: c.lt.d      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.d < ctx->f6.d;
    // 0x80006F80: nop

    // 0x80006F84: bc1f        L_80006FA4
    if (!c1cs) {
        // 0x80006F88: nop
    
            goto L_80006FA4;
    }
    // 0x80006F88: nop

    // 0x80006F8C: lwc1        $f8, 0x5250($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5250);
    // 0x80006F90: nop

    // 0x80006F94: swc1        $f8, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f8.u32l;
    // 0x80006F98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006F9C: lw          $v0, -0x5E48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E48);
    // 0x80006FA0: nop

L_80006FA4:
    // 0x80006FA4: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
L_80006FA8:
    // 0x80006FA8: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80006FAC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80006FB0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80006FB4: swc1        $f10, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = ctx->f10.u32l;
    // 0x80006FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006FBC:
    // 0x80006FBC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80006FC0: jr          $ra
    // 0x80006FC4: nop

    return;
    // 0x80006FC4: nop

;}
RECOMP_FUNC void spectate_nearest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BE08: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BE0C: lw          $v0, -0x4BA0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BA0);
    // 0x8001BE10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001BE14: bne         $v0, $zero, L_8001BE24
    if (ctx->r2 != 0) {
        // 0x8001BE18: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8001BE24;
    }
    // 0x8001BE18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001BE1C: b           L_8001BF4C
    // 0x8001BE20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001BF4C;
    // 0x8001BE20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BE24:
    // 0x8001BE24: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8001BE28: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001BE2C: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x8001BE30: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BE34: bne         $at, $zero, L_8001BE40
    if (ctx->r1 != 0) {
        // 0x8001BE38: addiu       $a2, $a0, -0x1
        ctx->r6 = ADD32(ctx->r4, -0X1);
            goto L_8001BE40;
    }
    // 0x8001BE38: addiu       $a2, $a0, -0x1
    ctx->r6 = ADD32(ctx->r4, -0X1);
    // 0x8001BE3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001BE40:
    // 0x8001BE40: bgez        $a2, L_8001BE4C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8001BE44: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8001BE4C;
    }
    // 0x8001BE44: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8001BE48: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
L_8001BE4C:
    // 0x8001BE4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BE50: lw          $v0, -0x4BA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BA4);
    // 0x8001BE54: lwc1        $f2, 0xC($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8001BE58: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8001BE5C: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    // 0x8001BE60: lwc1        $f14, 0x10($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8001BE64: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8001BE68: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8001BE6C: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8001BE70: lwc1        $f18, 0x14($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X14);
    // 0x8001BE74: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001BE78: sub.s       $f12, $f6, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x8001BE7C: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8001BE80: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8001BE84: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001BE88: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8001BE8C: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8001BE90: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8001BE94: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8001BE98: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001BE9C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8001BEA0: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8001BEA4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001BEA8: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x8001BEAC: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x8001BEB0: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8001BEB4: lwc1        $f6, 0x10($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X10);
    // 0x8001BEB8: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8001BEBC: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8001BEC0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001BEC4: sub.s       $f12, $f6, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x8001BEC8: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001BECC: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8001BED0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001BED4: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8001BED8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001BEDC: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x8001BEE0: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8001BEE4: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8001BEE8: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8001BEEC: lwc1        $f4, 0x10($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X10);
    // 0x8001BEF0: lwc1        $f8, 0x14($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X14);
    // 0x8001BEF4: sub.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8001BEF8: bc1f        L_8001BF10
    if (!c1cs) {
        // 0x8001BEFC: sub.s       $f16, $f8, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
            goto L_8001BF10;
    }
    // 0x8001BEFC: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8001BF00: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8001BF04: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8001BF08: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x8001BF0C: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
L_8001BF10:
    // 0x8001BF10: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001BF14: nop

    // 0x8001BF18: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001BF1C: nop

    // 0x8001BF20: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8001BF24: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001BF28: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8001BF2C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001BF30: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8001BF34: nop

    // 0x8001BF38: bc1f        L_8001BF48
    if (!c1cs) {
        // 0x8001BF3C: nop
    
            goto L_8001BF48;
    }
    // 0x8001BF3C: nop

    // 0x8001BF40: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x8001BF44: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
L_8001BF48:
    // 0x8001BF48: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8001BF4C:
    // 0x8001BF4C: jr          $ra
    // 0x8001BF50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001BF50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void audspat_line_validate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800099EC: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800099F0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800099F4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800099F8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800099FC: addiu       $t8, $t8, -0x5E28
    ctx->r24 = ADD32(ctx->r24, -0X5E28);
    // 0x80009A00: sll         $t7, $t7, 7
    ctx->r15 = S32(ctx->r15 << 7);
    // 0x80009A04: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80009A08: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80009A0C: lb          $a3, 0x17C($v0)
    ctx->r7 = MEM_B(ctx->r2, 0X17C);
    // 0x80009A10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80009A14: bgtz        $a3, L_80009A24
    if (SIGNED(ctx->r7) > 0) {
        // 0x80009A18: addiu       $a2, $v0, 0x4
        ctx->r6 = ADD32(ctx->r2, 0X4);
            goto L_80009A24;
    }
    // 0x80009A18: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x80009A1C: jr          $ra
    // 0x80009A20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80009A20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80009A24:
    // 0x80009A24: blez        $a3, L_80009AA8
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80009A28: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80009AA8;
    }
    // 0x80009A28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009A2C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80009A30: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80009A34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009A38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80009A3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80009A40: lwc1        $f3, 0x54A8($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X54A8);
    // 0x80009A44: lwc1        $f2, 0x54AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X54AC);
    // 0x80009A48: lb          $a1, 0x17C($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X17C);
    // 0x80009A4C: nop

L_80009A50:
    // 0x80009A50: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80009A54: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80009A58: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80009A5C: c.eq.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d == ctx->f4.d;
    // 0x80009A60: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80009A64: bc1t        L_80009A9C
    if (c1cs) {
        // 0x80009A68: nop
    
            goto L_80009A9C;
    }
    // 0x80009A68: nop

    // 0x80009A6C: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80009A70: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80009A74: c.eq.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d == ctx->f8.d;
    // 0x80009A78: nop

    // 0x80009A7C: bc1t        L_80009A9C
    if (c1cs) {
        // 0x80009A80: nop
    
            goto L_80009A9C;
    }
    // 0x80009A80: nop

    // 0x80009A84: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80009A88: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80009A8C: c.eq.d      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.d == ctx->f16.d;
    // 0x80009A90: nop

    // 0x80009A94: bc1f        L_80009AA0
    if (!c1cs) {
        // 0x80009A98: nop
    
            goto L_80009AA0;
    }
    // 0x80009A98: nop

L_80009A9C:
    // 0x80009A9C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80009AA0:
    // 0x80009AA0: bne         $at, $zero, L_80009A50
    if (ctx->r1 != 0) {
        // 0x80009AA4: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_80009A50;
    }
    // 0x80009AA4: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
L_80009AA8:
    // 0x80009AA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80009AAC: jr          $ra
    // 0x80009AB0: nop

    return;
    // 0x80009AB0: nop

;}
RECOMP_FUNC void update_camera_plane(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C2F0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8004C2F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004C2F8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8004C2FC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8004C300: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004C304: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8004C308: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004C30C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004C310: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x8004C314: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8004C318: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004C31C: lwc1        $f4, -0x2590($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2590);
    // 0x8004C320: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8004C324: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004C328: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004C32C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8004C330: sub.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8004C334: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8004C338: nop

    // 0x8004C33C: bc1f        L_8004C348
    if (!c1cs) {
        // 0x8004C340: nop
    
            goto L_8004C348;
    }
    // 0x8004C340: nop

    // 0x8004C344: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
L_8004C348:
    // 0x8004C348: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8004C34C: nop

    // 0x8004C350: bc1f        L_8004C35C
    if (!c1cs) {
        // 0x8004C354: nop
    
            goto L_8004C35C;
    }
    // 0x8004C354: nop

    // 0x8004C358: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
L_8004C35C:
    // 0x8004C35C: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x8004C360: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x8004C364: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8004C368: jal         0x80066450
    // 0x8004C36C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8004C36C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8004C370: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004C374: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004C378: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004C37C: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004C380: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004C384: bne         $v0, $at, L_8004C3A4
    if (ctx->r2 != ctx->r1) {
        // 0x8004C388: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8004C3A4;
    }
    // 0x8004C388: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004C38C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004C390: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004C394: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8004C398: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004C39C: b           L_8004C3C0
    // 0x8004C3A0: nop

        goto L_8004C3C0;
    // 0x8004C3A0: nop

L_8004C3A4:
    // 0x8004C3A4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004C3A8: bne         $at, $zero, L_8004C3C0
    if (ctx->r1 != 0) {
        // 0x8004C3AC: lui         $at, 0x42DC
        ctx->r1 = S32(0X42DC << 16);
            goto L_8004C3C0;
    }
    // 0x8004C3AC: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8004C3B0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004C3B4: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x8004C3B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004C3BC: nop

L_8004C3C0:
    // 0x8004C3C0: lw          $t7, -0x2558($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2558);
    // 0x8004C3C4: nop

    // 0x8004C3C8: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8004C3CC: beq         $t8, $zero, L_8004C3E8
    if (ctx->r24 == 0) {
        // 0x8004C3D0: nop
    
            goto L_8004C3E8;
    }
    // 0x8004C3D0: nop

    // 0x8004C3D4: lb          $t9, 0x1E2($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X1E2);
    // 0x8004C3D8: nop

    // 0x8004C3DC: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x8004C3E0: beq         $at, $zero, L_8004C548
    if (ctx->r1 == 0) {
        // 0x8004C3E4: nop
    
            goto L_8004C548;
    }
    // 0x8004C3E4: nop

L_8004C3E8:
    // 0x8004C3E8: lbu         $t2, 0x1F5($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X1F5);
    // 0x8004C3EC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8004C3F0: bne         $t2, $zero, L_8004C548
    if (ctx->r10 != 0) {
        // 0x8004C3F4: nop
    
            goto L_8004C548;
    }
    // 0x8004C3F4: nop

    // 0x8004C3F8: lh          $t3, 0x1A0($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X1A0);
    // 0x8004C3FC: lh          $t5, 0x196($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X196);
    // 0x8004C400: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8004C404: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8004C408: subu        $a0, $t4, $t6
    ctx->r4 = SUB32(ctx->r12, ctx->r14);
    // 0x8004C40C: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x8004C410: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004C414: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004C418: bne         $at, $zero, L_8004C428
    if (ctx->r1 != 0) {
        // 0x8004C41C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004C428;
    }
    // 0x8004C41C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004C420: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004C424: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_8004C428:
    // 0x8004C428: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x8004C42C: beq         $at, $zero, L_8004C438
    if (ctx->r1 == 0) {
        // 0x8004C430: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004C438;
    }
    // 0x8004C430: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004C434: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_8004C438:
    // 0x8004C438: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004C43C: lwc1        $f8, 0x94($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X94);
    // 0x8004C440: lwc1        $f11, 0x6AE8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6AE8);
    // 0x8004C444: lwc1        $f10, 0x6AEC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6AEC);
    // 0x8004C448: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8004C44C: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x8004C450: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004C454: bc1f        L_8004C47C
    if (!c1cs) {
        // 0x8004C458: nop
    
            goto L_8004C47C;
    }
    // 0x8004C458: nop

    // 0x8004C45C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004C460: lwc1        $f5, 0x6AF0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6AF0);
    // 0x8004C464: lwc1        $f4, 0x6AF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6AF4);
    // 0x8004C468: nop

    // 0x8004C46C: add.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f0.d + ctx->f4.d;
    // 0x8004C470: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8004C474: b           L_8004C488
    // 0x8004C478: swc1        $f8, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f8.u32l;
        goto L_8004C488;
    // 0x8004C478: swc1        $f8, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f8.u32l;
L_8004C47C:
    // 0x8004C47C: lwc1        $f10, 0x6AF8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6AF8);
    // 0x8004C480: nop

    // 0x8004C484: swc1        $f10, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f10.u32l;
L_8004C488:
    // 0x8004C488: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8004C48C: lwc1        $f8, 0x94($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X94);
    // 0x8004C490: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004C494: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004C498: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8004C49C: nop

    // 0x8004C4A0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8004C4A4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004C4A8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004C4AC: nop

    // 0x8004C4B0: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8004C4B4: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8004C4B8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8004C4BC: slti        $at, $v1, 0x201
    ctx->r1 = SIGNED(ctx->r3) < 0X201 ? 1 : 0;
    // 0x8004C4C0: bne         $at, $zero, L_8004C4D0
    if (ctx->r1 != 0) {
        // 0x8004C4C4: slti        $at, $v1, -0x200
        ctx->r1 = SIGNED(ctx->r3) < -0X200 ? 1 : 0;
            goto L_8004C4D0;
    }
    // 0x8004C4C4: slti        $at, $v1, -0x200
    ctx->r1 = SIGNED(ctx->r3) < -0X200 ? 1 : 0;
    // 0x8004C4C8: addiu       $v1, $zero, 0x200
    ctx->r3 = ADD32(0, 0X200);
    // 0x8004C4CC: slti        $at, $v1, -0x200
    ctx->r1 = SIGNED(ctx->r3) < -0X200 ? 1 : 0;
L_8004C4D0:
    // 0x8004C4D0: beq         $at, $zero, L_8004C4DC
    if (ctx->r1 == 0) {
        // 0x8004C4D4: nop
    
            goto L_8004C4DC;
    }
    // 0x8004C4D4: nop

    // 0x8004C4D8: addiu       $v1, $zero, -0x200
    ctx->r3 = ADD32(0, -0X200);
L_8004C4DC:
    // 0x8004C4DC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8004C4E0: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004C4E4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8004C4E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004C4EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004C4F0: nop

    // 0x8004C4F4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8004C4F8: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8004C4FC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8004C500: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004C504: mflo        $v1
    ctx->r3 = lo;
    // 0x8004C508: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8004C50C: bgez        $a0, L_8004C520
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8004C510: nop
    
            goto L_8004C520;
    }
    // 0x8004C510: nop

    // 0x8004C514: beq         $at, $zero, L_8004C520
    if (ctx->r1 == 0) {
        // 0x8004C518: nop
    
            goto L_8004C520;
    }
    // 0x8004C518: nop

    // 0x8004C51C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8004C520:
    // 0x8004C520: blez        $a0, L_8004C534
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8004C524: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8004C534;
    }
    // 0x8004C524: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004C528: beq         $at, $zero, L_8004C534
    if (ctx->r1 == 0) {
        // 0x8004C52C: nop
    
            goto L_8004C534;
    }
    // 0x8004C52C: nop

    // 0x8004C530: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8004C534:
    // 0x8004C534: lh          $t9, 0x196($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X196);
    // 0x8004C538: nop

    // 0x8004C53C: addu        $t2, $t9, $v1
    ctx->r10 = ADD32(ctx->r25, ctx->r3);
    // 0x8004C540: b           L_8004C578
    // 0x8004C544: sh          $t2, 0x196($a3)
    MEM_H(0X196, ctx->r7) = ctx->r10;
        goto L_8004C578;
    // 0x8004C544: sh          $t2, 0x196($a3)
    MEM_H(0X196, ctx->r7) = ctx->r10;
L_8004C548:
    // 0x8004C548: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8004C54C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004C550: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8004C554: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004C558: swc1        $f10, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f10.u32l;
    // 0x8004C55C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004C560: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004C564: nop

    // 0x8004C568: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8004C56C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8004C570: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8004C574: nop

L_8004C578:
    // 0x8004C578: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004C57C: lh          $t5, -0x24FA($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X24FA);
    // 0x8004C580: nop

    // 0x8004C584: beq         $t5, $zero, L_8004C59C
    if (ctx->r13 == 0) {
        // 0x8004C588: nop
    
            goto L_8004C59C;
    }
    // 0x8004C588: nop

    // 0x8004C58C: lh          $t4, 0x1A0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1A0);
    // 0x8004C590: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x8004C594: subu        $t7, $t6, $t4
    ctx->r15 = SUB32(ctx->r14, ctx->r12);
    // 0x8004C598: sh          $t7, 0x196($a3)
    MEM_H(0X196, ctx->r7) = ctx->r15;
L_8004C59C:
    // 0x8004C59C: lb          $v1, 0x1E0($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1E0);
    // 0x8004C5A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004C5A4: beq         $v1, $at, L_8004C5B4
    if (ctx->r3 == ctx->r1) {
        // 0x8004C5A8: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8004C5B4;
    }
    // 0x8004C5A8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004C5AC: bne         $v1, $at, L_8004C5C0
    if (ctx->r3 != ctx->r1) {
        // 0x8004C5B0: lw          $t8, 0x54($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X54);
            goto L_8004C5C0;
    }
    // 0x8004C5B0: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_8004C5B4:
    // 0x8004C5B4: b           L_8004C5EC
    // 0x8004C5B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8004C5EC;
    // 0x8004C5B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004C5BC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_8004C5C0:
    // 0x8004C5C0: nop

    // 0x8004C5C4: lh          $a0, 0x2($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X2);
    // 0x8004C5C8: nop

    // 0x8004C5CC: slti        $at, $a0, 0x3001
    ctx->r1 = SIGNED(ctx->r4) < 0X3001 ? 1 : 0;
    // 0x8004C5D0: bne         $at, $zero, L_8004C5E0
    if (ctx->r1 != 0) {
        // 0x8004C5D4: slti        $at, $a0, -0x3000
        ctx->r1 = SIGNED(ctx->r4) < -0X3000 ? 1 : 0;
            goto L_8004C5E0;
    }
    // 0x8004C5D4: slti        $at, $a0, -0x3000
    ctx->r1 = SIGNED(ctx->r4) < -0X3000 ? 1 : 0;
    // 0x8004C5D8: addiu       $a0, $zero, 0x3000
    ctx->r4 = ADD32(0, 0X3000);
    // 0x8004C5DC: slti        $at, $a0, -0x3000
    ctx->r1 = SIGNED(ctx->r4) < -0X3000 ? 1 : 0;
L_8004C5E0:
    // 0x8004C5E0: beq         $at, $zero, L_8004C5F0
    if (ctx->r1 == 0) {
        // 0x8004C5E4: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8004C5F0;
    }
    // 0x8004C5E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004C5E8: addiu       $a0, $zero, -0x3000
    ctx->r4 = ADD32(0, -0X3000);
L_8004C5EC:
    // 0x8004C5EC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_8004C5F0:
    // 0x8004C5F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8004C5F4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004C5F8: mul.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004C5FC: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x8004C600: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004C604: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8004C608: lh          $a2, 0x2($a1)
    ctx->r6 = MEM_H(ctx->r5, 0X2);
    // 0x8004C60C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8004C610: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004C614: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004C618: andi        $t3, $a2, 0xFFFF
    ctx->r11 = ctx->r6 & 0XFFFF;
    // 0x8004C61C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8004C620: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004C624: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8004C628: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8004C62C: subu        $a0, $a0, $t2
    ctx->r4 = SUB32(ctx->r4, ctx->r10);
    // 0x8004C630: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8004C634: subu        $v1, $a0, $t3
    ctx->r3 = SUB32(ctx->r4, ctx->r11);
    // 0x8004C638: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004C63C: bne         $at, $zero, L_8004C650
    if (ctx->r1 != 0) {
        // 0x8004C640: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8004C650;
    }
    // 0x8004C640: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8004C644: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004C648: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004C64C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004C650:
    // 0x8004C650: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8004C654: beq         $at, $zero, L_8004C660
    if (ctx->r1 == 0) {
        // 0x8004C658: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004C660;
    }
    // 0x8004C658: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004C65C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004C660:
    // 0x8004C660: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004C664: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004C668: mflo        $t5
    ctx->r13 = lo;
    // 0x8004C66C: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8004C670: addu        $t4, $a2, $t6
    ctx->r12 = ADD32(ctx->r6, ctx->r14);
    // 0x8004C674: sh          $t4, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r12;
    // 0x8004C678: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8004C67C: lwc1        $f2, 0xB8($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0XB8);
    // 0x8004C680: lbu         $a0, 0x3B($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X3B);
    // 0x8004C684: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8004C688: beq         $a0, $at, L_8004C6A8
    if (ctx->r4 == ctx->r1) {
        // 0x8004C68C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004C6A8;
    }
    // 0x8004C68C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004C690: beq         $a0, $at, L_8004C6B8
    if (ctx->r4 == ctx->r1) {
        // 0x8004C694: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8004C6B8;
    }
    // 0x8004C694: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004C698: beq         $a0, $at, L_8004C6D0
    if (ctx->r4 == ctx->r1) {
        // 0x8004C69C: lui         $at, 0x4254
        ctx->r1 = S32(0X4254 << 16);
            goto L_8004C6D0;
    }
    // 0x8004C69C: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x8004C6A0: b           L_8004C704
    // 0x8004C6A4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
        goto L_8004C704;
    // 0x8004C6A4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_8004C6A8:
    // 0x8004C6A8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8004C6AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004C6B0: b           L_8004C700
    // 0x8004C6B4: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
        goto L_8004C700;
    // 0x8004C6B4: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
L_8004C6B8:
    // 0x8004C6B8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8004C6BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004C6C0: sub.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x8004C6C4: b           L_8004C700
    // 0x8004C6C8: sub.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f6.fl;
        goto L_8004C700;
    // 0x8004C6C8: sub.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x8004C6CC: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
L_8004C6D0:
    // 0x8004C6D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004C6D4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004C6D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004C6DC: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8004C6E0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004C6E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004C6E8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8004C6EC: sub.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x8004C6F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004C6F4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8004C6F8: sub.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8004C6FC: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_8004C700:
    // 0x8004C700: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_8004C704:
    // 0x8004C704: beq         $at, $zero, L_8004C720
    if (ctx->r1 == 0) {
        // 0x8004C708: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_8004C720;
    }
    // 0x8004C708: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8004C70C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004C710: nop

    // 0x8004C714: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8004C718: b           L_8004C734
    // 0x8004C71C: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
        goto L_8004C734;
    // 0x8004C71C: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
L_8004C720:
    // 0x8004C720: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8004C724: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004C728: nop

    // 0x8004C72C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004C730: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
L_8004C734:
    // 0x8004C734: lwc1        $f0, 0x2C($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x8004C738: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8004C73C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004C740: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8004C744: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8004C748: nop

    // 0x8004C74C: bc1f        L_8004C7A8
    if (!c1cs) {
        // 0x8004C750: nop
    
            goto L_8004C7A8;
    }
    // 0x8004C750: nop

    // 0x8004C754: lb          $t8, 0x1E2($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1E2);
    // 0x8004C758: nop

    // 0x8004C75C: bne         $t8, $zero, L_8004C7A8
    if (ctx->r24 != 0) {
        // 0x8004C760: nop
    
            goto L_8004C7A8;
    }
    // 0x8004C760: nop

    // 0x8004C764: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004C768: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8004C76C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004C770: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004C774: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8004C778: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004C77C: lwc1        $f5, 0x6B00($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6B00);
    // 0x8004C780: lwc1        $f4, 0x6B04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6B04);
    // 0x8004C784: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x8004C788: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8004C78C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8004C790: nop

    // 0x8004C794: bc1f        L_8004C7A4
    if (!c1cs) {
        // 0x8004C798: nop
    
            goto L_8004C7A4;
    }
    // 0x8004C798: nop

    // 0x8004C79C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004C7A0: nop

L_8004C7A4:
    // 0x8004C7A4: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
L_8004C7A8:
    // 0x8004C7A8: lw          $t9, -0x2540($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2540);
    // 0x8004C7AC: nop

    // 0x8004C7B0: bne         $t9, $zero, L_8004C808
    if (ctx->r25 != 0) {
        // 0x8004C7B4: addiu       $a0, $zero, 0x24
        ctx->r4 = ADD32(0, 0X24);
            goto L_8004C808;
    }
    // 0x8004C7B4: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x8004C7B8: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x8004C7BC: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x8004C7C0: jal         0x8000C8B4
    // 0x8004C7C4: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    normalise_time(rdram, ctx);
        goto after_1;
    // 0x8004C7C4: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8004C7C8: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004C7CC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004C7D0: lb          $v1, 0x1D3($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1D3);
    // 0x8004C7D4: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004C7D8: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004C7DC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004C7E0: beq         $at, $zero, L_8004C7F8
    if (ctx->r1 == 0) {
        // 0x8004C7E4: addiu       $t0, $t0, -0x2578
        ctx->r8 = ADD32(ctx->r8, -0X2578);
            goto L_8004C7F8;
    }
    // 0x8004C7E4: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x8004C7E8: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8004C7EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004C7F0: b           L_8004C808
    // 0x8004C7F4: nop

        goto L_8004C808;
    // 0x8004C7F4: nop

L_8004C7F8:
    // 0x8004C7F8: blez        $v1, L_8004C808
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004C7FC: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8004C808;
    }
    // 0x8004C7FC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004C800: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004C804: nop

L_8004C808:
    // 0x8004C808: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8004C80C: lw          $t2, -0x2540($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2540);
    // 0x8004C810: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004C814: slti        $at, $t2, 0x51
    ctx->r1 = SIGNED(ctx->r10) < 0X51 ? 1 : 0;
    // 0x8004C818: bne         $at, $zero, L_8004C838
    if (ctx->r1 != 0) {
        // 0x8004C81C: nop
    
            goto L_8004C838;
    }
    // 0x8004C81C: nop

    // 0x8004C820: swc1        $f14, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f14.u32l;
    // 0x8004C824: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8004C828: nop

    // 0x8004C82C: swc1        $f18, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f18.u32l;
    // 0x8004C830: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004C834: nop

L_8004C838:
    // 0x8004C838: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8004C83C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8004C840: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8004C844: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8004C848: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004C84C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004C850: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8004C854: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8004C858: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8004C85C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8004C860: swc1        $f4, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f4.u32l;
    // 0x8004C864: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004C868: nop

    // 0x8004C86C: lwc1        $f12, 0x20($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8004C870: nop

    // 0x8004C874: sub.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x8004C878: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8004C87C: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8004C880: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x8004C884: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x8004C888: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8004C88C: swc1        $f10, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f10.u32l;
    // 0x8004C890: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8004C894: nop

    // 0x8004C898: lh          $a0, 0x2($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X2);
    // 0x8004C89C: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x8004C8A0: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // 0x8004C8A4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8004C8A8: jal         0x80070A04
    // 0x8004C8AC: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    sins_f(rdram, ctx);
        goto after_2;
    // 0x8004C8AC: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_2:
    // 0x8004C8B0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004C8B4: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x8004C8B8: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8004C8BC: nop

    // 0x8004C8C0: lh          $a0, 0x2($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X2);
    // 0x8004C8C4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8004C8C8: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // 0x8004C8CC: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8004C8D0: jal         0x80070A38
    // 0x8004C8D4: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    coss_f(rdram, ctx);
        goto after_3;
    // 0x8004C8D4: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_3:
    // 0x8004C8D8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004C8DC: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x8004C8E0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004C8E4: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8004C8E8: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8004C8EC: lwc1        $f12, 0x20($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8004C8F0: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004C8F4: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004C8F8: ori         $t3, $zero, 0x8000
    ctx->r11 = 0 | 0X8000;
    // 0x8004C8FC: lh          $t2, 0x196($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X196);
    // 0x8004C900: mul.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8004C904: subu        $a0, $t3, $t2
    ctx->r4 = SUB32(ctx->r11, ctx->r10);
    // 0x8004C908: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x8004C90C: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8004C910: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8004C914: sub.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8004C918: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8004C91C: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8004C920: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004C924: jal         0x80070A04
    // 0x8004C928: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    sins_f(rdram, ctx);
        goto after_4;
    // 0x8004C928: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x8004C92C: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004C930: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004C934: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8004C938: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x8004C93C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8004C940: lh          $t4, 0x196($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X196);
    // 0x8004C944: nop

    // 0x8004C948: subu        $a0, $t7, $t4
    ctx->r4 = SUB32(ctx->r15, ctx->r12);
    // 0x8004C94C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8004C950: jal         0x80070A38
    // 0x8004C954: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    coss_f(rdram, ctx);
        goto after_5;
    // 0x8004C954: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_5:
    // 0x8004C958: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004C95C: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004C960: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8004C964: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8004C968: lh          $a0, 0x196($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X196);
    // 0x8004C96C: nop

    // 0x8004C970: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x8004C974: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x8004C978: jal         0x80070A04
    // 0x8004C97C: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    sins_f(rdram, ctx);
        goto after_6;
    // 0x8004C97C: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    after_6:
    // 0x8004C980: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8004C984: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004C988: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004C98C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004C990: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x8004C994: lwc1        $f8, 0x30($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X30);
    // 0x8004C998: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004C99C: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8004C9A0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8004C9A4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004C9A8: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x8004C9AC: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004C9B0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8004C9B4: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004C9B8: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004C9BC: swc1        $f8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f8.u32l;
    // 0x8004C9C0: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8004C9C4: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004C9C8: lwc1        $f4, 0x10($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8004C9CC: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8004C9D0: lb          $v1, 0x1E0($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1E0);
    // 0x8004C9D4: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8004C9D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004C9DC: beq         $v1, $at, L_8004C9EC
    if (ctx->r3 == ctx->r1) {
        // 0x8004C9E0: mov.s       $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
            goto L_8004C9EC;
    }
    // 0x8004C9E0: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    // 0x8004C9E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C9E8: bne         $v1, $at, L_8004C9FC
    if (ctx->r3 != ctx->r1) {
        // 0x8004C9EC: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_8004C9FC;
    }
L_8004C9EC:
    // 0x8004C9EC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8004C9F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004C9F4: lb          $v1, 0x1E0($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1E0);
    // 0x8004C9F8: swc1        $f8, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->f8.u32l;
L_8004C9FC:
    // 0x8004C9FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004CA00: beq         $v1, $at, L_8004CA0C
    if (ctx->r3 == ctx->r1) {
        // 0x8004CA04: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8004CA0C;
    }
    // 0x8004CA04: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004CA08: bne         $v1, $at, L_8004CA1C
    if (ctx->r3 != ctx->r1) {
        // 0x8004CA0C: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_8004CA1C;
    }
L_8004CA0C:
    // 0x8004CA0C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8004CA10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004CA14: nop

    // 0x8004CA18: swc1        $f6, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->f6.u32l;
L_8004CA1C:
    // 0x8004CA1C: lwc1        $f4, 0x74($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X74);
    // 0x8004CA20: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004CA24: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004CA28: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004CA2C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8004CA30: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x8004CA34: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004CA38: bc1f        L_8004CA60
    if (!c1cs) {
        // 0x8004CA3C: nop
    
            goto L_8004CA60;
    }
    // 0x8004CA3C: nop

    // 0x8004CA40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004CA44: lwc1        $f9, 0x6B08($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6B08);
    // 0x8004CA48: lwc1        $f8, 0x6B0C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6B0C);
    // 0x8004CA4C: nop

    // 0x8004CA50: sub.d       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f0.d - ctx->f8.d;
    // 0x8004CA54: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8004CA58: b           L_8004CA6C
    // 0x8004CA5C: swc1        $f4, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->f4.u32l;
        goto L_8004CA6C;
    // 0x8004CA5C: swc1        $f4, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->f4.u32l;
L_8004CA60:
    // 0x8004CA60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004CA64: nop

    // 0x8004CA68: swc1        $f10, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->f10.u32l;
L_8004CA6C:
    // 0x8004CA6C: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004CA70: lwc1        $f4, 0x74($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X74);
    // 0x8004CA74: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8004CA78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004CA7C: div.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8004CA80: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004CA84: nop

    // 0x8004CA88: bc1f        L_8004CAA4
    if (!c1cs) {
        // 0x8004CA8C: nop
    
            goto L_8004CAA4;
    }
    // 0x8004CA8C: nop

    // 0x8004CA90: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8004CA94: nop

    // 0x8004CA98: bc1f        L_8004CAA4
    if (!c1cs) {
        // 0x8004CA9C: nop
    
            goto L_8004CAA4;
    }
    // 0x8004CA9C: nop

    // 0x8004CAA0: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8004CAA4:
    // 0x8004CAA4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004CAA8: nop

    // 0x8004CAAC: bc1f        L_8004CAC8
    if (!c1cs) {
        // 0x8004CAB0: nop
    
            goto L_8004CAC8;
    }
    // 0x8004CAB0: nop

    // 0x8004CAB4: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8004CAB8: nop

    // 0x8004CABC: bc1f        L_8004CAC8
    if (!c1cs) {
        // 0x8004CAC0: nop
    
            goto L_8004CAC8;
    }
    // 0x8004CAC0: nop

    // 0x8004CAC4: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8004CAC8:
    // 0x8004CAC8: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004CACC: nop

    // 0x8004CAD0: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8004CAD4: nop

    // 0x8004CAD8: sub.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8004CADC: swc1        $f8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f8.u32l;
    // 0x8004CAE0: lh          $a0, 0x196($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X196);
    // 0x8004CAE4: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x8004CAE8: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x8004CAEC: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8004CAF0: jal         0x80070A38
    // 0x8004CAF4: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    coss_f(rdram, ctx);
        goto after_7;
    // 0x8004CAF4: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_7:
    // 0x8004CAF8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8004CAFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004CB00: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x8004CB04: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8004CB08: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004CB0C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8004CB10: lwc1        $f8, 0x30($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X30);
    // 0x8004CB14: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004CB18: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8004CB1C: lwc1        $f6, 0x14($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8004CB20: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004CB24: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x8004CB28: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8004CB2C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8004CB30: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004CB34: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004CB38: swc1        $f8, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f8.u32l;
    // 0x8004CB3C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8004CB40: lh          $t3, 0x196($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X196);
    // 0x8004CB44: nop

    // 0x8004CB48: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
    // 0x8004CB4C: lb          $t5, 0x1E0($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X1E0);
    // 0x8004CB50: nop

    // 0x8004CB54: bne         $t5, $zero, L_8004CB6C
    if (ctx->r13 != 0) {
        // 0x8004CB58: nop
    
            goto L_8004CB6C;
    }
    // 0x8004CB58: nop

    // 0x8004CB5C: lh          $t6, -0x24FA($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X24FA);
    // 0x8004CB60: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004CB64: beq         $t6, $zero, L_8004CBB8
    if (ctx->r14 == 0) {
        // 0x8004CB68: nop
    
            goto L_8004CBB8;
    }
    // 0x8004CB68: nop

L_8004CB6C:
    // 0x8004CB6C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004CB70: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004CB74: lh          $v0, 0x4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X4);
    // 0x8004CB78: nop

    // 0x8004CB7C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8004CB80: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x8004CB84: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004CB88: bne         $at, $zero, L_8004CB98
    if (ctx->r1 != 0) {
        // 0x8004CB8C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004CB98;
    }
    // 0x8004CB8C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004CB90: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004CB94: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004CB98:
    // 0x8004CB98: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8004CB9C: beq         $at, $zero, L_8004CBA8
    if (ctx->r1 == 0) {
        // 0x8004CBA0: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004CBA8;
    }
    // 0x8004CBA0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004CBA4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004CBA8:
    // 0x8004CBA8: sra         $t7, $v1, 2
    ctx->r15 = S32(SIGNED(ctx->r3) >> 2);
    // 0x8004CBAC: addu        $t4, $v0, $t7
    ctx->r12 = ADD32(ctx->r2, ctx->r15);
    // 0x8004CBB0: b           L_8004CC00
    // 0x8004CBB4: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
        goto L_8004CC00;
    // 0x8004CBB4: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
L_8004CBB8:
    // 0x8004CBB8: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004CBBC: lh          $a0, 0x1A4($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X1A4);
    // 0x8004CBC0: lh          $v0, 0x4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X4);
    // 0x8004CBC4: sra         $t8, $a0, 4
    ctx->r24 = S32(SIGNED(ctx->r4) >> 4);
    // 0x8004CBC8: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x8004CBCC: subu        $v1, $t8, $t9
    ctx->r3 = SUB32(ctx->r24, ctx->r25);
    // 0x8004CBD0: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004CBD4: bne         $at, $zero, L_8004CBE4
    if (ctx->r1 != 0) {
        // 0x8004CBD8: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004CBE4;
    }
    // 0x8004CBD8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004CBDC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004CBE0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004CBE4:
    // 0x8004CBE4: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8004CBE8: beq         $at, $zero, L_8004CBF4
    if (ctx->r1 == 0) {
        // 0x8004CBEC: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004CBF4;
    }
    // 0x8004CBEC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004CBF0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004CBF4:
    // 0x8004CBF4: sra         $t3, $v1, 3
    ctx->r11 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8004CBF8: addu        $t2, $v0, $t3
    ctx->r10 = ADD32(ctx->r2, ctx->r11);
    // 0x8004CBFC: sh          $t2, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r10;
L_8004CC00:
    // 0x8004CC00: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004CC04: nop

    // 0x8004CC08: lwc1        $f12, 0xC($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8004CC0C: lwc1        $f14, 0x10($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8004CC10: lw          $a2, 0x14($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X14);
    // 0x8004CC14: jal         0x80029F58
    // 0x8004CC18: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_8;
    // 0x8004CC18: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    after_8:
    // 0x8004CC1C: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004CC20: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004CC24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004CC28: beq         $v0, $at, L_8004CC3C
    if (ctx->r2 == ctx->r1) {
        // 0x8004CC2C: addiu       $t0, $t0, -0x2578
        ctx->r8 = ADD32(ctx->r8, -0X2578);
            goto L_8004CC3C;
    }
    // 0x8004CC2C: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x8004CC30: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8004CC34: nop

    // 0x8004CC38: sh          $v0, 0x34($t5)
    MEM_H(0X34, ctx->r13) = ctx->r2;
L_8004CC3C:
    // 0x8004CC3C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8004CC40: nop

    // 0x8004CC44: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8004CC48: nop

    // 0x8004CC4C: sh          $t7, 0x196($a3)
    MEM_H(0X196, ctx->r7) = ctx->r15;
    // 0x8004CC50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004CC54: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8004CC58: jr          $ra
    // 0x8004CC5C: nop

    return;
    // 0x8004CC5C: nop

;}
RECOMP_FUNC void alEvtqNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C98BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C98C0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C98C4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C98C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C98CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C98D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C98D4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C98D8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800C98DC: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800C98E0: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800C98E4: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800C98E8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800C98EC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800C98F0: blez        $a2, L_800C9914
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800C98F4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800C9914;
    }
    // 0x800C98F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800C98F8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_800C98FC:
    // 0x800C98FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C9900: jal         0x800C8CF0
    // 0x800C9904: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_0;
    // 0x800C9904: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800C9908: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C990C: bne         $s0, $s3, L_800C98FC
    if (ctx->r16 != ctx->r19) {
        // 0x800C9910: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_800C98FC;
    }
    // 0x800C9910: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
L_800C9914:
    // 0x800C9914: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9918: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C991C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C9920: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9924: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C9928: jr          $ra
    // 0x800C992C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C992C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alSeqpGetChlFXMix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7F20: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C7F24: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x800C7F28: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800C7F2C: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800C7F30: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C7F34: jr          $ra
    // 0x800C7F38: lbu         $v0, 0xA($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0XA);
    return;
    // 0x800C7F38: lbu         $v0, 0xA($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0XA);
;}
RECOMP_FUNC void func_800B97A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9CC8: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800B9CCC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800B9CD0: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800B9CD4: addiu       $s5, $s5, -0x5A78
    ctx->r21 = ADD32(ctx->r21, -0X5A78);
    // 0x800B9CD8: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x800B9CDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B9CE0: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800B9CE4: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9CE8: lwc1        $f0, -0x5A20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A20);
    // 0x800B9CEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B9CF0: lwc1        $f2, -0x5A24($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5A24);
    // 0x800B9CF4: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800B9CF8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800B9CFC: add.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800B9D00: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x800B9D04: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800B9D08: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800B9D0C: sub.s       $f26, $f4, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f26.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800B9D10: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x800B9D14: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B9D18: lw          $t9, 0x3668($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3668);
    // 0x800B9D1C: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x800B9D20: c.le.s      $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f26.fl <= ctx->f22.fl;
    // 0x800B9D24: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B9D28: mflo        $t6
    ctx->r14 = lo;
    // 0x800B9D2C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x800B9D30: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800B9D34: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800B9D38: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800B9D3C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800B9D40: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800B9D44: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800B9D48: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800B9D4C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800B9D50: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800B9D54: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800B9D58: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x800B9D5C: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800B9D60: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x800B9D64: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800B9D68: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B9D6C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800B9D70: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x800B9D74: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x800B9D78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800B9D7C: sw          $t6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r14;
    // 0x800B9D80: bc1f        L_800B9D98
    if (!c1cs) {
        // 0x800B9D84: sw          $t1, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r9;
            goto L_800B9D98;
    }
    // 0x800B9D84: sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
    // 0x800B9D88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B9D8C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800B9D90: b           L_800B9DA8
    // 0x800B9D94: mov.s       $f28, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    ctx->f28.fl = ctx->f22.fl;
        goto L_800B9DA8;
    // 0x800B9D94: mov.s       $f28, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    ctx->f28.fl = ctx->f22.fl;
L_800B9D98:
    // 0x800B9D98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B9D9C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800B9DA0: nop

    // 0x800B9DA4: div.s       $f28, $f24, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f28.fl = DIV_S(ctx->f24.fl, ctx->f26.fl);
L_800B9DA8:
    // 0x800B9DA8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B9DAC: lh          $t2, -0x5458($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X5458);
    // 0x800B9DB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9DB4: beq         $t2, $at, L_800BA0E0
    if (ctx->r10 == ctx->r1) {
        // 0x800B9DB8: mov.s       $f26, $f12
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
            goto L_800BA0E0;
    }
    // 0x800B9DB8: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
    // 0x800B9DBC: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x800B9DC0: subu        $t3, $t3, $a3
    ctx->r11 = SUB32(ctx->r11, ctx->r7);
    // 0x800B9DC4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800B9DC8: addiu       $t4, $t4, -0x5458
    ctx->r12 = ADD32(ctx->r12, -0X5458);
    // 0x800B9DCC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B9DD0: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x800B9DD4: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x800B9DD8: nop

L_800B9DDC:
    // 0x800B9DDC: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800B9DE0: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800B9DE4: bne         $t5, $v1, L_800BA0D0
    if (ctx->r13 != ctx->r3) {
        // 0x800B9DE8: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_800BA0D0;
    }
    // 0x800B9DE8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B9DEC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B9DF0: lw          $t2, -0x5A28($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5A28);
    // 0x800B9DF4: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    // 0x800B9DF8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800B9DFC: lw          $t6, 0x3664($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3664);
    // 0x800B9E00: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B9E04: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800B9E08: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x800B9E0C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B9E10: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B9E14: lw          $a1, 0x28($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X28);
    // 0x800B9E18: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800B9E1C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B9E20: addu        $t1, $t6, $t9
    ctx->r9 = ADD32(ctx->r14, ctx->r25);
    // 0x800B9E24: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800B9E28: lw          $t0, 0x3674($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3674);
    // 0x800B9E2C: lw          $a3, 0x3600($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3600);
    // 0x800B9E30: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800B9E34: beq         $a1, $zero, L_800B9E88
    if (ctx->r5 == 0) {
        // 0x800B9E38: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_800B9E88;
    }
    // 0x800B9E38: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B9E3C: lh          $v1, 0x2($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X2);
    // 0x800B9E40: nop

    // 0x800B9E44: andi        $t2, $v1, 0x1
    ctx->r10 = ctx->r3 & 0X1;
    // 0x800B9E48: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9E4C: andi        $t3, $v1, 0x2
    ctx->r11 = ctx->r3 & 0X2;
    // 0x800B9E50: sra         $t5, $t3, 1
    ctx->r13 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800B9E54: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800B9E58: srlv        $t6, $a0, $t8
    ctx->r14 = S32(U32(ctx->r4) >> (ctx->r24 & 31));
    // 0x800B9E5C: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x800B9E60: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x800B9E64: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800B9E68: mflo        $t4
    ctx->r12 = lo;
    // 0x800B9E6C: sw          $t4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r12;
    // 0x800B9E70: nop

    // 0x800B9E74: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9E78: mflo        $t7
    ctx->r15 = lo;
    // 0x800B9E7C: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x800B9E80: b           L_800B9EA0
    // 0x800B9E84: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
        goto L_800B9EA0;
    // 0x800B9E84: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
L_800B9E88:
    // 0x800B9E88: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800B9E8C: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x800B9E90: sw          $t6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r14;
    // 0x800B9E94: sw          $zero, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = 0;
    // 0x800B9E98: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x800B9E9C: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
L_800B9EA0:
    // 0x800B9EA0: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800B9EA4: lh          $a0, 0x6($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X6);
    // 0x800B9EA8: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9EAC: sll         $t5, $t1, 1
    ctx->r13 = S32(ctx->r9 << 1);
    // 0x800B9EB0: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x800B9EB4: mflo        $t2
    ctx->r10 = lo;
    // 0x800B9EB8: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800B9EBC: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800B9EC0: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800B9EC4: addu        $t3, $a3, $t4
    ctx->r11 = ADD32(ctx->r7, ctx->r12);
    // 0x800B9EC8: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x800B9ECC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800B9ED0: bltz        $v0, L_800BA0D0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B9ED4: sw          $t8, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r24;
            goto L_800BA0D0;
    }
    // 0x800B9ED4: sw          $t8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r24;
    // 0x800B9ED8: lw          $v1, 0x4($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X4);
    // 0x800B9EDC: nop

L_800B9EE0:
    // 0x800B9EE0: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9EE4: lh          $s1, 0x4($a2)
    ctx->r17 = MEM_H(ctx->r6, 0X4);
    // 0x800B9EE8: sll         $t1, $s6, 2
    ctx->r9 = S32(ctx->r22 << 2);
    // 0x800B9EEC: addu        $t1, $t1, $s6
    ctx->r9 = ADD32(ctx->r9, ctx->r22);
    // 0x800B9EF0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800B9EF4: addiu       $t4, $t4, 0x35DC
    ctx->r12 = ADD32(ctx->r12, 0X35DC);
    // 0x800B9EF8: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x800B9EFC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B9F00: sll         $s4, $s6, 2
    ctx->r20 = S32(ctx->r22 << 2);
    // 0x800B9F04: mflo        $t6
    ctx->r14 = lo;
    // 0x800B9F08: addu        $s2, $t6, $s1
    ctx->r18 = ADD32(ctx->r14, ctx->r17);
    // 0x800B9F0C: bltz        $v0, L_800BA09C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B9F10: nop
    
            goto L_800BA09C;
    }
    // 0x800B9F10: nop

    // 0x800B9F14: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x800B9F18: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800B9F1C: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800B9F20: addu        $s7, $t2, $t4
    ctx->r23 = ADD32(ctx->r10, ctx->r12);
    // 0x800B9F24: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    // 0x800B9F28: sw          $a0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r4;
    // 0x800B9F2C: addu        $s0, $t3, $t1
    ctx->r16 = ADD32(ctx->r11, ctx->r9);
L_800B9F30:
    // 0x800B9F30: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B9F34: lw          $t5, 0x35D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X35D4);
    // 0x800B9F38: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x800B9F3C: addu        $v1, $t5, $t7
    ctx->r3 = ADD32(ctx->r13, ctx->r15);
    // 0x800B9F40: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B9F44: lw          $v0, 0x35D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X35D0);
    // 0x800B9F48: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x800B9F4C: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800B9F50: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800B9F54: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800B9F58: addu        $t3, $v0, $t4
    ctx->r11 = ADD32(ctx->r2, ctx->r12);
    // 0x800B9F5C: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x800B9F60: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800B9F64: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800B9F68: lwc1        $f16, 0x40($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X40);
    // 0x800B9F6C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B9F70: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B9F74: lw          $t1, 0x3718($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3718);
    // 0x800B9F78: mul.s       $f20, $f10, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B9F7C: blez        $t1, L_800B9FA0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800B9F80: nop
    
            goto L_800B9FA0;
    }
    // 0x800B9F80: nop

    // 0x800B9F84: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x800B9F88: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x800B9F8C: lw          $a0, 0xB8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB8);
    // 0x800B9F90: addu        $a1, $s3, $t5
    ctx->r5 = ADD32(ctx->r19, ctx->r13);
    // 0x800B9F94: jal         0x800BF4E4
    // 0x800B9F98: addu        $a2, $fp, $t7
    ctx->r6 = ADD32(ctx->r30, ctx->r15);
    waves_get_y(rdram, ctx);
        goto after_0;
    // 0x800B9F98: addu        $a2, $fp, $t7
    ctx->r6 = ADD32(ctx->r30, ctx->r15);
    after_0:
    // 0x800B9F9C: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
L_800B9FA0:
    // 0x800B9FA0: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800B9FA4: nop

    // 0x800B9FA8: addu        $t6, $t8, $s4
    ctx->r14 = ADD32(ctx->r24, ctx->r20);
    // 0x800B9FAC: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800B9FB0: nop

    // 0x800B9FB4: mul.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x800B9FB8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B9FBC: nop

    // 0x800B9FC0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B9FC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B9FC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B9FCC: nop

    // 0x800B9FD0: cvt.w.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = CVT_W_S(ctx->f20.fl);
    // 0x800B9FD4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B9FD8: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800B9FDC: sub.s       $f6, $f20, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f26.fl;
    // 0x800B9FE0: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x800B9FE4: mul.s       $f20, $f6, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x800B9FE8: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x800B9FEC: nop

    // 0x800B9FF0: bc1f        L_800BA000
    if (!c1cs) {
        // 0x800B9FF4: nop
    
            goto L_800BA000;
    }
    // 0x800B9FF4: nop

    // 0x800B9FF8: b           L_800BA014
    // 0x800B9FFC: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
        goto L_800BA014;
    // 0x800B9FFC: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
L_800BA000:
    // 0x800BA000: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x800BA004: nop

    // 0x800BA008: bc1f        L_800BA014
    if (!c1cs) {
        // 0x800BA00C: nop
    
            goto L_800BA014;
    }
    // 0x800BA00C: nop

    // 0x800BA010: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
L_800BA014:
    // 0x800BA014: mul.s       $f8, $f22, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x800BA018: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800BA01C: sb          $t3, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r11;
    // 0x800BA020: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800BA024: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BA028: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800BA02C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800BA030: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BA034: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BA038: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800BA03C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BA040: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x800BA044: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800BA048: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BA04C: addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
    // 0x800BA050: sb          $v0, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r2;
    // 0x800BA054: sb          $v0, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r2;
    // 0x800BA058: sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // 0x800BA05C: lw          $v1, 0x4($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X4);
    // 0x800BA060: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800BA064: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BA068: bne         $at, $zero, L_800BA078
    if (ctx->r1 != 0) {
        // 0x800BA06C: nop
    
            goto L_800BA078;
    }
    // 0x800BA06C: nop

    // 0x800BA070: subu        $s1, $s1, $v1
    ctx->r17 = SUB32(ctx->r17, ctx->r3);
    // 0x800BA074: subu        $s2, $s2, $v1
    ctx->r18 = SUB32(ctx->r18, ctx->r3);
L_800BA078:
    // 0x800BA078: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x800BA07C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800BA080: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800BA084: beq         $at, $zero, L_800B9F30
    if (ctx->r1 == 0) {
        // 0x800BA088: nop
    
            goto L_800B9F30;
    }
    // 0x800BA088: nop

    // 0x800BA08C: lw          $a1, 0x28($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X28);
    // 0x800BA090: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BA094: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x800BA098: nop

L_800BA09C:
    // 0x800BA09C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BA0A0: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BA0A4: bne         $at, $zero, L_800BA0B0
    if (ctx->r1 != 0) {
        // 0x800BA0A8: addiu       $fp, $fp, 0x1
        ctx->r30 = ADD32(ctx->r30, 0X1);
            goto L_800BA0B0;
    }
    // 0x800BA0A8: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800BA0AC: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
L_800BA0B0:
    // 0x800BA0B0: beq         $a1, $zero, L_800BA0C8
    if (ctx->r5 == 0) {
        // 0x800BA0B4: slt         $at, $v0, $fp
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r30) ? 1 : 0;
            goto L_800BA0C8;
    }
    // 0x800BA0B4: slt         $at, $v0, $fp
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x800BA0B8: lw          $t1, 0x8($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X8);
    // 0x800BA0BC: nop

    // 0x800BA0C0: addu        $t5, $t1, $v0
    ctx->r13 = ADD32(ctx->r9, ctx->r2);
    // 0x800BA0C4: sw          $t5, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r13;
L_800BA0C8:
    // 0x800BA0C8: beq         $at, $zero, L_800B9EE0
    if (ctx->r1 == 0) {
        // 0x800BA0CC: nop
    
            goto L_800B9EE0;
    }
    // 0x800BA0CC: nop

L_800BA0D0:
    // 0x800BA0D0: lh          $v1, 0xC($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XC);
    // 0x800BA0D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BA0D8: bne         $v1, $at, L_800B9DDC
    if (ctx->r3 != ctx->r1) {
        // 0x800BA0DC: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_800B9DDC;
    }
    // 0x800BA0DC: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
L_800BA0E0:
    // 0x800BA0E0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800BA0E4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800BA0E8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BA0EC: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BA0F0: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BA0F4: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800BA0F8: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BA0FC: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800BA100: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800BA104: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800BA108: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800BA10C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800BA110: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800BA114: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800BA118: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800BA11C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800BA120: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800BA124: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800BA128: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800BA12C: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800BA130: jr          $ra
    // 0x800BA134: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800BA134: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void set_ghost_none(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B7C4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8001B7C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001B7CC: sh          $t6, -0x24D4($at)
    MEM_H(-0X24D4, ctx->r1) = ctx->r14;
    // 0x8001B7D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B7D4: jr          $ra
    // 0x8001B7D8: sb          $zero, -0x3360($at)
    MEM_B(-0X3360, ctx->r1) = 0;
    return;
    // 0x8001B7D8: sb          $zero, -0x3360($at)
    MEM_B(-0X3360, ctx->r1) = 0;
;}
RECOMP_FUNC void sndp_apply_pitch_slide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000418C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80004190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004194: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80004198: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000419C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800041A0: nop

    // 0x800041A4: lb          $a0, 0x5($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X5);
    // 0x800041A8: jal         0x800C9F40
    // 0x800041AC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    alCents2Ratio(rdram, ctx);
        goto after_0;
    // 0x800041AC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x800041B0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800041B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800041B8: lwc1        $f4, 0x2C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x800041BC: lw          $a0, -0x33D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33D4);
    // 0x800041C0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800041C4: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x800041C8: sh          $t8, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r24;
    // 0x800041CC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800041D0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800041D4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800041D8: ori         $a2, $zero, 0x8235
    ctx->r6 = 0 | 0X8235;
    // 0x800041DC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800041E0: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800041E4: jal         0x800C970C
    // 0x800041E8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x800041E8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    after_1:
    // 0x800041EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800041F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800041F4: jr          $ra
    // 0x800041F8: nop

    return;
    // 0x800041F8: nop

;}
RECOMP_FUNC void func_80092188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800926A4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800926A8: lw          $t6, -0x604($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X604);
    // 0x800926AC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800926B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800926B4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800926B8: jal         0x8006ECD0
    // 0x800926BC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x800926BC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x800926C0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800926C4: addiu       $a2, $a2, 0xF00
    ctx->r6 = ADD32(ctx->r6, 0XF00);
    // 0x800926C8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800926CC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800926D0: beq         $v1, $zero, L_800926E8
    if (ctx->r3 == 0) {
        // 0x800926D4: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800926E8;
    }
    // 0x800926D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800926D8: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800926DC: nop

    // 0x800926E0: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800926E4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_800926E8:
    // 0x800926E8: lw          $v0, 0x6F88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6F88);
    // 0x800926EC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800926F0: bne         $v0, $at, L_80092738
    if (ctx->r2 != ctx->r1) {
        // 0x800926F4: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_80092738;
    }
    // 0x800926F4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800926F8: addiu       $t4, $t4, 0x6980
    ctx->r12 = ADD32(ctx->r12, 0X6980);
    // 0x800926FC: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x80092700: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80092704: beq         $t9, $at, L_80092738
    if (ctx->r25 == ctx->r1) {
        // 0x80092708: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_80092738;
    }
    // 0x80092708: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8009270C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80092710: bne         $v0, $at, L_80092738
    if (ctx->r2 != ctx->r1) {
        // 0x80092714: sw          $t6, 0x0($t4)
        MEM_W(0X0, ctx->r12) = ctx->r14;
            goto L_80092738;
    }
    // 0x80092714: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80092718: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009271C: lw          $a0, 0x6F8C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6F8C);
    // 0x80092720: jal         0x800C3744
    // 0x80092724: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    set_current_text(rdram, ctx);
        goto after_1;
    // 0x80092724: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_1:
    // 0x80092728: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009272C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80092730: lw          $v0, 0x6F88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6F88);
    // 0x80092734: addiu       $a2, $a2, 0xF00
    ctx->r6 = ADD32(ctx->r6, 0XF00);
L_80092738:
    // 0x80092738: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8009273C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80092740: bne         $v0, $at, L_80092764
    if (ctx->r2 != ctx->r1) {
        // 0x80092744: addiu       $t4, $t4, 0x6980
        ctx->r12 = ADD32(ctx->r12, 0X6980);
            goto L_80092764;
    }
    // 0x80092744: addiu       $t4, $t4, 0x6980
    ctx->r12 = ADD32(ctx->r12, 0X6980);
    // 0x80092748: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x8009274C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80092750: beq         $t5, $v0, L_80092764
    if (ctx->r13 == ctx->r2) {
        // 0x80092754: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80092764;
    }
    // 0x80092754: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80092758: beq         $v0, $at, L_80092764
    if (ctx->r2 == ctx->r1) {
        // 0x8009275C: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80092764;
    }
    // 0x8009275C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80092760: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
L_80092764:
    // 0x80092764: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80092768: lw          $t8, -0x5BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5BC);
    // 0x8009276C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80092770: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80092774: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80092778: lh          $v0, 0xCD8($v0)
    ctx->r2 = MEM_H(ctx->r2, 0XCD8);
    // 0x8009277C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80092780: beq         $t5, $v0, L_800927B0
    if (ctx->r13 == ctx->r2) {
        // 0x80092784: nop
    
            goto L_800927B0;
    }
    // 0x80092784: nop

    // 0x80092788: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8009278C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80092790: slti        $at, $t6, 0x7
    ctx->r1 = SIGNED(ctx->r14) < 0X7 ? 1 : 0;
    // 0x80092794: bne         $at, $zero, L_800927B0
    if (ctx->r1 != 0) {
        // 0x80092798: nop
    
            goto L_800927B0;
    }
    // 0x80092798: nop

    // 0x8009279C: jal         0x80001D04
    // 0x800927A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x800927A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800927A4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800927A8: addiu       $a2, $a2, 0xF00
    ctx->r6 = ADD32(ctx->r6, 0XF00);
    // 0x800927AC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_800927B0:
    // 0x800927B0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800927B4: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x800927B8: nop

    // 0x800927BC: bgez        $v0, L_8009289C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800927C0: addiu       $t1, $v0, 0x19
        ctx->r9 = ADD32(ctx->r2, 0X19);
            goto L_8009289C;
    }
    // 0x800927C0: addiu       $t1, $v0, 0x19
    ctx->r9 = ADD32(ctx->r2, 0X19);
    // 0x800927C4: slti        $at, $t1, 0x15
    ctx->r1 = SIGNED(ctx->r9) < 0X15 ? 1 : 0;
    // 0x800927C8: bne         $at, $zero, L_800927D4
    if (ctx->r1 != 0) {
        // 0x800927CC: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800927D4;
    }
    // 0x800927CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800927D0: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
L_800927D4:
    // 0x800927D4: bgez        $t1, L_800927E0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800927D8: nop
    
            goto L_800927E0;
    }
    // 0x800927D8: nop

    // 0x800927DC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800927E0:
    // 0x800927E0: lw          $v0, 0x6A18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A18);
    // 0x800927E4: addiu       $t7, $t1, 0x14
    ctx->r15 = ADD32(ctx->r9, 0X14);
    // 0x800927E8: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800927EC: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x800927F0: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x800927F4: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x800927F8: subu        $a1, $t9, $t0
    ctx->r5 = SUB32(ctx->r25, ctx->r8);
    // 0x800927FC: addiu       $a3, $t0, 0xF0
    ctx->r7 = ADD32(ctx->r8, 0XF0);
    // 0x80092800: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80092804: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x80092808: mflo        $v1
    ctx->r3 = lo;
    // 0x8009280C: nop

    // 0x80092810: nop

    // 0x80092814: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80092818: mflo        $t8
    ctx->r24 = lo;
    // 0x8009281C: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x80092820: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80092824: jal         0x80066B80
    // 0x80092828: subu        $a2, $v0, $t8
    ctx->r6 = SUB32(ctx->r2, ctx->r24);
    viewport_menu_set(rdram, ctx);
        goto after_3;
    // 0x80092828: subu        $a2, $v0, $t8
    ctx->r6 = SUB32(ctx->r2, ctx->r24);
    after_3:
    // 0x8009282C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80092830: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80092834: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80092838: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009283C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80092840: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80092844: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80092848: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009284C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80092850: addiu       $a0, $a0, -0x570
    ctx->r4 = ADD32(ctx->r4, -0X570);
    // 0x80092854: lwc1        $f18, 0x88($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80092858: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009285C: addiu       $v1, $v1, -0x324
    ctx->r3 = ADD32(ctx->r3, -0X324);
    // 0x80092860: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80092864: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80092868: add.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8009286C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80092870: swc1        $f4, 0x88($t6)
    MEM_W(0X88, ctx->r14) = ctx->f4.u32l;
    // 0x80092874: lwc1        $f6, 0xA8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XA8);
    // 0x80092878: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8009287C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80092880: swc1        $f8, 0xA8($t7)
    MEM_W(0XA8, ctx->r15) = ctx->f8.u32l;
    // 0x80092884: lwc1        $f16, 0xC8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80092888: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8009288C: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80092890: swc1        $f10, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->f10.u32l;
    // 0x80092894: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80092898: nop

L_8009289C:
    // 0x8009289C: blez        $v0, L_800928C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800928A0: slti        $at, $v0, 0x29
        ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
            goto L_800928C0;
    }
    // 0x800928A0: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x800928A4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800928A8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800928AC: addiu       $v1, $v1, -0x320
    ctx->r3 = ADD32(ctx->r3, -0X320);
    // 0x800928B0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800928B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800928B8: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800928BC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_800928C0:
    // 0x800928C0: bne         $at, $zero, L_800928DC
    if (ctx->r1 != 0) {
        // 0x800928C4: slti        $at, $v0, -0x1E
        ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
            goto L_800928DC;
    }
    // 0x800928C4: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x800928C8: jal         0x8008F4C4
    // 0x800928CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    trackmenu_assets(rdram, ctx);
        goto after_4;
    // 0x800928CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x800928D0: b           L_8009291C
    // 0x800928D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8009291C;
    // 0x800928D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800928D8: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
L_800928DC:
    // 0x800928DC: beq         $at, $zero, L_80092918
    if (ctx->r1 == 0) {
        // 0x800928E0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80092918;
    }
    // 0x800928E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800928E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800928E8: jal         0x8008F4C4
    // 0x800928EC: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    trackmenu_assets(rdram, ctx);
        goto after_5;
    // 0x800928EC: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    after_5:
    // 0x800928F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800928F4: lw          $v0, 0x6A18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A18);
    // 0x800928F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800928FC: sra         $v1, $v0, 1
    ctx->r3 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80092900: addu        $t6, $v1, $v0
    ctx->r14 = ADD32(ctx->r3, ctx->r2);
    // 0x80092904: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80092908: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x8009290C: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x80092910: jal         0x80066B80
    // 0x80092914: subu        $a2, $v0, $v1
    ctx->r6 = SUB32(ctx->r2, ctx->r3);
    viewport_menu_set(rdram, ctx);
        goto after_6;
    // 0x80092914: subu        $a2, $v0, $v1
    ctx->r6 = SUB32(ctx->r2, ctx->r3);
    after_6:
L_80092918:
    // 0x80092918: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8009291C:
    // 0x8009291C: jal         0x80066A58
    // 0x80092920: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camEnableUserView(rdram, ctx);
        goto after_7;
    // 0x80092920: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80092924: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80092928: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009292C: bne         $t9, $zero, L_8009311C
    if (ctx->r25 != 0) {
        // 0x80092930: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009311C;
    }
    // 0x80092930: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80092934: lw          $a0, -0x5BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5BC);
    // 0x80092938: jal         0x8006B338
    // 0x8009293C: nop

    leveltable_vehicle_usable(rdram, ctx);
        goto after_8;
    // 0x8009293C: nop

    after_8:
    // 0x80092940: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80092944: lw          $t2, -0x5C4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5C4);
    // 0x80092948: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8009294C: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x80092950: addiu       $t4, $t4, 0x6980
    ctx->r12 = ADD32(ctx->r12, 0X6980);
    // 0x80092954: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80092958: bne         $at, $zero, L_8009298C
    if (ctx->r1 != 0) {
        // 0x8009295C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8009298C;
    }
    // 0x8009295C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80092960: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80092964: lw          $v1, -0x5BC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5BC);
    // 0x80092968: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8009296C: bne         $v1, $at, L_80092978
    if (ctx->r3 != ctx->r1) {
        // 0x80092970: addiu       $at, $zero, -0x3
        ctx->r1 = ADD32(0, -0X3);
            goto L_80092978;
    }
    // 0x80092970: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80092974: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
L_80092978:
    // 0x80092978: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x8009297C: bne         $v1, $at, L_8009298C
    if (ctx->r3 != ctx->r1) {
        // 0x80092980: addiu       $at, $zero, -0x5
        ctx->r1 = ADD32(0, -0X5);
            goto L_8009298C;
    }
    // 0x80092980: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80092984: and         $t7, $a0, $at
    ctx->r15 = ctx->r4 & ctx->r1;
    // 0x80092988: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_8009298C:
    // 0x8009298C: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x80092990: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80092994: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80092998: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x8009299C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800929A0: beq         $at, $zero, L_80093060
    if (ctx->r1 == 0) {
        // 0x800929A4: sw          $zero, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = 0;
            goto L_80093060;
    }
    // 0x800929A4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800929A8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800929AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800929B0: addu        $at, $at, $t8
    gpr jr_addend_800929BC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800929B4: lw          $t8, -0x757C($at)
    ctx->r24 = ADD32(ctx->r1, -0X757C);
    // 0x800929B8: nop

    // 0x800929BC: jr          $t8
    // 0x800929C0: nop

    switch (jr_addend_800929BC >> 2) {
        case 0: goto L_800929C4; break;
        case 1: goto L_80092A74; break;
        case 2: goto L_80092C90; break;
        case 3: goto L_80092DCC; break;
        case 4: goto L_80092DCC; break;
        default: switch_error(__func__, 0x800929BC, 0x800E8A84);
    }
    // 0x800929C0: nop

L_800929C4:
    // 0x800929C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800929C8: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x800929CC: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x800929D0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800929D4: andi        $t6, $v1, 0x9000
    ctx->r14 = ctx->r3 & 0X9000;
    // 0x800929D8: beq         $t6, $zero, L_80092A04
    if (ctx->r14 == 0) {
        // 0x800929DC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80092A04;
    }
    // 0x800929DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800929E0: lw          $t9, 0x6F88($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6F88);
    // 0x800929E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800929E8: bne         $t9, $at, L_800929F8
    if (ctx->r25 != ctx->r1) {
        // 0x800929EC: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_800929F8;
    }
    // 0x800929EC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800929F0: b           L_800929FC
    // 0x800929F4: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
        goto L_800929FC;
    // 0x800929F4: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
L_800929F8:
    // 0x800929F8: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_800929FC:
    // 0x800929FC: b           L_80093060
    // 0x80092A00: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_80093060;
    // 0x80092A00: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_80092A04:
    // 0x80092A04: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
    // 0x80092A08: beq         $t6, $zero, L_80092A24
    if (ctx->r14 == 0) {
        // 0x80092A0C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80092A24;
    }
    // 0x80092A0C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80092A10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092A14: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80092A18: sw          $t5, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r13;
    // 0x80092A1C: b           L_80093060
    // 0x80092A20: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
        goto L_80093060;
    // 0x80092A20: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80092A24:
    // 0x80092A24: lh          $v0, 0x6DD8($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6DD8);
    // 0x80092A28: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80092A2C: blez        $v0, L_80092A50
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80092A30: nop
    
            goto L_80092A50;
    }
    // 0x80092A30: nop

    // 0x80092A34: lw          $t7, 0x998($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X998);
    // 0x80092A38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092A3C: beq         $t7, $zero, L_80092A50
    if (ctx->r15 == 0) {
        // 0x80092A40: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80092A50;
    }
    // 0x80092A40: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092A44: sw          $zero, 0x998($at)
    MEM_W(0X998, ctx->r1) = 0;
    // 0x80092A48: b           L_80093060
    // 0x80092A4C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
        goto L_80093060;
    // 0x80092A4C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_80092A50:
    // 0x80092A50: bgez        $v0, L_80093060
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80092A54: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_80093060;
    }
    // 0x80092A54: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80092A58: lw          $t6, 0x998($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X998);
    // 0x80092A5C: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80092A60: bne         $t6, $zero, L_80093060
    if (ctx->r14 != 0) {
        // 0x80092A64: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80093060;
    }
    // 0x80092A64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092A68: sw          $ra, 0x998($at)
    MEM_W(0X998, ctx->r1) = ctx->r31;
    // 0x80092A6C: b           L_80093060
    // 0x80092A70: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
        goto L_80093060;
    // 0x80092A70: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
L_80092A74:
    // 0x80092A74: blez        $t2, L_80092C44
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80092A78: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80092C44;
    }
    // 0x80092A78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80092A7C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80092A80: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80092A84: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80092A88: addiu       $t1, $t1, -0x600
    ctx->r9 = ADD32(ctx->r9, -0X600);
    // 0x80092A8C: addiu       $t3, $t3, 0x6F84
    ctx->r11 = ADD32(ctx->r11, 0X6F84);
    // 0x80092A90: addiu       $t0, $t0, 0x6D78
    ctx->r8 = ADD32(ctx->r8, 0X6D78);
    // 0x80092A94: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
L_80092A98:
    // 0x80092A98: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80092A9C: nop

    // 0x80092AA0: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x80092AA4: beq         $t9, $zero, L_80092B38
    if (ctx->r25 == 0) {
        // 0x80092AA8: andi        $t6, $v1, 0x9000
        ctx->r14 = ctx->r3 & 0X9000;
            goto L_80092B38;
    }
    // 0x80092AA8: andi        $t6, $v1, 0x9000
    ctx->r14 = ctx->r3 & 0X9000;
    // 0x80092AAC: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80092AB0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80092AB4: bne         $v1, $zero, L_80092B1C
    if (ctx->r3 != 0) {
        // 0x80092AB8: addu        $v0, $t3, $a1
        ctx->r2 = ADD32(ctx->r11, ctx->r5);
            goto L_80092B1C;
    }
    // 0x80092AB8: addu        $v0, $t3, $a1
    ctx->r2 = ADD32(ctx->r11, ctx->r5);
    // 0x80092ABC: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    // 0x80092AC0: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x80092AC4: jal         0x8009F1A4
    // 0x80092AC8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    is_adventure_two_unlocked(rdram, ctx);
        goto after_9;
    // 0x80092AC8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_9:
    // 0x80092ACC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80092AD0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80092AD4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80092AD8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80092ADC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80092AE0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80092AE4: addiu       $t4, $t4, 0x6980
    ctx->r12 = ADD32(ctx->r12, 0X6980);
    // 0x80092AE8: addiu       $t3, $t3, 0x6F84
    ctx->r11 = ADD32(ctx->r11, 0X6F84);
    // 0x80092AEC: addiu       $t1, $t1, -0x600
    ctx->r9 = ADD32(ctx->r9, -0X600);
    // 0x80092AF0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80092AF4: beq         $v0, $zero, L_80092B04
    if (ctx->r2 == 0) {
        // 0x80092AF8: addiu       $ra, $zero, 0x1
        ctx->r31 = ADD32(0, 0X1);
            goto L_80092B04;
    }
    // 0x80092AF8: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80092AFC: b           L_80092B0C
    // 0x80092B00: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
        goto L_80092B0C;
    // 0x80092B00: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
L_80092B04:
    // 0x80092B04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092B08: sw          $t5, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r13;
L_80092B0C:
    // 0x80092B0C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80092B10: lw          $t2, -0x5C4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5C4);
    // 0x80092B14: b           L_80092C38
    // 0x80092B18: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80092C38;
    // 0x80092B18: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80092B1C:
    // 0x80092B1C: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x80092B20: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80092B24: beq         $t7, $zero, L_80092C34
    if (ctx->r15 == 0) {
        // 0x80092B28: nop
    
            goto L_80092C34;
    }
    // 0x80092B28: nop

    // 0x80092B2C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80092B30: b           L_80092C34
    // 0x80092B34: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
        goto L_80092C34;
    // 0x80092B34: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_80092B38:
    // 0x80092B38: beq         $t6, $zero, L_80092B68
    if (ctx->r14 == 0) {
        // 0x80092B3C: addu        $v0, $t3, $a1
        ctx->r2 = ADD32(ctx->r11, ctx->r5);
            goto L_80092B68;
    }
    // 0x80092B3C: addu        $v0, $t3, $a1
    ctx->r2 = ADD32(ctx->r11, ctx->r5);
    // 0x80092B40: lb          $t9, 0x0($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X0);
    // 0x80092B44: nop

    // 0x80092B48: bne         $t9, $zero, L_80092C34
    if (ctx->r25 != 0) {
        // 0x80092B4C: nop
    
            goto L_80092C34;
    }
    // 0x80092B4C: nop

    // 0x80092B50: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80092B54: sb          $ra, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r31;
    // 0x80092B58: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80092B5C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80092B60: b           L_80092C34
    // 0x80092B64: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
        goto L_80092C34;
    // 0x80092B64: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
L_80092B68:
    // 0x80092B68: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x80092B6C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80092B70: bne         $t6, $zero, L_80092C34
    if (ctx->r14 != 0) {
        // 0x80092B74: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80092C34;
    }
    // 0x80092B74: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80092B78: lw          $t8, -0x5BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5BC);
    // 0x80092B7C: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x80092B80: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80092B84: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80092B88: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80092B8C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80092B90: andi        $t7, $t8, 0x2
    ctx->r15 = ctx->r24 & 0X2;
    // 0x80092B94: beq         $t7, $zero, L_80092C34
    if (ctx->r15 == 0) {
        // 0x80092B98: addiu       $t6, $t6, 0x6F80
        ctx->r14 = ADD32(ctx->r14, 0X6F80);
            goto L_80092C34;
    }
    // 0x80092B98: addiu       $t6, $t6, 0x6F80
    ctx->r14 = ADD32(ctx->r14, 0X6F80);
    // 0x80092B9C: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x80092BA0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80092BA4: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x80092BA8: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x80092BAC: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80092BB0: lh          $a2, 0x6DD0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X6DD0);
    // 0x80092BB4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80092BB8: blez        $a2, L_80092BE4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80092BBC: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80092BE4;
    }
    // 0x80092BBC: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
L_80092BC0:
    // 0x80092BC0: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x80092BC4: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80092BC8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80092BCC: sllv        $t6, $t7, $v0
    ctx->r14 = S32(ctx->r15 << (ctx->r2 & 31));
    // 0x80092BD0: and         $t9, $t6, $a0
    ctx->r25 = ctx->r14 & ctx->r4;
    // 0x80092BD4: bne         $t9, $zero, L_80092BE4
    if (ctx->r25 != 0) {
        // 0x80092BD8: nop
    
            goto L_80092BE4;
    }
    // 0x80092BD8: nop

    // 0x80092BDC: bgez        $v0, L_80092BC0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80092BE0: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80092BC0;
    }
    // 0x80092BE0: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
L_80092BE4:
    // 0x80092BE4: bgez        $a2, L_80092C10
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80092BE8: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_80092C10;
    }
    // 0x80092BE8: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
L_80092BEC:
    // 0x80092BEC: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x80092BF0: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80092BF4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80092BF8: sllv        $t6, $t7, $v0
    ctx->r14 = S32(ctx->r15 << (ctx->r2 & 31));
    // 0x80092BFC: and         $t9, $t6, $a0
    ctx->r25 = ctx->r14 & ctx->r4;
    // 0x80092C00: bne         $t9, $zero, L_80092C10
    if (ctx->r25 != 0) {
        // 0x80092C04: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_80092C10;
    }
    // 0x80092C04: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80092C08: bne         $at, $zero, L_80092BEC
    if (ctx->r1 != 0) {
        // 0x80092C0C: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_80092BEC;
    }
    // 0x80092C0C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
L_80092C10:
    // 0x80092C10: beq         $a3, $v0, L_80092C34
    if (ctx->r7 == ctx->r2) {
        // 0x80092C14: nop
    
            goto L_80092C34;
    }
    // 0x80092C14: nop

    // 0x80092C18: bltz        $v0, L_80092C28
    if (SIGNED(ctx->r2) < 0) {
        // 0x80092C1C: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_80092C28;
    }
    // 0x80092C1C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80092C20: bne         $at, $zero, L_80092C30
    if (ctx->r1 != 0) {
        // 0x80092C24: nop
    
            goto L_80092C30;
    }
    // 0x80092C24: nop

L_80092C28:
    // 0x80092C28: b           L_80092C34
    // 0x80092C2C: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
        goto L_80092C34;
    // 0x80092C2C: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
L_80092C30:
    // 0x80092C30: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
L_80092C34:
    // 0x80092C34: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80092C38:
    // 0x80092C38: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80092C3C: bne         $at, $zero, L_80092A98
    if (ctx->r1 != 0) {
        // 0x80092C40: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_80092A98;
    }
    // 0x80092C40: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_80092C44:
    // 0x80092C44: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80092C48: addiu       $t1, $t1, -0x600
    ctx->r9 = ADD32(ctx->r9, -0X600);
    // 0x80092C4C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80092C50: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80092C54: bne         $t2, $t8, L_80093060
    if (ctx->r10 != ctx->r24) {
        // 0x80092C58: slti        $at, $t2, 0x2
        ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
            goto L_80093060;
    }
    // 0x80092C58: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x80092C5C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80092C60: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80092C64: bne         $at, $zero, L_80092C78
    if (ctx->r1 != 0) {
        // 0x80092C68: sw          $zero, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = 0;
            goto L_80092C78;
    }
    // 0x80092C68: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80092C6C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80092C70: b           L_80092C7C
    // 0x80092C74: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
        goto L_80092C7C;
    // 0x80092C74: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
L_80092C78:
    // 0x80092C78: sw          $ra, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r31;
L_80092C7C:
    // 0x80092C7C: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    // 0x80092C80: jal         0x80001D04
    // 0x80092C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x80092C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80092C88: b           L_80093064
    // 0x80092C8C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_80093064;
    // 0x80092C8C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80092C90:
    // 0x80092C90: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092C94: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x80092C98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80092C9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80092CA0: andi        $t6, $v0, 0x9000
    ctx->r14 = ctx->r2 & 0X9000;
    // 0x80092CA4: beq         $t6, $zero, L_80092CC0
    if (ctx->r14 == 0) {
        // 0x80092CA8: andi        $t7, $v0, 0x4000
        ctx->r15 = ctx->r2 & 0X4000;
            goto L_80092CC0;
    }
    // 0x80092CA8: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
    // 0x80092CAC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80092CB0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092CB4: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80092CB8: b           L_80092CE8
    // 0x80092CBC: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_80092CE8;
    // 0x80092CBC: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_80092CC0:
    // 0x80092CC0: beq         $t7, $zero, L_80092CE8
    if (ctx->r15 == 0) {
        // 0x80092CC4: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_80092CE8;
    }
    // 0x80092CC4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80092CC8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80092CCC: addiu       $t3, $t3, 0x6F84
    ctx->r11 = ADD32(ctx->r11, 0X6F84);
    // 0x80092CD0: addiu       $t1, $t1, -0x600
    ctx->r9 = ADD32(ctx->r9, -0X600);
    // 0x80092CD4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80092CD8: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
    // 0x80092CDC: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80092CE0: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
    // 0x80092CE4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80092CE8:
    // 0x80092CE8: lh          $v1, 0x6DD0($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X6DD0);
    // 0x80092CEC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80092CF0: blez        $v1, L_80092D48
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80092CF4: nop
    
            goto L_80092D48;
    }
    // 0x80092CF4: nop

    // 0x80092CF8: lw          $v0, 0x994($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X994);
    // 0x80092CFC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092D00: blez        $v0, L_80092D48
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80092D04: nop
    
            goto L_80092D48;
    }
    // 0x80092D04: nop

    // 0x80092D08: lw          $a0, 0x6DE8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6DE8);
    // 0x80092D0C: nop

    // 0x80092D10: beq         $a0, $zero, L_80092D38
    if (ctx->r4 == 0) {
        // 0x80092D14: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80092D38;
    }
    // 0x80092D14: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80092D18: jal         0x8000488C
    // 0x80092D1C: nop

    sndp_stop(rdram, ctx);
        goto after_11;
    // 0x80092D1C: nop

    after_11:
    // 0x80092D20: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80092D24: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80092D28: lw          $v0, 0x994($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X994);
    // 0x80092D2C: lh          $v1, 0x6DD0($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X6DD0);
    // 0x80092D30: nop

    // 0x80092D34: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
L_80092D38:
    // 0x80092D38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092D3C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092D40: sw          $t9, 0x994($at)
    MEM_W(0X994, ctx->r1) = ctx->r25;
    // 0x80092D44: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_80092D48:
    // 0x80092D48: bgez        $v1, L_80093060
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80092D4C: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_80093060;
    }
    // 0x80092D4C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80092D50: lw          $t7, 0x994($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X994);
    // 0x80092D54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092D58: bgtz        $t7, L_80093064
    if (SIGNED(ctx->r15) > 0) {
        // 0x80092D5C: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_80093064;
    }
    // 0x80092D5C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80092D60: lw          $a0, 0x6DE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6DE0);
    // 0x80092D64: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80092D68: beq         $a0, $zero, L_80092D78
    if (ctx->r4 == 0) {
        // 0x80092D6C: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_80092D78;
    }
    // 0x80092D6C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80092D70: jal         0x8000488C
    // 0x80092D74: nop

    sndp_stop(rdram, ctx);
        goto after_12;
    // 0x80092D74: nop

    after_12:
L_80092D78:
    // 0x80092D78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80092D7C: jal         0x8006FB8C
    // 0x80092D80: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_13;
    // 0x80092D80: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_13:
    // 0x80092D84: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80092D88: bne         $at, $zero, L_80092DA8
    if (ctx->r1 != 0) {
        // 0x80092D8C: addiu       $a0, $zero, 0x147
        ctx->r4 = ADD32(0, 0X147);
            goto L_80092DA8;
    }
    // 0x80092D8C: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    // 0x80092D90: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80092D94: addiu       $a1, $a1, 0x6DE8
    ctx->r5 = ADD32(ctx->r5, 0X6DE8);
    // 0x80092D98: jal         0x80001D04
    // 0x80092D9C: addiu       $a0, $zero, 0x141
    ctx->r4 = ADD32(0, 0X141);
    sound_play(rdram, ctx);
        goto after_14;
    // 0x80092D9C: addiu       $a0, $zero, 0x141
    ctx->r4 = ADD32(0, 0X141);
    after_14:
    // 0x80092DA0: b           L_80092DB4
    // 0x80092DA4: nop

        goto L_80092DB4;
    // 0x80092DA4: nop

L_80092DA8:
    // 0x80092DA8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80092DAC: jal         0x80001D04
    // 0x80092DB0: addiu       $a1, $a1, 0x6DE8
    ctx->r5 = ADD32(ctx->r5, 0X6DE8);
    sound_play(rdram, ctx);
        goto after_15;
    // 0x80092DB0: addiu       $a1, $a1, 0x6DE8
    ctx->r5 = ADD32(ctx->r5, 0X6DE8);
    after_15:
L_80092DB4:
    // 0x80092DB4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80092DB8: lw          $t9, 0x994($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X994);
    // 0x80092DBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092DC0: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80092DC4: b           L_80093060
    // 0x80092DC8: sw          $t8, 0x994($at)
    MEM_W(0X994, ctx->r1) = ctx->r24;
        goto L_80093060;
    // 0x80092DC8: sw          $t8, 0x994($at)
    MEM_W(0X994, ctx->r1) = ctx->r24;
L_80092DCC:
    // 0x80092DCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80092DD0: bne         $v0, $at, L_80092ED0
    if (ctx->r2 != ctx->r1) {
        // 0x80092DD4: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80092ED0;
    }
    // 0x80092DD4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092DD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80092DDC: bne         $t2, $at, L_80092ED0
    if (ctx->r10 != ctx->r1) {
        // 0x80092DE0: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80092ED0;
    }
    // 0x80092DE0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80092DE4: lw          $t7, 0x6F88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6F88);
    // 0x80092DE8: nop

    // 0x80092DEC: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80092DF0: beq         $at, $zero, L_80092ED0
    if (ctx->r1 == 0) {
        // 0x80092DF4: nop
    
            goto L_80092ED0;
    }
    // 0x80092DF4: nop

    // 0x80092DF8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092DFC: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x80092E00: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80092E04: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80092E08: andi        $t6, $v1, 0x9000
    ctx->r14 = ctx->r3 & 0X9000;
    // 0x80092E0C: beq         $t6, $zero, L_80092E24
    if (ctx->r14 == 0) {
        // 0x80092E10: andi        $t7, $v1, 0x4000
        ctx->r15 = ctx->r3 & 0X4000;
            goto L_80092E24;
    }
    // 0x80092E10: andi        $t7, $v1, 0x4000
    ctx->r15 = ctx->r3 & 0X4000;
    // 0x80092E14: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092E18: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80092E1C: b           L_80093060
    // 0x80092E20: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_80093060;
    // 0x80092E20: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_80092E24:
    // 0x80092E24: beq         $t7, $zero, L_80092E78
    if (ctx->r15 == 0) {
        // 0x80092E28: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80092E78;
    }
    // 0x80092E28: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80092E2C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80092E30: addiu       $t1, $t1, -0x600
    ctx->r9 = ADD32(ctx->r9, -0X600);
    // 0x80092E34: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80092E38: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80092E3C: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x80092E40: andi        $t7, $t8, 0x4000
    ctx->r15 = ctx->r24 & 0X4000;
    // 0x80092E44: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
    // 0x80092E48: beq         $t7, $zero, L_80092E60
    if (ctx->r15 == 0) {
        // 0x80092E4C: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_80092E60;
    }
    // 0x80092E4C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80092E50: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80092E54: addiu       $t3, $t3, 0x6F84
    ctx->r11 = ADD32(ctx->r11, 0X6F84);
    // 0x80092E58: b           L_80092E6C
    // 0x80092E5C: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
        goto L_80092E6C;
    // 0x80092E5C: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
L_80092E60:
    // 0x80092E60: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80092E64: addiu       $t3, $t3, 0x6F84
    ctx->r11 = ADD32(ctx->r11, 0X6F84);
    // 0x80092E68: sb          $zero, 0x1($t3)
    MEM_B(0X1, ctx->r11) = 0;
L_80092E6C:
    // 0x80092E6C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80092E70: b           L_80093060
    // 0x80092E74: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
        goto L_80093060;
    // 0x80092E74: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80092E78:
    // 0x80092E78: lh          $v1, 0x6DC0($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X6DC0);
    // 0x80092E7C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80092E80: bgez        $v1, L_80092EA4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80092E84: addiu       $a0, $a0, 0x990
        ctx->r4 = ADD32(ctx->r4, 0X990);
            goto L_80092EA4;
    }
    // 0x80092E84: addiu       $a0, $a0, 0x990
    ctx->r4 = ADD32(ctx->r4, 0X990);
    // 0x80092E88: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80092E8C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80092E90: blez        $v0, L_80092EA4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80092E94: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80092EA4;
    }
    // 0x80092E94: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80092E98: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80092E9C: b           L_80093060
    // 0x80092EA0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
        goto L_80093060;
    // 0x80092EA0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_80092EA4:
    // 0x80092EA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80092EA8: blez        $v1, L_80093060
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80092EAC: addiu       $a0, $a0, 0x990
        ctx->r4 = ADD32(ctx->r4, 0X990);
            goto L_80093060;
    }
    // 0x80092EAC: addiu       $a0, $a0, 0x990
    ctx->r4 = ADD32(ctx->r4, 0X990);
    // 0x80092EB0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80092EB4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80092EB8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80092EBC: beq         $at, $zero, L_80093060
    if (ctx->r1 == 0) {
        // 0x80092EC0: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_80093060;
    }
    // 0x80092EC0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80092EC4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80092EC8: b           L_80093060
    // 0x80092ECC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
        goto L_80093060;
    // 0x80092ECC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_80092ED0:
    // 0x80092ED0: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x80092ED4: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80092ED8: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80092EDC: andi        $t9, $v1, 0x9000
    ctx->r25 = ctx->r3 & 0X9000;
    // 0x80092EE0: beq         $t9, $zero, L_80092F38
    if (ctx->r25 == 0) {
        // 0x80092EE4: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80092F38;
    }
    // 0x80092EE4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80092EE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092EEC: sw          $ra, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r31;
    // 0x80092EF0: jal         0x80078EFC
    // 0x80092EF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    bgdraw_set_func(rdram, ctx);
        goto after_16;
    // 0x80092EF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x80092EF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092EFC: jal         0x800C06A0
    // 0x80092F00: sw          $zero, 0xEFC($at)
    MEM_W(0XEFC, ctx->r1) = 0;
    disable_new_screen_transitions(rdram, ctx);
        goto after_17;
    // 0x80092F00: sw          $zero, 0xEFC($at)
    MEM_W(0XEFC, ctx->r1) = 0;
    after_17:
    // 0x80092F04: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80092F08: jal         0x800C06F8
    // 0x80092F0C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_18;
    // 0x80092F0C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_18:
    // 0x80092F10: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80092F14: lw          $t8, 0x6F88($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6F88);
    // 0x80092F18: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80092F1C: bne         $t8, $at, L_80092F30
    if (ctx->r24 != ctx->r1) {
        // 0x80092F20: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80092F30;
    }
    // 0x80092F20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80092F24: jal         0x800C3744
    // 0x80092F28: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    set_current_text(rdram, ctx);
        goto after_19;
    // 0x80092F28: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    after_19:
    // 0x80092F2C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80092F30:
    // 0x80092F30: b           L_80093060
    // 0x80092F34: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
        goto L_80093060;
    // 0x80092F34: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
L_80092F38:
    // 0x80092F38: lw          $v0, 0x6F88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6F88);
    // 0x80092F3C: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
    // 0x80092F40: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80092F44: bne         $at, $zero, L_80092FB8
    if (ctx->r1 != 0) {
        // 0x80092F48: addiu       $ra, $zero, 0x1
        ctx->r31 = ADD32(0, 0X1);
            goto L_80092FB8;
    }
    // 0x80092F48: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80092F4C: beq         $t6, $zero, L_80093060
    if (ctx->r14 == 0) {
        // 0x80092F50: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80093060;
    }
    // 0x80092F50: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80092F54: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80092F58: bne         $v0, $at, L_80092F8C
    if (ctx->r2 != ctx->r1) {
        // 0x80092F5C: sw          $t9, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r25;
            goto L_80092F8C;
    }
    // 0x80092F5C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80092F60: jal         0x8009F1A4
    // 0x80092F64: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_20;
    // 0x80092F64: nop

    after_20:
    // 0x80092F68: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80092F6C: addiu       $t4, $t4, 0x6980
    ctx->r12 = ADD32(ctx->r12, 0X6980);
    // 0x80092F70: beq         $v0, $zero, L_80092F8C
    if (ctx->r2 == 0) {
        // 0x80092F74: addiu       $t5, $zero, -0x1
        ctx->r13 = ADD32(0, -0X1);
            goto L_80092F8C;
    }
    // 0x80092F74: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80092F78: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x80092F7C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80092F80: lw          $v0, 0x6F88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6F88);
    // 0x80092F84: b           L_80092FA0
    // 0x80092F88: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
        goto L_80092FA0;
    // 0x80092F88: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_80092F8C:
    // 0x80092F8C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80092F90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092F94: lw          $v0, 0x6F88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6F88);
    // 0x80092F98: sw          $t5, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r13;
    // 0x80092F9C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_80092FA0:
    // 0x80092FA0: bne         $v0, $at, L_80093064
    if (ctx->r2 != ctx->r1) {
        // 0x80092FA4: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_80093064;
    }
    // 0x80092FA4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80092FA8: jal         0x800C3744
    // 0x80092FAC: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    set_current_text(rdram, ctx);
        goto after_21;
    // 0x80092FAC: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    after_21:
    // 0x80092FB0: b           L_80093064
    // 0x80092FB4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_80093064;
    // 0x80092FB4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80092FB8:
    // 0x80092FB8: bne         $ra, $t2, L_80092FE0
    if (ctx->r31 != ctx->r10) {
        // 0x80092FBC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80092FE0;
    }
    // 0x80092FBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80092FC0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80092FC4: nop

    // 0x80092FC8: andi        $t7, $t8, 0x4000
    ctx->r15 = ctx->r24 & 0X4000;
    // 0x80092FCC: beq         $t7, $zero, L_80093064
    if (ctx->r15 == 0) {
        // 0x80092FD0: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_80093064;
    }
    // 0x80092FD0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80092FD4: sw          $ra, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r31;
    // 0x80092FD8: b           L_80093060
    // 0x80092FDC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
        goto L_80093060;
    // 0x80092FDC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
L_80092FE0:
    // 0x80092FE0: bne         $t2, $at, L_80093000
    if (ctx->r10 != ctx->r1) {
        // 0x80092FE4: andi        $t6, $v1, 0x4000
        ctx->r14 = ctx->r3 & 0X4000;
            goto L_80093000;
    }
    // 0x80092FE4: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
    // 0x80092FE8: beq         $t6, $zero, L_80093060
    if (ctx->r14 == 0) {
        // 0x80092FEC: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_80093060;
    }
    // 0x80092FEC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80092FF0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092FF4: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80092FF8: b           L_80093060
    // 0x80092FFC: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_80093060;
    // 0x80092FFC: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80093000:
    // 0x80093000: blez        $t2, L_80093060
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80093004: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80093060;
    }
    // 0x80093004: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80093008: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009300C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80093010: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80093014: addiu       $t1, $t1, -0x600
    ctx->r9 = ADD32(ctx->r9, -0X600);
    // 0x80093018: addiu       $t3, $t3, 0x6F84
    ctx->r11 = ADD32(ctx->r11, 0X6F84);
    // 0x8009301C: addiu       $t0, $t0, 0x6D78
    ctx->r8 = ADD32(ctx->r8, 0X6D78);
L_80093020:
    // 0x80093020: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80093024: nop

    // 0x80093028: andi        $t6, $t7, 0x4000
    ctx->r14 = ctx->r15 & 0X4000;
    // 0x8009302C: beq         $t6, $zero, L_80093050
    if (ctx->r14 == 0) {
        // 0x80093030: addu        $t7, $t3, $a1
        ctx->r15 = ADD32(ctx->r11, ctx->r5);
            goto L_80093050;
    }
    // 0x80093030: addu        $t7, $t3, $a1
    ctx->r15 = ADD32(ctx->r11, ctx->r5);
    // 0x80093034: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80093038: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8009303C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80093040: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x80093044: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80093048: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
    // 0x8009304C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80093050:
    // 0x80093050: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80093054: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80093058: bne         $at, $zero, L_80093020
    if (ctx->r1 != 0) {
        // 0x8009305C: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_80093020;
    }
    // 0x8009305C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_80093060:
    // 0x80093060: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80093064:
    // 0x80093064: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80093068: beq         $t9, $zero, L_80093080
    if (ctx->r25 == 0) {
        // 0x8009306C: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_80093080;
    }
    // 0x8009306C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80093070: jal         0x80001D04
    // 0x80093074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_22;
    // 0x80093074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x80093078: b           L_800930B0
    // 0x8009307C: nop

        goto L_800930B0;
    // 0x8009307C: nop

L_80093080:
    // 0x80093080: beq         $t8, $zero, L_80093098
    if (ctx->r24 == 0) {
        // 0x80093084: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80093098;
    }
    // 0x80093084: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80093088: jal         0x80001D04
    // 0x8009308C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_23;
    // 0x8009308C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x80093090: b           L_800930B0
    // 0x80093094: nop

        goto L_800930B0;
    // 0x80093094: nop

L_80093098:
    // 0x80093098: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8009309C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800930A0: beq         $t7, $zero, L_800930B0
    if (ctx->r15 == 0) {
        // 0x800930A4: nop
    
            goto L_800930B0;
    }
    // 0x800930A4: nop

    // 0x800930A8: jal         0x80001D04
    // 0x800930AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_24;
    // 0x800930AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
L_800930B0:
    // 0x800930B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800930B4: lb          $a0, 0x6F80($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X6F80);
    // 0x800930B8: jal         0x8006DD54
    // 0x800930BC: nop

    set_level_default_vehicle(rdram, ctx);
        goto after_25;
    // 0x800930BC: nop

    after_25:
    // 0x800930C0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800930C4: lw          $t6, -0x5C4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C4);
    // 0x800930C8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800930CC: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800930D0: beq         $at, $zero, L_800930EC
    if (ctx->r1 == 0) {
        // 0x800930D4: nop
    
            goto L_800930EC;
    }
    // 0x800930D4: nop

    // 0x800930D8: lw          $t9, 0x6F88($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6F88);
    // 0x800930DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800930E0: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x800930E4: bne         $at, $zero, L_800930FC
    if (ctx->r1 != 0) {
        // 0x800930E8: nop
    
            goto L_800930FC;
    }
    // 0x800930E8: nop

L_800930EC:
    // 0x800930EC: jal         0x8000E4BC
    // 0x800930F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_time_trial_enabled(rdram, ctx);
        goto after_26;
    // 0x800930F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_26:
    // 0x800930F4: b           L_80093108
    // 0x800930F8: nop

        goto L_80093108;
    // 0x800930F8: nop

L_800930FC:
    // 0x800930FC: lw          $a0, 0x994($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X994);
    // 0x80093100: jal         0x8000E4BC
    // 0x80093104: nop

    set_time_trial_enabled(rdram, ctx);
        goto after_27;
    // 0x80093104: nop

    after_27:
L_80093108:
    // 0x80093108: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009310C: lw          $t8, 0x998($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X998);
    // 0x80093110: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093114: sw          $t8, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r24;
    // 0x80093118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009311C:
    // 0x8009311C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80093120: jr          $ra
    // 0x80093124: nop

    return;
    // 0x80093124: nop

;}
RECOMP_FUNC void mtxf_to_mtxs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F820: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8006F824: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8006F828: ori         $t0, $zero, 0x4
    ctx->r8 = 0 | 0X4;
L_8006F82C:
    // 0x8006F82C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006F830: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006F834: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006F838: mul.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F83C: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8006F840: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8006F844: mul.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006F848: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8006F84C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8006F850: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8006F854: nop

    // 0x8006F858: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8006F85C: trunc.w.s   $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8006F860: trunc.w.s   $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006F864: swc1        $f4, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->f4.u32l;
    // 0x8006F868: trunc.w.s   $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8006F86C: swc1        $f6, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->f6.u32l;
    // 0x8006F870: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8006F874: swc1        $f8, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->f8.u32l;
    // 0x8006F878: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x8006F87C: bnel        $t0, $zero, L_8006F82C
    if (ctx->r8 != 0) {
        // 0x8006F880: nop
    
            goto L_8006F82C;
    }
    goto skip_0;
    // 0x8006F880: nop

    skip_0:
    // 0x8006F884: jr          $ra
    // 0x8006F888: nop

    return;
    // 0x8006F888: nop

;}
RECOMP_FUNC void mark_to_read_flap_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED64: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006ED68: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006ED6C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006ED70: nop

    // 0x8006ED74: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8006ED78: jr          $ra
    // 0x8006ED7C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006ED7C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void arctan2_f(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_800708AC:
    // 0x80070990: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80070994: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80070998: nop

    // 0x8007099C: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800709A0: nop

    // 0x800709A4: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800709A8: cvt.w.s     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = CVT_W_S(ctx->f12.fl);
    // 0x800709AC: cvt.w.s     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = CVT_W_S(ctx->f14.fl);
    // 0x800709B0: mfc1        $a0, $f12
    ctx->r4 = (int32_t)ctx->f12.u32l;
    // 0x800709B4: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800709B8: j           L_800708AC
    // 0x800709BC: nop

    atan2s(rdram, ctx);
    return;
    // 0x800709BC: nop

;}
RECOMP_FUNC void func_80079760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079BB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80079BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079BB8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80079BBC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80079BC0: lw          $t6, 0x264($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X264);
    // 0x80079BC4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80079BC8: beq         $t6, $zero, L_80079BD4
    if (ctx->r14 == 0) {
        // 0x80079BCC: addiu       $a1, $sp, 0x20
        ctx->r5 = ADD32(ctx->r29, 0X20);
            goto L_80079BD4;
    }
    // 0x80079BCC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80079BD0: sw          $t7, 0x284($a0)
    MEM_W(0X284, ctx->r4) = ctx->r15;
L_80079BD4:
    // 0x80079BD4: lw          $t8, 0x284($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X284);
    // 0x80079BD8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80079BDC: beq         $t8, $zero, L_80079C04
    if (ctx->r24 == 0) {
        // 0x80079BE0: nop
    
            goto L_80079C04;
    }
    // 0x80079BE0: nop

    // 0x80079BE4: lw          $t9, 0x274($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X274);
    // 0x80079BE8: nop

    // 0x80079BEC: beq         $t9, $zero, L_80079C04
    if (ctx->r25 == 0) {
        // 0x80079BF0: nop
    
            goto L_80079C04;
    }
    // 0x80079BF0: nop

    // 0x80079BF4: jal         0x8007A4D0
    // 0x80079BF8: nop

    static_3_8007A4D0(rdram, ctx);
        goto after_0;
    // 0x80079BF8: nop

    after_0:
    // 0x80079BFC: b           L_80079C4C
    // 0x80079C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80079C4C;
    // 0x80079C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80079C04:
    // 0x80079C04: lw          $t0, 0x274($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X274);
    // 0x80079C08: lw          $t3, 0x278($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X278);
    // 0x80079C0C: sltiu       $t1, $t0, 0x1
    ctx->r9 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80079C10: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80079C14: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80079C18: or          $a3, $t2, $t4
    ctx->r7 = ctx->r10 | ctx->r12;
    // 0x80079C1C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80079C20: jal         0x8007A524
    // 0x80079C24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    static_3_8007A524(rdram, ctx);
        goto after_1;
    // 0x80079C24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x80079C28: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80079C2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80079C30: beq         $v0, $a3, L_80079C4C
    if (ctx->r2 == ctx->r7) {
        // 0x80079C34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80079C4C;
    }
    // 0x80079C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80079C38: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80079C3C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80079C40: jal         0x8007A3F8
    // 0x80079C44: nop

    static_3_8007A3F8(rdram, ctx);
        goto after_2;
    // 0x80079C44: nop

    after_2:
    // 0x80079C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80079C4C:
    // 0x80079C4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80079C50: jr          $ra
    // 0x80079C54: nop

    return;
    // 0x80079C54: nop

;}
RECOMP_FUNC void func_8001D248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D27C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001D280: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001D284: jr          $ra
    // 0x8001D288: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x8001D288: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void obj_loop_exit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038F98: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80038F9C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80038FA0: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80038FA4: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x80038FA8: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80038FAC: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80038FB0: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80038FB4: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80038FB8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80038FBC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80038FC0: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80038FC4: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80038FC8: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80038FCC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80038FD0: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80038FD4: lw          $s5, 0x64($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X64);
    // 0x80038FD8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80038FDC: jal         0x8006ECD0
    // 0x80038FE0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80038FE0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_0:
    // 0x80038FE4: lb          $v1, 0x14($s5)
    ctx->r3 = MEM_B(ctx->r21, 0X14);
    // 0x80038FE8: nop

    // 0x80038FEC: bne         $v1, $zero, L_8003901C
    if (ctx->r3 != 0) {
        // 0x80038FF0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8003901C;
    }
    // 0x80038FF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80038FF4: lbu         $t7, 0x48($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X48);
    // 0x80038FF8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80038FFC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80039000: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80039004: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80039008: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003900C: bne         $t0, $at, L_8003901C
    if (ctx->r8 != ctx->r1) {
        // 0x80039010: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8003901C;
    }
    // 0x80039010: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80039014: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80039018: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8003901C:
    // 0x8003901C: bne         $v1, $at, L_8003904C
    if (ctx->r3 != ctx->r1) {
        // 0x80039020: nop
    
            goto L_8003904C;
    }
    // 0x80039020: nop

    // 0x80039024: lbu         $t2, 0x48($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X48);
    // 0x80039028: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8003902C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80039030: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80039034: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80039038: nop

    // 0x8003903C: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x80039040: beq         $at, $zero, L_8003904C
    if (ctx->r1 == 0) {
        // 0x80039044: nop
    
            goto L_8003904C;
    }
    // 0x80039044: nop

    // 0x80039048: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8003904C:
    // 0x8003904C: beq         $s0, $zero, L_80039168
    if (ctx->r16 == 0) {
        // 0x80039050: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80039168;
    }
    // 0x80039050: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80039054: lw          $t7, 0x4C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X4C);
    // 0x80039058: lw          $v0, 0x10($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X10);
    // 0x8003905C: lbu         $t6, 0x13($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X13);
    // 0x80039060: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80039064: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80039068: beq         $at, $zero, L_80039168
    if (ctx->r1 == 0) {
        // 0x8003906C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80039168;
    }
    // 0x8003906C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80039070: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80039074: jal         0x8001BAA8
    // 0x80039078: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    get_racer_objects(rdram, ctx);
        goto after_1;
    // 0x80039078: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    after_1:
    // 0x8003907C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80039080: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80039084: blez        $t8, L_80039164
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80039088: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80039164;
    }
    // 0x80039088: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003908C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80039090: addiu       $s7, $zero, -0x78
    ctx->r23 = ADD32(0, -0X78);
    // 0x80039094: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_80039098:
    // 0x80039098: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8003909C: nop

    // 0x800390A0: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x800390A4: nop

    // 0x800390A8: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x800390AC: nop

    // 0x800390B0: beq         $s6, $t9, L_80039154
    if (ctx->r22 == ctx->r25) {
        // 0x800390B4: lw          $t2, 0x74($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X74);
            goto L_80039154;
    }
    // 0x800390B4: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x800390B8: lw          $t0, 0x108($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X108);
    // 0x800390BC: nop

    // 0x800390C0: bne         $t0, $zero, L_80039154
    if (ctx->r8 != 0) {
        // 0x800390C4: lw          $t2, 0x74($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X74);
            goto L_80039154;
    }
    // 0x800390C4: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x800390C8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800390CC: lwc1        $f8, 0xC($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800390D0: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800390D4: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800390D8: lwc1        $f16, 0x10($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X10);
    // 0x800390DC: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800390E0: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800390E4: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800390E8: lwc1        $f4, 0x14($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800390EC: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800390F0: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800390F4: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800390F8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800390FC: jal         0x800CA030
    // 0x80039100: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80039100: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_2:
    // 0x80039104: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80039108: nop

    // 0x8003910C: bc1f        L_80039154
    if (!c1cs) {
        // 0x80039110: lw          $t2, 0x74($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X74);
            goto L_80039154;
    }
    // 0x80039110: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80039114: lwc1        $f18, 0x0($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80039118: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003911C: lwc1        $f8, 0x8($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80039120: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80039124: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80039128: lwc1        $f4, 0xC($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0XC);
    // 0x8003912C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80039130: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80039134: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80039138: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8003913C: nop

    // 0x80039140: bc1f        L_80039154
    if (!c1cs) {
        // 0x80039144: lw          $t2, 0x74($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X74);
            goto L_80039154;
    }
    // 0x80039144: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80039148: sw          $s4, 0x108($s1)
    MEM_W(0X108, ctx->r17) = ctx->r20;
    // 0x8003914C: sb          $s7, 0x200($s1)
    MEM_B(0X200, ctx->r17) = ctx->r23;
    // 0x80039150: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
L_80039154:
    // 0x80039154: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80039158: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003915C: bne         $at, $zero, L_80039098
    if (ctx->r1 != 0) {
        // 0x80039160: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80039098;
    }
    // 0x80039160: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_80039164:
    // 0x80039164: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80039168:
    // 0x80039168: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8003916C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80039170: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80039174: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80039178: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8003917C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80039180: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80039184: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80039188: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8003918C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80039190: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x80039194: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80039198: jr          $ra
    // 0x8003919C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8003919C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void set_eeprom_settings_value(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EFBC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EFC0: addiu       $v0, $v0, 0x69E8
    ctx->r2 = ADD32(ctx->r2, 0X69E8);
    // 0x8009EFC4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8009EFC8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8009EFCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009EFD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EFD4: or          $t0, $t6, $a0
    ctx->r8 = ctx->r14 | ctx->r4;
    // 0x8009EFD8: or          $t1, $t7, $a1
    ctx->r9 = ctx->r15 | ctx->r5;
    // 0x8009EFDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009EFE0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009EFE4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8009EFE8: jal         0x8006EF20
    // 0x8009EFEC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    mark_write_eeprom_settings(rdram, ctx);
        goto after_0;
    // 0x8009EFEC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    after_0:
    // 0x8009EFF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EFF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009EFF8: jr          $ra
    // 0x8009EFFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8009EFFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void get_timestamp_from_frames(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800597E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800597E4: lw          $t6, 0x6710($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6710);
    // 0x800597E8: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x800597EC: bne         $t6, $at, L_80059838
    if (ctx->r14 != ctx->r1) {
        // 0x800597F0: addiu       $t0, $zero, 0xE10
        ctx->r8 = ADD32(0, 0XE10);
            goto L_80059838;
    }
    // 0x800597F0: addiu       $t0, $zero, 0xE10
    ctx->r8 = ADD32(0, 0XE10);
    // 0x800597F4: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800597F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800597FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80059800: lwc1        $f11, 0x6EB8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6EB8);
    // 0x80059804: lwc1        $f10, 0x6EBC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6EBC);
    // 0x80059808: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005980C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80059810: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80059814: nop

    // 0x80059818: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8005981C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059820: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059824: nop

    // 0x80059828: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x8005982C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80059830: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80059834: nop

L_80059838:
    // 0x80059838: div         $zero, $a0, $t0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r8)));
    // 0x8005983C: addiu       $t1, $zero, 0x3C
    ctx->r9 = ADD32(0, 0X3C);
    // 0x80059840: bne         $t0, $zero, L_8005984C
    if (ctx->r8 != 0) {
        // 0x80059844: nop
    
            goto L_8005984C;
    }
    // 0x80059844: nop

    // 0x80059848: break       7
    do_break(2147850312);
L_8005984C:
    // 0x8005984C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80059850: bne         $t0, $at, L_80059864
    if (ctx->r8 != ctx->r1) {
        // 0x80059854: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80059864;
    }
    // 0x80059854: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80059858: bne         $a0, $at, L_80059864
    if (ctx->r4 != ctx->r1) {
        // 0x8005985C: nop
    
            goto L_80059864;
    }
    // 0x8005985C: nop

    // 0x80059860: break       6
    do_break(2147850336);
L_80059864:
    // 0x80059864: mflo        $v0
    ctx->r2 = lo;
    // 0x80059868: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8005986C: nop

    // 0x80059870: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80059874: mflo        $t8
    ctx->r24 = lo;
    // 0x80059878: subu        $t9, $a0, $t8
    ctx->r25 = SUB32(ctx->r4, ctx->r24);
    // 0x8005987C: nop

    // 0x80059880: div         $zero, $t9, $t1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r9)));
    // 0x80059884: bne         $t1, $zero, L_80059890
    if (ctx->r9 != 0) {
        // 0x80059888: nop
    
            goto L_80059890;
    }
    // 0x80059888: nop

    // 0x8005988C: break       7
    do_break(2147850380);
L_80059890:
    // 0x80059890: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80059894: bne         $t1, $at, L_800598A8
    if (ctx->r9 != ctx->r1) {
        // 0x80059898: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800598A8;
    }
    // 0x80059898: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005989C: bne         $t9, $at, L_800598A8
    if (ctx->r25 != ctx->r1) {
        // 0x800598A0: nop
    
            goto L_800598A8;
    }
    // 0x800598A0: nop

    // 0x800598A4: break       6
    do_break(2147850404);
L_800598A8:
    // 0x800598A8: mflo        $v1
    ctx->r3 = lo;
    // 0x800598AC: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x800598B0: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800598B4: nop

    // 0x800598B8: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800598BC: mflo        $t3
    ctx->r11 = lo;
    // 0x800598C0: subu        $t4, $a0, $t3
    ctx->r12 = SUB32(ctx->r4, ctx->r11);
    // 0x800598C4: nop

    // 0x800598C8: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800598CC: mflo        $t5
    ctx->r13 = lo;
    // 0x800598D0: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x800598D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800598D8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800598DC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800598E0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800598E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800598E8: div         $zero, $t7, $t1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r9)));
    // 0x800598EC: bne         $t1, $zero, L_800598F8
    if (ctx->r9 != 0) {
        // 0x800598F0: nop
    
            goto L_800598F8;
    }
    // 0x800598F0: nop

    // 0x800598F4: break       7
    do_break(2147850484);
L_800598F8:
    // 0x800598F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800598FC: bne         $t1, $at, L_80059910
    if (ctx->r9 != ctx->r1) {
        // 0x80059900: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80059910;
    }
    // 0x80059900: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80059904: bne         $t7, $at, L_80059910
    if (ctx->r15 != ctx->r1) {
        // 0x80059908: nop
    
            goto L_80059910;
    }
    // 0x80059908: nop

    // 0x8005990C: break       6
    do_break(2147850508);
L_80059910:
    // 0x80059910: mflo        $t8
    ctx->r24 = lo;
    // 0x80059914: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80059918: jr          $ra
    // 0x8005991C: nop

    return;
    // 0x8005991C: nop

;}
RECOMP_FUNC void level_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BFF0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006BFF4: lw          $v0, 0x16E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16E8);
    // 0x8006BFF8: jr          $ra
    // 0x8006BFFC: nop

    return;
    // 0x8006BFFC: nop

;}
RECOMP_FUNC void func_80098774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098CB0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80098CB4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80098CB8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80098CBC: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80098CC0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80098CC4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80098CC8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80098CCC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80098CD0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80098CD4: jal         0x8006ECD0
    // 0x80098CD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80098CD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80098CDC: beq         $s6, $zero, L_80098CFC
    if (ctx->r22 == 0) {
        // 0x80098CE0: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_80098CFC;
    }
    // 0x80098CE0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80098CE4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80098CE8: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x80098CEC: nop

    // 0x80098CF0: lw          $v1, 0x84($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X84);
    // 0x80098CF4: b           L_80098D10
    // 0x80098CF8: nop

        goto L_80098D10;
    // 0x80098CF8: nop

L_80098CFC:
    // 0x80098CFC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80098D00: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x80098D04: nop

    // 0x80098D08: lw          $v1, 0x7C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X7C);
    // 0x80098D0C: nop

L_80098D10:
    // 0x80098D10: addiu       $a1, $a1, 0x15C8
    ctx->r5 = ADD32(ctx->r5, 0X15C8);
    // 0x80098D14: sw          $v1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r3;
    // 0x80098D18: sw          $v1, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r3;
    // 0x80098D1C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80098D20: lw          $t1, 0x1564($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1564);
    // 0x80098D24: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80098D28: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x80098D2C: addiu       $t0, $t1, -0x1
    ctx->r8 = ADD32(ctx->r9, -0X1);
    // 0x80098D30: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x80098D34: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x80098D38: bne         $t9, $zero, L_80098D48
    if (ctx->r25 != 0) {
        // 0x80098D3C: addiu       $a3, $zero, 0xF0
        ctx->r7 = ADD32(0, 0XF0);
            goto L_80098D48;
    }
    // 0x80098D3C: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x80098D40: addiu       $t0, $t8, 0x10
    ctx->r8 = ADD32(ctx->r24, 0X10);
    // 0x80098D44: addiu       $a3, $zero, 0x108
    ctx->r7 = ADD32(0, 0X108);
L_80098D48:
    // 0x80098D48: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80098D4C: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80098D50: addiu       $v1, $v1, 0x1A3C
    ctx->r3 = ADD32(ctx->r3, 0X1A3C);
    // 0x80098D54: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80098D58: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80098D5C: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80098D60: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    // 0x80098D64: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80098D68: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80098D6C: beq         $a2, $zero, L_80098F2C
    if (ctx->r6 == 0) {
        // 0x80098D70: addiu       $s0, $zero, 0x2
        ctx->r16 = ADD32(0, 0X2);
            goto L_80098F2C;
    }
    // 0x80098D70: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80098D74: beq         $a0, $zero, L_80098F30
    if (ctx->r4 == 0) {
        // 0x80098D78: sll         $t6, $s0, 5
        ctx->r14 = S32(ctx->r16 << 5);
            goto L_80098F30;
    }
    // 0x80098D78: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
    // 0x80098D7C: blez        $t1, L_80098F2C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80098D80: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80098F2C;
    }
    // 0x80098D80: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80098D84: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
    // 0x80098D88: sll         $t7, $s0, 5
    ctx->r15 = S32(ctx->r16 << 5);
    // 0x80098D8C: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x80098D90: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80098D94: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80098D98: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80098D9C: addiu       $t5, $t5, 0x1070
    ctx->r13 = ADD32(ctx->r13, 0X1070);
    // 0x80098DA0: addiu       $s3, $s3, 0x69D0
    ctx->r19 = ADD32(ctx->r19, 0X69D0);
    // 0x80098DA4: addiu       $s4, $s4, 0x69C8
    ctx->r20 = ADD32(ctx->r20, 0X69C8);
    // 0x80098DA8: addiu       $s5, $s5, 0x1584
    ctx->r21 = ADD32(ctx->r21, 0X1584);
    // 0x80098DAC: addu        $t3, $a1, $t7
    ctx->r11 = ADD32(ctx->r5, ctx->r15);
    // 0x80098DB0: addu        $t4, $a1, $t6
    ctx->r12 = ADD32(ctx->r5, ctx->r14);
    // 0x80098DB4: andi        $s1, $t1, 0x3
    ctx->r17 = ctx->r9 & 0X3;
    // 0x80098DB8: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x80098DBC: addiu       $ra, $zero, 0x18
    ctx->r31 = ADD32(0, 0X18);
L_80098DC0:
    // 0x80098DC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80098DC4: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_80098DC8:
    // 0x80098DC8: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x80098DCC: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x80098DD0: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80098DD4: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x80098DD8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80098DDC: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
    // 0x80098DE0: lh          $t6, -0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, -0X2);
    // 0x80098DE4: bne         $at, $zero, L_80098E2C
    if (ctx->r1 != 0) {
        // 0x80098DE8: sh          $t6, 0x8($v1)
        MEM_H(0X8, ctx->r3) = ctx->r14;
            goto L_80098E2C;
    }
    // 0x80098DE8: sh          $t6, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r14;
    // 0x80098DEC: sra         $t7, $t1, 1
    ctx->r15 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80098DF0: slt         $at, $t0, $t7
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80098DF4: bne         $at, $zero, L_80098E2C
    if (ctx->r1 != 0) {
        // 0x80098DF8: nop
    
            goto L_80098E2C;
    }
    // 0x80098DF8: nop

    // 0x80098DFC: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x80098E00: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80098E04: subu        $t9, $t8, $a3
    ctx->r25 = SUB32(ctx->r24, ctx->r7);
    // 0x80098E08: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x80098E0C: lh          $t6, -0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, -0X2);
    // 0x80098E10: nop

    // 0x80098E14: sh          $t6, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r14;
    // 0x80098E18: lh          $t7, -0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, -0X2);
    // 0x80098E1C: nop

    // 0x80098E20: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x80098E24: b           L_80098E58
    // 0x80098E28: sh          $t8, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r24;
        goto L_80098E58;
    // 0x80098E28: sh          $t8, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r24;
L_80098E2C:
    // 0x80098E2C: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x80098E30: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80098E34: addu        $t6, $t9, $a3
    ctx->r14 = ADD32(ctx->r25, ctx->r7);
    // 0x80098E38: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
    // 0x80098E3C: lh          $t7, -0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, -0X2);
    // 0x80098E40: nop

    // 0x80098E44: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x80098E48: lh          $t8, -0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, -0X2);
    // 0x80098E4C: nop

    // 0x80098E50: subu        $t9, $t8, $a3
    ctx->r25 = SUB32(ctx->r24, ctx->r7);
    // 0x80098E54: sh          $t9, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r25;
L_80098E58:
    // 0x80098E58: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x80098E5C: slti        $at, $a1, 0x60
    ctx->r1 = SIGNED(ctx->r5) < 0X60 ? 1 : 0;
    // 0x80098E60: bne         $at, $zero, L_80098DC8
    if (ctx->r1 != 0) {
        // 0x80098E64: addiu       $v1, $v1, 0x20
        ctx->r3 = ADD32(ctx->r3, 0X20);
            goto L_80098DC8;
    }
    // 0x80098E64: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80098E68: beq         $s1, $zero, L_80098E84
    if (ctx->r17 == 0) {
        // 0x80098E6C: addiu       $s0, $s0, 0x3
        ctx->r16 = ADD32(ctx->r16, 0X3);
            goto L_80098E84;
    }
    // 0x80098E6C: addiu       $s0, $s0, 0x3
    ctx->r16 = ADD32(ctx->r16, 0X3);
    // 0x80098E70: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80098E74: bne         $at, $zero, L_80098E88
    if (ctx->r1 != 0) {
        // 0x80098E78: or          $t2, $t0, $zero
        ctx->r10 = ctx->r8 | 0;
            goto L_80098E88;
    }
    // 0x80098E78: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80098E7C: b           L_80098E88
    // 0x80098E80: addiu       $t2, $t0, -0x3
    ctx->r10 = ADD32(ctx->r8, -0X3);
        goto L_80098E88;
    // 0x80098E80: addiu       $t2, $t0, -0x3
    ctx->r10 = ADD32(ctx->r8, -0X3);
L_80098E84:
    // 0x80098E84: andi        $t2, $t0, 0x3
    ctx->r10 = ctx->r8 & 0X3;
L_80098E88:
    // 0x80098E88: sll         $t6, $t2, 6
    ctx->r14 = S32(ctx->r10 << 6);
    // 0x80098E8C: subu        $t7, $s2, $t6
    ctx->r15 = SUB32(ctx->r18, ctx->r14);
    // 0x80098E90: beq         $s6, $zero, L_80098ED4
    if (ctx->r22 == 0) {
        // 0x80098E94: sb          $t7, 0x4D($t3)
        MEM_B(0X4D, ctx->r11) = ctx->r15;
            goto L_80098ED4;
    }
    // 0x80098E94: sb          $t7, 0x4D($t3)
    MEM_B(0X4D, ctx->r11) = ctx->r15;
    // 0x80098E98: addu        $t8, $s3, $t0
    ctx->r24 = ADD32(ctx->r19, ctx->r8);
    // 0x80098E9C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80098EA0: nop

    // 0x80098EA4: multu       $t9, $ra
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80098EA8: mflo        $t6
    ctx->r14 = lo;
    // 0x80098EAC: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80098EB0: lb          $t7, 0x59($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X59);
    // 0x80098EB4: nop

    // 0x80098EB8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80098EBC: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x80098EC0: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80098EC4: addiu       $t7, $v1, 0x54
    ctx->r15 = ADD32(ctx->r3, 0X54);
    // 0x80098EC8: sw          $t7, 0x54($t3)
    MEM_W(0X54, ctx->r11) = ctx->r15;
    // 0x80098ECC: b           L_80098F10
    // 0x80098ED0: sw          $t6, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r14;
        goto L_80098F10;
    // 0x80098ED0: sw          $t6, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r14;
L_80098ED4:
    // 0x80098ED4: addu        $t8, $s4, $t0
    ctx->r24 = ADD32(ctx->r20, ctx->r8);
    // 0x80098ED8: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80098EDC: nop

    // 0x80098EE0: multu       $t9, $ra
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80098EE4: mflo        $t6
    ctx->r14 = lo;
    // 0x80098EE8: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80098EEC: lb          $t8, 0x59($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X59);
    // 0x80098EF0: nop

    // 0x80098EF4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80098EF8: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x80098EFC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80098F00: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80098F04: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x80098F08: sw          $t9, 0x54($t3)
    MEM_W(0X54, ctx->r11) = ctx->r25;
    // 0x80098F0C: sw          $t7, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r15;
L_80098F10:
    // 0x80098F10: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80098F14: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80098F18: addiu       $t4, $t4, 0x60
    ctx->r12 = ADD32(ctx->r12, 0X60);
    // 0x80098F1C: bne         $at, $zero, L_80098DC0
    if (ctx->r1 != 0) {
        // 0x80098F20: addiu       $t3, $t3, 0x60
        ctx->r11 = ADD32(ctx->r11, 0X60);
            goto L_80098DC0;
    }
    // 0x80098F20: addiu       $t3, $t3, 0x60
    ctx->r11 = ADD32(ctx->r11, 0X60);
    // 0x80098F24: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80098F28: addiu       $a1, $a1, 0x15C8
    ctx->r5 = ADD32(ctx->r5, 0X15C8);
L_80098F2C:
    // 0x80098F2C: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
L_80098F30:
    // 0x80098F30: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x80098F34: sw          $zero, 0x14($t7)
    MEM_W(0X14, ctx->r15) = 0;
    // 0x80098F38: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80098F3C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80098F40: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80098F44: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80098F48: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80098F4C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80098F50: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80098F54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80098F58: jr          $ra
    // 0x80098F5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80098F5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void obj_init_effectbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034BA8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80034BAC: jr          $ra
    // 0x80034BB0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80034BB0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void level_is_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B480: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006B484: lw          $v0, -0x2774($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2774);
    // 0x8006B488: jr          $ra
    // 0x8006B48C: nop

    return;
    // 0x8006B48C: nop

;}
RECOMP_FUNC void func_80072C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072EAC: bgtz        $a0, L_80072EBC
    if (SIGNED(ctx->r4) > 0) {
        // 0x80072EB0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80072EBC;
    }
    // 0x80072EB0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80072EB4: jr          $ra
    // 0x80072EB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80072EB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80072EBC:
    // 0x80072EBC: addiu       $t6, $a0, 0x1F
    ctx->r14 = ADD32(ctx->r4, 0X1F);
    // 0x80072EC0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80072EC4: beq         $a0, $zero, L_80073074
    if (ctx->r4 == 0) {
        // 0x80072EC8: sllv        $v0, $t7, $t6
        ctx->r2 = S32(ctx->r15 << (ctx->r14 & 31));
            goto L_80073074;
    }
    // 0x80072EC8: sllv        $v0, $t7, $t6
    ctx->r2 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80072ECC: andi        $a1, $a0, 0x3
    ctx->r5 = ctx->r4 & 0X3;
    // 0x80072ED0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x80072ED4: beq         $a1, $zero, L_80072F4C
    if (ctx->r5 == 0) {
        // 0x80072ED8: addu        $t0, $a1, $a0
        ctx->r8 = ADD32(ctx->r5, ctx->r4);
            goto L_80072F4C;
    }
    // 0x80072ED8: addu        $t0, $a1, $a0
    ctx->r8 = ADD32(ctx->r5, ctx->r4);
    // 0x80072EDC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80072EE0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80072EE4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80072EE8: addiu       $t1, $t1, 0x4774
    ctx->r9 = ADD32(ctx->r9, 0X4774);
    // 0x80072EEC: addiu       $t2, $t2, 0x4770
    ctx->r10 = ADD32(ctx->r10, 0X4770);
    // 0x80072EF0: addiu       $t3, $t3, 0x476C
    ctx->r11 = ADD32(ctx->r11, 0X476C);
    // 0x80072EF4: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
L_80072EF8:
    // 0x80072EF8: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80072EFC: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x80072F00: bne         $a2, $zero, L_80072F24
    if (ctx->r6 != 0) {
        // 0x80072F04: srl         $t6, $v0, 1
        ctx->r14 = S32(U32(ctx->r2) >> 1);
            goto L_80072F24;
    }
    // 0x80072F04: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x80072F08: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80072F0C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80072F10: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x80072F14: addiu       $t9, $a3, 0x1
    ctx->r25 = ADD32(ctx->r7, 0X1);
    // 0x80072F18: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80072F1C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80072F20: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_80072F24:
    // 0x80072F24: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80072F28: srl         $t8, $a2, 1
    ctx->r24 = S32(U32(ctx->r6) >> 1);
    // 0x80072F2C: and         $t7, $t5, $a2
    ctx->r15 = ctx->r13 & ctx->r6;
    // 0x80072F30: beq         $t7, $zero, L_80072F3C
    if (ctx->r15 == 0) {
        // 0x80072F34: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80072F3C;
    }
    // 0x80072F34: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80072F38: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80072F3C:
    // 0x80072F3C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072F40: bne         $t0, $a1, L_80072EF8
    if (ctx->r8 != ctx->r5) {
        // 0x80072F44: sw          $t8, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r24;
            goto L_80072EF8;
    }
    // 0x80072F44: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80072F48: beq         $a1, $zero, L_80073074
    if (ctx->r5 == 0) {
        // 0x80072F4C: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_80073074;
    }
L_80072F4C:
    // 0x80072F4C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80072F50: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80072F54: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80072F58: addiu       $t3, $t3, 0x476C
    ctx->r11 = ADD32(ctx->r11, 0X476C);
    // 0x80072F5C: addiu       $t2, $t2, 0x4770
    ctx->r10 = ADD32(ctx->r10, 0X4770);
    // 0x80072F60: addiu       $t1, $t1, 0x4774
    ctx->r9 = ADD32(ctx->r9, 0X4774);
    // 0x80072F64: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
L_80072F68:
    // 0x80072F68: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80072F6C: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x80072F70: bne         $a2, $zero, L_80072F94
    if (ctx->r6 != 0) {
        // 0x80072F74: addiu       $a0, $a0, -0x4
        ctx->r4 = ADD32(ctx->r4, -0X4);
            goto L_80072F94;
    }
    // 0x80072F74: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80072F78: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80072F7C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80072F80: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x80072F84: addiu       $t5, $a3, 0x1
    ctx->r13 = ADD32(ctx->r7, 0X1);
    // 0x80072F88: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x80072F8C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80072F90: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
L_80072F94:
    // 0x80072F94: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x80072F98: srl         $t8, $a2, 1
    ctx->r24 = S32(U32(ctx->r6) >> 1);
    // 0x80072F9C: and         $t7, $a1, $a2
    ctx->r15 = ctx->r5 & ctx->r6;
    // 0x80072FA0: beq         $t7, $zero, L_80072FAC
    if (ctx->r15 == 0) {
        // 0x80072FA4: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_80072FAC;
    }
    // 0x80072FA4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80072FA8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80072FAC:
    // 0x80072FAC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072FB0: bne         $t8, $zero, L_80072FD4
    if (ctx->r24 != 0) {
        // 0x80072FB4: sw          $t8, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r24;
            goto L_80072FD4;
    }
    // 0x80072FB4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80072FB8: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80072FBC: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80072FC0: lbu         $a1, 0x0($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X0);
    // 0x80072FC4: addiu       $t5, $a3, 0x1
    ctx->r13 = ADD32(ctx->r7, 0X1);
    // 0x80072FC8: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x80072FCC: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80072FD0: sw          $a1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r5;
L_80072FD4:
    // 0x80072FD4: and         $t7, $a1, $a2
    ctx->r15 = ctx->r5 & ctx->r6;
    // 0x80072FD8: beq         $t7, $zero, L_80072FE4
    if (ctx->r15 == 0) {
        // 0x80072FDC: srl         $t6, $v0, 1
        ctx->r14 = S32(U32(ctx->r2) >> 1);
            goto L_80072FE4;
    }
    // 0x80072FDC: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x80072FE0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80072FE4:
    // 0x80072FE4: srl         $t8, $a2, 1
    ctx->r24 = S32(U32(ctx->r6) >> 1);
    // 0x80072FE8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80072FEC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80072FF0: bne         $t8, $zero, L_80073014
    if (ctx->r24 != 0) {
        // 0x80072FF4: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80073014;
    }
    // 0x80072FF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072FF8: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80072FFC: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80073000: lbu         $a1, 0x0($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X0);
    // 0x80073004: addiu       $t5, $a3, 0x1
    ctx->r13 = ADD32(ctx->r7, 0X1);
    // 0x80073008: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8007300C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80073010: sw          $a1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r5;
L_80073014:
    // 0x80073014: and         $t7, $a1, $a2
    ctx->r15 = ctx->r5 & ctx->r6;
    // 0x80073018: beq         $t7, $zero, L_80073024
    if (ctx->r15 == 0) {
        // 0x8007301C: srl         $t6, $v0, 1
        ctx->r14 = S32(U32(ctx->r2) >> 1);
            goto L_80073024;
    }
    // 0x8007301C: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x80073020: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80073024:
    // 0x80073024: srl         $t8, $a2, 1
    ctx->r24 = S32(U32(ctx->r6) >> 1);
    // 0x80073028: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007302C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80073030: bne         $t8, $zero, L_80073054
    if (ctx->r24 != 0) {
        // 0x80073034: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80073054;
    }
    // 0x80073034: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073038: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x8007303C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80073040: lbu         $a1, 0x0($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X0);
    // 0x80073044: addiu       $t5, $a3, 0x1
    ctx->r13 = ADD32(ctx->r7, 0X1);
    // 0x80073048: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8007304C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80073050: sw          $a1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r5;
L_80073054:
    // 0x80073054: and         $t7, $a1, $a2
    ctx->r15 = ctx->r5 & ctx->r6;
    // 0x80073058: beq         $t7, $zero, L_80073064
    if (ctx->r15 == 0) {
        // 0x8007305C: srl         $t6, $v0, 1
        ctx->r14 = S32(U32(ctx->r2) >> 1);
            goto L_80073064;
    }
    // 0x8007305C: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x80073060: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80073064:
    // 0x80073064: srl         $t8, $a2, 1
    ctx->r24 = S32(U32(ctx->r6) >> 1);
    // 0x80073068: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007306C: bne         $a0, $zero, L_80072F68
    if (ctx->r4 != 0) {
        // 0x80073070: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80072F68;
    }
    // 0x80073070: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80073074:
    // 0x80073074: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80073078: jr          $ra
    // 0x8007307C: nop

    return;
    // 0x8007307C: nop

;}
RECOMP_FUNC void set_current_text_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5560: blez        $a0, L_800C55A8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C5564: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C55A8;
    }
    // 0x800C5564: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C5568: beq         $at, $zero, L_800C55A8
    if (ctx->r1 == 0) {
        // 0x800C556C: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C55A8;
    }
    // 0x800C556C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C5570: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5574: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C5578: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C557C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C5580: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5584: sb          $a1, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r5;
    // 0x800C5588: sb          $a2, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r6;
    // 0x800C558C: sb          $a3, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r7;
    // 0x800C5590: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800C5594: nop

    // 0x800C5598: sb          $t8, 0x17($v0)
    MEM_B(0X17, ctx->r2) = ctx->r24;
    // 0x800C559C: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800C55A0: nop

    // 0x800C55A4: sb          $t9, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r25;
L_800C55A8:
    // 0x800C55A8: jr          $ra
    // 0x800C55AC: nop

    return;
    // 0x800C55AC: nop

;}
RECOMP_FUNC void func_800230D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023104: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80023108: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002310C: lw          $v0, -0x4BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BB0);
    // 0x80023110: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80023114: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80023118: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002311C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80023120: bne         $v0, $zero, L_800231EC
    if (ctx->r2 != 0) {
        // 0x80023124: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800231EC;
    }
    // 0x80023124: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80023128: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8002312C: addiu       $a3, $a3, -0x4C24
    ctx->r7 = ADD32(ctx->r7, -0X4C24);
    // 0x80023130: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80023134: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80023138: blez        $a0, L_800231E4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8002313C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800231E4;
    }
    // 0x8002313C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80023140: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80023144: addiu       $a1, $a1, -0x4C28
    ctx->r5 = ADD32(ctx->r5, -0X4C28);
    // 0x80023148: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
L_8002314C:
    // 0x8002314C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80023150: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80023154: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80023158: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x8002315C: nop

    // 0x80023160: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x80023164: nop

    // 0x80023168: andi        $t1, $t9, 0x8000
    ctx->r9 = ctx->r25 & 0X8000;
    // 0x8002316C: bne         $t1, $zero, L_800231D0
    if (ctx->r9 != 0) {
        // 0x80023170: nop
    
            goto L_800231D0;
    }
    // 0x80023170: nop

    // 0x80023174: lh          $t2, 0x48($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X48);
    // 0x80023178: nop

    // 0x8002317C: bne         $a2, $t2, L_800231D0
    if (ctx->r6 != ctx->r10) {
        // 0x80023180: nop
    
            goto L_800231D0;
    }
    // 0x80023180: nop

    // 0x80023184: lw          $t3, 0x78($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X78);
    // 0x80023188: nop

    // 0x8002318C: bne         $t3, $zero, L_800231D4
    if (ctx->r11 != 0) {
        // 0x80023190: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800231D4;
    }
    // 0x80023190: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80023194: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80023198: nop

    // 0x8002319C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x800231A0: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800231A4: nop

    // 0x800231A8: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800231AC: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800231B0: nop

    // 0x800231B4: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x800231B8: lh          $t4, 0x2E($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2E);
    // 0x800231BC: nop

    // 0x800231C0: sh          $t4, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r12;
    // 0x800231C4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800231C8: nop

    // 0x800231CC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800231D0:
    // 0x800231D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800231D4:
    // 0x800231D4: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800231D8: bne         $at, $zero, L_8002314C
    if (ctx->r1 != 0) {
        // 0x800231DC: nop
    
            goto L_8002314C;
    }
    // 0x800231DC: nop

    // 0x800231E0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
L_800231E4:
    // 0x800231E4: b           L_80023260
    // 0x800231E8: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
        goto L_80023260;
    // 0x800231E8: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_800231EC:
    // 0x800231EC: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x800231F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800231F4: lw          $t6, -0x4BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BB4);
    // 0x800231F8: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x800231FC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80023200: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80023204: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x80023208: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002320C: lwc1        $f16, -0x34($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0X34);
    // 0x80023210: lwc1        $f10, -0x2C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, -0X2C);
    // 0x80023214: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80023218: addiu       $t0, $t0, -0x3C
    ctx->r8 = ADD32(ctx->r8, -0X3C);
    // 0x8002321C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80023220: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x80023224: lwc1        $f6, 0x14($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80023228: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8002322C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80023230: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80023234: lwc1        $f8, 0x18($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80023238: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8002323C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80023240: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80023244: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x80023248: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8002324C: jal         0x80029F58
    // 0x80023250: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_0;
    // 0x80023250: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80023254: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80023258: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // 0x8002325C: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_80023260:
    // 0x80023260: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80023264: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80023268: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8002326C: jal         0x8002BAF0
    // 0x80023270: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    collision_get_y(rdram, ctx);
        goto after_1;
    // 0x80023270: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x80023274: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80023278: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8002327C: beq         $v0, $zero, L_80023294
    if (ctx->r2 == 0) {
        // 0x80023280: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80023294;
    }
    // 0x80023280: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80023284: addu        $t8, $sp, $t7
    ctx->r24 = ADD32(ctx->r29, ctx->r15);
    // 0x80023288: lwc1        $f4, 0x2C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X2C);
    // 0x8002328C: nop

    // 0x80023290: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_80023294:
    // 0x80023294: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023298: nop

    // 0x8002329C: swc1        $f6, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f6.u32l;
    // 0x800232A0: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800232A4: nop

    // 0x800232A8: swc1        $f16, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f16.u32l;
    // 0x800232AC: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800232B0: beq         $t0, $zero, L_800232D4
    if (ctx->r8 == 0) {
        // 0x800232B4: swc1        $f8, 0x64($s1)
        MEM_W(0X64, ctx->r17) = ctx->f8.u32l;
            goto L_800232D4;
    }
    // 0x800232B4: swc1        $f8, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->f8.u32l;
    // 0x800232B8: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800232BC: lwc1        $f14, 0x8($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800232C0: jal         0x80070990
    // 0x800232C4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x800232C4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800232C8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800232CC: b           L_800232E0
    // 0x800232D0: sh          $v0, 0x1A0($s1)
    MEM_H(0X1A0, ctx->r17) = ctx->r2;
        goto L_800232E0;
    // 0x800232D0: sh          $v0, 0x1A0($s1)
    MEM_H(0X1A0, ctx->r17) = ctx->r2;
L_800232D4:
    // 0x800232D4: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x800232D8: nop

    // 0x800232DC: sh          $t9, 0x1A0($s1)
    MEM_H(0X1A0, ctx->r17) = ctx->r25;
L_800232E0:
    // 0x800232E0: sb          $zero, 0x192($s1)
    MEM_B(0X192, ctx->r17) = 0;
    // 0x800232E4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800232E8: lw          $t2, -0x4BB0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4BB0);
    // 0x800232EC: lb          $t1, 0x193($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X193);
    // 0x800232F0: lh          $t4, 0x1A0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X1A0);
    // 0x800232F4: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800232F8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800232FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80023300: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80023304: mflo        $t3
    ctx->r11 = lo;
    // 0x80023308: sh          $t3, 0x190($s1)
    MEM_H(0X190, ctx->r17) = ctx->r11;
    // 0x8002330C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023310: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x80023314: swc1        $f10, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f10.u32l;
    // 0x80023318: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8002331C: nop

    // 0x80023320: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80023324: swc1        $f4, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f4.u32l;
    // 0x80023328: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002332C: nop

    // 0x80023330: swc1        $f6, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f6.u32l;
    // 0x80023334: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023338: nop

    // 0x8002333C: swc1        $f16, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f16.u32l;
    // 0x80023340: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80023344: nop

    // 0x80023348: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8002334C: swc1        $f10, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f10.u32l;
    // 0x80023350: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80023354: nop

    // 0x80023358: swc1        $f18, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f18.u32l;
    // 0x8002335C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023360: nop

    // 0x80023364: swc1        $f4, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f4.u32l;
    // 0x80023368: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8002336C: nop

    // 0x80023370: add.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80023374: swc1        $f16, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f16.u32l;
    // 0x80023378: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002337C: nop

    // 0x80023380: swc1        $f8, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f8.u32l;
    // 0x80023384: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023388: nop

    // 0x8002338C: swc1        $f10, 0xFC($s1)
    MEM_W(0XFC, ctx->r17) = ctx->f10.u32l;
    // 0x80023390: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80023394: nop

    // 0x80023398: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8002339C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800233A0: swc1        $f4, 0x100($s1)
    MEM_W(0X100, ctx->r17) = ctx->f4.u32l;
    // 0x800233A4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800233A8: nop

    // 0x800233AC: swc1        $f6, 0x104($s1)
    MEM_W(0X104, ctx->r17) = ctx->f6.u32l;
    // 0x800233B0: lw          $t5, 0x4C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4C);
    // 0x800233B4: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800233B8: nop

    // 0x800233BC: swc1        $f16, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f16.u32l;
    // 0x800233C0: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x800233C4: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800233C8: nop

    // 0x800233CC: swc1        $f8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f8.u32l;
    // 0x800233D0: lw          $t7, 0x4C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4C);
    // 0x800233D4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800233D8: nop

    // 0x800233DC: swc1        $f10, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f10.u32l;
    // 0x800233E0: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x800233E4: swc1        $f0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f0.u32l;
    // 0x800233E8: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800233EC: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800233F0: lb          $t8, 0x1D7($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X1D7);
    // 0x800233F4: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x800233F8: sb          $t8, 0x1D6($s1)
    MEM_B(0X1D6, ctx->r17) = ctx->r24;
    // 0x800233FC: beq         $a0, $at, L_8002343C
    if (ctx->r4 == ctx->r1) {
        // 0x80023400: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8002343C;
    }
    // 0x80023400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80023404: jal         0x80066828
    // 0x80023408: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    set_active_camera(rdram, ctx);
        goto after_3;
    // 0x80023408: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_3:
    // 0x8002340C: jal         0x80069F3C
    // 0x80023410: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_4;
    // 0x80023410: nop

    after_4:
    // 0x80023414: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023418: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8002341C: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x80023420: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80023424: nop

    // 0x80023428: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x8002342C: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80023430: nop

    // 0x80023434: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x80023438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002343C:
    // 0x8002343C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80023440: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80023444: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80023448: jr          $ra
    // 0x8002344C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x8002344C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void alCSPGetFadeIn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063E40: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80063E44: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80063E48: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80063E4C: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x80063E50: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80063E54: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80063E58: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80063E5C: lbu         $v0, 0x10($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X10);
    // 0x80063E60: jr          $ra
    // 0x80063E64: nop

    return;
    // 0x80063E64: nop

;}
RECOMP_FUNC void sound_volume_change(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000096C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80000970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000974: beq         $a0, $at, L_8000099C
    if (ctx->r4 == ctx->r1) {
        // 0x80000978: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8000099C;
    }
    // 0x80000978: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000097C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80000980: beq         $a0, $at, L_80000A14
    if (ctx->r4 == ctx->r1) {
        // 0x80000984: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80000A14;
    }
    // 0x80000984: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80000988: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000098C: beq         $a0, $at, L_80000A48
    if (ctx->r4 == ctx->r1) {
        // 0x80000990: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80000A48;
    }
    // 0x80000990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80000994: b           L_80000A7C
    // 0x80000998: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80000A7C;
    // 0x80000998: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000099C:
    // 0x8000099C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800009A0: jal         0x80004A60
    // 0x800009A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_0;
    // 0x800009A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800009A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800009AC: jal         0x80004A60
    // 0x800009B0: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_1;
    // 0x800009B0: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_1:
    // 0x800009B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800009B8: jal         0x80004A60
    // 0x800009BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_2;
    // 0x800009BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800009C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800009C4: jal         0x80004A60
    // 0x800009C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_3;
    // 0x800009C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800009CC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800009D0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800009D4: lw          $t8, -0x343C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X343C);
    // 0x800009D8: lbu         $t7, -0x3458($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3458);
    // 0x800009DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800009E0: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800009E4: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x800009E8: mflo        $a1
    ctx->r5 = lo;
    // 0x800009EC: sra         $t9, $a1, 2
    ctx->r25 = S32(SIGNED(ctx->r5) >> 2);
    // 0x800009F0: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x800009F4: jal         0x800C7DB0
    // 0x800009F8: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_4;
    // 0x800009F8: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    after_4:
    // 0x800009FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000A00: lw          $a0, -0x345C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X345C);
    // 0x80000A04: jal         0x800C7DB0
    // 0x80000A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alCSPSetVol(rdram, ctx);
        goto after_5;
    // 0x80000A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80000A0C: b           L_80000B04
    // 0x80000A10: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
        goto L_80000B04;
    // 0x80000A10: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80000A14:
    // 0x80000A14: jal         0x80004A60
    // 0x80000A18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_6;
    // 0x80000A18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80000A1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80000A20: jal         0x80004A60
    // 0x80000A24: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_7;
    // 0x80000A24: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_7:
    // 0x80000A28: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80000A2C: jal         0x80004A60
    // 0x80000A30: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_8;
    // 0x80000A30: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_8:
    // 0x80000A34: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80000A38: jal         0x80004A60
    // 0x80000A3C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_9;
    // 0x80000A3C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_9:
    // 0x80000A40: b           L_80000B04
    // 0x80000A44: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
        goto L_80000B04;
    // 0x80000A44: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80000A48:
    // 0x80000A48: jal         0x80004A60
    // 0x80000A4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_10;
    // 0x80000A4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80000A50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80000A54: jal         0x80004A60
    // 0x80000A58: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_11;
    // 0x80000A58: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_11:
    // 0x80000A5C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80000A60: jal         0x80004A60
    // 0x80000A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_12;
    // 0x80000A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80000A68: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80000A6C: jal         0x80004A60
    // 0x80000A70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_13;
    // 0x80000A70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80000A74: b           L_80000B04
    // 0x80000A78: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
        goto L_80000B04;
    // 0x80000A78: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80000A7C:
    // 0x80000A7C: jal         0x80004A60
    // 0x80000A80: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_14;
    // 0x80000A80: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_14:
    // 0x80000A84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80000A88: jal         0x80004A60
    // 0x80000A8C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_15;
    // 0x80000A8C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_15:
    // 0x80000A90: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80000A94: jal         0x80004A60
    // 0x80000A98: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_16;
    // 0x80000A98: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_16:
    // 0x80000A9C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80000AA0: jal         0x80004A60
    // 0x80000AA4: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_17;
    // 0x80000AA4: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_17:
    // 0x80000AA8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80000AAC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80000AB0: lw          $t3, -0x343C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X343C);
    // 0x80000AB4: lbu         $t2, -0x3458($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X3458);
    // 0x80000AB8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000ABC: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80000AC0: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80000AC4: mflo        $a1
    ctx->r5 = lo;
    // 0x80000AC8: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80000ACC: jal         0x800C7DB0
    // 0x80000AD0: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_18;
    // 0x80000AD0: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_18:
    // 0x80000AD4: jal         0x8000317C
    // 0x80000AD8: nop

    sndp_get_global_volume(rdram, ctx);
        goto after_19;
    // 0x80000AD8: nop

    after_19:
    // 0x80000ADC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80000AE0: lbu         $t6, -0x3454($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3454);
    // 0x80000AE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000AE8: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80000AEC: lw          $a0, -0x345C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X345C);
    // 0x80000AF0: mflo        $a1
    ctx->r5 = lo;
    // 0x80000AF4: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80000AF8: jal         0x800C7DB0
    // 0x80000AFC: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_20;
    // 0x80000AFC: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    after_20:
    // 0x80000B00: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80000B04:
    // 0x80000B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000B08: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000B10: jr          $ra
    // 0x80000B14: sb          $t9, 0x64F9($at)
    MEM_B(0X64F9, ctx->r1) = ctx->r25;
    return;
    // 0x80000B14: sb          $t9, 0x64F9($at)
    MEM_B(0X64F9, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void asset_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077190: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077194: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80077198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007719C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800771A0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800771A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800771A8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800771AC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800771B0: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x800771B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800771B8: jal         0x800C9110
    // 0x800771BC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800771BC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800771C0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800771C4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800771C8: beq         $a2, $zero, L_800771EC
    if (ctx->r6 == 0) {
        // 0x800771CC: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_800771EC;
    }
    // 0x800771CC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800771D0: lw          $a3, 0x4830($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4830);
    // 0x800771D4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800771D8: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800771DC: lui         $t1, 0xF
    ctx->r9 = S32(0XF << 16);
    // 0x800771E0: sltu        $at, $t6, $t0
    ctx->r1 = ctx->r14 < ctx->r8 ? 1 : 0;
    // 0x800771E4: beq         $at, $zero, L_800771F4
    if (ctx->r1 == 0) {
        // 0x800771E8: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800771F4;
    }
    // 0x800771E8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800771EC:
    // 0x800771EC: b           L_80077230
    // 0x800771F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80077230;
    // 0x800771F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800771F4:
    // 0x800771F4: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800771F8: addu        $v0, $t7, $a3
    ctx->r2 = ADD32(ctx->r15, ctx->r7);
    // 0x800771FC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80077200: addiu       $t1, $t1, -0x2E50
    ctx->r9 = ADD32(ctx->r9, -0X2E50);
    // 0x80077204: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80077208: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8007720C: jal         0x800773D4
    // 0x80077210: addu        $a0, $v1, $t1
    ctx->r4 = ADD32(ctx->r3, ctx->r9);
    dmacopy_v1(rdram, ctx);
        goto after_1;
    // 0x80077210: addu        $a0, $v1, $t1
    ctx->r4 = ADD32(ctx->r3, ctx->r9);
    after_1:
    // 0x80077214: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077218: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x8007721C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80077220: jal         0x800C9390
    // 0x80077224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80077224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80077228: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8007722C: nop

L_80077230:
    // 0x80077230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077234: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80077238: jr          $ra
    // 0x8007723C: nop

    return;
    // 0x8007723C: nop

;}
RECOMP_FUNC void racerfx_get_boost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BF44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000BF48: bne         $a0, $at, L_8000BF5C
    if (ctx->r4 != ctx->r1) {
        // 0x8000BF4C: nop
    
            goto L_8000BF5C;
    }
    // 0x8000BF4C: nop

    // 0x8000BF50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000BF54: lw          $a0, -0x3330($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3330);
    // 0x8000BF58: nop

L_8000BF5C:
    // 0x8000BF5C: bltz        $a0, L_8000BF6C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8000BF60: slti        $at, $a0, 0xA
        ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
            goto L_8000BF6C;
    }
    // 0x8000BF60: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x8000BF64: bne         $at, $zero, L_8000BF74
    if (ctx->r1 != 0) {
        // 0x8000BF68: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8000BF74;
    }
    // 0x8000BF68: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
L_8000BF6C:
    // 0x8000BF6C: jr          $ra
    // 0x8000BF70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000BF70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000BF74:
    // 0x8000BF74: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000BF78: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8000BF7C: lw          $v0, -0x4A60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4A60);
    // 0x8000BF80: nop

    // 0x8000BF84: jr          $ra
    // 0x8000BF88: nop

    return;
    // 0x8000BF88: nop

;}
RECOMP_FUNC void sound_table_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002128: beq         $a0, $zero, L_8000213C
    if (ctx->r4 == 0) {
        // 0x8000212C: lui         $t6, 0x8011
        ctx->r14 = S32(0X8011 << 16);
            goto L_8000213C;
    }
    // 0x8000212C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80002130: lw          $t6, 0x6298($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6298);
    // 0x80002134: nop

    // 0x80002138: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_8000213C:
    // 0x8000213C: beq         $a1, $zero, L_80002150
    if (ctx->r5 == 0) {
        // 0x80002140: lui         $t7, 0x8011
        ctx->r15 = S32(0X8011 << 16);
            goto L_80002150;
    }
    // 0x80002140: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80002144: lw          $t7, 0x62A8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X62A8);
    // 0x80002148: nop

    // 0x8000214C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_80002150:
    // 0x80002150: beq         $a2, $zero, L_80002164
    if (ctx->r6 == 0) {
        // 0x80002154: lui         $t8, 0x8011
        ctx->r24 = S32(0X8011 << 16);
            goto L_80002164;
    }
    // 0x80002154: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80002158: lw          $t8, 0x62A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X62A0);
    // 0x8000215C: nop

    // 0x80002160: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_80002164:
    // 0x80002164: jr          $ra
    // 0x80002168: nop

    return;
    // 0x80002168: nop

;}
