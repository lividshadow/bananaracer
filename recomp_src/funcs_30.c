#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void alFxNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064C48: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80064C4C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80064C50: sll         $s0, $a2, 16
    ctx->r16 = S32(ctx->r6 << 16);
    // 0x80064C54: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80064C58: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80064C5C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80064C60: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80064C64: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80064C68: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80064C6C: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80064C70: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80064C74: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80064C78: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80064C7C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80064C80: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80064C84: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80064C88: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80064C8C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80064C90: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80064C94: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80064C98: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80064C9C: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80064CA0: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80064CA4: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80064CA8: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80064CAC: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80064CB0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80064CB4: addiu       $a2, $a2, 0x41D4
    ctx->r6 = ADD32(ctx->r6, 0X41D4);
    // 0x80064CB8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80064CBC: jal         0x800CA610
    // 0x80064CC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80064CC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80064CC4: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80064CC8: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80064CCC: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80064CD0: addiu       $t7, $t7, 0x3E70
    ctx->r15 = ADD32(ctx->r15, 0X3E70);
    // 0x80064CD4: addiu       $t8, $t8, 0x41EC
    ctx->r24 = ADD32(ctx->r24, 0X41EC);
    // 0x80064CD8: sw          $t7, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r15;
    // 0x80064CDC: sw          $t8, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r24;
    // 0x80064CE0: addu        $t9, $v0, $s0
    ctx->r25 = ADD32(ctx->r2, ctx->r16);
    // 0x80064CE4: lbu         $t0, 0x1C($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1C);
    // 0x80064CE8: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064CEC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80064CF0: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x80064CF4: beq         $at, $zero, L_80064D68
    if (ctx->r1 == 0) {
        // 0x80064CF8: addiu       $s3, $s3, -0x2A68
        ctx->r19 = ADD32(ctx->r19, -0X2A68);
            goto L_80064D68;
    }
    // 0x80064CF8: addiu       $s3, $s3, -0x2A68
    ctx->r19 = ADD32(ctx->r19, -0X2A68);
    // 0x80064CFC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80064D00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80064D04: addu        $at, $at, $t1
    gpr jr_addend_80064D10 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80064D08: lw          $t1, 0x7430($at)
    ctx->r9 = ADD32(ctx->r1, 0X7430);
    // 0x80064D0C: nop

    // 0x80064D10: jr          $t1
    // 0x80064D14: nop

    switch (jr_addend_80064D10 >> 2) {
        case 0: goto L_80064D18; break;
        case 1: goto L_80064D24; break;
        case 2: goto L_80064D3C; break;
        case 3: goto L_80064D48; break;
        case 4: goto L_80064D30; break;
        case 5: goto L_80064D54; break;
        default: switch_error(__func__, 0x80064D10, 0x800E7430);
    }
    // 0x80064D14: nop

L_80064D18:
    // 0x80064D18: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064D1C: b           L_80064D68
    // 0x80064D20: addiu       $s3, $s3, -0x2BD0
    ctx->r19 = ADD32(ctx->r19, -0X2BD0);
        goto L_80064D68;
    // 0x80064D20: addiu       $s3, $s3, -0x2BD0
    ctx->r19 = ADD32(ctx->r19, -0X2BD0);
L_80064D24:
    // 0x80064D24: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064D28: b           L_80064D68
    // 0x80064D2C: addiu       $s3, $s3, -0x2B68
    ctx->r19 = ADD32(ctx->r19, -0X2B68);
        goto L_80064D68;
    // 0x80064D2C: addiu       $s3, $s3, -0x2B68
    ctx->r19 = ADD32(ctx->r19, -0X2B68);
L_80064D30:
    // 0x80064D30: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064D34: b           L_80064D68
    // 0x80064D38: addiu       $s3, $s3, -0x2AE0
    ctx->r19 = ADD32(ctx->r19, -0X2AE0);
        goto L_80064D68;
    // 0x80064D38: addiu       $s3, $s3, -0x2AE0
    ctx->r19 = ADD32(ctx->r19, -0X2AE0);
L_80064D3C:
    // 0x80064D3C: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064D40: b           L_80064D68
    // 0x80064D44: addiu       $s3, $s3, -0x2AB8
    ctx->r19 = ADD32(ctx->r19, -0X2AB8);
        goto L_80064D68;
    // 0x80064D44: addiu       $s3, $s3, -0x2AB8
    ctx->r19 = ADD32(ctx->r19, -0X2AB8);
L_80064D48:
    // 0x80064D48: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064D4C: b           L_80064D68
    // 0x80064D50: addiu       $s3, $s3, -0x2A90
    ctx->r19 = ADD32(ctx->r19, -0X2A90);
        goto L_80064D68;
    // 0x80064D50: addiu       $s3, $s3, -0x2A90
    ctx->r19 = ADD32(ctx->r19, -0X2A90);
L_80064D54:
    // 0x80064D54: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80064D58: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80064D5C: lw          $s3, 0x20($t3)
    ctx->r19 = MEM_W(ctx->r11, 0X20);
    // 0x80064D60: b           L_80064D6C
    // 0x80064D64: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
        goto L_80064D6C;
    // 0x80064D64: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
L_80064D68:
    // 0x80064D68: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
L_80064D6C:
    // 0x80064D6C: addiu       $fp, $zero, 0x28
    ctx->r30 = ADD32(0, 0X28);
    // 0x80064D70: andi        $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 & 0XFF;
    // 0x80064D74: multu       $t6, $fp
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064D78: sb          $t4, 0x24($s6)
    MEM_B(0X24, ctx->r22) = ctx->r12;
    // 0x80064D7C: lw          $t5, 0x4($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X4);
    // 0x80064D80: lui         $s5, 0xFF
    ctx->r21 = S32(0XFF << 16);
    // 0x80064D84: ori         $s5, $s5, 0xFFFF
    ctx->r21 = ctx->r21 | 0XFFFF;
    // 0x80064D88: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80064D8C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80064D90: sw          $t5, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->r13;
    // 0x80064D94: mflo        $a0
    ctx->r4 = lo;
    // 0x80064D98: jal         0x80070EDC
    // 0x80064D9C: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80064D9C: nop

    after_1:
    // 0x80064DA0: lw          $a0, 0x1C($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X1C);
    // 0x80064DA4: sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // 0x80064DA8: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80064DAC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80064DB0: jal         0x80070EDC
    // 0x80064DB4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x80064DB4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_2:
    // 0x80064DB8: lw          $t8, 0x1C($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X1C);
    // 0x80064DBC: sw          $v0, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->r2;
    // 0x80064DC0: sw          $v0, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r2;
    // 0x80064DC4: beq         $t8, $zero, L_80064DF4
    if (ctx->r24 == 0) {
        // 0x80064DC8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80064DF4;
    }
    // 0x80064DC8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80064DCC:
    // 0x80064DCC: lw          $t9, 0x14($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X14);
    // 0x80064DD0: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x80064DD4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80064DD8: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x80064DDC: lw          $t3, 0x1C($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X1C);
    // 0x80064DE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80064DE4: andi        $t2, $v1, 0xFFFF
    ctx->r10 = ctx->r3 & 0XFFFF;
    // 0x80064DE8: sltu        $at, $t2, $t3
    ctx->r1 = ctx->r10 < ctx->r11 ? 1 : 0;
    // 0x80064DEC: bne         $at, $zero, L_80064DCC
    if (ctx->r1 != 0) {
        // 0x80064DF0: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_80064DCC;
    }
    // 0x80064DF0: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_80064DF4:
    // 0x80064DF4: lbu         $t4, 0x24($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X24);
    // 0x80064DF8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80064DFC: blez        $t4, L_80065044
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80064E00: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80065044;
    }
    // 0x80064E00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80064E04: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80064E08: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80064E0C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80064E10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80064E14: lwc1        $f21, 0x7448($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, 0X7448);
    // 0x80064E18: lwc1        $f20, 0x744C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X744C);
    // 0x80064E1C: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80064E20: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_80064E24:
    // 0x80064E24: multu       $s4, $fp
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064E28: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80064E2C: lw          $t5, 0x20($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X20);
    // 0x80064E30: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x80064E34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80064E38: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80064E3C: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x80064E40: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80064E44: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x80064E48: addiu       $s1, $t0, 0x1
    ctx->r17 = ADD32(ctx->r8, 0X1);
    // 0x80064E4C: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x80064E50: addiu       $s1, $t4, 0x1
    ctx->r17 = ADD32(ctx->r12, 0X1);
    // 0x80064E54: mflo        $t6
    ctx->r14 = lo;
    // 0x80064E58: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    // 0x80064E5C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80064E60: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80064E64: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80064E68: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x80064E6C: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x80064E70: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80064E74: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x80064E78: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80064E7C: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x80064E80: addiu       $s1, $t8, 0x1
    ctx->r17 = ADD32(ctx->r24, 0X1);
    // 0x80064E84: sh          $t7, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r15;
    // 0x80064E88: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80064E8C: andi        $t2, $s1, 0xFFFF
    ctx->r10 = ctx->r17 & 0XFFFF;
    // 0x80064E90: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80064E94: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x80064E98: addiu       $s1, $t2, 0x1
    ctx->r17 = ADD32(ctx->r10, 0X1);
    // 0x80064E9C: sh          $t1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r9;
    // 0x80064EA0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80064EA4: andi        $t6, $s1, 0xFFFF
    ctx->r14 = ctx->r17 & 0XFFFF;
    // 0x80064EA8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80064EAC: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x80064EB0: sh          $t5, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r13;
    // 0x80064EB4: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80064EB8: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80064EBC: beq         $v0, $zero, L_80064FAC
    if (ctx->r2 == 0) {
        // 0x80064EC0: or          $t2, $s1, $zero
        ctx->r10 = ctx->r17 | 0;
            goto L_80064FAC;
    }
    // 0x80064EC0: or          $t2, $s1, $zero
    ctx->r10 = ctx->r17 | 0;
    // 0x80064EC4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80064EC8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80064ECC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80064ED0: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x80064ED4: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80064ED8: div.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80064EDC: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80064EE0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80064EE4: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80064EE8: addiu       $s1, $t6, 0x1
    ctx->r17 = ADD32(ctx->r14, 0X1);
    // 0x80064EEC: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x80064EF0: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80064EF4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x80064EF8: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80064EFC: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x80064F00: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80064F04: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80064F08: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x80064F0C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80064F10: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x80064F14: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x80064F18: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80064F1C: bgez        $t4, L_80064F34
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80064F20: swc1        $f6, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
            goto L_80064F34;
    }
    // 0x80064F20: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80064F24: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80064F28: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80064F2C: nop

    // 0x80064F30: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_80064F34:
    // 0x80064F34: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80064F38: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80064F3C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80064F40: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x80064F44: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80064F48: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x80064F4C: swc1        $f24, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f24.u32l;
    // 0x80064F50: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80064F54: nop

    // 0x80064F58: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80064F5C: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80064F60: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    // 0x80064F64: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80064F68: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80064F6C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80064F70: jal         0x80070EDC
    // 0x80064F74: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80064F74: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x80064F78: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x80064F7C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80064F80: jal         0x80070EDC
    // 0x80064F84: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x80064F84: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_4:
    // 0x80064F88: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80064F8C: nop

    // 0x80064F90: sw          $v0, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r2;
    // 0x80064F94: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x80064F98: nop

    // 0x80064F9C: swc1        $f26, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f26.u32l;
    // 0x80064FA0: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80064FA4: b           L_80064FBC
    // 0x80064FA8: sw          $s7, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r23;
        goto L_80064FBC;
    // 0x80064FA8: sw          $s7, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r23;
L_80064FAC:
    // 0x80064FAC: addiu       $s1, $t2, 0x2
    ctx->r17 = ADD32(ctx->r10, 0X2);
    // 0x80064FB0: andi        $t3, $s1, 0xFFFF
    ctx->r11 = ctx->r17 & 0XFFFF;
    // 0x80064FB4: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80064FB8: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
L_80064FBC:
    // 0x80064FBC: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80064FC0: addu        $s2, $s3, $t4
    ctx->r18 = ADD32(ctx->r19, ctx->r12);
    // 0x80064FC4: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80064FC8: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80064FCC: beq         $t5, $zero, L_8006501C
    if (ctx->r13 == 0) {
        // 0x80064FD0: nop
    
            goto L_8006501C;
    }
    // 0x80064FD0: nop

    // 0x80064FD4: jal         0x80070EDC
    // 0x80064FD8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x80064FD8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_5:
    // 0x80064FDC: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80064FE0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80064FE4: jal         0x80070EDC
    // 0x80064FE8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x80064FE8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_6:
    // 0x80064FEC: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80064FF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80064FF4: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    // 0x80064FF8: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x80064FFC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80065000: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x80065004: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x80065008: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x8006500C: jal         0x80064B90
    // 0x80065010: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    init_lpfilter(rdram, ctx);
        goto after_7;
    // 0x80065010: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    after_7:
    // 0x80065014: b           L_80065030
    // 0x80065018: lbu         $t2, 0x24($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X24);
        goto L_80065030;
    // 0x80065018: lbu         $t2, 0x24($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X24);
L_8006501C:
    // 0x8006501C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80065020: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x80065024: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80065028: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x8006502C: lbu         $t2, 0x24($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X24);
L_80065030:
    // 0x80065030: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80065034: andi        $t1, $s4, 0xFFFF
    ctx->r9 = ctx->r20 & 0XFFFF;
    // 0x80065038: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8006503C: bne         $at, $zero, L_80064E24
    if (ctx->r1 != 0) {
        // 0x80065040: or          $s4, $t1, $zero
        ctx->r20 = ctx->r9 | 0;
            goto L_80064E24;
    }
    // 0x80065040: or          $s4, $t1, $zero
    ctx->r20 = ctx->r9 | 0;
L_80065044:
    // 0x80065044: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80065048: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8006504C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80065050: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80065054: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80065058: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8006505C: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80065060: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80065064: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80065068: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8006506C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80065070: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80065074: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80065078: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8006507C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80065080: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80065084: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80065088: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8006508C: jr          $ra
    // 0x80065090: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80065090: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void bgload_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C79A8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C79AC: lw          $v0, 0x3D0C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3D0C);
    // 0x800C79B0: jr          $ra
    // 0x800C79B4: nop

    return;
    // 0x800C79B4: nop

;}
RECOMP_FUNC void compute_grid_overlap_mask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003151C: beq         $a0, $zero, L_80031638
    if (ctx->r4 == 0) {
        // 0x80031520: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80031638;
    }
    // 0x80031520: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80031524: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x80031528: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x8003152C: lh          $t1, 0x4($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X4);
    // 0x80031530: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80031534: lh          $t2, 0x6($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X6);
    // 0x80031538: beq         $at, $zero, L_80031544
    if (ctx->r1 == 0) {
        // 0x8003153C: lh          $t3, 0xA($a0)
        ctx->r11 = MEM_H(ctx->r4, 0XA);
            goto L_80031544;
    }
    // 0x8003153C: lh          $t3, 0xA($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XA);
    // 0x80031540: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
L_80031544:
    // 0x80031544: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80031548: beql        $at, $zero, L_80031558
    if (ctx->r1 == 0) {
        // 0x8003154C: slt         $at, $t5, $t1
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80031558;
    }
    goto skip_0;
    // 0x8003154C: slt         $at, $t5, $t1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r9) ? 1 : 0;
    skip_0:
    // 0x80031550: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x80031554: slt         $at, $t5, $t1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r9) ? 1 : 0;
L_80031558:
    // 0x80031558: beql        $at, $zero, L_80031568
    if (ctx->r1 == 0) {
        // 0x8003155C: slt         $at, $a2, $t1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80031568;
    }
    goto skip_1;
    // 0x8003155C: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    skip_1:
    // 0x80031560: or          $t5, $t1, $zero
    ctx->r13 = ctx->r9 | 0;
    // 0x80031564: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
L_80031568:
    // 0x80031568: beql        $at, $zero, L_80031578
    if (ctx->r1 == 0) {
        // 0x8003156C: slt         $at, $t2, $a3
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80031578;
    }
    goto skip_2;
    // 0x8003156C: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    skip_2:
    // 0x80031570: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80031574: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
L_80031578:
    // 0x80031578: beql        $at, $zero, L_80031588
    if (ctx->r1 == 0) {
        // 0x8003157C: slt         $at, $t2, $a1
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80031588;
    }
    goto skip_3;
    // 0x8003157C: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
    skip_3:
    // 0x80031580: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x80031584: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
L_80031588:
    // 0x80031588: beql        $at, $zero, L_80031598
    if (ctx->r1 == 0) {
        // 0x8003158C: slt         $at, $t3, $t5
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
            goto L_80031598;
    }
    goto skip_4;
    // 0x8003158C: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    skip_4:
    // 0x80031590: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80031594: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
L_80031598:
    // 0x80031598: beql        $at, $zero, L_800315A8
    if (ctx->r1 == 0) {
        // 0x8003159C: slt         $at, $t3, $a2
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800315A8;
    }
    goto skip_5;
    // 0x8003159C: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    skip_5:
    // 0x800315A0: or          $t5, $t3, $zero
    ctx->r13 = ctx->r11 | 0;
    // 0x800315A4: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
L_800315A8:
    // 0x800315A8: beql        $at, $zero, L_800315B8
    if (ctx->r1 == 0) {
        // 0x800315AC: sub         $t2, $t2, $t0
        ctx->r10 = SUB32(ctx->r10, ctx->r8);
            goto L_800315B8;
    }
    goto skip_6;
    // 0x800315AC: sub         $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    skip_6:
    // 0x800315B0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x800315B4: sub         $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
L_800315B8:
    // 0x800315B8: sra         $t2, $t2, 3
    ctx->r10 = S32(SIGNED(ctx->r10) >> 3);
    // 0x800315BC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800315C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800315C4: add         $t4, $t2, $t0
    ctx->r12 = ADD32(ctx->r10, ctx->r8);
L_800315C8:
    // 0x800315C8: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800315CC: bne         $at, $zero, L_800315E0
    if (ctx->r1 != 0) {
        // 0x800315D0: slt         $at, $a3, $t0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800315E0;
    }
    // 0x800315D0: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800315D4: bnel        $at, $zero, L_800315E4
    if (ctx->r1 != 0) {
        // 0x800315D8: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_800315E4;
    }
    goto skip_7;
    // 0x800315D8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    skip_7:
    // 0x800315DC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_800315E0:
    // 0x800315E0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_800315E4:
    // 0x800315E4: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800315E8: add         $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800315EC: bne         $at, $zero, L_800315C8
    if (ctx->r1 != 0) {
        // 0x800315F0: add         $t0, $t0, $t2
        ctx->r8 = ADD32(ctx->r8, ctx->r10);
            goto L_800315C8;
    }
    // 0x800315F0: add         $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x800315F4: sub         $t2, $t3, $t1
    ctx->r10 = SUB32(ctx->r11, ctx->r9);
    // 0x800315F8: sra         $t2, $t2, 3
    ctx->r10 = S32(SIGNED(ctx->r10) >> 3);
    // 0x800315FC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80031600: add         $t4, $t2, $t1
    ctx->r12 = ADD32(ctx->r10, ctx->r9);
    // 0x80031604: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
L_80031608:
    // 0x80031608: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8003160C: bne         $at, $zero, L_80031620
    if (ctx->r1 != 0) {
        // 0x80031610: slt         $at, $t5, $t0
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80031620;
    }
    // 0x80031610: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80031614: bnel        $at, $zero, L_80031624
    if (ctx->r1 != 0) {
        // 0x80031618: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_80031624;
    }
    goto skip_8;
    // 0x80031618: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    skip_8:
    // 0x8003161C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_80031620:
    // 0x80031620: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_80031624:
    // 0x80031624: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80031628: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8003162C: add         $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x80031630: bne         $at, $zero, L_80031608
    if (ctx->r1 != 0) {
        // 0x80031634: add         $t0, $t0, $t2
        ctx->r8 = ADD32(ctx->r8, ctx->r10);
            goto L_80031608;
    }
    // 0x80031634: add         $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
L_80031638:
    // 0x80031638: jr          $ra
    // 0x8003163C: nop

    return;
    // 0x8003163C: nop

;}
RECOMP_FUNC void rumble_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072594: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80072598: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8007259C: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x800725A0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800725A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800725A8: slti        $at, $t8, 0x13
    ctx->r1 = SIGNED(ctx->r24) < 0X13 ? 1 : 0;
    // 0x800725AC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800725B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800725B4: beq         $at, $zero, L_80072660
    if (ctx->r1 == 0) {
        // 0x800725B8: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80072660;
    }
    // 0x800725B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800725BC: bltz        $t7, L_80072660
    if (SIGNED(ctx->r15) < 0) {
        // 0x800725C0: slti        $at, $t7, 0x4
        ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
            goto L_80072660;
    }
    // 0x800725C0: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800725C4: beq         $at, $zero, L_80072664
    if (ctx->r1 == 0) {
        // 0x800725C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80072664;
    }
    // 0x800725C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800725CC: sh          $t7, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r15;
    // 0x800725D0: jal         0x80072490
    // 0x800725D4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    input_get_id(rdram, ctx);
        goto after_0;
    // 0x800725D4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x800725D8: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x800725DC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800725E0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800725E4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800725E8: addiu       $t1, $t1, 0x4738
    ctx->r9 = ADD32(ctx->r9, 0X4738);
    // 0x800725EC: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800725F0: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x800725F4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800725F8: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800725FC: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    // 0x80072600: bne         $a2, $t2, L_80072634
    if (ctx->r6 != ctx->r10) {
        // 0x80072604: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80072634;
    }
    // 0x80072604: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80072608: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    // 0x8007260C: addiu       $t4, $zero, -0x12C
    ctx->r12 = ADD32(0, -0X12C);
    // 0x80072610: bgez        $t3, L_8007261C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80072614: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8007261C;
    }
    // 0x80072614: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80072618: sh          $t4, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r12;
L_8007261C:
    // 0x8007261C: lw          $t5, 0x4760($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4760);
    // 0x80072620: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80072624: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80072628: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x8007262C: b           L_80072660
    // 0x80072630: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
        goto L_80072660;
    // 0x80072630: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
L_80072634:
    // 0x80072634: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x80072638: lw          $t0, 0x4760($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4760);
    // 0x8007263C: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80072640: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x80072644: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80072648: nop

    // 0x8007264C: beq         $a1, $zero, L_80072664
    if (ctx->r5 == 0) {
        // 0x80072650: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80072664;
    }
    // 0x80072650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072654: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80072658: jal         0x800727C4
    // 0x8007265C: nop

    rumble_start(rdram, ctx);
        goto after_1;
    // 0x8007265C: nop

    after_1:
L_80072660:
    // 0x80072660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80072664:
    // 0x80072664: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80072668: jr          $ra
    // 0x8007266C: nop

    return;
    // 0x8007266C: nop

;}
RECOMP_FUNC void draw_text_plain_unused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4964: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C4968: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800C496C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C4970: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C4974: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4978: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C497C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C4980: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C4984: lw          $a1, -0x5258($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5258);
    // 0x800C4988: jal         0x800C4B04
    // 0x800C498C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    render_text_string(rdram, ctx);
        goto after_0;
    // 0x800C498C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800C4990: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4994: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C4998: jr          $ra
    // 0x800C499C: nop

    return;
    // 0x800C499C: nop

;}
RECOMP_FUNC void init_object_water_effect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FC6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000FC70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FC74: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x8000FC78: sw          $a1, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r5;
    // 0x8000FC7C: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8000FC80: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x8000FC84: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8000FC88: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x8000FC8C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000FC90: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000FC94: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8000FC98: sra         $t9, $t8, 8
    ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
    // 0x8000FC9C: sh          $t9, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r25;
    // 0x8000FCA0: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x8000FCA4: nop

    // 0x8000FCA8: lh          $t0, 0x36($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X36);
    // 0x8000FCAC: nop

    // 0x8000FCB0: beq         $t0, $zero, L_8000FCD4
    if (ctx->r8 == 0) {
        // 0x8000FCB4: nop
    
            goto L_8000FCD4;
    }
    // 0x8000FCB4: nop

    // 0x8000FCB8: lh          $a0, 0x38($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X38);
    // 0x8000FCBC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8000FCC0: jal         0x8007B2C4
    // 0x8000FCC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    load_texture(rdram, ctx);
        goto after_0;
    // 0x8000FCC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000FCC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FCCC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8000FCD0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_8000FCD4:
    // 0x8000FCD4: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x8000FCD8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8000FCDC: sh          $t1, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r9;
    // 0x8000FCE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000FCE4: sw          $t2, -0x4C2C($at)
    MEM_W(-0X4C2C, ctx->r1) = ctx->r10;
    // 0x8000FCE8: lw          $t3, 0x40($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X40);
    // 0x8000FCEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000FCF0: lh          $t4, 0x36($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X36);
    // 0x8000FCF4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8000FCF8: beq         $t4, $zero, L_8000FD18
    if (ctx->r12 == 0) {
        // 0x8000FCFC: nop
    
            goto L_8000FD18;
    }
    // 0x8000FCFC: nop

    // 0x8000FD00: lw          $t5, 0x4($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X4);
    // 0x8000FD04: nop

    // 0x8000FD08: bne         $t5, $zero, L_8000FD18
    if (ctx->r13 != 0) {
        // 0x8000FD0C: nop
    
            goto L_8000FD18;
    }
    // 0x8000FD0C: nop

    // 0x8000FD10: b           L_8000FD18
    // 0x8000FD14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FD18;
    // 0x8000FD14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FD18:
    // 0x8000FD18: jr          $ra
    // 0x8000FD1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000FD1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void rumble_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800728C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800728CC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800728D0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800728D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800728D8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800728DC: bltz        $t7, L_80072944
    if (SIGNED(ctx->r15) < 0) {
        // 0x800728E0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80072944;
    }
    // 0x800728E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800728E4: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800728E8: beq         $at, $zero, L_80072948
    if (ctx->r1 == 0) {
        // 0x800728EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80072948;
    }
    // 0x800728EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800728F0: jal         0x80072490
    // 0x800728F4: nop

    input_get_id(rdram, ctx);
        goto after_0;
    // 0x800728F4: nop

    after_0:
    // 0x800728F8: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x800728FC: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80072900: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x80072904: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80072908: addu        $t3, $t3, $t8
    ctx->r11 = ADD32(ctx->r11, ctx->r24);
    // 0x8007290C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80072910: addiu       $a1, $a1, 0x4767
    ctx->r5 = ADD32(ctx->r5, 0X4767);
    // 0x80072914: addiu       $t4, $t4, 0x4738
    ctx->r12 = ADD32(ctx->r12, 0X4738);
    // 0x80072918: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8007291C: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x80072920: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80072924: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x80072928: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8007292C: sllv        $t1, $t0, $t8
    ctx->r9 = S32(ctx->r8 << (ctx->r24 & 31));
    // 0x80072930: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80072934: sb          $t2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r10;
    // 0x80072938: sh          $a2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r6;
    // 0x8007293C: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x80072940: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
L_80072944:
    // 0x80072944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80072948:
    // 0x80072948: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007294C: jr          $ra
    // 0x80072950: nop

    return;
    // 0x80072950: nop

;}
RECOMP_FUNC void racer_boss_sound_spatial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CC24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005CC28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005CC2C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8005CC30: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8005CC34: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005CC38: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8005CC3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005CC40: jal         0x8006FB8C
    // 0x8005CC44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x8005CC44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8005CC48: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005CC4C: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x8005CC50: sra         $t6, $v1, 24
    ctx->r14 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8005CC54: bne         $t0, $zero, L_8005CC60
    if (ctx->r8 != 0) {
        // 0x8005CC58: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8005CC60;
    }
    // 0x8005CC58: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8005CC5C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8005CC60:
    // 0x8005CC60: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8005CC64: lw          $t7, -0x24B8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X24B8);
    // 0x8005CC68: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8005CC6C: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x8005CC70: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8005CC74: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    // 0x8005CC78: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8005CC7C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8005CC80: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8005CC84: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8005CC88: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8005CC8C: jal         0x80009558
    // 0x8005CC90: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_1;
    // 0x8005CC90: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x8005CC94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005CC98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005CC9C: jr          $ra
    // 0x8005CCA0: nop

    return;
    // 0x8005CCA0: nop

;}
RECOMP_FUNC void menu_magic_codes_list_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ADE0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8008ADE4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008ADE8: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008ADEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008ADF0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8008ADF4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8008ADF8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008ADFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008AE00: beq         $v0, $zero, L_8008AE40
    if (ctx->r2 == 0) {
        // 0x8008AE04: sw          $zero, 0x48($sp)
        MEM_W(0X48, ctx->r29) = 0;
            goto L_8008AE40;
    }
    // 0x8008AE04: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8008AE08: blez        $v0, L_8008AE2C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008AE0C: subu        $t7, $v0, $a0
        ctx->r15 = SUB32(ctx->r2, ctx->r4);
            goto L_8008AE2C;
    }
    // 0x8008AE0C: subu        $t7, $v0, $a0
    ctx->r15 = SUB32(ctx->r2, ctx->r4);
    // 0x8008AE10: addu        $t6, $v0, $a0
    ctx->r14 = ADD32(ctx->r2, ctx->r4);
    // 0x8008AE14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008AE18: sw          $t6, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r14;
    // 0x8008AE1C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008AE20: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008AE24: b           L_8008AE40
    // 0x8008AE28: nop

        goto L_8008AE40;
    // 0x8008AE28: nop

L_8008AE2C:
    // 0x8008AE2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008AE30: sw          $t7, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r15;
    // 0x8008AE34: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008AE38: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008AE3C: nop

L_8008AE40:
    // 0x8008AE40: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008AE44: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8008AE48: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008AE4C: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x8008AE50: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8008AE54: andi        $t1, $t9, 0x3F
    ctx->r9 = ctx->r25 & 0X3F;
    // 0x8008AE58: bne         $at, $zero, L_8008AE74
    if (ctx->r1 != 0) {
        // 0x8008AE5C: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_8008AE74;
    }
    // 0x8008AE5C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8008AE60: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8008AE64: beq         $at, $zero, L_8008AE74
    if (ctx->r1 == 0) {
        // 0x8008AE68: nop
    
            goto L_8008AE74;
    }
    // 0x8008AE68: nop

    // 0x8008AE6C: jal         0x8008AA1C
    // 0x8008AE70: nop

    cheatlist_render(rdram, ctx);
        goto after_0;
    // 0x8008AE70: nop

    after_0:
L_8008AE74:
    // 0x8008AE74: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008AE78: lw          $t2, 0x6964($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6964);
    // 0x8008AE7C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8008AE80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008AE84: bne         $t2, $zero, L_8008AEF4
    if (ctx->r10 != 0) {
        // 0x8008AE88: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8008AEF4;
    }
    // 0x8008AE88: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8008AE8C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008AE90: lw          $t3, -0x604($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X604);
    // 0x8008AE94: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008AE98: bne         $t3, $zero, L_8008AEF4
    if (ctx->r11 != 0) {
        // 0x8008AE9C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8008AEF4;
    }
    // 0x8008AE9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008AEA0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008AEA4: addiu       $a1, $a1, 0x6A04
    ctx->r5 = ADD32(ctx->r5, 0X6A04);
    // 0x8008AEA8: addiu       $v1, $v1, 0x69FC
    ctx->r3 = ADD32(ctx->r3, 0X69FC);
    // 0x8008AEAC: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_8008AEB0:
    // 0x8008AEB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008AEB4: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x8008AEB8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8008AEBC: jal         0x8006A794
    // 0x8008AEC0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8008AEC0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_1:
    // 0x8008AEC4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8008AEC8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AECC: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8008AED0: lb          $t4, 0x0($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X0);
    // 0x8008AED4: lb          $t5, 0x0($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X0);
    // 0x8008AED8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008AEDC: or          $s3, $s3, $v0
    ctx->r19 = ctx->r19 | ctx->r2;
    // 0x8008AEE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008AEE4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008AEE8: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x8008AEEC: bne         $s0, $s1, L_8008AEB0
    if (ctx->r16 != ctx->r17) {
        // 0x8008AEF0: addu        $s2, $s2, $t5
        ctx->r18 = ADD32(ctx->r18, ctx->r13);
            goto L_8008AEB0;
    }
    // 0x8008AEF0: addu        $s2, $s2, $t5
    ctx->r18 = ADD32(ctx->r18, ctx->r13);
L_8008AEF4:
    // 0x8008AEF4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008AEF8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008AEFC: lw          $v0, 0x31C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C);
    // 0x8008AF00: addiu       $t0, $t0, 0x7240
    ctx->r8 = ADD32(ctx->r8, 0X7240);
    // 0x8008AF04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008AF08: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8008AF0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008AF10: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
L_8008AF14:
    // 0x8008AF14: and         $t6, $s1, $v0
    ctx->r14 = ctx->r17 & ctx->r2;
    // 0x8008AF18: beq         $t6, $zero, L_8008AF30
    if (ctx->r14 == 0) {
        // 0x8008AF1C: sll         $t9, $s1, 1
        ctx->r25 = S32(ctx->r17 << 1);
            goto L_8008AF30;
    }
    // 0x8008AF1C: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x8008AF20: sll         $t7, $a3, 1
    ctx->r15 = S32(ctx->r7 << 1);
    // 0x8008AF24: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8008AF28: sh          $s0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r16;
    // 0x8008AF2C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_8008AF30:
    // 0x8008AF30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008AF34: bne         $s0, $v1, L_8008AF14
    if (ctx->r16 != ctx->r3) {
        // 0x8008AF38: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8008AF14;
    }
    // 0x8008AF38: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8008AF3C: bltz        $a2, L_8008AF48
    if (SIGNED(ctx->r6) < 0) {
        // 0x8008AF40: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8008AF48;
    }
    // 0x8008AF40: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008AF44: blez        $a2, L_8008B068
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008AF48: addiu       $s0, $s0, 0x7206
        ctx->r16 = ADD32(ctx->r16, 0X7206);
            goto L_8008B068;
    }
L_8008AF48:
    // 0x8008AF48: addiu       $s0, $s0, 0x7206
    ctx->r16 = ADD32(ctx->r16, 0X7206);
    // 0x8008AF4C: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x8008AF50: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008AF54: beq         $a3, $t1, L_8008B068
    if (ctx->r7 == ctx->r9) {
        // 0x8008AF58: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8008B068;
    }
    // 0x8008AF58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008AF5C: jal         0x80001D04
    // 0x8008AF60: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008AF60: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8008AF64: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x8008AF68: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008AF6C: addiu       $t0, $t0, 0x7240
    ctx->r8 = ADD32(ctx->r8, 0X7240);
    // 0x8008AF70: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8008AF74: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008AF78: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8008AF7C: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8008AF80: addiu       $v0, $v0, 0x318
    ctx->r2 = ADD32(ctx->r2, 0X318);
    // 0x8008AF84: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8008AF88: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008AF8C: sllv        $s1, $t6, $t5
    ctx->r17 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x8008AF90: xor         $t8, $t7, $s1
    ctx->r24 = ctx->r15 ^ ctx->r17;
    // 0x8008AF94: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8008AF98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AF9C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8008AFA0: jal         0x8008ADB0
    // 0x8008AFA4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    cheatlist_exclusive(rdram, ctx);
        goto after_3;
    // 0x8008AFA4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_3:
    // 0x8008AFA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AFAC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8008AFB0: jal         0x8008ADB0
    // 0x8008AFB4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    cheatlist_exclusive(rdram, ctx);
        goto after_4;
    // 0x8008AFB4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_4:
    // 0x8008AFB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AFBC: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x8008AFC0: jal         0x8008ADB0
    // 0x8008AFC4: addiu       $a2, $zero, 0x6080
    ctx->r6 = ADD32(0, 0X6080);
    cheatlist_exclusive(rdram, ctx);
        goto after_5;
    // 0x8008AFC4: addiu       $a2, $zero, 0x6080
    ctx->r6 = ADD32(0, 0X6080);
    after_5:
    // 0x8008AFC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AFCC: addiu       $a1, $zero, 0x6080
    ctx->r5 = ADD32(0, 0X6080);
    // 0x8008AFD0: jal         0x8008ADB0
    // 0x8008AFD4: addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    cheatlist_exclusive(rdram, ctx);
        goto after_6;
    // 0x8008AFD4: addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    after_6:
    // 0x8008AFD8: lui         $a2, 0x1F
    ctx->r6 = S32(0X1F << 16);
    // 0x8008AFDC: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8008AFE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AFE4: jal         0x8008ADB0
    // 0x8008AFE8: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    cheatlist_exclusive(rdram, ctx);
        goto after_7;
    // 0x8008AFE8: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_7:
    // 0x8008AFEC: lui         $a1, 0x1F
    ctx->r5 = S32(0X1F << 16);
    // 0x8008AFF0: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x8008AFF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AFF8: jal         0x8008ADB0
    // 0x8008AFFC: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    cheatlist_exclusive(rdram, ctx);
        goto after_8;
    // 0x8008AFFC: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    after_8:
    // 0x8008B000: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008B004: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8008B008: jal         0x8008ADB0
    // 0x8008B00C: lui         $a2, 0xF
    ctx->r6 = S32(0XF << 16);
    cheatlist_exclusive(rdram, ctx);
        goto after_9;
    // 0x8008B00C: lui         $a2, 0xF
    ctx->r6 = S32(0XF << 16);
    after_9:
    // 0x8008B010: lui         $a2, 0xE
    ctx->r6 = S32(0XE << 16);
    // 0x8008B014: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8008B018: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008B01C: jal         0x8008ADB0
    // 0x8008B020: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    cheatlist_exclusive(rdram, ctx);
        goto after_10;
    // 0x8008B020: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_10:
    // 0x8008B024: lui         $a2, 0xD
    ctx->r6 = S32(0XD << 16);
    // 0x8008B028: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8008B02C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008B030: jal         0x8008ADB0
    // 0x8008B034: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    cheatlist_exclusive(rdram, ctx);
        goto after_11;
    // 0x8008B034: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    after_11:
    // 0x8008B038: lui         $a2, 0xB
    ctx->r6 = S32(0XB << 16);
    // 0x8008B03C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8008B040: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008B044: jal         0x8008ADB0
    // 0x8008B048: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    cheatlist_exclusive(rdram, ctx);
        goto after_12;
    // 0x8008B048: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    after_12:
    // 0x8008B04C: lui         $a2, 0x7
    ctx->r6 = S32(0X7 << 16);
    // 0x8008B050: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8008B054: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008B058: jal         0x8008ADB0
    // 0x8008B05C: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    cheatlist_exclusive(rdram, ctx);
        goto after_13;
    // 0x8008B05C: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    after_13:
    // 0x8008B060: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8008B064: nop

L_8008B068:
    // 0x8008B068: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008B06C: addiu       $s0, $s0, 0x7206
    ctx->r16 = ADD32(ctx->r16, 0X7206);
    // 0x8008B070: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8008B074: bgez        $s2, L_8008B0A4
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8008B078: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8008B0A4;
    }
    // 0x8008B078: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8008B07C: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8008B080: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x8008B084: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8008B088: nop

    // 0x8008B08C: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008B090: beq         $at, $zero, L_8008B0A4
    if (ctx->r1 == 0) {
        // 0x8008B094: nop
    
            goto L_8008B0A4;
    }
    // 0x8008B094: nop

    // 0x8008B098: sh          $a3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r7;
    // 0x8008B09C: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8008B0A0: nop

