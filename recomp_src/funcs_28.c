#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void _alFxEnabled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B7C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80064B80: lbu         $v0, -0x2BE0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2BE0);
    // 0x80064B84: jr          $ra
    // 0x80064B88: nop

    return;
    // 0x80064B88: nop

;}
RECOMP_FUNC void alHeapDBAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7D50: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800C7D54: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800C7D58: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C7D5C: multu       $a3, $t6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C7D60: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800C7D64: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C7D68: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x800C7D6C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800C7D70: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800C7D74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C7D78: mflo        $v0
    ctx->r2 = lo;
    // 0x800C7D7C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x800C7D80: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x800C7D84: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x800C7D88: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x800C7D8C: bne         $at, $zero, L_800C7D9C
    if (ctx->r1 != 0) {
        // 0x800C7D90: addu        $t2, $a0, $t7
        ctx->r10 = ADD32(ctx->r4, ctx->r15);
            goto L_800C7D9C;
    }
    // 0x800C7D90: addu        $t2, $a0, $t7
    ctx->r10 = ADD32(ctx->r4, ctx->r15);
    // 0x800C7D94: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C7D98: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
L_800C7D9C:
    // 0x800C7D9C: jr          $ra
    // 0x800C7DA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C7DA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void level_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BFC8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006BFCC: lw          $v0, 0x16E4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16E4);
    // 0x8006BFD0: jr          $ra
    // 0x8006BFD4: nop

    return;
    // 0x8006BFD4: nop

;}
RECOMP_FUNC void sprite_opaque(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C36C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007C370: sw          $a0, -0x12BC($at)
    MEM_W(-0X12BC, ctx->r1) = ctx->r4;
    // 0x8007C374: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C378: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007C37C: jr          $ra
    // 0x8007C380: sh          $t6, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r14;
    return;
    // 0x8007C380: sh          $t6, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void snow_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACB04: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800ACB08: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ACB0C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800ACB10: addiu       $s1, $s1, 0x2E68
    ctx->r17 = ADD32(ctx->r17, 0X2E68);
    // 0x800ACB14: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x800ACB18: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800ACB1C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800ACB20: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800ACB24: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800ACB28: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800ACB2C: beq         $t6, $zero, L_800ACD8C
    if (ctx->r14 == 0) {
        // 0x800ACB30: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800ACD8C;
    }
    // 0x800ACB30: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800ACB34: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800ACB38: addiu       $s3, $s3, 0x2E98
    ctx->r19 = ADD32(ctx->r19, 0X2E98);
    // 0x800ACB3C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800ACB40: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800ACB44: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800ACB48: addiu       $s5, $s5, -0x7E3C
    ctx->r21 = ADD32(ctx->r21, -0X7E3C);
    // 0x800ACB4C: addiu       $s4, $s4, -0x7E40
    ctx->r20 = ADD32(ctx->r20, -0X7E40);
    // 0x800ACB50: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800ACB54: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800ACB58: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x800ACB5C: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800ACB60: bne         $at, $zero, L_800ACD8C
    if (ctx->r1 != 0) {
        // 0x800ACB64: sw          $t8, 0x0($s5)
        MEM_W(0X0, ctx->r21) = ctx->r24;
            goto L_800ACD8C;
    }
    // 0x800ACB64: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x800ACB68: jal         0x80069FF0
    // 0x800ACB6C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    get_projection_matrix_s16(rdram, ctx);
        goto after_0;
    // 0x800ACB6C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x800ACB70: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800ACB74: addiu       $s0, $s0, -0x7E34
    ctx->r16 = ADD32(ctx->r16, -0X7E34);
    // 0x800ACB78: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ACB7C: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800ACB80: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800ACB84: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800ACB88: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x800ACB8C: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x800ACB90: addu        $t8, $v0, $t3
    ctx->r24 = ADD32(ctx->r2, ctx->r11);
    // 0x800ACB94: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800ACB98: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800ACB9C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ACBA0: lui         $t6, 0xBC00
    ctx->r14 = S32(0XBC00 << 16);
    // 0x800ACBA4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800ACBA8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800ACBAC: ori         $t6, $t6, 0xA
    ctx->r14 = ctx->r14 | 0XA;
    // 0x800ACBB0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800ACBB4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800ACBB8: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x800ACBBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ACBC0: jal         0x8007B918
    // 0x800ACBC4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    material_set_no_tex_offset(rdram, ctx);
        goto after_1;
    // 0x800ACBC4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x800ACBC8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800ACBCC: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800ACBD0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800ACBD4: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800ACBD8: beq         $at, $zero, L_800ACCBC
    if (ctx->r1 == 0) {
        // 0x800ACBDC: lui         $t3, 0x8000
        ctx->r11 = S32(0X8000 << 16);
            goto L_800ACCBC;
    }
    // 0x800ACBDC: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800ACBE0: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800ACBE4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800ACBE8: addiu       $t5, $t5, 0x2E94
    ctx->r13 = ADD32(ctx->r13, 0X2E94);
    // 0x800ACBEC: addiu       $s2, $s2, 0x2E9C
    ctx->r18 = ADD32(ctx->r18, 0X2E9C);
    // 0x800ACBF0: lui         $s1, 0x500
    ctx->r17 = S32(0X500 << 16);
    // 0x800ACBF4: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x800ACBF8: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
L_800ACBFC:
    // 0x800ACBFC: multu       $t0, $t4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ACC00: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x800ACC04: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ACC08: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800ACC0C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800ACC10: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800ACC14: mflo        $t7
    ctx->r15 = lo;
    // 0x800ACC18: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x800ACC1C: addu        $a3, $t2, $t3
    ctx->r7 = ADD32(ctx->r10, ctx->r11);
    // 0x800ACC20: andi        $t8, $a3, 0x6
    ctx->r24 = ctx->r7 & 0X6;
    // 0x800ACC24: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800ACC28: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800ACC2C: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x800ACC30: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800ACC34: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800ACC38: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800ACC3C: or          $t8, $t7, $ra
    ctx->r24 = ctx->r15 | ctx->r31;
    // 0x800ACC40: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800ACC44: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800ACC48: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800ACC4C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800ACC50: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800ACC54: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x800ACC58: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    // 0x800ACC5C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ACC60: addiu       $t8, $a2, -0x1
    ctx->r24 = ADD32(ctx->r6, -0X1);
    // 0x800ACC64: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x800ACC68: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800ACC6C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800ACC70: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800ACC74: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x800ACC78: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800ACC7C: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x800ACC80: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800ACC84: or          $t6, $t8, $s1
    ctx->r14 = ctx->r24 | ctx->r17;
    // 0x800ACC88: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800ACC8C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800ACC90: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800ACC94: nop

    // 0x800ACC98: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x800ACC9C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800ACCA0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800ACCA4: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800ACCA8: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800ACCAC: addu        $t9, $t0, $v0
    ctx->r25 = ADD32(ctx->r8, ctx->r2);
    // 0x800ACCB0: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800ACCB4: bne         $at, $zero, L_800ACBFC
    if (ctx->r1 != 0) {
        // 0x800ACCB8: nop
    
            goto L_800ACBFC;
    }
    // 0x800ACCB8: nop

L_800ACCBC:
    // 0x800ACCBC: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x800ACCC0: multu       $t0, $t4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ACCC4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800ACCC8: addiu       $t5, $t5, 0x2E94
    ctx->r13 = ADD32(ctx->r13, 0X2E94);
    // 0x800ACCCC: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800ACCD0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ACCD4: subu        $v0, $t1, $t0
    ctx->r2 = SUB32(ctx->r9, ctx->r8);
    // 0x800ACCD8: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800ACCDC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800ACCE0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800ACCE4: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x800ACCE8: lui         $s1, 0x500
    ctx->r17 = S32(0X500 << 16);
    // 0x800ACCEC: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800ACCF0: mflo        $t8
    ctx->r24 = lo;
    // 0x800ACCF4: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x800ACCF8: addu        $a3, $t2, $t3
    ctx->r7 = ADD32(ctx->r10, ctx->r11);
    // 0x800ACCFC: andi        $t7, $a3, 0x6
    ctx->r15 = ctx->r7 & 0X6;
    // 0x800ACD00: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x800ACD04: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800ACD08: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x800ACD0C: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800ACD10: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800ACD14: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x800ACD18: or          $t7, $t8, $ra
    ctx->r15 = ctx->r24 | ctx->r31;
    // 0x800ACD1C: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800ACD20: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800ACD24: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x800ACD28: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800ACD2C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800ACD30: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x800ACD34: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800ACD38: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ACD3C: subu        $a2, $t7, $t0
    ctx->r6 = SUB32(ctx->r15, ctx->r8);
    // 0x800ACD40: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800ACD44: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800ACD48: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800ACD4C: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x800ACD50: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x800ACD54: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800ACD58: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800ACD5C: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x800ACD60: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800ACD64: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x800ACD68: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800ACD6C: or          $t6, $t8, $s1
    ctx->r14 = ctx->r24 | ctx->r17;
    // 0x800ACD70: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800ACD74: addiu       $s2, $s2, 0x2E9C
    ctx->r18 = ADD32(ctx->r18, 0X2E9C);
    // 0x800ACD78: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800ACD7C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800ACD80: nop

    // 0x800ACD84: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x800ACD88: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_800ACD8C:
    // 0x800ACD8C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800ACD90: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800ACD94: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800ACD98: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACD9C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800ACDA0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800ACDA4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800ACDA8: jr          $ra
    // 0x800ACDAC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800ACDAC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void dialogue_close_stub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EEEC: jr          $ra
    // 0x8009EEF0: nop

    return;
    // 0x8009EEF0: nop

;}
RECOMP_FUNC void is_reset_pressed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED00: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006ED04: lw          $v1, 0x3AE0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3AE0);
    // 0x8006ED08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006ED0C: bne         $v1, $zero, L_8006ED44
    if (ctx->r3 != 0) {
        // 0x8006ED10: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006ED44;
    }
    // 0x8006ED10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006ED14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006ED18: addiu       $a0, $a0, 0x3AC8
    ctx->r4 = ADD32(ctx->r4, 0X3AC8);
    // 0x8006ED1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006ED20: jal         0x800C9110
    // 0x8006ED24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8006ED24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8006ED28: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8006ED2C: sltu        $t6, $zero, $t6
    ctx->r14 = 0 < ctx->r14 ? 1 : 0;
    // 0x8006ED30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006ED34: sw          $t6, 0x3AE0($at)
    MEM_W(0X3AE0, ctx->r1) = ctx->r14;
    // 0x8006ED38: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006ED3C: lw          $v1, 0x3AE0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3AE0);
    // 0x8006ED40: nop

L_8006ED44:
    // 0x8006ED44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006ED48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006ED4C: jr          $ra
    // 0x8006ED50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8006ED50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void update_bluey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D270: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8005D274: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8005D278: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005D27C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005D280: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8005D284: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005D288: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005D28C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005D290: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005D294: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8005D298: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8005D29C: jal         0x8005CC18
    // 0x8005D2A0: addiu       $a0, $a0, -0x2C90
    ctx->r4 = ADD32(ctx->r4, -0X2C90);
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005D2A0: addiu       $a0, $a0, -0x2C90
    ctx->r4 = ADD32(ctx->r4, -0X2C90);
    after_0:
    // 0x8005D2A4: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x8005D2A8: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x8005D2AC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005D2B0: addiu       $v1, $zero, -0x11
    ctx->r3 = ADD32(0, -0X11);
    // 0x8005D2B4: and         $t7, $t6, $v1
    ctx->r15 = ctx->r14 & ctx->r3;
    // 0x8005D2B8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005D2BC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8005D2C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D2C4: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x8005D2C8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8005D2CC: lb          $t2, 0x3B($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D2D0: nop

    // 0x8005D2D4: sh          $t2, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r10;
    // 0x8005D2D8: lh          $t3, 0x18($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X18);
    // 0x8005D2DC: nop

    // 0x8005D2E0: sh          $t3, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r11;
    // 0x8005D2E4: lh          $t4, 0x16A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X16A);
    // 0x8005D2E8: nop

    // 0x8005D2EC: sh          $t4, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r12;
    // 0x8005D2F0: lb          $t5, 0x1D8($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005D2F4: nop

    // 0x8005D2F8: bne         $t5, $at, L_8005D32C
    if (ctx->r13 != ctx->r1) {
        // 0x8005D2FC: lw          $t1, 0x78($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X78);
            goto L_8005D32C;
    }
    // 0x8005D2FC: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8005D300: jal         0x8002359C
    // 0x8005D304: nop

    func_80023568(rdram, ctx);
        goto after_1;
    // 0x8005D304: nop

    after_1:
    // 0x8005D308: beq         $v0, $zero, L_8005D32C
    if (ctx->r2 == 0) {
        // 0x8005D30C: lw          $t1, 0x78($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X78);
            goto L_8005D32C;
    }
    // 0x8005D30C: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8005D310: jal         0x80021434
    // 0x8005D314: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    func_80021400(rdram, ctx);
        goto after_2;
    // 0x8005D314: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    after_2:
    // 0x8005D318: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005D31C: nop

    // 0x8005D320: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005D324: sb          $t7, 0x1D8($s0)
    MEM_B(0X1D8, ctx->r16) = ctx->r15;
    // 0x8005D328: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
L_8005D32C:
    // 0x8005D32C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8005D330: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8005D334: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x8005D338: bne         $v1, $a0, L_8005D344
    if (ctx->r3 != ctx->r4) {
        // 0x8005D33C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005D344;
    }
    // 0x8005D33C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005D340: sb          $zero, -0x24B0($at)
    MEM_B(-0X24B0, ctx->r1) = 0;
L_8005D344:
    // 0x8005D344: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8005D348: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005D34C: bne         $t0, $t8, L_8005D3CC
    if (ctx->r8 != ctx->r24) {
        // 0x8005D350: nop
    
            goto L_8005D3CC;
    }
    // 0x8005D350: nop

    // 0x8005D354: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8005D358: nop

    // 0x8005D35C: beq         $a0, $v0, L_8005D3CC
    if (ctx->r4 == ctx->r2) {
        // 0x8005D360: addiu       $t9, $v0, -0xF
        ctx->r25 = ADD32(ctx->r2, -0XF);
            goto L_8005D3CC;
    }
    // 0x8005D360: addiu       $t9, $v0, -0xF
    ctx->r25 = ADD32(ctx->r2, -0XF);
    // 0x8005D364: bgez        $t9, L_8005D3C4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005D368: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_8005D3C4;
    }
    // 0x8005D368: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005D36C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8005D370: lb          $t3, -0x24AF($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X24AF);
    // 0x8005D374: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005D378: bne         $t3, $zero, L_8005D3A4
    if (ctx->r11 != 0) {
        // 0x8005D37C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8005D3A4;
    }
    // 0x8005D37C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005D380: jal         0x8005CCA4
    // 0x8005D384: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    play_random_boss_sound(rdram, ctx);
        goto after_3;
    // 0x8005D384: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_3:
    // 0x8005D388: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x8005D38C: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8005D390: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8005D394: sb          $t4, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r12;
    // 0x8005D398: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x8005D39C: nop

    // 0x8005D3A0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8005D3A4:
    // 0x8005D3A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005D3A8: sb          $t5, -0x24AF($at)
    MEM_B(-0X24AF, ctx->r1) = ctx->r13;
    // 0x8005D3AC: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8005D3B0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8005D3B4: nop

    // 0x8005D3B8: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x8005D3BC: b           L_8005D3CC
    // 0x8005D3C0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
        goto L_8005D3CC;
    // 0x8005D3C0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_8005D3C4:
    // 0x8005D3C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005D3C8: sb          $zero, -0x24AF($at)
    MEM_B(-0X24AF, ctx->r1) = 0;
L_8005D3CC:
    // 0x8005D3CC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8005D3D0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8005D3D4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005D3D8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005D3DC: jal         0x8004F834
    // 0x8005D3E0: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    func_8004F7F4(rdram, ctx);
        goto after_4;
    // 0x8005D3E0: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_4:
    // 0x8005D3E4: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x8005D3E8: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8005D3EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005D3F0: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x8005D3F4: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x8005D3F8: lh          $t8, 0x5A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X5A);
    // 0x8005D3FC: nop

    // 0x8005D400: sh          $t8, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r24;
    // 0x8005D404: lh          $t9, 0x5E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5E);
    // 0x8005D408: nop

    // 0x8005D40C: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005D410: lh          $t2, 0x5C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5C);
    // 0x8005D414: nop

    // 0x8005D418: sh          $t2, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r10;
    // 0x8005D41C: lb          $t3, 0x187($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X187);
    // 0x8005D420: nop

    // 0x8005D424: beq         $t3, $zero, L_8005D4B4
    if (ctx->r11 == 0) {
        // 0x8005D428: nop
    
            goto L_8005D4B4;
    }
    // 0x8005D428: nop

    // 0x8005D42C: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D430: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005D434: beq         $v1, $at, L_8005D4B4
    if (ctx->r3 == ctx->r1) {
        // 0x8005D438: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8005D4B4;
    }
    // 0x8005D438: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005D43C: sb          $v1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r3;
    // 0x8005D440: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
    // 0x8005D444: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005D448: jal         0x8005CCA4
    // 0x8005D44C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    play_random_boss_sound(rdram, ctx);
        goto after_5;
    // 0x8005D44C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8005D450: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005D454: jal         0x80001D04
    // 0x8005D458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8005D458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8005D45C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005D460: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005D464: jal         0x8006A168
    // 0x8005D468: nop

    set_camera_shake(rdram, ctx);
        goto after_7;
    // 0x8005D468: nop

    after_7:
    // 0x8005D46C: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8005D470: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D474: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005D478: lwc1        $f9, 0x6FC0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6FC0);
    // 0x8005D47C: lwc1        $f8, 0x6FC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FC4);
    // 0x8005D480: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005D484: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8005D488: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x8005D48C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005D490: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005D494: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005D498: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x8005D49C: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005D4A0: nop

    // 0x8005D4A4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005D4A8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005D4AC: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005D4B0: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
L_8005D4B4:
    // 0x8005D4B4: lw          $t5, 0x148($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X148);
    // 0x8005D4B8: nop

    // 0x8005D4BC: beq         $t5, $zero, L_8005D4F8
    if (ctx->r13 == 0) {
        // 0x8005D4C0: nop
    
            goto L_8005D4F8;
    }
    // 0x8005D4C0: nop

    // 0x8005D4C4: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005D4C8: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005D4CC: mul.s       $f20, $f0, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005D4D0: nop

    // 0x8005D4D4: mul.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005D4D8: nop

    // 0x8005D4DC: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005D4E0: nop

    // 0x8005D4E4: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005D4E8: jal         0x800CA030
    // 0x8005D4EC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005D4EC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_8:
    // 0x8005D4F0: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8005D4F4: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_8005D4F8:
    // 0x8005D4F8: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8005D4FC: lbu         $a1, 0x1C8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C8);
    // 0x8005D500: jal         0x8001BA50
    // 0x8005D504: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_9;
    // 0x8005D504: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_9:
    // 0x8005D508: lb          $t6, 0x1CA($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005D50C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8005D510: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8005D514: lb          $t8, 0x36($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X36);
    // 0x8005D518: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005D51C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D520: bne         $t8, $at, L_8005D52C
    if (ctx->r24 != ctx->r1) {
        // 0x8005D524: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_8005D52C;
    }
    // 0x8005D524: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005D528: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8005D52C:
    // 0x8005D52C: lb          $t9, 0x3B($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D530: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005D534: beq         $t9, $at, L_8005D6C4
    if (ctx->r25 == ctx->r1) {
        // 0x8005D538: nop
    
            goto L_8005D6C4;
    }
    // 0x8005D538: nop

    // 0x8005D53C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005D540: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005D544: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005D548: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005D54C: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8005D550: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    // 0x8005D554: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D558: bc1f        L_8005D634
    if (!c1cs) {
        // 0x8005D55C: nop
    
            goto L_8005D634;
    }
    // 0x8005D55C: nop

    // 0x8005D560: beq         $v1, $zero, L_8005D5F4
    if (ctx->r3 == 0) {
        // 0x8005D564: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8005D5F4;
    }
    // 0x8005D564: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8005D568: lbu         $t2, 0x1CD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005D56C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005D570: beq         $t2, $at, L_8005D584
    if (ctx->r10 == ctx->r1) {
        // 0x8005D574: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_8005D584;
    }
    // 0x8005D574: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8005D578: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005D57C: nop

    // 0x8005D580: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005D584:
    // 0x8005D584: sb          $t3, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r11;
    // 0x8005D588: lb          $v0, 0x1E1($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E1);
    // 0x8005D58C: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x8005D590: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x8005D594: subu        $v0, $t5, $t4
    ctx->r2 = SUB32(ctx->r13, ctx->r12);
    // 0x8005D598: bgez        $v0, L_8005D5A8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005D59C: slti        $at, $v0, 0x4A
        ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
            goto L_8005D5A8;
    }
    // 0x8005D59C: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
    // 0x8005D5A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005D5A4: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
L_8005D5A8:
    // 0x8005D5A8: bne         $at, $zero, L_8005D5B4
    if (ctx->r1 != 0) {
        // 0x8005D5AC: nop
    
            goto L_8005D5B4;
    }
    // 0x8005D5AC: nop

    // 0x8005D5B0: addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
L_8005D5B4:
    // 0x8005D5B4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8005D5B8: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D5BC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005D5C0: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8005D5C4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005D5C8: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8005D5CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005D5D0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8005D5D4: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8005D5D8: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8005D5DC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8005D5E0: sb          $t6, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r14;
    // 0x8005D5E4: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8005D5E8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005D5EC: b           L_8005D6E0
    // 0x8005D5F0: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005D6E0;
    // 0x8005D5F0: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005D5F4:
    // 0x8005D5F4: sb          $zero, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = 0;
    // 0x8005D5F8: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
    // 0x8005D5FC: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005D600: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005D604: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8005D608: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8005D60C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005D610: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005D614: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D618: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8005D61C: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8005D620: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8005D624: sub.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d - ctx->f4.d;
    // 0x8005D628: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005D62C: b           L_8005D6E0
    // 0x8005D630: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005D6E0;
    // 0x8005D630: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005D634:
    // 0x8005D634: lwc1        $f9, 0x6FC8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6FC8);
    // 0x8005D638: lwc1        $f8, 0x6FCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FCC);
    // 0x8005D63C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D640: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8005D644: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005D648: bc1t        L_8005D66C
    if (c1cs) {
        // 0x8005D64C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8005D66C;
    }
    // 0x8005D64C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005D650: lwc1        $f7, 0x6FD0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6FD0);
    // 0x8005D654: lwc1        $f6, 0x6FD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6FD4);
    // 0x8005D658: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8005D65C: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x8005D660: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8005D664: bc1f        L_8005D69C
    if (!c1cs) {
        // 0x8005D668: nop
    
            goto L_8005D69C;
    }
    // 0x8005D668: nop

L_8005D66C:
    // 0x8005D66C: sb          $t7, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r15;
    // 0x8005D670: sb          $t8, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r24;
    // 0x8005D674: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005D678: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005D67C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005D680: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8005D684: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005D688: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D68C: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8005D690: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005D694: b           L_8005D6E0
    // 0x8005D698: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_8005D6E0;
    // 0x8005D698: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_8005D69C:
    // 0x8005D69C: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
    // 0x8005D6A0: sb          $t2, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r10;
    // 0x8005D6A4: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D6A8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005D6AC: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8005D6B0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005D6B4: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8005D6B8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005D6BC: b           L_8005D6E0
    // 0x8005D6C0: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005D6E0;
    // 0x8005D6C0: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005D6C4:
    // 0x8005D6C4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D6C8: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005D6CC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8005D6D0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8005D6D4: add.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f8.d + ctx->f10.d;
    // 0x8005D6D8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005D6DC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005D6E0:
    // 0x8005D6E0: lw          $t3, 0x68($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X68);
    // 0x8005D6E4: lb          $t5, 0x3B($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D6E8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8005D6EC: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8005D6F0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005D6F4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D6F8: lw          $t4, 0x44($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X44);
    // 0x8005D6FC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005D700: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8005D704: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8005D708: nop

    // 0x8005D70C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8005D710: addiu       $t2, $t9, -0x11
    ctx->r10 = ADD32(ctx->r25, -0X11);
    // 0x8005D714: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8005D718: bc1f        L_8005D744
    if (!c1cs) {
        // 0x8005D71C: cvt.s.w     $f20, $f6
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8005D744;
    }
    // 0x8005D71C: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
L_8005D720:
    // 0x8005D720: add.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8005D724: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8005D728: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005D72C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D730: nop

    // 0x8005D734: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005D738: nop

    // 0x8005D73C: bc1t        L_8005D720
    if (c1cs) {
        // 0x8005D740: nop
    
            goto L_8005D720;
    }
    // 0x8005D740: nop

L_8005D744:
    // 0x8005D744: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005D748: nop

    // 0x8005D74C: bc1f        L_8005D778
    if (!c1cs) {
        // 0x8005D750: nop
    
            goto L_8005D778;
    }
    // 0x8005D750: nop

L_8005D754:
    // 0x8005D754: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8005D758: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8005D75C: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005D760: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D764: nop

    // 0x8005D768: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005D76C: nop

    // 0x8005D770: bc1t        L_8005D754
    if (c1cs) {
        // 0x8005D774: nop
    
            goto L_8005D754;
    }
    // 0x8005D774: nop

L_8005D778:
    // 0x8005D778: lh          $t3, 0x10($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X10);
    // 0x8005D77C: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D780: bne         $t0, $t3, L_8005D7A8
    if (ctx->r8 != ctx->r11) {
        // 0x8005D784: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8005D7A8;
    }
    // 0x8005D784: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005D788: bne         $v1, $at, L_8005D7A8
    if (ctx->r3 != ctx->r1) {
        // 0x8005D78C: nop
    
            goto L_8005D7A8;
    }
    // 0x8005D78C: nop

    // 0x8005D790: lbu         $t5, 0x1CD($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005D794: nop

    // 0x8005D798: sb          $t5, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r13;
    // 0x8005D79C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D7A0: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D7A4: nop

L_8005D7A8:
    // 0x8005D7A8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8005D7AC: lh          $t4, 0x18($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X18);
    // 0x8005D7B0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8005D7B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005D7B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005D7BC: sh          $t4, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r12;
    // 0x8005D7C0: cvt.w.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8005D7C4: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005D7C8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8005D7CC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005D7D0: bne         $v1, $zero, L_8005D804
    if (ctx->r3 != 0) {
        // 0x8005D7D4: sh          $t7, 0x18($s1)
        MEM_H(0X18, ctx->r17) = ctx->r15;
            goto L_8005D804;
    }
    // 0x8005D7D4: sh          $t7, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r15;
    // 0x8005D7D8: lh          $a2, 0x5C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X5C);
    // 0x8005D7DC: addiu       $t8, $zero, 0xAD
    ctx->r24 = ADD32(0, 0XAD);
    // 0x8005D7E0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005D7E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005D7E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8005D7EC: jal         0x800113CC
    // 0x8005D7F0: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    play_footstep_sounds(rdram, ctx);
        goto after_10;
    // 0x8005D7F0: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    after_10:
    // 0x8005D7F4: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x8005D7F8: nop

    // 0x8005D7FC: ori         $t2, $t9, 0x3
    ctx->r10 = ctx->r25 | 0X3;
    // 0x8005D800: sw          $t2, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r10;
L_8005D804:
    // 0x8005D804: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8005D808: jal         0x800B019C
    // 0x8005D80C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_11;
    // 0x8005D80C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8005D810: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005D814: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005D818: jal         0x8005D1E8
    // 0x8005D81C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    fade_when_near_camera(rdram, ctx);
        goto after_12;
    // 0x8005D81C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_12:
    // 0x8005D820: jal         0x8001BAFC
    // 0x8005D824: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_13;
    // 0x8005D824: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x8005D828: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8005D82C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005D830: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005D834: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005D838: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005D83C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005D840: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005D844: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005D848: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    // 0x8005D84C: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005D850: jal         0x800CA030
    // 0x8005D854: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_14;
    // 0x8005D854: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_14:
    // 0x8005D858: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D85C: lwc1        $f9, 0x6FD8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6FD8);
    // 0x8005D860: lwc1        $f8, 0x6FDC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FDC);
    // 0x8005D864: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8005D868: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8005D86C: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8005D870: bc1f        L_8005D8E0
    if (!c1cs) {
        // 0x8005D874: nop
    
            goto L_8005D8E0;
    }
    // 0x8005D874: nop

    // 0x8005D878: jal         0x80070990
    // 0x8005D87C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    arctan2_f(rdram, ctx);
        goto after_15;
    // 0x8005D87C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_15:
    // 0x8005D880: lh          $t3, 0x0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X0);
    // 0x8005D884: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005D888: andi        $t5, $t3, 0xFFFF
    ctx->r13 = ctx->r11 & 0XFFFF;
    // 0x8005D88C: subu        $v1, $v0, $t5
    ctx->r3 = SUB32(ctx->r2, ctx->r13);
    // 0x8005D890: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x8005D894: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005D898: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005D89C: bne         $at, $zero, L_8005D8AC
    if (ctx->r1 != 0) {
        // 0x8005D8A0: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8005D8AC;
    }
    // 0x8005D8A0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005D8A4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005D8A8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005D8AC:
    // 0x8005D8AC: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005D8B0: beq         $at, $zero, L_8005D8BC
    if (ctx->r1 == 0) {
        // 0x8005D8B4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005D8BC;
    }
    // 0x8005D8B4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005D8B8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005D8BC:
    // 0x8005D8BC: slti        $at, $v1, 0xC01
    ctx->r1 = SIGNED(ctx->r3) < 0XC01 ? 1 : 0;
    // 0x8005D8C0: bne         $at, $zero, L_8005D8D0
    if (ctx->r1 != 0) {
        // 0x8005D8C4: slti        $at, $v1, -0xC00
        ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
            goto L_8005D8D0;
    }
    // 0x8005D8C4: slti        $at, $v1, -0xC00
    ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
    // 0x8005D8C8: addiu       $v1, $zero, 0xC00
    ctx->r3 = ADD32(0, 0XC00);
    // 0x8005D8CC: slti        $at, $v1, -0xC00
    ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