L_8008B0A4:
    // 0x8008B0A4: blez        $s2, L_8008B0D0
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8008B0A8: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8008B0D0;
    }
    // 0x8008B0A8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008B0AC: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8008B0B0: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x8008B0B4: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8008B0B8: nop

    // 0x8008B0BC: bgez        $v0, L_8008B0D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008B0C0: nop
    
            goto L_8008B0D0;
    }
    // 0x8008B0C0: nop

    // 0x8008B0C4: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x8008B0C8: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8008B0CC: nop

L_8008B0D0:
    // 0x8008B0D0: addiu       $a1, $a1, 0x6980
    ctx->r5 = ADD32(ctx->r5, 0X6980);
    // 0x8008B0D4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8008B0D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B0DC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8008B0E0: beq         $at, $zero, L_8008B0F0
    if (ctx->r1 == 0) {
        // 0x8008B0E4: nop
    
            goto L_8008B0F0;
    }
    // 0x8008B0E4: nop

    // 0x8008B0E8: b           L_8008B110
    // 0x8008B0EC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_8008B110;
    // 0x8008B0EC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_8008B0F0:
    // 0x8008B0F0: lw          $a0, 0x7234($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7234);
    // 0x8008B0F4: nop

    // 0x8008B0F8: addu        $t2, $v1, $a0
    ctx->r10 = ADD32(ctx->r3, ctx->r4);
    // 0x8008B0FC: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8008B100: bne         $at, $zero, L_8008B110
    if (ctx->r1 != 0) {
        // 0x8008B104: subu        $t3, $v0, $a0
        ctx->r11 = SUB32(ctx->r2, ctx->r4);
            goto L_8008B110;
    }
    // 0x8008B104: subu        $t3, $v0, $a0
    ctx->r11 = SUB32(ctx->r2, ctx->r4);
    // 0x8008B108: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008B10C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
L_8008B110:
    // 0x8008B110: beq         $a2, $v0, L_8008B12C
    if (ctx->r6 == ctx->r2) {
        // 0x8008B114: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8008B12C;
    }
    // 0x8008B114: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008B118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008B11C: jal         0x80001D04
    // 0x8008B120: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_14;
    // 0x8008B120: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_14:
    // 0x8008B124: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8008B128: nop

L_8008B12C:
    // 0x8008B12C: andi        $t6, $s3, 0x9000
    ctx->r14 = ctx->r19 & 0X9000;
    // 0x8008B130: beq         $t6, $zero, L_8008B14C
    if (ctx->r14 == 0) {
        // 0x8008B134: andi        $t8, $s3, 0x4000
        ctx->r24 = ctx->r19 & 0X4000;
            goto L_8008B14C;
    }
    // 0x8008B134: andi        $t8, $s3, 0x4000
    ctx->r24 = ctx->r19 & 0X4000;
    // 0x8008B138: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x8008B13C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008B140: bne         $a3, $t5, L_8008B14C
    if (ctx->r7 != ctx->r13) {
        // 0x8008B144: nop
    
            goto L_8008B14C;
    }
    // 0x8008B144: nop

    // 0x8008B148: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
L_8008B14C:
    // 0x8008B14C: beq         $t8, $zero, L_8008B158
    if (ctx->r24 == 0) {
        // 0x8008B150: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_8008B158;
    }
    // 0x8008B150: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8008B154: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
L_8008B158:
    // 0x8008B158: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8008B15C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B160: beq         $t1, $zero, L_8008B180
    if (ctx->r9 == 0) {
        // 0x8008B164: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008B180;
    }
    // 0x8008B164: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008B168: sw          $t1, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r9;
    // 0x8008B16C: jal         0x800C06F8
    // 0x8008B170: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_15;
    // 0x8008B170: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_15:
    // 0x8008B174: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008B178: jal         0x80001D04
    // 0x8008B17C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_16;
    // 0x8008B17C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
L_8008B180:
    // 0x8008B180: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008B184: lw          $t2, -0x604($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X604);
    // 0x8008B188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008B18C: slti        $at, $t2, -0x1E
    ctx->r1 = SIGNED(ctx->r10) < -0X1E ? 1 : 0;
    // 0x8008B190: beq         $at, $zero, L_8008B1B0
    if (ctx->r1 == 0) {
        // 0x8008B194: nop
    
            goto L_8008B1B0;
    }
    // 0x8008B194: nop

    // 0x8008B198: jal         0x8008B1D4
    // 0x8008B19C: nop

    cheatlist_free(rdram, ctx);
        goto after_17;
    // 0x8008B19C: nop

    after_17:
    // 0x8008B1A0: jal         0x80081820
    // 0x8008B1A4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    menu_init(rdram, ctx);
        goto after_18;
    // 0x8008B1A4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_18:
    // 0x8008B1A8: b           L_8008B1B8
    // 0x8008B1AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008B1B8;
    // 0x8008B1AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008B1B0:
    // 0x8008B1B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B1B4: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_8008B1B8:
    // 0x8008B1B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008B1BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8008B1C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8008B1C4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B1C8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8008B1CC: jr          $ra
    // 0x8008B1D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8008B1D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void hud_bananas(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A469C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A46A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A46A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A46A8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800A46AC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800A46B0: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800A46B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A46B8: beq         $v0, $at, L_800A4768
    if (ctx->r2 == ctx->r1) {
        // 0x800A46BC: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800A4768;
    }
    // 0x800A46BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A46C0: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x800A46C4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800A46C8: blez        $v1, L_800A4708
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A46CC: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_800A4708;
    }
    // 0x800A46CC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800A46D0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800A46D4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800A46D8: lbu         $t9, 0x2D14($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X2D14);
    // 0x800A46DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A46E0: beq         $t9, $at, L_800A4708
    if (ctx->r25 == ctx->r1) {
        // 0x800A46E4: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800A4708;
    }
    // 0x800A46E4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A46E8: lw          $t2, 0x7320($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7320);
    // 0x800A46EC: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800A46F0: lb          $v0, 0x4C($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X4C);
    // 0x800A46F4: nop

    // 0x800A46F8: beq         $v0, $at, L_800A4708
    if (ctx->r2 == ctx->r1) {
        // 0x800A46FC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800A4708;
    }
    // 0x800A46FC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A4700: bne         $v0, $at, L_800A4B2C
    if (ctx->r2 != ctx->r1) {
        // 0x800A4704: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4B2C;
    }
    // 0x800A4704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A4708:
    // 0x800A4708: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800A470C: nop

    // 0x800A4710: lb          $t4, 0x1D8($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X1D8);
    // 0x800A4714: nop

    // 0x800A4718: bne         $t4, $zero, L_800A4B2C
    if (ctx->r12 != 0) {
        // 0x800A471C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4B2C;
    }
    // 0x800A471C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A4720: blez        $v1, L_800A4768
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A4724: nop
    
            goto L_800A4768;
    }
    // 0x800A4724: nop

    // 0x800A4728: lb          $v0, 0x193($t3)
    ctx->r2 = MEM_B(ctx->r11, 0X193);
    // 0x800A472C: nop

    // 0x800A4730: blez        $v0, L_800A4768
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A4734: sll         $t5, $v0, 2
        ctx->r13 = S32(ctx->r2 << 2);
            goto L_800A4768;
    }
    // 0x800A4734: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800A4738: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800A473C: lw          $t7, 0x128($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X128);
    // 0x800A4740: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A4744: slti        $at, $t7, 0xB4
    ctx->r1 = SIGNED(ctx->r15) < 0XB4 ? 1 : 0;
    // 0x800A4748: beq         $at, $zero, L_800A4768
    if (ctx->r1 == 0) {
        // 0x800A474C: nop
    
            goto L_800A4768;
    }
    // 0x800A474C: nop

    // 0x800A4750: lw          $t8, 0x7320($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7320);
    // 0x800A4754: nop

    // 0x800A4758: lb          $t9, 0x4C($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X4C);
    // 0x800A475C: nop

    // 0x800A4760: andi        $t2, $t9, 0x40
    ctx->r10 = ctx->r25 & 0X40;
    // 0x800A4764: beq         $t2, $zero, L_800A4B28
    if (ctx->r10 == 0) {
        // 0x800A4768: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_800A4B28;
    }
L_800A4768:
    // 0x800A4768: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A476C: addiu       $s0, $s0, 0x729C
    ctx->r16 = ADD32(ctx->r16, 0X729C);
    // 0x800A4770: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A4774: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4778: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A477C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4780: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4784: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4788: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A478C: jal         0x800AAB5C
    // 0x800A4790: addiu       $a3, $a3, 0x240
    ctx->r7 = ADD32(ctx->r7, 0X240);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A4790: addiu       $a3, $a3, 0x240
    ctx->r7 = ADD32(ctx->r7, 0X240);
    after_0:
    // 0x800A4794: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A4798: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A479C: lb          $a0, 0x185($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X185);
    // 0x800A47A0: nop

    // 0x800A47A4: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x800A47A8: lb          $a1, 0xFA($v0)
    ctx->r5 = MEM_B(ctx->r2, 0XFA);
    // 0x800A47AC: lbu         $v1, 0xF9($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XF9);
    // 0x800A47B0: bne         $a1, $zero, L_800A47DC
    if (ctx->r5 != 0) {
        // 0x800A47B4: nop
    
            goto L_800A47DC;
    }
    // 0x800A47B4: nop

    // 0x800A47B8: lb          $t4, 0xFB($v0)
    ctx->r12 = MEM_B(ctx->r2, 0XFB);
    // 0x800A47BC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800A47C0: beq         $a0, $t4, L_800A47DC
    if (ctx->r4 == ctx->r12) {
        // 0x800A47C4: nop
    
            goto L_800A47DC;
    }
    // 0x800A47C4: nop

    // 0x800A47C8: sb          $t3, 0xFA($v0)
    MEM_B(0XFA, ctx->r2) = ctx->r11;
    // 0x800A47CC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800A47D0: lb          $t5, 0x185($a2)
    ctx->r13 = MEM_B(ctx->r6, 0X185);
    // 0x800A47D4: b           L_800A4868
    // 0x800A47D8: sb          $t5, 0xFB($t6)
    MEM_B(0XFB, ctx->r14) = ctx->r13;
        goto L_800A4868;
    // 0x800A47D8: sb          $t5, 0xFB($t6)
    MEM_B(0XFB, ctx->r14) = ctx->r13;
L_800A47DC:
    // 0x800A47DC: beq         $a1, $zero, L_800A4868
    if (ctx->r5 == 0) {
        // 0x800A47E0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800A4868;
    }
    // 0x800A47E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A47E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A47E8: nop

    // 0x800A47EC: swc1        $f4, 0x388($v0)
    MEM_W(0X388, ctx->r2) = ctx->f4.u32l;
    // 0x800A47F0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800A47F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A47F8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A47FC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A4800: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A4804: lh          $t2, 0xF8($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XF8);
    // 0x800A4808: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800A480C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x800A4810: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x800A4814: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x800A4818: slt         $at, $t9, $t4
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800A481C: beq         $at, $zero, L_800A4868
    if (ctx->r1 == 0) {
        // 0x800A4820: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_800A4868;
    }
    // 0x800A4820: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800A4824: lb          $t3, 0xFA($v0)
    ctx->r11 = MEM_B(ctx->r2, 0XFA);
    // 0x800A4828: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A482C: addiu       $t5, $t3, -0x1
    ctx->r13 = ADD32(ctx->r11, -0X1);
    // 0x800A4830: sb          $t5, 0xFA($v0)
    MEM_B(0XFA, ctx->r2) = ctx->r13;
    // 0x800A4834: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A4838: nop

    // 0x800A483C: lb          $t6, 0xFA($v0)
    ctx->r14 = MEM_B(ctx->r2, 0XFA);
    // 0x800A4840: nop

    // 0x800A4844: bne         $t6, $zero, L_800A4868
    if (ctx->r14 != 0) {
        // 0x800A4848: nop
    
            goto L_800A4868;
    }
    // 0x800A4848: nop

    // 0x800A484C: sb          $a0, 0x39B($v0)
    MEM_B(0X39B, ctx->r2) = ctx->r4;
    // 0x800A4850: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800A4854: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800A4858: sb          $t7, 0x39A($t8)
    MEM_B(0X39A, ctx->r24) = ctx->r15;
    // 0x800A485C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A4860: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A4864: sh          $a0, 0x398($t9)
    MEM_H(0X398, ctx->r25) = ctx->r4;
L_800A4868:
    // 0x800A4868: bne         $v1, $zero, L_800A498C
    if (ctx->r3 != 0) {
        // 0x800A486C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800A498C;
    }
    // 0x800A486C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800A4870: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A4874: jal         0x8007C36C
    // 0x800A4878: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    sprite_opaque(rdram, ctx);
        goto after_1;
    // 0x800A4878: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x800A487C: jal         0x800662D8
    // 0x800A4880: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_2;
    // 0x800A4880: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800A4884: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A4888: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A488C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4890: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4894: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4898: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A489C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A48A0: jal         0x800AAB5C
    // 0x800A48A4: addiu       $a3, $a3, 0x360
    ctx->r7 = ADD32(ctx->r7, 0X360);
    hud_element_render(rdram, ctx);
        goto after_3;
    // 0x800A48A4: addiu       $a3, $a3, 0x360
    ctx->r7 = ADD32(ctx->r7, 0X360);
    after_3:
    // 0x800A48A8: jal         0x800662D8
    // 0x800A48AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_4;
    // 0x800A48AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800A48B0: jal         0x8007C36C
    // 0x800A48B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_5;
    // 0x800A48B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x800A48B8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800A48BC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800A48C0: nop

    // 0x800A48C4: sh          $t2, 0xF8($t4)
    MEM_H(0XF8, ctx->r12) = ctx->r10;
    // 0x800A48C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A48CC: nop

    // 0x800A48D0: lb          $t3, 0x39B($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X39B);
    // 0x800A48D4: nop

    // 0x800A48D8: beq         $t3, $zero, L_800A4A10
    if (ctx->r11 == 0) {
        // 0x800A48DC: lw          $t1, 0x3C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X3C);
            goto L_800A4A10;
    }
    // 0x800A48DC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800A48E0: lb          $t5, 0x39A($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X39A);
    // 0x800A48E4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800A48E8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800A48EC: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x800A48F0: sb          $t7, 0x39A($v0)
    MEM_B(0X39A, ctx->r2) = ctx->r15;
    // 0x800A48F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A48F8: nop

    // 0x800A48FC: lb          $t8, 0x39A($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X39A);
    // 0x800A4900: nop

    // 0x800A4904: bgez        $t8, L_800A494C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A4908: nop
    
            goto L_800A494C;
    }
    // 0x800A4908: nop

    // 0x800A490C: sb          $a0, 0x39A($v0)
    MEM_B(0X39A, ctx->r2) = ctx->r4;
    // 0x800A4910: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A4914: nop

    // 0x800A4918: lh          $v1, 0x398($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X398);
    // 0x800A491C: nop

    // 0x800A4920: bne         $a0, $v1, L_800A4948
    if (ctx->r4 != ctx->r3) {
        // 0x800A4924: addiu       $t4, $v1, 0x1
        ctx->r12 = ADD32(ctx->r3, 0X1);
            goto L_800A4948;
    }
    // 0x800A4924: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x800A4928: sh          $zero, 0x398($v0)
    MEM_H(0X398, ctx->r2) = 0;
    // 0x800A492C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A4930: nop

    // 0x800A4934: lb          $t9, 0x39B($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X39B);
    // 0x800A4938: nop

    // 0x800A493C: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x800A4940: b           L_800A494C
    // 0x800A4944: sb          $t2, 0x39B($v0)
    MEM_B(0X39B, ctx->r2) = ctx->r10;
        goto L_800A494C;
    // 0x800A4944: sb          $t2, 0x39B($v0)
    MEM_B(0X39B, ctx->r2) = ctx->r10;
L_800A4948:
    // 0x800A4948: sh          $t4, 0x398($v0)
    MEM_H(0X398, ctx->r2) = ctx->r12;
L_800A494C:
    // 0x800A494C: jal         0x800662D8
    // 0x800A4950: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_6;
    // 0x800A4950: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x800A4954: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A4958: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A495C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4960: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4964: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4968: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A496C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4970: jal         0x800AAB5C
    // 0x800A4974: addiu       $a3, $a3, 0x380
    ctx->r7 = ADD32(ctx->r7, 0X380);
    hud_element_render(rdram, ctx);
        goto after_7;
    // 0x800A4974: addiu       $a3, $a3, 0x380
    ctx->r7 = ADD32(ctx->r7, 0X380);
    after_7:
    // 0x800A4978: jal         0x800662D8
    // 0x800A497C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_8;
    // 0x800A497C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800A4980: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A4984: b           L_800A4A10
    // 0x800A4988: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
        goto L_800A4A10;
    // 0x800A4988: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_800A498C:
    // 0x800A498C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800A4990: addiu       $t3, $v0, 0x80
    ctx->r11 = ADD32(ctx->r2, 0X80);
    // 0x800A4994: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A4998: jal         0x80068748
    // 0x800A499C: sh          $t3, 0xF8($t5)
    MEM_H(0XF8, ctx->r13) = ctx->r11;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_9;
    // 0x800A499C: sh          $t3, 0xF8($t5)
    MEM_H(0XF8, ctx->r13) = ctx->r11;
    after_9:
    // 0x800A49A0: jal         0x8007C36C
    // 0x800A49A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_10;
    // 0x800A49A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x800A49A8: jal         0x800662D8
    // 0x800A49AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_11;
    // 0x800A49AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x800A49B0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A49B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A49B8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A49BC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A49C0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A49C4: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A49C8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A49CC: jal         0x800AAB5C
    // 0x800A49D0: addiu       $a3, $a3, 0xE0
    ctx->r7 = ADD32(ctx->r7, 0XE0);
    hud_element_render(rdram, ctx);
        goto after_12;
    // 0x800A49D0: addiu       $a3, $a3, 0xE0
    ctx->r7 = ADD32(ctx->r7, 0XE0);
    after_12:
    // 0x800A49D4: jal         0x8007C36C
    // 0x800A49D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_13;
    // 0x800A49D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x800A49DC: jal         0x800662D8
    // 0x800A49E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_14;
    // 0x800A49E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x800A49E4: jal         0x80068748
    // 0x800A49E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_15;
    // 0x800A49E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x800A49EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A49F0: nop

    // 0x800A49F4: lh          $t6, 0xF8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XF8);
    // 0x800A49F8: nop

    // 0x800A49FC: addiu       $t7, $t6, -0x80
    ctx->r15 = ADD32(ctx->r14, -0X80);
    // 0x800A4A00: sh          $t7, 0xF8($v0)
    MEM_H(0XF8, ctx->r2) = ctx->r15;
    // 0x800A4A04: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A4A08: nop

    // 0x800A4A0C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_800A4A10:
    // 0x800A4A10: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x800A4A14: div         $zero, $t1, $t0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r8)));
    // 0x800A4A18: bne         $t0, $zero, L_800A4A24
    if (ctx->r8 != 0) {
        // 0x800A4A1C: nop
    
            goto L_800A4A24;
    }
    // 0x800A4A1C: nop

    // 0x800A4A20: break       7
    do_break(2148157984);
L_800A4A24:
    // 0x800A4A24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A4A28: bne         $t0, $at, L_800A4A3C
    if (ctx->r8 != ctx->r1) {
        // 0x800A4A2C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A4A3C;
    }
    // 0x800A4A2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A4A30: bne         $t1, $at, L_800A4A3C
    if (ctx->r9 != ctx->r1) {
        // 0x800A4A34: nop
    
            goto L_800A4A3C;
    }
    // 0x800A4A34: nop

    // 0x800A4A38: break       6
    do_break(2148158008);
L_800A4A3C:
    // 0x800A4A3C: mflo        $v1
    ctx->r3 = lo;
    // 0x800A4A40: beq         $v1, $zero, L_800A4AAC
    if (ctx->r3 == 0) {
        // 0x800A4A44: nop
    
            goto L_800A4AAC;
    }
    // 0x800A4A44: nop

    // 0x800A4A48: div         $zero, $t1, $t0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r8)));
    // 0x800A4A4C: sh          $v1, 0x118($v0)
    MEM_H(0X118, ctx->r2) = ctx->r3;
    // 0x800A4A50: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A4A54: bne         $t0, $zero, L_800A4A60
    if (ctx->r8 != 0) {
        // 0x800A4A58: nop
    
            goto L_800A4A60;
    }
    // 0x800A4A58: nop

    // 0x800A4A5C: break       7
    do_break(2148158044);
L_800A4A60:
    // 0x800A4A60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A4A64: bne         $t0, $at, L_800A4A78
    if (ctx->r8 != ctx->r1) {
        // 0x800A4A68: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A4A78;
    }
    // 0x800A4A68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A4A6C: bne         $t1, $at, L_800A4A78
    if (ctx->r9 != ctx->r1) {
        // 0x800A4A70: nop
    
            goto L_800A4A78;
    }
    // 0x800A4A70: nop

    // 0x800A4A74: break       6
    do_break(2148158068);
L_800A4A78:
    // 0x800A4A78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4A7C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4A80: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4A84: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4A88: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4A8C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4A90: mfhi        $t8
    ctx->r24 = hi;
    // 0x800A4A94: sh          $t8, 0x138($t9)
    MEM_H(0X138, ctx->r25) = ctx->r24;
    // 0x800A4A98: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A4A9C: jal         0x800AAB5C
    // 0x800A4AA0: addiu       $a3, $a3, 0x120
    ctx->r7 = ADD32(ctx->r7, 0X120);
    hud_element_render(rdram, ctx);
        goto after_16;
    // 0x800A4AA0: addiu       $a3, $a3, 0x120
    ctx->r7 = ADD32(ctx->r7, 0X120);
    after_16:
    // 0x800A4AA4: b           L_800A4AE4
    // 0x800A4AA8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
        goto L_800A4AE4;
    // 0x800A4AA8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_800A4AAC:
    // 0x800A4AAC: div         $zero, $t1, $t0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r8)));
    // 0x800A4AB0: bne         $t0, $zero, L_800A4ABC
    if (ctx->r8 != 0) {
        // 0x800A4AB4: nop
    
            goto L_800A4ABC;
    }
    // 0x800A4AB4: nop

    // 0x800A4AB8: break       7
    do_break(2148158136);
L_800A4ABC:
    // 0x800A4ABC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A4AC0: bne         $t0, $at, L_800A4AD4
    if (ctx->r8 != ctx->r1) {
        // 0x800A4AC4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A4AD4;
    }
    // 0x800A4AC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A4AC8: bne         $t1, $at, L_800A4AD4
    if (ctx->r9 != ctx->r1) {
        // 0x800A4ACC: nop
    
            goto L_800A4AD4;
    }
    // 0x800A4ACC: nop

    // 0x800A4AD0: break       6
    do_break(2148158160);
L_800A4AD4:
    // 0x800A4AD4: mfhi        $t2
    ctx->r10 = hi;
    // 0x800A4AD8: sh          $t2, 0x118($v0)
    MEM_H(0X118, ctx->r2) = ctx->r10;
    // 0x800A4ADC: nop

    // 0x800A4AE0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_800A4AE4:
    // 0x800A4AE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4AE8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4AEC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4AF0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4AF4: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4AF8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4AFC: jal         0x800AAB5C
    // 0x800A4B00: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
    hud_element_render(rdram, ctx);
        goto after_17;
    // 0x800A4B00: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
    after_17:
    // 0x800A4B04: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A4B08: lw          $v1, 0x72BC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72BC);
    // 0x800A4B0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A4B10: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800A4B14: sw          $t4, 0x72BC($at)
    MEM_W(0X72BC, ctx->r1) = ctx->r12;
    // 0x800A4B18: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A4B1C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800A4B20: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800A4B24: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_800A4B28:
    // 0x800A4B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A4B2C:
    // 0x800A4B2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A4B30: jr          $ra
    // 0x800A4B34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800A4B34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void set_current_text_background_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C55B0: blez        $a0, L_800C55EC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C55B4: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C55EC;
    }
    // 0x800C55B4: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C55B8: beq         $at, $zero, L_800C55EC
    if (ctx->r1 == 0) {
        // 0x800C55BC: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C55EC;
    }
    // 0x800C55BC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C55C0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C55C4: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C55C8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C55CC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C55D0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C55D4: sb          $a1, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r5;
    // 0x800C55D8: sb          $a2, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r6;
    // 0x800C55DC: sb          $a3, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r7;
    // 0x800C55E0: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800C55E4: nop

    // 0x800C55E8: sb          $t8, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r24;
L_800C55EC:
    // 0x800C55EC: jr          $ra
    // 0x800C55F0: nop

    return;
    // 0x800C55F0: nop

;}
RECOMP_FUNC void obj_init_overridepos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037D94: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80037D98: jr          $ra
    // 0x80037D9C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80037D9C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void set_kerning(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C46C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C46C8: jr          $ra
    // 0x800C46CC: sw          $a0, -0x5250($at)
    MEM_W(-0X5250, ctx->r1) = ctx->r4;
    return;
    // 0x800C46CC: sw          $a0, -0x5250($at)
    MEM_W(-0X5250, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80014090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014090: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80014094: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80014098: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8001409C: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x800140A0: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x800140A4: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x800140A8: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x800140AC: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x800140B0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800140B4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800140B8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800140BC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800140C0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800140C4: lb          $t6, 0x74($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X74);
    // 0x800140C8: lb          $t9, 0x75($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X75);
    // 0x800140CC: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800140D0: lbu         $v1, 0x73($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X73);
    // 0x800140D4: lbu         $s5, 0x72($v0)
    ctx->r21 = MEM_BU(ctx->r2, 0X72);
    // 0x800140D8: or          $ra, $a0, $zero
    ctx->r31 = ctx->r4 | 0;
    // 0x800140DC: mflo        $s0
    ctx->r16 = lo;
    // 0x800140E0: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x800140E4: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800140E8: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800140EC: mflo        $s1
    ctx->r17 = lo;
    // 0x800140F0: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x800140F4: beq         $v1, $a2, L_80014110
    if (ctx->r3 == ctx->r6) {
        // 0x800140F8: sra         $s1, $t6, 16
        ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
            goto L_80014110;
    }
    // 0x800140F8: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800140FC: lb          $t8, 0x55($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X55);
    // 0x80014100: nop

    // 0x80014104: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80014108: beq         $at, $zero, L_80014288
    if (ctx->r1 == 0) {
        // 0x8001410C: nop
    
            goto L_80014288;
    }
    // 0x8001410C: nop

L_80014110:
    // 0x80014110: bne         $v1, $a2, L_80014124
    if (ctx->r3 != ctx->r6) {
        // 0x80014114: addiu       $fp, $v1, 0x1
        ctx->r30 = ADD32(ctx->r3, 0X1);
            goto L_80014124;
    }
    // 0x80014114: addiu       $fp, $v1, 0x1
    ctx->r30 = ADD32(ctx->r3, 0X1);
    // 0x80014118: lb          $fp, 0x55($v0)
    ctx->r30 = MEM_B(ctx->r2, 0X55);
    // 0x8001411C: b           L_80014124
    // 0x80014120: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80014124;
    // 0x80014120: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80014124:
    // 0x80014124: slt         $at, $v1, $fp
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x80014128: beq         $at, $zero, L_80014288
    if (ctx->r1 == 0) {
        // 0x8001412C: or          $s7, $v1, $zero
        ctx->r23 = ctx->r3 | 0;
            goto L_80014288;
    }
    // 0x8001412C: or          $s7, $v1, $zero
    ctx->r23 = ctx->r3 | 0;
    // 0x80014130: sll         $s6, $v1, 2
    ctx->r22 = S32(ctx->r3 << 2);
L_80014134:
    // 0x80014134: lw          $t9, 0x68($ra)
    ctx->r25 = MEM_W(ctx->r31, 0X68);
    // 0x80014138: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001413C: addu        $t6, $t9, $s6
    ctx->r14 = ADD32(ctx->r25, ctx->r22);
    // 0x80014140: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80014144: sll         $t9, $s5, 3
    ctx->r25 = S32(ctx->r21 << 3);
    // 0x80014148: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8001414C: nop

    // 0x80014150: lh          $t7, 0x22($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X22);
    // 0x80014154: nop

    // 0x80014158: slt         $at, $s5, $t7
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001415C: beq         $at, $zero, L_80014280
    if (ctx->r1 == 0) {
        // 0x80014160: nop
    
            goto L_80014280;
    }
    // 0x80014160: nop

    // 0x80014164: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80014168: lh          $v1, 0x28($t4)
    ctx->r3 = MEM_H(ctx->r12, 0X28);
    // 0x8001416C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80014170: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80014174: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80014178: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8001417C: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80014180: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x80014184: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x80014188: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001418C: blez        $v1, L_80014280
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80014190: sra         $s4, $t7, 16
        ctx->r20 = S32(SIGNED(ctx->r15) >> 16);
            goto L_80014280;
    }
    // 0x80014190: sra         $s4, $t7, 16
    ctx->r20 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80014194: lw          $t1, 0x38($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X38);
    // 0x80014198: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
L_8001419C:
    // 0x8001419C: lbu         $t9, 0x0($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X0);
    // 0x800141A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800141A4: bne         $s5, $t9, L_80014274
    if (ctx->r21 != ctx->r25) {
        // 0x800141A8: slt         $at, $s2, $v1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80014274;
    }
    // 0x800141A8: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800141AC: lh          $a1, 0x4($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X4);
    // 0x800141B0: lh          $t6, 0x10($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X10);
    // 0x800141B4: addiu       $t2, $s3, -0x1
    ctx->r10 = ADD32(ctx->r19, -0X1);
    // 0x800141B8: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800141BC: beq         $at, $zero, L_80014270
    if (ctx->r1 == 0) {
        // 0x800141C0: sll         $t7, $t2, 16
        ctx->r15 = S32(ctx->r10 << 16);
            goto L_80014270;
    }
    // 0x800141C0: sll         $t7, $t2, 16
    ctx->r15 = S32(ctx->r10 << 16);
    // 0x800141C4: addiu       $t3, $s4, -0x1
    ctx->r11 = ADD32(ctx->r20, -0X1);
    // 0x800141C8: sll         $t9, $t3, 16
    ctx->r25 = S32(ctx->r11 << 16);
    // 0x800141CC: sra         $t3, $t9, 16
    ctx->r11 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800141D0: sra         $t2, $t7, 16
    ctx->r10 = S32(SIGNED(ctx->r15) >> 16);
L_800141D4:
    // 0x800141D4: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x800141D8: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x800141DC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800141E0: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800141E4: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
    // 0x800141E8: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x800141EC: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x800141F0: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x800141F4: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x800141F8: subu        $t1, $t9, $v1
    ctx->r9 = SUB32(ctx->r25, ctx->r3);
    // 0x800141FC: subu        $a3, $t7, $v1
    ctx->r7 = SUB32(ctx->r15, ctx->r3);
    // 0x80014200: addu        $t9, $v1, $s0
    ctx->r25 = ADD32(ctx->r3, ctx->r16);
    // 0x80014204: addu        $t7, $a0, $s1
    ctx->r15 = ADD32(ctx->r4, ctx->r17);
    // 0x80014208: subu        $a2, $t8, $a0
    ctx->r6 = SUB32(ctx->r24, ctx->r4);
    // 0x8001420C: subu        $t0, $t6, $a0
    ctx->r8 = SUB32(ctx->r14, ctx->r4);
    // 0x80014210: and         $t6, $t9, $t2
    ctx->r14 = ctx->r25 & ctx->r10;
    // 0x80014214: and         $t8, $t7, $t3
    ctx->r24 = ctx->r15 & ctx->r11;
    // 0x80014218: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x8001421C: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x80014220: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80014224: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
    // 0x80014228: addu        $t9, $v1, $t1
    ctx->r25 = ADD32(ctx->r3, ctx->r9);
    // 0x8001422C: addu        $t7, $v1, $a3
    ctx->r15 = ADD32(ctx->r3, ctx->r7);
    // 0x80014230: addu        $t6, $a0, $a2
    ctx->r14 = ADD32(ctx->r4, ctx->r6);
    // 0x80014234: addu        $t8, $a0, $t0
    ctx->r24 = ADD32(ctx->r4, ctx->r8);
    // 0x80014238: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    // 0x8001423C: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x80014240: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
    // 0x80014244: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
    // 0x80014248: lw          $t9, 0x38($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X38);
    // 0x8001424C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80014250: addu        $t1, $t9, $t5
    ctx->r9 = ADD32(ctx->r25, ctx->r13);
    // 0x80014254: lh          $t6, 0x10($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X10);
    // 0x80014258: nop

    // 0x8001425C: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80014260: bne         $at, $zero, L_800141D4
    if (ctx->r1 != 0) {
        // 0x80014264: nop
    
            goto L_800141D4;
    }
    // 0x80014264: nop

    // 0x80014268: lh          $v1, 0x28($t4)
    ctx->r3 = MEM_H(ctx->r12, 0X28);
    // 0x8001426C: nop

L_80014270:
    // 0x80014270: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
L_80014274:
    // 0x80014274: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80014278: bne         $at, $zero, L_8001419C
    if (ctx->r1 != 0) {
        // 0x8001427C: addiu       $t1, $t1, 0xC
        ctx->r9 = ADD32(ctx->r9, 0XC);
            goto L_8001419C;
    }
    // 0x8001427C: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
L_80014280:
    // 0x80014280: bne         $s7, $fp, L_80014134
    if (ctx->r23 != ctx->r30) {
        // 0x80014284: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_80014134;
    }
    // 0x80014284: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_80014288:
    // 0x80014288: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001428C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80014290: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80014294: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80014298: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8001429C: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x800142A0: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x800142A4: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x800142A8: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x800142AC: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x800142B0: jr          $ra
    // 0x800142B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800142B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void render_text_string(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4B04: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800C4B08: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800C4B0C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800C4B10: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C4B14: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C4B18: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C4B1C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C4B20: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800C4B24: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x800C4B28: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C4B2C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C4B30: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x800C4B34: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x800C4B38: beq         $a2, $zero, L_800C52DC
    if (ctx->r6 == 0) {
        // 0x800C4B3C: addiu       $s4, $zero, -0x1
        ctx->r20 = ADD32(0, -0X1);
            goto L_800C52DC;
    }
    // 0x800C4B3C: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x800C4B40: lbu         $t7, 0x1D($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1D);
    // 0x800C4B44: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C4B48: lw          $t9, -0x525C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X525C);
    // 0x800C4B4C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C4B50: sll         $t8, $t7, 10
    ctx->r24 = S32(ctx->r15 << 10);
    // 0x800C4B54: lh          $s0, 0x0($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X0);
    // 0x800C4B58: lh          $ra, 0x2($a1)
    ctx->r31 = MEM_H(ctx->r5, 0X2);
    // 0x800C4B5C: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x800C4B60: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C4B64: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C4B68: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C4B6C: addiu       $t8, $t8, 0x3C20
    ctx->r24 = ADD32(ctx->r24, 0X3C20);
    // 0x800C4B70: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C4B74: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C4B78: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C4B7C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C4B80: lw          $t9, -0x5258($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5258);
    // 0x800C4B84: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800C4B88: beq         $a1, $t9, L_800C4CF8
    if (ctx->r5 == ctx->r25) {
        // 0x800C4B8C: andi        $t6, $s3, 0x5
        ctx->r14 = ctx->r19 & 0X5;
            goto L_800C4CF8;
    }
    // 0x800C4B8C: andi        $t6, $s3, 0x5
    ctx->r14 = ctx->r19 & 0X5;
    // 0x800C4B90: lh          $a0, 0xA($a1)
    ctx->r4 = MEM_H(ctx->r5, 0XA);
    // 0x800C4B94: lh          $a1, 0x6($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X6);
    // 0x800C4B98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C4B9C: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x800C4BA0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C4BA4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800C4BA8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800C4BAC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4BB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C4BB4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800C4BB8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C4BBC: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800C4BC0: addu        $a2, $a1, $a0
    ctx->r6 = ADD32(ctx->r5, ctx->r4);
    // 0x800C4BC4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x800C4BC8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C4BCC: lh          $t7, 0x4($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X4);
    // 0x800C4BD0: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800C4BD4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800C4BD8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C4BDC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C4BE0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C4BE4: nop

    // 0x800C4BE8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800C4BEC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C4BF0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C4BF4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800C4BF8: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800C4BFC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C4C00: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C4C04: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800C4C08: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C4C0C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800C4C10: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C4C14: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800C4C18: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800C4C1C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x800C4C20: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C4C24: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800C4C28: subu        $t9, $a2, $v0
    ctx->r25 = SUB32(ctx->r6, ctx->r2);
    // 0x800C4C2C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800C4C30: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800C4C34: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C4C38: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800C4C3C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C4C40: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800C4C44: nop

    // 0x800C4C48: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800C4C4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C4C50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C4C54: nop

    // 0x800C4C58: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800C4C5C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800C4C60: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800C4C64: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800C4C68: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800C4C6C: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800C4C70: lh          $t7, 0x8($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X8);
    // 0x800C4C74: nop

    // 0x800C4C78: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800C4C7C: nop

    // 0x800C4C80: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C4C84: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800C4C88: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C4C8C: nop

    // 0x800C4C90: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800C4C94: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C4C98: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C4C9C: nop

    // 0x800C4CA0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800C4CA4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C4CA8: addu        $t8, $a2, $v0
    ctx->r24 = ADD32(ctx->r6, ctx->r2);
    // 0x800C4CAC: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800C4CB0: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800C4CB4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C4CB8: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800C4CBC: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800C4CC0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800C4CC4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800C4CC8: nop

    // 0x800C4CCC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800C4CD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C4CD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C4CD8: nop

    // 0x800C4CDC: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800C4CE0: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800C4CE4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800C4CE8: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800C4CEC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800C4CF0: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800C4CF4: andi        $t6, $s3, 0x5
    ctx->r14 = ctx->r19 & 0X5;
L_800C4CF8:
    // 0x800C4CF8: beq         $t6, $zero, L_800C4D3C
    if (ctx->r14 == 0) {
        // 0x800C4CFC: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800C4D3C;
    }
    // 0x800C4CFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C4D00: lbu         $a2, 0x1D($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X1D);
    // 0x800C4D04: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x800C4D08: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800C4D0C: jal         0x800C5300
    // 0x800C4D10: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    get_text_width(rdram, ctx);
        goto after_0;
    // 0x800C4D10: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    after_0:
    // 0x800C4D14: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800C4D18: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x800C4D1C: andi        $t7, $s3, 0x1
    ctx->r15 = ctx->r19 & 0X1;
    // 0x800C4D20: beq         $t7, $zero, L_800C4D34
    if (ctx->r15 == 0) {
        // 0x800C4D24: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800C4D34;
    }
    // 0x800C4D24: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800C4D28: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800C4D2C: b           L_800C4D3C
    // 0x800C4D30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800C4D3C;
    // 0x800C4D30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C4D34:
    // 0x800C4D34: sra         $t8, $v0, 1
    ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800C4D38: subu        $s0, $s0, $t8
    ctx->r16 = SUB32(ctx->r16, ctx->r24);