L_8005D8D0:
    // 0x8005D8D0: beq         $at, $zero, L_8005D8DC
    if (ctx->r1 == 0) {
        // 0x8005D8D4: nop
    
            goto L_8005D8DC;
    }
    // 0x8005D8D4: nop

    // 0x8005D8D8: addiu       $v1, $zero, -0xC00
    ctx->r3 = ADD32(0, -0XC00);
L_8005D8DC:
    // 0x8005D8DC: sh          $v1, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r3;
L_8005D8E0:
    // 0x8005D8E0: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D8E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D8E8: bne         $v1, $at, L_8005D920
    if (ctx->r3 != ctx->r1) {
        // 0x8005D8EC: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8005D920;
    }
    // 0x8005D8EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005D8F0: lb          $t4, 0x1E7($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E7);
    // 0x8005D8F4: nop

    // 0x8005D8F8: andi        $t6, $t4, 0x1F
    ctx->r14 = ctx->r12 & 0X1F;
    // 0x8005D8FC: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x8005D900: beq         $at, $zero, L_8005D924
    if (ctx->r1 == 0) {
        // 0x8005D904: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005D924;
    }
    // 0x8005D904: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005D908: lh          $t7, 0x16C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X16C);
    // 0x8005D90C: nop

    // 0x8005D910: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8005D914: sh          $t8, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r24;
    // 0x8005D918: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D91C: nop

L_8005D920:
    // 0x8005D920: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8005D924:
    // 0x8005D924: bne         $v1, $at, L_8005D930
    if (ctx->r3 != ctx->r1) {
        // 0x8005D928: addiu       $a1, $a1, -0x24B0
        ctx->r5 = ADD32(ctx->r5, -0X24B0);
            goto L_8005D930;
    }
    // 0x8005D928: addiu       $a1, $a1, -0x24B0
    ctx->r5 = ADD32(ctx->r5, -0X24B0);
    // 0x8005D92C: sh          $zero, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = 0;
L_8005D930:
    // 0x8005D930: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8005D934: nop

    // 0x8005D938: lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4C);
    // 0x8005D93C: lw          $s0, 0x64($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X64);
    // 0x8005D940: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8005D944: nop

    // 0x8005D948: bne         $s1, $t9, L_8005D978
    if (ctx->r17 != ctx->r25) {
        // 0x8005D94C: nop
    
            goto L_8005D978;
    }
    // 0x8005D94C: nop

    // 0x8005D950: lh          $t2, 0x14($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X14);
    // 0x8005D954: nop

    // 0x8005D958: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x8005D95C: beq         $t3, $zero, L_8005D978
    if (ctx->r11 == 0) {
        // 0x8005D960: nop
    
            goto L_8005D978;
    }
    // 0x8005D960: nop

    // 0x8005D964: lb          $t5, 0x3B($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D968: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D96C: bne         $t5, $at, L_8005D978
    if (ctx->r13 != ctx->r1) {
        // 0x8005D970: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8005D978;
    }
    // 0x8005D970: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005D974: sb          $t4, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r12;
L_8005D978:
    // 0x8005D978: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005D97C: nop

    // 0x8005D980: beq         $t6, $zero, L_8005D9A4
    if (ctx->r14 == 0) {
        // 0x8005D984: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005D9A4;
    }
    // 0x8005D984: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D988: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x8005D98C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005D990: bne         $t7, $zero, L_8005D9A0
    if (ctx->r15 != 0) {
        // 0x8005D994: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005D9A0;
    }
    // 0x8005D994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D998: jal         0x8005CD08
    // 0x8005D99C: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    racer_boss_finish(rdram, ctx);
        goto after_16;
    // 0x8005D99C: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    after_16:
L_8005D9A0:
    // 0x8005D9A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005D9A4:
    // 0x8005D9A4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005D9A8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005D9AC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8005D9B0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005D9B4: jr          $ra
    // 0x8005D9B8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8005D9B8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void alFxParamHdl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800641EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800641F0: addiu       $v1, $a1, -0x2
    ctx->r3 = ADD32(ctx->r5, -0X2);
    // 0x800641F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800641F8: andi        $t6, $v1, 0x7
    ctx->r14 = ctx->r3 & 0X7;
    // 0x800641FC: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80064200: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80064204: beq         $at, $zero, L_80064454
    if (ctx->r1 == 0) {
        // 0x80064208: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80064454;
    }
    // 0x80064208: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8006420C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80064210: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80064214: addu        $at, $at, $t6
    gpr jr_addend_80064220 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80064218: lw          $t6, 0x7400($at)
    ctx->r14 = ADD32(ctx->r1, 0X7400);
    // 0x8006421C: nop

    // 0x80064220: jr          $t6
    // 0x80064224: nop

    switch (jr_addend_80064220 >> 2) {
        case 0: goto L_80064228; break;
        case 1: goto L_8006425C; break;
        case 2: goto L_800642BC; break;
        case 3: goto L_80064290; break;
        case 4: goto L_800642E8; break;
        case 5: goto L_80064314; break;
        case 6: goto L_80064384; break;
        case 7: goto L_80064404; break;
        default: switch_error(__func__, 0x80064220, 0x800E7400);
    }
    // 0x80064224: nop

L_80064228:
    // 0x80064228: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8006422C: and         $t7, $t0, $at
    ctx->r15 = ctx->r8 & ctx->r1;
    // 0x80064230: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x80064234: bgez        $v1, L_80064244
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80064238: sra         $t9, $v1, 3
        ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80064244;
    }
    // 0x80064238: sra         $t9, $v1, 3
    ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8006423C: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80064240: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_80064244:
    // 0x80064244: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80064248: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8006424C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80064250: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80064254: b           L_80064454
    // 0x80064258: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
        goto L_80064454;
    // 0x80064258: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
L_8006425C:
    // 0x8006425C: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80064260: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x80064264: lw          $t4, 0x20($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X20);
    // 0x80064268: bgez        $v1, L_80064278
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006426C: sra         $t5, $v1, 3
        ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80064278;
    }
    // 0x8006426C: sra         $t5, $v1, 3
    ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80064270: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80064274: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_80064278:
    // 0x80064278: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006427C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80064280: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80064284: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x80064288: b           L_80064454
    // 0x8006428C: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
        goto L_80064454;
    // 0x8006428C: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
L_80064290:
    // 0x80064290: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x80064294: bgez        $v1, L_800642A4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80064298: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800642A4;
    }
    // 0x80064298: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8006429C: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800642A0: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_800642A4:
    // 0x800642A4: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x800642A8: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x800642AC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800642B0: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x800642B4: b           L_80064454
    // 0x800642B8: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
        goto L_80064454;
    // 0x800642B8: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
L_800642BC:
    // 0x800642BC: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x800642C0: bgez        $v1, L_800642D0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800642C4: sra         $t4, $v1, 3
        ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800642D0;
    }
    // 0x800642C4: sra         $t4, $v1, 3
    ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800642C8: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800642CC: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_800642D0:
    // 0x800642D0: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800642D4: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800642D8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800642DC: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x800642E0: b           L_80064454
    // 0x800642E4: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
        goto L_80064454;
    // 0x800642E4: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
L_800642E8:
    // 0x800642E8: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x800642EC: bgez        $v1, L_800642FC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800642F0: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800642FC;
    }
    // 0x800642F0: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800642F4: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800642F8: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_800642FC:
    // 0x800642FC: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80064300: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x80064304: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80064308: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8006430C: b           L_80064454
    // 0x80064310: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
        goto L_80064454;
    // 0x80064310: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
L_80064314:
    // 0x80064314: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80064318: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8006431C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80064320: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80064324: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80064328: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006432C: lw          $t2, 0x3D10($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3D10);
    // 0x80064330: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x80064334: lw          $t4, 0x44($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X44);
    // 0x80064338: nop

    // 0x8006433C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80064340: nop

    // 0x80064344: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80064348: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8006434C: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x80064350: nop

    // 0x80064354: div.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f4.d);
    // 0x80064358: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8006435C: bgez        $v1, L_8006436C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80064360: sra         $t6, $v1, 3
        ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8006436C;
    }
    // 0x80064360: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80064364: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80064368: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8006436C:
    // 0x8006436C: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80064370: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x80064374: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80064378: addu        $t1, $t5, $t3
    ctx->r9 = ADD32(ctx->r13, ctx->r11);
    // 0x8006437C: b           L_80064454
    // 0x80064380: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
        goto L_80064454;
    // 0x80064380: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
L_80064384:
    // 0x80064384: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x80064388: bgez        $v1, L_80064398
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006438C: sra         $t8, $v1, 3
        ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80064398;
    }
    // 0x8006438C: sra         $t8, $v1, 3
    ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80064390: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80064394: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_80064398:
    // 0x80064398: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8006439C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800643A0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800643A4: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x800643A8: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800643AC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800643B0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800643B4: subu        $t6, $t2, $t4
    ctx->r14 = SUB32(ctx->r10, ctx->r12);
    // 0x800643B8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800643BC: bgez        $t6, L_800643D8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800643C0: cvt.d.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
            goto L_800643D8;
    }
    // 0x800643C0: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x800643C4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800643C8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800643CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800643D0: nop

    // 0x800643D4: add.d       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f18.d + ctx->f16.d;
L_800643D8:
    // 0x800643D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800643DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800643E0: lwc1        $f11, 0x7420($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X7420);
    // 0x800643E4: lwc1        $f10, 0x7424($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7424);
    // 0x800643E8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800643EC: nop

    // 0x800643F0: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800643F4: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x800643F8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800643FC: b           L_80064454
    // 0x80064400: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
        goto L_80064454;
    // 0x80064400: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
L_80064404:
    // 0x80064404: bgez        $v1, L_80064414
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80064408: sra         $v0, $v1, 3
        ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80064414;
    }
    // 0x80064408: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8006440C: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80064410: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_80064414:
    // 0x80064414: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80064418: lw          $t3, 0x20($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X20);
    // 0x8006441C: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x80064420: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80064424: addu        $t1, $t3, $t5
    ctx->r9 = ADD32(ctx->r11, ctx->r13);
    // 0x80064428: lw          $a1, 0x20($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X20);
    // 0x8006442C: nop

    // 0x80064430: beq         $a1, $zero, L_80064458
    if (ctx->r5 == 0) {
        // 0x80064434: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80064458;
    }
    // 0x80064434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064438: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x8006443C: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x80064440: nop

    // 0x80064444: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x80064448: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    // 0x8006444C: jal         0x80064B90
    // 0x80064450: nop

    init_lpfilter(rdram, ctx);
        goto after_0;
    // 0x80064450: nop

    after_0:
L_80064454:
    // 0x80064454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80064458:
    // 0x80064458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006445C: jr          $ra
    // 0x80064460: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80064460: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void load_menu_with_level_background(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DC68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006DC6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006DC70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006DC74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006DC78: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006DC7C: jal         0x8006EF3C
    // 0x8006DC80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alloc_displaylist_heap(rdram, ctx);
        goto after_0;
    // 0x8006DC80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8006DC84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006DC88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DC8C: sw          $v0, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = ctx->r2;
    // 0x8006DC90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DC94: sw          $v0, 0x3A70($at)
    MEM_W(0X3A70, ctx->r1) = ctx->r2;
    // 0x8006DC98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006DC9C: jal         0x80004A60
    // 0x8006DCA0: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_1;
    // 0x8006DCA0: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_1:
    // 0x8006DCA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006DCA8: jal         0x80004A60
    // 0x8006DCAC: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_2;
    // 0x8006DCAC: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_2:
    // 0x8006DCB0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8006DCB4: jal         0x80004A60
    // 0x8006DCB8: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_3;
    // 0x8006DCB8: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_3:
    // 0x8006DCBC: jal         0x800660E0
    // 0x8006DCC0: nop

    cam_init(rdram, ctx);
        goto after_4;
    // 0x8006DCC0: nop

    after_4:
    // 0x8006DCC4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DCC8: addiu       $v0, $v0, 0x3A94
    ctx->r2 = ADD32(ctx->r2, 0X3A94);
    // 0x8006DCCC: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8006DCD0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8006DCD4: bne         $t6, $zero, L_8006DD08
    if (ctx->r14 != 0) {
        // 0x8006DCD8: nop
    
            goto L_8006DD08;
    }
    // 0x8006DCD8: nop

    // 0x8006DCDC: bgez        $a0, L_8006DCF0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006DCE0: sb          $zero, 0x0($v0)
        MEM_B(0X0, ctx->r2) = 0;
            goto L_8006DCF0;
    }
    // 0x8006DCE0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8006DCE4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006DCE8: b           L_8006DD08
    // 0x8006DCEC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
        goto L_8006DD08;
    // 0x8006DCEC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_8006DCF0:
    // 0x8006DCF0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006DCF4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006DCF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006DCFC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8006DD00: jal         0x8006DD7C
    // 0x8006DD04: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    load_level_menu(rdram, ctx);
        goto after_5;
    // 0x8006DD04: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_5:
L_8006DD08:
    // 0x8006DD08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006DD0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006DD10: beq         $a0, $at, L_8006DD28
    if (ctx->r4 == ctx->r1) {
        // 0x8006DD14: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8006DD28;
    }
    // 0x8006DD14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006DD18: beq         $a0, $at, L_8006DD28
    if (ctx->r4 == ctx->r1) {
        // 0x8006DD1C: nop
    
            goto L_8006DD28;
    }
    // 0x8006DD1C: nop

    // 0x8006DD20: bne         $a0, $zero, L_8006DD38
    if (ctx->r4 != 0) {
        // 0x8006DD24: nop
    
            goto L_8006DD38;
    }
    // 0x8006DD24: nop

L_8006DD28:
    // 0x8006DD28: jal         0x80081810
    // 0x8006DD2C: nop

    reset_title_logo_scale(rdram, ctx);
        goto after_6;
    // 0x8006DD2C: nop

    after_6:
    // 0x8006DD30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006DD34: nop

L_8006DD38:
    // 0x8006DD38: jal         0x80081820
    // 0x8006DD3C: nop

    menu_init(rdram, ctx);
        goto after_7;
    // 0x8006DD3C: nop

    after_7:
    // 0x8006DD40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DD44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DD48: sw          $zero, 0x3A84($at)
    MEM_W(0X3A84, ctx->r1) = 0;
    // 0x8006DD4C: jr          $ra
    // 0x8006DD50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006DD50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void filename_compress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097C80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80097C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80097C88: blez        $a1, L_80097D04
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80097C8C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80097D04;
    }
    // 0x80097C8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80097C90: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80097C94: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80097C98: lbu         $t3, 0x14EC($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X14EC);
    // 0x80097C9C: addiu       $t4, $t4, 0x14EC
    ctx->r12 = ADD32(ctx->r12, 0X14EC);
    // 0x80097CA0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_80097CA4:
    // 0x80097CA4: lbu         $a0, 0x0($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X0);
    // 0x80097CA8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80097CAC: bne         $a0, $zero, L_80097CB8
    if (ctx->r4 != 0) {
        // 0x80097CB0: sll         $t8, $v1, 5
        ctx->r24 = S32(ctx->r3 << 5);
            goto L_80097CB8;
    }
    // 0x80097CB0: sll         $t8, $v1, 5
    ctx->r24 = S32(ctx->r3 << 5);
    // 0x80097CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097CB8:
    // 0x80097CB8: bne         $v0, $zero, L_80097CC8
    if (ctx->r2 != 0) {
        // 0x80097CBC: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80097CC8;
    }
    // 0x80097CBC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80097CC0: b           L_80097CCC
    // 0x80097CC4: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
        goto L_80097CCC;
    // 0x80097CC4: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
L_80097CC8:
    // 0x80097CC8: andi        $t0, $a0, 0xFF
    ctx->r8 = ctx->r4 & 0XFF;
L_80097CCC:
    // 0x80097CCC: beq         $t0, $t3, L_80097CF4
    if (ctx->r8 == ctx->r11) {
        // 0x80097CD0: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80097CF4;
    }
    // 0x80097CD0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_80097CD4:
    // 0x80097CD4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80097CD8: slti        $at, $t1, 0x1F
    ctx->r1 = SIGNED(ctx->r9) < 0X1F ? 1 : 0;
    // 0x80097CDC: beq         $at, $zero, L_80097CF4
    if (ctx->r1 == 0) {
        // 0x80097CE0: addu        $t6, $t4, $t1
        ctx->r14 = ADD32(ctx->r12, ctx->r9);
            goto L_80097CF4;
    }
    // 0x80097CE0: addu        $t6, $t4, $t1
    ctx->r14 = ADD32(ctx->r12, ctx->r9);
    // 0x80097CE4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80097CE8: nop

    // 0x80097CEC: bne         $a0, $t7, L_80097CD4
    if (ctx->r4 != ctx->r15) {
        // 0x80097CF0: nop
    
            goto L_80097CD4;
    }
    // 0x80097CF0: nop

L_80097CF4:
    // 0x80097CF4: andi        $t9, $t1, 0x1F
    ctx->r25 = ctx->r9 & 0X1F;
    // 0x80097CF8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80097CFC: bne         $a2, $a1, L_80097CA4
    if (ctx->r6 != ctx->r5) {
        // 0x80097D00: or          $v1, $t8, $t9
        ctx->r3 = ctx->r24 | ctx->r25;
            goto L_80097CA4;
    }
    // 0x80097D00: or          $v1, $t8, $t9
    ctx->r3 = ctx->r24 | ctx->r25;
L_80097D04:
    // 0x80097D04: jr          $ra
    // 0x80097D08: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80097D08: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void menu_pause_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094674: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80094678: lw          $t6, 0xF04($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XF04);
    // 0x8009467C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80094680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094684: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80094688: bne         $t6, $zero, L_800946A0
    if (ctx->r14 != 0) {
        // 0x8009468C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800946A0;
    }
    // 0x8009468C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80094690: jal         0x80000968
    // 0x80094694: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_change(rdram, ctx);
        goto after_0;
    // 0x80094694: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80094698: b           L_80094AA4
    // 0x8009469C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80094AA4;
    // 0x8009469C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800946A0:
    // 0x800946A0: jal         0x80000968
    // 0x800946A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sound_volume_change(rdram, ctx);
        goto after_1;
    // 0x800946A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800946A8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800946AC: addiu       $v0, $v0, 0x695C
    ctx->r2 = ADD32(ctx->r2, 0X695C);
    // 0x800946B0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800946B4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800946B8: nop

    // 0x800946BC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800946C0: andi        $t1, $t9, 0x3F
    ctx->r9 = ctx->r25 & 0X3F;
    // 0x800946C4: jal         0x8009C464
    // 0x800946C8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    update_controller_sticks(rdram, ctx);
        goto after_2;
    // 0x800946C8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    after_2:
    // 0x800946CC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800946D0: lw          $t2, 0x6964($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6964);
    // 0x800946D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800946D8: bne         $t2, $zero, L_800946F0
    if (ctx->r10 != 0) {
        // 0x800946DC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800946F0;
    }
    // 0x800946DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800946E0: lw          $a0, 0xF0C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XF0C);
    // 0x800946E4: jal         0x8006A794
    // 0x800946E8: nop

    input_pressed(rdram, ctx);
        goto after_3;
    // 0x800946E8: nop

    after_3:
    // 0x800946EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800946F0:
    // 0x800946F0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800946F4: addiu       $a2, $a2, -0x604
    ctx->r6 = ADD32(ctx->r6, -0X604);
    // 0x800946F8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800946FC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80094700: bne         $v0, $zero, L_800948EC
    if (ctx->r2 != 0) {
        // 0x80094704: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_800948EC;
    }
    // 0x80094704: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x80094708: addiu       $t0, $t0, 0xF08
    ctx->r8 = ADD32(ctx->r8, 0XF08);
    // 0x8009470C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80094710: andi        $t3, $v1, 0x9000
    ctx->r11 = ctx->r3 & 0X9000;
    // 0x80094714: beq         $v0, $zero, L_800947C8
    if (ctx->r2 == 0) {
        // 0x80094718: andi        $t1, $v1, 0x9000
        ctx->r9 = ctx->r3 & 0X9000;
            goto L_800947C8;
    }
    // 0x80094718: andi        $t1, $v1, 0x9000
    ctx->r9 = ctx->r3 & 0X9000;
    // 0x8009471C: beq         $t3, $zero, L_8009475C
    if (ctx->r11 == 0) {
        // 0x80094720: andi        $t5, $v1, 0x4000
        ctx->r13 = ctx->r3 & 0X4000;
            goto L_8009475C;
    }
    // 0x80094720: andi        $t5, $v1, 0x4000
    ctx->r13 = ctx->r3 & 0X4000;
    // 0x80094724: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80094728: jal         0x80001D04
    // 0x8009472C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8009472C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80094730: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80094734: addiu       $t0, $t0, 0xF08
    ctx->r8 = ADD32(ctx->r8, 0XF08);
    // 0x80094738: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8009473C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80094740: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80094744: bne         $v0, $t4, L_80094754
    if (ctx->r2 != ctx->r12) {
        // 0x80094748: addiu       $a2, $a2, -0x604
        ctx->r6 = ADD32(ctx->r6, -0X604);
            goto L_80094754;
    }
    // 0x80094748: addiu       $a2, $a2, -0x604
    ctx->r6 = ADD32(ctx->r6, -0X604);
    // 0x8009474C: b           L_80094A8C
    // 0x80094750: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_80094A8C;
    // 0x80094750: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80094754:
    // 0x80094754: b           L_80094A8C
    // 0x80094758: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
        goto L_80094A8C;
    // 0x80094758: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_8009475C:
    // 0x8009475C: beq         $t5, $zero, L_80094780
    if (ctx->r13 == 0) {
        // 0x80094760: sll         $a1, $v0, 24
        ctx->r5 = S32(ctx->r2 << 24);
            goto L_80094780;
    }
    // 0x80094760: sll         $a1, $v0, 24
    ctx->r5 = S32(ctx->r2 << 24);
    // 0x80094764: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80094768: jal         0x80001D04
    // 0x8009476C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8009476C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80094770: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80094774: addiu       $t0, $t0, 0xF08
    ctx->r8 = ADD32(ctx->r8, 0XF08);
    // 0x80094778: b           L_80094A8C
    // 0x8009477C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
        goto L_80094A8C;
    // 0x8009477C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_80094780:
    // 0x80094780: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80094784: lw          $a0, 0xF0C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XF0C);
    // 0x80094788: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009478C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80094790: lb          $t7, 0x6A04($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X6A04);
    // 0x80094794: sra         $t6, $a1, 24
    ctx->r14 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80094798: beq         $t7, $zero, L_800947B0
    if (ctx->r15 == 0) {
        // 0x8009479C: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_800947B0;
    }
    // 0x8009479C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800947A0: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800947A4: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x800947A8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800947AC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800947B0:
    // 0x800947B0: beq         $a1, $v0, L_80094A8C
    if (ctx->r5 == ctx->r2) {
        // 0x800947B4: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80094A8C;
    }
    // 0x800947B4: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800947B8: jal         0x80001D04
    // 0x800947BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x800947BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x800947C0: b           L_80094A90
    // 0x800947C4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_80094A90;
    // 0x800947C4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800947C8:
    // 0x800947C8: beq         $t1, $zero, L_80094854
    if (ctx->r9 == 0) {
        // 0x800947CC: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80094854;
    }
    // 0x800947CC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800947D0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x800947D4: jal         0x80001D04
    // 0x800947D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x800947D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x800947DC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800947E0: addiu       $a3, $a3, 0x7028
    ctx->r7 = ADD32(ctx->r7, 0X7028);
    // 0x800947E4: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800947E8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800947EC: lw          $v1, -0x5E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E0);
    // 0x800947F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800947F4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800947F8: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800947FC: lw          $v0, 0x7000($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7000);
    // 0x80094800: lw          $t4, 0x20C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X20C);
    // 0x80094804: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80094808: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009480C: addiu       $t0, $t0, 0xF08
    ctx->r8 = ADD32(ctx->r8, 0XF08);
    // 0x80094810: beq         $v0, $t4, L_8009483C
    if (ctx->r2 == ctx->r12) {
        // 0x80094814: addiu       $a2, $a2, -0x604
        ctx->r6 = ADD32(ctx->r6, -0X604);
            goto L_8009483C;
    }
    // 0x80094814: addiu       $a2, $a2, -0x604
    ctx->r6 = ADD32(ctx->r6, -0X604);
    // 0x80094818: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009481C: addiu       $a0, $a0, 0x1568
    ctx->r4 = ADD32(ctx->r4, 0X1568);
    // 0x80094820: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80094824: nop

    // 0x80094828: beq         $t5, $zero, L_80094848
    if (ctx->r13 == 0) {
        // 0x8009482C: nop
    
            goto L_80094848;
    }
    // 0x8009482C: nop

    // 0x80094830: lw          $t6, 0x204($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X204);
    // 0x80094834: nop

    // 0x80094838: bne         $v0, $t6, L_80094848
    if (ctx->r2 != ctx->r14) {
        // 0x8009483C: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80094848;
    }
L_8009483C:
    // 0x8009483C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80094840: b           L_80094A8C
    // 0x80094844: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
        goto L_80094A8C;
    // 0x80094844: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
L_80094848:
    // 0x80094848: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009484C: b           L_80094A8C
    // 0x80094850: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_80094A8C;
    // 0x80094850: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80094854:
    // 0x80094854: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80094858: lw          $a0, 0xF0C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XF0C);
    // 0x8009485C: addiu       $a3, $a3, 0x7028
    ctx->r7 = ADD32(ctx->r7, 0X7028);
    // 0x80094860: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80094864: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80094868: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8009486C: lb          $v1, 0x6A04($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A04);
    // 0x80094870: sll         $a1, $v0, 24
    ctx->r5 = S32(ctx->r2 << 24);
    // 0x80094874: sra         $t8, $a1, 24
    ctx->r24 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80094878: bgez        $v1, L_8009488C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8009487C: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_8009488C;
    }
    // 0x8009487C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80094880: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80094884: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80094888: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8009488C:
    // 0x8009488C: blez        $v1, L_800948A0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80094890: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_800948A0;
    }
    // 0x80094890: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80094894: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80094898: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x8009489C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800948A0:
    // 0x800948A0: bgez        $v0, L_800948B8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800948A4: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_800948B8;
    }
    // 0x800948A4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800948A8: lw          $t2, 0xF04($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XF04);
    // 0x800948AC: nop

    // 0x800948B0: addiu       $v0, $t2, -0x1
    ctx->r2 = ADD32(ctx->r10, -0X1);
    // 0x800948B4: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