L_800C4D3C:
    // 0x800C4D3C: andi        $t9, $s3, 0x2
    ctx->r25 = ctx->r19 & 0X2;
    // 0x800C4D40: beq         $t9, $zero, L_800C4D58
    if (ctx->r25 == 0) {
        // 0x800C4D44: andi        $t7, $s3, 0x8
        ctx->r15 = ctx->r19 & 0X8;
            goto L_800C4D58;
    }
    // 0x800C4D44: andi        $t7, $s3, 0x8
    ctx->r15 = ctx->r19 & 0X8;
    // 0x800C4D48: lhu         $t6, 0x22($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X22);
    // 0x800C4D4C: nop

    // 0x800C4D50: subu        $ra, $ra, $t6
    ctx->r31 = SUB32(ctx->r31, ctx->r14);
    // 0x800C4D54: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
L_800C4D58:
    // 0x800C4D58: beq         $t7, $zero, L_800C4D70
    if (ctx->r15 == 0) {
        // 0x800C4D5C: nop
    
            goto L_800C4D70;
    }
    // 0x800C4D5C: nop

    // 0x800C4D60: lhu         $t8, 0x22($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X22);
    // 0x800C4D64: nop

    // 0x800C4D68: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800C4D6C: subu        $ra, $ra, $t9
    ctx->r31 = SUB32(ctx->r31, ctx->r25);
L_800C4D70:
    // 0x800C4D70: lbu         $t6, 0x1B($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X1B);
    // 0x800C4D74: nop

    // 0x800C4D78: beq         $t6, $zero, L_800C4EA4
    if (ctx->r14 == 0) {
        // 0x800C4D7C: nop
    
            goto L_800C4EA4;
    }
    // 0x800C4D7C: nop

    // 0x800C4D80: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4D84: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x800C4D88: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800C4D8C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C4D90: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C4D94: lbu         $t6, 0x18($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X18);
    // 0x800C4D98: lbu         $t9, 0x19($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X19);
    // 0x800C4D9C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800C4DA0: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800C4DA4: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800C4DA8: lbu         $t7, 0x1A($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1A);
    // 0x800C4DAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C4DB0: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800C4DB4: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800C4DB8: lbu         $t8, 0x1B($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X1B);
    // 0x800C4DBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C4DC0: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800C4DC4: bne         $s5, $at, L_800C4DEC
    if (ctx->r21 != ctx->r1) {
        // 0x800C4DC8: sw          $t6, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r14;
            goto L_800C4DEC;
    }
    // 0x800C4DC8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800C4DCC: lbu         $a2, 0x1D($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X1D);
    // 0x800C4DD0: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x800C4DD4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800C4DD8: jal         0x800C5300
    // 0x800C4DDC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    get_text_width(rdram, ctx);
        goto after_1;
    // 0x800C4DDC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    after_1:
    // 0x800C4DE0: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800C4DE4: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x800C4DE8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_800C4DEC:
    // 0x800C4DEC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4DF0: lhu         $t7, 0x22($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X22);
    // 0x800C4DF4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800C4DF8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C4DFC: lui         $t8, 0x702
    ctx->r24 = S32(0X702 << 16);
    // 0x800C4E00: lui         $t6, 0xE
    ctx->r14 = S32(0XE << 16);
    // 0x800C4E04: addiu       $t6, $t6, 0x3C68
    ctx->r14 = ADD32(ctx->r14, 0X3C68);
    // 0x800C4E08: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800C4E0C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C4E10: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800C4E14: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4E18: addu        $t1, $t7, $ra
    ctx->r9 = ADD32(ctx->r15, ctx->r31);
    // 0x800C4E1C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800C4E20: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C4E24: lh          $t9, 0x4($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X4);
    // 0x800C4E28: addu        $t8, $s0, $s5
    ctx->r24 = ADD32(ctx->r16, ctx->r21);
    // 0x800C4E2C: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x800C4E30: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800C4E34: andi        $t9, $t7, 0x3FF
    ctx->r25 = ctx->r15 & 0X3FF;
    // 0x800C4E38: lh          $t7, 0x6($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X6);
    // 0x800C4E3C: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x800C4E40: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800C4E44: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800C4E48: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800C4E4C: addu        $t9, $t1, $t7
    ctx->r25 = ADD32(ctx->r9, ctx->r15);
    // 0x800C4E50: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x800C4E54: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800C4E58: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800C4E5C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800C4E60: lh          $t8, 0x4($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X4);
    // 0x800C4E64: nop

    // 0x800C4E68: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x800C4E6C: lh          $t8, 0x6($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X6);
    // 0x800C4E70: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x800C4E74: sll         $t9, $t7, 14
    ctx->r25 = S32(ctx->r15 << 14);
    // 0x800C4E78: addu        $t6, $ra, $t8
    ctx->r14 = ADD32(ctx->r31, ctx->r24);
    // 0x800C4E7C: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x800C4E80: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C4E84: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800C4E88: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800C4E8C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4E90: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800C4E94: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800C4E98: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C4E9C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800C4EA0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_800C4EA4:
    // 0x800C4EA4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4EA8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800C4EAC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C4EB0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800C4EB4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C4EB8: lbu         $t9, 0x1C($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X1C);
    // 0x800C4EBC: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800C4EC0: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x800C4EC4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C4EC8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4ECC: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800C4ED0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C4ED4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C4ED8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C4EDC: lbu         $t8, 0x14($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X14);
    // 0x800C4EE0: lbu         $t9, 0x15($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X15);
    // 0x800C4EE4: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x800C4EE8: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800C4EEC: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800C4EF0: lbu         $t6, 0x16($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X16);
    // 0x800C4EF4: nop

    // 0x800C4EF8: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800C4EFC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800C4F00: lbu         $t7, 0x17($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X17);
    // 0x800C4F04: nop

    // 0x800C4F08: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800C4F0C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C4F10: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4F14: lui         $t7, 0xE
    ctx->r15 = S32(0XE << 16);
    // 0x800C4F18: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C4F1C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C4F20: lui         $t9, 0x702
    ctx->r25 = S32(0X702 << 16);
    // 0x800C4F24: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x800C4F28: addiu       $t7, $t7, 0x3C58
    ctx->r15 = ADD32(ctx->r15, 0X3C58);
    // 0x800C4F2C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800C4F30: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800C4F34: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4F38: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800C4F3C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C4F40: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800C4F44: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800C4F48: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C4F4C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800C4F50: lh          $t9, 0x20($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X20);
    // 0x800C4F54: lh          $t7, 0x22($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X22);
    // 0x800C4F58: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x800C4F5C: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x800C4F60: beq         $t6, $zero, L_800C5270
    if (ctx->r14 == 0) {
        // 0x800C4F64: addu        $ra, $ra, $t7
        ctx->r31 = ADD32(ctx->r31, ctx->r15);
            goto L_800C5270;
    }
    // 0x800C4F64: addu        $ra, $ra, $t7
    ctx->r31 = ADD32(ctx->r31, ctx->r15);
    // 0x800C4F68: lh          $t9, 0xA($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XA);
    // 0x800C4F6C: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800C4F70: slt         $at, $t9, $ra
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x800C4F74: bne         $at, $zero, L_800C5270
    if (ctx->r1 != 0) {
        // 0x800C4F78: addu        $s3, $t8, $zero
        ctx->r19 = ADD32(ctx->r24, 0);
            goto L_800C5270;
    }
    // 0x800C4F78: addu        $s3, $t8, $zero
    ctx->r19 = ADD32(ctx->r24, 0);
    // 0x800C4F7C: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800C4F80: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    // 0x800C4F84: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
L_800C4F88:
    // 0x800C4F88: slti        $at, $a0, 0x21
    ctx->r1 = SIGNED(ctx->r4) < 0X21 ? 1 : 0;
    // 0x800C4F8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C4F90: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800C4F94: bne         $at, $zero, L_800C4FA4
    if (ctx->r1 != 0) {
        // 0x800C4F98: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800C4FA4;
    }
    // 0x800C4F98: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C4F9C: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x800C4FA0: bne         $at, $zero, L_800C5054
    if (ctx->r1 != 0) {
        // 0x800C4FA4: addiu       $t7, $v1, -0x9
        ctx->r15 = ADD32(ctx->r3, -0X9);
            goto L_800C5054;
    }
L_800C4FA4:
    // 0x800C4FA4: addiu       $t7, $v1, -0x9
    ctx->r15 = ADD32(ctx->r3, -0X9);
    // 0x800C4FA8: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x800C4FAC: beq         $at, $zero, L_800C5048
    if (ctx->r1 == 0) {
        // 0x800C4FB0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800C5048;
    }
    // 0x800C4FB0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C4FB4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C4FB8: addu        $at, $at, $t7
    gpr jr_addend_800C4FC4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C4FBC: lw          $t7, -0x6720($at)
    ctx->r15 = ADD32(ctx->r1, -0X6720);
    // 0x800C4FC0: nop

    // 0x800C4FC4: jr          $t7
    // 0x800C4FC8: nop

    switch (jr_addend_800C4FC4 >> 2) {
        case 0: goto L_800C4FE8; break;
        case 1: goto L_800C4FD8; break;
        case 2: goto L_800C5030; break;
        case 3: goto L_800C5048; break;
        case 4: goto L_800C503C; break;
        case 5: goto L_800C5048; break;
        case 6: goto L_800C5048; break;
        case 7: goto L_800C5048; break;
        case 8: goto L_800C5048; break;
        case 9: goto L_800C5048; break;
        case 10: goto L_800C5048; break;
        case 11: goto L_800C5048; break;
        case 12: goto L_800C5048; break;
        case 13: goto L_800C5048; break;
        case 14: goto L_800C5048; break;
        case 15: goto L_800C5048; break;
        case 16: goto L_800C5048; break;
        case 17: goto L_800C5048; break;
        case 18: goto L_800C5048; break;
        case 19: goto L_800C5048; break;
        case 20: goto L_800C5048; break;
        case 21: goto L_800C5048; break;
        case 22: goto L_800C5048; break;
        case 23: goto L_800C4FCC; break;
        default: switch_error(__func__, 0x800C4FC4, 0x800E98E0);
    }
    // 0x800C4FC8: nop

L_800C4FCC:
    // 0x800C4FCC: lhu         $t6, 0x24($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X24);
    // 0x800C4FD0: b           L_800C5114
    // 0x800C4FD4: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
        goto L_800C5114;
    // 0x800C4FD4: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
L_800C4FD8:
    // 0x800C4FD8: lhu         $t9, 0x22($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X22);
    // 0x800C4FDC: lh          $s0, 0x20($s2)
    ctx->r16 = MEM_H(ctx->r18, 0X20);
    // 0x800C4FE0: b           L_800C5114
    // 0x800C4FE4: addu        $ra, $ra, $t9
    ctx->r31 = ADD32(ctx->r31, ctx->r25);
        goto L_800C5114;
    // 0x800C4FE4: addu        $ra, $ra, $t9
    ctx->r31 = ADD32(ctx->r31, ctx->r25);
L_800C4FE8:
    // 0x800C4FE8: lh          $t7, 0x20($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X20);
    // 0x800C4FEC: lhu         $v0, 0x26($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X26);
    // 0x800C4FF0: subu        $t6, $s0, $t7
    ctx->r14 = SUB32(ctx->r16, ctx->r15);
    // 0x800C4FF4: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800C4FF8: addu        $t8, $s0, $v0
    ctx->r24 = ADD32(ctx->r16, ctx->r2);
    // 0x800C4FFC: bne         $v0, $zero, L_800C5008
    if (ctx->r2 != 0) {
        // 0x800C5000: nop
    
            goto L_800C5008;
    }
    // 0x800C5000: nop

    // 0x800C5004: break       7
    do_break(2148290564);
L_800C5008:
    // 0x800C5008: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C500C: bne         $v0, $at, L_800C5020
    if (ctx->r2 != ctx->r1) {
        // 0x800C5010: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5020;
    }
    // 0x800C5010: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5014: bne         $t6, $at, L_800C5020
    if (ctx->r14 != ctx->r1) {
        // 0x800C5018: nop
    
            goto L_800C5020;
    }
    // 0x800C5018: nop

    // 0x800C501C: break       6
    do_break(2148290588);
L_800C5020:
    // 0x800C5020: mfhi        $t9
    ctx->r25 = hi;
    // 0x800C5024: subu        $s0, $t8, $t9
    ctx->r16 = SUB32(ctx->r24, ctx->r25);
    // 0x800C5028: b           L_800C5114
    // 0x800C502C: nop

        goto L_800C5114;
    // 0x800C502C: nop

L_800C5030:
    // 0x800C5030: lhu         $t7, 0x22($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X22);
    // 0x800C5034: b           L_800C5114
    // 0x800C5038: addu        $ra, $ra, $t7
    ctx->r31 = ADD32(ctx->r31, ctx->r15);
        goto L_800C5114;
    // 0x800C5038: addu        $ra, $ra, $t7
    ctx->r31 = ADD32(ctx->r31, ctx->r15);
L_800C503C:
    // 0x800C503C: lh          $s0, 0x20($s2)
    ctx->r16 = MEM_H(ctx->r18, 0X20);
    // 0x800C5040: b           L_800C5114
    // 0x800C5044: nop

        goto L_800C5114;
    // 0x800C5044: nop

L_800C5048:
    // 0x800C5048: lhu         $t6, 0x24($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X24);
    // 0x800C504C: b           L_800C5114
    // 0x800C5050: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
        goto L_800C5114;
    // 0x800C5050: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
L_800C5054:
    // 0x800C5054: addiu       $a0, $v1, -0x20
    ctx->r4 = ADD32(ctx->r3, -0X20);
    // 0x800C5058: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800C505C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800C5060: addu        $v0, $t3, $t9
    ctx->r2 = ADD32(ctx->r11, ctx->r25);
    // 0x800C5064: lbu         $a3, 0x100($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X100);
    // 0x800C5068: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C506C: beq         $a3, $at, L_800C5114
    if (ctx->r7 == ctx->r1) {
        // 0x800C5070: nop
    
            goto L_800C5114;
    }
    // 0x800C5070: nop

    // 0x800C5074: beq         $s4, $a3, L_800C50CC
    if (ctx->r20 == ctx->r7) {
        // 0x800C5078: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800C50CC;
    }
    // 0x800C5078: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C507C: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x800C5080: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C5084: addu        $t6, $t3, $t7
    ctx->r14 = ADD32(ctx->r11, ctx->r15);
    // 0x800C5088: lw          $a0, 0x80($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X80);
    // 0x800C508C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C5090: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800C5094: lh          $a2, 0xA($a0)
    ctx->r6 = MEM_H(ctx->r4, 0XA);
    // 0x800C5098: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800C509C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x800C50A0: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800C50A4: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x800C50A8: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800C50AC: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800C50B0: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800C50B4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C50B8: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x800C50BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C50C0: addu        $t6, $t8, $at
    ctx->r14 = ADD32(ctx->r24, ctx->r1);
    // 0x800C50C4: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800C50C8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_800C50CC:
    // 0x800C50CC: lbu         $t9, 0x102($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X102);
    // 0x800C50D0: nop

    // 0x800C50D4: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x800C50D8: lbu         $t7, 0x103($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X103);
    // 0x800C50DC: nop

    // 0x800C50E0: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x800C50E4: lbu         $t8, 0x107($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X107);
    // 0x800C50E8: lbu         $t4, 0x104($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X104);
    // 0x800C50EC: lbu         $t5, 0x105($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X105);
    // 0x800C50F0: lbu         $s5, 0x106($v0)
    ctx->r21 = MEM_BU(ctx->r2, 0X106);
    // 0x800C50F4: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800C50F8: lhu         $v1, 0x20($t3)
    ctx->r3 = MEM_HU(ctx->r11, 0X20);
    // 0x800C50FC: nop

    // 0x800C5100: bne         $v1, $zero, L_800C5114
    if (ctx->r3 != 0) {
        // 0x800C5104: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_800C5114;
    }
    // 0x800C5104: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x800C5108: lbu         $t0, 0x101($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X101);
    // 0x800C510C: b           L_800C5114
    // 0x800C5110: nop

        goto L_800C5114;
    // 0x800C5110: nop

L_800C5114:
    // 0x800C5114: beq         $a1, $zero, L_800C5224
    if (ctx->r5 == 0) {
        // 0x800C5118: lui         $at, 0xE400
        ctx->r1 = S32(0XE400 << 16);
            goto L_800C5224;
    }
    // 0x800C5118: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800C511C: lh          $t6, 0x4($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X4);
    // 0x800C5120: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800C5124: addu        $t9, $t6, $s0
    ctx->r25 = ADD32(ctx->r14, ctx->r16);
    // 0x800C5128: lh          $t6, 0x6($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X6);
    // 0x800C512C: addu        $a1, $t9, $t7
    ctx->r5 = ADD32(ctx->r25, ctx->r15);
    // 0x800C5130: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800C5134: addu        $t9, $t6, $ra
    ctx->r25 = ADD32(ctx->r14, ctx->r31);
    // 0x800C5138: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800C513C: addu        $a2, $t9, $t7
    ctx->r6 = ADD32(ctx->r25, ctx->r15);
    // 0x800C5140: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5144: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800C5148: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800C514C: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x800C5150: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800C5154: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800C5158: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x800C515C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800C5160: sll         $t8, $t4, 5
    ctx->r24 = S32(ctx->r12 << 5);
    // 0x800C5164: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x800C5168: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800C516C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800C5170: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x800C5174: bgez        $a1, L_800C5190
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800C5178: or          $t5, $t6, $zero
        ctx->r13 = ctx->r14 | 0;
            goto L_800C5190;
    }
    // 0x800C5178: or          $t5, $t6, $zero
    ctx->r13 = ctx->r14 | 0;
    // 0x800C517C: blez        $v0, L_800C5190
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C5180: negu        $t9, $a1
        ctx->r25 = SUB32(0, ctx->r5);
            goto L_800C5190;
    }
    // 0x800C5180: negu        $t9, $a1
    ctx->r25 = SUB32(0, ctx->r5);
    // 0x800C5184: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x800C5188: addu        $t4, $t8, $t7
    ctx->r12 = ADD32(ctx->r24, ctx->r15);
    // 0x800C518C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800C5190:
    // 0x800C5190: bgez        $a2, L_800C51AC
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C5194: andi        $t7, $t2, 0xFFF
        ctx->r15 = ctx->r10 & 0XFFF;
            goto L_800C51AC;
    }
    // 0x800C5194: andi        $t7, $t2, 0xFFF
    ctx->r15 = ctx->r10 & 0XFFF;
    // 0x800C5198: blez        $v1, L_800C51AC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C519C: negu        $t8, $a2
        ctx->r24 = SUB32(0, ctx->r6);
            goto L_800C51AC;
    }
    // 0x800C519C: negu        $t8, $a2
    ctx->r24 = SUB32(0, ctx->r6);
    // 0x800C51A0: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x800C51A4: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x800C51A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800C51AC:
    // 0x800C51AC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C51B0: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800C51B4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800C51B8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C51BC: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x800C51C0: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800C51C4: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800C51C8: andi        $t8, $a1, 0xFFF
    ctx->r24 = ctx->r5 & 0XFFF;
    // 0x800C51CC: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800C51D0: andi        $t9, $a2, 0xFFF
    ctx->r25 = ctx->r6 & 0XFFF;
    // 0x800C51D4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C51D8: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800C51DC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800C51E0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C51E4: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x800C51E8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C51EC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800C51F0: andi        $t8, $t5, 0xFFFF
    ctx->r24 = ctx->r13 & 0XFFFF;
    // 0x800C51F4: sll         $t7, $t4, 16
    ctx->r15 = S32(ctx->r12 << 16);
    // 0x800C51F8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C51FC: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800C5200: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800C5204: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800C5208: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800C520C: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800C5210: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C5214: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x800C5218: lui         $t7, 0xB200
    ctx->r15 = S32(0XB200 << 16);
    // 0x800C521C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800C5220: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
L_800C5224:
    // 0x800C5224: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5228: lw          $t6, -0x5250($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5250);
    // 0x800C522C: nop

    // 0x800C5230: beq         $t6, $zero, L_800C5244
    if (ctx->r14 == 0) {
        // 0x800C5234: nop
    
            goto L_800C5244;
    }
    // 0x800C5234: nop

    // 0x800C5238: beq         $t0, $zero, L_800C5244
    if (ctx->r8 == 0) {
        // 0x800C523C: nop
    
            goto L_800C5244;
    }
    // 0x800C523C: nop

    // 0x800C5240: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800C5244:
    // 0x800C5244: lbu         $v0, 0x1($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1);
    // 0x800C5248: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x800C524C: beq         $v0, $zero, L_800C5270
    if (ctx->r2 == 0) {
        // 0x800C5250: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800C5270;
    }
    // 0x800C5250: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800C5254: lh          $t9, 0xA($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XA);
    // 0x800C5258: nop

    // 0x800C525C: slt         $at, $t9, $ra
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x800C5260: beq         $at, $zero, L_800C4F88
    if (ctx->r1 == 0) {
        // 0x800C5264: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_800C4F88;
    }
    // 0x800C5264: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x800C5268: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    // 0x800C526C: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
L_800C5270:
    // 0x800C5270: lh          $t7, 0x20($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X20);
    // 0x800C5274: lh          $t6, 0x22($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X22);
    // 0x800C5278: subu        $t8, $s0, $t7
    ctx->r24 = SUB32(ctx->r16, ctx->r15);
    // 0x800C527C: subu        $t9, $ra, $t6
    ctx->r25 = SUB32(ctx->r31, ctx->r14);
    // 0x800C5280: sh          $t8, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r24;
    // 0x800C5284: sh          $t9, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r25;
    // 0x800C5288: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C528C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800C5290: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800C5294: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C5298: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C529C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800C52A0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C52A4: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C52A8: nop

    // 0x800C52AC: beq         $s2, $t6, L_800C52BC
    if (ctx->r18 == ctx->r14) {
        // 0x800C52B0: nop
    
            goto L_800C52BC;
    }
    // 0x800C52B0: nop

    // 0x800C52B4: jal         0x80067C7C
    // 0x800C52B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    viewport_scissor(rdram, ctx);
        goto after_2;
    // 0x800C52B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
L_800C52BC:
    // 0x800C52BC: jal         0x8007B820
    // 0x800C52C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    rendermode_reset(rdram, ctx);
        goto after_3;
    // 0x800C52C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800C52C4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C52C8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800C52CC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800C52D0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C52D4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800C52D8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800C52DC:
    // 0x800C52DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C52E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C52E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C52E8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C52EC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C52F0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800C52F4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800C52F8: jr          $ra
    // 0x800C52FC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800C52FC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void gameselect_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CB50: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008CB54: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008CB58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008CB5C: slti        $at, $v0, -0x15
    ctx->r1 = SIGNED(ctx->r2) < -0X15 ? 1 : 0;
    // 0x8008CB60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CB64: bne         $at, $zero, L_8008CC64
    if (ctx->r1 != 0) {
        // 0x8008CB68: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8008CC64;
    }
    // 0x8008CB68: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008CB6C: slti        $at, $v0, 0x16
    ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
    // 0x8008CB70: beq         $at, $zero, L_8008CC64
    if (ctx->r1 == 0) {
        // 0x8008CB74: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8008CC64;
    }
    // 0x8008CB74: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008CB78: lw          $a2, 0x695C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X695C);
    // 0x8008CB7C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008CB80: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x8008CB84: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x8008CB88: bne         $at, $zero, L_8008CB98
    if (ctx->r1 != 0) {
        // 0x8008CB8C: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_8008CB98;
    }
    // 0x8008CB8C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8008CB90: addiu       $t7, $zero, 0x1FF
    ctx->r15 = ADD32(0, 0X1FF);
    // 0x8008CB94: subu        $a2, $t7, $t6
    ctx->r6 = SUB32(ctx->r15, ctx->r14);
L_8008CB98:
    // 0x8008CB98: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008CB9C: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8008CBA0: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8008CBA4: jal         0x8006816C
    // 0x8008CBA8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x8008CBA8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8008CBAC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008CBB0: addiu       $a0, $a0, 0x6980
    ctx->r4 = ADD32(ctx->r4, 0X6980);
    // 0x8008CBB4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8008CBB8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CBBC: bltz        $t8, L_8008CC0C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8008CBC0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008CC0C;
    }
    // 0x8008CBC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008CBC4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008CBC8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008CBCC: addiu       $a1, $a1, -0x620
    ctx->r5 = ADD32(ctx->r5, -0X620);
    // 0x8008CBD0: addiu       $a3, $a3, 0x6A00
    ctx->r7 = ADD32(ctx->r7, 0X6A00);
L_8008CBD4:
    // 0x8008CBD4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8008CBD8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008CBDC: bne         $v0, $t9, L_8008CBE8
    if (ctx->r2 != ctx->r25) {
        // 0x8008CBE0: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8008CBE8;
    }
    // 0x8008CBE0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8008CBE4: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_8008CBE8:
    // 0x8008CBE8: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x8008CBEC: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x8008CBF0: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8008CBF4: sb          $v1, 0x6F($t3)
    MEM_B(0X6F, ctx->r11) = ctx->r3;
    // 0x8008CBF8: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8008CBFC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008CC00: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008CC04: beq         $at, $zero, L_8008CBD4
    if (ctx->r1 == 0) {
        // 0x8008CC08: nop
    
            goto L_8008CBD4;
    }
    // 0x8008CC08: nop

L_8008CC0C:
    // 0x8008CC0C: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x8008CC10: lw          $t5, 0x300($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X300);
    // 0x8008CC14: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008CC18: bne         $t5, $zero, L_8008CC38
    if (ctx->r13 != 0) {
        // 0x8008CC1C: addiu       $a3, $a3, 0x6A00
        ctx->r7 = ADD32(ctx->r7, 0X6A00);
            goto L_8008CC38;
    }
    // 0x8008CC1C: addiu       $a3, $a3, 0x6A00
    ctx->r7 = ADD32(ctx->r7, 0X6A00);
    // 0x8008CC20: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8008CC24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CC28: sw          $t6, -0x2E4($at)
    MEM_W(-0X2E4, ctx->r1) = ctx->r14;
    // 0x8008CC2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CC30: b           L_8008CC48
    // 0x8008CC34: sw          $zero, -0x2E0($at)
    MEM_W(-0X2E0, ctx->r1) = 0;
        goto L_8008CC48;
    // 0x8008CC34: sw          $zero, -0x2E0($at)
    MEM_W(-0X2E0, ctx->r1) = 0;
L_8008CC38:
    // 0x8008CC38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CC3C: sw          $zero, -0x2E4($at)
    MEM_W(-0X2E4, ctx->r1) = 0;
    // 0x8008CC40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CC44: sw          $zero, -0x2E0($at)
    MEM_W(-0X2E0, ctx->r1) = 0;
L_8008CC48:
    // 0x8008CC48: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x8008CC4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008CC50: jal         0x8008263C
    // 0x8008CC54: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    draw_menu_elements(rdram, ctx);
        goto after_1;
    // 0x8008CC54: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x8008CC58: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008CC5C: jal         0x80081018
    // 0x8008CC60: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    func_80080BC8(rdram, ctx);
        goto after_2;
    // 0x8008CC60: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_2:
L_8008CC64:
    // 0x8008CC64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CC68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008CC6C: jr          $ra
    // 0x8008CC70: nop

    return;
    // 0x8008CC70: nop

;}
RECOMP_FUNC void tt_ghost_beaten(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B3F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B3FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B400: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001B404: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B408: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001B40C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001B410: jal         0x80059B9C
    // 0x8001B414: sw          $zero, -0x3378($at)
    MEM_W(-0X3378, ctx->r1) = 0;
    timetrial_free_staff_ghost(rdram, ctx);
        goto after_0;
    // 0x8001B414: sw          $zero, -0x3378($at)
    MEM_W(-0X3378, ctx->r1) = 0;
    after_0:
    // 0x8001B418: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B41C: sb          $zero, -0x335C($at)
    MEM_B(-0X335C, ctx->r1) = 0;
    // 0x8001B420: jal         0x8001E2D0
    // 0x8001B424: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8001B424: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_1:
    // 0x8001B428: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8001B42C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8001B430: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001B434: beq         $a3, $t6, L_8001B470
    if (ctx->r7 == ctx->r14) {
        // 0x8001B438: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001B470;
    }
    // 0x8001B438: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001B43C: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x8001B440: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8001B444: beq         $s0, $t7, L_8001B470
    if (ctx->r16 == ctx->r15) {
        // 0x8001B448: nop
    
            goto L_8001B470;
    }
    // 0x8001B448: nop

L_8001B44C:
    // 0x8001B44C: lb          $t8, 0x1($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X1);
    // 0x8001B450: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001B454: beq         $a3, $t8, L_8001B470
    if (ctx->r7 == ctx->r24) {
        // 0x8001B458: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8001B470;
    }
    // 0x8001B458: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001B45C: addu        $t9, $a1, $a2
    ctx->r25 = ADD32(ctx->r5, ctx->r6);
    // 0x8001B460: lb          $t0, 0x0($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X0);
    // 0x8001B464: nop

    // 0x8001B468: bne         $s0, $t0, L_8001B44C
    if (ctx->r16 != ctx->r8) {
        // 0x8001B46C: nop
    
            goto L_8001B44C;
    }
    // 0x8001B46C: nop

L_8001B470:
    // 0x8001B470: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8001B474: addiu       $s0, $s0, -0x3358
    ctx->r16 = ADD32(ctx->r16, -0X3358);
    // 0x8001B478: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x8001B47C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8001B480: beq         $t1, $zero, L_8001B514
    if (ctx->r9 == 0) {
        // 0x8001B484: sllv        $a1, $t2, $a2
        ctx->r5 = S32(ctx->r10 << (ctx->r6 & 31));
            goto L_8001B514;
    }
    // 0x8001B484: sllv        $a1, $t2, $a2
    ctx->r5 = S32(ctx->r10 << (ctx->r6 & 31));
    // 0x8001B488: jal         0x8009EFBC
    // 0x8001B48C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    set_eeprom_settings_value(rdram, ctx);
        goto after_2;
    // 0x8001B48C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_2:
    // 0x8001B490: jal         0x8009F04C
    // 0x8001B494: nop

    get_eeprom_settings(rdram, ctx);
        goto after_3;
    // 0x8001B494: nop

    after_3:
    // 0x8001B498: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8001B49C: ori         $at, $at, 0xFFF0
    ctx->r1 = ctx->r1 | 0XFFF0;
    // 0x8001B4A0: and         $t5, $v1, $at
    ctx->r13 = ctx->r3 & ctx->r1;
    // 0x8001B4A4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8001B4A8: ori         $at, $at, 0xFFF0
    ctx->r1 = ctx->r1 | 0XFFF0;
    // 0x8001B4AC: bne         $t5, $at, L_8001B4EC
    if (ctx->r13 != ctx->r1) {
        // 0x8001B4B0: addiu       $a0, $zero, 0x24C
        ctx->r4 = ADD32(0, 0X24C);
            goto L_8001B4EC;
    }
    // 0x8001B4B0: addiu       $a0, $zero, 0x24C
    ctx->r4 = ADD32(0, 0X24C);
    // 0x8001B4B4: jal         0x8009C824
    // 0x8001B4B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_magic_code_flags(rdram, ctx);
        goto after_4;
    // 0x8001B4B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8001B4BC: addiu       $a0, $zero, 0x24E
    ctx->r4 = ADD32(0, 0X24E);
    // 0x8001B4C0: jal         0x80001D04
    // 0x8001B4C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8001B4C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8001B4C8: addiu       $a0, $zero, 0x24F
    ctx->r4 = ADD32(0, 0X24F);
    // 0x8001B4CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001B4D0: jal         0x80000FDC
    // 0x8001B4D4: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_6;
    // 0x8001B4D4: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_6:
    // 0x8001B4D8: jal         0x800C3744
    // 0x8001B4DC: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    set_current_text(rdram, ctx);
        goto after_7;
    // 0x8001B4DC: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_7:
    // 0x8001B4E0: b           L_8001B50C
    // 0x8001B4E4: nop

        goto L_8001B50C;
    // 0x8001B4E4: nop

    // 0x8001B4E8: addiu       $a0, $zero, 0x24C
    ctx->r4 = ADD32(0, 0X24C);
L_8001B4EC:
    // 0x8001B4EC: jal         0x80001D04
    // 0x8001B4F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x8001B4F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8001B4F4: addiu       $a0, $zero, 0x24D
    ctx->r4 = ADD32(0, 0X24D);
    // 0x8001B4F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001B4FC: jal         0x80000FDC
    // 0x8001B500: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_9;
    // 0x8001B500: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_9:
    // 0x8001B504: jal         0x800C3744
    // 0x8001B508: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    set_current_text(rdram, ctx);
        goto after_10;
    // 0x8001B508: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_10:
L_8001B50C:
    // 0x8001B50C: b           L_8001B520
    // 0x8001B510: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_8001B520;
    // 0x8001B510: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8001B514:
    // 0x8001B514: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001B518: jal         0x800A72FC
    // 0x8001B51C: nop

    hud_time_trial_message(rdram, ctx);
        goto after_11;
    // 0x8001B51C: nop

    after_11:
L_8001B520:
    // 0x8001B520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B524: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001B528: jr          $ra
    // 0x8001B52C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001B52C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void init_object_shading(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F7EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000F7F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000F7F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000F7F8: lw          $t0, 0x40($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X40);
    // 0x8000F7FC: sw          $a1, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r5;
    // 0x8000F800: lb          $v0, 0x53($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X53);
    // 0x8000F804: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000F808: bne         $v0, $zero, L_8000F948
    if (ctx->r2 != 0) {
        // 0x8000F80C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8000F948;
    }
    // 0x8000F80C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000F810: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    // 0x8000F814: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000F818: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000F81C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000F820: bne         $t6, $zero, L_8000F83C
    if (ctx->r14 != 0) {
        // 0x8000F824: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_8000F83C;
    }
    // 0x8000F824: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
L_8000F828:
    // 0x8000F828: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8000F82C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000F830: beq         $t7, $zero, L_8000F828
    if (ctx->r15 == 0) {
        // 0x8000F834: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8000F828;
    }
    // 0x8000F834: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000F838: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
L_8000F83C:
    // 0x8000F83C: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8000F840: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8000F844: nop

    // 0x8000F848: beq         $v0, $zero, L_8000F978
    if (ctx->r2 == 0) {
        // 0x8000F84C: nop
    
            goto L_8000F978;
    }
    // 0x8000F84C: nop

    // 0x8000F850: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8000F854: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8000F858: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8000F85C: nop

    // 0x8000F860: beq         $t2, $zero, L_8000F978
    if (ctx->r10 == 0) {
        // 0x8000F864: nop
    
            goto L_8000F978;
    }
    // 0x8000F864: nop

    // 0x8000F868: lh          $t3, 0x3E($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X3E);
    // 0x8000F86C: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x8000F870: lw          $a1, 0x28($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X28);
    // 0x8000F874: lw          $a2, 0x2C($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X2C);
    // 0x8000F878: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8000F87C: lh          $t4, 0x40($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X40);
    // 0x8000F880: jal         0x8001D4E8
    // 0x8000F884: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    set_shading_properties(rdram, ctx);
        goto after_0;
    // 0x8000F884: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_0:
    // 0x8000F888: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x8000F88C: nop

    // 0x8000F890: lbu         $t5, 0x3D($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X3D);
    // 0x8000F894: nop

    // 0x8000F898: beq         $t5, $zero, L_8000F940
    if (ctx->r13 == 0) {
        // 0x8000F89C: nop
    
            goto L_8000F940;
    }
    // 0x8000F89C: nop

    // 0x8000F8A0: lbu         $t6, 0x3A($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X3A);
    // 0x8000F8A4: lw          $t7, 0x54($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X54);
    // 0x8000F8A8: nop

    // 0x8000F8AC: sb          $t6, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r14;
    // 0x8000F8B0: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x8000F8B4: lw          $t1, 0x54($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X54);
    // 0x8000F8B8: lbu         $t9, 0x3B($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3B);
    // 0x8000F8BC: nop

    // 0x8000F8C0: sb          $t9, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r25;
    // 0x8000F8C4: lw          $t2, 0x40($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X40);
    // 0x8000F8C8: lw          $t4, 0x54($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X54);
    // 0x8000F8CC: lbu         $t3, 0x3C($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3C);
    // 0x8000F8D0: nop

    // 0x8000F8D4: sb          $t3, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r11;
    // 0x8000F8D8: lw          $t5, 0x40($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X40);
    // 0x8000F8DC: lw          $t7, 0x54($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X54);
    // 0x8000F8E0: lbu         $t6, 0x3D($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X3D);
    // 0x8000F8E4: nop

    // 0x8000F8E8: sb          $t6, 0x7($t7)
    MEM_B(0X7, ctx->r15) = ctx->r14;
    // 0x8000F8EC: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x8000F8F0: nop

    // 0x8000F8F4: lh          $t8, 0x1C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X1C);
    // 0x8000F8F8: nop

    // 0x8000F8FC: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8000F900: negu        $t1, $t9
    ctx->r9 = SUB32(0, ctx->r25);
    // 0x8000F904: sh          $t1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r9;
    // 0x8000F908: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x8000F90C: nop

    // 0x8000F910: lh          $t2, 0x1E($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X1E);
    // 0x8000F914: nop

    // 0x8000F918: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8000F91C: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8000F920: sh          $t4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r12;
    // 0x8000F924: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x8000F928: nop

    // 0x8000F92C: lh          $t5, 0x20($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X20);
    // 0x8000F930: nop

    // 0x8000F934: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8000F938: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8000F93C: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
L_8000F940:
    // 0x8000F940: b           L_8000F978
    // 0x8000F944: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
        goto L_8000F978;
    // 0x8000F944: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
L_8000F948:
    // 0x8000F948: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000F94C: bne         $v0, $at, L_8000F978
    if (ctx->r2 != ctx->r1) {
        // 0x8000F950: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8000F978;
    }
    // 0x8000F950: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000F954: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000F958: lw          $t8, 0x54($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X54);
    // 0x8000F95C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8000F960: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x8000F964: sb          $v0, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r2;
    // 0x8000F968: sb          $v0, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r2;
    // 0x8000F96C: sb          $v0, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r2;
    // 0x8000F970: sb          $zero, 0x7($a1)
    MEM_B(0X7, ctx->r5) = 0;
    // 0x8000F974: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
L_8000F978:
    // 0x8000F978: bne         $a2, $zero, L_8000F984
    if (ctx->r6 != 0) {
        // 0x8000F97C: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_8000F984;
    }
    // 0x8000F97C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8000F980: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
L_8000F984:
    // 0x8000F984: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000F988: and         $v0, $a2, $at
    ctx->r2 = ctx->r6 & ctx->r1;
    // 0x8000F98C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000F990: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000F994: jr          $ra
    // 0x8000F998: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8000F998: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
;}
RECOMP_FUNC void fileselect_input_root(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DAB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008DAB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DAB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008DABC: jal         0x8006A794
    // 0x8008DAC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8008DAC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8008DAC4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008DAC8: lw          $t6, -0x5C4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C4);
    // 0x8008DACC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DAD0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008DAD4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8008DAD8: lb          $a2, 0x69FC($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X69FC);
    // 0x8008DADC: lb          $a3, 0x6A04($a3)
    ctx->r7 = MEM_B(ctx->r7, 0X6A04);
    // 0x8008DAE0: bne         $t0, $t6, L_8008DB28
    if (ctx->r8 != ctx->r14) {
        // 0x8008DAE4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008DB28;
    }
    // 0x8008DAE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008DAE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008DAEC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8008DAF0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008DAF4: jal         0x8006A794
    // 0x8008DAF8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8008DAF8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8008DAFC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008DB00: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008DB04: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8008DB08: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008DB0C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DB10: lb          $t7, 0x69FD($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X69FD);
    // 0x8008DB14: lb          $t8, 0x6A05($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X6A05);
    // 0x8008DB18: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8008DB1C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008DB20: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8008DB24: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
L_8008DB28:
    // 0x8008DB28: andi        $t9, $v1, 0x9000
    ctx->r25 = ctx->r3 & 0X9000;
    // 0x8008DB2C: beq         $t9, $zero, L_8008DC48
    if (ctx->r25 == 0) {
        // 0x8008DB30: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8008DC48;
    }
    // 0x8008DB30: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008DB34: addiu       $t1, $t1, 0x6980
    ctx->r9 = ADD32(ctx->r9, 0X6980);
    // 0x8008DB38: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8008DB3C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008DB40: beq         $v0, $zero, L_8008DB64
    if (ctx->r2 == 0) {
        // 0x8008DB44: addiu       $t3, $t3, -0x5B4
        ctx->r11 = ADD32(ctx->r11, -0X5B4);
            goto L_8008DB64;
    }
    // 0x8008DB44: addiu       $t3, $t3, -0x5B4
    ctx->r11 = ADD32(ctx->r11, -0X5B4);
    // 0x8008DB48: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008DB4C: beq         $v0, $t2, L_8008DBD4
    if (ctx->r2 == ctx->r10) {
        // 0x8008DB50: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008DBD4;
    }
    // 0x8008DB50: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008DB54: beq         $v0, $t0, L_8008DC10
    if (ctx->r2 == ctx->r8) {
        // 0x8008DB58: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008DC10;
    }
    // 0x8008DB58: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008DB5C: b           L_8008DC5C
    // 0x8008DB60: nop

        goto L_8008DC5C;
    // 0x8008DB60: nop

L_8008DB64:
    // 0x8008DB64: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8008DB68: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008DB6C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8008DB70: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8008DB74: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008DB78: addiu       $t6, $t6, 0x6A40
    ctx->r14 = ADD32(ctx->r14, 0X6A40);
    // 0x8008DB7C: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8008DB80: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x8008DB84: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008DB88: beq         $t7, $zero, L_8008DBC4
    if (ctx->r15 == 0) {
        // 0x8008DB8C: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008DBC4;
    }
    // 0x8008DB8C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008DB90: lw          $t8, -0x5EC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5EC);
    // 0x8008DB94: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8008DB98: addiu       $a0, $zero, 0x15C
    ctx->r4 = ADD32(0, 0X15C);
    // 0x8008DB9C: beq         $t8, $t9, L_8008DBC0
    if (ctx->r24 == ctx->r25) {
        // 0x8008DBA0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8008DBC0;
    }
    // 0x8008DBA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008DBA4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008DBA8: jal         0x80001D04
    // 0x8008DBAC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008DBAC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8008DBB0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008DBB4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DBB8: b           L_8008DC5C
    // 0x8008DBBC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
        goto L_8008DC5C;
    // 0x8008DBBC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_8008DBC0:
    // 0x8008DBC0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
L_8008DBC4:
    // 0x8008DBC4: jal         0x80001D04
    // 0x8008DBC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x8008DBC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8008DBCC: b           L_8008DD64
    // 0x8008DBD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008DD64;
    // 0x8008DBD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008DBD4:
    // 0x8008DBD4: jal         0x80001D04
    // 0x8008DBD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8008DBD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8008DBDC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008DBE0: addiu       $t3, $t3, -0x5B4
    ctx->r11 = ADD32(ctx->r11, -0X5B4);
    // 0x8008DBE4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8008DBE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DBEC: sw          $t4, 0x6A2C($at)
    MEM_W(0X6A2C, ctx->r1) = ctx->r12;
    // 0x8008DBF0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008DBF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DBF8: sw          $t2, 0x6A24($at)
    MEM_W(0X6A24, ctx->r1) = ctx->r10;
    // 0x8008DBFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DC00: sw          $zero, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = 0;
    // 0x8008DC04: b           L_8008DD64
    // 0x8008DC08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008DD64;
    // 0x8008DC08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008DC0C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
L_8008DC10:
    // 0x8008DC10: jal         0x80001D04
    // 0x8008DC14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8008DC14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8008DC18: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008DC1C: addiu       $t3, $t3, -0x5B4
    ctx->r11 = ADD32(ctx->r11, -0X5B4);
    // 0x8008DC20: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8008DC24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DC28: sw          $t5, 0x6A2C($at)
    MEM_W(0X6A2C, ctx->r1) = ctx->r13;
    // 0x8008DC2C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008DC30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DC34: sw          $t2, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r10;
    // 0x8008DC38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DC3C: sw          $zero, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = 0;
    // 0x8008DC40: b           L_8008DD64
    // 0x8008DC44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008DD64;
    // 0x8008DC44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008DC48:
    // 0x8008DC48: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
    // 0x8008DC4C: beq         $t6, $zero, L_8008DC5C
    if (ctx->r14 == 0) {
        // 0x8008DC50: nop
    
            goto L_8008DC5C;
    }
    // 0x8008DC50: nop

    // 0x8008DC54: b           L_8008DD64
    // 0x8008DC58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8008DD64;
    // 0x8008DC58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8008DC5C:
    // 0x8008DC5C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008DC60: addiu       $t1, $t1, 0x6980
    ctx->r9 = ADD32(ctx->r9, 0X6980);
    // 0x8008DC64: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008DC68: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8008DC6C: addiu       $t3, $t3, -0x5B4
    ctx->r11 = ADD32(ctx->r11, -0X5B4);
    // 0x8008DC70: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8008DC74: sll         $t7, $v0, 8
    ctx->r15 = S32(ctx->r2 << 8);
    // 0x8008DC78: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008DC7C: bne         $v0, $zero, L_8008DCD8
    if (ctx->r2 != 0) {
        // 0x8008DC80: or          $a0, $t7, $v1
        ctx->r4 = ctx->r15 | ctx->r3;
            goto L_8008DCD8;
    }
    // 0x8008DC80: or          $a0, $t7, $v1
    ctx->r4 = ctx->r15 | ctx->r3;
    // 0x8008DC84: bgez        $a2, L_8008DC9C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008DC88: nop
    
            goto L_8008DC9C;
    }
    // 0x8008DC88: nop

    // 0x8008DC8C: blez        $v1, L_8008DC9C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8008DC90: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_8008DC9C;
    }
    // 0x8008DC90: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x8008DC94: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8008DC98: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8008DC9C:
    // 0x8008DC9C: blez        $a2, L_8008DCB4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008DCA0: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8008DCB4;
    }
    // 0x8008DCA0: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8008DCA4: beq         $at, $zero, L_8008DCB4
    if (ctx->r1 == 0) {
        // 0x8008DCA8: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_8008DCB4;
    }
    // 0x8008DCA8: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8008DCAC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8008DCB0: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_8008DCB4:
    // 0x8008DCB4: bgez        $a3, L_8008DD48
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8008DCB8: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8008DD48;
    }
    // 0x8008DCB8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8008DCBC: bne         $at, $zero, L_8008DCD0
    if (ctx->r1 != 0) {
        // 0x8008DCC0: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8008DCD0;
    }
    // 0x8008DCC0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8008DCC4: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8008DCC8: b           L_8008DD48
    // 0x8008DCCC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8008DD48;
    // 0x8008DCCC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8008DCD0:
    // 0x8008DCD0: b           L_8008DD48
    // 0x8008DCD4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
        goto L_8008DD48;
    // 0x8008DCD4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
L_8008DCD8:
    // 0x8008DCD8: bgez        $a2, L_8008DCF0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008DCDC: nop
    
            goto L_8008DCF0;
    }
    // 0x8008DCDC: nop

    // 0x8008DCE0: bne         $t0, $v0, L_8008DCF0
    if (ctx->r8 != ctx->r2) {
        // 0x8008DCE4: nop
    
            goto L_8008DCF0;
    }
    // 0x8008DCE4: nop

    // 0x8008DCE8: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x8008DCEC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8008DCF0:
    // 0x8008DCF0: blez        $a2, L_8008DD08
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008DCF4: nop
    
            goto L_8008DD08;
    }
    // 0x8008DCF4: nop

    // 0x8008DCF8: bne         $t2, $v0, L_8008DD08
    if (ctx->r10 != ctx->r2) {
        // 0x8008DCFC: nop
    
            goto L_8008DD08;
    }
    // 0x8008DCFC: nop

    // 0x8008DD00: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8008DD04: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8008DD08:
    // 0x8008DD08: blez        $a3, L_8008DD4C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8008DD0C: sll         $t4, $v0, 8
        ctx->r12 = S32(ctx->r2 << 8);
            goto L_8008DD4C;
    }
    // 0x8008DD0C: sll         $t4, $v0, 8
    ctx->r12 = S32(ctx->r2 << 8);
    // 0x8008DD10: bne         $t2, $v0, L_8008DD28
    if (ctx->r10 != ctx->r2) {
        // 0x8008DD14: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8008DD28;
    }
    // 0x8008DD14: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8008DD18: bne         $at, $zero, L_8008DD28
    if (ctx->r1 != 0) {
        // 0x8008DD1C: nop
    
            goto L_8008DD28;
    }
    // 0x8008DD1C: nop

    // 0x8008DD20: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8008DD24: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8008DD28:
    // 0x8008DD28: bne         $t0, $v0, L_8008DD40
    if (ctx->r8 != ctx->r2) {
        // 0x8008DD2C: nop
    
            goto L_8008DD40;
    }
    // 0x8008DD2C: nop

    // 0x8008DD30: bgtz        $v1, L_8008DD40
    if (SIGNED(ctx->r3) > 0) {
        // 0x8008DD34: nop
    
            goto L_8008DD40;
    }
    // 0x8008DD34: nop

    // 0x8008DD38: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x8008DD3C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_8008DD40:
    // 0x8008DD40: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8008DD44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008DD48:
    // 0x8008DD48: sll         $t4, $v0, 8
    ctx->r12 = S32(ctx->r2 << 8);
L_8008DD4C:
    // 0x8008DD4C: or          $t5, $t4, $v1
    ctx->r13 = ctx->r12 | ctx->r3;
    // 0x8008DD50: beq         $a0, $t5, L_8008DD60
    if (ctx->r4 == ctx->r13) {
        // 0x8008DD54: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8008DD60;
    }
    // 0x8008DD54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008DD58: jal         0x80001D04
    // 0x8008DD5C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8008DD5C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    after_6:
L_8008DD60:
    // 0x8008DD60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008DD64:
    // 0x8008DD64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DD68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008DD6C: jr          $ra
    // 0x8008DD70: nop

    return;
    // 0x8008DD70: nop

;}
RECOMP_FUNC void init_game(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C620: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006C624: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006C628: jal         0x80070D70
    // 0x8006C62C: nop

    mempool_init_main(rdram, ctx);
        goto after_0;
    // 0x8006C62C: nop

    after_0:
    // 0x8006C630: jal         0x800C66D0
    // 0x8006C634: nop

    gzip_init(rdram, ctx);
        goto after_1;
    // 0x8006C634: nop

    after_1:
    // 0x8006C638: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006C63C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C640: jal         0x8006F72C
    // 0x8006C644: sb          $t6, -0x271C($at)
    MEM_B(-0X271C, ctx->r1) = ctx->r14;
    drm_validate_imem(rdram, ctx);
        goto after_2;
    // 0x8006C644: sb          $t6, -0x271C($at)
    MEM_B(-0X271C, ctx->r1) = ctx->r14;
    after_2:
    // 0x8006C648: beq         $v0, $zero, L_8006C658
    if (ctx->r2 == 0) {
        // 0x8006C64C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8006C658;
    }
    // 0x8006C64C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C650: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C654: sb          $zero, -0x271C($at)
    MEM_B(-0X271C, ctx->r1) = 0;
L_8006C658:
    // 0x8006C658: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C65C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8006C660: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x8006C664: sb          $zero, 0x3A94($at)
    MEM_B(0X3A94, ctx->r1) = 0;
    // 0x8006C668: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C66C: bne         $v0, $zero, L_8006C680
    if (ctx->r2 != 0) {
        // 0x8006C670: sw          $zero, 0x3A98($at)
        MEM_W(0X3A98, ctx->r1) = 0;
            goto L_8006C680;
    }
    // 0x8006C670: sw          $zero, 0x3A98($at)
    MEM_W(0X3A98, ctx->r1) = 0;
    // 0x8006C674: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x8006C678: b           L_8006C6A4
    // 0x8006C67C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_8006C6A4;
    // 0x8006C67C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8006C680:
    // 0x8006C680: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006C684: bne         $v0, $at, L_8006C698
    if (ctx->r2 != ctx->r1) {
        // 0x8006C688: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006C698;
    }
    // 0x8006C688: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006C68C: b           L_8006C6A4
    // 0x8006C690: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
        goto L_8006C6A4;
    // 0x8006C690: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8006C694: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8006C698:
    // 0x8006C698: bne         $v0, $at, L_8006C6A4
    if (ctx->r2 != ctx->r1) {
        // 0x8006C69C: addiu       $t8, $zero, 0x1C
        ctx->r24 = ADD32(0, 0X1C);
            goto L_8006C6A4;
    }
    // 0x8006C69C: addiu       $t8, $zero, 0x1C
    ctx->r24 = ADD32(0, 0X1C);
    // 0x8006C6A0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_8006C6A4:
    // 0x8006C6A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C6A8: lbu         $a3, 0x27($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X27);
    // 0x8006C6AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006C6B0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8006C6B4: addiu       $a1, $a1, 0x3A68
    ctx->r5 = ADD32(ctx->r5, 0X3A68);
    // 0x8006C6B8: addiu       $a0, $a0, 0x17E0
    ctx->r4 = ADD32(ctx->r4, 0X17E0);
    // 0x8006C6BC: jal         0x800797A0
    // 0x8006C6C0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    osCreateScheduler(rdram, ctx);
        goto after_3;
    // 0x8006C6C0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_3:
    // 0x8006C6C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C6C8: jal         0x8006F1F8
    // 0x8006C6CC: sb          $zero, -0x26F0($at)
    MEM_B(-0X26F0, ctx->r1) = 0;
    drm_validate_dmem(rdram, ctx);
        goto after_4;
    // 0x8006C6CC: sb          $zero, -0x26F0($at)
    MEM_B(-0X26F0, ctx->r1) = 0;
    after_4:
    // 0x8006C6D0: bne         $v0, $zero, L_8006C6E4
    if (ctx->r2 != 0) {
        // 0x8006C6D4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8006C6E4;
    }
    // 0x8006C6D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006C6D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006C6DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C6E0: sb          $t1, -0x26F0($at)
    MEM_B(-0X26F0, ctx->r1) = ctx->r9;
L_8006C6E4:
    // 0x8006C6E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C6E8: jal         0x8007A760
    // 0x8006C6EC: addiu       $a1, $a1, 0x17E0
    ctx->r5 = ADD32(ctx->r5, 0X17E0);
    video_init(rdram, ctx);
        goto after_5;
    // 0x8006C6EC: addiu       $a1, $a1, 0x17E0
    ctx->r5 = ADD32(ctx->r5, 0X17E0);
    after_5:
    // 0x8006C6F0: jal         0x80076E00
    // 0x8006C6F4: nop

    pi_init(rdram, ctx);
        goto after_6;
    // 0x8006C6F4: nop

    after_6:
    // 0x8006C6F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C6FC: jal         0x80078550
    // 0x8006C700: addiu       $a0, $a0, 0x17E0
    ctx->r4 = ADD32(ctx->r4, 0X17E0);
    gfxtask_init(rdram, ctx);
        goto after_7;
    // 0x8006C700: addiu       $a0, $a0, 0x17E0
    ctx->r4 = ADD32(ctx->r4, 0X17E0);
    after_7:
    // 0x8006C704: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C708: jal         0x80000450
    // 0x8006C70C: addiu       $a0, $a0, 0x17E0
    ctx->r4 = ADD32(ctx->r4, 0X17E0);
    audio_init(rdram, ctx);
        goto after_8;
    // 0x8006C70C: addiu       $a0, $a0, 0x17E0
    ctx->r4 = ADD32(ctx->r4, 0X17E0);
    after_8:
    // 0x8006C710: jal         0x80008040
    // 0x8006C714: nop

    audspat_init(rdram, ctx);
        goto after_9;
    // 0x8006C714: nop

    after_9:
    // 0x8006C718: jal         0x8006A34C
    // 0x8006C71C: nop

    input_init(rdram, ctx);
        goto after_10;
    // 0x8006C71C: nop

    after_10:
    // 0x8006C720: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C724: jal         0x8007B0C0
    // 0x8006C728: sw          $v0, -0x270C($at)
    MEM_W(-0X270C, ctx->r1) = ctx->r2;
    tex_init_textures(rdram, ctx);
        goto after_11;
    // 0x8006C728: sw          $v0, -0x270C($at)
    MEM_W(-0X270C, ctx->r1) = ctx->r2;
    after_11:
    // 0x8006C72C: jal         0x8005F9F0
    // 0x8006C730: nop

    allocate_object_model_pools(rdram, ctx);
        goto after_12;
    // 0x8006C730: nop

    after_12:
    // 0x8006C734: jal         0x8000BF8C
    // 0x8006C738: nop

    allocate_object_pools(rdram, ctx);
        goto after_13;
    // 0x8006C738: nop

    after_13:
    // 0x8006C73C: jal         0x800B63E8
    // 0x8006C740: nop

    debug_text_init(rdram, ctx);
        goto after_14;
    // 0x8006C740: nop

    after_14:
    // 0x8006C744: jal         0x80059920
    // 0x8006C748: nop

    allocate_ghost_data(rdram, ctx);
        goto after_15;
    // 0x8006C748: nop

    after_15:
    // 0x8006C74C: jal         0x800AEA90
    // 0x8006C750: nop

    init_particle_assets(rdram, ctx);
        goto after_16;
    // 0x8006C750: nop

    after_16:
    // 0x8006C754: jal         0x800AB750
    // 0x8006C758: nop

    weather_init(rdram, ctx);
        goto after_17;
    // 0x8006C758: nop

    after_17:
    // 0x8006C75C: jal         0x8006E5FC
    // 0x8006C760: nop

    calc_and_alloc_heap_for_settings(rdram, ctx);
        goto after_18;
    // 0x8006C760: nop

    after_18:
    // 0x8006C764: jal         0x8006F21C
    // 0x8006C768: nop

    default_alloc_displaylist_heap(rdram, ctx);
        goto after_19;
    // 0x8006C768: nop

    after_19:
    // 0x8006C76C: jal         0x800C4160
    // 0x8006C770: nop

    load_fonts(rdram, ctx);
        goto after_20;
    // 0x8006C770: nop

    after_20:
    // 0x8006C774: jal         0x80075D70
    // 0x8006C778: nop

    init_controller_paks(rdram, ctx);
        goto after_21;
    // 0x8006C778: nop

    after_21:
    // 0x8006C77C: jal         0x80081668
    // 0x8006C780: nop

    init_save_data(rdram, ctx);
        goto after_22;
    // 0x8006C780: nop

    after_22:
    // 0x8006C784: jal         0x800C78B0
    // 0x8006C788: nop

    bgload_init(rdram, ctx);
        goto after_23;
    // 0x8006C788: nop

    after_23:
    // 0x8006C78C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C790: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C794: addiu       $a1, $a1, 0x3AC4
    ctx->r5 = ADD32(ctx->r5, 0X3AC4);
    // 0x8006C798: addiu       $a0, $a0, 0x3AC8
    ctx->r4 = ADD32(ctx->r4, 0X3AC8);
    // 0x8006C79C: jal         0x800C8D80
    // 0x8006C7A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_24;
    // 0x8006C7A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_24:
    // 0x8006C7A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C7A8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C7AC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C7B0: addiu       $a2, $a2, 0x3AC8
    ctx->r6 = ADD32(ctx->r6, 0X3AC8);
    // 0x8006C7B4: addiu       $a1, $a1, 0x3AB8
    ctx->r5 = ADD32(ctx->r5, 0X3AB8);
    // 0x8006C7B8: addiu       $a0, $a0, 0x17E0
    ctx->r4 = ADD32(ctx->r4, 0X17E0);
    // 0x8006C7BC: jal         0x800798D0
    // 0x8006C7C0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    osScAddClient(rdram, ctx);
        goto after_25;
    // 0x8006C7C0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_25:
    // 0x8006C7C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C7C8: sw          $zero, 0x3AE0($at)
    MEM_W(0X3AE0, ctx->r1) = 0;
    // 0x8006C7CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C7D0: sw          $zero, 0x3A84($at)
    MEM_W(0X3A84, ctx->r1) = 0;
    // 0x8006C7D4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006C7D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C7DC: addiu       $t0, $t0, 0x3A68
    ctx->r8 = ADD32(ctx->r8, 0X3A68);
    // 0x8006C7E0: sw          $zero, 0x3A88($at)
    MEM_W(0X3A88, ctx->r1) = 0;
    // 0x8006C7E4: sll         $t3, $zero, 2
    ctx->r11 = S32(0 << 2);
    // 0x8006C7E8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006C7EC: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8006C7F0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006C7F4: lw          $t4, 0x1770($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1770);
    // 0x8006C7F8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006C7FC: addiu       $v1, $v1, 0x1778
    ctx->r3 = ADD32(ctx->r3, 0X1778);
    // 0x8006C800: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8006C804: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8006C808: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8006C80C: lui         $t6, 0xE900
    ctx->r14 = S32(0XE900 << 16);
    // 0x8006C810: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8006C814: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8006C818: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006C81C: lui         $t8, 0xB800
    ctx->r24 = S32(0XB800 << 16);
    // 0x8006C820: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006C824: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006C828: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8006C82C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8006C830: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006C834: jal         0x800CD7C0
    // 0x8006C838: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    osSetTime_recomp(rdram, ctx);
        goto after_26;
    // 0x8006C838: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    after_26:
    // 0x8006C83C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C840: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006C844: jr          $ra
    // 0x8006C848: nop

    return;
    // 0x8006C848: nop

;}
RECOMP_FUNC void menu_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80081824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081828: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008182C: jal         0x8009C3A0
    // 0x80081830: sw          $a0, -0x610($at)
    MEM_W(-0X610, ctx->r1) = ctx->r4;
    reset_controller_sticks(rdram, ctx);
        goto after_0;
    // 0x80081830: sw          $a0, -0x610($at)
    MEM_W(-0X610, ctx->r1) = ctx->r4;
    after_0:
    // 0x80081834: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80081838: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008183C: sw          $t6, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = ctx->r14;
    // 0x80081840: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081844: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x80081848: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008184C: sw          $zero, 0x6968($at)
    MEM_W(0X6968, ctx->r1) = 0;
    // 0x80081850: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081854: sb          $zero, 0x6DC8($at)
    MEM_B(0X6DC8, ctx->r1) = 0;
    // 0x80081858: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008185C: sw          $zero, 0x6DA8($at)
    MEM_W(0X6DA8, ctx->r1) = 0;
    // 0x80081860: sw          $zero, 0x6DAC($at)
    MEM_W(0X6DAC, ctx->r1) = 0;
    // 0x80081864: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081868: sw          $zero, 0x6DB0($at)
    MEM_W(0X6DB0, ctx->r1) = 0;
    // 0x8008186C: jal         0x80001844
    // 0x80081870: sw          $zero, 0x6DB4($at)
    MEM_W(0X6DB4, ctx->r1) = 0;
    music_stop(rdram, ctx);
        goto after_1;
    // 0x80081870: sw          $zero, 0x6DB4($at)
    MEM_W(0X6DB4, ctx->r1) = 0;
    after_1:
    // 0x80081874: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80081878: lw          $t7, -0x610($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X610);
    // 0x8008187C: nop

    // 0x80081880: sltiu       $at, $t7, 0x1D
    ctx->r1 = ctx->r15 < 0X1D ? 1 : 0;
    // 0x80081884: beq         $at, $zero, L_800819DC
    if (ctx->r1 == 0) {
        // 0x80081888: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800819DC;
    }
    // 0x80081888: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008188C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80081890: addu        $at, $at, $t7
    gpr jr_addend_8008189C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80081894: lw          $t7, -0x77EC($at)
    ctx->r15 = ADD32(ctx->r1, -0X77EC);
    // 0x80081898: nop

    // 0x8008189C: jr          $t7
    // 0x800818A0: nop

    switch (jr_addend_8008189C >> 2) {
        case 0: goto L_800818B4; break;
        case 1: goto L_800818A4; break;
        case 2: goto L_800819DC; break;
        case 3: goto L_80081914; break;
        case 4: goto L_800819DC; break;
        case 5: goto L_80081954; break;
        case 6: goto L_80081934; break;
        case 7: goto L_800819DC; break;
        case 8: goto L_800819DC; break;
        case 9: goto L_800819DC; break;
        case 10: goto L_800818F4; break;
        case 11: goto L_80081904; break;
        case 12: goto L_800818C4; break;
        case 13: goto L_800818D4; break;
        case 14: goto L_800818E4; break;
        case 15: goto L_80081944; break;
        case 16: goto L_800819DC; break;
        case 17: goto L_80081964; break;
        case 18: goto L_800819DC; break;
        case 19: goto L_80081924; break;
        case 20: goto L_80081974; break;
        case 21: goto L_80081984; break;
        case 22: goto L_800819DC; break;
        case 23: goto L_80081994; break;
        case 24: goto L_800819A4; break;
        case 25: goto L_800819B4; break;
        case 26: goto L_800819C4; break;
        case 27: goto L_800819DC; break;
        case 28: goto L_800819D4; break;
        default: switch_error(__func__, 0x8008189C, 0x800E8814);
    }
    // 0x800818A0: nop

L_800818A4:
    // 0x800818A4: jal         0x80082EFC
    // 0x800818A8: nop

    menu_logos_screen_init(rdram, ctx);
        goto after_2;
    // 0x800818A8: nop

    after_2:
    // 0x800818AC: b           L_800819E0
    // 0x800818B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800818B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800818B4:
    // 0x800818B4: jal         0x80083974
    // 0x800818B8: nop

    menu_title_screen_init(rdram, ctx);
        goto after_3;
    // 0x800818B8: nop

    after_3:
    // 0x800818BC: b           L_800819E0
    // 0x800818C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800818C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800818C4:
    // 0x800818C4: jal         0x80084594
    // 0x800818C8: nop

    menu_options_init(rdram, ctx);
        goto after_4;
    // 0x800818C8: nop

    after_4:
    // 0x800818CC: b           L_800819E0
    // 0x800818D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800818D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800818D4:
    // 0x800818D4: jal         0x80084B8C
    // 0x800818D8: nop

    menu_audio_options_init(rdram, ctx);
        goto after_5;
    // 0x800818D8: nop

    after_5:
    // 0x800818DC: b           L_800819E0
    // 0x800818E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800818E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800818E4:
    // 0x800818E4: jal         0x800856A8
    // 0x800818E8: nop

    menu_save_options_init(rdram, ctx);
        goto after_6;
    // 0x800818E8: nop

    after_6:
    // 0x800818EC: b           L_800819E0
    // 0x800818F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800818F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800818F4:
    // 0x800818F4: jal         0x80089A78
    // 0x800818F8: nop

    menu_magic_codes_init(rdram, ctx);
        goto after_7;
    // 0x800818F8: nop

    after_7:
    // 0x800818FC: b           L_800819E0
    // 0x80081900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081904:
    // 0x80081904: jal         0x8008A998
    // 0x80081908: nop

    menu_magic_codes_list_init(rdram, ctx);
        goto after_8;
    // 0x80081908: nop

    after_8:
    // 0x8008190C: b           L_800819E0
    // 0x80081910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081914:
    // 0x80081914: jal         0x8008B484
    // 0x80081918: nop

    menu_character_select_init(rdram, ctx);
        goto after_9;
    // 0x80081918: nop

    after_9:
    // 0x8008191C: b           L_800819E0
    // 0x80081920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081924:
    // 0x80081924: jal         0x8008C9C0
    // 0x80081928: nop

    menu_game_select_init(rdram, ctx);
        goto after_10;
    // 0x80081928: nop

    after_10:
    // 0x8008192C: b           L_800819E0
    // 0x80081930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081934:
    // 0x80081934: jal         0x8008CFB4
    // 0x80081938: nop

    menu_file_select_init(rdram, ctx);
        goto after_11;
    // 0x80081938: nop

    after_11:
    // 0x8008193C: b           L_800819E0
    // 0x80081940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081944:
    // 0x80081944: jal         0x8008EC58
    // 0x80081948: nop

    menu_track_select_init(rdram, ctx);
        goto after_12;
    // 0x80081948: nop

    after_12:
    // 0x8008194C: b           L_800819E0
    // 0x80081950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081954:
    // 0x80081954: jal         0x800931CC
    // 0x80081958: nop

    menu_adventure_track_init(rdram, ctx);
        goto after_13;
    // 0x80081958: nop

    after_13:
    // 0x8008195C: b           L_800819E0
    // 0x80081960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081964:
    // 0x80081964: jal         0x80096D4C
    // 0x80081968: nop

    menu_results_init(rdram, ctx);
        goto after_14;
    // 0x80081968: nop

    after_14:
    // 0x8008196C: b           L_800819E0
    // 0x80081970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081974:
    // 0x80081974: jal         0x800987A8
    // 0x80081978: nop

    menu_trophy_race_round_init(rdram, ctx);
        goto after_15;
    // 0x80081978: nop

    after_15:
    // 0x8008197C: b           L_800819E0
    // 0x80081980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081984:
    // 0x80081984: jal         0x80098F60
    // 0x80081988: nop

    menu_trophy_race_rankings_init(rdram, ctx);
        goto after_16;
    // 0x80081988: nop

    after_16:
    // 0x8008198C: b           L_800819E0
    // 0x80081990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081994:
    // 0x80081994: jal         0x8009B1D4
    // 0x80081998: nop

    menu_cinematic_init(rdram, ctx);
        goto after_17;
    // 0x80081998: nop

    after_17:
    // 0x8008199C: b           L_800819E0
    // 0x800819A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800819A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800819A4:
    // 0x800819A4: jal         0x80099F98
    // 0x800819A8: nop

    menu_ghost_data_init(rdram, ctx);
        goto after_18;
    // 0x800819A8: nop

    after_18:
    // 0x800819AC: b           L_800819E0
    // 0x800819B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800819B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800819B4:
    // 0x800819B4: jal         0x8009B484
    // 0x800819B8: nop

    menu_credits_init(rdram, ctx);
        goto after_19;
    // 0x800819B8: nop

    after_19:
    // 0x800819BC: b           L_800819E0
    // 0x800819C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800819C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800819C4:
    // 0x800819C4: jal         0x8008896C
    // 0x800819C8: nop

    menu_boot_init(rdram, ctx);
        goto after_20;
    // 0x800819C8: nop

    after_20:
    // 0x800819CC: b           L_800819E0
    // 0x800819D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800819D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800819D4:
    // 0x800819D4: jal         0x8008C86C
    // 0x800819D8: nop

    menu_caution_init(rdram, ctx);
        goto after_21;
    // 0x800819D8: nop

    after_21:
L_800819DC:
    // 0x800819DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800819E0:
    // 0x800819E0: ori         $t8, $zero, 0xD000
    ctx->r24 = 0 | 0XD000;
    // 0x800819E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800819E8: sw          $t8, 0x6A10($at)
    MEM_W(0X6A10, ctx->r1) = ctx->r24;
    // 0x800819EC: jr          $ra
    // 0x800819F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800819F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void get_projection_matrix_f32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069FE4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80069FE8: jr          $ra
    // 0x80069FEC: addiu       $v0, $v0, 0x1520
    ctx->r2 = ADD32(ctx->r2, 0X1520);
    return;
    // 0x80069FEC: addiu       $v0, $v0, 0x1520
    ctx->r2 = ADD32(ctx->r2, 0X1520);
;}
RECOMP_FUNC void get_racer_object_by_port(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BB4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BB50: lw          $v0, -0x4B90($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4B90);
    // 0x8001BB54: nop

    // 0x8001BB58: bne         $v0, $zero, L_8001BB68
    if (ctx->r2 != 0) {
        // 0x8001BB5C: nop
    
            goto L_8001BB68;
    }
    // 0x8001BB5C: nop

    // 0x8001BB60: jr          $ra
    // 0x8001BB64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BB64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BB68:
    // 0x8001BB68: bltz        $a0, L_8001BB78
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001BB6C: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001BB78;
    }
    // 0x8001BB6C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BB70: bne         $at, $zero, L_8001BB80
    if (ctx->r1 != 0) {
        // 0x8001BB74: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001BB80;
    }
    // 0x8001BB74: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
L_8001BB78:
    // 0x8001BB78: jr          $ra
    // 0x8001BB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BB80:
    // 0x8001BB80: lw          $t6, -0x4B94($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B94);
    // 0x8001BB84: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8001BB88: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001BB8C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001BB90: nop

    // 0x8001BB94: jr          $ra
    // 0x8001BB98: nop

    return;
    // 0x8001BB98: nop

;}
RECOMP_FUNC void block_visible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A638: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8002A63C: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8002A640: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8002A644: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002A648: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8002A64C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002A650: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8002A654: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8002A658: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002A65C: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x8002A660: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002A664: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x8002A668: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002A66C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8002A670: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002A674: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8002A678: addiu       $s3, $s3, -0x2988
    ctx->r19 = ADD32(ctx->r19, -0X2988);
L_8002A67C:
    // 0x8002A67C: lwc1        $f20, 0x0($s3)
    ctx->f20.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8002A680: lwc1        $f22, 0x4($s3)
    ctx->f22.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8002A684: lwc1        $f24, 0x8($s3)
    ctx->f24.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8002A688: lwc1        $f26, 0xC($s3)
    ctx->f26.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8002A68C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002A690: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002A694: andi        $t6, $s0, 0x1
    ctx->r14 = ctx->r16 & 0X1;
L_8002A698:
    // 0x8002A698: beq         $t6, $zero, L_8002A6CC
    if (ctx->r14 == 0) {
        // 0x8002A69C: nop
    
            goto L_8002A6CC;
    }
    // 0x8002A69C: nop

    // 0x8002A6A0: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x8002A6A4: nop

    // 0x8002A6A8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8002A6AC: nop

    // 0x8002A6B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002A6B4: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8002A6B8: jal         0x800CA0AC
    // 0x8002A6BC: nop

    __f_to_ll_recomp(rdram, ctx);
        goto after_0;
    // 0x8002A6BC: nop

    after_0:
    // 0x8002A6C0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A6C4: b           L_8002A6F4
    // 0x8002A6C8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
        goto L_8002A6F4;
    // 0x8002A6C8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_8002A6CC:
    // 0x8002A6CC: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8002A6D0: nop

    // 0x8002A6D4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8002A6D8: nop

    // 0x8002A6DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002A6E0: mul.s       $f12, $f10, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8002A6E4: jal         0x800CA0AC
    // 0x8002A6E8: nop

    __f_to_ll_recomp(rdram, ctx);
        goto after_1;
    // 0x8002A6E8: nop

    after_1:
    // 0x8002A6EC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A6F0: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_8002A6F4:
    // 0x8002A6F4: andi        $t9, $s0, 0x2
    ctx->r25 = ctx->r16 & 0X2;
    // 0x8002A6F8: beq         $t9, $zero, L_8002A740
    if (ctx->r25 == 0) {
        // 0x8002A6FC: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_8002A740;
    }
    // 0x8002A6FC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002A700: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002A704: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A708: jal         0x800CA21C
    // 0x8002A70C: nop

    __ll_to_f_recomp(rdram, ctx);
        goto after_2;
    // 0x8002A70C: nop

    after_2:
    // 0x8002A710: lh          $t0, 0x2($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2);
    // 0x8002A714: nop

    // 0x8002A718: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8002A71C: nop

    // 0x8002A720: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002A724: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x8002A728: jal         0x800CA0AC
    // 0x8002A72C: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    __f_to_ll_recomp(rdram, ctx);
        goto after_3;
    // 0x8002A72C: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_3:
    // 0x8002A730: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A734: b           L_8002A774
    // 0x8002A738: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
        goto L_8002A774;
    // 0x8002A738: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x8002A73C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_8002A740:
    // 0x8002A740: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A744: jal         0x800CA21C
    // 0x8002A748: nop

    __ll_to_f_recomp(rdram, ctx);
        goto after_4;
    // 0x8002A748: nop

    after_4:
    // 0x8002A74C: lh          $t1, 0x8($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X8);
    // 0x8002A750: nop

    // 0x8002A754: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8002A758: nop

    // 0x8002A75C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002A760: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8002A764: jal         0x800CA0AC
    // 0x8002A768: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    __f_to_ll_recomp(rdram, ctx);
        goto after_5;
    // 0x8002A768: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    after_5:
    // 0x8002A76C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A770: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_8002A774:
    // 0x8002A774: andi        $t2, $s0, 0x4
    ctx->r10 = ctx->r16 & 0X4;
    // 0x8002A778: beq         $t2, $zero, L_8002A7C0
    if (ctx->r10 == 0) {
        // 0x8002A77C: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_8002A7C0;
    }
    // 0x8002A77C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002A780: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002A784: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A788: jal         0x800CA21C
    // 0x8002A78C: nop

    __ll_to_f_recomp(rdram, ctx);
        goto after_6;
    // 0x8002A78C: nop

    after_6:
    // 0x8002A790: lh          $t3, 0x4($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X4);
    // 0x8002A794: nop

    // 0x8002A798: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8002A79C: nop

    // 0x8002A7A0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002A7A4: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x8002A7A8: jal         0x800CA0AC
    // 0x8002A7AC: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    __f_to_ll_recomp(rdram, ctx);
        goto after_7;
    // 0x8002A7AC: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_7:
    // 0x8002A7B0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A7B4: b           L_8002A7F4
    // 0x8002A7B8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
        goto L_8002A7F4;
    // 0x8002A7B8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x8002A7BC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_8002A7C0:
    // 0x8002A7C0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A7C4: jal         0x800CA21C
    // 0x8002A7C8: nop

    __ll_to_f_recomp(rdram, ctx);
        goto after_8;
    // 0x8002A7C8: nop

    after_8:
    // 0x8002A7CC: lh          $t4, 0xA($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XA);
    // 0x8002A7D0: nop

    // 0x8002A7D4: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8002A7D8: nop

    // 0x8002A7DC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002A7E0: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x8002A7E4: jal         0x800CA0AC
    // 0x8002A7E8: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    __f_to_ll_recomp(rdram, ctx);
        goto after_9;
    // 0x8002A7E8: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    after_9:
    // 0x8002A7EC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A7F0: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_8002A7F4:
    // 0x8002A7F4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002A7F8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A7FC: jal         0x800CA21C
    // 0x8002A800: nop

    __ll_to_f_recomp(rdram, ctx);
        goto after_10;
    // 0x8002A800: nop

    after_10:
    // 0x8002A804: jal         0x800CA0AC
    // 0x8002A808: add.s       $f12, $f0, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f26.fl;
    __f_to_ll_recomp(rdram, ctx);
        goto after_11;
    // 0x8002A808: add.s       $f12, $f0, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f26.fl;
    after_11:
    // 0x8002A80C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A810: bltz        $v0, L_8002A82C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8002A814: sw          $v1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r3;
            goto L_8002A82C;
    }
    // 0x8002A814: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x8002A818: bgtz        $v0, L_8002A828
    if (SIGNED(ctx->r2) > 0) {
        // 0x8002A81C: nop
    
            goto L_8002A828;
    }
    // 0x8002A81C: nop

    // 0x8002A820: beq         $v1, $zero, L_8002A82C
    if (ctx->r3 == 0) {
        // 0x8002A824: nop
    
            goto L_8002A82C;
    }
    // 0x8002A824: nop