L_800948B8:
    // 0x800948B8: lw          $t4, 0xF04($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XF04);
    // 0x800948BC: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800948C0: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800948C4: bne         $at, $zero, L_800948D4
    if (ctx->r1 != 0) {
        // 0x800948C8: nop
    
            goto L_800948D4;
    }
    // 0x800948C8: nop

    // 0x800948CC: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800948D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800948D4:
    // 0x800948D4: beq         $a1, $v0, L_80094A8C
    if (ctx->r5 == ctx->r2) {
        // 0x800948D8: nop
    
            goto L_80094A8C;
    }
    // 0x800948D8: nop

    // 0x800948DC: jal         0x80001D04
    // 0x800948E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800948E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800948E4: b           L_80094A90
    // 0x800948E8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_80094A90;
    // 0x800948E8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800948EC:
    // 0x800948EC: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x800948F0: bne         $at, $zero, L_80094A8C
    if (ctx->r1 != 0) {
        // 0x800948F4: sw          $t5, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r13;
            goto L_80094A8C;
    }
    // 0x800948F4: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800948F8: jal         0x80094AB4
    // 0x800948FC: nop

    menu_dialogue_end(rdram, ctx);
        goto after_9;
    // 0x800948FC: nop

    after_9:
    // 0x80094900: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80094904: addiu       $t0, $t0, 0xF08
    ctx->r8 = ADD32(ctx->r8, 0XF08);
    // 0x80094908: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8009490C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80094910: bne         $v0, $t7, L_8009495C
    if (ctx->r2 != ctx->r15) {
        // 0x80094914: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_8009495C;
    }
    // 0x80094914: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80094918: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009491C: addiu       $a0, $a0, 0x1568
    ctx->r4 = ADD32(ctx->r4, 0X1568);
    // 0x80094920: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80094924: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80094928: beq         $t8, $zero, L_80094954
    if (ctx->r24 == 0) {
        // 0x8009492C: nop
    
            goto L_80094954;
    }
    // 0x8009492C: nop

    // 0x80094930: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80094934: lw          $t9, -0x5C8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5C8);
    // 0x80094938: nop

    // 0x8009493C: bne         $t9, $zero, L_8009494C
    if (ctx->r25 != 0) {
        // 0x80094940: nop
    
            goto L_8009494C;
    }
    // 0x80094940: nop

    // 0x80094944: b           L_80094AA4
    // 0x80094948: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80094AA4;
    // 0x80094948: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8009494C:
    // 0x8009494C: b           L_80094AA4
    // 0x80094950: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80094AA4;
    // 0x80094950: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80094954:
    // 0x80094954: b           L_80094AA4
    // 0x80094958: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80094AA4;
    // 0x80094958: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8009495C:
    // 0x8009495C: addiu       $a3, $a3, 0x7028
    ctx->r7 = ADD32(ctx->r7, 0X7028);
    // 0x80094960: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80094964: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80094968: lw          $v1, -0x5E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E0);
    // 0x8009496C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80094970: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80094974: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80094978: lw          $v0, 0x7000($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7000);
    // 0x8009497C: lw          $t3, 0x188($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X188);
    // 0x80094980: nop

    // 0x80094984: bne         $v0, $t3, L_8009499C
    if (ctx->r2 != ctx->r11) {
        // 0x80094988: nop
    
            goto L_8009499C;
    }
    // 0x80094988: nop

    // 0x8009498C: jal         0x80000968
    // 0x80094990: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_change(rdram, ctx);
        goto after_10;
    // 0x80094990: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80094994: b           L_80094AA4
    // 0x80094998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80094AA4;
    // 0x80094998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009499C:
    // 0x8009499C: lw          $t4, 0x1F8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1F8);
    // 0x800949A0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800949A4: beq         $v0, $t4, L_800949BC
    if (ctx->r2 == ctx->r12) {
        // 0x800949A8: nop
    
            goto L_800949BC;
    }
    // 0x800949A8: nop

    // 0x800949AC: lw          $t5, 0x1FC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X1FC);
    // 0x800949B0: nop

    // 0x800949B4: bne         $v0, $t5, L_80094A1C
    if (ctx->r2 != ctx->r13) {
        // 0x800949B8: nop
    
            goto L_80094A1C;
    }
    // 0x800949B8: nop

L_800949BC:
    // 0x800949BC: lw          $t6, -0x5C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C8);
    // 0x800949C0: nop

    // 0x800949C4: bne         $t6, $zero, L_80094A14
    if (ctx->r14 != 0) {
        // 0x800949C8: nop
    
            goto L_80094A14;
    }
    // 0x800949C8: nop

    // 0x800949CC: jal         0x8006ED54
    // 0x800949D0: nop

    get_ingame_map_id(rdram, ctx);
        goto after_11;
    // 0x800949D0: nop

    after_11:
    // 0x800949D4: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800949D8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800949DC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800949E0: lh          $t8, 0xCD8($t8)
    ctx->r24 = MEM_H(ctx->r24, 0XCD8);
    // 0x800949E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800949E8: beq         $t8, $at, L_80094A14
    if (ctx->r24 == ctx->r1) {
        // 0x800949EC: nop
    
            goto L_80094A14;
    }
    // 0x800949EC: nop

    // 0x800949F0: jal         0x8006ED54
    // 0x800949F4: nop

    get_ingame_map_id(rdram, ctx);
        goto after_12;
    // 0x800949F4: nop

    after_12:
    // 0x800949F8: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800949FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80094A00: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80094A04: lhu         $a0, 0xCD8($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XCD8);
    // 0x80094A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80094A0C: jal         0x80000FDC
    // 0x80094A10: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_13;
    // 0x80094A10: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_13:
L_80094A14:
    // 0x80094A14: b           L_80094AA4
    // 0x80094A18: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80094AA4;
    // 0x80094A18: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80094A1C:
    // 0x80094A1C: lw          $t1, 0x64($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X64);
    // 0x80094A20: nop

    // 0x80094A24: bne         $v0, $t1, L_80094A34
    if (ctx->r2 != ctx->r9) {
        // 0x80094A28: nop
    
            goto L_80094A34;
    }
    // 0x80094A28: nop

    // 0x80094A2C: b           L_80094AA4
    // 0x80094A30: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80094AA4;
    // 0x80094A30: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80094A34:
    // 0x80094A34: lw          $t2, 0x60($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X60);
    // 0x80094A38: nop

    // 0x80094A3C: bne         $v0, $t2, L_80094A4C
    if (ctx->r2 != ctx->r10) {
        // 0x80094A40: nop
    
            goto L_80094A4C;
    }
    // 0x80094A40: nop

    // 0x80094A44: b           L_80094AA4
    // 0x80094A48: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80094AA4;
    // 0x80094A48: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80094A4C:
    // 0x80094A4C: lw          $t3, 0x68($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X68);
    // 0x80094A50: nop

    // 0x80094A54: bne         $v0, $t3, L_80094A64
    if (ctx->r2 != ctx->r11) {
        // 0x80094A58: nop
    
            goto L_80094A64;
    }
    // 0x80094A58: nop

    // 0x80094A5C: b           L_80094AA4
    // 0x80094A60: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_80094AA4;
    // 0x80094A60: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_80094A64:
    // 0x80094A64: lw          $t4, 0x200($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X200);
    // 0x80094A68: nop

    // 0x80094A6C: bne         $v0, $t4, L_80094A84
    if (ctx->r2 != ctx->r12) {
        // 0x80094A70: nop
    
            goto L_80094A84;
    }
    // 0x80094A70: nop

    // 0x80094A74: jal         0x80000968
    // 0x80094A78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_change(rdram, ctx);
        goto after_14;
    // 0x80094A78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x80094A7C: b           L_80094AA4
    // 0x80094A80: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80094AA4;
    // 0x80094A80: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80094A84:
    // 0x80094A84: b           L_80094AA4
    // 0x80094A88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80094AA4;
    // 0x80094A88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80094A8C:
    // 0x80094A8C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80094A90:
    // 0x80094A90: jal         0x80094244
    // 0x80094A94: nop

    pausemenu_render(rdram, ctx);
        goto after_15;
    // 0x80094A94: nop

    after_15:
    // 0x80094A98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094A9C: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x80094AA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80094AA4:
    // 0x80094AA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094AA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80094AAC: jr          $ra
    // 0x80094AB0: nop

    return;
    // 0x80094AB0: nop

;}
RECOMP_FUNC void music_channel_volume_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800011E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800011EC: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x800011F0: slti        $at, $a3, 0x10
    ctx->r1 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
    // 0x800011F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800011F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800011FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001200: beq         $at, $zero, L_80001218
    if (ctx->r1 == 0) {
        // 0x80001204: andi        $a2, $a1, 0xFF
        ctx->r6 = ctx->r5 & 0XFF;
            goto L_80001218;
    }
    // 0x80001204: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x80001208: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000120C: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001210: jal         0x800C7EA0
    // 0x80001214: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    alCSPSetChlVol(rdram, ctx);
        goto after_0;
    // 0x80001214: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    after_0:
L_80001218:
    // 0x80001218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000121C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001220: jr          $ra
    // 0x80001224: nop

    return;
    // 0x80001224: nop

;}
RECOMP_FUNC void mtxf_to_mtx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FAB0: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8006FAB4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8006FAB8: ori         $t0, $zero, 0x4
    ctx->r8 = 0 | 0X4;
L_8006FABC:
    // 0x8006FABC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006FAC0: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006FAC4: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006FAC8: mul.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006FACC: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8006FAD0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8006FAD4: mul.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006FAD8: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8006FADC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8006FAE0: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8006FAE4: nop

    // 0x8006FAE8: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8006FAEC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8006FAF0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8006FAF4: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x8006FAF8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8006FAFC: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8006FB00: sh          $t1, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r9;
    // 0x8006FB04: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8006FB08: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8006FB0C: sh          $t2, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r10;
    // 0x8006FB10: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x8006FB14: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8006FB18: sh          $t3, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r11;
    // 0x8006FB1C: srl         $t2, $t2, 16
    ctx->r10 = S32(U32(ctx->r10) >> 16);
    // 0x8006FB20: sh          $t4, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = ctx->r12;
    // 0x8006FB24: srl         $t3, $t3, 16
    ctx->r11 = S32(U32(ctx->r11) >> 16);
    // 0x8006FB28: srl         $t4, $t4, 16
    ctx->r12 = S32(U32(ctx->r12) >> 16);
    // 0x8006FB2C: sh          $t1, -0x8($a1)
    MEM_H(-0X8, ctx->r5) = ctx->r9;
    // 0x8006FB30: sh          $t2, -0x6($a1)
    MEM_H(-0X6, ctx->r5) = ctx->r10;
    // 0x8006FB34: sh          $t3, -0x4($a1)
    MEM_H(-0X4, ctx->r5) = ctx->r11;
    // 0x8006FB38: sh          $t4, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r12;
    // 0x8006FB3C: bnel        $t0, $zero, L_8006FABC
    if (ctx->r8 != 0) {
        // 0x8006FB40: nop
    
            goto L_8006FABC;
    }
    goto skip_0;
    // 0x8006FB40: nop

    skip_0:
    // 0x8006FB44: jr          $ra
    // 0x8006FB48: nop

    return;
    // 0x8006FB48: nop

;}
RECOMP_FUNC void get_si_device_status(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075B34: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80075B38: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80075B3C: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80075B40: addiu       $s4, $s4, 0x4590
    ctx->r20 = ADD32(ctx->r20, 0X4590);
    // 0x80075B44: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80075B48: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80075B4C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80075B50: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80075B54: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80075B58: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80075B5C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80075B60: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80075B64: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80075B68: bne         $t6, $zero, L_80075BA8
    if (ctx->r14 != 0) {
        // 0x80075B6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80075BA8;
    }
    // 0x80075B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80075B70: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x80075B74: subu        $t7, $t7, $s5
    ctx->r15 = SUB32(ctx->r15, ctx->r21);
    // 0x80075B78: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80075B7C: addu        $t7, $t7, $s5
    ctx->r15 = ADD32(ctx->r15, ctx->r21);
    // 0x80075B80: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80075B84: addiu       $t8, $t8, 0x4598
    ctx->r24 = ADD32(ctx->r24, 0X4598);
    // 0x80075B88: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80075B8C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80075B90: jal         0x8007231C
    // 0x80075B94: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_0;
    // 0x80075B94: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_0:
    // 0x80075B98: bne         $v0, $zero, L_80075BAC
    if (ctx->r2 != 0) {
        // 0x80075B9C: sll         $t9, $s5, 2
        ctx->r25 = S32(ctx->r21 << 2);
            goto L_80075BAC;
    }
    // 0x80075B9C: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
    // 0x80075BA0: b           L_80075D20
    // 0x80075BA4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80075D20;
    // 0x80075BA4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80075BA8:
    // 0x80075BA8: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
L_80075BAC:
    // 0x80075BAC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80075BB0: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x80075BB4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80075BB8: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x80075BBC: addu        $t9, $t9, $s5
    ctx->r25 = ADD32(ctx->r25, ctx->r21);
    // 0x80075BC0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80075BC4: addiu       $t0, $t0, 0x4598
    ctx->r8 = ADD32(ctx->r8, 0X4598);
    // 0x80075BC8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80075BCC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80075BD0: beq         $t1, $zero, L_80075C0C
    if (ctx->r9 == 0) {
        // 0x80075BD4: addu        $s3, $t9, $t0
        ctx->r19 = ADD32(ctx->r25, ctx->r8);
            goto L_80075C0C;
    }
    // 0x80075BD4: addu        $s3, $t9, $t0
    ctx->r19 = ADD32(ctx->r25, ctx->r8);
    // 0x80075BD8: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x80075BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80075BE0:
    // 0x80075BE0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80075BE4: jal         0x800C9110
    // 0x80075BE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80075BE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80075BEC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80075BF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80075BF4: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80075BF8: nop

    // 0x80075BFC: beq         $t2, $zero, L_80075C0C
    if (ctx->r10 == 0) {
        // 0x80075C00: nop
    
            goto L_80075C0C;
    }
    // 0x80075C00: nop

    // 0x80075C04: bne         $s1, $s2, L_80075BE0
    if (ctx->r17 != ctx->r18) {
        // 0x80075C08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80075BE0;
    }
    // 0x80075C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80075C0C:
    // 0x80075C0C: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x80075C10: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80075C14: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x80075C18: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80075C1C:
    // 0x80075C1C: jal         0x800CF940
    // 0x80075C20: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_2;
    // 0x80075C20: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x80075C24: bne         $v0, $s0, L_80075C40
    if (ctx->r2 != ctx->r16) {
        // 0x80075C28: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80075C40;
    }
    // 0x80075C28: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80075C2C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075C30: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80075C34: jal         0x800CF280
    // 0x80075C38: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_3;
    // 0x80075C38: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x80075C3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80075C40:
    // 0x80075C40: bne         $v0, $s2, L_80075C6C
    if (ctx->r2 != ctx->r18) {
        // 0x80075C44: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_80075C6C;
    }
    // 0x80075C44: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80075C48: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075C4C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80075C50: jal         0x8007231C
    // 0x80075C54: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    osMotorInit_recomp(rdram, ctx);
        goto after_4;
    // 0x80075C54: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_4:
    // 0x80075C58: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80075C5C: bne         $v0, $zero, L_80075C70
    if (ctx->r2 != 0) {
        // 0x80075C60: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80075C70;
    }
    // 0x80075C60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80075C64: b           L_80075D20
    // 0x80075C68: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80075D20;
    // 0x80075C68: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80075C6C:
    // 0x80075C6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80075C70:
    // 0x80075C70: bne         $v1, $at, L_80075CB8
    if (ctx->r3 != ctx->r1) {
        // 0x80075C74: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80075CB8;
    }
    // 0x80075C74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80075C78: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075C7C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80075C80: jal         0x800CF280
    // 0x80075C84: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_5;
    // 0x80075C84: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_5:
    // 0x80075C88: bne         $v0, $s2, L_80075CAC
    if (ctx->r2 != ctx->r18) {
        // 0x80075C8C: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_80075CAC;
    }
    // 0x80075C8C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80075C90: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075C94: jal         0x8007231C
    // 0x80075C98: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_6;
    // 0x80075C98: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_6:
    // 0x80075C9C: bne         $v0, $zero, L_80075CAC
    if (ctx->r2 != 0) {
        // 0x80075CA0: nop
    
            goto L_80075CAC;
    }
    // 0x80075CA0: nop

    // 0x80075CA4: b           L_80075D20
    // 0x80075CA8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80075D20;
    // 0x80075CA8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80075CAC:
    // 0x80075CAC: b           L_80075D20
    // 0x80075CB0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80075D20;
    // 0x80075CB0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80075CB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80075CB8:
    // 0x80075CB8: beq         $v1, $at, L_80075CC8
    if (ctx->r3 == ctx->r1) {
        // 0x80075CBC: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80075CC8;
    }
    // 0x80075CBC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80075CC0: bne         $v1, $at, L_80075CD0
    if (ctx->r3 != ctx->r1) {
        // 0x80075CC4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80075CD0;
    }
    // 0x80075CC4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80075CC8:
    // 0x80075CC8: b           L_80075D20
    // 0x80075CCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80075D20;
    // 0x80075CCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80075CD0:
    // 0x80075CD0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80075CD4: bne         $v1, $at, L_80075CE4
    if (ctx->r3 != ctx->r1) {
        // 0x80075CD8: nop
    
            goto L_80075CE4;
    }
    // 0x80075CD8: nop

    // 0x80075CDC: b           L_80075D20
    // 0x80075CE0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_80075D20;
    // 0x80075CE0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80075CE4:
    // 0x80075CE4: bne         $v1, $s2, L_80075CF4
    if (ctx->r3 != ctx->r18) {
        // 0x80075CE8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80075CF4;
    }
    // 0x80075CE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80075CEC: b           L_80075D20
    // 0x80075CF0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80075D20;
    // 0x80075CF0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80075CF4:
    // 0x80075CF4: bne         $v1, $at, L_80075D04
    if (ctx->r3 != ctx->r1) {
        // 0x80075CF8: nop
    
            goto L_80075D04;
    }
    // 0x80075CF8: nop

    // 0x80075CFC: b           L_80075D20
    // 0x80075D00: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80075D20;
    // 0x80075D00: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80075D04:
    // 0x80075D04: bne         $v1, $zero, L_80075D14
    if (ctx->r3 != 0) {
        // 0x80075D08: nop
    
            goto L_80075D14;
    }
    // 0x80075D08: nop

    // 0x80075D0C: b           L_80075D20
    // 0x80075D10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80075D20;
    // 0x80075D10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80075D14:
    // 0x80075D14: bne         $s1, $s0, L_80075C1C
    if (ctx->r17 != ctx->r16) {
        // 0x80075D18: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80075C1C;
    }
    // 0x80075D18: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80075D1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80075D20:
    // 0x80075D20: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80075D24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80075D28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80075D2C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80075D30: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80075D34: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80075D38: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80075D3C: jr          $ra
    // 0x80075D40: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80075D40: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void init_triangle_particle_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF374: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800AF378: sh          $t6, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r14;
    // 0x800AF37C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800AF380: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF384: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800AF388: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800AF38C: addiu       $v1, $v1, 0x33F8
    ctx->r3 = ADD32(ctx->r3, 0X33F8);
    // 0x800AF390: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AF394: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_800AF398:
    // 0x800AF398: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800AF39C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800AF3A0: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800AF3A4: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x800AF3A8: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x800AF3AC: sra         $a3, $t1, 16
    ctx->r7 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800AF3B0: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x800AF3B4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AF3B8: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800AF3BC: sb          $t0, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r8;
    // 0x800AF3C0: sb          $t0, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r8;
    // 0x800AF3C4: sb          $t0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r8;
    // 0x800AF3C8: sb          $t0, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r8;
    // 0x800AF3CC: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800AF3D0: bne         $at, $zero, L_800AF398
    if (ctx->r1 != 0) {
        // 0x800AF3D4: sh          $t9, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = ctx->r25;
            goto L_800AF398;
    }
    // 0x800AF3D4: sh          $t9, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r25;
    // 0x800AF3D8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800AF3DC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AF3E0: sh          $t3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r11;
    // 0x800AF3E4: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800AF3E8: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x800AF3EC: sw          $t4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r12;
    // 0x800AF3F0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800AF3F4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800AF3F8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AF3FC: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x800AF400: sb          $t6, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r14;
    // 0x800AF404: sb          $t7, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r15;
    // 0x800AF408: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x800AF40C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800AF410: jr          $ra
    // 0x800AF414: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    return;
    // 0x800AF414: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
;}
RECOMP_FUNC void get_fog_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030790: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80030794: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80030798: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8003079C: addiu       $t7, $t7, -0x26F8
    ctx->r15 = ADD32(ctx->r15, -0X26F8);
    // 0x800307A0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800307A4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800307A8: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800307AC: nop

    // 0x800307B0: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800307B4: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x800307B8: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x800307BC: nop

    // 0x800307C0: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800307C4: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
    // 0x800307C8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800307CC: nop

    // 0x800307D0: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800307D4: sb          $t3, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r11;
    // 0x800307D8: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x800307DC: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800307E0: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800307E4: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x800307E8: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x800307EC: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800307F0: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800307F4: jr          $ra
    // 0x800307F8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    return;
    // 0x800307F8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
;}
RECOMP_FUNC void hud_race_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A422C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800A4230: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A4234: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800A4238: jal         0x8006ECE0
    // 0x800A423C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    is_game_paused(rdram, ctx);
        goto after_0;
    // 0x800A423C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A4240: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800A4244: bne         $v0, $zero, L_800A468C
    if (ctx->r2 != 0) {
        // 0x800A4248: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800A468C;
    }
    // 0x800A4248: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A424C: bne         $t1, $zero, L_800A4270
    if (ctx->r9 != 0) {
        // 0x800A4250: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800A4270;
    }
    // 0x800A4250: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A4254: addiu       $v1, $v1, 0x2CF0
    ctx->r3 = ADD32(ctx->r3, 0X2CF0);
    // 0x800A4258: lb          $t6, 0xC($v1)
    ctx->r14 = MEM_B(ctx->r3, 0XC);
    // 0x800A425C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800A4260: bne         $v0, $t6, L_800A4270
    if (ctx->r2 != ctx->r14) {
        // 0x800A4264: nop
    
            goto L_800A4270;
    }
    // 0x800A4264: nop

    // 0x800A4268: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x800A426C: sb          $v0, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r2;
L_800A4270:
    // 0x800A4270: lw          $t7, 0x72CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72CC);
    // 0x800A4274: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A4278: bne         $t7, $at, L_800A4290
    if (ctx->r15 != ctx->r1) {
        // 0x800A427C: nop
    
            goto L_800A4290;
    }
    // 0x800A427C: nop

    // 0x800A4280: jal         0x8007C36C
    // 0x800A4284: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_1;
    // 0x800A4284: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800A4288: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800A428C: nop

L_800A4290:
    // 0x800A4290: blez        $t1, L_800A44A0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800A4294: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800A44A0;
    }
    // 0x800A4294: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A4298: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A429C: lbu         $t8, 0x72F4($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X72F4);
    // 0x800A42A0: sll         $t3, $t1, 8
    ctx->r11 = S32(ctx->r9 << 8);
    // 0x800A42A4: beq         $t8, $zero, L_800A4364
    if (ctx->r24 == 0) {
        // 0x800A42A8: subu        $t3, $t3, $t1
        ctx->r11 = SUB32(ctx->r11, ctx->r9);
            goto L_800A4364;
    }
    // 0x800A42A8: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x800A42AC: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x800A42B0: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x800A42B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A42B8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A42BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A42C0: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800A42C4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800A42C8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800A42CC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A42D0: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800A42D4: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A42D8: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800A42DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A42E0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A42E4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A42E8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A42EC: mflo        $t4
    ctx->r12 = lo;
    // 0x800A42F0: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800A42F4: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800A42F8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A42FC: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A4300: jal         0x800AAB5C
    // 0x800A4304: addiu       $a3, $a3, 0x1A0
    ctx->r7 = ADD32(ctx->r7, 0X1A0);
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A4304: addiu       $a3, $a3, 0x1A0
    ctx->r7 = ADD32(ctx->r7, 0X1A0);
    after_2:
    // 0x800A4308: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A430C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4310: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A4314: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800A4318: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A431C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A4320: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800A4324: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A4328: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A432C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A4330: lb          $t2, 0x7294($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X7294);
    // 0x800A4334: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A4338: bne         $t2, $at, L_800A4364
    if (ctx->r10 != ctx->r1) {
        // 0x800A433C: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_800A4364;
    }
    // 0x800A433C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800A4340: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4344: jal         0x80001D04
    // 0x800A4348: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800A4348: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    after_3:
    // 0x800A434C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A4350: addiu       $v0, $v0, 0x7294
    ctx->r2 = ADD32(ctx->r2, 0X7294);
    // 0x800A4354: lb          $t3, 0x0($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X0);
    // 0x800A4358: nop

    // 0x800A435C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800A4360: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
L_800A4364:
    // 0x800A4364: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A4368: lw          $t5, 0x72FC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72FC);
    // 0x800A436C: nop

    // 0x800A4370: bne         $t5, $zero, L_800A4684
    if (ctx->r13 != 0) {
        // 0x800A4374: nop
    
            goto L_800A4684;
    }
    // 0x800A4374: nop

    // 0x800A4378: jal         0x8002359C
    // 0x800A437C: nop

    func_80023568(rdram, ctx);
        goto after_4;
    // 0x800A437C: nop

    after_4:
    // 0x800A4380: bne         $v0, $zero, L_800A4684
    if (ctx->r2 != 0) {
        // 0x800A4384: nop
    
            goto L_800A4684;
    }
    // 0x800A4384: nop

    // 0x800A4388: jal         0x8001BAA8
    // 0x800A438C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    get_racer_objects(rdram, ctx);
        goto after_5;
    // 0x800A438C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_5:
    // 0x800A4390: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800A4394: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x800A4398: jal         0x8006FB8C
    // 0x800A439C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    rand_range(rdram, ctx);
        goto after_6;
    // 0x800A439C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x800A43A0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800A43A4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800A43A8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A43AC: lw          $t0, -0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, -0X4);
    // 0x800A43B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A43B4: lw          $v1, 0x64($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X64);
    // 0x800A43B8: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x800A43BC: lb          $t9, 0x1D6($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X1D6);
    // 0x800A43C0: nop

    // 0x800A43C4: bne         $t9, $zero, L_800A4684
    if (ctx->r25 != 0) {
        // 0x800A43C8: nop
    
            goto L_800A4684;
    }
    // 0x800A43C8: nop

    // 0x800A43CC: jal         0x8006FB8C
    // 0x800A43D0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    rand_range(rdram, ctx);
        goto after_7;
    // 0x800A43D0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_7:
    // 0x800A43D4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A43D8: slti        $at, $v0, 0x60
    ctx->r1 = SIGNED(ctx->r2) < 0X60 ? 1 : 0;
    // 0x800A43DC: bne         $at, $zero, L_800A4684
    if (ctx->r1 != 0) {
        // 0x800A43E0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800A4684;
    }
    // 0x800A43E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A43E4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800A43E8: jal         0x8006FB8C
    // 0x800A43EC: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    rand_range(rdram, ctx);
        goto after_8;
    // 0x800A43EC: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_8:
    // 0x800A43F0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800A43F4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A43F8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800A43FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A4400: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A4404: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x800A4408: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800A440C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A4410: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A4414: lui         $at, 0x3FF4
    ctx->r1 = S32(0X3FF4 << 16);
    // 0x800A4418: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A441C: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x800A4420: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A4424: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A4428: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800A442C: sub.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d - ctx->f18.d;
    // 0x800A4430: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800A4434: jal         0x8006FB8C
    // 0x800A4438: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    rand_range(rdram, ctx);
        goto after_9;
    // 0x800A4438: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x800A443C: sll         $t3, $v0, 6
    ctx->r11 = S32(ctx->r2 << 6);
    // 0x800A4440: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x800A4444: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800A4448: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x800A444C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A4450: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A4454: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A4458: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800A445C: lw          $a1, 0xC($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XC);
    // 0x800A4460: lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X10);
    // 0x800A4464: lw          $a3, 0x14($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X14);
    // 0x800A4468: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A446C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A4470: addiu       $t6, $t6, 0x72FC
    ctx->r14 = ADD32(ctx->r14, 0X72FC);
    // 0x800A4474: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x800A4478: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A447C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800A4480: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800A4484: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x800A4488: mflo        $t4
    ctx->r12 = lo;
    // 0x800A448C: addiu       $t5, $t4, 0x18
    ctx->r13 = ADD32(ctx->r12, 0X18);
    // 0x800A4490: jal         0x800095E8
    // 0x800A4494: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    audspat_play_sound_direct(rdram, ctx);
        goto after_10;
    // 0x800A4494: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_10:
    // 0x800A4498: b           L_800A4684
    // 0x800A449C: nop

        goto L_800A4684;
    // 0x800A449C: nop

L_800A44A0:
    // 0x800A44A0: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A44A4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A44A8: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A44AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A44B0: lwc1        $f6, 0x18C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X18C);
    // 0x800A44B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A44B8: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800A44BC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A44C0: bc1f        L_800A4684
    if (!c1cs) {
        // 0x800A44C4: lui         $t9, 0xFA00
        ctx->r25 = S32(0XFA00 << 16);
            goto L_800A4684;
    }
    // 0x800A44C4: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800A44C8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A44CC: addiu       $t2, $zero, -0x60
    ctx->r10 = ADD32(0, -0X60);
    // 0x800A44D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800A44D4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800A44D8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800A44DC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A44E0: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A44E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A44E8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A44EC: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A44F0: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A44F4: jal         0x800AAB5C
    // 0x800A44F8: addiu       $a3, $a3, 0x180
    ctx->r7 = ADD32(ctx->r7, 0X180);
    hud_element_render(rdram, ctx);
        goto after_11;
    // 0x800A44F8: addiu       $a3, $a3, 0x180
    ctx->r7 = ADD32(ctx->r7, 0X180);
    after_11:
    // 0x800A44FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4500: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4504: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A4508: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800A450C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800A4510: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800A4514: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800A4518: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A451C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A4520: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800A4524: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800A4528: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A452C: addiu       $a3, $a3, 0x72C8
    ctx->r7 = ADD32(ctx->r7, 0X72C8);
    // 0x800A4530: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800A4534: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A4538: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800A453C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800A4540: lb          $t8, 0x19A($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X19A);
    // 0x800A4544: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A4548: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x800A454C: sb          $t2, 0x19A($a1)
    MEM_B(0X19A, ctx->r5) = ctx->r10;
    // 0x800A4550: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800A4554: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x800A4558: nop

    // 0x800A455C: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x800A4560: lb          $t5, 0x19A($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X19A);
    // 0x800A4564: nop

    // 0x800A4568: slti        $at, $t5, 0x3C
    ctx->r1 = SIGNED(ctx->r13) < 0X3C ? 1 : 0;
    // 0x800A456C: bne         $at, $zero, L_800A4604
    if (ctx->r1 != 0) {
        // 0x800A4570: nop
    
            goto L_800A4604;
    }
    // 0x800A4570: nop

    // 0x800A4574: lb          $t6, 0x7294($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X7294);
    // 0x800A4578: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A457C: bne         $t6, $at, L_800A45E8
    if (ctx->r14 != ctx->r1) {
        // 0x800A4580: lw          $t9, 0x5C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X5C);
            goto L_800A45E8;
    }
    // 0x800A4580: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800A4584: jal         0x80066450
    // 0x800A4588: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_12;
    // 0x800A4588: nop

    after_12:
    // 0x800A458C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800A4590: bne         $at, $zero, L_800A45AC
    if (ctx->r1 != 0) {
        // 0x800A4594: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800A45AC;
    }
    // 0x800A4594: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A4598: jal         0x80000B34
    // 0x800A459C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    music_play(rdram, ctx);
        goto after_13;
    // 0x800A459C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x800A45A0: b           L_800A45BC
    // 0x800A45A4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
        goto L_800A45BC;
    // 0x800A45A4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A45A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800A45AC:
    // 0x800A45AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A45B0: jal         0x8006BF50
    // 0x800A45B4: nop

    level_music_start(rdram, ctx);
        goto after_14;
    // 0x800A45B4: nop

    after_14:
    // 0x800A45B8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
L_800A45BC:
    // 0x800A45BC: jal         0x80001D04
    // 0x800A45C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_15;
    // 0x800A45C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x800A45C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A45C8: addiu       $v0, $v0, 0x7294
    ctx->r2 = ADD32(ctx->r2, 0X7294);
    // 0x800A45CC: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x800A45D0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A45D4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800A45D8: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800A45DC: lw          $a2, 0x729C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X729C);
    // 0x800A45E0: nop

    // 0x800A45E4: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
L_800A45E8:
    // 0x800A45E8: lwc1        $f8, 0x18C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18C);
    // 0x800A45EC: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x800A45F0: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800A45F4: nop

    // 0x800A45F8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A45FC: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800A4600: swc1        $f4, 0x18C($a2)
    MEM_W(0X18C, ctx->r6) = ctx->f4.u32l;
L_800A4604:
    // 0x800A4604: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A4608: lb          $t3, 0x7294($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X7294);
    // 0x800A460C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A4610: bne         $t3, $at, L_800A4684
    if (ctx->r11 != ctx->r1) {
        // 0x800A4614: addiu       $a0, $zero, 0x19
        ctx->r4 = ADD32(0, 0X19);
            goto L_800A4684;
    }
    // 0x800A4614: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x800A4618: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A461C: jal         0x80001D04
    // 0x800A4620: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    sound_play(rdram, ctx);
        goto after_16;
    // 0x800A4620: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    after_16:
    // 0x800A4624: jal         0x8001B674
    // 0x800A4628: nop

    timetrial_ghost_staff(rdram, ctx);
        goto after_17;
    // 0x800A4628: nop

    after_17:
    // 0x800A462C: beq         $v0, $zero, L_800A4664
    if (ctx->r2 == 0) {
        // 0x800A4630: nop
    
            goto L_800A4664;
    }
    // 0x800A4630: nop

    // 0x800A4634: jal         0x8001B684
    // 0x800A4638: nop

    timetrial_staff_unbeaten(rdram, ctx);
        goto after_18;
    // 0x800A4638: nop

    after_18:
    // 0x800A463C: bne         $v0, $zero, L_800A4664
    if (ctx->r2 != 0) {
        // 0x800A4640: addiu       $a0, $zero, 0x24B
        ctx->r4 = ADD32(0, 0X24B);
            goto L_800A4664;
    }
    // 0x800A4640: addiu       $a0, $zero, 0x24B
    ctx->r4 = ADD32(0, 0X24B);
    // 0x800A4644: lui         $a1, 0x3FD9
    ctx->r5 = S32(0X3FD9 << 16);
    // 0x800A4648: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x800A464C: jal         0x800A79E0
    // 0x800A4650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    hud_sound_play_delayed(rdram, ctx);
        goto after_19;
    // 0x800A4650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x800A4654: lui         $a1, 0x3FD9
    ctx->r5 = S32(0X3FD9 << 16);
    // 0x800A4658: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x800A465C: jal         0x800C36B0
    // 0x800A4660: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    set_delayed_text(rdram, ctx);
        goto after_20;
    // 0x800A4660: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    after_20:
L_800A4664:
    // 0x800A4664: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A4668: lb          $t5, 0x7294($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X7294);
    // 0x800A466C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A4670: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A4674: sb          $t4, 0x7330($at)
    MEM_B(0X7330, ctx->r1) = ctx->r12;
    // 0x800A4678: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A467C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800A4680: sb          $t6, 0x7294($at)
    MEM_B(0X7294, ctx->r1) = ctx->r14;
L_800A4684:
    // 0x800A4684: jal         0x8007C36C
    // 0x800A4688: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_21;
    // 0x800A4688: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_21:
L_800A468C:
    // 0x800A468C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A4690: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800A4694: jr          $ra
    // 0x800A4698: nop

    return;
    // 0x800A4698: nop

;}
RECOMP_FUNC void alResamplePull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC6DC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800CC6E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CC6E4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800CC6E8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800CC6EC: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x800CC6F0: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800CC6F4: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x800CC6F8: bne         $a2, $zero, L_800CC708
    if (ctx->r6 != 0) {
        // 0x800CC6FC: sh          $t6, 0x46($sp)
        MEM_H(0X46, ctx->r29) = ctx->r14;
            goto L_800CC708;
    }
    // 0x800CC6FC: sh          $t6, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r14;
    // 0x800CC700: b           L_800CC8D4
    // 0x800CC704: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
        goto L_800CC8D4;
    // 0x800CC704: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
L_800CC708:
    // 0x800CC708: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x800CC70C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800CC710: beql        $t7, $zero, L_800CC77C
    if (ctx->r15 == 0) {
        // 0x800CC714: lwc1        $f2, 0x18($t0)
        ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
            goto L_800CC77C;
    }
    goto skip_0;
    // 0x800CC714: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    skip_0:
    // 0x800CC718: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800CC71C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800CC720: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800CC724: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CC728: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800CC72C: jalr        $t9
    // 0x800CC730: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CC730: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_0:
    // 0x800CC734: lh          $t3, 0x46($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X46);
    // 0x800CC738: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CC73C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC740: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800CC744: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800CC748: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CC74C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800CC750: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800CC754: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800CC758: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800CC75C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800CC760: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x800CC764: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800CC768: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800CC76C: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x800CC770: b           L_800CC8D0
    // 0x800CC774: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_800CC8D0;
    // 0x800CC774: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800CC778: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
L_800CC77C:
    // 0x800CC77C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CC780: ldc1        $f4, -0x6458($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X6458);
    // 0x800CC784: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800CC788: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CC78C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x800CC790: nop

    // 0x800CC794: bc1fl       L_800CC7AC
    if (!c1cs) {
        // 0x800CC798: lui         $at, 0x4700
        ctx->r1 = S32(0X4700 << 16);
            goto L_800CC7AC;
    }
    goto skip_1;
    // 0x800CC798: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    skip_1:
    // 0x800CC79C: lwc1        $f8, -0x6450($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6450);
    // 0x800CC7A0: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x800CC7A4: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800CC7A8: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
L_800CC7AC:
    // 0x800CC7AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800CC7B0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CC7B4: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800CC7B8: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800CC7BC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CC7C0: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800CC7C4: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800CC7C8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800CC7CC: nop

    // 0x800CC7D0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CC7D4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800CC7D8: swc1        $f4, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f4.u32l;
    // 0x800CC7DC: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800CC7E0: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800CC7E4: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x800CC7E8: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x800CC7EC: lwc1        $f10, 0x18($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800CC7F0: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800CC7F4: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800CC7F8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800CC7FC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800CC800: nop

    // 0x800CC804: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800CC808: nop

    // 0x800CC80C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800CC810: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800CC814: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    // 0x800CC818: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x800CC81C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800CC820: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800CC824: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800CC828: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800CC82C: jalr        $t9
    // 0x800CC830: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CC830: nop

    after_1:
    // 0x800CC834: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800CC838: lh          $t5, 0x46($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X46);
    // 0x800CC83C: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800CC840: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CC844: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800CC848: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CC84C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800CC850: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CC854: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CC858: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CC85C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800CC860: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800CC864: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x800CC868: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800CC86C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800CC870: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800CC874: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x800CC878: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800CC87C: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CC880: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800CC884: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800CC888: lw          $t3, 0x24($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X24);
    // 0x800CC88C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800CC890: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800CC894: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x800CC898: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x800CC89C: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x800CC8A0: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800CC8A4: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800CC8A8: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800CC8AC: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x800CC8B0: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x800CC8B4: jal         0x800C9250
    // 0x800CC8B8: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800CC8B8: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_2:
    // 0x800CC8BC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800CC8C0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800CC8C4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800CC8C8: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x800CC8CC: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
L_800CC8D0:
    // 0x800CC8D0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800CC8D4:
    // 0x800CC8D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC8D8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800CC8DC: jr          $ra
    // 0x800CC8E0: nop

    return;
    // 0x800CC8E0: nop

;}
RECOMP_FUNC void populate_settings_from_save_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800732C4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800732C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800732CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800732D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800732D4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800732D8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800732DC: jal         0x8006EBD4
    // 0x800732E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    clear_game_progress(rdram, ctx);
        goto after_0;
    // 0x800732E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800732E4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800732E8: jal         0x8006B464
    // 0x800732EC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    level_count(rdram, ctx);
        goto after_1;
    // 0x800732EC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x800732F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800732F4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800732F8: sw          $s1, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r17;
    // 0x800732FC: addiu       $v0, $v0, 0x4774
    ctx->r2 = ADD32(ctx->r2, 0X4774);
    // 0x80073300: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80073304: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073308: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x8007330C: jal         0x80072EAC
    // 0x80073310: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072C54(rdram, ctx);
        goto after_2;
    // 0x80073310: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_2:
    // 0x80073314: addiu       $a0, $v0, -0x5
    ctx->r4 = ADD32(ctx->r2, -0X5);
    // 0x80073318: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8007331C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80073320: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80073324: addiu       $v1, $s1, 0x2
    ctx->r3 = ADD32(ctx->r17, 0X2);
L_80073328:
    // 0x80073328: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8007332C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80073330: subu        $a0, $a0, $t9
    ctx->r4 = SUB32(ctx->r4, ctx->r25);
    // 0x80073334: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x80073338: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8007333C: slti        $at, $s0, 0x28
    ctx->r1 = SIGNED(ctx->r16) < 0X28 ? 1 : 0;
    // 0x80073340: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80073344: bne         $at, $zero, L_80073328
    if (ctx->r1 != 0) {
        // 0x80073348: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80073328;
    }
    // 0x80073348: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007334C: bne         $t1, $zero, L_8007352C
    if (ctx->r9 != 0) {
        // 0x80073350: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007352C;
    }
    // 0x80073350: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80073354: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80073358: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007335C: blez        $t2, L_80073418
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80073360: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80073418;
    }
    // 0x80073360: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80073364:
    // 0x80073364: jal         0x8006B38C
    // 0x80073368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_type(rdram, ctx);
        goto after_3;
    // 0x80073368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8007336C: beq         $v0, $zero, L_80073384
    if (ctx->r2 == 0) {
        // 0x80073370: andi        $t3, $v0, 0x40
        ctx->r11 = ctx->r2 & 0X40;
            goto L_80073384;
    }
    // 0x80073370: andi        $t3, $v0, 0x40
    ctx->r11 = ctx->r2 & 0X40;
    // 0x80073374: bne         $t3, $zero, L_80073384
    if (ctx->r11 != 0) {
        // 0x80073378: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80073384;
    }
    // 0x80073378: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8007337C: bne         $v0, $at, L_80073404
    if (ctx->r2 != ctx->r1) {
        // 0x80073380: lw          $t6, 0x48($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X48);
            goto L_80073404;
    }
    // 0x80073380: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
L_80073384:
    // 0x80073384: jal         0x80072EAC
    // 0x80073388: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80072C54(rdram, ctx);
        goto after_4;
    // 0x80073388: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x8007338C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80073390: blez        $v1, L_800733B4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80073394: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800733B4;
    }
    // 0x80073394: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80073398: lw          $t4, 0x4($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X4);
    // 0x8007339C: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x800733A0: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x800733A4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800733A8: nop

    // 0x800733AC: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800733B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800733B4:
    // 0x800733B4: bne         $at, $zero, L_800733D8
    if (ctx->r1 != 0) {
        // 0x800733B8: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_800733D8;
    }
    // 0x800733B8: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800733BC: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    // 0x800733C0: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x800733C4: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800733C8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800733CC: nop

    // 0x800733D0: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x800733D4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_800733D8:
    // 0x800733D8: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800733DC: bne         $at, $zero, L_80073400
    if (ctx->r1 != 0) {
        // 0x800733E0: nop
    
            goto L_80073400;
    }
    // 0x800733E0: nop

    // 0x800733E4: lw          $t2, 0x4($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X4);
    // 0x800733E8: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x800733EC: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x800733F0: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800733F4: nop

    // 0x800733F8: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x800733FC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80073400:
    // 0x80073400: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
L_80073404:
    // 0x80073404: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80073408: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007340C: bne         $at, $zero, L_80073364
    if (ctx->r1 != 0) {
        // 0x80073410: nop
    
            goto L_80073364;
    }
    // 0x80073410: nop

    // 0x80073414: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80073418:
    // 0x80073418: addiu       $t7, $zero, 0x44
    ctx->r15 = ADD32(0, 0X44);
    // 0x8007341C: jal         0x80072EAC
    // 0x80073420: subu        $a0, $t7, $s1
    ctx->r4 = SUB32(ctx->r15, ctx->r17);
    func_80072C54(rdram, ctx);
        goto after_5;
    // 0x80073420: subu        $a0, $t7, $s1
    ctx->r4 = SUB32(ctx->r15, ctx->r17);
    after_5:
    // 0x80073424: jal         0x80072EAC
    // 0x80073428: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80072C54(rdram, ctx);
        goto after_6;
    // 0x80073428: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_6:
    // 0x8007342C: sh          $v0, 0x14($s2)
    MEM_H(0X14, ctx->r18) = ctx->r2;
    // 0x80073430: jal         0x80072EAC
    // 0x80073434: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_80072C54(rdram, ctx);
        goto after_7;
    // 0x80073434: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_7:
    // 0x80073438: sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
    // 0x8007343C: jal         0x80072EAC
    // 0x80073440: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80072C54(rdram, ctx);
        goto after_8;
    // 0x80073440: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_8:
    // 0x80073444: sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // 0x80073448: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8007344C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80073450: blez        $t8, L_8007348C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80073454: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8007348C;
    }
    // 0x80073454: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
L_80073458:
    // 0x80073458: jal         0x80072EAC
    // 0x8007345C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80072C54(rdram, ctx);
        goto after_9;
    // 0x8007345C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_9:
    // 0x80073460: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80073464: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80073468: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007346C: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x80073470: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    // 0x80073474: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80073478: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8007347C: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80073480: bne         $at, $zero, L_80073458
    if (ctx->r1 != 0) {
        // 0x80073484: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80073458;
    }
    // 0x80073484: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80073488: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007348C:
    // 0x8007348C: jal         0x80072EAC
    // 0x80073490: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80072C54(rdram, ctx);
        goto after_10;
    // 0x80073490: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_10:
    // 0x80073494: sb          $v0, 0x16($s2)
    MEM_B(0X16, ctx->r18) = ctx->r2;
    // 0x80073498: jal         0x80072EAC
    // 0x8007349C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80072C54(rdram, ctx);
        goto after_11;
    // 0x8007349C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_11:
    // 0x800734A0: sb          $v0, 0x17($s2)
    MEM_B(0X17, ctx->r18) = ctx->r2;
    // 0x800734A4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800734A8: nop

    // 0x800734AC: blez        $t2, L_800734F8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800734B0: nop
    
            goto L_800734F8;
    }
    // 0x800734B0: nop

L_800734B4:
    // 0x800734B4: jal         0x80072EAC
    // 0x800734B8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072C54(rdram, ctx);
        goto after_12;
    // 0x800734B8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_12:
    // 0x800734BC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800734C0: jal         0x8006B414
    // 0x800734C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    level_world_id(rdram, ctx);
        goto after_13;
    // 0x800734C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800734C8: lw          $t3, 0x4($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X4);
    // 0x800734CC: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800734D0: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x800734D4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800734D8: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x800734DC: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x800734E0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800734E4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800734E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800734EC: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800734F0: bne         $at, $zero, L_800734B4
    if (ctx->r1 != 0) {
        // 0x800734F4: nop
    
            goto L_800734B4;
    }
    // 0x800734F4: nop

L_800734F8:
    // 0x800734F8: jal         0x80072EAC
    // 0x800734FC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_80072C54(rdram, ctx);
        goto after_14;
    // 0x800734FC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_14:
    // 0x80073500: sh          $v0, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r2;
    // 0x80073504: jal         0x80072EAC
    // 0x80073508: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80072C54(rdram, ctx);
        goto after_15;
    // 0x80073508: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_15:
    // 0x8007350C: sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // 0x80073510: jal         0x80072EAC
    // 0x80073514: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072C54(rdram, ctx);
        goto after_16;
    // 0x80073514: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_16:
    // 0x80073518: sw          $v0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->r2;
    // 0x8007351C: jal         0x80072EAC
    // 0x80073520: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_80072C54(rdram, ctx);
        goto after_17;
    // 0x80073520: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_17:
    // 0x80073524: sb          $zero, 0x4B($s2)
    MEM_B(0X4B, ctx->r18) = 0;
    // 0x80073528: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007352C:
    // 0x8007352C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80073530: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80073534: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80073538: jr          $ra
    // 0x8007353C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007353C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void free_all_objects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C604: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000C608: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000C60C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000C610: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000C614: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000C618: jal         0x80059B9C
    // 0x8000C61C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    timetrial_free_staff_ghost(rdram, ctx);
        goto after_0;
    // 0x8000C61C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x8000C620: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000C624: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000C628: addiu       $s0, $s0, -0x3374
    ctx->r16 = ADD32(ctx->r16, -0X3374);
    // 0x8000C62C: sb          $zero, -0x3348($at)
    MEM_B(-0X3348, ctx->r1) = 0;
    // 0x8000C630: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
    // 0x8000C634: nop

    // 0x8000C638: beq         $t6, $zero, L_8000C648
    if (ctx->r14 == 0) {
        // 0x8000C63C: nop
    
            goto L_8000C648;
    }
    // 0x8000C63C: nop

    // 0x8000C640: jal         0x800724E4
    // 0x8000C644: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    rumble_init(rdram, ctx);
        goto after_1;
    // 0x8000C644: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_8000C648:
    // 0x8000C648: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8000C64C: addiu       $s1, $s1, -0x334C
    ctx->r17 = ADD32(ctx->r17, -0X334C);
    // 0x8000C650: lb          $t7, 0x0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X0);
    // 0x8000C654: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8000C658: beq         $t7, $zero, L_8000C678
    if (ctx->r15 == 0) {
        // 0x8000C65C: nop
    
            goto L_8000C678;
    }
    // 0x8000C65C: nop

    // 0x8000C660: jal         0x8009F1C4
    // 0x8000C664: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_2;
    // 0x8000C664: nop

    after_2:
    // 0x8000C668: beq         $v0, $zero, L_8000C678
    if (ctx->r2 == 0) {
        // 0x8000C66C: nop
    
            goto L_8000C678;
    }
    // 0x8000C66C: nop

    // 0x8000C670: jal         0x8006F5D8
    // 0x8000C674: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    swap_lead_player(rdram, ctx);
        goto after_3;
    // 0x8000C674: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    after_3:
L_8000C678:
    // 0x8000C678: jal         0x8001004C
    // 0x8000C67C: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_4;
    // 0x8000C67C: nop

    after_4:
    // 0x8000C680: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8000C684: lw          $s2, -0x4C24($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X4C24);
    // 0x8000C688: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000C68C: blez        $s2, L_8000C6C0
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8000C690: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000C6C0;
    }
    // 0x8000C690: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000C694: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8000C698: addiu       $s3, $s3, -0x4C28
    ctx->r19 = ADD32(ctx->r19, -0X4C28);
L_8000C69C:
    // 0x8000C69C: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8000C6A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000C6A4: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x8000C6A8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8000C6AC: jal         0x800101AC
    // 0x8000C6B0: nop

    obj_destroy(rdram, ctx);
        goto after_5;
    // 0x8000C6B0: nop

    after_5:
    // 0x8000C6B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000C6B8: bne         $s0, $s2, L_8000C69C
    if (ctx->r16 != ctx->r18) {
        // 0x8000C6BC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000C69C;
    }
    // 0x8000C6BC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8000C6C0:
    // 0x8000C6C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C6C4: sw          $zero, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = 0;
    // 0x8000C6C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C6CC: sw          $zero, -0x4C24($at)
    MEM_W(-0X4C24, ctx->r1) = 0;
    // 0x8000C6D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C6D4: jal         0x8000C460
    // 0x8000C6D8: sw          $zero, -0x4C20($at)
    MEM_W(-0X4C20, ctx->r1) = 0;
    clear_object_pointers(rdram, ctx);
        goto after_6;
    // 0x8000C6D8: sw          $zero, -0x4C20($at)
    MEM_W(-0X4C20, ctx->r1) = 0;
    after_6:
    // 0x8000C6DC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000C6E0: addiu       $s0, $s0, -0x4BD0
    ctx->r16 = ADD32(ctx->r16, -0X4BD0);
    // 0x8000C6E4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000C6E8: jal         0x80071380
    // 0x8000C6EC: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x8000C6EC: nop

    after_7:
    // 0x8000C6F0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8000C6F4: jal         0x80071380
    // 0x8000C6F8: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x8000C6F8: nop

    after_8:
    // 0x8000C6FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000C700: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000C704: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000C708: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C70C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000C710: jr          $ra
    // 0x8000C714: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000C714: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void transition_fullscreen_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0CA0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800C0CA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0CA8: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x800C0CAC: beq         $t7, $zero, L_800C0D04
    if (ctx->r15 == 0) {
        // 0x800C0CB0: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800C0D04;
    }
    // 0x800C0CB0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C0CB4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C0CB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C0CBC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C0CC0: lhu         $t8, 0x3740($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X3740);
    // 0x800C0CC4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0CC8: swc1        $f4, -0x52F0($at)
    MEM_W(-0X52F0, ctx->r1) = ctx->f4.u32l;
    // 0x800C0CCC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800C0CD0: lui         $at, 0xC37F
    ctx->r1 = S32(0XC37F << 16);
    // 0x800C0CD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C0CD8: bgez        $t8, L_800C0CF0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800C0CDC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800C0CF0;
    }
    // 0x800C0CDC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C0CE0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C0CE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C0CE8: nop

    // 0x800C0CEC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800C0CF0:
    // 0x800C0CF0: nop

    // 0x800C0CF4: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C0CF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0CFC: b           L_800C0D48
    // 0x800C0D00: swc1        $f18, -0x52EC($at)
    MEM_W(-0X52EC, ctx->r1) = ctx->f18.u32l;
        goto L_800C0D48;
    // 0x800C0D00: swc1        $f18, -0x52EC($at)
    MEM_W(-0X52EC, ctx->r1) = ctx->f18.u32l;
L_800C0D04:
    // 0x800C0D04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C0D08: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C0D0C: lhu         $t9, 0x3740($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X3740);
    // 0x800C0D10: swc1        $f4, -0x52F0($at)
    MEM_W(-0X52F0, ctx->r1) = ctx->f4.u32l;
    // 0x800C0D14: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800C0D18: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C0D1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C0D20: bgez        $t9, L_800C0D38
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800C0D24: cvt.s.w     $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800C0D38;
    }
    // 0x800C0D24: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C0D28: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C0D2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C0D30: nop

    // 0x800C0D34: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800C0D38:
    // 0x800C0D38: nop

    // 0x800C0D3C: div.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800C0D40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0D44: swc1        $f18, -0x52EC($at)
    MEM_W(-0X52EC, ctx->r1) = ctx->f18.u32l;
L_800C0D48:
    // 0x800C0D48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0D4C: jr          $ra
    // 0x800C0D50: sw          $t0, 0x373C($at)
    MEM_W(0X373C, ctx->r1) = ctx->r8;
    return;
    // 0x800C0D50: sw          $t0, 0x373C($at)
    MEM_W(0X373C, ctx->r1) = ctx->r8;