L_8002A828:
    // 0x8002A828: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8002A82C:
    // 0x8002A82C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002A830: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8002A834: beq         $at, $zero, L_8002A848
    if (ctx->r1 == 0) {
        // 0x8002A838: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8002A848;
    }
    // 0x8002A838: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002A83C: beq         $s2, $zero, L_8002A698
    if (ctx->r18 == 0) {
        // 0x8002A840: andi        $t6, $s0, 0x1
        ctx->r14 = ctx->r16 & 0X1;
            goto L_8002A698;
    }
    // 0x8002A840: andi        $t6, $s0, 0x1
    ctx->r14 = ctx->r16 & 0X1;
    // 0x8002A844: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_8002A848:
    // 0x8002A848: bne         $s0, $at, L_8002A860
    if (ctx->r16 != ctx->r1) {
        // 0x8002A84C: addiu       $s3, $s3, 0x10
        ctx->r19 = ADD32(ctx->r19, 0X10);
            goto L_8002A860;
    }
    // 0x8002A84C: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x8002A850: bne         $s2, $zero, L_8002A860
    if (ctx->r18 != 0) {
        // 0x8002A854: nop
    
            goto L_8002A860;
    }
    // 0x8002A854: nop

    // 0x8002A858: b           L_8002A904
    // 0x8002A85C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002A904;
    // 0x8002A85C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002A860:
    // 0x8002A860: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002A864: addiu       $t5, $t5, -0x2958
    ctx->r13 = ADD32(ctx->r13, -0X2958);
    // 0x8002A868: bne         $s3, $t5, L_8002A67C
    if (ctx->r19 != ctx->r13) {
        // 0x8002A86C: nop
    
            goto L_8002A67C;
    }
    // 0x8002A86C: nop

    // 0x8002A870: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8002A874: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x8002A878: lh          $t7, 0xA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XA);
    // 0x8002A87C: lh          $t5, 0x4($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X4);
    // 0x8002A880: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8002A884: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x8002A888: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8002A88C: lh          $t2, 0x8($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X8);
    // 0x8002A890: lh          $t3, 0x2($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X2);
    // 0x8002A894: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8002A898: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8002A89C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002A8A0: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8002A8A4: sra         $t6, $t4, 1
    ctx->r14 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8002A8A8: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8002A8AC: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8002A8B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8002A8B4: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002A8B8: jal         0x80066588
    // 0x8002A8BC: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    get_distance_to_active_camera(rdram, ctx);
        goto after_12;
    // 0x8002A8BC: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_12:
    // 0x8002A8C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002A8C4: addiu       $v0, $v0, -0x2700
    ctx->r2 = ADD32(ctx->r2, -0X2700);
    // 0x8002A8C8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8002A8CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002A8D0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002A8D4: lwc1        $f11, 0x6438($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6438);
    // 0x8002A8D8: lwc1        $f10, 0x643C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X643C);
    // 0x8002A8DC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002A8E0: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8002A8E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002A8E8: bc1f        L_8002A900
    if (!c1cs) {
        // 0x8002A8EC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002A900;
    }
    // 0x8002A8EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A8F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002A8F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002A8F8: b           L_8002A904
    // 0x8002A8FC: sw          $t0, -0x49C4($at)
    MEM_W(-0X49C4, ctx->r1) = ctx->r8;
        goto L_8002A904;
    // 0x8002A8FC: sw          $t0, -0x49C4($at)
    MEM_W(-0X49C4, ctx->r1) = ctx->r8;
L_8002A900:
    // 0x8002A900: sw          $zero, -0x49C4($at)
    MEM_W(-0X49C4, ctx->r1) = 0;
L_8002A904:
    // 0x8002A904: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002A908: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8002A90C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8002A910: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002A914: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002A918: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002A91C: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002A920: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002A924: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002A928: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8002A92C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8002A930: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8002A934: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8002A938: jr          $ra
    // 0x8002A93C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8002A93C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void obj_init_buoy_pirateship(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040418: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004041C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040420: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80040424: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80040428: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8004042C: lw          $a1, 0xC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC);
    // 0x80040430: lw          $a2, 0x14($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X14);
    // 0x80040434: lh          $a0, 0x2E($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2E);
    // 0x80040438: jal         0x800BEB74
    // 0x8004043C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    obj_wave_init(rdram, ctx);
        goto after_0;
    // 0x8004043C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80040440: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80040444: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80040448: lw          $t7, 0x4C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4C);
    // 0x8004044C: sw          $v0, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r2;
    // 0x80040450: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80040454: lw          $t8, 0x4C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X4C);
    // 0x80040458: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8004045C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x80040460: lw          $t0, 0x4C($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X4C);
    // 0x80040464: nop

    // 0x80040468: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8004046C: lw          $t1, 0x4C($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X4C);
    // 0x80040470: nop

    // 0x80040474: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x80040478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004047C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040480: jr          $ra
    // 0x80040484: nop

    return;
    // 0x80040484: nop

;}
RECOMP_FUNC void alFxPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063E70: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80063E74: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80063E78: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80063E7C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80063E80: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80063E84: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80063E88: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80063E8C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80063E90: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80063E94: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80063E98: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80063E9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80063EA0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80063EA4: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x80063EA8: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x80063EAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80063EB0: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80063EB4: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80063EB8: jalr        $t9
    // 0x80063EBC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80063EBC: nop

    after_0:
    // 0x80063EC0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80063EC4: lbu         $t7, -0x2BE0($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2BE0);
    // 0x80063EC8: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x80063ECC: bne         $t7, $zero, L_80063EDC
    if (ctx->r15 != 0) {
        // 0x80063ED0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80063EDC;
    }
    // 0x80063ED0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80063ED4: b           L_800641A8
    // 0x80063ED8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800641A8;
    // 0x80063ED8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80063EDC:
    // 0x80063EDC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80063EE0: sll         $s1, $s6, 1
    ctx->r17 = S32(ctx->r22 << 1);
    // 0x80063EE4: andi        $t3, $s1, 0xFFFF
    ctx->r11 = ctx->r17 & 0XFFFF;
    // 0x80063EE8: addiu       $t0, $s0, 0x8
    ctx->r8 = ADD32(ctx->r16, 0X8);
    // 0x80063EEC: lui         $t8, 0x800
    ctx->r24 = S32(0X800 << 16);
    // 0x80063EF0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80063EF4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80063EF8: lui         $t4, 0xC00
    ctx->r12 = S32(0XC00 << 16);
    // 0x80063EFC: lui         $t5, 0x6C0
    ctx->r13 = S32(0X6C0 << 16);
    // 0x80063F00: ori         $t5, $t5, 0x6C0
    ctx->r13 = ctx->r13 | 0X6C0;
    // 0x80063F04: ori         $t4, $t4, 0xDA83
    ctx->r12 = ctx->r12 | 0XDA83;
    // 0x80063F08: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80063F0C: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x80063F10: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80063F14: lui         $t6, 0xC00
    ctx->r14 = S32(0XC00 << 16);
    // 0x80063F18: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x80063F1C: ori         $t9, $t9, 0x6C0
    ctx->r25 = ctx->r25 | 0X6C0;
    // 0x80063F20: ori         $t6, $t6, 0x5A82
    ctx->r14 = ctx->r14 | 0X5A82;
    // 0x80063F24: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80063F28: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80063F2C: lw          $a1, 0x18($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X18);
    // 0x80063F30: addiu       $s0, $t1, 0x8
    ctx->r16 = ADD32(ctx->r9, 0X8);
    // 0x80063F34: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80063F38: addiu       $s2, $zero, 0x140
    ctx->r18 = ADD32(0, 0X140);
    // 0x80063F3C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80063F40: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x80063F44: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x80063F48: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    // 0x80063F4C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80063F50: addiu       $a2, $zero, 0x6C0
    ctx->r6 = ADD32(0, 0X6C0);
    // 0x80063F54: jal         0x80064878
    // 0x80063F58: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    _saveBuffer(rdram, ctx);
        goto after_1;
    // 0x80063F58: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_1:
    // 0x80063F5C: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x80063F60: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x80063F64: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x80063F68: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80063F6C: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80063F70: lbu         $t8, 0x24($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X24);
    // 0x80063F74: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80063F78: blez        $t8, L_80064154
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80063F7C: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_80064154;
    }
    // 0x80063F7C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80063F80: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x80063F84: nop

L_80063F88:
    // 0x80063F88: sll         $t5, $s7, 2
    ctx->r13 = S32(ctx->r23 << 2);
    // 0x80063F8C: lw          $t4, 0x20($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X20);
    // 0x80063F90: addu        $t5, $t5, $s7
    ctx->r13 = ADD32(ctx->r13, ctx->r23);
    // 0x80063F94: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80063F98: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x80063F9C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80063FA0: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80063FA4: negu        $t9, $t6
    ctx->r25 = SUB32(0, ctx->r14);
    // 0x80063FA8: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x80063FAC: negu        $t4, $t8
    ctx->r12 = SUB32(0, ctx->r24);
    // 0x80063FB0: addu        $s4, $v0, $t7
    ctx->r20 = ADD32(ctx->r2, ctx->r15);
    // 0x80063FB4: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80063FB8: bne         $s4, $v1, L_80063FE0
    if (ctx->r20 != ctx->r3) {
        // 0x80063FBC: addu        $fp, $v0, $t5
        ctx->r30 = ADD32(ctx->r2, ctx->r13);
            goto L_80063FE0;
    }
    // 0x80063FBC: addu        $fp, $v0, $t5
    ctx->r30 = ADD32(ctx->r2, ctx->r13);
    // 0x80063FC0: or          $t6, $s2, $zero
    ctx->r14 = ctx->r18 | 0;
    // 0x80063FC4: sll         $s2, $s5, 16
    ctx->r18 = S32(ctx->r21 << 16);
    // 0x80063FC8: sll         $s5, $t6, 16
    ctx->r21 = S32(ctx->r14 << 16);
    // 0x80063FCC: sra         $t7, $s5, 16
    ctx->r15 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80063FD0: sra         $t9, $s2, 16
    ctx->r25 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80063FD4: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x80063FD8: b           L_80063FFC
    // 0x80063FDC: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
        goto L_80063FFC;
    // 0x80063FDC: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
L_80063FE0:
    // 0x80063FE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80063FE4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80063FE8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80063FEC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x80063FF0: jal         0x800646E0
    // 0x80063FF4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _loadBuffer(rdram, ctx);
        goto after_2;
    // 0x80063FF4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // 0x80063FF8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80063FFC:
    // 0x80063FFC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80064000: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80064004: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80064008: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x8006400C: jal         0x80064464
    // 0x80064010: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _loadOutputBuffer(rdram, ctx);
        goto after_3;
    // 0x80064010: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_3:
    // 0x80064014: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x80064018: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8006401C: beq         $a0, $zero, L_80064074
    if (ctx->r4 == 0) {
        // 0x80064020: andi        $t4, $a0, 0xFFFF
        ctx->r12 = ctx->r4 & 0XFFFF;
            goto L_80064074;
    }
    // 0x80064020: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x80064024: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80064028: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x8006402C: andi        $t7, $s2, 0xFFFF
    ctx->r15 = ctx->r18 & 0XFFFF;
    // 0x80064030: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80064034: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80064038: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8006403C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80064040: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x80064044: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80064048: bne         $t4, $zero, L_80064074
    if (ctx->r12 != 0) {
        // 0x8006404C: nop
    
            goto L_80064074;
    }
    // 0x8006404C: nop

    // 0x80064050: lw          $t5, 0x20($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X20);
    // 0x80064054: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80064058: bne         $t5, $zero, L_80064074
    if (ctx->r13 != 0) {
        // 0x8006405C: or          $a1, $fp, $zero
        ctx->r5 = ctx->r30 | 0;
            goto L_80064074;
    }
    // 0x8006405C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80064060: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80064064: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x80064068: jal         0x80064878
    // 0x8006406C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _saveBuffer(rdram, ctx);
        goto after_4;
    // 0x8006406C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_4:
    // 0x80064070: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80064074:
    // 0x80064074: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
    // 0x80064078: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8006407C: beq         $v1, $zero, L_800640C0
    if (ctx->r3 == 0) {
        // 0x80064080: andi        $t9, $v1, 0xFFFF
        ctx->r25 = ctx->r3 & 0XFFFF;
            goto L_800640C0;
    }
    // 0x80064080: andi        $t9, $v1, 0xFFFF
    ctx->r25 = ctx->r3 & 0XFFFF;
    // 0x80064084: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80064088: sll         $t4, $s2, 16
    ctx->r12 = S32(ctx->r18 << 16);
    // 0x8006408C: andi        $t5, $s5, 0xFFFF
    ctx->r13 = ctx->r21 & 0XFFFF;
    // 0x80064090: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80064094: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80064098: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006409C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800640A0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800640A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800640A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800640AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800640B0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800640B4: jal         0x80064878
    // 0x800640B8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    _saveBuffer(rdram, ctx);
        goto after_5;
    // 0x800640B8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_5:
    // 0x800640BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800640C0:
    // 0x800640C0: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800640C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800640C8: beq         $a0, $zero, L_800640DC
    if (ctx->r4 == 0) {
        // 0x800640CC: or          $a2, $s6, $zero
        ctx->r6 = ctx->r22 | 0;
            goto L_800640DC;
    }
    // 0x800640CC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800640D0: jal         0x80064A10
    // 0x800640D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _filterBuffer(rdram, ctx);
        goto after_6;
    // 0x800640D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x800640D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800640DC:
    // 0x800640DC: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x800640E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800640E4: bne         $t9, $zero, L_80064100
    if (ctx->r25 != 0) {
        // 0x800640E8: or          $a1, $fp, $zero
        ctx->r5 = ctx->r30 | 0;
            goto L_80064100;
    }
    // 0x800640E8: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800640EC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800640F0: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800640F4: jal         0x80064878
    // 0x800640F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _saveBuffer(rdram, ctx);
        goto after_7;
    // 0x800640F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_7:
    // 0x800640FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80064100:
    // 0x80064100: lh          $v1, 0xC($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XC);
    // 0x80064104: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80064108: beq         $v1, $zero, L_80064130
    if (ctx->r3 == 0) {
        // 0x8006410C: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80064130;
    }
    // 0x8006410C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80064110: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x80064114: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80064118: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8006411C: ori         $t9, $t6, 0x800
    ctx->r25 = ctx->r14 | 0X800;
    // 0x80064120: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x80064124: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80064128: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8006412C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80064130:
    // 0x80064130: lbu         $t6, 0x24($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X24);
    // 0x80064134: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x80064138: sll         $t4, $s7, 16
    ctx->r12 = S32(ctx->r23 << 16);
    // 0x8006413C: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x80064140: sra         $s7, $t4, 16
    ctx->r23 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80064144: slt         $at, $s7, $t6
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80064148: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8006414C: bne         $at, $zero, L_80063F88
    if (ctx->r1 != 0) {
        // 0x80064150: addu        $v1, $v0, $t8
        ctx->r3 = ADD32(ctx->r2, ctx->r24);
            goto L_80063F88;
    }
    // 0x80064150: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
L_80064154:
    // 0x80064154: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
    // 0x80064158: lw          $t9, 0x18($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X18);
    // 0x8006415C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80064160: lw          $t5, 0x14($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X14);
    // 0x80064164: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x80064168: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8006416C: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x80064170: sltu        $at, $t6, $t8
    ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
    // 0x80064174: beq         $at, $zero, L_80064184
    if (ctx->r1 == 0) {
        // 0x80064178: sw          $t8, 0x18($s3)
        MEM_W(0X18, ctx->r19) = ctx->r24;
            goto L_80064184;
    }
    // 0x80064178: sw          $t8, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r24;
    // 0x8006417C: subu        $t9, $t8, $t4
    ctx->r25 = SUB32(ctx->r24, ctx->r12);
    // 0x80064180: sw          $t9, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r25;
L_80064184:
    // 0x80064184: lui         $t7, 0xA00
    ctx->r15 = S32(0XA00 << 16);
    // 0x80064188: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x8006418C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80064190: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80064194: lui         $at, 0x6C0
    ctx->r1 = S32(0X6C0 << 16);
    // 0x80064198: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x8006419C: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x800641A0: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x800641A4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800641A8:
    // 0x800641A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800641AC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800641B0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800641B4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800641B8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800641BC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800641C0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800641C4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800641C8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800641CC: jr          $ra
    // 0x800641D0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800641D0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void weapon_projectile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E6D4: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8003E6D8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003E6DC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8003E6E0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8003E6E4: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x8003E6E8: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E6EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003E6F0: lh          $t6, 0x14($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X14);
    // 0x8003E6F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003E6F8: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x8003E6FC: sh          $t7, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r15;
    // 0x8003E700: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8003E704: lw          $s1, 0x64($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X64);
    // 0x8003E708: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x8003E70C: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003E710: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003E714: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    // 0x8003E718: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8003E71C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003E720: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
    // 0x8003E724: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x8003E728: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8003E72C: sh          $t8, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r24;
    // 0x8003E730: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8003E734: sh          $zero, 0x40($sp)
    MEM_H(0X40, ctx->r29) = 0;
    // 0x8003E738: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8003E73C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8003E740: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8003E744: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8003E748: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x8003E74C: jal         0x8006FE70
    // 0x8003E750: sh          $t9, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r25;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x8003E750: sh          $t9, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r25;
    after_0:
    // 0x8003E754: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003E758: lw          $a3, 0x10($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X10);
    // 0x8003E75C: addiu       $t0, $s0, 0x1C
    ctx->r8 = ADD32(ctx->r16, 0X1C);
    // 0x8003E760: addiu       $t1, $s0, 0x20
    ctx->r9 = ADD32(ctx->r16, 0X20);
    // 0x8003E764: addiu       $t2, $s0, 0x24
    ctx->r10 = ADD32(ctx->r16, 0X24);
    // 0x8003E768: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003E76C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003E770: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8003E774: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8003E778: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8003E77C: jal         0x8006F88C
    // 0x8003E780: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x8003E780: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x8003E784: lw          $t3, 0xEC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XEC);
    // 0x8003E788: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8003E78C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8003E790: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x8003E794: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003E798: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E79C: bne         $t4, $zero, L_8003E7B8
    if (ctx->r12 != 0) {
        // 0x8003E7A0: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8003E7B8;
    }
    // 0x8003E7A0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8003E7A4: lwc1        $f5, 0x6780($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6780);
    // 0x8003E7A8: lwc1        $f4, 0x6784($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6784);
    // 0x8003E7AC: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8003E7B0: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8003E7B4: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
L_8003E7B8:
    // 0x8003E7B8: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003E7BC: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003E7C0: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8003E7C4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8003E7C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003E7CC: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8003E7D0: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8003E7D4: addiu       $a2, $sp, 0xC8
    ctx->r6 = ADD32(ctx->r29, 0XC8);
    // 0x8003E7D8: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    // 0x8003E7DC: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003E7E0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003E7E4: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8003E7E8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8003E7EC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8003E7F0: swc1        $f8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f8.u32l;
    // 0x8003E7F4: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003E7F8: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003E7FC: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8003E800: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8003E804: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    // 0x8003E808: lbu         $t5, 0x18($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X18);
    // 0x8003E80C: nop

    // 0x8003E810: beq         $t5, $at, L_8003E88C
    if (ctx->r13 == ctx->r1) {
        // 0x8003E814: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_8003E88C;
    }
    // 0x8003E814: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8003E818: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003E81C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8003E820: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    // 0x8003E824: jal         0x80031170
    // 0x8003E828: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    generate_collision_candidates(rdram, ctx);
        goto after_2;
    // 0x8003E828: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8003E82C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8003E830: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8003E834: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003E838: addiu       $t8, $sp, 0xA4
    ctx->r24 = ADD32(ctx->r29, 0XA4);
    // 0x8003E83C: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
    // 0x8003E840: sb          $t6, 0x97($sp)
    MEM_B(0X97, ctx->r29) = ctx->r14;
    // 0x8003E844: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003E848: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003E84C: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x8003E850: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    // 0x8003E854: jal         0x80031640
    // 0x8003E858: addiu       $a3, $sp, 0x97
    ctx->r7 = ADD32(ctx->r29, 0X97);
    resolve_collisions(rdram, ctx);
        goto after_3;
    // 0x8003E858: addiu       $a3, $sp, 0x97
    ctx->r7 = ADD32(ctx->r29, 0X97);
    after_3:
    // 0x8003E85C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x8003E860: lwc1        $f2, 0xC0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8003E864: blez        $t9, L_8003E88C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8003E868: addiu       $a0, $sp, 0xB0
        ctx->r4 = ADD32(ctx->r29, 0XB0);
            goto L_8003E88C;
    }
    // 0x8003E868: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x8003E86C: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x8003E870: addiu       $a2, $sp, 0xA8
    ctx->r6 = ADD32(ctx->r29, 0XA8);
    // 0x8003E874: jal         0x8002AD14
    // 0x8003E878: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    get_collision_normal(rdram, ctx);
        goto after_4;
    // 0x8003E878: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x8003E87C: lwc1        $f2, 0xC0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8003E880: beq         $v0, $zero, L_8003E88C
    if (ctx->r2 == 0) {
        // 0x8003E884: nop
    
            goto L_8003E88C;
    }
    // 0x8003E884: nop

    // 0x8003E888: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003E88C:
    // 0x8003E88C: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8003E890: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8003E894: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8003E898: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8003E89C: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8003E8A0: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8003E8A4: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8003E8A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E8AC: sub.s       $f12, $f16, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8003E8B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003E8B4: sub.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8003E8B8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8003E8BC: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8003E8C0: swc1        $f14, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f14.u32l;
    // 0x8003E8C4: swc1        $f12, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f12.u32l;
    // 0x8003E8C8: swc1        $f0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f0.u32l;
    // 0x8003E8CC: jal         0x80011570
    // 0x8003E8D0: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    move_object(rdram, ctx);
        goto after_5;
    // 0x8003E8D0: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x8003E8D4: lwc1        $f2, 0xC0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8003E8D8: beq         $v0, $zero, L_8003E8E4
    if (ctx->r2 == 0) {
        // 0x8003E8DC: nop
    
            goto L_8003E8E4;
    }
    // 0x8003E8DC: nop

    // 0x8003E8E0: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003E8E4:
    // 0x8003E8E4: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8003E8E8: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8003E8EC: mul.s       $f18, $f8, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8003E8F0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003E8F4: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8003E8F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003E8FC: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003E900: nop

    // 0x8003E904: div.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8003E908: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x8003E90C: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003E910: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8003E914: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003E918: nop

    // 0x8003E91C: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8003E920: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8003E924: swc1        $f18, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
    // 0x8003E928: bc1f        L_8003E934
    if (!c1cs) {
        // 0x8003E92C: nop
    
            goto L_8003E934;
    }
    // 0x8003E92C: nop

    // 0x8003E930: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003E934:
    // 0x8003E934: lbu         $v0, 0x18($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X18);
    // 0x8003E938: nop

    // 0x8003E93C: bne         $v0, $zero, L_8003E9CC
    if (ctx->r2 != 0) {
        // 0x8003E940: nop
    
            goto L_8003E9CC;
    }
    // 0x8003E940: nop

    // 0x8003E944: jal         0x8001BA98
    // 0x8003E948: nop

    get_checkpoint_count(rdram, ctx);
        goto after_6;
    // 0x8003E948: nop

    after_6:
    // 0x8003E94C: blez        $v0, L_8003E9C4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003E950: addiu       $t5, $zero, -0x1
        ctx->r13 = ADD32(0, -0X1);
            goto L_8003E9C4;
    }
    // 0x8003E950: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8003E954: lb          $a0, 0x19($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X19);
    // 0x8003E958: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8003E95C: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
    // 0x8003E960: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    // 0x8003E964: addiu       $t0, $s1, 0xC
    ctx->r8 = ADD32(ctx->r17, 0XC);
    // 0x8003E968: addiu       $t1, $sp, 0x97
    ctx->r9 = ADD32(ctx->r29, 0X97);
    // 0x8003E96C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8003E970: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8003E974: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x8003E978: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003E97C: jal         0x80018618
    // 0x8003E980: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    checkpoint_is_passed(rdram, ctx);
        goto after_7;
    // 0x8003E980: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x8003E984: lw          $v1, 0x9C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X9C);
    // 0x8003E988: bne         $v0, $zero, L_8003E9B8
    if (ctx->r2 != 0) {
        // 0x8003E98C: nop
    
            goto L_8003E9B8;
    }
    // 0x8003E98C: nop

    // 0x8003E990: lb          $t2, 0x19($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X19);
    // 0x8003E994: nop

    // 0x8003E998: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8003E99C: sb          $t3, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r11;
    // 0x8003E9A0: lb          $t4, 0x19($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X19);
    // 0x8003E9A4: nop

    // 0x8003E9A8: slt         $at, $t4, $v1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003E9AC: bne         $at, $zero, L_8003E9B8
    if (ctx->r1 != 0) {
        // 0x8003E9B0: nop
    
            goto L_8003E9B8;
    }
    // 0x8003E9B0: nop

    // 0x8003E9B4: sb          $zero, 0x19($s1)
    MEM_B(0X19, ctx->r17) = 0;
L_8003E9B8:
    // 0x8003E9B8: lbu         $v0, 0x18($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X18);
    // 0x8003E9BC: b           L_8003E9CC
    // 0x8003E9C0: nop

        goto L_8003E9CC;
    // 0x8003E9C0: nop

L_8003E9C4:
    // 0x8003E9C4: lbu         $v0, 0x18($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X18);
    // 0x8003E9C8: sb          $t5, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r13;
L_8003E9CC:
    // 0x8003E9CC: bne         $v0, $zero, L_8003E9EC
    if (ctx->r2 != 0) {
        // 0x8003E9D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003E9EC;
    }
    // 0x8003E9D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E9D4: lw          $a1, 0xEC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XEC);
    // 0x8003E9D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E9DC: jal         0x8003EE18
    // 0x8003E9E0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    homing_rocket_prevent_overshoot(rdram, ctx);
        goto after_8;
    // 0x8003E9E0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_8:
    // 0x8003E9E4: b           L_8003E9FC
    // 0x8003E9E8: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
        goto L_8003E9FC;
    // 0x8003E9E8: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
L_8003E9EC:
    // 0x8003E9EC: lw          $a1, 0xEC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XEC);
    // 0x8003E9F0: jal         0x8003EC54
    // 0x8003E9F4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    rocket_prevent_overshoot(rdram, ctx);
        goto after_9;
    // 0x8003E9F4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_9:
    // 0x8003E9F8: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
L_8003E9FC:
    // 0x8003E9FC: nop

    // 0x8003EA00: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003EA04: nop

    // 0x8003EA08: beq         $v0, $zero, L_8003EB44
    if (ctx->r2 == 0) {
        // 0x8003EA0C: nop
    
            goto L_8003EB44;
    }
    // 0x8003EA0C: nop

    // 0x8003EA10: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x8003EA14: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8003EA18: bne         $v0, $t6, L_8003EA4C
    if (ctx->r2 != ctx->r14) {
        // 0x8003EA1C: addiu       $a0, $zero, 0x1C2
        ctx->r4 = ADD32(0, 0X1C2);
            goto L_8003EA4C;
    }
    // 0x8003EA1C: addiu       $a0, $zero, 0x1C2
    ctx->r4 = ADD32(0, 0X1C2);
    // 0x8003EA20: jal         0x8000C8B4
    // 0x8003EA24: sw          $v0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r2;
    normalise_time(rdram, ctx);
        goto after_10;
    // 0x8003EA24: sw          $v0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r2;
    after_10:
    // 0x8003EA28: lw          $v1, 0x78($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X78);
    // 0x8003EA2C: lw          $a1, 0xE4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE4);
    // 0x8003EA30: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003EA34: beq         $at, $zero, L_8003EB44
    if (ctx->r1 == 0) {
        // 0x8003EA38: nop
    
            goto L_8003EB44;
    }
    // 0x8003EA38: nop

    // 0x8003EA3C: beq         $v1, $zero, L_8003EB44
    if (ctx->r3 == 0) {
        // 0x8003EA40: nop
    
            goto L_8003EB44;
    }
    // 0x8003EA40: nop

    // 0x8003EA44: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x8003EA48: nop

L_8003EA4C:
    // 0x8003EA4C: lbu         $t7, 0x18($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X18);
    // 0x8003EA50: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8003EA54: bne         $t7, $zero, L_8003EA7C
    if (ctx->r15 != 0) {
        // 0x8003EA58: nop
    
            goto L_8003EA7C;
    }
    // 0x8003EA58: nop

    // 0x8003EA5C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8003EA60: nop

    // 0x8003EA64: bne         $a1, $t8, L_8003EA74
    if (ctx->r5 != ctx->r24) {
        // 0x8003EA68: nop
    
            goto L_8003EA74;
    }
    // 0x8003EA68: nop

    // 0x8003EA6C: b           L_8003EA7C
    // 0x8003EA70: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
        goto L_8003EA7C;
    // 0x8003EA70: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
L_8003EA74:
    // 0x8003EA74: b           L_8003EA7C
    // 0x8003EA78: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_8003EA7C;
    // 0x8003EA78: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_8003EA7C:
    // 0x8003EA7C: lbu         $t9, 0x13($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X13);
    // 0x8003EA80: nop

    // 0x8003EA84: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003EA88: beq         $at, $zero, L_8003EB44
    if (ctx->r1 == 0) {
        // 0x8003EA8C: nop
    
            goto L_8003EB44;
    }
    // 0x8003EA8C: nop

    // 0x8003EA90: lw          $t0, 0x40($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X40);
    // 0x8003EA94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003EA98: lb          $t1, 0x54($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X54);
    // 0x8003EA9C: nop

    // 0x8003EAA0: bne         $a0, $t1, L_8003EB04
    if (ctx->r4 != ctx->r9) {
        // 0x8003EAA4: nop
    
            goto L_8003EB04;
    }
    // 0x8003EAA4: nop

    // 0x8003EAA8: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x8003EAAC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8003EAB0: sb          $a0, 0x187($v1)
    MEM_B(0X187, ctx->r3) = ctx->r4;
    // 0x8003EAB4: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x8003EAB8: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x8003EABC: lw          $v0, 0x64($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X64);
    // 0x8003EAC0: bne         $a2, $t3, L_8003EAD8
    if (ctx->r6 != ctx->r11) {
        // 0x8003EAC4: nop
    
            goto L_8003EAD8;
    }
    // 0x8003EAC4: nop

    // 0x8003EAC8: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x8003EACC: nop

    // 0x8003EAD0: beq         $a2, $t4, L_8003EAE8
    if (ctx->r6 == ctx->r12) {
        // 0x8003EAD4: nop
    
            goto L_8003EAE8;
    }
    // 0x8003EAD4: nop

L_8003EAD8:
    // 0x8003EAD8: lbu         $t5, 0x1EF($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1EF);
    // 0x8003EADC: nop

    // 0x8003EAE0: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x8003EAE4: sb          $t6, 0x1EF($v0)
    MEM_B(0X1EF, ctx->r2) = ctx->r14;
L_8003EAE8:
    // 0x8003EAE8: lb          $t7, 0x1D8($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1D8);
    // 0x8003EAEC: nop

    // 0x8003EAF0: bne         $t7, $zero, L_8003EB04
    if (ctx->r15 != 0) {
        // 0x8003EAF4: nop
    
            goto L_8003EB04;
    }
    // 0x8003EAF4: nop

    // 0x8003EAF8: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8003EAFC: jal         0x80072594
    // 0x8003EB00: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    rumble_set(rdram, ctx);
        goto after_11;
    // 0x8003EB00: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_11:
L_8003EB04:
    // 0x8003EB04: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003EB08: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003EB0C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003EB10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003EB14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003EB18: addiu       $t8, $zero, 0x11
    ctx->r24 = ADD32(0, 0X11);
    // 0x8003EB1C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003EB20: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8003EB24: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003EB28: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003EB2C: jal         0x8003FC84
    // 0x8003EB30: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_12;
    // 0x8003EB30: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x8003EB34: jal         0x8000FFB8
    // 0x8003EB38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_13;
    // 0x8003EB38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8003EB3C: b           L_8003EC44
    // 0x8003EB40: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003EC44;
    // 0x8003EB40: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003EB44:
    // 0x8003EB44: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
    // 0x8003EB48: lw          $t1, 0xEC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XEC);
    // 0x8003EB4C: lw          $v1, 0x60($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X60);
    // 0x8003EB50: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8003EB54: beq         $v1, $zero, L_8003EBF4
    if (ctx->r3 == 0) {
        // 0x8003EB58: sw          $t2, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r10;
            goto L_8003EBF4;
    }
    // 0x8003EB58: sw          $t2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r10;
    // 0x8003EB5C: lw          $s1, 0x4($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X4);
    // 0x8003EB60: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x8003EB64: beq         $at, $zero, L_8003EB8C
    if (ctx->r1 == 0) {
        // 0x8003EB68: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8003EB8C;
    }
    // 0x8003EB68: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8003EB6C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8003EB70: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003EB74: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003EB78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003EB7C: nop

    // 0x8003EB80: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8003EB84: b           L_8003EBF4
    // 0x8003EB88: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
        goto L_8003EBF4;
    // 0x8003EB88: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
L_8003EB8C:
    // 0x8003EB8C: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x8003EB90: beq         $at, $zero, L_8003EBC8
    if (ctx->r1 == 0) {
        // 0x8003EB94: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8003EBC8;
    }
    // 0x8003EB94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003EB98: addiu       $t3, $v0, -0x8
    ctx->r11 = ADD32(ctx->r2, -0X8);
    // 0x8003EB9C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8003EBA0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8003EBA4: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003EBA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003EBAC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8003EBB0: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8003EBB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003EBB8: nop

    // 0x8003EBBC: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8003EBC0: b           L_8003EBF4
    // 0x8003EBC4: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
        goto L_8003EBF4;
    // 0x8003EBC4: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
L_8003EBC8:
    // 0x8003EBC8: sll         $t4, $a0, 28
    ctx->r12 = S32(ctx->r4 << 28);
    // 0x8003EBCC: jal         0x80070A04
    // 0x8003EBD0: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    sins_f(rdram, ctx);
        goto after_14;
    // 0x8003EBD0: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_14:
    // 0x8003EBD4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8003EBD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003EBDC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003EBE0: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003EBE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003EBE8: nop

    // 0x8003EBEC: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8003EBF0: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
L_8003EBF4:
    // 0x8003EBF4: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x8003EBF8: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8003EBFC: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003EC00: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8003EC04: bgez        $t8, L_8003EC40
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8003EC08: sw          $t8, 0x78($s0)
        MEM_W(0X78, ctx->r16) = ctx->r24;
            goto L_8003EC40;
    }
    // 0x8003EC08: sw          $t8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r24;
    // 0x8003EC0C: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003EC10: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003EC14: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003EC18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003EC1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003EC20: addiu       $t0, $zero, 0x11
    ctx->r8 = ADD32(0, 0X11);
    // 0x8003EC24: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003EC28: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8003EC2C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8003EC30: jal         0x8003FC84
    // 0x8003EC34: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_15;
    // 0x8003EC34: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_15:
    // 0x8003EC38: jal         0x8000FFB8
    // 0x8003EC3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_16;
    // 0x8003EC3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
L_8003EC40:
    // 0x8003EC40: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003EC44:
    // 0x8003EC44: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8003EC48: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8003EC4C: jr          $ra
    // 0x8003EC50: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x8003EC50: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void sprite_init_frame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D210: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007D214: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007D218: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8007D21C: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8007D220: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8007D224: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8007D228: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8007D22C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8007D230: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8007D234: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8007D238: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8007D23C: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x8007D240: addu        $a3, $a0, $a2
    ctx->r7 = ADD32(ctx->r4, ctx->r6);
    // 0x8007D244: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8007D248: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x8007D24C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8007D250: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007D254: lbu         $s2, 0xC($a3)
    ctx->r18 = MEM_BU(ctx->r7, 0XC);
    // 0x8007D258: lbu         $fp, 0xD($a3)
    ctx->r30 = MEM_BU(ctx->r7, 0XD);
    // 0x8007D25C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007D260: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007D264: lw          $t1, 0x6904($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6904);
    // 0x8007D268: lw          $v0, 0x6900($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6900);
    // 0x8007D26C: lw          $v1, 0x6908($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6908);
    // 0x8007D270: slt         $at, $s2, $fp
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x8007D274: beq         $at, $zero, L_8007D2A0
    if (ctx->r1 == 0) {
        // 0x8007D278: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8007D2A0;
    }
    // 0x8007D278: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8007D27C: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x8007D280: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x8007D284: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8007D288: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8007D28C: nop

    // 0x8007D290: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x8007D294: nop

    // 0x8007D298: andi        $t9, $t8, 0x3B
    ctx->r25 = ctx->r24 & 0X3B;
    // 0x8007D29C: sh          $t9, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r25;
L_8007D2A0:
    // 0x8007D2A0: slt         $at, $s2, $fp
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x8007D2A4: beq         $at, $zero, L_8007D4D8
    if (ctx->r1 == 0) {
        // 0x8007D2A8: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_8007D4D8;
    }
    // 0x8007D2A8: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8007D2AC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8007D2B0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8007D2B4: sll         $s3, $s2, 2
    ctx->r19 = S32(ctx->r18 << 2);
    // 0x8007D2B8: lui         $ra, 0x700
    ctx->r31 = S32(0X700 << 16);
    // 0x8007D2BC: addiu       $s7, $zero, 0x40
    ctx->r23 = ADD32(0, 0X40);
    // 0x8007D2C0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8007D2C4: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
    // 0x8007D2C8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_8007D2CC:
    // 0x8007D2CC: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8007D2D0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8007D2D4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8007D2D8: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8007D2DC: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8007D2E0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007D2E4: lbu         $s0, 0x0($a0)
    ctx->r16 = MEM_BU(ctx->r4, 0X0);
    // 0x8007D2E8: lbu         $s1, 0x1($a0)
    ctx->r17 = MEM_BU(ctx->r4, 0X1);
    // 0x8007D2EC: lb          $t9, 0x3($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X3);
    // 0x8007D2F0: lb          $t8, 0x4($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X4);
    // 0x8007D2F4: subu        $t0, $t9, $t6
    ctx->r8 = SUB32(ctx->r25, ctx->r14);
    // 0x8007D2F8: subu        $a2, $t7, $t8
    ctx->r6 = SUB32(ctx->r15, ctx->r24);
    // 0x8007D2FC: addu        $t3, $t0, $s0
    ctx->r11 = ADD32(ctx->r8, ctx->r16);
    // 0x8007D300: addiu       $a3, $a2, -0x1
    ctx->r7 = ADD32(ctx->r6, -0X1);
    // 0x8007D304: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x8007D308: subu        $t4, $a2, $s1
    ctx->r12 = SUB32(ctx->r6, ctx->r17);
    // 0x8007D30C: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x8007D310: sh          $a3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r7;
    // 0x8007D314: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8007D318: sb          $a1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r5;
    // 0x8007D31C: sb          $a1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r5;
    // 0x8007D320: sb          $a1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r5;
    // 0x8007D324: sb          $a1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r5;
    // 0x8007D328: sh          $t3, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r11;
    // 0x8007D32C: sh          $a3, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r7;
    // 0x8007D330: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x8007D334: sb          $a1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r5;
    // 0x8007D338: sb          $a1, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r5;
    // 0x8007D33C: sb          $a1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r5;
    // 0x8007D340: sb          $a1, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r5;
    // 0x8007D344: sh          $t3, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r11;
    // 0x8007D348: sh          $t4, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r12;
    // 0x8007D34C: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
    // 0x8007D350: sb          $a1, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r5;
    // 0x8007D354: sb          $a1, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r5;
    // 0x8007D358: sb          $a1, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r5;
    // 0x8007D35C: sb          $a1, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r5;
    // 0x8007D360: sh          $t0, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r8;
    // 0x8007D364: sh          $t4, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r12;
    // 0x8007D368: sh          $zero, 0x22($v0)
    MEM_H(0X22, ctx->r2) = 0;
    // 0x8007D36C: sb          $a1, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r5;
    // 0x8007D370: sb          $a1, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r5;
    // 0x8007D374: sb          $a1, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r5;
    // 0x8007D378: sb          $a1, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r5;
    // 0x8007D37C: lh          $a3, 0xA($a0)
    ctx->r7 = MEM_H(ctx->r4, 0XA);
    // 0x8007D380: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x8007D384: andi        $t9, $a3, 0xFF
    ctx->r25 = ctx->r7 & 0XFF;
    // 0x8007D388: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x8007D38C: sll         $t8, $a3, 3
    ctx->r24 = S32(ctx->r7 << 3);
    // 0x8007D390: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8007D394: or          $t7, $t6, $ra
    ctx->r15 = ctx->r14 | ctx->r31;
    // 0x8007D398: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8007D39C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8007D3A0: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x8007D3A4: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x8007D3A8: addu        $t7, $t8, $s4
    ctx->r15 = ADD32(ctx->r24, ctx->r20);
    // 0x8007D3AC: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8007D3B0: bne         $t5, $zero, L_8007D41C
    if (ctx->r13 != 0) {
        // 0x8007D3B4: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_8007D41C;
    }
    // 0x8007D3B4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8007D3B8: subu        $t0, $fp, $s2
    ctx->r8 = SUB32(ctx->r30, ctx->r18);
    // 0x8007D3BC: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // 0x8007D3C0: bne         $at, $zero, L_8007D3CC
    if (ctx->r1 != 0) {
        // 0x8007D3C4: or          $a2, $t1, $zero
        ctx->r6 = ctx->r9 | 0;
            goto L_8007D3CC;
    }
    // 0x8007D3C4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x8007D3C8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
L_8007D3CC:
    // 0x8007D3CC: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
    // 0x8007D3D0: addiu       $t9, $a0, -0x1
    ctx->r25 = ADD32(ctx->r4, -0X1);
    // 0x8007D3D4: addu        $a3, $s6, $s4
    ctx->r7 = ADD32(ctx->r22, ctx->r20);
    // 0x8007D3D8: andi        $t8, $a3, 0x6
    ctx->r24 = ctx->r7 & 0X6;
    // 0x8007D3DC: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x8007D3E0: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8007D3E4: ori         $t9, $t7, 0x1
    ctx->r25 = ctx->r15 | 0X1;
    // 0x8007D3E8: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8007D3EC: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x8007D3F0: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8007D3F4: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8007D3F8: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8007D3FC: addu        $t6, $t9, $a0
    ctx->r14 = ADD32(ctx->r25, ctx->r4);
    // 0x8007D400: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8007D404: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8007D408: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8007D40C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8007D410: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8007D414: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
    // 0x8007D418: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_8007D41C:
    // 0x8007D41C: lui         $t9, 0x511
    ctx->r25 = S32(0X511 << 16);
    // 0x8007D420: ori         $t9, $t9, 0x20
    ctx->r25 = ctx->r25 | 0X20;
    // 0x8007D424: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8007D428: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007D42C: addu        $t7, $v1, $s4
    ctx->r15 = ADD32(ctx->r3, ctx->r20);
    // 0x8007D430: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007D434: addiu       $a2, $s0, -0x1
    ctx->r6 = ADD32(ctx->r16, -0X1);
    // 0x8007D438: addiu       $a3, $s1, -0x1
    ctx->r7 = ADD32(ctx->r17, -0X1);
    // 0x8007D43C: addiu       $t0, $t2, 0x3
    ctx->r8 = ADD32(ctx->r10, 0X3);
    // 0x8007D440: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007D444: sll         $t8, $a2, 5
    ctx->r24 = S32(ctx->r6 << 5);
    // 0x8007D448: sll         $t9, $a3, 5
    ctx->r25 = S32(ctx->r7 << 5);
    // 0x8007D44C: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8007D450: addiu       $t6, $t2, 0x2
    ctx->r14 = ADD32(ctx->r10, 0X2);
    // 0x8007D454: addiu       $a0, $t2, 0x4
    ctx->r4 = ADD32(ctx->r10, 0X4);
    // 0x8007D458: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x8007D45C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8007D460: sb          $s7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r23;
    // 0x8007D464: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    // 0x8007D468: sb          $t6, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r14;
    // 0x8007D46C: sb          $t3, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r11;
    // 0x8007D470: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x8007D474: sh          $t9, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r25;
    // 0x8007D478: sh          $t8, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r24;
    // 0x8007D47C: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x8007D480: sh          $s5, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r21;
    // 0x8007D484: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x8007D488: sb          $s7, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r23;
    // 0x8007D48C: sb          $a0, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r4;
    // 0x8007D490: sb          $t0, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r8;
    // 0x8007D494: sb          $t3, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r11;
    // 0x8007D498: sh          $s5, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r21;
    // 0x8007D49C: sh          $t9, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r25;
    // 0x8007D4A0: sh          $t8, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r24;
    // 0x8007D4A4: sh          $t9, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r25;
    // 0x8007D4A8: sh          $s5, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r21;
    // 0x8007D4AC: sh          $zero, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = 0;
    // 0x8007D4B0: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8007D4B4: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8007D4B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007D4BC: bne         $at, $zero, L_8007D4CC
    if (ctx->r1 != 0) {
        // 0x8007D4C0: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_8007D4CC;
    }
    // 0x8007D4C0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8007D4C4: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8007D4C8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8007D4CC:
    // 0x8007D4CC: slt         $at, $s2, $fp
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x8007D4D0: bne         $at, $zero, L_8007D2CC
    if (ctx->r1 != 0) {
        // 0x8007D4D4: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8007D2CC;
    }
    // 0x8007D4D4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_8007D4D8:
    // 0x8007D4D8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8007D4DC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007D4E0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007D4E4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007D4E8: addiu       $a1, $t1, 0x8
    ctx->r5 = ADD32(ctx->r9, 0X8);
    // 0x8007D4EC: lui         $t6, 0xB800
    ctx->r14 = S32(0XB800 << 16);
    // 0x8007D4F0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007D4F4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8007D4F8: addiu       $t1, $a1, 0x8
    ctx->r9 = ADD32(ctx->r5, 0X8);
    // 0x8007D4FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007D500: sw          $t1, 0x6904($at)
    MEM_W(0X6904, ctx->r1) = ctx->r9;
    // 0x8007D504: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007D508: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D50C: sw          $v0, 0x6900($at)
    MEM_W(0X6900, ctx->r1) = ctx->r2;
    // 0x8007D510: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007D514: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8007D518: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8007D51C: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8007D520: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D524: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8007D528: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8007D52C: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8007D530: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8007D534: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8007D538: sw          $v1, 0x6908($at)
    MEM_W(0X6908, ctx->r1) = ctx->r3;
    // 0x8007D53C: jr          $ra
    // 0x8007D540: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8007D540: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void get_file_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076D4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80076D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076D54: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80076D58: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80076D5C: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80076D60: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80076D64: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80076D68: jal         0x80070EDC
    // 0x80076D6C: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80076D6C: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_0:
    // 0x80076D70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80076D74: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80076D78: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80076D7C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80076D80: jal         0x80076868
    // 0x80076D84: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    read_data_from_controller_pak(rdram, ctx);
        goto after_1;
    // 0x80076D84: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_1:
    // 0x80076D88: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80076D8C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80076D90: bne         $v0, $zero, L_80076DDC
    if (ctx->r2 != 0) {
        // 0x80076D94: lui         $at, 0x4741
        ctx->r1 = S32(0X4741 << 16);
            goto L_80076DDC;
    }
    // 0x80076D94: lui         $at, 0x4741
    ctx->r1 = S32(0X4741 << 16);
    // 0x80076D98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80076D9C: ori         $at, $at, 0x4D44
    ctx->r1 = ctx->r1 | 0X4D44;
    // 0x80076DA0: beq         $v0, $at, L_80076DC8
    if (ctx->r2 == ctx->r1) {
        // 0x80076DA4: lui         $at, 0x4748
        ctx->r1 = S32(0X4748 << 16);
            goto L_80076DC8;
    }
    // 0x80076DA4: lui         $at, 0x4748
    ctx->r1 = S32(0X4748 << 16);
    // 0x80076DA8: ori         $at, $at, 0x5353
    ctx->r1 = ctx->r1 | 0X5353;
    // 0x80076DAC: beq         $v0, $at, L_80076DD8
    if (ctx->r2 == ctx->r1) {
        // 0x80076DB0: lui         $at, 0x5449
        ctx->r1 = S32(0X5449 << 16);
            goto L_80076DD8;
    }
    // 0x80076DB0: lui         $at, 0x5449
    ctx->r1 = S32(0X5449 << 16);
    // 0x80076DB4: ori         $at, $at, 0x4D44
    ctx->r1 = ctx->r1 | 0X4D44;
    // 0x80076DB8: beq         $v0, $at, L_80076DD0
    if (ctx->r2 == ctx->r1) {
        // 0x80076DBC: nop
    
            goto L_80076DD0;
    }
    // 0x80076DBC: nop

    // 0x80076DC0: b           L_80076DDC
    // 0x80076DC4: nop

        goto L_80076DDC;
    // 0x80076DC4: nop

L_80076DC8:
    // 0x80076DC8: b           L_80076DDC
    // 0x80076DCC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80076DDC;
    // 0x80076DCC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80076DD0:
    // 0x80076DD0: b           L_80076DDC
    // 0x80076DD4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80076DDC;
    // 0x80076DD4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80076DD8:
    // 0x80076DD8: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80076DDC:
    // 0x80076DDC: jal         0x80071380
    // 0x80076DE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_2;
    // 0x80076DE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80076DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076DE8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80076DEC: jr          $ra
    // 0x80076DF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80076DF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alCSPNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800624D0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800624D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800624D8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800624DC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800624E0: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x800624E4: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800624E8: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800624EC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800624F0: lw          $t6, 0x3D10($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3D10);
    // 0x800624F4: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x800624F8: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x800624FC: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x80062500: addiu       $t0, $zero, 0x3E80
    ctx->r8 = ADD32(0, 0X3E80);
    // 0x80062504: sh          $t7, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r15;
    // 0x80062508: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x8006250C: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x80062510: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80062514: sh          $t9, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r25;
    // 0x80062518: sw          $t0, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r8;
    // 0x8006251C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x80062520: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x80062524: lw          $t1, 0x14($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X14);
    // 0x80062528: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8006252C: sw          $t1, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r9;
    // 0x80062530: lw          $t2, 0x18($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X18);
    // 0x80062534: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80062538: sw          $t2, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r10;
    // 0x8006253C: lw          $t3, 0x1C($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X1C);
    // 0x80062540: sb          $zero, 0x71($a0)
    MEM_B(0X71, ctx->r4) = 0;
    // 0x80062544: sw          $t3, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r11;
    // 0x80062548: lbu         $t4, 0x10($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X10);
    // 0x8006254C: sh          $t5, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r13;
    // 0x80062550: sb          $t4, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r12;
    // 0x80062554: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x80062558: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006255C: sb          $t6, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r14;
    // 0x80062560: lbu         $a3, 0x8($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X8);
    // 0x80062564: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80062568: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8006256C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80062570: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80062574: jal         0x800C7D50
    // 0x80062578: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x80062578: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8006257C: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x80062580: jal         0x8000AE90
    // 0x80062584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __initChanState(rdram, ctx);
        goto after_1;
    // 0x80062584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80062588: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8006258C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80062590: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x80062594: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80062598: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006259C: jal         0x800C7D50
    // 0x800625A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800625A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800625A4: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x800625A8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800625AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800625B0: blez        $t9, L_800625E0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800625B4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800625E0;
    }
    // 0x800625B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800625B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800625BC:
    // 0x800625BC: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    // 0x800625C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800625C4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800625C8: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
    // 0x800625CC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800625D0: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x800625D4: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800625D8: bne         $at, $zero, L_800625BC
    if (ctx->r1 != 0) {
        // 0x800625DC: nop
    
            goto L_800625BC;
    }
    // 0x800625DC: nop

L_800625E0:
    // 0x800625E0: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x800625E4: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x800625E8: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x800625EC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800625F0: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x800625F4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800625F8: jal         0x800C7D50
    // 0x800625FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800625FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80062600: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80062604: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x80062608: jal         0x800C98BC
    // 0x8006260C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alEvtqNew(rdram, ctx);
        goto after_4;
    // 0x8006260C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80062610: lui         $t3, 0x8006
    ctx->r11 = S32(0X8006 << 16);
    // 0x80062614: addiu       $t3, $t3, 0x2648
    ctx->r11 = ADD32(ctx->r11, 0X2648);
    // 0x80062618: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8006261C: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x80062620: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x80062624: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80062628: lw          $a0, 0x3D10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3D10);
    // 0x8006262C: jal         0x800C9930
    // 0x80062630: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynAddPlayer(rdram, ctx);
        goto after_5;
    // 0x80062630: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80062634: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80062638: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8006263C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80062640: jr          $ra
    // 0x80062644: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80062644: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void transition_render_barndoor_diag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2A68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2A6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2A70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C2A74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C2A78: jal         0x8007B820
    // 0x800C2A7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800C2A7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C2A80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C2A84: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C2A88: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C2A8C: addiu       $t8, $t8, 0x3BD8
    ctx->r24 = ADD32(ctx->r24, 0X3BD8);
    // 0x800C2A90: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800C2A94: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C2A98: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C2A9C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C2AA0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800C2AA4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C2AA8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C2AAC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800C2AB0: addiu       $a3, $a3, 0x3760
    ctx->r7 = ADD32(ctx->r7, 0X3760);
    // 0x800C2AB4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C2AB8: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800C2ABC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C2AC0: addiu       $t1, $t1, 0x3750
    ctx->r9 = ADD32(ctx->r9, 0X3750);
    // 0x800C2AC4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C2AC8: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800C2ACC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800C2AD0: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800C2AD4: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x800C2AD8: andi        $t7, $t6, 0x6
    ctx->r15 = ctx->r14 & 0X6;
    // 0x800C2ADC: ori         $t8, $t7, 0x48
    ctx->r24 = ctx->r15 | 0X48;
    // 0x800C2AE0: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800C2AE4: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800C2AE8: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800C2AEC: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800C2AF0: ori         $t4, $t3, 0xBC
    ctx->r12 = ctx->r11 | 0XBC;
    // 0x800C2AF4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800C2AF8: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800C2AFC: lui         $t3, 0x550
    ctx->r11 = S32(0X550 << 16);
    // 0x800C2B00: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800C2B04: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800C2B08: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800C2B0C: ori         $t3, $t3, 0x60
    ctx->r11 = ctx->r11 | 0X60;
    // 0x800C2B10: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800C2B14: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C2B18: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C2B1C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C2B20: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800C2B24: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800C2B28: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800C2B2C: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800C2B30: nop

    // 0x800C2B34: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C2B38: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800C2B3C: lw          $t6, 0x3758($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3758);
    // 0x800C2B40: nop

    // 0x800C2B44: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800C2B48: jal         0x8007B820
    // 0x800C2B4C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C2B4C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    after_1:
    // 0x800C2B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2B54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2B58: jr          $ra
    // 0x800C2B5C: nop

    return;
    // 0x800C2B5C: nop

;}
RECOMP_FUNC void trackMakeAbsolute(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D34C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002D350: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002D354: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002D358: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002D35C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8002D360: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D364: beq         $s0, $zero, L_8002D3B4
    if (ctx->r16 == 0) {
        // 0x8002D368: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8002D3B4;
    }
    // 0x8002D368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002D36C:
    // 0x8002D36C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8002D370: nop

    // 0x8002D374: beq         $v0, $zero, L_8002D380
    if (ctx->r2 == 0) {
        // 0x8002D378: addu        $t6, $v0, $s1
        ctx->r14 = ADD32(ctx->r2, ctx->r17);
            goto L_8002D380;
    }
    // 0x8002D378: addu        $t6, $v0, $s1
    ctx->r14 = ADD32(ctx->r2, ctx->r17);
    // 0x8002D37C: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_8002D380:
    // 0x8002D380: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8002D384: nop

    // 0x8002D388: beq         $v0, $zero, L_8002D394
    if (ctx->r2 == 0) {
        // 0x8002D38C: addu        $t7, $v0, $s1
        ctx->r15 = ADD32(ctx->r2, ctx->r17);
            goto L_8002D394;
    }
    // 0x8002D38C: addu        $t7, $v0, $s1
    ctx->r15 = ADD32(ctx->r2, ctx->r17);
    // 0x8002D390: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
L_8002D394:
    // 0x8002D394: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8002D398: jal         0x8002D34C
    // 0x8002D39C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    trackMakeAbsolute(rdram, ctx);
        goto after_0;
    // 0x8002D39C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8002D3A0: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x8002D3A4: nop

    // 0x8002D3A8: bne         $s0, $zero, L_8002D36C
    if (ctx->r16 != 0) {
        // 0x8002D3AC: nop
    
            goto L_8002D36C;
    }
    // 0x8002D3AC: nop

    // 0x8002D3B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002D3B4:
    // 0x8002D3B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002D3B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002D3BC: jr          $ra
    // 0x8002D3C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002D3C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void timetrial_init_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B69C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001B6A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B6A4: jal         0x800599F8
    // 0x8001B6A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    timetrial_map_id(rdram, ctx);
        goto after_0;
    // 0x8001B6A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001B6AC: jal         0x8006BFC8
    // 0x8001B6B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    level_id(rdram, ctx);
        goto after_1;
    // 0x8001B6B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001B6B4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001B6B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001B6BC: bne         $v0, $t6, L_8001B6D8
    if (ctx->r2 != ctx->r14) {
        // 0x8001B6C0: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_8001B6D8;
    }
    // 0x8001B6C0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8001B6C4: lh          $t7, -0x4BFE($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X4BFE);
    // 0x8001B6C8: lh          $t8, -0x3368($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X3368);
    // 0x8001B6CC: nop

    // 0x8001B6D0: beq         $t7, $t8, L_8001B738
    if (ctx->r15 == ctx->r24) {
        // 0x8001B6D4: nop
    
            goto L_8001B738;
    }
    // 0x8001B6D4: nop

L_8001B6D8:
    // 0x8001B6D8: jal         0x8006BFC8
    // 0x8001B6DC: nop

    level_id(rdram, ctx);
        goto after_2;
    // 0x8001B6DC: nop

    after_2:
    // 0x8001B6E0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001B6E4: lh          $a2, -0x4BFE($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X4BFE);
    // 0x8001B6E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8001B6EC: addiu       $t9, $sp, 0x2C
    ctx->r25 = ADD32(ctx->r29, 0X2C);
    // 0x8001B6F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8001B6F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001B6F8: jal         0x80059A08
    // 0x8001B6FC: addiu       $a3, $sp, 0x2E
    ctx->r7 = ADD32(ctx->r29, 0X2E);
    timetrial_load_player_ghost(rdram, ctx);
        goto after_3;
    // 0x8001B6FC: addiu       $a3, $sp, 0x2E
    ctx->r7 = ADD32(ctx->r29, 0X2E);
    after_3:
    // 0x8001B700: bne         $v0, $zero, L_8001B730
    if (ctx->r2 != 0) {
        // 0x8001B704: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8001B730;
    }
    // 0x8001B704: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001B708: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8001B70C: lh          $t0, -0x4BFE($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4BFE);
    // 0x8001B710: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B714: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x8001B718: sh          $t0, -0x3368($at)
    MEM_H(-0X3368, ctx->r1) = ctx->r8;
    // 0x8001B71C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B720: lh          $t2, 0x2C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2C);
    // 0x8001B724: sh          $t1, -0x3364($at)
    MEM_H(-0X3364, ctx->r1) = ctx->r9;
    // 0x8001B728: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B72C: sh          $t2, -0x336C($at)
    MEM_H(-0X336C, ctx->r1) = ctx->r10;
L_8001B730:
    // 0x8001B730: b           L_8001B75C
    // 0x8001B734: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8001B75C;
    // 0x8001B734: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001B738:
    // 0x8001B738: jal         0x8006BFC8
    // 0x8001B73C: nop

    level_id(rdram, ctx);
        goto after_4;
    // 0x8001B73C: nop

    after_4:
    // 0x8001B740: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001B744: lh          $a2, -0x4BFE($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X4BFE);
    // 0x8001B748: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8001B74C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001B750: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001B754: jal         0x80059A08
    // 0x8001B758: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    timetrial_load_player_ghost(rdram, ctx);
        goto after_5;
    // 0x8001B758: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
L_8001B75C:
    // 0x8001B75C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B760: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001B764: jr          $ra
    // 0x8001B768: nop

    return;
    // 0x8001B768: nop

;}
RECOMP_FUNC void mempool_slot_assign(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800719CC: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x800719D0: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800719D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800719D8: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x800719DC: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800719E0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800719E4: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800719E8: mflo        $t8
    ctx->r24 = lo;
    // 0x800719EC: addu        $t0, $v0, $t8
    ctx->r8 = ADD32(ctx->r2, ctx->r24);
    // 0x800719F0: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800719F4: sh          $a3, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r7;
    // 0x800719F8: sw          $a2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r6;
    // 0x800719FC: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80071A00: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80071A04: beq         $at, $zero, L_80071A84
    if (ctx->r1 == 0) {
        // 0x80071A08: sw          $t9, 0x10($t0)
        MEM_W(0X10, ctx->r8) = ctx->r25;
            goto L_80071A84;
    }
    // 0x80071A08: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x80071A0C: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x80071A10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80071A14: multu       $a3, $t3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071A18: addiu       $t6, $a3, 0x1
    ctx->r14 = ADD32(ctx->r7, 0X1);
    // 0x80071A1C: mflo        $t4
    ctx->r12 = lo;
    // 0x80071A20: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80071A24: lh          $a0, 0xE($t5)
    ctx->r4 = MEM_H(ctx->r13, 0XE);
    // 0x80071A28: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80071A2C: multu       $a0, $t3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071A30: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80071A34: subu        $t4, $t1, $a2
    ctx->r12 = SUB32(ctx->r9, ctx->r6);
    // 0x80071A38: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x80071A3C: mflo        $t7
    ctx->r15 = lo;
    // 0x80071A40: addu        $t2, $v0, $t7
    ctx->r10 = ADD32(ctx->r2, ctx->r15);
    // 0x80071A44: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80071A48: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80071A4C: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x80071A50: nop

    // 0x80071A54: sh          $t5, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r13;
    // 0x80071A58: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x80071A5C: sh          $a1, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r5;
    // 0x80071A60: sh          $t1, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r9;
    // 0x80071A64: beq         $t1, $at, L_80071A7C
    if (ctx->r9 == ctx->r1) {
        // 0x80071A68: sh          $a0, 0xC($t0)
        MEM_H(0XC, ctx->r8) = ctx->r4;
            goto L_80071A7C;
    }
    // 0x80071A68: sh          $a0, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r4;
    // 0x80071A6C: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071A70: mflo        $t6
    ctx->r14 = lo;
    // 0x80071A74: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80071A78: sh          $a0, 0xA($t7)
    MEM_H(0XA, ctx->r15) = ctx->r4;
L_80071A7C:
    // 0x80071A7C: jr          $ra
    // 0x80071A80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80071A80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80071A84:
    // 0x80071A84: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80071A88: jr          $ra
    // 0x80071A8C: nop

    return;
    // 0x80071A8C: nop

;}
RECOMP_FUNC void menu_init_arrow_textures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E968: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008E96C: addiu       $v0, $v0, 0x6AF0
    ctx->r2 = ADD32(ctx->r2, 0X6AF0);
    // 0x8008E970: lw          $t6, 0xF4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF4);
    // 0x8008E974: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E978: sw          $t6, 0x99C($at)
    MEM_W(0X99C, ctx->r1) = ctx->r14;
    // 0x8008E97C: lw          $t7, 0xF0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XF0);
    // 0x8008E980: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E984: sw          $t7, 0x9AC($at)
    MEM_W(0X9AC, ctx->r1) = ctx->r15;
    // 0x8008E988: lw          $t8, 0xFC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XFC);
    // 0x8008E98C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E990: sw          $t8, 0x9BC($at)
    MEM_W(0X9BC, ctx->r1) = ctx->r24;
    // 0x8008E994: lw          $t9, 0xF8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XF8);
    // 0x8008E998: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E99C: jr          $ra
    // 0x8008E9A0: sw          $t9, 0x9CC($at)
    MEM_W(0X9CC, ctx->r1) = ctx->r25;
    return;
    // 0x8008E9A0: sw          $t9, 0x9CC($at)
    MEM_W(0X9CC, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void func_8008FF1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800903D4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800903D8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800903DC: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800903E0: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800903E4: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800903E8: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800903EC: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800903F0: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800903F4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800903F8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800903FC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80090400: jal         0x8006ECD0
    // 0x80090404: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80090404: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    after_0:
    // 0x80090408: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8009040C: jal         0x8001E2D0
    // 0x80090410: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x80090410: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_1:
    // 0x80090414: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80090418: lw          $v1, -0x604($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X604);
    // 0x8009041C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80090420: slti        $at, $v1, -0x16
    ctx->r1 = SIGNED(ctx->r3) < -0X16 ? 1 : 0;
    // 0x80090424: bne         $at, $zero, L_80090970
    if (ctx->r1 != 0) {
        // 0x80090428: slti        $at, $v1, 0x17
        ctx->r1 = SIGNED(ctx->r3) < 0X17 ? 1 : 0;
            goto L_80090970;
    }
    // 0x80090428: slti        $at, $v1, 0x17
    ctx->r1 = SIGNED(ctx->r3) < 0X17 ? 1 : 0;
    // 0x8009042C: beq         $at, $zero, L_80090970
    if (ctx->r1 == 0) {
        // 0x80090430: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80090970;
    }
    // 0x80090430: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80090434: lh          $t6, 0x6ED8($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6ED8);
    // 0x80090438: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009043C: bne         $t6, $at, L_80090450
    if (ctx->r14 != ctx->r1) {
        // 0x80090440: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_80090450;
    }
    // 0x80090440: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80090444: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80090448: b           L_80090454
    // 0x8009044C: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
        goto L_80090454;
    // 0x8009044C: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
L_80090450:
    // 0x80090450: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
L_80090454:
    // 0x80090454: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090458: lwc1        $f4, 0x6F9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F9C);
    // 0x8009045C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80090460: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80090464: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80090468: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009046C: lw          $t1, 0x6A20($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6A20);
    // 0x80090470: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80090474: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x80090478: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8009047C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80090480: addiu       $s0, $s0, 0x6EF0
    ctx->r16 = ADD32(ctx->r16, 0X6EF0);
    // 0x80090484: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x80090488: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x8009048C: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x80090490: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80090494: nop

    // 0x80090498: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8009049C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800904A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800904A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800904A8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800904AC: lwc1        $f16, 0x6FA4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x800904B0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800904B4: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800904B8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800904BC: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x800904C0: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800904C4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800904C8: nop

    // 0x800904CC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800904D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800904D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800904D8: nop

    // 0x800904DC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800904E0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800904E4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800904E8: addiu       $s3, $v0, -0x1
    ctx->r19 = ADD32(ctx->r2, -0X1);
    // 0x800904EC: nop

L_800904F0:
    // 0x800904F0: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_800904F4:
    // 0x800904F4: bltz        $s3, L_80090520
    if (SIGNED(ctx->r19) < 0) {
        // 0x800904F8: nop
    
            goto L_80090520;
    }
    // 0x800904F8: nop

    // 0x800904FC: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80090500: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80090504: slt         $at, $t5, $s3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80090508: bne         $at, $zero, L_80090520
    if (ctx->r1 != 0) {
        // 0x8009050C: addu        $s2, $t6, $s6
        ctx->r18 = ADD32(ctx->r14, ctx->r22);
            goto L_80090520;
    }
    // 0x8009050C: addu        $s2, $t6, $s6
    ctx->r18 = ADD32(ctx->r14, ctx->r22);
    // 0x80090510: bltz        $s2, L_80090520
    if (SIGNED(ctx->r18) < 0) {
        // 0x80090514: slti        $at, $s2, 0x6
        ctx->r1 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
            goto L_80090520;
    }
    // 0x80090514: slti        $at, $s2, 0x6
    ctx->r1 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
    // 0x80090518: bne         $at, $zero, L_80090528
    if (ctx->r1 != 0) {
        // 0x8009051C: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80090528;
    }
    // 0x8009051C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80090520:
    // 0x80090520: b           L_8009082C
    // 0x80090524: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
        goto L_8009082C;
    // 0x80090524: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
L_80090528:
    // 0x80090528: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x8009052C: subu        $t8, $t8, $s3
    ctx->r24 = SUB32(ctx->r24, ctx->r19);
    // 0x80090530: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80090534: sll         $s4, $s2, 2
    ctx->r20 = S32(ctx->r18 << 2);
    // 0x80090538: sll         $t9, $s2, 1
    ctx->r25 = S32(ctx->r18 << 1);
    // 0x8009053C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80090540: addiu       $t1, $t1, 0x6EA8
    ctx->r9 = ADD32(ctx->r9, 0X6EA8);
    // 0x80090544: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80090548: addu        $s4, $s4, $s2
    ctx->r20 = ADD32(ctx->r20, ctx->r18);
    // 0x8009054C: sb          $t7, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r15;
    // 0x80090550: sll         $s4, $s4, 6
    ctx->r20 = S32(ctx->r20 << 6);
    // 0x80090554: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
    // 0x80090558: addiu       $a0, $s3, 0x1
    ctx->r4 = ADD32(ctx->r19, 0X1);
    // 0x8009055C: jal         0x8006B414
    // 0x80090560: negu        $s5, $s3
    ctx->r21 = SUB32(0, ctx->r19);
    level_world_id(rdram, ctx);
        goto after_2;
    // 0x80090560: negu        $s5, $s3
    ctx->r21 = SUB32(0, ctx->r19);
    after_2:
    // 0x80090564: jal         0x8006C01C
    // 0x80090568: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    level_name(rdram, ctx);
        goto after_3;
    // 0x80090568: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8009056C: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    // 0x80090570: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80090574: beq         $t2, $at, L_80090600
    if (ctx->r10 == ctx->r1) {
        // 0x80090578: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80090600;
    }
    // 0x80090578: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8009057C: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    // 0x80090580: subu        $t3, $t3, $s3
    ctx->r11 = SUB32(ctx->r11, ctx->r19);
    // 0x80090584: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80090588: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8009058C: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x80090590: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x80090594: lb          $a0, 0x0($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X0);
    // 0x80090598: jal         0x8006C01C
    // 0x8009059C: nop

    level_name(rdram, ctx);
        goto after_4;
    // 0x8009059C: nop

    after_4:
    // 0x800905A0: bne         $s2, $s7, L_800905D0
    if (ctx->r18 != ctx->r23) {
        // 0x800905A4: sw          $v0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r2;
            goto L_800905D0;
    }
    // 0x800905A4: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800905A8: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800905AC: sll         $t8, $s3, 1
    ctx->r24 = S32(ctx->r19 << 1);
    // 0x800905B0: lhu         $t7, 0xE($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XE);
    // 0x800905B4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800905B8: srav        $t9, $t7, $t8
    ctx->r25 = S32(SIGNED(ctx->r15) >> (ctx->r24 & 31));
    // 0x800905BC: andi        $t0, $t9, 0x3
    ctx->r8 = ctx->r25 & 0X3;
    // 0x800905C0: bne         $fp, $t0, L_80090610
    if (ctx->r30 != ctx->r8) {
        // 0x800905C4: nop
    
            goto L_80090610;
    }
    // 0x800905C4: nop

    // 0x800905C8: b           L_80090610
    // 0x800905CC: sb          $t1, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r9;
        goto L_80090610;
    // 0x800905CC: sb          $t1, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r9;
L_800905D0:
    // 0x800905D0: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800905D4: lb          $t4, 0x0($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X0);
    // 0x800905D8: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800905DC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800905E0: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800905E4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800905E8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800905EC: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800905F0: beq         $t8, $zero, L_80090610
    if (ctx->r24 == 0) {
        // 0x800905F4: nop
    
            goto L_80090610;
    }
    // 0x800905F4: nop

    // 0x800905F8: b           L_80090610
    // 0x800905FC: sb          $t9, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r25;
        goto L_80090610;
    // 0x800905FC: sb          $t9, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r25;
L_80090600:
    // 0x80090600: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80090604: lw          $t0, 0xEF8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XEF8);
    // 0x80090608: nop

    // 0x8009060C: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
L_80090610:
    // 0x80090610: mtc1        $s4, $f10
    ctx->f10.u32l = ctx->r20;
    // 0x80090614: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090618: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009061C: lwc1        $f16, 0x6F9C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6F9C);
    // 0x80090620: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80090624: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80090628: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009062C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80090630: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80090634: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80090638: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009063C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80090640: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090644: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80090648: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009064C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80090650: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80090654: sh          $t2, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r10;
    // 0x80090658: lw          $t4, 0x6A20($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6A20);
    // 0x8009065C: lwc1        $f18, 0x6FA4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x80090660: multu       $s5, $t4
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80090664: sb          $t7, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r15;
    // 0x80090668: mflo        $t3
    ctx->r11 = lo;
    // 0x8009066C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80090670: nop

    // 0x80090674: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80090678: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8009067C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80090680: nop

    // 0x80090684: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80090688: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009068C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80090690: nop

    // 0x80090694: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80090698: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8009069C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800906A0: sh          $t6, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r14;
    // 0x800906A4: lw          $t8, 0x6FB4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6FB4);
    // 0x800906A8: nop

    // 0x800906AC: bne         $s2, $t8, L_800906F0
    if (ctx->r18 != ctx->r24) {
        // 0x800906B0: nop
    
            goto L_800906F0;
    }
    // 0x800906B0: nop

    // 0x800906B4: lw          $t9, 0x6FB8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6FB8);
    // 0x800906B8: nop

    // 0x800906BC: bne         $s3, $t9, L_800906F0
    if (ctx->r19 != ctx->r25) {
        // 0x800906C0: nop
    
            goto L_800906F0;
    }
    // 0x800906C0: nop

    // 0x800906C4: lbu         $t1, 0xE($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XE);
    // 0x800906C8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800906CC: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x800906D0: sb          $t2, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r10;
    // 0x800906D4: lw          $v0, 0x6978($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6978);
    // 0x800906D8: nop

    // 0x800906DC: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x800906E0: beq         $at, $zero, L_80090700
    if (ctx->r1 == 0) {
        // 0x800906E4: sll         $t4, $v0, 3
        ctx->r12 = S32(ctx->r2 << 3);
            goto L_80090700;
    }
    // 0x800906E4: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x800906E8: b           L_80090700
    // 0x800906EC: sb          $t4, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r12;
        goto L_80090700;
    // 0x800906EC: sb          $t4, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r12;
L_800906F0:
    // 0x800906F0: lbu         $t3, 0xE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XE);
    // 0x800906F4: nop

    // 0x800906F8: andi        $t5, $t3, 0xFF7F
    ctx->r13 = ctx->r11 & 0XFF7F;
    // 0x800906FC: sb          $t5, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r13;
L_80090700:
    // 0x80090700: lbu         $t6, 0xE($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XE);
    // 0x80090704: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80090708: andi        $t7, $t6, 0xFF80
    ctx->r15 = ctx->r14 & 0XFF80;
    // 0x8009070C: sb          $t7, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r15;
    // 0x80090710: lw          $t8, -0x604($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X604);
    // 0x80090714: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x80090718: bne         $t8, $zero, L_80090800
    if (ctx->r24 != 0) {
        // 0x8009071C: nop
    
            goto L_80090800;
    }
    // 0x8009071C: nop

    // 0x80090720: blez        $s3, L_80090738
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80090724: ori         $t0, $t7, 0x1
        ctx->r8 = ctx->r15 | 0X1;
            goto L_80090738;
    }
    // 0x80090724: ori         $t0, $t7, 0x1
    ctx->r8 = ctx->r15 | 0X1;
    // 0x80090728: andi        $t1, $t0, 0x7F
    ctx->r9 = ctx->r8 & 0X7F;
    // 0x8009072C: andi        $t2, $t7, 0xFF80
    ctx->r10 = ctx->r15 & 0XFF80;
    // 0x80090730: or          $t4, $t1, $t2
    ctx->r12 = ctx->r9 | ctx->r10;
    // 0x80090734: sb          $t4, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r12;
L_80090738:
    // 0x80090738: beq         $at, $zero, L_80090760
    if (ctx->r1 == 0) {
        // 0x8009073C: lw          $t9, 0x60($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X60);
            goto L_80090760;
    }
    // 0x8009073C: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80090740: lbu         $t3, 0xE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XE);
    // 0x80090744: nop

    // 0x80090748: ori         $t5, $t3, 0x2
    ctx->r13 = ctx->r11 | 0X2;
    // 0x8009074C: andi        $t6, $t5, 0x7F
    ctx->r14 = ctx->r13 & 0X7F;
    // 0x80090750: andi        $t7, $t3, 0xFF80
    ctx->r15 = ctx->r11 & 0XFF80;
    // 0x80090754: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80090758: sb          $t8, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r24;
    // 0x8009075C: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