;}
RECOMP_FUNC void racer_sound_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007F78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80007F7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007F80: jr          $ra
    // 0x80007F84: sb          $t6, -0x33C0($at)
    MEM_B(-0X33C0, ctx->r1) = ctx->r14;
    return;
    // 0x80007F84: sb          $t6, -0x33C0($at)
    MEM_B(-0X33C0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void menu_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E9A4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8008E9A8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008E9AC: lw          $t6, 0x6964($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6964);
    // 0x8008E9B0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008E9B4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8008E9B8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8008E9BC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008E9C0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008E9C4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008E9C8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008E9CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008E9D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008E9D4: bne         $t6, $zero, L_8008EB74
    if (ctx->r14 != 0) {
        // 0x8008E9D8: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8008EB74;
    }
    // 0x8008E9D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008E9DC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008E9E0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008E9E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008E9E8: addiu       $v0, $v0, 0x6DDA
    ctx->r2 = ADD32(ctx->r2, 0X6DDA);
    // 0x8008E9EC: addiu       $s1, $s1, 0x6DD0
    ctx->r17 = ADD32(ctx->r17, 0X6DD0);
    // 0x8008E9F0: addiu       $s2, $s2, 0x6DB8
    ctx->r18 = ADD32(ctx->r18, 0X6DB8);
    // 0x8008E9F4: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
L_8008E9F8:
    // 0x8008E9F8: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8008E9FC: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x8008EA00: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8008EA04: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8008EA08: sw          $zero, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = 0;
    // 0x8008EA0C: sh          $zero, -0x2($s2)
    MEM_H(-0X2, ctx->r18) = 0;
    // 0x8008EA10: bne         $at, $zero, L_8008E9F8
    if (ctx->r1 != 0) {
        // 0x8008EA14: sh          $zero, -0x2($s1)
        MEM_H(-0X2, ctx->r17) = 0;
            goto L_8008E9F8;
    }
    // 0x8008EA14: sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
    // 0x8008EA18: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008EA1C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008EA20: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008EA24: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8008EA28: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8008EA2C: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008EA30: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008EA34: addiu       $s6, $s6, 0x6DB8
    ctx->r22 = ADD32(ctx->r22, 0X6DB8);
    // 0x8008EA38: addiu       $s7, $s7, 0x6DD0
    ctx->r23 = ADD32(ctx->r23, 0X6DD0);
    // 0x8008EA3C: addiu       $fp, $fp, -0x5C4
    ctx->r30 = ADD32(ctx->r30, -0X5C4);
    // 0x8008EA40: addiu       $s5, $s5, 0x6A04
    ctx->r21 = ADD32(ctx->r21, 0X6A04);
    // 0x8008EA44: addiu       $s4, $s4, 0x69FC
    ctx->r20 = ADD32(ctx->r20, 0X69FC);
    // 0x8008EA48: addiu       $s1, $s1, 0x6DD0
    ctx->r17 = ADD32(ctx->r17, 0X6DD0);
    // 0x8008EA4C: addiu       $s2, $s2, 0x6DB8
    ctx->r18 = ADD32(ctx->r18, 0X6DB8);
    // 0x8008EA50: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8008EA54: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
L_8008EA58:
    // 0x8008EA58: jal         0x8006A768
    // 0x8008EA5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    input_held(rdram, ctx);
        goto after_0;
    // 0x8008EA5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x8008EA60: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x8008EA64: lb          $v1, 0x0($s4)
    ctx->r3 = MEM_B(ctx->r20, 0X0);
    // 0x8008EA68: lb          $a0, 0x0($s5)
    ctx->r4 = MEM_B(ctx->r21, 0X0);
    // 0x8008EA6C: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8008EA70: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8008EA74: sh          $v1, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r3;
    // 0x8008EA78: beq         $at, $zero, L_8008EAA4
    if (ctx->r1 == 0) {
        // 0x8008EA7C: sh          $a0, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r4;
            goto L_8008EAA4;
    }
    // 0x8008EA7C: sh          $a0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r4;
    // 0x8008EA80: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8008EA84: lh          $t2, 0x8($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X8);
    // 0x8008EA88: lh          $t4, 0x8($s7)
    ctx->r12 = MEM_H(ctx->r23, 0X8);
    // 0x8008EA8C: or          $t1, $t8, $v0
    ctx->r9 = ctx->r24 | ctx->r2;
    // 0x8008EA90: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8008EA94: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x8008EA98: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    // 0x8008EA9C: sh          $t3, 0x8($s6)
    MEM_H(0X8, ctx->r22) = ctx->r11;
    // 0x8008EAA0: sh          $t5, 0x8($s7)
    MEM_H(0X8, ctx->r23) = ctx->r13;
L_8008EAA4:
    // 0x8008EAA4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8008EAA8: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8008EAAC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8008EAB0: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8008EAB4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8008EAB8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8008EABC: bne         $at, $zero, L_8008EA58
    if (ctx->r1 != 0) {
        // 0x8008EAC0: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8008EA58;
    }
    // 0x8008EAC0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8008EAC4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008EAC8: lw          $t6, 0x6D90($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D90);
    // 0x8008EACC: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x8008EAD0: nor         $t7, $t6, $zero
    ctx->r15 = ~(ctx->r14 | 0);
    // 0x8008EAD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EAD8: and         $t8, $t7, $v0
    ctx->r24 = ctx->r15 & ctx->r2;
    // 0x8008EADC: sw          $t8, 0x6D78($at)
    MEM_W(0X6D78, ctx->r1) = ctx->r24;
    // 0x8008EAE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EAE4: sw          $v0, 0x6D90($at)
    MEM_W(0X6D90, ctx->r1) = ctx->r2;
    // 0x8008EAE8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008EAEC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008EAF0: addiu       $t1, $t1, 0x6D90
    ctx->r9 = ADD32(ctx->r9, 0X6D90);
    // 0x8008EAF4: sll         $a0, $s3, 2
    ctx->r4 = S32(ctx->r19 << 2);
    // 0x8008EAF8: addu        $v0, $a0, $t1
    ctx->r2 = ADD32(ctx->r4, ctx->r9);
    // 0x8008EAFC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8008EB00: addiu       $t2, $sp, 0x60
    ctx->r10 = ADD32(ctx->r29, 0X60);
    // 0x8008EB04: addu        $s0, $a0, $t2
    ctx->r16 = ADD32(ctx->r4, ctx->r10);
    // 0x8008EB08: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008EB0C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8008EB10: addiu       $t9, $t9, 0x6D78
    ctx->r25 = ADD32(ctx->r25, 0X6D78);
    // 0x8008EB14: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x8008EB18: addu        $v1, $a0, $t9
    ctx->r3 = ADD32(ctx->r4, ctx->r25);
    // 0x8008EB1C: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8008EB20: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8008EB24: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8008EB28: and         $t5, $t4, $a1
    ctx->r13 = ctx->r12 & ctx->r5;
    // 0x8008EB2C: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8008EB30: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8008EB34: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x8008EB38: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8008EB3C: nor         $t1, $t9, $zero
    ctx->r9 = ~(ctx->r25 | 0);
    // 0x8008EB40: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x8008EB44: nor         $t7, $t6, $zero
    ctx->r15 = ~(ctx->r14 | 0);
    // 0x8008EB48: and         $t8, $t7, $a2
    ctx->r24 = ctx->r15 & ctx->r6;
    // 0x8008EB4C: and         $t2, $t1, $a3
    ctx->r10 = ctx->r9 & ctx->r7;
    // 0x8008EB50: and         $t5, $t4, $t0
    ctx->r13 = ctx->r12 & ctx->r8;
    // 0x8008EB54: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x8008EB58: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8008EB5C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8008EB60: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8008EB64: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8008EB68: sw          $a3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r7;
    // 0x8008EB6C: b           L_8008EC18
    // 0x8008EB70: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
        goto L_8008EC18;
    // 0x8008EB70: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
L_8008EB74:
    // 0x8008EB74: ori         $t6, $zero, 0xD000
    ctx->r14 = 0 | 0XD000;
    // 0x8008EB78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EB7C: sw          $t6, 0x6D90($at)
    MEM_W(0X6D90, ctx->r1) = ctx->r14;
    // 0x8008EB80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EB84: sw          $zero, 0x6D78($at)
    MEM_W(0X6D78, ctx->r1) = 0;
    // 0x8008EB88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EB8C: sh          $zero, 0x6DB8($at)
    MEM_H(0X6DB8, ctx->r1) = 0;
    // 0x8008EB90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EB94: sh          $zero, 0x6DD0($at)
    MEM_H(0X6DD0, ctx->r1) = 0;
    // 0x8008EB98: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008EB9C: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008EBA0: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008EBA4: sll         $a0, $s3, 2
    ctx->r4 = S32(ctx->r19 << 2);
    // 0x8008EBA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008EBAC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008EBB0: sll         $a1, $s3, 1
    ctx->r5 = S32(ctx->r19 << 1);
    // 0x8008EBB4: addiu       $s7, $s7, 0x6DD0
    ctx->r23 = ADD32(ctx->r23, 0X6DD0);
    // 0x8008EBB8: addiu       $s6, $s6, 0x6DB8
    ctx->r22 = ADD32(ctx->r22, 0X6DB8);
    // 0x8008EBBC: addiu       $t7, $t7, 0x6D90
    ctx->r15 = ADD32(ctx->r15, 0X6D90);
    // 0x8008EBC0: addiu       $t8, $t8, 0x6D78
    ctx->r24 = ADD32(ctx->r24, 0X6D78);
    // 0x8008EBC4: ori         $a2, $zero, 0xD000
    ctx->r6 = 0 | 0XD000;
    // 0x8008EBC8: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x8008EBCC: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x8008EBD0: addu        $s2, $s6, $a1
    ctx->r18 = ADD32(ctx->r22, ctx->r5);
    // 0x8008EBD4: addu        $s1, $s7, $a1
    ctx->r17 = ADD32(ctx->r23, ctx->r5);
    // 0x8008EBD8: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x8008EBDC: sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // 0x8008EBE0: sh          $zero, 0x6($s1)
    MEM_H(0X6, ctx->r17) = 0;
    // 0x8008EBE4: sh          $zero, 0x2($s2)
    MEM_H(0X2, ctx->r18) = 0;
    // 0x8008EBE8: sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // 0x8008EBEC: sh          $zero, 0x6($s2)
    MEM_H(0X6, ctx->r18) = 0;
    // 0x8008EBF0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8008EBF4: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8008EBF8: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8008EBFC: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8008EC00: sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
    // 0x8008EC04: sw          $a2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r6;
    // 0x8008EC08: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8008EC0C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8008EC10: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    // 0x8008EC14: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_8008EC18:
    // 0x8008EC18: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008EC1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008EC20: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008EC24: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008EC28: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008EC2C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008EC30: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EC34: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008EC38: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008EC3C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8008EC40: jr          $ra
    // 0x8008EC44: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8008EC44: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void gzip_inflate_dynamic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6F24: addiu       $sp, $sp, -0x540
    ctx->r29 = ADD32(ctx->r29, -0X540);
    // 0x800C6F28: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800C6F2C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800C6F30: lw          $s3, -0x4F6C($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X4F6C);
    // 0x800C6F34: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800C6F38: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800C6F3C: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x800C6F40: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800C6F44: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C6F48: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C6F4C: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800C6F50: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800C6F54: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800C6F58: lw          $s4, 0x3CF8($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X3CF8);
    // 0x800C6F5C: beq         $at, $zero, L_800C6F80
    if (ctx->r1 == 0) {
        // 0x800C6F60: lw          $s2, -0x4F70($s2)
        ctx->r18 = MEM_W(ctx->r18, -0X4F70);
            goto L_800C6F80;
    }
    // 0x800C6F60: lw          $s2, -0x4F70($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X4F70);
L_800C6F64:
    // 0x800C6F64: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C6F68: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6F6C: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C6F70: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C6F74: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6F78: bne         $at, $zero, L_800C6F64
    if (ctx->r1 != 0) {
        // 0x800C6F7C: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C6F64;
    }
    // 0x800C6F7C: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_800C6F80:
    // 0x800C6F80: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C6F84: andi        $s1, $s2, 0x1F
    ctx->r17 = ctx->r18 & 0X1F;
    // 0x800C6F88: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C6F8C: addiu       $s1, $s1, 0x101
    ctx->r17 = ADD32(ctx->r17, 0X101);
    // 0x800C6F90: beq         $at, $zero, L_800C6FB4
    if (ctx->r1 == 0) {
        // 0x800C6F94: srlv        $s2, $s2, $t0
        ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
            goto L_800C6FB4;
    }
    // 0x800C6F94: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
L_800C6F98:
    // 0x800C6F98: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C6F9C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6FA0: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C6FA4: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C6FA8: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6FAC: bne         $at, $zero, L_800C6F98
    if (ctx->r1 != 0) {
        // 0x800C6FB0: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C6F98;
    }
    // 0x800C6FB0: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_800C6FB4:
    // 0x800C6FB4: andi        $s0, $s2, 0x1F
    ctx->r16 = ctx->r18 & 0X1F;
    // 0x800C6FB8: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C6FBC: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C6FC0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800C6FC4: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C6FC8: beq         $at, $zero, L_800C6FEC
    if (ctx->r1 == 0) {
        // 0x800C6FCC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C6FEC;
    }
    // 0x800C6FCC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C6FD0:
    // 0x800C6FD0: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C6FD4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6FD8: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C6FDC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C6FE0: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6FE4: bne         $at, $zero, L_800C6FD0
    if (ctx->r1 != 0) {
        // 0x800C6FE8: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C6FD0;
    }
    // 0x800C6FE8: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_800C6FEC:
    // 0x800C6FEC: andi        $t2, $s2, 0xF
    ctx->r10 = ctx->r18 & 0XF;
    // 0x800C6FF0: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800C6FF4: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800C6FF8: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C6FFC: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C7000: or          $t1, $zero, $t2
    ctx->r9 = 0 | ctx->r10;
    // 0x800C7004: addiu       $t9, $t9, -0x66C0
    ctx->r25 = ADD32(ctx->r25, -0X66C0);
    // 0x800C7008: beq         $t2, $zero, L_800C7070
    if (ctx->r10 == 0) {
        // 0x800C700C: addi        $t7, $sp, 0x44
        ctx->r15 = ADD32(ctx->r29, 0X44);
            goto L_800C7070;
    }
    // 0x800C700C: addi        $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
L_800C7010:
    // 0x800C7010: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800C7014: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C7018: beql        $at, $zero, L_800C7040
    if (ctx->r1 == 0) {
        // 0x800C701C: lbu         $v1, 0x0($t9)
        ctx->r3 = MEM_BU(ctx->r25, 0X0);
            goto L_800C7040;
    }
    goto skip_0;
    // 0x800C701C: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    skip_0:
L_800C7020:
    // 0x800C7020: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C7024: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C7028: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C702C: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C7030: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C7034: bne         $at, $zero, L_800C7020
    if (ctx->r1 != 0) {
        // 0x800C7038: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C7020;
    }
    // 0x800C7038: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x800C703C: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
L_800C7040:
    // 0x800C7040: andi        $v0, $s2, 0x7
    ctx->r2 = ctx->r18 & 0X7;
    // 0x800C7044: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800C7048: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C704C: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800C7050: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800C7054: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C7058: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C705C: bne         $t2, $zero, L_800C7010
    if (ctx->r10 != 0) {
        // 0x800C7060: addiu       $t9, $t9, 0x1
        ctx->r25 = ADD32(ctx->r25, 0X1);
            goto L_800C7010;
    }
    // 0x800C7060: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x800C7064: sltiu       $at, $t1, 0x13
    ctx->r1 = ctx->r9 < 0X13 ? 1 : 0;
    // 0x800C7068: beql        $at, $zero, L_800C7094
    if (ctx->r1 == 0) {
        // 0x800C706C: addiu       $t5, $zero, 0x7
        ctx->r13 = ADD32(0, 0X7);
            goto L_800C7094;
    }
    goto skip_1;
    // 0x800C706C: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    skip_1:
L_800C7070:
    // 0x800C7070: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x800C7074: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800C7078: slti        $at, $t1, 0x13
    ctx->r1 = SIGNED(ctx->r9) < 0X13 ? 1 : 0;
    // 0x800C707C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C7080: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800C7084: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800C7088: bne         $at, $zero, L_800C7070
    if (ctx->r1 != 0) {
        // 0x800C708C: addiu       $t9, $t9, 0x1
        ctx->r25 = ADD32(ctx->r25, 0X1);
            goto L_800C7070;
    }
    // 0x800C708C: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x800C7090: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
L_800C7094:
    // 0x800C7094: addi        $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x800C7098: addi        $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x800C709C: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800C70A0: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800C70A4: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x800C70A8: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x800C70AC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x800C70B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C70B4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800C70B8: jal         0x800C67D4
    // 0x800C70BC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    gzip_huft_build(rdram, ctx);
        goto after_0;
    // 0x800C70BC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_0:
    // 0x800C70C0: addi        $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x800C70C4: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800C70C8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C70CC: addiu       $v0, $v0, -0x65F4
    ctx->r2 = ADD32(ctx->r2, -0X65F4);
    // 0x800C70D0: sll         $v1, $t5, 1
    ctx->r3 = S32(ctx->r13 << 1);
    // 0x800C70D4: addi        $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x800C70D8: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C70DC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800C70E0: add         $t9, $s1, $s0
    ctx->r25 = ADD32(ctx->r17, ctx->r16);
    // 0x800C70E4: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800C70E8: addi        $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x800C70EC: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
L_800C70F0:
    // 0x800C70F0: beq         $t9, $zero, L_800C7270
    if (ctx->r25 == 0) {
        // 0x800C70F4: sltu        $at, $s3, $t5
        ctx->r1 = ctx->r19 < ctx->r13 ? 1 : 0;
            goto L_800C7270;
    }
    // 0x800C70F4: sltu        $at, $s3, $t5
    ctx->r1 = ctx->r19 < ctx->r13 ? 1 : 0;
    // 0x800C70F8: beql        $at, $zero, L_800C7120
    if (ctx->r1 == 0) {
        // 0x800C70FC: and         $v0, $s2, $t8
        ctx->r2 = ctx->r18 & ctx->r24;
            goto L_800C7120;
    }
    goto skip_2;
    // 0x800C70FC: and         $v0, $s2, $t8
    ctx->r2 = ctx->r18 & ctx->r24;
    skip_2:
L_800C7100:
    // 0x800C7100: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C7104: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C7108: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C710C: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C7110: slt         $at, $s3, $t5
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800C7114: bne         $at, $zero, L_800C7100
    if (ctx->r1 != 0) {
        // 0x800C7118: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C7100;
    }
    // 0x800C7118: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x800C711C: and         $v0, $s2, $t8
    ctx->r2 = ctx->r18 & ctx->r24;
L_800C7120:
    // 0x800C7120: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C7124: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x800C7128: lhu         $t0, 0x4($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X4);
    // 0x800C712C: lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1);
    // 0x800C7130: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x800C7134: srlv        $s2, $s2, $v0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r2 & 31));
    // 0x800C7138: bne         $at, $zero, L_800C71AC
    if (ctx->r1 != 0) {
        // 0x800C713C: sub         $s3, $s3, $v0
        ctx->r19 = SUB32(ctx->r19, ctx->r2);
            goto L_800C71AC;
    }
    // 0x800C713C: sub         $s3, $s3, $v0
    ctx->r19 = SUB32(ctx->r19, ctx->r2);
    // 0x800C7140: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800C7144: beq         $t0, $at, L_800C71C0
    if (ctx->r8 == ctx->r1) {
        // 0x800C7148: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_800C71C0;
    }
    // 0x800C7148: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800C714C: beql        $t0, $at, L_800C721C
    if (ctx->r8 == ctx->r1) {
        // 0x800C7150: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_800C721C;
    }
    goto skip_3;
    // 0x800C7150: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    skip_3:
    // 0x800C7154: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800C7158: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C715C: beql        $at, $zero, L_800C7184
    if (ctx->r1 == 0) {
        // 0x800C7160: andi        $t1, $s2, 0x7F
        ctx->r9 = ctx->r18 & 0X7F;
            goto L_800C7184;
    }
    goto skip_4;
    // 0x800C7160: andi        $t1, $s2, 0x7F
    ctx->r9 = ctx->r18 & 0X7F;
    skip_4:
L_800C7164:
    // 0x800C7164: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C7168: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C716C: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C7170: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C7174: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C7178: bne         $at, $zero, L_800C7164
    if (ctx->r1 != 0) {
        // 0x800C717C: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C7164;
    }
    // 0x800C717C: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x800C7180: andi        $t1, $s2, 0x7F
    ctx->r9 = ctx->r18 & 0X7F;
L_800C7184:
    // 0x800C7184: addiu       $t1, $t1, 0xB
    ctx->r9 = ADD32(ctx->r9, 0XB);
    // 0x800C7188: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C718C: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C7190: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
L_800C7194:
    // 0x800C7194: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800C7198: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800C719C: bne         $t1, $zero, L_800C7194
    if (ctx->r9 != 0) {
        // 0x800C71A0: addiu       $t7, $t7, 0x4
        ctx->r15 = ADD32(ctx->r15, 0X4);
            goto L_800C7194;
    }
    // 0x800C71A0: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x800C71A4: j           L_800C70F0
    // 0x800C71A8: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
        goto L_800C70F0;
    // 0x800C71A8: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
L_800C71AC:
    // 0x800C71AC: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x800C71B0: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x800C71B4: addiu       $t9, $t9, -0x1
    ctx->r25 = ADD32(ctx->r25, -0X1);
    // 0x800C71B8: j           L_800C70F0
    // 0x800C71BC: or          $t2, $zero, $t0
    ctx->r10 = 0 | ctx->r8;
        goto L_800C70F0;
    // 0x800C71BC: or          $t2, $zero, $t0
    ctx->r10 = 0 | ctx->r8;
L_800C71C0:
    // 0x800C71C0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800C71C4: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C71C8: beql        $at, $zero, L_800C71F0
    if (ctx->r1 == 0) {
        // 0x800C71CC: andi        $t1, $s2, 0x3
        ctx->r9 = ctx->r18 & 0X3;
            goto L_800C71F0;
    }
    goto skip_5;
    // 0x800C71CC: andi        $t1, $s2, 0x3
    ctx->r9 = ctx->r18 & 0X3;
    skip_5:
L_800C71D0:
    // 0x800C71D0: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C71D4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C71D8: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C71DC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C71E0: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C71E4: bne         $at, $zero, L_800C71D0
    if (ctx->r1 != 0) {
        // 0x800C71E8: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C71D0;
    }
    // 0x800C71E8: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x800C71EC: andi        $t1, $s2, 0x3
    ctx->r9 = ctx->r18 & 0X3;
L_800C71F0:
    // 0x800C71F0: addi        $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x800C71F4: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C71F8: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C71FC: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
L_800C7200:
    // 0x800C7200: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800C7204: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x800C7208: bne         $t1, $zero, L_800C7200
    if (ctx->r9 != 0) {
        // 0x800C720C: addiu       $t7, $t7, 0x4
        ctx->r15 = ADD32(ctx->r15, 0X4);
            goto L_800C7200;
    }
    // 0x800C720C: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x800C7210: j           L_800C70F0
    // 0x800C7214: nop

        goto L_800C70F0;
    // 0x800C7214: nop

    // 0x800C7218: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
L_800C721C:
    // 0x800C721C: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C7220: beql        $at, $zero, L_800C7248
    if (ctx->r1 == 0) {
        // 0x800C7224: andi        $t1, $s2, 0x7
        ctx->r9 = ctx->r18 & 0X7;
            goto L_800C7248;
    }
    goto skip_6;
    // 0x800C7224: andi        $t1, $s2, 0x7
    ctx->r9 = ctx->r18 & 0X7;
    skip_6:
L_800C7228:
    // 0x800C7228: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C722C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C7230: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C7234: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C7238: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C723C: bne         $at, $zero, L_800C7228
    if (ctx->r1 != 0) {
        // 0x800C7240: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C7228;
    }
    // 0x800C7240: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x800C7244: andi        $t1, $s2, 0x7
    ctx->r9 = ctx->r18 & 0X7;
L_800C7248:
    // 0x800C7248: addi        $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x800C724C: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C7250: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C7254: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
L_800C7258:
    // 0x800C7258: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800C725C: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800C7260: bne         $t1, $zero, L_800C7258
    if (ctx->r9 != 0) {
        // 0x800C7264: addiu       $t7, $t7, 0x4
        ctx->r15 = ADD32(ctx->r15, 0X4);
            goto L_800C7258;
    }
    // 0x800C7264: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x800C7268: j           L_800C70F0
    // 0x800C726C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
        goto L_800C70F0;
    // 0x800C726C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
L_800C7270:
    // 0x800C7270: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C7274: sw          $s4, 0x3CF8($at)
    MEM_W(0X3CF8, ctx->r1) = ctx->r20;
    // 0x800C7278: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C727C: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x800C7280: sw          $s2, -0x4F70($at)
    MEM_W(-0X4F70, ctx->r1) = ctx->r18;
    // 0x800C7284: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800C7288: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C728C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7290: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800C7294: addiu       $v0, $v0, -0x666E
    ctx->r2 = ADD32(ctx->r2, -0X666E);
    // 0x800C7298: addi        $v1, $sp, 0x34
    ctx->r3 = ADD32(ctx->r29, 0X34);
    // 0x800C729C: addi        $t0, $sp, 0x38
    ctx->r8 = ADD32(ctx->r29, 0X38);
    // 0x800C72A0: sw          $s3, -0x4F6C($at)
    MEM_W(-0X4F6C, ctx->r1) = ctx->r19;
    // 0x800C72A4: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800C72A8: or          $a1, $zero, $s1
    ctx->r5 = 0 | ctx->r17;
    // 0x800C72AC: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x800C72B0: addiu       $a3, $a3, -0x66AC
    ctx->r7 = ADD32(ctx->r7, -0X66AC);
    // 0x800C72B4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C72B8: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800C72BC: jal         0x800C67D4
    // 0x800C72C0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    gzip_huft_build(rdram, ctx);
        goto after_1;
    // 0x800C72C0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_1:
    // 0x800C72C4: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800C72C8: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800C72CC: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x800C72D0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C72D4: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800C72D8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C72DC: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800C72E0: addiu       $v0, $v0, -0x6612
    ctx->r2 = ADD32(ctx->r2, -0X6612);
    // 0x800C72E4: addi        $v1, $sp, 0x3C
    ctx->r3 = ADD32(ctx->r29, 0X3C);
    // 0x800C72E8: addi        $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x800C72EC: or          $a1, $zero, $s0
    ctx->r5 = 0 | ctx->r16;
    // 0x800C72F0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C72F4: addiu       $a3, $a3, -0x664E
    ctx->r7 = ADD32(ctx->r7, -0X664E);
    // 0x800C72F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C72FC: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800C7300: jal         0x800C67D4
    // 0x800C7304: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    gzip_huft_build(rdram, ctx);
        goto after_2;
    // 0x800C7304: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_2:
    // 0x800C7308: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800C730C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800C7310: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800C7314: jal         0x800C75A0
    // 0x800C7318: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    gzip_inflate_codes(rdram, ctx);
        goto after_3;
    // 0x800C7318: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x800C731C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800C7320: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7324: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800C7328: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800C732C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800C7330: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7334: jr          $ra
    // 0x800C7338: addiu       $sp, $sp, 0x540
    ctx->r29 = ADD32(ctx->r29, 0X540);
    return;
    // 0x800C7338: addiu       $sp, $sp, 0x540
    ctx->r29 = ADD32(ctx->r29, 0X540);
;}
RECOMP_FUNC void caution_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C9A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C9A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C9A8: jal         0x800C478C
    // 0x8008C9AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x8008C9AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008C9B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C9B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C9B8: jr          $ra
    // 0x8008C9BC: nop

    return;
    // 0x8008C9BC: nop