L_80090760:
    // 0x80090760: nop

    // 0x80090764: slt         $at, $s3, $t9
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80090768: beq         $at, $zero, L_8009078C
    if (ctx->r1 == 0) {
        // 0x8009076C: nop
    
            goto L_8009078C;
    }
    // 0x8009076C: nop

    // 0x80090770: lbu         $t0, 0xE($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XE);
    // 0x80090774: nop

    // 0x80090778: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x8009077C: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x80090780: andi        $t4, $t0, 0xFF80
    ctx->r12 = ctx->r8 & 0XFF80;
    // 0x80090784: or          $t3, $t2, $t4
    ctx->r11 = ctx->r10 | ctx->r12;
    // 0x80090788: sb          $t3, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r11;
L_8009078C:
    // 0x8009078C: blez        $s2, L_800907B0
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80090790: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800907B0;
    }
    // 0x80090790: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80090794: lbu         $t5, 0xE($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XE);
    // 0x80090798: nop

    // 0x8009079C: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x800907A0: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x800907A4: andi        $t8, $t5, 0xFF80
    ctx->r24 = ctx->r13 & 0XFF80;
    // 0x800907A8: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800907AC: sb          $t9, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r25;
L_800907B0:
    // 0x800907B0: bne         $s2, $s7, L_800907D8
    if (ctx->r18 != ctx->r23) {
        // 0x800907B4: nop
    
            goto L_800907D8;
    }
    // 0x800907B4: nop

    // 0x800907B8: bne         $s3, $s7, L_800907D8
    if (ctx->r19 != ctx->r23) {
        // 0x800907BC: nop
    
            goto L_800907D8;
    }
    // 0x800907BC: nop

    // 0x800907C0: lbu         $t1, 0xE($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XE);
    // 0x800907C4: nop

    // 0x800907C8: andi        $t2, $t1, 0x7D
    ctx->r10 = ctx->r9 & 0X7D;
    // 0x800907CC: andi        $t4, $t1, 0xFF80
    ctx->r12 = ctx->r9 & 0XFF80;
    // 0x800907D0: or          $t3, $t2, $t4
    ctx->r11 = ctx->r10 | ctx->r12;
    // 0x800907D4: sb          $t3, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r11;
L_800907D8:
    // 0x800907D8: bne         $s2, $at, L_80090800
    if (ctx->r18 != ctx->r1) {
        // 0x800907DC: nop
    
            goto L_80090800;
    }
    // 0x800907DC: nop

    // 0x800907E0: bne         $s3, $fp, L_80090800
    if (ctx->r19 != ctx->r30) {
        // 0x800907E4: nop
    
            goto L_80090800;
    }
    // 0x800907E4: nop

    // 0x800907E8: lbu         $t6, 0xE($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XE);
    // 0x800907EC: nop

    // 0x800907F0: andi        $t7, $t6, 0x7B
    ctx->r15 = ctx->r14 & 0X7B;
    // 0x800907F4: andi        $t8, $t6, 0xFF80
    ctx->r24 = ctx->r14 & 0XFF80;
    // 0x800907F8: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800907FC: sb          $t9, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r25;
L_80090800:
    // 0x80090800: bne         $s2, $s7, L_80090814
    if (ctx->r18 != ctx->r23) {
        // 0x80090804: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80090814;
    }
    // 0x80090804: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80090808: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8009080C: b           L_8009082C
    // 0x80090810: sb          $t0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r8;
        goto L_8009082C;
    // 0x80090810: sb          $t0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r8;
L_80090814:
    // 0x80090814: bne         $s2, $at, L_80090828
    if (ctx->r18 != ctx->r1) {
        // 0x80090818: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_80090828;
    }
    // 0x80090818: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009081C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80090820: b           L_8009082C
    // 0x80090824: sb          $t1, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r9;
        goto L_8009082C;
    // 0x80090824: sb          $t1, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r9;
L_80090828:
    // 0x80090828: sb          $t2, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r10;
L_8009082C:
    // 0x8009082C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80090830: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80090834: bne         $s6, $at, L_800904F4
    if (ctx->r22 != ctx->r1) {
        // 0x80090838: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800904F4;
    }
    // 0x80090838: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8009083C: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80090840: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80090844: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80090848: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x8009084C: bne         $at, $zero, L_800904F0
    if (ctx->r1 != 0) {
        // 0x80090850: sw          $t3, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r11;
            goto L_800904F0;
    }
    // 0x80090850: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x80090854: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80090858: jal         0x80066AD4
    // 0x8009085C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camDisableUserView(rdram, ctx);
        goto after_5;
    // 0x8009085C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80090860: jal         0x8009C2A0
    // 0x80090864: nop

    menu_camera_centre(rdram, ctx);
        goto after_6;
    // 0x80090864: nop

    after_6:
    // 0x80090868: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8009086C: addiu       $s1, $s1, 0x693C
    ctx->r17 = ADD32(ctx->r17, 0X693C);
    // 0x80090870: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80090874: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x80090878: jal         0x8006816C
    // 0x8009087C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mtx_ortho(rdram, ctx);
        goto after_7;
    // 0x8009087C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80090880: jal         0x8007B820
    // 0x80090884: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    rendermode_reset(rdram, ctx);
        goto after_8;
    // 0x80090884: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80090888: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8009088C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80090890: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80090894: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80090898: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x8009089C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800908A0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800908A4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800908A8: sw          $t7, 0x6EE8($at)
    MEM_W(0X6EE8, ctx->r1) = ctx->r15;
    // 0x800908AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800908B0: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800908B4: sw          $t8, 0x6EEC($at)
    MEM_W(0X6EEC, ctx->r1) = ctx->r24;
    // 0x800908B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800908BC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800908C0: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800908C4: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800908C8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800908CC: sw          $zero, 0x6FB0($at)
    MEM_W(0X6FB0, ctx->r1) = 0;
    // 0x800908D0: addiu       $s2, $s2, 0xB54
    ctx->r18 = ADD32(ctx->r18, 0XB54);
    // 0x800908D4: addiu       $s3, $s3, 0x6F80
    ctx->r19 = ADD32(ctx->r19, 0X6F80);
    // 0x800908D8: addiu       $s4, $s4, 0xB74
    ctx->r20 = ADD32(ctx->r20, 0XB74);
    // 0x800908DC: addiu       $s0, $s0, 0x6EF0
    ctx->r16 = ADD32(ctx->r16, 0X6EF0);
    // 0x800908E0: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x800908E4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800908E8:
    // 0x800908E8: lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XC);
    // 0x800908EC: nop

    // 0x800908F0: beq         $v0, $zero, L_8009094C
    if (ctx->r2 == 0) {
        // 0x800908F4: nop
    
            goto L_8009094C;
    }
    // 0x800908F4: nop

    // 0x800908F8: bne         $s1, $v0, L_8009090C
    if (ctx->r17 != ctx->r2) {
        // 0x800908FC: or          $v0, $s4, $zero
        ctx->r2 = ctx->r20 | 0;
            goto L_8009090C;
    }
    // 0x800908FC: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80090900: b           L_8009090C
    // 0x80090904: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_8009090C;
    // 0x80090904: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80090908: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_8009090C:
    // 0x8009090C: lhu         $t1, 0xE($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XE);
    // 0x80090910: lbu         $t4, 0xE($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XE);
    // 0x80090914: lbu         $t9, 0xD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XD);
    // 0x80090918: lbu         $t0, 0xF($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XF);
    // 0x8009091C: lh          $a0, 0x8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8);
    // 0x80090920: lh          $a1, 0xA($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XA);
    // 0x80090924: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80090928: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x8009092C: srl         $t2, $t1, 15
    ctx->r10 = S32(U32(ctx->r9) >> 15);
    // 0x80090930: andi        $t3, $t4, 0x7F
    ctx->r11 = ctx->r12 & 0X7F;
    // 0x80090934: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80090938: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8009093C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80090940: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80090944: jal         0x8008FF0C
    // 0x80090948: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    trackmenu_render_2D(rdram, ctx);
        goto after_9;
    // 0x80090948: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_9:
L_8009094C:
    // 0x8009094C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80090950: bne         $s0, $s3, L_800908E8
    if (ctx->r16 != ctx->r19) {
        // 0x80090954: nop
    
            goto L_800908E8;
    }
    // 0x80090954: nop

    // 0x80090958: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009095C: addiu       $v0, $v0, 0x6EE4
    ctx->r2 = ADD32(ctx->r2, 0X6EE4);
    // 0x80090960: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80090964: nop

    // 0x80090968: subu        $t6, $s1, $t5
    ctx->r14 = SUB32(ctx->r17, ctx->r13);
    // 0x8009096C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80090970:
    // 0x80090970: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80090974: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80090978: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8009097C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80090980: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80090984: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80090988: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8009098C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80090990: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80090994: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80090998: jr          $ra
    // 0x8009099C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8009099C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void hud_reset_race_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB724: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB728: jr          $ra
    // 0x800AB72C: sb          $zero, 0x7294($at)
    MEM_B(0X7294, ctx->r1) = 0;
    return;
    // 0x800AB72C: sb          $zero, 0x7294($at)
    MEM_B(0X7294, ctx->r1) = 0;
;}
RECOMP_FUNC void set_frame_blackout_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F66C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8006F670: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F674: jr          $ra
    // 0x8006F678: sb          $t6, -0x26A0($at)
    MEM_B(-0X26A0, ctx->r1) = ctx->r14;
    return;
    // 0x8006F678: sb          $t6, -0x26A0($at)
    MEM_B(-0X26A0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void draw_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C49A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C49A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C49A8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C49AC: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800C49B0: lw          $s0, -0x5258($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X5258);
    // 0x800C49B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C49B8: bne         $a1, $v0, L_800C49D4
    if (ctx->r5 != ctx->r2) {
        // 0x800C49BC: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_800C49D4;
    }
    // 0x800C49BC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800C49C0: lh          $t6, 0xC($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XC);
    // 0x800C49C4: nop

    // 0x800C49C8: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800C49CC: b           L_800C49D8
    // 0x800C49D0: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
        goto L_800C49D8;
    // 0x800C49D0: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_800C49D4:
    // 0x800C49D4: sh          $a1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r5;
L_800C49D8:
    // 0x800C49D8: bne         $a2, $v0, L_800C49F4
    if (ctx->r6 != ctx->r2) {
        // 0x800C49DC: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800C49F4;
    }
    // 0x800C49DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C49E0: lh          $t8, 0xE($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XE);
    // 0x800C49E4: nop

    // 0x800C49E8: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800C49EC: b           L_800C49F8
    // 0x800C49F0: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
        goto L_800C49F8;
    // 0x800C49F0: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
L_800C49F4:
    // 0x800C49F4: sh          $a2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r6;
L_800C49F8:
    // 0x800C49F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C49FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C4A00: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800C4A04: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800C4A08: jal         0x800C4B04
    // 0x800C4A0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    render_text_string(rdram, ctx);
        goto after_0;
    // 0x800C4A0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800C4A10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C4A14: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C4A18: jr          $ra
    // 0x800C4A1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C4A1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void calculate_ghost_header_checksum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074CA4: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x80074CA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80074CAC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80074CB0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80074CB4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80074CB8: addiu       $v0, $t8, 0x8
    ctx->r2 = ADD32(ctx->r24, 0X8);
    // 0x80074CBC: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80074CC0: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80074CC4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80074CC8: bne         $at, $zero, L_80074CF8
    if (ctx->r1 != 0) {
        // 0x80074CCC: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80074CF8;
    }
    // 0x80074CCC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80074CD0:
    // 0x80074CD0: addu        $t1, $a0, $a1
    ctx->r9 = ADD32(ctx->r4, ctx->r5);
    // 0x80074CD4: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80074CD8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80074CDC: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x80074CE0: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80074CE4: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x80074CE8: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80074CEC: sll         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3 << 16);
    // 0x80074CF0: bne         $at, $zero, L_80074CD0
    if (ctx->r1 != 0) {
        // 0x80074CF4: sra         $v1, $t3, 16
        ctx->r3 = S32(SIGNED(ctx->r11) >> 16);
            goto L_80074CD0;
    }
    // 0x80074CF4: sra         $v1, $t3, 16
    ctx->r3 = S32(SIGNED(ctx->r11) >> 16);
L_80074CF8:
    // 0x80074CF8: jr          $ra
    // 0x80074CFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80074CFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void increase_emitter_opacity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4BC8: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    // 0x800B4BCC: sll         $v1, $a1, 5
    ctx->r3 = S32(ctx->r5 << 5);
    // 0x800B4BD0: addu        $t0, $t7, $v1
    ctx->r8 = ADD32(ctx->r15, ctx->r3);
    // 0x800B4BD4: lh          $t8, 0xA($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XA);
    // 0x800B4BD8: sll         $t6, $a3, 8
    ctx->r14 = S32(ctx->r7 << 8);
    // 0x800B4BDC: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800B4BE0: addu        $v0, $t9, $a2
    ctx->r2 = ADD32(ctx->r25, ctx->r6);
    // 0x800B4BE4: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B4BE8: beq         $at, $zero, L_800B4BF8
    if (ctx->r1 == 0) {
        // 0x800B4BEC: nop
    
            goto L_800B4BF8;
    }
    // 0x800B4BEC: nop

    // 0x800B4BF0: b           L_800B4BFC
    // 0x800B4BF4: sh          $t6, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r14;
        goto L_800B4BFC;
    // 0x800B4BF4: sh          $t6, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r14;
L_800B4BF8:
    // 0x800B4BF8: sh          $v0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r2;
L_800B4BFC:
    // 0x800B4BFC: lw          $t1, 0x6C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X6C);
    // 0x800B4C00: nop

    // 0x800B4C04: addu        $t0, $t1, $v1
    ctx->r8 = ADD32(ctx->r9, ctx->r3);
    // 0x800B4C08: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x800B4C0C: nop

    // 0x800B4C10: ori         $t3, $t2, 0x100
    ctx->r11 = ctx->r10 | 0X100;
    // 0x800B4C14: jr          $ra
    // 0x800B4C18: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
    return;
    // 0x800B4C18: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
;}
RECOMP_FUNC void render_title_screen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083BB4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80083BB8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80083BBC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80083BC0: addiu       $s0, $s0, 0x6E0C
    ctx->r16 = ADD32(ctx->r16, 0X6E0C);
    // 0x80083BC4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80083BC8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80083BCC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80083BD0: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80083BD4: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x80083BD8: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80083BDC: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80083BE0: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80083BE4: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80083BE8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80083BEC: beq         $t6, $zero, L_80083DBC
    if (ctx->r14 == 0) {
        // 0x80083BF0: sw          $a0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r4;
            goto L_80083DBC;
    }
    // 0x80083BF0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80083BF4: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80083BF8: addiu       $s6, $s6, 0x693C
    ctx->r22 = ADD32(ctx->r22, 0X693C);
    // 0x80083BFC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80083C00: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x80083C04: jal         0x8006816C
    // 0x80083C08: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x80083C08: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_0:
    // 0x80083C0C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083C10: lui         $at, 0x3D00
    ctx->r1 = S32(0X3D00 << 16);
    // 0x80083C14: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80083C18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80083C1C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80083C20: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x80083C24: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80083C28: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80083C2C: addiu       $s7, $s7, -0x31C
    ctx->r23 = ADD32(ctx->r23, -0X31C);
    // 0x80083C30: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80083C34: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x80083C38: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80083C3C: jal         0x80068748
    // 0x80083C40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x80083C40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80083C44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80083C48: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80083C4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80083C50: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80083C54: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80083C58: addiu       $a1, $a1, -0x2A4
    ctx->r5 = ADD32(ctx->r5, -0X2A4);
    // 0x80083C5C: bc1t        L_80083C9C
    if (c1cs) {
        // 0x80083C60: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80083C9C;
    }
    // 0x80083C60: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80083C64: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80083C68: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
    // 0x80083C6C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80083C70: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80083C74: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80083C78: addiu       $a1, $a1, -0x2A4
    ctx->r5 = ADD32(ctx->r5, -0X2A4);
    // 0x80083C7C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80083C80: lui         $a2, 0x4320
    ctx->r6 = S32(0X4320 << 16);
    // 0x80083C84: lui         $a3, 0x4250
    ctx->r7 = S32(0X4250 << 16);
    // 0x80083C88: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80083C8C: jal         0x80079150
    // 0x80083C90: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_2;
    // 0x80083C90: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80083C94: b           L_80083CC8
    // 0x80083C98: nop

        goto L_80083CC8;
    // 0x80083C98: nop

L_80083C9C:
    // 0x80083C9C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80083CA0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80083CA4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80083CA8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80083CAC: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80083CB0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80083CB4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80083CB8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80083CBC: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x80083CC0: jal         0x80078F08
    // 0x80083CC4: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    texrect_draw(rdram, ctx);
        goto after_3;
    // 0x80083CC4: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    after_3:
L_80083CC8:
    // 0x80083CC8: jal         0x8006F708
    // 0x80083CCC: nop

    is_controller_missing(rdram, ctx);
        goto after_4;
    // 0x80083CCC: nop

    after_4:
    // 0x80083CD0: bne         $v0, $zero, L_80083DF0
    if (ctx->r2 != 0) {
        // 0x80083CD4: lui         $t5, 0x8000
        ctx->r13 = S32(0X8000 << 16);
            goto L_80083DF0;
    }
    // 0x80083CD4: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x80083CD8: lw          $t5, 0x300($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X300);
    // 0x80083CDC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80083CE0: bne         $t5, $zero, L_80083CF0
    if (ctx->r13 != 0) {
        // 0x80083CE4: addiu       $s2, $zero, 0xC0
        ctx->r18 = ADD32(0, 0XC0);
            goto L_80083CF0;
    }
    // 0x80083CE4: addiu       $s2, $zero, 0xC0
    ctx->r18 = ADD32(0, 0XC0);
    // 0x80083CE8: b           L_80083CF0
    // 0x80083CEC: addiu       $s2, $zero, 0xDA
    ctx->r18 = ADD32(0, 0XDA);
        goto L_80083CF0;
    // 0x80083CEC: addiu       $s2, $zero, 0xDA
    ctx->r18 = ADD32(0, 0XDA);
L_80083CF0:
    // 0x80083CF0: jal         0x800C484C
    // 0x80083CF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_5;
    // 0x80083CF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80083CF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80083CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80083D00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80083D04: jal         0x800C492C
    // 0x80083D08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_6;
    // 0x80083D08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x80083D0C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80083D10: lw          $t6, -0x2DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2DC);
    // 0x80083D14: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80083D18: beq         $t6, $zero, L_80083DF0
    if (ctx->r14 == 0) {
        // 0x80083D1C: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80083DF0;
    }
    // 0x80083D1C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80083D20: addiu       $t8, $t8, -0x2DC
    ctx->r24 = ADD32(ctx->r24, -0X2DC);
    // 0x80083D24: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80083D28: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80083D2C: addiu       $s3, $s3, -0x624
    ctx->r19 = ADD32(ctx->r19, -0X624);
    // 0x80083D30: addiu       $s4, $s4, 0x695C
    ctx->r20 = ADD32(ctx->r20, 0X695C);
    // 0x80083D34: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80083D38: addiu       $s5, $zero, 0x1FF
    ctx->r21 = ADD32(0, 0X1FF);
L_80083D3C:
    // 0x80083D3C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80083D40: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80083D44: bne         $s1, $t9, L_80083D70
    if (ctx->r17 != ctx->r25) {
        // 0x80083D48: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80083D70;
    }
    // 0x80083D48: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80083D4C: lw          $a3, 0x0($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X0);
    // 0x80083D50: nop

    // 0x80083D54: andi        $t0, $a3, 0x1F
    ctx->r8 = ctx->r7 & 0X1F;
    // 0x80083D58: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80083D5C: slti        $at, $t1, 0x100
    ctx->r1 = SIGNED(ctx->r9) < 0X100 ? 1 : 0;
    // 0x80083D60: bne         $at, $zero, L_80083D74
    if (ctx->r1 != 0) {
        // 0x80083D64: or          $a3, $t1, $zero
        ctx->r7 = ctx->r9 | 0;
            goto L_80083D74;
    }
    // 0x80083D64: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80083D68: b           L_80083D74
    // 0x80083D6C: subu        $a3, $s5, $t1
    ctx->r7 = SUB32(ctx->r21, ctx->r9);
        goto L_80083D74;
    // 0x80083D6C: subu        $a3, $s5, $t1
    ctx->r7 = SUB32(ctx->r21, ctx->r9);
L_80083D70:
    // 0x80083D70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80083D74:
    // 0x80083D74: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x80083D78: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80083D7C: jal         0x800C48E4
    // 0x80083D80: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x80083D80: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_7:
    // 0x80083D84: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80083D88: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80083D8C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80083D90: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80083D94: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80083D98: jal         0x800C49A0
    // 0x80083D9C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_8;
    // 0x80083D9C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_8:
    // 0x80083DA0: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80083DA4: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80083DA8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80083DAC: bne         $t4, $zero, L_80083D3C
    if (ctx->r12 != 0) {
        // 0x80083DB0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80083D3C;
    }
    // 0x80083DB0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80083DB4: b           L_80083DF4
    // 0x80083DB8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80083DF4;
    // 0x80083DB8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80083DBC:
    // 0x80083DBC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083DC0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80083DC4: lw          $t5, 0x6E04($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6E04);
    // 0x80083DC8: lw          $v0, 0x6E14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E14);
    // 0x80083DCC: nop

    // 0x80083DD0: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80083DD4: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x80083DD8: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x80083DDC: nop

    // 0x80083DE0: bne         $t7, $t8, L_80083DF4
    if (ctx->r15 != ctx->r24) {
        // 0x80083DE4: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80083DF4;
    }
    // 0x80083DE4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80083DE8: jal         0x800834E8
    // 0x80083DEC: nop

    func_80083098(rdram, ctx);
        goto after_9;
    // 0x80083DEC: nop

    after_9:
L_80083DF0:
    // 0x80083DF0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80083DF4:
    // 0x80083DF4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80083DF8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80083DFC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80083E00: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80083E04: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80083E08: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80083E0C: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x80083E10: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80083E14: jr          $ra
    // 0x80083E18: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80083E18: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void lensflare_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACE08: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800ACE0C: addiu       $a1, $a1, 0x3010
    ctx->r5 = ADD32(ctx->r5, 0X3010);
    // 0x800ACE10: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x800ACE14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ACE18: sw          $zero, 0x3014($at)
    MEM_W(0X3014, ctx->r1) = 0;
    // 0x800ACE1C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800ACE20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ACE24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ACE28: lw          $v1, 0x3C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X3C);
    // 0x800ACE2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800ACE30: lbu         $v0, 0xC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XC);
    // 0x800ACE34: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800ACE38: beq         $v0, $a2, L_800ACE64
    if (ctx->r2 == ctx->r6) {
        // 0x800ACE3C: addiu       $a1, $a1, -0x7E10
        ctx->r5 = ADD32(ctx->r5, -0X7E10);
            goto L_800ACE64;
    }
    // 0x800ACE3C: addiu       $a1, $a1, -0x7E10
    ctx->r5 = ADD32(ctx->r5, -0X7E10);
    // 0x800ACE40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800ACE44: beq         $v0, $at, L_800ACE78
    if (ctx->r2 == ctx->r1) {
        // 0x800ACE48: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_800ACE78;
    }
    // 0x800ACE48: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800ACE4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800ACE50: beq         $v0, $at, L_800ACE88
    if (ctx->r2 == ctx->r1) {
        // 0x800ACE54: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800ACE88;
    }
    // 0x800ACE54: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800ACE58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACE5C: b           L_800ACE94
    // 0x800ACE60: sw          $zero, -0x7E1C($at)
    MEM_W(-0X7E1C, ctx->r1) = 0;
        goto L_800ACE94;
    // 0x800ACE60: sw          $zero, -0x7E1C($at)
    MEM_W(-0X7E1C, ctx->r1) = 0;
L_800ACE64:
    // 0x800ACE64: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800ACE68: addiu       $t7, $t7, 0x2F30
    ctx->r15 = ADD32(ctx->r15, 0X2F30);
    // 0x800ACE6C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACE70: b           L_800ACE94
    // 0x800ACE74: sw          $t7, -0x7E1C($at)
    MEM_W(-0X7E1C, ctx->r1) = ctx->r15;
        goto L_800ACE94;
    // 0x800ACE74: sw          $t7, -0x7E1C($at)
    MEM_W(-0X7E1C, ctx->r1) = ctx->r15;
L_800ACE78:
    // 0x800ACE78: addiu       $t8, $t8, 0x2F70
    ctx->r24 = ADD32(ctx->r24, 0X2F70);
    // 0x800ACE7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACE80: b           L_800ACE94
    // 0x800ACE84: sw          $t8, -0x7E1C($at)
    MEM_W(-0X7E1C, ctx->r1) = ctx->r24;
        goto L_800ACE94;
    // 0x800ACE84: sw          $t8, -0x7E1C($at)
    MEM_W(-0X7E1C, ctx->r1) = ctx->r24;
L_800ACE88:
    // 0x800ACE88: addiu       $t9, $t9, 0x2FC0
    ctx->r25 = ADD32(ctx->r25, 0X2FC0);
    // 0x800ACE8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACE90: sw          $t9, -0x7E1C($at)
    MEM_W(-0X7E1C, ctx->r1) = ctx->r25;
L_800ACE94:
    // 0x800ACE94: lbu         $v0, 0xD($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XD);
    // 0x800ACE98: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800ACE9C: beq         $v0, $a2, L_800ACEC8
    if (ctx->r2 == ctx->r6) {
        // 0x800ACEA0: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_800ACEC8;
    }
    // 0x800ACEA0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800ACEA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800ACEA8: beq         $v0, $at, L_800ACEDC
    if (ctx->r2 == ctx->r1) {
        // 0x800ACEAC: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_800ACEDC;
    }
    // 0x800ACEAC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800ACEB0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800ACEB4: beq         $v0, $at, L_800ACEEC
    if (ctx->r2 == ctx->r1) {
        // 0x800ACEB8: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_800ACEEC;
    }
    // 0x800ACEB8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800ACEBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACEC0: b           L_800ACEF8
    // 0x800ACEC4: sw          $zero, -0x7E18($at)
    MEM_W(-0X7E18, ctx->r1) = 0;
        goto L_800ACEF8;
    // 0x800ACEC4: sw          $zero, -0x7E18($at)
    MEM_W(-0X7E18, ctx->r1) = 0;
L_800ACEC8:
    // 0x800ACEC8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800ACECC: addiu       $t0, $t0, 0x2F30
    ctx->r8 = ADD32(ctx->r8, 0X2F30);
    // 0x800ACED0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACED4: b           L_800ACEF8
    // 0x800ACED8: sw          $t0, -0x7E18($at)
    MEM_W(-0X7E18, ctx->r1) = ctx->r8;
        goto L_800ACEF8;
    // 0x800ACED8: sw          $t0, -0x7E18($at)
    MEM_W(-0X7E18, ctx->r1) = ctx->r8;
L_800ACEDC:
    // 0x800ACEDC: addiu       $t1, $t1, 0x2F70
    ctx->r9 = ADD32(ctx->r9, 0X2F70);
    // 0x800ACEE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACEE4: b           L_800ACEF8
    // 0x800ACEE8: sw          $t1, -0x7E18($at)
    MEM_W(-0X7E18, ctx->r1) = ctx->r9;
        goto L_800ACEF8;
    // 0x800ACEE8: sw          $t1, -0x7E18($at)
    MEM_W(-0X7E18, ctx->r1) = ctx->r9;
L_800ACEEC:
    // 0x800ACEEC: addiu       $t2, $t2, 0x2FC0
    ctx->r10 = ADD32(ctx->r10, 0X2FC0);
    // 0x800ACEF0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACEF4: sw          $t2, -0x7E18($at)
    MEM_W(-0X7E18, ctx->r1) = ctx->r10;
L_800ACEF8:
    // 0x800ACEF8: lbu         $t3, 0xE($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XE);
    // 0x800ACEFC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800ACF00: bne         $a2, $t3, L_800ACF18
    if (ctx->r6 != ctx->r11) {
        // 0x800ACF04: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800ACF18;
    }
    // 0x800ACF04: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACF08: addiu       $t4, $t4, 0x2F10
    ctx->r12 = ADD32(ctx->r12, 0X2F10);
    // 0x800ACF0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ACF10: b           L_800ACF1C
    // 0x800ACF14: sw          $t4, -0x7E14($at)
    MEM_W(-0X7E14, ctx->r1) = ctx->r12;
        goto L_800ACF1C;
    // 0x800ACF14: sw          $t4, -0x7E14($at)
    MEM_W(-0X7E14, ctx->r1) = ctx->r12;
L_800ACF18:
    // 0x800ACF18: sw          $zero, -0x7E14($at)
    MEM_W(-0X7E14, ctx->r1) = 0;
L_800ACF1C:
    // 0x800ACF1C: lh          $t5, 0xA($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XA);
    // 0x800ACF20: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800ACF24: sh          $t5, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r13;
    // 0x800ACF28: lh          $t6, 0x8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X8);
    // 0x800ACF2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ACF30: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x800ACF34: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800ACF38: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800ACF3C: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
    // 0x800ACF40: jal         0x800706D0
    // 0x800ACF44: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    vec3f_rotate_py(rdram, ctx);
        goto after_0;
    // 0x800ACF44: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    after_0:
    // 0x800ACF48: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800ACF4C: addiu       $a1, $a1, -0x7E10
    ctx->r5 = ADD32(ctx->r5, -0X7E10);
    // 0x800ACF50: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ACF54: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ACF58: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ACF5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ACF60: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800ACF64: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800ACF68: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800ACF6C: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x800ACF70: swc1        $f16, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f16.u32l;
    // 0x800ACF74: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x800ACF78: jr          $ra
    // 0x800ACF7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800ACF7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80074B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074D8C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80074D90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074D94: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80074D98: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80074D9C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80074DA0: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80074DA4: jal         0x80075B34
    // 0x80074DA8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80074DA8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    after_0:
    // 0x80074DAC: beq         $v0, $zero, L_80074DCC
    if (ctx->r2 == 0) {
        // 0x80074DB0: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_80074DCC;
    }
    // 0x80074DB0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80074DB4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80074DB8: jal         0x80075D44
    // 0x80074DBC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80074DBC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80074DC0: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80074DC4: b           L_80075104
    // 0x80074DC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80075104;
    // 0x80074DC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80074DCC:
    // 0x80074DCC: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80074DD0: addiu       $a1, $a1, 0x7CCC
    ctx->r5 = ADD32(ctx->r5, 0X7CCC);
    // 0x80074DD4: beq         $v0, $zero, L_80074DF0
    if (ctx->r2 == 0) {
        // 0x80074DD8: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_80074DF0;
    }
    // 0x80074DD8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80074DDC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80074DE0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80074DE4: ori         $t8, $zero, 0xFFFF
    ctx->r24 = 0 | 0XFFFF;
    // 0x80074DE8: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x80074DEC: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
L_80074DF0:
    // 0x80074DF0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80074DF4: addiu       $a2, $a2, 0x7CDC
    ctx->r6 = ADD32(ctx->r6, 0X7CDC);
    // 0x80074DF8: jal         0x80076740
    // 0x80074DFC: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x80074DFC: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x80074E00: bne         $v0, $zero, L_80075088
    if (ctx->r2 != 0) {
        // 0x80074E04: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80075088;
    }
    // 0x80074E04: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80074E08: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x80074E0C: jal         0x80070EDC
    // 0x80074E10: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80074E10: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_3:
    // 0x80074E14: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80074E18: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80074E1C: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80074E20: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x80074E24: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80074E28: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80074E2C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80074E30: addiu       $t3, $t3, 0x4598
    ctx->r11 = ADD32(ctx->r11, 0X4598);
    // 0x80074E34: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80074E38: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80074E3C: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80074E40: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80074E44: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80074E48: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80074E4C: bne         $t6, $zero, L_80074E60
    if (ctx->r14 != 0) {
        // 0x80074E50: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80074E60;
    }
    // 0x80074E50: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80074E54: lw          $a0, 0x4590($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4590);
    // 0x80074E58: jal         0x800CF280
    // 0x80074E5C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_4;
    // 0x80074E5C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_4:
L_80074E60:
    // 0x80074E60: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80074E64: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80074E68: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80074E6C: jal         0x80076868
    // 0x80074E70: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    read_data_from_controller_pak(rdram, ctx);
        goto after_5;
    // 0x80074E70: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_5:
    // 0x80074E74: lh          $t0, 0x5E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X5E);
    // 0x80074E78: lh          $t1, 0x62($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X62);
    // 0x80074E7C: bne         $v0, $zero, L_80074F7C
    if (ctx->r2 != 0) {
        // 0x80074E80: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80074F7C;
    }
    // 0x80074E80: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80074E84: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80074E88: lui         $at, 0x4748
    ctx->r1 = S32(0X4748 << 16);
    // 0x80074E8C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80074E90: ori         $at, $at, 0x5353
    ctx->r1 = ctx->r1 | 0X5353;
    // 0x80074E94: bne         $t7, $at, L_80074F78
    if (ctx->r15 != ctx->r1) {
        // 0x80074E98: addiu       $a1, $a2, 0x4
        ctx->r5 = ADD32(ctx->r6, 0X4);
            goto L_80074F78;
    }
    // 0x80074E98: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80074E9C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80074EA0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80074EA4:
    // 0x80074EA4: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80074EA8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80074EAC: bne         $t0, $t8, L_80074EE4
    if (ctx->r8 != ctx->r24) {
        // 0x80074EB0: slti        $at, $v1, 0x18
        ctx->r1 = SIGNED(ctx->r3) < 0X18 ? 1 : 0;
            goto L_80074EE4;
    }
    // 0x80074EB0: slti        $at, $v1, 0x18
    ctx->r1 = SIGNED(ctx->r3) < 0X18 ? 1 : 0;
    // 0x80074EB4: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x80074EB8: nop

    // 0x80074EBC: bne         $t1, $t2, L_80074EE4
    if (ctx->r9 != ctx->r10) {
        // 0x80074EC0: nop
    
            goto L_80074EE4;
    }
    // 0x80074EC0: nop

    // 0x80074EC4: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x80074EC8: nop

    // 0x80074ECC: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80074ED0: lh          $t5, 0x6($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X6);
    // 0x80074ED4: nop

    // 0x80074ED8: subu        $t4, $t5, $t3
    ctx->r12 = SUB32(ctx->r13, ctx->r11);
    // 0x80074EDC: b           L_80074EEC
    // 0x80074EE0: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
        goto L_80074EEC;
    // 0x80074EE0: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
L_80074EE4:
    // 0x80074EE4: bne         $at, $zero, L_80074EA4
    if (ctx->r1 != 0) {
        // 0x80074EE8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80074EA4;
    }
    // 0x80074EE8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80074EEC:
    // 0x80074EEC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80074EF0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80074EF4: bne         $t9, $zero, L_80074F7C
    if (ctx->r25 != 0) {
        // 0x80074EF8: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80074F7C;
    }
    // 0x80074EF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80074EFC: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x80074F00: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80074F04: bne         $v1, $t7, L_80074F10
    if (ctx->r3 != ctx->r15) {
        // 0x80074F08: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80074F10;
    }
    // 0x80074F08: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80074F0C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074F10:
    // 0x80074F10: lbu         $t8, 0x4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4);
    // 0x80074F14: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80074F18: bne         $v1, $t8, L_80074F24
    if (ctx->r3 != ctx->r24) {
        // 0x80074F1C: addu        $v0, $a1, $t2
        ctx->r2 = ADD32(ctx->r5, ctx->r10);
            goto L_80074F24;
    }
    // 0x80074F1C: addu        $v0, $a1, $t2
    ctx->r2 = ADD32(ctx->r5, ctx->r10);
    // 0x80074F20: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074F24:
    // 0x80074F24: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80074F28: nop

    // 0x80074F2C: bne         $v1, $t3, L_80074F38
    if (ctx->r3 != ctx->r11) {
        // 0x80074F30: nop
    
            goto L_80074F38;
    }
    // 0x80074F30: nop

    // 0x80074F34: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074F38:
    // 0x80074F38: lbu         $t5, 0x4($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4);
    // 0x80074F3C: nop

    // 0x80074F40: bne         $v1, $t5, L_80074F4C
    if (ctx->r3 != ctx->r13) {
        // 0x80074F44: nop
    
            goto L_80074F4C;
    }
    // 0x80074F44: nop

    // 0x80074F48: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074F4C:
    // 0x80074F4C: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x80074F50: nop

    // 0x80074F54: bne         $v1, $t6, L_80074F60
    if (ctx->r3 != ctx->r14) {
        // 0x80074F58: nop
    
            goto L_80074F60;
    }
    // 0x80074F58: nop

    // 0x80074F5C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074F60:
    // 0x80074F60: lbu         $t4, 0xC($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XC);
    // 0x80074F64: nop

    // 0x80074F68: bne         $v1, $t4, L_80074F80
    if (ctx->r3 != ctx->r12) {
        // 0x80074F6C: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80074F80;
    }
    // 0x80074F6C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80074F70: b           L_80074F7C
    // 0x80074F74: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
        goto L_80074F7C;
    // 0x80074F74: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074F78:
    // 0x80074F78: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
L_80074F7C:
    // 0x80074F7C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_80074F80:
    // 0x80074F80: jal         0x80071380
    // 0x80074F84: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    mempool_free(rdram, ctx);
        goto after_6;
    // 0x80074F84: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_6:
    // 0x80074F88: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80074F8C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80074F90: beq         $t9, $zero, L_80075070
    if (ctx->r25 == 0) {
        // 0x80074F94: lw          $t3, 0x40($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X40);
            goto L_80075070;
    }
    // 0x80074F94: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80074F98: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80074F9C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80074FA0: beq         $t7, $zero, L_8007506C
    if (ctx->r15 == 0) {
        // 0x80074FA4: addiu       $a0, $a0, 0x100
        ctx->r4 = ADD32(ctx->r4, 0X100);
            goto L_8007506C;
    }
    // 0x80074FA4: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // 0x80074FA8: jal         0x80070EDC
    // 0x80074FAC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x80074FAC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_7:
    // 0x80074FB0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80074FB4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80074FB8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80074FBC: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80074FC0: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80074FC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80074FC8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80074FCC: jal         0x800CF53C
    // 0x80074FD0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_8;
    // 0x80074FD0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_8:
    // 0x80074FD4: bne         $v0, $zero, L_80075058
    if (ctx->r2 != 0) {
        // 0x80074FD8: addiu       $a3, $zero, 0x9
        ctx->r7 = ADD32(0, 0X9);
            goto L_80075058;
    }
    // 0x80074FD8: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x80074FDC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80074FE0: jal         0x80074CA4
    // 0x80074FE4: nop

    calculate_ghost_header_checksum(rdram, ctx);
        goto after_9;
    // 0x80074FE4: nop

    after_9:
    // 0x80074FE8: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80074FEC: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80074FF0: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80074FF4: nop

    // 0x80074FF8: bne         $v0, $t3, L_80075050
    if (ctx->r2 != ctx->r11) {
        // 0x80074FFC: nop
    
            goto L_80075050;
    }
    // 0x80074FFC: nop

    // 0x80075000: lbu         $t5, 0x2($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X2);
    // 0x80075004: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x80075008: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x8007500C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80075010: lh          $t4, 0x4($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X4);
    // 0x80075014: nop

    // 0x80075018: sh          $t4, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r12;
    // 0x8007501C: lh          $t7, 0x6($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X6);
    // 0x80075020: nop

    // 0x80075024: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80075028: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8007502C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80075030: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80075034: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80075038: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x8007503C: sll         $a2, $t8, 2
    ctx->r6 = S32(ctx->r24 << 2);
    // 0x80075040: jal         0x800CA300
    // 0x80075044: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    _bcopy(rdram, ctx);
        goto after_10;
    // 0x80075044: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_10:
    // 0x80075048: b           L_80075058
    // 0x8007504C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80075058;
    // 0x8007504C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80075050:
    // 0x80075050: b           L_80075058
    // 0x80075054: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
        goto L_80075058;
    // 0x80075054: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