;}
RECOMP_FUNC void save_rng_seed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FB58: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006FB5C: lw          $a0, -0x265C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X265C);
    // 0x8006FB60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006FB64: jr          $ra
    // 0x8006FB68: sw          $a0, -0x2658($at)
    MEM_W(-0X2658, ctx->r1) = ctx->r4;
    return;
    // 0x8006FB68: sw          $a0, -0x2658($at)
    MEM_W(-0X2658, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void setup_particle_velocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0570: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B0574: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B0578: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B057C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B0580: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B0584: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B0588: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800B058C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B0590: andi        $t7, $t6, 0x70
    ctx->r15 = ctx->r14 & 0X70;
    // 0x800B0594: beq         $t7, $zero, L_800B05C0
    if (ctx->r15 == 0) {
        // 0x800B0598: or          $s1, $a3, $zero
        ctx->r17 = ctx->r7 | 0;
            goto L_800B05C0;
    }
    // 0x800B0598: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800B059C: lwc1        $f4, 0x30($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X30);
    // 0x800B05A0: nop

    // 0x800B05A4: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x800B05A8: lwc1        $f6, 0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X34);
    // 0x800B05AC: nop

    // 0x800B05B0: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x800B05B4: lwc1        $f8, 0x38($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X38);
    // 0x800B05B8: b           L_800B05D8
    // 0x800B05BC: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
        goto L_800B05D8;
    // 0x800B05BC: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
L_800B05C0:
    // 0x800B05C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B05C4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B05C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B05CC: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x800B05D0: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x800B05D4: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_800B05D8:
    // 0x800B05D8: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x800B05DC: nop

    // 0x800B05E0: andi        $t8, $v1, 0x700
    ctx->r24 = ctx->r3 & 0X700;
    // 0x800B05E4: beq         $t8, $zero, L_800B06D8
    if (ctx->r24 == 0) {
        // 0x800B05E8: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800B06D8;
    }
    // 0x800B05E8: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800B05EC: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x800B05F0: beq         $t9, $zero, L_800B0640
    if (ctx->r25 == 0) {
        // 0x800B05F4: andi        $t0, $v1, 0x200
        ctx->r8 = ctx->r3 & 0X200;
            goto L_800B0640;
    }
    // 0x800B05F4: andi        $t0, $v1, 0x200
    ctx->r8 = ctx->r3 & 0X200;
    // 0x800B05F8: lw          $a1, 0x74($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X74);
    // 0x800B05FC: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x800B0600: jal         0x8006FB8C
    // 0x800B0604: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x800B0604: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_0:
    // 0x800B0608: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800B060C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B0610: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B0614: lwc1        $f11, -0x6EE8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X6EE8);
    // 0x800B0618: lwc1        $f10, -0x6EE4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6EE4);
    // 0x800B061C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B0620: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B0624: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B0628: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B062C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800B0630: add.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f4.d + ctx->f16.d;
    // 0x800B0634: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800B0638: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x800B063C: andi        $t0, $v1, 0x200
    ctx->r8 = ctx->r3 & 0X200;
L_800B0640:
    // 0x800B0640: beq         $t0, $zero, L_800B0690
    if (ctx->r8 == 0) {
        // 0x800B0644: andi        $t1, $v1, 0x400
        ctx->r9 = ctx->r3 & 0X400;
            goto L_800B0690;
    }
    // 0x800B0644: andi        $t1, $v1, 0x400
    ctx->r9 = ctx->r3 & 0X400;
    // 0x800B0648: lw          $a1, 0x78($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X78);
    // 0x800B064C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B0650: jal         0x8006FB8C
    // 0x800B0654: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x800B0654: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_1:
    // 0x800B0658: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800B065C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B0660: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B0664: lwc1        $f17, -0x6EE0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X6EE0);
    // 0x800B0668: lwc1        $f16, -0x6EDC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6EDC);
    // 0x800B066C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800B0670: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800B0674: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B0678: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B067C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B0680: add.d       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f10.d + ctx->f6.d;
    // 0x800B0684: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800B0688: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x800B068C: andi        $t1, $v1, 0x400
    ctx->r9 = ctx->r3 & 0X400;
L_800B0690:
    // 0x800B0690: beq         $t1, $zero, L_800B06D8
    if (ctx->r9 == 0) {
        // 0x800B0694: nop
    
            goto L_800B06D8;
    }
    // 0x800B0694: nop

    // 0x800B0698: lw          $a1, 0x7C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X7C);
    // 0x800B069C: jal         0x8006FB8C
    // 0x800B06A0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800B06A0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_2:
    // 0x800B06A4: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800B06A8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B06AC: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B06B0: lwc1        $f7, -0x6ED8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X6ED8);
    // 0x800B06B4: lwc1        $f6, -0x6ED4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6ED4);
    // 0x800B06B8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B06BC: mul.d       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x800B06C0: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B06C4: nop

    // 0x800B06C8: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x800B06CC: add.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f16.d + ctx->f18.d;
    // 0x800B06D0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800B06D4: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_800B06D8:
    // 0x800B06D8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800B06DC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800B06E0: andi        $v1, $v0, 0x70
    ctx->r3 = ctx->r2 & 0X70;
    // 0x800B06E4: beq         $v1, $at, L_800B06FC
    if (ctx->r3 == ctx->r1) {
        // 0x800B06E8: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800B06FC;
    }
    // 0x800B06E8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800B06EC: beq         $v1, $at, L_800B0758
    if (ctx->r3 == ctx->r1) {
        // 0x800B06F0: lw          $t5, 0x44($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X44);
            goto L_800B0758;
    }
    // 0x800B06F0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800B06F4: b           L_800B07AC
    // 0x800B06F8: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
        goto L_800B07AC;
    // 0x800B06F8: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
L_800B06FC:
    // 0x800B06FC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800B0700: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B0704: lwc1        $f4, 0x1C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x800B0708: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B070C: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B0710: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B0714: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x800B0718: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800B071C: nop

    // 0x800B0720: lwc1        $f8, 0x20($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X20);
    // 0x800B0724: nop

    // 0x800B0728: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800B072C: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x800B0730: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800B0734: nop

    // 0x800B0738: lwc1        $f4, 0x24($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X24);
    // 0x800B073C: nop

    // 0x800B0740: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B0744: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    // 0x800B0748: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800B074C: b           L_800B07AC
    // 0x800B0750: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
        goto L_800B07AC;
    // 0x800B0750: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x800B0754: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
L_800B0758:
    // 0x800B0758: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B075C: lwc1        $f8, 0x1C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x800B0760: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B0764: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800B0768: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B076C: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x800B0770: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800B0774: nop

    // 0x800B0778: lwc1        $f4, 0x20($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X20);
    // 0x800B077C: nop

    // 0x800B0780: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800B0784: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x800B0788: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800B078C: nop

    // 0x800B0790: lwc1        $f8, 0x24($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X24);
    // 0x800B0794: nop

    // 0x800B0798: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800B079C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x800B07A0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800B07A4: nop

    // 0x800B07A8: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
L_800B07AC:
    // 0x800B07AC: beq         $t8, $zero, L_800B0910
    if (ctx->r24 == 0) {
        // 0x800B07B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B0910;
    }
    // 0x800B07B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B07B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B07B8: nop

    // 0x800B07BC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800B07C0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800B07C4: lwc1        $f6, 0x3C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x800B07C8: nop

    // 0x800B07CC: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x800B07D0: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x800B07D4: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x800B07D8: nop

    // 0x800B07DC: andi        $t9, $v1, 0x10
    ctx->r25 = ctx->r3 & 0X10;
    // 0x800B07E0: beq         $t9, $zero, L_800B0830
    if (ctx->r25 == 0) {
        // 0x800B07E4: andi        $t0, $v1, 0x60
        ctx->r8 = ctx->r3 & 0X60;
            goto L_800B0830;
    }
    // 0x800B07E4: andi        $t0, $v1, 0x60
    ctx->r8 = ctx->r3 & 0X60;
    // 0x800B07E8: lw          $a1, 0x70($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X70);
    // 0x800B07EC: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B07F0: jal         0x8006FB8C
    // 0x800B07F4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_3;
    // 0x800B07F4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_3:
    // 0x800B07F8: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800B07FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B0800: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B0804: lwc1        $f11, -0x6ED0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X6ED0);
    // 0x800B0808: lwc1        $f10, -0x6ECC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6ECC);
    // 0x800B080C: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800B0810: mul.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B0814: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B0818: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B081C: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x800B0820: add.d       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f16.d + ctx->f6.d;
    // 0x800B0824: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x800B0828: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x800B082C: andi        $t0, $v1, 0x60
    ctx->r8 = ctx->r3 & 0X60;
L_800B0830:
    // 0x800B0830: beq         $t0, $zero, L_800B08B8
    if (ctx->r8 == 0) {
        // 0x800B0834: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_800B08B8;
    }
    // 0x800B0834: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800B0838: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800B083C: andi        $t3, $v1, 0x20
    ctx->r11 = ctx->r3 & 0X20;
    // 0x800B0840: lh          $t2, 0x12($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X12);
    // 0x800B0844: beq         $t3, $zero, L_800B086C
    if (ctx->r11 == 0) {
        // 0x800B0848: sh          $t2, 0x28($sp)
        MEM_H(0X28, ctx->r29) = ctx->r10;
            goto L_800B086C;
    }
    // 0x800B0848: sh          $t2, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r10;
    // 0x800B084C: lh          $a1, 0x6A($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X6A);
    // 0x800B0850: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B0854: jal         0x8006FB8C
    // 0x800B0858: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_4;
    // 0x800B0858: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_4:
    // 0x800B085C: lh          $t4, 0x28($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X28);
    // 0x800B0860: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0864: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800B0868: sh          $t5, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r13;
L_800B086C:
    // 0x800B086C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800B0870: andi        $t8, $v1, 0x40
    ctx->r24 = ctx->r3 & 0X40;
    // 0x800B0874: lh          $t7, 0x14($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X14);
    // 0x800B0878: beq         $t8, $zero, L_800B089C
    if (ctx->r24 == 0) {
        // 0x800B087C: sh          $t7, 0x2A($sp)
        MEM_H(0X2A, ctx->r29) = ctx->r15;
            goto L_800B089C;
    }
    // 0x800B087C: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    // 0x800B0880: lh          $a1, 0x6C($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X6C);
    // 0x800B0884: jal         0x8006FB8C
    // 0x800B0888: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_5;
    // 0x800B0888: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_5:
    // 0x800B088C: lh          $t9, 0x2A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A);
    // 0x800B0890: nop

    // 0x800B0894: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800B0898: sh          $t0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r8;
L_800B089C:
    // 0x800B089C: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x800B08A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B08A4: jal         0x800706D0
    // 0x800B08A8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    vec3f_rotate_py(rdram, ctx);
        goto after_6;
    // 0x800B08A8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x800B08AC: b           L_800B08CC
    // 0x800B08B0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
        goto L_800B08CC;
    // 0x800B08B0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x800B08B4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_800B08B8:
    // 0x800B08B8: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x800B08BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B08C0: jal         0x800706D0
    // 0x800B08C4: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    vec3f_rotate_py(rdram, ctx);
        goto after_7;
    // 0x800B08C4: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    after_7:
    // 0x800B08C8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
L_800B08CC:
    // 0x800B08CC: jal         0x80070560
    // 0x800B08D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    vec3f_rotate(rdram, ctx);
        goto after_8;
    // 0x800B08D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x800B08D4: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B08D8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800B08DC: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B08E0: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B08E4: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B08E8: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x800B08EC: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800B08F0: nop

    // 0x800B08F4: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800B08F8: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x800B08FC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B0900: nop

    // 0x800B0904: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B0908: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    // 0x800B090C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B0910:
    // 0x800B0910: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B0914: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B0918: jr          $ra
    // 0x800B091C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B091C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void get_taj_challenge_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017EBC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80017EC0: lh          $v0, -0x4BA8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4BA8);
    // 0x80017EC4: jr          $ra
    // 0x80017EC8: nop

    return;
    // 0x80017EC8: nop

;}
RECOMP_FUNC void play_rocket_trailing_sound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F138: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8003F13C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8003F140: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8003F144: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8003F148: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8003F14C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8003F150: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8003F154: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8003F158: andi        $s6, $a2, 0xFFFF
    ctx->r22 = ctx->r6 & 0XFFFF;
    // 0x8003F15C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8003F160: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8003F164: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003F168: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003F16C: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8003F170: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8003F174: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8003F178: jal         0x8001BAC4
    // 0x8003F17C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    get_racer_objects_by_port(rdram, ctx);
        goto after_0;
    // 0x8003F17C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_0:
    // 0x8003F180: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8003F184: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003F188: blez        $t6, L_8003F24C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8003F18C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8003F24C;
    }
    // 0x8003F18C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8003F190: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_8003F194:
    // 0x8003F194: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8003F198: lw          $t7, 0x4($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X4);
    // 0x8003F19C: nop

    // 0x8003F1A0: beq         $t7, $v0, L_8003F23C
    if (ctx->r15 == ctx->r2) {
        // 0x8003F1A4: lw          $t0, 0x60($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X60);
            goto L_8003F23C;
    }
    // 0x8003F1A4: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8003F1A8: lw          $t8, 0x64($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X64);
    // 0x8003F1AC: nop

    // 0x8003F1B0: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8003F1B4: nop

    // 0x8003F1B8: beq         $s3, $t9, L_8003F23C
    if (ctx->r19 == ctx->r25) {
        // 0x8003F1BC: lw          $t0, 0x60($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X60);
            goto L_8003F23C;
    }
    // 0x8003F1BC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8003F1C0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003F1C4: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8003F1C8: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003F1CC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003F1D0: lwc1        $f10, 0x10($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8003F1D4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003F1D8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003F1DC: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003F1E0: lwc1        $f18, 0x14($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8003F1E4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003F1E8: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003F1EC: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003F1F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003F1F4: jal         0x800CA030
    // 0x8003F1F8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8003F1F8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x8003F1FC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8003F200: jal         0x80001CB8
    // 0x8003F204: andi        $a0, $s6, 0xFFFF
    ctx->r4 = ctx->r22 & 0XFFFF;
    sound_distance(rdram, ctx);
        goto after_2;
    // 0x8003F204: andi        $a0, $s6, 0xFFFF
    ctx->r4 = ctx->r22 & 0XFFFF;
    after_2:
    // 0x8003F208: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8003F20C: bgez        $v0, L_8003F224
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003F210: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8003F224;
    }
    // 0x8003F210: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003F214: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8003F218: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003F21C: nop

    // 0x8003F220: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8003F224:
    // 0x8003F224: c.le.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl <= ctx->f18.fl;
    // 0x8003F228: nop

    // 0x8003F22C: bc1f        L_8003F23C
    if (!c1cs) {
        // 0x8003F230: lw          $t0, 0x60($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X60);
            goto L_8003F23C;
    }
    // 0x8003F230: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8003F234: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8003F238: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
L_8003F23C:
    // 0x8003F23C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003F240: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8003F244: bne         $at, $zero, L_8003F194
    if (ctx->r1 != 0) {
        // 0x8003F248: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8003F194;
    }
    // 0x8003F248: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8003F24C:
    // 0x8003F24C: beq         $s4, $zero, L_8003F2C4
    if (ctx->r20 == 0) {
        // 0x8003F250: nop
    
            goto L_8003F2C4;
    }
    // 0x8003F250: nop

    // 0x8003F254: lw          $a0, 0x1C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X1C);
    // 0x8003F258: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8003F25C: bne         $a0, $zero, L_8003F2A8
    if (ctx->r4 != 0) {
        // 0x8003F260: addiu       $s0, $s0, -0x25A4
        ctx->r16 = ADD32(ctx->r16, -0X25A4);
            goto L_8003F2A8;
    }
    // 0x8003F260: addiu       $s0, $s0, -0x25A4
    ctx->r16 = ADD32(ctx->r16, -0X25A4);
    // 0x8003F264: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8003F268: andi        $a0, $s6, 0xFFFF
    ctx->r4 = ctx->r22 & 0XFFFF;
    // 0x8003F26C: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x8003F270: beq         $at, $zero, L_8003F2F8
    if (ctx->r1 == 0) {
        // 0x8003F274: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8003F2F8;
    }
    // 0x8003F274: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003F278: lw          $a1, 0xC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XC);
    // 0x8003F27C: lw          $a2, 0x10($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X10);
    // 0x8003F280: lw          $a3, 0x14($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X14);
    // 0x8003F284: addiu       $t3, $s5, 0x1C
    ctx->r11 = ADD32(ctx->r21, 0X1C);
    // 0x8003F288: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8003F28C: jal         0x80009558
    // 0x8003F290: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_3;
    // 0x8003F290: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_3:
    // 0x8003F294: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8003F298: nop

    // 0x8003F29C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8003F2A0: b           L_8003F2F8
    // 0x8003F2A4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
        goto L_8003F2F8;
    // 0x8003F2A4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_8003F2A8:
    // 0x8003F2A8: lw          $a1, 0xC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XC);
    // 0x8003F2AC: lw          $a2, 0x10($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X10);
    // 0x8003F2B0: lw          $a3, 0x14($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X14);
    // 0x8003F2B4: jal         0x800096D8
    // 0x8003F2B8: nop

    audspat_point_set_position(rdram, ctx);
        goto after_4;
    // 0x8003F2B8: nop

    after_4:
    // 0x8003F2BC: b           L_8003F2FC
    // 0x8003F2C0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8003F2FC;
    // 0x8003F2C0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8003F2C4:
    // 0x8003F2C4: lw          $a0, 0x1C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X1C);
    // 0x8003F2C8: nop

    // 0x8003F2CC: beq         $a0, $zero, L_8003F2FC
    if (ctx->r4 == 0) {
        // 0x8003F2D0: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8003F2FC;
    }
    // 0x8003F2D0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8003F2D4: jal         0x800096F8
    // 0x8003F2D8: nop

    audspat_point_stop(rdram, ctx);
        goto after_5;
    // 0x8003F2D8: nop

    after_5:
    // 0x8003F2DC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8003F2E0: addiu       $s0, $s0, -0x25A4
    ctx->r16 = ADD32(ctx->r16, -0X25A4);
    // 0x8003F2E4: sw          $zero, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = 0;
    // 0x8003F2E8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8003F2EC: nop

    // 0x8003F2F0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8003F2F4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_8003F2F8:
    // 0x8003F2F8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8003F2FC:
    // 0x8003F2FC: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8003F300: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003F304: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003F308: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F30C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8003F310: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8003F314: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8003F318: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8003F31C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8003F320: jr          $ra
    // 0x8003F324: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8003F324: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void write_eeprom_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074BD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80074BD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074BDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074BE0: jal         0x8006A340
    // 0x80074BE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80074BE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80074BE8: jal         0x800CE770
    // 0x80074BEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x80074BEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074BF0: bne         $v0, $zero, L_80074C00
    if (ctx->r2 != 0) {
        // 0x80074BF4: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_80074C00;
    }
    // 0x80074BF4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074BF8: b           L_80074C94
    // 0x80074BFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80074C94;
    // 0x80074BFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074C00:
    // 0x80074C00: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80074C04: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80074C08: jal         0x800CF064
    // 0x80074C0C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ll_lshift_recomp(rdram, ctx);
        goto after_2;
    // 0x80074C0C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_2:
    // 0x80074C10: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80074C14: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x80074C18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074C1C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80074C20: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074C24: jal         0x800CEFC0
    // 0x80074C28: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ull_rshift_recomp(rdram, ctx);
        goto after_3;
    // 0x80074C28: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_3:
    // 0x80074C2C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80074C30: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x80074C34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074C38: jal         0x80074A64
    // 0x80074C3C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    calculate_eeprom_settings_checksum(rdram, ctx);
        goto after_4;
    // 0x80074C3C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_4:
    // 0x80074C40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80074C44: sra         $a0, $v0, 31
    ctx->r4 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80074C48: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074C4C: jal         0x800CF064
    // 0x80074C50: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    __ll_lshift_recomp(rdram, ctx);
        goto after_5;
    // 0x80074C50: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    after_5:
    // 0x80074C54: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80074C58: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80074C5C: or          $t8, $t6, $v0
    ctx->r24 = ctx->r14 | ctx->r2;
    // 0x80074C60: or          $t9, $t7, $v1
    ctx->r25 = ctx->r15 | ctx->r3;
    // 0x80074C64: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80074C68: jal         0x8006ED00
    // 0x80074C6C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    is_reset_pressed(rdram, ctx);
        goto after_6;
    // 0x80074C6C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    after_6:
    // 0x80074C70: bne         $v0, $zero, L_80074C94
    if (ctx->r2 != 0) {
        // 0x80074C74: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80074C94;
    }
    // 0x80074C74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80074C78: jal         0x8006A340
    // 0x80074C7C: nop

    si_mesg(rdram, ctx);
        goto after_7;
    // 0x80074C7C: nop

    after_7:
    // 0x80074C80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074C84: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80074C88: jal         0x800CEAE0
    // 0x80074C8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osEepromWrite_recomp(rdram, ctx);
        goto after_8;
    // 0x80074C8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_8:
    // 0x80074C90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80074C94:
    // 0x80074C94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074C98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074C9C: jr          $ra
    // 0x80074CA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80074CA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _collectPVoices(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800658FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80065900: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80065904: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80065908: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006590C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80065910: lw          $s0, 0x14($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X14);
    // 0x80065914: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80065918: beq         $s0, $zero, L_80065944
    if (ctx->r16 == 0) {
        // 0x8006591C: addiu       $s2, $a0, 0x4
        ctx->r18 = ADD32(ctx->r4, 0X4);
            goto L_80065944;
    }
    // 0x8006591C: addiu       $s2, $a0, 0x4
    ctx->r18 = ADD32(ctx->r4, 0X4);
L_80065920:
    // 0x80065920: jal         0x800C8CC0
    // 0x80065924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x80065924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80065928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006592C: jal         0x800C8CF0
    // 0x80065930: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_1;
    // 0x80065930: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x80065934: lw          $s0, 0x14($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X14);
    // 0x80065938: nop

    // 0x8006593C: bne         $s0, $zero, L_80065920
    if (ctx->r16 != 0) {
        // 0x80065940: nop
    
            goto L_80065920;
    }
    // 0x80065940: nop

L_80065944:
    // 0x80065944: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80065948: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006594C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80065950: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80065954: jr          $ra
    // 0x80065958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80065958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void tex_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B70C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007B710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B714: beq         $a0, $zero, L_8007B7B4
    if (ctx->r4 == 0) {
        // 0x8007B718: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8007B7B4;
    }
    // 0x8007B718: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007B71C: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
    // 0x8007B720: nop

    // 0x8007B724: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007B728: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8007B72C: bgtz        $t8, L_8007B7B4
    if (SIGNED(ctx->r24) > 0) {
        // 0x8007B730: sb          $t7, 0x5($a0)
        MEM_B(0X5, ctx->r4) = ctx->r15;
            goto L_8007B7B4;
    }
    // 0x8007B730: sb          $t7, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r15;
    // 0x8007B734: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007B738: lw          $a0, 0x68D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68D0);
    // 0x8007B73C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007B740: blez        $a0, L_8007B7B4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007B744: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8007B7B4;
    }
    // 0x8007B744: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007B748: lw          $a1, 0x68C8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X68C8);
    // 0x8007B74C: nop

    // 0x8007B750: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
L_8007B754:
    // 0x8007B754: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x8007B758: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8007B75C: nop

    // 0x8007B760: bne         $a2, $t1, L_8007B7A8
    if (ctx->r6 != ctx->r9) {
        // 0x8007B764: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8007B7A8;
    }
    // 0x8007B764: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007B768: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8007B76C: jal         0x80071380
    // 0x8007B770: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    mempool_free(rdram, ctx);
        goto after_0;
    // 0x8007B770: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_0:
    // 0x8007B774: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B778: addiu       $v0, $v0, 0x68C8
    ctx->r2 = ADD32(ctx->r2, 0X68C8);
    // 0x8007B77C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8007B780: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8007B784: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8007B788: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8007B78C: sw          $a0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r4;
    // 0x8007B790: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8007B794: nop

    // 0x8007B798: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x8007B79C: b           L_8007B7B4
    // 0x8007B7A0: sw          $a0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r4;
        goto L_8007B7B4;
    // 0x8007B7A0: sw          $a0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r4;
    // 0x8007B7A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8007B7A8:
    // 0x8007B7A8: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007B7AC: bne         $at, $zero, L_8007B754
    if (ctx->r1 != 0) {
        // 0x8007B7B0: sll         $t9, $v0, 3
        ctx->r25 = S32(ctx->r2 << 3);
            goto L_8007B754;
    }
    // 0x8007B7B0: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
L_8007B7B4:
    // 0x8007B7B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B7B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007B7BC: jr          $ra
    // 0x8007B7C0: nop

    return;
    // 0x8007B7C0: nop

;}
RECOMP_FUNC void light_distance_calc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033A54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80033A58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80033A5C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80033A60: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80033A64: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80033A68: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80033A6C: lbu         $t7, 0x3($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X3);
    // 0x80033A70: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80033A74: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80033A78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80033A7C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80033A80: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80033A84: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80033A88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80033A8C: beq         $at, $zero, L_80033C2C
    if (ctx->r1 == 0) {
        // 0x80033A90: div.s       $f20, $f6, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
            goto L_80033C2C;
    }
    // 0x80033A90: div.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80033A94: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80033A98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80033A9C: addu        $at, $at, $t8
    gpr jr_addend_80033AA8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80033AA0: lw          $t8, 0x6510($at)
    ctx->r24 = ADD32(ctx->r1, 0X6510);
    // 0x80033AA4: nop

    // 0x80033AA8: jr          $t8
    // 0x80033AAC: nop

    switch (jr_addend_80033AA8 >> 2) {
        case 0: goto L_80033AB0; break;
        case 1: goto L_80033AE4; break;
        case 2: goto L_80033B24; break;
        case 3: goto L_80033B88; break;
        case 4: goto L_80033BF4; break;
        default: switch_error(__func__, 0x80033AA8, 0x800E6510);
    }
    // 0x80033AAC: nop

L_80033AB0:
    // 0x80033AB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033AB4: lwc1        $f12, -0x25C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25C0);
    // 0x80033AB8: jal         0x800CA030
    // 0x80033ABC: nop

    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80033ABC: nop

    after_0:
    // 0x80033AC0: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80033AC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033AC8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80033ACC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80033AD0: nop

    // 0x80033AD4: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80033AD8: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80033ADC: b           L_80033C30
    // 0x80033AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80033C30;
    // 0x80033AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033AE4:
    // 0x80033AE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033AE8: lwc1        $f12, -0x25C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25C0);
    // 0x80033AEC: jal         0x800CA030
    // 0x80033AF0: nop

    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80033AF0: nop

    after_1:
    // 0x80033AF4: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80033AF8: nop

    // 0x80033AFC: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80033B00: jal         0x800CA030
    // 0x80033B04: nop

    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80033B04: nop

    after_2:
    // 0x80033B08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033B0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80033B10: nop

    // 0x80033B14: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80033B18: mul.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80033B1C: b           L_80033C30
    // 0x80033B20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80033C30;
    // 0x80033B20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033B24:
    // 0x80033B24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033B28: lwc1        $f12, -0x25C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25C0);
    // 0x80033B2C: jal         0x800CA030
    // 0x80033B30: nop

    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x80033B30: nop

    after_3:
    // 0x80033B34: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80033B38: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80033B3C: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80033B40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80033B44: nop

    // 0x80033B48: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80033B4C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80033B50: nop

    // 0x80033B54: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80033B58: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033B5C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033B60: nop

    // 0x80033B64: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80033B68: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80033B6C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80033B70: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x80033B74: jal         0x80070A38
    // 0x80033B78: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    coss_f(rdram, ctx);
        goto after_4;
    // 0x80033B78: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    after_4:
    // 0x80033B7C: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80033B80: b           L_80033C30
    // 0x80033B84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80033C30;
    // 0x80033B84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033B88:
    // 0x80033B88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033B8C: lwc1        $f12, -0x25C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25C0);
    // 0x80033B90: jal         0x800CA030
    // 0x80033B94: nop

    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x80033B94: nop

    after_5:
    // 0x80033B98: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80033B9C: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80033BA0: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80033BA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80033BA8: nop

    // 0x80033BAC: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80033BB0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80033BB4: nop

    // 0x80033BB8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80033BBC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033BC0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033BC4: nop

    // 0x80033BC8: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80033BCC: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80033BD0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80033BD4: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x80033BD8: jal         0x80070A38
    // 0x80033BDC: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    coss_f(rdram, ctx);
        goto after_6;
    // 0x80033BDC: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    after_6:
    // 0x80033BE0: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80033BE4: nop

    // 0x80033BE8: mul.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80033BEC: b           L_80033C2C
    // 0x80033BF0: nop

        goto L_80033C2C;
    // 0x80033BF0: nop

L_80033BF4:
    // 0x80033BF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033BF8: lwc1        $f12, -0x25C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25C0);
    // 0x80033BFC: jal         0x800CA030
    // 0x80033C00: nop

    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x80033C00: nop

    after_7:
    // 0x80033C04: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80033C08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033C0C: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80033C10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80033C14: nop

    // 0x80033C18: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80033C1C: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80033C20: nop

    // 0x80033C24: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80033C28: nop

L_80033C2C:
    // 0x80033C2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033C30:
    // 0x80033C30: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x80033C34: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80033C38: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80033C3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80033C40: jr          $ra
    // 0x80033C44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80033C44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sound_play_direct(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001F14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80001F18: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001F1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001F20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80001F24: blez        $t6, L_80001F4C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80001F28: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80001F4C;
    }
    // 0x80001F28: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80001F2C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80001F30: jal         0x800020E8
    // 0x80001F34: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    sound_count(rdram, ctx);
        goto after_0;
    // 0x80001F34: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80001F38: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80001F3C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80001F40: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80001F44: beq         $at, $zero, L_80001F5C
    if (ctx->r1 == 0) {
        // 0x80001F48: nop
    
            goto L_80001F5C;
    }
    // 0x80001F48: nop

L_80001F4C:
    // 0x80001F4C: beq         $a2, $zero, L_80001FAC
    if (ctx->r6 == 0) {
        // 0x80001F50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001FAC;
    }
    // 0x80001F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001F54: b           L_80001FA8
    // 0x80001F58: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_80001FA8;
    // 0x80001F58: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_80001F5C:
    // 0x80001F5C: beq         $a2, $zero, L_80001F88
    if (ctx->r6 == 0) {
        // 0x80001F60: lui         $t9, 0x8011
        ctx->r25 = S32(0X8011 << 16);
            goto L_80001F88;
    }
    // 0x80001F60: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80001F64: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80001F68: lw          $t7, 0x6294($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6294);
    // 0x80001F6C: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80001F70: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80001F74: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x80001F78: jal         0x80004638
    // 0x80001F7C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    sndp_play(rdram, ctx);
        goto after_1;
    // 0x80001F7C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_1:
    // 0x80001F80: b           L_80001FAC
    // 0x80001F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80001FAC;
    // 0x80001F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001F88:
    // 0x80001F88: lw          $t9, 0x6294($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6294);
    // 0x80001F8C: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80001F90: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80001F94: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80001F98: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x80001F9C: addiu       $a2, $a2, 0x6508
    ctx->r6 = ADD32(ctx->r6, 0X6508);
    // 0x80001FA0: jal         0x80004638
    // 0x80001FA4: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    sndp_play(rdram, ctx);
        goto after_2;
    // 0x80001FA4: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_2:
L_80001FA8:
    // 0x80001FA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001FAC:
    // 0x80001FAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80001FB0: jr          $ra
    // 0x80001FB4: nop

    return;
    // 0x80001FB4: nop

;}
RECOMP_FUNC void write_eeprom_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074948: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007494C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80074950: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80074954: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074958: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007495C: andi        $s1, $a1, 0xFF
    ctx->r17 = ctx->r5 & 0XFF;
    // 0x80074960: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80074964: jal         0x8006A340
    // 0x80074968: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80074968: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x8007496C: jal         0x800CE770
    // 0x80074970: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x80074970: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074974: bne         $v0, $zero, L_80074984
    if (ctx->r2 != 0) {
        // 0x80074978: addiu       $a0, $zero, 0x200
        ctx->r4 = ADD32(0, 0X200);
            goto L_80074984;
    }
    // 0x80074978: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x8007497C: b           L_80074A4C
    // 0x80074980: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80074A4C;
    // 0x80074980: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074984:
    // 0x80074984: jal         0x80070EDC
    // 0x80074988: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x80074988: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x8007498C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80074990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074994: jal         0x80073AFC
    // 0x80074998: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800738A4(rdram, ctx);
        goto after_3;
    // 0x80074998: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8007499C: andi        $t7, $s1, 0x1
    ctx->r15 = ctx->r17 & 0X1;
    // 0x800749A0: beq         $t7, $zero, L_800749E8
    if (ctx->r15 == 0) {
        // 0x800749A4: sw          $s1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r17;
            goto L_800749E8;
    }
    // 0x800749A4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800749A8: jal         0x8006ED00
    // 0x800749AC: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    is_reset_pressed(rdram, ctx);
        goto after_4;
    // 0x800749AC: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    after_4:
    // 0x800749B0: bne         $v0, $zero, L_800749E8
    if (ctx->r2 != 0) {
        // 0x800749B4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800749E8;
    }
    // 0x800749B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800749B8:
    // 0x800749B8: jal         0x8006A340
    // 0x800749BC: nop

    si_mesg(rdram, ctx);
        goto after_5;
    // 0x800749BC: nop

    after_5:
    // 0x800749C0: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x800749C4: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x800749C8: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
    // 0x800749CC: addu        $a2, $t9, $s2
    ctx->r6 = ADD32(ctx->r25, ctx->r18);
    // 0x800749D0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800749D4: jal         0x800CEAE0
    // 0x800749D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromWrite_recomp(rdram, ctx);
        goto after_6;
    // 0x800749D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x800749DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800749E0: bne         $s0, $s1, L_800749B8
    if (ctx->r16 != ctx->r17) {
        // 0x800749E4: nop
    
            goto L_800749B8;
    }
    // 0x800749E4: nop

L_800749E8:
    // 0x800749E8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800749EC: nop

    // 0x800749F0: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800749F4: beq         $t1, $zero, L_80074A40
    if (ctx->r9 == 0) {
        // 0x800749F8: nop
    
            goto L_80074A40;
    }
    // 0x800749F8: nop

    // 0x800749FC: jal         0x8006ED00
    // 0x80074A00: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    is_reset_pressed(rdram, ctx);
        goto after_7;
    // 0x80074A00: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    after_7:
    // 0x80074A04: bne         $v0, $zero, L_80074A40
    if (ctx->r2 != 0) {
        // 0x80074A08: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80074A40;
    }
    // 0x80074A08: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80074A0C:
    // 0x80074A0C: jal         0x8006A340
    // 0x80074A10: nop

    si_mesg(rdram, ctx);
        goto after_8;
    // 0x80074A10: nop

    after_8:
    // 0x80074A14: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80074A18: sll         $t3, $s0, 3
    ctx->r11 = S32(ctx->r16 << 3);
    // 0x80074A1C: addu        $a2, $s2, $t3
    ctx->r6 = ADD32(ctx->r18, ctx->r11);
    // 0x80074A20: andi        $t2, $a1, 0xFF
    ctx->r10 = ctx->r5 & 0XFF;
    // 0x80074A24: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80074A28: addiu       $a2, $a2, 0xC0
    ctx->r6 = ADD32(ctx->r6, 0XC0);
    // 0x80074A2C: jal         0x800CEAE0
    // 0x80074A30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromWrite_recomp(rdram, ctx);
        goto after_9;
    // 0x80074A30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x80074A34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074A38: bne         $s0, $s1, L_80074A0C
    if (ctx->r16 != ctx->r17) {
        // 0x80074A3C: nop
    
            goto L_80074A0C;
    }
    // 0x80074A3C: nop