L_80075058:
    // 0x80075058: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8007505C: jal         0x80071380
    // 0x80075060: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    mempool_free(rdram, ctx);
        goto after_11;
    // 0x80075060: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_11:
    // 0x80075064: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80075068: nop

L_8007506C:
    // 0x8007506C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
L_80075070:
    // 0x80075070: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80075074: beq         $t3, $zero, L_8007508C
    if (ctx->r11 == 0) {
        // 0x80075078: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_8007508C;
    }
    // 0x80075078: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8007507C: bne         $t5, $zero, L_8007508C
    if (ctx->r13 != 0) {
        // 0x80075080: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_8007508C;
    }
    // 0x80075080: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80075084: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80075088:
    // 0x80075088: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
L_8007508C:
    // 0x8007508C: jal         0x80075D44
    // 0x80075090: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    start_reading_controller_data(rdram, ctx);
        goto after_12;
    // 0x80075090: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_12:
    // 0x80075094: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80075098: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007509C: bne         $a3, $at, L_800750FC
    if (ctx->r7 != ctx->r1) {
        // 0x800750A0: addiu       $a1, $sp, 0x38
        ctx->r5 = ADD32(ctx->r29, 0X38);
            goto L_800750FC;
    }
    // 0x800750A0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800750A4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800750A8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800750AC: jal         0x800763EC
    // 0x800750B0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    get_free_space(rdram, ctx);
        goto after_13;
    // 0x800750B0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_13:
    // 0x800750B4: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800750B8: bne         $v0, $zero, L_800750F4
    if (ctx->r2 != 0) {
        // 0x800750BC: nop
    
            goto L_800750F4;
    }
    // 0x800750BC: nop

    // 0x800750C0: jal         0x80074D74
    // 0x800750C4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    get_ghost_data_file_size(rdram, ctx);
        goto after_14;
    // 0x800750C4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_14:
    // 0x800750C8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800750CC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800750D0: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800750D4: bne         $at, $zero, L_800750EC
    if (ctx->r1 != 0) {
        // 0x800750D8: nop
    
            goto L_800750EC;
    }
    // 0x800750D8: nop

    // 0x800750DC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800750E0: nop

    // 0x800750E4: bne         $t4, $zero, L_80075100
    if (ctx->r12 != 0) {
        // 0x800750E8: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_80075100;
    }
    // 0x800750E8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800750EC:
    // 0x800750EC: b           L_80075100
    // 0x800750F0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80075100;
    // 0x800750F0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800750F4:
    // 0x800750F4: b           L_80075100
    // 0x800750F8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_80075100;
    // 0x800750F8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_800750FC:
    // 0x800750FC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80075100:
    // 0x80075100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80075104:
    // 0x80075104: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80075108: jr          $ra
    // 0x8007510C: nop

    return;
    // 0x8007510C: nop

;}
RECOMP_FUNC void dump_memory_to_cpak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7980: addiu       $sp, $sp, -0x9F0
    ctx->r29 = ADD32(ctx->r29, -0X9F0);
    // 0x800B7984: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B7988: sw          $a0, 0x9F0($sp)
    MEM_W(0X9F0, ctx->r29) = ctx->r4;
    // 0x800B798C: sw          $a1, 0x9F4($sp)
    MEM_W(0X9F4, ctx->r29) = ctx->r5;
    // 0x800B7990: jal         0x8009C850
    // 0x800B7994: sw          $a2, 0x9F8($sp)
    MEM_W(0X9F8, ctx->r29) = ctx->r6;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x800B7994: sw          $a2, 0x9F8($sp)
    MEM_W(0X9F8, ctx->r29) = ctx->r6;
    after_0:
    // 0x800B7998: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800B799C: bgez        $t6, L_800B7BC8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B79A0: addiu       $a0, $sp, 0x840
        ctx->r4 = ADD32(ctx->r29, 0X840);
            goto L_800B7BC8;
    }
    // 0x800B79A0: addiu       $a0, $sp, 0x840
    ctx->r4 = ADD32(ctx->r29, 0X840);
    // 0x800B79A4: jal         0x800D0A40
    // 0x800B79A8: addiu       $a1, $zero, 0x1B0
    ctx->r5 = ADD32(0, 0X1B0);
    _bzero(rdram, ctx);
        goto after_1;
    // 0x800B79A8: addiu       $a1, $zero, 0x1B0
    ctx->r5 = ADD32(0, 0X1B0);
    after_1:
    // 0x800B79AC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B79B0: addiu       $v0, $v0, -0x5A90
    ctx->r2 = ADD32(ctx->r2, -0X5A90);
    // 0x800B79B4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B79B8: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800B79BC: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x800B79C0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800B79C4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800B79C8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800B79CC: lw          $t1, 0x9F4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B79D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B79D4: lw          $t7, 0x9F0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9F0);
    // 0x800B79D8: lw          $t4, 0x9F8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9F8);
    // 0x800B79DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B79E0: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800B79E4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800B79E8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B79EC: sra         $t2, $t1, 31
    ctx->r10 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800B79F0: sw          $t2, 0x878($sp)
    MEM_W(0X878, ctx->r29) = ctx->r10;
    // 0x800B79F4: sw          $t6, 0x880($sp)
    MEM_W(0X880, ctx->r29) = ctx->r14;
    // 0x800B79F8: sw          $t5, 0x960($sp)
    MEM_W(0X960, ctx->r29) = ctx->r13;
    // 0x800B79FC: swc1        $f6, 0x970($sp)
    MEM_W(0X970, ctx->r29) = ctx->f6.u32l;
    // 0x800B7A00: swc1        $f10, 0x974($sp)
    MEM_W(0X974, ctx->r29) = ctx->f10.u32l;
    // 0x800B7A04: swc1        $f18, 0x978($sp)
    MEM_W(0X978, ctx->r29) = ctx->f18.u32l;
    // 0x800B7A08: addiu       $a0, $sp, 0x840
    ctx->r4 = ADD32(ctx->r29, 0X840);
    // 0x800B7A0C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800B7A10: addiu       $a2, $zero, 0x1B0
    ctx->r6 = ADD32(0, 0X1B0);
    // 0x800B7A14: sw          $t1, 0x87C($sp)
    MEM_W(0X87C, ctx->r29) = ctx->r9;
    // 0x800B7A18: sw          $t7, 0x95C($sp)
    MEM_W(0X95C, ctx->r29) = ctx->r15;
    // 0x800B7A1C: jal         0x800CA300
    // 0x800B7A20: sw          $t4, 0x884($sp)
    MEM_W(0X884, ctx->r29) = ctx->r12;
    _bcopy(rdram, ctx);
        goto after_2;
    // 0x800B7A20: sw          $t4, 0x884($sp)
    MEM_W(0X884, ctx->r29) = ctx->r12;
    after_2:
    // 0x800B7A24: addiu       $a0, $sp, 0x240
    ctx->r4 = ADD32(ctx->r29, 0X240);
    // 0x800B7A28: jal         0x800D0A40
    // 0x800B7A2C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    _bzero(rdram, ctx);
        goto after_3;
    // 0x800B7A2C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_3:
    // 0x800B7A30: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800B7A34: jal         0x800245C8
    // 0x800B7A38: addiu       $a1, $sp, 0x9F4
    ctx->r5 = ADD32(ctx->r29, 0X9F4);
    func_80024594(rdram, ctx);
        goto after_4;
    // 0x800B7A38: addiu       $a1, $sp, 0x9F4
    ctx->r5 = ADD32(ctx->r29, 0X9F4);
    after_4:
    // 0x800B7A3C: lw          $t1, 0x9F4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7A40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B7A44: blez        $t1, L_800B7B98
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800B7A48: lui         $a3, 0x800F
        ctx->r7 = S32(0X800F << 16);
            goto L_800B7B98;
    }
    // 0x800B7A48: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800B7A4C: andi        $a2, $t1, 0x3
    ctx->r6 = ctx->r9 & 0X3;
    // 0x800B7A50: beq         $a2, $zero, L_800B7AB4
    if (ctx->r6 == 0) {
        // 0x800B7A54: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_800B7AB4;
    }
    // 0x800B7A54: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800B7A58: sll         $t2, $zero, 1
    ctx->r10 = S32(0 << 1);
    // 0x800B7A5C: addiu       $t3, $sp, 0x440
    ctx->r11 = ADD32(ctx->r29, 0X440);
    // 0x800B7A60: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
L_800B7A64:
    // 0x800B7A64: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800B7A68: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B7A6C: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800B7A70: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800B7A74: lh          $t5, 0x0($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X0);
    // 0x800B7A78: nop

    // 0x800B7A7C: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    // 0x800B7A80: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B7A84: lw          $t0, 0x9F4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7A88: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B7A8C: bgez        $t9, L_800B7A9C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800B7A90: sw          $t9, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r25;
            goto L_800B7A9C;
    }
    // 0x800B7A90: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800B7A94: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x800B7A98: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7A9C:
    // 0x800B7A9C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800B7AA0: bne         $v1, $a1, L_800B7A64
    if (ctx->r3 != ctx->r5) {
        // 0x800B7AA4: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_800B7A64;
    }
    // 0x800B7AA4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B7AA8: lw          $t1, 0x9F4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7AAC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800B7AB0: beq         $a1, $t1, L_800B7B98
    if (ctx->r5 == ctx->r9) {
        // 0x800B7AB4: sll         $t2, $a1, 1
        ctx->r10 = S32(ctx->r5 << 1);
            goto L_800B7B98;
    }
L_800B7AB4:
    // 0x800B7AB4: sll         $t2, $a1, 1
    ctx->r10 = S32(ctx->r5 << 1);
    // 0x800B7AB8: addiu       $t3, $sp, 0x440
    ctx->r11 = ADD32(ctx->r29, 0X440);
    // 0x800B7ABC: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
L_800B7AC0:
    // 0x800B7AC0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800B7AC4: nop

    // 0x800B7AC8: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800B7ACC: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x800B7AD0: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800B7AD4: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B7AD8: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x800B7ADC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800B7AE0: lw          $t9, 0x9F4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7AE4: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x800B7AE8: bgez        $t8, L_800B7B00
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B7AEC: sw          $t8, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r24;
            goto L_800B7B00;
    }
    // 0x800B7AEC: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800B7AF0: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x800B7AF4: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x800B7AF8: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // 0x800B7AFC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7B00:
    // 0x800B7B00: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    // 0x800B7B04: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B7B08: sh          $t1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r9;
    // 0x800B7B0C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B7B10: lw          $t4, 0x9F4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7B14: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800B7B18: bgez        $t3, L_800B7B30
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B7B1C: sw          $t3, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r11;
            goto L_800B7B30;
    }
    // 0x800B7B1C: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x800B7B20: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x800B7B24: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x800B7B28: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x800B7B2C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7B30:
    // 0x800B7B30: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800B7B34: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B7B38: sh          $t7, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r15;
    // 0x800B7B3C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800B7B40: lw          $t9, 0x9F4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7B44: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x800B7B48: bgez        $t8, L_800B7B60
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B7B4C: sw          $t8, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r24;
            goto L_800B7B60;
    }
    // 0x800B7B4C: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800B7B50: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x800B7B54: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x800B7B58: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // 0x800B7B5C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7B60:
    // 0x800B7B60: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    // 0x800B7B64: nop

    // 0x800B7B68: sh          $t1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r9;
    // 0x800B7B6C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B7B70: lw          $t4, 0x9F4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7B74: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800B7B78: bgez        $t3, L_800B7B88
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B7B7C: sw          $t3, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r11;
            goto L_800B7B88;
    }
    // 0x800B7B7C: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x800B7B80: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x800B7B84: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7B88:
    // 0x800B7B88: lw          $t6, 0x9F4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7B8C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B7B90: bne         $a1, $t6, L_800B7AC0
    if (ctx->r5 != ctx->r14) {
        // 0x800B7B94: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_800B7AC0;
    }
    // 0x800B7B94: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800B7B98:
    // 0x800B7B98: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800B7B9C: addiu       $t7, $sp, 0x40
    ctx->r15 = ADD32(ctx->r29, 0X40);
    // 0x800B7BA0: addiu       $t5, $zero, 0x800
    ctx->r13 = ADD32(0, 0X800);
    // 0x800B7BA4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800B7BA8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800B7BAC: addiu       $a2, $a2, -0x6B98
    ctx->r6 = ADD32(ctx->r6, -0X6B98);
    // 0x800B7BB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B7BB4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800B7BB8: jal         0x8007692C
    // 0x800B7BBC: addiu       $a3, $a3, -0x6B90
    ctx->r7 = ADD32(ctx->r7, -0X6B90);
    write_controller_pak_file(rdram, ctx);
        goto after_5;
    // 0x800B7BBC: addiu       $a3, $a3, -0x6B90
    ctx->r7 = ADD32(ctx->r7, -0X6B90);
    after_5:
L_800B7BC0:
    // 0x800B7BC0: b           L_800B7BC0
    pause_self(rdram);
    // 0x800B7BC4: nop

L_800B7BC8:
    // 0x800B7BC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7BCC: addiu       $sp, $sp, 0x9F0
    ctx->r29 = ADD32(ctx->r29, 0X9F0);
    // 0x800B7BD0: jr          $ra
    // 0x800B7BD4: nop

    return;
    // 0x800B7BD4: nop

;}
RECOMP_FUNC void get_multiplayer_racer_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C984: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009C988: lw          $t6, -0x5C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C8);
    // 0x8009C98C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009C990: bne         $t6, $zero, L_8009C9A0
    if (ctx->r14 != 0) {
        // 0x8009C994: nop
    
            goto L_8009C9A0;
    }
    // 0x8009C994: nop

    // 0x8009C998: jr          $ra
    // 0x8009C99C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x8009C99C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8009C9A0:
    // 0x8009C9A0: lw          $t7, 0x1568($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1568);
    // 0x8009C9A4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C9A8: beq         $t7, $zero, L_8009C9B8
    if (ctx->r15 == 0) {
        // 0x8009C9AC: nop
    
            goto L_8009C9B8;
    }
    // 0x8009C9AC: nop

    // 0x8009C9B0: jr          $ra
    // 0x8009C9B4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x8009C9B4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8009C9B8:
    // 0x8009C9B8: lw          $v0, 0x990($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X990);
    // 0x8009C9BC: nop

    // 0x8009C9C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009C9C4: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8009C9C8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8009C9CC: jr          $ra
    // 0x8009C9D0: nop

    return;
    // 0x8009C9D0: nop

;}
RECOMP_FUNC void func_8002C954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C994: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002C998: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002C99C: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8002C9A0: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8002C9A4: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8002C9A8: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8002C9AC: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8002C9B0: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8002C9B4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8002C9B8: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8002C9BC: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8002C9C0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8002C9C4: lh          $v0, 0x20($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X20);
    // 0x8002C9C8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8002C9CC: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8002C9D0: blez        $v0, L_8002CC40
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002C9D4: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8002CC40;
    }
    // 0x8002C9D4: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8002C9D8: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8002C9DC: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8002C9E0: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
L_8002C9E4:
    // 0x8002C9E4: lw          $t6, 0xC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XC);
    // 0x8002C9E8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002C9EC: addu        $a0, $t6, $fp
    ctx->r4 = ADD32(ctx->r14, ctx->r30);
    // 0x8002C9F0: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
    // 0x8002C9F4: lh          $s6, 0x10($a0)
    ctx->r22 = MEM_H(ctx->r4, 0X10);
    // 0x8002C9F8: lh          $t4, 0x2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2);
    // 0x8002C9FC: slt         $at, $v1, $s6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8002CA00: beq         $at, $zero, L_8002CC34
    if (ctx->r1 == 0) {
        // 0x8002CA04: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_8002CC34;
    }
    // 0x8002CA04: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8002CA08: sll         $s5, $v1, 4
    ctx->r21 = S32(ctx->r3 << 4);
    // 0x8002CA0C: sll         $s2, $v1, 1
    ctx->r18 = S32(ctx->r3 << 1);
L_8002CA10:
    // 0x8002CA10: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x8002CA14: addiu       $a3, $zero, -0x7D00
    ctx->r7 = ADD32(0, -0X7D00);
    // 0x8002CA18: addu        $t7, $v0, $s5
    ctx->r15 = ADD32(ctx->r2, ctx->r21);
    // 0x8002CA1C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8002CA20: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x8002CA24: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x8002CA28: beq         $t9, $zero, L_8002CA44
    if (ctx->r25 == 0) {
        // 0x8002CA2C: addiu       $t2, $zero, -0x7D00
        ctx->r10 = ADD32(0, -0X7D00);
            goto L_8002CA44;
    }
    // 0x8002CA2C: addiu       $t2, $zero, -0x7D00
    ctx->r10 = ADD32(0, -0X7D00);
    // 0x8002CA30: lw          $t6, 0x10($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X10);
    // 0x8002CA34: nop

    // 0x8002CA38: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x8002CA3C: b           L_8002CC1C
    // 0x8002CA40: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
        goto L_8002CC1C;
    // 0x8002CA40: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
L_8002CA44:
    // 0x8002CA44: sll         $t8, $s1, 4
    ctx->r24 = S32(ctx->r17 << 4);
    // 0x8002CA48: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x8002CA4C: addiu       $t3, $zero, 0x7D00
    ctx->r11 = ADD32(0, 0X7D00);
    // 0x8002CA50: addiu       $t0, $zero, 0x7D00
    ctx->r8 = ADD32(0, 0X7D00);
    // 0x8002CA54: addu        $a0, $v0, $t8
    ctx->r4 = ADD32(ctx->r2, ctx->r24);
    // 0x8002CA58: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002CA5C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8002CA60:
    // 0x8002CA60: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x8002CA64: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002CA68: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x8002CA6C: multu       $t6, $t5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002CA70: mflo        $t7
    ctx->r15 = lo;
    // 0x8002CA74: addu        $a2, $t7, $a1
    ctx->r6 = ADD32(ctx->r15, ctx->r5);
    // 0x8002CA78: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x8002CA7C: lh          $ra, 0x4($a2)
    ctx->r31 = MEM_H(ctx->r6, 0X4);
    // 0x8002CA80: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002CA84: beq         $at, $zero, L_8002CA9C
    if (ctx->r1 == 0) {
        // 0x8002CA88: slt         $at, $v0, $t0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_8002CA9C;
    }
    // 0x8002CA88: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002CA8C: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8002CA90: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8002CA94: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8002CA98: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
L_8002CA9C:
    // 0x8002CA9C: beq         $at, $zero, L_8002CAB4
    if (ctx->r1 == 0) {
        // 0x8002CAA0: slt         $at, $t2, $ra
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r31) ? 1 : 0;
            goto L_8002CAB4;
    }
    // 0x8002CAA0: slt         $at, $t2, $ra
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x8002CAA4: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x8002CAA8: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8002CAAC: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x8002CAB0: slt         $at, $t2, $ra
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r31) ? 1 : 0;
L_8002CAB4:
    // 0x8002CAB4: beq         $at, $zero, L_8002CACC
    if (ctx->r1 == 0) {
        // 0x8002CAB8: slt         $at, $ra, $t3
        ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_8002CACC;
    }
    // 0x8002CAB8: slt         $at, $ra, $t3
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002CABC: sll         $t2, $ra, 16
    ctx->r10 = S32(ctx->r31 << 16);
    // 0x8002CAC0: sra         $t6, $t2, 16
    ctx->r14 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8002CAC4: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x8002CAC8: slt         $at, $ra, $t3
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r11) ? 1 : 0;
L_8002CACC:
    // 0x8002CACC: beq         $at, $zero, L_8002CAE0
    if (ctx->r1 == 0) {
        // 0x8002CAD0: nop
    
            goto L_8002CAE0;
    }
    // 0x8002CAD0: nop

    // 0x8002CAD4: sll         $t3, $ra, 16
    ctx->r11 = S32(ctx->r31 << 16);
    // 0x8002CAD8: sra         $t7, $t3, 16
    ctx->r15 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8002CADC: or          $t3, $t7, $zero
    ctx->r11 = ctx->r15 | 0;
L_8002CAE0:
    // 0x8002CAE0: bne         $v1, $s0, L_8002CA60
    if (ctx->r3 != ctx->r16) {
        // 0x8002CAE4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8002CA60;
    }
    // 0x8002CAE4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002CAE8: lh          $ra, 0x0($s4)
    ctx->r31 = MEM_H(ctx->r20, 0X0);
    // 0x8002CAEC: lh          $t8, 0x6($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X6);
    // 0x8002CAF0: sll         $a0, $ra, 16
    ctx->r4 = S32(ctx->r31 << 16);
    // 0x8002CAF4: subu        $a2, $t8, $ra
    ctx->r6 = SUB32(ctx->r24, ctx->r31);
    // 0x8002CAF8: sra         $t9, $a2, 3
    ctx->r25 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002CAFC: addiu       $a2, $t9, 0x1
    ctx->r6 = ADD32(ctx->r25, 0X1);
    // 0x8002CB00: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8002CB04: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002CB08: addu        $v1, $a2, $ra
    ctx->r3 = ADD32(ctx->r6, ctx->r31);
    // 0x8002CB0C: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x8002CB10: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002CB14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002CB18: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002CB1C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8002CB20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002CB24:
    // 0x8002CB24: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002CB28: bne         $at, $zero, L_8002CB48
    if (ctx->r1 != 0) {
        // 0x8002CB2C: addu        $v1, $v1, $a2
        ctx->r3 = ADD32(ctx->r3, ctx->r6);
            goto L_8002CB48;
    }
    // 0x8002CB2C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002CB30: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002CB34: bne         $at, $zero, L_8002CB48
    if (ctx->r1 != 0) {
        // 0x8002CB38: nop
    
            goto L_8002CB48;
    }
    // 0x8002CB38: nop

    // 0x8002CB3C: or          $t1, $t1, $a1
    ctx->r9 = ctx->r9 | ctx->r5;
    // 0x8002CB40: sll         $t7, $t1, 16
    ctx->r15 = S32(ctx->r9 << 16);
    // 0x8002CB44: sra         $t1, $t7, 16
    ctx->r9 = S32(SIGNED(ctx->r15) >> 16);
L_8002CB48:
    // 0x8002CB48: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002CB4C: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8002CB50: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8002CB54: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002CB58: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002CB5C: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002CB60: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x8002CB64: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8002CB68: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8002CB6C: sll         $t6, $t9, 17
    ctx->r14 = S32(ctx->r25 << 17);
    // 0x8002CB70: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002CB74: bne         $at, $zero, L_8002CB24
    if (ctx->r1 != 0) {
        // 0x8002CB78: sra         $a1, $t6, 16
        ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
            goto L_8002CB24;
    }
    // 0x8002CB78: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002CB7C: lh          $a3, 0x4($s4)
    ctx->r7 = MEM_H(ctx->r20, 0X4);
    // 0x8002CB80: lh          $t6, 0xA($s4)
    ctx->r14 = MEM_H(ctx->r20, 0XA);
    // 0x8002CB84: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x8002CB88: subu        $a2, $t6, $a3
    ctx->r6 = SUB32(ctx->r14, ctx->r7);
    // 0x8002CB8C: sra         $t7, $a2, 3
    ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002CB90: addiu       $a2, $t7, 0x1
    ctx->r6 = ADD32(ctx->r15, 0X1);
    // 0x8002CB94: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8002CB98: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002CB9C: addu        $v1, $a2, $a3
    ctx->r3 = ADD32(ctx->r6, ctx->r7);
    // 0x8002CBA0: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8002CBA4: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002CBA8: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002CBAC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8002CBB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002CBB4:
    // 0x8002CBB4: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002CBB8: bne         $at, $zero, L_8002CBD8
    if (ctx->r1 != 0) {
        // 0x8002CBBC: addu        $v1, $v1, $a2
        ctx->r3 = ADD32(ctx->r3, ctx->r6);
            goto L_8002CBD8;
    }
    // 0x8002CBBC: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002CBC0: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002CBC4: bne         $at, $zero, L_8002CBD8
    if (ctx->r1 != 0) {
        // 0x8002CBC8: nop
    
            goto L_8002CBD8;
    }
    // 0x8002CBC8: nop

    // 0x8002CBCC: or          $t1, $t1, $a1
    ctx->r9 = ctx->r9 | ctx->r5;
    // 0x8002CBD0: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x8002CBD4: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
L_8002CBD8:
    // 0x8002CBD8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002CBDC: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8002CBE0: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8002CBE4: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002CBE8: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002CBEC: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002CBF0: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x8002CBF4: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8002CBF8: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8002CBFC: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x8002CC00: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002CC04: bne         $at, $zero, L_8002CBB4
    if (ctx->r1 != 0) {
        // 0x8002CC08: sra         $a1, $t8, 16
        ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
            goto L_8002CBB4;
    }
    // 0x8002CC08: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002CC0C: lw          $t8, 0x10($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X10);
    // 0x8002CC10: nop

    // 0x8002CC14: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8002CC18: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
L_8002CC1C:
    // 0x8002CC1C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002CC20: slt         $at, $s1, $s6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8002CC24: bne         $at, $zero, L_8002CA10
    if (ctx->r1 != 0) {
        // 0x8002CC28: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_8002CA10;
    }
    // 0x8002CC28: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8002CC2C: lh          $v0, 0x20($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X20);
    // 0x8002CC30: nop

L_8002CC34:
    // 0x8002CC34: slt         $at, $s7, $v0
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002CC38: bne         $at, $zero, L_8002C9E4
    if (ctx->r1 != 0) {
        // 0x8002CC3C: addiu       $fp, $fp, 0xC
        ctx->r30 = ADD32(ctx->r30, 0XC);
            goto L_8002C9E4;
    }
    // 0x8002CC3C: addiu       $fp, $fp, 0xC
    ctx->r30 = ADD32(ctx->r30, 0XC);
L_8002CC40:
    // 0x8002CC40: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002CC44: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002CC48: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8002CC4C: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8002CC50: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8002CC54: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8002CC58: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CC5C: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8002CC60: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8002CC64: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8002CC68: jr          $ra
    // 0x8002CC6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002CC6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bootscreen_init_cpak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80088C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088C68: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x80088C6C: jal         0x80070EDC
    // 0x80088C70: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80088C70: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80088C74: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80088C78: addiu       $a1, $a1, 0x7060
    ctx->r5 = ADD32(ctx->r5, 0X7060);
    // 0x80088C7C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088C80: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80088C84: addiu       $a0, $a0, 0x7064
    ctx->r4 = ADD32(ctx->r4, 0X7064);
    // 0x80088C88: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
L_80088C8C:
    // 0x80088C8C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80088C90: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80088C94: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80088C98: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80088C9C: slti        $at, $v1, 0x200
    ctx->r1 = SIGNED(ctx->r3) < 0X200 ? 1 : 0;
    // 0x80088CA0: bne         $at, $zero, L_80088C8C
    if (ctx->r1 != 0) {
        // 0x80088CA4: sw          $t7, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->r15;
            goto L_80088C8C;
    }
    // 0x80088CA4: sw          $t7, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r15;
    // 0x80088CA8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80088CAC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80088CB0: addiu       $v1, $v1, 0x7021
    ctx->r3 = ADD32(ctx->r3, 0X7021);
    // 0x80088CB4: addiu       $v0, $v0, 0x7020
    ctx->r2 = ADD32(ctx->r2, 0X7020);
L_80088CB8:
    // 0x80088CB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80088CBC: bne         $v0, $v1, L_80088CB8
    if (ctx->r2 != ctx->r3) {
        // 0x80088CC0: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_80088CB8;
    }
    // 0x80088CC0: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x80088CC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088CC8: sw          $zero, 0x71D0($at)
    MEM_W(0X71D0, ctx->r1) = 0;
    // 0x80088CCC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088CD0: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x80088CD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088CD8: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x80088CDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088CE0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80088CE4: jal         0x8009F064
    // 0x80088CE8: sw          $t8, 0x7028($at)
    MEM_W(0X7028, ctx->r1) = ctx->r24;
    get_language(rdram, ctx);
        goto after_1;
    // 0x80088CE8: sw          $t8, 0x7028($at)
    MEM_W(0X7028, ctx->r1) = ctx->r24;
    after_1:
    // 0x80088CEC: jal         0x8007FD50
    // 0x80088CF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    load_menu_text(rdram, ctx);
        goto after_2;
    // 0x80088CF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80088CF4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088CF8: addiu       $a0, $a0, 0x7028
    ctx->r4 = ADD32(ctx->r4, 0X7028);
    // 0x80088CFC: jal         0x8008838C
    // 0x80088D00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80087F14(rdram, ctx);
        goto after_3;
    // 0x80088D00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80088D04: bne         $v0, $zero, L_80088D14
    if (ctx->r2 != 0) {
        // 0x80088D08: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80088D14;
    }
    // 0x80088D08: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088D0C: b           L_80088D2C
    // 0x80088D10: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
        goto L_80088D2C;
    // 0x80088D10: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
L_80088D14:
    // 0x80088D14: jal         0x800887A4
    // 0x80088D18: nop

    check_for_controller_pak_errors(rdram, ctx);
        goto after_4;
    // 0x80088D18: nop

    after_4:
    // 0x80088D1C: bne         $v0, $zero, L_80088D2C
    if (ctx->r2 != 0) {
        // 0x80088D20: addiu       $t9, $zero, 0x14
        ctx->r25 = ADD32(0, 0X14);
            goto L_80088D2C;
    }
    // 0x80088D20: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80088D24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088D28: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
L_80088D2C:
    // 0x80088D2C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80088D30: lw          $t0, 0x7188($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7188);
    // 0x80088D34: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80088D38: bne         $t0, $zero, L_80088D54
    if (ctx->r8 != 0) {
        // 0x80088D3C: addiu       $a0, $zero, 0x3F
        ctx->r4 = ADD32(0, 0X3F);
            goto L_80088D54;
    }
    // 0x80088D3C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x80088D40: lw          $t1, 0x314($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X314);
    // 0x80088D44: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x80088D48: bne         $t1, $zero, L_80088D54
    if (ctx->r9 != 0) {
        // 0x80088D4C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80088D54;
    }
    // 0x80088D4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088D50: sw          $t2, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r10;
L_80088D54:
    // 0x80088D54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088D58: sw          $zero, -0x620($at)
    MEM_W(-0X620, ctx->r1) = 0;
    // 0x80088D5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088D60: jal         0x8009CC18
    // 0x80088D64: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    menu_asset_load(rdram, ctx);
        goto after_5;
    // 0x80088D64: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    after_5:
    // 0x80088D68: jal         0x8008E968
    // 0x80088D6C: nop

    menu_init_arrow_textures(rdram, ctx);
        goto after_6;
    // 0x80088D6C: nop

    after_6:
    // 0x80088D70: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x80088D74: lw          $t3, 0x300($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X300);
    // 0x80088D78: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80088D7C: bne         $t3, $zero, L_80088D94
    if (ctx->r11 != 0) {
        // 0x80088D80: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80088D94;
    }
    // 0x80088D80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088D84: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80088D88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088D8C: b           L_80088D98
    // 0x80088D90: sw          $t4, 0x7174($at)
    MEM_W(0X7174, ctx->r1) = ctx->r12;
        goto L_80088D98;
    // 0x80088D90: sw          $t4, 0x7174($at)
    MEM_W(0X7174, ctx->r1) = ctx->r12;
L_80088D94:
    // 0x80088D94: sw          $t5, 0x7174($at)
    MEM_W(0X7174, ctx->r1) = ctx->r13;
L_80088D98:
    // 0x80088D98: jal         0x800C46D0
    // 0x80088D9C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_7;
    // 0x80088D9C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x80088DA0: jal         0x800724D8
    // 0x80088DA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    rumble_enable(rdram, ctx);
        goto after_8;
    // 0x80088DA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x80088DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80088DB0: jr          $ra
    // 0x80088DB4: nop

    return;
    // 0x80088DB4: nop

;}
RECOMP_FUNC void cam_set_fov(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006632C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80066330: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80066334: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80066338: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006633C: bc1f        L_800663C4
    if (!c1cs) {
        // 0x80066340: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_800663C4;
    }
    // 0x80066340: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80066344: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80066348: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006634C: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80066350: addiu       $v0, $v0, 0x1290
    ctx->r2 = ADD32(ctx->r2, 0X1290);
    // 0x80066354: bc1f        L_800663C8
    if (!c1cs) {
        // 0x80066358: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800663C8;
    }
    // 0x80066358: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006635C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80066360: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80066364: c.eq.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl == ctx->f8.fl;
    // 0x80066368: addiu       $a0, $a0, 0x1460
    ctx->r4 = ADD32(ctx->r4, 0X1460);
    // 0x8006636C: bc1t        L_800663C4
    if (c1cs) {
        // 0x80066370: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800663C4;
    }
    // 0x80066370: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80066374: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80066378: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006637C: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x80066380: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80066384: lwc1        $f16, 0x7630($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7630);
    // 0x80066388: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006638C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80066390: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80066394: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x80066398: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x8006639C: addiu       $a1, $a1, 0x12EC
    ctx->r5 = ADD32(ctx->r5, 0X12EC);
    // 0x800663A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800663A4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x800663A8: jal         0x800CCE80
    // 0x800663AC: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_0;
    // 0x800663AC: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800663B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800663B4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800663B8: addiu       $a1, $a1, 0x1560
    ctx->r5 = ADD32(ctx->r5, 0X1560);
    // 0x800663BC: jal         0x8006FAB0
    // 0x800663C0: addiu       $a0, $a0, 0x1460
    ctx->r4 = ADD32(ctx->r4, 0X1460);
    mtxf_to_mtx(rdram, ctx);
        goto after_1;
    // 0x800663C0: addiu       $a0, $a0, 0x1460
    ctx->r4 = ADD32(ctx->r4, 0X1460);
    after_1:
L_800663C4:
    // 0x800663C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800663C8:
    // 0x800663C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800663CC: jr          $ra
    // 0x800663D0: nop

    return;
    // 0x800663D0: nop

;}
RECOMP_FUNC void update_carpet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D99C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004D9A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004D9A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004D9A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8004D9AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8004D9B0: lw          $t6, 0x118($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X118);
    // 0x8004D9B4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8004D9B8: beq         $t6, $zero, L_8004D9D0
    if (ctx->r14 == 0) {
        // 0x8004D9BC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8004D9D0;
    }
    // 0x8004D9BC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004D9C0: jal         0x80006AC8
    // 0x8004D9C4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    racer_sound_free(rdram, ctx);
        goto after_0;
    // 0x8004D9C4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x8004D9C8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8004D9CC: nop

L_8004D9D0:
    // 0x8004D9D0: jal         0x80023450
    // 0x8004D9D4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    is_taj_challenge(rdram, ctx);
        goto after_1;
    // 0x8004D9D4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_1:
    // 0x8004D9D8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8004D9DC: beq         $v0, $zero, L_8004DA00
    if (ctx->r2 == 0) {
        // 0x8004D9E0: addiu       $t0, $zero, 0xA
        ctx->r8 = ADD32(0, 0XA);
            goto L_8004DA00;
    }
    // 0x8004D9E0: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8004D9E4: lb          $t7, 0x1D6($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X1D6);
    // 0x8004D9E8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004D9EC: bne         $t7, $at, L_8004DA00
    if (ctx->r15 != ctx->r1) {
        // 0x8004D9F0: nop
    
            goto L_8004DA00;
    }
    // 0x8004D9F0: nop

    // 0x8004D9F4: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x8004D9F8: nop

    // 0x8004D9FC: sh          $zero, 0x14($t8)
    MEM_H(0X14, ctx->r24) = 0;
L_8004DA00:
    // 0x8004DA00: lh          $t9, 0x18($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X18);
    // 0x8004DA04: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8004DA08: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
    // 0x8004DA0C: sb          $t0, 0x1D6($a3)
    MEM_B(0X1D6, ctx->r7) = ctx->r8;
    // 0x8004DA10: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8004DA14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004DA18: jal         0x800497D4
    // 0x8004DA1C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_80049794(rdram, ctx);
        goto after_2;
    // 0x8004DA1C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_2:
    // 0x8004DA20: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8004DA24: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004DA28: lb          $t1, 0x1D7($a3)
    ctx->r9 = MEM_B(ctx->r7, 0X1D7);
    // 0x8004DA2C: nop

    // 0x8004DA30: sb          $t1, 0x1D6($a3)
    MEM_B(0X1D6, ctx->r7) = ctx->r9;
    // 0x8004DA34: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x8004DA38: lb          $t2, 0x1D6($a3)
    ctx->r10 = MEM_B(ctx->r7, 0X1D6);
    // 0x8004DA3C: nop

    // 0x8004DA40: bne         $t2, $at, L_8004DAE4
    if (ctx->r10 != ctx->r1) {
        // 0x8004DA44: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004DAE4;
    }
    // 0x8004DA44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004DA48: lw          $v0, 0x154($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X154);
    // 0x8004DA4C: nop

    // 0x8004DA50: beq         $v0, $zero, L_8004DAE4
    if (ctx->r2 == 0) {
        // 0x8004DA54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004DAE4;
    }
    // 0x8004DA54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004DA58: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004DA5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004DA60: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8004DA64: lw          $t3, 0x154($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X154);
    // 0x8004DA68: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8004DA6C: nop

    // 0x8004DA70: swc1        $f6, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f6.u32l;
    // 0x8004DA74: lw          $t4, 0x154($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X154);
    // 0x8004DA78: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8004DA7C: nop

    // 0x8004DA80: swc1        $f8, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f8.u32l;
    // 0x8004DA84: lw          $t6, 0x154($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X154);
    // 0x8004DA88: lh          $t5, 0x2E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2E);
    // 0x8004DA8C: nop

    // 0x8004DA90: sh          $t5, 0x2E($t6)
    MEM_H(0X2E, ctx->r14) = ctx->r13;
    // 0x8004DA94: lw          $t8, 0x154($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X154);
    // 0x8004DA98: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8004DA9C: nop

    // 0x8004DAA0: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x8004DAA4: lw          $t0, 0x154($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X154);
    // 0x8004DAA8: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x8004DAAC: nop

    // 0x8004DAB0: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x8004DAB4: lw          $t2, 0x154($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X154);
    // 0x8004DAB8: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
    // 0x8004DABC: nop

    // 0x8004DAC0: sh          $t1, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r9;
    // 0x8004DAC4: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x8004DAC8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8004DACC: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x8004DAD0: nop

    // 0x8004DAD4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8004DAD8: jal         0x80061E4C
    // 0x8004DADC: sh          $t5, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r13;
    func_80061C0C(rdram, ctx);
        goto after_3;
    // 0x8004DADC: sh          $t5, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r13;
    after_3:
    // 0x8004DAE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004DAE4:
    // 0x8004DAE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004DAE8: jr          $ra
    // 0x8004DAEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004DAEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