L_80074A40:
    // 0x80074A40: jal         0x80071380
    // 0x80074A44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_10;
    // 0x80074A44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x80074A48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80074A4C:
    // 0x80074A4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80074A50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074A54: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80074A58: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80074A5C: jr          $ra
    // 0x80074A60: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80074A60: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void obj_loop_checkpoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AD68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003AD6C: jr          $ra
    // 0x8003AD70: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003AD70: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void npc_dialogue_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D530: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009D534: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D538: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D53C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8009D540: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8009D544: jal         0x800C3958
    // 0x8009D548: sb          $zero, -0x59C($at)
    MEM_B(-0X59C, ctx->r1) = 0;
    textbox_visible(rdram, ctx);
        goto after_0;
    // 0x8009D548: sb          $zero, -0x59C($at)
    MEM_B(-0X59C, ctx->r1) = 0;
    after_0:
    // 0x8009D54C: beq         $v0, $zero, L_8009D56C
    if (ctx->r2 == 0) {
        // 0x8009D550: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_8009D56C;
    }
    // 0x8009D550: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009D554: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8009D558: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009D55C: beq         $t7, $at, L_8009D56C
    if (ctx->r15 == ctx->r1) {
        // 0x8009D560: nop
    
            goto L_8009D56C;
    }
    // 0x8009D560: nop

    // 0x8009D564: b           L_8009D64C
    // 0x8009D568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009D64C;
    // 0x8009D568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009D56C:
    // 0x8009D56C: lb          $t8, -0x5A0($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X5A0);
    // 0x8009D570: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8009D574: beq         $t8, $zero, L_8009D584
    if (ctx->r24 == 0) {
        // 0x8009D578: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8009D584;
    }
    // 0x8009D578: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009D57C: b           L_8009D64C
    // 0x8009D580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009D64C;
    // 0x8009D580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009D584:
    // 0x8009D584: beq         $t9, $at, L_8009D594
    if (ctx->r25 == ctx->r1) {
        // 0x8009D588: nop
    
            goto L_8009D594;
    }
    // 0x8009D588: nop

    // 0x8009D58C: jal         0x8006F5C8
    // 0x8009D590: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_pause_lockout_timer(rdram, ctx);
        goto after_1;
    // 0x8009D590: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_8009D594:
    // 0x8009D594: jal         0x8009C464
    // 0x8009D598: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    update_controller_sticks(rdram, ctx);
        goto after_2;
    // 0x8009D598: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_2:
    // 0x8009D59C: jal         0x800C59F4
    // 0x8009D5A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    dialogue_clear(rdram, ctx);
        goto after_3;
    // 0x8009D5A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8009D5A4: jal         0x800C5B54
    // 0x8009D5A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    open_dialogue_box(rdram, ctx);
        goto after_4;
    // 0x8009D5A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8009D5AC: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x8009D5B0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8009D5B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D5B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D5BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009D5C0: jal         0x800C551C
    // 0x8009D5C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_5;
    // 0x8009D5C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8009D5C8: jal         0x8001F484
    // 0x8009D5CC: nop

    func_8001F450(rdram, ctx);
        goto after_6;
    // 0x8009D5CC: nop

    after_6:
    // 0x8009D5D0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8009D5D4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8009D5D8: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x8009D5DC: beq         $at, $zero, L_8009D648
    if (ctx->r1 == 0) {
        // 0x8009D5E0: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8009D648;
    }
    // 0x8009D5E0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8009D5E4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009D5E8: addu        $at, $at, $t1
    gpr jr_addend_8009D5F4 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8009D5EC: lw          $t1, -0x74E8($at)
    ctx->r9 = ADD32(ctx->r1, -0X74E8);
    // 0x8009D5F0: nop

    // 0x8009D5F4: jr          $t1
    // 0x8009D5F8: nop

    switch (jr_addend_8009D5F4 >> 2) {
        case 0: goto L_8009D5FC; break;
        case 1: goto L_8009D648; break;
        case 2: goto L_8009D60C; break;
        case 3: goto L_8009D61C; break;
        case 4: goto L_8009D62C; break;
        case 5: goto L_8009D63C; break;
        default: switch_error(__func__, 0x8009D5F4, 0x800E8B18);
    }
    // 0x8009D5F8: nop

L_8009D5FC:
    // 0x8009D5FC: jal         0x8009D8A4
    // 0x8009D600: nop

    taj_menu_loop(rdram, ctx);
        goto after_7;
    // 0x8009D600: nop

    after_7:
    // 0x8009D604: b           L_8009D648
    // 0x8009D608: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8009D648;
    // 0x8009D608: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009D60C:
    // 0x8009D60C: jal         0x8009E080
    // 0x8009D610: nop

    tt_menu_loop(rdram, ctx);
        goto after_8;
    // 0x8009D610: nop

    after_8:
    // 0x8009D614: b           L_8009D648
    // 0x8009D618: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8009D648;
    // 0x8009D618: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009D61C:
    // 0x8009D61C: jal         0x800C3ABC
    // 0x8009D620: nop

    dialogue_challenge_loop(rdram, ctx);
        goto after_9;
    // 0x8009D620: nop

    after_9:
    // 0x8009D624: b           L_8009D648
    // 0x8009D628: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8009D648;
    // 0x8009D628: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009D62C:
    // 0x8009D62C: jal         0x8009ED2C
    // 0x8009D630: nop

    trophy_race_cabinet_menu_loop(rdram, ctx);
        goto after_10;
    // 0x8009D630: nop

    after_10:
    // 0x8009D634: b           L_8009D648
    // 0x8009D638: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8009D648;
    // 0x8009D638: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009D63C:
    // 0x8009D63C: jal         0x8009DF38
    // 0x8009D640: nop

    dialogue_race_defeat(rdram, ctx);
        goto after_11;
    // 0x8009D640: nop

    after_11:
    // 0x8009D644: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009D648:
    // 0x8009D648: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8009D64C:
    // 0x8009D64C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009D650: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009D654: jr          $ra
    // 0x8009D658: nop

    return;
    // 0x8009D658: nop

;}
RECOMP_FUNC void pi_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076E00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80076E04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076E08: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076E0C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80076E10: addiu       $a1, $a1, 0x47B8
    ctx->r5 = ADD32(ctx->r5, 0X47B8);
    // 0x80076E14: addiu       $a0, $a0, 0x47F8
    ctx->r4 = ADD32(ctx->r4, 0X47F8);
    // 0x80076E18: jal         0x800C8D80
    // 0x80076E1C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80076E1C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x80076E20: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076E24: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80076E28: addiu       $a1, $a1, 0x4798
    ctx->r5 = ADD32(ctx->r5, 0X4798);
    // 0x80076E2C: addiu       $a0, $a0, 0x47A0
    ctx->r4 = ADD32(ctx->r4, 0X47A0);
    // 0x80076E30: jal         0x800C8D80
    // 0x80076E34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80076E34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80076E38: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80076E3C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80076E40: addiu       $a2, $a2, 0x47B8
    ctx->r6 = ADD32(ctx->r6, 0X47B8);
    // 0x80076E44: addiu       $a1, $a1, 0x47F8
    ctx->r5 = ADD32(ctx->r5, 0X47F8);
    // 0x80076E48: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80076E4C: jal         0x800C6560
    // 0x80076E50: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_2;
    // 0x80076E50: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
    // 0x80076E54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076E58: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80076E5C: addiu       $a1, $a1, 0x4810
    ctx->r5 = ADD32(ctx->r5, 0X4810);
    // 0x80076E60: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x80076E64: jal         0x800C8D80
    // 0x80076E68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x80076E68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80076E6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076E70: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x80076E74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80076E78: jal         0x800C9390
    // 0x80076E7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80076E7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80076E80: lui         $t6, 0xF
    ctx->r14 = S32(0XF << 16);
    // 0x80076E84: lui         $t7, 0xF
    ctx->r15 = S32(0XF << 16);
    // 0x80076E88: addiu       $t7, $t7, -0x2F20
    ctx->r15 = ADD32(ctx->r15, -0X2F20);
    // 0x80076E8C: addiu       $t6, $t6, -0x2E50
    ctx->r14 = ADD32(ctx->r14, -0X2E50);
    // 0x80076E90: subu        $v1, $t6, $t7
    ctx->r3 = SUB32(ctx->r14, ctx->r15);
    // 0x80076E94: lui         $a1, 0x7F7F
    ctx->r5 = S32(0X7F7F << 16);
    // 0x80076E98: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x80076E9C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80076EA0: jal         0x80070EDC
    // 0x80076EA4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x80076EA4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_5:
    // 0x80076EA8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80076EAC: addiu       $v1, $v1, 0x4830
    ctx->r3 = ADD32(ctx->r3, 0X4830);
    // 0x80076EB0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80076EB4: jal         0x800716B8
    // 0x80076EB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mempool_locked_set(rdram, ctx);
        goto after_6;
    // 0x80076EB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80076EBC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80076EC0: lw          $a1, 0x4830($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4830);
    // 0x80076EC4: lui         $a0, 0xF
    ctx->r4 = S32(0XF << 16);
    // 0x80076EC8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80076ECC: jal         0x800773D4
    // 0x80076ED0: addiu       $a0, $a0, -0x2F20
    ctx->r4 = ADD32(ctx->r4, -0X2F20);
    dmacopy_v1(rdram, ctx);
        goto after_7;
    // 0x80076ED0: addiu       $a0, $a0, -0x2F20
    ctx->r4 = ADD32(ctx->r4, -0X2F20);
    after_7:
    // 0x80076ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076ED8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80076EDC: jr          $ra
    // 0x80076EE0: nop

    return;
    // 0x80076EE0: nop

;}
RECOMP_FUNC void func_8000CC20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CC20: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000CC24: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8000CC28: addiu       $a1, $a1, -0x4C78
    ctx->r5 = ADD32(ctx->r5, -0X4C78);
    // 0x8000CC2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000CC30: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
L_8000CC34:
    // 0x8000CC34: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8000CC38: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000CC3C: nop

    // 0x8000CC40: bne         $t8, $zero, L_8000CC50
    if (ctx->r24 != 0) {
        // 0x8000CC44: nop
    
            goto L_8000CC50;
    }
    // 0x8000CC44: nop

    // 0x8000CC48: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000CC4C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_8000CC50:
    // 0x8000CC50: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000CC54: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x8000CC58: bne         $at, $zero, L_8000CC34
    if (ctx->r1 != 0) {
        // 0x8000CC5C: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8000CC34;
    }
    // 0x8000CC5C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8000CC60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000CC64: beq         $v1, $at, L_8000CC74
    if (ctx->r3 == ctx->r1) {
        // 0x8000CC68: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_8000CC74;
    }
    // 0x8000CC68: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8000CC6C: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x8000CC70: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
L_8000CC74:
    // 0x8000CC74: jr          $ra
    // 0x8000CC78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000CC78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void alSynAllocFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065AA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065AA4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80065AA8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80065AAC: lh          $a2, 0x26($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X26);
    // 0x80065AB0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80065AB4: sll         $s1, $a2, 2
    ctx->r17 = S32(ctx->r6 << 2);
    // 0x80065AB8: addu        $s1, $s1, $a2
    ctx->r17 = ADD32(ctx->r17, ctx->r6);
    // 0x80065ABC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065AC0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80065AC4: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x80065AC8: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x80065ACC: subu        $s1, $s1, $a2
    ctx->r17 = SUB32(ctx->r17, ctx->r6);
    // 0x80065AD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80065AD4: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x80065AD8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80065ADC: addu        $a0, $t6, $s1
    ctx->r4 = ADD32(ctx->r14, ctx->r17);
    // 0x80065AE0: jal         0x80064C48
    // 0x80065AE4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    alFxNew(rdram, ctx);
        goto after_0;
    // 0x80065AE4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_0:
    // 0x80065AE8: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
    // 0x80065AEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80065AF0: addu        $a2, $t7, $s1
    ctx->r6 = ADD32(ctx->r15, ctx->r17);
    // 0x80065AF4: jal         0x800641D4
    // 0x80065AF8: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    alFxParam(rdram, ctx);
        goto after_1;
    // 0x80065AF8: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    after_1:
    // 0x80065AFC: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x80065B00: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80065B04: addu        $a2, $t8, $s1
    ctx->r6 = ADD32(ctx->r24, ctx->r17);
    // 0x80065B08: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x80065B0C: jal         0x800CC8F0
    // 0x80065B10: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    alMainBusParam(rdram, ctx);
        goto after_2;
    // 0x80065B10: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80065B14: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x80065B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80065B1C: addu        $v0, $t9, $s1
    ctx->r2 = ADD32(ctx->r25, ctx->r17);
    // 0x80065B20: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80065B24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80065B28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065B2C: jr          $ra
    // 0x80065B30: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    return;
    // 0x80065B30: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
;}
RECOMP_FUNC void menu_ghost_data_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AD10: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009AD14: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8009AD18: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009AD1C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8009AD20: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
    // 0x8009AD24: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8009AD28: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8009AD2C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8009AD30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009AD34: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x8009AD38: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x8009AD3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009AD40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009AD44: bne         $at, $zero, L_8009AD70
    if (ctx->r1 != 0) {
        // 0x8009AD48: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8009AD70;
    }
    // 0x8009AD48: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8009AD4C: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8009AD50: beq         $at, $zero, L_8009AD70
    if (ctx->r1 == 0) {
        // 0x8009AD54: nop
    
            goto L_8009AD70;
    }
    // 0x8009AD54: nop

    // 0x8009AD58: jal         0x8009A3C8
    // 0x8009AD5C: nop

    ghostmenu_render(rdram, ctx);
        goto after_0;
    // 0x8009AD5C: nop

    after_0:
    // 0x8009AD60: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009AD64: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009AD68: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8009AD6C: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_8009AD70:
    // 0x8009AD70: beq         $v0, $zero, L_8009AD90
    if (ctx->r2 == 0) {
        // 0x8009AD74: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8009AD90;
    }
    // 0x8009AD74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8009AD78: bgez        $v0, L_8009AD8C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009AD7C: addu        $t2, $v0, $s0
        ctx->r10 = ADD32(ctx->r2, ctx->r16);
            goto L_8009AD8C;
    }
    // 0x8009AD7C: addu        $t2, $v0, $s0
    ctx->r10 = ADD32(ctx->r2, ctx->r16);
    // 0x8009AD80: subu        $t9, $v0, $s0
    ctx->r25 = SUB32(ctx->r2, ctx->r16);
    // 0x8009AD84: b           L_8009AD90
    // 0x8009AD88: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
        goto L_8009AD90;
    // 0x8009AD88: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_8009AD8C:
    // 0x8009AD8C: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
L_8009AD90:
    // 0x8009AD90: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009AD94: lw          $t3, 0x6964($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6964);
    // 0x8009AD98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009AD9C: bne         $t3, $zero, L_8009AE20
    if (ctx->r11 != 0) {
        // 0x8009ADA0: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8009AE20;
    }
    // 0x8009ADA0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8009ADA4: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8009ADA8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009ADAC: bne         $t4, $zero, L_8009AE20
    if (ctx->r12 != 0) {
        // 0x8009ADB0: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009AE20;
    }
    // 0x8009ADB0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009ADB4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009ADB8: addiu       $a1, $a1, 0x6A04
    ctx->r5 = ADD32(ctx->r5, 0X6A04);
    // 0x8009ADBC: addiu       $v1, $v1, 0x69FC
    ctx->r3 = ADD32(ctx->r3, 0X69FC);
L_8009ADC0:
    // 0x8009ADC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009ADC4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8009ADC8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8009ADCC: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x8009ADD0: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8009ADD4: jal         0x8006A794
    // 0x8009ADD8: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8009ADD8: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_1:
    // 0x8009ADDC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8009ADE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8009ADE4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8009ADE8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8009ADEC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8009ADF0: lb          $t5, 0x0($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X0);
    // 0x8009ADF4: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x8009ADF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009ADFC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009AE00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009AE04: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8009AE08: or          $a3, $a3, $v0
    ctx->r7 = ctx->r7 | ctx->r2;
    // 0x8009AE0C: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x8009AE10: bne         $s0, $at, L_8009ADC0
    if (ctx->r16 != ctx->r1) {
        // 0x8009AE14: addu        $t0, $t0, $t6
        ctx->r8 = ADD32(ctx->r8, ctx->r14);
            goto L_8009ADC0;
    }
    // 0x8009AE14: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8009AE18: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009AE1C: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_8009AE20:
    // 0x8009AE20: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009AE24: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
    // 0x8009AE28: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8009AE2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009AE30: beq         $v0, $zero, L_8009AE5C
    if (ctx->r2 == 0) {
        // 0x8009AE34: nop
    
            goto L_8009AE5C;
    }
    // 0x8009AE34: nop

    // 0x8009AE38: beq         $v0, $v1, L_8009AF74
    if (ctx->r2 == ctx->r3) {
        // 0x8009AE3C: andi        $t3, $a3, 0x4000
        ctx->r11 = ctx->r7 & 0X4000;
            goto L_8009AF74;
    }
    // 0x8009AE3C: andi        $t3, $a3, 0x4000
    ctx->r11 = ctx->r7 & 0X4000;
    // 0x8009AE40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009AE44: beq         $v0, $at, L_8009B074
    if (ctx->r2 == ctx->r1) {
        // 0x8009AE48: andi        $t8, $a3, 0xD000
        ctx->r24 = ctx->r7 & 0XD000;
            goto L_8009B074;
    }
    // 0x8009AE48: andi        $t8, $a3, 0xD000
    ctx->r24 = ctx->r7 & 0XD000;
    // 0x8009AE4C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009AE50: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8009AE54: b           L_8009B0B0
    // 0x8009AE58: nop

        goto L_8009B0B0;
    // 0x8009AE58: nop

L_8009AE5C:
    // 0x8009AE5C: andi        $v0, $a3, 0x9000
    ctx->r2 = ctx->r7 & 0X9000;
    // 0x8009AE60: beq         $v0, $zero, L_8009AE90
    if (ctx->r2 == 0) {
        // 0x8009AE64: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8009AE90;
    }
    // 0x8009AE64: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009AE68: addiu       $a1, $a1, 0x6A74
    ctx->r5 = ADD32(ctx->r5, 0X6A74);
    // 0x8009AE6C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009AE70: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8009AE74: blez        $t7, L_8009AE90
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8009AE78: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8009AE90;
    }
    // 0x8009AE78: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009AE7C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8009AE80: jal         0x80001D04
    // 0x8009AE84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8009AE84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8009AE88: b           L_8009AF64
    // 0x8009AE8C: nop

        goto L_8009AF64;
    // 0x8009AE8C: nop

L_8009AE90:
    // 0x8009AE90: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009AE94: andi        $t9, $a3, 0x4000
    ctx->r25 = ctx->r7 & 0X4000;
    // 0x8009AE98: bne         $t9, $zero, L_8009AEB4
    if (ctx->r25 != 0) {
        // 0x8009AE9C: addiu       $a1, $a1, 0x6A74
        ctx->r5 = ADD32(ctx->r5, 0X6A74);
            goto L_8009AEB4;
    }
    // 0x8009AE9C: addiu       $a1, $a1, 0x6A74
    ctx->r5 = ADD32(ctx->r5, 0X6A74);
    // 0x8009AEA0: beq         $v0, $zero, L_8009AEDC
    if (ctx->r2 == 0) {
        // 0x8009AEA4: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8009AEDC;
    }
    // 0x8009AEA4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009AEA8: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8009AEAC: nop

    // 0x8009AEB0: bne         $t2, $zero, L_8009AEDC
    if (ctx->r10 != 0) {
        // 0x8009AEB4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8009AEDC;
    }
L_8009AEB4:
    // 0x8009AEB4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009AEB8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009AEBC: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x8009AEC0: jal         0x800C06F8
    // 0x8009AEC4: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x8009AEC4: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_3:
    // 0x8009AEC8: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009AECC: jal         0x80001D04
    // 0x8009AED0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8009AED0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8009AED4: b           L_8009AF64
    // 0x8009AED8: nop

        goto L_8009AF64;
    // 0x8009AED8: nop

L_8009AEDC:
    // 0x8009AEDC: addiu       $s0, $s0, 0x6A38
    ctx->r16 = ADD32(ctx->r16, 0X6A38);
    // 0x8009AEE0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009AEE4: bgez        $t0, L_8009AF28
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8009AEE8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8009AF28;
    }
    // 0x8009AEE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009AEEC: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8009AEF0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009AEF4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8009AEF8: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8009AEFC: beq         $at, $zero, L_8009AF28
    if (ctx->r1 == 0) {
        // 0x8009AF00: addiu       $v1, $v1, 0x6978
        ctx->r3 = ADD32(ctx->r3, 0X6978);
            goto L_8009AF28;
    }
    // 0x8009AF00: addiu       $v1, $v1, 0x6978
    ctx->r3 = ADD32(ctx->r3, 0X6978);
    // 0x8009AF04: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8009AF08: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x8009AF0C: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x8009AF10: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8009AF14: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8009AF18: bne         $at, $zero, L_8009AF28
    if (ctx->r1 != 0) {
        // 0x8009AF1C: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_8009AF28;
    }
    // 0x8009AF1C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8009AF20: addiu       $t8, $t5, -0x2
    ctx->r24 = ADD32(ctx->r13, -0X2);
    // 0x8009AF24: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8009AF28:
    // 0x8009AF28: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009AF2C: blez        $t0, L_8009AF54
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8009AF30: addiu       $v1, $v1, 0x6978
        ctx->r3 = ADD32(ctx->r3, 0X6978);
            goto L_8009AF54;
    }
    // 0x8009AF30: addiu       $v1, $v1, 0x6978
    ctx->r3 = ADD32(ctx->r3, 0X6978);
    // 0x8009AF34: blez        $v0, L_8009AF54
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009AF38: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8009AF54;
    }
    // 0x8009AF38: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8009AF3C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8009AF40: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8009AF44: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8009AF48: beq         $at, $zero, L_8009AF54
    if (ctx->r1 == 0) {
        // 0x8009AF4C: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8009AF54;
    }
    // 0x8009AF4C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8009AF50: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8009AF54:
    // 0x8009AF54: beq         $a0, $v0, L_8009AF64
    if (ctx->r4 == ctx->r2) {
        // 0x8009AF58: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8009AF64;
    }
    // 0x8009AF58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009AF5C: jal         0x80001D04
    // 0x8009AF60: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8009AF60: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    after_5:
L_8009AF64:
    // 0x8009AF64: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009AF68: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8009AF6C: b           L_8009B0B0
    // 0x8009AF70: nop

        goto L_8009B0B0;
    // 0x8009AF70: nop

L_8009AF74:
    // 0x8009AF74: beq         $t3, $zero, L_8009AF94
    if (ctx->r11 == 0) {
        // 0x8009AF78: andi        $t4, $a3, 0x9000
        ctx->r12 = ctx->r7 & 0X9000;
            goto L_8009AF94;
    }
    // 0x8009AF78: andi        $t4, $a3, 0x9000
    ctx->r12 = ctx->r7 & 0X9000;
    // 0x8009AF7C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8009AF80: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009AF84: jal         0x80001D04
    // 0x8009AF88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8009AF88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8009AF8C: b           L_8009B064
    // 0x8009AF90: nop

        goto L_8009B064;
    // 0x8009AF90: nop

L_8009AF94:
    // 0x8009AF94: beq         $t4, $zero, L_8009B04C
    if (ctx->r12 == 0) {
        // 0x8009AF98: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8009B04C;
    }
    // 0x8009AF98: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009AF9C: addiu       $s0, $s0, 0x6A38
    ctx->r16 = ADD32(ctx->r16, 0X6A38);
    // 0x8009AFA0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009AFA4: jal         0x80099E1C
    // 0x8009AFA8: nop

    ghostmenu_erase(rdram, ctx);
        goto after_7;
    // 0x8009AFA8: nop

    after_7:
    // 0x8009AFAC: bne         $v0, $zero, L_8009B01C
    if (ctx->r2 != 0) {
        // 0x8009AFB0: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8009B01C;
    }
    // 0x8009AFB0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009AFB4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009AFB8: addiu       $a1, $a1, 0x6A74
    ctx->r5 = ADD32(ctx->r5, 0X6A74);
    // 0x8009AFBC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8009AFC0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009AFC4: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009AFC8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8009AFCC: bne         $at, $zero, L_8009AFDC
    if (ctx->r1 != 0) {
        // 0x8009AFD0: nop
    
            goto L_8009AFDC;
    }
    // 0x8009AFD0: nop

    // 0x8009AFD4: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8009AFD8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_8009AFDC:
    // 0x8009AFDC: bgez        $v0, L_8009AFEC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009AFE0: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009AFEC;
    }
    // 0x8009AFE0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009AFE4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8009AFE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009AFEC:
    // 0x8009AFEC: addiu       $v1, $v1, 0x6978
    ctx->r3 = ADD32(ctx->r3, 0X6978);
    // 0x8009AFF0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8009AFF4: nop

    // 0x8009AFF8: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8009AFFC: beq         $at, $zero, L_8009B008
    if (ctx->r1 == 0) {
        // 0x8009B000: nop
    
            goto L_8009B008;
    }
    // 0x8009B000: nop

    // 0x8009B004: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8009B008:
    // 0x8009B008: jal         0x80001D04
    // 0x8009B00C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x8009B00C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8009B010: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009B014: b           L_8009B044
    // 0x8009B018: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
        goto L_8009B044;
    // 0x8009B018: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
L_8009B01C:
    // 0x8009B01C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B020: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B024: sw          $v1, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r3;
    // 0x8009B028: jal         0x800C06F8
    // 0x8009B02C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_9;
    // 0x8009B02C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_9:
    // 0x8009B030: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009B034: jal         0x80001D04
    // 0x8009B038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x8009B038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8009B03C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009B040: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
L_8009B044:
    // 0x8009B044: b           L_8009B064
    // 0x8009B048: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_8009B064;
    // 0x8009B048: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8009B04C:
    // 0x8009B04C: bgez        $t0, L_8009B064
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8009B050: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_8009B064;
    }
    // 0x8009B050: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8009B054: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8009B058: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8009B05C: jal         0x80001D04
    // 0x8009B060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_11;
    // 0x8009B060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
L_8009B064:
    // 0x8009B064: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009B068: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8009B06C: b           L_8009B0B0
    // 0x8009B070: nop

        goto L_8009B0B0;
    // 0x8009B070: nop

L_8009B074:
    // 0x8009B074: beq         $t8, $zero, L_8009B090
    if (ctx->r24 == 0) {
        // 0x8009B078: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8009B090;
    }
    // 0x8009B078: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009B07C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8009B080: jal         0x80001D04
    // 0x8009B084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_12;
    // 0x8009B084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8009B088: b           L_8009B0A4
    // 0x8009B08C: nop

        goto L_8009B0A4;
    // 0x8009B08C: nop

L_8009B090:
    // 0x8009B090: blez        $t0, L_8009B0A4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8009B094: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8009B0A4;
    }
    // 0x8009B094: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8009B098: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8009B09C: jal         0x80001D04
    // 0x8009B0A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x8009B0A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
L_8009B0A4:
    // 0x8009B0A4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009B0A8: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8009B0AC: nop

L_8009B0B0:
    // 0x8009B0B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B0B4: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x8009B0B8: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8009B0BC: bne         $at, $zero, L_8009B0D8
    if (ctx->r1 != 0) {
        // 0x8009B0C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009B0D8;
    }
    // 0x8009B0C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B0C4: jal         0x8009B0E8
    // 0x8009B0C8: nop

    ghostmenu_free(rdram, ctx);
        goto after_14;
    // 0x8009B0C8: nop

    after_14:
    // 0x8009B0CC: jal         0x80081820
    // 0x8009B0D0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    menu_init(rdram, ctx);
        goto after_15;
    // 0x8009B0D0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_15:
    // 0x8009B0D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009B0D8:
    // 0x8009B0D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009B0DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8009B0E0: jr          $ra
    // 0x8009B0E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8009B0E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void wavegen_add(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFA44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BFA48: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BFA4C: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x800BFA50: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x800BFA54: lbu         $t6, 0x10($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X10);
    // 0x800BFA58: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800BFA5C: beq         $t6, $zero, L_800BFA68
    if (ctx->r14 == 0) {
        // 0x800BFA60: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BFA68;
    }
    // 0x800BFA60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BFA64: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BFA68:
    // 0x800BFA68: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x800BFA6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800BFA70: beq         $t7, $zero, L_800BFA7C
    if (ctx->r15 == 0) {
        // 0x800BFA74: ori         $t8, $v1, 0x2
        ctx->r24 = ctx->r3 | 0X2;
            goto L_800BFA7C;
    }
    // 0x800BFA74: ori         $t8, $v1, 0x2
    ctx->r24 = ctx->r3 | 0X2;
    // 0x800BFA78: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800BFA7C:
    // 0x800BFA7C: lhu         $t9, 0xA($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XA);
    // 0x800BFA80: lw          $a1, 0xC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC);
    // 0x800BFA84: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800BFA88: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x800BFA8C: bgez        $t9, L_800BFAA4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800BFA90: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800BFAA4;
    }
    // 0x800BFA90: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BFA94: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BFA98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BFA9C: nop

    // 0x800BFAA0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800BFAA4:
    // 0x800BFAA4: lbu         $t0, 0x9($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X9);
    // 0x800BFAA8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800BFAAC: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x800BFAB0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800BFAB4: lbu         $t2, 0x8($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X8);
    // 0x800BFAB8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BFABC: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800BFAC0: bgez        $t2, L_800BFAD4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BFAC4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800BFAD4;
    }
    // 0x800BFAC4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BFAC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BFACC: nop

    // 0x800BFAD0: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800BFAD4:
    // 0x800BFAD4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800BFAD8: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x800BFADC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BFAE0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800BFAE4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800BFAE8: lhu         $t3, 0xE($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XE);
    // 0x800BFAEC: nop

    // 0x800BFAF0: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800BFAF4: bgez        $t3, L_800BFB08
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800BFAF8: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800BFB08;
    }
    // 0x800BFAF8: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BFAFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BFB00: nop

    // 0x800BFB04: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_800BFB08:
    // 0x800BFB08: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x800BFB0C: lhu         $t4, 0xC($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0XC);
    // 0x800BFB10: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BFB14: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800BFB18: bgez        $t4, L_800BFB2C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800BFB1C: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800BFB2C;
    }
    // 0x800BFB1C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BFB20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BFB24: nop

    // 0x800BFB28: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800BFB2C:
    // 0x800BFB2C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800BFB30: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800BFB34: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x800BFB38: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800BFB3C: jal         0x800BFB54
    // 0x800BFB40: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    wavegen_register(rdram, ctx);
        goto after_0;
    // 0x800BFB40: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x800BFB44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BFB48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BFB4C: jr          $ra
    // 0x800BFB50: nop

    return;
    // 0x800BFB50: nop

;}
RECOMP_FUNC void init_racer_headers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E7FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006E800: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006E804: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8006E808: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8006E80C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006E810: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006E814: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006E818: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006E81C: jal         0x8009C90C
    // 0x8006E820: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    get_number_of_active_players(rdram, ctx);
        goto after_0;
    // 0x8006E820: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8006E824: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006E828: addiu       $s0, $s0, 0x3A90
    ctx->r16 = ADD32(ctx->r16, 0X3A90);
    // 0x8006E82C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006E830: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006E834: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8006E838: addiu       $s6, $zero, 0x7
    ctx->r22 = ADD32(0, 0X7);
    // 0x8006E83C: addiu       $s5, $zero, 0x5
    ctx->r21 = ADD32(0, 0X5);
    // 0x8006E840: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x8006E844: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x8006E848: sb          $v0, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r2;
L_8006E84C:
    // 0x8006E84C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8006E850: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006E854: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8006E858: jal         0x8009C76C
    // 0x8006E85C: sb          $zero, 0x58($t8)
    MEM_B(0X58, ctx->r24) = 0;
    get_character_id_from_slot(rdram, ctx);
        goto after_1;
    // 0x8006E85C: sb          $zero, 0x58($t8)
    MEM_B(0X58, ctx->r24) = 0;
    after_1:
    // 0x8006E860: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8006E864: nop

    // 0x8006E868: addu        $t0, $t9, $s3
    ctx->r8 = ADD32(ctx->r25, ctx->r19);
    // 0x8006E86C: sb          $v0, 0x59($t0)
    MEM_B(0X59, ctx->r8) = ctx->r2;
    // 0x8006E870: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8006E874: nop

    // 0x8006E878: lbu         $t1, 0x4A($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X4A);
    // 0x8006E87C: addu        $t2, $v1, $s3
    ctx->r10 = ADD32(ctx->r3, ctx->r19);
    // 0x8006E880: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x8006E884: bne         $at, $zero, L_8006E894
    if (ctx->r1 != 0) {
        // 0x8006E888: nop
    
            goto L_8006E894;
    }
    // 0x8006E888: nop

    // 0x8006E88C: b           L_8006E8C8
    // 0x8006E890: sb          $s1, 0x5A($t2)
    MEM_B(0X5A, ctx->r10) = ctx->r17;
        goto L_8006E8C8;
    // 0x8006E890: sb          $s1, 0x5A($t2)
    MEM_B(0X5A, ctx->r10) = ctx->r17;
L_8006E894:
    // 0x8006E894: jal         0x8009F1C4
    // 0x8006E898: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_2;
    // 0x8006E898: nop

    after_2:
    // 0x8006E89C: beq         $v0, $zero, L_8006E8B8
    if (ctx->r2 == 0) {
        // 0x8006E8A0: nop
    
            goto L_8006E8B8;
    }
    // 0x8006E8A0: nop

    // 0x8006E8A4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8006E8A8: subu        $t3, $s5, $s1
    ctx->r11 = SUB32(ctx->r21, ctx->r17);
    // 0x8006E8AC: addu        $t5, $t4, $s3
    ctx->r13 = ADD32(ctx->r12, ctx->r19);
    // 0x8006E8B0: b           L_8006E8C8
    // 0x8006E8B4: sb          $t3, 0x5A($t5)
    MEM_B(0X5A, ctx->r13) = ctx->r11;
        goto L_8006E8C8;
    // 0x8006E8B4: sb          $t3, 0x5A($t5)
    MEM_B(0X5A, ctx->r13) = ctx->r11;
L_8006E8B8:
    // 0x8006E8B8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8006E8BC: subu        $t6, $s6, $s1
    ctx->r14 = SUB32(ctx->r22, ctx->r17);
    // 0x8006E8C0: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8006E8C4: sb          $t6, 0x5A($t8)
    MEM_B(0X5A, ctx->r24) = ctx->r14;
L_8006E8C8:
    // 0x8006E8C8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8006E8CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006E8D0: addu        $t0, $t9, $s3
    ctx->r8 = ADD32(ctx->r25, ctx->r19);
    // 0x8006E8D4: sb          $zero, 0x5B($t0)
    MEM_B(0X5B, ctx->r8) = 0;
L_8006E8D8:
    // 0x8006E8D8: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8006E8DC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8006E8E0: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x8006E8E4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8006E8E8: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8006E8EC: addu        $t3, $t4, $v0
    ctx->r11 = ADD32(ctx->r12, ctx->r2);
    // 0x8006E8F0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8006E8F4: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8006E8F8: bne         $at, $zero, L_8006E8D8
    if (ctx->r1 != 0) {
        // 0x8006E8FC: sh          $zero, 0x5C($t3)
        MEM_H(0X5C, ctx->r11) = 0;
            goto L_8006E8D8;
    }
    // 0x8006E8FC: sh          $zero, 0x5C($t3)
    MEM_H(0X5C, ctx->r11) = 0;
    // 0x8006E900: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8006E904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006E908: addu        $t7, $t5, $s3
    ctx->r15 = ADD32(ctx->r13, ctx->r19);
    // 0x8006E90C: sh          $zero, 0x64($t7)
    MEM_H(0X64, ctx->r15) = 0;
L_8006E910:
    // 0x8006E910: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x8006E914: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006E918: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x8006E91C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8006E920: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8006E924: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8006E928: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8006E92C: bne         $v0, $s2, L_8006E910
    if (ctx->r2 != ctx->r18) {
        // 0x8006E930: sh          $zero, 0x66($t0)
        MEM_H(0X66, ctx->r8) = 0;
            goto L_8006E910;
    }
    // 0x8006E930: sh          $zero, 0x66($t0)
    MEM_H(0X66, ctx->r8) = 0;
    // 0x8006E934: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006E938: bne         $s1, $s4, L_8006E84C
    if (ctx->r17 != ctx->r20) {
        // 0x8006E93C: addiu       $s3, $s3, 0x18
        ctx->r19 = ADD32(ctx->r19, 0X18);
            goto L_8006E84C;
    }
    // 0x8006E93C: addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    // 0x8006E940: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8006E944: nop

    // 0x8006E948: sb          $zero, 0x114($t1)
    MEM_B(0X114, ctx->r9) = 0;
    // 0x8006E94C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8006E950: nop

    // 0x8006E954: sb          $zero, 0x115($t2)
    MEM_B(0X115, ctx->r10) = 0;
    // 0x8006E958: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8006E95C: nop

    // 0x8006E960: sb          $zero, 0x116($t4)
    MEM_B(0X116, ctx->r12) = 0;
    // 0x8006E964: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8006E968: nop

    // 0x8006E96C: sb          $zero, 0x117($t3)
    MEM_B(0X117, ctx->r11) = 0;
    // 0x8006E970: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8006E974: nop

    // 0x8006E978: sb          $zero, 0x48($t5)
    MEM_B(0X48, ctx->r13) = 0;
    // 0x8006E97C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8006E980: nop

    // 0x8006E984: sb          $zero, 0x49($t7)
    MEM_B(0X49, ctx->r15) = 0;
    // 0x8006E988: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006E98C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8006E990: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E994: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006E998: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006E99C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006E9A0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E9A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006E9A8: jr          $ra
    // 0x8006E9AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006E9AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void optionscreen_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084B70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084B74: jal         0x800C478C
    // 0x80084B78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x80084B78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80084B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80084B84: jr          $ra
    // 0x80084B88: nop

    return;
    // 0x80084B88: nop

;}
RECOMP_FUNC void audspat_reverb_get_strength_at_point(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009D6C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80009D70: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x80009D74: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80009D78: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80009D7C: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80009D80: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80009D84: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x80009D88: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80009D8C: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x80009D90: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80009D94: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x80009D98: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80009D9C: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80009DA0: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80009DA4: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80009DA8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80009DAC: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x80009DB0: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x80009DB4: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80009DB8: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80009DBC: lwc1        $f4, 0xBC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XBC);
    // 0x80009DC0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80009DC4: c.eq.s      $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f24.fl == ctx->f4.fl;
    // 0x80009DC8: nop

    // 0x80009DCC: bc1f        L_80009E70
    if (!c1cs) {
        // 0x80009DD0: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80009E70;
    }
    // 0x80009DD0: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80009DD4: lb          $t6, 0xB8($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XB8);
    // 0x80009DD8: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x80009DDC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80009DE0: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    // 0x80009DE4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80009DE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009DEC: c.lt.s      $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f24.fl < ctx->f8.fl;
    // 0x80009DF0: nop

    // 0x80009DF4: bc1f        L_80009E6C
    if (!c1cs) {
        // 0x80009DF8: nop
    
            goto L_80009E6C;
    }
    // 0x80009DF8: nop

    // 0x80009DFC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80009E00: nop

L_80009E04:
    // 0x80009E04: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80009E08: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80009E0C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80009E10: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80009E14: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80009E18: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80009E1C: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80009E20: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80009E24: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80009E28: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80009E2C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80009E30: nop

    // 0x80009E34: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80009E38: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80009E3C: jal         0x800CA030
    // 0x80009E40: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80009E40: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_0:
    // 0x80009E44: lb          $t7, 0xB8($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XB8);
    // 0x80009E48: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80009E4C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80009E50: lwc1        $f6, 0xBC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XBC);
    // 0x80009E54: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80009E58: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80009E5C: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x80009E60: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80009E64: bc1t        L_80009E04
    if (c1cs) {
        // 0x80009E68: swc1        $f8, 0xBC($s1)
        MEM_W(0XBC, ctx->r17) = ctx->f8.u32l;
            goto L_80009E04;
    }
    // 0x80009E68: swc1        $f8, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->f8.u32l;
L_80009E6C:
    // 0x80009E6C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_80009E70:
    // 0x80009E70: mov.s       $f16, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    ctx->f16.fl = ctx->f24.fl;
    // 0x80009E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80009E78:
    // 0x80009E78: lwc1        $f22, 0x0($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80009E7C: lwc1        $f20, 0xC($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80009E80: lwc1        $f30, 0x4($s0)
    ctx->f30.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80009E84: sub.s       $f24, $f20, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80009E88: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80009E8C: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x80009E90: sub.s       $f26, $f0, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = ctx->f0.fl - ctx->f30.fl;
    // 0x80009E94: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80009E98: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80009E9C: mul.s       $f8, $f26, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x80009EA0: sub.s       $f28, $f2, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80009EA4: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x80009EA8: sb          $v0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r2;
    // 0x80009EAC: mul.s       $f4, $f28, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x80009EB0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80009EB4: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    // 0x80009EB8: jal         0x800CA030
    // 0x80009EBC: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80009EBC: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_1:
    // 0x80009EC0: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80009EC4: lbu         $v0, 0x57($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X57);
    // 0x80009EC8: c.le.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl <= ctx->f6.fl;
    // 0x80009ECC: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80009ED0: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80009ED4: bc1f        L_80009EEC
    if (!c1cs) {
        // 0x80009ED8: nop
    
            goto L_80009EEC;
    }
    // 0x80009ED8: nop

    // 0x80009EDC: c.le.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl <= ctx->f20.fl;
    // 0x80009EE0: nop

    // 0x80009EE4: bc1t        L_80009F14
    if (c1cs) {
        // 0x80009EE8: nop
    
            goto L_80009F14;
    }
    // 0x80009EE8: nop

L_80009EEC:
    // 0x80009EEC: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80009EF0: nop

    // 0x80009EF4: c.le.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl <= ctx->f8.fl;
    // 0x80009EF8: nop

    // 0x80009EFC: bc1f        L_8000A020
    if (!c1cs) {
        // 0x80009F00: nop
    
            goto L_8000A020;
    }
    // 0x80009F00: nop

    // 0x80009F04: c.le.s      $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f8.fl <= ctx->f22.fl;
    // 0x80009F08: nop

    // 0x80009F0C: bc1f        L_8000A020
    if (!c1cs) {
        // 0x80009F10: nop
    
            goto L_8000A020;
    }
    // 0x80009F10: nop

L_80009F14:
    // 0x80009F14: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80009F18: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80009F1C: c.eq.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl == ctx->f10.fl;
    // 0x80009F20: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80009F24: bc1t        L_80009F38
    if (c1cs) {
        // 0x80009F28: nop
    
            goto L_80009F38;
    }
    // 0x80009F28: nop

    // 0x80009F2C: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80009F30: b           L_80009F7C
    // 0x80009F34: div.s       $f12, $f6, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f24.fl);
        goto L_80009F7C;
    // 0x80009F34: div.s       $f12, $f6, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f24.fl);
L_80009F38:
    // 0x80009F38: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80009F3C: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80009F40: c.eq.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl == ctx->f2.fl;
    // 0x80009F44: nop

    // 0x80009F48: bc1t        L_80009F5C
    if (c1cs) {
        // 0x80009F4C: nop
    
            goto L_80009F5C;
    }
    // 0x80009F4C: nop

    // 0x80009F50: sub.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f30.fl;
    // 0x80009F54: b           L_80009F7C
    // 0x80009F58: div.s       $f12, $f10, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f26.fl);
        goto L_80009F7C;
    // 0x80009F58: div.s       $f12, $f10, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f26.fl);
L_80009F5C:
    // 0x80009F5C: c.eq.s      $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f28.fl == ctx->f2.fl;
    // 0x80009F60: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80009F64: bc1t        L_80009F78
    if (c1cs) {
        // 0x80009F68: nop
    
            goto L_80009F78;
    }
    // 0x80009F68: nop

    // 0x80009F6C: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80009F70: b           L_80009F7C
    // 0x80009F74: div.s       $f12, $f6, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f28.fl);
        goto L_80009F7C;
    // 0x80009F74: div.s       $f12, $f6, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f28.fl);
L_80009F78:
    // 0x80009F78: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80009F7C:
    // 0x80009F7C: mul.s       $f8, $f26, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f12.fl);
    // 0x80009F80: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80009F84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80009F88: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80009F8C: add.s       $f2, $f8, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x80009F90: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80009F94: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x80009F98: nop

    // 0x80009F9C: bc1f        L_80009FAC
    if (!c1cs) {
        // 0x80009FA0: nop
    
            goto L_80009FAC;
    }
    // 0x80009FA0: nop

    // 0x80009FA4: b           L_80009FB4
    // 0x80009FA8: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
        goto L_80009FB4;
    // 0x80009FA8: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
L_80009FAC:
    // 0x80009FAC: sub.s       $f14, $f2, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80009FB0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_80009FB4:
    // 0x80009FB4: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x80009FB8: nop

    // 0x80009FBC: bc1f        L_8000A018
    if (!c1cs) {
        // 0x80009FC0: nop
    
            goto L_8000A018;
    }
    // 0x80009FC0: nop

    // 0x80009FC4: mul.s       $f8, $f28, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f12.fl);
    // 0x80009FC8: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80009FCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80009FD0: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80009FD4: add.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80009FD8: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x80009FDC: nop

    // 0x80009FE0: bc1f        L_80009FF0
    if (!c1cs) {
        // 0x80009FE4: nop
    
            goto L_80009FF0;
    }
    // 0x80009FE4: nop

    // 0x80009FE8: b           L_80009FF8
    // 0x80009FEC: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
        goto L_80009FF8;
    // 0x80009FEC: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
L_80009FF0:
    // 0x80009FF0: sub.s       $f14, $f2, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80009FF4: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_80009FF8:
    // 0x80009FF8: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x80009FFC: nop

    // 0x8000A000: bc1f        L_8000A018
    if (!c1cs) {
        // 0x8000A004: nop
    
            goto L_8000A018;
    }
    // 0x8000A004: nop

    // 0x8000A008: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8000A00C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A010: b           L_8000A024
    // 0x8000A014: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
        goto L_8000A024;
    // 0x8000A014: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_8000A018:
    // 0x8000A018: b           L_8000A024
    // 0x8000A01C: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
        goto L_8000A024;
    // 0x8000A01C: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
L_8000A020:
    // 0x8000A020: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
L_8000A024:
    // 0x8000A024: beq         $v0, $zero, L_80009E78
    if (ctx->r2 == 0) {
        // 0x8000A028: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80009E78;
    }
    // 0x8000A028: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8000A02C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000A030: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000A034: lwc1        $f0, 0xBC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XBC);
    // 0x8000A038: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8000A03C: div.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8000A040: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8000A044: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8000A048: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x8000A04C: nop

    // 0x8000A050: bc1f        L_8000A05C
    if (!c1cs) {
        // 0x8000A054: nop
    
            goto L_8000A05C;
    }
    // 0x8000A054: nop

    // 0x8000A058: sub.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f16.fl;
L_8000A05C:
    // 0x8000A05C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000A060: nop

    // 0x8000A064: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8000A068: nop

    // 0x8000A06C: bc1f        L_8000A140
    if (!c1cs) {
        // 0x8000A070: nop
    
            goto L_8000A140;
    }
    // 0x8000A070: nop

    // 0x8000A074: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x8000A078: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000A07C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8000A080: bgez        $t8, L_8000A094
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8000A084: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8000A094;
    }
    // 0x8000A084: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000A088: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000A08C: nop

    // 0x8000A090: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8000A094:
    // 0x8000A094: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000A098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A09C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000A0A0: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000A0A4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000A0A8: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8000A0AC: nop

    // 0x8000A0B0: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8000A0B4: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8000A0B8: nop

    // 0x8000A0BC: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8000A0C0: beq         $v0, $zero, L_8000A124
    if (ctx->r2 == 0) {
        // 0x8000A0C4: nop
    
            goto L_8000A124;
    }
    // 0x8000A0C4: nop

    // 0x8000A0C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000A0CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A0D0: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8000A0D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000A0D8: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8000A0DC: nop

    // 0x8000A0E0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8000A0E4: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8000A0E8: nop

    // 0x8000A0EC: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8000A0F0: bne         $v0, $zero, L_8000A114
    if (ctx->r2 != 0) {
        // 0x8000A0F4: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8000A114;
    }
    // 0x8000A0F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000A0F8: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8000A0FC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000A100: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x8000A104: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8000A108: b           L_8000A148
    // 0x8000A10C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8000A148;
    // 0x8000A10C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8000A110:
    // 0x8000A110: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000A114:
    // 0x8000A114: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8000A118: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000A11C: b           L_8000A148
    // 0x8000A120: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8000A148;
    // 0x8000A120: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8000A124:
    // 0x8000A124: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8000A128: nop

    // 0x8000A12C: bltz        $v0, L_8000A110
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000A130: andi        $t0, $v0, 0xFF
        ctx->r8 = ctx->r2 & 0XFF;
            goto L_8000A110;
    }
    // 0x8000A130: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8000A134: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000A138: b           L_8000A148
    // 0x8000A13C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8000A148;
    // 0x8000A13C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8000A140:
    // 0x8000A140: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x8000A144: nop

L_8000A148:
    // 0x8000A148: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8000A14C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8000A150: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8000A154: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000A158: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8000A15C: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000A160: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8000A164: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000A168: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8000A16C: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000A170: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8000A174: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000A178: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8000A17C: jr          $ra
    // 0x8000A180: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8000A180: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void dummy_80079808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079C58: jr          $ra
    // 0x80079C5C: nop

    return;
    // 0x80079C5C: nop

;}
RECOMP_FUNC void func_800245B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800245E8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800245EC: addiu       $v1, $v1, -0x3390
    ctx->r3 = ADD32(ctx->r3, -0X3390);
    // 0x800245F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800245F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800245F8: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800245FC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80024600: sh          $a0, -0x4E60($at)
    MEM_H(-0X4E60, ctx->r1) = ctx->r4;
    // 0x80024604: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80024608: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x8002460C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80024610: bne         $at, $zero, L_8002461C
    if (ctx->r1 != 0) {
        // 0x80024614: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_8002461C;
    }
    // 0x80024614: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80024618: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8002461C:
    // 0x8002461C: jr          $ra
    // 0x80024620: nop

    return;
    // 0x80024620: nop

;}
RECOMP_FUNC void cam_set_layout(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006676C: bltz        $a0, L_80066788
    if (SIGNED(ctx->r4) < 0) {
        // 0x80066770: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_80066788;
    }
    // 0x80066770: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80066774: beq         $at, $zero, L_80066788
    if (ctx->r1 == 0) {
        // 0x80066778: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80066788;
    }
    // 0x80066778: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006677C: addiu       $v1, $v1, 0x1260
    ctx->r3 = ADD32(ctx->r3, 0X1260);
    // 0x80066780: b           L_80066794
    // 0x80066784: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80066794;
    // 0x80066784: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80066788:
    // 0x80066788: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006678C: addiu       $v1, $v1, 0x1260
    ctx->r3 = ADD32(ctx->r3, 0X1260);
    // 0x80066790: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80066794:
    // 0x80066794: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066798: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006679C: beq         $v0, $zero, L_800667D0
    if (ctx->r2 == 0) {
        // 0x800667A0: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800667D0;
    }
    // 0x800667A0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800667A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800667A8: beq         $v0, $at, L_800667DC
    if (ctx->r2 == ctx->r1) {
        // 0x800667AC: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_800667DC;
    }
    // 0x800667AC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800667B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800667B4: beq         $v0, $at, L_800667E8
    if (ctx->r2 == ctx->r1) {
        // 0x800667B8: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_800667E8;
    }
    // 0x800667B8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800667BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800667C0: beq         $v0, $at, L_800667F4
    if (ctx->r2 == ctx->r1) {
        // 0x800667C4: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_800667F4;
    }
    // 0x800667C4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800667C8: b           L_800667FC
    // 0x800667CC: nop

        goto L_800667FC;
    // 0x800667CC: nop

L_800667D0:
    // 0x800667D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800667D4: b           L_800667FC
    // 0x800667D8: sw          $t6, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r14;
        goto L_800667FC;
    // 0x800667D8: sw          $t6, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r14;
L_800667DC:
    // 0x800667DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800667E0: b           L_800667FC
    // 0x800667E4: sw          $t7, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r15;
        goto L_800667FC;
    // 0x800667E4: sw          $t7, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r15;
L_800667E8:
    // 0x800667E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800667EC: b           L_800667FC
    // 0x800667F0: sw          $t8, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r24;
        goto L_800667FC;
    // 0x800667F0: sw          $t8, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r24;
L_800667F4:
    // 0x800667F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800667F8: sw          $t9, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r25;
L_800667FC:
    // 0x800667FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066800: addiu       $v0, $v0, 0x1264
    ctx->r2 = ADD32(ctx->r2, 0X1264);
    // 0x80066804: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80066808: lw          $v1, 0x1268($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1268);
    // 0x8006680C: nop

    // 0x80066810: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80066814: bne         $at, $zero, L_80066820
    if (ctx->r1 != 0) {
        // 0x80066818: nop
    
            goto L_80066820;
    }
    // 0x80066818: nop

    // 0x8006681C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80066820:
    // 0x80066820: jr          $ra
    // 0x80066824: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80066824: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void menu_trophy_race_round_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800987A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800987AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800987B0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800987B4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800987B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800987BC: jal         0x8006ECD0
    // 0x800987C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x800987C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800987C4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800987C8: jal         0x8001E2D0
    // 0x800987CC: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x800987CC: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_1:
    // 0x800987D0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800987D4: lw          $v1, 0x156C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X156C);
    // 0x800987D8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800987DC: bne         $v1, $zero, L_80098818
    if (ctx->r3 != 0) {
        // 0x800987E0: lui         $s3, 0x800E
        ctx->r19 = S32(0X800E << 16);
            goto L_80098818;
    }
    // 0x800987E0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800987E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800987E8: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x800987EC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_800987F0:
    // 0x800987F0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800987F4: sw          $zero, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = 0;
    // 0x800987F8: sw          $zero, 0x84($v1)
    MEM_W(0X84, ctx->r3) = 0;
    // 0x800987FC: sw          $zero, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = 0;
    // 0x80098800: addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // 0x80098804: bne         $s0, $a0, L_800987F0
    if (ctx->r16 != ctx->r4) {
        // 0x80098808: sw          $zero, -0xC($v1)
        MEM_W(-0XC, ctx->r3) = 0;
            goto L_800987F0;
    }
    // 0x80098808: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x8009880C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80098810: lw          $v1, 0x156C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X156C);
    // 0x80098814: nop

L_80098818:
    // 0x80098818: lw          $t6, 0x1568($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1568);
    // 0x8009881C: addiu       $s3, $s3, -0x5C4
    ctx->r19 = ADD32(ctx->r19, -0X5C4);
    // 0x80098820: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80098824: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80098828: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8009882C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80098830: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80098834: lb          $a0, -0x6($t9)
    ctx->r4 = MEM_B(ctx->r25, -0X6);
    // 0x80098838: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8009883C:
    // 0x8009883C: bne         $a0, $v1, L_80098850
    if (ctx->r4 != ctx->r3) {
        // 0x80098840: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80098850;
    }
    // 0x80098840: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80098844: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80098848: andi        $t0, $s0, 0x3
    ctx->r8 = ctx->r16 & 0X3;
    // 0x8009884C: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_80098850:
    // 0x80098850: beq         $s0, $v1, L_8009883C
    if (ctx->r16 == ctx->r3) {
        // 0x80098854: nop
    
            goto L_8009883C;
    }
    // 0x80098854: nop

    // 0x80098858: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x8009885C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80098860: blez        $t1, L_8009888C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80098864: lui         $s2, 0x8012
        ctx->r18 = S32(0X8012 << 16);
            goto L_8009888C;
    }
    // 0x80098864: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80098868: addiu       $s2, $s2, 0x6F80
    ctx->r18 = ADD32(ctx->r18, 0X6F80);
L_8009886C:
    // 0x8009886C: jal         0x8006B2EC
    // 0x80098870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_vehicle_default(rdram, ctx);
        goto after_2;
    // 0x80098870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80098874: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80098878: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8009887C: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80098880: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80098884: bne         $at, $zero, L_8009886C
    if (ctx->r1 != 0) {
        // 0x80098888: sb          $v0, -0x1($s2)
        MEM_B(-0X1, ctx->r18) = ctx->r2;
            goto L_8009886C;
    }
    // 0x80098888: sb          $v0, -0x1($s2)
    MEM_B(-0X1, ctx->r18) = ctx->r2;
L_8009888C:
    // 0x8009888C: jal         0x8006B2EC
    // 0x80098890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_vehicle_default(rdram, ctx);
        goto after_3;
    // 0x80098890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80098894: jal         0x8006DD54
    // 0x80098898: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    set_level_default_vehicle(rdram, ctx);
        goto after_4;
    // 0x80098898: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8009889C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800988A0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800988A4: jal         0x8006E528
    // 0x800988A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    load_level_for_menu(rdram, ctx);
        goto after_5;
    // 0x800988A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800988AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800988B0: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x800988B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800988B8: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x800988BC: sw          $t3, 0xF00($at)
    MEM_W(0XF00, ctx->r1) = ctx->r11;
    // 0x800988C0: jal         0x800C46D0
    // 0x800988C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_6;
    // 0x800988C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x800988C8: jal         0x80000BE0
    // 0x800988CC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_7;
    // 0x800988CC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_7:
    // 0x800988D0: jal         0x80000B34
    // 0x800988D4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_8;
    // 0x800988D4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_8:
    // 0x800988D8: jal         0x80000C98
    // 0x800988DC: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    music_fade(rdram, ctx);
        goto after_9;
    // 0x800988DC: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_9:
    // 0x800988E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800988E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800988E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800988EC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800988F0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800988F4: jr          $ra
    // 0x800988F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800988F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
